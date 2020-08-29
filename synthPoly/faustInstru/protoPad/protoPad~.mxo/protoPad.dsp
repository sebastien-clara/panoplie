//--------------------`protoPad`-------------------
// Synthesizer
//
//
// #### Compilation example
// * faust2jaqt -midi protoPad.dsp
//
//
// #### Source
// * http://sccode.org/1-4QJ
///////////////////////////////////////////////////////////////

declare name "protoPad";

declare author "Sébastien Clara";

declare nvoices "16";

import("stdfaust.lib");


///////////////////////////////////////////////////////////////
// MIDI interface
///////////////////////////////////////////////////////////////
midigate = button ("v:protoPad/h:[0]midi/[1]gate");

midifreq = vslider("v:protoPad/h:[0]midi/[2]freq [unit:Hz] [style:knob]", 440, 20, 10000, 1);

midigain = vslider("v:protoPad/h:[0]midi/[9]gain [style:knob]", 0.5, 0, 3, 0.01);

bend = vslider("v:protoPad/h:[0]midi/[8]bend [hide:1] [style:knob] [midi:pitchwheel]", 1,0.9,1.1,0.01);



envelop(gate, gain) = en.adsre(att, dec, sus, rel, gate) * gain
with {
	att = vslider("v:protoPad/h:[1]env/[1]A [style:knob] [tooltip:sec]", 0.01, 0, 5, 0.01) : si.smoo;
	dec = vslider("v:protoPad/h:[1]env/[2]D [style:knob] [tooltip:sec]", 0.03, 0, 5, 0.01) : si.smoo;
	sus = vslider("v:protoPad/h:[1]env/[3]S [style:knob] [tooltip:percentage of max]", 90, 0, 100, 0.1) : si.smoo;
	rel = vslider("v:protoPad/h:[1]env/[4]R [style:knob] [tooltip:sec]", 0.3, 0.01, 5, 0.01) : si.smoo;
};


///////////////////////////////////////////////////////////////
// Synthesis
///////////////////////////////////////////////////////////////
protoPad(freq) = snd : co.limiter_1176_R4_mono
with {
	freq2 = freq*1.5;
	freq3 = freq*1.33;

	mod = freq + (os.osci(freq/2) * freq/3);

	sig = ((mod*0.99, mod+1, (mod-1)*0.99, freq2, freq3*0.99) : par(i, 5, os.sawtooth) :> _*0.1),
	((mod*0.99, (mod+1)*0.99, (mod-1)*0.99, freq2*0.99, freq3*0.99, (freq2+1)*0.99, (freq3+1)*0.99) :
		par(i, 7, _<:(os.sawtooth, os.triangle) : si.interpolate(os.lf_trianglepos(7.13)*0.1)) :> _*0.1) : +;

	shape = (sig : re.mono_freeverb(0.51, 0.51, 0.1, ba.sec2samp(0.05))) <:
	(fi.resonlp(((os.osc(freq/500)*1700)+4000)/1, 1/(os.oscp(freq/1000,1.5*ma.PI)+2.5),0.5),
		fi.resonlp(((os.osc(freq/300)*480)+700)/1, 1/(os.oscp(freq/1000,1.5*ma.PI)+2.5),0.5)) :> _;

	drive=0.3;
	offset=0;
	snd = (shape*0.05) : ef.cubicnl(drive,offset) : fi.highpass(3,freq);
};


///////////////////////////////////////////////////////////////
// DSP
///////////////////////////////////////////////////////////////
process = protoPad(midifreq*bend)*envelop(midigate,midigain) <: _,_;



