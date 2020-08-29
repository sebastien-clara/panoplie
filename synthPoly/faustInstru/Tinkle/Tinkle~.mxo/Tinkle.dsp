declare name "Tinkle";
declare description "Banded Waveguide Modeld Tibetan Bowl";
//declare author "Romain Michon";
declare author "Sébastien Clara";
declare description "This instrument uses banded waveguide. For more information, see Essl, G. and Cook, P. Banded Waveguides: Towards Physical Modelling of Bar Percussion Instruments, Proceedings of the 1999 International Computer Music Conference.";



import("stdfaust.lib");
instrument = library("instruments.lib");

//==================== INSTRUMENT =======================
amp = 0.25 * envelop(gate, gain); 

process = (gate : ba.toggle <:
		//nModes resonances with nModes feedbacks for bow table look-up 
		par(i,nModes,(resonance(i)~_))):>+:fi.lowpass(1,5000)*(amp);

//==================== GUI SPECIFICATION ================
gate = button ("v:Tinkle/h:[0]midi/[1]gate");
freq = vslider("v:Tinkle/h:[0]midi/[2]freq [unit:Hz] [style:knob]", 440, 180, 780, 1)*bend;
bend = vslider("v:Tinkle/h:[0]midi/[3]bend [midi:pitchwheel] [style:knob]", 1, 0.9, 1.1, 0.01);
gain = vslider("v:Tinkle/h:[0]midi/[9]gain [style:knob]", 0.1, 0, 1, 0.01);

envelop(gate, gain) = en.adsre(att, dec, sus, rel, gate) * gain
with {
	att = vslider("v:Tinkle/h:[1]env/[1]attack [style:knob] [tooltip:sec]", 0.01, 0, 15, 0.01) : si.smoo;
	dec = vslider("v:Tinkle/h:[1]env/[2]decay [style:knob] [tooltip:sec]", 0.05, 0, 15, 0.01) : si.smoo;
	sus = vslider("v:Tinkle/h:[1]env/[3]sustain [style:knob] [tooltip:percentage of max]", 80, 0, 100, 0.1) : si.smoo;
	rel = vslider("v:Tinkle/h:[1]env/[4]release [style:knob] [tooltip:sec]", 0.3, 0.01, 15, 0.01) : si.smoo;
};


//==================== MODAL PARAMETERS ================

preset = 0;

nMode(0) = 12;

modes(0,0) = 0.996108344;
basegains(0,0) = 0.999925960128219;
excitation(0,0) = 11.900357 / 10;
    
modes(0,1) = 1.0038916562;
basegains(0,1) = 0.999925960128219;
excitation(0,1) = 11.900357 / 10;

modes(0,2) = 2.979178;
basegains(0,2) = 0.999982774366897;
excitation(0,2) = 10.914886 / 10;

modes(0,3) = 2.99329767;
basegains(0,3) = 0.999982774366897;
excitation(0,3) = 10.914886 / 10;
    
modes(0,4) = 5.704452;
basegains(0,4) = 1.0;
excitation(0,4) = 42.995041 / 10;
    
modes(0,5) = 5.704452;
basegains(0,5) = 1.0;
excitation(0,5) = 42.995041 / 10;
    
modes(0,6) = 8.9982;
basegains(0,6) = 1.0;
excitation(0,6) = 40.063034 / 10;
    
modes(0,7) = 9.01549726;
basegains(0,7) = 1.0;
excitation(0,7) = 40.063034 / 10;
    
modes(0,8) = 12.83303;
basegains(0,8) = 0.999965497558225;
excitation(0,8) = 7.063034 / 10;
   
modes(0,9) = 12.807382;
basegains(0,9) = 0.999965497558225;
excitation(0,9) = 7.063034 / 10;
    
modes(0,10) = 17.2808219;
basegains(0,10) = 0.9999999999999999999965497558225;
excitation(0,10) = 57.063034 / 10;
    
modes(0,11) = 21.97602739726;
basegains(0,11) = 0.999999999999999965497558225;
excitation(0,11) = 57.063034 / 10;

//==================== SIGNAL PROCESSING ================

//----------------------- Synthesis parameters computing and functions declaration ----------------------------

//the number of modes depends on the preset being used
nModes = nMode(preset);

delayLengthBase = ma.SR/freq;

//delay lengths in number of samples
delayLength(x) = delayLengthBase/modes(preset,x);

//delay lines
delayLine(x) = de.delay(4096,delayLength(x));

//Filter bank: fi.bandpass filters (declared in instrument.lib)
radius = 1 - ma.PI*32/ma.SR;
bandPassFilter(x) = instrument.bandPass(freq*modes(preset,x),radius);


//----------------------- Algorithm implementation ----------------------------

//One resonance
resonance(x) = + : + (excitation(preset,x)) : delayLine(x) : *(basegains(preset,x)) : bandPassFilter(x);
