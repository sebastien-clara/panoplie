declare name "cabinetMarshallSterlingBass";
declare description "Generated by tools/physicalModeling/ir2dsp.py";

import("stdfaust.lib");

pi = 4*atan(1.0);
nModes = 109;

modeFrequencies=(131.838565022,417.488789238,637.219730942,681.165919283,725.112107623,834.977578475,1032.73542601,1120.62780269,1186.5470852,1230.49327354,1406.27802691,1516.14349776,1604.03587444,1691.92825112,1845.73991031,1955.60538117,2021.52466368,2109.41704036,2219.28251121,2307.17488789,2460.98654709,2548.87892377,2592.82511211,2702.69058296,2812.55605381,2988.34080717,3076.23318386,3142.15246637,3339.9103139,3383.85650224,3449.77578475,3581.61434978,3625.56053812,3669.50672646,3757.39910314,3845.29147982,3889.23766816,3955.15695067,3999.10313901,4108.96860987,4218.83408072,4328.69955157,4416.59192825,4504.48430493,4548.43049327,4636.32286996,4812.10762332,4900.0,5031.83856502,5185.65022422,5339.46188341,5537.21973094,5603.13901345,5669.05829596,5734.97757848,5866.8161435,5954.70852018,6042.60089686,6130.49327354,6174.43946188,6218.38565022,6262.33183857,6306.27802691,6394.17040359,6482.06278027,6547.98206278,6723.76681614,6811.65919283,6855.60538117,6965.47085202,7053.3632287,7141.25560538,7185.20179372,7229.14798206,7273.0941704,7382.95964126,7514.79820628,7602.69058296,7646.6367713,7778.47533632,7998.20627803,8064.12556054,8217.93721973,8305.82959641,8371.74887892,8547.53363229,8657.39910314,8701.34529148,8745.29147982,8789.23766816,8877.13004484,8921.07623318,9030.94170404,9096.86098655,9162.78026906,9228.69955157,9360.53811659,9426.4573991,10964.573991,11096.4125561,11184.3049327,11250.2242152,11338.1165919,11426.0089686,11469.955157,11513.9013453,11645.7399103,11799.5515695,11887.4439462);
massEigenValues=(1.0,0.226813437687,0.379482546432,0.356379343802,0.324869930141,0.231489469059,0.198885642377,0.154593353735,0.168669519442,0.176646004834,0.155074732044,0.118152989725,0.1424125851,0.162443369801,0.177585893457,0.175162671468,0.112866852774,0.227300172666,0.285262189763,0.381698227462,0.416597238873,0.465550658349,0.46515600702,0.396396342627,0.352809396004,0.333389978345,0.392812348766,0.371319244162,0.409175924236,0.417315948659,0.414163682535,0.33270024953,0.346150409966,0.304768089966,0.267954380472,0.324434004907,0.334639489167,0.319551617025,0.30000906121,0.287477939713,0.35290027498,0.359589509523,0.281987494308,0.228453486837,0.240051527989,0.207775535961,0.114607793745,0.112366358115,0.172109803198,0.249001223211,0.314835650235,0.176532728274,0.193965252025,0.196006199318,0.182124389079,0.155148764659,0.113591620681,0.0580262251343,0.0413999533599,0.0530047247431,0.0545897843166,0.0776453644616,0.0820598668285,0.0933575555374,0.106050868001,0.0918437449915,0.0694800635784,0.0549624108263,0.0566001436712,0.0496382471281,0.0396924421202,0.0374029534587,0.0356907092923,0.0347907055498,0.0307435797961,0.0271747545298,0.0312639265819,0.0292487427,0.0305933338626,0.0244674016707,0.0263185974454,0.0271496022126,0.023867038789,0.0216875069977,0.0204161044061,0.0254564655078,0.0201496505461,0.0202956340624,0.0192098056674,0.0187959215262,0.0191712190347,0.0184916625608,0.0156023288717,0.0142246727435,0.0144037207965,0.012763763779,0.0118829019207,0.0122878295605,0.0118440848897,0.0131614652869,0.0137466524532,0.014613008671,0.0139362669363,0.0126161820423,0.0121476432447,0.0119979193547,0.0119279476973,0.0144859134548,0.0154691568476);
t60=(24.1652228208,2.30152067661,6.04136446401,5.37011045083,5.37011045083,3.45224184184,12.0826505829,2.68509439832,9.66613613531,8.0551265036,9.66613613531,0.221776927074,0.322280277368,4.02760242451,5.37011045083,5.37011045083,0.221776927074,0.39950222543,0.420341731731,1.6666400339,1.79008904774,2.41659279312,2.41659279312,1.79008904774,0.710817890962,0.562058452405,1.34258637264,1.23931652458,1.38094374478,1.42155743293,1.38094374478,0.562058452405,0.58947211585,0.431598786484,0.416718771582,0.456024471347,0.562058452405,0.447581024725,0.431598786484,0.420341731731,2.68509439832,2.68509439832,0.420341731731,0.39950222543,0.402830757684,0.396228259278,0.221776927074,0.947731071379,1.15079951197,2.543777764,4.39374097713,1.15079951197,1.15079951197,1.15079951197,1.15079951197,1.12403855468,0.947731071379,0.176466272154,0.146533779708,1.09849400453,1.09849400453,1.93328990381,1.93328990381,3.45224184184,3.71779287999,3.45224184184,1.42155743293,1.09849400453,1.15079951197,1.07408476773,0.146091316242,0.14565151822,0.138560562746,0.138164899351,0.135837598371,0.123685238338,0.136220018719,0.128275413554,0.135837598371,0.118826000603,0.123685238338,0.123685238338,0.118826000603,0.0593066744992,0.0585896253428,0.123685238338,0.0585896253428,0.0585896253428,0.0585896253428,0.0585896253428,0.0585896253428,0.0585896253428,0.0573417559357,0.0561460017561,0.0561460017561,0.056016215682,0.056016215682,0.056016215682,0.743621254377,0.792378166139,0.84797815326,0.84797815326,0.84797815326,0.767225791021,0.743621254377,0.743621254377,0.743621254377,0.84797815326,1.85893561316);

modeFreqs=par(i,nModes,ba.take(i+1, modeFrequencies));
modeGains=par(i,nModes,ba.take(i+1, massEigenValues));
modeT60 = par(i,nModes,ba.take(i+1,t60));

cabinetMarshallSterlingBass=modalModel(nModes,modeFrequencies,modeT60,modeGains);

modalModel(n,modeFreqs,modeRes,modeGains) = _ <: par(i,n,gain(i)*pm.modeFilter(freqs(i),res(i))) :> _
with {
	freqs(i) = ba.take(i+1,modeFreqs);
	res(i) = ba.take(i+1,modeRes);
	gain(i) = ba.take(i+1,modeGains);
};


cab = cabinetMarshallSterlingBass;

wetdry = vslider("[2] amount[style:knob]",  1, 0, 1, 0.01);
dry = 1 - wetdry;

process = _ <: _*dry, (_*wetdry:cab) :> _;
