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
		"rect" : [ 623.0, 79.0, 465.0, 788.0 ],
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
					"id" : "obj-16",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 307.0, 478.0, 43.0, 22.0 ],
					"style" : "",
					"text" : "pack"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-18",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "" ],
					"patching_rect" : [ 307.0, 519.932373, 58.0, 22.0 ],
					"style" : "",
					"text" : "route 7 1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-19",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "int", "int" ],
					"patching_rect" : [ 307.0, 441.0, 43.0, 22.0 ],
					"style" : "",
					"text" : "swap"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-24",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "int", "int", "int" ],
					"patching_rect" : [ 307.0, 404.0, 67.0, 22.0 ],
					"style" : "",
					"text" : "unpack i i i"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-11",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 16.5, 573.0, 96.0, 22.0 ],
					"style" : "",
					"text" : "midiNoteFormat"
				}

			}
, 			{
				"box" : 				{
					"comment" : "",
					"id" : "obj-76",
					"index" : 0,
					"maxclass" : "inlet",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 16.5, 356.0, 30.0, 30.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-7",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1133.0, 537.0, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 230.0, 62.864746, 44.0, 47.0 ],
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
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-12",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1133.0, 604.0, 253.0, 19.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/0x00/portamento $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-55",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1133.0, 491.5, 83.0, 22.0 ],
					"style" : "",
					"text" : "r #1-porta"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-210",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 499.0, 2142.5, 90.0, 22.0 ],
					"style" : "",
					"text" : "r #1-osc3tune"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-211",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 297.0, 2129.5, 90.0, 22.0 ],
					"style" : "",
					"text" : "r #1-osc3form"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-196",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 957.0, 2271.0, 275.0, 19.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/osc3/lfo_freq/lfo2 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-197",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 957.0, 2167.432373, 93.0, 22.0 ],
					"style" : "",
					"text" : "r #1-osc3LFO2"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-198",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 817.0, 2209.864746, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 147.0, 274.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "osc3LFO1",
							"parameter_shortname" : "LFO1",
							"parameter_type" : 0,
							"parameter_mmax" : 500.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "osc3LFO1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-199",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 817.0, 2302.0, 275.0, 19.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/osc3/lfo_freq/lfo1 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-200",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 817.0, 2167.432373, 93.0, 22.0 ],
					"style" : "",
					"text" : "r #1-osc3LFO1"
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
					"patching_rect" : [ 499.0, 2186.932373, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 97.0, 274.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "osc3tune",
							"parameter_shortname" : "tune3",
							"parameter_type" : 0,
							"parameter_mmin" : -12.0,
							"parameter_mmax" : 12.0,
							"parameter_unitstyle" : 7
						}

					}
,
					"varname" : "osc3tune"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-202",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 499.0, 2284.0, 282.0, 19.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/osc3/lfo_freq/tuning_wav $1"
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
					"patching_rect" : [ 297.0, 2173.932373, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 51.0, 274.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "osc3form",
							"parameter_shortname" : "form3",
							"parameter_type" : 0,
							"parameter_mmax" : 4.0,
							"parameter_unitstyle" : 0
						}

					}
,
					"varname" : "osc3form"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-204",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 297.0, 2243.0, 235.0, 29.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/osc3/form_wav $1"
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
					"patching_rect" : [ 197.0, 2214.932373, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 230.0, 274.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "osc3amp",
							"parameter_shortname" : "amp3",
							"parameter_type" : 0,
							"parameter_mmax" : 1.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "osc3amp"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-206",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 197.0, 2284.0, 261.0, 19.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/osc3/amp_wav $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-207",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 197.0, 2171.5, 83.0, 22.0 ],
					"style" : "",
					"text" : "r #1-osc3amp"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.702269, 0.811747, 0.303388, 1.0 ],
					"id" : "obj-208",
					"linecount" : 2,
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 737.0, 2387.0, 116.0, 35.0 ],
					"style" : "",
					"text" : "s #1-wavesElectricKR"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-209",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 134.5, 2232.932373, 43.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 6.0, 287.5, 47.0, 20.0 ],
					"style" : "",
					"text" : "OSC3"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-178",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 900.0, 1915.864746, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 193.0, 227.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "osc2LFO2",
							"parameter_shortname" : "LFO2",
							"parameter_type" : 0,
							"parameter_mmax" : 500.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "osc2LFO2"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-179",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 900.0, 1977.0, 275.0, 19.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/osc2/lfo_freq/lfo2 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-180",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 900.0, 1873.432373, 93.0, 22.0 ],
					"style" : "",
					"text" : "r #1-osc2LFO2"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-181",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 760.0, 1915.864746, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 147.0, 227.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "osc2LFO1",
							"parameter_shortname" : "LFO1",
							"parameter_type" : 0,
							"parameter_mmax" : 500.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "osc2LFO1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-182",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 760.0, 2008.0, 275.0, 19.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/osc2/lfo_freq/lfo1 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-183",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 760.0, 1873.432373, 93.0, 22.0 ],
					"style" : "",
					"text" : "r #1-osc2LFO1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-184",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 442.0, 1892.932373, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 97.0, 227.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "osc2tune",
							"parameter_shortname" : "tune2",
							"parameter_type" : 0,
							"parameter_mmin" : -12.0,
							"parameter_mmax" : 12.0,
							"parameter_unitstyle" : 7
						}

					}
,
					"varname" : "osc2tune"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-185",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 442.0, 1990.0, 282.0, 19.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/osc2/lfo_freq/tuning_wav $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-186",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 442.0, 1849.5, 90.0, 22.0 ],
					"style" : "",
					"text" : "r #1-osc2tune"
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
					"patching_rect" : [ 240.0, 1879.932373, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 51.0, 227.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "osc2form",
							"parameter_shortname" : "form2",
							"parameter_type" : 0,
							"parameter_mmax" : 4.0,
							"parameter_unitstyle" : 0
						}

					}
