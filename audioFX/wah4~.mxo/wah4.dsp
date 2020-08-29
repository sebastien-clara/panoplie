declare name "wah4";

import("stdfaust.lib");


process = _ <: _*dry, (_*wetdry:ve.wah4(fr)) :> _
with {
	fr = vslider("[1] Resonance Frequency [scale:log] [tooltip: wah resonance frequency in Hz][style:knob]", 200,100,2000,1);
	wetdry = vslider("[2] amount[style:knob]",  1, 0, 1, 0.01);
	dry = 1 - wetdry;
};
