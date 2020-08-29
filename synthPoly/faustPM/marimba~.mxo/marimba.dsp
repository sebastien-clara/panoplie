declare name "MarimbaMIDI";
declare description "Simple MIDI-controllable marimba physical model.";
declare author "Sébastien Clara";
declare nvoices "8";

import("physmodels.lib");


///////////////////////////////////////////////////////////////
// GUI parameters
///////////////////////////////////////////////////////////////
gate = button("v:marimba/[0]gate");
freq = vslider("v:marimba/h:[1]midi/[0]freq[style:knob]", 220, 50, 2000, 1);
gain = vslider("v:marimba/h:[1]midi/[2]gain[style:knob]", 1, 0, 3, 0.01);

bend = vslider("v:marimba/h:[1]midi/[1]bend[hidden:1][midi:pitchwheel] [style:knob]",1,0.9,1.1,0.01) : si.polySmooth(gate,0.999,1);


strikePosition = nentry("v:marimba/h:[1]marimbaParams/[0]strikePosition [midi:ctrl 1]",0,0,4,1);
strikeCutoff = hslider("v:marimba/h:[1]marimbaParams/[1]strikeCutOff [midi:ctrl 1][style:knob]",6500,20,20000,1);
strikeSharpness = hslider("v:marimba/h:[1]marimbaParams/[2]strikeSharpness [style:knob]",0.5,0.01,5,0.01);


///////////////////////////////////////////////////////////////
// DSP
///////////////////////////////////////////////////////////////

process = marimba(freq,strikePosition,strikeCutoff,strikeSharpness,gain,gate);