,
					"varname" : "osc2form"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-188",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 240.0, 1949.0, 235.0, 29.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/osc2/form_wav $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-189",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 240.0, 1836.5, 90.0, 22.0 ],
					"style" : "",
					"text" : "r #1-osc2form"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-190",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 140.0, 1920.932373, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 230.0, 227.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "osc2amp",
							"parameter_shortname" : "amp2",
							"parameter_type" : 0,
							"parameter_mmax" : 1.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "osc2amp"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-191",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 140.0, 1990.0, 261.0, 19.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/osc2/amp_wav $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-192",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 140.0, 1877.5, 83.0, 22.0 ],
					"style" : "",
					"text" : "r #1-osc2amp"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.702269, 0.811747, 0.303388, 1.0 ],
					"id" : "obj-193",
					"linecount" : 2,
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 737.0, 2089.0, 116.0, 35.0 ],
					"style" : "",
					"text" : "s #1-wavesElectricKR"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-194",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 77.5, 1938.932373, 43.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 6.0, 240.5, 47.0, 20.0 ],
					"style" : "",
					"text" : "OSC2"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-175",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 877.0, 1639.864746, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 193.0, 178.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "osc1LFO2",
							"parameter_shortname" : "LFO2",
							"parameter_type" : 0,
							"parameter_mmax" : 500.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "osc1LFO2"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-176",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 877.0, 1701.0, 275.0, 19.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/osc1/lfo_freq/lfo2 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-177",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 877.0, 1597.432373, 93.0, 22.0 ],
					"style" : "",
					"text" : "r #1-osc1LFO2"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-172",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 737.0, 1639.864746, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 147.0, 178.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "osc1LFO1",
							"parameter_shortname" : "LFO1",
							"parameter_type" : 0,
							"parameter_mmax" : 500.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "osc1LFO1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-173",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 737.0, 1732.0, 275.0, 19.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/osc1/lfo_freq/lfo1 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-174",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 737.0, 1597.432373, 93.0, 22.0 ],
					"style" : "",
					"text" : "r #1-osc1LFO1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-166",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 419.0, 1616.932373, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 97.0, 178.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "osc1tune",
							"parameter_shortname" : "tune1",
							"parameter_type" : 0,
							"parameter_mmin" : -12.0,
							"parameter_mmax" : 12.0,
							"parameter_unitstyle" : 7
						}

					}
,
					"varname" : "osc1tune"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-167",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 419.0, 1714.0, 282.0, 19.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/osc1/lfo_freq/tuning_wav $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-168",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 419.0, 1573.5, 90.0, 22.0 ],
					"style" : "",
					"text" : "r #1-osc1tune"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-163",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 217.0, 1603.932373, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 51.0, 178.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "osc1form",
							"parameter_shortname" : "form1",
							"parameter_type" : 0,
							"parameter_mmax" : 4.0,
							"parameter_unitstyle" : 0
						}

					}
