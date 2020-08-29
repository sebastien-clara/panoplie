declare name 		"panpot";
declare version 	"1.0";
declare author 		"Sébastien Clara";

//-------------------------------------------------
// Stereo panpot
//-------------------------------------------------

panpot(x) 	= sqrt(c)*x, sqrt(1-c)*x
			with {
				c=(hslider("[1]pan[style:knob]",0,-1,1,0.1)-1)/-2;
			};

process		= panpot;
