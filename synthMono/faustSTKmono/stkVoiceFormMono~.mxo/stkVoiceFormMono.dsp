declare name "voiceForm mono";
declare description "Voice Formant Instrument";
declare author "Sébastien Clara";
declare licence "STK-4.3"; // Synthesis Tool Kit 4.3 (MIT style license);
declare description "This instrument contains an excitation singing wavetable (looping wave with random and periodic vibrato, smoothing on frequency, etc.), excitation noise, and four sweepable complex resonances. Phoneme preset numbers: 0->eee (beet), 1->ihh (bit), 2->ehh (bet), 3->aaa (bat), 4->ahh (father), 5->aww (bought), 6->ohh (bone), 7->uhh (but), 8->uuu (foot), 9->ooo (boot), 10->rrr (bird), 11->lll (lull), 12->mmm (mom), 13->nnn (nun), 14->nng (sang), 15->ngg (bong), 16->fff, 17->sss, 18->thh, 19->shh, 20->xxx, 21->hee (beet), 22->hoo (boot), 23->hah (father), 24->bbb, 25->ddd, 26->jjj, 27->ggg, 28->vvv, 29->zzz, 30->thz, 31->zhh";

import("instruments.lib");

//==================== GUI SPECIFICATION ================
frequency = vslider("v:voiceForm/h:[1]midi/freq [1][unit:Hz] [tooltip:Tone frequency][style:knob]",440,20,5000,1);
gain = vslider("v:voiceForm/h:[1]midi/gain [1][tooltip:Gain (value between 0 and 1)][style:knob]",1,0,1,0.01);
gate = button("v:voiceForm/h:[1]midi/gate [1][tooltip:noteOn = 1, noteOff = 0]");
bend = vslider("v:voiceForm/h:[1]midi/[1]bend[hidden:1][midi:pitchwheel] [style:knob]",1,0.9,1.1,0.01) : si.smoo;
portamento = si.smooth(vslider("v:voiceForm/h:[1]midi/[7]portamento [style:knob]", 0, 0, 5, 0.05) : ba.tau2pole);

freq = frequency*bend : portamento;


