declare name "Djembe";
declare description "Simple MIDI-controllable djembe physical model.";
declare author "Sébastien Clara";
declare nvoices "8";

import("physmodels.lib");

///////////////////////////////////////////////////////////////
// GUI parameters
///////////////////////////////////////////////////////////////
gate = button("v:djembe/[0]gate");
freq = vslider("v:djembe/h:[1]midi/[0]freq[style:knob]", 60, 25, 2000, 1);
gain = vslider("v:djembe/h:[1]midi/[2]gain[style:knob]", 1, 0, 3, 0.01);

strikePosition = hslider("v:djembe/h:[1]djembeParams/[0]strikePosition [midi:ctrl 1] [style:knob]",0.5,0,1,0.01);
strikeSharpness = hslider("v:djembe/h:[1]djembeParams/[1]strikeSharpness [style:knob]",0.5,0.01,5,0.01);



process = djembe(freq,strikePosition,strikeSharpness,gain,gate)*0.5;
