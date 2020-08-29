declare name "cabinetMarshallMG15";
declare description "Generated by tools/physicalModeling/ir2dsp.py";

import("stdfaust.lib");

pi = 4*atan(1.0);
nModes = 11;

modeFrequencies=(158.029115342,286.427771557,424.70324748,543.225083987,671.623740202,958.051511758,1708.68980963,2133.39305711,4227.27883539,7605.15117581,7733.54983203);
massEigenValues=(0.611078749629,0.34789209721,0.171554261056,0.204626822018,0.214611556888,0.226790750267,1.0,0.559425912064,0.390642188356,0.0132517118767,0.0119132128807);
t60=(4.34493343704,3.62079092182,0.0409134990214,0.0441438585647,0.0454317832264,0.0508360379224,0.80468114201,0.217321108684,0.157500643606,0.0269982167817,0.0265069810392);

modeFreqs=par(i,nModes,ba.take(i+1, modeFrequencies));
modeGains=par(i,nModes,ba.take(i+1, massEigenValues));
modeT60 = par(i,nModes,ba.take(i+1,t60));

cabinetMarshallMG15=modalModel(nModes,modeFrequencies,modeT60,modeGains);

modalModel(n,modeFreqs,modeRes,modeGains) = _ <: par(i,n,gain(i)*pm.modeFilter(freqs(i),res(i))) :> _
with {
	freqs(i) = ba.take(i+1,modeFreqs);
	res(i) = ba.take(i+1,modeRes);
	gain(i) = ba.take(i+1,modeGains);
};


cab = cabinetMarshallMG15;

wetdry = vslider("[2] amount[style:knob]",  1, 0, 1, 0.01);
dry = 1 - wetdry;

process = _ <: _*dry, (_*wetdry:cab) :> _;
