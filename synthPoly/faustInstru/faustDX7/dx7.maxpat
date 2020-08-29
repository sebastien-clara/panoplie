{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 7,
			"minor" : 3,
			"revision" : 4,
			"architecture" : "x86",
			"modernui" : 1
		}
,
		"rect" : [ 234.0, 218.0, 1124.0, 444.0 ],
		"bglocked" : 0,
		"openinpresentation" : 1,
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
		"toolbars_unpinned_last_save" : 2,
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
					"id" : "obj-32",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "" ],
					"patching_rect" : [ 250.0, 126.5, 68.0, 22.0 ],
					"style" : "",
					"text" : "select 27"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-35",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 4,
					"outlettype" : [ "int", "int", "int", "int" ],
					"patching_rect" : [ 250.0, 90.5, 68.0, 22.0 ],
					"style" : "",
					"text" : "key"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"id" : "obj-36",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 321.030212, 127.5, 31.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 35.0, 79.0, 34.0, 20.0 ],
					"style" : "",
					"text" : "esc",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-38",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 298.030212, 253.932373, 27.0, 22.0 ],
					"style" : "",
					"text" : "0"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-47",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 298.030212, 216.932373, 54.0, 22.0 ],
					"style" : "",
					"text" : "del 250"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-49",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 250.0, 231.932373, 27.0, 22.0 ],
					"style" : "",
					"text" : "1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-53",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 250.0, 161.432373, 45.0, 45.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 259.083344, 13.833298, 27.833298, 27.833298 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-59",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 250.0, 288.932373, 139.0, 19.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/Panic $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-27",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 11.5, 115.999985, 100.0, 22.0 ],
					"style" : "",
					"text" : "faustDX7~"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-24",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 1393.276978, 1329.0, 31.0, 22.0 ],
					"style" : "",
					"text" : "+ 7."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-22",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 812.276978, 1341.5, 31.0, 22.0 ],
					"style" : "",
					"text" : "+ 7."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-18",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 251.276947, 1358.5, 31.0, 22.0 ],
					"style" : "",
					"text" : "+ 7."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-15",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 1355.776978, 493.5, 31.0, 22.0 ],
					"style" : "",
					"text" : "+ 7."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-11",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 774.776978, 504.0, 31.0, 22.0 ],
					"style" : "",
					"text" : "+ 7."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-6",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 213.776947, 516.5, 31.0, 22.0 ],
					"style" : "",
					"text" : "+ 7."
				}

			}
