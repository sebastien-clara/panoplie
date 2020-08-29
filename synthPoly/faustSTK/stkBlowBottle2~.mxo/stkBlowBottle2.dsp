declare name "blowBottle";
declare description "Blown Bottle Instrument";
declare author "Sébastien Clara";
declare licence "STK-4.3"; // Synthesis Tool Kit 4.3 (MIT style license);
declare description "This object implements a helmholtz resonator (biquad filter) with a polynomial jet excitation (a la Cook).";

import("instruments.lib");

//==================== GUI SPECIFICATION ================
frequency = vslider("v:blowBottle/h:[1]midi/freq [1][unit:Hz] [tooltip:Tone frequency][style:knob]",440,20,5000,1);
gain = vslider("v:blowBottle/h:[1]midi/gain [1][tooltip:Gain (value between 0 and 1)][style:knob]",1,0,1,0.01);
gate = button("v:blowBottle/h:[1]midi/gate [1][tooltip:noteOn = 1, noteOff = 0]");
bend = vslider("v:blowBottle/h:[1]midi/[1]bend[hidden:1][midi:pitchwheel] [style:knob]",1,0.9,1.1,0.01) : si.polySmooth(gate,0.999,1);

freq = frequency*bend;


noiseGain = vslider("v:blowBottle/h:[2]Physical/Noise_Gain
[2][tooltip:Breath noise gain (value between 0 and 1)][style:knob]",0.5,0,1,0.01)*2;
pressure = vslider("v:blowBottle/h:[2]Physical/Pressure
[2][tooltip:Breath pressure (value bewteen 0 and 1)][style:knob]",1,0,1,0.01)*0.5+0.5;


typeModulation = nentry("v:blowBottle/h:[3]Nonlinear_Filter/Modulation_Type
[3][tooltip: 0=theta is modulated by the incoming signal; 1=theta is modulated by the averaged incoming signal;
2=theta is modulated by the squared incoming signal; 3=theta is modulated by a sine wave of frequency freqMod;
4=theta is modulated by a sine wave of frequency freq;][style:knob]",0,0,4,1);
nonLinearity = vslider("v:blowBottle/h:[3]Nonlinear_Filter/Nonlinearity
[3][tooltip:Nonlinearity factor (value between 0 and 1)][style:knob]",0,0,1,0.01);
frequencyMod = hslider("v:blowBottle/h:[3]Nonlinear_Filter/Modulation_Frequency [tooltip:Frequency of the sine wave for the modulation of theta (works if Modulation Type=3)][style:knob]", 2,0.1,5,0.1)*freq;
nonLinAttack = vslider("v:blowBottle/h:[3]Nonlinear_Filter/Nonlinearity_Attack
[3][unit:s][Attack duration of the nonlinearity][style:knob]",0.1,0,2,0.01);


vibratoFreq = vslider("v:blowBottle/h:[4]Vibrato/Vibrato_Freq
[4][unit:Hz][style:knob]",5,1,15,0.1);
vibratoGain = vslider("v:blowBottle/h:[4]Vibrato/Vibrato_Gain
[4][tooltip:A value between 0 and 1][style:knob]",0.1,0,1,0.01);
vibratoBegin = vslider("v:blowBottle/h:[4]Vibrato/Vibrato_Begin
[4][unit:s][tooltip:Vibrato silence duration before attack][style:knob]",0.05,0,2,0.01);
vibratoAttack = vslider("v:blowBottle/h:[4]Vibrato/Vibrato_Attack
[4][unit:s][tooltip:Vibrato attack duration][style:knob]",0.05,0,2,0.01);
vibratoRelease = vslider("v:blowBottle/h:[4]Vibrato/Vibrato_Release
[4][unit:s][tooltip:Vibrato release duration][style:knob]",0.01,0.01,2,0.01);


envelopeAttack = vslider("v:blowBottle/h:[5]Envelope/Envelope_Attack
[5][unit:s][tooltip:Envelope attack duration][style:knob]",0.01,0,2,0.01);
envelopeDecay = vslider("v:blowBottle/h:[5]Envelope/Envelope_Decay
[5][unit:s][tooltip:Envelope decay duration][style:knob]",0.01,0,2,0.01);
envelopeRelease = vslider("v:blowBottle/h:[5]Envelope/Envelope_Release
[5][unit:s][tooltip:Envelope release duration][style:knob]",0.05,0.01,2,0.01);


//==================== SIGNAL PROCESSING ================

//----------------------- Nonlinear filter ----------------------------
//nonlinearities are created by the nonlinear passive allpass ladder filter declared in miscfilter.lib

//nonlinear filter order
nlfOrder = 6;

//attack - sustain - release envelope for nonlinearity (declared in instruments.lib)
envelopeMod = en.asr(nonLinAttack,1,envelopeRelease,gate);

//nonLinearModultor is declared in instruments.lib, it adapts allpassnn from miscfilter.lib
//for using it with waveguide instruments
NLFM =  nonLinearModulator((nonLinearity : si.smoo),envelopeMod,freq,
typeModulation,(frequencyMod : si.smoo),nlfOrder);

//----------------------- Synthesis parameters computing and functions declaration ----------------------------

//botlle radius
bottleRadius = 0.999;


bandPassFilter = bandPass(freq,bottleRadius);

//----------------------- Algorithm implementation ----------------------------

//global envelope is of type attack - decay - sustain - release
envelopeG =  gain*en.adsr(gain*envelopeAttack,envelopeDecay,1,envelopeRelease,gate);

//pressure envelope is also ADSR
envelope = pressure*en.asr(gain*0.02,1,gain*0.2,gate);

//vibrato
vibrato =
os.osc(vibratoFreq)*vibratoGain*envVibrato(vibratoBegin,vibratoAttack,100,vibratoRelease,gate)*os.osc(vibratoFreq);

//breat pressure
breathPressure = envelope + vibrato;

//breath noise
randPressure = noiseGain*no.noise*breathPressure;


process =
	//differential pressure
	(-(breathPressure) <:
	((+(1))*randPressure : +(breathPressure)) - *(jetTable),_ : bandPassFilter,_)~NLFM : !,_ :
	//signal scaling
	fi.dcblocker*envelopeG*0.25;
