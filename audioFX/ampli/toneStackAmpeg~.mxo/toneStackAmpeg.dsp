declare name      "Tonestack Emulation Ampeg";
declare author    "Guitarix";
declare description "Ampeg VL 501";

import("stdfaust.lib");



process = component("tonestacks.lib").ampeg(t,m,l) 
with {
	t = vslider("Treble ", 0.5, 0, 1, 0.01);
	m = vslider("Middle ", 0.5, 0, 1, 0.01);
	l = vslider("Bass ", 0.5, 0, 1, 0.01);
};
