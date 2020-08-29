declare name 		"dryWet";
declare version 	"1.0";
declare author 		"Sébastien Clara";


dryWet(x, y) = sqrt(c)*x, sqrt(1-c)*y <: +, _, _
with {
	c=(hslider("[1]Dry-Wet[style:knob]",0,-1,1,0.1)-1)/-2;
};

process	= dryWet;
