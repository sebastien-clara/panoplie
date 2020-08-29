// inlets and outlets
inlets = 1;
outlets = 1;

var midiNotes = [];
var midiSeq = [];


var taskRun;

var operation;
var tempoMS;
var tempoSave;
var tempoCoef = 1;
var durCoef;
var octaveUp=0, octaveDown=0;
var transpose = 0;
var inTempo = false;

///////////////////////////////////////////////
// midi ON - OFF
function list(note, velocity) {

	if(velocity != 0) {
		midiNotes.push(note);
		
		if ((taskRun == null) || !taskRun.running) {
			taskManager.playArp();
		}
	} else {
		midiNotes.splice(midiNotes.indexOf(note), 1);
		if(midiNotes.length==0) { taskManager.stop() }
	};

	if(0 < midiNotes.length) { operations.apply(operation) }

//	post("midiNotes = " + midiNotes + "\n");
//	post("midiSeq = " + midiSeq + "\n");

}



///////////////////////////////////////////////
// Arp options
function selectOpe(ope) {
	operation = ope;
	if ((taskRun != null) && taskRun.running) {
		operations.apply(operation);
	}
}

function selectTempo(val) {
	tempoSave = Math.round(val);
	tempoMS = 60000/(tempoSave*tempoCoef);
}

function tempoMultiplicator(val) {
	tempoCoef = val;
	tempoMS = 60000/(tempoSave*tempoCoef);
}

function selectDur(val) { durCoef = Math.round(val)*0.01 }

function addOctaveUp(val) { octaveUp = val; operations.apply(operation)}

function addOctaveDown(val) { octaveDown = val; operations.apply(operation)}

function transposition(val) { transpose = val; operations.apply(operation)}

function playInTempo(val) {
		if (val == 0) {
			inTempo = false;
		} else {
			inTempo = true;
		}
};

		
function stopArp() { taskManager.stop() }