,
					"varname" : "osc1form"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-164",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 217.0, 1673.0, 235.0, 29.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/osc1/form_wav $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-165",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 217.0, 1560.5, 90.0, 22.0 ],
					"style" : "",
					"text" : "r #1-osc1form"
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
					"patching_rect" : [ 117.0, 1644.932373, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 230.0, 178.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "osc1amp",
							"parameter_shortname" : "amp1",
							"parameter_type" : 0,
							"parameter_mmax" : 1.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "osc1amp"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-161",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 117.0, 1714.0, 261.0, 19.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/osc1/amp_wav $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-162",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 117.0, 1601.5, 83.0, 22.0 ],
					"style" : "",
					"text" : "r #1-osc1amp"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.702269, 0.811747, 0.303388, 1.0 ],
					"id" : "obj-159",
					"linecount" : 2,
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 737.0, 1826.0, 116.0, 35.0 ],
					"style" : "",
					"text" : "s #1-wavesElectricKR"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-158",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 54.5, 1662.932373, 43.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 6.0, 191.5, 47.0, 20.0 ],
					"style" : "",
					"text" : "OSC1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-157",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1270.0, 246.364746, 56.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 0.5, 17.364746, 56.0, 20.0 ],
					"style" : "",
					"text" : "Tremolo"
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
					"patching_rect" : [ 1214.0, 232.864746, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 97.0, 3.864746, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "tremLFO2",
							"parameter_shortname" : "trem2",
							"parameter_type" : 0,
							"parameter_mmax" : 1.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "tremLFO2"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-155",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1214.0, 335.932373, 235.0, 29.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/FX/tremolo/lfo2 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-156",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1214.0, 189.432373, 94.0, 22.0 ],
					"style" : "",
					"text" : "r #1-tremLFO2"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-151",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1098.0, 232.864746, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 51.0, 3.864746, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "tremLFO1",
							"parameter_shortname" : "trem1",
							"parameter_type" : 0,
							"parameter_mmax" : 1.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "tremLFO1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-152",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1098.0, 301.932373, 235.0, 29.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/FX/tremolo/lfo1 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-153",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1098.0, 189.432373, 94.0, 22.0 ],
					"style" : "",
					"text" : "r #1-tremLFO1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-144",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1522.0, 1289.864746, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 187.5, 445.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "fmLFO2",
							"parameter_shortname" : "fmLFO2",
							"parameter_type" : 0,
							"parameter_mmax" : 1000.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "fmLFO2"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-145",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1522.0, 1403.0, 275.0, 29.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/FX/modulator/lfo_freq/lfo2 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-146",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1522.0, 1246.432373, 93.0, 22.0 ],
					"style" : "",
					"text" : "r #1-fmLFO2"
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
					"patching_rect" : [ 1390.0, 1289.864746, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 141.5, 445.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "fmLFO1",
							"parameter_shortname" : "fmLFO1",
							"parameter_type" : 0,
							"parameter_mmax" : 1000.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "fmLFO1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-148",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1390.0, 1374.0, 275.0, 29.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/FX/modulator/lfo_freq/lfo1 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-149",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1390.0, 1246.432373, 93.0, 22.0 ],
					"style" : "",
					"text" : "r #1-fmLFO1"
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
					"patching_rect" : [ 1112.0, 1324.864746, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 95.5, 445.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "fmIndex",
							"parameter_shortname" : "Index",
							"parameter_type" : 0,
							"parameter_mmax" : 15.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "fmIndex"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-142",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1112.0, 1423.0, 300.0, 19.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/FX/modulator/index_FM $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-143",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1112.0, 1281.432373, 93.0, 22.0 ],
					"style" : "",
					"text" : "r #1-fmIndex"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-138",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 983.0, 1319.864746, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 49.5, 445.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "fmCoef",
							"parameter_shortname" : "fmCoef",
							"parameter_type" : 0,
							"parameter_mmin" : 0.01,
							"parameter_mmax" : 5.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "fmCoef"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-139",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 983.0, 1398.0, 300.0, 29.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/FX/modulator/lfo_freq/coef_FM $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-140",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 983.0, 1276.432373, 93.0, 22.0 ],
					"style" : "",
					"text" : "r #1-fmCoef"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-112",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 832.0, 1345.0, 54.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 233.5, 494.0, 49.0, 20.0 ],
					"style" : "",
					"text" : "InvEnv",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-113",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 68.5, 1372.432373, 43.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 8.5, 458.5, 31.0, 20.0 ],
					"style" : "",
					"text" : "FM"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-114",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 790.0, 1276.432373, 85.0, 22.0 ],
					"style" : "",
					"text" : "r #1-fmInvEnv"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-115",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 790.0, 1464.0, 281.0, 29.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/FX/modulator/invEnv_LPF $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-116",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 790.0, 1345.0, 24.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 242.5, 517.0, 24.0, 24.0 ],
					"style" : "",
					"varname" : "fmInvEnv"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-117",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 657.0, 1319.864746, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 187.5, 494.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "fmEnvDepth",
							"parameter_shortname" : "envDepth",
							"parameter_type" : 0,
							"parameter_mmax" : 1.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "fmEnvDepth"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-118",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 657.0, 1428.0, 281.0, 19.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/FX/modulator/envDepth $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-119",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 657.0, 1276.432373, 100.0, 22.0 ],
					"style" : "",
					"text" : "r #1-fmEnvDepth"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.702269, 0.811747, 0.303388, 1.0 ],
					"id" : "obj-120",
					"linecount" : 2,
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 877.0, 1535.0, 116.0, 35.0 ],
					"style" : "",
					"text" : "s #1-wavesElectricKR"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-122",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 528.0, 1319.864746, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 141.5, 494.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "fmR",
							"parameter_shortname" : "R",
							"parameter_type" : 0,
							"parameter_mmax" : 10.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "fmR"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-126",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 528.0, 1388.932373, 269.0, 19.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/FX/modulator/env/R $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-127",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 528.0, 1276.432373, 83.0, 22.0 ],
					"style" : "",
					"text" : "r #1-fmEnvR"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-128",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 384.0, 1319.864746, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 92.5, 494.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "fmS",
							"parameter_shortname" : "S",
							"parameter_type" : 0,
							"parameter_mmax" : 1.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "fmS"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-129",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 384.0, 1428.0, 263.0, 19.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/FX/modulator/env/S $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-131",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 384.0, 1276.432373, 83.0, 22.0 ],
					"style" : "",
					"text" : "r #1-fmEnvS"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-132",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 270.0, 1319.864746, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 49.5, 494.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "fmD",
							"parameter_shortname" : "D",
							"parameter_type" : 0,
							"parameter_mmax" : 15.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "fmD"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-133",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 270.0, 1388.932373, 256.0, 29.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/FX/modulator/env/D $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-134",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 270.0, 1276.432373, 83.0, 22.0 ],
					"style" : "",
					"text" : "r #1-fmEnvD"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-135",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 165.5, 1393.932373, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 8.5, 494.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "fmA",
							"parameter_shortname" : "A",
							"parameter_type" : 0,
							"parameter_mmax" : 15.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "fmA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-136",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 165.5, 1463.0, 261.0, 19.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/FX/modulator/env/A $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-137",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 165.5, 1350.5, 83.0, 22.0 ],
					"style" : "",
					"text" : "r #1-fmEnvA"
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
					"patching_rect" : [ 1376.0, 1013.864746, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 184.0, 334.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "lpResonance",
							"parameter_shortname" : "reson",
							"parameter_type" : 0,
							"parameter_mmax" : 0.99,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "lpResonance"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-107",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1376.0, 1088.5, 247.0, 29.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/FX/filter/resonance $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-110",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1376.0, 970.432373, 107.0, 22.0 ],
					"style" : "",
					"text" : "r #1-lpResonance"
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
					"patching_rect" : [ 1265.0, 1013.864746, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 138.0, 334.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "lpLFO2",
							"parameter_shortname" : "lpLFO2",
							"parameter_type" : 0,
							"parameter_mmax" : 1000.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "lpLFO2"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-101",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1265.0, 1127.0, 275.0, 19.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/FX/filter/lfo_cutOff/lfo2 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-103",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1265.0, 970.432373, 93.0, 22.0 ],
					"style" : "",
					"text" : "r #1-lpLFO2"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-94",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1133.0, 1013.864746, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 97.0, 334.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "lpLFO1",
							"parameter_shortname" : "lpLFO1",
							"parameter_type" : 0,
							"parameter_mmax" : 1000.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "lpLFO1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-95",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1133.0, 1158.0, 275.0, 19.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/FX/filter/lfo_cutOff/lfo1 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-97",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1133.0, 970.432373, 93.0, 22.0 ],
					"style" : "",
					"text" : "r #1-lpLFO1"
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
					"patching_rect" : [ 998.0, 1013.864746, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 51.0, 334.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "lpCutCoef",
							"parameter_shortname" : "cutCoef",
							"parameter_type" : 0,
							"parameter_mmin" : 0.01,
							"parameter_mmax" : 5.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "lpCutCoef"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-92",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 998.0, 1092.0, 300.0, 19.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/FX/filter/lfo_cutOff/coef_cutOff $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-93",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 998.0, 970.432373, 93.0, 22.0 ],
					"style" : "",
					"text" : "r #1-lpCutCoef"
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
					"patching_rect" : [ 880.0, 1013.864746, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 230.0, 334.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "lpDepth",
							"parameter_shortname" : "depth",
							"parameter_type" : 0,
							"parameter_mmax" : 1.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "lpDepth"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-88",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 880.0, 1122.0, 258.0, 29.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/FX/filter/dry/wet_LPF $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-89",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 880.0, 970.432373, 83.0, 22.0 ],
					"style" : "",
					"text" : "r #1-lpDepth"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-86",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 802.0, 1039.0, 54.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 230.0, 383.0, 49.0, 20.0 ],
					"style" : "",
					"text" : "InvEnv",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-85",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 450.0, 285.432373, 49.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 10.0, 76.364746, 37.0, 20.0 ],
					"style" : "",
					"text" : "Env"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-84",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 349.5, 629.932373, 45.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 5.0, 130.432373, 35.0, 20.0 ],
					"style" : "",
					"text" : "LFO"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-83",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 38.5, 1066.432373, 43.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 8.5, 347.5, 36.0, 20.0 ],
					"style" : "",
					"text" : "Filter"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-81",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 760.0, 970.432373, 85.0, 22.0 ],
					"style" : "",
					"text" : "r #1-lpInvEnv"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-79",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 760.0, 1158.0, 254.0, 29.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/FX/filter/invEnv_LPF $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-78",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 760.0, 1039.0, 24.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 242.5, 406.0, 24.0, 24.0 ],
					"style" : "",
					"varname" : "lpInvEnv"
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
					"patching_rect" : [ 627.0, 1013.864746, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 187.5, 383.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "lpEnvDepth",
							"parameter_shortname" : "envDepth",
							"parameter_type" : 0,
							"parameter_mmax" : 1.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "lpEnvDepth"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-74",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 627.0, 1122.0, 245.0, 29.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/FX/filter/envDepth $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-75",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 627.0, 970.432373, 100.0, 22.0 ],
					"style" : "",
					"text" : "r #1-lpEnvDepth"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.702269, 0.811747, 0.303388, 1.0 ],
					"id" : "obj-72",
					"linecount" : 2,
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 847.0, 1229.0, 116.0, 35.0 ],
					"style" : "",
					"text" : "s #1-wavesElectricKR"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-60",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 472.0, 1013.864746, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 141.5, 383.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "lpR",
							"parameter_shortname" : "R",
							"parameter_type" : 0,
							"parameter_mmax" : 10.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "lpR"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-61",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 472.0, 1082.932373, 235.0, 29.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/FX/filter/env/R $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-62",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 472.0, 970.432373, 83.0, 22.0 ],
					"style" : "",
					"text" : "r #1-lpEnvR"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-63",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 354.0, 1013.864746, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 95.5, 383.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "lpS",
							"parameter_shortname" : "S",
							"parameter_type" : 0,
							"parameter_mmax" : 1.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "lpS"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-64",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 354.0, 1122.0, 231.0, 29.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/FX/filter/env/S $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-65",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 354.0, 970.432373, 83.0, 22.0 ],
					"style" : "",
					"text" : "r #1-lpEnvS"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-66",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 240.0, 1013.864746, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 49.5, 383.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "lpD",
							"parameter_shortname" : "D",
							"parameter_type" : 0,
							"parameter_mmax" : 15.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "lpD"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-67",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 240.0, 1080.932373, 235.0, 29.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/FX/filter/env/D $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-68",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 240.0, 970.432373, 83.0, 22.0 ],
					"style" : "",
					"text" : "r #1-lpEnvD"
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
					"patching_rect" : [ 117.0, 1052.932373, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 8.5, 383.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "lpA",
							"parameter_shortname" : "A",
							"parameter_type" : 0,
							"parameter_mmax" : 15.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "lpA"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-70",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 117.0, 1122.0, 229.0, 29.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/FX/filter/env/A $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-71",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 117.0, 1009.5, 83.0, 22.0 ],
					"style" : "",
					"text" : "r #1-lpEnvA"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-57",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 849.0, 616.432373, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 230.0, 116.932373, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "lfo2rate",
							"parameter_shortname" : "rate2",
							"parameter_type" : 0,
							"parameter_mmax" : 10.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "lfo2rate"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-58",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 849.0, 716.5, 235.0, 29.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/0x00/rate_lfo2 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-59",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 849.0, 573.0, 90.0, 22.0 ],
					"style" : "",
					"text" : "r #1-lfo2rate"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-56",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 699.0, 616.432373, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 97.0, 116.932373, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "lfo1rate",
							"parameter_shortname" : "rate1",
							"parameter_type" : 0,
							"parameter_mmax" : 10.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "lfo1rate"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-53",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 699.0, 685.5, 235.0, 29.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/0x00/rate_lfo1 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-54",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 699.0, 573.0, 90.0, 22.0 ],
					"style" : "",
					"text" : "r #1-lfo1rate"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-50",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 570.0, 616.432373, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 189.0, 116.932373, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "lfo2form",
							"parameter_shortname" : "form2",
							"parameter_type" : 0,
							"parameter_mmax" : 3.0,
							"parameter_unitstyle" : 0
						}

					}
