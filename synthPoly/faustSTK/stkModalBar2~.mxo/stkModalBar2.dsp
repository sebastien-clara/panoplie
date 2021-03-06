declare name "modalBar";
declare description "Nonlinear Modal percussive instruments";
declare author "Sébastien Clara";
declare licence "STK-4.3"; // Synthesis Tool Kit 4.3 (MIT style license);
declare description "A number of different struck bar instruments. Presets numbers: 0->Marimba, 1->Vibraphone, 2->Agogo, 3->Wood1, 4->Reso, 5->Wood2, 6->Beats, 7->2Fix; 8->Clump";

import("instruments.lib");

//========================= WAVE TABLES ===============================

//----------------------- STICK IMPACT ----------------------------
// Stick impact table.
//
// USAGE:
//   index : readMarmstk1 : _

readMarmstk1 = ffunction(float readMarmstk1 (int), <instrument.h>,"");
marmstk1TableSize = 246;


//==================== GUI SPECIFICATION ================

frequency = vslider("v:modalBar/h:[1]midi/freq [1][unit:Hz] [tooltip:Tone frequency][style:knob]",440,20,5000,1);
gain = vslider("v:modalBar/h:[1]midi/gain [1][tooltip:Gain (value between 0 and 1)][style:knob]",1,0,1,0.01);
gate = button("v:modalBar/h:[1]midi/gate [1][tooltip:noteOn = 1, noteOff = 0]");
bend = vslider("v:modalBar/h:[1]midi/[1]bend[hidden:1][midi:pitchwheel][style:knob]",1,0.9,1.1,0.01) : si.polySmooth(gate,0.999,1);

freq = frequency*bend;


stickHardness = hslider("v:modalBar/h:[2]Physical/Stick_Hardness
[2][tooltip:A value between 0 and 1][style:knob]",0.25,0,1,0.01);
reson = nentry("v:modalBar/h:[2]Physical/Resonance
[2][tooltip:A value between 0 and 1][style:knob]",1,0,1,1);
presetNumber = nentry("v:modalBar/h:[2]Physical/Preset
[2][tooltip:0->Marimba, 1->Vibraphone, 2->Agogo, 3->Wood1, 4->Reso, 5->Wood2, 6->Beats, 7->2Fix; 8->Clump]",1,0,8,1);


typeModulation = nentry("v:modalBar/h:[3]Nonlinear_Filter/Modulation_Type
[3][tooltip: 0=theta is modulated by the incoming signal; 1=theta is modulated by the averaged incoming signal;
2=theta is modulated by the squared incoming signal; 3=theta is modulated by a sine wave of frequency freqMod;
4=theta is modulated by a sine wave of frequency freq;][style:knob]",0,0,4,1);
nonLinearity = hslider("v:modalBar/h:[3]Nonlinear_Filter/Nonlinearity
[3][tooltip:Nonlinearity factor (value between 0 and 1)][style:knob]",0,0,1,0.01);
frequencyMod = hslider("v:modalBar/h:[3]Nonlinear_Filter/Modulation_Frequency [tooltip:Frequency of the sine wave for the modulation of theta (works if Modulation Type=3)][style:knob]", 2,0.1,5,0.1)*freq;
nonLinAttack = hslider("v:modalBar/h:[3]Nonlinear_Filter/Nonlinearity_Attack
[3][unit:s][Attack duration of the nonlinearity][style:knob]",0.1,0,2,0.01);


vibratoFreq = hslider("v:modalBar/h:[4]Vibrato/Vibrato_Freq
[4][unit:Hz][style:knob]",6,1,15,0.1);
vibratoGain = hslider("v:modalBar/h:[4]Vibrato/Vibrato_Gain
[4][tooltip:A value between 0 and 1][style:knob]",0.1,0,1,0.01);

//==================== SIGNAL PROCESSING ================

//----------------------- Nonlinear filter ----------------------------
//nonlinearities are created by the nonlinear passive allpass ladder filter declared in miscfilter.lib

//nonlinear filter order
nlfOrder = 6;

//nonLinearModultor is declared in instruments.lib, it adapts allpassnn from miscfilter.lib
//for using it with waveguide instruments
NLFM =  nonLinearModulator((nonLinearity : si.smoo),1,freq,
     typeModulation,(frequencyMod : si.smoo),nlfOrder);

//----------------------- Synthesis parameters computing and functions declaration ----------------------------


//check if the vibraphone is used
vibratoOn = presetNumber == 1;

//vibrato
vibrato = 1 + os.osc(vibratoFreq)*vibratoGain*vibratoOn;

//filter bank output gain
directGain = loadPreset(presetNumber,3,2);

//modal values for the filter bank
loadPreset = ffunction(float loadPreset (int,int,int), <modalBar.h>,"");

//filter bank using biquad filters
biquadBank = _ <: sum(i, 4, oneFilter(i))
	with{
		condition(x) = x<0 <: *(-x),((-(1))*-1)*x*freq :> +;
		dampCondition = (gate < 1) & (reson != 1);

		//the filter coefficients are interpolated when changing of preset
		oneFilter(j,y) = (loadPreset(presetNumber,0,j : si.smoo) : condition),
						loadPreset(presetNumber,1,j : si.smoo)*(1-(gain*0.03*dampCondition)),
						y*(loadPreset(presetNumber,2,j) : si.smoo) : bandPassH;
	};

//one pole filter with pole set at 0.9 for pre-filtering, onePole is declared in instruments.lib
sourceFilter = onePole(b0,a1)
	with{
		b0 = 1 - 0.9;
		a1 = -0.9;
	};

//excitation signal
excitation = counterSamples < (marmstk1TableSize*rate) : *(marmstk1Wave*gate)
	   with{
		//readMarmstk1 and marmstk1TableSize are both declared in instruments.lib
		marmstk1 = ba.time%marmstk1TableSize : int : readMarmstk1;

		dataRate(readRate) = readRate : (+ : ma.decimal) ~ _ : *(float(marmstk1TableSize));

		//the reading rate of the stick table is defined in function of the stickHardness
		rate = 0.25*pow(4,stickHardness);

		counterSamples = (*(gate)+1)~_ : -(1);
		marmstk1Wave = rdtable(marmstk1TableSize,marmstk1,int(dataRate(rate)*gate));
	   };

process = excitation : sourceFilter : *(gain) <:
	//resonance
	(biquadBank <: -(*(directGain))) + (directGain*_) :
	//vibrato for the vibraphone
	*(vibrato) : NLFM*0.6;
