declare name        "Tube Screamer";
declare category    "Distortion";
declare description "Based on a circuit diagram of the Ibanez TS-9 and a mathematical analysis published by Tamás Kenéz";


import("stdfaust.lib");


smoothi(c) = *(1-c) : +~*(c);

process = ts9nonlin : lowpassfilter : *(gain) with {

    R1 = 4700;
    R2 = 51000 + 500000 * vslider("drive[name:Drive][style:knob]", 0.5, 0, 1, 0.01);
    C = 0.047 * 1e-6;
    a1 = (R1 + R2) * C * 2 * ma.SR;
    a2 = R1 * C * 2 * ma.SR;
    B0 = (1 + a1) / (1 + a2);
    B1 = (1 - a1) / (1 + a2);
    A1 = (1 - a2) / (1 + a2);
    X2 = fi.tf1(B0, B1, A1);

    ts9nonlin = _ <: _ ,(X2,_ : - : ts9comp) : - :> _;
    
    fc = vslider("tone[log][name:Tone][style:knob]", 400, 100, 1000, 1.03);
    lowpassfilter = fi.lowpass(1,fc);
    gain = vslider("level[name:Level][style:knob]", -16, -20, 4, 0.1) : ba.db2linear : smoothi(0.999);
};


/****************************************************************************************/

//-- Rdtable from waveform
rtable(table, r) = (table, int(r)):rdtable;

// Change sign of input signal x;
inverse(x) = abs(x) * invsign(x);

//function that takes f value and x sign
ccopysign(f, x) = abs(f)*sign(x);       

//-- Get sign and reversed sign of a signal x
sign (x) = x<0, 1, -1 : select2;  
invsign (x) = x<0, -1, 1 : select2;

//-- Interpolate value between i and i+1 in table with coefficient f.
interpolation (table, f, i) = rtable(table, i)*(1-f) + rtable(table,i+1)*f;

//-- Bound Index with table boundaries
boundIndex(size, index) = index : floor: min(size-1) : max(0);

//-- Bound factor of interpolation : factor-index if still in the table boundaries, 0 otherwise
boundFactor(size, factor, index) = 0<index<size-1, factor - index, 0 : select2;  


/****************************************************************************************
 * 1-dimensional function tables for nonlinear interpolation
****************************************************************************************/
nonlininterpolation(table, low, high, step, size, x) = ts9(low, step, size, table, x) , inverse(x) : ccopysign;

//-- Interpolate value from table
ts9 (low, step, size, table, x) = interpolation(
	table, 
	getCoef(low, step, size, x), 
	nonlinindex(low, step, x) : boundIndex(size)
);

//-- Calculate non linear index
nonlinindex(low, step, x) = (abs(x)/(3.0 + abs(x)) - low) * step;

//--Get interpolation factor
getCoef(low, step, size, x) = boundFactor(size, nonlinindex(low, step, x), nonlinindex(low, step, x) : boundIndex(size));



/********* Faust Version of ts9nonlin.cc, generated by tools/ts9sim.py ****************/

ts9comp = nonlininterpolation(ts9table, low, high, step, size) with{

// Characteristics of the wavetable
	low = 0.0;
	high = 0.970874;
	step = 101.97;
	size = 100;
	
	ts9table = waveform{0.0,-0.0296990148227,-0.0599780676992,-0.0908231643281,-0.122163239629,
		-0.15376009788,-0.184938007182,-0.214177260107,-0.239335434213,-0.259232575019,
		-0.274433909887,-0.286183308354,-0.29553854444,-0.303222323477,-0.309706249977,
		-0.315301338712,-0.320218440785,-0.324604982281,-0.328567120703,-0.332183356975,
		-0.335513124719,-0.33860236542,-0.34148724693,-0.344196707008,-0.346754233717,
		-0.34917913798,-0.351487480543,-0.35369275887,-0.355806424152,-0.357838275995,
		-0.359796767655,-0.361689244919,-0.363522135105,-0.365301098113,-0.367031148289,
		-0.368716753588,-0.370361916943,-0.371970243537,-0.373544996828,-0.375089145544,
		-0.376605403346,-0.378096262548,-0.379564022938,-0.381010816596,-0.382438629377,
		-0.383849319643,-0.385244634694,-0.386626225283,-0.387995658543,-0.389354429565,
		-0.39070397188,-0.392045667012,-0.393380853288,-0.39471083403,-0.396036885269,
		-0.397360263098,-0.398682210753,-0.400003965547,-0.401326765733,-0.402651857394,
		-0.403980501471,-0.405313980999,-0.406653608692,-0.40800073496,-0.409356756504,
		-0.410723125631,-0.412101360439,-0.413493056085,-0.414899897347,-0.416323672745,
		-0.417766290556,-0.419229797097,-0.420716397759,-0.422228481377,-0.423768648654,
		-0.425339745558,-0.426944902828,-0.428587583057,-0.430271637224,-0.432001373102,
		-0.433781638746,-0.435617925286,-0.437516494692,-0.439484540257,-0.441530390423,
		-0.443663770898,-0.445896146322,-0.448241172434,-0.450715304661,-0.453338632988,
		-0.45613605235,-0.45913894467,-0.46238766699,-0.465935359011,-0.469854010456,
		-0.474244617411,-0.479255257451,-0.48511588606,-0.492212726244,-0.501272723631
	};
};