,
					"varname" : "lfo2form"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-51",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 570.0, 716.5, 235.0, 29.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/0x00/lfo2/form $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-52",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 570.0, 573.0, 90.0, 22.0 ],
					"style" : "",
					"text" : "r #1-lfo2form"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-43",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 416.0, 616.432373, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 51.0, 116.932373, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "lfo1form",
							"parameter_shortname" : "form1",
							"parameter_type" : 0,
							"parameter_mmax" : 3.0,
							"parameter_unitstyle" : 0
						}

					}
,
					"varname" : "lfo1form"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-46",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 416.0, 685.5, 235.0, 29.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/0x00/lfo1/form $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-49",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 416.0, 573.0, 90.0, 22.0 ],
					"style" : "",
					"text" : "r #1-lfo1form"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.702269, 0.811747, 0.303388, 1.0 ],
					"id" : "obj-42",
					"linecount" : 2,
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 623.0, 778.0, 116.0, 35.0 ],
					"style" : "",
					"text" : "s #1-wavesElectricKR"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-38",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 861.0, 232.864746, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 189.0, 62.864746, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "R",
							"parameter_shortname" : "R",
							"parameter_type" : 0,
							"parameter_mmax" : 10.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "R"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-40",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 861.0, 301.932373, 218.0, 29.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/0x00/env/R $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-41",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 861.0, 189.432373, 83.0, 22.0 ],
					"style" : "",
					"text" : "r #1-envR"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-34",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 743.0, 232.864746, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 143.0, 62.864746, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "S",
							"parameter_shortname" : "S",
							"parameter_type" : 0,
							"parameter_mmax" : 1.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "S"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-35",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 743.0, 341.0, 218.0, 29.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/0x00/env/S $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-37",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 743.0, 189.432373, 83.0, 22.0 ],
					"style" : "",
					"text" : "r #1-envS"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-31",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 629.0, 232.864746, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 97.0, 62.864746, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "D",
							"parameter_shortname" : "D",
							"parameter_type" : 0,
							"parameter_mmax" : 15.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "D"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-32",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 629.0, 299.932373, 218.0, 29.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/0x00/env/D $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-33",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 629.0, 189.432373, 83.0, 22.0 ],
					"style" : "",
					"text" : "r #1-envD"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-15",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 506.0, 271.932373, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 51.0, 62.864746, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "A",
							"parameter_shortname" : "A",
							"parameter_type" : 0,
							"parameter_mmax" : 15.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "A"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-20",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 506.0, 341.0, 218.0, 29.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/0x00/env/A $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-22",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 506.0, 228.5, 83.0, 22.0 ],
					"style" : "",
					"text" : "r #1-envA"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-13",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 988.5, 592.932373, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 143.0, 116.932373, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "bpm",
							"parameter_shortname" : "bpm",
							"parameter_type" : 0,
							"parameter_mmin" : 1.0,
							"parameter_mmax" : 1000.0,
							"parameter_unitstyle" : 0
						}

					}
