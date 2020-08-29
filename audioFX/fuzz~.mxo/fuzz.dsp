declare name "fuzz";
declare category "Distortion";
declare description "A simple waveshaping effect";


import("stdfaust.lib");

dist	= hslider("[1] distortion [style:knob]", 12, 0, 100, 0.1);	// distortion parameter
gain	= hslider("[9] gain [style:knob]", 3, -96, 96, 0.1) : si.smoo;		// output gain (dB)

wetdry = hslider("[3] amount [style:knob]",  1, 0, 1, 0.01) : si.smoo;
dry = 1 - wetdry;

// the waveshaping function
f(a,x)	= x*(abs(x) + a)/(x*x + (a-1)*abs(x) + 1);

// gain correction factor to compensate for distortion
g(a)	= 1/sqrt(a+1);

fc = hslider("tone[name:Tone][style:knob]", 400, 100, 2000, 1);
lpFilter = fi.lowpass(1,fc);

fuzz(x) = ba.db2linear(gain)*g(dist)*f(ba.db2linear(dist),x) : lpFilter;

process	= vgroup("[2] distortion", _ <: _*dry, (_*wetdry:fuzz) :> _);