, 			{
				"box" : 				{
					"comment" : "",
					"id" : "obj-44",
					"index" : 0,
					"maxclass" : "inlet",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 11.5, 35.499985, 30.0, 30.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-55",
					"linecount" : 15,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1508.0, 88.999985, 125.0, 210.0 ],
					"style" : "",
					"text" : ";\n#1-5-opMode 0;\n#1-5-opFreq 1;\n#1-5-opDetune 1;\n#1-5-opRateScale 0;\n#1-5-egR1 90;\n#1-5-egR2 90;\n#1-5-egR3 90;\n#1-5-egR4 90;\n#1-5-egL1 0;\n#1-5-egL2 90;\n#1-5-egL3 90;\n#1-5-egL4 0;\n#1-5-keyVelSens 1;\n#1-5-level 95;"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-51",
					"linecount" : 15,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1366.0, 88.999985, 127.0, 210.0 ],
					"style" : "",
					"text" : ";\n#1-4-opMode 0;\n#1-4-opFreq 1;\n#1-4-opDetune 1;\n#1-4-opRateScale 0;\n#1-4-egR1 90;\n#1-4-egR2 90;\n#1-4-egR3 90;\n#1-4-egR4 90;\n#1-4-egL1 0;\n#1-4-egL2 90;\n#1-4-egL3 90;\n#1-4-egL4 0;\n#1-4-keyVelSens 1;\n#1-4-level 95;"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-46",
					"linecount" : 15,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1228.0, 88.999985, 127.0, 210.0 ],
					"style" : "",
					"text" : ";\n#1-3-opMode 0;\n#1-3-opFreq 1;\n#1-3-opDetune 1;\n#1-3-opRateScale 0;\n#1-3-egR1 90;\n#1-3-egR2 90;\n#1-3-egR3 90;\n#1-3-egR4 90;\n#1-3-egL1 0;\n#1-3-egL2 90;\n#1-3-egL3 90;\n#1-3-egL4 0;\n#1-3-keyVelSens 1;\n#1-3-level 95;"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-41",
					"linecount" : 15,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1090.0, 88.999985, 127.0, 210.0 ],
					"style" : "",
					"text" : ";\n#1-2-opMode 0;\n#1-2-opFreq 1;\n#1-2-opDetune 1;\n#1-2-opRateScale 0;\n#1-2-egR1 90;\n#1-2-egR2 90;\n#1-2-egR3 90;\n#1-2-egR4 90;\n#1-2-egL1 0;\n#1-2-egL2 90;\n#1-2-egL3 90;\n#1-2-egL4 0;\n#1-2-keyVelSens 1;\n#1-2-level 95;"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-37",
					"linecount" : 15,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 954.776978, 88.999985, 127.0, 210.0 ],
					"style" : "",
					"text" : ";\n#1-1-opMode 0;\n#1-1-opFreq 1;\n#1-1-opDetune 1;\n#1-1-opRateScale 0;\n#1-1-egR1 90;\n#1-1-egR2 90;\n#1-1-egR3 90;\n#1-1-egR4 90;\n#1-1-egL1 0;\n#1-1-egL2 90;\n#1-1-egL3 90;\n#1-1-egL4 0;\n#1-1-keyVelSens 1;\n#1-1-level 95;"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-33",
					"linecount" : 15,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 823.276978, 88.999985, 127.0, 210.0 ],
					"style" : "",
					"text" : ";\n#1-0-opMode 0;\n#1-0-opFreq 1;\n#1-0-opDetune 1;\n#1-0-opRateScale 0;\n#1-0-egR1 90;\n#1-0-egR2 90;\n#1-0-egR3 90;\n#1-0-egR4 90;\n#1-0-egL1 0;\n#1-0-egL2 90;\n#1-0-egL3 90;\n#1-0-egL4 0;\n#1-0-keyVelSens 1;\n#1-0-level 95;"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-190",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1426.276978, 2018.333252, 71.0, 22.0 ],
					"style" : "",
					"text" : "s #1-toDX7"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-191",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1562.7771, 1501.5, 109.0, 22.0 ],
					"style" : "",
					"text" : "r #1-5-keyVelSens"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-192",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1562.776978, 1535.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 245.43335, 690.333374, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "5-keyVelSens",
							"parameter_shortname" : "5-keyVelSens",
							"parameter_type" : 0,
							"parameter_mmax" : 8.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "5-keyVelSens"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-193",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1599.276978, 1792.5, 71.0, 22.0 ],
					"style" : "",
					"text" : "r #1-5-level"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-194",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1599.276978, 1826.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 245.43335, 641.333374, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "5-level",
							"parameter_shortname" : "5-level",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "5-level"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-195",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1499.776978, 1826.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 245.43335, 592.333374, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "5-egL4",
							"parameter_shortname" : "5-egL4",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "5-egL4"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-196",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1499.776978, 1792.5, 73.0, 22.0 ],
					"style" : "",
					"text" : "r #1-5-egL4"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-197",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1402.276978, 1826.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 245.43335, 543.333374, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "5-egL3",
							"parameter_shortname" : "5-egL3",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "5-egL3"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-198",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1402.276978, 1792.5, 73.0, 22.0 ],
					"style" : "",
					"text" : "r #1-5-egL3"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-199",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1313.276978, 1826.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 245.43335, 494.333313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "5-egL2",
							"parameter_shortname" : "5-egL2",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "5-egL2"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-200",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1313.276978, 1792.5, 73.0, 22.0 ],
					"style" : "",
					"text" : "r #1-5-egL2"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-201",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1223.276978, 1826.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 245.43335, 445.333313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "5-egL1",
							"parameter_shortname" : "5-egL1",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "5-egL1"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-202",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1223.276978, 1792.5, 73.0, 22.0 ],
					"style" : "",
					"text" : "r #1-5-egL1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-203",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1469.276978, 1535.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 245.43335, 397.833313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "5-egR4",
							"parameter_shortname" : "5-egR4",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "5-egR4"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-204",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1469.2771, 1501.5, 75.0, 22.0 ],
					"style" : "",
					"text" : "r #1-5-egR4"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-205",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1371.776978, 1535.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 245.43335, 348.833313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "5-egR3",
							"parameter_shortname" : "5-egR3",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "5-egR1[1]"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-206",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1371.7771, 1501.5, 75.0, 22.0 ],
					"style" : "",
					"text" : "r #1-5-egR3"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-207",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1282.776978, 1535.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 245.43335, 299.833313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "5-egR2",
							"parameter_shortname" : "5-egR2",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "5-egR2"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-208",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1282.7771, 1501.5, 75.0, 22.0 ],
					"style" : "",
					"text" : "r #1-5-egR2"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-209",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1241.7771, 1467.333252, 71.0, 22.0 ],
					"style" : "",
					"text" : "s #1-toDX7"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-210",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1501.276978, 1309.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 245.43335, 201.833298, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "5-opRateScale",
							"parameter_shortname" : "5-opRateScale",
							"parameter_type" : 0,
							"parameter_mmax" : 10.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "5-opRateScale"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-211",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1501.2771, 1274.5, 115.0, 22.0 ],
					"style" : "",
					"text" : "r #1-5-opRateScale"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-212",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1393.276978, 1269.0, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 245.43335, 152.833298, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "5-opDetune",
							"parameter_shortname" : "5-opDet",
							"parameter_type" : 0,
							"parameter_mmin" : -7.0,
							"parameter_mmax" : 7.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "5-opDetune"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-213",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1393.2771, 1235.0, 98.0, 22.0 ],
					"style" : "",
					"text" : "r #1-5-opDetune"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-214",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1302.276978, 1308.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 245.43335, 103.833298, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "5-opFreq",
							"parameter_shortname" : "5-opFreq",
							"parameter_type" : 1,
							"parameter_mmax" : 1.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "5-opFreq"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-215",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1302.276978, 1274.5, 84.0, 22.0 ],
					"style" : "",
					"text" : "r #1-5-opFreq"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-216",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1192.776978, 1308.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 245.43335, 50.833298, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "5-opMode",
							"parameter_shortname" : "5-opMode",
							"parameter_type" : 1,
							"parameter_mmax" : 1.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "5-opMode"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-217",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1192.776978, 1274.5, 89.0, 22.0 ],
					"style" : "",
					"text" : "r #1-5-opMode"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-218",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1562.776978, 1614.0, 239.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op5/keyVelSens $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-219",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1599.276978, 1891.0, 201.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op5/level $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-220",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1499.776978, 1929.0, 203.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op5/egL4 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-221",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1402.276978, 1891.0, 203.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op5/egL3 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-222",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1313.276978, 1929.0, 203.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op5/egL2 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-223",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1223.276978, 1891.0, 203.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op5/egL1 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-224",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1469.276978, 1649.5, 205.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op5/egR4 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-225",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1371.776978, 1614.0, 205.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op5/egR3 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-226",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1282.776978, 1649.5, 205.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op5/egR2 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-227",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1501.276978, 1404.0, 245.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op5/opRateScale $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-228",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1393.276978, 1372.0, 227.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op5/opDetune $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-229",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1302.276978, 1404.0, 213.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op5/opFreq $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-230",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1192.776978, 1372.0, 220.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op5/opMode $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-231",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1192.776978, 1614.0, 205.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op5/egR1 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-232",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1192.776978, 1535.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 245.43335, 250.833298, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "5-egR1",
							"parameter_shortname" : "5-egR1",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "5-egR1"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-233",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1192.7771, 1501.5, 75.0, 22.0 ],
					"style" : "",
					"text" : "r #1-5-egR1"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-234",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1402.2771, 1716.333252, 71.0, 22.0 ],
					"style" : "",
					"text" : "s #1-toDX7"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-235",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 845.276978, 2025.333252, 71.0, 22.0 ],
					"style" : "",
					"text" : "s #1-toDX7"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-236",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 981.776978, 1508.5, 109.0, 22.0 ],
					"style" : "",
					"text" : "r #1-4-keyVelSens"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-237",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 981.776978, 1542.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 197.43335, 690.333313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "4-keyVelSens",
							"parameter_shortname" : "4-keyVelSens",
							"parameter_type" : 0,
							"parameter_mmax" : 8.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "4-keyVelSens"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-238",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1018.276978, 1799.5, 71.0, 22.0 ],
					"style" : "",
					"text" : "r #1-4-level"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-239",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1018.276978, 1833.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 197.43335, 641.333313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "4-level",
							"parameter_shortname" : "4-level",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "4-level"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-240",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 918.776978, 1833.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 197.43335, 592.333313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "4-egL4",
							"parameter_shortname" : "4-egL4",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "4-egL4"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-241",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 918.776978, 1799.5, 73.0, 22.0 ],
					"style" : "",
					"text" : "r #1-4-egL4"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-242",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 821.276978, 1833.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 197.43335, 543.333313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "4-egL3",
							"parameter_shortname" : "4-egL3",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "4-egL3"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-243",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 821.276978, 1799.5, 73.0, 22.0 ],
					"style" : "",
					"text" : "r #1-4-egL3"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-244",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 732.276978, 1833.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 197.43335, 494.333313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "4-egL2",
							"parameter_shortname" : "4-egL2",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "4-egL2"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-245",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 732.276978, 1799.5, 73.0, 22.0 ],
					"style" : "",
					"text" : "r #1-4-egL2"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-246",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 642.276978, 1833.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 197.43335, 445.333313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "4-egL1",
							"parameter_shortname" : "4-egL1",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "4-egL1"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-247",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 642.276978, 1799.5, 73.0, 22.0 ],
					"style" : "",
					"text" : "r #1-4-egL1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-248",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 888.276978, 1542.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 197.43335, 397.833313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "4-egR4",
							"parameter_shortname" : "4-egR4",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "4-egR4"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-249",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 888.276978, 1508.5, 75.0, 22.0 ],
					"style" : "",
					"text" : "r #1-4-egR4"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-250",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 790.776978, 1542.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 197.43335, 348.833313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "4-egR3",
							"parameter_shortname" : "4-egR3",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "4-egR1[1]"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-251",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 790.776978, 1508.5, 75.0, 22.0 ],
					"style" : "",
					"text" : "r #1-4-egR3"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-252",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 701.776978, 1542.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 197.43335, 299.833313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "4-egR2",
							"parameter_shortname" : "4-egR2",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "0-egR2[4]"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-253",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 701.776978, 1508.5, 75.0, 22.0 ],
					"style" : "",
					"text" : "r #1-4-egR2"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-254",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 660.7771, 1474.333252, 71.0, 22.0 ],
					"style" : "",
					"text" : "s #1-toDX7"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-255",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 920.276978, 1316.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 197.43335, 201.833298, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "4-opRateScale",
							"parameter_shortname" : "4-opRateScale",
							"parameter_type" : 0,
							"parameter_mmax" : 10.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "4-opRateScale"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-256",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 920.276978, 1281.5, 115.0, 22.0 ],
					"style" : "",
					"text" : "r #1-4-opRateScale"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-257",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 812.276978, 1273.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 197.43335, 152.833298, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "4-opDetune",
							"parameter_shortname" : "4-opDet",
							"parameter_type" : 0,
							"parameter_mmin" : -7.0,
							"parameter_mmax" : 7.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "0-opDetune[1]"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-258",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 812.276978, 1234.5, 98.0, 22.0 ],
					"style" : "",
					"text" : "r #1-4-opDetune"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-259",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 721.276978, 1315.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 197.43335, 103.833298, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "4-opFreq",
							"parameter_shortname" : "4-opFreq",
							"parameter_type" : 1,
							"parameter_mmax" : 1.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "4-opFreq"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-260",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 721.276978, 1281.5, 84.0, 22.0 ],
					"style" : "",
					"text" : "r #1-4-opFreq"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-261",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 611.776978, 1315.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 197.43335, 50.833298, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "4-opMode",
							"parameter_shortname" : "4-opMode",
							"parameter_type" : 1,
							"parameter_mmax" : 1.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "4-opMode"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-262",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 611.776978, 1281.5, 89.0, 22.0 ],
					"style" : "",
					"text" : "r #1-4-opMode"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-263",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 981.776978, 1621.0, 239.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op4/keyVelSens $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-264",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1018.276978, 1898.0, 201.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op4/level $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-265",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 918.776978, 1936.0, 203.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op4/egL4 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-266",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 821.276978, 1898.0, 203.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op4/egL3 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-267",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 732.276978, 1936.0, 203.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op4/egL2 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-268",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 642.276978, 1898.0, 203.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op4/egL1 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-269",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 888.276978, 1656.5, 205.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op4/egR4 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-270",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 790.776978, 1621.0, 205.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op4/egR3 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-271",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 701.776978, 1656.5, 205.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op4/egR2 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-272",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 920.276978, 1411.0, 245.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op4/opRateScale $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-273",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 812.276978, 1379.0, 227.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op4/opDetune $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-274",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 721.276978, 1411.0, 213.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op4/opFreq $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-275",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 611.776978, 1379.0, 220.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op4/opMode $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-276",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 611.776978, 1621.0, 205.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op4/egR1 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-277",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 611.776978, 1542.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 197.43335, 250.833298, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "4-egR1",
							"parameter_shortname" : "4-egR1",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "4-egR1"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-278",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 611.776978, 1508.5, 75.0, 22.0 ],
					"style" : "",
					"text" : "r #1-4-egR1"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-279",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 821.2771, 1723.333252, 71.0, 22.0 ],
					"style" : "",
					"text" : "s #1-toDX7"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-280",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 420.776978, 1525.5, 109.0, 22.0 ],
					"style" : "",
					"text" : "r #1-3-keyVelSens"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-281",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 420.776978, 1559.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 149.43335, 690.333313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "3-keyVelSens",
							"parameter_shortname" : "3-keyVelSens",
							"parameter_type" : 0,
							"parameter_mmax" : 8.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "0-keyVelSens[5]"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-282",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 457.276978, 1816.5, 71.0, 22.0 ],
					"style" : "",
					"text" : "r #1-3-level"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-283",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 457.276978, 1850.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 149.43335, 641.333313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "3-level",
							"parameter_shortname" : "3-level",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "3-level"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-284",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 260.276947, 2018.333252, 71.0, 22.0 ],
					"style" : "",
					"text" : "s #1-toDX7"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-285",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 357.776978, 1850.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 149.43335, 592.333313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "3-egL4",
							"parameter_shortname" : "3-egL4",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "3-egL4"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-286",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 357.776978, 1816.5, 73.0, 22.0 ],
					"style" : "",
					"text" : "r #1-3-egL4"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-287",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 260.276947, 1850.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 149.43335, 543.333313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "3-egL3",
							"parameter_shortname" : "3-egL3",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "3-egL3"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-288",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 260.276947, 1816.5, 73.0, 22.0 ],
					"style" : "",
					"text" : "r #1-3-egL3"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-289",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 171.276947, 1850.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 149.43335, 494.333313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "3-egL2",
							"parameter_shortname" : "3-egL2",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "3-egL2"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-290",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 171.276947, 1816.5, 73.0, 22.0 ],
					"style" : "",
					"text" : "r #1-3-egL2"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-291",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 81.276947, 1850.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 149.43335, 445.333313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "3-egL1",
							"parameter_shortname" : "3-egL1",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "3-egL1"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-292",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 81.276947, 1816.5, 73.0, 22.0 ],
					"style" : "",
					"text" : "r #1-3-egL1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-293",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 327.276978, 1559.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 149.43335, 397.833313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "3-egR4",
							"parameter_shortname" : "3-egR4",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "3-egR4"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-294",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 327.276978, 1525.5, 75.0, 22.0 ],
					"style" : "",
					"text" : "r #1-3-egR4"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-295",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 229.776947, 1559.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 149.43335, 348.833313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "3-egR3",
							"parameter_shortname" : "3-egR3",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "3-egR1[1]"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-296",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 229.776947, 1525.5, 75.0, 22.0 ],
					"style" : "",
					"text" : "r #1-3-egR3"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-297",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 140.776947, 1559.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 149.43335, 299.833313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "3-egR2",
							"parameter_shortname" : "3-egR2",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "3-egR2"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-298",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 140.776947, 1525.5, 75.0, 22.0 ],
					"style" : "",
					"text" : "r #1-3-egR2"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-299",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 99.777046, 1491.333252, 71.0, 22.0 ],
					"style" : "",
					"text" : "s #1-toDX7"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-300",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 359.276978, 1333.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 149.43335, 201.833298, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "3-opRateScale",
							"parameter_shortname" : "3-opRateScale",
							"parameter_type" : 0,
							"parameter_mmax" : 10.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "3-opRateScale"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-301",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 359.276978, 1298.5, 115.0, 22.0 ],
					"style" : "",
					"text" : "r #1-3-opRateScale"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-302",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 251.276947, 1298.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 149.43335, 152.833298, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "3-opDetune",
							"parameter_shortname" : "3-opDet",
							"parameter_type" : 0,
							"parameter_mmin" : -7.0,
							"parameter_mmax" : 7.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "3-opDetune"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-303",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 251.276947, 1259.5, 98.0, 22.0 ],
					"style" : "",
					"text" : "r #1-3-opDetune"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-304",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 160.276947, 1332.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 149.43335, 103.833298, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "3-opFreq",
							"parameter_shortname" : "3-opFreq",
							"parameter_type" : 1,
							"parameter_mmax" : 1.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "3-opFreq"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-305",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 160.276947, 1298.5, 84.0, 22.0 ],
					"style" : "",
					"text" : "r #1-3-opFreq"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-306",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 50.776947, 1332.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 149.43335, 50.833298, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "3-opMode",
							"parameter_shortname" : "3-opMode",
							"parameter_type" : 1,
							"parameter_mmax" : 1.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "3-opMode"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-307",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 50.776947, 1298.5, 89.0, 22.0 ],
					"style" : "",
					"text" : "r #1-3-opMode"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-308",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 420.776978, 1638.0, 239.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op3/keyVelSens $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-309",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 457.276978, 1915.0, 201.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op3/level $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-310",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 357.776978, 1953.0, 203.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op3/egL4 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-311",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 260.276947, 1915.0, 203.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op3/egL3 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-312",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 171.276947, 1953.0, 203.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op3/egL2 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-313",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 81.276947, 1915.0, 203.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op3/egL1 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-314",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 327.276978, 1673.5, 205.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op3/egR4 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-315",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 229.776947, 1638.0, 205.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op3/egR3 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-316",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 140.776947, 1673.5, 205.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op3/egR2 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-317",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 359.276978, 1428.0, 245.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op3/opRateScale $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-318",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 251.276947, 1396.0, 227.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op3/opDetune $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-319",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 160.276947, 1428.0, 213.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op3/opFreq $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-320",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 50.776947, 1396.0, 220.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op3/opMode $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-321",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 50.776947, 1638.0, 205.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op3/egR1 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-322",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 50.776947, 1559.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 149.43335, 250.833298, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "3-egR1",
							"parameter_shortname" : "3-egR1",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "3-egR1"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-323",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 50.776947, 1525.5, 75.0, 22.0 ],
					"style" : "",
					"text" : "r #1-3-egR1"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-324",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 260.277039, 1740.333252, 71.0, 22.0 ],
					"style" : "",
					"text" : "s #1-toDX7"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-145",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1388.7771, 1177.333252, 71.0, 22.0 ],
					"style" : "",
					"text" : "s #1-toDX7"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-146",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1525.276978, 660.5, 109.0, 22.0 ],
					"style" : "",
					"text" : "r #1-2-keyVelSens"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-147",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1525.276978, 694.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 101.433357, 690.333313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "2-keyVelSens",
							"parameter_shortname" : "2-keyVelSens",
							"parameter_type" : 0,
							"parameter_mmax" : 8.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "2-keyVelSens"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-148",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1561.776978, 951.5, 71.0, 22.0 ],
					"style" : "",
					"text" : "r #1-2-level"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-149",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1561.776978, 985.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 101.433357, 641.333313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "2-level",
							"parameter_shortname" : "2-level",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "2-level"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-150",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1462.276978, 985.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 101.433357, 592.333313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "2-egL4",
							"parameter_shortname" : "2-egL4",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "2-egL4"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-151",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1462.276978, 951.5, 73.0, 22.0 ],
					"style" : "",
					"text" : "r #1-2-egL4"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-152",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1364.776978, 985.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 101.433357, 543.333313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "2-egL3",
							"parameter_shortname" : "2-egL3",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "2-egL3"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-153",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1364.776978, 951.5, 73.0, 22.0 ],
					"style" : "",
					"text" : "r #1-2-egL3"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-154",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1275.776978, 985.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 101.433357, 494.333313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "2-egL2",
							"parameter_shortname" : "2-egL2",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "2-egL2"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-155",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1275.776978, 951.5, 73.0, 22.0 ],
					"style" : "",
					"text" : "r #1-2-egL2"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-156",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1185.776978, 985.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 101.433357, 445.333313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "2-egL1",
							"parameter_shortname" : "2-egL1",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "2-egL1"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-157",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1185.776978, 951.5, 73.0, 22.0 ],
					"style" : "",
					"text" : "r #1-2-egL1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-158",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1431.776978, 694.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 101.433357, 397.833313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "2-egR4",
							"parameter_shortname" : "2-egR4",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "2-egR4"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-159",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1431.776978, 660.5, 75.0, 22.0 ],
					"style" : "",
					"text" : "r #1-2-egR4"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-160",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1334.276978, 694.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 101.433357, 348.833313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "2-egR3",
							"parameter_shortname" : "2-egR3",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "2-egR1[1]"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-161",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1334.276978, 660.5, 75.0, 22.0 ],
					"style" : "",
					"text" : "r #1-2-egR3"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-162",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1245.276978, 694.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 101.433357, 299.833313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "2-egR2",
							"parameter_shortname" : "2-egR2",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "2-egR2"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-163",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1245.276978, 660.5, 75.0, 22.0 ],
					"style" : "",
					"text" : "r #1-2-egR2"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-164",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1286.7771, 620.333313, 71.0, 22.0 ],
					"style" : "",
					"text" : "s #1-toDX7"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-165",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1463.776978, 468.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 101.433357, 201.833298, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "2-opRateScale",
							"parameter_shortname" : "2-opRateScale",
							"parameter_type" : 0,
							"parameter_mmax" : 10.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "2-opRateScale"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-166",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1463.776978, 433.5, 115.0, 22.0 ],
					"style" : "",
					"text" : "r #1-2-opRateScale"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-167",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1355.776978, 433.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 101.433357, 152.833298, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "2-opDetune",
							"parameter_shortname" : "2-opDet",
							"parameter_type" : 0,
							"parameter_mmin" : -7.0,
							"parameter_mmax" : 7.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "2-opDetune"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-168",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1355.776978, 394.5, 98.0, 22.0 ],
					"style" : "",
					"text" : "r #1-2-opDetune"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-169",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1264.776978, 467.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 101.433357, 103.833298, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "2-opFreq",
							"parameter_shortname" : "2-opFreq",
							"parameter_type" : 1,
							"parameter_mmax" : 1.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "2-opFreq"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-170",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1264.776978, 433.5, 84.0, 22.0 ],
					"style" : "",
					"text" : "r #1-2-opFreq"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-171",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1155.276978, 467.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 101.433357, 50.833298, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "2-opMode",
							"parameter_shortname" : "2-opMode",
							"parameter_type" : 1,
							"parameter_mmax" : 1.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "2-opMode"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-172",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1155.276978, 433.5, 89.0, 22.0 ],
					"style" : "",
					"text" : "r #1-2-opMode"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-173",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1525.276978, 773.0, 239.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op2/keyVelSens $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-174",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1561.776978, 1050.0, 201.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op2/level $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-175",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1462.276978, 1088.0, 203.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op2/egL4 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-176",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1364.776978, 1050.0, 203.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op2/egL3 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-177",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1275.776978, 1088.0, 203.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op2/egL2 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-178",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1185.776978, 1050.0, 203.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op2/egL1 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-179",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1431.776978, 808.5, 205.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op2/egR4 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-180",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1334.276978, 773.0, 205.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op2/egR3 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-181",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1245.276978, 808.5, 205.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op2/egR2 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-182",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1463.776978, 563.0, 245.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op2/opRateScale $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-183",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1355.776978, 531.0, 227.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op2/opDetune $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-184",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1264.776978, 563.0, 213.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op2/opFreq $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-185",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1155.276978, 531.0, 220.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op2/opMode $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-186",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1155.276978, 773.0, 205.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op2/egR1 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-187",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1155.276978, 694.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 101.433357, 250.833298, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "2-egR1",
							"parameter_shortname" : "2-egR1",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "2-egR1"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-188",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1155.276978, 660.5, 75.0, 22.0 ],
					"style" : "",
					"text" : "r #1-2-egR1"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-189",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1364.7771, 875.333313, 71.0, 22.0 ],
					"style" : "",
					"text" : "s #1-toDX7"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-144",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 807.7771, 1184.333252, 71.0, 22.0 ],
					"style" : "",
					"text" : "s #1-toDX7"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-99",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 944.276978, 667.5, 108.0, 22.0 ],
					"style" : "",
					"text" : "r #1-1-keyVelSens"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-100",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 944.276978, 701.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 53.433353, 690.333313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "1-keyVelSens",
							"parameter_shortname" : "1-keyVelSens",
							"parameter_type" : 0,
							"parameter_mmax" : 8.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "1-keyVelSens"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-101",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 980.776978, 958.5, 71.0, 22.0 ],
					"style" : "",
					"text" : "r #1-1-level"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-102",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 980.776978, 992.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 53.433353, 641.333313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "1-level",
							"parameter_shortname" : "1-level",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "1-level"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-103",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 881.276978, 992.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 53.433353, 592.333313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "1-egL4",
							"parameter_shortname" : "1-egL4",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "1-egL4"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-104",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 881.276978, 958.5, 73.0, 22.0 ],
					"style" : "",
					"text" : "r #1-1-egL4"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-105",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 783.776978, 992.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 53.433353, 543.333313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "1-egL3",
							"parameter_shortname" : "1-egL3",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "1-egL3"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-106",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 783.776978, 958.5, 73.0, 22.0 ],
					"style" : "",
					"text" : "r #1-1-egL3"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-107",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 694.776978, 992.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 53.433353, 494.333313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "1-egL2",
							"parameter_shortname" : "1-egL2",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "1-egL2"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-108",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 694.776978, 958.5, 73.0, 22.0 ],
					"style" : "",
					"text" : "r #1-1-egL2"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-109",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 604.776978, 992.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 53.433353, 445.333313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "1-egL1",
							"parameter_shortname" : "1-egL1",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "1-egL1"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-110",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 604.776978, 958.5, 73.0, 22.0 ],
					"style" : "",
					"text" : "r #1-1-egL1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-111",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 850.776978, 701.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 53.433353, 397.833313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "1-egR4",
							"parameter_shortname" : "1-egR4",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "1-egR4"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-112",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 850.776978, 667.5, 75.0, 22.0 ],
					"style" : "",
					"text" : "r #1-1-egR4"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-113",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 753.276978, 701.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 53.433353, 348.833313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "1-egR3",
							"parameter_shortname" : "1-egR3",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "1-egR1"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-114",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 753.276978, 667.5, 75.0, 22.0 ],
					"style" : "",
					"text" : "r #1-1-egR3"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-115",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 664.276978, 701.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 53.433353, 299.833313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "1-egR2",
							"parameter_shortname" : "1-egR2",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "1-egR2"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-116",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 664.276978, 667.5, 75.0, 22.0 ],
					"style" : "",
					"text" : "r #1-1-egR2"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-118",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 718.2771, 627.333313, 71.0, 22.0 ],
					"style" : "",
					"text" : "s #1-toDX7"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-119",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 882.776978, 475.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 53.433353, 201.833298, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "1-opRateScale",
							"parameter_shortname" : "1-opRateScale",
							"parameter_type" : 0,
							"parameter_mmax" : 10.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "1-opRateScale"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-120",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 882.776978, 440.5, 115.0, 22.0 ],
					"style" : "",
					"text" : "r #1-1-opRateScale"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-121",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 774.776978, 445.0, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 53.433353, 152.833298, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "1-opDetune",
							"parameter_shortname" : "1-opDet",
							"parameter_type" : 0,
							"parameter_mmin" : -7.0,
							"parameter_mmax" : 7.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "1-opDetune"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-122",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 774.776978, 406.0, 98.0, 22.0 ],
					"style" : "",
					"text" : "r #1-1-opDetune"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-123",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 683.776978, 474.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 53.433353, 103.833298, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "1-opFreq",
							"parameter_shortname" : "1-opFreq",
							"parameter_type" : 1,
							"parameter_mmax" : 1.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "1-opFreq"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-124",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 683.776978, 440.5, 84.0, 22.0 ],
					"style" : "",
					"text" : "r #1-1-opFreq"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-125",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 574.276978, 474.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 53.433353, 50.833298, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "1-opMode",
							"parameter_shortname" : "1-opMode",
							"parameter_type" : 1,
							"parameter_mmax" : 1.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "1-opMode"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-126",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 574.276978, 440.5, 89.0, 22.0 ],
					"style" : "",
					"text" : "r #1-1-opMode"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-127",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 944.276978, 780.0, 238.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op1/keyVelSens $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-128",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 980.776978, 1057.0, 201.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op1/level $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-129",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 881.276978, 1095.0, 203.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op1/egL4 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-130",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 783.776978, 1057.0, 203.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op1/egL3 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-131",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 694.776978, 1095.0, 203.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op1/egL2 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-132",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 604.776978, 1057.0, 203.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op1/egL1 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-133",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 850.776978, 815.5, 205.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op1/egR4 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-134",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 753.276978, 780.0, 205.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op1/egR3 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-135",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 664.276978, 815.5, 205.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op1/egR2 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-136",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 882.776978, 570.0, 245.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op1/opRateScale $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-137",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 774.776978, 538.0, 227.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op1/opDetune $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-138",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 683.776978, 570.0, 213.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op1/opFreq $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-139",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 574.276978, 538.0, 220.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op1/opMode $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-140",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 574.276978, 780.0, 205.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op1/egR1 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-141",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 574.276978, 701.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 53.433353, 250.833313, 46.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "1-egR1",
							"parameter_shortname" : "1-egR1",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "1-egR1[1]"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-142",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 574.276978, 667.5, 75.0, 22.0 ],
					"style" : "",
					"text" : "r #1-1-egR1"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-143",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 791.7771, 886.333313, 71.0, 22.0 ],
					"style" : "",
					"text" : "s #1-toDX7"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-98",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 383.276978, 681.833374, 109.0, 22.0 ],
					"style" : "",
					"text" : "r #1-0-keyVelSens"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-97",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 383.276978, 718.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 7.433355, 690.333313, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "0-keyVelSens",
							"parameter_shortname" : "0-keyVelSens",
							"parameter_type" : 0,
							"parameter_mmax" : 8.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "0-keyVelSens"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-96",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 419.776978, 975.5, 71.0, 22.0 ],
					"style" : "",
					"text" : "r #1-0-level"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-95",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 419.776978, 1009.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 7.433355, 641.333313, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "0-level",
							"parameter_shortname" : "0-level",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "0-level"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-93",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 222.777054, 1177.333252, 71.0, 22.0 ],
					"style" : "",
					"text" : "s #1-toDX7"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-85",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 320.276978, 1009.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 7.433355, 592.333313, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "0-egL4",
							"parameter_shortname" : "0-egL4",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "0-egL4"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-86",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 320.276978, 975.5, 73.0, 22.0 ],
					"style" : "",
					"text" : "r #1-0-egL4"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-87",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 222.776947, 1009.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 7.433355, 543.333313, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "0-egL3",
							"parameter_shortname" : "0-egL3",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "0-egL3"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-88",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 222.776947, 975.5, 73.0, 22.0 ],
					"style" : "",
					"text" : "r #1-0-egL3"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-89",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 133.776947, 1009.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 7.433355, 494.333313, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "0-egL2",
							"parameter_shortname" : "0-egL2",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "0-egL2"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-90",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 133.776947, 975.5, 73.0, 22.0 ],
					"style" : "",
					"text" : "r #1-0-egL2"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-91",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 43.776947, 1009.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 7.433355, 445.333313, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "0-egL1",
							"parameter_shortname" : "0-egL1",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "0-egL1"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-92",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 43.776947, 975.5, 73.0, 22.0 ],
					"style" : "",
					"text" : "r #1-0-egL1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-83",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 289.776978, 718.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 7.433355, 397.833313, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "0-egR4",
							"parameter_shortname" : "0-egR4",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "0-egR4"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-84",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 289.776978, 681.833374, 75.0, 22.0 ],
					"style" : "",
					"text" : "r #1-0-egR4"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-81",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 192.276947, 718.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 7.433355, 348.833313, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "0-egR3",
							"parameter_shortname" : "0-egR3",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "0-egR1[2]"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-82",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 192.276947, 681.833374, 75.0, 22.0 ],
					"style" : "",
					"text" : "r #1-0-egR3"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-79",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 103.276947, 718.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 7.433355, 299.833313, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "0-egR2",
							"parameter_shortname" : "0-egR2",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "0-egR2"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-80",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 103.276947, 681.833374, 75.0, 22.0 ],
					"style" : "",
					"text" : "r #1-0-egR2"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-78",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 173.277054, 644.333313, 71.0, 22.0 ],
					"style" : "",
					"text" : "s #1-toDX7"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-76",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 321.776978, 492.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 7.433355, 201.833298, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "0-opRateScale",
							"parameter_shortname" : "0-opRateScale",
							"parameter_type" : 0,
							"parameter_mmax" : 10.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "0-opRateScale"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-77",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 321.777008, 457.5, 115.0, 22.0 ],
					"style" : "",
					"text" : "r #1-0-opRateScale"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-74",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 213.776947, 457.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 7.433355, 152.833298, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "0-opDetune",
							"parameter_shortname" : "0-opDet",
							"parameter_type" : 0,
							"parameter_mmin" : -7.0,
							"parameter_mmax" : 7.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "0-opDetune"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-75",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 213.776962, 418.5, 98.0, 22.0 ],
					"style" : "",
					"text" : "r #1-0-opDetune"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-73",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 122.776947, 491.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 7.433355, 103.833298, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "0-opFreq",
							"parameter_shortname" : "0-opFreq",
							"parameter_type" : 1,
							"parameter_mmax" : 1.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "0-opFreq"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-72",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 122.77697, 457.5, 84.0, 22.0 ],
					"style" : "",
					"text" : "r #1-0-opFreq"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-69",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 13.276947, 491.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 7.433355, 50.833298, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "0-opMode",
							"parameter_shortname" : "0-opMode",
							"parameter_type" : 1,
							"parameter_mmax" : 1.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "0-opMode"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-70",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 13.276967, 457.5, 89.0, 22.0 ],
					"style" : "",
					"text" : "r #1-0-opMode"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-68",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 383.276978, 797.0, 238.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op0/keyVelSens $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-64",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 419.776978, 1074.0, 201.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op0/level $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-62",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 320.276978, 1112.0, 203.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op0/egL4 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-60",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 222.776947, 1074.0, 203.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op0/egL3 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-58",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 133.776947, 1112.0, 203.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op0/egL2 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-56",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 43.776947, 1074.0, 203.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op0/egL1 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-54",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 289.776978, 832.5, 205.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op0/egR4 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-52",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 192.276947, 797.0, 205.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op0/egR3 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-50",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 103.276947, 832.5, 205.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op0/egR2 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-48",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 321.776978, 587.0, 245.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op0/opRateScale $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-45",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 213.776947, 555.0, 227.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op0/opDetune $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-43",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 122.776947, 587.0, 213.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op0/opFreq $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-40",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 13.276947, 555.0, 220.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op0/opMode $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-34",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 13.276947, 797.0, 205.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/op0/egR1 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-28",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 13.276947, 718.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 7.433355, 250.833298, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "0-egR1",
							"parameter_shortname" : "0-egR1",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "0-egR1"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-29",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 13.276947, 681.833374, 75.0, 22.0 ],
					"style" : "",
					"text" : "r #1-0-egR1"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-30",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 222.777054, 899.333313, 71.0, 22.0 ],
					"style" : "",
					"text" : "s #1-toDX7"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-23",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 596.776978, 296.5, 238.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/global/algorithm $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-25",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 596.776978, 230.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 170.499985, -0.166702, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "algorithm",
							"parameter_shortname" : "algo",
							"parameter_type" : 1,
							"parameter_mmax" : 31.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "algorithm"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-26",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 596.776978, 185.5, 85.0, 22.0 ],
					"style" : "",
					"text" : "r #1-algorithm"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-17",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 507.777008, 329.5, 237.0, 22.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/dx7/global/feedback $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-19",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 507.777008, 238.0, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 216.499985, -0.166702, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "feedback",
							"parameter_shortname" : "fbk",
							"parameter_type" : 0,
							"parameter_mmax" : 99.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "feedback"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-21",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 507.777008, 185.5, 84.0, 22.0 ],
					"style" : "",
					"text" : "r #1-feedback"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-2",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "", "", "", "" ],
					"patching_rect" : [ 128.0, 7.333298, 58.0, 22.0 ],
					"restore" : 					{
						"0-egL1" : [ 0.0 ],
						"0-egL2" : [ 90.0 ],
						"0-egL3" : [ 90.0 ],
						"0-egL4" : [ 0.0 ],
						"0-egR1" : [ 90.0 ],
						"0-egR1[2]" : [ 90.0 ],
						"0-egR2" : [ 90.0 ],
						"0-egR2[4]" : [ 90.0 ],
						"0-egR4" : [ 90.0 ],
						"0-keyVelSens" : [ 1.0 ],
						"0-keyVelSens[5]" : [ 1.0 ],
						"0-level" : [ 95.0 ],
						"0-opDetune" : [ 1.0 ],
						"0-opDetune[1]" : [ 1.0 ],
						"0-opFreq" : [ 1.0 ],
						"0-opMode" : [ 0.0 ],
						"0-opRateScale" : [ 0.0 ],
						"1-egL1" : [ 0.0 ],
						"1-egL2" : [ 90.0 ],
						"1-egL3" : [ 90.0 ],
						"1-egL4" : [ 0.0 ],
						"1-egR1" : [ 90.0 ],
						"1-egR1[1]" : [ 90.0 ],
						"1-egR2" : [ 90.0 ],
						"1-egR4" : [ 90.0 ],
						"1-keyVelSens" : [ 1.0 ],
						"1-level" : [ 95.0 ],
						"1-opDetune" : [ 1.0 ],
						"1-opFreq" : [ 1.0 ],
						"1-opMode" : [ 0.0 ],
						"1-opRateScale" : [ 0.0 ],
						"2-egL1" : [ 0.0 ],
						"2-egL2" : [ 90.0 ],
						"2-egL3" : [ 90.0 ],
						"2-egL4" : [ 0.0 ],
						"2-egR1" : [ 90.0 ],
						"2-egR1[1]" : [ 90.0 ],
						"2-egR2" : [ 90.0 ],
						"2-egR4" : [ 90.0 ],
						"2-keyVelSens" : [ 1.0 ],
						"2-level" : [ 95.0 ],
						"2-opDetune" : [ 1.0 ],
						"2-opFreq" : [ 1.0 ],
						"2-opMode" : [ 0.0 ],
						"2-opRateScale" : [ 0.0 ],
						"3-egL1" : [ 0.0 ],
						"3-egL2" : [ 90.0 ],
						"3-egL3" : [ 90.0 ],
						"3-egL4" : [ 0.0 ],
						"3-egR1" : [ 90.0 ],
						"3-egR1[1]" : [ 90.0 ],
						"3-egR2" : [ 90.0 ],
						"3-egR4" : [ 90.0 ],
						"3-level" : [ 95.0 ],
						"3-opDetune" : [ 1.0 ],
						"3-opFreq" : [ 1.0 ],
						"3-opMode" : [ 0.0 ],
						"3-opRateScale" : [ 0.0 ],
						"4-egL1" : [ 0.0 ],
						"4-egL2" : [ 90.0 ],
						"4-egL3" : [ 90.0 ],
						"4-egL4" : [ 0.0 ],
						"4-egR1" : [ 90.0 ],
						"4-egR1[1]" : [ 90.0 ],
						"4-egR4" : [ 90.0 ],
						"4-keyVelSens" : [ 1.0 ],
						"4-level" : [ 95.0 ],
						"4-opFreq" : [ 1.0 ],
						"4-opMode" : [ 0.0 ],
						"4-opRateScale" : [ 0.0 ],
						"5-egL1" : [ 0.0 ],
						"5-egL2" : [ 90.0 ],
						"5-egL3" : [ 90.0 ],
						"5-egL4" : [ 0.0 ],
						"5-egR1" : [ 90.0 ],
						"5-egR1[1]" : [ 90.0 ],
						"5-egR2" : [ 90.0 ],
						"5-egR4" : [ 90.0 ],
						"5-keyVelSens" : [ 1.0 ],
						"5-level" : [ 95.0 ],
						"5-opDetune" : [ 1.0 ],
						"5-opFreq" : [ 1.0 ],
						"5-opMode" : [ 0.0 ],
						"5-opRateScale" : [ 0.0 ],
						"algorithm" : [ 0.0 ],
						"feedback" : [ 0.0 ]
					}
