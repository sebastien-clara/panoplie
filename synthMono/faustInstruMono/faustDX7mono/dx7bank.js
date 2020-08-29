// inlets and outlets
inlets = 1;
//outlets = 1;

var bank = [];


function init(arg) {
	post("--------------------------\n");
	post("Roms folder => " + arg + "\n");
	
	var folder = Folder(arg);
	var familyInstru = [];
	bank = [];
	

	//Load directory in roms
	while (!folder.end) {
		if (folder.filetype == 'fold') {
			familyInstru.push(folder.filename);
		};
		folder.next();
	};

	folder.close();



	//Load syx files
	for(var i=0; i<familyInstru.length; i++) {
		folder = Folder(arg + familyInstru[i]);

		while (!folder.end) {
			if ((folder.extension=='.syx')||(folder.extension=='.SYX')) {
//				post(arg + familyInstru[i] + "/" + folder.filename + "\n");
				var test = dx7preset.loadBank(arg + familyInstru[i] + "/" + folder.filename);
				if(test!=false) {bank = bank.concat(test)};
			};
			folder.next();
		};
		
		folder.close();
	};


//	post("bank.length : " + bank.length + "\n");
//	post("bank[0].family : " + bank[0].family + "\n");
//	post("bank[0].name : " + bank[0].name + "\n");


	//update umenuPreset
	messnamed("#1-menuPresets", "clear");
	if(bank != []) {
		for(var i=0; i<bank.length; i++) {
			messnamed("#1-menuPresets", "append " + bank[i].family + " > " + bank[i].name);
		};
		messnamed("#1-menuPresets", 0);
	} else {
		post("Trouble with roms folder : " + arg + " !!??\n");
	};
};



