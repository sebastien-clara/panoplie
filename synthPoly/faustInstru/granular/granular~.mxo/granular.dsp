//--------------------`granular`-------------------
// Synthesizer
//
//
// #### Compilation example
// * faust2jaqt -midi granular.dsp
///////////////////////////////////////////////////////////////

declare name "granular";

declare author "Sébastien Clara";

declare nvoices "16";



import("stdfaust.lib");

///////////////////////////////////////////////////////////////
// MIDI interface
///////////////////////////////////////////////////////////////
gate = button ("v:granular/h:[0]midi/[1]gate");

freq = vslider("v:granular/h:[0]midi/[2]freq [unit:Hz] [style:knob]", 440, 30, 10000, 10);

gain = vslider("v:granular/h:[0]midi/[9]gain [style:knob]", 1, 0, 5, 0.01);

bend = vslider("v:granular/h:[0]midi/[8]bend [hide:1] [style:knob] [midi:pitchwheel]", 1,0.9,1.1,0.01);

portamento = si.smooth(hslider("v:granular/h:[2]grain/[9]portamento [style:knob]", 0, 0, 5, 0.05) : ba.tau2pole);

///////////////////////////////////////////////////////////////
// UI parameters
///////////////////////////////////////////////////////////////
envelop(gate, gain) = en.adsre(att, dec, sus, 0.01, gate) * gain
with {
	att = vslider("v:granular/h:[1]env/[1]attack [style:knob] [tooltip:sec]", 0.03, 0, 5, 0.01) : si.smoo;
	dec = vslider("v:granular/h:[1]env/[2]decay [style:knob] [tooltip:sec]", 0.05, 0, 5, 0.01) : si.smoo;
	sus = vslider("v:granular/h:[1]env/[3]sustain [style:knob] [tooltip:percentage of max]", 90, 0, 100, 0.1) : si.smoo;
};


grainDur = vslider("v:granular/h:[2]grain/[1]grainDur [style:knob] [tooltip:ms]", 10, 1, 100, 1)*0.001: si.smoo;

grainDensity = vslider("v:granular/h:[2]grain/[2]density [style:knob]", 5, 0.5, 150, 0.5);


///////////////////////////////////////////////////////////////
// Tools
///////////////////////////////////////////////////////////////
scale(value, minIn, maxIn, minOut, maxOut) =
	((maxOut - minOut) * (value - minIn) / (maxIn - minIn)) + minOut;


range(signal, low, high) = scale(signal, -1,1, low,high);


grainEnv(d, t) = (1-cos(ma.PI*en.ar(d/2,d/2, t)))/2;



///////////////////////////////////////////////////////////////
// Synthesis
///////////////////////////////////////////////////////////////
grainFreq(freq, density) =  f
with {
	cloud = checkbox("v:granular/h:[2]grain/[4]cloud"): si.smoo;
	cloudAmbitus = (2^(vslider("v:granular/h:[2]grain/[5]cloudAmbitus [style:knob] [tooltip:semitone]", 12, 2, 96, 1)/12)) : si.smoo;

	f = (freq * (1-cloud)),
		(range(no.lfnoise0(density), freq, freq*cloudAmbitus) * cloud) : +;
};



densityPulse(freq) = os.lf_squarewavepos(f)
with {
	async = checkbox("v:granular/h:[2]grain/[3]asynchro"): si.smoo;

	point = freq * 0.5;

	f = (freq * (1-async)),
		(range(no.lfnoise0(freq), freq-point, freq+point) * async) : +;
};


signalGrain(sig, density, dur) = sig * grainEnv(dur, density:densityPulse);


sinGrain(freq, density, dur) = signalGrain(os.osci(grainFreq(freq, density)), density, dur);



///////////////////////////////////////////////////////////////
// DSP
///////////////////////////////////////////////////////////////
process = sinGrain(freq*bend:portamento, grainDensity, grainDur) * envelop(gate, gain) * 0.01
	<: par(i,2,ef.cubicnl(0.7,0));
