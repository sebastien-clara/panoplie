declare name "harpsi";
declare description "Nonlinear WaveGuide Commuted Harpsichord";
declare author "Sébastien Clara";
declare licence "STK-4.3"; // Synthesis Tool Kit 4.3 (MIT style license);
declare description "A commuted WaveGuide Harpsichord.";

import("instruments.lib");

//==================== GUI SPECIFICATION ================

frequency = vslider("v:harpsi/h:[1]midi/freq [1][unit:Hz] [tooltip:Tone frequency][style:knob]",440,20,5000,1);
gain = vslider("v:harpsi/h:[1]midi/gain [1][tooltip:Gain (value between 0 and 1)][style:knob]",1,0,1,0.01);
gate = button("v:harpsi/h:[1]midi/gate [1][tooltip:noteOn = 1, noteOff = 0]");
bend = vslider("v:harpsi/h:[1]midi/[1]bend[hidden:1][midi:pitchwheel][style:knob]",1,0.9,1.1,0.01) : si.polySmooth(gate,0.999,1);

freq = frequency*bend;


typeModulation = nentry("v:harpsi/h:[2]Nonlinear_Filter/Modulation_Type
[2][tooltip: 0=theta is modulated by the incoming signal; 1=theta is modulated by the averaged incoming signal;
2=theta is modulated by the squared incoming signal; 3=theta is modulated by a sine wave of frequency freqMod;
4=theta is modulated by a sine wave of frequency freq;][style:knob]",0,0,4,1);
nonLinearity = hslider("v:harpsi/h:[2]Nonlinear_Filter/Nonlinearity
[2][tooltip:Nonlinearity factor (value between 0 and 1)][style:knob]",0,0,1,0.01);
frequencyMod = hslider("v:harpsi/h:[2]Nonlinear_Filter/Modulation_Frequency
[2][unit:Hz][tooltip:Frequency of the sine wave for the modulation of theta (works if Modulation Type=3)][style:knob]",220,20,1000,0.1);

//==================== PROCESSING ================

//----------------------- Nonlinear filter ----------------------------
//nonlinearities are created by the nonlinear passive allpass ladder filter declared in miscfilter.lib

//nonlinear filter order
nlfOrder = 6;

//nonLinearModultor is declared in instruments.lib, it adapts allpassnn from miscfilter.lib
//for using it with waveguide instruments
NLFM =  nonLinearModulator((nonLinearity : si.smoo),1,freq,
     typeModulation,(frequencyMod : si.smoo),nlfOrder);

//----------------------- Synthesis parameters computing and functions declaration ----------------------------

//convert a frequency in a midi note number
freqToNoteNumber = (log-log(440))/log(2)*12+69+0.5 : int;
freqn = freq : freqToNoteNumber;

//string excitation
soundBoard = dryTapAmp*no.noise
	with{
		dryTapAmpT60 = ffunction(float getValueDryTapAmpT60(float), <harpsichord.h>,"");
		noteCutOffTime = freqn : dryTapAmpT60*gain;
		dryTapAmp = asympT60(0.15,0,noteCutOffTime,gate);
	};

//loopfilter is a biquad filter whose coefficients are extracted from a C++ file using the foreign function mechanism
loopFilter = fi.TF2(b0,b1,b2,a1,a2)
	   with{
		//functions are imported from the C++ file
		loopFilterb0 = ffunction(float getValueLoopFilterb0(float), <harpsichord.h>,"");
		loopFilterb1 = ffunction(float getValueLoopFilterb1(float), <harpsichord.h>,"");
		loopFilterb2 = ffunction(float getValueLoopFilterb2(float), <harpsichord.h>,"");
		loopFiltera1 = ffunction(float getValueLoopFiltera1(float), <harpsichord.h>,"");
		loopFiltera2 = ffunction(float getValueLoopFiltera2(float), <harpsichord.h>,"");
		//coefficients are extracted from the functions
		b0 = loopFilterb0(freqn);
		b1 = loopFilterb1(freqn);
		b2 = loopFilterb2(freqn);
		a1 = loopFiltera1(freqn);
		a2 = loopFiltera2(freqn);
	   };

//delay length as a number of samples
delayLength = ma.SR/freq;

//----------------------- Algorithm implementation ----------------------------

//envelope for string loop resonance time
stringLoopGainT = gate*0.9996 + (gate<1)*releaseLoopGain(freqn)*0.9 : si.smoo
		with{
			releaseLoopGain = ffunction(float getValueReleaseLoopGain(float), <harpsichord.h>,"");
		};

//one string
string = (*(stringLoopGainT)+_ : de.delay(4096,delayLength) : loopFilter)~NLFM;


process = (soundBoard : string)*0.5;
