import("stdfaust.lib");

process = hgroup("faustVocoder",_,os.lf_imptrain(freq)*gain :
	ve.vocoder(bands,att,rel,BWRatio) <: _,_)
with{
	bands = 64;
	vocoderGroup(x) = vgroup("Vocoder",x);
	att = vocoderGroup(hslider("[0] Attack [style:knob] [tooltip: Attack time in seconds]",
		5,0.1,100,0.1)*0.001);
	rel = vocoderGroup(hslider("[1] Release [style:knob] [tooltip: Release time in seconds]",
		5,0.1,100,0.1)*0.001);
	BWRatio = vocoderGroup(hslider("[2] BW [style:knob] [tooltip: Coefficient to adjust the
		bandwidth of each band]",0.5,0.1,2,0.001));
	excitGroup(x) = vgroup("Excitation",x);
	freq = excitGroup(hslider("[0] Freq [style:knob]",330,50,2000,0.1));
	gain = excitGroup(vslider("[1] Gain",0.5,0,1,0.01) : si.smoo);
};
