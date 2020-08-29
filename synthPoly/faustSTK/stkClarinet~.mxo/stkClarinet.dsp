declare name "clarinet";
declare description "Nonlinear WaveGuide Clarinet";
declare author "Sébastien Clara";
declare licence "STK-4.3"; // Synthesis Tool Kit 4.3 (MIT style license);
declare description "A simple clarinet physical model, as discussed by Smith (1986), McIntyre, Schumacher, Woodhouse (1983), and others.";
declare reference "https://ccrma.stanford.edu/~jos/pasp/Woodwinds.html";

import("instruments.lib");

//==================== GUI SPECIFICATION ================

frequency = vslider("v:clarinet/h:[1]midi/freq [1][unit:Hz] [tooltip:Tone frequency][style:knob]",440,20,5000,1);
gain = vslider("v:clarinet/h:[1]midi/gain [1][tooltip:Gain (value between 0 and 1)][style:knob]",1,0,1,0.01);
gate = button("v:clarinet/h:[1]midi/gate [1][tooltip:noteOn = 1, noteOff = 0]");
bend = vslider("v:clarinet/h:[1]midi/[1]bend[hidden:1][midi:pitchwheel][style:knob]",1,0.9,1.1,0.01) : si.polySmooth(gate,0.999,1);

freq = frequency*bend;


reedStiffness = hslider("v:clarinet/h:[2]Physical/Reed_Stiffness
[2][tooltip:Reed stiffness (value between 0 and 1)][style:knob]",0.5,0,1,0.01);
noiseGain = hslider("v:clarinet/h:[2]Physical/Noise_Gain
[2][tooltip:Breath noise gain (value between 0 and 1)][style:knob]",0,0,1,0.01);
pressure = hslider("v:clarinet/h:[2]Physical/Pressure
[2][tooltip:Breath pressure (value bewteen 0 and 1)][style:knob]",1,0,1,0.01);


typeModulation = nentry("v:clarinet/h:[3]Nonlinear_Filter/Modulation_Type
[3][tooltip: 0=theta is modulated by the incoming signal; 1=theta is modulated by the averaged incoming signal;
2=theta is modulated by the squared incoming signal; 3=theta is modulated by a sine wave of frequency freqMod;
4=theta is modulated by a sine wave of frequency freq;][style:knob]",0,0,4,1);
nonLinearity = hslider("v:clarinet/h:[3]Nonlinear_Filter/Nonlinearity
[3][tooltip:Nonlinearity factor (value between 0 and 1)][style:knob]",0,0,1,0.01);
frequencyMod = hslider("v:clarinet/h:[3]Nonlinear_Filter/Modulation_Frequency
[3][unit:Hz][tooltip:Frequency of the sine wave for the modulation of theta (works if Modulation Type=3)][style:knob]",220,20,1000,0.1);
nonLinAttack = hslider("v:clarinet/h:[3]Nonlinear_Filter/Nonlinearity_Attack
[3][unit:s][Attack duration of the nonlinearity][style:knob]",0.1,0,2,0.01);


vibratoFreq = hslider("v:clarinet/h:[4]Vibrato/Vibrato_Freq
[4][unit:Hz][style:knob]",5,1,15,0.1);
vibratoGain = hslider("v:clarinet/h:[4]Vibrato/Vibrato_Gain
[4][tooltip:A value between 0 and 1][style:knob]",0.1,0,1,0.01);
vibratoAttack = hslider("v:clarinet/h:[4]Vibrato/Vibrato_Attack
[4][unit:s][tooltip:Vibrato attack duration][style:knob]",0.05,0,2,0.01);
vibratoRelease = hslider("v:clarinet/h:[4]Vibrato/Vibrato_Release
[4][unit:s][tooltip:Vibrato release duration][style:knob]",0.01,0.01,2,0.01);


envelopeAttack = hslider("v:clarinet/h:[5]Envelope/Envelope_Attack
[5][unit:s][tooltip:Envelope attack duration][style:knob]",0.01,0,2,0.01);
envelopeDecay = hslider("v:clarinet/h:[5]Envelope/Envelope_Decay
[5][unit:s][tooltip:Envelope decay duration][style:knob]",0.05,0,2,0.01);
envelopeRelease = hslider("v:clarinet/h:[5]Envelope/Envelope_Release
[5][unit:s][tooltip:Envelope release duration][style:knob]",0.1,0.01,2,0.01);

//==================== SIGNAL PROCESSING ======================

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

//reed table parameters
reedTableOffset = 0.7;
reedTableSlope = -0.44 + (0.26*reedStiffness);

//the reed function is declared in instruments.lib
reedTable = reed(reedTableOffset,reedTableSlope);

//delay line with a length adapted in function of the order of nonlinear filter
delayLength = ma.SR/freq*0.5 - 1.5 - (nlfOrder*nonLinearity)*(typeModulation < 2);
delayLine = de.fdelay(4096,delayLength);

//one zero filter used as a allpass: pole is set to -1
filter = oneZero0(0.5,0.5);



//----------------------- Algorithm implementation ----------------------------

//Breath pressure + vibrato + breath noise + envelope (Attack / Decay / Sustain / Release)
envelope = en.adsr(envelopeAttack,envelopeDecay,1,envelopeRelease,gate)*pressure*0.9;

vibrato = os.osc(vibratoFreq)*vibratoGain*
	envVibrato(0.1*2*vibratoAttack,0.9*2*vibratoAttack,100,vibratoRelease,gate);
breath = envelope + envelope*no.noise*noiseGain;
breathPressure = breath + breath*vibrato;

process =
	//Commuted Loss Filtering
	(_,(breathPressure <: _,_) : (filter*-0.95 - _ <:

	//Non-Linear Scattering
	*(reedTable)) + _) ~

	//Delay with Feedback
	(delayLine : NLFM) :

	//scaling and stereo
	*(gain)*1.0;
