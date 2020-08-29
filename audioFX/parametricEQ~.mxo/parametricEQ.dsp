// A parametric equalizer application.
//
// #### Usage:
//
// ```
// _ : parametric_eq : _ ;
// ```
//------------------------------------------------------------
declare name "parametricEQ";

import("stdfaust.lib");



process = fi.low_shelf(LL,FL) : fi.peak_eq(LP,FP,BP) : fi.high_shelf(LH,FH)
with{
	eq_group(x) = hgroup("[0] PARAMETRIC EQ SECTIONS [tooltip: See Faust's filters.lib
		for info and pointers]",x);
	ls_group(x) = eq_group(vgroup("[1] Low Shelf",x));

	LL = ls_group(hslider("[0] Low Boost|Cut [unit:dB] [style:knob]
		[tooltip: Amount of low-frequency boost or cut in decibels]",0,-40,40,0.1));
	FL = ls_group(hslider("[1] Transition Frequency [unit:Hz] [style:knob] [scale:log]
		[tooltip: Transition-frequency from boost (cut) to unity gain]",200,1,5000,1));


	pq_group(x) = eq_group(vgroup("[2] Peaking Equalizer[tooltip: Parametric Equalizer
		sections from filters.lib]",x));
	LP = pq_group(hslider("[0] Peak Boost|Cut [unit:dB] [style:knob][tooltip: Amount of
		local boost or cut in decibels]",0,-40,40,0.1));
	FP = pq_group(hslider("[1] Peak Frequency [unit:Hz] [style:knob] [tooltip: Peak
			Frequency]",2500,20,10000,1)) : si.smooth(0.999);
	Q = pq_group(hslider("[2] Peak Q [style:knob] [scale:log] [tooltip: Quality factor
			(Q) of the peak = center-frequency/bandwidth]",10,0.1,100,0.1));
	BP = FP/Q;


	hs_group(x) = eq_group(vgroup("[3] High Shelf [tooltip: A high shelf provides a boost
		or cut above some frequency]",x));
	LH = hs_group(hslider("[0] High Boost|Cut [unit:dB] [style:knob] [tooltip: Amount of
		high-frequency boost or cut in decibels]",0,-40,40,.1));
	FH = hs_group(hslider("[1] Transition Frequency [unit:Hz] [style:knob] [scale:log]
	[tooltip: Transition-frequency from boost (cut) to unity gain]",8000,20,10000,1));
};
