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
		"rect" : [ 175.0, 101.0, 464.0, 698.0 ],
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
					"id" : "obj-18",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 330.0, 513.0, 43.0, 22.0 ],
					"style" : "",
					"text" : "pack"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-42",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "" ],
					"patching_rect" : [ 330.0, 554.932373, 58.0, 22.0 ],
					"style" : "",
					"text" : "route 7 1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-43",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "int", "int" ],
					"patching_rect" : [ 330.0, 476.0, 43.0, 22.0 ],
					"style" : "",
					"text" : "swap"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-44",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "int", "int", "int" ],
					"patching_rect" : [ 330.0, 439.0, 67.0, 22.0 ],
					"style" : "",
					"text" : "unpack i i i"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-6",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 114.0, 718.932373, 44.0, 22.0 ],
					"style" : "",
					"text" : "$1 10."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-41",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 114.0, 753.932373, 43.0, 22.0 ],
					"style" : "",
					"text" : "line 1."
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-47",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 266.0, 718.932373, 115.0, 19.0 ],
					"style" : "",
					"text" : "/dx7/global/portamento $1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-117",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 114.0, 801.932373, 86.0, 19.0 ],
					"style" : "",
					"text" : "/dx7/global/gain $1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-327",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.5, 718.932373, 85.0, 19.0 ],
					"style" : "",
					"text" : "/dx7/global/freq $1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-65",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 477.0, 755.0, 87.0, 19.0 ],
					"style" : "",
					"text" : "/dx7/global/gate $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-77",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 519.0, 655.0, 64.0, 22.0 ],
					"style" : "",
					"text" : "r #1-onOff"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-20",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 507.530212, 712.864746, 45.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ -1.0, 46.5, 51.0, 20.0 ],
					"style" : "",
					"text" : "on / off",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-25",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 477.0, 710.864746, 24.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 13.25, 62.0, 22.5, 22.5 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-9",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "" ],
					"patching_rect" : [ 477.0, 607.0, 68.0, 22.0 ],
					"style" : "",
					"text" : "select 27"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-27",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 4,
					"outlettype" : [ "int", "int", "int", "int" ],
					"patching_rect" : [ 477.0, 571.0, 68.0, 22.0 ],
					"style" : "",
					"text" : "key"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontsize" : 10.0,
					"id" : "obj-29",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 548.030212, 608.0, 57.5, 18.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 0.0, 32.0, 49.0, 18.0 ],
					"style" : "",
					"text" : "esc = off",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-40",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 477.0, 655.0, 27.0, 22.0 ],
					"style" : "",
					"text" : "0"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-3",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 266.0, 603.5, 63.0, 22.0 ],
					"style" : "",
					"text" : "r #1-porta"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-329",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 169.5, 603.5, 59.0, 22.0 ],
					"style" : "",
					"text" : "r #1-amp"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.591933, 0.564554, 0.074619, 1.0 ],
					"id" : "obj-328",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 6.5, 603.5, 56.0, 22.0 ],
					"style" : "",
					"text" : "r #1-freq"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-11",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 77.0, 603.5, 34.0, 22.0 ],
					"style" : "",
					"text" : "mtof"
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
					"patching_rect" : [ 266.0, 643.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 144.0, 37.5, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "portamento",
							"parameter_shortname" : "porta",
							"parameter_type" : 0,
							"parameter_mmax" : 5.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "portamento"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-85",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 114.0, 603.5, 41.0, 22.0 ],
					"style" : "",
					"text" : "/ 127."
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
					"patching_rect" : [ 114.0, 643.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 98.0, 37.5, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "amp",
							"parameter_shortname" : "amp",
							"parameter_type" : 0,
							"parameter_mmax" : 1.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "live.dial"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-82",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 6.5, 643.5, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 52.0, 37.5, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "freq",
							"parameter_shortname" : "freq",
							"parameter_type" : 0,
							"parameter_mmin" : 30.0,
							"parameter_mmax" : 10000.0,
							"parameter_unitstyle" : 3
						}

					}
,
					"varname" : "live.dial[1]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-78",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 151.0, 561.5, 66.0, 22.0 ],
					"style" : "",
					"text" : "s #1-onOff"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-76",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 3,
					"outlettype" : [ "int", "int", "bang" ],
					"patching_rect" : [ 77.0, 530.0, 93.0, 22.0 ],
					"style" : "",
					"text" : "midiPoly2mono"
				}

			}
, 			{
				"box" : 				{
					"comment" : "",
					"id" : "obj-2",
					"index" : 0,
					"maxclass" : "inlet",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 77.0, 264.0, 30.0, 30.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"comment" : "",
					"id" : "obj-49",
					"index" : 0,
					"maxclass" : "outlet",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 14.0, 269.0, 30.0, 30.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-36",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "", "", "", "" ],
					"patching_rect" : [ 601.0, 9.5, 70.0, 22.0 ],
					"restore" : 					{
						"dx7preset" : [ 0 ],
						"live.dial" : [ 0.0 ],
						"live.dial[1]" : [ 440.0 ],
						"live.gain~" : [ -6.0 ],
						"portamento" : [ 0.0 ]
					}
,
					"style" : "",
					"text" : "autopattr",
					"varname" : "u770012689"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-39",
					"maxclass" : "newobj",
					"numinlets" : 5,
					"numoutlets" : 5,
					"outlettype" : [ "", "", "", "", "" ],
					"patching_rect" : [ 77.0, 451.0, 186.0, 22.0 ],
					"style" : "",
					"text" : "route midiNote bend stop midiCtl"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-30",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 7,
							"minor" : 3,
							"revision" : 5,
							"architecture" : "x86",
							"modernui" : 1
						}
,
						"rect" : [ 117.0, 103.0, 640.0, 480.0 ],
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
						"boxes" : [ 							{
								"box" : 								{
									"id" : "obj-27",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 123.917114, 235.0, 100.0, 22.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 82.872253, 232.0, 100.0, 22.0 ],
									"style" : "",
									"text" : "- 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-26",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "bang", "int" ],
									"patching_rect" : [ 50.0, 100.0, 92.917114, 22.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 8.955139, 97.0, 92.917114, 22.0 ],
									"style" : "",
									"text" : "t b i"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-18",
									"linecount" : 4,
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 50.0, 140.573151, 943.0, 67.0 ],
									"presentation" : 1,
									"presentation_linecount" : 4,
									"presentation_rect" : [ 8.955139, 137.573151, 937.0, 67.0 ],
									"style" : "",
									"text" : "4 16 57 62 64 73 78 85 86 114 136 143 150 168 188 206 216 224 228 234 243 249 251 256 276 286 287 308 310 322 346 354 367 380 382 407 409 417 442 502 515 524 577 600 629 679 723 730 731 734 760 762 767 770 784 795 820 852 865 879 883 892 925 929 944 968 969 973 990 994 996 1001 1006 1007 1011 1015 1019 1027 1038 1040 1048 1050 1069 1075 1078 1086 1099 1101 1103 1109 1120 1122 1126 1128 1130 1132 1134 1136 1139 1144 1145 1148 1151 1153 1158 1162 1179 1185 1189 1202 1204 1212 1224 1225 1236 1254 1268 1275 1285 1288 1312 1315 1328 1354 1383 1407 1498 1513 1551 1564 1581"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 13.0,
									"id" : "obj-19",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 50.0, 277.831573, 92.917114, 23.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 8.955139, 274.831573, 92.917114, 23.0 ],
									"style" : "",
									"text" : "zl mth 3"
								}

							}
, 							{
								"box" : 								{
									"comment" : "",
									"id" : "obj-30",
									"index" : 1,
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 50.0, 40.0, 30.0, 30.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"comment" : "",
									"id" : "obj-31",
									"index" : 1,
									"maxclass" : "outlet",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 50.0, 360.831573, 30.0, 30.0 ],
									"style" : ""
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-19", 0 ],
									"source" : [ "obj-18", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-31", 0 ],
									"source" : [ "obj-19", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-18", 0 ],
									"source" : [ "obj-26", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-27", 0 ],
									"source" : [ "obj-26", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-19", 1 ],
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-26", 0 ],
									"source" : [ "obj-30", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 539.0, 70.0, 84.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"globalpatchername" : "",
						"style" : "",
						"tags" : ""
					}
,
					"style" : "",
					"text" : "p presetSel"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-31",
					"maxclass" : "number",
					"maximum" : 131,
					"minimum" : 1,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 539.0, 30.5, 41.0, 23.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 128.5, 192.0, 41.0, 23.0 ],
					"style" : "",
					"triscale" : 0.9
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-21",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 137.780212, 6.0, 89.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 189.0, 195.0, 80.0, 20.0 ],
					"style" : "",
					"text" : "v. 20180914",
					"textjustification" : 2
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-8",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 14.0, 6.0, 105.469788, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1.0, 195.0, 101.0, 20.0 ],
					"style" : "",
					"text" : "Sébastien Clara"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-50",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 463.0, 81.0, 50.0, 22.0 ],
					"style" : "",
					"text" : "set $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-46",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 521.530212, 114.0, 94.469788, 20.0 ],
					"presentation" : 1,
					"presentation_linecount" : 2,
					"presentation_rect" : [ 128.5, 1.0, 50.0, 33.0 ],
					"style" : "",
					"text" : "preset number",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-38",
					"maxclass" : "number",
					"minimum" : 0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 463.0, 114.0, 50.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 177.939545, 6.5, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.702269, 0.811747, 0.303388, 1.0 ],
					"id" : "obj-24",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 374.0, 811.932373, 72.0, 22.0 ],
					"style" : "",
					"text" : "s #1-dx7KR"
				}

			}
, 			{
				"box" : 				{
					"args" : [ "#1" ],
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-5",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "selInput.maxpat",
					"numinlets" : 1,
					"numoutlets" : 2,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 77.0, 315.432373, 228.0, 104.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1.0, 112.0, 223.939545, 83.0 ],
					"varname" : "selInput",
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-23",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 7,
							"minor" : 3,
							"revision" : 5,
							"architecture" : "x86",
							"modernui" : 1
						}
,
						"rect" : [ 142.0, 128.0, 640.0, 480.0 ],
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
						"boxes" : [ 							{
								"box" : 								{
									"id" : "obj-2",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 214.0, 117.0, 114.0, 20.0 ],
									"style" : "",
									"text" : "flèches haut / bas"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-50",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 107.469788, 201.932373, 30.5, 22.0 ],
									"style" : "",
									"text" : "+ 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-46",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 50.0, 201.932373, 30.5, 22.0 ],
									"style" : "",
									"text" : "- 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-45",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 107.469788, 162.0, 42.0, 22.0 ],
									"style" : "",
									"text" : "int"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-44",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 50.0, 162.0, 42.0, 22.0 ],
									"style" : "",
									"text" : "int"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-5",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 3,
									"outlettype" : [ "bang", "bang", "" ],
									"patching_rect" : [ 50.0, 117.0, 133.939575, 22.0 ],
									"style" : "",
									"text" : "select 30 31"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-8",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 4,
									"outlettype" : [ "int", "int", "int", "int" ],
									"patching_rect" : [ 50.0, 70.0, 68.0, 22.0 ],
									"style" : "",
									"text" : "key"
								}

							}
