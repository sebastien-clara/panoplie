// inlets and outlets
inlets = 1;
outlets = 1;



///////////////////////////////////////////////
// Set parameters
function changeOpe(ope) {
	duetOperation.type = parseInt(ope);
	if (duetOperation.type==5) {duetOperation.multi=true} else {duetOperation.multi=false}
}

function changeTempoMul(val) { duetForOne.tempoMul = 1/val }

function stopDuo() { duetManager.stop() }



///////////////////////////////////////////////
// MIDI On - Off
function list(note, velocity) {
	if(velocity != 0) {
		duetForOne.midiON(note, velocity)
	} else {
		duetForOne.midiOFF(note, velocity)
	}
}

var duetForOne = {
  symmetryPoint : 60,
  tempoMul : 1,

  notes : {},
  backup : {},
  backupCounter : 0,
  timer : 0,

  getTimer : function() {
    this.timer = parseInt(new Date().getTime());
  },

	midiON : function(note, velocity) {
    this.getTimer();

  	this.notes.pitch.push(note);
  	this.notes.velocity.push(velocity);
  	this.notes.duration.push(0);
  	this.notes.date.push(this.timer);

  	switch(duetOperation.type) {
  	case 0:
  		outlet(0, [ duetOperation.symmetry(note, this.symmetryPoint), velocity*0.5 ]);
  		break;
  	case 1:
  		duetOperation.playSymmetry(note, velocity);
		outlet(0, [duetOperation.symmetry(note, this.symmetryPoint), velocity*0.5 ]);
  		break;
  	case 2:
  		duetOperation.playOvertones(note, velocity);
  		break;
  	case 3:
  		duetOperation.playRepetition(note, velocity);
  		break;
  	case 4:
  		duetOperation.playRepetition((note-Math.round(duetTool.clipScale(velocity, 15,127, 3,24))), velocity);
  		break;
  	case 5:
  		var index = this.notes.pitch.indexOf(note);

/*  		if(this.notes.velocity[index] > 105) {
  			duetOperation.playRepetition((this.notes.pitch[index]%12)+36-Math.round(duetTool.clipScale(velocity, 15,100, 3,24)), this.notes.velocity[index]);
  		}
*/

  		if( (this.notes.pitch.length > 1) &&
  			(this.notes.pitch[index] != this.notes.pitch[index-1]) &&
  			((this.notes.pitch[index]-this.notes.pitch[index-1])%12 == 0) ) {
  //				console.log("-------------octave !!\n");

  			duetOperation.playSymmetry(60-(this.notes.pitch[index]%12), this.notes.velocity[index]*1/3);
  			duetOperation.playSymmetry(60+(this.notes.pitch[index]%12), this.notes.velocity[index]*3/4);
  		}

  		break;
  	}
  },

  midiOFF : function(note, velocity) {
    this.getTimer();

  	var indexNote = this.notes.pitch.lastIndexOf(note);

  	this.notes.duration[indexNote] = this.timer - this.notes.date[indexNote];

  	if((duetOperation.type==0)||(duetOperation.type==1)) {
		outlet(0, [duetOperation.symmetry(note, this.symmetryPoint), 0 ]);
  	}

  	if(duetOperation.multi) {
  		if(this.notes.duration[indexNote]>1500) {
  			duetOperation.playOvertones((this.notes.pitch[indexNote]%12)+24, this.notes.velocity[indexNote]*1.25);
  		}
  	}

  	if( (this.notes.pitch.length > 5) &&
  		(((this.notes.pitch[indexNote]-this.notes.pitch[indexNote-1])%12)==5) ) {
  //			console.log("-------------quarte up -- " + this.backupCounter + " !!\n");

  		var indexSection = duetTool.searchSection(this.notes);
  //			console.log("indexSection => " + indexSection + "\n");
  		if(indexSection != -1) {
  			var indexBackup = this.backupCounter;
  			this.backupCounter = (this.backupCounter+1)%this.backup.pitch.length;

  			duetTool.saveData(this.notes, indexSection, this.backup, indexBackup);
  			duetTool.clearData(this.notes, indexSection);

  			if(duetOperation.multi) {
  				duetOperation.playEcho(
  					duetOperation.symmetryArr(this.backup.pitch[indexBackup], this.symmetryPoint).reverse(),
  					this.backup.velocity[indexBackup].reverse(),
  					this.backup.duration[indexBackup].reverse(),
  					duetTool.multiplyTabFactor(this.backup.interval[indexBackup], this.tempoMul).reverse());
  			}
  		}
  	}

  	if( (this.notes.pitch.length > 5) &&
  		((Math.abs(this.notes.pitch[indexNote]-this.notes.pitch[indexNote-1])%12)==6) ) {
  //			console.log("-------------triton -- " + this.backupCounter + " !!\n");

  		var indexSection = duetTool.searchSection(this.notes);
  //			console.log("indexSection => " + indexSection + "\n");
  		if(indexSection != -1) {
  			var indexBackup = this.backupCounter;
  			this.backupCounter = (this.backupCounter+1)%this.backup.pitch.length;

  			duetTool.saveData(this.notes, indexSection, this.backup, indexBackup);
  			duetTool.clearData(this.notes, indexSection);

  			if(duetOperation.multi) {
  				duetOperation.playEcho(
  					duetOperation.transposeArr(this.backup.pitch[indexBackup].reverse(), -1),
  					this.backup.velocity[indexBackup].reverse(),
  					this.backup.duration[indexBackup].reverse(),
  					duetTool.multiplyTabFactor(
              duetTool.arrayRotate(this.backup.interval[indexBackup].reverse()), this.tempoMul));
  			}
  		}
  	}

  	if( (this.notes.pitch.length > 5) &&
  		(((this.notes.pitch[indexNote-1]-this.notes.pitch[indexNote])%12)==7) ) {
  //			console.log("-------------quinte down -- " + this.backupCounter + " !!\n");

  		var indexSection = duetTool.searchSection(this.notes);
  //		console.log("indexSection => " + indexSection);
  		if(indexSection != -1) {
  			var indexBackup = this.backupCounter;
  			this.backupCounter = (this.backupCounter+1)%this.backup.pitch.length;

  			duetTool.saveData(this.notes, indexSection, this.backup, indexBackup);
  			duetTool.clearData(this.notes, indexSection);

  			if(duetOperation.multi) {
  				duetOperation.playEcho(
  					this.backup.pitch[indexBackup],
  					this.backup.velocity[indexBackup],
  					this.backup.duration[indexBackup],
  					duetTool.multiplyTabFactor(this.backup.interval[indexBackup], this.tempoMul));
  			}
  		}
  	}

  	if( (this.notes.pitch.length > 5) &&
  		((Math.abs(this.notes.pitch[indexNote]-this.notes.pitch[indexNote-1])%12)==8) ) {
  //			console.log("-------------sixte minor -- " + this.backupCounter + " !!\n");

  		var indexSection = duetTool.searchSection(this.notes);
  //			console.log("indexSection => " + indexSection + "\n");
  		if(indexSection != -1) {
  			var indexBackup = this.backupCounter;
  			this.backupCounter = (this.backupCounter+1)%this.backup.pitch.length;

  			duetTool.saveData(this.notes, indexSection, this.backup, indexBackup);
  			duetTool.clearData(this.notes, indexSection);

  			if(duetOperation.multi) {
  				duetOperation.playEcho(
  					duetOperation.symmetryArr(this.backup.pitch[indexBackup], this.symmetryPoint),
  					this.backup.velocity[indexBackup],
  					this.backup.duration[indexBackup],
  					duetTool.multiplyTabFactor(this.backup.interval[indexBackup], this.tempoMul));
  			}
  		}
  	}
  }
}


