declare name      "Tonestack Emulation Mesa Boogie";
declare author    "Guitarix";
declare description "Fender Mesa Boogie Mark";

import("stdfaust.lib");



process = component("tonestacks.lib").mesa(t,m,l) 
with {
	t = vslider("Treble ", 0.5, 0, 1, 0.01);
	m = vslider("Middle ", 0.5, 0, 1, 0.01);
	l = vslider("Bass ", 0.5, 0, 1, 0.01);
};
