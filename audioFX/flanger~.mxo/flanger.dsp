declare name "flanger";

import("stdfaust.lib");


process = _ <: _*dry, (_*wetdry:flanger) :> _
with {
	wetdry = vslider("[9] amount [style:knob]",  1, 0, 1, 0.01);
	dry = 1 - wetdry;

	invert = checkbox("[6] Invert Flange Sum");

	flanger = pf.flanger_mono(dmax,curdel,depth,fb,invert);

	lfo = os.osc;

	dmax = 2048;
	dflange = 0.001 * ma.SR *
		hslider("[1] Flange Delay [unit:ms] [style:knob]", 10, 0, 20, 0.001);
	odflange = 0.001 * ma.SR *
		hslider("[2] Delay Offset [unit:ms] [style:knob]", 1, 0, 20, 0.001);

	freq   = hslider("[3] Speed [unit:Hz] [style:knob]", 0.5, 0, 10, 0.01);
	depth  = hslider("[4] Depth [style:knob]", 1, 0, 1, 0.001);
	fb     = hslider("[5] Feedback [style:knob]", 0, -0.999, 0.999, 0.001);

	curdel = odflange+dflange*(1 + lfo(freq))/2;
};
