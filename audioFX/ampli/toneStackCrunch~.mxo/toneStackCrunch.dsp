declare name      "Tonestack Emulation Crunch";
declare author    "Guitarix";
declare description "Crunch Hughes & Kettner";

import("stdfaust.lib");



process = component("tonestacks.lib").crunch(t,m,l) 
with {
	t = vslider("Treble ", 0.5, 0, 1, 0.01);
	m = vslider("Middle ", 0.5, 0, 1, 0.01);
	l = vslider("Bass ", 0.5, 0, 1, 0.01);
};
