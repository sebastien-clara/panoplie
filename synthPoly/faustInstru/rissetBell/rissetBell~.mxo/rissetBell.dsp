//--------------------`rissetBell`-------------------
// Synthesizer
//
// #### Usage
//
// ```
// rissetBell(gate, gain, freq, duration) <: _,_
// ```
//
// Where:
//
// * `gate`: the trigger signal (0 or 1)
// * `gain`: the gain of the instrument
// * `freq`: the frequency of the instrument
// * `duration`: duration of the resonance of the bell
//
// #### Compilation example
// * faust2jaqt -midi rissetBell.dsp
//
//
// #### Source
// * Dodge, Jerse, Computer Music Synthesis Composition and Performance, 2ed., p. 107
///////////////////////////////////////////////////////////////

declare name "rissetBell";

declare author "Sébastien Clara";

declare nvoices "16";



import("stdfaust.lib");


///////////////////////////////////////////////////////////////
// GUI parameters
///////////////////////////////////////////////////////////////
midigate = button ("v:rissetBell/h:[0]midi/[1]gate");

midifreq = vslider("v:rissetBell/h:[0]midi/[2]freq[unit:Hz] [style:knob]", 1760, 20, 10000, 1);

midigain = vslider("v:rissetBell/h:[0]midi/[9]gain [style:knob]", 1, 0, 3, 0.01);

bend = vslider("v:rissetBell/h:[0]midi/[8]bend [hide:1] [style:knob] [midi:pitchwheel]", 1,0.9,1.1,0.01);



duration =  vslider("v:rissetBell/h:[1]parameters/[3]duration [style:knob]", 5, 0.2, 10, 0.2) : si.smoo;


env(gate, gain, dur) = en.adsre(att, (dur-att):abs, 0.01, rel, gate) * gain
with {
	att = vslider("v:rissetBell/h:[1]parameters/[1]attack [style:knob] [tooltip:sec]", 0.01, 0, 3, 0.01) : si.smoo;
	rel = vslider("v:rissetBell/h:[1]parameters/[2]release [style:knob] [tooltip:sec]", 0.3, 0.01, 5, 0.01) : si.smoo;
};

///////////////////////////////////////////////////////////////
// Synthesis
///////////////////////////////////////////////////////////////
rissetBell(gate, gain, freq, dur) = par(i, N, part(i)) :> _*0.05
with {
	coef = (0.56, 0.561, 0.92, 0.925, 1.19, 1.7, 2, 2.74, 3, 3.76, 4.07);
	amp = (1, 0.67, 1, 1.8, 2.67, 1.67, 1.46, 1.33, 1.33, 1, 1.33);
	dura = (1, 0.9, 0.65, 0.55, 0.325, 0.35, 0.25, 0.2, 0.15, 0.1, 0.075);

	N = ba.count(coef);
	part(i) = os.osci(freq*ba.take(i+1, coef)) * env(gate, gain * ba.take(i+1, amp), dur * ba.take(i+1, dura));
};



///////////////////////////////////////////////////////////////
// DSP
///////////////////////////////////////////////////////////////
process = rissetBell(midigate, midigain, midifreq*bend, duration) <: _,_;