phoneme = hslider("v:Physical/Phoneme
[2][tooltip:0->eee, 1->ihh, 2->ehh, 3->aaa, 4->ahh, 5->aww, 6->ohh, 7->uhh, 8->uuu, 9->ooo, 10->rrr, 11->lll, 12->mmm, 13->nnn, 14->nng, 15->ngg, 16->fff, 17->sss, 18->thh, 19->shh, 20->xxx, 21->hee, 22->hoo, 23->hah, 24->bbb, 25->ddd, 26->jjj, 27->ggg, 28->vvv, 29->zzz, 30->thz, 31->zhh][style:knob]",4,0,31,1);

vibratoFreq = hslider("v:voiceForm/h:[3]Vibrato/Vibrato_Freq
[3][unit:Hz][style:knob]",6,1,15,0.1);
vibratoGain = hslider("v:voiceForm/h:[3]Vibrato/Vibrato_Gain
[3][tooltip:A value between 0 and 1][style:knob]",0.05,0,1,0.01);
vibratoBegin = hslider("v:voiceForm/h:[3]Vibrato/Vibrato_Begin
[3][unit:s][tooltip:Vibrato silence duration before attack][style:knob]",0.05,0,2,0.01);
vibratoAttack = hslider("v:voiceForm/h:[3]Vibrato/Vibrato_Attack
[3][unit:s][tooltip:Vibrato attack duration][style:knob]",0.5,0,2,0.01);
vibratoRelease = hslider("v:voiceForm/h:[3]Vibrato/Vibrato_Release
[3][unit:s][tooltip:Vibrato release duration][style:knob]",0.1,0,2,0.01);


voicedEnvelopeAttack = hslider("v:voiceForm/h:[3]Envelope/Voiced_Attack
[4][unit:s][tooltip:Voiced sounds attack duration][style:knob]",0.01,0,2,0.01);
voicedEnvelopeRelease = hslider("v:voiceForm/h:[3]Envelope/Voiced_Release
[4][unit:s][tooltip:Voiced sounds release duration][style:knob]",0.01,0,2,0.01);

noiseEnvelopeAttack = hslider("v:voiceForm/h:[3]Envelope/Noised_Attack
[4][unit:s][tooltip:Noised sounds attack duration][style:knob]",0.001,0,2,0.001);
noiseEnvelopeRelease = hslider("v:voiceForm/h:[3]Envelope/Noised_Release
[4][unit:s][tooltip:Noised sounds release duration][style:knob]",0.001,0,2,0.001);

//==================== SIGNAL PROCESSING ================

//----------------------- Synthesis parameters computing and functions declaration ----------------------------

//exitation filters (declared in instruments.lib)
onePoleFilter = onePole(b0,a1)
	with{
		pole = 0.97 - (gain*0.2);
		b0 = 1 - pole;
		a1 = -pole;
	};
oneZeroFilter = oneZero1(b0,b1)
	with{
		zero = -0.9;
		b0 = 1/(1 - zero);
		b1 = -zero*b0;
	};

//implements a formant (resonance) which can be "swept" over time from one frequency setting to another
formSwep(frequency,radius,filterGain) = *(gain_) : bandPass(frequency_,radius)
	with{
		//filter's radius, gain and frequency are interpolated
		radius_ = radius : si.smoo;
		frequency_ = frequency : si.smoo;
		gain_ = filterGain : si.smoo;
	};

//formants parameters are countained in a C++ file
phonemeGains = ffunction(float loadPhonemeGains(int,int), <phonemes.h>,"");
phonemeParameters = ffunction(float loadPhonemeParameters(int,int,int), <phonemes.h>,"");

//formants frequencies
ffreq0 = phonemeParameters(phoneme,0,0);
ffreq1 = phonemeParameters(phoneme,1,0);
ffreq2 = phonemeParameters(phoneme,2,0);
ffreq3 = phonemeParameters(phoneme,3,0);

//formants radius
frad0 = phonemeParameters(phoneme,0,1);
frad1 = phonemeParameters(phoneme,1,1);
frad2 = phonemeParameters(phoneme,2,1);
frad3 = phonemeParameters(phoneme,3,1);

//formants gains
fgain0 = phonemeParameters(phoneme,0,2) : pow(10,(_/20));
fgain1 = phonemeParameters(phoneme,1,2) : pow(10,(_/20));
fgain2 = phonemeParameters(phoneme,2,2) : pow(10,(_/20));
fgain3 = phonemeParameters(phoneme,3,2) : pow(10,(_/20));

//gain of the voiced part od the sound
voiceGain = phonemeGains(phoneme,0) : si.smoo;

//gain of the fricative part of the sound
noiseGain = phonemeGains(phoneme,1) : si.smoo;

//formants filters
filter0 = formSwep(ffreq0,frad0,fgain0);
filter1 = formSwep(ffreq1,frad1,fgain1);
filter2 = formSwep(ffreq2,frad2,fgain2);
filter3 = formSwep(ffreq3,frad3,fgain3);

//----------------------- Algorithm implementation ----------------------------

//envelopes (declared in instruments.lib) and vibrato
vibratoEnvelope = envVibrato(vibratoBegin,vibratoAttack,100,vibratoRelease,gate);
voicedEnvelope = en.asr(voicedEnvelopeAttack,1,voicedEnvelopeRelease,gate);
noiseEnvelope = en.asr(noiseEnvelopeAttack,1,noiseEnvelopeRelease,gate);
vibrato = os.osc(vibratoFreq)*vibratoGain*100*vibratoEnvelope;

//the voice source is generated by an impulse train
//(imptrain defined in oscillator.lib) that is lowpass filtered
voiced = os.imptrain(freq+vibrato) : fi.lowpass3e(3300) : *(voiceGain*voicedEnvelope);

//ficative sounds are produced by a noise generator
frica = no.noise*noiseEnvelope*noiseGain;

process = voiced : oneZeroFilter : onePoleFilter :
		 +(frica) <: filter0,filter1,filter2,filter3 :> +;
