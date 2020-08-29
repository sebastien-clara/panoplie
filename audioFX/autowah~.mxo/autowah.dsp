declare name "autoWah";

import("stdfaust.lib");


process = ve.autowah(amount)
with {
	amount = vslider("amount [tooltip: amount of effect desired (0 to 1)][style:knob]",  1, 0, 1, 0.01);
};
