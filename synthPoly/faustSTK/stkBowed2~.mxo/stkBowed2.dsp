declare name "bowed";
declare description "Nonlinear WaveGuide Bowed Instrument";
declare author "Sébastien Clara";
declare licence "STK-4.3"; // Synthesis Tool Kit 4.3 (MIT style license);
declare description "A bowed string model, a la Smith (1986), after McIntyre, Schumacher, Woodhouse (1983).";
declare reference "https://ccrma.stanford.edu/~jos/pasp/Bowed_Strings.html";

import("instruments.lib");

//==================== GUI SPECIFICATION ================

frequency = vslider("v:bowed/h:[1]midi/freq [1][unit:Hz] [tooltip:Tone frequency][style:knob]",440,20,5000,1);
gain = vslider("v:bowed/h:[1]midi/gain [1][tooltip:Gain (value between 0 and 1)][style:knob]",1,0,1,0.01);
gate = button("v:bowed/h:[1]midi/gate [1][tooltip:noteOn = 1, noteOff = 0]");
bend = vslider("v:bowed/h:[1]midi/[1]bend[hidden:1][midi:pitchwheel] [style:knob]",1,0.9,1.1,0.01) : si.polySmooth(gate,0.999,1);

freq = frequency*bend;


bowPosition = hslider("v:bowed/h:[2]Physical/Bow_Position
[2][tooltip:Bow position along the string (value between 0 and 1)][style:knob]",0.7,0.01,1,0.01);
bowPressure = hslider("v:bowed/h:[2]Physical/Bow_Pressure
[2][tooltip:Bow pressure on the string (value between 0 and 1)][style:knob]",0.75,0,1,0.01);


typeModulation = nentry("v:bowed/h:[3]Nonlinear_Filter/Modulation_Type
[3][tooltip: 0=theta is modulated by the incoming signal; 1=theta is modulated by the averaged incoming signal;
2=theta is modulated by the squared incoming signal; 3=theta is modulated by a sine wave of frequency freqMod;
4=theta is modulated by a sine wave of frequency freq;][style:knob]",0,0,4,1);
nonLinearity = hslider("v:bowed/h:[3]Nonlinear_Filter/Nonlinearity
[3][tooltip:Nonlinearity factor (value between 0 and 1)][style:knob]",0,0,1,0.01);
frequencyMod = hslider("v:bowed/h:[3]Nonlinear_Filter/Modulation_Frequency [tooltip:Frequency of the sine wave for the modulation of theta (works if Modulation Type=3)][style:knob]", 2,0.1,5,0.1)*freq;
nonLinAttack = hslider("v:bowed/h:[3]Nonlinear_Filter/Nonlinearity_Attack
[3][unit:s][Attack duration of the nonlinearity][style:knob]",0.1,0,2,0.01);


vibratoFreq = hslider("v:bowed/h:[4]Vibrato/Vibrato_Freq
[4][unit:Hz][style:knob]",6,1,15,0.1);
vibratoGain = hslider("v:bowed/h:[4]Vibrato/Vibrato_Gain
[4][tooltip:A value between 0 and 1][style:knob]",0.01,0,1,0.01);
vibratoBegin = hslider("v:bowed/h:[4]Vibrato/Vibrato_Begin
[4][unit:s][tooltip:Vibrato silence duration before attack][style:knob]",0.05,0,2,0.01);
vibratoAttack = hslider("v:bowed/h:[4]Vibrato/Vibrato_Attack
[4][unit:s][tooltip:Vibrato attack duration][style:knob]",0.05,0,2,0.01);
vibratoRelease = hslider("v:bowed/h:[4]Vibrato/Vibrato_Release
[4][unit:s][tooltip:Vibrato release duration][style:knob]",0.01,0.01,2,0.01);


envelopeAttack = hslider("v:bowed/h:[6]Envelope/Envelope_Attack
[5][unit:s][tooltip:Envelope attack duration][style:knob]",0.01,0,2,0.01);
envelopeDecay = hslider("v:bowed/h:[6]Envelope/Envelope_Decay
[5][unit:s][tooltip:Envelope decay duration][style:knob]",0.05,0,2,0.01);
envelopeRelease = hslider("v:bowed/h:[6]Envelope/Envelope_Release
[5][unit:s][tooltip:Envelope release duration][style:knob]",0.1,0.01,2,0.01);

//==================== SIGNAL PROCESSING ================

//----------------------- Nonlinear filter ----------------------------
//nonlinearities are created by the nonlinear passive allpass ladder filter declared in miscfilter.lib

//nonlinear filter order
nlfOrder = 6;

//attack - sustain - release envelope for nonlinearity (declared in instruments.lib)
envelopeMod = en.asr(nonLinAttack,1,envelopeRelease,gate);

//nonLinearModultor is declared in instruments.lib, it adapts allpassnn from miscfilter.lib
//for using it with waveguide instruments
NLFM = nonLinearModulator((nonLinearity : si.smoo),envelopeMod,freq,
     typeModulation,(frequencyMod : si.smoo),nlfOrder);

//----------------------- Synthesis parameters computing and functions declaration ----------------------------

//Parameters for the bow table
tableOffset =  0;
tableSlope = 5 - (4*bowPressure);

//the bow table is declared in instruments.lib
bowTable = bow(tableOffset,tableSlope);

//a attack - decay - sustain - release envelope is used
envelope = en.adsr(gain*envelopeAttack,envelopeDecay,1, (1-gain)*envelopeRelease,gate);
maxVelocity = 0.03 + (0.2 * gain);

//Delay lines declaration and vibrato, the length of the two delay lines are evolving propotionally
betaRatio = 0.027236 + (0.2*bowPosition);
fdelneck = (ma.SR/freq-4)*(1 - betaRatio);
vibratoEnvelope = envVibrato(vibratoBegin,vibratoAttack,100,vibratoRelease,gate);
vibrato = fdelneck + ((ma.SR/freq - 4)*vibratoGain*vibratoEnvelope*os.osc(vibratoFreq));
neckDelay = de.fdelay(4096,vibrato);
fdelbridge = (ma.SR/freq - 4)*betaRatio;
bridgeDelay = de.delay(4096,fdelbridge);

//Body Filter: a biquad filter with a normalized pick gain (declared in instruments.lib)
bodyFilter = bandPass(500,0.85);

//String Filter: a lowpass filter (declared in instruments.lib)
stringFilter = *(0.95) : -onePole(b0,a1)
	with{
		pole = 0.6 - (0.1*22050/ma.SR);
		gain = 0.95;
		b0 = 1-pole;
		a1 = -pole;
	};


//----------------------- Algorithm implementation ----------------------------

bowVelocity = envelope*maxVelocity;
instrumentBody(feedBckBridge) = (*(-1) <: +(feedBckBridge),_ : (bowVelocity-_ <: *(bowTable) <: _,_),_ :
	_, + : +(feedBckBridge),_) ~ (neckDelay) : !,_;


process = (stringFilter : instrumentBody) ~ (bridgeDelay : NLFM) : bodyFilter(*(0.2)) :
	_*gain*2;