, 							{
								"box" : 								{
									"comment" : "",
									"id" : "obj-18",
									"index" : 1,
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 130.469788, 37.0, 30.0, 30.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"comment" : "",
									"id" : "obj-20",
									"index" : 1,
									"maxclass" : "outlet",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 72.734894, 283.932373, 30.0, 30.0 ],
									"style" : ""
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-44", 1 ],
									"order" : 1,
									"source" : [ "obj-18", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-45", 1 ],
									"order" : 0,
									"source" : [ "obj-18", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-46", 0 ],
									"source" : [ "obj-44", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-50", 0 ],
									"source" : [ "obj-45", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-20", 0 ],
									"source" : [ "obj-46", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-44", 0 ],
									"source" : [ "obj-5", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-45", 0 ],
									"source" : [ "obj-5", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-20", 0 ],
									"source" : [ "obj-50", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-5", 0 ],
									"source" : [ "obj-8", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 238.530212, 192.0, 99.469788, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"globalpatchername" : "",
						"style" : "",
						"tags" : ""
					}
,
					"style" : "",
					"text" : "p keyboardKR"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontsize" : 20.0,
					"id" : "obj-130",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 361.0, 6.0, 83.0, 51.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 0.0, 1.0, 120.0, 29.0 ],
					"style" : "",
					"text" : "DX7 mono",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-17",
					"maxclass" : "newobj",
					"numinlets" : 6,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 137.780212, 108.0, 104.5, 22.0 ],
					"style" : "",
					"text" : "scale 0 127 -70 0"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-14",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 140.030212, 143.0, 76.0, 22.0 ],
					"style" : "",
					"text" : "loadmess -6"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-102",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 415.0, 373.5, 68.0, 22.0 ],
					"style" : "",
					"text" : "round 0.01"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-99",
					"maxclass" : "newobj",
					"numinlets" : 6,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 415.0, 332.5, 125.0, 22.0 ],
					"style" : "",
					"text" : "scale 0 127 0.94 1.06"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-98",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 415.0, 408.0, 175.0, 19.0 ],
					"style" : "",
					"text" : "/dx7/global/bend $1"
				}

			}
, 			{
				"box" : 				{
					"channels" : 1,
					"id" : "obj-37",
					"maxclass" : "live.gain~",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "signal", "", "float", "list" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 14.0, 135.0, 48.0, 118.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 227.0, 3.0, 45.0, 192.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "live.gain~",
							"parameter_shortname" : "Gain",
							"parameter_type" : 0,
							"parameter_mmin" : -70.0,
							"parameter_mmax" : 6.0,
							"parameter_initial" : [ 0.0 ],
							"parameter_unitstyle" : 4
						}

					}
,
					"varname" : "live.gain~"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-32",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 7,
							"minor" : 3,
							"revision" : 5,
							"architecture" : "x86",
							"modernui" : 1
						}
,
						"rect" : [ 460.0, 79.0, 533.0, 723.0 ],
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
						"boxes" : [ 							{
								"box" : 								{
									"args" : [ "#1" ],
									"bgmode" : 0,
									"border" : 0,
									"clickthrough" : 0,
									"enablehscroll" : 0,
									"enablevscroll" : 0,
									"id" : "obj-9",
									"lockeddragscroll" : 0,
									"maxclass" : "bpatcher",
									"name" : "dx7mono.maxpat",
									"numinlets" : 1,
									"numoutlets" : 1,
									"offset" : [ 0.0, 0.0 ],
									"outlettype" : [ "signal" ],
									"patching_rect" : [ 20.0, 63.0, 302.0, 778.0 ],
									"varname" : "dx7mono",
									"viewvisibility" : 1
								}

							}
, 							{
								"box" : 								{
									"comment" : "",
									"id" : "obj-5",
									"index" : 1,
									"maxclass" : "outlet",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 20.0, 872.0, 30.0, 30.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"comment" : "",
									"id" : "obj-3",
									"index" : 1,
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 20.0, 9.0, 30.0, 30.0 ],
									"style" : ""
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-9", 0 ],
									"source" : [ "obj-3", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-5", 0 ],
									"source" : [ "obj-9", 0 ]
								}

							}
 ],
						"styles" : [ 							{
								"name" : "newobjYellow-1",
								"default" : 								{
									"fontsize" : [ 12.059008 ],
									"accentcolor" : [ 0.82517, 0.78181, 0.059545, 1.0 ]
								}
,
								"parentstyle" : "",
								"multi" : 0
							}
, 							{
								"name" : "numberGold-1",
								"default" : 								{
									"accentcolor" : [ 0.764706, 0.592157, 0.101961, 1.0 ]
								}
,
								"parentstyle" : "",
								"multi" : 0
							}
 ]
					}
,
					"patching_rect" : [ 14.0, 79.0, 70.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"globalpatchername" : "",
						"style" : "",
						"tags" : ""
					}
,
					"style" : "",
					"text" : "p dx7mono",
					"varname" : "dx7"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-35",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 351.0, 187.0, 135.0, 22.0 ],
					"style" : "",
					"text" : "sprintf loadPreset %i #1"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.702269, 0.811747, 0.303388, 1.0 ],
					"id" : "obj-34",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 351.0, 222.0, 81.0, 22.0 ],
					"style" : "",
					"text" : "s #1-dx7bank"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.702269, 0.811747, 0.303388, 1.0 ],
					"id" : "obj-33",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 777.5, 108.0, 79.0, 22.0 ],
					"style" : "",
					"text" : "r #1-dx7bank"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-28",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 351.0, 114.0, 63.0, 22.0 ],
					"style" : "",
					"text" : "sprintf %s"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.702269, 0.811747, 0.303388, 1.0 ],
					"id" : "obj-22",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 351.0, 81.0, 105.0, 22.0 ],
					"style" : "",
					"text" : "r #1-menuPresets"
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 14.0,
					"id" : "obj-15",
					"items" : [ "Bass", ">", "Bass", ",", "Bass", ">", "BassSynt", ",", "Bass", ">", "DiscBass", ",", "Bass", ">", "Funkbass", ",", "Bass", ">", "Kalimbass", ",", "Bass", ">", "Pastorius", ",", "Bass", ">", "SlapBass", ",", "Bass", ">", "Sunrise", ",", "Bass", ">", "WalkBass", ",", "Bass", ">", "PerBass", ",", "Bass", ">", "HardBass", ",", "Bass", ">", "0UTMAINSSS", ",", "Bass", ">", "18V2LOW", ",", "Bass", ">", "2Cool2Fret", ",", "Bass", ">", "2MOOGER", ",", "Bass", ">", "2NDBASS", ",", "Bass", ">", "3BYO", ",", "Bass", ">", "50GALBASS", ",", "Bass", ">", "ACBASS2", ",", "Bass", ">", "AcBass5", ",", "Bass", ">", "Acoustic4", ",", "Bass", ">", "Acoustic4", ",", "Bass", ">", "BASICBASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS", ",", "Bass", ">", "BASS6", ",", "Bass", ">", "BASS1", ",", "Bass", ">", "BASS3", ",", "Bass", ">", "BASSAFRCA", ",", "Bass", ">", "BASSAFRCA", ",", "Bass", ">", "BASSBM", ",", "Bass", ">", "BASSCOMBO", ",", "Bass", ">", "BASSFLANG", ",", "Bass", ">", "BASSFLANG", ",", "Bass", ">", "BASSFLANG", ",", "Bass", ">", "Bassflatw", ",", "Bass", ">", "BASSFLNG3", ",", "Bass", ">", "BASSFLNG5", ",", "Bass", ">", "BASSFLNG6", ",", "Bass", ">", "Bassfunk", ",", "Bass", ">", "BASSGITAR", ",", "Bass", ">", "BASSGROWL", ",", "Bass", ">", "BassGuitr", ",", "Bass", ">", "BASSLINE", ",", "Bass", ">", "BASSMOD3", ",", "Bass", ">", "BASSONE", ",", "Bass", ">", "BASSPULSE", ",", "Bass", ">", "basspunch", ",", "Bass", ">", "BASSPUSH", ",", "Bass", ">", "BASSPUSH2", ",", "Bass", ">", "BASSROTO", ",", "Bass", ">", "BassSlap", ",", "Bass", ">", "BassSyn", ",", "Bass", ">", "BASSSYNTH", ",", "Bass", ">", "BASSTHUMB", ",", "Bass", ">", "BassBras1", ",", "Bass", ">", "BassGuit1", ",", "Bass", ">", "BassSyn1", ",", "Bass", ">", "BassSyn2", ",", "Bass", ">", "BASSICE", ",", "Bass", ">", "Bass1", ",", "Bass", ">", "BASSEP2", ",", "Bass", ">", "BASSEP3", ",", "Bass", ">", "BASSEP4", ",", "Bass", ">", "BASSEP5", ",", "Bass", ">", "BASSPIA1", ",", "Bass", ">", "BASSPIANO", ",", "Bass", ">", "BassStrgs", ",", "Bass", ">", "BassSyn1", ",", "Bass", ">", "BassSyn2", ",", "Bass", ">", "BassMoog5", ",", "Bass", ">", "BASS1", ",", "Bass", ">", "BASS1EDBOW", ",", "Bass", ">", "BASS2PULZ", ",", "Bass", ">", "BASSAIRMAN", ",", "Bass", ">", "BASSBALLS", ",", "Bass", ">", "BASSBAR", ",", "Bass", ">", "BassBass1", ",", "Bass", ">", "BASSCC2", ",", "Bass", ">", "BASSCHORUS", ",", "Bass", ">", "BASSdb1", ",", "Bass", ">", "BASSdb2", ",", "Bass", ">", "BASSdb3", ",", "Bass", ">", "BASSKBPZ", ",", "Bass", ">", "BassKeys", ",", "Bass", ">", "BASSMALIT1", ",", "Bass", ">", "BASSMOVIE", ",", "Bass", ">", "BASSNASS", ",", "Bass", ">", "BASSPRES", ",", "Bass", ">", "BASSRESWP", ",", "Bass", ">", "BASSRESWP", ",", "Bass", ">", "BASSSTRAT", ",", "Bass", ">", "BASSSTRAT", ",", "Bass", ">", "BassSUCK", ",", "Bass", ">", "BASSSYNTH", ",", "Bass", ">", "BASSSYNTH", ",", "Bass", ">", "BASSTHING", ",", "Bass", ">", "BB2KBASS", ",", "Bass", ">", "BeatBass", ",", "Bass", ">", "BeatlBass1", ",", "Bass", ">", "BeatlBass2", ",", "Bass", ">", "BEEFBASS", ",", "Bass", ">", "BEEFPOP", ",", "Bass", ">", "BELLBASS", ",", "Bass", ">", "BestBass", ",", "Bass", ">", "BigBassS3", ",", "Bass", ">", "BLASSEDIT", ",", "Bass", ">", "BLASSEDM", ",", "Bass", ">", "Blockbass", ",", "Bass", ">", "BOBSBASS", ",", "Bass", ">", "BONEBASS", ",", "Bass", ">", "BOWEDBASS1", ",", "Bass", ">", "BOWEDBASS2", ",", "Bass", ">", "BOWEDBASS3", ",", "Bass", ">", "Brainacus", ",", "Bass", ">", "Brainacus0", ",", "Bass", ">", "Brainacus2", ",", "Bass", ">", "Brainacus7", ",", "Bass", ">", "BRUSHEDBS", ",", "Bass", ">", "BsAnna3", ",", "Bass", ">", "BsAnna5", ",", "Bass", ">", "BsAnna1a", ",", "Bells", ">", "BELL1", ",", "Bells", ">", "BELL2", ",", "Bells", ">", "BELL4", ",", "Bells", ">", "BELL5", ",", "Bells", ">", "BELL7", ",", "Bells", ">", "BELL8", ",", "Bells", ">", "BELL9", ",", "Bells", ">", "BELL10", ",", "Bells", ">", "BELLS11", ",", "Bells", ">", "BELLS12", ",", "Bells", ">", "BELLS13", ",", "Bells", ">", "BELLS14", ",", "Bells", ">", "BELLO2", ",", "Bells", ">", "BELLO3", ",", "Bells", ">", "BELLO4", ",", "Bells", ">", "BELLVOICE", ",", "Bells", ">", "BELLZJG", ",", "Bells", ">", "BELLZJG2", ",", "Bells", ">", "ADHATTERc", ",", "Bells", ">", "BELLTREE", ",", "Bells", ">", "BELLSTOO", ",", "Bells", ">", "BELZOFIRE", ",", "Bells", ">", "BIGBEN", ",", "Bells", ">", "BRONZEAGE", ",", "Bells", ">", "DREAMBELL", ",", "Bells", ">", "FROZENTIME", ",", "Bells", ">", "GLOCK", ",", "Bells", ">", "GLOKENSPL", ",", "Bells", ">", "GONG", ",", "Bells", ">", "GONG1", ",", "Bells", ">", "GONG2", ",", "Bells", ">", "GREATBELS", ",", "Bells", ">", "BelChunk1", ",", "Bells", ">", "BelChunk2", ",", "Bells", ">", "BelChunk3", ",", "Bells", ">", "BelChunk4", ",", "Bells", ">", "Belashun1", ",", "Bells", ">", "Belashun2", ",", "Bells", ">", "Belashun3", ",", "Bells", ">", "AditvBel2", ",", "Bells", ">", "AditvBel3", ",", "Bells", ">", "AditvBel4", ",", "Bells", ">", "AditvBel5", ",", "Bells", ">", "AditvBel6", ",", "Bells", ">", "AditvBel7", ",", "Bells", ">", "EchoEcho1", ",", "Bells", ">", "EchoEcho2", ",", "Bells", ">", "EchoEcho3", ",", "Bells", ">", "EchoEcho4", ",", "Bells", ">", "EchoEcho5", ",", "Bells", ">", "RodeBell1", ",", "Bells", ">", "RodeBell2", ",", "Bells", ">", "RodeBell3", ",", "Bells", ">", "RodeBell4", ",", "Bells", ">", "SwishBel1", ",", "Bells", ">", "SwishBel2", ",", "Bells", ">", "SwishBel3", ",", "Bells", ">", "Modulashn1", ",", "Bells", ">", "Modulashn2", ",", "Bells", ">", "ArpgRvrs1", ",", "Bells", ">", "ArpgRvrs2", ",", "Bells", ">", "ELLO2X", ",", "Bells", ">", "ELLO3", ",", "Bells", ">", "ELLO4c", ",", "Bells", ">", "HANDBELL1", ",", "Bells", ">", "HANDBELL2", ",", "Bells", ">", "JUNGLEBELL", ",", "Bells", ">", "MADHATTER", ",", "Bells", ">", "PURGATORY", ",", "Bells", ">", "SWELLBELL", ",", "Bells", ">", "SWISHBELL", ",", "Bells", ">", "TOYBOX", ",", "Bells", ">", "TUBERUPT", ",", "Bells", ">", "TUBERISEA", ",", "Bells", ">", "TUBERISEB", ",", "Bells", ">", "TUNEDBELL", ",", "Bells", ">", "STEELDM1", ",", "Bells", ">", "STEELDR2", ",", "Bells", ">", "CELESTE1", ",", "Bells", ">", "CELESTE2", ",", "Bells", ">", "76BELLS", ",", "Bells", ">", "HALLOWIN", ",", "Bells", ">", "OYBOXZ", ",", "Bells", ">", "REATBELSc", ",", "Bells", ">", "ROZENTIMER", ",", "Bells", ">", "CHRISTMAS", ",", "Bells", ">", "ChorBel1", ",", "Bells", ">", "K", ",", "Bells", ">", "STRINGBELL", ",", "Bells", ">", "TRSE163", ",", "Bells", ">", "TTRP223", ",", "Bells", ">", "TBLEXP2", ",", "Bells", ">", "TDBLS323", ",", "Bells", ">", "AnnaBel1", ",", "Bells", ">", "ArpEdgEo1", ",", "Bells", ">", "VIBES1", ",", "Brass", ">", "8BrsHM", ",", "Brass", ">", "NewSctHM", ",", "Brass", ">", "VelPolHM", ",", "Brass", ">", "GateSnHM", ",", "Brass", ">", "PolyfsHM", ",", "Brass", ">", "BirdldHM", ",", "Brass", ">", "PolytnHM", ",", "Brass", ">", "FolderHM", ",", "Brass", ">", "Brass", ",", "Brass", ">", "BrassREV7", ",", "Brass", ">", "BrassREV7", ",", "Brass", ">", "Brass3REV7", ",", "Brass", ">", "BrassRev2", ",", "Brass", ">", "Brass5", ",", "Brass", ">", "BrassLead1", ",", "Brass", ">", "BayBrass", ",", "Brass", ">", "FatBrass", ",", "Brass", ">", "TrumpetB", ",", "Brass", ">", "LayerBrass", ",", "Brass", ">", "Fanfare", ",", "Brass", ">", "StabBrass", ",", "Brass", ">", "StabBrass2", ",", "Brass", ">", "StabBrass3", ",", "Brass", ">", "ReverbBras", ",", "Brass", ">", "SynBrass", ",", "Brass", ">", "MellowHorn", ",", "Brass", ">", "MellowHorn", ",", "Brass", ">", "Synbrass9", ",", "Brass", ">", "SilvaBrass", ",", "Brass", ">", "SilvaTrmpt", ",", "Brass", ">", "TouchBrass", ",", "Brass", ">", "WahBrass", ",", "Brass", ">", "HORNS7", ",", "Brass", ">", "HORNS8", ",", "Brass", ">", "BCBRSENSM", ",", "Brass", ">", "BACKBRAS1", ",", "Brass", ">", "BASSBRASS", ",", "Brass", ">", "BHORN96", ",", "Brass", ">", "BHRN235", ",", "Brass", ">", "BTRP58", ",", "Brass", ">", "HORNS238", ",", "Brass", ">", "BHORN95", ",", "Brass", ">", "HOWAN1", ",", "Brass", ">", "HOWAN2", ",", "Brass", ">", "HRNSFOURU", ",", "Brass", ">", "IBRASS1", ",", "Brass", ">", "BachNew", ",", "Brass", ">", "BachNew2", ",", "Brass", ">", "KBRASS8", ",", "Brass", ">", "KBRASS10", ",", "Brass", ">", "KOBRASS3", ",", "Brass", ">", "KRUMHORN1", ",", "Brass", ">", "LEDBRS5", ",", "Brass", ">", "LEDBRS6", ",", "Brass", ">", "LOBRASS", ",", "Brass", ">", "LOGBRSII", ",", "Brass", ">", "JAZZTRUMP", ",", "Brass", ">", "LOWSYNBRS2", ",", "Brass", ">", "LYRICONBC", ",", "Brass", ">", "LYRICON1BC", ",", "Brass", ">", "LYRICON2BC", ",", "Brass", ">", "MHORN93", ",", "Brass", ">", "MHORN94", ",", "Brass", ">", "MHRN236", ",", "Brass", ">", "RDSTRMPT", ",", "Brass", ">", "BRASS", ",", "Brass", ">", "PERCHORNS", ",", "Brass", ">", "HORNOLKY", ",", "Brass", ">", "CS80BRSA", ",", "Brass", ">", "ROBINHOOD", ",", "Brass", ">", "BRASSINCAN", ",", "Brass", ">", "SYNTHBRASS", ",", "Brass", ">", "SYNBRASS1", ",", "Brass", ">", "SYNTBRASS", ",", "Brass", ">", "SYNBRASS", ",", "Brass", ">", "SYNTHBRASS", ",", "Brass", ">", "SYNTHBRASS", ",", "Brass", ">", "SPLIT1", ",", "Brass", ">", "SYNBRASS1", ",", "Brass", ">", "SYNBRASS1", ",", "Brass", ">", "SYNBRASS1", ",", "Brass", ">", "SYNBRS1A", ",", "Brass", ">", "SYNBRS2A", ",", "Brass", ">", "STUDIOBRS", ",", "Brass", ">", "SPLATBRS5", ",", "Brass", ">", "SPLATBRS5", ",", "Brass", ">", "SPLATBRAS5", ",", "Brass", ">", "SYNBRASSDW", ",", "Brass", ">", "RHYTMBRAS", ",", "Brass", ">", "ATAKBRASS", ",", "Brass", ">", "POSAUNEN", ",", "Brass", ">", "STRUMPET", ",", "Brass", ">", "BASSHORNS", ",", "Brass", ">", "PERCHORN", ",", "Brass", ">", "BRASS2", ",", "Brass", ">", "BRASS1", ",", "Brass", ">", "SYNBRASSM", ",", "Brass", ">", "4WAYHIPS", ",", "Brass", ">", "AFRCHRN1", ",", "Brass", ">", "AFRICA1", ",", "Brass", ">", "AFRICA2", ",", "Brass", ">", "AFRICABR1", ",", "Brass", ">", "BRASSED1", ",", "Brass", ">", "BRASSENS", ",", "Brass", ">", "BRASSED", ",", "Brass", ">", "BASSBRSS1", ",", "Brass", ">", "BASSBRSS2", ",", "Brass", ">", "BRASS6BC", ",", "Brass", ">", "BRASSHORNS", ",", "Brass", ">", "BRASSCHORS", ",", "Brass", ">", "CHORUSBRS", ",", "Brass", ">", "EBRASS1", ",", "Brass", ">", "EBRASS2", ",", "Brass", ">", "FANFAREA", ",", "Brass", ">", "FANFARE2", ",", "Brass", ">", "FANFARE2b", ",", "Brass", ">", "FANFAREH1", ",", "Brass", ">", "JAPAN", ",", "Brass", ">", "JAZZ3BRAZZ", ",", "Brass", ">", "LOWBRASS", ",", "Brass", ">", "MONSTERPAD", ",", "Brass", ">", "METBRASS1", ",", "Brass", ">", "NEWBRASS", ",", "Brass", ">", "PECBRASS", ",", "Brass", ">", "PERCBRASS", ",", "Brass", ">", "WITEBRASS", ",", "Brass", ">", "AMBRASSADR", ",", "Brass", ">", "DXBRASSA", ",", "Brass", ">", "BRASS5THS", ",", "Brass", ">", "HORNS1", ",", "Brass", ">", "HORNS2", ",", "Brass", ">", "BRASS26", ",", "Brass", ">", "HORNS3", ",", "Brass", ">", "BRASS8", ",", "Brass", ">", "BRASS10", ",", "Brass", ">", "BRASS12", ",", "Brass", ">", "BRASS20", ",", "Brass", ">", "BRASS24", ",", "Brass", ">", "BRASSEN1", ",", "Brass", ">", "BRASSEN3", ",", "Brass", ">", "BRASSA", ",", "Brass", ">", "BRASS3A", ",", "Brass", ">", "BRASSCA5", ",", "Brass", ">", "ICEBRASS", ",", "Brass", ">", "SYNBRAY2", ",", "Brass", ">", "BRASSSECS", ",", "Brass", ">", "BRGTBRASS", ",", "Brass", ">", "HORNS4", ",", "Brass", ">", "EMRSNTRPT", ",", "Brass", ">", "SYNTRUMPET", ",", "Brass", ">", "CONTRAFASS", ",", "Brass", ">", "HOTBCKS3", ",", "Brass", ">", "HORNS5", ",", "Brass", ">", "SOLOTBONE", ",", "Brass", ">", "WBRASSX4C", ",", "Brass", ">", "JAZZBRAZZ", ",", "Brass", ">", "BRASSMA", ",", "Brass", ">", "LRITBRAS", ",", "Brass", ">", "MODEBRM", ",", "Brass", ">", "BLASPERC", ",", "Chimes", ">", "KC", ",", "Chimes", ">", "KC", ",", "Chimes", ">", "KC", ",", "Chimes", ">", "KC", ",", "Clavinet", ">", "BELLCLAV1", ",", "Clavinet", ">", "BELLCLAV2", ",", "Clavinet", ">", "BELLCLAV2", ",", "Clavinet", ">", "CLAV1", ",", "Clavinet", ">", "CLAV1", ",", "Clavinet", ">", "CLAV1", ",", "Clavinet", ">", "CLAV1", ",", "Clavinet", ">", "CLAV1A", ",", "Clavinet", ">", "CLAV2", ",", "Clavinet", ">", "CLAV3", ",", "Clavinet", ">", "CLAV3", ",", "Clavinet", ">", "CLAV4", ",", "Clavinet", ">", "CLAV6", ",", "Clavinet", ">", "CLAV7", ",", "Clavinet", ">", "CLAV9", ",", "Clavinet", ">", "CLAV10", ",", "Clavinet", ">", "CLAV12", ",", "Clavinet", ">", "CLAV13", ",", "Clavinet", ">", "CLAV14", ",", "Clavinet", ">", "CLAV15", ",", "Clavinet", ">", "CLAV16", ",", "Clavinet", ">", "CLAV17", ",", "Clavinet", ">", "CLAV18", ",", "Clavinet", ">", "CLAV19", ",", "Clavinet", ">", "CLAV20", ",", "Clavinet", ">", "CLAV23", ",", "Clavinet", ">", "CLAV24", ",", "Clavinet", ">", "CLAV25", ",", "Clavinet", ">", "CLAV26", ",", "Clavinet", ">", "CLAV27", ",", "Clavinet", ">", "CLAV28", ",", "Clavinet", ">", "CLAV29", ",", "Clavinet", ">", "CLAV32", ",", "Clavinet", ">", "CLAV34", ",", "Clavinet", ">", "CLAV37", ",", "Clavinet", ">", "CLAV41", ",", "Clavinet", ">", "CLAV44", ",", "Clavinet", ">", "CLAV45", ",", "Clavinet", ">", "CLAVCD", ",", "Clavinet", ">", "CLAV138", ",", "Clavinet", ">", "CLAV1", ",", "Clavinet", ">", "CLAV1EG", ",", "Clavinet", ">", "CLAV10", ",", "Clavinet", ">", "CLAV15", ",", "Clavinet", ">", "CLAV4", ",", "Clavinet", ">", "CLAVENS", ",", "Clavinet", ">", "CLAVENS1", ",", "Clavinet", ">", "CLAVENS2", ",", "Clavinet", ">", "CLAVENS3", ",", "Clavinet", ">", "CLAVWARP", ",", "Clavinet", ">", "Clav", ",", "Clavinet", ">", "CLAVA", ",", "Clavinet", ">", "CLAVB", ",", "Clavinet", ">", "CLAV2B", ",", "Clavinet", ">", "CLAV176", ",", "Clavinet", ">", "CLAV1B", ",", "Clavinet", ">", "CLAV291", ",", "Clavinet", ">", "CLAVTOOTS", ",", "Clavinet", ">", "CLAVBRASA", ",", "Clavinet", ">", "CLAVBRASS", ",", "Clavinet", ">", "CLAVCOMP", ",", "Clavinet", ">", "Clavdroid", ",", "Clavinet", ">", "CLAVEPNO", ",", "Clavinet", ">", "CLAVEPNO", ",", "Clavinet", ">", "CLAVEPNO", ",", "Clavinet", ">", "CLAVES", ",", "Clavinet", ">", "CLAVFLANGE", ",", "Clavinet", ">", "Clavi1", ",", "Clavinet", ">", "CLAVI1", ",", "Clavinet", ">", "CLAVI1", ",", "Clavinet", ">", "CLAVI2", ",", "Clavinet", ">", "CLAVI3", ",", "Clavinet", ">", "CLAVI4", ",", "Clavinet", ">", "CLAVICLE", ",", "Clavinet", ">", "CLAVINEAT1", ",", "Clavinet", ">", "CLAVINET", ",", "Clavinet", ">", "CLAVINET", ",", "Clavinet", ">", "CLAVINET", ",", "Clavinet", ">", "CLAVINET", ",", "Clavinet", ">", "Clavinet", ",", "Clavinet", ">", "CLAVINET1", ",", "Clavinet", ">", "CLAVINET3", ",", "Clavinet", ">", "CLAVINET4", ",", "Clavinet", ">", "CLAVINET5", ",", "Clavinet", ">", "Clavinette", ",", "Clavinet", ">", "Clavinette", ",", "Clavinet", ">", "CLAVINETTO", ",", "Clavinet", ">", "Clavinolda", ",", "Clavinet", ">", "ClaviPluck", ",", "Clavinet", ">", "ClaviStuff", ",", "Clavinet", ">", "ClaviStuff", ",", "Clavinet", ">", "CLAVMET", ",", "Clavinet", ">", "CLAVOICE", ",", "Clavinet", ">", "CLAVOS", ",", "Clavinet", ">", "CLAVPIANO", ",", "Clavinet", ">", "CLAVRHDS1", ",", "Clavinet", ">", "clavsyn4", ",", "Clavinet", ">", "COSCLAVI2", ",", "Clavinet", ">", "COSCLAVI2", ",", "Clavinet", ">", "CS80CLAV", ",", "Clavinet", ">", "DX9CLAV1", ",", "Clavinet", ">", "DX9CLAV2", ",", "Clavinet", ">", "ECLAV1", ",", "Clavinet", ">", "ECLAV2", ",", "Clavinet", ">", "ECLAV3", ",", "Clavinet", ">", "EKKOCLAV", ",", "Clavinet", ">", "FRENCHDBL", ",", "Clavinet", ">", "FRETTCLAV", ",", "Clavinet", ">", "FULLCLAV", ",", "Clavinet", ">", "FUNKCLAV", ",", "Clavinet", ">", "FUNKCLAV2", ",", "Clavinet", ">", "FUNKCLAV4", ",", "Clavinet", ">", "FUNKYCLAV", ",", "Clavinet", ">", "FUNKYCLV1", ",", "Clavinet", ">", "FUZZCLAV", ",", "Clavinet", ">", "FUZZCLAVA", ",", "Clavinet", ">", "GRANDCLAV", ",", "Clavinet", ">", "GRANDCLAV", ",", "Clavinet", ">", "GUNGADIN", ",", "Clavinet", ">", "HOTCLAV", ",", "Clavinet", ">", "HotrodClav", ",", "Clavinet", ">", "ICECLAV", ",", "Clavinet", ">", "JEFFSCLAV1", ",", "Clavinet", ">", "JEFFSCLAV2", ",", "Clavinet", ">", "JEFFSCLAV3", ",", "Clavinet", ">", "JLCLAV1", ",", "Clavinet", ">", "JLCLAV2", ",", "Clavinet", ">", "JLCLAV3", ",", "Clavinet", ">", "JLCLAV4", ",", "Clavinet", ">", "KCLAV1", ",", "Clavinet", ">", "KCLAV2", ",", "Clavinet", ">", "KCLAV3", ",", "Clavinet", ">", "LEADCLAV", ",", "Clavinet", ">", "LECTROCLAV", ",", "Clavinet", ">", "LSTCLSUP", ",", "Clavinet", ">", "MEDLXPRS1", ",", "Clavinet", ">", "MEDLXPRS3", ",", "Clavinet", ">", "MEDLXPRS3", ",", "Clavinet", ">", "MEDLXPRS4", ",", "Clavinet", ">", "MEDLXPRS5", ",", "Clavinet", ">", "MEDLXPRS6", ",", "Clavinet", ">", "MEDLXPRS8", ",", "Clavinet", ">", "MEDLXPRSV", ",", "Clavinet", ">", "MEDLXPRSV", ",", "Clavinet", ">", "METALCLAV", ",", "Clavinet", ">", "METALCLAV", ",", "Clavinet", ">", "MrTwang1", ",", "Clavinet", ">", "MrTwang2", ",", "Clavinet", ">", "MrTwang3", ",", "Clavinet", ">", "MrTwang4", ",", "Clavinet", ">", "MrTwang5", ",", "Clavinet", ">", "MUTEDCLAV", ",", "Clavinet", ">", "MUTEDCLV1", ",", "Clavinet", ">", "MUTEDCLV2", ",", "Clavinet", ">", "MUTEDCLV3", ",", "Clavinet", ">", "MutedClav", ",", "Clavinet", ">", "NCLAV325", ",", "Clavinet", ">", "P61CLAV", ",", "Clavinet", ">", "PERCCLAV2", ",", "Clavinet", ">", "PERCLAV", ",", "Drums", ">", "TOMS", ",", "Drums", ">", "3DDrums", ",", "Drums", ">", "Handclap1", ",", "Drums", ">", "Pauke", ",", "Drums", ">", "Simmons1", ",", "Drums", ">", "Simmons2", ",", "Drums", ">", "Syntoms", ",", "Drums", ">", "Tablas", ",", "Drums", ">", "Timbales", ",", "Drums", ">", "WoodDrum", ",", "Drums", ">", "BDRLOF", ",", "Drums", ">", "BDRMSNAR", ",", "Drums", ">", "BDRMSNAR", ",", "Drums", ">", "BASSDR1", ",", "Drums", ">", "BASSDR2", ",", "Drums", ">", "BASSDRUM", ",", "Drums", ">", "BASSDRUM", ",", "Drums", ">", "BassDrum1", ",", "Drums", ">", "BassDrum2", ",", "Drums", ">", "BEATMEHRDR", ",", "Drums", ">", "BLASPERC", ",", "Drums", ">", "BlechDrum", ",", "Drums", ">", "BONGA8", ",", "Drums", ">", "BONGAS10", ",", "Drums", ">", "Bongo2", ",", "Drums", ">", "BOOMGONG", ",", "Drums", ">", "BOTTLEA", ",", "Drums", ">", "BSSNRT0M", ",", "Drums", ">", "BUBBLEDRUM", ",", "Drums", ">", "CARGOHULL", ",", "Drums", ">", "CASTANET1", ",", "Drums", ">", "CASTANET1", ",", "Drums", ">", "CASTANETTE", ",", "Drums", ">", "Castenet", ",", "Drums", ">", "CASTENETS", ",", "Drums", ">", "CASTINET", ",", "Drums", ">", "CASTONETS", ",", "Drums", ">", "CHIGONGMW", ",", "Drums", ">", "CIMBAL", ",", "Drums", ">", "CIMBAL", ",", "Drums", ">", "CLACKER1", ",", "Drums", ">", "CLACKER2", ",", "Drums", ">", "CLANGMW", ",", "Drums", ">", "CLAP3", ",", "Drums", ">", "CLAP5", ",", "Drums", ">", "CLAPFING", ",", "Drums", ">", "CLAPS", ",", "Drums", ">", "CLKDRUM", ",", "Drums", ">", "CLOCKCHIME", ",", "Drums", ">", "CLOCKWORKS", ",", "Drums", ">", "conga1", ",", "Drums", ">", "CongaBongo", ",", "Drums", ">", "CONGACURRY", ",", "Drums", ">", "CongaDrum", ",", "Drums", ">", "CongaDrum", ",", "Drums", ">", "CONGALUNGA", ",", "Drums", ">", "CONGAS", ",", "Drums", ">", "CONGAS1", ",", "Drums", ">", "Congas2", ",", "Drums", ">", "ConGloq", ",", "Drums", ">", "COWBELL", ",", "Drums", ">", "COWBELL", ",", "Drums", ">", "COWBELL", ",", "Drums", ">", "COWBELL1", ",", "Drums", ">", "COWBELL1", ",", "Drums", ">", "COWBELL2", ",", "Drums", ">", "COWBELL3", ",", "Drums", ">", "Cowbell1", ",", "Drums", ">", "Cowbell2", ",", "Drums", ">", "CRASH1", ",", "Drums", ">", "CRASHCYMB", ",", "Drums", ">", "CRSHTIMPNI", ",", "Drums", ">", "CUBAFIBRE", ",", "Drums", ">", "CUICA", ",", "Drums", ">", "DLYTRIANL", ",", "Drums", ">", "DRUMNO1", ",", "Drums", ">", "DRUMNO2", ",", "Drums", ">", "DRUMMY", ",", "Drums", ">", "DRUMS", ",", "Drums", ">", "DRUMS", ",", "Drums", ">", "DRUMS1", ",", "Drums", ">", "DRUMSA", ",", "Drums", ">", "DRUMSB", ",", "Drums", ">", "DRUMSD", ",", "Drums", ">", "DRUMSE", ",", "Drums", ">", "DRUMTONA", ",", "Drums", ">", "DXKICKMO", ",", "Drums", ">", "DX9LOGDR", ",", "Drums", ">", "DX9STEEL", ",", "Drums", ">", "DXPERC", ",", "Drums", ">", "EchoToms", ",", "Drums", ">", "ELSCHLAGZ", ",", "Drums", ">", "ELECTGONG", ",", "Drums", ">", "GANKOGUI", ",", "Drums", ">", "GateMeTom4", ",", "Drums", ">", "HANDCLAP1", ",", "Drums", ">", "HANDCLAP2", ",", "Drums", ">", "HANDDRUM", ",", "Drums", ">", "HANDDRUM2", ",", "Drums", ">", "HANDCLAPMW", ",", "Drums", ">", "HANDGLOCK1", ",", "Drums", ">", "Handrum", ",", "Drums", ">", "HardTamb", ",", "Drums", ">", "HEXAGON1", ",", "Drums", ">", "HEXAGON2", ",", "Drums", ">", "HEXAGON3", ",", "Drums", ">", "HIHAT", ",", "Drums", ">", "HIHAT", ",", "Drums", ">", "HiHat1", ",", "Drums", ">", "HiHat2", ",", "Drums", ">", "HOLLOWBELL", ",", "Drums", ">", "HOOVES", ",", "Drums", ">", "ISLANDRUMS", ",", "Drums", ">", "JonZClap", ",", "Drums", ">", "JP8PWM", ",", "Drums", ">", "JPNDRUM1", ",", "Drums", ">", "JPNDRUM2", ",", "Drums", ">", "JPNDRUM3", ",", "Drums", ">", "JPNDRUM4", ",", "Drums", ">", "JugBand", ",", "Drums", ">", "KMETALS", ",", "Drums", ">", "KALIMBA", ",", "Drums", ">", "KALIMBA", ",", "Drums", ">", "KALIMBA", ",", "Drums", ">", "KALIMBA", ",", "Drums", ">", "KALIMBA2", ",", "Drums", ">", "KickSnrC2", ",", "Drums", ">", "LATINOS", ",", "Drums", ">", "LATNDRM2", ",", "Drums", ">", "LATNDRM4", ",", "Drums", ">", "LOGDR3AV", ",", "Drums", ">", "LOGDR5AV", ",", "Drums", ">", "LOGDRUM", ",", "Drums", ">", "LOGDRUM", ",", "Drums", ">", "LOGDRUM", ",", "Drums", ">", "LOGDRUM", ",", "Drums", ">", "LOGDRUM", ",", "Drums", ">", "LOGDRUMS", ",", "Drums", ">", "LOGDRUMV", ",", "Drums", ">", "LONGTOM", ",", "Drums", ">", "LOWDRM1", ",", "Drums", ">", "LOWDRM3", ",", "Drums", ">", "MacumbaHM", ",", "Drums", ">", "Maracas", ",", "Drums", ">", "MICHAEL", ",", "Drums", ">", "MIDDRM3", ",", "Drums", ">", "MIDDRM5", ",", "Drums", ">", "MOHAWKDRUM", ",", "Drums", ">", "MOUTHDRUM", ",", "Drums", ">", "MultiPerc", ",", "Drums", ">", "MYSTDRUM", ",", "Drums", ">", "NEWDRUM", ",", "Drums", ">", "NEWDRUMS", ",", "Drums", ">", "NEWTIMPANI", ",", "Drums", ">", "OpenHiHat", ",", "Drums", ">", "ORIDRUM1", ",", "Drums", ">", "ORIDRUM2", ",", "Drums", ">", "ORIDRUM3", ",", "Drums", ">", "ORIDRUM5", ",", "Drums", ">", "PERCEX2", ",", "Drums", ">", "PERCWATER", ",", "Drums", ">", "PERCWATER", ",", "Drums", ">", "PERCYCPIU", ",", "Drums", ">", "PERCOLATE", ",", "Drums", ">", "PERCUS2", ",", "Drums", ">", "PERCUS3", ",", "Drums", ">", "PERCUS4", ",", "Drums", ">", "Percusn1", ",", "Drums", ">", "PERCUSS1A", ",", "Drums", ">", "PERCUSS2A", ",", "Drums", ">", "PERCUSSION", ",", "Drums", ">", "PERCUSSIVE", ",", "Drums", ">", "PERCUSSIVE", ",", "Drums", ">", "PLUCKDRUM", ",", "Drums", ">", "PLUCKEDRUM", ",", "Drums", ">", "POLYPERC", ",", "Drums", ">", "QUIKSNAP", ",", "Drums", ">", "RADSDRUMS", ",", "Drums", ">", "RapBeat", ",", "Drums", ">", "RASTADRUM", ",", "Drums", ">", "REVCYMB1", ",", "Drums", ">", "REVCYMB2", ",", "Drums", ">", "ROTOTOMS", ",", "Drums", ">", "RotoToms", ",", "Drums", ">", "RUBBERDRUM", ",", "Drums", ">", "SDRUM3", ",", "Drums", ">", "SALVATION", ",", "Drums", ">", "SAMBAWHIS", ",", "Drums", ">", "SAMBAWHIS", ",", "Drums", ">", "SamplPerc", ",", "Drums", ">", "Shaker", ",", "Drums", ">", "SIEMENSDR", ",", "Drums", ">", "SIZCYMB", ",", "Drums", ">", "SIZLECYMB", ",", "Drums", ">", "Sleighbell", ",", "Drums", ">", "SNARE6", ",", "Drums", ">", "SNARE8", ",", "Drums", ">", "SNAREDR1", ",", "Drums", ">", "SNAREDR2", ",", "Drums", ">", "SnareShot", ",", "Drums", ">", "SnareSnp1", ",", "Drums", ">", "SNAREDRUM", ",", "Drums", ">", "SoftTamb", ",", "Drums", ">", "STARCYMB", ",", "Drums", ">", "STLDRM2", ",", "Drums", ">", "STLDRUM2", ",", "Drums", ">", "StpdancHM", ",", "Drums", ">", "STRUCKCAN", ",", "Drums", ">", "SYNDRUMS", ",", "Drums", ">", "SYNMARIM", ",", "Drums", ">", "SYNPERC1", ",", "Drums", ">", "SYNPERC2", ",", "Drums", ">", "SYNPERC3", ",", "Drums", ">", "SYNPERC4", ",", "Drums", ">", "SYNPERC5", ",", "Drums", ">", "SYNPERC6", ",", "Drums", ">", "SYNPERC7", ",", "Drums", ">", "SYNPERC7", ",", "Drums", ">", "SYNPERC8", ",", "Drums", ">", "SYNPERC9", ",", "Drums", ">", "SYNCHIME1", ",", "Drums", ">", "SYNCHIME2", ",", "Drums", ">", "SYNCHIME2", ",", "Drums", ">", "SYNCHIME3", ",", "Drums", ">", "SYNDRUM1", ",", "Drums", ">", "SYNDRUM1", ",", "Drums", ">", "SYNDRUM2", ",", "Drums", ">", "SYNDRUM2", ",", "Drums", ">", "SYNDRUMJ", ",", "Drums", ">", "Synergy4", ",", "Drums", ">", "SYNPERC01", ",", "Drums", ">", "SYNPERC02", ",", "Drums", ">", "TABLA", ",", "Drums", ">", "Tabla2", ",", "Drums", ">", "TALKINDRUM", ",", "Drums", ">", "TALKINGDRM", ",", "Drums", ">", "TALKINGDRM", ",", "Drums", ">", "TAMATECH1", ",", "Drums", ">", "TambTuned", ",", "Drums", ">", "tamborine1", ",", "Drums", ">", "Tambourin2", ",", "Drums", ">", "TAMBOURINE", ",", "Drums", ">", "TAMBOURINE", ",", "Drums", ">", "TAMBRN1", ",", "Drums", ">", "TAMBRN2", ",", "Drums", ">", "TempleGong", ",", "Drums", ">", "THWACKTOMS", ",", "Drums", ">", "TIMBALES1", ",", "Drums", ">", "Timbali", ",", "Drums", ">", "TIMBALI", ",", "Drums", ">", "TIMBALI1", ",", "Drums", ">", "TIMBALI1", ",", "Drums", ">", "TIMP", ",", "Drums", ">", "TLKDRUM3", ",", "Drums", ">", "TLKDRUM3", ",", "Drums", ">", "TOMDRUMS", ",", "Drums", ">", "TOMTOMS", ",", "Drums", ">", "TOMSM", ",", "Drums", ">", "TOMTOM1", ",", "Drums", ">", "TOMTOM2", ",", "Drums", ">", "TOMTOM2", ",", "Drums", ">", "TomTomTom", ",", "Drums", ">", "TRASHCAN", ",", "Drums", ">", "TRIAL", ",", "Drums", ">", "TRIANGEL", ",", "Drums", ">", "Triangle", ",", "Drums", ">", "TRIANGLE", ",", "Drums", ">", "Triangle", ",", "Drums", ">", "Triangle1", ",", "Drums", ">", "TRIANGLE1", ",", "Drums", ">", "Triangle2", ",", "Drums", ">", "TRIANGLE2", ",", "Drums", ">", "Triangles1", ",", "Drums", ">", "Triangles2", ",", "Drums", ">", "TUBPERC", ",", "Drums", ">", "WBLOCK1", ",", "Drums", ">", "WBLOCK2", ",", "Drums", ">", "WBlock1", ",", "Drums", ">", "WOODBLK2", ",", "Drums", ">", "WOODBLOCK", ",", "Drums", ">", "AUSIMONA", ",", "Drums", ">", "TAP", ",", "Drums", ">", "TAP2", ",", "Drums", ">", "Tympani1", ",", "Drums", ">", "Tympani2", ",", "Drums", ">", "Tympani6", ",", "Drums", ">", "Tympani7", ",", "Drums", ">", "WHIP", ",", "Drums", ">", "Simmons1", ",", "Drums", ">", "SKINMETAL", ",", "Drums", ">", "SKINMETAL", ",", "Drums", ">", "SKINMETAL", ",", "Drums", ">", "Skulls", ",", "Drums", ">", "SNAREDR4", ",", "Drums", ">", "SPARGLES", ",", "Drums", ">", "Spinetto", ",", "Drums", ">", "strange1", ",", "Drums", ">", "strange4", ",", "Drums", ">", "STXXXAV", ",", "Drums", ">", "Tamb4", ",", "Drums", ">", "Tamb7", ",", "Drums", ">", "Tamb8", ",", "Drums", ">", "Tamb10", ",", "Drums", ">", "Tambourin1", ",", "Drums", ">", "TapSlap1", ",", "Drums", ">", "TapSlap2", ",", "Drums", ">", "Timbale1", ",", "Drums", ">", "Timbale4", ",", "Drums", ">", "Timbale5", ",", "Drums", ">", "Timbale6", ",", "Drums", ">", "Timbale7", ",", "Drums", ">", "TINGOLIT", ",", "Drums", ">", "TINYNOISE", ",", "Drums", ">", "TomTom1", ",", "Drums", ">", "TomTom2", ",", "Drums", ">", "TomTom4", ",", "Drums", ">", "TomTom6", ",", "Drums", ">", "TomTom7", ",", "Drums", ">", "ROTOTOMS", ",", "Drums", ">", "TRUMPCard", ",", "Drums", ">", "ENGLISH02", ",", "Drums", ">", "KickDr3", ",", "Drums", ">", "Kodo6", ",", "Drums", ">", "Kodo7", ",", "Drums", ">", "Kodo8", ",", "Drums", ">", "Kodo9", ",", "Drums", ">", "Kodo10", ",", "Drums", ">", "Kodo11", ",", "Drums", ">", "Kodo12", ",", "Drums", ">", "Kodo13", ",", "Drums", ">", "MBLOK248", ",", "Drums", ">", "METALOPHO", ",", "Drums", ">", "MILKBOTTLE", ",", "Drums", ">", "Muted", ",", "Drums", ">", "New4", ",", "Drums", ">", "New15", ",", "Drums", ">", "PERCWATER", ",", "Drums", ">", "PERCWATER", ",", "Drums", ">", "PERCWATER", ",", "Drums", ">", "PERCWATER", ",", "Drums", ">", "PERCWATER", ",", "Drums", ">", "PERCWATER", ",", "Drums", ">", "PERCWATER", ",", "Drums", ">", "PERCWATER", ",", "Drums", ">", "PERCUSSION", ",", "Drums", ">", "PERCUSSION", ",", "Drums", ">", "PERLEG", ",", "Drums", ">", "Pluk2", ",", "Drums", ">", "RHYTHM", ",", "Drums", ">", "SampleV1", ",", "Drums", ">", "Scratch1", ",", "Drums", ">", "Scratch3", ",", "Drums", ">", "5THSBONK", ",", "Drums", ">", "Agogo2", ",", "Drums", ">", "Belltree1", ",", "Drums", ">", "Belltree3", ",", "Drums", ">", "Belltree4", ",", "Drums", ">", "Belltree5", ",", "Drums", ">", "BigDrum", ",", "Drums", ">", "Block1", ",", "Drums", ">", "Block2", ",", "Drums", ">", "Block3", ",", "Drums", ">", "Block5", ",", "Drums", ">", "Block7", ",", "Drums", ">", "Block8", ",", "Drums", ">", "Block9", ",", "Drums", ">", "Block11", ",", "Drums", ">", "Bongo1", ",", "Drums", ">", "Cabasa1", ",", "Drums", ">", "CLANG", ",", "Drums", ">", "Clap1", ",", "Drums", ">", "Clap3", ",", "Drums", ">", "Clap6", ",", "Drums", ">", "Claves", ",", "Drums", ">", "Conga2", ",", "Drums", ">", "Conga3", ",", "Drums", ">", "CONGAS4", ",", "Drums", ">", "CONGAS5", ",", "Drums", ">", "Cymbalrev3", ",", "Drums", ">", "Castanet1", ",", "Drums", ">", "Castanet2", ",", "Drums", ">", "CASTANET4", ",", "Effects", ">", "RUMBLE1", ",", "Effects", ">", "MALECHOIR", ",", "Effects", ">", "PIANOSTAIN", ",", "Effects", ">", "LIGHTNING", ",", "Effects", ">", "DYNOMIPNO", ",", "Effects", ">", "SLEEP", ",", "Effects", ">", "ERIESUSTN", ",", "Effects", ">", "rB", ",", "Effects", ">", "SHNOISDR", ",", "Effects", ">", "CLARKSPECL", ",", "Effects", ">", "VAPORSHD", ",", "Effects", ">", "so", ",", "Effects", ">", "WAVES", ",", "Effects", ">", "WHATTHE", ",", "Effects", ">", "FEMCHOIR", ",", "Effects", ">", "TUNDSTATIC", ",", "Effects", ">", "mBw", ",", "Effects", ">", "Bwwvsa", ",", "Effects", ">", "FLEXATONE", ",", "Effects", ">", "VocoderLd", ",", "Effects", ">", "INITVOICE", ",", "Effects", ">", "INITVOICE", ",", "Effects", ">", "HockyOrg1a", ",", "Effects", ">", "SayAgain", ",", "Effects", ">", "QwerDaLune", ",", "Effects", ">", "Lytening2", ",", "Effects", ">", "Synergy4", ",", "Effects", ">", "DigiPad1", ",", "Effects", ">", "LdSubHarm", ",", "Effects", ">", "INGMOD", ",", "Effects", ">", "Damaged", ",", "Effects", ">", "Damaged", ",", "Effects", ">", "Frogger", ",", "Effects", ">", "Helicopt", ",", "Effects", ">", "Jingle", ",", "Effects", ">", "Mafia", ",", "Effects", ">", "Mashine", ",", "Effects", ">", "Nervous", ",", "Effects", ">", "Noise", ",", "Effects", ">", "Ocean", ",", "Effects", ">", "Policecar", ",", "Effects", ">", "Scottys", ",", "Effects", ">", "Scratch", ",", "Effects", ">", "Splitclap", ",", "Effects", ">", "Tarantula", ",", "Effects", ">", "TheBeach", ",", "Effects", ">", "What", ",", "Effects", ">", "GONG", ",", "Effects", ">", "ZAPPP", ",", "Effects", ">", "GOTCHA", ",", "Effects", ">", "IceCaves", ",", "Effects", ">", "IceCaves", ",", "Effects", ">", "IceCaves", ",", "Effects", ">", "J", ",", "Effects", ">", "LAZER", ",", "Effects", ">", "Smash", ",", "Effects", ">", "SCRATCH", ",", "Effects", ">", "155Secefx", ",", "Effects", ">", "30NP", ",", "Effects", ">", "37G537MT", ",", "Effects", ">", "4OKNEW2A", ",", "Effects", ">", "4VCrsPluk", ",", "Effects", ">", "7TALKA", ",", "Effects", ">", "7TALKB", ",", "Effects", ">", "99DEGREES", ",", "Effects", ">", "ATALK", ",", "Effects", ">", "AFCE305", ",", "Effects", ">", "ABSTURZ", ",", "Effects", ">", "ABUASHRAM", ",", "Effects", ">", "Acmesiren", ",", "Effects", ">", "AFTERTRIM", ",", "Effects", ">", "AirFarce", ",", "Effects", ">", "ALARM", ",", "Effects", ">", "ALARM", ",", "Effects", ">", "ALTAIR4", ",", "Effects", ">", "ALUTEc", ",", "Effects", ">", "AMBULANCE", ",", "Effects", ">", "AppyBirDay", ",", "Effects", ">", "AREUINTR", ",", "Effects", ">", "ATTRing", ",", "Effects", ">", "b", ",", "Effects", ">", "BABYCAT", ",", "Effects", ">", "BALLOON", ",", "Effects", ">", "Bang1", ",", "Effects", ">", "Bang", ",", "Effects", ">", "BASH", ",", "Effects", ">", "BEAMMEUP", ",", "Effects", ">", "BEAMMEUP", ",", "Effects", ">", "BEAMER11", ",", "Effects", ">", "BEERBASH", ",", "Effects", ">", "BELLTOWER", ",", "Effects", ">", "BIGBEN", ",", "Effects", ">", "BIGBEN", ",", "Effects", ">", "BIGBEN3", ",", "Effects", ">", "BIGBEN6", ",", "Effects", ">", "BIGDUCK", ",", "Effects", ">", "BIRD1", ",", "Effects", ">", "BIRD2", ",", "Effects", ">", "BIRD3", ",", "Effects", ">", "BIRD4", ",", "Effects", ">", "BIRDMOD1", ",", "Effects", ">", "BIRDSrB", ",", "Effects", ">", "BIRDSONG", ",", "Effects", ">", "BLAHHHHH", ",", "Effects", ">", "BLAM", ",", "Effects", ">", "BLEAT1", ",", "Effects", ">", "Boingo", ",", "Effects", ">", "BOMBDROP", ",", "Effects", ">", "BOMBSAWAY", ",", "Effects", ">", "BRUSHES", ",", "Effects", ">", "BTWNCELLS", ",", "Effects", ">", "BUBBLES", ",", "Effects", ">", "BURGALARM", ",", "Effects", ">", "BURNING", ",", "Effects", ">", "BURRRRP", ",", "Effects", ">", "BUSY", ",", "Effects", ">", "Buzy", ",", "Effects", ">", "Buzz1", ",", "Effects", ">", "Bwwvsa", ",", "Effects", ">", "bX", ",", "Effects", ">", "c", ",", "Effects", ">", "c", ",", "Effects", ">", "CDEbF", ",", "Effects", ">", "CALLME", ",", "Effects", ">", "CARHORN", ",", "Effects", ">", "CARKEYS", ",", "Effects", ">", "CHANG", ",", "Effects", ">", "CHAUCHAU", ",", "Effects", ">", "CHOPLIFT", ",", "Effects", ">", "CHOPPERS", ",", "Effects", ">", "CHROMOSOME", ",", "Effects", ">", "CLARKSPECL", ",", "Effects", ">", "CLASHK", ",", "Effects", ">", "Clawier", ",", "Effects", ">", "COMPUTE", ",", "Effects", ">", "COMPUTER1", ",", "Effects", ">", "COZ", ",", "Effects", ">", "COZWIND", ",", "Effects", ">", "Crasher1", ",", "Effects", ">", "Crasher2", ",", "Effects", ">", "CREATURES", ",", "Effects", ">", "CRIMI1M", ",", "Effects", ">", "CRIMI2M", ",", "Effects", ">", "CROSSING", ",", "Effects", ">", "DTALK", ",", "Effects", ">", "DaleTrail2", ",", "Effects", ">", "DelaydXplo", ",", "Effects", ">", "DEPARTURE", ",", "Effects", ">", "DESCENT", ",", "Effects", ">", "DESCENT", ",", "Effects", ">", "DESCENT", ",", "Effects", ">", "DESCENT", ",", "Effects", ">", "DialTone", ",", "Effects", ">", "DIALTONE", ",", "Effects", ">", "DIGIBIRD", ",", "Effects", ">", "DISGUSTING", ",", "Effects", ">", "DOG", ",", "Effects", ">", "DOORBELSS", ",", "Effects", ">", "DORBEL1", ",", "Effects", ">", "DORBEL2", ",", "Effects", ">", "DOWNSLIDE", ",", "Effects", ">", "DRIPORD", ",", "Effects", ">", "DRIPPING", ",", "Effects", ">", "EFFECT3A", ",", "Effects", ">", "ENVELOPES", ",", "Effects", ">", "EQUINOX", ",", "Effects", ">", "EVILTONE", ",", "Effects", ">", "EXPLOCLAP", ",", "Effects", ">", "EXPLOS2A", ",", "Effects", ">", "EXPLOSION", ",", "Effects", ">", "EXPLOSION", ",", "Effects", ">", "EXPLOSION", ",", "Effects", ">", "EXPLOSION1", ",", "Effects", ">", "EXPLOSION2", ",", "Effects", ">", "FACTORY", ",", "Effects", ">", "FIFTHS", ",", "Effects", ">", "FingerClp", ",", "Effects", ">", "Flexatone", ",", "Effects", ">", "FLEXATONE", ",", "Effects", ">", "FLEXATONE", ",", "Effects", ">", "FLEXI4", ",", "Effects", ">", "FLTMIN3RDS", ",", "Effects", ">", "FLY", ",", "Effects", ">", "FMINST1", ",", "Effects", ">", "FMINST2", ",", "Effects", ">", "GLASS2", ",", "Effects", ">", "GostHiway1", ",", "Effects", ">", "GRANDPRIX", ",", "Effects", ">", "GRANDPRIX", ",", "Effects", ">", "GRUMPY", ",", "Effects", ">", "GUIRO", ",", "Effects", ">", "GURGLEHOG", ",", "Effects", ">", "HARDc", ",", "Effects", ">", "HATTER", ",", "Effects", ">", "HEARTBEAT", ",", "Effects", ">", "HeartBeet2", ",", "Effects", ">", "HEAVYRAIN", ",", "Effects", ">", "HELICOPTER", ",", "Effects", ">", "HELICOPTR", ",", "Effects", ">", "HELLFIREMW", ",", "Effects", ">", "HELLICHOPT", ",", "Effects", ">", "Hellinair", ",", "Effects", ">", "HERBIE", ",", "Effects", ">", "HERZSCHLA", ",", "Effects", ">", "HOGSLIDE", ",", "Effects", ">", "HORRORoofs", ",", "Effects", ">", "HOWLOFFq", ",", "Effects", ">", "HOWLOFFq", ",", "Effects", ">", "HUSKIES", ",", "Effects", ">", "IMAGE1", ",", "Effects", ">", "IMAGE2", ",", "Effects", ">", "IMAGE3", ",", "Effects", ">", "IMAGE4", ",", "Effects", ">", "IMAGE5", ",", "Effects", ">", "IMAGE6", ",", "Effects", ">", "IMAGE7", ",", "Effects", ">", "IMAGE8", ",", "Effects", ">", "IMAGE9", ",", "Effects", ">", "IMAGE10", ",", "Effects", ">", "IMAGE11", ",", "Effects", ">", "IMAGE12", ",", "Effects", ">", "IMAGE13", ",", "Effects", ">", "IMAGE14", ",", "Effects", ">", "INDUSTAV", ",", "Effects", ">", "INDUSTAV", ",", "Effects", ">", "INDUSTAV", ",", "Effects", ">", "INSECT1", ",", "Effects", ">", "INSECT2", ",", "Effects", ">", "INSECT3", ",", "Effects", ">", "INSECTVOC", ",", "Effects", ">", "Invaders", ",", "Effects", ">", "KABASA", ",", "Effects", ">", "KELLERTUER", ",", "Effects", ">", "KETTLE2", ",", "Effects", ">", "KETTLE6", ",", "Effects", ">", "KEVINTALKA", ",", "Effects", ">", "KEVINTALKB", ",", "Effects", ">", "KLAXON", ",", "Effects", ">", "KLIK", ",", "Effects", ">", "KoikeCycle", ",", "Effects", ">", "LA", ",", "Effects", ">", "LABORATORY", ",", "Effects", ">", "Landing", ",", "Effects", ">", "LASERGUN", ",", "Effects", ">", "LASERGUN", ",", "Effects", ">", "LASERSE1", ",", "Effects", ">", "LASERSE2", ",", "Effects", ">", "LASERSE3", ",", "Effects", ">", "LASER1", ",", "Effects", ">", "LASER2", ",", "Effects", ">", "LASER3", ",", "Effects", ">", "LASER4", ",", "Effects", ">", "LASER5", ",", "Effects", ">", "LASER6", ",", "Effects", ">", "LASER7", ",", "Effects", ">", "LASER8", ",", "Effects", ">", "LASERS2", ",", "Effects", ">", "LASERSWEP1", ",", "Effects", ">", "LASERSWEP2", ",", "Effects", ">", "LASERu", ",", "Effects", ">", "LASERXPLO1", ",", "Effects", ">", "LASERXPLO2", ",", "Effects", ">", "LIGHTNING", ",", "Effects", ">", "LOCOMOTIVE", ",", "Effects", ">", "LongTrain", ",", "Effects", ">", "Lytening", ",", "Effects", ">", "Lytening2", ",", "Effects", ">", "Lytening2", ",", "Effects", ">", "MACGUN1", ",", "Effects", ">", "MACGUN2", ",", "Effects", ">", "MACHINEGUN", ",", "Effects", ">", "MACHINES", ",", "Effects", ">", "MARTIANS", ",", "Effects", ">", "MENSCHESSE", ",", "Effects", ">", "MIAMIRISE", ",", "Effects", ">", "Mickeeeeee", ",", "Effects", ">", "MIRIDORN", ",", "Effects", ">", "MIRIDORN", ",", "Effects", ">", "MIRIDORPC", ",", "Effects", ">", "MOBILE1", ",", "Effects", ">", "MOBILE2", ",", "Effects", ">", "MOTOCROSS", ",", "Effects", ">", "MOTORCYCLE", ",", "Effects", ">", "MOTORCYCLE", ",", "Effects", ">", "MT", ",", "Effects", ">", "MUNSTER5", ",", "Effects", ">", "MURDER", ",", "Effects", ">", "NGULF", ",", "Effects", ">", "NOISE", ",", "Effects", ">", "NOISE14", ",", "Effects", ">", "NOISEWAVE", ",", "Effects", ">", "OUTTHERE", ",", "Effects", ">", "PGLASS", ",", "Effects", ">", "PATROLCAR", ",", "Effects", ">", "PBGONGA1", ",", "Effects", ">", "PHONERING", ",", "Effects", ">", "PHONERING", ",", "Effects", ">", "PHONETONE", ",", "Effects", ">", "PIPOPA", ",", "Effects", ">", "PIHP3AVAL", ",", "Effects", ">", "PLANE1", ",", "Effects", ">", "PLANE2", ",", "Effects", ">", "PLANEPART1", ",", "Effects", ">", "PREPAREDP", ",", "Effects", ">", "PRINCE", ",", "Effects", ">", "PRINCE", ",", "Effects", ">", "PRIXSHIFT", ",", "Effects", ">", "Quijada", ",", "Effects", ">", "QwerDaLune", ",", "Effects", ">", "r2d2", ",", "Effects", ">", "RADIKLCHUK", ",", "Effects", ">", "RandmNots1", ",", "Effects", ">", "RandmNots3", ",", "Effects", ">", "Randomoiz1", ",", "Effects", ">", "Randomoiz2", ",", "Effects", ">", "Randomoiz3", ",", "Effects", ">", "Randomoiz4", ",", "Effects", ">", "REFSWHISL", ",", "Effects", ">", "REVERS1", ",", "Effects", ">", "REVERS2", ",", "Effects", ">", "RICOCHETS", ",", "Effects", ">", "ROADRUNNER", ",", "Effects", ">", "RUMBEARTH", ",", "Effects", ">", "RUMBLE", ",", "Effects", ">", "Rumble1", ",", "Effects", ">", "RUMBLE1", ",", "Effects", ">", "SampleHold", ",", "Effects", ">", "SAUCERMW", ",", "Effects", ">", "SAUCER", ",", "Effects", ">", "SAWEMUP", ",", "Effects", ">", "SAWEMUP2", ",", "Effects", ">", "SAWEMUP3", ",", "Effects", ">", "SCHLAGZA", ",", "Effects", ">", "SCIENCE", ",", "Effects", ">", "SCIENCE", ",", "Effects", ">", "SCIENCE", ",", "Effects", ">", "SCIENCE22", ",", "Effects", ">", "SCIENCE26", ",", "Effects", ">", "SCIERIE", ",", "Effects", ">", "SclCorHM", ",", "Effects", ">", "SCRATCH1", ",", "Effects", ">", "SCRATCH2", ",", "Effects", ">", "SCRATCHME", ",", "Effects", ">", "SCRATCHIN1", ",", "Effects", ">", "SCREENDOOR", ",", "Effects", ">", "SEAVOICE", ",", "Effects", ">", "SHNOISDR", ",", "Effects", ">", "SHIMMER", ",", "Effects", ">", "SHIMMER", ",", "Effects", ">", "SHIMMER", ",", "Effects", ">", "SHIMMER3", ",", "Effects", ">", "SHOCK", ",", "Effects", ">", "SIREN", ",", "Effects", ">", "SIREN", ",", "Effects", ">", "Sldng5s", ",", "Effects", ">", "SLOMOWARS", ",", "Effects", ">", "SmuthFall1", ",", "Effects", ">", "SNDEFCT2", ",", "Effects", ">", "SPGHSHD", ",", "Effects", ">", "SPPITCH", ",", "Effects", ">", "SPA2AV", ",", "Effects", ">", "space", ",", "Effects", ">", "SPACECOMP", ",", "Effects", ">", "SPACEGHOL", ",", "Effects", ">", "SPACENOS2", ",", "Effects", ">", "SPACENOS4", ",", "Effects", ">", "SPACEOUT", ",", "Effects", ">", "SPACERACE", ",", "Effects", ">", "SPACESHOT", ",", "Effects", ">", "SPACESLID", ",", "Effects", ">", "SPACEWARS", ",", "Effects", ">", "SPACEOFF", ",", "Effects", ">", "SPACED", ",", "Effects", ">", "SPACENOIS3", ",", "Effects", ">", "SPACENOISE", ",", "Effects", ">", "SPACESHIPS", ",", "Effects", ">", "SPACEWAY", ",", "Effects", ">", "SPACEWELL", ",", "Effects", ">", "SPACYECHO", ",", "Effects", ">", "SpiEfx1", ",", "Effects", ">", "SpiEfx2", ",", "Effects", ">", "SPOOKY", ",", "Effects", ">", "SQUARED", ",", "Effects", ">", "STHELENS", ",", "Effects", ">", "STHELENS", ",", "Effects", ">", "StacHeav1", ",", "Effects", ">", "StacHeav2", ",", "Effects", ">", "StacHeavn", ",", "Effects", ">", "STARTREK", ",", "Effects", ">", "STARTREK", ",", "Effects", ">", "STINGII", ",", "Effects", ">", "STOCKHAUSN", ",", "Effects", ">", "STORM1", ",", "Effects", ">", "STORM2", ",", "Effects", ">", "STORMY", ",", "Effects", ">", "STRANGE", ",", "Effects", ">", "STRANGE1", ",", "Effects", ">", "SuessMguse", ",", "Effects", ">", "SUMOBELCH", ",", "Effects", ">", "SUPERFOOT", ",", "Effects", ">", "SUSTAINN", ",", "Effects", ">", "SWEEPUPHU", ",", "Effects", ">", "SWOOPEEEEY", ",", "Effects", ">", "SYNHRAT", ",", "Effects", ">", "SYNL3K1", ",", "Effects", ">", "TRSE163", ",", "Effects", ">", "TRSE164", ",", "Effects", ">", "T00TWINKMW", ",", "Effects", ">", "TackyNess", ",", "Effects", ">", "TakeOff", ",", "Effects", ">", "TAKEOFF", ",", "Effects", ">", "TAKEOFF", ",", "Effects", ">", "TAKEOFF", ",", "Effects", ">", "TAKEOFF", ",", "Effects", ">", "TAPDANCE1", ",", "Effects", ">", "TapShoes", ",", "Effects", ">", "TAPSLAP", ",", "Effects", ">", "TELCALL1", ",", "Effects", ">", "TELCALL2", ",", "Effects", ">", "TELESIS", ",", "Effects", ">", "THEKID", ",", "Effects", ">", "THEPIT", ",", "Effects", ">", "THUNDER", ",", "Effects", ">", "TRAFFICJAM", ",", "Effects", ">", "TRAIN", ",", "Effects", ">", "TRAIN", ",", "Effects", ">", "TRANSPORT1", ",", "Effects", ">", "TUBSPACE", ",", "Effects", ">", "TUCHTONE", ",", "Effects", ">", "TundStatc", ",", "Effects", ">", "TUNDSTATIC", ",", "Effects", ">", "TVSTATIC", ",", "Effects", ">", "TWEET", ",", "Effects", ">", "TWINKMW1", ",", "Effects", ">", "TYPEWRITER", ",", "Effects", ">", "TYPEWRITER", ",", "Effects", ">", "UBOAT", ",", "Effects", ">", "UFO", ",", "Effects", ">", "UFO", ",", "Effects", ">", "VANHALEN", ",", "Effects", ">", "VAPORSHD", ",", "Effects", ">", "VOICEYMW", ",", "Effects", ">", "WARNING", ",", "Effects", ">", "Warp9", ",", "Effects", ">", "WASPSTING", ",", "Effects", ">", "WATER", ",", "Effects", ">", "WATERGDN", ",", "Effects", ">", "WATERKBD", ",", "Effects", ">", "WATERDROP", ",", "Effects", ">", "WATERFRONT", ",", "Effects", ">", "WatrUDoing", ",", "Effects", ">", "WAVE1", ",", "Effects", ">", "WAVE2", ",", "Effects", ">", "WAVE3", ",", "Effects", ">", "WAVE4", ",", "Effects", ">", "WAVEBREAK", ",", "Effects", ">", "WAVE2", ",", "Effects", ">", "WAVES", ",", "Effects", ">", "WEIRD", ",", "Effects", ">", "WEIRDBIRD", ",", "Effects", ">", "WHAT", ",", "Effects", ">", "WhirlerHM", ",", "Effects", ">", "WhiteNoise", ",", "Effects", ">", "Whoosh", ",", "Effects", ">", "WIERDAAV", ",", "Effects", ">", "WINEGLASS", ",", "Effects", ">", "WOLF", ",", "Effects", ">", "WOAAOUWWWW", ",", "Effects", ">", "XTALK", ",", "Effects", ">", "X311AV", ",", "Effects", ">", "XORCIST", ",", "Effects", ">", "YAGOTME", ",", "Effects", ">", "YAMATALKA", ",", "Effects", ">", "YAMATALKB", ",", "Effects", ">", "YAMATALKC", ",", "Effects", ">", "YESTALK", ",", "Effects", ">", "ZAPP", ",", "Effects", ">", "AAOOWWWWW", ",", "Effects", ">", "Blubb", ",", "Effects", ">", "CatCry", ",", "Effects", ">", "cb", ",", "Effects", ">", "cc", ",", "Effects", ">", "cc", ",", "Effects", ">", "cc", ",", "Effects", ">", "cc", ",", "Effects", ">", "E5", ",", "Effects", ">", "LUTEc", ",", "Effects", ">", "qB", ",", "Effects", ">", "qB", ",", "Effects", ">", "qB", ",", "Effects", ">", "nSYNnB", ",", "Effects", ">", "nSYNnB", ",", "Effects", ">", "DOWNZIZZLE", ",", "Effects", ">", "HITONE", ",", "Effects", ">", "MINGLE", ",", "Effects", ">", "V3", ",", "Effects", ">", 2001, ",", "Effects", ">", "AngryGods", ",", "Effects", ">", "ANVILPD1", ",", "Effects", ">", "AyeCAPN", ",", "Effects", ">", "Belch", ",", "Effects", ">", "BiPlane", ",", "Effects", ">", "Birds4", ",", "Effects", ">", "BIZARRE", ",", "Effects", ">", "BlNDeckr", ",", "Effects", ">", "BLACKBIRD", ",", "Effects", ">", "Bombdrop1", ",", "Effects", ">", "Bombdrop3", ",", "Effects", ">", "CWuorinen", ",", "Effects", ">", "canary", ",", "Effects", ">", "Canus2", ",", "Effects", ">", "Chicks", ",", "Effects", ">", "cilindr2X", ",", "Effects", ">", "cilindr2X", ",", "Effects", ">", "cilindr2XX", ",", "Effects", ">", "cilindr2XX", ",", "Effects", ">", "cilindr2Xz", ",", "Effects", ">", "cilinGTR1", ",", "Effects", ">", "cilinMIX1", ",", "Effects", ">", "cilinMIX1", ",", "Effects", ">", "cilndr2new", ",", "Effects", ">", "COMPUTER4", ",", "Effects", ">", "computer6", ",", "Effects", ">", "COMPUTERFX", ",", "Effects", ">", "DasBoat", ",", "Effects", ">", "dentistry", ",", "Effects", ">", "DRONEINC", ",", "Effects", ">", "DX29NOSE1A", ",", "Effects", ">", "DX29NOSE1A", ",", "Effects", ">", "EClCl33", ",", "Effects", ">", "EFFECT001", ",", "Effects", ">", "EFFECT002", ",", "Effects", ">", "EFFECT01", ",", "Effects", ">", "EFFECT02", ",", "Effects", ">", "ELECSAW", ",", "Effects", ">", "EXPLOSION4", ",", "Effects", ">", "FADER2", ",", "Effects", ">", "FLEXYBEAD", ",", "Effects", ">", "flySWAT", ",", "Effects", ">", "fxone", ",", "Effects", ">", "GARKONS", ",", "Effects", ">", "GHENGIS", ",", "Effects", ">", "GRANNIES", ",", "Effects", ">", "grilloelc1", ",", "Effects", ">", "grilloelcX", ",", "Effects", ">", "HAL9000", ",", "Effects", ">", "HEAVYRAIN", ",", "Effects", ">", "Hello", ",", "Effects", ">", "HELP", ",", "Effects", ">", "HRPSGLISS2", ",", "Effects", ">", "HUSKIES", ",", "Effects", ">", "Hyperion", ",", "Effects", ">", "INDUSTRIAL", ",", "Effects", ">", "Insect4", ",", "Effects", ">", "INTROPART", ",", "Effects", ">", "ISANYBODY", ",", "Effects", ">", "IXI20", ",", "Effects", ">", "Jackals", ",", "Effects", ">", "JETSONSPD", ",", "Effects", ">", "KARNEVIL9", ",", "Effects", ">", "Lasercanon", ",", "Effects", ">", "LFOSWEEP", ",", "Effects", ">", "LSOonACID", ",", "Effects", ">", "MACHINEGUN", ",", "Effects", ">", "metaCLASM", ",", "Effects", ">", "MIRop4ff", ",", "Effects", ">", "MIRop5Af", ",", "Effects", ">", "MIRop6ffx", ",", "Effects", ">", "MIXCREAT", ",", "Effects", ">", "MOVIEA", ",", "Effects", ">", "MOVIEB", ",", "Effects", ">", "MOVIEC", ",", "Effects", ">", "MOVIETOY", ",", "Effects", ">", "Movie2", ",", "Effects", ">", "New2", ",", "Effects", ">", "NEWSERG6A", ",", "Effects", ">", "NEW2SERG6A", ",", "Effects", ">", "OHDEAR", ",", "Effects", ">", "ONWEER", ",", "Effects", ">", "Pacman", ",", "Effects", ">", "PATCHCREA", ",", "Effects", ">", "PATCHCREA", ",", "Effects", ">", "PATCHCREA", ",", "Effects", ">", "PATCHCREA", ",", "Effects", ">", "PATCHCREA", ",", "Effects", ">", "PATCHCREA", ",", "Effects", ">", "PATCHCREA", ",", "Effects", ">", "PATCHCREA", ",", "Effects", ">", "PATCHCREA", ",", "Effects", ">", "POSE60", ",", "Effects", ">", "POSE70", ",", "Effects", ">", "PULLUP01", ",", "Effects", ">", "PULLUP02", ",", "Effects", ">", "QTIME2", ",", "Effects", ">", "Quark1", ",", "Effects", ">", "RECOIL", ",", "Effects", ">", "ROMPO2A", ",", "Effects", ">", "RUMBLE", ",", "Effects", ">", "SALL1212", ",", "Effects", ">", "Sample03", ",", "Effects", ">", "sayit", ",", "Effects", ">", "science", ",", "Effects", ">", "scifi", ",", "Effects", ">", "SEASIDE", ",", "Effects", ">", "SHNOSE1", ",", "Effects", ">", "SHNOSE1B", ",", "Effects", ">", "SHNOSE1B", ",", "Effects", ">", "SHNOSE1X", ",", "Effects", ">", "SHNOSE1Y", ",", "Effects", ">", "SH3ONOSE1B", ",", "Effects", ">", "SH3ONOSE1B", ",", "Effects", ">", "SHARP", ",", "Effects", ">", "SHIMMER5", ",", "Effects", ">", "ShipNFO", ",", "Effects", ">", "SHnNOSE1A", ",", "Effects", ">", "SHnNOSE1A", ",", "Effects", ">", "SHNOSE1A", ",", "Effects", ">", "SHORTCYCL", ",", "Effects", ">", "SHORTWAVE", ",", "Effects", ">", "Sidebands", ",", "Effects", ">", "SIPSI", ",", "Effects", ">", "Sneezer", ",", "Effects", ">", "SOUFFLE1DX", ",", "Effects", ">", "SOUFFLE1TX", ",", "Effects", ">", "SOUFFLE2DX", ",", "Effects", ">", "SOUFFLE3DX", ",", "Effects", ">", "SOUFFLE3TX", ",", "Effects", ">", "SOUFFLE4DX", ",", "Effects", ">", "SOUFFLE4TX", ",", "Effects", ">", "SOUFFLE5DX", ",", "Effects", ">", "SOUFFLE5TX", ",", "Effects", ">", "SOUFFLE6DX", ",", "Effects", ">", "SPACESHIP", ",", "Effects", ">", "SPACEWARP", ",", "Effects", ">", "SPLURGE", ",", "Effects", ">", "SPLUSCH", ",", "Effects", ">", "Stormatsea", ",", "Effects", ">", "STRINGS01", ",", "Effects", ">", "Sulphur", ",", "Effects", ">", "surgwrmbr3", ",", "Effects", ">", "surgwrmbr4", ",", "Effects", ">", "surgwrmbx2", ",", "Effects", ">", "TELCALL3", ",", "Effects", ">", "TENSION", ",", "Effects", ">", "TIRED", ",", "Effects", ">", "Tomeater", ",", "Effects", ">", "TRAFFICA", ",", "Effects", ">", "TRAFFICB", ",", "Effects", ">", "WESTSIDE", ",", "Effects", ">", "WHEEEEEEEE", ",", "Effects", ">", "WHITENOISE", ",", "Effects", ">", "Wolves", ",", "Effects", ">", "XYZ", ",", "Effects", ">", "ANGELA44", ",", "Effects", ">", "LASER10", ",", "Effects", ">", "TIMEWARP", ",", "Effects", ">", "HEAVYRAIN", ",", "Effects", ">", "THUNDER", ",", "Effects", ">", "STORM1", ",", "Effects", ">", "STORM2", ",", "Effects", ">", "WATERDROP", ",", "Effects", ">", "BUBBLES", ",", "Effects", ">", "WAVE1", ",", "Effects", ">", "WAVE2", ",", "Effects", ">", "WAVE3", ",", "Effects", ">", "WAVE4", ",", "Effects", ">", "RUMBEARTH", ",", "Effects", ">", "EXPLOSION1", ",", "Effects", ">", "EXPLOSION2", ",", "Effects", ">", "MACGUN1", ",", "Effects", ">", "MACGUN2", ",", "Effects", ">", "MOBILE1", ",", "Effects", ">", "MOBILE2", ",", "Effects", ">", "KLAXON", ",", "Effects", ">", "MOTORCYCLE", ",", "Effects", ">", "AMBULANCE", ",", "Effects", ">", "PATROLCAR", ",", "Effects", ">", "SIREN", ",", "Effects", ">", "PLANE1", ",", "Effects", ">", "PLANE2", ",", "Effects", ">", "HELICOPTER", ",", "Effects", ">", "LOCOMOTIVE", ",", "Effects", ">", "SHIP", ",", "Effects", ">", "TELCALL1", ",", "Effects", ">", "TELCALL2", ",", "Effects", ">", "BELL", ",", "Effects", ">", "PIPOPA", ",", "Effects", ">", "ALARM", ",", "Effects", ">", "DOG", ",", "Effects", ">", "BABYCAT", ",", "Effects", ">", "INSECT1", ",", "Effects", ">", "INSECT2", ",", "Effects", ">", "INSECT3", ",", "Effects", ">", "BIRD1", ",", "Effects", ">", "BIRD2", ",", "Effects", ">", "BIRD3", ",", "Effects", ">", "BIRD4", ",", "Effects", ">", "HEARTBEAT", ",", "Effects", ">", "TYPEWRITER", ",", "Effects", ">", "CROSSING", ",", "Effects", ">", "FACTORY", ",", "Effects", ">", "ROBOT", ",", "Effects", ">", "TEMPBELL1", ",", "Effects", ">", "TEMPBELL2", ",", "Effects", ">", "CHURCHBELL", ",", "Effects", ">", "BIGBEN", ",", "Effects", ">", "IMAGE1", ",", "Effects", ">", "IMAGE2", ",", "Effects", ">", "IMAGE3", ",", "Effects", ">", "IMAGE4", ",", "Effects", ">", "IMAGE5", ",", "Effects", ">", "IMAGE6", ",", "Effects", ">", "IMAGE7", ",", "Effects", ">", "IMAGE8", ",", "Effects", ">", "IMAGE9", ",", "Effects", ">", "IMAGE10", ",", "Effects", ">", "IMAGE11", ",", "Effects", ">", "IMAGE12", ",", "Effects", ">", "IMAGE13", ",", "Effects", ">", "IMAGE14", ",", "Effects", ">", "WILDBOAR", ",", "Effects", ">", "GURGLEHOG", ",", "Effects", ">", "DINGLE1", ",", "Effects", ">", "CRYSTALBEL", ",", "Effects", ">", "SPOOKY", ",", "Effects", ">", "EVILTONE", ",", "Effects", ">", "NEPTUNE", ",", "Effects", ">", "COMPUTE", ",", "Effects", ">", "GHOSTSITAR", ",", "Effects", ">", "WOLF", ",", "Effects", ">", "DLYTRIANL", ",", "Effects", ">", "EQUINOX", ",", "Effects", ">", "CULTURE", ",", "Effects", ">", "TRIANGLE", ",", "Effects", ">", "FLEXI4", ",", "Effects", ">", "EXPLOSION", ",", "Effects", ">", "GOTCHA", ",", "Effects", ">", "UFO", ",", "Effects", ">", "UFO", ",", "Effects", ">", "SWISHSTRG", ",", "Effects", ">", "MOTOCROSS", ",", "Effects", ">", "SAMBAWHIS", ",", "Effects", ">", "CARHORN", ",", "Effects", ">", "TRAFFICJAM", ",", "Effects", ">", "MARTIANS", ",", "Effects", ">", "BURRRRP", ",", "Effects", ">", "PHONETONE", ",", "Effects", ">", "OFFHOOK", ",", "Effects", ">", "DIALTONE", ",", "Effects", ">", "TUCHTONE", ",", "Effects", ">", "BUSY", ",", "Effects", ">", "PHONERING", ",", "Effects", ">", "DialTone", ",", "Effects", ">", "CDEbF", ",", "Effects", ">", "Buzy", ",", "Effects", ">", "ATTRing", ",", "Effects", ">", "OffTheHook", ",", "Effects", ">", "Echo1a", ",", "Effects", ">", "SmuthFall1", ",", "Effects", ">", "OrgWarp1", ",", "Effects", ">", "SuessMguse", ",", "Effects", ">", "SpiEfx1", ",", "Effects", ">", "SpiEfx2", ",", "Effects", ">", "DelaydXplo", ",", "Effects", ">", "Bang1", ",", "Effects", ">", "ModOut2", ",", "Effects", ">", "ModDown1", ",", "Effects", ">", "SawDown1", ",", "Effects", ">", "CaGhostLyn", ",", "Effects", ">", "GostHiway1", ",", "Effects", ">", "Lytening", ",", "Effects", ">", "Lytening2", ",", "Effects", ">", "Ouygue1", ",", "Effects", ">", "Ouygue2", ",", "Effects", ">", "DownUp1", ",", "Effects", ">", "WhislrsCus", ",", "Effects", ">", "RandmNots1", ",", "Effects", ">", "RndmNotes2", ",", "Effects", ">", "RandmNots3", ",", "Effects", ">", "Randomoiz1", ",", "Effects", ">", "Randomoiz2", ",", "Effects", ">", "Randomoiz3", ",", "Effects", ">", "Randomoiz4", ",", "Effects", ">", "RX15Seq", ",", "Effects", ">", "HELICOPTR", ",", "Effects", ">", "PBGONGA1", ",", "Effects", ">", "SPACESHOT", ",", "Effects", ">", "SAWEMUP", ",", "Effects", ">", "SAWEMUP2", ",", "Effects", ">", "SAWEMUP3", ",", "Effects", ">", "BURGALARM", ",", "Effects", ">", "SIREN", ",", "Effects", ">", "RUMBLE", ",", "Effects", ">", "UBOAT", ",", "Effects", ">", "SPACESLID", ",", "Effects", ">", "SPACEGHOL", ",", "Effects", ">", "SPACENOISE", ",", "Effects", ">", "SPACENOS2", ",", "Effects", ">", "GHOSTS", ",", "Effects", ">", "TVSTATIC", ",", "Effects", ">", "GANKOGUI", ",", "Effects", ">", "SPACECOMP", ",", "Effects", ">", "SPACENOIS3", ",", "Effects", ">", "SPACENOS4", ",", "Effects", ">", "SPGHSHD", ",", "Effects", ">", "VAPORSHD", ",", "Effects", ">", "CHOIR24", ",", "Effects", ">", "SPPITCH", ",", "Effects", ">", "SAUCER", ",", "Effects", ">", "SPACEOFF", ",", "Effects", ">", "BARK", ",", "Effects", ">", "NOISE14", ",", "Effects", ">", "SPACACC", ",", "Effects", ">", "SHNOISDR", ",", "Effects", ">", "LIGHTNING", ",", "Effects", ">", "WAVES", ",", "Effects", ">", "Smash", ",", "Effects", ">", "Dschungel", ",", "Effects", ">", "Fabrik", ",", "Effects", ">", "Scratch", ",", "Effects", ">", "Damaged", ",", "Effects", ">", "Helicopt", ",", "Effects", ">", "Frogger", ",", "Effects", ">", "Mashine", ",", "Effects", ">", "Ocean", ",", "Effects", ">", "Mafia", ",", "Effects", ">", "Tarantula", ",", "Effects", ">", "What", ",", "Effects", ">", "Policecar", ",", "Effects", ">", "Nervous", ",", "Effects", ">", "Blubb", ",", "Effects", ">", "Clash", ",", "Effects", ">", "Noise", ",", "Effects", ">", "CatCry", ",", "Effects", ">", "Whistling", ",", "Effects", ">", "BLAHHHHH", ",", "Effects", ">", "DEPARTURE", ",", "Effects", ">", "SHIMMER3", ",", "Effects", ">", "EXPLOS2A", ",", "Effects", ">", "4OKNEW2A", ",", "Effects", ">", "HERBIE", ",", "Effects", ">", "EXPLOCLAP", ",", "Effects", ">", "STRANGE", ",", "Effects", ">", "SPACEWELL", ",", "Effects", ">", "Landing", ",", "Effects", ">", "Invaders", ",", "Effects", ">", "THEBIRDS", ",", "Effects", ">", "KELLERTUER", ",", "Effects", ">", "STEAMHAMMR", ",", "Effects", ">", "COMPUTER1", ",", "Effects", ">", "ABSTURZ", ",", "Effects", ">", "SLOWGROW", ",", "Effects", ">", "DEMIAN", ",", "Effects", ">", "METROPOLIS", ",", "Effects", ">", "8BITBELL", ",", "Effects", ">", "ABUASHRAM", ",", "Effects", ">", "SHORTWAVE", ",", "Effects", ">", "HORRORoofs", ",", "Effects", ">", "GHOST30", ",", "Effects", ">", "SampleHold", ",", "Effects", ">", "EFFECT3A", ",", "Effects", ">", "AUSIMONA", ",", "Effects", ">", "INVERS", ",", "Effects", ">", "EXP004", ",", "Effects", ">", "L0RDJH", ",", "Effects", ">", "WETSOUNDA", ",", "Effects", ">", "PITCHYA", ",", "Effects", ">", "ARPEGSVP", ",", "Effects", ">", "RINGMOD2", ",", "Effects", ">", "SAWDOWN1", ",", "Effects", ">", "TAKEOFF", ",", "Effects", ">", "SAWDOWN2", ",", "Effects", ">", "INTRO2", ",", "Effects", ">", "VIBRACLAA", ",", "Effects", ">", "Scottys", ",", "Effects", ">", "Arrial", ",", "Effects", ">", "Jingle", ",", "Effects", ">", "NEStory", ",", "Effects", ">", "Bits", ",", "Effects", ">", "Dingle1", ",", "Effects", ">", "StpdancHM", ",", "Effects", ">", "Halloo", ",", "Effects", ">", "BimmelHM", ",", "Effects", ">", "JuchheHM", ",", "Effects", ">", "DxIntroHM", ",", "Effects", ">", "JudgemtHM", ",", "Effects", ">", "GurooHM", ",", "Effects", ">", "WhirlerHM", ",", "Effects", ">", "RDropHM", ",", "Effects", ">", "TYPEWRITER", ",", "Effects", ">", "DESCENT", ",", "Effects", ">", "HUSKIES", ",", "Effects", ">", "MACHINEGUN", ",", "Effects", ">", "PRIXSHIFT", ",", "Effects", ">", "STHELENS", ",", "Effects", ">", "EXPLOSION", ",", "Effects", ">", "TRAIN", ",", "Effects", ">", "BOMBDROP", ",", "Effects", ">", "DESCENT", ",", "Effects", ">", "RINGMODRA", ",", "Effects", ">", "TWEET", ",", "Effects", ">", "SPACEOUT", ",", "Effects", ">", "SCIENCE", ",", "Effects", ">", "HeartBeet2", ",", "Effects", ">", "WatrUDoing", ",", "Effects", ">", "Rumble1", ",", "Effects", ">", "Lytening2", ",", "Effects", ">", "DaleTrail2", ",", "Electric", "Piano", ">", "EPIANO1", ",", "Electric", "Piano", ">", "EPIANO1A", ",", "Electric", "Piano", ">", "EPIANO2", ",", "Electric", "Piano", ">", "EPIANO2A", ",", "Electric", "Piano", ">", "EPIANO3", ",", "Electric", "Piano", ">", "EPIANO3A", ",", "Electric", "Piano", ">", "EPIANO4", ",", "Electric", "Piano", ">", "EPIANO4A", ",", "Electric", "Piano", ">", "EPIANO5", ",", "Electric", "Piano", ">", "EPIANO5A", ",", "Electric", "Piano", ">", "EPIANO6", ",", "Electric", "Piano", ">", "EPIANO6A", ",", "Electric", "Piano", ">", "EPIANO7", ",", "Electric", "Piano", ">", "EPIANO7A", ",", "Electric", "Piano", ">", "EPIANO8", ",", "Electric", "Piano", ">", "EPIANO9", ",", "Electric", "Piano", ">", "EPIANO10", ",", "Electric", "Piano", ">", "EPIANO11", ",", "Electric", "Piano", ">", "EPIANO12", ",", "Electric", "Piano", ">", "EPIANO13", ",", "Electric", "Piano", ">", "EPIANO14", ",", "Electric", "Piano", ">", "EPIANO15", ",", "Electric", "Piano", ">", "EPIANO16", ",", "Electric", "Piano", ">", "EPIANO17", ",", "Electric", "Piano", ">", "EPIANO18", ",", "Electric", "Piano", ">", "EPIANO19", ",", "Electric", "Piano", ">", "EPIANO20", ",", "Electric", "Piano", ">", "EPNO1A", ",", "Electric", "Piano", ">", "EPNO2A", ",", "Electric", "Piano", ">", "EPNO3A", ",", "Electric", "Piano", ">", "CHORRDSA", ",", "Electric", "Piano", ">", "CHORRDSB", ",", "Electric", "Piano", ">", "EPIANO1", ",", "Electric", "Piano", ">", "EPIANO2", ",", "Electric", "Piano", ">", "EPIANO3", ",", "Electric", "Piano", ">", "EPIANO4", ",", "Electric", "Piano", ">", "ELECPNO1", ",", "Electric", "Piano", ">", "ELECPNO2", ",", "Electric", "Piano", ">", "ELECPNO5", ",", "Electric", "Piano", ">", "ELECPNO6", ",", "Electric", "Piano", ">", "ELECPNO8", ",", "Electric", "Piano", ">", "ELECPNO9", ",", "Electric", "Piano", ">", "ELECGRD1", ",", "Electric", "Piano", ">", "EGRAND2", ",", "Electric", "Piano", ">", "EGRAND8", ",", "Electric", "Piano", ">", "ELECGRAND", ",", "Electric", "Piano", ">", "ELEC2GRAND", ",", "Electric", "Piano", ">", "EGRAND2ED", ",", "Electric", "Piano", ">", "EMURHDS", ",", "Electric", "Piano", ">", "ANNIESCRY", ",", "Electric", "Piano", ">", "BJRHODS", ",", "Electric", "Piano", ">", "CHROMA5", ",", "Electric", "Piano", ">", "JEFSRHODS", ",", "Electric", "Piano", ">", "JOERHODES", ",", "Electric", "Piano", ">", "RHODES73", ",", "Electric", "Piano", ">", "TINEEPNO", ",", "Electric", "Piano", ">", "TYNRH0DES", ",", "Electric", "Piano", ">", "CHORPIANO", ",", "Electric", "Piano", ">", "DBEPNO6", ",", "Electric", "Piano", ">", "PROCRHDS", ",", "Electric", "Piano", ">", "RASHRHO2", ",", "Electric", "Piano", ">", "RHODSACOU", ",", "Electric", "Piano", ">", "MPNO115", ",", "Electric", "Piano", ">", "WURLITZER", ",", "Electric", "Piano", ">", "ELEC2GRAN", ",", "Electric", "Piano", ">", "ELECGRDA", ",", "Electric", "Piano", ">", "KCEpMax", ",", "Electric", "Piano", ">", "KCEpSaw", ",", "Electric", "Piano", ">", "KCEpTyn7", ",", "Electric", "Piano", ">", "KCPiano2", ",", "Electric", "Piano", ">", "EPIANODS", ",", "Electric", "Piano", ">", "EPNO141", ",", "Electric", "Piano", ">", "ELECPNOA", ",", "Electric", "Piano", ">", "ELECTINE", ",", "Electric", "Piano", ">", "ELECPNOA", ",", "Electric", "Piano", ">", "EPBRSBC", ",", "Electric", "Piano", ">", "MedlXprsv", ",", "Electric", "Piano", ">", "MUSICBOX", ",", "Electric", "Piano", ">", "MUSICBOXX", ",", "Electric", "Piano", ">", "MUSICBX1", ",", "Electric", "Piano", ">", "MUSICBX2", ",", "Ethnic", ">", "AFRICAJPN", ",", "Ethnic", ">", "AFRICAJPN", ",", "Ethnic", ">", "AFRICADRUM", ",", "Ethnic", ">", "AFRICANFL", ",", "Ethnic", ">", "AfriTumbaW", ",", "Ethnic", ">", "ZIMBABWEM", ",", "Ethnic", ">", "ORIENT1", ",", "Ethnic", ">", "AGITATO2", ",", "Ethnic", ">", "AGITATO2", ",", "Ethnic", ">", "AGITATO2", ",", "Ethnic", ">", "Agitato3", ",", "Ethnic", ">", "AGITATO3", ",", "Ethnic", ">", "AGITATO3", ",", "Ethnic", ">", "AGITATO4", ",", "Ethnic", ">", "AGITATO5", ",", "Ethnic", ">", "AGITATO6", ",", "Ethnic", ">", "AGITATO7", ",", "Ethnic", ">", "Agitato3", ",", "Ethnic", ">", "AGITATOCS", ",", "Ethnic", ">", "BANKOKSIT", ",", "Ethnic", ">", "BPOPSITAR", ",", "Ethnic", ">", "CHINA", ",", "Ethnic", ">", "ChinaGong", ",", "Ethnic", ">", "CHINALUTE", ",", "Ethnic", ">", "CHINAPIANO", ",", "Ethnic", ">", "CHINEES", ",", "Ethnic", ">", "ChinezBls", ",", "Ethnic", ">", "CHINK8END", ",", "Ethnic", ">", "CHNJAHARP", ",", "Ethnic", ">", "CHNSEBELLS", ",", "Ethnic", ">", "DAVEKOTO", ",", "Ethnic", ">", "EASTWEST", ",", "Ethnic", ">", "EASTWEST", ",", "Ethnic", ">", "ENVKOTO1", ",", "Ethnic", ">", "ENVKOTO2", ",", "Ethnic", ">", "ENVKOTO3", ",", "Ethnic", ">", "JAPAKNEES", ",", "Ethnic", ">", "JAPAN", ",", "Ethnic", ">", "japanchime", ",", "Ethnic", ">", "JAPANESE", ",", "Ethnic", ">", "KSITAR1", ",", "Ethnic", ">", "KSITAR2", ",", "Ethnic", ">", "KSITAR3", ",", "Ethnic", ">", "KSITAR4", ",", "Ethnic", ">", "KOTO", ",", "Ethnic", ">", "KOTO", ",", "Ethnic", ">", "KOTO2", ",", "Ethnic", ">", "KOTO4", ",", "Ethnic", ">", "KOTO5", ",", "Ethnic", ">", "KOTO6", ",", "Ethnic", ">", "KOTO7", ",", "Ethnic", ">", "KOTOA", ",", "Ethnic", ">", "KOTOB", ",", "Ethnic", ">", "KOTOC", ",", "Ethnic", ">", "Koto1", ",", "Ethnic", ">", "KOTO1", ",", "Ethnic", ">", "KOTO2", ",", "Ethnic", ">", "KOTO3", ",", "Ethnic", ">", "KOTO4", ",", "Ethnic", ">", "KOTO5", ",", "Ethnic", ">", "KOTO6", ",", "Ethnic", ">", "KOTO7", ",", "Ethnic", ">", "KOTO8", ",", "Ethnic", ">", "KOTOENV", ",", "Ethnic", ">", "METALKOTO", ",", "Ethnic", ">", "NEWSITAR", ",", "Ethnic", ">", "ORIENTAL", ",", "Ethnic", ">", "SOFTSITAR", ",", "Ethnic", ">", "SOFTSITAR", ",", "Ethnic", ">", "ZIMBALON", ",", "Ethnic", ">", "ZITHER", ",", "Ethnic", ">", "ChiWood", ",", "Ethnic", ">", "SPACEKOTO", ",", "Ethnic", ">", "Asia2", ",", "Ethnic", ">", "KENJOJI1", ",", "Ethnic", ">", "Koto2", ",", "Ethnic", ">", "KOTODUBBB", ",", "Ethnic", ">", "Sitar2", ",", "Ethnic", ">", "Sitar3", ",", "Ethnic", ">", "Sitar6", ",", "Ethnic", ">", "Sitar9", ",", "Ethnic", ">", "Sitar10", ",", "Ethnic", ">", "Sitar11", ",", "Ethnic", ">", 87, ",", "Ethnic", ">", "88R50cQ", ",", "Ethnic", ">", "R50cQ", ",", "Ethnic", ">", "R50cQ", ",", "Ethnic", ">", "ccM", ",", "Ethnic", ">", "BAcccW", ",", "Ethnic", ">", "HINGccb", ",", "Ethnic", ">", "Y5c", ",", "Ethnic", ">", "acccc", ",", "Ethnic", ">", "KO1acccc", ",", "Ethnic", ">", "KO2cccc", ",", "Ethnic", ">", "AAbb", ",", "Ethnic", ">", "NUM2c8cY", ",", "Ethnic", ">", "POR50cQ", ",", "Ethnic", ">", "6acccc", ",", "Ethnic", ">", "KO5XF7cR", ",", "Ethnic", ">", "d1aU7cR", ",", "Ethnic", ">", "d2aP7c", ",", "Ethnic", ">", "d3accc", ",", "Ethnic", ">", "NGbb", ",", "Ethnic", ">", "UIccc", ",", "Ethnic", ">", "LLSFcc", ",", "Ethnic", ">", "Ec", ",", "Ethnic", ">", "TAPcCc2", ",", "Ethnic", ">", "SUS5VU", ",", "Ethnic", ">", "unedcbcC", ",", "Ethnic", ">", "BELLcb", ",", "Ethnic", ">", "UNGAcccR", ",", "Ethnic", ">", "cNEcc", ",", "Ethnic", ">", "256c", ",", "Ethnic", ">", "TGS", ",", "Ethnic", ">", "BHarmAxl", ",", "Ethnic", ">", "BMelodca", ",", "Ethnic", ">", "BAGPIPE", ",", "Ethnic", ">", "BAGPIPE", ",", "Ethnic", ">", "BagPipeG", ",", "Ethnic", ">", "BagyPipes", ",", "Ethnic", ">", "BagyPipes", ",", "Ethnic", ">", "BAGYPIPES1", ",", "Ethnic", ">", "BAGYPIPES3", ",", "Ethnic", ">", "JHSUS1A", ",", "Ethnic", ">", "JHSUS1B", ",", "Ethnic", ">", "JHSUS1C", ",", "Ethnic", ">", "JHSUS1D", ",", "Ethnic", ">", "LUTE", ",", "Ethnic", ">", "LUTE", ",", "Ethnic", ">", "LUTE2", ",", "Ethnic", ">", "LUTESUS", ",", "Ethnic", ">", "ZYDECO", ",", "Ethnic", ">", "Lute2", ",", "Ethnic", ">", "Lute3", ",", "Ethnic", ">", "LuteBass", ",", "Ethnic", ">", "ITARccb", ",", "Ethnic", ">", "01Ncb", ",", "Ethnic", ">", "02ccb", ",", "Ethnic", ">", "03ccb", ",", "Ethnic", ">", 487, ",", "Ethnic", ">", "05ccb", ",", "Ethnic", ">", "06ccb", ",", "Ethnic", ">", "07ccb", ",", "Ethnic", ">", "08ccb", ",", "Ethnic", ">", "09ccb", ",", "Ethnic", ">", "10ccb", ",", "Ethnic", ">", "EG87", ",", "Ethnic", ">", "TARc3", ",", "Ethnic", ">", "TARccZ", ",", "Ethnic", ">", "ccZ", ",", "Ethnic", ">", "CELbb", ",", "Ethnic", ">", "2cccc", ",", "Ethnic", ">", "RA1cccc", ",", "Ethnic", ">", "RA2cccc", ",", "Ethnic", ">", "RA3cc", ",", "Ethnic", ">", "ra40O", ",", "Ethnic", ">", "SYNCROMBS", ",", "Ethnic", ">", "SYNCROM", ",", "Ethnic", ">", "SYNCTRMBN", ",", "Ethnic", ">", "SYNCTRBN2", ",", "Ethnic", ">", "SYNCSPLIT", ",", "Ethnic", ">", "SYNCROM1", ",", "Ethnic", ">", "SYNCOB8", ",", "Ethnic", ">", "SYNCPROF5", ",", "Ethnic", ">", "SYNCROM2", ",", "Ethnic", ">", "SYNCCLAV", ",", "Ethnic", ">", "SYNCROM3", ",", "Ethnic", ">", "SYNCVLNO", ",", "Ethnic", ">", "SYNCROM4", ",", "Ethnic", ">", "SYNCGUIT", ",", "Ethnic", ">", "SYNCROM5", ",", "Ethnic", ">", "SYNCROM6", ",", "Ethnic", ">", "SYNCAFRO", ",", "Ethnic", ">", "SYNCPERC", ",", "Ethnic", ">", "SYNCREPT", ",", "Ethnic", ">", "SYNCCLAV2", ",", "Ethnic", ">", "SYNCCH0IR", ",", "Ethnic", ">", "SYNCSPLT2", ",", "Ethnic", ">", "SYNCV0CI2", ",", "Ethnic", ">", "SYNCGIAP", ",", "Ethnic", ">", "SYNCBOX", ",", "Ethnic", ">", "SYNCROMB3", ",", "Ethnic", ">", "SYNCSEZN", ",", "Ethnic", ">", "SYNCMETAL", ",", "Ethnic", ">", "SYNCSYNT", ",", "Ethnic", ">", "SYNCRH0DS", ",", "Ethnic", ">", "SYNCROM8", ",", "Ethnic", ">", "SYNCHORN", ",", "Ethnic", ">", "VAFFANCULO", ",", "Ethnic", ">", "PIANOCP70", ",", "Ethnic", ">", "GRASSBRASS", ",", "Ethnic", ">", "CELLIMAX", ",", "Ethnic", ">", "VICSTRINGS", ",", "Ethnic", ">", "BURDEL", ",", "Ethnic", ">", "ALANPARSON", ",", "Ethnic", ">", "MAXPIANO1", ",", "Ethnic", ">", "CLAVICAZZ", ",", "Ethnic", ">", "PIANO3", ",", "Ethnic", ">", "EPIANO1", ",", "Ethnic", ">", "DAGGERMAX", ",", "Ethnic", ">", "FERROCHINA", ",", "Ethnic", ">", "FARIMBA", ",", "Ethnic", ">", "DEEBASS", ",", "Ethnic", ">", "SLAPBASS", ",", "Ethnic", ">", "ANALBRASS", ",", "Ethnic", ">", "STRAPP1", ",", "Ethnic", ">", "OOOOHMALE", ",", "Ethnic", ">", "HUMANMAX1", ",", "Ethnic", ">", "CARP5THS", ",", "Ethnic", ">", "CHINALUTE", ",", "Ethnic", ">", "GATORXXX", ",", "Ethnic", ">", "SOLOVIOLIN", ",", "Ethnic", ">", "ALANPARSON", ",", "Ethnic", ">", "TROMBONES", ",", "Ethnic", ">", "BACSKAZZ2", ",", "Ethnic", ">", "WHAT", ",", "Ethnic", ">", "SYNTHFULL", ",", "Ethnic", ">", "SLAPBASS", ",", "Ethnic", ">", "DEEFREGNA", ",", "Ethnic", ">", "FREGNAMAX", ",", "Ethnic", ">", "KOTO1", ",", "Ethnic", ">", "KOTO2", ",", "Ethnic", ">", "KOTO3", ",", "Ethnic", ">", "KOTO4", ",", "Ethnic", ">", "KOTO5", ",", "Ethnic", ">", "KOTO6", ",", "Ethnic", ">", "KOTO7", ",", "Ethnic", ">", "KOTO8", ",", "Ethnic", ">", "KOTO9", ",", "Ethnic", ">", "KOTO2", ",", "Ethnic", ">", "KOTO4", ",", "Ethnic", ">", "KOTO5", ",", "Ethnic", ">", "KOTO6", ",", "Ethnic", ">", "KOTO7", ",", "Ethnic", ">", "KOTO", ",", "Ethnic", ">", "KOTOA", ",", "Ethnic", ">", "KOTOB", ",", "Ethnic", ">", "KOTOC", ",", "Ethnic", ">", "KOTOENV", ",", "Ethnic", ">", "ENVKOTO1", ",", "Ethnic", ">", "ENVKOTO2", ",", "Ethnic", ">", "ENVKOTO3", ",", "Ethnic", ">", "SPACEKOTO", ",", "Ethnic", ">", "PLUCK", ",", "Ethnic", ">", "PLUCKIN", ",", "Ethnic", ">", "PLUCKVOICE", ",", "Ethnic", ">", "PLUK161", ",", "Ethnic", ">", "PLUK162", ",", "Ethnic", ">", "METALKOTO", ",", "Ethnic", ">", "Revokoto", ",", "Ethnic", ">", "LUTE2", ",", "Ethnic", ">", "LUTEHARD", ",", "Ethnic", ">", "cM7NN", ",", "Ethnic", ">", "cM7NN", ",", "Ethnic", ">", "cM7NN", ",", "Ethnic", ">", "cM7NN", ",", "Ethnic", ">", "YM7NN", ",", "Ethnic", ">", "R50cQ", ",", "Ethnic", ">", "R50cQ", ",", "Ethnic", ">", "R50cQ", ",", "Ethnic", ">", "R50cQ", ",", "Ethnic", ">", "2X9cR", ",", "Ethnic", ">", "4O", ",", "Ethnic", ">", "5O", ",", "Ethnic", ">", "6O", ",", "Ethnic", ">", "7R50cQ", ",", "Ethnic", ">", "R50cQ", ",", "Ethnic", ">", "R50cQ", ",", "Ethnic", ">", "R50cQ", ",", "Ethnic", ">", "Yc", ",", "Ethnic", ">", "NVYc", ",", "Ethnic", ">", "TO1Yc", ",", "Ethnic", ">", "TO2Yc", ",", "Ethnic", ">", "TO366", ",", "Ethnic", ">", "KOTOcRKcW", ",", "Ethnic", ">", "Yc", ",", "Ethnic", ">", "NcRcK", ",", "Ethnic", ">", "OICEcRKcW", ",", "Ethnic", ">", "161c3", ",", "Ethnic", ">", "1620O", ",", "Ethnic", ">", "KOTORF0cQ", ",", "Ethnic", ">", "toF0c", ",", "Ethnic", ">", "2c2", ",", "Ethnic", ">", "RD", ",", "Ethnic", ">", "PLUCKBASS", ",", "Ethnic", ">", "XYLOPIANO", ",", "Ethnic", ">", "MUTEDCLV3", ",", "Ethnic", ">", "LOGDRUM", ",", "Ethnic", ">", "XYLORIFIC", ",", "Ethnic", ">", "BLOCK", ",", "Ethnic", ">", "TORIMTORA2", ",", "Ethnic", ">", "RIMBASLRY", ",", "Ethnic", ">", "TORIMPLUK", ",", "Ethnic", ">", "NEWPERCTOY", ",", "Ethnic", ">", "JAMACA", ",", "Ethnic", ">", "CELEST101", ",", "Ethnic", ">", "76BELLS", ",", "Ethnic", ">", "MUSICBOXX", ",", "Ethnic", ">", "SWISHBELL", ",", "Ethnic", ">", "VIOLINSOLO", ",", "Ethnic", ">", "OBOE", ",", "Ethnic", ">", "PYRAMFLT2", ",", "Ethnic", ">", "ACCORDINEE", ",", "Ethnic", ">", "SQUZIMEBO", ",", "Ethnic", ">", "HORN2", ",", "Ethnic", ">", "TROMBONE", ",", "Ethnic", ">", "NYLONG2TR", ",", "Ethnic", ">", "JAZZGUIT1", ",", "Ethnic", ">", "TOMTOMS", ",", "Ethnic", ">", "TIMBALI", ",", "Ethnic", ">", "PERCUSSION", ",", "Ethnic", ">", "TAMBOURINE", ",", "Ethnic", ">", "CASTENETS", ",", "Ethnic", ">", "COWBELL", ",", "Ethnic", ">", "FLEXI4", ",", "Ethnic", ">", "TRYANGULS", ",", "Ethnic", ">", "SITAR", ",", "Ethnic", ">", "SITAR", ",", "Ethnic", ">", "KSITAR1", ",", "Ethnic", ">", "KSITAR2", ",", "Ethnic", ">", "KSITAR3", ",", "Ethnic", ">", "KSITAR4", ",", "Ethnic", ">", "NoNose", ",", "Ethnic", ">", "SITAR1", ",", "Ethnic", ">", "SITAR2", ",", "Ethnic", ">", "SITAR3", ",", "Ethnic", ">", "SITAR4", ",", "Ethnic", ">", "SITAR5", ",", "Ethnic", ">", "SITAR6", ",", "Ethnic", ">", "SITAR7", ",", "Ethnic", ">", "SITAR8", ",", "Ethnic", ">", "SITAR9", ",", "Ethnic", ">", "SITAR10", ",", "Ethnic", ">", "SITAR11", ",", "Ethnic", ">", "SITAR284", ",", "Ethnic", ">", "SITAREG", ",", "Ethnic", ">", "SOFTSITAR", ",", "Ethnic", ">", "SYNSITAR", ",", "Ethnic", ">", "2NOTESIT", ",", "Ethnic", ">", "NEWSITAR", ",", "Ethnic", ">", "Shami", ",", "Ethnic", ">", "BPOPSITAR", ",", "Ethnic", ">", "GHANDITAR1", ",", "Ethnic", ">", "GHANDITAR2", ",", "Ethnic", ">", "PHASITAR", ",", "Ethnic", ">", "SITTABA", ",", "Ethnic", ">", "SitarKC2", ",", "Ethnic", ">", "Sitar2", ",", "Guitar", ">", "ACOUSGUIT", ",", "Guitar", ">", "ACGUITAR1", ",", "Guitar", ">", "ACGUITAR1", ",", "Guitar", ">", "ACGUITAR2", ",", "Guitar", ">", "ACGUITAR3", ",", "Guitar", ">", "ACGUITAR4", ",", "Guitar", ">", "ELECGTR", ",", "Guitar", ">", "EGUITAR1", ",", "Guitar", ">", "EGUITAR2", ",", "Guitar", ">", "EGUITAR3", ",", "Guitar", ">", "EGUITAR4", ",", "Guitar", ">", "EGUITAR5", ",", "Guitar", ">", "EGUITARA", ",", "Guitar", ">", "EGUITARB", ",", "Guitar", ">", "JAZZGUIT1", ",", "Guitar", ">", "JAZZGUIT2", ",", "Guitar", ">", "GUITAR1", ",", "Guitar", ">", "GUITAR2", ",", "Guitar", ">", "GUITAR3", ",", "Guitar", ">", "GUITAR4", ",", "Guitar", ">", "GUITAR5", ",", "Guitar", ">", "GUITAR6", ",", "Guitar", ">", "GUITAR7", ",", "Guitar", ">", "GUITAR8", ",", "Guitar", ">", "NYLONGU1", ",", "Guitar", ">", "NYLONGU2", ",", "Guitar", ">", "NYLONGU3", ",", "Guitar", ">", "NYLONGU4", ",", "Guitar", ">", "NYLONGU5", ",", "Guitar", ">", "PEDSTEEL1", ",", "Guitar", ">", "PEDSTEEL2", ",", "Guitar", ">", "PEDSTEEL3", ",", "Guitar", ">", "GUITAR1", ",", "Guitar", ">", "GUITAR2", ",", "Guitar", ">", "GUITAR3", ",", "Guitar", ">", "GUITAR4", ",", "Guitar", ">", "GUITAR5", ",", "Guitar", ">", "GUITAR6", ",", "Guitar", ">", "JAZZGUIT", ",", "Guitar", ">", "JAZZGUIT1", ",", "Guitar", ">", "JAZZGUIT2", ",", "Guitar", ">", "ClasGtHit1", ",", "Guitar", ">", "ClasGtHit2", ",", "Guitar", ">", "ClasGtNyl1", ",", "Guitar", ">", "ClasGtNyl2", ",", "Guitar", ">", "NylonPick", ",", "Guitar", ">", "NylonPick2", ",", "Guitar", ">", "NylonPck3", ",", "Guitar", ">", "NylonPick4", ",", "Guitar", ">", "PKDGTRSA", ",", "Guitar", ">", "PKDGTRSB", ",", "Guitar", ">", "ClasGtNyl2", ",", "Guitar", ">", "PickGuitar", ",", "Guitar", ">", "PickOctav2", ",", "Guitar", ">", "PickOctave", ",", "Guitar", ">", "Pluck1", ",", "Guitar", ">", "SoftGuitr1", ",", "Guitar", ">", "SteelComb1", ",", "Guitar", ">", "SteelComb2", ",", "Guitar", ">", "NYLONG2TR", ",", "Guitar", ">", "PDSTL295", ",", "Guitar", ">", "PDSTLGUIT", ",", "Guitar", ">", "PEDSTEEL", ",", "Guitar", ">", "JGTR265", ",", "Guitar", ">", "GUITAR1", ",", "Guitar", ">", "GUITAR2", ",", "Guitar", ">", "GUITAR3", ",", "Guitar", ">", "GUITAR4", ",", "Guitar", ">", "GUITAR5", ",", "Guitar", ">", "GUITAR6", ",", "Guitar", ">", "GUITAR7", ",", "Guitar", ">", "GUITAR8", ",", "Guitar", ">", "BANJO", ",", "Guitar", ">", "BANJO1", ",", "Guitar", ">", "BANJO2", ",", "Guitar", ">", "BANJO263", ",", "Guitar", ">", "BANJOTOO", ",", "Guitar", ">", "MANDOLIN1", ",", "Guitar", ">", "MANDOLIN2", ",", "Guitar", ">", "SITAR", ",", "Guitar", ">", "SITAR284", ",", "Guitar", ">", "KOTO", ",", "Guitar", ">", "KOTO283", ",", "Guitar", ">", "LUTE", ",", "Guitar", ">", "BISHGTR1", ",", "Guitar", ">", "CLASGUIT", ",", "Guitar", ">", "FOLKGUIT", ",", "Guitar", ">", "JAZZGUITR", ",", "Guitar", ">", "JOEGUITAR", ",", "Guitar", ">", "LASTTWANG", ",", "Guitar", ">", "LEADGUITR", ",", "Guitar", ">", "METALGUIT", ",", "Guitar", ">", "PHASEGTR", ",", "Guitar", ">", "PWRGUITAR", ",", "Guitar", ">", "ROCKGUIT1", ",", "Guitar", ">", "SOULGITAR", ",", "Harmonica", ">", "ICA1AW", ",", "Harmonica", ">", "ICA16W", ",", "Harmonica", ">", "ICA2cbcC", ",", "Harmonica", ">", "KS1cbcC", ",", "Harmonica", ">", "ICA1cbcC", ",", "Harmonica", ">", "ICA1ccccc", ",", "Harmonica", ">", "HMb2Z", ",", "Harmonica", ">", "KAHKcc", ",", "Harmonica", ">", "IKAcbcC", ",", "Harmonica", ">", "ICA1cbcC", ",", "Harmonica", ">", "2BCAW", ",", "Harmonica", ">", "ICA16W", ",", "Harmonica", ">", "ICA2cbcC", ",", "Harmonica", ">", "ICA1cbcC", ",", "Harmonica", ">", "2BCccccc", ",", "Harmonica", ">", "HMc2Z", ",", "Harmonica", ">", "ION1b2Z", ",", "Harmonica", ">", "ION2c", ",", "Harmonica", ">", "Rizb2Z", ",", "Harmonica", ">", "IONHFcZ", ",", "Harmonica", ">", "2b2Z", ",", "Harmonica", ">", "IONb2Z", ",", "Harmonica", ">", "IONcbcC", ",", "Harmonica", ">", "ICAcbcC", ",", "Harmonica", ">", "ICA1AW", ",", "Harmonica", ">", "ICA16W", ",", "Harmonica", ">", "ICA2NLX", ",", "Harmonica", ">", "ion1cccccc", ",", "Harmonica", ">", "cccccc", ",", "Harmonica", ">", "cccccc", ",", "Harmonica", ">", "cccccc", ",", "Harmonica", ">", "HFcZ", ",", "Harp", ">", "ElHarp", ",", "Harp", ">", "ElHarp", ",", "Harp", ">", "AHARP", ",", "Harp", ">", "AUTOHARP", ",", "Harp", ">", "AUTOHARPY", ",", "Harp", ">", "AUTOHARPY", ",", "Harp", ">", "AUTOHARPY", ",", "Harp", ">", "COSMOHARP", ",", "Harp", ">", "DBHP311", ",", "Harp", ">", "DBHP312", ",", "Harp", ">", "DBLHARPA", ",", "Harp", ">", "DBLHARPB", ",", "Harp", ">", "DBLHARPB", ",", "Harp", ">", "DBLHARPC", ",", "Harp", ">", "DBLHARPD", ",", "Harp", ">", "DBLHARPF", ",", "Harp", ">", "DBLHARPG", ",", "Harp", ">", "DIGIHARPC", ",", "Harp", ">", "DOUBLEHARP", ",", "Harp", ">", "EHARFE", ",", "Harp", ">", "EHARFE", ",", "Harp", ">", "FMHARP", ",", "Harp", ">", "GLASHARP", ",", "Harp", ">", "Glassharp1", ",", "Harp", ">", "GLASSHARP1", ",", "Harp", ">", "Glassharp2", ",", "Harp", ">", "GLASSHARP2", ",", "Harp", ">", "HARPM", ",", "Harp", ">", "HARP1", ",", "Harp", ">", "HARP1", ",", "Harp", ">", "HARP1", ",", "Harp", ">", "HARP1", ",", "Harp", ">", "HARP2", ",", "Harp", ">", "Harp2M", ",", "Harp", ">", "HARP8", ",", "Harp", ">", "HARPA", ",", "Harp", ">", "HARPB", ",", "Harp", ">", "HARPC", ",", "Harp", ">", "HARPX", ",", "Harp", ">", "HARP11", ",", "Harp", ">", "HARP12", ",", "Harp", ">", "Harp3", ",", "Harp", ">", "HARP1", ",", "Harp", ">", "HARP1", ",", "Harp", ">", "HARP2", ",", "Harp", ">", "HARPCD1", ",", "Harp", ">", "HARPFMIN", ",", "Harp", ">", "HARPFMIN", ",", "Harp", ">", "HARPXM2", ",", "Harp", ">", "HARPDOCBOK", ",", "Harp", ">", "HARPFLUT2", ",", "Harp", ">", "HARPFLUT3", ",", "Harp", ">", "HARPFLUT3", ",", "Harp", ">", "HARPFLUTE", ",", "Harp", ">", "HARPFLUTE", ",", "Harp", ">", "HARPIC3", ",", "Harp", ">", "HARPIES", ",", "Harp", ">", "HARPS208", ",", "Harp", ">", "HARPS282", ",", "Harp", ">", "HarpStrum", ",", "Harp", ">", "HarpStrum", ",", "Harp", ">", "HeavenHarp", ",", "Harp", ">", "HIGHHARP", ",", "Harp", ">", "JEWSHARP", ",", "Harp", ">", "LOWHARP", ",", "Harp", ">", "PREHARP1", ",", "Harp", ">", "SamplHarp2", ",", "Harp", ">", "STEVIESHRP", ",", "Harp", ">", "SUPERHARP", ",", "Harp", ">", "SUSHARP1", ",", "Harp", ">", "SYNHARP", ",", "Harp", ">", "SYNHARPSA", ",", "Harp", ">", "WINDHARP3", ",", "Harp", ">", "EtherharpA", ",", "Harp", ">", "EtherharpB", ",", "Harp", ">", "Harp2", ",", "Harp", ">", "HarpCelt1", ",", "Harp", ">", "HarpCelt2", ",", "Harp", ">", "HRPSLUTE8c", ",", "Harp", ">", "HRPSPLUCK2", ",", "Harp", ">", "HRPSPLUCK3", ",", "Harp", ">", "HRPSPLUCK4", ",", "Harpsichord", ">", "HARPIC3", ",", "Harpsichord", ">", "HARPSICH2", ",", "Harpsichord", ">", "HARPSICH3", ",", "Harpsichord", ">", "HARPSICH4", ",", "Harpsichord", ">", "HARPSICH5", ",", "Harpsichord", ">", "HARPSI1A", ",", "Harpsichord", ">", "HARPSI1B", ",", "Harpsichord", ">", "HARPSI1C", ",", "Harpsichord", ">", "HARPSI2A", ",", "Harpsichord", ">", "HARPSI3A", ",", "Harpsichord", ">", "HARPSI3B", ",", "Harpsichord", ">", "HARPSICH3", ",", "Harpsichord", ">", "HARPSI1A", ",", "Harpsichord", ">", "HARPSI2A", ",", "Harpsichord", ">", "HARPSIC1", ",", "Harpsichord", ">", "HARPSICH1", ",", "Harpsichord", ">", "HARPSICH1", ",", "Harpsichord", ">", "HARPSICH1", ",", "Harpsichord", ">", "HARPSICH2", ",", "Harpsichord", ">", "HARPSICH1", ",", "Harpsichord", ">", "HARPSICH2", ",", "Harpsichord", ">", "HARPSICH2", ",", "Harpsichord", ">", "HARPSICH3", ",", "Harpsichord", ">", "HARPSICH2", ",", "Harpsichord", ">", "HARPSICH5", ",", "Harpsichord", ">", "HARPSICH6", ",", "Harpsichord", ">", "HARPSICH7", ",", "Harpsichord", ">", "HARPSICH1", ",", "Harpsichord", ">", "HARPSICH9", ",", "Harpsichord", ">", "HARPSICH10", ",", "Harpsichord", ">", "Harpsich11", ",", "Harpsichord", ">", "Harpsich12", ",", "Harpsichord", ">", "HARPSICH13", ",", "Harpsichord", ">", "HARPSICORD", ",", "Harpsichord", ">", "HARPSIORCH", ",", "Harpsichord", ">", "HSSHARPSI", ",", "Harpsichord", ">", "HSSHARPSI", ",", "Harpsichord", ">", "HSSHARPSI", ",", "Harpsichord", ">", "LECTROHARP", ",", "Harpsichord", ">", "PREHARP1", ",", "Harpsichord", ">", "VSHARPSI", ",", "Harpsichord", ">", "HARPXM2", ",", "Harpsichord", ">", "HARPSIB", ",", "Harpsichord", ">", "HARPSICHRD", ",", "Harpsichord", ">", "HARPSICH1", ",", "Harpsichord", ">", "HARPSICORD", ",", "Harpsichord", ">", "HardRoads", ",", "Harpsichord", ">", "HardRoads", ",", "Harpsichord", ">", "Rhodez", ",", "Harpsichord", ">", "DynoRhoad3", ",", "Harpsichord", ">", "Rhodes", ",", "Harpsichord", ">", "Rhodes", ",", "Mallet", ">", "MARIMBA", ",", "Mallet", ">", "MARIMBA", ",", "Mallet", ">", "PDSMARIMBA", ",", "Mallet", ">", "PLUCVIBE1", ",", "Mallet", ">", "CLICKSINE", ",", "Mallet", ">", "XYLORIFIC", ",", "Mallet", ">", "TORIMTORA2", ",", "Mallet", ">", "RIMBASLRY", ",", "Mallet", ">", "TORIMPLUK", ",", "Mallet", ">", "MARIMBA", ",", "Mallet", ">", "MARIMBAXX", ",", "Mallet", ">", "MARIMBASSL", ",", "Mallet", ">", "MARIMBCLAV", ",", "Mallet", ">", "MELL0RIMBA", ",", "Mallet", ">", "XYLOPHONE", ",", "Mallet", ">", "GLOKENSPL", ",", "Mallet", ">", "GLOKENSPL", ",", "Mallet", ">", "VIBE", ",", "Mallet", ">", "VIBE1", ",", "Mallet", ">", "VIBE2", ",", "Mallet", ">", "VIBRARHODE", ",", "Mallet", ">", "CELEST101", ",", "Mallet", ">", "CELESTE1", ",", "Mallet", ">", "CELESTE", ",", "Mallet", ">", "CELESTE", ",", "Mallet", ">", "CELEST13", ",", "Mallet", ">", "CLUNKONUM2", ",", "Mallet", ">", "CLICKSINE", ",", "Mallet", ">", "AMALLETA", ",", "Mallet", ">", "VIBESA", ",", "Mallet", ">", "VIBE", ",", "Mallet", ">", "KARIMBAA", ",", "Mallet", ">", "BLOCK", ",", "Mallet", ">", "c", ",", "Mallet", ">", "MARIMBA", ",", "Mallet", ">", "cP9", ",", "Mallet", ">", "MARIMBA11", ",", "Mallet", ">", "cP", ",", "Mallet", ">", "MARIMBA14", ",", "Mallet", ">", "cP", ",", "Mallet", ">", "MARIMBA2", ",", "Mallet", ">", "cP", ",", "Mallet", ">", "MARIMBA4", ",", "Mallet", ">", "cP9", ",", "Mallet", ">", "MARIMBA6", ",", "Mallet", ">", "cP8", ",", "Mallet", ">", "MARIMBA8", ",", "Mallet", ">", "cP9", ",", "Mallet", ">", "PLUCVIBE1", ",", "Mallet", ">", "cP9", ",", "Mallet", ">", "SWISHBELL", ",", "Mallet", ">", "cP", ",", "Mallet", ">", "VIBESYN2", ",", "Mallet", ">", "cP", ",", "Marimba", ">", "ExcMarim", ",", "Marimba", ">", "MARIMBA", ",", "Marimba", ">", "MARIMBA", ",", "Marimba", ">", "MARIMBA", ",", "Marimba", ">", "MARIMBA", ",", "Marimba", ">", "MARIMBA", ",", "Marimba", ">", "MARIMBA", ",", "Marimba", ">", "MARIMBA", ",", "Marimba", ">", "MARIMBA", ",", "Marimba", ">", "MARIMBA", ",", "Marimba", ">", "MARIMBA", ",", "Marimba", ">", "MARIMBA", ",", "Marimba", ">", "MARIMBAA", ",", "Marimba", ">", "MARIMBA10", ",", "Marimba", ">", "MARIMBA2", ",", "Marimba", ">", "MARIMBA3", ",", "Marimba", ">", "MARIMBA4", ",", "Marimba", ">", "MARIMBA5", ",", "Marimba", ">", "MARIMBA6", ",", "Marimba", ">", "MARIMBA7", ",", "Marimba", ">", "MARIMBA9", ",", "Marimba", ">", "MARIMBA9", ",", "Marimba", ">", "MARIMBAEP", ",", "Marimba", ">", "MARIMBAJL", ",", "Marimba", ">", "MARIMBAMO", ",", "Marimba", ">", "TakMrimba", ",", "Marimba", ">", "Marimba18", ",", "Marimba", ">", "Marimba19", ",", "Marimba", ">", "MARIMGUIT", ",", "Marimba", ">", "MARIMBA", ",", "Marimba", ">", "MARIMBA2", ",", "Marimba", ">", "MARIMBA3", ",", "Marimba", ">", "MARIMBA4", ",", "Marimba", ">", "MARIMBA5", ",", "Marimba", ">", "MARIMBA6", ",", "Marimba", ">", "MARIMBA7", ",", "Marimba", ">", "MARIMBA8", ",", "Marimba", ">", "MARIMBA9", ",", "Marimba", ">", "MARIMBA10", ",", "Marimba", ">", "MARIMBONE", ",", "Marimba", ">", "PIANOMRMBA", ",", "Marimba", ">", "PLUCVIBE1", ",", "Marimba", ">", "PLUCVIBE2", ",", "Marimba", ">", "RBPLUCK", ",", "Marimba", ">", "RIMBASLRY", ",", "Marimba", ">", "SWISHBELL", ",", "Marimba", ">", "TORIMPLUK", ",", "Marimba", ">", "TORIMTORA2", ",", "Marimba", ">", "TorimLong", ",", "Marimba", ">", "TormShort", ",", "Marimba", ">", "UTAHMBA", ",", "Marimba", ">", "AFRICA", ",", "Marimba", ">", "ARIMBAc", ",", "Marimba", ">", "ARIMBAAc", ",", "Marimba", ">", "BLOCK", ",", "Marimba", ">", "DRUM4", ",", "Marimba", ">", "KARIMBAA", ",", "Marimba", ">", "LOGDRUM", ",", "Marimba", ">", "MALLETEFX", ",", "Marimba", ">", "NEWPERCTOY", ",", "Marimba", ">", "WOODCHIPS", ",", "Orchestra", ">", "Ensemble1", ",", "Orchestra", ">", "Ensemble3", ",", "Orchestra", ">", "2001Bell", ",", "Orchestra", ">", "2001INTRO", ",", "Orchestra", ">", "2NDORCHMW", ",", "Orchestra", ">", "ARPA2", ",", "Orchestra", ">", "ARPEGGIO1", ",", "Orchestra", ">", "BASSORCH", ",", "Orchestra", ">", "Bellstrad", ",", "Orchestra", ">", "Bellstrad", ",", "Orchestra", ">", "BELLSTRGS", ",", "Orchestra", ">", "BRITEFULL", ",", "Orchestra", ">", "CARNIVAL", ",", "Orchestra", ">", "CHAMBERORC", ",", "Orchestra", ">", "CHAMBERORC", ",", "Orchestra", ">", "CHRISTHARP", ",", "Orchestra", ">", "CHRISTMAS", ",", "Orchestra", ">", "CHRISTMAS1", ",", "Orchestra", ">", "CHRISTMAS2", ",", "Orchestra", ">", "CLICKENS", ",", "Orchestra", ">", "CONTRABASS", ",", "Orchestra", ">", "CONTRABASS", ",", "Orchestra", ">", "CONTRAFASS", ",", "Orchestra", ">", "DONNAENSML", ",", "Orchestra", ">", "ELECORCH", ",", "Orchestra", ">", "ELECORCH", ",", "Orchestra", ">", "EleCelloA", ",", "Orchestra", ">", "EleCelloA", ",", "Orchestra", ">", "EleCelloB", ",", "Orchestra", ">", "Ensemble", ",", "Orchestra", ">", "Ensemble", ",", "Orchestra", ">", "ENSEMBLE1", ",", "Orchestra", ">", "ENSEMBLE2", ",", "Orchestra", ">", "ENSEMBLE3", ",", "Orchestra", ">", "ENSEMBLE1", ",", "Orchestra", ">", "Ensemble2", ",", "Orchestra", ">", "fullorch", ",", "Orchestra", ">", "fullorch", ",", "Orchestra", ">", "HallOrchA", ",", "Orchestra", ">", "HallOrchA", ",", "Orchestra", ">", "HallOrchB", ",", "Orchestra", ">", "HallOrchB", ",", "Orchestra", ">", "HallOrchB", ",", "Orchestra", ">", "JAVARESE", ",", "Orchestra", ">", "KRORCH", ",", "Orchestra", ">", "LASPEQUE", ",", "Orchestra", ">", "LOWDBLHRP", ",", "Orchestra", ">", "METALHARP", ",", "Orchestra", ">", "ORCHCHIME", ",", "Orchestra", ">", "ORCHCHIME", ",", "Orchestra", ">", "ORCHCHIME", ",", "Orchestra", ">", "ORCHEST2", ",", "Orchestra", ">", "ORCHEST2", ",", "Orchestra", ">", "ORCHEST2", ",", "Orchestra", ">", "ORCHEST3", ",", "Orchestra", ">", "ORCHEST3", ",", "Orchestra", ">", "ORCHEST6", ",", "Orchestra", ">", "ORCHEST7", ",", "Orchestra", ">", "ORCHESTER", ",", "Orchestra", ">", "Orchestra", ",", "Orchestra", ">", "ORCHESTRA", ",", "Orchestra", ">", "Orchestra", ",", "Orchestra", ">", "ORCHESTRA", ",", "Orchestra", ">", "ORCHESTRA", ",", "Orchestra", ">", "ORCHESTRA", ",", "Orchestra", ">", "ORCHESTRA", ",", "Orchestra", ">", "ORCHESTRA", ",", "Orchestra", ">", "ORCHESTRA", ",", "Orchestra", ">", "ORCHESTRA", ",", "Orchestra", ">", "Orchestra", ",", "Orchestra", ">", "ORCHESTRA1", ",", "Orchestra", ">", "ORCHESTRA1", ",", "Orchestra", ">", "ORCHESTRA3", ",", "Orchestra", ">", "ORCHESTRA5", ",", "Orchestra", ">", "ORCHESTRA6", ",", "Orchestra", ">", "ORCHESTRA7", ",", "Orchestra", ">", "Orchestra8", ",", "Orchestra", ">", "ORCHESTRAL", ",", "Orchestra", ">", "ORCHESTRAL", ",", "Orchestra", ">", "ORCHSTRGS", ",", "Orchestra", ">", "ORCSTRLM", ",", "Orchestra", ">", "PICKIT", ",", "Orchestra", ">", "RevsOrch1", ",", "Orchestra", ">", "RONT", ",", "Orchestra", ">", "SLOWORCH", ",", "Orchestra", ">", "SLOWORCH", ",", "Orchestra", ">", "SYNORCH", ",", "Orchestra", ">", "SYNORCH1", ",", "Orchestra", ">", "SYNORCH2", ",", "Orchestra", ">", "SYNORCH4", ",", "Orchestra", ">", "TOMBORCH", ",", "Orchestra", ">", "TOMBORCH", ",", "Orchestra", ">", "TOUCHENS", ",", "Orchestra", ">", "VOLLWEILE", ",", "Orchestra", ">", "WCORCH", ",", "Orchestra", ">", "WEDDNGMCH", ",", "Orchestra", ">", "X42", ",", "Orchestra", ">", "XMAS1", ",", "Orchestra", ">", "XMAS2V", ",", "Orchestra", ">", "NEOPIANORC", ",", "Orchestra", ">", "PIANORCH2", ",", "Organ", ">", "PIPES1", ",", "Organ", ">", "PIPES2", ",", "Organ", ">", "PIPES3", ",", "Organ", ">", "PIPES4", ",", "Organ", ">", "PIPES5", ",", "Organ", ">", "PIPES6", ",", "Organ", ">", "PIPES33", ",", "Organ", ">", "PIPES8", ",", "Organ", ">", "PIPES9", ",", "Organ", ">", "PIPES35", ",", "Organ", ">", "PIPES11", ",", "Organ", ">", "PIPES12", ",", "Organ", ">", "PIPES36", ",", "Organ", ">", "PIPES14", ",", "Organ", ">", "PIPES37", ",", "Organ", ">", "PIPES", ",", "Organ", ">", "PIPES17", ",", "Organ", ">", "PIPES8B", ",", "Organ", ">", "PIPES19", ",", "Organ", ">", "PIPES20", ",", "Organ", ">", "PIPES21", ",", "Organ", ">", "PIPES22", ",", "Organ", ">", "PIPES23", ",", "Organ", ">", "PIPES24", ",", "Organ", ">", "PIPES25", ",", "Organ", ">", "PIPES26", ",", "Organ", ">", "PIPES27", ",", "Organ", ">", "PIPES28", ",", "Organ", ">", "PIPES29", ",", "Organ", ">", "PIPES30", ",", "Organ", ">", "PIPES31", ",", "Organ", ">", "PIPES19", ",", "Organ", ">", "PIPEORGAN", ",", "Organ", ">", "PIPEORGAN", ",", "Organ", ">", "PIPEORGAN3", ",", "Organ", ">", "FullPipes", ",", "Organ", ">", "SMALLPIPE1", ",", "Organ", ">", "SMALLPIPE2", ",", "Organ", ">", "SMALLPIPE3", ",", "Organ", ">", "SMALLPIPE4", ",", "Organ", ">", "SMALLPIPE5", ",", "Organ", ">", "SMALL1PIPE", ",", "Organ", ">", "SMALL2PIPE", ",", "Organ", ">", "SMALL3PIPE", ",", "Organ", ">", "SYNPIPES", ",", "Organ", ">", "WINDPIPE2", ",", "Organ", ">", "POrgan2", ",", "Organ", ">", "POrgan3", ",", "Organ", ">", "PORG31", ",", "Organ", ">", "PORG32", ",", "Organ", ">", "PORG33", ",", "Organ", ">", "PORG34", ",", "Organ", ">", "PORG38", ",", "Organ", ">", "SoloPipe", ",", "Organ", ">", "PIPES3A", ",", "Organ", ">", "PIPES1", ",", "Organ", ">", "ChurchPipe", ",", "Organ", ">", "Pipes1", ",", "Organ", ">", "Pipes2", ",", "Organ", ">", "Pipes3", ",", "Organ", ">", "Pipes4", ",", "Organ", ">", "Pipes5", ",", "Organ", ">", "PIPEORG5", ",", "Organ", ">", "PIPEORG6", ",", "Percussion", ">", "CASTANET1", ",", "Percussion", ">", "CASTANET2", ",", "Percussion", ">", "CASTENETS", ",", "Percussion", ">", "CHIPB123", ",", "Percussion", ">", "CLHIHAT", ",", "Percussion", ">", "CLAVES", ",", "Percussion", ">", "CLUNKONUM2", ",", "Percussion", ">", "CONGAS1", ",", "Percussion", ">", "CONGAS2", ",", "Percussion", ">", "COWBELL", ",", "Percussion", ">", "COWBELL1", ",", "Percussion", ">", "COWBELL2", ",", "Percussion", ">", "COWBELL3", ",", "Percussion", ">", "COWBELL", ",", "Percussion", ">", "CRASHCYMB", ",", "Percussion", ">", "CSTNT298", ",", "Percussion", ">", "DROOBOARDZ", ",", "Percussion", ">", "EXTRADX1", ",", "Percussion", ">", "FLEXATONE", ",", "Percussion", ">", "FLEXI4", ",", "Percussion", ">", "GONG", ",", "Percussion", ">", "GUIRO", ",", "Percussion", ">", "HANDCLAP1", ",", "Percussion", ">", "HANDCLAP2", ",", "Percussion", ">", "HANDCLAPS", ",", "Percussion", ">", "HANDDRUMS", ",", "Percussion", ">", "HANDDRUMD", ",", "Percussion", ">", "HDRUM318", ",", "Percussion", ">", "HIHAT", ",", "Percussion", ">", "KABASA", ",", "Percussion", ">", "KARIMBA", ",", "Percussion", ">", "KARIMBAA", ",", "Percussion", ">", "AGOGO", ",", "Percussion", ">", "BELLTREE", ",", "Percussion", ">", "BLOCK", ",", "Percussion", ">", "BLTL321", ",", "Percussion", ">", "BLTR322", ",", "Percussion", ">", "JHPERC5", ",", "Percussion", ">", "MARACAS", ",", "Percussion", ">", "MARIMBA", ",", "Percussion", ">", "MBLOK248", ",", "Percussion", ">", "MICHAEL", ",", "Percussion", ">", "MTLBLOCKS", ",", "Percussion", ">", "NEWPERCTOY", ",", "Percussion", ">", "PERORCH", ",", "Percussion", ">", "PERCECHO", ",", "Percussion", ">", "PERCWATER", ",", "Percussion", ">", "PERCYCPIU", ",", "Percussion", ">", "PERCUSSION", ",", "Percussion", ">", "POLYPERC", ",", "Percussion", ">", "QKR288", ",", "Percussion", ">", "QUEKER", ",", "Percussion", ">", "QUIEKER", ",", "Percussion", ">", "RCYMBALB", ",", "Percussion", ">", "REVCYMB1", ",", "Percussion", ">", "REVCYMB2", ",", "Percussion", ">", "RUBBAGONG", ",", "Percussion", ">", "SAMBAWHIS", ",", "Percussion", ">", "SIZCYMB", ",", "Percussion", ">", "SIZLECYMB", ",", "Percussion", ">", "SKINMETAL", ",", "Percussion", ">", "SKLS278", ",", "Percussion", ">", "SKULLS", ",", "Percussion", ">", "SMALLBELL", ",", "Percussion", ">", "STARCYMB", ",", "Percussion", ">", "SUMOUARINA", ",", "Percussion", ">", "SWISHBELL", ",", "Percussion", ">", "SYNPERC1", ",", "Percussion", ">", "SYNPERC2", ",", "Percussion", ">", "SYNPERC3", ",", "Percussion", ">", "SYNPERC4", ",", "Percussion", ">", "SYNPERC5", ",", "Percussion", ">", "SYNPERC6", ",", "Percussion", ">", "SYNPERC7", ",", "Percussion", ">", "SYNPERC8", ",", "Percussion", ">", "SYNPERC9", ",", "Percussion", ">", "TBLEXPA", ",", "Percussion", ">", "TAMBLN1", ",", "Percussion", ">", "TAMBLN2", ",", "Percussion", ">", "TAMBORINE", ",", "Percussion", ">", "TAMBOURINE", ",", "Percussion", ">", "TAPSLAP", ",", "Percussion", ">", "THWACKTOM", ",", "Percussion", ">", "TIMBALES", ",", "Percussion", ">", "TIMBALES1", ",", "Percussion", ">", "TIMBALES2", ",", "Percussion", ">", "TIMBALI", ",", "Percussion", ">", "TIMBALI1", ",", "Percussion", ">", "TIMPANI", ",", "Percussion", ">", "TIMPANI1", ",", "Percussion", ">", "TIMPANI2", ",", "Percussion", ">", "TIMPANI2", ",", "Percussion", ">", "TIMPANIMW", ",", "Percussion", ">", "TMB268", ",", "Percussion", ">", "TMBRN308", ",", "Percussion", ">", "UBANGI", ",", "Percussion", ">", "TRIANGLE", ",", "Percussion", ">", "TRIANGLE1", ",", "Percussion", ">", "TRIANGLE2", ",", "Percussion", ">", "TRIGL328", ",", "Percussion", ">", "TRYANGULS", ",", "Percussion", ">", "TUNEDBLK", ",", "Percussion", ">", "WBLOCK1", ",", "Percussion", ">", "WBLOCK2", ",", "Percussion", ">", "WINDBELL1", ",", "Percussion", ">", "WINDBELL2", ",", "Percussion", ">", "WOODBLOCK", ",", "Percussion", ">", "WOODCHIPS", ",", "Percussion", ">", "5THLOGHIT", ",", "Percussion", ">", "AMALLETA", ",", "Percussion", ">", "AMALLETB", ",", "Percussion", ">", "AFMAL241", ",", "Percussion", ">", "BAMBOOMAR", ",", "Percussion", ">", "BAROOMBA", ",", "Percussion", ">", "BDWHOCARES", ",", "Percussion", ">", "BEATMEHARD", ",", "Percussion", ">", "BEATMEHRDR", ",", "Percussion", ">", "BSSNRT0M", ",", "Percussion", ">", "JAMACA", ",", "Percussion", ">", "JAMAICA", ",", "Percussion", ">", "JANPANY", ",", "Percussion", ">", "JCDRUM1", ",", "Percussion", ">", "JMISLANDS", ",", "Percussion", ">", "JPNDRUM1", ",", "Percussion", ">", "JPNDRUM2", ",", "Percussion", ">", "JPNDRUM3", ",", "Percussion", ">", "JPNDRUM4", ",", "Percussion", ">", "JUNGLEDRUM", ",", "Percussion", ">", "DRUM1", ",", "Percussion", ">", "DRUM2", ",", "Percussion", ">", "DRUM3", ",", "Percussion", ">", "DRUMS", ",", "Percussion", ">", "EDRUMS1", ",", "Percussion", ">", "EDRUMS2", ",", "Percussion", ">", "EDRUMS3", ",", "Percussion", ">", "EDRUMS4", ",", "Percussion", ">", "EDRUMS5", ",", "Percussion", ">", "SIMMONS", ",", "Percussion", ">", "SIMMONS2", ",", "Percussion", ">", "SIMMONS", ",", "Percussion", ">", "SIMMONS2", ",", "Percussion", ">", "SIMMONSSN", ",", "Percussion", ">", "SIMMONS2MH", ",", "Percussion", ">", "SIMMONSNAR", ",", "Percussion", ">", "SNAREDR1", ",", "Percussion", ">", "SNAREDR2", ",", "Percussion", ">", "SYNDRUM1", ",", "Percussion", ">", "SYNDRUM2", ",", "Percussion", ">", "SYNDRUMKBD", ",", "Percussion", ">", "Simmmons1", ",", "Percussion", ">", "Sinnndrum1", ",", "Percussion", ">", "TOMBLOW", ",", "Percussion", ">", "TOMHERZ", ",", "Percussion", ">", "TOMTOMS", ",", "Percussion", ">", "TOMTOM1", ",", "Percussion", ">", "TOMTOM2", ",", "Percussion", ">", "ACOUSTOMS", ",", "Percussion", ">", "SOFTHEAD", ",", "Percussion", ">", "SYNTOMS3", ",", "Percussion", ">", "SYNDM258", ",", "Percussion", ">", "JUNGLEVINE", ",", "Percussion", ">", "LOGDRUM", ",", "Percussion", ">", "LOGDRUMS", ",", "Percussion", ">", "MALL241", ",", "Percussion", ">", "MALR242", ",", "Percussion", ">", "MANGLEDRUM", ",", "Percussion", ">", "MarimPi1", ",", "Percussion", ">", "ODABL128", ",", "Percussion", ">", "PIANOMRMBA", ",", "Percussion", ">", "PLUK161", ",", "Percussion", ">", "RIMBASLRY", ",", "Percussion", ">", "ROTOTOMS", ",", "Percussion", ">", "STDM286", ",", "Percussion", ">", "STEELDRUM", ",", "Percussion", ">", "STLDRUM1", ",", "Percussion", ">", "STLDRUM2", ",", "Percussion", ">", "SYNDRUM", ",", "Percussion", ">", "TomTomTom", ",", "Percussion", ">", "BDRMSNAR", ",", "Percussion", ">", "BASSDR1", ",", "Percussion", ">", "BASSDR2", ",", "Percussion", ">", "KICKDRUM", ",", "Piano", ">", "PIANO1", ",", "Piano", ">", "PIANO2", ",", "Piano", ">", "PIANO3", ",", "Piano", ">", "PIANO4", ",", "Piano", ">", "PIANO5", ",", "Piano", ">", "PIANO6", ",", "Piano", ">", "PIANO7", ",", "Piano", ">", "PIANO8", ",", "Piano", ">", "PIANO9", ",", "Piano", ">", "PIANO10", ",", "Piano", ">", "PIANOONE", ",", "Piano", ">", "PIANOTWO", ",", "Piano", ">", "STEINWAY", ",", "Piano", ">", "STEINWAY6", ",", "Piano", ">", "STEVENSNYC", ",", "Piano", ">", "SUPERPIANO", ",", "Piano", ">", "BOSENDORF", ",", "Piano", ">", "BOSENDORF", ",", "Piano", ">", "FMPIANOA", ",", "Piano", ">", "FMPIANOB", ",", "Piano", ">", "FRANKYSPLT", ",", "Piano", ">", "GODFATHER", ",", "Piano", ">", "GRANDLH", ",", "Piano", ">", "GRANDPIAN", ",", "Piano", ">", "GRANDPRIX", ",", "Piano", ">", "GRANDPAP", ",", "Piano", ">", "GRANDPIANO", ",", "Piano", ">", "GRANDSON", ",", "Piano", ">", "HKPIANO1", ",", "Piano", ">", "HKPIANO2", ",", "Piano", ">", "HONKEYPF", ",", "Piano", ">", "HONKYTONK", ",", "Piano", ">", "KURZWEIL", ",", "Piano", ">", "LFTCHSPNO", ",", "Piano", ">", "LOWPIANO", ",", "Piano", ">", "OHNOAPIANO", ",", "Piano", ">", "PHOEBEC", ",", "Piano", ">", "PIANNEROLA", ",", "Piano", ">", "REVESPINO", ",", "Piano", ">", "RICSTEVENS", ",", "Piano", ">", "SOUNDBOARD", ",", "Piano", ">", "SPINETPNO", ",", "Piano", ">", "WATERPIANO", ",", "Piano", ">", "WURLITZER", ",", "Piano", ">", "WURLTZER", ",", "Piano", ">", "ACPNO1A", ",", "Piano", ">", "ACPNO2A", ",", "Piano", ">", "ACPNO11", ",", "Piano", ">", "APNO173", ",", "Piano", ">", "ACUPRIGHT", ",", "Piano", ">", "ACPIBO8", ",", "Piano", ">", "ACCPIANO", ",", "Piano", ">", "BALDWIN", ",", "Piano", ">", "CCPIANO2", ",", "Piano", ">", "CHORUSPNO2", ",", "Piano", ">", "ECEMBALO", ",", "Piano", ">", "EADGBE", ",", "Piano", ">", "ECH0PIANO", ",", "Piano", ">", "PIANOLEAD", ",", "Piano", ">", "PLEPIARD", ",", "Piano", ">", "PNOPB1", ",", "Piano", ">", "PNOB13", ",", "Piano", ">", "PREPPIANO", ",", "Piano", ">", "RUFFPIANO", ",", "Piano", ">", "PIANO1", ",", "Piano", ">", "PIANO1A", ",", "Piano", ">", "PIANO2", ",", "Piano", ">", "PIANO2A", ",", "Piano", ">", "PIANO3", ",", "Piano", ">", "PIANO4", ",", "Piano", ">", "PIANO5", ",", "Piano", ">", "CEMBALO1", ",", "Piano", ">", "CEMBALO2", ",", "Piano", ">", "CONGRNDB", ",", "Piano", ">", "MPNO113", ",", "Piano", ">", "OKFMPIAN", ",", "Piano", ">", "PIANO010", ",", "Piano", ">", "PIANO5THS", ",", "Piano", ">", "PIANOCP", ",", "Piano", ">", "PIANO1", ",", "Piano", ">", "PIANO2", ",", "Piano", ">", "PIANO3", ",", "Piano", ">", "PNO1223451", ",", "Piano", ">", "TPNO68", ",", "Piano", ">", "THNDRBPN1", ",", "Piano", ">", "TOYPIANO", ",", "Piano", ">", "WPNO114", ",", "Piano", ">", "PIANOMRMBA", ",", "Plucked", ">", "PIANO4", ",", "Plucked", ">", "PIANO5", ",", "Plucked", ">", "EPIANO2", ",", "Plucked", ">", "EPIANO3", ",", "Plucked", ">", "EPIANO4", ",", "Plucked", ">", "PIANO5THS", ",", "Plucked", ">", "CELESTE", ",", "Plucked", ">", "TOYPIANO", ",", "Plucked", ">", "HARPSICH2", ",", "Plucked", ">", "HARPSICH3", ",", "Plucked", ">", "CLAV2", ",", "Plucked", ">", "CLAV3", ",", "Plucked", ">", "EORGAN2", ",", "Plucked", ">", "EORGAN3", ",", "Plucked", ">", "EORGAN4", ",", "Plucked", ">", "EORGAN5", ",", "Plucked", ">", "PIPES2", ",", "Plucked", ">", "PIPES3", ",", "Plucked", ">", "PIPES4", ",", "Plucked", ">", "CALIOPE", ",", "Plucked", ">", "ACCORDION", ",", "Plucked", ">", "SITAR", ",", "Plucked", ">", "GUITAR3", ",", "Plucked", ">", "GUITAR4", ",", "Plucked", ">", "GUITAR5", ",", "Plucked", ">", "GUITAR6", ",", "Plucked", ">", "LUTE", ",", "Plucked", ">", "BANJO", ",", "Plucked", ">", "HARP1", ",", "Plucked", ">", "HARP2", ",", "Plucked", ">", "BASS3", ",", "Plucked", ">", "BASS4", ",", "Plucked", ">", "RBPLUCK", ",", "Plucked", ">", "Ghanditar", ",", "Plucked", ">", "RevZork2", ",", "Plucked", ">", "VERA", ",", "Plucked", ">", "KOTOXX", ",", "Plucked", ">", "GANJO", ",", "Plucked", ">", "CLAV1A", ",", "Plucked", ">", "MEDLXPRSV", ",", "Plucked", ">", "ELECCONGA", ",", "Plucked", ">", "000PF", ",", "Plucked", ">", "001PF", ",", "Plucked", ">", "003PF", ",", "Plucked", ">", "HONKPF", ",", "Plucked", ">", "PRETTYWAH", ",", "Plucked", ">", "DEVILTACK", ",", "Plucked", ">", "JAWTHING", ",", "Plucked", ">", "DELAYSX3", ",", "Plucked", ">", "AUTOHARP", ",", "Plucked", ">", "KOTO88", ",", "Plucked", ">", "KOTOXX", ",", "Plucked", ">", "JJJJJJJJJJ", ",", "Plucked", ">", "BOWOANO21", ",", "Plucked", ">", "KNOCWURST1", ",", "Plucked", ">", "SYNFLUT2", ",", "Plucked", ">", "KNUKLAVA", ",", "Plucked", ">", "BowedRoad", ",", "Plucked", ">", "SAHARA", ",", "Plucked", ">", "SLIDEGLASS", ",", "Plucked", ">", "RINGMOD", ",", "Plucked", ">", "SPACACC", ",", "Plucked", ">", "PBGONGA1", ",", "Plucked", ">", "PLUCKEDRUM", ",", "Plucked", ">", "1cO", ",", "Plucked", ">", "22O", ",", "Plucked", ">", "3F0c", ",", "Plucked", ">", "4TcU", ",", "Plucked", ">", "asscUcM", ",", "Plucked", ">", "in1cUcM", ",", "Plucked", ">", "in2c", ",", "Plucked", ">", "rumcAD", ",", "Plucked", ">", "ngyR50cQ", ",", "Plucked", ">", "cPcI", ",", "Plucked", ">", "en1R5ccQ", ",", "Plucked", ">", "en2ccb", ",", "Plucked", ">", "1cCc0", ",", "Plucked", ">", "2cQc", ",", "Plucked", ">", "3ccb", ",", "Plucked", ">", "4c", ",", "Plucked", ">", "5cb", ",", "Plucked", ">", "6c3", ",", "Plucked", ">", "7ccb", ",", "Plucked", ">", "8ccb", ",", "Plucked", ">", "9RLLK", ",", "Plucked", ">", "10cccc", ",", "Plucked", ">", "11cLcV", ",", "Plucked", ">", "o1c5c", ",", "Plucked", ">", "o20O", ",", "Plucked", ">", "1HGca", ",", "Plucked", ">", "2RJcY", ",", "Plucked", ">", "3Z5Ic", ",", "Plucked", ">", "4KU", ",", "Plucked", ">", "5HGcca", ",", "Plucked", ">", "DD4EacU", ",", "Plucked", ">", "COS", ",", "Plucked", ">", "D16bcHGcca", ",", "Plucked", ">", "D16cHGcca", ",", "Plucked", ">", "KVSHGcca", ",", "Plucked", ">", "R4HGcca", ",", "Plucked", ">", "R8HGcca", ",", "Plucked", ">", "TE8ccU", ",", "Plucked", ">", "UCK2cU", ",", "Plucked", ">", "UCK3cU", ",", "Plucked", ">", "UCK4V8cU", ",", "Plucked", ">", "aV8cU", ",", "Plucked", ">", "a2", ",", "Plucked", ">", "RBPLUCK", ",", "Plucked", ">", "Ghanditar", ",", "Plucked", ">", "RevZork2", ",", "Plucked", ">", "VERA", ",", "Plucked", ">", "KOTOXX", ",", "Plucked", ">", "GANJO", ",", "Plucked", ">", "CLAV1A", ",", "Plucked", ">", "MEDLXPRSV", ",", "Plucked", ">", "ELECCONGA", ",", "Plucked", ">", "000PF", ",", "Plucked", ">", "001PF", ",", "Plucked", ">", "003PF", ",", "Plucked", ">", "HONKPF", ",", "Plucked", ">", "PRETTYWAH", ",", "Plucked", ">", "DEVILTACK", ",", "Plucked", ">", "JAWTHING", ",", "Plucked", ">", "DELAYSX3", ",", "Plucked", ">", "AUTOHARP", ",", "Plucked", ">", "KOTO88", ",", "Plucked", ">", "KOTOXX", ",", "Plucked", ">", "JJJJJJJJJJ", ",", "Plucked", ">", "BOWOANO21", ",", "Plucked", ">", "KNOCWURST1", ",", "Plucked", ">", "SYNFLUT2", ",", "Plucked", ">", "KNUKLAVA", ",", "Plucked", ">", "BowedRoad", ",", "Plucked", ">", "SAHARA", ",", "Plucked", ">", "SLIDEGLASS", ",", "Plucked", ">", "RINGMOD", ",", "Plucked", ">", "SPACACC", ",", "Plucked", ">", "PBGONGA1", ",", "Plucked", ">", "PLUCKEDRUM", ",", "Sax", ">", "Sax", ",", "Sax", ">", "AltoSxHM", ",", "Sax", ">", "BRASSSAXS", ",", "Sax", ">", "HIGHSAX", ",", "Sax", ">", "SAXBC1", ",", "Sax", ">", "SAXBC2", ",", "Sax", ">", "SAXBC3", ",", "Sax", ">", "SAXBC4", ",", "Sax", ">", "SAXBC7", ",", "Sax", ">", "SAXBC8", ",", "Sax", ">", "SAXBC12", ",", "Sax", ">", "SAXBC13", ",", "Sax", ">", "SAXBC14", ",", "Sax", ">", "SAXBC15", ",", "Sax", ">", "SAXBC16", ",", "Sax", ">", "SAXBC17", ",", "Sax", ">", "SAXBC18", ",", "Sax", ">", "SAXBC19", ",", "Sax", ">", "SAXBC20", ",", "Sax", ">", "SAX2", ",", "Sax", ">", "SAXBC", ",", "Sax", ">", "SAXBC", ",", "Sax", ">", "SAXBC", ",", "Sax", ">", "SAXBC", ",", "Sax", ">", "SAXKS12", ",", "Sax", ">", "SAXKS14", ",", "Sax", ">", "SAXKS22", ",", "Sax", ">", "SAXY11", ",", "Sax", ">", "SAXY12", ",", "Sax", ">", "SAXY13", ",", "Sax", ">", "SAX1", ",", "Sax", ">", "SAXBRASS", ",", "Sax", ">", "SAXOPHONE", ",", "Sax", ">", "SAXOPHONE1", ",", "Sax", ">", "SAXOPHONE2", ",", "Sax", ">", "SAXOPHONE3", ",", "Sax", ">", "SAXOPHONE4", ",", "Sax", ">", "SAXOPHONE7", ",", "Sax", ">", "SaxophoneM", ",", "Sax", ">", "STKSAX1", ",", "Sax", ">", "Saxlo1bc", ",", "Sax", ">", "Saxlo2", ",", "Sax", ">", "Saxlo3bc", ",", "Sax", ">", "Saxlo5bc", ",", "Sax", ">", "Saxmed2bc", ",", "Sax", ">", "Saxmed3bc", ",", "Sax", ">", "Saxmed4", ",", "Sax", ">", "Saxmed6bc", ",", "Strings", ">", "CELLO1", ",", "Strings", ">", "CELLO2", ",", "Strings", ">", "CELLO3", ",", "Strings", ">", "CELLO4", ",", "Strings", ">", "CELLO5", ",", "Strings", ">", "CELLO6", ",", "Strings", ">", "CELLO7", ",", "Strings", ">", "CELLO71", ",", "Strings", ">", "CELLO72", ",", "Strings", ">", "CELLO73", ",", "Strings", ">", "CELLO74", ",", "Strings", ">", "CELLO75", ",", "Strings", ">", "CELLO76", ",", "Strings", ">", "CELLO77", ",", "Strings", ">", "CELLO77", ",", "Strings", ">", "CELLO78", ",", "Strings", ">", "CELLO78", ",", "Strings", ">", "CELLO8", ",", "Strings", ">", "CELLO9", ",", "Strings", ">", "CELLO10", ",", "Strings", ">", "CELLO11", ",", "Strings", ">", "CELLO13", ",", "Strings", ">", "CELLO217", ",", "Strings", ">", "CELLO231", ",", "Strings", ">", "CELLO231", ",", "Strings", ">", "CELLO232", ",", "Strings", ">", "CELLO233", ",", "Strings", ">", "CELLO233", ",", "Strings", ">", "CELLO234", ",", "Strings", ">", "BOWCELLO", ",", "Strings", ">", "BOWCELLO", ",", "Strings", ">", "HARDCELLO", ",", "Strings", ">", "CELLOS1", ",", "Strings", ">", "CELLOS2", ",", "Strings", ">", "CELLOS3", ",", "Strings", ">", "CELLOS4", ",", "Strings", ">", "CELLOS5", ",", "Strings", ">", "CELLOS6", ",", "Strings", ">", "CELLOS7", ",", "Strings", ">", "CELLOS8", ",", "Strings", ">", "CELLOS9", ",", "Strings", ">", "CELLOS10", ",", "Strings", ">", "CELLOS11", ",", "Strings", ">", "CELLOS12", ",", "Strings", ">", "CELLOS13", ",", "Strings", ">", "CELLOS14", ",", "Strings", ">", "CELLOS15", ",", "Strings", ">", "CELLOS16", ",", "Strings", ">", "CELLOS17", ",", "Strings", ">", "CELLOS18", ",", "Strings", ">", "CELLOS19", ",", "Strings", ">", "CELLOS20", ",", "Strings", ">", "CELLOS21", ",", "Strings", ">", "CELLOS22", ",", "Strings", ">", "CELLOS2", ",", "Strings", ">", "CELLOS24", ",", "Strings", ">", "CELLOS25", ",", "Strings", ">", "CELLOS26", ",", "Strings", ">", "CELLOS3", ",", "Strings", ">", "CELLOS5", ",", "Strings", ">", "CELLOS6", ",", "Strings", ">", "Cello", ",", "Strings", ">", "CELLOS8", ",", "Strings", ">", "CELLOS10", ",", "Strings", ">", "VIOLIN", ",", "Strings", ">", "VIOLON3", ",", "Strings", ">", "ACCVIOLIN", ",", "Strings", ">", "SOLOVIOLIN", ",", "Strings", ">", "PONTICELLO", ",", "Strings", ">", "VIOLETTE", ",", "Strings", ">", "VIOLYMOOG", ",", "Strings", ">", "ANGLEVIOLE", ",", "Strings", ">", "CELLO3", ",", "Strings", ">", "AVIOLIN", ",", "Strings", ">", "CELLOX", ",", "Strings", ">", "BRIGHT", ",", "Strings", ">", "NESCIO", ",", "Strings", ">", "CELLO4", ",", "Strings", ">", "VIOLFIFTH", ",", "Strings", ">", "STRGENS2", ",", "Strings", ">", "VIOLA", ",", "Strings", ">", "STRGSLOW", ",", "Strings", ">", "HIGHSTRGS", ",", "Strings", ">", "STRINGS1", ",", "Strings", ">", "STRINGS2", ",", "Strings", ">", "STRINGS3", ",", "Strings", ">", "STRINGS4", ",", "Strings", ">", "STRINGS5", ",", "Strings", ">", "STRINGS6", ",", "Strings", ">", "STRINGS7", ",", "Strings", ">", "LOWSTRINGS", ",", "Strings", ">", "LOSTRINGS", ",", "Strings", ">", "MIDSTRINGS", ",", "Strings", ">", "ANALOG", ",", "Strings", ">", "WARM", ",", "Strings", ">", "STRANGES", ",", "Strings", ">", "ANTRE", ",", "Strings", ">", "LABO", ",", "Strings", ">", "LIGHT", ",", "Strings", ">", "STENS5", ",", "Strings", ">", "STRINGS2B", ",", "Strings", ">", "VIOLONCELS", ",", "Strings", ">", "VIOLONBAS", ",", "Strings", ">", "PACIFIC3", ",", "Strings", ">", "SYNBS20A", ",", "Strings", ">", "SYNBS20B", ",", "Strings", ">", "TAPISGRIS", ",", "Strings", ">", "STACCATO", ",", "Strings", ">", "SYNBAS18", ",", "Strings", ">", "VIOLON117", ",", "Strings", ">", "ANLGO", ",", "Strings", ">", "POLYPRINT", ",", "Strings", ">", "BALTIC1", ",", "Strings", ">", "CELLOSC", ",", "Strings", ">", "ECELLO", ",", "Strings", ">", "BASCORDES", ",", "Strings", ">", "MELOMELIA", ",", "Strings", ">", "CELLOSYN", ",", "Strings", ">", "SOLOVIOLE", ",", "Strings", ">", "VIOLONSFM", ",", "Strings", ">", "SUPERSTRG", ",", "Strings", ">", "SYNVIOLON", ",", "Strings", ">", "ADDITIF", ",", "Strings", ">", "ANLGSYNC", ",", "Strings", ">", "ANGLSYN", ",", "Strings", ">", "ANLGSTRNG", ",", "Strings", ">", "FULLSTRING", ",", "Strings", ">", "STRINGSM1", ",", "Synth", "Analog", ">", "ANALOG1", ",", "Synth", "Analog", ">", "ANALOG2", ",", "Synth", "Analog", ">", "ANALOG3", ",", "Synth", "Analog", ">", "ANALOG4", ",", "Synth", "Analog", ">", "ANALOG5", ",", "Synth", "Analog", ">", "ANALOG6", ",", "Synth", "Analog", ">", "ANALOG7", ",", "Synth", "Analog", ">", "ANALOG8", ",", "Synth", "Analog", ">", "ANALOG9", ",", "Synth", "Analog", ">", "ANALOG10", ",", "Synth", "Analog", ">", "ANALOG11", ",", "Synth", "Analog", ">", "ANALOG12", ",", "Synth", "Analog", ">", "ANALOG13", ",", "Synth", "Analog", ">", "ANALOGBRT", ",", "Synth", "Analog", ">", "ANALOGBRT", ",", "Synth", "Analog", ">", "ANALOGBRT", ",", "Synth", "Analog", ">", "ANALOGPAD", ",", "Synth", "Analog", ">", "ANALOGPAD", ",", "Synth", "Analog", ">", "ANALOGPAD", ",", "Synth", "Analog", ">", "ANALOGSNC", ",", "Synth", "Analog", ">", "ANALOGSNC", ",", "Synth", "Analog", ">", "ANALOG4DL", ",", "Synth", "Analog", ">", "ANALOG5", ",", "Synth", "Analog", ">", "ANALOG", ",", "Synth", "Analog", ">", "ANALQGOB", ",", "Synth", "Analog", ">", "ANLGSTG3", ",", "Synth", "Analog", ">", "ANLGSYNC1", ",", "Synth", "Analog", ">", "ANLGSYNC3", ",", "Synth", "Analog", ">", "ANLGSYNC3", ",", "Synth", "Analog", ">", "ANLGBRTSYN", ",", "Synth", "Analog", ">", "ANLNG324", ",", "Synth", "Analog", ">", "ANLNG324", ",", "Synth", "Analog", ">", "ANLOGSQR1", ",", "Synth", "Analog", ">", "ANLOGSQR2", ",", "Synth", "Analog", ">", "Anna10", ",", "Synth", "Analog", ">", "Anna21", ",", "Synth", "Analog", ">", "Anna4", ",", "Synth", "Analog", ">", "Anna5", ",", "Synth", "Analog", ">", "AnnaGit2", ",", "Synth", "Analog", ">", "AnnaHit", ",", "Synth", "Analog", ">", "AnnaLog9", ",", "Synth", "Analog", ">", "AnnaLog31", ",", "Synth", "Analog", ">", "AnnaLogge", ",", "Synth", "Analog", ">", "AnnaLogue", ",", "Synth", "Analog", ">", "AnnaSolo1", ",", "Synth", "Analog", ">", "AnnaFatest", ",", "Synth", "Analog", ">", "AnnaFatst", ",", "Synth", "Analog", ">", "ANNALOGGER", ",", "Synth", "Analog", ">", "AnnaSubtl", ",", "Synth", "Analog", ">", "ANALOSYN3", ",", "Synth", "Analog", ">", "ANALOSYN1", ",", "Synth", "Analog", ">", "ANLGBRSS4", ",", "Synth", "Analog", ">", "ANALOG", ",", "Synth", "Analog", ">", "ANNANASTY1", ",", "Synth", "Analog", ">", "ANLGSYN1", ",", "Synth", "Analog", ">", "ANALOG1", ",", "Synth", "Analog", ">", "ANLGSYN3", ",", "Synth", "Analog", ">", "ANLGSTG1", ",", "Synth", "Analog", ">", "ANLGSTG3", ",", "Synth", "Analog", ">", "ANLGSTG4", ",", "Synth", "Analog", ">", "ANLGSTG6", ",", "Synth", "Analog", ">", "ANLGSYN2", ",", "Synth", "Analog", ">", "ANALGSTR2", ",", "Synth", "Analog", ">", "ANALOG1", ",", "Synth", "Analog", ">", "ANALGSYN1", ",", "Synth", "Analog", ">", "ANALGSYN2", ",", "Synth", "Analog", ">", "ANALGSYN3", ",", "Synth", "Analog", ">", "ANALGSYN4", ",", "Synth", "Analog", ">", "ANALGSYN5", ",", "Synth", "Analog", ">", "ANALGSYN6", ",", "Synth", "Analog", ">", "ANALGSYN7", ",", "Synth", "Analog", ">", "ANALGSYN8", ",", "Synth", "Analog", ">", "ANALGSYN9", ",", "Synth", "Analog", ">", "ANALGSYN10", ",", "Synth", "Analog", ">", "ANALGSYN11", ",", "Synth", "Analog", ">", "ANALGSYN12", ",", "Synth", "Analog", ">", "ANALGSYN13", ",", "Synth", "Analog", ">", "ANALGSYN14", ",", "Synth", "Analog", ">", "ANALGSYN15", ",", "Synth", "Analog", ">", "ANALGSYN17", ",", "Synth", "Analog", ">", "ANALGSYN18", ",", "Synth", "Analog", ">", "ANALGSYN19", ",", "Synth", "Analog", ">", "ANALOGSTR1", ",", "Synth", "Analog", ">", "ANALOGSTR2", ",", "Synth", "Analog", ">", "ANALOGSTR3", ",", "Synth", "Analog", ">", "AnalogX", ",", "Synth", "Analog", ">", "ANLOGLEAD1", ",", "Synth", "Analog", ">", "ANALGSYN16", ",", "Synth", "Analog", ">", "ANALOGBRS", ",", "Synth", "Analog", ">", "ANALOGBRS", ",", "Synth", "Analog", ">", "AnaBrass1", ",", "Synth", "Analog", ">", "AnaBrass2", ",", "Synth", "Analog", ">", "ANLGBRASS", ",", "Synth", "Analog", ">", "ANLGBRASS", ",", "Synth", "Analog", ">", "ANLGBRSS2", ",", "Synth", "Analog", ">", "ANLGBRSS3", ",", "Synth", "Lead", ">", "Lead1", ",", "Synth", "Lead", ">", "Lead2", ",", "Synth", "Lead", ">", "ANLOGLEAD1", ",", "Synth", "Lead", ">", "DIGILEAD1", ",", "Synth", "Lead", ">", "DIGILEAD1", ",", "Synth", "Lead", ">", "DIGILEAD2", ",", "Synth", "Lead", ">", "DIGILEAD7", ",", "Synth", "Lead", ">", "DX1LEADA", ",", "Synth", "Lead", ">", "DX1LEADB", ",", "Synth", "Lead", ">", "DX1LEADD", ",", "Synth", "Lead", ">", "FATLEAD", ",", "Synth", "Lead", ">", "FATLEAD", ",", "Synth", "Lead", ">", "LEAD1", ",", "Synth", "Lead", ">", "LEAD1", ",", "Synth", "Lead", ">", "LEAD2", ",", "Synth", "Lead", ">", "LEAD", ",", "Synth", "Lead", ">", "Lead1", ",", "Synth", "Lead", ">", "LEAD5", ",", "Synth", "Lead", ">", "LEADMOOG2", ",", "Synth", "Lead", ">", "LEADSYN2", ",", "Synth", "Lead", ">", "LEADSYNTH", ",", "Synth", "Lead", ">", "LEAD1JH", ",", "Synth", "Lead", ">", "LEADPROPH5", ",", "Synth", "Lead", ">", "LEADSYN1", ",", "Synth", "Lead", ">", "LEADSYN2", ",", "Synth", "Lead", ">", "LEADSYN2", ",", "Synth", "Lead", ">", "LEADSYN3", ",", "Synth", "Lead", ">", "LEADSYN4", ",", "Synth", "Lead", ">", "LEADSYN4", ",", "Synth", "Lead", ">", "LEADSYN5", ",", "Synth", "Lead", ">", "LEADSYN5", ",", "Synth", "Lead", ">", "LEADSYN6", ",", "Synth", "Lead", ">", "LEADSYN7", ",", "Synth", "Lead", ">", "LEADSYNTH1", ",", "Synth", "Lead", ">", "LEADSYNTH2", ",", "Synth", "Lead", ">", "METALLEAD", ",", "Synth", "Lead", ">", "MiniLead1", ",", "Synth", "Lead", ">", "SYNLEAD1", ",", "Synth", "Lead", ">", "SYNLEAD2", ",", "Synth", "Lead", ">", "SYNLEAD3", ",", "Synth", "Lead", ">", "SYNLEAD4", ",", "Synth", "Lead", ">", "SYNLEAD5", ",", "Synth", "Lead", ">", "SYNLEAD8", ",", "Synth", "Lead", ">", "SYNLEAD1", ",", "Synth", "Lead", ">", "SYNLEAD1", ",", "Synth", "Lead", ">", "SYNLEAD1", ",", "Synth", "Lead", ">", "SYNLEAD1", ",", "Synth", "Lead", ">", "SYNLEAD1", ",", "Synth", "Lead", ">", "SYNLEAD1", ",", "Synth", "Lead", ">", "SYNLEAD2", ",", "Synth", "Lead", ">", "SYNLEAD2", ",", "Synth", "Lead", ">", "SYNLEAD3", ",", "Synth", "Lead", ">", "SYNLEAD4", ",", "Synth", "Lead", ">", "SYNLEAD4", ",", "Synth", "Lead", ">", "SYNLEAD5", ",", "Synth", "Lead", ">", "SYNLEAD6", ",", "Synth", "Lead", ">", "SYNLEAD8", ",", "Synth", "Lead", ">", "SYNLEAD10", ",", "Synth", "Lead", ">", "SYNLEAD11", ",", "Synth", "Lead", ">", "SYNLEAD13", ",", "Synth", "Lead", ">", "SYNLEAD14", ",", "Synth", "Lead", ">", "SYNLEAD15", ",", "Synth", "Lead", ">", "SYNLEAD18", ",", "Synth", "Lead", ">", "SYNLEAD19", ",", "Synth", "Lead", ">", "SYNLEAD20", ",", "Synth", "Lead", ">", "SYNLEAD21", ",", "Synth", "Lead", ">", "SYNLEAD22", ",", "Synth", "Lead", ">", "SYNLEAD23", ",", "Synth", "Lead", ">", "SYNLEAD25", ",", "Synth", "Lead", ">", "SYNLEAD26", ",", "Synth", "Lead", ">", "SYNLEAD27", ",", "Synth", "Lead", ">", "SYNLEAD28", ",", "Synth", "Lead", ">", "SYNLEAD29", ",", "Synth", "Lead", ">", "SYNLEAD30", ",", "Synth", "Lead", ">", "SYNLEAD31", ",", "Synth", "Lead", ">", "SYNLEAD32", ",", "Synth", "Lead", ">", "SYNLEAD33", ",", "Synth", "Pads", ">", "ARMPAD1", ",", "Synth", "Pads", ">", "Whizpad", ",", "Synth", "Pads", ">", "NotreDam", ",", "Synth", "Pads", ">", "Prophet1", ",", "Synth", "Pads", ">", "Sternenkl", ",", "Synth", "Pads", ">", "AMBIENCE", ",", "Synth", "Pads", ">", "ANALOGPAD", ",", "Synth", "Pads", ">", "ANALOGPAD", ",", "Synth", "Pads", ">", "ANALOGPAD", ",", "Synth", "Pads", ">", "ANALOGPAD", ",", "Synth", "Pads", ">", "ANALOGPAD", ",", "Synth", "Pads", ">", "AnnaSubtl", ",", "Synth", "Pads", ">", "ARMPAD1", ",", "Synth", "Pads", ">", "AuraHM", ",", "Synth", "Pads", ">", "BassPad", ",", "Synth", "Pads", ">", "BoPadAnna", ",", "Synth", "Pads", ">", "BoPadAnna", ",", "Synth", "Pads", ">", "BRITEPAD", ",", "Synth", "Pads", ">", "BRONZE", ",", "Synth", "Pads", ">", "BUTTERFLY", ",", "Synth", "Pads", ">", "CARLOS1", ",", "Synth", "Pads", ">", "CARLOS2", ",", "Synth", "Pads", ">", "CARLOS3", ",", "Synth", "Pads", ">", "CARLOS4", ",", "Synth", "Pads", ">", "CARLOS6", ",", "Synth", "Pads", ">", "CARLOS7", ",", "Synth", "Pads", ">", "CARLOS1A", ",", "Synth", "Pads", ">", "CARLOS2", ",", "Synth", "Pads", ">", "Carlos1", ",", "Synth", "Pads", ">", "Carlos2", ",", "Synth", "Pads", ">", "Carlos4", ",", "Synth", "Pads", ">", "CARLOSNEW", ",", "Synth", "Pads", ">", "CHORUSPAD", ",", "Synth", "Pads", ">", "CHROMA26", ",", "Synth", "Pads", ">", "CHROMA26", ",", "Synth", "Pads", ">", "CHUNGKUO", ",", "Synth", "Pads", ">", "CIRRUS", ",", "Synth", "Pads", ">", "CIRRUS", ",", "Synth", "Pads", ">", "CLOUDS", ",", "Synth", "Pads", ">", "ConPadII", ",", "Synth", "Pads", ">", "ConPadII", ",", "Synth", "Pads", ">", "CRIMEPADS", ",", "Synth", "Pads", ">", "DARKPAD", ",", "Synth", "Pads", ">", "DHARMA", ",", "Synth", "Pads", ">", "DigiPad", ",", "Synth", "Pads", ">", "DigiPad", ",", "Synth", "Pads", ">", "DigiPad", ",", "Synth", "Pads", ">", "DigiPad1", ",", "Synth", "Pads", ">", "DIGILOG2", ",", "Synth", "Pads", ">", "DIGILOG2", ",", "Synth", "Pads", ">", "DnaPad4", ",", "Synth", "Pads", ">", "DnaPad1", ",", "Synth", "Pads", ">", "DnaPad2", ",", "Synth", "Pads", ">", "DnaPad2", ",", "Synth", "Pads", ">", "DX94", ",", "Synth", "Pads", ">", "ECHOSTRA", ",", "Synth", "Pads", ">", "FADEIN", ",", "Synth", "Pads", ">", "FATPAD3", ",", "Synth", "Pads", ">", "FATPAD4", ",", "Synth", "Pads", ">", "Flubos3", ",", "Synth", "Pads", ">", "Flubos3", ",", "Synth", "Pads", ">", "Flubos3", ",", "Synth", "Pads", ">", "GKCVCS2", ",", "Synth", "Pads", ">", "GLEECLUB", ",", "Synth", "Pads", ">", "GLIDEPAD", ",", "Synth", "Pads", ">", "HONGKONG", ",", "Synth", "Pads", ">", "HUMAN2", ",", "Synth", "Pads", ">", "ICEPAD1", ",", "Synth", "Pads", ">", "ICEPAD2", ",", "Synth", "Pads", ">", "JudgemtHM", ",", "Synth", "Pads", ">", "JUMPPAD", ",", "Synth", "Pads", ">", "JX33P", ",", "Synth", "Pads", ">", "Krg6118", ",", "Synth", "Pads", ">", "KYBDPAD1", ",", "Synth", "Pads", ">", "KYBDPAD2", ",", "Synth", "Pads", ">", "M1PADS", ",", "Synth", "Pads", ">", "MELLOWPAD", ",", "Synth", "Pads", ">", "MODERNPAD", ",", "Synth", "Pads", ">", "MONSTERPAD", ",", "Synth", "Pads", ">", "MONSTERPAD", ",", "Synth", "Pads", ">", "MOVIEPAD", ",", "Synth", "Pads", ">", "MysteriPa", ",", "Synth", "Pads", ">", "MysteriPa", ",", "Synth", "Pads", ">", "MysteriPb", ",", "Synth", "Pads", ">", "NARLYPAD", ",", "Synth", "Pads", ">", "NEPTUNE", ",", "Synth", "Pads", ">", "NICEPAD", ",", "Synth", "Pads", ">", "NOKOGIRI1", ",", "Synth", "Pads", ">", "OBA3Pad", ",", "Synth", "Pads", ">", "OBPAD2", ",", "Synth", "Pads", ">", "OB8PAD", ",", "Synth", "Pads", ">", "PAD", ",", "Synth", "Pads", ">", "PAD", ",", "Synth", "Pads", ">", "PAD", ",", "Synth", "Pads", ">", "PAD", ",", "Synth", "Pads", ">", "PAD", ",", "Synth", "Pads", ">", "PAD", ",", "Synth", "Pads", ">", "PAD", ",", "Synth", "Pads", ">", "PAD1", ",", "Synth", "Pads", ">", "PADSRUS", ",", "Synth", "Pads", ">", "PERFECTPAD", ",", "Synth", "Pads", ">", "PitchaPad", ",", "Synth", "Pads", ">", "RUSH", ",", "Synth", "Pads", ">", "SawsPad1", ",", "Synth", "Pads", ">", "SawsPad1", ",", "Synth", "Pads", ">", "SawsPad2", ",", "Synth", "Pads", ">", "SCIDX", ",", "Synth", "Pads", ">", "Slow3DPad", ",", "Synth", "Pads", ">", "SOFTTOUCH", ",", "Synth", "Pads", ">", "SOFTTOUCH", ",", "Synth", "Pads", ">", "SPACEPAD", ",", "Synth", "Pads", ">", "StringPad", ",", "Synth", "Pads", ">", "STRPADJL", ",", "Synth", "Pads", ">", "STRPADB", ",", "Synth", "Pads", ">", "STRPADBO1", ",", "Synth", "Pads", ">", "STRPADBO2", ",", "Synth", "Pads", ">", "STRPADC", ",", "Synth", "Pads", ">", "STRPADREV", ",", "Synth", "Pads", ">", "StrPd2", ",", "Synth", "Pads", ">", "StrPd3", ",", "Synth", "Pads", ">", "SUPERJX", ",", "Synth", "Pads", ">", "sweeell", ",", "Synth", "Pads", ">", "SYNTHPAD", ",", "Synth", "Pads", ">", "TADreamy", ",", "Synth", "Pads", ">", "TBar2Pad", ",", "Synth", "Pads", ">", "TODDWASH", ",", "Synth", "Pads", ">", "UNIVERSO", ",", "Synth", "Pads", ">", "VocPad1", ",", "Synth", "Pads", ">", "WARMPAD1", ",", "Synth", "Pads", ">", "WARMPAD2", ",", "Synth", "Pads", ">", "WARMPAD3", ",", "Synth", "Pads", ">", "WARMPAD4", ",", "Synth", "Pads", ">", "WARMPAD5", ",", "Synth", "Pads", ">", "WARMPAD6", ",", "Synth", "Pads", ">", "WRMPDFADE", ",", "Synth", "Pads", ">", "WRMPDFADE", ",", "Synth", "Pads", ">", "ArpCPad", ",", "Synth", "Percussion", ">", "ClapTrap", ",", "Synth", "Percussion", ">", "Clash", ",", "Synth", "Percussion", ">", "Syndrums1", ",", "Synth", "Percussion", ">", "Syndrums2", ",", "Synth", "Percussion", ">", "Syndrums3", ",", "Synth", "Percussion", ">", "EDRUM1", ",", "Synth", "Percussion", ">", "EDRUM2", ",", "Synth", "Percussion", ">", "EDRUMS1", ",", "Synth", "Percussion", ">", "EDRUMS2", ",", "Synth", "Percussion", ">", "EDRUMS2", ",", "Synth", "Percussion", ">", "EDRUMS3", ",", "Synth", "Percussion", ">", "EDRUMS", ",", "Synth", "Percussion", ">", "ELDRUM", ",", "Synth", "Percussion", ">", "ELECDRUMS", ",", "Synth", "Percussion", ">", "HITMETAL", ",", "Synth", "Percussion", ">", "HLDSTPED", ",", "Synth", "Percussion", ">", "PRCSYNDRM", ",", "Synth", "Percussion", ">", "SIMDRM1", ",", "Synth", "Percussion", ">", "SIMDRM3", ",", "Synth", "Percussion", ">", "SIMDRM4", ",", "Synth", "Percussion", ">", "SIMDRM5", ",", "Synth", "Percussion", ">", "SIMDRM6", ",", "Synth", "Percussion", ">", "simtom2", ",", "Synth", "Percussion", ">", "simtom7", ",", "Synth", "Percussion", ">", "simtom8", ",", "Synth", "Percussion", ">", "SIMM0NS", ",", "Synth", "Percussion", ">", "Simmens", ",", "Synth", "Percussion", ">", "Simmons", ",", "Synth", "Percussion", ">", "SIMMONS", ",", "Synth", "Percussion", ">", "SIMMONS", ",", "Synth", "Percussion", ">", "SIMMONS2", ",", "Synth", "Percussion", ">", "Simmons9", ",", "Synth", "Percussion", ">", "SIMMONS1", ",", "Synth", "Percussion", ">", "SIMMONS4MF", ",", "Synth", "Percussion", ">", "SIMMONSDS8", ",", "Synth", "Percussion", ">", "simsnr1", ",", "Synth", "Percussion", ">", "simsnr2", ",", "Synth", "Percussion", ">", "SKINMETAL", ",", "Synth", "Percussion", ">", "SYMMONDRES", ",", "Synth", "Percussion", ">", "SYNTOMS3", ",", "Synth", "Percussion", ">", "SynGong", ",", "Synth", "Percussion", ">", "KP", ",", "Synth", "Percussion", ">", "KP", ",", "Synth", "Resonant", ">", "Cristals", ",", "Synth", "Resonant", ">", "Dschungel", ",", "Synth", "Resonant", ">", "Kershaw", ",", "Synth", "Resonant", ">", "Octavian", ",", "Synth", "Resonant", ">", "Stratotro", ",", "Synth", "Resonant", ">", "AlmostHmn", ",", "Synth", "Resonant", ">", "bamboosng", ",", "Synth", "Resonant", ">", "BEAUTY", ",", "Synth", "Resonant", ">", "BRENDA", ",", "Synth", "Resonant", ">", "CASCADE21", ",", "Synth", "Resonant", ">", "CELEBIT", ",", "Synth", "Resonant", ">", "CELESTIAL", ",", "Synth", "Resonant", ">", "COOLPATCH", ",", "Synth", "Resonant", ">", "COOOL", ",", "Synth", "Resonant", ">", "CURVEDAIR", ",", "Synth", "Resonant", ">", "DX18", ",", "Synth", "Resonant", ">", "DXAdditv", ",", "Synth", "Resonant", ">", "DXFantasy", ",", "Synth", "Resonant", ">", "DXFantasy2", ",", "Synth", "Resonant", ">", "ERIHIPPG", ",", "Synth", "Resonant", ">", "Ethereal2", ",", "Synth", "Resonant", ">", "Ethereal2b", ",", "Synth", "Resonant", ">", "Ethereal2b", ",", "Synth", "Resonant", ">", "Fairlight2", ",", "Synth", "Resonant", ">", "fairytale", ",", "Synth", "Resonant", ">", "FLCLOUDA", ",", "Synth", "Resonant", ">", "FLCLOUDB", ",", "Synth", "Resonant", ">", "FLCLOUDB", ",", "Synth", "Resonant", ">", "FLACOSHRT", ",", "Synth", "Resonant", ">", "FLAUTY", ",", "Synth", "Resonant", ">", "FLCLD261", ",", "Synth", "Resonant", ">", "FLCLD262", ",", "Synth", "Resonant", ">", "FRIPP", ",", "Synth", "Resonant", ">", "GackFrShr", ",", "Synth", "Resonant", ">", "GLASS", ",", "Synth", "Resonant", ">", "GLASSSSJH", ",", "Synth", "Resonant", ">", "GLASSVOIC1", ",", "Synth", "Resonant", ">", "GLASSVOIC2", ",", "Synth", "Resonant", ">", "GLASSY1a", ",", "Synth", "Resonant", ">", "GLASSY1b", ",", "Synth", "Resonant", ">", "GLISTEN", ",", "Synth", "Resonant", ">", "GurooHM", ",", "Synth", "Resonant", ">", "HILLCREST", ",", "Synth", "Resonant", ">", "HOLOGRAM", ",", "Synth", "Resonant", ">", "HOLOGRAM", ",", "Synth", "Resonant", ">", "HORNOLKY", ",", "Synth", "Resonant", ">", "HYMNESKB", ",", "Synth", "Resonant", ">", "ISOLATION", ",", "Synth", "Resonant", ">", "ITSALIVE", ",", "Synth", "Resonant", ">", "JESSIESGL", ",", "Synth", "Resonant", ">", "JESSIESGL", ",", "Synth", "Resonant", ">", "MAY11", ",", "Synth", "Resonant", ">", "MEDUSA", ",", "Synth", "Resonant", ">", "OBGenviv", ",", "Synth", "Resonant", ">", "OBGENVIV1", ",", "Synth", "Resonant", ">", "ORCHSPACE", ",", "Synth", "Resonant", ">", "OXONAL", ",", "Synth", "Resonant", ">", "RAULVOIZ", ",", "Synth", "Resonant", ">", "RINGMOD", ",", "Synth", "Resonant", ">", "RptrRISE3", ",", "Synth", "Resonant", ">", "SAHARA", ",", "Synth", "Resonant", ">", "SLIDEGLASS", ",", "Synth", "Resonant", ">", "SloGlass", ",", "Synth", "Resonant", ">", "SOFTSPACE4", ",", "Synth", "Resonant", ">", "SPACEANGEL", ",", "Synth", "Resonant", ">", "SPACEMUSIC", ",", "Synth", "Resonant", ">", "SPACYSYNT", ",", "Synth", "Resonant", ">", "SPHAERE2", ",", "Synth", "Resonant", ">", "SphereHM", ",", "Synth", "Resonant", ">", "SPHERIC2", ",", "Synth", "Resonant", ">", "SPHERIC3", ",", "Synth", "Resonant", ">", "STERLING2", ",", "Synth", "Resonant", ">", "SWELLTONE", ",", "Synth", "Resonant", ">", "SWELL1", ",", "Synth", "Resonant", ">", "SWELL2", ",", "Synth", "Resonant", ">", "SWIRLHAT", ",", "Synth", "Resonant", ">", "SWIRLHAT", ",", "Synth", "Resonant", ">", "SYNRISEB", ",", "Synth", "Resonant", ">", "SYNRISEB", ",", "Synth", "Resonant", ">", "Textures6", ",", "Synth", "Resonant", ">", "Textures6", ",", "Synth", "Resonant", ">", "VANGELIS2", ",", "Synth", "Resonant", ">", 2001, ",", "Synth", "Resonant", ">", "Arrial", ",", "Synth", "Resonant", ">", "Backline2", ",", "Synth", "Resonant", ">", "SOLOIST", ",", "Synth", "Resonant", ">", "Atmosphere", ",", "Synth", "Resonant", ">", "CHANGES2X", ",", "Synth", "Resonant", ">", "ETHEREAL", ",", "Synth", "Resonant", ">", "Etheriala", ",", "Synth", "Resonant", ">", "Etherialb", ",", "Synth", "Resonant", ">", "Etherial5a", ",", "Synth", "Resonant", ">", "Etherial5b", ",", "Synth", "Resonant", ">", "Evolve1a", ",", "Synth", "Resonant", ">", "Evolve1b", ",", "Synth", "Resonant", ">", "GLASS", ",", "Synth", "Resonant", ">", "LOINSOMBR", ",", "Synth", "Resonant", ">", "Medusa", ",", "Synth", "Resonant", ">", "Movie1", ",", "Synth", "Resonant", ">", "MUTESINES", ",", "Synth", "Resonant", ">", "MysteryA", ",", "Synth", "Resonant", ">", "MysteryB", ",", "Synth", "Resonant", ">", "MYSTERY555", ",", "Synth", "Resonant", ">", "SPACES2", ",", "Synth", "Resonant", ">", "VeeCeeYe19", ",", "Synth", "Specific", ">", "MINIMOOG", ",", "Synth", "Specific", ">", "MINIMOOG1", ",", "Synth", "Specific", ">", "MINIMOOG2", ",", "Synth", "Specific", ">", "MINIMOOG", ",", "Synth", "Specific", ">", "ADMOOG", ",", "Synth", "Specific", ">", "MOOG2", ",", "Synth", "Specific", ">", "MOOG13A", ",", "Synth", "Specific", ">", "MOOG13B", ",", "Synth", "Specific", ">", "MOOG13C", ",", "Synth", "Specific", ">", "MOOG13DN", ",", "Synth", "Specific", ">", "MOOG143", ",", "Synth", "Specific", ">", "MOOG211", ",", "Synth", "Specific", ">", "MOOG51", ",", "Synth", "Specific", ">", "MOOG522", ",", "Synth", "Specific", ">", "MOOG523", ",", "Synth", "Specific", ">", "MOOG52MO", ",", "Synth", "Specific", ">", "MOOGBOB", ",", "Synth", "Specific", ">", "Mooger1", ",", "Synth", "Specific", ">", "Mooger2", ",", "Synth", "Specific", ">", "Mooger3", ",", "Synth", "Specific", ">", "Mooger4", ",", "Synth", "Specific", ">", "Mooger5", ",", "Synth", "Specific", ">", "MOOGER1", ",", "Synth", "Specific", ">", "MOOGER2", ",", "Synth", "Specific", ">", "POLYMOOG", ",", "Synth", "Specific", ">", "MOOGER4", ",", "Synth", "Specific", ">", "Mooger5", ",", "Synth", "Specific", ">", "Mooger6", ",", "Synth", "Specific", ">", "MoogerLow", ",", "Synth", "Specific", ">", "MOOOOOOOOG", ",", "Synth", "Specific", ">", "3OSCMOOG1", ",", "Synth", "Specific", ">", "OLDMOOG", ",", "Synth", "Specific", ">", "c", ",", "Synth", "Specific", ">", "cC", ",", "Synth", "Specific", ">", "cC", ",", "Synth", "Specific", ">", "ccc", ",", "Trombone", ">", "NOBONES", ",", "Trombone", ">", "TRBNE221", ",", "Trombone", ">", "TROMBONE", ",", "Trombone", ">", "Trombone", ",", "Trombone", ">", "TROMBONE1", ",", "Trombone", ">", "TROMBONE2", ",", "Trombone", ">", "TROMBONE4", ",", "Trombone", ">", "TROMBONE5", ",", "Trombone", ">", "TROMBONE6", ",", "Trombone", ">", "Trombone7", ",", "Trombone", ">", "TROMBONE8", ",", "Trombone", ">", "TROMBONEBC", ",", "Trombone", ">", "Trombones", ",", "Trombone", ">", "Trombbc2", ",", "Trombone", ">", "Trombbc3", ",", "Trombone", ">", "Trombone6", ",", "Trumpet", ">", "Perpet", ",", "Trumpet", ">", "STRUMPET", ",", "Trumpet", ">", "TOUCHTMPT", ",", "Trumpet", ">", "TPMUTE2", ",", "Trumpet", ">", "TPTMONO", ",", "Trumpet", ">", "TPTMUTE1", ",", "Trumpet", ">", "TPTMUTE2", ",", "Trumpet", ">", "TRBMUTE1", ",", "Trumpet", ">", "TRBMUTE2", ",", "Trumpet", ">", "TRMPT51", ",", "Trumpet", ">", "TRMPT51", ",", "Trumpet", ">", "TRMPT52", ",", "Trumpet", ">", "TRMPT53", ",", "Trumpet", ">", "TRMPT54", ",", "Trumpet", ">", "TRMPT55", ",", "Trumpet", ">", "TRMPT56", ",", "Trumpet", ">", "TROMPETBC", ",", "Trumpet", ">", "TROMPETBO", ",", "Trumpet", ">", "TROMPETE", ",", "Trumpet", ">", "TROMPETE1", ",", "Trumpet", ">", "TROMPETE3", ",", "Trumpet", ">", "TROMPETE4", ",", "Trumpet", ">", "TROMPETEA", ",", "Trumpet", ">", "TRUMPTWO", ",", "Trumpet", ">", "TRUMPAEG", ",", "Trumpet", ">", "TRUMPAEG", ",", "Trumpet", ">", "TRUMPET", ",", "Trumpet", ">", "TRUMPET", ",", "Trumpet", ">", "TRUMPET", ",", "Trumpet", ">", "TRUMPET", ",", "Trumpet", ">", "TRUMPET", ",", "Trumpet", ">", "TRUMPET", ",", "Trumpet", ">", "TRUMPET", ",", "Trumpet", ">", "TRUMPET", ",", "Trumpet", ">", "TRUMPET", ",", "Trumpet", ">", "TRUMPET", ",", "Trumpet", ">", "TRUMPET", ",", "Trumpet", ">", "TRUMPET", ",", "Trumpet", ">", "TRUMPET", ",", "Trumpet", ">", "TRUMPET", ",", "Trumpet", ">", "TRUMPET", ",", "Trumpet", ">", "TRUMPET", ",", "Trumpet", ">", "TRUMPET", ",", "Trumpet", ">", "TRUMPET", ",", "Trumpet", ">", "TRUMPET", ",", "Trumpet", ">", "TRUMPET", ",", "Trumpet", ">", "TRUMPET", ",", "Trumpet", ">", "TRUMPET", ",", "Trumpet", ">", "TRUMPET", ",", "Trumpet", ">", "TRUMPET", ",", "Trumpet", ">", "TRUMPET", ",", "Trumpet", ">", "TRUMPET", ",", "Trumpet", ">", "TRUMPET", ",", "Trumpet", ">", "TRUMPET", ",", "Trumpet", ">", "Trump3A", ",", "Trumpet", ">", "Trump4A", ",", "Trumpet", ">", "Trump4B", ",", "Trumpet", ">", "Trump5A", ",", "Trumpet", ">", "Trump5B", ",", "Trumpet", ">", "Trump20", ",", "Trumpet", ">", "Trumpbc11", ",", "Trumpet", ">", "Trumpbc12", ",", "Trumpet", ">", "Trumpbc13", ",", "Trumpet", ">", "Trumpbc14", ",", "Tuba", ">", "Tuba1", ",", "Tuba", ">", "Tuba1", ",", "Tuba", ">", "Tuba2", ",", "Tuba", ">", "Tuba2", ",", "Tuba", ">", "TUBA", ",", "Tuba", ">", "TUBA1", ",", "Tuba", ">", "TUBA1", ",", "Tuba", ">", "TUBA1", ",", "Tuba", ">", "Tuba2", ",", "Tuba", ">", "TUBA", ",", "Tuba", ">", "TUBA", ",", "Tuba", ">", "TUBA", ",", "Tuba", ">", "TUBA", ",", "Tuba", ">", "TUBA", ",", "Tuba", ">", "TUBA", ",", "Tuba", ">", "TUBA", ",", "Tuba", ">", "TUBA", ",", "Tuba", ">", "TUBA10", ",", "Tuba", ">", "TUBAFLUTE", ",", "Tuba", ">", "TUBAFLUTE", ",", "Tuba", ">", "TubBrass", ",", "Tuba", ">", "TubBrass", ",", "Tuba", ">", "YUBAE", ",", "Tuba", ">", "Tuba", ",", "Tuba", ">", "FHNTUBA", ",", "Tuba", ">", "FHNTUBA", ",", "Tuba", ">", "FHNTUBA", ",", "Tuba", ">", "FHNTUBA", ",", "Tuba", ">", "SPICETUBA1", ",", "Tuba", ">", "SPICETUBA1", ",", "Tuba", ">", "BRASECTION", ",", "Tuba", ">", "BIGBAND1", ",", "Vibraphone", ">", "coolVibe", ",", "Vibraphone", ">", "BASSTRVIBE", ",", "Vibraphone", ">", "bassvibe", ",", "Vibraphone", ">", "CoolVibes", ",", "Vibraphone", ">", "Cool2Vibes", ",", "Vibraphone", ">", "GoodVibes", ",", "Vibraphone", ">", "GoodVibes", ",", "Vibraphone", ">", "PERCVIBES", ",", "Vibraphone", ">", "PLUCVIBE1", ",", "Vibraphone", ">", "PLUCVIBE2", ",", "Vibraphone", ">", "VIB1", ",", "Vibraphone", ">", "VIB2", ",", "Vibraphone", ">", "VIBBELLM", ",", "Vibraphone", ">", "VIBE", ",", "Vibraphone", ">", "VIBE1", ",", "Vibraphone", ">", "VIBE2", ",", "Vibraphone", ">", "VIBE2", ",", "Vibraphone", ">", "VIBEIT", ",", "Vibraphone", ">", "VIBEOLUX", ",", "Vibraphone", ">", "VIBES", ",", "Vibraphone", ">", "VIBESA", ",", "Vibraphone", ">", "VIBESB", ",", "Vibraphone", ">", "VIBESB", ",", "Vibraphone", ">", "VIBES1", ",", "Vibraphone", ">", "VIBES1", ",", "Vibraphone", ">", "VIBES5THS", ",", "Vibraphone", ">", "VIBRAPHA", ",", "Vibraphone", ">", "VIBRAPHON2", ",", "Vibraphone", ">", "VibraPhone", ",", "Vibraphone", ">", "VIBE2A", ",", "Vibraphone", ">", "VIBE2B", ",", "Vibraphone", ">", "VIBE3A", ",", "Vibraphone", ">", "VIBE3B", ",", "Vibraphone", ">", "VIBE6", ",", "Vibraphone", ">", "VIBE8", ",", "Vibraphone", ">", "VIBE9", ",", "Vibraphone", ">", "VIBE12", ",", "Vibraphone", ">", "VIBE14", ",", "Voice", ">", "Choir", ",", "Voice", ">", "Choral", ",", "Voice", ">", "Choral", ",", "Voice", ">", "Chorus", ",", "Voice", ">", "IChoir", ",", "Voice", ">", "CH0R3A", ",", "Voice", ">", "CHOIR24", ",", "Voice", ">", "CHOIR24", ",", "Voice", ">", "CHOIR1A", ",", "Voice", ">", "CHOIR1B", ",", "Voice", ">", "ChoirFifth", ",", "Voice", ">", "CHOR", ",", "Voice", ">", "CHOR4A", ",", "Voice", ">", "CHORAL2", ",", "Voice", ">", "CHORALEM", ",", "Voice", ">", "CHORUS1", ",", "Voice", ">", "CHORUS2", ",", "Voice", ">", "CHORUS3", ",", "Voice", ">", "CHORUS4", ",", "Voice", ">", "CHORUS5", ",", "Voice", ">", "CHORUS5", ",", "Voice", ">", "CHORUS5", ",", "Voice", ">", "CHORUS6", ",", "Voice", ">", "CHORUS7", ",", "Voice", ">", "CHORUS7", ",", "Voice", ">", "CHORUS9", ",", "Voice", ">", "CHORWULF", ",", "Voice", ">", "DXCHOIR", ",", "Voice", ">", "FCHOIR", ",", "Voice", ">", "FCHORUS1", ",", "Voice", ">", "FCHORUS2", ",", "Voice", ">", "FCHORUS3", ",", "Voice", ">", "FEMCHOIR", ",", "Voice", ">", "FEMCHOI1", ",", "Voice", ">", "FEMCHOI3", ",", "Voice", ">", "FEMCHOI4", ",", "Voice", ">", "FEMCHOIR", ",", "Voice", ">", "FEMCHOIR", ",", "Voice", ">", "FEMVox", ",", "Voice", ">", "FEMAL2", ",", "Voice", ">", "FEMALEVC", ",", "Voice", ">", "GREGORIAN", ",", "Voice", ">", "Grinder4", ",", "Voice", ">", "Grinder5", ",", "Voice", ">", "Grinder6", ",", "Voice", ">", "MCHOIR1", ",", "Voice", ">", "MCHOIR2", ",", "Voice", ">", "MCHORUS1", ",", "Voice", ">", "MCHORUS2", ",", "Voice", ">", "MCHORUS3", ",", "Voice", ">", "MCHORUS4", ",", "Voice", ">", "MCHORUS5", ",", "Voice", ">", "MelloChor", ",", "Voice", ">", "MIXEDCHOIR", ",", "Voice", ">", "MYCHOIR1", ",", "Voice", ">", "NISHMALE", ",", "Voice", ">", "OK1CHORALE", ",", "Voice", ">", "OK2CHORALE", ",", "Voice", ">", "PIPECHOR", ",", "Voice", ">", "RADIOCHOIR", ",", "Voice", ">", "SCHOIR3", ",", "Voice", ">", "SCHOIR3", ",", "Voice", ">", "AAAHCHOIR", ",", "Voice", ">", "AltVox1", ",", "Voice", ">", "AltVox5", ",", "Voice", ">", "AltVox7", ",", "Voice", ">", "AltVox9", ",", "Voice", ">", "AltVox12", ",", "Voice", ">", "AltVox13", ",", "Voice", ">", "AltVox16", ",", "Voice", ">", "AltVox17", ",", "Voice", ">", "AltVox18", ",", "Voice", ">", "AltVox20", ",", "Voice", ">", "AltVox23", ",", "Voice", ">", "AltVox25", ",", "Voice", ">", "AltVox30", ",", "Voice", ">", "AltVox31", ",", "Voice", ">", "AltVox32", ",", "Voice", ">", "AltVox33", ",", "Voice", ">", "AltVox34", ",", "Voice", ">", "AltVox35", ",", "Voice", ">", "AltVox3B", ",", "Voice", ">", "AltVox1bc", ",", "Voice", ">", "AltVox4bc", ",", "Voice", ">", "AltVox6bc", ",", "Voice", ">", "AltVox11bc", ",", "Voice", ">", "SopVox4", ",", "Voice", ">", "SopVox1A", ",", "Voice", ">", "SopVox1B", ",", "Voice", ">", "SynVox1A", ",", "Voice", ">", "SynVox1B", ",", "Voice", ">", "SynVox2", ",", "Voice", ">", "TenVox2", ",", "Voice", ">", "TenVox3", ",", "Voice", ">", "TenVox5", ",", "Voice", ">", "TenVox8", ",", "Voice", ">", "BELLVOIC1", ",", "Voice", ">", "BELLVOIC2", ",", "Voice", ">", "BELLVOICE", ",", "Voice", ">", "CHORUS2", ",", "Voice", ">", "COPYFLITE", ",", "Voice", ">", "COSCHORUS1", ",", "Voice", ">", "COSCHORUS2", ",", "Voice", ">", "DBVOX1FEM", ",", "Voice", ">", "DDHIA5A", ",", "Voice", ">", "DMVC183", ",", "Voice", ">", "DMVC184", ",", "Voice", ">", "DMBEL274", ",", "Voice", ">", "DMBELREV1", ",", "Voice", ">", "FVOICE1", ",", "Voice", ">", "FVOICE2", ",", "Voice", ">", "FVOICE3", ",", "Voice", ">", "FVOICE7", ",", "Voice", ">", "FVOICE9", ",", "Voice", ">", "FCHORUS1", ",", "Voice", ">", "FCHORUS2", ",", "Voice", ">", "FCHORUS3", ",", "Voice", ">", "FEMCHOI1", ",", "Voice", ">", "FEMCHOI2", ",", "Voice", ">", "FEMCHOI3", ",", "Voice", ">", "FEMCHOI4", ",", "Voice", ">", "FEMAL2", ",", "Voice", ">", "FMENSMBA", ",", "Voice", ">", "HUMNVC10", ",", "Voice", ">", "HUMNVC2", ",", "Voice", ">", "HUMNVC3", ",", "Voice", ">", "HUMNVC7", ",", "Voice", ">", "KOVOICE1", ",", "Voice", ">", "MFVOIZE3", ",", "Voice", ">", "MVOICE9", ",", "Voice", ">", "MISSAJI", ",", "Voice", ">", "NEWVOICE", ",", "Voice", ">", "OBGenviv", ",", "Voice", ">", "OOCUTER", ",", "Voice", ">", "SYNVOX3", ",", "Voice", ">", "SYNVOX4", ",", "Voice", ">", "SYNVOX5", ",", "Voice", ">", "TINGVOIC4", ",", "Voice", ">", "VOICE1", ",", "Voice", ">", "VOICE2", ",", "Voice", ">", "VOICE3", ",", "Voice", ">", "VOICE4", ",", "Voice", ">", "VOICE5", ",", "Voice", ">", "VOICE35", ",", "Voice", ">", "VOICE46", ",", "Voice", ">", "VOICE48", ",", "Voice", ">", "VOICEF1", ",", "Voice", ">", "VOICEF3", ",", "Voice", ">", "VOICE177", ",", "Voice", ">", "VOICE177", ",", "Voice", ">", "VOICE178", ",", "Voice", ">", "VOICE186", ",", "Voice", ">", "VOICEPAD", ",", "Voice", ">", "VOICESOF1", ",", "Voice", ">", "VOICESOF2", ",", "Voice", ">", "VOICESOF3", ",", "Voice", ">", "VOICESOF4", ",", "Voice", ">", "VOICES1", ",", "Voice", ">", "VOICES2", ",", "Voice", ">", "VOICES3", ",", "Voice", ">", "VOICES4", ",", "Voice", ">", "VOICES7", ",", "Voice", ">", "VOICES9", ",", "Voice", ">", "VOICESBC1", ",", "Voice", ">", "VOICESBC2", ",", "Voice", ">", "VOICES", ",", "Voice", ">", "VOZNANDO", ",", "Voice", ">", "WATERVOIC1", ",", "Voice", ">", "YVOICE1", ",", "Voice", ">", "YVOICE4", ",", "Voice", ">", "YVOICE5", ",", "Voice", ">", "YVOICECD1", ",", "Voice", ">", "YVOICECD2", ",", "Voice", ">", "AAAHCHOIR", ",", "Voice", ">", "CHIMEVOIC", ",", "Voice", ">", "CHOIR24", ",", "Voice", ">", "CHORUS1", ",", "Voice", ">", "CHORUS2", ",", "Voice", ">", "CHORUS3", ",", "Voice", ">", "CHORUS4", ",", "Voice", ">", "CHORUS5", ",", "Voice", ">", "DBCHR1FE", ",", "Voice", ">", "DBCHR2FE", ",", "Voice", ">", "DBTENMA", ",", "Voice", ">", "DBTENMA", ",", "Voice", ">", "DBTENMA", ",", "Voice", ">", "DBTENMA", ",", "Voice", ">", "DBTENMA", ",", "Voice", ">", "DBTENMA", ",", "Voice", ">", "DDHIA5A", ",", "Voice", ">", "DDHIA5B", ",", "Voice", ">", "FMVOIZ1", ",", "Voice", ">", "FMVOIZ2", ",", "Voice", ">", "HUMNVC4", ",", "Voice", ">", "HUMNVC5", ",", "Voice", ">", "HUMNVC6", ",", "Voice", ">", "HUMNVC8", ",", "Voice", ">", "HUMNVC9", ",", "Voice", ">", "MCHOIR1", ",", "Voice", ">", "MCHOIR2", ",", "Voice", ">", "MCHOIR3", ",", "Voice", ">", "MCHOIR4", ",", "Voice", ">", "MVOICE1", ",", "Voice", ">", "MVOICE2", ",", "Voice", ">", "MVOICE3", ",", "Voice", ">", "MVOICE4", ",", "Voice", ">", "MVOICE5", ",", "Voice", ">", "MVOICE6", ",", "Voice", ">", "MCHORUS1", ",", "Voice", ">", "MCHORUS2", ",", "Voice", ">", "MCHORUS3", ",", "Voice", ">", "MCHORUS4", ",", "Voice", ">", "MCHORUS5", ",", "Voice", ">", "MALE4038", ",", "Voice", ">", "MALECHOI1", ",", "Voice", ">", "MALECHOI2", ",", "Voice", ">", "MALEVOICE", ",", "Voice", ">", "OOOH1", ",", "Voice", ">", "OOOH2", ",", "Voice", ">", "OOOH3", ",", "Voice", ">", "OOOH4", ",", "Voice", ">", "OOOH4038A", ",", "Voice", ">", "OOOH4038B", ",", "Voice", ">", "RAULVOIZ", ",", "Voice", ">", "SINGER2", ",", "Voice", ">", "VOCVOICE", ",", "Voice", ">", "VOICE3", ",", "Voice", ">", "VOICE4", ",", "Voice", ">", "VOICE5", ",", "Voice", ">", "VOICE6", ",", "Voice", ">", "VOICE16", ",", "Voice", ">", "VOICE17", ",", "Voice", ">", "VOICE18", ",", "Voice", ">", "VOICES8", ",", "Voice", ">", "Voices10", ",", "Voice", ">", "WINDENS", ",", "Voice", ">", "WindEns1E", ",", "Voice", ">", "WINDENS2E", ",", "Voice", ">", "YOVOICE1", ",", "Voice", ">", "YOVOICE2", ",", "Voice", ">", "KP", ",", "Voice", ">", "KP", ",", "Woodwind", ">", "BASSCLA", ",", "Woodwind", ">", "BASSCLARI", ",", "Woodwind", ">", "BASSCLARNT", ",", "Woodwind", ">", "BCCLA245", ",", "Woodwind", ">", "BSCLARINT", ",", "Woodwind", ">", "BsSqu1", ",", "Woodwind", ">", "BsSquare1", ",", "Woodwind", ">", "CLAIRNET", ",", "Woodwind", ">", "CLAR", ",", "Woodwind", ">", "CLARHAUNT", ",", "Woodwind", ">", "CLARHEP", ",", "Woodwind", ">", "CLARINET", ",", "Woodwind", ">", "CLARINET1", ",", "Woodwind", ">", "CLARINET2", ",", "Woodwind", ">", "CLARINET3", ",", "Woodwind", ">", "CLARINET4", ",", "Woodwind", ">", "CLARINET5", ",", "Woodwind", ">", "CLARINET6", ",", "Woodwind", ">", "CLARNFLT", ",", "Woodwind", ">", "RevsClar", ",", "Woodwind", ">", "CLARINET9", ",", "Woodwind", ">", "CLARINETGD", ",", "Woodwind", ">", "CLARINET11", ",", "Woodwind", ">", "CLARINEXUS", ",", "Woodwind", ">", "CLARNOBOE", ",", "Woodwind", ">", "JHSUS1A", ",", "Woodwind", ">", "JHSUS1B", ",", "Woodwind", ">", "JHSUS1C", ",", "Woodwind", ">", "KCLARI1", ",", "Woodwind", ">", "KCLARI2", ",", "Woodwind", ">", "CLARSTRING", ",", "Woodwind", ">", "SmoothSq2", ",", "Woodwind", ">", "FLUTE1", ",", "Woodwind", ">", "FLUTE2", ",", "Woodwind", ">", "FLUTE3", ",", "Woodwind", ">", "FLUTE4", ",", "Woodwind", ">", "FLUTE5", ",", "Woodwind", ">", "FLUTE6", ",", "Woodwind", ">", "FLUTE7", ",", "Woodwind", ">", "FLUTE8", ",", "Woodwind", ">", "FLUTE9", ",", "Woodwind", ">", "FLUTE10", ",", "Woodwind", ">", "FLUTE11", ",", "Woodwind", ">", "FLUTE12", ",", "Woodwind", ">", "FLUTE1", ",", "Woodwind", ">", "FLUTE14", ",", "Woodwind", ">", "FLUTE4", ",", "Woodwind", ">", "NOAFLUTE", ",", "Woodwind", ">", "FLUTE34", ",", "Woodwind", ">", "FLUTE18", ",", "Woodwind", ">", "FLUTE19", ",", "Woodwind", ">", "FLUTE35", ",", "Woodwind", ">", "Flute21", ",", "Woodwind", ">", "Flute22", ",", "Woodwind", ">", "Flute23", ",", "Woodwind", ">", "Flute24", ",", "Woodwind", ">", "FLUTE36", ",", "Woodwind", ">", "FLUTE26", ",", "Woodwind", ">", "FLUTE37", ",", "Woodwind", ">", "FLUTE28", ",", "Woodwind", ">", "FLUTE38", ",", "Woodwind", ">", "FLUTE30", ",", "Woodwind", ">", "FLUTE1", ",", "Woodwind", ">", "FLUTE32", ",", "Woodwind", ">", "BASSOON1", ",", "Woodwind", ">", "BASSOON2", ",", "Woodwind", ">", "BASSOON3", ",", "Woodwind", ">", "BASSOON4", ",", "Woodwind", ">", "BASSOON5", ",", "Woodwind", ">", "BASSOON", ",", "Woodwind", ">", "BASSOON", ",", "Woodwind", ">", "BASSOONBC", ",", "Woodwind", ">", "BASSOON9", ",", "Woodwind", ">", "BASSOONBC", ",", "Woodwind", ">", "BASSOONBC", ",", "Woodwind", ">", "BCBSN244", ",", "Woodwind", ">", "SYNBASSOON", ",", "Woodwind", ">", "OBOE1", ",", "Woodwind", ">", "OBOE2", ",", "Woodwind", ">", "OBOE3", ",", "Woodwind", ">", "OBOE4", ",", "Woodwind", ">", "OBOE5", ",", "Woodwind", ">", "OBOE6", ",", "Woodwind", ">", "OBOE7", ",", "Woodwind", ">", "OBOE8", ",", "Woodwind", ">", "OBOE9", ",", "Woodwind", ">", "DblReed1", ",", "Woodwind", ">", "OBOE11", ",", "Woodwind", ">", "OBOE12", ",", "Woodwind", ">", "OBOE21", ",", "Woodwind", ">", "OBOE14", ",", "Woodwind", ">", "OBOE15", ",", "Woodwind", ">", "OBOE157", ",", "Woodwind", ">", "OBOE17", ",", "Woodwind", ">", "OBOE18", ",", "Woodwind", ">", "OBOE19", ",", "Woodwind", ">", "LA8Fc", ",", "Woodwind", ">", "LARIC72bb", ",", "Woodwind", ">", "ARNTAFcc", ",", "Woodwind", ">", "2458Fc", ",", "Woodwind", ">", "RINTUKX", ",", "Woodwind", ">", "1UKX", ",", "Woodwind", ">", "are123cc", ",", "Woodwind", ">", "NET57c", ",", "Woodwind", ">", "cccc", ",", "Woodwind", ">", "AUNTcccccc", ",", "Woodwind", ">", "HEPIFcc", ",", "Woodwind", ">", "ETc23cc", ",", "Woodwind", ">", "ET1cFcc", ",", "Woodwind", ">", "ET2ccccc", ",", "Woodwind", ">", "ET3IFcc", ",", "Woodwind", ">", "ET4IFcc", ",", "Woodwind", ">", "ET5IFcc", ",", "Woodwind", ">", "ET65ba", ",", "Woodwind", ">", "FLTM8Fc", ",", "Woodwind", ">", "ClarcFcc", ",", "Woodwind", ">", "ET9IFcc", ",", "Woodwind", ">", "ETGDIFcc", ",", "Woodwind", ">", "ET11IFcc", ",", "Woodwind", ">", "EXUS9c", ",", "Woodwind", ">", "OBOEV2cIH", ",", "Woodwind", ">", "1AV2cIH", ",", "Woodwind", ">", "1BV2cIH", ",", "Woodwind", ">", "1CIFcc", ",", "Woodwind", ">", "I1IFcc", ",", "Woodwind", ">", "I27c", ",", "Woodwind", ">", "RINGc", ",", "Woodwind", ">", "Sq2" ],
					"maxclass" : "umenu",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "int", "", "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 351.0, 152.0, 229.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1.0, 85.0, 223.939545, 24.0 ],
					"style" : "",
					"varname" : "dx7preset"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-121",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 703.0, 36.0, 60.0, 22.0 ],
					"style" : "",
					"text" : "loadbang"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-1",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 753.0, 142.0, 112.0, 22.0 ],
					"style" : "",
					"text" : "sprintf init %sroms/"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-4",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 703.0, 73.0, 34.0, 22.0 ],
					"style" : "",
					"text" : "path"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-12",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 703.0, 108.0, 69.0, 22.0 ],
					"save" : [ "#N", "thispatcher", ";", "#Q", "end", ";" ],
					"style" : "",
					"text" : "thispatcher"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.541176, 0.815686, 0.913725, 1.0 ],
					"id" : "obj-13",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 753.0, 185.0, 80.0, 22.0 ],
					"saved_object_attributes" : 					{
						"filename" : "dx7bank.js",
						"parameter_enable" : 0
					}
