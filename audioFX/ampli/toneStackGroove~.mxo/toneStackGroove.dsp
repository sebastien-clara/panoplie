declare name      "Tonestack Emulation Groove";
declare author    "Guitarix";
declare description "Groove Trio Preamp";

import("stdfaust.lib");



process = component("tonestacks.lib").groove(t,m,l) 
with {
	t = vslider("Treble ", 0.5, 0, 1, 0.01);
	m = vslider("Middle ", 0.5, 0, 1, 0.01);
	l = vslider("Bass ", 0.5, 0, 1, 0.01);
};
