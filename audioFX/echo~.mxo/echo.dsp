
declare name "echo";
declare description "delay with feedback";


import("stdfaust.lib");

dtime		= hslider("[1] delay[style:knob]", 0.001, 0, 5, 0.001) : si.smoo;
feedback	= hslider("[2] feedback[style:knob]", 0, 0, 0.99, 0.001);

wetdry = hslider("[3] amount [style:knob]",  1, 0, 1, 0.01) : si.smoo;
dry = 1 - wetdry;


frac(n) = n-int(n);
delay(n,d,x) = x@(int(d)&(n-1));
fdelay(n,d,x) = delay(n,int(d),x)*(1 - frac(d)) + delay(n,int(d)+1,x)*frac(d);

echo(dtime,feedback) = +~echoo
with {
	echoo	= fdelay(1<<18, ma.SR*dtime)*feedback;
};

process = vgroup("echo", _ <: _*dry, (_*wetdry:out) :> _)
with { out = echo(dtime,feedback); };
