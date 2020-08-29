declare name "Clarinet";
declare description "Simple clarinet physical model with physical parameters.";
declare author "Sébastien Clara";
declare nvoices "8";

import("physmodels.lib");


///////////////////////////////////////////////////////////////
// GUI parameters
///////////////////////////////////////////////////////////////
envelop(a,d,s,r, gate, gain) = en.adsre(att, dec, sus, rel, gate) * gain
with {
	att = vslider("v:clarinet/h:[5]env/[1]A [style:knob] [tooltip:sec]", a, 0, 5, 0.01) : si.smoo;
	dec = vslider("v:clarinet/h:[5]env/[2]D [style:knob] [tooltip:sec]", d, 0, 5, 0.01) : si.smoo;
	sus = vslider("v:clarinet/h:[5]env/[3]S [style:knob] [tooltip:percentage of max : 0-1]", s, 0, 1, 0.01) : si.smoo;
	rel = vslider("v:clarinet/h:[5]env/[4]R [style:knob] [tooltip:sec]", r, 0.01, 5, 0.01) : si.smoo;
};

gate = button("v:clarinet/[0]gate");
frequency = vslider("v:clarinet/h:[1]midi/[0]freq[style:knob]", 440, 50, 2000, 1);
gain = vslider("v:clarinet/h:[1]midi/[2]gain[style:knob]", 1, 0, 3, 0.01);

bend = vslider("v:clarinet/h:[1]midi/[1]bend[hidden:1][midi:pitchwheel] [style:knob]",1,0.9,1.1,0.01) : si.polySmooth(gate,0.999,1);


reedStiffness = hslider("v:clarinet/h:[1]clarinetParams/[0]reedStiffness [midi:ctrl 1][style:knob]",0.5,0,1,0.01);
bellOpening = hslider("v:clarinet/h:[1]clarinetParams/[1]bellOpening [midi:ctrl 3][style:knob]",0.5,0,1,0.01);
vibratoFreq = hslider("v:clarinet/h:[1]clarinetParams/[2]vibratoFreq [style:knob]",5,1,10,0.01);
vibratoGain = hslider("v:clarinet/h:[1]clarinetParams/[3]vibratoGain [style:knob]",0.25,0,1,0.01)*0.01;


///////////////////////////////////////////////////////////////
// DSP
///////////////////////////////////////////////////////////////
env = envelop(0.3,0.2,0.8,0.3, gate, gain);

vibrato = 1+os.osc(vibratoFreq)*vibratoGain*env;
freq = frequency*bend*vibrato;

tubeLength = freq : f2l;
pressure = env;

blow = blower(pressure,0.05,2000,vibratoFreq,vibratoGain);

process = clarinetModel(tubeLength,blow,reedStiffness,bellOpening)*0.5;
