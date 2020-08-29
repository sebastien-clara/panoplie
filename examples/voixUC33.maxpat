{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 8,
			"minor" : 0,
			"revision" : 1,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"classnamespace" : "box",
		"rect" : [ 102.0, 79.0, 782.0, 629.0 ],
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
					"bgcolor" : [ 0.960784, 0.827451, 0.156863, 0.0 ],
					"bubble" : 1,
					"bubbleside" : 2,
					"id" : "obj-50",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 30.0, 1483.0, 98.0, 52.0 ],
					"text" : "Space bar = +1\nDel = -1",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-51",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 76.25, 1616.5, 22.0, 22.0 ],
					"text" : "-1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-53",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 3,
					"outlettype" : [ "bang", "bang", "" ],
					"patching_rect" : [ 53.75, 1577.0, 64.0, 22.0 ],
					"text" : "sel 32 127"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-54",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 132.25, 1577.0, 70.0, 22.0 ],
					"text" : "loadmess 1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-55",
					"maxclass" : "number",
					"minimum" : 1,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 132.25, 1616.5, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-56",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"patching_rect" : [ 56.25, 1664.5, 29.5, 22.0 ],
					"text" : "+"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-57",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 56.25, 1616.5, 18.0, 22.0 ],
					"text" : "1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-58",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 4,
					"outlettype" : [ "int", "int", "int", "int" ],
					"patching_rect" : [ 53.75, 1538.5, 50.5, 22.0 ],
					"text" : "key"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-52",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 86.5, 1856.0, 62.0, 22.0 ],
					"text" : "route float"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-22",
					"maxclass" : "ezadc~",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "signal" ],
					"patching_rect" : [ 11.0, 3.0, 45.0, 45.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-21",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 883.0, 364.0, 81.0, 22.0 ],
					"text" : "prepend note"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-42",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 309.0, 1785.0, 39.0, 23.0 ],
					"text" : "clear"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-23",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 334.0, 1871.0, 97.0, 23.0 ],
					"text" : "storagewindow"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-39",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 309.0, 1829.0, 84.0, 23.0 ],
					"text" : "clientwindow"
				}

			}
, 			{
				"box" : 				{
					"autorestore" : "voix.json",
					"id" : "obj-40",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 158.5, 1856.0, 100.0, 22.0 ],
					"saved_object_attributes" : 					{
						"client_rect" : [ 51, 45, 405, 173 ],
						"parameter_enable" : 0,
						"parameter_mappable" : 0,
						"storage_rect" : [ 583, 69, 1034, 197 ]
					}
,
					"text" : "pattrstorage",
					"varname" : "u678000288"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-29",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 355.0, 1448.0, 94.0, 20.0 ],
					"text" : "preset name !!"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-24",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 299.0, 1448.0, 61.0, 22.0 ],
					"text" : "voixUC33"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-33",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "bang" ],
					"patching_rect" : [ 163.0, 1410.0, 155.0, 22.0 ],
					"text" : "t b b"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-34",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 163.0, 1375.0, 93.0, 22.0 ],
					"text" : "loadbang"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-35",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 213.0, 1523.0, 105.0, 22.0 ],
					"text" : "sprintf %s%s.json"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-36",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 163.0, 1448.0, 34.0, 22.0 ],
					"text" : "path"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-37",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 163.0, 1482.0, 69.0, 22.0 ],
					"save" : [ "#N", "thispatcher", ";", "#Q", "end", ";" ],
					"text" : "thispatcher"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-10",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "" ],
					"patching_rect" : [ 213.0, 1562.5, 143.0, 22.0 ],
					"text" : "t b l"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-38",
					"linecount" : 4,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 213.0, 1596.5, 143.0, 62.0 ],
					"text" : "MacintoshHD:/Users/cs38620h/ownCloud/macShare/panoplie/examples/voix.json"
				}

			}
