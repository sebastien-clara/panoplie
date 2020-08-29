declare name "flute";
declare description "Nonlinear WaveGuide Flute";
declare author "Sébastien Clara";
declare licence "STK-4.3"; // Synthesis Tool Kit 4.3 (MIT style license);
declare description "A simple flute based on Smith algorythm: https://ccrma.stanford.edu/~jos/pasp/Flutes_Recorders_Pipe_Organs.html";

import("instruments.lib");

//==================== GUI SPECIFICATION ================

frequency = vslider("v:flute/h:[1]midi/freq [1][unit:Hz] [tooltip:Tone frequency][style:knob]",440,20,5000,1);
gain = vslider("v:flute/h:[1]midi/gain [1][tooltip:Gain (value between 0 and 1)][style:knob]",1,0,1,0.01);
gate = button("v:flute/h:[1]midi/gate [1][tooltip:noteOn = 1, noteOff = 0]") : int;
bend = vslider("v:flute/h:[1]midi/[1]bend[hidden:1][midi:pitchwheel][style:knob]",1,0.9,1.1,0.01) : si.polySmooth(gate,0.999,1);

freq = frequency*bend;


pressure = hslider("v:flute/h:[2]Physical/Pressure
[2][tooltip:Breath pressure (value bewteen 0 and 1)][style:knob]",0.9,0,1,0.01)*0.5+0.5 : si.smoo;
breathAmp = hslider("v:flute/h:[2]Physical/Noise Gain
[2][tooltip:Breath noise gain (value between 0 and 1)][style:knob]",0.1,0,1,0.01)/10;


typeModulation = nentry("v:flute/h:[3]Nonlinear_Filter/Modulation_Type
[3][tooltip: 0=theta is modulated by the incoming signal; 1=theta is modulated by the averaged incoming signal;
2=theta is modulated by the squared incoming signal; 3=theta is modulated by a sine wave of frequency freqMod;
4=theta is modulated by a sine wave of frequency freq;][style:knob]",0,0,4,1);
nonLinearity = hslider("v:flute/h:[3]Nonlinear_Filter/Nonlinearity
[3][tooltip:Nonlinearity factor (value between 0 and 1)][style:knob]",0,0,1,0.01);
frequencyMod = hslider("v:flute/h:[3]Nonlinear_Filter/Modulation_Frequency [tooltip:Frequency of the sine wave for the modulation of theta (works if Modulation Type=3)][style:knob]", 2,0.1,5,0.1)*freq;
nonLinAttack = hslider("v:flute/h:[3]Nonlinear_Filter/Nonlinearity Attack
[3][unit:s][Attack duration of the nonlinearity][style:knob]",0.1,0,2,0.01);


vibratoFreq = hslider("v:flute/h:[4]Vibrato/Vibrato_Freq
[4][unit:Hz][style:knob]",5,1,15,0.1);
vibratoGain = hslider("v:flute/h:[4]Vibrato/Vibrato_Gain
[4][tooltip:A value between 0 and 1][style:knob]",0.1,0,1,0.01);
vibratoBegin = hslider("v:flute/h:[4]Vibrato/Vibrato_Begin
[4][unit:s][tooltip:Vibrato silence duration before attack][style:knob]",0.1,0,2,0.01);
vibratoAttack = hslider("v:flute/h:[4]Vibrato/Vibrato_Attack
[4][unit:s][tooltip:Vibrato attack duration][style:knob]",0.05,0,2,0.01);
vibratoRelease = hslider("v:flute/h:[4]Vibrato/Vibrato_Release
[4][unit:s][tooltip:Vibrato release duration][style:knob]",0.2,0.01,2,0.01);


pressureEnvelope = checkbox("v:flute/h:[5]Pressure_Envelope/Pressure_Env
[5][unit:s][tooltip:Activate Pressure envelope][style:knob]") : int;
env1Attack = hslider("v:flute/h:[5]Pressure_Envelope/Press_Env_Attack
[5][unit:s][tooltip:Pressure envelope attack duration][style:knob]",0.05,0,2,0.01);
env1Decay = hslider("v:flute/h:[5]Pressure_Envelope/Press_Env_Decay
[5][unit:s][tooltip:Pressure envelope decay duration][style:knob]",0.2,0,2,0.01);
env1Release = hslider("v:flute/h:[5]Pressure_Envelope/Press_Env_Release
[5][unit:s][tooltip:Pressure envelope release duration][style:knob]",1,0.01,2,0.01);

env2Attack = hslider("v:flute/h:[6]Global_Envelope/Glob_Env_Attack
[6][unit:s][tooltip:Global envelope attack duration][style:knob]",0.1,0,2,0.01);
env2Release = hslider("v:flute/h:[6]Global_Envelope/Glob_Env_Release
[6][unit:s][tooltip:Global envelope release duration][style:knob]",0.1,0.01,2,0.01);

//==================== SIGNAL PROCESSING ================

//----------------------- Nonlinear filter ----------------------------
//nonlinearities are created by the nonlinear passive allpass ladder filter declared in miscfilter.lib

//nonlinear filter order
nlfOrder = 6;

//attack - sustain - release envelope for nonlinearity (declared in instruments.lib)
envelopeMod = en.asr(nonLinAttack,1,0.1,gate);

//nonLinearModultor is declared in instruments.lib, it adapts allpassnn from miscfilter.lib
//for using it with waveguide instruments
NLFM =  nonLinearModulator((nonLinearity : si.smoo),envelopeMod,freq,
     typeModulation,(frequencyMod : si.smoo),nlfOrder);

//----------------------- Synthesis parameters computing and functions declaration ----------------------------

//Loops feedbacks gains
feedBack1 = 0.4;
feedBack2 = 0.4;

//Delay Lines
embouchureDelayLength = (ma.SR/freq)/2-2;
boreDelayLength = ma.SR/freq-2;
embouchureDelay = de.fdelay(4096,embouchureDelayLength);
boreDelay = de.fdelay(4096,boreDelayLength);

//Polinomial
poly = _ <: _ - _*_*_;

//jet filter is a lowpass filter (declared in miscfilter.lib)
reflexionFilter = fi.lowpass(1,2000);


//----------------------- Algorithm implementation ----------------------------

//Pressure envelope
env1 = en.adsr(env1Attack,env1Decay,0.9,env1Release,(gate | pressureEnvelope))*pressure*1.1;

//Global envelope
env2 = en.asr(env2Attack,1,env2Release,gate)*0.5;

//Vibrato Envelope
vibratoEnvelope = envVibrato(vibratoBegin,vibratoAttack,100,vibratoRelease,gate)*vibratoGain;

vibrato = os.osc(vibratoFreq)*vibratoEnvelope;

breath = no.noise*env1;

flow = env1 + breath*breathAmp + vibrato;


//instrReverb is declared in instruments.lib
process = (_ <: (flow + *(feedBack1) : embouchureDelay : poly) + *(feedBack2) : reflexionFilter)~(boreDelay : NLFM) : *(env2)*gain;
