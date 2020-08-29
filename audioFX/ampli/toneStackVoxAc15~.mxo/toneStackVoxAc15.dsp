declare name      "Tonestack Emulation Vox AC-15";
declare author    "Guitarix";
declare description "VOX AC-15";

import("stdfaust.lib");



process = component("tonestacks.lib").ac15(t,m,l) 
with {
	t = vslider("Treble ", 0.5, 0, 1, 0.01);
	m = vslider("Middle ", 0.5, 0, 1, 0.01);
	l = vslider("Bass ", 0.5, 0, 1, 0.01);
};
