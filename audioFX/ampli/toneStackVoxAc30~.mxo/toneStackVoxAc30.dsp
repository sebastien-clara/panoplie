declare name      "Tonestack Emulation Vox AC-30";
declare author    "Guitarix";
declare description "Vox 59/86 AC-30";

import("stdfaust.lib");



process = component("tonestacks.lib").ac30(t,m,l) 
with {
	t = vslider("Treble ", 0.5, 0, 1, 0.01);
	m = vslider("Middle ", 0.5, 0, 1, 0.01);
	l = vslider("Bass ", 0.5, 0, 1, 0.01);
};
