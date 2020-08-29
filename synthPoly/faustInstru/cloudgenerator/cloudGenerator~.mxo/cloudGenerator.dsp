/*********************************************************************
----------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as
published by the Free Software Foundation.
<https://www.gnu.org/licenses/lgpl-3.0.en.html>

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.
**********************************************************************/

declare name "Cloud Generator";
declare version "0.01";
declare description "Source : https://github.com/visstup/cloud-generator";
declare nvoices "16";

// Revised by Sébastien Clara


import("stdfaust.lib");



//detuning parameters for individual oscillators
spread(i,spreadamt) = pow(spreadvox(i),spreadamt)
with {
	spreadvox(0) = 1;
	spreadvox(1) = 1.25;
	spreadvox(2) = 0.8;
	spreadvox(3) = 1.5;
	spreadvox(4) = 0.66;
	spreadvox(5) = 1.75;
	spreadvox(6) = 0.57;
	spreadvox(7) = 2;
	spreadvox(8) = 0.5;
};

//modulating the frequency of the oscillators
chaosMul(chaosbw,chaos) = (chaos * os.osc(chaosbw)*0.01 + 1);


//declaring 9 parallel sawtooth oscillators
parSaw(freq,spreadamt,chaosMul) = par(i,9,sawt(freq,i,chaosMul)) :> _
with {
  sawt(freq,i,chaosbw,chaos) = os.sawtooth(
    pow((freq * spread(i,spreadamt)), chaosMul)
  );
};

//same thing, but with sinusodial oscillators
parSine(freq,spreadamt,chaosMul) = par(i,9,sine(freq,i,chaosMul)) :> _
with {
  sine(freq,i,chaosbw,chaos) = os.osc(
    pow((freq * spread(i,spreadamt)), chaosMul)
  );
};


//declaring audio signal
	//path: oscillators : distortion
cloudgen(freq,spreadAmt,chaosbw,chaos,wavForm,richness) =
chaosMul(chaosbw,chaos) <: osc(freq,spreadAmt,wavForm) :
*(richness) : clip(-1,1) : cubic
with {
	osc(freq,spreadAmt,wavForm) =
		(parSine(freq,spreadAmt) * (1-wavForm)) +
		(parSaw(freq,spreadAmt) * wavForm) :> _*(0.2);

	clip(lo,hi) = min(hi) : max(lo);

	cubic(x) = x - x*x*x/3;
};

//declaring FX signal
	//path: LPF : compressor : volume
fxGen(lpFreq, lpReso, lpDepth, volume) =
	lpFilter(lpFreq, lpReso, lpDepth) :
	*(volume)
with {
	lpFilter(lpFreq, lpReso, lpDepth) = _ <: lpf :> _
	with {
		lpf = (ef.cubicnl_nodc(0.4,0) : (ve.moog_vcf_2bn(lpReso, lpFreq)*lpDepth*0.4)), _*(1-lpDepth);
	};
};


//declaring the envelope of the gate
envlop(att,dec,sus,rel,gate,gain) = en.adsr(att,dec,sus,rel,gate) * gain;


//declaring UI parameters
mainGroup(x) = hgroup("Cloud Generator",x);

cloudSynth = mainGroup(
	cloudgen(freq*bend:portamento,spreadAmt,chaosbw,chaos,wavForm,richness) *
  envlop(att,dec,sus,rel,gate,gain)
)
with {
	//declaring groups
	envGroup(x) = vgroup("[0]Envelope",x);
	noteGroup(x) = vgroup("[1]Note",x);
	modGroup(x) = vgroup("[2]Modulation",x);
	timbreGroup(x) = vgroup("[3]Timbre",x);


  att = envGroup(hslider("[1]Attack [style:knob][unit:ms]",20,1,3000,1)/1000);
  dec = envGroup(hslider("[2]Decay [style:knob][unit:ms]",100,1,3000,1)/1000);
  sus = envGroup(hslider("[3]Sustain [style:knob] [unit:%]",0.7,0,1,0.01));
  rel = envGroup(hslider("[4]Release [style:knob][unit:ms]",500,1,5000,1)/1000);


  gate = noteGroup(button("[9]gate [style:knob]"));
  gain = noteGroup(hslider("[3]gain [style:knob]", 0.5, 0, 10, 0.01));
  freq = noteGroup(hslider("[1]freq[unit:Hz] [style:knob]",220,20,5000,1));
	bend = noteGroup(hslider("[8]bend [style:knob] [hide:1] [midi:pitchwheel]", 1,0.9,1.1,0.01));
	portamento = noteGroup(si.smooth(hslider("[2]portamento [style:knob]", 0, 0, 5, 0.05) : ba.tau2pole));


  spreadAmt = modGroup(hslider("[1]Spread
    [tooltip:Modulates the individual detuning of the 9 parallel oscillators]
  [style:knob]",0.05,0,1,0.01) : ba.lin2LogGain);
  chaos = modGroup(hslider("[2]Leslie Amount
    [tooltip:The amount of the sinusoidal LFO modulating the pitch of the oscillators]
  [style:knob]",0,0,1,0.01) : si.smoo);
  chaosbw = modGroup(hslider("[3]Leslie Bandwidth
    [tooltip:The frequency of the sinusodial LFO modulating the pitch of the oscillators]
  [unit:Hz][style:knob]",1,0.01,20,0.01));


  wavForm = timbreGroup(hslider("[0]Wave Form
      [tooltip:Sine:0 ; Saw:1] [style:knob]",0,0,1,0.1):si.smoo);
  richness = timbreGroup(hslider("[1]Richness
    [tooltip:A simple cubic distortion unit]
		[style:knob]",1,1,10,0.01) : si.smoo);
};


fx = mainGroup(fxGen(lpFreq,lpReso,lpDepth, volume))
with {
	filterGroup(x) = vgroup("[7]LP Filter",x);
	compGroup(x) = vgroup("[8]Compressor",x);

  lpDepth = filterGroup(hslider("[2]LPF Depth [style:knob]",0,0,1,0.01));
	lpReso = filterGroup(hslider("[3]resonance [style:knob]", 0.1, 0, 0.99, 0.01));
  maxCut = 7000; //ma.SR/6.3;
	lpFreq = filterGroup(hslider("[4]Cutoff [unit:Hz][style:knob]",1500,20,maxCut,1) : si.smoo);

  volume = vslider("[9]Volume [unit:dB]",-15,-128,30,1) : si.smooth(0.999) : ba.db2linear;
};


process = cloudSynth : fx <: _,_;
/*
process = cloudSynth;
effect = fx <: _,_;
*/
