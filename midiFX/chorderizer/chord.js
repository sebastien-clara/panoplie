// inlets and outlets
inlets = 1;
outlets = 3;

var chord = 'Major';
var root = 42;
var inversion = 0;

var ChordDic = {
	// MajorS
	Major:[0,4,7],
	Major_6TH:[0,4,7,9],
	Major_6TH_ADD_9:[0,4,7,9,14],
	Major_7TH:[0,4,7,10],
	Major_ADD_9:[0,4,7,14],
	Major_9TH:[0,4,7,10,14],
	Major_13TH:[0,4,7,10,14,19],

	// MinorS
	Minor:[0,3,7],
	Minor_6TH:[0,3,7,9],
	Minor_6TH_ADD_9:[0,3,7,9,14],
	Minor_7TH:[0,3,7,10],
	Minor_7TH_FLAT_5:[0,3,6,10],
	Minor_ADD_9:[0,3,7,14],
	Minor_9TH:[0,3,7,10,14],
	Minor_10TH:[0,3,7,10,14,17],
	Minor_13TH:[0,3,7,10,14,17,19],

	// OTHERS
	Augmented:[0,4,8],
	Diminished:[0,3,6],
	Dominant_7TH:[0,4,7,10],
	Suspended_4TH:[0,5,7],
	Suspended_2ND:[0,2,7],
	_4TH:[0,5,10,15],
	_5TH:[0,7,14,21],
	WhatNot_1:[0,3,5,8,13],
	WhatNot_2:[0,3,6,9]
};


///////////////////////////////////////////////
// Set parameters
function selectChord(val) {
	chord = val;
	outlet(2, ChordDic[chord]);
}

function selectRoot(val) { root = val }

function selectInv(val) { inversion = val }
	
///////////////////////////////////////////////
// midi ON - OFF
function list(note, velocity) {
	var viewChord = ['chord '];
	var chordInv = arrayRotate(ChordDic[chord].slice(), inversion);

	for(var i=0; i<chordInv.length; i++) {
		viewChord.push(note + chordInv[i]);
		viewChord.push(velocity);
		outlet(0, [note + chordInv[i], velocity]);
	};

	if(velocity != 0) {
		root = note;
		messnamed("root", root);
		outlet(1, viewChord.toString().replace(/,/g, ' '));
	}
}


///////////////////////////////////////////////
// tools
function arrayRotate(arr, num) {
	if(num != 0) {
		for(var i=0; i<num; i++) {
			arr.push(arr.shift()+12)
		}
	}

	return arr
}