function loadPreset(index, instru) {
	var idx = parseInt(index);
	
//	post("Load : " + bank[idx].name + "\n");

	messnamed(instru + "-algorithm", bank[idx].algorithm);
	messnamed(instru + "-feedback", bank[idx].feedback);
	
	messnamed(instru + "-0-opMode", bank[idx].opMode[0]);
	messnamed(instru + "-0-opFreq", bank[idx].frequency[0]);
	messnamed(instru + "-0-opDetune", bank[idx].detune[0]);
	messnamed(instru + "-0-opRateScale", bank[idx].scaleRate[0]);
	messnamed(instru + "-0-egR1", bank[idx].opEgR1[0]);
	messnamed(instru + "-0-egR2", bank[idx].opEgR2[0]);
	messnamed(instru + "-0-egR3", bank[idx].opEgR3[0]);
	messnamed(instru + "-0-egR4", bank[idx].opEgR4[0]);
	messnamed(instru + "-0-egL1", bank[idx].opEgL1[0]);
	messnamed(instru + "-0-egL2", bank[idx].opEgL2[0]);
	messnamed(instru + "-0-egL3", bank[idx].opEgL3[0]);
	messnamed(instru + "-0-egL4", bank[idx].opEgL4[0]);
	messnamed(instru + "-0-keyVelSens", bank[idx].velocitySens[0]);
	messnamed(instru + "-0-level", bank[idx].level[0]);
	
	messnamed(instru + "-1-opMode", bank[idx].opMode[1]);
	messnamed(instru + "-1-opFreq", bank[idx].frequency[1]);
	messnamed(instru + "-1-opDetune", bank[idx].detune[1]);
	messnamed(instru + "-1-opRateScale", bank[idx].scaleRate[1]);
	messnamed(instru + "-1-egR1", bank[idx].opEgR1[1]);
	messnamed(instru + "-1-egR2", bank[idx].opEgR2[1]);
	messnamed(instru + "-1-egR3", bank[idx].opEgR3[1]);
	messnamed(instru + "-1-egR4", bank[idx].opEgR4[1]);
	messnamed(instru + "-1-egL1", bank[idx].opEgL1[1]);
	messnamed(instru + "-1-egL2", bank[idx].opEgL2[1]);
	messnamed(instru + "-1-egL3", bank[idx].opEgL3[1]);
	messnamed(instru + "-1-egL4", bank[idx].opEgL4[1]);
	messnamed(instru + "-1-keyVelSens", bank[idx].velocitySens[1]);
	messnamed(instru + "-1-level", bank[idx].level[1]);
	
	messnamed(instru + "-2-opMode", bank[idx].opMode[2]);
	messnamed(instru + "-2-opFreq", bank[idx].frequency[2]);
	messnamed(instru + "-2-opDetune", bank[idx].detune[2]);
	messnamed(instru + "-2-opRateScale", bank[idx].scaleRate[2]);
	messnamed(instru + "-2-egR1", bank[idx].opEgR1[2]);
	messnamed(instru + "-2-egR2", bank[idx].opEgR2[2]);
	messnamed(instru + "-2-egR3", bank[idx].opEgR3[2]);
	messnamed(instru + "-2-egR4", bank[idx].opEgR4[2]);
	messnamed(instru + "-2-egL1", bank[idx].opEgL1[2]);
	messnamed(instru + "-2-egL2", bank[idx].opEgL2[2]);
	messnamed(instru + "-2-egL3", bank[idx].opEgL3[2]);
	messnamed(instru + "-2-egL4", bank[idx].opEgL4[2]);
	messnamed(instru + "-2-keyVelSens", bank[idx].velocitySens[2]);
	messnamed(instru + "-2-level", bank[idx].level[2]);
	
	messnamed(instru + "-3-opMode", bank[idx].opMode[3]);
	messnamed(instru + "-3-opFreq", bank[idx].frequency[3]);
	messnamed(instru + "-3-opDetune", bank[idx].detune[3]);
	messnamed(instru + "-3-opRateScale", bank[idx].scaleRate[3]);
	messnamed(instru + "-3-egR1", bank[idx].opEgR1[3]);
	messnamed(instru + "-3-egR2", bank[idx].opEgR2[3]);
	messnamed(instru + "-3-egR3", bank[idx].opEgR3[3]);
	messnamed(instru + "-3-egR4", bank[idx].opEgR4[3]);
	messnamed(instru + "-3-egL1", bank[idx].opEgL1[3]);
	messnamed(instru + "-3-egL2", bank[idx].opEgL2[3]);
	messnamed(instru + "-3-egL3", bank[idx].opEgL3[3]);
	messnamed(instru + "-3-egL4", bank[idx].opEgL4[3]);
	messnamed(instru + "-3-keyVelSens", bank[idx].velocitySens[3]);
	messnamed(instru + "-3-level", bank[idx].level[3]);
	
	messnamed(instru + "-4-opMode", bank[idx].opMode[4]);
	messnamed(instru + "-4-opFreq", bank[idx].frequency[4]);
	messnamed(instru + "-4-opDetune", bank[idx].detune[4]);
	messnamed(instru + "-4-opRateScale", bank[idx].scaleRate[4]);
	messnamed(instru + "-4-egR1", bank[idx].opEgR1[4]);
	messnamed(instru + "-4-egR2", bank[idx].opEgR2[4]);
	messnamed(instru + "-4-egR3", bank[idx].opEgR3[4]);
	messnamed(instru + "-4-egR4", bank[idx].opEgR4[4]);
	messnamed(instru + "-4-egL1", bank[idx].opEgL1[4]);
	messnamed(instru + "-4-egL2", bank[idx].opEgL2[4]);
	messnamed(instru + "-4-egL3", bank[idx].opEgL3[4]);
	messnamed(instru + "-4-egL4", bank[idx].opEgL4[4]);
	messnamed(instru + "-4-keyVelSens", bank[idx].velocitySens[4]);
	messnamed(instru + "-4-level", bank[idx].level[4]);
	
	messnamed(instru + "-5-opMode", bank[idx].opMode[5]);
	messnamed(instru + "-5-opFreq", bank[idx].frequency[5]);
	messnamed(instru + "-5-opDetune", bank[idx].detune[5]);
	messnamed(instru + "-5-opRateScale", bank[idx].scaleRate[5]);
	messnamed(instru + "-5-egR1", bank[idx].opEgR1[5]);
	messnamed(instru + "-5-egR2", bank[idx].opEgR2[5]);
	messnamed(instru + "-5-egR3", bank[idx].opEgR3[5]);
	messnamed(instru + "-5-egR4", bank[idx].opEgR4[5]);
	messnamed(instru + "-5-egL1", bank[idx].opEgL1[5]);
	messnamed(instru + "-5-egL2", bank[idx].opEgL2[5]);
	messnamed(instru + "-5-egL3", bank[idx].opEgL3[5]);
	messnamed(instru + "-5-egL4", bank[idx].opEgL4[5]);
	messnamed(instru + "-5-keyVelSens", bank[idx].velocitySens[5]);
	messnamed(instru + "-5-level", bank[idx].level[5]);
};









