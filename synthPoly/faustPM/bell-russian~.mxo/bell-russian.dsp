declare name "RussianrussianBell";
declare description "Russian church bell physical model.";
declare author "Sébastien Clara";
declare nvoices "8";

import("physmodels.lib");


///////////////////////////////////////////////////////////////
// GUI parameters
///////////////////////////////////////////////////////////////
gate = button("v:russianBell/[0]gate");
gain = vslider("v:russianBell/[2]gain[style:knob]", 1, 0, 3, 0.01);


strikePosition = nentry("v:russianBell/[0]strikePosition", 0,0,4,1);
strikeCutoff = hslider("v:russianBell/[1]strikeCutOff", 6500,20,20000,1);
strikeSharpness = hslider("v:russianBell/[2]strikeSharpness", 0.5,0.01,5,0.01);

///////////////////////////////////////////////////////////////
// DSP
///////////////////////////////////////////////////////////////
process = russianBell(strikePosition,strikeCutoff,strikeSharpness,gain,gate)*0.5;
