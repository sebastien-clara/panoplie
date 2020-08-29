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
		"rect" : [ 108.0, 79.0, 858.0, 671.0 ],
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
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-11",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "noiseGate.maxpat",
					"numinlets" : 1,
					"numoutlets" : 1,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 376.0, 121.0, 129.0, 87.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 273.0, 253.0, 129.0, 87.0 ],
					"varname" : "noiseGate",
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.960784, 0.827451, 0.156863, 0.0 ],
					"bubble" : 1,
					"bubbleside" : 2,
					"id" : "obj-14",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 322.75, 482.5, 98.0, 52.0 ],
					"text" : "Space bar = +1\nDel = -1",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-21",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 369.0, 616.0, 22.0, 22.0 ],
					"text" : "-1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-32",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 3,
					"outlettype" : [ "bang", "bang", "" ],
					"patching_rect" : [ 346.5, 576.5, 64.0, 22.0 ],
					"text" : "sel 32 127"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-33",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 425.0, 576.5, 70.0, 22.0 ],
					"text" : "loadmess 1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-34",
					"maxclass" : "number",
					"minimum" : 1,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 425.0, 616.0, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-35",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"patching_rect" : [ 349.0, 664.0, 29.5, 22.0 ],
					"text" : "+"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-36",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 349.0, 616.0, 18.0, 22.0 ],
					"text" : "1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-37",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 4,
					"outlettype" : [ "int", "int", "int", "int" ],
					"patching_rect" : [ 346.5, 538.0, 50.5, 22.0 ],
					"text" : "key"
				}

			}
, 			{
				"box" : 				{
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-31",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "dryWet.maxpat",
					"numinlets" : 2,
					"numoutlets" : 1,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 376.0, 48.0, 71.0, 55.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 307.0, 146.0, 71.0, 55.0 ],
					"varname" : "dryWet",
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-4",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 383.0, 828.0, 62.0, 22.0 ],
					"text" : "route float"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-23",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 601.0, 425.0, 55.0, 22.0 ],
					"text" : "dxSeven"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-24",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "bang" ],
					"patching_rect" : [ 465.0, 387.0, 155.0, 22.0 ],
					"text" : "t b b"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-25",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 465.0, 352.0, 93.0, 22.0 ],
					"text" : "loadbang"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-26",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 515.0, 500.0, 105.0, 22.0 ],
					"text" : "sprintf %s%s.json"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-27",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 465.0, 425.0, 34.0, 22.0 ],
					"text" : "path"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-28",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 465.0, 459.0, 69.0, 22.0 ],
					"save" : [ "#N", "thispatcher", ";", "#Q", "end", ";" ],
					"text" : "thispatcher"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-8",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "", "", "", "" ],
					"patching_rect" : [ 283.0, 394.5, 58.0, 22.0 ],
					"text" : "autopattr",
					"varname" : "u037003537"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-9",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 657.0, 763.0, 97.0, 23.0 ],
					"text" : "storagewindow"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-38",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 632.0, 721.0, 84.0, 23.0 ],
					"text" : "clientwindow"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-10",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "" ],
					"patching_rect" : [ 515.0, 542.0, 143.0, 22.0 ],
					"text" : "t b l"
				}

			}
, 			{
				"box" : 				{
					"autorestore" : "dxSeven.json",
					"id" : "obj-13",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 457.0, 828.0, 100.0, 22.0 ],
					"saved_object_attributes" : 					{
						"client_rect" : [ 51, 45, 405, 173 ],
						"parameter_enable" : 0,
						"parameter_mappable" : 0,
						"storage_rect" : [ 583, 69, 1034, 197 ]
					}
,
					"text" : "pattrstorage",
					"varname" : "u550003153"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-18",
					"linecount" : 4,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 515.0, 576.0, 143.0, 62.0 ],
					"text" : "MacintoshHD:/Users/cs38620h/ownCloud/macShare/panoplie/examples/dxSeven.json"
				}

			}
