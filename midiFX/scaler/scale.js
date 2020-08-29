// inlets and outlets
inlets = 1;
outlets = 5;


var scale = 'Minor Pentatonic';
var root = 0;

var scaleDic = {
	// 5 note scales
	"Minor Pentatonic" : {scale:[0,3,5,7,10], modulo:12, name:"Minor Pentatonic"},
	"Major Pentatonic" : {scale:[0,2,4,7,9], modulo:12, name: "Major Pentatonic"},
	// another mode of major pentatonic
	"Ritusen" : {scale:[0,2,5,7,9], modulo:12, name:"Ritusen"},
	// another mode of major pentatonic
	"Egyptian" : {scale:[0,2,5,7,10], modulo:12, name:"Egyptian"},
	
	"Kumai" : {scale:[0,2,3,7,9], modulo:12, name: "Kumai"},
	"Hirajoshi" : {scale:[0,2,3,7,8], modulo:12, name: "Hirajoshi"},
	"Iwato" : {scale:[0,1,5,6,10], modulo:12, name: "Iwato"}, // mode of hirajoshi
	"Chinese" : {scale:[0,4,6,7,11], modulo:12, name: "Chinese"}, // mode of hirajoshi
	"Indian" : {scale:[0,4,5,7,10], modulo:12, name: "Indian"},
	"Pelog" : {scale:[0,1,3,7,8], modulo:12, name: "Pelog"},
	
	"Prometheus" : {scale:[0,2,4,6,11], modulo:12, name: "Prometheus"},
	"Scriabin" : {scale:[0,1,4,7,9], modulo:12, name: "Scriabin"},
	
	//Ethiopian scale
	"Tizita Major" : {scale:[0,2,4,7,9], modulo:12, name: "Tizita Major or Major Pentatonic"},
	"Tizita Minor" : {scale:[0,2,3,7,8], modulo:12, name: "Tizita Minor or Hirajoshi"},
	"Batti Major" : {scale:[0,4,5,7,11], modulo:12, name: "Batti Major"},
	"Batti Minor" : {scale:[0,3,5,7,10], modulo:12, name: "Batti Minor or Minor Pentatonic or Yu"},
	"Ambassel" : {scale:[0,1,5,7,8], modulo:12, name: "Ambassel"},
	"Ambassel 2" : {scale:[0,2,5,7,9], modulo:12, name: "Ambassel 2 or Ritusen"},
	"Anchi Hoye" : {scale:[0,3,6,7,11], modulo:12, name: "Anchi Hoye"},
	"Anchi Hoye 2" : {scale:[0,1,5,6,9], modulo:12, name: "Anchi Hoye 2"},
	"Yematebela Wofe" : {scale:[0,2,5,7,10], modulo:12, name: "Yematebela Wofe or Egyptian or Shang"},
	"Shegaye" : {scale:[0,3,5,8,10], modulo:12, name: "Shegaye or Jiao"},

	// han chinese pentatonic scales
	"Gong" : {scale:[0,2,4,7,9], modulo:12, name: "Gong"},
	"Shang" : {scale:[0,2,5,7,10], modulo:12, name: "Shang"},
	"Jiao" : {scale:[0,3,5,8,10], modulo:12, name: "Jiao"},
	"Zhi" : {scale:[0,2,5,7,9], modulo:12, name: "Zhi"},
	"Yu" : {scale:[0,3,5,7,10], modulo:12, name: "Yu"},
	
	
	// 6 note scales
	"Whole Tone" : {scale:[0,2,4,6,8,10], modulo:12, name: "Whole Tone"},
	"Augmented" : {scale:[0,3,4,7,8,11], modulo:12, name: "Augmented"},
	"Augmented 2" : {scale:[0,1,4,5,8,9], modulo:12, name: "Augmented 2"},
	
	// Partch's Otonalities and Utonalities
	"Partch Otonality 1" : {scale:[0,8,14,20,25,34], modulo:43, name: "Partch Otonality 1"},
	"Partch Otonality 2" : {scale:[0,7,13,18,27,35], modulo:43, name: "Partch Otonality 2"},
	"Partch Otonality 3" : {scale:[0,6,12,21,29,36], modulo:43, name: "Partch Otonality 3"},
	"Partch Otonality 4" : {scale:[0,5,15,23,30,37], modulo:43, name: "Partch Otonality 4"},
	"Partch Otonality 5" : {scale:[0,10,18,25,31,38], modulo:43, name: "Partch Otonality 5"},
	"Partch Otonality 6" : {scale:[0,9,16,22,28,33], modulo:43, name: "Partch Otonality 6"},
	"Partch Utonality 1" : {scale:[0,9,18,23,29,35], modulo:43, name: "Partch Utonality 1"},
	"Partch Utonality 2" : {scale:[0,8,16,25,30,36], modulo:43, name: "Partch Utonality 2"},
	"Partch Utonality 3" : {scale:[0,7,14,22,31,37], modulo:43, name: "Partch Utonality 3"},
	"Partch Utonality 4" : {scale:[0,6,13,20,28,38], modulo:43, name: "Partch Utonality 4"},
	"Partch Utonality 5" : {scale:[0,5,12,18,25,33], modulo:43, name: "Partch Utonality 5"},
	"Partch Utonality 6" : {scale:[0,10,15,21,27,34], modulo:43, name: "Partch Utonality 6"},
	
	// hexatonic modes with no tritone
	"Hex Major 7" : {scale:[0,2,4,7,9,11], modulo:12, name: "Hex Major 7"},
	"Hex Dorian" : {scale:[0,2,3,5,7,10], modulo:12, name: "Hex Dorian"},
	"Hex Phrygian" : {scale:[0,1,3,5,8,10], modulo:12, name: "Hex Phrygian"},
	"Hex Sus" : {scale:[0,2,5,7,9,10], modulo:12, name: "Hex Sus"},
	"Hex Major 6" : {scale:[0,2,4,5,7,9], modulo:12, name: "Hex Major 6"},
	"Hex Aeolian" : {scale:[0,3,5,7,8,10], modulo:12, name: "Hex Aeolian"},
	
	// 7 note scales
	"Major" : {scale:[0,2,4,5,7,9,11], modulo:12, name: "Major"},
	"Ionian" : {scale:[0,2,4,5,7,9,11], modulo:12, name: "Ionian"},
	"Dorian" : {scale:[0,2,3,5,7,9,10], modulo:12, name: "Dorian"},
	"Phrygian" : {scale:[0,1,3,5,7,8,10], modulo:12, name: "Phrygian"},
	"Lydian" : {scale:[0,2,4,6,7,9,11], modulo:12, name: "Lydian"},
	"Mixolydian" : {scale:[0,2,4,5,7,9,10], modulo:12, name: "Mixolydian"},
	"Aeolian" : {scale:[0,2,3,5,7,8,10], modulo:12, name: "Aeolian"},
	"Minor" : {scale:[0,2,3,5,7,8,10], modulo:12, name: "Natural Minor"},
	"Locrian" : {scale:[0,1,3,5,6,8,10], modulo:12, name: "Locrian"},
	
	"Marmonic Minor" : {scale:[0,2,3,5,7,8,11], modulo:12, name: "Harmonic Minor"},
	"Harmonic Major" : {scale:[0,2,4,5,7,8,11], modulo:12, name: "Harmonic Major"},
	
	"Melodic Minor" : {scale:[0,2,3,5,7,9,11], modulo:12, name: "Melodic Minor"},
	"Melodic Minor Desc" : {scale:[0,2,3,5,7,8,10], modulo:12, name: "Melodic Minor Descending"},
	"Melodic Major" : {scale:[0,2,4,5,7,8,10], modulo:12, name: "Melodic Major"},
	
	"Bartok" : {scale:[0,2,4,5,7,8,10], modulo:12, name: "Bartok"},
	"Hindu" : {scale:[0,2,4,5,7,8,10], modulo:12, name: "Hindu"},
	
	// raga modes
	"Todi" : {scale:[0,1,3,6,7,8,11], modulo:12, name: "Todi"},
	"Purvi" : {scale:[0,1,4,6,7,8,11], modulo:12, name: "Purvi"},
	"Marva" : {scale:[0,1,4,6,7,9,11], modulo:12, name: "Marva"},
	"Bhairavi" : {scale:[0,1,4,5,7,8,11], modulo:12, name: "Bhairavi"},
	"Ahirbhairav" : {scale:[0,1,4,5,7,9,10], modulo:12, name: "Ahirbhairav"},
	
	"Super Locrian" : {scale:[0,1,3,4,6,8,10], modulo:12, name: "Super Locrian"},
	"Romanian Minor" : {scale:[0,2,3,6,7,9,10], modulo:12, name: "Romanian Minor"},
	"Hungarian Minor" : {scale:[0,2,3,6,7,8,11], modulo:12, name: "Hungarian Minor"},
	"Neapolitan Minor" : {scale:[0,1,3,5,7,8,11], modulo:12, name: "Neapolitan Minor"},
	"Enigmatic" : {scale:[0,1,4,6,8,10,11], modulo:12, name: "Enigmatic"},
	"Spanish" : {scale:[0,1,4,5,7,8,10], modulo:12, name: "Spanish"},
	"Gypsy" : {scale:[0,2,3,6,7,8,10], modulo:12, name: "Gypsy"},

	// modes of whole tones with added note ->
	"Leading Whole Tone" : {scale:[0,2,4,6,8,10,11], modulo:12, name: "Leading Whole Tone"},
	"Lydian Minor" : {scale:[0,2,4,6,7,8,10], modulo:12, name: "Lydian Minor"},
	"Neapolitan Major" : {scale:[0,1,3,5,7,9,11], modulo:12, name: "Neapolitan Major"},
	"Locrian Major" : {scale:[0,2,4,5,6,8,10], modulo:12, name: "Locrian Major"},
	
	// 8 note scales
	"Diminished" : {scale:[0,1,3,4,6,7,9,10], modulo:12, name: "Diminished"},
	"Diminished 2" : {scale:[0,2,3,5,6,8,9,11], modulo:12, name: "Diminished 2"},

	//Bebop scale
	"Bebop Dominant" : {scale:[0,2,4,5,7,9,10,11], modulo:12, name: "Bebop Dominant"},
	"Bebop Dorian" : {scale:[0,2,3,4,5,7,9,10], modulo:12, name: "Bebop Dorian"},
	"Bebop Dorian 2" : {scale:[0,2,3,5,7,9,10,11], modulo:12, name: "Bebop Dorian 2"},
	"Bebop Major" : {scale:[0,2,4,5,7,8,9,11], modulo:12, name: "Bebop Major"},
	"Bebop Melodic Minor" : {scale:[0,2,3,5,7,8,9,11], modulo:12, name: "Bebop Melodic Minor"},
	"Bebop Harmonic Minor" : {scale:[0,2,3,5,7,8,10,11], modulo:12, name: "Bebop Harmonic Minor"},
	
	// maqam ajam
	"Ajam" : {scale:[0,4,8,10,14,18,22], modulo:24, name: "Ajam"},
	"Jiharkah" : {scale:[0,4,8,10,14,18,21], modulo:24, name: "Jiharkah"},
	"Shawq Afza" : {scale:[0,4,8,10,14,16,22], modulo:24, name: "Shawq Afza"},
	
	// maqam sikah
	"Sikah" : {scale:[0,3,7,11,14,17,21], modulo:24, name: "Sikah"},
	"Sikah Desc" : {scale:[0,3,7,11,13,17,21], modulo:24, name: "Sikah Descending"},
	"Huzam" : {scale:[0,3,7,9,15,17,21], modulo:24, name: "Huzam"},
	"Iraq" : {scale:[0,3,7,10,13,17,21], modulo:24, name: "Iraq"},
	"Bastanikar" : {scale:[0,3,7,10,13,15,21], modulo:24, name: "Bastanikar"},
	"Mustar" : {scale:[0,5,7,11,13,17,21], modulo:24, name: "Mustar"},
	
	// maqam bayati
	"Bayati" : {scale:[0,3,6,10,14,16,20], modulo:24, name: "Bayati"},
	"Karjighar" : {scale:[0,3,6,10,12,18,20], modulo:24, name: "Karjighar"},
	"Husseini" : {scale:[0,3,6,10,14,17,21], modulo:24, name: "Husseini"},
	
	// maqam nahawand
	"Nahawand" : {scale:[0,4,6,10,14,16,22], modulo:24, name: "Nahawand"},
	"Nahawand Desc" : {scale:[0,4,6,10,14,16,20], modulo:24, name: "Nahawand Descending"},
	"Farahfaza" : {scale:[0,4,6,10,14,16,20], modulo:24, name: "Farahfaza"},
	"Murassah" : {scale:[0,4,6,10,12,18,20], modulo:24, name: "Murassah"},
	"Ushaq Mashri" : {scale:[0,4,6,10,14,17,21], modulo:24, name: "Ushaq Mashri"},
	
	// maqam rast
	"Rast" : {scale:[0,4,7,10,14,18,21], modulo:24, name: "Rast"},
	"Rast Desc" : {scale:[0,4,7,10,14,18,20], modulo:24, name: "Rast Descending"},
	"Suznak" : {scale:[0,4,7,10,14,16,22], modulo:24, name: "Suznak"},
	"Nairuz" : {scale:[0,4,7,10,14,17,20], modulo:24, name: "Nairuz"},
	"Yakah" : {scale:[0,4,7,10,14,18,21], modulo:24, name: "Yakah"},
	"Yakah Desc" : {scale:[0,4,7,10,14,18,20], modulo:24, name: "Yakah Descending"},
	"Mahur" : {scale:[0,4,7,10,14,18,22], modulo:24, name: "Mahur"},
	
	// maqam hijaz
	"Hijaz" : {scale:[0,2,8,10,14,17,20], modulo:24, name: "Hijaz"},
	"Hijaz Desc" : {scale:[0,2,8,10,14,16,20], modulo:24, name: "Hijaz Descending"},
	"Zanjaran" : {scale:[0,2,8,10,14,18,20], modulo:24, name: "Zanjaran"},
	
	// maqam hijazKar
	"HijazKar" : {scale:[0,2,8,10,14,16,22], modulo:24, name: "hijazKar"},
	
	// maqam saba
	"Saba" : {scale:[0,3,6,8,12,16,20], modulo:24, name: "Saba"},
	"Zamzam" : {scale:[0,2,6,8,14,16,20], modulo:24, name: "Zamzam"},
	
	// maqam kurd
	"Kurd" : {scale:[0,2,6,10,14,16,20], modulo:24, name: "Kurd"},
	"Kijaz Kar Kurd" : {scale:[0,2,8,10,14,16,22], modulo:24, name: "Kijaz Kar Kurd"},
	
	// maqam nawa Athar
	"Nawa Athar" : {scale:[0,4,6,12,14,16,22], modulo:24, name: "Nawa Athar"},
	"Nikriz" : {scale:[0,4,6,12,14,18,20], modulo:24, name: "Nikriz"},
	"Athar Kurd" : {scale:[0,2,6,12,14,16,22], modulo:24, name: "Athar Kurd"},


	"Harmonic Series" : {scale:[0,7,12,16,19,21.5,24,26,28,29.5,31,32.5,33.5,35], modulo:36, name: "Harmonic Series"},
};


///////////////////////////////////////////////
// Set parameters
function selectScale(val) {
	scale = val;
	outlet(2, scaleDic[scale].scale);
	outlet(3, scaleDic[scale].modulo);
	printScale();
}

function selectRoot(val) {
	root = val;
	printScale();
}


function printScale() {
	var viewChord = ['chord '];
	var moduloScale = [];

	for(var i=0; i<scaleDic[scale].scale.length; i++) {
		viewChord.push(48 + root + scaleDic[scale].scale[i]);
		viewChord.push(100);
		moduloScale.push((root + scaleDic[scale].scale[i])%scaleDic[scale].modulo);
	};

	outlet(1, viewChord.toString().replace(/,/g, ' '));
	outlet(4, moduloScale.sort(function(a, b){return a - b}));
}

///////////////////////////////////////////////
// midi ON - OFF
function list(note, velocity) {
	var moduloNote = (note-root)%scaleDic[scale].modulo;
	var idx;

	for(var i=0; i<scaleDic[scale].scale.length; i++) {
		if (scaleDic[scale].scale[i] <= moduloNote) {
			idx = i;
		} else {
			break;
		}
	}
	outlet(0, [note-(moduloNote)+scaleDic[scale].scale[idx], velocity]);
}



