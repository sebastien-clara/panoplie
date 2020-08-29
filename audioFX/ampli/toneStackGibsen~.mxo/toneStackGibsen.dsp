declare name      "Tonestack Emulation Gibsen";
declare author    "Guitarix";
declare description "Gibsen gs12 reverbrocket";

import("stdfaust.lib");



process = component("tonestacks.lib").gibsen(t,m,l) 
with {
	t = vslider("Treble ", 0.5, 0, 1, 0.01);
	m = vslider("Middle ", 0.5, 0, 1, 0.01);
	l = vslider("Bass ", 0.5, 0, 1, 0.01);
};
