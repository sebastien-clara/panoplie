declare name      "Tonestack Emulation Sovtek";
declare author    "Guitarix";
declare description "Sovtek MIG 100 H";

import("stdfaust.lib");



process = component("tonestacks.lib").sovtek(t,m,l) 
with {
	t = vslider("Treble ", 0.5, 0, 1, 0.01);
	m = vslider("Middle ", 0.5, 0, 1, 0.01);
	l = vslider("Bass ", 0.5, 0, 1, 0.01);
};