duetForOne.notes.pitch = new Array;
duetForOne.notes.velocity = new Array;
duetForOne.notes.duration = new Array;
duetForOne.notes.date = new Array;

var duetBackupMemory = 128;
duetForOne.backup.pitch = new Array(duetBackupMemory);
duetForOne.backup.velocity = new Array(duetBackupMemory);
duetForOne.backup.duration = new Array(duetBackupMemory);
duetForOne.backup.interval = new Array(duetBackupMemory);


///////////////////////////////////////////////
// Duet operations
///////////////////////////////////////////////
// Duet operation
var duetOperation = {
  type : 3,
  multi : false,


	symmetryOpe : function() {
		var note = arguments.callee.task.arguments[0][0];
		var velocity = arguments.callee.task.arguments[0][1];
		var drift, amp;

		if (note == Number(duetForOne.symmetryPoint)) {
			drift = note;
			amp = Math.round(velocity-(arguments.callee.task.iterations*duetTool.midi2data(velocity, 0.125, 10)));
		} else if (Number(note) < Number(duetOperation.symmetryPoint)) {
			drift = duetOperation.symmetry(note, duetForOne.symmetryPoint) + (12*(arguments.callee.task.iterations));
			amp = Math.round((velocity*0.6)-(arguments.callee.task.iterations*duetTool.midi2data(velocity, 0.125, 10)));
		} else {
			drift = duetOperation.symmetry(note, duetForOne.symmetryPoint) - (12*(arguments.callee.task.iterations));
			//amp = Math.round(velocity-(arguments.callee.task.iterations*duetTool.midi2data(velocity, 0.125, 1)));
			amp = velocity*1.1;
		}


		if((23<drift)&&(drift<127)&&(amp>0)) {
			outlet(0, drift, amp, duetTool.midi2data(velocity, 1000, 200));
		} else {
			arguments.callee.task.cancel();
		}
	},
	
	playSymmetry : function(note, velocity) {
		var index = duetManager.counter;
		duetManager.counter = (duetManager.counter+1)%duetManager.run.length;

		duetManager.stopTask(duetManager.run[index]);

		duetManager.run[index] = new Task(this.symmetryOpe, this, [note, velocity]);
		duetManager.run[index].interval = duetTool.midi2data(velocity, 500, 50);
		duetManager.run[index].repeat();
	},



	overtonesOpe : function() {
		var note = arguments.callee.task.arguments[0][0];
		var velocity = arguments.callee.task.arguments[0][1];
		var coef = arguments.callee.task.iterations + 1;
		var drift = duetTool.freq2midi(duetTool.midi2freq(note)*coef);
		var amp = Math.round((velocity*0.7)-(arguments.callee.task.iterations*duetTool.midi2data(velocity, 1, 10)));


		if((drift<128)&&(amp>0)&&(arguments.callee.task.iterations<16)) {
			outlet(0, drift, amp, duetTool.midi2data(velocity, 1000, 200));
		} else {
			arguments.callee.task.cancel();
		}
	},

	playOvertones : function (note, velocity) {
		var index = duetManager.counter;
		duetManager.counter = (duetManager.counter+1)%duetManager.run.length;

		duetManager.stopTask(duetManager.run[index]);

		duetManager.stopTask(duetManager.run[index]);

		duetManager.run[index] = new Task(this.overtonesOpe, this, [note, velocity]);
		duetManager.run[index].interval = duetTool.midi2data(velocity, 1300, 25);
		duetManager.run[index].repeat(13);
	},



	repetitionOpe : function() {
		var note = arguments.callee.task.arguments[0][0];
		var velocity = arguments.callee.task.arguments[0][1];


		var coef = arguments.callee.task.iterations;
		var	decay = Math.exp(coef*0.01);
	
		var amp = Math.round(velocity-(arguments.callee.task.iterations*duetTool.midi2data(velocity, 0.01, 5)));
	
		arguments.callee.task.interval=arguments.callee.task.interval*decay;
	
		if((arguments.callee.task.interval<1800)&&(amp>0)) {
			outlet(0, [ note, amp, 150]);
		} else {
			arguments.callee.task.cancel();
		}
	},

	playRepetition : function(note, velocity) {
		var index = duetManager.counter;
		duetManager.counter = (duetManager.counter+1)%duetManager.run.length;

		duetManager.stopTask(duetManager.run[index]);


		duetManager.run[index] = new Task(this.repetitionOpe, this, [note, velocity]);
		duetManager.run[index].interval = duetTool.midi2data(velocity, 500, 100);
		duetManager.run[index].repeat();
	},




	echoOpe : function() {
		var pitch = arguments.callee.task.arguments[0][0];
		var velocity = arguments.callee.task.arguments[0][1];
		var dur = arguments.callee.task.arguments[0][2];
		var interval = arguments.callee.task.arguments[0][3];

		var index =  arguments.callee.task.iterations;

		outlet(0, [pitch[index], velocity[index], dur[index]]);

        if(index < pitch.length-1) {
			arguments.callee.task.interval =  interval[index];
		} else {
			arguments.callee.task.cancel();
		}
	},

	playEcho : function(pitch, velocity, dur, interval) {
    var index = duetManager.counter;
		duetManager.counter = (duetManager.counter+1)%duetManager.run.length;

		duetManager.stopTask(duetManager.run[index]);

		duetManager.run[index] = new Task(this.echoOpe, this, [pitch, velocity, dur, interval]);

		duetManager.run[index].repeat();
	},


	symmetry : function(note, symmetryPoint) {
		return((symmetryPoint*2) - note);
	},
	symmetryArr : function(arr, symmetryPoint) {
		for(var i = 0; i < arr.length; i++) arr[i] = this.symmetry(arr[i], symmetryPoint);

		return(arr);
	},

	transposeArr : function(arr, transpo) {
		for(var i = 0; i < arr.length; i++) arr[i] = arr[i] + transpo;

		return(arr);
	}
}


