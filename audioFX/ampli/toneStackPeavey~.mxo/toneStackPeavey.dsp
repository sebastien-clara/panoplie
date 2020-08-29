declare name      "Tonestack Emulation Peavey";
declare author    "Guitarix";
declare description "Peavey c20";

import("stdfaust.lib");



process = component("tonestacks.lib").peavey(t,m,l) 
with {
	t = vslider("Treble ", 0.5, 0, 1, 0.01);
	m = vslider("Middle ", 0.5, 0, 1, 0.01);
	l = vslider("Bass ", 0.5, 0, 1, 0.01);
};
