declare name "Flute";
declare description "Simple flute physical model with physical parameters.";
declare author "Sébastien Clara";
declare nvoices "8";

import("physmodels.lib");


///////////////////////////////////////////////////////////////
// GUI parameters
///////////////////////////////////////////////////////////////
envelop(a,d,s,r, gate, gain) = en.adsre(att, dec, sus, rel, gate) * gain
with {
	att = vslider("v:flute/h:[5]env/[1]A [style:knob] [tooltip:sec]", a, 0, 5, 0.01) : si.smoo;
	dec = vslider("v:flute/h:[5]env/[2]D [style:knob] [tooltip:sec]", d, 0, 5, 0.01) : si.smoo;
	sus = vslider("v:flute/h:[5]env/[3]S [style:knob] [tooltip:percentage of max : 0-1]", s, 0, 1, 0.01) : si.smoo;
	rel = vslider("v:flute/h:[5]env/[4]R [style:knob] [tooltip:sec]", r, 0.01, 5, 0.01) : si.smoo;
};


gate = button("v:flute/[0]gate");
frequency = vslider("v:flute/h:[1]midi/[0]freq[style:knob]", 440, 50, 2000, 1);
gain = vslider("v:flute/h:[1]midi/[2]gain[style:knob]", 1, 0, 3, 0.01);

bend = vslider("v:flute/h:[1]midi/[1]bend[hidden:1][midi:pitchwheel] [style:knob]",1,0.9,1.1,0.01) : si.polySmooth(gate,0.999,1);


mouthPosition = hslider("v:flute/h:[1]fluteParams/[0]mouthPosition [style:knob][midi:ctrl 1]",0.5,0,1,0.01) : si.smoo;
vibratoFreq = hslider("v:flute/h:[1]fluteParams/[1]vibratoFreq[style:knob]",5,1,10,0.01);
vibratoGain = hslider("v:flute/h:[1]fluteParams/[2]vibratoGain[style:knob]",0.5,0,1,0.01)*0.04;

///////////////////////////////////////////////////////////////
// DSP
///////////////////////////////////////////////////////////////
freq = frequency*bend;

tubeLength = freq : f2l;
pressure = envelop(0.3,0.2,0.8,0.3, gate, gain);
blow = blower(pressure,0.05,2000,vibratoFreq,vibratoGain);

process = fluteModel(tubeLength,mouthPosition,blow)*0.5;