///////////////////////////////////////////////
// task
var duetManager = {
	run : new Array(3),
	counter : 0,

	stop : function() {
		post("Stop task\n");
		this.stopAllTask(this.run);
	},

	stopTask : function(task) {
		if (((task != undefined) && task.running)) {
			task.cancel();
		}
	},

	stopAllTask : function(tab) {
		for(var i = 0; i < tab.length; i++) this.stopTask(tab[i]);
	}
};


///////////////////////////////////////////////
// tools
///////////////////////////////////////////////
// Tools
var duetTool = {
	searchSection : function(data) {
		var index = data.duration.indexOf(0);

		if (index == -1) {
			return(data.duration.length-1);
		} else if (index > data.duration.length-5) {
			return(-1);
		} else {
			return(index);
		}
	},

	saveData : function(data, indexData, save, indexSave) {
		save.pitch[indexSave] = data.pitch.slice(0, indexData+1);
		save.velocity[indexSave] = data.velocity.slice(0, indexData+1);
		save.duration[indexSave] = data.duration.slice(0, indexData+1);
    save.interval[indexSave] = this.date2interval(data.date.slice(0, indexData+1));
	},
	clearData : function(data, index) {
		data.pitch.splice(0, index+1);
		data.velocity.splice(0, index+1);
		data.duration.splice(0, index+1);
		data.date.splice(0, index+1);
	},

	date2interval : function(arr) {
		for(var i = 0; i < arr.length-1; i++) {
      arr[i] = arr[i+1] - arr[i];
    };
		arr[arr.length-1] = 0;
		return(arr);
	},


	multiplyTabFactor : function(arr, factor) {
		for(var i = 0; i < arr.length; i++) arr[i] = Math.round(arr[i] * factor);
		return(arr);
	},

  arrayRotate : function(arr, reverse) {
    if(reverse)
      arr.unshift(arr.pop())
    else
      arr.push(arr.shift())
    return arr
  },
/*
usage:
arrayRotate(['h','e','l','l','o']);       // ['e','l','l','o','h'];
arrayRotate(['h','e','l','l','o'], true); // ['o','h','e','l','l'];
*/


	midi2freq : function(note) {
		return(440 * Math.pow(2,(note - 69)/12));
	},

	freq2midi : function(freq) {
		return(Math.round((12 * (Math.log(freq / 440) / Math.log(2))) + 69));
	},


	scale : function(value, minIn, maxIn, minOut, maxOut) {
		return(((maxOut - minOut) * (value - minIn) / (maxIn - minIn)) + minOut);
	},

	clipScale : function(value, minIn, maxIn, minOut, maxOut) {
		var result = this.scale(value, minIn,maxIn, minOut,maxOut);

		if (result < Math.min(minOut, maxOut)) {
			return(Math.min(minOut, maxOut));
		} else if (result > Math.max(minOut, maxOut)) {
			return(Math.max(minOut, maxOut));
		} else {
			return(result);
		}
	},

	midi2data : function(value, minOut, maxOut) {
		return(this.clipScale(value, 0,127, minOut,maxOut));
	}
}

