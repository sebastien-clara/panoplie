declare name      "Tonestack Emulation Ibanez";
declare author    "Guitarix";
declare description "Ibanez gx20";

import("stdfaust.lib");



process = component("tonestacks.lib").ibanez(t,m,l) 
with {
	t = vslider("Treble ", 0.5, 0, 1, 0.01);
	m = vslider("Middle ", 0.5, 0, 1, 0.01);
	l = vslider("Bass ", 0.5, 0, 1, 0.01);
};
