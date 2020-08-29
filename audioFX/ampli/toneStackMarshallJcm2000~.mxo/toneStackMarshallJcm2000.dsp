declare name      "Tonestack Emulation Marshall JCM-2000";
declare author    "Guitarix";
declare description "Marshall JCM 2000 / TSL 100";

import("stdfaust.lib");



process = component("tonestacks.lib").jcm2000(t,m,l) 
with {
	t = vslider("Treble ", 0.5, 0, 1, 0.01);
	m = vslider("Middle ", 0.5, 0, 1, 0.01);
	l = vslider("Bass ", 0.5, 0, 1, 0.01);
};