,
					"style" : "",
					"text" : "js dx7bank.js"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.702269, 0.811747, 0.303388, 1.0 ],
					"id" : "obj-10",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 415.0, 484.0, 71.0, 22.0 ],
					"style" : "",
					"text" : "s #1-dx7KR"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.702269, 0.811747, 0.303388, 1.0 ],
					"id" : "obj-7",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 14.0, 35.0, 69.0, 22.0 ],
					"style" : "",
					"text" : "r #1-dx7KR"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 0 ],
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-98", 0 ],
					"source" : [ "obj-102", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-82", 0 ],
					"source" : [ "obj-11", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 0 ],
					"source" : [ "obj-117", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-12", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"source" : [ "obj-121", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-37", 0 ],
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"order" : 2,
					"source" : [ "obj-15", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 0 ],
					"order" : 1,
					"source" : [ "obj-15", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-50", 0 ],
					"order" : 0,
					"source" : [ "obj-15", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-37", 0 ],
					"source" : [ "obj-17", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-42", 0 ],
					"source" : [ "obj-18", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-5", 0 ],
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-28", 0 ],
					"source" : [ "obj-22", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 0 ],
					"source" : [ "obj-23", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-65", 0 ],
					"source" : [ "obj-25", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"source" : [ "obj-27", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 0 ],
					"source" : [ "obj-28", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-89", 0 ],
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-38", 0 ],
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-30", 0 ],
					"source" : [ "obj-31", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-37", 0 ],
					"source" : [ "obj-32", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 0 ],
					"source" : [ "obj-327", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-82", 0 ],
					"source" : [ "obj-328", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-83", 0 ],
					"source" : [ "obj-329", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 0 ],
					"source" : [ "obj-33", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-34", 0 ],
					"source" : [ "obj-35", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-49", 0 ],
					"source" : [ "obj-37", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 0 ],
					"source" : [ "obj-38", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-44", 0 ],
					"source" : [ "obj-39", 3 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-76", 1 ],
					"source" : [ "obj-39", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-76", 0 ],
					"source" : [ "obj-39", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-99", 0 ],
					"source" : [ "obj-39", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-12", 0 ],
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"source" : [ "obj-40", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-117", 0 ],
					"source" : [ "obj-41", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-17", 0 ],
					"source" : [ "obj-42", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-18", 1 ],
					"source" : [ "obj-43", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-18", 0 ],
					"source" : [ "obj-43", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-43", 1 ],
					"source" : [ "obj-44", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-43", 0 ],
					"source" : [ "obj-44", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 0 ],
					"source" : [ "obj-47", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-39", 0 ],
					"source" : [ "obj-5", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-38", 0 ],
					"source" : [ "obj-50", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-41", 0 ],
					"source" : [ "obj-6", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 0 ],
					"source" : [ "obj-65", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-32", 0 ],
					"source" : [ "obj-7", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 0 ],
					"source" : [ "obj-76", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-78", 0 ],
					"source" : [ "obj-76", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-85", 0 ],
					"source" : [ "obj-76", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"source" : [ "obj-77", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-327", 0 ],
					"source" : [ "obj-82", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"source" : [ "obj-83", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-83", 0 ],
					"source" : [ "obj-85", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-47", 0 ],
					"source" : [ "obj-89", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-40", 0 ],
					"source" : [ "obj-9", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-10", 0 ],
					"source" : [ "obj-98", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-102", 0 ],
					"source" : [ "obj-99", 0 ]
				}

			}
 ],
		"parameters" : 		{
			"obj-32::obj-9::obj-150" : [ "2-egL4", "2-egL4", 0 ],
			"obj-32::obj-9::obj-147" : [ "2-keyVelSens", "2-keyVelSens", 0 ],
			"obj-32::obj-9::obj-165" : [ "2-opRateScale", "2-opRateScale", 0 ],
			"obj-32::obj-9::obj-322" : [ "3-egR1", "3-egR1", 0 ],
			"obj-32::obj-9::obj-295" : [ "3-egR3", "3-egR3", 0 ],
			"obj-32::obj-9::obj-302" : [ "3-opDetune", "3-opDet", 0 ],
			"obj-32::obj-9::obj-91" : [ "0-egL1", "0-egL1", 0 ],
			"obj-32::obj-9::obj-244" : [ "4-egL2", "4-egL2", 0 ],
			"obj-32::obj-9::obj-248" : [ "4-egR4", "4-egR4", 0 ],
			"obj-32::obj-9::obj-255" : [ "4-opRateScale", "4-opRateScale", 0 ],
			"obj-32::obj-9::obj-160" : [ "2-egR3", "2-egR3", 0 ],
			"obj-32::obj-9::obj-69" : [ "0-opMode", "0-opMode", 0 ],
			"obj-32::obj-9::obj-250" : [ "4-egR3", "4-egR3", 0 ],
			"obj-32::obj-9::obj-232" : [ "5-egR1", "5-egR1", 0 ],
			"obj-32::obj-9::obj-103" : [ "1-egL4", "1-egL4", 0 ],
			"obj-32::obj-9::obj-194" : [ "5-level", "5-level", 0 ],
			"obj-32::obj-9::obj-25" : [ "algorithm", "algo", 0 ],
			"obj-32::obj-9::obj-100" : [ "1-keyVelSens", "1-keyVelSens", 0 ],
			"obj-82" : [ "freq", "freq", 0 ],
			"obj-32::obj-9::obj-119" : [ "1-opRateScale", "1-opRateScale", 0 ],
			"obj-32::obj-9::obj-187" : [ "2-egR1", "2-egR1", 0 ],
			"obj-32::obj-9::obj-149" : [ "2-level", "2-level", 0 ],
			"obj-32::obj-9::obj-291" : [ "3-egL1", "3-egL1", 0 ],
			"obj-32::obj-9::obj-304" : [ "3-opFreq", "3-opFreq", 0 ],
			"obj-32::obj-9::obj-242" : [ "4-egL3", "4-egL3", 0 ],
			"obj-32::obj-9::obj-89" : [ "0-egL2", "0-egL2", 0 ],
			"obj-32::obj-9::obj-81" : [ "0-egR3", "0-egR3", 0 ],
			"obj-32::obj-9::obj-79" : [ "0-egR2", "0-egR2", 0 ],
			"obj-32::obj-9::obj-94" : [ "amp[1]", "amp", 0 ],
			"obj-32::obj-9::obj-237" : [ "4-keyVelSens", "4-keyVelSens", 0 ],
			"obj-32::obj-9::obj-201" : [ "5-egL1", "5-egL1", 0 ],
			"obj-32::obj-9::obj-95" : [ "0-level", "0-level", 0 ],
			"obj-32::obj-9::obj-76" : [ "0-opRateScale", "0-opRateScale", 0 ],
			"obj-32::obj-9::obj-212" : [ "5-opDetune", "5-opDet", 0 ],
			"obj-32::obj-9::obj-141" : [ "1-egR1", "1-egR1", 0 ],
			"obj-32::obj-9::obj-257" : [ "4-opDetune", "4-opDet", 0 ],
			"obj-32::obj-9::obj-102" : [ "1-level", "1-level", 0 ],
			"obj-32::obj-9::obj-19" : [ "feedback", "fbk", 0 ],
			"obj-32::obj-9::obj-156" : [ "2-egL1", "2-egL1", 0 ],
			"obj-32::obj-9::obj-167" : [ "2-opDetune", "2-opDet", 0 ],
			"obj-32::obj-9::obj-289" : [ "3-egL2", "3-egL2", 0 ],
			"obj-32::obj-9::obj-297" : [ "3-egR2", "3-egR2", 0 ],
			"obj-32::obj-9::obj-306" : [ "3-opMode", "3-opMode", 0 ],
			"obj-32::obj-9::obj-281" : [ "3-keyVelSens", "3-keyVelSens", 0 ],
			"obj-32::obj-9::obj-87" : [ "0-egL3", "0-egL3", 0 ],
			"obj-32::obj-9::obj-240" : [ "4-egL4", "4-egL4", 0 ],
			"obj-83" : [ "amp", "amp", 0 ],
			"obj-32::obj-9::obj-239" : [ "4-level", "4-level", 0 ],
			"obj-32::obj-9::obj-38" : [ "portamento[1]", "porta", 0 ],
			"obj-32::obj-9::obj-74" : [ "0-opDetune", "0-opDet", 0 ],
			"obj-32::obj-9::obj-199" : [ "5-egL2", "5-egL2", 0 ],
			"obj-32::obj-9::obj-109" : [ "1-egL1", "1-egL1", 0 ],
			"obj-32::obj-9::obj-207" : [ "5-egR2", "5-egR2", 0 ],
			"obj-32::obj-9::obj-214" : [ "5-opFreq", "5-opFreq", 0 ],
			"obj-32::obj-9::obj-121" : [ "1-opDetune", "1-opDet", 0 ],
			"obj-32::obj-9::obj-154" : [ "2-egL2", "2-egL2", 0 ],
			"obj-32::obj-9::obj-162" : [ "2-egR2", "2-egR2", 0 ],
			"obj-32::obj-9::obj-169" : [ "2-opFreq", "2-opFreq", 0 ],
			"obj-32::obj-9::obj-287" : [ "3-egL3", "3-egL3", 0 ],
			"obj-32::obj-9::obj-293" : [ "3-egR4", "3-egR4", 0 ],
			"obj-32::obj-9::obj-300" : [ "3-opRateScale", "3-opRateScale", 0 ],
			"obj-32::obj-9::obj-277" : [ "4-egR1", "4-egR1", 0 ],
			"obj-32::obj-9::obj-85" : [ "0-egL4", "0-egL4", 0 ],
			"obj-32::obj-9::obj-205" : [ "5-egR3", "5-egR3", 0 ],
			"obj-32::obj-9::obj-326" : [ "freq[1]", "freq", 0 ],
			"obj-32::obj-9::obj-83" : [ "0-egR4", "0-egR4", 0 ],
			"obj-32::obj-9::obj-259" : [ "4-opFreq", "4-opFreq", 0 ],
			"obj-32::obj-9::obj-197" : [ "5-egL3", "5-egL3", 0 ],
			"obj-32::obj-9::obj-203" : [ "5-egR4", "5-egR4", 0 ],
			"obj-32::obj-9::obj-107" : [ "1-egL2", "1-egL2", 0 ],
			"obj-32::obj-9::obj-216" : [ "5-opMode", "5-opMode", 0 ],
			"obj-32::obj-9::obj-115" : [ "1-egR2", "1-egR2", 0 ],
			"obj-32::obj-9::obj-123" : [ "1-opFreq", "1-opFreq", 0 ],
			"obj-32::obj-9::obj-152" : [ "2-egL3", "2-egL3", 0 ],
			"obj-32::obj-9::obj-158" : [ "2-egR4", "2-egR4", 0 ],
			"obj-89" : [ "portamento", "porta", 0 ],
			"obj-32::obj-9::obj-171" : [ "2-opMode", "2-opMode", 0 ],
			"obj-32::obj-9::obj-285" : [ "3-egL4", "3-egL4", 0 ],
			"obj-32::obj-9::obj-283" : [ "3-level", "3-level", 0 ],
			"obj-32::obj-9::obj-246" : [ "4-egL1", "4-egL1", 0 ],
			"obj-32::obj-9::obj-28" : [ "0-egR1", "0-egR1", 0 ],
			"obj-32::obj-9::obj-261" : [ "4-opMode", "4-opMode", 0 ],
			"obj-32::obj-9::obj-97" : [ "0-keyVelSens", "0-keyVelSens", 0 ],
			"obj-32::obj-9::obj-195" : [ "5-egL4", "5-egL4", 0 ],
			"obj-32::obj-9::obj-113" : [ "1-egR3", "1-egR3", 0 ],
			"obj-32::obj-9::obj-73" : [ "0-opFreq", "0-opFreq", 0 ],
			"obj-32::obj-9::obj-252" : [ "4-egR2", "4-egR2", 0 ],
			"obj-32::obj-9::obj-105" : [ "1-egL3", "1-egL3", 0 ],
			"obj-32::obj-9::obj-192" : [ "5-keyVelSens", "5-keyVelSens", 0 ],
			"obj-32::obj-9::obj-210" : [ "5-opRateScale", "5-opRateScale", 0 ],
			"obj-32::obj-9::obj-111" : [ "1-egR4", "1-egR4", 0 ],
			"obj-32::obj-9::obj-125" : [ "1-opMode", "1-opMode", 0 ],
			"obj-37" : [ "live.gain~", "Gain", 0 ]
		}
,
		"dependency_cache" : [ 			{
				"name" : "dx7bank.js",
				"bootpath" : "~/ownCloud/macShare/lutherie/synthMono/faustInstruMono/faustDX7mono",
				"patcherrelativepath" : ".",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "dx7mono.maxpat",
				"bootpath" : "~/ownCloud/macShare/lutherie/synthMono/faustInstruMono/faustDX7mono",
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
				"name" : "midiPoly2mono.maxpat",
				"bootpath" : "~/ownCloud/macShare/lutherie/tools/under",
				"patcherrelativepath" : "../../../tools/under",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "faustDX7mono~.mxo",
				"type" : "iLaX"
			}
 ],
		"autosave" : 0,
		"styles" : [ 			{
				"name" : "newobjYellow-1",
				"default" : 				{
					"fontsize" : [ 12.059008 ],
					"accentcolor" : [ 0.82517, 0.78181, 0.059545, 1.0 ]
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
