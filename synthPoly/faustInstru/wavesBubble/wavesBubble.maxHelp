{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 8,
			"minor" : 0,
			"revision" : 0,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"rect" : [ 180.0, 87.0, 605.0, 757.0 ],
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
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-10",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 409.371979, 118.427277, 158.0, 51.0 ],
					"presentation_linecount" : 5,
					"presentation_rect" : [ 409.371979, 118.427277, 158.0, 51.0 ],
					"style" : "",
					"text" : "LFO form : 0=sin ; 2=saw ; 2=randSmooth ; 3=rand",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-9",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 36.5, 10.427277, 96.0, 37.0 ],
					"presentation_rect" : [ 36.5, 10.427277, 96.0, 37.0 ],
					"style" : "",
					"text" : "Tremolo parameters",
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
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 5.5, 484.427277, 127.0, 24.0 ],
					"presentation_rect" : [ 5.5, 484.427277, 127.0, 24.0 ],
					"style" : "",
					"text" : "FM parameters",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-4",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1.5, 590.427246, 132.0, 24.0 ],
					"presentation_rect" : [ 1.5, 590.427246, 132.0, 24.0 ],
					"style" : "",
					"text" : "Output parameters",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-3",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 409.371979, 80.427277, 100.0, 24.0 ],
					"presentation_rect" : [ 409.371979, 80.427277, 100.0, 24.0 ],
					"style" : "",
					"text" : "Portamento",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-27",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 48.371979, 80.427277, 85.0, 24.0 ],
					"presentation_rect" : [ 48.371979, 80.427277, 85.0, 24.0 ],
					"style" : "",
					"text" : "ADSR env",
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
					"patching_rect" : [ 5.5, 242.427277, 127.0, 24.0 ],
					"presentation_rect" : [ 5.5, 242.427277, 127.0, 24.0 ],
					"style" : "",
					"text" : "OSC parameters",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-6",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 36.5, 125.427277, 96.0, 37.0 ],
					"presentation_rect" : [ 36.5, 125.427277, 96.0, 37.0 ],
					"style" : "",
					"text" : "Global LFO parameters",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-5",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 21.5, 365.427277, 111.0, 37.0 ],
					"presentation_rect" : [ 21.5, 365.427277, 111.0, 37.0 ],
					"style" : "",
					"text" : "Low pass filter parameters",
					"textjustification" : 1
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
					"id" : "obj-2",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "wavesBubble.maxpat",
					"numinlets" : 1,
					"numoutlets" : 1,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 133.371979, 2.0, 291.0, 654.0 ],
					"presentation_rect" : [ 133.371979, 2.0, 291.0, 654.0 ],
					"varname" : "wavesBubble",
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-1",
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 133.371979, 683.0, 45.0, 45.0 ],
					"presentation_rect" : [ 133.371979, 683.0, 45.0, 45.0 ],
					"style" : ""
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 1 ],
					"order" : 0,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"order" : 1,
					"source" : [ "obj-2", 0 ]
				}

			}
 ],
		"parameters" : 		{
			"obj-2::obj-147" : [ "fmLFO1", "fmLFO1", 0 ],
			"obj-2::obj-203" : [ "osc3form", "form3", 0 ],
			"obj-2::obj-56" : [ "lfo1rate", "rate1", 0 ],
			"obj-2::obj-66" : [ "lpD", "D", 0 ],
			"obj-2::obj-13" : [ "bpm", "bpm", 0 ],
			"obj-2::obj-100" : [ "lpLFO2", "lpLFO2", 0 ],
			"obj-2::obj-31" : [ "D", "D", 0 ],
			"obj-2::obj-175" : [ "osc1LFO2", "LFO2", 0 ],
			"obj-2::obj-178" : [ "osc2LFO2", "LFO2", 0 ],
			"obj-2::obj-141" : [ "fmIndex", "Index", 0 ],
			"obj-2::obj-34" : [ "S", "S", 0 ],
			"obj-2::obj-195" : [ "osc3LFO2", "LFO2", 0 ],
			"obj-2::obj-128" : [ "fmS", "S", 0 ],
			"obj-2::obj-151" : [ "tremLFO1", "trem1", 0 ],
			"obj-2::obj-69" : [ "lpA", "A", 0 ],
			"obj-2::obj-63" : [ "lpS", "S", 0 ],
			"obj-2::obj-166" : [ "osc1tune", "tune1", 0 ],
			"obj-2::obj-132" : [ "fmD", "D", 0 ],
			"obj-2::obj-184" : [ "osc2tune", "tune2", 0 ],
			"obj-2::obj-144" : [ "fmLFO2", "fmLFO2", 0 ],
			"obj-2::obj-201" : [ "osc3tune", "tune3", 0 ],
			"obj-2::obj-50" : [ "lfo2form", "form2", 0 ],
			"obj-2::obj-87" : [ "lpDepth", "depth", 0 ],
			"obj-2::obj-60" : [ "lpR", "R", 0 ],
			"obj-2::obj-160" : [ "osc1amp", "amp1", 0 ],
			"obj-2::obj-135" : [ "fmA", "A", 0 ],
			"obj-2::obj-190" : [ "osc2amp", "amp2", 0 ],
			"obj-2::obj-205" : [ "osc3amp", "amp3", 0 ],
			"obj-2::obj-43" : [ "lfo1form", "form1", 0 ],
			"obj-2::obj-154" : [ "tremLFO2", "trem2", 0 ],
			"obj-2::obj-91" : [ "lpCutCoef", "cutCoef", 0 ],
			"obj-2::obj-94" : [ "lpLFO1", "lpLFO1", 0 ],
			"obj-2::obj-172" : [ "osc1LFO1", "LFO1", 0 ],
			"obj-2::obj-181" : [ "osc2LFO1", "LFO1", 0 ],
			"obj-2::obj-117" : [ "fmEnvDepth", "envDepth", 0 ],
			"obj-2::obj-198" : [ "osc3LFO1", "LFO1", 0 ],
			"obj-2::obj-8" : [ "live.gain~", "Gain", 0 ],
			"obj-2::obj-122" : [ "fmR", "R", 0 ],
			"obj-2::obj-38" : [ "R", "R", 0 ],
			"obj-2::obj-7" : [ "portamento", "porta", 0 ],
			"obj-2::obj-57" : [ "lfo2rate", "rate2", 0 ],
			"obj-2::obj-73" : [ "lpEnvDepth", "envDepth", 0 ],
			"obj-2::obj-15" : [ "A", "A", 0 ],
			"obj-2::obj-105" : [ "lpResonance", "reson", 0 ],
			"obj-2::obj-163" : [ "osc1form", "form1", 0 ],
			"obj-2::obj-138" : [ "fmCoef", "fmCoef", 0 ],
			"obj-2::obj-187" : [ "osc2form", "form2", 0 ],
			"parameterbanks" : 			{

			}

		}
,
		"dependency_cache" : [ 			{
				"name" : "wavesBubble.maxpat",
				"bootpath" : "~/ownCloud/macShare/lutherie/synthPoly/faustInstru/wavesBubble",
				"patcherrelativepath" : ".",
				"type" : "TEXT",
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
				"name" : "wavesBubble~.mxo",
				"type" : "iLaX"
			}
 ],
		"autosave" : 0
	}

}