, 			{
				"box" : 				{
					"args" : [ "instru20" ],
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-28",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "presetManager.maxpat",
					"numinlets" : 3,
					"numoutlets" : 1,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "" ],
					"patching_rect" : [ 158.5, 1694.0, 128.0, 128.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 890.5, 3.5, 128.0, 128.0 ],
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-9",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 973.0, 190.5, 72.0, 22.0 ],
					"text" : "loadmess 4"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-20",
					"maxclass" : "meter~",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 240.5, 847.0, 17.0, 80.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 763.0, 539.0, 17.0, 80.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-19",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "stkModalBar2.maxpat",
					"numinlets" : 1,
					"numoutlets" : 1,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 447.0, 891.0, 278.0, 218.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 820.5, 384.0, 268.0, 216.0 ],
					"varname" : "stkModalBar2",
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.501961, 0.501961, 0.0, 1.0 ],
					"id" : "obj-16",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 346.200012000000015, 1307.0, 116.0, 22.0 ],
					"text" : "s scaler2-scaleRoot"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.501961, 0.501961, 0.0, 1.0 ],
					"id" : "obj-17",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 316.200012000000015, 1270.0, 124.0, 22.0 ],
					"text" : "s scaler2-selectScale"
				}

			}
, 			{
				"box" : 				{
					"args" : [ "scaler2" ],
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-14",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "midiTune.maxpat",
					"numinlets" : 1,
					"numoutlets" : 1,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "" ],
					"patching_rect" : [ 754.5, 1190.5, 224.0, 181.0 ],
					"varname" : "scaler2",
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"args" : [ "a2perc" ],
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-12",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "audio2midiPerc.maxpat",
					"numinlets" : 2,
					"numoutlets" : 1,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "" ],
					"patching_rect" : [ 754.5, 891.0, 258.0, 252.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 825.0, 135.0, 259.0, 247.0 ],
					"varname" : "audio2midiPerc",
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"args" : [ "a2poly" ],
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-11",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "audio2midiPolyphonic.maxpat",
					"numinlets" : 2,
					"numoutlets" : 1,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "" ],
					"patching_rect" : [ 271.0, 699.0, 225.0, 132.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 542.0, 3.5, 235.0, 129.5 ],
					"varname" : "audio2midiPolyphonic",
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"args" : [ "rev" ],
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-8",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "zitaLight.maxpat",
					"numinlets" : 2,
					"numoutlets" : 2,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "signal", "signal" ],
					"patching_rect" : [ 11.0, 948.0, 103.0, 78.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 437.0, 539.0, 103.0, 78.0 ],
					"varname" : "zitaLight",
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"args" : [ "press" ],
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-7",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "compressor.maxpat",
					"numinlets" : 1,
					"numoutlets" : 1,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 11.0, 847.0, 219.0, 80.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 542.0, 539.0, 219.0, 80.0 ],
					"varname" : "compressor",
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.501961, 0.501961, 0.0, 1.0 ],
					"id" : "obj-61",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 346.200012000000015, 1239.0, 116.0, 22.0 ],
					"text" : "s scaler1-scaleRoot"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.501961, 0.501961, 0.0, 1.0 ],
					"id" : "obj-26",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 316.200012000000015, 1202.0, 124.0, 22.0 ],
					"text" : "s scaler1-selectScale"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-6",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "int", "int" ],
					"patching_rect" : [ 316.200012000000015, 1165.0, 49.0, 22.0 ],
					"text" : "unpack"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-47",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 883.0, 152.5, 65.0, 22.0 ],
					"text" : "route note"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-41",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 273.0, 1121.0, 130.0, 22.0 ],
					"text" : "prepend enablednotes"
				}

			}
, 			{
				"box" : 				{
					"args" : [ 5 ],
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-32",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "scale.maxpat",
					"numinlets" : 3,
					"numoutlets" : 6,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "", "", "", "", "", "" ],
					"patching_rect" : [ 100.200012000000001, 1078.0, 235.0, 27.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 837.0, 599.0, 235.0, 27.0 ],
					"varname" : "scale",
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-31",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 5,
					"outlettype" : [ "signal", "signal", "signal", "signal", "list" ],
					"patching_rect" : [ 11.0, 758.0, 136.0, 22.0 ],
					"saved_object_attributes" : 					{
						"correction_ambience_threshold" : [ 0.300000011920929 ],
						"enablednotes" : [ 0, 1, 5, 6, 10 ],
						"notebase" : 0,
						"notelist" : [ 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100 ],
						"pitchdetection" : 0,
						"quality" : "better",
						"reportlatency" : 0,
						"retune" : 1,
						"use_16bit" : [ 0 ],
						"windowsize" : [ 64 ]
					}
,
					"text" : "retune~ @quality better"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-30",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 628.0, 354.5, 225.0, 22.0 ],
					"text" : "note 56. 111.510978 2304."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-27",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "float", "float", "float" ],
					"patching_rect" : [ 883.0, 190.5, 69.0, 22.0 ],
					"text" : "unpack f f f"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-25",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 628.0, 320.5, 225.0, 22.0 ],
					"text" : "note 56 111.510978 576."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-18",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 883.0, 324.5, 69.0, 22.0 ],
					"text" : "pack f f f"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-15",
					"maxclass" : "number",
					"minimum" : 1,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 973.0, 224.5, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-13",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 932.5, 268.5, 29.5, 22.0 ],
					"text" : "* 1."
				}

			}
