declare name      "Tonestack Emulation Fender Twin";
declare author    "Guitarix";
declare description "Fender 69 Twin Reverb AA270";

import("stdfaust.lib");



process = component("tonestacks.lib").twin(t,m,l) 
with {
	t = vslider("Treble ", 0.5, 0, 1, 0.01);
	m = vslider("Middle ", 0.5, 0, 1, 0.01);
	l = vslider("Bass ", 0.5, 0, 1, 0.01);
};