,
					"varname" : "bpm"
				}

			}
, 			{
				"box" : 				{
					"comment" : "",
					"id" : "obj-5",
					"index" : 0,
					"maxclass" : "outlet",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 23.0, 302.5, 30.0, 30.0 ],
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
					"patching_rect" : [ 628.0, 39.5, 70.0, 22.0 ],
					"restore" : 					{
						"A" : [ 0.05 ],
						"D" : [ 0.05 ],
						"R" : [ 0.1 ],
						"S" : [ 0.75 ],
						"bpm" : [ 120.0 ],
						"fmA" : [ 0.0 ],
						"fmCoef" : [ 2.0 ],
						"fmD" : [ 0.0 ],
						"fmEnvDepth" : [ 0.0 ],
						"fmIndex" : [ 0.0 ],
						"fmInvEnv" : [ 0 ],
						"fmLFO1" : [ 0.0 ],
						"fmLFO2" : [ 0.0 ],
						"fmR" : [ 0.0 ],
						"fmS" : [ 0.0 ],
						"lfo1form" : [ 0.0 ],
						"lfo1rate" : [ 1.0 ],
						"lfo2form" : [ 0.047244 ],
						"lfo2rate" : [ 1.0 ],
						"live.gain~" : [ -6.0 ],
						"lpA" : [ 0.0 ],
						"lpCutCoef" : [ 2.0 ],
						"lpD" : [ 0.0 ],
						"lpDepth" : [ 0.0 ],
						"lpEnvDepth" : [ 0.0 ],
						"lpInvEnv" : [ 0 ],
						"lpLFO1" : [ 0.0 ],
						"lpLFO2" : [ 0.0 ],
						"lpR" : [ 0.0 ],
						"lpResonance" : [ 0.0 ],
						"lpS" : [ 0.0 ],
						"osc1LFO1" : [ 0.0 ],
						"osc1LFO2" : [ 0.0 ],
						"osc1amp" : [ 0.15 ],
						"osc1form" : [ 0.0 ],
						"osc1tune" : [ 0.0 ],
						"osc2LFO1" : [ 0.0 ],
						"osc2LFO2" : [ 0.0 ],
						"osc2amp" : [ 0.0 ],
						"osc2form" : [ 0.0 ],
						"osc2tune" : [ 0.0 ],
						"osc3LFO1" : [ 0.0 ],
						"osc3LFO2" : [ 0.0 ],
						"osc3amp" : [ 0.0 ],
						"osc3form" : [ 0.0 ],
						"osc3tune" : [ 0.0 ],
						"portamento" : [ 0.0 ],
						"tremLFO1" : [ 0.0 ],
						"tremLFO2" : [ 0.0 ]
					}
,
					"style" : "",
					"text" : "autopattr",
					"varname" : "u265004809"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-39",
					"maxclass" : "newobj",
					"numinlets" : 6,
					"numoutlets" : 6,
					"outlettype" : [ "", "", "", "", "", "" ],
					"patching_rect" : [ 16.5, 507.5, 221.0, 22.0 ],
					"style" : "",
					"text" : "route midiNote bend tempo stop midiCtl"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-21",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 138.780212, 9.0, 89.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 155.5, 635.0, 80.0, 20.0 ],
					"style" : "",
					"text" : "v. 20180914",
					"textjustification" : 2
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-2",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 15.0, 9.0, 105.469788, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 8.5, 635.0, 101.0, 20.0 ],
					"style" : "",
					"text" : "Sébastien Clara"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.702269, 0.811747, 0.303388, 1.0 ],
					"id" : "obj-26",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 16.5, 651.5, 130.5, 22.0 ],
					"style" : "",
					"text" : "s #1-wavesElectricKR"
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
					"id" : "obj-23",
					"lockeddragscroll" : 0,
					"maxclass" : "bpatcher",
					"name" : "selInput.maxpat",
					"numinlets" : 1,
					"numoutlets" : 2,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 16.5, 404.0, 224.0, 82.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 8.5, 556.0, 224.0, 81.0 ],
					"varname" : "selInput",
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-9",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "" ],
					"patching_rect" : [ 172.5, 595.0, 68.0, 22.0 ],
					"style" : "",
					"text" : "select 27"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-4",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 4,
					"outlettype" : [ "int", "int", "int", "int" ],
					"patching_rect" : [ 172.5, 559.0, 68.0, 22.0 ],
					"style" : "",
					"text" : "key"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontsize" : 10.0,
					"id" : "obj-10",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 243.530212, 596.0, 27.0, 18.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 173.5, 38.114746, 30.0, 18.0 ],
					"style" : "",
					"text" : "esc",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-25",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 172.5, 629.932373, 45.0, 45.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 249.0, 34.864746, 24.5, 24.5 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-17",
					"maxclass" : "newobj",
					"numinlets" : 6,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 186.030212, 109.0, 104.5, 22.0 ],
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
					"patching_rect" : [ 192.280212, 143.0, 100.0, 22.0 ],
					"style" : "",
					"text" : "loadmess -6"
				}

			}
