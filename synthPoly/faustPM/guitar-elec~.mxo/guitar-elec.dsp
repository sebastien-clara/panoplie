declare name "ElecGuitar";
declare description "Simple electric guitar model without effect chain.";
declare author "Sébastien Clara";
declare nvoices "8";

import("physmodels.lib");


///////////////////////////////////////////////////////////////
// GUI parameters
///////////////////////////////////////////////////////////////
gate = button("v:elecGuitar/[0]gate");
frequency = vslider("v:elecGuitar/h:[1]midi/[0]freq[style:knob]", 440, 50, 2000, 1);
gain = vslider("v:elecGuitar/h:[1]midi/[2]gain[style:knob]", 1, 0, 3, 0.01);

bend = vslider("v:elecGuitar/h:[1]midi/[1]bend[hidden:1][midi:pitchwheel] [style:knob]",1,0.9,1.1,0.01) : si.polySmooth(gate,0.999,1);

pluckPosition = hslider("v:elecGuitar/[1]pluckPosition[midi:ctrl 1]",0.8,0,1,0.01) : si.smoo;

///////////////////////////////////////////////////////////////
// DSP
///////////////////////////////////////////////////////////////
freq = frequency*bend;
stringLength = freq : f2l;

process = elecGuitar(stringLength,pluckPosition,1,gain,gate)*0.5;
