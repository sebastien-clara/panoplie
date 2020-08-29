declare name "EnglishenglishBell";
declare description "English church bell physical model.";
declare author "Sébastien Clara";
declare nvoices "8";

import("physmodels.lib");


///////////////////////////////////////////////////////////////
// GUI parameters
///////////////////////////////////////////////////////////////
gate = button("v:englishBell/[4]gate");
gain = vslider("v:englishBell/[3]gain[style:knob]", 1, 0, 3, 0.01);

strikePosition = nentry("v:englishBell/[0]strikePosition", 0,0,4,1);
strikeCutoff = hslider("v:englishBell/[1]strikeCutOff", 6500,20,20000,1);
strikeSharpness = hslider("v:englishBell/[2]strikeSharpness", 0.5,0.01,5,0.01);

///////////////////////////////////////////////////////////////
// DSP
///////////////////////////////////////////////////////////////
process = englishBell(strikePosition,strikeCutoff,strikeSharpness,gain,gate)*0.5;
