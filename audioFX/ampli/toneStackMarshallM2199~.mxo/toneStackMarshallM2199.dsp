declare name      "Tonestack Emulation Marshall M-2199";
declare author    "Guitarix";
declare description "Marshall undated M2199 30W solid state";

import("stdfaust.lib");



process = component("tonestacks.lib").m2199(t,m,l) 
with {
	t = vslider("Treble ", 0.5, 0, 1, 0.01);
	m = vslider("Middle ", 0.5, 0, 1, 0.01);
	l = vslider("Bass ", 0.5, 0, 1, 0.01);
};
