/* ------------------------------------------------------------
author: "Sébastien Clara"
name: "wavesBubble"
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

static double fmydspSIG0Wave0[32768] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,-3.9980732253752996e-06,-7.8095524713716996e-08,3.1910647521726997e-05,6.4157909946515994e-05,6.8294044467620999e-05,6.4253268647007997e-05,5.8273650211049e-05,6.4066029153764004e-05,0.00010198687959928,0.00016006758960429999,0.00023018293722998001,0.00032024580286816001,0.00045230245450511998,0.00057732046116142999,0.00063607533229515,0.00067409314215182998,0.00071829039370641004,0.00077022117329760996,0.00084424240048975002,0.00093045842368156,0.0010048543335869999,0.0011218523140997,0.0013690288178623,0.0016351628582924999,0.0018166301306337001,0.0019575767219067002,0.0020527464803308001,0.0021500883158296,0.0023216693662106999,0.0025030155666172999,0.0026439637877047001,0.0027608294039965001,0.0028260878752916999,0.0029200878925622,0.0031624024268240001,0.0034328296314924999,0.0036323731765150998,0.0037880195304751002,0.0038542600814253001,0.0039471085183321996,0.0042363512329756997,0.0045559988357126999,0.0047467891126870996,0.0049104811623692998,0.0050755529664457,0.0053233499638735996,0.0058408211916685,0.0063822353258728998,0.0066780755296350003,0.0068999575451016001,0.0071256151422858004,0.0074100182391702999,0.0079218940809369,0.0084378756582737004,0.0086849965155124994,0.0088896313682198993,0.0092457802966236999,0.0096568390727042996,0.010089179500937,0.010523829609156,0.010910403914750001,0.011294543743133999,0.011705461889505,0.012158473953605,0.012689870782197001,0.013278305530548,0.01393972709775,0.014595637097955,0.015136737376451,0.015626931563019999,0.016045713797212001,0.016550609841942999,0.017409816384315002,0.018373452126980001,0.019210822880268,0.020013956353068001,0.020797807723284,0.021586751565337001,0.022472048178315,0.023294776678085001,0.02381750755012,0.024263877421618001,0.024789011105895001,0.025469170883298,0.026621518656610998,0.027782900258898999,0.028344254940748,0.028758391737938,0.029303409159183998,0.030111936852335999,0.031712606549263,0.033384699374436999,0.034220315515994998,0.034819126129150002,0.035599227994680002,0.036506865173577999,0.037817526608705999,0.039025880396366001,0.039364404976367999,0.039493922144174999,0.039985615760088002,0.040747791528701997,0.042076654732226999,0.043445240706205,0.044103626161814,0.044586148113012002,0.045351676642895002,0.046212881803513003,0.047210779041052003,0.048063140362500999,0.048267740756272999,0.048247255384922,0.048377342522143998,0.048589497804642001,0.049037441611289999,0.049461957067250997,0.049508184194565,0.049385469406842998,0.049229614436625997,0.049036134034395003,0.048889383673667998,0.048690438270569,0.048258483409882001,0.047821708023548001,0.047687821090221003,0.047649897634983,0.047559764236211999,0.047403078526257997,0.047157905995846003,0.046668034046887998,0.045566197484732,0.044252149760723003,0.043127734214067001,0.042171213775872997,0.041680492460727997,0.041210893541573999,0.040082581341267,0.038817457854748001,0.037867404520512002,0.037200249731540999,0.037248648703097999,0.037223353981971997,0.035826388746500001,0.034085087478160997,0.033075850456953,0.032314743846655003,0.031713500618934999,0.030881967395544,0.028913924470544,0.026673993095756,0.025177428498864,0.023965479806066,0.022954910993576001,0.021757276728749001,0.019394254311919001,0.016911800950765998,0.015647167339921001,0.014931688085198,0.014457331970333999,0.013978650793433,0.012747803702950001,0.011471005156636,0.011113514192402,0.010990238748490999,0.010493156500160999,0.0096701327711344008,0.0080808373168111004,0.0063969623297452996,0.0056435787118971001,0.0052212183363735997,0.0046200165525078999,0.0040046731010079002,0.0033749109134078,0.0028039522003382002,0.0024658516049385001,0.0021865924354642998,0.0017506950534880001,0.0012374697253108001,0.00058242998784407995,2.4596462026238001e-05,-4.7067728701222002e-06,0.00023478645016438999,0.00053276948165147998,0.00089890498202294003,0.0013667186722159,0.0016498211771250001,0.0011443770490587001,0.00032124272547661998,-0.00032018261845224001,-0.00088494690135120999,-0.001322940341197,-0.0016200869577006,-0.0018496817210689001,-0.0017044472042470999,-0.00050260673742740999,0.0011431650491431,0.0027049141936004001,0.0038493287283926998,0.0034134951420127999,0.0024535330012440998,0.0023508036974818,0.0025011794641613999,0.0025320369750260999,0.0025142119266092998,0.0022275338415055999,0.0021103161852807002,0.0030379346571863001,0.0043035824783146,0.0051237801089882998,0.0056045041419565999,0.0053568407893181003,0.0049204062670468998,0.0051581030711532003,0.0056425193324685001,0.0060422793030739004,0.0064207250252365997,0.0065905284136533997,0.0069175357930361999,0.0082591082900762992,0.0097401002421974997,0.010103940963744999,0.0098710814490913998,0.0092711104080081003,0.0084610208868979991,0.0078699812293053003,0.0073268031701445996,0.0067268800921738,0.0061102993786335,0.0054282280616461996,0.0048559750430286,0.0048897988162934997,0.0049643125385045997,0.0041848444379866002,0.0029734917916357999,0.0016375425038859001,0.00017227325588465,-0.0012278804788365999,-0.0027220912743359999,-0.0045608808286488004,-0.0065710870549082999,-0.0085311084985732998,-0.010539810173213,-0.012738086283207,-0.014945046976209001,-0.016760217025876,-0.018561927601694998,-0.020888779312371999,-0.023575890809297999,-0.026742167770862999,-0.029998341575265,-0.032496567815541999,-0.034786775708198998,-0.037541534751653997,-0.040512319654225998,-0.043647062033415,-0.046761181205511003,-0.049371637403965003,-0.051805239170790003,-0.054429639130831001,-0.057214923202991,-0.060166269540787,-0.063563309609889998,-0.068176791071892007,-0.073362022638321006,-0.078272432088851998,-0.083020381629466997,-0.087469696998595997,-0.091472446918488007,-0.094484426081181003,-0.097007140517234997,-0.099738709628582001,-0.10258387774229,-0.10571333020926001,-0.10909494012594,-0.1128918454051,-0.11676990985870001,-0.12009064853191,-0.12308817356825,-0.12585605680942999,-0.12848085165024001,-0.13124838471413,-0.13396307826042,-0.13626325130462999,-0.13846826553345001,-0.14110881090164001,-0.14394190907477999,-0.14685107767582001,-0.14962354302406,-0.15160441398621,-0.15325970947741999,-0.15522937476634999,-0.15735231339931,-0.15982916951180001,-0.16218073666096,-0.16333544254303001,-0.16388036310672999,-0.16451124846935,-0.16503335535526001,-0.16548068821430001,-0.16567260026931999,-0.16490314900875,-0.16405637562274999,-0.16491524875163999,-0.16655234992504001,-0.16806949675082999,-0.16933758556843001,-0.16940240561962,-0.16887743771076,-0.16863691806792999,-0.16837345063685999,-0.16790121793747001,-0.16722336411475999,-0.16601978242397,-0.16485007107258001,-0.16503141820431,-0.16575132310390001,-0.16596199572086001,-0.16579718887806,-0.16465711593627999,-0.16336466372013,-0.16377985477448001,-0.16478021442890001,-0.16480819880962,-0.16429026424884999,-0.16312876343727001,-0.16179074347019001,-0.16150747239589999,-0.16153840720654,-0.16084948182105999,-0.15970493853091999,-0.15791162848473,-0.15599468350410001,-0.15522415935993,-0.15498054027557001,-0.15454867482185,-0.15405163168906999,-0.15331582725048001,-0.15251618623734001,-0.15197387337685,-0.15159367024899001,-0.15138810873031999,-0.15123738348484,-0.15086509287357,-0.15033243596554,-0.14949817955493999,-0.14866042137145999,-0.14855943620205,-0.14881527423859001,-0.14898383617401001,-0.14906007051468001,-0.14866659045219,-0.14812083542346999,-0.14805740118027,-0.14817139506339999,-0.14815627038479001,-0.14792270958424,-0.14671809971333,-0.14543905854225,-0.14613161981105999,-0.14780884981155001,-0.14926002919674,-0.15063166618346999,-0.15143661201,-0.15211085975169999,-0.1536490470171,-0.15544089674950001,-0.15645389258862,-0.15705724060535001,-0.15746194124221999,-0.15787650644779,-0.15918517112732,-0.16071914136410001,-0.16114774346352001,-0.16104555130004999,-0.16094821691513,-0.16106429696082999,-0.1625180542469,-0.16450861096382,-0.1654754281044,-0.16606265306473,-0.16701114177703999,-0.16820225119591001,-0.16991767287254,-0.17176946997643,-0.17280068993568001,-0.17343547940254,-0.17420378327370001,-0.17503468692303001,-0.17614716291428001,-0.17730002105236001,-0.17791491746902,-0.17825511097908001,-0.17867802083491999,-0.17911231517792001,-0.17962017655373,-0.18010179698466999,-0.18028578162193001,-0.18031209707260001,-0.18040685355663,-0.18050438165665,-0.18057662248611001,-0.18059647083281999,-0.18049216270446999,-0.18024463951587999,-0.17968243360519001,-0.17898644506931,-0.17851749062538,-0.17826794087886999,-0.1786831766367,-0.17919233441353,-0.17836172878741999,-0.17670845985413,-0.17467249929904999,-0.17242811620234999,-0.17079855501652,-0.16946704685687999,-0.16804809868335999,-0.16661882400513001,-0.16502809524536,-0.16357851028442,-0.16350246965885001,-0.16366447508335,-0.16118805110455001,-0.15736554563046001,-0.15399272739886999,-0.15102502703667001,-0.15007351338863001,-0.14956644177437001,-0.14537434279919001,-0.13940329849720001,-0.13460709154605999,-0.13053722679615001,-0.12809486687183,-0.12629809975624001,-0.12250641733408001,-0.11787478625774001,-0.1141615062952,-0.11107559502125,-0.10918736457825,-0.10769639909266999,-0.10424476861954,-0.099924281239509999,-0.096586056053638,-0.093796834349632,-0.091612599790096005,-0.089595235884189994,-0.086198091506957994,-0.082226380705833005,-0.079290799796581005,-0.076844684779643999,-0.074488796293736004,-0.071785554289818004,-0.066628962755202997,-0.060385964810848,-0.056009940803051002,-0.052827399224042997,-0.050745587795972998,-0.049504145979881002,-0.048326049000024997,-0.047253184020519,-0.045967631042003999,-0.044441938400268999,-0.042389232665300002,-0.039836965501307997,-0.036585029214621,-0.032849870622158002,-0.029152104631066,-0.025462536141275999,-0.021980555728078,-0.018740387633443,-0.016112804412842002,-0.013804787769914,-0.010990303009747999,-0.0080370903015136996,-0.0056408890523016002,-0.0036236438900231998,-0.0020849225111306,-0.00057092704810202002,0.0026923143304884,0.0067428881302475999,0.0094711109995841997,0.011410966515541,0.012703496031463,0.013827974908054,0.016708269715309001,0.020528081804514001,0.023798972368239999,0.026807712391018999,0.029443105682731001,0.031959231942891998,0.035486169159412002,0.039178546518086999,0.040564920753241002,0.04067212715745,0.041302364319563002,0.042314596474170997,0.044473692774772998,0.047469101846217998,0.050899777561426003,0.054594572633504999,0.057625081390141997,0.060296081006527003,0.063089661300181996,0.065852433443069,0.068298056721686998,0.070567339658737002,0.072998717427254001,0.075491264462470994,0.077818520367145996,0.080173633992671994,0.083221152424811998,0.086637668311596,0.089745163917542004,0.092591330409050002,0.094688482582568997,0.096490420401095997,0.099566720426083,0.10319712013005999,0.10562603920697999,0.10745860636234,0.10964642465115,0.11221151798964001,0.11609245836734999,0.12071405351162,0.12451291829348,0.12789902091026001,0.13114434480667,0.13455870747566001,0.13988672196865001,0.14611457288265001,0.15041844546795,0.1536096483469,0.15668368339538999,0.1597760617733,0.16448338329792001,0.16978359222412001,0.17249043285846999,0.17377886176109,0.17586638033390001,0.17862790822982999,0.18354617059230999,0.18954245746136,0.19300484657288,0.19532081484795,0.19935680925846,0.20480100810528001,0.21340969204902999,0.22313824295998,0.22617660462856001,0.22543488442897999,0.22722254693508001,0.23031702637672,0.23431542515754999,0.2388588488102,0.24203900992870001,0.24466767907143,0.24887470901011999,0.25402015447616999,0.25911274552344998,0.26405081152915999,0.26745775341987998,0.2700542807579,0.27391722798347001,0.27855640649795999,0.28342214226723,0.28852331638335998,0.29363268613815002,0.2986615896225,0.30297049880027999,0.30681645870209001,0.31091684103012002,0.31501114368438998,0.31857085227965998,0.32155287265777999,0.32311490178107999,0.32386013865470997,0.32556676864624001,0.32825726270675998,0.33391651511192,0.34122905135155002,0.34550192952156,0.34816867113112998,0.35231673717499001,0.35724076628684998,0.36227133870125,0.36701783537865001,0.36879613995552002,0.36887234449387002,0.37102073431014998,0.37450352311134,0.37915119528770003,0.38426735997200001,0.38616049289703003,0.38620981574058999,0.38811922073364002,0.39110392332076999,0.39448642730713002,0.39791706204414001,0.39887422323227001,0.39852848649025002,0.40068501234054998,0.40436288714409002,0.40793833136558999,0.41134193539619002,0.41290026903152,0.41325670480728,0.41420233249664001,0.41541337966919001,0.41673338413238997,0.41803213953972002,0.41826248168945002,0.4181115925312,0.42040520906447998,0.42425015568732999,0.42744603753089999,0.43026724457741,0.43201175332068997,0.43348613381385998,0.43864643573760997,0.44601836800575001,0.45133975148201,0.45517584681510997,0.45685037970543002,0.45705631375312999,0.45883849263191001,0.46142685413361001,0.46319052577018999,0.46441349387169001,0.46508333086967002,0.46563711762428001,0.46849253773688998,0.47292205691338002,0.47702732682228,0.48109218478202997,0.4853059053421,0.48951581120491,0.49285227060317999,0.49568766355514998,0.49938601255416998,0.50363320112228005,0.50775194168090998,0.51189529895782004,0.51626271009445002,0.52100789546966997,0.52716708183288996,0.53446429967880005,0.54217147827148005,0.5504567027092,0.55996245145797996,0.57023692131042003,0.57939076423644997,0.58758360147475996,0.59438878297805997,0.59969818592071999,0.60175281763077004,0.60186982154846003,0.60634374618529996,0.61374378204346003,0.62086939811706998,0.62820571660994995,0.63626813888550005,0.64488965272902998,0.65357452630997004,0.66221100091934004,0.66978895664214999,0.67646175622939997,0.68218666315079002,0.68713355064392001,0.69242024421691994,0.69761776924133001,0.70094698667526001,0.70286542177199995,0.70454698801041005,0.70602017641068004,0.70827782154082997,0.71122014522552002,0.71528077125549006,0.72011983394623003,0.72417736053466997,0.72755295038223,0.72946673631668002,0.73025172948837003,0.73147106170653997,0.73264014720917003,0.73215579986571999,0.73005384206771995,0.72516685724258001,0.71788150072098,0.70934718847275002,0.69974458217621005,0.69101464748383001,0.68295073509215998,0.67569482326508001,0.66938942670821999,0.66573482751846003,0.66373282670974998,0.65837681293488004,0.65036010742188,0.63987171649932995,0.62730276584625,0.61533159017562999,0.60338902473449996,0.58992493152617997,0.57512152194976995,0.55857360363007003,0.54088544845580999,0.52624362707137995,0.51341003179550004,0.49724930524826,0.47871521115303001,0.45988351106643999,0.44089603424071999,0.42505732178687999,0.41092479228973,0.39095476269722002,0.36665487289429,0.34195911884308,0.31688913702964999,0.29486089944839,0.27501624822616999,0.25407028198241999,0.23267364501953,0.21272429823875,0.19414541125297999,0.17855998873710999,0.16491112112999001,0.14655409753323001,0.12488153576850999,0.10446537286043001,0.084846302866935994,0.066676795482634998,0.049308888614178002,0.028210796415806001,0.0044945552945136998,-0.017331631854177,-0.037810627371072998,-0.057886160910129998,-0.076962001621722995,-0.090747177600860998,-0.10024403035641,-0.10926759988070001,-0.11763717234135,-0.12647274136542999,-0.13616319000721,-0.15135627985000999,-0.17084823548794001,-0.18917912244797,-0.20702980458736001,-0.22503627836703999,-0.24349884688854001,-0.26575407385826,-0.29071232676505998,-0.31252449750900002,-0.33185160160065003,-0.34949347376822998,-0.36511299014090998,-0.37598937749862998,-0.38288906216620999,-0.38950398564339,-0.39573293924331998,-0.40346246957778997,-0.41274258494376997,-0.42638266086578003,-0.44337621331214999,-0.45783242583275002,-0.47031620144844,-0.48083308339119002,-0.48932203650474998,-0.49463018774986001,-0.49728414416312999,-0.50093060731887995,-0.50506645441054998,-0.50829243659973,-0.51082009077071999,-0.51337504386902,-0.51597726345062001,-0.51927649974822998,-0.52328926324844005,-0.52887350320815996,-0.53580951690673995,-0.54305976629257002,-0.55055755376815996,-0.55690985918045,-0.56220996379851995,-0.56602627038955999,-0.56845808029175005,-0.56990593671798995,-0.57041138410568004,-0.57033270597457997,-0.56996417045592995,-0.57269799709320002,-0.57791805267333995,-0.58300358057021995,-0.58790975809097001,-0.58968597650527999,-0.58902156352997004,-0.59015244245528997,-0.59249627590178999,-0.59394907951355003,-0.59461349248885997,-0.59337127208710005,-0.59079265594482,-0.59193313121795998,-0.59595376253127996,-0.59876108169555997,-0.60066902637482,-0.60143595933913996,-0.60121196508408004,-0.60119068622589,-0.60123229026794001,-0.60090059041976995,-0.60022747516632002,-0.59897869825363004,-0.59739041328429998,-0.59811031818390004,-0.60059481859206998,-0.60123378038405995,-0.60038805007935003,-0.59872728586196999,-0.59639322757721003,-0.59556639194489003,-0.59588581323624001,-0.59524786472321001,-0.59384757280349998,-0.59183806180954002,-0.58946043252945002,-0.58998912572860995,-0.59274536371231001,-0.59253555536269997,-0.59000462293625,-0.58810126781464001,-0.58670502901077004,-0.58728057146071999,-0.58928138017653997,-0.58736670017241999,-0.58216917514801003,-0.57663911581038996,-0.57057213783264005,-0.56354689598082996,-0.55580747127533003,-0.55032777786255005,-0.54672473669052002,-0.54281842708588002,-0.53879052400589,-0.53498214483260997,-0.53149831295012995,-0.52996504306793002,-0.53019911050796997,-0.53136968612670998,-0.53347671031952004,-0.53618389368056996,-0.53928071260452004,-0.53950881958008001,-0.53718924522400002,-0.53357225656509,-0.52866876125336004,-0.52322316169739003,-0.51743292808533004,-0.51507562398911,-0.51566547155380005,-0.51581549644470004,-0.51576757431029996,-0.51613759994507002,-0.51686960458755005,-0.51781380176544001,-0.51879382133483998,-0.51681184768677002,-0.51227337121964001,-0.50802320241928001,-0.50417643785476995,-0.50556105375289995,-0.51141768693923995,-0.51451611518859997,-0.51542377471923995,-0.51647204160689997,-0.51761913299561002,-0.52034151554107999,-0.52429252862929998,-0.52490144968033003,-0.52275425195694003,-0.52328211069107,-0.52615076303482,-0.53090399503707997,-0.53736567497252996,-0.54246568679810003,-0.54638350009918002,-0.54932713508606001,-0.55129367113113004,-0.55205070972443004,-0.55172520875930997,-0.55238592624663996,-0.55389076471329002,-0.55556184053420998,-0.55745607614517001,-0.56017607450484996,-0.56364744901657005,-0.56679725646973,-0.56980586051940996,-0.57521969079971003,-0.58284711837768999,-0.59144371747971003,-0.60100382566452004,-0.61080312728882002,-0.62066859006882003,-0.62611848115920998,-0.62752997875214001,-0.62817227840423995,-0.62795794010161998,-0.62751168012618996,-0.62697970867157005,-0.63047993183135997,-0.63768768310546997,-0.64560574293136996,-0.65434306859970004,-0.66447985172271995,-0.67563003301619995,-0.67890864610671997,-0.67500269412993996,-0.67105823755264005,-0.66685378551482999,-0.66305655241012995,-0.65980148315429998,-0.66176182031631003,-0.66856175661087003,-0.67563992738723999,-0.68313753604889005,-0.69101911783217995,-0.69908475875854004,-0.70127558708190996,-0.69809991121292003,-0.69713109731673994,-0.69804817438125999,-0.69938480854034002,-0.70107936859131004,-0.70017850399017001,-0.69691848754883001,-0.69518232345580999,-0.69478434324265004,-0.6940558552742,-0.69299167394637995,-0.68970936536788996,-0.68440645933151001,-0.68134814500809004,-0.68034446239471003,-0.67958241701125999,-0.67906582355499001,-0.67721980810164994,-0.67416757345199996,-0.67247879505157004,-0.67204344272614003,-0.67153006792068004,-0.67095935344696001,-0.67005324363707996,-0.66878134012222001,-0.66560339927672996,-0.66058498620987005,-0.65466034412384,-0.64780741930008001,-0.63991075754166005,-0.63099032640456998,-0.62149930000304998,-0.61151045560837003,-0.60461014509201005,-0.60069102048874001,-0.59895342588425005,-0.59933453798294001,-0.59854763746261996,-0.59664160013198997,-0.59253281354903997,-0.58626645803452004,-0.57857620716095004,-0.56948667764663996,-0.56088519096375,-0.55274051427840998,-0.54540890455246005,-0.53885978460312001,-0.53185027837752996,-0.52440303564071999,-0.51665848493576005,-0.50861513614654996,-0.50019711256027,-0.49141165614128002,-0.48270520567893999,-0.47406527400017001,-0.46505254507065003,-0.45567268133163003,-0.44597300887107999,-0.43594935536384999,-0.42532753944397,-0.41410556435585,-0.40182775259018,-0.38850012421607999,-0.37394168972969,-0.35818445682526001,-0.34436795115470997,-0.33245801925659002,-0.32173156738281,-0.31220752000808999,-0.30622184276580999,-0.30371776223183,-0.29908895492554,-0.29237511754036,-0.28404521942138999,-0.27409890294075001,-0.26233994960785001,-0.24877932667732,-0.23574681580067,-0.22322973608971,-0.21047377586364999,-0.19747865200042999,-0.18316005170345001,-0.16752658784388999,-0.15383328497410001,-0.14207403361797,-0.13139174878596999,-0.12178672105074,-0.11132779717445,-0.10001388192177001,-0.089170187711716004,-0.078799821436405001,-0.067780330777167996,-0.056112416088581002,-0.042368564754725002,-0.026527682319283,-0.014011947438121,-0.0048581101000308999,0.0052043092437088004,0.016193225979805,0.028213858604431,0.041290037333965003,0.051403868943453002,0.058499164879322003,0.067312978208065005,0.077882915735245001,0.089666925370692999,0.10269843041897,0.11254491657019,0.11912873387337,0.12660577893257,0.13501510024071001,0.14436240494250999,0.15468619763850999,0.16256873309611999,0.16793525218964001,0.17384421825408999,0.18033334612846,0.18709194660187001,0.19411316514015001,0.20185658335685999,0.21033427119254999,0.21921607851982,0.22851088643074,0.23739080131054,0.24585118889808999,0.2532596886158,0.25958549976348999,0.26598563790321,0.27248775959014998,0.27867487072945002,0.28455406427383001,0.28935697674750999,0.29305171966553001,0.29643660783768,0.29951265454291998,0.30299520492554,0.30691084265709001,0.31077447533607,0.31457540392875999,0.31826522946357999,0.32180672883986999,0.32681885361670998,0.33336281776428001,0.34065517783165,0.34874191880226002,0.35487753152847001,0.35891717672348,0.36387404799460998,0.36986815929412997,0.37520915269852001,0.37989223003387002,0.38226583600044001,0.38214308023452997,0.38462483882904003,0.38992890715598999,0.39563179016112998,0.40172630548477001,0.40600222349166998,0.40820825099945002,0.41456231474875999,0.42541211843491,0.43591490387916998,0.44600278139114002,0.45305997133254999,0.45685026049614003,0.46165233850478998,0.46768230199813998,0.47271168231964,0.47670665383339,0.47809815406799,0.47651204466820002,0.48140397667884999,0.49343925714492998,0.50385349988937,0.51236808300018,0.51780599355697998,0.51983320713043002,0.52581787109375,0.53630745410919001,0.54443687200545998,0.54986643791198997,0.55438774824142001,0.55784809589385997,0.56587457656859996,0.57902628183365001,0.58955818414687999,0.59709328413009999,0.60284143686295,0.60668790340423995,0.61205482482910001,0.61919498443604004,0.62585812807082997,0.63189542293548995,0.63849890232086004,0.64562106132507002,0.65581381320953003,0.66949373483658003,0.68015909194946,0.68736571073532005,0.69391304254532005,0.69985008239746005,0.70661354064940995,0.71436899900436002,0.72130441665649003,0.72723609209061002,0.73403185606002996,0.74169415235518998,0.75249415636063,0.76693713665009,0.77735352516174006,0.78312110900878995,0.78843259811401001,0.79354029893875,0.79720342159270996,0.79924869537354004,0.80201709270476995,0.80567014217376998,0.80961912870407005,0.81382203102112005,0.81872272491455,0.82440739870071,0.82977038621902,0.83476316928864003,0.83906078338623002,0.84261196851730003,0.84592050313949996,0.84907853603363004,0.85059136152267001,0.84999811649322998,0.85392755270003995,0.86309444904327004,0.87277138233185003,0.88293224573134999,0.88933259248733998,0.89147883653641002,0.89224296808242998,0.89164638519286998,0.89198124408722002,0.89340484142303001,0.89626586437224998,0.90068888664246005,0.90541803836822998,0.91042709350586004,0.91486418247223,0.91872709989547996,0.92088919878006004,0.92117708921431996,0.92084795236588002,0.91994822025298995,0.91901361942291004,0.91806989908217995,0.91744315624237005,0.91714328527450995,0.91750985383987005,0.91862303018570002,0.91971141099929998,0.92068964242935003,0.92201030254364003,0.92375266551971003,0.92520672082901001,0.92631888389587003,0.92709147930144997,0.92751646041869995,0.92760872840881003,0.92734426259994995,0.92710709571838001,0.92698025703429998,0.92624366283417003,0.92481601238250999,0.92298221588134999,0.92069959640502996,0.91881537437438998,0.91744649410248003,0.91595596075057995,0.91420173645019998,0.91340041160582996,0.91361153125762995,0.91577845811844005,0.92053973674774003,0.92054605484009,0.91468811035155995,0.90882480144500999,0.90337455272675005,0.89911383390427002,0.89649736881256004,0.89119338989258001,0.88259512186050004,0.87339669466018999,0.86377727985382002,0.85391587018966997,0.84355396032332997,0.83657109737395996,0.83370810747146995,0.83055859804152998,0.82673478126526001,0.82236391305922996,0.81756031513214,0.81039142608643,0.80031353235244995,0.79149454832077004,0.78442609310150002,0.77812743186950994,0.77278041839599998,0.76560056209563998,0.75622063875197998,0.74546885490417003,0.73330050706863004,0.72079062461853005,0.70799988508223999,0.69560056924820002,0.68372654914856001,0.67186808586121005,0.66006755828857,0.64745467901230003,0.63408863544464,0.61811387538910001,0.59909480810164994,0.57946467399597001,0.55945730209350997,0.53918117284775002,0.51871979236603005,0.49744254350661998,0.47499945759772999,0.45459678769112,0.43692699074745001,0.41840428113937,0.39866346120834001,0.37745469808578003,0.35425746440887002,0.33404132723808,0.31793719530106002,0.30002003908156999,0.27947187423705999,0.25808736681937999,0.23566295206547,0.21602356433868,0.20032700896263,0.1815087646246,0.15851338207721999,0.13365881145,0.10647717118263,0.083856806159018998,0.067430540919304005,0.049442116171122,0.028693687170744001,0.0085131861269473995,-0.010922795161604999,-0.028023675084113998,-0.041988022625446,-0.058452576398849002,-0.078499130904675002,-0.098423220217228005,-0.11805573850870001,-0.13499850034714,-0.14826336503029,-0.16410540044308,-0.18389731645584001,-0.20197542011738001,-0.21770192682743,-0.23068812489509999,-0.24014721810817999,-0.25243401527405002,-0.26899012923241,-0.28420513868331998,-0.29747781157494002,-0.30801314115523998,-0.31484422087669001,-0.32541716098785001,-0.34158489108085999,-0.35553067922592002,-0.36617553234099998,-0.37442490458487998,-0.37974074482918002,-0.38729241490364003,-0.39853641390799999,-0.40683829784393,-0.41100180149078003,-0.41404756903647999,-0.41612464189529003,-0.41885486245155001,-0.42274197936058,-0.42569768428802002,-0.42726641893387002,-0.42898565530777,-0.43081903457642001,-0.43501612544059998,-0.44274112582206998,-0.44691675901413003,-0.44611111283302002,-0.44391793012619002,-0.44055041670799,-0.43775245547295,-0.43610134720802002,-0.43328130245209001,-0.42871922254562,-0.42460569739342002,-0.42124149203299999,-0.41866672039031999,-0.41720235347748003,-0.41448640823364002,-0.40993961691856001,-0.40537816286086997,-0.40107563138008001,-0.39671051502228,-0.39220553636550998,-0.38805708289146001,-0.38444116711616999,-0.38054767251014998,-0.37624594569205999,-0.37157091498375,-0.36633479595183999,-0.36204972863196999,-0.35924887657165999,-0.35559174418449002,-0.35060033202170998,-0.34522733092308,-0.33938094973563998,-0.33473592996597001,-0.33187147974968001,-0.32847353816031999,-0.32399031519889998,-0.31997740268706998,-0.31653416156768999,-0.31466284394263999,-0.31493729352951,-0.31441777944565003,-0.31245526671410001,-0.31035828590393,-0.30815586447715998,-0.30693766474723999,-0.30721402168273998,-0.30660423636436002,-0.30436936020851002,-0.30317887663840998,-0.30348455905914001,-0.30506855249405002,-0.30817839503288003,-0.31105595827103,-0.31322512030602001,-0.31594723463058,-0.31947416067123002,-0.32337585091590998,-0.32786524295807001,-0.33085167407990002,-0.33140164613723999,-0.33357030153275002,-0.33825719356536998,-0.34403300285339,-0.35122182965278997,-0.35604605078696999,-0.35691905021666998,-0.36018711328505998,-0.36736744642258001,-0.37542745471000999,-0.38437891006469999,-0.39099994301795998,-0.39394110441208002,-0.3981240093708,-0.40462100505829002,-0.41182231903076,-0.41970682144165,-0.42694771289825001,-0.43270626664161999,-0.44102346897125,-0.45324540138245001,-0.46519652009009999,-0.47629982233047002,-0.48554414510727001,-0.49210417270660001,-0.49973273277282998,-0.50959157943725997,-0.51847809553145996,-0.52581095695496005,-0.53183746337891002,-0.53622627258301003,-0.54107528924942005,-0.54694056510925004,-0.55286860466002996,-0.55871528387070002,-0.56455582380295,-0.57038754224777,-0.57620173692703003,-0.58198642730713002,-0.58779793977737005,-0.59361493587493996,-0.59966295957564997,-0.60603564977645996,-0.61245453357696999,-0.61896300315857,-0.62494206428527999,-0.63023746013641002,-0.6350514292717,-0.63977420330047996,-0.64185452461242998,-0.63998907804489003,-0.63919705152511996,-0.64071929454803001,-0.64293807744980003,-0.64572650194168002,-0.64854067564010998,-0.65096020698546997,-0.65485441684723,-0.66117364168167003,-0.66636204719543002,-0.66993379592895996,-0.67025130987167003,-0.66597628593445002,-0.66269707679749001,-0.66194432973862005,-0.66138756275177002,-0.66065520048141002,-0.65993469953536998,-0.65932130813598999,-0.65814030170440996,-0.65610635280608998,-0.65404921770096003,-0.65216326713562001,-0.65027093887329002,-0.64840209484099998,-0.64623248577117998,-0.64346438646316995,-0.64147973060607999,-0.64072853326796997,-0.64033275842667003,-0.64016878604889005,-0.64008826017380005,-0.64029413461685003,-0.63916665315627996,-0.63607007265090998,-0.63248199224472001,-0.62854766845703003,-0.62513566017151001,-0.62258052825928001,-0.62038266658783003,-0.61856210231780995,-0.61649769544600996,-0.61390107870101995,-0.61158484220505005,-0.61001533269882002,-0.60741764307021995,-0.60322815179824996,-0.59839689731598,-0.59307318925857999,-0.58727991580963002,-0.58053678274154996,-0.57595390081405995,-0.57504802942276001,-0.5734446644783,-0.57009148597716996,-0.56547492742537997,-0.55922502279282005,-0.55333924293518,-0.54846203327178999,-0.54371333122252996,-0.53890198469161998,-0.53432500362395996,-0.5301873087883,-0.52559155225753995,-0.52014195919036998,-0.51486438512802002,-0.51011615991591996,-0.50511825084686002,-0.49945777654647999,-0.49458241462708002,-0.49111610651016002,-0.48748502135277,-0.48323047161102001,-0.47894236445427002,-0.47468060255050998,-0.47068110108375999,-0.46719011664391003,-0.46325722336768999,-0.45857065916061002,-0.45354279875754999,-0.44825088977813998,-0.44265168905258001,-0.43668350577353998,-0.43067809939384,-0.42468613386154003,-0.41891297698021002,-0.41342118382454002,-0.40829038619995001,-0.40384921431540999,-0.39845925569534002,-0.39146488904952997,-0.38406062126160001,-0.37664395570754999,-0.36835908889771002,-0.35841310024261003,-0.3501059114933,-0.34487026929855003,-0.33972764015197998,-0.33398160338402,-0.32767233252525002,-0.32039791345596003,-0.31381756067276001,-0.30877780914307001,-0.30314821004867998,-0.29629039764404003,-0.28876420855522,-0.28035932779312001,-0.27260333299637002,-0.26627165079116999,-0.25962027907371998,-0.25212594866753002,-0.24427878856658999,-0.23592700064182001,-0.22830693423748,-0.22240839898586001,-0.21494030952453999,-0.20451244711875999,-0.19369332492352001,-0.18300756812096,-0.17285695672035001,-0.16361457109451,-0.15447208285332001,-0.14514282345772,-0.13606709241866999,-0.12735858559607999,-0.11897177249193,-0.11126726865768,-0.10239429026841999,-0.091554932296275995,-0.079992756247520003,-0.067959614098071996,-0.055546566843986997,-0.042414456605910998,-0.030748244374989998,-0.022065995261073001,-0.012086289934814001,0.00077791325747967005,0.014604483731091,0.029652336612344,0.042586207389832001,0.051223188638687002,0.061049897223711,0.074097551405430007,0.087831839919089993,0.10228312015533,0.11453153938055,0.12206552177667999,0.13243985176086001,0.14893592894077001,0.16626559197902999,0.18356835842133001,0.19862957298756001,0.20924425125122001,0.22175821661949,0.23897622525692,0.25631505250931003,0.27287614345550998,0.28731483221053999,0.29732966423035001,0.31116151809692,0.33300274610518998,0.35494607686995999,0.37500756978989003,0.39245966076851002,0.40575504302978999,0.41946473717690003,0.43586829304695002,0.45068708062172003,0.46252289414406,0.47227591276169001,0.47767013311385997,0.49027296900749001,0.51731956005096003,0.54274493455886996,0.56096524000168002,0.57619774341582997,0.58815425634384,0.60099327564240002,0.61724978685378995,0.63204127550125,0.64341282844543002,0.65394818782805997,0.66319918632507002,0.67639464139937999,0.69766867160796997,0.71657240390777999,0.72912287712097001,0.73872894048690996,0.74579101800919001,0.75111877918242997,0.75462651252747004,0.75848698616027999,0.76337260007857999,0.76999264955520996,0.77861082553864003,0.79001641273499001,0.80644047260284002,0.81920218467712003,0.82430785894393999,0.82628041505813998,0.82629680633545,0.82367825508117998,0.81716513633728005,0.81227362155913996,0.81113755702972001,0.81302380561829002,0.81816697120667004,0.82612401247025002,0.83859544992446999,0.84723871946335005,0.84825956821441995,0.84493023157119995,0.83760762214661,0.82732671499251997,0.81279051303864003,0.80208450555801003,0.79935544729232999,0.79986083507537997,0.80272889137268,0.80670571327208995,0.81219315528869995,0.81434947252274004,0.81112253665923995,0.80291289091109996,0.78831791877747004,0.77245146036148005,0.75599688291550005,0.74431788921356001,0.74092543125152999,0.74098908901214999,0.74382168054580999,0.74643641710280995,0.74778568744659002,0.74634879827499001,0.74205946922302002,0.73128545284270996,0.70956379175186002,0.68942916393279996,0.67542773485184004,0.66764581203461004,0.66770941019058005,0.67269963026046997,0.68325245380402,0.69248795509338001,0.69729137420653997,0.69861894845963002,0.69645297527312999,0.68993085622786998,0.67685413360596003,0.66500788927078003,0.65792208909988004,0.65348076820374001,0.65178406238555997,0.65140134096145996,0.65230762958527,0.65195012092589999,0.64889544248580999,0.64431673288345004,0.63849866390228005,0.63121759891509999,0.62148106098175004,0.61330419778823997,0.60874271392821999,0.60604000091553001,0.60486841201782005,0.60501289367676003,0.60728633403777998,0.60755020380019997,0.60317766666411998,0.59780806303024003,0.59261184930801003,0.58752775192260998,0.58239078521729004,0.57876878976821999,0.57758730649947998,0.57793152332305997,0.57965165376662997,0.58241075277328003,0.58687371015548995,0.58947098255157004,0.58770906925201005,0.58541554212570002,0.58407342433928999,0.58304029703140003,0.58309119939803999,0.58099174499511996,0.57414287328720004,0.56744784116744995,0.56313610076903997,0.55962699651717995,0.55692636966705,0.55375111103057995,0.54898929595946999,0.54461699724196999,0.54166138172150002,0.53896576166152999,0.53639370203018,0.53305059671402,0.52814543247223,0.52296990156173995,0.51826512813568004,0.51298874616623003,0.50719898939133001,0.49914675951004001,0.48665761947632002,0.47499698400496998,0.46749037504196,0.45963755249977001,0.44981554150580999,0.43819811940192999,0.42382100224495001,0.40949127078056002,0.39679017663001998,0.38432490825652998,0.37167176604271002,0.35901394486427002,0.34615832567214999,0.33388391137123002,0.32272791862487998,0.31200236082076999,0.30143284797668002,0.29114222526549999,0.28100141882896001,0.27158328890799999,0.26448869705200001,0.25450715422629999,0.23833346366881999,0.21944601833819999,0.19787202775477999,0.17785699665546001,0.16194692254066001,0.14907844364643,0.13965648412703999,0.13210433721542,0.12603822350502,0.12006863951683,0.11482805013657001,0.10460839420557,0.084612913429736994,0.061895146965981002,0.038714908063411997,0.016999317333102001,-0.0025012791156768998,-0.016637502238153998,-0.021783497184514999,-0.024525012820959001,-0.027752397581934998,-0.031135203316808,-0.033420331776142002,-0.041229061782360001,-0.060701936483382998,-0.081460684537888003,-0.098760470747947998,-0.11388225853443,-0.12692177295685,-0.13612420856953,-0.13929039239883001,-0.14105549454689001,-0.14366732537745999,-0.14660939574241999,-0.14847649633884,-0.15544006228446999,-0.17349967360497001,-0.19219480454922,-0.20621992647647999,-0.21811363101006001,-0.22798480093479001,-0.23631460964680001,-0.24352638423442999,-0.24916514754294999,-0.25261691212654003,-0.25553011894226002,-0.25834959745406999,-0.26248374581336997,-0.26967060565947998,-0.27690821886063,-0.28190350532531999,-0.28806984424590998,-0.29637464880942999,-0.30877962708473,-0.32955709099769998,-0.34811460971831998,-0.35730016231536998,-0.36382803320884999,-0.37011903524398998,-0.37585803866385997,-0.38167989253998003,-0.38664373755455,-0.38895919919013999,-0.39362204074860002,-0.40355706214905002,-0.41769564151763999,-0.43964341282844999,-0.45645049214362998,-0.45774203538894997,-0.45545998215674999,-0.45506003499031,-0.45436415076255998,-0.45297724008559997,-0.45220243930817,-0.45208427309990001,-0.45504209399223,-0.46339863538741999,-0.47430649399757002,-0.4880148768425,-0.49924176931380998,-0.50299388170241999,-0.50545489788054998,-0.50971060991286998,-0.51433318853377996,-0.51915204524993996,-0.52423423528670998,-0.52894693613052002,-0.53555417060851995,-0.54621893167496005,-0.55786722898482999,-0.56936091184616,-0.57961404323578003,-0.58676284551619995,-0.59392547607421997,-0.60354751348494995,-0.61250376701355003,-0.61918872594832997,-0.62423503398894997,-0.62759262323380005,-0.62946462631225997,-0.6290699839592,-0.62956821918488004,-0.63301539421081998,-0.63883280754089,-0.64758962392806996,-0.65778827667235995,-0.66945111751555997,-0.67952859401703003,-0.68567883968353005,-0.68897020816803001,-0.68924474716187001,-0.68745005130768,-0.68279635906219005,-0.68009942770003995,-0.68333727121353005,-0.68934828042983998,-0.69773489236831998,-0.70597714185714999,-0.71235817670821999,-0.71650427579880005,-0.71734762191771995,-0.71615034341812001,-0.71338492631911998,-0.70944547653197998,-0.70314246416091997,-0.6999180316925,-0.70500808954239003,-0.71239596605301003,-0.71933263540268,-0.72553420066832996,-0.73030865192412997,-0.73287773132323997,-0.73195362091063998,-0.72943186759948997,-0.72640830278396995,-0.72254943847655995,-0.71665364503859996,-0.71298009157180997,-0.71593409776688,-0.71982330083847001,-0.72143405675887995,-0.72179245948792004,-0.72050392627715998,-0.71850067377089999,-0.71648925542830999,-0.71400421857833996,-0.71078580617904996,-0.70720666646956998,-0.70344835519791005,-0.69957685470580999,-0.69540196657180997,-0.69188505411148005,-0.68984121084213001,-0.68874317407607999,-0.68896919488907005,-0.68869191408157004,-0.68585485219955,-0.68313229084015004,-0.68249684572220004,-0.68215733766555997,-0.68163692951202004,-0.67985451221465998,-0.67484301328659002,-0.66999071836472002,-0.66796898841857999,-0.66661906242371005,-0.66527444124222002,-0.66316014528275002,-0.65858989953994995,-0.65456897020339999,-0.6539751291275,-0.65337175130844005,-0.65098488330840998,-0.64659082889556996,-0.63782393932342996,-0.63024842739105003,-0.62914377450943004,-0.62918382883071999,-0.62732958793640003,-0.62480425834655995,-0.62113845348357999,-0.61819219589232999,-0.61830860376357999,-0.61818546056747004,-0.61543303728104004,-0.61150783300400002,-0.60645437240600997,-0.60166919231414995,-0.59904509782791004,-0.59609329700470004,-0.59089511632919001,-0.58496767282485995,-0.57822781801223999,-0.57309705018997004,-0.57230383157730003,-0.57327181100845004,-0.57482331991196001,-0.57657003402710005,-0.57784044742583995,-0.57868784666061002,-0.57979172468185003,-0.57848930358886996,-0.57155972719193004,-0.56294828653336004,-0.55476671457291005,-0.54764610528946001,-0.54221552610396995,-0.54010784626007002,-0.54468965530395996,-0.55015486478805997,-0.55224412679671997,-0.55224400758742997,-0.55057686567306996,-0.54533147811890004,-0.53308379650116,-0.51997572183608998,-0.51062947511672996,-0.50363624095917003,-0.49851006269455,-0.49735870957375,-0.50440686941146995,-0.51155072450637995,-0.51221406459808005,-0.50922119617462003,-0.50251394510268999,-0.49369946122169001,-0.48355534672736999,-0.47394505143165999,-0.46693506836891002,-0.46185722947121,-0.45828545093535999,-0.45769324898719999,-0.46355551481246998,-0.46864846348763001,-0.46638938784598999,-0.46078974008559997,-0.45349305868148998,-0.44414508342742998,-0.43226012587547002,-0.41993921995163003,-0.40906456112862,-0.39914444088936002,-0.39010682702065003,-0.38261356949806002,-0.37823912501335,-0.37388533353806003,-0.36665689945220997,-0.35836142301558999,-0.34962895512580999,-0.34079146385192999,-0.33219906687737,-0.32431250810623002,-0.31786671280861001,-0.31223699450492998,-0.30725100636482,-0.30238416790962003,-0.29745110869407998,-0.29136678576469,-0.28285044431686002,-0.27255997061728998,-0.26053252816200001,-0.24728539586067,-0.23253625631332001,-0.21866315603256001,-0.20877204835415,-0.19993841648102001,-0.19011087715625999,-0.18015514314174999,-0.170315772295,-0.16034026443957999,-0.1504717618227,-0.13948053121567,-0.12549841403961001,-0.11085730791091999,-0.097057357430457999,-0.084512010216712993,-0.074839353561401006,-0.065833404660224998,-0.055689465254544997,-0.044987540692091002,-0.033536598086356999,-0.021833134815097001,-0.010728503577411,0.0010658045066521001,0.015230132266879,0.029679019004107,0.042923666536808,0.054914813488722,0.070384144783020006,0.073505312204361004,0.097728654742241003,0.10874711722136,0.12306378036736999,0.13590396940707999,0.14942429959774001,0.16501820087433,0.18022195994854001,0.19256113469600999,0.20338378846645,0.2130146920681,0.22207665443419999,0.23119518160819999,0.24072808027267001,0.25147506594657998,0.26278135180473,0.27418893575668002,0.28586506843567,0.29790371656418002,0.31007453799248003,0.32226774096489003,0.33419498801231001,0.34548309445380998,0.35623410344124001,0.36574238538741999,0.37602692842483998,0.38982269167900002,0.40461504459380998,0.41860368847847002,0.4320524930954,0.44457083940505998,0.45628678798675998,0.46735256910324002,0.47732108831406,0.48569473624228998,0.49268254637718001,0.49720627069473,0.50257110595703003,0.51356858015060003,0.52553230524062999,0.53448730707169001,0.54218149185180997,0.54813444614410001,0.55520051717758001,0.56814992427826005,0.58170557022095004,0.59095978736876997,0.59823304414749001,0.60315859317779996,0.60915738344193004,0.62204176187515003,0.63559436798096003,0.64376628398894997,0.65004032850266003,0.65546685457230003,0.66198581457137995,0.67395609617232999,0.68619340658187999,0.69310045242310003,0.69847643375396995,0.70464944839478005,0.71147257089615001,0.72074180841446001,0.72925215959548995,0.73226678371428999,0.73473334312438998,0.74070274829865002,0.74990272521973,0.76592546701430997,0.78185057640075994,0.78859215974807995,0.79294878244400002,0.79999721050261996,0.80827260017394997,0.81901806592940996,0.82916796207428001,0.83400046825409002,0.83801358938216997,0.84538918733597002,0.85433548688889005,0.86536175012589001,0.87542665004730003,0.87953734397887995,0.88211709260940996,0.8872737288475,0.89304953813553001,0.89873927831650002,0.90406566858292003,0.90769183635712003,0.91169750690460005,0.91868019104003995,0.92699795961380005,0.93610388040543002,0.94468539953232,0.95056736469268999,0.95476084947586004,0.95747339725493996,0.95927137136458995,0.96088230609893999,0.96245032548903997,0.96410870552062999,0.96677523851394997,0.97232925891875999,0.97885900735855003,0.98473817110062001,0.98986089229583996,0.99337452650070002,0.99552518129348999,0.99590039253234997,0.99558770656586004,0.99601215124130005,0.99659740924835005,0.99708580970764005,0.99770581722259999,0.99900430440902999,0.99999600648880005,0.99948781728744995,0.99787420034409002,0.99546581506729004,0.99150848388671997,0.98413133621215998,0.97614079713821,0.97087699174881004,0.96715646982193004,0.96518594026565996,0.96379435062408003,0.96141451597214,0.95835918188095004,0.95437264442444003,0.94956618547439997,0.94405925273894997,0.93764185905456998,0.92961376905440996,0.92125964164733998,0.91437721252440995,0.90797144174576006,0.90135282278061002,0.89474213123321999,0.88823455572127996,0.88162529468535999,0.87458020448685003,0.86735802888869995,0.86026269197464,0.85305434465408003,0.84594976902008001,0.83780598640441994,0.82625633478164995,0.81370866298676003,0.80286818742751997,0.79276025295258001,0.78370183706284002,0.77419668436050004,0.7611443400383,0.74766588211060003,0.73761832714080999,0.72888761758803999,0.72081959247589,0.71149730682373002,0.69630622863769998,0.67967844009399003,0.66677182912827004,0.65539181232452004,0.64499455690384,0.63444733619689997,0.62088596820830999,0.60706037282944003,0.59647494554519997,0.58707273006438998,0.57774996757507002,0.56748449802399004,0.55303966999053999,0.53787630796431996,0.52651673555374001,0.51664084196090998,0.50699383020401001,0.49701130390166998,0.48447546362876998,0.47168052196503002,0.46191382408142001,0.45289126038550997,0.44271191954612998,0.43119075894356002,0.41618233919143999,0.40049013495445002,0.38831067085266002,0.37714955210686002,0.36473199725151001,0.35197210311889998,0.33887705206870999,0.32647603750228998,0.31731709837914002,0.30878522992134,0.29747885465621998,0.28482297062874001,0.27105551958084001,0.25737154483794999,0.24635247886181,0.23628005385399001,0.22540549933910001,0.21435278654098999,0.20303127169609,0.19220186769962,0.18388591706752999,0.17577841877937,0.16448093950748,0.15181809663772999,0.13887648284435,0.12635402381419999,0.11656872183083999,0.10757926851511,0.096866406500339994,0.085696458816528001,0.074936226010323001,0.064646534621716004,0.055859956890345001,0.047144360840320997,0.036082405596971998,0.024201886728406001,0.012909655459225001,0.0021130200475454001,-0.0075040240772069004,-0.016476159915328002,-0.025387719273566998,-0.034160360693932003,-0.042994707822800002,-0.051720753312110998,-0.059716198593377998,-0.068097420036793005,-0.079195573925971999,-0.091016560792923001,-0.10088916122913,-0.10994517058134,-0.11886896193027,-0.12760595977306,-0.13645094633102001,-0.14519791305065,-0.15361821651459001,-0.16176684200763999,-0.16921001672745001,-0.17701423168182001,-0.18768645823002,-0.19892355799674999,-0.20746642351151001,-0.21462434530258001,-0.22104907035828,-0.22693079710007,-0.23318336904049,-0.23905591666698001,-0.24311204254627,-0.24679632484913,-0.25203439593315002,-0.25856161117554,-0.26775172352790999,-0.27725663781165999,-0.28258591890335,-0.28639644384384,-0.29146936535835,-0.29719173908233998,-0.30439558625221003,-0.31154435873031999,-0.31546920537949003,-0.31832784414290999,-0.32271739840508001,-0.32795369625092002,-0.33474782109260998,-0.34133997559547002,-0.34396466612816001,-0.34503698348999001,-0.34733095765114003,-0.35026755928992998,-0.35462120175362,-0.35912951827049,-0.36078014969826,-0.36231088638306003,-0.36832070350647,-0.37618345022201999,-0.38381758332253002,-0.38996535539626997,-0.38965457677840998,-0.38703060150146001,-0.38840851187705999,-0.39110910892487,-0.39328026771544999,-0.39474114775657998,-0.39326095581054998,-0.39134645462036,-0.39365091919898998,-0.39756581187248002,-0.40037247538567,-0.40227839350700001,-0.40151369571686002,-0.40016433596611001,-0.40224158763884998,-0.40544855594634999,-0.40702822804451,-0.40782958269119002,-0.40806025266647,-0.40791481733321999,-0.40773642063141002,-0.40780603885651001,-0.40897464752196999,-0.41089817881584001,-0.41359063982964001,-0.41643482446670999,-0.41770803928375,-0.41869756579398998,-0.42136090993880998,-0.42497304081916998,-0.42948865890503002,-0.43392610549927002,-0.43559363484383001,-0.43628191947937001,-0.43872547149657998,-0.44163849949836997,-0.44374582171440002,-0.44522619247437001,-0.44532448053360002,-0.44519871473312,-0.44723081588745001,-0.45035180449486001,-0.45361152291298001,-0.45699480175972002,-0.45978218317031999,-0.46250525116919999,-0.46611306071281,-0.47004291415214999,-0.47361856698990001,-0.47685337066650002,-0.47904735803603998,-0.48111611604691001,-0.48516389727592002,-0.48982942104339999,-0.49327927827835,-0.49572241306304998,-0.49570351839066001,-0.49547672271728999,-0.50035339593886996,-0.50714260339737005,-0.51123648881911998,-0.51411873102187999,-0.51622629165649003,-0.51838213205338002,-0.52330023050308005,-0.52916991710662997,-0.53315985202788996,-0.53617310523987005,-0.53846478462219005,-0.54055982828140003,-0.54428356885910001,-0.54827982187270996,-0.55007737874984997,-0.55083018541336004,-0.55168128013610995,-0.55281275510787997,-0.55557841062545998,-0.55910152196884,-0.56210285425186002,-0.56476932764053001,-0.56666272878646995,-0.56821691989899004,-0.57050311565399003,-0.57271343469619995,-0.57309156656265003,-0.57283717393875,-0.57385396957396995,-0.57578706741332997,-0.57911640405654996,-0.58320188522339,-0.58698034286499001,-0.59022223949431996,-0.59176379442214999,-0.59181159734725997,-0.58965677022934004,-0.58653932809830001,-0.58538472652435003,-0.58508044481277,-0.58452349901198997,-0.58396667242050004,-0.58332455158233998,-0.58282291889190996,-0.58324104547500999,-0.58387964963912997,-0.58325421810150002,-0.58199495077133001,-0.58061778545380005,-0.57947671413421997,-0.58055746555328003,-0.58187836408615001,-0.57906121015548995,-0.57388275861740001,-0.56771647930144997,-0.56160044670105003,-0.55975204706192005,-0.55984067916869995,-0.55807584524154996,-0.55564433336258001,-0.55325388908385997,-0.55115038156509,-0.55096900463104004,-0.55119144916534002,-0.54829853773116999,-0.54393452405929998,-0.54026782512664995,-0.53710681200027,-0.53558260202408003,-0.53472316265106001,-0.53243505954741999,-0.52948820590973,-0.52671784162520996,-0.52395254373550004,-0.52169102430344005,-0.51889175176619995,-0.51224786043167003,-0.50392687320708995,-0.49802953004836997,-0.49344182014464999,-0.48975136876106001,-0.48664459586143,-0.48298728466034002,-0.47911655902862998,-0.47527003288268999,-0.47141039371490001,-0.46783271431923001,-0.46396380662918002,-0.45803642272949002,-0.45105403661728,-0.44469326734543002,-0.43877083063125999,-0.43384060263634,-0.42967143654822998,-0.42647296190262002,-0.42323121428490001,-0.41672885417937999,-0.40845218300818997,-0.40055948495865001,-0.39288482069969,-0.38653159141540999,-0.38074338436126998,-0.37374526262282998,-0.36642512679099998,-0.36030742526053999,-0.35505658388138001,-0.35108238458633001,-0.34742414951324002,-0.34112608432769997,-0.33350631594657998,-0.32664474844933,-0.32010960578918002,-0.31420367956160999,-0.30826357007027,-0.30008262395858998,-0.29090011119843001,-0.28307694196701,-0.27612948417664002,-0.27048280835152,-0.26525908708571999,-0.25759449601173001,-0.24895641207694999,-0.24224700033665,-0.23649172484875,-0.23080877959727999,-0.22479850053787001,-0.21646857261658001,-0.20663668215275,-0.19642621278763001,-0.18586768209933999,-0.17565253376960999,-0.16581891477107999,-0.15719830989837999,-0.14916561543941001,-0.14009486138821001,-0.13066032528877,-0.12185403704643,-0.11368879675865,-0.10739392787218,-0.10169479995966001,-0.092980407178402003,-0.082552105188370001,-0.072102002799510997,-0.061630867421627003,-0.052484598010777997,-0.043865930289029999,-0.033830307424068,-0.023196524009109001,-0.013383781537414,-0.0041446983814239996,0.0042076483368874004,0.012143493629992,0.021159419789910001,0.030670113861560998,0.039608642458916002,0.048350758850574001,0.057524681091309003,0.066921524703503002,0.076275184750557001,0.085568793118000003,0.094537310302257996,0.10330577939749,0.11217326670885,0.12098844349384,0.12932160496712,0.13744160532951,0.14608727395535001,0.15494924783707001,0.16330821812153001,0.17153838276863001,0.18066604435444,0.19015651941299,0.19876077771187001,0.20681706070899999,0.21464468538761,0.22226679325104001,0.22971999645232999,0.2374073266983,0.24708105623721999,0.25790220499039002,0.268110871315,0.27795445919036998,0.28700739145278997,0.29561716318129999,0.30495950579643,0.31440094113349998,0.32230222225188998,0.32919821143150002,0.33582931756973,0.34225380420684998,0.34931764006615001,0.35659366846085,0.36300301551818998,0.36890754103661,0.37453415989875999,0.38049870729446,0.38991513848304998,0.40104866027831998,0.40924456715584001,0.41587230563164002,0.42261347174643998,0.42971679568290999,0.44005069136620001,0.45165565609932001,0.45857119560241999,0.46275261044501997,0.46713545918464999,0.47198057174683,0.48115128278732,0.49237418174744002,0.49903520941733998,0.50326097011565996,0.50865483283997004,0.51480948925018,0.52326428890228005,0.53250122070312,0.53694498538971003,0.53883326053618996,0.54305475950241,0.54888147115706998,0.55771017074585005,0.56768745183945002,0.57164400815964,0.57223087549210006,0.57509738206863004,0.57923954725266003,0.58493614196777,0.59130656719207997,0.59439307451248002,0.59600961208344005,0.60101336240768,0.60817605257034002,0.61625862121581998,0.62474471330643,0.63031721115112005,0.63421553373337003,0.63929587602615001,0.64492738246918002,0.65066564083098999,0.65621370077133001,0.65960752964019997,0.66191756725311002,0.66648793220519997,0.67237609624863004,0.67815321683884,0.68370044231414995,0.68732875585555997,0.68969762325286998,0.69240343570708995,0.69516992568970004,0.69804209470749001,0.70080435276030995,0.70232176780700994,0.70319843292235995,0.70548611879348999,0.70848804712295999,0.71058720350266003,0.71206724643706998,0.71316117048264005,0.71368038654327004,0.71268361806869995,0.71068686246872004,0.70937073230742997,0.70837539434432995,0.70740848779678001,0.70631998777390004,0.70408356189728005,0.70113247632980003,0.69872581958770996,0.69659477472304998,0.69449275732039994,0.69232273101806996,0.68926995992661,0.68579351902008001,0.68354177474975997,0.68206173181534002,0.68065631389617998,0.67910194396973,0.67561978101730003,0.67088639736176003,0.66693675518036,0.66319715976714999,0.65840744972229004,0.65275549888610995,0.64590197801589999,0.63842576742171997,0.63304150104523005,0.62899804115294999,0.62472254037857,0.62037825584411999,0.61565172672271995,0.61061221361160001,0.60532647371292003,0.59978580474854004,0.59395188093185003,0.58788293600081998,0.58192443847655995,0.57590150833130005,0.56910943984984996,0.56178748607634998,0.55466318130492998,0.54755926132202004,0.53993535041809004,0.53211748600006004,0.52550780773162997,0.51970243453979004,0.51375645399094005,0.50769942998885997,0.50096690654755005,0.49370622634888001,0.48601558804512002,0.47817897796630998,0.47194206714629999,0.46674862504004999,0.46131694316864003,0.45540705323219,0.44622769951820002,0.43503659963607999,0.42664915323257002,0.4199495613575,0.41273313760757002,0.40507376194,0.39532324671745001,0.38441690802574002,0.37642154097557001,0.37030506134032998,0.36364570260048001,0.35659217834473,0.34776282310486001,0.33798882365227001,0.33121374249458002,0.32622030377388,0.31920203566550998,0.31073385477066001,0.30080008506775002,0.28997397422790999,0.28164950013161,0.27495688199996998,0.26750543713570002,0.25972375273705001,0.25214162468910001,0.24491761624812999,0.23975084722042,0.23581342399120001,0.22953878343105,0.22156378626823001,0.21249710023403001,0.20276442170143,0.1956413090229,0.19013337790966001,0.18281623721123,0.17430758476256999,0.16563223302364,0.15676333010196999,0.14826583862305001,0.14002108573913999,0.13175490498542999,0.12354028970003,0.115583345294,0.10790965706110001,0.10090274363755999,0.094417996704577997,0.087885327637196003,0.081364318728447002,0.074822187423705999,0.068222612142563005,0.061372250318527,0.054199896752834001,0.045977730304002998,0.036957096308470001,0.028077390044928,0.019305281341076001,0.011258846148849,0.0037186713889241002,-0.0042296932078897996,-0.012438748963176999,-0.020709145814179999,-0.029001379385591001,-0.037118662148714003,-0.044857472181320003,-0.050445370376110001,-0.054435972124337997,-0.059033911675215003,-0.064011916518211004,-0.069510839879512995,-0.075559630990028007,-0.082667373120784995,-0.090620040893555007,-0.098384454846382002,-0.1060878932476,-0.11378712952137,-0.12147807329893,-0.12929007411002999,-0.13703368604183,-0.1433487534523,-0.14857733249664001,-0.15396924316883001,-0.15942940115929,-0.16530215740203999,-0.17148232460022,-0.17753696441649999,-0.18352751433848999,-0.18955920636654,-0.19561792910098999,-0.20178589224815,-0.20792374014854001,-0.21293927729129999,-0.21712933480739999,-0.22169776260853,-0.22660025954247001,-0.23284097015857999,-0.23986589908600001,-0.24414478242397,-0.24638395011424999,-0.24895709753035999,-0.25168561935424999,-0.25525861978531,-0.25934118032455,-0.26180979609489002,-0.26314347982406999,-0.26537799835205,-0.26821771264076,-0.27115595340728998,-0.27403733134269997,-0.27496758103371,-0.27451899647713002,-0.27580538392067,-0.27829670906067,-0.28036236763,-0.28208115696906999,-0.28266456723213002,-0.2824028134346,-0.28299862146378002,-0.28419983386992997,-0.28533738851547003,-0.28646883368491999,-0.28739115595817999,-0.28832173347473,-0.29120117425919001,-0.29548838734626998,-0.29841712117195002,-0.30010852217674,-0.29871135950089001,-0.29507628083228998,-0.29531618952750999,-0.29828709363937,-0.29909047484397999,-0.29830461740494002,-0.29674836993217002,-0.29469481110572998,-0.29540067911147999,-0.29817253351211997,-0.29958066344260997,-0.30001962184906,-0.3000710606575,-0.29987061023712003,-0.30124098062514998,-0.30376002192496998,-0.30508011579513999,-0.30548825860022999,-0.30566963553429,-0.30560389161110002,-0.30551707744598,-0.30545079708098999,-0.30608129501343001,-0.30727949738503002,-0.30841866135597001,-0.30955016613007003,-0.31061846017838002,-0.31166931986808999,-0.31318375468254001,-0.31501230597495999,-0.31606283783912997,-0.31647312641143999,-0.31658101081848,-0.31645315885544001,-0.31713402271271002,-0.31840282678603998,-0.31895312666893,-0.31889793276786998,-0.31802958250045998,-0.31661856174469,-0.31751805543900002,-0.32020092010498002,-0.32162430882454002,-0.32207116484642001,-0.32179206609726002,-0.32095924019813998,-0.32181859016418002,-0.32388377189635997,-0.32370296120643999,-0.32173204421996998,-0.31973117589951,-0.31779986619949002,-0.31881970167160001,-0.32219523191451999,-0.32378771901130998,-0.32404580712317999,-0.32451733946799999,-0.32508799433708002,-0.32572689652442999,-0.32634818553924999,-0.32589787244797003,-0.32454815506934998,-0.32317021489143,-0.32185992598534002,-0.32283678650856001,-0.32562011480330999,-0.32629716396331998,-0.32532942295074002,-0.32484400272369002,-0.32474473118781999,-0.32575887441634999,-0.32766541838646002,-0.32838279008865001,-0.32814550399780001,-0.32807114720344999,-0.32807993888855003,-0.32811617851257002,-0.32813498377799999,-0.32753926515579002,-0.32639187574387002,-0.32490146160125999,-0.32310765981674,-0.32174909114838002,-0.32072448730469,-0.31936651468277,-0.31771543622017001,-0.31571388244629001,-0.31339609622955,-0.31101545691490001,-0.30864563584327998,-0.30775469541549999,-0.30808183550835,-0.30721572041512002,-0.30538171529769997,-0.30355459451674999,-0.30176371335982999,-0.30140548944473,-0.30223602056503002,-0.30188301205634999,-0.30057924985885998,-0.29960295557976002,-0.29894223809241999,-0.29970151185989002,-0.30164495110512002,-0.30209916830062999,-0.30132421851157998,-0.30089533329009999,-0.30077046155929998,-0.30184718966483998,-0.30389881134032998,-0.30401068925857999,-0.30248168110847001,-0.301513671875,-0.30099710822105002,-0.30120161175728,-0.30197614431380998,-0.30088421702384999,-0.29823207855224998,-0.29702016711235002,-0.29707130789757002,-0.29809439182281,-0.30001643300056002,-0.30141267180442999,-0.30238473415375,-0.30348244309424999,-0.30464503169059998,-0.30513522028923001,-0.30502372980117998,-0.30498531460762002,-0.30497214198111999,-0.30461177229880998,-0.30395343899727001,-0.30365911126137002,-0.30368092656135998,-0.30368936061858998,-0.30369654297829002,-0.30364042520522999,-0.30354258418083002,-0.30376583337784002,-0.30429312586784002,-0.30529552698134999,-0.30667012929915999,-0.30624914169312001,-0.30422526597977001,-0.30273279547691001,-0.30166548490523998,-0.30064430832862998,-0.29964917898178001,-0.29793268442153997,-0.29555979371071001,-0.29322928190231001,-0.29094082117080999,-0.28946048021317,-0.28868162631988997,-0.28666999936103998,-0.28357636928558,-0.28135788440704002,-0.27990716695786,-0.27857682108879001,-0.27726811170577997,-0.272555321455,-0.26474314928054998,-0.25850695371628002,-0.25366464257240001,-0.24980874359607999,-0.24686266481876001,-0.24240201711654999,-0.23660297691821999,-0.23221193253993999,-0.22908613085747001,-0.22571411728859,-0.22209644317627,-0.21672180294991,-0.20973055064678001,-0.20394387841225001,-0.19923925399779999,-0.19457273185252999,-0.18991383910178999,-0.18327248096466001,-0.17477054893970001,-0.16643518209457001,-0.15821778774261,-0.15026669204234999,-0.14258313179015999,-0.13554385304451,-0.12911982834339,-0.12267032265663,-0.11620324105024001,-0.10935402661562001,-0.10215086489916,-0.095404937863349998,-0.089064538478850999,-0.081728674471377993,-0.073452509939671007,-0.065241433680057997,-0.057068314403296003,-0.048711497336625997,-0.040158867835999,-0.030528046190739001,-0.019882081076503001,-0.010391822084785,-0.0019946731626987002,0.0063346698880195999,0.014569476246834001,0.022144451737404001,0.029081782326102,0.036078508943319001,0.043122544884682,0.050170868635178001,0.057227779179810999,0.064583338797091994,0.072227776050568002,0.079836517572402996,0.087414525449275998,0.095007508993148998,0.10261126607656,0.10992904752493,0.1169683560729,0.12396604567765999,0.13092382252216,0.13820561766624001,0.14580640196799999,0.15386390686035001,0.16235268115997001,0.16883461177348999,0.17335733771324,0.17830668389797,0.18366128206252999,0.18926724791527,0.19512939453125,0.20195333659649001,0.20972628891468001,0.21738930046558,0.22494974732399001,0.23264476656913999,0.24046362936497001,0.24637465178967,0.2503981590271,0.25482615828513999,0.25964933633803999,0.26471883058548001,0.27003622055054,0.27639830112456998,0.28379845619201999,0.28953039646148998,0.29360020160674999,0.29765024781227001,0.30167955160141002,0.30742108821869002,0.31487730145454002,0.32093283534049999,0.32558235526085,0.33016845583915999,0.33468857407570002,0.34138461947441001,0.35027959942817999,0.35607001185416998,0.35872116684914002,0.36217528581619002,0.36644816398621,0.37183669209480003,0.37836825847625999,0.38152095675468001,0.38123050332068997,0.38299560546875,0.38686060905456998,0.39209628105164002,0.39873757958411998,0.40193745493888999,0.40159946680068997,0.40362641215324002,0.40809154510498002,0.41332086920737998,0.41934287548065002,0.42205956578254999,0.42136660218239003,0.42211198806763001,0.42436739802361001,0.42698660492897,0.42998465895652999,0.43114963173866,0.43038275837897999,0.4325769841671,0.43785604834557001,0.44286477565764998,0.44758909940719999,0.44965937733650002,0.44895806908607,0.45003470778464999,0.45301130414009,0.45539870858192,0.45717740058898998,0.45699992775916998,0.45476105809211997,0.45456141233443997,0.45653936266898998,0.45780792832375,0.45830267667770003,0.4584544301033,0.45824679732322998,0.45873892307281,0.45998671650887002,0.46060997247696001,0.46057513356209001,0.45990964770317,0.45857977867125999,0.45793831348419001,0.45803996920585999,0.45807498693465998,0.45802268385887002,0.45812958478928001,0.45846009254455999,0.45659551024437001,0.45238459110259999,0.44889917969704002,0.44625496864318998,0.44346669316291998,0.44056683778763001,0.43539589643477999,0.42775681614875999,0.42201587557793002,0.41836366057396002,0.41508373618125999,0.41219070553780002,0.40755277872085999,0.40096262097358998,0.39670029282570002,0.39503541588782998,0.39216881990433,0.38798925280571001,0.38183614611625999,0.37350514531135998,0.36809524893760998,0.36594551801682002,0.36286911368370001,0.35873448848723999,0.35301572084427002,0.34556904435157998,0.33948755264281999,0.33498886227607999,0.32958889007567999,0.32321101427077997,0.31518444418906999,0.30529409646987998,0.29828384518623002,0.29452589154242997,0.28973361849785001,0.28368470072745999,0.27764651179313998,0.27165991067885997,0.26568800210952997,0.25970935821532998,0.25431922078133001,0.24957664310932001,0.2448121458292,0.24001897871493999,0.23462864756584001,0.22856654226779999,0.22282543778419001,0.21746926009654999,0.21218171715736001,0.20699620246886999,0.20084828138350999,0.19359977543354001,0.1870000064373,0.18116176128386999,0.17555758357048001,0.17017799615859999,0.16469371318817,0.15899026393890001,0.15520063042641,0.15364263951778001,0.15034841001033999,0.1450881510973,0.13790230453013999,0.12852105498314001,0.12200489640235999,0.11889427900313999,0.11446473002434,0.10838703811169,0.1019234135747,0.094960466027259993,0.090799376368523005,0.089928045868873999,0.087221458554267994,0.082300670444965002,0.076341681182384005,0.069143153727054998,0.065377257764339003,0.065717279911040996,0.063618354499340002,0.058506179600954,0.053307760506868002,0.048057064414023999,0.045053664594888999,0.044769424945116001,0.042018305510283002,0.036276243627070999,0.030517525970935998,0.024795964360237,0.021254653111099999,0.020332802087068998,0.017522934824227999,0.012335354462266,0.0077286688610910996,0.0038934252224863001,0.00082935637328773997,-0.0012892805971205,-0.0049803163856267998,-0.010572748258709999,-0.015904661267996001,-0.020879140123725,-0.024704825133085001,-0.027182521298527999,-0.030196946114302001,-0.033931676298380002,-0.037701174616814,-0.041467379778623997,-0.045214198529720001,-0.048933196812868,-0.052671052515507001,-0.056433860212563997,-0.060216099023818997,-0.064061529934406003,-0.067367836833000003,-0.070100829005241005,-0.071927517652511999,-0.072656728327274003,-0.074508436024188995,-0.077725440263748002,-0.081482641398906999,-0.085727654397488001,-0.090518400073050995,-0.095897130668162994,-0.10133414715528,-0.10683301091194,-0.11176701635121999,-0.11610863357782,-0.11933413147926,-0.12124892324209,-0.12376303970814,-0.12715487182140001,-0.13000726699828999,-0.13224409520625999,-0.13325147330761,-0.13270731270312999,-0.13393440842627999,-0.13743852078915,-0.14065958559513,-0.14337328076363001,-0.14572039246558999,-0.14758799970149999,-0.15032820403576,-0.15420359373093001,-0.15753623843192999,-0.16008949279785001,-0.16301448643208,-0.16655330359935999,-0.16890953481196999,-0.16981150209904,-0.17050129175185999,-0.17110075056553001,-0.17137068510056,-0.17121970653533999,-0.17157706618308999,-0.17256426811218001,-0.17387725412846,-0.1755265891552,-0.17715048789978,-0.17870111763477001,-0.180220246315,-0.18162819743156,-0.18389846384524999,-0.18728022277355,-0.19024755060672999,-0.19280429184437001,-0.19305026531218999,-0.19042770564556,-0.18867301940917999,-0.18832167983055001,-0.18771757185459001,-0.18671178817749001,-0.18534263968468001,-0.18347674608230999,-0.18249765038490001,-0.18272206187248,-0.18242442607879999,-0.18140797317028001,-0.17974691092968001,-0.17719821631908,-0.17634479701519001,-0.17783051729202001,-0.17803004384040999,-0.17646093666553,-0.17394994199276001,-0.17028392851353,-0.16828130185604001,-0.16852656006812999,-0.168551415205,-0.16808070242404999,-0.16716432571411,-0.16549164056778001,-0.16617406904696999,-0.17012423276901001,-0.17193183302879,-0.17072521150111999,-0.16884629428386999,-0.16631133854388999,-0.1652262955904,-0.16619847714901001,-0.16607214510441001,-0.16428910195827001,-0.16265055537223999,-0.16122576594353,-0.16132934391498999,-0.16359293460846,-0.1637170612812,-0.16085977852344999,-0.15787419676781,-0.15499900281428999,-0.15290786325931999,-0.15176968276500999,-0.15121528506279,-0.15127727389335999,-0.15133903920649999,-0.15130133926868,-0.15120705962181,-0.15088440477848,-0.15198938548565,-0.15507894754410001,-0.15711206197739,-0.15758150815964,-0.15745843946933999,-0.15664277970790999,-0.15693068504332999,-0.15891014039515999,-0.15961045026779,-0.15844444930553001,-0.1571162045002,-0.15565577149390999,-0.15560519695281999,-0.15748655796051,-0.15885885059834001,-0.15932458639145,-0.15950335562229001,-0.15934689342975999,-0.15978732705116,-0.16119985282421001,-0.16153477132319999,-0.16032876074314001,-0.15905490517616,-0.15778234601020999,-0.15757924318314001,-0.15892216563225001,-0.15923769772053001,-0.15784630179404999,-0.15737281739712,-0.15819405019283,-0.16027234494685999,-0.16409669816493999,-0.16584043204783999,-0.16456177830696,-0.16316585242748,-0.16199888288975001,-0.16137568652629999,-0.16158440709114,-0.16099718213080999,-0.15912140905857,-0.15798984467982999,-0.15800270438194,-0.15832214057446001,-0.15894480049609999,-0.15909273922443001,-0.15851446986198001,-0.15812231600285001,-0.15808726847172,-0.15810203552245999,-0.15817400813103,-0.15799424052238001,-0.15753582119942,-0.15655401349067999,-0.15492235124111001,-0.15321363508701,-0.15140716731548001,-0.15042769908904999,-0.15069599449634999,-0.15021383762359999,-0.14847482740879001,-0.1469192802906,-0.14573101699352001,-0.14511089026928001,-0.14528381824493,-0.14497821033000999,-0.14384636282921001,-0.14288838207721999,-0.14218734204769001,-0.14229367673397,-0.14360423386096999,-0.14397126436234001,-0.14280492067337,-0.14178112149239,-0.14116679131984999,-0.14084343612194,-0.14087139070033999,-0.14089535176754001,-0.14083926379681,-0.14080473780632,-0.14080657064915,-0.14081022143364,-0.14081022143364,-0.14078676700591999,-0.14065080881118999,-0.14103604853153001,-0.14216178655624001,-0.14335806667805001,-0.14474491775036,-0.1445831656456,-0.1420821249485,-0.14048714935779999,-0.14063462615013,-0.14064140617847001,-0.14031629264355,-0.13892157375813,-0.13580648601055001,-0.13434740900993,-0.13556401431560999,-0.13670657575129999,-0.13728669285774001,-0.13759341835975999,-0.13758151233196,-0.13751202821732,-0.13739059865475001,-0.13753536343575001,-0.13807193934917,-0.13867129385471,-0.13948404788971,-0.13904856145382,-0.13677284121513,-0.13463467359542999,-0.13302963972092,-0.13170419633388999,-0.13074268400669001,-0.1295311152935,-0.12775810062885001,-0.12666617333888999,-0.12651886045933,-0.12724761664866999,-0.12935520708560999,-0.12953865528107,-0.12655517458915999,-0.12412117421627,-0.12308215349913,-0.12241221964359,-0.12233067303896,-0.12051009386778,-0.11580920219421,-0.11240848898888001,-0.11152122914791,-0.11060459166765001,-0.10937212407589,-0.10683523118495999,-0.10224206745625,-0.098710924386977997,-0.097205609083176006,-0.095658361911774001,-0.093855820596217998,-0.090811647474766,-0.085870049893855993,-0.081525281071663,-0.078530430793761999,-0.075364850461483002,-0.071817532181740001,-0.067507013678550998,-0.061978418380022,-0.057349424809217002,-0.054360352456569998,-0.051229003816842998,-0.047532185912132,-0.043790388852358003,-0.039906635880469998,-0.036988046020268998,-0.035771660506724999,-0.033318635076283999,-0.028806993737817001,-0.023332403972745001,-0.016771351918577999,-0.010879639536142001,-0.0063659520819783003,-0.0015441381838172999,0.0039251786656678,0.010038129985332,0.017194656655192,0.023228194564581001,0.027299892157316,0.031431373208761,0.036109458655118998,0.040832433849572997,0.045541521161795002,0.050228577107191003,0.054826594889163999,0.059686858206986999,0.065005570650100999,0.070113427937031,0.074837639927864005,0.079282395541667994,0.083259738981723994,0.087909981608391002,0.093693181872367998,0.099546723067759996,0.10516972094774001,0.11106740683317,0.11749859154224,0.12346908450127,0.12856850028038,0.13382475078105999,0.13952682912350001,0.14531846344471,0.15134347975254001,0.1564227938652,0.15996786952018999,0.16359908878803001,0.16781683266163,0.17183977365493999,0.17546039819716999,0.1790370196104,0.18259574472904,0.18639037013054,0.19055853784084001,0.19476470351219,0.19897238910198001,0.20295071601868001,0.20652280747890001,0.21028709411620999,0.21450380980968001,0.21853004395962,0.2221561819315,0.22574552893638999,0.22947518527508001,0.23276478052138999,0.23540969192982,0.2377457767725,0.23983794450759999,0.24164748191832999,0.24282824993134,0.24530521035194,0.24990577995777,0.25497710704803001,0.26016438007354997,0.26548206806183,0.27139621973037997,0.27500632405281,0.27478811144829002,0.27460902929306003,0.27561378479004001,0.27671298384665999,0.27784052491187999,0.27849990129470997,0.27814847230911,0.27883195877075001,0.28136658668518,0.28435990214348,0.28769195079803001,0.29035773873329002,0.2917106449604,0.29341199994087003,0.29609698057174999,0.29865661263465998,0.30102011561393999,0.30222338438034002,0.30164685845375,0.30085474252701,0.30028638243674999,0.29975289106369002,0.29938483238219998,0.29852628707885998,0.29663774371147,0.29555523395538003,0.29610928893089,0.29663681983947998,0.29664155840874001,0.29657053947449002,0.29637649655342002,0.29665657877922003,0.29784882068634,0.29869124293326998,0.29884228110312999,0.29823207855224998,0.29639959335326999,0.29532203078269997,0.29607892036437999,0.29616802930831998,0.29474848508835,0.29268774390220997,0.28988870978355002,0.28762924671173001,0.28663212060928001,0.28537678718567,0.28337487578392001,0.28108295798302002,0.27864041924477001,0.27570042014121998,0.27199056744576,0.26839646697044001,0.26531326770781999,0.26209309697151001,0.25867444276809998,0.2545194029808,0.24885104596614999,0.24455341696739,0.24306011199951,0.24171221256256001,0.24000211060047,0.23696766793728,0.23169673979281999,0.22653234004973999,0.22233110666274999,0.21825461089611001,0.21425226330757,0.20982316136359999,0.20463854074478,0.19937115907669001,0.19429703056812,0.18899708986281999,0.18344938755035001,0.17721502482890999,0.16967050731182001,0.16304458677768999,0.15852226316929,0.15384995937347001,0.14828392863274001,0.14236314594746,0.13592872023582001,0.13008169829845001,0.12553465366364,0.12073289602994999,0.11510297656059,0.10917982459068,0.10297430306673,0.096904456615447998,0.091196022927760995,0.085547789931296997,0.079884231090546001,0.074215769767760995,0.068581372499465998,0.062739796936511993,0.056436188519001,0.050472192466259003,0.045348282903432999,0.039973858743906,0.033998887985944998,0.027469836175441999,0.019990134984255,0.013184594921768,0.0078270081430673998,0.0029808182734995998,-0.0014538629911840001,-0.0060757463797926998,-0.011357055976987,-0.016295956447720999,-0.020316326990723999,-0.024609021842480001,-0.02946369163692,-0.035309199243783999,-0.043169163167477001,-0.049368470907210998,-0.051570836454630002,-0.054483331739901997,-0.059994954615831,-0.066297799348830996,-0.073549501597880998,-0.079264208674431,-0.081568852066994005,-0.084423758089542,-0.089498423039912997,-0.095100156962871996,-0.1013840213418,-0.10587704926729,-0.10651855915785,-0.10804031789302999,-0.11263158917427001,-0.11766096949577,-0.12276974320412,-0.12645074725151001,-0.12714494764805001,-0.12864479422569,-0.13295848667622001,-0.13703824579716001,-0.14008694887161,-0.14153383672236999,-0.13999305665493,-0.13982205092906999,-0.14352396130562001,-0.14720422029495001,-0.14958988130093001,-0.15097108483315,-0.15067307651042999,-0.15111894905567,-0.15381194651127,-0.15625648200511999,-0.15751308202743999,-0.15815541148185999,-0.15782949328422999,-0.15838398039341001,-0.16120728850364999,-0.16354563832283001,-0.16414615511894001,-0.16429035365582001,-0.16415712237357999,-0.16437816619873,-0.16550822556018999,-0.16654115915298001,-0.16701439023018,-0.16744211316109001,-0.16811370849609,-0.16838784515857999,-0.16781562566757,-0.16730841994286,-0.16729347407817999,-0.16736035048962,-0.16763433814049,-0.16713173687457999,-0.16489377617836001,-0.16315148770808999,-0.16302625834942,-0.16335573792458,-0.16402295231819,-0.16418312489986001,-0.16289368271828,-0.16235683858395,-0.16399252414703,-0.16540558636189001,-0.16565769910812,-0.16513046622276001,-0.16333045065403001,-0.16227321326732999,-0.16345667839049999,-0.16424052417278001,-0.16338706016540999,-0.16203758120537001,-0.16007721424103,-0.15920598804951,-0.16094429790973999,-0.16232693195343001,-0.16189692914486001,-0.16099897027016,-0.15960343182087,-0.15929147601127999,-0.16160368919373,-0.16339084506035001,-0.16297674179077001,-0.16217964887618999,-0.16146729886531999,-0.16117112338542999,-0.16197839379310999,-0.16216693818569,-0.16062605381011999,-0.15895041823386999,-0.15769314765930001,-0.15689876675605999,-0.15685671567917001,-0.15697255730629001,-0.15704210102558,-0.15692284703254999,-0.15635983645915999,-0.15590888261795,-0.15588831901549999,-0.15594178438187001,-0.15594178438187001,-0.15594178438187001,-0.15594178438187001,-0.15593147277832001,-0.15565125644207001,-0.15612402558326999,-0.15838830173016,-0.16021732985973,-0.16036839783192,-0.16004098951817,-0.15939782559872001,-0.15921601653098999,-0.16041705012321,-0.16113206744194,-0.16037194430828,-0.15891970694065,-0.15666843950748,-0.15482038259506001,-0.15451566874980999,-0.15371790528297,-0.15129898488522001,-0.14836600422859,-0.14485478401183999,-0.14236436784267001,-0.14235372841357999,-0.14246894419193001,-0.14153340458870001,-0.14040689170361001,-0.13917225599288999,-0.13831126689911,-0.13846252858638999,-0.13825125992298001,-0.13668105006218001,-0.13522148132323999,-0.13458941876888,-0.1343058347702,-0.13477002084254999,-0.13404886424540999,-0.13039229810238001,-0.12669669091701999,-0.12426717579365,-0.12280554324388999,-0.1229095235467,-0.12280266731977001,-0.12125657498837,-0.11963552236557,-0.11842438578606,-0.11766168475151,-0.1178922355175,-0.11756227910519,-0.11549112945795,-0.11324261128902,-0.11156819760799,-0.10999391973019,-0.10822889953852,-0.10699254274368,-0.10692419856787,-0.10694792121648999,-0.10661341995001,-0.10581739246845,-0.10428366065025001,-0.10242115706205,-0.10038007050753001,-0.098253563046454995,-0.096130520105361994,-0.094012439250946003,-0.091800339519978,-0.089943476021290006,-0.088913612067699002,-0.087870828807354001,-0.086239956319331998,-0.084701798856258004,-0.083699278533459001,-0.082609325647354001,-0.081181801855564006,-0.079337947070599005,-0.076715901494026004,-0.074243418872355998,-0.072498470544814994,-0.071122206747532002,-0.070302732288837003,-0.069055758416652999,-0.066297598183155004,-0.063931718468665993,-0.063105948269366996,-0.062977857887745001,-0.063852488994598,-0.063737682998180001,-0.060617294162511999,-0.057560797780752002,-0.056368503719568003,-0.055699836462735998,-0.055363625288009997,-0.054595366120338003,-0.052221242338419002,-0.050557039678097,-0.051295872777700001,-0.052600555121898998,-0.053966507315636,-0.054510291665792,-0.053004693239927,-0.051368027925491,-0.050703775137662999,-0.050383556634187997,-0.050452962517738002,-0.050284326076507999,-0.049238909035921,-0.048182893544436001,-0.047703467309475001,-0.047149658203125,-0.046136323362589,-0.045040253549814002,-0.043915055692196003,-0.043102327734231997,-0.043049626052379997,-0.043022848665714,-0.042617008090018997,-0.041947703808545997,-0.040965631604195002,-0.039750657975674002,-0.038167703896761003,-0.036829955875874003,-0.036228988319635003,-0.035968605428934,-0.036344897001981999,-0.035831470042466999,-0.032627582550049002,-0.029670380055904,-0.029019223526119999,-0.028845166787505001,-0.028783263638616,-0.027615159749985001,-0.023594737052917002,-0.019547434523702001,-0.017407467588782002,-0.015644557774067001,-0.013884047977625999,-0.011502221226692,-0.0071428301744163002,-0.0036439353134482999,-0.0033354973420500998,-0.0037931413389742001,-0.0039889388717710998,-0.0037299967370927,-0.0024795690551399998,-0.00068758317502216003,0.0014690360985695999,0.0039920173585414999,0.0066674556583166001,0.010074994526803001,0.015374884940684,0.019835917279124,0.021030556410550998,0.021615019068122,0.022957570850848999,0.024689700454472999,0.027096370235085002,0.02954969368875,0.031319830566645002,0.033591352403164,0.037238650023937003,0.041558325290680001,0.046359989792109001,0.051351193338633,0.056299746036529999,0.061094295233488,0.065561980009078993,0.069795459508895999,0.073645502328873,0.077683970332145996,0.082705564796924994,0.087342016398906999,0.090451523661613006,0.093156024813651997,0.095661893486976998,0.099038302898406996,0.10501831769943,0.11071152985096,0.11368498206138999,0.11633783578873,0.11952848732471,0.12421947717667001,0.13274919986725001,0.14061203598975999,0.14385430514812,0.14627335965633001,0.14979150891303999,0.15406812727451,0.16027835011482,0.16546499729156,0.16624063253402999,0.16726066172123,0.17152479290962,0.17797176539897999,0.18792557716370001,0.19711561501026001,0.20057632029056999,0.20476743578911,0.21422033011913,0.22620251774788,0.24113583564758001,0.25480410456656999,0.26172688603401001,0.26917460560799,0.28259402513504001,0.29810130596161,0.31506770849228,0.33050039410590998,0.34017434716224998,0.34934502840041998,0.36198517680168002,0.37508720159531,0.38769418001174999,0.39871108531951999,0.40527239441871998,0.41280642151833002,0.42649111151695002,0.44134232401848,0.45487439632415999,0.46673381328583002,0.47436290979384999,0.482666015625,0.49648401141166998,0.51099365949631004,0.52332752943038996,0.53432965278625,0.54275715351105003,0.55211353302001998,0.56637644767760997,0.58112651109695002,0.59363484382628995,0.60444730520248002,0.61279261112213002,0.62000173330306996,0.62685418128966996,0.63374519348144998,0.64131420850753995,0.64934939146042003,0.65786182880402,0.66684919595717995,0.67710918188095004,0.68614357709884999,0.69165205955505005,0.69480073451996005,0.69630765914917003,0.69492423534393,0.68840497732161998,0.68102735280991,0.67667251825332997,0.67283862829207997,0.66878634691238004,0.66363173723221003,0.65529513359070002,0.64709609746932995,0.64240729808806996,0.63796114921570002,0.63182961940765003,0.62414747476578003,0.61407023668288996,0.60273700952529996,0.59118807315826005,0.57857829332351995,0.56453418731688998,0.54884171485901001,0.53000801801681996,0.51167160272598,0.49801477789879001,0.48498225212097001,0.46973350644112,0.45357820391655002,0.43634566664696001,0.41952005028724998,0.40517440438271002,0.39101347327232,0.37548840045928999,0.35880619287491,0.34086486697196999,0.32105961441994002,0.29823848605156,0.27407950162888001,0.24973210692406,0.22539925575256001,0.20162689685821999,0.17846557497978,0.15601003170013,0.13465443253517001,0.11503825336695001,0.096460342407227007,0.078678354620934005,0.061012391000986002,0.042205825448036,0.023832688108086999,0.0074287969619035998,-0.0082698836922646003,-0.023928411304950999,-0.039739463478326999,-0.056689623743296003,-0.073035255074500996,-0.086972236633301003,-0.099745251238346003,-0.11201429367064999,-0.12369809299707001,-0.15143340826035001,-0.14572557806969,-0.15664856135845001,-0.16066788136959001,-0.16570402681828,-0.17045614123344,-0.17383322119712999,-0.17352883517741999,-0.17184789478779,-0.17055605351924999,-0.16902382671832999,-0.16753052175045,-0.16511510312557001,-0.16026706993580001,-0.15484474599361001,-0.15058614313602001,-0.14646250009537001,-0.14206606149673001,-0.1372214704752,-0.13201949000359001,-0.12523938715458,-0.1150309741497,-0.10320818424225001,-0.090909063816071001,-0.078484609723091001,-0.067900940775870999,-0.055599372833967001,-0.036945655941963002,-0.016559485346079001,0.0022266935557126999,0.019572567194700002,0.03343790024519,0.046906888484955001,0.063720732927321999,0.080467462539673004,0.094436392188071996,0.10669308900832999,0.11624506115913,0.12657006084919001,0.14278033375740001,0.15990516543388,0.17390623688698001,0.18608164787292,0.19563268125057001,0.20484387874602999,0.21714980900288,0.22901427745819,0.23721981048584001,0.2433618158102,0.24768708646297,0.25126054883003002,0.25600522756576999,0.26003181934357,0.26135912537575001,0.26162397861481002,0.26187920570374001,0.26231881976128002,0.26415100693702998,0.26561766862869002,0.26487347483634999,0.26277121901512002,0.25974580645561002,0.25539848208427002,0.24934692680835999,0.24183803796768,0.23291398584843001,0.22286441922187999,0.21214604377747001,0.20044946670531999,0.18702411651611001,0.17347863316536,0.16211934387683999,0.15090002119540999,0.13823214173317,0.12427602708340001,0.10765229165553999,0.091150015592575004,0.079165026545525,0.067058086395264005,0.050227280706166999,0.030836675316094998,0.0087608452886343002,-0.013240879401565001,-0.029912222176790002,-0.046970058232545998,-0.070455253124237005,-0.097040027379989999,-0.12649087607861001,-0.1545951962471,-0.17345950007439001,-0.19075950980185999,-0.21445302665234001,-0.23990440368652,-0.26510348916054,-0.28833037614821999,-0.30457618832588002,-0.31985649466514998,-0.34132283926009999,-0.36426922678946999,-0.38572502136230002,-0.40542301535606001,-0.42049008607864002,-0.43484908342361001,-0.45375391840934998,-0.47306936979294001,-0.48966267704964,-0.50351148843765003,-0.51161789894104004,-0.51887905597687001,-0.53202146291732999,-0.54626905918121005,-0.55780494213104004,-0.56770694255829002,-0.57445794343947998,-0.58194440603256004,-0.59684759378433005,-0.61276352405547996,-0.62316524982452004,-0.63062965869903997,-0.63509619235991999,-0.63881188631057995,-0.64577674865723,-0.65290665626526001,-0.65732795000076005,-0.66027408838271995,-0.66205966472625999,-0.66311562061310003,-0.66453295946121005,-0.66520631313323997,-0.66382807493210005,-0.66118562221527,-0.65760588645935003,-0.65361684560776001,-0.65056532621384,-0.64704310894011996,-0.64114171266555997,-0.634421646595,-0.62816935777663996,-0.62248671054839999,-0.61851668357848999,-0.61493510007857999,-0.61009973287581998,-0.60487091541289995,-0.59980082511902,-0.59475141763687001,-0.58954161405562999,-0.58475977182387995,-0.58144605159759999,-0.57876878976821999,-0.57604616880417003,-0.57317799329758001,-0.56962502002715998,-0.56571412086487005,-0.56161761283875,-0.55749315023421997,-0.55366063117981001,-0.55004227161407004,-0.54613727331160999,-0.54335862398148005,-0.54447728395462003,-0.54683178663253995,-0.54715943336487005,-0.54721736907958995,-0.54774671792983998,-0.54980242252349998,-0.55648070573806996,-0.56434178352356001,-0.56898319721222002,-0.57248270511626997,-0.57576650381088001,-0.57940113544464,-0.58562356233597002,-0.59167945384979004,-0.59331488609313998,-0.59373688697814997,-0.59578329324722001,-0.59954530000687001,-0.60783475637436002,-0.61673188209534002,-0.62018847465515003,-0.62214887142180997,-0.62616574764251998,-0.63141918182373002,-0.63910496234893999,-0.64684796333312999,-0.65025407075882002,-0.65295273065567005,-0.65901350975036999,-0.66703981161117998,-0.67768549919127996,-0.68831408023833995,-0.69383984804152998,-0.69793200492858998,-0.70454788208008001,-0.71210950613021995,-0.72044658660889005,-0.72819709777831998,-0.73233073949813998,-0.73515081405640004,-0.73934847116470004,-0.74367475509643999,-0.74754542112349998,-0.75052076578140003,-0.75161272287368996,-0.75096774101257002,-0.74800932407378995,-0.74369424581527999,-0.73906069993973,-0.73462641239166004,-0.73268574476241999,-0.73058813810348999,-0.72409671545028997,-0.71600025892258001,-0.70892107486724998,-0.70263737440108998,-0.69887441396713001,-0.69526255130768,-0.68783378601073997,-0.67906165122985995,-0.67141091823578003,-0.66418880224228005,-0.65905421972275002,-0.65170067548751998,-0.63287520408630005,-0.61035925149918002,-0.59385448694229004,-0.58022898435592996,-0.56972295045853005,-0.55979812145232999,-0.54498952627181996,-0.52896744012832997,-0.51608437299728005,-0.50433039665222001,-0.49335551261902,-0.48059740662575001,-0.45909851789473999,-0.43534016609192,-0.41854679584503002,-0.40467852354049999,-0.39189383387566001,-0.37836781144142001,-0.35821813344955,-0.33648067712784002,-0.32032898068428001,-0.30629527568817,-0.29200422763824002,-0.27690038084983998,-0.25746855139732,-0.23746018111705999,-0.22322721779346,-0.21084466576576,-0.19632670283317999,-0.18010853230953,-0.15950341522694,-0.13852320611477001,-0.12454824894667001,-0.11336672306061001,-0.10074284672736999,-0.087518125772476002,-0.072453096508980006,-0.057423643767834001,-0.045936740934849001,-0.035988070070743998,-0.025477182120084998,-0.014918921515346,-0.0038037076592445001,0.0067670382559299001,0.014548756182194001,0.020855620503426001,0.027084536850452,0.032970510423182997,0.038718193769454998,0.044262073934078001,0.049710050225257998,0.054759267717600001,0.058722794055938998,0.062067773193120998,0.065347440540791002,0.068486593663692003,0.071823246777057995,0.074835576117039004,0.076470054686069003,0.077360913157463004,0.078213602304459007,0.078928545117377999,0.079923503100871998,0.080549344420433003,0.079430520534515006,0.077471673488616999,0.075738616287708005,0.074136763811111006,0.073419503867625996,0.072570018470287004,0.069642253220080996,0.065602377057076,0.06143968179822,0.056903779506683003,0.052289042621851002,0.046880804002284997,0.038983698934317003,0.029747677966952001,0.020609639585017998,0.011426284909248,0.0026247007772326001,-0.0058095920830964999,-0.013765851035714,-0.021056512370706,-0.027205308899283,-0.032342735677958,-0.036402639001607999,-0.039587531238794001,-0.041898511350155002,-0.044193342328071997,-0.048655435442924,-0.054115399718285002,-0.059395909309386999,-0.064375087618828,-0.067733697593212003,-0.070658385753631994,-0.075259022414684004,-0.080579504370689004,-0.085856147110461994,-0.090839490294455996,-0.094414085149765001,-0.097149148583412004,-0.099757999181747006,-0.10194583237171,-0.10342222452164,-0.10428950190543999,-0.10427167266607,-0.10416945815086,-0.10606449842453,-0.10860332846642,-0.10991812497377,-0.11031503975390999,-0.10932693630456999,-0.10733784735203,-0.10493360459805,-0.10203015059233,-0.098722055554389995,-0.095068253576755996,-0.091066919267177998,-0.087128236889839006,-0.084494091570377003,-0.082293346524239003,-0.079135842621326002,-0.075442187488079002,-0.071734167635441007,-0.067245028913021004,-0.059964299201964999,-0.051341243088245003,-0.043815448880195999,-0.036555223166942999,-0.029357247054576999,-0.021440107375382999,-0.010032483376563,0.002607399597764,0.012108705937862001,0.020514875650405998,0.030064925551414001,0.040697045624256002,0.054381515830754998,0.068919554352759996,0.079286716878414001,0.088242962956429,0.099511392414569994,0.11258871853352,0.12969806790352001,0.14762100577354001,0.15843133628368,0.16645956039429,0.17793783545493999,0.19138330221176,0.20771704614162001,0.22460915148258001,0.23554441332817,0.24447481334209001,0.25776565074920998,0.27361497282982,0.29233941435813998,0.31146043539047003,0.3233907520771,0.33281713724135997,0.34776821732521002,0.36548215150833002,0.38452535867691001,0.40323826670647001,0.41506573557853998,0.42439508438110002,0.43949881196022,0.45701801776885997,0.47396573424339,0.48918077349662997,0.49565622210503002,0.49937587976455999,0.51332122087479004,0.53184884786606001,0.54836261272429998,0.56304651498795,0.57105022668839001,0.57637721300125,0.58767729997634999,0.60125613212585005,0.61250841617583995,0.62213593721390004,0.62853056192398005,0.63361001014708995,0.64212644100188998,0.65194350481033003,0.66020256280899003,0.66733133792876997,0.67232996225357,0.67634749412536999,0.68238639831543002,0.68887490034103005,0.69317251443863004,0.69607138633728005,0.69777226448059004,0.69903403520583995,0.70248866081238004,0.70676726102829002,0.70961749553679998,0.71157777309418002,0.71276277303696001,0.71323412656784002,0.71311360597609996,0.71256464719771995,0.71216577291489003,0.71172362565993996,0.71111005544661998,0.71022766828536998,0.70858329534530995,0.70654773712158003,0.70506304502487005,0.70359110832214,0.70118045806884999,0.69797807931900002,0.69341182708740001,0.68839037418365001,0.68557268381118996,0.68371319770812999,0.68088752031326005,0.67734098434447998,0.67221361398696999,0.66645431518554998,0.66270834207535001,0.65969961881637995,0.65522891283035001,0.64983320236205999,0.64322251081466997,0.63647323846817005,0.63313972949982,0.63152313232421997,0.62872153520583995,0.62533217668533003,0.62089830636978005,0.61639982461928999,0.61508965492249001,0.61522930860518998,0.61335599422455001,0.61051100492476995,0.60741889476776001,0.60453158617019997,0.60404467582703003,0.60482633113860995,0.60468298196793002,0.60419869422912997,0.60383093357086004,0.60348194837570002,0.60310316085814997,0.60271352529526001,0.60234934091568004,0.60200041532516002,0.60166347026824996,0.60132843255997004,0.60098922252654996,0.60059732198714999,0.59992450475693004,0.59913873672484996,0.59870392084122004,0.59840244054794001,0.59772562980652,0.59695309400558005,0.59670925140381004,0.59680539369582997,0.59702181816100997,0.59740340709686002,0.59793311357498002,0.59866917133330999,0.60019820928573997,0.60168117284775002,0.60054868459702004,0.59758669137955001,0.59319657087326005,0.58826971054077004,0.58678036928177002,0.58663141727447998,0.58308959007262995,0.57754695415497004,0.57125920057296997,0.56470221281052002,0.56098490953445002,0.55823647975921997,0.55170202255249001,0.54301464557648005,0.53432983160018999,0.52588081359863004,0.52096021175384999,0.51698368787766003,0.50619679689407004,0.49176159501076,0.47919610142708002,0.46821036934853,0.46292385458946,0.45983847975731001,0.44837355613708002,0.43232399225235002,0.41795104742049999,0.40444263815879999,0.39401388168335,0.38438799977303001,0.36788088083267001,0.34779217839241,0.33091104030608998,0.31596097350121,0.30409291386603998,0.29283168911933999,0.27244743704795998,0.24742217361926999,0.22795177996159,0.2116219997406,0.19726979732513,0.18343606591225001,0.16279214620589999,0.13886745274067,0.12027936428784999,0.10467508435249,0.089511036872864005,0.074367567896842998,0.055149734020233002,0.034146308898926003,0.017649471759796,0.0037458129227161,-0.010249646380544,-0.024456130340695,-0.041853364557027997,-0.060595884919167002,-0.075189270079136006,-0.087419427931308996,-0.10025417804718,-0.11351688206196001,-0.12919531762600001,-0.14574274420738001,-0.15802301466464999,-0.16778361797333,-0.17837060987948999,-0.18920929729939001,-0.20068277418613001,-0.21202056109904999,-0.22014187276363001,-0.22614672780037001,-0.23236489295959001,-0.23828083276748999,-0.24335800111294001,-0.2477333843708,-0.25177946686745001,-0.25519520044326999,-0.25685662031174,-0.25719895958900002,-0.25725281238556003,-0.25679051876067999,-0.25560268759727001,-0.25368535518646002,-0.25081691145897,-0.24716000258922999,-0.24328662455082001,-0.23901078104973,-0.23406173288821999,-0.22831517457962,-0.22084860503674,-0.21216395497321999,-0.20357012748718001,-0.19508874416350999,-0.18799729645252,-0.18165072798729001,-0.17419074475765001,-0.16598430275917,-0.15725822746754001,-0.14806252717971999,-0.13878533244133001,-0.12928386032580999,-0.11910801380873,-0.10850211977959,-0.098171636462211997,-0.088078401982783994,-0.078491829335690003,-0.069457888603210005,-0.061619583517312997,-0.054521009325981001,-0.046569962054491001,-0.038073521107434997,-0.029103361070156,-0.019907340407372,-0.011663211509585001,-0.0041108252480626002,0.0030487205367535001,0.0098089212551713007,0.016456604003906,0.022753242403269001,0.027618438005446999,0.031525578349828998,0.035911574959754999,0.040501262992620003,0.045260403305291998,0.049863543361424997,0.052717834711075003,0.054197397083043997,0.054837033152579998,0.054639350622891998,0.054021373391150998,0.052839748561382002,0.050645902752875997,0.047634579241276002,0.044427238404750997,0.040915176272392002,0.036993108689784997,0.032718695700168998,0.028475312516093001,0.023962469771504,0.017793284729123001,0.010475410148501001,0.0035246857441961999,-0.0033525200560688998,-0.010305915959179001,-0.017617180943488998,-0.027057267725468001,-0.037927273660898,-0.047999497503041999,-0.057690054178237998,-0.067371279001236004,-0.077140845358371998,-0.087921343743801006,-0.099277324974537007,-0.10954250395298,-0.11917937546967999,-0.12897634506225999,-0.13932605087757,-0.15362103283404999,-0.17020876705647001,-0.18275628983973999,-0.19264809787272999,-0.20197260379790999,-0.21108479797839999,-0.22414883971214,-0.23931117355824,-0.24942201375961001,-0.25626149773598,-0.26371806859969998,-0.27165263891219998,-0.28290745615959001,-0.29591712355614003,-0.30396270751952997,-0.30873471498489002,-0.31421953439713002,-0.32008948922156999,-0.32812726497650002,-0.33708560466766002,-0.34089803695679,-0.34132778644562001,-0.34361714124679998,-0.34696438908576999,-0.35113933682442,-0.35562393069267001,-0.35702791810036,-0.35643109679222001,-0.35743951797485002,-0.35941448807715998,-0.36179104447365001,-0.36411663889884999,-0.36296254396438998,-0.35946708917617998,-0.35764175653458002,-0.35680475831031999,-0.35618335008620999,-0.35562518239021002,-0.35367622971535001,-0.35064545273781,-0.34712424874306003,-0.34314000606536998,-0.33924877643585,-0.33539983630179998,-0.33181548118590998,-0.32836836576461997,-0.32443076372147001,-0.32015427947044001,-0.31593114137650002,-0.31176674365996998,-0.30808034539223,-0.30469048023223999,-0.30072256922722002,-0.29641646146773998,-0.29253005981445002,-0.28903418779373002,-0.28644388914107999,-0.28453010320663003,-0.28218802809714999,-0.27967864274978999,-0.27786922454834001,-0.27656325697898998,-0.27520516514777998,-0.27380594611168002,-0.27180293202400002,-0.26954033970833002,-0.26882883906364002,-0.26938045024871998,-0.27093976736068998,-0.27329012751579002,-0.27467194199562001,-0.27554297447205001,-0.27761143445969,-0.28056064248085,-0.28361502289772,-0.28682792186736999,-0.28984305262566001,-0.29288622736931003,-0.29725122451781999,-0.30269020795821999,-0.30858460068702998,-0.31495195627213002,-0.32141545414924999,-0.3280762732029,-0.33530965447425998,-0.34307312965393,-0.35135975480080001,-0.36016833782196001,-0.3696928024292,-0.37968567013741,-0.38837578892708002,-0.39617177844048002,-0.40451869368553001,-0.41330313682556002,-0.42308533191681003,-0.43349117040634,-0.44213739037513999,-0.44949665665626998,-0.45710858702660001,-0.46480298042297002,-0.47263732552527998,-0.48043745756148998,-0.48679742217063998,-0.49211388826370001,-0.49825599789619002,-0.50497013330460006,-0.51201474666595004,-0.51919376850127996,-0.52480787038803001,-0.52913117408751997,-0.53284096717833995,-0.53589504957198997,-0.53860616683960005,-0.54077684879303001,-0.54089814424515004,-0.53939956426619995,-0.53853285312652999,-0.53795033693313998,-0.53685677051544001,-0.53515625,-0.53124713897705,-0.52557933330536,-0.52057558298110995,-0.51583504676819003,-0.51013696193695002,-0.50349777936935003,-0.49484428763389998,-0.48459300398826999,-0.47554656863213002,-0.46712249517441001,-0.45675882697105002,-0.44468879699706998,-0.43031683564186002,-0.41425922513008001,-0.40179857611656,-0.39176395535469,-0.37848994135857,-0.36252480745316001,-0.34319880604744002,-0.32148638367652999,-0.30613747239112998,-0.29528871178626998,-0.27958595752715998,-0.26013100147246998,-0.23858180642127999,-0.21544492244720001,-0.19705264270306,-0.18205520510674,-0.16330499947071,-0.14174464344977999,-0.11981309950352,-0.097716227173805001,-0.079934619367122997,-0.065275177359580994,-0.046014808118342999,-0.023296579718590001,-0.0012621162459254,0.020179858431219999,0.038088161498308001,0.053317673504353,0.071818955242634,0.092695727944374001,0.11232823133469,0.13088223338127,0.14662468433379999,0.16019985079765001,0.17670978605747001,0.1953991651535,0.21304047107696999,0.22985275089741,0.24529506266116999,0.25961533188820002,0.27506613731384,0.29117485880852001,0.30491337180138001,0.31657525897026001,0.32649233937263,0.33484131097794001,0.34386616945267001,0.35318306088447998,0.36061665415763999,0.36636337637901001,0.37063345313071999,0.37352770566940002,0.37621665000915999,0.37861824035644998,0.38085034489632003,0.38290020823478998,0.38487190008163003,0.38668426871299999,0.38741034269333002,0.38721340894699002,0.38724085688590998,0.38733470439911,0.38675805926322998,0.38545992970467002,0.38183647394179998,0.37634414434433,0.37318688631058,0.37185561656951999,0.36992275714874001,0.36752167344093001,0.36411023139954002,0.35991090536117998,0.35720065236092002,0.35570830106735002,0.35402846336365001,0.35227194428443998,0.35076093673705999,0.34943148493767001,0.34769082069397,0.34557932615280001,0.34305974841117998,0.34016945958138001,0.33731067180634,0.33447235822678001,0.33191320300102001,0.32957831025124001,0.32695868611335999,0.32410559058188998,0.32095843553543002,0.31774815917014998,0.31781899929046997,0.32077765464782998,0.32415252923964999,0.32808351516723999,0.33256199955940002,0.33755621314049,0.34230881929397999,0.34698331356049,0.35345470905303999,0.36147886514664002,0.36924630403518999,0.37677070498465998,0.38232216238976002,0.38627290725708002,0.39297288656235002,0.40193024277687001,0.40958282351494002,0.41602063179016002,0.41931608319282998,0.41980218887329002,0.42055469751357999,0.42157340049744002,0.42550048232079002,0.43220514059067,0.44208037853241,0.45512908697128002,0.47270795702933999,0.49426439404487998,0.51162695884705001,0.52529549598694003,0.53633785247803001,0.54477924108505005,0.55164825916289995,0.55685323476791004,0.55964970588684004,0.56012737751007002,0.55903023481368996,0.55646723508835005,0.55487042665482,0.55423939228057995,0.55704432725905995,0.56305956840515003,0.57048916816711004,0.57937806844711004,0.58985906839371005,0.60151684284210005,0.60570365190506004,0.60306078195571999,0.59843641519546997,0.59163188934326005,0.58220279216766002,0.57034367322921997,0.56005907058715998,0.55113077163696,0.54267770051955999,0.53471118211746005,0.52636432647705,0.51793295145035001,0.51574611663818004,0.51925665140152,0.52194344997405995,0.52405720949172996,0.52610230445862005,0.52786523103714,0.52395564317703003,0.51476907730103005,0.50489240884780995,0.49411869049071999,0.48201051354407998,0.46827834844589,0.44429528713226002,0.41085523366928001,0.38018679618835,0.35194256901741,0.32688155770302002,0.30539974570273998,0.30153578519821,0.31412222981452997,0.32419812679290999,0.33230054378509999,0.33717259764670998,0.33866974711418002,0.32910996675491,0.30910885334014998,0.28995260596275002,0.27124032378196999,0.25098782777786,0.22918267548084001,0.20332136750221,0.17378963530064001,0.15078349411488001,0.13403622806071999,0.12402093410492,0.12076215445995001,0.12743769586086001,0.14359755814075001,0.15635102987289001,0.16593985259533001,0.16901773214339999,0.16569972038269001,0.15535360574722001,0.13826692104339999,0.12507726252078999,0.11554662883282001,0.11026602983475001,0.10917358100414,0.11114154011011,0.116135828197,0.12150173634291001,0.1273186057806,0.13467162847518999,0.14352911710739,0.15323205292225001,0.16378806531428999,0.17497162520885001,0.18679313361645,0.19984963536263001,0.21406771242618999,0.22625318169594,0.23638151586056,0.23992045223712999,0.23692351579665999,0.22479803860188,0.20379064977169001,0.18676871061325001,0.17365489900111999,0.17167308926582001,0.18074768781662001,0.20517331361770999,0.24464815855026001,0.28003343939781,0.31150811910629,0.33500498533249001,0.35061460733414002,0.36080712080001998,0.36560565233231002,0.36957743763924,0.37267720699309997,0.37477567791938998,0.37587013840674999,0.37580898404120999,0.37459814548491999,0.37294647097588002,0.37084978818893,0.36844363808632002,0.36572369933128002,0.36155512928963002,0.35597297549248003,0.35575437545776001,0.36086490750312999,0.36937454342842002,0.38129383325576999,0.40039914846419999,0.42664471268653997,0.43931767344474998,0.43845793604851002,0.4310427904129,0.41706812381744002,0.39454513788223,0.36346015334129,0.34210357069969,0.33050519227982,0.32107949256897,0.31381559371947998,0.30876040458678999,0.30591940879821999,0.30330497026442998,0.30091086030005998,0.29853725433349998,0.29618465900420998,0.2945568561554,0.29374238848686002,0.27843552827835,0.24845917522906999,0.21605414152145,0.18129523098469,0.14310678839683999,0.10133130848407999,0.075535416603088004,0.066029712557792997,0.057961873710155001,0.051207572221756002,0.045926686376333001,0.042185351252556,0.032631993293761999,0.017110140994191,0.0016232966445386,-0.01376744825393,-0.028938669711350999,-0.043933816254139002,-0.054761547595262999,-0.061321042478085001,-0.066208280622958998,-0.069363445043563995,-0.076320245862007002,-0.087039023637771995,-0.11061213165522001,-0.14742437005042999,-0.18480920791625999,-0.22270421683788,-0.25328534841536998,-0.27649536728858998,-0.28593811392784002,-0.28129354119300998,-0.27116498351097001,-0.25551283359527999,-0.24416245520115001,-0.23729838430882,-0.23713700473308999,-0.24387098848819999,-0.25176084041594998,-0.26065143942833002,-0.27189362049103,-0.28552782535553001,-0.30103632807732,-0.31851303577423001,-0.33416903018951,-0.34808316826820002,-0.35297811031342002,-0.34855589270592002,-0.33779823780059998,-0.32051205635071001,-0.30570784211159002,-0.29344132542610002,-0.29161024093628002,-0.30065879225731001,-0.31436619162559998,-0.33273428678513001,-0.3508343398571,-0.36881491541861999,-0.37552267313004001,-0.37029600143433,-0.36212727427482999,-0.35112929344177002,-0.34151199460030002,-0.33321860432625,-0.33369469642638999,-0.34350374341010997,-0.35407972335815002,-0.36518034338951,-0.37628263235092002,-0.38764059543610002,-0.38995066285133001,-0.38245284557343001,-0.37647348642348999,-0.37241363525391002,-0.36906883120536998,-0.36574551463126997,-0.38248482346535001,-0.42112043499946999,-0.45474451780318997,-0.48225602507590998,-0.50605523586273005,-0.52654558420180997,-0.53251743316650002,-0.52275526523589999,-0.51522767543793002,-0.51067113876342995,-0.50857603549956998,-0.50853425264358998,-0.52257645130157004,-0.55208295583724998,-0.57768160104751998,-0.59832799434661998,-0.61808329820633001,-0.63687640428543002,-0.65953767299652,-0.68681806325911998,-0.70727586746215998,-0.72011369466782005,-0.73073095083237005,-0.73930615186690996,-0.74662780761719005,-0.75267755985259999,-0.75882256031035999,-0.76490998268126997,-0.77550995349884,-0.79075288772582997,-0.81421220302581998,-0.84698867797851995,-0.87091720104217996,-0.88449943065643,-0.89777630567551003,-0.91119337081909002,-0.92551529407500999,-0.94109952449798995,-0.95253109931946001,-0.95921677350998003,-0.96657246351241999,-0.97493106126785001,-0.98404145240784002,-0.99438428878784002,-0.99705219268798995,-0.99111974239348999,-0.98336625099181996,-0.97409039735794001,-0.96401011943817005,-0.95276790857314997,-0.94821649789810003,-0.95105731487274003,-0.95834320783615001,-0.97025460004806996,-0.98195827007294001,-0.99369913339615001,-0.99540019035339,-0.98593646287918002,-0.97190576791762995,-0.95338040590286,-0.93510234355927002,-0.91722875833510997,-0.90313035249710005,-0.89311760663985995,-0.88697576522827004,-0.88513004779815996,-0.88122898340224998,-0.87495106458663996,-0.86406320333481001,-0.84816402196884,-0.82994914054871005,-0.80931591987609997,-0.79053330421447998,-0.77396970987320002,-0.75915497541428001,-0.74608856439589999,-0.73488020896911999,-0.72566390037536999,-0.71659111976624001,-0.70750695466994995,-0.69863849878311002,-0.69004505872725996,-0.68091720342635997,-0.67118567228317005,-0.66089916229248002,-0.65002423524857,-0.63902086019516002,-0.62796133756637995,-0.61616718769072998,-0.60334241390228005,-0.59292221069336004,-0.58530730009079002,-0.57892775535582996,-0.57374310493469005,-0.56921166181563998,-0.56566745042801003,-0.55767959356307995,-0.54446685314178001,-0.53001397848128995,-0.51458245515822998,-0.49795502424240001,-0.47919371724129001,-0.47120109200478,-0.47602802515030002,-0.48232197761536,-0.48925921320915,-0.49597036838531,-0.50248539447784002,-0.50609934329987005,-0.50638544559479004,-0.50531417131423995,-0.50307577848434004,-0.49904516339302002,-0.49288901686668002,-0.48831123113632002,-0.48589953780174,-0.48275581002235002,-0.47859907150268999,-0.47368231415749001,-0.46767368912696999,-0.46473529934883001,-0.46566689014434998,-0.46586304903030001,-0.46485221385955999,-0.46333476901053999,-0.46138763427733998,-0.45831912755965998,-0.45391446352004999,-0.44983705878258001,-0.44621637463570002,-0.44334489107132002,-0.44111070036888,-0.44149664044379999,-0.44501170516013999,-0.44837972521781999,-0.4513133764267,-0.45347571372986001,-0.45490252971648998,-0.45429870486259,-0.45133295655250999,-0.44808223843575001,-0.44490560889244002,-0.44019660353661,-0.43381065130233998,-0.42543059587478999,-0.41459584236144997,-0.40582799911499001,-0.39996749162674,-0.39340382814406999,-0.38571181893348999,-0.37746566534041998,-0.36832553148269997,-0.36234182119370001,-0.36047497391701,-0.35761287808418002,-0.35309153795241999,-0.34805050492286999,-0.34234195947647,-0.33842006325722002,-0.33703726530075001,-0.33354106545447998,-0.32723444700241,-0.31975299119949002,-0.31100749969482,-0.3034433722496,-0.29778745770454002,-0.28982627391815002,-0.27876985073089999,-0.26749646663665999,-0.25600466132164001,-0.24752597510815,-0.24312867224216,-0.23657339811325001,-0.22673089802265001,-0.21733739972114999,-0.20872297883033999,-0.20170024037361001,-0.19697606563567999,-0.18905863165855,-0.17672456800938,-0.16490767896174999,-0.15409564971924,-0.14509917795658001,-0.13836418092250999,-0.13131701946259,-0.12350149452686,-0.11618369072676001,-0.10954952985048,-0.10319759696722,-0.097325056791306,-0.089661315083504001,-0.079576157033443007,-0.069935217499732999,-0.061128664761781998,-0.052982255816460003,-0.045850295573472998,-0.036557115614414,-0.024187164381146001,-0.013003640808165001,-0.0037129828706384,0.0050553292967378998,0.013318574987352,0.022132514044642001,0.031906500458716999,0.040495023131371002,0.047511346638203,0.053789373487233998,0.059375945478677999,0.064467735588550998,0.068758681416511994,0.075259633362292994,0.084602586925030004,0.095255538821219995,0.10710479319096,0.11996106058359,0.13457161188125999,0.14408551156520999,0.14695951342583,0.14739640057087,0.14592552185058999,0.14185275137424,0.13371387124062001,0.13355188071728,0.14422541856766,0.15750500559807001,0.17236320674419001,0.18914312124252,0.20910513401031,0.22104063630104001,0.2220361828804,0.22122564911841999,0.21982792019844,0.21766640245914001,0.21426743268967,0.21457062661647999,0.21986255049705999,0.22642196714877999,0.23383155465125999,0.2415452003479,0.24969208240509,0.25598484277724998,0.25978431105614003,0.26296278834343001,0.26573228836059998,0.26845380663871998,0.27122598886490001,0.27399688959121998,0.27672174572945002,0.27973869442940003,0.28300884366035001,0.28723663091660001,0.29245603084563998,0.29948213696480003,0.30882611870766002,0.31784784793853998,0.32620182633400002,0.33321985602379001,0.33873710036277999,0.34261304140090998,0.34455144405365001,0.34626176953316001,0.34759399294853,0.35185152292251998,0.35975202918053001,0.37078094482422003,0.38549026846885998,0.39985364675522,0.41334620118141002,0.42446553707123003,0.43265968561172002,0.43917751312255998,0.44395199418067999,0.44844475388527,0.45187824964522999,0.46211895346642001,0.48147672414780002,0.50431096553802002,0.53042811155319003,0.55540132522582997,0.57897037267685003,0.59610575437545998,0.60490018129348999,0.61112409830092995,0.61550348997116,0.61921638250350997,0.62125688791275002,0.63146817684173995,0.65334218740463001,0.67619717121124001,0.69845187664032005,0.71859121322632002,0.73589026927947998,0.75159424543381004,0.76587426662445002,0.77873688936233998,0.79031628370285001,0.79966080188750999,0.80573081970214999,0.81450504064560003,0.82802146673203003,0.84037554264069003,0.85036045312881003,0.85897922515868996,0.86527037620544001,0.87639290094375999,0.89536821842194003,0.91177278757095004,0.92330378293991,0.93242394924163996,0.93915945291518999,0.94492018222809004,0.95024049282073997,0.95369642972946,0.95480304956436002,0.95505154132842995,0.95454156398773005,0.95448464155196999,0.95547348260880005,0.95554393529892001,0.95413494110107,0.95244586467742998,0.95066517591475996,0.94890713691711004,0.94735634326935003,0.94511508941650002,0.94170141220092995,0.93897026777267001,0.93718510866164995,0.93724536895751998,0.94031953811645996,0.94059222936630005,0.93660038709641003,0.92973548173903997,0.92009836435318004,0.90766185522079001,0.891546189785,0.87738776206970004,0.86692535877228005,0.85720610618590998,0.84776324033737005,0.83848434686661,0.82904452085494995,0.82091492414473999,0.81476122140884,0.80846214294434005,0.80152928829193004,0.79426836967467995,0.78666347265243997,0.77888566255569003,0.77119863033295,0.76220023632050005,0.75127148628234997,0.74018412828445002,0.72917175292969005,0.71908324956893999,0.71047329902649003,0.70150679349899003,0.69152569770812999,0.68206542730330999,0.67330235242844005,0.66607904434204002,0.66108930110930997,0.65565454959868996,0.64888203144072998,0.64242547750473,0.63645148277283004,0.63190346956252996,0.62975138425827004,0.62584662437438998,0.61858016252518,0.61165964603423995,0.60593563318252996,0.60100412368774003,0.59750646352768,0.59168618917464999,0.58161860704421997,0.57302355766295998,0.56732892990112005,0.56372845172882002,0.56225407123565996,0.56282073259354004,0.56609773635864002,0.56812655925750999,0.56766051054000999,0.56603175401688,0.56337130069732999,0.55995857715607,0.55583840608597002,0.551324903965,0.54652714729309004,0.54139286279678001,0.53602212667464999,0.52976590394973999,0.52179747819901001,0.51583582162857,0.51330173015594005,0.51161158084868996,0.51038885116577004,0.50879341363907005,0.50657880306243996,0.50339370965957997,0.49898147583008001,0.49397569894790999,0.48860761523246998,0.48235592246056003,0.47467610239982999,0.46793910861014998,0.46311098337173001,0.45833328366280002,0.45316088199615001,0.44785684347152999,0.44277450442313998,0.43595895171165,0.42622125148772999,0.41707479953766002,0.40956896543503002,0.40289998054504,0.39754399657249001,0.3904502093792,0.38002583384513999,0.37016639113425998,0.36213877797126998,0.35434842109679998,0.34700030088424999,0.33733198046683999,0.32345855236053001,0.31096616387366999,0.30183041095733998,0.29336011409759999,0.28521418571472001,0.27632871270179998,0.26569736003875999,0.25657021999358998,0.25041502714156999,0.24418523907660999,0.23727634549141,0.22889225184917,0.21792146563529999,0.20834481716156,0.20210994780064001,0.19495652616024001,0.18602809309959001,0.17403426766395999,0.15684741735457999,0.14257787168026001,0.13483923673629999,0.12708321213721999,0.11760295182467,0.10697949677706001,0.094188347458839,0.084076941013336001,0.079364523291587996,0.073649041354655997,0.064857870340346999,0.054764509201049999,0.042868491262197002,0.033029958605765998,0.027436327189207001,0.021279724314809002,0.012868848629295999,0.0042347721755504998,-0.0045530619099735997,-0.011709925718606001,-0.015724197030067,-0.021006243303418,-0.029351115226746001,-0.038218345493078003,-0.047190640121697998,-0.055402673780918003,-0.061790991574526,-0.069791994988917999,-0.081152454018593001,-0.092388421297073003,-0.10269748419523,-0.11144648492336,-0.11833013594151,-0.12299356609583,-0.1247434169054,-0.12604932487011,-0.12758882343769001,-0.12978167831897999,-0.13265292346478,-0.13745972514152999,-0.1453358232975,-0.15305919945240001,-0.1596082597971,-0.16519957780837999,-0.16987457871437001,-0.17290598154067999,-0.17361491918564001,-0.17398846149444999,-0.17468559741973999,-0.17554861307144001,-0.17706297338009,-0.17714069783688,-0.17427231371403001,-0.17231476306915,-0.17273682355881001,-0.17420288920402999,-0.17656779289246,-0.17940530180931,-0.18273584544659,-0.18558432161808,-0.18761198222636999,-0.18870802223682001,-0.18914626538754001,-0.18705126643181,-0.18039098381995999,-0.17551094293594,-0.17520995438098999,-0.17622223496437001,-0.17777201533317999,-0.17995175719261,-0.18284511566162001,-0.18556989729404,-0.1877163797617,-0.18964563310145999,-0.19150073826312999,-0.19290536642075001,-0.19338457286357999,-0.1945406794548,-0.19693261384964,-0.20053702592850001,-0.20555613934993999,-0.21155001223087,-0.21894247829913999,-0.22514468431473,-0.22860409319401001,-0.23194709420203999,-0.23600542545319,-0.2405339628458,-0.24558529257774001,-0.25115659832954002,-0.25695773959160001,-0.26435029506683,-0.27419880032539001,-0.28494536876678001,-0.29654091596602999,-0.30700376629829002,-0.31468078494071999,-0.32323002815246998,-0.33441686630249001,-0.34582656621933,-0.35692492127419001,-0.36703366041183,-0.37509500980376997,-0.38406437635422003,-0.39530372619629001,-0.40745636820793002,-0.42024448513985002,-0.43345871567726002,-0.44630154967308,-0.46171188354491999,-0.48213914036750999,-0.50177186727524004,-0.51862710714339999,-0.53243428468704002,-0.54218494892119995,-0.55000185966491999,-0.55582994222641002,-0.56307303905487005,-0.57352501153946001,-0.58588403463364003,-0.60046887397766002,-0.61496585607528997,-0.62838393449783003,-0.64084923267365002,-0.65224868059158003,-0.66246896982193004,-0.67146813869475996,-0.67909300327301003,-0.68492156267166004,-0.69042301177979004,-0.69626033306122004,-0.70208448171616,-0.70801496505737005,-0.71342051029205,-0.71769219636917003,-0.72230714559554998,-0.72820007801055997,-0.73377382755279996,-0.73859661817551003,-0.74218237400054998,-0.74400961399078003,-0.74495506286621005,-0.74531835317612005,-0.74510830640793002,-0.74447214603423995,-0.74304103851318004,-0.74016821384429998,-0.73797106742858998,-0.73778361082077004,-0.73766022920608998,-0.73700660467148005,-0.73563760519027999,-0.73381984233856001,-0.72953784465789995,-0.72085493803024003,-0.71201509237288996,-0.70480448007583996,-0.69857019186019997,-0.69302821159363004,-0.68961358070374001,-0.68984216451644997,-0.69011551141739003,-0.68892782926559004,-0.68661266565322998,-0.68354970216750999,-0.67751610279082997,-0.66614019870758001,-0.65496075153350997,-0.64665055274963001,-0.63939815759659002,-0.63273525238036998,-0.62722992897034002,-0.62347584962845004,-0.61981523036956998,-0.61538267135619995,-0.61084270477295,-0.60644185543060003,-0.60177963972091997,-0.59647476673125999,-0.59146046638489003,-0.58726704120635997,-0.58333379030228005,-0.57941669225693004,-0.57580643892287997,-0.57261037826537997,-0.56978744268417003,-0.56743597984313998,-0.56517589092255005,-0.56284940242767001,-0.56038898229598999,-0.55767208337784002,-0.55492347478866999,-0.55259817838669001,-0.54925870895385998,-0.54413032531738004,-0.53766053915024004,-0.52887535095214999,-0.52186203002929998,-0.51921921968460005,-0.51836562156677002,-0.51859080791473,-0.51958090066910001,-0.52128350734711004,-0.52266383171081998,-0.52353382110596003,-0.52242374420166005,-0.51797086000443004,-0.51221650838851995,-0.50524324178696001,-0.49982991814612998,-0.49839356541634,-0.49746933579445002,-0.49546289443969999,-0.49334588646888999,-0.49122455716133001,-0.48937663435936002,-0.48862460255623003,-0.48647418618201999,-0.48101717233657998,-0.47500586509705001,-0.46949040889740001,-0.46463876962661999,-0.46137788891791998,-0.45742619037628002,-0.45121601223946001,-0.44466882944107,-0.43853160738945002,-0.43272018432616999,-0.42809322476387002,-0.42184281349182001,-0.41147783398628002,-0.40116003155708002,-0.39306682348250999,-0.38574248552321999,-0.37909042835236001,-0.37223353981972002,-0.36436158418655001,-0.35655373334884999,-0.34933516383170998,-0.34236523509026001,-0.33570483326911998,-0.32885566353798001,-0.32181650400161999,-0.31356760859489002,-0.30331677198410001,-0.29180905222893,-0.27963638305664001,-0.26549917459487998,-0.24729360640049,-0.2304992377758,-0.21873405575752,-0.20875613391399001,-0.19949851930140999,-0.19096930325031,-0.18357220292091,-0.17490835487843001,-0.16303077340125999,-0.15017057955265001,-0.13725225627422,-0.12409900128841,-0.11066925525665,-0.097527191042900002,-0.085036389529705006,-0.073081485927105005,-0.061734087765217001,-0.050803881138562997,-0.040580302476882997,-0.029646750539541002,-0.016730964183806998,-0.0035437913611531002,0.0091299954801798006,0.021425167098641,0.033157411962747997,0.044612661004066002,0.056164201349019997,0.066945210099219998,0.076316289603709994,0.084948226809501995,0.092719539999962006,0.10102361440659,0.11136396229267,0.12138662487268,0.12938646972178999,0.13744106888770999,0.14598172903060999,0.15670475363731001,0.17244741320609999,0.18734483420848999,0.19767341017723,0.20580473542212999,0.21243169903754999,0.21723282337189001,0.21997162699698999,0.22134335339069,0.22095832228661,0.22156921029091001,0.22492755949497001,0.23085781931877,0.24090433120728,0.25078153610228998,0.25770452618598999,0.26292088627815002,0.26652458310126997,0.26860839128494002,0.26890051364898998,0.26864767074585,0.26874521374701998,0.26872354745865001,0.26834577322005998,0.26813513040543002,0.26846763491630998,0.26905241608620001,0.27005663514137002,0.27055186033249001,0.26968884468079002,0.26837405562401001,0.26683065295219,0.26566597819327997,0.26558321714401001,0.26578775048255998,0.26588562130928001,0.26597890257835,0.26588797569275002,0.26612272858620001,0.26720434427260997,0.26839706301688998,0.26924589276313998,0.27002069354057001,0.27074190974236001,0.27157938480376997,0.2728688120842,0.27388751506804998,0.27382686734200001,0.27400350570679,0.27509006857871998,0.27723973989487,0.28062576055527,0.28563782572745999,0.29325038194656,0.30126637220383001,0.30835652351379,0.31456542015076,0.31939083337784002,0.32343724370003002,0.32685065269469998,0.33015683293343001,0.33373352885245999,0.33771955966949002,0.34173575043678001,0.34773963689803999,0.35820782184601002,0.36930996179580999,0.37840160727500999,0.38713666796683999,0.39566510915755998,0.40517610311508001,0.41763424873352001,0.42957419157027998,0.43838450312614002,0.44593611359596003,0.45242583751678001,0.45948138833045998,0.46942871809005998,0.47879299521446,0.48432061076164001,0.49020001292228998,0.49825611710548001,0.51000070571899003,0.53002393245696999,0.54866415262222001,0.55765527486801003,0.56405740976333996,0.57105898857116999,0.57844960689545,0.58755934238434004,0.59641087055205999,0.60275858640670998,0.61015015840529996,0.62106537818909002,0.63437700271606001,0.65198135375976995,0.66709887981414995,0.67263633012771995,0.67609095573425004,0.68199080228805997,0.68830877542496005,0.69511342048644997,0.70114648342133001,0.70478045940399003,0.70810562372207997,0.71252614259720004,0.71739965677260997,0.72293359041214,0.72809374332428001,0.73153156042098999,0.73509812355042004,0.74032545089722002,0.74585694074631004,0.75129282474518,0.75579577684402,0.75769186019896995,0.75978398323059004,0.76473397016525002,0.76982468366623003,0.77356046438216997,0.77604794502258001,0.77650696039199996,0.77631002664565996,0.7763894200325,0.77667856216430997,0.77742546796798995,0.77853751182555997,0.78019076585769997,0.78181278705597002,0.78293031454086004,0.78368055820464999,0.78403806686401001,0.78400599956511996,0.78357052803039995,0.78275889158249001,0.78125745058060003,0.78011453151703003,0.78033322095871005,0.78128796815872004,0.78296071290970004,0.78466349840163996,0.78546863794327004,0.78640335798264005,0.78829491138457997,0.79046791791916005,0.79293978214264005,0.79459726810455,0.79338395595551003,0.79269301891327004,0.79580193758010997,0.79984474182128995,0.80343401432036998,0.80612635612488004,0.80690115690231001,0.80638223886490001,0.80480104684830001,0.80219042301178001,0.79865598678589,0.79418277740479004,0.78769952058792003,0.78258126974106001,0.78283828496932995,0.78447467088698997,0.78491038084029996,0.78477370738982999,0.78433138132095004,0.78204017877579002,0.77582913637161,0.76797807216643998,0.76010900735855003,0.75167846679688,0.74237024784088002,0.73318529129027998,0.72486311197280995,0.71767753362655995,0.71250778436661,0.70816570520401001,0.70496761798858998,0.69940489530562999,0.68629366159438998,0.67168402671813998,0.66052722930908003,0.65009099245071,0.63995909690857,0.62835562229155995,0.61188536882401001,0.59530830383301003,0.58328843116759999,0.57217341661453003,0.56028628349303999,0.5466530919075,0.52807003259659002,0.50972539186478005,0.49734574556351002,0.48568484187125999,0.47157859802245999,0.45480388402938998,0.43198850750923001,0.40949383378028997,0.39469051361084001,0.38089120388031,0.36358225345612,0.34379643201827997,0.34552612900733998,0.29537057876586997,0.26587849855423001,0.24852915108203999,0.22500360012053999,0.19908300042152,0.17560553550720001,0.16372871398926001,0.15443640947341999,0.14058588445187001,0.12548042833805001,0.10900446772575,0.094314798712730005,0.086884409189223993,0.079896375536919001,0.066880546510220004,0.051823943853377998,0.035810247063637002,0.021262532100081,0.012544207274913999,0.0052503943443298002,-0.0044395946897565998,-0.014334117993712,-0.023672364652157,-0.031827658414840997,-0.036825843155384001,-0.041780266910791002,-0.050373643636702999,-0.059400625526904997,-0.066619031131268006,-0.072411678731440998,-0.075935527682303994,-0.078568629920482996,-0.081724002957344,-0.084707170724868996,-0.087342329323292001,-0.089413978159428004,-0.090492665767669997,-0.090975321829319,-0.091032885015011,-0.090978652238846006,-0.091258026659488997,-0.091741420328616999,-0.092880293726920998,-0.093405909836292003,-0.091693520545959001,-0.088891007006168005,-0.085819393396377994,-0.082080833613873,-0.077836245298385995,-0.072192855179309998,-0.062884740531444994,-0.053776144981384,-0.049262892454862997,-0.04674270004034,-0.045053519308566999,-0.043709445744753002,-0.041476663202047001,-0.039123412221669998,-0.037456300109625001,-0.035360760986804997,-0.032018877565860998,-0.026984091848135001,-0.01798777654767,-0.0092325340956449994,-0.0059136170893907998,-0.0045564845204353003,-0.0029677762649953001,-0.0014407641720027,0.0013320802245289001,0.0029460173100233,0.00020516826771199999,-0.0043540112674236003,-0.0088451821357012003,-0.013587130233645,-0.017648611217737,-0.022753851488233001,-0.031316943466663,-0.041250862181187002,-0.050829697400330998,-0.060511402785777997,-0.070185713469981995,-0.079873263835906996,-0.089506544172764005,-0.099228344857692996,-0.10921215265989,-0.11937904357909999,-0.12949433922768,-0.14013957977295,-0.15219357609749001,-0.16490754485129999,-0.17741437256336001,-0.19053916633129001,-0.2045710682869,-0.22060047090054,-0.24081063270569,-0.26312524080276001,-0.28588467836379999,-0.30892843008040999,-0.33169946074486001,-0.35341462492942999,-0.37243846058845997,-0.39002665877342002,-0.40660095214844,-0.42359042167664002,-0.44295486807822998,-0.46467188000678999,-0.49067544937134,-0.51761573553085005,-0.54120790958404996,-0.56370878219604004,-0.58650135993957997,-0.60904312133788996,-0.63158005475998003,-0.65300589799881004,-0.67124450206757003,-0.68840122222900002,-0.70668935775757002,-0.72520577907562001,-0.74429929256438998,-0.76219409704207997,-0.77541977167130005,-0.78759270906447998,-0.80272746086121005,-0.81893610954285001,-0.83597034215927002,-0.85211074352264005,-0.86405932903289995,-0.87441337108612005,-0.88574415445328003,-0.89677065610885998,-0.90695220232009999,-0.91593950986862005,-0.92256474494934004,-0.92816364765167003,-0.9344841837883,-0.94033735990524003,-0.94486123323440996,-0.94797980785369995,-0.94973635673523005,-0.94878309965134,-0.94208270311356002,-0.93298494815826005,-0.92490053176880005,-0.91757398843765003,-0.91226828098296997,-0.90838533639908003,-0.90587288141250999,-0.90406060218811002,-0.90191859006882003,-0.89967942237854004,-0.89782631397247004,-0.89477640390395996,-0.88763582706451005,-0.87881535291671997,-0.87089449167251998,-0.86276060342788996,-0.85417455434798994,-0.84445410966873002,-0.83155113458633001,-0.81812936067580999,-0.80764698982239003,-0.79863536357880005,-0.79036480188369995,-0.78307008743286,-0.77733612060546997,-0.77168750762938998,-0.76379996538161998,-0.75489127635955999,-0.74573659896850997,-0.73633176088332997,-0.72663015127181996,-0.71760302782059004,-0.71090763807296997,-0.70583653450011996,-0.70197474956511996,-0.69955420494080001,-0.69911837577820002,-0.69966524839401001,-0.69957357645035001,-0.69984859228134,-0.70137971639633001,-0.70390951633453003,-0.70784091949463002,-0.71209985017776001,-0.71458542346954002,-0.71707832813262995,-0.72161304950714,-0.72746580839157005,-0.73527598381042003,-0.74280327558517001,-0.74603432416916005,-0.74736589193344005,-0.74874526262283003,-0.75002789497375,-0.75145953893660999,-0.75401622056961004,-0.75986832380295,-0.76753300428391003,-0.77559685707091996,-0.78428333997725996,-0.79346615076064997,-0.80277132987975997,-0.81134808063507002,-0.81975138187408003,-0.82867103815079002,-0.83758425712585005,-0.84586340188980003,-0.85380214452743997,-0.86164480447768999,-0.86923646926880005,-0.87652617692946999,-0.88329005241393999,-0.88914263248444003,-0.89410716295241999,-0.89798283576964999,-0.90094107389449996,-0.90301930904387995,-0.90459388494491999,-0.90635722875595004,-0.90812224149704002,-0.91025209426880005,-0.91183841228484996,-0.91097736358643,-0.90920370817184004,-0.90835940837859996,-0.90791928768158003,-0.90810596942902,-0.90827250480652,-0.90738892555237005,-0.90564703941345004,-0.90284204483032005,-0.89910870790482,-0.89453804492949995,-0.88922041654587003,-0.88345420360564997,-0.87696641683578003,-0.86940723657607999,-0.86085343360901001,-0.85122096538544001,-0.84064412117003995,-0.82959604263305997,-0.81735271215438998,-0.80239230394363004,-0.78601503372192005,-0.76986771821975997,-0.75359773635864002,-0.73755818605422996,-0.72125148773193004,-0.70368707180023005,-0.68563675880431996,-0.66791498661041004,-0.65065711736678999,-0.63470411300659002,-0.61947703361510997,-0.60422211885452004,-0.58930093050002996,-0.57488751411437999,-0.56124705076217996,-0.55020004510880005,-0.53856956958770996,-0.51992881298064997,-0.49849498271942,-0.47923657298088002,-0.46081238985062001,-0.44423067569732999,-0.42684993147849998,-0.40248578786849998,-0.37601891160010997,-0.35426306724548001,-0.3347293138504,-0.31721204519272,-0.29911327362061002,-0.27320244908333002,-0.24555546045303001,-0.22524817287922,-0.20856876671314001,-0.19355866312980999,-0.17901381850243001,-0.16019852459431,-0.14110937714576999,-0.12824428081511999,-0.11809040606022,-0.10744774341582999,-0.095890872180461995,-0.079486526548861999,-0.062202736735344002,-0.051093339920044001,-0.042311791330575999,-0.031819183379412003,-0.020212378352879999,-0.0055481316521764001,0.0094229560345411006,0.019056355580688002,0.026785369962453998,0.036678269505501002,0.047995969653130001,0.062522828578949002,0.07729547470808,0.085936561226844996,0.092309229075908994,0.10129007697105,0.11148755997419001,0.12345343083143,0.13510452210903001,0.14147228002548001,0.14549919962883001,0.15091481804848,0.15663366019725999,0.16249808669089999,0.16816335916519001,0.17243328690529,0.17640325427055001,0.18189899623394001,0.18830020725727001,0.19558897614479001,0.20303523540497001,0.20850159227848,0.21361134946346,0.22113919258118001,0.22966898977757,0.23776789009571,0.24536180496216001,0.25107952952384999,0.25614225864410001,0.26287284493446,0.26998621225357,0.27598205208777998,0.28097498416901001,0.28422230482101002,0.2862688601017,0.28773236274719,0.28888323903084001,0.29072746634482999,0.29293900728226002,0.29526925086974998,0.29792338609695002,0.30127719044684997,0.30516976118088002,0.30940544605254999,0.31409928202629001,0.31952479481696999,0.32538256049156,0.33099445700645003,0.33678930997848999,0.34349152445793002,0.35072678327559997,0.35793209075928001,0.36541727185249001,0.37379986047745001,0.38252806663513,0.39055436849594,0.39828673005103998,0.40606093406677002,0.41389018297195002,0.42236632108687999,0.43058511614799,0.43640190362929998,0.44092437624931002,0.44557380676269998,0.45009571313857999,0.45447534322739003,0.45912432670593001,0.46518716216087003,0.47213345766067999,0.47932031750678999,0.48689943552017001,0.49479186534882003,0.50319570302963001,0.51268756389617998,0.52286285161972001,0.53298991918563998,0.54335117340088002,0.55419975519179998,0.56554114818572998,0.57753032445908004,0.59013563394546997,0.60345649719238004,0.61729794740677002,0.63170236349106001,0.64570200443268,0.65627133846283003,0.66524243354796997,0.67557042837143,0.68651002645492998,0.69809561967849998,0.70986270904541005,0.72043663263321001,0.73055720329285001,0.74141037464142001,0.75257712602615001,0.76385813951491999,0.77489817142487005,0.78432416915893999,0.7930936217308,0.80300796031952004,0.81347757577895996,0.82400131225586004,0.83470135927199995,0.84565407037734996,0.85677343606948997,0.86799627542496005,0.87909156084061002,0.88947695493697998,0.89913064241409002,0.90762948989867998,0.91508531570435003,0.92134314775466997,0.92681777477264005,0.93258780241012995,0.93832921981812001,0.94400370121001997,0.94924128055572998,0.95289027690886996,0.95543271303177002,0.95753562450409002,0.95898121595383001,0.95940345525741999,0.95918238162993996,0.95905077457428001,0.95906662940979004,0.95992225408553999,0.96131229400634999,0.96288675069809004,0.96457600593566994,0.96628773212432995,0.96744453907012995,0.96613699197768999,0.96316188573837003,0.95946091413498003,0.95512783527374001,0.95107889175414995,0.94696027040482,0.94233012199402,0.93728262186050004,0.93182307481766002,0.92595744132996005,0.91979038715363004,0.91313451528548994,0.90533530712127996,0.89685225486755005,0.88864803314208995,0.88048601150512995,0.87224888801574996,0.86398631334304998,0.85571765899658003,0.84756195545196999,0.83992433547973999,0.83264726400375,0.82505118846893,0.81813651323318004,0.81511473655700994,0.81417262554169001,0.81179618835448997,0.80879026651382002,0.80556541681289995,0.80176424980163996,0.79619824886321999,0.78968423604964999,0.78398460149765004,0.77873545885086004,0.77389454841614003,0.76951962709427002,0.76608484983444003,0.76294875144957996,0.75829464197159002,0.75270682573318004,0.74704891443252996,0.74079954624176003,0.73227483034134,0.72285205125809004,0.71583741903304998,0.71053493022919001,0.70676523447036999,0.70469880104064997,0.70533823966980003,0.70752972364426003,0.70808368921279996,0.70786458253859996,0.70768547058105002,0.70724916458130005,0.70613831281661998,0.70431667566299005,0.70144587755203003,0.69752019643784002,0.69225758314133001,0.68577951192856001,0.67743360996246005,0.66888386011124001,0.6657686829567,0.66599309444427002,0.66639852523804,0.66737455129623002,0.66860830783844005,0.66950273513794001,0.66766345500946001,0.66379219293594005,0.65845823287964,0.65193414688109996,0.64505070447921997,0.63840681314467995,0.63517153263091997,0.63374435901642001,0.63069832324982,0.62677401304244995,0.62214738130569003,0.61705344915390004,0.61278039216994995,0.60836958885193004,0.60088604688643998,0.59167307615279996,0.58333122730255005,0.57565689086913996,0.57006871700286998,0.56553339958190996,0.55937474966048994,0.55211633443831998,0.54384130239487005,0.53454899787902999,0.52446532249450994,0.51317572593688998,0.49865725636482,0.48245435953139998,0.46876621246338002,0.45684736967086997,0.44708499312401001,0.43891143798827997,0.43076154589652998,0.42263400554656999,0.41347277164459001,0.40346983075142001,0.3924657702446,0.38069665431976002,0.36891910433768998,0.35698038339615001,0.34475213289260997,0.33237707614898998,0.32028678059577997,0.30845269560813998,0.29755410552025002,0.28664714097977001,0.27226924896240001,0.25564184784888999,0.23876520991325001,0.22175735235214,0.20667842030524999,0.19266690313816001,0.17768658697605,0.16238841414451999,0.14767856895924,0.13380551338196001,0.12264885008335,0.11334317922591999,0.10371678322554,0.094321429729462003,0.085781373083591003,0.078114166855812003,0.072788074612616993,0.067910417914390994,0.055957049131393002,0.039907768368721001,0.026506589725614,0.014513444155455,0.0039351559244096002,-0.0059336302801966997,-0.018367268145083999,-0.031899362802505001,-0.042641479521990003,-0.051608696579933,-0.059681717306376003,-0.067680768668651997,-0.080417394638061995,-0.095637619495391998,-0.10721546411514001,-0.11653001606464,-0.1248759329319,-0.13238328695297,-0.14063282310962999,-0.14896194636821999,-0.15535382926464,-0.16073562204837999,-0.16719007492064999,-0.17506140470504999,-0.18818202614783999,-0.20445400476455999,-0.21764169633388999,-0.22883822023868999,-0.23832409083843001,-0.24615329504013,-0.2525580227375,-0.25759899616241,-0.26134249567986001,-0.26434192061424,-0.26898473501205,-0.27501237392425998,-0.28341078758240001,-0.29339066147803999,-0.30204659700393999,-0.31011989712714999,-0.31890475749968999,-0.32809942960739003,-0.33752730488777,-0.34674823284148998,-0.35366401076317,-0.3586371243,-0.36168074607848999,-0.36295592784882003,-0.36270630359650002,-0.36156794428825001,-0.36263591051102001,-0.36541312932968001,-0.37007704377174,-0.37628099322318997,-0.38277578353882002,-0.38952925801277,-0.39542576670647001,-0.40073227882384999,-0.40583762526512002,-0.41070935130119002,-0.41549611091614003,-0.42010635137558,-0.42389228940009999,-0.42743963003159002,-0.43344098329544001,-0.44094833731651001,-0.44737228751183,-0.45310172438621998,-0.45851862430572998,-0.46307268738746998,-0.46367940306664002,-0.46171015501022,-0.46162086725235002,-0.46272033452987998,-0.46454748511313998,-0.46756264567375,-0.47442641854286,-0.48387289047241,-0.49166217446326999,-0.49827402830124001,-0.50293987989426003,-0.50590878725052002,-0.50743532180786,-0.50793391466141002,-0.50962001085280995,-0.51224738359451005,-0.51620125770569003,-0.52144837379455999,-0.52861022949219005,-0.53697395324706998,-0.54322159290313998,-0.54797738790511996,-0.55194896459579001,-0.55513685941696,-0.55769860744475996,-0.56000626087188998,-0.56423735618590998,-0.56997507810592996,-0.57669019699097002,-0.58440560102463002,-0.59356641769409002,-0.60320472717285001,-0.60790222883223999,-0.60914522409438998,-0.61080104112625,-0.61245536804198997,-0.61467492580413996,-0.61731511354446,-0.61999839544295998,-0.62294191122054998,-0.62714433670044001,-0.63238018751143998,-0.63845574855803999,-0.64498466253280995,-0.64940071105956998,-0.65243279933928999,-0.65624785423278997,-0.66051769256591997,-0.66509538888930997,-0.66982442140579002,-0.67356413602829002,-0.67672574520110995,-0.68095636367797996,-0.68582504987716997,-0.69029074907303001,-0.69420039653777998,-0.69560664892196999,-0.69515854120255005,-0.69511514902115001,-0.69520390033722002,-0.69541347026824996,-0.69585454463958996,-0.69743049144744995,-0.69978892803192005,-0.70146572589874001,-0.70272117853164995,-0.70397818088530995,-0.70523494482039994,-0.70677268505096003,-0.70854556560516002,-0.71080070734024003,-0.71313136816025002,-0.71325576305389005,-0.71143049001694003,-0.70721501111983998,-0.70098531246185003,-0.69447588920592995,-0.68771582841873002,-0.68221032619475996,-0.67779952287673995,-0.67505013942719005,-0.67347019910812,-0.67010319232940996,-0.66569083929062001,-0.66275954246520996,-0.66092962026596003,-0.65990322828293002,-0.65938490629196,-0.65710180997848999,-0.65355670452117998,-0.65028464794159002,-0.64706385135651001,-0.64371114969253995,-0.64006716012955001,-0.63454240560532005,-0.62783741950989003,-0.62363183498383001,-0.62122178077697998,-0.61885958909988004,-0.61656719446181996,-0.61305987834929998,-0.60868459939956998,-0.60475414991378995,-0.60111254453659002,-0.59774863719939997,-0.59458261728286999,-0.59119844436645996,-0.58751952648162997,-0.58246070146561002,-0.57638740539551003,-0.57099097967148005,-0.56610321998596003,-0.56213515996932995,-0.55870622396469005,-0.55321586132050005,-0.54622846841812001,-0.53968960046768,-0.53347635269164995,-0.52794063091277998,-0.52329373359679998,-0.52195096015929998,-0.52309495210648005,-0.52259922027588002,-0.52091550827026001,-0.51850718259811002,-0.51496249437331998,-0.50658470392226995,-0.49464094638824002,-0.48604264855384999,-0.47981354594231002,-0.47408857941628002,-0.46888938546181003,-0.46300438046455,-0.45668801665306002,-0.45101314783096003,-0.44572666287422003,-0.43990716338157998,-0.43337881565094,-0.42332333326339999,-0.41076853871345997,-0.40199899673461997,-0.39598968625068998,-0.38960254192352001,-0.3830289542675,-0.37511256337165999,-0.36636686325072998,-0.36056065559387002,-0.35670083761214999,-0.34962180256844,-0.33978638052940002,-0.32586920261383001,-0.30910983681679,-0.29971274733543002,-0.29568064212799,-0.28830945491790999,-0.27846249938010997,-0.26595383882522999,-0.25162267684937001,-0.24310548603535001,-0.23886252939701,-0.23155219852924,-0.22200885415077001,-0.21149018406868,-0.20020763576031,-0.19150534272194,-0.18439726531506001,-0.17238412797451,-0.15646813809872001,-0.13981010019779,-0.12278003245591999,-0.11183390021324,-0.10576398670673,-0.098931282758713004,-0.091798499226570004,-0.084251299500465004,-0.076295077800750996,-0.068205244839191007,-0.059434019029140001,-0.044091250747442003,-0.023478573188186001,-0.0048928251489996997,0.011986793950199999,0.023730576038361002,0.031210485845803999,0.039880786091088999,0.049217816442250997,0.058437012135982999,0.067631326615810006,0.076857246458529996,0.086518503725528995,0.10151236504316,0.12076572328806,0.13746172189712999,0.15211096405982999,0.16430401802062999,0.17416873574257,0.18187847733498,0.18786558508873,0.19699668884277,0.20875814557076,0.22205223143100999,0.23677033185959001,0.25099650025367998,0.26489597558974998,0.27862662076950001,0.29214447736740001,0.30516004562378002,0.31756275892258001,0.32739961147308,0.33519759774208002,0.34544995427132003,0.35765352845192,0.36999201774597001,0.38246595859527999,0.39331328868866,0.40298730134964,0.41561415791512002,0.43057754635811002,0.44416746497154003,0.45654767751693998,0.46599826216697998,0.47314971685410001,0.48452129960059998,0.49927040934563,0.51268035173416004,0.52501761913300005,0.53536063432693004,0.54410547018051003,0.55562210083008001,0.56932771205902,0.58150041103363004,0.59241318702697998,0.60236030817032005,0.61146306991577004,0.62161713838577004,0.63253921270369995,0.64206844568252996,0.65039116144179998,0.65803474187850997,0.66509056091309005,0.67333638668060003,0.68254238367080999,0.69103568792342995,0.69897884130478005,0.70707136392592995,0.71540600061417003,0.72631454467773005,0.73933750391006003,0.74974471330643,0.75795149803161999,0.76586389541625999,0.77342724800109997,0.78154957294464,0.79000383615493996,0.79614740610123003,0.80020725727080999,0.8033419251442,0.80548804998398005,0.80636811256409002,0.80612039566039995,0.80670154094696001,0.80802559852599998,0.81042116880417003,0.81390285491943004,0.81950980424881004,0.82694631814956998,0.83225321769714,0.83565378189087003,0.83737421035767001,0.83739978075027,0.83504426479339999,0.83058983087539995,0.82870501279830999,0.82893586158751997,0.82736396789551003,0.82424449920653997,0.82075607776642001,0.81689876317978005,0.81369245052338002,0.81100279092788996,0.80726355314255005,0.80257761478423995,0.79734736680983997,0.79164671897887995,0.78738528490066995,0.78436702489853005,0.78043609857559004,0.77572917938232,0.77110898494720004,0.76653832197188998,0.76220589876175004,0.75796163082123003,0.75056648254394998,0.74032092094420998,0.73061072826384998,0.72130203247070002,0.71258932352065996,0.70439523458481001,0.69524639844893998,0.68526619672775002,0.67591083049774003,0.66711652278900002,0.65874797105788996,0.65077978372573997,0.64261472225188998,0.63425517082214,0.62522906064987005,0.61553817987442005,0.60489809513091997,0.59325224161148005,0.57834458351134999,0.56047540903090998,0.54538166522980003,0.53282177448273005,0.52171856164931996,0.51208811998366999,0.50388783216475996,0.49704897403717002,0.48963254690169999,0.48167526721954002,0.47251942753791998,0.46213230490684998,0.44821166992188,0.43104365468025002,0.41723302006721003,0.40651029348373002,0.39668551087379,0.38781431317329002,0.38026839494705,0.37394917011260997,0.3658073246479,0.35593792796134999,0.3447542488575,0.33221134543419001,0.31610041856766002,0.29673513770102999,0.28381335735321001,0.27695399522781,0.27117216587067,0.26657816767692999,0.26349991559982,0.26186215877532998,0.25857749581336997,0.25373780727386003,0.24812823534011999,0.24173916876316001,0.23444937169551999,0.22632697224616999,0.22062893211842,0.21722441911696999,0.21312035620212999,0.20838606357573999,0.20355835556984,0.19865939021111001,0.19533069431781999,0.19350610673428001,0.19126668572426,0.18864817917346999,0.18579143285751001,0.18271155655384,0.18040493130683999,0.17883962392807001,0.17694608867167999,0.17475089430808999,0.17293232679366999,0.17149558663368,0.17162379622459001,0.17326964437962,0.17406010627747001,0.17403168976307001,0.17375488579272999,0.17323112487792999,0.17317193746567,0.17354656755924,0.17179407179355999,0.16798871755600001,0.16722868382931,0.16946260631084001,0.17448779940605,0.18226052820683,0.18736650049685999,0.18985341489315,0.19061541557312001,0.18965238332748,0.18742935359478,0.18394556641578999,0.17929427325726,0.17349280416964999,0.17075639963149999,0.17106056213379001,0.17269712686538999,0.17566484212875,0.17794638872147001,0.17954339087009,0.17824117839336001,0.1740461140871,0.16954569518566001,0.16473808884621,0.1599453240633,0.15516711771488001,0.15083935856819,0.14696285128593001,0.14334452152252,0.13998426496982999,0.13710062205790999,0.13470615446567999,0.12889121472835999,0.11962442100048,0.1110732331872,0.10325388610363,0.096593782305716996,0.091116569936274996,0.083194501698016995,0.072779908776283,0.063722424209118,0.056052979081869,0.049312327057122997,0.043533362448214999,0.034271776676177999,0.021439353004098001,0.010397629812360001,0.0012086490169168,-0.0070869391784072,-0.014438087120651999,-0.026635663583875001,-0.043845392763615001,-0.057468857616186003,-0.067364171147345997,-0.076558463275433003,-0.085032097995280997,-0.096980847418307994,-0.11255466938019,-0.12532930076122001,-0.13515308499336001,-0.14571048319339999,-0.15698233246803001,-0.17417275905609,-0.19757375121116999,-0.21480683982372001,-0.22553580999374001,-0.23665596544743001,-0.24822136759758001,-0.26383429765701,-0.28374639153481002,-0.29849654436111001,-0.30773136019706998,-0.31970849633217002,-0.33456841111183,-0.35395163297652998,-0.37814542651175997,-0.39570468664169001,-0.40616923570633001,-0.41848304867744002,-0.43286114931107,-0.44872483611107,-0.46623578667641002,-0.47819212079048001,-0.48416432738303999,-0.49403128027915999,-0.50810521841048994,-0.52430355548858998,-0.54276663064956998,-0.55650305747985995,-0.56512492895125999,-0.57546478509902999,-0.58774858713150002,-0.60059094429016002,-0.61403262615204002,-0.62566584348679,-0.63534384965896995,-0.64541476964950995,-0.65596950054169001,-0.66624891757964999,-0.67622309923171997,-0.68623489141464,-0.69629001617431996,-0.70655953884125,-0.71707290410994995,-0.72716933488846003,-0.73683291673660001,-0.74591529369354004,-0.75443750619887995,-0.76143145561217995,-0.76678097248077004,-0.77263462543488004,-0.77904337644577004,-0.78686851263045998,-0.79620188474654996,-0.80577665567398005,-0.81558895111083995,-0.82452118396759,-0.83253049850464,-0.83943086862563998,-0.84521609544753995,-0.84954112768172996,-0.85227811336517001,-0.85621845722197998,-0.86151254177094005,-0.86759936809539995,-0.87455087900161999,-0.88023060560225996,-0.88446700572967996,-0.88897007703780995,-0.89383459091187001,-0.89862012863159002,-0.90338325500488004,-0.90635144710541005,-0.90730041265488004,-0.90929806232452004,-0.91253662109375,-0.91605681180954002,-0.91988360881804998,-0.92267149686812999,-0.92428898811339999,-0.92595601081848,-0.92772251367569003,-0.92972463369369995,-0.9319651722908,-0.93472999334335005,-0.93810141086578003,-0.94072043895721003,-0.94246858358383001,-0.94419336318970004,-0.94591176509857,-0.94821077585220004,-0.95123749971390004,-0.95280843973160001,-0.95270901918411,-0.95264881849288996,-0.95272266864777,-0.95297032594680997,-0.95353281497955,-0.95181280374527,-0.94743859767913996,-0.94431275129318004,-0.94272363185883001,-0.94168657064437999,-0.94126534461974998,-0.93949997425079002,-0.93610954284668002,-0.93381178379059004,-0.9328807592392,-0.93153738975525002,-0.92977416515349998,-0.92575711011886996,-0.91908121109009,-0.91442537307739002,-0.91227859258652,-0.90974628925322998,-0.90678352117537997,-0.90110003948212003,-0.89220380783080999,-0.88532638549804998,-0.88105660676955999,-0.87570220232009999,-0.86906528472900002,-0.86040163040161,-0.84934669733046997,-0.84049206972122004,-0.83438056707382002,-0.82782500982285001,-0.82065474987029996,-0.81220036745071,-0.80219191312789995,-0.79383766651153997,-0.78769582509994995,-0.77900016307830999,-0.76730591058731001,-0.7538036108017,-0.73824840784072998,-0.72513681650161999,-0.71503341197967996,-0.70508331060410001,-0.69507491588592996,-0.68519586324691995,-0.67533284425734996,-0.66733473539351995,-0.66178733110428001,-0.65254247188568004,-0.63884097337723,-0.62399113178252996,-0.60791242122650002,-0.59505420923232999,-0.58624523878098,-0.57568931579589999,-0.56270879507064997,-0.55014353990554998,-0.53813415765761996,-0.52761960029601995,-0.51893377304077004,-0.50901067256927002,-0.49743852019309998,-0.48610737919807001,-0.47515654563903997,-0.46460226178169001,-0.45441997051239003,-0.44520646333693997,-0.43713200092316001,-0.42879328131675998,-0.42006480693817,-0.41070356965065002,-0.40030491352080999,-0.39369764924049,-0.39185711741446999,-0.38851162791251997,-0.38305866718291998,-0.37602150440215998,-0.3673469722271,-0.35740631818771001,-0.34601533412933,-0.33582073450089001,-0.32719147205353,-0.31886079907416998,-0.31058272719383001,-0.30424141883849998,-0.30030271410942,-0.29545900225638999,-0.28931239247321999,-0.28277671337128002,-0.27596613764763001,-0.26813510060309997,-0.25899714231491,-0.25104779005050998,-0.24471078813076,-0.23816241323948001,-0.23128356039524001,-0.22343166172504,-0.21430303156375999,-0.20637775957584001,-0.20015351474285001,-0.19309569895267001,-0.18499957025051,-0.17511452734470001,-0.16284295916557001,-0.15358778834343001,-0.14838230609893999,-0.14258392155169999,-0.13571678102015999,-0.12783269584179,-0.11863810569048,-0.11090309917927001,-0.10533380508423,-0.097824372351170003,-0.087799005210400002,-0.076422892510891002,-0.063390001654624994,-0.052945386618376,-0.046126667410134999,-0.037531580775976001,-0.026328541338443999,-0.014820666983724,-0.0029303096234798002,0.0062614921480417,0.011891597881913,0.018608022481202999,0.027116585522890001,0.03563205525279,0.043975219130515997,0.052220948040485,0.060121491551399002,0.070139944553374994,0.082940854132175001,0.095208980143069999,0.10672973096371,0.11567808687687001,0.12133994698524,0.12789899110794001,0.13605846464634,0.14396898448466999,0.15139263868332001,0.15879571437835999,0.16607023775578,0.17470929026604001,0.18520425260067,0.19491562247276001,0.20353619754314001,0.21075659990310999,0.21623976528645,0.22235214710236001,0.22952321171761,0.23667980730534,0.24366916716098999,0.25092747807503002,0.25861546397209001,0.26566246151924,0.27177929878235002,0.27825626730919001,0.28526613116263999,0.29281297326088002,0.30112272500991999,0.30829086899757002,0.31376123428344999,0.32006832957268,0.32766342163085999,0.33560433983803001,0.34402674436568997,0.35071632266045,0.35473093390464999,0.36142444610595997,0.37204149365424999,0.38241720199585,0.39215308427811002,0.40005350112915,0.40552145242691001,0.41157063841820002,0.41880697011947998,0.42571356892585999,0.43211328983307001,0.43778911232947998,0.44208166003227001,0.45023500919342002,0.46384626626968001,0.47640079259871998,0.48695814609527999,0.49555683135986001,0.50148403644562001,0.50985419750214001,0.52216756343841997,0.53265327215195002,0.54025804996490001,0.54663532972336004,0.55119729042053001,0.56023591756821001,0.57584828138350996,0.58951842784882003,0.59964090585708996,0.60897415876389005,0.61764967441559004,0.62702351808547996,0.63773947954178001,0.64673024415970004,0.65324044227599998,0.65933805704116999,0.66497772932053001,0.67288583517074996,0.68420422077178999,0.69382756948471003,0.70043694972991999,0.70795452594757002,0.71684378385544001,0.72813808917999001,0.74300944805144997,0.75431489944457997,0.76012736558913996,0.76585924625396995,0.77220731973648005,0.77999395132064997,0.79010021686553999,0.79763382673264005,0.80107247829437001,0.80555242300034002,0.81198191642760997,0.81968289613723999,0.82902681827544999,0.83710807561874001,0.84306478500366,0.84936070442199996,0.85641604661941995,0.86398661136626997,0.87235963344573997,0.87942594289779996,0.88447415828705001,0.88984763622284002,0.89599585533142001,0.90245610475539995,0.90930867195128995,0.91572767496108998,0.92149537801742998,0.92703449726105003,0.93244326114654996,0.93742781877518,0.94190341234206998,0.94614738225937001,0.95027792453766002,0.95375710725784002,0.95633792877196999,0.95908105373383001,0.96227198839188,0.96521461009979004,0.96760427951812999,0.97084027528762995,0.97542190551758001,0.97972124814987005,0.98350322246552002,0.98641175031661998,0.98825365304946999,0.98957967758179,0.99044758081436002,0.99108999967574996,0.99151045084,0.99209642410277998,0.99297565221785999,0.99389016628265003,0.99486827850341997,0.99546259641646995,0.99560242891312001,0.99507045745849998,0.99361884593964001,0.99254834651946999,0.99237400293349998,0.99139630794525002,0.98914402723312,0.98663961887359997,0.98411911725998003,0.98115128278732,0.97768598794937001,0.97361975908278997,0.96893155574798995,0.96354323625564997,0.95738399028777998,0.95079791545867998,0.94398581981659002,0.93606364727019997,0.92658877372741999,0.91718494892119995,0.9079949259758,0.90032637119293002,0.89523565769196001,0.88803923130035001,0.87711107730865001,0.86649829149246005,0.85695821046829002,0.84860765933990001,0.84237289428711004,0.83319032192230003,0.81916260719299006,0.80518823862076006,0.79239100217819003,0.77961474657059004,0.76671230792999001,0.75382846593857,0.74094748497009,0.72826296091080001,0.71586823463439997,0.70351356267928999,0.69133335351944003,0.67813324928284002,0.66324198246001997,0.64903938770294001,0.63625925779342996,0.62357145547866999,0.61078852415085005,0.59758317470551003,0.58359110355376997,0.57038164138794001,0.55867213010787997,0.54632818698883001,0.53301167488098,0.51789867877960005,0.49995374679565002,0.48381799459456998,0.47117969393730003,0.45843845605849998,0.44485193490982,0.43053933978080999,0.41491445899009999,0.40100920200348,0.39000979065894997,0.37926340103148998,0.36820933222771002,0.35694319009781,0.34527158737183,0.33399653434753002,0.32349762320518,0.31267845630646002,0.30123129487037997,0.28949531912804,0.27738973498344,0.26565486192702997,0.25455686450005,0.24367974698544001,0.23289069533348,0.22252120077609999,0.21268753707408999,0.20318131148815,0.19418664276600001,0.18440014123917001,0.17325638234615001,0.16199615597725001,0.15088386833667999,0.13993228971957999,0.1291421353817,0.11876332759857,0.10887037962675,0.099463537335395993,0.090616993606091004,0.082041591405869002,0.074031040072441004,0.064489513635635001,0.052349116653203999,0.040311973541975001,0.028905779123306,0.018777947872877,0.010718123055995,0.0018588011153042,-0.0090876296162605008,-0.019095353782176999,-0.027304541319609001,-0.034484144300222001,-0.040292106568812998,-0.047143332660197997,-0.056152708828448999,-0.064983174204825994,-0.073028780519962005,-0.080543071031570004,-0.086628064513205996,-0.096168994903563995,-0.11201371997595,-0.12622873485087999,-0.13632778823375999,-0.14477625489234999,-0.15137982368469,-0.15919245779513999,-0.16992974281310999,-0.17938965559006001,-0.18600827455520999,-0.19242006540298001,-0.19862793385982999,-0.20784413814545,-0.22261837124825001,-0.23489990830421001,-0.24155798554419999,-0.24756442010402999,-0.25367116928101002,-0.26172539591789001,-0.27343711256981001,-0.28363466262817,-0.29013597965240001,-0.29692035913467002,-0.30469122529030002,-0.31485867500304998,-0.3296537399292,-0.34049361944199003,-0.34350645542144997,-0.34585541486740001,-0.34948825836182001,-0.35332405567169001,-0.35745218396187001,-0.36122250556946001,-0.36408594250678999,-0.36779555678367998,-0.37295377254486001,-0.37910750508308,-0.38676398992538003,-0.39305105805397,-0.39640685915946999,-0.40019363164902,-0.40558525919914001,-0.41117423772812001,-0.41688162088393999,-0.42165124416351002,-0.42473310232161998,-0.42797252535820002,-0.43203300237656,-0.43618467450142001,-0.44036719202995001,-0.44417423009871998,-0.44733521342277999,-0.45041486620902998,-0.45349347591400002,-0.45693084597588002,-0.46093159914017001,-0.46520978212357,-0.46987807750701999,-0.47404897212982,-0.47724762558937001,-0.48032709956169001,-0.48354026675223999,-0.48677793145179998,-0.49033978581429,-0.49275472760201,-0.49299019575119002,-0.49368622899054998,-0.49567502737044999,-0.49880075454711997,-0.50393140316009999,-0.50726652145385998,-0.50654715299606001,-0.50658357143402,-0.50896728038787997,-0.51275879144669001,-0.51836341619491999,-0.52353030443191995,-0.52716326713562001,-0.53079259395598999,-0.53484052419661998,-0.53914117813109996,-0.54410678148269997,-0.54781901836394997,-0.54904502630233998,-0.55050569772720004,-0.55331569910049005,-0.55610406398773005,-0.55870795249938998,-0.56031912565231001,-0.55989903211594005,-0.56072640419006003,-0.56452441215515003,-0.56833100318909002,-0.57124775648116999,-0.57353669404983998,-0.57498204708098999,-0.57629156112670998,-0.57778555154800004,-0.57909458875655995,-0.58016538619994995,-0.58080428838730003,-0.58041781187056996,-0.58135968446732,-0.58504736423491999,-0.58880084753035999,-0.59162712097168002,-0.59439396858214999,-0.59783989191054998,-0.59930711984634,-0.59703594446181996,-0.59474027156830001,-0.59384083747864003,-0.59325730800628995,-0.59274321794509999,-0.59262174367904996,-0.59293776750564997,-0.59388399124145996,-0.59565955400466997,-0.59779602289199996,-0.60048234462738004,-0.60214126110077004,-0.60155695676804,-0.60137873888016002,-0.60275453329086004,-0.60449004173278997,-0.60631090402603005,-0.60818088054657005,-0.61001819372177002,-0.61189377307892001,-0.61399197578429998,-0.61556822061538996,-0.61635029315947998,-0.61625146865845004,-0.61455267667769997,-0.61404162645339999,-0.61647570133208995,-0.61882954835892001,-0.62012338638305997,-0.62037903070449996,-0.61887973546982,-0.61796236038207997,-0.61891025304794001,-0.61997884511947998,-0.62054997682571,-0.62107414007187001,-0.62164258956909002,-0.62220931053161999,-0.62303298711777,-0.62298065423964999,-0.62132662534714,-0.61920905113220004,-0.61657148599625,-0.61523330211639005,-0.61644911766052002,-0.61832040548324996,-0.62034076452255005,-0.62208682298660001,-0.62323111295699996,-0.62391793727875,-0.62414538860321001,-0.62391853332519998,-0.62319028377533003,-0.62217026948929,-0.62100100517273005,-0.61945164203643999,-0.61749428510666005,-0.61491668224335005,-0.61155116558074996,-0.60766643285750999,-0.60341590642928999,-0.59853124618529996,-0.59274053573607999,-0.58678501844405995,-0.58105111122131003,-0.57515048980713002,-0.56896889209747004,-0.56254833936690996,-0.55587929487228005,-0.54898172616958996,-0.54176038503646995,-0.53464186191559004,-0.52788424491882002,-0.52118235826491999,-0.51437604427338002,-0.50775563716887995,-0.50177091360091997,-0.49501571059227001,-0.48672395944594998,-0.47762137651442998,-0.46797284483910001,-0.45748129487037997,-0.44588726758956998,-0.43387100100517001,-0.42158651351929,-0.40954157710075001,-0.39799058437347001,-0.38706755638123003,-0.37729009985924,-0.36705005168915,-0.35541194677353,-0.34334322810173001,-0.33093330264090998,-0.31898960471152998,-0.30844444036483998,-0.29726007580757002,-0.28428494930267001,-0.27079954743384999,-0.25724905729294001,-0.24346473813057001,-0.22940433025359999,-0.21526852250098999,-0.20104438066482999,-0.18715693056582999,-0.17391440272330999,-0.16094224154948999,-0.14786264300346,-0.13567247986794001,-0.12504175305366999,-0.1150489076972,-0.10536101460456999,-0.095982536673546004,-0.087116964161395999,-0.077682271599769995,-0.066825091838837003,-0.055833924561739003,-0.045357823371886999,-0.034792196005582997,-0.02398126758635,-0.012835469096899,-0.0011896984651685,0.010636903345584999,0.022579271346331,0.034382883459330001,0.046257581561803998,0.056787468492985001,0.064561106264590995,0.072258628904819003,0.081373870372771995,0.090547151863574996,0.099440239369868996,0.10777551680803001,0.11489567160606,0.12244565784931,0.13128423690796001,0.14102530479431,0.15179635584354001,0.16303300857544001,0.17432522773743001,0.18616406619549,0.19913974404335,0.21169824898243,0.22301036119461001,0.23343104124069,0.24293218553066001,0.25165280699730003,0.25942692160606001,0.26715356111526001,0.27543300390244002,0.28378054499625999,0.2920323908329,0.30027464032173001,0.30823075771331998,0.31698012351990001,0.32743391394615001,0.33827745914459001,0.34925156831741,0.35926651954651001,0.36701741814612998,0.37478962540626998,0.38390889763831998,0.3932757973671,0.40291637182236001,0.41149252653121998,0.41785797476768,0.42336422204971003,0.42846760153770003,0.43343749642371998,0.43876710534095997,0.44360271096229997,0.44667351245879999,0.45122945308684997,0.45999747514724998,0.46900397539138999,0.47646516561508001,0.48253664374352001,0.48632696270942999,0.48989209532737998,0.49474009871482999,0.49913740158080999,0.50230270624161,0.50453925132750999,0.50510066747664994,0.50670516490936002,0.51193392276764005,0.51682782173157005,0.51924234628677002,0.52034401893616,0.51948511600493996,0.51975286006927002,0.52412027120589999,0.52822208404541005,0.52951198816299005,0.52993136644363004,0.52945351600646995,0.53032964468001997,0.53513771295546997,0.53969782590866,0.54139715433121005,0.54237997531891002,0.54328376054764005,0.54440581798553001,0.54642510414124001,0.54815626144409002,0.54869830608367998,0.54914802312850997,0.55004650354384999,0.55119091272354004,0.55288392305374001,0.55406254529953003,0.55368518829346003,0.55325472354889005,0.55339968204498002,0.55444902181625,0.55746269226073997,0.56002146005630005,0.56023377180098999,0.56009215116500999,0.56071424484252996,0.56112176179885997,0.56072700023651001,0.56030136346817005,0.56018453836440996,0.56046456098556996,0.56132262945175004,0.56263691186904996,0.56465309858321999,0.56639498472214,0.56719195842742998,0.56730151176453003,0.56654965877533003,0.56554359197616999,0.56446844339371005,0.56396228075027,0.56502711772919001,0.56587541103363004,0.56520450115204002,0.56416219472884999,0.56299436092376998,0.56241935491562001,0.56350404024124001,0.56451505422591997,0.56422984600067005,0.56365531682967995,0.56302851438521995,0.56285357475280995,0.56397044658661,0.56493276357651001,0.56466692686080999,0.56410902738571,0.56367301940918002,0.56324177980422996,0.56279736757277998,0.56249052286148005,0.56254410743713001,0.56255275011063,0.5622586607933,0.56175243854523005,0.56116420030594005,0.56004083156586004,0.55773949623107999,0.55543571710587003,0.55383670330047996,0.55285829305649004,0.55307030677794999,0.55299210548401001,0.55121243000030995,0.54933726787567005,0.54826951026917004,0.54766792058945002,0.5478156208992,0.54774332046509,0.54643815755844005,0.54513293504714999,0.54460728168488004,0.54440605640410999,0.54444372653961004,0.54458105564116999,0.54468441009520996,0.54477244615554998,0.54487133026123002,0.54481905698776001,0.54436361789703003,0.54395437240600997,0.54395323991776001,0.54406422376633001,0.54391425848007002,0.54431486129760998,0.54590988159179998,0.54829543828964,0.55192202329635998,0.55487978458404996,0.55510365962982,0.55491763353348,0.55576503276824996,0.55694752931595004,0.55854368209839,0.55984163284302002,0.55988067388535001,0.56003963947295998,0.56142681837081998,0.56309199333190996,0.56482785940169999,0.56588536500930997,0.56499356031418002,0.56414574384688998,0.56496340036392001,0.56618076562881003,0.56736212968826005,0.56813544034957997,0.56777322292328003,0.56724911928177002,0.56727737188339,0.56742203235625999,0.56770443916321001,0.56758093833922996,0.56631612777710005,0.56486421823501998,0.56409549713134999,0.56304633617401001,0.56129902601241999,0.55846130847930997,0.55342745780945002,0.54829859733581998,0.54491442441939997,0.54194486141205001,0.53881216049194003,0.53554463386536,0.53173863887786998,0.52821016311645996,0.52600502967833995,0.52360934019089,0.51995319128035999,0.51535320281982,0.50938111543654996,0.50323170423508001,0.49826532602309997,0.49300447106361001,0.48648777604103,0.47903862595558,0.47017061710357999,0.46137836575508001,0.45417806506156999,0.44740653038025002,0.44045147299767001,0.43350324034691001,0.42665851116179998,0.41955277323723,0.41162213683128002,0.40372231602669001,0.39674031734467002,0.38972166180611001,0.38190394639969,0.37387973070144997,0.36616975069045998,0.35806259512901001,0.34888175129889998,0.33925545215607,0.32948544621468001,0.31973224878311002,0.31019213795661998,0.30099418759346003,0.29233223199844,0.28415650129317999,0.27655774354934998,0.26930364966393,0.26253458857536,0.25525310635567,0.24607944488524999,0.23658327758312001,0.22788232564926,0.21964485943317,0.21246460080147,0.20466306805611001,0.19411501288413999,0.18313364684582001,0.17354838550091001,0.16429461538792001,0.15497365593910001,0.14553906023502,0.13549780845642001,0.12583132088183999,0.11758775264025,0.10991784185171,0.10247235000134,0.094887599349021995,0.086403481662273005,0.077932760119438005,0.070364296436309995,0.062907233834266996,0.055149558931589002,0.046909250319004003,0.037479653954505997,0.028059562668203999,0.019920710474252999,0.012039550580083999,0.0039638420566915997,-0.0046948790550232003,-0.015128732658923,-0.025341792032123001,-0.033039081841707001,-0.040399044752120999,-0.049042161554097997,-0.058286648243666001,-0.090857565402984994,-0.078163653612136993,-0.089600667357444999,-0.095947645604609999,-0.10456348955630999,-0.11362741142511,-0.12270679324865,-0.13025525212288,-0.13776619732379999,-0.14639958739281,-0.15564778447151001,-0.16592088341712999,-0.17562681436538999,-0.18243816494942,-0.18885923922062001,-0.19705869257450001,-0.20587046444415999,-0.21513609588145999,-0.22395625710486999,-0.23069925606250999,-0.23728361725807001,-0.24549199640750999,-0.25429168343544001,-0.2631559073925,-0.27226862311362998,-0.28159248828888001,-0.29127007722854997,-0.30167984962463001,-0.31211018562317,-0.32186561822891002,-0.33116394281387002,-0.34005621075629999,-0.34836009144782998,-0.35552489757537997,-0.36264929175376998,-0.37089359760284002,-0.37974482774733997,-0.38946080207825001,-0.39886331558228,-0.40614682435989002,-0.41312947869300998,-0.42131593823433,-0.43021684885025002,-0.44035124778748003,-0.45020380616187999,-0.45724996924400002,-0.46454250812531001,-0.47512620687485002,-0.48730409145355003,-0.50114119052886996,-0.51416033506393,-0.52217280864715998,-0.52941155433654996,-0.53983813524246005,-0.55129301548003995,-0.56337320804596003,-0.57437789440154996,-0.58070456981659002,-0.58680766820908004,-0.59757661819457997,-0.60966503620148005,-0.62138158082962003,-0.63177549839019997,-0.63702309131622004,-0.64322948455811002,-0.65825599431991999,-0.67559492588043002,-0.69050884246826005,-0.70337963104248002,-0.71108824014663996,-0.71883744001389005,-0.73351109027863004,-0.74940115213393999,-0.76198661327362005,-0.77244782447814997,-0.77924782037734996,-0.78592824935912997,-0.79757118225098,-0.80993670225143,-0.81935501098633001,-0.82741159200668002,-0.83381175994873002,-0.84083700180054,-0.85245758295059004,-0.86481076478957997,-0.87403017282485995,-0.88220131397247004,-0.88992238044739003,-0.89846682548523005,-0.91126310825348,-0.92360633611678999,-0.92983210086822998,-0.93348777294159002,-0.93668705224991,-0.93957597017287997,-0.94348871707916004,-0.94744241237640003,-0.95053488016128995,-0.95334368944168002,-0.95616286993027,-0.95919656753539995,-0.96302640438080001,-0.96704822778702004,-0.97085285186768,-0.97410750389098999,-0.97609865665436002,-0.97721356153488004,-0.97751039266586004,-0.97741019725800005,-0.97800099849701005,-0.97779327630997004,-0.97513347864151001,-0.97055071592330999,-0.96317529678345004,-0.9554997086525,-0.95145684480667003,-0.94802898168563998,-0.94247680902481001,-0.93593853712081998,-0.92842942476273005,-0.92098653316498003,-0.91599780321121005,-0.91059070825577004,-0.90117990970612005,-0.88995671272277999,-0.87766492366791005,-0.86622232198714999,-0.85999947786330999,-0.85471081733704002,-0.84547472000122004,-0.83498185873032005,-0.82471156120300004,-0.81501758098601995,-0.80853730440140004,-0.80095189809798994,-0.78573656082152998,-0.76786655187607,-0.75127834081650002,-0.73625499010086004,-0.72624921798705999,-0.71722257137298995,-0.70426070690154996,-0.68969285488128995,-0.67495220899581998,-0.65931355953216997,-0.64197301864624001,-0.62400197982787997,-0.60708498954773005,-0.58974951505661,-0.57037717103957997,-0.54972869157791004,-0.52795612812042003,-0.50569707155228005,-0.48285847902298001,-0.46224945783615001,-0.44835388660431003,-0.43955063819884999,-0.43525910377501997,-0.43593528866768,-0.44412589073181002,-0.45407533645629999,-0.45745113492012002,-0.45762541890143998,-0.45562887191772,-0.45220318436623003,-0.45268586277961997,-0.44674721360206998,-0.41781759262085,-0.37663289904594,-0.33088970184326,-0.28265902400017001,-0.23559367656708,-0.19653487205504999,-0.18086846172810001,-0.17822144925594,-0.17943888902664001,-0.18604159355163999,-0.19464491307734999,-0.20986403524875999,-0.24024647474288999,-0.27726092934607999,-0.31129696965218001,-0.34410494565964,-0.38390094041824002,-0.40500047802924999,-0.35757952928543002,-0.28140196204184997,-0.21849118173122001,-0.15835657715797,-0.098924160003661998,-0.051673740148543999,-0.039752796292305,-0.045723035931586997,-0.050866935402154999,-0.061287246644497001,-0.075328253209590995,-0.10044625401497,-0.15438233315944999,-0.21858254075049999,-0.27100127935410001,-0.31504964828491,-0.35029515624045998,-0.36650815606116999,-0.33829256892204002,-0.28987580537795998,-0.25091218948364002,-0.21322742104529999,-0.17686492204665999,-0.14237585663794999,-0.10931736975908,-0.081296943128109006,-0.063189469277858998,-0.056581690907477999,-0.065016306936741,-0.091417834162712,-0.15034550428391,-0.22036214172839999,-0.26986986398696999,-0.30885273218155002,-0.33957940340041998,-0.36112371087074002,-0.37293538451195002,-0.37500399351120001,-0.3665537238121,-0.34890884160995,-0.32371085882187001,-0.29136607050896002,-0.24887564778328,-0.20746469497681,-0.18499562144279,-0.17937770485877999,-0.19765837490558999,-0.2337494045496,-0.28493160009384,-0.34081989526749001,-0.37899389863013999,-0.40949419140816001,-0.44023561477661,-0.46762111783027999,-0.49077534675598,-0.50567322969437001,-0.50589448213577004,-0.48960283398628002,-0.44543814659119002,-0.38675686717032998,-0.32972225546836997,-0.27745985984802002,-0.24351468682288999,-0.22590722143649999,-0.23079407215118,-0.25010240077972001,-0.27213308215141002,-0.2986963391304,-0.32448485493660001,-0.35702559351920998,-0.41416567564010998,-0.47767865657806002,-0.52239209413527998,-0.55264896154403997,-0.56787222623824996,-0.55924409627913996,-0.49934664368629,-0.41687548160553001,-0.35433784127235002,-0.29993635416031,-0.25448834896088002,-0.21354833245277,-0.16472753882408001,-0.12042246758937999,-0.099406950175761996,-0.095599018037319003,-0.10497590154409001,-0.13235521316528001,-0.19459864497185,-0.26711654663085999,-0.30804479122161998,-0.33045747876166998,-0.34003892540932001,-0.33234655857085998,-0.29707553982735002,-0.24579021334647999,-0.19748878479004001,-0.14561453461647,-0.088455960154532998,-0.022868663072586001,0.069375425577164002,0.15992082655430001,0.19519805908203,0.19857323169707999,0.18997853994370001,0.16431069374084001,0.11404579132794999,0.057003080844878998,0.02932471036911,0.016239274293183999,0.0062024164944886996,0.0019592568278313,-0.00012298836372793,0.0081163709983230001,0.044127866625786001,0.099044315516949005,0.16429880261421001,0.24009749293327001,0.33087313175201,0.41710478067397999,0.45359352231026001,0.46315371990204002,0.47005236148834001,0.46910628676414001,0.46238651871681002,0.44885858893393998,0.42642816901206998,0.39798244833946,0.36683565378188998,0.33618575334549,0.31064864993094998,0.29815939068794001,0.32423007488250999,0.37132945656776001,0.41509845852852001,0.46052449941634999,0.50569975376128995,0.55030578374863004,0.59373289346695002,0.63334769010544001,0.66417384147643999,0.6846342086792,0.68950480222702004,0.67763090133667003,0.63923805952071999,0.58543008565902999,0.53319096565247004,0.48444291949272,0.45286589860915999,0.43573266267776001,0.43707236647606001,0.45078182220459001,0.46389883756638001,0.48200628161429998,0.51136499643326006,0.54923903942107999,0.59620690345764005,0.64486598968506004,0.68026298284530995,0.70167064666748002,0.69703859090804998,0.67291516065598,0.63483643531799006,0.58762878179550004,0.54483008384705001,0.50539565086365001,0.47505223751067999,0.45163601636887002,0.43320494890213002,0.42051613330840998,0.41076236963272,0.41188514232634998,0.44615849852562001,0.49886506795883001,0.54951167106627996,0.59785813093185003,0.63536769151688,0.65633428096770996,0.63614571094512995,0.59159547090529996,0.54881286621094005,0.50358474254607999,0.46228280663490001,0.41988405585289001,0.36426693201065002,0.30540055036545,0.26076555252075001,0.22718048095703,0.20147135853767001,0.19512656331062,0.24528940021991999,0.32368874549866,0.38038858771324002,0.42698666453362,0.46624633669853,0.49273353815079002,0.48993942141532998,0.46918171644210999,0.45034036040306002,0.42781665921210998,0.40175184607505998,0.36627626419067,0.29842728376388999,0.21924081444740001,0.17118680477142001,0.14210844039917001,0.1245426684618,0.12174722552299,0.1417298167944,0.17578393220901001,0.20517887175082999,0.23498639464377999,0.26708862185478,0.30185005068778997,0.34586834907531999,0.38851457834244002,0.40452271699905001,0.40099513530731001,0.38251531124115001,0.34675532579422003,0.28214192390442,0.20642185211181999,0.16418321430683,0.13915285468102001,0.1139443218708,0.092275157570838998,0.070906147360802002,0.056948360055685002,0.068544387817383007,0.10039909183979,0.15046519041060999,0.21618816256522999,0.29706120491027999,0.37844607234000999,0.41655385494232,0.42572313547134,0.41754621267318998,0.39284506440162997,0.35863119363785001,0.31716054677963001,0.28046798706054998,0.24370619654655001,0.19827562570571999,0.15043297410011,0.1093073412776,0.079770639538764995,0.081769868731498996,0.11037191003561,0.16936688125134,0.24748656153679,0.31739595532416998,0.37962862849236001,0.41703015565871998,0.43640512228012002,0.44618290662766003,0.44544547796249001,0.43673521280289002,0.41918680071830999,0.39246854186058,0.35565090179442999,0.29997524619102001,0.23814108967781,0.20249466598033999,0.18644101917743999,0.19021245837212,0.21428334712982,0.26664867997169001,0.33451545238495001,0.38358375430107,0.42203074693679998,0.45203867554665,0.47510877251625,0.49918514490128002,0.51820105314255005,0.51749360561371005,0.50205290317535001,0.47769147157669001,0.44388160109519997,0.39792832732201,0.34876003861427002,0.32410383224486999,0.31557941436768,0.31500485539436002,0.32340952754021002,0.34000909328460999,0.36341762542724998,0.38897484540938998,0.41699880361557001,0.44549095630646002,0.47483405470848,0.50866037607193004,0.53944575786590998,0.54276698827743997,0.52809470891953003,0.51000291109085005,0.48600718379021002,0.45499965548514998,0.42106917500495999,0.39810842275620001,0.38146862387656999,0.36478596925735002,0.34961456060410001,0.33300769329071001,0.32287311553955,0.34865465760231001,0.39523237943648998,0.43167015910148998,0.46376317739487,0.49258896708487998,0.51518106460571,0.51993578672409002,0.51239579916,0.50393867492676003,0.49185511469840998,0.47549229860306003,0.45283865928650002,0.41351193189620999,0.36520856618880998,0.32682058215141002,0.2958305478096,0.27416223287581998,0.2645263671875,0.28225761651992998,0.31687808036803999,0.34174013137817,0.36258262395858998,0.38204345107079002,0.39950454235076999,0.41526269912719999,0.42728298902512002,0.42921137809753002,0.42118602991103998,0.39977380633353998,0.36504793167114002,0.30966120958327997,0.24386227130890001,0.20059165358542999,0.17181541025638999,0.15073923766613001,0.13838118314743,0.13529548048973,0.1399003714323,0.14606493711471999,0.15597853064537001,0.17425236105919001,0.19881403446198001,0.22754488885402999,0.25661650300026001,0.27167645096778997,0.27331751585007003,0.25167667865753002,0.21232137084007,0.16641078889370001,0.11644538491964,0.080970950424671007,0.053837221115827998,0.024066992104053001,-0.0053885132074356001,-0.031566139310597999,-0.053176857531071001,-0.063498161733149996,-0.063647538423538,-0.051300875842571002,-0.030075456947087999,-0.011575258336961,0.0051733367145060999,0.017335355281830001,0.023209579288959999,0.011896290816367,-0.011327860876918,-0.033630639314650997,-0.05676981061697,-0.076537378132343001,-0.097675397992133997,-0.14013452827930001,-0.19352039694786,-0.22999918460846,-0.25453892350196999,-0.26837885379790999,-0.27083736658096003,-0.25669422745705001,-0.23129607737064001,-0.21275839209556999,-0.19792324304580999,-0.18597184121609001,-0.17786100506783001,-0.17740017175674,-0.18382215499877999,-0.19659166038035999,-0.21586343646049,-0.24078147113323001,-0.27339315414429,-0.32692977786063998,-0.39082360267638999,-0.42838960886001998,-0.4483197927475,-0.46121254563331998,-0.46597075462340998,-0.46434009075165,-0.45652350783348,-0.44457960128784002,-0.42857298254967002,-0.41028130054473999,-0.38943004608154003,-0.36281794309616,-0.33612751960754,-0.33350673317909002,-0.34839725494384999,-0.36952733993530001,-0.39843529462813998,-0.43741726875304998,-0.48140841722487998,-0.50769656896590998,-0.52257633209229004,-0.53790223598480003,-0.55155187845230003,-0.56370544433594005,-0.57179796695708995,-0.56360590457916004,-0.54270386695862005,-0.51543885469437001,-0.48233139514923001,-0.44735774397849998,-0.41394484043120999,-0.40278041362762002,-0.40765869617462003,-0.41551271080970997,-0.42779639363289002,-0.44234845042228998,-0.45936289429665,-0.47826880216598999,-0.49855369329452998,-0.51820611953734996,-0.53624457120894997,-0.54762077331543002,-0.55153405666350996,-0.53932595252991,-0.51395624876021995,-0.48145732283592002,-0.44328230619431003,-0.41005286574364003,-0.38097894191741999,-0.36106163263321001,-0.34829628467559998,-0.3362549841404,-0.32684266567230003,-0.32457587122916998,-0.32906487584114003,-0.34265369176865001,-0.36342611908912997,-0.38544821739196999,-0.40715041756629999,-0.41608271002768998,-0.41450297832489003,-0.40372821688652,-0.38441967964172002,-0.36031761765480003,-0.33120977878571001,-0.29854461550713002,-0.26249676942825001,-0.22440606355667,-0.18511015176772999,-0.14784342050551999,-0.11511597037315,-0.10382854938507,-0.10953187197446999,-0.1227098852396,-0.14347842335701,-0.16737648844719,-0.19281224906444999,-0.20704121887683999,-0.21288488805294001,-0.21545913815498,-0.21421529352665,-0.21227143704890999,-0.20567779242991999,-0.17227193713187999,-0.11979891359806,-0.072572886943817,-0.028496138751507,0.0067394748330116003,0.033003468066454003,0.042837455868721001,0.039599422365427003,0.035975471138954003,0.030216470360756,0.022114254534244999,0.01159481331706,-0.0025369562208652002,-0.018792111426592002,-0.029792945832014001,-0.036390643566847,-0.040173031389713003,-0.037782367318868998,-0.0067044645547867003,0.044348370283841997,0.082150928676127999,0.11161664128304,0.13638857007027,0.15589217841625,0.16842158138752,0.17440421879292001,0.17497202754020999,0.17015020549297,0.16127082705498,0.14769759774207999,0.12433353066444,0.094891920685768003,0.077909246087074002,0.070760697126388994,0.071501061320304996,0.080818071961403004,0.10430346429348,0.13828767836094,0.16393913328647999,0.18450626730919001,0.20531840622424999,0.22592844069004001,0.24887584149837,0.27163487672806003,0.27988198399544001,0.27622759342193998,0.26579779386520003,0.24817423522472001,0.22168546915053999,0.18970677256584001,0.17380048334598999,0.16992048919201,0.16914686560631001,0.17233256995678001,0.17890200018883001,0.18868564069270999,0.19968891143799,0.21234023571013999,0.22829882800578999,0.24682328104973,0.26534825563431003,0.28284755349159002,0.29031005501746998,0.28900048136710998,0.27922642230987998,0.26208305358887002,0.24414922297000999,0.2255754172802,0.21346236765384999,0.20601932704449,0.19616930186748999,0.18548867106438,0.17898917198181,0.17672419548035001,0.18295772373676,0.19707004725933,0.21981617808341999,0.24934667348862,0.27354201674460998,0.29346549510955999,0.30683574080467002,0.31410157680511003,0.31570428609848,0.31217271089554,0.30757007002830999,0.30149286985397,0.29476347565651001,0.28674906492232999,0.27178478240967002,0.25250133872031999,0.24423426389694,0.24503163993359001,0.25249531865120001,0.26685133576393,0.28974774479866,0.31957617402076999,0.34508806467056002,0.36771860718727001,0.38910552859306002,0.40940406918526001,0.43233105540276001,0.45575958490371998,0.46521550416946,0.46314102411269997,0.45680403709411999,0.4457995891571,0.43077182769775002,0.41327986121178001,0.40737375617027,0.41088864207268,0.41800716519356002,0.42917662858963002,0.44405066967009998,0.46243289113045,0.48229107260704002,0.50373554229735995,0.52595406770705999,0.54905068874358998,0.57502150535582996,0.60174471139908003,0.61110192537307995,0.60660797357559004,0.60341691970824995,0.60002124309539995,0.59555041790009,0.58980369567871005,0.58032631874083995,0.56793218851089,0.55766218900680997,0.54911011457443004,0.54239797592162997,0.53789359331131004,0.53974395990372004,0.54704409837723,0.55536609888077004,0.56485641002654996,0.57396060228348,0.58219063282012995,0.58286553621292003,0.57723814249038996,0.57152616977691995,0.56492841243743996,0.55549311637877996,0.54279541969299006,0.52002751827240001,0.48907947540282998,0.46224477887153997,0.43845903873443998,0.41740563511848,0.39923053979874001,0.38601806759834001,0.37723830342293002,0.36979502439499001,0.36362361907959001,0.35551488399505998,0.34575358033179998,0.33414292335509999,0.32087296247482,0.30859431624412997,0.29616537690162997,0.27388700842857,0.24270889163017001,0.20257532596587999,0.15502744913100999,0.11618261784315,0.084422171115874994,0.05657510086894,0.032709512859582998,0.011703052558005,-0.0064514055848121999,-0.022816821932793,-0.037390507757663997,-0.050956625491380997,-0.063595294952392994,-0.076861396431922996,-0.090696707367897006,-0.10464011132716999,-0.11971853673457999,-0.14869284629821999,-0.18947078287600999,-0.22989374399185,-0.27016806602478,-0.30189633369446001,-0.32636097073554998,-0.35107523202896002,-0.37525829672812999,-0.39599424600601002,-0.41326773166656,-0.42433428764343001,-0.42966875433922003,-0.43208295106888001,-0.43173518776893999,-0.43290209770202998,-0.43529352545737998,-0.43833959102630998,-0.44271722435951,-0.45806893706321999,-0.48273828625678999,-0.50389790534973,-0.52243840694427002,-0.53871923685073997,-0.55300194025039995,-0.56906878948212003,-0.58618831634520996,-0.59782880544661998,-0.60448360443115001,-0.60734373331070002,-0.60624784231186002,-0.59896546602249001,-0.58616566658019997,-0.5753145813942,-0.56587278842926003,-0.55681920051574996,-0.54819524288177002,-0.53993785381317005,-0.53214609622955,-0.52623242139815996,-0.52206856012344005,-0.51894629001616999,-0.51696348190307995,-0.51788848638535001,-0.52104032039642001,-0.51727443933487005,-0.50737780332564997,-0.49524199962616,-0.48067584633826999,-0.46338769793509998,-0.44359776377678001,-0.42513465881348,-0.40752175450325001,-0.38660648465156999,-0.36258727312088002,-0.33399808406830001,-0.30163061618804998,-0.27792021632195002,-0.26168552041054,-0.24423465132712999,-0.22602403163910001,-0.2071638405323,-0.18792882561683999,-0.17311234772205,-0.16225105524062999,-0.15162828564643999,-0.14135091006756001,-0.13077868521214001,-0.11962506920099,-0.10133063793182,-0.076497711241245006,-0.050070777535439003,-0.021936565637589001,0.0060749659314751998,0.033952668309212002,0.059415668249129999,0.082624480128288005,0.10466512292624,0.12540598213672999,0.14328306913375999,0.15825062990189001,0.16763639450073001,0.17172989249229001,0.17348296940326999,0.17302994430065,0.17574900388718001,0.18144458532332999,0.19114498794078999,0.20476268231868999,0.22205685079098,0.24284991621971,0.26299792528152,0.28265675902366999,0.30148038268089,0.31950980424880998,0.33801195025443997,0.35654130578040999,0.36523279547691001,0.36455899477004999,0.35639244318008001,0.34092411398888001,0.32362511754036,0.30451402068138,0.28946715593338002,0.27822208404540999,0.26977032423018998,0.26413422822951999,0.26147589087486001,0.26175025105476002,0.26393416523933,0.26801472902298001,0.27267903089522999,0.27795928716660001,0.28503352403641002,0.29329279065132002,0.28400906920433,0.25822323560714999,0.22998446226120001,0.19904541969299,0.16972500085830999,0.14190052449703,0.11656727641821001,0.093691729009151001,0.073407255113125,0.055724106729030998,0.041286602616310002,0.030058372765778999,0.021500213071704001,0.015583170577884,0.010800598189235001,0.0071723195724189004,0.0054168538190424,0.0051028565503657003,-0.012268455699086,-0.045797109603882002,-0.075815409421920998,-0.10279579460620999,-0.12844559550285001,-0.15293534100056,-0.18547539412975,-0.22559580206870999,-0.26016137003898998,-0.28946059942245,-0.31545013189316001,-0.33806973695754999,-0.35497877001762002,-0.36628019809723,-0.37507513165473999,-0.38135048747063,-0.38709452748299,-0.39231520891190003,-0.39979755878447998,-0.40948069095612,-0.42005819082259999,-0.43162775039673001,-0.44906127452849998,-0.47238242626190002,-0.51039302349090998,-0.56261807680130005,-0.60188335180283004,-0.62861096858978005,-0.64978927373885997,-0.66535556316375999,-0.67447769641875999,-0.67722785472869995,-0.67987221479416005,-0.68236225843429998,-0.68626433610916004,-0.69155716896056996,-0.69800549745560003,-0.70560848712920998,-0.71394771337509,-0.72304582595824995,-0.73586201667786,-0.75236284732819003,-0.77089726924895996,-0.79143762588500999,-0.80678486824036,-0.81699800491332997,-0.82722204923630005,-0.83743160963058005,-0.84626489877701006,-0.85371142625809004,-0.85454767942429,-0.84878778457642001,-0.83622282743454002,-0.81686127185821999,-0.79802101850509999,-0.77969682216643998,-0.76899027824402,-0.76590585708617998,-0.76527154445648005,-0.76708638668060003,-0.76927596330643,-0.77183866500854004,-0.77355617284775002,-0.77442252635955999,-0.77537602186203003,-0.77643603086472002,-0.77374678850173995,-0.76729571819304998,-0.75654834508895996,-0.74152582883835005,-0.71676725149154996,-0.68213772773742998,-0.65264230966568004,-0.62839484214783004,-0.60804146528243996,-0.59159469604491999,-0.57748627662659002,-0.56571120023726995,-0.55530500411987005,-0.54625660181045999,-0.53873324394225997,-0.53275346755981001,-0.52702605724335005,-0.52158826589583995,-0.51186311244964999,-0.49775993824004999,-0.48184797167777998,-0.46415045857429998,-0.4451014995575,-0.42471444606781,-0.40259435772896002,-0.37872007489204002,-0.35413533449173001,-0.32885187864304,-0.30244702100754001,-0.2747595012188,-0.25543981790543002,-0.24476593732834001,-0.23659332096576999,-0.23081479966640001,-0.22863709926605,-0.23027084767818001,-0.22517584264278001,-0.21301451325417001,-0.19995002448558999,-0.18609163165091999,-0.17163388431071999,-0.15661595761776001,-0.13975454866886,-0.12097564339638001,-0.10224515199661,-0.083591751754284002,-0.065078288316727004,-0.04650654643774,-0.036777880042790999,-0.036316573619843001,-0.037406601011752999,-0.039869528263806998,-0.043694317340850997,-0.048945914953946998,-0.052491128444671999,-0.054205644875764999,-0.055380135774611997,-0.056072466075419998,-0.055465195327996999,-0.053608350455760997,-0.047795295715331997,-0.037831131368876003,-0.027112543582916,-0.015651002526283,-0.0060200267471373003,0.0018273564055562,0.0029254113323986999,-0.0031530011910944999,-0.0084446342661977005,-0.012547898106276999,-0.019585184752941,-0.029634214937687,-0.044605407863855001,-0.064878955483437001,-0.081883832812309001,-0.095277972519397999,-0.10591903328896,-0.11385276913643,-0.11777473241090999,-0.11754605919123,-0.11504832655191,-0.11009337007999,-0.1095424965024,-0.11374244093895,-0.12156186252832001,-0.13317561149596999,-0.14327794313431,-0.15138614177703999,-0.16384834051132,-0.18102148175239999,-0.20104770362377,-0.22420516610145999,-0.24214668571949,-0.25423264503478998,-0.26636633276938998,-0.27884516119956998,-0.29049021005629999,-0.30136486887932001,-0.30914250016212003,-0.31359466910361999,-0.31715250015259,-0.31990814208983998,-0.32227659225464,-0.32431995868683,-0.32498624920844998,-0.32392817735672003,-0.32768064737320002,-0.33685314655303999,-0.34591999650001998,-0.35465133190155002,-0.36231276392937001,-0.36877596378326,-0.37542402744293002,-0.38243430852889998,-0.3877132833004,-0.39115285873413003,-0.39328503608704002,-0.39461272954941001,-0.38499230146407998,-0.36301261186599998,-0.34416422247887002,-0.32940030097960998,-0.31714904308318997,-0.30756387114525002,-0.29751178622246,-0.28664535284041998,-0.27789765596389998,-0.27157258987427002,-0.26552724838257002,-0.2599641084671,-0.24887669086455999,-0.23147974908352001,-0.21465125679970001,-0.19898062944412001,-0.18161280453205,-0.16263490915298001,-0.13738773763180001,-0.10481340438128001,-0.077399894595145999,-0.056372635066508997,-0.035277199000120003,-0.014011325314641001,0.012377574108541,0.045082218945026002,0.070646859705447998,0.087554596364498,0.10516998916864,0.1239421069622,0.14631250500678999,0.17299476265906999,0.19623534381390001,0.21499608457087999,0.23671212792397001,0.26187473535537997,0.29112556576728998,0.32516792416572998,0.35453179478645003,0.37787407636642001,0.40451353788375999,0.43525317311286998,0.46856909990311002,0.50524872541428001,0.53266876935958996,0.54908353090286,0.56496500968933006,0.58112382888794001,0.59652543067931996,0.61114031076430997,0.62518864870071,0.63856720924376997,0.65295827388762995,0.66854131221770996,0.68476241827010997,0.70152521133422996,0.71973091363907005,0.73949784040451005,0.76040613651276001,0.78265762329101995,0.80338495969771995,0.82255768775939997,0.83713084459304998,0.84663283824920998,0.85317409038544001,0.85671567916869995,0.85974836349487005,0.86249190568923995,0.86533087491989003,0.86846208572387995,0.87004190683365001,0.86969321966170998,0.87004137039185003,0.87129104137420998,0.87385302782059004,0.87797725200652998,0.88140946626662997,0.88396656513214,0.88530546426773005,0.88532054424286,0.88466370105742997,0.88348513841628995,0.88075214624404996,0.87647724151610995,0.86933439970016002,0.85909992456436002,0.84660303592681996,0.83172744512557995,0.81655770540237005,0.80124014616012995,0.78665524721145996,0.77297639846802002,0.75953978300095004,0.74628406763077004,0.73319751024246005,0.72015160322188998,0.70855927467346003,0.69867783784866,0.68933141231536998,0.68045526742935003,0.67194318771362005,0.66443860530853005,0.65026438236237005,0.62785220146178999,0.60499876737595004,0.58235478401184004,0.56123232841491999,0.54204386472702004,0.52278697490692005,0.50308954715729004,0.48479688167571999,0.46811696887016002,0.45293319225311002,0.43945604562759,0.42545056343079002,0.41040581464767001,0.39700388908385997,0.38565671443938998,0.37531334161758001,0.36640775203705001,0.35320839285851002,0.33423033356666998,0.31759107112884999,0.30441012978554,0.29257464408875,0.28226903080940002,0.26982778310776001,0.25411158800125,0.24197283387183999,0.23458413779736001,0.22829414904118001,0.22290337085723999,0.21660971641540999,0.208640396595,0.20399375259875999,0.20355425775051,0.20458364486694,0.20677895843982999,0.21048335731029999,0.21593642234801999,0.22105827927589,0.22575514018536,0.22839346528053001,0.22873318195343001,0.22647486627102001,0.22098885476589,0.21742950379848,0.21639406681060999,0.21863111853600001,0.2243664264679,0.23345541954040999,0.24650061130524001,0.25779685378075001,0.26594865322112998,0.27662438154220997,0.29072532057762002,0.3065879046917,0.32475221157074002,0.33877974748611001,0.34695538878441001,0.35646870732307001,0.36852973699570002,0.38055118918419001,0.39264735579491,0.40124386548995999,0.40493831038474998,0.41137006878853,0.42202273011208002,0.43308854103088001,0.44434496760367997,0.45365121960639998,0.45957031846045998,0.47162330150603998,0.49221569299697998,0.51260054111481002,0.53199064731598,0.54721212387085005,0.55684447288512995,0.56784105300902998,0.58178514242171997,0.59363037347794001,0.60286575555801003,0.60827863216400002,0.60928541421890003,0.60835862159729004,0.60547822713851995,0.60365098714828003,0.60340631008148005,0.60443383455276001,0.60629570484160999,0.61314189434052002,0.62702351808547996,0.63659763336181996,0.63973903656006004,0.63949453830719005,0.63548433780669999,0.63312077522277999,0.63414311408997004,0.63188445568085005,0.62512177228928001,0.61589133739471003,0.60441154241562001,0.59040123224258001,0.57322877645492998,0.55770534276962003,0.54480409622192005,0.53313094377518,0.52251666784285999,0.51333451271056996,0.50583499670028997,0.49847859144210999,0.49109104275703003,0.48309364914893999,0.47445091605186002,0.46458050608634999,0.45384821295737998,0.43847087025642001,0.41728189587593001,0.39403411746025002,0.36938768625259,0.34239977598190002,0.31221798062325001,0.28463083505629999,0.26114097237586997,0.23807078599930001,0.21478551626205,0.19205662608147001,0.16965685784817,0.14988140761852001,0.13364093005656999,0.11737381666898999,0.10043566673994,0.083377093076706002,0.066728577017783994,0.046678129583597003,0.021973606199026,-0.0034095142036675999,-0.028820373117924,-0.054374124854803002,-0.080129228532313995,-0.10517130047083,-0.12918204069138001,-0.15317921340466001,-0.1774929612875,-0.20103824138640999,-0.22385396063328,-0.24432374536991,-0.26184099912643,-0.27825346589088001,-0.29367864131927002,-0.30943283438683,-0.32579940557480003,-0.34294334053992998,-0.36122259497643,-0.37861484289169001,-0.39444136619567999,-0.41068497300147999,-0.42761969566344998,-0.44584685564040999,-0.46625274419785001,-0.48389565944671997,-0.49747741222382003,-0.50927698612213002,-0.51968741416930997,-0.52818655967712003,-0.53451538085938,-0.54001307487488004,-0.54500025510787997,-0.54909139871597001,-0.55221492052078003,-0.55456656217574996,-0.55617058277130005,-0.55694782733917003,-0.55625820159911998,-0.55831325054169001,-0.56443572044373003,-0.57184129953384,-0.58066463470458995,-0.58707159757614003,-0.59020900726318004,-0.58986723423003995,-0.58550488948821999,-0.57950013875961004,-0.57229453325271995,-0.56416314840316995,-0.55530101060866999,-0.54522019624710005,-0.53353279829025002,-0.52213233709335005,-0.51133972406386996,-0.50169712305069003,-0.49364146590232999,-0.48550996184348999,-0.47685116529464999,-0.46837785840034002,-0.46024733781815003,-0.45214897394179998,-0.44402536749839999,-0.43590962886809997,-0.42783555388451,-0.41961658000946001,-0.41133520007133001,-0.40235197544098,-0.39315608143806002,-0.37958461046219,-0.35944899916648998,-0.34024935960769997,-0.32381188869476002,-0.30859422683715998,-0.29454138875008001,-0.28121450543403997,-0.26827716827393,-0.25704389810562001,-0.24783459305763,-0.24046345055102999,-0.23497125506401001,-0.23120534420013,-0.22963118553162001,-0.22726182639598999,-0.22339183092116999,-0.21804058551788,-0.21142163872719,-0.20143283903598999,-0.18628184497356001,-0.17358331382275,-0.16571100056171001,-0.15900601446629001,-0.15276929736136999,-0.1474200040102,-0.14264194667339,-0.14036470651627,-0.14132322371006001,-0.14400693774223,-0.14816644787788,-0.1535664498806,-0.16039617359638,-0.16692903637886,-0.17249810695647999,-0.17838422954082001,-0.18490238487720001,-0.19170857965946,-0.19887882471085,-0.20569512248039001,-0.21187296509743,-0.21794946491718001,-0.22399854660033999,-0.23014368116855999,-0.23603996634482999,-0.24388559162616999,-0.25416159629821999,-0.26744902133942,-0.2844320833683,-0.30270248651505,-0.32213559746741999,-0.34003594517708002,-0.35482946038245999,-0.37090370059013,-0.38977783918380998,-0.40873262286186002,-0.42728990316391002,-0.44505184888839999,-0.46197053790092002,-0.47715681791306003,-0.48974582552910001,-0.50299614667892001,-0.51771187782287997,-0.53407633304596003,-0.55254358053206998,-0.57164961099625,-0.59108269214630005,-0.61052757501601995,-0.62973058223723999,-0.64936631917953003,-0.67022413015366,-0.68885380029678001,-0.70379656553268,-0.71792727708816995,-0.73195374011992997,-0.74557828903197998,-0.75909906625748003,-0.77097117900848,-0.78017991781234997,-0.78987634181975996,-0.80119287967681996,-0.81245398521422996,-0.82332056760787997,-0.83379340171813998,-0.84382170438766002,-0.85337698459625,-0.86243319511413996,-0.87104523181914995,-0.87930792570114003,-0.88682836294173994,-0.89375823736190996,-0.89869475364685003,-0.90090018510818004,-0.90198606252669999,-0.90229535102844005,-0.90215945243835005,-0.90212154388428001,-0.90016657114028997,-0.89521420001983998,-0.88989657163619995,-0.88484245538712003,-0.88041722774506004,-0.87758660316466996,-0.87246340513229004,-0.86298745870589999,-0.85392105579375999,-0.84655678272247004,-0.84080719947814997,-0.83844947814940995,-0.83124583959579001,-0.81491708755492998,-0.79862427711487005,-0.78514486551285001,-0.77256226539612005,-0.76183682680130005,-0.74708282947539995,-0.72477251291275002,-0.70336008071899003,-0.68570929765701005,-0.66910529136658004,-0.65400367975234996,-0.63575440645217995,-0.61110979318618996,-0.58864587545394997,-0.57175803184509,-0.55573529005051003,-0.54005694389342995,-0.52192437648773005,-0.49892181158066001,-0.47773179411888,-0.46143993735312999,-0.44450509548187001,-0.42584916949272,-0.40355315804482,-0.37480166554451,-0.34919127821922002,-0.33141112327576,-0.31305870413780001,-0.29194992780684997,-0.26777690649032998,-0.23803579807281,-0.21255433559417999,-0.19628150761127,-0.18050853908062001,-0.16260972619056999,-0.14400495588779,-0.12386040389538,-0.10653917491436,-0.094847477972507005,-0.082369640469551003,-0.066774487495422002,-0.050123341381550002,-0.032083205878734998,-0.015981215983629001,-0.0040256967768073004,0.0086255203932524005,0.023854125291108998,0.039593815803527999,0.056117326021194,0.070005074143410007,0.079232707619666998,0.087413467466830999,0.095709204673767007,0.10344162583351001,0.11064930260181,0.11690279096365,0.12175895273685,0.12654592096806,0.13184078037739,0.13699042797089001,0.14190459251404,0.14630672335625,0.14997835457325001,0.15335240960120999,0.15661345422268,0.15951955318451,0.16209769248962,0.16393457353115001,0.16475863754749001,0.16507804393768,0.1650156378746,0.16471017897129001,0.16429473459721,0.16356937587261,0.16306225955486001,0.16005413234234001,0.15247313678265001,0.14514291286469,0.13981303572654999,0.13569425046444,0.13275508582591999,0.13121294975281,0.13170237839221999,0.13174563646317,0.13020738959312,0.12812228500843001,0.12571880221366999,0.12292595952749,0.11971902102232,0.11625719815493001,0.11242537200451,0.10900823026896,0.10635141283273999,0.10430956631898999,0.10316197574138999,0.10169138759375,0.099247619509697002,0.096637122333049996,0.093905091285705997,0.091815099120140006,0.090803623199463002,0.090414471924305004,0.090243935585022,0.091567993164062,0.094963580369948994,0.10004007071257,0.10760946571827,0.11385910958051999,0.11641389131546,0.11902935057878,0.12306523323059,0.1277638822794,0.13320168852806,0.13874231278895999,0.14371031522750999,0.14986203610897,0.15798081457615001,0.16748440265656001,0.17820315063,0.1904358714819,0.20465329289435999,0.21928308904171001,0.23370052874087999,0.24793890118598999,0.26178255677223,0.27568835020065002,0.29000902175902998,0.30394133925437999,0.31698906421660999,0.32998239994049,0.34303960204124001,0.35687470436096003,0.37239295244217002,0.38726192712784002,0.40010878443718001,0.41290283203125,0.42607805132866,0.44053462147713002,0.45773148536682001,0.47367385029793002,0.48570284247397999,0.49828845262527,0.51304948329926003,0.52982580661774004,0.55002027750015003,0.56887078285216996,0.58354955911635997,0.59754669666289995,0.61208933591842996,0.62663567066193004,0.64190775156020996,0.65486681461333995,0.66293215751648005,0.67128187417983998,0.68244773149490001,0.69420385360717995,0.70684647560119995,0.71683055162429998,0.72063404321670999,0.72578191757202004,0.73613357543945002,0.74810427427292003,0.76168197393417003,0.77301907539367998,0.77938288450241,0.78408235311508001,0.78838688135146995,0.79150432348250999,0.79340565204619995,0.79367452859878995,0.79154866933822998,0.78922718763350996,0.78805577754973999,0.78645038604735995,0.78386908769607999,0.78040134906768999,0.77565872669220004,0.77091228961945002,0.76700460910796997,0.76284480094910001,0.75798928737640003,0.75270366668701005,0.74728953838348,0.74070364236831998,0.73201024532318004,0.72302371263503995,0.7147022485733,0.70624965429305997,0.69876855611801003,0.68704926967621005,0.66627246141434004,0.64551520347595004,0.62923848628998003,0.61464577913284002,0.60176777839661,0.58849865198134999,0.57277250289917003,0.55830156803131004,0.54744082689285001,0.53703355789185003,0.52675873041152999,0.51325094699859997,0.49252313375473,0.47269785404205,0.45872995257378002,0.44511842727661,0.43054577708244002,0.41273647546768,0.38761544227599998,0.36493393778800998,0.35111871361732,0.33861127495766002,0.32481563091277998,0.30918118357657998,0.28889384865760998,0.27131348848343001,0.26186555624008001,0.25310334563254999,0.24190808832645,0.22893750667571999,0.21238224208355,0.19784398376942,0.19014228880405001,0.18145790696144001,0.16770794987679,0.15167261660098999,0.1321092247963,0.11615256965159999,0.10966017842292999,0.10492213070393,0.098325289785861997,0.091853089630603998,0.085307523608207994,0.080593645572662007,0.079523593187332001,0.079294554889202007,0.078609541058539997,0.077791921794415006,0.076702512800693998,0.075435817241669006,0.073981180787086001,0.07246121764183,0.070895530283450997,0.069467321038246002,0.068228483200073006,0.067405328154564001,0.067208997905254003,0.067398682236671004,0.067674584686755995,0.068791210651397997,0.071192577481270003,0.074643321335315996,0.078790284693240994,0.084804765880108005,0.094055071473122004,0.10383708029985,0.1127984970808,0.12105699628592,0.12781347334384999,0.13506306707859,0.14452767372131001,0.15370620787143999,0.16120855510234999,0.16797550022602001,0.17356805503368,0.18047283589839999,0.19119749963284,0.20189253985882,0.21031725406647001,0.21807116270065,0.22522756457328999,0.23316729068756001,0.24333013594151001,0.25373762845992998,0.26324996352196001,0.27272525429726002,0.28219488263129999,0.2925109565258,0.30544066429138,0.31665164232254001,0.32285246253013999,0.32742053270339999,0.33165717124938998,0.33576694130897999,0.34070909023285001,0.34469628334044999,0.34624296426772999,0.34733843803406,0.34889781475067,0.35095268487929998,0.35356408357620001,0.35740339756012002,0.36350604891777,0.36984476447105002,0.37525764107704002,0.38005626201629999,0.38518619537353999,0.38702630996704002,0.38190510869026001,0.37504819035530002,0.36938858032227001,0.36363717913628002,0.35774901509285001,0.35146343708038003,0.34425154328346003,0.33729842305183,0.33150133490562,0.32607129216193997,0.32108417153357999,0.31521421670914002,0.30690029263495999,0.29846981167793002,0.29158449172973999,0.28464046120643999,0.27716392278670998,0.26845970749855003,0.25745785236358998,0.24575783312321001,0.23473419249058,0.2225431650877,0.20865124464035001,0.19169045984745001,0.16857728362082999,0.14607422053814001,0.12923517823219,0.11431875824928001,0.099837534129620001,0.086374923586844995,0.073876738548279003,0.062607660889625993,0.05356839671731,0.043966922909021003,0.031837940216064002,0.017948597669601,0.0013113096356392,-0.014642272144556,-0.026307297870516999,-0.038350775837897998,-0.053667247295379999,-0.070682875812054,-0.090186133980750996,-0.10828942805529,-0.12095504999161,-0.13287624716759,-0.14699433743953999,-0.16137759387493,-0.17607034742832001,-0.18882341682911,-0.19721969962120001,-0.20378609001636999,-0.2097078114748,-0.21511164307594,-0.22027833759785001,-0.22565823793411,-0.23069983720779,-0.23861086368560999,-0.25331383943558,-0.26935699582099998,-0.28395730257034002,-0.29622480273246998,-0.30379715561866999,-0.30968493223190002,-0.31590265035629,-0.32124397158623003,-0.32533884048461997,-0.32819625735282998,-0.32899332046509,-0.33011204004287997,-0.33404988050460999,-0.33792564272880998,-0.34010598063469,-0.34089002013205999,-0.33975118398665999,-0.33766680955887002,-0.33503279089928001,-0.3325722515583,-0.33098828792571999,-0.33021023869513999,-0.32974120974540999,-0.33166506886482,-0.33950665593147,-0.34676739573478998,-0.34835046529769997,-0.34720182418822998,-0.34431847929955001,-0.33939501643181003,-0.33172386884688998,-0.32371193170547002,-0.31738457083701999,-0.31183880567550998,-0.30688697099686002,-0.30265432596206998,-0.29914316534995999,-0.29649946093558999,-0.29486677050590998,-0.29417046904563998,-0.29426482319831998,-0.29555535316467002,-0.29936844110489003,-0.30240923166275002,-0.30144527554512002,-0.29928830265999001,-0.29753223061562001,-0.29554650187491999,-0.29343652725219999,-0.29068315029143998,-0.28662610054016002,-0.28207036852836997,-0.27748084068298001,-0.27291804552077997,-0.26781433820723999,-0.26456168293952997,-0.26581740379333002,-0.26910376548767001,-0.27300423383713002,-0.27780139446259,-0.28349107503891002,-0.28951302170753002,-0.29546478390693998,-0.30108594894409002,-0.30596882104874001,-0.31030076742172003,-0.31406298279762002,-0.31743913888931002,-0.32092157006263999,-0.32345706224442,-0.32359230518340998,-0.32343629002571,-0.32397323846817,-0.32655730843544001,-0.33365049958228998,-0.34227672219276001,-0.35022979974746998,-0.35847386717795998,-0.36709490418433999,-0.37639024853705999,-0.38715463876723999,-0.39783912897110002,-0.40691006183624001,-0.41554471850394997,-0.42441952228545998,-0.43326929211616999,-0.44261053204535999,-0.45075845718384,-0.45545202493668002,-0.45939823985099998,-0.46467348933219998,-0.47036263346672003,-0.47654700279236001,-0.48239409923553001,-0.48631292581558,-0.49088856577873002,-0.49849772453308,-0.50769639015197998,-0.51829648017883001,-0.52905589342116999,-0.53893274068831998,-0.54735666513443004,-0.55309563875197998,-0.55724245309830001,-0.56061333417892001,-0.56267458200455001,-0.56299811601639005,-0.56213849782944003,-0.56041997671126997,-0.55804920196533003,-0.55522519350052002,-0.55226695537567005,-0.54908555746078003,-0.54707884788512995,-0.54824382066726995,-0.55056023597716996,-0.55280601978302002,-0.55470001697539995,-0.55613839626312001,-0.55539286136626997,-0.54963713884354004,-0.54215300083160001,-0.53545773029327004,-0.52892374992371005,-0.54884797334670998,-0.51697880029678001,-0.48507726192473999,-0.47360724210739003,-0.45958003401755998,-0.44931855797768,-0.43915840983391002,-0.42667308449745001,-0.41443070769309998,-0.40475535392760997,-0.39602538943290999,-0.38832947611808999,-0.37883210182190002,-0.36289441585540999,-0.34579956531525002,-0.33249932527541998,-0.31968867778777998,-0.30658921599388,-0.29041934013366999,-0.26530510187148998,-0.23933956027031,-0.22070235013962,-0.20411045849323001,-0.1871677339077,-0.16897675395011999,-0.14562775194645,-0.1234440729022,-0.10977017879485999,-0.098597250878810994,-0.085958853363991006,-0.072326317429542999,-0.055700272321701001,-0.039368826895952003,-0.027719784528016999,-0.016123281791805999,-0.00088102836161852002,0.017210872843862,0.040588699281216001,0.063413359224796004,0.077925443649292006,0.090854801237582994,0.1075834184885,0.12573702633381001,0.14578145742415999,0.16436712443828999,0.17651152610779,0.18651258945464999,0.19775481522082999,0.20898984372616,0.22037020325661,0.23096004128455999,0.23904551565647,0.24674142897129001,0.25618565082549999,0.26623511314392001,0.27652573585509999,0.28663653135299999,0.29544645547866999,0.30444470047951,0.31562456488608998,0.32691979408263999,0.33687788248062001,0.34501111507415999,0.34978225827217002,0.35248562693595997,0.35386073589325001,0.35442653298378002,0.35515323281288003,0.35575059056281999,0.35631769895554,0.35663476586342002,0.35615974664687999,0.35581976175308,0.35664656758308,0.35820892453193998,0.36052450537682001,0.36319488286972001,0.36589115858077997,0.36823299527168002,0.36961048841476002,0.37012892961501997,0.37007227540016002,0.36833763122558999,0.36265400052071001,0.35603660345077998,0.35180389881134,0.34836274385451999,0.34559842944144997,0.34195992350577997,0.33421742916107,0.32608249783516002,0.32154461741446999,0.31859275698661998,0.31634983420371998,0.31466212868690002,0.31291717290878002,0.31136909127235002,0.31022900342941001,0.30912074446678001,0.30763545632361999,0.30584341287612998,0.30409806966781999,0.30121085047722002,0.29521164298058,0.28785055875777998,0.28060507774353,0.27333405613898998,0.26591157913208002,0.25979560613632002,0.25736925005912997,0.25698703527451,0.25738573074340998,0.25886550545692,0.26180610060692,0.26484131813049,0.26578041911125,0.26626446843147,0.26778870820999001,0.26966154575348,0.27194797992705999,0.27362862229347001,0.27278918027878002,0.27114239335059998,0.27032738924026001,0.26987588405608998,0.26965731382370001,0.27013918757438998,0.27202266454696999,0.27492833137512002,0.27859786152839999,0.28313711285590998,0.28861942887306002,0.29494491219521002,0.30223476886749001,0.30987280607223999,0.31698983907700001,0.32384479045867998,0.33045154809951999,0.33676114678383001,0.34274578094482,0.34831431508063998,0.35316234827041998,0.35775199532509,0.36268171668053001,0.36769488453865001,0.37281915545464001,0.37769106030464,0.38126572966576,0.38505721092223999,0.39099848270415999,0.39834108948708002,0.40731918811798001,0.41664919257164001,0.42424449324607999,0.43119049072266002,0.43827039003371998,0.44512832164763999,0.45194640755652998,0.45775923132896001,0.46054255962371998,0.46229103207588002,0.46537473797798001,0.46873593330383001,0.47199705243111001,0.47479403018951,0.47613742947578003,0.47687128186226002,0.47792309522629001,0.47893264889717002,0.47980704903603,0.48045083880424,0.48021841049193997,0.48036250472068998,0.48311984539031999,0.48664882779120999,0.48933833837509,0.49085614085196999,0.48953068256378002,0.48669642210007003,0.48363524675369002,0.48025318980217002,0.47703176736831998,0.47377336025237998,0.47041949629784002,0.46690136194228998,0.46301651000977001,0.45896425843239003,0.45501038432120999,0.45101031661034002,0.44698381423950001,0.44260734319687001,0.43712586164473999,0.43126404285431003,0.42590963840485002,0.42075672745705001,0.41602861881255998,0.41092947125434998,0.40380385518074002,0.39605709910393,0.38945114612579002,0.38313156366348,0.37655597925186002,0.36970680952071999,0.36198669672012002,0.35426869988441001,0.34803614020348,0.34227842092513999,0.33605650067329002,0.32940489053726002,0.32146373391151001,0.31353268027306003,0.30783677101134999,0.30292832851410001,0.29750195145607,0.29156020283699002,0.28358432650566001,0.27601391077041998,0.27303582429885997,0.27214699983597002,0.27102330327034002,0.27012690901755998,0.27006226778030001,0.26854294538498003,0.26128900051116999,0.2504703104496,0.23772357404232,0.22295108437538,0.20431596040725999,0.18795314431189999,0.18594671785830999,0.19101583957672,0.19601504504681,0.20256926119328,0.21043640375136999,0.21888920664787001,0.22650699317455,0.23349875211716001,0.23977565765381001,0.24479964375495999,0.24836468696594,0.24860057234763999,0.24114736914634999,0.22882916033268,0.21365742385386999,0.19753095507622001,0.18404272198676999,0.17455588281154999,0.17461243271828,0.18031454086304,0.1872219145298,0.19620302319527,0.20656470954417999,0.21866807341576,0.23344454169272999,0.24928215146065,0.26487782597541998,0.27758610248566001,0.28189566731452997,0.27854856848717002,0.26489207148552002,0.24432122707366999,0.2198907583952,0.19568486511707001,0.18151059746741999,0.1744622439146,0.17473481595515999,0.18056687712669001,0.18877319991589001,0.19979520142078,0.21301159262656999,0.22818556427955999,0.24508231878281,0.26247730851173001,0.28061300516129001,0.29318732023239003,0.28586044907570002,0.26607865095138999,0.23991957306862,0.20891617238522001,0.17819750308990001,0.14903888106346,0.12731286883354001,0.11046701669693,0.096236988902091994,0.085603415966034005,0.077903106808661998,0.076575390994549006,0.090533010661602006,0.11287160217762,0.13453340530395999,0.15664665400982,0.18227079510689001,0.19860348105431,0.17442508041859001,0.13033539056778001,0.092372372746468007,0.055183529853821002,0.020943356677890001,-0.0098596327006817003,-0.034592077136039998,-0.054486364126205,-0.070786230266094,-0.083056800067424996,-0.092380359768866993,-0.095590919256209994,-0.083726167678832994,-0.064842648804187997,-0.051019668579102,-0.040282435715199003,-0.032342612743377998,-0.032805770635604997,-0.057800881564616997,-0.094942003488540996,-0.12547129392624001,-0.15497326850890999,-0.18483360111712999,-0.21606108546257,-0.25422444939612998,-0.29229563474655001,-0.31724622845650002,-0.33327597379683999,-0.34321916103362998,-0.34496045112610002,-0.33222565054893,-0.31291174888611001,-0.30114379525184998,-0.29392671585083002,-0.29197525978088001,-0.29592710733414002,-0.30904620885848999,-0.32778447866440003,-0.34514641761780002,-0.36433190107345997,-0.38867825269699002,-0.41756236553192,-0.45570313930511003,-0.49297347664833002,-0.50671243667603005,-0.50625228881836004,-0.50009179115294999,-0.48700714111327997,-0.46616256237030002,-0.44325917959213001,-0.43248265981674,-0.42796456813812001,-0.42383980751037997,-0.42174679040909002,-0.42163670063018999,-0.42491707205772,-0.43493458628654003,-0.45076799392700001,-0.47337275743483997,-0.49998775124549999,-0.52635192871094005,-0.54977947473526001,-0.56062054634094005,-0.56259500980376997,-0.55831521749496005,-0.54878473281859996,-0.53781408071518,-0.52466160058974998,-0.51034754514694003,-0.49341180920601002,-0.46862128376960999,-0.44180089235306003,-0.42342281341553001,-0.41281917691231002,-0.41467696428299,-0.42737513780594,-0.45291143655777,-0.48435288667679,-0.50570988655089999,-0.52035766839981001,-0.52722001075744995,-0.52690690755844005,-0.51920348405838002,-0.50613492727279996,-0.49269893765450001,-0.47776100039482,-0.46149921417236001,-0.44363912940025002,-0.42122098803519997,-0.39972251653670998,-0.39212468266486999,-0.39420080184937001,-0.40292620658875,-0.41857868432999001,-0.44308596849442,-0.47027888894080999,-0.48428940773009999,-0.49047726392745999,-0.49304178357124001,-0.49176946282387002,-0.48840412497520003,-0.48267364501952997,-0.47469103336334001,-0.46492806077003002,-0.45457789301871998,-0.44366112351418002,-0.43144592642784002,-0.42105096578598,-0.42147982120513999,-0.42864027619362,-0.43703553080558999,-0.44771325588226002,-0.46102234721183999,-0.47541549801826,-0.48656284809112998,-0.49596139788628002,-0.5050602555275,-0.51355636119842996,-0.52258950471877996,-0.52971482276917004,-0.52767121791839999,-0.52042257785796997,-0.51438224315643,-0.50841569900512995,-0.50189524888991999,-0.49750721454620001,-0.50381600856780995,-0.51633548736571999,-0.52789556980133001,-0.53972309827804998,-0.55131310224533003,-0.56208997964858998,-0.56976556777954002,-0.57533687353134,-0.58011931180954002,-0.58402425050734996,-0.58759689331054998,-0.59070163965224998,-0.59327715635300005,-0.59538328647614003,-0.59691244363785001,-0.59835940599441995,-0.60083359479903997,-0.60458987951278997,-0.61177837848662997,-0.62059795856475997,-0.62708622217178001,-0.63215434551239003,-0.63606899976730003,-0.63869839906693004,-0.63967841863632002,-0.63926148414612005,-0.63732373714446999,-0.63510066270828003,-0.63619667291641002,-0.63986903429030995,-0.64704519510268999,-0.65589022636413996,-0.66102236509322998,-0.66444510221481001,-0.66892123222350997,-0.67372149229050005,-0.67871242761612005,-0.68317604064940995,-0.68452697992324996,-0.68391674757003995,-0.68324238061904996,-0.68210935592651001,-0.68054682016373003,-0.67841619253159002,-0.67464298009872004,-0.67070335149765004,-0.67090088129044001,-0.67366290092467995,-0.67709726095199996,-0.68105137348175004,-0.68331229686737005,-0.68537038564681996,-0.69108414649963001,-0.69860953092574996,-0.70485180616378995,-0.70985758304596003,-0.71210289001464999,-0.71139830350875999,-0.70532977581024003,-0.69577270746231001,-0.68706572055816995,-0.67858129739760997,-0.67044258117676003,-0.66374182701110995,-0.66294109821320002,-0.66581094264983998,-0.66798490285873002,-0.67026704549788996,-0.67224407196045,-0.67448967695235995,-0.67917901277542003,-0.68480342626571999,-0.68776339292526001,-0.68875312805176003,-0.68838667869568004,-0.68544369935989002,-0.67485362291336004,-0.65991872549056996,-0.64864689111710006,-0.63916963338851995,-0.63048315048217995,-0.62254428863525002,-0.61427754163741999,-0.60657173395157005,-0.60204637050628995,-0.59968423843384,-0.59777265787125,-0.59651052951812999,-0.59615391492844005,-0.59550178050994995,-0.59043329954146995,-0.58186799287795998,-0.57044118642806996,-0.55575340986251998,-0.53537929058074996,-0.51214379072188998,-0.49528932571411,-0.48159798979759,-0.46590653061866999,-0.44897198677062999,-0.42880889773369002,-0.40814581513405002,-0.39646464586258001,-0.39012888073920998,-0.38239470124245001,-0.37445205450058,-0.36660715937614002,-0.35816624760628002,-0.34664481878281,-0.33257511258125,-0.3161219060421,-0.29743438959121998,-0.27696302533150002,-0.25490725040436002,-0.23251017928123,-0.20921732485294001,-0.18332710862160001,-0.15596826374531,-0.12918217480183,-0.10435318946838,-0.089143395423888994,-0.080370187759398998,-0.071478419005871,-0.063291385769844,-0.054800916463136999,-0.045842014253139003,-0.034785311669111002,-0.022225487977265999,-0.0094238752499222998,0.0040364619344472998,0.018786460161208999,0.034951955080032002,0.053765922784804999,0.074468344449997004,0.095271080732345997,0.11596645414829,0.13455428183078999,0.15133421123028001,0.16624911129475001,0.17901362478732999,0.18792378902435,0.19406703114509999,0.20058637857437001,0.20696093142033001,0.21347787976265001,0.21972982585430001,0.22368234395980999,0.22673192620277,0.23332303762435999,0.24239601194859001,0.25309395790099998,0.26492762565612998,0.27537813782692,0.28487139940262002,0.29335656762123002,0.30087751150130998,0.30762737989425998,0.31341329216956998,0.31768235564232,0.32033914327620999,0.32036128640174999,0.31828859448433,0.31558820605277998,0.31213691830634999,0.30782759189606002,0.30361878871918002,0.30402451753616,0.30757752060889998,0.31129720807076,0.31549990177155002,0.31924694776535001,0.32312878966330999,0.32936242222786,0.33699053525924999,0.34343266487121998,0.34904417395592002,0.35401976108550998,0.35766616463661,0.35641855001450001,0.35174027085303999,0.34750804305076999,0.34320828318595997,0.33840572834014998,0.33445632457732999,0.33824557065964,0.34714785218239003,0.35409793257713001,0.36044210195540999,0.36688509583473,0.37403151392937001,0.38574734330177002,0.40029764175415,0.41242194175719998,0.42307385802268999,0.43291583657264998,0.44188278913498003,0.45003706216812001,0.45735439658165,0.46349868178367998,0.46893626451491999,0.47531703114509999,0.48283919692039001,0.49431499838829002,0.50832426548003995,0.51962274312973,0.52984154224395996,0.54275989532471003,0.55820953845978005,0.57925194501876998,0.60363930463791005,0.62226223945617998,0.63726019859313998,0.65238934755324995,0.66718751192092995,0.68234139680862005,0.69714206457137995,0.70799028873444003,0.71640700101851995,0.72739094495773005,0.74010872840881003,0.75450146198273005,0.76986259222030995,0.78180575370788996,0.79226124286652,0.80815953016280995,0.82793813943863004,0.84974664449691995,0.87233150005340998,0.88705819845199996,0.89656209945679,0.90821087360382002,0.92061644792556996,0.93212276697159002,0.94256085157393998,0.94953799247741999,0.95403546094893998,0.95955216884613004,0.96536993980408004,0.97040182352065996,0.97458225488662997,0.97626715898514005,0.97647196054458996,0.97983872890472001,0.98510432243347001,0.98905718326569003,0.99192130565643,0.99242562055588002,0.99099975824356001,0.98898702859878995,0.98614448308945002,0.98210912942885997,0.97693264484405995,0.97063457965850997,0.96325260400771995,0.95503246784210005,0.94590079784393,0.93563127517699995,0.92425334453582997,0.91167521476746005,0.89803129434586004,0.88395899534224998,0.86944246292114002,0.85488516092300004,0.84022367000580001,0.82538330554962003,0.81042307615279996,0.79583299160003995,0.78130203485489003,0.76531219482421997,0.74815022945403997,0.73033547401428001,0.71182453632355003,0.69268035888671997,0.67293846607207997,0.65280812978744995,0.63234895467758001,0.61210119724274004,0.59197556972503995,0.57188367843627996,0.55180174112320002,0.53143370151519997,0.51094305515288996,0.49115076661110002,0.47189649939536998,0.45258066058159002,0.43357279896736001,0.41696694493294001,0.40222170948982,0.38756212592125,0.37319380044937001,0.35917103290558,0.34539529681205999,0.33120894432067999,0.31670877337455999,0.30196550488472002,0.28701147437095997,0.27201956510544001,0.25705504417419001,0.24261589348316001,0.22872331738471999,0.21592400968075001,0.20414441823959001,0.19315379858017001,0.18321245908736999,0.17617069184779999,0.17148360610008001,0.16699573397636,0.16290116310120001,0.15887066721915999,0.15493519604205999,0.15105411410332001,0.14713278412819,0.14232344925404,0.13689723610877999,0.13197843730450001,0.12752883136272,0.12431224435568,0.12205540388823,0.11934296041726999,0.11649747192859999,0.11465095728636,0.11373694986105,0.11427260190247999,0.11604883521794999,0.11796817183494999,0.12020229548215999,0.12312053143978,0.12669916450977001,0.13127936422825001,0.13653507828712,0.14029541611671001,0.14284789562225,0.14452952146529999,0.14536932110785999,0.14579801261424999,0.14574573934078,0.14487254619598,0.14340168237685999,0.14284209907055001,0.14296706020832001,0.14329470694065,0.1438249796629,0.14410953223705,0.1443163305521,0.14547976851462999,0.14738468825817,0.14927610754967,0.15110714733600999,0.15226627886294999,0.15245176851749001,0.14825950562953999,0.14050194621086001,0.13274984061718001,0.12484523653984,0.11870268732309,0.11371577531099,0.10622970759869001,0.096987269818783001,0.089197203516960005,0.082586519420146998,0.077933833003044004,0.074590802192688002,0.067311361432076,0.057129286229609999,0.048584945499897003,0.041227448731661002,0.035323224961758,0.030247043818234998,0.020288949832320002,0.0066473502665758003,-0.0046986313536763,-0.014491467736661,-0.023864358663559002,-0.033401794731617002,-0.050196155905724002,-0.072473637759686002,-0.089894205331801993,-0.1036691069603,-0.1161031126976,-0.12735220789908999,-0.1408524364233,-0.15582337975502,-0.16762234270573001,-0.17699511349201,-0.18682445585728,-0.19720344245433999,-0.21204552054404999,-0.23026895523071,-0.24437506496906,-0.25553020834923001,-0.26855000853539002,-0.28330379724503002,-0.30353012681007002,-0.32775974273682001,-0.34406307339668002,-0.35416036844254001,-0.36515030264853998,-0.37652748823165999,-0.38922473788260997,-0.40270513296126997,-0.41208454966545,-0.41821312904357999,-0.42577606439589999,-0.43435168266295998,-0.4435758292675,-0.45327174663544001,-0.46122509241103998,-0.46782913804053999,-0.47544652223586997,-0.48381447792053001,-0.49222066998482,-0.50056344270705999,-0.50707882642746005,-0.51203083992003995,-0.51680159568786999,-0.52126008272170998,-0.52518618106841997,-0.52849000692367998,-0.52997577190399003,-0.52977865934372004,-0.52821493148804,-0.52540552616118996,-0.52285718917847002,-0.52054196596145996,-0.51961189508437999,-0.51986056566238004,-0.51996588706970004,-0.52000129222869995,-0.51979792118072998,-0.51932847499847001,-0.51807320117949995,-0.51605123281479004,-0.51299840211867997,-0.50895541906357,-0.50415927171706998,-0.49859723448753002,-0.49237778782844999,-0.48543548583983998,-0.47675848007201999,-0.46663299202919001,-0.45788189768790999,-0.45029145479201999,-0.44358092546463002,-0.43772757053375,-0.43226814270019998,-0.42727810144424,-0.42340657114982999,-0.42056792974472001,-0.41821151971817,-0.41633099317550998,-0.41465356945991999,-0.41300398111343001,-0.40846192836761003,-0.40135824680328003,-0.39358115196228,-0.38511863350867998,-0.37742325663567,-0.37034228444098999,-0.36300361156464001,-0.35549435019492998,-0.34831997752190003,-0.34150266647339,-0.33560752868652,-0.33071976900101002,-0.32888787984848,-0.32984682917594998,-0.33148065209388999,-0.33386039733887002,-0.33648592233657998,-0.33926597237586997,-0.33997046947478998,-0.33886229991912997,-0.33809912204741999,-0.33757084608077997,-0.33736404776572998,-0.33743926882744002,-0.33730190992355003,-0.33699762821197998,-0.33681604266166998,-0.33676746487616999,-0.33701410889625999,-0.33769536018371998,-0.34176775813103,-0.34886905550956998,-0.35524091124535001,-0.36109930276871,-0.36701786518097002,-0.37299650907516002,-0.37941870093345997,-0.38622599840164001,-0.39269310235977001,-0.39885735511780002,-0.40473830699920998,-0.41036137938499001,-0.41631931066513,-0.42251878976821999,-0.42753931879996998,-0.43151134252548001,-0.43571576476097001,-0.4401273727417,-0.44546711444854997,-0.45163580775260997,-0.45713698863982999,-0.46211859583854997,-0.46833604574203003,-0.47574058175086997,-0.48533800244330999,-0.49683624505996998,-0.50463038682938,-0.50902485847473,-0.51168674230575995,-0.51257556676865001,-0.51178652048110995,-0.50940030813216997,-0.50740116834641003,-0.50575774908065996,-0.50564885139464999,-0.50700724124908003,-0.50963217020035001,-0.51343441009520996,-0.51585501432419001,-0.51706546545028997,-0.51916313171386996,-0.52204138040543002,-0.52497601509094005,-0.52787435054778997,-0.52756494283676003,-0.52418452501296997,-0.51831132173537997,-0.50999921560286998,-0.50099575519562001,-0.4912970662117,-0.48266428709030001,-0.47497612237929998,-0.46625712513924,-0.45660600066184998,-0.44723173975945002,-0.43813157081603998,-0.43033534288406,-0.42378568649291998,-0.41774871945380998,-0.41221442818642001,-0.40625062584876998,-0.39986976981163003,-0.39286357164383001,-0.38514423370361001,-0.37274757027625999,-0.35592862963675997,-0.34038770198821999,-0.32598480582236999,-0.31296443939209001,-0.30120539665222001,-0.28593274950981001,-0.26739826798438998,-0.25155389308928999,-0.23825013637542999,-0.22692492604256001,-0.21748143434525,-0.20499938726424999,-0.18967694044113001,-0.17611740529537001,-0.16419643163681,-0.15224060416221999,-0.14022688567638,-0.12517261505127,-0.10722894966601999,-0.091686703264712996,-0.078410260379314006,-0.065009824931621996,-0.051478855311870998,-0.034808613359927999,-0.015159234404563999,0.00022727064788341999,0.011517838574946,0.022610364481807001,0.033477470278739999,0.045976832509040999,0.060024153441190997,0.071095183491707001,0.079289987683295995,0.088201120495795995,0.097794033586978996,0.10869139432907,0.12085056304932,0.13086465001106001,0.13879972696303999,0.14802087843417999,0.15849451720714999,0.16995082795620001,0.18236581981182001,0.1925001591444,0.20039364695549,0.20822437107562999,0.21597653627395999,0.22326689958571999,0.23009242117404999,0.23549205064774001,0.23947802186011999,0.24374112486839,0.24827232956886,0.25252526998519997,0.25649785995482999,0.25870752334594999,0.25916150212288003,0.25974720716476002,0.26046174764633001,0.26132881641388001,0.26234835386276001,0.26335582137107999,0.26435124874115001,0.26534670591353998,0.26634213328362,0.26735025644302002,0.26837149262428001,0.26925203204155002,0.26999178528786,0.27049073576927002,0.27074798941611999,0.27086421847343001,0.27083900570869002,0.27089592814445002,0.27104151248932001,0.27026376128196999,0.26854777336121,0.26718625426291998,0.26618850231170998,0.26549196243286,0.26510098576545998,0.26438152790070002,0.26330852508545,0.26402065157889998,0.26654419302940002,0.27049332857132002,0.27589601278304998,0.27989700436592002,0.28244674205780002,0.28497043251991,0.28748452663421997,0.28987151384353999,0.29213616251945002,0.29366001486777998,0.29438775777817,0.29774725437164001,0.30382710695267001,0.31022751331329002,0.31693717837334001,0.32221746444701999,0.32595545053482,0.33325117826461997,0.34426832199097002,0.35479125380516002,0.36477616429329002,0.37246260046959001,0.37772190570830999,0.38536891341209001,0.39557343721389998,0.40462395548820002,0.41245704889297002,0.41831216216087003,0.42203295230865001,0.43016314506531,0.44299677014351002,0.45406857132911999,0.46321755647659002,0.47097149491309998,0.47722479701041998,0.48671501874924,0.49970325827598999,0.51059687137604004,0.51923036575317005,0.52642309665679998,0.53209286928177002,0.53997677564621005,0.55030286312103005,0.55857330560684004,0.56461524963378995,0.57005625963211004,0.57487231492996005,0.58142125606536998,0.58988404273987005,0.59666299819946,0.60158503055572998,0.60666763782500999,0.61193233728409002,0.61879640817642001,0.62745922803878995,0.63329315185546997,0.63607048988341996,0.63795340061187999,0.63901519775391002,0.63883376121520996,0.63734203577042003,0.63624030351639005,0.63562411069869995,0.63458216190338002,0.63308119773865001,0.63115292787552002,0.62874966859818004,0.62721657752991,0.62667095661162997,0.62545096874237005,0.62348777055740001,0.62087678909302002,0.61758899688721003,0.61444300413132003,0.61155796051025002,0.60679006576537997,0.59999871253966996,0.59213227033615001,0.58306837081909002,0.57684069871902,0.57386034727097002,0.56884497404098999,0.56148701906204002,0.55349069833755005,0.54486423730849998,0.53700119256973,0.53014481067657004,0.52034217119216997,0.50724095106125,0.49425119161606001,0.48144966363906999,0.47073012590407998,0.46239113807678001,0.45238742232322998,0.44039297103882002,0.42893099784851002,0.41809085011482,0.40858095884322998,0.40059503912925998,0.3911826312542,0.38011234998702997,0.36878794431686002,0.35725423693656999,0.34601315855980003,0.33521783351897999,0.32246631383896002,0.30748549103737,0.29285866022110002,0.27874758839607,0.26476991176605003,0.25094586610794001,0.23662520945071999,0.22166647017002,0.20791302621364999,0.19551043212413999,0.18385013937950001,0.17291849851607999,0.16246673464774999,0.15246586501598,0.14309570193290999,0.13436748087406,0.1262039989233,0.11854996532202,0.11233565956354,0.10769575089216001,0.10340376943350001,0.099359795451163996,0.095904164016247004,0.093017332255839996,0.091375738382339006,0.091142982244491993,0.090446792542934001,0.089110128581524006,0.08789861947298,0.086839891970157998,0.086425773799419001,0.086990296840668002,0.083734430372714996,0.075985029339789997,0.068643048405647,0.062036029994487998,0.056098297238349998,0.050745740532874999,0.047786258161067997,0.047513850033282998,0.047683257609605997,0.048117745667695999,0.049035001546144,0.050398439168929998,0.052823957055807003,0.056463822722434998,0.059858039021491997,0.062895052134990997,0.065662898123263994,0.068282850086688995,0.068889603018761,0.067175857722758997,0.065271355211734994,0.063383549451828003,0.060949936509131997,0.058016233146190997,0.053401362150908002,0.046792633831501,0.040977586060762003,0.036210644990206001,0.032163400202990002,0.028817739337683002,0.026407122612000001,0.025022830814123001,0.023742103949188999,0.022475473582745001,0.021337371319531999,0.020329646766186,0.019514514133334,0.018989557400346,0.017601059749721999,0.015235831029712999,0.011982869356871,0.0078431963920593002,0.0026840777136384998,-0.0036274050362408001,-0.0095702726393937995,-0.014911551028490001,-0.020748794078827001,-0.027211098000407,-0.033870276063681003,-0.040748465806245998,-0.047053117305039999,-0.052465248852968001,-0.059879440814257001,-0.069745898246764998,-0.080198541283606997,-0.091269813477992998,-0.1006178483367,-0.10773999989032999,-0.11553636193275001,-0.12440352886915,-0.13296538591384999,-0.14121177792549,-0.14790207147598,-0.15275141596794001,-0.15733225643634999,-0.16177369654179,-0.16632315516471999,-0.17103829979897001,-0.17561991512774999,-0.17979018390179,-0.18644870817661,-0.19621501863002999,-0.20581766963004999,-0.21499547362328,-0.22285032272339,-0.22885543107986001,-0.23741018772125,-0.24945887923241,-0.26006826758384999,-0.26869693398476002,-0.27556332945824003,-0.28031879663467002,-0.28643563389777998,-0.29467844963074002,-0.30121314525603998,-0.30554693937302002,-0.30855494737625,-0.31017029285431003,-0.31168356537818998,-0.31332850456237998,-0.31432810425758001,-0.31454372406005998,-0.31456422805786,-0.31434321403503002,-0.31508037447928999,-0.31717067956924,-0.31818598508835,-0.31774929165839999,-0.31677886843681002,-0.31531536579132002,-0.31381204724312001,-0.31246367096901001,-0.30998432636260997,-0.30611798167228998,-0.30183172225951999,-0.29722228646277998,-0.29235211014748003,-0.28720864653587003,-0.28210499882697998,-0.27708745002746998,-0.27212625741959001,-0.26722383499146002,-0.26231035590172003,-0.25724208354950001,-0.25332891941071001,-0.25088945031165999,-0.24857772886752999,-0.24621668457984999,-0.24405162036419001,-0.24229373037815,-0.23907856643200001,-0.23397676646709001,-0.22858133912086001,-0.22307124733924999,-0.21753929555415999,-0.21204838156700001,-0.20635046064854001,-0.20039989054203,-0.19430242478848,-0.18799442052841001,-0.18204627931118,-0.17632219195366,-0.17281353473663,-0.17203781008720001,-0.17208282649517001,-0.17276442050933999,-0.17364692687988001,-0.17473061382770999,-0.17521685361861999,-0.17497430741787001,-0.17398722469806999,-0.17212675511837,-0.17029681801796001,-0.16854278743267001,-0.16765667498112,-0.16794490814209001,-0.16788493096828,-0.16702282428741,-0.16735477745533001,-0.16912740468979001,-0.17269912362098999,-0.17847323417663999,-0.18379923701286,-0.1880721449852,-0.19299812614917999,-0.19881422817707001,-0.20543719828129001,-0.21316868066788,-0.21957990527153001,-0.22397577762604001,-0.22891202569008001,-0.23483932018279999,-0.24105714261531999,-0.24764345586299999,-0.25331953167915,-0.25747245550156,-0.26332786679268,-0.27162045240402,-0.28057706356049,-0.29029536247253002,-0.29810187220572998,-0.30306619405745999,-0.30885028839111001,-0.31624129414558,-0.32341253757477001,-0.33025401830673001,-0.33567899465561002,-0.33903944492339999,-0.34375968575478,-0.35071697831153997,-0.35745510458946,-0.36369827389717002,-0.36870998144150002,-0.37164247035980003,-0.37780696153641002,-0.38885399699210998,-0.39911904931067999,-0.40770941972732999,-0.41475829482079002,-0.41995996236800998,-0.42495203018187999,-0.4301909506321,-0.43434774875641002,-0.43721306324004999,-0.43888080120086997,-0.43940085172652998,-0.4382406771183,-0.43495813012123002,-0.43207719922066001,-0.43011575937271002,-0.42853233218192999,-0.42726656794548001,-0.42649018764495999,-0.42629116773605003,-0.42623949050902998,-0.42630207538604997,-0.42620462179183999,-0.42599505186080999,-0.42485633492469999,-0.42246150970459001,-0.42001196742058,-0.41784039139748003,-0.41508734226227001,-0.41177636384964,-0.4066926240921,-0.39916241168976002,-0.39219921827316001,-0.3866326212883,-0.38051879405974998,-0.37367609143257002,-0.36514252424240001,-0.35411143302916998,-0.34463086724281,-0.33782842755317999,-0.33120876550674,-0.32442429661750999,-0.31716388463973999,-0.30908706784248002,-0.30181491374968999,-0.29607313871384,-0.28902691602706998,-0.28005871176719999,-0.26966306567192,-0.25735661387443998,-0.24665766954422,-0.23883260786533,-0.23020726442337,-0.21996225416660001,-0.2091411948204,-0.19751736521721,-0.18751135468482999,-0.18019761145115001,-0.17188058793545,-0.16161209344864,-0.15100303292274,-0.14012554287910001,-0.13014850020409,-0.12177941203117,-0.11218978464602999,-0.1004965826869,-0.088747233152389998,-0.077139385044575001,-0.066751673817634999,-0.058177754282951001,-0.04940552636981,-0.039895720779895998,-0.030569538474082999,-0.021539963781833999,-0.013021841645241001,-0.0052096676081419,0.0027039945125579999,0.010935294441879,0.019181918352842001,0.027416983619332001,0.035544637590647001,0.043537329882383,0.051395107060670998,0.059112090617417998,0.066695168614387998,0.074122458696364996,0.081535197794437006,0.088968843221663998,0.096394777297973994,0.10377208888531,0.11133617907762999,0.11912164837122,0.12726229429245001,0.13589397072792,0.14441926777363001,0.15265817940234999,0.16090920567513001,0.16927993297576999,0.17743416130542999,0.18536499142647,0.19267152249812999,0.19916240870953,0.20534653961658,0.21129678189754,0.21721279621124001,0.22322256863116999,0.22892454266548001,0.23412489891051999,0.23946885764598999,0.24516747891903001,0.25082382559776001,0.25640797615050998,0.26163890957831998,0.26631417870522001,0.27116629481316001,0.27646613121032998,0.28160345554352001,0.28640875220299,0.29114189743996,0.29584231972693997,0.30054637789726002,0.30529010295867998,0.30995643138884998,0.31450340151786998,0.31898537278174999,0.32321846485138001,0.32833990454674,0.33486485481262002,0.34150832891464,0.34797537326812999,0.35435199737549,0.36067396402358998,0.36661264300346003,0.37205970287322998,0.37712752819061002,0.38181903958321001,0.38621219992638001,0.39038825035094998,0.39399585127830999,0.39678257703781,0.39967596530914001,0.40301191806793002,0.40621683001518,0.40927496552467002,0.41159814596175998,0.41272646188736001,0.41428923606873003,0.41711837053299,0.41889694333076,0.41912889480590998,0.41740682721138,0.41296628117561002,0.40888008475304,0.40597254037857,0.40411534905433999,0.4034132361412,0.40385794639587003,0.40579909086227001,0.40742948651313998,0.40825429558754001,0.40827172994614003,0.40739667415619002,0.40561717748642001,0.40267074108124001,0.39989739656447998,0.39791241288184998,0.39541137218474998,0.39198195934295998,0.38819015026093001,0.38416084647179,0.37989851832389998,0.37606823444366,0.36918741464615001,0.35752415657043002,0.34489715099335,0.33179667592049,0.32055699825286998,0.31232097744942,0.30546766519546997,0.29979860782623002,0.29462522268294999,0.28969642519951,0.28505522012710999,0.28121209144592002,0.27530887722969,0.26585561037063998,0.25614002346991999,0.24688379466534,0.23866261541843001,0.23199923336506001,0.22582806646824,0.21998465061187999,0.21396249532700001,0.20761644840240001,0.20074236392975001,0.19374288618565,0.1839716732502,0.16942241787910001,0.15609902143477999,0.14599403738976,0.13759878277779,0.13085386157036,0.12521858513355,0.1207028105855,0.11627788096666,0.11154922097921,0.10673239827156,0.10186160355806,0.096782654523849002,0.091304585337638994,0.086146697401999997,0.081619523465633004,0.077267356216908001,0.072998277842999004,0.068738117814063998,0.064386777579784005,0.060239829123019999,0.056495662778616,0.052614472806454003,0.048474669456482003,0.043856255710124997,0.038214419037104,0.033750317990780002,0.031562708318232997,0.029694497585296999,0.027602985501289,0.025431867688894001,0.023128682747483,0.020748078823089999,0.018442980945109998,0.015528779476880999,0.011763485148549,0.0071484940126537999,0.00075273960828780998,-0.0031120302155613999,-0.0022341811563819998,-0.00034266320290043999,0.0014692577533424,0.0037292449269444002,0.0068497695028782004,0.0088670970872044997,0.0089441137388348996,0.0078798886388540008,0.0056011546403169996,0.0031258750241249999,0.00047589279711246003,-0.00065776403062045997,0.00089250435121356996,0.0027006356976926001,0.0040402426384389001,0.0049643320962787004,0.0054225600324571003,0.0051285657100378999,0.0039844606071711003,0.0018598393071443001,-0.0016420199535786999,-0.0050205914303660002,-0.0079324319958687002,-0.0095648150891065997,-0.0091380914673209,-0.0084652267396450008,-0.0079762814566493,-0.0083102155476808999,-0.0097712390124797995,-0.012496954761445999,-0.016680125147104,-0.022006945684551998,-0.029090709984303,-0.034726805984973998,-0.037563223391770997,-0.038384448736906003,-0.036895532160997002,-0.034667864441871997,-0.031716596335173,-0.030610900372266998,-0.032642919570207998,-0.03675028309226,-0.043089501559733998,-0.050130214542149998,-0.057580679655074997,-0.064051121473312003,-0.068712964653969005,-0.072450079023838002,-0.075451478362083005,-0.077771268785,-0.078991189599037004,-0.081250190734863004,-0.085740387439728005,-0.090808823704720001,-0.096087925136089006,-0.10112765431404,-0.10548886656761,-0.10996554046869,-0.11498388648033001,-0.11978742480278,-0.12419323623179999,-0.12793704867363001,-0.13067997992038999,-0.13325843214989,-0.1360939592123,-0.13863319158553999,-0.14070436358451999,-0.14235334098339,-0.14330911636353,-0.14470236003399001,-0.14725509285926999,-0.14975096285343001,-0.15173006057739,-0.15345099568366999,-0.15440703928471,-0.15692132711411,-0.16272038221359,-0.16838541626930001,-0.17261503636837,-0.17593234777451,-0.17834936082363001,-0.17969931662083,-0.17973521351814001,-0.17919810116290999,-0.17837789654732,-0.17725943028926999,-0.17598502337933,-0.17415964603424,-0.1714588701725,-0.16861246526241,-0.16589941084384999,-0.16327902674674999,-0.1608465462923,-0.15834760665893999,-0.15545545518397999,-0.1531358063221,-0.15195593237877,-0.15114156901836001,-0.15045113861560999,-0.14988599717616999,-0.14970922470093001,-0.14862409234047,-0.14601165056229001,-0.14213612675667001,-0.13704305887222001,-0.13049072027205999,-0.12151461839676,-0.11369466781616,-0.10935137420893,-0.10513290762900999,-0.099713027477264002,-0.093882486224174,-0.087049499154091006,-0.082102745771407998,-0.081105090677737995,-0.080826714634895006,-0.080011956393718997,-0.079151205718516998,-0.078396499156952001,-0.077050663530826999,-0.075103059411049,-0.071317084133625003,-0.064505904912948997,-0.056963972747326001,-0.048849407583475002,-0.043121684342623,-0.042103860527277,-0.042491767555474999,-0.043056171387433999,-0.044095337390899998,-0.045511830598115997,-0.04725544527173,-0.049421194940804998,-0.051448743790388003,-0.053126297891139998,-0.054251555353403001,-0.054690346121787997,-0.054390411823988002,-0.053354442119598,-0.051333259791136003,-0.047743473201990003,-0.044390127062797997,-0.042098093777895002,-0.040779959410429001,-0.040612246841192003,-0.041417684406042002,-0.042974814772606,-0.045944362878799001,-0.050677381455898,-0.056953884661198002,-0.064610309898852997,-0.074185661971569006,-0.087254300713538999,-0.098625369369984006,-0.10540792346001,-0.10951837897301001,-0.11109263449907,-0.11105233430861999,-0.10908520966768,-0.10843227803707001,-0.11118152737617,-0.11569686979054999,-0.12148977816105,-0.12885440886020999,-0.13835369050502999,-0.1480101197958,-0.15670000016689001,-0.16510000824928001,-0.17326822876930001,-0.18146638572216001,-0.19085171818732999,-0.19756869971752,-0.19880233705044001,-0.19820061326027,-0.19720256328583,-0.19553568959236001,-0.19194376468658,-0.19189679622649999,-0.19955876469611999,-0.20961147546768,-0.21986858546734001,-0.23096571862698001,-0.24407802522182001,-0.25420150160789001,-0.25729167461395003,-0.25896468758583002,-0.26184090971946999,-0.26457276940345997,-0.26760080456733998,-0.26862806081772,-0.26554992794991,-0.26170116662978998,-0.25859734416008001,-0.25590866804123003,-0.25343412160873002,-0.2525343298912,-0.25455638766289002,-0.25725105404853998,-0.25955718755722001,-0.26172044873237998,-0.26372751593589999,-0.26524126529693998,-0.26594957709312,-0.26626753807067999,-0.26656737923621998,-0.26611480116844,-0.26473289728165,-0.26178190112114003,-0.25628033280373003,-0.25027585029602001,-0.24466677010058999,-0.23979121446609,-0.23601999878883001,-0.23352774977683999,-0.23295927047729001,-0.23267431557178,-0.23202461004257,-0.23031668365002,-0.22695104777812999,-0.22200013697147,-0.21484020352364,-0.20737791061401001,-0.20101842284203,-0.19436398148537001,-0.18676793575287001,-0.17866964638232999,-0.16973224282265001,-0.16158196330069999,-0.15508498251437999,-0.15047098696232,-0.14838550984859,-0.14779104292393,-0.14860406517982,-0.14936462044716001,-0.14931935071944999,-0.14779832959174999,-0.14381933212279999,-0.13871283829212,-0.13293291628361001,-0.12701970338821,-0.12195725739002,-0.11586137115955,-0.10714992880821,-0.098010756075381997,-0.089290164411068004,-0.081581994891167006,-0.075339481234550004,-0.071067929267882995,-0.069794446229934998,-0.069453567266463997,-0.068890735507010997,-0.068340778350829995,-0.067953057587146995,-0.066721327602863006,-0.063551671802998005,-0.060090944170952003,-0.057245761156082001,-0.054685410112143,-0.052541919052600999,-0.050386913120747001,-0.047837186604738,-0.045351903885603,-0.043256856501102003,-0.041149388998746997,-0.038878694176674,-0.036312244832516001,-0.032924022525548997,-0.030093776062131001,-0.028803858906030998,-0.028423747047782,-0.028748905286193002,-0.029883151873945999,-0.032435625791550002,-0.034370869398117003,-0.034214843064547001,-0.032776530832052002,-0.030494285747408999,-0.026452830061316001,-0.018867621198297001,-0.012074623256922001,-0.0094211343675851995,-0.0081830797716975004,-0.0073402845300734,-0.0068677165545523002,-0.0065156612545252002,-0.0061664530076086998,-0.0058038774877787001,-0.0049785147421062001,-0.003326459787786,-0.00098502077162265994,0.0024444120936096001,0.0056043383665383001,0.0072118053212762,0.0086860395967959993,0.010792762041092,0.013227442279458001,0.015721255913376999,0.019128441810608,0.024078490212559998,0.03029147721827,0.037926811724900998,0.046343594789504998,0.056138657033443,0.063884347677231001,0.066055372357367997,0.066581480205058996,0.067476332187653004,0.068480610847473006,0.069403782486916005,0.072062522172927995,0.078167147934437006,0.086343005299567996,0.096326619386673001,0.10714361816645,0.11830056458712,0.12877538800239999,0.13722628355026001,0.14510315656662001,0.15330192446709001,0.16126047074795,0.16884572803973999,0.17590527236462,0.18214131891727001,0.18802946805953999,0.19369360804558,0.19964958727359999,0.20628650486469,0.21374204754828999,0.22246623039246,0.23168917000294001,0.24088595807551999,0.25023397803307001,0.25973722338675997,0.26935422420501998,0.27939674258232,0.28874731063843001,0.29642167687415999,0.30305361747741999,0.30883589386940002,0.31386083364487,0.31840026378632003,0.32198438048362998,0.32348749041557001,0.32559323310852001,0.33065596222878002,0.33695983886719,0.34416317939758001,0.35110220313071999,0.3561025261879,0.36121952533722002,0.36802452802657998,0.37526485323906,0.38265666365623002,0.38930046558379999,0.39415007829665999,0.39794039726257002,0.40100082755089,0.40323257446289001,0.40472009778022999,0.40523931384086997,0.40424928069115001,0.40296265482902999,0.40245369076728998,0.40200608968735002,0.40139964222907998,0.40043893456459001,0.39895504713058,0.39675721526146002,0.39335343241692,0.38963449001312001,0.38626071810722001,0.38306456804276001,0.38028806447982999,0.37733855843544001,0.37357231974602001,0.36965221166611001,0.36610087752342002,0.36245518922806003,0.35893842577933999,0.35408940911293002,0.34578919410705999,0.33693340420723,0.32982668280602001,0.32311984896660001,0.31669193506241,0.30942684412003002,0.29939398169518,0.28945344686508001,0.28220170736312999,0.27555343508719998,0.26867145299910999,0.26089832186699002,0.25045332312584001,0.24025875329971,0.23330014944076999,0.22669745981693001,0.21887049078941001,0.20958013832569,0.19695658981799999,0.18460452556609999,0.17634356021881001,0.16864125430584001,0.15937727689743,0.14887553453444999,0.13552077114582001,0.12315534055233,0.11609160900116,0.11033008992672,0.10324420034885,0.095770306885242004,0.087413281202316007,0.079801507294177995,0.075400963425636,0.070808045566082001,0.063091866672039004,0.053907144814730003,0.043091244995593997,0.033020175993443,0.027080275118351,0.021602811291814,0.013552092015743001,0.0049231648445129004,-0.0038379821926355002,-0.011299735866487,-0.015269793570042,-0.017822721973061999,-0.020264063030480998,-0.022507265210151998,-0.024845065549015999,-0.027423510327935,-0.030327059328555998,-0.034015808254480001,-0.039429176598787002,-0.045162566006183999,-0.050226826220751003,-0.054403081536293002,-0.056944597512483999,-0.058473944664001,-0.059272345155478003,-0.059595238417387002,-0.059843748807907,-0.059851389378309,-0.032826010137796,-0.059048414230346999,-0.058116745203733,-0.057029165327549002,-0.055355694144964003,-0.053341243416071001,-0.050669621676206998,-0.046598345041274997,-0.042640432715416003,-0.040332771837711001,-0.038909710943699001,-0.038303889334202,-0.037944696843623997,-0.037276852875948001,-0.036151699721813001,-0.034159332513809003,-0.031504012644291,-0.028328925371169999,-0.024418469518423001,-0.019280066713691001,-0.01385800447315,-0.0091619435697793995,-0.0046076877042651003,7.413886487484e-05,0.0048627047799528001,0.010272837243974001,0.014994360506535,0.017393182963133001,0.018744045868516,0.019834809005259999,0.020645579323172999,0.021267633885145,0.022177990525960999,0.024100441485643002,0.026498874649405001,0.029015868902206001,0.031757853925228001,0.034816976636647998,0.037890955805779003,0.040642328560351999,0.043196406215429001,0.045518893748521999,0.047758996486663999,0.050133559852839002,0.052449721843003998,0.05455831065774,0.056502621620893,0.058329392224549997,0.059886425733566,0.061263844370842001,0.061758950352668998,0.060215923935174998,0.057816457003354998,0.055437572300434002,0.053154293447733002,0.051196992397308003,0.050059489905833997,0.050897274166345999,0.052220068871975001,0.052613049745559998,0.052505549043416998,0.052041571587323997,0.050725892186165002,0.047697219997644001,0.043958432972431002,0.040393553674220997,0.036859061568974998,0.033534694463014998,0.030362891033292001,0.027364879846573001,0.024479478597641002,0.021589059382676998,0.018849439918995001,0.016481943428515999,0.014248944818973999,0.011921939440072001,0.0095930732786654992,0.0073986314237118002,0.0050164079293609004,0.0020904510747641,-0.0013056430034339001,-0.0053644971922040003,-0.0096694668754935004,-0.013637203723192,-0.017719063907862001,-0.022335549816489001,-0.027204010635614,-0.032320354133844001,-0.037182852625847002,-0.041061479598283997,-0.044301427900791002,-0.046988751739263999,-0.049279540777205998,-0.051411155611277001,-0.053342778235674002,-0.054946392774581999,-0.056697636842728001,-0.059337224811316001,-0.062289968132973002,-0.065147571265696994,-0.067860826849936995,-0.069865830242634,-0.072131931781768993,-0.076096370816230996,-0.080506674945354004,-0.084364823997020999,-0.087634906172752006,-0.089645892381667994,-0.091063708066940002,-0.092558257281779993,-0.093875445425510004,-0.094990730285645003,-0.095803432166575997,-0.095873028039932001,-0.096042200922966003,-0.097652316093445005,-0.099492050707340005,-0.10030490905045999,-0.10072347521782,-0.10091210156678999,-0.10130402445793001,-0.10287097841501,-0.10465703904629001,-0.10560841113329,-0.10626433044672,-0.10677146911620999,-0.10751423984766,-0.10940547287464,-0.11148148775100999,-0.11262280493974999,-0.11341753602028,-0.11414336413145,-0.11494524031878001,-0.11645676195621001,-0.1177736967802,-0.11767540127039,-0.11689557880163,-0.11597350239753999,-0.11477852612734001,-0.11305161565542,-0.11161297559738,-0.11155065894127,-0.11264033615589,-0.11499331146479,-0.11868331581354,-0.12479966878891,-0.13078278303145999,-0.13278049230576,-0.13292954862118,-0.13274352252482999,-0.13181202113627999,-0.12983219325542,-0.12776219844817999,-0.12701965868473,-0.12703900039196001,-0.12762062251567999,-0.12875629961491,-0.13048765063286,-0.13245329260826,-0.13413904607296001,-0.13560520112513999,-0.13664920628071001,-0.13746790587902,-0.13833111524582001,-0.13903629779816001,-0.13933792710303999,-0.13942207396030001,-0.13947267830372001,-0.13943566381931,-0.13938915729522999,-0.13912291824817999,-0.13841520249844,-0.13713599741459001,-0.13477215170859999,-0.13193753361701999,-0.12927931547165,-0.12687568366527999,-0.12529192864895,-0.12406063079834,-0.1227565035224,-0.12132729589938999,-0.11952454596758,-0.11732283234596,-0.11461906135082001,-0.11130274087191,-0.1070170328021,-0.10215095430613,-0.097203500568866993,-0.091987833380699005,-0.086421087384223993,-0.080547817051410994,-0.074136801064014005,-0.067879669368267004,-0.062890022993088004,-0.058732964098454001,-0.055344197899102998,-0.052426014095545002,-0.049783535301685,-0.046669349074364,-0.041530698537827003,-0.035201996564865001,-0.028190987184643999,-0.020753808319568998,-0.013721399009228001,-0.0065356688573956004,0.0014771716669202001,0.0098692327737808002,0.018335131928325001,0.026618424803019,0.033797051757573998,0.040870584547520003,0.049396183341741999,0.058362372219563002,0.066872961819172003,0.074889212846755995,0.081500306725502,0.087875448167323997,0.096012555062770996,0.10452251881360999,0.11194165796041,0.11859846860169999,0.12361539155244999,0.12892894446850001,0.13837958872318001,0.14913466572761999,0.15793737769127,0.16576708853245001,0.17234903573989999,0.17873625457287001,0.1872796267271,0.19604690372944,0.20257696509361001,0.20775152742863001,0.2117365449667,0.21498712897301001,0.21861530840397,0.22189152240752999,0.22381979227066001,0.22512894868850999,0.22629339993,0.22805477678776001,0.23274806141852999,0.23817092180252,0.24116271734238001,0.24302168190479001,0.24454727768897999,0.24562321603298001,0.24657897651196001,0.24699139595031999,0.24613828957080999,0.24440336227417001,0.24218127131462,0.23929961025714999,0.23547178506850999,0.23112270236015001,0.22705236077308999,0.22277384996414001,0.21777667105198001,0.21214815974236001,0.20541058480739999,0.19854415953158999,0.19360098242759999,0.18920201063156,0.18368302285671001,0.17752394080162001,0.17050316929817,0.1633515059948,0.15796655416489,0.15260142087935999,0.14455159008502999,0.13499598205089999,0.12432445585728,0.11364847421646,0.10625493526459,0.099423572421073997,0.088984273374081005,0.076921410858630995,0.064448952674866,0.052593275904654999,0.045119479298592002,0.038788259029387998,0.028446631506085,0.016575381159782,0.0052127456292509998,-0.0054571563377976001,-0.013090278953313999,-0.020223854109645001,-0.031552873551846002,-0.044370070099831002,-0.055739790201187002,-0.065996050834655998,-0.073532357811928004,-0.080359518527984994,-0.090475417673587993,-0.10146257281303001,-0.11046701669693,-0.11800833791494,-0.12302134186029,-0.12714146077633001,-0.13367730379105,-0.14090214669703999,-0.14684604108334001,-0.15216331183910001,-0.15672178566455999,-0.16157995164394001,-0.16967135667801,-0.17870406806469,-0.18512812256812999,-0.19022968411446001,-0.19460543990135001,-0.19867421686649001,-0.20406377315520999,-0.20951700210571,-0.2129744887352,-0.21536873281002,-0.21747346222401001,-0.21942239999770999,-0.22232589125633001,-0.22507286071777,-0.22565075755118999,-0.22489042580127999,-0.22353386878966999,-0.22140154242516,-0.21826502680779,-0.21465811133384999,-0.21174004673958,-0.20906594395638001,-0.20631240308285001,-0.20348212122917,-0.20037093758582999,-0.19710327684879,-0.19389973580837,-0.19059602916241,-0.18692551553249001,-0.18297831714153001,-0.17889314889908001,-0.17446972429752,-0.16922396421432001,-0.16347266733645999,-0.15767797827721,-0.15173289179801999,-0.14567846059799,-0.13943922519683999,-0.13283604383469,-0.12597021460533001,-0.11894988268614,-0.11180892586707999,-0.10459025204182,-0.097485877573490004,-0.091045938432217005,-0.085001975297927995,-0.079058438539505005,-0.073223493993281999,-0.067423537373542994,-0.061526067554950999,-0.055030662566423,-0.048332586884498999,-0.042147830128670002,-0.036211520433426,-0.030365189537405999,-0.024491865187882999,-0.018016107380390001,-0.011484504677355,-0.0059486422687768997,-0.0010743970051408001,0.0033090671058744001,0.0072543178685009002,0.011033909395337001,0.01448180899024,0.017291767522693,0.019642353057860999,0.021796047687531,0.023706799373030999,0.025433439761400001,0.026916405186057001,0.027868619188666,0.028704183176160001,0.030351758003234999,0.032505486160517003,0.035165473818778999,0.037865463644265997,0.039432775229215997,0.040108095854520999,0.039728440344334003,0.038502387702465002,0.036808077245950997,0.034665890038013,0.032398562878370001,0.029841722920536998,0.026685386896133,0.02315279096365,0.019558636471629001,0.016005979850887999,0.013090873137116,0.010405507870018,0.0071611688472331004,0.0036742696538567998,0.00033268611878156998,-0.0029813875444233001,-0.0063029681332409,-0.0097286710515617995,-0.013569081202149001,-0.017688594758510999,-0.021908326074481,-0.026271400973200999,-0.030429333448409999,-0.035160362720490002,-0.042886577546596999,-0.052064631134272003,-0.059992633759975003,-0.067178852856159002,-0.073276922106742998,-0.078593559563159998,-0.083746172487735998,-0.088577777147292994,-0.092972800135612002,-0.097061298787593994,-0.10093812644482,-0.10497313737869,-0.11057914793491,-0.11683285981417001,-0.12191197276115,-0.12639985978602999,-0.13057745993136999,-0.13487726449966,-0.14110293984413,-0.14805810153484,-0.15328095853328999,-0.15762656927109001,-0.16190446913241999,-0.16619405150413999,-0.17155739665031,-0.17708776891232,-0.18066194653511,-0.18305768072605,-0.18519520759583,-0.18693077564239999,-0.18835671246051999,-0.18952530622482,-0.19058573246002,-0.19164286553859999,-0.19308622181415999,-0.19486048817634999,-0.19725418090819999,-0.19982193410397001,-0.20125703513622001,-0.20214739441872001,-0.20345677435397999,-0.20493373274803001,-0.20672190189362,-0.20822185277939001,-0.20748256146908001,-0.20536360144615001,-0.20323786139488001,-0.20082020759583,-0.19809901714325001,-0.19505724310875,-0.19158129394053999,-0.18782609701156999,-0.18415500223636999,-0.18056936562060999,-0.17731466889381001,-0.17432074248790999,-0.17152863740921001,-0.16895514726638999,-0.16670383512973999,-0.16459754109383001,-0.16222967207432001,-0.15953105688095001,-0.15601728856564001,-0.1517977565527,-0.14681947231292999,-0.14124138653278001,-0.13547199964522999,-0.12953136861323999,-0.12384881079196999,-0.11815415322781,-0.11171940714120999,-0.10494787245989,-0.098635368049144995,-0.092697903513907998,-0.087436683475971,-0.082671560347079995,-0.078039973974228002,-0.073581822216510995,-0.069200396537780998,-0.064907014369965002,-0.060704756528139003,-0.056532014161348003,-0.052247729152440997,-0.047768604010344003,-0.042705267667769997,-0.037168368697165999,-0.031324278563260997,-0.025044938549399001,-0.017609909176825998,-0.0098519176244735995,-0.0042733033187686998,-0.00010811164975166,0.0034690585453062998,0.0065359594300389004,0.0098064132034778994,0.013245048001409,0.017272535711526999,0.021709421649575001,0.026253122836350999,0.030917571857572001,0.035596624016762002,0.040241688489914003,0.044597875326871997,0.048731002956629001,0.052666563540697001,0.056456737220286997,0.060365390032529997,0.064226567745209004,0.067568093538283996,0.070585161447524997,0.073678612709044994,0.076741024851798997,0.079915799200535001,0.082721255719662004,0.083180926740169997,0.082257039844989999,0.082080811262131001,0.082281835377216006,0.082789763808249997,0.083838783204555997,0.086508840322495006,0.090202115476130995,0.093460820615291998,0.096545517444610998,0.099464580416678994,0.10218645632267,0.10461205244063999,0.10669556260109,0.10815928876399999,0.10911881178617,0.10980249196291,0.11019139736891,0.11035124957561,0.11029363423586,0.11010398715734,0.10977951437235001,0.10931227356195,0.10879840701818,0.10868618637323001,0.1087566614151,0.10836608707905,0.10780921578407,0.10775340348482,0.10814277082682,0.10947663336992,0.11122816056013,0.11161021888255999,0.11107560992241,0.11016947776079,0.10880760848522,0.10690163075924,0.10462719947099999,0.10256392508745001,0.10071985423565,0.099580891430378002,0.098979748785495994,0.098637953400612002,0.098534144461154993,0.098363101482390997,0.098232880234718004,0.098374217748641996,0.098730213940144002,0.099376775324344996,0.10005650669336,0.099691227078437999,0.098589368164539004,0.097239248454571006,0.095604136586189006,0.093802988529205003,0.091894067823886996,0.090166300535201999,0.088647261261940002,0.087729208171368006,0.087237827479839006,0.086728923022746998,0.086263649165629994,0.085693202912807007,0.085202105343341994,0.085566945374011993,0.086498185992241003,0.087327547371386996,0.088123768568038996,0.088620372116565996,0.089022710919379994,0.090134106576442996,0.091644905507565003,0.092790432274342,0.093663088977336995,0.093992367386818002,0.094047755002975006,0.094928778707980999,0.096275843679904993,0.097283139824866999,0.098065137863158999,0.098509840667247994,0.098740473389625993,0.099176973104476998,0.099806286394596003,0.10088273137808,0.10234599560499,0.10413534939289,0.10623042285442,0.10853812843561,0.11101651191711,0.11341065168381,0.11574973165989,0.11797377467155,0.12010353058577,0.12219107896089999,0.12422069162130001,0.12610772252083,0.12793529033661,0.13001738488674,0.13233157992363001,0.13509011268616,0.13812671601772,0.14080682396888999,0.14323315024375999,0.14544034004211001,0.14742086827754999,0.14902094006538,0.15044805407524001,0.15268997848033999,0.15546497702598999,0.15814407169819,0.1607868373394,0.16329324245453,0.16561217606067999,0.16735437512397999,0.16864420473576,0.16978734731674,0.17077037692069999,0.17158190906047999,0.17245212197304,0.17474327981471999,0.17796990275383001,0.18065173923969,0.18304917216301,0.18537715077399999,0.18767334520817,0.19031515717506001,0.19316108524799,0.19579932093620001,0.19824215769768,0.20030893385410001,0.20195063948631001,0.20267142355442,0.20266932249069,0.20254880189895999,0.20230995118618,0.20237390697002,0.20270985364913999,0.20359195768832999,0.20483846962451999,0.20567269623279999,0.20622932910919001,0.20665527880192,0.2069333344698,0.20703591406345001,0.20699745416640999,0.20699070394038999,0.20699073374270999,0.20700401067734001,0.20701092481613001,0.20688466727734001,0.20667891204357,0.20668944716453999,0.20675307512283,0.20616450905799999,0.20502911508082999,0.20326818525790999,0.20108470320701999,0.19963093101977999,0.19865520298480999,0.19760452210903001,0.19653612375259,0.19534823298453999,0.19411066174507,0.19332759082317,0.19268321990966999,0.19056600332260001,0.18737220764160001,0.18412329256535001,0.18080301582812999,0.17810967564583,0.17588323354721,0.17373329401015999,0.17171490192413,0.16982541978359,0.16813577711582001,0.16728298366069999,0.16690738499165,0.16512328386306999,0.16239625215530001,0.16010496020317,0.15812700986861999,0.15677793323993999,0.15594464540482,0.15521194040774999,0.15462964773178001,0.15418735146522999,0.15390010178089,0.15381672978401001,0.15396229922770999,0.15461210906506001,0.15563699603080999,0.15640388429165,0.15701398253441001,0.15759603679180001,0.15818014740944,0.15909960865973999,0.16024632751942,0.16115546226501001,0.16190746426582001,0.16255585849285001,0.16324217617511999,0.16510997712611999,0.16782072186470001,0.16990485787392001,0.17165479063988001,0.17382799088955,0.17645049095154,0.18056979775429,0.18569286167622001,0.18910820782185001,0.19133390486240001,0.19376137852669001,0.19631814956665,0.19980722665787001,0.20379936695098999,0.20563894510269001,0.20599409937859001,0.20744338631629999,0.20977458357810999,0.21382106840611001,0.21906384825705999,0.22222559154034,0.22400209307671001,0.22684447467327001,0.23048546910286,0.235146895051,0.24044266343116999,0.24347995221614999,0.2449111789465,0.24730174243450001,0.25033685564995001,0.25391840934753002,0.25773146748543002,0.25918665528297002,0.25879490375518999,0.25833800435066001,0.25764325261116,0.25676015019416998,0.25565418601036,0.25411626696586997,0.25221809744835,0.25040668249129999,0.24858134984970001,0.24638727307319999,0.24377353489399001,0.24014994502067999,0.23548097908497001,0.22878320515156,0.22036553919315,0.21181544661522,0.20306302607059001,0.1950788795948,0.18748190999031,0.17770750820636999,0.16630123555660001,0.15565156936645999,0.14560356736183,0.13709019124508001,0.12965387105942,0.12017634510994001,0.10906581580639001,0.097259886562823999,0.084674827754498,0.071419790387154,0.057303093373775003,0.040507495403290003,0.021474082022904999,0.0026121977716683999,-0.016343422234057998,-0.035491149872540997,-0.055135391652584,-0.078631043434142997,-0.10504060983658001,-0.12852546572685,-0.14978176355362,-0.17027734220028001,-0.19000388681888999,-0.20982846617699,-0.22971573472022999,-0.25012534856795998,-0.27101144194603,-0.29233884811401001,-0.31414240598679,-0.33672350645065002,-0.36007684469223,-0.38450255990027998,-0.40988528728485002,-0.43541803956031999,-0.46112990379333002,-0.48668584227562001,-0.5120655298233,-0.53675365447998002,-0.56078618764876997,-0.58409941196441995,-0.60666769742965998,-0.62790310382842995,-0.64807999134063998,-0.66973996162414995,-0.69245344400405995,-0.71392691135405995,-0.73435938358306996,-0.75378888845444003,-0.77237397432327004,-0.79201352596283003,-0.81229382753372004,-0.83035564422607,-0.84649890661240001,-0.86143273115158003,-0.87522500753402999,-0.88931477069855003,-0.90340214967728005,-0.91533774137497004,-0.92538899183273005,-0.93458408117294001,-0.94297540187836004,-0.95222806930542003,-0.96198195219039995,-0.96950942277908003,-0.97510874271393,-0.97989410161972001,-0.98381030559539995,-0.98717939853668002,-0.98987925052643,-0.99080765247345004,-0.99003803730010997,-0.98755073547363004,-0.98330616950989003,-0.97647577524185003,-0.96733510494232,-0.95873135328293002,-0.95030099153518999,-0.94005542993545999,-0.92809516191482999,-0.91357344388962003,-0.89692866802215998,-0.88322901725768999,-0.87186807394027999,-0.85948312282562001,-0.84629857540131004,-0.83235943317412997,-0.81778299808501997,-0.80459481477737005,-0.79222059249877996,-0.77449595928192005,-0.75202363729476995,-0.72697567939758001,-0.69965481758117998,-0.67689180374145996,-0.65749889612197998,-0.63050889968872004,-0.59705519676207996,-0.56283634901046997,-0.52809685468673995,-0.50217944383621005,-0.48360770940781,-0.45908564329147,-0.42977938055991999,-0.40105795860290999,-0.37285283207893,-0.34945419430732999,-0.32982331514358998,-0.30137091875076,-0.26546841859817999,-0.23173508048058,-0.19984975457191001,-0.17419825494289001,-0.15364073216915,-0.12331517785788,-0.084855124354362002,-0.051190942525864001,-0.021706487983465,0.0013241712003946001,0.018903102725744001,0.046162277460098003,0.081531502306461001,0.11204681545495999,0.13844345510006001,0.16160227358341001,0.18194079399109001,0.20766773819923001,0.23790396749973,0.26435533165932001,0.28756374120712003,0.30955404043197998,0.33058395981789002,0.35796239972115002,0.39067849516869002,0.41621288657187999,0.43540850281714999,0.45280545949936002,0.46840536594391002,0.48626211285590998,0.50589329004287997,0.52139234542847002,0.53321886062622004,0.54520463943481001,0.55728161334991,0.57176178693770996,0.58829289674759,0.60153043270110995,0.61187666654587003,0.62299448251723999,0.63477253913878995,0.64848506450652998,0.66379022598267001,0.67409920692444003,0.67986845970153997,0.68533986806869995,0.69035893678664995,0.69544339179992998,0.70033293962479004,0.69915753602982,0.69233489036560003,0.68444073200225997,0.67532867193222001,0.66497009992598999,0.65351593494414995,0.64532309770583995,0.64011156558990001,0.63481664657592995,0.62952047586440996,0.62395745515822998,0.61806619167328003,0.60960137844086004,0.59869128465652,0.58673411607741999,0.57369148731232,0.55971860885619995,0.54478377103805997,0.52807885408401001,0.50966805219650002,0.49070796370505998,0.47117364406585999,0.45132938027382002,0.43117350339889998,0.41097095608710998,0.39071717858315003,0.37057891488075001,0.35053855180740001,0.33023044466972001,0.30964770913124001,0.28805893659592002,0.26553007960320002,0.24400787055491999,0.22335618734359999,0.20029599964618999,0.17491075396538,0.14701990783214999,0.11673051118850999,0.087992534041405002,0.060705345124006001,0.034536935389041998,0.0094861090183258005,-0.014586050063372,-0.037666425108910002,-0.059072390198707997,-0.078874923288821994,-0.099848441779612995,-0.12191574275494001,-0.14422227442265001,-0.16672864556313,-0.18621574342250999,-0.20285984873772001,-0.22319914400578,-0.24706007540225999,-0.27122038602829002,-0.29567086696625,-0.31670975685120001,-0.33446788787842002,-0.35344719886780002,-0.37354558706284002,-0.39237394928932001,-0.40993759036063998,-0.42436835169791998,-0.43571332097054,-0.44541421532630998,-0.45346152782440002,-0.46043679118156,-0.46632900834084001,-0.47060745954513999,-0.47331333160400002,-0.47811639308928999,-0.48494860529900002,-0.49057906866074003,-0.49503612518311002,-0.49844750761986001,-0.50081181526184004,-0.50183850526810003,-0.50153040885925004,-0.49996283650397999,-0.49713566899299999,-0.49335598945617998,-0.48860535025597002,-0.47937881946563998,-0.46571400761603998,-0.45223805308342002,-0.43892842531204002,-0.42488288879394998,-0.41009479761124001,-0.39070755243300997,-0.36674588918686002,-0.34671670198441001,-0.33060276508330999,-0.31451287865638999,-0.29844915866852001,-0.27816301584244002,-0.25364869832992998,-0.2322353720665,-0.21393917500973,-0.19320556521415999,-0.17003372311591999,-0.14005248248577001,-0.10320402681828,-0.073677830398082997,-0.051563657820224998,-0.027285384014249001,-0.00081131979823112,0.029771460220218,0.064535461366176994,0.092872582376003002,0.11465941369534,0.13869203627109999,0.16503016650676999,0.19376513361931,0.22496666014194,0.25030520558357,0.26961207389831998,0.29338747262955001,0.32175379991531,0.35255575180054,0.38585799932480003,0.41374742984772001,0.43601340055465998,0.4630571603775,0.49506014585495001,0.52779084444045998,0.56131422519684004,0.58676934242249001,0.60388773679732999,0.6225780248642,0.64302110671997004,0.66252034902572998,0.68108773231506003,0.69559693336487005,0.70588243007660001,0.71876674890518,0.73443490266800004,0.74906861782073997,0.76263338327408003,0.77339762449265004,0.78123396635055997,0.79104906320571999,0.80303651094437001,0.81242710351944003,0.81914144754410001,0.82235991954803001,0.82199645042419001,0.82086080312729004,0.81904453039169001,0.81524521112442005,0.80943232774733997,0.80177712440491,0.79226666688919001,0.78139394521713001,0.76913267374038996,0.75706380605697998,0.74524390697479004,0.73322546482086004,0.72102302312850997,0.70787459611893,0.69379425048828003,0.67739051580428999,0.65859228372573997,0.63844579458237005,0.61700075864792003,0.59340745210648005,0.56759858131409002,0.54099160432815996,0.51362019777297996,0.48579150438308999,0.45751744508742997,0.42880570888518998,0.39963105320929998,0.37081676721572998,0.34239232540130998,0.31431895494460999,0.28658774495125,0.25974890589714,0.23395128548145,0.20533542335033,0.17365626990794999,0.14174295961857,0.10968370735645,0.077716581523417996,0.045882910490035997,0.013529594056308001,-0.019389547407627002,-0.052324742078781003,-0.085263051092624997,-0.11815047264099,-0.15106265246868,-0.18200550973415,-0.21089513599873,-0.23759546875953999,-0.26204437017441001,-0.28520065546036,-0.30698186159134,-0.33061042428017001,-0.35642594099045,-0.37991783022880998,-0.40078267455101002,-0.42128711938857999,-0.44141176342964,-0.46395429968834001,-0.48931398987769997,-0.51175814867019997,-0.53091096878052002,-0.54898577928543002,-0.56602966785430997,-0.58307808637618996,-0.60034906864166004,-0.61445015668868996,-0.62511050701141002,-0.63436716794967996,-0.64232039451598999,-0.64883327484131004,-0.65392899513244995,-0.65708029270171997,-0.65818327665329002,-0.65869230031966997,-0.65867888927460005,-0.65831661224365001,-0.65764623880385997,-0.65627169609070002,-0.65420967340469005,-0.65073388814926003,-0.64578747749329002,-0.63949859142303001,-0.63179486989974998,-0.62424981594086004,-0.61714071035384999,-0.60710573196411,-0.59383600950241,-0.57905185222625999,-0.56263810396194003,-0.54849344491958996,-0.53720772266387995,-0.52288407087326005,-0.50497597455978005,-0.48649901151656999,-0.46742126345634,-0.45146566629410001,-0.43935599923134,-0.42322823405266002,-0.40227961540222001,-0.38119792938232,-0.36011216044425998,-0.34187895059585999,-0.32731711864471003,-0.30647501349449002,-0.27810120582580999,-0.25103178620338001,-0.22569970786572,-0.20458608865738001,-0.18841700255871,-0.16940578818321,-0.14666259288788,-0.12533704936504,-0.10574515163898,-0.088322766125201999,-0.073431380093098006,-0.056429035961628002,-0.036641430109738998,-0.018908053636551,-0.0036572832614183001,0.010119205340743001,0.022132076323032001,0.037508767098187998,0.057096011936664998,0.074648626148701006,0.089581817388535004,0.10350617766380001,0.1163349673152,0.13074357807636,0.14736989140511,0.16046732664107999,0.16938614845276001,0.17671163380145999,0.18255919218062999,0.18768522143364,0.19219772517681,0.19570644199848,0.19811205565928999,0.20037621259689001,0.20255734026432001,0.20506411790848,0.20808902382850999,0.2096404582262,0.20942169427872001,0.20901250839232999,0.20854820311069,0.20799791812897001,0.20752440392971,0.20514059066772,0.20054696500301,0.19519458711147,0.18920588493346999,0.18247805535792999,0.17497695982455999,0.16713763773441001,0.15897752344607999,0.15080505609511999,0.14267419278622001,0.13434627652167999,0.12579368054866999,0.11711178719996999,0.10830695927143,0.099409990012645999,0.090456932783126998,0.081124499440192996,0.071463279426097995,0.060444485396147003,0.047841101884842002,0.035004522651434,0.022050937637687,0.0091150235384702995,-0.0037551047280431002,-0.016797801479696998,-0.030058562755585001,-0.043304733932018002,-0.056567121297120999,-0.069277651607990001,-0.081405691802501998,-0.092602290213107993,-0.10284034907818,-0.11183886229992,-0.11940731108189,-0.12720809876919001,-0.13540302217007,-0.1442496329546,-0.15392670035361999,-0.16298814117908,-0.17115454375743999,-0.17973569035529999,-0.18889226019381999,-0.19838501513004,-0.20834508538245999,-0.21723526716232,-0.22478871047497001,-0.23190499842167001,-0.23865658044815,-0.24521231651306,-0.25169724225998003,-0.25708022713661,-0.26111933588982,-0.26506975293159002,-0.26909953355789001,-0.27291241288184998,-0.27652835845946999,-0.27955251932143999,-0.28193494677544001,-0.28364545106888001,-0.28462517261504999,-0.28535234928130998,-0.28588521480559997,-0.2863352894783,-0.28695905208588002,-0.28536880016326999,-0.28101652860641002,-0.27625301480293002,-0.2712733745575,-0.26680591702460998,-0.26313459873199002,-0.25868031382561002,-0.25308114290236999,-0.24794310331344999,-0.24343429505825001,-0.23986265063286,-0.23758481442928001,-0.23375581204890999,-0.22771169245243,-0.2221749573946,-0.21752123534678999,-0.21344761550426,-0.21042840182781,-0.20389251410961001,-0.19262769818306,-0.18200151622294999,-0.17280557751656,-0.16403403878212,-0.15602055191993999,-0.14499740302563,-0.12975235283375,-0.11637529730797,-0.10586223751307,-0.096486710011959007,-0.088287673890591001,-0.079525828361510995,-0.069652304053306996,-0.061217140406370003,-0.054813168942928002,-0.048297658562660002,-0.041626941412687003,-0.032643675804138003,-0.020417962223291002,-0.010029637254775001,-0.0025305300951003998,0.0050001516938210002,0.01286537759006,0.021529432386160001,0.031390827149152999,0.039932690560818003,0.046445600688457003,0.053789027035235998,0.062343627214431999,0.072332158684731002,0.084283493459225006,0.094416178762913,0.10182565450668001,0.1092396825552,0.1170464977622,0.12503093481064001,0.13345722854136999,0.14013960957527,0.14432735741138,0.14933551847935,0.15576526522636,0.16278818249702001,0.17069245874882,0.17655059695243999,0.17964538931846999,0.18182393908500999,0.18325538933277,0.18442665040493,0.18529424071312001,0.18708251416683,0.19008141756058,0.19375321269035001,0.19815847277640999,0.20239284634589999,0.20640754699707001,0.20932911336422,0.21089965105056999,0.21178263425827001,0.21198102831841001,0.21215462684631001,0.21241748332977001,0.21282657980919001,0.21334460377692999,0.21449999511241999,0.21655763685703,0.21825011074542999,0.21938844025134999,0.21981811523438,0.21943624317645999,0.21859356760979001,0.21732325851917,0.21578872203826999,0.21404719352721999,0.21192707121372001,0.20933943986893,0.20674437284469999,0.20421935617924,0.20177887380123,0.19944137334824,0.19714912772179,0.19481855630875,0.19301688671111999,0.19195561110973,0.19084393978118999,0.1894983202219,0.18827350437640999,0.18717543780804,0.18655997514725001,0.18671806156635001,0.18607477843761,0.18418991565703999,0.18211813271046001,0.17993366718292,0.17827668786049,0.17743924260138999,0.17636382579803001,0.17474725842475999,0.17342202365397999,0.17253501713276001,0.17205932736397,0.17221255600452001,0.17156179249287001,0.16968287527560999,0.16756044328212999,0.16531684994698001,0.16319386661053001,0.16134367883205,0.15918068587779999,0.15648443996906,0.15402293205261,0.15195897221565,0.15011970698832999,0.14843325316906,0.14729756116866999,0.14688287675381001,0.14658099412917999,0.14627373218535999,0.14604309201241,0.14609877765179,0.14501397311687,0.14225330948830001,0.13940705358982,0.13684348762035001,0.13407263159752,0.13115431368350999,0.12724004685879001,0.12185694277287,0.11686860024928999,0.11274375021458,0.10883905738591999,0.10509208589792,0.10135940462350999,0.097575530409812997,0.093886554241180004,0.090327471494675002,0.086846403777599002,0.083479866385459997,0.079936832189560006,0.076092362403870004,0.072349272668361997,0.068899475038051994,0.065027914941310994,0.060548681765794997,0.055681616067885999,0.050321780145167999,0.045288629829883999,0.040760532021523001,0.036803688853979,0.033522404730319998,0.030553234741091999,0.027907187119126001,0.025108646601439001,0.022327210754156002,0.017758149653672999,0.010763125494123,0.0025345131289214,-0.0070949085056782003,-0.015823714435101,-0.023000532761216001,-0.029142867773771002,-0.034220270812511,-0.038644358515738997,-0.042584922164678997,-0.045626077800988998,-0.047641143202782003,-0.048875052481890002,-0.049273226410151,-0.049427639693022003,-0.049475118517875998,-0.049460291862488001,-0.049308229237795001,-0.049677997827529997,-0.050861164927483,-0.052093811333179002,-0.053143523633480003,-0.054445307701825998,-0.056141838431357997,-0.0578951574862,-0.059745054692030002,-0.061051473021507,-0.061632610857487002,-0.061634439975022999,-0.061462450772523998,-0.058719243854284002,-0.052085954695939997,-0.045735273510218,-0.040734831243753003,-0.036401852965355003,-0.032611913979052998,-0.029993921518326,-0.029049966484308,-0.027815453708172001,-0.025827020406723002,-0.023058176040649001,-0.019670719280839001,-0.014215803705156,-0.0057942764833570004,0.0026822655927389999,0.010343201458454,0.018146505579352001,0.025952532887458999,0.035432148724793999,0.047796737402678001,0.058820847421885002,0.067149981856346005,0.074533224105835003,0.081202216446399994,0.087520129978657005,0.093663603067398002,0.099422223865985995,0.10456635057926,0.11017112433909999,0.11652657389641,0.12362042069435,0.13167908787727001,0.13966313004493999,0.14702533185482,0.15524695813656,0.1647407412529,0.17535136640071999,0.18804515898228,0.19760961830616,0.20185451209544999,0.20484751462935999,0.20753529667854001,0.20961670577526001,0.21108280122279999,0.21231192350388001,0.21343588829040999,0.21437272429466001,0.21513901650906,0.21564611792564001,0.21602189540863001,0.21543553471565,0.21347351372241999,0.21105787158011999,0.20850552618504001,0.20536483824252999,0.2018286883831,0.19635374844073999,0.18803223967551999,0.17920947074890001,0.17065724730491999,0.16151525080203999,0.15175107121468001,0.14071017503738001,0.12778037786484001,0.11503663659096,0.10339263826609001,0.091109730303288006,0.077787525951862002,0.063281230628490004,0.046993572264910001,0.03147454932332,0.018198924139141998,0.0034383349120617,-0.013900706544518001,-0.033384077250957003,-0.055688511580229,-0.077520102262497004,-0.097246453166007996,-0.11811035871506,-0.14114317297935,-0.16536572575569,-0.19139912724495001,-0.21520860493183,-0.23429943621159,-0.25483229756355003,-0.27902266383170998,-0.30432537198067,-0.33098387718201,-0.35519427061080999,-0.37448889017105003,-0.39482256770134,-0.41849893331527999,-0.44233873486518999,-0.46607184410094998,-0.48738989233970997,-0.50424635410309004,-0.52254927158356002,-0.54493784904480003,-0.56701427698134999,-0.58789879083633001,-0.60638600587845004,-0.62071716785430997,-0.63669270277023005,-0.65710759162902999,-0.67703253030777,-0.69527554512024003,-0.71132755279541005,-0.72426807880402,-0.73666489124297996,-0.74973738193511996,-0.76133334636687999,-0.77075910568237005,-0.77860933542251998,-0.78508979082107999,-0.78963810205460006,-0.79171288013457997,-0.79309028387070002,-0.79450792074203003,-0.79519248008728005,-0.79555606842041005,-0.79282212257384999,-0.78506201505661,-0.77683734893798995,-0.76992595195769997,-0.76248800754546997,-0.75483709573746005,-0.74362123012543002,-0.72624254226685003,-0.70921307802199995,-0.69542109966277998,-0.68089199066161998,-0.66540539264678999,-0.64514040946960005,-0.61634236574172996,-0.58950406312943004,-0.56956779956818004,-0.54938793182373002,-0.52753102779387995,-0.50175929069518999,-0.46871817111969,-0.43876275420188998,-0.41774880886077997,-0.39471682906151001,-0.36652764678000999,-0.33239883184433,-0.28819110989571001,-0.24894462525844999,-0.22330580651759999,-0.19576314091682001,-0.16108909249306,-0.12180323153734,-0.074587203562259993,-0.034914188086987,-0.012681366875767999,0.011328598484397,0.044360455125569999,0.080815464258193997,0.12182100862265,0.15797328948975001,0.18256427347660001,0.20933371782303001,0.24408257007598999,0.28069204092026001,0.31919834017754001,0.35285437107085998,0.37587746977806002,0.40157604217529003,0.43627896904945002,0.47184580564499001,0.50708156824112005,0.53735923767089999,0.55835908651351995,0.57953095436096003,0.60526067018509,0.63029754161835005,0.65360724925994995,0.67352920770644997,0.68775725364685003,0.70243340730667003,0.72083055973053001,0.73827916383742997,0.75342243909836004,0.76610416173935003,0.77534353733062999,0.78397715091705,0.79364639520644997,0.80178231000900002,0.80748665332794001,0.81117469072341997,0.81307113170624001,0.81219792366027999,0.80750298500061002,0.80183690786362005,0.79647547006607,0.79052764177321999,0.78431439399719005,0.77580612897873003,0.76336026191711004,0.75037306547164995,0.73840671777724998,0.72597283124923995,0.71315217018126997,0.69801807403563998,0.67871236801146995,0.65947288274765004,0.64251571893692005,0.62512618303298995,0.60690885782241999,0.58612835407257002,0.56120264530181996,0.53506118059158003,0.50873112678527999,0.48225453495978998,0.45585244894027999,0.42955866456031999,0.40347370505333002,0.37742820382117998,0.35127192735672003,0.32538115978241,0.29988160729407998,0.27488335967063998,0.25090381503105003,0.22610382735729001,0.19912713766098,0.17238651216029999,0.14682656526565999,0.12216209620236999,0.098489433526993006,0.075640946626663,0.0532859377563,0.032536502927542003,0.014113957062363999,-0.0029844553209841,-0.018747517839074,-0.034621331840753999,-0.051921822130680001,-0.068164683878422005,-0.082114562392234997,-0.094935446977614996,-0.1067831069231,-0.11831853538752,-0.13034398853779,-0.14107543230056999,-0.14957223832607,-0.15672114491462999,-0.16274856030941001,-0.1677351295948,-0.17197534441948001,-0.17464199662209001,-0.17523640394210999,-0.17433655261993,-0.17226858437060999,-0.16846264898777,-0.16232728958129999,-0.15534812211990001,-0.14853560924529999,-0.14039942622185,-0.13041053712368,-0.1184568926692,-0.10348270833492,-0.089005053043365007,-0.077641747891903007,-0.065367728471755995,-0.050338923931122,-0.033758535981177999,-0.014991957694292001,0.0025340393185615999,0.015671283006668001,0.030233891680837,0.049219764769077003,0.070264510810375005,0.093797944486140997,0.11577346175908999,0.13227188587189001,0.15053246915339999,0.17479459941386999,0.20033685863018,0.22657053172587999,0.24951496720314001,0.26437327265739002,0.28088793158531,0.30503794550896002,0.33008006215095997,0.35451388359070002,0.37503987550735002,0.38669088482857,0.40034201741219,0.42319244146347001,0.44633209705353,0.46665629744530002,0.48338997364044001,0.49397268891335,0.50386285781859996,0.51649481058121005,0.52817350625991999,0.53751766681670998,0.54486447572707997,0.54944705963134999,0.55370682477951005,0.55953782796859997,0.56433230638503995,0.56688046455383001,0.56780362129211004,0.56715309619903997,0.56502139568329002,0.56144285202026001,0.55653136968613004,0.55037325620651001,0.54292941093445002,0.53451716899872004,0.52392691373824996,0.50981909036635997,0.49485263228415999,0.48078149557114003,0.46570762991905001,0.44975054264068998,0.42982259392737998,0.40193814039230003,0.37425559759139998,0.35215184092522001,0.33011236786842002,0.30662831664085,0.27983689308166998,0.24608328938484,0.21345138549805001,0.18800041079520999,0.16207353770732999,0.13272902369499001,0.099102437496184997,0.056683495640754998,0.017537932842969998,-0.0086505673825741005,-0.034460581839085,-0.065727703273295995,-0.10067695379257,-0.1421066224575,-0.18095694482326999,-0.20921656489372001,-0.23821270465850999,-0.27398753166199002,-0.31299692392348999,-0.35700204968451998,-0.39695984125137002,-0.42421838641166998,-0.45123672485352001,-0.48509308695793002,-0.52077448368072998,-0.55845040082931996,-0.59239208698273005,-0.61617320775985995,-0.64004302024840998,-0.67048072814940995,-0.70189136266707997,-0.73328179121017001,-0.76117670536041004,-0.78102713823318004,-0.80026835203170998,-0.82384461164473999,-0.84713643789291004,-0.86889070272446001,-0.88734197616577004,-0.89968210458755005,-0.91071027517319003,-0.92367595434188998,-0.93563956022262995,-0.94563931226730003,-0.95316606760025002,-0.95696038007735995,-0.95943248271942005,-0.96230876445769997,-0.96398341655731001,-0.96378964185714999,-0.96187055110930997,-0.95800626277923995,-0.95271015167235995,-0.94644522666930997,-0.93859529495239002,-0.92878872156143,-0.91729408502579002,-0.90423011779785001,-0.88948416709900002,-0.87316560745239002,-0.85473310947418002,-0.83343648910521995,-0.81068998575211004,-0.78671371936797996,-0.76342010498046997,-0.74360579252242998,-0.72232770919800005,-0.69588577747345004,-0.66781049966812001,-0.63906800746918002,-0.61142182350159002,-0.58801972866058005,-0.56310999393463002,-0.53206175565720004,-0.49982899427414001,-0.46829897165298001,-0.43872854113579002,-0.41453269124031,-0.38875237107277,-0.35533770918846003,-0.32123622298241,-0.28986597061156999,-0.26091313362121998,-0.23671962320805001,-0.2116437703371,-0.18036518990993,-0.14935612678528001,-0.12217664718628,-0.097708344459533997,-0.077505715191363997,-0.056805275380611003,-0.030820444226264999,-0.0054648076184094004,0.015555419027805001,0.034564875066279997,0.051322635263204998,0.068987727165222001,0.091418251395225997,0.11323124170303001,0.13085681200027,0.14647373557091001,0.16054902970790999,0.17366863787174,0.18696559965611001,0.19853763282299,0.20680238306522,0.21333071589470001,0.21873646974564001,0.22344912588596,0.22826643288136,0.23217339813709001,0.23442119359970001,0.23567694425583,0.23631624877453,0.23608653247356001,0.23473556339741,0.23280414938926999,0.23096564412116999,0.22813799977303001,0.22372564673424,0.21756559610366999,0.20853665471076999,0.19935734570026001,0.19276982545853,0.18567177653313,0.17616069316864,0.16507288813591001,0.15168620646,0.13874025642872001,0.12913596630096,0.11977124214172,0.10869178920984,0.096965126693248999,0.084345877170562994,0.072573125362396004,0.063899539411068004,0.055286131799220997,0.044471006840467002,0.032994236797093998,0.020951153710485001,0.0099308630451560003,0.0020044036209583001,-0.0052844556048511999,-0.013704149052501001,-0.022043762728571999,-0.030107324942946,-0.037005137652159001,-0.041672918945551002,-0.045010060071945003,-0.047372225672007003,-0.048990804702043998,-0.050184436142444999,-0.050876185297966003,-0.051303222775458998,-0.050803251564503001,-0.048586446791886999,-0.045635905116796001,-0.042532708495854998,-0.039300981909036997,-0.036891099065541999,-0.032895419746636997,-0.024576894938945999,-0.015074076130986,-0.0064518833532929004,0.0019937853794545,0.0090884277597070001,0.018488300964235999,0.034770544618368003,0.052235055714845997,0.066659286618233005,0.080274827778338997,0.093032129108906,0.10713491588831001,0.12572751939297,0.14487582445145,0.16140455007553001,0.17753659188747001,0.19383206963538999,0.21159134805202001,0.23340471088886,0.25527307391166998,0.27357187867165,0.29109430313110002,0.30887782573700001,0.32792451977730003,0.35083597898482999,0.3732813000679,0.39106234908103998,0.40770888328552002,0.42503824830054998,0.44319656491280002,0.46402791142464,0.48397588729857999,0.49940401315688998,0.51338934898375999,0.52771478891373003,0.54199832677840998,0.55702012777328003,0.57102197408676003,0.58198642730713002,0.59191870689392001,0.60219812393187999,0.61230355501175004,0.62276726961135997,0.63181543350220004,0.63737815618515004,0.64126807451248002,0.64464670419693004,0.64711874723434004,0.64908456802367998,0.64932215213776001,0.64627993106841997,0.64157366752625,0.63633906841277998,0.63025140762329002,0.62342590093613004,0.61568665504455999,0.60686033964157005,0.59707665443419999,0.5863898396492,0.57484167814255005,0.56262838840484997,0.54933017492294001,0.53445333242416004,0.51845723390579002,0.50166422128677002,0.48396047949790999,0.46541866660117998,0.44580361247063,0.42463919520378002,0.40273755788803001,0.38109302520751998,0.35864612460135997,0.33465319871902,0.30919137597084001,0.29765152931213001,0.25334918498992998,0.21518296003342,0.19351531565189001,0.1643538326025,0.13323754072189001,0.10442391037941,0.087288819253445005,0.072179719805716996,0.051124013960361002,0.028199698776007,0.0035757236182690001,-0.018928516656160001,-0.032938439399004003,-0.045654445886612001,-0.063598327338695998,-0.082887187600135998,-0.10257381945848,-0.12020054459571999,-0.13106973469256999,-0.14060939848423001,-0.15400218963623,-0.16783268749714,-0.18063068389893,-0.19147579371928999,-0.19780923426151001,-0.20283766090870001,-0.20978942513466001,-0.21649195253848999,-0.22178688645363001,-0.22561860084533999,-0.22738309204578,-0.22749552130699,-0.22608058154582999,-0.22345364093781001,-0.22000885009766,-0.21571016311645999,-0.21086710691452001,-0.20486508309841001,-0.19663695991039001,-0.1876782476902,-0.17955866456031999,-0.17133824527263999,-0.16329135000705999,-0.15324787795544001,-0.13726007938384999,-0.12018057703972,-0.10675666481256001,-0.094628304243088004,-0.083697527647018002,-0.071600340306759006,-0.053924564272165,-0.035748213529587,-0.022231165319681001,-0.010242648422718,0.0012158947065473,0.014020538888871999,0.032549202442169002,0.051300439983605998,0.064250126481056005,0.075414352118969005,0.086974687874317003,0.099470138549805007,0.11591253429650999,0.13169668614864,0.14118546247482,0.14858080446720001,0.15678156912326999,0.16540798544884,0.1763202548027,0.18598808348179,0.18977662920951999,0.1911835372448,0.19284382462502,0.19397947192192,0.19500686228274999,0.19492945075035001,0.19248490035533999,0.18837201595306,0.18295055627823001,0.17620459198951999,0.16829900443554,0.15909402072430001,0.14862754940987,0.13649402558804,0.12192609906196999,0.10576189309359001,0.088450282812119002,0.070754438638686995,0.054604217410088002,0.037632383406161998,0.017013983801007,-0.0053162313997746,-0.028329607099294999,-0.051310762763023002,-0.071745827794074998,-0.093141049146652,-0.12003129720687999,-0.14908102154732,-0.17806431651115001,-0.20655420422553999,-0.23186200857162001,-0.25763908028603,-0.28877449035644998,-0.32140746712684998,-0.35248452425003002,-0.38232749700545998,-0.40907570719719,-0.43574559688567999,-0.46680986881255998,-0.49839159846306003,-0.52694916725159002,-0.55351865291595004,-0.57719558477402,-0.60031086206436002,-0.62670004367828003,-0.65300178527831998,-0.67587429285049005,-0.69679522514342995,-0.71593207120894997,-0.73445212841034002,-0.75505477190018,-0.77463775873184004,-0.78951400518417003,-0.80167037248610995,-0.81194216012955001,-0.82114535570144997,-0.83185553550720004,-0.84084486961365001,-0.84389913082123003,-0.84373587369919001,-0.84225732088089,-0.83948683738707996,-0.83714765310286998,-0.83268988132476995,-0.82234925031661998,-0.80900853872298994,-0.79516702890395996,-0.78041118383408004,-0.76607906818390004,-0.74975472688675004,-0.72755360603332997,-0.70263743400573997,-0.67787277698517001,-0.65285378694534002,-0.62994241714478005,-0.60438877344131003,-0.56813234090804998,-0.52799916267394997,-0.49076664447784002,-0.45458379387856002,-0.42132288217545,-0.38651949167251998,-0.34211942553519997,-0.29522898793220997,-0.25357154011726002,-0.21407905220984999,-0.17690208554268,-0.13866063952446001,-0.092056572437286002,-0.044113077223301003,-0.0033387281000614001,0.034622240811585998,0.071126095950602999,0.10961090028286,0.15842634439468001,0.20984080433846,0.25466573238373003,0.29724159836768999,0.33955696225165999,0.38267034292221003,0.43176889419556003,0.47930783033370999,0.51360726356506003,0.54246246814728005,0.57228177785873002,0.60307496786117998,0.64041769504546997,0.67674154043197998,0.70045161247252996,0.71911412477492997,0.73937332630157004,0.76011681556702004,0.78453415632248003,0.8073148727417,0.81983530521393,0.82762044668197998,0.83577966690062999,0.84285742044448997,0.84941583871840998,0.85398644208908003,0.85431259870528997,0.85116451978683005,0.84453183412552002,0.83493781089783004,0.82269167900085005,0.80904710292815996,0.79742813110351995,0.78424990177154996,0.76435929536819003,0.74074661731720004,0.71513748168945002,0.68918776512145996,0.66849839687347001,0.64711463451384998,0.61624896526337003,0.58107745647429998,0.54530769586562999,0.51027226448059004,0.48274400830268999,0.45479741692543002,0.41370719671249001,0.36786389350891002,0.32493403553963002,0.28485381603241,0.25450643897057001,0.22461497783661,0.17918033897877,0.12921069562435,0.085990481078625003,0.047530964016914,0.018799014389514999,-0.0082813091576098997,-0.048065595328807997,-0.091452978551387995,-0.12908345460892001,-0.16359007358551,-0.19363431632518999,-0.22291140258312001,-0.25928866863250999,-0.29654276371001997,-0.32687163352965998,-0.35313540697098,-0.37595459818839999,-0.39680829644202997,-0.41963791847228998,-0.44133713841437999,-0.45774412155151001,-0.47084394097327997,-0.48197934031487,-0.49137353897094999,-0.50070083141327004,-0.50820708274840998,-0.51105982065201006,-0.51087927818297996,-0.50921887159348,-0.50581657886505005,-0.50128179788589,-0.49474290013312999,-0.48473316431045999,-0.47190973162651001,-0.45695880055428001,-0.43929278850554998,-0.41748577356339001,-0.39335042238235002,-0.37000736594200001,-0.34586220979691001,-0.31950712203978998,-0.29114976525307001,-0.25998881459236001,-0.22730840742587999,-0.19558934867382,-0.16332951188087,-0.12873594462872001,-0.092565827071666995,-0.054731849581003002,-0.016702435910702002,0.017755225300789001,0.051606409251690001,0.089075461030006006,0.12842461466789001,0.16897071897984001,0.20960998535156,0.24742072820663,0.28393211960793002,0.32077237963675997,0.35732266306876997,0.39347705245018,0.42861223220825001,0.46119546890259,0.49208039045334001,0.52230542898178001,0.55136537551880005,0.57896918058394997,0.60475611686706998,0.62766277790070002,0.64832055568695002,0.66747540235518998,0.68491834402083995,0.70076578855515004,0.71465265750884999,0.72589242458344005,0.73463261127472002,0.74088984727858997,0.74449068307876998,0.74514812231063998,0.74277442693710005,0.73670327663421997,0.72779893875122004,0.71774023771286,0.70567399263382002,0.69063979387283003,0.67297971248626998,0.65254759788512995,0.63016325235366999,0.60829883813857999,0.58465713262557995,0.55518710613250999,0.52180296182632002,0.48541221022606001,0.44801935553550998,0.41616714000701999,0.38467109203339001,0.34488964080811002,0.30080062150955,0.25546503067017001,0.21018499135971,0.17139181494712999,0.13349960744381001,0.086336687207221999,0.035197764635085997,-0.014637080952525,-0.062490969896317,-0.10133314132689999,-0.13840579986571999,-0.18813729286194,-0.24271669983864,-0.29317805171013001,-0.34024292230606001,-0.37811380624771002,-0.41340824961661998,-0.46013599634170999,-0.51032549142838002,-0.55369794368743996,-0.59238082170485995,-0.62357997894286998,-0.65209299325943004,-0.68926805257796997,-0.72848063707351995,-0.76054632663726995,-0.78804486989974998,-0.81105589866637995,-0.83122789859771995,-0.85353714227676003,-0.87448024749756004,-0.88823390007018999,-0.89700323343277,-0.90230625867844005,-0.90462779998778997,-0.90625447034836004,-0.90602391958237005,-0.90240746736526001,-0.89591890573501998,-0.88725912570953003,-0.87558895349502996,-0.85846745967865001,-0.83812189102172996,-0.81902992725372004,-0.79915398359298995,-0.77665311098098999,-0.75084310770035001,-0.71741551160812,-0.68062788248062001,-0.64969933032990002,-0.61989516019821,-0.58534759283065996,-0.54644197225571001,-0.49813508987427002,-0.44694471359253002,-0.40843814611434998,-0.37432312965393,-0.33303105831146002,-0.28702926635741999,-0.23304456472397,-0.17747694253922,-0.13703916966915,-0.10273914039135,-0.061273530125618002,-0.016322426497935999,0.032220140099525001,0.080796122550963995,0.11834301799536,0.15162818133830999,0.19220776855946001,0.23604372143745,0.28106951713562001,0.32457846403121998,0.35634362697601002,0.38278713822365001,0.41534510254860002,0.44983890652656999,0.48311346769333002,0.51380425691605003,0.53502559661865001,0.55129873752594005,0.57101762294768998,0.59112346172332997,0.60902482271194003,0.62421679496765003,0.63309824466705,0.63798528909683005,0.64317202568053999,0.64715141057967995,0.64859098196029996,0.64746230840682995,0.64275276660919001,0.63501900434493996,0.62506717443465998,0.61287486553192005,0.59885507822036999,0.58292782306670998,0.56525236368178999,0.54556471109390003,0.52298963069916005,0.49819979071616999,0.47248202562331998,0.44563883543014998,0.41793093085289001,0.38924127817153997,0.35938084125518999,0.32845848798751998,0.29663267731666998,0.2639354467392,0.2305299192667,0.19642527401446999,0.16152691841125,0.12628103792667,0.091917537152767001,0.058144230395554997,0.024932526051998,-0.0077996663749217996,-0.040413029491901002,-0.072601072490214996,-0.10367878526448999,-0.13383664190769001,-0.16329786181450001,-0.19183975458145,-0.21914097666740001,-0.24489796161652,-0.26778843998909002,-0.28853064775467002,-0.30846217274665999,-0.32719948887825001,-0.34500801563263001,-0.36075240373611001,-0.37059876322745999,-0.37654516100883001,-0.3821673989296,-0.38668674230576,-0.39066717028617998,-0.39270439743996,-0.38812005519866999,-0.37944737076759,-0.37154522538184998,-0.36316007375717002,-0.35429167747498003,-0.34347349405289002,-0.32511103153228998,-0.30250346660614003,-0.28256422281264998,-0.26327437162398998,-0.24357768893241999,-0.22213816642761,-0.19269774854183,-0.15931949019432001,-0.13135230541229001,-0.10564315319061,-0.078953243792056996,-0.050594840198755001,-0.014778001233935001,0.024299178272486,0.055989593267440997,0.084467247128486994,0.11573077738284999,0.14948219060897999,0.19063916802406,0.2343512326479,0.26663112640380998,0.29325798153876997,0.32364085316657998,0.35637769103049999,0.39494037628174,0.43485680222510997,0.46226182579994002,0.48287451267241999,0.50644630193710005,0.53108197450637995,0.55806320905685003,0.58471375703812001,0.60214519500732,0.61388152837752996,0.62587445974349998,0.63691568374634,0.64716446399688998,0.65583282709122004,0.66034060716628995,0.66140639781952004,0.65958666801453003,0.65508210659027,0.64878487586974998,0.64072728157043002,0.63258111476898005,0.62234044075011996,0.60328793525696001,0.57838010787964,0.55272144079207997,0.52648580074310003,0.50569051504134999,0.48549377918242997,0.45147284865379,0.40920877456665,0.36815768480300998,0.3275091946125,0.29284673929214,0.25906431674956998,0.20935522019863001,0.15139982104301,0.10091896355152,0.055688306689262002,0.021063100546598001,-0.0091319754719734001,-0.055641375482081999,-0.11047697812319,-0.15859392285346999,-0.20291414856911,-0.24243065714836001,-0.28040915727615001,-0.33019819855690002,-0.38533663749695002,-0.4306500852108,-0.46975016593933,-0.50428491830826006,-0.53666245937347001,-0.57885295152663996,-0.62500113248824996,-0.66074997186661,-0.68989354372025002,-0.71617025136947998,-0.74040812253952004,-0.76945650577544999,-0.79969221353530995,-0.82150459289551003,-0.83768600225448997,-0.85203403234482,-0.86448276042937999,-0.87827569246292003,-0.89107555150985995,-0.89553946256637995,-0.89404058456420998,-0.89068478345871005,-0.88487267494202004,-0.87716269493103005,-0.86713755130768,-0.85346311330794999,-0.83664494752884,-0.81774359941482999,-0.79659968614578003,-0.77335572242737005,-0.74788606166839999,-0.71977406740188998,-0.68915146589278997,-0.65623384714126998,-0.62102311849594005,-0.58336794376373002,-0.54378032684326005,-0.50443762540817005,-0.46462985873222001,-0.42285865545272999,-0.37959563732147,-0.33545657992362998,-0.29082408547401001,-0.24796867370605,-0.20603320002556,-0.16291402280330999,-0.11924035847187001,-0.075753666460513999,-0.033023521304130998,0.0054186247289180998,0.041226178407668998,0.079157099127768998,0.11790632456541,0.15547835826874001,0.19185239076614,0.22558312118053001,0.25697803497313998,0.28628775477409002,0.3134625852108,0.33854883909224998,0.36136034131049999,0.38106694817543002,0.39790257811545998,0.41227096319199003,0.42413944005965998,0.43374758958817,0.44088405370712003,0.44452723860741,0.44526070356369002,0.44534504413604997,0.44379132986068998,0.43767473101616,0.42765909433365001,0.41424158215522999,0.3979783654213,0.38234841823577997,0.36576017737388999,0.34316489100455999,0.31592097878455999,0.28600582480431003,0.25406464934348999,0.22555151581763999,0.19783034920692,0.16195280849933999,0.12053122371435,0.078369639813899994,0.036102168262004998,0.0016843210905789999,-0.028668092563747999,-0.067656204104423995,-0.11202473938465,-0.15602886676788,-0.19976824522018,-0.23857520520687001,-0.27499985694884999,-0.31878650188446001,-0.36679866909981002,-0.41137281060219,-0.45313295722008001,-0.48853215575218001,-0.51981210708617998,-0.55604708194732999,-0.59445315599441995,-0.62808686494827004,-0.65787696838378995,-0.68279600143432995,-0.70400613546371005,-0.72689223289490001,-0.74984383583069003,-0.76877951622009,-0.78432410955428999,-0.79692971706390003,-0.80623465776443004,-0.81015139818191995,-0.80968755483626997,-0.80853915214538996,-0.80598729848862005,-0.80180382728577004,-0.79497718811035001,-0.77896237373351995,-0.7564891576767,-0.73741185665131004,-0.71943843364715998,-0.69888544082642001,-0.67482036352158004,-0.63758790493010997,-0.59170961380005005,-0.55489504337311002,-0.52296054363250999,-0.48773500323295998,-0.44902420043945002,-0.39738178253174,-0.33788838982581998,-0.29254731535911999,-0.25551459193229997,-0.21217322349548001,-0.16367077827453999,-0.10238796472549,-0.034014321863650998,0.013288024812937,0.047632146626711003,0.092446386814117001,0.14478369057178,0.20868092775345001,0.27903899550437999,0.32811078429222001,0.36360213160514998,0.40821206569671997,0.45842063426971003,0.51299983263016002,0.56921154260634999,0.60867190361023005,0.63708198070526001,0.67371237277984997,0.71518695354462003,0.75778746604919001,0.79995405673981002,0.82850766181946001,0.84751790761947998,0.87112706899643,0.89681094884872004,0.92098933458328003,0.94306468963623002,0.95635592937469005,0.96273624897002996,0.96821010112761996,0.97193419933319003,0.97345465421677002,0.97258889675140003,0.96832299232482999,0.96045291423797996,0.94626122713089,0.92694002389908003,0.90761113166809004,0.88772463798523005,0.86890619993210005,0.84954392910003995,0.81968975067139005,0.78220725059509,0.74740988016128995,0.71400237083435003,0.68301212787627996,0.65248721837997004,0.60913521051407005,0.55698585510253995,0.51187980175018,0.47150266170501998,0.43424963951111001,0.39866265654563998,0.35278543829918002,0.30009567737579002,0.25443744659424,0.21361842751502999,0.17444792389870001,0.13635610044002999,0.091941930353641996,0.043900586664676999,0.0051563456654549001,-0.026701683178543999,-0.057353820651769999,-0.086904734373092998,-0.12145602703093999,-0.15876826643944,-0.18780395388603,-0.21061481535435,-0.23263603448868,-0.25348457694054,-0.27518630027771002,-0.29665294289589,-0.31150767207146002,-0.32105642557143999,-0.32944837212563,-0.33632028102875,-0.34269857406616,-0.34787663817406,-0.34729006886482,-0.34193593263625999,-0.33542343974112998,-0.32736381888389998,-0.31794840097427002,-0.30682700872420998,-0.29141798615455999,-0.27230820059776001,-0.25175639986991999,-0.22955933213234,-0.20599208772182001,-0.18095242977142001,-0.15379896759987,-0.12478955835104,-0.095371119678020005,-0.065408773720264005,-0.035106837749481,-0.0043498501181602001,0.027575390413404,0.060553524643182997,0.094308078289031996,0.12880900502205,0.16368453204632,0.19890309870243,0.2341328561306,0.26915743947029003,0.30177238583565003,0.33238464593887002,0.36242029070853998,0.39178386330604997,0.42102271318436002,0.44982987642288003,0.47609326243401001,0.50010746717453003,0.52262943983078003,0.54355770349502996,0.56279247999190996,0.58012598752974998,0.59357905387877996,0.60350573062896995,0.61127257347107,0.61676305532455,0.62009483575821001,0.62118792533875,0.61958247423171997,0.61523723602295,0.60725414752960005,0.59587430953979004,0.58218210935592996,0.56635898351669001,0.55162143707275002,0.5369678735733,0.51561278104782005,0.48862725496291998,0.45966768264771002,0.42895328998566001,0.40257617831230003,0.37876290082932002,0.34537205100059998,0.30434510111808999,0.26329624652862998,0.22218705713749001,0.18824036419392001,0.15925647318363001,0.11923290044069,0.070796430110930994,0.025597304105759,-0.016841128468513,-0.049869917333125999,-0.075999230146407998,-0.11560720950365,-0.16541862487792999,-0.21002249419689001,-0.25046560168266002,-0.28336301445960999,-0.31053137779236001,-0.34862422943115001,-0.39477652311325001,-0.43344762921333002,-0.46597072482108998,-0.49250409007071999,-0.51405829191207997,-0.54196947813034002,-0.57424676418303999,-0.59911507368088002,-0.61777007579803001,-0.63283503055572998,-0.64464473724365001,-0.65936297178268,-0.67584139108658003,-0.68661731481552002,-0.69247788190841997,-0.69589138031006004,-0.69677853584289995,-0.69611978530884,-0.69377648830413996,-0.68906474113464,-0.68208420276642001,-0.67355138063430997,-0.66332232952117998,-0.6500603556633,-0.63406836986542003,-0.61798393726348999,-0.60145848989487005,-0.58278602361678999,-0.56192147731780995,-0.53604257106780995,-0.50606667995453003,-0.48138144612312,-0.46076339483260997,-0.43729454278946001,-0.41136229038238997,-0.38119921088219,-0.34769201278687001,-0.32116144895554,-0.30018395185470997,-0.27538549900054998,-0.24745880067348,-0.21674855053424999,-0.18390600383281999,-0.15831403434277,-0.13866189122200001,-0.11550050228834,-0.089628495275973996,-0.063280791044234994,-0.036797571927309002,-0.017110688611864999,-0.0032502803951501998,0.012162163853645,0.028551081195474001,0.044400393962860003,0.059534750878811001,0.070014268159866,0.076390340924263,0.083215191960335,0.090114429593086007,0.095590867102145996,0.099638111889362002,0.10088828206062,0.099530354142188998,0.097150824964046006,0.093641236424445995,0.088698126375674993,0.082331016659736994,0.074473425745963995,0.065144963562489,0.054539542645216002,0.042674724012612998,0.029992487281560998,0.016475975513457999,0.0023597758263350001,-0.012428989633917999,-0.029056644067168,-0.047341778874397,-0.065248392522334997,-0.082896552979945998,-0.10051925480366,-0.11813566088676,-0.13631857931614,-0.15496736764908001,-0.17281778156756999,-0.18993853032589,-0.20648825168609999,-0.22243368625641,-0.23723894357681,-0.25092867016791998,-0.26342910528183,-0.27476888895035001,-0.28545007109642001,-0.29541918635367997,-0.30421164631844,-0.31178861856460999,-0.31687098741531,-0.31957626342772999,-0.32103180885315002,-0.32119914889335999,-0.32055211067200001,-0.31891921162605003,-0.31287068128585999,-0.30272951722144997,-0.29217308759688998,-0.28106972575188,-0.27029526233673001,-0.25956308841705,-0.24297505617142001,-0.22104054689406999,-0.19985555112362,-0.17917743325232999,-0.15934480726719,-0.14006695151328999,-0.11438564956188001,-0.082905881106852999,-0.053871244192122997,-0.026927225291729001,-0.0013161106035113001,0.023231117054819998,0.054585747420787999,0.092111960053444006,0.12659479677676999,0.15843182802200001,0.18950279057026001,0.21993091702461001,0.25517302751540999,0.29469865560531999,0.32858225703239002,0.35729274153709001,0.38479605317116,0.41111296415329002,0.44081157445907998,0.47345566749572998,0.49991112947464,0.52063906192779996,0.54131960868835005,0.56186914443970004,0.58525383472443004,0.61112415790557995,0.63066357374190996,0.64427119493483997,0.65717303752899003,0.66925185918807995,0.68132162094116,0.69321745634079002,0.69980710744857999,0.70129793882369995,0.70051074028015003,0.69739019870758001,0.69212913513184005,0.68473631143570002,0.67598634958267001,0.66584420204162997,0.65357172489166004,0.63920032978057995,0.62313479185104004,0.60544002056122004,0.59002304077148005,0.57664930820464999,0.55783265829086004,0.53379839658737005,0.50802189111710006,0.48054540157317999,0.45744171738625,0.43838948011397999,0.41176003217696999,0.37787306308745999,0.34311270713806002,0.30748575925826999,0.27848374843597001,0.25570458173751998,0.22055028378962999,0.17351567745209001,0.12873636186123,0.086130186915398005,0.054344274103642003,0.033027585595846003,0.0045740026980638998,-0.030674401670694001,-0.062531515955925002,-0.091078400611876997,-0.11339963972569,-0.12963181734085,-0.14953437447547999,-0.17294541001319999,-0.19305671751499001,-0.20992866158484999,-0.22321964800357999,-0.23300921916962,-0.24941630661488001,-0.27228319644928001,-0.28993850946425997,-0.30246743559837003,-0.31145641207695002,-0.31691831350326999,-0.32238420844077997,-0.32782125473022,-0.32980680465697998,-0.32835909724236001,-0.32494732737540999,-0.31956520676612998,-0.31114032864571001,-0.29968085885048001,-0.28845620155334001,-0.27745971083641002,-0.26524668931960999,-0.25181794166565002,-0.23501908779144001,-0.21484424173832001,-0.19896240532397999,-0.18738718330859999,-0.17624063789844999,-0.16551870107651001,-0.15459193289279999,-0.14346358180046001,-0.13053067028522,-0.11579228192568,-0.098130650818348,-0.077545613050460996,-0.051782459020614999,-0.020738288760184999,-0.00047942996025084999,0.0088285030797123996,0.017207413911819,0.024720534682274,0.030932815745473002,0.035824254155158997,0.041934158653020998,0.049275174736976998,0.059057377278805001,0.071314543485640994,0.084805294871329998,0.099623098969460006,0.10574954748154,0.10299724340439,0.097235061228274994,0.088492929935455003,0.078920073807240004,0.068484544754028001,0.062230806797743003,0.060269135981797999,0.060472514480351999,0.062895409762858998,0.062804736196995004,0.060229770839213999,0.048208896070719001,0.026541892439127,-0.00087526626884937004,-0.034140124917030001,-0.064826220273972002,-0.092851169407367998,-0.11368611454964,-0.12715084850788,-0.13661718368529999,-0.14196754992008001,-0.15181407332419999,-0.16631123423576,-0.18716903030872001,-0.21448138356209001,-0.24743139743805001,-0.28631037473679,-0.31765723228455001,-0.34113174676894997,-0.35708299279213002,-0.36535838246345997,-0.37034994363785001,-0.37181177735329002,-0.38428315520286999,-0.40830862522125,-0.43908721208571999,-0.47685182094574002,-0.51039278507232999,-0.53977870941161998,-0.54988861083983998,-0.53990775346756004,-0.52107256650925005,-0.49337279796599998,-0.4659506380558,-0.4385624229908,-0.43077051639557001,-0.44374626874924,-0.46138659119606001,-0.48347109556197998,-0.50384932756423995,-0.52306461334229004,-0.51485568284988004,-0.47736513614655002,-0.43776273727416998,-0.39675423502922003,-0.35892885923385998,-0.32424020767211997,-0.30196183919906999,-0.29289975762366999,-0.28494867682456998,-0.27768221497536,-0.27270755171776001,-0.27099794149398998,-0.24497985839844,-0.19227698445319999,-0.14611047506332001,-0.10783828794956,-0.075162455439567996,-0.048143774271010999,-0.025990724563599001,-0.0087778270244598007,0.0058640963397920002,0.017891164869070001,0.029984891414642001,0.041670925915240999,0.068852864205837,0.11332379281521,0.15035721659660001,0.17861454188824,0.20369651913643,0.22568178176879999,0.246745839715,0.26720127463340998,0.28254634141922003,0.29234895110129999,0.30117917060852001,0.30911791324615001,0.31931743025780002,0.33225423097610002,0.34160447120666998,0.34690526127815002,0.35119393467902998,0.35459071397781,0.35733696818352001,0.35946550965308999,0.36080554127692999,0.36132508516312001,0.36149725317955,0.36133465170860002,0.36125895380973999,0.36143428087233997,0.35923945903777998,0.35451427102089,0.34743916988373003,0.33799853920937001,0.32613638043403997,0.31161472201347001,0.29912483692169001,0.28934308886527998,0.27503272891045,0.25554612278937999,0.23427931964397,0.2108369320631,0.19555811583996,0.18955811858176999,0.18541157245636,0.18278098106384,0.18047206103801999,0.17845976352692,0.17553128302097001,0.17196805775165999,0.16097895801067,0.14148603379725999,0.12304488569498,0.10590543597936999,0.096000783145427995,0.093958541750907995,0.097773030400276004,0.10777878761291999,0.11732273548841,0.12598595023154999,0.13279861211777,0.13772617280482999,0.13900813460350001,0.13601160049437999,0.13613890111446,0.13989357650279999,0.14754359424114,0.15888510644435999,0.17896600067616,0.20922978222370001,0.23419834673404999,0.25255751609802002,0.26651331782340998,0.27609172463416998,0.28107729554175997,0.28074193000793002,0.28533226251602001,0.29580512642860002,0.31018716096878002,0.3282553255558,0.35295495390892001,0.38563823699951,0.41065317392348999,0.42627760767937001,0.43835979700089001,0.44712254405022001,0.45421913266182001,0.45960435271263,0.46628600358963002,0.47457087039947998,0.48404836654663003,0.49464315176009999,0.50793975591660001,0.52501660585402998,0.53333193063735995,0.53117394447327004,0.52625805139542003,0.51918506622313998,0.50925016403197998,0.49582427740097001,0.48704019188880998,0.48404997587204002,0.48187208175659002,0.48007357120513999,0.47999721765518,0.48284479975700001,0.47432008385657998,0.45202314853668002,0.42856669425964,0.40509241819382003,0.38086262345313998,0.35608428716660001,0.32864028215407998,0.29800841212272999,0.26797845959663003,0.23898813128471,0.21007630228995999,0.18117675185203999,0.15228344500065,0.12321731448174,0.096145160496235005,0.071612723171710996,0.046187262982130002,0.019936840981244999,-0.012048229575157001,-0.051006153225898999,-0.089262232184409998,-0.12602677941321999,-0.16180820763111001,-0.19672834873198999,-0.22915056347846999,-0.25895199179648998,-0.28514802455902,-0.30697518587111999,-0.33123373985290999,-0.35853925347327997,-0.39063310623169001,-0.42863100767135998,-0.46377059817313998,-0.49537897109985002,-0.52051383256911998,-0.53875005245208996,-0.54959833621979004,-0.55237609148026001,-0.55249857902527,-0.54949927330017001,-0.55471354722976995,-0.56992757320403997,-0.59166145324706998,-0.62074643373489002,-0.64673954248428001,-0.66939717531204002,-0.67795670032500999,-0.67011427879332996,-0.65407437086105003,-0.62970030307769997,-0.60614126920699996,-0.58381772041321001,-0.57093870639801003,-0.56946843862534002,-0.57168000936508001,-0.57711076736449995,-0.58321917057036998,-0.59163767099380005,-0.581598341465,-0.54824733734131004,-0.51216572523116999,-0.47500565648079002,-0.44275483489036999,-0.41595882177353,-0.39985939860344,-0.39645048975945002,-0.39459404349326999,-0.39298397302628002,-0.39238595962523998,-0.39559715986251998,-0.37445470690727001,-0.32130521535873002,-0.27211326360702998,-0.23143422603607,-0.19710560142993999,-0.16834303736687001,-0.15532463788986001,-0.16165339946747001,-0.16761133074760001,-0.17067390680312999,-0.17155024409294001,-0.17196813225745999,-0.15319387614727001,-0.10895222425461,-0.071612194180489003,-0.045957185328007001,-0.026829749345778999,-0.013328470289707,-0.01229212526232,-0.026732752099632998,-0.038761224597691997,-0.045897983014583997,-0.048585049808024999,-0.047232747077941999,-0.035357661545277003,-0.0096115171909331998,0.0097100147977471005,0.019453957676888001,0.022182904183864999,0.018319053575396999,0.0035759792663156999,-0.025165019556880001,-0.046940200030804,-0.058071039617061997,-0.063584454357623998,-0.063972979784011993,-0.057677235454320998,-0.042857609689236,-0.033079139888287,-0.030466625466942999,-0.034583702683449,-0.045745033770799998,-0.063716962933539997,-0.090614974498749001,-0.108947083354,-0.11504583805799,-0.11615609377623,-0.11288533359766,-0.10645481944084,-0.096301175653934007,-0.089217580854892994,-0.086216539144516005,-0.088458657264709001,-0.096937775611876997,-0.10681860893965001,-0.11840327084063999,-0.12344904243946,-0.12032891064881999,-0.11010331660509,-0.091837309300900005,-0.072416312992573006,-0.052253458648919997,-0.037107449024916001,-0.028490394353867,-0.023595156148075998,-0.022770417854190001,-0.020956965163350001,-0.017528865486383001,-0.01055976562202,-0.00019129831343889001,0.018537949770689,0.048251286149024998,0.076195865869521998,0.10033541917801,0.12006805092096,0.13446900248527999,0.14744038879870999,0.15926378965377999,0.17254573106766,0.18780831992625999,0.20500254631042,0.22338148951530001,0.2495296895504,0.28698742389678999,0.31854751706123002,0.34062540531157998,0.35765278339385997,0.36960339546204002,0.37945577502250999,0.38728204369545,0.3968853354454,0.40912228822708002,0.42335635423660001,0.43914434313773998,0.46007284522057001,0.48879724740982,0.51108700037002996,0.52343273162841997,0.53226220607758001,0.53830021619796997,0.54236787557601995,0.54418903589249001,0.54767876863480003,0.55397129058838002,0.56069040298462003,0.56751114130019997,0.57457262277603005,0.58307909965515003,0.58432620763778997,0.57533901929855003,0.56476908922195002,0.55410325527190996,0.54301214218140004,0.53089773654937999,0.52294039726257002,0.52103257179259999,0.51952093839644997,0.51738876104355003,0.51522952318191995,0.51464772224426003,0.50431162118911999,0.47968673706054998,0.45562955737114003,0.43515512347221003,0.41624709963799,0.39889228343964001,0.38296693563460998,0.36839318275451999,0.35558998584746998,0.34510123729705999,0.33411315083504001,0.32287418842316001,0.30566903948784002,0.27956742048263999,0.25526559352875,0.23524995148182001,0.21691030263901001,0.19996595382689999,0.18456336855888,0.17065730690955999,0.15865936875343001,0.14940053224564001,0.13822822272777999,0.12441939115524001,0.10591808706522,0.080565668642521002,0.058321796357632003,0.041869841516017997,0.027535906061529999,0.014727171510457999,0.0040550651028751997,-0.0041373251006007004,-0.011492257006466,-0.017857007682323001,-0.026424404233694,-0.038150995969771999,-0.052046630531549003,-0.068795166909695005,-0.083420202136039998,-0.094214960932732003,-0.10460962355137,-0.11529043316841001,-0.12584984302520999,-0.13646267354488001,-0.14597107470036,-0.15365995466709001,-0.16227243840694,-0.17265014350414001,-0.18337385356426,-0.19444565474986999,-0.20434606075287001,-0.21236807107924999,-0.22040832042694,-0.22901876270770999,-0.23723284900187999,-0.24488201737404,-0.25188964605330999,-0.25786611437798002,-0.26488509774208002,-0.27365872263907998,-0.28289699554442999,-0.29236900806427002,-0.30193752050400002,-0.31094866991043002,-0.32298943400383001,-0.33999451994896002,-0.35575389862061002,-0.36878821253777,-0.37951469421387002,-0.38737446069717002,-0.39498475193977001,-0.40323618054389998,-0.41062295436858998,-0.41667649149894997,-0.42234101891518,-0.42694696784018998,-0.43565326929092002,-0.45128771662711997,-0.46531364321709001,-0.4753557741642,-0.48370292782784002,-0.49030944705009,-0.49705508351326,-0.50483953952788996,-0.51150780916214,-0.51618993282318004,-0.52103328704833995,-0.52609193325043002,-0.53397440910339,-0.54687076807021995,-0.55673211812973,-0.56088995933533004,-0.56309437751769997,-0.56409764289856001,-0.56337308883667003,-0.56030291318893,-0.55811059474945002,-0.55773752927779996,-0.55869990587233997,-0.56095349788666005,-0.56498050689696999,-0.57229524850845004,-0.57526212930678999,-0.57094651460648005,-0.56416571140288996,-0.55601489543914995,-0.54575282335280995,-0.53244268894196001,-0.52097421884536999,-0.51335680484771995,-0.50599610805510997,-0.49809971451759,-0.48983517289161999,-0.48171633481978998,-0.47054037451744002,-0.45506393909454002,-0.43702259659767001,-0.41646248102187999,-0.39483466744423001,-0.37190827727317999,-0.35145252943039001,-0.33541360497474998,-0.31959345936775002,-0.30294468998909002,-0.28572559356688998,-0.26824668049812,-0.24842403829098,-0.22577756643294999,-0.19946202635765001,-0.16802698373795,-0.13709633052348999,-0.10759396851062999,-0.083071634173393,-0.066221758723259,-0.049883868545294002,-0.031984563916921997,-0.013495161198080001,0.0054832138121128004,0.025576762855053,0.046596899628638999,0.070631161332130002,0.099631026387214994,0.12700703740120001,0.15075895190239,0.17149810492991999,0.18851619958877999,0.2047029286623,0.22082449495792,0.23732113838196001,0.25450411438942,0.27220040559768999,0.29026204347610002,0.30955940485000999,0.33175206184387002,0.34982731938361999,0.36092314124107,0.36866953969001998,0.37344712018967002,0.37710008025169001,0.37998586893081998,0.38384926319121998,0.38953867554665,0.39618372917174999,0.40367585420608998,0.41188588738441001,0.4218056499958,0.42816409468651001,0.42838853597641002,0.42676910758018,0.42431116104125999,0.42136216163634999,0.41826242208481001,0.41480752825737,0.41083896160125999,0.40706166625022999,0.40372261404991,0.40080174803733998,0.39911675453186002,0.39481747150420998,0.38572746515273998,0.37626114487647999,0.36778977513312999,0.35961857438087003,0.35150423645973,0.34458392858504999,0.33954596519469998,0.33490696549415999,0.33018499612808,0.32566335797309998,0.32166790962219,0.31671825051308,0.30998912453651001,0.30303287506103999,0.29635682702065003,0.28963291645049999,0.28287467360496998,0.27584341168403997,0.26818853616714,0.26113474369049,0.25509041547775002,0.25002408027648998,0.24581652879714999,0.24336528778076,0.24360747635364999,0.24368606507778001,0.2423954308033,0.24097196757792999,0.23967359960078999,0.23851618170738001,0.23760110139846999,0.23668321967125,0.23535726964473999,0.23512436449528001,0.23653055727482,0.23950754106045,0.24479581415653001,0.24933190643787001,0.25163713097571999,0.25349825620651001,0.25544118881226002,0.25708431005478,0.2584076821804,0.25918552279472001,0.2584782242775,0.26012337207794001,0.26598355174065003,0.27401429414749001,0.28495737910271002,0.29329133033751997,0.29647096991539001,0.29632452130317999,0.2928010225296,0.28729692101478999,0.27984741330147,0.27282643318175998,0.26722428202629001,0.26310414075851002,0.26115292310714999,0.25931113958358998,0.25711515545844998,0.25345450639724998,0.24897578358649999,0.23823595046997001,0.21691644191741999,0.19431550800799999,0.17308314144611001,0.15544568002223999,0.14453794062138001,0.13304316997528001,0.11752316355705,0.10186453908682,0.087019115686417001,0.073433861136436004,0.064339622855186004,0.047156140208243998,0.013009954243898,-0.020770400762558001,-0.047705061733722999,-0.070335723459721,-0.086656503379344996,-0.10470647364855,-0.12939177453518,-0.15322454273701,-0.17319950461388001,-0.19193950295448001,-0.20790262520312999,-0.23034431040287001,-0.26717555522919001,-0.30105397105217002,-0.32395786046982,-0.34334436058998002,-0.35988569259643999,-0.37834894657134999,-0.40303611755370999,-0.42546299099922003,-0.44129231572151001,-0.45604994893074002,-0.47088277339934997,-0.48807647824286998,-0.51105505228043002,-0.53081780672072998,-0.54263377189635997,-0.55172282457351995,-0.55955576896667003,-0.56613051891327004,-0.57186138629912997,-0.57625573873519997,-0.57890456914902,-0.58089083433151001,-0.58259445428848,-0.58425438404082997,-0.58687192201614002,-0.58706998825072998,-0.58262157440186002,-0.57692497968673995,-0.57138967514037997,-0.56503570079803001,-0.55800044536590998,-0.54896545410155995,-0.53681075572967996,-0.52362573146820002,-0.51024591922759999,-0.49643671512603998,-0.48204863071442,-0.46794509887695002,-0.45478275418281999,-0.44148361682892001,-0.42755895853043002,-0.41340583562851002,-0.39925870299339,-0.38454216718674,-0.36887568235397,-0.35284110903740001,-0.33666488528251998,-0.32027676701545998,-0.30364042520522999,-0.28695347905159002,-0.27032816410065003,-0.25368583202361999,-0.23709288239479001,-0.22022527456284,-0.20300498604774,-0.18512539565562999,-0.16594429314136999,-0.14732117950915999,-0.13008198142051999,-0.11417522281408,-0.099676288664341001,-0.086897507309913996,-0.076302990317344999,-0.066781580448150996,-0.058259498327970997,-0.049149043858051002,-0.03836078569293,-0.026845492422581,-0.014525465667247999,-0.0027301041409373001,0.0076175765134394004,0.017462534829974001,0.027229759842157,0.036423601210117,0.044961191713810002,0.052485037595034,0.058206938207149998,0.064381822943686995,0.072351761162280995,0.080933727324008997,0.090157553553581002,0.098592177033424003,0.10515570640564,0.11106671392917999,0.11683700978755999,0.12211185693741,0.12675909698009,0.13094989955424999,0.13377758860587999,0.13898721337318001,0.14955431222915999,0.16120593249797999,0.17231503129004999,0.18264400959015001,0.19153437018394001,0.19959746301174,0.20718958973884999,0.21368278563022999,0.21869824826716999,0.22259737551212,0.22391420602798001,0.22868126630783001,0.24215026199817999,0.25608989596366999,0.26644307374954002,0.27542287111281999,0.28266176581383001,0.29079130291938998,0.30209827423095997,0.31332176923751998,0.32256028056144997,0.33186256885528997,0.34104517102241999,0.35361787676811002,0.37400844693183999,0.39314138889312999,0.40568965673446999,0.41563329100608998,0.42386016249656999,0.43110451102257002,0.43836495280266002,0.44429132342339001,0.44745343923568998,0.45103958249092002,0.45626702904701,0.46441856026648998,0.47875827550888,0.49113643169402998,0.49609369039536,0.49861770868300997,0.50048059225081998,0.50140976905822998,0.50154507160187001,0.50131487846375,0.50111007690429998,0.50057107210159002,0.49948418140410999,0.49817502498626998,0.49702256917953003,0.49519518017768999,0.49254664778709001,0.48808664083481001,0.48090648651123002,0.47193312644958002,0.46040847897530002,0.45036146044731001,0.44549933075905002,0.44082677364348999,0.43366479873656999,0.42567077279090998,0.41708374023438,0.40845787525177002,0.40168282389641002,0.39143565297126998,0.37317693233490001,0.35272255539893999,0.33162075281143,0.31357097625732,0.30366292595862998,0.29353570938110002,0.27781799435616,0.26101902127266002,0.2443800419569,0.22909308969975001,0.21808174252509999,0.20480540394783001,0.18389441072941001,0.16187711060047,0.14153781533241,0.12335613369942,0.11024241149426001,0.095506794750690002,0.073591515421866996,0.051123071461915998,0.031291499733924998,0.013365802355110999,-0.00074162986129521998,-0.016609549522399999,-0.039547331631183999,-0.062310423702002002,-0.080839298665524001,-0.097080007195472995,-0.11041831225157001,-0.12394312024117,-0.14054287970066001,-0.15688194334507,-0.17091269791125999,-0.18445417284966001,-0.19793093204498,-0.21234677731991,-0.22959686815739,-0.24588921666145,-0.25846874713897999,-0.2695409655571,-0.27986738085746998,-0.28960314393044001,-0.29913634061812999,-0.30818334221839999,-0.31662791967392001,-0.32454061508179,-0.33211377263068997,-0.33875072002411,-0.34357842803000999,-0.34831893444061002,-0.35433042049407998,-0.36034077405929998,-0.36583814024924999,-0.37071430683135997,-0.37418866157531999,-0.37819093465804998,-0.38448312878608998,-0.39106646180152999,-0.39700233936309998,-0.40220531821250999,-0.40641203522682001,-0.40945824980736001,-0.41094362735748002,-0.41157749295235002,-0.41176611185074002,-0.41150915622710998,-0.41040450334549,-0.41017013788223,-0.41286793351173001,-0.41544738411902998,-0.41586923599242998,-0.41530784964561002,-0.41372859477996998,-0.41230064630508001,-0.41266757249831998,-0.41221547126769997,-0.40901118516922003,-0.40449208021164001,-0.39913028478621998,-0.39317414164543002,-0.38702636957169001,-0.38040149211884,-0.37333050370215998,-0.36536687612534002,-0.35637724399567,-0.34571054577826998,-0.33233225345612,-0.31789532303809998,-0.3037956058979,-0.28865891695022999,-0.27182209491729997,-0.25326475501059997,-0.23156723380089,-0.21072252094746,-0.19447436928749001,-0.17940129339694999,-0.16365000605582999,-0.14800329506397,-0.13173858821392001,-0.11750826984644,-0.10858425498009,-0.10043562948704,-0.089941099286079004,-0.078638643026351998,-0.065984405577183006,-0.054818987846374997,-0.048567242920398997,-0.042957548052072997,-0.034968443214893001,-0.026493944227695,-0.017644159495831001,-0.010176111012697,-0.0067158965393901001,-0.0034696101211011002,0.0025316767860203999,0.0091856233775616004,0.016123175621032999,0.021794835105538,0.023449514061213001,0.025505075231194,0.031857483088969997,0.039077389985323001,0.045513384044169998,0.051045306026936001,0.054251741617918001,0.057807702571154002,0.064402937889098996,0.071225136518478005,0.076584532856941001,0.080905467271805004,0.083253167569636993,0.086139753460883997,0.092303566634654999,0.098895117640494995,0.10412286967039,0.10860253125428999,0.11189039051532999,0.11535399407148,0.12054087221621999,0.12583278119564001,0.12994919717312001,0.13401354849339001,0.13781614601611999,0.14384618401527,0.15561290085316001,0.16866026818752,0.17943142354488001,0.19027028977870999,0.20156146585941001,0.21512216329575001,0.23395714163779999,0.25401958823204002,0.27134168148040999,0.29004898667335999,0.31154832243919001,0.33903500437737,0.38080126047134,0.42123353481293002,0.44616097211838002,0.46428045630455,0.47933712601661999,0.49029296636580999,0.49635934829711997,0.50067853927612005,0.50634914636612005,0.51181328296660999,0.51666706800461004,0.52077525854110995,0.52428930997848999,0.52597367763518998,0.52450478076935003,0.52061963081359997,0.51447784900664995,0.50639146566391002,0.49617376923561002,0.48543652892112998,0.47645151615143,0.46666181087494002,0.45396351814269997,0.43970778584480003,0.42381638288498003,0.40834459662437,0.39670446515083002,0.38431107997893998,0.36699938774108998,0.34759184718132002,0.32689777016639998,0.30652707815169999,0.28953391313553001,0.27209877967834001,0.25093466043472001,0.22791495919228,0.20381760597229001,0.17851080000401001,0.15256482362747001,0.12463679164648001,0.092593483626841999,0.059502996504307001,0.027574166655540001,-0.0029407581314445002,-0.030316952615976001,-0.056815333664417003,-0.084248781204223994,-0.11214433610438999,-0.14060135185719,-0.16972084343433,-0.23149538040161,-0.23034663498402,-0.29392486810683999,-0.31867086887360002,-0.34931796789169001,-0.37392130494117998,-0.39646255970000999,-0.41680151224135997,-0.43535712361335999,-0.45249918103218001,-0.46824803948402,-0.48282334208487998,-0.49600407481193998,-0.50743412971497004,-0.51772284507750999,-0.52752470970153997,-0.53639125823974998,-0.54428273439407004,-0.55060762166976995,-0.55392938852310003,-0.55665266513823997,-0.56144517660141002,-0.56634896993636996,-0.57033181190491,-0.57311755418777,-0.57393145561217995,-0.57315325737,-0.57074892520904996,-0.56720787286758001,-0.56309539079666004,-0.55823642015456998,-0.55223572254180997,-0.54628831148148005,-0.54203444719314997,-0.53799831867217995,-0.53295326232910001,-0.52754187583922996,-0.52294158935546997,-0.51646727323532005,-0.50430119037627996,-0.49032625555991999,-0.47771808505058,-0.46558198332786999,-0.45423623919487,-0.44318950176239003,-0.43168249726294999,-0.42068895697594,-0.41124877333641002,-0.40266966819763,-0.39477950334549,-0.38693505525589,-0.37790003418922002,-0.36900836229324002,-0.36171841621398998,-0.35482910275459001,-0.34794539213181003,-0.33983686566353,-0.32766020298004001,-0.31521430611610002,-0.30661892890929998,-0.29940515756607,-0.29220315814018,-0.28520214557647999,-0.27752944827080001,-0.27087906002998002,-0.26717326045036,-0.26554894447326999,-0.26550054550170998,-0.26765504479407998,-0.27325150370598,-0.28028330206870999,-0.28641784191132003,-0.29296982288361001,-0.30064743757248003,-0.30933910608291998,-0.32013344764709001,-0.33029955625534002,-0.33601063489914001,-0.34016871452331998,-0.3451052904129,-0.34987798333168002,-0.35431084036826999,-0.35820570588112,-0.36103388667107,-0.36343863606452997,-0.36615857481955999,-0.36871868371964001,-0.37100902199745001,-0.37251272797585,-0.37319600582123003,-0.37127032876014998,-0.36352840065955999,-0.35285803675652,-0.34111833572388001,-0.32954683899879,-0.32166957855224998,-0.31382614374161,-0.30177837610245001,-0.28858721256255998,-0.27630615234375,-0.26521575450897,-0.25802099704741999,-0.25032901763915999,-0.23605036735535001,-0.21983614563942,-0.20527002215385001,-0.19201269745826999,-0.18216738104819999,-0.17255263030529,-0.15894962847232999,-0.14421093463897999,-0.13059885799884999,-0.11729897558688999,-0.10555768758059,-0.091483801603316997,-0.068293124437332001,-0.042360737919806997,-0.02017904818058,0.00094855204224585999,0.020522395148873,0.042470932006836,0.074405662715435,0.10880419611931,0.13752384483814001,0.16435158252716001,0.18994224071502999,0.21721623837948001,0.25297066569327997,0.28975674510001997,0.31870865821838001,0.34466943144798001,0.36997887492179998,0.39607137441634999,0.42841359972954002,0.45981487631798001,0.48090198636054998,0.49707052111625999,0.51200079917908004,0.52507531642913996,0.53697055578232,0.54761958122252996,0.55693817138671997,0.56566894054412997,0.57486146688461004,0.58431667089462003,0.59534156322479004,0.60481190681457997,0.60781824588776001,0.60750895738601995,0.60658156871795998,0.60401707887650002,0.59960007667542004,0.59308981895446999,0.58414119482039994,0.57255083322525002,0.55759662389755005,0.54007488489151001,0.51997095346451006,0.49952188134192999,0.48349210619925997,0.46752044558525002,0.44641327857971003,0.42289501428603998,0.39820808172226002,0.37358531355857999,0.35200792551040999,0.33157837390900002,0.31061407923697998,0.28970041871071001,0.26889067888259999,0.24841013550758001,0.22874960303306999,0.20952168107033001,0.1903575360775,0.17129580676556,0.15235947072506001,0.13322298228741,0.11301825940609,0.092808254063128995,0.074058741331100006,0.056046191602945002,0.038271583616734002,0.020883094519377001,0.0037700310349464,-0.012753160670400001,-0.028045833110809,-0.042689889669418002,-0.057351648807526003,-0.071842730045319006,-0.086426131427288,-0.10041964799166,-0.11300718039274001,-0.12393067777157001,-0.13221742212772,-0.13846501708031,-0.14347922801971,-0.14642052352428001,-0.14606864750385001,-0.14317125082016,-0.13825832307339,-0.13155496120453,-0.12361609190702,-0.11449831724167001,-0.10399270802736001,-0.093507140874863004,-0.085615076124667996,-0.079084977507590998,-0.073108814656733995,-0.067735783755779003,-0.062496412545442998,-0.057895898818969997,-0.054792352020741002,-0.052483040839434003,-0.050199519842863,-0.048035651445389002,-0.045723017305135998,-0.043461211025714999,-0.041430432349442999,-0.039673782885074997,-0.038326870650052997,-0.037424195557833002,-0.036561761051416002,-0.037074934691190997,-0.041748881340027001,-0.048518724739552002,-0.055037587881088,-0.061934854835272002,-0.068188369274139002,-0.076342336833477006,-0.091789916157722001,-0.11021831631660001,-0.12626831233501001,-0.14173230528830999,-0.15690824389458,-0.17241449654102001,-0.19009435176848999,-0.20818231999874001,-0.22408519685268,-0.23904848098754999,-0.25366702675818997,-0.26872298121451998,-0.28697317838669001,-0.30545011162758001,-0.31971472501754999,-0.33151876926422003,-0.34198510646820002,-0.35064136981964,-0.35682845115661999,-0.36144602298737,-0.36575317382812,-0.36969733238219998,-0.37372207641602001,-0.37794756889343001,-0.38316082954406999,-0.38843953609467002,-0.39240729808807001,-0.39542606472969,-0.39751487970352001,-0.39860227704048001,-0.39823621511459001,-0.39723971486092002,-0.39719769358634999,-0.39723908901214999,-0.39655229449272,-0.39518219232558999,-0.39280334115027998,-0.38948625326156999,-0.38550516963004999,-0.38010644912719999,-0.37176927924156,-0.36123734712601002,-0.34899559617043002,-0.33536446094513001,-0.32220202684402,-0.30691552162169999,-0.28447717428206998,-0.25787302851677002,-0.22964167594910001,-0.20101307332516,-0.17727072536944999,-0.15391442179680001,-0.12370043992995999,-0.090353153645992001,-0.057019773870707002,-0.024337057024240001,0.0028388984501361999,0.029838116839528001,0.066427811980246998,0.10724461078644,0.14666959643364,0.18543130159377999,0.22078311443328999,0.25619345903397001,0.29875624179839999,0.34384632110595997,0.38568362593651001,0.42538639903068998,0.46034285426139998,0.49524927139281999,0.54091680049895996,0.58979225158690995,0.63146793842315996,0.66881966590881003,0.70129144191741999,0.73137533664703003,0.76524418592453003,0.79889887571335005,0.82668364048003995,0.85079318284988004,0.87231475114821999,0.89228624105453003,0.91475683450698997,0.93615424633026001,0.95027524232864002,0.95991533994675005,0.96729141473769997,0.97300326824187999,0.98075801134108997,0.98714405298232999,0.98598474264144997,0.98017311096190995,0.97269999980927002,0.96295756101607999,0.95121145248412997,0.93739962577820002,0.92139828205108998,0.90355557203293002,0.88463580608367998,0.86436378955840998,0.84281104803085005,0.81939500570296997,0.79227477312088002,0.76305162906646995,0.73427772521973,0.70552206039429,0.67859148979187001,0.65019780397414995,0.61213088035582996,0.56974345445633001,0.53102135658264005,0.49369752407074002,0.45834589004517001,0.42195561528205999,0.37631961703299999,0.32652533054352001,0.27998507022857999,0.23475146293640001,0.19045245647430001,0.14705693721770999,0.10375122725964001,0.061920829117298001,0.024818088859319999,-0.0091610103845596001,-0.041605606675148003,-0.072956353425980003,-0.10604349523782999,-0.13841590285301,-0.16504096984863001,-0.18860445916652999,-0.21251909434794999,-0.23646524548531,-0.26268428564071999,-0.28845599293709001,-0.30737003684044001,-0.32305917143821999,-0.3405567407608,-0.35913431644440003,-0.38115134835242998,-0.40347754955291998,-0.41859585046768,-0.43054214119911,-0.44493782520294001,-0.46067205071449002,-0.47941955924034002,-0.49832820892334001,-0.51016581058501997,-0.51872026920319003,-0.52940714359283003,-0.54087489843368997,-0.55355280637741,-0.56587111949920998,-0.57351386547089001,-0.57865560054778997,-0.58440625667571999,-0.58991360664367998,-0.59512329101562,-0.59937649965286,-0.60109758377074995,-0.60036599636078003,-0.59610545635223,-0.58923697471618997,-0.58120155334473,-0.57229447364806996,-0.56491547822952004,-0.55700826644896995,-0.54392421245574996,-0.52801185846329002,-0.51234501600266003,-0.49700966477393999,-0.48535624146460998,-0.47406440973281999,-0.45514634251594999,-0.43260031938553001,-0.41211321949959001,-0.39298155903816001,-0.37788200378418002,-0.36385905742645003,-0.34334635734558,-0.32036840915679998,-0.30128267407416998,-0.2848108112812,-0.27208957076072998,-0.26122921705245999,-0.24689291417598999,-0.23195983469486001,-0.22127324342728,-0.21354652941227001,-0.20840470492839999,-0.20536401867866999,-0.202711597085,-0.20116704702377,-0.20179830491542999,-0.20417585968971,-0.20743770897388,-0.21232287585734999,-0.22108986973763001,-0.23194947838783,-0.24100929498672,-0.24945138394833,-0.25801053643227001,-0.26702725887299,-0.27878934144973999,-0.29110977053642001,-0.29862242937088002,-0.30337035655974998,-0.3077572286129,-0.31167110800742998,-0.31679287552834001,-0.32169431447982999,-0.32308757305145003,-0.32200506329535999,-0.31943920254706998,-0.31519719958304998,-0.30887511372566001,-0.30133798718451998,-0.29528510570526001,-0.28946253657340998,-0.28173226118088002,-0.27270364761353,-0.26258429884911,-0.25189995765686002,-0.24275767803192,-0.23394599556922999,-0.22295819222926999,-0.21062803268433,-0.19761349260807001,-0.18436588346957999,-0.17300644516944999,-0.16244831681252,-0.15064069628716001,-0.13812693953513999,-0.12505599856377,-0.11185598373413,-0.10034749656916001,-0.089386828243731994,-0.076393060386181003,-0.062216397374867997,-0.047820523381233,-0.033141106367110998,-0.018900610506535,-0.0043339990079403002,0.012768849730492001,0.031483273953198998,0.050460871309041998,0.069647595286369005,0.087508454918861001,0.10529176890850001,0.12648789584636999,0.14951890707016,0.17161758244038,0.19317395985126001,0.21309761703013999,0.23269529640674999,0.25623223185539001,0.28152334690094,0.30412358045577997,0.32498794794083002,0.3438429236412,0.36177411675452997,0.38278672099112998,0.40493535995482999,0.42428946495056002,0.44174921512603998,0.45739498734473999,0.47193676233291998,0.48826995491982,0.50492590665817005,0.51867038011551003,0.53044426441193004,0.54109346866607999,0.55091202259063998,0.56191146373749001,0.57283365726471003,0.58050489425659002,0.58588534593581998,0.59011018276214999,0.59314054250716997,0.59574735164642001,0.59743320941925004,0.59669756889342995,0.59434252977371005,0.59212458133697998,0.58982264995574996,0.58864307403563998,0.58692020177840998,0.57884860038757002,0.56680518388748002,0.55528092384338001,0.54358792304992998,0.53288251161574995,0.52175807952881004,0.50528055429458996,0.48561540246009999,0.46729347109795,0.44945079088210999,0.43305957317352001,0.41601568460464,0.39005899429321,0.35893607139587003,0.33108407258986999,0.30450099706650002,0.27821043133736001,0.25099852681160001,0.21639782190323001,0.17802277207375,0.14547391235828,0.11609175801277,0.087043836712836997,0.057673174887896,0.022619269788264999,-0.015280243009329,-0.048551436513661998,-0.079278096556663999,-0.10996716469525999,-0.14083607494830999,-0.17534783482551999,-0.21115541458129999,-0.24099013209343001,-0.26723733544349998,-0.29405879974365001,-0.32092040777205999,-0.34934774041175998,-0.37764912843704002,-0.39959380030632002,-0.41749823093414001,-0.43602907657623002,-0.45462363958358998,-0.47507604956626998,-0.49560803174973,-0.50959050655365001,-0.51963049173355003,-0.53163093328475997,-0.54447138309479004,-0.55816197395324996,-0.57185190916061002,-0.58198797702788996,-0.58956688642501998,-0.59612196683884,-0.60144358873366999,-0.60552418231964,-0.60860854387283003,-0.61214625835419001,-0.61522412300109997,-0.61481708288193004,-0.61187022924422996,-0.60812717676162997,-0.60342305898666004,-0.59889233112335005,-0.59330970048903997,-0.58169162273407005,-0.56593149900436002,-0.55016511678696001,-0.53426522016525002,-0.52171248197555997,-0.51006090641021995,-0.49031883478165,-0.46569004654884,-0.44328123331070002,-0.42244994640349998,-0.40690028667450001,-0.39352664351463001,-0.37023040652275002,-0.34114924073219,-0.31569191813469,-0.29250052571297003,-0.27351528406143,-0.25620865821838001,-0.22943031787872001,-0.19738763570786,-0.17098046839236999,-0.14822557568549999,-0.12895388901234001,-0.11150050908327,-0.087253853678703003,-0.059475485235452999,-0.037020239979029,-0.018013522028923,-0.00081977434456347996,0.015350807458162001,0.036034487187862001,0.058949369937181001,0.077320083975792001,0.092681139707565002,0.10698642581701,0.12047632038592999,0.13596349954605,0.15237081050873,0.16650001704692999,0.17920443415642001,0.19212600588799,0.20518577098846,0.21943992376328,0.23427554965019001,0.24738898873328999,0.25941127538681003,0.27171692252159002,0.28408718109130998,0.29632937908173002,0.30860236287116999,0.32157257199286998,0.33513671159744002,0.34925895929336997,0.36397197842598,0.37974405288696,0.39604973793030002,0.41044449806213001,0.42356142401695002,0.43684589862822998,0.44995424151420998,0.46225398778915,0.47372087836266003,0.48362508416175998,0.49231821298598999,0.50105923414230003,0.509621322155,0.51785737276077004,0.52566111087798995,0.53251796960830999,0.53835141658783003,0.54220372438430997,0.54445534944534002,0.54629713296890003,0.54764002561569003,0.54897743463516002,0.55010962486267001,0.55036056041717996,0.54986220598221003,0.54887384176253995,0.54728662967681996,0.54463833570480003,0.54107284545898005,0.53704869747161998,0.53246593475341997,0.52717858552932995,0.52112323045731002,0.51320034265518,0.50445139408112005,0.50037145614624001,0.49936854839325001,0.49687904119491999,0.49341997504233998,0.48812898993491999,0.48168760538101002,0.47761979699134999,0.47478315234183999,0.46928337216376997,0.46180453896522999,0.45296934247017001,0.44319853186607,0.43575817346572998,0.42955306172370999,0.42060434818268,0.40971007943152998,0.39821872115134999,0.38636139035224998,0.37695306539536,0.36891159415245001,0.35788607597351002,0.34471690654754999,0.33079200983047002,0.31632405519485002,0.30443924665451,0.29355031251906999,0.27589121460915,0.25337731838226002,0.23131188750267001,0.20943148434162001,0.19111961126328,0.17454463243484,0.15027242898941001,0.12078659236431,0.093917533755301999,0.068976357579230999,0.048383496701717002,0.030732674524188,0.0087258340790867996,-0.015925286337733002,-0.038125917315483003,-0.058437265455723003,-0.075613766908646005,-0.091100022196770006,-0.11416761577129,-0.14223337173462,-0.16576007008553001,-0.18610394001007,-0.20450310409069,-0.22122988104819999,-0.23919656872749001,-0.25748485326767001,-0.27216827869415,-0.28397572040558,-0.29442322254181003,-0.30370041728019997,-0.31457212567329002,-0.32620355486870001,-0.33515590429306003,-0.34190946817397999,-0.34707614779472001,-0.35059317946433999,-0.35218808054924,-0.35214334726334001,-0.35229417681693997,-0.35232514142990001,-0.35167020559311002,-0.35020282864571001,-0.34619519114494002,-0.34037181735039002,-0.33702573180199003,-0.33499476313590998,-0.32957807183266002,-0.32110393047333002,-0.30719593167304998,-0.28937155008316001,-0.27740657329558999,-0.26919621229172003,-0.25724551081656999,-0.24234838783741,-0.22350765764712999,-0.20209304988384,-0.18825258314609999,-0.17966917157173001,-0.16705222427845001,-0.15161803364754001,-0.13454878330230999,-0.11660068482161,-0.10512527823447999,-0.098248936235904999,-0.087391592562199,-0.073763057589531,-0.059395302087069002,-0.044701986014843001,-0.035108774900435999,-0.029111251235008,-0.019016349688172,-0.0060546603053808004,0.0064854314550757,0.0185671672225,0.026937305927277,0.032515320926904998,0.040069457143544998,0.048943027853966002,0.057689450681210001,0.066360101103783001,0.073780268430710005,0.080680735409260004,0.092681147158146002,0.10859970003366,0.1233337521553,0.13723668456078,0.14876858890056999,0.15859946608542999,0.17128187417984,0.18602184951305001,0.19975580275058999,0.21275657415390001,0.22458669543265999,0.23571974039078,0.25035986304282998,0.26755192875861999,0.28227278590201998,0.29509764909744002,0.30691510438919001,0.31783384084701999,0.32953238487244002,0.34169447422027999,0.35281762480736001,0.36311349272728,0.37327411770821001,0.38328808546066001,0.39380452036857999,0.40454241633415,0.41341421008110002,0.42064824700356002,0.42668065428733998,0.43145200610161,0.43462243676186002,0.43627142906188998,0.43692290782928001,0.43649989366531,0.43467634916306003,0.43148943781853,0.42693662643433,0.42112156748772001,0.41520315408706998,0.40894702076911998,0.40103650093079002,0.39154756069183,0.37981620430946,0.36622008681297002,0.35426551103592002,0.34341615438460998,0.33111622929572998,0.31757086515427002,0.30267998576164001,0.28663170337677002,0.27136167883873002,0.25658246874808999,0.24086847901344,0.22435088455676999,0.20711296796799,0.18931233882904,0.17285105586051999,0.15742994844913,0.14139427244663,0.12487809360027,0.10810219496489,0.090991273522377,0.072731114923953996,0.053451269865035997,0.033969562500714999,0.014188822358846999,-0.0061834272928535999,-0.027251539751886999,-0.050724692642689001,-0.076255001127720004,-0.10120745003223,-0.12580312788486001,-0.15043085813522,-0.17508715391158999,-0.20016869902611001,-0.22546976804732999,-0.24850809574127,-0.26971277594566001,-0.29222190380096003,-0.31582683324813998,-0.34106141328812001,-0.36749896407126997,-0.38984307646750999,-0.40883666276932001,-0.42944353818893,-0.45128718018531999,-0.47400277853012002,-0.49730378389358998,-0.51692432165145996,-0.53344416618347001,-0.55087023973464999,-0.56890511512756003,-0.58724874258041004,-0.60563904047011996,-0.62018334865570002,-0.63129019737243997,-0.64113712310791005,-0.64960587024688998,-0.65688365697860995,-0.66287571191787997,-0.66629379987716997,-0.66735786199570002,-0.66814947128295998,-0.66852259635925004,-0.66825252771377996,-0.66726970672607,-0.66469073295592995,-0.66040307283401001,-0.65146642923355003,-0.63833689689635997,-0.62513917684554998,-0.61175537109375,-0.60055166482925004,-0.59098112583160001,-0.57610392570496005,-0.55671143531799006,-0.53938156366348,-0.52375781536101995,-0.51081526279448997,-0.49975526332855003,-0.47711318731308,-0.44448798894882002,-0.4168062210083,-0.39319759607315002,-0.37245056033134,-0.35410472750664002,-0.32877218723297003,-0.29753783345222001,-0.27136135101317999,-0.24950581789017001,-0.22910250723362,-0.20976528525352001,-0.18070143461227001,-0.14337250590323999,-0.11570700258017,-0.096474297344685003,-0.078806594014167994,-0.062663599848747004,-0.040806915611028997,-0.014184251427650001,0.0048853536136448002,0.017307626083493,0.029921665787697001,0.042640246450900997,0.060355618596077,0.082317769527434997,0.097168013453483998,0.10569719225168001,0.11437215656042,0.12298753857613,0.13293343782424999,0.14390815794468001,0.15049779415131001,0.15309906005859,0.15575146675109999,0.15829254686832001,0.16051468253136,0.16238050162792,0.16295525431633001,0.16231477260589999,0.16140183806419001,0.16018791496754001,0.15885804593562999,0.15737833082676,0.15510103106499001,0.15205819904803999,0.14844252169132,0.14426447451114999,0.13979163765906999,0.13507649302482999,0.13210061192513001,0.13068363070488001,0.12757782638073001,0.12293133884668,0.11789737641811,0.11248859763145,0.10822762548923,0.10497363656759,0.099793903529643999,0.092844873666763,0.086099959909915993,0.07956799864769,0.075595453381538003,0.073994055390357999,0.070757851004600997,0.066054821014404005,0.061802491545676998,0.057982042431830999,0.055788774043321998,0.055108856409788,0.052882175892590998,0.049247909337282,0.046544179320335,0.044714111834764002,0.043784465640782998,0.043707683682442003,0.042582824826240998,0.040498085319995998,0.039310913532972003,0.038974523544312002,0.039317905902863,0.040300834923983002,0.039923783391713999,0.038261588662863,0.03688707575202,0.035763122141361001,0.034523345530033001,0.033163908869028001,0.031189316883683,0.028616815805435,0.025838896632195001,0.022853780537843999,0.019954260438680999,0.017127620056272001,0.013968805782497,0.010477845557034,0.0062405681237578002,0.0012688590213656,-0.0040965136140584998,-0.0098595116287470003,-0.016061592847109001,-0.022690705955028999,-0.028826568275689999,-0.034484609961510003,-0.039966367185116002,-0.045269526541233,-0.050232000648974998,-0.054880984127522001,-0.061861746013164999,-0.071122087538241993,-0.080039076507091994,-0.088634684681892006,-0.096786439418793002,-0.1045022085309,-0.11258946359157999,-0.12102982401848,-0.12800981104374001,-0.13354508578777,-0.13802161812781999,-0.14145290851593001,-0.14691874384879999,-0.15438985824585,-0.16069743037223999,-0.16585795581341001,-0.17091840505600001,-0.17588044703007,-0.18267384171486001,-0.19128718972205999,-0.19806303083897001,-0.20300871133803999,-0.20780403912067,-0.2124480009079,-0.21830849349499001,-0.22538763284683,-0.23096311092377,-0.23502820730209001,-0.24008688330649999,-0.24614031612873,-0.25477817654610002,-0.26602226495742998,-0.27456599473952997,-0.28037953376769997,-0.28616511821746998,-0.29192987084388999,-0.29854631423950001,-0.30604034662246998,-0.31074139475821999,-0.31260681152344,-0.31467822194098999,-0.31697529554366999,-0.31960862874985002,-0.32259699702263001,-0.32409372925758001,-0.32409036159514998,-0.32171222567558,-0.31694075465201998,-0.31046551465987998,-0.30227017402648998,-0.29463014006615001,-0.28760609030723999,-0.27821478247643,-0.26640358567237998,-0.25339135527611001,-0.23915043473243999,-0.22736519575118999,-0.21821916103363001,-0.20213624835013999,-0.17887355387211001,-0.15493907034397,-0.13034921884537001,-0.11058223247528,-0.095932006835938,-0.074250340461730999,-0.045171793550252998,-0.017535364255309001,0.0085610169917344995,0.02967331930995,0.045485537499189002,0.068960219621658006,0.10057461261749,0.12947264313698001,0.15546660125256001,0.17684370279312001,0.19330881536007,0.21662485599518,0.24733054637908999,0.27329206466674999,0.29420459270477001,0.31094956398009999,0.32326444983482,0.34273093938827998,0.36996787786483998,0.39202892780303999,0.40852105617522999,0.42185449600219999,0.43188038468361001,0.44616287946701,0.46516814827919001,0.47972378134727001,0.48948916792870001,0.49749445915222001,0.50373303890228005,0.51100265979767001,0.51949447393417003,0.52577769756317005,0.52966850996017001,0.53374087810516002,0.53803199529648005,0.54401791095733998,0.55188316106795998,0.55763250589371005,0.56108945608139005,0.56351852416991999,0.56494683027267001,0.56555140018463002,0.56534987688064997,0.56408035755157004,0.56171733140945002,0.55870157480240001,0.55503767728805997,0.55101907253265003,0.54664516448974998,0.54242950677872004,0.53847819566726995,0.53255522251128995,0.52454847097396995,0.51474410295485995,0.50298500061035001,0.49359872937201998,0.48696026206017001,0.47835350036620999,0.46752974390983998,0.45577409863472002,0.44304519891739003,0.43149527907371998,0.42138084769249001,0.40898531675339,0.39404380321503002,0.37867245078086997,0.36284089088440002,0.34944158792496,0.33883449435233998,0.32623180747031999,0.31129670143126997,0.29634001851081998,0.28135776519775002,0.26877859234809998,0.25897338986397,0.24677681922913,0.23175504803658001,0.21745671331881999,0.2040024548769,0.19253899157047,0.18334864079952001,0.17214126884937,0.15849734842777,0.14612503349781,0.13520662486553001,0.12596920132636999,0.11857067793608,0.11050937324762,0.10155856609343999,0.093297258019446994,0.085807800292969,0.079076454043388006,0.073146976530551994,0.067298933863639998,0.061440765857696998,0.056440409272908998,0.052350752055645003,0.049138605594635003,0.046831242740154003,0.045037858188152001,0.043765824288130001,0.042445786297321,0.041020441800356001,0.039725340902805002,0.038506582379341001,0.038475047796964999,0.039722569286823002,0.041956197470426997,0.045141950249671998,0.049622334539889998,0.055407755076885001,0.062917374074459007,0.072418123483658003,0.080037586390971999,0.085367575287819006,0.090553611516953,0.095707476139069006,0.10107006877661,0.10669104754925,0.11227339506149001,0.11779541522264,0.12327489256859001,0.12868128716946001,0.13448238372803001,0.14073568582535001,0.14716590940952001,0.15381579101085999,0.15977984666823999,0.16495680809020999,0.16974338889122001,0.17413352429866999,0.17856742441654,0.18310056626797,0.18746869266033001,0.19164155423640999,0.19586716592312001,0.20024760067462999,0.20354853570461001,0.20557519793510001,0.20763483643531999,0.20983661711216001,0.21199570596218001,0.2140516936779,0.21683649718761,0.22054000198841001,0.22352464497089,0.22558514773846,0.22764091193676,0.22973640263080999,0.23224142193794001,0.23531547188759,0.23734360933304,0.23808644711971,0.23875719308853,0.23938018083571999,0.24100305140018,0.2439553886652,0.24528712034225,0.24451680481433999,0.24438221752643999,0.24512821435928001,0.24673764407634999,0.24951533973216999,0.24990597367287001,0.24738489091395999,0.24420705437660001,0.24055197834969,0.23647360503674,0.23205104470252999,0.22661800682545,0.22007003426551999,0.21288575232029,0.20509317517281,0.19679389894009,0.18792556226254001,0.17944653332232999,0.17156502604484999,0.16299606859683999,0.15355487167835,0.14389710128307001,0.13396582007408001,0.1251548230648,0.11784981191158,0.10937380045652,0.099334500730037995,0.089098319411278007,0.078740373253821994,0.068870708346366993,0.059845782816410002,0.048460081219672997,0.034045051783323003,0.020126685500145,0.0070323012769221999,-0.0047466042451560003,-0.014662764035164999,-0.027804873883724001,-0.045238815248013001,-0.061599809676408997,-0.076276674866675997,-0.089682601392268996,-0.10125756263733,-0.11701853573322001,-0.1383388787508,-0.1581172645092,-0.17543317377567,-0.19180046021937999,-0.20681494474411,-0.22591845691203999,-0.25057286024094,-0.27251470088959001,-0.29053923487663003,-0.30731114745139998,-0.32253646850585999,-0.34174120426178001,-0.36657619476317999,-0.38739544153214001,-0.40260285139084001,-0.41682890057563998,-0.43023875355720997,-0.44582006335258001,-0.46457383036612998,-0.48079305887222001,-0.49344456195830999,-0.50592988729476995,-0.51844888925552002,-0.53276216983794999,-0.54978823661803999,-0.56315279006957997,-0.57154577970505005,-0.57978564500809004,-0.58836156129837003,-0.59794318675994995,-0.60924381017685003,-0.61681771278381003,-0.61937701702117998,-0.62229764461517001,-0.62626099586487005,-0.63103264570235995,-0.63709640502929998,-0.64031547307967995,-0.63975912332535001,-0.63881874084473,-0.63796705007553001,-0.63658320903777998,-0.63475072383881004,-0.63129723072052002,-0.62581574916839999,-0.62043714523314997,-0.61548453569411998,-0.61059641838073997,-0.60582202672957997,-0.60053640604018999,-0.59453278779983998,-0.58884942531586004,-0.58371978998184004,-0.57835096120833995,-0.57271724939346003,-0.56617975234984996,-0.55858284235000999,-0.55033046007155995,-0.54140901565552002,-0.53233051300048995,-0.52318704128265003,-0.51392245292663996,-0.50462043285369995,-0.49456143379210998,-0.48354315757750999,-0.47235867381095997,-0.46114525198936002,-0.44959664344787997,-0.43752878904343001,-0.42620137333870001,-0.41586565971375,-0.40601199865340998,-0.39656093716620999,-0.38773512840271002,-0.37962940335273998,-0.37176632881165,-0.36425718665123002,-0.35561180114745999,-0.34552115201950001,-0.33446052670478998,-0.32238391041755998,-0.30984795093535999,-0.29646679759026001,-0.28613832592964,-0.27980744838714999,-0.27519151568412997,-0.27223652601241999,-0.26920181512833002,-0.2660645544529,-0.26038491725921997,-0.25139719247817999,-0.2415256947279,-0.23098088800906999,-0.2207487821579,-0.21085910499096,-0.20275400578975999,-0.19689200818538999,-0.19185841083527,-0.18746899068355999,-0.18367451429366999,-0.18079760670662001,-0.17603446543217,-0.16852784156799,-0.16102655231953,-0.15391907095908999,-0.14741875231266,-0.14171980321406999,-0.1360506862402,-0.13023222982883001,-0.12466610968113,-0.11938314139843,-0.11460089683532999,-0.11051239073277,-0.10600193589926001,-0.10071620345116,-0.095813363790512002,-0.091495662927627994,-0.087665662169455996,-0.084467604756354994,-0.080847114324569994,-0.076363034546374997,-0.072820834815502,-0.070630058646202004,-0.069072641432285004,-0.068093188107013994,-0.067420087754725994,-0.066933818161487996,-0.067064739763737002,-0.068014286458492001,-0.068885408341885002,-0.069546543061732996,-0.069748148322105005,-0.069224916398525002,-0.069374896585940996,-0.070610612630844005,-0.071885906159877999,-0.073099292814732,-0.073743134737015006,-0.073450379073619995,-0.073955461382866003,-0.075801916420459997,-0.077477827668190002,-0.078709535300732006,-0.079615958034991996,-0.080090165138245004,-0.080816194415091996,-0.082099609076976998,-0.082791611552238006,-0.082676053047179995,-0.081716224551201005,-0.079589702188969005,-0.078199587762355999,-0.077946603298187006,-0.078723847866058003,-0.080662623047828994,-0.083151698112488001,-0.086256653070449996,-0.088739886879921001,-0.090275190770625999,-0.091193735599518003,-0.091454870998859003,-0.091521315276622994,-0.091507539153099005,-0.091341994702815996,-0.091091535985469999,-0.090297065675258997,-0.088751524686812994,-0.087140969932078996,-0.085511632263660001,-0.084412075579165996,-0.083973921835423002,-0.084279589354991996,-0.085599824786185996,-0.086451880633830996,-0.086498811841011006,-0.085868157446384,-0.084524303674698001,-0.082571551203728,-0.080005422234534995,-0.076969601213931996,-0.073445729911327001,-0.069777302443981004,-0.066108398139476998,-0.062043480575084999,-0.057475186884403,-0.052594736218452003,-0.047432888299226997,-0.042011588811874001,-0.036422055214643,-0.030134713277221,-0.022880863398314001,-0.015584094449877999,-0.0084845302626490992,-0.0013054157607257,0.0059510720893741001,0.013516212813556,0.021487023681402002,0.029622390866280001,0.037823151797055997,0.046387888491154002,0.055309697985648998,0.065050795674323994,0.075974710285663993,0.086587630212307004,0.096383668482303994,0.10635907948017,0.11661475896835,0.12773105502129001,0.14029610157013001,0.15177483856678001,0.16127543151379001,0.17060019075871,0.18008381128310999,0.18981152772903001,0.19994015991687999,0.2099621295929,0.21962593495846,0.22974754869937999,0.24057696759701,0.25174713134766002,0.26330101490021002,0.27463287115097001,0.28558948636054998,0.29613408446312001,0.30625337362289001,0.31579908728599998,0.32454806566237998,0.33357346057892001,0.34341722726821999,0.35248503088951,0.36027812957763999,0.36750972270965998,0.37400057911873003,0.38152560591697998,0.39094507694244002,0.40010455250740001,0.40853849053383001,0.41616788506508001,0.42296218872070002,0.42852380871772999,0.43253329396248003,0.43611049652099998,0.43958234786986999,0.44266200065612998,0.44531878829001997,0.44751250743866,0.44900506734848,0.45106244087219,0.45432814955710998,0.45711669325829002,0.4590370953083,0.46002241969108998,0.45979890227317999,0.45940744876862,0.45911604166031,0.45893296599388,0.45893138647079001,0.45894849300384999,0.45884048938750999,0.45925864577293002,0.46093526482581998,0.46084058284759999,0.45789676904678001,0.45344769954681002,0.44711184501647999,0.44229578971862998,0.44068703055382002,0.43857118487357999,0.43485993146896001,0.43062272667884999,0.42581561207771002,0.42158040404320002,0.41890671849250999,0.41438087821007002,0.40663349628447998,0.39799389243125999,0.3886690735817,0.38029715418816001,0.37365889549254999,0.36760458350182001,0.36195984482764998,0.35638150572777,0.35070741176605003,0.34511235356330999,0.34010964632034002,0.33312705159187,0.32279708981513999,0.31226247549057001,0.30223479866982,0.29323014616965998,0.28597378730773998,0.27820450067519997,0.26896503567696001,0.25993815064429998,0.25155028700829002,0.24369314312935,0.23667168617248999,0.22907981276511999,0.22010117769241,0.21173451840877999,0.20458859205245999,0.19831781089306,0.19303393363953,0.18809007108212,0.18310762941837,0.17898540198803001,0.17611980438232,0.17374387383461001,0.17160178720951,0.16999691724777,0.16907034814357999,0.16841287910937999,0.16778710484504999,0.16776174306870001,0.16831921041011999,0.17038969695567999,0.17492109537125,0.17881588637828999,0.18073406815529,0.18265637755394001,0.18489015102386,0.18828651309013,0.19377449154854001,0.19854269921779999,0.20134624838828999,0.20411524176598,0.20735104382038,0.21097391843796001,0.21541564166546001,0.21884626150131001,0.22026517987250999,0.22164803743361999,0.22363738715649001,0.22579577565192999,0.22832700610161,0.23001688718796001,0.23023390769957999,0.2300194054842,0.22967307269573001,0.22906570136547,0.22812430560589,0.22722351551056,0.22652474045752999,0.22587186098098999,0.22527246177197,0.22455464303493,0.22369164228439001,0.22252772748470001,0.22119729220866999,0.21874676644801999,0.21454600989819,0.20993658900261,0.20524217188357999,0.20085434615611999,0.19735421240330001,0.19300109148026001,0.18692982196808,0.18049620091915,0.17395986616611001,0.16788567602634,0.16322405636310999,0.15678726136683999,0.14675621688366,0.13650779426098,0.12697890400886999,0.11849763244390001,0.11189153790474,0.10474977642298,0.095866404473782002,0.087041430175303997,0.078767456114292006,0.071114473044872006,0.064819984138012002,0.057027034461497997,0.045787367969750997,0.035303350538014998,0.027214281260967001,0.020217161625624001,0.014346051961184001,0.0084448726847768003,0.0019962163642049001,-0.0047835307195783,-0.011898841708899001,-0.019369561225176,-0.027203988283873,-0.035426639020442997,-0.044337589293717998,-0.052648581564425999,-0.059712965041399002,-0.066263742744922999,-0.072591461241245006,-0.078195847570895996,-0.082455918192863006,-0.087436474859714994,-0.094197355210781,-0.10141864418983,-0.10880264639854,-0.11608231812715999,-0.12305243313313,-0.12986004352569999,-0.13658149540424,-0.14298826456069999,-0.14902018010616,-0.15452663600444999,-0.15871009230614,-0.16473905742167999,-0.17469081282616,-0.18489576876163,-0.19402149319649001,-0.20261593163013,-0.21047359704971,-0.21840606629848,-0.22706237435341001,-0.2350158393383,-0.24152623116970001,-0.24755857884884,-0.25286114215851002,-0.25977298617362998,-0.27025297284125999,-0.28021046519279003,-0.28780415654182001,-0.29465934634209001,-0.30093121528625,-0.30755311250687001,-0.31558620929718001,-0.32245609164237998,-0.32674062252045,-0.33035069704056003,-0.33363455533981001,-0.33764407038688998,-0.34354880452156,-0.34875115752219998,-0.35168248414992997,-0.35484629869460999,-0.35901883244513999,-0.36453831195830999,-0.37253117561339999,-0.37960103154182001,-0.38368526101111999,-0.38766652345656999,-0.39249712228775002,-0.39814525842666998,-0.40530452132224998,-0.41184377670288003,-0.41651311516762002,-0.42086416482924999,-0.42540350556374001,-0.43005579710007003,-0.43520632386208002,-0.43953961133956998,-0.44206622242928001,-0.44456475973129,-0.44786593317986001,-0.45126795768737998,-0.45472568273544001,-0.45773029327393,-0.45985132455826,-0.46179011464119002,-0.46391266584396001,-0.46577104926108998,-0.46727403998375,-0.46822187304496998,-0.46878960728645003,-0.46777698397635997,-0.46415549516678001,-0.45979326963424999,-0.45526593923568998,-0.45116773247719,-0.44857311248779003,-0.44484794139861999,-0.43824827671050998,-0.43133214116096003,-0.42502221465111001,-0.41936013102531,-0.41536691784858998,-0.40982449054718001,-0.40032166242598999,-0.39074540138245001,-0.38256135582924,-0.37587198615074002,-0.37231585383415,-0.3668477833271,-0.35587009787559998,-0.34464114904403997,-0.33550733327866,-0.32697969675063998,-0.31963419914246,-0.31011575460433999,-0.29527628421782998,-0.28102090954781,-0.27025705575942999,-0.26113706827164002,-0.25374996662139998,-0.24640846252441001,-0.23775006830692,-0.22966012358665,-0.22324225306511,-0.21698331832886,-0.21075862646103,-0.20281556248665,-0.19101691246033001,-0.17986015975475,-0.17198412120341999,-0.16479945182799999,-0.15764167904854001,-0.14989057183266,-0.14043579995632,-0.13167211413383001,-0.12519454956055001,-0.11898650974034999,-0.11224172264338,-0.10514299571514001,-0.097092531621455994,-0.090066604316235005,-0.085463851690291998,-0.081641510128974998,-0.077988252043724005,-0.074546821415424,-0.071346625685692,-0.067842096090316995,-0.063698031008244005,-0.059043012559414,-0.053872741758822999,-0.048172857612371001,-0.041385568678379003,-0.035573638975619999,-0.032026946544647002,-0.029863139614463002,-0.029016584157944,-0.028966750949620999,-0.029956294223666,-0.029891051352023999,-0.026954550296068001,-0.023601124063133999,-0.021058743819594002,-0.018504951149224999,-0.015774400904774999,-0.012753092683852,-0.0090762488543986997,-0.0057059922255576004,-0.0033581180032343002,-0.0011747132521123,0.0010328365024178999,0.0038291800301521999,0.0079827206209302001,0.012068644165993,0.015334472060204,0.018084811046719999,0.020355015993118002,0.022030476480722001,0.022980302572249998,0.023452484980226,0.023225035518407999,0.023536780849099,0.025077007710934001,0.027893798425794002,0.032617904245853001,0.037668064236641,0.042139273136853998,0.046345394104719002,0.050219975411892,0.053914096206427002,0.057543054223061003,0.060969676822423997,0.064101196825503998,0.067065887153148998,0.069960825145245001,0.072641849517822002,0.074932165443896998,0.077224411070346999,0.079661570489407002,0.082463026046752999,0.085907340049743999,0.089620701968670002,0.093425922095776007,0.097353048622608004,0.10140115767717001,0.10548634082079,0.10954191535711,0.11361426115036,0.11779198795557,0.12181439250708,0.12584483623504999,0.12878271937370001,0.12947304546832999,0.12961328029633001,0.13012483716011,0.13064768910408001,0.13151067495346,0.13153563439846,0.12950940430164001,0.12725788354873999,0.12572708725928999,0.12476098537445,0.12490988522768,0.12472146749496001,0.12296294420958,0.12104748189448999,0.11980144679546,0.11855977773666,0.11781991273165,0.11502149701118,0.10729942470789,0.099036298692225994,0.092835851013660001,0.087429203093051994,0.082986757159232996,0.078242756426334006,0.071771241724490994,0.065657995641231995,0.061312839388846997,0.057547178119420998,0.054075650870799997,0.050314057618380002,0.045273974537849003,0.040703475475311002,0.037871859967708997,0.035716436803341002,0.033906087279319999,0.032170858234167002,0.030264653265476001,0.028083436191082001,0.025284668430686,0.022563628852366999,0.020369274541736,0.018542246893047998,0.017216490581632,0.015953315421939,0.014106748625636,0.012922013178468,0.013223114423454,0.014667246490717,0.017797660082578999,0.020689852535725001,0.021531295031308999,0.022226413711905001,0.023813748732209001,0.02582030557096,0.028422020375728999,0.030805921182036001,0.031951665878296003,0.033439353108405998,0.036380521953106003,0.040026299655436998,0.044391103088856,0.048583645373583,0.051317956298589998,0.054687060415744997,0.060427468270062998,0.066790312528609994,0.073104895651339999,0.078824847936629999,0.082540385425090998,0.086952522397041002,0.094619363546371002,0.10254918783903,0.10928729921579,0.11447145789862,0.11639942973851999,0.11844320595264,0.12348288297653,0.12897896766663,0.13373464345932001,0.13790139555931,0.14053083956241999,0.14401985704899001,0.15077534317970001,0.15813459455966999,0.16457723081112,0.17050550878047999,0.17551293969154,0.18055488169193001,0.18667164444923001,0.19254630804062001,0.19733031094073999,0.2013632953167,0.20458999276161,0.20727989077567999,0.20962108671665,0.21164692938328,0.21337553858757,0.21500785648823001,0.21673721075058,0.21847708523272999,0.22025072574615001,0.22193779051304,0.22345480322837999,0.22477868199348,0.22593338787556,0.22670421004294999,0.22680702805519001,0.22661304473877,0.22649739682674,0.22597053647040999,0.22489568591118,0.22276946902274999,0.21842554211616999,0.21412706375122001,0.21200776100158999,0.21017363667488001,0.20760467648506001,0.20451377332210999,0.20041519403458,0.19646093249321001,0.19380232691765001,0.19140955805779,0.18866091966629001,0.18585011363029,0.18326111137866999,0.18020008504391,0.17597331106663,0.17116862535477001,0.16603460907935999,0.16071961820125999,0.15528099238873,0.15017499029636,0.14605566859245001,0.14216302335261999,0.13798135519027999,0.13367845118046001,0.12915070354939001,0.1246906593442,0.12060853838921,0.11663748323917,0.11261779069901,0.10861045122147001,0.10462933778763001,0.10064686089754001,0.096537925302981997,0.092628568410872997,0.089333377778529996,0.086148388683795998,0.082799784839152998,0.079133912920951996,0.074583046138287007,0.070213422179221996,0.067053489387034995,0.064357370138168002,0.061673194169998002,0.059295862913131998,0.057315792888403001,0.055847302079201001,0.055284705013036999,0.054824572056532003,0.05381565541029,0.052369195967913,0.050051897764206002,0.047877181321383001,0.047058209776878003,0.046340048313141001,0.044811468571423999,0.042859937995671997,0.040384095162153001,0.037914473563432999,0.036061491817236002,0.034386917948722999,0.032675538212060998,0.030917974188923999,0.028884410858153999,0.027036024257541001,0.026017034426331999,0.024981211870909001,0.023135906085371999,0.02105956710875,0.018995683640242001,0.017112407833337999,0.0160778388381,0.014603046700358,0.011234985664487,0.0072423354722559001,0.0033661560155450999,-0.00033449157490394999,-0.0032077394425869001,-0.0063080163672565998,-0.010838702321053001,-0.015654191374779001,-0.019946582615376001,-0.023937890306115001,-0.011475029401481001,-0.030873516574502002,-0.041668005287646998,-0.045982290059328003,-0.051461905241013003,-0.056086085736752,-0.060773644596338001,-0.065930642187595007,-0.071081489324569994,-0.075772702693939001,-0.080330170691013003,-0.084706239402294006,-0.089573226869106001,-0.096088610589504006,-0.10280160605907,-0.10844910889864,-0.11353369802237,-0.11802558600903,-0.12227112799883,-0.12678757309913999,-0.13107359409332001,-0.13468699157238001,-0.13792012631893,-0.14084583520888999,-0.14370122551917999,-0.14686185121536,-0.15002709627151001,-0.15291954576969,-0.15580698847770999,-0.15893553197384,-0.16213111579417999,-0.16537314653397001,-0.16843038797379001,-0.17095370590687001,-0.17322242259979001,-0.17546357214451,-0.17753094434738001,-0.1792858093977,-0.18090695142745999,-0.18254521489143,-0.18418219685555001,-0.18586537241935999,-0.18755368888377999,-0.18932391703129001,-0.19087061285973,-0.19174733757973,-0.19235840439796001,-0.19303350150585,-0.19364556670189001,-0.19421429932116999,-0.19461680948734,-0.19464279711245999,-0.19452689588069999,-0.19450996816158,-0.19443367421627,-0.19431149959564001,-0.19384241104125999,-0.19258797168732,-0.19084969162941001,-0.18878144025803001,-0.18646390736103,-0.18409070372580999,-0.18152981996536,-0.17862330377102001,-0.17559595406055001,-0.1727738827467,-0.16979448497294999,-0.16643738746643,-0.16248056292533999,-0.15735346078873,-0.15172255039214999,-0.14624480903149001,-0.1406519562006,-0.13487745821475999,-0.12891279160975999,-0.12261081486939999,-0.11629305779934,-0.11052465438843,-0.10461728274822001,-0.097798526287078996,-0.090552099049091006,-0.083125166594981995,-0.075625002384185999,-0.068378672003746005,-0.061083644628525002,-0.053470991551875999,-0.045625388622283998,-0.037347301840781999,-0.029202494770287999,-0.022147655487061001,-0.015197247266769,-0.0073283389210700997,0.00092186592519283002,0.0094926077872515002,0.017807422205806001,0.024749774485826,0.031411089003086,0.038964997977018002,0.046682335436344001,0.054194517433643001,0.061273049563169001,0.067170739173888994,0.072790451347827995,0.079247929155826999,0.085760451853274994,0.091681867837905995,0.097287967801094,0.10271517187357,0.1078507527709,0.11259210109711,0.11697562038898,0.12098921835423,0.12468360364437001,0.12796510756016,0.13126042485236999,0.13530506193638001,0.13947094976902,0.14316698908806,0.14659789204597001,0.14990986883640001,0.15278428792953,0.15462151169777,0.15609638392924999,0.1579368263483,0.15990182757377999,0.16192702949047,0.16411925852299,0.16667750477790999,0.16937096416950001,0.17195811867714,0.17448492348194,0.17706270515919001,0.17928731441498,0.18040560185908999,0.18112984299660001,0.18223530054091999,0.18337360024452001,0.18446460366249001,0.18530514836310999,0.18543946743011,0.1852769702673,0.18528446555138001,0.18519502878189001,0.1848718225956,0.18421614170073999,0.18281699717045,0.18127408623694999,0.18057155609131001,0.17981402575970001,0.17808198928832999,0.1756190508604,0.17194394767283999,0.16824850440024999,0.16665288805962,0.16536426544189001,0.16244168579578,0.15873704850674,0.15430741012096,0.15005242824553999,0.14766347408295,0.14605574309826,0.14427489042281999,0.14265972375870001,0.14124755561352001,0.14016419649124001,0.13957421481609,0.13955573737620999,0.14045180380344,0.14182949066162001,0.14325410127640001,0.14460988342761999,0.14507460594176999,0.14590568840504001,0.14914032816886999,0.15328542888165,0.15702311694622001,0.16036674380301999,0.16217119991779,0.16404676437377999,0.16854494810104001,0.17387863993645,0.17836894094944,0.18235732614993999,0.18488170206547,0.18793110549450001,0.19514702260493999,0.20364195108413999,0.21036179363728,0.21609950065613001,0.21991989016533001,0.22396406531334001,0.23227414488792,0.24164363741875,0.24839839339256001,0.25402343273162997,0.25852173566817999,0.26363909244536998,0.27338847517967002,0.28424218297004999,0.29175215959549,0.29796686768531999,0.30371427536010998,0.31001174449920998,0.32004323601723,0.33054724335669999,0.33695966005325001,0.34160199761391002,0.34585019946098,0.35033789277076999,0.35768583416938998,0.36523231863976002,0.36910602450371,0.37148225307464999,0.37412637472152999,0.37694463133812001,0.38122913241385997,0.38526880741119002,0.38637131452559997,0.38593024015427002,0.38510048389434998,0.38356882333754999,0.38119274377822998,0.37835425138473999,0.37598526477813998,0.37312626838683999,0.36852115392684998,0.36246851086616999,0.35439255833625999,0.34556365013123003,0.33856615424156,0.33144703507423001,0.32175278663634999,0.31052619218826,0.29802379012107999,0.28515666723250999,0.27441444993018999,0.26359838247299,0.24958315491676,0.23387931287288999,0.21739934384823001,0.20063343644142001,0.18575677275658001,0.17039427161217,0.15059202909469999,0.12872928380966001,0.10682447999715999,0.085388451814651004,0.067328669130802002,0.049840349704027002,0.028551628813147999,0.0057778209447861004,-0.016439229249954002,-0.038301039487122997,-0.058400683104992003,-0.078786663711071001,-0.1032842323184,-0.1295602619648,-0.15515521168709001,-0.1805115044117,-0.20485186576843001,-0.22920364141464,-0.25550442934036,-0.28249844908714,-0.30876070261001998,-0.33458110690116999,-0.35937973856925998,-0.38421866297722002,-0.41141498088836997,-0.43922677636147001,-0.46530151367188,-0.49045863747597002,-0.51507091522216997,-0.53911864757537997,-0.56287950277328003,-0.58599734306335005,-0.60784369707107999,-0.62870538234711004,-0.64898729324340998,-0.66824400424956998,-0.68570381402969005,-0.70173066854476995,-0.71667385101318004,-0.73041296005249001,-0.74296170473098999,-0.75414597988128995,-0.76376223564148005,-0.77154058218001997,-0.77656012773514005,-0.77959960699080999,-0.78181844949722001,-0.78285169601439997,-0.78262162208556996,-0.78100752830505005,-0.77760034799576006,-0.77275842428206998,-0.76701468229294001,-0.76023775339126998,-0.75275439023972002,-0.74379926919937001,-0.73136550188064997,-0.71715188026428001,-0.70374292135239003,-0.69040346145630005,-0.67772239446640004,-0.66391330957412997,-0.64446544647216997,-0.62261623144150002,-0.60317397117615001,-0.58438611030579002,-0.56589084863662997,-0.54600137472152999,-0.51957339048385998,-0.49060040712357,-0.46545800566673001,-0.4416296184063,-0.41791790723800998,-0.39280563592911,-0.36061754822731001,-0.32630771398544001,-0.29875677824020003,-0.27365243434906,-0.24689994752406999,-0.21816241741180001,-0.18247617781162001,-0.14519557356834001,-0.11696104705334,-0.092330262064933999,-0.065242484211921997,-0.036455947905779003,-0.0026329346001147998,0.031808242201804997,0.057012584060430999,0.078843712806701993,0.10514023154974,0.13420835137366999,0.16858386993408001,0.20333400368689999,0.22669529914855999,0.24526499211788,0.2679026722908,0.29215466976165999,0.31868904829025002,0.34435132145882003,0.36056566238402998,0.37269508838653997,0.3888258934021,0.40636754035950001,0.42483964562415999,0.44210606813431003,0.45158436894416998,0.45745909214019997,0.46633103489875999,0.47586715221405002,0.4847716987133,0.49220845103263999,0.49481853842735002,0.49470230937004001,0.49513882398605003,0.49507641792297002,0.49398580193519998,0.49166890978812999,0.48724886775017001,0.48115482926369002,0.47378966212272999,0.46534037590027,0.45647650957107999,0.44708317518233998,0.43787837028503002,0.42746445536612998,0.41203689575195002,0.39398366212844999,0.37700814008713002,0.36035487055778997,0.34507846832275002,0.32930940389633001,0.30809086561202997,0.28433904051781,0.26267388463020003,0.24176740646361999,0.22175700962542999,0.20094355940819,0.17381766438484,0.14418749511241999,0.11894152313471,0.095799252390861997,0.073397710919379994,0.051083687692880998,0.025601305067539,-0.00070650130510330005,-0.023263288661838001,-0.043934009969234002,-0.064378641545772997,-0.085251338779925995,-0.11032857000828,-0.13658934831618999,-0.15772373974323001,-0.17633117735386,-0.19531993567944,-0.21450957655906999,-0.23588664829730999,-0.25748735666275002,-0.27475050091742997,-0.28971132636070002,-0.30496722459793002,-0.32022827863692999,-0.33671143651009,-0.35322785377501997,-0.36691969633102001,-0.37917539477348,-0.39203041791915999,-0.40509811043739002,-0.41907313466071999,-0.43274855613708002,-0.44270962476730003,-0.45072990655898998,-0.45973107218741999,-0.46890294551848999,-0.47801315784454002,-0.48659729957580999,-0.49288672208786,-0.49795284867286999,-0.50383460521697998,-0.50986331701278997,-0.51574575901030995,-0.52086240053177002,-0.52286833524704002,-0.52308714389801003,-0.52390664815902999,-0.52468103170394997,-0.52509409189223999,-0.52506285905838002,-0.52406173944473,-0.52242642641068004,-0.52089607715607,-0.51912623643875,-0.51665633916855003,-0.51342350244521995,-0.50862312316894998,-0.50306868553161999,-0.49888077378272999,-0.49515321850777,-0.49065315723419001,-0.48542058467865001,-0.47850930690764998,-0.47070801258087003,-0.46398514509201,-0.45749408006668002,-0.44993513822556003,-0.44157728552817999,-0.43224066495895003,-0.42231878638268,-0.41301628947258001,-0.40380629897117998,-0.39382782578468001,-0.38330256938933999,-0.37216562032700001,-0.36081716418266002,-0.35085469484329002,-0.34116807579994002,-0.32918480038643,-0.31575211882590998,-0.30155467987061002,-0.28702744841576,-0.27457383275031999,-0.26251763105392001,-0.24679209291935,-0.22892169654368999,-0.21070192754268999,-0.1925154030323,-0.17765289545058999,-0.16365866363049,-0.14414778351783999,-0.12176345288753999,-0.10053626447916,-0.080219045281409995,-0.063602492213248998,-0.048205658793448999,-0.027096606791018999,-0.0031320862472057,0.019095310941339001,0.040172573179007,0.057682249695062998,0.074681684374809001,0.10105770081282001,0.13208609819412001,0.15865397453308,0.18261317908763999,0.20301212370395999,0.22225701808928999,0.24891841411591001,0.27890864014625999,0.30396109819411998,0.32615187764168002,0.34590566158295,0.36529842019080999,0.39318108558655002,0.42481347918509998,0.44940185546875,0.47010970115661999,0.48969060182571,0.50937300920485995,0.53675639629364003,0.56731569766998002,0.58974003791809004,0.60769659280777,0.62583971023560003,0.64433902502060003,0.66822403669357,0.69388562440872004,0.71113616228104004,0.72369992733001998,0.73749268054962003,0.75210875272750999,0.77148860692978005,0.79216527938842995,0.80344790220260998,0.80933493375777998,0.81677353382110995,0.82475548982619995,0.83520466089249001,0.84598141908645996,0.85009539127349998,0.85006028413773005,0.85028451681136996,0.84994292259215998,0.84916579723357999,0.84747040271759,0.84315216541289995,0.83670246601105003,0.82870429754257002,0.81916904449463002,0.80845397710800004,0.79657644033431996,0.78414601087570002,0.77056020498276001,0.75368928909302002,0.73443323373795,0.71435117721557995,0.69378036260605003,0.67597174644470004,0.65875214338303001,0.63547796010971003,0.60845154523848999,0.58144396543502996,0.55460822582244995,0.53234016895294001,0.51163631677627996,0.48301380872726002,0.44983506202697998,0.41825097799300998,0.38784065842628002,0.36243775486946,0.33906489610672003,0.30766203999518998,0.27192899584769997,0.23933003842830999,0.208870023489,0.18300245702267001,0.15901909768580999,0.12646627426147,0.089651942253113001,0.058663025498390003,0.031597942113876003,0.0088825654238461997,-0.011555645614862,-0.038721643388270999,-0.069256216287612998,-0.095539003610611004,-0.11929160356522001,-0.14187960326672,-0.16388735175133001,-0.18939781188964999,-0.21632097661495001,-0.23855665326118,-0.25771284103393999,-0.27588632702826998,-0.29331251978874001,-0.31310564279556002,-0.33351442217826999,-0.34895956516266002,-0.36110642552375999,-0.37287279963492997,-0.38414111733437001,-0.39693173766135997,-0.41001796722411998,-0.41925039887428001,-0.42594599723816001,-0.43273451924324002,-0.43937417864799,-0.44722288846969999,-0.45509955286979997,-0.45836207270621998,-0.45859375596045998,-0.45941349864005998,-0.46025335788727001,-0.46153867244719998,-0.46253377199173001,-0.45999264717102001,-0.45501863956451,-0.45018163323402,-0.44509434700012002,-0.43989107012749001,-0.43441194295883001,-0.42795789241790999,-0.42084437608719,-0.41404986381531,-0.40734094381331998,-0.40050417184830001,-0.39333578944205999,-0.38450488448143,-0.37462130188942,-0.36562913656235002,-0.35706576704978998,-0.3483567237854,-0.33931198716164002,-0.32832455635071001,-0.31616342067719,-0.30541682243347001,-0.29543676972388999,-0.28514406085013999,-0.27451825141906999,-0.26249822974205,-0.24959601461886999,-0.23752942681313,-0.22592446208,-0.21428883075714,-0.20259442925453,-0.19017997384071,-0.17744626104832001,-0.16607300937176001,-0.15547493100165999,-0.14400017261504999,-0.1319116204977,-0.11905470490455999,-0.10584257543087,-0.094429574906826005,-0.084115728735924003,-0.072944521903992005,-0.061291169375180997,-0.049440708011389001,-0.037637278437613997,-0.027511391788721001,-0.018488066270946998,-0.0088352737948298003,0.0011523626744746999,0.011357220821083,0.021601825952530001,0.030691364780067999,0.039135247468948003,0.048801973462104999,0.059244293719530002,0.069669909775257,0.079955928027630005,0.088479213416575997,0.096074230968951999,0.10620433092117,0.11796142160891999,0.12929902970790999,0.14021262526511999,0.14871965348721,0.15579932928085,0.16547611355781999,0.17676408588886,0.18739549815654999,0.19757258892058999,0.20652051270008001,0.21471536159515001,0.22445137798786,0.23496282100676999,0.24375614523888001,0.25115230679512002,0.25672733783722002,0.26104190945625,0.26724779605865001,0.27437135577201999,0.27924871444701999,0.28240129351616,0.28425133228302002,0.28501656651496998,0.28641551733017001,0.28789764642714999,0.28755235671996998,0.28573060035705999,0.28304272890090998,0.27941384911536998,0.27482804656028997,0.26927682757378002,0.26267766952514998,0.25508943200111001,0.24686017632484,0.23786188662051999,0.22741255164145999,0.21584074199200001,0.20478746294975,0.19379878044127999,0.18151696026325001,0.16795156896114,0.15168747305870001,0.13350015878676999,0.11731882393360001,0.10223343968390999,0.085798859596251997,0.068138480186462,0.047518238425255002,0.025051616132259001,0.0069510033354162996,-0.0084060970693827005,-0.026424258947371999,-0.046441331505775001,-0.068784661591052995,-0.092809826135635001,-0.11436365544796,-0.13452577590942,-0.15709763765335,-0.18148963153361999,-0.20723494887352001,-0.23378300666808999,-0.25660812854767001,-0.27708175778388999,-0.30089488625526001,-0.32705968618393,-0.35396832227706998,-0.38110333681107,-0.40311649441719,-0.42160108685492997,-0.44331228733062999,-0.46706697344780002,-0.49035698175429998,-0.51308482885360995,-0.53225541114806996,-0.54887509346008001,-0.56775480508803999,-0.58793067932128995,-0.60660237073898005,-0.62391149997711004,-0.63839548826217996,-0.65065866708755005,-0.66394329071045,-0.67759686708449995,-0.68962520360946999,-0.70014339685439997,-0.70820111036301003,-0.71423006057739002,-0.72078317403793002,-0.72727310657500999,-0.73146075010300005,-0.73357892036437999,-0.73340791463851995,-0.73120760917663996,-0.72876375913619995,-0.72574728727340998,-0.72110456228256004,-0.71498972177505005,-0.70760244131088001,-0.69911122322082997,-0.69132697582244995,-0.68360930681229004,-0.67230385541916005,-0.65805792808533004,-0.64273065328598,-0.62636518478393999,-0.61110740900039995,-0.5962718129158,-0.57803070545196999,-0.55707627534866,-0.53563952445983998,-0.51369458436965998,-0.49323323369026001,-0.4735079407692,-0.44980040192603998,-0.42303615808487,-0.39677757024764998,-0.37081781029701,-0.34680521488190003,-0.32396170496941001,-0.29681590199470997,-0.26647242903709001,-0.23758205771446,-0.20978879928589,-0.18446706235408999,-0.16073316335678001,-0.13160184025763999,-0.098574101924896004,-0.068797841668128995,-0.041545633226633003,-0.016953233629464999,0.0057501606643199999,0.033562511205673003,0.065147474408149997,0.094490677118301003,0.12223707139492,0.14909131824970001,0.17527128756046001,0.20364582538605,0.23339472711086001,0.25927761197089999,0.28200793266295998,0.30341118574142001,0.32372030615807001,0.34708595275879001,0.37247738242148998,0.39350339770317,0.41107401251793002,0.42818725109099998,0.44491052627562999,0.46491289138794001,0.48715394735335998,0.50441950559616,0.51776289939880005,0.53125041723250999,0.54470741748810003,0.56014639139175004,0.57685989141464,0.58930283784866,0.59833538532257002,0.60787409543991,0.61763596534729004,0.62825202941894998,0.63931715488434004,0.64710265398026001,0.65218299627303999,0.65732771158217995,0.66230857372284002,0.66710829734802002,0.67159181833267001,0.674261033535,0.67539626359939997,0.67672836780547996,0.67809605598449996,0.67933785915375,0.68033629655838002,0.67968970537186002,0.67755913734436002,0.67442864179610995,0.67032420635223,0.66581869125366,0.66092711687088002,0.65666639804839999,0.65268647670746005,0.64566802978516002,0.63606196641921997,0.62608063220978005,0.61567777395248002,0.60648632049561002,0.59806102514267001,0.58634644746779996,0.57190245389937999,0.55787009000777998,0.54408806562423995,0.53174000978470004,0.52028846740723,0.50378811359405995,0.48309287428856001,0.46351951360702998,0.44477251172066001,0.42832124233245999,0.41346061229705999,0.39187246561049999,0.36481854319571999,0.34137091040611001,0.32083457708358998,0.30257827043532998,0.28603926301003002,0.26277133822441001,0.23399946093558999,0.20878940820694,0.18640631437301999,0.16521339118480999,0.14481249451636999,0.11760348826647,0.084874421358109006,0.058124557137489,0.036338042467833002,0.015638694167137,-0.0041430369019507998,-0.029174568131565999,-0.058480046689509999,-0.083179794251919001,-0.10410188138485001,-0.12551490962504999,-0.14735862612723999,-0.17298147082328999,-0.20160461962223,-0.22404477000237,-0.24123702943325001,-0.25929942727089,-0.27799081802367998,-0.29935720562934998,-0.32278329133986999,-0.34005853533745001,-0.35203763842583002,-0.36509680747986001,-0.3789256811142,-0.39442136883736001,-0.41114309430121998,-0.42236521840095997,-0.42878726124763,-0.43617737293242997,-0.44421738386154003,-0.45284351706504999,-0.46176195144652998,-0.46563512086867997,-0.46500933170318998,-0.46478280425071999,-0.46466374397277999,-0.46383246779442,-0.46217891573906,-0.45696538686751997,-0.44845485687255998,-0.43900132179259999,-0.42849773168563998,-0.41701123118401001,-0.40448480844498003,-0.38988912105559997,-0.37333419919013999,-0.35608148574829002,-0.33805811405182001,-0.31898412108420998,-0.29883235692978,-0.27675390243530001,-0.25283977389335999,-0.22819748520850999,-0.20277588069439001,-0.17647705972194999,-0.14929762482643,-0.12098196148871999,-0.091615498065948001,-0.062956050038337999,-0.034884013235569,-0.0063042249530554,0.022733332589269,0.051944084465503998,0.081359528005123,0.11158818006516,0.1425761282444,0.17359578609467,0.20466634631156999,0.23575732111931,0.26680791378021002,0.29602274298668002,0.32354271411896002,0.35135096311568997,0.37936463952065003,0.40731954574585,0.43515402078629001,0.46091699600219999,0.48473078012465998,0.50816786289214999,0.53116929531097001,0.55349153280258001,0.57511204481125,0.59526342153548994,0.61395585536956998,0.63066041469573997,0.64542579650878995,0.65922194719314997,0.67201775312423995,0.68398094177246005,0.69501549005508001,0.70185989141464,0.70471090078354004,0.70710992813109996,0.70896995067596003,0.71087098121643,0.71266216039658004,0.70923924446106001,0.70085942745208996,0.69226258993149004,0.68333303928375,0.67432743310928001,0.66510111093520996,0.64963901042937999,0.62828540802001998,0.60973709821701005,0.59375816583633001,0.57893115282059004,0.56510269641875999,0.54355096817017001,0.51469802856445002,0.49004563689232,0.46929574012755998,0.44925129413604997,0.42981201410294001,0.40223792195320002,0.36694699525833002,0.33811670541763,0.31539261341094998,0.29279223084450001,0.27029845118522999,0.24070304632187001,0.20434333384037001,0.17551068961620001,0.15387311577797,0.13148371875286,0.10839712619781,0.080397598445414997,0.047710534185171002,0.023350361734629,0.0070398915559052996,-0.010562167502939999,-0.029371647164226002,-0.051449581980704998,-0.076674118638038996,-0.095711745321751002,-0.1087251752615,-0.12297407537699,-0.13839375972748,-0.15514318645,-0.17316272854805001,-0.18511022627354001,-0.19108587503433,-0.19748923182486999,-0.20427623391151001,-0.21093854308127999,-0.21746176481247001,-0.22093486785888999,-0.22137930989265001,-0.22025030851364,-0.21754465997219,-0.21372558176517001,-0.20879334211348999,-0.20378972589970001,-0.19870579242705999,-0.18982660770415999,-0.17716130614281,-0.16379705071448999,-0.14973191916942999,-0.13772842288017001,-0.12779143452644001,-0.11357264220715001,-0.095058128237723999,-0.076998621225357,-0.059395950287579997,-0.045211680233478997,-0.034479584544897003,-0.019319277256727,0.00032028183341026003,0.018780440092087,0.036041174083947997,0.051167454570531998,0.064115837216376995,0.081574916839599998,0.10363321006298,0.12318626791239,0.14018575847149001,0.15467996895312999,0.16664032638073001,0.17919701337814001,0.19240288436413,0.20344957709312,0.21230548620223999,0.21959103643894001,0.22530181705951999,0.23029085993767001,0.23457759618759,0.23731675744056999,0.23848778009415,0.23897181451321001,0.23878103494644001,0.23796887695789001,0.23656752705574,0.23236446082591999,0.22530725598335,0.21671636402607,0.20661932229996,0.19444561004638999,0.18019266426562999,0.16344620287417999,0.14417499303817999,0.12371462583542001,0.10209607332945,0.078723497688770003,0.053528960794209997,0.029712654650211001,0.0073904432356357999,-0.015996109694241999,-0.040496449917555001,-0.065959013998507995,-0.092353120446205,-0.12125276029110001,-0.15273493528366,-0.18499232828616999,-0.21797959506511999,-0.25196099281311002,-0.28695118427277,-0.32253363728522999,-0.35872033238411,-0.39462739229201999,-0.43023097515106001,-0.46563404798508001,-0.50088453292847002,-0.53417867422104004,-0.56544792652130005,-0.59526115655899003,-0.62360668182373002,-0.65128713846206998,-0.67831349372864003,-0.70529925823212003,-0.73231887817383001,-0.75749105215072998,-0.78070431947707997,-0.80363386869430997,-0.82631307840347001,-0.84946793317795,-0.87322288751601995,-0.89461022615432995,-0.9135075211525,-0.93060517311096003,-0.94593626260757002,-0.95904475450516002,-0.96994662284850997,-0.97765374183654996,-0.98207676410675004,-0.98463279008865001,-0.98537755012511996,-0.98411029577255005,-0.98079419136046997,-0.97631794214249001,-0.97071176767348999,-0.96411234140395996,-0.95652431249618997,-0.94789189100266003,-0.93811494112015004,-0.93014770746231001,-0.92441016435623002,-0.91353482007980003,-0.89709633588791005,-0.87751191854476995,-0.85466837882996005,-0.83365309238434004,-0.81505942344666005,-0.79035329818725997,-0.75891560316086004,-0.72585326433181996,-0.69109833240509,-0.66139179468154996,-0.63748264312743996,-0.61028140783310003,-0.57916462421417003,-0.54834717512131004,-0.51784020662307995,-0.49184212088585,-0.47114938497543002,-0.44341921806335,-0.40757763385772999,-0.37268099188804998,-0.33903625607491,-0.3099852502346,-0.28653085231781,-0.25210329890250999,-0.20495182275772,-0.16176968812942999,-0.12337200343609001,-0.091094888746738004,-0.065622799098492002,-0.036471582949162001,-0.0025940760970116,0.027435071766375999,0.053074635565280998,0.075399383902549993,0.093874335289001007,0.1193518564105,0.15318560600281,0.18280297517776001,0.20727397501469,0.22985348105431,0.25015294551848999,0.27825185656548002,0.31573355197906,0.34633627533912997,0.36872011423111001,0.38860228657722001,0.40604451298714,0.42506814002991,0.44638589024544001,0.46284875273705001,0.47372087836266003,0.48346990346909002,0.49223962426186002,0.50217795372009,0.51373058557509999,0.52230477333069003,0.52726203203201005,0.53373062610625999,0.54196387529373002,0.55379480123519997,0.56998163461685003,0.58110839128493996,0.58609396219253995,0.59108638763428001,0.59649693965911998,0.60226082801819003,0.60871142148972002,0.61122572422027999,0.60920757055283004,0.60624617338180997,0.60258066654205,0.59816414117812999,0.59291201829910001,0.58827924728393999,0.58430790901184004,0.58213979005813998,0.58195990324019997,0.58274149894714,0.58454078435898005,0.58550035953521995,0.58537095785141002,0.58542639017105003,0.58583897352219005,0.58559310436249001,0.58475559949875,0.58135902881622004,0.57516932487488004,0.56681549549103005,0.55615055561065996,0.54546731710434004,0.53482311964035001,0.52621215581893999,0.51993715763091997,0.51469284296036,0.51043719053268,0.50648492574691995,0.50276345014571999,0.49936804175376998,0.49643310904503002,0.49230945110321001,0.48687806725501998,0.47971889376639998,0.47077146172522999,0.46023061871528997,0.44831609725951999,0.43212389945983998,0.41081124544143999,0.39127054810523998,0.37422823905945002,0.35882669687271002,0.34539085626602001,0.32965946197509999,0.31082731485366999,0.29348003864288003,0.27816686034202998,0.26339903473853998,0.24926573038100999,0.23351462185383001,0.21588180959225001,0.19662173092365001,0.17572304606438,0.15337394177913999,0.12970593571663,0.10313303023577,0.072941675782203994,0.045445285737514003,0.021606456488370999,-0.0019609476439655001,-0.025436474010348001,-0.050166804343461997,-0.076578840613365007,-0.10190038383007,-0.12573480606078999,-0.14931273460388,-0.17273299396038,-0.19594275951385001,-0.21875923871993999,-0.24326221644877999,-0.26982042193412997,-0.29701852798461997,-0.32472765445709001,-0.35300722718239003,-0.38205564022063998,-0.40967833995818997,-0.43553560972214,-0.46053302288054998,-0.48479828238486999,-0.50797009468079002,-0.53033727407455,-0.54847139120101995,-0.56165879964828003,-0.57289171218872004,-0.58236169815062999,-0.59106570482253995,-0.59876698255538996,-0.60969841480255005,-0.62505453824997004,-0.63820344209670998,-0.64816486835480003,-0.65709042549133001,-0.66506707668303999,-0.67312777042389005,-0.68172746896743996,-0.68787437677383001,-0.69108688831329002,-0.69257420301437,-0.69254916906357,-0.68992584943770996,-0.68431562185286998,-0.67822480201721003,-0.67203056812285999,-0.66511738300322998,-0.65747886896133001,-0.64869564771652,-0.63854080438614003,-0.62865179777144997,-0.61946094036101995,-0.60892844200134,-0.59680908918381004,-0.58292394876480003,-0.56686031818390004,-0.55217659473419001,-0.54007047414779996,-0.52394145727158004,-0.50266605615616,-0.47837257385254001,-0.45043176412581998,-0.42657342553138999,-0.40895235538482999,-0.38807103037834001,-0.36226713657379001,-0.33530768752098,-0.30685284733772,-0.28373447060585,-0.26822185516357,-0.24925613403319999,-0.22473199665546001,-0.1999990940094,-0.17522405087948001,-0.15449962019919999,-0.13960932195187001,-0.1207781881094,-0.095830954611301006,-0.071587145328522006,-0.048589903861283999,-0.029785774648189999,-0.016863914206624,6.6714361310004998e-05,0.023332435637712,0.045447468757628999,0.065543740987778001,0.082519717514515006,0.095081269741058003,0.11184186488389999,0.13509669899939999,0.15657836198806999,0.17499002814292999,0.19141715764999001,0.20487675070763001,0.22400529682636,0.25155174732208002,0.2762798666954,0.29624095559120001,0.31388890743255998,0.32863488793373002,0.34705159068107999,0.37148031592369002,0.39181181788445002,0.4060418009758,0.41797876358031999,0.42758318781853,0.43872997164726002,0.45280152559280001,0.46431487798691001,0.47205260396004001,0.47902578115463001,0.48540011048317,0.49312418699264998,0.50315886735916004,0.51094979047775002,0.51542949676514005,0.51920831203461004,0.52255463600159002,0.52620142698287997,0.53069955110550004,0.5331004858017,0.53259408473969005,0.53158968687056996,0.53040498495101995,0.52930188179016002,0.52833634614944003,0.52778285741805997,0.52770823240279996,0.52806627750396995,0.52885419130324995,0.5301930308342,0.53246116638184005,0.53295856714249001,0.53085660934447998,0.52869719266891002,0.52698707580565995,0.52499628067017001,0.52291494607925004,0.51874148845672996,0.51186805963516002,0.50391465425491,0.49504217505455,0.48582980036736001,0.47627478837967002,0.46747615933418002,0.45995470881461997,0.45161336660384999,0.44203916192054998,0.43156650662422003,0.42017307877540999,0.40814784169196999,0.39569550752639998,0.38174208998679998,0.36590534448624001,0.34945401549339,0.33259963989258001,0.31542435288428999,0.29813337326049999,0.2795398235321,0.25902557373047003,0.23924745619297,0.22063462436198999,0.20368526875973,0.18887525796890001,0.17412085831165,0.15902534127234999,0.14361220598221,0.12779124081134999,0.11181231588125,0.095646910369396002,0.079833030700683996,0.064738869667053001,0.048669792711735001,0.031212853267789002,0.012879300862550999,-0.0064318720251322001,-0.025641262531281,-0.044372007250786001,-0.063595369458199005,-0.083571940660477004,-0.10374689847231,-0.12420930713415,-0.14370742440223999,-0.16161049902439001,-0.18025594949722001,-0.20034195482730999,-0.22034201025962999,-0.24014663696288999,-0.25861522555351002,-0.27463528513907998,-0.29365742206572998,-0.31757593154906999,-0.34159755706786998,-0.36496099829674,-0.38696298003196999,-0.40739294886589,-0.42578899860382002,-0.44191172719001998,-0.45637926459312,-0.46935912966728,-0.48055496811866999,-0.49005216360092002,-0.49695605039597002,-0.50075757503509999,-0.50331842899322998,-0.50500297546386996,-0.50592261552811002,-0.50599896907805997,-0.50626415014267001,-0.50719624757767001,-0.50737780332564997,-0.50649231672286998,-0.50478053092956998,-0.50258338451384998,-0.49781200289726002,-0.48946002125740001,-0.48073333501816001,-0.47250318527222002,-0.46364024281501998,-0.45429569482803001,-0.44244995713233998,-0.42685613036156,-0.41203939914703003,-0.39938354492188,-0.38660344481468001,-0.37343606352806002,-0.35900807380675998,-0.34246581792830999,-0.32737615704535999,-0.31522905826568998,-0.30209904909134,-0.2872868180275,-0.26988118886947998,-0.24851621687412001,-0.22931849956511999,-0.21487723290919999,-0.1985550224781,-0.17893172800540999,-0.1557714343071,-0.12707197666167999,-0.10306162387133,-0.087971173226832997,-0.071811988949776001,-0.052072245627641997,-0.030870037153362999,-0.0073272604495287002,0.012155449949205,0.024469595402478998,0.037962634116411001,0.054965093731880001,0.072968386113643993,0.092427119612693995,0.10862945765257,0.11912418156861999,0.13065765798091999,0.14538206160069,0.15999227762222001,0.17449699342250999,0.18530943989754001,0.19063653051853,0.19472213089466001,0.19872143864632,0.20152851939201,0.20319627225399001,0.20263861119747001,0.19941332936287001,0.19419246912002999,0.18676717579364999,0.17899376153946001,0.17143617570399999,0.16388286650181,0.15661416947842,0.14819578826426999,0.13786011934280001,0.12768478691578,0.11820472776889999,0.10930421948433,0.10140730440617,0.092440925538539997,0.081390351057053001,0.070700533688068001,0.061125297099352001,0.051833450794219998,0.043204475194215997,0.032373797148465999,0.017590237781405001,0.0038157387170941002,-0.0073667159304022997,-0.017631834372877998,-0.026973441243172001,-0.036888014525174997,-0.048338513821362998,-0.058693218976259003,-0.066978387534618003,-0.074731655418873,-0.082031436264515006,-0.090239450335502999,-0.10023258626461,-0.10973756015301001,-0.11783663928509,-0.12624339759350001,-0.13525480031966999,-0.14550825953484001,-0.15805524587631001,-0.16872245073318001,-0.17573121190071,-0.18212278187274999,-0.18858614563942,-0.19527953863143999,-0.20323356986046001,-0.20794634521008001,-0.20729169249535001,-0.20539054274558999,-0.20335738360882,-0.20070244371891,-0.19763991236687001,-0.19317288696766,-0.18664616346359,-0.17986960709095001,-0.17347557842731001,-0.16685549914837,-0.16037224233149999,-0.15165674686432001,-0.13946825265884,-0.12627667188644001,-0.11278825998306,-0.098652742803096993,-0.083896718919276997,-0.068389780819416005,-0.052061147987842997,-0.035031635314225998,-0.017071466892958,0.00056424899958073995,0.01771466806531,0.033203132450580999,0.046588718891144,0.057820592075586,0.066406063735484994,0.074281454086304002,0.081987984478473996,0.089867837727069994,0.098548159003258001,0.10598154366015999,0.11097204685211,0.11628223955630999,0.12269869446754,0.13027490675448999,0.13970737159252,0.14835871756076999,0.15488661825656999,0.16171652078629001,0.16957700252533001,0.17815233767033001,0.18807727098464999,0.19634220004082001,0.20144264400004999,0.20578753948212,0.21013344824314001,0.21386456489562999,0.21691846847533999,0.21910071372986001,0.21984103322029,0.22145676612854001,0.22501716017723,0.22915278375149001,0.23386798799038,0.23762859404087,0.23997257649899001,0.24030213057995001,0.23798392713069999,0.23449821770191001,0.23017401993275,0.22564505040645999,0.22183710336685,0.21581529080868,0.20589254796504999,0.19535976648330999,0.18495757877826999,0.17585864663124001,0.16983424127102001,0.16138857603073001,0.14743925631046001,0.1336794346571,0.12173996865749,0.11193316429852999,0.10564618557692,0.098444849252701,0.087981708347797005,0.078056655824184001,0.069950081408024001,0.062880925834178994,0.057968072593212003,0.049677859991789003,0.034124240279197998,0.019681233912706,0.0094716344028711007,0.0015071625821291999,-0.0043698465451598003,-0.0084346393123268994,-0.010581472888589001,-0.011908455751836,-0.012677334249019999,-0.013631061650813001,-0.014824027195573001,-0.017648182809353,-0.023277521133423001,-0.029107535257935999,-0.033952638506889003,-0.039203889667987997,-0.044967044144869003,-0.052408736199141,-0.062839701771736006,-0.072719030082225994,-0.080208003520966006,-0.087871879339218001,-0.096357271075248996,-0.10613148659468,-0.11844069510698001,-0.12923303246498,-0.13637134432792999,-0.14261554181576,-0.14884094893932001,-0.15462748706341001,-0.16000348329544001,-0.16477586328982999,-0.16853880882263,-0.17270730435848,-0.17790231108665,-0.18381853401661,-0.19103142619133001,-0.19699434936047,-0.20026871562004001,-0.20267216861248,-0.20478381216526001,-0.2063764333725,-0.20760461688042001,-0.20787811279297,-0.20712593197823001,-0.20462867617607,-0.19961108267307001,-0.19388423860073001,-0.18749272823334001,-0.18310137093067,-0.18266484141350001,-0.18309660255908999,-0.18333914875984,-0.18356476724147999,-0.18377561867236999,-0.18341736495495001,-0.18254366517067,-0.17982672154903001,-0.17401690781116,-0.16779920458794001,-0.16210919618607,-0.15721918642520999,-0.15379644930363001,-0.15038987994194,-0.14639368653297,-0.14205621182919001,-0.13736011087894001,-0.13236781954765001,-0.12747909128665999,-0.12110523879528,-0.11160212755203,-0.10296498984098,-0.097016617655754006,-0.092744246125221003,-0.090295769274234994,-0.088656865060328993,-0.088103950023650998,-0.085622541606426003,-0.079495340585709007,-0.070998631417750993,-0.060511872172355999,-0.047504242509604,-0.030551144853234,-0.014716008678079,-0.0027662459760904,0.0076228822581470004,0.016924459487199998,0.025510353967547,0.033646006137132999,0.041406195610762003,0.048856467008590997,0.056113868951797,0.063366740942000996,0.070166982710360995,0.076674506068229994,0.081495411694050002,0.083573549985885995,0.084452085196972004,0.084818586707115007,0.084126383066176993,0.081582218408584997,0.079833477735519007,0.080640740692615995,0.081723704934119998,0.082209169864654999,0.082429453730582997,0.082742832601070002,0.081656455993651997,0.078079789876938005,0.073560550808906999,0.068716175854206002,0.0633295327425,0.056676462292671002,0.051698401570319998,0.050572637468576001,0.050219494849442999,0.049416214227676003,0.048454254865646001,0.047348462045193003,0.045593436807394,0.042778600007295997,0.039465136826038,0.035895593464375,0.031950771808623997,0.027847327291964999,0.022693242877722002,0.01557020097971,0.0083482172340154995,0.0019872207194567,-0.0040956055745482002,-0.010159028694033999,-0.015605350024998001,-0.020113430917263,-0.023875951766967999,-0.026731301099062001,-0.029422020539640999,-0.032254431396723002,-0.035496372729540003,-0.039767149835825001,-0.043527483940124997,-0.045592632144689997,-0.047736130654811998,-0.050729561597109001,-0.054401580244302999,-0.059251718223095003,-0.063680492341518,-0.066393837332725997,-0.069297924637793995,-0.073293045163155005,-0.077960699796676997,-0.083893395960331005,-0.088758073747157995,-0.091549225151539002,-0.091533184051514005,-0.087672300636767994,-0.081386350095271995,-0.072756215929985005,-0.063648365437983995,-0.055654272437096003,-0.046940326690674002,-0.036465357989073001,-0.025496827438474,-0.014233539812267,-0.0038126856088638002,0.0038504102267324998,0.013214034028351,0.027507323771715001,0.042873982340096997,0.058109097182751,0.072024047374724995,0.083003990352154,0.093342579901217998,0.10428962111473,0.11488838493824,0.12484980374575,0.13418494164944,0.14154206216335,0.15166169404984001,0.16893395781517001,0.18665109574795,0.20151552557944999,0.21448649466038,0.22448085248470001,0.23470073938370001,0.24782882630825001,0.26031690835952997,0.27022784948348999,0.27897047996521002,0.28560614585875999,0.29501086473464999,0.31228071451187001,0.32915884256362998,0.34093418717384,0.35046198964119002,0.35811501741409002,0.36486059427260997,0.37171840667724998,0.37754032015799999,0.38153097033500999,0.38482117652893,0.38756173849106001,0.39109110832214,0.39724859595299,0.40265887975692999,0.40513265132904003,0.40637627243996,0.40684685111045998,0.40689399838447998,0.40704375505446999,0.40663227438927002,0.40506723523139998,0.40337884426116999,0.40208870172500999,0.40121451020241,0.40162932872772,0.40076577663421997,0.39687392115593001,0.39094117283821,0.38317352533339999,0.37357929348946001,0.36163184046745001,0.34938046336174,0.33890935778617998,0.32724398374557001,0.31252199411392001,0.29612749814986999,0.27748417854308999,0.26018822193146002,0.24802052974701,0.23577246069908001,0.22017507255077001,0.20366927981377,0.18652269244194,0.17065738141537001,0.15857611596584001,0.14641608297825001,0.13154585659504001,0.11611521244049,0.10064369440079,0.086105562746525005,0.074357181787490997,0.061808172613381999,0.045712247490882998,0.028575189411640001,0.011444967240095,-0.0057287570089102,-0.022409368306398,-0.039613641798495997,-0.058366939425468001,-0.077140167355536998,-0.095085807144642001,-0.11232356727123,-0.12847471237183,-0.14434991776942999,-0.16034170985221999,-0.17673909664154,-0.19389180839062001,-0.21167413890362,-0.2304730117321,-0.24899499118328,-0.26632651686668002,-0.28274241089821001,-0.29812577366829002,-0.31271857023239003,-0.32686129212379,-0.33989506959915,-0.35089358687401001,-0.36164832115173001,-0.37349680066108998,-0.38553828001022,-0.39755865931510997,-0.40926504135132002,-0.42061018943786999,-0.43083366751670998,-0.43908604979514998,-0.44626292586326999,-0.45280906558036998,-0.45870169997214999,-0.46397808194160001,-0.46886152029036998,-0.47352826595306002,-0.47798669338226002,-0.48226150870322998,-0.48645612597465998,-0.49116033315659002,-0.49471241235732999,-0.49545255303383001,-0.49519509077071999,-0.49497914314269997,-0.49445188045501998,-0.49345144629477999,-0.49256613850594,-0.49236279726027998,-0.49233078956603998,-0.49220237135887002,-0.49207532405852999,-0.49221327900887002,-0.49176084995269997,-0.48986726999282998,-0.48735737800598,-0.48468542098999001,-0.48170793056487998,-0.47876217961311002,-0.47480374574661,-0.46863925457000999,-0.46175324916839999,-0.45532071590424,-0.44827920198441001,-0.44075030088424999,-0.43067392706870999,-0.41484048962593001,-0.39835056662559998,-0.38536697626114003,-0.37280872464179998,-0.35975912213326,-0.34498023986816001,-0.32569253444671997,-0.30671155452727999,-0.29236507415771001,-0.27886015176772999,-0.26441612839699002,-0.24877010285854001,-0.22990924119948999,-0.21189771592616999,-0.19899787008761999,-0.18651533126830999,-0.17171397805214,-0.15482030808926001,-0.13349716365337,-0.11320009082556,-0.099639952182769997,-0.087087556719779996,-0.071964003145694996,-0.055626031011343002,-0.037144906818867,-0.019728705286980001,-0.0081783467903732993,0.0048856120556593002,0.025576174259185999,0.050032369792461,0.078272975981236004,0.10556975752115,0.12580999732018,0.14536389708519001,0.16889534890652,0.19333289563656,0.21803374588489999,0.24105198681355,0.25798499584197998,0.27664706110954002,0.30479428172112,0.33549591898918002,0.36585873365402,0.39321097731589999,0.41216936707496998,0.42933177947998002,0.45022675395012002,0.47080928087233997,0.48936682939529003,0.50527161359786998,0.51540321111678999,0.52602744102478005,0.54392457008362005,0.56264436244964999,0.57822757959366,0.59134966135025002,0.60024291276931996,0.60843360424042003,0.62004613876342995,0.63062167167663996,0.63703244924544999,0.64027518033981001,0.64032977819443004,0.63705271482467996,0.62916439771652,0.62015652656554998,0.61322474479675004,0.60730886459350997,0.60249686241150002,0.59859925508499001,0.59613704681395996,0.59306335449219005,0.58723145723342995,0.57979726791382002,0.57121604681015004,0.56133913993835005,0.55022698640822998,0.53771173954009999,0.52362626791,0.50804877281188998,0.49131628870964,0.47247186303138999,0.44935196638107,0.42603442072867997,0.40681219100951999,0.38854062557219998,0.36963140964508001,0.34987238049507002,0.32796186208724998,0.30561983585357999,0.28477075695991999,0.26342487335205,0.24020847678185001,0.21525388956069999,0.19674690067768,0.15915443003178001,0.11147877573966999,0.089383661746978996,0.060647990554570999,0.033740513026713999,0.0075655058026313999,-0.014954535290598999,-0.037356104701757001,-0.062821343541145006,-0.089591890573502003,-0.11752647161484001,-0.14492480456828999,-0.16924898326397,-0.19274555146694,-0.21737287938595001,-0.24159188568591999,-0.26494026184081998,-0.28606712818146002,-0.30245310068129999,-0.31695500016212003,-0.33182191848754999,-0.34662610292434998,-0.36176416277884998,-0.37703236937522999,-0.39220741391182001,-0.40772220492362998,-0.42463350296021002,-0.44094151258469,-0.45493736863135997,-0.46650257706642001,-0.47439920902251997,-0.48014497756958002,-0.48504677414893999,-0.48875451087951999,-0.49134752154349998,-0.49283599853516002,-0.49312147498130998,-0.49260592460632002,-0.49173966050147999,-0.49037608504294999,-0.48850899934768999,-0.48615586757660001,-0.48319780826568998,-0.48003038764,-0.47758361697196999,-0.4742888212204,-0.46835896372795,-0.46093150973320002,-0.45238447189330999,-0.44341614842415,-0.43530714511870999,-0.42698690295219,-0.41746553778647999,-0.40748557448387002,-0.39741358160973,-0.38756394386291998,-0.3787716627121,-0.37003079056740001,-0.36026167869567999,-0.35017135739326,-0.34007099270821001,-0.33024531602858997,-0.32242572307586997,-0.31289052963257002,-0.29639971256255998,-0.27757489681244002,-0.25998210906982,-0.24313235282897999,-0.2287105768919,-0.21403318643569999,-0.19550342857837999,-0.17627853155136,-0.15889659523964,-0.14282175898551999,-0.12910914421082001,-0.11564661562443,-0.099415458738804002,-0.083056665956974002,-0.068969652056694003,-0.055999923497438001,-0.044673133641480997,-0.032152980566025002,-0.013542303815484,0.0062989220023155004,0.022599875926970998,0.037614315748214999,0.051686093211173997,0.066415362060069996,0.085180766880512002,0.10426260530949,0.11957620829344,0.13353297114372001,0.14725409448147,0.16147917509078999,0.17869526147841999,0.19565343856812001,0.2083373516798,0.21948593854904,0.23087301850319,0.24268528819084001,0.25683212280272999,0.27052277326584001,0.28007632493973,0.28812971711159002,0.29665973782539001,0.30538037419318997,0.31528607010840998,0.32473766803741,0.33118385076522999,0.33705091476440002,0.34464088082313998,0.35333731770514998,0.36424612998962003,0.37461447715759,0.38034155964851002,0.38424471020699003,0.38861238956451,0.39265906810759998,0.39673820137978,0.39956024289130998,0.39904618263245001,0.39671343564986999,0.39375355839728998,0.39005246758460999,0.38597485423088002,0.38140854239464,0.37652933597565003,0.37085127830504999,0.36357322335242998,0.35532900691031999,0.34666174650192,0.33750280737876998,0.32837650179862998,0.31819266080856001,0.30502787232398998,0.29073897004128002,0.27701276540755998,0.26392528414726002,0.25309666991233998,0.24224822223185999,0.22818419337272999,0.21300528943538999,0.19830313324928001,0.18397884070873,0.17112022638321001,0.15816393494605999,0.14282712340355,0.12669914960861001,0.11112120002508,0.095853872597218004,0.081449143588542994,0.067005567252635997,0.050980679690837999,0.034776922315358998,0.019923446699977001,0.0058546494692564002,-0.0072028031572699998,-0.020290173590183001,-0.035445030778645997,-0.050871573388577,-0.064498089253902005,-0.077350646257400998,-0.089936278760433003,-0.10248811542988,-0.11582002043724,-0.12920534610748,-0.14178439974785001,-0.15398906171321999,-0.16601990163326,-0.17803616821766,-0.19078373908997001,-0.20311035215855,-0.21323962509632,-0.22228965163230999,-0.23123055696486999,-0.23981428146361999,-0.24853684008120999,-0.25620648264884999,-0.26066741347312999,-0.26355323195456998,-0.26642438769340998,-0.26909759640693998,-0.27256074547768,-0.27524405717849998,-0.27446159720420998,-0.27225705981255,-0.27084469795227001,-0.26940259337424999,-0.26819929480553001,-0.2657830119133,-0.25914415717125,-0.25074818730353998,-0.24336004257202001,-0.23610533773899001,-0.22909240424633001,-0.22168616950511999,-0.21245898306370001,-0.20274224877357,-0.19431301951408,-0.18624128401279,-0.17827820777893,-0.16935643553734001,-0.1567394733429,-0.14297057688236001,-0.13149738311768,-0.12051116675138,-0.10896171629429,-0.096173644065857003,-0.079429663717746998,-0.061838254332542003,-0.048125065863131998,-0.035617761313915003,-0.022134920582175002,-0.007792841643095,0.0089891152456403004,0.026136050000787,0.039883870631456,0.053222410380840003,0.069446511566639002,0.088091373443604001,0.11140326410532,0.13546735048294001,0.15335509181022999,0.16920037567616,0.1870928555727,0.2057800590992,0.22604821622372001,0.24534390866756001,0.25830477476120001,0.26886740326880998,0.28176701068878002,0.29525762796402,0.30909493565558999,0.32199871540070002,0.33090096712111999,0.33794313669205001,0.34561255574226002,0.35310247540473999,0.36041474342346003,0.36698451638222002,0.37208512425423002,0.37517452239990001,0.37436649203299999,0.37126401066780002,0.36772963404655001,0.36372724175452997,0.36067628860473999,0.35700285434723,0.34996551275253002,0.34134608507156,0.33297631144523998,0.32476693391799999,0.31897118687629999,0.31168061494826999,0.29495391249656999,0.27432686090469,0.25622582435607999,0.23944097757339,0.22746974229813,0.21376642584801001,0.18437656760216001,0.1495173573494,0.12217240780591999,0.098620958626270003,0.079511716961861004,0.061934117227792997,0.039096608757973002,0.015851359814405001,-0.0012807855382562,-0.014904517680407001,-0.026190616190433998,-0.036222357302903997,-0.048174999654292998,-0.060352988541126001,-0.070558696985245001,-0.080369234085082994,-0.091071903705596993,-0.10400407016277,-0.12441679090261,-0.14693413674830999,-0.16263832151890001,-0.17536531388759999,-0.18776334822178001,-0.20022544264792999,-0.21584004163741999,-0.23187530040741,-0.24370646476746,-0.25387009978294001,-0.26490819454192999,-0.27675828337669001,-0.29149115085602001,-0.30674535036086997,-0.31795895099639998,-0.32785600423812999,-0.33969938755035001,-0.35272628068924,-0.36838442087173001,-0.38347899913787997,-0.39119151234626998,-0.39497917890549,-0.39849281311035001,-0.40089046955108998,-0.40192052721977001,-0.40251129865646001,-0.40459099411964,-0.40759304165839999,-0.41151350736617998,-0.41599994897842002,-0.42086696624755998,-0.42493686079978998,-0.42537248134612998,-0.42320796847343001,-0.41888877749442999,-0.41285020112991,-0.40607464313507002,-0.39876526594161998,-0.39244344830513,-0.38563027977942999,-0.37541159987450001,-0.36349874734879001,-0.35184341669083002,-0.34052014350891002,-0.33132609724998002,-0.32264989614487,-0.31162959337233997,-0.29947167634964,-0.28729367256165,-0.27487301826477001,-0.26278039813041998,-0.24989834427834001,-0.23324649035931,-0.21511787176132,-0.19908022880553999,-0.18432135879993,-0.17143221199511999,-0.15929999947547999,-0.14541585743426999,-0.13098028302192999,-0.11737743765116,-0.10425628721714,-0.091729477047920005,-0.079431988298893003,-0.066683605313301003,-0.053431749343872001,-0.039139408618212003,-0.023985184729099,-0.0081266202032566001,0.0085699837654829008,0.026609688997268999,0.045311313122511,0.063339769840240007,0.080998778343201003,0.098261460661887998,0.11511570215225,0.13122239708899999,0.1472424864769,0.16478037834167,0.18305587768555001,0.20124655961990001,0.21923780441283999,0.23603495955466999,0.25237649679183999,0.26977387070656,0.28730362653732,0.30362313985825001,0.31891351938248003,0.33246904611588002,0.34522679448128002,0.35941371321678001,0.37387743592262002,0.38701373338699002,0.39923244714737,0.41032868623733998,0.42097458243370001,0.43310278654098999,0.44552889466286,0.45640370249748002,0.46611422300339,0.47455370426178001,0.48177921772003002,0.48784664273262002,0.49276515841483998,0.49658593535423001,0.49930611252785001,0.50120592117310003,0.50171113014221003,0.49901086091995001,0.49448090791701999,0.49075001478195002,0.48699042201041998,0.48277705907821999,0.47783303260803001,0.47089347243308999,0.46284550428391003,0.45567235350608998,0.44814184308052002,0.43857875466347002,0.42653599381446999,0.40864735841750999,0.38797944784164001,0.37141737341880998,0.3560416996479,0.33835279941558999,0.31867101788521002,0.29446500539780002,0.26891589164733998,0.25031164288521002,0.23447324335575001,0.21502505242825001,0.19332127273083,0.16796672344208,0.14180494844913,0.12326812744141,0.1075966656208,0.086474962532520003,0.06224425137043,0.034881766885519,0.0073387473821639997,-0.010682306252420001,-0.024266090244054999,-0.042096588760614,-0.061591751873493,-0.081434361636639002,-0.10052269697188999,-0.11386692523956,-0.12472878396511,-0.13982039690018,-0.15671397745609,-0.17309707403183,-0.18844953179359,-0.19897206127643999,-0.20726320147513999,-0.21894958615303001,-0.23187692463397999,-0.24353951215743999,-0.25392591953277999,-0.26107272505759999,-0.26620760560036,-0.27176553010941001,-0.27705818414687999,-0.28159007430076999,-0.28540918231009998,-0.28794133663177002,-0.29011994600295998,-0.29480892419815002,-0.30056047439575001,-0.30485343933105002,-0.30819952487946001,-0.31060126423835999,-0.31201633810996998,-0.31216406822205001,-0.31133127212523998,-0.31022378802299,-0.30866855382919001,-0.30670142173767001,-0.30409565567969998,-0.29985797405242998,-0.29480284452437999,-0.29091170430183,-0.28758037090302002,-0.28438720107079002,-0.28106236457825001,-0.27647218108177002,-0.27094310522079001,-0.26478907465934998,-0.25789770483970997,-0.25033634901047003,-0.24166525900364,-0.22967213392258001,-0.21639102697372001,-0.20728963613510001,-0.20045508444308999,-0.19347307085991,-0.18650618195533999,-0.17809459567069999,-0.16942569613457001,-0.16374431550502999,-0.15967246890067999,-0.15494392812252,-0.14982490241527999,-0.14340454339981001,-0.13648861646652,-0.13134406507015001,-0.12705251574515999,-0.12204735726118,-0.11667162925004999,-0.11073134839535,-0.10485985130071999,-0.10123679041862001,-0.099024243652821003,-0.096903651952744002,-0.095052570104598999,-0.093229077756405002,-0.091485999524593006,-0.089908793568611006,-0.088327869772911002,-0.086199603974819003,-0.083668656647205006,-0.080827847123146002,-0.077730968594551003,-0.074678763747214993,-0.071501038968562997,-0.067757621407509003,-0.063631743192672993,-0.059403177350759999,-0.055131524801254002,-0.051199417561293002,-0.047539159655570998,-0.044242076575755997,-0.041173301637172997,-0.037961494177579998,-0.034618809819220997,-0.030807990580797001,-0.026822617277503,-0.023551493883133,-0.020686583593488,-0.017695961520075999,-0.014725072309375,-0.011886277236043999,-0.0092701287940145007,-0.0074408967047929998,-0.0060003078542649997,-0.0038615833036601999,-0.0012777508236468001,0.0017209248617290999,0.0048612975515424997,0.0069067450240254003,0.0084877358749508997,0.011111060157418,0.014446793124079999,0.018485156819224,0.022880785167217001,0.025982497259974001,0.028746820986271002,0.033770579844713003,0.040321663022041002,0.047639008611440999,0.055458948016166999,0.061785437166691,0.067860402166842998,0.077362708747387002,0.089041717350482996,0.10089437663555,0.11282713711262,0.12280301749706,0.13179855048656,0.14240300655365001,0.15371207892895,0.16406230628490001,0.17359967529774001,0.18139995634556,0.18826900422573001,0.19703151285647999,0.20663005113602001,0.21488600969315,0.22211438417435,0.22775684297085,0.23247432708740001,0.23876032233238001,0.24570116400719,0.25136858224869002,0.25609770417213001,0.25984132289886003,0.26276680827141002,0.26552832126616999,0.26793524622916998,0.26965770125388999,0.27077072858809997,0.27147936820983998,0.27156338095665,0.27014636993407998,0.26755103468894997,0.26465082168579002,0.26105493307114003,0.25616586208344,0.24940538406372001,0.23699159920216001,0.22107844054699,0.20846267044544001,0.19732441008091001,0.18514016270638001,0.17165037989616,0.15284650027752,0.13136649131774999,0.11627452820539,0.10499296337366,0.093045674264431,0.080798603594303006,0.065982230007647996,0.050300575792789001,0.040370713919401002,0.033681228756904998,0.02399373985827,0.012229580432176999,-0.0026293154805899,-0.01926975697279,-0.031660113483666999,-0.042448103427886998,-0.059294380247593002,-0.080674171447754003,-0.1066712886095,-0.13494943082333,-0.15402670204638999,-0.16755940020084001,-0.18396650254725999,-0.20167192816734,-0.21987757086754001,-0.23786783218384,-0.25090211629867998,-0.26134499907494002,-0.27720609307289001,-0.29637554287910001,-0.31554889678955,-0.33410367369652,-0.34606134891509999,-0.35363164544106002,-0.36292484402656999,-0.37272119522094999,-0.38181030750275002,-0.39003935456276001,-0.39555343985558,-0.39921426773071,-0.40394008159637002,-0.4090088903904,-0.41314002871513,-0.41639384627342002,-0.41812747716903997,-0.41853433847427002,-0.41822823882103,-0.41685900092125,-0.41318419575691001,-0.40733730792999001,-0.39966079592705001,-0.38925611972808999,-0.37075453996657998,-0.34658923745155001,-0.32501196861267001,-0.30466133356094,-0.28559499979018999,-0.26652505993843001,-0.24007949233055001,-0.20894914865493999,-0.18158310651779,-0.15635040402412001,-0.13182330131531,-0.10706853866577,-0.075124323368072995,-0.038847096264362002,-0.0084173362702130994,0.018521036952734,0.046024456620216002,0.074595034122466999,0.11133137345314,0.15286783874035001,0.18607465922832001,0.21394014358520999,0.24227251112461001,0.27076524496078003,0.30275526642799,0.33645898103714,0.36425548791884999,0.38816770911217002,0.41331854462624001,0.43921816349030002,0.46772319078445002,0.49741202592849998,0.52139490842819003,0.54148751497268999,0.56251794099807995,0.58384960889815996,0.60633230209350997,0.62862712144851995,0.64327436685562001,0.65228670835494995,0.6613547205925,0.66968095302581998,0.67720532417296997,0.68349850177765004,0.68590056896210005,0.68519639968872004,0.68393975496292003,0.68168544769286998,0.67814642190933005,0.67282545566559004,0.66224735975266003,0.64742928743362005,0.63168114423751998,0.61453658342360995,0.59590888023375999,0.57552617788314997,0.55155313014983998,0.52454900741577004,0.49644148349762002,0.46698549389839,0.43630933761597002,0.40418261289597002,0.36892774701117997,0.33131167292594998,0.29509302973746998,0.25933572649955999,0.22126865386962999,0.18108896911144001,0.13701342046261,0.090469978749752003,0.049821242690085997,0.012887470424175001,-0.027553167194127998,-0.070624887943268003,-0.11682973057032001,-0.16528604924679,-0.21057224273681999,-0.25385916233062999,-0.29851803183556003,-0.34404423832893,-0.39044791460036998,-0.43674540519714,-0.47562775015830999,-0.50918132066726995,-0.54561626911162997,-0.58364331722259999,-0.62161815166473,-0.65895324945449996,-0.69008529186249001,-0.71639591455460006,-0.74284243583678999,-0.76869541406631003,-0.79313534498214999,-0.81580948829651001,-0.83354401588439997,-0.84703147411346003,-0.85844796895981001,-0.86758542060851995,-0.87470370531081998,-0.87968188524246005,-0.88232403993607,-0.88222354650497004,-0.87576878070830999,-0.86405605077743997,-0.85191828012465998,-0.83886802196502996,-0.82633024454116999,-0.81282222270965998,-0.78756618499756004,-0.75333708524704002,-0.72171258926392001,-0.69139438867569003,-0.66341656446456998,-0.63587325811385997,-0.59387582540511996,-0.54132497310637995,-0.49566501379013,-0.45460397005080999,-0.41639852523804,-0.37915819883347002,-0.32544031739235002,-0.25966203212737998,-0.20187279582024001,-0.14937272667884999,-0.098013877868651997,-0.04716994613409,0.0123993717134,0.077861338853836004,0.13378912210464,0.18275457620621,0.23194657266140001,0.28155279159545998,0.34074077010155002,0.40607094764709001,0.45604559779166998,0.49455511569977001,0.53513908386230002,0.57717078924178999,0.62830162048339999,0.68520718812943004,0.72554463148116999,0.75330728292464999,0.78331786394118996,0.81442201137543002,0.85015690326690996,0.88827937841414994,0.91176921129226995,0.92379188537598,0.93748724460601995,0.95157247781753995,0.96618843078613004,0.98033452033997004,0.98520225286483998,0.98234236240386996,0.97804522514342995,0.97174984216689997,0.96354812383652,0.95325285196303999,0.93955415487288996,0.92253291606902998,0.90161937475204001,0.87707829475402999,0.85066628456116,0.82234543561935003,0.79384809732437001,0.76441329717635997,0.72783422470092995,0.68528640270232999,0.64218604564667003,0.5985079407692,0.55927360057830999,0.52315431833267001,0.48133176565169999,0.43508687615394998,0.38932663202286,0.34387010335922003,0.30158981680870001,0.26145151257514998,0.21501432359219,0.16377404332161,0.11550344526768,0.069658651947975006,0.027729079127312001,-0.011056881397963,-0.053568720817566001,-0.098697423934936995,-0.14079169929027999,-0.18032503128051999,-0.21756182610989,-0.25260022282599998,-0.28662624955177002,-0.31939291954040999,-0.34919020533562001,-0.37623995542526001,-0.40134447813034002,-0.42458570003509999,-0.44799247384071,-0.47096195816994002,-0.48837101459503002,-0.50084632635116999,-0.51090699434279996,-0.51845896244048995,-0.52471143007277998,-0.52930265665053999,-0.52895170450211004,-0.52416735887527,-0.51791256666183005,-0.51005357503891002,-0.50177645683288996,-0.49273651838303001,-0.47970020771027,-0.46317702531815003,-0.44642552733420998,-0.42926090955733998,-0.41315937042236001,-0.39722272753715998,-0.37090370059013,-0.33573377132415999,-0.30139446258545,-0.26727923750876997,-0.23434163630009,-0.20208473503589999,-0.16464218497276001,-0.12306924164294999,-0.085919454693794001,-0.05254590138793,-0.022376280277966999,0.0049819312989712004,0.035266142338514002,0.067744955420493996,0.097532615065575007,0.12509927153587,0.15196202695370001,0.17860485613346,0.21412399411201,0.25698789954184997,0.29385170340538003,0.32570600509643999,0.35506334900856001,0.38178741931915,0.40552085638045998,0.42625984549522,0.44335168600081998,0.45708802342415,0.47092437744141002,0.48481270670891002,0.50187456607819003,0.52141702175140003,0.53577721118927002,0.54551291465759,0.55250352621078003,0.55662018060684004,0.55697298049927002,0.55371427536010998,0.54845517873764005,0.54115444421768,0.53259736299515004,0.52272021770476995,0.51106899976730003,0.49780169129371998,0.48587381839751997,0.47470369935036,0.45696276426315002,0.43315038084983998,0.40427106618880998,0.37087148427963001,0.34416860342026001,0.32289397716522,0.29445317387580999,0.25970381498336997,0.22219681739807001,0.18234489858149999,0.15167693793774001,0.12885691225529,0.099140159785748,0.063536018133162994,0.02763263694942,-0.0084419623017310992,-0.035997007042170001,-0.056443244218826003,-0.090579070150851995,-0.13678798079491,-0.18208417296410001,-0.22663621604442999,-0.26147651672362998,-0.28781250119209001,-0.32292377948760997,-0.36551764607429998,-0.40389293432236001,-0.43836581707000999,-0.46456378698348999,-0.48332545161246998,-0.50953829288482999,-0.54211539030074996,-0.57012015581131004,-0.59394985437393,-0.61245495080947998,-0.62614154815673995,-0.64634639024733997,-0.67215800285339,-0.69198787212372004,-0.70630508661269997,-0.71632534265518,-0.72208338975905995,-0.72477447986603005,-0.72441357374190996,-0.72254425287247004,-0.71911406517028997,-0.71441143751143998,-0.70837044715881003,-0.69925248622893998,-0.68724316358565996,-0.67607390880585005,-0.66555917263030995,-0.65408217906952004,-0.64159697294234996,-0.62496984004973999,-0.60447257757187001,-0.58562523126601995,-0.56812292337418002,-0.54791164398193004,-0.52498412132262995,-0.49424484372138999,-0.45629319548607,-0.42654573917388999,-0.40431538224219998,-0.38094085454941001,-0.35658800601959001,-0.32915496826172003,-0.29887837171554998,-0.27251803874968999,-0.24967929720879001,-0.22195306420326,-0.18954162299633001,-0.15109165012836001,-0.1070564314723,-0.075117185711861004,-0.054507020860909999,-0.030267398804425999,-0.0027551464736461999,0.026729498058558,0.058020807802677002,0.082599014043807997,0.10081971436739,0.12114980071783001,0.14338569343089999,0.16577723622321999,0.18824441730975999,0.20489796996116999,0.21597689390182001,0.22863349318504,0.24269860982895,0.25563234090804998,0.26740998029709001,0.27413484454155002,0.27593842148781,0.27705651521683,0.27742049098014998,0.27655223011970997,0.27443611621857,0.26970627903937999,0.26239284873009,0.25330442190169999,0.24244053661823001,0.23053097724915,0.21756091713904999,0.20315214991569999,0.18729485571384,0.16866102814674,0.14727190136908999,0.12389990687370001,0.098538741469383004,0.071156278252601998,0.041754115372896,0.010208498686551999,-0.023449655622243999,-0.054892331361770998,-0.084153793752193007,-0.11196642369032,-0.13833323121071001,-0.16416853666306,-0.18947298824787001,-0.21549154818058,-0.24221783876419001,-0.26937571167946001,-0.29696652293205,-0.32551628351211997,-0.35501801967620999,-0.38227361440659002,-0.40728935599326999,-0.43116721510887002,-0.45390665531157998,-0.47609663009643999,-0.49773913621902,-0.51632106304169001,-0.53183674812316994,-0.54638272523880005,-0.55996274948119995,-0.57262319326401001,-0.58437138795853005,-0.59295731782912997,-0.59836202859878995,-0.60316687822341997,-0.60738253593445002,-0.61192703247070002,-0.61687809228896995,-0.60906612873077004,-0.58831888437270996,-0.56817400455474998,-0.54872280359268,-0.52974647283553999,-0.51127833127974998,-0.48977905511856001,-0.46517458558083002,-0.44234946370125,-0.42137435078620999,-0.40068146586418002,-0.38040322065352999,-0.34598299860954002,-0.29703465104103,-0.25237780809402,-0.21229293942451,-0.17237024009228,-0.13268232345580999,-0.083882763981819,-0.025620803236961,0.026583151891828,0.072400458157063002,0.11853700876235999,0.16498947143555001,0.21881380677223,0.28046754002571,0.32922369241714,0.36446166038513,0.40084266662598,0.43851643800735002,0.48373249173164001,0.53700494766234996,0.57804769277572998,0.60614061355590998,0.63701856136321999,0.67094540596008001,0.7109706401825,0.75762540102005005,0.78999650478363004,0.80730646848679,0.82300204038619995,0.83737289905547996,0.85008645057678001,0.86120510101318004,0.86850124597549005,0.87179148197173995,0.87622195482253995,0.88195681571960005,0.88802665472030995,0.89451944828033003,0.89767980575562001,0.89742273092269997,0.89279025793075995,0.88369280099868996,0.87194275856018,0.85759460926055997,0.84119838476180997,0.82305562496185003,0.79309701919555997,0.75064796209335005,0.70663702487946001,0.66117131710052002,0.62236088514328003,0.59102135896682995,0.55063581466675005,0.50023782253265003,0.45207580924034002,0.40638324618339999,0.3687509894371,0.33999073505402,0.30301392078400002,0.25677955150603998,0.21299193799496,0.17201556265354001,0.13547074794769001,0.10393073409796,0.063828080892563005,0.014080844819546001,-0.030964866280555999,-0.070687785744666998,-0.10650537908077,-0.13805222511292001,-0.17563100159167999,-0.22025090456009,-0.25781694054603999,-0.28759920597076,-0.31291499733924999,-0.33364918828010998,-0.35499483346938998,-0.37736123800277999,-0.39687368273735002,-0.41329577565192999,-0.42832222580910001,-0.44195631146431003,-0.45606711506844,-0.47107741236687001,-0.47959506511687999,-0.48108553886414002,-0.47939139604567998,-0.47468927502632002,-0.46647793054580999,-0.45463991165161,-0.44141554832458002,-0.42692938446999001,-0.41105455160141002,-0.39382487535477001,-0.37430202960968001,-0.35216277837753002,-0.33308216929436002,-0.31757509708405002,-0.30161905288696,-0.28502276539803001,-0.26754212379455999,-0.24902011454105,-0.23194469511509,-0.21657457947730999,-0.20069919526576999,-0.18418528139591001,-0.16723698377609,-0.14976750314236001,-0.13345701992511999,-0.11848945170641,-0.1033818051219,-0.088026985526084997,-0.072780899703503002,-0.057573728263377998,-0.043952167034149003,-0.032094128429889998,-0.020613811910152002,-0.0093805864453315995,0.00085003837011755001,0.010137603618205,0.016683848574757999,0.020260911434888999,0.022538810968398999,0.023580316454171999,0.024013143032789001,0.023901306092739001,0.023052485659718999,0.021436829119921001,0.019280439242720999,0.016470875591040001,0.014961579814553001,0.014840872958302,0.017134053632617,0.022145833820105001,0.026642739772796999,0.030474610626698002,0.032467439770698998,0.032532829791306998,0.030231976881623001,0.025410275906324001,0.019554931670427,0.012614556588232999,0.0069522866979240998,0.0027768709696828998,-3.4966855309904001e-05,-0.0013785443734378,-0.0026952535845338999,-0.0042137727141379998,-0.0042495215311646002,-0.0026100729592143999,-0.00016861339099705,0.0031248456798494001,0.0058025484904647004,0.0077763316221534998,0.0084699308499693992,0.0077714482322335,0.0063224555924534997,0.0041182832792401002,0.0017562052235007,-0.00084724510088562998,-0.0017382217338309,-0.00061083526816219005,0.00084419746417552005,0.0025368684437125999,0.0039313635788857998,0.0049347057938575996,0.0059706773608923002,0.0070924959145485999,0.008012511767447,0.0086956461891531996,0.0093172043561935008,0.0099172666668891993,0.010133736766875,0.0098904082551599,0.0097272135317326008,0.0096798008307814997,0.0099106524139642993,0.010472667403518999,0.010977322235703,0.011398687027395001,0.011665381491184,0.011823791079223,0.01142914313823,0.010805488564074,0.0052197678014635996,-0.0063662165775894997,-0.017202138900756999,-0.026504397392273001,-0.035947188735007997,-0.045288681983947997,-0.058771077543497002,-0.077317073941230996,-0.095192141830921007,-0.11145041882992,-0.13029880821705001,-0.15146194398403001,-0.18326739966868999,-0.22829486429691001,-0.26742973923683,-0.29780778288840998,-0.3295606970787,-0.36307439208031,-0.40485209226607999,-0.45780944824219,-0.49821588397026001,-0.52232730388641002,-0.54356545209884999,-0.56309336423874001,-0.58157020807266002,-0.59977251291275002,-0.61127704381943004,-0.61466252803802002,-0.61759889125823997,-0.62093907594680997,-0.62412446737288996,-0.62737780809402,-0.62850320339203003,-0.62694770097732999,-0.62587958574295,-0.62574046850204001,-0.62576264142990001,-0.62641757726669001,-0.62240970134734996,-0.61312109231948997,-0.59823602437973,-0.57734495401382002,-0.55322515964508001,-0.52578830718993996,-0.49961745738982999,-0.47633752226830001,-0.44543257355690002,-0.40485399961472002,-0.36242306232451998,-0.31839388608932001,-0.27915173768996998,-0.24733015894890001,-0.20544502139091,-0.14980351924895999,-0.095347121357917994,-0.043115749955177002,-6.3055194914341e-05,0.030290704220533,0.071757256984710999,0.12920725345612,0.18476520478725,0.23663491010665999,0.28230690956116,0.31946435570717002,0.36508917808532998,0.42320853471755998,0.47685956954955999,0.52389597892760997,0.56492036581038996,0.59823954105376997,0.63851326704025002,0.68953001499176003,0.73477864265441994,0.77179527282714999,0.80413031578063998,0.83114087581634999,0.86135071516036998,0.89752018451690996,0.92576938867569003,0.94367569684982,0.95654296875,0.96454131603241,0.97112935781479004,0.97766208648681996,0.97704780101776001,0.96785068511963002,0.95426666736603005,0.93684607744216997,0.91508138179778997,0.88896280527115001,0.85840624570847002,0.82324320077895996,0.78482884168625,0.74349057674408003,0.69780451059340998,0.64665269851685003,0.59802407026291005,0.55368119478225997,0.50880330801009999,0.46286115050316001,0.41533842682838001,0.36589112877845997,0.31618103384972002,0.26669579744339,0.21536357700825001,0.16182893514633001,0.10622200369835,0.047412268817425003,-0.0051211565732956002,-0.048481501638889,-0.094077676534653001,-0.14388886094093001,-0.19533218443393999,-0.24905198812484999,-0.29808855056763001,-0.34064984321594,-0.38187712430954002,-0.42259818315505998,-0.46180182695388999,-0.49972543120384,-0.53376621007919001,-0.56301701068877996,-0.59122580289840998,-0.61928641796112005,-0.64480578899384,-0.66795194149017001,-0.68475008010864002,-0.69391250610351995,-0.69988924264908003,-0.70345795154571999,-0.70378881692885997,-0.70104646682739002,-0.69337046146393,-0.67977070808411,-0.66552555561065996,-0.65244764089583995,-0.63352704048157005,-0.60783874988555997,-0.57337164878845004,-0.52732920646667003,-0.48735487461089999,-0.45864218473433999,-0.42525306344031999,-0.38443267345428001,-0.33801597356795998,-0.28388923406601002,-0.23830880224705001,-0.20707294344902,-0.16904386878013999,-0.11978518217802001,-0.065936654806137002,-0.0060721486806870001,0.043282452970742999,0.075660631060600003,0.11531942337751,0.16786980628966999,0.22273844480515001,0.28037419915199002,0.32695129513741,0.35727494955062999,0.38861307501793002,0.4247852563858,0.45932313799857999,0.49208921194076999,0.51794087886810003,0.53463453054428001,0.55026137828827004,0.56668061017990001,0.58078980445862005,0.59241235256195002,0.60003113746643,0.60351657867431996,0.60114717483520996,0.59170842170714999,0.58085346221923995,0.56966680288314997,0.55828773975372004,0.54816621541976995,0.53029179573059004,0.50120842456818004,0.47231897711754001,0.44601261615753002,0.42047733068465998,0.39788115024567,0.36242076754570002,0.30728363990784002,0.25652807950973999,0.21569086611270999,0.17808926105499001,0.14482852816582001,0.10301943123340999,0.046556361019610998,-0.0023870067670941002,-0.037956267595290999,-0.070481650531292003,-0.10009630024433,-0.13665890693665,-0.18524511158466,-0.22759531438350999,-0.25859335064888,-0.28822970390320002,-0.31743973493576,-0.35112908482552002,-0.39303570985794001,-0.42718443274498002,-0.44864481687545998,-0.46797665953635997,-0.48681494593620001,-0.50665706396103005,-0.52973365783690995,-0.54547411203384,-0.55037218332291005,-0.55240279436110995,-0.55305385589599998,-0.55206596851348999,-0.54997247457503995,-0.54436743259429998,-0.53451985120773005,-0.52175492048264005,-0.50624197721481001,-0.48830199241638,-0.46803283691406,-0.44557324051857,-0.42144149541855003,-0.39266085624695002,-0.35804575681686002,-0.32052722573280001,-0.27973288297652998,-0.24168594181538,-0.20940494537354001,-0.17341108620167001,-0.13072690367699,-0.087124913930893,-0.042573459446429998,-0.0039591090753675002,0.024781864136456999,0.056725468486546998,0.095852836966515004,0.13536976277828,0.17449255287647,0.21064126491547,0.24198530614375999,0.27473741769790999,0.31098225712776001,0.34656536579132002,0.38081094622612,0.41288733482361001,0.44171181321143999,0.47191599011420998,0.50581467151642001,0.53626096248626998,0.56164330244063998,0.58200716972350997,0.59668999910355003,0.60814583301544001,0.61687386035919001,0.62330090999603005,0.62760859727858997,0.62986093759536999,0.63000982999802002,0.62864816188812001,0.62627077102661,0.62092602252960005,0.61191892623901001,0.60048985481261996,0.58674144744873002,0.57149267196654996,0.55517405271529996,0.53672909736633001,0.51569199562072998,0.49334019422531,0.46984791755675998,0.44596412777901001,0.42243397235870001,0.39638021588326,0.36651268601418002,0.33597823977469998,0.30534958839416998,0.27544248104094998,0.24676065146923001,0.21833407878875999,0.18982540071011,0.16195203363895,0.13486061990261,0.10870005935431,0.084083780646324005,0.057938940823078003,0.028751060366630998,0.00028285104781388998,-0.026461578905582001,-0.052083998918532999,-0.076581314206123005,-0.10010883212089999,-0.12292340397835,-0.14388012886047,-0.16255041956902,-0.17956881225109,-0.19504283368587,-0.20907038450241,-0.22169822454453,-0.23292602598667,-0.24271205067634999,-0.25133144855499001,-0.25896638631821001,-0.26504927873611001,-0.26924580335616999,-0.27254176139831998,-0.27526482939719998,-0.27705454826355003,-0.27793034911156,-0.27743452787398998,-0.27511635422706998,-0.27260434627532998,-0.27055147290230003,-0.26791191101074002,-0.26456630229950001,-0.25989216566085999,-0.25323319435120001,-0.2468713670969,-0.24178229272366,-0.23622378706932001,-0.22984725236893,-0.22228080034256001,-0.21278536319732999,-0.20428085327147999,-0.19820669293404,-0.19152215123176999,-0.1833952665329,-0.17407760024071001,-0.16297100484370999,-0.15288995206355999,-0.14534422755241,-0.13696131110191001,-0.12663602828979001,-0.11540437489748,-0.10275731235743001,-0.092140659689902996,-0.085328906774520999,-0.078884541988372997,-0.071720257401465995,-0.064858727157116006,-0.058194972574710999,-0.053093500435351999,-0.050209071487187999,-0.048566009849309998,-0.048028286546468998,-0.048165049403906,-0.048958260565995997,-0.049621850252150997,-0.049731016159057999,-0.050006430596112997,-0.050740443170071002,-0.051394794136285997,-0.051889259368181,-0.051918178796768001,-0.051231980323791997,-0.050445813685656003,-0.049761898815631998,-0.049061391502618998,-0.048364054411650002,-0.047534439712762999,-0.046473056077957001,-0.045444786548615002,-0.044588003307581003,-0.043616883456707001,-0.042444009333849002,-0.041125297546387003,-0.039883237332105997,-0.037644203752278997,-0.033671792596579,-0.029779613018036,-0.026641726493835002,-0.023644097149372,-0.020784245803951999,-0.017542740330100001,-0.013511331751943001,-0.0097030345350504008,-0.0065426416695118002,-0.0034943337086588001,-0.00054872198961675004,0.0028738786932081001,0.0073586292564868996,0.011196498759090999,0.01366542186588,0.015578656457365,0.017134139314294,0.018262146040797001,0.01907841488719,0.019074261188507,0.017888640984893001,0.016375564038753999,0.014816167764365999,0.013161825016141,0.011648505926131999,0.0093281045556068004,0.0056836372241378004,0.0015732899773866001,-0.0027348501607776,-0.0073398789390922,-0.012089222669601,-0.017640493810176999,-0.024361696094275,-0.031644966453314001,-0.039296753704548,-0.047408849000931001,-0.056098312139510997,-0.064832165837288,-0.073315821588038996,-0.082005769014359006,-0.091085687279700997,-0.10033414512873,-0.10992625355721,-0.11879999190569,-0.12618158757687001,-0.13373656570910999,-0.14217822253703999,-0.15076124668120999,-0.15960064530373,-0.16738919913768999,-0.17324176430702001,-0.17877443134785001,-0.18468600511551,-0.19014498591423001,-0.19511178135872001,-0.19878740608692,-0.20050352811812999,-0.20169417560101,-0.20307850837708,-0.20361912250518999,-0.20313672721386,-0.20108035206795,-0.19706951081752999,-0.19158163666725,-0.18476183712482,-0.17656056582928001,-0.16711412370205,-0.15585725009441001,-0.14250433444977001,-0.12735360860825001,-0.11064686626196001,-0.091649860143660999,-0.069902338087558996,-0.046139243990183001,-0.019607998430728999,0.0053585721179843001,0.025318440049886998,0.047460451722144997,0.074950195848941997,0.10510800778866,0.13877812027931,0.16981893777847001,0.19352456927299,0.21894073486328,0.25032553076744002,0.28301820158958002,0.31687861680983997,0.34704482555388999,0.3689728975296,0.39244240522384999,0.42248898744583002,0.45294797420501998,0.48270925879477999,0.50871765613555997,0.52763295173644997,0.54664754867554,0.56959372758865001,0.59159010648726995,0.61145079135894997,0.62784028053284002,0.63890290260314997,0.64876866340636996,0.65951395034789995,0.66901206970214999,0.67672616243362005,0.68249940872192005,0.68642318248749001,0.68732696771622004,0.68401062488555997,0.67919987440108998,0.67413526773453003,0.66813832521438998,0.66263383626937999,0.65139347314835006,0.62923717498778997,0.60626947879791004,0.58716201782226995,0.56853514909743996,0.55120247602463002,0.52900618314742998,0.49631509184837003,0.46448314189911,0.43944692611693997,0.41506898403168002,0.39097976684570002,0.36132273077964999,0.31943911314010998,0.28021416068076999,0.25221389532089,0.22523772716522,0.19713106751442,0.16316136717796001,0.11601136624812999,0.073701225221157005,0.047180525958538,0.022895241156219999,-0.0033085066825151001,-0.033063974231482003,-0.070994734764098996,-0.10550211369991,-0.12907165288924999,-0.1518769711256,-0.17772957682609999,-0.2059497833252,-0.23979160189629001,-0.26819121837616,-0.28306394815445002,-0.29641252756119002,-0.31342437863349998,-0.33145931363106002,-0.35192653536796997,-0.36826235055923001,-0.37534663081169001,-0.38091149926186002,-0.38851568102836997,-0.39586660265923002,-0.40342020988464,-0.40768623352050998,-0.40591955184937001,-0.40194195508956998,-0.39727452397346003,-0.3916015625,-0.38517764210701,-0.37766981124878002,-0.36907130479813,-0.35891973972321001,-0.34653908014297002,-0.33354803919791998,-0.32044818997383001,-0.30814269185066001,-0.29801785945892001,-0.28707274794579002,-0.27331894636154003,-0.25923469662665999,-0.24566064774990001,-0.23293046653270999,-0.22241292893886999,-0.21029368042946001,-0.19342350959778001,-0.17686367034912001,-0.16286337375641,-0.1509467959404,-0.14233937859535001,-0.13331022858620001,-0.12095288932323001,-0.10934442281723,-0.1004139482975,-0.093109682202339006,-0.087781593203545005,-0.082514271140099002,-0.075555063784121995,-0.069673635065556003,-0.066313818097114993,-0.064521595835685994,-0.064312256872654003,-0.064812250435352006,-0.065093658864498,-0.066743083298205996,-0.070742972195147996,-0.076074585318564994,-0.082367770373820995,-0.089636601507664004,-0.097795382142066997,-0.1068721562624,-0.11688718944788,-0.12775205075741,-0.13939115405083,-0.15191671252250999,-0.16575405001640001,-0.17951840162277,-0.19227567315102001,-0.20478385686874001,-0.21723362803459001,-0.22978822886944,-0.24290910363196999,-0.25543251633643999,-0.26648312807083002,-0.27708315849303999,-0.28765201568603999,-0.29816967248916998,-0.30901971459388999,-0.31912848353385997,-0.32771870493888999,-0.33555534482001997,-0.34302172064781,-0.34976837038994002,-0.35612502694129999,-0.36044669151306002,-0.36113086342812001,-0.36055415868759,-0.36002042889594998,-0.35878422856330999,-0.35714721679688,-0.35348027944565003,-0.34601601958275002,-0.33767572045326,-0.33032464981079002,-0.32236018776893999,-0.31361883878708002,-0.30267491936683999,-0.28754955530166998,-0.27190864086151001,-0.25830987095833002,-0.2442798614502,-0.22901685535908001,-0.21195323765278001,-0.19145295023917999,-0.17130918800830999,-0.15463492274283999,-0.13769960403442,-0.11889830231666999,-0.098036698997020999,-0.073009930551051996,-0.049368061125278001,-0.031770132482052002,-0.014821304008365,0.0040983781218528999,0.024193022400141002,0.046701155602931997,0.067750290036201005,0.083597220480442005,0.099395036697388001,0.11815395951271,0.13810081779957001,0.15996181964874001,0.17972803115845001,0.19333045184611999,0.20614175498486001,0.22132879495621,0.23693414032459001,0.25315555930138001,0.26751127839088001,0.27730664610862998,0.28615891933441001,0.29628586769103998,0.30620908737183,0.31574440002441001,0.32399296760558999,0.32975947856902998,0.33484390377998002,0.34045007824897999,0.34567674994469,0.35021150112152,0.35404038429259999,0.35658428072928999,0.35950684547424,0.36432027816772,0.36935231089592002,0.37384963035583002,0.37770646810531999,0.38064384460449002,0.38267642259598,0.38354721665382002,0.38391005992888999,0.38421049714088001,0.38429573178290999,0.38414666056633001,0.38385626673697998,0.38342198729514998,0.38306114077567999,0.38296660780906999,0.38302010297775002,0.38342466950416998,0.38338279724120999,0.38198795914650002,0.38050135970116,0.37973541021347001,0.37925940752029003,0.37924411892891002,0.37879186868668002,0.37689459323883001,0.37484499812125999,0.37355509400367998,0.37228450179099998,0.3708952665329,0.36883229017258001,0.36524546146393,0.36144286394119002,0.35846352577209001,0.35536637902259999,0.35184711217879999,0.34749794006348,0.34136086702347002,0.33529251813888999,0.33113133907317999,0.32663154602050998,0.32067295908928001,0.31294158101081998,0.30145883560181003,0.29089286923409002,0.28613093495369002,0.2812140583992,0.27241533994674999,0.26123267412186002,0.24667526781558999,0.23237080872058999,0.22229662537575001,0.21187062561511999,0.19799596071243,0.18264980614185,0.1659080684185,0.14975333213806,0.13711389899254001,0.12368685007095,0.10603412985801999,0.086854450404643999,0.066430851817131001,0.047662418335675999,0.035004507750273001,0.021896466612815999,0.0029677096754313001,-0.017464747652410999,-0.037915885448455998,-0.056867681443690997,-0.071182541549206002,-0.085562169551849004,-0.10404612123966001,-0.12313119322061999,-0.14126619696616999,-0.15795032680035001,-0.17138335108757,-0.18453738093375999,-0.20022183656692999,-0.21567556262015999,-0.22935405373573001,-0.24146868288517001,-0.25127372145652999,-0.26025041937827997,-0.26976716518402,-0.27874112129210998,-0.28658083081245,-0.29354569315910001,-0.29964619874954002,-0.30498865246772999,-0.30984088778496,-0.31365436315535999,-0.31593096256255998,-0.31701135635375999,-0.31709387898445002,-0.31600585579871998,-0.31347417831420998,-0.31007456779480003,-0.30624982714652998,-0.30192017555237,-0.29712963104248002,-0.29194304347038003,-0.28664225339889998,-0.28056615591049,-0.27300557494164002,-0.26462605595589,-0.25573867559433,-0.24653042852879001,-0.23737752437592,-0.22792363166808999,-0.21775151789187999,-0.20752961933613001,-0.19768434762955001,-0.18835042417049,-0.17999888956547,-0.17195630073547,-0.16352298855781999,-0.15543271601200001,-0.14818935096263999,-0.14162012934685,-0.13592913746834001,-0.13048800826073001,-0.12445425242186001,-0.11884601414204,-0.11445541679859,-0.11091159284115,-0.10799442231655,-0.10609529167414,-0.10565636307001,-0.10622248798609001,-0.10749863088130999,-0.10951888561249,-0.11202036589384,-0.11561616510153,-0.12122401595116,-0.12754784524441001,-0.13345757126808,-0.13956134021281999,-0.14592926204205001,-0.15299762785435,-0.16160428524017001,-0.17053699493408001,-0.17844848334789001,-0.18672600388527,-0.19605351984500999,-0.20707628130913,-0.22176703810692,-0.2367201000452,-0.24838553369044999,-0.25944682955741999,-0.27140164375304998,-0.28411430120468001,-0.29893478751183,-0.31288146972656,-0.32240885496139998,-0.33069542050362,-0.33988937735558,-0.34944909811019997,-0.39111378788947998,-0.37019306421280002,-0.37979888916016002,-0.38301354646683,-0.38663932681084001,-0.38908249139786,-0.38992008566856001,-0.38825106620789002,-0.38389673829079002,-0.37598404288291998,-0.36567351222038003,-0.35338258743286,-0.34050267934799,-0.33001145720482,-0.31769418716431003,-0.29905483126639998,-0.27762171626090998,-0.25473833084106001,-0.23265245556830999,-0.2166985720396,-0.19931846857071001,-0.17222458124161,-0.14211732149124001,-0.112684071064,-0.085268959403037997,-0.065473817288875996,-0.044678758829832001,-0.013002637773751999,0.021470408886671,0.053540188819169998,0.083439648151397997,0.10692823678255001,0.13187685608864,0.16855539381504001,0.20712760090828,0.24003548920154999,0.26906806230545,0.29120662808418002,0.31315335631371,0.34398788213730003,0.37524858117103999,0.39993157982826,0.42101520299910999,0.43795546889304998,0.45457619428634999,0.47699165344237998,0.49904078245163003,0.51520538330078003,0.52814596891402998,0.53851199150085005,0.54722821712493996,0.55618137121200995,0.56355446577071999,0.56754434108733998,0.56946814060211004,0.57030797004699996,0.56961190700530995,0.56714904308319003,0.56314390897750999,0.55777454376221003,0.55101889371872004,0.54313778877258001,0.53349357843399003,0.52089363336562999,0.50694990158080999,0.49359780550003002,0.47932937741280002,0.46321251988411,0.44497972726821999,0.42301347851753002,0.40007913112639998,0.37971708178519997,0.35927644371986001,0.33685058355330999,0.31279903650284002,0.28563848137856002,0.25878486037254,0.23723521828651001,0.21662969887257,0.19314955174922999,0.16831022500991999,0.14141188561915999,0.11549277603626,0.095281846821307997,0.076890826225280998,0.056920014321803998,0.036856532096863001,0.016722558066249001,-0.0021145828068256001,-0.017259374260901999,-0.030791148543357998,-0.044572368264197998,-0.057899087667465002,-0.070899099111557007,-0.082792580127715995,-0.092358082532882996,-0.10048519074917001,-0.1079121530056,-0.11432285606860999,-0.11982969939709,-0.12381616234779,-0.12520188093185,-0.12499326467514001,-0.12408562004566,-0.12231475114822001,-0.11988719552755001,-0.11662022769451,-0.1123254224658,-0.10711300373077,-0.10096776485443,-0.094115577638148998,-0.086875721812247994,-0.079140163958072995,-0.070840060710906996,-0.062132254242896999,-0.053087268024682999,-0.043991561979055002,-0.035265877842902998,-0.026841275393962999,-0.018795469775795999,-0.011127581819892001,-0.0038298652507365001,0.0029934253543614999,0.0090838233008980994,0.014788461849093,0.020671311765909001,0.026145327836275,0.030634131282567999,0.034221336245536998,0.036715447902678999,0.038312748074531999,0.039211124181746999,0.039368800818919997,0.039044819772243,0.037594720721244999,0.033945232629776001,0.028963072225451001,0.023356037214397999,0.017182882875204,0.011253839358687,0.0043549025431275003,-0.0053410311229526997,-0.016434518620371999,-0.027708612382411998,-0.039321437478064998,-0.050404235720634002,-0.062557488679886003,-0.078512348234653001,-0.095845937728882002,-0.11207038909196999,-0.12792038917542001,-0.14291681349277,-0.15834130346774999,-0.17664007842540999,-0.19547408819199,-0.21220077574252999,-0.22787222266196999,-0.24238964915276001,-0.25704458355903997,-0.27461457252501997,-0.29240047931670998,-0.30712777376174999,-0.32045143842696999,-0.33300697803496998,-0.34573158621788003,-0.36138337850571001,-0.37685897946357999,-0.38808977603911998,-0.39716842770576,-0.40541243553161999,-0.41277673840522999,-0.42014810442924,-0.42645734548568998,-0.43016222119330999,-0.43224254250526001,-0.43354499340057001,-0.43387916684151001,-0.43332481384277,-0.43187925219536,-0.42970514297485002,-0.42645448446273998,-0.42170071601867998,-0.41539710760116999,-0.40660986304282998,-0.39713916182518,-0.39002868533134,-0.38326269388199002,-0.37486886978148998,-0.36554750800133001,-0.35516011714934997,-0.34461265802383001,-0.33589029312134,-0.32720354199409002,-0.31634876132010997,-0.30425003170967002,-0.29090592265129001,-0.27750328183174,-0.26675772666931002,-0.25630167126656,-0.24310483038424999,-0.22868496179580999,-0.21369117498397999,-0.19908607006073001,-0.18752372264861999,-0.17670381069183,-0.16360300779343001,-0.14981788396835,-0.13628493249415999,-0.12359993904829,-0.11409676074982,-0.10520835220814,-0.093029662966728002,-0.079877376556395999,-0.067677438259125006,-0.056458450853824997,-0.047999810427427,-0.040019743144512003,-0.028690185397862999,-0.016542676836252001,-0.0061870627105236001,0.0030417405068873999,0.010411985218525001,0.017570156604051999,0.027774473652243999,0.038642104715109003,0.047481223940848999,0.055025227367878002,0.060627210885285998,0.065912678837776004,0.074082657694817006,0.083003997802734,0.090195782482623998,0.096727237105369998,0.10289034247398,0.10959032177925,0.11923618614674,0.12984974682330999,0.13883706927299,0.14720173180102999,0.15529172122477999,0.16349239647388,0.17311170697212,0.18286806344986001,0.19076851010323001,0.19789698719977999,0.20505285263062001,0.21255126595497001,0.22198012471199,0.23161230981350001,0.23854602873325001,0.24449416995049,0.25107038021088002,0.25824931263924,0.26740840077400002,0.27684780955315003,0.2836622595787,0.28936061263084001,0.29533788561821001,0.30129736661911,0.30778178572655002,0.31374940276146002,0.31708520650864003,0.31913939118384999,0.32141014933585998,0.32362994551659002,0.32655596733093001,0.32886964082718001,0.32784599065781,0.32531365752219998,0.32354018092155001,0.32182398438454002,0.32043385505675998,0.31822922825812999,0.31244367361068998,0.30515459179878002,0.29923513531684998,0.29364007711411,0.28813537955284002,0.28196883201598999,0.27298045158385997,0.26284435391425998,0.25401005148888001,0.24546958506107,0.23661883175373,0.22724683582783001,0.21629106998444,0.20470324158669001,0.19409212470055001,0.18359939754009,0.17236819863319,0.16046307981013999,0.1471251398325,0.13349594175816001,0.12195572257042001,0.11105397343636,0.099018655717373005,0.086285799741744995,0.072412274777889002,0.058406274765730001,0.046432189643382998,0.035376556217669997,0.024009302258491998,0.012694900855421999,0.0014201691374183,-0.0095222331583499995,-0.019325260072946999,-0.028593484312296,-0.038273259997367998,-0.047962322831154001,-0.057499125599860999,-0.066501326858996998,-0.073815114796161999,-0.080221444368361997,-0.086834780871867995,-0.093301787972450007,-0.099563889205456002,-0.10540149360895,-0.11030399799347,-0.11439158022404,-0.11752390116453,-0.11999609321356,-0.12242955714464,-0.12458309531212,-0.12648768723011,-0.12765930593013999,-0.12670120596886,-0.12463667988777,-0.12293562293052999,-0.12138184905052,-0.1207437440753,-0.11990775167942,-0.11631935089827,-0.11153499782085,-0.10763364285231,-0.10424047708511,-0.10206054896116,-0.10006905347109001,-0.095892839133739,-0.090955302119254997,-0.087244167923927002,-0.084250681102276001,-0.081977657973765994,-0.080263666808605,-0.078808240592479997,-0.077551938593388006,-0.076084807515144001,-0.074706353247165999,-0.073709711432456998,-0.073396407067776004,-0.074952863156796001,-0.077475398778915003,-0.07931762188673,-0.081214547157288,-0.083529233932495006,-0.087126508355141005,-0.095177426934241999,-0.10512509942055,-0.11215178668499,-0.11831392347813,-0.12550859153270999,-0.13399353623390001,-0.14641426503658,-0.16022051870823001,-0.16993054747580999,-0.17837736010551,-0.18911710381508001,-0.20185954868792999,-0.21930290758609999,-0.23802141845225999,-0.24992986023426,-0.25923192501067999,-0.27160751819611001,-0.28599444031714999,-0.30451092123985002,-0.32361596822739003,-0.33431139588356001,-0.34136709570884999,-0.35172459483147001,-0.36353874206543002,-0.37712123990058999,-0.39042112231255,-0.39745271205902,-0.40153077244759,-0.40788105130196001,-0.41482496261597002,-0.42159131169318997,-0.42733398079871998,-0.42884457111358998,-0.42803663015366,-0.42814868688583002,-0.4281157553196,-0.42734000086784002,-0.42539167404174999,-0.42086774110794001,-0.41397234797478,-0.40401563048362998,-0.39190444350242998,-0.37960627675056002,-0.36670860648155001,-0.35381719470023998,-0.33976298570633001,-0.32115882635116999,-0.30000373721123003,-0.27951416373253002,-0.25922274589539002,-0.24085944890975999,-0.22193968296051,-0.19559621810913,-0.16566377878189001,-0.13839611411095001,-0.11253902316092999,-0.089441075921059002,-0.066775128245354004,-0.037771951407193999,-0.0063087455928326,0.020769855007528999,0.045400507748126998,0.067960366606711994,0.090078353881836007,0.1175370067358,0.14702984690665999,0.17254513502120999,0.19592624902725,0.21823874115944,0.24020010232924999,0.26546338200568997,0.29128482937812999,0.31170719861983998,0.32879003882407998,0.34444797039031999,0.35889893770218001,0.37435898184776001,0.38946828246116999,0.40140905976294999,0.41132515668869002,0.42073827981949002,0.42945683002472002,0.43832281231879999,0.44624680280684997,0.4501356780529,0.45147606730460998,0.45267549157143,0.45330840349196999,0.45412468910217002,0.45396521687508001,0.44939664006232999,0.44204604625701999,0.43454563617705999,0.42648708820343001,0.41851779818535001,0.41002997756004,0.39931052923202998,0.38730859756469999,0.37585061788558999,0.36451137065887002,0.35343369841576,0.34203249216080001,0.32824820280075001,0.31320813298224998,0.29917520284652999,0.28549247980117998,0.27172797918320002,0.25763720273972002,0.24193064868450001,0.22539009153843001,0.20970176160335999,0.19438242912292,0.17903560400009,0.16364157199859999,0.14768059551716001,0.13166782259941001,0.11697985231876,0.1031865850091,0.089762754738330994,0.076880760490893998,0.064763121306896002,0.053381353616713999,0.042845815420151,0.033017501235007997,0.023489724844693999,0.014401189982890999,0.0059568835422396998,-0.0019149081781507,-0.0093801775947212999,-0.016299689188599999,-0.022322278469801001,-0.027516968548298,-0.031826864928007001,-0.035365149378777001,-0.038522079586982998,-0.041118603199720001,-0.042761031538248,-0.043619289994240001,-0.043913427740335,-0.043769903481006997,-0.044096529483794999,-0.044111430644989,-0.041569575667381002,-0.037264153361320003,-0.032130751758813997,-0.026498226448894002,-0.022354025393724001,-0.018824543803930002,-0.014113688841462,-0.0087918508797884005,-0.0035018296912313002,0.0015928237698972,0.0053433510474860998,0.0082857143133879003,0.011576788499951,0.014885179698467,0.017797190696001001,0.020401250571012001,0.022964844480156999,0.025069013237952999,0.025159664452076,0.023948533460497998,0.022929094731808,0.021821230649947999,0.021231500431894999,0.019968170672655002,0.013419399037957001,0.0037432936951517998,-0.004292574711144,-0.011691978201269999,-0.018117018043995001,-0.025059808045625999,-0.038778699934482998,-0.056221947073935997,-0.070211112499237005,-0.082425370812415993,-0.093249984085559998,-0.10437578707933,-0.12374607473612,-0.14733090996741999,-0.16496302187442999,-0.17942751944065,-0.19353964924812,-0.20817352831364,-0.22975634038448001,-0.25480818748473999,-0.27403005957602999,-0.29003709554672003,-0.30615600943565002,-0.32241007685661,-0.34202581644058,-0.36273473501205,-0.37742367386817999,-0.38844785094260997,-0.39988797903061002,-0.41133567690848999,-0.42461743950844,-0.43821081519126998,-0.44695487618446,-0.45264872908592002,-0.45882150530815002,-0.46486723423004001,-0.47123757004737998,-0.47704339027405002,-0.47865563631058,-0.47747671604156,-0.47658342123031999,-0.47546172142028997,-0.47447606921196001,-0.47298958897590998,-0.46849772334098999,-0.46182802319527,-0.45461440086365001,-0.44655305147170998,-0.43755823373795,-0.42754542827606001,-0.41628366708754999,-0.40358358621597001,-0.38827428221702998,-0.37091085314750999,-0.35278221964835998,-0.33396625518799,-0.31602331995964,-0.29813924431800998,-0.27777954936027999,-0.25575274229049999,-0.23356759548187001,-0.21120266616343999,-0.18990765511989999,-0.16896757483482,-0.14602483808993999,-0.12181548774242,-0.097773991525173007,-0.073786780238151994,-0.050604172050953002,-0.02768437191844,-0.0030368883162737001,0.022700559347868,0.048139087855815998,0.073515608906745994,0.098768219351767994,0.12414202839136,0.15091063082218001,0.17846366763115001,0.20504899322987,0.23087301850319,0.25562027096748002,0.27935141324996998,0.30196473002433999,0.32363757491112,0.34507811069488997,0.36619195342063998,0.38717982172965998,0.40782856941223,0.42739689350128002,0.44589301943778997,0.46273657679558,0.47814598679543002,0.49279800057411,0.50643074512482,0.51816284656525002,0.52833712100982999,0.53797346353530995,0.54685765504837003,0.55476176738739003,0.56163495779036998,0.56716233491898005,0.57129156589508001,0.57337093353270996,0.57374393939972002,0.57366585731506003,0.57281213998795,0.57032108306884999,0.56661432981491,0.56322753429412997,0.55980104207992998,0.55574578046798995,0.55106663703918002,0.54562991857528997,0.53911393880844005,0.52936726808547996,0.51734924316405995,0.5062837600708,0.49563336372375,0.48554271459579001,0.47527432441710998,0.46061748266219998,0.44315785169601002,0.42799124121665999,0.41411599516869002,0.40050607919692999,0.38673427700995999,0.36931845545768999,0.34967982769012002,0.3328814804554,0.31772544980049,0.30206590890884,0.28565946221352001,0.26490348577499001,0.24149464070797,0.22198586165904999,0.20494170486926999,0.18785274028778001,0.17068754136562,0.15075910091399999,0.12955361604690999,0.11368981003761,0.10126025974751,0.087038159370422002,0.07151760160923,0.052628282457589999,0.031997524201869999,0.017687540501356,0.0074378773570060999,-0.0051379064098001003,-0.019206583499908,-0.035591054707766002,-0.053073197603225999,-0.064873479306697998,-0.072940334677696006,-0.083150461316108995,-0.094645828008651997,-0.10733905434608,-0.12060123682022,-0.13032715022564001,-0.13787926733493999,-0.14815244078636,-0.16022111475468001,-0.17277839779854001,-0.18545833230018999,-0.19463859498500999,-0.20161332190037001,-0.21143667399883001,-0.22307305037975,-0.23455192148685,-0.24566724896431,-0.25289583206177002,-0.25788402557373002,-0.26838079094887002,-0.28253093361854997,-0.29532861709594999,-0.30704915523529003,-0.31489264965057001,-0.32026094198227001,-0.33000275492668002,-0.34249112010001997,-0.3531548678875,-0.36230328679085,-0.36785554885864002,-0.37088388204575001,-0.37680280208588002,-0.38433972001076,-0.38966771960258001,-0.39323645830154003,-0.39471557736397,-0.39458477497101002,-0.39582127332687,-0.39770248532294999,-0.39785498380661,-0.39662891626357999,-0.39452040195464999,-0.39147278666495999,-0.38731262087821999,-0.38220360875129999,-0.37713038921356001,-0.37193867564201,-0.36656969785690002,-0.36080330610275002,-0.35277783870696999,-0.34316405653954002,-0.33514723181724998,-0.32817530632018999,-0.32115855813026001,-0.31400540471076999,-0.30495214462280001,-0.29464906454085998,-0.28635177016258001,-0.27942961454391002,-0.27221122384071,-0.26469331979751998,-0.25506135821342002,-0.24417914450169001,-0.23709949851036,-0.23270708322524999,-0.22716444730759,-0.22079072892665999,-0.21225807070732,-0.20252145826817,-0.19781814515591001,-0.19683825969696001,-0.19508312642573999,-0.19298675656319,-0.19005186855792999,-0.18664154410361999,-0.18518836796283999,-0.18508295714855,-0.18362192809582001,-0.18121407926083,-0.17858426272868999,-0.17592471837997001,-0.17550826072692999,-0.17673666775227001,-0.17684210836886999,-0.17619337141513999,-0.17527055740356001,-0.17423237860203,-0.17493523657321999,-0.17682538926600999,-0.17696392536163,-0.17579562962055001,-0.1743440926075,-0.17267224192618999,-0.17226672172546001,-0.17270269989966999,-0.17177519202232,-0.16975554823875,-0.16718873381614999,-0.16391636431216999,-0.15887112915516,-0.15229824185370999,-0.14537830650806,-0.13797406852245001,-0.1298840045929,-0.12112011015415,-0.11154776811600001,-0.10129787772894,-0.091625988483428997,-0.082143470644951005,-0.070493549108504999,-0.056970916688442001,-0.041959129273890998,-0.025673912838100998,-0.01056353840977,0.0039462242275475996,0.020981883630156999,0.040121186524630002,0.060348682105541,0.081538498401641998,0.10134142637253001,0.12046127766371,0.14359754323959001,0.16999253630638,0.19698522984982,0.22441583871841,0.24801209568977001,0.26888227462768999,0.29408925771713001,0.32257789373397999,0.35059869289397999,0.37810006737709001,0.40074998140335,0.41983997821808,0.44459760189056002,0.47361010313034002,0.50113451480865001,0.52736872434616,0.54905462265015004,0.56713050603866999,0.58842903375625999,0.61185693740845004,0.63221663236617998,0.64988738298416004,0.66413879394530995,0.67541366815567005,0.68766862154007002,0.70032227039337003,0.71070349216461004,0.71904832124710005,0.72570145130157004,0.73064094781875999,0.73372924327849998,0.73505401611328003,0.73548811674117998,0.73491936922072998,0.73311072587966997,0.72988939285277998,0.72279608249663996,0.71237236261367998,0.702592253685,0.69302320480347002,0.68266439437866,0.67118495702743997,0.65333521366118996,0.63021075725554998,0.61014032363892001,0.59212785959243996,0.57214814424515004,0.55012708902358998,0.52078622579574996,0.48556414246558999,0.45756486058235002,0.43509760499000999,0.40955296158790999,0.38124710321425997,0.34579014778137002,0.30452120304107999,0.27062323689460999,0.24234510958194999,0.20945881307125,0.17259466648102001,0.12934947013855,0.081381686031818001,0.049144461750983998,0.029727153480053,0.0034647416323423,-0.028193511068820998,-0.064169302582741006,-0.10346431285143,-0.13143421709538,-0.15013343095779,-0.17431415617466001,-0.20280133187770999,-0.23304808139801,-0.26448374986648998,-0.28655168414116,-0.30077078938483998,-0.31910863518714999,-0.34057140350342002,-0.36183539032936002,-0.38270777463913003,-0.39728909730911,-0.40647602081299,-0.41816118359566001,-0.43165031075478,-0.44384270906447998,-0.45468330383300998,-0.46042734384536999,-0.46165716648102001,-0.46385818719864003,-0.46659019589424,-0.46789804100990001,-0.46784317493438998,-0.46575129032134999,-0.46176266670227001,-0.45742738246918002,-0.45263880491257003,-0.44706812500954002,-0.44071736931800998,-0.43335595726967002,-0.42502754926682002,-0.41616094112396002,-0.40677809715271002,-0.39759024977683999,-0.38858178257942,-0.38048756122589,-0.37306955456733998,-0.36244791746139998,-0.34907388687134,-0.33758077025414002,-0.32765915989875999,-0.31801587343215998,-0.30856382846831998,-0.29620847105980003,-0.28141736984253002,-0.27025306224822998,-0.26229831576347001,-0.25522288680076999,-0.24902455508709001,-0.24153737723827001,-0.23303343355656,-0.22696998715401001,-0.22308057546616,-0.21916501224040999,-0.21527299284935,-0.21024070680140999,-0.20429350435734001,-0.20118319988250999,-0.20062611997127999,-0.20011726021767001,-0.19970005750656,-0.19781231880187999,-0.19471091032028001,-0.19485341012478,-0.19788964092731001,-0.19993926584721,-0.20116019248962,-0.20155790448189001,-0.20126269757748,-0.20341886579990001,-0.20777997374535001,-0.2113091647625,-0.21412731707096,-0.21650642156600999,-0.21846175193787001,-0.22054007649422,-0.22268608212471,-0.22394154965877999,-0.22435916960239,-0.22446592152118999,-0.22424407303332999,-0.22365894913673001,-0.22270800173283001,-0.22128598392009999,-0.21940818428993,-0.21739645302296001,-0.21524582803249001,-0.21315963566303001,-0.21111337840557001,-0.20865349471569,-0.20576865971087999,-0.20178274810314001,-0.19668182730674999,-0.18900047242640999,-0.17889623343944999,-0.17036031186580999,-0.16319945454597001,-0.15470014512538999,-0.14489808678627,-0.13212661445141,-0.11660540103912,-0.10504274070263001,-0.097110472619533997,-0.086918234825134,-0.074601724743842995,-0.059606689959764002,-0.042102016508578997,-0.028611019253730999,-0.018805969506501999,-0.0052288202568889003,0.011932153254747,0.032010536640881999,0.054855190217494999,0.072641626000403997,0.085738107562065,0.10403565317392,0.12727184593678001,0.15232652425766,0.17913173139095001,0.20092689990997001,0.21801917254924999,0.24051840603352001,0.26815354824066001,0.29571163654326998,0.32316961884499001,0.34349161386490001,0.35700249671936002,0.37741738557816001,0.40441381931304998,0.43011623620987,0.45457863807678001,0.47388657927513,0.48821204900741999,0.50653511285782005,0.52867192029953003,0.54873865842819003,0.56678050756454001,0.58083957433700995,0.59100234508514005,0.60333472490311002,0.61773753166198997,0.63009530305862005,0.64044582843780995,0.64920300245285001,0.65636563301086004,0.66186010837554998,0.66569244861603005,0.66865217685698997,0.67073309421538996,0.67193770408630005,0.67225474119186002,0.66928970813750999,0.66307330131530995,0.65795570611954002,0.65391188859939997,0.64918464422225997,0.64376902580260997,0.63344258069991999,0.61822998523712003,0.60609823465347001,0.59703063964844005,0.58679354190826005,0.57538950443268,0.55820387601851995,0.53522855043411,0.51739853620528997,0.50473648309707997,0.48976850509643999,0.47248995304107999,0.44893246889114002,0.41904258728027,0.39594516158103998,0.37972626090049999,0.36087989807129001,0.33938005566597002,0.31189188361168002,0.27831432223320002,0.25307410955428999,0.23634183406830001,0.21569460630417001,0.19104610383511,0.16238175332546001,0.1295922100544,0.10564484447241,0.090767532587051003,0.072513498365879003,0.050752002745866998,0.026954237371682999,0.0010450333356857001,-0.018919138237834001,-0.032732397317885999,-0.050215557217598003,-0.071526363492011996,-0.093422815203667006,-0.11592842638493001,-0.13435393571854001,-0.14852678775787001,-0.1659517288208,-0.18679669499397,-0.20719696581364,-0.22714214026928001,-0.24369426071643999,-0.25671684741973999,-0.27133247256278997,-0.28768250346183999,-0.30267035961151001,-0.31625923514366,-0.32759344577789001,-0.33660900592803999,-0.34557607769965998,-0.35455584526062001,-0.36273631453513999,-0.37011361122130998,-0.37620902061462003,-0.38100048899651001,-0.38490113615990001,-0.38790190219879001,-0.39079836010933,-0.39361947774887002,-0.39609017968178001,-0.39824464917183,-0.39839842915535001,-0.39648106694221003,-0.39353805780411,-0.38958793878554998,-0.38480740785598999,-0.37919351458549,-0.37306028604507002,-0.36639469861983998,-0.36009246110915999,-0.35421276092529003,-0.34769412875174999,-0.34053310751915,-0.33169284462929,-0.32107555866241,-0.31079396605491999,-0.30092626810074002,-0.29107859730720997,-0.28126603364943997,-0.27063721418380998,-0.25908935070037997,-0.24891667068005,-0.24021887779236001,-0.23235987126827001,-0.22534492611884999,-0.21857079863548001,-0.21201652288437001,-0.20558597147464999,-0.19926139712334001,-0.19337859749794001,-0.18795132637024001,-0.18285498023033001,-0.17803868651390001,-0.17485113441944,-0.17339816689491,-0.17232143878937001,-0.17156633734703,-0.17127868533134,-0.17148989439011,-0.1713879108429,-0.17090232670307001,-0.17091390490531999,-0.17146363854408,-0.17250275611877,-0.17408460378647,-0.17486831545830001,-0.17472115159035001,-0.17535951733589,-0.17689992487431,-0.17834538221359,-0.17962709069252,-0.18141712248325001,-0.18377166986464999,-0.18611961603165,-0.18845532834529999,-0.19036270678042999,-0.19182766973972001,-0.19256742298603,-0.19250386953354001,-0.19300606846808999,-0.19421347975730999,-0.19475975632667999,-0.19461980462073999,-0.19273369014263,-0.18885585665703,-0.18684428930283001,-0.18710745871067,-0.18568362295627999,-0.18234924972057001,-0.17736169695854001,-0.17059496045113001,-0.16450409591198001,-0.15936876833439001,-0.15258912742138001,-0.14399726688862,-0.13390818238258001,-0.12214809656143,-0.11225325614214,-0.10469766706227999,-0.094770416617392994,-0.082110449671744995,-0.068042628467083005,-0.052372828125954,-0.039918106049298997,-0.031419195234776001,-0.019320966675878001,-0.0029545016586780999,0.014299071393907001,0.032436124980450003,0.048153091222048,0.060805052518845,0.077403880655766005,0.098706424236297996,0.11984898895024999,0.14066058397292999,0.15882301330566001,0.17370679974556,0.19265256822109,0.21655195951462,0.23929449915886,0.26053857803344999,0.27918282151222001,0.2946765422821,0.31397351622580999,0.33795973658562001,0.36080411076545998,0.38214147090911998,0.40147042274474998,0.41845870018004999,0.43714651465415999,0.45814901590347001,0.47685059905052002,0.49289250373839999,0.50661516189574995,0.51786738634108997,0.52879905700684005,0.53969025611876997,0.54894572496413996,0.55640327930449995,0.56278860569,0.56815618276596003,0.57243937253952004,0.57567703723907004,0.57731044292449996,0.57726812362670998,0.57595062255858998,0.57346856594086004,0.56855487823485995,0.56087958812714001,0.55354803800582997,0.54697877168654996,0.53908973932266002,0.52977448701858998,0.51835137605667003,0.50467360019684004,0.48963311314583002,0.47328934073447998,0.45583206415175997,0.43733322620392001,0.41702815890312001,0.39460816979407998,0.37329134345054998,0.35365232825279003,0.33216476440429998,0.30852228403090998,0.28264439105987998,0.25423282384871998,0.22652043402194999,0.19994533061981001,0.17284922301769001,0.14502653479576,0.11720535159110999,0.089115262031554995,0.064907997846603005,0.045417755842209001,0.025758018717170001,0.0055225286632776,-0.015567881986498999,-0.037374615669250003,-0.062529668211937006,-0.091539695858954995,-0.12187572568655,-0.15347900986671001,-0.18459354341029999,-0.21531447768211001,-0.24208092689513999,-0.26424837112427002,-0.28432571887969998,-0.30210351943969999,-0.32218271493911999,-0.34478831291199002,-0.37355870008469,-0.40969124436378002,-0.44532865285873002,-0.48013117909431002,-0.50919020175934004,-0.53211766481400002,-0.54608845710753995,-0.55034756660461004,-0.54848319292068004,-0.54024469852447998,-0.53208315372466997,-0.52480900287627996,-0.51815605163573997,-0.51242780685425005,-0.50492203235625999,-0.49504011869431003,-0.48580536246299999,-0.47753658890723999,-0.47026345133781,-0.46411705017089999,-0.45804360508919001,-0.45166611671447998,-0.44764950871468001,-0.44645717740058999,-0.44659578800201,-0.44810286164284002,-0.44933614134789002,-0.45042607188224998,-0.44780850410460998,-0.44073510169982999,-0.43193057179451,-0.42157080769539002,-0.41090884804726002,-0.40057021379470997,-0.38612481951714001,-0.36653238534927002,-0.34653392434120001,-0.32650232315062999,-0.30878424644469998,-0.29539409279822998,-0.26993891596794001,-0.22851242125033999,-0.18814001977444,-0.15058326721191001,-0.1179296001792,-0.090888842940331005,-0.067649602890014995,-0.048075072467327,-0.031805511564016002,-0.018838554620742999,-0.0089313322678208004,-0.0029151439666747999,0.0075163771398365003,0.02442585490644,0.039381306618452003,0.051166947931050998,0.061322566121817003,0.069408871233462996,0.080487214028835005,0.096161492168903004,0.10852479934692,0.11639078706503,0.1212507262826,0.12335040420293999,0.12104973942041,0.11351630836725,0.10601264983416001,0.099223360419273002,0.093444839119911,0.088568031787871995,0.086878925561905004,0.089272007346152996,0.091136701405047996,0.091889649629593007,0.091147549450397006,0.088928557932377,0.083673685789107999,0.074433296918869005,0.067078478634356994,0.062522441148758004,0.060242250561713999,0.060197092592716002,0.063181646168232006,0.069948256015778004,0.075365290045737998,0.078719444572925998,0.079484827816485998,0.077418655157088997,0.072829112410545002,0.065163232386112005,0.059271831065416003,0.056447397917509003,0.052425969392060998,0.046489052474498999,0.039606753736734002,0.031423315405846003,0.025559762492776,0.023071404546498999,0.020284917205572,0.016602307558060001,0.012552986852825,0.0078819468617438992,0.0048733260482549997,0.0043425280600786001,0.0027849746402353001,-0.00067048263736068996,-0.0034551292192190998,-0.0053855171427131003,-0.0051180087029933999,-0.0023997409734874998,0.0030115935951470999,0.011486072093248,0.020793339237570999,0.030560759827494999,0.040732670575379999,0.050997398793697003,0.063357241451740001,0.078469544649124007,0.093966580927372007,0.10955087840557,0.12449929118156,0.13793869316578,0.15530644357203999,0.17846049368382,0.20056784152984999,0.22042256593703999,0.23875886201859001,0.2550950050354,0.27307513356209001,0.29418534040451,0.31231120228767001,0.32617247104644997,0.33759444952010997,0.34654808044433999,0.35468226671219,0.36246648430824002,0.36886987090111001,0.37365472316741999,0.37742936611175998,0.38011640310286998,0.38299721479415999,0.38660001754760998,0.38892659544945002,0.38942608237267001,0.38956061005592002,0.38954177498817,0.38950106501579002,0.38950103521347001,0.38948220014571999,0.38936784863472002,0.38968321681022999,0.39061123132705999,0.39168071746826,0.39318132400513001,0.39252364635468001,0.38888475298882003,0.38433402776718001,0.3791531920433,0.37390884757041998,0.36958941817284002,0.36037167906760997,0.3441855609417,0.32733741402625999,0.31112462282181003,0.29448264837264998,0.27828657627106002,0.25607973337173001,0.22553750872612,0.19334198534489,0.16075819730759,0.12714125216007,0.092213347554207001,0.058068968355656003,0.025337643921375001,-0.0072412095032632004,-0.039904769510031003,-0.072411835193634005,-0.10474916547537,-0.13685961067676999,-0.16872364282607999,-0.20037128031254001,-0.23181538283825001,-0.26298862695693997,-0.29382586479187001,-0.3247292637825,-0.35612189769745001,-0.38584375381469999,-0.41343116760254001,-0.43896612524986001,-0.46248388290405001,-0.48344665765762002,-0.50167328119277999,-0.51744246482848999,-0.53042161464690996,-0.54295724630356001,-0.55555260181427002,-0.56837666034697998,-0.58172971010207997,-0.59446817636490001,-0.60640102624893,-0.61723387241364003,-0.62686181068419999,-0.63526427745819003,-0.64220660924910999,-0.64904582500457997,-0.65628588199615001,-0.66270196437836004,-0.66799402236937999,-0.67254614830017001,-0.67633765935898005,-0.67997449636458995,-0.68442255258560003,-0.68462747335434004,-0.67879492044448997,-0.67068177461624001,-0.66048616170883001,-0.65159463882446,-0.64679753780365001,-0.63454902172089001,-0.61065250635146995,-0.58449774980545,-0.55725687742232999,-0.53334009647368996,-0.51661825180054,-0.49172416329384,-0.45278209447861001,-0.41369962692260998,-0.37690091133117998,-0.34534272551536999,-0.32348841428757003,-0.29142656922339999,-0.24081405997276001,-0.19283372163772999,-0.15204471349716001,-0.11845968663692,-0.095274478197098,-0.067677564918995001,-0.029620569199324001,0.0046205399557948,0.031459026038647003,0.053904250264168001,0.070691555738449,0.090939365327357996,0.11872071027756,0.14415019750595001,0.16438508033752,0.18317803740501001,0.19998103380203,0.22173166275024001,0.25249820947647,0.27987337112427002,0.30008110404014998,0.31788796186446999,0.33354964852333002,0.35009315609932001,0.36918604373932001,0.38654321432114003,0.40051871538161998,0.41472077369690002,0.42945876717567,0.44767662882804998,0.47203955054282998,0.49275553226470997,0.50634628534317005,0.51834750175475997,0.52984982728957997,0.54093241691589,0.55240452289580999,0.56088256835938,0.56508827209473,0.56715905666350996,0.56759673357009999,0.56603443622589,0.56223446130752996,0.55738359689713002,0.55228406190872004,0.54431998729705999,0.53250604867935003,0.51840037107467996,0.50147664546966997,0.4864210486412,0.47583207488059998,0.46306407451629999,0.44574001431464999,0.42761334776878002,0.40857535600661998,0.39354649186134,0.38552063703536998,0.37672254443169001,0.36455982923508001,0.35226428508759,0.34009951353072998,0.32992994785308999,0.32323050498962003,0.31559121608733998,0.30535462498665,0.29501730203629001,0.28495603799820002,0.27603027224540999,0.26908594369888,0.26149576902389998,0.25230848789214999,0.24272902309895,0.23296770453453,0.22319987416267001,0.21389356255531,0.20307682454586001,0.18969555199145999,0.1761981099844,0.16329476237297,0.15063551068306,0.13837671279906999,0.12571772933006001,0.11218354105948999,0.098948039114475,0.086361050605773995,0.074241675436496998,0.062480077147483999,0.051620278507471001,0.041844714432955003,0.033071897923945999,0.025258142501116,0.018627395853400001,0.013153589330614,0.0093722436577081993,0.0080081289634108994,0.0063442760147154002,0.0032973831985145998,0.00012609845725819,-0.0031879746820778002,-0.0052145919762552001,-0.0045441607944667001,-0.0057098167017101999,-0.01081611122936,-0.016225729137659,-0.021074699237943001,-0.024958934634924001,-0.026569407433270999,-0.030907178297639001,-0.040355786681175003,-0.050973676145077002,-0.061881422996521003,-0.072402335703372997,-0.081309139728546004,-0.092671588063239996,-0.10872484743595,-0.12479756772518,-0.13932767510413999,-0.15346316993237,-0.16696357727051001,-0.18172881007194999,-0.19911436736584001,-0.21579270064830999,-0.23054085671902,-0.24443367123604001,-0.25756776332855003,-0.27037328481674,-0.28333190083504001,-0.29499110579491,-0.30460074543952997,-0.31349372863769998,-0.32175546884536999,-0.33074736595153997,-0.34134498238563998,-0.35192912817000999,-0.36175054311751997,-0.37215346097946,-0.38350436091423001,-0.39590409398079002,-0.40988159179688,-0.42345702648162997,-0.43570300936699002,-0.44778701663017001,-0.45985442399978999,-0.47257021069527,-0.48648482561111001,-0.50039869546890003,-0.51402115821838001,-0.52697902917862005,-0.53898984193802002,-0.55043220520019998,-0.56152731180190996,-0.57171797752380005,-0.58086699247359996,-0.58876258134841997,-0.59516334533690995,-0.60063803195953003,-0.60509061813354004,-0.60986614227295,-0.61650961637497004,-0.62040382623671997,-0.61948662996292003,-0.61581218242644997,-0.60896825790404996,-0.60290658473969005,-0.60033643245696999,-0.59602302312850997,-0.58768701553345004,-0.57810622453689997,-0.56756073236464999,-0.55811518430710005,-0.55228656530380005,-0.54288512468338002,-0.52606594562530995,-0.50757151842116999,-0.48823165893554998,-0.47195604443549999,-0.46297472715378002,-0.45054557919501997,-0.42907488346099998,-0.40662354230880998,-0.38520696759223999,-0.36651495099067999,-0.35446059703826999,-0.33666706085205,-0.30573147535324002,-0.27396062016486999,-0.24531109631062001,-0.21963149309158,-0.20015220344067,-0.17578877508640001,-0.13952463865279999,-0.10348217189312001,-0.071936532855033999,-0.043610271066427002,-0.021269181743264001,0.0059456364251672996,0.045439045876265002,0.083719685673714003,0.11533933877945,0.14407457411289001,0.16870200634002999,0.19718325138091999,0.23579053580761,0.27197340130806003,0.30011042952537997,0.32529228925705,0.34806036949157998,0.37119153141974998,0.39731326699257002,0.42107903957366999,0.43946355581284002,0.45709252357482999,0.47492203116416998,0.49540597200393999,0.52186352014542003,0.54589283466339,0.56296747922896995,0.57852756977080999,0.59425491094589,0.60989803075789994,0.62630546092987005,0.6408497095108,0.65167248249053999,0.66207498311996005,0.67331737279892001,0.68509757518768,0.69827491044998002,0.70976650714874001,0.71785396337509,0.72428679466248003,0.72948467731475997,0.73371213674544999,0.73733770847321001,0.73971879482268998,0.74038553237914995,0.74030637741089,0.73997831344604004,0.73892122507095004,0.73759168386458995,0.73358702659607,0.72536009550095004,0.71479058265686002,0.70228457450866999,0.68862497806548995,0.67434144020080999,0.65920174121857,0.64320397377014005,0.62633818387984996,0.60851866006850996,0.59006679058074996,0.57109522819518999,0.55172950029373002,0.53218805789947998,0.51193982362747004,0.49060609936714,0.46881699562072998,0.44691187143326,0.42450454831123002,0.40179523825645003,0.37746462225914001,0.35005024075508001,0.32284080982208002,0.29738312959670998,0.27301269769669001,0.24998304247856001,0.22725410759449,0.20414790511131001,0.18143041431904,0.15952523052692,0.13774481415748999,0.11544462293386,0.094116307795047996,0.074886567890644004,0.055864796042442003,0.036134917289018999,0.016338685527444,-0.0033503901213407998,-0.023055359721183999,-0.042519599199295002,-0.062852911651134005,-0.084880620241164995,-0.10749024152756,-0.13028854131699,-0.15316799283027999,-0.17532220482826,-0.19932310283183999,-0.22724287211895,-0.25581115484237998,-0.28426444530486999,-0.31043004989624001,-0.33150658011436002,-0.35304006934165999,-0.37858796119690002,-0.40381759405135997,-0.42744117975235002,-0.44827130436897,-0.46419838070869002,-0.47965693473816001,-0.49757513403893,-0.51439827680588002,-0.52857416868210005,-0.54097753763198997,-0.55206161737442005,-0.56061446666717996,-0.56526231765747004,-0.56899333000183006,-0.57328379154205,-0.57776540517806996,-0.58249974250793002,-0.58774715662002996,-0.59398490190506004,-0.60002952814101995,-0.60510021448134999,-0.60997605323792004,-0.61459392309188998,-0.62020349502562999,-0.62803483009338001,-0.63615554571152,-0.64376920461654996,-0.65072345733643,-0.65686994791030995,-0.66172713041305997,-0.66441196203232,-0.66702157258987005,-0.67100679874419999,-0.67482358217239002,-0.67820775508881004,-0.68001097440720004,-0.67894619703293002,-0.67701256275177002,-0.67565518617630005,-0.67284345626830999,-0.66774767637252996,-0.66017442941666005,-0.64872950315474998,-0.63737970590590998,-0.62948966026305997,-0.62034308910369995,-0.60770034790038996,-0.59216374158858998,-0.57176089286803999,-0.55306679010391002,-0.54177516698837003,-0.53015667200089001,-0.51434302330017001,-0.49604156613349998,-0.47413176298141002,-0.45312359929085,-0.43756422400474998,-0.42018893361092002,-0.39655396342277999,-0.37027487158775002,-0.34117484092712003,-0.31416040658951,-0.29453065991402,-0.27421301603317,-0.24812720716,-0.22080871462821999,-0.19330079853535001,-0.16773390769957999,-0.14791762828826999,-0.12603330612183,-0.096208587288857006,-0.064834907650948001,-0.034124694764614001,-0.0056854393333197004,0.016535043716431001,0.040896687656641,0.073919847607612998,0.10827955603599999,0.14083112776279,0.17155557870864999,0.19826345145702001,0.22585532069205999,0.25876635313034002,0.29081687331200001,0.31878542900085,0.34356278181076,0.36381259560585,0.38342919945717002,0.40554872155190003,0.42709907889366,0.44660684466362,0.46481367945670998,0.48130875825882002,0.49795502424240001,0.51683253049849998,0.53472226858139005,0.54951912164687999,0.56280225515366,0.57512360811233998,0.58642441034317005,0.59711140394211004,0.60613232851027998,0.61256372928618996,0.61745834350586004,0.62136876583098999,0.62406682968140004,0.62538182735443004,0.62584871053696001,0.62582272291183005,0.62520986795425004,0.6241455078125,0.62225610017776001,0.61894690990447998,0.61547273397446001,0.61282408237456998,0.61010783910750999,0.60690367221831998,0.60338360071181996,0.59987175464630005,0.59530651569366,0.58870655298232999,0.58111691474914995,0.57292073965072998,0.56447732448578003,0.55674082040786999,0.54770714044571001,0.53542006015777999,0.52244263887404996,0.51033818721770996,0.49835500121116999,0.48740243911742998,0.47399505972861999,0.45416533946991,0.43346515297889998,0.41553562879562,0.39827731251717002,0.38145321607589999,0.36396747827530002,0.34393772482871998,0.32470968365669001,0.30909469723701,0.29433646798134,0.27944570779799999,0.26340660452843001,0.24417218565941001,0.22509230673312999,0.20869854092598,0.19312503933906999,0.17781658470631001,0.16223807632923001,0.14518882334232,0.12877741456031999,0.11509069055319,0.10147745162249,0.086291052401066007,0.070153802633285994,0.052527047693728998,0.035245358943939001,0.020462134853005,0.0052924291230737998,-0.012331182137132,-0.031019724905491,-0.050708785653114,-0.069964699447154999,-0.086845137178897996,-0.10394658893347,-0.12304935604334,-0.14323838055134,-0.16497543454169999,-0.18604935705662001,-0.20342743396759,-0.22165787220000999,-0.24441304802895,-0.26877224445343001,-0.29385930299759,-0.31833407282829002,-0.34012150764464999,-0.36161485314369002,-0.38464969396590998,-0.40763202309607999,-0.43010562658309998,-0.45107838511467002,-0.46909683942795,-0.48579755425452997,-0.50220197439194003,-0.51798415184020996,-0.53335034847259999,-0.54773497581482,-0.56026375293732,-0.57242482900619995,-0.58548110723494995,-0.59853309392928999,-0.61125338077544999,-0.62347847223282005,-0.63500714302062999,-0.64573591947555997,-0.65544015169143999,-0.66436684131622004,-0.67274165153502996,-0.68030291795731002,-0.68786489963530995,-0.69236475229262995,-0.68967360258101995,-0.68533456325530995,-0.68344467878341997,-0.68216711282730003,-0.68218493461608998,-0.68025344610214,-0.67231363058089999,-0.66294419765472001,-0.65554243326187001,-0.64807766675948997,-0.64088982343673995,-0.63059753179550004,-0.61183071136474998,-0.59243112802505005,-0.57923555374145996,-0.56733417510985995,-0.55534255504607999,-0.54057615995407005,-0.51766300201416005,-0.49457183480263001,-0.47924137115478999,-0.46395221352576999,-0.44435581564902998,-0.42010101675986999,-0.38633298873901001,-0.35292634367942999,-0.33054447174071999,-0.30914935469626997,-0.28273326158523998,-0.25197926163673001,-0.21231211721897,-0.17395474016665999,-0.14856733381748,-0.12466636300087,-0.094393730163573997,-0.060711931437254001,-0.021551791578531002,0.015955433249473999,0.042469169944525001,0.068330973386764998,0.1016438305378,0.13803723454475,0.17803007364272999,0.21542643010616,0.24146498739719,0.26559385657309997,0.29544538259505998,0.32640680670737998,0.35704869031906,0.3858725130558,0.40944090485572998,0.43245157599449002,0.45936265587807001,0.48692387342452997,0.51375979185104004,0.53895246982573997,0.56049609184265003,0.58041787147521995,0.60043066740036,0.61932462453841997,0.63643646240233998,0.65190261602402,0.66502332687377996,0.67765086889267001,0.69224095344543002,0.70619553327560003,0.71780878305435003,0.72693246603011996,0.80228960514069003,0.73556715250015003,0.73229026794434005,0.72996860742569003,0.72641497850418002,0.72232973575591997,0.71656256914139005,0.70764988660812,0.69720637798309004,0.68659371137618996,0.67515224218368997,0.66290700435637995,0.64915633201598999,0.63284772634506004,0.61500644683838002,0.59650415182114003,0.57680994272232,0.5561329126358,0.53311061859131004,0.50516772270203003,0.47597169876098999,0.44913944602013001,0.42263036966324002,0.39595884084701999,0.36794272065162997,0.33649232983589,0.30362331867218001,0.27049422264098999,0.23781591653824,0.20664629340172,0.17727097868919001,0.15142999589442999,0.12598237395287001,0.097182378172874007,0.067968681454658994,0.040224146097897998,0.013817805796862001,-0.0097187981009483008,-0.033345822244883,-0.060984253883361997,-0.088953390717506006,-0.11431839317082999,-0.13801842927933,-0.15869796276093001,-0.18026572465897001,-0.20875525474548001,-0.23767051100730999,-0.26097685098647999,-0.28167963027954002,-0.30074000358581998,-0.3187490105629,-0.33742737770080999,-0.35468825697898998,-0.36827522516250999,-0.37977287173271002,-0.38985478878021002,-0.39935502409934998,-0.41050544381142001,-0.4202755689621,-0.42514923214911998,-0.42772167921066001,-0.42995709180831998,-0.43100133538245999,-0.43030598759651001,-0.42870873212813998,-0.42682912945746998,-0.42507010698317998,-0.42411121726036,-0.42398807406424999,-0.42537638545036,-0.42717570066451999,-0.42837598919867997,-0.42892393469809997,-0.42843264341353998,-0.42675969004630998,-0.42287632822990001,-0.41883173584937999,-0.41782623529433999,-0.41651996970177002,-0.41140717267990001,-0.40463241934776001,-0.39691334962844999,-0.38971444964409002,-0.38613188266754001,-0.38309857249259999,-0.37755212187767001,-0.37106764316558999,-0.36355310678482,-0.35735940933228,-0.35730347037315002,-0.35769912600517001,-0.35218992829322998,-0.34440496563910999,-0.33575880527495999,-0.32790794968605003,-0.32481789588928001,-0.32255202531815003,-0.31687819957732999,-0.31035867333411998,-0.30430495738982999,-0.29935759305954002,-0.29823634028434998,-0.29695743322371998,-0.29019773006438998,-0.28190553188324002,-0.27498072385788003,-0.26936683058739003,-0.2673367857933,-0.26548710465431002,-0.25907284021378002,-0.25181493163108998,-0.24692460894585,-0.24343985319138001,-0.24223658442497001,-0.2409648001194,-0.23588682711124001,-0.22999310493469,-0.22609835863113001,-0.22297091782093001,-0.22050367295741999,-0.21766440570354001,-0.21247823536395999,-0.20659312605857999,-0.20154139399529,-0.19685040414332999,-0.19300870597363001,-0.18864464759826999,-0.18145325779915,-0.1733605414629,-0.16636385023594,-0.15942047536373,-0.15177956223488001,-0.14390604197979001,-0.13650374114513,-0.12851551175116999,-0.11849182099104,-0.10730850696564,-0.095871120691298994,-0.083316572010516995,-0.068358495831489993,-0.052330985665321003,-0.036737266927958,-0.020980203524232001,-0.0049373982474208,0.011603066697716999,0.029443111270666001,0.047322049736976998,0.063160382211207997,0.078800171613693001,0.096149310469627006,0.11460177600384,0.13466511666775,0.15481805801392001,0.17225402593613001,0.18941536545752999,0.20901808142662001,0.22979798913002,0.25091111660004001,0.27288475632668002,0.29561313986777998,0.32044208049773998,0.35010093450545998,0.38224920630455,0.41567903757094998,0.44778162240982,0.47265121340751998,0.49479079246521002,0.51899492740631004,0.54305118322372004,0.56589412689208995,0.58724135160446,0.60530525445937999,0.62258225679398005,0.64286899566650002,0.66368508338928001,0.68319076299667003,0.70094221830367998,0.71427595615386996,0.72647351026535001,0.74231350421905995,0.75890064239501998,0.77374315261840998,0.78751564025878995,0.79972100257874001,0.81151396036148005,0.82566201686858998,0.83882898092269997,0.84691774845123002,0.85071134567260998,0.84839946031570002,0.8431950211525,0.84062099456786998,0.83682864904403997,0.82769298553466997,0.8150081038475,0.79912477731705001,0.78160512447357,0.76612365245819003,0.74969732761383001,0.72849100828170998,0.70475292205811002,0.67975252866744995,0.65485841035842995,0.63496589660644998,0.61428517103195002,0.58396905660628995,0.54920744895935003,0.51400142908096003,0.47890686988830999,0.44874548912048001,0.41782176494598,0.37700724601746,0.33224523067473999,0.28889641165732999,0.24696443974971999,0.21074676513672,0.17528066039085,0.1325301527977,0.087753951549530002,0.046228632330893998,0.0068520531058311003,-0.028502348810434001,-0.063174277544021995,-0.10340181738138,-0.14485323429107999,-0.18261930346489,-0.21843209862709001,-0.25171130895615001,-0.28553929924964999,-0.32688945531844998,-0.37016275525093001,-0.40816432237625,-0.44379785656928999,-0.47797918319701999,-0.51231497526169001,-0.55171000957489003,-0.59149742126464999,-0.62505155801773005,-0.65512222051619995,-0.68299168348312,-0.70942860841750999,-0.73718905448913996,-0.76401573419571001,-0.78704077005385997,-0.80708509683608998,-0.82463192939758001,-0.83866673707962003,-0.84646981954574996,-0.85106641054152998,-0.85754954814911,-0.86297869682312001,-0.86473751068115001,-0.86261397600173995,-0.85294109582901001,-0.84096860885619995,-0.83594191074371005,-0.83322387933731001,-0.82873642444610995,-0.82324361801146995,-0.81527996063232,-0.80714613199233998,-0.80384087562561002,-0.80124700069427002,-0.79361474514008001,-0.78299808502196999,-0.76982498168945002,-0.75538426637650002,-0.74394208192824995,-0.73107439279555997,-0.70954704284668002,-0.68267452716827004,-0.65151536464690996,-0.61970984935759998,-0.59731972217560003,-0.57692474126815996,-0.54784667491912997,-0.51507049798964999,-0.48191171884536999,-0.45007991790771001,-0.42675790190696999,-0.40579873323441001,-0.37741860747337003,-0.34639322757720997,-0.31641772389411998,-0.28856152296066001,-0.26886594295501998,-0.25168251991272,-0.22743561863899001,-0.20098043978214,-0.17708756029605999,-0.15502110123634,-0.13715736567973999,-0.11989776790142,-0.095815211534499997,-0.069303408265113997,-0.045394401997327999,-0.023322261869907001,-0.0053484076634048999,0.011650057509542001,0.034108139574527997,0.058184903115033999,0.079134330153464993,0.098199114203452995,0.11480257660151,0.130554869771,0.14921554923058,0.16851526498795,0.18543361127377,0.2010643184185,0.2156081199646,0.23016527295113001,0.24757219851017001,0.26641723513603,0.28491294384003002,0.30404180288315003,0.32456046342849998,0.34721300005912997,0.37558078765869002,0.40556442737579002,0.42939832806587003,0.45031827688217002,0.47102841734885997,0.49134144186973999,0.51321500539779996,0.53425025939940995,0.54945528507232999,0.56149381399154996,0.57353639602661,0.58498179912567005,0.59616261720657004,0.60710233449936002,0.61827480792999001,0.62912213802338002,0.63848567008972001,0.64695125818252996,0.65476703643798995,0.66281479597091997,0.67373901605606001,0.68593400716782005,0.69714695215224998,0.70795190334320002,0.71916896104813,0.72906500101089,0.73348265886306996,0.73452049493789995,0.73478001356125,0.73360300064087003,0.73138934373856002,0.72701388597488004,0.71738374233246005,0.70459026098250999,0.69164717197418002,0.67828238010405995,0.66556274890900002,0.65322327613830999,0.64126348495482999,0.62968307733536,0.61872005462645996,0.60784840583801003,0.59605121612548995,0.58330816030501997,0.56826502084732,0.55269372463225996,0.54131543636321999,0.53067421913146995,0.51533848047256003,0.49583879113196999,0.46873471140862,0.43810087442397999,0.41314214468001997,0.38949039578437999,0.36158168315887002,0.33069887757300997,0.29519549012183999,0.25882682204246998,0.2317019701004,0.20821286737919001,0.17967274785042001,0.1488828510046,0.11672990769148001,0.085423685610293995,0.062809199094772006,0.043635375797749003,0.018470412120223,-0.0093767680227757003,-0.037543978542088997,-0.065271481871605003,-0.088253505527972995,-0.10946889221668001,-0.13454203307629001,-0.16132229566574,-0.18798944354057001,-0.21398162841797,-0.23577201366424999,-0.25614249706268,-0.28091108798981002,-0.30760446190834001,-0.33352032303809998,-0.35846978425979997,-0.37980622053146001,-0.39923566579818998,-0.42000085115433,-0.44081035256385998,-0.46052703261375,-0.47860786318778997,-0.49215689301491,-0.50331205129623002,-0.51646524667740001,-0.52997189760207997,-0.54199391603470004,-0.5529118180275,-0.56275188922882002,-0.57139623165131004,-0.57844597101212003,-0.58412539958954002,-0.58860975503921997,-0.59225004911422996,-0.59632939100266003,-0.60017973184586004,-0.60245561599731001,-0.60396277904509998,-0.60628885030746005,-0.60882717370987005,-0.61129963397980003,-0.61286711692810003,-0.61037862300873003,-0.60568892955779996,-0.60233682394027999,-0.59917116165161,-0.59553205966948997,-0.59065282344818004,-0.58086812496185003,-0.56902635097503995,-0.56189322471618997,-0.55647629499435003,-0.54865485429764005,-0.53855723142624001,-0.52231043577194003,-0.50403600931168002,-0.49479073286057002,-0.48952606320380998,-0.48055112361907998,-0.46892628073692,-0.45162248611450001,-0.43202954530715998,-0.41964942216873002,-0.40984562039375,-0.39469254016875999,-0.37588071823120001,-0.35221332311629999,-0.32651790976523998,-0.30785611271857999,-0.29177129268646002,-0.27021217346191001,-0.24533000588417,-0.21757093071938,-0.18889857828616999,-0.16681545972824,-0.14736622571944999,-0.12276885658503001,-0.095349758863449,-0.066512927412987005,-0.037658847868443,-0.015529572963715,0.0041689202189445001,0.031382769346237002,0.062488868832588002,0.093108110129832999,0.12286078929901,0.14656695723534,0.16763956844806999,0.19429120421410001,0.22342626750469,0.25084069371223,0.27660953998566001,0.29771748185157998,0.31594514846802002,0.33528560400009,0.35443961620330999,0.37173533439635997,0.38754114508629001,0.40214669704437001,0.41527387499808999,0.42587095499039002,0.43469876050949002,0.44345813989638999,0.45201435685157998,0.46157100796700001,0.47091013193129999,0.47631269693375,0.47939118742942999,0.48309260606766002,0.48684310913085999,0.49079778790473999,0.4945801794529,0.49730545282364003,0.49873155355453003,0.49719765782356001,0.49348774552344998,0.48935595154762002,0.48410984873772001,0.47614294290543002,0.46642118692397999,0.45735126733780002,0.44824573397635997,0.43854767084121998,0.42794275283812999,0.41446095705031999,0.39942944049835,0.38634580373763999,0.37421041727066001,0.36193370819092002,0.34953173995018,0.33605092763901001,0.32225584983826,0.31036204099655001,0.29966878890991,0.28917020559311002,0.27902603149414001,0.26961395144463002,0.26010257005692,0.24716632068156999,0.23240499198437001,0.21936252713203,0.20737984776497001,0.19691823422908999,0.18701256811618999,0.17393922805786,0.15935470163821999,0.14693284034729001,0.13581375777721,0.12561787664890001,0.11580163240433,0.10361538082361001,0.090467751026153995,0.080025158822535997,0.071129485964775002,0.062081802636384999,0.052873484790324998,0.042007632553577,0.030369298532605001,0.020424874499439999,0.011449694633483999,0.0024937600828707001,-0.0065149879083037003,-0.0169891230762,-0.027801491320133001,-0.034978676587343001,-0.040255919098854002,-0.047416720539330999,-0.056149829179049003,-0.068797007203102001,-0.083281606435776007,-0.092327140271663999,-0.098595574498177005,-0.10755175352097,-0.11825186759233,-0.13130673766136,-0.14548586308955999,-0.15595951676368999,-0.16432605683804,-0.17357045412064001,-0.18326471745968001,-0.19406886398792,-0.20523284375667999,-0.21385237574577001,-0.22105769813060999,-0.2295955568552,-0.23872035741806,-0.24708683788776001,-0.25518763065338002,-0.26464396715164001,-0.27440676093102001,-0.28097534179688,-0.28538715839385997,-0.28930202126503002,-0.29278224706650002,-0.29714643955231002,-0.30223494768143,-0.30856698751450001,-0.31570345163344998,-0.32222151756286999,-0.32830327749251997,-0.33383265137672002,-0.33866074681281999,-0.34182181954384,-0.34381195902824002,-0.34596765041351002,-0.34822976589202997,-0.35206916928290999,-0.35601246356964,-0.35392120480536998,-0.34805428981781,-0.34399619698523998,-0.34073457121848999,-0.33830979466437999,-0.33575022220612,-0.32812166213989002,-0.31743076443672003,-0.30928182601929,-0.30243664979934998,-0.29599544405937001,-0.28900989890098999,-0.27564790844916998,-0.25842082500458002,-0.24477948248386,-0.23306474089622001,-0.22180896997451999,-0.20998919010162001,-0.1906183809042,-0.16691589355469,-0.14910525083542001,-0.13484236598015001,-0.12128874659538,-0.10775426775216999,-0.087863765656948006,-0.06459254771471,-0.047904927283525002,-0.035185679793358002,-0.021664641797542999,-0.0074179600924253004,0.011637719348073,0.033114887773990999,0.047966625541449003,0.058678321540356002,0.070491895079612996,0.082845397293568004,0.097126424312591997,0.11243245005608,0.12501883506774999,0.13618353009223999,0.14941754937172,0.16439393162727001,0.18282377719879001,0.20324681699276001,0.21932412683964,0.2326605618,0.24664989113808,0.26072108745575001,0.27442312240601002,0.28773745894432001,0.30030834674835,0.31220433115959001,0.32345598936080999,0.33412662148476002,0.34470266103745001,0.35490593314170998,0.36371892690659002,0.37121984362602001,0.37689927220344999,0.38106200098991,0.38485601544379999,0.38815867900848,0.39145672321320002,0.39428842067719,0.39432466030120999,0.39229643344879001,0.39025554060936002,0.38803660869598,0.38671296834946001,0.38548347353934997,0.38047009706496998,0.37280979752540999,0.36567750573157998,0.35873872041701999,0.35287663340568998,0.34741243720054998,0.33910632133483998,0.32877457141875999,0.31848600506782998,0.30796217918396002,0.29705190658568997,0.28588977456093001,0.27535465359687999,0.26508429646491999,0.25370463728905002,0.24140377342701,0.22795195877551999,0.21373832225799999,0.20095191895962,0.18905903398991,0.17666333913803001,0.16395047307013999,0.15090025961399001,0.13762983679770999,0.12494400888681,0.11250486224889999,0.098763942718505998,0.084162123501301006,0.069961227476596999,0.056219354271888997,0.044824790209531999,0.034745000302791998,0.020862916484475,0.0043887291103600996,-0.011480155400932,-0.026906037703155999,-0.040214024484157999,-0.052043635398148998,-0.065172940492630005,-0.078914374113082997,-0.091276682913303001,-0.1023365855217,-0.11056677997111999,-0.11682906746864,-0.12574085593223999,-0.13612243533134,-0.14410769939422999,-0.15017722547053999,-0.15389072895049999,-0.15604978799819999,-0.16192439198493999,-0.17011237144470001,-0.17561702430248,-0.17916898429393999,-0.18165557086468001,-0.18307593464850999,-0.18399542570114,-0.18430492281913999,-0.18377093970776001,-0.18240471184254001,-0.17993988096714,-0.17661972343922,-0.17406992614269001,-0.17183771729469,-0.16794627904892001,-0.16287904977798001,-0.15836545825005,-0.15424296259879999,-0.15071415901183999,-0.14775417745113001,-0.14554011821747001,-0.14390283823013,-0.14173513650894001,-0.13926210999489,-0.13705933094025,-0.13519917428493,-0.13481913506984999,-0.13555455207825001,-0.1356997191906,-0.13550056517124001,-0.13519249856471999,-0.13497312366962,-0.13679997622967,-0.14000006020069,-0.14120803773403001,-0.14085403084754999,-0.13904136419296001,-0.13621263206004999,-0.13601724803448001,-0.13759578764439001,-0.13748772442341001,-0.13607744872569999,-0.13318671286106001,-0.12927189469337,-0.12792031466961001,-0.12831279635428999,-0.12702111899853,-0.12449123710394,-0.12118138372898,-0.11739049851894,-0.11620712280273,-0.11675105243921,-0.11437649279833,-0.1098705008626,-0.1055846363306,-0.10147475451231,-0.099323675036429998,-0.098544321954250003,-0.095783293247222998,-0.091572470963001001,-0.087409302592277999,-0.083281435072422,-0.080549500882625996,-0.078704953193664995,-0.074409760534763003,-0.068322524428368003,-0.063197687268257002,-0.058794349431992,-0.055434465408325001,-0.052884224802255998,-0.049446377903223003,-0.045375201851129997,-0.041458565741776997,-0.037616651505232003,-0.033961482346058003,-0.030265606939793001,-0.024501882493496,-0.017027951776981,-0.0093576712533831995,-0.0012951828539371,0.0076541686430573004,0.017507884651423,0.028956934809685,0.041761554777622001,0.054387014359235999,0.066937133669853002,0.078831709921360002,0.090382963418961002,0.10418643802404,0.11975158751011,0.13458997011185,0.14899820089339999,0.16381292045116,0.17892652750015001,0.19408582150935999,0.20915614068508001,0.22244082391261999,0.23429338634013999,0.24653458595276001,0.25915199518204002,0.27401655912398998,0.29049029946326999,0.30374675989151001,0.31436496973037997,0.32415717840195002,0.33292385935782998,0.33987888693809998,0.3451786339283,0.34995907545089999,0.35400131344794999,0.35598164796829002,0.35601499676704002,0.35397815704345997,0.35008835792541998,0.34671023488045,0.34344515204429998,0.33797946572304,0.33057880401611001,0.32197734713553999,0.31232482194901001,0.30406907200812999,0.29677531123161,0.28765624761580999,0.27705267071723999,0.26631477475165999,0.25546371936798001,0.24597613513470001,0.23757821321486999,0.22849623858929,0.21886116266250999,0.20864148437977001,0.19789756834507,0.18738068640232,0.17690812051296001,0.16480968892573999,0.15133857727051001,0.13803149759769001,0.12482696771622,0.11235518008471,0.10048670321703,0.088236756622790999,0.075696729123592002,0.063094414770603,0.050470963120461003,0.038618467748164999,0.027387715876102,0.015479792840778999,0.0030680801719427,-0.0087282219901680998,-0.019981786608696001,-0.030796930193901,-0.041104964911937998,-0.049824126064777,-0.057181857526301998,-0.065385766327380995,-0.074200883507729007,-0.082508139312266998,-0.090266622602939994,-0.095768250524998003,-0.099308855831622994,-0.10353386402130001,-0.1082024872303,-0.11233720928431,-0.11589436233044,-0.11707795411348,-0.11629594862461,-0.11807388067245,-0.12195951491594,-0.12538267672062001,-0.12841543555259999,-0.12983570992946999,-0.12986741960049,-0.13077487051487,-0.13235983252524999,-0.13357201218605,-0.13445226848125,-0.13465712964535001,-0.13430431485176,-0.13505473732948001,-0.13671523332596,-0.1376536488533,-0.13796485960484001,-0.13769124448299,-0.13690346479415999,-0.13681679964065999,-0.13731098175049,-0.13743464648723999,-0.1372542232275,-0.13719159364700001,-0.13717684149741999,-0.13620942831039001,-0.13440780341625,-0.13300815224647999,-0.1319322437048,-0.13082678616047,-0.12971998751163,-0.12876479327679,-0.12801507115364,-0.12871588766575001,-0.13074487447739,-0.13296034932136999,-0.1353989392519,-0.13767470419406999,-0.13986699283123,-0.14325669407844999,-0.14771425724029999,-0.15179292857647,-0.15555791556835,-0.15893806517124001,-0.16200819611549,-0.16632451117038999,-0.17174929380417001,-0.17681372165680001,-0.18156628310680001,-0.18572552502154999,-0.18933320045471,-0.19301824271679,-0.19673146307468001,-0.19995154440403001,-0.20268613100051999,-0.20457689464091999,-0.20567660033703,-0.20705205202103,-0.20857886970042999,-0.20816387236118,-0.20591178536415,-0.20236298441886999,-0.19755931198596999,-0.19324150681496,-0.18922020494937999,-0.18208417296410001,-0.17202343046665,-0.16063520312308999,-0.14800021052361001,-0.13803595304489,-0.13044759631156999,-0.12060111761092999,-0.10872919112444,-0.097221940755844005,-0.086052730679511996,-0.076776742935180997,-0.069218419492244998,-0.059474378824234002,-0.047739379107952,-0.036335349082946999,-0.025233414024115001,-0.015755105763674001,-0.0077705150470138004,0.0017724202480167001,0.012730835936964001,0.023170409724115999,0.033116571605206001,0.041508562862873001,0.048463448882103001,0.057245224714279001,0.067721471190453006,0.077993012964724995,0.088112600147723999,0.098474837839602994,0.10907786339521,0.12021129578351999,0.13184216618538,0.14291237294674,0.15344095230103,0.16315799951553001,0.17208968102932001,0.18112894892692999,0.19024521112442,0.19883430004120001,0.20691274106502999,0.21471154689788999,0.22223694622517001,0.23016256093979001,0.23844055831432001,0.24511806666850999,0.25024107098579002,0.25448992848396002,0.25785860419272999,0.26064416766166998,0.26282027363777,0.26298326253891002,0.26116853952407998,0.25839376449585,0.25463604927062999,0.24898211658000999,0.24147725105286,0.23479829728602999,0.22889563441277,0.22242201864719,0.21539263427258001,0.20794296264647999,0.20007228851318001,0.19176673889160001,0.18302649259567,0.17384001612663,0.16420976817607999,0.15440326929091999,0.14441800117493001,0.13416884839535001,0.12366025149822001,0.11345730721951,0.10355585068464,0.093959584832190995,0.084663927555084006,0.074697069823741996,0.064072594046593004,0.054857656359672997,0.047039456665515997,0.039448976516724001,0.032086998224258,0.023776229470968,0.014524424448609,0.0069577349349856004,0.0010709660127758999,-0.0042338757775724004,-0.0089561389759182999,-0.01368592120707,-0.018424952402711001,-0.020800834521651001,-0.020807167515159,-0.020905973389745001,-0.02109813503921,-0.022947667166590999,-0.026469944044947999,-0.028341332450508998,-0.028543258085847002,-0.028800502419472001,-0.029119597747921999,-0.029600718989968001,-0.030253078788518999,-0.029565595090388998,-0.027516126632689999,-0.026022128760815,-0.025097070261836,-0.024773601442575,-0.025068728253245,-0.023932054638862998,-0.021320100873708999,-0.020056346431375001,-0.020176921039819998,-0.020702823996543999,-0.021633127704263001,-0.022288372740148998,-0.022654328495264001,-0.023209948092698999,-0.023959377780557001,-0.025027902796864999,-0.026426099240780002,-0.027520401403308001,-0.028300385922193999,-0.028883557766676001,-0.029270840808749001,-0.029470432549715,-0.029483474791049999,-0.029264723882079,-0.028816234320402,-0.027958065271378001,-0.026683524250984001,-0.025130575522779999,-0.02328734099865,-0.021991847082972998,-0.021280949935317001,-0.019973073154687999,-0.018009493127464998,-0.017186066135764001,-0.017541311681270998,-0.018979558721185001,-0.021508609876037001,-0.024838622659445,-0.028967816382647001,-0.033683724701405002,-0.038979984819888999,-0.044815547764301002,-0.051164899021387003,-0.059176292270422003,-0.068937107920647001,-0.078100152313708995,-0.086588092148303999,-0.095065042376518,-0.1035393923521,-0.11225559562445001,-0.12125239521264999,-0.12944428622723,-0.13680826127529,-0.14311940968037001,-0.14839187264442,-0.15166328847408,-0.15283668041229001,-0.15415173768997001,-0.15569847822189001,-0.15687435865402,-0.15770110487937999,-0.15689578652382,-0.15433229506016,-0.15263848006725,-0.15196599066256999,-0.15042547881602999,-0.14797523617743999,-0.14386449754238001,-0.13794113695620999,-0.13375549018383001,-0.13151882588863001,-0.12897336483002,-0.1260444521904,-0.12271292507648,-0.11896121501923,-0.11508943140507,-0.11113040149212,-0.10653103888035,-0.10127396136522,-0.095138028264046007,-0.088046796619891995,-0.081716045737266998,-0.076271228492259993,-0.070415295660495994,-0.064094431698322005,-0.057352062314749,-0.050157722085714,-0.043270077556372001,-0.036792274564504998,-0.029079496860504001,-0.020021051168442001,-0.010391794145107,-0.00017689727246760999,0.0094670578837394992,0.018372748047112999,0.029035482555628,0.041659884154797003,0.054474875330925002,0.067469604313373996,0.078985653817654003,0.088760077953338998,0.1005153208971,0.11457199603319,0.12822328507899999,0.14137925207615001,0.15320785343647,0.16357807815075001,0.17395430803299,0.18441620469093001,0.19489666819571999,0.2054131925106,0.21559801697730999,0.22534814476966999,0.236413449049,0.24905329942703,0.26028156280518,0.26992827653884999,0.27802601456642001,0.28453671932219998,0.28981292247772,0.29380959272384999,0.29770463705062999,0.30158519744873002,0.30524939298629999,0.30870175361633001,0.31213104724884,0.31588390469550998,0.31403475999831998,0.30603826045990001,0.29467526078223999,0.28012627363205,0.26146110892295998,0.23830813169479001,0.21610237658024001,0.19529484212399001,0.17445559799671001,0.15351645648479001,0.13238351047038999,0.11083494871855,0.092334270477295005,0.077273309230803999,0.063327707350254003,0.050357267260551002,0.038549497723578997,0.028132880106568,0.01542773284018,-1.8235296010971002e-05,-0.015449496917427001,-0.030674580484629,-0.045992068946362,-0.061511747539043003,-0.075621694326401007,-0.088141709566116,-0.099909566342831005,-0.11097967624664,-0.12125966697931,-0.13067594170569999,-0.14033588767051999,-0.15042436122894001,-0.15953801572323001,-0.16753414273261999,-0.17486733198165999,-0.18145324289799,-0.18898738920689001,-0.19782058894634,-0.20503279566765001,-0.21030734479426999,-0.21483913064002999,-0.21871206164359999,-0.22187034785748,-0.22436952590942,-0.22548589110374001,-0.22511531412600999,-0.22378641366959001,-0.22150966525078,-0.21869215369225001,-0.21541176736355,-0.21113181114196999,-0.2057368606329,-0.20015853643417,-0.19449873268604001,-0.18846714496613001,-0.18203078210354001,-0.17548643052578,-0.16901682317257,-0.16067382693290999,-0.15028204023837999,-0.13756676018238001,-0.12215295433998,-0.10818765312433,-0.096263960003852997,-0.083938300609588998,-0.070994392037391996,-0.057528492063283997,-0.043255582451819999,-0.031788583844899999,-0.024068556725979001,-0.013065043836832,0.002122649922967,0.01900976151228,0.037885140627623,0.053143877536058003,0.063832923769951005,0.074154771864414007,0.084565475583076005,0.094142936170100999,0.10298570245504,0.10921422392129999,0.11236788332462,0.11534695327282,0.11848741024733001,0.12129791080952,0.12388982623816,0.12462387233973,0.12298600375652,0.12276435643435001,0.12461027503013999,0.12577804923058,0.12608678638935,0.12469357997178999,0.12144441902637,0.11657831072807,0.10994393378495999,0.10324874520302001,0.096643060445785994,0.090632624924183003,0.085367605090141005,0.080120444297790999,0.074812747538090002,0.069511547684668995,0.064273603260516995,0.058520384132862001,0.052204407751560003,0.045014120638371,0.036703821271657999,0.029352197423577,0.023312073200940999,0.017529260367154999,0.011980511248112001,0.0057817595079540998,-0.0014555333182216001,-0.0070023825392127002,-0.010394520126283001,-0.013021867722273,-0.015036921016872,-0.016219489276409,-0.016457613557577001,-0.016695735976099999,-0.017003769055008999,-0.017811680212617,-0.019123468548058999,-0.021655058488250001,-0.025725420564413001,-0.029191242530942001,-0.031615942716599003,-0.034581035375595003,-0.038216464221478001,-0.043275430798531002,-0.050635244697332001,-0.053033642470837,-0.04893235117197,-0.043749835342169002,-0.038134258240461003,-0.031760446727276001,-0.024684555828571,-0.016614014282823001,-0.0073820454999804002,0.0018414801452308999,0.010916698724031001,0.019801029935479001,0.028720106929540998,0.035383183509111002,0.039316900074481999,0.041788533329964003,0.042774524539709001,0.043557129800319998,0.043978855013846997,0.047280497848988003,0.054280918091535998,0.062116596847773001,0.070466369390488004,0.079104624688625003,0.088058292865752993,0.096414014697075001,0.10395355522633,0.11134378612041,0.11873347312212,0.12556678056716999,0.13183116912841999,0.13700269162654999,0.14094159007071999,0.1440491527319,0.14627677202225001,0.14845205843449,0.15074099600315,0.15284195542335999,0.15467047691345001,0.15679542720317999,0.15962876379490001,0.16046637296676999,0.15882903337479001,0.15526001155376001,0.14971785247326,0.14277935028076,0.13447104394435999,0.12533327937125999,0.11543513834476,0.10495711117983,0.093793854117392994,0.083198666572570995,0.073641970753670002,0.062978506088257002,0.050687287002801999,0.038297440856695002,0.025895373895764,0.014560726471244999,0.0048944149166346004,-0.0062798680737614996,-0.019767761230469,-0.033250421285629002,-0.046549204736947999,-0.058281362056731997,-0.067270860075950997,-0.080671861767768999,-0.10050699859858001,-0.12037713825703,-0.1395075917244,-0.15655989944935,-0.17078022658825001,-0.18530271947384,-0.20101152360439001,-0.21498814225196999,-0.22677601873875,-0.23625074326991999,-0.24254372715950001,-0.25172501802443997,-0.26565581560134999,-0.27841001749039002,-0.28901910781860002,-0.29785004258156,-0.30462950468062999,-0.31099912524223,-0.31745475530624001,-0.32245528697968001,-0.32565101981163003,-0.32775819301605003,-0.32861194014549,-0.33018720149994002,-0.33317229151726002,-0.33532914519309998,-0.33628609776496998,-0.33619809150696001,-0.33536750078201,-0.33133652806281999,-0.32299587130546997,-0.31502002477646002,-0.30867734551429998,-0.30091717839241,-0.29170888662338001,-0.27765411138535001,-0.25665023922919999,-0.23857183754444,-0.22607839107513,-0.21326597034931,-0.19946269690990001,-0.18288297951221,-0.16197967529297,-0.14442333579062999,-0.13286121189594,-0.119050770998,-0.10163142532110001,-0.079776383936405001,-0.051463939249515998,-0.028259241953492002,-0.013929659500718001,0.0017455404158682,0.020729556679726001,0.041756317019463002,0.065954633057117004,0.085388563573359999,0.096981473267077997,0.11052688211203,0.12819987535477001,0.14753845334053001,0.16912773251534,0.18716609477997001,0.19916395843029,0.21347226202488001,0.23233366012573001,0.25148579478263999,0.27103036642075001,0.28572171926498002,0.29322552680969,0.30094781517982,0.31069436669349998,0.31987541913986001,0.32832515239715998,0.33474096655845997,0.33824148774147,0.34243127703666998,0.34847602248192,0.35364887118339999,0.35764580965041998,0.35929206013679998,0.35812470316887002,0.35493156313896002,0.34951758384705001,0.34389823675156,0.33859017491340998,0.33340460062027,0.32907062768936002,0.32102540135384,0.30727028846741,0.29392972588539001,0.28245911002159002,0.27161562442780002,0.26214635372161998,0.24858510494232,0.22827365994453,0.20986269414424999,0.19563634693623,0.18276065587997001,0.17171669006348,0.15698090195656,0.13575363159180001,0.11700865626335,0.10335388779640001,0.090575352311134005,0.078600488603114999,0.063386507332324996,0.042392462491988997,0.024646546691656002,0.013107728213072,0.0019905983936042001,-0.0095000127330422002,-0.023266086354852,-0.041231483221054001,-0.055521141737700001,-0.063296876847744002,-0.070646256208419994,-0.078747704625130005,-0.087832309305668002,-0.098812580108642994,-0.10766458511353,-0.11283556371927,-0.11783747375011,-0.12339472025633,-0.12956467270850999,-0.13702696561812999,-0.14250561594962999,-0.14471338689327001,-0.14647795259953,-0.14842179417609999,-0.15034179389477001,-0.15238742530346,-0.15391176939011,-0.15462526679038999,-0.15528124570846999,-0.15607082843781001,-0.15690419077873,-0.15807828307152,-0.15790903568268,-0.15577028691768999,-0.15274120867252,-0.14897465705872001,-0.14480271935462999,-0.14040151238441001,-0.13545519113540999,-0.12989643216133001,-0.12372092902659999,-0.11675169318914,-0.10991187393665,-0.10349006950855,-0.097248636186123005,-0.091297574341296997,-0.084874689579009996,-0.077607929706573001,-0.070390261709689997,-0.063369564712047993,-0.056903611868620002,-0.051398433744906998,-0.045292805880307999,-0.037766002118587001,-0.031086370348930002,-0.025832133367658001,-0.021941438317299,-0.020020613446832002,-0.017116626724601,-0.011813477613031999,-0.0074317092075943999,-0.0049573201686143997,-0.0033724547829479001,-0.0027982441242784001,-0.0017001080559567001,0.00089118676260113998,0.0022242597769945999,0.0014326917007565,-0.00064178934553638003,-0.0042163124307989996,-0.0074631930328905999,-0.0095470827072859001,-0.012042951770127,-0.015470370650291001,-0.019018625840544999,-0.022686289623379999,-0.025538178160787,-0.026941813528538,-0.028647774830460999,-0.031235139816998998,-0.034092299640179,-0.037260182201862002,-0.039971128106116999,-0.041722793132066997,-0.043879654258489997,-0.047002147883176998,-0.050074499100446999,-0.052917212247849003,-0.055205807089805999,-0.056654557585715998,-0.058029461652040003,-0.059604201465844997,-0.061032235622405999,-0.062236744910479001,-0.063238501548767007,-0.063876532018184995,-0.064960472285748,-0.066959470510482996,-0.068735420703887995,-0.069903723895549996,-0.070902369916439001,-0.072152897715569,-0.071898072957992998,-0.069066479802132,-0.066396154463291002,-0.064879111945628995,-0.063377365469933,-0.061977516859770002,-0.059080306440591999,-0.053521089255809999,-0.048438739031552998,-0.045181468129157999,-0.041541814804077003,-0.037330713123082997,-0.030708640813828,-0.019897222518920999,-0.010358332656324,-0.0045129619538784001,0.0015176406595855999,0.0085054952651262006,0.017467483878136,0.030076637864113,0.040532164275646002,0.046051524579525001,0.051436889916657999,0.057906202971935002,0.065662406384944999,0.075822100043296994,0.084320768713951,0.089021980762481995,0.094022132456303004,0.10052517056465,0.10822816193104,0.11819798499346,0.12572805583477001,0.12810119986533999,0.13089725375174999,0.13608570396899999,0.14188988506794001,0.14834544062614,0.15377113223076,0.15701057016850001,0.16058611869812001,0.16544322669506001,0.17066311836243001,0.17643670737743,0.18103757500647999,0.18381074070930001,0.18487714231013999,0.18385834991932001,0.18217000365257,0.18021345138549999,0.17839497327805001,0.17765179276466,0.17465710639953999,0.16765496134758001,0.15955957770348,0.15093721449375,0.14300201833248,0.13720211386681,0.1294729411602,0.11748819798231,0.10579024255276,0.095723487436771004,0.087480187416076993,0.082491993904114005,0.075637772679329002,0.064003601670265003,0.052752453833817999,0.043615035712718998,0.035747803747654003,0.030043253675103,0.022303489968181,0.0097355516627431003,-0.0019609523005784,-0.010551384650171001,-0.017975989729166,-0.024188846349715999,-0.031111231073736999,-0.040214471518993003,-0.048394571989775002,-0.054324395954609001,-0.059420570731162997,-0.063652932643890006,-0.068688414990902003,-0.075831107795237995,-0.082332558929920002,-0.086914271116257005,-0.091227918863296995,-0.095564767718315,-0.10066592693329,-0.10751111805439,-0.1133945286274,-0.11698344349861001,-0.11990427225828,-0.12254738062620001,-0.12511573731899001,-0.12780030071734999,-0.13048069179058,-0.13317397236824,-0.13574244081973999,-0.13813635706902,-0.14035293459892001,-0.14277023077011,-0.14367929100990001,-0.14197990298270999,-0.13952279090881001,-0.13701245188712999,-0.13399347662926001,-0.13057869672774999,-0.12599907815455999,-0.11962493509053999,-0.11279170215129999,-0.10603104531764999,-0.099064268171786998,-0.091649696230888006,-0.084750398993492002,-0.079005077481270003,-0.073327325284480993,-0.067234769463538999,-0.061229735612868999,-0.055363908410072001,-0.049984551966189998,-0.045467548072338,-0.040931273251772003,-0.035905446857214002,-0.030983980745077001,-0.026247762143612002,-0.022121779620647,-0.019140515476465,-0.015945764258504001,-0.011789234355092,-0.0076156244613230003,-0.0036872555501759,-0.00012133538257331,0.0027679246850311999,0.0058460691943764999,0.0096720578148960998,0.013351608067751,0.016596581786871002,0.019321085885167,0.021323144435882999,0.023028166964650001,0.024702673777938,0.025917612016200998,0.026603236794472001,0.026414165273309,0.024863293394445998,0.023225050419569002,0.022443018853663999,0.020757000893354,0.017308458685875001,0.012904535047710001,0.0075309015810490001,0.0021308888681232999,-0.0024841520935296999,-0.0077534802258015,-0.014471905305982,-0.021614970639347999,-0.029171228408813001,-0.035806063562632003,-0.040496245026588003,-0.044688113033772001,-0.048996157944202,-0.052969735115766997,-0.056321017444134001,-0.059815492480993,-0.063664801418781003,-0.068329818546772003,-0.074408769607544001,-0.080626018345356001,-0.086445853114128002,-0.091941140592098,-0.097205176949500996,-0.10154919326304999,-0.10437367111444,-0.1067361086607,-0.1091021373868,-0.11127735674380999,-0.11344487965107,-0.11486682295799,-0.11474011093378,-0.11487776786089,-0.11623608320951,-0.11808691918850001,-0.12028436362743,-0.12272498011589,-0.1253536939621,-0.12805405259131999,-0.13088801503181,-0.13333623111248,-0.13534508645535001,-0.13609062135219999,-0.13468605279922,-0.13282977044582001,-0.13151209056377,-0.12967798113823001,-0.12744827568531,-0.12297002971172,-0.11393164098263001,-0.10550374537706,-0.10068038105965001,-0.096763208508492002,-0.093181729316710996,-0.089031413197517006,-0.083043403923512005,-0.077705509960650995,-0.074662119150162007,-0.071772538125514998,-0.068316005170345001,-0.063936538994311995,-0.057895358651875999,-0.051647588610648998,-0.046389237046242003,-0.040025223046540999,-0.031631480902433,-0.021269546821713,-0.0078130457550287004,0.0051188934594393002,0.014578902162611001,0.024952646344899999,0.038420852273703003,0.053626026958226998,0.071399785578250996,0.087567970156670005,0.098667368292809005,0.10943064093590001,0.12215365469455999,0.13544349372386999,0.14937138557433999,0.16263651847839,0.17369748651981001,0.18555516004562,0.20014798641205001,0.21544250845908999,0.23095044493674999,0.24574106931685999,0.25863978266715998,0.27155670523643,0.28587588667870001,0.29963889718056003,0.31221207976340998,0.32285046577454002,0.33062687516212003,0.33676356077193997,0.34155985713004999,0.34579375386237998,0.35016325116157998,0.35408228635788003,0.35733878612518,0.36002171039580999,0.36208185553550998,0.36371028423308999,0.36503824591637002,0.36597740650177002,0.36691516637802002,0.36635512113571,0.36290916800499001,0.35861566662788003,0.35445222258567999,0.35022100806236001,0.34638571739196999,0.34167882800102001,0.33500492572784002,0.32787534594536,0.32105723023415,0.31422606110572998,0.30735316872597002,0.30049273371696,0.29420995712280001,0.28657716512679998,0.27614605426788003,0.26423019170760997,0.25136193633080001,0.23735930025578,0.22281788289547,0.20566523075104001,0.18400073051453,0.16037485003471,0.13585208356379999,0.11080674082041,0.085958234965801003,0.060549020767211997,0.033966518938541003,0.0072696525603532999,-0.018906276673078998,-0.044896326959133002,-0.070105694234371005,-0.096842624247074002,-0.12721621990203999,-0.15862898528576,-0.18977138400078,-0.22107385098933999,-0.25177925825119002,-0.28439965844154003,-0.32246398925781,-0.35883358120918002,-0.3888133764267,-0.41522598266602001,-0.43744292855263001,-0.46009775996208002,-0.48827233910561002,-0.51462775468826005,-0.53450947999954002,-0.55130571126937999,-0.56513690948485995,-0.57943636178970004,-0.59843498468399003,-0.61574113368988004,-0.62697547674178999,-0.63586014509201005,-0.64327114820480003,-0.65112739801407005,-0.66234391927719005,-0.67226177453994995,-0.67761003971099998,-0.68109095096588002,-0.68377327919006003,-0.68553870916366999,-0.68708044290543002,-0.68671011924743997,-0.68341219425201005,-0.67721694707869995,-0.66797995567321999,-0.65534460544586004,-0.63787353038787997,-0.61945909261703003,-0.60409492254257002,-0.58638358116150002,-0.56318277120589999,-0.53560048341750999,-0.50110483169555997,-0.46811529994010997,-0.44577625393866999,-0.42152971029281999,-0.38726714253425998,-0.34779781103134,-0.30141887068748002,-0.25831377506255998,-0.23045472800732,-0.20120283961296001,-0.15887662768364,-0.1123953089118,-0.062916867434977999,-0.018018716946244,0.011063806712627,0.041964530944823997,0.088125437498092998,0.13839185237884999,0.18960586190223999,0.23672071099281,0.27045354247093001,0.30611571669579002,0.35670346021652,0.40905249118804998,0.45750281214714,0.49959763884544001,0.52695900201796997,0.55586570501328003,0.60108447074890003,0.64737802743911999,0.68684494495392001,0.72046762704848999,0.74333751201630005,0.76680105924606001,0.80217707157134999,0.83672147989273005,0.86296224594116,0.88327479362488004,0.89551895856857,0.90586656332016002,0.92046642303466997,0.93311494588851995,0.93996065855026001,0.94327813386917003,0.94376569986342995,0.94145321846008001,0.93665063381195002,0.92907541990279996,0.91866195201874001,0.90518164634705001,0.88904672861098999,0.86826950311661,0.83947211503982999,0.80875390768051003,0.78125232458115001,0.75319916009902999,0.72364872694016003,0.69056558609009,0.64983665943145996,0.60843706130981001,0.57280015945435003,0.53682494163512995,0.49780249595642001,0.45431917905807001,0.40129709243773998,0.34867167472839,0.3062452673912,0.26435887813567999,0.21762719750404,0.16670471429825001,0.10699611902237,0.049780990928410998,0.0075084529817104001,-0.033476732671261,-0.082222774624824996,-0.13494876027107,-0.19316682219504999,-0.2504715025425,-0.29941549897193998,-0.34767031669616999,-0.40060892701148998,-0.45499181747437001,-0.51173543930054,-0.56427174806595004,-0.60414940118789995,-0.64093363285064997,-0.68163013458251998,-0.72230786085128995,-0.76275169849395996,-0.79955744743347001,-0.82779026031493996,-0.85334348678589,-0.88109195232391002,-0.90731042623519997,-0.93094664812088002,-0.94967222213744995,-0.95933687686919999,-0.96541094779967995,-0.97238618135452004,-0.97749495506286999,-0.98008435964583995,-0.97879660129546997,-0.97111010551453003,-0.96042090654373002,-0.94979614019393999,-0.93681967258453003,-0.92012661695480003,-0.90011197328568004,-0.87585425376892001,-0.84998649358749001,-0.82576113939285001,-0.79970282316207997,-0.76925444602965998,-0.73559534549713002,-0.69818603992462003,-0.65954649448394997,-0.62293803691864003,-0.58501255512238004,-0.54308003187179998,-0.49898934364318998,-0.45271649956702997,-0.40700396895409002,-0.36632943153380998,-0.32488256692885997,-0.2773854136467,-0.22756446897984001,-0.17605203390120999,-0.12651678919792,-0.085168257355690002,-0.044393297284842002,0.0025804042816162001,0.051230404525994998,0.099738828837871996,0.14709761738777,0.19042842090129999,0.23369710147381001,0.28128743171692,0.32874599099159002,0.37341231107711997,0.41454821825027,0.44892808794974998,0.48145145177840998,0.51735275983810003,0.55218827724456998,0.58305168151855002,0.61068481206893999,0.63198900222777998,0.65557229518890003,0.69743305444716996,0.71235054731368996,0.73012435436249001,0.74304956197739003,0.75293231010437001,0.75837808847427002,0.76126050949097002,0.76333993673324996,0.76361721754073997,0.76264864206313998,0.75752282142639005,0.74322885274886996,0.72639870643616,0.71331423521042003,0.70045143365859996,0.68724066019058005,0.67095732688903997,0.64627259969711004,0.6200504899025,0.59901064634322998,0.57896405458449995,0.55825579166411998,0.53568685054778997,0.50740855932235995,0.47938570380210999,0.45845818519592002,0.43905311822891002,0.41762682795525002,0.39424765110016002,0.36597657203674,0.33803877234459001,0.31714197993278997,0.29695302248000999,0.27271634340286,0.24535711109638,0.21181011199951,0.17907504737377,0.15680414438248,0.13575494289397999,0.10813510417938001,0.077338196337222997,0.042692102491856003,0.0088988542556763008,-0.015938129276037001,-0.041103109717369003,-0.075822681188582999,-0.11459055542946001,-0.15627269446850001,-0.19605973362922999,-0.22492635250092,-0.25237116217612998,-0.28796285390853998,-0.32527905702590998,-0.36196464300156,-0.39399570226669001,-0.41330915689468001,-0.42764523625374001,-0.44403752684593001,-0.45900177955626997,-0.47151637077331998,-0.48050040006638001,-0.48423564434052002,-0.48304367065429998,-0.47561487555504001,-0.46496149897575001,-0.45430684089661,-0.44297343492508001,-0.43257737159728998,-0.41964650154114003,-0.39869073033333002,-0.37559089064598,-0.35565328598022,-0.33750653266906999,-0.32274761795998003,-0.30785983800888,-0.28775951266289002,-0.26683899760245999,-0.24885027110576999,-0.23248457908629999,-0.21829456090926999,-0.20428760349750999,-0.18740013241768,-0.17017358541489,-0.15486037731171001,-0.14043152332306,-0.12700495123863001,-0.11315017938614,-0.096426129341125003,-0.07897461950779,-0.062846727669239003,-0.046971414238214,-0.030814418569207001,-0.014403235167265001,0.0028588250279427,0.019769903272390001,0.034702863544225998,0.048719763755798,0.062543101608752996,0.076072014868259,0.090113297104835996,0.10283303260803001,0.11165324598551001,0.11826635152102,0.12392524629831,0.12825626134872001,0.13155500590801,0.13304074108600999,0.13163799047470001,0.12791942059993999,0.12213998287916,0.11444189399481,0.10425091534853,0.093943953514098996,0.087531507015227994,0.081696227192879001,0.073288962244987002,0.063602209091186995,0.053116783499717997,0.041682086884975003,0.029009636491537,0.015877904370427,0.0033699367195368,-0.0090212821960448993,-0.02166523039341,-0.034182295203209,-0.046347748488187998,-0.057811602950095999,-0.068002410233021005,-0.076975226402283006,-0.084677301347255998,-0.090823218226432995,-0.094884611666203003,-0.097209021449088995,-0.097987182438373996,-0.097384542226790993,-0.095821246504784005,-0.092965744435787007,-0.088292941451072998,-0.082481734454632,-0.076270096004008997,-0.069571167230605996,-0.062651559710502999,-0.055281799286603997,-0.046998795121908001,-0.038507454097271,-0.03051289357245,-0.023211313411593,-0.017232175916433001,-0.012386184185743001,-0.0087974769994616994,-0.0061254012398421999,-0.0034596601035445998,-0.0021208107937127,-0.0039401929825544002,-0.0079335533082485008,-0.014049624092877,-0.020755052566528001,-0.024777386337519001,-0.029060084372759001,-0.037226643413304998,-0.047057028859854001,-0.057262822985648998,-0.066898182034491993,-0.073204979300499004,-0.078522086143493999,-0.085656397044658994,-0.092957571148872001,-0.099335372447968001,-0.10450816899538,-0.10767865180969,-0.10867055505514001,-0.10634130984545,-0.10214781761169001,-0.097977578639984006,-0.093166060745715998,-0.088418282568455006,-0.081409022212029003,-0.067526645958424003,-0.050735589116812002,-0.035081997513771002,-0.020135067403316002,-0.0089409528300166009,0.0036723520606756002,0.026903435587882999,0.053340632468461997,0.074932649731636006,0.094102896749973006,0.10951665788889001,0.12515951693058,0.14899936318397999,0.17435243725777,0.19337503612040999,0.20912973582745001,0.22214788198471,0.23435156047344,0.25042709708214,0.26637202501297003,0.27708765864371998,0.2851881980896,0.29214304685593001,0.29883241653442,0.30851319432259,0.31791031360625999,0.32229298353195002,0.32444825768470997,0.32661539316177002,0.32888501882553001,0.3331743478775,0.33742398023605003,0.33876413106918002,0.33843398094177002,0.33716693520545998,0.33485355973244002,0.33141949772835,0.32743147015571999,0.32393983006477001,0.32048925757407998,0.31687486171722001,0.31295394897460999,0.30870655179023998,0.30336588621139998,0.29540419578552002,0.28553321957588002,0.27431094646454002,0.26150724291800997,0.24665512144566001,0.23061850667,0.21515503525734,0.19885851442814001,0.17978891730308999,0.15901871025562,0.13667285442352001,0.11470811069012,0.098198860883713004,0.082646459341049,0.061642892658710001,0.038288298994302999,0.014449302107095999,-0.0088457651436328992,-0.027436081320047,-0.045343536883593001,-0.068711906671524006,-0.094346329569817006,-0.1199369430542,-0.14474809169769001,-0.16517138481140001,-0.18448910117149001,-0.20782642066479001,-0.23221239447594,-0.25505322217941001,-0.27597969770432002,-0.29208683967589999,-0.30606883764267001,-0.32261583209037997,-0.33828434348106001,-0.34904444217682001,-0.35542622208594998,-0.35587674379348999,-0.35191267728806003,-0.34447333216666998,-0.33599707484245001,-0.33178222179412997,-0.33044362068175998,-0.33179426193236999,-0.33640787005424,-0.34674954414367998,-0.35908576846123003,-0.36707025766373003,-0.37276530265808,-0.37639093399048001,-0.37913489341736001,-0.38396334648132002,-0.38904792070388999,-0.39211368560790999,-0.39408281445503002,-0.39542093873023998,-0.39646705985068997,-0.39802715182303999,-0.40016773343085998,-0.40367403626442,-0.40787658095360002,-0.41190549731255,-0.41580134630202997,-0.42123791575432001,-0.42331719398499001,-0.4111300110817,-0.39099055528641002,-0.36992284655571001,-0.34672531485558,-0.32255423069,-0.29727435112,-0.27089056372643,-0.24420848488808,-0.21886923909187,-0.19461345672607,-0.17254368960857,-0.15074701607227001,-0.12513624131680001,-0.098065480589866999,-0.072404578328133004,-0.047313801944256002,-0.022971775382757,0.0015978217124939,0.028905350714922,0.057224825024604999,0.084187790751457006,0.11038888990879001,0.13620319962502,0.16074708104134,0.18206486105919001,0.20109659433364999,0.21837815642357,0.23473450541495999,0.25161334872246,0.27005937695503002,0.2943420112133,0.32099169492722002,0.34443268179893,0.36652117967606002,0.38807147741317999,0.40941953659058,0.43280443549156,0.45544618368148998,0.47143059968947998,0.48408207297325001,0.49730050563812001,0.51083952188491999,0.52741104364394997,0.54401910305023005,0.55470335483551003,0.56228160858153997,0.56998485326767001,0.57681840658187999,0.58306169509887995,0.58700907230376997,0.58547133207321,0.57799321413039995,0.56135535240172996,0.53704851865768,0.50424045324325995,0.46823710203170998,0.44251719117165,0.42075514793396002,0.39547413587570002,0.36895799636840998,0.34119492769241,0.31474667787552002,0.29762497544289002,0.28388151526451,0.26310163736343001,0.23936529457569,0.21564204990864,0.19306465983391,0.17802359163761,0.16488713026047,0.14245010912417999,0.1159250959754,0.090737290680408006,0.067303277552128005,0.050701983273029001,0.037724576890469,0.023568961769341999,0.0091754589229822003,-0.0057323114015162,-0.021416569128633,-0.03749205544591,-0.056549243628979,-0.086741283535957003,-0.12230808287859,-0.15370017290115001,-0.18293802440165999,-0.20857644081116,-0.23292033374310001,-0.26222735643387002,-0.29231739044188998,-0.31603270769119002,-0.33546951413155002,-0.35115540027617997,-0.36424654722214,-0.37805581092834001,-0.39162573218345997,-0.40429532527924,-0.41654992103576999,-0.42886841297150002,-0.44196248054504,-0.45983317494392001,-0.47785982489585999,-0.48574006557464999,-0.48706889152527,-0.48533344268799,-0.47936880588531,-0.46623042225838002,-0.45026826858521002,-0.44188821315764998,-0.43750730156897999,-0.4338350892067,-0.43161338567733998,-0.43169763684272999,-0.43241226673125999,-0.42956677079201,-0.42444923520088002,-0.41799688339232999,-0.41001245379447998,-0.40053287148476002,-0.38946214318275002,-0.37645485997200001,-0.36181181669235002,-0.34621673822402999,-0.32938003540039001,-0.31007748842239002,-0.29020923376083002,-0.27489304542541998,-0.26181483268737998,-0.24780063331127,-0.23331564664841001,-0.21903310716152,-0.20236396789551001,-0.17530755698681,-0.14178858697414001,-0.10759016871452,-0.072087824344634996,-0.036182567477226001,-0.0012357085943222,0.027571920305490001,0.052689965814352001,0.077726878225803001,0.10220235586166,0.12668158113955999,0.15149515867232999,0.17836412787437,0.20620411634444999,0.233044013381,0.25914302468299999,0.28412178158759999,0.30791628360748002,0.33033585548401001,0.35093757510184997,0.36795470118522999,0.38240593671799,0.39623078703879999,0.40892961621284002,0.42038628458977001,0.43031311035156,0.43726313114165999,0.44255051016808,0.44910335540771001,0.45647069811821001,0.46573224663733997,0.47554269433022001,0.48312059044838002,0.48801097273826999,0.48683914542197998,0.48076015710830999,0.47057181596755998,0.45711228251456998,0.44334381818771001,0.42877966165543002,0.41369840502739003,0.39826565980911,0.38274657726287997,0.36793887615204002,0.35633945465088002,0.34772476553916998,0.34338334202766002,0.34235531091690002,0.34275305271148998,0.34448173642159002,0.34883052110672003,0.35047984123230003,0.33093801140785001,0.29835799336433,0.26595810055732999,0.23257125914096999,0.20296134054661,0.17578914761542999,0.14973145723343001,0.12556876242161,0.10496432334185,0.087718516588211004,0.073984198272228005,0.064201608300209004,0.060911796987057003,0.061858970671892,0.061458360403776002,0.060537569224833998,0.061541408300400002,0.058066755533218002,0.026157349348068001,-0.021928429603577,-0.060880772769451003,-0.095951005816460003,-0.12796400487422999,-0.15761642158031,-0.18861508369446001,-0.21811714768410001,-0.23838666081429,-0.25193074345589,-0.26184371113777,-0.26818013191223,-0.27258682250977001,-0.27556121349335,-0.27964544296264998,-0.28488096594809997,-0.29240629076958002,-0.30325776338576999,-0.32401692867279003,-0.34963032603263999,-0.36617687344550998,-0.37754037976264998,-0.38803371787071,-0.39702734351157998,-0.40531262755393999,-0.41213002800941001,-0.41497221589088001,-0.41502687335013999,-0.41492637991905001,-0.41404959559441001,-0.4118332862854,-0.40850138664246,-0.40456071496009999,-0.39985328912735002,-0.39406308531760997,-0.38738167285919001,-0.38034731149673001,-0.37277954816817999,-0.36483776569366,-0.35571613907813998,-0.34227001667022999,-0.32559126615523998,-0.30669099092483998,-0.28687149286269997,-0.27288159728049999,-0.26132789254188998,-0.24370133876801001,-0.22234170138836001,-0.19947579503058999,-0.17613363265991,-0.1591199785471,-0.14461684226989999,-0.12185652554034999,-0.094442874193192,-0.068213857710360995,-0.043161459267138998,-0.024222420528531002,-0.0086063314229250006,0.011962570250033999,0.034298278391361001,0.052158840000629002,0.065865784883499007,0.071648791432380995,0.071594446897507005,0.070176966488360998,0.068177804350852994,0.071435377001762002,0.079347200691699996,0.093032054603100003,0.11333349347115,0.14758574962616,0.18952175974846,0.21899914741515999,0.23987345397472001,0.25346738100052002,0.25998437404633001,0.25912955403327997,0.25357383489608998,0.25428614020348,0.25889638066291998,0.26542568206786998,0.27418237924576,0.28612112998962003,0.29973149299621998,0.30929601192473999,0.31596311926842002,0.32039445638656999,0.32263559103012002,0.32347920536995001,0.32238635420799,0.31741321086884,0.30927917361259,0.29970228672027999,0.28833636641501997,0.27410072088241999,0.25840404629706998,0.24705475568770999,0.2382820546627,0.22872816026210999,0.21872913837433,0.20597717165946999,0.19316732883453,0.19159679114819,0.19740837812424,0.20193000137806,0.20632344484328999,0.21155244112015001,0.21467922627926,0.20137827098370001,0.17676538228989,0.15322333574295,0.12889502942562001,0.10295829921961,0.077211275696753998,0.060352042317389998,0.049603860825300002,0.038668084889649998,0.028552820906043001,0.018979160115123,0.010770763270557,0.0081569496542215,0.0092651462182402992,0.0088343033567070996,0.0072312932461500003,0.0032245789188892001,-0.0041738753207027999,-0.022136723622679998,-0.047257825732231001,-0.068979650735855005,-0.088717445731162997,-0.10597442090511,-0.1202919408679,-0.12831464409828,-0.13137304782866999,-0.13285562396049,-0.13295219838618999,-0.13474899530411,-0.13811038434504999,-0.14542327821254999,-0.15532602369785001,-0.16323606669903001,-0.16955803334712999,-0.17292626202106001,-0.17358575761317999,-0.17135751247406,-0.16663827002048001,-0.16091006994247001,-0.15439826250076,-0.14937022328377,-0.14541736245154999,-0.14255438745022,-0.14029516279696999,-0.13620927929877999,-0.13072539865971,-0.12415170669556,-0.11652458459139001,-0.10804421454668001,-0.098890833556652,-0.090142086148261996,-0.081649616360664007,-0.073514968156815005,-0.065644383430480999,-0.057682573795318999,-0.049643173813820003,-0.041512969881295998,-0.033046223223208999,-0.022600231692195001,-0.010858628898859,-0.00010059680789709,0.0098399277776479999,0.018238717690109998,0.025112371891737002,0.02962563559413,0.03232279792428,0.035436112433672,0.038736291229725002,0.04236551374197,0.046678882092237001,0.054416541010140998,0.064365491271018996,0.071950085461139998,0.077752999961375996,0.081549093127251004,0.083447664976119995,0.083464153110981001,0.081983953714371005,0.081115968525410004,0.080659233033657005,0.081217274069786002,0.082539230585098003,0.083798743784428004,0.085002020001410994,0.085653446614742001,0.085710339248180001,0.084546215832232999,0.082208320498466006,0.078511402010917997,0.073429472744464999,0.066611878573895,0.058149658143520001,0.048337511718273003,0.037092804908751997,0.023560132831334998,0.0085964370518922997,-0.0031088190153241001,-0.012424234300852001,-0.020935442298650998,-0.028490943834185999,-0.034968182444571998,-0.040744394063950001,-0.048187498003243998,-0.056861035525798999,-0.065958827733994002,-0.075534224510192996,-0.085319742560387005,-0.095407076179980996,-0.10617831349373,-0.11753427237272,-0.12918695807457001,-0.14111341536045,-0.15310233831406,-0.16499660909176,-0.17557235062122001,-0.18503342568874001,-0.19367903470993,-0.20152372121810999,-0.20889553427696,-0.21570643782616,-0.22177368402481001,-0.22696797549725001,-0.23017591238022,-0.23168659210205,-0.23237136006355,-0.23231601715087999,-0.23296104371547999,-0.23388032615185,-0.23333218693732999,-0.23157666623591999,-0.22923938930035001,-0.22601479291915999,-0.22012761235236999,-0.21192993223667,-0.20220413804053999,-0.19114671647549,-0.18045756220817999,-0.17020764946938,-0.16251315176487,-0.15686625242232999,-0.15175396203995001,-0.14699397981167001,-0.14029991626739999,-0.13176026940346,-0.11973393708467001,-0.10483777523041,-0.090164467692375003,-0.075315773487090995,-0.059763550758361997,-0.043636783957481003,-0.027279540896415998,-0.010979223996401,0.0023205396719277,0.013556592166424001,0.027381230145692999,0.043220456689596003,0.061032194644213,0.080151423811912995,0.094859905540942993,0.10666088014841001,0.12272077053784999,0.14192426204681,0.16174940764904,0.1819744259119,0.19830490648745999,0.21202751994133001,0.23003640770912001,0.25117990374565002,0.27231377363205,0.29324552416800997,0.30965590476990001,0.32247948646544999,0.33583801984786998,0.34902936220169001,0.35973733663558999,0.36802068352699002,0.37235260009766002,0.37315002083777998,0.37247577309607999,0.37015849351883001,0.36642435193062001,0.36123803257942,0.35422521829605003,0.34577804803848,0.33905795216559997,0.33362612128258001,0.32843533158302002,0.32349064946174999,0.31869864463806002,0.31346175074576998,0.30163949728012002,0.28462272882461997,0.26957628130912997,0.25576734542847002,0.24295510351658001,0.23063689470290999,0.21355608105658999,0.19302056729794001,0.17675012350082001,0.16375827789306999,0.15174147486687001,0.14047642052174,0.12540093064308,0.10777559876442,0.095952875912188998,0.088674686849117001,0.081338450312613997,0.073988705873489005,0.062780447304249004,0.048738852143287999,0.038857109844685003,0.031967658549547001,0.022722734138370001,0.011382300406693999,-0.0048024537973106003,-0.024629211053252002,-0.038118705153465,-0.046710457652807,-0.056218117475509997,-0.066334009170532005,-0.079113624989986003,-0.093804374337196003,-0.10375021398067,-0.11037294566630999,-0.12291920185089,-0.14047659933567,-0.16245943307877,-0.18778145313263001,-0.20414593815804,-0.21320515871047999,-0.2219000607729,-0.22973169386386999,-0.23696394264698001,-0.24337361752987,-0.24651215970515999,-0.24703520536422999,-0.25036185979843001,-0.25582987070084001,-0.26106834411620999,-0.26590570807456998,-0.26645842194557001,-0.26314485073089999,-0.25690859556197998,-0.247961550951,-0.23927769064903001,-0.23071163892745999,-0.22344943881035001,-0.21720209717750999,-0.20951701700687,-0.20075677335261999,-0.19298642873763999,-0.1862036883831,-0.18242381513118999,-0.18122693896294001,-0.17933651804924,-0.17698976397513999,-0.17437192797661,-0.17145317792892001,-0.16819541156292001,-0.16434644162654999,-0.15616166591644001,-0.14428080618382,-0.13363283872604001,-0.12387362122536,-0.11523345857859001,-0.10729449987410999,-0.094222649931908001,-0.076968908309936995,-0.063328683376312006,-0.052622146904469001,-0.042629525065422003,-0.033233482390642,-0.020689658820628998,-0.0056288745254278001,0.0064365477301179998,0.015972875058651002,0.024567250162363,0.032309792935848,0.042023248970508999,0.053260568529367003,0.061933543533086999,0.068427316844463001,0.074747636914252999,0.080874502658843994,0.088259600102901001,0.096710205078125,0.10464428365231,0.11219868808984999,0.12005686014891,0.12823101878165999,0.13753153383732,0.14785802364348999,0.15841498970984999,0.16922941803932001,0.17998801171779999,0.19075454771518999,0.20275351405143999,0.21560473740100999,0.22366277873515999,0.22748880088328999,0.23147118091582999,0.23538023233413999,0.23952937126160001,0.24356822669506001,0.24133257567883001,0.23347237706183999,0.22601886093616,0.21860605478287001,0.20979864895344,0.19966967403888999,0.18842417001723999,0.17613640427589,0.1643281430006,0.15292249619960999,0.14163453876971999,0.13060408830643,0.12263487279415,0.11745519191027,0.11199779063463,0.10655327886343,0.10400699079037,0.10437799245119,0.11141551285982,0.12451953440905,0.1346575319767,0.14228995144366999,0.14904391765593999,0.15485866367817,0.15963868796825001,0.16326627135277,0.16309283673763,0.15923139452933999,0.15174232423306,0.14063273370266,0.12560516595839999,0.10683278739452,0.088622018694877999,0.070586964488028994,0.047283671796322001,0.018976744264364,-0.01347316801548,-0.049738910049200002,-0.080599330365658001,-0.10657384246588,-0.1324629932642,-0.15806351602077001,-0.18235215544701,-0.20518958568573001,-0.22245633602142001,-0.23414045572281,-0.23518455028533999,-0.22604484856129001,-0.21439965069294001,-0.20012325048446999,-0.18688158690928999,-0.17441827058792,-0.15859128534794001,-0.13966131210327001,-0.12181399017572,-0.10501054674387,-0.091654039919375999,-0.081716239452362005,-0.077251017093658003,-0.078067198395728996,-0.079873338341712993,-0.082768343389033994,-0.085538886487484006,-0.088432759046554996,-0.099925652146339,-0.11951541900635,-0.13658761978149001,-0.15137475728989,-0.16253954172134,-0.17028750479221,-0.18159075081348,-0.19609425961971,-0.20560157299042001,-0.21030646562576,-0.21121501922607,-0.20826581120491,-0.19860784709453999,-0.18242764472961001,-0.16582103073596999,-0.14864541590214,-0.13016171753406999,-0.11028315126896,-0.083139702677726995,-0.049077458679676,-0.021212819963694,0.00074880570173264005,0.020640280097723,0.038434091955423001,0.055761091411114003,0.072525642812252003,0.084400750696659005,0.091479413211346006,0.095831245183944994,0.097410991787910003,0.094217516481875999,0.086367793381214003,0.081126898527144997,0.078357838094233995,0.074323661625385007,0.069057047367096003,0.061345517635345001,0.051300685852766002,0.048463940620422002,0.052683636546134997,0.058162558823823998,0.064951613545417994,0.073527656495570998,0.083883330225945005,0.095174178481102004,0.10740742832422,0.12077325582504,0.13526554405689001,0.15038771927357,0.16611978411674,0.17786100506783001,0.18565036356449,0.19313089549540999,0.20028229057788999,0.2055484354496,0.20892427861690999,0.20652838051319,0.19837926328182001,0.18925189971924,0.17913870513439001,0.16777499020100001,0.15516053140163,0.13948497176169999,0.12074357271194,0.10499522089957999,0.092249006032944003,0.080253802239895006,0.069001898169518003,0.060305144637823001,0.054168600589036997,0.050486963242292002,0.049263894557952999,0.049637570977210999,0.051603365689515998,0.055234152823687002,0.060523055493832002,0.069023273885249994,0.080778166651726005,0.090790770947933003,0.099026143550872997,0.10535821318626,0.10975933820009,0.11553964763879999,0.12279331684113,0.12440045177936999,0.1202818825841,0.11124479770659999,0.097224816679955001,0.084516450762748996,0.073226064443587993,0.060434348881244999,0.046106081455946003,0.030494010075926999,0.013562822714447999,-0.0020482763648032999,-0.016305541619657998,-0.028952527791261999,-0.039978604763745998,-0.049611806869507002,-0.057855077087879,-0.064978659152984994,-0.071048051118850999,-0.072155408561229997,-0.068155832588672999,-0.063289083540439994,-0.057610623538493999,-0.052159387618303001,-0.046996407210826999,-0.040130756795406002,-0.031464017927646998,-0.023963030427694001,-0.017683213576674,-0.012672890909016001,-0.0088955042883754002,-0.0084692947566509004,-0.011493509635329,-0.015790207311511002,-0.021317934617399999,-0.027575975283979998,-0.034466121345758001,-0.045698247849940997,-0.061496328562498002,-0.076647169888020006,-0.091000676155089999,-0.10534538328647999,-0.11969936639070999,-0.13382148742676001,-0.14773030579089999,-0.16059444844723,-0.17240990698337999,-0.18260404467583,-0.19122375547886,-0.19571177661419001,-0.19586065411567999,-0.19589897990227001,-0.19597746431828,-0.19550527632236001,-0.19453892111778001,-0.19073683023453,-0.18386717140674999,-0.17872340977192,-0.17553240060806,-0.17240697145462,-0.16935910284519001,-0.16410344839096,-0.15634818375111001,-0.15208205580711001,-0.15162301063538,-0.15208572149277,-0.15334638953209001,-0.15644310414790999,-0.16148395836352999,-0.16649456322192999,-0.17142264544964,-0.17565864324569999,-0.17918354272841999,-0.18162539601326,-0.18294696509837999,-0.18372206389904,-0.18404060602187999,-0.18222367763519001,-0.17817768454551999,-0.17227092385292,-0.16441315412520999,-0.15708358585835,-0.15047340095042999,-0.14278024435042999,-0.13390979170799,-0.12425666302443,-0.11377835273743001,-0.10380151867867,-0.094469815492630005,-0.083957888185978005,-0.072100594639777998,-0.060548551380634003,-0.049309976398945,-0.039812851697205998,-0.032141573727131001,-0.026385933160781999,-0.022681515663861999,-0.018504874780773999,-0.01372220274061,-0.0082714529708027996,-0.0020838882774114999,0.0036725155077874999,0.0088329277932643994,0.015419909730554,0.023566702380775999,0.032553765922785,0.042163725942372998,0.056289453059435002,0.075449705123901006,0.094043627381325004,0.11169134080409999,0.12952116131783001,0.14741699397564001,0.16861222684383001,0.1937084197998,0.21539425849915,0.23310592770576,0.24900801479816001,0.26306554675102001,0.27781936526299,0.29373374581336997,0.30560755729674999,0.31294983625411998,0.31852066516875999,0.32234337925911,0.32683634757996,0.33248016238213002,0.33402848243713001,0.33091396093369002,0.32682606577873002,0.32193449139594998,0.31704589724540999,0.31224539875983998,0.30735164880753002,0.30227860808371998,0.29829132556915,0.29546836018562,0.29408648610115001,0.29427945613861001,0.29441472887992998,0.29433795809746,0.29461616277695002,0.29528427124022999,0.29650646448134999,0.29856365919112998,0.29724854230880998,0.29191669821739002,0.28740054368973,0.28415551781654003,0.28097259998321999,0.27831169962883001,0.26811200380325001,0.24896474182605999,0.23184174299240001,0.21780590713024001,0.20378437638283001,0.19008567929268,0.16946238279343001,0.14042839407921001,0.11521196365356,0.095153987407683993,0.075218267738818997,0.055304527282715003,0.031940232962370002,0.0041863583028316003,-0.019647795706986999,-0.038560278713703003,-0.056631352752447003,-0.074008293449878998,-0.092797875404357993,-0.11365889012814,-0.13062264025211001,-0.14279903471470001,-0.15504550933837999,-0.16777862608433,-0.18073822557926,-0.19413936138153001,-0.20533882081509,-0.21384581923484999,-0.22277885675430001,-0.23246620595455,-0.24224162101746,-0.25222459435463002,-0.26030972599982999,-0.26594072580338002,-0.27340006828308,-0.28314575552940002,-0.29461371898651001,-0.30814474821090998,-0.31945833563804998,-0.32798153162003002,-0.33547013998031999,-0.34206473827361999,-0.34758153557777,-0.35194772481918002,-0.35600638389587003,-0.35992619395255998,-0.36270272731781,-0.36415827274322998,-0.36513474583625999,-0.36552488803863997,-0.36775791645049999,-0.37269759178161999,-0.37336274981499001,-0.36856007575989003,-0.36356166005134999,-0.35872885584830999,-0.35586619377135997,-0.35601609945297003,-0.35010230541228998,-0.33637443184853,-0.32324036955833002,-0.31133100390433999,-0.30324128270148998,-0.30043593049049,-0.29082483053206998,-0.27203345298767001,-0.25530076026916998,-0.24185205996037001,-0.23118810355663,-0.22444166243076,-0.2099004983902,-0.18490140140056999,-0.16322162747383001,-0.14666399359703,-0.13213446736335999,-0.12042895704508,-0.10071391612291,-0.070180162787436995,-0.044210594147444,-0.025009829550982,-0.0078244395554065999,0.0069232629612088004,0.027793839573859998,0.057137459516524998,0.082252405583858004,0.10123206675052999,0.11845760047436001,0.13392472267151001,0.15169459581375,0.17312023043633001,0.19031919538975001,0.20200188457966001,0.21150895953178001,0.21894301474094,0.22645258903502999,0.23462690412998,0.24080410599709001,0.24454484879971,0.2470945417881,0.24860033392906,0.24875187873839999,0.24726711213589,0.24657309055328,0.24711726605892001,0.24774359166622001,0.24838350713252999,0.24846112728118999,0.24755845963955,0.24882937967777,0.25315493345260998,0.25627505779266002,0.25744175910950001,0.25857803225517001,0.25990059971808999,0.26136547327041998,0.26322475075722002,0.26335322856902998,0.26130542159080999,0.25833171606063998,0.25442755222321001,0.25115674734116,0.24950729310513001,0.24274231493473,0.22927252948283999,0.2144768089056,0.19845725595951,0.18638746440411,0.18004764616489,0.17122744023799999,0.15831334888935,0.14553646743297999,0.13319285213946999,0.12314894795417999,0.11637631058693,0.10741467773914,0.094986543059349005,0.083203375339508001,0.072525843977927995,0.063670888543128995,0.057305138558148998,0.049227997660636999,0.038337625563145003,0.028588842600583999,0.020686279982327999,0.013218861073256,0.0059465924277901996,-0.00035283609759063,-0.0053668948821723001,-0.010761281475425001,-0.016739571467042001,-0.02373287640512,-0.031994253396987998,-0.040265604853630003,-0.048202704638242999,-0.057077713310719001,-0.067225947976112005,-0.077519863843917999,-0.088034562766551999,-0.096860304474831002,-0.10344868153334,-0.10948270559311001,-0.11527533829212,-0.1203141734004,-0.12482049316167999,-0.12650729715824,-0.12445575743914,-0.12278517335653,-0.12242542952299,-0.12122892588377,-0.11896026879549,-0.11518172174692,-0.10947662591934,-0.10419170558453,-0.099904350936413006,-0.095191434025763993,-0.089776657521725006,-0.083980701863765994,-0.076893538236618,-0.075851842761039998,-0.083435699343681002,-0.090150006115436998,-0.094332635402678999,-0.097171418368816001,-0.098962709307670996,-0.097547911107540006,-0.092293374240398005,-0.084978185594082004,-0.075830146670341006,-0.065341487526894004,-0.054311331361532003,-0.037534318864346002,-0.012727282941340999,0.010326734744012,0.02933656051755,0.048525687307119002,0.067965939640999007,0.091482251882553003,0.12133939564228,0.14698849618435,0.16590136289596999,0.18252776563167999,0.19703303277493001,0.21274270117283001,0.23188234865665,0.24389341473578999,0.24657107889652,0.24194295704364999,0.2305705845356,0.20890557765960999,0.17410591244698001,0.14119544625281999,0.1137278676033,0.086913786828517997,0.060366101562976997,0.032640330493449998,0.0018947198987007,-0.021766379475594001,-0.035876698791981,-0.043811999261378999,-0.045947566628455998,-0.042195640504359998,-0.031494911760091997,-0.021546063944696998,-0.015522501431406001,-0.0025922805070877001,0.020091664046049,0.047300748527049997,0.080053962767123996,0.10590405017137999,0.11974761635065,0.13766801357269001,0.16387210786343001,0.1906953305006,0.21887271106243,0.23573239147663,0.23727010190487,0.23088711500167999,0.21716770529747001,0.19983059167862,0.1799281090498,0.15706755220890001,0.13222810626029999,0.099137589335442006,0.054663032293320001,0.010081632994115,-0.032641001045703999,-0.071377791464329002,-0.10379185527562999,-0.1399717181921,-0.18381661176681999,-0.22406871616839999,-0.25861081480980003,-0.28683978319168002,-0.30722075700759999,-0.32673007249831998,-0.34816312789916998,-0.36340752243996,-0.37059706449509,-0.37134280800818997,-0.36571633815764998,-0.35379165410995,-0.33425155282021002,-0.31539356708527,-0.29931086301804,-0.28478759527205999,-0.27155053615570002,-0.26137664914130998,-0.25519227981567,-0.24984075129031999,-0.24438166618346999,-0.24037408828734999,-0.23781180381774999,-0.23854340612888,-0.24430340528488001,-0.24743343889712999,-0.24538818001747001,-0.24291369318962,-0.24067328870296001,-0.24009318649768999,-0.24292381107807001,-0.24143750965595001,-0.23272573947906,-0.22338078916073001,-0.21478439867495999,-0.20693516731261999,-0.20202267169952001,-0.18814937770366999,-0.16056528687477001,-0.13012889027596,-0.099102608859539004,-0.067181445658206995,-0.034022402018309,-0.0031410744413733001,0.024550031870603999,0.048996273428202002,0.069816298782824998,0.088307559490203996,0.10481697320937999,0.11908897012472,0.13110715150832999,0.14086256921290999,0.14833581447600999,0.15345379710196999,0.15523585677147,0.15923303365707001,0.16776154935359999,0.17576321959496,0.18184685707091999,0.18772307038307001,0.19357186555861999,0.19993276894093001,0.20711921155453,0.21437530219555001,0.22128297388554,0.22915413975716001,0.23789174854754999,0.24986591935158001,0.26627808809280001,0.28439283370972002,0.30444949865340998,0.32177668809891002,0.33522683382034002,0.34354436397552002,0.3451828956604,0.34564390778541998,0.34718143939972002,0.34521719813347002,0.33899441361427002,0.32676404714584001,0.30556562542915,0.28815817832946999,0.28020939230919001,0.26950693130492998,0.25245103240013,0.23296290636063,0.21006859838962999,0.19262135028839,0.18562775850296001,0.17610828578471999,0.16002589464188,0.14145500957966001,0.11935442686081001,0.10266767442226001,0.095561876893044004,0.090004868805408006,0.083931833505629994,0.078391902148724005,0.073003455996513006,0.070032447576522994,0.072568446397780997,0.067684471607208002,0.049589022994040999,0.029348773881793001,0.0088923573493958005,-0.0078451028093696005,-0.01607583835721,-0.032600328326225003,-0.065029814839363001,-0.098360434174538006,-0.12929175794125,-0.15572421252728,-0.17372719943522999,-0.19737355411053001,-0.23380360007286,-0.26697546243668002,-0.29215556383133001,-0.31218618154526001,-0.32570144534111001,-0.34055683016777,-0.36085385084152,-0.37806758284568998,-0.38991409540175997,-0.39702299237250999,-0.40039578080177002,-0.39377313852309997,-0.37206679582595997,-0.35095849633217002,-0.33584082126616999,-0.32252746820450001,-0.31220883131027,-0.29607430100441001,-0.26811340451241,-0.24413718283176,-0.23034253716469,-0.21835377812386,-0.20747521519661,-0.19168417155743001,-0.16587242484093001,-0.14430156350136,-0.13323056697845001,-0.12246320396662,-0.1101730838418,-0.092593125998973999,-0.064825817942619005,-0.042775835841893997,-0.033481799066066999,-0.026376875117421001,-0.019009683281183,-0.010621466673910999,0.0012186961248517,0.0080615608021617005,0.0055694864131509998,0.0018503532046452,-0.00076860282570123998,-0.0027984774205833999,-0.0029836827889084998,-0.0063168299384415002,-0.015349883586167999,-0.025678381323814,-0.036236301064491001,-0.046575017273426,-0.057329442352057003,-0.063768960535525998,-0.063912339508533006,-0.059223853051662001,-0.049481306225061,-0.036632396280765998,-0.021275870501995,-0.0039286687970161004,0.014548476785421,0.036838307976723002,0.064834982156753998,0.093834012746810996,0.12309953570366,0.14919529855250999,0.17003409564495001,0.18855233490466999,0.20606936514377999,0.22001951932906999,0.22999700903893,0.23435796797276001,0.23214966058731001,0.22443404793739,0.21136203408241,0.19334065914154,0.17043472826480999,0.14336140453814999,0.11424940824509,0.074419192969799,0.016541421413421999,-0.040019039064646003,-0.088337630033493,-0.13056886196136,-0.16389061510562999,-0.19936892390250999,-0.24437983334064001,-0.28346204757690002,-0.31083282828330999,-0.33027017116546997,-0.34027382731438,-0.34979397058487,-0.36496090888977001,-0.3734547495842,-0.36980643868446,-0.36083567142487,-0.34761548042297002,-0.33336925506592002,-0.32026445865630998,-0.30551299452781999,-0.28764304518700001,-0.26982802152634,-0.25311720371245999,-0.23745867609978,-0.22204203903674999,-0.21126471459866,-0.20751999318600001,-0.20783114433288999,-0.21148276329040999,-0.21807774901390001,-0.22738826274872001,-0.23908324539660999,-0.25332072377205,-0.26861721277237,-0.28459423780441001,-0.30024936795235002,-0.31518521904945002,-0.32890132069588002,-0.34089267253875999,-0.35208350419998002,-0.36318644881248002,-0.37251111865044001,-0.38035026192665,-0.38276883959769997,-0.37672251462936002,-0.36804977059364002,-0.35916572809219,-0.34830725193023998,-0.33564645051955999,-0.31912159919739003,-0.29755976796150002,-0.27215743064879999,-0.24326522648335,-0.21073193848133001,-0.17522968351841001,-0.13378036022185999,-0.082637041807175002,-0.03253661096096,0.010648027062416,0.054081257432699002,0.099096693098545005,0.14914126694202001,0.20976528525352001,0.26546019315719999,0.30856990814209001,0.34572944045067,0.37851965427398998,0.40677025914192,0.43124595284461997,0.44980794191360002,0.46209564805031,0.46608930826187001,0.46078443527222002,0.44594705104827997,0.41861447691916998,0.38988757133483998,0.36850601434708002,0.33773851394652998,0.29038274288177002,0.23011422157288,0.1487620472908,0.081156052649020996,0.048677604645491,0.025769138708711,0.0035867467522620999,-0.014276036061346999,-0.029227301478386002,-0.035868506878614002,-0.030284196138382,-0.018827958032489,-0.0039725638926028997,0.014981139451265,0.038064505904912997,0.064263463020324998,0.089118495583534005,0.12881244719028001,0.19614073634147999,0.26849606633186002,0.34045162796973999,0.39915752410888999,0.43356174230576,0.45742231607437001,0.47644311189651001,0.48622879385947998,0.48656380176544001,0.47436788678169001,0.44977319240570002,0.40557798743248002,0.33150929212570002,0.25372147560120001,0.18361617624759999,0.12067370116711,0.070744819939137005,0.019363818690181001,-0.041912626475095999,-0.10438460111618,-0.16449138522147999,-0.22549644112587,-0.28536373376846003,-0.35621777176857,-0.45774132013321001,-0.53616678714751997,-0.56343823671340998,-0.55522161722183005,-0.51879972219466997,-0.43339958786964,-0.26677915453911,-0.10749703645706001,-0.0057126060128212001,0.076723203063011003,0.14687982201576,0.21403549611568001,0.29376369714737,0.35125270485878002,0.36479026079178001,0.35857811570168002,0.34118175506592002,0.31155666708946,0.26649942994117998,0.22345533967018,0.19333678483962999,0.16834592819214,0.14681145548819999,0.12825775146484,0.11804769933224001,0.093273267149924996,0.038373161107301997,-0.031410761177539999,-0.11074760556221,-0.20119960606098,-0.31157544255257003,-0.40715417265892001,-0.46204051375388999,-0.50761938095092995,-0.55861157178878995,-0.60460484027863004,-0.65447723865509,-0.66504722833633001,-0.60027551651000999,-0.51014029979705999,-0.41461476683616999,-0.31501054763794001,-0.20779728889464999,-0.12634402513504001,-0.097888581454754001,-0.090060941874980996,-0.091044932603836004,-0.098354116082190995,-0.10979575663805,-0.11783484369515999,-0.11422473937273001,-0.11119096726178999,-0.11444910615683,-0.12234926223754999,-0.13426847755908999,-0.15386141836643,-0.18397080898285001,-0.22165885567665,-0.26805162429809998,-0.31507524847983998,-0.35839763283729997,-0.3970975279808,-0.42835786938666998,-0.45679742097854997,-0.49008584022522,-0.50804841518402,-0.49962490797043002,-0.46696206927299,-0.40227445960045,-0.32881462574004999,-0.25517868995666998,-0.19510340690613001,-0.16140842437743999,-0.14589208364487,-0.14931650459765999,-0.16195419430732999,-0.18382194638252,-0.19374838471413,-0.17461015284060999,-0.14038327336310999,-0.091935381293296994,-0.042478214949369,0.0037851855158805999,0.031320996582507997,0.023676227778195998,0.00080205127596855001,-0.0297343544662,-0.064267329871654996,-0.10329185426235001,-0.13006414473057001,-0.1292400509119,-0.11763296276331001,-0.10269115865231,-0.082767590880393996,-0.052650354802607997,-0.033611539751290997,-0.045121423900127001,-0.062646843492984994,-0.075239285826683003,-0.082447774708270999,-0.090476915240288003,-0.066667161881923995,0.024995908141135999,0.12809960544109,0.21247962117194999,0.28534984588623002,0.35807383060455,0.38075008988379999,0.29598540067673001,0.19798284769058,0.14098744094372001,0.10464242100715999,0.082703784108161996,0.097565427422522999,0.18098343908787001,0.26977825164795,0.32535699009895003,0.36137747764587003,0.38338723778724998,0.36987861990929,0.28808531165123002,0.20515426993370001,0.16419216990471,0.14631476998328999,0.14779576659203,0.17521865665913,0.24502933025359999,0.31320023536682001,0.34908825159072998,0.36746108531951999,0.37202310562134,0.35792014002799999,0.31451919674873002,0.26975339651107999,0.24437882006167999,0.22522303462029,0.20773306488991,0.19431500136852001,0.18758411705493999,0.18040835857390999,0.16853715479374001,0.15148440003395,0.12808965146542001,0.097228154540062006,0.052051983773707997,0.011875713244081,-0.0070589082315563999,-0.01856560818851,-0.029066603630781,-0.036077845841646,-0.041568294167518997,-0.038653489202260999,-0.021633511409163,0.0055349669419228996,0.043417710810899998,0.085603997111319996,0.13253423571587,0.16744491457939001,0.17209017276763999,0.16617999970913,0.16040253639221,0.15150701999664001,0.13863277435303001,0.12624628841877,0.11691092699765999,0.11248781532049,0.11770521849394,0.12392550706862999,0.12617559731007,0.12355753034352999,0.11333533376455,0.097730100154877,0.077050194144249004,0.053368918597697997,0.028580982238054001,0.0019686431623995001,-0.027871889993548001,-0.056423116475344003,-0.079299703240394995,-0.10067632794380001,-0.12278012186289,-0.14492891728877999,-0.16724459826946,-0.18965825438499001,-0.21646940708160001,-0.23363259434700001,-0.22884415090084001,-0.21004554629326,-0.18066577613354001,-0.13860829174518999,-0.074215114116669006,-0.016495952382684,0.0094200707972050008,0.018745198845862999,0.015434104017913,0.0028403946198523001,-0.022582866251468998,-0.037053607404231997,-0.016308564692736002,0.020261630415915999,0.063534028828144004,0.11473239958286,0.17875713109970001,0.23463582992554,0.26156070828437999,0.27562201023102001,0.28436100482941001,0.28661301732062999,0.27629017829894997,0.27676710486411998,0.31320840120316001,0.36166709661483998,0.40868052840232999,0.45706540346146002,0.50918710231780995,0.55242258310318004,0.57294547557830999,0.58310014009475997,0.59048283100127996,0.59110909700393999,0.58742171525955,0.56815844774246005,0.51769161224365001,0.45728635787964,0.40098682045937001,0.34718596935272,0.29065462946892001,0.25675442814826999,0.27802228927611999,0.31623074412345997,0.34503641724585998,0.37380203604697998,0.40252447128295998,0.43175947666168002,0.46324035525321999,0.49307000637053999,0.51606196165085005,0.53934007883071999,0.56618458032607999,0.60104662179946999,0.65470129251480003,0.70907491445541004,0.75098228454589999,0.78162902593613004,0.79909884929657005,0.80004590749741,0.77701789140701005,0.74192309379578003,0.70595484972,0.66061961650848,0.60139942169188998,0.52921229600905995,0.43562960624695002,0.34483948349952998,0.28144907951355003,0.22977232933044001,0.18230780959129,0.14156895875931,0.10675030946732,0.080181017518044004,0.067688062787055997,0.057265717536211,0.037621356546879002,0.014719518832862001,-0.011341850273310999,-0.034797064960003003,-0.047321245074272003,-0.057664334774017001,-0.072888039052486003,-0.088534593582153001,-0.10284773260355,-0.11521099507809,-0.11901972442865,-0.13082370162010001,-0.17064310610294001,-0.21935200691223,-0.26790240406990001,-0.30766627192496998,-0.32357230782509,-0.32705849409102999,-0.32287174463272,-0.31532928347588002,-0.30970045924187001,-0.30748948454857,-0.30651715397835,-0.32301050424576,-0.38357201218605003,-0.45405757427215998,-0.50778466463089,-0.54997354745865001,-0.65574288368224998,-0.58868503570556996,-0.62328523397446001,-0.62198722362518,-0.61542642116546997,-0.59891772270203003,-0.57329237461089999,-0.53362476825714,-0.49243670701981002,-0.46306717395781999,-0.43855565786362,-0.41580384969710998,-0.39639645814896002,-0.38046669960022,-0.36930680274963001,-0.36495947837830001,-0.36542555689812001,-0.37009257078170998,-0.37673395872116,-0.38184240460396002,-0.38836508989334001,-0.39906647801398998,-0.41126596927643,-0.42316731810570002,-0.43462058901786998,-0.44591820240021002,-0.45390093326568998,-0.45472130179405001,-0.45020970702170998,-0.44075956940651001,-0.42697837948799,-0.40836542844772,-0.38869526982307001,-0.37441003322601002,-0.35791128873825001,-0.33236324787139998,-0.30053934454918002,-0.26283562183379999,-0.21980133652687001,-0.17247293889522999,-0.11996442824601999,-0.060966975986958001,0.0024370774626731998,0.077921196818351995,0.13781748712062999,0.14349959790707001,0.12705743312835999,0.11112206429243,0.092572823166846993,0.071698270738125,0.061174310743809003,0.079772546887398002,0.11421422660350999,0.16016036272049,0.20682230591774001,0.24722380936145999,0.26200330257415999,0.21486656367779,0.1403676122427,0.063043117523192999,-0.013170391321181999,-0.077455066144465998,-0.12232315540314,-0.12967851758002999,-0.11560737341642,-0.091539785265923004,-0.058556843549012999,-0.023290045559405999,0.017664272338152001,0.068116761744021995,0.12141050398350001,0.16921214759350001,0.21726694703102001,0.26923432946205,0.32498538494110002,0.38863003253937001,0.45188385248183999,0.50689196586608998,0.55261445045471003,0.58368754386902,0.60351592302321999,0.61481344699859997,0.61563235521316995,0.60750150680542003,0.58237624168395996,0.52778351306914995,0.45339396595955,0.36285713315009999,0.26543408632277998,0.16948440670966999,0.086932212114333995,0.041089083999395003,0.016000293195248001,0.0016821529716253001,-0.0034871967509389002,-0.010845243930817001,-0.0047908136621118,0.036807719618081998,0.093444511294364999,0.14918397367000999,0.20151835680008001,0.24552969634533001,0.26907068490982,0.24679371714591999,0.20192614197730999,0.15448814630508001,0.10231256484985,0.051583305001259003,-0.00087076425552368001,-0.059086199849844,-0.11621847003698001,-0.16502812504768,-0.20588304102421001,-0.24533973634243,-0.25858539342879999,-0.19968785345553999,-0.11516542732715999,-0.051476348191500002,0.0046167150139809002,0.052634976804256002,0.090456567704677998,0.11404690146446,0.12633904814720001,0.13142047822475,0.12412363290787,0.10562491416931,0.058532007038593001,-0.057325400412082998,-0.19295275211334001,-0.29245880246161998,-0.37603026628494002,-0.44782140851021002,-0.5083339214325,-0.56468498706818004,-0.60364824533463002,-0.60787957906723,-0.58433961868286,-0.53928053379059004,-0.46198642253875999,-0.32241547107696999,-0.17000281810760001,-0.068352922797202995,0.0067347288131713997,0.063816621899605006,0.098661929368973,0.10485430061817,0.09345106035471,0.080999955534934998,0.056647222489118999,0.010607250034809,-0.052716832607985001,-0.14241793751717,-0.22827297449112,-0.26327261328696999,-0.27111616730690002,-0.26603254675865001,-0.24638907611370001,-0.21347226202488001,-0.17340543866158001,-0.13519394397736001,-0.099293082952499001,-0.070627212524413993,-0.047796729952097002,-0.031373154371976998,-0.020046951249241999,-0.011091633699834,-0.0074645252898334997,-0.014189643785357,-0.026101082563400001,-0.039001248776913001,-0.049895137548447002,-0.050148420035838998,-0.046531416475773003,-0.047309659421444002,-0.046888850629330001,-0.040891624987125001,-0.028569633141160001,-0.0057971011847257996,0.024294212460518001,0.061644658446311999,0.098895817995070995,0.12474592030048,0.14029788970946999,0.14080913364886999,0.13032877445221,0.11174940317869,0.087920889258384996,0.065251834690570998,0.041352193802595,0.015370678156614,-0.01260643824935,-0.046652041375636999,-0.076669365167618006,-0.086765632033348,-0.083123922348022003,-0.06878350675106,-0.042352128773928001,0.0050276182591915001,0.052395742386579999,0.065536841750145,0.059837970882654003,0.043525397777556998,0.017984051257372,-0.012485126033425,-0.044285088777542003,-0.068395823240279999,-0.088749587535858002,-0.10907038301229,-0.12528844177723,-0.13359339535236001,-0.13152919709682001,-0.11087843775749,-0.078532785177231001,-0.042880501598119999,-0.00097819417715073,0.057706706225871998,0.10852105915546,0.10530694574118001,0.077594816684722998,0.05508666485548,0.030136071145535001,0.0089042261242867002,-0.022128239274025002,-0.090714976191520996,-0.17449966073036,-0.24719174206257,-0.31508028507232999,-0.38230502605437999,-0.43439066410065003,-0.44104930758476002,-0.42360335588455,-0.40541291236876997,-0.38140317797661,-0.35133001208304998,-0.32126420736312999,-0.30426341295241999,-0.29266363382339,-0.27877900004387002,-0.2648121714592,-0.25213423371315002,-0.23780983686446999,-0.21518623828888001,-0.19011941552162001,-0.17183154821395999,-0.15431648492812999,-0.13240058720112,-0.10410277545452,-0.058625210076570997,-0.0086747780442237993,0.026529420167207999,0.053217772394419001,0.073829457163810994,0.086836770176887998,0.090521030128002,0.085258163511752999,0.069983467459678997,0.047000043094157999,0.020757559686899001,-0.011088244616985,-0.053438067436217998,-0.099135264754295002,-0.13902893662453,-0.17028915882111001,-0.18160125613212999,-0.17800714075565,-0.15984937548636999,-0.13511081039906001,-0.12227960675955001,-0.11109019070864,-0.089663386344910001,-0.063608944416046004,-0.036240644752979001,-0.010506153106689,0.0021763993427156999,0.013038253411650999,0.040549457073212003,0.075943149626254994,0.11440469324589,0.15014159679413,0.16553302109241,0.17232425510883001,0.18627806007861999,0.20087823271751001,0.21128652989864,0.21829035878181,0.21971066296100999,0.21888986229897001,0.22221685945988001,0.22667261958122001,0.2298201918602,0.23136095702647999,0.22982163727283,0.22462250292301,0.21262353658676,0.19701310992241,0.18243227899075001,0.16854342818260001,0.15929412841797,0.14905363321303999,0.124311812222,0.096373297274113007,0.082360535860062006,0.077400028705596993,0.080119505524634996,0.091287866234778997,0.11532285809517,0.14381612837315,0.16108053922653001,0.17071761190890999,0.17489047348499001,0.16679395735263999,0.12601336836815,0.071687869727612,0.035976868122816003,0.0080508515238762006,-0.017164967954159002,-0.040799282491206998,-0.070581704378127996,-0.099113978445529993,-0.11252000927925,-0.11784769594669001,-0.12232778221369001,-0.12597601115703999,-0.13366010785103,-0.14235411584377,-0.14695711433886999,-0.15090054273605,-0.15850633382797,-0.17004495859145999,-0.19317319989203999,-0.21631306409835999,-0.21386471390723999,-0.19922657310962999,-0.18861815333366,-0.17847216129303001,-0.16979712247848999,-0.16186411678790999,-0.15322837233542999,-0.14514401555060999,-0.13974910974502999,-0.13647086918354001,-0.13558863103390001,-0.13618263602257,-0.13562180101870999,-0.13586489856243,-0.14049531519413,-0.14770878851413999,-0.15625452995299999,-0.16438072919846,-0.16719773411750999,-0.16591198742390001,-0.15978616476058999,-0.15064033865929,-0.14238905906676999,-0.13410696387290999,-0.12685485184192999,-0.11825594305992,-0.10192833840847,-0.081943407654762004,-0.064122319221496998,-0.047931373119353998,-0.036647051572800002,-0.026961175724863999,-0.012293090112507,0.0050111170858145003,0.022786714136600002,0.041906420141458997,0.064136408269405004,0.087423764169216003,0.10806214809417999,0.12611475586890999,0.14023025333881001,0.14940814673901001,0.14818851649761,0.14208596944808999,0.14327354729176001,0.1460085362196,0.14246366918087,0.13521222770214,0.12484017014503,0.11411689221859,0.11189389973879001,0.11320310086012,0.11005776375532,0.10519579797983,0.099614426493645006,0.095889203250408006,0.10269161313772,0.11516201496124,0.12559053301810999,0.13615027070044999,0.14757458865643,0.1605489552021,0.18114195764065,0.20030805468558999,0.19506770372391,0.17588891088962999,0.15599253773689001,0.13404755294323001,0.11592189967631999,0.097026020288467005,0.067073486745357999,0.031577423214911998,-0.0015534963458775999,-0.032546900212764997,-0.055665452033281,-0.075413718819618003,-0.10154233872890001,-0.12983047962189001,-0.15439628064631999,-0.17696747183799999,-0.19837547838687999,-0.21926142275332999,-0.242686226964,-0.26634687185286998,-0.28553482890129001,-0.30168032646178999,-0.31811940670013,-0.32987514138222002,-0.32174444198607999,-0.30332991480826998,-0.29253405332565002,-0.28501787781714999,-0.28006827831268,-0.27656728029250999,-0.27045091986656,-0.26383459568023998,-0.26106327772141003,-0.25961196422576999,-0.25626409053802002,-0.24911305308341999,-0.22691106796265001,-0.19929008185863001,-0.18788923323154,-0.18652296066283999,-0.19063350558281,-0.20109973847866,-0.21905340254307001,-0.24207137525082001,-0.26491898298263999,-0.28642383217812001,-0.30061689019202997,-0.30733981728554,-0.30005821585655001,-0.28435876965522999,-0.27331200242043002,-0.26298597455025002,-0.25043407082558,-0.23506467044352999,-0.20957428216933999,-0.18260169029236001,-0.17680580914020999,-0.18516758084297,-0.20152743160725001,-0.22557151317596,-0.25623694062232999,-0.28725543618201999,-0.30017849802970997,-0.29604372382164001,-0.26322853565215998,-0.20970648527145,-0.14890195429325001,-0.084601998329163,-0.039759926497935999,-0.0046436563134193004,0.037062633782624997,0.080546937882900002,0.12186782062054,0.16000272333622001,0.18920014798640999,0.21100637316703999,0.22577358782290999,0.23486487567424999,0.24236507713795,0.24817788600922,0.25527566671370999,0.26191541552544001,0.26387146115303001,0.26307719945907998,0.26269176602364003,0.26278841495513999,0.26719743013382002,0.27229249477386003,0.26678150892258001,0.25646778941154003,0.25331521034241,0.254538834095,0.25995951890945002,0.2672107219696,0.26771870255469998,0.26457238197326999,0.26243126392365002,0.26039004325866999,0.25992718338965998,0.25796714425086997,0.24166023731232,0.21975414454937001,0.21498712897301001,0.22011390328406999,0.22633136808872001,0.23359605669975,0.23565058410167999,0.23481959104538,0.23520167171955,0.23531150817870999,0.23300015926361001,0.22805657982826,0.21742740273475999,0.20335498452187001,0.19160243868828,0.18104596436024001,0.17193558812140999,0.16354906558990001,0.15149915218352999,0.14024323225020999,0.14399452507495999,0.15772369503975001,0.17302498221397,0.19143658876419001,0.21721847355366,0.24244932830334001,0.23783645033836001,0.21488949656487,0.19552856683731001,0.17564523220062001,0.15354080498219,0.13135394454002,0.11653897166252,0.10700973123312001,0.10011296719313,0.096388377249241,0.096761479973793002,0.10004848241806,0.10165792703628999,0.1037470921874,0.1129522100091,0.12521013617516,0.13293212652205999,0.13216142356395999,0.097097724676131994,0.042093090713024001,0.0038552526384592,-0.024475337937474001,-0.045168519020080997,-0.056419044733047,-0.050663128495216002,-0.031773190945386998,-0.0082183014601469005,0.019445294514297998,0.044441059231758,0.066210828721522993,0.076214440166950004,0.078459255397320002,0.084256485104561005,0.088866919279098996,0.081646583974361003,0.063928902149199995,0.030468298122287001,-0.012382265180349,-0.041093342006206998,-0.063203535974026004,-0.092937245965003995,-0.12723271548748,-0.16494175791740001,-0.20351189374924,-0.23129008710384,-0.25158599019050998,-0.26931932568549999,-0.2842156291008,-0.29908925294875999,-0.31229653954505998,-0.31864070892334001,-0.31982734799384999,-0.31889587640762002,-0.31598675251007002,-0.31357559561728998,-0.31146836280822998,-0.31030237674713002,-0.31054180860518998,-0.31522843241692,-0.32293301820754999,-0.32975026965141002,-0.33638879656791998,-0.34406810998916998,-0.35115933418273998,-0.35038456320763001,-0.34466123580933,-0.34079477190971003,-0.33855822682380998,-0.34171792864799,-0.34956815838813998,-0.36300596594809997,-0.38014745712280001,-0.39362400770187,-0.40442630648612998,-0.41433390974998002,-0.41894468665123002,-0.39566066861152999,-0.35461139678955,-0.32467964291572998,-0.30116099119186002,-0.28613594174384999,-0.27493521571159002,-0.24568960070609999,-0.20646607875824,-0.17863413691520999,-0.15791472792625,-0.14166314899921001,-0.12744954228401001,-0.10024558007716999,-0.066139087080956005,-0.043177198618649999,-0.027092751115561,-0.012357222847641,0.0023862384259701001,0.029478771612048,0.063407830893993003,0.086330570280551994,0.10266382992268,0.11997041106224,0.13789094984531,0.16128700971602999,0.18725338578223999,0.20453059673308999,0.21649202704430001,0.23105910420417999,0.24723802506924,0.26685410737991,0.28805083036423001,0.30259555578232,0.31280940771103,0.32403275370598,0.33545583486557001,0.34681928157806002,0.35817158222197998,0.37009876966476002,0.38193303346634,0.39089819788933,0.39723384380340998,0.39868393540382002,0.39759153127669999,0.40547505021094998,0.41859033703803999,0.42609983682632002,0.43007987737656,0.43350899219513001,0.43575632572174,0.43623232841491999,0.4340181350708,0.42341411113739003,0.40604171156883001,0.38450756669044001,0.36060115695,0.34835261106491,0.34180933237076,0.31805127859116,0.28327783942223,0.25212204456329002,0.22447419166565,0.21273612976073999,0.21162506937980999,0.20135623216629001,0.18624675273895,0.17491276562214,0.16636668145656999,0.16256891191006001,0.16138869524002,0.15232358872890001,0.13753655552864,0.1206679046154,0.10173161327839,0.083804972469807004,0.065751828253269001,0.042791560292243999,0.016730327159166,-0.0055848797783256002,-0.025380123406649,-0.044690612703561998,-0.063001304864883007,-0.078551165759563002,-0.091808147728442993,-0.10416107624769,-0.11543043702840999,-0.12576825916767001,-0.134925827384,-0.14180289208888999,-0.14629438519478,-0.14671185612679,-0.14357216656207999,-0.13898006081580999,-0.1321584135294,-0.12017017602921,-0.10324940085411,-0.079909920692444,-0.051207397133112002,-0.021993106231093001,0.0080033615231513994,0.038399156183003998,0.067088186740874994,0.078755497932433999,0.077822275459765999,0.078957475721836007,0.081088803708552995,0.090774990618228996,0.10437531024218,0.10282372683287,0.090856298804283003,0.083229444921016998,0.078569352626800995,0.080397844314575001,0.086705580353737002,0.086690247058868006,0.083149828016758007,0.086051367223262995,0.093787804245949,0.10444942116736999,0.11703511327505001,0.1228132545948,0.12405268847942,0.12902264297009,0.13637696206569999,0.14463943243027,0.15254180133343001,0.14898362755774999,0.13733789324760001,0.13182023167609999,0.13032223284245001,0.13049687445163999,0.13140118122100999,0.12367811799049,0.11020773649215999,0.103803999722,0.10239488631487,0.10170685499907001,0.10199858248234001,0.10208047181368,0.10211566835642,0.10198697447777,0.10191135108471,0.10315878689289,0.10573407262564,0.11148921400309,0.11930342763662,0.12307392805815,0.12296289205551,0.11525362730025999,0.10039512813091001,0.077257513999939006,0.047300830483437001,0.019904419779777999,-0.0055491738021374,-0.025760557502508,-0.041462168097495998,-0.055271130055189001,-0.066741839051247004,-0.075429417192935999,-0.080338925123214999,-0.072447687387466,-0.053959872573614003,-0.033044595271349002,-0.010416116565466,-0.00034043192863463998,0.0012401305139064999,0.015499724075198,0.038802001625299003,0.060487974435090998,0.080254137516022006,0.086004786193371,0.080809094011784002,0.079535402357578,0.080133616924286,0.078069962561130996,0.073426127433776994,0.062430724501609997,0.046791266649961,0.038159087300301001,0.034531053155660997,0.028686104342341,0.021347839385271,0.012926291674376001,0.0035436982288957002,-0.0058284290134907003,-0.015152510255575,-0.022996136918663999,-0.029798567295074001,-0.038280144333839,-0.048021689057349999,-0.057427406311034997,-0.066796168684958995,-0.07769463956356,-0.089820191264152999,-0.10172864794731,-0.1135586053133,-0.12554717063904,-0.13753420114517001,-0.14806063473225001,-0.15740433335303999,-0.16657376289368001,-0.17577801644801999,-0.1886629909277,-0.20400916039944,-0.21279788017272999,-0.21656800806522,-0.22199995815754001,-0.22882673144341001,-0.24093137681484,-0.25688686966896002,-0.26573094725608998,-0.26919567584991,-0.27434808015822998,-0.28114041686058,-0.29623818397522,-0.31759417057036998,-0.32946357131004,-0.33451458811759999,-0.34589171409607,-0.36286723613739003,-0.39156365394592002,-0.42882379889487998,-0.44553536176682002,-0.44650354981422002,-0.45710262656211997,-0.47485879063606001,-0.49798795580864003,-0.52350598573685003,-0.51614522933960005,-0.48170161247253002,-0.45158475637436002,-0.42323553562164001,-0.394925147295,-0.36643555760384,-0.33472549915313998,-0.30053240060806002,-0.26948419213295,-0.24102494120598,-0.21449121832848,-0.18926967680453999,-0.15716120600700001,-0.11959923803806,-0.086542420089244995,-0.056605495512485997,-0.023001488298178,0.014504753053188,0.066299200057982996,0.12985000014305001,0.18381968140602001,0.23044309020042,0.27779173851013,0.32565838098526001,0.37893894314766002,0.43620955944061002,0.48406919836998002,0.52395457029342996,0.56223595142365002,0.59839498996734997,0.63077157735824996,0.65955799818038996,0.68600577116012995,0.7100413441658,0.73150056600571001,0.75058615207671997,0.76998096704482999,0.78941297531127996,0.80712258815765003,0.82362383604050005,0.84482109546660999,0.87000024318695002,0.89494144916534002,0.9197108745575,0.94330018758774004,0.96468460559845004,0.96724009513855003,0.95289224386214999,0.93230223655700994,0.90590649843215998,0.89116853475571001,0.88524514436722002,0.86131715774536,0.82220107316971003,0.78533732891082997,0.75029224157332997,0.72829604148865001,0.71640872955321999,0.67823547124863004,0.61776596307755005,0.56330466270446999,0.51378697156905995,0.48006808757781999,0.45905074477196001,0.40939161181450001,0.33565434813499001,0.27408733963965998,0.22293967008591001,0.18859967589377999,0.16801945865154,0.11404222995042999,0.031801357865334001,-0.034100145101546998,-0.086300246417522,-0.12967221438884999,-0.16537827253342,-0.2184676527977,-0.28610000014304998,-0.34033054113388,-0.38291555643081998,-0.42046216130257003,-0.45317438244820002,-0.49039182066916998,-0.53105878829955999,-0.56387645006179998,-0.58963710069655995,-0.61341738700866999,-0.63506317138671997,-0.65636295080185003,-0.67684686183928999,-0.68895524740219005,-0.69313758611678999,-0.69182378053664995,-0.68476432561874001,-0.66698801517487005,-0.63955879211426003,-0.62100231647491,-0.61012309789658004,-0.59911096096038996,-0.58794271945953003,-0.56839334964751997,-0.54155975580214999,-0.52536904811858998,-0.51829963922500999,-0.50194597244262995,-0.47711285948753002,-0.44416585564612998,-0.40405344963074002,-0.38078758120536998,-0.37241706252098,-0.35382404923438998,-0.32614406943321,-0.29327186942101002,-0.25595563650130998,-0.23746645450591999,-0.23606692254542999,-0.22868011891841999,-0.21618402004241999,-0.20081101357937001,-0.18278731405734999,-0.17008256912231001,-0.16200056672096,-0.14641803503035999,-0.12384568154812001,-0.097449451684952004,-0.067299276590346999,-0.038687653839587999,-0.011091124266385999,0.027076380327344,0.075120076537132,0.12262925505638,0.16974194347857999,0.21079072356223999,0.24622322618961001,0.28533443808556003,0.32765802741050998,0.36627396941184998,0.40123474597931003,0.42781037092209001,0.44627591967583002,0.46185210347175998,0.47432640194893,0.48043802380562001,0.48026591539383001,0.47414490580558999,0.46203631162643,0.44176000356674,0.41357162594794999,0.38605764508246998,0.35901930928230003,0.33292448520660001,0.30755198001862,0.27215826511383001,0.22741210460663,0.19476309418678001,0.17367327213287001,0.15970546007156,0.15259033441544001,0.13482265174388999,0.10688456892967001,0.076920449733734006,0.044830985367298001,0.012529246509075,-0.020156620070337999,-0.062350429594516997,-0.11366450786590999,-0.15809904038906,-0.19599513709544999,-0.23472309112549,-0.27416270971298001,-0.31342771649361001,-0.35231950879097002,-0.37406754493713001,-0.37907493114471003,-0.38271260261536,-0.38481858372687999,-0.38646817207335998,-0.38756075501442,-0.37980690598487998,-0.36340489983558999,-0.35061722993851002,-0.34130263328552002,-0.33242788910866,-0.32394525408745001,-0.30642682313919001,-0.28004026412964,-0.25816836953163003,-0.24072995781897999,-0.22930678725243001,-0.22382766008377,-0.21314769983292001,-0.19735291600227001,-0.18363605439663,-0.17195814847946,-0.15918026864529,-0.14530017971991999,-0.12560550868511,-0.10012216120957999,-0.076404534280300002,-0.054440427571534999,-0.033772852271795002,-0.014401599764824,0.0048053502105175998,0.023846860975027001,0.044126413762568997,0.065641105175018005,0.091074533760547999,0.1204326748848,0.15381047129631001,0.19122761487960999,0.22691744565964,0.26085188984870999,0.29508098959923001,0.32962617278098999,0.36195883154869002,0.39209121465683,0.41600313782692,0.43368589878081998,0.44268584251403997,0.44299235939979997,0.43163603544235002,0.40839508175849998,0.39749765396117998,0.39927965402603,0.40012264251709001,0.39988985657692,0.40052512288094,0.40197694301605003,0.41096729040146002,0.42774745821952997,0.43740224838257002,0.43970820307732,0.43780532479286,0.43162104487419001,0.42954218387603998,0.43190684914589,0.42262119054794001,0.40125831961632002,0.38052546977996998,0.36055657267570002,0.34479942917824002,0.33344742655754001,0.31930765509605002,0.30223014950751997,0.28378519415855002,0.26396390795708002,0.24392136931419001,0.22359950840473,0.20789314806461001,0.19708749651908999,0.18184714019299,0.16190628707408999,0.14177629351616,0.12179823964834,0.088843122124672005,0.042195096611976998,0.00031290575861930999,-0.036410406231880001,-0.067171350121497997,-0.091945715248584997,-0.10876105725765001,-0.11734325438738,-0.12638811767100999,-0.13613939285278001,-0.14643181860446999,-0.15747444331645999,-0.16112652420998,-0.15678544342518,-0.15817494690417999,-0.16578543186187999,-0.1767945587635,-0.19156868755817,-0.19410586357116999,-0.18313011527060999,-0.18510752916336001,-0.20121267437935,-0.21987789869308,-0.24100463092327001,-0.25776752829552002,-0.26978522539138999,-0.28122597932816001,-0.29241734743117997,-0.29735973477364003,-0.29593521356583002,-0.28393504023552002,-0.26030886173248002,-0.25120440125464999,-0.25818014144897,-0.26464396715164001,-0.27001273632049999,-0.27542200684547002,-0.28096622228621998,-0.28384259343147,-0.28387272357941001,-0.28286764025687999,-0.28095898032187999,-0.27649742364883001,-0.26946595311165,-0.25850531458854997,-0.24343332648277,-0.22694583237171001,-0.20903737843037001,-0.19227388501167,-0.17660892009734999,-0.16614648699760001,-0.16110850870609,-0.16127316653727999,-0.16683419048786,-0.17367058992386,-0.18164469301701,-0.18913042545319,-0.19580551981926,-0.20702944695950001,-0.22336769104004001,-0.23820553719997001,-0.25126758217812001,-0.26124483346938998,-0.26761475205420998,-0.27995580434799,-0.29929840564728,-0.31485185027121998,-0.32626274228096003,-0.32884052395821001,-0.32137286663054998,-0.32298690080643,-0.33561438322067,-0.3417886197567,-0.34079399704933,-0.32795903086661998,-0.30171769857406999,-0.28606367111205999,-0.28320276737213002,-0.27716100215911998,-0.26697000861168002,-0.25489372014999001,-0.24042002856731001,-0.2352446615696,-0.24131947755814001,-0.23617239296435999,-0.21810196340084001,-0.1929167509079,-0.16002801060676999,-0.13524118065834001,-0.12098281830549,-0.092531390488147999,-0.047616954892874,0.0014625564217566999,0.054762996733188997,0.10008374601603,0.13629868626594999,0.16736088693142001,0.19336912035942,0.21555601060390001,0.23395080864428999,0.24936679005623,0.26148661971092002,0.27665999531745999,0.29559463262558,0.31438639760017001,0.33285474777222002,0.34899881482124001,0.36136656999588002,0.39100971817969998,0.44099855422973999,0.48791548609733998,0.53001409769058005,0.57018220424652,0.60909479856491,0.63697654008865001,0.65240842103957997,0.66550934314728005,0.67725980281830001,0.68478810787201005,0.68921166658401001,0.67018657922744995,0.62344425916671997,0.58674299716948997,0.56354689598082996,0.54642683267592995,0.53615939617157005,0.51668936014175004,0.48529252409934998,0.46161115169525002,0.44831067323684998,0.43053674697875999,0.40846157073974998,0.36201331019402,0.28537741303443998,0.23297829926013999,0.21137490868568001,0.19393397867680001,0.17912025749683,0.16190440952778001,0.14037019014359001,0.13164998590946,0.13821263611317,0.14750692248344,0.15891443192959001,0.16785542666912001,0.17378503084183,0.17719574272633001,0.17843717336654999,0.1731823682785,0.16124865412712,0.13839529454707999,0.10196449607610999,0.079931288957596006,0.076469488441943997,0.072816058993339997,0.067273370921611994,0.062413025647401997,0.059139605611562999,0.047393485903739999,0.025679469108582001,-4.9443915486335998e-05,-0.029383685439824999,-0.061672188341618001,-0.097170002758503002,-0.13136953115462999,-0.16350048780441001,-0.19715321063995001,-0.23294280469417999,-0.26797577738762002,-0.30280745029449002,-0.32796970009804,-0.3420507311821,-0.34907251596451,-0.34881818294525002,-0.34717983007431003,-0.34489691257477001,-0.34165006875991999,-0.33833315968513,-0.32485795021057001,-0.29871737957000999,-0.27499660849571,-0.25496098399161998,-0.24253216385841,-0.24013401567935999,-0.22781674563884999,-0.20216217637062001,-0.17614752054214,-0.15066154301167001,-0.13029196858406,-0.11775690317154,-0.090136766433716001,-0.041820760816335997,-0.0046658087521790998,0.016917195171118001,0.032679192721843997,0.042548514902591997,0.055645104497671002,0.074638605117798004,0.084262646734714994,0.082531064748763996,0.071826182305813002,0.051109086722136002,0.031351335346698997,0.013401467353106,0.0025516415480523998,0.00034565059468149998,-0.00063531973864883,-0.0017773484578355999,0.0033755004405974999,0.017686204984784001,0.019773896783590001,0.0056692529469728001,-0.011541087180376001,-0.030198868364096,-0.053735282272099998,-0.083673328161239999,-0.10804027318954,-0.12480954825878,-0.13869884610176,-0.15003295242785999,-0.16075578331946999,-0.17325346171855999,-0.16713246703147999,-0.13704876601696001,-0.10768134891987,-0.082302734255791002,-0.058040417730808001,-0.034309029579163,-0.016216266900301,-0.0045609753578900996,0.0016205350402742999,0.0023831953294575002,-0.0027637199964374,-0.014922018162906,-0.024431187659502002,-0.028947964310646002,-0.037751644849777,-0.052996646612883003,-0.066180624067782995,-0.077247649431228999,-0.076457679271697998,-0.059929393231869001,-0.048361960798502003,-0.045149561017751999,-0.045244686305523002,-0.048643387854099003,-0.051747754216194,-0.053147915750742,-0.060432430356741,-0.075886309146881006,-0.089424178004264998,-0.10074005275965001,-0.10011255741119,-0.083762951195240007,-0.070317476987838995,-0.064050860702991,-0.051200889050960999,-0.030380653217435001,0.0026661399751902,0.052026063203811999,0.090724065899848993,0.1130995452404,0.13233789801598,0.14997060596942999,0.16623052954674,0.18196891248225999,0.19215324521065,0.19593909382819999,0.19390541315078999,0.18583434820174999,0.17294259369373,0.15401534736156,0.14065003395080999,0.13597831130028001,0.13016059994698001,0.1216883584857,0.11145213991404,0.098379515111446006,0.091412171721458005,0.094469472765923004,0.087874889373779005,0.066595271229743999,0.045245490968226998,0.024105193093418999,0.017509505152701998,0.030769465491175998,0.043441936373711,0.051472533494234002,0.062084984034300003,0.076183676719665999,0.093401253223418995,0.11461666226387,0.13355065882205999,0.14908896386623,0.16148361563683,0.17057466506957999,0.17715165019035001,0.18246990442276001,0.17739529907703,0.15772360563278001,0.14291663467884,0.13700550794600999,0.13462947309017001,0.13678285479546001,0.13188628852366999,0.11599083989859001,0.10225085169077,0.093185171484946996,0.086017712950705996,0.081636615097522999,0.071506440639496002,0.052038423717021998,0.037672769278287999,0.031579382717609003,0.028808703646063999,0.029421888291836,0.028542971238493999,0.024091223254799999,0.023780532181263001,0.029102785512804999,0.038882810622454002,0.053287453949451002,0.070924237370491,0.091772750020026994,0.11406730115414,0.13733573257923001,0.16224552690982999,0.18889072537422,0.21778258681297,0.25151267647742998,0.27251636981964,0.27503874897956998,0.27505329251289001,0.27550852298737,0.27431887388228998,0.27071639895438998,0.26956486701964999,0.27165552973746998,0.27821895480156,0.28994652628898998,0.30535349249839999,0.32663801312446999,0.33686456084250999,0.32972249388695002,0.32409563660621998,0.32369530200958002,0.32719194889068998,0.33887597918509998,0.33065804839134,0.29127681255340998,0.25709104537964,0.23712842166424,0.21714721620083,0.19800721108913,0.15990941226482,0.093206174671650002,0.031840279698371998,-0.015540197491646,-0.062478616833687002,-0.11120263487100999,-0.16044874489307001,-0.21280789375305001,-0.25120639801025002,-0.26899123191833002,-0.28508415818214,-0.30340874195098999,-0.32201135158539002,-0.34230175614357,-0.35564175248146002,-0.35840812325478,-0.36158758401871,-0.36776384711266003,-0.37423971295357,-0.38075569272040999,-0.38704067468643,-0.39239037036896002,-0.40055087208748003,-0.41246810555458002,-0.42756682634353999,-0.44664245843887002,-0.46480011940001997,-0.48107469081879001,-0.49455916881561002,-0.50487726926804,-0.51204377412795998,-0.51597183942795,-0.51709353923797996,-0.51666259765625,-0.50742065906525002,-0.48637056350708002,-0.46122592687607,-0.43228578567504999,-0.40762552618980002,-0.39247292280196999,-0.36787596344947998,-0.32691702246665999,-0.28577637672424,-0.24664062261580999,-0.21616017818451,-0.19944889843464,-0.17825262248515999,-0.14637288451194999,-0.11615521460772001,-0.089297667145728996,-0.070546500384808003,-0.066276103258133004,-0.047363232821226002,-0.0020890608429909,0.041586078703403001,0.078108415007590998,0.10532806068658999,0.11810553818941,0.13850295543671001,0.17594644427299,0.20633211731911,0.22299523651600001,0.23381499946116999,0.23736378550529,0.24904577434062999,0.27669385075568997,0.29877725243567999,0.30905309319495999,0.31529968976973999,0.31765168905258001,0.32245573401451,0.33267042040825001,0.34199786186218001,0.34952622652054,0.35290509462357,0.35155698657036,0.34402245283126998,0.32913491129875,0.31063374876976002,0.29009103775023998,0.26398074626923002,0.23274390399455999,0.18896263837814001,0.12617121636868001,0.068751648068427998,0.025512803345918999,-0.01794745400548,-0.064210109412669997,-0.11552039533854,-0.17746677994728,-0.22476533055305001,-0.24561661481857,-0.26773622632027,-0.29765829443932001,-0.33585259318352001,-0.38931486010550997,-0.42612621188164002,-0.43298122286796997,-0.43519222736358998,-0.43895247578620999,-0.44142383337021002,-0.44500625133513999,-0.43720585107803001,-0.41159245371818998,-0.38389337062835999,-0.35834434628487,-0.33304288983344998,-0.30914595723152,-0.28078049421309997,-0.24410566687584001,-0.21077314019203,-0.18512916564941001,-0.16043365001678001,-0.13548749685287001,-0.10904943943023999,-0.080099925398827002,-0.050851795822382001,-0.021910279989243001,0.0069693252444267004,0.035105481743812998,0.066172704100609006,0.10332915186882,0.13573537766933,0.15942902863026001,0.17926929891109,0.19593459367752,0.21071992814540999,0.22425399720669001,0.23604598641395999,0.24564130604267001,0.25504016876220997,0.26460057497025002,0.27566739916800997,0.29017180204391002,0.30070197582245001,0.30311545729637002,0.30741003155708002,0.31658938527107,0.32912644743919001,0.34602513909339999,0.36244758963585,0.37884095311165,0.38540926575661,0.37744852900504999,0.36186057329178001,0.33897510170937001,0.31510421633719998,0.2938314974308,0.26849403977393999,0.23686382174491999,0.20142085850239,0.16161407530308,0.12273096293211,0.088498763740063005,0.049059107899665999,-0.00081273540854453997,-0.049536779522896,-0.094640403985977006,-0.13217163085938,-0.15657010674477001,-0.18620853126049,-0.23009189963341001,-0.27184656262397999,-0.3071191906929,-0.33579182624817,-0.35440641641616999,-0.37598097324370999,-0.40763536095619002,-0.43500357866286998,-0.45364874601364003,-0.46538791060447998,-0.46718496084213001,-0.47325927019119002,-0.49174138903617998,-0.50637197494507002,-0.51211011409759999,-0.51095753908157004,-0.50124579668045,-0.49020031094550998,-0.48122009634972002,-0.46964699029922002,-0.45421528816223,-0.43550369143486001,-0.41353636980057001,-0.38815221190452998,-0.35928958654403997,-0.32689967751503002,-0.29015582799910999,-0.25278809666634,-0.21629969775676999,-0.17956693470478,-0.14120742678642001,-0.10697783529758,-0.079920142889022994,-0.05528224632144,-0.033416368067265001,-0.0064925355836748999,0.031430013477801999,0.066644959151744995,0.092050954699516005,0.12047572433949,0.15580527484417001,0.19781090319156999,0.25131389498710999,0.29687967896460998,0.32310312986374001,0.35062536597251998,0.38626262545585999,0.42748451232910001,0.4803161919117,0.51807075738907005,0.52269983291625999,0.53203111886978005,0.56057798862456998,0.59754890203475997,0.64727538824080999,0.68237555027008001,0.68575608730315996,0.68728870153427002,0.69833534955978005,0.70900690555572998,0.72018957138062001,0.71923911571502996,0.69974029064178001,0.66739356517792003,0.62193745374679998,0.56952953338623002,0.51104521751403997,0.45393061637878002,0.40300521254539001,0.35163822770119002,0.29741159081459001,0.24259637296200001,0.18690624833107,0.13406337797642001,0.089729428291320995,0.035610005259514001,-0.040145140141249001,-0.11553716659546,-0.18375159800053001,-0.242815092206,-0.28668838739394997,-0.33223602175713002,-0.38921868801116999,-0.44217678904532998,-0.48559662699699002,-0.52224028110503995,-0.55191433429717995,-0.57596188783645996,-0.59417569637298995,-0.60985785722732999,-0.62499618530273005,-0.63707810640335005,-0.64331531524658003,-0.65266740322113004,-0.67181766033172996,-0.68704020977019997,-0.69209015369414995,-0.69275206327437999,-0.68895161151885997,-0.68697804212570002,-0.69285857677460005,-0.69307893514633001,-0.68045169115066995,-0.66419982910155995,-0.64537882804871005,-0.63154900074005005,-0.63180965185164994,-0.62339210510253995,-0.59370046854018999,-0.55891084671020996,-0.52369391918181996,-0.48933875560759998,-0.45801597833633001,-0.42712599039077997,-0.39495313167571999,-0.36532375216483998,-0.33867263793945002,-0.31943777203559998,-0.31415987014771002,-0.30475187301635998,-0.28022855520248002,-0.25588056445121998,-0.23733992874622001,-0.22229784727096999,-0.21247044205665999,-0.20099785923958,-0.18333804607390999,-0.16596801578998999,-0.15133282542229001,-0.13856339454651001,-0.13072057068348,-0.11552498489618,-0.083133980631828003,-0.051749054342507997,-0.030315464362502001,-0.010520402342081001,0.0095636164769530001,0.031154148280621002,0.055885463953018001,0.081250399351119995,0.10629500448704,0.13121618330479001,0.15579831600189001,0.18049359321594,0.20560258626937999,0.2306837439537,0.25635296106339001,0.27957528829575001,0.30009296536446001,0.31316095590590998,0.31211552023888001,0.31370258331299,0.32849940657616,0.34293037652969,0.35268077254294999,0.35600832104683,0.34551516175269997,0.34346348047255998,0.36895322799683,0.38594236969947998,0.37715607881545998,0.35270962119102001,0.30771055817603998,0.26735624670982,0.24659670889377999,0.23462758958339999,0.22920829057693001,0.22958217561245001,0.23425656557082999,0.24574007093906,0.27002522349357999,0.28769215941428999,0.28637447953223999,0.27875730395317,0.26723527908325001,0.25836244225501998,0.25800591707229997,0.25921133160590998,0.25832873582839999,0.25989830493927002,0.26530632376670998,0.27576225996017001,0.29730594158173002,0.31040650606155001,0.30049195885657998,0.28738999366759999,0.27927538752556003,0.27435854077339,0.27853977680205999,0.27248680591583002,0.24113389849663,0.20586360991000999,0.17620646953583,0.14846874773502,0.12465263903141,0.097476132214069006,0.060401376336813001,0.024339435622095999,-0.0043261498212814001,-0.031857334077358003,-0.056601308286189998,-0.092786043882369995,-0.15457694232464,-0.21795162558556,-0.27062448859214999,-0.31907624006271001,-0.36163172125816001,-0.40798774361610002,-0.46803322434424999,-0.52442240715027,-0.56757611036301003,-0.60416364669800005,-0.63790339231491,-0.66108196973801003,-0.66540539264678999,-0.66803568601607999,-0.67958551645278997,-0.69111245870589999,-0.70128822326660001,-0.70461422204971003,-0.69380211830139005,-0.68252140283585006,-0.68082410097122004,-0.67554438114166004,-0.66281950473785001,-0.63637214899062999,-0.58118242025375,-0.53505665063857999,-0.52657043933867997,-0.52198415994643999,-0.50690913200377996,-0.48380449414253002,-0.44537928700446999,-0.41114166378974998,-0.39858487248420998,-0.38133946061134,-0.34504306316375999,-0.29798656702041998,-0.2349194586277,-0.18088176846504,-0.15901911258698001,-0.13741259276866999,-0.097530364990234,-0.054545376449822998,-0.011913638561964,0.024807551875710002,0.048082627356052003,0.069333463907242002,0.094957247376441997,0.1213314384222,0.14912664890289001,0.17333756387234001,0.1891832947731,0.20291243493557001,0.21851558983326,0.23184618353844,0.24112139642239,0.24672694504261,0.24938739836216001,0.24581950902939001,0.23145335912703999,0.21550700068473999,0.20244486629962999,0.19375276565551999,0.19657434523105999,0.19308729469776001,0.16694620251656,0.14066530764103,0.12625309824944,0.11936938762665,0.12544642388821001,0.12599039077759,0.10346364974975999,0.080862887203693001,0.070968829095364006,0.067394211888313002,0.073764540255069996,0.073848873376845994,0.051980994641780999,0.027715248987079,0.011983649805188,-0.0010296212276444,-0.0087508093565702005,-0.024092381820083001,-0.061495013535022999,-0.099310904741286996,-0.12320502847433,-0.14418491721153001,-0.16510537266731001,-0.18951562047004999,-0.22532668709754999,-0.25637614727020003,-0.27000689506531,-0.27807956933974998,-0.28321984410286,-0.29353109002112998,-0.32393729686736999,-0.345259308815,-0.33349543809891002,-0.31369268894196001,-0.29864883422852001,-0.28362542390822998,-0.2705717086792,-0.25290766358375999,-0.22301197052002,-0.19252373278141,-0.16906560957432001,-0.14824356138705999,-0.13024163246154999,-0.11061169952154,-0.083819463849067993,-0.057832516729832001,-0.038414172828197,-0.020660879090427998,-0.0024094544351101,0.015882942825555999,0.034548871219157999,0.053310435265302998,0.072513990104197998,0.090633988380432004,0.10797201097012001,0.1200595125556,0.12033864855765999,0.11987449228763999,0.12742853164672999,0.13537018001080001,0.14233964681625,0.14182114601135001,0.12260150909424,0.10435865819454,0.10371941328049,0.10466922074556,0.10108143091202,0.088197417557240004,0.052811611443757997,0.020899372175335999,0.015013704076409,0.014304671436548001,0.0088174827396870006,-0.00077173893805593003,-0.021382151171565,-0.037713155150413999,-0.031778275966644003,-0.02993755415082,-0.05013794079423,-0.084325440227984994,-0.13833239674567999,-0.18909370899200001,-0.21276098489761,-0.23335166275500999,-0.26504230499268,-0.30139267444611001,-0.34656861424446,-0.38357737660407998,-0.39460265636443997,-0.39739108085632002,-0.40224650502205,-0.40524455904960999,-0.40710937976837003,-0.40486165881156999,-0.39311474561691001,-0.38214817643165999,-0.38008746504784002,-0.38257533311844,-0.38964328169822998,-0.39737436175346003,-0.40518805384635997,-0.40471968054771001,-0.38458830118178999,-0.35870146751403997,-0.33436474204062999,-0.31425255537032998,-0.31089079380035001,-0.29820531606674,-0.24875342845917001,-0.19260427355765999,-0.14848291873932001,-0.1109851077199,-0.086865268647670996,-0.057848941534758003,-0.0018459558486938,0.053584840148687002,0.088726431131362998,0.11296182870865,0.12390451133251,0.13571554422379001,0.16681115329266,0.1949802339077,0.20371520519257,0.20243062078953,0.19222229719162001,0.17951744794846,0.17279979586600999,0.16392268240451999,0.14689357578754,0.12636108696460999,0.10487802326678999,0.081453375518322005,0.054902233183383997,0.028637548908591,0.0048506110906601004,-0.015055946074426001,-0.029546801000834001,-0.037451848387717999,-0.035530917346478001,-0.029160043224692001,-0.022646557539701,-0.014404934830964,-0.0063157649710773997,0.0077291382476686998,0.038589134812355,0.067862957715988007,0.078212007880211001,0.082259938120841994,0.086816735565661995,0.089539162814617004,0.089486777782440005,0.089539013803004996,0.092754952609539004,0.096928946673870003,0.1009471192956,0.10495718568563001,0.10960627347231,0.11225007474422,0.11184004694223,0.10469784587622,0.085516087710857003,0.059016443789005002,0.024111468344927001,-0.0075398376211524001,-0.019685544073582001,-0.029498102143407,-0.051358714699744998,-0.075013875961304002,-0.098474398255347997,-0.11226598918437999,-0.10026936978102,-0.082049369812011996,-0.074761502444743999,-0.067378118634223993,-0.055562350898980997,-0.037196964025496999,-0.0028678886592388001,0.029419057071208999,0.039315897971391997,0.044775545597076,0.057018049061298003,0.074878744781016998,0.10643304884434,0.13504469394683999,0.14106188714504,0.14236663281917999,0.15193463861942,0.16433960199356001,0.23189204931259,0.19442926347256001,0.17981173098087,0.18516130745411,0.19425779581069999,0.21015909314156,0.22426010668278001,0.22512120008469,0.2241031229496,0.22985850274562999,0.23936223983765001,0.25521698594093001,0.26921531558036998,0.27200987935066001,0.26911401748656999,0.26326939463615001,0.25368407368660001,0.23958548903464999,0.22362145781517001,0.20992940664290999,0.19358108937740001,0.16910164058207999,0.14174042642116999,0.11545208841562001,0.089174404740334001,0.064619794487953006,0.037474304437637003,0.001924991607666,-0.036537948995829003,-0.075066246092319003,-0.11088672280311999,-0.13900706171989,-0.16252148151397999,-0.18422332406044001,-0.20048443973064001,-0.20798258483410001,-0.20792138576508001,-0.19860813021660001,-0.18537726998328999,-0.17538335919379999,-0.16283656656741999,-0.14311434328556,-0.11873252689838,-0.087239883840084007,-0.059016495943069,-0.05045734718442,-0.044418707489966999,-0.024866389110683999,-0.00053681805729865995,0.026353189721704001,0.050837527960539003,0.064090266823769004,0.073398627340793998,0.086062252521515004,0.095287024974822998,0.099053658545017007,0.088785767555236997,0.043899640440941003,-0.0061457380652428003,-0.027852388098836001,-0.043301694095134999,-0.063800491392611999,-0.093898020684719002,-0.15172612667084001,-0.21192508935928001,-0.24703581631183999,-0.27152627706527999,-0.29142919182777,-0.30827662348746998,-0.32878035306931003,-0.34514310956000999,-0.34909677505492998,-0.34548750519753002,-0.33805119991302002,-0.32351079583168002,-0.29567533731460999,-0.26521587371826,-0.24575442075729001,-0.22769084572792,-0.20406506955623999,-0.17687718570232,-0.14234185218810999,-0.11056295782328,-0.096544533967971996,-0.087858751416205999,-0.074122510850430007,-0.058599494397639999,-0.038251854479313001,-0.021693497896194,-0.023235963657497999,-0.028585907071828998,-0.023049855604768001,-0.014486530795693,-0.0048471614718437004,0.00013905111700296001,-0.012905937619507001,-0.028157163411378999,-0.026964109390974,-0.021461402997375,-0.019120419397949999,-0.020933613181113999,-0.035416971892118003,-0.050202488899230999,-0.049508951604365997,-0.043591476976870998,-0.039581019431352997,-0.036334209144114997,-0.038744386285542998,-0.036854274570942001,-0.014872618019581001,0.012901969254016999,0.032617293298243998,0.049527458846568999,0.062915004789829004,0.078310936689376998,0.1063639819622,0.13635233044624001,0.15703900158404999,0.17301109433174,0.18427217006683,0.19492851197719999,0.21179370582104001,0.23073077201843001,0.24913807213306,0.26680085062981002,0.28017583489418002,0.2954129576683,0.32285553216933999,0.35236600041388999,0.37286019325255998,0.38942381739616,0.40451249480246998,0.41768836975098,0.42901775240897999,0.43940487504004999,0.45152580738067999,0.46144324541092002,0.46443253755568997,0.46192210912704001,0.45427590608597002,0.44053199887276001,0.41820946335793002,0.39090985059737998,0.36421939730643998,0.33351236581802002,0.29213654994964999,0.24719870090484999,0.20790097117424,0.16834567487239999,0.12358044087887,0.075234204530715998,0.017399780452251001,-0.033336937427521002,-0.046791031956673002,-0.048839975148438998,-0.067654423415660997,-0.090979605913161996,-0.11515320837498,-0.13516747951508001,-0.13852137327194,-0.13586910068989,-0.13867378234863001,-0.14259061217308,-0.14975079894066001,-0.15070782601832999,-0.12596309185028001,-0.094076953828335003,-0.076249003410338995,-0.064986638724803994,-0.059707902371882997,-0.056961387395859001,-0.049746342003344997,-0.042856328189373002,-0.041166324168443999,-0.042325809597969,-0.046396750956774001,-0.049580931663513003,-0.042487379163504001,-0.035368874669074998,-0.042213663458823998,-0.055288091301918002,-0.068907089531421994,-0.083682127296924994,-0.097908101975917997,-0.1121097356081,-0.12633171677589,-0.14055892825127,-0.15478946268558999,-0.16901108622551,-0.18479987978935,-0.19796228408812999,-0.20055109262466,-0.19860659539700001,-0.19815966486931,-0.19836720824241999,-0.20308373868464999,-0.20568801462649999,-0.19313424825667999,-0.17748293280602001,-0.17473390698433,-0.17660330235957999,-0.17856681346893,-0.17732118070125999,-0.15938879549502999,-0.1414370238781,-0.14908213913441001,-0.16769997775555001,-0.18664607405663,-0.20350781083107,-0.20565417408942999,-0.20394761860371,-0.21290145814419001,-0.22471363842486999,-0.23426559567451,-0.23946343362330999,-0.23090194165707001,-0.21845382452011,-0.21704046428203999,-0.21799257397652,-0.21439391374587999,-0.20539204776287001,-0.18280097842216,-0.15623502433299999,-0.14105117321013999,-0.12827990949154,-0.10883024334907999,-0.086325056850910006,-0.060968056321144,-0.036949101835489002,-0.023524582386016998,-0.014776229858398,-0.0041707204654813004,0.0057681091129779998,0.016299068927765,0.021107867360114999,0.0053851613774895998,-0.018398948013783001,-0.034533523023129002,-0.047265790402889002,-0.055464684963225999,-0.061900101602076998,-0.072616793215275005,-0.082689031958580003,-0.085903443396091003,-0.083942338824272003,-0.077973313629627006,-0.065084807574749007,-0.037230327725410003,-0.0034584440290928,0.021467991173267,0.045060545206070002,0.072278954088687994,0.10595054924488,0.16166861355305001,0.21831178665161,0.23726005852222001,0.24164949357509999,0.25684875249862998,0.27524578571320002,0.29890707135201,0.31877774000168002,0.31402432918549,0.29949650168419001,0.29363077878951999,0.29142531752585998,0.29593396186829002,0.29897415637969998,0.28222030401230003,0.25868436694144997,0.24542638659477001,0.23639331758022,0.23068776726723,0.22350722551346,0.20137007534504001,0.17523023486136999,0.16120550036430001,0.15267853438854001,0.14660535752772999,0.13966472446917999,0.12204091250896,0.099489390850067,0.078847385942935999,0.057697109878063001,0.034705691039562003,0.010162264108658,-0.016318246722221,-0.043987300246953999,-0.071187674999237005,-0.099026739597321001,-0.12928706407547,-0.16072472929955001,-0.19203355908393999,-0.22279819846153001,-0.25182920694351002,-0.27859547734260998,-0.30126711726188998,-0.32042038440704002,-0.33451890945434998,-0.34773352742195002,-0.3709565103054,-0.39533674716949002,-0.40788036584853998,-0.41180202364921997,-0.40582075715065002,-0.39268803596496998,-0.37798109650612,-0.35943967103958002,-0.33482536673545998,-0.3055365383625,-0.27203854918480003,-0.237160384655,-0.20875486731529,-0.18186996877193001,-0.14891144633292999,-0.11399618536234001,-0.080647215247154,-0.050974927842617,-0.033326685428619003,-0.021943528205156,-0.0080090072005986994,0.0049308910965919,0.01518639549613,0.020265463739634001,0.010570120066403999,-0.0050181057304144001,-0.010034505277872001,-0.012263771146536,-0.019554972648621001,-0.031309783458710001,-0.054616637527942997,-0.079083368182182007,-0.08146146684885,-0.074716277420521005,-0.075905449688435003,-0.080198481678962999,-0.089489787817000996,-0.095934703946114003,-0.078249044716358004,-0.050443191081284998,-0.033810447901486997,-0.021715560927987002,-0.013089652173221,-0.0030547138303518,0.024198347702622001,0.056869335472584,0.075676620006561002,0.086171776056290006,0.089235134422779,0.087441787123680004,0.087984286248683999,0.087733805179596003,0.083040855824946996,0.075394749641417999,0.066628120839596003,0.055690072476864,0.039048284292221,0.021678350865840999,0.014352183789015,0.013046050444245,0.014845161698758999,0.019067900255321998,0.021394453942776,0.024954371154308,0.036271341145039,0.051051028072834001,0.062790803611279006,0.072326101362704995,0.075938358902931005,0.078621849417686004,0.092624232172966003,0.11101229488849999,0.12326876074076,0.13245326280594,0.13944184780120999,0.14551836252212999,0.15607111155987,0.16641567647457001,0.16748602688313,0.16208630800247001,0.14871749281883001,0.13438792526721999,0.14080452919006001,0.1535941362381,0.14656552672386,0.12981694936752,0.11081109941006,0.094329334795475006,0.10134658962488,0.11849243938923,0.1224505379796,0.12051715701818,0.11603546887636,0.11225609481335,0.12286037951708,0.13819588720798001,0.13897900283337,0.13346135616301999,0.13179962337017001,0.13231235742569,0.13899384438991999,0.14596289396286,0.13772912323475001,0.12209275364876,0.11038225144148001,0.10077988356352,0.097407788038254006,0.094816125929355996,0.079081863164901997,0.056618377566338002,0.037185981869698001,0.017343245446682001,-0.0068157892674208,-0.033918723464012,-0.063123054802418005,-0.093344345688819996,-0.12174184620380001,-0.14770178496837999,-0.1674230992794,-0.18239083886147001,-0.1943324804306,-0.20298703014850999,-0.20839925110339999,-0.21102495491504999,-0.21408253908156999,-0.21327210962772,-0.19517356157303001,-0.16880592703819,-0.15261460840702001,-0.14071194827556999,-0.12939369678497001,-0.11590176820754999,-0.085799545049666998,-0.050532083958387,-0.036771681159734997,-0.033894497901200998,-0.029263788834213999,-0.022244378924369999,0.0012393333017826,0.029462963342667001,0.034114573150872997,0.026603305712341999,0.022411487996578001,0.019315583631395999,0.021961521357298001,0.025918558239936999,0.019274586811662001,0.0079623125493526008,0.0023050215095282,7.2680879384278994e-05,0.0021335880737752,0.0060870540328323997,0.0035724067129195001,-0.00034662103280425001,0.0049820332787931,0.016277389600873,0.032345276325941003,0.049467071890831001,0.054644435644150002,0.052373483777046002,0.047639105468988002,0.040432631969452001,0.034276299178599999,0.027460109442472,0.016756001859902999,0.0032462123781443002,-0.012030903249979,-0.028700210154057,-0.044951487332582002,-0.061169575899838999,-0.076485119760035997,-0.092718616127968001,-0.1171699911356,-0.14452886581421001,-0.16372440755366999,-0.17492128908634,-0.16829653084278001,-0.15176355838776001,-0.14572539925575001,-0.14344909787178001,-0.13694427907466999,-0.12659360468388001,-0.10543084144592001,-0.080768346786498996,-0.073958016932010998,-0.076959758996964001,-0.076943904161452997,-0.076944932341575997,-0.077387921512127006,-0.080876097083092,-0.098819404840469,-0.12419939041138001,-0.14047902822495001,-0.15204903483391,-0.16148349642754001,-0.17080402374268,-0.19083879888058,-0.21492649614810999,-0.22656923532486001,-0.23099203407763999,-0.23404407501221,-0.23665896058083,-0.24856212735176,-0.26276597380638,-0.26002538204192999,-0.24716834723948999,-0.23399838805199,-0.22060687839984999,-0.21585215628147,-0.21400091052055001,-0.19942197203636,-0.17804142832756001,-0.15970571339129999,-0.14363494515419001,-0.13577502965926999,-0.13092955946922,-0.11278765648602999,-0.087963491678237998,-0.068612620234488997,-0.053370088338851998,-0.04669813811779,-0.045285791158676002,-0.040162824094296001,-0.033472765237093,-0.026923269033432,-0.020315289497374999,-0.014216516166925,-0.0080262115225196006,-0.00027250777930020999,0.0092992540448904003,0.022929741069673999,0.039669208228588,0.059480726718902997,0.079141855239867998,0.083609171211719999,0.080844312906264995,0.091489002108573997,0.10976491868495999,0.12809258699417,0.14740496873855999,0.16635857522488001,0.18528231978415999,0.20441322028636999,0.22363723814486999,0.24289904534817,0.26180279254913003,0.27825844287871998,0.29353132843971003,0.31103217601776001,0.33018583059311002,0.35193940997124001,0.37471112608910001,0.39329934120178001,0.40824091434478998,0.41800659894942999,0.42294758558272999,0.42329984903335999,0.41899368166924,0.40771821141242998,0.39339366555214,0.39226269721985002,0.39783918857574002,0.39511516690254,0.38725489377974998,0.37496787309647001,0.36113527417183,0.35817989706992998,0.36303165555,0.37194490432739002,0.38551995158195002,0.40436628460884,0.42754384875298002,0.45102021098137002,0.47631895542144997,0.50819236040115001,0.54379838705062999,0.57665556669234996,0.60459458827972001,0.61191409826278997,0.60466134548187001,0.59724771976471003,0.58687508106232,0.57268655300140003,0.55309563875197998,0.52098655700684005,0.47765448689460999,0.42178338766098,0.35636910796165,0.29294756054878002,0.22999605536461001,0.16968806087971,0.11079629510640999,0.048789326101541998,-0.014033459126949,-0.070744290947913999,-0.12256231158972,-0.17080071568489,-0.21399499475955999,-0.24533924460411,-0.26763707399367997,-0.28855597972870001,-0.30676379799843001,-0.32345429062843001,-0.3357155919075,-0.32734644412994002,-0.30719396471977001,-0.30502966046333002,-0.31401494145393,-0.32595473527907998,-0.33946704864501998,-0.33944454789161999,-0.33357995748519997,-0.34792426228522999,-0.37576669454575001,-0.40591239929199002,-0.43812331557273998,-0.46164470911026001,-0.48129421472549,-0.51261472702026001,-0.55164116621017001,-0.59175026416778997,-0.63248598575591997,-0.66713154315947998,-0.69684207439422996,-0.72231531143187999,-0.74305951595305997,-0.75698488950729004,-0.76450085639954002,-0.76705288887024003,-0.76297968626021995,-0.74370276927947998,-0.71270543336867997,-0.68055254220963002,-0.64592134952544999,-0.61014556884766002,-0.57265305519104004,-0.53115475177765004,-0.48701673746108998,-0.44492778182030002,-0.40486246347427002,-0.37041723728179998,-0.34063547849655001,-0.31299996376037997,-0.2885770201683,-0.27173274755478,-0.26079317927361001,-0.25248554348946001,-0.24433135986328,-0.21763652563095001,-0.18017460405826999,-0.15981251001357999,-0.15015088021754999,-0.13966694474220001,-0.12800668179989,-0.10252376645803001,-0.069037273526192003,-0.050132751464844,-0.040269479155540001,-0.028069339692592999,-0.013213748112321001,0.017973084002733002,0.058061979711055998,0.074585981667042001,0.076371394097804995,0.086625151336193001,0.10268197953701,0.13000538945198001,0.16333712637424,0.17595261335373,0.17513407766819,0.18098783493042001,0.19071502983569999,0.20450845360756001,0.22071021795272999,0.22932192683220001,0.23361788690089999,0.24468655884266,0.26069471240044001,0.28130018711089999,0.30407515168190002,0.31376138329505998,0.31431344151496998,0.31672847270965998,0.31957444548607,0.32285887002945002,0.32617795467376998,0.32771208882331998,0.32743349671364003,0.3232909142971,0.31619662046432001,0.30996131896973,0.30400973558425998,0.29932442307472001,0.29382023215294001,0.27406013011932001,0.24410152435303001,0.21651101112366,0.19161933660507,0.18419812619685999,0.18803632259368999,0.17475515604019001,0.15080095827578999,0.1342309564352,0.12281499803066,0.11730606853962,0.11586099863052,0.10650968551636,0.092726059257983995,0.087524101138114999,0.088712699711323006,0.093097157776355993,0.099976763129233995,0.10185703635215999,0.10079023987055,0.10426112264395,0.11103349179029,0.12019710242748,0.13008172810078,0.12734332680702001,0.11595415323973,0.1119334474206,0.11282193660735999,0.11627170443535,0.12048809230328,0.10975846648216001,0.088796481490134999,0.077642843127251004,0.072929650545120003,0.068347498774529003,0.063288025557994995,0.047230165451764998,0.023766152560711001,0.0097549203783273992,0.0024233832955360001,-0.0039023084100336001,-0.0091268662363290995,-0.016833616420627001,-0.026271572336554999,-0.034760244190692999,-0.043112590909004003,-0.055508755147456998,-0.071002334356307997,-0.085921436548233004,-0.10086347907782001,-0.11770711839199,-0.13581874966620999,-0.15196487307549,-0.16650919616222001,-0.18016070127486999,-0.19217602908611001,-0.19748568534850999,-0.19666512310504999,-0.18987962603569,-0.17714737355709001,-0.15732672810555001,-0.13188754022120999,-0.11253966391087,-0.096396222710609006,-0.069602012634276997,-0.035024680197238998,-0.0017745234072207999,0.028775775805116002,0.036056082695723003,0.025407768785954001,0.022393334656953999,0.023443043231964,0.022121377289294999,0.017321575433016,-0.0069496715441346004,-0.046031080186367,-0.074744574725627996,-0.096739582717419004,-0.12109276652336,-0.14735746383667001,-0.18076111376286,-0.21829730272292999,-0.23891678452491999,-0.24558906257152999,-0.24517229199408999,-0.23769864439964,-0.22917057573794999,-0.21808004379272,-0.19562488794326999,-0.16391405463219,-0.13362072408198999,-0.10404970496893,-0.078533500432968001,-0.055952560156584001,-0.028068985790014,0.0026507042348385,0.020633898675441999,0.027917623519897,0.029240617528557999,0.024815415963530998,0.021084712818264999,0.016265029087662999,-0.0011570984497665999,-0.029206499457359002,-0.060025215148926003,-0.093552723526954998,-0.12395963817835,-0.15094229578971999,-0.1655542999506,-0.16942377388477001,-0.16930077970028001,-0.16528150439261999,-0.16593258082866999,-0.16829565167426999,-0.14912278950214,-0.11266710609198,-0.080132365226745994,-0.050331078469753002,-0.031195398420095,-0.019698284566402002,0.0085696922615169993,0.049600075930357,0.084665492177009999,0.11449804157019,0.12886951863766,0.13107374310493,0.14745937287807001,0.17380972206593001,0.18853844702243999,0.19355112314223999,0.19071170687674999,0.18045988678932001,0.16832621395587999,0.15365171432495001,0.13384930789471,0.10944240540266,0.083025053143501004,0.055315844714642001,0.037430774420500003,0.027520133182405999,0.014433247037232,-0.00052601844072341995,-0.013044124469161001,-0.022545006126165001,-0.017450945451855999,-0.00017672032117843999,0.011416168883443,0.019163440912962001,0.028836470097302998,0.040336951613426,0.058209564536809998,0.080903112888336001,0.094041079282760995,0.098897390067577001,0.098294891417027005,0.092064917087555001,0.079938389360904999,0.061929326504469001,0.037909299135207998,0.0080164447426795994,-0.026516184210777002,-0.065499715507030001,-0.10739547014236001,-0.15085336565971,-0.17593564093113001,-0.18504033982754001,-0.19127523899078,-0.19377121329308,-0.19233053922653001,-0.1865495890379,-0.17104040086269001,-0.14653408527374001,-0.11748865246773001,-0.084017440676688995,-0.051241159439086997,-0.018899064511060999,0.012281760573387,0.0420086607337,0.064873702824116003,0.081496253609656996,0.095386587083339996,0.10656107962132,0.1196910738945,0.13339693844318001,0.13040472567080999,0.11286073923110999,0.096236817538738001,0.080188944935799006,0.074764415621758007,0.077911123633384996,0.066288501024245994,0.042637102305888998,0.027776004746556001,0.021066181361674999,0.032138314098119999,0.059134088456630998,0.081512331962585005,0.10099576413631001,0.12703996896743999,0.15927809476852001,0.20027148723602001,0.24920485913754001,0.29609748721123003,0.34102261066437001,0.37584829330443997,0.40126937627791998,0.42170551419258001,0.43664968013763,0.44131773710250999,0.43566101789473999,0.41391095519066001,0.37678837776183999,0.33128592371941001,0.27731865644455,0.22091542184353,0.16093319654464999,0.080769553780556003,-0.018130645155907,-0.12434452772141,-0.23778720200062001,-0.35103794932365001,-0.46240666508674999,-0.528364777565,-0.55229723453521995,-0.56121701002121005,-0.55403566360473999,-0.53178960084914995,-0.49394494295120001,-0.42949187755585,-0.34005516767501998,-0.25027948617934997,-0.15907603502274001,-0.058059088885784003,0.049023941159247998,0.078169949352741006,0.036182440817355999,-0.0012759584933518999,-0.037050411105156,-0.071038603782654003,-0.10337422788143,-0.13345317542553001,-0.16095516085625,-0.17731228470801999,-0.18281821906567,-0.17655795812607,-0.15858456492424,-0.12737381458281999,-0.083592675626278007,-0.041763618588448001,-0.0018945448100567001,0.028350234031677,0.046714663505553998,-0.026977937668562001,-0.18590857088566001,-0.31746393442153997,-0.42488282918929998,-0.50286859273911,-0.55012607574463002,-0.50777387619018999,-0.38078504800796997,-0.26259678602219,-0.15036524832249001,-0.041767679154872998,0.063336990773678006,0.16794960200787001,0.27120667695999001,0.34686732292174999,0.39577442407607999,0.42224225401878002,0.42590487003326,0.39180669188499001,0.32174509763718001,0.26607802510262002,0.22369454801083,0.20120766758919001,0.19834670424461001,0.21770438551903001,0.25830128788947998,0.28438511490821999,0.29665514826775002,0.28851234912871998,0.26037788391112998,0.21963226795196999,0.16660463809966999,0.12081933766602999,0.082359224557877003,0.076707288622856001,0.10292867571115,0.14377845823765001,0.19911870360374001,0.2442419230938,0.28013032674789001,0.33622029423714,0.41154229640960999,0.48105651140213002,0.54470670223235995,0.57680159807205,0.57760721445083996,0.53232419490813998,0.44188106060027998,0.34981143474579002,0.25573962926865001,0.17565280199051,0.109380222857,0.065256439149379994,0.042923670262098,0.023572940379380999,0.0073952209204435002,-0.0079598519951104996,-0.022413041442633001,-0.032439276576042002,-0.038060009479523003,-0.037818819284438997,-0.031759940087795001,-0.025525789707899,-0.018836269155145,0.022268112748861001,0.097146794199944,0.15062020719051,0.18308210372924999,0.20003880560397999,0.20152182877064001,0.19482424855232,0.17992243170738001,0.16024251282214999,0.13575494289397999,0.10402840375899999,0.065031975507735998,0.00052665919065474998,-0.089348763227463004,-0.15224748849868999,-0.18826854228973,-0.21391037106513999,-0.22916372120379999,-0.23733022809029,-0.23840428888797999,-0.24003089964390001,-0.24221420288086001,-0.24685022234917001,-0.25393527746201,-0.26894462108611999,-0.29198589920998003,-0.29387629032134999,-0.27442905306816001,-0.25352278351784002,-0.23122037947178001,-0.21009162068366999,-0.19013054668903001,-0.17581893503665999,-0.16717807948589,-0.16548091173172,-0.17074277997017001,-0.18427409231663,-0.20628267526627,-0.21202011406422,-0.20107886195183,-0.19431132078171001,-0.19194762408732999,-0.18980291485785999,-0.18792849779129001,-0.17817452549933999,-0.16029329597950001,-0.14764435589314001,-0.14047433435917001,-0.13299390673636999,-0.12538312375546001,-0.098011128604411996,-0.050262719392775997,-0.0052189957350492,0.036815699189900998,0.075376003980636999,0.11054787784815,0.13424295186995999,0.14620651304721999,0.15321737527847001,0.15536102652549999,0.15354980528355,0.1477342993021,0.14199307560921001,0.13640689849854001,0.13125580549240001,0.12661993503571001,0.11915063112974,0.10876897722483,0.095809943974018,0.080245077610015994,0.063196055591105998,0.04461757838726,0.027771811932324999,0.012783097103238,-0.0028664655983447998,-0.019450867548585,-0.028258506208658,-0.029158415272832,-0.018570715561509001,0.0036573074758052999,0.036842048168181998,0.081263259053229994,0.12696686387062001,0.17396442592144001,0.21103431284428001,0.23758769035339,0.26177328824996998,0.28378003835678001,0.30640304088593001,0.33058246970177002,0.32689598202705,0.29361450672150002,0.25533193349838001,0.21227478981018,0.18213659524917999,0.16653956472874001,0.13457173109055001,0.084445811808109006,0.038765233010054002,-0.0020162835717200999,-0.031280074268578997,-0.049198254942894003,-0.040221735835074997,-0.0027696825563908001,0.036236435174942003,0.075850546360015994,0.11537641286850001,0.15479207038879,0.19178883731365001,0.22641356289386999,0.25480136275290999,0.27682527899741999,0.2942533493042,0.30882468819617998,0.27363044023513999,0.18372495472431,0.11141593009233,0.059948809444904001,0.021675867959857001,-0.0044415704905987003,0.0080027282238007008,0.062358509749174,0.10838586837053001,0.14346595108509,0.17575803399086001,0.20508340001106001,0.24125139415263999,0.28606197237968001,0.31086400151253002,0.31427946686745001,0.29725509881973,0.26033222675322998,0.18645346164703,0.071944266557692996,-0.024158284068108,-0.098150573670863994,-0.16421401500701999,-0.22279879450798001,-0.27534541487693998,-0.32286715507507002,-0.34783753752708002,-0.34941193461418002,-0.32561382651329002,-0.27641981840134,-0.19283708930016,-0.069789871573448001,0.0041253156960010997,0.021721819415689,0.021845715120435,0.0061738248914480001,-0.023891407996416002,-0.068735778331756994,-0.11662356555462,-0.16682589054107999,-0.21959078311919999,-0.27530059218406999,-0.32837483286857999,-0.38047897815704002,-0.39697247743607,-0.37613037228584001,-0.30597305297852001,-0.18267560005187999,-0.050609607249498,0.090731739997864005,0.18337348103522999,0.22086483240127999,0.24123278260230999,0.24683530628681,0.23508884012699,0.20672871172428001,0.15240253508091001,0.073341622948647003,-0.066184878349304005,-0.27493360638617997,-0.45773875713348,-0.60973799228668002,-0.70377540588378995,-0.73628044128418002,-0.71944254636765004,-0.65170687437056996,-0.56622976064681996,-0.46569716930388999,-0.34698584675789002,-0.20906627178192,-0.065193004906178006,0.086349979043006994,0.20514526963234,0.28746771812438998,0.33984771370888001,0.36192131042480002,0.36063829064369002,0.33564612269402,0.30009302496910001,0.25518554449080999,0.19962012767792001,0.13330294191837,0.05547471344471,-0.036718271672725997,-0.10398217290639999,-0.14173182845116,-0.16713547706604001,-0.18055956065654999,-0.19338943064212999,-0.20865567028522,-0.19932189583778001,-0.16146682202816001,-0.11702635139226999,-0.067162536084652003,-0.017778571695089,0.031642764806746999,0.064716465771197995,0.079006507992744002,0.085961304605007005,0.086527310311794003,0.077776603400706995,0.056714672595262999,0.060395542532205998,0.094717644155024996,0.12874577939510001,0.15980279445647999,0.19197183847426999,0.22868403792381001,0.22714667022227999,0.17974241077899999,0.12939590215683,0.080215901136397996,0.027525929734110999,-0.028485797345638001,-0.091587029397488001,-0.16362854838370999,-0.22742976248263999,-0.28152477741241,-0.32449936866759999,-0.35763227939606002,-0.36071676015853998,-0.32896971702576,-0.29327350854874001,-0.25675073266029003,-0.21715414524078,-0.17419356107712,-0.13209693133830999,-0.091129958629608002,-0.053002852946519997,-0.017266724258661,0.0088921012356876997,0.02529351785779,0.023657236248255002,0.00033235549926758002,-0.015379918739199999,-0.019916631281376,-0.018410915508866001,-0.011068447493017001,0.0022913843858987002,0.022179525345564,0.043724678456783003,0.067498207092285004,0.081728860735893,0.085083782672881997,0.075963698327541004,0.052283905446529,0.033072650432587003,0.022278551012277999,0.0010259468108416,-0.033442784100770999,-0.074079498648642994,-0.12262932956219,-0.15470361709595001,-0.16626873612404,-0.16802583634852999,-0.16076539456844,-0.14569798111915999,-0.12257093936205,-0.096764884889126004,-0.069649636745453006,-0.033955506980418999,0.012276094406843,0.058451481163502003,0.10468111932278,0.13779973983765001,0.15549319982529,0.16244128346442999,0.15828464925288999,0.14986492693424,0.13760185241698999,0.12651577591895999,0.11800418794155,0.1056018024683,0.087695106863975997,0.072401128709316004,0.060687638819218001,0.052135217934847003,0.045779321342706999,0.052029434591532003,0.074377074837685006,0.093397021293639998,0.10639173537493,0.11566647142172,0.12101878225803001,0.12459275871515001,0.12704460322857,0.12513981759548001,0.11854037642479,0.1068439334631,0.090493172407150005,0.063680976629256994,0.023308746516705,-0.010432664304972,-0.034621439874172003,-0.051242958754301002,-0.061167564243078003,-0.055236570537090003,-0.029404809698462001,-0.0077361548319458996,0.0054970225319265998,0.018388256430625999,0.030988082289696,0.050503958016634001,0.080911502242087999,0.097585789859295002,0.095588475465774994,0.087196394801139998,0.073718108236789995,0.055770449340342997,0.033497650176287003,0.0079353200271726002,-0.020678622648119999,-0.052802953869103997,-0.088636793196201005,-0.12750025093555001,-0.17092467844486001,-0.20506268739700001,-0.22648073732853,-0.24582974612712999,-0.26487770676612998,-0.28096064925193998,-0.29520702362061002,-0.29608207941054998,-0.28035539388656999,-0.25905555486678999,-0.2334842979908,-0.20510640740395,-0.17368087172508001,-0.14462871849537001,-0.11920100450516,-0.094837568700313998,-0.071218892931938005,-0.048215575516223998,-0.02479987218976,-0.0087809674441814006,-0.0021991692483425002,0.00071405043127015005,0.00024523583124392,0.00022152801102492999,0.0012057996354997,0.0048888623714447004,0.012670683674514001,0.016528045758605,0.014394131489097999,0.01214368082583,0.010932413861155999,0.0083907041698694004,0.0045540062710642997,-0.0037129817064851999,-0.019085362553596,-0.025878071784972999,-0.021379970014095001,-0.0053292829543351997,0.025094605982304001,0.051540184766054001,0.069414667785167999,0.089205853641033006,0.11265276372433,0.13804444670676999,0.16703651845455,0.1864894926548,0.19317039847374001,0.19323751330375999,0.18731762468815,0.17662598192692,0.16150480508803999,0.1417598426342,0.11705358326435,0.089758716523647003,0.059942569583654001,0.030215809121727999,0.0010015815496444999,-0.027166739106177999,-0.055331211537122997,-0.074622072279453,-0.082189366221428001,-0.086105324327946001,-0.087541371583939001,-0.087860815227031999,-0.089367814362049006,-0.078532941639422996,-0.050577938556670997,-0.020822230726479998,0.0087935309857129999,0.033861570060252998,0.053870849311351998,0.063562847673893003,0.06005059927702,0.054889202117919998,0.050383873283862998,0.045371539890765998,0.040644146502018003,0.030907645821571,0.013551540672779,-0.00092163728550075997,-0.010572758503257999,-0.015857897698878999,-0.019058611243962999,-0.0027165440842509001,0.041188798844814002,0.083152599632740007,0.11756880581379001,0.1458428800106,0.17113059759140001,0.16794624924660001,0.12432660162449,0.08382622897625,0.055882740765809999,0.033096887171267998,0.015153106302023,0.0017076225485653,-0.0075408034026622998,-0.011259915307164,-0.0083213988691567993,-0.0041026421822608003,0.0010722465813159999,0.0020717692095785999,-0.0029188017360866,-0.010028410702944,-0.017027858644724,-0.033760454505681999,-0.061542417854071003,-0.10646996647119999,-0.17740572988987,-0.2282882630825,-0.24647326767444999,-0.24938383698462999,-0.23977175354958,-0.21451780200005,-0.16868725419044001,-0.13106486201286,-0.10933877527714,-0.095428243279456995,-0.088501676917076,-0.088597714900970001,-0.097127646207809004,-0.10474789887667001,-0.10956097394228,-0.10996960103512,-0.10473674535751,-0.097034983336926006,-0.086486294865607993,-0.079327844083308993,-0.077866099774836994,-0.077435232698917,-0.077087469398974998,-0.077424921095370997,-0.078696213662623998,-0.079631969332694993,-0.080710932612419004,-0.077096313238144004,-0.066428616642951993,-0.055577814579010003,-0.045557934790849998,-0.039222255349158998,-0.038866497576237002,-0.036084387451410002,-0.027851685881615001,-0.020841537043451999,-0.016301602125167999,-0.014962215907872001,-0.018740816041827001,-0.018543936312199,-0.011366916820407,-0.0021198561880737998,0.0080696521326899997,0.020319955423474,0.032754778861999997,0.058019682765006998,0.10539495944977,0.13962396979332001,0.15118856728076999,0.14689293503761,0.12702515721321,0.091481320559977999,0.035175628960133001,-0.012593444436789,-0.042857050895691001,-0.064257495105267001,-0.078256703913212003,-0.082082726061343994,-0.072635091841220994,-0.064317211508750999,-0.061368826776742998,-0.060437165200709998,-0.061451256275177002,-0.063107900321484001,-0.064737059175968004,-0.067948624491692006,-0.073373422026633994,-0.079531505703926003,-0.086160369217396005,-0.093222983181476995,-0.10299672931433,-0.10236436128616,-0.085944138467311998,-0.063977941870689004,-0.038623195141553997,-0.0094542531296611006,0.027176205068827002,0.049745146185160002,0.049300458282232,0.04255885258317,0.033372968435286997,0.020023941993713001,-5.7445839047432e-05,-0.012109884060919,-0.0095201572403312007,-0.0058968681842089003,-0.0046954671852291003,-0.0038692827802150999,-0.0022637217771262,-0.0058392873033880997,-0.017422292381525002,-0.030918143689631999,-0.045689336955547,-0.057931177318096001,-0.069587662816048002,-0.062747366726397996,-0.026162870228290998,0.0088771330192685006,0.033549156039953003,0.052055284380913003,0.065480180084705006,0.067250728607177998,0.053490817546843997,0.034310936927795001,0.011804506182670999,-0.011438237503171,-0.034858059138059998,-0.05522208660841,-0.071538247168064006,-0.083142556250095007,-0.090645320713519995,-0.089003525674342998,-0.077221699059009996,-0.051829092204570999,-0.0064820013940333999,0.033144567161797998,0.059821158647537002,0.072387807071208995,0.068736292421818002,0.050860833376646,0.014658056199551,-0.017603326588869001,-0.039656046777963999,-0.048673611134291001,-0.041524473577738003,-0.023394742980599001,0.0076420605182648,0.035756565630435999,0.055688053369521998,0.068223990499973006,0.071833640336989996,0.070880591869353998,0.065759211778640997,0.060743741691112997,0.057943403720855997,0.054553262889385001,0.049506258219481,0.045029744505882,0.041583791375160002,0.039839897304772998,0.040172837674618003,0.042349569499492999,0.046832650899887002,0.051270913332701,0.054834127426147003,0.058079116046429,0.062942288815974995,0.060006927698850999,0.043581694364548,0.026469362899661002,0.012114951387048,0.0014609559439123,-0.0035077419597655999,-0.0078168725594878006,-0.013539159670471999,-0.017796508967876001,-0.019516695290804,-0.020455362275243,-0.020109660923481001,-0.023218866437673999,-0.033220410346985002,-0.041654981672763998,-0.045690979808569003,-0.046748846769332997,-0.044737808406352997,-0.040112823247909997,-0.032223798334598999,-0.024853801354766,-0.019214179366827001,-0.015709521248937,-0.014045035466551999,-0.017555978149176001,-0.029747605323792,-0.039873212575911997,-0.043787587434052998,-0.044615231454371997,-0.042906358838080999,-0.038040265440941003,-0.028388861566782001,-0.020923823118209998,-0.018940802663565001,-0.018345581367612,-0.018123809248209,-0.018410325050354,-0.019398320466280001,-0.019584191963077001,-0.018423138186336001,-0.015885422006249001,-0.012166114524007,-0.0057181259617209001,0.0057676015421747997,0.01431599073112,0.015924170613289001,0.016260590404272,0.017031542956829002,0.01742822676897,0.017434583976864999,0.017057260498404999,0.015813680365681999,0.015901835635304,0.01847736723721,0.022008357569575001,0.026669416576624,0.029780244454740999,0.029347434639930999,0.029538553208113001,0.032256208360195,0.035072583705187003,0.038197141140698998,0.037747271358967001,0.030942808836699,0.023100830614567001,0.015920586884021998,0.0093795480206608998,0.0037112063728273002,-0.00072994740912690997,-0.0039317132905126,-0.0050411196425556998,-0.0029679085128008998,-0.00087046355474739996,0.00039235083386302,-0.00046035880222916999,-0.005089586135,-0.0093489037826657,-0.011333727277815,-0.01296763587743,-0.014817363582551001,-0.016439381986855999,-0.017966195940971,-0.018462151288986001,-0.017415875568986001,-0.015381149016321,-0.012494561262429,-0.0087785739451646996,-0.0042217746376991003,0.0010167182190344,0.0076310872100294001,0.012332417070866001,0.013344896025956,0.01258435472846,0.010513206012547001,0.0073101120069623002,0.0031977165490389,-0.0020424756221473,-0.0085502825677395006,-0.015963189303875001,-0.024149801582098,-0.033177379518746997,-0.044559918344021003,-0.051865704357623998,-0.051188707351685001,-0.047833316028118002,-0.042996585369110003,-0.038552209734916999,-0.035249318927526002,-0.034618135541677003,-0.038126446306705003,-0.043246049433946998,-0.049082800745964002,-0.055778257548809003,-0.064671434462069993,-0.069635413587093006,-0.066375710070133001,-0.061888016760349003,-0.058773837983608003,-0.056320998817682003,-0.055220164358616,-0.053406152874230998,-0.049403849989175998,-0.045821208506823002,-0.043720200657845001,-0.042635571211575997,-0.042975883930921999,-0.043040324002504002,-0.041768185794352999,-0.040486671030520997,-0.039730370044708002,-0.039073694497347003,-0.039013531059027003,-0.037096269428729997,-0.031198168173432,-0.025499615818262,-0.022130098193884,-0.018999602645636,-0.015721373260021002,-0.011472139507532,-0.0051339045166968996,0.00075478723738343001,0.0048295827582479,0.0084268013015388991,0.011697744950651999,0.015586173161864,0.021310940384865001,0.026015143841504999,0.028158741071819999,0.02916300483048,0.029413161799311999,0.028914483264088998,0.027274528518319002,0.026388393715024001,0.02719584852457,0.029483370482921999,0.033352863043547003,0.038799487054347999,0.046603959053755001,0.053758393973112002,0.058544944971800003,0.062245320528745998,0.065127938985825001,0.067287169396876997,0.068634644150734003,0.069951251149177995,0.071996606886386996,0.073325656354427005,0.073110625147820005,0.072241805493831995,0.070769116282463004,0.069643862545490001,0.069883294403552995,0.069541826844215004,0.067483574151993006,0.064931184053421007,0.061961531639099003,0.059861596673727001,0.059918954968452003,0.059911683201790002,0.058702584356070002,0.057140849530697001,0.055675022304057999,0.053414680063724997,0.050811588764191,0.044601544737816003,0.031232595443725999,0.017788380384445,0.0071980599313973999,0.00016648502787575001,-0.0016471184790134001,-0.00053448101971298001,0.0030520181171595998,0.0074180979281663999,0.011567953974009001,0.015301324427127999,0.018410826101899001,0.020390955731272999,0.020594617351889999,0.020203772932291,0.019682340323925001,0.019260633736849001,0.019648525863886001,0.019058113917708001,0.015982059761881998,0.012847380712628,0.010870579630136001,0.0094166435301304002,0.008400441147387,0.0078377118334174,0.0082687884569168004,0.0076384330168365999,0.0045052077621222002,0.00024509587092324999,-0.0046395091339946001,-0.010279919020832,-0.016806636005639999,-0.023591436445713002,-0.030374780297279001,-0.036857895553112002,-0.042664848268031998,-0.048311196267605001,-0.054361186921596999,-0.059541255235671997,-0.063044816255569,-0.065529718995093994,-0.067286953330040006,-0.067992575466632996,-0.067326731979846996,-0.066000387072563005,-0.064583040773869005,-0.062291607260703999,-0.058797843754291999,-0.054020781069994001,-0.046086888760328001,-0.041358411312103001,-0.045266907662153001,-0.050648096948861999,-0.054089330136775998,-0.056716535240412001,-0.058819863945246,-0.058887772262096003,-0.055725991725921999,-0.050496224313973999,-0.043245512992143999,-0.035346571356058003,-0.026867046952248001,-0.020703902468085001,-0.019833035767078001,-0.020194603130220999,-0.019768722355366,-0.019214635714888999,-0.018847834318875999,-0.017260508611797998,-0.013072891160845999,-0.0082689542323350993,-0.0036195530556142001,0.00032100666430779002,0.0034215950872748999,0.0041974447667599002,0.00085005164146423004,-0.0037804390303790999,-0.0086639905348420004,-0.012517879717052,-0.014222268015146,-0.013860511593521,-0.010498368181287999,-0.0066221207380294999,-0.0037918803282081998,-0.0014440115774049999,0.00042475725058466001,0.0017343302024528,0.0027032028883696001,0.0023760546464473,-0.00059102941304444996,-0.0035385014489292999,-0.0047629373148083999,-0.0051853908225894,-0.0046761678531765999,-0.0043317331001162997,-0.0053336862474679999,-0.0060357744805515003,-0.0054681985639035997,-0.0041677327826619001,-0.0017750684637575999,6.1283790273591998e-05,-0.00045951336505823,-0.00069372262805699999,0.0011123000876978001,0.0035738963633776002,0.0065475199371575997,0.0088037019595503998,0.0088361334055661999,0.0087630450725555004,0.010013893246650999,0.011397028341889,0.012521018274128,0.013149369508027999,0.012358106672764,0.012385382317007001,0.015289839357137999,0.018609721213579001,0.021169524639844998,0.022886414080858002,0.023062890395522,0.022811483591794999,0.022981317713856999,0.022761140018702001,0.021765790879726001,0.020090980455279,0.017341749742627002,0.01473552454263,0.013270311057568001,0.012195250019431,0.011241748929023999,0.010381483472884,0.0097476085647941,0.0085793184116482995,0.0058284085243939998,0.0032577544916421002,0.0021813539788127002,0.0015979344025254,0.0013430907856673,0.00068256288068368998,-0.0016346501652150999,-0.0034068694803863998,-0.0028950390405953,-0.0015570907853543999,5.3645228035747998e-05,0.0017303021159023001,0.0030305422842503002,0.0044021005742252003,0.0062099937349557998,0.0079652462154627002,0.0096308421343565005,0.010433229617774001,0.0088642789050936994,0.0079167783260345008,0.010141346603631999,0.013304667547345,0.016325773671269,0.019450750201941001,0.022504376247525,0.025695940479636002,0.029437636956573001,0.032751437276602,0.034742452204227003,0.036224268376826997,0.037620320916176002,0.038802582770586,0.039856474846601,0.040566254407166998,0.040767870843409999,0.040518734604119998,0.039526510983705999,0.038735650479794,0.039132397621869999,0.039687257260084,0.039792351424693999,0.039665468037127997,0.039472326636313997,0.038680180907249,0.036744322627783002,0.034188680350780001,0.031154751777648999,0.028045427054166999,0.025145094841719,0.022723760455847002,0.021253997460008001,0.020192697644233999,0.019234754145145,0.018371261656283999,0.017559817060828001,0.016627736389637,0.015225316397846,0.013972661457956,0.013510965742171,0.013113143853843,0.012296596542001,0.011265094392002,0.0096677495166659008,0.0087086288258432995,0.0099665829911828006,0.011323485523462001,0.011240578256547,0.010401595383883,0.0087735690176487004,0.0068467692472041,0.0050703347660601,0.0033159859012811999,0.0016217597294599,-5.5007007176755003e-05,-0.0020692271646112,-0.0033839985262603001,-0.0023375614546238999,-0.0016664828872308001,-0.0037534409202635002,-0.0070049804635345997,-0.011009148322046001,-0.014968432486057,-0.017795942723750999,-0.020312337204813999,-0.022950636222958998,-0.025578312575817001,-0.028548534959554998,-0.030809242278337,-0.030699048191309,-0.030816236510873,-0.033705085515976001,-0.037072025239468002,-0.039653845131396998,-0.04143488034606,-0.041396860033274002,-0.041435364633799002,-0.043460484594107,-0.045885153114795997,-0.047646570950747001,-0.049417387694119998,-0.051847979426384,-0.053799752146005998,-0.054104879498482,-0.053775832056998998,-0.053451038897037999,-0.052901249378919997,-0.052275795489549998,-0.051085282117127997,-0.048489432781935002,-0.045815378427505001,-0.044256623834371997,-0.043130673468113001,-0.042097702622414003,-0.041405558586121001,-0.041303906589746003,-0.041411023586987998,-0.041520625352858997,-0.041406426578760001,-0.041258584707974999,-0.039643544703722,-0.034089833498001001,-0.028137944638728998,-0.025029039010405998,-0.022790718823671001,-0.020533205941319001,-0.018393380567430999,-0.015862451866269001,-0.014002026058733,-0.014503226615488999,-0.014869119971991,-0.01307625323534,-0.0095558175817131996,-0.0030768238939345,0.0033866495359689002,0.0065230038017034999,0.0087114600464701999,0.011364597827196,0.01400969363749,0.0069358632899821004,0.019275870174169998};

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
			fmydspSIG0Wave0_idx = ((1 + fmydspSIG0Wave0_idx) % 32768);
			
		}
		
	}
};

mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }

static double ftbl0mydspSIG0[32768];
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
		m->declare("filename", "wavesBubbleMono");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "0.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.1");
		m->declare("misceffects.lib/name", "Faust Math Library");
		m->declare("misceffects.lib/version", "2.0");
		m->declare("name", "wavesBubble");
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
		sig0->fillmydspSIG0(32768, ftbl0mydspSIG0);
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
		ui_interface->openHorizontalBox("wavesBubble");
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
		ui_interface->addVerticalSlider("form wav", &fVslider7, 0.0, 0.0, 15.0, 1.0);
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
		ui_interface->addVerticalSlider("form wav", &fVslider20, 0.0, 0.0, 15.0, 1.0);
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
		ui_interface->addVerticalSlider("form wav", &fVslider25, 0.0, 0.0, 15.0, 1.0);
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
		ui_interface->addVerticalSlider("A", &fVslider1, 0.01, 0.0, 5.0, 0.01);
		ui_interface->declare(&fVslider2, "2", "");
		ui_interface->declare(&fVslider2, "style", "knob");
		ui_interface->declare(&fVslider2, "tooltip", "sec");
		ui_interface->addVerticalSlider("D", &fVslider2, 0.059999999999999998, 0.0, 5.0, 0.01);
		ui_interface->declare(&fVslider3, "3", "");
		ui_interface->declare(&fVslider3, "style", "knob");
		ui_interface->declare(&fVslider3, "tooltip", "percentage of max");
		ui_interface->addVerticalSlider("S", &fVslider3, 0.90000000000000002, 0.0, 1.0, 0.01);
		ui_interface->declare(&fVslider0, "4", "");
		ui_interface->declare(&fVslider0, "style", "knob");
		ui_interface->declare(&fVslider0, "tooltip", "sec");
		ui_interface->addVerticalSlider("R", &fVslider0, 0.10000000000000001, 0.01, 5.0, 0.01);
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
		ui_interface->addVerticalSlider("A", &fVslider34, 0.0, 0.0, 5.0, 0.01);
		ui_interface->declare(&fVslider35, "2", "");
		ui_interface->declare(&fVslider35, "style", "knob");
		ui_interface->declare(&fVslider35, "tooltip", "sec");
		ui_interface->addVerticalSlider("D", &fVslider35, 0.0, 0.0, 5.0, 0.01);
		ui_interface->declare(&fVslider36, "3", "");
		ui_interface->declare(&fVslider36, "style", "knob");
		ui_interface->declare(&fVslider36, "tooltip", "percentage of max");
		ui_interface->addVerticalSlider("S", &fVslider36, 0.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fVslider33, "4", "");
		ui_interface->declare(&fVslider33, "style", "knob");
		ui_interface->declare(&fVslider33, "tooltip", "sec");
		ui_interface->addVerticalSlider("R", &fVslider33, 0.10000000000000001, 0.01, 5.0, 0.01);
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
		ui_interface->addVerticalSlider("A", &fVslider43, 0.0, 0.0, 5.0, 0.01);
		ui_interface->declare(&fVslider44, "2", "");
		ui_interface->declare(&fVslider44, "style", "knob");
		ui_interface->declare(&fVslider44, "tooltip", "sec");
		ui_interface->addVerticalSlider("D", &fVslider44, 0.0, 0.0, 5.0, 0.01);
		ui_interface->declare(&fVslider45, "3", "");
		ui_interface->declare(&fVslider45, "style", "knob");
		ui_interface->declare(&fVslider45, "tooltip", "percentage of max");
		ui_interface->addVerticalSlider("S", &fVslider45, 0.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fVslider42, "4", "");
		ui_interface->declare(&fVslider42, "style", "knob");
		ui_interface->declare(&fVslider42, "tooltip", "sec");
		ui_interface->addVerticalSlider("R", &fVslider42, 0.10000000000000001, 0.01, 5.0, 0.01);
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
