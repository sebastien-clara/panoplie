declare name "cabinetVoxTopBoostTreble";
declare description "Generated by tools/physicalModeling/ir2dsp.py";

import("stdfaust.lib");

pi = 4*atan(1.0);
nModes = 182;

modeFrequencies=(99.9874039552,127.761682832,166.645673259,255.523365663,344.401058068,499.937019776,616.588991057,655.472981484,733.240962338,788.789520091,872.11235672,922.106058698,1177.62942436,1283.17168409,1349.82995339,1394.2687996,1460.9270689,1477.59163623,1510.92077088,1566.46932863,1583.13389596,1599.79846328,1616.46303061,1638.68245371,1677.56644414,1688.67615569,1755.33442499,1821.99269429,1877.54125205,1938.64466558,1983.08351178,2044.18692531,2110.84519461,2210.83259856,2344.14913717,2399.69769492,2416.36226225,2477.46567578,2505.23995465,2527.45937776,2555.23365663,2677.44048369,2738.54389722,2766.31817609,2827.42158962,2977.40269555,3032.95125331,3132.93865726,3277.36490742,3294.02947474,3349.5780325,3371.7974556,3427.34601335,3449.56543645,3505.11399421,3521.77856153,3605.10139816,3682.86937901,3732.86308099,3816.18591762,3899.50875425,4016.16072553,4071.70928329,4132.81269681,4149.47726414,4321.67779317,4493.87832221,4638.30457236,4710.51769744,4766.0662552,4860.49880338,4910.49250535,4954.93135156,5021.58962086,5088.24789016,5182.68043834,5249.33870765,5338.21640005,5388.21010203,5493.75236176,5543.74606374,5638.17861192,5693.72716967,5804.82428517,5860.37284293,6049.23793929,6138.11563169,6660.27207457,6782.47890162,6832.4726036,6988.00856531,7143.54452702,7154.65423857,7282.4159214,7415.73246001,7560.15871017,7704.58496032,7837.90149893,7871.23063358,7910.11462401,8004.54717219,8154.52827812,8221.18654742,8310.06423983,8448.93563421,8498.92933619,8587.80702859,8732.23327875,8882.21438468,9032.19549062,9093.29890414,9182.17659655,9259.9445774,9271.05428895,9332.15770248,9465.47424109,9476.58395264,9582.12621237,9720.99760675,9837.64957803,9848.75928958,9876.53356846,9982.07582819,10043.1792417,10132.0569341,10198.7152034,10254.2637612,10298.7026074,10448.6837133,10598.6648192,10643.1036654,10781.9750598,10965.2853004,11070.8275601,11193.0343872,11309.6863585,11326.3509258,11381.8994836,11542.990301,11698.5262628,11820.7330898,11959.6044842,12109.5855901,12270.6764076,12426.2123693,12498.4254944,12637.2968888,12648.4066003,12781.7231389,12920.5945333,13059.4659277,13187.2276105,13198.3373221,14675.9289583,14698.1483814,14720.3678045,14792.5809296,14803.6906411,14814.8003527,14842.5746316,14975.8911702,15020.3300164,15053.659151,15070.3237184,15081.4334299,15103.652853,15114.7625646,15136.9819877,15159.2014108,15175.8659781,15192.5305454,15209.1951127,15253.6339589,15264.7436705,15275.853382,15286.9630936,15342.5116513,15353.6213629,15370.2859302,15392.5053533,15997.9846328,16114.6366041);
massEigenValues=(0.0812924670098,0.0797786858989,0.0935597984945,0.236908218373,0.247848795595,0.286535649593,0.214844579162,0.217760815167,0.163084051558,0.238890495504,0.284188785488,0.325300427184,0.301976120408,0.256973780891,0.255597132706,0.283346699178,0.261737826211,0.259847979776,0.251000344196,0.306590819106,0.313307231656,0.313524169238,0.316067942028,0.313482909382,0.340849855624,0.342099738452,0.419790297866,0.4249390581,0.393490236965,0.354261445184,0.424497492895,0.440145429637,0.582055062803,0.5719505083,0.573730719988,0.644736731114,0.641747088177,0.539326788505,0.558656409579,0.563833288425,0.553804552913,0.412609191553,0.356400035685,0.365204368727,0.523577117666,0.405515479179,0.338766685948,0.541820635889,0.994346115716,1.0,0.943961975873,0.949976794661,0.991631368505,0.988898712827,0.92503119641,0.92800638397,0.844667455522,0.638342528389,0.553906633664,0.457652028241,0.555871422983,0.590969362329,0.583102887393,0.51949278213,0.519844619297,0.240897093632,0.400205107903,0.636240750922,0.700201848725,0.685835972433,0.559952328836,0.506909791659,0.47350836386,0.460507038532,0.486801426589,0.435431359777,0.45860982215,0.390831299787,0.38185525252,0.350289223889,0.357024143076,0.27030587906,0.260751740116,0.161731518691,0.150745259236,0.22107865048,0.289496879916,0.0611533599978,0.0617751742988,0.0652211715409,0.0491285422723,0.041062571263,0.0411074952296,0.036202813234,0.0188064256968,0.031883740736,0.0516827006423,0.050635405965,0.0538754885718,0.0514560912426,0.0534934334749,0.0436281764521,0.0357710789089,0.0446535462937,0.0485546813709,0.0431106448476,0.044736087161,0.0411877136759,0.0385941654334,0.0463726798808,0.0442915853377,0.0571198020259,0.0542777611234,0.0542520513986,0.0574168604979,0.0656679587316,0.0654807603593,0.071712871303,0.0598419677359,0.0602454635099,0.0601678376639,0.0599462061509,0.0609206139236,0.0559740635599,0.0524296088177,0.0506377309955,0.0468415747818,0.0463642168491,0.0467146106855,0.0545669544592,0.0524235787644,0.0729643258003,0.110266579875,0.112998632728,0.094243440065,0.0639801187733,0.0639228291021,0.0655919532912,0.072763104288,0.0794744840233,0.068862021056,0.0578276531645,0.0534406596981,0.0384795544393,0.0263982180554,0.0214898117319,0.0300971133443,0.0301623198533,0.036215648905,0.0317552862967,0.0229462964709,0.0123038460731,0.0124616053266,0.0102094417173,0.0104463508058,0.0103903162606,0.0106083064619,0.0110040217052,0.0108839920027,0.0103360711656,0.0103695804881,0.0103792459525,0.0115478836617,0.0115741280558,0.0112711979732,0.0108866683146,0.0108576157819,0.0105975986441,0.0109149068248,0.0112890493305,0.010997486141,0.0113619622001,0.0104317923836,0.0112384173602,0.0105372759086,0.0105793065525,0.0103694136776,0.010489596811,0.0102131405132,0.0102545934485,0.0106803770099,0.0102900885812);
t60=(0.0105751234975,0.0105751234975,0.0106204055935,0.150918156646,0.214429646696,0.226338051331,0.149078647077,0.149078647077,0.0764410194097,0.226338051331,0.407345805406,0.488799295711,0.0218186944235,0.0147989941055,0.0147989941055,0.0211803823377,0.0147989941055,0.0147989941055,0.014763608598,0.0218574469399,0.0218963378587,0.0218963378587,0.0218963378587,0.0218963378587,0.0232625385578,0.0232625385578,0.0640470869761,0.0643837642314,0.0489504812201,0.0249623854887,0.0643837642314,0.070702787926,0.24942577474,0.24443882647,0.239647444806,0.254620512528,0.254620512528,0.235040347058,0.239647444806,0.239647444806,0.235040347058,0.226338051331,0.0249623854887,0.0250641600356,0.555443060688,0.555443060688,0.0232186294343,0.0608645657491,0.156719686852,0.15875398966,0.150918156646,0.150918156646,0.156719686852,0.156719686852,0.150918156646,0.150918156646,0.1328829652,0.0978225549736,0.0611684965187,0.0593891736878,0.0611684965187,0.0617855680864,0.0617855680864,0.0605636441966,0.0605636441966,0.014763608598,0.0577105673004,0.152803653959,0.177151163056,0.172163197002,0.0886147711953,0.0694989631848,0.0679562840982,0.067210373342,0.0687189569013,0.0664806780444,0.067210373342,0.0574399938194,0.0574399938194,0.0522921602287,0.0525162535221,0.0147989941055,0.0147989941055,0.0142854929507,0.0110167803039,0.190984975253,0.298078928886,0.00985297292544,0.00986079855377,0.15875398966,0.00978310169984,0.00960157094947,0.00960157094947,0.939926321566,1.11080777118,0.0137758299947,0.147283463044,0.143819813862,0.150918156646,0.147283463044,0.149078647077,0.0143853069643,0.0140419468179,0.0563826375587,0.169773129941,0.0143685740098,0.0563826375587,0.0143352252521,0.0140899857271,0.0194414038552,0.0144020791524,0.0501522530355,0.0493446106811,0.0493446106811,0.0501522530355,0.0599706517306,0.0596784944693,0.111151305558,0.0509868168241,0.0509868168241,0.0509868168241,0.0509868168241,0.0539022755086,0.0497451487566,0.020578484191,0.0204758133759,0.0194721385346,0.0194414038552,0.0194721385346,0.036333664223,0.020578484191,0.0456680301136,0.150918156646,0.154736885385,0.119862907549,0.0408051404786,0.0408051404786,0.0413555012354,0.0456680301136,0.055363556662,0.0420647290407,0.0393646464966,0.0358036173538,0.0140899857271,0.0122116053245,0.0121397420132,0.142148401762,0.143819813862,0.179755174754,0.149078647077,0.0121636016737,0.011637673677,0.011637673677,0.0582594449382,0.0588188779216,0.0588188779216,0.0602656873902,0.0698956520976,0.0605636441966,0.0585378230727,0.0588188779216,0.0588188779216,0.083194176575,0.083194176575,0.070296900655,0.0605636441966,0.0605636441966,0.0602656873902,0.0605636441966,0.070702787926,0.0698956520976,0.083194176575,0.0588188779216,0.070296900655,0.0602656873902,0.0602656873902,0.0588188779216,0.0588188779216,0.0582594449382,0.0582594449382,0.142148401762,0.114265499704);

modeFreqs=par(i,nModes,ba.take(i+1, modeFrequencies));
modeGains=par(i,nModes,ba.take(i+1, massEigenValues));
modeT60 = par(i,nModes,ba.take(i+1,t60));

cabinetVoxTopBoostTreble=modalModel(nModes,modeFrequencies,modeT60,modeGains);

modalModel(n,modeFreqs,modeRes,modeGains) = _ <: par(i,n,gain(i)*pm.modeFilter(freqs(i),res(i))) :> _
with {
	freqs(i) = ba.take(i+1,modeFreqs);
	res(i) = ba.take(i+1,modeRes);
	gain(i) = ba.take(i+1,modeGains);
};


cab = cabinetVoxTopBoostTreble;

wetdry = vslider("[2] amount[style:knob]",  1, 0, 1, 0.01);
dry = 1 - wetdry;

process = _ <: _*dry, (_*wetdry:cab) :> _;
