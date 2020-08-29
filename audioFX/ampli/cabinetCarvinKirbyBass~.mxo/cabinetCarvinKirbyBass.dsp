declare name "cabinetCarvinKirbyBass";
declare description "Generated by tools/physicalModeling/ir2dsp.py";

import("stdfaust.lib");

pi = 4*atan(1.0);
nModes = 58;

modeFrequencies=(160.753341434,750.182260024,1071.68894289,1232.44228433,1553.94896719,1661.11786148,2036.20899149,2250.54678007,2411.30012151,2572.05346294,2732.80680437,2893.56014581,3000.7290401,3161.48238153,3268.65127582,3375.82017011,3482.9890644,3590.15795869,3750.91130012,3858.08019441,4018.83353584,4393.92466586,4501.09356015,4608.26245443,4715.43134872,4876.18469016,4983.35358445,5144.10692588,5251.27582017,5412.0291616,5519.19805589,5733.53584447,5840.70473876,5947.87363305,6269.38031592,6376.54921021,6537.30255164,6644.47144593,6751.64034022,6912.39368165,7019.56257594,7126.73147023,7287.48481166,7394.65370595,7501.82260024,7662.57594168,7823.32928311,8037.66707169,8573.51154313,8787.84933171,9162.94046173,9323.69380316,10234.6294046,10341.7982989,11306.3183475,11413.4872418,11574.2405832,11681.4094775);
massEigenValues=(1.0,0.238934640147,0.247595767826,0.154233491965,0.292780037218,0.234843687501,0.266255258441,0.34730085397,0.302519344801,0.373856624687,0.226707874154,0.313228067585,0.323845073129,0.263987279044,0.298039636186,0.361182613489,0.327606833058,0.31921353718,0.295800533845,0.239977709644,0.241030768835,0.213038829308,0.243285006899,0.277793977183,0.189947991964,0.154566486743,0.135349888037,0.0916616683491,0.0713864171216,0.0443082157922,0.0266485462222,0.039589065361,0.046114750495,0.0439142906853,0.0632201538299,0.048886662503,0.0389377047574,0.043119838128,0.0424672384615,0.0450488925529,0.0394900451555,0.0407586723926,0.0542467021481,0.0542735712433,0.0400040091257,0.0485654335627,0.0534073292645,0.0564438329905,0.0266889619559,0.0252141732334,0.0324852037603,0.0329659521857,0.0448094385389,0.042984364612,0.0111028120482,0.0122521982915,0.0127631895393,0.0139949517417);
t60=(39.286789534,19.6434339395,23.5721050585,4.91091724377,23.5721050585,19.6434339395,2.94658168457,10.714635942,3.68320751923,11.7860917016,2.87471574949,6.20324326965,6.20324326965,2.94658168457,3.68320751923,16.8372402832,6.20324326965,6.20324326965,3.68320751923,2.87471574949,39.286789534,10.714635942,13.0956487413,58.9301451294,1.84164293279,1.68379453972,1.25390955448,1.20273277054,1.17867968209,1.15556985201,1.13334886156,23.5721050585,29.4651117367,39.286789534,29.4651117367,16.8372402832,11.7860917016,58.9301451294,39.286789534,58.9301451294,4.71448368783,4.71448368783,23.5721050585,23.5721050585,4.71448368783,9.8217561422,10.714635942,10.714635942,3.18548736067,1.59278285363,13.0956487413,13.0956487413,10.714635942,10.714635942,0.519285985476,8.41865931405,9.06624246552,9.8217561422);

modeFreqs=par(i,nModes,ba.take(i+1, modeFrequencies));
modeGains=par(i,nModes,ba.take(i+1, massEigenValues));
modeT60 = par(i,nModes,ba.take(i+1,t60));

cabinetCarvinKirbyBass=modalModel(nModes,modeFrequencies,modeT60,modeGains);

modalModel(n,modeFreqs,modeRes,modeGains) = _ <: par(i,n,gain(i)*pm.modeFilter(freqs(i),res(i))) :> _
with {
	freqs(i) = ba.take(i+1,modeFreqs);
	res(i) = ba.take(i+1,modeRes);
	gain(i) = ba.take(i+1,modeGains);
};


cab = cabinetCarvinKirbyBass;

wetdry = vslider("[2] amount[style:knob]",  1, 0, 1, 0.01);
dry = 1 - wetdry;

process = _ <: _*dry, (_*wetdry:cab) :> _;