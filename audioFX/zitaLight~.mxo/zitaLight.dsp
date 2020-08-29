declare name "zitaLight";

import("stdfaust.lib");


process = hgroup("Zita Light",(_,_ <: re.zita_rev1_stereo(rdel,f1,f2,t60dc,t60m,fsmax),_,_ :
	out_eq,_,_ : dry_wet : out_level))
with{
	fsmax = 48000.0;  // highest sampling rate that will be used
	rdel = 60;
	f1 = 200;
	t60dc = 3;
	t60m = 2;
	f2 = 6000;
	out_eq = pareq_stereo(eq1f,eq1l,eq1q) : pareq_stereo(eq2f,eq2l,eq2q);
	pareq_stereo(eqf,eql,Q) = fi.peak_eq_rm(eql,eqf,tpbt), fi.peak_eq_rm(eql,eqf,tpbt)
	with {
		tpbt = wcT/sqrt(max(0,g)); // tan(PI*B/SR), B bw in Hz (Q^2 ~ g/4)
		wcT = 2*ma.PI*eqf/ma.SR;  // peak frequency in rad/sample
		g = ba.db2linear(eql); // peak gain
	};
	eq1f = 315;
	eq1l = 0;
	eq1q = 3;
	eq2f = 1500;
	eq2l = 0;
	eq2q = 3;
//	dry_wet(x,y) = *(wet) + dry*x, *(wet) + dry*y
	dry_wet(x,y) = *(dry) + wet*x, *(dry) + wet*y
	with {
		wet = 0.5*(drywet+1.0);
		dry = 1.0-wet;
	};
	drywet = vslider("[1] Dry-Wet Mix [style:knob] [tooltip: -1 = dry, 1 = wet]",
		0,-1.0,1.0,0.01) : si.smoo;
	gain = vslider("[2] Level [unit:dB] [style:knob] [tooltip: Output scale
		factor]", -6, -70, 40, 0.1) : ba.db2linear : si.smoo;
	out_level = *(gain),*(gain);
};
