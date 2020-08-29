declare name "Crybaby";

import("stdfaust.lib");


process = _ <: _*dry, (_*wetdry:ve.crybaby(wah)) :> _
with{
	wah = vslider("[1] Wah parameter [tooltip: wah pedal angle between 0 (rocked back) and 1 (rocked forward)]",0.8,0,1,0.01);
	wetdry = vslider("[2] amount[style:knob]",  1, 0, 1, 0.01);
	dry = 1 - wetdry;
};
