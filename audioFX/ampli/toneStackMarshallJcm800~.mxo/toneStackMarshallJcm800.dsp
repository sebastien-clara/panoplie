declare name      "Tonestack Emulation Marshall JCM-800";
declare author    "Guitarix";
declare description "Marshall 59/81 JCM-800 Lead 100 2203";

import("stdfaust.lib");



process = component("tonestacks.lib").jcm800(t,m,l) 
with {
	t = vslider("Treble ", 0.5, 0, 1, 0.01);
	m = vslider("Middle ", 0.5, 0, 1, 0.01);
	l = vslider("Bass ", 0.5, 0, 1, 0.01);
};
