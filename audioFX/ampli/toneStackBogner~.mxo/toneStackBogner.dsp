declare name      "Tonestack Emulation Bogner";
declare author    "Guitarix";
declare description "Bogner Triple Giant Preamp";

import("stdfaust.lib");



process = component("tonestacks.lib").bogner(t,m,l) 
with {
	t = vslider("Treble ", 0.5, 0, 1, 0.01);
	m = vslider("Middle ", 0.5, 0, 1, 0.01);
	l = vslider("Bass ", 0.5, 0, 1, 0.01);
};
