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
		"rect" : [ 110.0, 104.0, 778.0, 674.0 ],
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
					"id" : "obj-6",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 0.75, 480.427277, 141.0, 24.0 ],
					"presentation_rect" : [ 9.75, 318.427277, 0.0, 0.0 ],
					"style" : "",
					"text" : "I/O parameters",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-4",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 471.75, 247.927277, 141.0, 24.0 ],
					"presentation_rect" : [ 495.75, 188.427277, 0.0, 0.0 ],
					"style" : "",
					"text" : "Velocity control",
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
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 51.75, 241.427277, 141.0, 37.0 ],
					"presentation_rect" : [ 17.75, 328.427277, 0.0, 0.0 ],
					"style" : "",
					"text" : "Select a pitch for the pad",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 0,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-5",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 389.5, 526.427246, 179.0, 66.0 ],
					"style" : "",
					"text" : "Select the duration of the perc or scale between velocity to perc duration",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-9",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 551.75, 399.427277, 137.0, 24.0 ],
					"style" : "",
					"text" : "Pitch transposition",
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
					"name" : "roland-spd-sx.maxpat",
					"numinlets" : 1,
					"numoutlets" : 1,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "" ],
					"patching_rect" : [ 146.0, 3.427277, 475.0, 569.0 ],
					"varname" : "roland-spd-sx",
					"viewvisibility" : 1
				}

			}
 ],
		"lines" : [  ],
		"parameters" : 		{
			"obj-10::obj-26" : [ "duration", "dur", 0 ],
			"obj-10::obj-18" : [ "transposition", "transpo", 0 ]
		}
,
		"dependency_cache" : [ 			{
				"name" : "roland-spd-sx.maxpat",
				"bootpath" : "~/ownCloud/macShare/lutherie/HCI/roland",
				"patcherrelativepath" : ".",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "roland-spd-sx.jpg",
				"bootpath" : "~/ownCloud/macShare/lutherie/HCI/roland",
				"patcherrelativepath" : ".",
				"type" : "JPEG",
				"implicit" : 1
			}
, 			{
				"name" : "selInput.maxpat",
				"bootpath" : "~/ownCloud/macShare/lutherie/tools",
				"patcherrelativepath" : "../../tools",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "selOutput.maxpat",
				"bootpath" : "~/ownCloud/macShare/lutherie/tools",
				"patcherrelativepath" : "../../tools",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "pad.maxpat",
				"bootpath" : "~/ownCloud/macShare/lutherie/HCI/roland",
				"patcherrelativepath" : ".",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "vel2dur.maxpat",
				"bootpath" : "~/ownCloud/macShare/lutherie/tools",
				"patcherrelativepath" : "../../tools",
				"type" : "JSON",
				"implicit" : 1
			}
 ],
		"autosave" : 0
	}

}
