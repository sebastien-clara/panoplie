declare name      "Tonestack Emulation Marshall M-lead";
declare author    "Guitarix";
declare description "Marshall 67 Major Lead 200";

import("stdfaust.lib");



process = component("tonestacks.lib").mlead(t,m,l) 
with {
	t = vslider("Treble ", 0.5, 0, 1, 0.01);
	m = vslider("Middle ", 0.5, 0, 1, 0.01);
	l = vslider("Bass ", 0.5, 0, 1, 0.01);
};