, 			{
				"box" : 				{
					"channels" : 1,
					"id" : "obj-8",
					"maxclass" : "live.gain~",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "signal", "", "float", "list" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 23.0, 175.864746, 53.0, 108.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 242.5, 551.5, 40.0, 86.0 ],
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
					"fontface" : 1,
					"fontsize" : 20.0,
					"id" : "obj-130",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 446.5, 36.0, 167.0, 29.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 151.0, 3.864746, 141.0, 29.0 ],
					"style" : "",
					"text" : "wavesElectric",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-125",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 16.5, 745.5, 60.0, 22.0 ],
					"style" : "",
					"text" : "loadbang"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 9.0,
					"id" : "obj-109",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 988.5, 662.0, 218.0, 19.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/0x00/bpm $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-108",
					"linecount" : 17,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 16.5, 778.0, 112.0, 236.0 ],
					"style" : "",
					"text" : ";\n#1-osc1amp 0.15;\n#1-osc2amp 0;\n#1-osc3amp 0;\n#1-osc1tune 0;\r#1-osc2tune 0;\r#1-osc3tune 0;\n#1-porta 0;\r#1-bmp 120;\n#1-lfo1rate 1;\n#1-lfo2rate 1;\n#1-envA 0.05;\n#1-envD 0.05;\n#1-envS 0.75;\n#1-envR 0.1;\n#1-lpCutCoef 2;\n#1-fmCoef 2;"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-106",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 988.5, 549.5, 83.0, 22.0 ],
					"style" : "",
					"text" : "r #1-bmp"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-102",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 212.0, 288.5, 68.0, 22.0 ],
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
					"patching_rect" : [ 212.0, 247.5, 125.0, 22.0 ],
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
					"patching_rect" : [ 212.0, 323.5, 221.0, 19.0 ],
					"style" : "",
					"text" : "/Polyphonic/Voices/wavesElectric/0x00/0x00/bend $1"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.702269, 0.811747, 0.303388, 1.0 ],
					"id" : "obj-96",
					"linecount" : 2,
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 752.0, 459.0, 116.0, 35.0 ],
					"style" : "",
					"text" : "s #1-wavesElectricKR"
				}

			}
