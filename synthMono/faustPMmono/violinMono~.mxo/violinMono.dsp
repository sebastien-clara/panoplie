declare name "Violin";
declare description "Simple violin physical model controlled with continuous parameters.";
declare author "Sébastien Clara";

import("physmodels.lib");


///////////////////////////////////////////////////////////////
// GUI parameters
///////////////////////////////////////////////////////////////
envelop(a,d,s,r, gate, gain) = en.adsre(att, dec, sus, rel, gate) * gain
with {
	att = vslider("v:violin/h:[5]env/[1]A [style:knob] [tooltip:sec]", a, 0, 5, 0.01) : si.smoo;
	dec = vslider("v:violin/h:[5]env/[2]D [style:knob] [tooltip:sec]", d, 0, 5, 0.01) : si.smoo;
	sus = vslider("v:violin/h:[5]env/[3]S [style:knob] [tooltip:percentage of max : 0-1]", s, 0, 1, 0.01) : si.smoo;
	rel = vslider("v:violin/h:[5]env/[4]R [style:knob] [tooltip:sec]", r, 0.01, 5, 0.01) : si.smoo;
};

gate = button("v:violin/[0]gate");
frequency = vslider("v:violin/h:[1]midi/[0]freq[style:knob]", 440, 50, 4000, 1) : portamento;
gain = vslider("v:violin/h:[1]midi/[2]gain[style:knob]", 1, 0, 3, 0.01);

bend = vslider("v:violin/h:[1]midi/[1]bend[hidden:1][midi:pitchwheel] [style:knob]",1,0.9,1.1,0.01) : si.smoo;
portamento = si.smooth(vslider("v:violin/h:[1]midi/[3]portamento [style:knob]", 0, 0, 5, 0.05) : ba.tau2pole);


bowPress = hslider("v:violin/h:[1]bow/[0]pressure[style:knob] [midi:ctrl 1]",0.5,0,1,0.01) : si.smoo;
bowPos = hslider("v:violin/h:[1]bow/[1]position[style:knob]",0.7,0,1,0.01) : si.smoo;

vibratoFreq = hslider("v:violin/h:[2]vib/[0]vibratoFrequency [style:knob]",6,1,10,0.01);
vibratoGain = hslider("v:violin/h:[2]vib/[1]vibratoGain [style:knob]",0.25,0,1,0.01)*0.01;


///////////////////////////////////////////////////////////////
// DSP
///////////////////////////////////////////////////////////////
env = envelop(0.05,0.2,0.8,0.3, gate, gain);
vibrato = 1+os.osc(vibratoFreq)*vibratoGain*env;
freq = frequency*bend*vibrato;

stringLength = freq : f2l;
bowVel = env;

process = violinModel(stringLength,bowPress,bowVel,bowPos)*0.5;