, 			{
				"box" : 				{
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-20",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "presetManager.maxpat",
					"numinlets" : 3,
					"numoutlets" : 1,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "" ],
					"patching_rect" : [ 457.0, 663.0, 135.0, 134.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 278.0, 1.0, 129.0, 131.0 ],
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-7",
					"maxclass" : "live.meter~",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "float", "int" ],
					"patching_rect" : [ 596.0, 242.0, 19.0, 79.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 431.0, 342.0, 19.0, 79.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-2",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "compressor.maxpat",
					"numinlets" : 1,
					"numoutlets" : 1,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 376.0, 242.0, 218.0, 79.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 213.0, 342.0, 218.0, 79.0 ],
					"varname" : "compressor",
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-22",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "toneStackFenderBassman.maxpat",
					"numinlets" : 1,
					"numoutlets" : 1,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 20.0, 471.0, 154.0, 75.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 3.0, 346.0, 154.0, 75.0 ],
					"varname" : "toneStackFenderBassman",
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-17",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "distoTubeScreamer.maxpat",
					"numinlets" : 1,
					"numoutlets" : 1,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 20.0, 266.0, 209.0, 85.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 3.0, 187.0, 209.0, 85.0 ],
					"varname" : "distoTubeScreamer",
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-16",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "cabinetAmpegMotown.maxpat",
					"numinlets" : 1,
					"numoutlets" : 1,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 20.0, 369.0, 154.0, 73.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 3.0, 274.0, 154.0, 73.0 ],
					"varname" : "cabinetAmpegMotown",
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-6",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 20.0, 585.0, 130.0, 22.0 ],
					"text" : "send~ toAudioOut"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-5",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 428.0, 8.0, 130.0, 22.0 ],
					"text" : "receive~ toAudioOut"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-3",
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 386.0, 383.0, 45.0, 45.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 320.0, 202.0, 45.0, 45.0 ]
				}

			}
