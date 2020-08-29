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
		"rect" : [ 222.0, 79.0, 1003.0, 787.0 ],
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
					"bubbleside" : 0,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-20",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 489.0, 369.427246000000025, 99.0, 39.0 ],
					"text" : "aux2: Echo FX",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 0,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-19",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 386.5, 585.427245999999968, 187.0, 39.0 ],
					"text" : "aux1: Chorus > Disto > TS FXs",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-10",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "uc33concat.maxpat",
					"numinlets" : 1,
					"numoutlets" : 3,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "signal", "signal", "" ],
					"patching_rect" : [ 142.0, 74.427277000000004, 532.0, 546.0 ],
					"varname" : "uc33concat",
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-16",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 623.108764999999948, 131.927277000000004, 179.0, 37.0 ],
					"text" : "Parameters for concatenative synthesis",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"angle" : 270.0,
					"bgcolor" : [ 0.862745, 0.870588, 0.878431, 1.0 ],
					"bordercolor" : [ 0.0, 0.0, 0.0, 0.0 ],
					"id" : "obj-2",
					"maxclass" : "panel",
					"mode" : 0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 147.75, 519.427245999999968, 172.108765000000005, 43.0 ],
					"proportion" : 0.39
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 16.0,
					"id" : "obj-4",
					"linecount" : 4,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 617.108764999999948, 509.927246000000025, 247.0, 78.0 ],
					"text" : "To work, it is necessary to install the free third-party application MuBu For Max. For that, you can use the Max package installer",
					"textjustification" : 2
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontsize" : 15.0,
					"id" : "obj-23",
					"linecount" : 4,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 693.108764999999948, 195.927260999999987, 109.0, 74.0 ],
					"text" : "Area controlled by the MIDI controller",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-21",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 4.75, 469.427246000000025, 141.0, 37.0 ],
					"text" : "Tempo parameters for synthesis",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 16.0,
					"id" : "obj-32",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 198.5, 6.0, 329.0, 24.0 ],
					"text" : "Concatenative synthesis for UC33 controler"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-18",
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 142.0, 659.0, 45.0, 45.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-17",
					"maxclass" : "ezadc~",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "signal" ],
					"patching_rect" : [ 142.0, 6.0, 45.0, 45.0 ]
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-15",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 4.75, 81.427277000000004, 141.0, 24.0 ],
					"text" : "Recording a sound",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-14",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 27.75, 351.427246000000025, 118.0, 24.0 ],
					"text" : "Channels gain",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-13",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 555.0, 682.0, 119.0, 22.0 ],
					"text" : "stop"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 0,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-11",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 590.5, 627.427245999999968, 148.0, 52.0 ],
					"text" : "Tempo data, when outlet parameter is selected",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-8",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 4.75, 525.427245999999968, 143.0, 37.0 ],
					"text" : "Select the aux channel output",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 0,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-7",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 337.5, 627.427245999999968, 141.0, 52.0 ],
					"text" : "Aux output for one channel",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-3",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 4.75, 217.427277000000004, 141.0, 24.0 ],
					"text" : "Sends parameters",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"angle" : 270.0,
					"bgcolor" : [ 0.862745, 0.870588, 0.878431, 0.8 ],
					"border" : 2,
					"bordercolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"id" : "obj-72",
					"maxclass" : "panel",
					"mode" : 0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 142.0, 78.427277000000004, 664.108764999999948, 380.999969000000021 ],
					"proportion" : 0.39
				}

			}
