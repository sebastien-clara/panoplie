{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 7,
			"minor" : 3,
			"revision" : 5,
			"architecture" : "x86",
			"modernui" : 1
		}
,
		"rect" : [ 299.0, 409.0, 432.0, 335.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 1,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 1,
		"objectsnaponopen" : 1,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"lefttoolbarpinned" : 0,
		"toptoolbarpinned" : 0,
		"righttoolbarpinned" : 0,
		"bottomtoolbarpinned" : 0,
		"toolbars_unpinned_last_save" : 0,
		"tallnewobj" : 0,
		"boxanimatetime" : 200,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"style" : "",
		"subpatcher_template" : "",
		"boxes" : [ 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-4",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 3.0, 128.427277, 127.0, 24.0 ],
					"style" : "",
					"text" : "Output parameters",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-7",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 15.0, 56.427277, 115.0, 24.0 ],
					"style" : "",
					"text" : "Select a preset",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-2",
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 132.0, 232.0, 45.0, 45.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"args" : [ 1 ],
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-1",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "dx7main.maxpat",
					"numinlets" : 1,
					"numoutlets" : 1,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 132.0, 14.0, 273.0, 190.0 ],
					"varname" : "dx7main",
					"viewvisibility" : 1
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 1 ],
					"order" : 0,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"order" : 1,
					"source" : [ "obj-1", 0 ]
				}

			}
 ],
		"parameters" : 		{
			"obj-1::obj-32::obj-9::obj-239" : [ "4-level", "4-level", 0 ],
			"obj-1::obj-32::obj-9::obj-74" : [ "0-opDetune", "0-opDet", 0 ],
			"obj-1::obj-32::obj-9::obj-199" : [ "5-egL2", "5-egL2", 0 ],
			"obj-1::obj-32::obj-9::obj-207" : [ "5-egR2", "5-egR2", 0 ],
			"obj-1::obj-32::obj-9::obj-109" : [ "1-egL1", "1-egL1", 0 ],
			"obj-1::obj-32::obj-9::obj-214" : [ "5-opFreq", "5-opFreq", 0 ],
			"obj-1::obj-32::obj-9::obj-121" : [ "1-opDetune", "1-opDet", 0 ],
			"obj-1::obj-32::obj-9::obj-250" : [ "4-egR3", "4-egR3", 0 ],
			"obj-1::obj-32::obj-9::obj-154" : [ "2-egL2", "2-egL2", 0 ],
			"obj-1::obj-32::obj-9::obj-162" : [ "2-egR2", "2-egR2", 0 ],
			"obj-1::obj-32::obj-9::obj-252" : [ "4-egR2", "4-egR2", 0 ],
			"obj-1::obj-32::obj-9::obj-169" : [ "2-opFreq", "2-opFreq", 0 ],
			"obj-1::obj-32::obj-9::obj-287" : [ "3-egL3", "3-egL3", 0 ],
			"obj-1::obj-32::obj-9::obj-257" : [ "4-opDetune", "4-opDet", 0 ],
			"obj-1::obj-32::obj-9::obj-293" : [ "3-egR4", "3-egR4", 0 ],
			"obj-1::obj-32::obj-9::obj-300" : [ "3-opRateScale", "3-opRateScale", 0 ],
			"obj-1::obj-32::obj-9::obj-277" : [ "4-egR1", "4-egR1", 0 ],
			"obj-1::obj-32::obj-9::obj-85" : [ "0-egL4", "0-egL4", 0 ],
			"obj-1::obj-32::obj-9::obj-83" : [ "0-egR4", "0-egR4", 0 ],
			"obj-1::obj-32::obj-9::obj-259" : [ "4-opFreq", "4-opFreq", 0 ],
			"obj-1::obj-32::obj-9::obj-197" : [ "5-egL3", "5-egL3", 0 ],
			"obj-1::obj-32::obj-9::obj-107" : [ "1-egL2", "1-egL2", 0 ],
			"obj-1::obj-32::obj-9::obj-203" : [ "5-egR4", "5-egR4", 0 ],
			"obj-1::obj-32::obj-9::obj-115" : [ "1-egR2", "1-egR2", 0 ],
			"obj-1::obj-32::obj-9::obj-216" : [ "5-opMode", "5-opMode", 0 ],
			"obj-1::obj-32::obj-9::obj-123" : [ "1-opFreq", "1-opFreq", 0 ],
			"obj-1::obj-32::obj-9::obj-152" : [ "2-egL3", "2-egL3", 0 ],
			"obj-1::obj-32::obj-9::obj-158" : [ "2-egR4", "2-egR4", 0 ],
			"obj-1::obj-32::obj-9::obj-171" : [ "2-opMode", "2-opMode", 0 ],
			"obj-1::obj-32::obj-9::obj-285" : [ "3-egL4", "3-egL4", 0 ],
			"obj-1::obj-32::obj-9::obj-283" : [ "3-level", "3-level", 0 ],
			"obj-1::obj-32::obj-9::obj-246" : [ "4-egL1", "4-egL1", 0 ],
			"obj-1::obj-32::obj-9::obj-28" : [ "0-egR1", "0-egR1", 0 ],
			"obj-1::obj-32::obj-9::obj-261" : [ "4-opMode", "4-opMode", 0 ],
			"obj-1::obj-32::obj-9::obj-97" : [ "0-keyVelSens", "0-keyVelSens", 0 ],
			"obj-1::obj-32::obj-9::obj-113" : [ "1-egR3", "1-egR3", 0 ],
			"obj-1::obj-32::obj-9::obj-195" : [ "5-egL4", "5-egL4", 0 ],
			"obj-1::obj-32::obj-9::obj-73" : [ "0-opFreq", "0-opFreq", 0 ],
			"obj-1::obj-32::obj-9::obj-295" : [ "3-egR3", "3-egR3", 0 ],
			"obj-1::obj-32::obj-9::obj-105" : [ "1-egL3", "1-egL3", 0 ],
			"obj-1::obj-32::obj-9::obj-192" : [ "5-keyVelSens", "5-keyVelSens", 0 ],
			"obj-1::obj-32::obj-9::obj-210" : [ "5-opRateScale", "5-opRateScale", 0 ],
			"obj-1::obj-32::obj-9::obj-111" : [ "1-egR4", "1-egR4", 0 ],
			"obj-1::obj-32::obj-9::obj-125" : [ "1-opMode", "1-opMode", 0 ],
			"obj-1::obj-32::obj-9::obj-150" : [ "2-egL4", "2-egL4", 0 ],
			"obj-1::obj-32::obj-9::obj-81" : [ "0-egR3", "0-egR3", 0 ],
			"obj-1::obj-32::obj-9::obj-147" : [ "2-keyVelSens", "2-keyVelSens", 0 ],
			"obj-1::obj-32::obj-9::obj-165" : [ "2-opRateScale", "2-opRateScale", 0 ],
			"obj-1::obj-32::obj-9::obj-322" : [ "3-egR1", "3-egR1", 0 ],
			"obj-1::obj-32::obj-9::obj-281" : [ "3-keyVelSens", "3-keyVelSens", 0 ],
			"obj-1::obj-32::obj-9::obj-160" : [ "2-egR3", "2-egR3", 0 ],
			"obj-1::obj-32::obj-9::obj-302" : [ "3-opDetune", "3-opDet", 0 ],
			"obj-1::obj-32::obj-9::obj-91" : [ "0-egL1", "0-egL1", 0 ],
			"obj-1::obj-32::obj-9::obj-244" : [ "4-egL2", "4-egL2", 0 ],
			"obj-1::obj-32::obj-9::obj-248" : [ "4-egR4", "4-egR4", 0 ],
			"obj-1::obj-32::obj-9::obj-255" : [ "4-opRateScale", "4-opRateScale", 0 ],
			"obj-1::obj-32::obj-9::obj-232" : [ "5-egR1", "5-egR1", 0 ],
			"obj-1::obj-32::obj-9::obj-69" : [ "0-opMode", "0-opMode", 0 ],
			"obj-1::obj-32::obj-9::obj-194" : [ "5-level", "5-level", 0 ],
			"obj-1::obj-32::obj-9::obj-103" : [ "1-egL4", "1-egL4", 0 ],
			"obj-1::obj-32::obj-9::obj-100" : [ "1-keyVelSens", "1-keyVelSens", 0 ],
			"obj-1::obj-32::obj-9::obj-25" : [ "algorithm", "algo", 0 ],
			"obj-1::obj-32::obj-9::obj-119" : [ "1-opRateScale", "1-opRateScale", 0 ],
			"obj-1::obj-32::obj-9::obj-187" : [ "2-egR1", "2-egR1", 0 ],
			"obj-1::obj-32::obj-9::obj-149" : [ "2-level", "2-level", 0 ],
			"obj-1::obj-32::obj-9::obj-291" : [ "3-egL1", "3-egL1", 0 ],
			"obj-1::obj-32::obj-9::obj-304" : [ "3-opFreq", "3-opFreq", 0 ],
			"obj-1::obj-32::obj-9::obj-242" : [ "4-egL3", "4-egL3", 0 ],
			"obj-1::obj-32::obj-9::obj-89" : [ "0-egL2", "0-egL2", 0 ],
			"obj-1::obj-32::obj-9::obj-237" : [ "4-keyVelSens", "4-keyVelSens", 0 ],
			"obj-1::obj-32::obj-9::obj-79" : [ "0-egR2", "0-egR2", 0 ],
			"obj-1::obj-32::obj-9::obj-201" : [ "5-egL1", "5-egL1", 0 ],
			"obj-1::obj-32::obj-9::obj-95" : [ "0-level", "0-level", 0 ],
			"obj-1::obj-37" : [ "live.gain~", "Gain", 0 ],
			"obj-1::obj-32::obj-9::obj-76" : [ "0-opRateScale", "0-opRateScale", 0 ],
			"obj-1::obj-32::obj-9::obj-141" : [ "1-egR1", "1-egR1", 0 ],
			"obj-1::obj-32::obj-9::obj-212" : [ "5-opDetune", "5-opDet", 0 ],
			"obj-1::obj-32::obj-9::obj-102" : [ "1-level", "1-level", 0 ],
			"obj-1::obj-32::obj-9::obj-19" : [ "feedback", "fbk", 0 ],
			"obj-1::obj-32::obj-9::obj-156" : [ "2-egL1", "2-egL1", 0 ],
			"obj-1::obj-32::obj-9::obj-167" : [ "2-opDetune", "2-opDet", 0 ],
			"obj-1::obj-32::obj-9::obj-289" : [ "3-egL2", "3-egL2", 0 ],
			"obj-1::obj-32::obj-9::obj-297" : [ "3-egR2", "3-egR2", 0 ],
			"obj-1::obj-32::obj-9::obj-306" : [ "3-opMode", "3-opMode", 0 ],
			"obj-1::obj-32::obj-9::obj-240" : [ "4-egL4", "4-egL4", 0 ],
			"obj-1::obj-32::obj-9::obj-205" : [ "5-egR3", "5-egR3", 0 ],
			"obj-1::obj-32::obj-9::obj-87" : [ "0-egL3", "0-egL3", 0 ]
		}
,
		"dependency_cache" : [ 			{
				"name" : "dx7main.maxpat",
				"bootpath" : "~/ownCloud/macShare/lutherie/synthPoly/faustInstru/faustDX7",
				"patcherrelativepath" : ".",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "dx7bank.js",
				"bootpath" : "~/ownCloud/macShare/lutherie/synthPoly/faustInstru/faustDX7",
				"patcherrelativepath" : ".",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "dx7.maxpat",
				"bootpath" : "~/ownCloud/macShare/lutherie/synthPoly/faustInstru/faustDX7",
				"patcherrelativepath" : ".",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "selInput.maxpat",
				"bootpath" : "~/ownCloud/macShare/lutherie/tools",
				"patcherrelativepath" : "../../../tools",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "midiNoteFormat.maxpat",
				"bootpath" : "~/ownCloud/macShare/lutherie/tools/under",
				"patcherrelativepath" : "../../../tools/under",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "faustDX7~.mxo",
				"type" : "iLaX"
			}
 ],
		"autosave" : 0
	}

}