,
					"style" : "",
					"text" : "autopattr",
					"varname" : "u092002906"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-1",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1051.053955, 17.0, 62.0, 22.0 ],
					"style" : "",
					"text" : "r #1-reset"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-16",
					"linecount" : 3,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 719.776978, 88.999985, 96.0, 49.0 ],
					"style" : "",
					"text" : ";\n#1-feedback 0;\n#1-algorithm 0;"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 1.0, 0.973183, 0.925342, 0.0 ],
					"blinkcolor" : [ 0.952941, 0.085953, 0.0, 0.87 ],
					"id" : "obj-42",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"outlinecolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"patching_rect" : [ 69.5, 362.0, 20.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 127.900055, 17.833298, 19.0, 19.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontsize" : 11.0,
					"id" : "obj-39",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 97.0, 362.0, 43.0, 19.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 119.100037, 5.833298, 36.600037, 19.0 ],
					"style" : "",
					"text" : "reset",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-20",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 69.5, 396.166626, 64.0, 22.0 ],
					"style" : "",
					"text" : "s #1-reset"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-31",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 560.776978, 372.333313, 71.0, 22.0 ],
					"style" : "",
					"text" : "s #1-toDX7"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-9",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 7.5, 364.333313, 43.0, 22.0 ],
					"style" : "",
					"text" : "set $1"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontsize" : 10.0,
					"id" : "obj-14",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 7.5, 395.666626, 44.0, 18.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 84.100037, 13.833298, 33.0, 18.0 ],
					"style" : "",
					"text" : "#1",
					"textcolor" : [ 0.741176, 0.356863, 0.047059, 1.0 ],
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontsize" : 15.0,
					"id" : "obj-8",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 246.0, 7.333298, 142.0, 23.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1.600037, 10.833298, 85.5, 23.0 ],
					"style" : "",
					"text" : "Faust DX7",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-7",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 7.5, 334.333313, 29.5, 22.0 ],
					"style" : "",
					"text" : "#1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-5",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 69.5, 298.5, 60.0, 22.0 ],
					"style" : "",
					"text" : "loadbang"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontsize" : 11.0,
					"id" : "obj-13",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 338.0, 155.432373, 43.0, 19.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 252.833328, -3.166702, 40.333332, 19.0 ],
					"style" : "",
					"text" : "panic",
					"textcolor" : [ 0.784314, 0.145098, 0.023529, 1.0 ],
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"comment" : "",
					"id" : "obj-12",
					"index" : 0,
					"maxclass" : "outlet",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 11.5, 159.499985, 30.0, 30.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-4",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 56.0, 50.666672, 69.0, 22.0 ],
					"style" : "",
					"text" : "r #1-toDX7"
				}

			}