var dx7preset = {

	// Table from d72csound
	FreqTableCoarse: [
		[0.5,1,2,3,4,5,6,7,8,9,10,11,12,13,
			14,15,16,17,18,19,20,21,22,23,24,
			25,26,27,28,29,30,31],
		[1,10,100,1000,1,10,100,1000,1,10,
			100,1000,1,10,100,1000,1,10,100,
			1000,1,10,100,1000,1,10,100,1000,
			1,10,100,1000]
	],

	// Table from d72csound
	FreqTableFine: [
		[1.00,1.01,1.02,1.03,1.04,1.05,1.06,
			1.07,1.08,1.09,1.10,1.11,1.12,1.13,
			1.14,1.15,1.16,1.17,1.18,1.19,1.20,
			1.21,1.22,1.23,1.24,1.25,1.26,1.27,
			1.28,1.29,1.30,1.31,1.32,1.33,1.34,
			1.35,1.36,1.37,1.38,1.39,1.40,1.41,
			1.42,1.43,1.44,1.45,1.46,1.47,1.48,
			1.49,1.50,1.51,1.52,1.53,1.54,1.55,
			1.56,1.57,1.58,1.59,1.60,1.61,1.62,
			1.63,1.64,1.65,1.66,1.67,1.68,1.69,
			1.70,1.71,1.72,1.73,1.74,1.75,1.76,
			1.77,1.78,1.79,1.80,1.81,1.82,1.83,
			1.84,1.85,1.86,1.87,1.88,1.89,1.90,
			1.91,1.92,1.93,1.94,1.95,1.96,1.97,
			1.98,1.99],
		[1.000,1.023,1.047,1.072,1.096,1.122,
			1.148,1.175,1.202,1.230,1.259,1.288,
			1.318,1.349,1.380,1.413,1.445,1.479,
			1.514,1.549,1.585,1.622,1.660,1.698,
			1.738,1.778,1.820,1.862,1.905,1.950,
			1.995,2.042,2.089,2.138,2.188,2.239,
			2.291,2.344,2.399,2.455,2.512,2.570,
			2.630,2.692,2.716,2.818,2.884,2.951,
			3.020,3.090,3.162,3.236,3.311,3.388,
			3.467,3.548,3.631,3.715,3.802,3.890,
			3.981,4.074,4.169,4.266,4.365,4.467,
			4.571,4.677,4.786,4.898,5.012,5.129,
			5.248,5.370,5.495,5.623,5.754,5.888,
			6.026,6.166,6.310,6.457,6.607,6.761,
			6.918,7.079,7.244,7.413,7.586,7.762,
			7.943,8.128,8.318,8.511,8.718,8.913,
			9.120,9.333,9.550,9.772]
	],


	// Function to get rid of problematic characters in a string
	format: function(input) {
  	  	var output="";

    		for (var i = 0; i < input.length; i++) {
        		if ((input[i] >= 'a' && input[i] <= 'z')
        	    	|| (input[i] >= 'A' && input[i] <= 'Z')
        	    	|| (input[i] >= '0' && input[i] <= '9')) {
	        	    	output = output + input[i];
			};
	    	};
	    	return output;
	},



	charCode: function(input) {
		var output="";

		for(var i=0; i<input.length; i++) {
			output = output + String.fromCharCode(input[i]);
		};
		
		return output;
	},

	extractData: function(array, index) {
		var output=[];
		for (var op = 5; op >= 0; op--) {
			output.push(array[op][index]);
		};
		return output;
	},

	arrayAnd: function(array, nb) {
		var output=[];
		for(var i=0; i<array.length; i++) {
			output.push(array[i] & nb);
		};
		return output;
	},

	arrayRightShift: function(array, nb) {
		var output=[];
		for(var i=0; i<array.length; i++) {
			output.push(array[i] >> nb);
		};
		return output;
	},

	arrayAdd: function(array, nb) {
		var output=[];
		for(var i=0; i<array.length; i++) {
			output.push(array[i] + nb);
		};
		return output;
	},


	computedFrequency: function(mode, coarse, fine) {
		var frequency = [];
				
		for(var i=0; i<mode.length; i++) {
			frequency.push(
				this.FreqTableCoarse[mode[i]][coarse[i]]
				* this.FreqTableFine[mode[i]][fine[i]]);
		};
		
		return frequency;
	},




	loadBank: function (filename) {
		var fpin = File(filename);
		var presets = [];

		// Loading preset file
		if (fpin.open == 0) {
			post("Cannot open file " + filename + "\n");
			return false;
		};

  		//Read header (6L)
  		fpin.readbytes(6);

		// Parsing presets and converting them
		// preset file always contain 32 voices
		for (var i = 0; i < 32; i++) {
			var test = this.convertPatch(fpin);
			if(test!=false) {presets.push(test)};
		};

		fpin.close;
		return presets;
	},


	// Convert a DX7 patch in a string and a vector of instruments names
	convertPatch: function(bankData) {
		var instrument;// preset name
		var operators = [{},{},{},{},{},{}];
		var global;

		for(var i=0; i<6; i++) {
			operators[i] = bankData.readbytes(17);
		};

		global =  bankData.readbytes(16);

		instrument = bankData.readbytes(10);
		if(instrument==null) {return false};
		instrument[10] = '\0';
 		instrument = this.format(this.charCode(instrument));
		if(instrument=="") {return false};


//		post("family : " + bankData.foldername.split("/").pop() + "\n");
//		post("instrument : " + instrument + "\n");



		return {
			family: bankData.foldername.split("/").pop(),
			name: instrument,
			opEgR1: this.extractData(operators, 0),
			opEgR2: this.extractData(operators, 1),
			opEgR3: this.extractData(operators, 2),
			opEgR4: this.extractData(operators, 3),
			opEgL1: this.extractData(operators, 4),
			opEgL2: this.extractData(operators, 5),
			opEgL3: this.extractData(operators, 6),
			opEgL4: this.extractData(operators, 7),
			scaleBreakpoint: this.extractData(operators, 8),
			scaleDepthL: this.extractData(operators, 9),
			scaleDepthR: this.extractData(operators, 10),
			scaleCurveL: this.arrayAnd(this.extractData(operators, 11), 3), //2
			scaleCurveR: this.arrayRightShift(this.extractData(operators, 11), 2), //6
			scaleRate: this.arrayAnd(this.extractData(operators, 12), 7), //3
			detune: this.arrayAdd(this.arrayRightShift(this.extractData(operators, 12), 3), -7), //5 //range 0 to 14
			lfoAmpModSens: this.arrayAnd(this.extractData(operators, 13), 3), //2
			velocitySens: this.arrayRightShift(this.extractData(operators, 13), 2), //6
			level: this.extractData(operators, 14),
			opMode: this.arrayAnd(this.extractData(operators, 15), 1), //1
//			freqCoarse: this.arrayRightShift(this.extractData(operators, 15), 1), //7
//			freqFine: this.extractData(operators, 16),
			frequency: this.computedFrequency(
				this.arrayAnd(this.extractData(operators, 15), 1), //1
				this.arrayRightShift(this.extractData(operators, 15), 1), //7
				this.extractData(operators, 16)),
						
			pEgR1: global[0],
			pEgR2: global[1],
			pEgR3: global[2],
			pEgR4: global[3],
			pEgL1: global[4],
			pEgL2: global[5],
			pEgL3: global[6],
			pEgL4: global[7],
			algorithm: global[8],
			feedback:  global[9] & 7, //3
			keySync:   global[9] >> 3, //5
			lfoSpeed:  global[10],
			lfoDelay:  global[11],
			lfoPitchModDepth: global[12],
			lfoAmpModDepth: global[13],
			lfoPitchModSens: global[14] & 1, //1
			lfoWaveform: (global[14] >> 1) & 7, //3
			lfoSync:   global[14] >> 4, //4
			transpose: global[15]
		};
	}
};


