declare name "compressor";

import("stdfaust.lib");

process = hgroup("compressor", compressor)
with {
	compressor = co.compressor_mono(ratio,threshold,attack,release) * makeupgain;

	ratio = hslider("[0] Ratio [style:knob]
	[tooltip: A compression Ratio of N means that for each N dB increase in input
	signal level above Threshold, the output level goes up 1 dB]",
	5, 1, 20, 0.1);

	threshold = hslider("[1] Threshold [unit:dB] [style:knob]
	[tooltip: When the signal level exceeds the Threshold (in dB), its level
	is compressed according to the Ratio]",
	-30, -100, 10, 0.1);

	attack = hslider("[2] Attack [unit:ms] [style:knob] [scale:log]
	[tooltip: Time constant in ms (1/e smoothing time) for the compression gain
	to approach (exponentially) a new lower target level (the compression
	`kicking in')]", 50, 1, 1000, 0.1) : *(0.001) : max(1/ma.SR);

	release = hslider("[3] Release [unit:ms] [style: knob] [scale:log]
	[tooltip: Time constant in ms (1/e smoothing time) for the compression gain
	to approach (exponentially) a new higher target level (the compression
	'releasing')]", 500, 1, 1000, 0.1) : *(0.001) : max(1/ma.SR);

	makeupgain = hslider("[5] Makeup Gain [unit:dB] [style: knob]
	[tooltip: The compressed-signal output level is increased by this amount
	(in dB) to make up for the level lost due to compression]",
	40, -96, 96, 0.1) : ba.db2linear : si.smoo;
};

