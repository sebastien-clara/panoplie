declare name      "Tonestack Emulation Soldano";
declare author    "Guitarix";
declare description "Soldano SLO 100";

import("stdfaust.lib");



process = component("tonestacks.lib").soldano(t,m,l) 
with {
	t = vslider("Treble ", 0.5, 0, 1, 0.01);
	m = vslider("Middle ", 0.5, 0, 1, 0.01);
	l = vslider("Bass ", 0.5, 0, 1, 0.01);
};