, 			{
				"box" : 				{
					"angle" : 270.0,
					"border" : 1,
					"bordercolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"grad1" : [ 1.0, 1.0, 1.0, 0.0 ],
					"grad2" : [ 0.290196, 0.309804, 0.301961, 0.0 ],
					"id" : "obj-10",
					"maxclass" : "panel",
					"mode" : 1,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 422.599976, 7.333298, 40.0, 40.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 0.266685, -0.166702, 298.233276, 742.666748 ],
					"proportion" : 0.39,
					"style" : ""
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 0 ],
					"order" : 6,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-33", 0 ],
					"order" : 5,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-37", 0 ],
					"order" : 4,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-41", 0 ],
					"order" : 3,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-46", 0 ],
					"order" : 2,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-51", 0 ],
					"order" : 1,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-55", 0 ],
					"order" : 0,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-127", 0 ],
					"source" : [ "obj-100", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-102", 0 ],
					"source" : [ "obj-101", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-128", 0 ],
					"source" : [ "obj-102", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-129", 0 ],
					"source" : [ "obj-103", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-103", 0 ],
					"source" : [ "obj-104", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-130", 0 ],
					"source" : [ "obj-105", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-105", 0 ],
					"source" : [ "obj-106", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-131", 0 ],
					"source" : [ "obj-107", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-107", 0 ],
					"source" : [ "obj-108", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-132", 0 ],
					"source" : [ "obj-109", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-137", 0 ],
					"source" : [ "obj-11", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-109", 0 ],
					"source" : [ "obj-110", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-133", 0 ],
					"source" : [ "obj-111", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-111", 0 ],
					"source" : [ "obj-112", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-134", 0 ],
					"source" : [ "obj-113", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-113", 0 ],
					"source" : [ "obj-114", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-135", 0 ],
					"source" : [ "obj-115", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-115", 0 ],
					"source" : [ "obj-116", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-136", 0 ],
					"source" : [ "obj-119", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-119", 0 ],
					"source" : [ "obj-120", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 0 ],
					"source" : [ "obj-121", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-121", 0 ],
					"source" : [ "obj-122", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-138", 0 ],
					"source" : [ "obj-123", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-123", 0 ],
					"source" : [ "obj-124", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-139", 0 ],
					"source" : [ "obj-125", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-125", 0 ],
					"source" : [ "obj-126", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-143", 0 ],
					"source" : [ "obj-127", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-144", 0 ],
					"source" : [ "obj-128", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-144", 0 ],
					"source" : [ "obj-129", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-144", 0 ],
					"source" : [ "obj-130", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-144", 0 ],
					"source" : [ "obj-131", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-144", 0 ],
					"source" : [ "obj-132", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-143", 0 ],
					"source" : [ "obj-133", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-143", 0 ],
					"source" : [ "obj-134", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-143", 0 ],
					"source" : [ "obj-135", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-118", 0 ],
					"source" : [ "obj-136", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-118", 0 ],
					"source" : [ "obj-137", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-118", 0 ],
					"source" : [ "obj-138", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-118", 0 ],
					"source" : [ "obj-139", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-143", 0 ],
					"source" : [ "obj-140", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-140", 0 ],
					"source" : [ "obj-141", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-141", 0 ],
					"source" : [ "obj-142", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-147", 0 ],
					"source" : [ "obj-146", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-173", 0 ],
					"source" : [ "obj-147", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-149", 0 ],
					"source" : [ "obj-148", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-174", 0 ],
					"source" : [ "obj-149", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-183", 0 ],
					"source" : [ "obj-15", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-175", 0 ],
					"source" : [ "obj-150", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-150", 0 ],
					"source" : [ "obj-151", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-176", 0 ],
					"source" : [ "obj-152", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-152", 0 ],
					"source" : [ "obj-153", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-177", 0 ],
					"source" : [ "obj-154", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-154", 0 ],
					"source" : [ "obj-155", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-178", 0 ],
					"source" : [ "obj-156", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-156", 0 ],
					"source" : [ "obj-157", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-179", 0 ],
					"source" : [ "obj-158", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-158", 0 ],
					"source" : [ "obj-159", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-180", 0 ],
					"source" : [ "obj-160", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-160", 0 ],
					"source" : [ "obj-161", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-181", 0 ],
					"source" : [ "obj-162", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-162", 0 ],
					"source" : [ "obj-163", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-182", 0 ],
					"source" : [ "obj-165", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-165", 0 ],
					"source" : [ "obj-166", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 0 ],
					"source" : [ "obj-167", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-167", 0 ],
					"source" : [ "obj-168", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-184", 0 ],
					"source" : [ "obj-169", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-31", 0 ],
					"source" : [ "obj-17", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-169", 0 ],
					"source" : [ "obj-170", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-185", 0 ],
					"source" : [ "obj-171", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-171", 0 ],
					"source" : [ "obj-172", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-189", 0 ],
					"source" : [ "obj-173", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-145", 0 ],
					"source" : [ "obj-174", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-145", 0 ],
					"source" : [ "obj-175", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-145", 0 ],
					"source" : [ "obj-176", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-145", 0 ],
					"source" : [ "obj-177", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-145", 0 ],
					"source" : [ "obj-178", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-189", 0 ],
					"source" : [ "obj-179", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-318", 0 ],
					"source" : [ "obj-18", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-189", 0 ],
					"source" : [ "obj-180", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-189", 0 ],
					"source" : [ "obj-181", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-164", 0 ],
					"source" : [ "obj-182", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-164", 0 ],
					"source" : [ "obj-183", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-164", 0 ],
					"source" : [ "obj-184", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-164", 0 ],
					"source" : [ "obj-185", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-189", 0 ],
					"source" : [ "obj-186", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-186", 0 ],
					"source" : [ "obj-187", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-187", 0 ],
					"source" : [ "obj-188", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-17", 0 ],
					"source" : [ "obj-19", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-192", 0 ],
					"source" : [ "obj-191", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-218", 0 ],
					"source" : [ "obj-192", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-194", 0 ],
					"source" : [ "obj-193", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-219", 0 ],
					"source" : [ "obj-194", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-220", 0 ],
					"source" : [ "obj-195", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-195", 0 ],
					"source" : [ "obj-196", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-221", 0 ],
					"source" : [ "obj-197", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-197", 0 ],
					"source" : [ "obj-198", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-222", 0 ],
					"source" : [ "obj-199", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-199", 0 ],
					"source" : [ "obj-200", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-223", 0 ],
					"source" : [ "obj-201", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-201", 0 ],
					"source" : [ "obj-202", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-224", 0 ],
					"source" : [ "obj-203", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-203", 0 ],
					"source" : [ "obj-204", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-225", 0 ],
					"source" : [ "obj-205", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-205", 0 ],
					"source" : [ "obj-206", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-226", 0 ],
					"source" : [ "obj-207", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-207", 0 ],
					"source" : [ "obj-208", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-19", 0 ],
					"source" : [ "obj-21", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-227", 0 ],
					"source" : [ "obj-210", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-210", 0 ],
					"source" : [ "obj-211", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 0 ],
					"source" : [ "obj-212", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-212", 0 ],
					"source" : [ "obj-213", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-229", 0 ],
					"source" : [ "obj-214", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-214", 0 ],
					"source" : [ "obj-215", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-230", 0 ],
					"source" : [ "obj-216", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-216", 0 ],
					"source" : [ "obj-217", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-234", 0 ],
					"source" : [ "obj-218", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-190", 0 ],
					"source" : [ "obj-219", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-273", 0 ],
					"source" : [ "obj-22", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-190", 0 ],
					"source" : [ "obj-220", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-190", 0 ],
					"source" : [ "obj-221", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-190", 0 ],
					"source" : [ "obj-222", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-190", 0 ],
					"source" : [ "obj-223", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-234", 0 ],
					"source" : [ "obj-224", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-234", 0 ],
					"source" : [ "obj-225", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-234", 0 ],
					"source" : [ "obj-226", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-209", 0 ],
					"source" : [ "obj-227", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-209", 0 ],
					"source" : [ "obj-228", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-209", 0 ],
					"source" : [ "obj-229", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-31", 0 ],
					"source" : [ "obj-23", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-209", 0 ],
					"source" : [ "obj-230", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-234", 0 ],
					"source" : [ "obj-231", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-231", 0 ],
					"source" : [ "obj-232", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-232", 0 ],
					"source" : [ "obj-233", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-237", 0 ],
					"source" : [ "obj-236", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-263", 0 ],
					"source" : [ "obj-237", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-239", 0 ],
					"source" : [ "obj-238", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-264", 0 ],
					"source" : [ "obj-239", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-228", 0 ],
					"source" : [ "obj-24", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-265", 0 ],
					"source" : [ "obj-240", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-240", 0 ],
					"source" : [ "obj-241", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-266", 0 ],
					"source" : [ "obj-242", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-242", 0 ],
					"source" : [ "obj-243", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-267", 0 ],
					"source" : [ "obj-244", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-244", 0 ],
					"source" : [ "obj-245", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-268", 0 ],
					"source" : [ "obj-246", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-246", 0 ],
					"source" : [ "obj-247", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-269", 0 ],
					"source" : [ "obj-248", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-248", 0 ],
					"source" : [ "obj-249", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"source" : [ "obj-25", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-270", 0 ],
					"source" : [ "obj-250", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-250", 0 ],
					"source" : [ "obj-251", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-271", 0 ],
					"source" : [ "obj-252", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-252", 0 ],
					"source" : [ "obj-253", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-272", 0 ],
					"source" : [ "obj-255", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-255", 0 ],
					"source" : [ "obj-256", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"source" : [ "obj-257", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-257", 0 ],
					"source" : [ "obj-258", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-274", 0 ],
					"source" : [ "obj-259", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"source" : [ "obj-26", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-259", 0 ],
					"source" : [ "obj-260", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-275", 0 ],
					"source" : [ "obj-261", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-261", 0 ],
					"source" : [ "obj-262", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-279", 0 ],
					"source" : [ "obj-263", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-235", 0 ],
					"source" : [ "obj-264", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-235", 0 ],
					"source" : [ "obj-265", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-235", 0 ],
					"source" : [ "obj-266", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-235", 0 ],
					"source" : [ "obj-267", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-235", 0 ],
					"source" : [ "obj-268", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-279", 0 ],
					"source" : [ "obj-269", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-12", 0 ],
					"source" : [ "obj-27", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-279", 0 ],
					"source" : [ "obj-270", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-279", 0 ],
					"source" : [ "obj-271", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-254", 0 ],
					"source" : [ "obj-272", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-254", 0 ],
					"source" : [ "obj-273", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-254", 0 ],
					"source" : [ "obj-274", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-254", 0 ],
					"source" : [ "obj-275", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-279", 0 ],
					"source" : [ "obj-276", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-276", 0 ],
					"source" : [ "obj-277", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-277", 0 ],
					"source" : [ "obj-278", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-34", 0 ],
					"source" : [ "obj-28", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-281", 0 ],
					"source" : [ "obj-280", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-308", 0 ],
					"source" : [ "obj-281", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-283", 0 ],
					"source" : [ "obj-282", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-309", 0 ],
					"source" : [ "obj-283", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-310", 0 ],
					"source" : [ "obj-285", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-285", 0 ],
					"source" : [ "obj-286", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-311", 0 ],
					"source" : [ "obj-287", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-287", 0 ],
					"source" : [ "obj-288", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-312", 0 ],
					"source" : [ "obj-289", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-28", 0 ],
					"source" : [ "obj-29", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-289", 0 ],
					"source" : [ "obj-290", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-313", 0 ],
					"source" : [ "obj-291", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-291", 0 ],
					"source" : [ "obj-292", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-314", 0 ],
					"source" : [ "obj-293", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-293", 0 ],
					"source" : [ "obj-294", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-315", 0 ],
					"source" : [ "obj-295", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-295", 0 ],
					"source" : [ "obj-296", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-316", 0 ],
					"source" : [ "obj-297", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-297", 0 ],
					"source" : [ "obj-298", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-317", 0 ],
					"source" : [ "obj-300", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-300", 0 ],
					"source" : [ "obj-301", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-18", 0 ],
					"source" : [ "obj-302", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-302", 0 ],
					"source" : [ "obj-303", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-319", 0 ],
					"source" : [ "obj-304", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-304", 0 ],
					"source" : [ "obj-305", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-320", 0 ],
					"source" : [ "obj-306", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-306", 0 ],
					"source" : [ "obj-307", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-324", 0 ],
					"source" : [ "obj-308", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-284", 0 ],
					"source" : [ "obj-309", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-284", 0 ],
					"source" : [ "obj-310", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-284", 0 ],
					"source" : [ "obj-311", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-284", 0 ],
					"source" : [ "obj-312", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-284", 0 ],
					"source" : [ "obj-313", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-324", 0 ],
					"source" : [ "obj-314", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-324", 0 ],
					"source" : [ "obj-315", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-324", 0 ],
					"source" : [ "obj-316", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-299", 0 ],
					"source" : [ "obj-317", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-299", 0 ],
					"source" : [ "obj-318", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-299", 0 ],
					"source" : [ "obj-319", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-53", 0 ],
					"source" : [ "obj-32", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-299", 0 ],
					"source" : [ "obj-320", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-324", 0 ],
					"source" : [ "obj-321", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-321", 0 ],
					"source" : [ "obj-322", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-322", 0 ],
					"source" : [ "obj-323", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-30", 0 ],
					"source" : [ "obj-34", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-32", 0 ],
					"source" : [ "obj-35", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-59", 0 ],
					"source" : [ "obj-38", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 0 ],
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-78", 0 ],
					"source" : [ "obj-40", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-20", 0 ],
					"source" : [ "obj-42", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-78", 0 ],
					"source" : [ "obj-43", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 0 ],
					"source" : [ "obj-44", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-78", 0 ],
					"source" : [ "obj-45", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-38", 0 ],
					"source" : [ "obj-47", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-78", 0 ],
					"source" : [ "obj-48", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-59", 0 ],
					"source" : [ "obj-49", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-42", 0 ],
					"order" : 0,
					"source" : [ "obj-5", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 0 ],
					"order" : 1,
					"source" : [ "obj-5", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-30", 0 ],
					"source" : [ "obj-50", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-30", 0 ],
					"source" : [ "obj-52", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-47", 0 ],
					"order" : 0,
					"source" : [ "obj-53", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-49", 0 ],
					"order" : 1,
					"source" : [ "obj-53", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-30", 0 ],
					"source" : [ "obj-54", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-93", 0 ],
					"source" : [ "obj-56", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-93", 0 ],
					"source" : [ "obj-58", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-31", 0 ],
					"source" : [ "obj-59", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-45", 0 ],
					"source" : [ "obj-6", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-93", 0 ],
					"source" : [ "obj-60", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-93", 0 ],
					"source" : [ "obj-62", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-93", 0 ],
					"source" : [ "obj-64", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-30", 0 ],
					"source" : [ "obj-68", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-40", 0 ],
					"source" : [ "obj-69", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"source" : [ "obj-7", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-69", 0 ],
					"source" : [ "obj-70", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-73", 0 ],
					"source" : [ "obj-72", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-43", 0 ],
					"source" : [ "obj-73", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"source" : [ "obj-74", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-74", 0 ],
					"source" : [ "obj-75", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-48", 0 ],
					"source" : [ "obj-76", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-76", 0 ],
					"source" : [ "obj-77", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-50", 0 ],
					"source" : [ "obj-79", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-79", 0 ],
					"source" : [ "obj-80", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-52", 0 ],
					"source" : [ "obj-81", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-81", 0 ],
					"source" : [ "obj-82", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-54", 0 ],
					"source" : [ "obj-83", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-83", 0 ],
					"source" : [ "obj-84", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-62", 0 ],
					"source" : [ "obj-85", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-85", 0 ],
					"source" : [ "obj-86", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-60", 0 ],
					"source" : [ "obj-87", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-87", 0 ],
					"source" : [ "obj-88", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-58", 0 ],
					"source" : [ "obj-89", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 0 ],
					"source" : [ "obj-9", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-89", 0 ],
					"source" : [ "obj-90", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-56", 0 ],
					"source" : [ "obj-91", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-91", 0 ],
					"source" : [ "obj-92", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-64", 0 ],
					"source" : [ "obj-95", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-95", 0 ],
					"source" : [ "obj-96", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-68", 0 ],
					"source" : [ "obj-97", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-97", 0 ],
					"source" : [ "obj-98", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-100", 0 ],
					"source" : [ "obj-99", 0 ]
				}

			}
 ],
		"parameters" : 		{
			"obj-103" : [ "1-egL4", "1-egL4", 0 ],
			"obj-158" : [ "2-egR4", "2-egR4", 0 ],
			"obj-171" : [ "2-opMode", "2-opMode", 0 ],
			"obj-100" : [ "1-keyVelSens", "1-keyVelSens", 0 ],
			"obj-119" : [ "1-opRateScale", "1-opRateScale", 0 ],
			"obj-285" : [ "3-egL4", "3-egL4", 0 ],
			"obj-283" : [ "3-level", "3-level", 0 ],
			"obj-246" : [ "4-egL1", "4-egL1", 0 ],
			"obj-261" : [ "4-opMode", "4-opMode", 0 ],
			"obj-195" : [ "5-egL4", "5-egL4", 0 ],
			"obj-257" : [ "4-opDetune", "4-opDet", 0 ],
			"obj-89" : [ "0-egL2", "0-egL2", 0 ],
			"obj-192" : [ "5-keyVelSens", "5-keyVelSens", 0 ],
			"obj-79" : [ "0-egR2", "0-egR2", 0 ],
			"obj-210" : [ "5-opRateScale", "5-opRateScale", 0 ],
			"obj-205" : [ "5-egR3", "5-egR3", 0 ],
			"obj-95" : [ "0-level", "0-level", 0 ],
			"obj-76" : [ "0-opRateScale", "0-opRateScale", 0 ],
			"obj-150" : [ "2-egL4", "2-egL4", 0 ],
			"obj-147" : [ "2-keyVelSens", "2-keyVelSens", 0 ],
			"obj-141" : [ "1-egR1", "1-egR1", 0 ],
			"obj-165" : [ "2-opRateScale", "2-opRateScale", 0 ],
			"obj-102" : [ "1-level", "1-level", 0 ],
			"obj-322" : [ "3-egR1", "3-egR1", 0 ],
			"obj-302" : [ "3-opDetune", "3-opDet", 0 ],
			"obj-244" : [ "4-egL2", "4-egL2", 0 ],
			"obj-81" : [ "0-egR3", "0-egR3", 0 ],
			"obj-160" : [ "2-egR3", "2-egR3", 0 ],
			"obj-248" : [ "4-egR4", "4-egR4", 0 ],
			"obj-255" : [ "4-opRateScale", "4-opRateScale", 0 ],
			"obj-232" : [ "5-egR1", "5-egR1", 0 ],
			"obj-87" : [ "0-egL3", "0-egL3", 0 ],
			"obj-194" : [ "5-level", "5-level", 0 ],
			"obj-25" : [ "algorithm", "algo", 0 ],
			"obj-74" : [ "0-opDetune", "0-opDet", 0 ],
			"obj-295" : [ "3-egR3", "3-egR3", 0 ],
			"obj-187" : [ "2-egR1", "2-egR1", 0 ],
			"obj-109" : [ "1-egL1", "1-egL1", 0 ],
			"obj-149" : [ "2-level", "2-level", 0 ],
			"obj-291" : [ "3-egL1", "3-egL1", 0 ],
			"obj-121" : [ "1-opDetune", "1-opDet", 0 ],
			"obj-304" : [ "3-opFreq", "3-opFreq", 0 ],
			"obj-281" : [ "3-keyVelSens", "3-keyVelSens", 0 ],
			"obj-242" : [ "4-egL3", "4-egL3", 0 ],
			"obj-237" : [ "4-keyVelSens", "4-keyVelSens", 0 ],
			"obj-201" : [ "5-egL1", "5-egL1", 0 ],
			"obj-212" : [ "5-opDetune", "5-opDet", 0 ],
			"obj-85" : [ "0-egL4", "0-egL4", 0 ],
			"obj-83" : [ "0-egR4", "0-egR4", 0 ],
			"obj-19" : [ "feedback", "fbk", 0 ],
			"obj-156" : [ "2-egL1", "2-egL1", 0 ],
			"obj-107" : [ "1-egL2", "1-egL2", 0 ],
			"obj-115" : [ "1-egR2", "1-egR2", 0 ],
			"obj-167" : [ "2-opDetune", "2-opDet", 0 ],
			"obj-289" : [ "3-egL2", "3-egL2", 0 ],
			"obj-123" : [ "1-opFreq", "1-opFreq", 0 ],
			"obj-297" : [ "3-egR2", "3-egR2", 0 ],
			"obj-306" : [ "3-opMode", "3-opMode", 0 ],
			"obj-240" : [ "4-egL4", "4-egL4", 0 ],
			"obj-239" : [ "4-level", "4-level", 0 ],
			"obj-199" : [ "5-egL2", "5-egL2", 0 ],
			"obj-207" : [ "5-egR2", "5-egR2", 0 ],
			"obj-28" : [ "0-egR1", "0-egR1", 0 ],
			"obj-214" : [ "5-opFreq", "5-opFreq", 0 ],
			"obj-97" : [ "0-keyVelSens", "0-keyVelSens", 0 ],
			"obj-154" : [ "2-egL2", "2-egL2", 0 ],
			"obj-73" : [ "0-opFreq", "0-opFreq", 0 ],
			"obj-105" : [ "1-egL3", "1-egL3", 0 ],
			"obj-162" : [ "2-egR2", "2-egR2", 0 ],
			"obj-111" : [ "1-egR4", "1-egR4", 0 ],
			"obj-169" : [ "2-opFreq", "2-opFreq", 0 ],
			"obj-125" : [ "1-opMode", "1-opMode", 0 ],
			"obj-287" : [ "3-egL3", "3-egL3", 0 ],
			"obj-293" : [ "3-egR4", "3-egR4", 0 ],
			"obj-300" : [ "3-opRateScale", "3-opRateScale", 0 ],
			"obj-250" : [ "4-egR3", "4-egR3", 0 ],
			"obj-252" : [ "4-egR2", "4-egR2", 0 ],
			"obj-277" : [ "4-egR1", "4-egR1", 0 ],
			"obj-259" : [ "4-opFreq", "4-opFreq", 0 ],
			"obj-197" : [ "5-egL3", "5-egL3", 0 ],
			"obj-91" : [ "0-egL1", "0-egL1", 0 ],
			"obj-203" : [ "5-egR4", "5-egR4", 0 ],
			"obj-216" : [ "5-opMode", "5-opMode", 0 ],
			"obj-113" : [ "1-egR3", "1-egR3", 0 ],
			"obj-69" : [ "0-opMode", "0-opMode", 0 ],
			"obj-152" : [ "2-egL3", "2-egL3", 0 ]
		}
,
		"dependency_cache" : [ 			{
				"name" : "faustDX7~.mxo",
				"type" : "iLaX"
			}
 ],
		"autosave" : 0,
		"styles" : [ 			{
				"name" : "newobjYellow-1",
				"default" : 				{
					"accentcolor" : [ 0.82517, 0.78181, 0.059545, 1.0 ],
					"fontsize" : [ 12.059008 ]
				}
,
				"parentstyle" : "",
				"multi" : 0
			}
, 			{
				"name" : "numberGold-1",
				"default" : 				{
					"accentcolor" : [ 0.764706, 0.592157, 0.101961, 1.0 ]
				}
,
				"parentstyle" : "",
				"multi" : 0
			}
 ]
	}

}
