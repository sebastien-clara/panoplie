declare name "NLFfm";
declare description "FM synthesizer implemented with a nonlinear passive allpass filter";
declare author "Sébastien Clara";

import("instruments.lib");

//==================== GUI SPECIFICATION ================
frequency = vslider("v:NLFfm/h:[1]midi/freq [1][unit:Hz] [tooltip:Tone frequency][style:knob]",440,20,5000,1);
gain = vslider("v:NLFfm/h:[1]midi/gain [1][tooltip:Gain (value between 0 and 1)][style:knob]",1,0,1,0.01);
gate = button("v:NLFfm/h:[1]midi/gate [1][tooltip:noteOn = 1, noteOff = 0]");
bend = vslider("v:NLFfm/h:[1]midi/[1]bend[hidden:1][midi:pitchwheel][style:knob]",1,0.9,1.1,0.01) : si.polySmooth(gate,0.999,1);

freq = frequency*bend;


typeModulation = nentry("v:NLFfm/h:[2]Nonlinear_Filter/Modulation_Type
[2][tooltip: 0=theta is modulated by the incoming signal; 1=theta is modulated by the averaged incoming signal;
2=theta is modulated by the squared incoming signal; 3=theta is modulated by a sine wave of frequency freqMod;
4=theta is modulated by a sine wave of frequency freq;][style:knob]",0,0,4,1);
nonLinearity = hslider("v:NLFfm/h:[2]Nonlinear_Filter/Nonlinearity
[2][tooltip:Nonlinearity factor (value between 0 and 1)][style:knob]",0,0,1,0.01);
frequencyMod = hslider("v:NLFfm/h:[3]Nonlinear_Filter/Modulation_Frequency [tooltip:Frequency of the sine wave for the modulation of theta (works if Modulation Type=3)][style:knob]", 2,0.1,5,0.1)*freq;
nonLinAttack = hslider("v:NLFfm/h:[2]Nonlinear_Filter/Nonlinearity_Attack
[2][unit:s][Attack duration of the nonlinearity][style:knob]",0.1,0,2,0.01);


vibratoFreq = hslider("v:NLFfm/h:[3]Vibrato/Vibrato_Freq
[3][unit:Hz][style:knob]",5,1,15,0.1);
vibratoGain = hslider("v:NLFfm/h:[3]Vibrato/Vibrato_Gain
[3][tooltip:A value between 0 and 1][style:knob]",0.1,0,1,0.01);
vibratoAttack = hslider("v:NLFfm/h:[3]Vibrato/Vibrato_Attack
[3][unit:s][tooltip:Vibrato attack duration][style:knob]",0.5,0,2,0.01);
vibratoRelease = hslider("v:NLFfm/h:[3]Vibrato/Vibrato_Release
[3][unit:s][tooltip:Vibrato release duration][style:knob]",0.01,0,2,0.01);


envelopeAttack = hslider("v:NLFfm/h:[4]Envelope/Envelope_Attack
[4][unit:s][tooltip:Envelope attack duration][style:knob]",0.05,0,2,0.01);
envelopeDecay = hslider("v:NLFfm/h:[4]Envelope/Envelope_Decay
[4][unit:s][tooltip:Envelope decay duration][style:knob]",0.05,0,2,0.01);
envelopeRelease = hslider("v:NLFfm/h:[4]Envelope/Envelope_Release
[4][unit:s][tooltip:Envelope release duration][style:knob]",0.05,0,2,0.01);

//----------------------- Nonlinear filter ----------------------------
//nonlinearities are created by the nonlinear passive allpass ladder filter declared in miscfilter.lib

//nonlinear filter order
nlfOrder = 3;

//attack - sustain - release envelope for nonlinearity (declared in instruments.lib)
envelopeMod = en.asr(nonLinAttack,1,envelopeRelease,gate);

//nonLinearModultor is declared in instruments.lib, it adapts allpassnn from miscfilter.lib
//for using it with waveguide instruments
NLFM =  nonLinearModulator((nonLinearity : si.smoo),envelopeMod,freq,
     typeModulation,(frequencyMod : si.smoo),nlfOrder);

//----------------------- Algorithm implementation ----------------------------

//vibrato gain is controled by envVibrato (declared in instruments.lib)
vibrato = os.osc(vibratoFreq)*vibratoGain*envVibrato(0.1*2*vibratoAttack,0.9*2*vibratoAttack,100,vibratoRelease,gate);

//output gain is controled by an adsr envelope
envelope = en.adsr(envelopeAttack,envelopeDecay,0.9,envelopeRelease,gate)*gain;
breath = envelope + envelope*vibrato;

process = os.osc(freq)*breath*0.5 : NLFM;
