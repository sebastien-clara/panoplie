declare name "Bass";
declare description "Nonlinear WaveGuide Acoustic Bass";
declare author "Sébastien Clara";
declare licence "STK-4.3"; // Synthesis Tool Kit 4.3 (MIT style license);

import("instruments.lib");

//==================== GUI SPECIFICATION ================

frequency = vslider("v:bass/h:[1]midi/freq [1][unit:Hz] [tooltip:Tone frequency][style:knob]",120,20,4000,1);
gain = vslider("v:bass/h:[1]midi/gain [1][tooltip:Gain (value between 0 and 1)][style:knob]",1,0,1,0.01);
gate = button("v:bass/h:[1]midi/gate [1][tooltip:noteOn = 1, noteOff = 0]");
bend = vslider("v:bass/h:[1]midi/[1]bend[hidden:1][midi:pitchwheel][style:knob]",1,0.9,1.1,0.01) : si.polySmooth(gate,0.999,1);

freq = frequency*bend;


touchLength = hslider("v:bass/h:[2]Physical/Touch_Length
[2][tooltip:A value between 0 and 3][style:knob]",0.15,0,3,0.01)*2;


typeModulation = nentry("v:bass/h:[3]Nonlinear_Filter/Modulation_Type
[3][tooltip: 0=theta is modulated by the incoming signal; 1=theta is modulated by the averaged incoming signal;
2=theta is modulated by the squared incoming signal; 3=theta is modulated by a sine wave of frequency freqMod;
4=theta is modulated by a sine wave of frequency freq;][style:knob]",0,0,4,1);
nonLinearity = hslider("v:bass/h:[3]Nonlinear_Filter/Nonlinearity
[3][tooltip:Nonlinearity factor (value between 0 and 1)][style:knob]",0,0,1,0.01);
frequencyMod = hslider("v:bass/h:[3]Nonlinear_Filter/Modulation_Frequency [tooltip:Frequency of the sine wave for the modulation of theta (works if Modulation Type=3)][style:knob]", 2,0.1,5,0.1)*freq;

//==================== SIGNAL PROCESSING ======================

//----------------------- Nonlinear filter ----------------------------
//nonlinearities are created by the nonlinear passive allpass ladder filter declared in miscfilter.lib

//nonlinear filter order
nlfOrder = 6;

//nonLinearModultor is declared in instruments.lib, it adapts allpassnn from miscfilter.lib
//for using it with waveguide instruments
NLFM =  nonLinearModulator((nonLinearity : si.smoo),1,freq, typeModulation,(frequencyMod : si.smoo),nlfOrder);

//----------------------- Synthesis parameters computing and functions declaration ----------------------------

//delay length in number of samples
delayLength = float(ma.SR)/freq;

//string excitation
excitation = asympT60(-0.5,-0.985,0.02,gate),no.noise*asympT60(gain,0,touchLength,gate) : onePoleSwep : excitationFilter : excitationFilter
with{
		//the exitation filter is a one pole filter (declared in instruments.lib)
		excitationFilter = onePole(0.035,-0.965);
};

//the bodyfilter is a bandpass filter (declared in instruments.lib)
bodyFilter = bandPass(108,0.997);

//the reflexion filter is pole zero filter (declared in instruments.lib) whose coefficients are
//modulated in function of the tone being played
reflexionFilter = poleZero(b0,b1,a1)
with{
		//filter coefficients are stored in a C++ function
		loopFilterb0 = ffunction(float getValueBassLoopFilterb0(float), <bass.h>,"");
		loopFilterb1 = ffunction(float getValueBassLoopFilterb1(float), <bass.h>,"");
		loopFiltera1 = ffunction(float getValueBassLoopFiltera1(float), <bass.h>,"");
		freqToNoteNumber = (log - log(440))/log(2)*12 + 69 + 0.5 : int;
		freqn = freq : freqToNoteNumber;
		b0 = loopFilterb0(freqn);
		b1 = loopFilterb1(freqn);
		a1 = loopFiltera1(freqn);
};

delayLine = asympT60(0,delayLength,0.01,gate),_ : de.fdelay(4096);

//the resonance duration is different whether a note-on signal is sent or not
resonanceGain = gate + (gate < 1 <: *(asympT60(1,0.9,0.05)));


process = excitation :
	(+)~(delayLine : NLFM : reflexionFilter*resonanceGain) <:
	bodyFilter*1.5 + *(0.5) : *(2);
