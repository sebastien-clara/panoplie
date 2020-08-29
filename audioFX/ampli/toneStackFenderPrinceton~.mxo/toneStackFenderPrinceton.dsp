declare name      "Tonestack Emulation Fender Princeton";
declare author    "Guitarix";
declare description "Fender 64 Princeton AA1164";

import("stdfaust.lib");



process = component("tonestacks.lib").princeton(t,m,l) 
with {
	t = vslider("Treble ", 0.5, 0, 1, 0.01);
	m = vslider("Middle ", 0.5, 0, 1, 0.01);
	l = vslider("Bass ", 0.5, 0, 1, 0.01);
};
