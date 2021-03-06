declare name "NylonGuitar";
declare description "Simple acoustic guitar model with nylon strings.";
declare author "Sébastien Clara";
declare nvoices "8";

import("physmodels.lib");


///////////////////////////////////////////////////////////////
// GUI parameters
///////////////////////////////////////////////////////////////
gate = button("v:nylonGuitar/[0]gate");
frequency = vslider("v:nylonGuitar/h:[1]midi/[0]freq[style:knob]", 440, 50, 2000, 1);
gain = vslider("v:nylonGuitar/h:[1]midi/[2]gain[style:knob]", 1, 0, 3, 0.01);

bend = vslider("v:nylonGuitar/h:[1]midi/[1]bend[hidden:1][midi:pitchwheel] [style:knob]",1,0.9,1.1,0.01) : si.polySmooth(gate,0.999,1);


pluckPosition = hslider("v:nylonGuitar/pluckPosition[midi:ctrl 1]",0.8,0,1,0.01) : si.smoo;

///////////////////////////////////////////////////////////////
// DSP
///////////////////////////////////////////////////////////////
freq = frequency*bend;
stringLength = freq : f2l;

process = nylonGuitar(stringLength,pluckPosition,gain,gate)*0.5;
