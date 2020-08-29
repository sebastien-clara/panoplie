declare name "cabinetAmpegMotown";
declare description "Generated by tools/physicalModeling/ir2dsp.py";

import("stdfaust.lib");

pi = 4*atan(1.0);
nModes = 87;

modeFrequencies=(5.55485577529,72.2131250787,111.097115506,211.084519461,299.962211865,344.401058068,366.620481169,477.717596675,561.040433304,622.143846832,772.124952765,833.228366293,933.215770248,1083.19687618,1183.18428014,1388.71394382,1499.81105933,1560.91447286,1688.67615569,1760.88928077,1883.09610782,1971.97380023,2055.29663686,2105.29033883,2327.48456985,2527.45937776,2616.33707016,2649.66620481,2744.09875299,2794.09245497,2916.29928203,3032.95125331,3094.05466683,3271.81005164,3427.34601335,3577.32711928,3610.65625394,3677.31452324,3710.64365789,3843.9601965,4010.60586976,4038.38014863,4110.59327371,4160.58697569,4305.01322585,4460.54918756,4604.97543771,4727.18226477,4804.95024562,4877.1633707,4949.37649578,5027.14447663,5104.91245749,5160.46101524,5315.99697695,5338.21640005,5421.53923668,5460.42322711,5488.19750598,5565.96548684,5599.29462149,5749.27572742,5810.37914095,5977.02481421,6104.78649704,6165.88991057,6338.0904396,6410.30356468,6526.95553596,6638.05265147,6688.04635345,6754.70462275,6793.58861318,7038.00226729,7065.77654616,7126.87995969,7165.76395012,7326.8547676,7404.62274846,7543.49414284,9398.81597178,9432.14510644,9598.7907797,9748.77188563,10054.2889533,10065.3986648,10082.0632321);
massEigenValues=(0.0115070149161,0.286995254364,0.73161132958,0.299665536897,0.348151307004,0.451744582535,0.458046769946,0.646857693742,0.37108234696,0.772926112706,0.526863013212,0.242346588938,0.552898792521,0.755010709684,1.0,0.712971351281,0.295881627006,0.333239622228,0.603858350087,0.738089898189,0.481197920276,0.698506709971,0.513815680107,0.616690296156,0.519229390471,0.484716412383,0.459421501812,0.472210580341,0.372355658191,0.370386595176,0.320042074463,0.42516881138,0.3519116748,0.183764817916,0.154584656101,0.188929359254,0.198761447063,0.21876484479,0.228721498695,0.166966957034,0.112891282825,0.114407270958,0.116576773406,0.131766239703,0.0741767520569,0.0733995616373,0.0387527779035,0.031626682123,0.0262903210052,0.0422183560419,0.0505842130137,0.0473980022334,0.0231361403914,0.0291508696874,0.0319602263795,0.031673497682,0.0361039215165,0.0365546011466,0.0352450970914,0.0257048281812,0.0257702297668,0.0127727368426,0.0121874681851,0.0191519084168,0.0375948078263,0.0415537217269,0.0339901101379,0.0346587898704,0.0234222550933,0.0376036326082,0.0292265058767,0.0232579350857,0.026292460735,0.0219623963602,0.0218340373738,0.027868127701,0.0290266345047,0.0327061503338,0.0281252201871,0.0222404601527,0.0101496573351,0.0106396413865,0.0105239015661,0.0102158129255,0.0101941839009,0.010177344719,0.0101243905929);
t60=(6.10909018068,0.0861207886704,1.74551029889,0.0861207886704,0.130057335639,0.230607102062,0.230607102062,0.643132225291,0.130057335639,1.11080777118,1.22188071348,0.0843406011682,1.35763653188,0.277760708206,0.330295206849,0.718785622302,0.0947917280661,0.555443060688,0.470002336384,0.555443060688,0.207163501523,0.718785622302,0.21825734818,0.321605289754,0.452597744427,0.313361009441,0.298078928886,0.313361009441,0.169773129941,0.169773129941,0.210733934924,0.407345805406,0.226338051331,0.0281014077532,0.643132225291,0.179755174754,0.190984975253,0.277760708206,0.298078928886,0.162985339515,0.0826325834499,0.0986108143979,0.0986108143979,0.101053767176,0.070296900655,0.531296769015,0.0147812800606,0.581888999203,0.0719491006169,0.290983677212,0.313361009441,0.305528943153,0.0715288041324,0.130057335639,0.254620512528,0.24942577474,0.452597744427,0.470002336384,0.277760708206,0.0719491006169,0.0719491006169,0.872794323539,0.678857440537,1.01824698596,0.581888999203,0.610979531587,0.394208145712,0.407345805406,0.188047950499,0.531296769015,0.24942577474,0.188047950499,0.197143252978,0.116440492457,0.116440492457,0.143819813862,0.145531021491,0.581888999203,0.143819813862,0.116440492457,0.150918156646,0.154736885385,0.154736885385,0.150918156646,0.160841826757,0.160841826757,0.15875398966);

modeFreqs=par(i,nModes,ba.take(i+1, modeFrequencies));
modeGains=par(i,nModes,ba.take(i+1, massEigenValues));
modeT60 = par(i,nModes,ba.take(i+1,t60));

cabinetAmpegMotown=modalModel(nModes,modeFrequencies,modeT60,modeGains);

modalModel(n,modeFreqs,modeRes,modeGains) = _ <: par(i,n,gain(i)*pm.modeFilter(freqs(i),res(i))) :> _
with {
	freqs(i) = ba.take(i+1,modeFreqs);
	res(i) = ba.take(i+1,modeRes);
	gain(i) = ba.take(i+1,modeGains);
};


cab = cabinetAmpegMotown;

wetdry = vslider("[2] amount[style:knob]",  1, 0, 1, 0.01);
dry = 1 - wetdry;

process = _ <: _*dry, (_*wetdry:cab) :> _;
