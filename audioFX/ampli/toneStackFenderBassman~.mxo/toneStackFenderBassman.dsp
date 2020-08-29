declare name      "Tonestack Emulation Fender Bassman";
declare author    "Guitarix";
declare description "Fender 59 Bassman 5F6-A";

import("stdfaust.lib");



process = component("tonestacks.lib").bassman(t,m,l) 
with {
	t = vslider("Treble ", 0.5, 0, 1, 0.01);
	m = vslider("Middle ", 0.5, 0, 1, 0.01);
	l = vslider("Bass ", 0.5, 0, 1, 0.01);
};