///////////////////////////////////////////////
// Arp operations
var operations = {
	Up : function () {
		if(1 < midiSeq.length) {
			midiSeq.sort(function(a, b){return a - b});
		}
	},
	
	Down : function () {
		if(1 < midiSeq.length) {
			midiSeq.sort(function(a, b){return b - a});
		}
	},

	UpDown : function () {
	switch (midiSeq.length) {
    	case 0:
        	break;
    	case 1:
        	break;
    	case 2:
			midiSeq.sort(function(a, b){return a - b});
        	break;
		default:
			var tmp = [];
			midiSeq.sort(function(a, b){return a - b});
			tmp = midiSeq.slice();
			tmp.shift(); tmp.pop();tmp.reverse();
			midiSeq = midiSeq.concat(tmp);
		}
	},

	UpDown2 : function () {
		if(1 < midiSeq.length) {
			var tmp = [];
			midiSeq.sort(function(a, b){return a - b});
			tmp = midiSeq.slice();
			tmp.reverse();
			midiSeq = midiSeq.concat(tmp);
		};
	},
	

	DownUp : function () {
	switch (midiSeq.length) {
    	case 0:
        	break;
    	case 1:
        	break;
    	case 2:
			midiSeq.sort(function(a, b){return b - a});
        	break;
		default:
			var tmp = [];
			midiSeq.sort(function(a, b){return b - a});
			tmp = midiSeq.slice();
			tmp.shift(); tmp.pop();tmp.reverse();
			midiSeq = midiSeq.concat(tmp);
		}
	},
	
	DownUp2 : function () {
		if(1 < midiSeq.length) {
			var tmp = [];
			midiSeq.sort(function(a, b){return b - a});
			tmp = midiSeq.slice();
			tmp.reverse();
			midiSeq = midiSeq.concat(tmp);
		}
	},
	
	Random : function () { },

	FiFo : function () { },

	LiFo : function () {
		midiSeq.reverse();
	},

	Converge : function () {
		if(1 < midiSeq.length) {
			var tmp = midiSeq.slice();
			var cpt = midiSeq.length;
			midiSeq = [];
			for(var i=0; i<cpt; i++) {
				if(i%2 == 0) {
					midiSeq.push(tmp.shift());
				} else {
					midiSeq.push(tmp.pop());
				}
			}
		}
	},

	AltRepeat : function (repeat, first) {
		if(1 < midiSeq.length) {
			var tmp = midiSeq.slice();
			var cpt = midiSeq.length;
			midiSeq = [];
			for(var i=0; i<cpt; i++) {
				if(first) {
					midiSeq.push(repeat);
					midiSeq.push(tmp.shift());
				} else {
					midiSeq.push(tmp.shift());
					midiSeq.push(repeat);
				}
			}
		} else {
			midiSeq.push(repeat)
		}
	},
	
	octaveUp : function () {
		var tmp = midiNotes.slice();
		
		for(var i=0; i<octaveUp; i++) {
			for(var j=0; j<tmp.length; j++) {
				midiSeq.push(tmp[j]+(12*(i+1)));
			}
		}
	},

	octaveDown : function () {
		var tmp = midiNotes.slice();
		tmp.reverse();
		
		for(var i=0; i<octaveDown; i++) {
			for(var j=0; j<tmp.length; j++) {
				midiSeq.unshift(tmp[j]-(12*(i+1)));
			}
		}
	},
	
	addOctave : function () {
		this.octaveUp();
		this.octaveDown();
	},

	transposeTab : function(tab, transpo) {
		if(transpo != 0) {
			for(i = 0; i < tab.length; i++) tab[i] = tab[i] + transpo;
		}
		return(tab);
	},	


	apply : function(ope) {
		midiSeq = midiNotes.slice();

		this.transposeTab(midiSeq, transpose);

		this.addOctave();

		switch (ope) {
    	case "Up":
        	this.Up();
        	break;
    	case "Down":
        	this.Down();
        	break;
    	case "UpDown":
        	this.UpDown();
        	break;
    	case "UpDown2":
        	this.UpDown2();
        	break;
    	case "DownUp":
        	this.DownUp();
        	break;
    	case "DownUp2":
        	this.DownUp2();
        	break;
    	case "Random":
//        	this.Random();
        	break;
    	case "FiFo":
//        	this.FiFo();
        	break;
    	case "LiFo":
        	this.LiFo();
        	break;

		case "Converge":
			this.Up();
			this.Converge();
	       	break;
	   	case "ConvergeDown":
			this.Down();
			this.Converge();
	       	break;
	   	case "Diverge":
			this.Down();
			this.Converge();
			midiSeq.reverse();
	       	break;
		case "DivergeDown":
			this.Up();
			this.Converge();
			midiSeq.reverse();
	       	break;
		case "Conv&Diverge":
			//Diverge
			this.Down();
			this.Converge();
			midiSeq.reverse();
			var div = midiSeq.slice();
			//div.shift();
			
			//Converge
			midiSeq = midiNotes.slice();
			this.Up();
			this.Converge();
			//Conv&Diverge
			midiSeq = midiSeq.concat(div);
	       	break;
		case "Div&Converge":
			//Converge
			this.Up();
			this.Converge();
			var conv = midiSeq.slice();
			//conv.shift();
			
			//Diverge
			midiSeq = midiNotes.slice();
			this.Down();
			this.Converge();
			midiSeq.reverse();
			//Div&Converge
			midiSeq = midiSeq.concat(conv);
	       	break;
	    case "PinkyUp":
			this.Up();
			this.AltRepeat(midiSeq.pop(), false);
	       	break;
	   	case "PinkyUpDown":
			this.Up();
			var repeat = midiSeq.pop(); 
			this.UpDown();
			this.AltRepeat(repeat, false);
	       	break;
	   	case "PinkyDown":
			this.Down();
			this.AltRepeat(midiSeq.shift(), true);
	       	break;
    	case "PinkyDownUp":
			this.Down();
			var repeat = midiSeq.shift(); 
			this.DownUp();
			this.AltRepeat(repeat, true);
			break;
	    case "ThumbUp":
			this.Up();
			this.AltRepeat(midiSeq.shift(), true);
			break;
	   	case "ThumbUpDown":
			this.Up();
			var repeat = midiSeq.shift(); 
			this.UpDown();
			this.AltRepeat(repeat, true);
			break;
	    case "ThumbDown":
			this.Down();
			this.AltRepeat(midiSeq.pop(), true);
			break;
	    case "ThumbDownUp":
			this.Down();
			var repeat = midiSeq.pop(); 
			this.DownUp();
			this.AltRepeat(repeat, true);
			break;
		}
	}
}

///////////////////////////////////////////////
// task
var taskManager = {
	stop : function() {
		if (((taskRun != null) && taskRun.running)) {
//			post("stop task\n");
			taskRun.cancel();
		}
	},
	

	play : function() {
		var index;
		var interval;
		
		if(operation=="Random") {
			index = Math.floor(Math.random() * (midiSeq.length));
		} else {
			index = arguments.callee.task.iterations % (midiSeq.length);
		}

		if(inTempo) {
			interval = tempoMS / midiSeq.length
		} else {
			interval = tempoMS
		}
		arguments.callee.task.interval = interval;
		
		outlet(0, [midiSeq[index], 100, interval * durCoef]);
	},

	playArp : function() {
		this.stop();
		
		taskRun = new Task(this.play, this);
		taskRun.interval = tempoMS;
		
		taskRun.repeat();
	}
}
