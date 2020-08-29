declare name "moogVcf2b";

import("stdfaust.lib");


process = _ <: _*dry, (_*wetdry:vcf) :> _
with {
	wetdry = vslider("[3] amount [style:knob]",  1, 0, 1, 0.01);
	dry = 1 - wetdry;


	freq = hslider("[1] Corner Frequency [unit:PK] [tooltip: The VCF resonates
		at the corner frequency. The VCF response is flat below the corner frequency, and rolls off -24 dB per
		octave above.] [style:knob]",
		440, 20, 5000, 1) : si.smoo;

	res = hslider("[2] Corner Resonance [style:knob] [tooltip: Amount of
		resonance near VCF corner frequency (specified between 0 and 1)]", 0.9, 0, 1, 0.01);

	vcf = ve.moog_vcf_2bn(res,freq);
};
