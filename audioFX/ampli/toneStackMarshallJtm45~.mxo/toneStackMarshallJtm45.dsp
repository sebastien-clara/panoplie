declare name      "Tonestack Emulation Marshall JTM 45";
declare author    "Guitarix";
declare description "Marshall JTM 45";

import("stdfaust.lib");



process = component("tonestacks.lib").jtm45(t,m,l) 
with {
	t = vslider("Treble ", 0.5, 0, 1, 0.01);
	m = vslider("Middle ", 0.5, 0, 1, 0.01);
	l = vslider("Bass ", 0.5, 0, 1, 0.01);
};