, 			{
				"box" : 				{
					"color" : [ 0.702269, 0.811747, 0.303388, 1.0 ],
					"id" : "obj-80",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 23.0, 70.0, 132.0, 22.0 ],
					"style" : "",
					"text" : "r #1-wavesElectricKR"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-3",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 23.0, 36.0, 79.0, 22.0 ],
					"style" : "",
					"text" : "polyphony 8"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-1",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "signal" ],
					"patching_rect" : [ 23.0, 109.0, 101.0, 22.0 ],
					"style" : "",
					"text" : "wavesElectric~"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 1,
					"fontsize" : 16.0,
					"id" : "obj-6",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 224.5, 644.932373, 75.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 193.0, 35.114746, 60.0, 24.0 ],
					"style" : "",
					"text" : "Panic",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"background" : 1,
					"id" : "obj-195",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 957.0, 2209.864746, 44.0, 47.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 193.0, 274.0, 44.0, 47.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "osc3LFO2",
							"parameter_shortname" : "LFO2",
							"parameter_type" : 0,
							"parameter_mmax" : 500.0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "osc3LFO2"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-8", 0 ],
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-101", 0 ],
					"source" : [ "obj-100", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-72", 0 ],
					"source" : [ "obj-101", 0 ]
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
					"destination" : [ "obj-100", 0 ],
					"source" : [ "obj-103", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-107", 0 ],
					"source" : [ "obj-105", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 0 ],
					"source" : [ "obj-106", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-72", 0 ],
					"source" : [ "obj-107", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-42", 0 ],
					"source" : [ "obj-109", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-26", 0 ],
					"source" : [ "obj-11", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-105", 0 ],
					"source" : [ "obj-110", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-116", 0 ],
					"source" : [ "obj-114", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-120", 0 ],
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
					"destination" : [ "obj-118", 0 ],
					"source" : [ "obj-117", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-120", 0 ],
					"source" : [ "obj-118", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-117", 0 ],
					"source" : [ "obj-119", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-42", 0 ],
					"source" : [ "obj-12", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-126", 0 ],
					"source" : [ "obj-122", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-108", 0 ],
					"source" : [ "obj-125", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-120", 0 ],
					"source" : [ "obj-126", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-122", 0 ],
					"source" : [ "obj-127", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-129", 0 ],
					"source" : [ "obj-128", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-120", 0 ],
					"source" : [ "obj-129", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-109", 0 ],
					"source" : [ "obj-13", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-128", 0 ],
					"source" : [ "obj-131", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-133", 0 ],
					"source" : [ "obj-132", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-120", 0 ],
					"source" : [ "obj-133", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-132", 0 ],
					"source" : [ "obj-134", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-136", 0 ],
					"source" : [ "obj-135", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-120", 0 ],
					"source" : [ "obj-136", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-135", 0 ],
					"source" : [ "obj-137", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-139", 0 ],
					"source" : [ "obj-138", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-120", 0 ],
					"source" : [ "obj-139", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-8", 0 ],
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-138", 0 ],
					"source" : [ "obj-140", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-142", 0 ],
					"source" : [ "obj-141", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-120", 0 ],
					"source" : [ "obj-142", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-141", 0 ],
					"source" : [ "obj-143", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-145", 0 ],
					"source" : [ "obj-144", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-120", 0 ],
					"source" : [ "obj-145", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-144", 0 ],
					"source" : [ "obj-146", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-148", 0 ],
					"source" : [ "obj-147", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-120", 0 ],
					"source" : [ "obj-148", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-147", 0 ],
					"source" : [ "obj-149", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-20", 0 ],
					"source" : [ "obj-15", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-152", 0 ],
					"source" : [ "obj-151", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-96", 0 ],
					"source" : [ "obj-152", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-151", 0 ],
					"source" : [ "obj-153", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-155", 0 ],
					"source" : [ "obj-154", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-96", 0 ],
					"source" : [ "obj-155", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-154", 0 ],
					"source" : [ "obj-156", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-18", 0 ],
					"source" : [ "obj-16", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-161", 0 ],
					"source" : [ "obj-160", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-159", 0 ],
					"source" : [ "obj-161", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-160", 0 ],
					"source" : [ "obj-162", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-164", 0 ],
					"source" : [ "obj-163", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-159", 0 ],
					"source" : [ "obj-164", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-163", 0 ],
					"source" : [ "obj-165", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-167", 0 ],
					"source" : [ "obj-166", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-159", 0 ],
					"source" : [ "obj-167", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-166", 0 ],
					"source" : [ "obj-168", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-8", 0 ],
					"source" : [ "obj-17", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-173", 0 ],
					"source" : [ "obj-172", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-159", 0 ],
					"source" : [ "obj-173", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-172", 0 ],
					"source" : [ "obj-174", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-176", 0 ],
					"source" : [ "obj-175", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-159", 0 ],
					"source" : [ "obj-176", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-175", 0 ],
					"source" : [ "obj-177", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-179", 0 ],
					"source" : [ "obj-178", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-193", 0 ],
					"source" : [ "obj-179", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-17", 0 ],
					"source" : [ "obj-18", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-178", 0 ],
					"source" : [ "obj-180", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-182", 0 ],
					"source" : [ "obj-181", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-193", 0 ],
					"source" : [ "obj-182", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-181", 0 ],
					"source" : [ "obj-183", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-185", 0 ],
					"source" : [ "obj-184", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-193", 0 ],
					"source" : [ "obj-185", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-184", 0 ],
					"source" : [ "obj-186", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-188", 0 ],
					"source" : [ "obj-187", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-193", 0 ],
					"source" : [ "obj-188", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-187", 0 ],
					"source" : [ "obj-189", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 1 ],
					"source" : [ "obj-19", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 0 ],
					"source" : [ "obj-19", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-191", 0 ],
					"source" : [ "obj-190", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-193", 0 ],
					"source" : [ "obj-191", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-190", 0 ],
					"source" : [ "obj-192", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-196", 0 ],
					"source" : [ "obj-195", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-208", 0 ],
					"source" : [ "obj-196", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-195", 0 ],
					"source" : [ "obj-197", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-199", 0 ],
					"source" : [ "obj-198", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-208", 0 ],
					"source" : [ "obj-199", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-96", 0 ],
					"source" : [ "obj-20", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-198", 0 ],
					"source" : [ "obj-200", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-202", 0 ],
					"source" : [ "obj-201", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-208", 0 ],
					"source" : [ "obj-202", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-204", 0 ],
					"source" : [ "obj-203", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-208", 0 ],
					"source" : [ "obj-204", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-206", 0 ],
					"source" : [ "obj-205", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-208", 0 ],
					"source" : [ "obj-206", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-205", 0 ],
					"source" : [ "obj-207", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-201", 0 ],
					"source" : [ "obj-210", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-203", 0 ],
					"source" : [ "obj-211", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 0 ],
					"source" : [ "obj-22", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-39", 0 ],
					"source" : [ "obj-23", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-19", 1 ],
					"source" : [ "obj-24", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-19", 0 ],
					"source" : [ "obj-24", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 1 ],
					"source" : [ "obj-25", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-32", 0 ],
					"source" : [ "obj-31", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-96", 0 ],
					"source" : [ "obj-32", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-31", 0 ],
					"source" : [ "obj-33", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 0 ],
					"source" : [ "obj-34", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-96", 0 ],
					"source" : [ "obj-35", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-34", 0 ],
					"source" : [ "obj-37", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-40", 0 ],
					"source" : [ "obj-38", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 1 ],
					"source" : [ "obj-39", 3 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 0 ],
					"source" : [ "obj-39", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 0 ],
					"source" : [ "obj-39", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 0 ],
					"source" : [ "obj-39", 4 ]
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
					"destination" : [ "obj-9", 0 ],
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-96", 0 ],
					"source" : [ "obj-40", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-38", 0 ],
					"source" : [ "obj-41", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-46", 0 ],
					"source" : [ "obj-43", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-42", 0 ],
					"source" : [ "obj-46", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-43", 0 ],
					"source" : [ "obj-49", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-51", 0 ],
					"source" : [ "obj-50", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-42", 0 ],
					"source" : [ "obj-51", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-50", 0 ],
					"source" : [ "obj-52", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-42", 0 ],
					"source" : [ "obj-53", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-56", 0 ],
					"source" : [ "obj-54", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 0 ],
					"source" : [ "obj-55", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-53", 0 ],
					"source" : [ "obj-56", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-58", 0 ],
					"source" : [ "obj-57", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-42", 0 ],
					"source" : [ "obj-58", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-57", 0 ],
					"source" : [ "obj-59", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-61", 0 ],
					"source" : [ "obj-60", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-72", 0 ],
					"source" : [ "obj-61", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-60", 0 ],
					"source" : [ "obj-62", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-64", 0 ],
					"source" : [ "obj-63", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-72", 0 ],
					"source" : [ "obj-64", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-63", 0 ],
					"source" : [ "obj-65", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-67", 0 ],
					"source" : [ "obj-66", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-72", 0 ],
					"source" : [ "obj-67", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-66", 0 ],
					"source" : [ "obj-68", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-70", 0 ],
					"source" : [ "obj-69", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-12", 0 ],
					"source" : [ "obj-7", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-72", 0 ],
					"source" : [ "obj-70", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-69", 0 ],
					"source" : [ "obj-71", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-74", 0 ],
					"source" : [ "obj-73", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-72", 0 ],
					"source" : [ "obj-74", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-73", 0 ],
					"source" : [ "obj-75", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"source" : [ "obj-76", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-79", 0 ],
					"source" : [ "obj-78", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-72", 0 ],
					"source" : [ "obj-79", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-5", 0 ],
					"source" : [ "obj-8", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-80", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-78", 0 ],
					"source" : [ "obj-81", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-88", 0 ],
					"source" : [ "obj-87", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-72", 0 ],
					"source" : [ "obj-88", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-87", 0 ],
					"source" : [ "obj-89", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"source" : [ "obj-9", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-92", 0 ],
					"source" : [ "obj-91", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-72", 0 ],
					"source" : [ "obj-92", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-91", 0 ],
					"source" : [ "obj-93", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-95", 0 ],
					"source" : [ "obj-94", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-72", 0 ],
					"source" : [ "obj-95", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-94", 0 ],
					"source" : [ "obj-97", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-96", 0 ],
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
			"obj-94" : [ "lpLFO1", "lpLFO1", 0 ],
			"obj-172" : [ "osc1LFO1", "LFO1", 0 ],
			"obj-181" : [ "osc2LFO1", "LFO1", 0 ],
			"obj-198" : [ "osc3LFO1", "LFO1", 0 ],
			"obj-151" : [ "tremLFO1", "trem1", 0 ],
			"obj-38" : [ "R", "R", 0 ],
			"obj-138" : [ "fmCoef", "fmCoef", 0 ],
			"obj-147" : [ "fmLFO1", "fmLFO1", 0 ],
			"obj-56" : [ "lfo1rate", "rate1", 0 ],
			"obj-66" : [ "lpD", "D", 0 ],
			"obj-100" : [ "lpLFO2", "lpLFO2", 0 ],
			"obj-175" : [ "osc1LFO2", "LFO2", 0 ],
			"obj-178" : [ "osc2LFO2", "LFO2", 0 ],
			"obj-31" : [ "D", "D", 0 ],
			"obj-195" : [ "osc3LFO2", "LFO2", 0 ],
			"obj-154" : [ "tremLFO2", "trem2", 0 ],
			"obj-34" : [ "S", "S", 0 ],
			"obj-132" : [ "fmD", "D", 0 ],
			"obj-144" : [ "fmLFO2", "fmLFO2", 0 ],
			"obj-50" : [ "lfo2form", "form2", 0 ],
			"obj-87" : [ "lpDepth", "depth", 0 ],
			"obj-13" : [ "bpm", "bpm", 0 ],
			"obj-60" : [ "lpR", "R", 0 ],
			"obj-160" : [ "osc1amp", "amp1", 0 ],
			"obj-190" : [ "osc2amp", "amp2", 0 ],
			"obj-205" : [ "osc3amp", "amp3", 0 ],
			"obj-117" : [ "fmEnvDepth", "envDepth", 0 ],
			"obj-122" : [ "fmR", "R", 0 ],
			"obj-57" : [ "lfo2rate", "rate2", 0 ],
			"obj-73" : [ "lpEnvDepth", "envDepth", 0 ],
			"obj-105" : [ "lpResonance", "reson", 0 ],
			"obj-163" : [ "osc1form", "form1", 0 ],
			"obj-15" : [ "A", "A", 0 ],
			"obj-187" : [ "osc2form", "form2", 0 ],
			"obj-203" : [ "osc3form", "form3", 0 ],
			"obj-141" : [ "fmIndex", "Index", 0 ],
			"obj-128" : [ "fmS", "S", 0 ],
			"obj-69" : [ "lpA", "A", 0 ],
			"obj-7" : [ "portamento", "porta", 0 ],
			"obj-63" : [ "lpS", "S", 0 ],
			"obj-166" : [ "osc1tune", "tune1", 0 ],
			"obj-184" : [ "osc2tune", "tune2", 0 ],
			"obj-201" : [ "osc3tune", "tune3", 0 ],
			"obj-135" : [ "fmA", "A", 0 ],
			"obj-43" : [ "lfo1form", "form1", 0 ],
			"obj-91" : [ "lpCutCoef", "cutCoef", 0 ],
			"obj-8" : [ "live.gain~", "Gain", 0 ]
		}
,
		"dependency_cache" : [ 			{
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
				"name" : "wavesElectric~.mxo",
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