, 			{
				"box" : 				{
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
					"patching_rect" : [ 20.0, 12.0, 274.0, 186.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 3.0, 1.0, 271.0, 181.0 ],
					"varname" : "dx7main",
					"viewvisibility" : 1
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-17", 0 ],
					"order" : 1,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-31", 0 ],
					"order" : 0,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-18", 1 ],
					"source" : [ "obj-10", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-18", 0 ],
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
					"destination" : [ "obj-20", 2 ],
					"source" : [ "obj-13", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"source" : [ "obj-16", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 0 ],
					"source" : [ "obj-17", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-20", 1 ],
					"source" : [ "obj-18", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 1 ],
					"order" : 1,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 0 ],
					"order" : 2,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 0 ],
					"order" : 0,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 0 ],
					"order" : 0,
					"source" : [ "obj-20", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"order" : 1,
					"source" : [ "obj-20", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 0 ],
					"source" : [ "obj-21", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"source" : [ "obj-22", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-26", 1 ],
					"source" : [ "obj-23", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"source" : [ "obj-24", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 0 ],
					"source" : [ "obj-24", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 0 ],
					"source" : [ "obj-25", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-10", 0 ],
					"source" : [ "obj-26", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-28", 0 ],
					"source" : [ "obj-27", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-26", 0 ],
					"source" : [ "obj-28", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 0 ],
					"source" : [ "obj-31", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-21", 0 ],
					"source" : [ "obj-32", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-36", 0 ],
					"source" : [ "obj-32", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-34", 0 ],
					"source" : [ "obj-33", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 1 ],
					"source" : [ "obj-34", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-20", 0 ],
					"order" : 1,
					"source" : [ "obj-35", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-34", 0 ],
					"order" : 0,
					"source" : [ "obj-35", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 0 ],
					"source" : [ "obj-36", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-32", 0 ],
					"source" : [ "obj-37", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 0 ],
					"source" : [ "obj-38", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-34", 0 ],
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-31", 1 ],
					"source" : [ "obj-5", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 0 ],
					"source" : [ "obj-9", 0 ]
				}

			}
 ],
		"parameters" : 		{
			"obj-1::obj-32::obj-9::obj-210" : [ "5-opRateScale", "5-opRateScale", 0 ],
			"obj-1::obj-32::obj-9::obj-111" : [ "1-egR4", "1-egR4", 0 ],
			"obj-1::obj-32::obj-9::obj-306" : [ "3-opMode", "3-opMode", 0 ],
			"obj-16::obj-4" : [ "amount", "amount", 0 ],
			"obj-1::obj-32::obj-9::obj-125" : [ "1-opMode", "1-opMode", 0 ],
			"obj-2::obj-15" : [ "gain", "gain", 0 ],
			"obj-1::obj-32::obj-9::obj-250" : [ "4-egR3", "4-egR3", 0 ],
			"obj-1::obj-32::obj-9::obj-240" : [ "4-egL4", "4-egL4", 0 ],
			"obj-1::obj-32::obj-9::obj-89" : [ "0-egL2", "0-egL2", 0 ],
			"obj-1::obj-32::obj-9::obj-295" : [ "3-egR3", "3-egR3", 0 ],
			"obj-1::obj-32::obj-9::obj-150" : [ "2-egL4", "2-egL4", 0 ],
			"obj-17::obj-4" : [ "tone", "tone", 0 ],
			"obj-22::obj-24" : [ "treble", "treble", 0 ],
			"obj-1::obj-32::obj-9::obj-239" : [ "4-level", "4-level", 0 ],
			"obj-1::obj-32::obj-9::obj-79" : [ "0-egR2", "0-egR2", 0 ],
			"obj-1::obj-32::obj-9::obj-252" : [ "4-egR2", "4-egR2", 0 ],
			"obj-1::obj-32::obj-9::obj-147" : [ "2-keyVelSens", "2-keyVelSens", 0 ],
			"obj-2::obj-24" : [ "attack", "attack", 0 ],
			"obj-1::obj-32::obj-9::obj-74" : [ "0-opDetune", "0-opDet", 0 ],
			"obj-1::obj-32::obj-9::obj-199" : [ "5-egL2", "5-egL2", 0 ],
			"obj-1::obj-32::obj-9::obj-165" : [ "2-opRateScale", "2-opRateScale", 0 ],
			"obj-1::obj-32::obj-9::obj-257" : [ "4-opDetune", "4-opDet", 0 ],
			"obj-1::obj-32::obj-9::obj-109" : [ "1-egL1", "1-egL1", 0 ],
			"obj-1::obj-32::obj-9::obj-207" : [ "5-egR2", "5-egR2", 0 ],
			"obj-1::obj-32::obj-9::obj-322" : [ "3-egR1", "3-egR1", 0 ],
			"obj-1::obj-32::obj-9::obj-113" : [ "1-egR3", "1-egR3", 0 ],
			"obj-1::obj-32::obj-9::obj-214" : [ "5-opFreq", "5-opFreq", 0 ],
			"obj-1::obj-32::obj-9::obj-302" : [ "3-opDetune", "3-opDet", 0 ],
			"obj-1::obj-32::obj-9::obj-121" : [ "1-opDetune", "1-opDet", 0 ],
			"obj-1::obj-32::obj-9::obj-91" : [ "0-egL1", "0-egL1", 0 ],
			"obj-1::obj-32::obj-9::obj-244" : [ "4-egL2", "4-egL2", 0 ],
			"obj-1::obj-32::obj-9::obj-154" : [ "2-egL2", "2-egL2", 0 ],
			"obj-1::obj-32::obj-9::obj-28" : [ "0-egR1", "0-egR1", 0 ],
			"obj-1::obj-32::obj-9::obj-248" : [ "4-egR4", "4-egR4", 0 ],
			"obj-1::obj-32::obj-9::obj-281" : [ "3-keyVelSens", "3-keyVelSens", 0 ],
			"obj-1::obj-32::obj-9::obj-205" : [ "5-egR3", "5-egR3", 0 ],
			"obj-1::obj-32::obj-9::obj-162" : [ "2-egR2", "2-egR2", 0 ],
			"obj-1::obj-32::obj-9::obj-97" : [ "0-keyVelSens", "0-keyVelSens", 0 ],
			"obj-1::obj-32::obj-9::obj-255" : [ "4-opRateScale", "4-opRateScale", 0 ],
			"obj-1::obj-32::obj-9::obj-169" : [ "2-opFreq", "2-opFreq", 0 ],
			"obj-1::obj-32::obj-9::obj-232" : [ "5-egR1", "5-egR1", 0 ],
			"obj-1::obj-32::obj-9::obj-69" : [ "0-opMode", "0-opMode", 0 ],
			"obj-11::obj-38" : [ "threshold[1]", "thresh", 0 ],
			"obj-1::obj-32::obj-9::obj-287" : [ "3-egL3", "3-egL3", 0 ],
			"obj-1::obj-32::obj-9::obj-103" : [ "1-egL4", "1-egL4", 0 ],
			"obj-1::obj-32::obj-9::obj-194" : [ "5-level", "5-level", 0 ],
			"obj-2::obj-9" : [ "release", "release", 0 ],
			"obj-1::obj-32::obj-9::obj-293" : [ "3-egR4", "3-egR4", 0 ],
			"obj-1::obj-32::obj-9::obj-25" : [ "algorithm", "algo", 0 ],
			"obj-1::obj-32::obj-9::obj-100" : [ "1-keyVelSens", "1-keyVelSens", 0 ],
			"obj-1::obj-32::obj-9::obj-300" : [ "3-opRateScale", "3-opRateScale", 0 ],
			"obj-17::obj-9" : [ "level", "level", 0 ],
			"obj-1::obj-32::obj-9::obj-119" : [ "1-opRateScale", "1-opRateScale", 0 ],
			"obj-1::obj-32::obj-9::obj-277" : [ "4-egR1", "4-egR1", 0 ],
			"obj-1::obj-32::obj-9::obj-87" : [ "0-egL3", "0-egL3", 0 ],
			"obj-1::obj-32::obj-9::obj-187" : [ "2-egR1", "2-egR1", 0 ],
			"obj-1::obj-32::obj-9::obj-259" : [ "4-opFreq", "4-opFreq", 0 ],
			"obj-1::obj-32::obj-9::obj-149" : [ "2-level", "2-level", 0 ],
			"obj-2::obj-12" : [ "threshold", "thres", 0 ],
			"obj-1::obj-32::obj-9::obj-197" : [ "5-egL3", "5-egL3", 0 ],
			"obj-11::obj-39" : [ "attack[1]", "attack", 0 ],
			"obj-1::obj-32::obj-9::obj-291" : [ "3-egL1", "3-egL1", 0 ],
			"obj-1::obj-32::obj-9::obj-203" : [ "5-egR4", "5-egR4", 0 ],
			"obj-1::obj-32::obj-9::obj-107" : [ "1-egL2", "1-egL2", 0 ],
			"obj-1::obj-32::obj-9::obj-216" : [ "5-opMode", "5-opMode", 0 ],
			"obj-1::obj-32::obj-9::obj-115" : [ "1-egR2", "1-egR2", 0 ],
			"obj-1::obj-32::obj-9::obj-304" : [ "3-opFreq", "3-opFreq", 0 ],
			"obj-1::obj-32::obj-9::obj-123" : [ "1-opFreq", "1-opFreq", 0 ],
			"obj-1::obj-32::obj-9::obj-242" : [ "4-egL3", "4-egL3", 0 ],
			"obj-1::obj-32::obj-9::obj-152" : [ "2-egL3", "2-egL3", 0 ],
			"obj-17::obj-24" : [ "drive", "drive", 0 ],
			"obj-22::obj-13" : [ "middle", "middle", 0 ],
			"obj-1::obj-32::obj-9::obj-237" : [ "4-keyVelSens", "4-keyVelSens", 0 ],
			"obj-2::obj-4" : [ "ratio", "ratio", 0 ],
			"obj-1::obj-32::obj-9::obj-158" : [ "2-egR4", "2-egR4", 0 ],
			"obj-1::obj-32::obj-9::obj-201" : [ "5-egL1", "5-egL1", 0 ],
			"obj-1::obj-32::obj-9::obj-171" : [ "2-opMode", "2-opMode", 0 ],
			"obj-1::obj-32::obj-9::obj-76" : [ "0-opRateScale", "0-opRateScale", 0 ],
			"obj-11::obj-41" : [ "release[1]", "release", 0 ],
			"obj-1::obj-32::obj-9::obj-285" : [ "3-egL4", "3-egL4", 0 ],
			"obj-1::obj-32::obj-9::obj-141" : [ "1-egR1", "1-egR1", 0 ],
			"obj-1::obj-32::obj-9::obj-212" : [ "5-opDetune", "5-opDet", 0 ],
			"obj-1::obj-32::obj-9::obj-283" : [ "3-level", "3-level", 0 ],
			"obj-1::obj-32::obj-9::obj-102" : [ "1-level", "1-level", 0 ],
			"obj-1::obj-32::obj-9::obj-19" : [ "feedback", "fbk", 0 ],
			"obj-31::obj-24" : [ "dryWet", "dryWet", 0 ],
			"obj-1::obj-32::obj-9::obj-246" : [ "4-egL1", "4-egL1", 0 ],
			"obj-1::obj-32::obj-9::obj-156" : [ "2-egL1", "2-egL1", 0 ],
			"obj-1::obj-32::obj-9::obj-85" : [ "0-egL4", "0-egL4", 0 ],
			"obj-1::obj-32::obj-9::obj-83" : [ "0-egR4", "0-egR4", 0 ],
			"obj-1::obj-32::obj-9::obj-261" : [ "4-opMode", "4-opMode", 0 ],
			"obj-1::obj-32::obj-9::obj-167" : [ "2-opDetune", "2-opDet", 0 ],
			"obj-1::obj-32::obj-9::obj-195" : [ "5-egL4", "5-egL4", 0 ],
			"obj-1::obj-32::obj-9::obj-160" : [ "2-egR3", "2-egR3", 0 ],
			"obj-1::obj-32::obj-9::obj-73" : [ "0-opFreq", "0-opFreq", 0 ],
			"obj-1::obj-37" : [ "live.gain~", "Gain", 0 ],
			"obj-1::obj-32::obj-9::obj-95" : [ "0-level", "0-level", 0 ],
			"obj-1::obj-32::obj-9::obj-289" : [ "3-egL2", "3-egL2", 0 ],
			"obj-1::obj-32::obj-9::obj-192" : [ "5-keyVelSens", "5-keyVelSens", 0 ],
			"obj-1::obj-32::obj-9::obj-105" : [ "1-egL3", "1-egL3", 0 ],
			"obj-22::obj-4" : [ "bass", "bass", 0 ],
			"obj-1::obj-32::obj-9::obj-81" : [ "0-egR3", "0-egR3", 0 ],
			"obj-1::obj-32::obj-9::obj-297" : [ "3-egR2", "3-egR2", 0 ],
			"parameterbanks" : 			{

			}

		}
,
		"dependency_cache" : [ 			{
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
				"name" : "selInput.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/tools",
				"patcherrelativepath" : "../tools",
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
				"name" : "cabinetAmpegMotown.maxpat",
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
				"name" : "toneStackFenderBassman.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/audioFX/ampli",
				"patcherrelativepath" : "../audioFX/ampli",
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
				"name" : "presetManager.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/tools",
				"patcherrelativepath" : "../tools",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "dxSeven.json",
				"bootpath" : "~/ownCloud/macShare/panoplie/examples",
				"patcherrelativepath" : ".",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "dryWet.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/tools",
				"patcherrelativepath" : "../tools",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "noiseGate.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/tools",
				"patcherrelativepath" : "../tools",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "faustDX7~.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "cabinetAmpegMotown~.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "distoTubeScreamer~.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "toneStackFenderBassman~.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "compressor~.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "dryWet~.mxo",
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
