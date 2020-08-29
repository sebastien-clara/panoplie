declare name      "Tonestack Emulation Roland";
declare author    "Guitarix";
declare description "Roland Cube 60";

import("stdfaust.lib");



process = component("tonestacks.lib").roland(t,m,l) 
with {
	t = vslider("Treble ", 0.5, 0, 1, 0.01);
	m = vslider("Middle ", 0.5, 0, 1, 0.01);
	l = vslider("Bass ", 0.5, 0, 1, 0.01);
};