, 			{
				"box" : 				{
					"args" : [ 4 ],
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-5",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "dx7main.maxpat",
					"numinlets" : 1,
					"numoutlets" : 1,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 628.0, 628.5, 277.5, 183.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 542.0, 354.0, 277.5, 183.0 ],
					"varname" : "dx7main",
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"args" : [ "scaler1" ],
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-4",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "midiTune.maxpat",
					"numinlets" : 1,
					"numoutlets" : 1,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "" ],
					"patching_rect" : [ 628.0, 409.5, 224.0, 181.0 ],
					"varname" : "scaler1",
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-3",
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 11.0, 1050.0, 45.0, 45.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 804.0, 45.0, 45.0, 45.0 ]
				}

			}
, 			{
				"box" : 				{
					"args" : [ "duet" ],
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-2",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "duetForOne.maxpat",
					"numinlets" : 1,
					"numoutlets" : 1,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "" ],
					"patching_rect" : [ 628.0, 85.5, 225.0, 217.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 542.0, 135.0, 225.0, 217.0 ],
					"varname" : "duetForOne",
					"viewvisibility" : 1
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
					"name" : "uc33concat.maxpat",
					"numinlets" : 1,
					"numoutlets" : 3,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "signal", "signal", "" ],
					"patching_rect" : [ 11.0, 84.5, 539.0, 553.5 ],
					"presentation" : 1,
					"presentation_rect" : [ 1.0, 3.5, 539.0, 596.5 ],
					"varname" : "uc33concat",
					"viewvisibility" : 1
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 0 ],
					"order" : 1,
					"source" : [ "obj-1", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-12", 1 ],
					"order" : 0,
					"source" : [ "obj-1", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-12", 0 ],
					"order" : 0,
					"source" : [ "obj-1", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"order" : 1,
					"source" : [ "obj-1", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-31", 0 ],
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-38", 1 ],
					"source" : [ "obj-10", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-38", 0 ],
					"source" : [ "obj-10", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"source" : [ "obj-11", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 0 ],
					"source" : [ "obj-12", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-18", 2 ],
					"source" : [ "obj-13", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-19", 0 ],
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 1 ],
					"source" : [ "obj-15", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-21", 0 ],
					"source" : [ "obj-18", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 0 ],
					"source" : [ "obj-19", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 1 ],
					"order" : 1,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-47", 0 ],
					"order" : 0,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-30", 1 ],
					"order" : 0,
					"source" : [ "obj-21", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"order" : 1,
					"source" : [ "obj-21", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-22", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-22", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-40", 0 ],
					"source" : [ "obj-23", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 1 ],
					"source" : [ "obj-24", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 0 ],
					"source" : [ "obj-27", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-18", 1 ],
					"source" : [ "obj-27", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-18", 0 ],
					"source" : [ "obj-27", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-40", 0 ],
					"order" : 0,
					"source" : [ "obj-28", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-52", 0 ],
					"order" : 1,
					"source" : [ "obj-28", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 0 ],
					"source" : [ "obj-31", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-41", 0 ],
					"source" : [ "obj-32", 4 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"source" : [ "obj-32", 5 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 0 ],
					"source" : [ "obj-33", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-36", 0 ],
					"source" : [ "obj-33", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-33", 0 ],
					"source" : [ "obj-34", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-10", 0 ],
					"source" : [ "obj-35", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-37", 0 ],
					"source" : [ "obj-36", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 0 ],
					"source" : [ "obj-37", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-28", 1 ],
					"source" : [ "obj-38", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-40", 0 ],
					"source" : [ "obj-39", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-5", 0 ],
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-28", 2 ],
					"source" : [ "obj-40", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-31", 0 ],
					"source" : [ "obj-41", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-40", 0 ],
					"source" : [ "obj-42", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 0 ],
					"source" : [ "obj-47", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 0 ],
					"source" : [ "obj-5", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-56", 0 ],
					"source" : [ "obj-51", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-55", 0 ],
					"source" : [ "obj-52", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-51", 0 ],
					"source" : [ "obj-53", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-57", 0 ],
					"source" : [ "obj-53", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-55", 0 ],
					"source" : [ "obj-54", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-56", 1 ],
					"source" : [ "obj-55", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-28", 0 ],
					"order" : 1,
					"source" : [ "obj-56", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-55", 0 ],
					"order" : 0,
					"source" : [ "obj-56", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-56", 0 ],
					"source" : [ "obj-57", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-53", 0 ],
					"source" : [ "obj-58", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 0 ],
					"order" : 0,
					"source" : [ "obj-6", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-17", 0 ],
					"order" : 0,
					"source" : [ "obj-6", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-26", 0 ],
					"order" : 1,
					"source" : [ "obj-6", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-61", 0 ],
					"order" : 1,
					"source" : [ "obj-6", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-20", 0 ],
					"order" : 0,
					"source" : [ "obj-7", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-8", 1 ],
					"order" : 1,
					"source" : [ "obj-7", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-8", 0 ],
					"order" : 2,
					"source" : [ "obj-7", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 1 ],
					"source" : [ "obj-8", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 0 ],
					"source" : [ "obj-8", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 0 ],
					"source" : [ "obj-9", 0 ]
				}

			}
 ],
		"parameters" : 		{
			"obj-1::obj-3::obj-31" : [ "aux2[9]", "aux2", 0 ],
			"obj-5::obj-32::obj-9::obj-165" : [ "2-opRateScale", "2-opRateScale", 0 ],
			"obj-5::obj-32::obj-9::obj-250" : [ "4-egR3", "4-egR3", 0 ],
			"obj-19::obj-23" : [ "modType", "modType", 0 ],
			"obj-1::obj-129::obj-24" : [ "amount", "amount", 0 ],
			"obj-5::obj-32::obj-9::obj-109" : [ "1-egL1", "1-egL1", 0 ],
			"obj-5::obj-32::obj-9::obj-207" : [ "5-egR2", "5-egR2", 0 ],
			"obj-1::obj-9::obj-8" : [ "track[3]", "track", 0 ],
			"obj-5::obj-32::obj-9::obj-322" : [ "3-egR1", "3-egR1", 0 ],
			"obj-19::obj-41" : [ "vibDepth", "vibDepth", 0 ],
			"obj-5::obj-32::obj-9::obj-214" : [ "5-opFreq", "5-opFreq", 0 ],
			"obj-7::obj-15" : [ "gain[1]", "gain", 0 ],
			"obj-1::obj-33::obj-8" : [ "track[1]", "track", 0 ],
			"obj-1::obj-122::obj-31" : [ "aux2", "aux2", 0 ],
			"obj-5::obj-32::obj-9::obj-302" : [ "3-opDetune", "3-opDet", 0 ],
			"obj-5::obj-32::obj-9::obj-121" : [ "1-opDetune", "1-opDet", 0 ],
			"obj-5::obj-32::obj-9::obj-81" : [ "0-egR3", "0-egR3", 0 ],
			"obj-7::obj-9" : [ "release", "release", 0 ],
			"obj-1::obj-62::obj-9" : [ "level[6]", "level", 0 ],
			"obj-1::obj-122::obj-22" : [ "aux1", "aux1", 0 ],
			"obj-5::obj-32::obj-9::obj-244" : [ "4-egL2", "4-egL2", 0 ],
			"obj-5::obj-32::obj-9::obj-91" : [ "0-egL1", "0-egL1", 0 ],
			"obj-5::obj-32::obj-9::obj-154" : [ "2-egL2", "2-egL2", 0 ],
			"obj-1::obj-93::obj-24" : [ "treble", "treble", 0 ],
			"obj-1::obj-11::obj-13" : [ "gain", "gain", 0 ],
			"obj-5::obj-32::obj-9::obj-248" : [ "4-egR4", "4-egR4", 0 ],
			"obj-5::obj-32::obj-9::obj-162" : [ "2-egR2", "2-egR2", 0 ],
			"obj-1::obj-54::obj-4" : [ "amountBass", "bass", 0 ],
			"obj-5::obj-32::obj-9::obj-255" : [ "4-opRateScale", "4-opRateScale", 0 ],
			"obj-1::obj-32::obj-8" : [ "track[5]", "track", 0 ],
			"obj-5::obj-32::obj-9::obj-169" : [ "2-opFreq", "2-opFreq", 0 ],
			"obj-5::obj-37" : [ "live.gain~[1]", "Gain", 0 ],
			"obj-5::obj-32::obj-9::obj-232" : [ "5-egR1", "5-egR1", 0 ],
			"obj-5::obj-32::obj-9::obj-69" : [ "0-opMode", "0-opMode", 0 ],
			"obj-7::obj-4" : [ "ratio", "ratio", 0 ],
			"obj-1::obj-9::obj-31" : [ "aux2[8]", "aux2", 0 ],
			"obj-5::obj-32::obj-9::obj-287" : [ "3-egL3", "3-egL3", 0 ],
			"obj-1::obj-59" : [ "disto", "disto", 0 ],
			"obj-5::obj-32::obj-9::obj-160" : [ "2-egR3", "2-egR3", 0 ],
			"obj-5::obj-32::obj-9::obj-103" : [ "1-egL4", "1-egL4", 0 ],
			"obj-5::obj-32::obj-9::obj-194" : [ "5-level", "5-level", 0 ],
			"obj-1::obj-22::obj-22" : [ "aux1[7]", "aux1", 0 ],
			"obj-1::obj-94" : [ "shakeFreq", "freq", 0 ],
			"obj-5::obj-32::obj-9::obj-293" : [ "3-egR4", "3-egR4", 0 ],
			"obj-1::obj-144" : [ "melody tempo", "tempo", 0 ],
			"obj-5::obj-32::obj-9::obj-100" : [ "1-keyVelSens", "1-keyVelSens", 0 ],
			"obj-5::obj-32::obj-9::obj-25" : [ "algorithm", "algo", 0 ],
			"obj-5::obj-32::obj-9::obj-300" : [ "3-opRateScale", "3-opRateScale", 0 ],
			"obj-5::obj-32::obj-9::obj-119" : [ "1-opRateScale", "1-opRateScale", 0 ],
			"obj-5::obj-32::obj-9::obj-277" : [ "4-egR1", "4-egR1", 0 ],
			"obj-5::obj-32::obj-9::obj-85" : [ "0-egL4", "0-egL4", 0 ],
			"obj-5::obj-32::obj-9::obj-281" : [ "3-keyVelSens", "3-keyVelSens", 0 ],
			"obj-5::obj-32::obj-9::obj-187" : [ "2-egR1", "2-egR1", 0 ],
			"obj-5::obj-32::obj-9::obj-83" : [ "0-egR4", "0-egR4", 0 ],
			"obj-5::obj-32::obj-9::obj-259" : [ "4-opFreq", "4-opFreq", 0 ],
			"obj-8::obj-15" : [ "level[4]", "level", 0 ],
			"obj-1::obj-32::obj-22" : [ "aux1[10]", "aux1", 0 ],
			"obj-1::obj-122::obj-8" : [ "track", "track", 0 ],
			"obj-5::obj-32::obj-9::obj-149" : [ "2-level", "2-level", 0 ],
			"obj-5::obj-32::obj-9::obj-197" : [ "5-egL3", "5-egL3", 0 ],
			"obj-1::obj-3::obj-22" : [ "aux1[9]", "aux1", 0 ],
			"obj-1::obj-145::obj-15" : [ "delay", "delay", 0 ],
			"obj-5::obj-32::obj-9::obj-252" : [ "4-egR2", "4-egR2", 0 ],
			"obj-5::obj-32::obj-9::obj-291" : [ "3-egL1", "3-egL1", 0 ],
			"obj-19::obj-24" : [ "nonLin", "nonLin", 0 ],
			"obj-19::obj-8" : [ "live.gain~[2]", "Gain", 0 ],
			"obj-1::obj-145::obj-9" : [ "freq", "freq", 0 ],
			"obj-1::obj-66" : [ "delay[2]", "delay", 0 ],
			"obj-5::obj-32::obj-9::obj-203" : [ "5-egR4", "5-egR4", 0 ],
			"obj-5::obj-32::obj-9::obj-107" : [ "1-egL2", "1-egL2", 0 ],
			"obj-12::obj-179" : [ "transposition[1]", "transpo", 0 ],
			"obj-1::obj-22::obj-8" : [ "track[2]", "track", 0 ],
			"obj-1::obj-62::obj-24" : [ "drive", "drive", 0 ],
			"obj-1::obj-10" : [ "main", "main", 0 ],
			"obj-5::obj-32::obj-9::obj-115" : [ "1-egR2", "1-egR2", 0 ],
			"obj-5::obj-32::obj-9::obj-216" : [ "5-opMode", "5-opMode", 0 ],
			"obj-1::obj-33::obj-31" : [ "aux2[6]", "aux2", 0 ],
			"obj-1::obj-129::obj-9" : [ "feedback", "fb", 0 ],
			"obj-5::obj-32::obj-9::obj-304" : [ "3-opFreq", "3-opFreq", 0 ],
			"obj-1::obj-131" : [ "tone[1]", "tone", 0 ],
			"obj-5::obj-32::obj-9::obj-205" : [ "5-egR3", "5-egR3", 0 ],
			"obj-5::obj-32::obj-9::obj-113" : [ "1-egR3", "1-egR3", 0 ],
			"obj-5::obj-32::obj-9::obj-123" : [ "1-opFreq", "1-opFreq", 0 ],
			"obj-5::obj-32::obj-9::obj-89" : [ "0-egL2", "0-egL2", 0 ],
			"obj-5::obj-32::obj-9::obj-242" : [ "4-egL3", "4-egL3", 0 ],
			"obj-7::obj-12" : [ "threshold", "thres", 0 ],
			"obj-1::obj-42" : [ "aux1[5]", "aux1", 0 ],
			"obj-5::obj-32::obj-9::obj-152" : [ "2-egL3", "2-egL3", 0 ],
			"obj-11::obj-179" : [ "transposition", "transpo", 0 ],
			"obj-5::obj-32::obj-9::obj-79" : [ "0-egR2", "0-egR2", 0 ],
			"obj-5::obj-32::obj-9::obj-237" : [ "4-keyVelSens", "4-keyVelSens", 0 ],
			"obj-7::obj-24" : [ "attack", "attack", 0 ],
			"obj-5::obj-32::obj-9::obj-158" : [ "2-egR4", "2-egR4", 0 ],
			"obj-1::obj-54::obj-24" : [ "amountTreble", "treble", 0 ],
			"obj-1::obj-145::obj-24" : [ "depth", "depth", 0 ],
			"obj-5::obj-32::obj-9::obj-95" : [ "0-level", "0-level", 0 ],
			"obj-5::obj-32::obj-9::obj-201" : [ "5-egL1", "5-egL1", 0 ],
			"obj-1::obj-32::obj-31" : [ "aux2[10]", "aux2", 0 ],
			"obj-1::obj-134" : [ "chorus", "chorus", 0 ],
			"obj-5::obj-32::obj-9::obj-171" : [ "2-opMode", "2-opMode", 0 ],
			"obj-19::obj-20" : [ "modCoef", "modCoef", 0 ],
			"obj-5::obj-32::obj-9::obj-76" : [ "0-opRateScale", "0-opRateScale", 0 ],
			"obj-1::obj-9::obj-22" : [ "aux1[8]", "aux1", 0 ],
			"obj-1::obj-98" : [ "shakeAmp", "amp", 0 ],
			"obj-5::obj-32::obj-9::obj-285" : [ "3-egL4", "3-egL4", 0 ],
			"obj-19::obj-37" : [ "vib", "vib", 0 ],
			"obj-1::obj-93::obj-13" : [ "middle", "middle", 0 ],
			"obj-5::obj-32::obj-9::obj-19" : [ "feedback[2]", "fbk", 0 ],
			"obj-5::obj-32::obj-9::obj-212" : [ "5-opDetune", "5-opDet", 0 ],
			"obj-5::obj-32::obj-9::obj-141" : [ "1-egR1", "1-egR1", 0 ],
			"obj-8::obj-4" : [ "dryWet", "dryWet", 0 ],
			"obj-1::obj-33::obj-22" : [ "aux1[6]", "aux1", 0 ],
			"obj-5::obj-32::obj-9::obj-283" : [ "3-level", "3-level", 0 ],
			"obj-1::obj-11::obj-4" : [ "preGain", "preGain", 0 ],
			"obj-1::obj-189" : [ "channel", "channel", 0 ],
			"obj-5::obj-32::obj-9::obj-102" : [ "1-level", "1-level", 0 ],
			"obj-5::obj-32::obj-9::obj-246" : [ "4-egL1", "4-egL1", 0 ],
			"obj-5::obj-32::obj-9::obj-156" : [ "2-egL1", "2-egL1", 0 ],
			"obj-5::obj-32::obj-9::obj-295" : [ "3-egR3", "3-egR3", 0 ],
			"obj-5::obj-32::obj-9::obj-28" : [ "0-egR1", "0-egR1", 0 ],
			"obj-19::obj-52" : [ "resonance", "reso", 0 ],
			"obj-5::obj-32::obj-9::obj-261" : [ "4-opMode", "4-opMode", 0 ],
			"obj-5::obj-32::obj-9::obj-97" : [ "0-keyVelSens", "0-keyVelSens", 0 ],
			"obj-5::obj-32::obj-9::obj-167" : [ "2-opDetune", "2-opDet", 0 ],
			"obj-1::obj-64" : [ "feedback[1]", "fb", 0 ],
			"obj-5::obj-32::obj-9::obj-73" : [ "0-opFreq", "0-opFreq", 0 ],
			"obj-5::obj-32::obj-9::obj-195" : [ "5-egL4", "5-egL4", 0 ],
			"obj-1::obj-3::obj-8" : [ "track[4]", "track", 0 ],
			"obj-1::obj-93::obj-4" : [ "bass", "bass", 0 ],
			"obj-5::obj-32::obj-9::obj-257" : [ "4-opDetune", "4-opDet", 0 ],
			"obj-5::obj-32::obj-9::obj-289" : [ "3-egL2", "3-egL2", 0 ],
			"obj-19::obj-33" : [ "stick", "stick", 0 ],
			"obj-5::obj-32::obj-9::obj-192" : [ "5-keyVelSens", "5-keyVelSens", 0 ],
			"obj-5::obj-32::obj-9::obj-105" : [ "1-egL3", "1-egL3", 0 ],
			"obj-12::obj-92" : [ "melody tempo[1]", "tempo", 0 ],
			"obj-1::obj-22::obj-31" : [ "aux2[7]", "aux2", 0 ],
			"obj-5::obj-32::obj-9::obj-297" : [ "3-egR2", "3-egR2", 0 ],
			"obj-1::obj-62::obj-4" : [ "tone", "tone", 0 ],
			"obj-5::obj-32::obj-9::obj-111" : [ "1-egR4", "1-egR4", 0 ],
			"obj-5::obj-32::obj-9::obj-210" : [ "5-opRateScale", "5-opRateScale", 0 ],
			"obj-5::obj-32::obj-9::obj-306" : [ "3-opMode", "3-opMode", 0 ],
			"obj-1::obj-46" : [ "aux2[5]", "aux2", 0 ],
			"obj-5::obj-32::obj-9::obj-125" : [ "1-opMode", "1-opMode", 0 ],
			"obj-1::obj-129::obj-15" : [ "delay[1]", "delay", 0 ],
			"obj-5::obj-32::obj-9::obj-87" : [ "0-egL3", "0-egL3", 0 ],
			"obj-5::obj-32::obj-9::obj-240" : [ "4-egL4", "4-egL4", 0 ],
			"obj-5::obj-32::obj-9::obj-150" : [ "2-egL4", "2-egL4", 0 ],
			"obj-5::obj-32::obj-9::obj-239" : [ "4-level", "4-level", 0 ],
			"obj-12::obj-98" : [ "rest", "rest", 0 ],
			"obj-5::obj-32::obj-9::obj-147" : [ "2-keyVelSens", "2-keyVelSens", 0 ],
			"obj-5::obj-32::obj-9::obj-74" : [ "0-opDetune", "0-opDet", 0 ],
			"obj-5::obj-32::obj-9::obj-199" : [ "5-egL2", "5-egL2", 0 ],
			"parameterbanks" : 			{

			}

		}
,
		"dependency_cache" : [ 			{
				"name" : "uc33concat.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/HCI/uc33",
				"patcherrelativepath" : "../HCI/uc33",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "mubuConcat.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/tools/under",
				"patcherrelativepath" : "../tools/under",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "track2aux.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/tools/under",
				"patcherrelativepath" : "../tools/under",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "cabinetAmpegManatee.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/audioFX/ampli",
				"patcherrelativepath" : "../audioFX/ampli",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "distoTubeScreamer.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/audioFX",
				"patcherrelativepath" : "../audioFX",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "echo.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/audioFX",
				"patcherrelativepath" : "../audioFX",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "toneStackFenderBassman.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/audioFX/ampli",
				"patcherrelativepath" : "../audioFX/ampli",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "chorus.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/audioFX",
				"patcherrelativepath" : "../audioFX",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "tube6DJ8.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/audioFX/ampli",
				"patcherrelativepath" : "../audioFX/ampli",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "duetForOne.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/midiFX/duoPourUn",
				"patcherrelativepath" : "../midiFX/duoPourUn",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "duetForOne.js",
				"bootpath" : "~/ownCloud/macShare/panoplie/midiFX/duoPourUn",
				"patcherrelativepath" : "../midiFX/duoPourUn",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "selInput.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/tools",
				"patcherrelativepath" : "../tools",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "selOutput.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/tools",
				"patcherrelativepath" : "../tools",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "midiTune.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/midiFX/scaler",
				"patcherrelativepath" : "../midiFX/scaler",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "scale.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/midiFX/scaler",
				"patcherrelativepath" : "../midiFX/scaler",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "scale.js",
				"bootpath" : "~/ownCloud/macShare/panoplie/midiFX/scaler",
				"patcherrelativepath" : "../midiFX/scaler",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "dx7main.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/synthPoly/faustInstru/faustDX7",
				"patcherrelativepath" : "../synthPoly/faustInstru/faustDX7",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "dx7bank.js",
				"bootpath" : "~/ownCloud/macShare/panoplie/synthPoly/faustInstru/faustDX7",
				"patcherrelativepath" : "../synthPoly/faustInstru/faustDX7",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "dx7.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/synthPoly/faustInstru/faustDX7",
				"patcherrelativepath" : "../synthPoly/faustInstru/faustDX7",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "midiNoteFormat.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/tools/under",
				"patcherrelativepath" : "../tools/under",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "compressor.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/audioFX",
				"patcherrelativepath" : "../audioFX",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "zitaLight.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/audioFX",
				"patcherrelativepath" : "../audioFX",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "audio2midiPolyphonic.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/tools",
				"patcherrelativepath" : "../tools",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "audio2midiPerc.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/tools",
				"patcherrelativepath" : "../tools",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "vel2dur.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/tools",
				"patcherrelativepath" : "../tools",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "stkModalBar2.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/synthPoly/faustSTK",
				"patcherrelativepath" : "../synthPoly/faustSTK",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "presetManager.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/tools",
				"patcherrelativepath" : "../tools",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "voix.json",
				"bootpath" : "~/ownCloud/macShare/panoplie/examples",
				"patcherrelativepath" : ".",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "mubu.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "pipo.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "mubu.concat~.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "mubu.knn.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "mubu.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "mubu.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "cabinetAmpegManateeTreble~.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "cabinetAmpegManateeBass~.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "distoTubeScreamer~.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "echo~.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "toneStackFenderBassman~.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "chorus~.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "tube6DJ8~.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "faustDX7~.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "compressor~.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "zitaLight~.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "sigmund~.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "stkModalBar2~.mxo",
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
