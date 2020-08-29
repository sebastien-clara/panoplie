declare name "cabinetOrangeTangerineBass";
declare description "Generated by tools/physicalModeling/ir2dsp.py";

import("stdfaust.lib");

pi = 4*atan(1.0);
nModes = 148;

modeFrequencies=(72.2131250787,83.3228366293,122.206827056,161.090817483,188.86509636,227.749086787,355.510769618,438.833606248,505.491875551,577.70500063,672.13754881,722.131250787,755.460385439,788.789520091,833.228366293,960.990049125,1005.42889533,1122.08086661,1177.62942436,1227.62312634,1338.72024184,1394.2687996,1572.02418441,1610.90817483,1655.34702104,1705.34072301,1733.11500189,1749.77956922,1805.32812697,1855.32182895,1910.8703867,1960.86408868,2010.85779065,2071.96120418,2183.05831969,2249.71658899,2294.15543519,2349.70399295,2383.0331276,2483.02053155,2527.45937776,2588.56279128,2644.11134904,2699.65990679,2732.98904144,2794.09245497,2888.52500315,2960.73812823,3044.06096486,3110.71923416,3177.37750346,3277.36490742,3416.2363018,3466.23000378,3482.8945711,3577.32711928,3616.21110971,3755.08250409,3816.18591762,3871.73447537,3905.06361003,4010.60586976,4077.26413906,4177.25154302,4227.24524499,4371.67149515,4477.21375488,4638.30457236,4677.18856279,4821.61481295,4904.93764958,4949.37649578,4982.70563043,5032.69933241,5077.13817861,5110.46731326,5171.57072679,5227.11928454,5260.4484192,5293.77755385,5349.3261116,5421.53923668,5510.41692908,5577.07519839,5649.28832347,5688.17231389,5704.83688122,5854.81798715,5938.14082378,6021.46366041,6093.67678549,6171.44476634,6221.43846832,6360.3098627,6393.63899735,6532.51039174,6588.05894949,6626.94293992,6671.38178612,6704.71092077,6788.0337574,6854.6920267,6888.02116136,7004.67313264,7065.77654616,7132.43481547,7182.42851745,7276.86106563,7315.74505605,7437.95188311,7460.17130621,7482.39072931,7565.71356594,7721.24952765,8154.52827812,8282.28996095,8365.61279758,8454.49048999,8687.79443255,8748.89784608,8843.33039426,8871.10467313,8926.65323089,8965.53722131,9015.53092329,9054.41491372,9098.85375992,9159.95717345,9215.5057312,9248.83486585,9271.05428895,9315.49313516,9354.37712558,9393.26111601,9421.03539489,9482.13880841,9532.13251039,11054.1629928,11104.1566948,11198.589243,11237.4732334,11270.8023681,11293.0217912,11420.783474,11443.0028971,11592.984003,11731.8553974,11809.6233783);
massEigenValues=(0.119917672778,0.123125463738,0.471865353894,0.480164738818,0.492980812232,0.5330114397,0.707683797515,0.4616843113,0.493383938012,1.0,0.924437789224,0.844288894023,0.522283489539,0.651728086567,0.776153475794,0.510814670129,0.408762187071,0.710615864617,0.333005312171,0.334851227928,0.146135962708,0.257963891937,0.352128183854,0.319688278298,0.467072341492,0.413743173819,0.392886613708,0.38495213033,0.224036208062,0.476586357092,0.0873746064033,0.24768608956,0.291884410548,0.363053448997,0.730009815494,0.685025101001,0.737994897139,0.678078547274,0.674021795687,0.583102643033,0.486675592723,0.401498838664,0.475789580654,0.307849290109,0.267290931175,0.441150374352,0.323268631155,0.403362109164,0.314554804497,0.407397920649,0.334889562539,0.385857592375,0.187011477348,0.120514553706,0.120595871237,0.187884446179,0.170468750826,0.277380497317,0.324011775421,0.34310055981,0.314063176387,0.150328668932,0.166944495729,0.225831088238,0.272368141572,0.198174166292,0.239538995231,0.176705315672,0.207208848573,0.235519228198,0.130456111288,0.188471817534,0.219363183809,0.212699540025,0.179622262408,0.197764067795,0.217235461309,0.156204701335,0.149215160141,0.137128489381,0.118090683324,0.0586116206424,0.125204013492,0.138194615112,0.0768994354429,0.108912042184,0.111641883436,0.120142397882,0.0788150781815,0.131245470097,0.0911342544397,0.100398403895,0.0849566502223,0.0363709322628,0.0324881709855,0.0519457312041,0.0160874896778,0.0309368461525,0.0386022608938,0.0473170526616,0.0421751516284,0.0463077879051,0.0490695720205,0.0215862839244,0.0101955489716,0.0192620411673,0.0147940356029,0.0183359953346,0.0109192539165,0.0142897224175,0.0127477839772,0.0132240897007,0.0140813085112,0.0103153131222,0.0116470744567,0.0110300514837,0.0124531003622,0.0105446982172,0.0218982518762,0.0168242714074,0.0205527029356,0.0205809132849,0.0167642147523,0.0155892870875,0.0173355980323,0.015685051952,0.0172746772752,0.014336165374,0.0106526653215,0.0118210899767,0.0121648441757,0.012923174978,0.0137382339379,0.0149016710786,0.0152644160628,0.0106629145149,0.0113717380614,0.0135297387062,0.0125146329336,0.0125239423395,0.0110871921259,0.0105061114479,0.0105186385344,0.0113791509931,0.012000147128,0.0155334943264,0.0113289171128,0.0114685491428);
t60=(0.0525162535221,0.0525162535221,0.15875398966,0.15875398966,0.15875398966,0.160841826757,0.718785622302,0.15875398966,0.15875398966,1.74551029889,0.610979531587,0.381891589759,0.188047950499,0.200373824908,0.643132225291,0.814613258605,0.147283463044,1.35763653188,0.581888999203,1.11080777118,0.0843406011682,1.74551029889,0.271589989347,0.26568756262,1.35763653188,0.470002336384,0.284218437251,0.277760708206,0.182436918149,1.74551029889,4.07275290229,0.0485626077877,0.0509868168241,0.055363556662,0.182436918149,0.177151163056,0.185199926501,0.177151163056,0.177151163056,0.150918156646,0.117559358926,0.101053767176,0.117559358926,0.0514146184385,0.0505660863164,0.555443060688,0.0514146184385,0.210733934924,0.0514146184385,0.509162668329,0.051631226853,1.01824698596,1.11080777118,0.0429486508916,0.0429486508916,0.555443060688,0.531296769015,0.260036302995,0.313361009441,0.321605289754,0.298078928886,0.190984975253,1.35763653188,0.509162668329,0.610979531587,0.763704826809,0.718785622302,0.643132225291,0.763704826809,0.939926321566,0.110150648586,0.197143252978,0.235040347058,0.222224238814,0.190984975253,0.197143252978,0.226338051331,0.119862907549,0.111151305558,0.110150648586,0.10820246688,0.0978225549736,0.509162668329,0.555443060688,0.581888999203,0.939926321566,0.939926321566,0.763704826809,0.194015238893,0.678857440537,0.407345805406,0.678857440537,0.488799295711,0.763704826809,0.678857440537,0.763704826809,0.113208211565,0.210733934924,0.222224238814,0.718785622302,0.421389510608,0.421389510608,0.436436337622,1.11080777118,0.235040347058,1.11080777118,0.509162668329,1.22188071348,0.24443882647,0.555443060688,0.470002336384,0.509162668329,1.22188071348,1.11080777118,1.11080777118,0.271589989347,0.678857440537,0.271589989347,0.718785622302,0.581888999203,0.203712082574,0.203712082574,0.179755174754,0.174621551698,0.179755174754,0.174621551698,0.179755174754,0.0978225549736,0.0849257553911,0.089916776793,0.0905822463244,0.0912576482394,0.0970468076064,0.260036302995,0.290983677212,0.0849257553911,0.0892610221477,0.222224238814,0.207163501523,0.207163501523,0.169773129941,0.165186785054,0.165186785054,0.147283463044,0.147283463044,0.531296769015,0.147283463044,0.147283463044);

modeFreqs=par(i,nModes,ba.take(i+1, modeFrequencies));
modeGains=par(i,nModes,ba.take(i+1, massEigenValues));
modeT60 = par(i,nModes,ba.take(i+1,t60));

cabinetOrangeTangerineBass=modalModel(nModes,modeFrequencies,modeT60,modeGains);

modalModel(n,modeFreqs,modeRes,modeGains) = _ <: par(i,n,gain(i)*pm.modeFilter(freqs(i),res(i))) :> _
with {
	freqs(i) = ba.take(i+1,modeFreqs);
	res(i) = ba.take(i+1,modeRes);
	gain(i) = ba.take(i+1,modeGains);
};


cab = cabinetOrangeTangerineBass;

wetdry = vslider("[2] amount[style:knob]",  1, 0, 1, 0.01);
dry = 1 - wetdry;

process = _ <: _*dry, (_*wetdry:cab) :> _;
