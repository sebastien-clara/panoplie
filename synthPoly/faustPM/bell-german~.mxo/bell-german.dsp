declare name "GermanBell";
declare description "German church bell physical model.";
declare author "Sébastien Clara";
declare nvoices "8";

import("physmodels.lib");


///////////////////////////////////////////////////////////////
// GUI parameters
///////////////////////////////////////////////////////////////
gate = button("v:germanBell/[0]gate");
gain = vslider("v:germanBell/[2]gain[style:knob]", 1, 0, 3, 0.01);


strikePosition = nentry("v:germanBell/[0]strikePosition", 0,0,4,1);
strikeCutoff = hslider("v:germanBell/[1]strikeCutOff", 6500,20,20000,1);
strikeSharpness = hslider("v:germanBell/[2]strikeSharpness", 	0.5,0.01,5,0.01);

///////////////////////////////////////////////////////////////
// DSP
///////////////////////////////////////////////////////////////
process = germanBell(strikePosition,strikeCutoff,strikeSharpness,gain,gate)*0.5;
