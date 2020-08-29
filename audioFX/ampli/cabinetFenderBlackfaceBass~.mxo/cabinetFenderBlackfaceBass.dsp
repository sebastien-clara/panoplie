declare name "cabinetFenderBlackfaceBass";
declare description "Generated by tools/physicalModeling/ir2dsp.py";

import("stdfaust.lib");

pi = 4*atan(1.0);
nModes = 339;

modeFrequencies=(105.54225973,133.316538607,177.755384809,238.858798337,272.187932989,305.517067641,333.291346517,444.388462023,605.479279506,649.918125709,716.576395012,749.905529664,849.892933619,872.11235672,883.222068271,916.551202922,994.319183776,1016.53860688,1027.64831843,1077.64202041,1099.86144351,1138.74543393,1149.85514548,1205.40370324,1294.28139564,1305.39110719,1399.82365537,1433.15279002,1444.26250157,1549.8047613,1622.01788638,1655.34702104,1738.66985766,1794.21841542,1833.10240584,1871.98639627,1933.0898098,2021.9675022,2105.29033883,2144.17432926,2216.38745434,2249.71658899,2310.82000252,2449.6913969,2538.56908931,2594.11764706,2710.76961834,2738.54389722,2771.87303187,2805.20216652,2932.96384935,2994.06726288,3060.72553218,3088.49981106,3110.71923416,3205.15178234,3277.36490742,3321.80375362,3394.0168787,3427.34601335,3477.33971533,3527.33341731,3627.32082126,3660.64995591,3727.30822522,3788.41163875,3860.62476382,3949.50245623,4005.05101398,4082.81899484,4227.24524499,4371.67149515,4516.09774531,4671.63370702,4810.5051014,4943.82164001,5049.36389974,5093.80274594,5315.99697695,5382.65524625,5499.30721753,5538.19120796,5671.50774657,5782.60486207,5804.82428517,5893.70197758,6049.23793929,6193.66418944,6338.0904396,6438.07784356,6482.51668976,6621.38808414,6760.25947852,6910.24058446,7010.22798841,7115.77024814,7160.20909434,7254.64164252,7287.97077718,7393.51303691,7515.71986396,7643.48154679,7804.57236428,7921.22433556,8060.09572994,8187.85741277,8337.83851871,8371.16765336,8460.04534576,8526.70361506,8604.47159592,8676.684721,8754.45270185,8865.54981736,8898.87895201,8982.20178864,9026.64063484,9065.52462527,9204.39601965,9326.60284671,9476.58395264,9576.57135659,9732.1073183,9759.88159718,9859.86900113,9893.19813579,9993.18553974,10137.6117899,10165.3860688,10237.5991939,10270.9283285,10387.5802998,10432.019146,10504.2322711,10559.7808288,10670.8779443,10681.9876559,10704.207079,10776.4202041,10865.2978965,10904.1818869,10915.2915984,10931.9561658,11015.2790024,11109.7115506,11165.2601083,11204.1440988,11220.8086661,11276.3572238,11298.5766469,11359.6800605,11470.777176,11565.2097241,11604.0937146,11670.7519839,12020.7078977,12065.1467439,12131.8050132,12198.4632825,12254.0118403,12326.2249654,12337.3346769,12365.1089558,12426.2123693,12470.6512155,12503.9803502,12526.1997733,12553.9740521,12565.0837637,12926.1493891,12965.0333795,13098.3499181,13109.4596297,13120.5693412,13231.6664567,13348.318428,13403.8669858,13437.1961204,13448.305832,13459.4155435,13481.6349666,13520.518957,13626.0612168,13637.1709283,13653.8354957,13681.6097745,13737.1583323,13759.3777554,13787.1520343,13803.8166016,13820.4811689,13831.5908805,13848.2554478,13876.0297267,13898.2491498,13909.3588613,13926.0234286,13970.4622748,13981.5719864,14003.7914095,14042.6753999,14059.3399673,14070.4496788,14087.1142461,14103.7788135,14114.888525,14175.9919385,14203.7662174,14253.7599194,14275.9793425,14292.6439098,14303.7536214,14320.4181887,14337.082756,14353.7473233,14375.9667464,14392.6313138,14409.2958811,14420.4055926,14431.5153042,14448.1798715,14470.3992946,14487.0638619,14525.9478524,14542.6124197,14553.7221313,14614.8255448,14631.4901121,14642.5998237,14698.1483814,15120.3174203,15131.4271319,15142.5368434,15159.2014108,15170.3111223,15181.4208339,15198.0854012,15225.8596801,15242.5242474,15253.6339589,15275.853382,15286.9630936,15298.0728051,15309.1825167,15331.4019398,15348.0665071,15370.2859302,15392.5053533,15403.6150649,15431.3893437,15442.4990553,15453.6087668,15470.2733342,15481.3830457,15498.047613,15520.2670362,15542.4864593,15553.5961708,15570.2607381,15592.4801612,15609.1447286,15620.2544401,15642.4738632,15659.1384305,15670.2481421,15686.9127094,15698.022421,15714.6869883,15731.3515556,15742.4612672,15753.5709787,15770.235546,15792.4549691,15803.5646807,15825.7841038,15853.5583827,15892.4423731,15903.5520846,15920.216652,15942.4360751,15964.6554982,15981.3200655,15992.4297771,16009.0943444,16031.3137675,16059.0880464,16075.7526137,16097.9720368,16114.6366041,16125.7463157,16136.8560272,16159.0754503,16175.7400176,16197.9594407,16214.6240081,16231.2885754,16242.3982869,16259.0628543,16297.9468447,16314.611412,16325.7211236,16359.0502582,16370.1599698,16386.8245371,16403.4891044,16420.1536717,16436.8182391,16459.0376622,16481.2570853,16497.9216526,16514.5862199,16531.2507873,16542.3604988,16553.4702104,16564.5799219,16581.2444892,16597.9090566,16609.0187681,16636.793047,16653.4576143,16664.5673259,16686.786749,16697.8964605,16720.1158836,16731.2255952,16753.4450183,16764.5547298,16775.6644414,16786.7741529,16797.8838645,16808.993576,16825.6581433,16847.8775664,16858.987278,16870.0969895,16886.7615569,16897.8712684,16908.98098,16981.1941051);
massEigenValues=(0.251884383454,0.294567788702,0.328902239188,0.277600242129,0.495164069944,0.583437401672,0.59626964227,0.570567149844,0.402229847493,0.320903876808,0.482758623127,0.474255240471,0.321743640066,0.311205842687,0.311231083228,0.305414196961,0.479935452885,0.508533143287,0.508946873752,0.390036757192,0.408482908293,0.393751032511,0.390418675256,0.382884012012,0.338475433806,0.34569364806,0.272337609584,0.279885273954,0.280542631443,0.192409798331,0.211092474954,0.238430906684,0.37159896749,0.326914484105,0.30257050615,0.32598127092,0.352840190561,0.505793026154,0.517401280483,0.557356749919,0.318553188232,0.334196155602,0.40290576278,0.694539963402,0.445604844255,0.611188511752,0.520323054774,0.537451590799,0.571500639381,0.609160845902,0.666288654402,0.689964000419,0.800240482855,0.786339611351,0.783536469207,0.642096930163,0.501913641277,0.515054259497,0.356341490527,0.429109073285,0.353789762053,0.322860541516,0.344269516159,0.355801900655,0.321857685091,0.291073916297,0.375019786604,0.403438929843,0.372570478113,0.535656279252,0.466396651847,0.604673996637,0.664997861355,0.632305483601,0.939805145314,1.0,0.868615461936,0.913701811742,0.365295854283,0.394603716177,0.387563055625,0.404884451627,0.486334548931,0.485185072099,0.485323669127,0.462265514295,0.260745876049,0.223428959895,0.185381184974,0.130173344413,0.138031724927,0.123137331499,0.165234365215,0.197981108328,0.180402732321,0.121604778297,0.13062524891,0.125266540585,0.137101909661,0.184833493104,0.177807593644,0.133758982263,0.123192755738,0.177447625212,0.216324219714,0.208516061021,0.178241844954,0.182989057712,0.182122289773,0.164855112389,0.177979903462,0.189797081555,0.212037032005,0.199658504417,0.196307237154,0.184730360835,0.187771866804,0.19011907562,0.171781053277,0.14070391233,0.111393669352,0.0957438805606,0.0890744024419,0.088431392903,0.0943511461388,0.0890726725291,0.0906405626903,0.07551000981,0.0763719108976,0.0574375995824,0.0624160287147,0.0455830780641,0.0481960684534,0.0326798470717,0.0355224575781,0.0335277793191,0.0332497053317,0.0328796679898,0.0333454756237,0.0273648722434,0.0290107702339,0.0291741414218,0.0296975514339,0.035090276592,0.0320253515549,0.0345915994975,0.0308779738891,0.0309164411147,0.0278897571447,0.0286431496332,0.0256569927043,0.021689937925,0.0142986016289,0.0151018507543,0.0101502606496,0.0121241606261,0.0111874821307,0.0137725337551,0.0130914794142,0.0161429524991,0.0125876114868,0.0127481902849,0.0131979581826,0.0116890588587,0.0113234411282,0.0123474668689,0.0120320200027,0.0112709812022,0.0111068783251,0.0132357902645,0.0126592523483,0.0180235327664,0.017897904189,0.0177964880294,0.0228914031149,0.0239498527178,0.0226496985848,0.0215751820325,0.0211211269592,0.0210482932229,0.0211420940936,0.0216844592187,0.0179202384007,0.0179248265187,0.0177621487747,0.0170020515742,0.0155858300598,0.0160301877495,0.0164787703757,0.0167577505637,0.0168241769159,0.0169122081219,0.017037451388,0.0167392915038,0.0169192424427,0.0172505869785,0.0172536880198,0.01891240391,0.0189387437642,0.0186626704732,0.0204447231386,0.0208649617548,0.0211277211662,0.0212065650606,0.0208788886191,0.0207853745511,0.0224288172927,0.0225802487303,0.0227344040724,0.023272934158,0.0234351743579,0.0234662975358,0.0233736826728,0.0226100100317,0.0228501870322,0.0221845424313,0.0215450023251,0.0209272300856,0.0206269383624,0.0209234868044,0.020808061482,0.0202538950315,0.020184360172,0.0190611902563,0.0187339741907,0.0185416402231,0.0158506898399,0.0153645858652,0.01465136563,0.0105800462305,0.0117475211655,0.0119236208741,0.0125216842409,0.0125824519933,0.0135344750087,0.0132568712822,0.0135541135392,0.0144643230657,0.0150947590249,0.0161992758634,0.0166866876013,0.0165291188525,0.0164441188448,0.0157456035506,0.0154973510005,0.0154432786092,0.0157596273982,0.0159054224135,0.01572143707,0.0158348583879,0.0151884466934,0.0149829303458,0.0153246129541,0.0152159562681,0.0153535548837,0.0152104156713,0.0144848023149,0.0144696339222,0.0147598621256,0.0142242894457,0.0146558101822,0.014039100556,0.0134102334966,0.0131088886169,0.0134126608149,0.0132655208793,0.0130011203051,0.0136077481738,0.0136233599321,0.0134878283736,0.0135235347974,0.0130051630991,0.0134427722488,0.0130874312888,0.0133885467452,0.012903353587,0.013457359205,0.0130721668525,0.0121617540955,0.0128669266092,0.0127348100147,0.0125758673751,0.0120287666373,0.0115798595577,0.0118577792112,0.0112681762453,0.0125419624114,0.0118251893348,0.0119449042275,0.011557513175,0.010860442457,0.0113832849399,0.0112927149497,0.0114252876879,0.0116810602221,0.011235842151,0.0107353941681,0.0107122025127,0.0117499828155,0.0116225541834,0.01168821123,0.0108307813129,0.011131642282,0.0113311867587,0.0110011006306,0.0109434823074,0.0118426355832,0.0119476543998,0.0117035194038,0.0122546794833,0.01278888324,0.0124176731145,0.0128854766489,0.0131141511341,0.0125130715718,0.0127470458895,0.0128515541651,0.0124066512342,0.0132758113319,0.0124865562256,0.0137948430007,0.0130875925269,0.012710525322,0.0127215846077,0.012740460728,0.0128817867037,0.0121653961346,0.011913796418,0.0120453475754,0.0117655110959,0.0124500276586,0.0113977364963,0.0116210008226,0.0120623190717,0.0106162005839,0.0111794127801,0.0100456029557,0.0103952717017,0.0102168121494);
t60=(0.0994118910513,0.0994118910513,0.610979531587,0.0994118910513,0.277760708206,0.298078928886,0.298078928886,0.290983677212,0.313361009441,0.12225859813,0.678857440537,0.678857440537,0.102750832425,0.101895228693,0.101895228693,0.101053767176,0.305528943153,0.330295206849,0.330295206849,0.160841826757,0.194015238893,0.190984975253,0.160841826757,0.1328829652,0.103620937917,0.10450591701,0.0970468076064,0.0986108143979,0.0986108143979,0.0867310184335,0.015033222817,0.015088338069,0.0329225566183,0.0305472987813,0.0156428374875,0.0305472987813,0.0307769632561,0.330295206849,0.330295206849,0.349164741141,0.0301720670206,0.0306234708313,0.0596784944693,0.610979531587,0.0668435319893,0.643132225291,0.0994118910513,0.100226100112,0.101053767176,0.394208145712,0.150918156646,0.165186785054,0.197143252978,0.194015238893,0.194015238893,0.147283463044,0.0986108143979,0.0994118910513,0.0307769632561,0.555443060688,0.0307769632561,0.0305472987813,0.0306234708313,0.0307769632561,0.0305472987813,0.0155443297085,0.555443060688,0.290983677212,0.277760708206,0.939926321566,0.718785622302,0.763704826809,0.678857440537,0.106322048027,0.167448544174,0.174621551698,0.15875398966,0.165186785054,0.0381407774625,0.0556148527445,0.124752072014,0.126037367835,0.169773129941,0.169773129941,0.169773129941,0.1328829652,0.0151253078254,0.763704826809,0.581888999203,0.0119062269167,0.0119176877079,0.718785622302,0.763704826809,0.610979531587,0.284218437251,0.135834178312,0.13891953749,0.143819813862,0.145531021491,0.290983677212,0.284218437251,0.145531021491,0.038621059178,0.0453303294073,0.0536662059707,0.0497451487566,0.0453303294073,0.0456680301136,0.0456680301136,0.044833055849,0.0453303294073,0.047992205691,0.053200225235,0.0491467545253,0.0489504812201,0.0456680301136,0.0458387776637,0.047992205691,0.0451633482481,0.0435589030118,0.0380225714838,0.0228308064216,0.0227044048583,0.0227044048583,0.0227885159351,0.0227044048583,0.0227463823712,0.00667942376281,0.00667942376281,0.00659841497267,0.00660538018958,0.0065227674736,0.00658799497982,0.00606204785872,0.00650244007038,0.00606791356426,0.00606497927444,0.00606497927444,0.00606497927444,0.00600401666599,0.00600976907547,0.00600976907547,0.00603869949587,0.00607379078313,0.00605911931288,0.00607085073241,0.00604451948475,0.00604451948475,0.00600689147511,0.00600689147511,0.00599254526084,0.00598397081689,0.00592743726125,0.00593023821582,0.00589680283146,0.0970468076064,0.0955316760376,0.106322048027,0.0994118910513,0.185199926501,0.0978225549736,0.0986108143979,0.102750832425,0.0970468076064,0.0962832767358,0.0978225549736,0.0970468076064,0.0955316760376,0.0955316760376,0.0362264002984,0.0358036173538,0.0404019058763,0.0404019058763,0.0402692629172,0.10450591701,0.127349440656,0.103620937917,0.0427987550503,0.0426499037805,0.0426499037805,0.0426499037805,0.0427987550503,0.0404019058763,0.0404019058763,0.0401374897492,0.0383794127328,0.0379050974318,0.0379050974318,0.0381407774625,0.0382597222295,0.0382597222295,0.0382597222295,0.0383794127328,0.0382597222295,0.0383794127328,0.0384998560076,0.0384998560076,0.0413555012354,0.0413555012354,0.0412165212447,0.042209509341,0.0426499037805,0.0426499037805,0.0426499037805,0.0426499037805,0.0426499037805,0.0809924340054,0.0809924340054,0.0809924340054,0.0947917280661,0.0955316760376,0.0955316760376,0.0955316760376,0.0809924340054,0.0815318609316,0.0789043297965,0.0427987550503,0.0426499037805,0.042209509341,0.0426499037805,0.0426499037805,0.042209509341,0.0420647290407,0.0414954234646,0.0412165212447,0.0409413501626,0.0379050974318,0.0376723180826,0.0373284717649,0.0338298518956,0.0338298518956,0.0343986954966,0.0360137653449,0.0360137653449,0.0381407774625,0.0376723180826,0.0381407774625,0.0637139167773,0.0694989631848,0.0779001777853,0.0861207886704,0.0789043297965,0.0789043297965,0.0723743710262,0.0723743710262,0.0723743710262,0.0723743710262,0.0754982710046,0.0723743710262,0.0754982710046,0.0723743710262,0.0694989631848,0.0723743710262,0.0723743710262,0.0723743710262,0.0723743710262,0.0637139167773,0.0637139167773,0.0643837642314,0.0582594449382,0.0640470869761,0.0582594449382,0.0376723180826,0.0376723180826,0.0376723180826,0.0376723180826,0.0376723180826,0.0381407774625,0.0381407774625,0.0381407774625,0.0381407774625,0.0376723180826,0.0381407774625,0.0376723180826,0.0376723180826,0.0366593097966,0.0381407774625,0.0376723180826,0.0343986954966,0.0366593097966,0.0362264002984,0.0360137653449,0.0343986954966,0.0338298518956,0.0338298518956,0.0338298518956,0.0360137653449,0.0338298518956,0.0343986954966,0.0338298518956,0.03337002376,0.0338298518956,0.0338298518956,0.0338298518956,0.0338298518956,0.0338298518956,0.0329225566183,0.0329225566183,0.0338298518956,0.0338298518956,0.0338298518956,0.03337002376,0.0338298518956,0.0338298518956,0.0337368728713,0.03337002376,0.0338298518956,0.0343986954966,0.0338298518956,0.0349870423412,0.0366593097966,0.0349870423412,0.0366593097966,0.0376723180826,0.0360137653449,0.0366593097966,0.0366593097966,0.0349870423412,0.0376723180826,0.0360137653449,0.0382597222295,0.0376723180826,0.0362264002984,0.0362264002984,0.0362264002984,0.0366593097966,0.0343986954966,0.0343986954966,0.0343986954966,0.0338298518956,0.035595912948,0.0338298518956,0.0338298518956,0.0343986954966,0.0329225566183,0.0338298518956,0.0325731514408,0.0325731514408,0.0325731514408);

modeFreqs=par(i,nModes,ba.take(i+1, modeFrequencies));
modeGains=par(i,nModes,ba.take(i+1, massEigenValues));
modeT60 = par(i,nModes,ba.take(i+1,t60));

cabinetFenderBlackfaceBass=modalModel(nModes,modeFrequencies,modeT60,modeGains);

modalModel(n,modeFreqs,modeRes,modeGains) = _ <: par(i,n,gain(i)*pm.modeFilter(freqs(i),res(i))) :> _
with {
	freqs(i) = ba.take(i+1,modeFreqs);
	res(i) = ba.take(i+1,modeRes);
	gain(i) = ba.take(i+1,modeGains);
};


cab = cabinetFenderBlackfaceBass;

wetdry = vslider("[2] amount[style:knob]",  1, 0, 1, 0.01);
dry = 1 - wetdry;

process = _ <: _*dry, (_*wetdry:cab) :> _;