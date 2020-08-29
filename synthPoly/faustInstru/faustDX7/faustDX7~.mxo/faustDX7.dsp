declare name "faustDX7";

declare nvoices "16";


import("stdfaust.lib");


bend = vslider("h:dx7/v:global/[9]bend [style:knob] [midi:pitchwheel]", 1,0.9,1.1,0.01);

process = dx7 * 0.25;

dx7 = par(i,32, dx.dx7_algo(i,egR1,egR2,egR3,egR4,egL1,egL2,egL3,egL4,outLevel,keyVelSens,ampModSens,opMode,opFreq,opDetune,opRateScale,feedback,lfoDelay,lfoDepth,lfoSpeed,freq*bend,gain,gate) ) :
	ba.selectn(32,algorithm) : _
with{
	algorithm = nentry("h:dx7/v:global/[0]algorithm",0,0,31,1) : int;
	feedback = nentry("h:dx7/v:global/[1]feedback",0,0,99,1) : dx.dx7_fdbkscalef/(2*ma.PI);
	lfoDelay = nentry("h:dx7/v:global/[2]lfoDelay",0,0,99,1);
	lfoDepth = nentry("h:dx7/v:global/[3]lfoDepth",0,0,99,1);
	lfoSpeed = nentry("h:dx7/v:global/[4]lfoSpeed",0,0,99,1);
	freq = hslider("h:dx7/v:global/[5]freq",400,50,1000,0.01);
	gain = hslider("h:dx7/v:global/[6]gain",0.8,0,1,0.01);
	gate = button("h:dx7/v:global/[7]gate");
	egR1UI = par(i,6,nentry("h:dx7/v:[%i]op%i/[0]egR1",90,0,99,1));
	egR1(n) = ba.take(n+1,egR1UI);
	egR2UI = par(i,6,nentry("h:dx7/v:[%i]op%i/[1]egR2",90,0,99,1));
	egR2(n) = ba.take(n+1,egR2UI);
	egR3UI = par(i,6,nentry("h:dx7/v:[%i]op%i/[2]egR3",90,0,99,1));
	egR3(n) = ba.take(n+1,egR3UI);
	egR4UI = par(i,6,nentry("h:dx7/v:[%i]op%i/[3]egR4",90,0,99,1));
	egR4(n) = ba.take(n+1,egR4UI);
	egL1UI = par(i,6,nentry("h:dx7/v:[%i]op%i/[4]egL1",0,0,99,1));
	egL1(n) = ba.take(n+1,egL1UI);
	egL2UI = par(i,6,nentry("h:dx7/v:[%i]op%i/[5]egL2",90,0,99,1));
	egL2(n) = ba.take(n+1,egL2UI);
	egL3UI = par(i,6,nentry("h:dx7/v:[%i]op%i/[6]egL3",90,0,99,1));
	egL3(n) = ba.take(n+1,egL3UI);
	egL4UI = par(i,6,nentry("h:dx7/v:[%i]op%i/[7]egL4",0,0,99,1));
	egL4(n) = ba.take(n+1,egL4UI);
	outLevelUI = par(i,6,nentry("h:dx7/v:[%i]op%i/[8]level",95,0,99,1));
	outLevel(n) = ba.take(n+1,outLevelUI);
	keyVelSensUI = par(i,6,nentry("h:dx7/v:[%i]op%i/[9]keyVelSens",1,0,8,1));
	keyVelSens(n) = ba.take(n+1,keyVelSensUI);
	ampModSensUI = par(i,6,nentry("h:dx7/v:[%i]op%i/[10]ampModSens",0,0,99,1));
	ampModSens(n) = ba.take(n+1,ampModSensUI);
	opModeUI = par(i,6,nentry("h:dx7/v:[%i]op%i/[11]opMode",0,0,1,1));
	opMode(n) = ba.take(n+1,opModeUI);
	opFreqUI = par(i,6,nentry("h:dx7/v:[%i]op%i/[12]opFreq",1.0,0.0,2.0,0.01));
	opFreq(n) = ba.take(n+1,opFreqUI);
	opDetuneUI = par(i,6,nentry("h:dx7/v:[%i]op%i/[13]opDetune",1,-10,10,1));
	opDetune(n) = ba.take(n+1,opDetuneUI);
	opRateScaleUI = par(i,6,nentry("h:dx7/v:[%i]op%i/[14]opRateScale",0,0,10,1));
	opRateScale(n) = ba.take(n+1,opRateScaleUI);
};
