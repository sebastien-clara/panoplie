declare name "glassHarmonica";
declare description "Nonlinear Banded Waveguide Modeled Glass Harmonica";
declare author "Sébastien Clara";
declare licence "STK-4.3"; // Synthesis Tool Kit 4.3 (MIT style license);
declare description "This instrument uses banded waveguide. For more information, see Essl, G. and Cook, P. Banded Waveguides: Towards Physical Modelling of Bar Percussion Instruments, Proceedings of the 1999 International Computer Music Conference.";

import("instruments.lib");

//==================== GUI SPECIFICATION ================
envelop(a,d,s,r, gate, gain) = en.adsre(att, dec, sus, rel, gate) * gain
with {
	att = vslider("v:glassHarmonica/h:[5]env/[1]A [style:knob] [tooltip:sec]", a, 0, 10, 0.01) : si.smoo;
	dec = vslider("v:glassHarmonica/h:[5]env/[2]D [style:knob] [tooltip:sec]", d, 0, 10, 0.01) : si.smoo;
	sus = vslider("v:glassHarmonica/h:[5]env/[3]S [style:knob] [tooltip:percentage of max : 0-1]", s, 0, 1, 0.01) : si.smoo;
	rel = vslider("v:glassHarmonica/h:[5]env/[4]R [style:knob] [tooltip:sec]", r, 0.01, 10, 0.01) : si.smoo;
};

frequency = vslider("v:glassHarmonica/h:[1]midi/freq [1][unit:Hz] [tooltip:Tone frequency][style:knob]",440,20,5000,1);
gain = vslider("v:glassHarmonica/h:[1]midi/gain [1][tooltip:Gain (value between 0 and 1)][style:knob]",1,0,1,0.01);
gate = button("v:glassHarmonica/h:[1]midi/gate [1][tooltip:noteOn = 1, noteOff = 0]");
bend = vslider("v:glassHarmonica/h:[1]midi/[1]bend[hidden:1][midi:pitchwheel][style:knob]",1,0.9,1.1,0.01) : si.polySmooth(gate,0.999,1);

freq = frequency*bend;


integrationConstant = hslider("v:glassHarmonica/h:[2]Physical/Integration_Constant
[2][tooltip:A value between 0 and 1][style:knob]",0,0,1,0.01);
baseGain = hslider("v:glassHarmonica/h:[2]Physical/Base_Gain
[2][tooltip:A value between 0 and 1][style:knob]",1,0,1,0.01);
bowPressure = hslider("v:glassHarmonica/h:[2]Physical/Bow_Pressure
[2][tooltip:Bow pressure on the instrument (Value between 0 and 1)][style:knob]",0.2,0,1,0.01);
bowPosition = hslider("v:glassHarmonica/h:[2]Physical/Bow_Position
[2][tooltip:Bow position on the instrument (Value between 0 and 1)][style:knob]",0,0,1,0.01);


typeModulation = nentry("v:glassHarmonica/h:[3]Nonlinear_Filter/Modulation_Type
[3][tooltip: 0=theta is modulated by the incoming signal; 1=theta is modulated by the averaged incoming signal;
2=theta is modulated by the squared incoming signal; 3=theta is modulated by a sine wave of frequency freqMod;
4=theta is modulated by a sine wave of frequency freq;][style:knob]",0,0,4,1);
nonLinearity = hslider("v:glassHarmonica/h:[3]Nonlinear_Filter/Nonlinearity
[3][tooltip:Nonlinearity factor (value between 0 and 1)][style:knob]",0,0,1,0.01);
frequencyMod = hslider("v:glassHarmonica/h:[3]Nonlinear_Filter/Modulation_Frequency [tooltip:Frequency of the sine wave for the modulation of theta (works if Modulation Type=3)][style:knob]", 2,0.1,5,0.1)*freq;
nonLinAttack = hslider("v:glassHarmonica/h:[3]Nonlinear_Filter/Nonlinearity_Attack
[3][unit:s][Attack duration of the nonlinearity][style:knob]",0.1,0,2,0.01);

//==================== MODAL PARAMETERS ================

preset = 3;

nMode(3) = 6;

modes(3,0) = 1.0;
basegains(3,0) = pow(0.999,1);
excitation(3,0) = 1*gain*gate/(nMode(3) - 1);

modes(3,1) = 2.32;
basegains(3,1) = pow(0.999,2);
excitation(3,1) = 1*gain*gate/(nMode(3) - 1);

modes(3,2) = 4.25;
basegains(3,2) = pow(0.999,3);
excitation(3,2) = 1*gain*gate/(nMode(3) - 1);

modes(3,3) = 6.63;
basegains(3,3) = pow(0.999,4);
excitation(3,3) = 1*gain*gate/(nMode(3) - 1);

modes(3,4) = 9.38;
basegains(3,4) = pow(0.999,5);
excitation(3,4) = 1*gain*gate/(nMode(3) - 1);

modes(3,5) = 9 : float;
basegains(3,5) = 0 : float;
excitation(3,5) = 0 : float;

//==================== SIGNAL PROCESSING ================

//----------------------- Nonlinear filter ----------------------------
//nonlinearities are created by the nonlinear passive allpass ladder filter declared in miscfilter.lib

//nonlinear filter order
nlfOrder = 6;

//nonLinearModultor is declared in instruments.lib, it adapts allpassnn from miscfilter.lib
//for using it with waveguide instruments
NLFM =  nonLinearModulator((nonLinearity : si.smoo),1,freq,
typeModulation,(frequencyMod : si.smoo),nlfOrder);

//----------------------- Synthesis parameters computing and functions declaration ----------------------------

//the number of modes depends on the preset being used
nModes = nMode(preset);

delayLengthBase = ma.SR/freq;

//delay lengths in number of samples
delayLength(x) = delayLengthBase/modes(preset,x);

//delay lines
delayLine(x) = de.delay(4096,delayLength(x));

//Filter bank: bandpass filters (declared in instruments.lib)
radius = 1 - ma.PI*32/ma.SR;
bandPassFilter(x) = bandPass(freq*modes(preset,x),radius);


//----------------------- Algorithm implementation ----------------------------

//One resonance
resonance(x) = + : + (excitation(preset,x)) : delayLine(x) : *(basegains(preset,x)) : bandPassFilter(x);


amp = 0.15 * envelop(0.01,0.1,0.6,5, gate, gain);

process =
		(gate : ba.toggle <:
		//nModes resonances with nModes feedbacks for bow table look-up
		par(i,nModes,(resonance(i)~_))):>+:
		//Signal Scaling
		*(4) : NLFM * amp;
