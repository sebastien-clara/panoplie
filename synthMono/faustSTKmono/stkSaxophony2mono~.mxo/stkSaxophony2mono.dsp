declare name "saxophony2 mono";
declare description "Nonlinear WaveGuide Saxophone";
declare author "Sébastien Clara";
declare licence "STK-4.3"; // Synthesis Tool Kit 4.3 (MIT style license);
declare description "This class implements a hybrid digital waveguide instrument that can generate a variety of wind-like sounds.  It has also been referred to as the blowed string model. The waveguide section is essentially that of a string, with one rigid and one lossy termination.  The non-linear function is a reed table. The string can be blown at any point between the terminations, though just as with strings, it is impossible to excite the system at either end. If the excitation is placed at the string mid-point, the sound is that of a clarinet.  At points closer to the bridge, the sound is closer to that of a saxophone.  See Scavone (2002) for more details.";
declare reference "https://ccrma.stanford.edu/~jos/pasp/Woodwinds.html";

import("instruments.lib");

//==================== GUI SPECIFICATION ================

frequency = vslider("v:saxophony/h:[1]midi/freq [1][unit:Hz] [tooltip:Tone frequency][style:knob]",440,20,5000,1);
gain = vslider("v:saxophony/h:[1]midi/gain [1][tooltip:Gain (value between 0 and 1)][style:knob]",1,0,1,0.01)*0.5;
gate = button("v:saxophony/h:[1]midi/gate [1][tooltip:noteOn = 1, noteOff = 0]");
bend = vslider("v:saxophony/h:[1]midi/[1]bend[hidden:1][midi:pitchwheel] [style:knob]",1,0.9,1.1,0.01) : si.smoo;
portamento = si.smooth(vslider("v:saxophony/h:[1]midi/[7]portamento [style:knob]", 0, 0, 5, 0.05) : ba.tau2pole);

freq = frequency*bend : portamento;


pressure = hslider("v:saxophony/h:[2]Physical/Pressure
[2][tooltip:Breath pressure (a value between 0 and 1)][style:knob]",1,0,1,0.01);
reedStiffness = hslider("v:saxophony/h:[2]Physical/Reed_Stiffness
[2][tooltip:A value between 0 and 1][style:knob]",0.3,0,1,0.01);
blowPosition = hslider("v:saxophony/h:[2]Physical/Blow_Position
[2][tooltip:A value between 0 and 1][style:knob]",0.5,0,1,0.01);
noiseGain = hslider("v:saxophony/h:[2]Physical/Noise_Gain[style:knob]",0.05,0,1,0.01);


typeModulation = nentry("v:saxophony/h:[3]Nonlinear_Filter/Modulation_Type
[3][tooltip: 0=theta is modulated by the incoming signal; 1=theta is modulated by the averaged incoming signal;
2=theta is modulated by the squared incoming signal; 3=theta is modulated by a sine wave of frequency freqMod;
4=theta is modulated by a sine wave of frequency freq;][style:knob]",0,0,4,1);
nonLinearity = hslider("v:saxophony/h:[3]Nonlinear_Filter/Nonlinearity
[3][tooltip:Nonlinearity factor (value between 0 and 1)][style:knob]",0,0,1,0.01);
frequencyMod = hslider("v:saxophony/h:[3]Nonlinear_Filter/Modulation_Frequency [tooltip:Frequency of the sine wave for the modulation of theta (works if Modulation Type=3)][style:knob]", 2,0.1,5,0.1)*freq;
nonLinAttack = hslider("v:saxophony/h:[3]Nonlinear_Filter/Nonlinearity_Attack
[3][unit:s][Attack duration of the nonlinearity][style:knob]",0.1,0,2,0.01);


vibratoFreq = hslider("v:saxophony/h:[4]Vibrato/Vibrato_Freq
[4][unit:Hz][style:knob]",6,1,15,0.1);
vibratoGain = hslider("v:saxophony/h:[4]Vibrato/Vibrato_Gain
[4][tooltip:A value between 0 and 1][style:knob]",0.1,0,1,0.01);
vibratoBegin = hslider("v:saxophony/h:[4]Vibrato/Vibrato_Begin
[4][unit:s][tooltip:Vibrato silence duration before attack][style:knob]",0.05,0,2,0.01);
vibratoAttack = hslider("v:saxophony/h:[4]Vibrato/Vibrato_Attack
[4][unit:s][tooltip:Vibrato attack duration][style:knob]",0.3,0,2,0.01);
vibratoRelease = hslider("v:saxophony/h:[4]Vibrato/Vibrato_Release
[4][unit:s][tooltip:Vibrato release duration][style:knob]",0.1,0,2,0.01);


envelopeAttack = hslider("v:saxophony/h:[5]Envelope/Envelope_Attack
[5][unit:s][tooltip:Envelope attack duration][style:knob]",0.05,0,2,0.01);
envelopeRelease = hslider("v:saxophony/h:[5]Envelope/Envelope_Release
[5][unit:s][tooltip:Envelope release duration][style:knob]",0.01,0,2,0.01);

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

//reed table parameters
reedTableOffset = 0.7;
reedTableSlope = 0.1 + (0.4*reedStiffness);

//the reed function is declared in instruments.lib
reedTable = reed(reedTableOffset,reedTableSlope);

//Delay lines length in number of samples
fdel1 = (1-blowPosition) * (ma.SR/freq - 3);
fdel2 = (ma.SR/freq - 3)*blowPosition +1 ;

//Delay lines
delay1 = de.fdelay(4096,fdel1);
delay2 = de.fdelay(4096,fdel2);

//Breath pressure is controlled by an attack / sustain / release envelope (asr is declared in instruments.lib)
envelope = (0.55+pressure*0.3)*en.asr(pressure*envelopeAttack,1,pressure*envelopeRelease,gate);
breath = envelope + envelope*noiseGain*no.noise;

//envVibrato is decalred in instruments.lib
vibrato = vibratoGain*envVibrato(vibratoBegin,vibratoAttack,100,vibratoRelease,gate)*osc(vibratoFreq);
breathPressure = breath + breath*vibratoGain*os.osc(vibratoFreq);

//Body filter is a one zero filter (declared in instruments.lib)
bodyFilter = *(gain) : oneZero1(b0,b1)
	with{
		gain = -0.95;
		b0 = 0.5;
		b1 = 0.5;
	};

instrumentBody(delay1FeedBack,breathP) = delay1FeedBack <: -(delay2) <:
	((breathP - _ <: breathP - _*reedTable) - delay1FeedBack),_;

process =
	(bodyFilter,breathPressure : instrumentBody) ~
	(delay1 : NLFM) : !,
	//Scaling Output and stereo
	*(gain);
