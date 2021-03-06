declare name      "Tube Amp Emulation 12AT7";
declare author    "Guitarix";

import("stdfaust.lib");


process = component("tubes.lib").T1_12AT7 : *(preamp):
 	fi.lowpass(1,6531.0) : component("tubes.lib").T2_12AT7 : *(preamp):
 	fi.lowpass(1,6531.0) : component("tubes.lib").T3_12AT7 : *(gain)
	with {
 		preamp = vslider("Pregain",-6,-20,20,0.1) : ba.db2linear : si.smooth(0.999);
 		gain  = vslider("Gain", -6, -20.0, 20.0, 0.1) : ba.db2linear : si.smooth(0.999);
};