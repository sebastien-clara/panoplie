/* ------------------------------------------------------------
name: "cabinetVoxTopBoostBass"
Code generated with Faust 2.5.35 (https://faust.grame.fr)
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
            replace(res.begin(), res.end(), ' ', '_');
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
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return atoi(argv[i+1]);
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
         
    public:
        
        dsp_parallelizer(dsp* dsp1, dsp* dsp2, int buffer_size = 4096)
            :fDSP1(dsp1), fDSP2(dsp2)
        {}
        
        virtual ~dsp_parallelizer()
        {
            delete fDSP1;
            delete fDSP2;
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
            FAUSTFLOAT** inputs_dsp2 = (FAUSTFLOAT**)alloca(fDSP2->getNumInputs() * sizeof(FAUSTFLOAT*));
            for (int chan = 0; chan < fDSP2->getNumInputs(); chan++) {
                inputs_dsp2[chan] = inputs[fDSP1->getNumInputs() + chan];
            }
            
            FAUSTFLOAT** outputs_dsp2 = (FAUSTFLOAT**)alloca(fDSP2->getNumOutputs() * sizeof(FAUSTFLOAT*));
            for (int chan = 0; chan < fDSP2->getNumOutputs(); chan++) {
                outputs_dsp2[chan] = outputs[fDSP1->getNumOutputs() + chan];
            }
            
            fDSP2->compute(count, inputs_dsp2, outputs_dsp2);
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

#define BUFFER_SIZE     1024
#define SAMPLE_RATE     44100
#define MAX_CHAN        64

#define MIN_CHAN(a,b) ((a) < (b) ? (a) : (b))

struct Soundfile {
    
    int fLength;
    int fSampleRate;
    int fChannels;
    FAUSTFLOAT** fBuffers;
    
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
    static std::string Check(const std::string& soundfile_dir_str, const std::string& file_name_str, std::string& sha_key)
    {
        std::string path_name_str = CheckAux(file_name_str, sha_key);
        if (path_name_str != "") {
            return path_name_str;
        } else {
            return CheckAux(soundfile_dir_str + "/" + file_name_str, sha_key);
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
    
    virtual ~Soundfile()
    {
        // Free the real channels only
        for (int chan = 0; chan < fChannels; chan++) {
            delete fBuffers[chan];
        }
        delete [] fBuffers;
    }
    
};

#endif

// To be used by dsp code if no SoundUI is used or when soundfile is not found
static Soundfile* defaultsound = new Soundfile("", MAX_CHAN);

class SoundUI : public GenericUI
{
		
    private:
    
        std::string fSoundfileDir;                     // The soundfile directory
        std::map<std::string, Soundfile*> fSFMap;      // Map to share loaded soundfiles
    
     public:
            
        SoundUI(const std::string& sound_dir = ""):fSoundfileDir(sound_dir)
        {}
    
        virtual ~SoundUI()
        {   
            // delete all soundfiles
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

#include <cmath>
#include <math.h>

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
	int fSamplingFreq;
	double fConst0;
	double fConst1;
	double fConst2;
	double fConst3;
	double fConst4;
	double fRec0[3];
	double fConst5;
	double fRec1[3];
	double fConst6;
	double fConst7;
	double fConst8;
	double fRec2[3];
	double fConst9;
	double fConst10;
	double fConst11;
	double fRec3[3];
	double fConst12;
	double fConst13;
	double fConst14;
	double fRec4[3];
	double fConst15;
	double fConst16;
	double fConst17;
	double fConst18;
	double fRec5[3];
	double fConst19;
	double fConst20;
	double fConst21;
	double fConst22;
	double fRec6[3];
	double fConst23;
	double fConst24;
	double fConst25;
	double fConst26;
	double fRec7[3];
	double fConst27;
	double fRec8[3];
	double fConst28;
	double fConst29;
	double fConst30;
	double fConst31;
	double fRec9[3];
	double fConst32;
	double fConst33;
	double fConst34;
	double fRec10[3];
	double fConst35;
	double fConst36;
	double fConst37;
	double fRec11[3];
	double fConst38;
	double fConst39;
	double fConst40;
	double fConst41;
	double fRec12[3];
	double fConst42;
	double fConst43;
	double fConst44;
	double fRec13[3];
	double fConst45;
	double fConst46;
	double fConst47;
	double fConst48;
	double fRec14[3];
	double fConst49;
	double fRec15[3];
	double fConst50;
	double fConst51;
	double fConst52;
	double fConst53;
	double fRec16[3];
	double fConst54;
	double fConst55;
	double fConst56;
	double fConst57;
	double fRec17[3];
	double fConst58;
	double fConst59;
	double fConst60;
	double fConst61;
	double fRec18[3];
	double fConst62;
	double fRec19[3];
	double fConst63;
	double fConst64;
	double fConst65;
	double fConst66;
	double fRec20[3];
	double fConst67;
	double fRec21[3];
	double fConst68;
	double fRec22[3];
	double fConst69;
	double fConst70;
	double fConst71;
	double fConst72;
	double fRec23[3];
	double fConst73;
	double fConst74;
	double fConst75;
	double fConst76;
	double fRec24[3];
	double fConst77;
	double fConst78;
	double fConst79;
	double fRec25[3];
	double fConst80;
	double fRec26[3];
	double fConst81;
	double fConst82;
	double fConst83;
	double fConst84;
	double fRec27[3];
	double fConst85;
	double fConst86;
	double fConst87;
	double fRec28[3];
	double fConst88;
	double fConst89;
	double fConst90;
	double fConst91;
	double fRec29[3];
	double fConst92;
	double fConst93;
	double fConst94;
	double fRec30[3];
	double fConst95;
	double fConst96;
	double fConst97;
	double fConst98;
	double fRec31[3];
	double fConst99;
	double fConst100;
	double fConst101;
	double fConst102;
	double fRec32[3];
	double fConst103;
	double fConst104;
	double fConst105;
	double fRec33[3];
	double fConst106;
	double fRec34[3];
	double fConst107;
	double fRec35[3];
	double fConst108;
	double fRec36[3];
	double fConst109;
	double fRec37[3];
	double fConst110;
	double fConst111;
	double fConst112;
	double fRec38[3];
	double fConst113;
	double fConst114;
	double fConst115;
	double fConst116;
	double fRec39[3];
	double fConst117;
	double fConst118;
	double fConst119;
	double fRec40[3];
	double fConst120;
	double fConst121;
	double fConst122;
	double fRec41[3];
	double fConst123;
	double fRec42[3];
	double fConst124;
	double fRec43[3];
	double fConst125;
	double fConst126;
	double fConst127;
	double fRec44[3];
	double fConst128;
	double fConst129;
	double fConst130;
	double fConst131;
	double fRec45[3];
	double fConst132;
	double fConst133;
	double fConst134;
	double fConst135;
	double fRec46[3];
	double fConst136;
	double fRec47[3];
	double fConst137;
	double fConst138;
	double fConst139;
	double fRec48[3];
	double fConst140;
	double fConst141;
	double fConst142;
	double fRec49[3];
	double fConst143;
	double fRec50[3];
	double fConst144;
	double fRec51[3];
	double fConst145;
	double fRec52[3];
	double fConst146;
	double fConst147;
	double fConst148;
	double fRec53[3];
	double fConst149;
	double fConst150;
	double fConst151;
	double fConst152;
	double fRec54[3];
	double fConst153;
	double fConst154;
	double fConst155;
	double fRec55[3];
	double fConst156;
	double fConst157;
	double fConst158;
	double fConst159;
	double fRec56[3];
	double fConst160;
	double fRec57[3];
	double fConst161;
	double fRec58[3];
	double fConst162;
	double fConst163;
	double fConst164;
	double fConst165;
	double fRec59[3];
	double fConst166;
	double fConst167;
	double fConst168;
	double fRec60[3];
	double fConst169;
	double fRec61[3];
	double fConst170;
	double fRec62[3];
	double fConst171;
	double fConst172;
	double fConst173;
	double fRec63[3];
	double fConst174;
	double fConst175;
	double fConst176;
	double fConst177;
	double fRec64[3];
	double fConst178;
	double fRec65[3];
	double fConst179;
	double fConst180;
	double fConst181;
	double fRec66[3];
	double fConst182;
	double fConst183;
	double fConst184;
	double fRec67[3];
	double fConst185;
	double fRec68[3];
	double fConst186;
	double fConst187;
	double fConst188;
	double fRec69[3];
	double fConst189;
	double fConst190;
	double fConst191;
	double fRec70[3];
	double fConst192;
	double fRec71[3];
	double fConst193;
	double fConst194;
	double fConst195;
	double fRec72[3];
	double fConst196;
	double fConst197;
	double fConst198;
	double fConst199;
	double fRec73[3];
	double fConst200;
	double fConst201;
	double fConst202;
	double fRec74[3];
	double fConst203;
	double fConst204;
	double fConst205;
	double fRec75[3];
	double fConst206;
	double fConst207;
	double fConst208;
	double fRec76[3];
	double fConst209;
	double fConst210;
	double fConst211;
	double fConst212;
	double fRec77[3];
	double fConst213;
	double fConst214;
	double fConst215;
	double fConst216;
	double fRec78[3];
	double fConst217;
	double fConst218;
	double fConst219;
	double fRec79[3];
	double fConst220;
	double fRec80[3];
	double fConst221;
	double fRec81[3];
	double fConst222;
	double fConst223;
	double fConst224;
	double fConst225;
	double fRec82[3];
	double fConst226;
	double fRec83[3];
	double fConst227;
	double fConst228;
	double fConst229;
	double fRec84[3];
	double fConst230;
	double fConst231;
	double fConst232;
	double fConst233;
	double fRec85[3];
	double fConst234;
	double fConst235;
	double fConst236;
	double fConst237;
	double fRec86[3];
	double fConst238;
	double fRec87[3];
	double fConst239;
	double fConst240;
	double fConst241;
	double fRec88[3];
	double fConst242;
	double fRec89[3];
	double fConst243;
	double fRec90[3];
	double fConst244;
	double fRec91[3];
	double fConst245;
	double fConst246;
	double fConst247;
	double fRec92[3];
	double fConst248;
	double fConst249;
	double fConst250;
	double fRec93[3];
	double fConst251;
	double fConst252;
	double fConst253;
	double fRec94[3];
	double fConst254;
	double fConst255;
	double fConst256;
	double fConst257;
	double fRec95[3];
	double fConst258;
	double fConst259;
	double fConst260;
	double fConst261;
	double fRec96[3];
	double fConst262;
	double fConst263;
	double fConst264;
	double fConst265;
	double fRec97[3];
	double fConst266;
	double fConst267;
	double fConst268;
	double fRec98[3];
	double fConst269;
	double fConst270;
	double fConst271;
	double fConst272;
	double fRec99[3];
	double fConst273;
	double fConst274;
	double fConst275;
	double fRec100[3];
	double fConst276;
	double fConst277;
	double fConst278;
	double fRec101[3];
	double fConst279;
	double fConst280;
	double fConst281;
	double fConst282;
	double fRec102[3];
	double fConst283;
	double fConst284;
	double fConst285;
	double fConst286;
	double fRec103[3];
	double fConst287;
	double fConst288;
	double fConst289;
	double fConst290;
	double fRec104[3];
	double fConst291;
	double fConst292;
	double fConst293;
	double fConst294;
	double fRec105[3];
	double fConst295;
	double fConst296;
	double fConst297;
	double fRec106[3];
	double fConst298;
	double fConst299;
	double fConst300;
	double fRec107[3];
	double fConst301;
	double fConst302;
	double fConst303;
	double fRec108[3];
	double fConst304;
	double fConst305;
	double fConst306;
	double fRec109[3];
	double fConst307;
	double fConst308;
	double fConst309;
	double fConst310;
	double fRec110[3];
	double fConst311;
	double fRec111[3];
	double fConst312;
	double fConst313;
	double fConst314;
	double fRec112[3];
	double fConst315;
	double fConst316;
	double fConst317;
	double fRec113[3];
	double fConst318;
	double fRec114[3];
	double fConst319;
	double fRec115[3];
	double fConst320;
	double fRec116[3];
	double fConst321;
	double fRec117[3];
	double fConst322;
	double fConst323;
	double fConst324;
	double fConst325;
	double fRec118[3];
	double fConst326;
	double fConst327;
	double fConst328;
	double fRec119[3];
	double fConst329;
	double fRec120[3];
	double fConst330;
	double fRec121[3];
	double fConst331;
	double fRec122[3];
	double fConst332;
	double fConst333;
	double fConst334;
	double fRec123[3];
	double fConst335;
	double fConst336;
	double fConst337;
	double fConst338;
	double fRec124[3];
	double fConst339;
	double fRec125[3];
	double fConst340;
	double fConst341;
	double fConst342;
	double fConst343;
	double fRec126[3];
	double fConst344;
	double fConst345;
	double fConst346;
	double fRec127[3];
	double fConst347;
	double fConst348;
	double fConst349;
	double fRec128[3];
	double fConst350;
	double fConst351;
	double fConst352;
	double fRec129[3];
	double fConst353;
	double fRec130[3];
	double fConst354;
	double fRec131[3];
	double fConst355;
	double fRec132[3];
	double fConst356;
	double fRec133[3];
	double fConst357;
	double fRec134[3];
	double fConst358;
	double fConst359;
	double fConst360;
	double fRec135[3];
	double fConst361;
	double fConst362;
	double fConst363;
	double fConst364;
	double fRec136[3];
	double fConst365;
	double fRec137[3];
	double fConst366;
	double fRec138[3];
	double fConst367;
	double fConst368;
	double fConst369;
	double fRec139[3];
	double fConst370;
	double fConst371;
	double fConst372;
	double fRec140[3];
	double fConst373;
	double fConst374;
	double fConst375;
	double fRec141[3];
	double fConst376;
	double fConst377;
	double fConst378;
	double fRec142[3];
	double fConst379;
	double fRec143[3];
	double fConst380;
	double fConst381;
	double fConst382;
	double fRec144[3];
	double fConst383;
	double fConst384;
	double fConst385;
	double fRec145[3];
	double fConst386;
	double fConst387;
	double fConst388;
	double fRec146[3];
	double fConst389;
	double fConst390;
	double fConst391;
	double fRec147[3];
	double fConst392;
	double fRec148[3];
	double fConst393;
	double fConst394;
	double fConst395;
	double fRec149[3];
	double fConst396;
	double fConst397;
	double fConst398;
	double fRec150[3];
	double fConst399;
	double fRec151[3];
	double fConst400;
	double fRec152[3];
	double fConst401;
	double fConst402;
	double fConst403;
	double fConst404;
	double fRec153[3];
	double fConst405;
	double fRec154[3];
	double fConst406;
	double fConst407;
	double fConst408;
	double fRec155[3];
	double fConst409;
	double fRec156[3];
	double fConst410;
	double fRec157[3];
	double fConst411;
	double fRec158[3];
	double fConst412;
	double fRec159[3];
	double fConst413;
	double fConst414;
	double fConst415;
	double fConst416;
	double fRec160[3];
	double fConst417;
	double fRec161[3];
	double fConst418;
	double fConst419;
	double fConst420;
	double fConst421;
	double fRec162[3];
	double fConst422;
	double fRec163[3];
	double fConst423;
	double fConst424;
	double fConst425;
	double fRec164[3];
	double fConst426;
	double fRec165[3];
	double fConst427;
	double fConst428;
	double fConst429;
	double fRec166[3];
	double fConst430;
	double fConst431;
	double fConst432;
	double fRec167[3];
	double fConst433;
	double fRec168[3];
	double fConst434;
	double fConst435;
	double fConst436;
	double fRec169[3];
	double fConst437;
	double fRec170[3];
	double fConst438;
	double fConst439;
	double fConst440;
	double fRec171[3];
	double fConst441;
	double fConst442;
	double fConst443;
	double fRec172[3];
	double fConst444;
	double fConst445;
	double fConst446;
	double fRec173[3];
	double fConst447;
	double fConst448;
	double fConst449;
	double fRec174[3];
	double fConst450;
	double fConst451;
	double fConst452;
	double fConst453;
	double fRec175[3];
	double fConst454;
	double fRec176[3];
	double fConst455;
	double fRec177[3];
	double fConst456;
	double fConst457;
	double fConst458;
	double fRec178[3];
	double fConst459;
	double fConst460;
	double fConst461;
	double fConst462;
	double fRec179[3];
	double fConst463;
	double fConst464;
	double fConst465;
	double fRec180[3];
	double fConst466;
	double fConst467;
	double fConst468;
	double fRec181[3];
	double fConst469;
	double fConst470;
	double fConst471;
	double fRec182[3];
	double fConst472;
	double fRec183[3];
	double fConst473;
	double fConst474;
	double fConst475;
	double fRec184[3];
	double fConst476;
	double fConst477;
	double fConst478;
	double fConst479;
	double fRec185[3];
	double fConst480;
	double fConst481;
	double fConst482;
	double fRec186[3];
	double fConst483;
	double fConst484;
	double fConst485;
	double fConst486;
	double fRec187[3];
	double fConst487;
	double fRec188[3];
	double fConst488;
	double fConst489;
	double fConst490;
	double fRec189[3];
	double fConst491;
	double fConst492;
	double fConst493;
	double fConst494;
	double fRec190[3];
	double fConst495;
	double fRec191[3];
	double fConst496;
	double fRec192[3];
	double fConst497;
	double fRec193[3];
	double fConst498;
	double fRec194[3];
	double fConst499;
	double fRec195[3];
	double fConst500;
	double fConst501;
	double fConst502;
	double fRec196[3];
	double fConst503;
	double fRec197[3];
	double fConst504;
	double fRec198[3];
	double fConst505;
	double fConst506;
	double fConst507;
	double fRec199[3];
	double fConst508;
	double fConst509;
	double fConst510;
	double fConst511;
	double fRec200[3];
	double fConst512;
	double fRec201[3];
	double fConst513;
	double fConst514;
	double fConst515;
	double fRec202[3];
	double fConst516;
	double fConst517;
	double fConst518;
	double fConst519;
	double fRec203[3];
	double fConst520;
	double fConst521;
	double fConst522;
	double fRec204[3];
	double fConst523;
	double fRec205[3];
	double fConst524;
	double fRec206[3];
	double fConst525;
	double fRec207[3];
	double fConst526;
	double fRec208[3];
	double fConst527;
	double fRec209[3];
	double fConst528;
	double fRec210[3];
	double fConst529;
	double fRec211[3];
	double fConst530;
	double fRec212[3];
	double fConst531;
	double fRec213[3];
	double fConst532;
	double fRec214[3];
	double fConst533;
	double fConst534;
	double fConst535;
	double fRec215[3];
	double fConst536;
	double fRec216[3];
	double fConst537;
	double fRec217[3];
	double fConst538;
	double fConst539;
	double fConst540;
	double fConst541;
	double fRec218[3];
	double fConst542;
	double fRec219[3];
	double fConst543;
	double fRec220[3];
	double fConst544;
	double fRec221[3];
	double fConst545;
	double fRec222[3];
	double fConst546;
	double fRec223[3];
	double fConst547;
	double fRec224[3];
	double fConst548;
	double fRec225[3];
	double fConst549;
	double fRec226[3];
	double fConst550;
	double fRec227[3];
	double fConst551;
	double fRec228[3];
	double fConst552;
	double fRec229[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.0");
		m->declare("description", "Generated by tools/physicalModeling/ir2dsp.py");
		m->declare("filename", "cabinetVoxTopBoostBass");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "0.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.1");
		m->declare("name", "cabinetVoxTopBoostBass");
	}

	virtual int getNumInputs() {
		return 1;
		
	}
	virtual int getNumOutputs() {
		return 1;
		
	}
	virtual int getInputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
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
	virtual int getOutputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
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
		
	}
	
	virtual void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = min(192000.0, max(1.0, double(fSamplingFreq)));
		fConst1 = pow(0.001, (1.0 / (0.013315794649900001 * fConst0)));
		fConst2 = (0.0 - (2.0 * fConst1));
		fConst3 = (cos((628.23938743434269 / fConst0)) * fConst2);
		fConst4 = mydsp_faustpower2_f(fConst1);
		fConst5 = (fConst2 * cos((802.75032839056087 / fConst0)));
		fConst6 = pow(0.001, (1.0 / (0.0134024062651 * fConst0)));
		fConst7 = (cos((1047.0656457259988 / fConst0)) * (0.0 - (2.0 * fConst6)));
		fConst8 = mydsp_faustpower2_f(fConst6);
		fConst9 = pow(0.001, (1.0 / (0.013358959241299999 * fConst0)));
		fConst10 = (cos((1151.772210292944 / fConst0)) * (0.0 - (2.0 * fConst9)));
		fConst11 = mydsp_faustpower2_f(fConst9);
		fConst12 = pow(0.001, (1.0 / (0.149078647077 * fConst0)));
		fConst13 = (cos((1605.5006567748383 / fConst0)) * (0.0 - (2.0 * fConst12)));
		fConst14 = mydsp_faustpower2_f(fConst12);
		fConst15 = pow(0.001, (1.0 / (0.147283463044 * fConst0)));
		fConst16 = (0.0 - (2.0 * fConst15));
		fConst17 = (cos((1814.9137859212947 / fConst0)) * fConst16);
		fConst18 = mydsp_faustpower2_f(fConst15);
		fConst19 = pow(0.001, (1.0 / (0.21442964669600001 * fConst0)));
		fConst20 = (0.0 - (2.0 * fConst19));
		fConst21 = (cos((2163.9356678299609 / fConst0)) * fConst20);
		fConst22 = mydsp_faustpower2_f(fConst19);
		fConst23 = pow(0.001, (1.0 / (0.643132225291 * fConst0)));
		fConst24 = (0.0 - (2.0 * fConst23));
		fConst25 = (cos((3141.1969371717132 / fConst0)) * fConst24);
		fConst26 = mydsp_faustpower2_f(fConst23);
		fConst27 = (fConst16 * cos((4118.4582065134655 / fConst0)));
		fConst28 = pow(0.001, (1.0 / (0.077900177785300007 * fConst0)));
		fConst29 = (0.0 - (2.0 * fConst28));
		fConst30 = (cos((4572.1866529953604 / fConst0)) * fConst29);
		fConst31 = mydsp_faustpower2_f(fConst28);
		fConst32 = pow(0.001, (1.0 / (0.93992632156599998 * fConst0)));
		fConst33 = (cos((4956.1107230930083 / fConst0)) * (0.0 - (2.0 * fConst32)));
		fConst34 = mydsp_faustpower2_f(fConst32);
		fConst35 = pow(0.001, (1.0 / (0.370321491753 * fConst0)));
		fConst36 = (cos((5514.5457341418478 / fConst0)) * (0.0 - (2.0 * fConst35)));
		fConst37 = mydsp_faustpower2_f(fConst35);
		fConst38 = pow(0.001, (1.0 / (0.531296769015 * fConst0)));
		fConst39 = (0.0 - (2.0 * fConst38));
		fConst40 = (cos((5793.7632396725503 / fConst0)) * fConst39);
		fConst41 = mydsp_faustpower2_f(fConst38);
		fConst42 = pow(0.001, (1.0 / (0.33029520684899999 * fConst0)));
		fConst43 = (cos((7364.3617082835399 / fConst0)) * (0.0 - (2.0 * fConst42)));
		fConst44 = mydsp_faustpower2_f(fConst42);
		fConst45 = pow(0.001, (1.0 / (0.17975517475399999 * fConst0)));
		fConst46 = (0.0 - (2.0 * fConst45));
		fConst47 = (cos((7922.7967193072473 / fConst0)) * fConst46);
		fConst48 = mydsp_faustpower2_f(fConst45);
		fConst49 = (fConst46 * cos((7992.6010956852097 / fConst0)));
		fConst50 = pow(0.001, (1.0 / (0.019021125037899999 * fConst0)));
		fConst51 = (0.0 - (2.0 * fConst50));
		fConst52 = (cos((8341.6229775750271 / fConst0)) * fConst51);
		fConst53 = mydsp_faustpower2_f(fConst50);
		fConst54 = pow(0.001, (1.0 / (0.019050538957900001 * fConst0)));
		fConst55 = (0.0 - (2.0 * fConst54));
		fConst56 = (cos((8690.6448595276761 / fConst0)) * fConst55);
		fConst57 = mydsp_faustpower2_f(fConst54);
		fConst58 = pow(0.001, (1.0 / (0.0188754130108 * fConst0)));
		fConst59 = (0.0 - (2.0 * fConst58));
		fConst60 = (cos((9388.6886233073092 / fConst0)) * fConst59);
		fConst61 = mydsp_faustpower2_f(fConst58);
		fConst62 = (fConst59 * cos((9458.4929996852716 / fConst0)));
		fConst63 = pow(0.001, (1.0 / (0.021327177777100002 * fConst0)));
		fConst64 = (0.0 - (2.0 * fConst63));
		fConst65 = (cos((10051.830198929378 / fConst0)) * fConst64);
		fConst66 = mydsp_faustpower2_f(fConst63);
		fConst67 = (fConst64 * cos((10156.536763527738 / fConst0)));
		fConst68 = (fConst64 * cos((10365.949892661629 / fConst0)));
		fConst69 = pow(0.001, (1.0 / (0.24942577473999999 * fConst0)));
		fConst70 = (0.0 - (2.0 * fConst69));
		fConst71 = (cos((10854.580527307371 / fConst0)) * fConst70);
		fConst72 = mydsp_faustpower2_f(fConst69);
		fConst73 = pow(0.001, (1.0 / (0.254620512528 * fConst0)));
		fConst74 = (0.0 - (2.0 * fConst73));
		fConst75 = (cos((10994.189280126129 / fConst0)) * fConst74);
		fConst76 = mydsp_faustpower2_f(fConst73);
		fConst77 = pow(0.001, (1.0 / (0.030623470831300001 * fConst0)));
		fConst78 = (cos((11517.72210292944 / fConst0)) * (0.0 - (2.0 * fConst77)));
		fConst79 = mydsp_faustpower2_f(fConst77);
		fConst80 = (fConst70 * cos((11901.646173039653 / fConst0)));
		fConst81 = pow(0.001, (1.0 / (0.0213641963149 * fConst0)));
		fConst82 = (0.0 - (2.0 * fConst81));
		fConst83 = (cos((12425.178995905793 / fConst0)) * fConst82);
		fConst84 = mydsp_faustpower2_f(fConst81);
		fConst85 = pow(0.001, (1.0 / (0.061168496518700002 * fConst0)));
		fConst86 = (cos((13018.516195149899 / fConst0)) * (0.0 - (2.0 * fConst85)));
		fConst87 = mydsp_faustpower2_f(fConst85);
		fConst88 = pow(0.001, (1.0 / (0.27158998934700002 * fConst0)));
		fConst89 = (0.0 - (2.0 * fConst88));
		fConst90 = (cos((13332.635888882151 / fConst0)) * fConst89);
		fConst91 = mydsp_faustpower2_f(fConst88);
		fConst92 = pow(0.001, (1.0 / (0.10275083242499999 * fConst0)));
		fConst93 = (cos((13925.973088126255 / fConst0)) * (0.0 - (2.0 * fConst92)));
		fConst94 = mydsp_faustpower2_f(fConst92);
		fConst95 = pow(0.001, (1.0 / (0.207163501523 * fConst0)));
		fConst96 = (0.0 - (2.0 * fConst95));
		fConst97 = (cos((14693.821228346682 / fConst0)) * fConst96);
		fConst98 = mydsp_faustpower2_f(fConst95);
		fConst99 = pow(0.001, (1.0 / (0.210733934924 * fConst0)));
		fConst100 = (0.0 - (2.0 * fConst99));
		fConst101 = (cos((15077.745298394064 / fConst0)) * fConst100);
		fConst102 = mydsp_faustpower2_f(fConst99);
		fConst103 = pow(0.001, (1.0 / (0.19401523889300001 * fConst0)));
		fConst104 = (cos((15391.864992126317 / fConst0)) * (0.0 - (2.0 * fConst103)));
		fConst105 = mydsp_faustpower2_f(fConst103);
		fConst106 = (fConst96 * cos((15496.571556724679 / fConst0)));
		fConst107 = (fConst96 * cos((15705.984685858568 / fConst0)));
		fConst108 = (fConst96 * cos((15950.300003212855 / fConst0)));
		fConst109 = (fConst100 * cos((16055.006567748384 / fConst0)));
		fConst110 = pow(0.001, (1.0 / (0.0608645657491 * fConst0)));
		fConst111 = (cos((16613.441578834922 / fConst0)) * (0.0 - (2.0 * fConst110)));
		fConst112 = mydsp_faustpower2_f(fConst110);
		fConst113 = pow(0.001, (1.0 / (0.0221725126285 * fConst0)));
		fConst114 = (0.0 - (2.0 * fConst113));
		fConst115 = (cos((16997.365648882307 / fConst0)) * fConst114);
		fConst116 = mydsp_faustpower2_f(fConst113);
		fConst117 = pow(0.001, (1.0 / (0.0605636441966 * fConst0)));
		fConst118 = (cos((17381.289718992521 / fConst0)) * (0.0 - (2.0 * fConst117)));
		fConst119 = mydsp_faustpower2_f(fConst117);
		fConst120 = pow(0.001, (1.0 / (0.45259774442700001 * fConst0)));
		fConst121 = (cos((18184.040047370512 / fConst0)) * (0.0 - (2.0 * fConst120)));
		fConst122 = mydsp_faustpower2_f(fConst120);
		fConst123 = (fConst20 * cos((19021.692563968903 / fConst0)));
		fConst124 = (fConst74 * cos((20103.660397921587 / fConst0)));
		fConst125 = pow(0.001, (1.0 / (0.13891953748999999 * fConst0)));
		fConst126 = (cos((20452.682279811401 / fConst0)) * (0.0 - (2.0 * fConst125)));
		fConst127 = mydsp_faustpower2_f(fConst125);
		fConst128 = pow(0.001, (1.0 / (0.55544306068799998 * fConst0)));
		fConst129 = (0.0 - (2.0 * fConst128));
		fConst130 = (cos((20941.312914457147 / fConst0)) * fConst129);
		fConst131 = mydsp_faustpower2_f(fConst128);
		fConst132 = pow(0.001, (1.0 / (0.34916474114099999 * fConst0)));
		fConst133 = (0.0 - (2.0 * fConst132));
		fConst134 = (cos((21744.063242835138 / fConst0)) * fConst133);
		fConst135 = mydsp_faustpower2_f(fConst132);
		fConst136 = (fConst133 * cos((21918.574183811463 / fConst0)));
		fConst137 = pow(0.001, (1.0 / (0.030700024696799999 * fConst0)));
		fConst138 = (cos((22372.302630299644 / fConst0)) * (0.0 - (2.0 * fConst137)));
		fConst139 = mydsp_faustpower2_f(fConst137);
		fConst140 = pow(0.001, (1.0 / (0.13288296520000001 * fConst0)));
		fConst141 = (cos((22651.520135811494 / fConst0)) * (0.0 - (2.0 * fConst140)));
		fConst142 = mydsp_faustpower2_f(fConst140);
		fConst143 = (fConst55 * cos((23105.248582299675 / fConst0)));
		fConst144 = (fConst51 * cos((23454.270464189489 / fConst0)));
		fConst145 = (fConst114 * cos((23942.901098898066 / fConst0)));
		fConst146 = pow(0.001, (1.0 / (0.103620937917 * fConst0)));
		fConst147 = (cos((24780.553615433626 / fConst0)) * (0.0 - (2.0 * fConst146)));
		fConst148 = mydsp_faustpower2_f(fConst146);
		fConst149 = pow(0.001, (1.0 / (0.117559358926 * fConst0)));
		fConst150 = (0.0 - (2.0 * fConst149));
		fConst151 = (cos((25059.771121008311 / fConst0)) * fConst150);
		fConst152 = mydsp_faustpower2_f(fConst149);
		fConst153 = pow(0.001, (1.0 / (0.20037382490799999 * fConst0)));
		fConst154 = (cos((25653.108320252413 / fConst0)) * (0.0 - (2.0 * fConst153)));
		fConst155 = mydsp_faustpower2_f(fConst153);
		fConst156 = pow(0.001, (1.0 / (0.22633805133099999 * fConst0)));
		fConst157 = (0.0 - (2.0 * fConst156));
		fConst158 = (cos((25932.32582576427 / fConst0)) * fConst157);
		fConst159 = mydsp_faustpower2_f(fConst156);
		fConst160 = (fConst96 * cos((26211.54333127612 / fConst0)));
		fConst161 = (fConst96 * cos((26386.054272252448 / fConst0)));
		fConst162 = pow(0.001, (1.0 / (0.15473688538499999 * fConst0)));
		fConst163 = (0.0 - (2.0 * fConst162));
		fConst164 = (cos((26700.173965921862 / fConst0)) * fConst163);
		fConst165 = mydsp_faustpower2_f(fConst162);
		fConst166 = pow(0.001, (1.0 / (0.022212537959800001 * fConst0)));
		fConst167 = (cos((27642.533047118621 / fConst0)) * (0.0 - (2.0 * fConst166)));
		fConst168 = mydsp_faustpower2_f(fConst166);
		fConst169 = (fConst82 * cos((28270.772434520291 / fConst0)));
		fConst170 = (fConst55 * cos((28549.989940032141 / fConst0)));
		fConst171 = pow(0.001, (1.0 / (0.018991802183099999 * fConst0)));
		fConst172 = (cos((28899.011821984794 / fConst0)) * (0.0 - (2.0 * fConst171)));
		fConst173 = mydsp_faustpower2_f(fConst171);
		fConst174 = pow(0.001, (1.0 / (0.814613258605 * fConst0)));
		fConst175 = (0.0 - (2.0 * fConst174));
		fConst176 = (cos((29352.740268472968 / fConst0)) * fConst175);
		fConst177 = mydsp_faustpower2_f(fConst174);
		fConst178 = (fConst175 * cos((30434.708102362816 / fConst0)));
		fConst179 = pow(0.001, (1.0 / (0.26003630299500002 * fConst0)));
		fConst180 = (cos((30888.436548850994 / fConst0)) * (0.0 - (2.0 * fConst179)));
		fConst181 = mydsp_faustpower2_f(fConst179);
		fConst182 = pow(0.001, (1.0 / (0.29098367721200002 * fConst0)));
		fConst183 = (cos((31237.458430740808 / fConst0)) * (0.0 - (2.0 * fConst182)));
		fConst184 = mydsp_faustpower2_f(fConst182);
		fConst185 = (fConst175 * cos((32249.621888252695 / fConst0)));
		fConst186 = pow(0.001, (1.0 / (1.0182469859600001 * fConst0)));
		fConst187 = (cos((33017.470028473123 / fConst0)) * (0.0 - (2.0 * fConst186)));
		fConst188 = mydsp_faustpower2_f(fConst186);
		fConst189 = pow(0.001, (1.0 / (1.3576365318800001 * fConst0)));
		fConst190 = (cos((33506.1006631817 / fConst0)) * (0.0 - (2.0 * fConst189)));
		fConst191 = mydsp_faustpower2_f(fConst189);
		fConst192 = (fConst39 * cos((34029.63348598501 / fConst0)));
		fConst193 = pow(0.001, (1.0 / (0.488799295711 * fConst0)));
		fConst194 = (cos((34378.655367937652 / fConst0)) * (0.0 - (2.0 * fConst193)));
		fConst195 = mydsp_faustpower2_f(fConst193);
		fConst196 = pow(0.001, (1.0 / (0.87279432353899999 * fConst0)));
		fConst197 = (0.0 - (2.0 * fConst196));
		fConst198 = (cos((35006.894755339323 / fConst0)) * fConst197);
		fConst199 = mydsp_faustpower2_f(fConst196);
		fConst200 = pow(0.001, (1.0 / (0.14381981386199999 * fConst0)));
		fConst201 = (cos((35460.623201827504 / fConst0)) * (0.0 - (2.0 * fConst200)));
		fConst202 = mydsp_faustpower2_f(fConst200);
		fConst203 = pow(0.001, (1.0 / (0.011952203736799999 * fConst0)));
		fConst204 = (cos((35879.449460095282 / fConst0)) * (0.0 - (2.0 * fConst203)));
		fConst205 = mydsp_faustpower2_f(fConst203);
		fConst206 = pow(0.001, (1.0 / (0.0119176877079 * fConst0)));
		fConst207 = (cos((36228.471342047931 / fConst0)) * (0.0 - (2.0 * fConst206)));
		fConst208 = mydsp_faustpower2_f(fConst206);
		fConst209 = pow(0.001, (1.0 / (0.016028895488499999 * fConst0)));
		fConst210 = (0.0 - (2.0 * fConst209));
		fConst211 = (cos((36717.101976693673 / fConst0)) * fConst210);
		fConst212 = mydsp_faustpower2_f(fConst209);
		fConst213 = pow(0.001, (1.0 / (0.064047086976099996 * fConst0)));
		fConst214 = (0.0 - (2.0 * fConst213));
		fConst215 = (cos((36996.31948220553 / fConst0)) * fConst214);
		fConst216 = mydsp_faustpower2_f(fConst213);
		fConst217 = pow(0.001, (1.0 / (0.066843531989300001 * fConst0)));
		fConst218 = (cos((37205.732611402251 / fConst0)) * (0.0 - (2.0 * fConst217)));
		fConst219 = mydsp_faustpower2_f(fConst217);
		fConst220 = (fConst197 * cos((37659.461057827597 / fConst0)));
		fConst221 = (fConst24 * cos((38392.407009890463 / fConst0)));
		fConst222 = pow(0.001, (1.0 / (0.128689136067 * fConst0)));
		fConst223 = (0.0 - (2.0 * fConst222));
		fConst224 = (cos((38915.939832693766 / fConst0)) * fConst223);
		fConst225 = mydsp_faustpower2_f(fConst222);
		fConst226 = (fConst89 * cos((39299.863902803983 / fConst0)));
		fConst227 = pow(0.001, (1.0 / (0.13583417831200001 * fConst0)));
		fConst228 = (cos((39893.201102048093 / fConst0)) * (0.0 - (2.0 * fConst227)));
		fConst229 = mydsp_faustpower2_f(fConst227);
		fConst230 = pow(0.001, (1.0 / (0.16977312994099999 * fConst0)));
		fConst231 = (0.0 - (2.0 * fConst230));
		fConst232 = (cos((40207.320795780339 / fConst0)) * fConst231);
		fConst233 = mydsp_faustpower2_f(fConst230);
		fConst234 = pow(0.001, (1.0 / (0.096283276735800005 * fConst0)));
		fConst235 = (0.0 - (2.0 * fConst234));
		fConst236 = (cos((41079.875500536291 / fConst0)) * fConst235);
		fConst237 = mydsp_faustpower2_f(fConst234);
		fConst238 = (fConst29 * cos((41254.386441512623 / fConst0)));
		fConst239 = pow(0.001, (1.0 / (0.67885744053700003 * fConst0)));
		fConst240 = (cos((42022.23458173305 / fConst0)) * (0.0 - (2.0 * fConst239)));
		fConst241 = mydsp_faustpower2_f(fConst239);
		fConst242 = (fConst214 * cos((42894.789286489009 / fConst0)));
		fConst243 = (fConst214 * cos((43034.398039244938 / fConst0)));
		fConst244 = (fConst129 * cos((43906.952744000897 / fConst0)));
		fConst245 = pow(0.001, (1.0 / (0.0505660863164 * fConst0)));
		fConst246 = (cos((44570.094319622956 / fConst0)) * (0.0 - (2.0 * fConst245)));
		fConst247 = mydsp_faustpower2_f(fConst245);
		fConst248 = pow(0.001, (1.0 / (0.050358318166399997 * fConst0)));
		fConst249 = (cos((44744.605260599288 / fConst0)) * (0.0 - (2.0 * fConst248)));
		fConst250 = mydsp_faustpower2_f(fConst248);
		fConst251 = pow(0.001, (1.0 / (0.71878562230200005 * fConst0)));
		fConst252 = (cos((45582.257777134844 / fConst0)) * (0.0 - (2.0 * fConst251)));
		fConst253 = mydsp_faustpower2_f(fConst251);
		fConst254 = pow(0.001, (1.0 / (0.0160080997987 * fConst0)));
		fConst255 = (0.0 - (2.0 * fConst254));
		fConst256 = (cos((46001.084035465457 / fConst0)) * fConst255);
		fConst257 = mydsp_faustpower2_f(fConst254);
		fConst258 = pow(0.001, (1.0 / (0.76370482680899998 * fConst0)));
		fConst259 = (0.0 - (2.0 * fConst258));
		fConst260 = (cos((46524.616858331603 / fConst0)) * fConst259);
		fConst261 = mydsp_faustpower2_f(fConst258);
		fConst262 = pow(0.001, (1.0 / (0.063057880617800002 * fConst0)));
		fConst263 = (0.0 - (2.0 * fConst262));
		fConst264 = (cos((47466.975939465519 / fConst0)) * fConst263);
		fConst265 = mydsp_faustpower2_f(fConst262);
		fConst266 = pow(0.001, (1.0 / (0.116440492457 * fConst0)));
		fConst267 = (cos((48374.432832441875 / fConst0)) * (0.0 - (2.0 * fConst266)));
		fConst268 = mydsp_faustpower2_f(fConst266);
		fConst269 = pow(0.001, (1.0 / (0.097046807606399998 * fConst0)));
		fConst270 = (0.0 - (2.0 * fConst269));
		fConst271 = (cos((48688.552526111293 / fConst0)) * fConst270);
		fConst272 = mydsp_faustpower2_f(fConst269);
		fConst273 = pow(0.001, (1.0 / (0.145531021491 * fConst0)));
		fConst274 = (cos((49002.672219843545 / fConst0)) * (0.0 - (2.0 * fConst273)));
		fConst275 = mydsp_faustpower2_f(fConst273);
		fConst276 = pow(0.001, (1.0 / (0.137359524421 * fConst0)));
		fConst277 = (cos((49561.107230930087 / fConst0)) * (0.0 - (2.0 * fConst276)));
		fConst278 = mydsp_faustpower2_f(fConst276);
		fConst279 = pow(0.001, (1.0 / (0.12734944065600001 * fConst0)));
		fConst280 = (0.0 - (2.0 * fConst279));
		fConst281 = (cos((49840.324736441937 / fConst0)) * fConst280);
		fConst282 = mydsp_faustpower2_f(fConst279);
		fConst283 = pow(0.001, (1.0 / (0.126037367835 * fConst0)));
		fConst284 = (0.0 - (2.0 * fConst283));
		fConst285 = (cos((49910.129112819901 / fConst0)) * fConst284);
		fConst286 = mydsp_faustpower2_f(fConst283);
		fConst287 = pow(0.001, (1.0 / (0.063713916777299998 * fConst0)));
		fConst288 = (0.0 - (2.0 * fConst287));
		fConst289 = (cos((50608.172876662364 / fConst0)) * fConst288);
		fConst290 = mydsp_faustpower2_f(fConst287);
		fConst291 = pow(0.001, (1.0 / (0.055114524509700002 * fConst0)));
		fConst292 = (0.0 - (2.0 * fConst291));
		fConst293 = (cos((51061.90132308771 / fConst0)) * fConst292);
		fConst294 = mydsp_faustpower2_f(fConst291);
		fConst295 = pow(0.001, (1.0 / (0.054380709776599999 * fConst0)));
		fConst296 = (cos((51306.216640441999 / fConst0)) * (0.0 - (2.0 * fConst295)));
		fConst297 = mydsp_faustpower2_f(fConst295);
		fConst298 = pow(0.001, (1.0 / (0.054623130713700001 * fConst0)));
		fConst299 = (cos((51934.456027906497 / fConst0)) * (0.0 - (2.0 * fConst298)));
		fConst300 = mydsp_faustpower2_f(fConst298);
		fConst301 = pow(0.001, (1.0 / (0.026639342724800001 * fConst0)));
		fConst302 = (cos((52178.771345197951 / fConst0)) * (0.0 - (2.0 * fConst301)));
		fConst303 = mydsp_faustpower2_f(fConst301);
		fConst304 = pow(0.001, (1.0 / (0.054867725831199997 * fConst0)));
		fConst305 = (cos((52527.793227150607 / fConst0)) * (0.0 - (2.0 * fConst304)));
		fConst306 = mydsp_faustpower2_f(fConst304);
		fConst307 = pow(0.001, (1.0 / (0.055868443769900002 * fConst0)));
		fConst308 = (0.0 - (2.0 * fConst307));
		fConst309 = (cos((53051.326050016745 / fConst0)) * fConst308);
		fConst310 = mydsp_faustpower2_f(fConst307);
		fConst311 = (fConst292 * cos((53435.250120064127 / fConst0)));
		fConst312 = pow(0.001, (1.0 / (0.026524360717600001 * fConst0)));
		fConst313 = (cos((54063.489507528633 / fConst0)) * (0.0 - (2.0 * fConst312)));
		fConst314 = mydsp_faustpower2_f(fConst312);
		fConst315 = pow(0.001, (1.0 / (0.016282746357799999 * fConst0)));
		fConst316 = (cos((54238.000448504958 / fConst0)) * (0.0 - (2.0 * fConst315)));
		fConst317 = mydsp_faustpower2_f(fConst315);
		fConst318 = (fConst255 * cos((54901.142024127017 / fConst0)));
		fConst319 = (fConst255 * cos((55215.261717796442 / fConst0)));
		fConst320 = (fConst255 * cos((55529.381411528695 / fConst0)));
		fConst321 = (fConst255 * cos((55599.185787906652 / fConst0)));
		fConst322 = pow(0.001, (1.0 / (0.016049745546599999 * fConst0)));
		fConst323 = (0.0 - (2.0 * fConst322));
		fConst324 = (cos((56052.914234394826 / fConst0)) * fConst323);
		fConst325 = mydsp_faustpower2_f(fConst322);
		fConst326 = pow(0.001, (1.0 / (0.052069974113800002 * fConst0)));
		fConst327 = (cos((56541.544869040583 / fConst0)) * (0.0 - (2.0 * fConst326)));
		fConst328 = mydsp_faustpower2_f(fConst326);
		fConst329 = (fConst210 * cos((57099.97988012711 / fConst0)));
		fConst330 = (fConst210 * cos((57169.784256505081 / fConst0)));
		fConst331 = (fConst323 * cos((57483.903950237334 / fConst0)));
		fConst332 = pow(0.001, (1.0 / (0.016261283908799998 * fConst0)));
		fConst333 = (cos((57972.534584883077 / fConst0)) * (0.0 - (2.0 * fConst332)));
		fConst334 = mydsp_faustpower2_f(fConst332);
		fConst335 = pow(0.001, (1.0 / (0.15875398966000001 * fConst0)));
		fConst336 = (0.0 - (2.0 * fConst335));
		fConst337 = (cos((58565.871784127172 / fConst0)) * fConst336);
		fConst338 = mydsp_faustpower2_f(fConst335);
		fConst339 = (fConst284 * cos((58984.69804239495 / fConst0)));
		fConst340 = pow(0.001, (1.0 / (0.13005733563899999 * fConst0)));
		fConst341 = (0.0 - (2.0 * fConst340));
		fConst342 = (cos((59368.622112505174 / fConst0)) * fConst341);
		fConst343 = mydsp_faustpower2_f(fConst340);
		fConst344 = pow(0.001, (1.0 / (0.152803653959 * fConst0)));
		fConst345 = (cos((59578.03524163906 / fConst0)) * (0.0 - (2.0 * fConst344)));
		fConst346 = mydsp_faustpower2_f(fConst344);
		fConst347 = pow(0.001, (1.0 / (0.0596784944693 * fConst0)));
		fConst348 = (cos((60276.079005481522 / fConst0)) * (0.0 - (2.0 * fConst347)));
		fConst349 = mydsp_faustpower2_f(fConst347);
		fConst350 = pow(0.001, (1.0 / (0.059389173687800001 * fConst0)));
		fConst351 = (cos((60625.100887371344 / fConst0)) * (0.0 - (2.0 * fConst350)));
		fConst352 = mydsp_faustpower2_f(fConst350);
		fConst353 = (fConst255 * cos((61148.633710237489 / fConst0)));
		fConst354 = (fConst323 * cos((61532.557780347699 / fConst0)));
		fConst355 = (fConst323 * cos((61741.970909481584 / fConst0)));
		fConst356 = (fConst255 * cos((62090.992791371405 / fConst0)));
		fConst357 = (fConst210 * cos((62335.308108725694 / fConst0)));
		fConst358 = pow(0.001, (1.0 / (0.016070650186499998 * fConst0)));
		fConst359 = (cos((62544.72123785958 / fConst0)) * (0.0 - (2.0 * fConst358)));
		fConst360 = mydsp_faustpower2_f(fConst358);
		fConst361 = pow(0.001, (1.0 / (0.015966670675399999 * fConst0)));
		fConst362 = (0.0 - (2.0 * fConst361));
		fConst363 = (cos((63068.254060474399 / fConst0)) * fConst362);
		fConst364 = mydsp_faustpower2_f(fConst361);
		fConst365 = (fConst362 * cos((63138.058437166525 / fConst0)));
		fConst366 = (fConst362 * cos((63242.765001576379 / fConst0)));
		fConst367 = pow(0.001, (1.0 / (0.015623035668500001 * fConst0)));
		fConst368 = (cos((63801.200012600093 / fConst0)) * (0.0 - (2.0 * fConst367)));
		fConst369 = mydsp_faustpower2_f(fConst367);
		fConst370 = pow(0.001, (1.0 / (0.0052756858927000003 * fConst0)));
		fConst371 = (cos((64254.92845921393 / fConst0)) * (0.0 - (2.0 * fConst370)));
		fConst372 = mydsp_faustpower2_f(fConst370);
		fConst373 = pow(0.001, (1.0 / (0.0064855982833299996 * fConst0)));
		fConst374 = (cos((64394.537211969866 / fConst0)) * (0.0 - (2.0 * fConst373)));
		fConst375 = mydsp_faustpower2_f(fConst373);
		fConst376 = pow(0.001, (1.0 / (0.31336100944099998 * fConst0)));
		fConst377 = (cos((65301.994105197547 / fConst0)) * (0.0 - (2.0 * fConst376)));
		fConst378 = mydsp_faustpower2_f(fConst376);
		fConst379 = (fConst336 * cos((65616.113798427134 / fConst0)));
		fConst380 = pow(0.001, (1.0 / (0.188047950499 * fConst0)));
		fConst381 = (cos((65755.722551183062 / fConst0)) * (0.0 - (2.0 * fConst380)));
		fConst382 = mydsp_faustpower2_f(fConst380);
		fConst383 = pow(0.001, (1.0 / (0.203712082574 * fConst0)));
		fConst384 = (cos((66034.940056694919 / fConst0)) * (0.0 - (2.0 * fConst383)));
		fConst385 = mydsp_faustpower2_f(fConst383);
		fConst386 = pow(0.001, (1.0 / (0.0064889595714400002 * fConst0)));
		fConst387 = (cos((66488.668503308771 / fConst0)) * (0.0 - (2.0 * fConst386)));
		fConst388 = mydsp_faustpower2_f(fConst386);
		fConst389 = pow(0.001, (1.0 / (0.0566433052457 * fConst0)));
		fConst390 = (cos((67361.223208190379 / fConst0)) * (0.0 - (2.0 * fConst389)));
		fConst391 = mydsp_faustpower2_f(fConst389);
		fConst392 = (fConst308 * cos((67640.440713702235 / fConst0)));
		fConst393 = pow(0.001, (1.0 / (0.057710567300400001 * fConst0)));
		fConst394 = (cos((68094.169160316073 / fConst0)) * (0.0 - (2.0 * fConst393)));
		fConst395 = mydsp_faustpower2_f(fConst393);
		fConst396 = pow(0.001, (1.0 / (0.063384199121099993 * fConst0)));
		fConst397 = (cos((68268.680101418067 / fConst0)) * (0.0 - (2.0 * fConst396)));
		fConst398 = mydsp_faustpower2_f(fConst396);
		fConst399 = (fConst288 * cos((68373.386665827929 / fConst0)));
		fConst400 = (fConst263 * cos((68443.19104189174 / fConst0)));
		fConst401 = pow(0.001, (1.0 / (0.21825734818 * fConst0)));
		fConst402 = (0.0 - (2.0 * fConst401));
		fConst403 = (cos((68827.115112441767 / fConst0)) * fConst402);
		fConst404 = mydsp_faustpower2_f(fConst401);
		fConst405 = (fConst402 * cos((69594.963252285204 / fConst0)));
		fConst406 = pow(0.001, (1.0 / (0.12225859813000001 * fConst0)));
		fConst407 = (cos((70467.517957166841 / fConst0)) * (0.0 - (2.0 * fConst406)));
		fConst408 = mydsp_faustpower2_f(fConst406);
		fConst409 = (fConst280 * cos((71165.561720946454 / fConst0)));
		fConst410 = (fConst284 * cos((71374.974850394516 / fConst0)));
		fConst411 = (fConst341 * cos((71584.38797921424 / fConst0)));
		fConst412 = (fConst341 * cos((71933.409861418215 / fConst0)));
		fConst413 = pow(0.001, (1.0 / (0.16744854417400001 * fConst0)));
		fConst414 = (0.0 - (2.0 * fConst413));
		fConst415 = (cos((72142.822990237953 / fConst0)) * fConst414);
		fConst416 = mydsp_faustpower2_f(fConst413);
		fConst417 = (fConst223 * cos((73015.377695119576 / fConst0)));
		fConst418 = pow(0.001, (1.0 / (0.057171949064100003 * fConst0)));
		fConst419 = (0.0 - (2.0 * fConst418));
		fConst420 = (cos((73783.225835591336 / fConst0)) * fConst419);
		fConst421 = mydsp_faustpower2_f(fConst418);
		fConst422 = (fConst419 * cos((74062.443341103179 / fConst0)));
		fConst423 = pow(0.001, (1.0 / (0.057439993819400001 * fConst0)));
		fConst424 = (cos((74202.052093859107 / fConst0)) * (0.0 - (2.0 * fConst423)));
		fConst425 = mydsp_faustpower2_f(fConst423);
		fConst426 = (fConst150 * cos((75179.313363150592 / fConst0)));
		fConst427 = pow(0.001, (1.0 / (0.109167860492 * fConst0)));
		fConst428 = (cos((75702.846185828239 / fConst0)) * (0.0 - (2.0 * fConst427)));
		fConst429 = mydsp_faustpower2_f(fConst427);
		fConst430 = pow(0.001, (1.0 / (0.110150648586 * fConst0)));
		fConst431 = (cos((75947.161502994029 / fConst0)) * (0.0 - (2.0 * fConst430)));
		fConst432 = mydsp_faustpower2_f(fConst430);
		fConst433 = (fConst163 * cos((76261.281196851953 / fConst0)));
		fConst434 = pow(0.001, (1.0 / (0.114265499704 * fConst0)));
		fConst435 = (cos((76749.911831811856 / fConst0)) * (0.0 - (2.0 * fConst434)));
		fConst436 = mydsp_faustpower2_f(fConst434);
		fConst437 = (fConst20 * cos((77203.640277797371 / fConst0)));
		fConst438 = pow(0.001, (1.0 / (0.118699950961 * fConst0)));
		fConst439 = (cos((77587.564348347412 / fConst0)) * (0.0 - (2.0 * fConst438)));
		fConst440 = mydsp_faustpower2_f(fConst438);
		fConst441 = pow(0.001, (1.0 / (0.107254010001 * fConst0)));
		fConst442 = (cos((78111.09717102506 / fConst0)) * (0.0 - (2.0 * fConst441)));
		fConst443 = mydsp_faustpower2_f(fConst441);
		fConst444 = pow(0.001, (1.0 / (0.062734908972699996 * fConst0)));
		fConst445 = (cos((78390.314676536902 / fConst0)) * (0.0 - (2.0 * fConst444)));
		fConst446 = mydsp_faustpower2_f(fConst444);
		fConst447 = pow(0.001, (1.0 / (0.0624152329582 * fConst0)));
		fConst448 = (cos((79053.456251970492 / fConst0)) * (0.0 - (2.0 * fConst447)));
		fConst449 = mydsp_faustpower2_f(fConst447);
		fConst450 = pow(0.001, (1.0 / (0.029378231457300001 * fConst0)));
		fConst451 = (0.0 - (2.0 * fConst450));
		fConst452 = (cos((79262.869381418539 / fConst0)) * fConst451);
		fConst453 = mydsp_faustpower2_f(fConst450);
		fConst454 = (fConst451 * cos((79367.575945828401 / fConst0)));
		fConst455 = (fConst451 * cos((79437.380322520519 / fConst0)));
		fConst456 = pow(0.001, (1.0 / (0.165186785054 * fConst0)));
		fConst457 = (cos((79960.913145198167 / fConst0)) * (0.0 - (2.0 * fConst456)));
		fConst458 = mydsp_faustpower2_f(fConst456);
		fConst459 = pow(0.001, (1.0 / (0.16298533951499999 * fConst0)));
		fConst460 = (0.0 - (2.0 * fConst459));
		fConst461 = (cos((80205.228462363957 / fConst0)) * fConst460);
		fConst462 = mydsp_faustpower2_f(fConst459);
		fConst463 = pow(0.001, (1.0 / (0.16084182675700001 * fConst0)));
		fConst464 = (cos((80379.739403465952 / fConst0)) * (0.0 - (2.0 * fConst463)));
		fConst465 = mydsp_faustpower2_f(fConst463);
		fConst466 = pow(0.001, (1.0 / (0.174621551698 * fConst0)));
		fConst467 = (cos((80903.272226143585 / fConst0)) * (0.0 - (2.0 * fConst466)));
		fConst468 = mydsp_faustpower2_f(fConst466);
		fConst469 = pow(0.001, (1.0 / (0.61097953158700002 * fConst0)));
		fConst470 = (cos((81950.337872127202 / fConst0)) * (0.0 - (2.0 * fConst469)));
		fConst471 = mydsp_faustpower2_f(fConst469);
		fConst472 = (fConst259 * cos((82927.599141418686 / fConst0)));
		fConst473 = pow(0.001, (1.0 / (0.10022610011200001 * fConst0)));
		fConst474 = (cos((83904.860410710171 / fConst0)) * (0.0 - (2.0 * fConst473)));
		fConst475 = mydsp_faustpower2_f(fConst473);
		fConst476 = pow(0.001, (1.0 / (0.092639152163999997 * fConst0)));
		fConst477 = (0.0 - (2.0 * fConst476));
		fConst478 = (cos((84149.175727875961 / fConst0)) * fConst477);
		fConst479 = mydsp_faustpower2_f(fConst476);
		fConst480 = pow(0.001, (1.0 / (0.094063163911999995 * fConst0)));
		fConst481 = (cos((84323.686668977956 / fConst0)) * (0.0 - (2.0 * fConst480)));
		fConst482 = mydsp_faustpower2_f(fConst480);
		fConst483 = pow(0.001, (1.0 / (0.235040347058 * fConst0)));
		fConst484 = (0.0 - (2.0 * fConst483));
		fConst485 = (cos((84777.415115591793 / fConst0)) * fConst484);
		fConst486 = mydsp_faustpower2_f(fConst483);
		fConst487 = (fConst484 * cos((84951.926056065466 / fConst0)));
		fConst488 = pow(0.001, (1.0 / (0.071113394818299994 * fConst0)));
		fConst489 = (cos((85405.654502679303 / fConst0)) * (0.0 - (2.0 * fConst488)));
		fConst490 = mydsp_faustpower2_f(fConst488);
		fConst491 = pow(0.001, (1.0 / (0.097822554973599998 * fConst0)));
		fConst492 = (0.0 - (2.0 * fConst491));
		fConst493 = (cos((85719.774196537212 / fConst0)) * fConst492);
		fConst494 = mydsp_faustpower2_f(fConst491);
		fConst495 = (fConst492 * cos((85824.480760947088 / fConst0)));
		fConst496 = (fConst270 * cos((86033.893890395135 / fConst0)));
		fConst497 = (fConst235 * cos((86103.698266458945 / fConst0)));
		fConst498 = (fConst270 * cos((86208.404831497115 / fConst0)));
		fConst499 = (fConst270 * cos((86278.209207560925 / fConst0)));
		fConst500 = pow(0.001, (1.0 / (0.071528804132399995 * fConst0)));
		fConst501 = (cos((86557.426713072782 / fConst0)) * (0.0 - (2.0 * fConst500)));
		fConst502 = mydsp_faustpower2_f(fConst500);
		fConst503 = (fConst477 * cos((86697.035465828711 / fConst0)));
		fConst504 = (fConst24 * cos((87185.666100788614 / fConst0)));
		fConst505 = pow(0.001, (1.0 / (0.0049118469725599996 * fConst0)));
		fConst506 = (cos((87744.101111812313 / fConst0)) * (0.0 - (2.0 * fConst505)));
		fConst507 = mydsp_faustpower2_f(fConst505);
		fConst508 = pow(0.001, (1.0 / (0.0049099360767499997 * fConst0)));
		fConst509 = (0.0 - (2.0 * fConst508));
		fConst510 = (cos((87883.709864568242 / fConst0)) * fConst509);
		fConst511 = mydsp_faustpower2_f(fConst508);
		fConst512 = (fConst509 * cos((88372.340498899837 / fConst0)));
		fConst513 = pow(0.001, (1.0 / (0.17715116305600001 * fConst0)));
		fConst514 = (cos((90222.15647307293 / fConst0)) * (0.0 - (2.0 * fConst513)));
		fConst515 = mydsp_faustpower2_f(fConst513);
		fConst516 = pow(0.001, (1.0 / (0.18243691814900001 * fConst0)));
		fConst517 = (0.0 - (2.0 * fConst516));
		fConst518 = (cos((90536.276166930853 / fConst0)) * fConst517);
		fConst519 = mydsp_faustpower2_f(fConst516);
		fConst520 = pow(0.001, (1.0 / (0.18519992650100001 * fConst0)));
		fConst521 = (cos((90780.591484096643 / fConst0)) * (0.0 - (2.0 * fConst520)));
		fConst522 = mydsp_faustpower2_f(fConst520);
		fConst523 = (fConst517 * cos((90885.298048506505 / fConst0)));
		fConst524 = (fConst517 * cos((90990.00461354469 / fConst0)));
		fConst525 = (fConst517 * cos((91164.515554018362 / fConst0)));
		fConst526 = (fConst517 * cos((91339.026495120343 / fConst0)));
		fConst527 = (fConst517 * cos((91408.830871812475 / fConst0)));
		fConst528 = (fConst517 * cos((91478.635247876271 / fConst0)));
		fConst529 = (fConst517 * cos((91548.439624568389 / fConst0)));
		fConst530 = (fConst341 * cos((94619.832185198786 / fConst0)));
		fConst531 = (fConst341 * cos((94689.636561890919 / fConst0)));
		fConst532 = (fConst341 * cos((95003.756255120505 / fConst0)));
		fConst533 = pow(0.001, (1.0 / (0.13434235629800001 * fConst0)));
		fConst534 = (cos((95108.462820158689 / fConst0)) * (0.0 - (2.0 * fConst533)));
		fConst535 = mydsp_faustpower2_f(fConst533);
		fConst536 = (fConst460 * cos((95178.267196222499 / fConst0)));
		fConst537 = (fConst157 * cos((95387.680325670546 / fConst0)));
		fConst538 = pow(0.001, (1.0 / (0.230607102062 * fConst0)));
		fConst539 = (0.0 - (2.0 * fConst538));
		fConst540 = (cos((95527.28907842646 / fConst0)) * fConst539);
		fConst541 = mydsp_faustpower2_f(fConst538);
		fConst542 = (fConst539 * cos((95631.995642836337 / fConst0)));
		fConst543 = (fConst157 * cos((95736.702207246199 / fConst0)));
		fConst544 = (fConst157 * cos((95806.506583938317 / fConst0)));
		fConst545 = (fConst157 * cos((95876.310960002127 / fConst0)));
		fConst546 = (fConst460 * cos((96050.821901104107 / fConst0)));
		fConst547 = (fConst460 * cos((96155.528465513984 / fConst0)));
		fConst548 = (fConst460 * cos((96260.235029923846 / fConst0)));
		fConst549 = (fConst414 * cos((96330.039406615964 / fConst0)));
		fConst550 = (fConst460 * cos((96399.843782679774 / fConst0)));
		fConst551 = (fConst231 * cos((96539.452535435703 / fConst0)));
		fConst552 = (fConst414 * cos((96713.963476537683 / fConst0)));
		
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = FAUSTFLOAT(1.0);
		
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 3); l0 = (l0 + 1)) {
			fRec0[l0] = 0.0;
			
		}
		for (int l1 = 0; (l1 < 3); l1 = (l1 + 1)) {
			fRec1[l1] = 0.0;
			
		}
		for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
			fRec2[l2] = 0.0;
			
		}
		for (int l3 = 0; (l3 < 3); l3 = (l3 + 1)) {
			fRec3[l3] = 0.0;
			
		}
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec4[l4] = 0.0;
			
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec5[l5] = 0.0;
			
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec6[l6] = 0.0;
			
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec7[l7] = 0.0;
			
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec8[l8] = 0.0;
			
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec9[l9] = 0.0;
			
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec10[l10] = 0.0;
			
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec11[l11] = 0.0;
			
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec12[l12] = 0.0;
			
		}
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec13[l13] = 0.0;
			
		}
		for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
			fRec14[l14] = 0.0;
			
		}
		for (int l15 = 0; (l15 < 3); l15 = (l15 + 1)) {
			fRec15[l15] = 0.0;
			
		}
		for (int l16 = 0; (l16 < 3); l16 = (l16 + 1)) {
			fRec16[l16] = 0.0;
			
		}
		for (int l17 = 0; (l17 < 3); l17 = (l17 + 1)) {
			fRec17[l17] = 0.0;
			
		}
		for (int l18 = 0; (l18 < 3); l18 = (l18 + 1)) {
			fRec18[l18] = 0.0;
			
		}
		for (int l19 = 0; (l19 < 3); l19 = (l19 + 1)) {
			fRec19[l19] = 0.0;
			
		}
		for (int l20 = 0; (l20 < 3); l20 = (l20 + 1)) {
			fRec20[l20] = 0.0;
			
		}
		for (int l21 = 0; (l21 < 3); l21 = (l21 + 1)) {
			fRec21[l21] = 0.0;
			
		}
		for (int l22 = 0; (l22 < 3); l22 = (l22 + 1)) {
			fRec22[l22] = 0.0;
			
		}
		for (int l23 = 0; (l23 < 3); l23 = (l23 + 1)) {
			fRec23[l23] = 0.0;
			
		}
		for (int l24 = 0; (l24 < 3); l24 = (l24 + 1)) {
			fRec24[l24] = 0.0;
			
		}
		for (int l25 = 0; (l25 < 3); l25 = (l25 + 1)) {
			fRec25[l25] = 0.0;
			
		}
		for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) {
			fRec26[l26] = 0.0;
			
		}
		for (int l27 = 0; (l27 < 3); l27 = (l27 + 1)) {
			fRec27[l27] = 0.0;
			
		}
		for (int l28 = 0; (l28 < 3); l28 = (l28 + 1)) {
			fRec28[l28] = 0.0;
			
		}
		for (int l29 = 0; (l29 < 3); l29 = (l29 + 1)) {
			fRec29[l29] = 0.0;
			
		}
		for (int l30 = 0; (l30 < 3); l30 = (l30 + 1)) {
			fRec30[l30] = 0.0;
			
		}
		for (int l31 = 0; (l31 < 3); l31 = (l31 + 1)) {
			fRec31[l31] = 0.0;
			
		}
		for (int l32 = 0; (l32 < 3); l32 = (l32 + 1)) {
			fRec32[l32] = 0.0;
			
		}
		for (int l33 = 0; (l33 < 3); l33 = (l33 + 1)) {
			fRec33[l33] = 0.0;
			
		}
		for (int l34 = 0; (l34 < 3); l34 = (l34 + 1)) {
			fRec34[l34] = 0.0;
			
		}
		for (int l35 = 0; (l35 < 3); l35 = (l35 + 1)) {
			fRec35[l35] = 0.0;
			
		}
		for (int l36 = 0; (l36 < 3); l36 = (l36 + 1)) {
			fRec36[l36] = 0.0;
			
		}
		for (int l37 = 0; (l37 < 3); l37 = (l37 + 1)) {
			fRec37[l37] = 0.0;
			
		}
		for (int l38 = 0; (l38 < 3); l38 = (l38 + 1)) {
			fRec38[l38] = 0.0;
			
		}
		for (int l39 = 0; (l39 < 3); l39 = (l39 + 1)) {
			fRec39[l39] = 0.0;
			
		}
		for (int l40 = 0; (l40 < 3); l40 = (l40 + 1)) {
			fRec40[l40] = 0.0;
			
		}
		for (int l41 = 0; (l41 < 3); l41 = (l41 + 1)) {
			fRec41[l41] = 0.0;
			
		}
		for (int l42 = 0; (l42 < 3); l42 = (l42 + 1)) {
			fRec42[l42] = 0.0;
			
		}
		for (int l43 = 0; (l43 < 3); l43 = (l43 + 1)) {
			fRec43[l43] = 0.0;
			
		}
		for (int l44 = 0; (l44 < 3); l44 = (l44 + 1)) {
			fRec44[l44] = 0.0;
			
		}
		for (int l45 = 0; (l45 < 3); l45 = (l45 + 1)) {
			fRec45[l45] = 0.0;
			
		}
		for (int l46 = 0; (l46 < 3); l46 = (l46 + 1)) {
			fRec46[l46] = 0.0;
			
		}
		for (int l47 = 0; (l47 < 3); l47 = (l47 + 1)) {
			fRec47[l47] = 0.0;
			
		}
		for (int l48 = 0; (l48 < 3); l48 = (l48 + 1)) {
			fRec48[l48] = 0.0;
			
		}
		for (int l49 = 0; (l49 < 3); l49 = (l49 + 1)) {
			fRec49[l49] = 0.0;
			
		}
		for (int l50 = 0; (l50 < 3); l50 = (l50 + 1)) {
			fRec50[l50] = 0.0;
			
		}
		for (int l51 = 0; (l51 < 3); l51 = (l51 + 1)) {
			fRec51[l51] = 0.0;
			
		}
		for (int l52 = 0; (l52 < 3); l52 = (l52 + 1)) {
			fRec52[l52] = 0.0;
			
		}
		for (int l53 = 0; (l53 < 3); l53 = (l53 + 1)) {
			fRec53[l53] = 0.0;
			
		}
		for (int l54 = 0; (l54 < 3); l54 = (l54 + 1)) {
			fRec54[l54] = 0.0;
			
		}
		for (int l55 = 0; (l55 < 3); l55 = (l55 + 1)) {
			fRec55[l55] = 0.0;
			
		}
		for (int l56 = 0; (l56 < 3); l56 = (l56 + 1)) {
			fRec56[l56] = 0.0;
			
		}
		for (int l57 = 0; (l57 < 3); l57 = (l57 + 1)) {
			fRec57[l57] = 0.0;
			
		}
		for (int l58 = 0; (l58 < 3); l58 = (l58 + 1)) {
			fRec58[l58] = 0.0;
			
		}
		for (int l59 = 0; (l59 < 3); l59 = (l59 + 1)) {
			fRec59[l59] = 0.0;
			
		}
		for (int l60 = 0; (l60 < 3); l60 = (l60 + 1)) {
			fRec60[l60] = 0.0;
			
		}
		for (int l61 = 0; (l61 < 3); l61 = (l61 + 1)) {
			fRec61[l61] = 0.0;
			
		}
		for (int l62 = 0; (l62 < 3); l62 = (l62 + 1)) {
			fRec62[l62] = 0.0;
			
		}
		for (int l63 = 0; (l63 < 3); l63 = (l63 + 1)) {
			fRec63[l63] = 0.0;
			
		}
		for (int l64 = 0; (l64 < 3); l64 = (l64 + 1)) {
			fRec64[l64] = 0.0;
			
		}
		for (int l65 = 0; (l65 < 3); l65 = (l65 + 1)) {
			fRec65[l65] = 0.0;
			
		}
		for (int l66 = 0; (l66 < 3); l66 = (l66 + 1)) {
			fRec66[l66] = 0.0;
			
		}
		for (int l67 = 0; (l67 < 3); l67 = (l67 + 1)) {
			fRec67[l67] = 0.0;
			
		}
		for (int l68 = 0; (l68 < 3); l68 = (l68 + 1)) {
			fRec68[l68] = 0.0;
			
		}
		for (int l69 = 0; (l69 < 3); l69 = (l69 + 1)) {
			fRec69[l69] = 0.0;
			
		}
		for (int l70 = 0; (l70 < 3); l70 = (l70 + 1)) {
			fRec70[l70] = 0.0;
			
		}
		for (int l71 = 0; (l71 < 3); l71 = (l71 + 1)) {
			fRec71[l71] = 0.0;
			
		}
		for (int l72 = 0; (l72 < 3); l72 = (l72 + 1)) {
			fRec72[l72] = 0.0;
			
		}
		for (int l73 = 0; (l73 < 3); l73 = (l73 + 1)) {
			fRec73[l73] = 0.0;
			
		}
		for (int l74 = 0; (l74 < 3); l74 = (l74 + 1)) {
			fRec74[l74] = 0.0;
			
		}
		for (int l75 = 0; (l75 < 3); l75 = (l75 + 1)) {
			fRec75[l75] = 0.0;
			
		}
		for (int l76 = 0; (l76 < 3); l76 = (l76 + 1)) {
			fRec76[l76] = 0.0;
			
		}
		for (int l77 = 0; (l77 < 3); l77 = (l77 + 1)) {
			fRec77[l77] = 0.0;
			
		}
		for (int l78 = 0; (l78 < 3); l78 = (l78 + 1)) {
			fRec78[l78] = 0.0;
			
		}
		for (int l79 = 0; (l79 < 3); l79 = (l79 + 1)) {
			fRec79[l79] = 0.0;
			
		}
		for (int l80 = 0; (l80 < 3); l80 = (l80 + 1)) {
			fRec80[l80] = 0.0;
			
		}
		for (int l81 = 0; (l81 < 3); l81 = (l81 + 1)) {
			fRec81[l81] = 0.0;
			
		}
		for (int l82 = 0; (l82 < 3); l82 = (l82 + 1)) {
			fRec82[l82] = 0.0;
			
		}
		for (int l83 = 0; (l83 < 3); l83 = (l83 + 1)) {
			fRec83[l83] = 0.0;
			
		}
		for (int l84 = 0; (l84 < 3); l84 = (l84 + 1)) {
			fRec84[l84] = 0.0;
			
		}
		for (int l85 = 0; (l85 < 3); l85 = (l85 + 1)) {
			fRec85[l85] = 0.0;
			
		}
		for (int l86 = 0; (l86 < 3); l86 = (l86 + 1)) {
			fRec86[l86] = 0.0;
			
		}
		for (int l87 = 0; (l87 < 3); l87 = (l87 + 1)) {
			fRec87[l87] = 0.0;
			
		}
		for (int l88 = 0; (l88 < 3); l88 = (l88 + 1)) {
			fRec88[l88] = 0.0;
			
		}
		for (int l89 = 0; (l89 < 3); l89 = (l89 + 1)) {
			fRec89[l89] = 0.0;
			
		}
		for (int l90 = 0; (l90 < 3); l90 = (l90 + 1)) {
			fRec90[l90] = 0.0;
			
		}
		for (int l91 = 0; (l91 < 3); l91 = (l91 + 1)) {
			fRec91[l91] = 0.0;
			
		}
		for (int l92 = 0; (l92 < 3); l92 = (l92 + 1)) {
			fRec92[l92] = 0.0;
			
		}
		for (int l93 = 0; (l93 < 3); l93 = (l93 + 1)) {
			fRec93[l93] = 0.0;
			
		}
		for (int l94 = 0; (l94 < 3); l94 = (l94 + 1)) {
			fRec94[l94] = 0.0;
			
		}
		for (int l95 = 0; (l95 < 3); l95 = (l95 + 1)) {
			fRec95[l95] = 0.0;
			
		}
		for (int l96 = 0; (l96 < 3); l96 = (l96 + 1)) {
			fRec96[l96] = 0.0;
			
		}
		for (int l97 = 0; (l97 < 3); l97 = (l97 + 1)) {
			fRec97[l97] = 0.0;
			
		}
		for (int l98 = 0; (l98 < 3); l98 = (l98 + 1)) {
			fRec98[l98] = 0.0;
			
		}
		for (int l99 = 0; (l99 < 3); l99 = (l99 + 1)) {
			fRec99[l99] = 0.0;
			
		}
		for (int l100 = 0; (l100 < 3); l100 = (l100 + 1)) {
			fRec100[l100] = 0.0;
			
		}
		for (int l101 = 0; (l101 < 3); l101 = (l101 + 1)) {
			fRec101[l101] = 0.0;
			
		}
		for (int l102 = 0; (l102 < 3); l102 = (l102 + 1)) {
			fRec102[l102] = 0.0;
			
		}
		for (int l103 = 0; (l103 < 3); l103 = (l103 + 1)) {
			fRec103[l103] = 0.0;
			
		}
		for (int l104 = 0; (l104 < 3); l104 = (l104 + 1)) {
			fRec104[l104] = 0.0;
			
		}
		for (int l105 = 0; (l105 < 3); l105 = (l105 + 1)) {
			fRec105[l105] = 0.0;
			
		}
		for (int l106 = 0; (l106 < 3); l106 = (l106 + 1)) {
			fRec106[l106] = 0.0;
			
		}
		for (int l107 = 0; (l107 < 3); l107 = (l107 + 1)) {
			fRec107[l107] = 0.0;
			
		}
		for (int l108 = 0; (l108 < 3); l108 = (l108 + 1)) {
			fRec108[l108] = 0.0;
			
		}
		for (int l109 = 0; (l109 < 3); l109 = (l109 + 1)) {
			fRec109[l109] = 0.0;
			
		}
		for (int l110 = 0; (l110 < 3); l110 = (l110 + 1)) {
			fRec110[l110] = 0.0;
			
		}
		for (int l111 = 0; (l111 < 3); l111 = (l111 + 1)) {
			fRec111[l111] = 0.0;
			
		}
		for (int l112 = 0; (l112 < 3); l112 = (l112 + 1)) {
			fRec112[l112] = 0.0;
			
		}
		for (int l113 = 0; (l113 < 3); l113 = (l113 + 1)) {
			fRec113[l113] = 0.0;
			
		}
		for (int l114 = 0; (l114 < 3); l114 = (l114 + 1)) {
			fRec114[l114] = 0.0;
			
		}
		for (int l115 = 0; (l115 < 3); l115 = (l115 + 1)) {
			fRec115[l115] = 0.0;
			
		}
		for (int l116 = 0; (l116 < 3); l116 = (l116 + 1)) {
			fRec116[l116] = 0.0;
			
		}
		for (int l117 = 0; (l117 < 3); l117 = (l117 + 1)) {
			fRec117[l117] = 0.0;
			
		}
		for (int l118 = 0; (l118 < 3); l118 = (l118 + 1)) {
			fRec118[l118] = 0.0;
			
		}
		for (int l119 = 0; (l119 < 3); l119 = (l119 + 1)) {
			fRec119[l119] = 0.0;
			
		}
		for (int l120 = 0; (l120 < 3); l120 = (l120 + 1)) {
			fRec120[l120] = 0.0;
			
		}
		for (int l121 = 0; (l121 < 3); l121 = (l121 + 1)) {
			fRec121[l121] = 0.0;
			
		}
		for (int l122 = 0; (l122 < 3); l122 = (l122 + 1)) {
			fRec122[l122] = 0.0;
			
		}
		for (int l123 = 0; (l123 < 3); l123 = (l123 + 1)) {
			fRec123[l123] = 0.0;
			
		}
		for (int l124 = 0; (l124 < 3); l124 = (l124 + 1)) {
			fRec124[l124] = 0.0;
			
		}
		for (int l125 = 0; (l125 < 3); l125 = (l125 + 1)) {
			fRec125[l125] = 0.0;
			
		}
		for (int l126 = 0; (l126 < 3); l126 = (l126 + 1)) {
			fRec126[l126] = 0.0;
			
		}
		for (int l127 = 0; (l127 < 3); l127 = (l127 + 1)) {
			fRec127[l127] = 0.0;
			
		}
		for (int l128 = 0; (l128 < 3); l128 = (l128 + 1)) {
			fRec128[l128] = 0.0;
			
		}
		for (int l129 = 0; (l129 < 3); l129 = (l129 + 1)) {
			fRec129[l129] = 0.0;
			
		}
		for (int l130 = 0; (l130 < 3); l130 = (l130 + 1)) {
			fRec130[l130] = 0.0;
			
		}
		for (int l131 = 0; (l131 < 3); l131 = (l131 + 1)) {
			fRec131[l131] = 0.0;
			
		}
		for (int l132 = 0; (l132 < 3); l132 = (l132 + 1)) {
			fRec132[l132] = 0.0;
			
		}
		for (int l133 = 0; (l133 < 3); l133 = (l133 + 1)) {
			fRec133[l133] = 0.0;
			
		}
		for (int l134 = 0; (l134 < 3); l134 = (l134 + 1)) {
			fRec134[l134] = 0.0;
			
		}
		for (int l135 = 0; (l135 < 3); l135 = (l135 + 1)) {
			fRec135[l135] = 0.0;
			
		}
		for (int l136 = 0; (l136 < 3); l136 = (l136 + 1)) {
			fRec136[l136] = 0.0;
			
		}
		for (int l137 = 0; (l137 < 3); l137 = (l137 + 1)) {
			fRec137[l137] = 0.0;
			
		}
		for (int l138 = 0; (l138 < 3); l138 = (l138 + 1)) {
			fRec138[l138] = 0.0;
			
		}
		for (int l139 = 0; (l139 < 3); l139 = (l139 + 1)) {
			fRec139[l139] = 0.0;
			
		}
		for (int l140 = 0; (l140 < 3); l140 = (l140 + 1)) {
			fRec140[l140] = 0.0;
			
		}
		for (int l141 = 0; (l141 < 3); l141 = (l141 + 1)) {
			fRec141[l141] = 0.0;
			
		}
		for (int l142 = 0; (l142 < 3); l142 = (l142 + 1)) {
			fRec142[l142] = 0.0;
			
		}
		for (int l143 = 0; (l143 < 3); l143 = (l143 + 1)) {
			fRec143[l143] = 0.0;
			
		}
		for (int l144 = 0; (l144 < 3); l144 = (l144 + 1)) {
			fRec144[l144] = 0.0;
			
		}
		for (int l145 = 0; (l145 < 3); l145 = (l145 + 1)) {
			fRec145[l145] = 0.0;
			
		}
		for (int l146 = 0; (l146 < 3); l146 = (l146 + 1)) {
			fRec146[l146] = 0.0;
			
		}
		for (int l147 = 0; (l147 < 3); l147 = (l147 + 1)) {
			fRec147[l147] = 0.0;
			
		}
		for (int l148 = 0; (l148 < 3); l148 = (l148 + 1)) {
			fRec148[l148] = 0.0;
			
		}
		for (int l149 = 0; (l149 < 3); l149 = (l149 + 1)) {
			fRec149[l149] = 0.0;
			
		}
		for (int l150 = 0; (l150 < 3); l150 = (l150 + 1)) {
			fRec150[l150] = 0.0;
			
		}
		for (int l151 = 0; (l151 < 3); l151 = (l151 + 1)) {
			fRec151[l151] = 0.0;
			
		}
		for (int l152 = 0; (l152 < 3); l152 = (l152 + 1)) {
			fRec152[l152] = 0.0;
			
		}
		for (int l153 = 0; (l153 < 3); l153 = (l153 + 1)) {
			fRec153[l153] = 0.0;
			
		}
		for (int l154 = 0; (l154 < 3); l154 = (l154 + 1)) {
			fRec154[l154] = 0.0;
			
		}
		for (int l155 = 0; (l155 < 3); l155 = (l155 + 1)) {
			fRec155[l155] = 0.0;
			
		}
		for (int l156 = 0; (l156 < 3); l156 = (l156 + 1)) {
			fRec156[l156] = 0.0;
			
		}
		for (int l157 = 0; (l157 < 3); l157 = (l157 + 1)) {
			fRec157[l157] = 0.0;
			
		}
		for (int l158 = 0; (l158 < 3); l158 = (l158 + 1)) {
			fRec158[l158] = 0.0;
			
		}
		for (int l159 = 0; (l159 < 3); l159 = (l159 + 1)) {
			fRec159[l159] = 0.0;
			
		}
		for (int l160 = 0; (l160 < 3); l160 = (l160 + 1)) {
			fRec160[l160] = 0.0;
			
		}
		for (int l161 = 0; (l161 < 3); l161 = (l161 + 1)) {
			fRec161[l161] = 0.0;
			
		}
		for (int l162 = 0; (l162 < 3); l162 = (l162 + 1)) {
			fRec162[l162] = 0.0;
			
		}
		for (int l163 = 0; (l163 < 3); l163 = (l163 + 1)) {
			fRec163[l163] = 0.0;
			
		}
		for (int l164 = 0; (l164 < 3); l164 = (l164 + 1)) {
			fRec164[l164] = 0.0;
			
		}
		for (int l165 = 0; (l165 < 3); l165 = (l165 + 1)) {
			fRec165[l165] = 0.0;
			
		}
		for (int l166 = 0; (l166 < 3); l166 = (l166 + 1)) {
			fRec166[l166] = 0.0;
			
		}
		for (int l167 = 0; (l167 < 3); l167 = (l167 + 1)) {
			fRec167[l167] = 0.0;
			
		}
		for (int l168 = 0; (l168 < 3); l168 = (l168 + 1)) {
			fRec168[l168] = 0.0;
			
		}
		for (int l169 = 0; (l169 < 3); l169 = (l169 + 1)) {
			fRec169[l169] = 0.0;
			
		}
		for (int l170 = 0; (l170 < 3); l170 = (l170 + 1)) {
			fRec170[l170] = 0.0;
			
		}
		for (int l171 = 0; (l171 < 3); l171 = (l171 + 1)) {
			fRec171[l171] = 0.0;
			
		}
		for (int l172 = 0; (l172 < 3); l172 = (l172 + 1)) {
			fRec172[l172] = 0.0;
			
		}
		for (int l173 = 0; (l173 < 3); l173 = (l173 + 1)) {
			fRec173[l173] = 0.0;
			
		}
		for (int l174 = 0; (l174 < 3); l174 = (l174 + 1)) {
			fRec174[l174] = 0.0;
			
		}
		for (int l175 = 0; (l175 < 3); l175 = (l175 + 1)) {
			fRec175[l175] = 0.0;
			
		}
		for (int l176 = 0; (l176 < 3); l176 = (l176 + 1)) {
			fRec176[l176] = 0.0;
			
		}
		for (int l177 = 0; (l177 < 3); l177 = (l177 + 1)) {
			fRec177[l177] = 0.0;
			
		}
		for (int l178 = 0; (l178 < 3); l178 = (l178 + 1)) {
			fRec178[l178] = 0.0;
			
		}
		for (int l179 = 0; (l179 < 3); l179 = (l179 + 1)) {
			fRec179[l179] = 0.0;
			
		}
		for (int l180 = 0; (l180 < 3); l180 = (l180 + 1)) {
			fRec180[l180] = 0.0;
			
		}
		for (int l181 = 0; (l181 < 3); l181 = (l181 + 1)) {
			fRec181[l181] = 0.0;
			
		}
		for (int l182 = 0; (l182 < 3); l182 = (l182 + 1)) {
			fRec182[l182] = 0.0;
			
		}
		for (int l183 = 0; (l183 < 3); l183 = (l183 + 1)) {
			fRec183[l183] = 0.0;
			
		}
		for (int l184 = 0; (l184 < 3); l184 = (l184 + 1)) {
			fRec184[l184] = 0.0;
			
		}
		for (int l185 = 0; (l185 < 3); l185 = (l185 + 1)) {
			fRec185[l185] = 0.0;
			
		}
		for (int l186 = 0; (l186 < 3); l186 = (l186 + 1)) {
			fRec186[l186] = 0.0;
			
		}
		for (int l187 = 0; (l187 < 3); l187 = (l187 + 1)) {
			fRec187[l187] = 0.0;
			
		}
		for (int l188 = 0; (l188 < 3); l188 = (l188 + 1)) {
			fRec188[l188] = 0.0;
			
		}
		for (int l189 = 0; (l189 < 3); l189 = (l189 + 1)) {
			fRec189[l189] = 0.0;
			
		}
		for (int l190 = 0; (l190 < 3); l190 = (l190 + 1)) {
			fRec190[l190] = 0.0;
			
		}
		for (int l191 = 0; (l191 < 3); l191 = (l191 + 1)) {
			fRec191[l191] = 0.0;
			
		}
		for (int l192 = 0; (l192 < 3); l192 = (l192 + 1)) {
			fRec192[l192] = 0.0;
			
		}
		for (int l193 = 0; (l193 < 3); l193 = (l193 + 1)) {
			fRec193[l193] = 0.0;
			
		}
		for (int l194 = 0; (l194 < 3); l194 = (l194 + 1)) {
			fRec194[l194] = 0.0;
			
		}
		for (int l195 = 0; (l195 < 3); l195 = (l195 + 1)) {
			fRec195[l195] = 0.0;
			
		}
		for (int l196 = 0; (l196 < 3); l196 = (l196 + 1)) {
			fRec196[l196] = 0.0;
			
		}
		for (int l197 = 0; (l197 < 3); l197 = (l197 + 1)) {
			fRec197[l197] = 0.0;
			
		}
		for (int l198 = 0; (l198 < 3); l198 = (l198 + 1)) {
			fRec198[l198] = 0.0;
			
		}
		for (int l199 = 0; (l199 < 3); l199 = (l199 + 1)) {
			fRec199[l199] = 0.0;
			
		}
		for (int l200 = 0; (l200 < 3); l200 = (l200 + 1)) {
			fRec200[l200] = 0.0;
			
		}
		for (int l201 = 0; (l201 < 3); l201 = (l201 + 1)) {
			fRec201[l201] = 0.0;
			
		}
		for (int l202 = 0; (l202 < 3); l202 = (l202 + 1)) {
			fRec202[l202] = 0.0;
			
		}
		for (int l203 = 0; (l203 < 3); l203 = (l203 + 1)) {
			fRec203[l203] = 0.0;
			
		}
		for (int l204 = 0; (l204 < 3); l204 = (l204 + 1)) {
			fRec204[l204] = 0.0;
			
		}
		for (int l205 = 0; (l205 < 3); l205 = (l205 + 1)) {
			fRec205[l205] = 0.0;
			
		}
		for (int l206 = 0; (l206 < 3); l206 = (l206 + 1)) {
			fRec206[l206] = 0.0;
			
		}
		for (int l207 = 0; (l207 < 3); l207 = (l207 + 1)) {
			fRec207[l207] = 0.0;
			
		}
		for (int l208 = 0; (l208 < 3); l208 = (l208 + 1)) {
			fRec208[l208] = 0.0;
			
		}
		for (int l209 = 0; (l209 < 3); l209 = (l209 + 1)) {
			fRec209[l209] = 0.0;
			
		}
		for (int l210 = 0; (l210 < 3); l210 = (l210 + 1)) {
			fRec210[l210] = 0.0;
			
		}
		for (int l211 = 0; (l211 < 3); l211 = (l211 + 1)) {
			fRec211[l211] = 0.0;
			
		}
		for (int l212 = 0; (l212 < 3); l212 = (l212 + 1)) {
			fRec212[l212] = 0.0;
			
		}
		for (int l213 = 0; (l213 < 3); l213 = (l213 + 1)) {
			fRec213[l213] = 0.0;
			
		}
		for (int l214 = 0; (l214 < 3); l214 = (l214 + 1)) {
			fRec214[l214] = 0.0;
			
		}
		for (int l215 = 0; (l215 < 3); l215 = (l215 + 1)) {
			fRec215[l215] = 0.0;
			
		}
		for (int l216 = 0; (l216 < 3); l216 = (l216 + 1)) {
			fRec216[l216] = 0.0;
			
		}
		for (int l217 = 0; (l217 < 3); l217 = (l217 + 1)) {
			fRec217[l217] = 0.0;
			
		}
		for (int l218 = 0; (l218 < 3); l218 = (l218 + 1)) {
			fRec218[l218] = 0.0;
			
		}
		for (int l219 = 0; (l219 < 3); l219 = (l219 + 1)) {
			fRec219[l219] = 0.0;
			
		}
		for (int l220 = 0; (l220 < 3); l220 = (l220 + 1)) {
			fRec220[l220] = 0.0;
			
		}
		for (int l221 = 0; (l221 < 3); l221 = (l221 + 1)) {
			fRec221[l221] = 0.0;
			
		}
		for (int l222 = 0; (l222 < 3); l222 = (l222 + 1)) {
			fRec222[l222] = 0.0;
			
		}
		for (int l223 = 0; (l223 < 3); l223 = (l223 + 1)) {
			fRec223[l223] = 0.0;
			
		}
		for (int l224 = 0; (l224 < 3); l224 = (l224 + 1)) {
			fRec224[l224] = 0.0;
			
		}
		for (int l225 = 0; (l225 < 3); l225 = (l225 + 1)) {
			fRec225[l225] = 0.0;
			
		}
		for (int l226 = 0; (l226 < 3); l226 = (l226 + 1)) {
			fRec226[l226] = 0.0;
			
		}
		for (int l227 = 0; (l227 < 3); l227 = (l227 + 1)) {
			fRec227[l227] = 0.0;
			
		}
		for (int l228 = 0; (l228 < 3); l228 = (l228 + 1)) {
			fRec228[l228] = 0.0;
			
		}
		for (int l229 = 0; (l229 < 3); l229 = (l229 + 1)) {
			fRec229[l229] = 0.0;
			
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
		ui_interface->openVerticalBox("cabinetVoxTopBoostBass");
		ui_interface->declare(&fVslider0, "2", "");
		ui_interface->declare(&fVslider0, "style", "knob");
		ui_interface->addVerticalSlider("amount", &fVslider0, 1.0, 0.0, 1.0, 0.01);
		ui_interface->closeBox();
		
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = double(fVslider0);
		double fSlow1 = (1.0 - fSlow0);
		for (int i = 0; (i < count); i = (i + 1)) {
			double fTemp0 = double(input0[i]);
			double fTemp1 = (fSlow0 * fTemp0);
			fRec0[0] = (fTemp1 - ((fConst3 * fRec0[1]) + (fConst4 * fRec0[2])));
			fRec1[0] = (fTemp1 - ((fConst5 * fRec1[1]) + (fConst4 * fRec1[2])));
			fRec2[0] = (fTemp1 - ((fConst7 * fRec2[1]) + (fConst8 * fRec2[2])));
			fRec3[0] = (fTemp1 - ((fConst10 * fRec3[1]) + (fConst11 * fRec3[2])));
			fRec4[0] = (fTemp1 - ((fConst13 * fRec4[1]) + (fConst14 * fRec4[2])));
			fRec5[0] = (fTemp1 - ((fConst17 * fRec5[1]) + (fConst18 * fRec5[2])));
			fRec6[0] = (fTemp1 - ((fConst21 * fRec6[1]) + (fConst22 * fRec6[2])));
			fRec7[0] = (fTemp1 - ((fConst25 * fRec7[1]) + (fConst26 * fRec7[2])));
			fRec8[0] = (fTemp1 - ((fConst27 * fRec8[1]) + (fConst18 * fRec8[2])));
			fRec9[0] = (fTemp1 - ((fConst30 * fRec9[1]) + (fConst31 * fRec9[2])));
			fRec10[0] = (fTemp1 - ((fConst33 * fRec10[1]) + (fConst34 * fRec10[2])));
			fRec11[0] = (fTemp1 - ((fConst36 * fRec11[1]) + (fConst37 * fRec11[2])));
			fRec12[0] = (fTemp1 - ((fConst40 * fRec12[1]) + (fConst41 * fRec12[2])));
			fRec13[0] = (fTemp1 - ((fConst43 * fRec13[1]) + (fConst44 * fRec13[2])));
			fRec14[0] = (fTemp1 - ((fConst47 * fRec14[1]) + (fConst48 * fRec14[2])));
			fRec15[0] = (fTemp1 - ((fConst49 * fRec15[1]) + (fConst48 * fRec15[2])));
			fRec16[0] = (fTemp1 - ((fConst52 * fRec16[1]) + (fConst53 * fRec16[2])));
			fRec17[0] = (fTemp1 - ((fConst56 * fRec17[1]) + (fConst57 * fRec17[2])));
			fRec18[0] = (fTemp1 - ((fConst60 * fRec18[1]) + (fConst61 * fRec18[2])));
			fRec19[0] = (fTemp1 - ((fConst62 * fRec19[1]) + (fConst61 * fRec19[2])));
			fRec20[0] = (fTemp1 - ((fConst65 * fRec20[1]) + (fConst66 * fRec20[2])));
			fRec21[0] = (fTemp1 - ((fConst67 * fRec21[1]) + (fConst66 * fRec21[2])));
			fRec22[0] = (fTemp1 - ((fConst68 * fRec22[1]) + (fConst66 * fRec22[2])));
			fRec23[0] = (fTemp1 - ((fConst71 * fRec23[1]) + (fConst72 * fRec23[2])));
			fRec24[0] = (fTemp1 - ((fConst75 * fRec24[1]) + (fConst76 * fRec24[2])));
			fRec25[0] = (fTemp1 - ((fConst78 * fRec25[1]) + (fConst79 * fRec25[2])));
			fRec26[0] = (fTemp1 - ((fConst80 * fRec26[1]) + (fConst72 * fRec26[2])));
			fRec27[0] = (fTemp1 - ((fConst83 * fRec27[1]) + (fConst84 * fRec27[2])));
			fRec28[0] = (fTemp1 - ((fConst86 * fRec28[1]) + (fConst87 * fRec28[2])));
			fRec29[0] = (fTemp1 - ((fConst90 * fRec29[1]) + (fConst91 * fRec29[2])));
			fRec30[0] = (fTemp1 - ((fConst93 * fRec30[1]) + (fConst94 * fRec30[2])));
			fRec31[0] = (fTemp1 - ((fConst97 * fRec31[1]) + (fConst98 * fRec31[2])));
			fRec32[0] = (fTemp1 - ((fConst101 * fRec32[1]) + (fConst102 * fRec32[2])));
			fRec33[0] = (fTemp1 - ((fConst104 * fRec33[1]) + (fConst105 * fRec33[2])));
			fRec34[0] = (fTemp1 - ((fConst106 * fRec34[1]) + (fConst98 * fRec34[2])));
			fRec35[0] = (fTemp1 - ((fConst107 * fRec35[1]) + (fConst98 * fRec35[2])));
			fRec36[0] = (fTemp1 - ((fConst108 * fRec36[1]) + (fConst98 * fRec36[2])));
			fRec37[0] = (fTemp1 - ((fConst109 * fRec37[1]) + (fConst102 * fRec37[2])));
			fRec38[0] = (fTemp1 - ((fConst111 * fRec38[1]) + (fConst112 * fRec38[2])));
			fRec39[0] = (fTemp1 - ((fConst115 * fRec39[1]) + (fConst116 * fRec39[2])));
			fRec40[0] = (fTemp1 - ((fConst118 * fRec40[1]) + (fConst119 * fRec40[2])));
			fRec41[0] = (fTemp1 - ((fConst121 * fRec41[1]) + (fConst122 * fRec41[2])));
			fRec42[0] = (fTemp1 - ((fConst123 * fRec42[1]) + (fConst22 * fRec42[2])));
			fRec43[0] = (fTemp1 - ((fConst124 * fRec43[1]) + (fConst76 * fRec43[2])));
			fRec44[0] = (fTemp1 - ((fConst126 * fRec44[1]) + (fConst127 * fRec44[2])));
			fRec45[0] = (fTemp1 - ((fConst130 * fRec45[1]) + (fConst131 * fRec45[2])));
			fRec46[0] = (fTemp1 - ((fConst134 * fRec46[1]) + (fConst135 * fRec46[2])));
			fRec47[0] = (fTemp1 - ((fConst136 * fRec47[1]) + (fConst135 * fRec47[2])));
			fRec48[0] = (fTemp1 - ((fConst138 * fRec48[1]) + (fConst139 * fRec48[2])));
			fRec49[0] = (fTemp1 - ((fConst141 * fRec49[1]) + (fConst142 * fRec49[2])));
			fRec50[0] = (fTemp1 - ((fConst143 * fRec50[1]) + (fConst57 * fRec50[2])));
			fRec51[0] = (fTemp1 - ((fConst144 * fRec51[1]) + (fConst53 * fRec51[2])));
			fRec52[0] = (fTemp1 - ((fConst145 * fRec52[1]) + (fConst116 * fRec52[2])));
			fRec53[0] = (fTemp1 - ((fConst147 * fRec53[1]) + (fConst148 * fRec53[2])));
			fRec54[0] = (fTemp1 - ((fConst151 * fRec54[1]) + (fConst152 * fRec54[2])));
			fRec55[0] = (fTemp1 - ((fConst154 * fRec55[1]) + (fConst155 * fRec55[2])));
			fRec56[0] = (fTemp1 - ((fConst158 * fRec56[1]) + (fConst159 * fRec56[2])));
			fRec57[0] = (fTemp1 - ((fConst160 * fRec57[1]) + (fConst98 * fRec57[2])));
			fRec58[0] = (fTemp1 - ((fConst161 * fRec58[1]) + (fConst98 * fRec58[2])));
			fRec59[0] = (fTemp1 - ((fConst164 * fRec59[1]) + (fConst165 * fRec59[2])));
			fRec60[0] = (fTemp1 - ((fConst167 * fRec60[1]) + (fConst168 * fRec60[2])));
			fRec61[0] = (fTemp1 - ((fConst169 * fRec61[1]) + (fConst84 * fRec61[2])));
			fRec62[0] = (fTemp1 - ((fConst170 * fRec62[1]) + (fConst57 * fRec62[2])));
			fRec63[0] = (fTemp1 - ((fConst172 * fRec63[1]) + (fConst173 * fRec63[2])));
			fRec64[0] = (fTemp1 - ((fConst176 * fRec64[1]) + (fConst177 * fRec64[2])));
			fRec65[0] = (fTemp1 - ((fConst178 * fRec65[1]) + (fConst177 * fRec65[2])));
			fRec66[0] = (fTemp1 - ((fConst180 * fRec66[1]) + (fConst181 * fRec66[2])));
			fRec67[0] = (fTemp1 - ((fConst183 * fRec67[1]) + (fConst184 * fRec67[2])));
			fRec68[0] = (fTemp1 - ((fConst185 * fRec68[1]) + (fConst177 * fRec68[2])));
			fRec69[0] = (fTemp1 - ((fConst187 * fRec69[1]) + (fConst188 * fRec69[2])));
			fRec70[0] = (fTemp1 - ((fConst190 * fRec70[1]) + (fConst191 * fRec70[2])));
			fRec71[0] = (fTemp1 - ((fConst192 * fRec71[1]) + (fConst41 * fRec71[2])));
			fRec72[0] = (fTemp1 - ((fConst194 * fRec72[1]) + (fConst195 * fRec72[2])));
			fRec73[0] = (fTemp1 - ((fConst198 * fRec73[1]) + (fConst199 * fRec73[2])));
			fRec74[0] = (fTemp1 - ((fConst201 * fRec74[1]) + (fConst202 * fRec74[2])));
			fRec75[0] = (fTemp1 - ((fConst204 * fRec75[1]) + (fConst205 * fRec75[2])));
			fRec76[0] = (fTemp1 - ((fConst207 * fRec76[1]) + (fConst208 * fRec76[2])));
			fRec77[0] = (fTemp1 - ((fConst211 * fRec77[1]) + (fConst212 * fRec77[2])));
			fRec78[0] = (fTemp1 - ((fConst215 * fRec78[1]) + (fConst216 * fRec78[2])));
			fRec79[0] = (fTemp1 - ((fConst218 * fRec79[1]) + (fConst219 * fRec79[2])));
			fRec80[0] = (fTemp1 - ((fConst220 * fRec80[1]) + (fConst199 * fRec80[2])));
			fRec81[0] = (fTemp1 - ((fConst221 * fRec81[1]) + (fConst26 * fRec81[2])));
			fRec82[0] = (fTemp1 - ((fConst224 * fRec82[1]) + (fConst225 * fRec82[2])));
			fRec83[0] = (fTemp1 - ((fConst226 * fRec83[1]) + (fConst91 * fRec83[2])));
			fRec84[0] = (fTemp1 - ((fConst228 * fRec84[1]) + (fConst229 * fRec84[2])));
			fRec85[0] = (fTemp1 - ((fConst232 * fRec85[1]) + (fConst233 * fRec85[2])));
			fRec86[0] = (fTemp1 - ((fConst236 * fRec86[1]) + (fConst237 * fRec86[2])));
			fRec87[0] = (fTemp1 - ((fConst238 * fRec87[1]) + (fConst31 * fRec87[2])));
			fRec88[0] = (fTemp1 - ((fConst240 * fRec88[1]) + (fConst241 * fRec88[2])));
			fRec89[0] = (fTemp1 - ((fConst242 * fRec89[1]) + (fConst216 * fRec89[2])));
			fRec90[0] = (fTemp1 - ((fConst243 * fRec90[1]) + (fConst216 * fRec90[2])));
			fRec91[0] = (fTemp1 - ((fConst244 * fRec91[1]) + (fConst131 * fRec91[2])));
			fRec92[0] = (fTemp1 - ((fConst246 * fRec92[1]) + (fConst247 * fRec92[2])));
			fRec93[0] = (fTemp1 - ((fConst249 * fRec93[1]) + (fConst250 * fRec93[2])));
			fRec94[0] = (fTemp1 - ((fConst252 * fRec94[1]) + (fConst253 * fRec94[2])));
			fRec95[0] = (fTemp1 - ((fConst256 * fRec95[1]) + (fConst257 * fRec95[2])));
			fRec96[0] = (fTemp1 - ((fConst260 * fRec96[1]) + (fConst261 * fRec96[2])));
			fRec97[0] = (fTemp1 - ((fConst264 * fRec97[1]) + (fConst265 * fRec97[2])));
			fRec98[0] = (fTemp1 - ((fConst267 * fRec98[1]) + (fConst268 * fRec98[2])));
			fRec99[0] = (fTemp1 - ((fConst271 * fRec99[1]) + (fConst272 * fRec99[2])));
			fRec100[0] = (fTemp1 - ((fConst274 * fRec100[1]) + (fConst275 * fRec100[2])));
			fRec101[0] = (fTemp1 - ((fConst277 * fRec101[1]) + (fConst278 * fRec101[2])));
			fRec102[0] = (fTemp1 - ((fConst281 * fRec102[1]) + (fConst282 * fRec102[2])));
			fRec103[0] = (fTemp1 - ((fConst285 * fRec103[1]) + (fConst286 * fRec103[2])));
			fRec104[0] = (fTemp1 - ((fConst289 * fRec104[1]) + (fConst290 * fRec104[2])));
			fRec105[0] = (fTemp1 - ((fConst293 * fRec105[1]) + (fConst294 * fRec105[2])));
			fRec106[0] = (fTemp1 - ((fConst296 * fRec106[1]) + (fConst297 * fRec106[2])));
			fRec107[0] = (fTemp1 - ((fConst299 * fRec107[1]) + (fConst300 * fRec107[2])));
			fRec108[0] = (fTemp1 - ((fConst302 * fRec108[1]) + (fConst303 * fRec108[2])));
			fRec109[0] = (fTemp1 - ((fConst305 * fRec109[1]) + (fConst306 * fRec109[2])));
			fRec110[0] = (fTemp1 - ((fConst309 * fRec110[1]) + (fConst310 * fRec110[2])));
			fRec111[0] = (fTemp1 - ((fConst311 * fRec111[1]) + (fConst294 * fRec111[2])));
			fRec112[0] = (fTemp1 - ((fConst313 * fRec112[1]) + (fConst314 * fRec112[2])));
			fRec113[0] = (fTemp1 - ((fConst316 * fRec113[1]) + (fConst317 * fRec113[2])));
			fRec114[0] = (fTemp1 - ((fConst318 * fRec114[1]) + (fConst257 * fRec114[2])));
			fRec115[0] = (fTemp1 - ((fConst319 * fRec115[1]) + (fConst257 * fRec115[2])));
			fRec116[0] = (fTemp1 - ((fConst320 * fRec116[1]) + (fConst257 * fRec116[2])));
			fRec117[0] = (fTemp1 - ((fConst321 * fRec117[1]) + (fConst257 * fRec117[2])));
			fRec118[0] = (fTemp1 - ((fConst324 * fRec118[1]) + (fConst325 * fRec118[2])));
			fRec119[0] = (fTemp1 - ((fConst327 * fRec119[1]) + (fConst328 * fRec119[2])));
			fRec120[0] = (fTemp1 - ((fConst329 * fRec120[1]) + (fConst212 * fRec120[2])));
			fRec121[0] = (fTemp1 - ((fConst330 * fRec121[1]) + (fConst212 * fRec121[2])));
			fRec122[0] = (fTemp1 - ((fConst331 * fRec122[1]) + (fConst325 * fRec122[2])));
			fRec123[0] = (fTemp1 - ((fConst333 * fRec123[1]) + (fConst334 * fRec123[2])));
			fRec124[0] = (fTemp1 - ((fConst337 * fRec124[1]) + (fConst338 * fRec124[2])));
			fRec125[0] = (fTemp1 - ((fConst339 * fRec125[1]) + (fConst286 * fRec125[2])));
			fRec126[0] = (fTemp1 - ((fConst342 * fRec126[1]) + (fConst343 * fRec126[2])));
			fRec127[0] = (fTemp1 - ((fConst345 * fRec127[1]) + (fConst346 * fRec127[2])));
			fRec128[0] = (fTemp1 - ((fConst348 * fRec128[1]) + (fConst349 * fRec128[2])));
			fRec129[0] = (fTemp1 - ((fConst351 * fRec129[1]) + (fConst352 * fRec129[2])));
			fRec130[0] = (fTemp1 - ((fConst353 * fRec130[1]) + (fConst257 * fRec130[2])));
			fRec131[0] = (fTemp1 - ((fConst354 * fRec131[1]) + (fConst325 * fRec131[2])));
			fRec132[0] = (fTemp1 - ((fConst355 * fRec132[1]) + (fConst325 * fRec132[2])));
			fRec133[0] = (fTemp1 - ((fConst356 * fRec133[1]) + (fConst257 * fRec133[2])));
			fRec134[0] = (fTemp1 - ((fConst357 * fRec134[1]) + (fConst212 * fRec134[2])));
			fRec135[0] = (fTemp1 - ((fConst359 * fRec135[1]) + (fConst360 * fRec135[2])));
			fRec136[0] = (fTemp1 - ((fConst363 * fRec136[1]) + (fConst364 * fRec136[2])));
			fRec137[0] = (fTemp1 - ((fConst365 * fRec137[1]) + (fConst364 * fRec137[2])));
			fRec138[0] = (fTemp1 - ((fConst366 * fRec138[1]) + (fConst364 * fRec138[2])));
			fRec139[0] = (fTemp1 - ((fConst368 * fRec139[1]) + (fConst369 * fRec139[2])));
			fRec140[0] = (fTemp1 - ((fConst371 * fRec140[1]) + (fConst372 * fRec140[2])));
			fRec141[0] = (fTemp1 - ((fConst374 * fRec141[1]) + (fConst375 * fRec141[2])));
			fRec142[0] = (fTemp1 - ((fConst377 * fRec142[1]) + (fConst378 * fRec142[2])));
			fRec143[0] = (fTemp1 - ((fConst379 * fRec143[1]) + (fConst338 * fRec143[2])));
			fRec144[0] = (fTemp1 - ((fConst381 * fRec144[1]) + (fConst382 * fRec144[2])));
			fRec145[0] = (fTemp1 - ((fConst384 * fRec145[1]) + (fConst385 * fRec145[2])));
			fRec146[0] = (fTemp1 - ((fConst387 * fRec146[1]) + (fConst388 * fRec146[2])));
			fRec147[0] = (fTemp1 - ((fConst390 * fRec147[1]) + (fConst391 * fRec147[2])));
			fRec148[0] = (fTemp1 - ((fConst392 * fRec148[1]) + (fConst310 * fRec148[2])));
			fRec149[0] = (fTemp1 - ((fConst394 * fRec149[1]) + (fConst395 * fRec149[2])));
			fRec150[0] = (fTemp1 - ((fConst397 * fRec150[1]) + (fConst398 * fRec150[2])));
			fRec151[0] = (fTemp1 - ((fConst399 * fRec151[1]) + (fConst290 * fRec151[2])));
			fRec152[0] = (fTemp1 - ((fConst400 * fRec152[1]) + (fConst265 * fRec152[2])));
			fRec153[0] = (fTemp1 - ((fConst403 * fRec153[1]) + (fConst404 * fRec153[2])));
			fRec154[0] = (fTemp1 - ((fConst405 * fRec154[1]) + (fConst404 * fRec154[2])));
			fRec155[0] = (fTemp1 - ((fConst407 * fRec155[1]) + (fConst408 * fRec155[2])));
			fRec156[0] = (fTemp1 - ((fConst409 * fRec156[1]) + (fConst282 * fRec156[2])));
			fRec157[0] = (fTemp1 - ((fConst410 * fRec157[1]) + (fConst286 * fRec157[2])));
			fRec158[0] = (fTemp1 - ((fConst411 * fRec158[1]) + (fConst343 * fRec158[2])));
			fRec159[0] = (fTemp1 - ((fConst412 * fRec159[1]) + (fConst343 * fRec159[2])));
			fRec160[0] = (fTemp1 - ((fConst415 * fRec160[1]) + (fConst416 * fRec160[2])));
			fRec161[0] = (fTemp1 - ((fConst417 * fRec161[1]) + (fConst225 * fRec161[2])));
			fRec162[0] = (fTemp1 - ((fConst420 * fRec162[1]) + (fConst421 * fRec162[2])));
			fRec163[0] = (fTemp1 - ((fConst422 * fRec163[1]) + (fConst421 * fRec163[2])));
			fRec164[0] = (fTemp1 - ((fConst424 * fRec164[1]) + (fConst425 * fRec164[2])));
			fRec165[0] = (fTemp1 - ((fConst426 * fRec165[1]) + (fConst152 * fRec165[2])));
			fRec166[0] = (fTemp1 - ((fConst428 * fRec166[1]) + (fConst429 * fRec166[2])));
			fRec167[0] = (fTemp1 - ((fConst431 * fRec167[1]) + (fConst432 * fRec167[2])));
			fRec168[0] = (fTemp1 - ((fConst433 * fRec168[1]) + (fConst165 * fRec168[2])));
			fRec169[0] = (fTemp1 - ((fConst435 * fRec169[1]) + (fConst436 * fRec169[2])));
			fRec170[0] = (fTemp1 - ((fConst437 * fRec170[1]) + (fConst22 * fRec170[2])));
			fRec171[0] = (fTemp1 - ((fConst439 * fRec171[1]) + (fConst440 * fRec171[2])));
			fRec172[0] = (fTemp1 - ((fConst442 * fRec172[1]) + (fConst443 * fRec172[2])));
			fRec173[0] = (fTemp1 - ((fConst445 * fRec173[1]) + (fConst446 * fRec173[2])));
			fRec174[0] = (fTemp1 - ((fConst448 * fRec174[1]) + (fConst449 * fRec174[2])));
			fRec175[0] = (fTemp1 - ((fConst452 * fRec175[1]) + (fConst453 * fRec175[2])));
			fRec176[0] = (fTemp1 - ((fConst454 * fRec176[1]) + (fConst453 * fRec176[2])));
			fRec177[0] = (fTemp1 - ((fConst455 * fRec177[1]) + (fConst453 * fRec177[2])));
			fRec178[0] = (fTemp1 - ((fConst457 * fRec178[1]) + (fConst458 * fRec178[2])));
			fRec179[0] = (fTemp1 - ((fConst461 * fRec179[1]) + (fConst462 * fRec179[2])));
			fRec180[0] = (fTemp1 - ((fConst464 * fRec180[1]) + (fConst465 * fRec180[2])));
			fRec181[0] = (fTemp1 - ((fConst467 * fRec181[1]) + (fConst468 * fRec181[2])));
			fRec182[0] = (fTemp1 - ((fConst470 * fRec182[1]) + (fConst471 * fRec182[2])));
			fRec183[0] = (fTemp1 - ((fConst472 * fRec183[1]) + (fConst261 * fRec183[2])));
			fRec184[0] = (fTemp1 - ((fConst474 * fRec184[1]) + (fConst475 * fRec184[2])));
			fRec185[0] = (fTemp1 - ((fConst478 * fRec185[1]) + (fConst479 * fRec185[2])));
			fRec186[0] = (fTemp1 - ((fConst481 * fRec186[1]) + (fConst482 * fRec186[2])));
			fRec187[0] = (fTemp1 - ((fConst485 * fRec187[1]) + (fConst486 * fRec187[2])));
			fRec188[0] = (fTemp1 - ((fConst487 * fRec188[1]) + (fConst486 * fRec188[2])));
			fRec189[0] = (fTemp1 - ((fConst489 * fRec189[1]) + (fConst490 * fRec189[2])));
			fRec190[0] = (fTemp1 - ((fConst493 * fRec190[1]) + (fConst494 * fRec190[2])));
			fRec191[0] = (fTemp1 - ((fConst495 * fRec191[1]) + (fConst494 * fRec191[2])));
			fRec192[0] = (fTemp1 - ((fConst496 * fRec192[1]) + (fConst272 * fRec192[2])));
			fRec193[0] = (fTemp1 - ((fConst497 * fRec193[1]) + (fConst237 * fRec193[2])));
			fRec194[0] = (fTemp1 - ((fConst498 * fRec194[1]) + (fConst272 * fRec194[2])));
			fRec195[0] = (fTemp1 - ((fConst499 * fRec195[1]) + (fConst272 * fRec195[2])));
			fRec196[0] = (fTemp1 - ((fConst501 * fRec196[1]) + (fConst502 * fRec196[2])));
			fRec197[0] = (fTemp1 - ((fConst503 * fRec197[1]) + (fConst479 * fRec197[2])));
			fRec198[0] = (fTemp1 - ((fConst504 * fRec198[1]) + (fConst26 * fRec198[2])));
			fRec199[0] = (fTemp1 - ((fConst506 * fRec199[1]) + (fConst507 * fRec199[2])));
			fRec200[0] = (fTemp1 - ((fConst510 * fRec200[1]) + (fConst511 * fRec200[2])));
			fRec201[0] = (fTemp1 - ((fConst512 * fRec201[1]) + (fConst511 * fRec201[2])));
			fRec202[0] = (fTemp1 - ((fConst514 * fRec202[1]) + (fConst515 * fRec202[2])));
			fRec203[0] = (fTemp1 - ((fConst518 * fRec203[1]) + (fConst519 * fRec203[2])));
			fRec204[0] = (fTemp1 - ((fConst521 * fRec204[1]) + (fConst522 * fRec204[2])));
			fRec205[0] = (fTemp1 - ((fConst523 * fRec205[1]) + (fConst519 * fRec205[2])));
			fRec206[0] = (fTemp1 - ((fConst524 * fRec206[1]) + (fConst519 * fRec206[2])));
			fRec207[0] = (fTemp1 - ((fConst525 * fRec207[1]) + (fConst519 * fRec207[2])));
			fRec208[0] = (fTemp1 - ((fConst526 * fRec208[1]) + (fConst519 * fRec208[2])));
			fRec209[0] = (fTemp1 - ((fConst527 * fRec209[1]) + (fConst519 * fRec209[2])));
			fRec210[0] = (fTemp1 - ((fConst528 * fRec210[1]) + (fConst519 * fRec210[2])));
			fRec211[0] = (fTemp1 - ((fConst529 * fRec211[1]) + (fConst519 * fRec211[2])));
			fRec212[0] = (fTemp1 - ((fConst530 * fRec212[1]) + (fConst343 * fRec212[2])));
			fRec213[0] = (fTemp1 - ((fConst531 * fRec213[1]) + (fConst343 * fRec213[2])));
			fRec214[0] = (fTemp1 - ((fConst532 * fRec214[1]) + (fConst343 * fRec214[2])));
			fRec215[0] = (fTemp1 - ((fConst534 * fRec215[1]) + (fConst535 * fRec215[2])));
			fRec216[0] = (fTemp1 - ((fConst536 * fRec216[1]) + (fConst462 * fRec216[2])));
			fRec217[0] = (fTemp1 - ((fConst537 * fRec217[1]) + (fConst159 * fRec217[2])));
			fRec218[0] = (fTemp1 - ((fConst540 * fRec218[1]) + (fConst541 * fRec218[2])));
			fRec219[0] = (fTemp1 - ((fConst542 * fRec219[1]) + (fConst541 * fRec219[2])));
			fRec220[0] = (fTemp1 - ((fConst543 * fRec220[1]) + (fConst159 * fRec220[2])));
			fRec221[0] = (fTemp1 - ((fConst544 * fRec221[1]) + (fConst159 * fRec221[2])));
			fRec222[0] = (fTemp1 - ((fConst545 * fRec222[1]) + (fConst159 * fRec222[2])));
			fRec223[0] = (fTemp1 - ((fConst546 * fRec223[1]) + (fConst462 * fRec223[2])));
			fRec224[0] = (fTemp1 - ((fConst547 * fRec224[1]) + (fConst462 * fRec224[2])));
			fRec225[0] = (fTemp1 - ((fConst548 * fRec225[1]) + (fConst462 * fRec225[2])));
			fRec226[0] = (fTemp1 - ((fConst549 * fRec226[1]) + (fConst416 * fRec226[2])));
			fRec227[0] = (fTemp1 - ((fConst550 * fRec227[1]) + (fConst462 * fRec227[2])));
			fRec228[0] = (fTemp1 - ((fConst551 * fRec228[1]) + (fConst233 * fRec228[2])));
			fRec229[0] = (fTemp1 - ((fConst552 * fRec229[1]) + (fConst416 * fRec229[2])));
			output0[i] = FAUSTFLOAT((fTemp0 * (fSlow1 + (fSlow0 * ((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((0.165635490394 * (fRec0[0] - fRec0[2])) + (0.16466086906300001 * (fRec1[0] - fRec1[2]))) + (0.19891871321400001 * (fRec2[0] - fRec2[2]))) + (0.19273821496599999 * (fRec3[0] - fRec3[2]))) + (0.50139777233899996 * (fRec4[0] - fRec4[2]))) + (0.47355663470699999 * (fRec5[0] - fRec5[2]))) + (0.55058484939999996 * (fRec6[0] - fRec6[2]))) + (0.64547212290599998 * (fRec7[0] - fRec7[2]))) + (0.486609993884 * (fRec8[0] - fRec8[2]))) + (0.35721816613399998 * (fRec9[0] - fRec9[2]))) + (0.488001601206 * (fRec10[0] - fRec10[2]))) + (0.48846218741000003 * (fRec11[0] - fRec11[2]))) + (0.59084765219099999 * (fRec12[0] - fRec12[2]))) + (0.51075243844100005 * (fRec13[0] - fRec13[2]))) + (0.43580975842899999 * (fRec14[0] - fRec14[2]))) + (0.43776571431299999 * (fRec15[0] - fRec15[2]))) + (0.41286330328300003 * (fRec16[0] - fRec16[2]))) + (0.424424392122 * (fRec17[0] - fRec17[2]))) + (0.313433345458 * (fRec18[0] - fRec18[2]))) + (0.31370825608000003 * (fRec19[0] - fRec19[2]))) + (0.44264112409 * (fRec20[0] - fRec20[2]))) + (0.44225335970700003 * (fRec21[0] - fRec21[2]))) + (0.459718698506 * (fRec22[0] - fRec22[2]))) + (0.62817611825399999 * (fRec23[0] - fRec23[2]))) + (0.64451630871300003 * (fRec24[0] - fRec24[2]))) + (0.53070575568800005 * (fRec25[0] - fRec25[2]))) + (0.63753698393299996 * (fRec26[0] - fRec26[2]))) + (0.46763033124499997 * (fRec27[0] - fRec27[2]))) + (0.61078645650499996 * (fRec28[0] - fRec28[2]))) + (0.74294846772400003 * (fRec29[0] - fRec29[2]))) + (0.71601324795300003 * (fRec30[0] - fRec30[2]))) + (0.83685992486600003 * (fRec31[0] - fRec31[2]))) + (0.86896857399799998 * (fRec32[0] - fRec32[2]))) + (0.83562462012700001 * (fRec33[0] - fRec33[2]))) + (0.83668946421299994 * (fRec34[0] - fRec34[2]))) + (0.84864895396399997 * (fRec35[0] - fRec35[2]))) + (0.86185832035999999 * (fRec36[0] - fRec36[2]))) + (0.86952171909099996 * (fRec37[0] - fRec37[2]))) + (0.59927830823999995 * (fRec38[0] - fRec38[2]))) + (0.50761295022300001 * (fRec39[0] - fRec39[2]))) + (0.57911022599399997 * (fRec40[0] - fRec40[2]))) + (fRec41[0] - fRec41[2])) + (0.80399379492900003 * (fRec42[0] - fRec42[2]))) + (0.771712035706 * (fRec43[0] - fRec43[2]))) + (0.67295431591199995 * (fRec44[0] - fRec44[2]))) + (0.83493490496699996 * (fRec45[0] - fRec45[2]))) + (0.74755808749999997 * (fRec46[0] - fRec46[2]))) + (0.73380332827899997 * (fRec47[0] - fRec47[2]))) + (0.53907376378100003 * (fRec48[0] - fRec48[2]))) + (0.59593543175100006 * (fRec49[0] - fRec49[2]))) + (0.429716845726 * (fRec50[0] - fRec50[2]))) + (0.40239039103500002 * (fRec51[0] - fRec51[2]))) + (0.51673509622500002 * (fRec52[0] - fRec52[2]))) + (0.59465629264700004 * (fRec53[0] - fRec53[2]))) + (0.652799509118 * (fRec54[0] - fRec54[2]))) + (0.88263129312499999 * (fRec55[0] - fRec55[2]))) + (0.93564602875500003 * (fRec56[0] - fRec56[2]))) + (0.89661363367500002 * (fRec57[0] - fRec57[2]))) + (0.89407698581499995 * (fRec58[0] - fRec58[2]))) + (0.79471592383199996 * (fRec59[0] - fRec59[2]))) + (0.519177232637 * (fRec60[0] - fRec60[2]))) + (0.466216317032 * (fRec61[0] - fRec61[2]))) + (0.422780193704 * (fRec62[0] - fRec62[2]))) + (0.37295555311799999 * (fRec63[0] - fRec63[2]))) + (0.49122678937800002 * (fRec64[0] - fRec64[2]))) + (0.60164460596900005 * (fRec65[0] - fRec65[2]))) + (0.42840171024200002 * (fRec66[0] - fRec66[2]))) + (0.48244723091800001 * (fRec67[0] - fRec67[2]))) + (0.38695797214299998 * (fRec68[0] - fRec68[2]))) + (0.214926080204 * (fRec69[0] - fRec69[2]))) + (0.20616238730299999 * (fRec70[0] - fRec70[2]))) + (0.30478804298500001 * (fRec71[0] - fRec71[2]))) + (0.27549206881999999 * (fRec72[0] - fRec72[2]))) + (0.21777239639900001 * (fRec73[0] - fRec73[2]))) + (0.111527796382 * (fRec74[0] - fRec74[2]))) + (0.093611715843199994 * (fRec75[0] - fRec75[2]))) + (0.077810175144000002 * (fRec76[0] - fRec76[2]))) + (0.039633978484100003 * (fRec77[0] - fRec77[2]))) + (0.054636447390099999 * (fRec78[0] - fRec78[2]))) + (0.0649433105959 * (fRec79[0] - fRec79[2]))) + (0.13059256617699999 * (fRec80[0] - fRec80[2]))) + (0.13761034729300001 * (fRec81[0] - fRec81[2]))) + (0.098040798104000002 * (fRec82[0] - fRec82[2]))) + (0.13272142262 * (fRec83[0] - fRec83[2]))) + (0.113693463974 * (fRec84[0] - fRec84[2]))) + (0.11959446841099999 * (fRec85[0] - fRec85[2]))) + (0.077015899429299997 * (fRec86[0] - fRec86[2]))) + (0.075111987931400004 * (fRec87[0] - fRec87[2]))) + (0.097466282164399995 * (fRec88[0] - fRec88[2]))) + (0.054463582585200003 * (fRec89[0] - fRec89[2]))) + (0.054706813774800002 * (fRec90[0] - fRec90[2]))) + (0.057776630363900003 * (fRec91[0] - fRec91[2]))) + (0.0492453946021 * (fRec92[0] - fRec92[2]))) + (0.048650269920200002 * (fRec93[0] - fRec93[2]))) + (0.053227469464399997 * (fRec94[0] - fRec94[2]))) + (0.035232611929599998 * (fRec95[0] - fRec95[2]))) + (0.057546496679199997 * (fRec96[0] - fRec96[2]))) + (0.057330489915500001 * (fRec97[0] - fRec97[2]))) + (0.065822929443 * (fRec98[0] - fRec98[2]))) + (0.062835485220100004 * (fRec99[0] - fRec99[2]))) + (0.075274309415099994 * (fRec100[0] - fRec100[2]))) + (0.071476323804799999 * (fRec101[0] - fRec101[2]))) + (0.069337289352200002 * (fRec102[0] - fRec102[2]))) + (0.069201016401100005 * (fRec103[0] - fRec103[2]))) + (0.0586186210155 * (fRec104[0] - fRec104[2]))) + (0.051303405623899997 * (fRec105[0] - fRec105[2]))) + (0.047371668672099999 * (fRec106[0] - fRec106[2]))) + (0.049005442192000002 * (fRec107[0] - fRec107[2]))) + (0.046883225182700002 * (fRec108[0] - fRec108[2]))) + (0.049165795704000002 * (fRec109[0] - fRec109[2]))) + (0.054115048103499999 * (fRec110[0] - fRec110[2]))) + (0.050877245516400001 * (fRec111[0] - fRec111[2]))) + (0.046181153941299999 * (fRec112[0] - fRec112[2]))) + (0.045531004016500003 * (fRec113[0] - fRec113[2]))) + (0.035687816671499999 * (fRec114[0] - fRec114[2]))) + (0.036995210171199999 * (fRec115[0] - fRec115[2]))) + (0.034979195157000001 * (fRec116[0] - fRec116[2]))) + (0.034940974641800002 * (fRec117[0] - fRec117[2]))) + (0.0411681444095 * (fRec118[0] - fRec118[2]))) + (0.047455082275599997 * (fRec119[0] - fRec119[2]))) + (0.039206693803500003 * (fRec120[0] - fRec120[2]))) + (0.038949464827799998 * (fRec121[0] - fRec121[2]))) + (0.042275820944600001 * (fRec122[0] - fRec122[2]))) + (0.044711044108400003 * (fRec123[0] - fRec123[2]))) + (0.063470442535800004 * (fRec124[0] - fRec124[2]))) + (0.057917946916200003 * (fRec125[0] - fRec125[2]))) + (0.059517347939900003 * (fRec126[0] - fRec126[2]))) + (0.062790031144800001 * (fRec127[0] - fRec127[2]))) + (0.050036864510499997 * (fRec128[0] - fRec128[2]))) + (0.049955243117400003 * (fRec129[0] - fRec129[2]))) + (0.036879233317 * (fRec130[0] - fRec130[2]))) + (0.042439561775299998 * (fRec131[0] - fRec131[2]))) + (0.042022450690100001 * (fRec132[0] - fRec132[2]))) + (0.037057582303700001 * (fRec133[0] - fRec133[2]))) + (0.038962892653099997 * (fRec134[0] - fRec134[2]))) + (0.043117153059300001 * (fRec135[0] - fRec135[2]))) + (0.031166433160599999 * (fRec136[0] - fRec136[2]))) + (0.031297721090299997 * (fRec137[0] - fRec137[2]))) + (0.031283569189799999 * (fRec138[0] - fRec138[2]))) + (0.023174459639 * (fRec139[0] - fRec139[2]))) + (0.0167554594013 * (fRec140[0] - fRec140[2]))) + (0.016995587828400001 * (fRec141[0] - fRec141[2]))) + (0.029003591227100001 * (fRec142[0] - fRec142[2]))) + (0.021738320082700002 * (fRec143[0] - fRec143[2]))) + (0.022048495796799999 * (fRec144[0] - fRec144[2]))) + (0.0231599970651 * (fRec145[0] - fRec145[2]))) + (0.017729704345799999 * (fRec146[0] - fRec146[2]))) + (0.026182110826599998 * (fRec147[0] - fRec147[2]))) + (0.022501816152899999 * (fRec148[0] - fRec148[2]))) + (0.031397100249999997 * (fRec149[0] - fRec149[2]))) + (0.0327149840762 * (fRec150[0] - fRec150[2]))) + (0.032851161754199998 * (fRec151[0] - fRec151[2]))) + (0.032686553317499999 * (fRec152[0] - fRec152[2]))) + (0.039932951137899998 * (fRec153[0] - fRec153[2]))) + (0.040702614129200003 * (fRec154[0] - fRec154[2]))) + (0.0449735115002 * (fRec155[0] - fRec155[2]))) + (0.049282872166199997 * (fRec156[0] - fRec156[2]))) + (0.048041938354000002 * (fRec157[0] - fRec157[2]))) + (0.050924002880799998 * (fRec158[0] - fRec158[2]))) + (0.052471339916600003 * (fRec159[0] - fRec159[2]))) + (0.0553806186428 * (fRec160[0] - fRec160[2]))) + (0.050054359866299997 * (fRec161[0] - fRec161[2]))) + (0.028576183172700002 * (fRec162[0] - fRec162[2]))) + (0.029182883966400001 * (fRec163[0] - fRec163[2]))) + (0.029893104142299998 * (fRec164[0] - fRec164[2]))) + (0.029387365186900001 * (fRec165[0] - fRec165[2]))) + (0.023935090761100002 * (fRec166[0] - fRec166[2]))) + (0.025290099493100002 * (fRec167[0] - fRec167[2]))) + (0.030151773949 * (fRec168[0] - fRec168[2]))) + (0.027663533024 * (fRec169[0] - fRec169[2]))) + (0.034291968975800002 * (fRec170[0] - fRec170[2]))) + (0.029752230437299999 * (fRec171[0] - fRec171[2]))) + (0.023404995560099999 * (fRec172[0] - fRec172[2]))) + (0.021287957614699999 * (fRec173[0] - fRec173[2]))) + (0.020670888236199999 * (fRec174[0] - fRec174[2]))) + (0.020287400371800001 * (fRec175[0] - fRec175[2]))) + (0.020202025112700001 * (fRec176[0] - fRec176[2]))) + (0.020215622681700001 * (fRec177[0] - fRec177[2]))) + (0.023724612586100001 * (fRec178[0] - fRec178[2]))) + (0.0228966918991 * (fRec179[0] - fRec179[2]))) + (0.022313028556200001 * (fRec180[0] - fRec180[2]))) + (0.025632794155599999 * (fRec181[0] - fRec181[2]))) + (0.0199608582587 * (fRec182[0] - fRec182[2]))) + (0.0143419433609 * (fRec183[0] - fRec183[2]))) + (0.0144685628477 * (fRec184[0] - fRec184[2]))) + (0.0125122935523 * (fRec185[0] - fRec185[2]))) + (0.0130193749747 * (fRec186[0] - fRec186[2]))) + (0.016212346115000002 * (fRec187[0] - fRec187[2]))) + (0.0162712665444 * (fRec188[0] - fRec188[2]))) + (0.0118072383081 * (fRec189[0] - fRec189[2]))) + (0.0141341070732 * (fRec190[0] - fRec190[2]))) + (0.014153178685599999 * (fRec191[0] - fRec191[2]))) + (0.0135619704464 * (fRec192[0] - fRec192[2]))) + (0.0134918059003 * (fRec193[0] - fRec193[2]))) + (0.0138886095035 * (fRec194[0] - fRec194[2]))) + (0.013845872181800001 * (fRec195[0] - fRec195[2]))) + (0.0120407578433 * (fRec196[0] - fRec196[2]))) + (0.0126552367981 * (fRec197[0] - fRec197[2]))) + (0.018761025362799999 * (fRec198[0] - fRec198[2]))) + (0.011168412320099999 * (fRec199[0] - fRec199[2]))) + (0.0102609435048 * (fRec200[0] - fRec200[2]))) + (0.0102454688762 * (fRec201[0] - fRec201[2]))) + (0.0101025529679 * (fRec202[0] - fRec202[2]))) + (0.010206777616199999 * (fRec203[0] - fRec203[2]))) + (0.0108033179872 * (fRec204[0] - fRec204[2]))) + (0.010458965461300001 * (fRec205[0] - fRec205[2]))) + (0.010377060775799999 * (fRec206[0] - fRec206[2]))) + (0.010275304616599999 * (fRec207[0] - fRec207[2]))) + (0.0102915841141 * (fRec208[0] - fRec208[2]))) + (0.0104134664304 * (fRec209[0] - fRec209[2]))) + (0.0105227431987 * (fRec210[0] - fRec210[2]))) + (0.0102863887225 * (fRec211[0] - fRec211[2]))) + (0.010379448725899999 * (fRec212[0] - fRec212[2]))) + (0.010466067337700001 * (fRec213[0] - fRec213[2]))) + (0.0103196331675 * (fRec214[0] - fRec214[2]))) + (0.010778827351300001 * (fRec215[0] - fRec215[2]))) + (0.011940782152399999 * (fRec216[0] - fRec216[2]))) + (0.0140319382175 * (fRec217[0] - fRec217[2]))) + (0.0144217886454 * (fRec218[0] - fRec218[2]))) + (0.014527940657100001 * (fRec219[0] - fRec219[2]))) + (0.014263942254 * (fRec220[0] - fRec220[2]))) + (0.013936592982499999 * (fRec221[0] - fRec221[2]))) + (0.0139011260235 * (fRec222[0] - fRec222[2]))) + (0.0119490609966 * (fRec223[0] - fRec223[2]))) + (0.011858882453 * (fRec224[0] - fRec224[2]))) + (0.012047499651499999 * (fRec225[0] - fRec225[2]))) + (0.0123300625074 * (fRec226[0] - fRec226[2]))) + (0.011963251386799999 * (fRec227[0] - fRec227[2]))) + (0.0129282133115 * (fRec228[0] - fRec228[2]))) + (0.012279811024299999 * (fRec229[0] - fRec229[2])))))));
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fRec20[2] = fRec20[1];
			fRec20[1] = fRec20[0];
			fRec21[2] = fRec21[1];
			fRec21[1] = fRec21[0];
			fRec22[2] = fRec22[1];
			fRec22[1] = fRec22[0];
			fRec23[2] = fRec23[1];
			fRec23[1] = fRec23[0];
			fRec24[2] = fRec24[1];
			fRec24[1] = fRec24[0];
			fRec25[2] = fRec25[1];
			fRec25[1] = fRec25[0];
			fRec26[2] = fRec26[1];
			fRec26[1] = fRec26[0];
			fRec27[2] = fRec27[1];
			fRec27[1] = fRec27[0];
			fRec28[2] = fRec28[1];
			fRec28[1] = fRec28[0];
			fRec29[2] = fRec29[1];
			fRec29[1] = fRec29[0];
			fRec30[2] = fRec30[1];
			fRec30[1] = fRec30[0];
			fRec31[2] = fRec31[1];
			fRec31[1] = fRec31[0];
			fRec32[2] = fRec32[1];
			fRec32[1] = fRec32[0];
			fRec33[2] = fRec33[1];
			fRec33[1] = fRec33[0];
			fRec34[2] = fRec34[1];
			fRec34[1] = fRec34[0];
			fRec35[2] = fRec35[1];
			fRec35[1] = fRec35[0];
			fRec36[2] = fRec36[1];
			fRec36[1] = fRec36[0];
			fRec37[2] = fRec37[1];
			fRec37[1] = fRec37[0];
			fRec38[2] = fRec38[1];
			fRec38[1] = fRec38[0];
			fRec39[2] = fRec39[1];
			fRec39[1] = fRec39[0];
			fRec40[2] = fRec40[1];
			fRec40[1] = fRec40[0];
			fRec41[2] = fRec41[1];
			fRec41[1] = fRec41[0];
			fRec42[2] = fRec42[1];
			fRec42[1] = fRec42[0];
			fRec43[2] = fRec43[1];
			fRec43[1] = fRec43[0];
			fRec44[2] = fRec44[1];
			fRec44[1] = fRec44[0];
			fRec45[2] = fRec45[1];
			fRec45[1] = fRec45[0];
			fRec46[2] = fRec46[1];
			fRec46[1] = fRec46[0];
			fRec47[2] = fRec47[1];
			fRec47[1] = fRec47[0];
			fRec48[2] = fRec48[1];
			fRec48[1] = fRec48[0];
			fRec49[2] = fRec49[1];
			fRec49[1] = fRec49[0];
			fRec50[2] = fRec50[1];
			fRec50[1] = fRec50[0];
			fRec51[2] = fRec51[1];
			fRec51[1] = fRec51[0];
			fRec52[2] = fRec52[1];
			fRec52[1] = fRec52[0];
			fRec53[2] = fRec53[1];
			fRec53[1] = fRec53[0];
			fRec54[2] = fRec54[1];
			fRec54[1] = fRec54[0];
			fRec55[2] = fRec55[1];
			fRec55[1] = fRec55[0];
			fRec56[2] = fRec56[1];
			fRec56[1] = fRec56[0];
			fRec57[2] = fRec57[1];
			fRec57[1] = fRec57[0];
			fRec58[2] = fRec58[1];
			fRec58[1] = fRec58[0];
			fRec59[2] = fRec59[1];
			fRec59[1] = fRec59[0];
			fRec60[2] = fRec60[1];
			fRec60[1] = fRec60[0];
			fRec61[2] = fRec61[1];
			fRec61[1] = fRec61[0];
			fRec62[2] = fRec62[1];
			fRec62[1] = fRec62[0];
			fRec63[2] = fRec63[1];
			fRec63[1] = fRec63[0];
			fRec64[2] = fRec64[1];
			fRec64[1] = fRec64[0];
			fRec65[2] = fRec65[1];
			fRec65[1] = fRec65[0];
			fRec66[2] = fRec66[1];
			fRec66[1] = fRec66[0];
			fRec67[2] = fRec67[1];
			fRec67[1] = fRec67[0];
			fRec68[2] = fRec68[1];
			fRec68[1] = fRec68[0];
			fRec69[2] = fRec69[1];
			fRec69[1] = fRec69[0];
			fRec70[2] = fRec70[1];
			fRec70[1] = fRec70[0];
			fRec71[2] = fRec71[1];
			fRec71[1] = fRec71[0];
			fRec72[2] = fRec72[1];
			fRec72[1] = fRec72[0];
			fRec73[2] = fRec73[1];
			fRec73[1] = fRec73[0];
			fRec74[2] = fRec74[1];
			fRec74[1] = fRec74[0];
			fRec75[2] = fRec75[1];
			fRec75[1] = fRec75[0];
			fRec76[2] = fRec76[1];
			fRec76[1] = fRec76[0];
			fRec77[2] = fRec77[1];
			fRec77[1] = fRec77[0];
			fRec78[2] = fRec78[1];
			fRec78[1] = fRec78[0];
			fRec79[2] = fRec79[1];
			fRec79[1] = fRec79[0];
			fRec80[2] = fRec80[1];
			fRec80[1] = fRec80[0];
			fRec81[2] = fRec81[1];
			fRec81[1] = fRec81[0];
			fRec82[2] = fRec82[1];
			fRec82[1] = fRec82[0];
			fRec83[2] = fRec83[1];
			fRec83[1] = fRec83[0];
			fRec84[2] = fRec84[1];
			fRec84[1] = fRec84[0];
			fRec85[2] = fRec85[1];
			fRec85[1] = fRec85[0];
			fRec86[2] = fRec86[1];
			fRec86[1] = fRec86[0];
			fRec87[2] = fRec87[1];
			fRec87[1] = fRec87[0];
			fRec88[2] = fRec88[1];
			fRec88[1] = fRec88[0];
			fRec89[2] = fRec89[1];
			fRec89[1] = fRec89[0];
			fRec90[2] = fRec90[1];
			fRec90[1] = fRec90[0];
			fRec91[2] = fRec91[1];
			fRec91[1] = fRec91[0];
			fRec92[2] = fRec92[1];
			fRec92[1] = fRec92[0];
			fRec93[2] = fRec93[1];
			fRec93[1] = fRec93[0];
			fRec94[2] = fRec94[1];
			fRec94[1] = fRec94[0];
			fRec95[2] = fRec95[1];
			fRec95[1] = fRec95[0];
			fRec96[2] = fRec96[1];
			fRec96[1] = fRec96[0];
			fRec97[2] = fRec97[1];
			fRec97[1] = fRec97[0];
			fRec98[2] = fRec98[1];
			fRec98[1] = fRec98[0];
			fRec99[2] = fRec99[1];
			fRec99[1] = fRec99[0];
			fRec100[2] = fRec100[1];
			fRec100[1] = fRec100[0];
			fRec101[2] = fRec101[1];
			fRec101[1] = fRec101[0];
			fRec102[2] = fRec102[1];
			fRec102[1] = fRec102[0];
			fRec103[2] = fRec103[1];
			fRec103[1] = fRec103[0];
			fRec104[2] = fRec104[1];
			fRec104[1] = fRec104[0];
			fRec105[2] = fRec105[1];
			fRec105[1] = fRec105[0];
			fRec106[2] = fRec106[1];
			fRec106[1] = fRec106[0];
			fRec107[2] = fRec107[1];
			fRec107[1] = fRec107[0];
			fRec108[2] = fRec108[1];
			fRec108[1] = fRec108[0];
			fRec109[2] = fRec109[1];
			fRec109[1] = fRec109[0];
			fRec110[2] = fRec110[1];
			fRec110[1] = fRec110[0];
			fRec111[2] = fRec111[1];
			fRec111[1] = fRec111[0];
			fRec112[2] = fRec112[1];
			fRec112[1] = fRec112[0];
			fRec113[2] = fRec113[1];
			fRec113[1] = fRec113[0];
			fRec114[2] = fRec114[1];
			fRec114[1] = fRec114[0];
			fRec115[2] = fRec115[1];
			fRec115[1] = fRec115[0];
			fRec116[2] = fRec116[1];
			fRec116[1] = fRec116[0];
			fRec117[2] = fRec117[1];
			fRec117[1] = fRec117[0];
			fRec118[2] = fRec118[1];
			fRec118[1] = fRec118[0];
			fRec119[2] = fRec119[1];
			fRec119[1] = fRec119[0];
			fRec120[2] = fRec120[1];
			fRec120[1] = fRec120[0];
			fRec121[2] = fRec121[1];
			fRec121[1] = fRec121[0];
			fRec122[2] = fRec122[1];
			fRec122[1] = fRec122[0];
			fRec123[2] = fRec123[1];
			fRec123[1] = fRec123[0];
			fRec124[2] = fRec124[1];
			fRec124[1] = fRec124[0];
			fRec125[2] = fRec125[1];
			fRec125[1] = fRec125[0];
			fRec126[2] = fRec126[1];
			fRec126[1] = fRec126[0];
			fRec127[2] = fRec127[1];
			fRec127[1] = fRec127[0];
			fRec128[2] = fRec128[1];
			fRec128[1] = fRec128[0];
			fRec129[2] = fRec129[1];
			fRec129[1] = fRec129[0];
			fRec130[2] = fRec130[1];
			fRec130[1] = fRec130[0];
			fRec131[2] = fRec131[1];
			fRec131[1] = fRec131[0];
			fRec132[2] = fRec132[1];
			fRec132[1] = fRec132[0];
			fRec133[2] = fRec133[1];
			fRec133[1] = fRec133[0];
			fRec134[2] = fRec134[1];
			fRec134[1] = fRec134[0];
			fRec135[2] = fRec135[1];
			fRec135[1] = fRec135[0];
			fRec136[2] = fRec136[1];
			fRec136[1] = fRec136[0];
			fRec137[2] = fRec137[1];
			fRec137[1] = fRec137[0];
			fRec138[2] = fRec138[1];
			fRec138[1] = fRec138[0];
			fRec139[2] = fRec139[1];
			fRec139[1] = fRec139[0];
			fRec140[2] = fRec140[1];
			fRec140[1] = fRec140[0];
			fRec141[2] = fRec141[1];
			fRec141[1] = fRec141[0];
			fRec142[2] = fRec142[1];
			fRec142[1] = fRec142[0];
			fRec143[2] = fRec143[1];
			fRec143[1] = fRec143[0];
			fRec144[2] = fRec144[1];
			fRec144[1] = fRec144[0];
			fRec145[2] = fRec145[1];
			fRec145[1] = fRec145[0];
			fRec146[2] = fRec146[1];
			fRec146[1] = fRec146[0];
			fRec147[2] = fRec147[1];
			fRec147[1] = fRec147[0];
			fRec148[2] = fRec148[1];
			fRec148[1] = fRec148[0];
			fRec149[2] = fRec149[1];
			fRec149[1] = fRec149[0];
			fRec150[2] = fRec150[1];
			fRec150[1] = fRec150[0];
			fRec151[2] = fRec151[1];
			fRec151[1] = fRec151[0];
			fRec152[2] = fRec152[1];
			fRec152[1] = fRec152[0];
			fRec153[2] = fRec153[1];
			fRec153[1] = fRec153[0];
			fRec154[2] = fRec154[1];
			fRec154[1] = fRec154[0];
			fRec155[2] = fRec155[1];
			fRec155[1] = fRec155[0];
			fRec156[2] = fRec156[1];
			fRec156[1] = fRec156[0];
			fRec157[2] = fRec157[1];
			fRec157[1] = fRec157[0];
			fRec158[2] = fRec158[1];
			fRec158[1] = fRec158[0];
			fRec159[2] = fRec159[1];
			fRec159[1] = fRec159[0];
			fRec160[2] = fRec160[1];
			fRec160[1] = fRec160[0];
			fRec161[2] = fRec161[1];
			fRec161[1] = fRec161[0];
			fRec162[2] = fRec162[1];
			fRec162[1] = fRec162[0];
			fRec163[2] = fRec163[1];
			fRec163[1] = fRec163[0];
			fRec164[2] = fRec164[1];
			fRec164[1] = fRec164[0];
			fRec165[2] = fRec165[1];
			fRec165[1] = fRec165[0];
			fRec166[2] = fRec166[1];
			fRec166[1] = fRec166[0];
			fRec167[2] = fRec167[1];
			fRec167[1] = fRec167[0];
			fRec168[2] = fRec168[1];
			fRec168[1] = fRec168[0];
			fRec169[2] = fRec169[1];
			fRec169[1] = fRec169[0];
			fRec170[2] = fRec170[1];
			fRec170[1] = fRec170[0];
			fRec171[2] = fRec171[1];
			fRec171[1] = fRec171[0];
			fRec172[2] = fRec172[1];
			fRec172[1] = fRec172[0];
			fRec173[2] = fRec173[1];
			fRec173[1] = fRec173[0];
			fRec174[2] = fRec174[1];
			fRec174[1] = fRec174[0];
			fRec175[2] = fRec175[1];
			fRec175[1] = fRec175[0];
			fRec176[2] = fRec176[1];
			fRec176[1] = fRec176[0];
			fRec177[2] = fRec177[1];
			fRec177[1] = fRec177[0];
			fRec178[2] = fRec178[1];
			fRec178[1] = fRec178[0];
			fRec179[2] = fRec179[1];
			fRec179[1] = fRec179[0];
			fRec180[2] = fRec180[1];
			fRec180[1] = fRec180[0];
			fRec181[2] = fRec181[1];
			fRec181[1] = fRec181[0];
			fRec182[2] = fRec182[1];
			fRec182[1] = fRec182[0];
			fRec183[2] = fRec183[1];
			fRec183[1] = fRec183[0];
			fRec184[2] = fRec184[1];
			fRec184[1] = fRec184[0];
			fRec185[2] = fRec185[1];
			fRec185[1] = fRec185[0];
			fRec186[2] = fRec186[1];
			fRec186[1] = fRec186[0];
			fRec187[2] = fRec187[1];
			fRec187[1] = fRec187[0];
			fRec188[2] = fRec188[1];
			fRec188[1] = fRec188[0];
			fRec189[2] = fRec189[1];
			fRec189[1] = fRec189[0];
			fRec190[2] = fRec190[1];
			fRec190[1] = fRec190[0];
			fRec191[2] = fRec191[1];
			fRec191[1] = fRec191[0];
			fRec192[2] = fRec192[1];
			fRec192[1] = fRec192[0];
			fRec193[2] = fRec193[1];
			fRec193[1] = fRec193[0];
			fRec194[2] = fRec194[1];
			fRec194[1] = fRec194[0];
			fRec195[2] = fRec195[1];
			fRec195[1] = fRec195[0];
			fRec196[2] = fRec196[1];
			fRec196[1] = fRec196[0];
			fRec197[2] = fRec197[1];
			fRec197[1] = fRec197[0];
			fRec198[2] = fRec198[1];
			fRec198[1] = fRec198[0];
			fRec199[2] = fRec199[1];
			fRec199[1] = fRec199[0];
			fRec200[2] = fRec200[1];
			fRec200[1] = fRec200[0];
			fRec201[2] = fRec201[1];
			fRec201[1] = fRec201[0];
			fRec202[2] = fRec202[1];
			fRec202[1] = fRec202[0];
			fRec203[2] = fRec203[1];
			fRec203[1] = fRec203[0];
			fRec204[2] = fRec204[1];
			fRec204[1] = fRec204[0];
			fRec205[2] = fRec205[1];
			fRec205[1] = fRec205[0];
			fRec206[2] = fRec206[1];
			fRec206[1] = fRec206[0];
			fRec207[2] = fRec207[1];
			fRec207[1] = fRec207[0];
			fRec208[2] = fRec208[1];
			fRec208[1] = fRec208[0];
			fRec209[2] = fRec209[1];
			fRec209[1] = fRec209[0];
			fRec210[2] = fRec210[1];
			fRec210[1] = fRec210[0];
			fRec211[2] = fRec211[1];
			fRec211[1] = fRec211[0];
			fRec212[2] = fRec212[1];
			fRec212[1] = fRec212[0];
			fRec213[2] = fRec213[1];
			fRec213[1] = fRec213[0];
			fRec214[2] = fRec214[1];
			fRec214[1] = fRec214[0];
			fRec215[2] = fRec215[1];
			fRec215[1] = fRec215[0];
			fRec216[2] = fRec216[1];
			fRec216[1] = fRec216[0];
			fRec217[2] = fRec217[1];
			fRec217[1] = fRec217[0];
			fRec218[2] = fRec218[1];
			fRec218[1] = fRec218[0];
			fRec219[2] = fRec219[1];
			fRec219[1] = fRec219[0];
			fRec220[2] = fRec220[1];
			fRec220[1] = fRec220[0];
			fRec221[2] = fRec221[1];
			fRec221[1] = fRec221[0];
			fRec222[2] = fRec222[1];
			fRec222[1] = fRec222[0];
			fRec223[2] = fRec223[1];
			fRec223[1] = fRec223[0];
			fRec224[2] = fRec224[1];
			fRec224[1] = fRec224[0];
			fRec225[2] = fRec225[1];
			fRec225[1] = fRec225[0];
			fRec226[2] = fRec226[1];
			fRec226[1] = fRec226[0];
			fRec227[2] = fRec227[1];
			fRec227[1] = fRec227[0];
			fRec228[2] = fRec228[1];
			fRec228[1] = fRec228[0];
			fRec229[2] = fRec229[1];
			fRec229[1] = fRec229[0];
			
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
            LinearValueConverter(umin, umax, log(std::max<double>(DBL_MIN, fmin)), log(std::max<double>(DBL_MIN, fmax)))
        {}

        virtual double ui2faust(double x) 	{ return exp(LinearValueConverter::ui2faust(x)); }
        virtual double faust2ui(double x)	{ return LinearValueConverter::faust2ui(log(std::max<double>(x, DBL_MIN))); }

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

        virtual double ui2faust(double x) { return log(LinearValueConverter::ui2faust(x)); }
        virtual double faust2ui(double x) { return LinearValueConverter::faust2ui(exp(x)); }

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
        nvoices = atoi(numVoices.c_str());
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
            return pow(2.0,(v/16383.0*4-2)/12);
        }

        int bend2wheel(float v)
        {
            return (int)((12*log(v)/log(2)+2)/4*16383);
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
#include <math.h>
#include <float.h>
#include <algorithm>
#include <ostream>
#include <sstream>
#include <vector>
#include <limits.h>

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

inline FAUSTFLOAT STR2REAL(const std::string& s) { return (strtod(s.c_str(), NULL)); }

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
            fDSPSize = atoi(fMetadatas["size"].c_str());
            fMetadatas.erase("size");
        } else {
            fDSPSize = -1;
        }
         
        if (fMetadatas.find("inputs") != fMetadatas.end()) {
            fNumInputs = atoi(fMetadatas["inputs"].c_str());
            fMetadatas.erase("inputs");
        } else {
            fNumInputs = -1;
        }
        
        if (fMetadatas.find("outputs") != fMetadatas.end()) {
            fNumOutputs = atoi(fMetadatas["outputs"].c_str());
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
                    fPathInputTable[(*it)->address] = make_pair(atoi((*it)->index.c_str()), &fInControl[counterIn]);
                }
                fInControl[counterIn] = STR2REAL((*it)->init);
                counterIn++;
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                if ((*it)->address != "") {
                    fPathOutputTable[(*it)->address] = make_pair(atoi((*it)->index.c_str()), &fOutControl[counterOut]);
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
    return 440.0 * pow(2.0, (note-69.0)/12.0);
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

    dsp_voice(dsp* dsp):decorator_dsp(dsp)
    {
        dsp->buildUserInterface(this);
        fNote = kFreeVoice;
        fLevel = FAUSTFLOAT(0);
        fDate = 0;
        fTrigger = false;
        extractPaths(fGatePath, fFreqPath, fGainPath);
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
            FAUSTFLOAT** inputs_slice = (FAUSTFLOAT**)alloca(getNumInputs() * sizeof(FAUSTFLOAT*));
            for (int chan = 0; chan < getNumInputs(); chan++) {
                inputs_slice[chan] = &(inputs[chan][offset]);
            }

            FAUSTFLOAT** outputs_slice = (FAUSTFLOAT**)alloca(getNumOutputs() * sizeof(FAUSTFLOAT*));
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                outputs_slice[chan] = &(outputs[chan][offset]);
            }

            compute(slice, inputs_slice, outputs_slice);
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
        
        string name = string((s)->s_name);
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
