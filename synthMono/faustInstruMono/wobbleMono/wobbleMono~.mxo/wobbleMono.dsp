//--------------------`wobble`-------------------
// Synthesizer
//
//
// #### Compilation example
// * faust2jaqt -midi wobble.dsp
//
//
// #### Source
// * https://www.youtube.com/watch?v=E_qrk2hE__s
///////////////////////////////////////////////////////////////

declare name "wobble";

declare author "Sébastien Clara";



import("stdfaust.lib");


///////////////////////////////////////////////////////////////
// GUI parameters
///////////////////////////////////////////////////////////////
gate = button ("v:wobble/h:[0]midi/[1]gate");

freq = vslider("v:wobble/h:[0]midi/[2]freq [unit:Hz] [style:knob]", 220, 20, 5000, 10) : portamento;

gain = vslider("v:wobble/h:[0]midi/[9]gain [style:knob]", 1, 0, 3, 0.01) : si.smoo;

bend = vslider("v:wobble/h:[0]midi/[8]bend [hide:1] [style:knob] [midi:pitchwheel]", 1,0.9,1.1,0.01);

portamento = si.smooth(vslider("v:wobble/h:[0]midi/[7]portamento [style:knob]", 0, 0, 5, 0.05) : ba.tau2pole);


envelop(gate, gain) = en.adsre(att, dec, sus, rel, gate) * gain
with {
	att = vslider("v:wobble/h:[2]parameters/h:[9]env/[1]attack [style:knob] [tooltip:sec]", 0.03, 0.01, 5, 0.01) : si.smoo;
	dec = vslider("v:wobble/h:[2]parameters/h:[9]env/[2]decay [style:knob] [tooltip:sec]", 0.05, 0.01, 5, 0.01) : si.smoo;
	sus = vslider("v:wobble/h:[2]parameters/h:[9]env/[3]sustain [style:knob] [tooltip:percentage of max]", 0.9, 0.1, 1, 0.1) : si.smoo;
	rel = vslider("v:wobble/h:[2]parameters/h:[9]env/[4]release [style:knob] [tooltip:sec]", 0.3, 0.01, 5, 0.01) : si.smoo;
};



///////////////////////////////////////////////////////////////
// Tools
///////////////////////////////////////////////////////////////
scale(value, minIn, maxIn, minOut, maxOut) =
	((maxOut - minOut) * (value - minIn) / (maxIn - minIn)) + minOut;


range(signal, low, high) = scale(signal, -1,1, low,high);


clip(value, low, high) = resul
with {
	maxR = (value > max(low, high))*max(low, high) + (value <= max(low, high))*value;
	resul = (maxR < min(low, high))*min(low, high) + (maxR >= min(low, high))*maxR;
};



///////////////////////////////////////////////////////////////
// Synthesis
///////////////////////////////////////////////////////////////
maxCut = ma.SR/6.3;

modulation(freq) = clip(range(os.osci(modCoef*freq),freq*1.5,maxCut) * modAmp, 20,maxCut)
with {
	modCoef = vslider("v:wobble/h:[2]parameters/[1]modCoef [style:knob]", 0.01, 0, 1, 0.01);
	modAmp = vslider("v:wobble/h:[2]parameters/[2]modAmp [style:knob]", 0.5, 0.05, 1, 0.01);
};


wobble(freq) = (main + beat) * 0.8  : filter : co.limiter_1176_R4_mono
with {
	ampBeat = vslider("v:wobble/h:[2]parameters/[3]beat [style:knob]", 0.5, 0, 1, 0.01) : si.smoo;
	r = vslider("v:wobble/h:[2]parameters/[4]resonance [style:knob]", 0.05, 0, 1, 0.01): si.smoo;

	main = os.sawtooth(freq) * 0.5;
	beat = (os.sawtooth(freq*0.99)+os.sawtooth(freq*1.001)+os.sawtooth(freq*1.008)) * 0.5 * ampBeat;
	filter = ef.cubicnl_nodc(0.4,0) : (ve.moog_vcf_2bn(r, modulation(freq))*0.4);
};


///////////////////////////////////////////////////////////////
// DSP
///////////////////////////////////////////////////////////////
process = (wobble(freq*bend) * envelop(gate, gain) * 0.5) <: _,_;
