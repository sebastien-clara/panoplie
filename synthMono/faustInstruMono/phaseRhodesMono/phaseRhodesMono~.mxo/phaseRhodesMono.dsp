//--------------------`phaseRhodes`-------------------
// Synthesizer
//
//
// #### Compilation example
// * faust2jaqt -midi phaseRhodes.dsp
//
//
// #### Source
// * http://sccode.org/1-522
///////////////////////////////////////////////////////////////

declare name "phaseRhodes";

declare author "Sébastien Clara";



import("stdfaust.lib");


///////////////////////////////////////////////////////////////
// MIDI interface
///////////////////////////////////////////////////////////////
midigate = button ("v:phaseRhodes/h:[0]midi/[1]gate");

midifreq = vslider("v:phaseRhodes/h:[0]midi/[2]freq [unit:Hz] [style:knob]", 440, 30, 5000, 1) : portamento;

midigain = vslider("v:phaseRhodes/h:[0]midi/[9]gain [style:knob]", 1, 0, 3, 0.01) : si.smoo;

bend = vslider("v:phaseRhodes/h:[0]midi/[8]bend [hide:1] [style:knob] [midi:pitchwheel]", 1,0.9,1.1,0.01);

portamento = si.smooth(vslider("v:phaseRhodes/h:[0]midi/[7]portamento [style:knob]", 0, 0, 5, 0.05) : ba.tau2pole);

///////////////////////////////////////////////////////////////
// Synthesis
///////////////////////////////////////////////////////////////
phaseRhodes(gate, gain, freq) = sig * 0.5
with {
	modIndex = vslider("v:phaseRhodes/h:[1]fx/[1]modIndex [style:knob]", 0.2,0,15,0.01) : si.smoo;
	lfoSpeed = vslider("v:phaseRhodes/h:[1]fx/[2]lfoSpeed [style:knob]", 0.4,0,10,0.01);
	lfoDepth = vslider("v:phaseRhodes/h:[1]fx/[3]lfoDepth [style:knob]", 0.1,0,1,0.01) : si.smoo;
	brightness = vslider("v:phaseRhodes/h:[1]fx/[4]brightness [style:knob]", 0.2,0,1,0.01)*0.7 : si.smoo;
	rel = vslider("v:phaseRhodes/h:[1]fx/[5]release [style:knob] [tooltip:sec]", 0.05, 0.01, 5, 0.01) : si.smoo;

	env1 = en.adsr(0.01, 1.25, 0.7, rel, gate) * gain;
	env2 = en.adsr(0.01, 1, 0.7, rel, gate) * gain;
	env3 = en.adsr(0.01, 1.5, 0.7, rel, gate) * gain;
	env4 = en.adsr(0.01, 1.5, 0.7, rel, gate) * gain;

	osc4 = os.osci(freq * 0.5) * 4 * ma.PI * 0.535887 * modIndex * env4;
	osc3 = os.oscp(freq, osc4) * env3;
	osc2 = os.osci(freq * 15) * 2 * ma.PI * 0.108819 * env2;
	osc1 = os.oscp(freq, osc2) * env1;

	sig = ((osc3 * (1 - brightness)) + (osc1 * brightness)) * (os.osci(lfoSpeed) * lfoDepth + 1);
};


///////////////////////////////////////////////////////////////
// DSP
///////////////////////////////////////////////////////////////
process = phaseRhodes(midigate, midigain, midifreq*bend) <: _,_;
