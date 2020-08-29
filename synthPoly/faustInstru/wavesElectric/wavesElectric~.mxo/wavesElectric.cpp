/* ------------------------------------------------------------
author: "Sébastien Clara"
name: "wavesElectric"
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

static double fmydspSIG0Wave0[10240] = {-0.22370067238808,0.26563954353333002,0.78243947029114003,0.96469545364380005,0.99997633695601995,0.93255311250687001,0.83142328262329002,0.80105835199356001,0.78243350982666005,0.74173688888550005,0.70617789030074996,0.70025074481964,0.69960641860962003,0.68160659074783003,0.66408550739287997,0.66269171237946001,0.66258049011230002,0.64944189786911,0.63603949546813998,0.63441842794418002,0.63365083932876998,0.62334114313125999,0.61275589466095004,0.61078482866286998,0.60927361249923995,0.60024404525757002,0.59097224473953003,0.58865910768509,0.58660823106766002,0.57816779613494995,0.56934928894043002,0.56614339351653997,0.56297749280929998,0.55397200584411999,0.54500418901443004,0.54224973917007002,0.54010772705078003,0.53329223394393999,0.52591019868850997,0.52157264947891002,0.51730823516846003,0.51003557443618996,0.50301826000214001,0.50008350610732999,0.49731224775313998,0.49046245217322998,0.48329028487205999,0.47950637340545998,0.47599127888679998,0.46973454952240001,0.46327769756317,0.45921778678893999,0.45510885119437999,0.44803395867348,0.44121086597442999,0.43868952989577997,0.43618479371071001,0.42869657278061002,0.42091074585915,0.41785877943039001,0.41513440012932001,0.40823972225188998,0.40093740820884999,0.39680457115173001,0.39322072267531999,0.38789156079291998,0.38251426815987,0.37886235117911998,0.37505576014518999,0.36879250407219,0.36228573322295998,0.35782474279403997,0.35380813479424,0.34887042641639998,0.34398078918456998,0.34019353985785999,0.33630517125129999,0.33075073361397,0.32505533099174,0.32084378600121,0.31697809696197998,0.31255969405174,0.30801951885223,0.30360141396522999,0.29911822080611999,0.29422852396964999,0.28952196240424999,0.28608509898186002,0.28249523043633001,0.27667123079299999,0.27077874541282998,0.26744326949120001,0.26447054743767001,0.25965380668639998,0.25446480512619002,0.25015765428543002,0.24591951072216001,0.24095740914345001,0.23602959513664001,0.23204657435417,0.22823761403560999,0.2237514257431,0.21926660835743,0.21560083329678001,0.21192120015620999,0.20721027255058,0.20227140188216999,0.19787558913230999,0.19359698891640001,0.18891270458698001,0.18461245298386,0.18221110105515001,0.17972539365292001,0.17438121140002999,0.16848707199096999,0.16431929171085,0.16076330840587999,0.15736013650894001,0.15388326346874001,0.14970104396343001,0.14524948596953999,0.14061605930328,0.13643276691437001,0.13427171111107,0.13217245042324,0.12749949097633001,0.12214794009924,0.11790893226862,0.11383327096701,0.10894322395325,0.10443870723248,0.10228419303894,0.10039733350277,0.096017502248287007,0.091251134872436995,0.08849298208952,0.085877656936645994,0.081297099590301999,0.076285354793071997,0.072440713644028001,0.068737812340259996,0.063984423875808993,0.059398211538792003,0.056812927126884002,0.054445106536149999,0.049848482012749003,0.045058123767376002,0.042599722743034002,0.040508680045604997,0.036609437316656002,0.032240871340035997,0.028619064018130001,0.025065941736102,0.020851166918873999,0.016743019223213002,0.014000348746777001,0.011320989578962,0.0066981995478271996,0.0020046457648277001,-0.00015448592603207,-0.0019078406039625001,-0.0058415746316314004,-0.010213092900813001,-0.013110963627696001,-0.015891447663306999,-0.020286627113819001,-0.024722252041101001,-0.026892436668276998,-0.028846869245172001,-0.033390376716852001,-0.038352526724339003,-0.041127335280179998,-0.043418474495411002,-0.047016810625792001,-0.050834372639655998,-0.053672242909670001,-0.056496594101190997,-0.060721140354872,-0.065016955137253002,-0.067488357424735995,-0.069552630186081002,-0.072864286601542996,-0.076465286314486999,-0.079446367919444996,-0.082308433949946996,-0.085585385560989005,-0.088821023702621002,-0.091182790696620997,-0.093659058213234003,-0.097942158579825994,-0.10256139189004999,-0.10566130280494999,-0.10818327963351999,-0.1107614710927,-0.11338295787572999,-0.11633935570716999,-0.119529992342,-0.12306606769561999,-0.12659014761448001,-0.12938141822815,-0.13201010227203,-0.13525927066803001,-0.13856679201125999,-0.14118298888205999,-0.1436747610569,-0.14673157036303999,-0.15000893175602001,-0.15325590968132,-0.15650771558285001,-0.15982539951801,-0.16291131079196999,-0.16499179601669001,-0.16691595315933,-0.16998511552810999,-0.17343664169312001,-0.17653562128544001,-0.17953018844127999,-0.18250443041325001,-0.18542809784412001,-0.18819248676299999,-0.19104328751564001,-0.19479426741600001,-0.19825501739979001,-0.19889126718044001,-0.19917410612106001,-0.20304323732853,-0.20781876146792999,-0.2102612555027,-0.21196062862873,-0.21419674158096,-0.21665996313095001,-0.21942296624183999,-0.22245572507381001,-0.22598221898078999,-0.22940148413181,-0.23164020478725,-0.23313830792904,-0.23371045291424,-0.23444704711437001,-0.23755115270614999,-0.24186939001082999,-0.24688202142714999,-0.25154072046280002,-0.25289058685303001,-0.25330460071563998,-0.25609931349754,-0.25967010855674999,-0.26260295510291998,-0.26538228988647,-0.26832658052443997,-0.27110868692397999,-0.27307599782943998,-0.27480590343474998,-0.27715077996254001,-0.27972605824470997,-0.28216898441315003,-0.28470048308371998,-0.28776544332504,-0.29080393910407998,-0.29266467690468001,-0.294278383255,-0.29720920324326,-0.30031400918960999,-0.30176490545272999,-0.30288392305374001,-0.30561321973800998,-0.30885180830955999,-0.31133791804313998,-0.31357827782630998,-0.31601765751839,-0.31834682822227001,-0.31986284255981001,-0.3214291036129,-0.32495266199112,-0.32877597212790999,-0.32992523908615001,-0.33051905035973,-0.33387789130210999,-0.33789101243018999,-0.33966955542563998,-0.34066191315651001,-0.34219187498093001,-0.34419241547585,-0.34756073355674999,-0.35133326053619002,-0.35390818119049,-0.35588726401329002,-0.35744965076446999,-0.35901728272437999,-0.36194556951522999,-0.36506444215775002,-0.36615177989005998,-0.36683928966522,-0.36997151374817,-0.37354707717896002,-0.37418651580811002,-0.37417793273925998,-0.37702724337577997,-0.38087567687035001,-0.38366457819938998,-0.38585889339446999,-0.38706019520759999,-0.38798856735228998,-0.39014908671379001,-0.39278396964072998,-0.39513948559760997,-0.39726459980010997,-0.39857134222983998,-0.39981892704964,-0.40270215272902998,-0.40603190660477001,-0.40789973735808999,-0.40926244854927002,-0.4112341105938,-0.41343456506728998,-0.41569513082504,-0.41791629791259999,-0.41969934105873002,-0.42133185267447998,-0.42327940464019997,-0.42533203959464999,-0.42725244164467002,-0.42914891242981001,-0.43104821443558,-0.43312793970107999,-0.43616747856139998,-0.43921494483947998,-0.44004577398299999,-0.44023483991623003,-0.44243547320366,-0.44538271427155002,-0.44767206907272,-0.44960299134254,-0.45099523663521002,-0.45208853483200001,-0.45309427380562001,-0.45444551110268,-0.45785874128342002,-0.46170064806937999,-0.46258622407913003,-0.46244779229164001,-0.46410486102103998,-0.46647641062737,-0.46862292289733998,-0.47071763873099998,-0.47262209653853998,-0.47443339228629999,-0.47631415724754,-0.47819015383719998,-0.48008355498313998,-0.48176851868629,-0.48236563801764998,-0.48280102014541998,-0.48516076803206998,-0.48822271823883001,-0.49004375934601002,-0.49144616723061002,-0.49346083402634,-0.49556428194045998,-0.49687096476554998,-0.49796938896178999,-0.50010204315186002,-0.50236433744430997,-0.50280350446701005,-0.50275856256484996,-0.50466716289519997,-0.50746476650238004,-0.51007753610610995,-0.51241499185562001,-0.51329237222671997,-0.51368367671966997,-0.51553410291671997,-0.51799142360687001,-0.52013820409775002,-0.52198517322539995,-0.52277630567551003,-0.52320253849029996,-0.52469259500503995,-0.52667576074599998,-0.52857655286788996,-0.53043407201767001,-0.53198194503784002,-0.53335648775100997,-0.53466945886612005,-0.53604930639267001,-0.53799450397491,-0.54019260406493996,-0.54221200942992998,-0.54398185014724998,-0.54476648569107,-0.54531699419021995,-0.54754018783569003,-0.55026918649672996,-0.55126065015793002,-0.55159771442412997,-0.55286431312561002,-0.55463379621506004,-0.55693250894546997,-0.55929827690125,-0.56030100584029996,-0.56069147586822998,-0.56159806251526001,-0.56282866001128995,-0.56464958190918002,-0.5667752623558,-0.56868547201157005,-0.57033360004425004,-0.57104653120041005,-0.57142281532287997,-0.57285040616989003,-0.57471257448196,-0.57609695196152,-0.57730442285537997,-0.57861179113387995,-0.57998472452163996,-0.58146017789840998,-0.58308446407318004,-0.58524823188782005,-0.58741509914398005,-0.58810102939606002,-0.58804392814635997,-0.58839827775955,-0.58894908428192005,-0.58977848291396995,-0.59087723493576005,-0.59251421689987005,-0.59419029951096003,-0.59414792060851995,-0.59370648860930997,-0.59609276056289995,-0.59963291883469005,-0.60127991437911998,-0.60205441713332997,-0.60299694538116,-0.60400301218033003,-0.60553675889969005,-0.60720932483672996,-0.60802894830704002,-0.60849332809447998,-0.60949140787125,-0.61076265573501998,-0.61221218109131004,-0.61361783742904996,-0.61395841836928999,-0.61402922868729004,-0.61591643095016002,-0.61852425336838002,-0.61961686611176003,-0.62012267112732,-0.62162762880324995,-0.62348145246506004,-0.62468087673187001,-0.62544870376587003,-0.62561601400375,-0.62564396858214999,-0.62699824571608997,-0.62905740737914995,-0.63091969490051003,-0.63262498378753995,-0.63353431224822998,-0.63415497541428001,-0.63589006662368996,-0.63799947500229004,-0.63885557651519997,-0.63916659355163996,-0.64022380113601995,-0.64159137010573997,-0.64274322986603005,-0.64371389150619995,-0.64414852857589999,-0.64437800645828003,-0.64521992206572998,-0.64650952816009999,-0.64853358268738004,-0.65070998668670998,-0.65092355012893999,-0.65038865804671997,-0.65199774503707997,-0.65457081794739003,-0.65608954429625999,-0.65701806545258001,-0.65740865468979004,-0.65759080648421997,-0.65883451700211004,-0.66056060791016002,-0.66170442104339999,-0.66244953870773005,-0.66243189573287997,-0.66224467754364003,-0.66383522748946999,-0.66641956567764005,-0.66881567239760997,-0.67095702886580999,-0.67166322469711004,-0.67153108119964999,-0.67170190811157005,-0.67209345102310003,-0.67335712909697998,-0.67502427101134999,-0.67581295967101995,-0.67619729042053001,-0.67702490091323997,-0.67802876234054998,-0.67869901657104004,-0.67936062812804998,-0.68111777305603005,-0.68323314189911,-0.68347680568695002,-0.68294501304625999,-0.68438822031020996,-0.68662840127945002,-0.68703758716582997,-0.68659901618957997,-0.687156021595,-0.68822836875916005,-0.68938559293747004,-0.69056409597396995,-0.69113218784331998,-0.69145601987839,-0.69246399402617997,-0.69390630722045998,-0.69572395086287997,-0.69753897190094005,-0.69760143756866,-0.69683456420898005,-0.69761127233505005,-0.69917768239974998,-0.70026445388794001,-0.70123887062072998,-0.70284551382064997,-0.70459634065627996,-0.70485538244247004,-0.70444381237029996,-0.70556968450545998,-0.70741623640060003,-0.70836126804351995,-0.70876234769821,-0.70871514081955,-0.70850473642348999,-0.70937126874923995,-0.71088647842407005,-0.71239316463470004,-0.71380829811096003,-0.71419072151184004,-0.71402990818024004,-0.71455097198485995,-0.71553480625152999,-0.71736019849777,-0.71930366754532005,-0.71816635131836004,-0.71560996770858998,-0.71635484695435003,-0.71887552738189997,-0.72037136554717995,-0.72134888172150002,-0.72172766923903997,-0.72189867496490001,-0.72358590364455999,-0.72603678703308006,-0.72741502523421997,-0.72808015346527,-0.72803676128386996,-0.72759711742401001,-0.72810459136963002,-0.72914355993270996,-0.72998070716857999,-0.73071616888045998,-0.73120701313018999,-0.73158347606659002,-0.73227459192276001,-0.73319453001021995,-0.73435336351394997,-0.73564499616623003,-0.73676621913910001,-0.73757553100586004,-0.73680973052979004,-0.73540300130844005,-0.73693680763244995,-0.73993641138077004,-0.74031007289885997,-0.73932027816771995,-0.73961395025252996,-0.74058294296265004,-0.74144530296325994,-0.74229425191878995,-0.74304980039597002,-0.74369269609451005,-0.74395692348480003,-0.74405801296233998,-0.74478423595428001,-0.74594044685364003,-0.74742650985717995,-0.74895817041396995,-0.74896699190140004,-0.74811440706252996,-0.74822551012038996,-0.7489652633667,-0.75034791231154996,-0.75202190876007002,-0.75217354297637995,-0.75153881311417003,-0.75227046012877996,-0.75380045175552002,-0.75522255897521995,-0.75644975900650002,-0.75613468885421997,-0.75500917434692005,-0.75563865900039995,-0.75730252265929998,-0.75861680507660001,-0.75963968038559004,-0.75946319103241,-0.75857597589492998,-0.75860530138016002,-0.75923633575438998,-0.76029247045517001,-0.76159876585007003,-0.76213592290877996,-0.76221573352813998,-0.76256835460662997,-0.76308304071426003,-0.76383715867996005,-0.76467895507812,-0.76480394601821999,-0.76455378532410001,-0.76507645845412997,-0.76607328653336004,-0.76697081327437999,-0.76777762174606001,-0.76805567741393999,-0.76799607276917004,-0.76815003156661998,-0.76850855350493996,-0.76957118511199996,-0.77105110883713002,-0.77188861370087003,-0.77225971221923995,-0.77216964960098,-0.77176624536514005,-0.77176415920258001,-0.77206981182098,-0.77287113666534002,-0.77395415306090998,-0.77422749996185003,-0.77407050132750999,-0.77479541301726995,-0.77597147226333996,-0.77617537975311002,-0.77581709623337003,-0.77600520849228005,-0.77657335996627996,-0.77759957313537997,-0.77885627746581998,-0.77902960777283004,-0.77858501672744995,-0.77918463945389005,-0.78035187721251997,-0.78063428401946999,-0.78040456771850997,-0.78064477443695002,-0.78118014335632002,-0.78178948163985995,-0.78247189521789995,-0.78306376934052002,-0.78361183404921997,-0.78437674045562999,-0.78514212369919001,-0.78462111949920998,-0.78337258100509999,-0.78380775451660001,-0.78522557020187,-0.78524839878081998,-0.78453987836838002,-0.78529226779937999,-0.78694301843643,-0.78792154788971003,-0.78842264413833996,-0.78821444511413996,-0.78759586811065996,-0.78826022148132002,-0.78972363471984997,-0.79042166471481001,-0.79063576459884999,-0.79079449176787997,-0.79091829061508001,-0.79146373271942005,-0.79230314493178999,-0.79315012693404996,-0.79390710592269997,-0.79360520839690996,-0.79260367155074996,-0.79231917858124001,-0.79254120588303001,-0.79313439130783003,-0.79403281211853005,-0.79481357336044001,-0.79548203945160001,-0.79565793275832997,-0.79549229145050004,-0.79565322399139005,-0.79599809646606001,-0.79612606763839999,-0.79611968994141002,-0.79621291160582996,-0.79636478424071999,-0.79641282558440996,-0.79646962881088001,-0.79735422134399003,-0.79868781566619995,-0.79842728376389005,-0.79714316129684004,-0.79696923494339,-0.79759347438812001,-0.79879271984099998,-0.80036711692810003,-0.80071866512298995,-0.80026614665984996,-0.80057460069655995,-0.80136305093765003,-0.80197668075562001,-0.80246520042419001,-0.80267298221588002,-0.80264222621918002,-0.80252248048782004,-0.80228334665297996,-0.80168473720551003,-0.80092799663544001,-0.80138468742371005,-0.80268222093581998,-0.80323165655135997,-0.80334264039992997,-0.80404049158096003,-0.80509221553802002,-0.80568361282348999,-0.80585014820098999,-0.80493235588073997,-0.80333971977233998,-0.80369132757187001,-0.80538821220398005,-0.80612516403197998,-0.80627101659775002,-0.80678349733353005,-0.80749362707137995,-0.80784589052199995,-0.8079195022583,-0.80784535408019997,-0.80764830112456998,-0.80762791633606001,-0.80772203207016002,-0.80766969919205001,-0.80754899978637995,-0.80780720710753995,-0.80833005905151001,-0.80860489606857,-0.80868858098983998,-0.80856287479401001,-0.80828756093979004,-0.80838280916214,-0.80869531631470004,-0.80827921628952004,-0.80742472410202004,-0.80781733989715998,-0.80910807847976995,-0.80984270572661998,-0.810213804245,-0.81069451570510997,-0.81116455793381004,-0.81078672409057995,-0.80986166000366,-0.81039035320282005,-0.81192356348037997,-0.81227618455886996,-0.81179296970366999,-0.81152129173278997,-0.81143152713776001,-0.81230568885803001,-0.81381124258041004,-0.81358861923217995,-0.81212419271469005,-0.81165868043900002,-0.81193494796752996,-0.81267559528350997,-0.81375002861023005,-0.81368225812911998,-0.81282150745392001,-0.81312519311904996,-0.81425905227661,-0.81480866670608998,-0.81495392322539995,-0.81524622440338002,-0.81557852029800004,-0.81534773111342995,-0.81465828418732,-0.81387865543365001,-0.81306660175322998,-0.81315153837204002,-0.81393736600875999,-0.81431585550308005,-0.81448066234589001,-0.81554591655731001,-0.81721949577331998,-0.81750410795212003,-0.81671440601348999,-0.81615823507309004,-0.81576108932494995,-0.81598269939422996,-0.81664121150970004,-0.81620490550994995,-0.81499993801116999,-0.81513476371765003,-0.81625211238860995,-0.81642079353332997,-0.81591778993607,-0.81604462862015004,-0.81661415100098,-0.81671833992003995,-0.81647336483001998,-0.81632030010223,-0.81624299287795998,-0.81654423475266003,-0.81708174943923995,-0.81634241342545,-0.81471681594848999,-0.81539529561996005,-0.81780636310577004,-0.81833088397980003,-0.81743609905242998,-0.81718689203261996,-0.81741589307785001,-0.81802636384964,-0.81893610954285001,-0.81918531656265003,-0.81889897584914995,-0.81862032413482999,-0.81832307577133001,-0.81812715530395996,-0.81803065538405995,-0.81822043657303001,-0.81861567497252996,-0.81833076477051003,-0.81753206253052002,-0.81747514009475997,-0.81800293922424006,-0.81831789016723999,-0.81847661733626997,-0.81850856542587003,-0.81841748952866,-0.81826382875443004,-0.81802421808242998,-0.81735479831696001,-0.81636565923690996,-0.81615275144577004,-0.81661534309386996,-0.81759625673294001,-0.81898516416550005,-0.81908798217773005,-0.81817597150803001,-0.81835931539536,-0.81940102577208995,-0.82000541687011996,-0.82025134563446001,-0.82015651464462003,-0.81970453262329002,-0.81844311952590998,-0.81653326749802002,-0.81582725048064997,-0.81614887714385997,-0.81682693958282004,-0.81781828403473,-0.81786477565765003,-0.81715291738509999,-0.81722980737686002,-0.81794971227645996,-0.81859058141707997,-0.81916344165802002,-0.81916695833205999,-0.81869369745255005,-0.81872802972794001,-0.81913954019546997,-0.81872206926346003,-0.81762278079987005,-0.81704217195510997,-0.81690609455108998,-0.81712973117828003,-0.81769490242003995,-0.81840246915817005,-0.81919872760773005,-0.81884521245955999,-0.81754118204116999,-0.81757175922393999,-0.81867814064026001,-0.81846457719803001,-0.81716531515121005,-0.81670039892196999,-0.81691354513168002,-0.81672102212905995,-0.81621903181076005,-0.81618219614028997,-0.81656140089035001,-0.81729072332382002,-0.81828981637955001,-0.81791120767592995,-0.81635397672652998,-0.81573349237442005,-0.81592351198196,-0.81660014390945002,-0.81769788265228005,-0.81770890951157005,-0.81676077842712003,-0.81576806306839,-0.81474620103836004,-0.81490188837051003,-0.81609708070755005,-0.81675666570662997,-0.81695777177811002,-0.81682062149047996,-0.81636506319045998,-0.81601101160049005,-0.81574279069901001,-0.81566292047500999,-0.81574505567551003,-0.81547015905380005,-0.81489658355713002,-0.81488937139510997,-0.81537765264510997,-0.81559598445892001,-0.81555968523026001,-0.81481140851973999,-0.81343674659729004,-0.81303197145462003,-0.81349647045134998,-0.81397956609725997,-0.81448876857758001,-0.81440806388855003,-0.81380516290664995,-0.8137983083725,-0.81431877613068004,-0.81472706794739003,-0.81501185894011996,-0.81411796808242998,-0.81217914819716996,-0.81192469596863004,-0.81317973136902,-0.81364780664444003,-0.81342941522598,-0.81337064504623002,-0.81342583894730003,-0.81280905008315996,-0.81160032749176003,-0.81162846088409002,-0.81277370452881004,-0.81299567222595004,-0.81239801645278997,-0.81246453523635997,-0.81311643123626998,-0.81303697824478005,-0.81229209899902,-0.81196522712707997,-0.81199908256530995,-0.81120663881302002,-0.80968523025512995,-0.81004631519318004,-0.81213611364365001,-0.81266736984252996,-0.81177240610123003,-0.81143903732300005,-0.81160777807235995,-0.81172442436217995,-0.81179153919220004,-0.81147032976151001,-0.81077295541762995,-0.80971169471741,-0.80832171440125,-0.80826109647750999,-0.80945569276810003,-0.81016433238982999,-0.81042659282684004,-0.81050968170166005,-0.81040722131729004,-0.8098811507225,-0.80895107984543002,-0.80842208862304998,-0.80827325582503995,-0.80815553665161,-0.80807501077652,-0.80808705091475996,-0.80819141864777,-0.80847173929214,-0.8089154958725,-0.80874091386795,-0.80797380208969005,-0.80757981538773005,-0.80754029750823997,-0.80747485160828003,-0.80738747119903997,-0.80729949474335005,-0.80720734596251997,-0.80676150321960005,-0.80597364902496005,-0.80549460649490001,-0.80531883239746005,-0.80563724040984996,-0.80643910169600996,-0.80693161487579002,-0.80711781978607,-0.80638724565506004,-0.80475950241089,-0.80403578281402999,-0.80419749021529996,-0.80450463294982999,-0.80496078729630005,-0.80564391613007003,-0.80654627084732,-0.80612021684646995,-0.80438309907912997,-0.80363088846206998,-0.80385035276412997,-0.80391526222229004,-0.80382764339446999,-0.80314970016479004,-0.80188477039337003,-0.80138295888901001,-0.80164116621017001,-0.80164819955826006,-0.80140513181686002,-0.80174493789672996,-0.80266880989074996,-0.80284535884857,-0.80227190256118996,-0.80187034606934005,-0.80164206027984997,-0.80166995525359996,-0.80195701122284002,-0.80167835950850996,-0.80082744359970004,-0.80036163330078003,-0.80028820037841997,-0.79990833997725996,-0.79921615123749001,-0.79867392778396995,-0.79828351736069003,-0.79819351434707997,-0.79840910434723,-0.79840886592865001,-0.79818731546402,-0.79787862300873003,-0.79747658967972002,-0.79790991544723999,-0.79920887947082997,-0.79915857315062999,-0.79771673679351995,-0.79666024446487005,-0.79600614309311002,-0.79593336582184004,-0.79645735025405995,-0.79662519693375,-0.79642003774643,-0.79616028070449996,-0.79584765434265003,-0.79558211565018,-0.79536092281341997,-0.79558002948760997,-0.79626584053039995,-0.79610538482666005,-0.79506272077560003,-0.79392826557159002,-0.79269784688949996,-0.79237323999404996,-0.79299551248550004,-0.79340857267380005,-0.79359322786330999,-0.79340773820876997,-0.79282987117767001,-0.79283428192139005,-0.79347443580626997,-0.79303306341170998,-0.79143077135086004,-0.79065722227097002,-0.79076057672500999,-0.79170733690261996,-0.79357069730759,-0.79308819770812999,-0.79008191823958995,-0.78861063718795998,-0.78879898786545,-0.78965526819229004,-0.79120343923569003,-0.79176962375641002,-0.79127609729767001,-0.79093253612518,-0.79080206155777,-0.78947257995605002,-0.78681635856627996,-0.78619819879532005,-0.78781968355179,-0.78797250986098999,-0.78647273778914994,-0.78597503900527999,-0.78659188747405995,-0.78717869520187,-0.78772991895676003,-0.78732419013976995,-0.78586626052856001,-0.78532510995865001,-0.78581172227858997,-0.78594559431076005,-0.78567564487456998,-0.78518521785735995,-0.78445148468018,-0.78427344560623002,-0.78471571207046997,-0.78478860855103005,-0.78443878889083996,-0.78417211771010997,-0.78401213884354004,-0.78379434347152999,-0.78352332115172996,-0.78289735317230003,-0.78187221288680997,-0.78124517202376997,-0.78104478120804,-0.78147321939467995,-0.78260499238967995,-0.78281193971634,-0.78196883201598999,-0.78140652179717995,-0.78118753433228005,-0.78113454580306996,-0.78127557039260997,-0.78080594539642001,-0.77963423728943004,-0.77903425693511996,-0.77910250425339,-0.77894008159636996,-0.77849435806274003,-0.77805018424988004,-0.77759695053100997,-0.77766448259354004,-0.77833676338196001,-0.77836120128632003,-0.77763080596923995,-0.77706384658812999,-0.77668493986130005,-0.77700555324553999,-0.77817368507384999,-0.77761149406433006,-0.77500492334366,-0.77401775121688998,-0.77495789527893,-0.77550065517426003,-0.77553069591521995,-0.77503675222396995,-0.77394890785216996,-0.77341783046722001,-0.77354860305786,-0.77362626791,-0.77362984418868996,-0.77324676513671997,-0.77241742610930997,-0.77179139852524004,-0.77138262987136996,-0.77173745632171997,-0.77300810813903997,-0.77305024862288996,-0.77162045240402,-0.77073240280151001,-0.77055698633194003,-0.77006709575652998,-0.76913517713546997,-0.76913279294967996,-0.7702831029892,-0.77012652158737005,-0.76836103200911998,-0.76745593547821001,-0.76761752367019997,-0.76798546314240002,-0.76854509115219005,-0.76883125305176003,-0.76881051063537997,-0.76840144395828003,-0.76756483316421997,-0.76674920320510997,-0.76596748828887995,-0.76555114984511996,-0.76557910442351995,-0.76520270109177002,-0.76429867744446001,-0.76385122537613004,-0.76395505666732999,-0.76426047086715998,-0.76481723785400002,-0.76449096202849998,-0.76306879520416004,-0.76244002580643,-0.76283490657805997,-0.76286792755126998,-0.76239246129990001,-0.76218843460082997,-0.76235145330428999,-0.76227742433547996,-0.76193803548812999,-0.76102906465529996,-0.75940334796905995,-0.75879007577895996,-0.75945454835892001,-0.75964260101318004,-0.75918352603911998,-0.75856465101241999,-0.75776118040085005,-0.75753110647202004,-0.75801879167556996,-0.75818920135498002,-0.75793957710266002,-0.75752609968185003,-0.75694608688354004,-0.75642400979996005,-0.75599688291550005,-0.75540655851364003,-0.75455421209335005,-0.75451880693436002,-0.75551378726958995,-0.75602382421493997,-0.75588321685791005,-0.75555175542830999,-0.75504660606384,-0.75450354814528997,-0.75392782688141002,-0.75346249341964999,-0.75314038991928001,-0.75273042917251998,-0.75218254327774003,-0.75188535451889005,-0.75192093849181996,-0.75169330835341996,-0.75109195709229004,-0.75081837177277,-0.75098848342895996,-0.75096243619919001,-0.75064551830292003,-0.75053006410598999,-0.75074183940886996,-0.75024437904357999,-0.74880111217499001,-0.74802184104919001,-0.74815696477890004,-0.74811804294586004,-0.74781018495560003,-0.74716407060623002,-0.74606448411941995,-0.74564754962920998,-0.74612277746200995,-0.74646872282027998,-0.74657201766967995,-0.74664324522018,-0.74673318862914995,-0.74638044834136996,-0.74547106027603005,-0.74471223354339999,-0.74418878555297996,-0.74374806880951005,-0.7433500289917,-0.74341583251953003,-0.74415326118469005,-0.74372386932373002,-0.74167394638062001,-0.74071091413498003,-0.74128019809723,-0.74174934625625999,-0.74200040102005005,-0.74158412218094005,-0.74031382799149004,-0.73938244581223,-0.73892802000045998,-0.73895680904387995,-0.73961412906646995,-0.73951506614685003,-0.73833054304123003,-0.73776227235794001,-0.73809319734572998,-0.73838669061661,-0.73859316110610995,-0.73821824789046997,-0.73703402280806996,-0.7366915345192,-0.73764652013778997,-0.73722887039185003,-0.73480373620987005,-0.73359298706054998,-0.73418438434600997,-0.73446792364119995,-0.73415738344193004,-0.73383480310439997,-0.73354560136795,-0.73334401845931996,-0.73330628871918002,-0.73275268077849998,-0.73140752315520996,-0.73113381862640003,-0.73241531848907004,-0.73286247253418002,-0.73198908567429,-0.73169982433319003,-0.73243290185928001,-0.73208504915237005,-0.73013454675674005,-0.72902351617812999,-0.7291619181633,-0.72963589429855003,-0.73051494359970004,-0.73027729988098,-0.72844904661179,-0.72730916738509999,-0.72722995281219005,-0.72758406400680997,-0.72855395078659002,-0.72788906097411998,-0.72480010986328003,-0.72349596023560003,-0.72494220733643,-0.72553527355194003,-0.72458702325821001,-0.72422701120376998,-0.72489356994628995,-0.72495347261429,-0.72407400608062999,-0.72332215309143,-0.72282707691193004,-0.72265553474426003,-0.72296011447905995,-0.72262454032898005,-0.72133755683899003,-0.72033762931823997,-0.71979933977126997,-0.71970236301421997,-0.72019714117050004,-0.72012132406234997,-0.71911442279815996,-0.71878236532211004,-0.71959519386292004,-0.71945250034331998,-0.71776831150054998,-0.71697270870208996,-0.71766221523285001,-0.71771371364594005,-0.71664041280746005,-0.71604853868483997,-0.71625542640686002,-0.71647161245346003,-0.71661704778670998,-0.71653467416762995,-0.71615207195282005,-0.71574836969375999,-0.71538639068604004,-0.71485847234725997,-0.71404564380645996,-0.71370279788971003,-0.71410989761353005,-0.71397894620894997,-0.71296089887618996,-0.71224021911621005,-0.71203511953354004,-0.71201705932616999,-0.71224457025527999,-0.71196222305297996,-0.71084928512572998,-0.71041971445083996,-0.71117460727691995,-0.71105730533599998,-0.70946538448333996,-0.70857578516006003,-0.70892226696014005,-0.70897406339644997,-0.70839899778366,-0.70804423093795998,-0.70812070369720004,-0.70793491601944003,-0.70733815431595004,-0.70661056041717996,-0.70568019151688,-0.70538359880446999,-0.70604813098907004,-0.70639175176619995,-0.70613360404967995,-0.70578855276107999,-0.70541977882384999,-0.70503938198089999,-0.70465952157973999,-0.70426124334335005,-0.70380437374115001,-0.70358312129973999,-0.70372319221497004,-0.70371222496033004,-0.7034495472908,-0.70301645994186002,-0.70238512754439997,-0.70177853107452004,-0.70125323534011996,-0.70069038867949995,-0.69999682903289995,-0.69974440336226995,-0.70019298791884999,-0.70024108886719005,-0.69954729080199995,-0.69914215803145996,-0.69931668043136996,-0.69924479722976995,-0.69876426458358998,-0.69801640510559004,-0.69688093662261996,-0.69626241922378995,-0.69644862413405995,-0.69671946763991999,-0.69702810049056996,-0.69687420129776001,-0.69604742527008001,-0.69517350196838001,-0.69433373212813998,-0.69373190402984997,-0.69349670410155995,-0.69313937425613004,-0.69253104925155995,-0.69188529253006004,-0.69107949733733998,-0.69122022390366,-0.69295144081116,-0.69347894191741999,-0.69186997413634999,-0.69068539142608998,-0.69048500061035001,-0.69062870740891003,-0.69123607873917003,-0.69101196527481001,-0.68933558464050004,-0.68845838308333995,-0.68912798166275002,-0.68929612636565996,-0.68836152553558005,-0.68783110380172996,-0.68820625543594005,-0.68794149160384999,-0.68642729520797996,-0.68571442365645996,-0.68645119667053001,-0.68710219860077004,-0.68748468160628995,-0.68693119287491,-0.68488210439681996,-0.68373858928679998,-0.68433010578155995,-0.68458753824233998,-0.68396651744842996,-0.68344783782958995,-0.68317711353302002,-0.68328779935837003,-0.68398535251616999,-0.68432921171187999,-0.68407255411148005,-0.68344962596893,-0.68235671520232999,-0.68158298730849998,-0.68139904737473,-0.68127769231795998,-0.68113446235657005,-0.68091309070587003,-0.68058788776398005,-0.68012863397598,-0.67940491437911998,-0.67918574810027998,-0.67992782592773005,-0.67990362644196001,-0.67840337753295998,-0.67743629217148005,-0.67764204740524003,-0.67767977714538996,-0.67715805768966997,-0.67689758539199996,-0.67715203762053999,-0.67737990617751997,-0.67761105298996005,-0.67697125673294001,-0.67480319738387995,-0.67369157075882002,-0.67464524507523005,-0.67522084712982,-0.67475283145904996,-0.67416399717330999,-0.67360532283783003,-0.67306774854660001,-0.67257881164551003,-0.67209482192992998,-0.67157423496246005,-0.67121827602385997,-0.67111170291901001,-0.67104578018187999,-0.67094749212265004,-0.67099320888518998,-0.67132091522216997,-0.67135798931122004,-0.67094087600707997,-0.67017370462418002,-0.66886800527572998,-0.66816234588623002,-0.66867452859878995,-0.66853165626526001,-0.66696220636367998,-0.66584920883179,-0.66572630405426003,-0.66598832607268998,-0.66672682762145996,-0.66689085960387995,-0.66595441102982,-0.66524970531464001,-0.66528111696242997,-0.66490727663039995,-0.66357237100600996,-0.66298568248749001,-0.66392308473587003,-0.66438168287277,-0.66368156671524003,-0.66295945644378995,-0.66241252422332997,-0.66225081682205,-0.66275882720946999,-0.66289055347443004,-0.66226786375045998,-0.66146838665009,-0.66055351495742998,-0.65980756282805997,-0.65932714939116999,-0.65912705659866,-0.65933209657669001,-0.65937584638596003,-0.65905040502547996,-0.65863251686096003,-0.65810632705687999,-0.65786355733871005,-0.65825206041336004,-0.65801221132277998,-0.65643501281738004,-0.65551823377608998,-0.65604406595230003,-0.65660911798476995,-0.65701842308044001,-0.65658915042876997,-0.65467000007628995,-0.65339785814285001,-0.65362983942032005,-0.65389299392699995,-0.65380704402923995,-0.65361714363098,-0.65326255559920998,-0.65315502882003995,-0.6535450220108,-0.65378457307815996,-0.65374809503554998,-0.65317535400391002,-0.65168780088425005,-0.65070849657059004,-0.65088266134261996,-0.65098583698273005,-0.65071022510528997,-0.65008902549743997,-0.64889866113662997,-0.64808332920073997,-0.64807498455047996,-0.64809674024581998,-0.64796042442321999,-0.64765334129332996,-0.64702129364014005,-0.64668393135071001,-0.64707225561142001,-0.64689904451369995,-0.64534413814545,-0.64473664760589999,-0.64628618955612005,-0.64722263813018999,-0.64653527736663996,-0.64551663398742998,-0.64433187246322998,-0.64354169368743996,-0.64358514547348,-0.64337509870528997,-0.64235311746597001,-0.64179682731627996,-0.64234638214110995,-0.64256298542023005,-0.64175790548324996,-0.64138531684875,-0.64214038848876998,-0.64255535602570002,-0.64208722114562999,-0.64141821861267001,-0.64070153236389005,-0.63990712165832997,-0.63892948627472002,-0.63836854696274004,-0.63854485750197998,-0.63889181613921997,-0.63944298028946001,-0.63928204774857,-0.63770514726639005,-0.63652056455612005,-0.63647258281707997,-0.63658708333969005,-0.63661921024322998,-0.63666075468062999,-0.63679921627045,-0.63655823469161998,-0.63561648130417003,-0.63472288846970004,-0.63407921791077004,-0.63380789756775002,-0.63421618938446001,-0.63422387838364003,-0.63319116830826006,-0.63247674703598,-0.63269972801207996,-0.63284438848494995,-0.63264220952988004,-0.63203155994414995,-0.63063681125641002,-0.62989324331284002,-0.63061708211899004,-0.63127052783965998,-0.63130080699920998,-0.63120132684707997,-0.63114464282990002,-0.63074088096618997,-0.62971526384354004,-0.62877064943313998,-0.62809729576110995,-0.62788385152816995,-0.62854409217833995,-0.62866109609604004,-0.62737494707107999,-0.62640720605849998,-0.62657284736633001,-0.62655079364777,-0.62574899196625,-0.62514466047286998,-0.62513977289199996,-0.62519502639770996,-0.62512320280074996,-0.62512910366058005,-0.62534433603286999,-0.62539446353911998,-0.62515366077422996,-0.62459862232207997,-0.62354081869125,-0.62267315387725997,-0.62225574254990001,-0.62226933240891003,-0.62307578325271995,-0.62322306632996005,-0.62177217006683005,-0.62052023410796997,-0.62024992704391002,-0.62002599239348999,-0.61946272850036999,-0.61920094490051003,-0.61965513229369995,-0.61985367536545,-0.61923694610596003,-0.61881166696547996,-0.61910027265548995,-0.61921977996826005,-0.61882209777831998,-0.61821627616882002,-0.61747181415557995,-0.61656069755553999,-0.61532700061797996,-0.61445897817612005,-0.61431682109832997,-0.61451268196106001,-0.61506050825118996,-0.61547136306762995,-0.61549824476241999,-0.61528724431991999,-0.61476868391036998,-0.61431425809859996,-0.61415666341782005,-0.61394101381302002,-0.61347270011902,-0.61310338973999001,-0.61293345689774004,-0.61305719614028997,-0.61380255222321001,-0.61402308940886996,-0.61293792724608998,-0.61194771528243996,-0.61165153980255005,-0.61154556274413996,-0.61161077022552002,-0.61146152019500999,-0.61080098152161,-0.61012285947800005,-0.60965687036514005,-0.60912793874741,-0.60824912786483998,-0.60790604352951005,-0.60885113477706998,-0.60940122604369995,-0.60863721370696999,-0.60775679349899003,-0.60713499784470004,-0.60676902532578003,-0.60683429241179998,-0.60691946744919001,-0.60690063238143999,-0.60662788152695002,-0.60584175586699995,-0.60522264242171997,-0.60523730516434004,-0.60507321357726995,-0.60430461168288996,-0.60347419977187999,-0.60269629955292003,-0.60221689939499001,-0.60232585668563998,-0.60242128372192005,-0.60222423076630005,-0.60192453861237005,-0.60148870944976995,-0.60119688510894997,-0.60129588842392001,-0.60131126642226995,-0.60101068019866999,-0.60059624910355003,-0.60004562139510997,-0.59966272115706998,-0.59977912902831998,-0.59963393211365001,-0.59857273101806996,-0.59800124168395996,-0.59894591569901001,-0.59954839944839,-0.59880399703979004,-0.59786289930344005,-0.59704214334488004,-0.59654539823532005,-0.59670543670653997,-0.59687602519989003,-0.59669029712677002,-0.59658628702163996,-0.59687960147857999,-0.59689193964005005,-0.59619742631911998,-0.59536892175674005,-0.59461414813994995,-0.59391570091248003,-0.59323912858963002,-0.59286707639694003,-0.59308874607086004,-0.59331899881363004,-0.59332317113875999,-0.59305936098098999,-0.59223377704619995,-0.59171837568283003,-0.59221929311751997,-0.59252256155014005,-0.59192711114883001,-0.59125512838364003,-0.59073358774185003,-0.59059321880340998,-0.59133511781693004,-0.59167695045471003,-0.59058105945587003,-0.58983731269836004,-0.59072780609131004,-0.59112972021103005,-0.58956754207610995,-0.58839935064315996,-0.58911222219466997,-0.58965772390366,-0.58892709016800004,-0.58814924955367998,-0.58778256177902,-0.58771389722823997,-0.58826947212219005,-0.58834499120712003,-0.58682876825332997,-0.58591902256011996,-0.58731055259705001,-0.58825135231018,-0.58708345890044999,-0.58570891618729004,-0.58479154109955001,-0.58444863557815996,-0.58536964654921997,-0.58576369285582996,-0.58423787355422996,-0.58280998468399003,-0.58252859115600997,-0.58257186412811002,-0.58277928829193004,-0.58289581537247004,-0.58270066976546997,-0.58233255147934004,-0.58179718255997004,-0.58117723464965998,-0.58038067817687999,-0.57993960380553999,-0.58040720224380005,-0.58079749345778997,-0.58046162128447998,-0.58014911413193004,-0.58031386137009,-0.58034121990204002,-0.57979273796081998,-0.57934260368347001,-0.57936710119247004,-0.57957750558853005,-0.58010601997375,-0.58015799522400002,-0.57902491092681996,-0.57767391204833995,-0.57637071609497004,-0.57565784454346003,-0.5762580037117,-0.57695937156677002,-0.57717722654342996,-0.57699286937714001,-0.57610630989074996,-0.57527971267699995,-0.57496958971024004,-0.57495057582855003,-0.57534521818161,-0.57560580968857,-0.57533860206604004,-0.57485210895537997,-0.57420110702515004,-0.57352936267853005,-0.57281816005706998,-0.57250738143920998,-0.57311290502547996,-0.57375472784042003,-0.57406955957412997,-0.57382464408875,-0.57230597734451005,-0.57123339176178001,-0.57213062047957997,-0.57281148433685003,-0.57188290357589999,-0.57069420814514005,-0.56971663236617998,-0.56911623477936002,-0.56932950019836004,-0.56959813833237005,-0.56946128606795998,-0.56920582056045999,-0.56886839866637995,-0.56857007741928001,-0.56843441724777,-0.56833386421204002,-0.56816297769546997,-0.56811034679412997,-0.56839191913605003,-0.56859064102172996,-0.56849890947341997,-0.56807106733321999,-0.5670138001442,-0.56606400012970004,-0.5656515955925,-0.56572633981705001,-0.56665802001953003,-0.56742227077483998,-0.56735974550247004,-0.56670409440993996,-0.56515020132064997,-0.56371974945068004,-0.56316316127777,-0.56299918889999001,-0.56316143274306996,-0.56341761350632003,-0.56366485357285001,-0.56365060806274003,-0.56291669607161998,-0.56235975027083995,-0.56290954351425004,-0.56307280063628995,-0.56144595146178999,-0.56014543771743996,-0.56090593338012995,-0.56155169010161998,-0.56051754951476995,-0.55952954292296997,-0.55972278118134,-0.55994009971618997,-0.55944925546645996,-0.55899375677108998,-0.55906295776366999,-0.55911874771117998,-0.55884093046187999,-0.55846059322357,-0.55802386999130005,-0.55764412879944003,-0.55748283863068004,-0.55730795860291005,-0.55685931444168002,-0.55660027265548995,-0.55704927444457997,-0.55734944343566994,-0.55683314800261996,-0.55612707138062001,-0.55543756484984996,-0.55500090122223,-0.55528873205185003,-0.55548292398453003,-0.55488640069962003,-0.55425190925598,-0.55403864383697998,-0.55393278598785001,-0.55385899543761996,-0.55370962619780995,-0.55318939685821999,-0.55294996500015003,-0.55390948057175005,-0.55435991287231001,-0.55250328779221003,-0.55089682340622004,-0.55166274309158003,-0.55250698328018,-0.55186086893081998,-0.551114320755,-0.55106949806213001,-0.55113065242767001,-0.55113154649733997,-0.55085527896881004,-0.54984796047211004,-0.54890507459641003,-0.54865223169327004,-0.54862880706786998,-0.54870247840881003,-0.54871451854705999,-0.54834783077240001,-0.54811763763428001,-0.54867672920226995,-0.54891133308411,-0.54764711856841997,-0.54647207260132002,-0.54661327600479004,-0.54705744981766002,-0.54733031988143999,-0.54750549793242997,-0.54744607210159002,-0.54734838008881004,-0.54742246866225996,-0.54736727476119995,-0.54688173532485995,-0.54635518789291004,-0.54613393545151001,-0.54583024978637995,-0.54514187574386996,-0.54435515403748003,-0.54343664646149004,-0.54295998811722002,-0.54396569728850996,-0.54457896947860995,-0.54274791479110995,-0.54110908508301003,-0.54196137189865001,-0.54295951128006004,-0.54247957468033003,-0.54167890548705999,-0.54102951288223,-0.54056435823440996,-0.54052108526230003,-0.54067242145537997,-0.54104423522948997,-0.54117351770401001,-0.54029637575150002,-0.53963035345078003,-0.54044163227080999,-0.54125094413757002,-0.54090034961699995,-0.54028493165970004,-0.54006725549697998,-0.53946596384047996,-0.53729987144470004,-0.53581583499908003,-0.53765565156937001,-0.53945058584213001,-0.53827440738678001,-0.53670567274094005,-0.53634911775589,-0.53639596700668002,-0.53671908378600997,-0.53703737258911,-0.53711140155792003,-0.53680181503295998,-0.53549593687056996,-0.53449833393097002,-0.53539228439330999,-0.53623759746552002,-0.53520494699478005,-0.53416001796722001,-0.53472858667374001,-0.53525835275650002,-0.53419661521911999,-0.53334432840347001,-0.53454172611237005,-0.53559792041778997,-0.53431600332259999,-0.53316026926041005,-0.53456795215607,-0.53577846288680997,-0.53414350748062001,-0.53244817256927002,-0.53319877386092995,-0.53394502401351995,-0.53251087665557995,-0.53110730648041005,-0.53180533647536998,-0.53238642215729004,-0.53058367967606002,-0.52906835079193004,-0.53059899806975996,-0.53212112188339,-0.53086644411087003,-0.52927285432815996,-0.52919054031372004,-0.52924680709839,-0.52832680940627996,-0.52769738435744995,-0.52887719869614003,-0.52979779243469005,-0.52799457311630005,-0.52647674083710005,-0.52853739261626997,-0.53047275543213002,-0.52859324216842996,-0.52656370401382002,-0.52785372734070002,-0.52900379896163996,-0.52634936571121005,-0.52428060770035001,-0.52792489528655995,-0.53105038404464999,-0.52683138847350997,-0.52259689569473,-0.52561777830124001,-0.52885508537292003,-0.52574616670608998,-0.52241480350493996,-0.52471005916595004,-0.52671796083449995,-0.54107457399367997,-0.51808220148087003,0.00085451826453208999,0.0013615828938782,0.0018004947341979001,0.0015056512784212999,0.0012509035877883001,0.001897633774206,0.0025325827300549,0.0021727036219090002,0.001860628137365,0.0023217906709759998,0.0035617726389319,0.0049795862287282996,0.0091127995401621004,0.017912728711963002,0.032705664634704999,0.053958337754011002,0.086316287517547996,0.13364881277084001,0.19920775294304,0.29019173979759,0.39922484755516002,0.53457129001616999,0.65635317564010998,0.71222561597823997,0.74169433116912997,0.76943767070769997,0.79193222522735995,0.81516039371490001,0.83577495813369995,0.85222512483597002,0.86474335193634,0.87251675128937001,0.87707108259201005,0.88025569915770996,0.88061040639876997,0.87672060728072998,0.87002849578857,0.86210709810257002,0.85146057605742997,0.83619534969330001,0.81871986389160001,0.80156105756759999,0.78305524587631004,0.76157325506210005,0.73916590213776001,0.72101604938507002,0.69692409038544001,0.65679055452347002,0.60255950689315996,0.52535063028336004,0.44667840003967002,0.39112460613250999,0.3477865755558,0.31340271234512002,0.28773605823517001,0.26899611949920998,0.25817859172821001,0.25639989972115002,0.26180914044379999,0.27129587531089999,0.28893512487410999,0.31896802783012002,0.35930335521697998,0.40777018666267001,0.46818614006041998,0.55346214771270996,0.63686460256577004,0.68571394681930997,0.71869093179703003,0.74402189254760998,0.76569432020187,0.79345703125,0.82144623994827004,0.84556394815445002,0.86824667453766002,0.89153289794921997,0.91343796253204002,0.93195819854735995,0.94828420877456998,0.96353310346603005,0.97641289234160999,0.98535645008087003,0.99162888526917004,0.99640971422195002,0.99897772073746005,0.99913197755813998,0.99624609947205001,0.98885613679885997,0.97874677181243996,0.96796870231627996,0.95527547597884999,0.93962246179580999,0.92187422513962003,0.90287172794341997,0.88210636377335006,0.85869115591048994,0.83426839113234996,0.81112360954285001,0.78758037090302002,0.76093351840973,0.73540568351746005,0.72046810388564997,0.70141124725341997,0.66018962860107,0.60603547096251997,0.53850919008255005,0.47167003154754999,0.42709583044052002,0.39362579584121998,0.36412841081619002,0.34253558516501997,0.33242028951644997,0.33003813028335999,0.33151805400848,0.33819270133972001,0.34950405359268,0.36752355098723999,0.39507019519806003,0.43112403154373002,0.47630685567856001,0.52833163738250999,0.58934605121613004,0.64588755369186002,0.67623293399811002,0.69409209489821999,0.70875090360641002,0.72033655643463002,0.73358654975891002,0.74611496925354004,0.75652664899826005,0.76521676778793002,0.77220124006270996,0.77735024690627996,0.78065085411071999,0.78167903423309004,0.77961885929107999,0.77513098716735995,0.76899731159210005,0.76061236858367998,0.74911385774612005,0.73548185825348,0.72320485115051003,0.70546257495880005,0.67585426568984996,0.63033431768417003,0.55283164978027,0.46478360891342002,0.39197468757629,0.32665401697159002,0.26842299103737,0.21803501248359999,0.17721539735794001,0.14376893639565,0.11507329344749,0.091862902045249994,0.074763402342796006,0.061936598271132001,0.050812657922505999,0.042033672332763998,0.035761017352343001,0.031122414395212999,0.026643225923181,0.023126833140850001,0.021535757929087001,0.020706122741102999,0.018968963995575999,0.017404451966286,0.017206601798534001,0.017463238909841,0.017027905210853001,0.016780653968453001,0.017871670424938001,0.019351968541741,0.019986910745502001,0.020674217492341999,0.022547923028468999,0.024697007611394001,0.025995353236794,0.027153965085745,0.029023975133895999,0.030862443149090001,0.031696081161499003,0.032143853604794,0.032984979450703,0.033496826887131001,0.03264219686389,0.031184811145067,0.030095893889665999,0.028665153309703002,0.025932215154171,0.022702850401401999,0.019970141351222999,0.01724467985332,0.013971102423966,0.01077863574028,0.0086165964603424003,0.0068905297666787997,0.0048507107421755999,0.0031512705609201999,0.0027972101233900001,0.0029479076620191002,0.0025261170230806,0.0020910506136715,0.0022303320001811002,0.0024513101670890999,0.0020371754653752002,0.0015168885001912999,0.0016273387009278001,0.0017923410050571,0.0012421186547726,0.00045937660615891001,-5.1604176405816999e-05,-0.00049875664990395004,-0.001083985902369,-0.0015648454427718999,-0.0014731409028172001,-0.0012462206650525,-0.0015598544850945,-0.0019428201485425,-0.0017593086231499999,-0.0014677899889648,-0.0016994273755698999,-0.0020096364896744,-0.0017876166384667,-0.0014711348339915,-0.0016647588927298999,-0.0019487964455037999,-0.0017511594342068,-0.0014700214378535999,-0.0016551048029214001,-0.0019192118197680001,-0.0017142354045062999,-0.0014373116428033001,-0.001661529764533,-0.0019762918818742002,-0.0017953547649086001,-0.0015281138475984001,-0.0017477539367974,-0.0020645414479077001,-0.0019380846060812001,-0.0017368845874443999,-0.0019803987815976,-0.0023067824076861,-0.0021995343267918002,-0.0020113692153244998,-0.0022417567670344998,-0.0025509665720165001,-0.0024533879477531,-0.0022841056343167999,-0.0025109385605900998,-0.0028449785895646,-0.0027959460858256002,-0.0028819076251239001,-0.0039879940450191003,-0.0055814031511544999,-0.0069732526317238998,-0.0085933916270733001,-0.011045003309846001,-0.013904037885368,-0.016520086675881999,-0.019354417920112998,-0.023129936307669002,-0.027320122346281998,-0.031198974698781998,-0.035090558230876999,-0.03931375220418,-0.043665729463100003,-0.047896269708872001,-0.052093420177697997,-0.056418146938086,-0.060574386268854002,-0.063922479748726002,-0.066907361149788,-0.070182591676711994,-0.073376350104809002,-0.076043188571930001,-0.078374654054642001,-0.080586895346641998,-0.082492947578429995,-0.083739653229712996,-0.08459959924221,-0.085358120501040996,-0.086133182048797996,-0.087259896099566997,-0.088785208761692005,-0.091357491910458,-0.094010673463345004,-0.094831138849258007,-0.094845570623874997,-0.094954431056975999,-0.095403477549553001,-0.097256906330584994,-0.10009881108999,-0.10368897765875,-0.10796713083982,-0.11262597888707999,-0.11785950511694,-0.12368976324797,-0.13059036433696999,-0.13947625458241,-0.15035474300384999,-0.16410817205906,-0.17973408102989,-0.19489121437073001,-0.2115852534771,-0.23390521109104001,-0.25865751504897999,-0.28050425648688998,-0.30208602547646002,-0.32617104053496998,-0.35225942730903997,-0.38165670633316001,-0.41212144494057001,-0.43866428732871998,-0.46416586637496998,-0.49297684431076,-0.52249109745026001,-0.54829931259154996,-0.57358646392821999,-0.60511338710785001,-0.63686430454253995,-0.65881979465484997,-0.67395830154419001,-0.68210881948471003,-0.68609726428985995,-0.69254493713378995,-0.69906640052794999,-0.70345759391785001,-0.70728731155395996,-0.71367877721785999,-0.72034591436385997,-0.72318983078002996,-0.72444057464599998,-0.72730523347855003,-0.73026680946349998,-0.73138296604155995,-0.73156982660294001,-0.73210364580153997,-0.73221379518509,-0.73040193319321001,-0.72787338495255005,-0.72686898708344005,-0.72633075714110995,-0.72491711378098,-0.72318506240845004,-0.72146451473235995,-0.72016805410384999,-0.72071206569671997,-0.72223919630051003,-0.72326207160949996,-0.72465068101883001,-0.72778964042663996,-0.73206549882889005,-0.73675495386124001,-0.74208980798721003,-0.74816471338271995,-0.75507980585098,-0.76335227489471003,-0.77240669727324995,-0.78093159198760997,-0.78964847326278997,-0.79995673894882002,-0.81074917316437001,-0.81973439455032004,-0.82817971706390003,-0.83832764625549006,-0.84879511594771995,-0.85717529058455999,-0.86453938484191994,-0.87230211496353005,-0.87988293170928999,-0.88680815696715998,-0.89283597469330001,-0.89693021774292003,-0.89964473247527998,-0.90168648958205999,-0.90305888652802002,-0.90437597036362005,-0.90510320663452004,-0.90407902002335006,-0.90189266204833995,-0.89934581518172996,-0.89631825685500999,-0.89294660091400002,-0.88923722505569003,-0.8852511048317,-0.8810618519783,-0.87675535678864003,-0.87259662151337003,-0.86936604976653997,-0.86681884527205999,-0.86480355262756003,-0.86330586671829002,-0.86224132776259999,-0.86155736446381004,-0.86087590456009,-0.86064755916595004,-0.86204534769058005,-0.86441707611083995,-0.86652934551239003,-0.86902832984924006,-0.87325388193130005,-0.87825918197632002,-0.88200956583023005,-0.88548552989960005,-0.89039206504821999,-0.89584469795226995,-0.90028464794159002,-0.90436303615570002,-0.90911519527435003,-0.91396319866179998,-0.91780394315720004,-0.92112147808074996,-0.92449605464935003,-0.92798531055449995,-0.93219578266143999,-0.93679761886597002,-0.94140076637268,-0.94579583406447998,-0.94891291856766002,-0.95146059989928999,-0.95499271154403997,-0.95875817537307995,-0.96142125129699996,-0.96356141567230003,-0.96614074707030995,-0.96872454881668002,-0.97065466642380005,-0.97206318378447998,-0.97279500961304,-0.97314298152923995,-0.97417956590652,-0.97505241632462003,-0.97344738245009999,-0.97080910205840998,-0.97029089927672996,-0.97052592039107999,-0.96930360794067005,-0.96737062931061002,-0.96559226512909002,-0.96376085281372004,-0.96185082197188998,-0.95973408222197998,-0.95674496889114002,-0.95354264974594005,-0.95192915201187001,-0.95105844736098999,-0.94940704107285001,-0.94750308990479004,-0.94604021310805997,-0.94479656219482,-0.94335770606994995,-0.94210755825043002,-0.94231271743774003,-0.94306129217148005,-0.94188874959946001,-0.94017189741134999,-0.94099259376526001,-0.94298344850539995,-0.94369363784789995,-0.94391489028930997,-0.94459849596024004,-0.94551682472229004,-0.94657355546951005,-0.94772148132323997,-0.94876420497893998,-0.94973886013030995,-0.95043259859085005,-0.95125454664230003,-0.95377659797668002,-0.95692980289458995,-0.95809102058411,-0.95820659399033004,-0.95858657360077004,-0.95904636383056996,-0.95988953113555997,-0.96090048551559004,-0.96170246601105003,-0.96218180656433006,-0.96163719892501998,-0.96037322282791004,-0.95873278379439997,-0.95698672533035001,-0.95647883415222001,-0.95651274919509999,-0.95559281110764005,-0.95416337251662997,-0.95260047912598,-0.95107394456863004,-0.95061892271042003,-0.95059794187545998,-0.94931972026824996,-0.94754397869109996,-0.94693374633788996,-0.94680351018905995,-0.94577711820601995,-0.94434660673141002,-0.94340777397155995,-0.94259899854660001,-0.94114959239960005,-0.93939661979675004,-0.93819802999496005,-0.93704473972321001,-0.93467772006989003,-0.93144249916077004,-0.92749655246734997,-0.92318743467330999,-0.91994887590408003,-0.91727048158645996,-0.91421490907669001,-0.91114777326583996,-0.90883845090866,-0.90699481964110995,-0.90496850013732999,-0.90307801961899004,-0.90211570262909002,-0.90179246664046997,-0.90148878097534002,-0.90150547027588002,-0.90287023782730003,-0.90479594469070002,-0.90472733974456998,-0.90380996465682995,-0.90484112501143998,-0.90671718120574996,-0.90711015462875,-0.90669614076614002,-0.90642166137695002,-0.90611881017685003,-0.90589869022368996,-0.90552330017089999,-0.90408623218535999,-0.90194684267044001,-0.89978659152984997,-0.89755296707152998,-0.89548993110657005,-0.89356517791748002,-0.89190065860748002,-0.89036762714385997,-0.88855296373366999,-0.88655537366866999,-0.88431096076964999,-0.88209390640259,-0.88114756345749001,-0.88084590435027998,-0.87949001789092995,-0.87762010097503995,-0.87622600793839001,-0.87505424022675005,-0.87369996309279996,-0.87234920263289994,-0.87165802717208996,-0.87120062112808005,-0.86957973241805997,-0.86731821298598999,-0.86568129062652999,-0.86419695615768,-0.86173093318938998,-0.85865950584411999,-0.85565412044525002,-0.85270792245865001,-0.85038679838180997,-0.84835535287857,-0.84561276435851995,-0.84241628646850997,-0.83906280994414995,-0.83559584617615001,-0.83227056264876997,-0.82921791076660001,-0.82740235328674006,-0.82627415657043002,-0.82397997379303001,-0.82125645875930997,-0.82013863325118996,-0.81987172365188998,-0.81858867406845004,-0.81677711009979004,-0.81517750024795999,-0.81371116638184005,-0.81269997358321999,-0.81182289123535001,-0.80982345342635997,-0.80712217092514005,-0.80460906028748003,-0.80216950178145996,-0.79992538690567005,-0.79784142971038996,-0.79598069190979004,-0.79416227340697998,-0.79148972034454002,-0.78835391998291005,-0.78584659099579002,-0.78375518321991,-0.78196054697036999,-0.78040134906768999,-0.77873980998992998,-0.77703934907912997,-0.77534997463225996,-0.77364444732666005,-0.77200025320053001,-0.77014499902724998,-0.76658797264098999,-0.76205366849899003,-0.75908207893372004,-0.75676262378693004,-0.75259125232696999,-0.74720567464828003,-0.74169200658797996,-0.73599869012832997,-0.73075062036514005,-0.72565197944641002,-0.71952098608017001,-0.71297460794448997,-0.70823103189467995,-0.70466768741607999,-0.70093768835068004,-0.69727510213851995,-0.69376254081725997,-0.69052350521088002,-0.68831861019134999,-0.68681615591048994,-0.68492746353149003,-0.68291145563125999,-0.68131792545319003,-0.67993706464767001,-0.67802697420119995,-0.67585277557373002,-0.67486560344696001,-0.67383790016174006,-0.66730386018752996,-0.65682196617125999,-0.64595401287079002,-0.63431990146636996,-0.62281298637390003,-0.61089670658112005,-0.59575861692429,-0.57908833026885997,-0.56786793470383001,-0.56025612354278997,-0.55219179391860995,-0.54411447048187001,-0.53492563962936002,-0.52547574043274003,-0.51967597007750999,-0.51626974344253995,-0.51141393184661998,-0.50604122877121005,-0.50251621007919001,-0.50006800889969005,-0.49642857909202998,-0.49181324243545999,-0.48571950197219999,-0.47820317745209001,-0.46895867586135997,-0.45825004577637002,-0.44737088680267001,-0.43594846129416998,-0.42266917228699002,-0.40811237692833002,-0.39466601610183999,-0.38168519735335998,-0.36702635884285001,-0.35156306624412997,-0.33864259719848999,-0.32760787010192999,-0.31731456518173001,-0.30794939398766003,-0.29986372590065002,-0.29288321733474998,-0.28611934185027998,-0.27990323305129999,-0.27568143606186002,-0.27290818095206998,-0.26975819468498002,-0.26625010371208002,-0.26073750853539002,-0.25396668910980003,-0.24941724538803001,-0.24592138826846999,-0.23898202180861999,-0.22972482442855999,-0.22143055498600001,-0.21351036429404999,-0.20461297035216999,-0.19532129168510001,-0.18835878372192,-0.18304863572121,-0.17725986242294001,-0.17152497172355999,-0.16755443811417001,-0.16499045491219,-0.16285620629787001,-0.16139821708202001,-0.16173143684864,-0.16328802704810999,-0.16318427026272,-0.16212938725948001,-0.16260257363319,-0.16384719312191001,-0.16288509964942999,-0.16028639674187001,-0.15740589797497001,-0.15399177372455999,-0.14930713176727001,-0.14360241591930001,-0.13797737658024001,-0.13222351670265001,-0.12570008635520999,-0.11868188530206999,-0.11253401637077,-0.10699545592070001,-0.10126252472401,-0.095651201903819996,-0.091746412217616993,-0.089206025004386999,-0.087084770202636996,-0.085419781506061998,-0.083705894649029,-0.082069508731364996,-0.080868884921073997,-0.080120116472243999,-0.080374479293823006,-0.081353999674319999,-0.081556186079978998,-0.081253327429295003,-0.081087268888950001,-0.081017047166823994,-0.081335633993148998,-0.081875428557396004,-0.081752583384513994,-0.081049866974353998,-0.079524405300616996,-0.077345676720142004,-0.075582824647426994,-0.073987469077109999,-0.071485854685306993,-0.06839545071125,-0.066348321735859001,-0.06493204832077,-0.062269795686006997,-0.058797098696232002,-0.056352835148572998,-0.054565109312533999,-0.052036009728908997,-0.049041882157326001,-0.046626966446638003,-0.044586244970559998,-0.042124699801206998,-0.039411842823029002,-0.037155274301767002,-0.035222101956606001,-0.033100228756666003,-0.030909979715943,-0.029242718592285999,-0.027958733960985999,-0.026377124711871001,-0.024652976542711001,-0.023516809567809001,-0.022817453369498,-0.021889608353376,-0.020869147032499001,-0.020374916493892999,-0.020266922190784999,-0.019850261509417998,-0.019271349534392,-0.019251126796007,-0.019609352573752001,-0.019377646967768999,-0.018743231892586001,-0.018518012017012,-0.018554607406258999,-0.018234658986330001,-0.017665592953563,-0.017298411577940001,-0.01704329252243,-0.016468178480864001,-0.015649570152164002,-0.014905048534274001,-0.014188137836753999,-0.013318398967385001,-0.01234670355916,-0.011609464883804,-0.011035458184779001,-0.01022860314697,-0.0092808529734611997,-0.0087370313704013998,-0.0084861721843480994,-0.0079297637566924008,-0.0071844607591629002,-0.0068709258921444,-0.0068695633672178,-0.0065608108416199996,-0.0060436758212744999,-0.0057483362033963004,-0.0056076990440488,-0.0053210472688079002,-0.0049384809099138,-0.0047123613767326,-0.0045952186919749,-0.0043142433278262997,-0.0039233220741152998,-0.0037446336355060001,-0.0037164948880671999,-0.0034748259931803001,-0.0030881296843289999,-0.0029550872277468001,-0.0030074920505284999,-0.0028684504795819998,-0.0026060529053211,-0.0026303469203413001,-0.0028635994531213999,-0.0028269079048187,-0.0025998777709900999,-0.0026287462096661,-0.0028388090431689999,-0.0027945544570683999,-0.0025691918563098002,-0.0025968840345740002,-0.0028060537297278998,-0.0027742399834095998,-0.0025687688030303002,-0.0025830413214862,-0.0027545418124646,-0.0027081281878053999,-0.0025050814729183999,-0.0025314260274171998,-0.0027230263222009,-0.0026655634865165,-0.0024256841279566002,-0.0024263025261461999,-0.0026024568360299002,-0.0025494534056634001,-0.0023292438127099999,-0.0023357332684099999,-0.0025091997813433001,-0.0024660348426551,-0.0022637625224887999,-0.0022766299080104,-0.0024484354071318999,-0.0024053626693785,-0.0022030172403902002,-0.002215287880972,-0.0023871655575930999,-0.0023456215858459,-0.0021442554425448001,-0.0021462924778461001,-0.0023002149537206,-0.002252189675346,-0.0020524789579212999,-0.0020553909707814,-0.0022104436066002001,-0.0021533893886954,-0.0019355824915692,-0.0019308094633743,-0.0020876429043710002,-0.0020317074377089999,-0.0018138337181881001,-0.0018084628973155999,-0.0019653623457997998,-0.001910024904646,-0.0016920858761295999,-0.0016861169133335001,-0.0018430808559059999,-0.0017883416730910999,-0.0015703389653936,-0.0015628668479621001,-0.0017187919002026001,-0.0016750307986512999,-0.0014761183410883,-0.001466718968004,-0.0016040744958445,-0.0015427464386448,-0.0013263029977678999,-0.0013181881513447001,-0.0014742158818990001,-0.0014306922676042,-0.0012305604759603999,-0.0012294829357415,-0.0013850156683475,-0.0013321205042303001,-0.0011138787958770999,-0.0011058010859415,-0.0012642019428313,-0.0012057444546372,-0.00097281596390530001,-0.00093667377950624,-0.0010529430583119,-0.00089749693870544,-0.00051732093561440999,-0.00031981142819859001,-0.00027235259767622,-0.00018040309078060001,-5.9890706324950003e-05,-3.4726617741399001e-05,-8.9395442046225003e-05,-4.7346613428089998e-05,7.1363596362062002e-05,5.6331173254874999e-05,-6.8987807026132995e-05,-5.7302790082758001e-05,6.6854059696197998e-05,6.5457948949187994e-05,-3.9455873775296001e-05,-4.7710651415399997e-05,2.6816196623258001e-05,9.539434540784e-05,0.00016494288865943001,0.00031633558683096999,0.00053347693756222996,0.00053950294386595,0.00036945866304450003,0.00049711996689439004,0.00087606039596721996,0.00097432837355882005,0.00083584140520543001,0.00090744462795556004,0.0011542104184627999,0.0012181688798591,0.0011283510830253001,0.0012104103807360001,0.0014371210709214,0.0014845738187432001,0.0013794765109196,0.0014457736397162,0.0016572745516896001,0.0016900007613003,0.0015696253394708001,0.0016201601829380001,0.0018164498033001999,0.001835276838392,0.0017008677823468999,0.001727451919578,0.0018916871631518,0.0018790981266648,0.0017129185143857999,0.0017150368075817999,0.0018631363054737,0.0018535536946728999,0.0017070244066417,0.0017161731375380999,0.0018614510772750001,0.0018598492024466001,0.0017301199259236,0.0017546791350469,0.001915225526318,0.0019293195800856001,0.0018148110248147999,0.001854968490079,0.0020320632029325,0.0020545769948511999,0.0019397630821912999,0.0019707581959664999,0.0021310662850738001,0.0021373601630329999,0.0020059873349965,0.0020293295383453001,0.0021912164520472002,0.0022001995239407002,0.0020714090205728999,0.0020758705213666001,0.0022002693731337998,0.0022019443567841998,0.0020930238533765,0.0021158379968256001,0.0022581242956221,0.0022571105509995998,0.0021258951164782,0.0021564513444900998,0.0023351770360023,0.0023614407982677,0.0022478955797850999,0.0022671679034829001,0.0024081696756184001,0.0024175201542675001,0.0023056813515722999,0.0023345535155386002,0.0024936746340245,0.0025129735004157001,0.0024022846482694002,0.0024127319920807999,0.0025356519035994998,0.0025393150281161,0.0024316417984664002,0.0024430463090539,0.0025659762322903,0.0025692475028336,0.0024602070916443998,0.0024798507802188002,0.0026208986528218001,0.0026326314546167998,0.0025220825336874,0.0025398989673704,0.0026795864105225,0.0027002859860659001,0.0026078384835273001,0.0026326405350119001,0.0027694695163518,0.0027886927127838,0.0026963963173329999,0.0028338176198303999,0.0031935335136949999,0.0033934691455214999,0.0034393367823213001,0.0035598897375166,0.0037517794407904001,0.0038385556545108999,0.0038224586751312,0.0038177520036697002,0.0038233529776335001,0.0037851638626307002,0.0037042924668639998,0.0037284803111106001,0.0038556328509003002,0.0038242249283939999,0.0036369950976223001,0.0036536506377161,0.0038715533446521001,0.0039225276559590998,0.0038086785934865002,0.0039162812754511998,0.0042437873780726996,0.0044106869027018998,0.0044178124517201996,0.004549459554255,0.0048054126091300999,0.0049830195493995996,0.0050821416079997999,0.0052747102454304999,0.0055611743591726,0.0057446029968560002,0.0058242017403244998,0.0060039991512895003,0.0062853335402906002,0.0063944980502129,0.0063291713595389999,0.0064467443153262,0.0067502469755708998,0.0069049624726176002,0.0069069466553628002,0.0071882456541061002,0.0077549219131470004,0.0080451359972357993,0.0080514987930654994,0.0082800285890697999,0.0087371338158846006,0.0090943491086364001,0.0093485666438936996,0.0095630791038275008,0.0097387554123998001,0.0098081836476922001,0.0097678704187273997,0.0098960921168327002,0.0101995235309,0.010361775755882,0.010376426391304001,0.010475926101208,0.010665070265532,0.010776734910905,0.010805803351103999,0.010984869673848,0.011321997269987999,0.011475805193186001,0.011435138061643001,0.011613990180194,0.012027543038130001,0.012118948623538,0.011868984438479,0.011878730729221999,0.012168169021605999,0.012181062251329,0.011898191645741,0.011832473799585999,0.012002210132778,0.011948714964092,0.011655769310891999,0.011485011316836,0.011447579599916999,0.011334529146551999,0.011132611893116999,0.011280965991318,0.011802571825683001,0.012120661325753001,0.012211333028972,0.012526641599834,0.013084417209029,0.013575256802141999,0.013986362144351,0.014548987150192001,0.015276278369129001,0.015876764431596,0.016337072476744999,0.016876837238669,0.017508650198579001,0.017981197685003,0.018282866105437001,0.018564026802778001,0.01882690563798,0.019153255969286,0.019555730745195999,0.019705059006810001,0.019582659006119,0.019406566396356,0.019167443737388001,0.019407738000153999,0.020175745710731,0.020563360303640001,0.020517151802778001,0.020721696317196,0.021208655089140001,0.021704612299799999,0.022199057042598998,0.022762233391403999,0.023399189114570999,0.024031342938541998,0.024659205228089998,0.025176828727126,0.025571420788764999,0.026074182242154999,0.026703391224146,0.027253841981292,0.027734864503144999,0.027669295668602,0.027006391435862,0.026490043848753,0.026164039969444001,0.025682028383016999,0.025010995566844999,0.024668879806995,0.0247025154531,0.024518882855773,0.024072105064988001,0.023829707875848,0.023816112428904,0.023927144706249001,0.024157736450434002,0.024545723572373002,0.025089930742979001,0.025870574638247001,0.026906926184893001,0.027861343696713,0.028703389689325998,0.029726143926381999,0.030952800065279,0.032191220670937999,0.033433895558119001,0.034679781645535999,0.035949368029833,0.036787152290344002,0.037143766880034998,0.037515573203564002,0.037948757410049001,0.038000736385584002,0.037612915039062,0.037479788064956998,0.037652902305126003,0.037913672626019003,0.038280107080936002,0.038198504596948998,0.037588074803352002,0.037334203720093002,0.037522375583649001,0.037537902593612997,0.037355314940213998,0.036776881664990997,0.035728298127650999,0.035291474312544001,0.035592816770077002,0.035607375204563002,0.035261139273643001,0.034749165177344998,0.034032732248305997,0.033945314586162997,0.034613970667124003,0.034831069409847003,0.034479249268770003,0.034214030951261999,0.034056868404150002,0.034277532249688998,0.034912966191769,0.035772144794464,0.036882374435663001,0.037565290927886998,0.037692297250032002,0.038570083677768999,0.040379967540502999,0.041671592742204999,0.042293414473533998,0.043079856783152001,0.044102706015110002,0.045052424073219001,0.045892000198364001,0.046941120177506998,0.048266824334860001,0.049175892025232003,0.049566276371479,0.050215970724821,0.051235351711512001,0.051803991198539998,0.051815073937177998,0.051954761147499001,0.052291799336672003,0.052564918994904002,0.052775613963604001,0.052669908851384999,0.052213348448276999,0.051571611315011999,0.050761770457029003,0.04967812821269,0.048274718225001997,0.047100923955441,0.04625041410327,0.045062307268381001,0.04344454780221,0.041918948292732003,0.040523920208215998,0.039273966103792003,0.038164239376783003,0.037327133119106001,0.036772128194570999,0.036548621952533999,0.036678325384855,0.036959610879420998,0.037373658269643999,0.037937909364699998,0.038659822195768002,0.039423998445272002,0.040192052721976998,0.041347678750753,0.042992971837521002,0.044282272458075998,0.045093301683664003,0.045974250882863998,0.046973899006843997,0.048070184886456001,0.049309179186820998,0.050137959420681,0.050440907478332998,0.050975363701581997,0.051869612187147002,0.052393425256014002,0.052406080067158002,0.052805427461863001,0.053731199353933001,0.054556094110011999,0.055239826440810998,0.055582530796528001,0.055506285279989,0.055601164698600998,0.055953752249479002,0.056241974234581001,0.056415073573588999,0.056753590703011003,0.057324614375830002,0.057661224156618,0.057670358568430002,0.057881072163582001,0.058402739465236997,0.058588888496161,0.058318860828876003,0.058194916695356001,0.058293048292398002,0.058439388871193002,0.058622475713491003,0.058809258043766001,0.058958012610674002,0.059503082185983998,0.060591902583838002,0.061145685613154997,0.060936342924832999,0.061141263693571,0.061984851956367,0.062366072088480003,0.062035359442233998,0.062422309070826,0.063812032341956995,0.064882092177868,0.065443806350231004,0.066016018390656003,0.066712930798530995,0.066798351705074005,0.066061109304428003,0.065785944461822995,0.066190071403980005,0.066629745066165993,0.067104764282702997,0.066962450742722002,0.066012658178806,0.065257295966148002,0.064871974289417003,0.064261689782143,0.063311547040938998,0.062529072165489002,0.061983276158571,0.061574209481478001,0.061308246105909001,0.061081182211636997,0.060906283557415002,0.060490999370813002,0.059714853763580003,0.059361889958382,0.059627383947371999,0.059597577899693999,0.05908827111125,0.058786053210497,0.058801114559174,0.058857265859842002,0.058934386819601003,0.058945104479789998,0.058834630995988998,0.058968544006348003,0.059426736086607,0.059954769909381998,0.060579188168048997,0.060770876705647001,0.060368988662957999,0.060130968689918997,0.060228884220123,0.059986628592014,0.059250295162200997,0.058629501610993999,0.05822129547596,0.057858150452375003,0.057531971484423003,0.057207904756069003,0.056936345994473003,0.056194312870502,0.054812222719192998,0.053575821220875001,0.052618093788623997,0.051693774759769003,0.05070997402072,0.050282299518584997,0.050591781735419998,0.050837516784668003,0.050791446119547001,0.051478534936904997,0.053185351192951001,0.054667688906193002,0.055573716759682,0.057429138571023997,0.060647897422314002,0.063595414161682004,0.065993785858154005,0.068254977464676,0.070447385311127,0.072300449013709994,0.073750339448451996,0.075044937431811995,0.076350592076777996,0.076567307114600996,0.075358785688876995,0.074036985635757002,0.072852186858653994,0.071307644248009006,0.069263972342013994,0.067370623350143002,0.065733797848225001,0.064290948212146995,0.063012599945067999,0.062167633324861998,0.061868503689766,0.061574187129736002,0.061122503131628002,0.061129029840230997,0.061768550425768003,0.062402833253145003,0.062881313264370006,0.063632652163505998,0.064782023429870994,0.065854780375957003,0.066808469593525002,0.067407213151454995,0.067598506808281,0.067377395927905995,0.066676467657088997,0.065952166914940005,0.065330401062965004,0.064439602196217,0.063124142587185003,0.062134142965078,0.061649039387702997,0.061283934861422001,0.060988344252109999,0.060744777321814998,0.060525432229041998,0.060458477586507998,0.060569345951080003,0.060842547565698998,0.061311695724726001,0.061728060245513999,0.062011025846004,0.062417212873697003,0.063023678958415999,0.063578896224498999,0.064043268561362998,0.064412124454975003,0.064708672463894001,0.064713768661022006,0.064343996345996995,0.063883520662785007,0.063373439013958005,0.062864609062671994,0.062375146895647,0.061880256980658001,0.061326447874308,0.061102971434592999,0.061438266187906002,0.061241004616021999,0.060134988278151003,0.059303827583789999,0.058967225253582001,0.059038188308476999,0.059588365256785999,0.060207404196261999,0.060800462961196997,0.061466578394174999,0.062216509133577,0.063044309616089006,0.063985615968704002,0.064800836145878005,0.065431132912635998,0.065936349332333,0.066289044916629999,0.066734872758389005,0.067451499402522999,0.067584797739982994,0.066861055791377993,0.065966278314589996,0.065035380423069,0.063953660428524003,0.062676824629307001,0.061463087797165,0.060442037880420997,0.059094239026307997,0.057192344218493001,0.055544223636389001,0.054330449551344001,0.053423959761858,0.052917666733264999,0.052176248282193999,0.050991758704185,0.049807876348494998,0.048691593110561003,0.047699108719826001,0.046842876821756002,0.046187069267035002,0.045728202909230999,0.045615002512931997,0.045967429876328,0.046257525682449001,0.046369452029466997,0.046318382024765001,0.046050488948822001,0.045825347304343997,0.045738011598587001,0.045554105192422999,0.045247476547956002,0.044690597802400998,0.043775521218777001,0.042954038828610999,0.042375843971968002,0.041721239686011997,0.040904339402913999,0.040088675916194999,0.039303585886954998,0.038547169417143,0.037823744118214001,0.037124767899513002,0.036416593939066003,0.035899743437767001,0.035662580281495999,0.035457815974950999,0.035231351852416999,0.034994505345820999,0.034716293215752002,0.034555938094854001,0.034584421664475999,0.034603834152221999,0.034574814140797001,0.034474447369576,0.034246839582919998,0.034156795591116,0.034312147647142001,0.034441124647856002,0.034439213573933002,0.034584783017634999,0.034949738532305,0.035471167415379999,0.036186676472425003,0.036841571331024003,0.037361714988946998,0.037803106009960001,0.038167323917149998,0.038478415459393997,0.038803379982710003,0.038792580366134997,0.038320075720548998,0.037603460252284997,0.036675747483968998,0.035580180585384001,0.034299552440642998,0.033034451305865999,0.031870055943727001,0.030624482780695,0.029204940423369002,0.027919575572014001,0.026871101930736999,0.025894027203320999,0.024922236800194002,0.024155285209417,0.023690368980169001,0.023243330419063998,0.0226886048913,0.022350613027810998,0.022333838045597,0.022478314116596999,0.022754574194551,0.023162646219134001,0.023740770295262,0.024245213717221999,0.024549381807446001,0.024985970929265001,0.025677932426333001,0.026394203305244002,0.027115635573864001,0.027673071250318999,0.027995459735393999,0.028170034289360001,0.028196837753057001,0.028158502653241001,0.028092324733733999,0.027937205508351,0.027700366452335999,0.027265556156635,0.026528185233474,0.025867028161883,0.025441767647862001,0.024937400594353999,0.024253439158200999,0.02354109659791,0.022856498137115999,0.022056087851523999,0.021014509722589999,0.020209545269608001,0.019849143922329001,0.019528269767761001,0.019116427749394999,0.018801823258400002,0.018652528524399001,0.018519617617129999,0.018390391021967,0.018127880990505,0.017587738111615001,0.017292467877268999,0.017536874860524999,0.017544999718666,0.017003754153848,0.016469154506922001,0.016097469255328001,0.015759242698549999,0.015447219833732,0.015108912251890001,0.014680625870824001,0.014396905899048001,0.01437923964113,0.014351624064147001,0.014205023646355,0.014127282425761001,0.014184368774295001,0.014270009472966,0.014353371225297,0.014464102685452,0.014604372903705001,0.014792125672102001,0.015074907802045,0.015243984758854001,0.015194404870272,0.015135560184717,0.015173394232988,0.015048394910990999,0.014641392044722999,0.01418779976666,0.013782371766865,0.013257439248264001,0.012516794726253,0.011825757101177999,0.011283189989626,0.010780490934849001,0.010272673331201,0.0098812254145740994,0.0097014652565121998,0.0094360122457146992,0.0089254509657621002,0.0085096703842282,0.0083252275362611008,0.0081685474142432005,0.0079793781042098999,0.0078082573600113002,0.0076604769565165,0.0075492598116397996,0.0074959774501622001,0.0074245510622859001,0.0072947419248520998,0.0071848263032734004,0.0071356920525431997,0.0070564784109592004,0.0069210729561745999,0.0067258877679706001,0.0064441277645528004,0.0061746975407004001,0.0059585999697446997,0.0057560466229916001,0.0055720121599734003,0.0053448895923793004,0.0050244261510670003,0.0047426037490368002,0.0045604319311678002,0.004384039901197,0.0041756485588848999,0.0039953258819877997,0.0038560433313251001,0.0037745421286671998,0.0037793382070959,0.0037786222528666002,0.0037334025837481,0.0036821376997977001,0.0036199265159666998,0.0036064651794731999,0.0036770689766854,0.0037732212804258,0.0038816423621029,0.0039876908995211003,0.0040855831466615001,0.0041636577807367004,0.0042121126316487997,0.004249875433743,0.0042867767624557001,0.0043050055392087,0.0043089720420538997,0.0042534051463007996,0.0041050608269870004,0.0039352034218609003,0.0037656151689589002,0.0036004933062941001,0.0034497864544392001,0.0032942374236882002,0.0031184805557132001,0.0029642940498887998,0.0028441112954170002,0.0027669621631503001,0.0027500877622514998,0.0027435845695436001,0.0027262708172202002,0.0027150753885508,0.0027168528176843999,0.0027144195046276002,0.0026994596701115001,0.0026825957465917002,0.002665281528607,0.0026539252139627999,0.0026536188088357002,0.0026553561910987,0.0026594824157655001,0.0026513703633099998,0.0026153179351240002,0.0025935298763216002,0.0026098615489899999,0.0026255189441143998,0.0026217265985905998,0.0026283790357410999,0.0026664538308977998,0.0026842954102903999,0.0026489975862204998,0.0026241585146636001,0.0026424683164805,0.0026543999556452001,0.0026357474271208,0.0026251813396811,0.0026417551562189999,0.0026562465354799999,0.0026566253509372,0.002655332442373,0.0026594626251607999,0.0026516052894294002,0.0026156930252909999,0.0025937345344572999,0.0026139800902456002,0.0026223573368042998,0.0025889470707624999,0.0025615449994801998,0.0025648451410234,0.0025602478999644999,0.0025264588184654999,0.0025005235802382001,0.0025037946179508998,0.0024991517420858002,0.0024633260909468001,0.0024411228951067001,0.0024612371344118998,0.0024696644395590002,0.0024322548415511998,0.0024120972957461999,0.0024469592608511001,0.0024723659735173,0.0024523183237760999,0.0024437587708234999,0.0024811017792672001,0.0025014206767082002,0.0024666478857397998,0.0024412011262029002,0.0024632476270199,0.0024683275260031002,0.0024162968620657999,0.0023791063576936999,0.0024006031453608998,0.0024075314868242,0.0023596927057952001,0.0023151398636400999,0.0023050459567456999,0.0022817587014288001,0.0022120047360659001,0.0021645429078490002,0.0021874497178942,0.0021922620944679,0.0021215728484094,0.002074207412079,0.0021076092962175998,0.0021366069559008,0.0021147658117114999,0.0021091965027153002,0.0021609533578157,0.0021985697094351001,0.0021752824541181001,0.0021716875489800999,0.0022421840112655999,0.0022897815797478,0.0022524797823280001,0.0022301729768515002,0.0022812106180935998,0.0023208782076836001,0.0023039088118821001,0.0022895324509590999,0.0023118196986616,0.0023162574507295999,0.0022667825687677002,0.0022251841146499001,0.0022294982336461999,0.0022237936500460001,0.0021737478673458,0.0021337301004677998,0.0021400600671768002,0.0021309694275260002,0.0020643051248044001,0.0020106635056436001,0.0020142260473222,0.0020102895796298998,0.0019603390246630001,0.0019200079841538999,0.0019221168477088,0.0019200862152501999,0.0018868179759011,0.0018599919276312,0.0018648020923138001,0.0018577530281617999,0.0018058377318083999,0.0017688000807538999,0.0017894844058901,0.0017976192757487,0.0017444032710045999,0.0017090083565563,0.0017462213290855,0.0017681148601695999,0.0017177506815641999,0.0016771950758994001,0.0016956895124167,0.0017073166090995,0.0016687425086274999,0.0016498968470842,0.0017001391388475999,0.0017408637795597,0.0017224667826667001,0.0017105835722759,0.0017449650913477,0.0017705109203234,0.0017514061182736999,0.0017411295557395001,0.0017775184242055,0.0017999418778345,0.0017664240440354001,0.0017391727305949001,0.0017602590378374,0.0017674774862826001,0.0017167254118249,0.0016773556126282001,0.0016996288904919999,0.0017053351039067,0.0016361073357984001,0.0015860813437029999,0.0016239332035184,0.0016450803959742,0.0015726679703221,0.0015271417796612001,0.0015957579016685,0.0016478165052830999,0.0015936662675813001,0.0015583699569106,0.0016256601084024,0.0016794000985101,0.0016418033046648,0.0016202427214012001,0.0016923939110711,0.00173838599585,0.0016680584521963999,0.0016186307184398001,0.0016888893442228001,0.0017385168466717,0.0016724261222407001,0.0016166918212548,0.0016581276431680001,0.0016740278806536999,0.0015734733315185001,0.0014930253382771999,0.0015284079127014,0.0015539835439995001,0.0014862981624901,0.0014335783198476,0.0014748001703992,0.0014910682803020001,0.0013887477107345999,0.0013109032297507,0.0013623494887725,0.0014021467650308999,0.0013315498363226999,0.0012827422469853999,0.0013523022644222,0.00140290427953,0.001333415042609,0.0012826690217480001,0.0013500450877472999,0.0014037905493750999,0.0013486965326592001,0.0013147260760888,0.0013992534950375999,0.001465494162403,0.0014095020014792999,0.0013765596086158999,0.0014772112481296,0.0015577635494992,0.0015049864305183001,0.0014671918470412001,0.0015514321858063,0.0016181295504794,0.0015644649975002001,0.0015281991800292999,0.0016143309185280999,0.0016783882165328,0.0016106816474348001,0.0015572076663375001,0.0016259062103927001,0.0016778315184638,0.0016132728196680999,0.0015556674916297,0.0015958955045789001,0.0016139928484335999,0.0015129779931158001,0.0014331252314149999,0.0014872041065245999,0.0015231413999571999,0.0014233898837119,0.0013415805296971999,0.0013954936293884999,0.0014316370943560999,0.0013300233986228999,0.0012507651699707001,0.0013206513831392,0.0013712667860090999,0.0012709698639810001,0.0011896967189385999,0.0012573713902383999,0.0013109712162986001,0.0012249479768798,0.0011604109313338999,0.0012431523064151001,0.0013122170930728,0.0012395933736116,0.0011927993036807,0.0013087121769786,0.0014048689045011999,0.0013327943161129999,0.0012849500635639,0.0014187399065122,0.0015268701827153999,0.0014442029641940999,0.0013746005715802,0.0014748456887901001,0.0015563542256132,0.0014734821161255,0.0014044700656086,0.0014904947020113,0.0015552702825516,0.0014573541702702999,0.0013728502672166001,0.0014454432530329,0.0014925980940461,0.0013616284122691001,0.0012497878633440001,0.0013196349609643,0.0013706195168197001,0.0012398809194564999,0.0011277212761343,0.0011953276116401,0.0012491472298278999,0.0011285761138424,0.0010382845066487999,0.0011528118047863,0.0012511304812506,0.0011486667208374,0.0010697186226025,0.0011972227366640999,0.0013136779889464001,0.0012446460314095001,0.0011926225852220999,0.0013245466398075,0.0014352214056997999,0.0013505236711353001,0.0012836977839470001,0.0014200228033587,0.0015253090532497001,0.0013932236470282,0.0012823858996853,0.0014163107844069999,0.0015249047428369999,0.001381266862154,0.0012504953192547001,0.0013490072451532,0.0014330650446936,0.0013027933891862999,0.0011898669181392,0.0012914878316224001,0.0013716362882406001,0.0012218398042023,0.0010987836867571001,0.0012303153052926001,0.0013419433962554,0.0011973191285505999,0.0010678345570341,0.0011832331074402001,0.0012806028826162,0.0011348618427292,0.001006810227409,0.0011258556041867001,0.0012188642285764001,0.0010419241152704001,0.00088406336726620999,0.00099981378298252994,0.0010968708666040999,0.00091633474221452995,0.0007627205341123,0.00090758694568648999,0.0010369057999924001,0.00087548105511813998,0.00073250191053376003,0.00087848049588500998,0.0010064119705930001,0.00083747564349323999,0.00070325250271708001,0.00090962677495554003,0.001099479268305,0.00095280294772237995,0.00082552811363711997,0.0010349556105211,0.0012212368892505999,0.0010613254271447999,0.00091643142513931004,0.0011081809643656,0.0012820017291233,0.0011190176010132001,0.00097769615240395004,0.0011924764839931999,0.0013727468904108,0.0011513162171468,0.00094587996136397004,0.0011342093348503,0.0013120414223522,0.00112663093023,0.00094560580328106999,0.0010938065825029999,0.0012193957809359,0.00099647010210901,0.00079285027459263997,0.00096266181208192999,0.0010965737747027999,0.00081951497122644999,0.00051493843784555999,0.00050884723896161004,0.00048385397531091999,0.00013062151265331,-0.00015386614541057001,4.1913852328435e-05,0.00024361786199734,9.5065624918788993e-06,-0.00021398134413175,-1.6439487808384001e-05,0.00015129821258597,-0.00012838313705288001,-0.00042964474414475002,-0.00036332692252472,-0.00033943029120564,-0.00078493007458746,-0.0011609571520239,-0.00090810784604399995,-0.00064128346275538,-0.00093811564147472002,-0.0012208807747811001,-0.00095494079869240999,-0.00070226419484243003,-0.00099831842817365993,-0.0012819145340472,-0.0010206205770373,-0.00076303799869492997,-0.0010352284880355,-0.0012813262874261,-0.00097495608497411002,-0.00063968863105400996,-0.00077903125202283003,-0.00085207959637046001,-0.00027474929811433001,0.00024535885313526002,-2.9239541618152999e-05,-0.00033526335028000002,4.4568208977580003e-05,0.00042776399641298002,0.00015520080341958,-5.9860427427338003e-05,0.00052764179417863,0.0010995395714417,0.00083671789616346001,0.00054979330161586003,0.0010099271312356,0.0014652373502030999,0.0011752598220482,0.00091598532162606998,0.0014801262877882,0.0020450358279049002,0.0017770102713257001,0.0015261051012203,0.0022397520951926999,0.0027771843597293,0.0040894802659750002,0.0048824548721313,0.0060414723120630004,0.0073757143691181998,0.0089690433815121998,0.010787328705192001,0.012993507087231,0.015547214075923001,0.019026452675462002,0.023814721032977,0.030478736385703,0.039800547063350997,0.051560971885920001,0.065692603588103998,0.082518123090267001,0.10234217345715001,0.12517890334129,0.15118470788002,0.18024815618991999,0.21251657605171001,0.24736960232258001,0.28433379530906999,0.32304430007934998,0.36306747794151001,0.40407091379165999,0.44570058584213001,0.48752474784851002,0.52904897928238004,0.57002162933349998,0.61038410663605003,0.64901566505431996,0.68451440334320002,0.71742230653762995,0.74796581268311002,0.77574330568313998,0.80025076866150002,0.82193070650100997,0.84143817424774003,0.85773724317551003,0.86963629722595004,0.87800365686417003,0.88325279951096003,0.88570994138717996,0.88606220483779996,0.88377749919891002,0.87833583354949996,0.87025767564774004,0.86003726720810003,0.84737056493759,0.83166366815567005,0.81417387723922996,0.79631972312927002,0.77743774652481001,0.75712108612061002,0.73587775230408004,0.71371173858643,0.69184148311615001,0.67209219932555997,0.65317893028259,0.63363522291183005,0.61539655923842995,0.60051953792571999,0.58790081739426003,0.57660746574402,0.56785303354262995,0.56294232606887995,0.56115758419036998,0.56204324960708996,0.56590390205383001,0.57299107313155995,0.58311694860457997,0.59635680913925004,0.61213529109955001,0.62968468666077004,0.64935123920440996,0.67162549495696999,0.69545471668242997,0.71965873241425005,0.74457401037215998,0.77054381370544001,0.79646933078766002,0.82095760107039994,0.84460955858231002,0.86788916587830001,0.89003354310989002,0.91021782159804998,0.92867368459702004,0.94550329446793002,0.96032637357712003,0.97274392843246005,0.98268890380858998,0.98968952894211004,0.99441802501678001,0.99786621332169001,0.99905109405518,0.99704146385193004,0.99212342500687001,0.98394536972045998,0.97348171472549005,0.96211004257202004,0.94897705316544001,0.93340253829955999,0.9158046245575,0.89626479148865001,0.87528342008590998,0.85358363389969005,0.83099073171616,0.80709218978882002,0.78320848941803001,0.76138681173324996,0.74014312028884999,0.71772545576096003,0.69598060846329002,0.67686980962752996,0.65959918498992998,0.64385557174682995,0.62981837987900002,0.61750066280365001,0.60716789960860995,0.59910297393798995,0.59348779916762995,0.59089726209641003,0.59070748090743996,0.59231764078140003,0.59576654434204002,0.60060656070708995,0.60755103826523005,0.61786246299743997,0.63016343116759999,0.64312267303466997,0.65677493810653997,0.67063814401626998,0.68469494581223,0.69877541065215998,0.71274548768997004,0.72653263807296997,0.73965460062027,0.75130593776703003,0.76182913780212003,0.77166897058487005,0.77998405694962003,0.78549504280089999,0.78906178474426003,0.79179471731186002,0.79244792461394997,0.78923463821411,0.78359669446945002,0.77724081277847001,0.76893955469131003,0.75735068321228005,0.74340784549713002,0.72798317670821999,0.71073293685912997,0.69124287366866999,0.67030519247054998,0.64887803792953003,0.62691152095795,0.60482567548751998,0.58237314224242998,0.55912530422211004,0.53576904535294001,0.51317399740219005,0.49114140868187001,0.46951407194138001,0.44892752170562999,0.43038445711135997,0.41346469521522999,0.39802798628807001,0.38396182656288003,0.37087237834929998,0.35922175645827997,0.34959694743156,0.34177657961844998,0.33593258261681003,0.33141142129897999,0.32707911729813,0.32360267639160001,0.32157671451568998,0.32074311375617998,0.32092291116714,0.32224890589714,0.32509201765059997,0.32879307866096003,0.33232942223549,0.33622840046883001,0.34110379219054998,0.34625864028931003,0.35081723332405002,0.35502058267593001,0.35892763733864003,0.36234596371651001,0.36501267552375999,0.36691561341286,0.36800661683083002,0.36806464195250999,0.36661908030509999,0.36396053433418002,0.36053639650344999,0.35580646991729997,0.34896531701088002,0.34044891595839999,0.33061730861664002,0.31937247514724998,0.30656641721724998,0.29259473085402998,0.27808105945587003,0.26284381747246,0.246910110116,0.23018535971642001,0.2125459164381,0.19396060705185,0.17389918863772999,0.15346083045006001,0.13455186784267001,0.1161528006196,0.097132615745067999,0.078399270772934002,0.061004161834716998,0.044698804616928003,0.029757827520370001,0.015652552247047001,0.0012011080980301001,-0.012437065131961999,-0.023553028702736001,-0.033059641718863997,-0.041792672127484998,-0.049459990113973999,-0.055919181555509997,-0.061265598982573,-0.065682411193848003,-0.068944506347178997,-0.070566825568675995,-0.071046702563762998,-0.071063369512557997,-0.070428974926472002,-0.068799175322055997,-0.067034304141998,-0.066978439688683,-0.067219369113445004,-0.065634682774543998,-0.063718251883984001,-0.063179500401019995,-0.063625484704970994,-0.065416596829890997,-0.067934513092041002,-0.070038802921772003,-0.072378762066363997,-0.075456015765667003,-0.079478405416012005,-0.085208609700202997,-0.092205218970776007,-0.10028032958508,-0.10888954997063,-0.11653335392475,-0.1243851184845,-0.13400495052337999,-0.14485125243663999,-0.15681861341,-0.16961616277694999,-0.18271431326866,-0.19605018198490001,-0.20907796919346,-0.22225713729857999,-0.23645390570163999,-0.2508989572525,-0.26437401771544999,-0.27751049399375999,-0.29117080569267001,-0.30459946393967002,-0.31651026010513,-0.32772460579871998,-0.33940058946608997,-0.35083967447281,-0.36123269796370999,-0.37080034613608998,-0.37947803735732999,-0.38747239112853998,-0.39520737528800998,-0.40248563885688998,-0.40918746590614002,-0.41521695256232999,-0.42019864916800997,-0.42448127269745001,-0.42859655618668002,-0.43238037824630998,-0.43579125404357999,-0.43880748748779003,-0.44137009978294001,-0.44348087906837003,-0.44507253170013,-0.44624602794647,-0.44705584645271002,-0.44775003194808999,-0.44881314039230003,-0.4502729177475,-0.45277789235115001,-0.45546472072601002,-0.45673087239264998,-0.45723173022269997,-0.45720502734183999,-0.45722007751464999,-0.45869493484496998,-0.46112194657326,-0.46426808834076,-0.46801060438156,-0.47193181514740001,-0.47620096802710998,-0.48088428378105003,-0.48611715435982,-0.49210542440414001,-0.49906420707702998,-0.50795245170592995,-0.51774442195892001,-0.52637422084808005,-0.53505831956863004,-0.54575866460800004,-0.55713266134261996,-0.56718981266021995,-0.57658451795578003,-0.58547431230545,-0.59425991773605003,-0.60428369045258001,-0.61445105075836004,-0.62281483411788996,-0.63033002614974998,-0.63818669319152999,-0.64586740732193004,-0.65272319316864003,-0.65917801856994995,-0.66588217020035001,-0.67259919643402,-0.67916113138198997,-0.68558257818222001,-0.69176018238068004,-0.69781380891800004,-0.70418018102645996,-0.71030026674270996,-0.71471869945526001,-0.71861702203750999,-0.72443276643752996,-0.73055166006088001,-0.73432821035384999,-0.73687314987182995,-0.73930871486663996,-0.74137771129607999,-0.74317020177840998,-0.74450886249542003,-0.74501508474349998,-0.74481046199798995,-0.74386811256409002,-0.74239993095398005,-0.74076747894286998,-0.73915112018585005,-0.73846238851546997,-0.73794060945510997,-0.73579019308089999,-0.73341345787047996,-0.73350197076796997,-0.73479557037354004,-0.73557829856873003,-0.73661953210830999,-0.73883491754532005,-0.74200809001922996,-0.74623882770537997,-0.75127321481705001,-0.75636178255080999,-0.76205188035964999,-0.76954340934752996,-0.77800500392913996,-0.78585326671599998,-0.79385590553284002,-0.80331200361251998,-0.81334114074706998,-0.82231545448303001,-0.83092093467712003,-0.84005993604660001,-0.84930366277695002,-0.85819172859191994,-0.86660325527190996,-0.87375408411026001,-0.88024049997330001,-0.88746786117554,-0.89443767070769997,-0.89926832914351995,-0.90264493227005005,-0.90512835979462003,-0.90680867433547996,-0.90834200382232999,-0.90937507152556996,-0.90939515829086004,-0.90848785638809004,-0.90642869472503995,-0.90356099605560003,-0.90068018436431996,-0.89755475521088002,-0.89401090145110995,-0.89015829563141002,-0.88607853651046997,-0.88197857141494995,-0.87843096256256004,-0.87536638975143,-0.87295675277710005,-0.87114006280899003,-0.86995869874954002,-0.86920815706252996,-0.86816608905792003,-0.86736792325973999,-0.86796319484711004,-0.86945593357086004,-0.87108868360518998,-0.87320202589035001,-0.87642663717269997,-0.88035178184509,-0.88422322273253995,-0.88819330930710005,-0.89217990636825995,-0.89629697799682995,-0.90094310045241999,-0.90576457977295,-0.90990155935286998,-0.91374886035919001,-0.91807001829146995,-0.92236542701721003,-0.92541587352752996,-0.92798721790313998,-0.93160670995712003,-0.93577277660369995,-0.94010734558105002,-0.94445621967315996,-0.94811487197875999,-0.95131784677505005,-0.95420897006989003,-0.95693022012711004,-0.96014940738678001,-0.96339446306229004,-0.96549153327941994,-0.96709233522414995,-0.96968615055083995,-0.97238469123839999,-0.97316026687622004,-0.97306030988693004,-0.97424608469009,-0.97567105293274003,-0.97538226842880005,-0.97411477565765003,-0.97270566225052002,-0.97126853466034002,-0.97097438573837003,-0.97097414731979004,-0.96913707256317005,-0.96649992465973,-0.96516197919846003,-0.96415251493454002,-0.96152079105376997,-0.95822292566299005,-0.95607006549835005,-0.95450878143311002,-0.95298326015472001,-0.95157361030579002,-0.95022583007812,-0.94889718294143999,-0.94725018739699995,-0.94565331935883001,-0.94522857666016002,-0.94540345668793002,-0.94504177570342995,-0.94447541236876997,-0.94386017322539995,-0.94348156452178999,-0.94466024637222001,-0.94652724266052002,-0.94690734148026001,-0.94671130180358998,-0.94760793447494995,-0.94900655746460005,-0.95004045963286998,-0.95091265439987005,-0.95165705680847001,-0.95241630077362005,-0.95366328954696999,-0.95530503988266002,-0.95765560865402,-0.96009850502014005,-0.96045774221419999,-0.95981496572494995,-0.96049040555954002,-0.96172314882277998,-0.96245884895324996,-0.96294134855269997,-0.96348267793654996,-0.96374404430389005,-0.96251684427260997,-0.96050441265106001,-0.95931977033615001,-0.95858156681061002,-0.95820575952529996,-0.95792746543884,-0.95663088560104004,-0.95485913753509999,-0.95377808809279996,-0.95307403802872004,-0.95251822471618997,-0.95199084281920998,-0.95076978206634999,-0.94929981231688998,-0.94885879755019997,-0.94882309436797996,-0.94766920804976995,-0.94601368904114003,-0.94520014524460005,-0.94466274976730003,-0.94309985637664995,-0.94107246398926003,-0.94004935026169001,-0.93918025493622004,-0.93607121706009,-0.93174064159393,-0.92830753326416005,-0.92526972293854004,-0.92216265201569003,-0.91915225982666005,-0.91660255193710005,-0.91437494754791004,-0.91214615106582997,-0.91007757186890004,-0.90857905149460005,-0.90751999616623003,-0.90661662817000999,-0.90604799985885998,-0.90640044212340998,-0.90737932920455999,-0.90840280056,-0.90938305854796997,-0.90934395790099998,-0.90890318155288996,-0.91004765033722002,-0.91183674335480003,-0.91181296110152998,-0.91084259748458996,-0.91069537401198997,-0.91083025932312001,-0.91038376092911,-0.90946412086487005,-0.90782248973846003,-0.90567010641098,-0.90361112356186002,-0.90157479047775002,-0.89969521760940996,-0.89795506000518999,-0.89647805690765003,-0.89509922266006003,-0.89315706491470004,-0.89093846082687,-0.88907968997955,-0.88753014802932995,-0.88669270277023005,-0.88621348142624001,-0.88483673334122004,-0.88301074504851995,-0.88171643018723,-0.88069546222687001,-0.87952280044555997,-0.87834650278090998,-0.87765139341354004,-0.87708890438080001,-0.87538653612136996,-0.87306106090545998,-0.87154865264893,-0.87027311325072998,-0.86763840913773005,-0.86425375938416005,-0.86160188913345004,-0.85933768749237005,-0.85710173845291004,-0.85485440492630005,-0.85219109058380005,-0.84920471906661998,-0.84587568044661998,-0.84239119291305997,-0.83951300382614003,-0.83712357282639005,-0.83542060852051003,-0.83412551879883001,-0.83197122812270996,-0.82953017950057995,-0.82865297794341997,-0.82858914136886996,-0.82719790935516002,-0.82512331008911,-0.82374304533005005,-0.82272857427597001,-0.82167571783065996,-0.82050549983978005,-0.81850492954253995,-0.81595295667648005,-0.81352758407592995,-0.81117248535155995,-0.80915886163712003,-0.80736416578293002,-0.80550652742385997,-0.80354624986649004,-0.80097699165344005,-0.79807645082473999,-0.79574865102768,-0.79381942749023005,-0.79220706224441995,-0.79082125425339,-0.78916198015213002,-0.78737986087798995,-0.78588294982910001,-0.78449046611786,-0.78273296356201005,-0.78055882453918002,-0.77714383602142001,-0.77299028635025002,-0.77015054225921997,-0.76784801483153997,-0.76372241973876998,-0.75839614868163996,-0.75308686494827004,-0.74769526720046997,-0.74271845817565996,-0.73788189888,-0.73194122314453003,-0.72555285692214999,-0.72125083208083995,-0.71826738119125,-0.71458095312118997,-0.71067488193511996,-0.70751357078552002,-0.70491564273833995,-0.70267117023467995,-0.70078253746033004,-0.69920837879180997,-0.69784206151962003,-0.69601804018020996,-0.69397753477097002,-0.69259309768677002,-0.69150948524474998,-0.68951112031937001,-0.68685162067412997,-0.68380844593047996,-0.68052029609679998,-0.67799699306488004,-0.67591208219527998,-0.67335349321365001,-0.67044633626937999,-0.66701489686965998,-0.66332101821899003,-0.66067755222321001,-0.65875077247619995,-0.65681797266006003,-0.65491765737534002,-0.65260231494903997,-0.65013372898101995,-0.64868831634520996,-0.64790362119675005,-0.64662653207778997,-0.64514219760894997,-0.64424604177474998,-0.64368975162506004,-0.64269864559173995,-0.64138072729110995,-0.63979214429855003,-0.63788056373596003,-0.63531529903411998,-0.63222932815552002,-0.62917876243590998,-0.62599092721938998,-0.62201428413391002,-0.61748021841048994,-0.61330175399779996,-0.60922378301619995,-0.60432910919188998,-0.59895330667496005,-0.59437596797943004,-0.59035879373550004,-0.58647108078002996,-0.58280253410339,-0.57961529493331998,-0.57682263851166005,-0.57404458522796997,-0.57142144441605003,-0.56957536935805997,-0.56830620765686002,-0.56701064109802002,-0.56563496589661,-0.56322604417801003,-0.56015217304230003,-0.55809324979782005,-0.55651909112929998,-0.55336606502533003,-0.54910135269164995,-0.54504293203354004,-0.54096090793609997,-0.53626120090484997,-0.53122079372405995,-0.52721852064133001,-0.52394682168961004,-0.5204718708992,-0.51703131198883001,-0.51445096731186002,-0.51258349418640003,-0.51106667518616,-0.51001781225204001,-0.51012021303177002,-0.51103848218918002,-0.51102739572525002,-0.51047855615616,-0.51071661710739003,-0.51136726140975997,-0.51097476482391002,-0.50975471735000999,-0.50800305604935003,-0.50567901134491,-0.50266683101653997,-0.49902337789536,-0.49505326151848,-0.49070289731026001,-0.48577859997749001,-0.48039373755455,-0.47517240047455001,-0.47002959251403997,-0.46476897597312999,-0.45954942703246998,-0.45531433820723999,-0.45195418596268,-0.44960781931876997,-0.44809198379517001,-0.44620475172996998,-0.44418212771415999,-0.44264900684357,-0.44160288572311002,-0.44164714217186002,-0.44252347946166998,-0.44289648532866999,-0.44293925166129999,-0.44275110960007003,-0.44241228699683999,-0.44263464212418002,-0.44321790337563,-0.44337391853333002,-0.44309633970260998,-0.44155395030974998,-0.43903547525406,-0.43711590766906999,-0.43544712662696999,-0.43248516321182001,-0.42863473296165,-0.42594081163406,-0.42393887042999001,-0.42056855559348999,-0.41624161601067,-0.41257157921790999,-0.40928664803504999,-0.40551903843879999,-0.40139329433441001,-0.39722281694411998,-0.3929734826088,-0.38860556483268999,-0.38412204384804,-0.37950038909911998,-0.37476867437362998,-0.37010529637336997,-0.36551699042320002,-0.36124300956726002,-0.35721719264983998,-0.35304641723633001,-0.34883970022201999,-0.34519115090370001,-0.34201660752295998,-0.33906707167625,-0.33640310168266002,-0.33439749479294001,-0.33295640349388,-0.33153834939003002,-0.33025667071342002,-0.32974916696548001,-0.32983139157294999,-0.32942888140678001,-0.32866314053535001,-0.32764816284179998,-0.32643136382103,-0.32557523250580001,-0.32492363452910999,-0.32351550459862,-0.32151293754577998,-0.31966856122017001,-0.31780797243117997,-0.31487271189690003,-0.31105861067772,-0.30725082755089,-0.30338138341903997,-0.29959017038344998,-0.29581022262572998,-0.29145684838295,-0.28670582175254999,-0.28279322385788003,-0.27951386570929998,-0.27588501572608998,-0.27207878232001997,-0.26896879076958002,-0.26644876599312001,-0.26434311270714,-0.26253983378410001,-0.25965529680251997,-0.25599360466003002,-0.25348982214928001,-0.25182229280472002,-0.24935090541839999,-0.24628235399723,-0.24331770837307001,-0.24042606353759999,-0.23790729045868,-0.23566247522830999,-0.23288670182228,-0.22972816228866999,-0.22716794908047,-0.22499804198741999,-0.22157897055149001,-0.21730901300906999,-0.21520981192589,-0.21483209729194999,-0.21397107839584001,-0.21279861032962999,-0.21131838858127999,-0.20958811044692999,-0.20810408890247001,-0.20685295760632,-0.20621761679649001,-0.20607951283455,-0.20548620820044999,-0.20451290905475999,-0.20326833426952001,-0.20167896151542999,-0.19873394072056,-0.19470149278641,-0.19200882315636,-0.19027027487754999,-0.18695060908794001,-0.18236488103866999,-0.17807278037071,-0.17397561669350001,-0.17015312612056999,-0.16659860312939001,-0.16341382265091001,-0.16055871546268,-0.15764245390892001,-0.15469607710837999,-0.15172274410725001,-0.14875246584415,-0.14615249633788999,-0.14388751983643,-0.14193101227283,-0.14021304249763,-0.13780696690083,-0.13480181992053999,-0.13146641850471,-0.12782455980778001,-0.12441035360098,-0.12116225063801001,-0.11775822937489,-0.11421562731266,-0.11044634878635,-0.10650160163641,-0.10307821631432,-0.10006165504455999,-0.096399918198585996,-0.092227451503277005,-0.088561803102492995,-0.085305258631706002,-0.081906341016293002,-0.078418649733067003,-0.075190834701060999,-0.072185248136519997,-0.069118268787860995,-0.066022865474223993,-0.063171356916428001,-0.060531128197907999,-0.057804524898528997,-0.055036477744579003,-0.052732214331627003,-0.050810780376195998,-0.048387169837952,-0.045564610511065001,-0.043214131146668999,-0.041265334933995999,-0.039305970072745999,-0.037382736802101003,-0.036036893725395001,-0.035165246576071001,-0.03346511349082,-0.031061049550772001,-0.028849026188253999,-0.026791097596288001,-0.025117231532931002,-0.023739464581013,-0.021258058026433001,-0.017832376062870001,-0.015051809139549999,-0.01279245596379,-0.010063836351036999,-0.0070117563009261998,-0.0056548691354692,-0.0057758660987019999,-0.0051113995723426004,-0.0038132460322230998,-0.0027542759198695001,-0.0018910340731964001,-0.0010781397577375,-0.00032014586031437001,0.00040929802344181001,0.0010959377977997,0.001433550613001,0.0014650606317446,0.0018329782178625,0.0024770239833741999,0.0025436070282011999,0.0021698880009353,0.0038032513111830001,0.0071700843982398996,0.0084373950958252005,0.0078800413757563002,0.0080237463116646004,0.0087758265435695995,0.010263953357935,0.012457614764571001,0.014938054606318,0.017716977745295001,0.020652936771512,0.023768536746501999,0.027508795261383001,0.031826134771109002,0.035889789462089997,0.039769317954778997,0.044590774923562997,0.050244033336639002,0.054931882768868998,0.058726612478494998,0.061751432716846001,0.064051993191241996,0.066983163356781006,0.070443376898765994,0.072883285582065999,0.074381828308104997,0.075850024819374001,0.077223420143126997,0.077292777597903997,0.076147072017192993,0.075322434306145006,0.074765354394912997,0.074202723801136003,0.073659650981426003,0.073745116591453996,0.074444517493248,0.075975067913531993,0.078292474150658001,0.080049656331539001,0.081328622996807001,0.083722628653048997,0.087161518633366006,0.09067153185606,0.094265185296535006,0.097530633211136003,0.10048589855433,0.10335168242455001,0.10612086951733,0.10875781625509,0.11124646663666,0.11280862987041,0.11349301785231,0.11466132104397,0.11625970155001,0.11711395531893,0.11727948486805,0.11827051639557,0.12003751844167999,0.12157256901264001,0.12291743606329,0.12532398104667999,0.12874740362167,0.1320461332798,0.13524371385573999,0.13857278227806,0.14202632009982999,0.14532488584518,0.14848007261752999,0.15203770995140001,0.15596602857113001,0.15862558782100999,0.16007113456725999,0.16251696646214001,0.16590230166912001,0.16789560019970001,0.16855075955391,0.16980472207069,0.17162249982357,0.17290125787258001,0.17366530001163,0.17505595088004999,0.17705857753754001,0.17942817509174,0.18216355144978,0.18493896722794001,0.18776124715805001,0.19107566773890999,0.19487610459328,0.19882929325104001,0.20293882489203999,0.20746085047721999,0.21238838136196,0.21681992709636999,0.22076185047626001,0.22446143627167001,0.22791533172131001,0.23053151369095001,0.23231425881386,0.23376530408859,0.23488369584084001,0.23596967756748,0.23702049255370999,0.23677632212638999,0.23524141311645999,0.23490731418133001,0.23577196896076,0.23600026965140999,0.23559153079987,0.23518526554107999,0.23478102684020999,0.23501902818680001,0.23590256273745999,0.23651722073555001,0.23685640096664001,0.23833297193049999,0.24095910787582001,0.24290770292281999,0.24416629970074,0.24570427834988001,0.24752733111382,0.24943262338638,0.25142073631286999,0.25326955318451,0.25497648119925997,0.25668919086455999,0.25841110944748003,0.25985845923424,0.26102823019027999,0.26194304227829002,0.26259705424308999,0.26359668374062001,0.26495206356049,0.26626098155974998,0.26750913262366999,0.26971942186356002,0.27292993664741999,0.27496469020844,0.27577000856400002,0.27734383940696999,0.27972564101219,0.28201419115067,0.28420951962471003,0.28549355268477999,0.28583577275276001,0.28625297546387002,0.28675788640976002,0.28757080435753002,0.28870686888695002,0.28960165381432001,0.29024210572242998,0.29076582193375,0.29116809368134,0.29178330302237998,0.29261922836304,0.29368421435356001,0.29499256610870001,0.29583802819251998,0.29618436098098999,0.29709225893021002,0.29862099885941001,0.29903659224509999,0.29825469851494002,0.2983106970787,0.29929372668266002,0.29937109351157998,0.29846298694611001,0.29812189936638001,0.29841634631156999,0.29809573292732,0.29710799455643,0.29623213410378002,0.29548472166061002,0.29489928483963002,0.29445150494576,0.29520329833031,0.29723480343818998,0.29884985089302002,0.29997000098227999,0.30156525969504999,0.30367299914360002,0.30595055222510997,0.30839252471924,0.31090214848518,0.31348136067389998,0.31595164537429998,0.31830978393554998,0.32045421004294999,0.32237946987152,0.32414421439170998,0.32576102018356001,0.32685008645058,0.32735958695411999,0.32846084237098999,0.33026221394539002,0.33091005682945002,0.33028501272201999,0.32965078949928001,0.32900583744049,0.32970067858696001,0.33188208937644997,0.33324787020683,0.33365735411643999,0.33433374762535001,0.33531475067138999,0.33680611848830999,0.33885258436202997,0.34065824747085999,0.34216481447219999,0.34399768710135997,0.34622368216514998,0.34780687093735002,0.34865084290504,0.34995844960213002,0.35182321071625,0.35339906811714,0.35469081997870999,0.35470381379128002,0.35331863164902,0.35198742151259999,0.35079044103621998,0.34942811727523998,0.34785705804825001,0.34684687852858997,0.34647479653357999,0.34595027565955999,0.34522271156311002,0.34448033571242997,0.34368410706519997,0.34380468726157998,0.34494888782500999,0.34601297974585998,0.34687873721123003,0.34884217381477001,0.35206621885299999,0.35467714071273998,0.35649988055228998,0.35896104574203003,0.36219078302383001,0.36512556672096003,0.36767828464508001,0.37049278616905001,0.37368279695510997,0.37573221325874001,0.37647333741187999,0.37732860445976002,0.37843576073647001,0.37872046232223999,0.37804898619652,0.37768012285232999,0.37769153714179998,0.37812867760657998,0.37908056378365002,0.37914910912513999,0.37815675139427002,0.37753310799598999,0.37738886475562999,0.37742459774017001,0.37770801782607999,0.37681329250335999,0.37448686361312999,0.37324836850165999,0.37335720658302002,0.37341621518134999,0.37338384985924,0.37247046828269997,0.37045314908027999,0.36987745761870999,0.37107914686202997,0.37167012691498003,0.37144720554352001,0.37100380659102999,0.37030145525932001,0.37033465504646002,0.37118926644325001,0.37287852168083002,0.3755410015583,0.37716135382652,0.37741068005562001,0.37885457277298001,0.38181489706039001,0.38437733054161,0.38638788461684997,0.38808742165565002,0.38944420218468001,0.39098390936852001,0.39276415109634,0.39461907744407998,0.39656788110732999,0.39820924401282998,0.39948850870132002,0.40067389607429998,0.40178969502449002,0.40278851985931002,0.40369570255280002,0.40409052371978998,0.40385299921036,0.40414875745772999,0.40519708395004,0.40539035201072998,0.40451365709304998,0.40366116166115001,0.40299251675606002,0.40147936344147001,0.39892023801804,0.39683991670608998,0.39546731114388001,0.39356902241706998,0.39099857211112998,0.38829672336578003,0.38547915220260998,0.38282775878906,0.38034981489182002,0.37832567095757003,0.37677031755446999,0.37588489055634,0.37571620941161998,0.37599176168442,0.37670066952705,0.37769341468811002,0.37896597385406,0.38033813238143999,0.38175204396248003,0.38368031382561002,0.3862292766571,0.38873270153999001,0.39116916060447998,0.39299014210701,0.39401221275330001,0.39566746354103,0.39824962615967002,0.40000975131988997,0.40066161751746998,0.40153667330741999,0.40282371640205,0.40377798676491,0.40428453683853,0.40485367178916998,0.40550646185875,0.40660372376442,0.40831276774406,0.40926405787468001,0.40920138359070002,0.40929988026619002,0.40970566868781999,0.41008087992668002,0.41037955880165,0.41083699464798001,0.41151008009911,0.41204977035522,0.41240057349205,0.41275122761726002,0.41312447190285001,0.41348776221275002,0.41387790441513,0.41384726762772001,0.41323333978652999,0.41319945454597001,0.41400185227393999,0.41433408856392001,0.41390103101730003,0.41430521011353,0.41589757800102001,0.41692963242531,0.41710594296455,0.41743510961532998,0.41806271672249001,0.41855096817017001,0.41881850361824002,0.41922071576117997,0.41976204514503002,0.42084175348281999,0.42264744639397001,0.42389041185379001,0.42433884739875999,0.42470908164978,0.42513987421989002,0.42492923140526001,0.42378404736518999,0.42379561066628002,0.42553141713142001,0.42611008882522999,0.42497879266739003,0.42402955889701999,0.42355442047119002,0.42278921604156,0.42159402370452997,0.42054462432861001,0.41973510384559998,0.41891530156135998,0.41800236701964999,0.41756078600883001,0.41779801249504001,0.41747778654098999,0.41629484295844998,0.41553449630736999,0.41543358564376998,0.41532319784164001,0.41512888669968001,0.41482880711554998,0.41436722874641002,0.41413137316704002,0.41420584917067998,0.41433382034302002,0.41450095176696999,0.41452944278717002,0.41428780555724998,0.4147130548954,0.41612693667411998,0.41689920425415,0.41668653488159002,0.41650238633156,0.41652286052704002,0.41629788279532998,0.41574922204018,0.41508883237839,0.41433021426201,0.41355997323990001,0.41275718808174,0.41227671504021002,0.41231104731559998,0.41171753406525002,0.41023126244545,0.40862435102463002,0.40700474381446999,0.40526130795478998,0.40327474474906999,0.40199473500251998,0.40166214108467002,0.40152722597121998,0.40141412615776001,0.40193507075309998,0.40321928262710999,0.40492832660674999,0.40703478455544001,0.40938115119933999,0.41184905171393998,0.41519755125045998,0.41979351639748003,0.42368900775909002,0.42646133899688998,0.42901739478111001,0.43150982260704002,0.43362766504287997,0.43535745143889998,0.43653547763824002,0.43719923496245999,0.43676063418388,0.43493768572807001,0.43310445547103998,0.43158641457558,0.42955911159514998,0.42675906419754001,0.42432397603989003,0.42248168587684998,0.42088398337364002,0.41945216059684998,0.41851812601089,0.41820850968361001,0.41795721650124001,0.41757142543793002,0.41781851649284002,0.41895532608031999,0.41998663544655002,0.42064622044562999,0.42172828316688998,0.42349869012833002,0.42491567134857,0.4257964193821,0.42620635032653997,0.42612445354461997,0.42560195922852001,0.42458531260490001,0.42352622747420998,0.42256084084510998,0.42128732800483998,0.41948917508125,0.41827976703643999,0.41799384355545,0.41767680644989003,0.41711187362670998,0.41674643754959001,0.41666224598884999,0.41673335433005998,0.41693174839019997,0.41736000776290999,0.41809457540512002,0.41871479153633001,0.41907471418380998,0.41965073347092002,0.42060711979866,0.42137736082076999,0.42183220386504999,0.42218506336212003,0.42252758145331998,0.42240789532660999,0.42163884639740001,0.42091211676598,0.42040550708771002,0.41975930333138001,0.41884681582451,0.41815218329429998,0.41778942942619002,0.41763889789580999,0.41784286499022999,0.41731920838356001,0.41555756330490001,0.41446438431740001,0.41452005505562001,0.41495892405509999,0.41570225358009,0.41656169295311002,0.41748175024986001,0.41846406459808,0.41949248313903997,0.42063963413238997,0.42199614644050998,0.42305567860602999,0.42363932728767001,0.42422196269035001,0.42492428421973999,0.42555171251297003,0.42618465423584001,0.42610007524490001,0.42500942945480003,0.42372360825539002,0.42242190241813998,0.42093536257744002,0.41921159625053001,0.41750872135161998,0.41598567366599998,0.41394782066344998,0.41102644801139998,0.40862363576888999,0.40713784098625,0.40592858195304998,0.40499722957611001,0.40369272232056003,0.40174564719200001,0.39981290698050997,0.39801105856895003,0.39638465642928999,0.39492157101630998,0.39386940002441001,0.39328211545943997,0.39323157072067,0.39388892054558,0.39437189698219,0.39445206522942,0.39427971839905002,0.39379325509071,0.39340636134147999,0.39330452680588002,0.39296877384186002,0.39230343699455,0.39121222496032998,0.38952767848969,0.38802796602249001,0.38700577616692,0.38578549027442999,0.38416206836700001,0.38254794478415999,0.38103780150414002,0.37953740358353,0.37801906466483998,0.37657085061072998,0.37515467405318997,0.37412253022193998,0.37365549802780001,0.37322100996971003,0.37267836928367998,0.37215182185173001,0.37161201238632002,0.37131243944168002,0.37139508128165999,0.37141984701156999,0.37127259373665,0.37101858854294001,0.37057858705521002,0.37042242288589,0.37076589465141002,0.37104645371437001,0.37102425098419001,0.37135285139084001,0.37222743034362998,0.37339749932289001,0.37490418553352001,0.37628483772277999,0.37740340828896002,0.37830740213393999,0.37896022200584001,0.37954533100128002,0.38025620579719999,0.38026937842369002,0.37928488850594,0.37779939174652,0.37591427564620999,0.37359917163848999,0.37077686190605003,0.36792415380478,0.36526095867156999,0.36226809024811002,0.35866227746009999,0.35534796118736001,0.35264682769775002,0.35002177953719998,0.34723562002182001,0.34499698877335,0.34363549947739003,0.34230175614357,0.34060785174370001,0.33954459428786998,0.33943873643875,0.33983120322227001,0.34063762426375999,0.34185621142387002,0.34361806511879001,0.34512335062027,0.34595310688018999,0.34713724255562001,0.34906080365181003,0.35104119777678999,0.35300269722938998,0.35454037785530002,0.35547626018523998,0.35599938035010997,0.35609424114227001,0.35600620508193997,0.35583671927451999,0.35546168684959001,0.35492739081383001,0.35385072231293002,0.35193061828612998,0.35014215111732,0.34889268875121998,0.34744971990585,0.34559491276741,0.34357979893683999,0.34151989221572998,0.33902454376220997,0.33570986986160001,0.33300000429152998,0.33148404955864003,0.33023431897163003,0.32901170849799999,0.32796496152878002,0.32708996534348,0.32648050785065003,0.32639428973197998,0.32563221454620001,0.32335522770882003,0.32202872633933999,0.32293680310249001,0.32308930158615001,0.32134246826172003,0.31940272450446999,0.31765148043633001,0.31614401936531,0.31510066986084001,0.3138220012188,0.31185546517371998,0.31045064330101002,0.31017866730690002,0.30997607111931003,0.30947682261467002,0.30913421511650002,0.30903190374374001,0.30923938751220997,0.30989339947701,0.31050413846969999,0.31079301238059998,0.31141087412834001,0.31279677152634,0.31368857622147001,0.31349006295204002,0.31329047679901001,0.31362122297286998,0.31328919529915,0.31177029013634,0.30996990203857,0.30827116966248003,0.30595377087593001,0.30261403322219999,0.29925006628035999,0.29619750380516002,0.29325321316719,0.29027381539344999,0.28789955377579002,0.28666228055954002,0.28501984477043002,0.28219449520111001,0.27959424257277998,0.27765664458275002,0.27616310119629001,0.27524590492249001,0.27425116300583002,0.27277290821075001,0.27168333530425998,0.27146255970000999,0.27105975151062001,0.26998227834701999,0.26907166838646002,0.26871851086616999,0.26819565892219999,0.26731207966804998,0.26597318053246,0.26400718092918002,0.26187071204184997,0.25965210795402999,0.25763824582099998,0.25618082284927002,0.25423428416251997,0.25118309259415,0.24826608598232,0.24596758186817,0.24379248917103,0.24161146581172999,0.23951457440853,0.23736035823821999,0.23586097359656999,0.23547619581223,0.23530288040638001,0.23510339856147999,0.23467472195625,0.23363673686981001,0.23313997685908999,0.23372574150562,0.23475271463394001,0.23614296317101,0.23752991855145,0.23876899480819999,0.23976193368435,0.24037706851959001,0.24090208113194,0.24149626493453999,0.24187569320201999,0.24201215803623,0.24163921177386999,0.24061405658721999,0.23903986811638001,0.23678548634051999,0.23450639843941001,0.23255920410156,0.23047971725464,0.22807012498379001,0.22563709318638001,0.22331386804580999,0.22091615200042999,0.21829289197922,0.2158812135458,0.21399639546870999,0.21194383502007,0.20925121009350001,0.20694027841091001,0.2055386453867,0.20429058372973999,0.20301951467991,0.20149350166321001,0.19932708144187999,0.19761000573634999,0.19705405831337,0.19632267951964999,0.19465675950049999,0.19338165223598,0.19308616220951,0.19312615692616,0.19322122633457001,0.19385445117950001,0.19547650218009999,0.1968447715044,0.19725780189037001,0.19770158827305001,0.19863161444663999,0.19941371679306,0.19976818561553999,0.20004476606846,0.20038992166519001,0.20062564313412001,0.20072975754738001,0.20057819783688,0.20013992488384,0.19928580522537001,0.19794015586375999,0.19613471627234999,0.19372186064720001,0.19132255017756999,0.18937309086323001,0.18713495135307001,0.18418169021606001,0.1812112480402,0.17847771942616,0.17593355476856001,0.17364653944969,0.17145293951035001,0.16915877163410001,0.16730961203575001,0.16636095941067,0.16533541679381999,0.16352751851082001,0.16230003535748,0.16245405375957001,0.16279946267605,0.16272503137589001,0.16306617856026001,0.16449202597140999,0.16540113091469,0.16472209990025,0.16421040892600999,0.16502937674522,0.16504137217998999,0.16306470334529999,0.16060183942317999,0.15834228694439001,0.15550000965595001,0.15164476633071999,0.14752061665058,0.14350868761539001,0.13920268416404999,0.13433127105236001,0.12947644293308,0.12466638535261,0.12074191868305,0.11844719946384,0.11652804166079,0.1141055971384,0.11277893185616,0.11358213424683,0.11490838974714,0.11596535891294001,0.11750156432390001,0.11979518085717999,0.12260767817496999,0.12610177695750999,0.12938444316386999,0.13189226388931,0.13414911925792999,0.13633382320404,0.13834942877292999,0.14044709503651001,0.14158962666988001,0.14097405970096999,0.13981463015078999,0.13877376914024001,0.13709104061127,0.13438975811004999,0.13112144172192,0.12735225260258001,0.12343850731849999,0.11958833038807,0.11579772084951,0.11221601814032001,0.10842651128769,0.10389607399702,0.099945075809955999,0.097587585449219,0.095225617289542999,0.091833665966987998,0.088868126273155004,0.087224923074244995,0.085655525326729001,0.083483338356017997,0.081432595849037004,0.079890049993992004,0.078329004347323997,0.076450660824776001,0.074607290327548995,0.072922676801682004,0.071420356631279006,0.070243746042252003,0.069002389907836997,0.067316703498362995,0.065912388265133001,0.065221384167670995,0.064839668571949005,0.064635902643203999,0.064609229564666998,0.064637452363968007,0.065067432820796994,0.066239878535270996,0.067518800497054998,0.068497255444527005,0.069623678922653004,0.071286402642726995,0.072654888033866993,0.073221690952778001,0.073411829769610998,0.073390275239944,0.073025010526180004,0.072159178555011999,0.071232497692108002,0.070651762187480996,0.069735586643218994,0.068065859377384005,0.066043302416800995,0.063634164631366993,0.061479032039642001,0.060144152492284997,0.058924723416567001,0.057370055466890002,0.056072544306517001,0.055316146463156003,0.054976295679808003,0.055034678429364998,0.055532131344079999,0.056593857705592998,0.057839073240757002,0.059031095355748998,0.060296315699816,0.061767995357512998,0.063038147985935003,0.063839778304099995,0.064346186816692005,0.064630396664142997,0.064582556486129997,0.064118877053260998,0.063361279666424006,0.062490414828062002,0.061052192002534998,0.058486130088567997,0.055941302329302001,0.054243955761194,0.052532732486724999,0.050235748291016,0.048177454620600003,0.047039743512868999,0.045755364000797001,0.043584298342466,0.041332002729177003,0.039220470935106,0.037645861506462,0.037105403840541999,0.036936137825251,0.036815624684095001,0.036807402968407003,0.036924045532941999,0.03698106855154,0.036703042685986002,0.036648094654083002,0.037216812372208002,0.038044370710849998,0.039068132638930997,0.040017329156399002,0.040504079312086001,0.041206452995539003,0.042641852051020002,0.044231683015823003,0.045706253498793002,0.047118186950684003,0.048338390886784002,0.049703016877174003,0.051643338054419001,0.053329497575759999,0.054063439369202,0.054706685245037003,0.055795762687922003,0.056877322494983999,0.057894647121428999,0.058452125638722999,0.058032389730215003,0.057440124452114001,0.057487588375807003,0.056816447526217,0.054169598966836999,0.051369961351155999,0.049520663917065,0.048049960285424999,0.047051388770341998,0.045826710760592998,0.043677706271410002,0.041404988616705003,0.039318129420279999,0.037654895335435999,0.036961078643799002,0.036224532872438001,0.034538134932517998,0.033040303736925,0.032593686133622998,0.032202277332544001,0.031097183004021998,0.030249726027249998,0.030435787513852001,0.030694739893078998,0.03024491854012,0.030087564140558,0.030930502340198,0.032124295830726998,0.033246457576752,0.034770999103784998,0.037186183035374,0.039633948355913003,0.041532613337040003,0.043166410177946,0.044644583016634001,0.045774154365062998,0.04625752940774,0.046712558716535998,0.047914616763592002,0.048537474125624001,0.047282412648201003,0.045884180814028001,0.045751903206110001,0.045340817421674999,0.043656736612320002,0.041424080729485002,0.038728412240743998,0.036191117018460998,0.034529112279414999,0.033010248094797003,0.031250439584255003,0.029329149052500999,0.02682208456099,0.024974925443529999,0.025146484375,0.025630032643675998,0.025055831298231999,0.024839686229824999,0.026007529348135001,0.027538925409316999,0.028806021437048999,0.030206350609659999,0.032010197639464999,0.033772997558117003,0.035039108246564997,0.036404434591532003,0.038499251008034002,0.040384031832217997,0.041372548788785997,0.041857216507196003,0.041918210685252998,0.041673164814710999,0.041180949658154997,0.040629886090754998,0.04045382887125,0.039794217795134,0.037646826356649003,0.035418521612883003,0.034207291901111998,0.033213984221220003,0.032039515674113998,0.030897885560989002,0.029761461541057001,0.028908295556903,0.028756109997630001,0.028672680258750999,0.028178082779050002,0.027530824765563001,0.026788083836436001,0.026001973077655002,0.025316361337899999,0.024464413523674001,0.023141602054238,0.021742520853877002,0.020602606236934998,0.019421726465225001,0.017921838909388001,0.016497697681189,0.015453398227692001,0.014621892943978001,0.013941564597189,0.013445215299725999,0.013260738924146,0.013014816679059999,0.012164360843599,0.011532172560692,0.011748796328902,0.012545770965516999,0.014135204255580999,0.015719840303063001,0.016359204426408001,0.017031826078892,0.018626177683473001,0.020140310749411999,0.020667005330324,0.021142503246665001,0.022318314760923001,0.023556631058454999,0.024456823244690999,0.025227643549442,0.026102462783456001,0.026549333706498,0.025899797677994,0.024979289621115001,0.024363923817873001,0.023919606581330001,0.023954132571816,0.023694328963756998,0.022254185751080999,0.020508032292128001,0.019088303670287,0.017639778554439999,0.015999376773834,0.014281315729022,0.012536025606096001,0.01077270694077,0.0090206880122422999,0.0072645600885152999,0.0053073158487677999,0.0037380596622824998,0.0034496367443352998,0.0031911446712910999,0.0018652252620086,0.00012870886712335001,-0.0019398184958845,-0.0037700885441153999,-0.0044100666418671998,-0.0050503057427703996,-0.0067845876328646998,-0.0087780812755227002,-0.010589067824185,-0.012221470475197,-0.013507452793419,-0.014534901827574,-0.015250886790454001,-0.015906365588306999,-0.016926543787121998,-0.01770288310945,-0.017418647184968002,-0.017184285447000999,-0.018311260268091999,-0.019288273528217999,-0.018745396286249001,-0.017666466534138,-0.016789548099040999,-0.015436769463122,-0.012875407002865999,-0.010035762563348,-0.0078000919893383997,-0.0055519319139421004,-0.0027853085193783001,-6.1037018895149001e-05,-0.0084231086075306008,-0.0033335317857563001,0.0032292371615767002,0.0090992376208304995,0.015003522858024001,0.020957339555025,0.026930354535580001,0.032884303480386998,0.038857113569975003,0.044881403446198002,0.05093627050519,0.057008296251296997,0.063106931746005998,0.069243647158146002,0.075399637222289997,0.081555612385272994,0.087722942233085993,0.093913085758685996,0.10010732710361001,0.10628631711005999,0.11246136575937001,0.1186345666647,0.12481516599655,0.13101673126221,0.13722985982895,0.1434505879879,0.14967526495457001,0.15589421987534,0.16212049126625,0.16837154328823001,0.17462687194347001,0.18086503446102001,0.18710283935069999,0.19335402548312999,0.19960920512676,0.20585870742797999,0.21211542189120999,0.21839500963687999,0.22468261420727001,0.23096451163292001,0.23724994063377,0.24354311823845001,0.24984747171402,0.25617650151253002,0.26250648498535001,0.26881158351897999,0.27510499954223999,0.28139087557793002,0.28767266869545,0.29395824670791998,0.30024030804634,0.30651465058326999,0.31277784705161998,0.31901642680168002,0.32525384426116999,0.33152171969414002,0.33779081702232,0.34402757883071999,0.35026657581329002,0.35654562711715998,0.36283358931540999,0.36910429596901001,0.37537080049514998,0.38163378834723999,0.38790711760521002,0.39421838521956998,0.40053531527518998,0.40682905912398998,0.41310408711433,0.41934692859650002,0.42558062076568998,0.43183529376983998,0.43808740377425998,0.44431638717651001,0.45053356885910001,0.45674884319304998,0.46294960379601002,0.46912187337875,0.47527462244034002,0.48141586780548001,0.48753848671913003,0.49363625049590998,0.49971121549606001,0.50576144456863004,0.51179218292235995,0.51781511306762995,0.52381271123885997,0.52976274490356001,0.53568130731582997,0.54158276319503995,0.54745805263518998,0.55329895019530995,0.55911278724669999,0.56491112709044999,0.57067668437957997,0.57638341188430997,0.58205747604369995,0.58772784471511996,0.59337651729583996,0.59898877143859997,0.60457390546798995,0.61014169454574996,0.61568009853363004,0.62117832899094005,0.62663513422011996,0.63204067945480003,0.63740688562393,0.64274656772614003,0.64805579185485995,0.65333455801009999,0.65858280658722002,0.66380238533019997,0.66898828744887995,0.67413222789764005,0.67924129962920998,0.68432533740997004,0.68937259912491,0.69436490535735995,0.69932085275650002,0.70426523685455,0.70917731523514005,0.71403425931930997,0.71885162591934004,0.72364431619643999,0.72840338945389005,0.73311519622803001,0.73780137300491,0.74249863624572998,0.74716955423355003,0.75176811218261996,0.75632560253143,0.76087355613707996,0.76538950204848999,0.76985186338425005,0.77427160739899004,0.77864980697632002,0.78299915790557995,0.78734636306762995,0.79166615009307995,0.79593211412429998,0.80015236139296997,0.80432510375976995,0.80845516920089999,0.81254732608794999,0.81660437583922996,0.82063657045364002,0.82463222742080999,0.82857453823089999,0.83247715234756003,0.83635509014130005,0.84019958972930997,0.84400558471679998,0.84777057170867998,0.85148608684539995,0.85515886545180997,0.85879892110824996,0.86239498853683005,0.86592674255371005,0.86941689252853005,0.87290090322494995,0.87634742259979004,0.87971937656402999,0.88303607702255005,0.88630789518356001,0.88953971862793002,0.89274841547011996,0.89592093229294001,0.89904367923737005,0.90212059020996005,0.90515190362929998,0.90813738107680997,0.91107892990112005,0.91397172212600997,0.91680938005446999,0.91959363222122004,0.92232441902161,0.92500191926955999,0.92762595415115001,0.93019676208496005,0.93271231651305997,0.93517738580704002,0.93760234117508001,0.93997591733931996,0.94228088855742997,0.94453060626983998,0.94674026966095004,0.94890153408051003,0.95100557804107999,0.95305901765822998,0.95507061481475997,0.95703363418579002,0.95893788337707997,0.96079432964324996,0.96262508630752996,0.96440398693085005,0.96609342098235995,0.96771180629730003,0.96927160024643,0.97077322006225997,0.97222006320953003,0.97361898422241,0.97498905658722002,0.97631275653839,0.97756284475327004,0.97876274585723999,0.97994154691696,0.98108750581741,0.98219496011733998,0.98326158523560003,0.98428231477737005,0.98525458574295,0.98617130517960006,0.98703479766846003,0.98784482479095004,0.98860150575637995,0.98930662870407005,0.98995566368103005,0.99054002761840998,0.99106597900391002,0.99154067039490001,0.99196207523346003,0.99233001470565996,0.99264454841614003,0.99290251731873003,0.99311220645904996,0.99329131841660001,0.99342709779739002,0.99350559711455999,0.99353063106536998,0.99349391460419001,0.99341672658919999,0.99334269762038996,0.99324077367783004,0.99307215213776001,0.99285501241684004,0.99260210990905995,0.99231368303298995,0.99200034141541005,0.99165129661560003,0.9912526011467,0.99080789089203003,0.99032104015349998,0.98978328704833995,0.98917561769484996,0.98851430416107,0.98782259225845004,0.98709052801132002,0.98631048202515004,0.98548471927643,0.98461174964904996,0.98369538784027,0.98274630308151001,0.98175418376922996,0.98070138692856001,0.97960007190704002,0.97846621274947998,0.97729206085205,0.97606670856475997,0.97480058670044001,0.97350955009460005,0.97218567132949996,0.97082507610321001,0.96942144632339,0.96795380115509,0.96644240617751997,0.96492266654967995,0.96337074041366999,0.96175575256348,0.96008962392806996,0.95837801694869995,0.95662319660187001,0.95483565330505005,0.95300525426865001,0.95111572742462003,0.94917517900466997,0.94719088077544999,0.94516086578368996,0.94308203458786,0.94096213579178001,0.93882036209106001,0.93664139509201005,0.93440628051758001,0.93211311101912997,0.92973911762238004,0.92730808258056996,0.92485952377319003,0.92237627506256004,0.91984027624130005,0.91726291179657005,0.91465896368027,0.91202479600905995,0.90936160087585005,0.90666562318802002,0.90392971038818004,0.90115559101105003,0.89834326505661,0.89549285173416004,0.89260596036911,0.88967865705490001,0.88670527935027998,0.88368391990661999,0.88060075044632002,0.87747323513030995,0.87433677911758001,0.87116909027099998,0.86793541908264005,0.86465454101562,0.86135095357894997,0.85801482200623003,0.85463696718215998,0.85122317075729004,0.84778237342833995,0.84430909156799006,0.84079545736312999,0.83724385499954002,0.83365565538405995,0.83002716302872004,0.82635110616684004,0.8226290345192,0.81885981559752996,0.81504702568053999,0.81120431423187001,0.80731499195098999,0.80335092544555997,0.79931569099426003,0.79520231485366999,0.79101258516312001,0.78673875331878995,0.78239911794661998,0.77804231643677002,0.77363318204880005,0.76911264657973999,0.76450818777083995,0.75984913110732999,0.75513148307800004,0.75036716461181996,0.74554353952408003,0.74063289165497004,0.73565196990966997,0.73062670230865001,0.7255442738533,0.72038626670837003,0.71516346931457997,0.70988667011260997,0.70456266403197998,0.69921875,0.69383865594864003,0.68839007616043002,0.68289971351624001,0.67741519212723,0.67192161083221003,0.66640460491179998,0.66088020801544001,0.65538191795348999,0.64989542961121005,0.64440494775771995,0.63891434669494995,0.63341909646988004,0.6279296875,0.62246900796890003,0.61703157424927002,0.61160933971404996,0.60621958971024004,0.60090214014053001,0.59564423561096003,0.59043174982071001,0.58528012037277,0.58022165298462003,0.57524549961089999,0.57033920288086004,0.56551456451416005,0.56080251932143999,0.55618047714232999,0.55160361528396995,0.54709464311599998,0.54268491268158003,0.53836709260940996,0.53413623571395996,0.53000241518020996,0.52598875761032005,0.52208977937697998,0.51830810308455999,0.51463711261749001,0.51105690002440995,0.50758093595505005,0.50423276424408003,0.50100690126419001,0.49790298938750999,0.49492105841637002,0.49206703901290999,0.48932784795760997,0.4866678416729,0.48410415649414001,0.48166802525520003,0.47933778166771002,0.47707110643387002,0.47488361597061002,0.47279280424117998,0.47079202532768,0.46887317299843001,0.46703803539276001,0.46528965234755998,0.46362164616585,0.46202287077903997,0.46048724651336997,0.45899447798728998,0.45754367113112998,0.45612385869026001,0.45472919940947998,0.45333775877952998,0.45195186138152998,0.45056998729705999,0.44918116927147,0.44775423407554998,0.44629618525504999,0.44481354951858998,0.44329372048378002,0.44170671701431002,0.44005647301674,0.43833726644516002,0.43654763698577997,0.43468853831290999,0.43274331092834001,0.43066167831420998,0.42846050858498003,0.42616078257561002,0.42374977469443997,0.42120349407196001,0.41852715611458002,0.41572561860085,0.41278964281081998,0.40969416499138001,0.40644729137420998,0.40305900573730002,0.39952445030212003,0.39583984017371998,0.39199793338776001,0.38797211647034002,0.38377368450165,0.37942036986351002,0.37490576505661,0.37022161483764998,0.36536958813666998,0.36035129427910001,0.35516381263732999,0.34979766607285001,0.34425759315491,0.33855170011520003,0.33267849683762002,0.32663458585739003,0.32042598724365001,0.31406873464584001,0.30755931138991999,0.30090177059174,0.29408729076384998,0.28708478808402998,0.27991384267807001,0.27261653542518999,0.26518142223357999,0.25759252905845997,0.24986594915390001,0.24204349517821999,0.23411367833614,0.22606348991394001,0.21790309250355,0.20965687930584001,0.2013197094202,0.19288966059685,0.18436959385872001,0.17576614022254999,0.16708041727542999,0.158313408494,0.14947739243506999,0.14061392843723,0.1317118704319,0.12275946140289,0.11376390606165,0.10473603010177999,0.095683537423611006,0.086637109518050995,0.077592775225638996,0.068551033735275005,0.059523887932300998,0.050554484128951999,0.041629046201706002,0.032722160220145999,0.023853428661822999,0.015072006732225,0.0063679441809654002,-0.0022557917982340002,-0.010807272978126999,-0.019321862608194001,-0.027773164212704,-0.036095406860112998,-0.044301763176918002,-0.052395150065422003,-0.060372903943062002,-0.068228237330914002,-0.075960129499434995,-0.083564668893814004,-0.091035604476929002,-0.098348610103129994,-0.10550856590271,-0.11251879483461,-0.11937405914068,-0.12605930864810999,-0.13257524371147,-0.13891805708408,-0.14508163928986001,-0.15104024112225001,-0.15680128335953,-0.16237224638462,-0.16775408387183999,-0.17296150326729001,-0.17798013985156999,-0.18276730179787001,-0.18733358383179,-0.19169226288794999,-0.19583415985107,-0.19973163306712999,-0.20339457690716001,-0.20684143900870999,-0.21006651222705999,-0.21305973827839,-0.21582528948783999,-0.21837688982487,-0.22070302069187001,-0.222765147686,-0.22457946836948001,-0.22618651390076,-0.22756768763065,-0.228679433465,-0.22953201830386999,-0.23013357818127,-0.23048494756221999,-0.23059420287609,-0.2304597645998,-0.23007880151272,-0.22945614159107,-0.22860968112946001,-0.22753392159939001,-0.22622270882129999,-0.22467277944087999,-0.22286649048328,-0.22080926597118,-0.21850602328777,-0.21596232056618,-0.21320417523384,-0.21022462844848999,-0.20701207220553999,-0.20357270538807001,-0.19992734491825001,-0.19606588780879999,-0.19195640087127999,-0.18761509656906,-0.1830883026123,-0.17836144566536,-0.17340569198132,-0.16823020577431,-0.16284987330437001,-0.15726622939109999,-0.15149301290511999,-0.14553172886372001,-0.13939863443375,-0.13309071958065,-0.12660367786884,-0.11994428932667001,-0.11314277350903,-0.10618566721677999,-0.099034830927848996,-0.091702960431575997,-0.084213718771934995,-0.076567083597183005,-0.068777836859226005,-0.060845237225294002,-0.052770845592021998,-0.044564228504895997,-0.036267176270485001,-0.027872338891029001,-0.019370853900909001,-0.010775832459330999,-0.0021465970203279998,0.0065408255904913001,0.015349522233009,0.024264967069029999,0.033275946974754,0.042372465133666999,0.051501922309398998,0.060677282512187999,0.069922037422656999,0.079224780201911996,0.088553659617901001,0.097910203039645996,0.10728103667498,0.11666484922171,0.12604650855064001,0.13542674481868999,0.14479643106460999,0.15415903925895999,0.16352832317352001,0.17289450764656,0.18222343921660999,0.19152073562145,0.20079003274441001,0.21002717316151001,0.21921767294406999,0.22836025059223,0.23743844032288,0.24645508825779,0.25541323423385998,0.26430878043174999,0.27312478423119002,0.28186398744583002,0.29053059220313998,0.29911863803863997,0.30760622024536,0.31599155068397999,0.32424867153168002,0.33238372206687999,0.34040734171866999,0.34831613302231001,0.35610616207123003,0.36377093195915,0.3712754547596,0.37862703204155002,0.38583430647849998,0.39289772510528997,0.39982682466507002,0.40661829710007003,0.41326570510864002,0.41976657509804,0.42610284686089001,0.43227919936179998,0.43830591440201,0.44417980313300998,0.44989430904388,0.45544707775116,0.46082255244254999,0.46602135896683,0.47103556990623002,0.4758662879467,0.48051315546036,0.48497775197029003,0.48926749825478,0.49338290095329002,0.49733224511147001,0.50111424922943004,0.50472617149353005,0.50817173719405995,0.51146918535232999,0.51461428403854004,0.51759761571884,0.52042061090469005,0.52308237552643,0.52558463811874001,0.52793842554091996,0.53013896942139005,0.53216505050659002,0.53402459621428999,0.53574293851851995,0.53731805086135997,0.53875982761383001,0.54006361961365001,0.54120832681655995,0.54220163822173995,0.54306900501250999,0.54380828142166004,0.54442727565765003,0.54492455720901001,0.54529881477356001,0.5455516576767,0.54569059610366999,0.54571604728698997,0.54563415050507003,0.54544687271117998,0.54517132043839001,0.54480499029160001,0.54434716701508001,0.54379785060883001,0.54315602779387995,0.54242318868636996,0.54160583019257003,0.54070585966109996,0.53973603248596003,0.53870022296905995,0.53763699531554998,0.53653508424759,0.53535509109497004,0.53410649299622004,0.53281563520431996,0.53148066997527998,0.53010791540145996,0.52869790792464999,0.52725666761398005,0.52578622102737005,0.52430588006973,0.52281010150909002,0.52127635478973,0.51971310377121005,0.51815706491470004,0.51660209894179998,0.51503789424895996,0.51346582174301003,0.51188385486603005,0.51029503345490002,0.50871580839157005,0.50714534521103005,0.50559276342392001,0.50405538082123003,0.50252085924149004,0.50099474191666005,0.49950245022773998,0.49804219603539002,0.49662378430366999,0.49524310231209001,0.49387791752815002,0.49253624677657998,0.49125832319259999,0.49003383517264998,0.48882409930228998,0.48763638734817999,0.48648974299431003,0.48538196086884,0.48431232571602001,0.48328077793120999,0.48228627443313998,0.48133018612862,0.48042029142379999,0.47955679893494002,0.47874918580054998,0.47799497842789002,0.47728300094603998,0.47661688923835999,0.47601577639580001,0.47547611594200001,0.47498625516891002,0.47454994916915999,0.47418823838233998,0.47389513254165999,0.47364133596419999,0.47343257069588002,0.47328874468803001,0.47320643067360002,0.47317498922348,0.47319671511650002,0.47328299283981001,0.47343015670776001,0.47362124919891002,0.47385698556900002,0.47412943840027,0.47443959116936002,0.47478887438773998,0.47517603635788003,0.47558921575545998,0.47603309154509998,0.47653552889824002,0.47709241509438,0.47769567370415,0.47834384441375999,0.47901770472527,0.47972154617309998,0.48047596216201999,0.48127654194831998,0.48210492730141002,0.48296293616295,0.48385140299797003,0.4847703576088,0.48572182655334001,0.48670348525047002,0.48769968748093001,0.4887098968029,0.48971539735794001,0.49072027206420998,0.49174311757088002,0.49278211593628002,0.49383530020714,0.49490389227866999,0.49599975347518999,0.49711850285530002,0.49822923541068997,0.49933907389641002,0.50048780441284002,0.50166845321654996,0.50285172462463001,0.50404137372971003,0.50525057315826005,0.50647526979446,0.50769025087357,0.50889611244202004,0.51007437705993997,0.51122909784317005,0.51237881183624001,0.51352179050446001,0.51465821266174006,0.51578688621520996,0.51690101623535001,0.51799929141998002,0.51906055212020996,0.52009052038193004,0.52112877368927002,0.52216875553131004,0.52318191528320002,0.52417075634002996,0.52513682842255005,0.52607995271682995,0.52700215578079002,0.52790147066116,0.52875816822052002,0.52957576513289994,0.5303760766983,0.53115445375443004,0.53188323974608998,0.53256481885910001,0.53319680690765003,0.53378301858902,0.53436201810837003,0.53492772579193004,0.53545153141021995,0.53593575954437001,0.53637892007828003,0.53678399324417003,0.53717947006225997,0.53756123781204002,0.53791290521622004,0.53823322057723999,0.53849357366562001,0.53869891166687001,0.53887748718261996,0.53902709484099998,0.53914809226990001,0.53923875093460005,0.53927737474441995,0.53926903009414995,0.53925406932830999,0.53922629356384,0.53914690017699995,0.53901964426041005,0.53885644674301003,0.53865575790404996,0.53840810060500999,0.53811419010161998,0.53777360916137995,0.53738719224929998,0.53696388006210005,0.53650301694869995,0.53600305318831998,0.53546482324599998,0.53489828109741,0.53430193662643,0.53366625308990001,0.53299194574356001,0.53227859735489003,0.53152698278427002,0.53074604272841996,0.52993512153625,0.52909380197525002,0.52822190523148005,0.52731865644455,0.52638471126555997,0.52542912960052002,0.52445119619369995,0.52345037460327004,0.52242666482925004,0.52138012647628995,0.52031069993973,0.51921933889389005,0.51810532808304,0.51696234941482999,0.51578897237777999,0.51455426216125,0.51326352357864002,0.51196503639221003,0.51065444946288996,0.50931209325789994,0.50793832540511996,0.50652438402176003,0.50507158041,0.50358849763869995,0.50207531452178999,0.50053942203521995,0.49898099899291998,0.49740755558013999,0.49581915140152,0.49422693252562999,0.49262839555740001,0.49099430441856001,0.48932749032973999,0.48765027523040999,0.48595982789992997,0.48422700166701999,0.48245409131049999,0.48065271973610002,0.47882169485092002,0.47695147991179998,0.47504255175590998,0.47309300303459001,0.47110447287559998,0.46910643577576,0.46709579229355003,0.46504205465317,0.46294790506362998,0.46083214879036,0.45869430899620001,0.45654323697089999,0.45437774062156999,0.45218750834464999,0.44997349381446999,0.44774615764617998,0.44550442695617998,0.44323885440826,0.44094982743263,0.43863961100577997,0.43630728125571999,0.43393385410308999,0.43152078986168002,0.42907747626304998,0.42660382390022,0.42410841584205999,0.42159068584442,0.41905006766318997,0.41648662090302002,0.41390359401702997,0.41129931807518,0.40863347053527999,0.40590989589691001,0.40317690372467002,0.40043208003044001,0.39766588807106001,0.39487746357918002,0.39203783869742997,0.38914939761161998,0.38624107837677002,0.38331171870232,0.38035947084427002,0.37738436460495001,0.37438637018204002,0.37136554718018,0.36832427978516002,0.36526149511337003,0.36214765906334001,0.35898485779762002,0.35580366849898998,0.35260239243507002,0.34936115145683,0.34608054161071999,0.34276098012924,0.33940285444259999,0.33601275086402999,0.33259138464928001,0.32916679978371,0.32573741674423001,0.32228493690491,0.31880933046340998,0.31529292464255998,0.31173667311668002,0.30815082788467002,0.30453509092330999,0.30088973045348999,0.29721435904503002,0.29350078105927002,0.28974893689156,0.28594890236854997,0.28210145235062001,0.27822530269623003,0.27431991696357999,0.27038410305977001,0.26641774177550998,0.26242250204085998,0.25839784741402,0.25432491302490001,0.25020435452460998,0.24604427814484001,0.2418450564146,0.23763634264469,0.23341654241085,0.22914758324623,0.22483026981354001,0.22046487033366999,0.21605205535888999,0.21161967515944999,0.20716699957848,0.20268300175667001,0.19816784560680001,0.1936229467392,0.18904818594455999,0.18443216383457001,0.17977559566498,0.17510776221752,0.17042788863182001,0.16571441292763001,0.16096787154674999,0.15621072053908999,0.15144214034080999,0.14662383496761,0.14175647497176999,0.13685254752636,0.13191181421279999,0.12692232429981001,0.12188450247049,0.11682842671870999,0.11175345629454,0.10662595927715,0.10144676268100999,0.096275962889194003,0.091112568974495003,0.085905708372592995,0.080655962228774997,0.075384885072708005,0.070092327892779999,0.064777635037899003,0.059440754354000001,0.054072625935078,0.048673305660485999,0.043244231492281002,0.037785347551106997,0.032286882400513001,0.026748912408948,0.021179025992751,0.015577267855406,0.0099722445011139003,0.0043638339266181001,-0.0012772437185049001,-0.0069509446620940997,-0.012656565755605999,-0.018394105136395,-0.024144031107425998,-0.029906332492828001,-0.035702668130397998,-0.041533112525939997,-0.047368358820676998,-0.053208339959382997,-0.059064254164696003,-0.064936138689518003,-0.070824675261974002,-0.076729938387870997,-0.082633852958679005,-0.088536299765110002,-0.094437353312969,-0.10033687949181,-0.10625509917735999,-0.11219232529402,-0.11811851710081001,-0.12403336167336,-0.12995643913745999,-0.13588784635067,-0.14183585345745001,-0.14780060946941001,-0.15377166867256001,-0.15974880754948001,-0.16574388742446999,-0.17175734043120999,-0.17775990068913,-0.18375098705292001,-0.18975234031676999,-0.19576440751553001,-0.2017662525177,-0.20775735378265001,-0.21375732123852001,-0.21976640820502999,-0.22578242421149999,-0.2318052649498,-0.23784461617470001,-0.24390079081058999,-0.24996399879455999,-0.25603407621384,-0.26211243867874001,-0.26819926500320002,-0.27428680658339999,-0.28037527203559998,-0.28644540905951998,-0.29249620437621998,-0.29855695366858997,-0.30462849140166998,-0.31069949269295,-0.31676971912384,-0.32284060120583002,-0.32891231775284002,-0.33497524261474998,-0.34102886915206998,-0.34708306193352001,-0.35313802957535001,-0.35919430851936002,-0.36525231599808,-0.37129274010657998,-0.37731462717056002,-0.38333877921103998,-0.38936626911163003,-0.39537629485129999,-0.40136763453483998,-0.40736129879951,-0.41335833072661998,-0.41933852434157998,-0.42530092597008001,-0.43125620484352001,-0.43720471858977999,-0.44314676523209001,-0.44908311963080999,-0.45499435067177002,-0.46087926626205,-0.46675935387611001,-0.47263628244400002,-0.47848004102706998,-0.48428905010223,-0.49008429050446001,-0.49586689472197998,-0.50162553787231001,-0.50735956430435003,-0.51308000087738004,-0.51878798007964999,-0.52446389198303001,-0.53010678291321001,-0.53572660684586004,-0.54132348299026001,-0.54690486192703003,-0.5524708032608,-0.55803143978118996,-0.56358820199965998,-0.56911140680312999,-0.57459872961044001,-0.58008080720901001,-0.58555972576141002,-0.59101557731627996,-0.59644794464110995,-0.60184818506241,-0.60721504688262995,-0.61256873607634998,-0.61791086196899003,-0.62322050333023005,-0.62849593162536999,-0.63375872373580999,-0.63901096582412997,-0.64422339200973999,-0.64939415454865002,-0.65453362464904996,-0.65964132547378995,-0.66473633050919001,-0.66982084512711004,-0.67486566305161,-0.67986881732940996,-0.68484175205231002,-0.68978506326675004,-0.69469845294952004,-0.69958245754241999,-0.70442736148833995,-0.70923227071761996,-0.71400642395019998,-0.71874994039536,-0.72347199916839999,-0.72817426919937001,-0.73283773660660001,-0.73746132850646995,-0.74204576015472001,-0.74658989906311002,-0.75111234188080001,-0.75561475753784002,-0.76008689403534002,-0.76452881097794001,-0.76893228292464999,-0.77329677343368997,-0.77762264013289994,-0.78190922737122004,-0.78616511821747004,-0.79039025306702004,-0.79459393024445002,-0.79877775907516002,-0.80292302370071,-0.80702847242355003,-0.81109625101089,-0.81512701511383001,-0.81911188364028997,-0.82305020093918002,-0.82694214582443004,-0.83078724145889005,-0.83459490537643,-0.83836662769318004,-0.84209173917769997,-0.84576910734177002,-0.84940868616104004,-0.85301101207732999,-0.85657459497452004,-0.86009895801544001,-0.86359250545501998,-0.86705535650252996,-0.87049770355224998,-0.87392258644104004,-0.87729239463805997,-0.88060283660889005,-0.88387560844420998,-0.88711214065552002,-0.89031088352203003,-0.89347285032271995,-0.89658880233765004,-0.89965826272964,-0.90268236398696999,-0.90566194057464999,-0.90858703851699996,-0.91145539283751997,-0.91428655385971003,-0.91708260774612005,-0.91983270645142001,-0.92253619432448997,-0.92519450187683006,-0.92780822515488004,-0.93036854267119995,-0.93287444114685003,-0.93532609939574995,-0.9377219080925,-0.94008195400238004,-0.94241052865982,-0.94466757774353005,-0.94684612751007002,-0.94899529218673995,-0.95111989974975997,-0.95320719480515004,-0.95525789260864002,-0.95725417137145996,-0.95919269323348999,-0.96109473705292003,-0.96296423673630005,-0.96477061510086004,-0.96650815010071001,-0.96821749210357999,-0.96990519762038996,-0.97153109312056996,-0.97309094667435003,-0.97459656000136996,-0.97604721784591997,-0.97746038436890004,-0.97883874177932995,-0.98017156124115001,-0.98145902156830001,-0.98269224166869995,-0.98386853933333995,-0.98500722646713001,-0.98611104488373003,-0.98716855049133001,-0.98817813396454002,-0.98915112018585005,-0.99009072780608998,-0.99096751213073997,-0.99177521467208996,-0.99255287647247004,-0.99330520629883001,-0.99402046203613004,-0.99469918012618996,-0.99532407522202004,-0.99589240550994995,-0.99641543626785001,-0.99689501523972002,-0.99732041358947998,-0.99768882989883001,-0.99802035093306996,-0.99831974506377996,-0.99855643510818004,-0.99872392416,-0.99886202812195002,-0.99897766113280995,-0.99904000759125,-0.99904620647429998,-0.99899888038634999,-0.99889832735062001,-0.99874383211135997,-0.99853479862213002,-0.99827980995178001,-0.9979801774025,-0.99763429164885997,-0.99724137783051003,-0.99681103229523005,-0.99634641408919999,-0.99582862854003995,-0.99525541067123002,-0.99462848901749001,-0.99394685029983998,-0.99321931600571001,-0.99244701862335005,-0.99162906408310003,-0.99076521396636996,-0.98985588550568004,-0.98890066146850997,-0.98789930343627996,-0.98685103654860995,-0.98576509952544999,-0.98464488983153997,-0.98347002267838002,-0.98223406076430997,-0.98097670078277999,-0.97970759868622004,-0.97837722301482999,-0.97697645425796997,-0.97553825378418002,-0.97406929731368996,-0.97253823280333995,-0.97093749046325994,-0.96930623054503995,-0.96765142679214,-0.96595221757889005,-0.96420806646347001,-0.96240121126175004,-0.96052426099777,-0.95862483978270996,-0.95671355724335005,-0.95474904775619995,-0.95272415876389005,-0.95066064596176003,-0.94856113195419001,-0.94642347097396995,-0.94424778223037997,-0.94203305244446001,-0.93977731466293002,-0.93749904632568004,-0.93520295619964999,-0.93286806344985995,-0.93048858642578003,-0.92809385061264005,-0.92568987607955999,-0.92325609922409002,-0.92078965902328003,-0.91829276084900002,-0.91576534509659002,-0.91320699453354004,-0.91061681509018,-0.90800327062607,-0.90536803007125999,-0.90271121263503995,-0.90003579854964999,-0.89731568098068004,-0.89454656839371005,-0.89173066616058005,-0.88886445760726995,-0.88597637414931996,-0.88307601213455,-0.88011652231215998,-0.87709057331085005,-0.87400215864181996,-0.8708468079567,-0.86766099929810003,-0.86445504426955999,-0.86118847131729004,-0.8578519821167,-0.85447627305983997,-0.85106575489044001,-0.84761756658553999,-0.84413266181946001,-0.84060251712798995,-0.83702552318572998,-0.83340382575989003,-0.82974106073380005,-0.82601016759872004,-0.82220429182053001,-0.81834530830383001,-0.81443983316421997,-0.81045931577681996,-0.8063992857933,-0.80226373672484996,-0.79805511236190996,-0.79375517368316995,-0.78935843706131004,-0.78488391637802002,-0.78033226728438998,-0.77571940422058006,-0.77105093002319003,-0.76630574464797996,-0.76147592067719005,-0.75659906864166004,-0.75168418884277,-0.74670821428298995,-0.74166429042815996,-0.73658084869384999,-0.73146271705626997,-0.72630602121353005,-0.72110962867737005,-0.71588158607482999,-0.71062111854553001,-0.70534467697143999,-0.70005691051482999,-0.69474560022354004,-0.68940567970276001,-0.68406373262404996,-0.67872369289398005,-0.67339038848876998,-0.66806429624556996,-0.66275143623351995,-0.65744870901107999,-0.65218877792357999,-0.64697599411010998,-0.64182275533676003,-0.63673120737076006,-0.63170796632767001,-0.62675613164902,-0.62186449766159002,-0.61702626943588001,-0.61227720975875999,-0.60762423276901001,-0.60306268930435003,-0.59859257936478005,-0.59421265125275002,-0.58991783857346003,-0.58574211597443004,-0.58169138431548995,-0.57776927947998002,-0.57397633790970004,-0.57031965255737005,-0.56679970026016002,-0.56342387199402,-0.56019413471222002,-0.55710977315902999,-0.55417352914810003,-0.55136847496033004,-0.54869228601455999,-0.54613870382309004,-0.54370594024658003,-0.54139637947082997,-0.53921520709991,-0.53712928295134998,-0.53513491153716997,-0.53321039676666004,-0.53134590387344005,-0.52957141399384,-0.52789527177811002,-0.52629709243774003,-0.52477431297302002,-0.52332121133803999,-0.52193719148635997,-0.52061516046524003,-0.51935446262359997,-0.51814854145050004,-0.51699811220169001,-0.51588815450668002,-0.51481890678405995,-0.51376742124556996,-0.51272922754287997,-0.51170033216475996,-0.51068282127380005,-0.50965297222136996,-0.50860762596130005,-0.50753355026244995,-0.50642830133437999,-0.50528657436371005,-0.50411051511765004,-0.50287675857544001,-0.50158345699310003,-0.50020778179169001,-0.49873957037925998,-0.49721053242683,-0.49563932418822998,-0.49394541978835999,-0.49210748076438998,-0.49015438556670998,-0.48809447884559998,-0.48590132594108998,-0.48357576131821001,-0.4810791015625,-0.47840097546576998,-0.47554779052733998,-0.47252100706099998,-0.46931323409080999,-0.46592813730240001,-0.46233254671097002,-0.45851516723633001,-0.45449757575989003,-0.45028254389763001,-0.44587609171866999,-0.44128036499022999,-0.43649375438690002,-0.43151491880416998,-0.42635276913643,-0.42101237177848999,-0.41547590494156,-0.40974044799804998,-0.40379911661147999,-0.39764383435249001,-0.39131048321723999,-0.38481381535530002,-0.37811380624771002,-0.37119430303574003,-0.36410233378410001,-0.35684901475906,-0.34942749142647,-0.34183481335639998,-0.33408775925635997,-0.32619079947472002,-0.31814089417458002,-0.30993506312370001,-0.30158954858780002,-0.29310590028763001,-0.28449779748916998,-0.27576678991317999,-0.26692658662795998,-0.25797873735428001,-0.24893712997437001,-0.23980489373207001,-0.23058679699897999,-0.22127911448479001,-0.21191371977328999,-0.20249836146832001,-0.19303575158118999,-0.18352517485618999,-0.17398129403591001,-0.16440419852734001,-0.15481631457806,-0.14522470533848,-0.13562524318694999,-0.12601636350154999,-0.11640550196171,-0.10678882896899999,-0.097197614610194993,-0.087636768817902,-0.078125782310962996,-0.068670287728310006,-0.059273973107338,-0.049934595823287999,-0.040675058960915,-0.031497932970524001,-0.022423269227146998,-0.013452094048262,-0.0046145133674144996,0.0040734382346272,0.012651257216930001,0.021136607974768001,0.029483295977115999,0.037682157009839998,0.045723255723715002,0.053601641207933003,0.061321053653955002,0.068889416754245994,0.076265446841717002,0.083436660468578006,0.090409487485885995,0.097182318568229994,0.1037644892931,0.11016649007797,0.11634495109320001,0.12228082120419,0.12801411747932001,0.13355821371078,0.13889175653458,0.14401280879973999,0.14890784025192,0.15357336401939001,0.15800341963768,0.16219219565392001,0.16615825891495001,0.16991326212883001,0.17342135310173001,0.17666883766651001,0.17967793345451,0.18245708942413,0.18498767912388001,0.18726767599583,0.18928284943104001,0.19102303683758001,0.19251604378223,0.19377472996712,0.19477011263371,0.19549098610877999,0.19595791399479001,0.19617787003517001,0.19613978266716001,0.19583934545517001,0.19528603553772,0.19448259472846999,0.19342702627182001,0.19211439788342,0.19056963920593001,0.18880589306355,0.18679445981979001,0.18452553451060999,0.18201094865799,0.17925013601779999,0.17625792324542999,0.17303980886935999,0.16959284245968001,0.16591535508633001,0.16201543807982999,0.15789586305618,0.15355488657951,0.14898914098739999,0.14421513676643,0.13924185931683,0.13404963910580001,0.12862613797187999,0.12300602346658999,0.1171972155571,0.11121039837599,0.10505293309689,0.098713301122188998,0.092181831598281999,0.085491776466370004,0.078651145100593997,0.071670562028884999,0.064557462930679002,0.057300679385662003,0.049893908202648003,0.042354766279459,0.034690752625464998,0.026890031993389001,0.018939398229121999,0.010888811200856999,0.0027609057724475999,-0.0054773055016993999,-0.013839762657881,-0.022298878058791001,-0.030852757394314,-0.039474032819270997,-0.048154376447200997,-0.056883364915848,-0.065653346478939001,-0.074475765228270999,-0.083360552787780998,-0.092274405062199,-0.10120541602373,-0.11015975475311,-0.11914265155792,-0.12813027203082999,-0.13711358606815,-0.14609734714031,-0.15508683025837,-0.16405880451202001,-0.17301122844219,-0.18191608786583,-0.19075420498848,-0.19956405460835,-0.20837016403674999,-0.21711108088493,-0.22576183080673001,-0.23434852063656,-0.24287900328636,-0.25134313106536998,-0.25974488258362,-0.26805379986763,-0.27625399827956998,-0.28436747193335998,-0.29240575432777,-0.30034258961678001,-0.30817219614982999,-0.31588318943977001,-0.32346931099892001,-0.33093374967575001,-0.33828008174896002,-0.34549230337143,-0.35256057977675997,-0.35950377583504001,-0.36633178591728,-0.37302586436272001,-0.37957790493964999,-0.38599863648415,-0.39229124784469999,-0.39845445752143999,-0.40448996424674999,-0.41039016842842002,-0.41615363955498003,-0.42177417874335998,-0.4272503554821,-0.43257603049277998,-0.43775171041489003,-0.44276332855224998,-0.44760629534721003,-0.45227527618407998,-0.45676165819168002,-0.46109041571616999,-0.46527311205864003,-0.46929740905762002,-0.47315821051598,-0.47686448693275002,-0.48041597008705,-0.48382696509361001,-0.48710957169532998,-0.49023747444152999,-0.49319890141486999,-0.49600553512572998,-0.49865344166755998,-0.50117242336273005,-0.50358128547668002,-0.50585073232651001,-0.50796890258788996,-0.50994795560837003,-0.51178932189940995,-0.51349908113480003,-0.51507884263991999,-0.51653504371643,-0.51787465810776001,-0.51908057928085005,-0.52014040946960005,-0.52107989788054998,-0.52190572023392001,-0.52262866497039995,-0.52325552701949996,-0.52378332614899004,-0.52421206235885998,-0.52454125881195002,-0.52476352453232,-0.52490949630737005,-0.52499496936797996,-0.52500605583190996,-0.52493745088577004,-0.52479815483092995,-0.52458983659743996,-0.52431839704514005,-0.52398568391800004,-0.52359753847122004,-0.52315765619277999,-0.52266407012938998,-0.52211123704910001,-0.52152180671691994,-0.52090454101562,-0.52026259899139005,-0.51960331201553001,-0.51890963315964,-0.51816880702972001,-0.51740676164626997,-0.51663607358931996,-0.51584428548812999,-0.51502221822739003,-0.51419401168822998,-0.51337248086928999,-0.51254522800446001,-0.51170480251312001,-0.51086801290511996,-0.51004391908645996,-0.50922167301178001,-0.50839394330978005,-0.50757747888564997,-0.50678330659866,-0.50599312782287997,-0.50519591569901001,-0.50440955162047996,-0.50363761186599998,-0.50289201736449995,-0.50218200683594005,-0.50149667263030995,-0.50082468986510997,-0.50019770860671997,-0.49963641166687001,-0.49911168217659002,-0.49860480427741999,-0.49815055727959001,-0.49777156114577997,-0.49743169546126997,-0.49711605906487,-0.49683079123496998,-0.49657401442527999,-0.49635317921638,-0.49617201089858998,-0.49602892994880998,-0.49592193961143,-0.49585840106009998,-0.49584019184112998,-0.49587315320969,-0.49596101045608998,-0.49610242247580999,-0.49630111455916998,-0.49654251337050997,-0.49682077765464999,-0.49713176488875999,-0.49746963381767001,-0.49784341454505998,-0.49825885891914001,-0.49870705604553001,-0.49918213486670998,-0.49969306588173001,-0.50024574995041005,-0.50083118677139005,-0.50144547224045,-0.50209027528762995,-0.50276350975036999,-0.50347262620926003,-0.50422346591948997,-0.50500714778900002,-0.50582170486449995,-0.50666129589080999,-0.50751608610152998,-0.50840997695922996,-0.50936442613601995,-0.51033818721770996,-0.51130944490432995,-0.51229345798491999,-0.51329034566878995,-0.51431322097777998,-0.51537579298018998,-0.51645296812056996,-0.51752889156341997,-0.51862299442291004,-0.51974529027938998,-0.52088522911071999,-0.52204072475433005,-0.52320617437363004,-0.52437359094619995,-0.52555918693542003,-0.52677488327026001,-0.52800303697586004,-0.52923351526259999,-0.53047680854796997,-0.53173476457596003,-0.53301352262497004,-0.53432476520537997,-0.53563815355301003,-0.53693330287933005,-0.53823125362395996,-0.53954410552979004,-0.54085445404053001,-0.54215580224991,-0.54344433546065996,-0.54471600055695002,-0.54597252607346003,-0.54721581935883001,-0.54843866825104004,-0.54963505268097002,-0.55081349611282004,-0.55197435617446999,-0.55313026905060003,-0.55429559946060003,-0.55544555187224998,-0.55656570196152,-0.55766814947127996,-0.55876106023787997,-0.55982863903045998,-0.56086641550063998,-0.56186336278914994,-0.56279915571213002,-0.56371968984604004,-0.56465822458267001,-0.56557661294937001,-0.56645578145981001,-0.56730937957764005,-0.56813788414000999,-0.56895357370376998,-0.56977105140686002,-0.57056593894957996,-0.57132524251937999,-0.57205408811569003,-0.57275247573853005,-0.57342034578322998,-0.57405972480774003,-0.57466363906859996,-0.57522779703140003,-0.57575386762618996,-0.57623970508574995,-0.57669234275818004,-0.57711219787598,-0.57751160860062001,-0.57790505886078003,-0.57826852798462003,-0.57858878374099998,-0.57887095212936002,-0.57911294698714999,-0.57932174205779996,-0.57949972152710005,-0.57965219020844005,-0.57978749275207997,-0.57989013195037997,-0.57994920015335005,-0.57997506856918002,-0.57997012138366999,-0.57993954420089999,-0.57988780736922996,-0.57981312274932995,-0.57970952987670998,-0.57959783077240001,-0.57950329780579002,-0.57937949895858998,-0.57918566465377996,-0.57897996902465998,-0.57880401611328003,-0.57861161231994995,-0.57838010787964,-0.57811814546585005,-0.57782769203186002,-0.57750189304351995,-0.57713228464126998,-0.57673400640488004,-0.57631236314774004,-0.57587748765945002,-0.57544642686844005,-0.57498860359191994,-0.57447576522827004,-0.57394868135452004,-0.57343816757202004,-0.57290875911713002,-0.57233989238739003,-0.57174533605575995,-0.57113361358643,-0.57048958539963002,-0.56980192661285001,-0.56908094882964999,-0.56833320856094005,-0.56755030155181996,-0.56672751903534002,-0.56586652994155995,-0.56496143341063998,-0.56403237581252996,-0.56310129165649003,-0.56213623285294001,-0.56111043691634999,-0.56005758047104004,-0.55900245904921997,-0.55791819095612005,-0.55678445100784002,-0.55562663078308006,-0.5544627904892,-0.55327439308167004,-0.55204999446868996,-0.55079990625381003,-0.54953664541244995,-0.54823195934295998,-0.54685693979262995,-0.54545158147812001,-0.54404777288437001,-0.54261040687561002,-0.54111617803573997,-0.53958541154860995,-0.53802967071533003,-0.53643894195556996,-0.53481030464171997,-0.53313893079758001,-0.53141206502913996,-0.52965766191482999,-0.52789711952208995,-0.52611672878265003,-0.52430778741837003,-0.52248507738113004,-0.52066618204116999,-0.51882165670394997,-0.51692789793015004,-0.51500505208969005,-0.51306486129760998,-0.51109737157821999,-0.50909954309464001,-0.50706678628921997,-0.50499415397643999,-0.50288337469100997,-0.50073450803757003,-0.49854749441147,-0.49631839990616,-0.49406003952026001,-0.49178245663643,-0.48948198556900002,-0.48715865612030002,-0.48481249809264998,-0.48244738578795998,-0.48005062341690002,-0.47761014103888999,-0.47513601183891002,-0.47263711690902999,-0.47009897232056003,-0.46750947833061002,-0.46487861871719,-0.46221145987510998,-0.45950624346732999,-0.4567648768425,-0.45398101210594,-0.45114561915397999,-0.44827324151992998,-0.44537594914436002,-0.44244381785393,-0.43946388363838002,-0.43646311759949002,-0.43346792459487998,-0.43045216798781999,-0.42739850282669001,-0.42431864142418002,-0.42121970653534002,-0.41809365153313,-0.41494116187095997,-0.41174539923668002,-0.40848878026009,-0.40518307685852001,-0.40183153748512002,-0.39843848347664002,-0.39501115679741,-0.39154142141342002,-0.38802218437195002,-0.38446143269539002,-0.38086244463920998,-0.37722957134246998,-0.37356805801392001,-0.36987602710723999,-0.36614564061165,-0.36240160465240001,-0.35867279767990001,-0.35492718219757002,-0.35114371776580999,-0.34732979536057002,-0.34349125623702997,-0.33960971236228998,-0.33566731214522999,-0.33167573809624001,-0.32763826847076,-0.32355925440788003,-0.31944200396537997,-0.31529080867767001,-0.31111291050911,-0.30690038204192999,-0.30264598131179998,-0.29835757613182001,-0.29404246807098,-0.28969275951384998,-0.28530114889144997,-0.28087550401688,-0.27642709016799999,-0.27193593978882002,-0.26738193631172003,-0.26278275251388999,-0.25814333558083002,-0.25347799062728998,-0.24880881607533001,-0.24411223828792999,-0.23936615884303999,-0.23459407687187001,-0.22984728217125,-0.22501274943352001,-0.21995912492274999,-0.21482133865356001,-0.20968283712864,-0.20454148948192999,-0.19943831861019001,-0.19432242214680001,-0.18914175033569,-0.18395084142685,-0.17879992723464999,-0.17364042997359999,-0.16843335330486001,-0.16320766508578999,-0.15798388421535001,-0.15274457633495001,-0.14747670292854001,-0.14218989014625999,-0.13689358532429,-0.13157418370247001,-0.12621857225895,-0.12083640694618,-0.11543133854866,-0.11000730842351999,-0.10457184165716001,-0.099117241799831002,-0.093641720712185003,-0.088135562837123996,-0.082579836249352001,-0.077001489698886996,-0.071428850293158999,-0.065837010741234006,-0.060208979994058998,-0.054550465196371002,-0.048859551548957998,-0.043141983449459,-0.037401542067528,-0.031642060726880999,-0.025871150195599001,-0.020081179216504,-0.0044557023793458999,0.0012495806440711,0.0085998158901929994,0.015165684744715999,0.021746831014751999,0.028331777080893999,0.034924350678921003,0.041522637009621,0.048132322728633999,0.054762966930865999,0.061401333659887002,0.068032070994376997,0.074670314788817999,0.081329531967640006,0.088000252842902998,0.094676665961741999,0.10136070847511,0.10805048048495999,0.11475159972906,0.12146987766027,0.12820339202881001,0.13495405018330001,0.14171624183654999,0.14848227798939001,0.15525960922241,0.16205221414566001,0.16886372864245999,0.17570383846759999,0.18255946040154,0.18941695988178001,0.19628572463989,0.20317734777926999,0.21007327735424,0.21695576608181,0.22383064031600999,0.23069790005683999,0.23755753040314001,0.24440954625607,0.25125396251678001,0.25809255242348,0.26491996645927002,0.27173018455504999,0.27852514386177002,0.28530305624008001,0.29206925630568997,0.29882976412772999,0.30558267235755998,0.31232982873916998,0.31906583905219998,0.32578274607657998,0.33248794078826999,0.33918750286102001,0.34587943553924999,0.35256740450858998,0.35924077033996998,0.36588364839554,0.37251067161559998,0.37913393974303999,0.38574960827826998,0.39235767722129999,0.39895811676978998,0.40555280447005998,0.41213634610175998,0.41870087385178001,0.42525357007980003,0.43180257081985002,0.43834045529366,0.44486102461815002,0.45136639475821999,0.45785656571388,0.46433144807816001,0.47079116106032998,0.47723552584647999,0.48366659879683999,0.49007892608643,0.49646833539009,0.50283139944077004,0.50915843248366999,0.51546168327331998,0.52175909280777,0.52803111076355003,0.53425550460814997,0.54044848680496005,0.54662078619002996,0.55277353525161999,0.55891847610473999,0.56503814458847001,0.57111018896103005,0.57715076208115001,0.58317238092421997,0.58917117118835005,0.59515064954758001,0.60110068321228005,0.60700511932373002,0.61287796497345004,0.61873549222946,0.62456369400024003,0.63034969568252996,0.63609760999679998,0.64180743694304998,0.64747911691666005,0.65311455726624001,0.65870857238769998,0.66425126791,0.66975480318069003,0.67523354291916005,0.68067860603332997,0.68608349561690996,0.69145041704178001,0.69678086042403997,0.70207005739212003,0.70730972290038996,0.71250677108765004,0.71766960620880005,0.72279113531113004,0.72786307334900002,0.73289251327515004,0.73788940906525002,0.74284183979034002,0.74773341417313,0.75257784128188998,0.75739008188248003,0.76216101646422996,0.76688414812088002,0.77156150341034002,0.77619332075118996,0.78077924251555997,0.78531777858733998,0.78981363773346003,0.79427510499954002,0.79869538545608998,0.80306619405746005,0.80739444494247004,0.81168991327286,0.81594109535216996,0.82013338804244995,0.82427531480788996,0.82837516069411998,0.83242624998092996,0.83642035722732999,0.84036409854889005,0.84426748752594005,0.84811913967133001,0.85190421342849998,0.85563123226166005,0.85930502414703003,0.86292850971222002,0.86651021242142001,0.87004309892653997,0.87351870536803999,0.87694400548935003,0.88032567501068004,0.88366156816482999,0.88695180416107,0.89019620418548995,0.89339488744735995,0.89654785394669001,0.89965689182280995,0.90271711349487005,0.90572035312652999,0.90867310762404996,0.91158211231232,0.91444534063339,0.91726481914519997,0.92003554105759,0.92274731397628995,0.92541170120239002,0.92804354429244995,0.93063461780547996,0.93317943811417003,0.93567574024199995,0.93811321258545,0.94050312042235995,0.94286233186722002,0.94517779350280995,0.94743406772614003,0.94963991641998002,0.95180183649062999,0.95391809940338002,0.95598882436751997,0.95801371335982999,0.95999628305435003,0.96192747354507002,0.96379023790358997,0.96559768915176003,0.96736663579940996,0.96908438205719005,0.97073560953140003,0.97232848405838002,0.97386997938155995,0.97535818815231001,0.97679466009140004,0.97817504405974998,0.97948908805847001,0.98074769973755005,0.98196434974669999,0.98313540220260998,0.98426264524460005,0.98534137010573997,0.98636287450789994,0.98733377456664995,0.98826092481613004,0.98914241790770996,0.98997813463211004,0.99076819419860995,0.99151074886321999,0.99221026897429998,0.99287718534470004,0.99350053071975997,0.99406319856643999,0.99457776546478005,0.99505990743636996,0.99550133943557995,0.99589335918427002,0.99624216556548995,0.99655675888062001,0.99683046340942005,0.99705487489699995,0.99723607301712003,0.99738293886185003,0.99748909473419001,0.99754399061203003,0.99755859375,0.99754983186722002,0.99750560522079001,0.99740815162659002,0.99727022647857999,0.99710565805435003,0.99691081047058006,0.99668699502945002,0.99643021821975997,0.99613332748412997,0.99579828977585005,0.99542516469955,0.99501383304596003,0.99456119537354004,0.99407553672791005,0.99357092380524004,0.99304354190826005,0.99249660968780995,0.99192172288894997,0.99130493402481001,0.99064970016479004,0.98995482921599998,0.98922431468964001,0.98846703767776001,0.98767685890197998,0.98684638738632002,0.98597788810730003,0.98507279157639005,0.98412710428238004,0.98313051462172996,0.98209303617476995,0.98103243112563998,0.97993648052215998,0.97878742218018,0.97759741544723999,0.97638267278670998,0.97513514757155995,0.97384893894196001,0.97252225875854004,0.97114461660384999,0.96972608566284002,0.96828413009643999,0.96680706739426003,0.96527868509293002,0.96370685100554998,0.96210050582885998,0.96045380830765004,0.95875751972197998,0.95701783895492998,0.95524233579635998,0.95342862606048995,0.95157516002654996,0.94968593120574996,0.94776821136474998,0.94582003355026001,0.94384312629699996,0.94183337688446001,0.93978011608124001,0.93769347667694003,0.93558949232100996,0.93346053361893,0.93129581212997004,0.92910510301589999,0.92690646648407005,0.92468798160553001,0.92243516445160001,0.92015165090561002,0.91783618927001998,0.91549241542815996,0.91312611103057995,0.91073936223983998,0.90834087133408004,0.90592497587204002,0.90348261594771995,0.90101957321167003,0.89854329824447998,0.89605188369750999,0.89354676008223999,0.89102411270142001,0.88847517967223999,0.88590544462204002,0.88332396745681996,0.88072526454926003,0.87809997797011996,0.87545394897461004,0.87279474735259999,0.87012040615081998,0.86743229627608998,0.86472690105437999,0.86199331283569003,0.85924118757248003,0.85648548603057995,0.85372227430344005,0.85095137357712003,0.84817296266555997,0.84538841247559005,0.84259414672851995,0.83977949619293002,0.83695393800734996,0.83413523435592996,0.83131247758865001,0.82846903800964,0.82561224699019997,0.82274991273880005,0.81987994909285999,0.81700247526169001,0.81411737203598,0.81122446060180997,0.80832397937775002,0.80541753768920998,0.80250126123428001,0.79956483840942005,0.79661709070205999,0.79367488622664994,0.79073083400725996,0.78777557611464999,0.78481465578079002,0.78185725212097001,0.77889794111251998,0.77592587471008001,0.77295011281966997,0.76998758316039995,0.76703083515167003,0.76407206058501997,0.76111322641373003,0.75815433263778997,0.75519549846649003,0.75223666429519997,0.74927777051926003,0.74632048606873003,0.74336117506027,0.74038922786713002,0.73741346597671997,0.73445236682892001,0.73149520158768,0.72852486371993996,0.72554862499237005,0.72257298231125,0.71959930658339999,0.71663671731948997,0.71367996931076005,0.71071970462798995,0.70776122808455999,0.70481383800507003,0.70187234878539995,0.69892579317092995,0.69598293304443004,0.69306230545044001,0.69015330076217996,0.68723899126053001,0.68432623147964,0.68142306804657005,0.67852753400803001,0.67563986778259,0.67275965213776001,0.66988712549210006,0.66702222824097002,0.66416490077972001,0.66131520271301003,0.65847462415695002,0.65563988685607999,0.65280014276505005,0.64996391534804998,0.64714837074279996,0.64434653520583995,0.64155030250549006,0.63876163959502996,0.63598048686981001,0.63320702314376998,0.63043969869614003,0.62768173217773005,0.62494248151778997,0.62221682071686002,0.61949831247330001,0.61678552627562999,0.61406797170639005,0.61135363578795998,0.60865998268126997,0.60598003864287997,0.60330426692963002,0.60063773393631004,0.59798997640609997,0.59535574913025002,0.59272581338882002,0.59010505676269998,0.58750289678573997,0.58491438627242998,0.58233022689819003,0.57975518703461004,0.57719880342483998,0.57465612888336004,0.57211756706238004,0.56958824396133001,0.56707757711411,0.56458061933517001,0.56209081411362005,0.55960685014724998,0.55711799860000999,0.55463230609893999,0.55216580629348999,0.54971468448639005,0.54728180170059004,0.54486089944839,0.54243469238280995,0.54000979661941995,0.53759306669234996,0.53518569469452004,0.53279685974121005,0.53042185306548995,0.52805107831955,0.52568942308426003,0.52334630489348999,0.52101707458496005,0.51869350671768,0.51637744903563998,0.51406753063202004,0.51176685094832997,0.50948321819304998,0.50721502304077004,0.50496214628220004,0.50272446870804,0.50050348043441995,0.49829620122910001,0.49609175324440002,0.49389782547951,0.49173060059547002,0.48958656191826,0.48746541142464,0.48536705970763999,0.48329159617424,0.48123893141746998,0.47920924425125,0.47720232605933999,0.47521981596946999,0.47325861454009999,0.47131076455116,0.46937805414200001,0.46745908260344998,0.46555685997009,0.46368077397346003,0.46182623505592002,0.45998516678809998,0.45815914869308,0.45634835958481001,0.45455279946326999,0.45277383923531,0.45100870728492998,0.44924664497375,0.44749480485915999,0.44577232003211997,0.44407024979590998,0.44237071275710999,0.44067978858947998,0.43900740146637002,0.43734902143477999,0.43569505214691001,0.43404996395111001,0.43242183327674999,0.43080917000771002,0.42921456694603,0.42763242125510997,0.42604386806487998,0.42445757985115001,0.42289170622826,0.42134010791778997,0.41979557275772,0.41825720667839,0.41671419143677002,0.4151736497879,0.41365346312522999,0.41214752197266002,0.41064605116844,0.40915325284004,0.40767896175384999,0.40621879696846003,0.40476441383362,0.40331748127937,0.40187540650367998,0.40044352412223999,0.39903953671455,0.39765754342079002,0.3962889611721,0.39493539929389998,0.39359709620476002,0.39227405190468001,0.39096760749817,0.38967517018317999,0.38838717341423001,0.38710781931876997,0.38584688305855003,0.38460016250610002,0.38335925340652,0.38212579488754,0.38089987635611999,0.37968161702156,0.37847098708152999,0.37726795673370001,0.37607127428054998,0.37488341331482,0.37371516227722001,0.37256008386612,0.37140005826950001,0.37024077773094,0.36908954381942999,0.36794731020927002,0.36682352423668002,0.36571404337883001,0.36461162567138999,0.36351552605629001,0.36241632699965998,0.36131799221039002,0.36022910475731001,0.35914805531501998,0.35807460546494002,0.35700878500937999,0.35595062375068998,0.35490009188652,0.35385578870772999,0.35282024741173001,0.35180437564849998,0.35080176591873002,0.34979304671287997,0.34878596663474998,0.34779900312424,0.34682670235634,0.34585890173911998,0.34489953517914002,0.34395986795424999,0.34303349256516003,0.34210103750228998,0.34117019176482999,0.34025812149048001,0.33936178684235002,0.33848190307616999,0.33761626482009999,0.33675527572632002,0.33590266108513001,0.33506959676742998,0.33424997329711997,0.33342561125754999,0.33260172605514998,0.33178722858428999,0.33098062872887002,0.33018159866333002,0.32939019799232,0.32860645651817,0.32783031463623002,0.32706177234650002,0.32630088925362,0.32554888725281,0.32480350136757002,0.32405644655228,0.32330912351607999,0.32256051898003002,0.32181283831596003,0.32107454538344998,0.32034412026405001,0.31962257623672002,0.31890770792960998,0.31818988919258001,0.31747269630432001,0.31676489114760997,0.31606495380402,0.31537386775017001,0.31468951702117998,0.31400346755981001,0.31331717967986999,0.31262958049773998,0.31194287538527998,0.31126675009727001,0.31059762835503002,0.30992436408996998,0.30925250053406,0.30860179662704001,0.30796518921852001,0.30732393264771002,0.30668297410010997,0.30605256557464999,0.30542925000191001,0.30480295419692999,0.30417722463607999,0.30356079339981001,0.30295228958129999,0.30235141515732,0.30175814032554998,0.30117252469062999,0.30059450864791998,0.30002409219741999,0.29946130514144997,0.29890492558478998,0.29835700988769998,0.29782715439795998,0.29731211066245999,0.29680296778679,0.29630118608474998,0.29580581188201999,0.29531878232955999,0.29484993219375999,0.29439583420753002,0.29394772648811002,0.29350692033768,0.29307252168655001,0.29264652729034002,0.29223740100861001,0.29184380173683,0.29146665334701999,0.29110404849052002,0.29074740409851002,0.29039809107780001,0.29005518555641002,0.28972062468528997,0.28940412402152998,0.28910249471664001,0.28880682587624001,0.28851848840714001,0.28823658823967002,0.28796300292014998,0.28770628571509999,0.28746509552001998,0.28724035620688998,0.28703019022942,0.28682368993759,0.28662574291228998,0.28645515441894998,0.28630739450455001,0.28617209196090998,0.28605234622955,0.28595706820487998,0.28588500618934998,0.28583580255508001,0.28580945730209001,0.28580597043036998,0.28582537174224998,0.28586760163307001,0.28593271970749001,0.28602185845375,0.28613328933715998,0.28625950217246998,0.28640004992485002,0.28654432296753002,0.28669705986977001,0.28687810897826999,0.28708153963089,0.28728714585303999,0.28750079870223999,0.28774169087410001,0.2880055308342,0.28828424215317,0.28857725858687999,0.28887519240379,0.28918090462684998,0.28950345516205001,0.28984162211418002,0.29019501805304998,0.29056367278098999,0.29094865918159002,0.29134842753410001,0.29175308346748002,0.29216554760933,0.29259479045867998,0.29303961992263999,0.29349973797798001,0.29397505521773998,0.29446566104888999,0.29497149586678001,0.29549255967139998,0.29602885246277,0.29658043384552002,0.29714721441268999,0.29772928357124001,0.29832658171653997,0.29894024133682001,0.29956871271133001,0.30020323395728998,0.30084499716759,0.30149444937705999,0.30215150117874001,0.30281615257263,0.30348840355873002,0.30416944622992997,0.30485764145851002,0.30554217100143,0.30622711777687001,0.30693143606186002,0.30765134096146002,0.30837732553482,0.30911061167717002,0.30985149741173001,0.31060001254081998,0.31135502457619002,0.31211805343628002,0.31290003657340998,0.31369689106941001,0.31448966264724998,0.31528204679489003,0.31608349084853998,0.31689298152924,0.31771117448807001,0.31853663921356001,0.31935954093933,0.32018238306045999,0.32101434469223,0.32185432314873003,0.32270193099976002,0.32355713844299,0.32442212104797002,0.32529407739638999,0.32615226507187001,0.32700300216674999,0.32787439227103998,0.32876193523406999,0.32965567708014998,0.33055663108826,0.33146515488625,0.33238133788108998,0.33330622315406999,0.33423846960067999,0.33516919612884999,0.33609953522682001,0.33702883124352001,0.33795842528343001,0.33889809250831998,0.33984556794166998,0.3407926261425,0.34173902869224998,0.34267535805701999,0.34360384941101002,0.34453383088112,0.34546416997910001,0.34639453887938998,0.34732493758201999,0.34825631976128002,0.34918749332428001,0.35010862350464,0.35102188587188998,0.35193553566933,0.35284981131554,0.35377621650696001,0.35471010208129999,0.35562142729759,0.35651674866675997,0.35742494463920998,0.35834190249442999,0.35925742983817999,0.36017253994942,0.36108765006065002,0.36200276017188998,0.36291787028313,0.36383295059204002,0.36474809050559998,0.36566323041915999,0.36657932400703003,0.36749532818794001,0.36840230226517001,0.36930122971535001,0.37019252777099998,0.37107622623443998,0.37195330858231002,0.37282264232634998,0.37367439270019998,0.3745105266571,0.37534141540527,0.37616503238678001,0.37697103619576,0.37776145339012002,0.37854656577110002,0.37932443618773998,0.38008475303650002,0.38082945346831998,0.38156878948211997,0.38230091333388999,0.38301652669906999,0.38371640443802002,0.38440003991126998,0.38506850600242998,0.38573160767554998,0.38638749718665999,0.38702690601348999,0.38765051960945002,0.38825896382331998,0.3888521194458,0.38943004608154003,0.38999268412589999,0.39054211974143999,0.39107623696326999,0.39157530665397999,0.39204296469687999,0.39249795675277999,0.39293867349625,0.39336511492728998,0.39377626776695002,0.39416331052780001,0.39452704787254,0.39486688375473,0.39518386125565003,0.39548784494400002,0.39577707648277,0.39604216814040999,0.39628392457961997,0.39650282263755998,0.39669877290726002,0.39687198400496998,0.39702224731445002,0.39714968204498002,0.39725422859192,0.39733591675758001,0.39739468693732999,0.39743068814277999,0.39744374155998002,0.39743396639824002,0.3974013030529,0.39734581112862,0.39726740121840998,0.39716616272925997,0.39704203605652,0.39689412713050998,0.39672324061393999,0.39654022455214999,0.39634263515472001,0.39611217379570002,0.39585015177727001,0.39555770158768,0.39523473381995999,0.39488035440445002,0.39449533820152,0.39409053325652998,0.39366364479065002,0.39319437742232999,0.39268568158150002,0.39215838909148998,0.39160957932472001,0.39101836085320002,0.39038771390915,0.38973656296730003,0.38906362652778997,0.38836961984634,0.38765311241150002,0.38689520955085999,0.38609796762465998,0.38527229428290999,0.38441684842110002,0.38352128863335,0.38258683681487998,0.38162398338317999,0.38063135743141002,0.37959858775138999,0.37852695584297003,0.37742596864700001,0.37629500031471003,0.37513449788094,0.37394368648529003,0.37271365523338001,0.37144494056701999,0.37013819813727999,0.36879324913025002,0.36740934848785001,0.36598709225655002,0.36453542113303999,0.36305382847786,0.36154356598853998,0.36000329256058,0.35841244459152,0.35677397251129001,0.35511764883995001,0.35344070196152,0.35172343254089,0.34996697306633001,0.34817233681679,0.34633958339691001,0.34446793794632002,0.34255784749985002,0.34061834216117998,0.33864888548851002,0.33664986491202997,0.33462080359459001,0.3325514793396,0.33044320344924999,0.32830551266669999,0.32613793015480003,0.32393983006477001,0.32171124219893998,0.31945303082465998,0.31716468930244002,0.31483542919159002,0.31246683001518,0.31007999181746998,0.30767250061035001,0.30521446466446001,0.30270823836326999,0.30017524957656999,0.29761371016501997,0.29500347375870001,0.29234600067138999,0.28965142369270003,0.28691938519478,0.28414916992188,0.28134086728096003,0.27849528193473999,0.27561196684837003,0.27268108725548001,0.26970347762107999,0.26669043302536,0.26364067196846003,0.26053389906883001,0.25737175345420998,0.25417345762253002,0.25093829631804998,0.24766501784325001,0.24435363709926999,0.24100330471991999,0.23761443793774001,0.23419606685638,0.23074780404567999,0.22726908326149001,0.22375987470149999,0.22022014856339001,0.21664994955062999,0.21305087208748,0.20942223072051999,0.20574429631232999,0.20201848447323001,0.19826491177082001,0.19448255002498999,0.19065950810908999,0.1867967993021,0.1829147040844,0.17901197075844,0.17506763339042999,0.17108295857906,0.16707807779312001,0.16305208206176999,0.15899468958377999,0.15490616858006001,0.15078714489937001,0.14663763344288,0.14245684444904,0.13824507594109001,0.13401211798191001,0.12975746393203999,0.12546983361243999,0.12115001678466999,0.11681833863258,0.11247375607491,0.10809690505265999,0.10368827730417,0.099247582256794004,0.094775326550007005,0.090290367603302002,0.085792005062102994,0.081269904971123005,0.076724283397198001,0.072155028581618999,0.067562349140644004,0.062956050038337999,0.058335732668638,0.053691692650318,0.049024119973182997,0.044332925230264997,0.039618279784917998,0.034890003502369003,0.030147729441523999,0.025380985811353,0.020590120926498999,0.015784842893481001,0.010964989662170001,0.0061306487768887996,0.0012816679663956001,-0.0035902438685298001,-0.0084850881248713008,-0.013412741012871,-0.018372790887952,-0.023346468806267,-0.028334032744168999,-0.033336840569972999,-0.038354892283677999,-0.043387442827225002,-0.048434600234032003,-0.053506165742874,-0.058601915836334,-0.063712872564792994,-0.068839035928248998,-0.073971293866633994,-0.079109832644463002,-0.084265127778053006,-0.089437022805213998,-0.094615034759044994,-0.099799305200577004,-0.10500031709671,-0.11021793633698999,-0.11544243246317,-0.12067385017872,-0.12591215968132,-0.13115739822388001,-0.13641864061355999,-0.14169582724571,-0.14698897302151001,-0.15229806303978,-0.15761403739452001,-0.16293694078922,-0.16826817393303001,-0.17360772192478,-0.17894586920738001,-0.18428257107734999,-0.18962974846363001,-0.19498743116855999,-0.20032632350922,-0.20564636588096999,-0.21096849441528001,-0.21629279851913,-0.22160810232162001,-0.22691433131694999,-0.23222121596336001,-0.23752884566783999,-0.24283577501774001,-0.24814194440842,-0.25345712900161999,-0.25878143310547003,-0.26410502195357999,-0.26942792534827997,-0.27475079894066001,-0.28007367253304,-0.28539654612540999,-0.29071941971778997,-0.29604229331017001,-0.30136516690254,-0.30668872594833002,-0.31201308965683,-0.31732851266861001,-0.32263475656509,-0.32794299721718001,-0.33325359225272999,-0.33854699134826999,-0.34382283687592002,-0.34909173846245001,-0.35435372591018999,-0.35960876941681003,-0.36485698819160001,-0.37008938193321,-0.37530577182769997,-0.38050690293312001,-0.38569280505179998,-0.39086413383483998,-0.39602103829384,-0.40115314722061002,-0.40625998377799999,-0.41136166453362,-0.41645893454552002,-0.42153155803679998,-0.42657893896103,-0.43161091208458002,-0.43662759661674,-0.4416378736496,-0.44664219021797003,-0.45163065195084001,-0.45660310983657998,-0.4615603685379,-0.46650233864784002,-0.47142973542213001,-0.47634276747704002,-0.48123240470885997,-0.48609837889670998,-0.49094212055205999,-0.49576392769813998,-0.50055468082428001,-0.50531411170958995,-0.51004248857498002,-0.51473951339722002,-0.51941537857055997,-0.52407103776931996,-0.52868688106536998,-0.53326207399367997,-0.53780740499496005,-0.54232299327849998,-0.54680740833282004,-0.55126041173935003,-0.55569171905518,-0.56010192632675004,-0.56448048353195002,-0.56882679462432995,-0.57315200567244995,-0.57745701074599998,-0.58172172307967995,-0.58594483137131004,-0.59014660120009999,-0.59432810544967996,-0.59847801923751998,-0.60259568691253995,-0.60669153928757003,-0.61076629161835005,-0.61480957269669001,-0.61882054805756004,-0.62280899286269997,-0.62677544355392001,-0.63071972131729004,-0.63464206457137995,-0.63853347301482999,-0.64239352941512995,-0.64622259140015004,-0.65002012252807995,-0.65379518270492998,-0.65754818916321001,-0.66127961874008001,-0.66499018669127996,-0.66866052150725996,-0.67228907346724998,-0.67589741945267001,-0.67948764562607,-0.68302971124649003,-0.68652147054671997,-0.68998354673385998,-0.69341683387756003,-0.69682019948958995,-0.70019412040710005,-0.70352953672409002,-0.70682603120804,-0.71008384227752996,-0.71330243349074995,-0.71649152040482,-0.71965199708938998,-0.72277343273162997,-0.72585487365723,-0.72890609502792003,-0.73192781209946001,-0.73491954803466997,-0.73788183927536,-0.74080514907837003,-0.74368840456009,-0.74654150009154996,-0.74936491250991999,-0.75215846300125,-0.75492256879806996,-0.75764775276184004,-0.76033282279967995,-0.76298773288726995,-0.76561301946640004,-0.76820892095565996,-0.77077651023865001,-0.77329725027083995,-0.77576941251755005,-0.77820324897766002,-0.78059864044188998,-0.78296440839767001,-0.78530174493789995,-0.78760063648223999,-0.78986054658890004,-0.79208177328109997,-0.79426383972168002,-0.79641556739806996,-0.79853773117064997,-0.80062997341155995,-0.80269289016723999,-0.80471634864806996,-0.80669838190079002,-0.80865931510925004,-0.81060135364532004,-0.81250429153442005,-0.81436616182327004,-0.81619834899902,-0.81800204515456998,-0.81976693868636996,-0.82149159908295,-0.82318609952927002,-0.82485097646713001,-0.82648527622223,-0.82808911800384999,-0.82966297864913996,-0.83120757341384999,-0.83271390199661,-0.83418118953705001,-0.83561033010482999,-0.83700126409530995,-0.83835375308990001,-0.83966684341430997,-0.84095066785812,-0.84220725297928001,-0.84341740608214999,-0.84457868337631004,-0.84570151567458995,-0.84678590297698997,-0.84784108400345004,-0.84886902570723999,-0.84985047578812001,-0.85078310966491999,-0.85167783498764005,-0.85253542661667003,-0.85335421562195002,-0.85413378477097002,-0.85488337278366,-0.85560464859009,-0.85628783702849998,-0.85693186521529996,-0.85753786563873002,-0.85810577869414995,-0.85863500833510997,-0.85912489891052002,-0.85958433151244995,-0.86001425981521995,-0.86041420698166005,-0.86078494787215998,-0.86111646890640003,-0.86140644550322998,-0.86167466640472001,-0.86192435026169001,-0.86213499307632002,-0.86230295896529996,-0.86244928836822998,-0.86257708072661998,-0.86266571283339999,-0.86271184682846003,-0.86273604631423995,-0.86274188756943004,-0.86270910501480003,-0.86263501644134999,-0.86253088712692005,-0.86239850521088002,-0.86222803592681996,-0.86201846599579002,-0.86177033185958996,-0.86148279905319003,-0.86116528511046997,-0.86081945896149004,-0.86043518781661998,-0.86001038551330999,-0.85955518484116,-0.85907042026519997,-0.85855525732039994,-0.85800951719284002,-0.85743325948714999,-0.85682660341262995,-0.85618889331818004,-0.85551941394805997,-0.85482752323151001,-0.85411500930786,-0.85337167978286999,-0.85259550809859996,-0.85179680585860995,-0.85097765922545998,-0.85012757778168002,-0.84924471378326005,-0.84833890199661,-0.84741121530533003,-0.84646105766295998,-0.84548950195312,-0.84448695182800004,-0.84345161914824995,-0.84239381551742998,-0.84131538867949995,-0.84020620584488004,-0.83906418085098,-0.83789873123169001,-0.83671009540557995,-0.83550691604614002,-0.83429217338562001,-0.83304649591446001,-0.83176547288894997,-0.83046931028366,-0.82916140556335005,-0.82783073186874001,-0.82647633552551003,-0.82509851455687999,-0.82369643449783003,-0.82227891683578003,-0.82084721326828003,-0.81940019130706998,-0.81793797016143999,-0.81646090745926003,-0.81497007608413996,-0.81345564126967995,-0.81191450357437001,-0.81036579608917003,-0.80881297588348,-0.80724549293518,-0.80566316843033003,-0.80405730009079002,-0.80242466926574996,-0.80078452825545998,-0.79914021492003995,-0.79748046398162997,-0.79580295085907005,-0.79411762952804998,-0.79242569208144997,-0.79072654247284002,-0.78902125358581998,-0.78730094432830999,-0.78556430339812999,-0.78381210565567005,-0.78204321861267001,-0.78026634454726995,-0.77848291397095004,-0.77669227123259998,-0.77489548921585005,-0.77308374643326006,-0.77125567197800005,-0.7694119811058,-0.76755160093306996,-0.76568329334259,-0.76380836963653997,-0.76192545890808006,-0.76003348827362005,-0.75814163684845004,-0.75625228881836004,-0.75435525178909002,-0.75244802236556996,-0.75054043531418002,-0.74863398075104004,-0.74672865867615001,-0.74482780694962003,-0.74290436506270996,-0.74095183610916004,-0.73899167776107999,-0.73702907562256004,-0.73504322767258001,-0.73302781581878995,-0.73101204633713002,-0.72900259494780995,-0.72697824239731001,-0.72493493556975996,-0.72288322448730002,-0.72082352638244995,-0.71876382827759,-0.71670669317244995,-0.71464240550994995,-0.71256929636001998,-0.71048867702483998,-0.70840036869048995,-0.70630484819411998,-0.70420324802399004,-0.70208638906479004,-0.69995164871215998,-0.69780886173248002,-0.69565951824187999,-0.69350266456604004,-0.69133812189101995,-0.68916565179824996,-0.68698394298553001,-0.68480181694030995,-0.68262088298797996,-0.68043947219848999,-0.67825663089751997,-0.67608153820037997,-0.67391824722289995,-0.67174804210662997,-0.66956645250320002,-0.66738426685332997,-0.66520327329635998,-0.66302192211151001,-0.66083902120589999,-0.65866357088089,-0.65649843215942005,-0.65433412790297996,-0.65217030048369995,-0.64999866485596003,-0.64781516790390004,-0.64563816785812,-0.64347112178802002,-0.64131236076355003,-0.63916432857512995,-0.63700878620148005,-0.63483858108520996,-0.63268268108367998,-0.63054859638214,-0.62841564416884999,-0.62628042697905995,-0.62414449453354004,-0.62200540304184004,-0.61988037824631004,-0.61777293682098,-0.61568105220795,-0.61360597610473999,-0.6115391254425,-0.60947877168654996,-0.60742604732512995,-0.60538089275359996,-0.60334342718124001,-0.60131353139876997,-0.59929162263869995,-0.59727889299393,-0.59526652097702004,-0.59325134754180997,-0.59124350547791005,-0.58924603462219005,-0.58724892139435003,-0.58524900674820002,-0.58325600624083995,-0.58127182722091997,-0.57929503917694003,-0.57732415199279996,-0.57536816596984997,-0.57343024015427002,-0.57150065898894997,-0.56957751512527,-0.56766134500503995,-0.56574946641921997,-0.56386005878447998,-0.56200081110000999,-0.56014275550841996,-0.55827617645264005,-0.55643123388289994,-0.55461770296097002,-0.55280572175980003,-0.55098682641982999,-0.54918235540390004,-0.54739886522293002,-0.54561650753020996,-0.54383009672164995,-0.54205054044723999,-0.54027980566025002,-0.53851675987243997,-0.53676128387451005,-0.53501337766646995,-0.53327322006225997,-0.53153997659683005,-0.52981108427047996,-0.52810436487197998,-0.52642792463303001,-0.52475333213805997,-0.52307170629500999,-0.5214039683342,-0.51975566148758001,-0.51811581850052002,-0.51648235321045,-0.51485669612884999,-0.51324039697646995,-0.51162439584732,-0.51000374555588002,-0.50839728116989003,-0.50681185722350997,-0.50522786378859996,-0.50363963842392001,-0.50205826759338001,-0.50048577785491999,-0.49892112612723999,-0.49736583232879999,-0.49581110477447998,-0.49425342679023998,-0.49270281195641003,-0.49116271734237998,-0.48962354660034002,-0.48808309435844,-0.48654243350028997,-0.48500001430511003,-0.48346433043480003,-0.48193749785423001,-0.48041799664496998,-0.47890442609786998,-0.47740548849106001,-0.47592473030089999,-0.47445228695869002,-0.47298443317413003,-0.47153121232986001,-0.47009617090224998,-0.46866974234580999,-0.46724963188170998,-0.46583691239357,-0.46443009376526001,-0.46303778886795,-0.46166372299193997,-0.4602980017662,-0.45893692970276001,-0.45759057998656999,-0.45626422762871,-0.45493963360785999,-0.45361074805259999,-0.45228871703147999,-0.45097732543945002,-0.44966647028923001,-0.44835081696509999,-0.44704884290695002,-0.44576823711395003,-0.44448965787888001,-0.44320851564406999,-0.44192686676978998,-0.44064170122147001,-0.43936970829964,-0.43811556696892001,-0.4368771314621,-0.43565744161606001,-0.43443965911865001,-0.43321752548218001,-0.43200191855431003,-0.43079522252083002,-0.42959594726562,-0.42840254306793002,-0.42722371220589,-0.42606496810913003,-0.42490822076797002,-0.42374706268311002,-0.42259222269058,-0.42144453525543002,-0.42031142115593001,-0.41919842362403997,-0.41808766126633001,-0.41697424650192,-0.41586068272590998,-0.41474530100821999,-0.41363659501076,-0.41253864765166998,-0.41144138574599998,-0.41033920645714,-0.40925040841103,-0.40818312764168002,-0.40711793303490001,-0.40604829788208002,-0.40498530864715998,-0.40393310785294001,-0.40288183093071001,-0.40182745456696001,-0.40077948570250999,-0.39974045753478998,-0.39870929718018,-0.39768755435943998,-0.39666658639907998,-0.39564064145088002,-0.39462777972221003,-0.39363461732864002,-0.39265030622482,-0.39167228341103,-0.39070186018943998,-0.38973906636237998,-0.38878411054611001,-0.38783860206603998,-0.38689434528351002,-0.38594871759415,-0.38500270247459001,-0.38405308127402998,-0.38311651349067999,-0.38220155239105003,-0.38128876686096003,-0.38036960363388,-0.37946346402168002,-0.37857902050018,-0.37769672274589999,-0.37680801749228998,-0.37593218684196,-0.37507617473602001,-0.37422925233840998,-0.37339046597481002,-0.37255281209946001,-0.37171190977097002,-0.37087732553482,-0.37005171179771001,-0.36923390626906999,-0.36842563748360002,-0.36761847138405002,-0.36680808663367998,-0.36600396037102001,-0.36520883440971003,-0.36442151665688,-0.36364370584487998,-0.36286723613739003,-0.36208939552307001,-0.36131152510643,-0.36053371429442999,-0.35975569486617998,-0.35897579789161999,-0.35820248723030002,-0.35744190216063998,-0.35667636990547003,-0.35589855909348,-0.35511949658393999,-0.35434371232986001,-0.35356169939040999,-0.35277071595192,-0.35197189450263999,-0.35116362571715998,-0.35035401582718001,-0.34954771399498002,-0.34873509407043002,-0.34791156649589999,-0.34708639979361999,-0.3462607562542,-0.34544140100478998,-0.34463298320770003,-0.34382587671280002,-0.34301549196242997,-0.34221139550209001,-0.34141820669174,-0.34062635898589999,-0.3398312330246,-0.33904248476027998,-0.33826658129692,-0.33748582005500999,-0.33669081330299,-0.33590045571326999,-0.33512252569199003,-0.33434626460075001,-0.33357045054436002,-0.33278828859329002,-0.33199328184128002,-0.33120304346085,-0.33042713999748002,-0.32964658737183,-0.32885363698005998,-0.32805892825126998,-0.32726377248763999,-0.32647496461867997,-0.32569903135299999,-0.32491821050643999,-0.32412117719650002,-0.32333499193192,-0.32257413864135998,-0.32181018590927002,-0.32103046774864002,-0.32025510072708002,-0.31949028372764998,-0.31873321533202997,-0.31798568367958002,-0.31723964214325001,-0.31649026274681002,-0.31574666500092002,-0.31501027941704002,-0.31428760290146002,-0.31358355283736999,-0.31288877129554998,-0.31220015883446001,-0.31151929497719,-0.31084796786308,-0.31017822027205999,-0.30950507521629,-0.30883786082268,-0.30817973613739003,-0.30752936005592002,-0.30688855051994002,-0.30624943971634,-0.30560886859893999,-0.30496814846991999,-0.30432552099228,-0.30368876457214,-0.30306109786034002,-0.30244120955467002,-0.30183085799217002,-0.30122214555740001,-0.30061000585556003,-0.30000370740891003,-0.2994065284729,-0.29881712794304,-0.29823726415634,-0.29765903949737998,-0.29707741737366,-0.29650172591209001,-0.29593712091446001,-0.29537415504455999,-0.29480776190758001,-0.29424718022346003,-0.29369574785232999,-0.29315191507339,-0.29261568188666998,-0.29208710789679998,-0.29156613349915,-0.29105278849602001,-0.29054707288741999,-0.29004895687102999,-0.28955850005150002,-0.28907576203346003,-0.28860259056090998,-0.28813105821608997,-0.28765410184860002,-0.28718888759612998,-0.28674581646919001,-0.28630644083022999,-0.28586208820343001,-0.28542330861092002,-0.28499174118041998,-0.28457349538803001,-0.28417202830315003,-0.283785790205,-0.28341481089592002,-0.28305894136429,-0.28271639347076,-0.28239494562148998,-0.28210183978080999,-0.28181993961334001,-0.28153669834137002,-0.28127837181090998,-0.28106105327606001,-0.28085705637932001,-0.28065213561058,-0.28046631813049,-0.28031036257744002,-0.28016594052315003,-0.28002408146857999,-0.27989557385445002,-0.27978578209876998,-0.27968546748161,-0.27958726882934998,-0.27950802445411999,-0.27945667505263999,-0.27942264080048002,-0.27940225601196,-0.27939707040786999,-0.27940511703491,-0.27943408489227001,-0.27948945760727001,-0.27956193685531999,-0.27964413166045998,-0.27975273132324002,-0.27989491820335,-0.28006759285927002,-0.28027072548866,-0.28050446510315002,-0.28077065944671997,-0.28106182813643998,-0.28137430548668002,-0.28170961141585998,-0.28206780552864003,-0.28244897723197998,-0.28285497426987,-0.28327825665473999,-0.28371325135231001,-0.28416901826858998,-0.28465124964714,-0.28515076637268,-0.28566196560860002,-0.28619387745857,-0.28675025701522999,-0.28732946515083002,-0.28793153166771002,-0.28855642676352999,-0.28920221328735002,-0.28987637162209001,-0.29058456420897999,-0.29131782054901001,-0.29207238554955001,-0.29284968972205999,-0.29364791512489002,-0.29447439312934998,-0.29533296823501998,-0.29622215032577998,-0.29714581370353998,-0.29808905720710999,-0.29904037714005,-0.30001777410507002,-0.30103081464767001,-0.30206891894340998,-0.30312630534172003,-0.30421212315558999,-0.30533602833748003,-0.30647414922714,-0.30760911107062999,-0.30876782536507003,-0.30996584892272999,-0.31118363142013999,-0.31241145730018999,-0.31365984678268,-0.31493270397186002,-0.31622850894928001,-0.31754913926125,-0.31888744235039002,-0.32024133205414002,-0.32160514593124001,-0.32297298312187001,-0.32435363531112998,-0.32574915885924999,-0.32716530561446999,-0.32860994338989002,-0.33006688952446001,-0.3315261900425,-0.33299836516379999,-0.33448740839958002,-0.3359916806221,-0.33751121163367998,-0.33904600143433,-0.34059602022170998,-0.34216126799583002,-0.34374177455902,-0.34533753991126998,-0.34694856405258001,-0.34857478737830999,-0.35021626949309997,-0.35187301039696001,-0.3535447716713,-0.35523197054862998,-0.35693237185478,-0.35865333676338002,-0.36040481925010998,-0.36216357350348999,-0.36391136050223999,-0.36567473411559998,-0.36747193336487,-0.36927658319473,-0.37107422947884,-0.37287706136703003,-0.37469115853309998,-0.37650772929192,-0.37832066416740001,-0.38013872504233998,-0.38196805119513999,-0.38379994034767001,-0.38563019037246998,-0.38746035099030002,-0.38928848505019997,-0.39112177491187999,-0.39296633005142001,-0.39481344819068998,-0.39665687084197998,-0.3985053896904,-0.40036520361900002,-0.40222749114036999,-0.40408408641815002,-0.40595087409018998,-0.40784025192260998,-0.40973478555678999,-0.41162395477295,-0.41351819038391002,-0.41542375087737998,-0.41733184456825001,-0.41923627257347001,-0.42114576697349998,-0.42306861281394997,-0.42498907446861001,-0.42689856886864003,-0.42880043387413003,-0.43069469928741,-0.43258136510848999,-0.43446445465088002,-0.43632993102074003,-0.43816518783568997,-0.43998751044272999,-0.44181165099143999,-0.44361329078674,-0.44537535309791998,-0.44711682200432001,-0.44884842634201,-0.45055982470512002,-0.45224469900130998,-0.4539116024971,-0.45556694269179998,-0.45720216631888999,-0.45881080627441001,-0.46040144562721003,-0.46197855472565003,-0.46354040503501998,-0.46508705615996998,-0.46661844849585998,-0.46813660860062001,-0.46963465213776001,-0.47110611200333002,-0.47255954146384999,-0.47399944067000999,-0.47542414069175998,-0.47683557868004001,-0.47822695970535001,-0.47959375381469999,-0.48093765974045,-0.48225870728492998,-0.48355695605277998,-0.48483228683472002,-0.48608475923538003,-0.48731437325478,-0.48852106928825001,-0.48970496654509998,-0.49086597561835998,-0.49200409650803001,-0.49311941862106001,-0.49421584606170998,-0.49527993798255998,-0.49630042910576,-0.49728757143021002,-0.49824595451355003,-0.49917384982108998,-0.50007325410842995,-0.50093746185303001,-0.50176185369491999,-0.50254809856414995,-0.50329625606536998,-0.50400626659393,-0.50468027591705,-0.50531142950057995,-0.50589710474014005,-0.50643235445023005,-0.50690853595733998,-0.50734066963196001,-0.50774019956589,-0.50809693336487005,-0.50840616226196,-0.50866973400116,-0.50888758897780995,-0.50905966758728005,-0.50918602943419999,-0.50926661491393999,-0.50930148363113004,-0.50929063558578003,-0.50923407077788996,-0.50913172960280995,-0.50898569822311002,-0.50878930091857999,-0.50853377580643,-0.5082340836525,-0.50790184736251998,-0.50752687454223999,-0.50710439682007002,-0.50663620233536,-0.50612229108810003,-0.50556266307830999,-0.50495725870132002,-0.50430613756179998,-0.50360929965973,-0.50286668539046997,-0.50207841396331998,-0.50124442577362005,-0.50036460161208995,-0.49943906068802002,-0.4984658062458,-0.49745133519173002,-0.49640452861786,-0.49531060457229997,-0.49415376782416998,-0.49295705556870001,-0.49173912405968001,-0.49048182368278997,-0.48917320370674,-0.48782336711884,-0.48643913865089,-0.48501235246657998,-0.48353606462478999,-0.48201850056647999,-0.48046654462813998,-0.4788721203804,-0.47723016142844998,-0.47554245591164002,-0.47380903363228,-0.47202986478806003,-0.47020894289017001,-0.46833354234695002,-0.46639156341553001,-0.46439293026924,-0.46234077215195002,-0.46023964881897,-0.45810058712959001,-0.45590269565581998,-0.45362681150436002,-0.45129102468491,-0.44890746474266002,-0.44646623730659002,-0.44396021962165999,-0.44139754772186002,-0.43878337740897999,-0.43611580133437999,-0.43339687585830999,-0.43062028288840998,-0.42778089642525002,-0.42488053441048002,-0.42191720008849998,-0.41889721155166998,-0.41582766175269997,-0.41270044445991999,-0.40950649976730003,-0.40626007318496998,-0.40297356247902,-0.39963704347610002,-0.39624339342116999,-0.39280059933661998,-0.38931393623352001,-0.38578152656554998,-0.38220337033272,-0.37857949733733998,-0.3749098777771,-0.37119454145432002,-0.36743345856666998,-0.36362665891647,-0.35977607965469,-0.35587561130523998,-0.35192188620567,-0.34791061282157998,-0.34383460879326,-0.33970177173615002,-0.33551740646361999,-0.33127969503402999,-0.32699057459830999,-0.32264396548271002,-0.31822869181633001,-0.31376475095749001,-0.30927219986915999,-0.30473333597183,-0.30013543367385997,-0.29548826813697998,-0.29079332947731001,-0.28606083989143,-0.28130349516869002,-0.27651160955428999,-0.27167782187461997,-0.26680997014045998,-0.26191347837447998,-0.25698652863503002,-0.25202906131744002,-0.24704113602638,-0.24202464520931,-0.23697364330292001,-0.23188070952892001,-0.22675369679928001,-0.22159998118877,-0.21641178429127,-0.21118360757828,-0.20591731369495,-0.20061098039149999,-0.19527052342892001,-0.18990337848663,-0.18450178205966999,-0.17906019091606001,-0.17358048260212,-0.16806267201899999,-0.16250674426556,-0.15691077709198001,-0.15128064155578999,-0.14562381803989,-0.13993260264397001,-0.13420522212982,-0.12843188643455999,-0.12260142713784999,-0.11671761423349,-0.11076892167330001,-0.10479024052619999,-0.098821051418781003,-0.092832595109940005,-0.086813718080521005,-0.080752730369567996,-0.074630774557589999,-0.068459331989287997,-0.062245968729258,-0.055983025580645003,-0.049660999327897998,-0.043293293565512002,-0.036889370530843998,-0.030451169237494,-0.023980565369129,-0.017487104982137999};

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
			fmydspSIG0Wave0_idx = ((1 + fmydspSIG0Wave0_idx) % 10240);
			
		}
		
	}
};

mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }

static double ftbl0mydspSIG0[10240];
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
	
	FAUSTFLOAT fVslider0;
	int iVec0[2];
	int fSamplingFreq;
	double fConst0;
	double fConst1;
	FAUSTFLOAT fButton0;
	FAUSTFLOAT fVslider1;
	double fRec1[2];
	int iRec2[2];
	FAUSTFLOAT fVslider2;
	double fRec3[2];
	FAUSTFLOAT fVslider3;
	double fRec4[2];
	FAUSTFLOAT fVslider4;
	double fRec5[2];
	double fRec0[2];
	FAUSTFLOAT fVslider5;
	double fRec6[2];
	FAUSTFLOAT fVslider6;
	double fRec8[2];
	FAUSTFLOAT fVslider7;
	double fConst2;
	FAUSTFLOAT fVslider8;
	double fConst3;
	FAUSTFLOAT fVslider9;
	double fRec13[2];
	FAUSTFLOAT fVslider10;
	double fRec14[2];
	double fRec15[2];
	double fRec12[2];
	double fRec11[2];
	double fRec16[2];
	double fConst4;
	double fRec20[2];
	double fRec21[2];
	int iRec22[2];
	double fRec19[2];
	double fRec18[2];
	double fRec10[2];
	FAUSTFLOAT fVslider11;
	double fRec23[2];
	FAUSTFLOAT fVslider12;
	FAUSTFLOAT fVslider13;
	double fRec27[2];
	double fRec28[2];
	double fRec26[2];
	double fRec25[2];
	double fRec29[2];
	double fRec33[2];
	double fRec34[2];
	double fRec32[2];
	double fRec31[2];
	double fRec24[2];
	FAUSTFLOAT fVslider14;
	double fRec35[2];
	FAUSTFLOAT fVslider15;
	FAUSTFLOAT fVslider16;
	FAUSTFLOAT fVslider17;
	double fConst5;
	FAUSTFLOAT fVslider18;
	double fRec36[2];
	double fRec9[2];
	double fConst6;
	double fRec39[2];
	double fRec38[2];
	double fRec37[2];
	FAUSTFLOAT fVslider19;
	double fRec40[2];
	FAUSTFLOAT fVslider20;
	FAUSTFLOAT fVslider21;
	double fRec42[2];
	FAUSTFLOAT fVslider22;
	double fRec43[2];
	FAUSTFLOAT fVslider23;
	double fRec41[2];
	double fRec46[2];
	double fRec45[2];
	double fRec44[2];
	FAUSTFLOAT fVslider24;
	double fRec47[2];
	FAUSTFLOAT fVslider25;
	FAUSTFLOAT fVslider26;
	double fRec49[2];
	FAUSTFLOAT fVslider27;
	double fRec50[2];
	FAUSTFLOAT fVslider28;
	double fRec48[2];
	double fRec53[2];
	double fRec52[2];
	double fRec51[2];
	FAUSTFLOAT fVslider29;
	double fRec57[2];
	FAUSTFLOAT fVslider30;
	double fRec58[2];
	FAUSTFLOAT fVslider31;
	double fRec59[2];
	double fRec56[2];
	double fRec55[2];
	double fRec54[2];
	FAUSTFLOAT fCheckbox0;
	double fRec60[2];
	FAUSTFLOAT fVslider32;
	double fRec61[2];
	FAUSTFLOAT fVslider33;
	double fRec63[2];
	FAUSTFLOAT fVslider34;
	double fRec64[2];
	FAUSTFLOAT fVslider35;
	double fRec65[2];
	FAUSTFLOAT fVslider36;
	double fRec66[2];
	double fRec62[2];
	FAUSTFLOAT fVslider37;
	double fRec67[2];
	double fRec70[2];
	double fRec69[2];
	double fRec68[2];
	double fVec1[2];
	double fRec7[2];
	FAUSTFLOAT fVslider38;
	double fRec71[2];
	double fConst7;
	double fConst8;
	double fConst9;
	double fConst10;
	FAUSTFLOAT fCheckbox1;
	double fRec72[2];
	FAUSTFLOAT fVslider39;
	double fRec73[2];
	FAUSTFLOAT fVslider40;
	double fRec74[2];
	FAUSTFLOAT fVslider41;
	double fRec75[2];
	FAUSTFLOAT fVslider42;
	double fRec77[2];
	FAUSTFLOAT fVslider43;
	double fRec78[2];
	FAUSTFLOAT fVslider44;
	double fRec79[2];
	FAUSTFLOAT fVslider45;
	double fRec80[2];
	double fRec76[2];
	FAUSTFLOAT fVslider46;
	double fRec81[2];
	double fRec84[2];
	double fRec82[2];
	double fRec87[2];
	double fRec85[2];
	FAUSTFLOAT fVslider47;
	double fRec88[2];
	FAUSTFLOAT fVslider48;
	double fRec89[2];
	double fConst11;
	double fConst12;
	double fConst13;
	double fConst14;
	double fRec92[2];
	double fRec91[2];
	double fRec90[2];
	
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
		m->declare("filename", "wavesElectric");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "0.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.1");
		m->declare("misceffects.lib/name", "Faust Math Library");
		m->declare("misceffects.lib/version", "2.0");
		m->declare("name", "wavesElectric");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.0");
		m->declare("nvoices", "16");
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
		sig0->fillmydspSIG0(10240, ftbl0mydspSIG0);
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
		fVslider0 = FAUSTFLOAT(1.0);
		fButton0 = FAUSTFLOAT(0.0);
		fVslider1 = FAUSTFLOAT(0.10000000000000001);
		fVslider2 = FAUSTFLOAT(0.01);
		fVslider3 = FAUSTFLOAT(0.059999999999999998);
		fVslider4 = FAUSTFLOAT(0.90000000000000002);
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
			fRec8[l8] = 0.0;
			
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec13[l9] = 0.0;
			
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec14[l10] = 0.0;
			
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec15[l11] = 0.0;
			
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec12[l12] = 0.0;
			
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec11[l13] = 0.0;
			
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec16[l14] = 0.0;
			
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec20[l15] = 0.0;
			
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec21[l16] = 0.0;
			
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			iRec22[l17] = 0;
			
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec19[l18] = 0.0;
			
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec18[l19] = 0.0;
			
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec10[l20] = 0.0;
			
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec23[l21] = 0.0;
			
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec27[l22] = 0.0;
			
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec28[l23] = 0.0;
			
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec26[l24] = 0.0;
			
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec25[l25] = 0.0;
			
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec29[l26] = 0.0;
			
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec33[l27] = 0.0;
			
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec34[l28] = 0.0;
			
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec32[l29] = 0.0;
			
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec31[l30] = 0.0;
			
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec24[l31] = 0.0;
			
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec35[l32] = 0.0;
			
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec36[l33] = 0.0;
			
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec9[l34] = 0.0;
			
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec39[l35] = 0.0;
			
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec38[l36] = 0.0;
			
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec37[l37] = 0.0;
			
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec40[l38] = 0.0;
			
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec42[l39] = 0.0;
			
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec43[l40] = 0.0;
			
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec41[l41] = 0.0;
			
		}
		for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
			fRec46[l42] = 0.0;
			
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec45[l43] = 0.0;
			
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec44[l44] = 0.0;
			
		}
		for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) {
			fRec47[l45] = 0.0;
			
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fRec49[l46] = 0.0;
			
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fRec50[l47] = 0.0;
			
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec48[l48] = 0.0;
			
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fRec53[l49] = 0.0;
			
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fRec52[l50] = 0.0;
			
		}
		for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
			fRec51[l51] = 0.0;
			
		}
		for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) {
			fRec57[l52] = 0.0;
			
		}
		for (int l53 = 0; (l53 < 2); l53 = (l53 + 1)) {
			fRec58[l53] = 0.0;
			
		}
		for (int l54 = 0; (l54 < 2); l54 = (l54 + 1)) {
			fRec59[l54] = 0.0;
			
		}
		for (int l55 = 0; (l55 < 2); l55 = (l55 + 1)) {
			fRec56[l55] = 0.0;
			
		}
		for (int l56 = 0; (l56 < 2); l56 = (l56 + 1)) {
			fRec55[l56] = 0.0;
			
		}
		for (int l57 = 0; (l57 < 2); l57 = (l57 + 1)) {
			fRec54[l57] = 0.0;
			
		}
		for (int l58 = 0; (l58 < 2); l58 = (l58 + 1)) {
			fRec60[l58] = 0.0;
			
		}
		for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) {
			fRec61[l59] = 0.0;
			
		}
		for (int l60 = 0; (l60 < 2); l60 = (l60 + 1)) {
			fRec63[l60] = 0.0;
			
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
			fRec62[l64] = 0.0;
			
		}
		for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) {
			fRec67[l65] = 0.0;
			
		}
		for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) {
			fRec70[l66] = 0.0;
			
		}
		for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) {
			fRec69[l67] = 0.0;
			
		}
		for (int l68 = 0; (l68 < 2); l68 = (l68 + 1)) {
			fRec68[l68] = 0.0;
			
		}
		for (int l69 = 0; (l69 < 2); l69 = (l69 + 1)) {
			fVec1[l69] = 0.0;
			
		}
		for (int l70 = 0; (l70 < 2); l70 = (l70 + 1)) {
			fRec7[l70] = 0.0;
			
		}
		for (int l71 = 0; (l71 < 2); l71 = (l71 + 1)) {
			fRec71[l71] = 0.0;
			
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
			fRec77[l76] = 0.0;
			
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
			fRec76[l80] = 0.0;
			
		}
		for (int l81 = 0; (l81 < 2); l81 = (l81 + 1)) {
			fRec81[l81] = 0.0;
			
		}
		for (int l82 = 0; (l82 < 2); l82 = (l82 + 1)) {
			fRec84[l82] = 0.0;
			
		}
		for (int l83 = 0; (l83 < 2); l83 = (l83 + 1)) {
			fRec82[l83] = 0.0;
			
		}
		for (int l84 = 0; (l84 < 2); l84 = (l84 + 1)) {
			fRec87[l84] = 0.0;
			
		}
		for (int l85 = 0; (l85 < 2); l85 = (l85 + 1)) {
			fRec85[l85] = 0.0;
			
		}
		for (int l86 = 0; (l86 < 2); l86 = (l86 + 1)) {
			fRec88[l86] = 0.0;
			
		}
		for (int l87 = 0; (l87 < 2); l87 = (l87 + 1)) {
			fRec89[l87] = 0.0;
			
		}
		for (int l88 = 0; (l88 < 2); l88 = (l88 + 1)) {
			fRec92[l88] = 0.0;
			
		}
		for (int l89 = 0; (l89 < 2); l89 = (l89 + 1)) {
			fRec91[l89] = 0.0;
			
		}
		for (int l90 = 0; (l90 < 2); l90 = (l90 + 1)) {
			fRec90[l90] = 0.0;
			
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
		ui_interface->openHorizontalBox("wavesElectric");
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
		ui_interface->addVerticalSlider("form wav", &fVslider7, 0.0, 0.0, 4.0, 1.0);
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
		ui_interface->addVerticalSlider("form wav", &fVslider20, 0.0, 0.0, 4.0, 1.0);
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
		ui_interface->addVerticalSlider("form wav", &fVslider25, 0.0, 0.0, 4.0, 1.0);
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
		ui_interface->addVerticalSlider("freq", &fVslider17, 440.0, 20.0, 5000.0, 1.0);
		ui_interface->declare(&fVslider18, "2", "");
		ui_interface->declare(&fVslider18, "style", "knob");
		ui_interface->addVerticalSlider("portamento", &fVslider18, 0.0, 0.0, 5.0, 0.050000000000000003);
		ui_interface->declare(0, "5", "");
		ui_interface->openHorizontalBox("env");
		ui_interface->declare(&fVslider2, "1", "");
		ui_interface->declare(&fVslider2, "style", "knob");
		ui_interface->declare(&fVslider2, "tooltip", "sec");
		ui_interface->addVerticalSlider("A", &fVslider2, 0.01, 0.0, 5.0, 0.01);
		ui_interface->declare(&fVslider3, "2", "");
		ui_interface->declare(&fVslider3, "style", "knob");
		ui_interface->declare(&fVslider3, "tooltip", "sec");
		ui_interface->addVerticalSlider("D", &fVslider3, 0.059999999999999998, 0.0, 5.0, 0.01);
		ui_interface->declare(&fVslider4, "3", "");
		ui_interface->declare(&fVslider4, "style", "knob");
		ui_interface->declare(&fVslider4, "tooltip", "percentage of max");
		ui_interface->addVerticalSlider("S", &fVslider4, 0.90000000000000002, 0.0, 1.0, 0.01);
		ui_interface->declare(&fVslider1, "4", "");
		ui_interface->declare(&fVslider1, "style", "knob");
		ui_interface->declare(&fVslider1, "tooltip", "sec");
		ui_interface->addVerticalSlider("R", &fVslider1, 0.10000000000000001, 0.01, 5.0, 0.01);
		ui_interface->closeBox();
		ui_interface->declare(&fVslider15, "9", "");
		ui_interface->declare(&fVslider15, "hide", "1");
		ui_interface->declare(&fVslider15, "midi", "pitchwheel");
		ui_interface->declare(&fVslider15, "style", "knob");
		ui_interface->addVerticalSlider("bend", &fVslider15, 1.0, 0.90000000000000002, 1.1000000000000001, 0.01);
		ui_interface->declare(&fVslider0, "9", "");
		ui_interface->declare(&fVslider0, "style", "knob");
		ui_interface->addVerticalSlider("gain", &fVslider0, 1.0, 0.0, 3.0, 0.01);
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
		double fSlow0 = (0.5 * double(fVslider0));
		int iSlow1 = (double(fButton0) > 0.0);
		double fSlow2 = (0.0010000000000000009 * double(fVslider1));
		double fSlow3 = (0.0010000000000000009 * double(fVslider2));
		double fSlow4 = (0.0010000000000000009 * double(fVslider3));
		double fSlow5 = double(iSlow1);
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
			fRec1[0] = (fSlow2 + (0.999 * fRec1[1]));
			iRec2[0] = (iSlow1 * (iRec2[1] + 1));
			fRec3[0] = (fSlow3 + (0.999 * fRec3[1]));
			int iTemp0 = (iRec2[0] < int((fConst0 * fRec3[0])));
			fRec4[0] = (fSlow4 + (0.999 * fRec4[1]));
			double fTemp1 = std::exp((0.0 - (fConst1 / (iSlow1?(iTemp0?fRec3[0]:fRec4[0]):fRec1[0]))));
			fRec5[0] = (fSlow6 + (0.999 * fRec5[1]));
			fRec0[0] = ((fRec0[1] * fTemp1) + ((iSlow1?(iTemp0?double(iSlow1):(fSlow5 * fRec5[0])):0.0) * (1.0 - fTemp1)));
			fRec6[0] = (fSlow7 + (0.999 * fRec6[1]));
			fRec8[0] = (fSlow8 + (0.999 * fRec8[1]));
			fRec13[0] = (fSlow13 + (0.999 * fRec13[1]));
			fRec14[0] = (fSlow14 + (0.999 * fRec14[1]));
			double fTemp2 = (fRec13[0] * fRec14[0]);
			fRec15[0] = (fRec15[1] + (fConst3 * (fTemp2 * (0.0 - fRec11[1]))));
			int iTemp3 = (1 - iVec0[1]);
			fRec12[0] = ((fRec12[1] + (fConst3 * (fTemp2 * fRec15[0]))) + double(iTemp3));
			fRec11[0] = fRec12[0];
			double fTemp4 = std::max(9.9999999999999995e-08, std::fabs((0.016666666666666666 * fTemp2)));
			double fTemp5 = (fRec16[1] + (fConst2 * fTemp4));
			double fTemp6 = (fTemp5 + -1.0);
			int iTemp7 = (fTemp6 < 0.0);
			fRec16[0] = (iTemp7?fTemp5:fTemp6);
			double fRec17 = (iTemp7?fTemp5:(fTemp5 + (fTemp6 * (1.0 - (fConst0 / fTemp4)))));
			double fTemp8 = std::exp((0.0 - (fConst4 * fTemp2)));
			double fTemp9 = (fConst3 * fTemp2);
			double fTemp10 = std::sin(fTemp9);
			double fTemp11 = std::cos(fTemp9);
			fRec20[0] = ((fRec21[1] * fTemp10) + (fRec20[1] * fTemp11));
			fRec21[0] = (((fRec21[1] * fTemp11) + (fRec20[1] * (0.0 - fTemp10))) + double(iTemp3));
			int iTemp12 = ((fRec20[1] <= 0.0) & (fRec20[0] > 0.0));
			iRec22[0] = ((1103515245 * iRec22[1]) + 12345);
			fRec19[0] = ((fRec19[1] * double((1 - iTemp12))) + (4.6566128752457969e-10 * double((iRec22[0] * iTemp12))));
			fRec18[0] = ((fRec18[1] * fTemp8) + (fRec19[0] * (1.0 - fTemp8)));
			fRec10[0] = ((0.999 * fRec10[1]) + (0.0010000000000000009 * (iSlow11?(iSlow15?fRec19[0]:fRec18[0]):(iSlow12?((2.0 * fRec17) + -1.0):fRec11[0]))));
			fRec23[0] = (fSlow16 + (0.999 * fRec23[1]));
			fRec27[0] = (fSlow20 + (0.999 * fRec27[1]));
			double fTemp13 = (fRec14[0] * fRec27[0]);
			fRec28[0] = (fRec28[1] + (fConst3 * (fTemp13 * (0.0 - fRec25[1]))));
			fRec26[0] = ((fRec26[1] + (fConst3 * (fTemp13 * fRec28[0]))) + double(iTemp3));
			fRec25[0] = fRec26[0];
			double fTemp14 = std::max(9.9999999999999995e-08, std::fabs((0.016666666666666666 * fTemp13)));
			double fTemp15 = (fRec29[1] + (fConst2 * fTemp14));
			double fTemp16 = (fTemp15 + -1.0);
			int iTemp17 = (fTemp16 < 0.0);
			fRec29[0] = (iTemp17?fTemp15:fTemp16);
			double fRec30 = (iTemp17?fTemp15:(fTemp15 + (fTemp16 * (1.0 - (fConst0 / fTemp14)))));
			double fTemp18 = std::exp((0.0 - (fConst4 * fTemp13)));
			double fTemp19 = (fConst3 * fTemp13);
			double fTemp20 = std::sin(fTemp19);
			double fTemp21 = std::cos(fTemp19);
			fRec33[0] = ((fRec34[1] * fTemp20) + (fRec33[1] * fTemp21));
			fRec34[0] = (((fRec34[1] * fTemp21) + (fRec33[1] * (0.0 - fTemp20))) + double(iTemp3));
			int iTemp22 = ((fRec33[1] <= 0.0) & (fRec33[0] > 0.0));
			fRec32[0] = ((fRec32[1] * double((1 - iTemp22))) + (4.6566128752457969e-10 * double((iRec22[0] * iTemp22))));
			fRec31[0] = ((fRec31[1] * fTemp18) + (fRec32[0] * (1.0 - fTemp18)));
			fRec24[0] = ((0.999 * fRec24[1]) + (0.0010000000000000009 * (iSlow18?(iSlow21?fRec32[0]:fRec31[0]):(iSlow19?((2.0 * fRec30) + -1.0):fRec25[0]))));
			fRec35[0] = (fSlow22 + (0.999 * fRec35[1]));
			fRec36[0] = (fSlow26 + (fSlow25 * fRec36[1]));
			double fTemp23 = (((fRec10[0] * fRec23[0]) + (fRec24[0] * fRec35[0])) + (fSlow24 * fRec36[0]));
			double fTemp24 = (fRec9[1] + (fConst2 * fTemp23));
			fRec9[0] = (fTemp24 - std::floor(fTemp24));
			double fTemp25 = (fTemp23 + -200.0);
			double fTemp26 = (0.0002631578947368421 * fTemp25);
			double fTemp27 = (double((fTemp26 > 1.0)) + (0.0002631578947368421 * (fTemp25 * double((fTemp26 <= 1.0)))));
			int iTemp28 = (fTemp27 >= 0.0);
			fRec39[0] = (fRec39[1] + (fConst6 * (fTemp23 * (0.0 - fRec37[1]))));
			fRec38[0] = ((fRec38[1] + (fConst6 * (fRec39[0] * fTemp23))) + double(iTemp3));
			fRec37[0] = fRec38[0];
			fRec40[0] = (fSlow27 + (0.999 * fRec40[1]));
			fRec42[0] = (fSlow29 + (0.999 * fRec42[1]));
			fRec43[0] = (fSlow30 + (0.999 * fRec43[1]));
			double fTemp29 = (((fRec10[0] * fRec42[0]) + (fRec24[0] * fRec43[0])) + (fSlow31 * fRec36[0]));
			double fTemp30 = (fRec41[1] + (fConst2 * fTemp29));
			fRec41[0] = (fTemp30 - std::floor(fTemp30));
			double fTemp31 = (fTemp29 + -200.0);
			double fTemp32 = (0.0002631578947368421 * fTemp31);
			double fTemp33 = (double((fTemp32 > 1.0)) + (0.0002631578947368421 * (fTemp31 * double((fTemp32 <= 1.0)))));
			int iTemp34 = (fTemp33 >= 0.0);
			fRec46[0] = (fRec46[1] + (fConst6 * (fTemp29 * (0.0 - fRec44[1]))));
			fRec45[0] = ((fRec45[1] + (fConst6 * (fRec46[0] * fTemp29))) + double(iTemp3));
			fRec44[0] = fRec45[0];
			fRec47[0] = (fSlow32 + (0.999 * fRec47[1]));
			fRec49[0] = (fSlow34 + (0.999 * fRec49[1]));
			fRec50[0] = (fSlow35 + (0.999 * fRec50[1]));
			double fTemp35 = (((fRec10[0] * fRec49[0]) + (fRec24[0] * fRec50[0])) + (fSlow36 * fRec36[0]));
			double fTemp36 = (fRec48[1] + (fConst2 * fTemp35));
			fRec48[0] = (fTemp36 - std::floor(fTemp36));
			double fTemp37 = (fTemp35 + -200.0);
			double fTemp38 = (0.0002631578947368421 * fTemp37);
			double fTemp39 = (double((fTemp38 > 1.0)) + (0.0002631578947368421 * (fTemp37 * double((fTemp38 <= 1.0)))));
			int iTemp40 = (fTemp39 >= 0.0);
			fRec53[0] = (fRec53[1] + (fConst6 * (fTemp35 * (0.0 - fRec51[1]))));
			fRec52[0] = ((fRec52[1] + (fConst6 * (fRec53[0] * fTemp35))) + double(iTemp3));
			fRec51[0] = fRec52[0];
			double fTemp41 = (((fRec8[0] * ((ftbl0mydspSIG0[int((2048.0 * (fSlow9 + fRec9[0])))] * (1.0 - (fTemp27 * double(iTemp28)))) + ((fRec37[0] * fTemp27) * double(iTemp28)))) + (fRec40[0] * ((ftbl0mydspSIG0[int((2048.0 * (fSlow28 + fRec41[0])))] * (1.0 - (fTemp33 * double(iTemp34)))) + ((fRec44[0] * fTemp33) * double(iTemp34))))) + (fRec47[0] * ((ftbl0mydspSIG0[int((2048.0 * (fSlow33 + fRec48[0])))] * (1.0 - (fTemp39 * double(iTemp40)))) + ((fRec51[0] * fTemp39) * double(iTemp40)))));
			fRec57[0] = (fSlow37 + (0.999 * fRec57[1]));
			fRec58[0] = (fSlow38 + (0.999 * fRec58[1]));
			fRec59[0] = (fSlow40 + (0.999 * fRec59[1]));
			double fTemp42 = (((fRec10[0] * fRec57[0]) + (fRec24[0] * fRec58[0])) + (fSlow39 * (fRec36[0] * fRec59[0])));
			double fTemp43 = (double((20000 * (fTemp42 > 20000.0))) + (fTemp42 * double((fTemp42 <= 20000.0))));
			int iTemp44 = (fTemp43 >= 0.0);
			fRec56[0] = (fRec56[1] + (fConst6 * (((0.0 - fRec54[1]) * fTemp43) * double(iTemp44))));
			fRec55[0] = ((fRec55[1] + (fConst6 * ((fRec56[0] * fTemp43) * double(iTemp44)))) + double(iTemp3));
			fRec54[0] = fRec55[0];
			fRec60[0] = (fSlow41 + (0.999 * fRec60[1]));
			fRec61[0] = (fSlow42 + (0.999 * fRec61[1]));
			fRec63[0] = (fSlow43 + (0.999 * fRec63[1]));
			fRec64[0] = (fSlow44 + (0.999 * fRec64[1]));
			int iTemp45 = (iRec2[0] < int((fConst0 * fRec64[0])));
			fRec65[0] = (fSlow45 + (0.999 * fRec65[1]));
			double fTemp46 = std::exp((0.0 - (fConst1 / (iSlow1?(iTemp45?fRec64[0]:fRec65[0]):fRec63[0]))));
			fRec66[0] = (fSlow46 + (0.999 * fRec66[1]));
			fRec62[0] = ((fRec62[1] * fTemp46) + ((iSlow1?(iTemp45?double(iSlow1):(fSlow5 * fRec66[0])):0.0) * (1.0 - fTemp46)));
			fRec67[0] = (fSlow47 + (0.999 * fRec67[1]));
			double fTemp47 = (3.1415926535897931 * (fRec54[0] * (((1.0 - fRec60[0]) * (fRec61[0] + (fRec62[0] * ((15.0 * fRec67[0]) - fRec61[0])))) + ((fRec61[0] * fRec60[0]) * (1.0 - (fRec62[0] * fRec67[0]))))));
			double fTemp48 = std::sin(fTemp47);
			double fTemp49 = (0.0 - fTemp48);
			double fTemp50 = std::cos(fTemp47);
			double fTemp51 = ((fRec68[1] * fTemp49) + (0.20000000000000001 * (fTemp41 * fTemp50)));
			double fTemp52 = ((fTemp49 * fRec69[1]) + (fTemp50 * fTemp51));
			fRec70[0] = ((fTemp49 * fRec70[1]) + (fTemp50 * fTemp52));
			fRec69[0] = ((fTemp48 * fTemp52) + (fTemp50 * fRec70[1]));
			fRec68[0] = ((fTemp48 * fTemp51) + (fTemp50 * fRec69[1]));
			double fTemp53 = ((0.20000000000000001 * (fTemp41 * fTemp48)) + (fRec68[1] * fTemp50));
			double fTemp54 = std::max(-1.0, std::min(1.0, (6.3095734448019334 * fTemp53)));
			double fTemp55 = (fTemp54 * (1.0 - (0.33333333333333331 * mydsp_faustpower2_f(fTemp54))));
			fVec1[0] = fTemp55;
			fRec7[0] = (((0.995 * fRec7[1]) + fTemp55) - fVec1[1]);
			fRec71[0] = (fSlow48 + (0.999 * fRec71[1]));
			double fTemp56 = mydsp_faustpower2_f((1.4141994202374715 * fRec71[0]));
			double fTemp57 = (1.9999800000000003 * fRec71[0]);
			double fTemp58 = (fTemp56 + fTemp57);
			double fTemp59 = (fTemp57 + 2.0);
			fRec72[0] = (fSlow49 + (0.999 * fRec72[1]));
			fRec73[0] = (fSlow50 + (0.999 * fRec73[1]));
			fRec74[0] = (fSlow51 + (0.999 * fRec74[1]));
			fRec75[0] = (fSlow52 + (0.999 * fRec75[1]));
			double fTemp60 = (((fRec10[0] * fRec73[0]) + (fRec24[0] * fRec74[0])) + (fSlow39 * (fRec36[0] * fRec75[0])));
			fRec77[0] = (fSlow53 + (0.999 * fRec77[1]));
			fRec78[0] = (fSlow54 + (0.999 * fRec78[1]));
			int iTemp61 = (iRec2[0] < int((fConst0 * fRec78[0])));
			fRec79[0] = (fSlow55 + (0.999 * fRec79[1]));
			double fTemp62 = std::exp((0.0 - (fConst1 / (iSlow1?(iTemp61?fRec78[0]:fRec79[0]):fRec77[0]))));
			fRec80[0] = (fSlow56 + (0.999 * fRec80[1]));
			fRec76[0] = ((fRec76[1] * fTemp62) + ((iSlow1?(iTemp61?double(iSlow1):(fSlow5 * fRec80[0])):0.0) * (1.0 - fTemp62)));
			fRec81[0] = (fSlow57 + (0.999 * fRec81[1]));
			double fTemp63 = (((1.0 - fRec72[0]) * (fTemp60 + (fRec76[0] * ((fConst8 * fRec81[0]) - fTemp60)))) + (fRec72[0] * (fTemp60 - ((fRec76[0] * fRec81[0]) * (fTemp60 + -20.0)))));
			double fTemp64 = ((fConst10 * double((fTemp63 > fConst10))) + (fTemp63 * double((fTemp63 <= fConst10))));
			double fTemp65 = std::tan((fConst7 * std::max(((fConst9 * double((fTemp64 < fConst9))) + (fTemp64 * double((fTemp64 >= fConst9)))), 20.0)));
			double fTemp66 = (1.0 / fTemp65);
			double fTemp67 = ((fTemp58 + ((fTemp59 + fTemp66) / fTemp65)) + 1.0);
			double fTemp68 = ((fTemp58 + (1.0 - ((fTemp59 - fTemp66) / fTemp65))) / fTemp67);
			double fTemp69 = std::max(-0.99990000000000001, std::min(0.99990000000000001, fTemp68));
			double fTemp70 = (1.0 - mydsp_faustpower2_f(fTemp69));
			double fTemp71 = std::sqrt(std::max(0.0, fTemp70));
			double fTemp72 = ((fRec82[1] * (0.0 - fTemp69)) + (fRec7[0] * fTemp71));
			double fTemp73 = (1.0 / mydsp_faustpower2_f(fTemp65));
			double fTemp74 = (fTemp58 + (1.0 - fTemp73));
			double fTemp75 = std::max(-0.99990000000000001, std::min(0.99990000000000001, (2.0 * (fTemp74 / (fTemp67 * (fTemp68 + 1.0))))));
			double fTemp76 = (1.0 - mydsp_faustpower2_f(fTemp75));
			double fTemp77 = std::sqrt(std::max(0.0, fTemp76));
			fRec84[0] = ((fRec84[1] * (0.0 - fTemp75)) + (fTemp72 * fTemp77));
			fRec82[0] = ((fTemp72 * fTemp75) + (fRec84[1] * fTemp77));
			double fRec83 = fRec84[0];
			double fTemp78 = (1.0 - (fTemp74 / fTemp67));
			double fTemp79 = std::sqrt(fTemp70);
			double fTemp80 = ((((fRec7[0] * fTemp69) + (fRec82[1] * fTemp71)) + (2.0 * ((fRec82[0] * fTemp78) / fTemp79))) + ((fRec83 * ((1.0 - fTemp68) - (2.0 * (fTemp75 * fTemp78)))) / (fTemp79 * std::sqrt(fTemp76))));
			double fTemp81 = (2.0 - fTemp57);
			double fTemp82 = (1.0 - fTemp57);
			double fTemp83 = ((fTemp56 + ((fTemp66 + fTemp81) / fTemp65)) + fTemp82);
			double fTemp84 = (((fTemp56 + ((fTemp66 - fTemp81) / fTemp65)) + fTemp82) / fTemp83);
			double fTemp85 = std::max(-0.99990000000000001, std::min(0.99990000000000001, fTemp84));
			double fTemp86 = (1.0 - mydsp_faustpower2_f(fTemp85));
			double fTemp87 = std::sqrt(std::max(0.0, fTemp86));
			double fTemp88 = ((fRec85[1] * (0.0 - fTemp85)) + ((fTemp80 * fTemp87) / fTemp67));
			double fTemp89 = (fTemp56 + (1.0 - (fTemp57 + fTemp73)));
			double fTemp90 = std::max(-0.99990000000000001, std::min(0.99990000000000001, (2.0 * (fTemp89 / (fTemp83 * (fTemp84 + 1.0))))));
			double fTemp91 = (1.0 - mydsp_faustpower2_f(fTemp90));
			double fTemp92 = std::sqrt(std::max(0.0, fTemp91));
			fRec87[0] = ((fRec87[1] * (0.0 - fTemp90)) + (fTemp88 * fTemp92));
			fRec85[0] = ((fTemp88 * fTemp90) + (fRec87[1] * fTemp92));
			double fRec86 = fRec87[0];
			double fTemp93 = (1.0 - (fTemp89 / fTemp83));
			double fTemp94 = std::sqrt(fTemp86);
			fRec88[0] = (fSlow58 + (0.999 * fRec88[1]));
			fRec89[0] = (fSlow59 + (0.999 * fRec89[1]));
			double fTemp95 = ((fRec0[0] * ((0.40000000000000002 * ((fRec6[0] * (((((fTemp80 * fTemp85) / fTemp67) + (fRec85[1] * fTemp87)) + (2.0 * ((fRec85[0] * fTemp93) / fTemp94))) + ((fRec86 * ((1.0 - fTemp84) - (2.0 * (fTemp90 * fTemp93)))) / (fTemp94 * std::sqrt(fTemp91))))) / fTemp83)) + ((1.0 - fRec6[0]) * fTemp53))) * (((fRec10[0] * fRec88[0]) + (fRec24[0] * fRec89[0])) + 2.0));
			double fTemp96 = std::fabs((fSlow0 * fTemp95));
			double fTemp97 = ((fRec91[1] > fTemp96)?fConst14:fConst13);
			fRec92[0] = ((fRec92[1] * fTemp97) + (fTemp96 * (1.0 - fTemp97)));
			fRec91[0] = fRec92[0];
			fRec90[0] = ((fConst11 * fRec90[1]) + (fConst12 * (0.0 - (0.75 * std::max(((20.0 * std::log10(fRec91[0])) + 6.0), 0.0)))));
			double fTemp98 = (fSlow0 * (fTemp95 * std::pow(10.0, (0.050000000000000003 * fRec90[0]))));
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
			fRec8[1] = fRec8[0];
			fRec13[1] = fRec13[0];
			fRec14[1] = fRec14[0];
			fRec15[1] = fRec15[0];
			fRec12[1] = fRec12[0];
			fRec11[1] = fRec11[0];
			fRec16[1] = fRec16[0];
			fRec20[1] = fRec20[0];
			fRec21[1] = fRec21[0];
			iRec22[1] = iRec22[0];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			fRec10[1] = fRec10[0];
			fRec23[1] = fRec23[0];
			fRec27[1] = fRec27[0];
			fRec28[1] = fRec28[0];
			fRec26[1] = fRec26[0];
			fRec25[1] = fRec25[0];
			fRec29[1] = fRec29[0];
			fRec33[1] = fRec33[0];
			fRec34[1] = fRec34[0];
			fRec32[1] = fRec32[0];
			fRec31[1] = fRec31[0];
			fRec24[1] = fRec24[0];
			fRec35[1] = fRec35[0];
			fRec36[1] = fRec36[0];
			fRec9[1] = fRec9[0];
			fRec39[1] = fRec39[0];
			fRec38[1] = fRec38[0];
			fRec37[1] = fRec37[0];
			fRec40[1] = fRec40[0];
			fRec42[1] = fRec42[0];
			fRec43[1] = fRec43[0];
			fRec41[1] = fRec41[0];
			fRec46[1] = fRec46[0];
			fRec45[1] = fRec45[0];
			fRec44[1] = fRec44[0];
			fRec47[1] = fRec47[0];
			fRec49[1] = fRec49[0];
			fRec50[1] = fRec50[0];
			fRec48[1] = fRec48[0];
			fRec53[1] = fRec53[0];
			fRec52[1] = fRec52[0];
			fRec51[1] = fRec51[0];
			fRec57[1] = fRec57[0];
			fRec58[1] = fRec58[0];
			fRec59[1] = fRec59[0];
			fRec56[1] = fRec56[0];
			fRec55[1] = fRec55[0];
			fRec54[1] = fRec54[0];
			fRec60[1] = fRec60[0];
			fRec61[1] = fRec61[0];
			fRec63[1] = fRec63[0];
			fRec64[1] = fRec64[0];
			fRec65[1] = fRec65[0];
			fRec66[1] = fRec66[0];
			fRec62[1] = fRec62[0];
			fRec67[1] = fRec67[0];
			fRec70[1] = fRec70[0];
			fRec69[1] = fRec69[0];
			fRec68[1] = fRec68[0];
			fVec1[1] = fVec1[0];
			fRec7[1] = fRec7[0];
			fRec71[1] = fRec71[0];
			fRec72[1] = fRec72[0];
			fRec73[1] = fRec73[0];
			fRec74[1] = fRec74[0];
			fRec75[1] = fRec75[0];
			fRec77[1] = fRec77[0];
			fRec78[1] = fRec78[0];
			fRec79[1] = fRec79[0];
			fRec80[1] = fRec80[0];
			fRec76[1] = fRec76[0];
			fRec81[1] = fRec81[0];
			fRec84[1] = fRec84[0];
			fRec82[1] = fRec82[0];
			fRec87[1] = fRec87[0];
			fRec85[1] = fRec85[0];
			fRec88[1] = fRec88[0];
			fRec89[1] = fRec89[0];
			fRec92[1] = fRec92[0];
			fRec91[1] = fRec91[0];
			fRec90[1] = fRec90[0];
			
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
