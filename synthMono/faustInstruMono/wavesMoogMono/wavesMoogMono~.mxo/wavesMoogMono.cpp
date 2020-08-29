/* ------------------------------------------------------------
author: "Sébastien Clara"
name: "wavesMoog"
Code generated with Faust 2.6.3 (https://faust.grame.fr)
Compilation options: cpp, -double -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

/************************************************************************

    IMPORTANT NOTE : this file contains two clearly delimited sections :
    the ARCHITECTURE section (in two parts) and the USER section. Each section
    is governed by its own copyright and license. Please check individually
    each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2004-2028 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either version 3
    of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.

    MAX MSP SDK : in order to compile a MaxMSP external with this
    architecture file you will need the official MaxMSP SDK from
    cycling'74. Please check the corresponding license.

 ************************************************************************
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>

#ifdef __APPLE__
#include <Carbon/Carbon.h>
#include <unistd.h>
#endif

#ifdef WIN32
#ifndef NAN
    static const unsigned long __nan[2] = {0xffffffff, 0x7fffffff};
    #define NAN (*(const float *) __nan)
#endif
#endif

#define FAUSTFLOAT double

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __UI_H__
#define __UI_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/*******************************************************************************
 * UI : Faust DSP User Interface
 * User Interface as expected by the buildUserInterface() method of a DSP.
 * This abstract class contains only the method that the Faust compiler can
 * generate to describe a DSP user interface.
 ******************************************************************************/

struct Soundfile;

class UI
{

    public:

        UI() {}

        virtual ~UI() {}

        // -- widget's layouts

        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;

        // -- active widgets

        virtual void addButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) = 0;

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
};

#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef FAUST_JSONUI_H
#define FAUST_JSONUI_H

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <assert.h>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef FAUST_PATHBUILDER_H
#define FAUST_PATHBUILDER_H

#include <vector>
#include <string>
#include <algorithm>

/*******************************************************************************
 * PathBuilder : Faust User Interface
 * Helper class to build complete hierarchical path for UI items.
 ******************************************************************************/

class PathBuilder
{

    protected:
    
        std::vector<std::string> fControlsLevel;
       
    public:
    
        PathBuilder() {}
        virtual ~PathBuilder() {}
    
        std::string buildPath(const std::string& label) 
        {
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res += fControlsLevel[i];
                res += "/";
            }
            res += label;
            std::replace(res.begin(), res.end(), ' ', '_');
            return res;
        }
    
};

#endif  // FAUST_PATHBUILDER_H
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __meta__
#define __meta__

struct Meta
{
    virtual void declare(const char* key, const char* value) = 0;
    virtual ~Meta() {};
};

#endif

/*******************************************************************************
 * JSONUI : Faust User Interface
 * This class produce a complete JSON decription of the DSP instance.
 ******************************************************************************/

template <typename REAL>
class JSONUIAux : public PathBuilder, public Meta, public UI
{

    protected:
    
        std::stringstream fJSON;
        std::stringstream fUI;
        std::stringstream fMeta;
        std::vector<std::pair <std::string, std::string> > fMetaAux;
        std::string fVersion;
        std::string fOptions;
        std::string fName;
        std::string fFileName;
        std::string fExpandedCode;
        std::string fSHAKey;
        std::string fDSPSize;
        std::map<std::string, int> fPathTable;
    
        char fCloseUIPar;
        char fCloseMetaPar;
        int fTab;
    
        int fInputs, fOutputs;
         
        void tab(int n, std::ostream& fout)
        {
            fout << '\n';
            while (n-- > 0) {
                fout << '\t';
            }
        }
    
        void addMeta(int tab_val, bool quote = true)
        {
            if (fMetaAux.size() > 0) {
                tab(tab_val, fUI); fUI << "\"meta\": [";
                std::string sep = "";
                for (size_t i = 0; i < fMetaAux.size(); i++) {
                    fUI << sep;
                    tab(tab_val + 1, fUI); fUI << "{ \"" << fMetaAux[i].first << "\": \"" << fMetaAux[i].second << "\" }";
                    sep = ",";
                }
                tab(tab_val, fUI); fUI << ((quote) ? "],": "]");
                fMetaAux.clear();
            }
        }
    
        // Add escape (that is  '\') for internal strings
        inline std::string flatten(const std::string& src)
        {
            bool in_string = false;
            std::stringstream dst;
            for (size_t i = 0; i < src.size(); i++) {
                switch (src[i]) {
                    case '\n':
                    case '\t':
                        break;
                    case ' ':
                        if (in_string) dst << src[i];
                        break;
                    case '"':
                        dst << "\\" << '"';
                        in_string = !in_string;
                        break;
                    case '\\':
                        dst << '\\' << '\\';
                        break;
                    default:
                        dst << src[i];
                        break;
                }
            }
            return dst.str();
        }
    
        inline std::string getAddressIndex(const std::string& path)
        {
            if (fPathTable.find(path) != fPathTable.end()) {
                std::stringstream num; num << fPathTable[path];
                return num.str();
            } else {
                return "-1";
            }
        }
      
     public:
     
        JSONUIAux(const std::string& name,
                  const std::string& filename,
                  int inputs,
                  int outputs,
                  const std::string& sha_key,
                  const std::string& dsp_code,
                  const std::string& version,
                  const std::string& options,
                  const std::string& size,
                  const std::map<std::string, int>& path_table)
        {
            init(name, filename, inputs, outputs, sha_key, dsp_code,  version, options, size, path_table);
        }

        JSONUIAux(const std::string& name, const std::string& filename, int inputs, int outputs)
        {
            init(name, filename, inputs, outputs, "", "", "", "", "", std::map<std::string, int>());
        }

        JSONUIAux(int inputs, int outputs)
        {
            init("", "", inputs, outputs, "", "","", "", "", std::map<std::string, int>());
        }
        
        JSONUIAux()
        {
            init("", "", -1, -1, "", "", "", "", "", std::map<std::string, int>());
        }
 
        virtual ~JSONUIAux() {}
        
        void setInputs(int inputs) { fInputs = inputs; }
        void setOutputs(int outputs) { fOutputs = outputs; }
    
        // Init may be called multiple times so fMeta and fUI are reinitialized
        void init(const std::string& name,
                  const std::string& filename,
                  int inputs,
                  int outputs,
                  const std::string& sha_key,
                  const std::string& dsp_code,
                  const std::string& version,
                  const std::string& options,
                  const std::string& size,
                  const std::map<std::string, int>& path_table)
        {
            fTab = 1;
            
            // Start Meta generation
            fMeta.str("");
            tab(fTab, fMeta); fMeta << "\"meta\": [";
            fCloseMetaPar = ' ';
            
            // Start UI generation
            fUI.str("");
            tab(fTab, fUI); fUI << "\"ui\": [";
            fCloseUIPar = ' ';
            fTab += 1;
            
            fName = name;
            fFileName = filename;
            fInputs = inputs;
            fOutputs = outputs;
            fExpandedCode = dsp_code;
            fSHAKey = sha_key;
            fDSPSize = size;
            fPathTable = path_table;
            fVersion = version;
            fOptions = options;
        }
   
        // -- widget's layouts
    
        virtual void openGenericGroup(const char* label, const char* name)
        {
            fControlsLevel.push_back(label);
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
            addMeta(fTab + 1);
            tab(fTab, fUI); fUI << "\"items\": [";
            fCloseUIPar = ' ';
            fTab += 1;
        }

        virtual void openTabBox(const char* label)
        {
            openGenericGroup(label, "tgroup");
        }
    
        virtual void openHorizontalBox(const char* label)
        {
            openGenericGroup(label, "hgroup");
        }
    
        virtual void openVerticalBox(const char* label)
        {
            openGenericGroup(label, "vgroup");
        }
    
        virtual void closeBox()
        {
            fControlsLevel.pop_back();
            fTab -= 1;
            tab(fTab, fUI); fUI << "]";
            fTab -= 1;
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }
    
        // -- active widgets
  
        virtual void addGenericButton(const char* label, const char* name)
        {
            std::string path = buildPath(label);
            std::string index = getAddressIndex(path);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\",";
                tab(fTab + 1, fUI); fUI << "\"index\": \"" << index << "\"" << ((fMetaAux.size() > 0) ? "," : "");
            } else {
                tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\"" << ((fMetaAux.size() > 0) ? "," : "");
            }
            addMeta(fTab + 1, false);
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        virtual void addButton(const char* label, REAL* zone)
        {
            addGenericButton(label, "button");
        }
    
        virtual void addCheckButton(const char* label, REAL* zone)
        {
            addGenericButton(label, "checkbox");
        }

        virtual void addGenericEntry(const char* label, const char* name, REAL init, REAL min, REAL max, REAL step)
        {
            std::string path = buildPath(label);
            std::string index = getAddressIndex(path);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab + 1, fUI); fUI << "\"index\": \"" << index << "\",";
            }
            addMeta(fTab + 1);
            tab(fTab + 1, fUI); fUI << "\"init\": \"" << init << "\",";
            tab(fTab + 1, fUI); fUI << "\"min\": \"" << min << "\",";
            tab(fTab + 1, fUI); fUI << "\"max\": \"" << max << "\",";
            tab(fTab + 1, fUI); fUI << "\"step\": \"" << step << "\"";
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }
    
        virtual void addVerticalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "vslider", init, min, max, step);
        }
    
        virtual void addHorizontalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "hslider", init, min, max, step);
        }
    
        virtual void addNumEntry(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "nentry", init, min, max, step);
        }

        // -- passive widgets
    
        virtual void addGenericBargraph(const char* label, const char* name, REAL min, REAL max) 
        {
            std::string path = buildPath(label);
            std::string index = getAddressIndex(path);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab + 1, fUI); fUI << "\"index\": \"" << index << "\",";
            }
            addMeta(fTab + 1);
            tab(fTab + 1, fUI); fUI << "\"min\": \"" << min << "\",";
            tab(fTab + 1, fUI); fUI << "\"max\": \"" << max << "\"";
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        virtual void addHorizontalBargraph(const char* label, REAL* zone, REAL min, REAL max) 
        {
            addGenericBargraph(label, "hbargraph", min, max);
        }
    
        virtual void addVerticalBargraph(const char* label, REAL* zone, REAL min, REAL max)
        {
            addGenericBargraph(label, "vbargraph", min, max);
        }
    
        virtual void addSoundfile(const char* label, const char* url, Soundfile** zone)
        {
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << "soundfile" << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\"" << ",";
            tab(fTab + 1, fUI); fUI << "\"url\": \"" << url << "\"" << ",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << buildPath(label) << "\"" << ((fMetaAux.size() > 0) ? "," : "");
            addMeta(fTab + 1, false);
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        // -- metadata declarations

        virtual void declare(REAL* zone, const char* key, const char* val)
        {
            fMetaAux.push_back(std::make_pair(key, val));
        }
    
        // Meta interface
        virtual void declare(const char* key, const char* value)
        {
            fMeta << fCloseMetaPar;
            // fName found in metadata
            if ((strcmp(key, "name") == 0) && (fName == "")) fName = value;
            // fFileName found in metadata
            if ((strcmp(key, "filename") == 0) && (fFileName == "")) fFileName = value;
            tab(fTab, fMeta); fMeta << "{ " << "\"" << key << "\"" << ": " << "\"" << value << "\" }";
            fCloseMetaPar = ',';
        }
    
        std::string JSON(bool flat = false)
        {
            fTab = 0;
            fJSON << "{";
            fTab += 1;
            tab(fTab, fJSON); fJSON << "\"name\": \"" << fName << "\",";
            tab(fTab, fJSON); fJSON << "\"filename\": \"" << fFileName << "\",";
            if (fVersion != "") { tab(fTab, fJSON); fJSON << "\"version\": \"" << fVersion << "\","; }
            if (fOptions != "") { tab(fTab, fJSON); fJSON << "\"options\": \"" << fOptions << "\","; }
            if (fDSPSize != "") { tab(fTab, fJSON); fJSON << "\"size\": \"" << fDSPSize << "\","; }
            if (fSHAKey != "") { tab(fTab, fJSON); fJSON << "\"sha_key\": \"" << fSHAKey << "\","; }
            if (fExpandedCode != "") { tab(fTab, fJSON); fJSON << "\"code\": \"" << fExpandedCode << "\","; }
            tab(fTab, fJSON); fJSON << "\"inputs\": \"" << fInputs << "\","; 
            tab(fTab, fJSON); fJSON << "\"outputs\": \"" << fOutputs << "\",";
            tab(fTab, fMeta); fMeta << "],";
            tab(fTab, fUI); fUI << "]";
            fTab -= 1;
            if (fCloseMetaPar == ',') { // If "declare" has been called, fCloseMetaPar state is now ','
                fJSON << fMeta.str() << fUI.str();
            } else {
                fJSON << fUI.str();
            }
            tab(fTab, fJSON); fJSON << "}";
            return (flat) ? flatten(fJSON.str()) : fJSON.str();
        }
    
};

// Externally available class using FAUSTFLOAT

class JSONUI : public JSONUIAux<FAUSTFLOAT>
{
    public :
    
        JSONUI(const std::string& name,
               const std::string& filename,
               int inputs,
               int outputs,
               const std::string& sha_key,
               const std::string& dsp_code,
               const std::string& version,
               const std::string& options,
               const std::string& size,
               const std::map<std::string, int>& path_table):
        JSONUIAux<FAUSTFLOAT>(name, filename,
                              inputs, outputs,
                              sha_key, dsp_code,
                              version, options,
                              size, path_table)
        {}
        
        JSONUI(const std::string& name, const std::string& filename, int inputs, int outputs):
        JSONUIAux<FAUSTFLOAT>(name, filename, inputs, outputs)
        {}
        
        JSONUI(int inputs, int outputs):JSONUIAux<FAUSTFLOAT>(inputs, outputs)
        {}
        
        JSONUI():JSONUIAux<FAUSTFLOAT>()
        {}
    
        virtual ~JSONUI() {}
    
};

#endif // FAUST_JSONUI_H
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __dsp__
#define __dsp__

#include <string>
#include <vector>

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

class UI;
struct Meta;

/**
 * DSP memory manager.
 */

struct dsp_memory_manager {
    
    virtual ~dsp_memory_manager() {}
    
    virtual void* allocate(size_t size) = 0;
    virtual void destroy(void* ptr) = 0;
    
};

/**
* Signal processor definition.
*/

class dsp {

    public:

        dsp() {}
        virtual ~dsp() {}

        /* Return instance number of audio inputs */
        virtual int getNumInputs() = 0;
    
        /* Return instance number of audio outputs */
        virtual int getNumOutputs() = 0;
    
        /**
         * Trigger the ui_interface parameter with instance specific calls
         * to 'addBtton', 'addVerticalSlider'... in order to build the UI.
         *
         * @param ui_interface - the user interface builder
         */
        virtual void buildUserInterface(UI* ui_interface) = 0;
    
        /* Returns the sample rate currently used by the instance */
        virtual int getSampleRate() = 0;
    
        /**
         * Global init, calls the following methods:
         * - static class 'classInit': static tables initialization
         * - 'instanceInit': constants and instance state initialization
         *
         * @param samplingRate - the sampling rate in Hertz
         */
        virtual void init(int samplingRate) = 0;

        /**
         * Init instance state
         *
         * @param samplingRate - the sampling rate in Hertz
         */
        virtual void instanceInit(int samplingRate) = 0;

        /**
         * Init instance constant state
         *
         * @param samplingRate - the sampling rate in Hertz
         */
        virtual void instanceConstants(int samplingRate) = 0;
    
        /* Init default control parameters values */
        virtual void instanceResetUserInterface() = 0;
    
        /* Init instance state (delay lines...) */
        virtual void instanceClear() = 0;
 
        /**
         * Return a clone of the instance.
         *
         * @return a copy of the instance on success, otherwise a null pointer.
         */
        virtual dsp* clone() = 0;
    
        /**
         * Trigger the Meta* parameter with instance specific calls to 'declare' (key, value) metadata.
         *
         * @param m - the Meta* meta user
         */
        virtual void metadata(Meta* m) = 0;
    
        /**
         * DSP instance computation, to be called with successive in/out audio buffers.
         *
         * @param count - the number of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         *
         */
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) = 0;
    
        /**
         * DSP instance computation: alternative method to be used by subclasses.
         *
         * @param date_usec - the timestamp in microsec given by audio driver.
         * @param count - the number of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         *
         */
        virtual void compute(double /*date_usec*/, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
       
};

/**
 * Generic DSP decorator.
 */

class decorator_dsp : public dsp {

    protected:

        dsp* fDSP;

    public:

        decorator_dsp(dsp* dsp = 0):fDSP(dsp) {}
        virtual ~decorator_dsp() { delete fDSP; }

        virtual int getNumInputs() { return fDSP->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP->getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) { fDSP->buildUserInterface(ui_interface); }
        virtual int getSampleRate() { return fDSP->getSampleRate(); }
        virtual void init(int samplingRate) { fDSP->init(samplingRate); }
        virtual void instanceInit(int samplingRate) { fDSP->instanceInit(samplingRate); }
        virtual void instanceConstants(int samplingRate) { fDSP->instanceConstants(samplingRate); }
        virtual void instanceResetUserInterface() { fDSP->instanceResetUserInterface(); }
        virtual void instanceClear() { fDSP->instanceClear(); }
        virtual decorator_dsp* clone() { return new decorator_dsp(fDSP->clone()); }
        virtual void metadata(Meta* m) { fDSP->metadata(m); }
        // Beware: subclasses usually have to overload the two 'compute' methods
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(count, inputs, outputs); }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(date_usec, count, inputs, outputs); }
    
};

/**
 * DSP factory class.
 */

class dsp_factory {
    
    protected:
    
        // So that to force sub-classes to use deleteDSPFactory(dsp_factory* factory);
        virtual ~dsp_factory() {}
    
    public:
    
        virtual std::string getName() = 0;
        virtual std::string getSHAKey() = 0;
        virtual std::string getDSPCode() = 0;
    
        virtual std::vector<std::string> getDSPFactoryLibraryList() = 0;
        virtual std::vector<std::string> getDSPFactoryIncludePathnames() = 0;
    
        virtual dsp* createDSPInstance() = 0;
    
        virtual void setMemoryManager(dsp_memory_manager* manager) = 0;
        virtual dsp_memory_manager* getMemoryManager() = 0;
    
};

/**
 * On Intel set FZ (Flush to Zero) and DAZ (Denormals Are Zero)
 * flags to avoid costly denormals.
 */

#ifdef __SSE__
    #include <xmmintrin.h>
    #ifdef __SSE2__
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8040)
    #else
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8000)
    #endif
#else
    #define AVOIDDENORMALS
#endif

#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef __misc__
#define __misc__

#include <algorithm>
#include <map>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>


using std::max;
using std::min;

struct XXXX_Meta : std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

struct MY_Meta : Meta, std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

inline int lsr(int x, int n)	{ return int(((unsigned int)x) >> n); }

inline int int2pow2(int x)		{ int r = 0; while ((1<<r) < x) r++; return r; }

inline long lopt(char* argv[], const char* name, long def)
{
	int	i;
    for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return std::atoi(argv[i+1]);
	return def;
}

inline bool isopt(char* argv[], const char* name)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return true;
	return false;
}

inline const char* lopts(char* argv[], const char* name, const char* def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return argv[i+1];
	return def;
}

#endif


#ifdef POLY2
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __dsp_combiner__
#define __dsp_combiner__

#include <string.h>
#include <assert.h>


// Combine two DSP in sequence

class dsp_sequencer : public dsp {
    
    private:
        
        dsp* fDSP1;
        dsp* fDSP2;
        FAUSTFLOAT** fSeqBuffer;
         
    public:
        
        dsp_sequencer(dsp* dsp1, dsp* dsp2, int buffer_size = 4096)
            :fDSP1(dsp1), fDSP2(dsp2)
        {
            assert(fDSP1->getNumOutputs() == fDSP2->getNumInputs());
            fSeqBuffer = new FAUSTFLOAT*[fDSP1->getNumOutputs()];
            for (int i = 0; i < fDSP1->getNumOutputs(); i++) {
                fSeqBuffer[i] = new FAUSTFLOAT[buffer_size];
            }
        }
        
        virtual ~dsp_sequencer()
        {
            for (int i = 0; i < fDSP1->getNumOutputs(); i++) {
               delete [] fSeqBuffer[i];
            }
            
            delete [] fSeqBuffer;
            delete fDSP1;
            delete fDSP2;
        }
               
        virtual int getNumInputs() { return fDSP1->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP2->getNumOutputs(); }
    
        virtual void buildUserInterface(UI* ui_interface)
        {
            ui_interface->openTabBox("Sequencer");
            ui_interface->openVerticalBox("DSP1");
            fDSP1->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->openVerticalBox("DSP2");
            fDSP2->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->closeBox();
        }
        
        virtual int getSampleRate()
        {
            return fDSP1->getSampleRate();
        }
    
        virtual void init(int samplingRate)
        {
            fDSP1->init(samplingRate);
            fDSP2->init(samplingRate);
        }
    
        virtual void instanceInit(int samplingRate)
        {
            fDSP1->instanceInit(samplingRate);
            fDSP2->instanceInit(samplingRate);
        }
    
        virtual void instanceConstants(int samplingRate)
        {
            fDSP1->instanceConstants(samplingRate);
            fDSP2->instanceConstants(samplingRate);
        }
    
        virtual void instanceResetUserInterface()
        {
            fDSP1->instanceResetUserInterface();
            fDSP2->instanceResetUserInterface();
        }
    
        virtual void instanceClear()
        {
            fDSP1->instanceClear();
            fDSP2->instanceClear();
        }
        
        virtual dsp* clone()
        {
            return new dsp_sequencer(fDSP1->clone(), fDSP2->clone());
        }
    
        virtual void metadata(Meta* m)
        {
            fDSP1->metadata(m);
            fDSP2->metadata(m);
        }
 
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, fSeqBuffer);
            fDSP2->compute(count, fSeqBuffer, outputs);
        }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
};

// Combine two DSP in parallel

class dsp_parallelizer : public dsp {
    
    private:
        
        dsp* fDSP1;
        dsp* fDSP2;
    
        FAUSTFLOAT** fInputsDSP2;
        FAUSTFLOAT** fOutputsDSP2;
    
    public:
        
        dsp_parallelizer(dsp* dsp1, dsp* dsp2, int buffer_size = 4096)
            :fDSP1(dsp1), fDSP2(dsp2)
        {
            fInputsDSP2 = new FAUSTFLOAT*[fDSP2->getNumInputs()];
            fOutputsDSP2 = new FAUSTFLOAT*[fDSP2->getNumOutputs()];
        }
        
        virtual ~dsp_parallelizer()
        {
            delete fDSP1;
            delete fDSP2;
            delete [] fInputsDSP2;
            delete [] fOutputsDSP2;
        }
               
        virtual int getNumInputs() { return fDSP1->getNumInputs() + fDSP2->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP1->getNumOutputs() + fDSP2->getNumOutputs(); }
    
        virtual void buildUserInterface(UI* ui_interface)
        {
            ui_interface->openTabBox("Parallelizer");
            ui_interface->openVerticalBox("DSP1");
            fDSP1->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->openVerticalBox("DSP2");
            fDSP2->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->closeBox();
        }
        
        virtual int getSampleRate()
        {
            return fDSP1->getSampleRate();
        }
    
        virtual void init(int samplingRate)
        {
            fDSP1->init(samplingRate);
            fDSP2->init(samplingRate);
        }
    
        virtual void instanceInit(int samplingRate)
        {
            fDSP1->instanceInit(samplingRate);
            fDSP2->instanceInit(samplingRate);
        }
    
        virtual void instanceConstants(int samplingRate)
        {
            fDSP1->instanceConstants(samplingRate);
            fDSP2->instanceConstants(samplingRate);
        }
        
        virtual void instanceResetUserInterface()
        {
            fDSP1->instanceResetUserInterface();
            fDSP2->instanceResetUserInterface();
        }

        virtual void instanceClear()
        {
            fDSP1->instanceClear();
            fDSP2->instanceClear();
        }
        
        virtual dsp* clone()
        {
            return new dsp_parallelizer(fDSP1->clone(), fDSP2->clone());
        }

        virtual void metadata(Meta* m)
        {
            fDSP1->metadata(m);
            fDSP2->metadata(m);
        }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, outputs);
            
            // Shift inputs/outputs channels for fDSP2
            for (int chan = 0; chan < fDSP2->getNumInputs(); chan++) {
                fInputsDSP2[chan] = inputs[fDSP1->getNumInputs() + chan];
            }
            for (int chan = 0; chan < fDSP2->getNumOutputs(); chan++) {
                fOutputsDSP2[chan] = outputs[fDSP1->getNumOutputs() + chan];
            }
            
            fDSP2->compute(count, fInputsDSP2, fOutputsDSP2);
        }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
};

#endif
#include "effect.cpp"
#endif

#if SOUNDFILE
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef __SoundUI_H__
#define __SoundUI_H__

#include <map>
#include <vector>
#include <string>

#ifdef __APPLE__
#include <CoreFoundation/CFBundle.h>
#endif

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef Decorator_UI_H
#define Decorator_UI_H


//----------------------------------------------------------------
//  Generic UI empty implementation
//----------------------------------------------------------------

class GenericUI : public UI
{
    
    public:
        
        GenericUI() {}
        virtual ~GenericUI() {}
        
        // -- widget's layouts
        virtual void openTabBox(const char* label) {}
        virtual void openHorizontalBox(const char* label) {}
        virtual void openVerticalBox(const char* label) {}
        virtual void closeBox() {}
        
        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
    
        // -- passive widgets
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* soundpath, Soundfile** sf_zone) {}
    
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) {}
    
};

//----------------------------------------------------------------
//  Generic UI decorator
//----------------------------------------------------------------

class DecoratorUI : public UI
{
    
    protected:
        
        UI* fUI;
        
    public:
        
        DecoratorUI(UI* ui = 0):fUI(ui) {}
        virtual ~DecoratorUI() { delete fUI; }
        
        // -- widget's layouts
        virtual void openTabBox(const char* label)          { fUI->openTabBox(label); }
        virtual void openHorizontalBox(const char* label)   { fUI->openHorizontalBox(label); }
        virtual void openVerticalBox(const char* label)     { fUI->openVerticalBox(label); }
        virtual void closeBox()                             { fUI->closeBox(); }
        
        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone)         { fUI->addButton(label, zone); }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)    { fUI->addCheckButton(label, zone); }
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addVerticalSlider(label, zone, init, min, max, step); }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addHorizontalSlider(label, zone, init, min, max, step); }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addNumEntry(label, zone, init, min, max, step); }
        
        // -- passive widgets
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        { fUI->addHorizontalBargraph(label, zone, min, max); }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        { fUI->addVerticalBargraph(label, zone, min, max); }
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) { fUI->addSoundfile(label, filename, sf_zone); }
    
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) { fUI->declare(zone, key, val); }
    
};

#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __soundfile__
#define __soundfile__

#include <sndfile.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#define BUFFER_SIZE 1024
#define SAMPLE_RATE 44100
#define MAX_CHAN    64

#define MIN_CHAN(a,b) ((a) < (b) ? (a) : (b))

#define PRE_PACKED_STRUCTURE
#define POST_PACKED_STRUCTURE __attribute__((__packed__))

PRE_PACKED_STRUCTURE
struct Soundfile {
    
    FAUSTFLOAT** fBuffers;
    int fLength;
    int fSampleRate;
    int fChannels;
    
    typedef sf_count_t (* sample_read)(SNDFILE* sndfile, FAUSTFLOAT* ptr, sf_count_t frames);
    
    static std::string CheckAux(const std::string& path_name_str, std::string& sha_key)
    {
        SF_INFO snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name_str.c_str(), SFM_READ, &snd_info);
        if (snd_file) {
            sf_close(snd_file);
            // Possibly read associated SHA_KEY file
            std::string sha_key_path_name_str = path_name_str + "_sha_key";
            std::ifstream reader(sha_key_path_name_str.c_str());
            if (reader.is_open()) {
                std::string sha_key_line;
                getline(reader, sha_key_line);
                std::stringstream line_reader(sha_key_line);
                line_reader >> sha_key;
            }
            return path_name_str;
        } else {
            std::cerr << "ERROR : cannot open '" << path_name_str << "' (" << sf_strerror(NULL) << ")" << std::endl;
            return "";
        }
    }
    
    // Check if soundfile exists and return the real path_name
    static std::string Check(const std::vector<std::string>& sound_directories, const std::string& file_name_str, std::string& sha_key)
    {
        std::string path_name_str = CheckAux(file_name_str, sha_key);
        if (path_name_str != "") {
            return path_name_str;
        } else {
            for (int i = 0; i < sound_directories.size(); i++) {
                std::string res = CheckAux(sound_directories[i] + "/" + file_name_str, sha_key);
                if (res != "") { return res; }
            }
            return "";
        }
    }
    
    Soundfile(const std::string& path_name_str, int max_chan)
    {
        fBuffers = new FAUSTFLOAT*[max_chan];
        if (!fBuffers) {
            throw std::bad_alloc();
        }
     
        // Open sndfile
        SF_INFO	snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name_str.c_str(), SFM_READ, &snd_info);
        
        if (snd_file) {
            
            fChannels = MIN_CHAN(max_chan, snd_info.channels);
            fLength = int(snd_info.frames);
            fSampleRate = snd_info.samplerate;
            
            for (int chan = 0; chan < fChannels; chan++) {
                fBuffers[chan] = new FAUSTFLOAT[snd_info.frames];
                if (!fBuffers[chan]) {
                    throw std::bad_alloc();
                }
            }
            
            // Read and fill snd_info.channels number of channels
            sf_count_t nbf, index = 0;
            FAUSTFLOAT buffer[BUFFER_SIZE * snd_info.channels];
            sample_read reader;
            if (sizeof(FAUSTFLOAT) == 4) {
                reader = reinterpret_cast<sample_read>(sf_readf_float);
            } else {
                reader = reinterpret_cast<sample_read>(sf_readf_double);
            }
            do {
                nbf = reader(snd_file, buffer, BUFFER_SIZE);
                for (int sample = 0; sample < nbf; sample++) {
                    for (int chan = 0; chan < fChannels; chan++) {
                        fBuffers[chan][index + sample] = buffer[sample * snd_info.channels + chan];
                    }
                }
                index += nbf;
            } while (nbf == BUFFER_SIZE);
            
            // Share the same buffers for all other channels so that we have max_chan channels available
            for (int chan = fChannels; chan < max_chan; chan++) {
                fBuffers[chan] = fBuffers[chan % snd_info.channels];
            }
       
            sf_close(snd_file);
            
        } else {
            
            if (path_name_str != "") {
                std::cerr << "Error opening the file : " << path_name_str << std::endl;
            }
            
            fChannels = 1;
            fLength = BUFFER_SIZE;
            fSampleRate = SAMPLE_RATE;
            
            // Allocate 1 channel
            fBuffers[0] = new FAUSTFLOAT[BUFFER_SIZE];
            if (!fBuffers[0]) {
                throw std::bad_alloc();
            }
            memset(fBuffers[0], 0, BUFFER_SIZE * sizeof(FAUSTFLOAT));
            
            // Share the same buffer for all other channels so that we have max_chan channels available
            for (int chan = fChannels; chan < max_chan; chan++) {
                fBuffers[chan] = fBuffers[0];
            }
        }
    }
    
    ~Soundfile()
    {
        // Free the real channels only
        for (int chan = 0; chan < fChannels; chan++) {
            delete fBuffers[chan];
        }
        delete [] fBuffers;
    }
    
} POST_PACKED_STRUCTURE;

#endif

// To be used by dsp code if no SoundUI is used or when soundfile is not found
extern "C" Soundfile* defaultsound = new Soundfile("", MAX_CHAN);

class SoundUI : public GenericUI
{
		
    private:
    
        std::vector<std::string> fSoundfileDir;        // The soundfile directories
        std::map<std::string, Soundfile*> fSFMap;      // Map to share loaded soundfiles
    
     public:
            
        SoundUI(const std::string& sound_directory = "")
        {
            fSoundfileDir.push_back(sound_directory);
        }
    
        SoundUI(const std::vector<std::string>& sound_directories):fSoundfileDir(sound_directories)
        {}
    
        virtual ~SoundUI()
        {   
            // Delete all soundfiles
            std::map<std::string, Soundfile*>::iterator it;
            for (it = fSFMap.begin(); it != fSFMap.end(); it++) {
                delete (*it).second;
            }
        }

        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* file_name, Soundfile** sf_zone)
        {
            // If no filename was given, assume label is the filename
            std::string file_name_str;
            if (strlen(file_name) == 0) {
                file_name_str = label;
            } else {
                file_name_str = file_name;
            }
            
            std::string sha_key;
            std::string path_name_str = Soundfile::Check(fSoundfileDir, file_name_str, sha_key);
            if (path_name_str != "") {
                std::string file_key = (sha_key == "") ? path_name_str : sha_key;
                // Check if 'file_key' is already loaded
                if (fSFMap.find(file_key) == fSFMap.end()) {
                    fSFMap[file_key] = new Soundfile(path_name_str, 64);
                }
                // Get the soundfile
                *sf_zone = fSFMap[file_key];
            } else {
                // Take the defaultsound
                std::cout << "addSoundfile : defaultsound\n";
                *sf_zone = defaultsound;
            }
        }
    
    static std::string getBinaryPath(std::string folder = "")
    {
        std::string bundle_path_str;
    #ifdef __APPLE__
        CFURLRef bundle_ref = CFBundleCopyBundleURL(CFBundleGetMainBundle());
        if (bundle_ref) {
            UInt8 bundle_path[512];
            if (CFURLGetFileSystemRepresentation(bundle_ref, true, bundle_path, 512)) {
                bundle_path_str = std::string((char*)bundle_path) + folder;
            }
        }
    #endif
        return bundle_path_str;
    }
    
    static std::string getBinaryPathFrom(const std::string& path)
    {
        std::string bundle_path_str;
    #ifdef __APPLE__
        CFBundleRef bundle = CFBundleGetBundleWithIdentifier(CFStringCreateWithCString(kCFAllocatorDefault, path.c_str(), CFStringGetSystemEncoding()));
        CFURLRef bundle_ref = CFBundleCopyBundleURL(bundle);
        if (bundle_ref) {
            UInt8 bundle_path[512];
            if (CFURLGetFileSystemRepresentation(bundle_ref, true, bundle_path, 512)) {
                bundle_path_str = std::string((char*)bundle_path);
            }
        }
    #endif
        return bundle_path_str;
    }
};

#endif
#endif

using namespace std;

/******************************************************************************
*******************************************************************************

							       VECTOR INTRINSICS

*******************************************************************************
*******************************************************************************/


/********************END ARCHITECTURE SECTION (part 1/2)****************/

/**************************BEGIN USER SECTION **************************/

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <math.h>

static double fmydspSIG0Wave0[12288] = {0.0,0.0047074296035356997,0.0094148592070713005,0.014122288810607,0.018829718414143,0.023270972717315,0.027235469995153,0.031199967272991,0.035164464550829,0.039128961828667,0.042466887160516997,0.045556959665631003,0.048647032170745001,0.051737104675859,0.054794214618572999,0.05744378742615,0.060093360233726002,0.062742933041303003,0.065392505848878998,0.068010756022532995,0.070588007984244999,0.073165259945957004,0.075742511907669993,0.078319763869381998,0.080829376235611997,0.083321158106756998,0.085812939977902,0.088304721849047002,0.090760097307988993,0.093008618152135999,0.095257138996283006,0.097505659840429998,0.099754180684577004,0.10188915884431,0.10391414252851,0.10593912621271,0.10796410989690999,0.10998909358112,0.11194573697312001,0.11389182518910999,0.1158379134051,0.11778400162108001,0.11972566203017999,0.12165202637911,0.12357839072805001,0.12550475507698,0.12743111942591001,0.12929234879740001,0.13110694456635999,0.13292154033532,0.13473613610428001,0.13655073187323999,0.13822302657567001,0.13988640603055,0.14154978548543001,0.14321316494031,0.14485096151094001,0.14642887087525,0.14800678023957001,0.14958468960387999,0.15116259896819001,0.15273186143690001,0.15429662155651,0.15586138167611999,0.15742614179573,0.15899017140175001,0.16050890916489999,0.16202764692805,0.1635463846912,0.16506512245435001,0.16654450193404,0.16795804573956999,0.16937158954510001,0.17078513335063999,0.17219867715616999,0.17354480499281999,0.17486630408543999,0.17618780317805,0.17750930227066,0.17882901235039,0.18013078757595,0.18143256280150999,0.18273433802707001,0.18403611325263,0.18532903286440999,0.18661108422291001,0.18789313558140999,0.18917518693992,0.19045723829842001,0.19168090820312,0.19289063871577,0.19410036922841001,0.19531009974104999,0.19650677045963,0.19763760550404999,0.19876844054848,0.19989927559289999,0.20103011063733001,0.20214372643274001,0.20324168836541001,0.20433965029807,0.20543761223074,0.20653557416341001,0.20762193732921,0.20870675001717001,0.20979156270513999,0.21087637539310999,0.21195328660750001,0.21300522618371001,0.21405716575992001,0.21510910533611999,0.21616104491233001,0.21716969037673001,0.21814930910708,0.21912892783742,0.22010854656777001,0.22108816529811001,0.22202374449460999,0.2229573408685,0.22389093724237999,0.22482453361627,0.22575398544364,0.22667443257281999,0.22759487970200001,0.22851532683119,0.22943577396036999,0.23034736547577001,0.23125466336025,0.23216196124472999,0.23306925912921,0.23397488726832999,0.23482958817399999,0.23568428907967001,0.23653898998534001,0.23739369089101001,0.23822531353047,0.23902084283498001,0.23981637213949,0.24061190144399999,0.24140743074849999,0.24219312048215,0.24297550054195,0.24375788060176001,0.24454026066156001,0.24532194002464999,0.24609774546211,0.24687355089956001,0.24764935633702001,0.24842516177446999,0.24918262982986,0.24991898753319999,0.25065534523654998,0.25139170293989999,0.25212806064324,0.25282653599875998,0.25351687134563999,0.25420720669253,0.25489754203942,0.25558310668528,0.25624714354276001,0.25691118040024002,0.25757521725771998,0.25823925411520998,0.25889974276380001,0.25955720499892998,0.26021466723406,0.26087212946918997,0.26152959170432,0.26216934271190001,0.26280708107996997,0.26344481944804998,0.26408255781612999,0.26470850360760001,0.26530021961922001,0.26589193563084002,0.26648365164246002,0.26707536765406997,0.26764688272853998,0.2682057256284,0.26876456852825997,0.26932341142812,0.26988225432798002,0.27043470150678001,0.27098696978428999,0.27153923806180003,0.27209150633931001,0.27264159798447002,0.27318729163963001,0.27373298529479001,0.27427867894995001,0.27482437260511,0.27534287326441997,0.27584911918547,0.27635536510651998,0.27686161102757001,0.27736629156234999,0.27783966437163998,0.27831303718094003,0.27878640999023002,0.27925978279952002,0.27972514977615998,0.28017879871840001,0.28063244766063999,0.28108609660287998,0.28153974554512001,0.28199339448735999,0.28244704342959998,0.28290069237184001,0.28335434131407999,0.28380557508893001,0.28423950016410998,0.2846734252393,0.28510735031447998,0.28554127538967,0.28595623692827998,0.28635071426935998,0.28674519161043999,0.28713966895151,0.28753414629259,0.28791207526448998,0.28828682873851003,0.28866158221254001,0.28903633568656001,0.28940979212624002,0.28977797097792002,0.29014614982959003,0.29051432868125998,0.29088250753293998,0.29124338124866,0.29159841085562999,0.29195344046261001,0.29230847006958,0.29266349967654998,0.2929944968771,0.29332322799465999,0.29365195911223002,0.2939806902298,0.29430226529581999,0.29460469792397997,0.29490713055214002,0.29520956318030001,0.29551199580845999,0.29580613934359001,0.29609542272704997,0.2963847061105,0.29667398949396001,0.29696327287742003,0.29725255626087999,0.29754183964433001,0.29783112302779002,0.29812040641124998,0.29840056582899999,0.29866355072305001,0.29892653561709998,0.29918952051115,0.29945250540520002,0.29969694419901999,0.29993363060367001,0.30017031700830998,0.30040700341296001,0.30064285494492998,0.30086639210486998,0.30108992926481998,0.30131346642475998,0.30153700358469998,0.30175776777468,0.30197473031227001,0.30219169284986003,0.30240865538745998,0.30262561792504999,0.30283745195903999,0.30304783987428002,0.30325822778952,0.30346861570477002,0.30367445654559,0.30385197134907999,0.30402948615255998,0.30420700095605002,0.30438451575953002,0.30455223571748002,0.30471002665391,0.30486781759033998,0.30502560852677002,0.3051833994632,0.30533556991749,0.30548678623157,0.30563800254564999,0.30578921885972998,0.30594043517380998,0.30609165148789003,0.30624286780197002,0.30639408411605001,0.30654530043013001,0.30668524596302998,0.30681673841006002,0.30694823085709,0.30707972330410999,0.30721121575114002,0.30731214589472,0.30741076522999,0.30750938456526,0.30760800390053,0.30770662323579001,0.30780524257106001,0.30790386190633001,0.30800248124160001,0.30810110057687001,0.30819547100653999,0.30828751571946,0.30837956043238002,0.30847160514529998,0.30856359022445001,0.30864248569267,0.30872138116087999,0.30880027662909998,0.30887917209730997,0.30894852616348001,0.30900112314229,0.3090537201211,0.30910631709990999,0.30915891407871998,0.30920202928924001,0.30924147702334998,0.30928092475746,0.30932037249157002,0.30935982022566999,0.30939926795978001,0.30943871569388998,0.309478163428,0.30951761116210003,0.30955418156716002,0.30958705467891001,0.30961992779066999,0.30965280090243003,0.30968567401418001,0.30970284853787999,0.30971599778258002,0.30972914702727999,0.30974229627198002,0.30975240419478001,0.30974582957243002,0.30973925495007998,0.30973268032772999,0.30972610570538001,0.30971616177542999,0.30970301253072002,0.30968986328602,0.30967671404132002,0.30966356479661999,0.30964469071068002,0.30962496684363,0.30960524297656999,0.30958551910951998,0.30956428948995002,0.30953799100055002,0.30951169251114002,0.30948539402174002,0.30945909553232998,0.30941735189836,0.30936475491955001,0.30931215794074002,0.30925956096193002,0.30920696398311998,0.30914815018453001,0.30908897858336998,0.30902980698221,0.30897063538105002,0.30890946604883002,0.30884371982532,0.30877797360179998,0.30871222737829002,0.30864648115477999,0.30858073493125998,0.30851498870775002,0.30844924248423999,0.30838349626071998,0.30831721333334999,0.30822516862042998,0.30813312390751002,0.30804107919459001,0.30794903448166999,0.30785201034956,0.30774681639194001,0.30764162243431997,0.30753642847669999,0.30743123451908,0.30732604056145002,0.30722084660382998,0.30711565264620999,0.30701045868859,0.30690526473097002,0.30680007077334998,0.30669487681572999,0.30658968285811,0.30648448890049002,0.30637034987843997,0.30624543205376997,0.30612051422908998,0.30599559640441998,0.30587067857973999,0.30572974908974998,0.30558510739801997,0.30544046570629002,0.30529582401456001,0.30515006418978002,0.30499884787569997,0.30484763156161998,0.30469641524753999,0.30454519893345999,0.30439745628607001,0.30425281459434,0.30410817290261,0.30396353121087999,0.30381888951914998,0.30366258942678998,0.30350479849035999,0.30334700755393001,0.30318921661749998,0.30302659534628001,0.30284908054278997,0.30267156573930998,0.30249405093581999,0.30231653613234,0.30213109003839,0.30194042599020998,0.30174976194202002,0.30155909789383001,0.30136843384563999,0.30118409097630999,0.30100000155048001,0.30081591212463998,0.30063182269880001,0.30044563118283002,0.30025496713464001,0.30006430308644999,0.29987363903825998,0.29968297499008001,0.29947893807058001,0.29926855015532999,0.29905816224009002,0.29884777432484999,0.29863690933950998,0.29841337217955999,0.29818983501961999,0.29796629785966999,0.29774276069972999,0.29751922353978,0.29729568637984,0.29707214921989,0.29684861205995,0.29662507490001,0.29640153774006001,0.29617800058012,0.29595446342017001,0.29573092626023001,0.29550592807309001,0.29526924166844998,0.29503255526380001,0.29479586885914999,0.29455918245451002,0.29431632395541002,0.29406648830606003,0.29381665265670998,0.29356681700735998,0.29331698135800999,0.29305626254694001,0.29279327765288998,0.29253029275884002,0.29226730786478999,0.29200554546287,0.29174913519117002,0.29149272491946998,0.29123631464777,0.29097990437607002,0.29071991607859998,0.29045693118455002,0.29019394629049,0.28993096139643998,0.28966797650239001,0.28938719093012999,0.28910448216903001,0.28882177340791998,0.28853906464682,0.28825464141502999,0.28796535803156997,0.28767607464811001,0.28738679126465999,0.28709750788119998,0.28680822449774002,0.28651894111428,0.28622965773082998,0.28594037434737002,0.28565109096391,0.28535538204250999,0.28505952403669998,0.28476366603088998,0.28446780802507998,0.28416974357004998,0.28386731094188999,0.28356487831373001,0.28326244568557002,0.28296001305740998,0.28264389448068,0.28232173798547,0.28199958149025001,0.28167742499504,0.28135526849982001,0.28103311200461001,0.28071095550940001,0.28038879901418001,0.28006664251897001,0.27974718445152003,0.27943160257866001,0.27911602070579999,0.27880043883292999,0.27848485696007003,0.27815411320300998,0.27781880746309001,0.27748350172317998,0.27714819598326002,0.27681205537066,0.27647017500839999,0.27612829464612998,0.27578641428386003,0.27544453392159002,0.27509946315300998,0.27475100816838999,0.27440255318377998,0.27405409819915999,0.27370564321454,0.27335718822992,0.27300873324530001,0.27266027826068001,0.27231182327606002,0.27196204144022001,0.27160701183324998,0.27125198222628,0.27089695261931002,0.27054192301233998,0.27017952863566003,0.26981134978398003,0.26944317093231002,0.26907499208064001,0.26870681322896001,0.26833259645879998,0.26795784298477998,0.26758308951075999,0.26720833603673,0.26683358256271,0.26645882908868002,0.26608407561466002,0.26570932214062998,0.26533456866660998,0.26495981519257999,0.26458506171856,0.26421030824453001,0.26383555477051002,0.26346080129649002,0.26307298802840001,0.26268508530967999,0.26229718259094997,0.26190927987222001,0.26151675553687997,0.26111570357344999,0.26071465161002,0.26031359964659001,0.25991254768316002,0.25951149571972998,0.25911044375629999,0.25870939179287,0.25830833982944001,0.25790728786601003,0.25750623590257998,0.25710518393914999,0.25670413197572001,0.25630308001229002,0.25589922526200998,0.25549159867623,0.25508397209043998,0.25467634550466001,0.25426871891887998,0.25385077569212999,0.25342999986164999,0.25300922403116999,0.25258844820067999,0.25216673313843002,0.25173938268559998,0.25131203223276,0.25088468177993001,0.25045733132709003,0.25003327563965999,0.24961249980917,0.24919172397868999,0.2487709481482,0.24835017231772,0.24792374618821,0.24749639573537,0.24706904528254001,0.24664169482970999,0.24621148195625001,0.24577098225871999,0.24533048256118001,0.24488998286364,0.24444948316609999,0.24400519672463,0.24355812240474001,0.24311104808485001,0.24266397376495999,0.24221689944506999,0.24176982512518,0.24132275080529,0.24087567648541,0.24042860216552001,0.23998152784563001,0.23953445352573999,0.23908737920584999,0.23864030488596,0.23819323056607,0.23774187752369999,0.23728822858146001,0.23683457963922,0.23638093069697999,0.23592716248720999,0.23546036430027001,0.23499356611333,0.23452676792638999,0.23405996973943999,0.23359317155250001,0.23312637336556,0.23265957517861999,0.23219277699167001,0.23172597880473,0.23125918061778999,0.23079238243083999,0.23032558424390001,0.22985878605696,0.22939143625771,0.22891806344842,0.22844469063912001,0.22797131782982999,0.22749794502053,0.2270216650653,0.22654171763365999,0.22606177020200999,0.22558182277037001,0.22510187533872,0.22461666522751,0.22413014317350999,0.22364362111951,0.22315709906552,0.22267057701151999,0.22218405495752,0.22169753290352001,0.22121101084952999,0.22072448879553,0.22023456761704999,0.21974147094071,0.21924837426436,0.21875527758801,0.21826218091166,0.21776908423531,0.21727598755897001,0.21678289088262001,0.21628979420627001,0.21579362639114,0.21528738047009,0.21478113454903999,0.21427488862798,0.21376864270693,0.21326239678587999,0.21275615086482999,0.21224990494377999,0.21174365902273001,0.21123741310168001,0.21073116718063001,0.21022492125958001,0.20971867533853,0.20921242941748,0.20870618349643,0.20819993757538,0.20769369165432999,0.20718744573327999,0.20668119981222999,0.20616618772803999,0.20564679256228999,0.20512739739652999,0.20460800223077999,0.20408844307217999,0.20356247328407001,0.20303650349596999,0.20251053370787001,0.20198456391976,0.20146111365814001,0.20094171849237999,0.20042232332662999,0.19990292816088001,0.19938353299511999,0.19885926276926,0.19833329298114999,0.19780732319305,0.19728135340493999,0.19675472764544999,0.19622218323498999,0.19568963882453999,0.19515709441408,0.19462455000362999,0.19408899408815,0.19354987505533999,0.19301075602253001,0.19247163698972999,0.19193251795692001,0.19139339892411,0.19085427989129999,0.1903151608585,0.18977604182569,0.18923692279288001,0.18869780376008,0.18815868472726999,0.18761956569446001,0.18708044666165,0.18654132762885001,0.18600220859604,0.18546308956322999,0.18492397053043,0.18438485149761999,0.18383401443042,0.18328174615291001,0.1827294778754,0.18217720959788999,0.1816233013919,0.18106445849204,0.18050561559218001,0.17994677269232001,0.17938792979245999,0.17883707781680999,0.17829138416165,0.17774569050649999,0.17719999685134,0.17665430319618,0.17609590754953999,0.17553706464968,0.17497822174982,0.17441937884996001,0.17386053595008999,0.17330169305022999,0.17274285015037,0.17218400725051,0.17162516435065001,0.17105734656947999,0.17048535442491999,0.16991336228036,0.16934137013579001,0.16876964634316,0.16820422882095001,0.16763881129874,0.16707339377652999,0.16650797625430999,0.16594255873210001,0.16537714120989,0.16481172368767999,0.16424630616545999,0.16368088864325001,0.16311049170184,0.16253849955728,0.16196650741272001,0.16139451526814999,0.16082176279311,0.16024319602619999,0.15966462925927999,0.15908606249237001,0.15850749572545,0.15792892895853999,0.15735036219161999,0.15677179542471001,0.15619322865779001,0.15561466189088,0.15503609512395999,0.15445752835705001,0.15387896159013001,0.15330039482322,0.1527218280563,0.15214326128939001,0.15156469452247001,0.15098612775556,0.15040756098864,0.14982177853643,0.14923006252481,0.14863834651319,0.14804663050156999,0.14745491448994999,0.14686319847834001,0.14627148246672,0.1456797664551,0.14508805044348,0.14449633443186999,0.14390461842025001,0.14331290240863001,0.14272118639701001,0.1421294703854,0.14154185419497001,0.14095671280571001,0.14037157141643999,0.13978643002717001,0.13920128863791001,0.13860323653899001,0.13800494590501999,0.13740665527105,0.13680836463707999,0.13620783773701001,0.13560297248069,0.13499810722437,0.13439324196805,0.13378837671172999,0.13318810325513999,0.13258981262118,0.13199152198721001,0.13139323135323999,0.13079494071927,0.13019665008529999,0.12959835945133,0.12900006881736001,0.12840177818338999,0.12780075930477999,0.12719589404845999,0.12659102879212999,0.12598616353580999,0.12538129827948999,0.12477134924489,0.12415990936622,0.12354846948754999,0.12293702960888001,0.12232558973021,0.12171414985154,0.12110270997286,0.12049127009419,0.11987983021552,0.11927161056004,0.11866674530372,0.11806188004739999,0.11745701479108001,0.11685214953476,0.11624170852162,0.11563026864294999,0.11501882876427,0.11440738888559999,0.11379594900693001,0.11318450912826,0.11257306924959,0.11196162937092,0.11135018949224,0.1107313252101,0.11010673608672999,0.10948214696335,0.10885755783998,0.10823296871661001,0.1076144473286,0.10699643282757999,0.10637841832655,0.10576040382552999,0.10514423797115,0.10453279809248001,0.10392135821381,0.10330991833514,0.10269847845647,0.10207863021723999,0.10145404109386,0.10082945197048999,0.10020486284712,0.099580273723741994,0.098955684600367994,0.098331095476993993,0.097706506353620007,0.097081917230244993,0.096457328106870993,0.095832738983497007,0.095208149860123006,0.094583560736749006,0.093958971613375006,0.093334382490001006,0.092709793366626006,0.092085204243252006,0.091460615119878005,0.090836025996504005,0.090211436873130005,0.089586847749756005,0.088962258626382004,0.088337669503007005,0.087710247775899003,0.087079084030174003,0.086447920284448004,0.085816756538723005,0.085185592792997006,0.084549240909905996,0.083911502541828997,0.083273764173752998,0.082636025805676,0.081999256486244995,0.081368092740519996,0.080736928994793997,0.080105765249068997,0.079474601503342998,0.078846762339895002,0.078222173216521002,0.077597584093147001,0.076972994969773001,0.076348405846399001,0.075712456491207003,0.075074718123130005,0.074436979755053007,0.073799241386975994,0.073161503018899995,0.072523764650822997,0.071886026282745999,0.071248287914669001,0.070610549546593002,0.069972811178516003,0.069335072810439005,0.068697334442362007,0.068059596074285994,0.067421857706208996,0.066790291432583998,0.066159127686858998,0.065527963941132999,0.064896800195408,0.064263683443950004,0.063625945075873006,0.062988206707795993,0.062350468339720001,0.061712729971643003,0.061070683064201998,0.060426370073774001,0.059782057083346003,0.059137744092917999,0.058493431102490001,0.057849118112061997,0.057204805121633999,0.056560492131206001,0.055916179140777997,0.055274311134624998,0.054636572766548999,0.053998834398472001,0.053361096030395003,0.052723357662317998,0.052085619294241998,0.051447880926165,0.050810142558088002,0.050172404190010997,0.049533502963558997,0.04888261535078,0.048231727738001003,0.047580840125220999,0.046929952512442002,0.046282001862481999,0.045637688872054001,0.044993375881625997,0.044349062891197999,0.043704749900769002,0.043060436910340998,0.042416123919913,0.041771810929485002,0.041127497939056998,0.040484258356359999,0.039846519988283001,0.039208781620206003,0.038571043252129997,0.037933304884052998,0.037288708633250997,0.036637821020472,0.035986933407693003,0.035336045794913,0.034685158182134003,0.034034270569354999,0.033383382956575003,0.032732495343795999,0.032081607731016003,0.031432285504511,0.030787972514082999,0.030143659523655001,0.029499346533227,0.028855033542798999,0.028210720552371001,0.027566407561943,0.026922094571514999,0.026277781581087001,0.025633468590659,0.024989155600230999,0.024344842609801999,0.023700529619374001,0.023056216628946,0.022409846273701,0.021758958660922,0.021108071048142,0.020457183435362999,0.019806295822583,0.019150995311355001,0.018493533076223999,0.017836070841093999,0.017178608605963,0.016521533990291,0.015877220999862999,0.015232908009435,0.014588595019005999,0.013944282028578,0.013299969038150001,0.012655656047721999,0.012011343057294,0.011367030066866001,0.010722717076438,0.010073499209018,0.0094226115962383998,0.0087717239834590004,0.0081208363706796998,0.0074699487579003004,0.0068190611451209001,0.0061681735323414998,0.0055172859195622001,0.0048663983067827998,0.0042155106940034003,0.0035646230812241002,0.0029137354684446999,0.0022628478556653,0.0016119602428858999,0.00096646948564212999,0.00032215649521400997,-0.00032215649521400997,-0.00096646948564204,-0.0016119602428858999,-0.0022628478556653,-0.0029137354684446999,-0.003564623081224,-0.0042155106940034003,-0.0048663983067827998,-0.0055172859195621003,-0.0061681735323414998,-0.0068190611451209001,-0.0074699487579003004,-0.0081208363706795992,-0.0087717239834590004,-0.0094226115962383998,-0.010073499209018,-0.010722717076438,-0.011367030066866001,-0.012011343057294,-0.012655656047721999,-0.013299969038150001,-0.013944282028578,-0.014588595019005999,-0.015232908009435,-0.015877220999862999,-0.016521533990291,-0.017178608605963,-0.017836070841093999,-0.018493533076223999,-0.019150995311355001,-0.019806295822583,-0.020457183435362999,-0.021108071048142,-0.021758958660921,-0.022409846273701,-0.023056216628946,-0.023700529619374001,-0.024344842609801999,-0.02498915560023,-0.025633468590659,-0.026277781581087001,-0.026922094571514999,-0.027566407561943,-0.028210720552371001,-0.028855033542798999,-0.029499346533227,-0.030143659523655001,-0.030787972514082999,-0.031432285504511,-0.032081607731016003,-0.032732495343795999,-0.033383382956575003,-0.034034270569354,-0.034685158182134003,-0.035336045794913,-0.035986933407693003,-0.036637821020472,-0.037288708633250997,-0.037933304884052998,-0.038571043252129997,-0.039208781620206003,-0.039846519988283001,-0.040484258356359999,-0.041127497939056998,-0.041771810929485002,-0.042416123919913,-0.043060436910340998,-0.043704749900769002,-0.044349062891197,-0.044993375881625997,-0.045637688872054001,-0.046282001862481999,-0.046929952512442002,-0.047580840125220999,-0.048231727738001003,-0.04888261535078,-0.049533502963558997,-0.050172404190010997,-0.050810142558088002,-0.051447880926165,-0.052085619294241998,-0.052723357662317998,-0.053361096030395003,-0.053998834398472001,-0.054636572766548999,-0.055274311134624998,-0.055916179140777997,-0.056560492131206001,-0.057204805121633999,-0.057849118112061997,-0.058493431102490001,-0.059137744092917999,-0.059782057083346003,-0.060426370073774001,-0.061070683064201998,-0.061712729971643003,-0.062350468339720001,-0.062988206707795993,-0.063625945075873006,-0.064263683443950004,-0.064896800195408,-0.065527963941132999,-0.066159127686858998,-0.066790291432583998,-0.067421857706208996,-0.068059596074284995,-0.068697334442362007,-0.069335072810439005,-0.069972811178516003,-0.070610549546593002,-0.071248287914669001,-0.071886026282745999,-0.072523764650822997,-0.073161503018899995,-0.073799241386975994,-0.074436979755053007,-0.075074718123130005,-0.075712456491207003,-0.076348405846399001,-0.076972994969773001,-0.077597584093147001,-0.078222173216521002,-0.078846762339895002,-0.079474601503342998,-0.080105765249068997,-0.080736928994793997,-0.081368092740519996,-0.081999256486244995,-0.082636025805676,-0.083273764173752998,-0.083911502541828997,-0.084549240909905996,-0.085185592792997006,-0.085816756538723005,-0.086447920284448004,-0.087079084030174003,-0.087710247775899003,-0.088337669503007005,-0.088962258626382004,-0.089586847749756005,-0.090211436873130005,-0.090836025996504005,-0.091460615119878005,-0.092085204243252006,-0.092709793366626006,-0.093334382490001006,-0.093958971613375006,-0.094583560736749006,-0.095208149860123006,-0.095832738983497007,-0.096457328106870993,-0.097081917230244993,-0.097706506353620007,-0.098331095476993993,-0.098955684600367994,-0.099580273723741994,-0.10020486284712,-0.10082945197048999,-0.10145404109386,-0.10207863021723999,-0.10269847845647,-0.10330991833514,-0.10392135821381,-0.10453279809248001,-0.10514423797115,-0.10576040382552999,-0.10637841832655,-0.10699643282757999,-0.1076144473286,-0.10823296871661001,-0.10885755783998,-0.10948214696335,-0.11010673608672999,-0.1107313252101,-0.11135018949224,-0.11196162937092,-0.11257306924959,-0.11318450912826,-0.11379594900693001,-0.11440738888559999,-0.11501882876427,-0.11563026864294999,-0.11624170852162,-0.11685214953476,-0.11745701479108001,-0.11806188004739999,-0.11866674530372,-0.11927161056004,-0.11987983021552,-0.12049127009419,-0.12110270997286,-0.12171414985154,-0.12232558973021,-0.12293702960888001,-0.12354846948754999,-0.12415990936622,-0.12477134924489,-0.12538129827948999,-0.12598616353580999,-0.12659102879212999,-0.12719589404845999,-0.12780075930477999,-0.12840177818338999,-0.12900006881736001,-0.12959835945133,-0.13019665008529999,-0.13079494071927,-0.13139323135323999,-0.13199152198721001,-0.13258981262118,-0.13318810325513999,-0.13378837671172999,-0.13439324196805,-0.13499810722437,-0.13560297248069,-0.13620783773701001,-0.13680836463707999,-0.13740665527105,-0.13800494590501999,-0.13860323653899001,-0.13920128863791001,-0.13978643002717001,-0.14037157141643999,-0.14095671280571001,-0.14154185419497001,-0.1421294703854,-0.14272118639701001,-0.14331290240863001,-0.14390461842025001,-0.14449633443186999,-0.14508805044348,-0.1456797664551,-0.14627148246672,-0.14686319847834001,-0.14745491448994999,-0.14804663050156999,-0.14863834651319,-0.14923006252481,-0.14982177853643,-0.15040756098864,-0.15098612775556,-0.15156469452247001,-0.15214326128939001,-0.1527218280563,-0.15330039482322,-0.15387896159013001,-0.15445752835705001,-0.15503609512395999,-0.15561466189088,-0.15619322865779001,-0.15677179542471001,-0.15735036219161999,-0.15792892895853999,-0.15850749572545,-0.15908606249237001,-0.15966462925927999,-0.16024319602619999,-0.16082176279311,-0.16139451526814999,-0.16196650741272001,-0.16253849955728,-0.16311049170184,-0.16368088864325001,-0.16424630616545999,-0.16481172368767999,-0.16537714120989,-0.16594255873210001,-0.16650797625430999,-0.16707339377652999,-0.16763881129874,-0.16820422882095001,-0.16876964634316,-0.16934137013579001,-0.16991336228036,-0.17048535442491999,-0.17105734656947999,-0.17162516435065001,-0.17218400725051,-0.17274285015037,-0.17330169305022999,-0.17386053595008999,-0.17441937884996001,-0.17497822174982,-0.17553706464968,-0.17609590754953999,-0.17665430319618,-0.17719999685134,-0.17774569050649999,-0.17829138416165,-0.17883707781680999,-0.17938792979245999,-0.17994677269232001,-0.18050561559218001,-0.18106445849204,-0.1816233013919,-0.18217720959788999,-0.1827294778754,-0.18328174615291001,-0.18383401443042,-0.18438485149761999,-0.18492397053043,-0.18546308956322999,-0.18600220859604,-0.18654132762885001,-0.18708044666165,-0.18761956569446001,-0.18815868472726999,-0.18869780376008,-0.18923692279288001,-0.18977604182569,-0.1903151608585,-0.19085427989129999,-0.19139339892411,-0.19193251795692001,-0.19247163698972999,-0.19301075602253001,-0.19354987505533999,-0.19408899408815,-0.19462455000362999,-0.19515709441408,-0.19568963882453999,-0.19622218323498999,-0.19675472764544999,-0.19728135340493999,-0.19780732319305,-0.19833329298114999,-0.19885926276926,-0.19938353299511999,-0.19990292816088001,-0.20042232332662999,-0.20094171849237999,-0.20146111365814001,-0.20198456391976,-0.20251053370787001,-0.20303650349596999,-0.20356247328407001,-0.20408844307217999,-0.20460800223077999,-0.20512739739652999,-0.20564679256228999,-0.20616618772803999,-0.20668119981222999,-0.20718744573327999,-0.20769369165432999,-0.20819993757538,-0.20870618349643,-0.20921242941748,-0.20971867533853,-0.21022492125958001,-0.21073116718063001,-0.21123741310168001,-0.21174365902273001,-0.21224990494377999,-0.21275615086482999,-0.21326239678587999,-0.21376864270693,-0.21427488862798,-0.21478113454903999,-0.21528738047009,-0.21579362639114,-0.21628979420627001,-0.21678289088262001,-0.21727598755897001,-0.21776908423531,-0.21826218091166,-0.21875527758801,-0.21924837426436,-0.21974147094071,-0.22023456761704999,-0.22072448879553,-0.22121101084952999,-0.22169753290352001,-0.22218405495752,-0.22267057701151999,-0.22315709906552,-0.22364362111951,-0.22413014317350999,-0.22461666522751,-0.22510187533872,-0.22558182277037001,-0.22606177020200999,-0.22654171763365999,-0.2270216650653,-0.22749794502053,-0.22797131782982999,-0.22844469063912001,-0.22891806344842,-0.22939143625771,-0.22985878605696,-0.23032558424390001,-0.23079238243083999,-0.23125918061778999,-0.23172597880473,-0.23219277699167001,-0.23265957517861,-0.23312637336556,-0.23359317155250001,-0.23405996973943999,-0.23452676792638999,-0.23499356611333,-0.23546036430027001,-0.23592716248720999,-0.23638093069697999,-0.23683457963922,-0.23728822858146001,-0.23774187752369999,-0.23819323056607,-0.23864030488596,-0.23908737920584999,-0.23953445352573999,-0.23998152784563001,-0.24042860216552001,-0.24087567648541,-0.24132275080529,-0.24176982512518,-0.24221689944506999,-0.24266397376495999,-0.24311104808485001,-0.24355812240474001,-0.24400519672463,-0.24444948316609999,-0.24488998286364,-0.24533048256118001,-0.24577098225871999,-0.24621148195625001,-0.24664169482970999,-0.24706904528254001,-0.24749639573537,-0.24792374618821,-0.24835017231772,-0.2487709481482,-0.24919172397868999,-0.24961249980917,-0.25003327563965999,-0.25045733132709003,-0.25088468177993001,-0.25131203223276,-0.25173938268559998,-0.25216673313843002,-0.25258844820067999,-0.25300922403116999,-0.25342999986164999,-0.25385077569212999,-0.25426871891887998,-0.25467634550466001,-0.25508397209043998,-0.25549159867623,-0.25589922526200998,-0.25630308001229002,-0.25670413197572001,-0.25710518393914999,-0.25750623590257998,-0.25790728786601003,-0.25830833982944001,-0.25870939179287,-0.25911044375629999,-0.25951149571972998,-0.25991254768316002,-0.26031359964659001,-0.26071465161002,-0.26111570357344999,-0.26151675553687997,-0.26190927987222001,-0.26229718259094997,-0.26268508530967999,-0.26307298802840001,-0.26346080129649002,-0.26383555477051002,-0.26421030824453001,-0.26458506171856,-0.26495981519257999,-0.26533456866660998,-0.26570932214062998,-0.26608407561466002,-0.26645882908868002,-0.26683358256271,-0.26720833603673,-0.26758308951075999,-0.26795784298477998,-0.26833259645879998,-0.26870681322896001,-0.26907499208064001,-0.26944317093231002,-0.26981134978398003,-0.27017952863566003,-0.27054192301233998,-0.27089695261931002,-0.27125198222628,-0.27160701183324998,-0.27196204144022001,-0.27231182327606002,-0.27266027826068001,-0.27300873324530001,-0.27335718822992,-0.27370564321454,-0.27405409819915999,-0.27440255318376999,-0.27475100816838999,-0.27509946315300998,-0.27544453392159002,-0.27578641428386003,-0.27612829464612998,-0.27647017500839999,-0.27681205537066,-0.27714819598326002,-0.27748350172317998,-0.27781880746309001,-0.27815411320300998,-0.27848485696007003,-0.27880043883292999,-0.27911602070579999,-0.27943160257866001,-0.27974718445152003,-0.28006664251897001,-0.28038879901418001,-0.28071095550940001,-0.28103311200461001,-0.28135526849982001,-0.28167742499504,-0.28199958149025001,-0.28232173798547,-0.28264389448068,-0.28296001305740998,-0.28326244568557002,-0.28356487831373001,-0.28386731094188999,-0.28416974357004998,-0.28446780802507998,-0.28476366603088998,-0.28505952403669998,-0.28535538204250999,-0.28565109096391,-0.28594037434737002,-0.28622965773082998,-0.28651894111428,-0.28680822449774002,-0.28709750788119998,-0.28738679126465999,-0.28767607464811001,-0.28796535803156997,-0.28825464141502999,-0.28853906464682,-0.28882177340791998,-0.28910448216903001,-0.28938719093012999,-0.28966797650239001,-0.28993096139643998,-0.29019394629049,-0.29045693118455002,-0.29071991607859998,-0.29097990437607002,-0.29123631464777,-0.29149272491946998,-0.29174913519117002,-0.29200554546287,-0.29226730786478999,-0.29253029275884002,-0.29279327765288998,-0.29305626254694001,-0.29331698135800999,-0.29356681700735998,-0.29381665265670998,-0.29406648830606003,-0.29431632395541002,-0.29455918245451002,-0.29479586885914999,-0.29503255526380001,-0.29526924166844998,-0.29550592807309001,-0.29573092626023001,-0.29595446342017001,-0.29617800058012,-0.29640153774006001,-0.29662507490001,-0.29684861205995,-0.29707214921989,-0.29729568637984,-0.29751922353978,-0.29774276069972999,-0.29796629785966999,-0.29818983501961999,-0.29841337217955999,-0.29863690933950998,-0.29884777432484999,-0.29905816224009002,-0.29926855015532999,-0.29947893807058001,-0.29968297499008001,-0.29987363903825998,-0.30006430308644999,-0.30025496713464001,-0.30044563118283002,-0.30063182269880001,-0.30081591212463998,-0.30100000155048001,-0.30118409097630999,-0.30136843384563999,-0.30155909789383001,-0.30174976194202002,-0.30194042599020998,-0.30213109003839,-0.30231653613234,-0.30249405093581999,-0.30267156573930998,-0.30284908054278997,-0.30302659534628001,-0.30318921661749998,-0.30334700755393001,-0.30350479849035999,-0.30366258942678998,-0.30381888951914998,-0.30396353121087999,-0.30410817290261,-0.30425281459434,-0.30439745628607001,-0.30454519893345999,-0.30469641524753999,-0.30484763156161998,-0.30499884787569997,-0.30515006418978002,-0.30529582401456001,-0.30544046570629002,-0.30558510739801997,-0.30572974908974998,-0.30587067857973999,-0.30599559640441998,-0.30612051422908998,-0.30624543205376997,-0.30637034987843997,-0.30648448890049002,-0.30658968285811,-0.30669487681572999,-0.30680007077334998,-0.30690526473097002,-0.30701045868859,-0.30711565264620999,-0.30722084660382998,-0.30732604056145002,-0.30743123451908,-0.30753642847669999,-0.30764162243431997,-0.30774681639194001,-0.30785201034956,-0.30794903448166999,-0.30804107919459001,-0.30813312390751002,-0.30822516862042998,-0.30831721333334999,-0.30838349626071998,-0.30844924248423999,-0.30851498870775002,-0.30858073493125998,-0.30864648115477999,-0.30871222737829002,-0.30877797360179998,-0.30884371982532,-0.30890946604883002,-0.30897063538105002,-0.30902980698221,-0.30908897858336998,-0.30914815018453001,-0.30920696398311998,-0.30925956096193002,-0.30931215794074002,-0.30936475491955001,-0.30941735189836,-0.30945909553232998,-0.30948539402174002,-0.30951169251114002,-0.30953799100055002,-0.30956428948995002,-0.30958551910951998,-0.30960524297656999,-0.30962496684363,-0.30964469071068002,-0.30966356479661999,-0.30967671404132002,-0.30968986328602,-0.30970301253072002,-0.30971616177542999,-0.30972610570538001,-0.30973268032772999,-0.30973925495007998,-0.30974582957243002,-0.30975240419478001,-0.30974229627198002,-0.30972914702727999,-0.30971599778258002,-0.30970284853787999,-0.30968567401418001,-0.30965280090243003,-0.30961992779066999,-0.30958705467891001,-0.30955418156716002,-0.30951761116210003,-0.309478163428,-0.30943871569388998,-0.30939926795978001,-0.30935982022566999,-0.30932037249157002,-0.30928092475746,-0.30924147702334998,-0.30920202928924001,-0.30915891407871998,-0.30910631709990999,-0.3090537201211,-0.30900112314229,-0.30894852616348001,-0.30887917209730997,-0.30880027662909998,-0.30872138116087999,-0.30864248569267,-0.30856359022445001,-0.30847160514529998,-0.30837956043238002,-0.30828751571946,-0.30819547100653999,-0.30810110057687001,-0.30800248124160001,-0.30790386190633001,-0.30780524257106001,-0.30770662323579001,-0.30760800390053,-0.30750938456526,-0.30741076522999,-0.30731214589472,-0.30721121575114002,-0.30707972330410999,-0.30694823085709,-0.30681673841006002,-0.30668524596302998,-0.30654530043013001,-0.30639408411605001,-0.30624286780197002,-0.30609165148789003,-0.30594043517380998,-0.30578921885972998,-0.30563800254564999,-0.30548678623157,-0.30533556991749,-0.3051833994632,-0.30502560852677002,-0.30486781759033998,-0.30471002665391,-0.30455223571748002,-0.30438451575953002,-0.30420700095605002,-0.30402948615255998,-0.30385197134907999,-0.30367445654559,-0.30346861570477002,-0.30325822778952,-0.30304783987428002,-0.30283745195903999,-0.30262561792504999,-0.30240865538745998,-0.30219169284986003,-0.30197473031227001,-0.30175776777468,-0.30153700358469998,-0.30131346642475998,-0.30108992926481998,-0.30086639210486998,-0.30064285494492998,-0.30040700341296001,-0.30017031700830998,-0.29993363060367001,-0.29969694419901999,-0.29945250540520002,-0.29918952051115,-0.29892653561709998,-0.29866355072305001,-0.29840056582899999,-0.29812040641124998,-0.29783112302779002,-0.29754183964433001,-0.29725255626087999,-0.29696327287742003,-0.29667398949396001,-0.2963847061105,-0.29609542272704997,-0.29580613934359001,-0.29551199580845999,-0.29520956318030001,-0.29490713055214002,-0.29460469792397997,-0.29430226529581999,-0.2939806902298,-0.29365195911223002,-0.29332322799465999,-0.2929944968771,-0.29266349967654998,-0.29230847006958,-0.29195344046261001,-0.29159841085562999,-0.29124338124866,-0.29088250753293998,-0.29051432868125998,-0.29014614982959003,-0.28977797097792002,-0.28940979212624002,-0.28903633568656001,-0.28866158221254001,-0.28828682873851003,-0.28791207526448998,-0.28753414629259,-0.28713966895151,-0.28674519161043999,-0.28635071426935998,-0.28595623692827998,-0.28554127538967,-0.28510735031447998,-0.2846734252393,-0.28423950016410998,-0.28380557508893001,-0.28335434131407999,-0.28290069237184001,-0.28244704342959998,-0.28199339448735999,-0.28153974554512001,-0.28108609660287998,-0.28063244766063999,-0.28017879871840001,-0.27972514977615998,-0.27925978279952002,-0.27878640999023002,-0.27831303718094003,-0.27783966437163998,-0.27736629156234999,-0.27686161102757001,-0.27635536510651998,-0.27584911918547,-0.27534287326441997,-0.27482437260511,-0.27427867894995001,-0.27373298529479001,-0.27318729163963001,-0.27264159798447002,-0.27209150633931001,-0.27153923806180003,-0.27098696978428999,-0.27043470150678001,-0.26988225432798002,-0.26932341142812,-0.26876456852825997,-0.2682057256284,-0.26764688272853998,-0.26707536765406997,-0.26648365164246002,-0.26589193563084002,-0.26530021961922001,-0.26470850360760001,-0.26408255781612999,-0.26344481944804998,-0.26280708107996997,-0.26216934271190001,-0.26152959170432,-0.26087212946918997,-0.26021466723406,-0.25955720499892998,-0.25889974276380001,-0.25823925411520998,-0.25757521725771998,-0.25691118040024002,-0.25624714354276001,-0.25558310668528,-0.25489754203942,-0.25420720669253,-0.25351687134563999,-0.25282653599875998,-0.25212806064324,-0.25139170293989999,-0.25065534523654998,-0.24991898753319999,-0.24918262982986,-0.24842516177446999,-0.24764935633702001,-0.24687355089956001,-0.24609774546211,-0.24532194002464999,-0.24454026066156001,-0.24375788060176001,-0.24297550054195,-0.24219312048215,-0.24140743074849999,-0.24061190144399999,-0.23981637213949,-0.23902084283498001,-0.23822531353047,-0.23739369089101001,-0.23653898998534001,-0.23568428907967001,-0.23482958817399999,-0.23397488726832999,-0.23306925912921,-0.23216196124472999,-0.23125466336025,-0.23034736547577001,-0.22943577396036999,-0.22851532683119,-0.22759487970200001,-0.22667443257281999,-0.22575398544364,-0.22482453361627,-0.22389093724237999,-0.2229573408685,-0.22202374449460999,-0.22108816529811001,-0.22010854656777001,-0.21912892783742,-0.21814930910708,-0.21716969037673001,-0.21616104491233001,-0.21510910533611999,-0.21405716575992001,-0.21300522618371001,-0.21195328660750001,-0.21087637539310999,-0.20979156270513999,-0.20870675001717001,-0.20762193732921,-0.20653557416341001,-0.20543761223074,-0.20433965029807,-0.20324168836541001,-0.20214372643274001,-0.20103011063733001,-0.19989927559289999,-0.19876844054848,-0.19763760550404999,-0.19650677045963,-0.19531009974104999,-0.19410036922841001,-0.19289063871577,-0.19168090820312,-0.19045723829842001,-0.18917518693992,-0.18789313558142001,-0.18661108422291001,-0.18532903286440999,-0.18403611325263,-0.18273433802707001,-0.18143256280150999,-0.18013078757595,-0.17882901235039,-0.17750930227066,-0.17618780317805,-0.17486630408543999,-0.17354480499281999,-0.17219867715616999,-0.17078513335063999,-0.16937158954510001,-0.16795804573956999,-0.16654450193404,-0.16506512245435001,-0.1635463846912,-0.16202764692805,-0.16050890916489999,-0.15899017140175001,-0.15742614179573,-0.15586138167611999,-0.15429662155651,-0.15273186143690001,-0.15116259896819001,-0.14958468960387999,-0.14800678023957001,-0.14642887087525,-0.14485096151094001,-0.14321316494031,-0.14154978548543001,-0.13988640603055,-0.13822302657567001,-0.13655073187323999,-0.13473613610428001,-0.13292154033532,-0.13110694456635999,-0.12929234879740001,-0.12743111942591001,-0.12550475507698,-0.12357839072805001,-0.12165202637911,-0.11972566203017999,-0.11778400162108001,-0.1158379134051,-0.11389182518910999,-0.11194573697312001,-0.10998909358112,-0.10796410989690999,-0.10593912621271,-0.10391414252851,-0.10188915884431,-0.099754180684577004,-0.097505659840429998,-0.095257138996283006,-0.093008618152135999,-0.090760097307988993,-0.088304721849048001,-0.085812939977902,-0.083321158106756998,-0.080829376235610997,-0.078319763869381998,-0.075742511907669993,-0.073165259945958003,-0.070588007984245998,-0.068010756022532995,-0.065392505848879998,-0.062742933041303003,-0.060093360233727001,-0.057443787426149001,-0.054794214618572999,-0.051737104675859999,-0.048647032170746,-0.045556959665632002,-0.042466887160516997,-0.039128961828667,-0.035164464550829,-0.031199967272991,-0.027235469995153999,-0.023270972717315,-0.018829718414143,-0.014122288810607,-0.0094148592070719996,-0.0047074296035354004,0.0,0.0,0.050716636817980998,0.10143327363596,0.15214991045394,0.20286654727191999,0.24343318967162,0.26581977877781998,0.28820636788401999,0.31059295699021999,0.33297954609642,0.33555138629415998,0.33028511379075998,0.32501884128736003,0.31975256878397001,0.31414929097840999,0.30437940216436998,0.29460951335032998,0.28483962453629003,0.27506973572225002,0.27011498999583999,0.27146278757786002,0.27281058515987999,0.27415838274189003,0.27550618032391,0.28122973942907997,0.28810679440855003,0.29498384938800998,0.30186090436747998,0.30786420545406001,0.30890299578556002,0.30994178611707002,0.31098057644858002,0.31201936678008002,0.31030641675984999,0.30592771827387999,0.30154901978790999,0.29717032130193999,0.29279162281596999,0.29097568528735002,0.28955556685946998,0.28813544843158001,0.28671533000369998,0.28640659110512001,0.28993716330778002,0.29346773551042998,0.29699830771308,0.30052887991573002,0.30343492262876998,0.30589383138816001,0.30835274014754999,0.31081164890694002,0.31327055766633,0.31165841852214998,0.30979122577438001,0.30792403302660998,0.30605684027884,0.30411880262083002,0.30201492346841002,0.29991104431600002,0.29780716516358002,0.29570328601116003,0.29596433280792001,0.29745677208166998,0.29894921135541003,0.30044165062916001,0.30195214402460002,0.30458199296512001,0.30721184190564998,0.30984169084617003,0.31247153978669001,0.31404609475185002,0.31385543070366001,0.31366476665547,0.31347410260727998,0.31328343855910001,0.31182150195503,0.30989513760609999,0.30796877325716998,0.30604240890822998,0.30429912021117,0.30439116492409002,0.30448320963700998,0.30457525434992999,0.30466729906284001,0.30569508696511,0.30787128696339,0.31004748696167,0.31222368695996,0.31439988695824,0.31555706521739002,0.31647093772422003,0.31738481023104997,0.31829868273789003,0.31884688101108,0.31755168040788001,0.31625647980466998,0.31496127920146,0.31366607859825002,0.3126567175287,0.31190721058065002,0.31115770363259998,0.31040819668455,0.30965868973650001,0.31081138055500002,0.31221834973818002,0.31362531892135997,0.31503228810453998,0.31645506023487002,0.31792777564156,0.31940049104826002,0.32087320645494999,0.32234592186164002,0.32264576042111998,0.32215923836712002,0.32167271631312999,0.32118619425912998,0.32069967220513002,0.31964063621115002,0.31855582352318002,0.31747101083522,0.31638619814725,0.31582359832033002,0.31639559046490001,0.31696758260946001,0.31753957475402,0.31811156689858999,0.31934330226971003,0.32089491314461999,0.32244652401953,0.32399813489443002,0.32550946316254997,0.32579217192366,0.32607488068476997,0.32635758944587001,0.32664029820697998,0.32643067062220998,0.32545105189187001,0.32447143316152,0.32349181443118002,0.32251219570084,0.32215738972048003,0.32201274802875002,0.32186810633702001,0.32172346464529,0.32172947274689001,0.32299837486069999,0.32426727697449997,0.32553617908830002,0.3268050812021,0.32787838457384,0.32872651085715998,0.32957463714048002,0.3304227634238,0.33127088970711999,0.33093383967964002,0.33034212366802002,0.32975040765640001,0.32915869164479,0.32856578295791,0.32796749232394001,0.32736920168997002,0.32677091105599998,0.32617262042203998,0.32630880902788001,0.32707146522064001,0.32783412141339002,0.32859677760613998,0.32935943379888999,0.3304408920877,0.33155857788741999,0.33267626368713998,0.33379394948685998,0.33460671294882999,0.33453439210295999,0.33446207125709998,0.33438975041122998,0.33431742956536997,0.33383300960151002,0.33309007727582002,0.33234714495012002,0.33160421262442002,0.33086128029871997,0.33103933180606998,0.33124314509896002,0.33144695839185001,0.33165077168474,0.33214625371161,0.33323106639957001,0.33431587908754001,0.33540069177550003,0.33648550446346998,0.33711256838800002,0.33753334421848002,0.33795412004897002,0.33837489587945002,0.33874651858093002,0.33813507870225001,0.33752363882358,0.33691219894490998,0.33630075906624002,0.33583075556455,0.33556777067048998,0.33530478577644002,0.33504180088239,0.33477881598833997,0.33533979079522003,0.33615504396677998,0.33697029713833998,0.33778555030989998,0.33859355797927998,0.33934963954968,0.34010572112007997,0.34086180269048,0.34161788426088002,0.34187143211197002,0.34158214872851,0.34129286534505998,0.34100358196160002,0.34071429857814001,0.34022091864142001,0.33968837423095999,0.33915582982051001,0.33862328541004999,0.33827362284173002,0.33866810018281002,0.33906257752389002,0.33945705486497002,0.33985153220605002,0.34051629957712998,0.3413972989722,0.34227829836728002,0.34315929776234999,0.34404029715743001,0.34421234056317002,0.34431753452079,0.34442272847840999,0.34452792243602998,0.34444705905364997,0.34386849228673,0.34328992551982002,0.34271135875289999,0.34213279198599,0.34190236712644001,0.34187606863703002,0.34184977014762002,0.34182347165822002,0.34179717316880998,0.34255738437729,0.34332661519238999,0.34409584600749998,0.34486507682259998,0.34552482004916002,0.3459784689914,0.34643211793363998,0.34688576687588002,0.34733941581812,0.34717640692744001,0.34675563109696,0.34633485526647001,0.34591407943599001,0.34549747796890001,0.34514244836192998,0.34478741875496,0.34443238914799001,0.34407735954101998,0.34408004306035,0.34457313973670001,0.34506623641304002,0.34555933308939002,0.34605242976574002,0.34666861052856002,0.34731949814133001,0.34797038575410999,0.34862127336689003,0.34916303119371001,0.34902496412432998,0.34888689705495002,0.34874882998557,0.34861076291620002,0.34828659378149002,0.34777377323808001,0.34726095269467999,0.34674813215127998,0.34623531160788001,0.34627329831480003,0.34640479076182001,0.34653628320884999,0.34666777565587997,0.34691418236386001,0.3475847938437,0.34825540532353,0.34892601680336,0.34959662828319998,0.34998547023368998,0.35016298503717003,0.35034049984066001,0.35051801464414001,0.35069552944762999,0.35024957326078998,0.34975647658445003,0.34926337990810002,0.34877028323175002,0.34836049492207,0.34815668162918001,0.34795286833627997,0.34774905504338999,0.3475452417505,0.34780455916814002,0.34831737971153998,0.34883020025494998,0.34934302079835,0.34985542390541002,0.35027619973589003,0.35069697556638002,0.35111775139686002,0.35153852722734003,0.35168975844986999,0.35136760195465,0.35104544545944,0.35072328896422,0.35040113246901,0.34999838094334002,0.34956445586814999,0.34913053079297002,0.34869660571777999,0.34831590377590999,0.34855259018056001,0.34878927658520997,0.34902596298985999,0.34926264939450002,0.34962593827762001,0.35015190806572999,0.35067787785382998,0.35120384764194001,0.35172981743004,0.35178482957625001,0.35171908335273,0.35165333712921998,0.35158759090571001,0.35145290805237001,0.35094008750896999,0.35042726696556997,0.34991444642217001,0.34940162587876,0.34911117963693,0.34903228416871002,0.34895338870050002,0.34887449323227998,0.34879559776406999,0.34919186411802999,0.34965866230497,0.35012546049192,0.35059225867886001,0.35099430950782001,0.35117839893364999,0.35136248835949002,0.35154657778532999,0.35173066721115998,0.35154407316729003,0.35109699884739998,0.35064992452750998,0.35020285020761999,0.34975577588772999,0.34940195386445999,0.34905349887984,0.34870504389522,0.34835658891060001,0.34819991610722001,0.34848262486832998,0.34876533362943002,0.34904804239053999,0.34933075115165002,0.34965263929493001,0.34999451965720002,0.35033640001945998,0.35067828038172999,0.35100781655509999,0.35074483166103998,0.35048184676699001,0.35021886187293999,0.34995587697889002,0.34960077282971003,0.34909452690866,0.34858828098761002,0.34808203506655999,0.34757578914551002,0.34744747219635003,0.34745404681871001,0.34746062144105999,0.34746719606340998,0.34750883533830002,0.34788358881232001,0.34825834228635,0.34863309576036999,0.34900784923439998,0.34919475635552999,0.34915530862142002,0.34911586088731,0.34907641315319998,0.34903696541910001,0.34860256327381001,0.34807659348570003,0.34755062369759998,0.34702465390949,0.34654229131045,0.34627273179404999,0.34600317227764998,0.34573361276123998,0.34546405324483997,0.34548280806324999,0.34575894220199999,0.34603507634075997,0.34631121047951002,0.34658734461827001,0.34674689475069997,0.34689153644242998,0.34703617813415999,0.34718081982589,0.34718538180873998,0.34675803135590999,0.34633068090307001,0.34590333045024002,0.34547597999739998,0.34502087002797999,0.34454749721868,0.34407412440939,0.34360075160009002,0.34312737879080002,0.34316602146911002,0.34322519307027,0.34328436467142998,0.34334353627259001,0.34346156639766001,0.34370482742466002,0.34394808845165997,0.34419134947865998,0.34443461050565999,0.34434354974982001,0.34409371410047002,0.34384387845113001,0.34359404280178002,0.34333275746996,0.34276733994774999,0.34220192242553998,0.34163650490332997,0.34107108738111003,0.34065093770513999,0.34045369903459999,0.34025646036405999,0.34005922169351999,0.33986198302297999,0.33997656929824999,0.34019353183584,0.34041049437344001,0.34062745691103002,0.34081373787765001,0.34075456627648998,0.34069539467533,0.34063622307416003,0.34057705147299999,0.34028951237711003,0.33974381872194998,0.33919812506678998,0.33865243141162998,0.33810673775646999,0.33765899255675003,0.33723164210391998,0.33680429165108,0.33637694119825001,0.33604250014789,0.33611482099376,0.33618714183962001,0.33625946268548002,0.33633178353135001,0.33640768240298002,0.33648657787120001,0.33656547333941,0.33664436880762999,0.33672326427584998,0.33634527567019001,0.33591792521734998,0.33549057476451999,0.33506322431168001,0.33459644103317998,0.33401787426627,0.33343930749935002,0.33286074073243999,0.33228217396552001,0.33197222748325,0.33182758579152,0.33168294409978999,0.33153830240805998,0.33139366071632997,0.33150604054236998,0.33162438374469,0.33174272694702001,0.33186107014934002,0.33185364574587001,0.33159723547417003,0.33134082520246999,0.33108441493077001,0.33082800465906997,0.33031156136457002,0.32968039761884999,0.32904923387312002,0.32841807012739999,0.32779993635885002,0.32741860826246999,0.32703728016610001,0.32665595206971998,0.32627462397335,0.32607139210963998,0.32612398908844997,0.32617658606726002,0.32622918304607001,0.32628178002488001,0.32621813589151,0.32611951655624,0.32602089722097,0.3259222778857,0.32576354771750998,0.32519155557293999,0.32461956342838,0.32404757128381001,0.32347557913925001,0.32290358699469002,0.32233159485011997,0.32175960270555998,0.32118761056099998,0.32061561841642999,0.32042629612791002,0.32030795292558001,0.32018960972325999,0.32007126652093998,0.3199754797894,0.31996890516705001,0.31996233054470002,0.31995575592234998,0.3199491813,0.31969956927726001,0.31925906957972,0.31881856988217999,0.31837807018464997,0.31793757048711002,0.31727970572407999,0.31660251962189001,0.31592533351971003,0.31524814741752,0.31466554046318002,0.31433023472325999,0.31399492898334003,0.31365962324343,0.31332431750350997,0.31318938120668,0.31316965733962998,0.31314993347256997,0.31313020960552002,0.31311048573847,0.31283609588727002,0.31255996174852002,0.31228382760975998,0.31200769347100998,0.31158828921706999,0.31090452849252997,0.31022076776800001,0.30953700704345999,0.30885324631893002,0.30826747877514998,0.30772178511998999,0.30717609146482999,0.30663039780967999,0.30611332836067001,0.30598841053600001,0.30586349271132002,0.30573857488665002,0.30561365706197002,0.30547472530302999,0.30531693436660001,0.30515914343016998,0.30500135249374,0.30484356155731002,0.30434016314842999,0.30374187251446,0.3031435818805,0.30254529124653001,0.30193291213609003,0.30123600216684998,0.30053909219760999,0.29984218222837999,0.29914527225914,0.29864604821365998,0.29834361558549999,0.29804118295734,0.29773875032918001,0.29743631770102003,0.29729774374466,0.29718597516467998,0.29707420658471001,0.29696243800473998,0.29677624648876,0.29632259754652002,0.29586894860427998,0.29541529966204,0.29496165071980002,0.29433002481241999,0.29356736861965999,0.29280471242690997,0.29204205623416002,0.29127940004141001,0.29075015039634999,0.29023732985294998,0.28972450930955002,0.28921168876614001,0.28880272042069999,0.28864492948427001,0.28848713854784003,0.28832934761140999,0.28817155667497002,0.28791107639896002,0.2875954945261,0.28727991265323,0.28696433078036998,0.28664499198045001,0.28591520889945998,0.28518542581846001,0.28445564273746998,0.28372585965647001,0.28300815241244998,0.28231124244320999,0.28161433247397,0.28091742250473001,0.28022051253549002,0.27981938602986001,0.27953010264639999,0.27924081926295002,0.27895153587949001,0.27866721700678998,0.27843710522449,0.27820699344219002,0.27797688165989998,0.2777467698776,0.27734513648498998,0.27672712198395999,0.27610910748293999,0.27549109298191998,0.27487307848088999,0.27410770895192998,0.27330560502507001,0.27250350109822002,0.27170139717135999,0.27095042919612,0.27047048176447003,0.26999053433282999,0.26951058690118002,0.26903063946953998,0.26868325789265002,0.26845972073270002,0.26823618357276002,0.26801264641280997,0.26778910925286997,0.26734114042654,0.26686119299488997,0.26638124556324999,0.26590129813160002,0.26533996552214001,0.26451156310587998,0.26368316068961001,0.26285475827334998,0.26202635585709,0.26129133991339998,0.26062072843356998,0.25995011695373998,0.2592795054739,0.25860889399407,0.25828809416696002,0.25798566153879998,0.25768322891063999,0.25738079628248001,0.25706011572289,0.25669851149356998,0.25633690726425001,0.25597530303492999,0.25561369880561002,0.25498910968222999,0.25423302811183002,0.25347694654142999,0.25272086497103002,0.25196314347214999,0.25114131567824,0.25031948788433001,0.24949766009041,0.2486758322965,0.24799509798543001,0.24754144904319,0.24708780010094999,0.24663415115871001,0.24618050221647,0.24583410459666999,0.24552509734615,0.24521609009563999,0.24490708284512999,0.24456527702507,0.24392753865698999,0.24328980028891001,0.24265206192083999,0.24201432355276001,0.24126214799382001,0.2403745739764,0.23948699995896999,0.23859942594155001,0.23771185192412,0.23702285833690001,0.23637854534646999,0.23573423235603999,0.23508991936561,0.23450070797202999,0.23417197685447,0.23384324573689999,0.23351451461934,0.23318578350176999,0.23275895484435999,0.23224613430096,0.23173331375756001,0.23122049321415,0.23070767267075001,0.22987846519869001,0.22901061504831999,0.22814276489794999,0.22727491474757,0.2264218239535,0.22561314540429001,0.22480446685507999,0.22399578830587,0.22318710975666001,0.22259818162344999,0.22215110730356,0.22170403298367,0.22125695866378001,0.2208098843439,0.22040091599844999,0.21999328941266999,0.21958566282688999,0.21917803624111001,0.21864889095512999,0.21786651089532999,0.21708413083552,0.21630175077572,0.21551937071591001,0.21464275440239999,0.21372230727322,0.21280186014404001,0.21188141301485,0.21097384677844,0.21036898152212,0.20976411626579999,0.20915925100947999,0.20855438575315999,0.20803610872045999,0.20764820600173001,0.20726030328301001,0.20687240056428,0.20648449784555001,0.2058924389398,0.20523497670467,0.20457751446954001,0.20392005223441001,0.20322913545832999,0.20228238983974001,0.20133564422115,0.20038889860257,0.19944215298397999,0.19857330396808001,0.19779092390826999,0.19700854384847,0.19622616378866001,0.19544378372886001,0.19494044495373999,0.19449337063385,0.19404629631397,0.19359922199408,0.19313586765693999,0.19260332324648,0.19207077883602999,0.19153823442557,0.19100569001511,0.19027110641621001,0.18937038315408,0.18846965989195,0.18756893662981999,0.18666821336770001,0.18574959997672,0.18482915284754001,0.18390870571835,0.18298825858917001,0.18216025870079999,0.18158826655624,0.18101627441168,0.18044428226711001,0.17987229012254999,0.17936589511709,0.17889909693014999,0.17843229874321001,0.17796550055626001,0.17749870236932,0.17671559179592,0.17592663711376,0.17513768243160999,0.17434872774945001,0.17349044881801001,0.17249768084295999,0.17150491286792,0.17051214489287,0.16951937691782001,0.1687010973328,0.16795816500710001,0.16721523268140001,0.16647230035569999,0.16574502189275001,0.1652782237058,0.16481142551885999,0.16434462733192001,0.16387782914498,0.16332918361856,0.16266514676107999,0.16200110990359001,0.16133707304611,0.16067303618862999,0.15975989419539,0.15877370084270001,0.15778750749000001,0.1568013141373,0.15582636174889999,0.15492563848676999,0.15402491522464001,0.15312419196251001,0.15222346870038,0.15149341726745999,0.15094114898995001,0.15038888071244,0.14983661243492999,0.14928434415742001,0.14873207587991,0.14817980760239999,0.14762753932489001,0.14707527104738,0.14644974269224001,0.14554244480775999,0.14463514692328,0.14372784903880001,0.14282055115431999,0.14185385804207001,0.14084136619995999,0.13982887435786001,0.13881638251576001,0.13780389067366,0.13708871786456001,0.13639838251767,0.13570804717078,0.13501771182389999,0.13437728993649001,0.13386446939308999,0.13335164884969,0.13283882830629001,0.13232600776288,0.13164081582803999,0.13085843576823999,0.13007605570843001,0.12929367564861999,0.12851129558881999,0.12746652697259001,0.12642116201872999,0.12537579706487001,0.12433043211102,0.12335294528769,0.12249824438202001,0.12164354347634999,0.12078884257068,0.11993414166501,0.11930016022399,0.11875446656884001,0.11820877291368,0.11766307925852,0.11710927541162,0.11645181317649,0.11579435094135,0.11513688870622001,0.11447942647109,0.11367466884179001,0.11267532624439,0.11167598364699,0.11067664104959,0.10967729845219,0.10868314399216,0.10769037601711,0.10669760804207,0.10570484006702,0.10476246262156,0.10411157500878,0.10346068739600001,0.10280979978322,0.10215891217044,0.10154791954499,0.10097592740043,0.10040393525586,0.099831943111299004,0.099259950966734997,0.098409633142632999,0.097515484502854993,0.096621335863077001,0.095727187223298996,0.094795051876603004,0.093729963055691007,0.092664874234779995,0.091599785413867998,0.090534696592956002,0.089626086765694002,0.088830557461185997,0.088035028156677006,0.087239498852169001,0.086443969547660995,0.085870635643434001,0.085311792743573006,0.084752949843711997,0.084194106943851002,0.083574720866282995,0.082812064673531,0.082049408480780003,0.081286752288027994,0.080524096095276998,0.079567555631144996,0.078509041432583998,0.077450527234024,0.076392013035464001,0.075335019497854996,0.074388273879266997,0.073441528260678998,0.072494782642090999,0.071548037023502001,0.070723540618703007,0.070105526117680006,0.069487511616657005,0.068869497115634004,0.068251482614611003,0.067614266041958998,0.066969953051531,0.066325640061103003,0.065681327070675005,0.065006779762494998,0.064020586409799005,0.063034393057102997,0.062048199704407003,0.061062006351711003,0.060043506408006,0.058984992209445003,0.057926478010884998,0.056867963812324999,0.055809449613764002,0.055010267741283002,0.054273910037937002,0.053537552334589997,0.052801194631243997,0.052090598713436999,0.051512031946521999,0.050933465179607,0.050354898412692001,0.049776331645777001,0.049050320400280997,0.048189044872260001,0.047327769344238997,0.046466493816217001,0.045605218288195998,0.044535701660395,0.043437739727727,0.042339777795058001,0.041241815862390001,0.040195511676767999,0.039314512281692998,0.038433512886617997,0.037552513491543003,0.036671514096467003,0.035963035177240997,0.035371319165623999,0.034779603154006002,0.034187887142387997,0.033596171130770999,0.032872649594872003,0.032142866513877003,0.031413083432882002,0.030683300351886999,0.029852706394839001,0.028800766818629,0.027748827242420001,0.026696887666210999,0.025644948090002,0.024619485904486999,0.023606994062384999,0.022594502220283998,0.021582010378183001,0.02057940283227,0.019902216730085,0.019225030627900999,0.018547844525715999,0.017870658423531,0.017213867068232001,0.016589277944858,0.015964688821484,0.01534009969811,0.014715510574735999,0.013850582478741999,0.012903836860154,0.011957091241565,0.011010345622976999,0.010048512662395001,0.0089571253520778008,0.0078657380417608003,0.0067743507314439004,0.0056829634211268999,0.0047253942745862998,0.0039232903477268996,0.0031211864208674001,0.0023190824940081001,0.0015169785671486,0.00088757401742643998,0.00029585800580879,-0.00029585800580879,-0.00088757401742637005,-0.0015169785671486,-0.0023190824940079002,-0.0031211864208674001,-0.0039232903477267999,-0.0047253942745862998,-0.0056829634211268999,-0.0067743507314437998,-0.0078657380417608003,-0.0089571253520777001,-0.010048512662395001,-0.011010345622976999,-0.011957091241565,-0.012903836860154,-0.013850582478741999,-0.014715510574735999,-0.01534009969811,-0.015964688821484,-0.016589277944858,-0.017213867068232001,-0.017870658423531,-0.018547844525715999,-0.019225030627900999,-0.019902216730085,-0.02057940283227,-0.021582010378183001,-0.022594502220283998,-0.023606994062384999,-0.024619485904486999,-0.025644948090002,-0.026696887666210999,-0.027748827242420001,-0.028800766818629,-0.029852706394839001,-0.030683300351886999,-0.031413083432882002,-0.032142866513877003,-0.032872649594872003,-0.033596171130770999,-0.034187887142387997,-0.034779603154006002,-0.035371319165623,-0.035963035177240997,-0.036671514096467003,-0.037552513491541997,-0.038433512886617997,-0.039314512281692998,-0.040195511676767999,-0.041241815862390001,-0.042339777795058001,-0.043437739727727,-0.044535701660395,-0.045605218288195998,-0.046466493816217001,-0.047327769344238997,-0.048189044872260001,-0.049050320400280997,-0.049776331645777001,-0.050354898412692001,-0.050933465179607,-0.051512031946521999,-0.052090598713436999,-0.052801194631243997,-0.053537552334589997,-0.054273910037937002,-0.055010267741283002,-0.055809449613764002,-0.056867963812324,-0.057926478010884998,-0.058984992209445003,-0.060043506408006,-0.061062006351711003,-0.062048199704407003,-0.063034393057102997,-0.064020586409799005,-0.065006779762494998,-0.065681327070675005,-0.066325640061103003,-0.066969953051531,-0.067614266041958998,-0.068251482614611003,-0.068869497115634004,-0.069487511616657005,-0.070105526117680006,-0.070723540618703007,-0.071548037023502001,-0.07249478264209,-0.073441528260678998,-0.074388273879266997,-0.075335019497854996,-0.076392013035463002,-0.077450527234024,-0.078509041432583998,-0.079567555631144996,-0.080524096095276998,-0.081286752288027994,-0.082049408480780003,-0.082812064673531,-0.083574720866282995,-0.084194106943851002,-0.084752949843711997,-0.085311792743573006,-0.085870635643434001,-0.086443969547660995,-0.087239498852169001,-0.088035028156677006,-0.088830557461185997,-0.089626086765694002,-0.090534696592956002,-0.091599785413867998,-0.092664874234779995,-0.093729963055691007,-0.094795051876603004,-0.095727187223298996,-0.096621335863077001,-0.097515484502854993,-0.098409633142632,-0.099259950966734997,-0.099831943111299004,-0.10040393525586,-0.10097592740043,-0.10154791954499,-0.10215891217044,-0.10280979978322,-0.10346068739600001,-0.10411157500878,-0.10476246262156,-0.10570484006702,-0.10669760804207,-0.10769037601711,-0.10868314399216,-0.10967729845219,-0.11067664104959,-0.11167598364699,-0.11267532624439,-0.11367466884179001,-0.11447942647109,-0.11513688870622001,-0.11579435094135,-0.11645181317649,-0.11710927541162,-0.11766307925852,-0.11820877291368,-0.11875446656884001,-0.11930016022399,-0.11993414166501,-0.12078884257068,-0.12164354347634999,-0.12249824438202001,-0.12335294528769,-0.12433043211102,-0.12537579706487001,-0.12642116201872999,-0.12746652697259001,-0.12851129558881999,-0.12929367564861999,-0.13007605570843001,-0.13085843576823999,-0.13164081582803999,-0.13232600776288,-0.13283882830629001,-0.13335164884969,-0.13386446939308999,-0.13437728993649001,-0.13501771182389999,-0.13570804717078,-0.13639838251767,-0.13708871786456001,-0.13780389067366,-0.13881638251576001,-0.13982887435786001,-0.14084136619995999,-0.14185385804207001,-0.14282055115431999,-0.14372784903880001,-0.14463514692328,-0.14554244480775999,-0.14644974269224001,-0.14707527104738,-0.14762753932489001,-0.14817980760239999,-0.14873207587991,-0.14928434415742001,-0.14983661243492999,-0.15038888071244,-0.15094114898995001,-0.15149341726745999,-0.15222346870038,-0.15312419196251001,-0.15402491522464001,-0.15492563848676999,-0.15582636174889999,-0.1568013141373,-0.15778750749000001,-0.15877370084270001,-0.15975989419539,-0.16067303618862999,-0.16133707304611,-0.16200110990359001,-0.16266514676107999,-0.16332918361856,-0.16387782914498,-0.16434462733192001,-0.16481142551885999,-0.1652782237058,-0.16574502189275001,-0.16647230035569999,-0.16721523268140001,-0.16795816500710001,-0.1687010973328,-0.16951937691782001,-0.17051214489287,-0.17150491286792,-0.17249768084295999,-0.17349044881801001,-0.17434872774945001,-0.17513768243160999,-0.17592663711376,-0.17671559179592,-0.17749870236932,-0.17796550055626001,-0.17843229874321001,-0.17889909693014999,-0.17936589511709,-0.17987229012254999,-0.18044428226711001,-0.18101627441168,-0.18158826655624,-0.18216025870079999,-0.18298825858917001,-0.18390870571835,-0.18482915284754001,-0.18574959997672,-0.18666821336770001,-0.18756893662981999,-0.18846965989195,-0.18937038315408,-0.19027110641621001,-0.19100569001511,-0.19153823442557,-0.19207077883602999,-0.19260332324648,-0.19313586765693999,-0.19359922199408,-0.19404629631397,-0.19449337063385,-0.19494044495373999,-0.19544378372886001,-0.19622616378866001,-0.19700854384847,-0.19779092390826999,-0.19857330396808001,-0.19944215298397999,-0.20038889860257,-0.20133564422115,-0.20228238983974001,-0.20322913545832999,-0.20392005223441001,-0.20457751446954001,-0.20523497670467,-0.2058924389398,-0.20648449784555001,-0.20687240056428,-0.20726030328301001,-0.20764820600173001,-0.20803610872045999,-0.20855438575315999,-0.20915925100947999,-0.20976411626579999,-0.21036898152212,-0.21097384677844,-0.21188141301485,-0.21280186014404001,-0.21372230727322,-0.21464275440239999,-0.21551937071591001,-0.21630175077572,-0.21708413083552,-0.21786651089532999,-0.21864889095512999,-0.21917803624111001,-0.21958566282688999,-0.21999328941266999,-0.22040091599844999,-0.2208098843439,-0.22125695866378001,-0.22170403298367,-0.22215110730356,-0.22259818162344999,-0.22318710975666001,-0.22399578830587,-0.22480446685507999,-0.22561314540429001,-0.2264218239535,-0.22727491474757,-0.22814276489794999,-0.22901061504831999,-0.22987846519869001,-0.23070767267075001,-0.23122049321415,-0.23173331375756001,-0.23224613430096,-0.23275895484435999,-0.23318578350176999,-0.23351451461934,-0.23384324573689999,-0.23417197685447,-0.23450070797202999,-0.23508991936561,-0.23573423235603999,-0.23637854534646999,-0.23702285833690001,-0.23771185192412,-0.23859942594155001,-0.23948699995896999,-0.2403745739764,-0.24126214799382001,-0.24201432355276001,-0.24265206192083999,-0.24328980028891001,-0.24392753865698999,-0.24456527702507,-0.24490708284512999,-0.24521609009563999,-0.24552509734615,-0.24583410459666999,-0.24618050221647,-0.24663415115871001,-0.24708780010094999,-0.24754144904319,-0.24799509798543001,-0.2486758322965,-0.24949766009041,-0.25031948788433001,-0.25114131567824,-0.25196314347214999,-0.25272086497103002,-0.25347694654142999,-0.25423302811183002,-0.25498910968222999,-0.25561369880561002,-0.25597530303492999,-0.25633690726425001,-0.25669851149356998,-0.25706011572289,-0.25738079628248001,-0.25768322891063999,-0.25798566153879998,-0.25828809416696002,-0.25860889399407,-0.2592795054739,-0.25995011695373998,-0.26062072843356998,-0.26129133991339998,-0.26202635585709,-0.26285475827334998,-0.26368316068961001,-0.26451156310587998,-0.26533996552214001,-0.26590129813160002,-0.26638124556324999,-0.26686119299488997,-0.26734114042654,-0.26778910925286997,-0.26801264641280997,-0.26823618357276002,-0.26845972073270002,-0.26868325789265002,-0.26903063946953998,-0.26951058690118002,-0.26999053433282999,-0.27047048176447003,-0.27095042919612,-0.27170139717135999,-0.27250350109822002,-0.27330560502507001,-0.27410770895192998,-0.27487307848088999,-0.27549109298191998,-0.27610910748293999,-0.27672712198395999,-0.27734513648498998,-0.2777467698776,-0.27797688165989998,-0.27820699344219002,-0.27843710522449,-0.27866721700678998,-0.27895153587949001,-0.27924081926295002,-0.27953010264639999,-0.27981938602986001,-0.28022051253549002,-0.28091742250473001,-0.28161433247397,-0.28231124244320999,-0.28300815241244998,-0.28372585965647001,-0.28445564273746998,-0.28518542581846001,-0.28591520889945998,-0.28664499198045001,-0.28696433078036998,-0.28727991265323,-0.2875954945261,-0.28791107639896002,-0.28817155667497002,-0.28832934761140999,-0.28848713854784003,-0.28864492948427001,-0.28880272042069999,-0.28921168876614001,-0.28972450930955002,-0.29023732985294998,-0.29075015039634999,-0.29127940004141001,-0.29204205623416002,-0.29280471242690997,-0.29356736861965999,-0.29433002481241999,-0.29496165071980002,-0.29541529966204,-0.29586894860427998,-0.29632259754652002,-0.29677624648876,-0.29696243800473998,-0.29707420658471001,-0.29718597516467998,-0.29729774374466,-0.29743631770102003,-0.29773875032918001,-0.29804118295734,-0.29834361558549999,-0.29864604821365998,-0.29914527225914,-0.29984218222837999,-0.30053909219760999,-0.30123600216684998,-0.30193291213609003,-0.30254529124653001,-0.3031435818805,-0.30374187251446,-0.30434016314842999,-0.30484356155731002,-0.30500135249374,-0.30515914343016998,-0.30531693436660001,-0.30547472530302999,-0.30561365706197002,-0.30573857488665002,-0.30586349271132002,-0.30598841053600001,-0.30611332836067001,-0.30663039780967999,-0.30717609146482999,-0.30772178511998999,-0.30826747877514998,-0.30885324631893002,-0.30953700704345999,-0.31022076776800001,-0.31090452849252997,-0.31158828921706999,-0.31200769347100998,-0.31228382760975998,-0.31255996174852002,-0.31283609588727002,-0.31311048573847,-0.31313020960552002,-0.31314993347256997,-0.31316965733962998,-0.31318938120668,-0.31332431750350997,-0.31365962324343,-0.31399492898334003,-0.31433023472325999,-0.31466554046318002,-0.31524814741752,-0.31592533351971003,-0.31660251962189001,-0.31727970572407999,-0.31793757048711002,-0.31837807018464997,-0.31881856988217999,-0.31925906957972,-0.31969956927726001,-0.3199491813,-0.31995575592234998,-0.31996233054470002,-0.31996890516705001,-0.3199754797894,-0.32007126652093998,-0.32018960972325999,-0.32030795292558001,-0.32042629612791002,-0.32061561841642999,-0.32118761056099998,-0.32175960270555998,-0.32233159485011997,-0.32290358699469002,-0.32347557913925001,-0.32404757128381001,-0.32461956342838,-0.32519155557293999,-0.32576354771750998,-0.3259222778857,-0.32602089722097,-0.32611951655624,-0.32621813589151,-0.32628178002488001,-0.32622918304607001,-0.32617658606726002,-0.32612398908844997,-0.32607139210963998,-0.32627462397335,-0.32665595206971998,-0.32703728016610001,-0.32741860826246999,-0.32779993635885002,-0.32841807012739999,-0.32904923387312002,-0.32968039761884999,-0.33031156136457002,-0.33082800465906997,-0.33108441493077001,-0.33134082520246999,-0.33159723547417003,-0.33185364574587001,-0.33186107014934002,-0.33174272694702001,-0.33162438374469,-0.33150604054236998,-0.33139366071632997,-0.33153830240805998,-0.33168294409978999,-0.33182758579152,-0.33197222748325,-0.33228217396552001,-0.33286074073243999,-0.33343930749935002,-0.33401787426627,-0.33459644103317998,-0.33506322431168001,-0.33549057476451999,-0.33591792521734998,-0.33634527567019001,-0.33672326427584998,-0.33664436880762999,-0.33656547333941,-0.33648657787120001,-0.33640768240298002,-0.33633178353135001,-0.33625946268548002,-0.33618714183962001,-0.33611482099376,-0.33604250014789,-0.33637694119825001,-0.33680429165108,-0.33723164210391998,-0.33765899255675003,-0.33810673775646999,-0.33865243141162998,-0.33919812506678998,-0.33974381872194998,-0.34028951237711003,-0.34057705147299999,-0.34063622307416003,-0.34069539467533,-0.34075456627648998,-0.34081373787765001,-0.34062745691103002,-0.34041049437344001,-0.34019353183584,-0.33997656929824999,-0.33986198302297999,-0.34005922169351999,-0.34025646036405999,-0.34045369903459999,-0.34065093770513999,-0.34107108738111003,-0.34163650490332997,-0.34220192242553998,-0.34276733994774999,-0.34333275746996,-0.34359404280178002,-0.34384387845113001,-0.34409371410047002,-0.34434354974982001,-0.34443461050565999,-0.34419134947865998,-0.34394808845165997,-0.34370482742466002,-0.34346156639766001,-0.34334353627259001,-0.34328436467142998,-0.34322519307027,-0.34316602146911002,-0.34312737879080002,-0.34360075160009002,-0.34407412440939,-0.34454749721868,-0.34502087002797999,-0.34547597999739998,-0.34590333045024002,-0.34633068090307001,-0.34675803135590999,-0.34718538180873998,-0.34718081982589,-0.34703617813415999,-0.34689153644242998,-0.34674689475069997,-0.34658734461827001,-0.34631121047951002,-0.34603507634075997,-0.34575894220199999,-0.34548280806324999,-0.34546405324483997,-0.34573361276123998,-0.34600317227764998,-0.34627273179404999,-0.34654229131045,-0.34702465390949,-0.34755062369759998,-0.34807659348570003,-0.34860256327381001,-0.34903696541910001,-0.34907641315319998,-0.34911586088731,-0.34915530862142002,-0.34919475635552999,-0.34900784923439998,-0.34863309576036999,-0.34825834228635,-0.34788358881232001,-0.34750883533830002,-0.34746719606340998,-0.34746062144105999,-0.34745404681871001,-0.34744747219635003,-0.34757578914551002,-0.34808203506655999,-0.34858828098761002,-0.34909452690866,-0.34960077282971003,-0.34995587697889002,-0.35021886187293999,-0.35048184676699001,-0.35074483166103998,-0.35100781655509999,-0.35067828038172999,-0.35033640001945998,-0.34999451965720002,-0.34965263929493001,-0.34933075115165002,-0.34904804239053999,-0.34876533362943002,-0.34848262486832998,-0.34819991610722001,-0.34835658891060001,-0.34870504389522,-0.34905349887984,-0.34940195386445999,-0.34975577588772999,-0.35020285020761999,-0.35064992452750998,-0.35109699884739998,-0.35154407316729003,-0.35173066721115998,-0.35154657778532999,-0.35136248835949002,-0.35117839893364999,-0.35099430950782001,-0.35059225867886001,-0.35012546049192,-0.34965866230497,-0.34919186411802999,-0.34879559776406999,-0.34887449323227998,-0.34895338870050002,-0.34903228416871002,-0.34911117963693,-0.34940162587876,-0.34991444642217001,-0.35042726696556997,-0.35094008750896999,-0.35145290805237001,-0.35158759090571001,-0.35165333712921998,-0.35171908335273,-0.35178482957625001,-0.35172981743004,-0.35120384764194001,-0.35067787785382998,-0.35015190806572999,-0.34962593827762001,-0.34926264939450002,-0.34902596298985999,-0.34878927658520997,-0.34855259018056001,-0.34831590377590999,-0.34869660571777999,-0.34913053079297002,-0.34956445586814999,-0.34999838094334002,-0.35040113246901,-0.35072328896422,-0.35104544545944,-0.35136760195465,-0.35168975844986999,-0.35153852722734003,-0.35111775139686002,-0.35069697556638002,-0.35027619973589003,-0.34985542390541002,-0.34934302079835,-0.34883020025494998,-0.34831737971153998,-0.34780455916814002,-0.3475452417505,-0.34774905504338999,-0.34795286833627997,-0.34815668162918001,-0.34836049492207,-0.34877028323175002,-0.34926337990810002,-0.34975647658445003,-0.35024957326078998,-0.35069552944762999,-0.35051801464414001,-0.35034049984066001,-0.35016298503717003,-0.34998547023368998,-0.34959662828319998,-0.34892601680336,-0.34825540532353,-0.3475847938437,-0.34691418236386001,-0.34666777565587997,-0.34653628320884999,-0.34640479076182001,-0.34627329831480003,-0.34623531160788001,-0.34674813215127998,-0.34726095269467999,-0.34777377323808001,-0.34828659378149002,-0.34861076291620002,-0.34874882998557,-0.34888689705495002,-0.34902496412432998,-0.34916303119371001,-0.34862127336689003,-0.34797038575410999,-0.34731949814134,-0.34666861052856002,-0.34605242976574002,-0.34555933308939002,-0.34506623641304002,-0.34457313973670001,-0.34408004306035,-0.34407735954101998,-0.34443238914799001,-0.34478741875496,-0.34514244836192998,-0.34549747796890001,-0.34591407943599001,-0.34633485526647001,-0.34675563109696,-0.34717640692744001,-0.34733941581812,-0.34688576687588002,-0.34643211793363998,-0.3459784689914,-0.34552482004916002,-0.34486507682259998,-0.34409584600749998,-0.34332661519238999,-0.34255738437729,-0.34179717316880998,-0.34182347165822002,-0.34184977014762002,-0.34187606863703002,-0.34190236712644001,-0.34213279198599,-0.34271135875289999,-0.34328992551982002,-0.34386849228673,-0.34444705905364997,-0.34452792243602998,-0.34442272847840999,-0.34431753452079,-0.34421234056317002,-0.34404029715743001,-0.34315929776234999,-0.34227829836728002,-0.3413972989722,-0.34051629957712998,-0.33985153220605002,-0.33945705486497002,-0.33906257752389002,-0.33866810018281002,-0.33827362284173002,-0.33862328541004999,-0.33915582982051001,-0.33968837423095999,-0.34022091864142001,-0.34071429857814001,-0.34100358196160002,-0.34129286534505998,-0.34158214872851,-0.34187143211197002,-0.34161788426088002,-0.34086180269048,-0.34010572112007997,-0.33934963954968,-0.33859355797927998,-0.33778555030989998,-0.33697029713833998,-0.33615504396677998,-0.33533979079522003,-0.33477881598833997,-0.33504180088239,-0.33530478577644002,-0.33556777067048998,-0.33583075556455,-0.33630075906624002,-0.33691219894490998,-0.33752363882358,-0.33813507870225001,-0.33874651858093002,-0.33837489587945002,-0.33795412004897002,-0.33753334421848002,-0.33711256838800002,-0.33648550446346998,-0.33540069177550003,-0.33431587908754001,-0.33323106639957001,-0.33214625371161,-0.33165077168474,-0.33144695839185001,-0.33124314509896002,-0.33103933180606998,-0.33086128029871997,-0.33160421262442002,-0.33234714495012002,-0.33309007727582002,-0.33383300960151002,-0.33431742956536997,-0.33438975041122998,-0.33446207125709998,-0.33453439210295999,-0.33460671294882999,-0.33379394948685998,-0.33267626368713998,-0.33155857788741999,-0.3304408920877,-0.32935943379888999,-0.32859677760613998,-0.32783412141339002,-0.32707146522064001,-0.32630880902788001,-0.32617262042203998,-0.32677091105599998,-0.32736920168997002,-0.32796749232394001,-0.32856578295791,-0.32915869164479,-0.32975040765640001,-0.33034212366802002,-0.33093383967964002,-0.33127088970711999,-0.3304227634238,-0.32957463714048002,-0.32872651085715998,-0.32787838457384,-0.3268050812021,-0.32553617908830002,-0.32426727697449997,-0.32299837486069999,-0.32172947274689001,-0.32172346464529,-0.32186810633702001,-0.32201274802875002,-0.32215738972048003,-0.32251219570084,-0.32349181443118002,-0.32447143316152,-0.32545105189187001,-0.32643067062220998,-0.32664029820697998,-0.32635758944587001,-0.32607488068476997,-0.32579217192366,-0.32550946316254997,-0.32399813489443002,-0.32244652401953,-0.32089491314461999,-0.31934330226971003,-0.31811156689858999,-0.31753957475402,-0.31696758260946001,-0.31639559046490001,-0.31582359832033002,-0.31638619814725,-0.31747101083522,-0.31855582352318002,-0.31964063621115002,-0.32069967220513002,-0.32118619425912998,-0.32167271631312999,-0.32215923836712002,-0.32264576042111998,-0.32234592186164002,-0.32087320645494999,-0.31940049104826002,-0.31792777564156,-0.31645506023487002,-0.31503228810453998,-0.31362531892135997,-0.31221834973818002,-0.31081138055500002,-0.30965868973650001,-0.31040819668455,-0.31115770363259998,-0.31190721058065002,-0.3126567175287,-0.31366607859825002,-0.31496127920146,-0.31625647980466998,-0.31755168040788001,-0.31884688101108,-0.31829868273789003,-0.31738481023104997,-0.31647093772422003,-0.31555706521739002,-0.31439988695824,-0.31222368695996,-0.31004748696167,-0.30787128696339,-0.30569508696511,-0.30466729906284001,-0.30457525434992999,-0.30448320963700998,-0.30439116492409002,-0.30429912021117,-0.30604240890822998,-0.30796877325716998,-0.30989513760609999,-0.31182150195503,-0.31328343855910001,-0.31347410260727998,-0.31366476665547,-0.31385543070366001,-0.31404609475185002,-0.31247153978669001,-0.30984169084617003,-0.30721184190564998,-0.30458199296512001,-0.30195214402460002,-0.30044165062916001,-0.29894921135541003,-0.29745677208166998,-0.29596433280792001,-0.29570328601116003,-0.29780716516358002,-0.29991104431600002,-0.30201492346841002,-0.30411880262083002,-0.30605684027884,-0.30792403302660998,-0.30979122577438001,-0.31165841852214998,-0.31327055766633,-0.31081164890694002,-0.30835274014754999,-0.30589383138816001,-0.30343492262876998,-0.30052887991573002,-0.29699830771308,-0.29346773551042998,-0.28993716330776997,-0.28640659110512001,-0.28671533000369998,-0.28813544843158001,-0.28955556685946998,-0.29097568528735002,-0.29279162281596999,-0.29717032130193999,-0.30154901978790999,-0.30592771827387999,-0.31030641675984999,-0.31201936678008002,-0.31098057644858002,-0.30994178611707002,-0.30890299578556002,-0.30786420545406001,-0.30186090436747998,-0.29498384938802003,-0.28810679440855003,-0.28122973942907997,-0.27550618032391,-0.27415838274189003,-0.27281058515987999,-0.27146278757786002,-0.27011498999583999,-0.27506973572225002,-0.28483962453629003,-0.29460951335032998,-0.30437940216436998,-0.31414929097840999,-0.31975256878397001,-0.32501884128736003,-0.33028511379075998,-0.33555138629415998,-0.33297954609642,-0.31059295699021999,-0.28820636788402998,-0.26581977877782997,-0.24343318967162,-0.20286654727191999,-0.15214991045394999,-0.10143327363597,-0.050716636817978,0.0,0.0,0.083589748574514997,0.16717949714902999,0.25076924572353998,0.33435899429805999,0.40103365586452999,0.43741104133431002,0.47378842680409,0.51016581227387003,0.54654319774365001,0.54989129063205999,0.54017399879683003,0.53045670696159997,0.52073941512637001,0.51046126775178002,0.49324890643606001,0.47603654512033999,0.45882418380460999,0.44161182248889003,0.43242090296967001,0.43372925281758001,0.43503760266549002,0.43634595251340003,0.43765430236130998,0.44625732242973998,0.45678329281418001,0.46730926319861998,0.47783523358306002,0.48690494747934998,0.48770047678386003,0.48849600608837002,0.48929153539288001,0.49008706469738,0.48630415222734003,0.47808587428820998,0.46986759634907999,0.46164931840994,0.45343104047081001,0.44947264074521998,0.44617218032486999,0.44287171990451002,0.43957125948414999,0.43812457421493001,0.44308183946781998,0.44803910472070002,0.45299636997359,0.45795363522646998,0.46186874084024998,0.46503770881357998,0.46820667678691003,0.47137564476024002,0.47454461273357001,0.47093262553623,0.46689580741252001,0.46285898928882002,0.45882217116511997,0.45466727819102998,0.45023598272624998,0.44580468726146,0.44137339179668,0.43694209633190001,0.43645378526501999,0.43801854538462998,0.43958330550424002,0.44114806562386,0.44274308987810002,0.44621449047959,0.44968589108107998,0.45315729168257002,0.45662869228406,0.45834126959326998,0.45711181521357003,0.45588236083388001,0.45465290645418999,0.45342345207448997,0.45007521010167001,0.44595292188739999,0.44183063367313002,0.43770834545887,0.43389197844788002,0.43314247149982998,0.43239296455178,0.43164345760373002,0.43089395065568997,0.43170303173279001,0.43442492538624,0.43714681903968,0.43986871269312,0.44259060634656,0.44361413043477999,0.44423214493580998,0.44485015943682998,0.44546817393784999,0.44547781969898997,0.44242062030563001,0.43936342091226999,0.43630622151891002,0.43324902212555999,0.43067051785483002,0.4285271909683,0.42638386408176998,0.42424053719525001,0.42209721030871999,0.42312614616091998,0.42457913770055999,0.42603212924020001,0.42748512077984002,0.42896655762433999,0.43053789236631002,0.43210922710826999,0.43368056185023002,0.43525189659218999,0.43487106047436003,0.43318138253006999,0.43149170458579,0.42980202664150002,0.42811234869721998,0.42547896645625,0.42280309515927,0.42012722386228002,0.41745135256530003,0.41564169149021002,0.41571401233608002,0.41578633318194003,0.41585865402781003,0.41593097487366998,0.41711910305573002,0.41884822873411998,0.42057735441251998,0.42230648009090999,0.42396818980043,0.42357371245934999,0.42317923511827998,0.42278475777719998,0.42239028043611998,0.42117780677039002,0.41868602489924001,0.41619424302809999,0.41370246115694997,0.41121067928581001,0.40977173149731,0.40868691880934999,0.40760210612137998,0.40651729343342002,0.40568333016877001,0.40695223228256999,0.40822113439636998,0.40949003651017002,0.41075893862398,0.41170388032124,0.4122758724658,0.41284786461036999,0.41341985675492998,0.41399184889948998,0.41259395895669998,0.41077278856539001,0.40895161817407999,0.40713044778277002,0.40531047006671,0.40349587429775002,0.40168127852878999,0.39986668275983001,0.39805208699087002,0.39745807507938002,0.39790514939927002,0.39835222371916001,0.39879929803905001,0.39924637235894,0.40023659099063003,0.40128853056684,0.40234047014303997,0.40339240971925,0.40393726850173001,0.40301024675019997,0.40208322499866,0.40115620324713003,0.40022918149559999,0.3986234082556,0.39659184994905,0.39456029164250001,0.39252873333594002,0.39049717502939002,0.38999419405684999,0.38953397049226002,0.38907374692766999,0.38861352336308003,0.38864739534036002,0.38967961104951998,0.39071182675867,0.39174404246783001,0.39277625817697998,0.39304253783643001,0.39296364236821002,0.39288474690000003,0.39280585143177998,0.39264555587730998,0.39085725859775999,0.38906896131820001,0.38728066403865002,0.38549236675908999,0.38394157584841998,0.38273841995813002,0.38153526406784,0.38033210817754998,0.37912895228726001,0.37930241199488002,0.37990070262885001,0.38049899326282,0.38109728389677999,0.38168591386118,0.38220530902693001,0.38272470419268001,0.38324409935844,0.38376349452419001,0.38344849408051002,0.38223218894552002,0.38101588381052998,0.37979957867553998,0.37858327354054999,0.37702496877576003,0.37540103705499001,0.37377710533421998,0.37215317361344002,0.37083793606593002,0.37077876446476998,0.37071959286360001,0.37066042126243998,0.37060124966128,0.37099134392078997,0.37174085086884001,0.37249035781688999,0.37323986476493998,0.37398937171299002,0.37357330694976998,0.37304733716166,0.37252136737356001,0.37199539758545003,0.37115992856829,0.36949654911341001,0.36783316965853002,0.36616979020364998,0.36450641074876999,0.36343155689919998,0.36270177381820001,0.36197199073720998,0.36124220765621001,0.36051242457521998,0.36110215776422,0.36170702302053998,0.36231188827686001,0.36291675353317998,0.36333913947525998,0.36341803494348002,0.36349693041169001,0.36357582587991,0.36365472134811999,0.36272285435335999,0.36136848214898998,0.36001410994462002,0.35865973774025001,0.35731246195366001,0.35606985832926002,0.35482725470486998,0.35358465108046999,0.35234204745607001,0.35170117831545,0.35188526774127998,0.35206935716712001,0.35225344659295998,0.35243753601879002,0.35283189409235,0.35328554303458998,0.35373919197683001,0.35419284091907,0.35446642571446002,0.35361829943113998,0.35277017314782,0.35192204686450002,0.35107392058119002,0.34991888913750002,0.34845274835314999,0.34698660756881,0.34552046678447002,0.34405432600012997,0.34352118525205,0.34314643177802001,0.34277167830400002,0.34239692482996997,0.34221556364877997,0.34274810805924,0.34328065246970002,0.34381319688015,0.34434574129061002,0.34440866981883,0.34411938643536999,0.34383010305190997,0.34354081966846001,0.34325153628499999,0.34194147196641,0.34055422665028001,0.33916698133416001,0.33777973601803002,0.33653449359963,0.33564034495985001,0.33474619632007002,0.33385204768028998,0.33295789904051998,0.33284130012576002,0.33315030737626999,0.33345931462678002,0.33376832187729,0.33407664333953002,0.33423443427596,0.33439222521238998,0.33455001614882002,0.33470780708525,0.33442430817678998,0.33336579397823002,0.33230727977967001,0.33124876558110999,0.33019025138254998,0.32900373331208999,0.32776770431003999,0.32653167530799998,0.32529564630594998,0.32414936611695,0.32404417215933001,0.32393897820171003,0.32383378424408998,0.32372859028647,0.32383344134996001,0.32420819482398,0.324582948298,0.32495770177202998,0.32533245524604998,0.32494321076765997,0.3243580693784,0.32377292798912999,0.32318778659986003,0.32248808875221002,0.32116001503725,0.31983194132228998,0.31850386760732002,0.31717579389236,0.31622845193614002,0.31564331054688,0.31505816915760998,0.31447302776834002,0.31388788637907999,0.31410422276215999,0.31443952850208001,0.31477483424198999,0.31511013998191001,0.31533853729352002,0.31520704484649997,0.31507555239946999,0.31494405995245001,0.31481256750542003,0.31407485313396999,0.31291114497778999,0.31174743682160999,0.31058372866542,0.30942002050924,0.30842416648697002,0.30743797313427002,0.30645177978158,0.30546558642888,0.30479903004491998,0.30486477626843,0.30493052249195002,0.30499626871545998,0.30506201493897001,0.30521047319152,0.30540113723971002,0.30559180128789998,0.30578246533608999,0.30595260046141998,0.30513734728985997,0.30432209411830002,0.30350684094674002,0.30269158777517002,0.30172944173734001,0.30052628584704999,0.29932312995676003,0.29811997406647001,0.29691681817617999,0.29635323439216998,0.29601792865226001,0.29568262291233999,0.29534731717242002,0.29507149611091998,0.29536077949438,0.29565006287784001,0.29593934626129997,0.29622862964475,0.29620781746153002,0.29581334012045002,0.29541886277937002,0.29502438543829002,0.29462990809722001,0.29358962692163998,0.29239962027604999,0.29120961363046999,0.29001960698488,0.28890675151994999,0.28817039381659998,0.28743403611325002,0.28669767840991001,0.28596132070656,0.28570085533898998,0.28586522089777,0.28602958645655002,0.28619395201532999,0.28635831757412,0.28635363632374,0.28632733783433001,0.28630103934493001,0.28627474085552002,0.28601658629625998,0.28504354218826,0.28407049808027002,0.28309745397227998,0.28212440986428,0.28111170930401003,0.28007291897251002,0.27903412864100002,0.27799533830949003,0.27695654797799002,0.27679008032906,0.27665858788204001,0.27652709543500997,0.27639560298798999,0.27636501086766002,0.27654910029349,0.27673318971932998,0.27691727914517,0.27710136857099998,0.27674162789676998,0.27612361339574998,0.27550559889471998,0.27488758439369998,0.27425024855351998,0.27309968964204001,0.27194913073056998,0.27079857181909001,0.26964801290760998,0.26875167272704997,0.268245426806,0.26773918088495002,0.26723293496389999,0.26672668904284003,0.26674510096712001,0.26693576501529998,0.26712642906348999,0.26731709311168,0.26745881274902999,0.26720897709968,0.26695914145033001,0.26670930580098001,0.26645947015163002,0.26583005069346999,0.26477153649490998,0.26371302229635002,0.26265450809779001,0.26159599389922999,0.26071705186896998,0.25987550020799999,0.25903394854703998,0.25819239688606999,0.25750854671089002,0.25751512133324,0.25752169595558999,0.25752827057793998,0.25753484520029002,0.25755573192572001,0.25758860503747999,0.25762147814924002,0.25765435126099001,0.25768722437274999,0.25696653544058001,0.25616443151371998,0.25536232758686001,0.25456022366001002,0.25369296984725997,0.25264103027105,0.25158909069483998,0.25053715111863001,0.24948521154242001,0.24889725245787001,0.24859481982970999,0.24829238720154001,0.24798995457337999,0.24768752194522001,0.24782845143522,0.2479796677493,0.24813088406337999,0.24828210037746001,0.24822811691366001,0.24776789334907001,0.24730766978447999,0.24684744621988999,0.2463872226553,0.24549817270224,0.24441993463663,0.24334169657101001,0.24226345850539999,0.24120819434690999,0.24057045597883001,0.23993271761075999,0.23929497924268001,0.2386572408746,0.23831363113321,0.23839252660143001,0.23847142206964,0.23855031753785999,0.23862921300608,0.23853627378671999,0.23839163209499001,0.23824699040326,0.23810234871152999,0.23785919204361999,0.23693874491443001,0.23601829778524999,0.23509785065607,0.23417740352687999,0.23326014680401,0.23234627429717999,0.23143240179034999,0.23051852928352001,0.22960465677669001,0.22933965924314001,0.22919501755141,0.22905037585967999,0.22890573416794999,0.22880222486412999,0.22886139646529,0.22892056806645,0.22897973966762,0.22903891126878001,0.22870406769052001,0.22805975470008999,0.22741544170967001,0.22677112871923999,0.22612681572880999,0.22512022762923001,0.22408143729772001,0.22304264696622,0.22200385663471001,0.22112876098215001,0.22068168666226001,0.22023461234238001,0.21978753802248999,0.21934046370259999,0.21923986154471001,0.21933848087998001,0.21943710021525001,0.21953571955052001,0.21963433888579001,0.21930851491417,0.21897978379659999,0.21865105267903001,0.21832232156147,0.21776019880465,0.21676743082961,0.21577466285456001,0.21478189487950999,0.21378912690446,0.21296901358122999,0.21221950663318001,0.21146999968513,0.21072049273707999,0.21002018364337,0.20999388515396,0.20996758666455001,0.20994128817515001,0.20991498968573999,0.20986907168836999,0.20979675084251001,0.20972442999664001,0.20965210915078,0.20957978830491,0.20894005220577999,0.20814452290127,0.20734899359677,0.20655346429225999,0.20573633265717001,0.20478958703858,0.20384284141999001,0.2028960958014,0.20194935018280999,0.20133537586922001,0.20105266710812,0.20076995834701,0.2004872495859,0.20020454082479999,0.20021564761312,0.20027481921428,0.20033399081545,0.20039316241661001,0.2003292499313,0.19982300401024999,0.19931675808919999,0.19881051216814999,0.19830426624709999,0.19751022778666,0.19650431056691001,0.19549839334715999,0.19449247612741,0.19348655890766001,0.19288603200759,0.19231403986302001,0.19174204771846001,0.19117005557389999,0.19077307361477999,0.19079937210417999,0.19082567059359001,0.19085196908298999,0.19087826757240001,0.19074197460747,0.19051843744752001,0.19029490028758,0.19007136312763001,0.18984174332388001,0.1889475946841,0.18805344604433,0.18715929740455001,0.18626514876476999,0.18539515179894001,0.18456674938267001,0.18373834696641,0.18290994455014001,0.18208154213388,0.18174929262431,0.18160465093257999,0.18146000924085001,0.18131536754912,0.18118120649121,0.18116148262414999,0.18114175875710001,0.18112203489004,0.18110231102298999,0.18079477970811,0.18012416822828001,0.17945355674843999,0.17878294526860999,0.17811233378878,0.17721016440789999,0.17625026954461001,0.17529037468132,0.17433047981802999,0.17345824658608999,0.17305062000030999,0.17264299341452,0.17223536682873999,0.17182774024295999,0.17165125412189,0.17169070185599,0.1717301495901,0.17176959732420999,0.17180904505832001,0.17147444001511,0.17108653729639001,0.17069863457765999,0.17031073185893,0.16979077017242999,0.16883744993149,0.16788412969055,0.16693080944961,0.16597748920867,0.16518759529474999,0.16451040919257001,0.16383322309038001,0.1631560369882,0.16247885088601,0.16239509526613,0.16234249828732,0.16228990130851001,0.16223730432969999,0.16215632167978,0.16201167998804999,0.16186703829633001,0.1617223966046,0.16157775491286999,0.16100357122751999,0.16021461654536001,0.15942566186321,0.15863670718105,0.15784545659902,0.15696445720395,0.15608345780887001,0.15520245841380001,0.15432145901871999,0.15367729511270001,0.15341431021865001,0.15315132532459999,0.15288834043055,0.15262535553649001,0.15255737304688,0.15255737304688,0.15255737304688,0.15255737304688,0.15250292742141999,0.15195723376626,0.1514115401111,0.15086584645594001,0.15032015280078001,0.14958774583421999,0.14863442559328,0.14768110535234,0.14672778511140999,0.14577446487046999,0.14517000214204001,0.14464403235393999,0.14411806256584,0.14359209277773,0.14315795898438,0.14315795898438,0.14315795898438,0.14315795898438,0.14315795898438,0.14300730919103999,0.14272460042994001,0.14244189166883001,0.14215918290772001,0.14187647414662,0.14106059482055,0.14017959542547001,0.13929859603040001,0.13841759663531999,0.13756447602436001,0.13679524520926001,0.13602601439416001,0.13525678357906001,0.13448755276395,0.13410188631132999,0.13396381924195,0.13382575217258,0.1336876851032,0.13354961803382001,0.13346235893037001,0.13337688883980001,0.13329141874924,0.13320594865867,0.13292647502919999,0.13224271430466,0.13155895358012001,0.13087519285558999,0.13019143213105,0.12935061098368,0.12843673847685,0.12752286597001999,0.12660899346318999,0.12571712581483999,0.12534237234081,0.12496761886679,0.12459286539276,0.12421811191874001,0.12399291992188,0.12399291992188,0.12399291992188,0.12399291992188,0.12399291992188,0.12366427825494999,0.12323035317977001,0.12279642810458,0.12236250302939999,0.12187231349898001,0.1209518663698,0.12003141924062,0.11911097211144001,0.11819052498224999,0.11740717587379999,0.11677601212808,0.11614484838234999,0.11551368463663,0.11488252089089999,0.11472736874847,0.11466819714731,0.11460902554615,0.11454985394499,0.11446438385442,0.11426714518388,0.11406990651333999,0.11387266784279999,0.11367542917226001,0.11314626897785,0.11234416505099,0.11154206112413,0.11073995719727001,0.10993785327041,0.10911189583842,0.10828349342216,0.10745509100589,0.10662668858962999,0.105955272054,0.10571858564934999,0.1054818992447,0.10524521284006,0.10500852643541,0.10489073484538999,0.10484471248893,0.10479869013246999,0.10475266777601,0.10470664541955001,0.10413773932221999,0.10355917255530001,0.10298060578839,0.10240203902147001,0.10170718641705,0.10078673928787001,0.099866292158685005,0.098945845029502003,0.098025397900319,0.097408009553806005,0.096921487499809,0.096434965445811996,0.095948443391816005,0.095488383820072006,0.095468659953017995,0.095448936085963998,0.095429212218910001,0.095409488351856003,0.095261536986291001,0.094932805868726003,0.094604074751160006,0.094275343633594993,0.093946612516029995,0.093195927801164993,0.092321503028440999,0.091447078255717004,0.090572653482992996,0.089718981259732003,0.089002347423440001,0.088285713587146999,0.087569079750854997,0.086852445914561996,0.086419191719208005,0.086281124649830995,0.086143057580453,0.086004990511076004,0.085866923441697995,0.085740007885969,0.085615090061294002,0.085490172236619005,0.085365254411943994,0.085119593125992002,0.084409533912050999,0.083699474698109996,0.082989415484168993,0.082279356270228005,0.081476492012892004,0.080602067240168995,0.079727642467445001,0.078853217694721006,0.077978792921996998,0.077595854714024998,0.077253974351757002,0.076912093989489005,0.076570213627220995,0.076317068304034993,0.076290769814629997,0.076264471325224001,0.076238172835819004,0.076211874346413994,0.075899691598032004,0.075426318788737998,0.074952945979444005,0.074479573170149999,0.074006200360856006,0.073099886433462005,0.072192588548982001,0.071285290664500997,0.070377992780021006,0.069585385529891006,0.069000244140625,0.068415102751358994,0.067829961362092003,0.067244819972825998,0.067030675130526005,0.066964928907012999,0.066899182683499994,0.066833436459987003,0.066755286413807,0.066518600009160003,0.066281913604512993,0.066045227199865997,0.065808540795219,0.065325417865703006,0.064516739316492003,0.063708060767281,0.062899382218070995,0.062090703668859999,0.061297589531746001,0.060508634849589002,0.059719680167433002,0.058930725485276003,0.058225108986664997,0.058001571826720999,0.057778034666776001,0.057554497506832003,0.057330960346886999,0.057180563997045998,0.057101668528830002,0.057022773060614998,0.056943877592399002,0.056864982124182999,0.056331677383250997,0.055726812126931001,0.055121946870610998,0.054517081614291002,0.053846470134457002,0.052945746872328003,0.052045023610198998,0.05114430034807,0.050243577085941002,0.049610013081261999,0.049169513383725001,0.048729013686186998,0.04828851398865,0.047848014291111997,0.047784012355161998,0.047744564621054003,0.047705116886946002,0.047665669152838,0.047528571132105998,0.047160392280432999,0.046792213428759999,0.046424034577086999,0.046055855725413999,0.045355919342711999,0.044481494569987998,0.043607069797264003,0.042732645024541001,0.041860903771144001,0.041183717668959001,0.040506531566775,0.039829345464590001,0.039152159362405001,0.038680351939385002,0.038555434114710997,0.038430516290036,0.038305598465361003,0.038180680640685999,0.038026959708567003,0.037862594149785003,0.037698228591001998,0.037533863032218999,0.037319494563308998,0.036589711482313998,0.035859928401318998,0.035130145320323998,0.034400362239328998,0.033620650790410003,0.032779099129442997,0.031937547468474999,0.031095995807507999,0.030254444146541,0.029841584698072,0.02953257744756,0.029223570197048999,0.028914562946537999,0.028647418597528,0.028594821618718,0.028542224639907,0.028489627661097,0.028437030682287,0.028147836749473,0.027641590828423001,0.027135344907371999,0.026629098986321001,0.026122853065270998,0.025269538644586999,0.024368815382458001,0.023468092120329,0.022567368858200001,0.021751176454873001,0.021205482799715,0.020659789144556,0.020114095489398,0.019568401834239,0.019312856252099001,0.019253684650936999,0.019194513049775999,0.019135341448614,0.019076169847452001,0.018803598826025999,0.018520890064920002,0.018238181303814001,0.017955472542707001,0.017504059866573,0.016682232072660001,0.015860404278746,0.015038576484833,0.01421674869092,0.013439049881495999,0.012682968311095,0.011926886740695,0.011170805170294999,0.010431391236604,0.010240727188416,0.010050063140228001,0.0098593990920401997,0.0096687350438522997,0.0095112124593536001,0.0094060185017326992,0.0093008245441118,0.0091956305864909008,0.0090904366288699998,0.0085830427578850003,0.0079387297674569004,0.0072944167770289002,0.0066501037866009,0.0059811024183637996,0.0051001030232886999,0.0042191036282135004,0.0033381042331385,0.0024571048380633001,0.0017950806200766,0.0013874540342956,0.00097982744851459998,0.00057220086273359998,0.00016457427695254999,5.9171601161763002e-05,1.9723867053918999e-05,-1.9723867053918999e-05,-5.9171601161758001e-05,-0.00016457427695254999,-0.00057220086273355,-0.00097982744851459998,-0.0013874540342956,-0.0017950806200766,-0.0024571048380633001,-0.0033381042331383998,-0.0042191036282135004,-0.0051001030232886001,-0.0059811024183637996,-0.0066501037866008002,-0.0072944167770289002,-0.0079387297674569004,-0.0085830427578850003,-0.0090904366288699998,-0.0091956305864909008,-0.0093008245441118,-0.0094060185017326992,-0.0095112124593536001,-0.0096687350438522997,-0.0098593990920401997,-0.010050063140228001,-0.010240727188416,-0.010431391236604,-0.011170805170294999,-0.011926886740695,-0.012682968311095,-0.013439049881495999,-0.01421674869092,-0.015038576484833,-0.015860404278746,-0.016682232072660001,-0.017504059866573,-0.017955472542707001,-0.018238181303814001,-0.018520890064920002,-0.018803598826025999,-0.019076169847452001,-0.019135341448614,-0.019194513049775999,-0.019253684650936999,-0.019312856252099001,-0.019568401834239,-0.020114095489398,-0.020659789144556,-0.021205482799714001,-0.021751176454873001,-0.022567368858198999,-0.023468092120329,-0.024368815382458001,-0.025269538644586999,-0.026122853065270998,-0.026629098986321001,-0.027135344907371999,-0.027641590828423001,-0.028147836749473,-0.028437030682287,-0.028489627661097,-0.028542224639907,-0.028594821618718,-0.028647418597528,-0.028914562946537999,-0.029223570197048999,-0.02953257744756,-0.029841584698072,-0.030254444146541,-0.031095995807507999,-0.031937547468474999,-0.032779099129441998,-0.033620650790410003,-0.034400362239328998,-0.035130145320323998,-0.035859928401318998,-0.036589711482313998,-0.037319494563308998,-0.037533863032218999,-0.037698228591001998,-0.037862594149785003,-0.038026959708567003,-0.038180680640685999,-0.038305598465361003,-0.038430516290036,-0.038555434114710997,-0.038680351939385002,-0.039152159362405001,-0.039829345464590001,-0.040506531566775,-0.041183717668959001,-0.041860903771144001,-0.042732645024540002,-0.043607069797264003,-0.044481494569987998,-0.045355919342711999,-0.046055855725413999,-0.046424034577086999,-0.046792213428759999,-0.047160392280432999,-0.047528571132105998,-0.047665669152838,-0.047705116886946002,-0.047744564621054003,-0.047784012355161998,-0.047848014291111997,-0.04828851398865,-0.048729013686186998,-0.049169513383725001,-0.049610013081261999,-0.050243577085941002,-0.05114430034807,-0.052045023610198998,-0.052945746872328003,-0.053846470134457002,-0.054517081614291002,-0.055121946870610998,-0.055726812126931001,-0.056331677383250997,-0.056864982124182999,-0.056943877592399002,-0.057022773060614998,-0.057101668528830002,-0.057180563997045998,-0.057330960346886999,-0.057554497506832003,-0.057778034666776001,-0.05800157182672,-0.058225108986664997,-0.058930725485276003,-0.059719680167433002,-0.060508634849589002,-0.061297589531746001,-0.062090703668859999,-0.062899382218070995,-0.063708060767281,-0.064516739316492003,-0.065325417865703006,-0.065808540795219,-0.066045227199865997,-0.066281913604512993,-0.066518600009160003,-0.066755286413807,-0.066833436459987003,-0.066899182683499994,-0.066964928907012999,-0.067030675130526005,-0.067244819972825998,-0.067829961362092003,-0.068415102751358994,-0.069000244140625,-0.069585385529891006,-0.070377992780021006,-0.071285290664500997,-0.072192588548982001,-0.073099886433462005,-0.074006200360856006,-0.074479573170149999,-0.074952945979444005,-0.075426318788737998,-0.075899691598032004,-0.076211874346413994,-0.076238172835819004,-0.076264471325224001,-0.076290769814629997,-0.076317068304034993,-0.076570213627220995,-0.076912093989489005,-0.077253974351757002,-0.077595854714024998,-0.077978792921996998,-0.078853217694721006,-0.079727642467445001,-0.080602067240168995,-0.081476492012892004,-0.082279356270228005,-0.082989415484168993,-0.083699474698109996,-0.084409533912050999,-0.085119593125992002,-0.085365254411943994,-0.085490172236619005,-0.085615090061294002,-0.085740007885969,-0.085866923441697995,-0.086004990511076004,-0.086143057580453,-0.086281124649830995,-0.086419191719208005,-0.086852445914561996,-0.087569079750854997,-0.088285713587146999,-0.089002347423440001,-0.089718981259732003,-0.090572653482992996,-0.091447078255717004,-0.092321503028440999,-0.093195927801164993,-0.093946612516029995,-0.094275343633594993,-0.094604074751160006,-0.094932805868726003,-0.095261536986291001,-0.095409488351856003,-0.095429212218910001,-0.095448936085963998,-0.095468659953017995,-0.095488383820072006,-0.095948443391816005,-0.096434965445811996,-0.096921487499809,-0.097408009553806005,-0.098025397900319,-0.098945845029502003,-0.099866292158685005,-0.10078673928787001,-0.10170718641705,-0.10240203902147001,-0.10298060578839,-0.10355917255530001,-0.10413773932221999,-0.10470664541955001,-0.10475266777601,-0.10479869013246999,-0.10484471248893,-0.10489073484538999,-0.10500852643541,-0.10524521284006,-0.1054818992447,-0.10571858564934999,-0.105955272054,-0.10662668858962999,-0.10745509100589,-0.10828349342216,-0.10911189583842,-0.10993785327041,-0.11073995719727001,-0.11154206112413,-0.11234416505099,-0.11314626897785,-0.11367542917226001,-0.11387266784279999,-0.11406990651333999,-0.11426714518388,-0.11446438385442,-0.11454985394499,-0.11460902554615,-0.11466819714731,-0.11472736874847,-0.11488252089089999,-0.11551368463663,-0.11614484838234999,-0.11677601212808,-0.11740717587379999,-0.11819052498224999,-0.11911097211144001,-0.12003141924062,-0.1209518663698,-0.12187231349898001,-0.12236250302939999,-0.12279642810458,-0.12323035317977001,-0.12366427825494999,-0.12399291992188,-0.12399291992188,-0.12399291992188,-0.12399291992188,-0.12399291992188,-0.12421811191874001,-0.12459286539276,-0.12496761886679,-0.12534237234081,-0.12571712581483999,-0.12660899346318999,-0.12752286597001999,-0.12843673847685,-0.12935061098368,-0.13019143213105,-0.13087519285558999,-0.13155895358012001,-0.13224271430466,-0.13292647502919999,-0.13320594865867,-0.13329141874924,-0.13337688883980001,-0.13346235893037001,-0.13354961803382001,-0.1336876851032,-0.13382575217258,-0.13396381924195,-0.13410188631132999,-0.13448755276395,-0.13525678357906001,-0.13602601439416001,-0.13679524520926001,-0.13756447602436001,-0.13841759663531999,-0.13929859603040001,-0.14017959542547001,-0.14106059482055,-0.14187647414662,-0.14215918290772001,-0.14244189166883001,-0.14272460042994001,-0.14300730919103999,-0.14315795898438,-0.14315795898438,-0.14315795898438,-0.14315795898438,-0.14315795898438,-0.14359209277773,-0.14411806256584,-0.14464403235393999,-0.14517000214204001,-0.14577446487046999,-0.14672778511140999,-0.14768110535234,-0.14863442559328,-0.14958774583421999,-0.15032015280078001,-0.15086584645594001,-0.1514115401111,-0.15195723376626,-0.15250292742141999,-0.15255737304688,-0.15255737304688,-0.15255737304688,-0.15255737304688,-0.15262535553649001,-0.15288834043055,-0.15315132532459999,-0.15341431021865001,-0.15367729511270001,-0.15432145901871999,-0.15520245841380001,-0.15608345780887001,-0.15696445720395,-0.15784545659902,-0.15863670718105,-0.15942566186321,-0.16021461654536001,-0.16100357122751999,-0.16157775491286999,-0.1617223966046,-0.16186703829633001,-0.16201167998804999,-0.16215632167978,-0.16223730432969999,-0.16228990130851001,-0.16234249828732,-0.16239509526613,-0.16247885088601,-0.1631560369882,-0.16383322309038001,-0.16451040919257001,-0.16518759529474999,-0.16597748920867,-0.16693080944961,-0.16788412969055,-0.16883744993149,-0.16979077017242999,-0.17031073185893,-0.17069863457765999,-0.17108653729639001,-0.17147444001511,-0.17180904505832001,-0.17176959732420999,-0.1717301495901,-0.17169070185599,-0.17165125412189,-0.17182774024295999,-0.17223536682873999,-0.17264299341452,-0.17305062000030999,-0.17345824658608999,-0.17433047981802999,-0.17529037468132,-0.17625026954461001,-0.17721016440789999,-0.17811233378878,-0.17878294526860999,-0.17945355674843999,-0.18012416822828001,-0.18079477970811,-0.18110231102298999,-0.18112203489004,-0.18114175875710001,-0.18116148262414999,-0.18118120649121,-0.18131536754912,-0.18146000924085001,-0.18160465093257999,-0.18174929262431,-0.18208154213388,-0.18290994455014001,-0.18373834696641,-0.18456674938267001,-0.18539515179894001,-0.18626514876476999,-0.18715929740455001,-0.18805344604433,-0.1889475946841,-0.18984174332388001,-0.19007136312763001,-0.19029490028758,-0.19051843744752001,-0.19074197460747,-0.19087826757240001,-0.19085196908298999,-0.19082567059359001,-0.19079937210417999,-0.19077307361477999,-0.19117005557389999,-0.19174204771846001,-0.19231403986302001,-0.19288603200759,-0.19348655890766001,-0.19449247612741,-0.19549839334715999,-0.19650431056691001,-0.19751022778666,-0.19830426624709999,-0.19881051216814999,-0.19931675808919999,-0.19982300401024999,-0.2003292499313,-0.20039316241661001,-0.20033399081545,-0.20027481921428,-0.20021564761312,-0.20020454082479999,-0.2004872495859,-0.20076995834701,-0.20105266710812,-0.20133537586922001,-0.20194935018280999,-0.2028960958014,-0.20384284141999001,-0.20478958703858,-0.20573633265717001,-0.20655346429225999,-0.20734899359677,-0.20814452290127,-0.20894005220577999,-0.20957978830491,-0.20965210915078,-0.20972442999664001,-0.20979675084251001,-0.20986907168836999,-0.20991498968573999,-0.20994128817515001,-0.20996758666455001,-0.20999388515396,-0.21002018364337,-0.21072049273707999,-0.21146999968513,-0.21221950663318001,-0.21296901358122999,-0.21378912690446,-0.21478189487950999,-0.21577466285456001,-0.21676743082961,-0.21776019880465,-0.21832232156147,-0.21865105267903001,-0.21897978379659999,-0.21930851491417,-0.21963433888579001,-0.21953571955052001,-0.21943710021525001,-0.21933848087998001,-0.21923986154471001,-0.21934046370259999,-0.21978753802248999,-0.22023461234238001,-0.22068168666226001,-0.22112876098215001,-0.22200385663471001,-0.22304264696622,-0.22408143729772001,-0.22512022762923001,-0.22612681572880999,-0.22677112871923999,-0.22741544170967001,-0.22805975470008999,-0.22870406769052001,-0.22903891126878001,-0.22897973966762,-0.22892056806645,-0.22886139646529,-0.22880222486412999,-0.22890573416794999,-0.22905037585967999,-0.22919501755141,-0.22933965924314001,-0.22960465677669001,-0.23051852928352001,-0.23143240179034999,-0.23234627429717999,-0.23326014680401,-0.23417740352687999,-0.23509785065607,-0.23601829778524999,-0.23693874491443001,-0.23785919204361999,-0.23810234871152999,-0.23824699040326,-0.23839163209499001,-0.23853627378671999,-0.23862921300608,-0.23855031753785999,-0.23847142206964,-0.23839252660143001,-0.23831363113321,-0.2386572408746,-0.23929497924268001,-0.23993271761075999,-0.24057045597883001,-0.24120819434690999,-0.24226345850539999,-0.24334169657101001,-0.24441993463663,-0.24549817270224,-0.2463872226553,-0.24684744621988999,-0.24730766978447999,-0.24776789334907001,-0.24822811691366001,-0.24828210037746001,-0.24813088406337999,-0.2479796677493,-0.24782845143522,-0.24768752194522001,-0.24798995457337999,-0.24829238720154001,-0.2485948198297,-0.24889725245787001,-0.24948521154242001,-0.25053715111863001,-0.25158909069483998,-0.25264103027105,-0.25369296984725997,-0.25456022366001002,-0.25536232758686001,-0.25616443151371998,-0.25696653544058001,-0.25768722437274999,-0.25765435126099001,-0.25762147814924002,-0.25758860503747999,-0.25755573192572001,-0.25753484520029002,-0.25752827057793998,-0.25752169595558999,-0.25751512133324,-0.25750854671089002,-0.25819239688606999,-0.25903394854703998,-0.25987550020799999,-0.26071705186896998,-0.26159599389922999,-0.26265450809779001,-0.26371302229635002,-0.26477153649490998,-0.26583005069346999,-0.26645947015163002,-0.26670930580098001,-0.26695914145033001,-0.26720897709968,-0.26745881274902999,-0.26731709311168,-0.26712642906348999,-0.26693576501529998,-0.26674510096712001,-0.26672668904284003,-0.26723293496389999,-0.26773918088495002,-0.268245426806,-0.26875167272704997,-0.26964801290760998,-0.27079857181909001,-0.27194913073056998,-0.27309968964204001,-0.27425024855351998,-0.27488758439369998,-0.27550559889471998,-0.27612361339574998,-0.27674162789676998,-0.27710136857099998,-0.27691727914517,-0.27673318971932998,-0.27654910029349,-0.27636501086766002,-0.27639560298798999,-0.27652709543500997,-0.27665858788204001,-0.27679008032906,-0.27695654797799002,-0.27799533830949003,-0.27903412864100002,-0.28007291897251002,-0.28111170930401003,-0.28212440986428,-0.28309745397227998,-0.28407049808027002,-0.28504354218826,-0.28601658629625998,-0.28627474085552002,-0.28630103934493001,-0.28632733783433001,-0.28635363632374,-0.28635831757412,-0.28619395201532999,-0.28602958645655002,-0.28586522089777,-0.28570085533898998,-0.28596132070656,-0.28669767840991001,-0.28743403611325002,-0.28817039381659998,-0.28890675151994999,-0.29001960698488,-0.29120961363046999,-0.29239962027604999,-0.29358962692163998,-0.29462990809722001,-0.29502438543829002,-0.29541886277937002,-0.29581334012045002,-0.29620781746153002,-0.29622862964475,-0.29593934626129997,-0.29565006287784001,-0.29536077949438,-0.29507149611091998,-0.29534731717242002,-0.29568262291233999,-0.29601792865226001,-0.29635323439216998,-0.29691681817617999,-0.29811997406647001,-0.29932312995676003,-0.30052628584704999,-0.30172944173734001,-0.30269158777517002,-0.30350684094674002,-0.30432209411830002,-0.30513734728985997,-0.30595260046141998,-0.30578246533608999,-0.30559180128789998,-0.30540113723971002,-0.30521047319152,-0.30506201493897001,-0.30499626871545998,-0.30493052249195002,-0.30486477626843,-0.30479903004491998,-0.30546558642888,-0.30645177978158,-0.30743797313427002,-0.30842416648697002,-0.30942002050924,-0.31058372866542,-0.31174743682160999,-0.31291114497778999,-0.31407485313396999,-0.31481256750542003,-0.31494405995245001,-0.31507555239946999,-0.31520704484649997,-0.31533853729352002,-0.31511013998191001,-0.31477483424198999,-0.31443952850208001,-0.31410422276215999,-0.31388788637907999,-0.31447302776834002,-0.31505816915760998,-0.31564331054687,-0.31622845193614002,-0.31717579389236,-0.31850386760732002,-0.31983194132228998,-0.32116001503725,-0.32248808875221002,-0.32318778659986003,-0.32377292798912999,-0.3243580693784,-0.32494321076765997,-0.32533245524604998,-0.32495770177202998,-0.324582948298,-0.32420819482398,-0.32383344134996001,-0.32372859028647,-0.32383378424408998,-0.32393897820171003,-0.32404417215933001,-0.32414936611695,-0.32529564630594998,-0.32653167530799998,-0.32776770431003999,-0.32900373331208999,-0.33019025138254998,-0.33124876558110999,-0.33230727977967001,-0.33336579397823002,-0.33442430817678998,-0.33470780708525,-0.33455001614882002,-0.33439222521238998,-0.33423443427596,-0.33407664333953002,-0.33376832187729,-0.33345931462678002,-0.33315030737626999,-0.33284130012576002,-0.33295789904051998,-0.33385204768028998,-0.33474619632007002,-0.33564034495985001,-0.33653449359963,-0.33777973601803002,-0.33916698133416001,-0.34055422665028001,-0.34194147196641,-0.34325153628499999,-0.34354081966846001,-0.34383010305190997,-0.34411938643536999,-0.34440866981883,-0.34434574129061002,-0.34381319688015,-0.34328065246970002,-0.34274810805924,-0.34221556364877997,-0.34239692482996997,-0.34277167830400002,-0.34314643177802001,-0.34352118525205,-0.34405432600012997,-0.34552046678447002,-0.34698660756881,-0.34845274835314999,-0.34991888913750002,-0.35107392058119002,-0.35192204686450002,-0.35277017314782,-0.35361829943113998,-0.35446642571446002,-0.35419284091907,-0.35373919197683001,-0.35328554303458998,-0.35283189409235,-0.35243753601879002,-0.35225344659295998,-0.35206935716712001,-0.35188526774127998,-0.35170117831545,-0.35234204745607001,-0.35358465108046999,-0.35482725470486998,-0.35606985832926002,-0.35731246195366001,-0.35865973774025001,-0.36001410994462002,-0.36136848214898998,-0.36272285435335999,-0.36365472134811999,-0.36357582587991,-0.36349693041169001,-0.36341803494348002,-0.36333913947525998,-0.36291675353317998,-0.36231188827686001,-0.36170702302053998,-0.36110215776422,-0.36051242457521998,-0.36124220765621001,-0.36197199073720998,-0.36270177381820001,-0.36343155689919998,-0.36450641074876999,-0.36616979020364998,-0.36783316965853002,-0.36949654911341001,-0.37115992856829,-0.37199539758545003,-0.37252136737356001,-0.37304733716166,-0.37357330694976998,-0.37398937171299002,-0.37323986476493998,-0.37249035781688999,-0.37174085086884001,-0.37099134392078997,-0.37060124966128,-0.37066042126243998,-0.37071959286360001,-0.37077876446476998,-0.37083793606593002,-0.37215317361344002,-0.37377710533421998,-0.37540103705499001,-0.37702496877576003,-0.37858327354054999,-0.37979957867553998,-0.38101588381052998,-0.38223218894552002,-0.38344849408051002,-0.38376349452419001,-0.38324409935844,-0.38272470419268001,-0.38220530902693001,-0.38168591386118,-0.38109728389677999,-0.38049899326282,-0.37990070262885001,-0.37930241199488002,-0.37912895228726001,-0.38033210817754998,-0.38153526406784,-0.38273841995813002,-0.38394157584841998,-0.38549236675908999,-0.38728066403865002,-0.38906896131820001,-0.39085725859775999,-0.39264555587730998,-0.39280585143177998,-0.39288474690000003,-0.39296364236821002,-0.39304253783643001,-0.39277625817697998,-0.39174404246783001,-0.39071182675867,-0.38967961104951998,-0.38864739534036002,-0.38861352336308003,-0.38907374692766999,-0.38953397049226002,-0.38999419405684999,-0.39049717502939002,-0.39252873333594002,-0.39456029164249001,-0.39659184994905,-0.3986234082556,-0.40022918149559999,-0.40115620324713003,-0.40208322499866,-0.40301024675019997,-0.40393726850173001,-0.40339240971925,-0.40234047014303997,-0.40128853056684,-0.40023659099063003,-0.39924637235894,-0.39879929803905001,-0.39835222371916001,-0.39790514939927002,-0.39745807507938002,-0.39805208699087002,-0.39986668275983001,-0.40168127852878999,-0.40349587429775002,-0.40531047006671,-0.40713044778277002,-0.40895161817407999,-0.41077278856539001,-0.41259395895671003,-0.41399184889948998,-0.41341985675492998,-0.41284786461036999,-0.4122758724658,-0.41170388032124,-0.41075893862398,-0.40949003651018001,-0.40822113439636998,-0.40695223228256999,-0.40568333016877001,-0.40651729343342002,-0.40760210612137998,-0.40868691880934999,-0.40977173149731,-0.41121067928581001,-0.41370246115694997,-0.41619424302809999,-0.41868602489924001,-0.42117780677039002,-0.42239028043611998,-0.42278475777719998,-0.42317923511827998,-0.42357371245934999,-0.42396818980043,-0.42230648009090999,-0.42057735441251998,-0.41884822873411998,-0.41711910305573002,-0.41593097487366998,-0.41585865402781003,-0.41578633318194003,-0.41571401233608002,-0.41564169149021002,-0.41745135256530003,-0.42012722386228002,-0.42280309515926001,-0.42547896645625,-0.42811234869721998,-0.42980202664150002,-0.43149170458579,-0.43318138253006999,-0.43487106047436003,-0.43525189659218999,-0.43368056185023002,-0.43210922710826999,-0.43053789236631002,-0.42896655762433999,-0.42748512077984002,-0.42603212924020001,-0.42457913770055999,-0.42312614616091998,-0.42209721030871999,-0.42424053719525001,-0.42638386408176998,-0.4285271909683,-0.43067051785483002,-0.43324902212555999,-0.43630622151891002,-0.43936342091226999,-0.44242062030563001,-0.44547781969898997,-0.44546817393784999,-0.44485015943682998,-0.44423214493580998,-0.44361413043477999,-0.44259060634656,-0.43986871269312,-0.43714681903968,-0.43442492538624,-0.43170303173279001,-0.43089395065568997,-0.43164345760373002,-0.43239296455178,-0.43314247149982998,-0.43389197844788002,-0.43770834545886,-0.44183063367313002,-0.44595292188739999,-0.45007521010167001,-0.45342345207448997,-0.45465290645418999,-0.45588236083388001,-0.45711181521357003,-0.45834126959326998,-0.45662869228406,-0.45315729168257002,-0.44968589108107998,-0.44621449047959,-0.44274308987810002,-0.44114806562386,-0.43958330550424002,-0.43801854538462998,-0.43645378526501999,-0.43694209633190001,-0.44137339179668,-0.44580468726146,-0.45023598272624998,-0.45466727819102998,-0.45882217116511997,-0.46285898928882002,-0.46689580741252001,-0.47093262553623,-0.47454461273357001,-0.47137564476024002,-0.46820667678691003,-0.46503770881357998,-0.46186874084024998,-0.45795363522646998,-0.45299636997359,-0.44803910472070002,-0.44308183946781998,-0.43812457421493001,-0.43957125948414999,-0.44287171990451002,-0.44617218032486999,-0.44947264074521998,-0.45343104047081001,-0.46164931840994,-0.46986759634907999,-0.47808587428820998,-0.48630415222735002,-0.49008706469738,-0.48929153539288001,-0.48849600608837002,-0.48770047678386003,-0.48690494747934998,-0.47783523358306002,-0.46730926319861998,-0.45678329281418001,-0.44625732242973998,-0.43765430236130998,-0.43634595251340003,-0.43503760266549002,-0.43372925281758001,-0.43242090296967001,-0.44161182248889003,-0.45882418380460999,-0.47603654512033,-0.49324890643606001,-0.51046126775178002,-0.52073941512637001,-0.53045670696159997,-0.54017399879683003,-0.54989129063205999,-0.54654319774365001,-0.51016581227387003,-0.47378842680409,-0.43741104133431002,-0.40103365586452999,-0.33435899429805999,-0.25076924572355003,-0.16717949714904001,-0.083589748574510001,0.0,0.0,0.041867195133122002,0.083734390266243006,0.12560158539936001,0.16746878053249001,0.20097854234092999,0.21951897737161,0.2380594124023,0.25659984743297998,0.27514028246367001,0.27722024847719001,0.27278895301241002,0.26835765754763002,0.26392636208284997,0.25919545168519997,0.25076021120848002,0.24232497073174999,0.23388973025502,0.22545448977829999,0.22096590117588,0.22164308727807,0.22232027338025001,0.22299745948244001,0.22367464558462,0.22817086730868,0.23367382621672,0.23917678512476001,0.24467974403281001,0.24948606132355,0.25033418760685999,0.25118231389017998,0.25203044017350001,0.25287856645682,0.25135231483955001,0.24752588463108999,0.24369945442263,0.23987302421417001,0.23604659400570999,0.23413938700308001,0.23252860452700999,0.23091782205094,0.22930703957487,0.22864233183756,0.23124588228868001,0.23384943273979,0.23645298319090999,0.23905653364203,0.24129992598257,0.24328546193267001,0.24527099788275999,0.24725653383286,0.24924206978294999,0.24782475414192001,0.2461942477988,0.24456374145567,0.24293323511254999,0.24116103894895999,0.23905715979653999,0.23695328064412,0.2348494014917,0.23274552233928,0.23256557745996001,0.23338740525387999,0.23420923304779001,0.2350310608417,0.23587229942542001,0.23791700697667001,0.23996171452793,0.24200642207918999,0.24405112963044001,0.24526931322896001,0.24510494767018001,0.24494058211139999,0.24477621655262,0.24461185099383001,0.24321473628995999,0.24136726740924,0.23951979852852001,0.23767232964780999,0.23596022940870001,0.23560519980173,0.23525017019475999,0.23489514058779001,0.23454011098082,0.23504112403918001,0.23659273491409,0.23814434578900001,0.23969595666391,0.24124756753880999,0.24214636761208999,0.24288929993778999,0.24363223226349001,0.24437516458919001,0.24479813196045,0.24360812531487,0.24241811866928001,0.24122811202368999,0.24003810537810999,0.23894108267719999,0.23792859083510001,0.23691609899300001,0.2359036071509,0.2348911153088,0.23548505267808001,0.23629373122729,0.23710240977649999,0.23791108832571001,0.23880352249480999,0.23996065602864,0.24111778956246999,0.2422749230963,0.24343205663013001,0.24364065553249001,0.24321330507965,0.24278595462682001,0.24235860417398,0.24193125372115001,0.24078039664084999,0.23959696461762001,0.23841353259438,0.23723010057114999,0.2364383281937,0.23649749979486001,0.23655667139601999,0.23661584299718,0.23667501459835,0.23745149091563,0.23857575133770001,0.23970001175978001,0.24082427218185001,0.24192098180550001,0.24217739207719999,0.2424338023489,0.2426902126206,0.24294662289230001,0.24272095382534001,0.24174133509498999,0.24076171636464999,0.2397820976343,0.23880247890396,0.23817216493935001,0.23765934439594999,0.23714652385255,0.23663370330915001,0.23625751862482,0.23702674943992,0.23779598025502,0.23856521107013001,0.23933444188523001,0.24007311039688001,0.24077659498847001,0.24148007958005999,0.24218356417164999,0.24288704876323999,0.24257853349128,0.24205256370316999,0.24152659391507,0.24100062412695999,0.24042098395232001,0.2395991561584,0.23877732836449,0.23795550057057999,0.23713367277666,0.23690439586705,0.2371805300058,0.23745666414455999,0.23773279828331001,0.23800893242207,0.23879869216002,0.23964681844333999,0.24049494472666,0.24134307100998001,0.24197050764552999,0.24195735840082,0.24194420915612,0.24193105991142,0.24191791066672,0.24141185855538999,0.24059660538382999,0.23978135221227001,0.23896609904071001,0.23815084586915,0.23791760331430001,0.23770064077670999,0.23748367823912001,0.23726671570152,0.23735883495664001,0.23807546879294,0.23879210262923001,0.23950873646552001,0.24022537030180999,0.24073352450327001,0.24114772571140999,0.24156192691954001,0.24197612812767,0.24234336774758,0.24177137560302001,0.24119938345844999,0.24062739131388999,0.24005539916933,0.23948874424652999,0.23892990134667,0.23837105844681,0.23781221554695001,0.23725337264709001,0.23741800655781001,0.23780590927653,0.23819381199525999,0.23858171471399001,0.23900181966463999,0.23965270727742,0.24030359489020001,0.24095448250297999,0.24160537011576,0.24185170228153999,0.24166103823335,0.24147037418516001,0.24127971013697999,0.24108904608879,0.24049018893407001,0.23981300283189,0.2391358167297,0.23845863062752001,0.23791244499382,0.23789929574911001,0.23788614650441001,0.23787299725971001,0.23785984801501001,0.23821560813557,0.23886649574835001,0.23951738336112999,0.24016827097391,0.24081915858669001,0.24105548718875999,0.24125272585929999,0.24144996452983999,0.24164720320038,0.24163512736341,0.24106313521884001,0.24049114307427999,0.23991915092971,0.23934715878515,0.23890779212911001,0.23854618789977999,0.23818458367046,0.23782297944114,0.23746137521182001,0.23791228100097001,0.23837250456556,0.23883272813015,0.23929295169473999,0.23976001823362,0.24023996566526001,0.24071991309690999,0.24119986052855999,0.2416798079602,0.2416033723847,0.24129436513419,0.24098535788368,0.24067635063317,0.24035189823808001,0.23979962996057,0.23924736168307001,0.23869509340556,0.23814282512804999,0.23788171869752001,0.2380197857669,0.23815785283627999,0.23829591990564999,0.23843398697502999,0.23891566378580001,0.23949423055270999,0.24007279731962999,0.24065136408654,0.24115444941816999,0.24118732252992001,0.24122019564168001,0.24125306875343,0.24128594186519001,0.24102496961063,0.24046612671077,0.23990728381091,0.23934844091105001,0.23878959801119001,0.23854550211150999,0.23835483806332,0.23816417401514001,0.23797350996694999,0.23792859083510001,0.23842168751144999,0.23891478418779999,0.23940788086414999,0.23990097754049,0.24029639411334,0.24061855060855,0.24094070710376,0.24126286359898,0.24158502009419,0.24125314329563999,0.24087181519925999,0.24049048710289,0.24010915900651,0.23971457730635001,0.23928722685351,0.23885987640067999,0.23843252594784001,0.23800517549500999,0.23801546231910001,0.23826529796844001,0.23851513361779,0.23876496926714,0.23901590814111001,0.23950900481744999,0.2400021014938,0.24049519817015,0.2409882948465,0.24126432462617001,0.24115913066854999,0.24105393671093001,0.24094874275330999,0.24084354879568001,0.24044442002110999,0.23993159947770001,0.2394187789343,0.23890595839090001,0.23843018532265001,0.23838416296619,0.23833814060972999,0.23829211825327001,0.23824609589682,0.23843601452297,0.23892911119932,0.23942220787565999,0.23991530455200999,0.24040840122835999,0.24065555335837999,0.24083964278421999,0.24102373221005999,0.24120782163589,0.2412976300827,0.24087027962987001,0.24044292917703,0.24001557872420001,0.23958822827137,0.23922152535532001,0.23891251810481001,0.23860351085430001,0.23829450360379001,0.23798549635328001,0.23823752354340999,0.23857282928333001,0.23890813502323999,0.23924344076316001,0.23959229827567999,0.23998677561675999,0.24038125295783,0.24077573029891,0.24117020763999,0.24120944665593,0.24099905874069,0.24078867082545,0.2405782829102,0.24036789499496,0.23992748474806999,0.23947383580583001,0.23902018686359,0.23856653792134999,0.23827470519453001,0.23835360066274999,0.23843249613095999,0.23851139159918,0.23859028706738999,0.23893037841678,0.23940375122606999,0.23987712403535999,0.24035049684466001,0.24081528239211,0.24086787937092,0.24092047634972999,0.24097307332854001,0.24102567030735,0.24088904935672001,0.24044197503683001,0.23999490071693999,0.23954782639705,0.23910075207716,0.23884748748644999,0.23866339806060999,0.23847930863478001,0.23829521920894001,0.23816560522544,0.23855350794416999,0.23894141066290001,0.23932931338162999,0.23971721610034999,0.24006337518509999,0.24035923319090999,0.24065509119671999,0.24095094920252999,0.24124680720833999,0.24105697803282999,0.24075454540467001,0.24045211277650999,0.24014968014835,0.23983494805660999,0.23946019458258,0.23908544110856,0.23871068763452999,0.23833593416050999,0.23825644235467,0.23844053178050001,0.23862462120634001,0.23880871063218001,0.23899280005800999,0.23939839909586,0.23983232417104,0.24026624924623,0.24070017432141999,0.24101173091528999,0.24094598469177,0.24088023846826001,0.24081449224474999,0.24074874602124,0.24045695801974001,0.2400164583222,0.23957595862466,0.23913545892713001,0.23869495922959,0.23860844554817001,0.23853612470231,0.23846380385644,0.23839148301058,0.23847681892518,0.23889759475566,0.23931837058614999,0.23973914641662999,0.24015992224711,0.24042468124561001,0.24061534529379999,0.24080600934199001,0.24099667339017,0.24116730049405,0.24080569626473,0.24044409203541001,0.24008248780609001,0.23972088357676999,0.23938522003427001,0.23908936202846001,0.23879350402266,0.23849764601685,0.23820178801104,0.23833654540658,0.23861267954533,0.23888881368409001,0.23916494782284001,0.23945203966552001,0.23982679313954,0.24020154661356999,0.24057630008759001,0.24095105356161001,0.24107275116310001,0.24090838560430999,0.24074402004553,0.24057965448675001,0.24041528892797001,0.24003870171573,0.23961792588524999,0.23919715005476999,0.23877637422428,0.23844117284345001,0.23848062057756,0.23852006831167,0.23855951604577999,0.23859896377987999,0.23885309306016,0.23928701813534001,0.23972094321053,0.24015486828572,0.2405887933609,0.24070823978784001,0.24079370987839999,0.24087917996896999,0.24096465005953999,0.24092153484902001,0.24051390826324001,0.24010628167744999,0.23969865509166999,0.23929102850589001,0.23900957205380999,0.23880575876092,0.23860194546801999,0.23839813217513001,0.23819431888223999,0.23853025077667001,0.23887870576129,0.23922716074590999,0.23957561573052999,0.23990862557057999,0.24021105819874,0.24051349082689999,0.24081592345506,0.24111835608321999,0.24102845818575999,0.24076547329171,0.24050248839766,0.24023950350359999,0.23997068940923,0.23959593593521,0.23922118246119001,0.23884642898715999,0.23847167551314,0.23831279626053001,0.23846401257461,0.23861522888869,0.23876644520276999,0.23891766151685001,0.23927609024831001,0.23969686607879001,0.24011764190927001,0.24053841773976001,0.24090242222802999,0.24087612373862999,0.24084982524922,0.24082352675981999,0.24079722827041,0.24057312458971999,0.24013919951453,0.23970527443935,0.23927134936416,0.23883742428897001,0.2386918880908,0.23859984337789,0.23850779866496999,0.23841575395205,0.23842322308083999,0.23882427504427001,0.23922532700769999,0.23962637897113001,0.24002743093456,0.24032169373720999,0.24053208165246001,0.24074246956770001,0.24095285748294001,0.24116324539817999,0.24087248607909001,0.24053718033918001,0.24020187459926001,0.23986656885933999,0.23953671960872999,0.23922113773586001,0.238905555863,0.23858997399014001,0.23827439211727999,0.23831780549661,0.23856764114595999,0.23881747679531001,0.23906731244466001,0.23931714809401,0.23970411158096999,0.24009201429970001,0.24047991701843,0.24086781973714999,0.24107085779112999,0.24093279072175,0.24079472365237001,0.24065665658298999,0.24051858951362001,0.24017520339883999,0.23974785294600001,0.23932050249317,0.23889315204032999,0.23849532030010001,0.23850189492245,0.23850846954480001,0.23851504416715,0.23852161878950001,0.23871317734413,0.23915367704167001,0.23959417673920999,0.24003467643674001,0.24047517613427999,0.24065775980761001,0.24076952838758001,0.24088129696755001,0.24099306554752001,0.24103157404987,0.24063052208644001,0.24022947012300999,0.23982841815958,0.23942736619614999,0.23910868336762001,0.23887199696297001,0.23863531055831999,0.23839862415367999,0.23816193774902999,0.23842247765881,0.23876435802108001,0.23910623838334,0.23944811874561001,0.23978856789757,0.24012387363748999,0.2404591793774,0.24079448511731999,0.24112979085724001,0.24112807638656,0.24087824073721001,0.24062840508785999,0.24037856943850999,0.24012873378916,0.23973148347810999,0.23932385689232999,0.23891623030654999,0.23850860372077001,0.23825867862076999,0.2383901710678,0.23852166351481999,0.23865315596184999,0.23878464840888,0.23912151953506999,0.23956859385495999,0.24001566817483999,0.24046274249472999,0.24090576171875,0.24090576171875,0.24090576171875,0.24090576171875,0.24090576171875,0.24073911516853999,0.24028546622630001,0.23983181728406,0.23937816834181999,0.23892451939958001,0.23870463480761001,0.23857314236058,0.23844164991354999,0.23831015746653,0.23822444884091001,0.23863865004904,0.23905285125718001,0.23946705246531,0.23988125367343999,0.24022859052501,0.24049157541905999,0.24075456031310999,0.24101754520716001,0.24128053010122,0.24105408579533,0.24070563081071,0.24035717582609001,0.24000872084148001,0.23965817867516001,0.23929657444583999,0.23893497021651,0.23857336598719001,0.23821176175787001,0.23816287698079999,0.23840613800779001,0.23864939903478999,0.23889266006179,0.23913592108879,0.23955182185915999,0.2399923215567,0.24043282125424001,0.24087332095177,0.24118329725092999,0.24106495404861,0.24094661084628,0.24082826764396001,0.24070992444163999,0.24037367946995999,0.23988715741596001,0.23940063536195999,0.23891411330796999,0.23842759125397001,0.23838458040252999,0.23836485653548001,0.23834513266842,0.23832540880136999,0.23846180612539,0.23894832817938999,0.23943485023337999,0.23992137228738,0.24040789434137999,0.24067964539855999,0.24084401095735,0.24100837651613,0.24117274207490999,0.24132185629885,0.24087478197896001,0.24042770765907001,0.23998063333919001,0.23953355901930001,0.23914443380843001,0.23884857580262001,0.23855271779681,0.23825685979101,0.23796100178519999,0.23815752485058,0.23852570370225001,0.23889388255392999,0.2392620614056,0.23963417608561999,0.24004180267139999,0.24044942925717999,0.24085705584295999,0.24126468242874,0.24137115851227001,0.24112132286292001,0.24087148721356999,0.24062165156422,0.24037181591487,0.23992339983531999,0.23943030315896999,0.23893720648262001,0.23844410980627001,0.23805662452387999,0.23816839310386001,0.23828016168383001,0.23839193026380001,0.23850369884377001,0.23884319385552999,0.23938231288834,0.23992143192113999,0.24046055095395,0.24099966998676001,0.24109350371256,0.24113295144666999,0.24117239918078001,0.24121184691488001,0.24110698094295999,0.24056786191015,0.24002874287734,0.23948962384454001,0.23895050481173,0.2386191498086,0.23842191113805999,0.23822467246751999,0.23802743379697999,0.23783019512643999,0.23829346001293999,0.23877998206692999,0.23926650412093001,0.23975302617493,0.24019691008850999,0.24055193969548,0.24090696930245001,0.24126199890941999,0.24161702851639,0.24145600244832,0.24105495048489001,0.24065389852145999,0.24025284655803,0.23984857437140999,0.23936862693977001,0.23888867950812001,0.23840873207648,0.23792878464483,0.23774796016750999,0.23801751968390999,0.23828707920032,0.23855663871672,0.23882619823312001,0.23932481103253,0.23989680317709999,0.24046879532165999,0.24104078746622001,0.24153370524128001,0.24142193666131001,0.24131016808134001,0.24119839950137001,0.24108663092138999,0.24073494080513999,0.24011692630411999,0.23949891180310001,0.23888089730206999,0.23826288280105001,0.23810446571011001,0.23803871948659999,0.23797297326308001,0.23790722703957001,0.23797046864504001,0.23858190852371999,0.23919334840239001,0.23980478828106,0.24041622815972999,0.24083284453525999,0.24108925480696,0.24134566507866001,0.24160207535035999,0.24185848562206,0.24137543723475,0.24081659433489,0.24025775143503,0.23969890853517001,0.23917495138656,0.23874760093371999,0.23832025048089001,0.23789290002805,0.23746554957522001,0.2375834753412,0.23803054966109,0.23847762398097999,0.23892469830086999,0.23937177262076001,0.23994795403715999,0.24052652080407,0.24110508757099,0.24168365433790001,0.24196479771273999,0.24166893970693001,0.24137308170112001,0.24107722369531001,0.24078136568950001,0.24020999969945001,0.23951966435256,0.23882932900567,0.23813899365878,0.23749375634503,0.23759895030264999,0.23770414426027001,0.23780933821790001,0.23791453217552,0.23828709410876001,0.23903660105680999,0.23978610800485001,0.24053561495289999,0.24128512190095,0.24154150235576999,0.24165327093573999,0.24176503951572001,0.24187680809569001,0.24187616703274001,0.24113323470704001,0.24039030238133999,0.23964737005565001,0.23890443772994999,0.23835793901898999,0.23801605865671999,0.23767417829446,0.23733229793218999,0.23699041756992001,0.23751277951537,0.23818996561756001,0.23886715171973999,0.23954433782192999,0.24019710389824001,0.2407559467981,0.24131478969796,0.24187363259781999,0.24243247549767999,0.24236766850593,0.24182197485077001,0.24127628119561001,0.24073058754046001,0.24018489388530001,0.23945110043375001,0.2387015934857,0.23795208653764999,0.23720257958961,0.23676364527834001,0.23711867488530999,0.23747370449228,0.23782873409925001,0.23818376370621999,0.23888353609608001,0.23977768473586,0.24067183337563,0.24156598201540999,0.24246013065519001,0.24235720278056,0.24225200882292999,0.24214681486531001,0.24204162090768999,0.24162512379969001,0.24064550506935001,0.23966588633899999,0.23868626760865999,0.23770664887831,0.2372999615243,0.23712244672081001,0.23694493191732999,0.23676741711384,0.23667386664841,0.23765348537875999,0.23863310410909999,0.23961272283943999,0.24059234156979001,0.24135951502007999,0.24184603707407001,0.24233255912807,0.24281908118206999,0.24330560323605999,0.24269742830591001,0.24179670504378001,0.24089598178165,0.23999525851952,0.23911100908437,0.23832205440220999,0.23753309972006001,0.23674414503790001,0.23595519035574,0.23593088959739,0.23665409805602999,0.23737730651468,0.23810051497331999,0.23882372343197,0.23985365814969001,0.24093189621531,0.24201013428092,0.24308837234653999,0.24382326902269,0.24335647083574999,0.24288967264881001,0.24242287446186001,0.24195607627492,0.24100457486374999,0.23970279963819,0.23840102441263,0.23709924918707001,0.23579747396150999,0.23581652694874,0.23592172090635999,0.23602691486398,0.23613210882159999,0.23663962196011001,0.23809918812209999,0.23955875428408999,0.24101832044607999,0.24247788660806999,0.24319207546009,0.2435142319553,0.24383638845051001,0.24415854494573,0.24445592361248999,0.24295690971639,0.24145789582029001,0.23995888192420001,0.23845986802810001,0.23721268751239999,0.23639085971849,0.23556903192458001,0.23474720413066,0.23392537633675001,0.23474052514922999,0.23616064357711,0.23758076200499001,0.23900088043286999,0.24041576599806999,0.24177671282478999,0.24313765965150999,0.24449860647822999,0.24585955330494999,0.24608095855786999,0.24489095191228999,0.2437009452667,0.24251093862111001,0.24132093197553001,0.23954345822393,0.23762366849734001,0.23570387877075999,0.23378408904417999,0.23230332307950999,0.23307255389461001,0.23384178470971001,0.23461101552482,0.23538024633992,0.23704443085060001,0.23952963809939001,0.24201484534817999,0.24450005259697999,0.24698525984576999,0.247168246047,0.24703675359996999,0.24690526115294001,0.24677376870591999,0.24595663707082999,0.24294546003393,0.23993428299703001,0.23692310596013,0.23391192892323001,0.23221426005473,0.23140558150552001,0.23059690295631,0.22978822440710001,0.22897954585788999,0.23228194437552999,0.23577964346642999,0.23927734255732,0.24277504164822,0.24586332514045001,0.24805267438343001,0.25024202362642001,0.25243137286939998,0.25462072211239001,0.25269725000095,0.24875905121252001,0.24482085242408999,0.24088265363566,0.23693050054671999,0.232518928949,0.22810735735127,0.22369578575353999,0.21928421415581001,0.21827856528799999,0.22265068915162001,0.22702281301523999,0.23139493687884999,0.23576706074247,0.24360202776261999,0.25261583500626,0.26162964224989999,0.27064344949354002,0.27815812357356001,0.27279980635724999,0.26744148914093002,0.26208317192462,0.25672485470829998,0.2390795969998,0.20715980548421001,0.17524001396861,0.14332022245302001,0.11140043093742,0.068303751607728003,0.022767917202574001,-0.022767917202574001,-0.068303751607721994,-0.11140043093742,-0.14332022245302001,-0.17524001396861,-0.20715980548421001,-0.2390795969998,-0.25672485470829998,-0.26208317192461,-0.26744148914093002,-0.27279980635723999,-0.27815812357356001,-0.27064344949354002,-0.26162964224989999,-0.25261583500626,-0.24360202776261999,-0.23576706074247,-0.23139493687886001,-0.22702281301523999,-0.22265068915162001,-0.21827856528799999,-0.21928421415581001,-0.22369578575353999,-0.22810735735127,-0.232518928949,-0.23693050054671999,-0.24088265363566,-0.24482085242408999,-0.24875905121252001,-0.25269725000095,-0.25462072211239001,-0.25243137286940998,-0.25024202362642001,-0.24805267438343001,-0.24586332514045001,-0.24277504164822,-0.23927734255732,-0.23577964346642999,-0.23228194437552999,-0.22897954585788999,-0.22978822440710001,-0.23059690295631,-0.23140558150552001,-0.23221426005473,-0.23391192892323001,-0.23692310596013,-0.23993428299703001,-0.24294546003393,-0.24595663707082999,-0.24677376870591999,-0.24690526115294001,-0.24703675359996999,-0.247168246047,-0.24698525984576999,-0.24450005259697999,-0.24201484534817999,-0.23952963809939001,-0.23704443085060001,-0.23538024633992,-0.23461101552482,-0.23384178470971001,-0.23307255389461001,-0.23230332307950999,-0.23378408904417999,-0.23570387877075999,-0.23762366849734001,-0.23954345822393,-0.24132093197553001,-0.24251093862111001,-0.2437009452667,-0.24489095191228999,-0.24608095855786999,-0.24585955330494999,-0.24449860647822999,-0.24313765965150999,-0.24177671282478999,-0.24041576599806999,-0.23900088043286999,-0.23758076200499001,-0.23616064357711,-0.23474052514922999,-0.23392537633675001,-0.23474720413066,-0.23556903192458001,-0.23639085971849,-0.23721268751239999,-0.23845986802810001,-0.23995888192420001,-0.24145789582029001,-0.24295690971639,-0.24445592361248999,-0.24415854494573,-0.24383638845051001,-0.2435142319553,-0.24319207546009,-0.24247788660806999,-0.24101832044607999,-0.23955875428408999,-0.23809918812209999,-0.23663962196011001,-0.23613210882159999,-0.23602691486398,-0.23592172090635999,-0.23581652694874,-0.23579747396150999,-0.23709924918707001,-0.23840102441263,-0.23970279963819,-0.24100457486374999,-0.24195607627492,-0.24242287446186001,-0.24288967264881001,-0.24335647083574999,-0.24382326902269,-0.24308837234653999,-0.24201013428092,-0.24093189621531,-0.23985365814969001,-0.23882372343197,-0.23810051497331999,-0.23737730651468,-0.23665409805602999,-0.23593088959739,-0.23595519035574,-0.23674414503790001,-0.23753309972006001,-0.23832205440220999,-0.23911100908437,-0.23999525851952,-0.24089598178165,-0.24179670504378001,-0.24269742830589999,-0.24330560323605999,-0.24281908118206999,-0.24233255912807,-0.24184603707407001,-0.24135951502007999,-0.24059234156979001,-0.23961272283945001,-0.23863310410909999,-0.23765348537875999,-0.23667386664841,-0.23676741711384,-0.23694493191732999,-0.23712244672081001,-0.2372999615243,-0.23770664887831,-0.23868626760865999,-0.23966588633899999,-0.24064550506935001,-0.24162512379969001,-0.24204162090768999,-0.24214681486531001,-0.24225200882292999,-0.24235720278056,-0.24246013065519001,-0.24156598201540999,-0.24067183337563,-0.23977768473586,-0.23888353609608001,-0.23818376370621999,-0.23782873409925001,-0.23747370449228,-0.23711867488530999,-0.23676364527834001,-0.23720257958961,-0.23795208653764999,-0.2387015934857,-0.23945110043375001,-0.24018489388530001,-0.24073058754046001,-0.24127628119561001,-0.24182197485077001,-0.24236766850593,-0.24243247549767999,-0.24187363259781999,-0.24131478969796,-0.2407559467981,-0.24019710389824001,-0.23954433782192999,-0.23886715171973999,-0.23818996561756001,-0.23751277951537,-0.23699041756992001,-0.23733229793218999,-0.23767417829446,-0.23801605865671999,-0.23835793901898999,-0.23890443772994999,-0.23964737005565001,-0.24039030238133999,-0.24113323470704001,-0.24187616703274001,-0.24187680809569001,-0.24176503951572001,-0.24165327093573999,-0.24154150235576999,-0.24128512190095,-0.24053561495289999,-0.23978610800485001,-0.23903660105680999,-0.23828709410876001,-0.23791453217552,-0.23780933821790001,-0.23770414426027001,-0.23759895030264999,-0.23749375634503,-0.23813899365878,-0.23882932900567,-0.23951966435256,-0.24020999969945001,-0.24078136568950001,-0.24107722369531001,-0.24137308170112001,-0.24166893970693001,-0.24196479771273999,-0.24168365433790001,-0.24110508757099,-0.24052652080407,-0.23994795403715999,-0.23937177262076001,-0.23892469830086999,-0.23847762398097999,-0.23803054966109,-0.2375834753412,-0.23746554957522001,-0.23789290002805,-0.23832025048089001,-0.23874760093371999,-0.23917495138656,-0.23969890853517001,-0.24025775143503,-0.24081659433489,-0.24137543723475,-0.24185848562206,-0.24160207535035999,-0.24134566507866001,-0.24108925480696,-0.24083284453525999,-0.24041622815972999,-0.23980478828106,-0.23919334840239001,-0.23858190852371999,-0.23797046864504001,-0.23790722703957001,-0.23797297326308001,-0.23803871948659999,-0.23810446571011001,-0.23826288280105001,-0.23888089730206999,-0.23949891180310001,-0.24011692630411999,-0.24073494080513999,-0.24108663092138999,-0.24119839950137001,-0.24131016808134001,-0.24142193666131001,-0.24153370524128001,-0.24104078746622001,-0.24046879532165999,-0.23989680317709999,-0.23932481103253,-0.23882619823312001,-0.23855663871672,-0.23828707920032,-0.23801751968390999,-0.23774796016750999,-0.23792878464483,-0.23840873207648,-0.23888867950812001,-0.23936862693977001,-0.23984857437140999,-0.24025284655803,-0.24065389852145999,-0.24105495048489001,-0.24145600244832,-0.24161702851639,-0.24126199890941999,-0.24090696930245001,-0.24055193969548,-0.24019691008850999,-0.23975302617493,-0.23926650412093001,-0.23877998206692999,-0.23829346001293999,-0.23783019512643999,-0.23802743379697999,-0.23822467246751999,-0.23842191113805999,-0.2386191498086,-0.23895050481173,-0.23948962384454001,-0.24002874287734,-0.24056786191015,-0.24110698094295999,-0.24121184691488001,-0.24117239918078001,-0.24113295144666999,-0.24109350371256,-0.24099966998676001,-0.24046055095395,-0.23992143192113999,-0.23938231288834,-0.23884319385552999,-0.23850369884377001,-0.23839193026380001,-0.23828016168383001,-0.23816839310386001,-0.23805662452387999,-0.23844410980627001,-0.23893720648262001,-0.23943030315896999,-0.23992339983531999,-0.24037181591487,-0.24062165156422,-0.24087148721356999,-0.24112132286292001,-0.24137115851227001,-0.24126468242874,-0.24085705584295999,-0.24044942925717999,-0.24004180267139999,-0.23963417608561999,-0.2392620614056,-0.23889388255392999,-0.23852570370225001,-0.23815752485058,-0.23796100178519999,-0.23825685979101,-0.23855271779681,-0.23884857580262001,-0.23914443380843001,-0.23953355901930001,-0.23998063333919001,-0.24042770765907001,-0.24087478197896001,-0.24132185629885,-0.24117274207490999,-0.24100837651613,-0.24084401095735,-0.24067964539855999,-0.24040789434137999,-0.23992137228738,-0.23943485023337999,-0.23894832817938999,-0.23846180612539,-0.23832540880136999,-0.23834513266842,-0.23836485653548001,-0.23838458040252999,-0.23842759125397001,-0.23891411330796999,-0.23940063536195999,-0.23988715741596001,-0.24037367946995999,-0.24070992444163999,-0.24082826764396001,-0.24094661084628,-0.24106495404861,-0.24118329725092999,-0.24087332095177,-0.24043282125424001,-0.2399923215567,-0.23955182185915999,-0.23913592108879,-0.23889266006179,-0.23864939903478999,-0.23840613800779001,-0.23816287698079999,-0.23821176175787001,-0.23857336598719001,-0.23893497021651,-0.23929657444583999,-0.23965817867516001,-0.24000872084148001,-0.24035717582609001,-0.24070563081071,-0.24105408579533,-0.24128053010122,-0.24101754520716001,-0.24075456031310999,-0.24049157541905999,-0.24022859052501,-0.23988125367343999,-0.23946705246531,-0.23905285125718001,-0.23863865004904,-0.23822444884091001,-0.23831015746653,-0.23844164991354999,-0.23857314236058,-0.23870463480761001,-0.23892451939958001,-0.23937816834181999,-0.23983181728406,-0.24028546622630001,-0.24073911516853999,-0.24090576171875,-0.24090576171875,-0.24090576171875,-0.24090576171875,-0.24090576171875,-0.24046274249472999,-0.24001566817483999,-0.23956859385495999,-0.23912151953506999,-0.23878464840888,-0.23865315596184999,-0.23852166351481999,-0.2383901710678,-0.23825867862076999,-0.23850860372077001,-0.23891623030654999,-0.23932385689232999,-0.23973148347810999,-0.24012873378916,-0.24037856943850999,-0.24062840508785999,-0.24087824073721001,-0.24112807638656,-0.24112979085724001,-0.24079448511731999,-0.2404591793774,-0.24012387363748999,-0.23978856789757,-0.23944811874561001,-0.23910623838334,-0.23876435802108001,-0.23842247765881,-0.23816193774902999,-0.23839862415367999,-0.23863531055831999,-0.23887199696297001,-0.23910868336762001,-0.23942736619614999,-0.23982841815958,-0.24022947012300999,-0.24063052208644001,-0.24103157404987,-0.24099306554752001,-0.24088129696755001,-0.24076952838758001,-0.24065775980761001,-0.24047517613427999,-0.24003467643674001,-0.23959417673920999,-0.23915367704167001,-0.23871317734413,-0.23852161878950001,-0.23851504416715,-0.23850846954480001,-0.23850189492245,-0.23849532030010001,-0.23889315204032999,-0.23932050249317,-0.23974785294600001,-0.24017520339883999,-0.24051858951362001,-0.24065665658298999,-0.24079472365237001,-0.24093279072175,-0.24107085779112999,-0.24086781973714999,-0.24047991701843,-0.24009201429970001,-0.23970411158096999,-0.23931714809401,-0.23906731244466001,-0.23881747679531001,-0.23856764114595999,-0.23831780549661,-0.23827439211727999,-0.23858997399014001,-0.238905555863,-0.23922113773586001,-0.23953671960872999,-0.23986656885933999,-0.24020187459926001,-0.24053718033918001,-0.24087248607909001,-0.24116324539817999,-0.24095285748294001,-0.24074246956770001,-0.24053208165246001,-0.24032169373720999,-0.24002743093456,-0.23962637897113001,-0.23922532700769999,-0.23882427504427001,-0.23842322308083999,-0.23841575395205,-0.23850779866496999,-0.23859984337789,-0.2386918880908,-0.23883742428897001,-0.23927134936416,-0.23970527443935,-0.24013919951453,-0.24057312458971999,-0.24079722827041,-0.24082352675981999,-0.24084982524922,-0.24087612373862999,-0.24090242222802999,-0.24053841773976001,-0.24011764190927001,-0.23969686607879001,-0.23927609024831001,-0.23891766151685001,-0.23876644520276999,-0.23861522888869,-0.23846401257461,-0.23831279626053001,-0.23847167551314,-0.23884642898715999,-0.23922118246119001,-0.23959593593521,-0.23997068940923,-0.24023950350359999,-0.24050248839766,-0.24076547329171,-0.24102845818575999,-0.24111835608321999,-0.24081592345506,-0.24051349082689999,-0.24021105819874,-0.23990862557057999,-0.23957561573052999,-0.23922716074590999,-0.23887870576129,-0.23853025077667001,-0.23819431888223999,-0.23839813217513001,-0.23860194546801999,-0.23880575876092,-0.23900957205380999,-0.23929102850589001,-0.23969865509166999,-0.24010628167744999,-0.24051390826324001,-0.24092153484902001,-0.24096465005953999,-0.24087917996896999,-0.24079370987839999,-0.24070823978784001,-0.2405887933609,-0.24015486828572,-0.23972094321053,-0.23928701813534001,-0.23885309306016,-0.23859896377987999,-0.23855951604577999,-0.23852006831167,-0.23848062057756,-0.23844117284345001,-0.23877637422428,-0.23919715005476999,-0.23961792588524999,-0.24003870171573,-0.24041528892797001,-0.24057965448675001,-0.24074402004553,-0.24090838560430999,-0.24107275116310001,-0.24095105356161001,-0.24057630008759001,-0.24020154661356999,-0.23982679313954,-0.23945203966552001,-0.23916494782284001,-0.23888881368409001,-0.23861267954533,-0.23833654540658,-0.23820178801104,-0.23849764601685,-0.23879350402266,-0.23908936202846001,-0.23938522003427001,-0.23972088357676999,-0.24008248780609001,-0.24044409203541001,-0.24080569626473,-0.24116730049405,-0.24099667339017,-0.24080600934199001,-0.24061534529379999,-0.24042468124561001,-0.24015992224711,-0.23973914641662999,-0.23931837058614999,-0.23889759475566,-0.23847681892518,-0.23839148301058,-0.23846380385644,-0.23853612470231,-0.23860844554817001,-0.23869495922959,-0.23913545892713001,-0.23957595862466,-0.2400164583222,-0.24045695801974001,-0.24074874602124,-0.24081449224474999,-0.24088023846826001,-0.24094598469177,-0.24101173091528999,-0.24070017432141999,-0.24026624924623,-0.23983232417104,-0.23939839909586,-0.23899280005800999,-0.23880871063218001,-0.23862462120634001,-0.23844053178050001,-0.23825644235467,-0.23833593416050999,-0.23871068763452999,-0.23908544110856,-0.23946019458258,-0.23983494805660999,-0.24014968014835,-0.24045211277650999,-0.24075454540467001,-0.24105697803282999,-0.24124680720833999,-0.24095094920252999,-0.24065509119671999,-0.24035923319090999,-0.24006337518509999,-0.23971721610034999,-0.23932931338162999,-0.23894141066290001,-0.23855350794416999,-0.23816560522544,-0.23829521920894001,-0.23847930863478001,-0.23866339806060999,-0.23884748748644999,-0.23910075207716,-0.23954782639705,-0.23999490071693999,-0.24044197503683001,-0.24088904935672001,-0.24102567030735,-0.24097307332854001,-0.24092047634972999,-0.24086787937092,-0.24081528239211,-0.24035049684466001,-0.23987712403535999,-0.23940375122606999,-0.23893037841678,-0.23859028706738999,-0.23851139159918,-0.23843249613095999,-0.23835360066274999,-0.23827470519453001,-0.23856653792134999,-0.23902018686359,-0.23947383580583001,-0.23992748474806999,-0.24036789499496,-0.2405782829102,-0.24078867082545,-0.24099905874069,-0.24120944665593,-0.24117020763999,-0.24077573029891,-0.24038125295783,-0.23998677561675999,-0.23959229827567999,-0.23924344076316001,-0.23890813502323999,-0.23857282928333001,-0.23823752354340999,-0.23798549635328001,-0.23829450360379001,-0.23860351085430001,-0.23891251810481001,-0.23922152535532001,-0.23958822827137,-0.24001557872420001,-0.24044292917703,-0.24087027962987001,-0.2412976300827,-0.24120782163589,-0.24102373221005999,-0.24083964278421999,-0.24065555335837999,-0.24040840122835999,-0.23991530455200999,-0.23942220787565999,-0.23892911119932,-0.23843601452297,-0.23824609589682,-0.23829211825327001,-0.23833814060972999,-0.23838416296619,-0.23843018532265001,-0.23890595839090001,-0.2394187789343,-0.23993159947770001,-0.24044442002110999,-0.24084354879568001,-0.24094874275330999,-0.24105393671093001,-0.24115913066854999,-0.24126432462617001,-0.2409882948465,-0.24049519817015,-0.2400021014938,-0.23950900481744999,-0.23901590814111001,-0.23876496926714,-0.23851513361779,-0.23826529796844001,-0.23801546231910001,-0.23800517549500999,-0.23843252594784001,-0.23885987640067999,-0.23928722685351,-0.23971457730635001,-0.24010915900651,-0.24049048710289,-0.24087181519925999,-0.24125314329563999,-0.24158502009419,-0.24126286359898,-0.24094070710376,-0.24061855060855,-0.24029639411334,-0.23990097754049,-0.23940788086414999,-0.23891478418779999,-0.23842168751144999,-0.23792859083510001,-0.23797350996694999,-0.23816417401514001,-0.23835483806332,-0.23854550211150999,-0.23878959801119001,-0.23934844091105001,-0.23990728381091,-0.24046612671077,-0.24102496961063,-0.24128594186519001,-0.24125306875343,-0.24122019564168001,-0.24118732252992001,-0.24115444941816999,-0.24065136408654,-0.24007279731962999,-0.23949423055270999,-0.23891566378580001,-0.23843398697502999,-0.23829591990564999,-0.23815785283627999,-0.2380197857669,-0.23788171869752001,-0.23814282512804999,-0.23869509340556,-0.23924736168307001,-0.23979962996057,-0.24035189823808001,-0.24067635063317,-0.24098535788368,-0.24129436513419,-0.2416033723847,-0.2416798079602,-0.24119986052855999,-0.24071991309690999,-0.24023996566526001,-0.23976001823362,-0.23929295169473999,-0.23883272813015,-0.23837250456556,-0.23791228100097001,-0.23746137521182001,-0.23782297944114,-0.23818458367046,-0.23854618789977999,-0.23890779212911001,-0.23934715878515,-0.23991915092971,-0.24049114307427999,-0.24106313521884001,-0.24163512736341,-0.24164720320038,-0.24144996452983999,-0.24125272585929999,-0.24105548718875999,-0.24081915858669001,-0.24016827097391,-0.23951738336112999,-0.23886649574835001,-0.23821560813557,-0.23785984801501001,-0.23787299725971001,-0.23788614650441001,-0.23789929574911001,-0.23791244499382,-0.23845863062752001,-0.2391358167297,-0.23981300283189,-0.24049018893407001,-0.24108904608879,-0.24127971013697999,-0.24147037418516001,-0.24166103823335,-0.24185170228153999,-0.24160537011576,-0.24095448250297999,-0.24030359489020001,-0.23965270727742,-0.23900181966463999,-0.23858171471399001,-0.23819381199525999,-0.23780590927653,-0.23741800655781001,-0.23725337264709001,-0.23781221554695001,-0.23837105844681,-0.23892990134667,-0.23948874424652999,-0.24005539916933,-0.24062739131388999,-0.24119938345844999,-0.24177137560302001,-0.24234336774758,-0.24197612812767,-0.24156192691954001,-0.24114772571140999,-0.24073352450327001,-0.24022537030180999,-0.23950873646552001,-0.23879210262923001,-0.23807546879294,-0.23735883495664001,-0.23726671570152,-0.23748367823912001,-0.23770064077670999,-0.23791760331430001,-0.23815084586915,-0.23896609904071001,-0.23978135221227001,-0.24059660538382999,-0.24141185855538999,-0.24191791066672,-0.24193105991142,-0.24194420915612,-0.24195735840082,-0.24197050764552999,-0.24134307100998001,-0.24049494472666,-0.23964681844333999,-0.23879869216002,-0.23800893242207,-0.23773279828331001,-0.23745666414455999,-0.2371805300058,-0.23690439586705,-0.23713367277666,-0.23795550057057999,-0.23877732836449,-0.2395991561584,-0.24042098395232001,-0.24100062412695999,-0.24152659391507,-0.24205256370316999,-0.24257853349128,-0.24288704876323999,-0.24218356417164999,-0.24148007958005999,-0.24077659498847001,-0.24007311039688001,-0.23933444188523001,-0.23856521107013001,-0.23779598025502,-0.23702674943992,-0.23625751862482,-0.23663370330915001,-0.23714652385255,-0.23765934439594999,-0.23817216493935001,-0.23880247890396,-0.2397820976343,-0.24076171636464999,-0.24174133509498999,-0.24272095382534001,-0.24294662289230001,-0.2426902126206,-0.2424338023489,-0.24217739207719999,-0.24192098180550001,-0.24082427218185001,-0.23970001175978001,-0.23857575133770001,-0.23745149091563,-0.23667501459835,-0.23661584299718,-0.23655667139601999,-0.23649749979486001,-0.2364383281937,-0.23723010057114999,-0.23841353259438,-0.23959696461762001,-0.24078039664084999,-0.24193125372115001,-0.24235860417398,-0.24278595462682001,-0.24321330507965,-0.24364065553249001,-0.24343205663013001,-0.2422749230963,-0.24111778956246999,-0.23996065602864,-0.23880352249480999,-0.23791108832571001,-0.23710240977649999,-0.23629373122729,-0.23548505267808001,-0.2348911153088,-0.2359036071509,-0.23691609899300001,-0.23792859083510001,-0.23894108267719999,-0.24003810537810999,-0.24122811202368999,-0.24241811866928001,-0.24360812531487,-0.24479813196045,-0.24437516458919001,-0.24363223226349001,-0.24288929993778999,-0.24214636761208999,-0.24124756753880999,-0.23969595666391,-0.23814434578900001,-0.23659273491409,-0.23504112403918001,-0.23454011098082,-0.23489514058779001,-0.23525017019475999,-0.23560519980173,-0.23596022940870001,-0.23767232964780999,-0.23951979852852001,-0.24136726740924,-0.24321473628995999,-0.24461185099383001,-0.24477621655262,-0.24494058211139999,-0.24510494767018001,-0.24526931322896001,-0.24405112963044001,-0.24200642207918999,-0.23996171452793,-0.23791700697667001,-0.23587229942542001,-0.2350310608417,-0.23420923304779001,-0.23338740525387999,-0.23256557745996001,-0.23274552233928,-0.2348494014917,-0.23695328064412,-0.23905715979653999,-0.24116103894895999,-0.24293323511254999,-0.24456374145567,-0.2461942477988,-0.24782475414192001,-0.24924206978294999,-0.24725653383286,-0.24527099788275999,-0.24328546193267001,-0.24129992598257,-0.23905653364203,-0.23645298319090999,-0.23384943273979,-0.23124588228868001,-0.22864233183756,-0.22930703957487,-0.23091782205094,-0.23252860452700999,-0.23413938700308001,-0.23604659400570999,-0.23987302421417001,-0.24369945442263,-0.24752588463108999,-0.25135231483955001,-0.25287856645682,-0.25203044017350001,-0.25118231389017998,-0.25033418760685999,-0.24948606132355,-0.24467974403281001,-0.23917678512476001,-0.23367382621672,-0.22817086730868,-0.22367464558462,-0.22299745948244001,-0.22232027338025001,-0.22164308727807,-0.22096590117588,-0.22545448977829999,-0.23388973025502,-0.24232497073174999,-0.25076021120848002,-0.25919545168519997,-0.26392636208284997,-0.26835765754763002,-0.27278895301241002,-0.27722024847719001,-0.27514028246367001,-0.25659984743297998,-0.2380594124023,-0.21951897737161,-0.20097854234092999,-0.16746878053249001,-0.12560158539937,-0.08373439026625,-0.041867195133118998,0.0,0.0,0.056035506300187998,0.11207101260037999,0.16810651890056,0.22414202520074999,0.26890159200678998,0.29346438111126999,0.31802717021575,0.34258995932023001,0.36715274842471002,0.36970072020888001,0.36354029906571,0.35737987792253001,0.35121945677936001,0.34468463996472998,0.33352093121221998,0.3223572224597,0.31119351370718001,0.30002980495465997,0.29421657157864001,0.29540657822423,0.29659658486981999,0.29778659151539999,0.29897659816098998,0.30501584349811001,0.31233339817511002,0.31965095285211997,0.32696850752911999,0.33331686447582998,0.33415841613679997,0.33499996779777003,0.33584151945874002,0.33668307111969997,0.33447900724573998,0.32932450332231999,0.32416999939889002,0.31901549547546998,0.31386099155204,0.31153691473040002,0.30964999811556998,0.30776308150074999,0.30587616488592001,0.30522313045768001,0.30883259812855002,0.31244206579942002,0.31605153347027998,0.31966100114114998,0.32257314140644,0.32498602780937003,0.3273989142123,0.32981180061523002,0.33222468701815999,0.33013962231791,0.32777275827143998,0.32540589422497002,0.3230390301785,0.32059541747928,0.31797214316110001,0.31534886884293001,0.31272559452476001,0.31010232020659001,0.31008608491466,0.31142730787432998,0.31276853083398998,0.31410975379366002,0.31547111805672001,0.31808124313018998,0.32069136820366001,0.32330149327712998,0.32591161835060001,0.32735821416916999,0.32685854287047,0.32635887157177002,0.32585920027307003,0.32535952897437997,0.32345375318205999,0.32103429215677998,0.31861483113150002,0.31619537010621002,0.31397866387453,0.31379457444870001,0.31361048502285999,0.31342639559702001,0.31324230617118998,0.31408546794374997,0.31618934709617003,0.31829322624859002,0.32039710540101002,0.32250098455342002,0.32348500127377999,0.32420163511007,0.32491826894636,0.32563490278265,0.32595103626782002,0.32424820907883001,0.32254538188984999,0.32084255470085998,0.31913972751186998,0.31775373450476002,0.31665577257208999,0.31555781063943,0.31445984870676003,0.31336188677408999,0.31434010411100999,0.31559585698011,0.31685160984921001,0.31810736271831003,0.31938207912397998,0.32071672746129998,0.32205137579861998,0.32338602413592998,0.32472067247324998,0.32477617659799002,0.32397407267112999,0.32317196874428,0.32236986481742003,0.32156776089055999,0.32016168621382002,0.31872841854123002,0.31729515086865001,0.31586188319606001,0.31499227384968997,0.31534730345666001,0.31570233306362999,0.31605736267059997,0.31641239227757001,0.31748472660067001,0.31890484502854999,0.32032496345643002,0.32174508188431,0.32312178693285998,0.32317438391167003,0.32322698089048002,0.32327957786929001,0.32333217484810001,0.32285397170402003,0.32154562185611002,0.32023727200820001,0.31892892216029001,0.31762057231238,0.31699115285422003,0.31659010089078998,0.31618904892735999,0.31578799696393001,0.31554880594124002,0.31666649174096001,0.31778417754068,0.31890186334040999,0.32001954914012998,0.32092941127641,0.32160002275624,0.32227063423607999,0.32294124571590999,0.32361185719573998,0.32301611590514001,0.32214826575476002,0.32128041560439002,0.32041256545402003,0.31954590797889998,0.31868463245088002,0.31782335692286001,0.31696208139484,0.31610080586681999,0.31602013629415998,0.31660527768342001,0.31719041907269002,0.31777556046195998,0.31836070185122001,0.31928826030662,0.32025472979226,0.32122119927790999,0.32218766876354998,0.32283236937344001,0.32254308598997999,0.32225380260651998,0.32196451922306002,0.32167523583961,0.32095769258842999,0.31997149923572998,0.31898530588304003,0.31799911253034002,0.31701291917765001,0.31699247970543998,0.31699905432779002,0.31700562895014001,0.31701220357248999,0.31732568335521,0.31825927972910001,0.31919287610299002,0.32012647247686998,0.32106006885075999,0.32152231996328001,0.32177215561263001,0.32202199126198,0.32227182691132999,0.32247063096814998,0.32164880317423,0.32082697538032001,0.32000514758641002,0.31918331979248998,0.31850826559732998,0.31804804203274001,0.31758781846814998,0.31712759490356002,0.31666737133896,0.31706125234241,0.31771871457753997,0.31837617681267999,0.31903363904781001,0.31968546589234997,0.32029690577101999,0.32090834564969001,0.32151978552836002,0.32213122540703998,0.32222748920867,0.32176726564407998,0.32130704207949001,0.32084681851489999,0.32038659495031002,0.31972227483245003,0.31901879024086,0.31831530564927002,0.31761182105767999,0.3170964064456,0.31734624209494999,0.31759607774429999,0.31784591339364998,0.31809574904299998,0.31861587472234998,0.31935223242569,0.32008859012904001,0.32082494783238003,0.32156130553572998,0.32158870724975003,0.32154925951564001,0.32150981178152999,0.32147036404742002,0.32124843699908001,0.32053837778513999,0.31982831857118998,0.31911825935725002,0.31840820014331001,0.31804628283674002,0.3178884919003,0.31773070096387002,0.31757291002743998,0.31741511909101,0.31804383785245999,0.31868157622054,0.31931931458861001,0.31995705295669002,0.32048530373621997,0.32080746023144002,0.32112961672665002,0.32145177322186003,0.32177392971708002,0.32150261100466998,0.32098321583891998,0.32046382067316997,0.31994442550740998,0.31942920470505998,0.31897555576282,0.31852190682058001,0.31806825787833998,0.3176146089361,0.31751035421023999,0.31788510768425998,0.31825986115829002,0.31863461463231002,0.31900936810634001,0.31950720566683,0.32003975007729002,0.32057229448773999,0.32110483889820002,0.32153371001198,0.32131674747438999,0.32109978493680003,0.32088282239920002,0.32066585986161,0.32027585505273998,0.31971043753053002,0.31914502000832001,0.31857960248611,0.31801418496389999,0.31797709276342001,0.31802968974223,0.31808228672104,0.31813488369984999,0.31829538797249002,0.31885423087234999,0.31941307377221001,0.31997191667206998,0.32053075957193,0.32082661757774,0.32092523691301,0.32102385624828,0.32112247558355,0.32122109491882,0.32075736787066,0.32025112194960997,0.31974487602856,0.31923863010751002,0.31881190580919,0.31858179402689002,0.31835168224459998,0.3181215704623,0.31789145868000002,0.31808198855223002,0.31850276438271002,0.31892354021319003,0.31934431604368002,0.31976470425469999,0.32010000999462002,0.32043531573453998,0.32077062147445001,0.32110592721436998,0.32120746860402,0.32089846135351002,0.32058945410299,0.32028044685248003,0.31997143960197,0.31959605997343998,0.31919500801001,0.31879395604658001,0.31839290408315002,0.31803829191251998,0.31822238133835001,0.31840647076418999,0.31859056019003001,0.31877464961586,0.31906807754583999,0.31950200262102002,0.31993592769620999,0.32036985277140001,0.32080377784657998,0.32084523822019001,0.32078606661901998,0.32072689501786,0.32066772341670002,0.32055076669936,0.32011684162418003,0.31968291654899,0.31924899147379998,0.31881506639862001,0.31857319185659999,0.31851402025544001,0.31845484865427998,0.31839567705312,0.31833650545196002,0.31867234789574,0.31906682523682001,0.31946130257790001,0.31985577991897002,0.32019755592215998,0.32036192148094,0.32052628703972003,0.32069065259850998,0.32085501815729001,0.32072978725536,0.32040105613779002,0.32007232502022998,0.31974359390265999,0.31941486278510001,0.31916695032460002,0.31892368929760001,0.3186804282706,0.31843716724359999,0.31834173831464002,0.31858499934163997,0.31882826036863998,0.31907152139563999,0.31931478242264,0.31959286956713001,0.31988872757293002,0.32018458557874002,0.32048044358455002,0.32076717762465001,0.32061596131057002,0.32046474499649003,0.32031352868240998,0.32016231236832998,0.31994636360470002,0.31962420710949002,0.31930205061428002,0.31897989411906003,0.31865773762385002,0.31861660523593999,0.31867577683710002,0.31873494843826,0.31879412003942997,0.31887771166646001,0.31919329353933001,0.31950887541218997,0.31982445728504999,0.32014003915791001,0.32032740844071,0.32036028155245999,0.32039315466422003,0.32042602777598,0.32045890088772999,0.32023025013263001,0.31994096674917,0.31965168336570998,0.31936239998225002,0.31910442432427999,0.31899923036666,0.31889403640904002,0.31878884245141997,0.31868364849378999,0.31875908520377,0.31899577160840997,0.31923245801305999,0.31946914441771002,0.31970583082234999,0.31987839602353002,0.32004276158230999,0.32020712714109001,0.32037149269986998,0.32045213245565002,0.32027461765217002,0.32009710284867998,0.31991958804519999,0.31974207324171,0.31955266150254003,0.31935542283200002,0.31915818416146002,0.31896094549092002,0.31876370682039001,0.31886356355623002,0.31897533213620999,0.31908710071618002,0.31919886929614999,0.31934216922822001,0.31955255714345998,0.31976294505870001,0.31997333297393998,0.32018372088918001,0.32022026147735,0.32017423912088999,0.32012821676442998,0.32008219440798003,0.32003044721028001,0.31982663391739002,0.31962282062449998,0.31941900733160999,0.31921519403872001,0.31908920280632003,0.31908262818396999,0.31907605356161001,0.31906947893926002,0.31906290431690998,0.31918996895704999,0.31936090913817999,0.31953184931931999,0.31970278950045,0.31986131095047998,0.31992048255164002,0.3199796541528,0.32003882575395998,0.32009799735512001,0.32006458753950001,0.31992652047011999,0.31978845340075002,0.31965038633137,0.31951231926198997,0.31941778483948002,0.31933231474891,0.31924684465834002,0.31916137456777,0.31910891176493,0.31920095647785002,0.31929300119076998,0.31938504590368999,0.31947709061660001,0.31956913532952003,0.31966118004243999,0.31975322475536,0.31984526946828001,0.31993731418120003,0.31989882058729002,0.31984622360847997,0.31979362662966998,0.31974102965085999,0.31968157478933001,0.31960267932110997,0.31952378385288999,0.31944488838467999,0.31936599291646001,0.31934814751293999,0.31936787137999001,0.31938759524705002,0.31940731911409997,0.31942704298114999,0.31948532007586999,0.31954449167702997,0.3196036632782,0.31966283487935998,0.3197021484375,0.3197021484375,0.3197021484375,0.3197021484375,0.3197021484375,0.31968390050607998,0.31965760201666998,0.31963130352726998,0.31960500503785999,0.31957973523085997,0.31957316060850999,0.31956658598616,0.31956001136381001,0.31955343674145997,0.31954686211910999,0.31954028749676,0.31953371287440002,0.31952713825204998,0.31952056362969999,0.31951398900735001,0.31950741438500002,0.31950083976264998,0.31949426514029999,0.31949269975402,0.31952557286577998,0.31955844597754002,0.31959131908929,0.31962419220104998,0.31966025571911999,0.31969970345322002,0.31973915118732998,0.31977859892144,0.31981804665555003,0.3197853971704,0.31973937481393999,0.31969335245747998,0.31964733010101998,0.31959201978600998,0.31949997507309003,0.31940793036017001,0.31931588564725,0.31922384093432998,0.31920544391849998,0.31924489165261,0.31928433938672002,0.31932378712081999,0.31936323485493001,0.31950532720329999,0.31965654351737999,0.31980775983145998,0.31995897614553998,0.32006472171547001,0.32005157247076998,0.32003842322606002,0.32002527398135999,0.32001212473666002,0.31988209331681999,0.31968485464627999,0.31948761597573999,0.31929037730519999,0.31909313863465999,0.31903955769877002,0.31898696071996002,0.31893436374114997,0.31888176676233998,0.31893315615744999,0.31917641718445,0.31941967821145001,0.31966293923844002,0.31990620026543998,0.32007946616333,0.32022410785505001,0.32036874954678002,0.32051339123851003,0.32063030323052999,0.32036731833648002,0.32010433344242001,0.31984134854836999,0.31957836365432002,0.31931257597341001,0.31904301645701,0.31877345694060999,0.31850389742419999,0.31823433790779998,0.31837228570964998,0.31862212135899998,0.31887195700835003,0.31912179265770002,0.3193941698694,0.31980179645517998,0.32020942304096001,0.32061704962673998,0.32102467621252001,0.32113577391266002,0.32095168448682998,0.32076759506099001,0.32058350563514998,0.32039941620932,0.31989325973890997,0.31933441683905001,0.31877557393918998,0.31821673103933001,0.31779242190839002,0.31785159350955999,0.31791076511071997,0.31796993671188001,0.31802910831303999,0.31845938082025999,0.31916286541185002,0.31986635000343,0.32056983459501998,0.32127331918661001,0.32146085246224998,0.32161206877632997,0.32176328509041002,0.32191450140449002,0.32177723939092001,0.3209422623523,0.32010728531367999,0.31927230827507003,0.31843733123645002,0.31785907754678999,0.31741857784924998,0.31697807815172002,0.31653757845418001,0.31610930367801998,0.3170166015625,0.31792389944698002,0.31883119733145998,0.31973849521594,0.32062164142647998,0.32146319308743998,0.32230474474840998,0.32314629640937997,0.32398784807035003,0.32356516395945001,0.32266444069731998,0.32176371743519,0.32086299417307002,0.31992255482490001,0.31854845875346999,0.31717436268205002,0.31580026661062999,0.31442617053920002,0.31399108260564002,0.31474058955369,0.31549009650173998,0.31623960344979002,0.31698911039784,0.31882272933714001,0.32092660848956001,0.32303048764198,0.32513436679439001,0.32684585578742997,0.32647767693576002,0.32610949808409001,0.32574131923241001,0.32537314038074,0.32356033362466002,0.32039794027369001,0.31723554692271,0.31407315357172999,0.31091076022074998,0.3100674940891,0.30955467354569999,0.30904185300230003,0.30852903245890001,0.30932912374625998,0.31443760531322001,0.31954608688018998,0.32465456844716001,0.32976305001411998,0.33354466544981998,0.33641120079498998,0.33927773614015999,0.34214427148533,0.34501080683050001,0.33387862943007002,0.32201143608596,0.31014424274185998,0.29827704939775002,0.28152954817168002,0.25383723882796999,0.22614492948427001,0.19845262014057,0.17076031079685999,0.14263407637796999,0.11429087942148,0.085947682465003006,0.057604485508521,0.029651591529716002,0.016955995769343001,0.0042604000089687,-0.0084351957514039993,-0.021130791511778001,-0.027698898874495999,-0.024405013076492,-0.021111127278487001,-0.017817241480481999,-0.014523355682477,-0.0091819446379231007,-0.0031267174523690999,0.0029285097331841,0.0089837369187373006,0.014367249399846,0.013690063297661001,0.013012877195477,0.012335691093292,0.011658504991107,0.0093882327319706992,0.0052330714059449996,0.0010779100799187999,-0.0030772512461067999,-0.0072324125721330004,-0.0083873992905013003,-0.0088673467221468006,-0.0093472941537920996,-0.0098272415854374993,-0.0096884440024654992,-0.0066246699867567004,-0.0035608959710474999,-0.00049712195533874995,0.0025666520603704001,0.0046004019077078998,0.0057312369521326997,0.0068620719965573999,0.0079929070409822008,0.0091237420854069998,0.0072606193419486997,0.0050318223648555,0.0028030253877627002,0.00057422841066947995,-0.0014774562908372001,-0.0029961940539890001,-0.0045149318171408999,-0.0060336695802927004,-0.0075524073434447003,-0.0072212461500442996,-0.0056959337645410002,-0.0041706213790379002,-0.0026453089935349,-0.0011199966080316,0.00058949465395233996,0.0023054710876435,0.0040214475213344999,0.0057374239550257002,0.0066049013943805003,0.0057041781322515004,0.0048034548701223999,0.0039027316079935002,0.0030020083458644001,0.0015044554769557,-0.00027069255789729,-0.0020458405927499998,-0.0038209886276028,-0.0055094589881915998,-0.0051610040035722999,-0.0048125490189529999,-0.0044640940343337997,-0.0041156390497144998,-0.0032240397532975001,-0.0015146379419579,0.00019476386938200999,0.0019041656807216999,0.0036135674920616001,0.0041279086964155004,0.0042594011434416001,0.0043908935904678004,0.0045223860374939001,0.0044607545436157001,0.0029222929134099999,0.0013838312832041,-0.00015463034700163999,-0.0016930919772074999,-0.0027548263989604,-0.0032873708094161998,-0.0038199152198720998,-0.0043524596303278996,-0.0048850040407838,-0.0038964998797784002,-0.0026012992765708999,-0.0013060986733635001,-1.0898070156132e-05,0.0011991455197392,0.0020472718030578002,0.0028953980863763999,0.0037435243696948999,0.0045916506530135999,0.0044259731514488003,0.0034266305540501,0.0024272879566515,0.0014279453592528999,0.00042860276185423003,-0.00063037359836797999,-0.0016954624192797999,-0.0027605512401914002,-0.0038256400611032001,-0.0044337255406158996,-0.0037762633054851998,-0.0031188010703545,-0.0024613388352237998,-0.0018038766000931,-0.00081432884823831998,0.0003756777973483,0.0015656844429348001,0.0027556910885212001,0.0039456977341078003,0.0036703388342697002,0.0033679062061095001,0.0030654735779494001,0.0027630409497893002,0.0021475310668050999,0.00092465130946210998,-0.00029822844788104003,-0.0015211082052240001,-0.0027439879625671998,-0.0031403437671745,-0.0031797915012824001,-0.0032192392353902,-0.0032586869694979999,-0.0032299285873762999,-0.0020662204311951001,-0.00090251227501371998,0.00026119588116750998,0.0014249040373489001,0.0022530381016807998,0.0026080677086514001,0.0029630973156219002,0.0033181269225925,0.0036731565295630999,0.0029605926975834001,0.0019349516107795,0.00090931052397566004,-0.00011633056282814,-0.0010892255864145999,-0.0017138147097887,-0.0023384038331629,-0.002962992956537,-0.0035875820799111998,-0.0035037221009404,-0.0026818943070271001,-0.0018600665131137,-0.0010382387192003999,-0.00021641092528700001,0.00061099262545031001,0.0014393950417149999,0.0022677974579796002,0.0030961998742442,0.0036356319843062999,0.0030636398397426998,0.0024916476951789002,0.0019196555506153,0.0013476634060515,0.00055665135907734004,-0.0004032435042134,-0.0013631383675043001,-0.0023230332307949998,-0.0032829280940859002,-0.0030838855022212999,-0.0027880274964124001,-0.0024921694906036001,-0.0021963114847948001,-0.0016971023477573999,-0.00067803588330491002,0.00034103058114771999,0.0013600970456002,0.0023791635100528,0.0027381736706919,0.0027250244259893002,0.0027118751812866002,0.0026987259365839999,0.0026855766918814001,0.0016884703605887,0.00068912776319001996,-0.00031021483420855999,-0.0013095574316073001,-0.0020467500076330998,-0.0023097349016853999,-0.0025727197957376999,-0.0028357046897899002,-0.0030986895838421998,-0.0025257582075141,-0.0016184603230337,-0.00071116243855338999,0.00019613544592689001,0.0010743320541493999,0.0015805779752000001,0.0020868238962506,0.0025930698173012002,0.0030993157383519001,0.0030645343461850002,0.0023150273981360999,0.0015655204500869999,0.00081601350203809001,6.6506553989060006e-05,-0.00064668343250026997,-0.0013501680240902,-0.0020536526156798999,-0.0027571372072696999,-0.0032765025561415999,-0.0027308089009831999,-0.0021851152458247001,-0.0016394215906662,-0.0010937279355077,-0.00039842807786550001,0.00044312358310171998,0.0012846752440691001,0.0021262269050363,0.0029677785660035998,0.0028153099429043,0.0025063026923928,0.0021972954418814001,0.00188828819137,0.0014463274666433,0.00053902958216298005,-0.00036826830231742,-0.0012755661867977,-0.0021828640712780998,-0.0025367606367550002,-0.0024907382802958999,-0.0024447159238366999,-0.0023986935673776001,-0.0023526712109184001,-0.0014919323867627001,-0.00057805987993097998,0.00033581262690062001,0.0012496851337322999,0.0019526330214567,0.0021564463143472,0.0023602596072377002,0.0025640729001282,0.0027678861930187999,0.0022823331876680002,0.0014342069043493,0.00058608062103079005,-0.00026204566228773,-0.0011045365550194999,-0.0015384616302058,-0.001972386705392,-0.0024063117805782999,-0.0028402368557645,-0.0028462896826910999,-0.0021296558463987001,-0.0014130220101063,-0.00069638817381386005,2.0245662478638001e-05,0.0006744727659761,0.0013056365117015999,0.0019368002574270001,0.0025679640031524001,0.0030956333534974999,0.0025565143206904002,0.0020173952878831999,0.001478276255076,0.00093915722226884995,0.00029724449079447001,-0.00047198632430837999,-0.0012412171394113,-0.0020104479545142002,-0.0027796787696170999,-0.0026703551739207,-0.0023481986787066002,-0.0020260421834926001,-0.0017038856882785999,-0.0012958565745985,-0.00044773029127997998,0.00040039599203865999,0.0012485222753572001,0.0020966485586758001,0.0024612941099016999,0.0023823986416859999,0.0023035031734702999,0.0022246077052545999,0.0021457122370390001,0.0013668952945622001,0.00049247052183833996,-0.00038195425088540999,-0.0012563790236092001,-0.0019601766924538999,-0.0021179676288852001,-0.0022757585653166001,-0.002433549501748,-0.0025913404381794,-0.0021609933887625,-0.0013325909724979,-0.00050418855623322,0.00032421386003139002,0.0011526162762960999,0.0015542198520319,0.0019355479484076999,0.0023168760447835001,0.0026982041411593,0.0027359523130266999,0.0020193184767343,0.0013026846404418,0.00058605080414941,-0.00013058303214309001,-0.00075454600100754998,-0.0013331127679226001,-0.0019116795348376001,-0.0024902463017524999,-0.0030354777952491,-0.0024832095177394001,-0.0019309412402295999,-0.0013786729627199,-0.00082640468521003995,-0.00020530413696112,0.00052447894403389,0.0012542620250290001,0.0019840451060240002,0.0027138281870191,0.0026392114412860002,0.0022907564566668,0.0019423014720475001,0.0015938464874283001,0.0011960147471910001,0.00037418695327771001,-0.00044764084063570001,-0.0012694686345490001,-0.0020912964284624,-0.0024782151901029002,-0.0023598719877793999,-0.0022415287854559,-0.0021231855831322999,-0.0020048423808088,-0.0012820513585049,-0.00042735045283492001,0.00042735045283492001,0.0012820513585048,0.0020048423808088,0.0021231855831322999,0.0022415287854559,0.0023598719877793999,0.0024782151901029002,0.0020912964284624,0.0012694686345491001,0.00044764084063570001,-0.00037418695327760999,-0.0011960147471910001,-0.0015938464874281999,-0.0019423014720475001,-0.0022907564566668,-0.0026392114412860002,-0.0027138281870191,-0.0019840451060240999,-0.0012542620250290001,-0.00052447894403398997,0.00020530413696112,0.00082640468521003995,0.0013786729627198,0.0019309412402295999,0.0024832095177392999,0.0030354777952491,0.0024902463017526001,0.0019116795348376001,0.0013331127679226001,0.00075454600100763,0.00013058303214309001,-0.00058605080414931004,-0.0013026846404418,-0.0020193184767341998,-0.0027359523130266999,-0.0026982041411593,-0.0023168760447835001,-0.0019355479484076999,-0.001554219852032,-0.0011526162762960999,-0.00032421386003150002,0.00050418855623322,0.0013325909724978,0.0021609933887625,0.0025913404381794,0.002433549501748,0.0022757585653166001,0.0021179676288852999,0.0019601766924538999,0.0012563790236093,0.00038195425088540999,-0.00049247052183833996,-0.0013668952945621001,-0.0021457122370390001,-0.0022246077052545999,-0.0023035031734702999,-0.0023823986416859999,-0.0024612941099016999,-0.0020966485586758001,-0.0012485222753573001,-0.00040039599203865999,0.00044773029127986999,0.0012958565745985,0.0017038856882785999,0.0020260421834926001,0.0023481986787066002,0.0026703551739205998,0.0027796787696170999,0.0020104479545142999,0.0012412171394113,0.00047198632430848,-0.00029724449079447001,-0.00093915722226884995,-0.001478276255076,-0.0020173952878831999,-0.0025565143206903,-0.0030956333534974999,-0.0025679640031524998,-0.0019368002574270001,-0.0013056365117015999,-0.00067447276597618002,-2.0245662478638001e-05,0.00069638817381375998,0.0014130220101063,0.0021296558463987001,0.0028462896826910999,0.0028402368557645,0.0024063117805782999,0.001972386705392,0.0015384616302058,0.0011045365550194999,0.00026204566228785003,-0.00058608062103079005,-0.0014342069043493,-0.0022823331876677998,-0.0027678861930187999,-0.0025640729001283002,-0.0023602596072377002,-0.0021564463143472,-0.0019526330214567,-0.0012496851337322999,-0.00033581262690073998,0.00057805987993097998,0.0014919323867626001,0.0023526712109184001,0.0023986935673776001,0.0024447159238366999,0.0024907382802958999,0.0025367606367550002,0.0021828640712780998,0.0012755661867978,0.00036826830231742,-0.00053902958216286003,-0.0014463274666433,-0.00188828819137,-0.0021972954418814001,-0.0025063026923928,-0.0028153099429041998,-0.0029677785660035998,-0.0021262269050364001,-0.0012846752440691001,-0.00044312358310183002,0.00039842807786550001,0.0010937279355077,0.0016394215906662,0.0021851152458247001,0.0027308089009831001,0.0032765025561415999,0.0027571372072698001,0.0020536526156798999,0.0013501680240902,0.00064668343250037005,-6.6506553989060006e-05,-0.00081601350203799005,-0.0015655204500869999,-0.0023150273981360002,-0.0030645343461850002,-0.0030993157383519001,-0.0025930698173012999,-0.0020868238962506,-0.0015805779752000001,-0.0010743320541493999,-0.00019613544592701,0.00071116243855338999,0.0016184603230337,0.0025257582075139998,0.0030986895838421998,0.0028357046897899999,0.0025727197957376999,0.0023097349016853999,0.0020467500076330998,0.0013095574316073001,0.00031021483420868998,-0.00068912776319001996,-0.0016884703605886001,-0.0026855766918814001,-0.0026987259365839999,-0.0027118751812866002,-0.0027250244259893002,-0.0027381736706919,-0.0023791635100528,-0.0013600970456003,-0.00034103058114771999,0.00067803588330478002,0.0016971023477573999,0.0021963114847948001,0.0024921694906036001,0.0027880274964124001,0.0030838855022212999,0.0032829280940859002,0.0023230332307951,0.0013631383675044,0.0004032435042134,-0.00055665135907734004,-0.0013476634060515,-0.0019196555506152001,-0.0024916476951788,-0.0030636398397426998,-0.0036356319843062999,-0.0030961998742444,-0.0022677974579797,-0.0014393950417150999,-0.00061099262545031001,0.00021641092528700001,0.0010382387192002999,0.0018600665131136001,0.0026818943070271001,0.0035037221009404,0.0035875820799111998,0.0029629929565371002,0.0023384038331629,0.0017138147097887,0.0010892255864145999,0.00011633056282827,-0.00090931052397553004,-0.0019349516107793,-0.0029605926975834001,-0.0036731565295630999,-0.0033181269225925,-0.0029630973156219999,-0.0026080677086514001,-0.0022530381016807998,-0.0014249040373489001,-0.00026119588116767001,0.00090251227501357003,0.0020662204311951001,0.0032299285873762999,0.0032586869694979999,0.0032192392353902,0.0031797915012824001,0.0031403437671745,0.0027439879625671998,0.0015211082052242,0.00029822844788120998,-0.00092465130946210998,-0.0021475310668050999,-0.0027630409497893002,-0.0030654735779494001,-0.0033679062061095001,-0.0036703388342697002,-0.0039456977341078003,-0.0027556910885214001,-0.0015656844429349,-0.00037567779734813998,0.00081432884823831998,0.0018038766000931,0.0024613388352237998,0.0031188010703543999,0.0037762633054851998,0.0044337255406158996,0.0038256400611032001,0.0027605512401914999,0.0016954624192799001,0.00063037359836797999,-0.00042860276185423003,-0.0014279453592527999,-0.0024272879566513998,-0.0034266305540502002,-0.0044259731514488003,-0.0045916506530135999,-0.0037435243696950999,-0.0028953980863765001,-0.0020472718030578002,-0.0011991455197392,1.0898070155961e-05,0.0013060986733632999,0.0026012992765707,0.0038964998797784002,0.0048850040407838,0.0043524596303280002,0.0038199152198720998,0.0032873708094161998,0.0027548263989604,0.0016930919772074999,0.00015463034700184,-0.0013838312832039001,-0.0029222929134099999,-0.0044607545436157001,-0.0045223860374939001,-0.0043908935904678004,-0.0042594011434416001,-0.0041279086964155004,-0.0036135674920616001,-0.0019041656807219001,-0.00019476386938224,0.0015146379419579,0.0032240397532975001,0.0041156390497144998,0.0044640940343337,0.0048125490189529999,0.0051610040035722999,0.0055094589881915998,0.0038209886276029999,0.0020458405927503,0.00027069255789705999,-0.0015044554769557,-0.0030020083458644001,-0.0039027316079932998,-0.0048034548701223001,-0.0057041781322515004,-0.0066049013943805003,-0.0057374239550257002,-0.0040214475213347003,-0.0023054710876438001,-0.00058949465395233996,0.0011199966080316,0.0026453089935347001,0.0041706213790376999,0.0056959337645411997,0.0072212461500442996,0.0075524073434447003,0.0060336695802928999,0.0045149318171411002,0.0029961940539890001,0.0014774562908372001,-0.00057422841066947995,-0.0028030253877624001,-0.0050318223648551999,-0.0072606193419486997,-0.0091237420854069998,-0.0079929070409822996,-0.0068620719965576003,-0.0057312369521326,-0.0046004019077078998,-0.0025666520603704001,0.00049712195533834999,0.0035608959710471001,0.0066246699867567004,0.0096884440024654992,0.0098272415854375999,0.0093472941537922002,0.0088673467221468006,0.0083873992905013003,0.0072324125721330004,0.0030772512461074001,-0.0010779100799182999,-0.0052330714059449996,-0.0093882327319706992,-0.011658504991107,-0.012335691093292,-0.013012877195477,-0.013690063297661001,-0.014367249399846,-0.0089837369187381003,-0.0029285097331849001,0.0031267174523683001,0.0091819446379231007,0.014523355682477,0.017817241480481999,0.021111127278485999,0.024405013076492,0.027698898874495999,0.021130791511778001,0.0084351957514056993,-0.004260400008967,-0.016955995769343001,-0.029651591529716002,-0.057604485508517003,-0.085947682464998995,-0.11429087942148,-0.14263407637796999,-0.17076031079685999,-0.19845262014056,-0.22614492948425999,-0.25383723882796999,-0.28152954817168002,-0.29827704939775002,-0.31014424274184998,-0.32201143608596,-0.33387862943007002,-0.34501080683050001,-0.34214427148533,-0.33927773614015999,-0.33641120079498998,-0.33354466544981998,-0.32976305001411998,-0.32465456844716001,-0.31954608688018998,-0.31443760531322001,-0.30932912374625998,-0.30852903245890001,-0.30904185300230003,-0.30955467354569999,-0.3100674940891,-0.31091076022074998,-0.31407315357172999,-0.31723554692271,-0.32039794027369001,-0.32356033362466002,-0.32537314038074,-0.32574131923241001,-0.32610949808409001,-0.32647767693576002,-0.32684585578742997,-0.32513436679439001,-0.32303048764198,-0.32092660848956001,-0.31882272933714001,-0.31698911039784,-0.31623960344979002,-0.31549009650173998,-0.31474058955369,-0.31399108260564002,-0.31442617053920002,-0.31580026661062999,-0.31717436268205002,-0.31854845875346999,-0.31992255482490001,-0.32086299417307002,-0.32176371743519,-0.32266444069731998,-0.32356516395945001,-0.32398784807035003,-0.32314629640937997,-0.32230474474840998,-0.32146319308743998,-0.32062164142647998,-0.31973849521594,-0.31883119733145998,-0.31792389944698002,-0.3170166015625,-0.31610930367801998,-0.31653757845418001,-0.31697807815172002,-0.31741857784924998,-0.31785907754678999,-0.31843733123645002,-0.31927230827507003,-0.32010728531367999,-0.3209422623523,-0.32177723939092001,-0.32191450140449002,-0.32176328509041002,-0.32161206877632997,-0.32146085246224998,-0.32127331918661001,-0.32056983459501998,-0.31986635000343,-0.31916286541185002,-0.31845938082025999,-0.31802910831303999,-0.31796993671188001,-0.31791076511071997,-0.31785159350955999,-0.31779242190839002,-0.31821673103933001,-0.31877557393918998,-0.31933441683905001,-0.31989325973890997,-0.32039941620932,-0.32058350563514998,-0.32076759506099001,-0.32095168448682998,-0.32113577391266002,-0.32102467621252001,-0.32061704962673998,-0.32020942304096001,-0.31980179645517998,-0.3193941698694,-0.31912179265770002,-0.31887195700835003,-0.31862212135899998,-0.31837228570964998,-0.31823433790779998,-0.31850389742419999,-0.31877345694060999,-0.31904301645701,-0.31931257597341001,-0.31957836365432002,-0.31984134854836999,-0.32010433344242001,-0.32036731833648002,-0.32063030323052999,-0.32051339123851003,-0.32036874954678002,-0.32022410785505001,-0.32007946616333,-0.31990620026543998,-0.31966293923844002,-0.31941967821145001,-0.31917641718445,-0.31893315615744999,-0.31888176676233998,-0.31893436374114997,-0.31898696071996002,-0.31903955769877002,-0.31909313863465999,-0.31929037730519999,-0.31948761597573999,-0.31968485464627999,-0.31988209331681999,-0.32001212473666002,-0.32002527398135999,-0.32003842322606002,-0.32005157247076998,-0.32006472171547001,-0.31995897614553998,-0.31980775983145998,-0.31965654351737999,-0.31950532720329999,-0.31936323485493001,-0.31932378712081999,-0.31928433938672002,-0.31924489165261,-0.31920544391849998,-0.31922384093432998,-0.31931588564725,-0.31940793036017001,-0.31949997507309003,-0.31959201978600998,-0.31964733010101998,-0.31969335245747998,-0.31973937481393999,-0.3197853971704,-0.31981804665555003,-0.31977859892144,-0.31973915118732998,-0.31969970345322002,-0.31966025571911999,-0.31962419220104998,-0.31959131908929,-0.31955844597754002,-0.31952557286577998,-0.31949269975402,-0.31949426514029999,-0.31950083976264998,-0.31950741438500002,-0.31951398900735001,-0.31952056362969999,-0.31952713825204998,-0.31953371287440002,-0.31954028749676,-0.31954686211910999,-0.31955343674145997,-0.31956001136381001,-0.31956658598616,-0.31957316060850999,-0.31957973523085997,-0.31960500503785999,-0.31963130352726998,-0.31965760201666998,-0.31968390050607998,-0.3197021484375,-0.3197021484375,-0.3197021484375,-0.3197021484375,-0.3197021484375,-0.31966283487935998,-0.3196036632782,-0.31954449167704002,-0.31948532007586999,-0.31942704298114999,-0.31940731911409997,-0.31938759524705002,-0.31936787137999001,-0.31934814751293999,-0.31936599291646001,-0.31944488838467999,-0.31952378385288999,-0.31960267932110997,-0.31968157478933001,-0.31974102965085999,-0.31979362662966998,-0.31984622360847997,-0.31989882058729002,-0.31993731418120003,-0.31984526946828001,-0.31975322475536,-0.31966118004243999,-0.31956913532952003,-0.31947709061660001,-0.31938504590368999,-0.31929300119076998,-0.31920095647785002,-0.31910891176493,-0.31916137456777,-0.31924684465834002,-0.31933231474891,-0.31941778483948002,-0.31951231926198997,-0.31965038633137,-0.31978845340075002,-0.31992652047011999,-0.32006458753950001,-0.32009799735512001,-0.32003882575395998,-0.3199796541528,-0.31992048255164002,-0.31986131095047998,-0.31970278950045,-0.31953184931931999,-0.31936090913817999,-0.31918996895704999,-0.31906290431690998,-0.31906947893926002,-0.31907605356161001,-0.31908262818396999,-0.31908920280632003,-0.31921519403872001,-0.31941900733160999,-0.31962282062449998,-0.31982663391739002,-0.32003044721028001,-0.32008219440798003,-0.32012821676442998,-0.32017423912088999,-0.32022026147735,-0.32018372088918001,-0.31997333297393998,-0.31976294505870001,-0.31955255714345998,-0.31934216922822001,-0.31919886929614999,-0.31908710071618002,-0.31897533213620999,-0.31886356355623002,-0.31876370682039001,-0.31896094549092002,-0.31915818416146002,-0.31935542283200002,-0.31955266150254003,-0.31974207324171,-0.31991958804519999,-0.32009710284867998,-0.32027461765217002,-0.32045213245565002,-0.32037149269986998,-0.32020712714109001,-0.32004276158230999,-0.31987839602353002,-0.31970583082234999,-0.31946914441771002,-0.31923245801305999,-0.31899577160840997,-0.31875908520377,-0.31868364849378999,-0.31878884245141997,-0.31889403640904002,-0.31899923036666,-0.31910442432427999,-0.31936239998225002,-0.31965168336570998,-0.31994096674917,-0.32023025013263001,-0.32045890088772999,-0.32042602777598,-0.32039315466422003,-0.32036028155245999,-0.32032740844071,-0.32014003915791001,-0.31982445728504999,-0.31950887541218997,-0.31919329353933001,-0.31887771166646001,-0.31879412003942997,-0.31873494843826,-0.31867577683710002,-0.31861660523593999,-0.31865773762385002,-0.31897989411906003,-0.31930205061428002,-0.31962420710949002,-0.31994636360470002,-0.32016231236832998,-0.32031352868240998,-0.32046474499649003,-0.32061596131057002,-0.32076717762465001,-0.32048044358455002,-0.32018458557874002,-0.31988872757293002,-0.31959286956713001,-0.31931478242264,-0.31907152139563999,-0.31882826036863998,-0.31858499934163997,-0.31834173831464002,-0.31843716724359999,-0.3186804282706,-0.31892368929760001,-0.31916695032460002,-0.31941486278510001,-0.31974359390265999,-0.32007232502022998,-0.32040105613779002,-0.32072978725536,-0.32085501815729001,-0.32069065259850998,-0.32052628703972003,-0.32036192148094,-0.32019755592215998,-0.31985577991897002,-0.31946130257790001,-0.31906682523682001,-0.31867234789574,-0.31833650545196002,-0.31839567705312,-0.31845484865427998,-0.31851402025544001,-0.31857319185659999,-0.31881506639862001,-0.31924899147379998,-0.31968291654899,-0.32011684162418003,-0.32055076669936,-0.32066772341670002,-0.32072689501786,-0.32078606661901998,-0.32084523822019001,-0.32080377784657998,-0.32036985277140001,-0.31993592769620999,-0.31950200262102002,-0.31906807754583999,-0.31877464961586,-0.31859056019003001,-0.31840647076418999,-0.31822238133835001,-0.31803829191251998,-0.31839290408315002,-0.31879395604658001,-0.31919500801001,-0.31959605997343998,-0.31997143960197,-0.32028044685248003,-0.32058945410299,-0.32089846135351002,-0.32120746860402,-0.32110592721436998,-0.32077062147445001,-0.32043531573453998,-0.32010000999462002,-0.31976470425469999,-0.31934431604368002,-0.31892354021319003,-0.31850276438271002,-0.31808198855223002,-0.31789145868000002,-0.3181215704623,-0.31835168224459998,-0.31858179402689002,-0.31881190580919,-0.31923863010751002,-0.31974487602856,-0.32025112194960997,-0.32075736787066,-0.32122109491882,-0.32112247558355,-0.32102385624828,-0.32092523691301,-0.32082661757774,-0.32053075957193,-0.31997191667206998,-0.31941307377221001,-0.31885423087234999,-0.31829538797249002,-0.31813488369984999,-0.31808228672104,-0.31802968974223,-0.31797709276342001,-0.31801418496389999,-0.31857960248611,-0.31914502000832001,-0.31971043753053002,-0.32027585505273998,-0.32066585986161,-0.32088282239920002,-0.32109978493680003,-0.32131674747438999,-0.32153371001198,-0.32110483889820002,-0.32057229448773999,-0.32003975007729002,-0.31950720566683,-0.31900936810634001,-0.31863461463231002,-0.31825986115829002,-0.31788510768425998,-0.31751035421023999,-0.3176146089361,-0.31806825787833998,-0.31852190682058001,-0.31897555576282,-0.31942920470505998,-0.31994442550740998,-0.32046382067315998,-0.32098321583891998,-0.32150261100466998,-0.32177392971708002,-0.32145177322186003,-0.32112961672665002,-0.32080746023144002,-0.32048530373621997,-0.31995705295669002,-0.31931931458861001,-0.31868157622054,-0.31804383785245999,-0.31741511909101,-0.31757291002743998,-0.31773070096387002,-0.3178884919003,-0.31804628283674002,-0.31840820014331001,-0.31911825935725002,-0.31982831857118998,-0.32053837778513999,-0.32124843699908001,-0.32147036404742002,-0.32150981178152999,-0.32154925951564001,-0.32158870724975003,-0.32156130553572998,-0.32082494783238003,-0.32008859012904001,-0.31935223242569,-0.31861587472234998,-0.31809574904299998,-0.31784591339364998,-0.31759607774429999,-0.31734624209494999,-0.3170964064456,-0.31761182105767999,-0.31831530564927002,-0.31901879024086,-0.31972227483245003,-0.32038659495031002,-0.32084681851489999,-0.32130704207949001,-0.32176726564407998,-0.32222748920867,-0.32213122540703998,-0.32151978552836002,-0.32090834564969001,-0.32029690577101999,-0.31968546589234997,-0.31903363904781001,-0.31837617681267999,-0.31771871457753997,-0.31706125234241,-0.31666737133896,-0.31712759490356002,-0.31758781846814998,-0.31804804203274001,-0.31850826559732998,-0.31918331979248998,-0.32000514758641002,-0.32082697538032001,-0.32164880317423,-0.32247063096814998,-0.32227182691132999,-0.32202199126198,-0.32177215561263001,-0.32152231996328001,-0.32106006885075999,-0.32012647247686998,-0.31919287610299002,-0.31825927972910001,-0.31732568335521,-0.31701220357248999,-0.31700562895014001,-0.31699905432779002,-0.31699247970543998,-0.31701291917765001,-0.31799911253034002,-0.31898530588304003,-0.31997149923572998,-0.32095769258842999,-0.32167523583961,-0.32196451922306002,-0.32225380260651998,-0.32254308598997999,-0.32283236937344001,-0.32218766876354998,-0.32122119927790999,-0.32025472979226,-0.31928826030662,-0.31836070185122001,-0.31777556046195998,-0.31719041907269002,-0.31660527768342001,-0.31602013629415998,-0.31610080586681999,-0.31696208139484,-0.31782335692286001,-0.31868463245088002,-0.31954590797889998,-0.32041256545402003,-0.32128041560439002,-0.32214826575476002,-0.32301611590514001,-0.32361185719573998,-0.32294124571590999,-0.32227063423607999,-0.32160002275624,-0.32092941127641,-0.32001954914012998,-0.31890186334040999,-0.31778417754068,-0.31666649174096001,-0.31554880594124002,-0.31578799696393001,-0.31618904892735999,-0.31659010089078998,-0.31699115285422003,-0.31762057231238,-0.31892892216029001,-0.32023727200820001,-0.32154562185611002,-0.32285397170402003,-0.32333217484810001,-0.32327957786929001,-0.32322698089048002,-0.32317438391167003,-0.32312178693285998,-0.32174508188431,-0.32032496345643002,-0.31890484502854999,-0.31748472660067001,-0.31641239227757001,-0.31605736267059997,-0.31570233306362999,-0.31534730345666001,-0.31499227384968997,-0.31586188319606001,-0.31729515086865001,-0.31872841854123002,-0.32016168621382002,-0.32156776089055999,-0.32236986481742003,-0.32317196874428,-0.32397407267112999,-0.32477617659799002,-0.32472067247324998,-0.32338602413592998,-0.32205137579861998,-0.32071672746129998,-0.31938207912397998,-0.31810736271831003,-0.31685160984921001,-0.31559585698011,-0.31434010411100999,-0.31336188677408999,-0.31445984870676003,-0.31555781063943,-0.31665577257208999,-0.31775373450476002,-0.31913972751186998,-0.32084255470085998,-0.32254538188984999,-0.32424820907884,-0.32595103626782002,-0.32563490278265,-0.32491826894636,-0.32420163511007,-0.32348500127377999,-0.32250098455342002,-0.32039710540101002,-0.31829322624859002,-0.31618934709617003,-0.31408546794374997,-0.31324230617118998,-0.31342639559702001,-0.31361048502285999,-0.31379457444870001,-0.31397866387453,-0.31619537010621002,-0.31861483113150002,-0.32103429215677998,-0.32345375318205999,-0.32535952897437997,-0.32585920027307003,-0.32635887157177002,-0.32685854287047,-0.32735821416916999,-0.32591161835060001,-0.32330149327712998,-0.32069136820366001,-0.31808124313018998,-0.31547111805672001,-0.31410975379366002,-0.31276853083400002,-0.31142730787432998,-0.31008608491466,-0.31010232020659001,-0.31272559452476001,-0.31534886884293001,-0.31797214316110001,-0.32059541747928,-0.3230390301785,-0.32540589422497002,-0.32777275827143998,-0.33013962231791,-0.33222468701815999,-0.32981180061523002,-0.3273989142123,-0.32498602780937003,-0.32257314140644,-0.31966100114114998,-0.31605153347027998,-0.31244206579942002,-0.30883259812855002,-0.30522313045768001,-0.30587616488592001,-0.30776308150074999,-0.30964999811556998,-0.31153691473040002,-0.31386099155204,-0.31901549547546998,-0.32416999939889002,-0.32932450332231999,-0.33447900724573998,-0.33668307111969997,-0.33584151945874002,-0.33499996779777003,-0.33415841613679997,-0.33331686447582998,-0.32696850752911999,-0.31965095285211997,-0.31233339817511002,-0.30501584349811001,-0.29897659816098998,-0.29778659151539999,-0.29659658486981999,-0.29540657822423,-0.29421657157864001,-0.30002980495465997,-0.31119351370718001,-0.3223572224597,-0.33352093121221998,-0.34468463996474002,-0.35121945677936001,-0.35737987792253001,-0.36354029906570001,-0.36970072020888001,-0.36715274842471002,-0.34258995932023001,-0.31802717021575,-0.29346438111126999,-0.26890159200678998,-0.22414202520074999,-0.16810651890056999,-0.11207101260037999,-0.056035506300185001,0.0,0.0,0.062800792699682001,0.12560158539936001,0.18840237809905,0.25120317079873,0.30146781351139001,0.32927846605742001,0.35708911860344,0.38489977114946999,0.41271042369549998,0.41583037271578999,0.40918342951862002,0.40253648632145,0.39588954312426999,0.38879293153853001,0.37613678351226998,0.36348063548600001,0.35082448745973999,0.33816833943347002,0.33143501673085002,0.33245408319530001,0.33347314965975,0.33449221612420998,0.33551128258865998,0.34225890248592,0.35051662815916002,0.35877435383239997,0.36703207950563999,0.37424385879583999,0.37551276090963998,0.37678166302344002,0.37805056513724,0.37931946725104998,0.37702513276860999,0.37127891283357001,0.36553269289853002,0.35978647296347999,0.35404025302844,0.35117002038998002,0.34874398474233997,0.34631794909470998,0.34389191344707998,0.34289015568228998,0.34680863060367001,0.35072710552503999,0.35464558044641997,0.35856405536780001,0.36194229312331999,0.36493374629316999,0.36792519946301,0.37091665263285001,0.37390810580270001,0.37177672057717998,0.36932438644013998,0.36687205230309999,0.36441971816606999,0.36175091346998001,0.35857537087430003,0.35539982827861999,0.35222428568294001,0.34904874308724998,0.34878288086414999,0.35003205911089003,0.35128123735764,0.35253041560439002,0.35380871003584002,0.35689220791859999,0.35997570580136001,0.36305920368413003,0.36614270156688999,0.36797657394967997,0.36772016367797999,0.36746375340628001,0.36720734313457998,0.36695093286288,0.36484058344719,0.36205294357023998,0.35926530369329002,0.35647766381633,0.35389397140822998,0.35335485237543002,0.35281573334262001,0.35227661430981,0.35173749527700998,0.35249424772723997,0.35484138790664999,0.35718852808606999,0.35953566826548999,0.36188280844490001,0.36325338612432001,0.36439079579110001,0.36552820545787001,0.36666561512465001,0.36731437083041002,0.36549977506144998,0.36368517929249,0.36187058352353002,0.36005598775455999,0.35838258982753002,0.35683755357496999,0.35529251732242001,0.35374748106985998,0.35220244481730001,0.35311054775758,0.35434657675962999,0.35558260576167,0.35681863476372,0.35818266763765999,0.35995124105016002,0.36171981446266999,0.36348838787517002,0.36525696128766999,0.36557714986870998,0.36492626225593,0.36427537464315002,0.36362448703036998,0.36297359941759,0.36120284937274999,0.35938167898144002,0.35756050859012001,0.35573933819880998,0.35452327159886998,0.35462189093413998,0.35472051026940998,0.35481912960467998,0.35491774893994998,0.35611003657696,0.35783258763301001,0.35955513868904998,0.36127768974509,0.36295828844898997,0.36335934041242002,0.36376039237585001,0.36416144433927999,0.36456249630270998,0.36421735099191999,0.36270518785111999,0.36119302471032,0.35968086156952001,0.35816869842872001,0.35718787211468001,0.35638576818781997,0.35558366426096,0.35478156033410002,0.35419316890475999,0.35539632479505001,0.35659948068533998,0.35780263657563,0.35900579246592002,0.36016004867069001,0.36125801060335999,0.36235597253603002,0.3634539344687,0.36455189640135999,0.36406421148898999,0.36323580907273001,0.36240740665645998,0.36157900424020001,0.36066830723123999,0.35938625587272999,0.35810420451422997,0.35682215315572002,0.35554010179722001,0.35518058474960001,0.35560793520243,0.35603528565526998,0.35646263610809997,0.35688998656094001,0.35813795722399,0.35947918018364999,0.36082040314331998,0.36216162610299002,0.36315244107229999,0.36312614258289999,0.36309984409349,0.36307354560409,0.36304724711468001,0.36224119245102998,0.36094599184782999,0.35965079124462002,0.35835559064140998,0.3570603900382,0.35669256898911,0.35635068862684,0.35600880826456999,0.35566692790229998,0.35581696644957,0.35696095073869999,0.35810493502781998,0.35924891931695002,0.36039290360608001,0.36120603977906002,0.36187007663653997,0.36253411349401998,0.36319815035150999,0.36378673559057001,0.36286628846139002,0.36194584133221003,0.36102539420302998,0.36010494707384,0.35919250577731998,0.35829178251519,0.35739105925305997,0.35649033599093,0.35558961272880002,0.35585951513934,0.35649067888507002,0.35712184263079,0.35775300637652002,0.35843649874911998,0.35949501294767999,0.36055352714624,0.36161204134480002,0.36267055554335997,0.36306850655112999,0.36275292467825998,0.36243734280540002,0.36212176093254,0.36180617905967999,0.36081763017335,0.35969994437363001,0.35858225857390003,0.35746457277417998,0.35656478874382003,0.35655163949911001,0.35653849025440998,0.35652534100971001,0.35651219176500998,0.35710902137179001,0.35819383405975003,0.35927864674771998,0.36036345943567999,0.36144827212364999,0.3618421531271,0.36217088424465999,0.36249961536223002,0.3628283464798,0.36280464205906998,0.36183817257342998,0.36087170308778999,0.35990523360214999,0.3589387641165,0.35820438923577003,0.35760609860179998,0.35700780796782999,0.35640951733387,0.35581122669990001,0.35656495273666,0.35733418355176999,0.35810341436686999,0.35887264518196998,0.35965784293706998,0.36047309610862999,0.36128834928019998,0.36210360245175999,0.36291885562331999,0.36278825768273998,0.36226228789463,0.36173631810653001,0.36121034831842003,0.36065724516823,0.35970392492728998,0.35875060468636,0.35779728444542003,0.35684396420448,0.35639532449831002,0.35663858552531003,0.35688184655230998,0.35712510757930999,0.35736836860630999,0.35821166455483999,0.35922415639694,0.36023664823904,0.36124914008114001,0.36212794793543002,0.36217397029189002,0.36221999264834998,0.36226601500480998,0.36231203736126999,0.36184872774944998,0.36086910901911001,0.35988949028875999,0.35890987155842002,0.35793025282807001,0.35750144134805001,0.35716613560812999,0.35683082986821002,0.35649552412829999,0.35641807477882997,0.35729249955155001,0.35816692432427999,0.35904134909699997,0.35991577386973,0.3606248938519,0.36121003524117001,0.36179517663042998,0.3623803180197,0.36296545940897001,0.36235867096379998,0.36166176099455999,0.36096485102532,0.36026794105608001,0.35954452387926999,0.35875556919710999,0.35796661451494999,0.35717765983279998,0.35638870515063997,0.35641554034390999,0.35688891315319998,0.35736228596250003,0.35783565877179002,0.35831105912902,0.35923150625820999,0.36015195338738998,0.36107240051657002,0.36199284764575002,0.36250539983722002,0.36230158654432998,0.36209777325143999,0.36189395995855,0.36169014666566002,0.36092690904371999,0.35994729031338002,0.35896767158303,0.35798805285268998,0.35707939830009999,0.35699392820954001,0.35690845811896998,0.35682298802840001,0.35673751793783998,0.35710954316721,0.35806943803050001,0.35902933289379002,0.35998922775707998,0.36094912262036999,0.36143805984177002,0.36180623869343997,0.36217441754510998,0.36254259639677999,0.36272119951644,0.36185992398841998,0.36099864846039997,0.36013737293238002,0.35927609740436001,0.35853948625752002,0.35792147175650002,0.35730345725547003,0.35668544275445002,0.35606742825343002,0.35658293231616001,0.35726669304068998,0.35795045376522999,0.35863421448976002,0.35935110176954999,0.36017950418581002,0.36100790660207999,0.36183630901834002,0.36266471143460999,0.36274016305301998,0.36228651411078,0.36183286516854002,0.36137921622629998,0.36092556728406,0.35998078957964003,0.35900774547164999,0.35803470136366,0.35706165725566003,0.35643821608221998,0.35661573088571002,0.35679324568919002,0.35697076049268001,0.35714827529616999,0.35790042103822001,0.35894578599207999,0.35999115094592998,0.36103651589979002,0.36206309621836003,0.36218801404304002,0.36231293186771002,0.36243784969239001,0.36256276751706001,0.36224949645250998,0.36121728074335002,0.3601850650342,0.35915284932503999,0.35812063361589003,0.35752933504061002,0.35709540996542,0.35666148489024002,0.35622755981505,0.35592387487786997,0.35685747125175998,0.35779106762564,0.35872466399953001,0.35965826037340998,0.36049644272678,0.36121965118541999,0.36194285964407003,0.36266606810271002,0.36338927656136,0.36291694734291002,0.36216744039485999,0.36141793344681,0.36066842649876002,0.35987978489386002,0.35890016616352,0.35792054743316998,0.35694092870283001,0.35596130997247999,0.35576326624615001,0.35626293754484001,0.35676260884354,0.35726228014223999,0.35776195144093997,0.35885620117188,0.36002648395040998,0.36119676672894002,0.36236704950747001,0.36320725940878001,0.36302974460528997,0.36285222980180998,0.36267471499831999,0.36249720019484,0.36164949134786001,0.36036086536700002,0.35907223938614002,0.35778361340529002,0.35649498742442998,0.35624935595536,0.35604554266247002,0.35584172936957997,0.35563791607668999,0.35592178769617,0.35724328678877998,0.35856478588140001,0.35988628497400998,0.36120778406662002,0.36204785979196002,0.36265929967062999,0.3632707395493,0.36388217942797002,0.36442659095723001,0.36319056195519001,0.36195453295314001,0.36071850395109001,0.35948247494905,0.35831907987012002,0.35726714029390999,0.35621520071770002,0.35516326114149999,0.35411132156529002,0.35464325472967001,0.35569519430587998,0.35674713388209001,0.35779907345829998,0.35889922693175003,0.36038509158315002,0.36187095623454002,0.36335682088594001,0.36484268553733001,0.36529163832075001,0.36456842986211002,0.36384522140345998,0.36312201294481999,0.36239880448618,0.36067434514972002,0.35874140617844003,0.35680846720715997,0.35487552823586999,0.35334601167009,0.35358269807474002,0.35381938447937999,0.35405607088403002,0.35429275728867998,0.35570303614568999,0.35809619868157,0.36048936121744002,0.36288252375331997,0.36527568628919999,0.36593624947998998,0.36640962228929003,0.36688299509858002,0.36735636790788001,0.36694678831636002,0.36403423061473,0.36112167291309999,0.35820911521148002,0.35529655750985001,0.35318579065782002,0.35156843355939998,0.34995107646098,0.34833371936256002,0.34671636226413999,0.35029726536261002,0.35399877774639998,0.35770029013018001,0.36140180251397003,0.36520701801130001,0.3692175376456,0.37322805727989999,0.37723857691419999,0.38124909654848999,0.37823416258454001,0.37211976379782002,0.36600536501110997,0.35989096622438999,0.35309695125966001,0.33395165097265,0.31480635068564,0.29566105039863999,0.27651575011163998,0.25613726833476003,0.23398736563320999,0.21183746293165001,0.1896875602301,0.16753765752854999,0.15295858900314999,0.14065747058385999,0.12835635216456001,0.11605523374527001,0.10532033647277,0.10535320958453,0.10538608269629,0.10541895580804,0.1054518289198,0.1075169908517,0.11173789840124,0.11595880595077999,0.12017971350032,0.12440062104985999,0.12574873170913001,0.12656398488069001,0.12737923805226001,0.12819449122382001,0.12838745117188,0.12611920646067001,0.12385096174947,0.12158271703827001,0.11931447232707,0.11773851596849,0.11670630025934001,0.11567408455018,0.11464186884102,0.11360965313187001,0.11470882264824001,0.11599744862909001,0.11728607460995,0.1185747005908,0.11979602987031,0.12084139482417,0.12188675977803,0.12293212473189,0.12397748968574,0.12392499706602,0.12324123634148,0.12255747561695,0.12187371489241,0.12118995416788,0.12023846766514,0.1192851474242,0.11833182718326,0.11737850694231999,0.11685730785525,0.117133441994,0.11740957613276,0.11768571027150999,0.11796184441026999,0.11861595224624,0.11942463079545,0.12023330934466001,0.12104198789387,0.12179520704365,0.1217886324213,0.12178205779895,0.1217754831766,0.12176890855425,0.12149046360717999,0.12084615061676,0.12020183762632999,0.1195575246359,0.11891321164547,0.11865061437087999,0.11849282343445,0.11833503249802001,0.11817724156157999,0.11810961687454,0.11858298968384,0.11905636249312999,0.11952973530242,0.12000310811172001,0.12036445889755,0.12061429454689999,0.12086413019625,0.1211139658456,0.12136380149495,0.12112771142793,0.12081212955506999,0.1204965476822,0.12018096580934,0.11987110877771,0.11958182539425,0.11929254201079,0.11900325862734,0.11871397524388,0.11869733742405,0.11888142684989,0.11906551627572,0.11924960570156,0.1194336951274,0.11970377643923,0.11997991057798001,0.12025604471673,0.12053217885549,0.12070638398514,0.12063406313927,0.12056174229341,0.12048942144755,0.12041710060168,0.12023353297127,0.11999027194427,0.11974701091727,0.11950374989027,0.1192626953125,0.1192626953125,0.1192626953125,0.1192626953125,0.1192626953125,0.11933273516694,0.11952339921511999,0.11971406326330999,0.1199047273115,0.12009539135969,0.12018587068633001,0.12023846766514,0.12029106464394999,0.12034366162276,0.12038026184470001,0.12024219477532,0.12010412770594001,0.11996606063656,0.11982799356719,0.11971899795719,0.11964667711132,0.11957435626545999,0.11950203541958999,0.11942971457373,0.11947843535796,0.11955733082617,0.11963622629439,0.1197151217626,0.11979297363997,0.11986529448583,0.1199376153317,0.12000993617756001,0.12008225702343001,0.1201001918776,0.12006731876583999,0.12003444565408,0.12000157254233,0.11996869943056999,0.11991280768636001,0.1198536360852,0.11979446448404001,0.11973529288288,0.11969147697564,0.11969805159799,0.11970462622035,0.1197112008427,0.11971777546505,0.1197399144995,0.11977278761125,0.11980566072300999,0.11983853383477,0.11987140694652,0.11987929351166,0.11988586813401,0.11989244275636,0.11989901737871,0.11990153690519,0.11989496228284,0.11988838766049,0.11988181303813999,0.11987523841578,0.119873046875,0.119873046875,0.119873046875,0.119873046875,0.11987255489646,0.1198528310294,0.11983310716235,0.11981338329529,0.11979365942824,0.11977645508767,0.11976330584295999,0.11975015659825999,0.11973700735355999,0.11972385810886001,0.11974483428493,0.11977770739669,0.11981058050844,0.11984345362020001,0.11987698270335,0.11991643043745,0.11995587817156,0.11999532590567,0.12003477363978,0.12004109481864,0.12000822170688,0.11997534859512,0.11994247548337,0.11990960237161,0.11984989406658,0.11978414784307,0.11971840161956,0.11965265539604,0.11960183252168,0.11962155638873,0.11964128025579,0.11966100412284,0.11968072798989,0.11973548669261,0.11982095678316999,0.11990642687373999,0.11999189696430999,0.12007736705487,0.12009252893907001,0.12009910356142001,0.12010567818378,0.12011225280613,0.12009094864436,0.11998575468674,0.11988056072912,0.11977536677149,0.11967017281387,0.11960493347734,0.11956548574324,0.11952603800913,0.11948659027502,0.11944714254091,0.11955376770884001,0.11966553628881001,0.11977730486879,0.11988907344876,0.11999018249363,0.12006907796184001,0.12014797343006001,0.12022686889827,0.12030576436649,0.12026349893709,0.12016487960182,0.12006626026655,0.11996764093128,0.11986794818828,0.1197430303636,0.11961811253893,0.11949319471425,0.11936827688958,0.11932207563183,0.1193943964777,0.11946671732356,0.11953903816942001,0.11961135901529001,0.11975339172989,0.11991775728868,0.12008212284746,0.12024648840624,0.12038804405074,0.12035517093898999,0.12032229782723,0.12028942471548,0.12025655160371999,0.12014889775338,0.11995823370519,0.11976756965701001,0.11957690560882001,0.11938624156063,0.11933783385365999,0.1193181099866,0.11929838611955,0.1192786622525,0.11930026458308,0.11949750325362,0.11969474192416001,0.11989198059470001,0.12008921926523999,0.12022512461071,0.12031059470128,0.12039606479183999,0.12048153488240999,0.12056700497297999,0.12040201325968999,0.12021134921149999,0.12002068516331001,0.11983002111512001,0.11964982279231,0.11949860647823,0.11934739016415,0.11919617385007,0.11904495753599,0.11909053263923,0.11925489819801,0.11941926375679,0.11958362931558,0.11974799487436,0.11995754791692,0.12016793583216,0.1203783237474,0.12058871166265001,0.12068952253869999,0.12057775395872999,0.12046598537875999,0.12035421679878,0.12024244821881,0.12002966004462,0.11977324977291,0.11951683950121,0.11926042922951,0.11902079095361,0.11906023868771,0.11909968642182001,0.11913913415593,0.11917858189004001,0.11932170292081,0.11961098630427,0.11990026968773,0.12018955307119,0.12047883645464,0.12058002004172,0.12062604239817,0.12067206475463001,0.12071808711109,0.12071828092082,0.12041584829266,0.1201134156645,0.11981098303634,0.11950855040817999,0.11928662335982999,0.11914855629046001,0.11901048922108,0.11887242215170001,0.11873435508232,0.11895313644968,0.11923584521079,0.11951855397189,0.119801262733,0.12007311814927001,0.12030322993157,0.12053334171386,0.12076345349615999,0.12099356527846,0.12096382293925,0.12073371115695,0.12050359937466,0.12027348759236001,0.12004337581007,0.11973438346798999,0.11941880159513001,0.11910321972227,0.11878763784941,0.11860330988852,0.11875452620260001,0.11890574251668,0.11905695883076001,0.11920817514484,0.11951074194896,0.11989864466769,0.12028654738642,0.12067445010515,0.12106235282387,0.12101731442450001,0.12097129206804,0.12092526971158001,0.12087924735512,0.12069512811241,0.12026120303722,0.11982727796202999,0.11939335288685,0.11895942781166,0.11877909531288,0.11870019984467001,0.11862130437645001,0.11854240890822999,0.11850120197812,0.11894170167566,0.11938220137320001,0.11982270107074,0.12026320076827,0.12061022454259,0.12083376170253,0.12105729886247001,0.12128083602242,0.12150437318236,0.12122466101784,0.12081045980971,0.12039625860156999,0.11998205739344001,0.11957463952583,0.11920646067416001,0.11883828182248,0.11847010297081,0.11810192411914,0.11809280015343,0.11843468051569001,0.11877656087796,0.11911844124022999,0.1194603216025,0.11993852474658,0.12043819604528,0.12093786734398,0.12143753864268,0.12177795797776,0.12156099544016,0.12134403290257,0.12112707036497999,0.12091010782738,0.12046033507973,0.11984232057871,0.11922430607768,0.11860629157666,0.11798827707564,0.11799981620874,0.11805241318755,0.11810501016636001,0.11815760714517,0.11840159868576999,0.11909850865501,0.11979541862423999,0.12049232859348,0.12118923856272,0.12152853976475,0.12167975607883,0.12183097239291001,0.12198218870699,0.12212150808538,0.12139829962673999,0.1206750911681,0.11995188270944999,0.11922867425081,0.11862771500595,0.11823323766488,0.1178387603238,0.11744428298272,0.11704980564164,0.11744741375527,0.11813774910215,0.11882808444904,0.11951841979593,0.12020642942607,0.12087046628355,0.12153450314103,0.12219853999851001,0.12286257685599,0.12296859077785,0.12238344938859,0.12179830799932,0.12121316661004999,0.12062802522079,0.11975708902319,0.11881691802695001,0.11787674703072,0.11693657603448,0.11621215999214,0.11659348808851,0.11697481618489,0.11735614428127,0.11773747237764,0.1185577049684,0.11978058472574001,0.12100346448308,0.12222634424043,0.12344922399777,0.12353834665631,0.12347260043280001,0.12340685420928001,0.12334110798577,0.12293567294077,0.12144323366703,0.11995079439328001,0.11845835511953,0.11696591584579,0.11612434927638,0.11572329731295,0.11532224534952,0.11492119338609,0.11452014142266,0.11616521331235,0.11790748823545,0.11964976315855,0.12139203808163999,0.12293063388782,0.12402202119812999,0.12511340850845001,0.12620479581877,0.12729618312908,0.12633557266063999,0.12436976057760001,0.12240394849456,0.12043813641152,0.11846534717823,0.11626284869054,0.11406035020285001,0.11185785171515999,0.10965535322747,0.10915326676138,0.11133604138201,0.11351881600265,0.11570159062328,0.11788436524392,0.12179856144281,0.12630217775346,0.13080579406410001,0.13530941037475,0.13906414589185001,0.13638827459486999,0.13371240329789,0.13103653200091001,0.12836066070393001,0.11953827783895001,0.10357509476998,0.087611911701003006,0.071648728632031006,0.055685545563057,0.034142013870337003,0.011380671290111,-0.011380671290111,-0.034142013870333998,-0.055685545563057,-0.071648728632028993,-0.087611911701003006,-0.10357509476998,-0.11953827783895001,-0.12836066070393001,-0.13103653200091001,-0.13371240329789,-0.13638827459486999,-0.13906414589185001,-0.13530941037475,-0.13080579406410001,-0.12630217775346,-0.12179856144281,-0.11788436524392,-0.11570159062328,-0.11351881600265,-0.11133604138201,-0.10915326676138,-0.10965535322747,-0.11185785171515999,-0.11406035020285001,-0.11626284869054,-0.11846534717823,-0.12043813641152,-0.12240394849456,-0.12436976057760001,-0.12633557266063999,-0.12729618312908,-0.12620479581877,-0.12511340850845001,-0.12402202119812999,-0.12293063388782,-0.12139203808163999,-0.11964976315855,-0.11790748823545,-0.11616521331236,-0.11452014142266,-0.11492119338609,-0.11532224534952,-0.11572329731295,-0.11612434927638,-0.11696591584579,-0.11845835511953,-0.11995079439328001,-0.12144323366703,-0.12293567294077,-0.12334110798577,-0.12340685420928001,-0.12347260043280001,-0.12353834665631,-0.12344922399777,-0.12222634424043,-0.12100346448308,-0.11978058472574001,-0.1185577049684,-0.11773747237764,-0.11735614428127,-0.11697481618489,-0.11659348808851,-0.11621215999214,-0.11693657603448,-0.11787674703072,-0.11881691802695001,-0.11975708902319,-0.12062802522079,-0.12121316661004999,-0.12179830799932,-0.12238344938859,-0.12296859077785,-0.12286257685599,-0.12219853999851001,-0.12153450314103,-0.12087046628355,-0.12020642942607,-0.11951841979593,-0.11882808444904,-0.11813774910215,-0.11744741375527,-0.11704980564164,-0.11744428298272,-0.1178387603238,-0.11823323766488,-0.11862771500595,-0.11922867425081,-0.11995188270944999,-0.1206750911681,-0.12139829962673999,-0.12212150808538,-0.12198218870699,-0.12183097239291001,-0.12167975607883,-0.12152853976475,-0.12118923856272,-0.12049232859348,-0.11979541862423999,-0.11909850865501,-0.11840159868576999,-0.11815760714517,-0.11810501016636001,-0.11805241318755,-0.11799981620874,-0.11798827707564,-0.11860629157666,-0.11922430607768,-0.11984232057871,-0.12046033507973,-0.12091010782738,-0.12112707036497999,-0.12134403290257,-0.12156099544016,-0.12177795797776,-0.12143753864268,-0.12093786734398,-0.12043819604528,-0.11993852474658,-0.1194603216025,-0.11911844124022999,-0.11877656087796,-0.11843468051569001,-0.11809280015343,-0.11810192411914,-0.11847010297081,-0.11883828182248,-0.11920646067416001,-0.11957463952583,-0.11998205739344001,-0.12039625860156999,-0.12081045980971,-0.12122466101784,-0.12150437318236,-0.12128083602242,-0.12105729886247001,-0.12083376170253,-0.12061022454259,-0.12026320076827,-0.11982270107074,-0.11938220137320001,-0.11894170167566,-0.11850120197812,-0.11854240890822999,-0.11862130437645001,-0.11870019984467001,-0.11877909531288,-0.11895942781166,-0.11939335288685,-0.11982727796202999,-0.12026120303722,-0.12069512811241,-0.12087924735512,-0.12092526971158001,-0.12097129206804,-0.12101731442450001,-0.12106235282387,-0.12067445010515,-0.12028654738642,-0.11989864466769,-0.11951074194896,-0.11920817514484,-0.11905695883076001,-0.11890574251668,-0.11875452620260001,-0.11860330988852,-0.11878763784941,-0.11910321972227,-0.11941880159513001,-0.11973438346798999,-0.12004337581007,-0.12027348759236001,-0.12050359937466,-0.12073371115695,-0.12096382293925,-0.12099356527846,-0.12076345349615999,-0.12053334171386,-0.12030322993157,-0.12007311814927001,-0.119801262733,-0.11951855397189,-0.11923584521079,-0.11895313644968,-0.11873435508232,-0.11887242215170001,-0.11901048922108,-0.11914855629046001,-0.11928662335982999,-0.11950855040817999,-0.11981098303634,-0.1201134156645,-0.12041584829266,-0.12071828092082,-0.12071808711109,-0.12067206475463001,-0.12062604239817,-0.12058002004172,-0.12047883645464,-0.12018955307119,-0.11990026968773,-0.11961098630427,-0.11932170292081,-0.11917858189004001,-0.11913913415593,-0.11909968642182001,-0.11906023868771,-0.11902079095361,-0.11926042922951,-0.11951683950121,-0.11977324977291,-0.12002966004462,-0.12024244821881,-0.12035421679878,-0.12046598537875999,-0.12057775395872999,-0.12068952253869999,-0.12058871166265001,-0.1203783237474,-0.12016793583216,-0.11995754791692,-0.11974799487436,-0.11958362931558,-0.11941926375679,-0.11925489819801,-0.11909053263923,-0.11904495753599,-0.11919617385007,-0.11934739016415,-0.11949860647823,-0.11964982279231,-0.11983002111512001,-0.12002068516331001,-0.12021134921149999,-0.12040201325968999,-0.12056700497297999,-0.12048153488240999,-0.12039606479183999,-0.12031059470128,-0.12022512461071,-0.12008921926523999,-0.11989198059470001,-0.11969474192416001,-0.11949750325362,-0.11930026458308,-0.1192786622525,-0.11929838611955,-0.1193181099866,-0.11933783385365999,-0.11938624156063,-0.11957690560882001,-0.11976756965701001,-0.11995823370519,-0.12014889775338,-0.12025655160371999,-0.12028942471548,-0.12032229782723,-0.12035517093898999,-0.12038804405074,-0.12024648840624,-0.12008212284746,-0.11991775728868,-0.11975339172989,-0.11961135901529001,-0.11953903816942001,-0.11946671732356,-0.1193943964777,-0.11932207563183,-0.11936827688958,-0.11949319471425,-0.11961811253893,-0.1197430303636,-0.11986794818828,-0.11996764093128,-0.12006626026655,-0.12016487960182,-0.12026349893709,-0.12030576436649,-0.12022686889827,-0.12014797343006001,-0.12006907796184001,-0.11999018249363,-0.11988907344876,-0.11977730486879,-0.11966553628881001,-0.11955376770884001,-0.11944714254091,-0.11948659027502,-0.11952603800913,-0.11956548574324,-0.11960493347734,-0.11967017281387,-0.11977536677149,-0.11988056072912,-0.11998575468674,-0.12009094864436,-0.12011225280613,-0.12010567818378,-0.12009910356142001,-0.12009252893907001,-0.12007736705487,-0.11999189696430999,-0.11990642687373999,-0.11982095678316999,-0.11973548669261,-0.11968072798989,-0.11966100412284,-0.11964128025579,-0.11962155638873,-0.11960183252168,-0.11965265539604,-0.11971840161956,-0.11978414784307,-0.11984989406658,-0.11990960237161,-0.11994247548337,-0.11997534859512,-0.12000822170688,-0.12004109481864,-0.12003477363978,-0.11999532590567,-0.11995587817156,-0.11991643043745,-0.11987698270335,-0.11984345362020001,-0.11981058050844,-0.11977770739669,-0.11974483428493,-0.11972385810886001,-0.11973700735355999,-0.11975015659825999,-0.11976330584295999,-0.11977645508767,-0.11979365942824,-0.11981338329529,-0.11983310716235,-0.1198528310294,-0.11987255489646,-0.119873046875,-0.119873046875,-0.119873046875,-0.119873046875,-0.11987523841578,-0.11988181303813999,-0.11988838766049,-0.11989496228284,-0.11990153690519,-0.11989901737871,-0.11989244275636,-0.11988586813401,-0.11987929351166,-0.11987140694652,-0.11983853383477,-0.11980566072300999,-0.11977278761125,-0.1197399144995,-0.11971777546505,-0.1197112008427,-0.11970462622035,-0.11969805159799,-0.11969147697564,-0.11973529288288,-0.11979446448404001,-0.1198536360852,-0.11991280768636001,-0.11996869943056999,-0.12000157254233,-0.12003444565408,-0.12006731876583999,-0.1201001918776,-0.12008225702343001,-0.12000993617756001,-0.1199376153317,-0.11986529448583,-0.11979297363997,-0.1197151217626,-0.11963622629439,-0.11955733082617,-0.11947843535796,-0.11942971457373,-0.11950203541958999,-0.11957435626545999,-0.11964667711132,-0.11971899795719,-0.11982799356719,-0.11996606063656,-0.12010412770594001,-0.12024219477532,-0.12038026184470001,-0.12034366162276,-0.12029106464394999,-0.12023846766514,-0.12018587068633001,-0.12009539135969,-0.1199047273115,-0.11971406326330999,-0.11952339921511999,-0.11933273516694,-0.1192626953125,-0.1192626953125,-0.1192626953125,-0.1192626953125,-0.1192626953125,-0.11950374989027,-0.11974701091727,-0.11999027194427,-0.12023353297127,-0.12041710060168,-0.12048942144755,-0.12056174229341,-0.12063406313927,-0.12070638398514,-0.12053217885549,-0.12025604471673,-0.11997991057798001,-0.11970377643923,-0.1194336951274,-0.11924960570156,-0.11906551627572,-0.11888142684989,-0.11869733742405,-0.11871397524388,-0.11900325862734,-0.11929254201079,-0.11958182539425,-0.11987110877771,-0.12018096580934,-0.1204965476822,-0.12081212955506999,-0.12112771142793,-0.12136380149495,-0.1211139658456,-0.12086413019625,-0.12061429454689999,-0.12036445889755,-0.12000310811172001,-0.11952973530242,-0.11905636249312999,-0.11858298968384,-0.11810961687454,-0.11817724156157999,-0.11833503249802001,-0.11849282343445,-0.11865061437087999,-0.11891321164547,-0.1195575246359,-0.12020183762632999,-0.12084615061676,-0.12149046360717999,-0.12176890855425,-0.1217754831766,-0.12178205779895,-0.1217886324213,-0.12179520704365,-0.12104198789387,-0.12023330934466001,-0.11942463079545,-0.11861595224624,-0.11796184441026999,-0.11768571027150999,-0.11740957613276,-0.117133441994,-0.11685730785525,-0.11737850694231999,-0.11833182718326,-0.1192851474242,-0.12023846766514,-0.12118995416788,-0.12187371489241,-0.12255747561695,-0.12324123634148,-0.12392499706602,-0.12397748968574,-0.12293212473189,-0.12188675977803,-0.12084139482417,-0.11979602987031,-0.1185747005908,-0.11728607460995,-0.11599744862909001,-0.11470882264824001,-0.11360965313187001,-0.11464186884102,-0.11567408455018,-0.11670630025934001,-0.11773851596849,-0.11931447232707,-0.12158271703827001,-0.12385096174947,-0.12611920646067001,-0.12838745117188,-0.12819449122382001,-0.12737923805226001,-0.12656398488069001,-0.12574873170913001,-0.12440062104985999,-0.12017971350032,-0.11595880595077999,-0.11173789840124,-0.1075169908517,-0.1054518289198,-0.10541895580804,-0.10538608269629,-0.10535320958453,-0.10532033647277,-0.11605523374527001,-0.12835635216456001,-0.14065747058385999,-0.15295858900314999,-0.16753765752854999,-0.1896875602301,-0.21183746293165001,-0.23398736563320999,-0.25613726833476003,-0.27651575011162999,-0.29566105039863999,-0.31480635068564,-0.33395165097265,-0.35309695125966001,-0.35989096622438999,-0.36600536501110997,-0.37211976379782002,-0.37823416258454001,-0.38124909654848999,-0.37723857691419999,-0.37322805727989999,-0.3692175376456,-0.36520701801130001,-0.36140180251397003,-0.35770029013018001,-0.35399877774639998,-0.35029726536261002,-0.34671636226413999,-0.34833371936256002,-0.34995107646098,-0.35156843355939998,-0.35318579065782002,-0.35529655750985001,-0.35820911521148002,-0.36112167291309999,-0.36403423061473,-0.36694678831636002,-0.36735636790788001,-0.36688299509858002,-0.36640962228929003,-0.36593624947998998,-0.36527568628919999,-0.36288252375331997,-0.36048936121745001,-0.35809619868157,-0.35570303614568999,-0.35429275728867998,-0.35405607088403002,-0.35381938447937999,-0.35358269807474002,-0.35334601167009,-0.35487552823586999,-0.35680846720715997,-0.35874140617844003,-0.36067434514972002,-0.36239880448618,-0.36312201294481999,-0.36384522140345998,-0.36456842986211002,-0.36529163832075001,-0.36484268553733001,-0.36335682088594001,-0.36187095623454002,-0.36038509158315002,-0.35889922693175003,-0.35779907345829998,-0.35674713388209001,-0.35569519430587998,-0.35464325472967001,-0.35411132156529002,-0.35516326114149999,-0.35621520071770002,-0.35726714029390999,-0.35831907987012002,-0.35948247494905,-0.36071850395109001,-0.36195453295314001,-0.36319056195519001,-0.36442659095723001,-0.36388217942797002,-0.3632707395493,-0.36265929967062999,-0.36204785979196002,-0.36120778406662002,-0.35988628497400998,-0.35856478588140001,-0.35724328678877998,-0.35592178769617,-0.35563791607668999,-0.35584172936957997,-0.35604554266247002,-0.35624935595536,-0.35649498742442998,-0.35778361340529002,-0.35907223938614002,-0.36036086536700002,-0.36164949134786001,-0.36249720019484,-0.36267471499831999,-0.36285222980180998,-0.36302974460528997,-0.36320725940878001,-0.36236704950747001,-0.36119676672894002,-0.36002648395040998,-0.35885620117187,-0.35776195144093997,-0.35726228014223999,-0.35676260884354,-0.35626293754484001,-0.35576326624615001,-0.35596130997247999,-0.35694092870283001,-0.35792054743316998,-0.35890016616352,-0.35987978489386002,-0.36066842649876002,-0.36141793344681,-0.36216744039485999,-0.36291694734291002,-0.36338927656136,-0.36266606810271002,-0.36194285964407003,-0.36121965118541999,-0.36049644272678,-0.35965826037340998,-0.35872466399953001,-0.35779106762564,-0.35685747125175998,-0.35592387487786997,-0.35622755981505,-0.35666148489024002,-0.35709540996542,-0.35752933504061002,-0.35812063361589003,-0.35915284932503999,-0.3601850650342,-0.36121728074335002,-0.36224949645250998,-0.36256276751706001,-0.36243784969239001,-0.36231293186771002,-0.36218801404304002,-0.36206309621836003,-0.36103651589979002,-0.35999115094592998,-0.35894578599207999,-0.35790042103822001,-0.35714827529616999,-0.35697076049268001,-0.35679324568919002,-0.35661573088571002,-0.35643821608221998,-0.35706165725566003,-0.35803470136366,-0.35900774547164999,-0.35998078957964003,-0.36092556728406,-0.36137921622629998,-0.36183286516854002,-0.36228651411078,-0.36274016305301998,-0.36266471143460999,-0.36183630901834002,-0.36100790660207999,-0.36017950418581002,-0.35935110176954999,-0.35863421448976002,-0.35795045376522999,-0.35726669304068998,-0.35658293231616001,-0.35606742825343002,-0.35668544275445002,-0.35730345725547003,-0.35792147175650002,-0.35853948625752002,-0.35927609740436001,-0.36013737293238002,-0.36099864846039997,-0.36185992398841998,-0.36272119951644,-0.36254259639677999,-0.36217441754510998,-0.36180623869343997,-0.36143805984177002,-0.36094912262036999,-0.35998922775707998,-0.35902933289379002,-0.35806943803050001,-0.35710954316721,-0.35673751793783998,-0.35682298802840001,-0.35690845811896998,-0.35699392820954001,-0.35707939830009999,-0.35798805285268998,-0.35896767158303,-0.35994729031338002,-0.36092690904371999,-0.36169014666566002,-0.36189395995855,-0.36209777325143999,-0.36230158654432998,-0.36250539983722002,-0.36199284764575002,-0.36107240051657002,-0.36015195338738998,-0.35923150625820999,-0.35831105912902,-0.35783565877179002,-0.35736228596250003,-0.35688891315319998,-0.35641554034390999,-0.35638870515063997,-0.35717765983279998,-0.35796661451494999,-0.35875556919710999,-0.35954452387926999,-0.36026794105608001,-0.36096485102532,-0.36166176099455999,-0.36235867096379998,-0.36296545940897001,-0.3623803180197,-0.36179517663042998,-0.36121003524117001,-0.3606248938519,-0.35991577386973,-0.35904134909699997,-0.35816692432427999,-0.35729249955155001,-0.35641807477882997,-0.35649552412829999,-0.35683082986821002,-0.35716613560812999,-0.35750144134805001,-0.35793025282807001,-0.35890987155842002,-0.35988949028875999,-0.36086910901911001,-0.36184872774944998,-0.36231203736126999,-0.36226601500480998,-0.36221999264834998,-0.36217397029189002,-0.36212794793543002,-0.36124914008114001,-0.36023664823904,-0.35922415639694,-0.35821166455483999,-0.35736836860630999,-0.35712510757930999,-0.35688184655230998,-0.35663858552531003,-0.35639532449831002,-0.35684396420448,-0.35779728444542003,-0.35875060468635001,-0.35970392492728998,-0.36065724516823,-0.36121034831842003,-0.36173631810653001,-0.36226228789463,-0.36278825768273998,-0.36291885562331999,-0.36210360245175999,-0.36128834928019998,-0.36047309610862999,-0.35965784293706998,-0.35887264518196998,-0.35810341436686999,-0.35733418355176999,-0.35656495273666,-0.35581122669990001,-0.35640951733387,-0.35700780796782999,-0.35760609860179998,-0.35820438923577003,-0.3589387641165,-0.35990523360214999,-0.36087170308778999,-0.36183817257342998,-0.36280464205906998,-0.3628283464798,-0.36249961536223002,-0.36217088424465999,-0.3618421531271,-0.36144827212364999,-0.36036345943567999,-0.35927864674771998,-0.35819383405975003,-0.35710902137179001,-0.35651219176500998,-0.35652534100971001,-0.35653849025440998,-0.35655163949911001,-0.35656478874382003,-0.35746457277417998,-0.35858225857390003,-0.35969994437363001,-0.36081763017335,-0.36180617905967999,-0.36212176093254,-0.36243734280540002,-0.36275292467825998,-0.36306850655112999,-0.36267055554335997,-0.36161204134480002,-0.36055352714624,-0.35949501294767999,-0.35843649874911998,-0.35775300637652002,-0.35712184263079,-0.35649067888507002,-0.35585951513934,-0.35558961272880002,-0.35649033599093,-0.35739105925305997,-0.35829178251519,-0.35919250577731998,-0.36010494707384,-0.36102539420302998,-0.36194584133221003,-0.36286628846139002,-0.36378673559057001,-0.36319815035150999,-0.36253411349401998,-0.36187007663653997,-0.36120603977906002,-0.36039290360608001,-0.35924891931695002,-0.35810493502781998,-0.35696095073869999,-0.35581696644957,-0.35566692790229998,-0.35600880826456999,-0.35635068862684,-0.35669256898911,-0.3570603900382,-0.35835559064140998,-0.35965079124462002,-0.36094599184782999,-0.36224119245102998,-0.36304724711468001,-0.36307354560409,-0.36309984409349,-0.36312614258289999,-0.36315244107229999,-0.36216162610299002,-0.36082040314331998,-0.35947918018364999,-0.35813795722399,-0.35688998656094001,-0.35646263610809997,-0.35603528565526998,-0.35560793520243,-0.35518058474960001,-0.35554010179722001,-0.35682215315572002,-0.35810420451422997,-0.35938625587272999,-0.36066830723123999,-0.36157900424020001,-0.36240740665645998,-0.36323580907273001,-0.36406421148898999,-0.36455189640135999,-0.3634539344687,-0.36235597253603002,-0.36125801060335999,-0.36016004867069001,-0.35900579246592002,-0.35780263657563,-0.35659948068533998,-0.35539632479505001,-0.35419316890475999,-0.35478156033410002,-0.35558366426096,-0.35638576818781997,-0.35718787211468001,-0.35816869842872001,-0.35968086156952001,-0.36119302471032,-0.36270518785111999,-0.36421735099191999,-0.36456249630270998,-0.36416144433927999,-0.36376039237585001,-0.36335934041242002,-0.36295828844898997,-0.36127768974509,-0.35955513868904998,-0.35783258763301001,-0.35611003657696,-0.35491774893994998,-0.35481912960467998,-0.35472051026940998,-0.35462189093413998,-0.35452327159886998,-0.35573933819880998,-0.35756050859012001,-0.35938167898144002,-0.36120284937274999,-0.36297359941759,-0.36362448703036998,-0.36427537464315002,-0.36492626225593,-0.36557714986870998,-0.36525696128766999,-0.36348838787517002,-0.36171981446266999,-0.35995124105016002,-0.35818266763765999,-0.35681863476372,-0.35558260576167,-0.35434657675962999,-0.35311054775758,-0.35220244481730001,-0.35374748106985998,-0.35529251732242001,-0.35683755357496999,-0.35838258982753002,-0.36005598775455999,-0.36187058352353002,-0.36368517929249,-0.36549977506144998,-0.36731437083041002,-0.36666561512465001,-0.36552820545787001,-0.36439079579110001,-0.36325338612432001,-0.36188280844490001,-0.35953566826548999,-0.35718852808606999,-0.35484138790664999,-0.35249424772723997,-0.35173749527700998,-0.35227661430981,-0.35281573334262001,-0.35335485237543002,-0.35389397140822998,-0.35647766381633,-0.35926530369329002,-0.36205294357023998,-0.36484058344719,-0.36695093286288,-0.36720734313457998,-0.36746375340628001,-0.36772016367797999,-0.36797657394967997,-0.36614270156688999,-0.36305920368413003,-0.35997570580136001,-0.35689220791859999,-0.35380871003584002,-0.35253041560439002,-0.35128123735764,-0.35003205911089003,-0.34878288086414999,-0.34904874308724998,-0.35222428568294001,-0.35539982827861999,-0.35857537087430003,-0.36175091346998001,-0.36441971816606999,-0.36687205230309999,-0.36932438644013998,-0.37177672057717998,-0.37390810580270001,-0.37091665263285001,-0.36792519946301,-0.36493374629316999,-0.36194229312331999,-0.35856405536780001,-0.35464558044641997,-0.35072710552503999,-0.34680863060367001,-0.34289015568228998,-0.34389191344707998,-0.34631794909470998,-0.34874398474233997,-0.35117002038998002,-0.35404025302844,-0.35978647296347999,-0.36553269289851997,-0.37127891283357001,-0.37702513276860999,-0.37931946725104998,-0.37805056513724,-0.37678166302344002,-0.37551276090963998,-0.37424385879583999,-0.36703207950563999,-0.35877435383239997,-0.35051662815916002,-0.34225890248592,-0.33551128258865998,-0.33449221612420998,-0.33347314965975,-0.33245408319530001,-0.33143501673085002,-0.33816833943347002,-0.35082448745972999,-0.36348063548600001,-0.37613678351226998,-0.38879293153853001,-0.39588954312426999,-0.40253648632145,-0.40918342951862002,-0.41583037271578999,-0.41271042369549998,-0.38489977114946999,-0.35708911860345,-0.32927846605742001,-0.30146781351139001,-0.25120317079873,-0.18840237809905,-0.12560158539937,-0.062800792699679003,0.0};

class mydspSIG0 {
	
  private:
	
	int fmydspSIG0Wave0_idx;
	
  public:
	
	int getNumInputsmydspSIG0() {
		return 0;
		
	}
	int getNumOutputsmydspSIG0() {
		return 1;
		
	}
	int getInputRatemydspSIG0(int channel) {
		int rate;
		switch (channel) {
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	int getOutputRatemydspSIG0(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 0;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	
	void instanceInitmydspSIG0(int samplingFreq) {
		fmydspSIG0Wave0_idx = 0;
		
	}
	
	void fillmydspSIG0(int count, double* output) {
		for (int i = 0; (i < count); i = (i + 1)) {
			output[i] = fmydspSIG0Wave0[fmydspSIG0Wave0_idx];
			fmydspSIG0Wave0_idx = ((1 + fmydspSIG0Wave0_idx) % 12288);
			
		}
		
	}
};

mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }

static double ftbl0mydspSIG0[12288];
double mydsp_faustpower2_f(double value) {
	return (value * value);
	
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif
#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class mydsp : public dsp {
	
 private:
	
	int iVec0[2];
	int fSamplingFreq;
	double fConst0;
	double fConst1;
	FAUSTFLOAT fButton0;
	FAUSTFLOAT fVslider0;
	double fRec1[2];
	int iRec2[2];
	FAUSTFLOAT fVslider1;
	double fRec3[2];
	FAUSTFLOAT fVslider2;
	double fRec4[2];
	FAUSTFLOAT fVslider3;
	double fRec5[2];
	double fRec0[2];
	FAUSTFLOAT fVslider4;
	double fRec6[2];
	FAUSTFLOAT fVslider5;
	double fRec7[2];
	FAUSTFLOAT fVslider6;
	double fRec9[2];
	FAUSTFLOAT fVslider7;
	double fConst2;
	FAUSTFLOAT fVslider8;
	double fConst3;
	FAUSTFLOAT fVslider9;
	double fRec14[2];
	FAUSTFLOAT fVslider10;
	double fRec15[2];
	double fRec16[2];
	double fRec13[2];
	double fRec12[2];
	double fRec17[2];
	double fConst4;
	double fRec21[2];
	double fRec22[2];
	int iRec23[2];
	double fRec20[2];
	double fRec19[2];
	double fRec11[2];
	FAUSTFLOAT fVslider11;
	double fRec24[2];
	FAUSTFLOAT fVslider12;
	FAUSTFLOAT fVslider13;
	double fRec28[2];
	double fRec29[2];
	double fRec27[2];
	double fRec26[2];
	double fRec30[2];
	double fRec34[2];
	double fRec35[2];
	double fRec33[2];
	double fRec32[2];
	double fRec25[2];
	FAUSTFLOAT fVslider14;
	double fRec36[2];
	FAUSTFLOAT fVslider15;
	FAUSTFLOAT fVslider16;
	FAUSTFLOAT fVslider17;
	double fConst5;
	FAUSTFLOAT fVslider18;
	double fRec37[2];
	double fRec10[2];
	double fConst6;
	double fRec40[2];
	double fRec39[2];
	double fRec38[2];
	FAUSTFLOAT fVslider19;
	double fRec41[2];
	FAUSTFLOAT fVslider20;
	FAUSTFLOAT fVslider21;
	double fRec43[2];
	FAUSTFLOAT fVslider22;
	double fRec44[2];
	FAUSTFLOAT fVslider23;
	double fRec42[2];
	double fRec47[2];
	double fRec46[2];
	double fRec45[2];
	FAUSTFLOAT fVslider24;
	double fRec48[2];
	FAUSTFLOAT fVslider25;
	FAUSTFLOAT fVslider26;
	double fRec50[2];
	FAUSTFLOAT fVslider27;
	double fRec51[2];
	FAUSTFLOAT fVslider28;
	double fRec49[2];
	double fRec54[2];
	double fRec53[2];
	double fRec52[2];
	FAUSTFLOAT fVslider29;
	double fRec58[2];
	FAUSTFLOAT fVslider30;
	double fRec59[2];
	FAUSTFLOAT fVslider31;
	double fRec60[2];
	double fRec57[2];
	double fRec56[2];
	double fRec55[2];
	FAUSTFLOAT fCheckbox0;
	double fRec61[2];
	FAUSTFLOAT fVslider32;
	double fRec62[2];
	FAUSTFLOAT fVslider33;
	double fRec64[2];
	FAUSTFLOAT fVslider34;
	double fRec65[2];
	FAUSTFLOAT fVslider35;
	double fRec66[2];
	FAUSTFLOAT fVslider36;
	double fRec67[2];
	double fRec63[2];
	FAUSTFLOAT fVslider37;
	double fRec68[2];
	double fRec71[2];
	double fRec70[2];
	double fRec69[2];
	double fVec1[2];
	double fRec8[2];
	FAUSTFLOAT fVslider38;
	double fRec72[2];
	double fConst7;
	double fConst8;
	double fConst9;
	double fConst10;
	FAUSTFLOAT fCheckbox1;
	double fRec73[2];
	FAUSTFLOAT fVslider39;
	double fRec74[2];
	FAUSTFLOAT fVslider40;
	double fRec75[2];
	FAUSTFLOAT fVslider41;
	double fRec76[2];
	FAUSTFLOAT fVslider42;
	double fRec78[2];
	FAUSTFLOAT fVslider43;
	double fRec79[2];
	FAUSTFLOAT fVslider44;
	double fRec80[2];
	FAUSTFLOAT fVslider45;
	double fRec81[2];
	double fRec77[2];
	FAUSTFLOAT fVslider46;
	double fRec82[2];
	double fRec85[2];
	double fRec83[2];
	double fRec88[2];
	double fRec86[2];
	FAUSTFLOAT fVslider47;
	double fRec89[2];
	FAUSTFLOAT fVslider48;
	double fRec90[2];
	double fConst11;
	double fConst12;
	double fConst13;
	double fConst14;
	double fRec93[2];
	double fRec92[2];
	double fRec91[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "0.0");
		m->declare("author", "Sébastien Clara");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.0");
		m->declare("compressors.lib/name", "Faust Compressor Effect Library");
		m->declare("compressors.lib/version", "0.0");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.0");
		m->declare("filename", "wavesMoogMono");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "0.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.1");
		m->declare("misceffects.lib/name", "Faust Math Library");
		m->declare("misceffects.lib/version", "2.0");
		m->declare("name", "wavesMoog");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.0");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.0");
		m->declare("vaeffects.lib/name", "Faust Virtual Analog Filter Effect Library");
		m->declare("vaeffects.lib/version", "0.0");
	}

	virtual int getNumInputs() {
		return 0;
		
	}
	virtual int getNumOutputs() {
		return 2;
		
	}
	virtual int getInputRate(int channel) {
		int rate;
		switch (channel) {
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	virtual int getOutputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	
	static void classInit(int samplingFreq) {
		mydspSIG0* sig0 = newmydspSIG0();
		sig0->instanceInitmydspSIG0(samplingFreq);
		sig0->fillmydspSIG0(12288, ftbl0mydspSIG0);
		deletemydspSIG0(sig0);
		
	}
	
	virtual void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = std::min(192000.0, std::max(1.0, double(fSamplingFreq)));
		fConst1 = (6.9100000000000001 / fConst0);
		fConst2 = (1.0 / fConst0);
		fConst3 = (0.10471975511965977 / fConst0);
		fConst4 = (0.016666666666666666 / fConst0);
		fConst5 = (1.0 / fConst0);
		fConst6 = (6.2831853071795862 / fConst0);
		fConst7 = (3.1415926535897931 / fConst0);
		fConst8 = (0.15873015873015872 * fConst0);
		fConst9 = std::min(20.0, fConst8);
		fConst10 = std::max(20.0, fConst8);
		fConst11 = std::exp((0.0 - (2500.0 / fConst0)));
		fConst12 = (1.0 - fConst11);
		fConst13 = std::exp((0.0 - (1250.0 / fConst0)));
		fConst14 = std::exp((0.0 - (2.0 / fConst0)));
		
	}
	
	virtual void instanceResetUserInterface() {
		fButton0 = FAUSTFLOAT(0.0);
		fVslider0 = FAUSTFLOAT(0.10000000000000001);
		fVslider1 = FAUSTFLOAT(0.01);
		fVslider2 = FAUSTFLOAT(0.059999999999999998);
		fVslider3 = FAUSTFLOAT(0.90000000000000002);
		fVslider4 = FAUSTFLOAT(1.0);
		fVslider5 = FAUSTFLOAT(1.0);
		fVslider6 = FAUSTFLOAT(0.0);
		fVslider7 = FAUSTFLOAT(0.0);
		fVslider8 = FAUSTFLOAT(0.0);
		fVslider9 = FAUSTFLOAT(1.0);
		fVslider10 = FAUSTFLOAT(120.0);
		fVslider11 = FAUSTFLOAT(0.0);
		fVslider12 = FAUSTFLOAT(0.0);
		fVslider13 = FAUSTFLOAT(1.0);
		fVslider14 = FAUSTFLOAT(0.0);
		fVslider15 = FAUSTFLOAT(1.0);
		fVslider16 = FAUSTFLOAT(0.0);
		fVslider17 = FAUSTFLOAT(440.0);
		fVslider18 = FAUSTFLOAT(0.0);
		fVslider19 = FAUSTFLOAT(0.0);
		fVslider20 = FAUSTFLOAT(0.0);
		fVslider21 = FAUSTFLOAT(0.0);
		fVslider22 = FAUSTFLOAT(0.0);
		fVslider23 = FAUSTFLOAT(0.0);
		fVslider24 = FAUSTFLOAT(0.0);
		fVslider25 = FAUSTFLOAT(0.0);
		fVslider26 = FAUSTFLOAT(0.0);
		fVslider27 = FAUSTFLOAT(0.0);
		fVslider28 = FAUSTFLOAT(0.0);
		fVslider29 = FAUSTFLOAT(0.0);
		fVslider30 = FAUSTFLOAT(0.0);
		fVslider31 = FAUSTFLOAT(1.0);
		fCheckbox0 = FAUSTFLOAT(0.0);
		fVslider32 = FAUSTFLOAT(0.0);
		fVslider33 = FAUSTFLOAT(0.10000000000000001);
		fVslider34 = FAUSTFLOAT(0.0);
		fVslider35 = FAUSTFLOAT(0.0);
		fVslider36 = FAUSTFLOAT(0.0);
		fVslider37 = FAUSTFLOAT(1.0);
		fVslider38 = FAUSTFLOAT(0.10000000000000001);
		fCheckbox1 = FAUSTFLOAT(0.0);
		fVslider39 = FAUSTFLOAT(0.0);
		fVslider40 = FAUSTFLOAT(0.0);
		fVslider41 = FAUSTFLOAT(2.0);
		fVslider42 = FAUSTFLOAT(0.10000000000000001);
		fVslider43 = FAUSTFLOAT(0.0);
		fVslider44 = FAUSTFLOAT(0.0);
		fVslider45 = FAUSTFLOAT(0.0);
		fVslider46 = FAUSTFLOAT(1.0);
		fVslider47 = FAUSTFLOAT(0.0);
		fVslider48 = FAUSTFLOAT(0.0);
		
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iVec0[l0] = 0;
			
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec1[l1] = 0.0;
			
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iRec2[l2] = 0;
			
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec3[l3] = 0.0;
			
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec4[l4] = 0.0;
			
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec5[l5] = 0.0;
			
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec0[l6] = 0.0;
			
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec6[l7] = 0.0;
			
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec7[l8] = 0.0;
			
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec9[l9] = 0.0;
			
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec14[l10] = 0.0;
			
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec15[l11] = 0.0;
			
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec16[l12] = 0.0;
			
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec13[l13] = 0.0;
			
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec12[l14] = 0.0;
			
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec17[l15] = 0.0;
			
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec21[l16] = 0.0;
			
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec22[l17] = 0.0;
			
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			iRec23[l18] = 0;
			
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec20[l19] = 0.0;
			
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec19[l20] = 0.0;
			
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec11[l21] = 0.0;
			
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec24[l22] = 0.0;
			
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec28[l23] = 0.0;
			
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec29[l24] = 0.0;
			
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec27[l25] = 0.0;
			
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec26[l26] = 0.0;
			
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec30[l27] = 0.0;
			
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec34[l28] = 0.0;
			
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec35[l29] = 0.0;
			
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec33[l30] = 0.0;
			
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec32[l31] = 0.0;
			
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec25[l32] = 0.0;
			
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec36[l33] = 0.0;
			
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec37[l34] = 0.0;
			
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec10[l35] = 0.0;
			
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec40[l36] = 0.0;
			
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec39[l37] = 0.0;
			
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec38[l38] = 0.0;
			
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec41[l39] = 0.0;
			
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec43[l40] = 0.0;
			
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec44[l41] = 0.0;
			
		}
		for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
			fRec42[l42] = 0.0;
			
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec47[l43] = 0.0;
			
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec46[l44] = 0.0;
			
		}
		for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) {
			fRec45[l45] = 0.0;
			
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fRec48[l46] = 0.0;
			
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fRec50[l47] = 0.0;
			
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec51[l48] = 0.0;
			
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fRec49[l49] = 0.0;
			
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fRec54[l50] = 0.0;
			
		}
		for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
			fRec53[l51] = 0.0;
			
		}
		for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) {
			fRec52[l52] = 0.0;
			
		}
		for (int l53 = 0; (l53 < 2); l53 = (l53 + 1)) {
			fRec58[l53] = 0.0;
			
		}
		for (int l54 = 0; (l54 < 2); l54 = (l54 + 1)) {
			fRec59[l54] = 0.0;
			
		}
		for (int l55 = 0; (l55 < 2); l55 = (l55 + 1)) {
			fRec60[l55] = 0.0;
			
		}
		for (int l56 = 0; (l56 < 2); l56 = (l56 + 1)) {
			fRec57[l56] = 0.0;
			
		}
		for (int l57 = 0; (l57 < 2); l57 = (l57 + 1)) {
			fRec56[l57] = 0.0;
			
		}
		for (int l58 = 0; (l58 < 2); l58 = (l58 + 1)) {
			fRec55[l58] = 0.0;
			
		}
		for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) {
			fRec61[l59] = 0.0;
			
		}
		for (int l60 = 0; (l60 < 2); l60 = (l60 + 1)) {
			fRec62[l60] = 0.0;
			
		}
		for (int l61 = 0; (l61 < 2); l61 = (l61 + 1)) {
			fRec64[l61] = 0.0;
			
		}
		for (int l62 = 0; (l62 < 2); l62 = (l62 + 1)) {
			fRec65[l62] = 0.0;
			
		}
		for (int l63 = 0; (l63 < 2); l63 = (l63 + 1)) {
			fRec66[l63] = 0.0;
			
		}
		for (int l64 = 0; (l64 < 2); l64 = (l64 + 1)) {
			fRec67[l64] = 0.0;
			
		}
		for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) {
			fRec63[l65] = 0.0;
			
		}
		for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) {
			fRec68[l66] = 0.0;
			
		}
		for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) {
			fRec71[l67] = 0.0;
			
		}
		for (int l68 = 0; (l68 < 2); l68 = (l68 + 1)) {
			fRec70[l68] = 0.0;
			
		}
		for (int l69 = 0; (l69 < 2); l69 = (l69 + 1)) {
			fRec69[l69] = 0.0;
			
		}
		for (int l70 = 0; (l70 < 2); l70 = (l70 + 1)) {
			fVec1[l70] = 0.0;
			
		}
		for (int l71 = 0; (l71 < 2); l71 = (l71 + 1)) {
			fRec8[l71] = 0.0;
			
		}
		for (int l72 = 0; (l72 < 2); l72 = (l72 + 1)) {
			fRec72[l72] = 0.0;
			
		}
		for (int l73 = 0; (l73 < 2); l73 = (l73 + 1)) {
			fRec73[l73] = 0.0;
			
		}
		for (int l74 = 0; (l74 < 2); l74 = (l74 + 1)) {
			fRec74[l74] = 0.0;
			
		}
		for (int l75 = 0; (l75 < 2); l75 = (l75 + 1)) {
			fRec75[l75] = 0.0;
			
		}
		for (int l76 = 0; (l76 < 2); l76 = (l76 + 1)) {
			fRec76[l76] = 0.0;
			
		}
		for (int l77 = 0; (l77 < 2); l77 = (l77 + 1)) {
			fRec78[l77] = 0.0;
			
		}
		for (int l78 = 0; (l78 < 2); l78 = (l78 + 1)) {
			fRec79[l78] = 0.0;
			
		}
		for (int l79 = 0; (l79 < 2); l79 = (l79 + 1)) {
			fRec80[l79] = 0.0;
			
		}
		for (int l80 = 0; (l80 < 2); l80 = (l80 + 1)) {
			fRec81[l80] = 0.0;
			
		}
		for (int l81 = 0; (l81 < 2); l81 = (l81 + 1)) {
			fRec77[l81] = 0.0;
			
		}
		for (int l82 = 0; (l82 < 2); l82 = (l82 + 1)) {
			fRec82[l82] = 0.0;
			
		}
		for (int l83 = 0; (l83 < 2); l83 = (l83 + 1)) {
			fRec85[l83] = 0.0;
			
		}
		for (int l84 = 0; (l84 < 2); l84 = (l84 + 1)) {
			fRec83[l84] = 0.0;
			
		}
		for (int l85 = 0; (l85 < 2); l85 = (l85 + 1)) {
			fRec88[l85] = 0.0;
			
		}
		for (int l86 = 0; (l86 < 2); l86 = (l86 + 1)) {
			fRec86[l86] = 0.0;
			
		}
		for (int l87 = 0; (l87 < 2); l87 = (l87 + 1)) {
			fRec89[l87] = 0.0;
			
		}
		for (int l88 = 0; (l88 < 2); l88 = (l88 + 1)) {
			fRec90[l88] = 0.0;
			
		}
		for (int l89 = 0; (l89 < 2); l89 = (l89 + 1)) {
			fRec93[l89] = 0.0;
			
		}
		for (int l90 = 0; (l90 < 2); l90 = (l90 + 1)) {
			fRec92[l90] = 0.0;
			
		}
		for (int l91 = 0; (l91 < 2); l91 = (l91 + 1)) {
			fRec91[l91] = 0.0;
			
		}
		
	}
	
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void instanceInit(int samplingFreq) {
		instanceConstants(samplingFreq);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual mydsp* clone() {
		return new mydsp();
	}
	virtual int getSampleRate() {
		return fSamplingFreq;
		
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openHorizontalBox("wavesMoog");
		ui_interface->declare(0, "1", "");
		ui_interface->openVerticalBox("0x00");
		ui_interface->declare(0, "4", "");
		ui_interface->openHorizontalBox("osc1");
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("lfo freq");
		ui_interface->declare(&fVslider16, "3", "");
		ui_interface->declare(&fVslider16, "style", "knob");
		ui_interface->declare(&fVslider16, "tooltip", "semitone");
		ui_interface->addVerticalSlider("tuning wav", &fVslider16, 0.0, -12.0, 12.0, 0.01);
		ui_interface->declare(&fVslider11, "9", "");
		ui_interface->declare(&fVslider11, "style", "knob");
		ui_interface->declare(&fVslider11, "tooltip", "amp lfo1");
		ui_interface->addVerticalSlider("lfo1", &fVslider11, 0.0, 0.0, 500.0, 0.10000000000000001);
		ui_interface->declare(&fVslider14, "9", "");
		ui_interface->declare(&fVslider14, "style", "knob");
		ui_interface->declare(&fVslider14, "tooltip", "amp lfo2");
		ui_interface->addVerticalSlider("lfo2", &fVslider14, 0.0, 0.0, 500.0, 0.10000000000000001);
		ui_interface->closeBox();
		ui_interface->declare(&fVslider7, "2", "");
		ui_interface->declare(&fVslider7, "style", "knob");
		ui_interface->addVerticalSlider("form wav", &fVslider7, 0.0, 0.0, 5.0, 1.0);
		ui_interface->declare(&fVslider6, "3", "");
		ui_interface->declare(&fVslider6, "style", "knob");
		ui_interface->addVerticalSlider("amp wav", &fVslider6, 0.0, 0.0, 1.0, 0.01);
		ui_interface->closeBox();
		ui_interface->declare(0, "5", "");
		ui_interface->openHorizontalBox("osc2");
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("lfo freq");
		ui_interface->declare(&fVslider23, "3", "");
		ui_interface->declare(&fVslider23, "style", "knob");
		ui_interface->declare(&fVslider23, "tooltip", "semitone");
		ui_interface->addVerticalSlider("tuning wav", &fVslider23, 0.0, -12.0, 12.0, 0.01);
		ui_interface->declare(&fVslider21, "9", "");
		ui_interface->declare(&fVslider21, "style", "knob");
		ui_interface->declare(&fVslider21, "tooltip", "amp lfo1");
		ui_interface->addVerticalSlider("lfo1", &fVslider21, 0.0, 0.0, 500.0, 0.10000000000000001);
		ui_interface->declare(&fVslider22, "9", "");
		ui_interface->declare(&fVslider22, "style", "knob");
		ui_interface->declare(&fVslider22, "tooltip", "amp lfo2");
		ui_interface->addVerticalSlider("lfo2", &fVslider22, 0.0, 0.0, 500.0, 0.10000000000000001);
		ui_interface->closeBox();
		ui_interface->declare(&fVslider20, "2", "");
		ui_interface->declare(&fVslider20, "style", "knob");
		ui_interface->addVerticalSlider("form wav", &fVslider20, 0.0, 0.0, 5.0, 1.0);
		ui_interface->declare(&fVslider19, "3", "");
		ui_interface->declare(&fVslider19, "style", "knob");
		ui_interface->addVerticalSlider("amp wav", &fVslider19, 0.0, 0.0, 1.0, 0.01);
		ui_interface->closeBox();
		ui_interface->declare(0, "6", "");
		ui_interface->openHorizontalBox("osc3");
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("lfo freq");
		ui_interface->declare(&fVslider28, "3", "");
		ui_interface->declare(&fVslider28, "style", "knob");
		ui_interface->declare(&fVslider28, "tooltip", "semitone");
		ui_interface->addVerticalSlider("tuning wav", &fVslider28, 0.0, -12.0, 12.0, 0.01);
		ui_interface->declare(&fVslider26, "9", "");
		ui_interface->declare(&fVslider26, "style", "knob");
		ui_interface->declare(&fVslider26, "tooltip", "amp lfo1");
		ui_interface->addVerticalSlider("lfo1", &fVslider26, 0.0, 0.0, 500.0, 0.10000000000000001);
		ui_interface->declare(&fVslider27, "9", "");
		ui_interface->declare(&fVslider27, "style", "knob");
		ui_interface->declare(&fVslider27, "tooltip", "amp lfo2");
		ui_interface->addVerticalSlider("lfo2", &fVslider27, 0.0, 0.0, 500.0, 0.10000000000000001);
		ui_interface->closeBox();
		ui_interface->declare(&fVslider25, "2", "");
		ui_interface->declare(&fVslider25, "style", "knob");
		ui_interface->addVerticalSlider("form wav", &fVslider25, 0.0, 0.0, 5.0, 1.0);
		ui_interface->declare(&fVslider24, "3", "");
		ui_interface->declare(&fVslider24, "style", "knob");
		ui_interface->addVerticalSlider("amp wav", &fVslider24, 0.0, 0.0, 1.0, 0.01);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openVerticalBox("0x00");
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("0x00");
		ui_interface->declare(&fButton0, "1", "");
		ui_interface->addButton("gate", &fButton0);
		ui_interface->declare(&fVslider17, "2", "");
		ui_interface->declare(&fVslider17, "style", "knob");
		ui_interface->declare(&fVslider17, "unit", "Hz");
		ui_interface->addVerticalSlider("freq", &fVslider17, 440.0, 20.0, 4000.0, 1.0);
		ui_interface->declare(&fVslider18, "2", "");
		ui_interface->declare(&fVslider18, "style", "knob");
		ui_interface->addVerticalSlider("portamento", &fVslider18, 0.0, 0.0, 5.0, 0.050000000000000003);
		ui_interface->declare(0, "5", "");
		ui_interface->openHorizontalBox("env");
		ui_interface->declare(&fVslider1, "1", "");
		ui_interface->declare(&fVslider1, "style", "knob");
		ui_interface->declare(&fVslider1, "tooltip", "sec");
		ui_interface->addVerticalSlider("A", &fVslider1, 0.01, 0.0, 15.0, 0.01);
		ui_interface->declare(&fVslider2, "2", "");
		ui_interface->declare(&fVslider2, "style", "knob");
		ui_interface->declare(&fVslider2, "tooltip", "sec");
		ui_interface->addVerticalSlider("D", &fVslider2, 0.059999999999999998, 0.0, 15.0, 0.01);
		ui_interface->declare(&fVslider3, "3", "");
		ui_interface->declare(&fVslider3, "style", "knob");
		ui_interface->declare(&fVslider3, "tooltip", "percentage of max");
		ui_interface->addVerticalSlider("S", &fVslider3, 0.90000000000000002, 0.0, 1.0, 0.01);
		ui_interface->declare(&fVslider0, "4", "");
		ui_interface->declare(&fVslider0, "style", "knob");
		ui_interface->declare(&fVslider0, "tooltip", "sec");
		ui_interface->addVerticalSlider("R", &fVslider0, 0.10000000000000001, 0.01, 10.0, 0.01);
		ui_interface->closeBox();
		ui_interface->declare(&fVslider15, "9", "");
		ui_interface->declare(&fVslider15, "hide", "1");
		ui_interface->declare(&fVslider15, "midi", "pitchwheel");
		ui_interface->declare(&fVslider15, "style", "knob");
		ui_interface->addVerticalSlider("bend", &fVslider15, 1.0, 0.90000000000000002, 1.1000000000000001, 0.01);
		ui_interface->declare(&fVslider4, "9", "");
		ui_interface->declare(&fVslider4, "style", "knob");
		ui_interface->addVerticalSlider("gain", &fVslider4, 1.0, 0.0, 3.0, 0.01);
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("0x00");
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("lfo1");
		ui_interface->declare(&fVslider8, "1", "");
		ui_interface->declare(&fVslider8, "style", "knob");
		ui_interface->declare(&fVslider8, "tooltip", "0=sin\n1=saw\n2=randSmooth\n3=rand");
		ui_interface->addVerticalSlider("form", &fVslider8, 0.0, 0.0, 3.0, 1.0);
		ui_interface->closeBox();
		ui_interface->declare(&fVslider9, "1", "");
		ui_interface->declare(&fVslider9, "style", "knob");
		ui_interface->declare(&fVslider9, "tooltip", "modulation coef");
		ui_interface->addVerticalSlider("rate lfo1", &fVslider9, 1.0, 0.0, 10.0, 0.01);
		ui_interface->declare(&fVslider10, "2", "");
		ui_interface->declare(&fVslider10, "style", "knob");
		ui_interface->declare(&fVslider10, "tooltip", "global lfo rate");
		ui_interface->addVerticalSlider("bpm", &fVslider10, 120.0, 1.0, 1000.0, 1.0);
		ui_interface->declare(0, "3", "");
		ui_interface->openHorizontalBox("lfo2");
		ui_interface->declare(&fVslider12, "1", "");
		ui_interface->declare(&fVslider12, "style", "knob");
		ui_interface->declare(&fVslider12, "tooltip", "0=sin\n1=saw\n2=randSmooth\n3=rand");
		ui_interface->addVerticalSlider("form", &fVslider12, 0.0, 0.0, 3.0, 1.0);
		ui_interface->closeBox();
		ui_interface->declare(&fVslider13, "3", "");
		ui_interface->declare(&fVslider13, "style", "knob");
		ui_interface->declare(&fVslider13, "tooltip", "modulation coef");
		ui_interface->addVerticalSlider("rate lfo2", &fVslider13, 1.0, 0.0, 10.0, 0.01);
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openTabBox("FX");
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("tremolo");
		ui_interface->declare(&fVslider47, "9", "");
		ui_interface->declare(&fVslider47, "style", "knob");
		ui_interface->declare(&fVslider47, "tooltip", "amp lfo1");
		ui_interface->addVerticalSlider("lfo1", &fVslider47, 0.0, 0.0, 1.0, 0.10000000000000001);
		ui_interface->declare(&fVslider48, "9", "");
		ui_interface->declare(&fVslider48, "style", "knob");
		ui_interface->declare(&fVslider48, "tooltip", "amp lfo2");
		ui_interface->addVerticalSlider("lfo2", &fVslider48, 0.0, 0.0, 1.0, 0.10000000000000001);
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("modulator");
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("lfo freq");
		ui_interface->declare(&fVslider31, "1", "");
		ui_interface->declare(&fVslider31, "style", "knob");
		ui_interface->addVerticalSlider("coef FM", &fVslider31, 1.0, 0.01, 10.0, 0.01);
		ui_interface->declare(&fVslider29, "9", "");
		ui_interface->declare(&fVslider29, "style", "knob");
		ui_interface->declare(&fVslider29, "tooltip", "amp lfo1");
		ui_interface->addVerticalSlider("lfo1", &fVslider29, 0.0, 0.0, 1000.0, 0.10000000000000001);
		ui_interface->declare(&fVslider30, "9", "");
		ui_interface->declare(&fVslider30, "style", "knob");
		ui_interface->declare(&fVslider30, "tooltip", "amp lfo2");
		ui_interface->addVerticalSlider("lfo2", &fVslider30, 0.0, 0.0, 1000.0, 0.10000000000000001);
		ui_interface->closeBox();
		ui_interface->declare(&fVslider32, "2", "");
		ui_interface->declare(&fVslider32, "style", "knob");
		ui_interface->addVerticalSlider("index FM", &fVslider32, 0.0, 0.0, 15.0, 0.01);
		ui_interface->declare(0, "5", "");
		ui_interface->openHorizontalBox("env");
		ui_interface->declare(&fVslider34, "1", "");
		ui_interface->declare(&fVslider34, "style", "knob");
		ui_interface->declare(&fVslider34, "tooltip", "sec");
		ui_interface->addVerticalSlider("A", &fVslider34, 0.0, 0.0, 15.0, 0.01);
		ui_interface->declare(&fVslider35, "2", "");
		ui_interface->declare(&fVslider35, "style", "knob");
		ui_interface->declare(&fVslider35, "tooltip", "sec");
		ui_interface->addVerticalSlider("D", &fVslider35, 0.0, 0.0, 15.0, 0.01);
		ui_interface->declare(&fVslider36, "3", "");
		ui_interface->declare(&fVslider36, "style", "knob");
		ui_interface->declare(&fVslider36, "tooltip", "percentage of max");
		ui_interface->addVerticalSlider("S", &fVslider36, 0.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fVslider33, "4", "");
		ui_interface->declare(&fVslider33, "style", "knob");
		ui_interface->declare(&fVslider33, "tooltip", "sec");
		ui_interface->addVerticalSlider("R", &fVslider33, 0.10000000000000001, 0.01, 10.0, 0.01);
		ui_interface->closeBox();
		ui_interface->declare(&fVslider37, "5", "");
		ui_interface->declare(&fVslider37, "style", "knob");
		ui_interface->addVerticalSlider("envDepth", &fVslider37, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fCheckbox0, "5", "");
		ui_interface->addCheckButton("invEnv LPF", &fCheckbox0);
		ui_interface->closeBox();
		ui_interface->declare(0, "3", "");
		ui_interface->openHorizontalBox("filter");
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("lfo cutOff");
		ui_interface->declare(&fVslider41, "1", "");
		ui_interface->declare(&fVslider41, "style", "knob");
		ui_interface->declare(&fVslider41, "tooltip", "pitchTracker * coef = cutOff");
		ui_interface->addVerticalSlider("coef cutOff", &fVslider41, 2.0, 0.01, 5.0, 0.01);
		ui_interface->declare(&fVslider39, "9", "");
		ui_interface->declare(&fVslider39, "style", "knob");
		ui_interface->declare(&fVslider39, "tooltip", "amp lfo1");
		ui_interface->addVerticalSlider("lfo1", &fVslider39, 0.0, 0.0, 1000.0, 0.10000000000000001);
		ui_interface->declare(&fVslider40, "9", "");
		ui_interface->declare(&fVslider40, "style", "knob");
		ui_interface->declare(&fVslider40, "tooltip", "amp lfo2");
		ui_interface->addVerticalSlider("lfo2", &fVslider40, 0.0, 0.0, 1000.0, 0.10000000000000001);
		ui_interface->closeBox();
		ui_interface->declare(0, "5", "");
		ui_interface->openHorizontalBox("env");
		ui_interface->declare(&fVslider43, "1", "");
		ui_interface->declare(&fVslider43, "style", "knob");
		ui_interface->declare(&fVslider43, "tooltip", "sec");
		ui_interface->addVerticalSlider("A", &fVslider43, 0.0, 0.0, 15.0, 0.01);
		ui_interface->declare(&fVslider44, "2", "");
		ui_interface->declare(&fVslider44, "style", "knob");
		ui_interface->declare(&fVslider44, "tooltip", "sec");
		ui_interface->addVerticalSlider("D", &fVslider44, 0.0, 0.0, 15.0, 0.01);
		ui_interface->declare(&fVslider45, "3", "");
		ui_interface->declare(&fVslider45, "style", "knob");
		ui_interface->declare(&fVslider45, "tooltip", "percentage of max");
		ui_interface->addVerticalSlider("S", &fVslider45, 0.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fVslider42, "4", "");
		ui_interface->declare(&fVslider42, "style", "knob");
		ui_interface->declare(&fVslider42, "tooltip", "sec");
		ui_interface->addVerticalSlider("R", &fVslider42, 0.10000000000000001, 0.01, 10.0, 0.01);
		ui_interface->closeBox();
		ui_interface->declare(&fVslider46, "5", "");
		ui_interface->declare(&fVslider46, "style", "knob");
		ui_interface->addVerticalSlider("envDepth", &fVslider46, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fCheckbox1, "5", "");
		ui_interface->addCheckButton("invEnv LPF", &fCheckbox1);
		ui_interface->declare(&fVslider38, "8", "");
		ui_interface->declare(&fVslider38, "style", "knob");
		ui_interface->addVerticalSlider("resonance", &fVslider38, 0.10000000000000001, 0.0, 0.98999999999999999, 0.01);
		ui_interface->declare(&fVslider5, "9", "");
		ui_interface->declare(&fVslider5, "style", "knob");
		ui_interface->addVerticalSlider("dry/wet LPF", &fVslider5, 1.0, 0.0, 1.0, 0.01);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->closeBox();
		
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		int iSlow0 = (double(fButton0) > 0.0);
		double fSlow1 = (0.0010000000000000009 * double(fVslider0));
		double fSlow2 = (0.0010000000000000009 * double(fVslider1));
		double fSlow3 = (0.0010000000000000009 * double(fVslider2));
		double fSlow4 = double(iSlow0);
		double fSlow5 = (0.0010000000000000009 * double(fVslider3));
		double fSlow6 = (0.0010000000000000009 * double(fVslider4));
		double fSlow7 = (0.0010000000000000009 * double(fVslider5));
		double fSlow8 = (0.0010000000000000009 * double(fVslider6));
		double fSlow9 = double(fVslider7);
		double fSlow10 = double(fVslider8);
		int iSlow11 = (fSlow10 >= 2.0);
		int iSlow12 = (fSlow10 >= 1.0);
		double fSlow13 = (0.0010000000000000009 * double(fVslider9));
		double fSlow14 = (0.0010000000000000009 * double(fVslider10));
		int iSlow15 = (fSlow10 >= 3.0);
		double fSlow16 = (0.0010000000000000009 * double(fVslider11));
		double fSlow17 = double(fVslider12);
		int iSlow18 = (fSlow17 >= 2.0);
		int iSlow19 = (fSlow17 >= 1.0);
		double fSlow20 = (0.0010000000000000009 * double(fVslider13));
		int iSlow21 = (fSlow17 >= 3.0);
		double fSlow22 = (0.0010000000000000009 * double(fVslider14));
		double fSlow23 = double(fVslider15);
		double fSlow24 = (2.0 * (fSlow23 * std::pow(2.0, (0.083333333333333329 * double(fVslider16)))));
		double fSlow25 = std::exp((0.0 - (fConst5 / double(fVslider18))));
		double fSlow26 = (double(fVslider17) * (1.0 - fSlow25));
		double fSlow27 = (0.0010000000000000009 * double(fVslider19));
		double fSlow28 = double(fVslider20);
		double fSlow29 = (0.0010000000000000009 * double(fVslider21));
		double fSlow30 = (0.0010000000000000009 * double(fVslider22));
		double fSlow31 = (2.0 * (fSlow23 * std::pow(2.0, (0.083333333333333329 * double(fVslider23)))));
		double fSlow32 = (0.0010000000000000009 * double(fVslider24));
		double fSlow33 = double(fVslider25);
		double fSlow34 = (0.0010000000000000009 * double(fVslider26));
		double fSlow35 = (0.0010000000000000009 * double(fVslider27));
		double fSlow36 = (2.0 * (fSlow23 * std::pow(2.0, (0.083333333333333329 * double(fVslider28)))));
		double fSlow37 = (0.0010000000000000009 * double(fVslider29));
		double fSlow38 = (0.0010000000000000009 * double(fVslider30));
		double fSlow39 = (2.0 * fSlow23);
		double fSlow40 = (0.0010000000000000009 * double(fVslider31));
		double fSlow41 = (0.0010000000000000009 * double(fCheckbox0));
		double fSlow42 = (0.0010000000000000009 * double(fVslider32));
		double fSlow43 = (0.0010000000000000009 * double(fVslider33));
		double fSlow44 = (0.0010000000000000009 * double(fVslider34));
		double fSlow45 = (0.0010000000000000009 * double(fVslider35));
		double fSlow46 = (0.0010000000000000009 * double(fVslider36));
		double fSlow47 = (0.0010000000000000009 * double(fVslider37));
		double fSlow48 = (0.0010000000000000009 * double(fVslider38));
		double fSlow49 = (0.0010000000000000009 * double(fCheckbox1));
		double fSlow50 = (0.0010000000000000009 * double(fVslider39));
		double fSlow51 = (0.0010000000000000009 * double(fVslider40));
		double fSlow52 = (0.0010000000000000009 * double(fVslider41));
		double fSlow53 = (0.0010000000000000009 * double(fVslider42));
		double fSlow54 = (0.0010000000000000009 * double(fVslider43));
		double fSlow55 = (0.0010000000000000009 * double(fVslider44));
		double fSlow56 = (0.0010000000000000009 * double(fVslider45));
		double fSlow57 = (0.0010000000000000009 * double(fVslider46));
		double fSlow58 = (0.0010000000000000009 * double(fVslider47));
		double fSlow59 = (0.0010000000000000009 * double(fVslider48));
		for (int i = 0; (i < count); i = (i + 1)) {
			iVec0[0] = 1;
			fRec1[0] = (fSlow1 + (0.999 * fRec1[1]));
			iRec2[0] = (iSlow0 * (iRec2[1] + 1));
			fRec3[0] = (fSlow2 + (0.999 * fRec3[1]));
			int iTemp0 = (iRec2[0] < int((fConst0 * fRec3[0])));
			fRec4[0] = (fSlow3 + (0.999 * fRec4[1]));
			double fTemp1 = std::exp((0.0 - (fConst1 / (iSlow0?(iTemp0?fRec3[0]:fRec4[0]):fRec1[0]))));
			fRec5[0] = (fSlow5 + (0.999 * fRec5[1]));
			fRec0[0] = ((fRec0[1] * fTemp1) + ((iSlow0?(iTemp0?double(iSlow0):(fSlow4 * fRec5[0])):0.0) * (1.0 - fTemp1)));
			fRec6[0] = (fSlow6 + (0.999 * fRec6[1]));
			fRec7[0] = (fSlow7 + (0.999 * fRec7[1]));
			fRec9[0] = (fSlow8 + (0.999 * fRec9[1]));
			fRec14[0] = (fSlow13 + (0.999 * fRec14[1]));
			fRec15[0] = (fSlow14 + (0.999 * fRec15[1]));
			double fTemp2 = (fRec14[0] * fRec15[0]);
			fRec16[0] = (fRec16[1] + (fConst3 * (fTemp2 * (0.0 - fRec12[1]))));
			int iTemp3 = (1 - iVec0[1]);
			fRec13[0] = ((fRec13[1] + (fConst3 * (fTemp2 * fRec16[0]))) + double(iTemp3));
			fRec12[0] = fRec13[0];
			double fTemp4 = std::max(9.9999999999999995e-08, std::fabs((0.016666666666666666 * fTemp2)));
			double fTemp5 = (fRec17[1] + (fConst2 * fTemp4));
			double fTemp6 = (fTemp5 + -1.0);
			int iTemp7 = (fTemp6 < 0.0);
			fRec17[0] = (iTemp7?fTemp5:fTemp6);
			double fRec18 = (iTemp7?fTemp5:(fTemp5 + (fTemp6 * (1.0 - (fConst0 / fTemp4)))));
			double fTemp8 = std::exp((0.0 - (fConst4 * fTemp2)));
			double fTemp9 = (fConst3 * fTemp2);
			double fTemp10 = std::sin(fTemp9);
			double fTemp11 = std::cos(fTemp9);
			fRec21[0] = ((fRec22[1] * fTemp10) + (fRec21[1] * fTemp11));
			fRec22[0] = (((fRec22[1] * fTemp11) + (fRec21[1] * (0.0 - fTemp10))) + double(iTemp3));
			int iTemp12 = ((fRec21[1] <= 0.0) & (fRec21[0] > 0.0));
			iRec23[0] = ((1103515245 * iRec23[1]) + 12345);
			fRec20[0] = ((fRec20[1] * double((1 - iTemp12))) + (4.6566128752457969e-10 * double((iRec23[0] * iTemp12))));
			fRec19[0] = ((fRec19[1] * fTemp8) + (fRec20[0] * (1.0 - fTemp8)));
			fRec11[0] = ((0.999 * fRec11[1]) + (0.0010000000000000009 * (iSlow11?(iSlow15?fRec20[0]:fRec19[0]):(iSlow12?((2.0 * fRec18) + -1.0):fRec12[0]))));
			fRec24[0] = (fSlow16 + (0.999 * fRec24[1]));
			fRec28[0] = (fSlow20 + (0.999 * fRec28[1]));
			double fTemp13 = (fRec15[0] * fRec28[0]);
			fRec29[0] = (fRec29[1] + (fConst3 * (fTemp13 * (0.0 - fRec26[1]))));
			fRec27[0] = ((fRec27[1] + (fConst3 * (fTemp13 * fRec29[0]))) + double(iTemp3));
			fRec26[0] = fRec27[0];
			double fTemp14 = std::max(9.9999999999999995e-08, std::fabs((0.016666666666666666 * fTemp13)));
			double fTemp15 = (fRec30[1] + (fConst2 * fTemp14));
			double fTemp16 = (fTemp15 + -1.0);
			int iTemp17 = (fTemp16 < 0.0);
			fRec30[0] = (iTemp17?fTemp15:fTemp16);
			double fRec31 = (iTemp17?fTemp15:(fTemp15 + (fTemp16 * (1.0 - (fConst0 / fTemp14)))));
			double fTemp18 = std::exp((0.0 - (fConst4 * fTemp13)));
			double fTemp19 = (fConst3 * fTemp13);
			double fTemp20 = std::sin(fTemp19);
			double fTemp21 = std::cos(fTemp19);
			fRec34[0] = ((fRec35[1] * fTemp20) + (fRec34[1] * fTemp21));
			fRec35[0] = (((fRec35[1] * fTemp21) + (fRec34[1] * (0.0 - fTemp20))) + double(iTemp3));
			int iTemp22 = ((fRec34[1] <= 0.0) & (fRec34[0] > 0.0));
			fRec33[0] = ((fRec33[1] * double((1 - iTemp22))) + (4.6566128752457969e-10 * double((iRec23[0] * iTemp22))));
			fRec32[0] = ((fRec32[1] * fTemp18) + (fRec33[0] * (1.0 - fTemp18)));
			fRec25[0] = ((0.999 * fRec25[1]) + (0.0010000000000000009 * (iSlow18?(iSlow21?fRec33[0]:fRec32[0]):(iSlow19?((2.0 * fRec31) + -1.0):fRec26[0]))));
			fRec36[0] = (fSlow22 + (0.999 * fRec36[1]));
			fRec37[0] = (fSlow26 + (fSlow25 * fRec37[1]));
			double fTemp23 = (((fRec11[0] * fRec24[0]) + (fRec25[0] * fRec36[0])) + (fSlow24 * fRec37[0]));
			double fTemp24 = (fRec10[1] + (fConst2 * fTemp23));
			fRec10[0] = (fTemp24 - std::floor(fTemp24));
			double fTemp25 = (fTemp23 + -200.0);
			double fTemp26 = (0.0002631578947368421 * fTemp25);
			double fTemp27 = (double((fTemp26 > 1.0)) + (0.0002631578947368421 * (fTemp25 * double((fTemp26 <= 1.0)))));
			int iTemp28 = (fTemp27 >= 0.0);
			fRec40[0] = (fRec40[1] + (fConst6 * (fTemp23 * (0.0 - fRec38[1]))));
			fRec39[0] = ((fRec39[1] + (fConst6 * (fRec40[0] * fTemp23))) + double(iTemp3));
			fRec38[0] = fRec39[0];
			fRec41[0] = (fSlow27 + (0.999 * fRec41[1]));
			fRec43[0] = (fSlow29 + (0.999 * fRec43[1]));
			fRec44[0] = (fSlow30 + (0.999 * fRec44[1]));
			double fTemp29 = (((fRec11[0] * fRec43[0]) + (fRec25[0] * fRec44[0])) + (fSlow31 * fRec37[0]));
			double fTemp30 = (fRec42[1] + (fConst2 * fTemp29));
			fRec42[0] = (fTemp30 - std::floor(fTemp30));
			double fTemp31 = (fTemp29 + -200.0);
			double fTemp32 = (0.0002631578947368421 * fTemp31);
			double fTemp33 = (double((fTemp32 > 1.0)) + (0.0002631578947368421 * (fTemp31 * double((fTemp32 <= 1.0)))));
			int iTemp34 = (fTemp33 >= 0.0);
			fRec47[0] = (fRec47[1] + (fConst6 * (fTemp29 * (0.0 - fRec45[1]))));
			fRec46[0] = ((fRec46[1] + (fConst6 * (fRec47[0] * fTemp29))) + double(iTemp3));
			fRec45[0] = fRec46[0];
			fRec48[0] = (fSlow32 + (0.999 * fRec48[1]));
			fRec50[0] = (fSlow34 + (0.999 * fRec50[1]));
			fRec51[0] = (fSlow35 + (0.999 * fRec51[1]));
			double fTemp35 = (((fRec11[0] * fRec50[0]) + (fRec25[0] * fRec51[0])) + (fSlow36 * fRec37[0]));
			double fTemp36 = (fRec49[1] + (fConst2 * fTemp35));
			fRec49[0] = (fTemp36 - std::floor(fTemp36));
			double fTemp37 = (fTemp35 + -200.0);
			double fTemp38 = (0.0002631578947368421 * fTemp37);
			double fTemp39 = (double((fTemp38 > 1.0)) + (0.0002631578947368421 * (fTemp37 * double((fTemp38 <= 1.0)))));
			int iTemp40 = (fTemp39 >= 0.0);
			fRec54[0] = (fRec54[1] + (fConst6 * (fTemp35 * (0.0 - fRec52[1]))));
			fRec53[0] = ((fRec53[1] + (fConst6 * (fRec54[0] * fTemp35))) + double(iTemp3));
			fRec52[0] = fRec53[0];
			double fTemp41 = (((fRec9[0] * ((ftbl0mydspSIG0[int((2048.0 * (fSlow9 + fRec10[0])))] * (1.0 - (fTemp27 * double(iTemp28)))) + ((fRec38[0] * fTemp27) * double(iTemp28)))) + (fRec41[0] * ((ftbl0mydspSIG0[int((2048.0 * (fSlow28 + fRec42[0])))] * (1.0 - (fTemp33 * double(iTemp34)))) + ((fRec45[0] * fTemp33) * double(iTemp34))))) + (fRec48[0] * ((ftbl0mydspSIG0[int((2048.0 * (fSlow33 + fRec49[0])))] * (1.0 - (fTemp39 * double(iTemp40)))) + ((fRec52[0] * fTemp39) * double(iTemp40)))));
			fRec58[0] = (fSlow37 + (0.999 * fRec58[1]));
			fRec59[0] = (fSlow38 + (0.999 * fRec59[1]));
			fRec60[0] = (fSlow40 + (0.999 * fRec60[1]));
			double fTemp42 = (((fRec11[0] * fRec58[0]) + (fRec25[0] * fRec59[0])) + (fSlow39 * (fRec37[0] * fRec60[0])));
			double fTemp43 = (double((20000 * (fTemp42 > 20000.0))) + (fTemp42 * double((fTemp42 <= 20000.0))));
			int iTemp44 = (fTemp43 >= 0.0);
			fRec57[0] = (fRec57[1] + (fConst6 * (((0.0 - fRec55[1]) * fTemp43) * double(iTemp44))));
			fRec56[0] = ((fRec56[1] + (fConst6 * ((fRec57[0] * fTemp43) * double(iTemp44)))) + double(iTemp3));
			fRec55[0] = fRec56[0];
			fRec61[0] = (fSlow41 + (0.999 * fRec61[1]));
			fRec62[0] = (fSlow42 + (0.999 * fRec62[1]));
			fRec64[0] = (fSlow43 + (0.999 * fRec64[1]));
			fRec65[0] = (fSlow44 + (0.999 * fRec65[1]));
			int iTemp45 = (iRec2[0] < int((fConst0 * fRec65[0])));
			fRec66[0] = (fSlow45 + (0.999 * fRec66[1]));
			double fTemp46 = std::exp((0.0 - (fConst1 / (iSlow0?(iTemp45?fRec65[0]:fRec66[0]):fRec64[0]))));
			fRec67[0] = (fSlow46 + (0.999 * fRec67[1]));
			fRec63[0] = ((fRec63[1] * fTemp46) + ((iSlow0?(iTemp45?double(iSlow0):(fSlow4 * fRec67[0])):0.0) * (1.0 - fTemp46)));
			fRec68[0] = (fSlow47 + (0.999 * fRec68[1]));
			double fTemp47 = (3.1415926535897931 * (fRec55[0] * (((1.0 - fRec61[0]) * (fRec62[0] + (fRec63[0] * ((15.0 * fRec68[0]) - fRec62[0])))) + ((fRec62[0] * fRec61[0]) * (1.0 - (fRec63[0] * fRec68[0]))))));
			double fTemp48 = std::sin(fTemp47);
			double fTemp49 = (0.0 - fTemp48);
			double fTemp50 = std::cos(fTemp47);
			double fTemp51 = ((fRec69[1] * fTemp49) + (0.20000000000000001 * (fTemp41 * fTemp50)));
			double fTemp52 = ((fTemp49 * fRec70[1]) + (fTemp50 * fTemp51));
			fRec71[0] = ((fTemp49 * fRec71[1]) + (fTemp50 * fTemp52));
			fRec70[0] = ((fTemp48 * fTemp52) + (fTemp50 * fRec71[1]));
			fRec69[0] = ((fTemp48 * fTemp51) + (fTemp50 * fRec70[1]));
			double fTemp53 = ((0.20000000000000001 * (fTemp41 * fTemp48)) + (fRec69[1] * fTemp50));
			double fTemp54 = std::max(-1.0, std::min(1.0, (6.3095734448019334 * fTemp53)));
			double fTemp55 = (fTemp54 * (1.0 - (0.33333333333333331 * mydsp_faustpower2_f(fTemp54))));
			fVec1[0] = fTemp55;
			fRec8[0] = (((0.995 * fRec8[1]) + fTemp55) - fVec1[1]);
			fRec72[0] = (fSlow48 + (0.999 * fRec72[1]));
			double fTemp56 = mydsp_faustpower2_f((1.4141994202374715 * fRec72[0]));
			double fTemp57 = (1.9999800000000003 * fRec72[0]);
			double fTemp58 = (fTemp56 + fTemp57);
			double fTemp59 = (fTemp57 + 2.0);
			fRec73[0] = (fSlow49 + (0.999 * fRec73[1]));
			fRec74[0] = (fSlow50 + (0.999 * fRec74[1]));
			fRec75[0] = (fSlow51 + (0.999 * fRec75[1]));
			fRec76[0] = (fSlow52 + (0.999 * fRec76[1]));
			double fTemp60 = (((fRec11[0] * fRec74[0]) + (fRec25[0] * fRec75[0])) + (fSlow39 * (fRec37[0] * fRec76[0])));
			fRec78[0] = (fSlow53 + (0.999 * fRec78[1]));
			fRec79[0] = (fSlow54 + (0.999 * fRec79[1]));
			int iTemp61 = (iRec2[0] < int((fConst0 * fRec79[0])));
			fRec80[0] = (fSlow55 + (0.999 * fRec80[1]));
			double fTemp62 = std::exp((0.0 - (fConst1 / (iSlow0?(iTemp61?fRec79[0]:fRec80[0]):fRec78[0]))));
			fRec81[0] = (fSlow56 + (0.999 * fRec81[1]));
			fRec77[0] = ((fRec77[1] * fTemp62) + ((iSlow0?(iTemp61?double(iSlow0):(fSlow4 * fRec81[0])):0.0) * (1.0 - fTemp62)));
			fRec82[0] = (fSlow57 + (0.999 * fRec82[1]));
			double fTemp63 = (((1.0 - fRec73[0]) * (fTemp60 + (fRec77[0] * ((fConst8 * fRec82[0]) - fTemp60)))) + (fRec73[0] * (fTemp60 - ((fRec77[0] * fRec82[0]) * (fTemp60 + -20.0)))));
			double fTemp64 = ((fConst10 * double((fTemp63 > fConst10))) + (fTemp63 * double((fTemp63 <= fConst10))));
			double fTemp65 = std::tan((fConst7 * std::max(((fConst9 * double((fTemp64 < fConst9))) + (fTemp64 * double((fTemp64 >= fConst9)))), 20.0)));
			double fTemp66 = (1.0 / fTemp65);
			double fTemp67 = ((fTemp58 + ((fTemp59 + fTemp66) / fTemp65)) + 1.0);
			double fTemp68 = ((fTemp58 + (1.0 - ((fTemp59 - fTemp66) / fTemp65))) / fTemp67);
			double fTemp69 = std::max(-0.99990000000000001, std::min(0.99990000000000001, fTemp68));
			double fTemp70 = (1.0 - mydsp_faustpower2_f(fTemp69));
			double fTemp71 = std::sqrt(std::max(0.0, fTemp70));
			double fTemp72 = ((fRec83[1] * (0.0 - fTemp69)) + (fRec8[0] * fTemp71));
			double fTemp73 = (1.0 / mydsp_faustpower2_f(fTemp65));
			double fTemp74 = (fTemp58 + (1.0 - fTemp73));
			double fTemp75 = std::max(-0.99990000000000001, std::min(0.99990000000000001, (2.0 * (fTemp74 / (fTemp67 * (fTemp68 + 1.0))))));
			double fTemp76 = (1.0 - mydsp_faustpower2_f(fTemp75));
			double fTemp77 = std::sqrt(std::max(0.0, fTemp76));
			fRec85[0] = ((fRec85[1] * (0.0 - fTemp75)) + (fTemp72 * fTemp77));
			fRec83[0] = ((fTemp72 * fTemp75) + (fRec85[1] * fTemp77));
			double fRec84 = fRec85[0];
			double fTemp78 = (1.0 - (fTemp74 / fTemp67));
			double fTemp79 = std::sqrt(fTemp70);
			double fTemp80 = ((((fRec8[0] * fTemp69) + (fRec83[1] * fTemp71)) + (2.0 * ((fRec83[0] * fTemp78) / fTemp79))) + ((fRec84 * ((1.0 - fTemp68) - (2.0 * (fTemp75 * fTemp78)))) / (fTemp79 * std::sqrt(fTemp76))));
			double fTemp81 = (2.0 - fTemp57);
			double fTemp82 = (1.0 - fTemp57);
			double fTemp83 = ((fTemp56 + ((fTemp66 + fTemp81) / fTemp65)) + fTemp82);
			double fTemp84 = (((fTemp56 + ((fTemp66 - fTemp81) / fTemp65)) + fTemp82) / fTemp83);
			double fTemp85 = std::max(-0.99990000000000001, std::min(0.99990000000000001, fTemp84));
			double fTemp86 = (1.0 - mydsp_faustpower2_f(fTemp85));
			double fTemp87 = std::sqrt(std::max(0.0, fTemp86));
			double fTemp88 = ((fRec86[1] * (0.0 - fTemp85)) + ((fTemp80 * fTemp87) / fTemp67));
			double fTemp89 = (fTemp56 + (1.0 - (fTemp57 + fTemp73)));
			double fTemp90 = std::max(-0.99990000000000001, std::min(0.99990000000000001, (2.0 * (fTemp89 / (fTemp83 * (fTemp84 + 1.0))))));
			double fTemp91 = (1.0 - mydsp_faustpower2_f(fTemp90));
			double fTemp92 = std::sqrt(std::max(0.0, fTemp91));
			fRec88[0] = ((fRec88[1] * (0.0 - fTemp90)) + (fTemp88 * fTemp92));
			fRec86[0] = ((fTemp88 * fTemp90) + (fRec88[1] * fTemp92));
			double fRec87 = fRec88[0];
			double fTemp93 = (1.0 - (fTemp89 / fTemp83));
			double fTemp94 = std::sqrt(fTemp86);
			fRec89[0] = (fSlow58 + (0.999 * fRec89[1]));
			fRec90[0] = (fSlow59 + (0.999 * fRec90[1]));
			double fTemp95 = (((fRec0[0] * fRec6[0]) * ((0.40000000000000002 * ((fRec7[0] * (((((fTemp80 * fTemp85) / fTemp67) + (fRec86[1] * fTemp87)) + (2.0 * ((fRec86[0] * fTemp93) / fTemp94))) + ((fRec87 * ((1.0 - fTemp84) - (2.0 * (fTemp90 * fTemp93)))) / (fTemp94 * std::sqrt(fTemp91))))) / fTemp83)) + ((1.0 - fRec7[0]) * fTemp53))) * (((fRec11[0] * fRec89[0]) + (fRec25[0] * fRec90[0])) + 2.0));
			double fTemp96 = std::fabs((0.5 * fTemp95));
			double fTemp97 = ((fRec92[1] > fTemp96)?fConst14:fConst13);
			fRec93[0] = ((fRec93[1] * fTemp97) + (fTemp96 * (1.0 - fTemp97)));
			fRec92[0] = fRec93[0];
			fRec91[0] = ((fConst11 * fRec91[1]) + (fConst12 * (0.0 - (0.75 * std::max(((20.0 * std::log10(fRec92[0])) + 6.0), 0.0)))));
			double fTemp98 = (0.5 * (fTemp95 * std::pow(10.0, (0.050000000000000003 * fRec91[0]))));
			output0[i] = FAUSTFLOAT(fTemp98);
			output1[i] = FAUSTFLOAT(fTemp98);
			iVec0[1] = iVec0[0];
			fRec1[1] = fRec1[0];
			iRec2[1] = iRec2[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			fRec0[1] = fRec0[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			fRec9[1] = fRec9[0];
			fRec14[1] = fRec14[0];
			fRec15[1] = fRec15[0];
			fRec16[1] = fRec16[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec17[1] = fRec17[0];
			fRec21[1] = fRec21[0];
			fRec22[1] = fRec22[0];
			iRec23[1] = iRec23[0];
			fRec20[1] = fRec20[0];
			fRec19[1] = fRec19[0];
			fRec11[1] = fRec11[0];
			fRec24[1] = fRec24[0];
			fRec28[1] = fRec28[0];
			fRec29[1] = fRec29[0];
			fRec27[1] = fRec27[0];
			fRec26[1] = fRec26[0];
			fRec30[1] = fRec30[0];
			fRec34[1] = fRec34[0];
			fRec35[1] = fRec35[0];
			fRec33[1] = fRec33[0];
			fRec32[1] = fRec32[0];
			fRec25[1] = fRec25[0];
			fRec36[1] = fRec36[0];
			fRec37[1] = fRec37[0];
			fRec10[1] = fRec10[0];
			fRec40[1] = fRec40[0];
			fRec39[1] = fRec39[0];
			fRec38[1] = fRec38[0];
			fRec41[1] = fRec41[0];
			fRec43[1] = fRec43[0];
			fRec44[1] = fRec44[0];
			fRec42[1] = fRec42[0];
			fRec47[1] = fRec47[0];
			fRec46[1] = fRec46[0];
			fRec45[1] = fRec45[0];
			fRec48[1] = fRec48[0];
			fRec50[1] = fRec50[0];
			fRec51[1] = fRec51[0];
			fRec49[1] = fRec49[0];
			fRec54[1] = fRec54[0];
			fRec53[1] = fRec53[0];
			fRec52[1] = fRec52[0];
			fRec58[1] = fRec58[0];
			fRec59[1] = fRec59[0];
			fRec60[1] = fRec60[0];
			fRec57[1] = fRec57[0];
			fRec56[1] = fRec56[0];
			fRec55[1] = fRec55[0];
			fRec61[1] = fRec61[0];
			fRec62[1] = fRec62[0];
			fRec64[1] = fRec64[0];
			fRec65[1] = fRec65[0];
			fRec66[1] = fRec66[0];
			fRec67[1] = fRec67[0];
			fRec63[1] = fRec63[0];
			fRec68[1] = fRec68[0];
			fRec71[1] = fRec71[0];
			fRec70[1] = fRec70[0];
			fRec69[1] = fRec69[0];
			fVec1[1] = fVec1[0];
			fRec8[1] = fRec8[0];
			fRec72[1] = fRec72[0];
			fRec73[1] = fRec73[0];
			fRec74[1] = fRec74[0];
			fRec75[1] = fRec75[0];
			fRec76[1] = fRec76[0];
			fRec78[1] = fRec78[0];
			fRec79[1] = fRec79[0];
			fRec80[1] = fRec80[0];
			fRec81[1] = fRec81[0];
			fRec77[1] = fRec77[0];
			fRec82[1] = fRec82[0];
			fRec85[1] = fRec85[0];
			fRec83[1] = fRec83[0];
			fRec88[1] = fRec88[0];
			fRec86[1] = fRec86[0];
			fRec89[1] = fRec89[0];
			fRec90[1] = fRec90[0];
			fRec93[1] = fRec93[0];
			fRec92[1] = fRec92[0];
			fRec91[1] = fRec91[0];
			
		}
		
	}

	
};

/***************************END USER SECTION ***************************/

/*******************BEGIN ARCHITECTURE SECTION (part 2/2)***************/

/* Faust code wrapper ------- */

#include "ext.h"
#include "ext_obex.h"
#include "z_dsp.h"
#include "jpatcher_api.h"
#include <string.h>

#define ASSIST_INLET 	1  	/* should be defined somewhere ?? */
#define ASSIST_OUTLET 	2	/* should be defined somewhere ?? */

#define EXTERNAL_VERSION    "0.64"
#define STR_SIZE            512

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef __GUI_H__
#define __GUI_H__

#include <list>
#include <map>
#include <vector>
#include <iostream>

#ifdef _WIN32
# pragma warning (disable: 4100)
#else
# pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

/*
  Copyright (C) 2000 Paul Davis
  Copyright (C) 2003 Rohan Drape
  Copyright (C) 2016 GRAME (renaming for internal use)

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

  ISO/POSIX C version of Paul Davis's lock free ringbuffer C++ code.
  This is safe for the case of one read thread and one write thread.
*/

#ifndef __ring_buffer__
#define __ring_buffer__

#include <stdlib.h>
#include <string.h>

#ifdef WIN32
#pragma warning (disable: 4334)
#endif

typedef struct {
    char *buf;
    size_t len;
}
ringbuffer_data_t;

typedef struct {
    char *buf;
    volatile size_t write_ptr;
    volatile size_t read_ptr;
    size_t	size;
    size_t	size_mask;
    int	mlocked;
}
ringbuffer_t;

ringbuffer_t *ringbuffer_create(size_t sz);
void ringbuffer_free(ringbuffer_t *rb);
void ringbuffer_get_read_vector(const ringbuffer_t *rb,
                                         ringbuffer_data_t *vec);
void ringbuffer_get_write_vector(const ringbuffer_t *rb,
                                          ringbuffer_data_t *vec);
size_t ringbuffer_read(ringbuffer_t *rb, char *dest, size_t cnt);
size_t ringbuffer_peek(ringbuffer_t *rb, char *dest, size_t cnt);
void ringbuffer_read_advance(ringbuffer_t *rb, size_t cnt);
size_t ringbuffer_read_space(const ringbuffer_t *rb);
int ringbuffer_mlock(ringbuffer_t *rb);
void ringbuffer_reset(ringbuffer_t *rb);
void ringbuffer_reset_size (ringbuffer_t * rb, size_t sz);
size_t ringbuffer_write(ringbuffer_t *rb, const char *src,
                                 size_t cnt);
void ringbuffer_write_advance(ringbuffer_t *rb, size_t cnt);
size_t ringbuffer_write_space(const ringbuffer_t *rb);

/* Create a new ringbuffer to hold at least `sz' bytes of data. The
   actual buffer size is rounded up to the next power of two. */

inline ringbuffer_t *
ringbuffer_create (size_t sz)
{
	size_t power_of_two;
	ringbuffer_t *rb;

	if ((rb = (ringbuffer_t *) malloc (sizeof (ringbuffer_t))) == NULL) {
		return NULL;
	}

	for (power_of_two = 1u; 1u << power_of_two < sz; power_of_two++);

	rb->size = 1u << power_of_two;
	rb->size_mask = rb->size;
	rb->size_mask -= 1;
	rb->write_ptr = 0;
	rb->read_ptr = 0;
	if ((rb->buf = (char *) malloc (rb->size)) == NULL) {
		free (rb);
		return NULL;
	}
	rb->mlocked = 0;

	return rb;
}

/* Free all data associated with the ringbuffer `rb'. */

inline void
ringbuffer_free (ringbuffer_t * rb)
{
#ifdef USE_MLOCK
	if (rb->mlocked) {
		munlock (rb->buf, rb->size);
	}
#endif /* USE_MLOCK */
	free (rb->buf);
	free (rb);
}

/* Lock the data block of `rb' using the system call 'mlock'.  */

inline int
ringbuffer_mlock (ringbuffer_t * rb)
{
#ifdef USE_MLOCK
	if (mlock (rb->buf, rb->size)) {
		return -1;
	}
#endif /* USE_MLOCK */
	rb->mlocked = 1;
	return 0;
}

/* Reset the read and write pointers to zero. This is not thread
   safe. */

inline void
ringbuffer_reset (ringbuffer_t * rb)
{
	rb->read_ptr = 0;
	rb->write_ptr = 0;
    memset(rb->buf, 0, rb->size);
}

/* Reset the read and write pointers to zero. This is not thread
   safe. */

inline void
ringbuffer_reset_size (ringbuffer_t * rb, size_t sz)
{
    rb->size = sz;
    rb->size_mask = rb->size;
    rb->size_mask -= 1;
    rb->read_ptr = 0;
    rb->write_ptr = 0;
}

/* Return the number of bytes available for reading. This is the
   number of bytes in front of the read pointer and behind the write
   pointer.  */

inline size_t
ringbuffer_read_space (const ringbuffer_t * rb)
{
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		return w - r;
	} else {
		return (w - r + rb->size) & rb->size_mask;
	}
}

/* Return the number of bytes available for writing. This is the
   number of bytes in front of the write pointer and behind the read
   pointer.  */

inline size_t
ringbuffer_write_space (const ringbuffer_t * rb)
{
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		return ((r - w + rb->size) & rb->size_mask) - 1;
	} else if (w < r) {
		return (r - w) - 1;
	} else {
		return rb->size - 1;
	}
}

/* The copying data reader. Copy at most `cnt' bytes from `rb' to
   `dest'.  Returns the actual number of bytes copied. */

inline size_t
ringbuffer_read (ringbuffer_t * rb, char *dest, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_read;
	size_t n1, n2;

	if ((free_cnt = ringbuffer_read_space (rb)) == 0) {
		return 0;
	}

	to_read = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = rb->read_ptr + to_read;

	if (cnt2 > rb->size) {
		n1 = rb->size - rb->read_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_read;
		n2 = 0;
	}

	memcpy (dest, &(rb->buf[rb->read_ptr]), n1);
	rb->read_ptr = (rb->read_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (dest + n1, &(rb->buf[rb->read_ptr]), n2);
		rb->read_ptr = (rb->read_ptr + n2) & rb->size_mask;
	}

	return to_read;
}

/* The copying data reader w/o read pointer advance. Copy at most
   `cnt' bytes from `rb' to `dest'.  Returns the actual number of bytes
   copied. */

inline size_t
ringbuffer_peek (ringbuffer_t * rb, char *dest, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_read;
	size_t n1, n2;
	size_t tmp_read_ptr;

	tmp_read_ptr = rb->read_ptr;

	if ((free_cnt = ringbuffer_read_space (rb)) == 0) {
		return 0;
	}

	to_read = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = tmp_read_ptr + to_read;

	if (cnt2 > rb->size) {
		n1 = rb->size - tmp_read_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_read;
		n2 = 0;
	}

	memcpy (dest, &(rb->buf[tmp_read_ptr]), n1);
	tmp_read_ptr = (tmp_read_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (dest + n1, &(rb->buf[tmp_read_ptr]), n2);
	}

	return to_read;
}

/* The copying data writer. Copy at most `cnt' bytes to `rb' from
   `src'.  Returns the actual number of bytes copied. */

inline size_t
ringbuffer_write (ringbuffer_t * rb, const char *src, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_write;
	size_t n1, n2;

	if ((free_cnt = ringbuffer_write_space (rb)) == 0) {
		return 0;
	}

	to_write = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = rb->write_ptr + to_write;

	if (cnt2 > rb->size) {
		n1 = rb->size - rb->write_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_write;
		n2 = 0;
	}

	memcpy (&(rb->buf[rb->write_ptr]), src, n1);
	rb->write_ptr = (rb->write_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (&(rb->buf[rb->write_ptr]), src + n1, n2);
		rb->write_ptr = (rb->write_ptr + n2) & rb->size_mask;
	}

	return to_write;
}

/* Advance the read pointer `cnt' places. */

inline void
ringbuffer_read_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->read_ptr + cnt) & rb->size_mask;
	rb->read_ptr = tmp;
}

/* Advance the write pointer `cnt' places. */

inline void
ringbuffer_write_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->write_ptr + cnt) & rb->size_mask;
	rb->write_ptr = tmp;
}

/* The non-copying data reader. `vec' is an array of two places. Set
   the values at `vec' to hold the current readable data at `rb'. If
   the readable data is in one segment the second segment has zero
   length. */

inline void
ringbuffer_get_read_vector (const ringbuffer_t * rb,
				 ringbuffer_data_t * vec)
{
	size_t free_cnt;
	size_t cnt2;
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		free_cnt = w - r;
	} else {
		free_cnt = (w - r + rb->size) & rb->size_mask;
	}

	cnt2 = r + free_cnt;

	if (cnt2 > rb->size) {

		/* Two part vector: the rest of the buffer after the current write
		   ptr, plus some from the start of the buffer. */

		vec[0].buf = &(rb->buf[r]);
		vec[0].len = rb->size - r;
		vec[1].buf = rb->buf;
		vec[1].len = cnt2 & rb->size_mask;

	} else {

		/* Single part vector: just the rest of the buffer */

		vec[0].buf = &(rb->buf[r]);
		vec[0].len = free_cnt;
		vec[1].len = 0;
	}
}

/* The non-copying data writer. `vec' is an array of two places. Set
   the values at `vec' to hold the current writeable data at `rb'. If
   the writeable data is in one segment the second segment has zero
   length. */

inline void
ringbuffer_get_write_vector (const ringbuffer_t * rb,
				  ringbuffer_data_t * vec)
{
	size_t free_cnt;
	size_t cnt2;
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		free_cnt = ((r - w + rb->size) & rb->size_mask) - 1;
	} else if (w < r) {
		free_cnt = (r - w) - 1;
	} else {
		free_cnt = rb->size - 1;
	}

	cnt2 = w + free_cnt;

	if (cnt2 > rb->size) {

		/* Two part vector: the rest of the buffer after the current write
		   ptr, plus some from the start of the buffer. */

		vec[0].buf = &(rb->buf[w]);
		vec[0].len = rb->size - w;
		vec[1].buf = rb->buf;
		vec[1].len = cnt2 & rb->size_mask;
	} else {
		vec[0].buf = &(rb->buf[w]);
		vec[0].len = free_cnt;
		vec[1].len = 0;
	}
}

#endif // __ring_buffer__

/*******************************************************************************
 * GUI : Abstract Graphic User Interface
 * Provides additional mechanisms to synchronize widgets and zones. Widgets
 * should both reflect the value of a zone and allow to change this value.
 ******************************************************************************/

class uiItem;
typedef void (*uiCallback)(FAUSTFLOAT val, void* data);

class clist : public std::list<uiItem*>
{
    
    public:
    
        virtual ~clist();
        
};

typedef std::map<FAUSTFLOAT*, clist*> zmap;

typedef std::map<FAUSTFLOAT*, ringbuffer_t*> ztimedmap;

class GUI : public UI
{
		
    private:
     
        static std::list<GUI*> fGuiList;
        zmap fZoneMap;
        bool fStopped;
        
     public:
            
        GUI():fStopped(false)
        {	
            fGuiList.push_back(this);
        }
        
        virtual ~GUI() 
        {   
            // delete all items
            zmap::iterator it;
            for (it = fZoneMap.begin(); it != fZoneMap.end(); it++) {
                delete (*it).second;
            }
            // suppress 'this' in static fGuiList
            fGuiList.remove(this);
        }

        // -- registerZone(z,c) : zone management
        
        void registerZone(FAUSTFLOAT* z, uiItem* c)
        {
            if (fZoneMap.find(z) == fZoneMap.end()) fZoneMap[z] = new clist();
            fZoneMap[z]->push_back(c);
        }

        void updateAllZones();
        
        void updateZone(FAUSTFLOAT* z);
        
        static void updateAllGuis()
        {
            std::list<GUI*>::iterator g;
            for (g = fGuiList.begin(); g != fGuiList.end(); g++) {
                (*g)->updateAllZones();
            }
        }
        void addCallback(FAUSTFLOAT* zone, uiCallback foo, void* data);
        virtual void show() {};	
        virtual bool run() { return false; };
    
        virtual void stop() { fStopped = true; }
        bool stopped() { return fStopped; }
    
        // -- widget's layouts
        
        virtual void openTabBox(const char* label) {};
        virtual void openHorizontalBox(const char* label) {}
        virtual void openVerticalBox(const char* label) {}
        virtual void closeBox() {}
        
        // -- active widgets
        
        virtual void addButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
    
        // -- passive widgets
        
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}
    
        // -- metadata declarations

        virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
    
        // Static global for timed zones, shared between all UI that will set timed values
        static ztimedmap gTimedZoneMap;

};

/**
 * User Interface Item: abstract definition
 */

class uiItem
{
    protected:
          
        GUI* fGUI;
        FAUSTFLOAT* fZone;
        FAUSTFLOAT fCache;

        uiItem(GUI* ui, FAUSTFLOAT* zone):fGUI(ui), fZone(zone), fCache(FAUSTFLOAT(-123456.654321))
        { 
            ui->registerZone(zone, this); 
        }

    public:

        virtual ~uiItem() 
        {}

        void modifyZone(FAUSTFLOAT v) 	
        { 
            fCache = v;
            if (*fZone != v) {
                *fZone = v;
                fGUI->updateZone(fZone);
            }
        }
                
        FAUSTFLOAT cache() { return fCache; }
        virtual void reflectZone() = 0;
};

/**
 * User Interface item owned (and so deleted) by external code
 */

class uiOwnedItem : public uiItem {
    
    protected:
    
        uiOwnedItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {}
    
     public:
    
        virtual ~uiOwnedItem()
        {}
    
        virtual void reflectZone() {}
};

/**
 * Callback Item
 */

struct uiCallbackItem : public uiItem {
    
	uiCallback fCallback;
	void* fData;
	
	uiCallbackItem(GUI* ui, FAUSTFLOAT* zone, uiCallback foo, void* data) 
			: uiItem(ui, zone), fCallback(foo), fData(data) {}
	
	virtual void reflectZone() 
    {		
		FAUSTFLOAT v = *fZone;
		fCache = v; 
		fCallback(v, fData);	
	}
};

/**
 * Base class for timed items
 */

// For precise timestamped control
struct DatedControl {
    
    double fDate;
    FAUSTFLOAT fValue;
    
    DatedControl(double d = 0., FAUSTFLOAT v = FAUSTFLOAT(0)):fDate(d), fValue(v) {}
    
};

class uiTimedItem : public uiItem
{
    
    protected:
        
        bool fDelete;
        
    public:
        
        uiTimedItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {
            if (GUI::gTimedZoneMap.find(fZone) == GUI::gTimedZoneMap.end()) {
                GUI::gTimedZoneMap[fZone] = ringbuffer_create(8192);
                fDelete = true;
            } else {
                fDelete = false;
            }
        }
        
        virtual ~uiTimedItem()
        {
            ztimedmap::iterator it;
            if (fDelete && ((it = GUI::gTimedZoneMap.find(fZone)) != GUI::gTimedZoneMap.end())) {
                ringbuffer_free((*it).second);
                GUI::gTimedZoneMap.erase(it);
            }
        }
        
        virtual void modifyZone(double date, FAUSTFLOAT v)
        {
            size_t res;
            DatedControl dated_val(date, v);
            if ((res = ringbuffer_write(GUI::gTimedZoneMap[fZone], (const char*)&dated_val, sizeof(DatedControl))) != sizeof(DatedControl)) {
                std::cerr << "ringbuffer_write error DatedControl" << std::endl;
            }
        }
    
};

/**
 * Allows to group a set of zones
 */

class uiGroupItem : public uiItem
{
    protected:
    
        std::vector<FAUSTFLOAT*> fZoneMap;

    public:
    
        uiGroupItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {}
        virtual ~uiGroupItem() 
        {}
        
        virtual void reflectZone() 
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            
            // Update all zones of the same group
            std::vector<FAUSTFLOAT*>::iterator it;
            for (it = fZoneMap.begin(); it != fZoneMap.end(); it++) {
                (*(*it)) = v;
            }
        }
        
        void addZone(FAUSTFLOAT* zone) { fZoneMap.push_back(zone); }

};

/**
 * Update all user items reflecting zone z
 */

inline void GUI::updateZone(FAUSTFLOAT* z)
{
	FAUSTFLOAT v = *z;
	clist* l = fZoneMap[z];
	for (clist::iterator c = l->begin(); c != l->end(); c++) {
		if ((*c)->cache() != v) (*c)->reflectZone();
	}
}

/**
 * Update all user items not up to date
 */

inline void GUI::updateAllZones()
{
	for (zmap::iterator m = fZoneMap.begin(); m != fZoneMap.end(); m++) {
		FAUSTFLOAT* z = m->first;
		clist*	l = m->second;
        if (z) {
            FAUSTFLOAT v = *z;
            for (clist::iterator c = l->begin(); c != l->end(); c++) {
                if ((*c)->cache() != v) (*c)->reflectZone();
            }
        }
	}
}

inline void GUI::addCallback(FAUSTFLOAT* zone, uiCallback foo, void* data) 
{ 
	new uiCallbackItem(this, zone, foo, data); 
};

inline clist::~clist() 
{
    std::list<uiItem*>::iterator it;
    for (it = begin(); it != end(); it++) {
        uiOwnedItem* owned = dynamic_cast<uiOwnedItem*>(*it);
        // owned items are deleted by external code
        if (!owned) {
            delete (*it);
        }
    }
}

#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef FAUST_MIDIUI_H
#define FAUST_MIDIUI_H

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <cstdlib>
#include <cmath>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __midi__
#define __midi__

#include <vector>
#include <string>
#include <algorithm>

class MapUI;

//----------------------------------------------------------------
//  MIDI processor definition
//----------------------------------------------------------------

class midi {

    public:

        midi() {}
        virtual ~midi() {}

        // Additional time-stamped API for MIDI input
        virtual MapUI* keyOn(double, int channel, int pitch, int velocity)
        {
            return keyOn(channel, pitch, velocity);
        }
        
        virtual void keyOff(double, int channel, int pitch, int velocity = 127)
        {
            keyOff(channel, pitch, velocity);
        }
        
        virtual void pitchWheel(double, int channel, int wheel)
        {
            pitchWheel(channel, wheel);
        }
           
        virtual void ctrlChange(double, int channel, int ctrl, int value)
        {
            ctrlChange(channel, ctrl, value);
        }
       
        virtual void progChange(double, int channel, int pgm)
        {
            progChange(channel, pgm);
        }
        
        virtual void keyPress(double, int channel, int pitch, int press)
        {
            keyPress(channel, pitch, press);
        }
        
        virtual void chanPress(double date, int channel, int press)
        {
            chanPress(channel, press);
        }
       
        virtual void ctrlChange14bits(double, int channel, int ctrl, int value)
        {
            ctrlChange14bits(channel, ctrl, value);
        }

        // MIDI sync
        virtual void start_sync(double date)  {}
        virtual void stop_sync(double date)   {}
        virtual void clock(double date)  {}

        // Standard MIDI API
        virtual MapUI* keyOn(int channel, int pitch, int velocity)      { return 0; }
        virtual void keyOff(int channel, int pitch, int velocity)       {}
        virtual void keyPress(int channel, int pitch, int press)        {}
        virtual void chanPress(int channel, int press)                  {}
        virtual void ctrlChange(int channel, int ctrl, int value)       {}
        virtual void ctrlChange14bits(int channel, int ctrl, int value) {}
        virtual void pitchWheel(int channel, int wheel)                 {}
        virtual void progChange(int channel, int pgm)                   {}

        enum MidiStatus {

            // channel voice messages
            MIDI_NOTE_OFF = 0x80,
            MIDI_NOTE_ON = 0x90,
            MIDI_CONTROL_CHANGE = 0xB0,
            MIDI_PROGRAM_CHANGE = 0xC0,
            MIDI_PITCH_BEND = 0xE0,
            MIDI_AFTERTOUCH = 0xD0,         // aka channel pressure
            MIDI_POLY_AFTERTOUCH = 0xA0,    // aka key pressure
            MIDI_CLOCK = 0xF8,
            MIDI_START = 0xFA,
            MIDI_STOP = 0xFC

        };

        enum MidiCtrl {

            ALL_NOTES_OFF = 123,
            ALL_SOUND_OFF = 120

        };
};

//----------------------------------------------------------------
//  Base class for MIDI API handling
//----------------------------------------------------------------

class midi_handler : public midi {

    protected:

        std::vector<midi*> fMidiInputs;
        std::string fName;

    public:

        midi_handler(const std::string& name = "MIDIHandler"):fName(name) {}
        virtual ~midi_handler() {}

        void addMidiIn(midi* midi_dsp) { if (midi_dsp) fMidiInputs.push_back(midi_dsp); }
        void removeMidiIn(midi* midi_dsp)
        {
            std::vector<midi*>::iterator it = std::find(fMidiInputs.begin(), fMidiInputs.end(), midi_dsp);
            if (it != fMidiInputs.end()) {
                fMidiInputs.erase(it);
            }
        }

        virtual bool start_midi() { return true; }
        virtual void stop_midi() {}
    
        void setName(const std::string& name) { fName = name; }
        std::string getName() { return fName; }
        
        void handleSync(double time, int type)
        {
            if (type == MIDI_CLOCK) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->clock(time);
                }
            } else if (type == MIDI_START) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->start_sync(time);
                }
            } else if (type == MIDI_STOP) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->stop_sync(time);
                }
            }
        }

        void handleData1(double time, int type, int channel, int data1)
        {
            if (type == MIDI_PROGRAM_CHANGE) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->progChange(time, channel, data1);
                }
            } else if (type == MIDI_AFTERTOUCH) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->chanPress(time, channel, data1);
                }
            }
        }

        void handleData2(double time, int type, int channel, int data1, int data2)
        {
            if (type == MIDI_NOTE_OFF || ((type == MIDI_NOTE_ON) && (data2 == 0))) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyOff(time, channel, data1, data2);
                }
            } else if (type == MIDI_NOTE_ON) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyOn(time, channel, data1, data2);
                }
            } else if (type == MIDI_CONTROL_CHANGE) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->ctrlChange(time, channel, data1, data2);
                }
            } else if (type == MIDI_PITCH_BEND) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->pitchWheel(time, channel, (data2 * 128.0) + data1);
                }
            } else if (type == MIDI_POLY_AFTERTOUCH) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyPress(time, channel, data1, data2);
                }
            }
        }

};

#endif // __midi__
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __ValueConverter__
#define __ValueConverter__

/***************************************************************************************
								ValueConverter.h
							    (GRAME, © 2015)

Set of conversion objects used to map user interface values (for example a gui slider
delivering values between 0 and 1) to faust values (for example a vslider between
20 and 20000) using a log scale.

-- Utilities

Range(lo,hi) : clip a value x between lo and hi
Interpolator(lo,hi,v1,v2) : Maps a value x between lo and hi to a value y between v1 and v2
Interpolator3pt(lo,mi,hi,v1,vm,v2) : Map values between lo mid hi to values between v1 vm v2

-- Value Converters

ValueConverter::ui2faust(x)
ValueConverter::faust2ui(x)

-- ValueConverters used for sliders depending of the scale

LinearValueConverter(umin, umax, fmin, fmax)
LogValueConverter(umin, umax, fmin, fmax)
ExpValueConverter(umin, umax, fmin, fmax)

-- ValueConverters used for accelerometers based on 3 points

AccUpConverter(amin, amid, amax, fmin, fmid, fmax)		-- curve 0
AccDownConverter(amin, amid, amax, fmin, fmid, fmax)	-- curve 1
AccUpDownConverter(amin, amid, amax, fmin, fmid, fmax)	-- curve 2
AccDownUpConverter(amin, amid, amax, fmin, fmid, fmax)	-- curve 3

-- lists of ZoneControl are used to implement accelerometers metadata for each axes

ZoneControl(zone, valueConverter) : a zone with an accelerometer data converter

-- ZoneReader are used to implement screencolor metadata

ZoneReader(zone, valueConverter) : a zone with a data converter

****************************************************************************************/

#include <float.h>
#include <algorithm>    // std::max
#include <cmath>
#include <vector>
#include <assert.h>

//--------------------------------------------------------------------------------------
// Interpolator(lo,hi,v1,v2)
// Maps a value x between lo and hi to a value y between v1 and v2
// y = v1 + (x-lo)/(hi-lo)*(v2-v1)
// y = v1 + (x-lo) * coef   		with coef = (v2-v1)/(hi-lo)
// y = v1 + x*coef - lo*coef
// y = v1 - lo*coef + x*coef
// y = offset + x*coef				with offset = v1 - lo*coef
//--------------------------------------------------------------------------------------
class Interpolator
{
    private:

        //--------------------------------------------------------------------------------------
        // Range(lo,hi) clip a value between lo and hi
        //--------------------------------------------------------------------------------------
        struct Range
        {
            double fLo;
            double fHi;

            Range(double x, double y) : fLo(std::min<double>(x,y)), fHi(std::max<double>(x,y)) {}
            double operator()(double x) { return (x<fLo) ? fLo : (x>fHi) ? fHi : x; }
        };


        Range fRange;
        double fCoef;
        double fOffset;

    public:

        Interpolator(double lo, double hi, double v1, double v2) : fRange(lo,hi)
        {
            if (hi != lo) {
                // regular case
                fCoef = (v2-v1)/(hi-lo);
                fOffset = v1 - lo*fCoef;
            } else {
                // degenerate case, avoids division by zero
                fCoef = 0;
                fOffset = (v1+v2)/2;
            }
        }
        double operator()(double v)
        {
            double x = fRange(v);
            return  fOffset + x*fCoef;
        }

        void getLowHigh(double& amin, double& amax)
        {
            amin = fRange.fLo;
            amax = fRange.fHi;
        }
};

//--------------------------------------------------------------------------------------
// Interpolator3pt(lo,mi,hi,v1,vm,v2)
// Map values between lo mid hi to values between v1 vm v2
//--------------------------------------------------------------------------------------
class Interpolator3pt
{

    private:

        Interpolator fSegment1;
        Interpolator fSegment2;
        double fMid;

    public:

        Interpolator3pt(double lo, double mi, double hi, double v1, double vm, double v2) :
            fSegment1(lo, mi, v1, vm),
            fSegment2(mi, hi, vm, v2),
            fMid(mi) {}
        double operator()(double x) { return  (x < fMid) ? fSegment1(x) : fSegment2(x); }

        void getMappingValues(double& amin, double& amid, double& amax)
        {
            fSegment1.getLowHigh(amin, amid);
            fSegment2.getLowHigh(amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Abstract ValueConverter class. Converts values between UI and Faust representations
//--------------------------------------------------------------------------------------
class ValueConverter
{

    public:

        virtual ~ValueConverter() {}
        virtual double ui2faust(double x) = 0;
        virtual double faust2ui(double x) = 0;
};

//--------------------------------------------------------------------------------------
// Linear conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class LinearValueConverter : public ValueConverter
{

    private:

        Interpolator fUI2F;
        Interpolator fF2UI;

    public:

        LinearValueConverter(double umin, double umax, double fmin, double fmax) :
            fUI2F(umin,umax,fmin,fmax), fF2UI(fmin,fmax,umin,umax)
        {}

        LinearValueConverter() :
            fUI2F(0.,0.,0.,0.), fF2UI(0.,0.,0.,0.)
        {}
        virtual double ui2faust(double x) {	return fUI2F(x); }
        virtual double faust2ui(double x) {	return fF2UI(x); }

};

//--------------------------------------------------------------------------------------
// Logarithmic conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class LogValueConverter : public LinearValueConverter
{

    public:

        LogValueConverter(double umin, double umax, double fmin, double fmax) :
        LinearValueConverter(umin, umax, log(std::max<double>(DBL_MIN, fmin)), std::log(std::max<double>(DBL_MIN, fmax)))
        {}

        virtual double ui2faust(double x) 	{ return std::exp(LinearValueConverter::ui2faust(x)); }
        virtual double faust2ui(double x)	{ return LinearValueConverter::faust2ui(std::log(std::max<double>(x, DBL_MIN))); }

};

//--------------------------------------------------------------------------------------
// Exponential conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class ExpValueConverter : public LinearValueConverter
{

    public:

        ExpValueConverter(double umin, double umax, double fmin, double fmax) :
            LinearValueConverter(umin, umax, exp(fmin), exp(fmax))
        {}

        virtual double ui2faust(double x) { return std::log(LinearValueConverter::ui2faust(x)); }
        virtual double faust2ui(double x) { return LinearValueConverter::faust2ui(std::exp(x)); }

};

//--------------------------------------------------------------------------------------
// A converter than can be updated
//--------------------------------------------------------------------------------------

class UpdatableValueConverter : public ValueConverter {

    protected:

        bool fActive;

    public:

        UpdatableValueConverter():fActive(true)
        {}
        virtual ~UpdatableValueConverter()
        {}

        virtual void setMappingValues(double amin, double amid, double amax, double min, double init, double max) = 0;
        virtual void getMappingValues(double& amin, double& amid, double& amax) = 0;

        void setActive(bool on_off) { fActive = on_off; }
        bool getActive() { return fActive; }

};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using an Up curve (curve 0)
//--------------------------------------------------------------------------------------
class AccUpConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt fA2F;
        Interpolator3pt fF2A;

    public:

        AccUpConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmin,fmid,fmax),
            fF2A(fmin,fmid,fmax,amin,amid,amax)
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
            //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccUpConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmin,fmid,fmax);
            fF2A = Interpolator3pt(fmin,fmid,fmax,amin,amid,amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }

};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using a Down curve (curve 1)
//--------------------------------------------------------------------------------------
class AccDownConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt	fA2F;
        Interpolator3pt	fF2A;

    public:

        AccDownConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmax,fmid,fmin),
            fF2A(fmin,fmid,fmax,amax,amid,amin)
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
             //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccDownConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmax,fmid,fmin);
            fF2A = Interpolator3pt(fmin,fmid,fmax,amax,amid,amin);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using an Up-Down curve (curve 2)
//--------------------------------------------------------------------------------------
class AccUpDownConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt	fA2F;
        Interpolator fF2A;

    public:

        AccUpDownConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmin,fmax,fmin),
            fF2A(fmin,fmax,amin,amax)				// Special, pseudo inverse of a non monotone function
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
             //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccUpDownConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmin,fmax,fmin);
            fF2A = Interpolator(fmin,fmax,amin,amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using a Down-Up curve (curve 3)
//--------------------------------------------------------------------------------------
class AccDownUpConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt	fA2F;
        Interpolator fF2A;

    public:

        AccDownUpConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmax,fmin,fmax),
            fF2A(fmin,fmax,amin,amax)				// Special, pseudo inverse of a non monotone function
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
            //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccDownUpConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmax,fmin,fmax);
            fF2A = Interpolator(fmin,fmax,amin,amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Base class for ZoneControl
//--------------------------------------------------------------------------------------
class ZoneControl
{

    protected:

        FAUSTFLOAT*	fZone;

    public:

        ZoneControl(FAUSTFLOAT* zone) : fZone(zone) {}
        virtual ~ZoneControl() {}

        virtual void update(double v) {}

        virtual void setMappingValues(int curve, double amin, double amid, double amax, double min, double init, double max) {}
        virtual void getMappingValues(double& amin, double& amid, double& amax) {}

        FAUSTFLOAT* getZone() { return fZone; }

        virtual void setActive(bool on_off) {}
        virtual bool getActive() { return false; }

        virtual int getCurve() { return -1; }

};

//--------------------------------------------------------------------------------------
//  Useful to implement accelerometers metadata as a list of ZoneControl for each axes
//--------------------------------------------------------------------------------------
class ConverterZoneControl : public ZoneControl
{

    private:

        ValueConverter* fValueConverter;

    public:

        ConverterZoneControl(FAUSTFLOAT* zone, ValueConverter* valueConverter) : ZoneControl(zone), fValueConverter(valueConverter) {}
        virtual ~ConverterZoneControl() { delete fValueConverter; } // Assuming fValueConverter is not kept elsewhere...

        void update(double v) { *fZone = fValueConverter->ui2faust(v); }

        ValueConverter* getConverter() { return fValueConverter; }

};

//--------------------------------------------------------------------------------------
// Association of a zone and a four value converter, each one for each possible curve.
// Useful to implement accelerometers metadata as a list of ZoneControl for each axes
//--------------------------------------------------------------------------------------
class CurveZoneControl : public ZoneControl
{

    private:

        std::vector<UpdatableValueConverter*> fValueConverters;
        int fCurve;

    public:

        CurveZoneControl(FAUSTFLOAT* zone, int curve, double amin, double amid, double amax, double min, double init, double max) : ZoneControl(zone), fCurve(0)
        {
            assert(curve >= 0 && curve <= 3);
            fValueConverters.push_back(new AccUpConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccDownConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccUpDownConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccDownUpConverter(amin, amid, amax, min, init, max));
            fCurve = curve;
        }
        virtual ~CurveZoneControl()
        {
            std::vector<UpdatableValueConverter*>::iterator it;
            for (it = fValueConverters.begin(); it != fValueConverters.end(); it++) {
                delete(*it);
            }
        }
        void update(double v) { if (fValueConverters[fCurve]->getActive()) *fZone = fValueConverters[fCurve]->ui2faust(v); }

        void setMappingValues(int curve, double amin, double amid, double amax, double min, double init, double max)
        {
            fValueConverters[curve]->setMappingValues(amin, amid, amax, min, init, max);
            fCurve = curve;
        }

        void getMappingValues(double& amin, double& amid, double& amax)
        {
            fValueConverters[fCurve]->getMappingValues(amin, amid, amax);
        }

        void setActive(bool on_off)
        {
            std::vector<UpdatableValueConverter*>::iterator it;
            for (it = fValueConverters.begin(); it != fValueConverters.end(); it++) {
                (*it)->setActive(on_off);
            }
        }

        int getCurve() { return fCurve; }
};

class ZoneReader
{

    private:

        FAUSTFLOAT* fZone;
        Interpolator fInterpolator;

    public:

        ZoneReader(FAUSTFLOAT* zone, double lo, double hi) : fZone(zone), fInterpolator(lo, hi, 0, 255) {}

        virtual ~ZoneReader() {}

        int getValue()
        {
            if (fZone != 0) {
                return (int)fInterpolator(*fZone);
            } else {
                return 127;
            }
        }

};

#endif

#ifdef _MSC_VER
#define gsscanf sscanf_s
#else
#define gsscanf sscanf
#endif

/*****************************************************************************
* Helper code for MIDI meta and polyphonic 'nvoices' parsing
******************************************************************************/

struct MidiMeta : public Meta, public std::map<std::string, std::string>
{
    void declare(const char* key, const char* value)
    {
        (*this)[key] = value;
    }
    
    const std::string get(const char* key, const char* def)
    {
        if (this->find(key) != this->end()) {
            return (*this)[key];
        } else {
            return def;
        }
    }
    
    static void analyse(dsp* tmp_dsp, bool& midi_sync, int& nvoices)
    {
        JSONUI jsonui;
        tmp_dsp->buildUserInterface(&jsonui);
        std::string json = jsonui.JSON();
        midi_sync = ((json.find("midi") != std::string::npos) &&
                     ((json.find("start") != std::string::npos) ||
                      (json.find("stop") != std::string::npos) ||
                      (json.find("clock") != std::string::npos)));
    
    #if defined(NVOICES) && NVOICES!=NUM_VOICES
        nvoices = NVOICES;
    #else
        MidiMeta meta;
        tmp_dsp->metadata(&meta);
        std::string numVoices = meta.get("nvoices", "0");
        nvoices = std::atoi(numVoices.c_str());
        if (nvoices < 0) nvoices = 0;
    #endif
    }
};

/*******************************************************************************
 * MidiUI : Faust User Interface
 * This class decodes MIDI meta data and maps incoming MIDI messages to them.
 * Currently ctrl, keyon/keyoff, keypress, pgm, chanpress, pitchwheel/pitchbend
 * start/stop/clock meta data is handled.
 ******************************************************************************/

class uiMidi {
    
    protected:
        
        midi* fMidiOut;
        bool fInputCtrl;
        
    public:
        
        uiMidi(midi* midi_out, bool input):fMidiOut(midi_out), fInputCtrl(input)
        {}
        virtual ~uiMidi()
        {}
    
};

class uiMidiItem : public uiMidi, public uiItem {
    
    public:
        
        uiMidiItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidi(midi_out, input), uiItem(ui, zone)
        {}
        virtual ~uiMidiItem()
        {}
    
        virtual void reflectZone() {}
    
};

class uiMidiTimedItem : public uiMidi, public uiTimedItem {
    
    public:
        
        uiMidiTimedItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidi(midi_out, input), uiTimedItem(ui, zone)
        {}
        virtual ~uiMidiTimedItem()
        {}
    
        virtual void reflectZone() {}
    
};

// MIDI sync

class uiMidiStart : public uiMidiTimedItem
{
  
    public:
    
        uiMidiStart(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiStart()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(0)) {
                fMidiOut->start_sync(0);
            }
        }
        
};

class uiMidiStop : public uiMidiTimedItem
{
  
    public:
    
        uiMidiStop(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiStop()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(1)) {
                fMidiOut->stop_sync(0);
            }
        }
};

class uiMidiClock : public uiMidiTimedItem
{

    private:
        
        bool fState;
  
    public:
    
        uiMidiClock(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input), fState(false)
        {}
        virtual ~uiMidiClock()
        {}
    
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->clock(0);
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                fState = !fState;
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fState));
            }
        }

};

class uiMidiProgChange : public uiMidiItem
{
    
    private:
        
        int fPgm;
  
    public:
    
        uiMidiProgChange(midi* midi_out, int pgm, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fPgm(pgm)
        {}
        virtual ~uiMidiProgChange()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(0)) {
                fMidiOut->progChange(0, fPgm);
            }
        }
        
};

class uiMidiChanPress : public uiMidiItem
{
    private:
        
        int fPress;
  
    public:
    
        uiMidiChanPress(midi* midi_out, int press, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fPress(press)
        {}
        virtual ~uiMidiChanPress()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(0)) {
                fMidiOut->chanPress(0, fPress);
            }
        }
        
};

class uiMidiCtrlChange : public uiMidiItem
{
    private:
    
        int fCtrl;
        LinearValueConverter fConverter;
 
    public:
    
        uiMidiCtrlChange(midi* midi_out, int ctrl, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fCtrl(ctrl), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiCtrlChange()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->ctrlChange(0, fCtrl, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
 
};

class uiMidiPitchWheel : public uiMidiItem
{

    private:
    	
		// currently, the range is of pitchwheel if fixed (-2/2 semitones)
        FAUSTFLOAT wheel2bend(float v)
        {
            return std::pow(2.0,(v/16383.0*4-2)/12);
        }

        int bend2wheel(float v)
        {
            return (int)((12*std::log(v)/std::log(2.0)+2)/4*16383);
        }
 
    public:
    
        uiMidiPitchWheel(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiPitchWheel()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->pitchWheel(0, bend2wheel(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(wheel2bend(v));
            }
        }
 
};

class uiMidiKeyOn : public uiMidiItem
{

    private:
        
        int fKeyOn;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyOn(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fKeyOn(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyOn()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyOn(0, fKeyOn, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
        
};

class uiMidiKeyOff : public uiMidiItem
{

    private:
        
        int fKeyOff;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyOff(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fKeyOff(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyOff()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyOff(0, fKeyOff, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
        
};


class uiMidiKeyPress : public uiMidiItem
{

    private:
    
        int fKey;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyPress(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fKey(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyPress()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyPress(0, fKey, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
        
};

class MapUI;

class MidiUI : public GUI, public midi
{

    protected:
    
        std::map <int, std::vector<uiMidiCtrlChange*> > fCtrlChangeTable;
        std::map <int, std::vector<uiMidiProgChange*> > fProgChangeTable;
        std::map <int, std::vector<uiMidiChanPress*> >  fChanPressTable;
        std::map <int, std::vector<uiMidiKeyOn*> >      fKeyOnTable;
        std::map <int, std::vector<uiMidiKeyOff*> >     fKeyOffTable;
        std::map <int, std::vector<uiMidiKeyOn*> >      fKeyTable;
        std::map <int, std::vector<uiMidiKeyPress*> >   fKeyPressTable;
        std::vector<uiMidiPitchWheel*>                  fPitchWheelTable;
        
        std::vector<uiMidiStart*>   fStartTable;
        std::vector<uiMidiStop*>    fStopTable;
        std::vector<uiMidiClock*>   fClockTable;
        
        std::vector<std::pair <std::string, std::string> > fMetaAux;
        
        midi_handler* fMidiHandler;
        bool fDelete;
    
        void addGenericZone(FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
        {
            if (fMetaAux.size() > 0) {
                for (size_t i = 0; i < fMetaAux.size(); i++) {
                    unsigned num;
                    if (fMetaAux[i].first == "midi") {
                        if (gsscanf(fMetaAux[i].second.c_str(), "ctrl %u", &num) == 1) {
                            fCtrlChangeTable[num].push_back(new uiMidiCtrlChange(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyon %u", &num) == 1) {
                            fKeyOnTable[num].push_back(new uiMidiKeyOn(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyoff %u", &num) == 1) {
                            fKeyOffTable[num].push_back(new uiMidiKeyOff(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "key %u", &num) == 1) {
                            fKeyTable[num].push_back(new uiMidiKeyOn(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keypress %u", &num) == 1) {
                            fKeyPressTable[num].push_back(new uiMidiKeyPress(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "pgm %u", &num) == 1) {
                            fProgChangeTable[num].push_back(new uiMidiProgChange(fMidiHandler, num, this, zone, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "chanpress %u", &num) == 1) {
                            fChanPressTable[num].push_back(new uiMidiChanPress(fMidiHandler, num, this, zone, input));
                        } else if (strcmp(fMetaAux[i].second.c_str(), "pitchwheel") == 0 
                            || strcmp(fMetaAux[i].second.c_str(), "pitchbend") == 0) {
                            fPitchWheelTable.push_back(new uiMidiPitchWheel(fMidiHandler, this, zone, input));
                        // MIDI sync
                        } else if (strcmp(fMetaAux[i].second.c_str(), "start") == 0) {
                            fStartTable.push_back(new uiMidiStart(fMidiHandler, this, zone, input));
                        } else if (strcmp(fMetaAux[i].second.c_str(), "stop") == 0) {
                            fStopTable.push_back(new uiMidiStop(fMidiHandler, this, zone, input));
                        } else if (strcmp(fMetaAux[i].second.c_str(), "clock") == 0) {
                            fClockTable.push_back(new uiMidiClock(fMidiHandler, this, zone, input));
                        }
                    }
                }
            }
            fMetaAux.clear();
        }

    public:
    
        MidiUI():fMidiHandler(NULL), fDelete(false)
        {}

        MidiUI(midi_handler* midi_handler, bool delete_handler = false)
        {
            fMidiHandler = midi_handler;
            fMidiHandler->addMidiIn(this);
            fDelete = delete_handler;
        }
 
        virtual ~MidiUI() 
        { 
            fMidiHandler->removeMidiIn(this);
            if (fDelete) delete fMidiHandler;
        }
        
        bool run() { return fMidiHandler->start_midi(); }
        void stop() { fMidiHandler->stop_midi(); }
        
        void addMidiIn(midi* midi_dsp) { fMidiHandler->addMidiIn(midi_dsp); }
        void removeMidiIn(midi* midi_dsp) { fMidiHandler->removeMidiIn(midi_dsp); }
      
        // -- active widgets
        
        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericZone(zone, FAUSTFLOAT(0), FAUSTFLOAT(1));
        }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericZone(zone, FAUSTFLOAT(0), FAUSTFLOAT(1));
        }
        
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {
            addGenericZone(zone, min, max, false);
        }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            addGenericZone(zone, min, max, false);
        }

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            fMetaAux.push_back(std::make_pair(key, val));
        }
        
        // -- MIDI API 
        
        MapUI* keyOn(double date, int channel, int note, int velocity)
        {
            if (fKeyOnTable.find(note) != fKeyOnTable.end()) {
                for (unsigned int i = 0; i < fKeyOnTable[note].size(); i++) {
                    fKeyOnTable[note][i]->modifyZone(FAUSTFLOAT(velocity));
                }
            }
            // If note is in fKeyTable, handle it as a keyOn
            if (fKeyTable.find(note) != fKeyTable.end()) {
                for (unsigned int i = 0; i < fKeyTable[note].size(); i++) {
                    fKeyTable[note][i]->modifyZone(FAUSTFLOAT(velocity));
                }
            }
            return 0;
        }
        
        void keyOff(double date, int channel, int note, int velocity)
        {
            if (fKeyOffTable.find(note) != fKeyOffTable.end()) {
                for (unsigned int i = 0; i < fKeyOffTable[note].size(); i++) {
                    fKeyOffTable[note][i]->modifyZone(FAUSTFLOAT(velocity));
                }
            }
            // If note is in fKeyTable, handle it as a keyOff with a 0 velocity
            if (fKeyTable.find(note) != fKeyTable.end()) {
                for (unsigned int i = 0; i < fKeyTable[note].size(); i++) {
                    fKeyTable[note][i]->modifyZone(0);
                }
            }
        }
           
        void ctrlChange(double date, int channel, int ctrl, int value)
        {
            if (fCtrlChangeTable.find(ctrl) != fCtrlChangeTable.end()) {
                for (unsigned int i = 0; i < fCtrlChangeTable[ctrl].size(); i++) {
                    fCtrlChangeTable[ctrl][i]->modifyZone(FAUSTFLOAT(value));
                }
            } 
        }
        
        void progChange(double date, int channel, int pgm)
        {
            if (fProgChangeTable.find(pgm) != fProgChangeTable.end()) {
                for (unsigned int i = 0; i < fProgChangeTable[pgm].size(); i++) {
                    fProgChangeTable[pgm][i]->modifyZone(FAUSTFLOAT(1));
                }
            } 
        }
        
        void pitchWheel(double date, int channel, int wheel) 
        {
            for (unsigned int i = 0; i < fPitchWheelTable.size(); i++) {
                fPitchWheelTable[i]->modifyZone(FAUSTFLOAT(wheel));
            }
        }
        
        void keyPress(double date, int channel, int pitch, int press) 
        {
            if (fKeyPressTable.find(pitch) != fKeyPressTable.end()) {
                for (unsigned int i = 0; i < fKeyPressTable[pitch].size(); i++) {
                    fKeyPressTable[pitch][i]->modifyZone(FAUSTFLOAT(press));
                }
            } 
        }
        
        void chanPress(double date, int channel, int press)
        {
            if (fChanPressTable.find(press) != fChanPressTable.end()) {
                for (unsigned int i = 0; i < fChanPressTable[press].size(); i++) {
                    fChanPressTable[press][i]->modifyZone(FAUSTFLOAT(1));
                }
            } 
        }
        
        void ctrlChange14bits(double date, int channel, int ctrl, int value) {}
        
        // MIDI sync
        
        void start_sync(double date)
        {
            for (unsigned int i = 0; i < fStartTable.size(); i++) {
                fStartTable[i]->modifyZone(date, FAUSTFLOAT(1));
            }
        }
        
        void stop_sync(double date)
        {
            for (unsigned int i = 0; i < fStopTable.size(); i++) {
                fStopTable[i]->modifyZone(date, FAUSTFLOAT(0));
            }
        }
        
        void clock(double date)
        {
            for (unsigned int i = 0; i < fClockTable.size(); i++) {
                fClockTable[i]->modifyZone(date, FAUSTFLOAT(1));
            }
        }
};

#endif // FAUST_MIDIUI_H
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __poly_dsp__
#define __poly_dsp__

#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <ostream>
#include <sstream>
#include <vector>
#include <limits.h>
#include <float.h>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef FAUST_MAPUI_H
#define FAUST_MAPUI_H

#include <vector>
#include <map>
#include <string>


/*******************************************************************************
 * MapUI : Faust User Interface
 * This class creates a map of complete hierarchical path and zones for each UI items.
 ******************************************************************************/

class MapUI : public UI, public PathBuilder
{
    
    protected:
    
        // Complete path map
        std::map<std::string, FAUSTFLOAT*> fPathZoneMap;
    
        // Label zone map
        std::map<std::string, FAUSTFLOAT*> fLabelZoneMap;
    
    public:
        
        MapUI() {};
        virtual ~MapUI() {};
        
        // -- widget's layouts
        void openTabBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openHorizontalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openVerticalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void closeBox()
        {
            fControlsLevel.pop_back();
        }
        
        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        
        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}
        
        // -- metadata declarations
        void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {}
        
        // set/get
        void setParamValue(const std::string& path, FAUSTFLOAT value)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                *fPathZoneMap[path] = value;
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                *fLabelZoneMap[path] = value;
            }
        }
        
        FAUSTFLOAT getParamValue(const std::string& path)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                return *fPathZoneMap[path];
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                return *fLabelZoneMap[path];
            } else {
                return FAUSTFLOAT(0);
            }
        }
    
        // map access 
        std::map<std::string, FAUSTFLOAT*>& getMap() { return fPathZoneMap; }
        
        int getParamsCount() { return int(fPathZoneMap.size()); }
        
        std::string getParamAddress(int index)
        { 
            std::map<std::string, FAUSTFLOAT*>::iterator it = fPathZoneMap.begin();
            while (index-- > 0 && it++ != fPathZoneMap.end()) {}
            return (*it).first;
        }
    
        std::string getParamAddress(FAUSTFLOAT* zone)
        {
            std::map<std::string, FAUSTFLOAT*>::iterator it = fPathZoneMap.begin();
            do {
                if ((*it).second == zone) return (*it).first;
            }
            while (it++ != fPathZoneMap.end());
            return "";
        }
};

#endif // FAUST_MAPUI_H
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __proxy_dsp__
#define __proxy_dsp__

#include <vector>
#include <map>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __JSONUIDecoder__
#define __JSONUIDecoder__

#include <vector>
#include <map>
#include <utility>
#include <assert.h>
#include <cstdlib>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef SIMPLEPARSER_H
#define SIMPLEPARSER_H

// ---------------------------------------------------------------------
//                          Simple Parser
// A parser returns true if it was able to parse what it is
// supposed to parse and advance the pointer. Otherwise it returns false
// and the pointer is not advanced so that another parser can be tried.
// ---------------------------------------------------------------------

#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <ctype.h>

#ifndef _WIN32
# pragma GCC diagnostic ignored "-Wunused-function"
#endif

using namespace std;

struct itemInfo {
    std::string type;
    std::string label;
    std::string address;
    std::string index;
    std::string init;
    std::string min;
    std::string max;
    std::string step;
    std::vector<std::pair<std::string, std::string> > meta;
};

bool parseMenuList(const char*& p, vector<string>& names, vector<double>& values);
bool parseMenuItem(const char*& p, string& name, double& value);

void skipBlank(const char*& p);
bool parseChar(const char*& p, char x);
bool parseWord(const char*& p, const char* w);
bool parseString(const char*& p, char quote, string& s);
bool parseSQString(const char*& p, string& s);
bool parseDQString(const char*& p, string& s);
bool parseDouble(const char*& p, double& x);

// ---------------------------------------------------------------------
//
//                          IMPLEMENTATION
// 
// ---------------------------------------------------------------------

/**
 * @brief parseMenuList, parse a menu list {'low' : 440.0; 'mid' : 880.0; 'hi' : 1760.0}...
 * @param p the string to parse, then the remaining string
 * @param names the vector of names found
 * @param values the vector of values found
 * @return true if a menu list was found
 */
inline bool parseMenuList(const char*& p, vector<string>& names, vector<double>& values)
{
    vector<string> tmpnames;
    vector<double> tmpvalues;

    const char* saved = p;

    if (parseChar(p, '{')) {
        do {
            string n;
            double v;
            if (parseMenuItem(p, n, v)) {
                tmpnames.push_back(n);
                tmpvalues.push_back(v);
            } else {
                p = saved;
                return false;
            }
        } while (parseChar(p, ';'));
        if (parseChar(p, '}')) {
            // we suceeded
            names = tmpnames;
            values = tmpvalues;
            return true;
        }
    }
    p = saved;
    return false;
}

/**
 * @brief parseMenuItem, parse a menu item ...'low':440.0...
 * @param p the string to parse, then the remaining string
 * @param name the name found
 * @param value the value found
 * @return true if a nemu item was found
 */
inline bool parseMenuItem(const char*& p, string& name, double& value)
{
    const char* saved = p;
    if (parseSQString(p, name) && parseChar(p, ':') && parseDouble(p, value)) {
        return true;
    } else {
        p = saved;
        return false;
    }
}

// ---------------------------------------------------------------------
//                          Elementary parsers
// ---------------------------------------------------------------------

// Report a parsing error
static bool parseError(const char*& p, const char* errmsg)
{
    std::cerr << "Parse error : " << errmsg << " here : " << p << std::endl;
    return true;
}

// Parse character x, but don't report error if fails
static bool tryChar(const char*& p, char x)
{
    skipBlank(p);
    if (x == *p) {
        p++;
        return true;
    } else {
        return false;
    }
}

/**
 * @brief skipBlank : advance pointer p to the first non blank character
 * @param p the string to parse, then the remaining string
 */
inline void skipBlank(const char*& p)
{
    while (isspace(*p)) { p++; }
}

/**
 * @brief parseChar : parse a specific character x
 * @param p the string to parse, then the remaining string
 * @param x the character to recognize
 * @return true if x was found at the begin of p
 */
inline bool parseChar(const char*& p, char x)
{
    skipBlank(p);
    if (x == *p) {
        p++;
        return true;
    } else {
        return false;
    }
}

/**
 * @brief parseWord : parse a specific string w
 * @param p the string to parse, then the remaining string
 * @param w the string to recognize
 * @return true if string w was found at the begin of p
 */
inline bool parseWord(const char*& p, const char* w)
{
    skipBlank(p);
    const char* saved = p;
    while ((*w == *p) && (*w)) {++w; ++p;}
    if (*w) {
        p = saved;
        return false;
    } else {
        return true;
    }
}

/**
 * @brief parseDouble : parse number [s]dddd[.dddd] and store the result in x
 * @param p the string to parse, then the remaining string
 * @param x the float number found if any
 * @return true if a float number was found at the begin of p
 */
inline bool parseDouble(const char*& p, double& x)
{
    double sign = +1.0;    // sign of the number
    double ipart = 0;      // integral part of the number
    double dpart = 0;      // decimal part of the number before division
    double dcoef = 1.0;    // division factor for the decimal part

    bool valid = false;   // true if the number contains at least one digit
    skipBlank(p);
    const char* saved = p;  // to restore position if we fail

    if (parseChar(p, '+')) {
        sign = 1.0;
    } else if (parseChar(p, '-')) {
        sign = -1.0;
    }
    while (isdigit(*p)) {
        valid = true;
        ipart = ipart*10 + (*p - '0');
        p++;
    }
    if (parseChar(p, '.')) {
        while (isdigit(*p)) {
            valid = true;
            dpart = dpart*10 + (*p - '0');
            dcoef *= 10.0;
            p++;
        }
    }
    if (valid)  {
        x = sign*(ipart + dpart/dcoef);
    } else {
        p = saved;
    }
    return valid;
}

/**
 * @brief parseString, parse an arbitrary quoted string q...q and store the result in s
 * @param p the string to parse, then the remaining string
 * @param quote the character used to quote the string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
inline bool parseString(const char*& p, char quote, string& s)
{
    string str;
    skipBlank(p);
 
    const char* saved = p;
    if (*p++ == quote) {
        while ((*p != 0) && (*p != quote)) {
            str += *p++;
        }
        if (*p++ == quote) {
            s = str;
            return true;
        }
    }
    p = saved;
    return false;
}

/**
 * @brief parseSQString, parse a single quoted string '...' and store the result in s
 * @param p the string to parse, then the remaining string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
inline bool parseSQString(const char*& p, string& s)
{
    return parseString(p, '\'', s);
}

/**
 * @brief parseDQString, parse a double quoted string "..." and store the result in s
 * @param p the string to parse, then the remaining string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
inline bool parseDQString(const char*& p, string& s)
{
    return parseString(p, '"', s);
}

static bool parseMetaData(const char*& p, std::map<std::string, std::string>& metadatas)
{
    std::string metaKey, metaValue;
    if (parseChar(p, ':') && parseChar(p, '[')) {
        do { 
            if (parseChar(p, '{') && parseDQString(p, metaKey) && parseChar(p, ':') && parseDQString(p, metaValue) && parseChar(p, '}')) {
                metadatas[metaKey] = metaValue;
            }
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        return false;
    }
}

static bool parseItemMetaData(const char*& p, std::vector<std::pair<std::string, std::string> >& metadatas)
{
    std::string metaKey, metaValue;
    if (parseChar(p, ':') && parseChar(p, '[')) {
        do { 
            if (parseChar(p, '{') && parseDQString(p, metaKey) && parseChar(p, ':') && parseDQString(p, metaValue) && parseChar(p, '}')) {
                metadatas.push_back(std::make_pair(metaKey, metaValue));
            }
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse metadatas of the interface:
// "name" : "...", "inputs" : "...", "outputs" : "...", ...
// and store the result as key/value
//
static bool parseGlobalMetaData(const char*& p, std::string& key, std::string& value, std::map<std::string, std::string>& metadatas)
{
    if (parseDQString(p, key)) {
        if (key == "meta") {
            return parseMetaData(p, metadatas);
        } else {
            return parseChar(p, ':') && parseDQString(p, value);
        }
    } else {
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse gui:
// "type" : "...", "label" : "...", "address" : "...", ...
// and store the result in uiItems Vector
//
static bool parseUI(const char*& p, std::vector<itemInfo*>& uiItems, int& numItems)
{
    if (parseChar(p, '{')) {
        
        std::string label;
        std::string value;
        
        do {
            if (parseDQString(p, label)) {
                if (label == "type") {
                    if (uiItems.size() != 0) {
                        numItems++;
                    }
                    if (parseChar(p, ':') && parseDQString(p, value)) {   
                        itemInfo* item = new itemInfo;
                        item->type = value;
                        uiItems.push_back(item);
                    }
                }
                
                else if (label == "label") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->label = value;
                    }
                }
                
                else if (label == "address") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->address = value;
                    }
                }
                
                else if (label == "index") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->index = value;
                    }
                }
                
                else if (label == "meta") {
                    itemInfo* item = uiItems[numItems];
                    if (!parseItemMetaData(p, item->meta)) {
                        return false;
                    }
                }
                
                else if (label == "init") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->init = value;
                    }
                }
                
                else if (label == "min") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->min = value;
                    }
                }
                
                else if (label == "max") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->max = value;
                    }
                }
                
                else if (label == "step"){
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->step = value;
                    }
                }
                
                else if (label == "items") {
                    if (parseChar(p, ':') && parseChar(p, '[')) {
                        do { 
                            if (!parseUI(p, uiItems, numItems)) {
                                return false;
                            }
                        } while (tryChar(p, ','));
                        if (parseChar(p, ']')) {
                            itemInfo* item = new itemInfo;
                            item->type = "close";
                            uiItems.push_back(item);
                            numItems++;
                        }
                    }
                }
            } else {
                return false;
            }
            
        } while (tryChar(p, ','));
        
        return parseChar(p, '}');
    } else {
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse full JSON record describing a JSON/Faust interface :
// {"metadatas": "...", "ui": [{ "type": "...", "label": "...", "items": [...], "address": "...","init": "...", "min": "...", "max": "...","step": "..."}]}
//
// and store the result in map Metadatas and vector containing the items of the interface. Returns true if parsing was successfull.
//

inline bool parseJson(const char*& p, std::map<std::string, std::string>& metadatas, std::vector<itemInfo*>& uiItems)
{
    parseChar(p, '{');
    
    do {
        std::string key;
        std::string value;
        if (parseGlobalMetaData(p, key, value, metadatas)) {
            if (key != "meta") {
                // keep "name", "inputs", "outputs" key/value pairs
                metadatas[key] = value;
            }
        } else if (key == "ui") {
            int numItems = 0;
            parseChar(p, '[') && parseUI(p, uiItems, numItems);
        }
    } while (tryChar(p, ','));
    
    return parseChar(p, '}');
}

#endif // SIMPLEPARSER_H

#ifdef _WIN32
#include <windows.h>
#define snprintf _snprintf
#endif

inline FAUSTFLOAT STR2REAL(const std::string& s) { return (std::strtod(s.c_str(), NULL)); }

//-------------------------------------------------------------------
//  Decode a dsp JSON description and implement 'buildUserInterface'
//-------------------------------------------------------------------

typedef std::map<std::string, pair <int, FAUSTFLOAT*> > controlMap;

struct JSONUIDecoder {

    std::string fName;
    std::string fFileName;
    
    std::map<std::string, std::string> fMetadatas; 
    std::vector<itemInfo*> fUiItems;     
    
    FAUSTFLOAT* fInControl;
    FAUSTFLOAT* fOutControl;
    
    std::string fJSON;
    
    int fNumInputs, fNumOutputs; 
    int fInputItems, fOutputItems;
    
    std::string fVersion;
    std::string fOptions;
    
    int fDSPSize;
    
    controlMap fPathInputTable;     // [path, <index, zone>]
    controlMap fPathOutputTable;    // [path, <index, zone>]
    
    bool isInput(const string& type) { return (type == "vslider" || type == "hslider" || type == "nentry" || type == "button" || type == "checkbox"); }
    bool isOutput(const string& type) { return (type == "hbargraph" || type == "vbargraph"); }

    JSONUIDecoder(const std::string& json) 
    {
        fJSON = json;
        const char* p = fJSON.c_str();
        parseJson(p, fMetadatas, fUiItems);
        
        // fMetadatas will contain the "meta" section as well as <name : val>, <inputs : val>, <ouputs : val> pairs
        if (fMetadatas.find("name") != fMetadatas.end()) {
            fName = fMetadatas["name"];
            fMetadatas.erase("name");
        } else {
            fName = "";
        }
        
        if (fMetadatas.find("filename") != fMetadatas.end()) {
            fFileName = fMetadatas["filename"];
            fMetadatas.erase("filename");
        } else {
            fName = "";
        }
     
        if (fMetadatas.find("version") != fMetadatas.end()) {
            fVersion = fMetadatas["version"];
            fMetadatas.erase("version");
        } else {
            fVersion = "";
        }
        
        if (fMetadatas.find("options") != fMetadatas.end()) {
            fOptions = fMetadatas["options"];
            fMetadatas.erase("options");
        } else {
            fOptions = "";
        }
        
        if (fMetadatas.find("size") != fMetadatas.end()) {
            fDSPSize = std::atoi(fMetadatas["size"].c_str());
            fMetadatas.erase("size");
        } else {
            fDSPSize = -1;
        }
         
        if (fMetadatas.find("inputs") != fMetadatas.end()) {
            fNumInputs = std::atoi(fMetadatas["inputs"].c_str());
            fMetadatas.erase("inputs");
        } else {
            fNumInputs = -1;
        }
        
        if (fMetadatas.find("outputs") != fMetadatas.end()) {
            fNumOutputs = std::atoi(fMetadatas["outputs"].c_str());
            fMetadatas.erase("outputs");
        } else {
            fNumOutputs = -1;
        }
       
        fInputItems = 0;
        fOutputItems = 0;
        
        vector<itemInfo*>::iterator it;
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            string type = (*it)->type;
            if (isInput(type)) {
                fInputItems++;
            } else if (isOutput(type)) {
                fOutputItems++;          
            }
        }
        
        fInControl = new FAUSTFLOAT[fInputItems];
        fOutControl = new FAUSTFLOAT[fOutputItems];
        
        int counterIn = 0;
        int counterOut = 0;
        
        // Prepare the fPathTable and init zone
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            string type = (*it)->type;
            // Meta data declaration for input items
            if (isInput(type)) {
                if ((*it)->address != "") {
                    fPathInputTable[(*it)->address] = make_pair(std::atoi((*it)->index.c_str()), &fInControl[counterIn]);
                }
                fInControl[counterIn] = STR2REAL((*it)->init);
                counterIn++;
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                if ((*it)->address != "") {
                    fPathOutputTable[(*it)->address] = make_pair(std::atoi((*it)->index.c_str()), &fOutControl[counterOut]);
                }
                fOutControl[counterOut] = FAUSTFLOAT(0);
                counterOut++;
            }
        }
    }
    
    virtual ~JSONUIDecoder() 
    {
        vector<itemInfo*>::iterator it;
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            delete(*it);
        }
        delete [] fInControl;
        delete [] fOutControl;
    }
    
    void metadata(Meta* m)
    {
        std::map<std::string, std::string>::iterator it;
        for (it = fMetadatas.begin(); it != fMetadatas.end(); it++) {
            m->declare((*it).first.c_str(), (*it).second.c_str());
        }
    }
    
    void resetUserInterface()
    {
        vector<itemInfo*>::iterator it;
        int item = 0;
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            if (isInput((*it)->type)) {
                fInControl[item++] = STR2REAL((*it)->init);
            }
        }
    }
   
    void buildUserInterface(UI* ui)
    {
        // To be sure the floats are correctly encoded
        char* tmp_local = setlocale(LC_ALL, NULL);
        setlocale(LC_ALL, "C");

        int counterIn = 0;
        int counterOut = 0;
        vector<itemInfo*>::iterator it;
        
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            
            bool isInItem = false;
            bool isOutItem = false;
            string type = (*it)->type;
            
            FAUSTFLOAT init = STR2REAL((*it)->init);
            FAUSTFLOAT min = STR2REAL((*it)->min);
            FAUSTFLOAT max = STR2REAL((*it)->max);
            FAUSTFLOAT step = STR2REAL((*it)->step);
            
            if (isInput(type)) {
                isInItem = true;
            } else if (isOutput(type)) {
                isOutItem = true;
            }
            
            // Meta data declaration for input items
            if (isInput(type)) {
                fInControl[counterIn] = init;
                for (size_t i = 0; i < (*it)->meta.size(); i++) {
                    ui->declare(&fInControl[counterIn], (*it)->meta[i].first.c_str(), (*it)->meta[i].second.c_str());
                }
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                fOutControl[counterOut] = init;
                for (size_t i = 0; i < (*it)->meta.size(); i++) {
                    ui->declare(&fOutControl[counterOut], (*it)->meta[i].first.c_str(), (*it)->meta[i].second.c_str());
                }
            }
            // Meta data declaration for group opening or closing
            else {
                for (size_t i = 0; i < (*it)->meta.size(); i++) {
                    ui->declare(0, (*it)->meta[i].first.c_str(), (*it)->meta[i].second.c_str());
                }
            }
            
            if (type == "hgroup") {
                ui->openHorizontalBox((*it)->label.c_str());
            } else if (type == "vgroup") { 
                ui->openVerticalBox((*it)->label.c_str());
            } else if (type == "tgroup") {
                ui->openTabBox((*it)->label.c_str());
            } else if (type == "vslider") {
                ui->addVerticalSlider((*it)->label.c_str(), &fInControl[counterIn], init, min, max, step);
            } else if (type == "hslider") {
                ui->addHorizontalSlider((*it)->label.c_str(), &fInControl[counterIn], init, min, max, step);            
            } else if (type == "checkbox") {
                ui->addCheckButton((*it)->label.c_str(), &fInControl[counterIn]);
            } else if (type == "hbargraph") {
                ui->addHorizontalBargraph((*it)->label.c_str(), &fOutControl[counterOut], min, max);
            } else if (type == "vbargraph") {
                ui->addVerticalBargraph((*it)->label.c_str(), &fOutControl[counterOut], min, max);
            } else if (type == "nentry") {
                ui->addNumEntry((*it)->label.c_str(), &fInControl[counterIn], init, min, max, step);
            } else if (type == "button") {
                ui->addButton((*it)->label.c_str(), &fInControl[counterIn]);
            } else if (type == "close") {
                ui->closeBox();
            }
                
            if (isInItem) {
                counterIn++;
            }
                
            if (isOutItem) {
                counterOut++;
            }
        }
        
        setlocale(LC_ALL, tmp_local);
    }
    
};


#endif

//----------------------------------------------------------------
//  Proxy dsp definition created from the DSP JSON description
//  This class allows a 'proxy' dsp to control a real dsp 
//  possibly running somewhere else.
//----------------------------------------------------------------

class proxy_dsp : public dsp {

    private:
    
        int fSamplingFreq;
        JSONUIDecoder* fDecoder;
        
    public:
    
        proxy_dsp(const string& json)
        {
            fDecoder = new JSONUIDecoder(json);
            fSamplingFreq = -1;
        }
          
        proxy_dsp(dsp* dsp)
        {
            JSONUI builder(dsp->getNumInputs(), dsp->getNumOutputs());
            dsp->metadata(&builder);
            dsp->buildUserInterface(&builder);
            fSamplingFreq = dsp->getSampleRate();
            fDecoder = new JSONUIDecoder(builder.JSON());
        }
      
        virtual ~proxy_dsp()
        {
            delete fDecoder;
        }
       
        virtual int getNumInputs() 	{ return fDecoder->fNumInputs; }
        virtual int getNumOutputs() { return fDecoder->fNumOutputs; }
        
        virtual void buildUserInterface(UI* ui) { fDecoder->buildUserInterface(ui); }
        
        // To possibly implement in a concrete proxy dsp 
        virtual void init(int samplingFreq)
        {
            instanceInit(samplingFreq);
        }
        virtual void instanceInit(int samplingFreq)
        {
            instanceConstants(samplingFreq);
            instanceResetUserInterface();
            instanceClear();
        }
        virtual void instanceConstants(int samplingRate) { fSamplingFreq = samplingRate; }
        virtual void instanceResetUserInterface() { fDecoder->resetUserInterface(); }
        virtual void instanceClear() {}
    
        virtual int getSampleRate() { return fSamplingFreq; }
    
        virtual proxy_dsp* clone() { return new proxy_dsp(fDecoder->fJSON); }
        virtual void metadata(Meta* m) { fDecoder->metadata(m); }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {}
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {} 
        
};

#endif

#define kActiveVoice      0
#define kFreeVoice        -1
#define kReleaseVoice     -2
#define kNoVoice          -3

#define VOICE_STOP_LEVEL  0.001
#define MIX_BUFFER_SIZE   16384

#define FLOAT_MAX(a, b) (((a) < (b)) ? (b) : (a))

// endsWith(<str>,<end>) : returns true if <str> ends with <end>

static inline bool endsWith(std::string const& str, std::string const& end)
{
    size_t l1 = str.length();
    size_t l2 = end.length();
    return (l1 >= l2) && (0 == str.compare(l1 - l2, l2, end));
}

static inline double midiToFreq(double note)
{
    return 440.0 * std::pow(2.0, (note-69.0)/12.0);
}

/**
 * Allows to control zones in a grouped manner.
 */

class GroupUI : public GUI, public PathBuilder
{

    private:

        std::map<std::string, uiGroupItem*> fLabelZoneMap;

        void insertMap(std::string label, FAUSTFLOAT* zone)
        {
            if (!endsWith(label, "/gate")
                && !endsWith(label, "/freq")
                && !endsWith(label, "/gain")) {

                // Groups all controller except 'freq', 'gate', and 'gain'
                if (fLabelZoneMap.find(label) != fLabelZoneMap.end()) {
                    fLabelZoneMap[label]->addZone(zone);
                } else {
                    fLabelZoneMap[label] = new uiGroupItem(this, zone);
                }
            }
        }

        uiCallbackItem* fPanic;

    public:

        GroupUI(FAUSTFLOAT* zone, uiCallback cb, void* arg)
        {
            fPanic = new uiCallbackItem(this, zone, cb, arg);
        }
    
        virtual ~GroupUI()
        {
            // 'fPanic' is kept and deleted in GUI, so do not delete here
        }

        // -- widget's layouts
        void openTabBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openHorizontalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openVerticalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void closeBox()
        {
            fControlsLevel.pop_back();
        }

        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            insertMap(buildPath(label), zone);
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            insertMap(buildPath(label), zone);
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }

        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            insertMap(buildPath(label), zone);
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            insertMap(buildPath(label), zone);
        }

};

/**
 * One voice of polyphony.
 */

struct dsp_voice : public MapUI, public decorator_dsp {

    int fNote;              // Playing note actual pitch
    int fDate;              // KeyOn date
    bool fTrigger;          // True if stolen note and need for envelop trigger
    FAUSTFLOAT fLevel;      // Last audio block level
    std::string fGatePath;  // Path of 'gate' control
    std::string fGainPath;  // Path of 'gain' control
    std::string fFreqPath;  // Path of 'freq' control
    FAUSTFLOAT** fInputsSlice;
    FAUSTFLOAT** fOutputsSlice;
 
    dsp_voice(dsp* dsp):decorator_dsp(dsp)
    {
        dsp->buildUserInterface(this);
        fNote = kFreeVoice;
        fLevel = FAUSTFLOAT(0);
        fDate = 0;
        fTrigger = false;
        extractPaths(fGatePath, fFreqPath, fGainPath);
        fInputsSlice = new FAUSTFLOAT*[dsp->getNumInputs()];
        fOutputsSlice = new FAUSTFLOAT*[dsp->getNumOutputs()];
    }
    virtual ~dsp_voice()
    {
        delete [] fInputsSlice;
        delete [] fOutputsSlice;
    }

    void extractPaths(std::string& gate, std::string& freq, std::string& gain)
    {
        // Keep gain, freq and gate labels
        std::map<std::string, FAUSTFLOAT*>::iterator it;
        for (it = getMap().begin(); it != getMap().end(); it++) {
            std::string path = (*it).first;
            if (endsWith(path, "/gate")) {
                gate = path;
            } else if (endsWith(path, "/freq")) {
                freq = path;
            } else if (endsWith(path, "/gain")) {
                gain = path;
            }
        }
    }

    // MIDI velocity [0..127]
    void keyOn(int pitch, int velocity)
    {
        setParamValue(fFreqPath, midiToFreq(pitch));
        setParamValue(fGainPath, float(velocity)/127.f);
        fNote = pitch;
    }

    // Normalized MIDI velocity [0..1]
    void keyOn(int pitch, float velocity)
    {
        setParamValue(fFreqPath, midiToFreq(pitch));
        setParamValue(fGainPath, velocity);
        fNote = pitch;
    }

    void keyOff(bool hard = false)
    {
        // No use of velocity for now...
        setParamValue(fGatePath, FAUSTFLOAT(0));
        
        if (hard) {
            // Stop immediately
            fNote = kFreeVoice;
            fTrigger = false;
        } else {
            // Release voice
            fNote = kReleaseVoice;
        }
    }

    void play(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        if (fTrigger) {
            // New note, so trigger it
            trigger(count, inputs, outputs);
        } else {
            // Compute the voice
            compute(count, inputs, outputs);
        }
    }

    void trigger(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        setParamValue(fGatePath, FAUSTFLOAT(0));
        computeSlice(0, 1, inputs, outputs);
        setParamValue(fGatePath, FAUSTFLOAT(1));
        computeSlice(1, count - 1, inputs, outputs);
        fTrigger = false;
    }

    void computeSlice(int offset, int slice, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        if (slice > 0) {
            for (int chan = 0; chan < getNumInputs(); chan++) {
                fInputsSlice[chan] = &(inputs[chan][offset]);
            }
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                fOutputsSlice[chan] = &(outputs[chan][offset]);
            }
            compute(slice, fInputsSlice, fOutputsSlice);
        }
    }

};

/**
 * A group of voices.
 */

struct dsp_voice_group {

    GroupUI fGroups;

    std::vector<dsp_voice*> fVoiceTable; // Individual voices
    dsp* fVoiceGroup;                    // Voices group to be used for GUI grouped control

    FAUSTFLOAT fPanic;

    bool fVoiceControl;
    bool fGroupControl;

    dsp_voice_group(uiCallback cb, void* arg, bool control, bool group)
        :fGroups(&fPanic, cb, arg),
        fVoiceGroup(0), fPanic(FAUSTFLOAT(0)),
        fVoiceControl(control), fGroupControl(group)
    {}

    virtual ~dsp_voice_group()
    {
        for (size_t i = 0; i < fVoiceTable.size(); i++) {
            delete fVoiceTable[i];
        }
        delete fVoiceGroup;
    }

    void addVoice(dsp_voice* voice)
    {
        fVoiceTable.push_back(voice);
    }

    void clearVoices()
    {
        fVoiceTable.clear();
    }

    void init()
    {
        // Groups all uiItem for a given path
        fVoiceGroup = new proxy_dsp(fVoiceTable[0]);
        fVoiceGroup->buildUserInterface(&fGroups);
        for (size_t i = 0; i < fVoiceTable.size(); i++) {
            fVoiceTable[i]->buildUserInterface(&fGroups);
        }
    }

    void buildUserInterface(UI* ui_interface)
    {
        if (fVoiceTable.size() > 1) {
            ui_interface->openTabBox("Polyphonic");

            // Grouped voices UI
            ui_interface->openVerticalBox("Voices");
            ui_interface->addButton("Panic", &fPanic);
            fVoiceGroup->buildUserInterface(ui_interface);
            ui_interface->closeBox();

            // If not grouped, also add individual voices UI
            if (!fGroupControl) {
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    char buffer[32];
                    snprintf(buffer, 32, ((fVoiceTable.size() < 8) ? "Voice%ld" : "V%ld"), i+1);
                    ui_interface->openHorizontalBox(buffer);
                    fVoiceTable[i]->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                }
            }

            ui_interface->closeBox();
        } else {
            fVoiceTable[0]->buildUserInterface(ui_interface);
        }
    }

};

/**
 * Base class for Polyphonic DSP.
 */
class dsp_poly : public decorator_dsp, public midi {

    public:
    
        dsp_poly(dsp* dsp):decorator_dsp(dsp)
        {}
    
        virtual ~dsp_poly() {}
};

/**
 * Polyphonic DSP : group a set of DSP to be played together or triggered by MIDI.
 */

class mydsp_poly : public dsp_voice_group, public dsp_poly {

    private:

        FAUSTFLOAT** fMixBuffer;
        int fDate;

        inline FAUSTFLOAT mixVoice(int count, FAUSTFLOAT** outputBuffer, FAUSTFLOAT** mixBuffer)
        {
            FAUSTFLOAT level = 0;
            for (int i = 0; i < getNumOutputs(); i++) {
                FAUSTFLOAT* mixChannel = mixBuffer[i];
                FAUSTFLOAT* outChannel = outputBuffer[i];
                for (int j = 0; j < count; j++) {
                    level = FLOAT_MAX(level, (FAUSTFLOAT)fabs(outChannel[j]));
                    mixChannel[j] += outChannel[j];
                }
            }
            return level;
        }

        inline void clearOutput(int count, FAUSTFLOAT** mixBuffer)
        {
            for (int i = 0; i < getNumOutputs(); i++) {
                memset(mixBuffer[i], 0, count * sizeof(FAUSTFLOAT));
            }
        }
    
        inline int getPlayingVoice(int pitch)
        {
            int voice_playing = kNoVoice;
            int oldest_date_playing = INT_MAX;
            
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                if (fVoiceTable[i]->fNote == pitch) {
                    // Keeps oldest playing voice
                    if (fVoiceTable[i]->fDate < oldest_date_playing) {
                        oldest_date_playing = fVoiceTable[i]->fDate;
                        voice_playing = i;
                    }
                }
            }
            
            return voice_playing;
        }
    
        // Always returns a voice
        inline int getFreeVoice()
        {
            int voice = kNoVoice;
            
            // Looks for the first available voice
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                if (fVoiceTable[i]->fNote == kFreeVoice) {
                    voice = i;
                    goto result;
                }
            }

            {
                // Otherwise steal one
                int voice_release = kNoVoice;
                int voice_playing = kNoVoice;
                
                int oldest_date_release = INT_MAX;
                int oldest_date_playing = INT_MAX;

                // Scan all voices
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    if (fVoiceTable[i]->fNote == kReleaseVoice) {
                        // Keeps oldest release voice
                        if (fVoiceTable[i]->fDate < oldest_date_release) {
                            oldest_date_release = fVoiceTable[i]->fDate;
                            voice_release = i;
                        }
                    } else {
                        // Otherwise keeps oldest playing voice
                        if (fVoiceTable[i]->fDate < oldest_date_playing) {
                            oldest_date_playing = fVoiceTable[i]->fDate;
                            voice_playing = i;
                        }
                    }
                }
            
                // Then decide which one to steal
                if (oldest_date_release != INT_MAX) {
                    std::cout << "Steal release voice : voice_date " << fVoiceTable[voice_release]->fDate << " cur_date = " << fDate << " voice = " << voice_release << std::endl;
                    voice = voice_release;
                    goto result;
                } else if (oldest_date_playing != INT_MAX) {
                    std::cout << "Steal playing voice : voice_date " << fVoiceTable[voice_playing]->fDate << " cur_date = " << fDate << " voice = " << voice_playing << std::endl;
                    voice = voice_playing;
                    goto result;
                } else {
                    assert(false);
                    return kNoVoice;
                }
            }
            
        result:
            fVoiceTable[voice]->fDate = fDate++;
            fVoiceTable[voice]->fTrigger = true;    // So that envelop is always re-initialized
            fVoiceTable[voice]->fNote = kActiveVoice;
            return voice;
        }

        static void panic(FAUSTFLOAT val, void* arg)
        {
            if (val == FAUSTFLOAT(1)) {
                static_cast<mydsp_poly*>(arg)->allNotesOff(true);
            }
        }

        inline bool checkPolyphony()
        {
            if (fVoiceTable.size() > 0) {
                return true;
            } else {
                std::cout << "DSP is not polyphonic...\n";
                return false;
            }
        }

    public:
    
        /**
         * Constructor.
         *
         * @param dsp - the dsp to be used for one voice. Beware: mydsp_poly will use and finally delete the pointer.
         * @param nvoices - number of polyphony voices
         * @param control - whether voices will be dynamically allocated and controlled (typically by a MIDI controler).
         *                If false all voices are always running.
         * @param group - if true, voices are not individually accessible, a global "Voices" tab will automatically dispatch
         *                a given control on all voices, assuming GUI::updateAllGuis() is called.
         *                If false, all voices can be individually controlled.
         *
         */
        mydsp_poly(dsp* dsp,
                   int nvoices,
                   bool control = false,
                   bool group = true)
        : dsp_voice_group(panic, this, control, group), dsp_poly(dsp)
        {
            fDate = 0;

            // Create voices
            for (int i = 0; i < nvoices; i++) {
                addVoice(new dsp_voice(dsp->clone()));
            }

            // Init audio output buffers
            fMixBuffer = new FAUSTFLOAT*[getNumOutputs()];
            for (int i = 0; i < getNumOutputs(); i++) {
                fMixBuffer[i] = new FAUSTFLOAT[MIX_BUFFER_SIZE];
            }

            dsp_voice_group::init();
        }

        virtual ~mydsp_poly()
        {
            for (int i = 0; i < getNumOutputs(); i++) {
                delete[] fMixBuffer[i];
            }
            delete[] fMixBuffer;
        }

        // DSP API
    
        void buildUserInterface(UI* ui_interface)
        {
            dsp_voice_group::buildUserInterface(ui_interface);
        }

        void init(int samplingRate)
        {
            decorator_dsp::init(samplingRate);
            fVoiceGroup->init(samplingRate);
            fPanic = FAUSTFLOAT(0);
            
            // Init voices
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->init(samplingRate);
            }
        }
    
        void instanceInit(int samplingFreq)
        {
            instanceConstants(samplingFreq);
            instanceResetUserInterface();
            instanceClear();
        }

        void instanceConstants(int samplingRate)
        {
            decorator_dsp::instanceConstants(samplingRate);
            fVoiceGroup->instanceConstants(samplingRate);
            
            // Init voices
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceConstants(samplingRate);
            }
        }

        void instanceResetUserInterface()
        {
            decorator_dsp::instanceResetUserInterface();
            fVoiceGroup->instanceResetUserInterface();
            fPanic = FAUSTFLOAT(0);
            
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceResetUserInterface();
            }
        }

        void instanceClear()
        {
            decorator_dsp::instanceClear();
            fVoiceGroup->instanceClear();
            
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceClear();
            }
        }

        virtual mydsp_poly* clone()
        {
            return new mydsp_poly(fDSP->clone(), int(fVoiceTable.size()), fVoiceControl, fGroupControl);
        }

        void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            assert(count < MIX_BUFFER_SIZE);

            // First clear the outputs
            clearOutput(count, outputs);

            if (fVoiceControl) {
                // Mix all playing voices
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    dsp_voice* voice = fVoiceTable[i];
                    if (voice->fNote != kFreeVoice) {
                        voice->play(count, inputs, fMixBuffer);
                        // Mix it in result
                        voice->fLevel = mixVoice(count, fMixBuffer, outputs);
                        // Check the level to possibly set the voice in kFreeVoice again
                        if ((voice->fLevel < VOICE_STOP_LEVEL) && (voice->fNote == kReleaseVoice)) {
                            voice->fNote = kFreeVoice;
                        }
                    }
                }
            } else {
                // Mix all voices
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    fVoiceTable[i]->compute(count, inputs, fMixBuffer);
                    mixVoice(count, fMixBuffer, outputs);
                }
            }
        }

        void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            compute(count, inputs, outputs);
        }

        // Additional polyphonic API
        MapUI* newVoice()
        {
            return fVoiceTable[getFreeVoice()];
        }

        void deleteVoice(MapUI* voice)
        {
            std::vector<dsp_voice*>::iterator it = find(fVoiceTable.begin(), fVoiceTable.end(), reinterpret_cast<dsp_voice*>(voice));
            if (it != fVoiceTable.end()) {
                (*it)->keyOff();
            } else {
                std::cout << "Voice not found\n";
            }
        }

        // MIDI API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            if (checkPolyphony()) {
                int voice = getFreeVoice();
                fVoiceTable[voice]->keyOn(pitch, velocity);
                return fVoiceTable[voice];
            } else {
                return 0;
            }
        }

        void keyOff(int channel, int pitch, int velocity = 127)
        {
            if (checkPolyphony()) {
                int voice = getPlayingVoice(pitch);
                if (voice != kNoVoice) {
                    fVoiceTable[voice]->keyOff();
                } else {
                    std::cout << "Playing pitch = " << pitch << " not found\n";
                }
            }
        }

        void pitchWheel(int channel, int wheel)
        {}

        void ctrlChange(int channel, int ctrl, int value)
        {
            if (ctrl == ALL_NOTES_OFF || ctrl == ALL_SOUND_OFF) {
                allNotesOff();
            }
        }

        void progChange(int channel, int pgm)
        {}

        void keyPress(int channel, int pitch, int press)
        {}

        void chanPress(int channel, int press)
        {}

        void ctrlChange14bits(int channel, int ctrl, int value)
        {}

        // Terminate all active voices, gently or immediately (depending of 'hard' value)
        void allNotesOff(bool hard = false)
        {
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->keyOff(hard);
            }
        }

};

#endif // __poly_dsp__

std::list<GUI*> GUI::fGuiList;
ztimedmap GUI::gTimedZoneMap;

static const char* getCodeSize()
{
    int tmp;
    return (sizeof(&tmp) == 8) ? "64 bits" : "32 bits";
}

class mspUI;

struct Max_Meta1 : Meta
{
    int fCount;
    
    Max_Meta1():fCount(0)
    {}
     
    void declare(const char* key, const char* value)
    {
        if ((strcmp("name", key) == 0) || (strcmp("author", key) == 0)) {
            fCount++;
        }
    }
};

struct Max_Meta2 : Meta
{
    void declare(const char* key, const char* value)
    {
        if ((strcmp("name", key) == 0) || (strcmp("author", key) == 0)) {
            post("%s : %s", key, value);
        }
    }
};

struct Max_Meta3 : Meta
{
    string fName;
    void declare(const char* key, const char* value)
    {
        if ((strcmp("filename", key) == 0)) {
            fName = "com.grame." + string(value) + "~";
        }
    }
};

/*--------------------------------------------------------------------------*/
typedef struct faust
{
    t_pxobject m_ob;
    t_atom *m_seen, *m_want;
    map<string, vector <t_object*> > m_output_table;
    short m_where;
    bool m_mute;
    void** m_args;
    mspUI* m_dspUI;
    dsp* m_dsp;
    char* m_json;
    t_systhread_mutex m_mutex;    
    int m_Inputs;
    int m_Outputs;
#ifdef MIDICTRL
    MidiUI* m_midiUI;
    midi_handler* m_midiHandler;
#endif
#ifdef SOUNDFILE
    SoundUI* m_soundInterface;
#endif
} t_faust;

void* faust_class;

void faust_create_jsui(t_faust* x);
void faust_make_json(t_faust* x);

/*--------------------------------------------------------------------------*/
class mspUIObject {

	protected:

		string fLabel;
		FAUSTFLOAT* fZone;

		FAUSTFLOAT range(FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT val) {return (val < min) ? min : (val > max) ? max : val;}

	public:

		mspUIObject(const string& label, FAUSTFLOAT* zone):fLabel(label),fZone(zone) {}
		virtual ~mspUIObject() {}

		virtual void setValue(FAUSTFLOAT f) {*fZone = range(0.0,1.0,f);}
        virtual FAUSTFLOAT getValue() { return *fZone; }
		virtual void toString(char* buffer) {}
		virtual string getName() {return fLabel;}
};

/*--------------------------------------------------------------------------*/
class mspCheckButton : public mspUIObject {

	public:

		mspCheckButton(const string& label, FAUSTFLOAT* zone):mspUIObject(label,zone) {}
		virtual ~mspCheckButton() {}

		void toString(char* buffer)
		{
            snprintf(buffer, STR_SIZE, "CheckButton(double): %s", fLabel.c_str());
		}
};

/*--------------------------------------------------------------------------*/
class mspButton : public mspUIObject {

	public:

		mspButton(const string& label, FAUSTFLOAT* zone):mspUIObject(label,zone) {}
		virtual ~mspButton() {}

		void toString(char* buffer)
		{
            snprintf(buffer, STR_SIZE, "Button(double): %s", fLabel.c_str());
		}
};

/*--------------------------------------------------------------------------*/
class mspSlider : public mspUIObject {

	private:

		FAUSTFLOAT fInit;
		FAUSTFLOAT fMin;
		FAUSTFLOAT fMax;
		FAUSTFLOAT fStep;

	public:

		mspSlider(const string& label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
			:mspUIObject(label,zone),fInit(init),fMin(min),fMax(max),fStep(step) {}
		virtual ~mspSlider() {}

        void toString(char* buffer)
        {
            stringstream str;
            str << "Slider(float): " << fLabel << " [init=" << fInit << ":min=" << fMin << ":max=" << fMax << ":step=" << fStep << ":cur=" << *fZone << "]";
            string res = str.str();
            snprintf(buffer, STR_SIZE, "%s", res.c_str());
        }

		void setValue(FAUSTFLOAT f) {*fZone = range(fMin,fMax,f);}
};

/*--------------------------------------------------------------------------*/
class mspBargraph : public mspUIObject {
    
    private:
        
        FAUSTFLOAT fMin;
        FAUSTFLOAT fMax;
        FAUSTFLOAT fCurrent;
        
    public:
        
        mspBargraph(const string& label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        :mspUIObject(label,zone),fMin(min),fMax(max),fCurrent(*zone) {}
        virtual ~mspBargraph() {}
        
        void toString(char* buffer)
        {
            stringstream str;
            str << "Bargraph(float): " << fLabel << " [min=" << fMin << ":max=" << fMax << ":cur=" << *fZone << "]";
            string res = str.str();
            snprintf(buffer, STR_SIZE, "%s", res.c_str());
        }
    
        virtual FAUSTFLOAT getValue() 
        { 
            if (*fZone != fCurrent) {
                fCurrent = *fZone;
                return fCurrent;
            } else {
                return NAN; 
            }
        }
};

/*--------------------------------------------------------------------------*/

#define MULTI_SIZE  256

class mspUI : public UI
{
	private:

        map<string, mspUIObject*> fUITable1;       // Table using labels
        map<string, mspUIObject*> fUITable2;       // Table using complete path
        map<string, mspUIObject*> fUITable3;       // Table containing bargraph
       
        map<const char*, const char*> fDeclareTable;
        std::vector<std::string> fControlsLevel;
        
        FAUSTFLOAT* fMultiTable[MULTI_SIZE];
        int fMultiIndex;
        int fMultiControl;
        
        std::string buildPath(const std::string& label) 
        {
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res += fControlsLevel[i];
                res += "/";
            }
            res += label;
            replace(res.begin(), res.end(), ' ', '_');
            return res;
        }
    
        string createLabel(const char* label)
        {
            map<const char*, const char*>::reverse_iterator it;
            if (fDeclareTable.size() > 0) {
                unsigned int i = 0;
                string res = string(label);
                char sep = '[';
                for (it = fDeclareTable.rbegin(); it != fDeclareTable.rend(); it++, i++) {
                    res = res + sep + (*it).first + ":" + (*it).second;
                    sep = ',';
                }
                res += ']';
                fDeclareTable.clear();
                return res;
            } else {
                return string(label);
            }
        }

	public:
    
		typedef map<string, mspUIObject*>::iterator iterator;

		mspUI() 
        {
     		for (int i = 0; i < MULTI_SIZE; i++) {
                fMultiTable[i] = 0;
            }
            fMultiIndex = fMultiControl = 0;
        }
		virtual ~mspUI()
		{
            clear();
   		}
      
		void addButton(const char* label, FAUSTFLOAT* zone) 
        {
            mspUIObject* obj = new mspButton(createLabel(label), zone);
            fUITable1[string(label)] = obj;
            fUITable2[buildPath(label)] = obj;
        }
        
        void addCheckButton(const char* label, FAUSTFLOAT* zone) 
        {
            mspUIObject* obj = new mspCheckButton(createLabel(label), zone);
            fUITable1[string(label)] = obj;
            fUITable2[buildPath(label)] = obj; 
        }
        
        void addSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            mspUIObject* obj = new mspSlider(createLabel(label), zone, init, min, max, step);
            fUITable1[string(label)] = obj;
            fUITable2[buildPath(label)] = obj; 
        }
        
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addSlider(label, zone, init, min, max, step);
        }
        
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addSlider(label, zone, init, min, max, step);
        }
        
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            mspUIObject* obj = new mspSlider(createLabel(label), zone, init, min, max, step);
            fUITable1[string(label)] = obj;
            fUITable2[buildPath(label)] = obj;
        }
        
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {   
            fUITable3[buildPath(label)] = new mspBargraph(createLabel(label), zone, min, max);
            fDeclareTable.clear();
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {
            fUITable3[buildPath(label)] = new mspBargraph(createLabel(label), zone, min, max);
            fDeclareTable.clear();
        }
    
        void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}
    
        void openTabBox(const char* label) {fControlsLevel.push_back(label); fDeclareTable.clear();}
        void openHorizontalBox(const char* label) {fControlsLevel.push_back(label); fDeclareTable.clear();}
        void openVerticalBox(const char* label) {fControlsLevel.push_back(label); fDeclareTable.clear();}
        void closeBox() {fControlsLevel.pop_back(); fDeclareTable.clear();}

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            if (strcmp(key,"multi") == 0) {
                int index = atoi(val);
                if (index >= 0 && index < MULTI_SIZE) {
                    fMultiTable[index] = zone;
                    fMultiControl++;
                } else {
                    post("Invalid multi index = %d", index);
                }
            }
            
            fDeclareTable[key] = val;
        }
        
        void setMultiValues(FAUSTFLOAT* multi, int buffer_size)
		{
            for (int read = 0; read < buffer_size; read++) {
                int write = (fMultiIndex + read) & (MULTI_SIZE - 1);
                if (fMultiTable[write]) {
                    *fMultiTable[write] = multi[read];
                }
            }
            fMultiIndex += buffer_size;
		}
        
        bool isMulti() { return fMultiControl > 0; }
    
        bool isValue(string name) 
        {
            return (fUITable1.count(name) || fUITable2.count(name));
        }
        bool isOutputValue(string name) 
        {
            return fUITable3.count(name);
        }
        bool isInputValue(string name) 
        {
            return fUITable2.count(name);
        }
        bool setValue(string name, FAUSTFLOAT f)
        {
            if (fUITable1.count(name)) {
                fUITable1[name]->setValue(f);
                return true;
            } else if (fUITable2.count(name)) {
                fUITable2[name]->setValue(f);
                return true;
            } else {
                return false;
            }
        }
		FAUSTFLOAT getOutputValue(string name) { return fUITable3[name]->getValue(); }
          
        iterator begin1()	{ return fUITable1.begin(); }
        iterator end1()		{ return fUITable1.end(); }
        
        iterator begin2()	{ return fUITable2.begin(); }
        iterator end2()		{ return fUITable2.end(); }

        int itemsCount() { return fUITable1.size(); }
        void clear() 
        { 
            iterator it;
            for (it = begin1(); it != end1(); it++) {
                delete (*it).second;
            }
            fUITable1.clear(); 
            fUITable2.clear(); 
        }
    
        void displayControls()
        {
            iterator it;
            post((char*)"------- labels and ranges ----------");
            for (it = fUITable1.begin(); it != fUITable1.end(); it++) {
                char param[STR_SIZE];
                it->second->toString(param);
                post(param);
            }
            post((char*)"------- complete paths ----------");
            for (it = fUITable2.begin(); it != fUITable2.end(); it++) {
                post(it->first.c_str());
            }
            post((char*)"---------------------------------");
        }
    
};

//--------------------------------------------------------------------------
static bool check_digit(const string& name)
{
    for (int i = name.size() - 1; i >= 0; i--) {
        if (isdigit(name[i])) { return true; }
    }
    return false;
}

static int count_digit(const string& name)
{
    int count = 0;
    for (int i = name.size() - 1; i >= 0; i--) {
        if (isdigit(name[i])) { count++; }
    }
    return count;
}

/*--------------------------------------------------------------------------*/
void faust_anything(t_faust* obj, t_symbol* s, short ac, t_atom* av)
{
    if (ac < 0) return;
    
    bool res = false;
    string name = string((s)->s_name);
    
    // Check if no argument is there, consider it is a toggle message for a button
    if (ac == 0 && obj->m_dspUI->isValue(name)) {
        
        float off = 0.0f;
        float on = 1.0f;
        obj->m_dspUI->setValue(name, off);
        obj->m_dspUI->setValue(name, on);
        
        av[0].a_type = A_FLOAT;
        av[0].a_w.w_float = off;
        faust_anything(obj, s, 1, av);
        
        return;
    }
    
    // List of values
    if (check_digit(name)) {
        
        int ndigit = 0;
        int pos;
        
        for (pos = name.size() - 1; pos >= 0; pos--) {
            if (isdigit(name[pos]) || name[pos] == ' ') {
                ndigit++;
            } else {
                break;
            }
        }
        pos++;
        
        string prefix = name.substr(0, pos);
        string num_base = name.substr(pos);
        int num = atoi(num_base.c_str());
        
        int i;
        t_atom* ap;
       
        // Increment ap each time to get to the next atom
        for (i = 0, ap = av; i < ac; i++, ap++) {
            float value;
            switch (atom_gettype(ap)) {
                case A_LONG: 
                    value = (float)ap[0].a_w.w_long;
                    break;
                
                case A_FLOAT:
                    value = ap[0].a_w.w_float;
                    break;
                    
                default:
                    post("Invalid argument in parameter setting"); 
                    return;         
            }
            
            stringstream num_val;
            num_val << num + i;
            string str = num_val.str();
            char param_name[256];
            
            switch (ndigit - count_digit(str)) {
                case 0:
                    sprintf(param_name, "%s%s", prefix.c_str(), str.c_str());
                    break;
                case 1:
                    sprintf(param_name, "%s %s", prefix.c_str(), str.c_str());
                    break;
                case 2:
                    sprintf(param_name, "%s  %s", prefix.c_str(), str.c_str());
                    break;
            }
            
            // Try special naming scheme for list of parameters
            res = obj->m_dspUI->setValue(param_name, value); 
            
            // Otherwise try standard name
            if (!res) {
                res = obj->m_dspUI->setValue(name, value);
            }
            
            if (!res) {
                post("Unknown parameter : %s", (s)->s_name);
            }
        }
    } else {
        // Standard parameter name
        float value = (av[0].a_type == A_LONG) ? (float)av[0].a_w.w_long : av[0].a_w.w_float;
        res = obj->m_dspUI->setValue(name, value);
    }
    
    if (!res) {
        post("Unknown parameter : %s", (s)->s_name);
    }
}

/*--------------------------------------------------------------------------*/
void faust_polyphony(t_faust* obj, t_symbol* s, short ac, t_atom* av)
{
    if (systhread_mutex_lock(obj->m_mutex) == MAX_ERR_NONE) {
    #ifdef MIDICTRL
        mydsp_poly* poly = dynamic_cast<mydsp_poly*>(obj->m_dsp);
        if (poly) {
            obj->m_midiHandler->removeMidiIn(poly);
        }
    #endif
        // Delete old
        delete obj->m_dsp;
        obj->m_dspUI->clear();
        mydsp_poly* dsp_poly = NULL;
        // Allocate new one
        if (av[0].a_w.w_long > 0) {
            post("polyphonic DSP voices = %d", av[0].a_w.w_long);
            dsp_poly = new mydsp_poly(new mydsp(), av[0].a_w.w_long, true, true);
        #ifdef POLY2
            obj->m_dsp = new dsp_sequencer(dsp_poly, new effect());
        #else
            obj->m_dsp = dsp_poly;
        #endif
        } else {
            obj->m_dsp = new mydsp();
            post("monophonic DSP");
        }
        // Initialize User Interface (here connnection with controls)
        obj->m_dsp->buildUserInterface(obj->m_dspUI);
    #ifdef MIDICTRL
        obj->m_midiHandler->addMidiIn(dsp_poly);
        obj->m_dsp->buildUserInterface(obj->m_midiUI);
    #endif
        // Initialize at the system's sampling rate
        obj->m_dsp->init(long(sys_getsr()));
        
        // Prepare JSON
        faust_make_json(obj);
        
        // Send JSON to JS script
        faust_create_jsui(obj);
        
        systhread_mutex_unlock(obj->m_mutex);
    } else {
        post("Mutex lock cannot be taken...");
    }
}

/*--------------------------------------------------------------------------*/
#ifdef MIDICTRL
void faust_midievent(t_faust* obj, t_symbol* s, short ac, t_atom* av) 
{
    if (ac > 0) {
        int type = (int)av[0].a_w.w_long & 0xf0;
        int channel = (int)av[0].a_w.w_long & 0x0f;
                
        if (ac == 1) {
            obj->m_midiHandler->handleSync(0.0, av[0].a_w.w_long);
        } else if (ac == 2) {
            obj->m_midiHandler->handleData1(0.0, type, channel, av[1].a_w.w_long);
        } else if (ac == 3) {
            obj->m_midiHandler->handleData2(0.0, type, channel, av[1].a_w.w_long, av[2].a_w.w_long);
        }
    }
}
#endif

/*--------------------------------------------------------------------------*/
void faust_create_jsui(t_faust* x)
{
    t_object *patcher, *box, *obj;
    object_obex_lookup((t_object*)x, gensym("#P"), &patcher);
    
    for (box = jpatcher_get_firstobject(patcher); box; box = jbox_get_nextobject(box)) {
        obj = jbox_get_object(box);
        // Notify JSON
        if (obj && strcmp(object_classname(obj)->s_name, "js") == 0) {
            t_atom json;
            atom_setsym(&json, gensym(x->m_json));
            object_method_typed(obj, gensym("anything"), 1, &json, 0);
        }
    }
        
    // Keep all outputs
    x->m_output_table.clear();
    for (box = jpatcher_get_firstobject(patcher); box; box = jbox_get_nextobject(box)) {
        obj = jbox_get_object(box);
        t_symbol* scriptingname = jbox_get_varname(obj); // scripting name
        // Keep control outputs
        if (scriptingname && x->m_dspUI->isOutputValue(scriptingname->s_name)) {
            x->m_output_table[scriptingname->s_name].push_back(obj);
        }
    }
}

void faust_update_outputs(t_faust* x)
{
    map<string, vector<t_object*> >::iterator it1;
    vector<t_object*>::iterator it2;
    for (it1 = x->m_output_table.begin(); it1 != x->m_output_table.end(); it1++) {
        FAUSTFLOAT value = x->m_dspUI->getOutputValue((*it1).first);
        if (value != NAN) {
            t_atom at_value;
            atom_setfloat(&at_value, value);
            for (it2 = (*it1).second.begin(); it2 != (*it1).second.end(); it2++) {
                object_method_typed((*it2), gensym("float"), 1, &at_value, 0);
            }
        }
    }
}

/*--------------------------------------------------------------------------*/
void faust_make_json(t_faust* x)
{
    // Prepare JSON
    if (x->m_json) free(x->m_json);
    JSONUI builder(x->m_dsp->getNumInputs(), x->m_dsp->getNumOutputs());
    x->m_dsp->metadata(&builder);
    x->m_dsp->buildUserInterface(&builder);
    x->m_json = strdup(builder.JSON().c_str());
}

/*--------------------------------------------------------------------------*/
void* faust_new(t_symbol* s, short ac, t_atom* av)
{
    bool midi_sync = false;
    int nvoices = 0;
    mydsp_poly* dsp_poly = NULL;
    
    mydsp* tmp_dsp = new mydsp();
    MidiMeta::analyse(tmp_dsp, midi_sync, nvoices);
    delete tmp_dsp;
    
    t_faust* x = (t_faust*)newobject(faust_class);

    x->m_json = 0;
    x->m_mute = false;
    
#ifdef MIDICTRL
    x->m_midiHandler = new midi_handler();
    x->m_midiUI = new MidiUI(x->m_midiHandler);
#endif
    
    if (nvoices > 0) {
        post("polyphonic DSP voices = %d", nvoices);
        dsp_poly = new mydsp_poly(new mydsp(), nvoices, true, true);
    #ifdef POLY2
        x->m_dsp = new dsp_sequencer(dsp_poly, new effect());
    #else
        x->m_dsp = dsp_poly;
    #endif
        
    #ifdef MIDICTRL
        x->m_midiHandler->addMidiIn(dsp_poly);
        x->m_dsp->buildUserInterface(x->m_midiUI);
    #endif
    } else {
        post("monophonic DSP");
        x->m_dsp = new mydsp();
    }
    
    x->m_Inputs = x->m_dsp->getNumInputs();
    x->m_Outputs = x->m_dsp->getNumOutputs();
   
    x->m_dspUI = new mspUI();

    x->m_dsp->init(long(sys_getsr()));
    x->m_dsp->buildUserInterface(x->m_dspUI);
    
    t_max_err err = systhread_mutex_new(&x->m_mutex, SYSTHREAD_MUTEX_NORMAL);
    if (err != MAX_ERR_NONE) {
        post("Cannot allocate mutex...");
    }
    
    // Prepare JSON
    faust_make_json(x);
    
    int num_input;
    
    if (x->m_dspUI->isMulti()) {
        num_input = x->m_dsp->getNumInputs() + 1;
    } else {
        num_input = x->m_dsp->getNumInputs();
    }
    
    x->m_args = (void**)calloc((num_input + x->m_dsp->getNumOutputs()) + 2, sizeof(void*));
    /* Multi in */
    dsp_setup((t_pxobject*)x, num_input);

    /* Multi out */
    for (int i = 0; i< x->m_dsp->getNumOutputs(); i++) {
        outlet_new((t_pxobject*)x, (char*)"signal");
    }

    ((t_pxobject*)x)->z_misc = Z_NO_INPLACE; // To assure input and output buffers are actually different

#ifdef SOUNDFILE
    Max_Meta3 meta3;
    x->m_dsp->metadata(&meta3);
    string bundle_path_str = SoundUI::getBinaryPathFrom(meta3.fName);
    if (bundle_path_str == "") {
        post("Bundle_path cannot be found!");
    }
    x->m_soundInterface = new SoundUI(bundle_path_str);
    x->m_dsp->buildUserInterface(x->m_soundInterface);
#endif
    
    // Send JSON to JS script
    faust_create_jsui(x);
    return x;
}

/*--------------------------------------------------------------------------*/
void faust_dblclick(t_faust* x, long inlet)
{
    x->m_dspUI->displayControls();
}

/*--------------------------------------------------------------------------*/
//11/13/2015 : faust_assist is actually called at each click in the patcher, so we now use 'faust_dblclick' to display the parameters...
void faust_assist(t_faust* x, void* b, long msg, long a, char* dst)
{
    if (msg == ASSIST_INLET) {
        if (a == 0) {
            if (x->m_dsp->getNumInputs() == 0) {
                sprintf(dst, "(signal) : Unused Input");
            } else {
                sprintf(dst, "(signal) : Audio Input %ld", (a+1));
			}
        } else if (a < x->m_dsp->getNumInputs()) {
            sprintf(dst, "(signal) : Audio Input %ld", (a+1));
        }
    } else if (msg == ASSIST_OUTLET) {
        sprintf(dst, "(signal) : Audio Output %ld", (a+1));
    }
}

/*--------------------------------------------------------------------------*/
void faust_mute(t_faust* obj, t_symbol* s, short ac, t_atom* at)
{
    if (atom_gettype(at) == A_LONG) {
        obj->m_mute = atom_getlong(at);
    }
}

/*--------------------------------------------------------------------------*/
void faust_free(t_faust* x)
{
	dsp_free((t_pxobject*)x);
	delete x->m_dsp;
	delete x->m_dspUI;
	if (x->m_args) free(x->m_args);
    if (x->m_json) free(x->m_json);
    systhread_mutex_free(x->m_mutex);
#ifdef MIDICTRL
    // m_midiUI *must* be deleted before m_midiHandler
    delete x->m_midiUI;
    delete x->m_midiHandler;
#endif
#ifdef SOUNDFILE
    delete x->m_soundInterface;
#endif
}

/*--------------------------------------------------------------------------*/
void faust_perform64(t_faust* x, t_object* dsp64, double** ins, long numins, double** outs, long numouts, long sampleframes, long flags, void* userparam)
{
    AVOIDDENORMALS;
    if (!x->m_mute && systhread_mutex_trylock(x->m_mutex) == MAX_ERR_NONE) {
        if (x->m_dsp) {
            if (x->m_dspUI->isMulti()) {
                x->m_dspUI->setMultiValues(ins[0], sampleframes);
                x->m_dsp->compute(sampleframes, ++ins, outs);
            } else {
                x->m_dsp->compute(sampleframes, ins, outs);
            }
            faust_update_outputs(x);
        }
    #ifdef MIDICTRL
        GUI::updateAllGuis();
    #endif
        systhread_mutex_unlock(x->m_mutex);
    } else {
        // Write null buffers to outs
        for (int i = 0; i < numouts; i++) {
             memset(outs[i], 0, sizeof(double) * sampleframes);
        }
    }
}

/*--------------------------------------------------------------------------*/
void faust_dsp64(t_faust* x, t_object* dsp64, short* count, double samplerate, long maxvectorsize, long flags)
{
    object_method(dsp64, gensym("dsp_add64"), x, faust_perform64, 0, NULL);
}

/*--------------------------------------------------------------------------*/
extern "C" int main(void)
{
	setup((t_messlist**)&faust_class, (method)faust_new, (method)faust_free,
		(short)sizeof(t_faust), 0L, A_DEFFLOAT, 0);

    dsp* tmp_dsp = new mydsp();
    mspUI m_dspUI;
    tmp_dsp->buildUserInterface(&m_dspUI);

    // 03/11/14 : use 'anything' to handle all parameter changes
    addmess((method)faust_anything, (char*)"anything", A_GIMME, 0);
    addmess((method)faust_polyphony, (char*)"polyphony", A_GIMME, 0);
#ifdef MIDICTRL
    addmess((method)faust_midievent, (char*)"midievent", A_GIMME, 0);
#endif
    addmess((method)faust_dsp64, (char*)"dsp64", A_CANT, 0);
    addmess((method)faust_dblclick, (char*)"dblclick", A_CANT, 0);
    addmess((method)faust_assist, (char*)"assist", A_CANT, 0);
    addmess((method)faust_mute, (char*)"mute", A_GIMME, 0);
    dsp_initclass();

    post((char*)"Faust DSP object v%s (sample = 64 bits code = %s)", EXTERNAL_VERSION, getCodeSize());
    post((char*)"Copyright (c) 2012-2018 Grame");
    Max_Meta1 meta1;
    tmp_dsp->metadata(&meta1);
    if (meta1.fCount > 0) {
        Max_Meta2 meta2;
        post("------------------------------");
        tmp_dsp->metadata(&meta2);
        post("------------------------------");
    }
    
    delete(tmp_dsp);
    return 0;
}

/********************END ARCHITECTURE SECTION (part 2/2)****************/





#endif
