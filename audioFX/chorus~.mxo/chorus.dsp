declare name "chorus";


import("stdfaust.lib");

freq	= hslider("[1]freq[style:knob]", 3, 0, 15, 0.01);
dtime	= hslider("[2]delay[style:knob]", 0.001, 0, 0.2, 0.001) : si.smoo;
depth	= hslider("[3]depth[style:knob]", 0.02, 0, 1, 0.001) : si.smoo;
level	= hslider("[4]level[style:knob]", 1, 0, 1, 0.01) : si.smoo;


decimal(x) = x - floor(x);
time = (+(1)~_ ) - 1; 			// 0,1,2,3,...

frac(n) = n-int(n);
delay(n,d,x) = x@(int(d)&(n-1));
fdelay(n,d,x) = delay(n,int(d),x)*(1 - frac(d)) + delay(n,int(d)+1,x)*frac(d);

tblosc(n,f,freq,mod)	= (1-d)*rdtable(n,wave,i&(n-1)) + d*rdtable(n,wave,(i+1)&(n-1))
with {
	wave	 	= time*(2.0*ma.PI)/n : f;
	phase		= freq/ma.SR : (+ : decimal) ~ _;
	modphase	= decimal(phase+mod/(2*ma.PI))*n;
	i		= int(floor(modphase));
	d		= decimal(modphase);
};

chorus(dtime,freq,depth,phase,x) = x+level*fdelay(1<<16, t, x)
with {
	t		= ma.SR*dtime/2*(1+depth*tblosc(1<<16, sin, freq, phase));
};

process = vgroup("chorus", chorus(dtime,freq,depth,0));
