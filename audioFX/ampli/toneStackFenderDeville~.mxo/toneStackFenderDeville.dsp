declare name      "Tonestack Emulation Fender Deville";
declare author    "Guitarix";
declare description "Fender Deville Hot Rod";

import("stdfaust.lib");



process = component("tonestacks.lib").fender_deville(t,m,l) 
with {
	t = vslider("Treble ", 0.5, 0, 1, 0.01);
	m = vslider("Middle ", 0.5, 0, 1, 0.01);
	l = vslider("Bass ", 0.5, 0, 1, 0.01);
};