, 			{
				"box" : 				{
					"angle" : 270.0,
					"bgcolor" : [ 0.862745, 0.870588, 0.878431, 1.0 ],
					"bordercolor" : [ 0.0, 0.0, 0.0, 0.0 ],
					"id" : "obj-1",
					"maxclass" : "panel",
					"mode" : 0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 204.0, 468.427246000000025, 174.108765000000005, 25.999969 ],
					"proportion" : 0.39
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 1 ],
					"source" : [ "obj-10", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-18", 1 ],
					"order" : 0,
					"source" : [ "obj-10", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-18", 0 ],
					"order" : 1,
					"source" : [ "obj-10", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-10", 0 ],
					"source" : [ "obj-17", 0 ]
				}

			}
 ],
		"parameters" : 		{
			"obj-10::obj-3::obj-31" : [ "aux2[9]", "aux2", 0 ],
			"obj-10::obj-93::obj-4" : [ "bass", "bass", 0 ],
			"obj-10::obj-93::obj-24" : [ "treble", "treble", 0 ],
			"obj-10::obj-9::obj-22" : [ "aux1[8]", "aux1", 0 ],
			"obj-10::obj-134" : [ "chorus", "chorus", 0 ],
			"obj-10::obj-94" : [ "shakeFreq", "freq", 0 ],
			"obj-10::obj-33::obj-31" : [ "aux2[6]", "aux2", 0 ],
			"obj-10::obj-59" : [ "disto", "disto", 0 ],
			"obj-10::obj-129::obj-15" : [ "delay[1]", "delay", 0 ],
			"obj-10::obj-64" : [ "feedback[1]", "fb", 0 ],
			"obj-10::obj-122::obj-8" : [ "track", "track", 0 ],
			"obj-10::obj-145::obj-9" : [ "freq", "freq", 0 ],
			"obj-10::obj-32::obj-22" : [ "aux1[10]", "aux1", 0 ],
			"obj-10::obj-66" : [ "delay[2]", "delay", 0 ],
			"obj-10::obj-9::obj-31" : [ "aux2[8]", "aux2", 0 ],
			"obj-10::obj-46" : [ "aux2[5]", "aux2", 0 ],
			"obj-10::obj-11::obj-13" : [ "gain", "gain", 0 ],
			"obj-10::obj-22::obj-31" : [ "aux2[7]", "aux2", 0 ],
			"obj-10::obj-10" : [ "main", "main", 0 ],
			"obj-10::obj-54::obj-4" : [ "amountBass", "bass", 0 ],
			"obj-10::obj-32::obj-31" : [ "aux2[10]", "aux2", 0 ],
			"obj-10::obj-3::obj-22" : [ "aux1[9]", "aux1", 0 ],
			"obj-10::obj-145::obj-24" : [ "depth", "depth", 0 ],
			"obj-10::obj-98" : [ "shakeAmp", "amp", 0 ],
			"obj-10::obj-22::obj-8" : [ "track[2]", "track", 0 ],
			"obj-10::obj-33::obj-22" : [ "aux1[6]", "aux1", 0 ],
			"obj-10::obj-62::obj-4" : [ "tone", "tone", 0 ],
			"obj-10::obj-145::obj-15" : [ "delay", "delay", 0 ],
			"obj-10::obj-62::obj-9" : [ "level[2]", "level", 0 ],
			"obj-10::obj-62::obj-24" : [ "drive", "drive", 0 ],
			"obj-10::obj-32::obj-8" : [ "track[5]", "track", 0 ],
			"obj-10::obj-9::obj-8" : [ "track[3]", "track", 0 ],
			"obj-10::obj-11::obj-4" : [ "preGain", "preGain", 0 ],
			"obj-10::obj-33::obj-8" : [ "track[1]", "track", 0 ],
			"obj-10::obj-122::obj-31" : [ "aux2", "aux2", 0 ],
			"obj-10::obj-144" : [ "melody tempo", "tempo", 0 ],
			"obj-10::obj-131" : [ "tone[1]", "tone", 0 ],
			"obj-10::obj-54::obj-24" : [ "amountTreble", "treble", 0 ],
			"obj-10::obj-129::obj-9" : [ "feedback", "fb", 0 ],
			"obj-10::obj-122::obj-22" : [ "aux1", "aux1", 0 ],
			"obj-10::obj-129::obj-24" : [ "amount", "amount", 0 ],
			"obj-10::obj-189" : [ "channel", "channel", 0 ],
			"obj-10::obj-93::obj-13" : [ "middle", "middle", 0 ],
			"obj-10::obj-3::obj-8" : [ "track[4]", "track", 0 ],
			"obj-10::obj-22::obj-22" : [ "aux1[7]", "aux1", 0 ],
			"obj-10::obj-42" : [ "aux1[5]", "aux1", 0 ],
			"parameterbanks" : 			{

			}

		}
,
		"dependency_cache" : [ 			{
				"name" : "uc33concat.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/HCI/uc33",
				"patcherrelativepath" : ".",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "mubuConcat.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/tools/under",
				"patcherrelativepath" : "../../tools/under",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "track2aux.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/tools/under",
				"patcherrelativepath" : "../../tools/under",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "cabinetAmpegManatee.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/audioFX/ampli",
				"patcherrelativepath" : "../../audioFX/ampli",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "distoTubeScreamer.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/audioFX",
				"patcherrelativepath" : "../../audioFX",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "echo.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/audioFX",
				"patcherrelativepath" : "../../audioFX",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "toneStackFenderBassman.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/audioFX/ampli",
				"patcherrelativepath" : "../../audioFX/ampli",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "chorus.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/audioFX",
				"patcherrelativepath" : "../../audioFX",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "tube6DJ8.maxpat",
				"bootpath" : "~/ownCloud/macShare/panoplie/audioFX/ampli",
				"patcherrelativepath" : "../../audioFX/ampli",
				"type" : "JSON",
				"implicit" : 1
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
 ],
		"autosave" : 0,
		"styles" : [ 			{
				"name" : "newobjBlue-1",
				"default" : 				{
					"accentcolor" : [ 0.317647, 0.654902, 0.976471, 1.0 ]
				}
,
				"parentstyle" : "",
				"multi" : 0
			}
, 			{
				"name" : "newobjGreen-1",
				"default" : 				{
					"accentcolor" : [ 0.0, 0.533333, 0.168627, 1.0 ]
				}
,
				"parentstyle" : "",
				"multi" : 0
			}
, 			{
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
