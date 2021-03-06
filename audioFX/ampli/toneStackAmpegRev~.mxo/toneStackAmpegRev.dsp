declare name      "Tonestack Emulation Ampeg Rev";
declare author    "Guitarix";
declare description "Ampeg reverbrocket";

import("stdfaust.lib");



process = component("tonestacks.lib").ampeg_rev(t,m,l) 
with {
	t = vslider("Treble ", 0.5, 0, 1, 0.01);
	m = vslider("Middle ", 0.5, 0, 1, 0.01);
	l = vslider("Bass ", 0.5, 0, 1, 0.01);
};
