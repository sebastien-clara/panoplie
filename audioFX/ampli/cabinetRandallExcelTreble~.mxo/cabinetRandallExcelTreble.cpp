/* ------------------------------------------------------------
name: "cabinetRandallExcelTreble"
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
	double fRec0[3];
	double fConst4;
	double fConst5;
	double fConst6;
	double fRec1[3];
	double fConst7;
	double fConst8;
	double fConst9;
	double fConst10;
	double fRec2[3];
	double fConst11;
	double fConst12;
	double fConst13;
	double fConst14;
	double fRec3[3];
	double fConst15;
	double fRec4[3];
	double fConst16;
	double fConst17;
	double fConst18;
	double fConst19;
	double fRec5[3];
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
	double fConst28;
	double fConst29;
	double fRec8[3];
	double fConst30;
	double fConst31;
	double fConst32;
	double fConst33;
	double fRec9[3];
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
	double fRec13[3];
	double fConst43;
	double fRec14[3];
	double fConst44;
	double fConst45;
	double fConst46;
	double fRec15[3];
	double fConst47;
	double fConst48;
	double fConst49;
	double fConst50;
	double fRec16[3];
	double fConst51;
	double fConst52;
	double fConst53;
	double fConst54;
	double fRec17[3];
	double fConst55;
	double fRec18[3];
	double fConst56;
	double fConst57;
	double fConst58;
	double fConst59;
	double fRec19[3];
	double fConst60;
	double fConst61;
	double fConst62;
	double fConst63;
	double fRec20[3];
	double fConst64;
	double fRec21[3];
	double fConst65;
	double fConst66;
	double fConst67;
	double fRec22[3];
	double fConst68;
	double fConst69;
	double fConst70;
	double fConst71;
	double fRec23[3];
	double fConst72;
	double fConst73;
	double fConst74;
	double fConst75;
	double fRec24[3];
	double fConst76;
	double fConst77;
	double fConst78;
	double fRec25[3];
	double fConst79;
	double fRec26[3];
	double fConst80;
	double fConst81;
	double fConst82;
	double fRec27[3];
	double fConst83;
	double fConst84;
	double fConst85;
	double fRec28[3];
	double fConst86;
	double fConst87;
	double fConst88;
	double fConst89;
	double fRec29[3];
	double fConst90;
	double fConst91;
	double fConst92;
	double fRec30[3];
	double fConst93;
	double fConst94;
	double fConst95;
	double fRec31[3];
	double fConst96;
	double fConst97;
	double fConst98;
	double fConst99;
	double fRec32[3];
	double fConst100;
	double fConst101;
	double fConst102;
	double fConst103;
	double fRec33[3];
	double fConst104;
	double fConst105;
	double fConst106;
	double fRec34[3];
	double fConst107;
	double fConst108;
	double fConst109;
	double fRec35[3];
	double fConst110;
	double fConst111;
	double fConst112;
	double fConst113;
	double fRec36[3];
	double fConst114;
	double fRec37[3];
	double fConst115;
	double fConst116;
	double fConst117;
	double fRec38[3];
	double fConst118;
	double fConst119;
	double fConst120;
	double fRec39[3];
	double fConst121;
	double fConst122;
	double fConst123;
	double fConst124;
	double fRec40[3];
	double fConst125;
	double fConst126;
	double fConst127;
	double fRec41[3];
	double fConst128;
	double fConst129;
	double fConst130;
	double fRec42[3];
	double fConst131;
	double fRec43[3];
	double fConst132;
	double fRec44[3];
	double fConst133;
	double fConst134;
	double fConst135;
	double fRec45[3];
	double fConst136;
	double fRec46[3];
	double fConst137;
	double fRec47[3];
	double fConst138;
	double fRec48[3];
	double fConst139;
	double fConst140;
	double fConst141;
	double fConst142;
	double fRec49[3];
	double fConst143;
	double fConst144;
	double fConst145;
	double fConst146;
	double fRec50[3];
	double fConst147;
	double fConst148;
	double fConst149;
	double fConst150;
	double fRec51[3];
	double fConst151;
	double fRec52[3];
	double fConst152;
	double fConst153;
	double fConst154;
	double fConst155;
	double fRec53[3];
	double fConst156;
	double fRec54[3];
	double fConst157;
	double fRec55[3];
	double fConst158;
	double fRec56[3];
	double fConst159;
	double fRec57[3];
	double fConst160;
	double fConst161;
	double fConst162;
	double fRec58[3];
	double fConst163;
	double fRec59[3];
	double fConst164;
	double fConst165;
	double fConst166;
	double fRec60[3];
	double fConst167;
	double fConst168;
	double fConst169;
	double fRec61[3];
	double fConst170;
	double fRec62[3];
	double fConst171;
	double fRec63[3];
	double fConst172;
	double fConst173;
	double fConst174;
	double fConst175;
	double fRec64[3];
	double fConst176;
	double fRec65[3];
	double fConst177;
	double fConst178;
	double fConst179;
	double fRec66[3];
	double fConst180;
	double fConst181;
	double fConst182;
	double fRec67[3];
	double fConst183;
	double fConst184;
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
	double fConst193;
	double fConst194;
	double fConst195;
	double fRec71[3];
	double fConst196;
	double fRec72[3];
	double fConst197;
	double fConst198;
	double fConst199;
	double fConst200;
	double fRec73[3];
	double fConst201;
	double fConst202;
	double fConst203;
	double fRec74[3];
	double fConst204;
	double fConst205;
	double fConst206;
	double fRec75[3];
	double fConst207;
	double fConst208;
	double fConst209;
	double fRec76[3];
	double fConst210;
	double fRec77[3];
	double fConst211;
	double fRec78[3];
	double fConst212;
	double fConst213;
	double fConst214;
	double fConst215;
	double fRec79[3];
	double fConst216;
	double fRec80[3];
	double fConst217;
	double fConst218;
	double fConst219;
	double fRec81[3];
	double fConst220;
	double fConst221;
	double fConst222;
	double fRec82[3];
	double fConst223;
	double fConst224;
	double fConst225;
	double fRec83[3];
	double fConst226;
	double fConst227;
	double fConst228;
	double fRec84[3];
	double fConst229;
	double fConst230;
	double fConst231;
	double fRec85[3];
	double fConst232;
	double fConst233;
	double fConst234;
	double fRec86[3];
	double fConst235;
	double fConst236;
	double fConst237;
	double fRec87[3];
	double fConst238;
	double fConst239;
	double fConst240;
	double fRec88[3];
	double fConst241;
	double fConst242;
	double fConst243;
	double fRec89[3];
	double fConst244;
	double fConst245;
	double fConst246;
	double fRec90[3];
	double fConst247;
	double fConst248;
	double fConst249;
	double fConst250;
	double fRec91[3];
	double fConst251;
	double fRec92[3];
	double fConst252;
	double fConst253;
	double fConst254;
	double fRec93[3];
	double fConst255;
	double fConst256;
	double fConst257;
	double fConst258;
	double fRec94[3];
	double fConst259;
	double fRec95[3];
	double fConst260;
	double fConst261;
	double fConst262;
	double fRec96[3];
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
	double fRec99[3];
	double fConst272;
	double fConst273;
	double fConst274;
	double fConst275;
	double fRec100[3];
	double fConst276;
	double fRec101[3];
	double fConst277;
	double fConst278;
	double fConst279;
	double fRec102[3];
	double fConst280;
	double fConst281;
	double fConst282;
	double fRec103[3];
	double fConst283;
	double fConst284;
	double fConst285;
	double fConst286;
	double fRec104[3];
	double fConst287;
	double fRec105[3];
	double fConst288;
	double fConst289;
	double fConst290;
	double fConst291;
	double fRec106[3];
	double fConst292;
	double fRec107[3];
	double fConst293;
	double fRec108[3];
	double fConst294;
	double fRec109[3];
	double fConst295;
	double fConst296;
	double fConst297;
	double fRec110[3];
	double fConst298;
	double fConst299;
	double fConst300;
	double fRec111[3];
	double fConst301;
	double fConst302;
	double fConst303;
	double fConst304;
	double fRec112[3];
	double fConst305;
	double fRec113[3];
	double fConst306;
	double fRec114[3];
	double fConst307;
	double fRec115[3];
	double fConst308;
	double fConst309;
	double fConst310;
	double fRec116[3];
	double fConst311;
	double fConst312;
	double fConst313;
	double fRec117[3];
	double fConst314;
	double fConst315;
	double fConst316;
	double fRec118[3];
	double fConst317;
	double fRec119[3];
	double fConst318;
	double fRec120[3];
	double fConst319;
	double fConst320;
	double fConst321;
	double fConst322;
	double fRec121[3];
	double fConst323;
	double fRec122[3];
	double fConst324;
	double fConst325;
	double fConst326;
	double fRec123[3];
	double fConst327;
	double fConst328;
	double fConst329;
	double fRec124[3];
	double fConst330;
	double fConst331;
	double fConst332;
	double fConst333;
	double fRec125[3];
	double fConst334;
	double fRec126[3];
	double fConst335;
	double fRec127[3];
	double fConst336;
	double fRec128[3];
	double fConst337;
	double fConst338;
	double fConst339;
	double fRec129[3];
	double fConst340;
	double fConst341;
	double fConst342;
	double fConst343;
	double fRec130[3];
	double fConst344;
	double fConst345;
	double fConst346;
	double fRec131[3];
	double fConst347;
	double fConst348;
	double fConst349;
	double fRec132[3];
	double fConst350;
	double fConst351;
	double fConst352;
	double fRec133[3];
	double fConst353;
	double fConst354;
	double fConst355;
	double fRec134[3];
	double fConst356;
	double fConst357;
	double fConst358;
	double fConst359;
	double fRec135[3];
	double fConst360;
	double fConst361;
	double fConst362;
	double fConst363;
	double fRec136[3];
	double fConst364;
	double fConst365;
	double fConst366;
	double fRec137[3];
	double fConst367;
	double fRec138[3];
	double fConst368;
	double fConst369;
	double fConst370;
	double fRec139[3];
	double fConst371;
	double fConst372;
	double fConst373;
	double fRec140[3];
	double fConst374;
	double fConst375;
	double fConst376;
	double fConst377;
	double fRec141[3];
	double fConst378;
	double fRec142[3];
	double fConst379;
	double fRec143[3];
	double fConst380;
	double fConst381;
	double fConst382;
	double fConst383;
	double fRec144[3];
	double fConst384;
	double fRec145[3];
	double fConst385;
	double fConst386;
	double fConst387;
	double fRec146[3];
	double fConst388;
	double fConst389;
	double fConst390;
	double fRec147[3];
	double fConst391;
	double fConst392;
	double fConst393;
	double fRec148[3];
	double fConst394;
	double fConst395;
	double fConst396;
	double fConst397;
	double fRec149[3];
	double fConst398;
	double fRec150[3];
	double fConst399;
	double fConst400;
	double fConst401;
	double fRec151[3];
	double fConst402;
	double fRec152[3];
	double fConst403;
	double fRec153[3];
	double fConst404;
	double fRec154[3];
	double fConst405;
	double fConst406;
	double fConst407;
	double fConst408;
	double fRec155[3];
	double fConst409;
	double fRec156[3];
	double fConst410;
	double fConst411;
	double fConst412;
	double fRec157[3];
	double fConst413;
	double fConst414;
	double fConst415;
	double fRec158[3];
	double fConst416;
	double fRec159[3];
	double fConst417;
	double fRec160[3];
	double fConst418;
	double fRec161[3];
	double fConst419;
	double fConst420;
	double fConst421;
	double fRec162[3];
	double fConst422;
	double fConst423;
	double fConst424;
	double fRec163[3];
	double fConst425;
	double fConst426;
	double fConst427;
	double fConst428;
	double fRec164[3];
	double fConst429;
	double fRec165[3];
	double fConst430;
	double fConst431;
	double fConst432;
	double fConst433;
	double fRec166[3];
	double fConst434;
	double fRec167[3];
	double fConst435;
	double fRec168[3];
	double fConst436;
	double fRec169[3];
	double fConst437;
	double fRec170[3];
	double fConst438;
	double fRec171[3];
	double fConst439;
	double fConst440;
	double fConst441;
	double fRec172[3];
	double fConst442;
	double fRec173[3];
	double fConst443;
	double fConst444;
	double fConst445;
	double fRec174[3];
	double fConst446;
	double fRec175[3];
	double fConst447;
	double fConst448;
	double fConst449;
	double fRec176[3];
	double fConst450;
	double fConst451;
	double fConst452;
	double fRec177[3];
	double fConst453;
	double fConst454;
	double fConst455;
	double fRec178[3];
	double fConst456;
	double fConst457;
	double fConst458;
	double fConst459;
	double fRec179[3];
	double fConst460;
	double fConst461;
	double fConst462;
	double fConst463;
	double fRec180[3];
	double fConst464;
	double fConst465;
	double fConst466;
	double fRec181[3];
	double fConst467;
	double fRec182[3];
	double fConst468;
	double fConst469;
	double fConst470;
	double fRec183[3];
	double fConst471;
	double fConst472;
	double fConst473;
	double fConst474;
	double fRec184[3];
	double fConst475;
	double fRec185[3];
	double fConst476;
	double fConst477;
	double fConst478;
	double fRec186[3];
	double fConst479;
	double fRec187[3];
	double fConst480;
	double fRec188[3];
	double fConst481;
	double fRec189[3];
	double fConst482;
	double fConst483;
	double fConst484;
	double fRec190[3];
	double fConst485;
	double fRec191[3];
	double fConst486;
	double fRec192[3];
	double fConst487;
	double fRec193[3];
	double fConst488;
	double fConst489;
	double fConst490;
	double fConst491;
	double fRec194[3];
	double fConst492;
	double fConst493;
	double fConst494;
	double fConst495;
	double fRec195[3];
	double fConst496;
	double fConst497;
	double fConst498;
	double fConst499;
	double fRec196[3];
	double fConst500;
	double fRec197[3];
	double fConst501;
	double fRec198[3];
	double fConst502;
	double fRec199[3];
	double fConst503;
	double fRec200[3];
	double fConst504;
	double fRec201[3];
	double fConst505;
	double fConst506;
	double fConst507;
	double fConst508;
	double fRec202[3];
	double fConst509;
	double fConst510;
	double fConst511;
	double fConst512;
	double fRec203[3];
	double fConst513;
	double fRec204[3];
	double fConst514;
	double fConst515;
	double fConst516;
	double fRec205[3];
	double fConst517;
	double fConst518;
	double fConst519;
	double fRec206[3];
	double fConst520;
	double fConst521;
	double fConst522;
	double fRec207[3];
	double fConst523;
	double fConst524;
	double fConst525;
	double fRec208[3];
	double fConst526;
	double fConst527;
	double fConst528;
	double fRec209[3];
	double fConst529;
	double fRec210[3];
	double fConst530;
	double fRec211[3];
	double fConst531;
	double fRec212[3];
	double fConst532;
	double fRec213[3];
	double fConst533;
	double fRec214[3];
	double fConst534;
	double fRec215[3];
	double fConst535;
	double fRec216[3];
	double fConst536;
	double fRec217[3];
	double fConst537;
	double fRec218[3];
	double fConst538;
	double fConst539;
	double fConst540;
	double fConst541;
	double fRec219[3];
	double fConst542;
	double fConst543;
	double fConst544;
	double fRec220[3];
	double fConst545;
	double fConst546;
	double fConst547;
	double fConst548;
	double fRec221[3];
	double fConst549;
	double fRec222[3];
	double fConst550;
	double fRec223[3];
	double fConst551;
	double fRec224[3];
	double fConst552;
	double fRec225[3];
	double fConst553;
	double fRec226[3];
	double fConst554;
	double fRec227[3];
	double fConst555;
	double fRec228[3];
	double fConst556;
	double fConst557;
	double fConst558;
	double fConst559;
	double fRec229[3];
	double fConst560;
	double fConst561;
	double fConst562;
	double fConst563;
	double fRec230[3];
	double fConst564;
	double fRec231[3];
	double fConst565;
	double fRec232[3];
	double fConst566;
	double fConst567;
	double fConst568;
	double fConst569;
	double fRec233[3];
	double fConst570;
	double fRec234[3];
	double fConst571;
	double fRec235[3];
	double fConst572;
	double fRec236[3];
	double fConst573;
	double fRec237[3];
	double fConst574;
	double fRec238[3];
	double fConst575;
	double fConst576;
	double fConst577;
	double fRec239[3];
	double fConst578;
	double fRec240[3];
	double fConst579;
	double fRec241[3];
	double fConst580;
	double fRec242[3];
	double fConst581;
	double fConst582;
	double fConst583;
	double fConst584;
	double fRec243[3];
	double fConst585;
	double fRec244[3];
	double fConst586;
	double fRec245[3];
	double fConst587;
	double fRec246[3];
	double fConst588;
	double fConst589;
	double fConst590;
	double fConst591;
	double fRec247[3];
	double fConst592;
	double fRec248[3];
	double fConst593;
	double fRec249[3];
	double fConst594;
	double fConst595;
	double fConst596;
	double fRec250[3];
	double fConst597;
	double fConst598;
	double fConst599;
	double fRec251[3];
	double fConst600;
	double fRec252[3];
	double fConst601;
	double fRec253[3];
	double fConst602;
	double fRec254[3];
	double fConst603;
	double fConst604;
	double fConst605;
	double fConst606;
	double fRec255[3];
	double fConst607;
	double fRec256[3];
	double fConst608;
	double fRec257[3];
	double fConst609;
	double fRec258[3];
	double fConst610;
	double fRec259[3];
	double fConst611;
	double fConst612;
	double fConst613;
	double fConst614;
	double fRec260[3];
	double fConst615;
	double fRec261[3];
	double fConst616;
	double fRec262[3];
	double fConst617;
	double fRec263[3];
	double fConst618;
	double fRec264[3];
	double fConst619;
	double fRec265[3];
	double fConst620;
	double fRec266[3];
	double fConst621;
	double fConst622;
	double fConst623;
	double fRec267[3];
	double fConst624;
	double fConst625;
	double fConst626;
	double fRec268[3];
	double fConst627;
	double fRec269[3];
	double fConst628;
	double fRec270[3];
	double fConst629;
	double fRec271[3];
	double fConst630;
	double fRec272[3];
	double fConst631;
	double fRec273[3];
	double fConst632;
	double fRec274[3];
	double fConst633;
	double fRec275[3];
	double fConst634;
	double fConst635;
	double fConst636;
	double fRec276[3];
	double fConst637;
	double fConst638;
	double fConst639;
	double fRec277[3];
	double fConst640;
	double fConst641;
	double fConst642;
	double fConst643;
	double fRec278[3];
	double fConst644;
	double fRec279[3];
	double fConst645;
	double fRec280[3];
	double fConst646;
	double fRec281[3];
	double fConst647;
	double fConst648;
	double fConst649;
	double fRec282[3];
	double fConst650;
	double fConst651;
	double fConst652;
	double fRec283[3];
	double fConst653;
	double fRec284[3];
	double fConst654;
	double fRec285[3];
	double fConst655;
	double fRec286[3];
	double fConst656;
	double fRec287[3];
	double fConst657;
	double fRec288[3];
	double fConst658;
	double fRec289[3];
	double fConst659;
	double fRec290[3];
	double fConst660;
	double fRec291[3];
	double fConst661;
	double fConst662;
	double fConst663;
	double fConst664;
	double fRec292[3];
	double fConst665;
	double fConst666;
	double fConst667;
	double fRec293[3];
	double fConst668;
	double fRec294[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.0");
		m->declare("description", "Generated by tools/physicalModeling/ir2dsp.py");
		m->declare("filename", "cabinetRandallExcelTreble");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "0.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.1");
		m->declare("name", "cabinetRandallExcelTreble");
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
		fConst1 = pow(0.001, (1.0 / (0.0098922267827000008 * fConst0)));
		fConst2 = (cos((453.72844648000955 / fConst0)) * (0.0 - (2.0 * fConst1)));
		fConst3 = mydsp_faustpower2_f(fConst1);
		fConst4 = pow(0.001, (1.0 / (0.14051541293299999 * fConst0)));
		fConst5 = (cos((767.84814019529585 / fConst0)) * (0.0 - (2.0 * fConst4)));
		fConst6 = mydsp_faustpower2_f(fConst4);
		fConst7 = pow(0.001, (1.0 / (0.172163197002 * fConst0)));
		fConst8 = (0.0 - (2.0 * fConst7));
		fConst9 = (cos((1012.163457530734 / fConst0)) * fConst8);
		fConst10 = mydsp_faustpower2_f(fConst7);
		fConst11 = pow(0.001, (1.0 / (0.174621551698 * fConst0)));
		fConst12 = (0.0 - (2.0 * fConst11));
		fConst13 = (cos((1151.772210292944 / fConst0)) * fConst12);
		fConst14 = mydsp_faustpower2_f(fConst11);
		fConst15 = (fConst12 * cos((1430.989715823647 / fConst0)));
		fConst16 = pow(0.001, (1.0 / (0.71878562230200005 * fConst0)));
		fConst17 = (0.0 - (2.0 * fConst16));
		fConst18 = (cos((2094.1312914457149 / fConst0)) * fConst17);
		fConst19 = mydsp_faustpower2_f(fConst16);
		fConst20 = pow(0.001, (1.0 / (0.814613258605 * fConst0)));
		fConst21 = (cos((2966.6859962142389 / fConst0)) * (0.0 - (2.0 * fConst20)));
		fConst22 = mydsp_faustpower2_f(fConst20);
		fConst23 = pow(0.001, (1.0 / (0.137359524421 * fConst0)));
		fConst24 = (0.0 - (2.0 * fConst23));
		fConst25 = (cos((3560.0231954583433 / fConst0)) * fConst24);
		fConst26 = mydsp_faustpower2_f(fConst23);
		fConst27 = pow(0.001, (1.0 / (1.22188071348 * fConst0)));
		fConst28 = (cos((3978.8494537512561 / fConst0)) * (0.0 - (2.0 * fConst27)));
		fConst29 = mydsp_faustpower2_f(fConst27);
		fConst30 = pow(0.001, (1.0 / (0.34916474114099999 * fConst0)));
		fConst31 = (0.0 - (2.0 * fConst30));
		fConst32 = (cos((4502.3822766111143 / fConst0)) * fConst31);
		fConst33 = mydsp_faustpower2_f(fConst30);
		fConst34 = (fConst31 * cos((4781.5997821355331 / fConst0)));
		fConst35 = pow(0.001, (1.0 / (0.19714325297800001 * fConst0)));
		fConst36 = (cos((5549.4479223371127 / fConst0)) * (0.0 - (2.0 * fConst35)));
		fConst37 = mydsp_faustpower2_f(fConst35);
		fConst38 = pow(0.001, (1.0 / (1.74551029889 * fConst0)));
		fConst39 = (0.0 - (2.0 * fConst38));
		fConst40 = (cos((6456.9048153071853 / fConst0)) * fConst39);
		fConst41 = mydsp_faustpower2_f(fConst38);
		fConst42 = (fConst39 * cos((7364.3617082835399 / fConst0)));
		fConst43 = (fConst39 * cos((7643.579213795394 / fConst0)));
		fConst44 = pow(0.001, (1.0 / (0.33029520684899999 * fConst0)));
		fConst45 = (cos((7922.7967193072473 / fConst0)) * (0.0 - (2.0 * fConst44)));
		fConst46 = mydsp_faustpower2_f(fConst44);
		fConst47 = pow(0.001, (1.0 / (0.29807892888600002 * fConst0)));
		fConst48 = (0.0 - (2.0 * fConst47));
		fConst49 = (cos((8376.525165795425 / fConst0)) * fConst48);
		fConst50 = mydsp_faustpower2_f(fConst47);
		fConst51 = pow(0.001, (1.0 / (0.12104889298300001 * fConst0)));
		fConst52 = (0.0 - (2.0 * fConst51));
		fConst53 = (cos((8934.9601768191314 / fConst0)) * fConst52);
		fConst54 = mydsp_faustpower2_f(fConst51);
		fConst55 = (fConst52 * cos((9737.7105051971266 / fConst0)));
		fConst56 = pow(0.001, (1.0 / (0.32160528975399999 * fConst0)));
		fConst57 = (0.0 - (2.0 * fConst56));
		fConst58 = (cos((10331.047704441231 / fConst0)) * fConst57);
		fConst59 = mydsp_faustpower2_f(fConst56);
		fConst60 = pow(0.001, (1.0 / (0.58188899920299997 * fConst0)));
		fConst61 = (0.0 - (2.0 * fConst60));
		fConst62 = (cos((11168.700221039622 / fConst0)) * fConst61);
		fConst63 = mydsp_faustpower2_f(fConst60);
		fConst64 = (fConst61 * cos((11447.917726551475 / fConst0)));
		fConst65 = pow(0.001, (1.0 / (1.0182469859600001 * fConst0)));
		fConst66 = (cos((12076.157114015978 / fConst0)) * (0.0 - (2.0 * fConst65)));
		fConst67 = mydsp_faustpower2_f(fConst65);
		fConst68 = pow(0.001, (1.0 / (0.017286947607800002 * fConst0)));
		fConst69 = (0.0 - (2.0 * fConst68));
		fConst70 = (cos((12948.711818771935 / fConst0)) * fConst69);
		fConst71 = mydsp_faustpower2_f(fConst68);
		fConst72 = pow(0.001, (1.0 / (0.017262744562800001 * fConst0)));
		fConst73 = (0.0 - (2.0 * fConst72));
		fConst74 = (cos((13053.418383370295 / fConst0)) * fConst73);
		fConst75 = mydsp_faustpower2_f(fConst72);
		fConst76 = pow(0.001, (1.0 / (0.0167925897496 * fConst0)));
		fConst77 = (cos((13227.92932428379 / fConst0)) * (0.0 - (2.0 * fConst76)));
		fConst78 = mydsp_faustpower2_f(fConst76);
		fConst79 = (fConst17 * cos((13925.973088126255 / fConst0)));
		fConst80 = pow(0.001, (1.0 / (0.27158998934700002 * fConst0)));
		fConst81 = (cos((14833.429981102609 / fConst0)) * (0.0 - (2.0 * fConst80)));
		fConst82 = mydsp_faustpower2_f(fConst80);
		fConst83 = pow(0.001, (1.0 / (0.531296769015 * fConst0)));
		fConst84 = (cos((15705.984685858568 / fConst0)) * (0.0 - (2.0 * fConst83)));
		fConst85 = mydsp_faustpower2_f(fConst83);
		fConst86 = pow(0.001, (1.0 / (0.124752072014 * fConst0)));
		fConst87 = (0.0 - (2.0 * fConst86));
		fConst88 = (cos((16438.930637858601 / fConst0)) * fConst87);
		fConst89 = mydsp_faustpower2_f(fConst86);
		fConst90 = pow(0.001, (1.0 / (0.126037367835 * fConst0)));
		fConst91 = (cos((16648.34376699249 / fConst0)) * (0.0 - (2.0 * fConst90)));
		fConst92 = mydsp_faustpower2_f(fConst90);
		fConst93 = pow(0.001, (1.0 / (0.67885744053700003 * fConst0)));
		fConst94 = (cos((17590.70284812641 / fConst0)) * (0.0 - (2.0 * fConst93)));
		fConst95 = mydsp_faustpower2_f(fConst93);
		fConst96 = pow(0.001, (1.0 / (0.017238609504399999 * fConst0)));
		fConst97 = (0.0 - (2.0 * fConst96));
		fConst98 = (cos((18114.235670992552 / fConst0)) * fConst97);
		fConst99 = mydsp_faustpower2_f(fConst96);
		fConst100 = pow(0.001, (1.0 / (0.016815485640600002 * fConst0)));
		fConst101 = (0.0 - (2.0 * fConst100));
		fConst102 = (cos((18323.648800189272 / fConst0)) * fConst101);
		fConst103 = mydsp_faustpower2_f(fConst100);
		fConst104 = pow(0.001, (1.0 / (0.090582246324399998 * fConst0)));
		fConst105 = (cos((19440.518822236685 / fConst0)) * (0.0 - (2.0 * fConst104)));
		fConst106 = mydsp_faustpower2_f(fConst104);
		fConst107 = pow(0.001, (1.0 / (0.097822554973599998 * fConst0)));
		fConst108 = (cos((20138.562586079152 / fConst0)) * (0.0 - (2.0 * fConst107)));
		fConst109 = mydsp_faustpower2_f(fConst107);
		fConst110 = pow(0.001, (1.0 / (0.096283276735800005 * fConst0)));
		fConst111 = (0.0 - (2.0 * fConst110));
		fConst112 = (cos((20382.87790343344 / fConst0)) * fConst111);
		fConst113 = mydsp_faustpower2_f(fConst110);
		fConst114 = (fConst111 * cos((20801.704161701218 / fConst0)));
		fConst115 = pow(0.001, (1.0 / (0.095531676037600002 * fConst0)));
		fConst116 = (cos((21150.726043591036 / fConst0)) * (0.0 - (2.0 * fConst115)));
		fConst117 = mydsp_faustpower2_f(fConst115);
		fConst118 = pow(0.001, (1.0 / (0.091943206576700007 * fConst0)));
		fConst119 = (cos((21499.747925543685 / fConst0)) * (0.0 - (2.0 * fConst118)));
		fConst120 = mydsp_faustpower2_f(fConst118);
		fConst121 = pow(0.001, (1.0 / (0.087977818820200004 * fConst0)));
		fConst122 = (0.0 - (2.0 * fConst121));
		fConst123 = (cos((22093.085124787787 / fConst0)) * fConst122);
		fConst124 = mydsp_faustpower2_f(fConst121);
		fConst125 = pow(0.001, (1.0 / (0.092639152163999997 * fConst0)));
		fConst126 = (cos((22407.204818457209 / fConst0)) * (0.0 - (2.0 * fConst125)));
		fConst127 = mydsp_faustpower2_f(fConst125);
		fConst128 = pow(0.001, (1.0 / (0.089916776793000003 * fConst0)));
		fConst129 = (cos((23035.444205921711 / fConst0)) * (0.0 - (2.0 * fConst128)));
		fConst130 = mydsp_faustpower2_f(fConst128);
		fConst131 = (fConst122 * cos((23244.8573350556 / fConst0)));
		fConst132 = (cos((23907.998910677667 / fConst0)) * fConst69);
		fConst133 = pow(0.001, (1.0 / (0.023484607697899999 * fConst0)));
		fConst134 = (cos((24431.531733543809 / fConst0)) * (0.0 - (2.0 * fConst133)));
		fConst135 = mydsp_faustpower2_f(fConst133);
		fConst136 = (cos((25234.282061921804 / fConst0)) * fConst69);
		fConst137 = (fConst101 * cos((25827.61926116591 / fConst0)));
		fConst138 = (fConst101 * cos((26037.032390299799 / fConst0)));
		fConst139 = pow(0.001, (1.0 / (0.061168496518700002 * fConst0)));
		fConst140 = (0.0 - (2.0 * fConst139));
		fConst141 = (cos((26735.076154142262 / fConst0)) * fConst140);
		fConst142 = mydsp_faustpower2_f(fConst139);
		fConst143 = pow(0.001, (1.0 / (0.13434235629800001 * fConst0)));
		fConst144 = (0.0 - (2.0 * fConst143));
		fConst145 = (cos((27153.902412410043 / fConst0)) * fConst144);
		fConst146 = mydsp_faustpower2_f(fConst143);
		fConst147 = pow(0.001, (1.0 / (0.13005733563899999 * fConst0)));
		fConst148 = (0.0 - (2.0 * fConst147));
		fConst149 = (cos((27642.533047118621 / fConst0)) * fConst148);
		fConst150 = mydsp_faustpower2_f(fConst147);
		fConst151 = (cos((27956.652740788035 / fConst0)) * fConst87);
		fConst152 = pow(0.001, (1.0 / (0.13288296520000001 * fConst0)));
		fConst153 = (0.0 - (2.0 * fConst152));
		fConst154 = (cos((28375.478999118652 / fConst0)) * fConst153);
		fConst155 = mydsp_faustpower2_f(fConst152);
		fConst156 = (cos((29248.033703874604 / fConst0)) * fConst87);
		fConst157 = (cos((30120.588408630567 / fConst0)) * fConst73);
		fConst158 = (cos((30225.294973228927 / fConst0)) * fConst97);
		fConst159 = (cos((30888.436548850994 / fConst0)) * fConst73);
		fConst160 = pow(0.001, (1.0 / (0.017335558809799999 * fConst0)));
		fConst161 = (cos((31202.556242583247 / fConst0)) * (0.0 - (2.0 * fConst160)));
		fConst162 = mydsp_faustpower2_f(fConst160);
		fConst163 = (cos((31795.893441827349 / fConst0)) * fConst69);
		fConst164 = pow(0.001, (1.0 / (0.017384445431200001 * fConst0)));
		fConst165 = (cos((32459.03501744942 / fConst0)) * (0.0 - (2.0 * fConst164)));
		fConst166 = mydsp_faustpower2_f(fConst164);
		fConst167 = pow(0.001, (1.0 / (0.0231313082736 * fConst0)));
		fConst168 = (cos((32842.959087496798 / fConst0)) * (0.0 - (2.0 * fConst167)));
		fConst169 = mydsp_faustpower2_f(fConst167);
		fConst170 = (cos((33506.1006631817 / fConst0)) * fConst97);
		fConst171 = (cos((33994.731297827442 / fConst0)) * fConst97);
		fConst172 = pow(0.001, (1.0 / (0.17975517475399999 * fConst0)));
		fConst173 = (0.0 - (2.0 * fConst172));
		fConst174 = (cos((34622.970685229113 / fConst0)) * fConst173);
		fConst175 = mydsp_faustpower2_f(fConst172);
		fConst176 = (fConst173 * cos((35390.81882544954 / fConst0)));
		fConst177 = pow(0.001, (1.0 / (0.031979253901099999 * fConst0)));
		fConst178 = (cos((35809.645083717325 / fConst0)) * (0.0 - (2.0 * fConst177)));
		fConst179 = mydsp_faustpower2_f(fConst177);
		fConst180 = pow(0.001, (1.0 / (0.082078528489899993 * fConst0)));
		fConst181 = (cos((36263.373530205499 / fConst0)) * (0.0 - (2.0 * fConst180)));
		fConst182 = mydsp_faustpower2_f(fConst180);
		fConst183 = pow(0.001, (1.0 / (0.0149422580744 * fConst0)));
		fConst184 = (cos((36891.612917669998 / fConst0)) * (0.0 - (2.0 * fConst183)));
		fConst185 = mydsp_faustpower2_f(fConst183);
		fConst186 = pow(0.001, (1.0 / (0.014924197760999999 * fConst0)));
		fConst187 = (cos((37135.928234961459 / fConst0)) * (0.0 - (2.0 * fConst186)));
		fConst188 = mydsp_faustpower2_f(fConst186);
		fConst189 = pow(0.001, (1.0 / (0.012872246654 * fConst0)));
		fConst190 = (cos((37659.461057827597 / fConst0)) * (0.0 - (2.0 * fConst189)));
		fConst191 = mydsp_faustpower2_f(fConst189);
		fConst192 = pow(0.001, (1.0 / (0.012832183246 * fConst0)));
		fConst193 = (0.0 - (2.0 * fConst192));
		fConst194 = (cos((37868.874187024318 / fConst0)) * fConst193);
		fConst195 = mydsp_faustpower2_f(fConst192);
		fConst196 = (fConst193 * cos((37973.58075155985 / fConst0)));
		fConst197 = pow(0.001, (1.0 / (0.0127923699768 * fConst0)));
		fConst198 = (0.0 - (2.0 * fConst197));
		fConst199 = (cos((38392.407009890463 / fConst0)) * fConst198);
		fConst200 = mydsp_faustpower2_f(fConst197);
		fConst201 = pow(0.001, (1.0 / (0.0126874064918 * fConst0)));
		fConst202 = (cos((38566.917950803952 / fConst0)) * (0.0 - (2.0 * fConst201)));
		fConst203 = mydsp_faustpower2_f(fConst201);
		fConst204 = pow(0.001, (1.0 / (0.0128188844789 * fConst0)));
		fConst205 = (cos((38950.84202091417 / fConst0)) * (0.0 - (2.0 * fConst204)));
		fConst206 = mydsp_faustpower2_f(fConst204);
		fConst207 = pow(0.001, (1.0 / (0.012845509805899999 * fConst0)));
		fConst208 = (cos((39299.863902803983 / fConst0)) * (0.0 - (2.0 * fConst207)));
		fConst209 = mydsp_faustpower2_f(fConst207);
		fConst210 = (fConst193 * cos((39509.277031937869 / fConst0)));
		fConst211 = (fConst198 * cos((39928.103290268482 / fConst0)));
		fConst212 = pow(0.001, (1.0 / (0.0126614358698 * fConst0)));
		fConst213 = (0.0 - (2.0 * fConst212));
		fConst214 = (cos((40137.516419402375 / fConst0)) * fConst213);
		fConst215 = mydsp_faustpower2_f(fConst212);
		fConst216 = (fConst213 * cos((40277.125172158303 / fConst0)));
		fConst217 = pow(0.001, (1.0 / (0.0125331711977 * fConst0)));
		fConst218 = (cos((40870.462371402406 / fConst0)) * (0.0 - (2.0 * fConst217)));
		fConst219 = mydsp_faustpower2_f(fConst217);
		fConst220 = pow(0.001, (1.0 / (0.0122357504464 * fConst0)));
		fConst221 = (cos((41708.114888000797 / fConst0)) * (0.0 - (2.0 * fConst220)));
		fConst222 = mydsp_faustpower2_f(fConst220);
		fConst223 = pow(0.001, (1.0 / (0.0098607985537700008 * fConst0)));
		fConst224 = (cos((42301.452087244907 / fConst0)) * (0.0 - (2.0 * fConst223)));
		fConst225 = mydsp_faustpower2_f(fConst223);
		fConst226 = pow(0.001, (1.0 / (0.0098843508075900002 * fConst0)));
		fConst227 = (cos((42755.180533733081 / fConst0)) * (0.0 - (2.0 * fConst226)));
		fConst228 = mydsp_faustpower2_f(fConst226);
		fConst229 = pow(0.001, (1.0 / (0.0097294442436999997 * fConst0)));
		fConst230 = (cos((43208.908980158427 / fConst0)) * (0.0 - (2.0 * fConst229)));
		fConst231 = mydsp_faustpower2_f(fConst229);
		fConst232 = pow(0.001, (1.0 / (0.0097218272938899997 * fConst0)));
		fConst233 = (cos((43557.930862111076 / fConst0)) * (0.0 - (2.0 * fConst232)));
		fConst234 = mydsp_faustpower2_f(fConst232);
		fConst235 = pow(0.001, (1.0 / (0.0095279221101900007 * fConst0)));
		fConst236 = (cos((44151.268061355178 / fConst0)) * (0.0 - (2.0 * fConst235)));
		fConst237 = mydsp_faustpower2_f(fConst235);
		fConst238 = pow(0.001, (1.0 / (0.0095206198348900001 * fConst0)));
		fConst239 = (cos((44430.485566867035 / fConst0)) * (0.0 - (2.0 * fConst238)));
		fConst240 = mydsp_faustpower2_f(fConst238);
		fConst241 = pow(0.001, (1.0 / (0.0094195603912199995 * fConst0)));
		fConst242 = (cos((45268.138083465426 / fConst0)) * (0.0 - (2.0 * fConst241)));
		fConst243 = mydsp_faustpower2_f(fConst241);
		fConst244 = pow(0.001, (1.0 / (0.0090426401674900004 * fConst0)));
		fConst245 = (cos((46245.399352756911 / fConst0)) * (0.0 - (2.0 * fConst244)));
		fConst246 = mydsp_faustpower2_f(fConst244);
		fConst247 = pow(0.001, (1.0 / (0.0090558125985799997 * fConst0)));
		fConst248 = (0.0 - (2.0 * fConst247));
		fConst249 = (cos((46559.519046489164 / fConst0)) * fConst248);
		fConst250 = mydsp_faustpower2_f(fConst247);
		fConst251 = (fConst248 * cos((46734.029987465488 / fConst0)));
		fConst252 = pow(0.001, (1.0 / (0.0090492215472199999 * fConst0)));
		fConst253 = (cos((46838.736552001021 / fConst0)) * (0.0 - (2.0 * fConst252)));
		fConst254 = mydsp_faustpower2_f(fConst252);
		fConst255 = pow(0.001, (1.0 / (0.0090624133429100008 * fConst0)));
		fConst256 = (0.0 - (2.0 * fConst255));
		fConst257 = (cos((46978.34530481977 / fConst0)) * fConst256);
		fConst258 = mydsp_faustpower2_f(fConst255);
		fConst259 = (fConst256 * cos((47048.149681197741 / fConst0)));
		fConst260 = pow(0.001, (1.0 / (0.0090690238016000006 * fConst0)));
		fConst261 = (cos((47222.660622111231 / fConst0)) * (0.0 - (2.0 * fConst260)));
		fConst262 = mydsp_faustpower2_f(fConst260);
		fConst263 = pow(0.001, (1.0 / (0.0089130113074600004 * fConst0)));
		fConst264 = (cos((48234.824079685946 / fConst0)) * (0.0 - (2.0 * fConst263)));
		fConst265 = mydsp_faustpower2_f(fConst263);
		fConst266 = pow(0.001, (1.0 / (0.0087995098027700003 * fConst0)));
		fConst267 = (cos((48758.356902552085 / fConst0)) * (0.0 - (2.0 * fConst266)));
		fConst268 = mydsp_faustpower2_f(fConst266);
		fConst269 = pow(0.001, (1.0 / (0.0086286355167400006 * fConst0)));
		fConst270 = (cos((49386.596289953755 / fConst0)) * (0.0 - (2.0 * fConst269)));
		fConst271 = mydsp_faustpower2_f(fConst269);
		fConst272 = pow(0.001, (1.0 / (0.643132225291 * fConst0)));
		fConst273 = (0.0 - (2.0 * fConst272));
		fConst274 = (cos((49561.107230930087 / fConst0)) * fConst273);
		fConst275 = mydsp_faustpower2_f(fConst272);
		fConst276 = (fConst273 * cos((49630.911607308044 / fConst0)));
		fConst277 = pow(0.001, (1.0 / (0.0085810374044200007 * fConst0)));
		fConst278 = (cos((50049.737865575829 / fConst0)) * (0.0 - (2.0 * fConst277)));
		fConst279 = mydsp_faustpower2_f(fConst277);
		fConst280 = pow(0.001, (1.0 / (0.0085633244648900004 * fConst0)));
		fConst281 = (cos((50294.053182930118 / fConst0)) * (0.0 - (2.0 * fConst280)));
		fConst282 = mydsp_faustpower2_f(fConst280);
		fConst283 = pow(0.001, (1.0 / (0.131454958861 * fConst0)));
		fConst284 = (0.0 - (2.0 * fConst283));
		fConst285 = (cos((51341.118828662395 / fConst0)) * fConst284);
		fConst286 = mydsp_faustpower2_f(fConst283);
		fConst287 = (fConst148 * cos((51480.727581418323 / fConst0)));
		fConst288 = pow(0.001, (1.0 / (0.13583417831200001 * fConst0)));
		fConst289 = (0.0 - (2.0 * fConst288));
		fConst290 = (cos((51899.553839686108 / fConst0)) * fConst289);
		fConst291 = mydsp_faustpower2_f(fConst288);
		fConst292 = (fConst289 * cos((52004.260404284461 / fConst0)));
		fConst293 = (fConst144 * cos((52143.869157040397 / fConst0)));
		fConst294 = (fConst144 * cos((52353.282286174282 / fConst0)));
		fConst295 = pow(0.001, (1.0 / (0.222224238814 * fConst0)));
		fConst296 = (cos((52737.206356284492 / fConst0)) * (0.0 - (2.0 * fConst295)));
		fConst297 = mydsp_faustpower2_f(fConst295);
		fConst298 = pow(0.001, (1.0 / (0.21442964669600001 * fConst0)));
		fConst299 = (cos((52946.619485418385 / fConst0)) * (0.0 - (2.0 * fConst298)));
		fConst300 = mydsp_faustpower2_f(fConst298);
		fConst301 = pow(0.001, (1.0 / (0.24443882647000001 * fConst0)));
		fConst302 = (0.0 - (2.0 * fConst301));
		fConst303 = (cos((53505.054496442091 / fConst0)) * fConst302);
		fConst304 = mydsp_faustpower2_f(fConst301);
		fConst305 = (fConst302 * cos((53609.761061040459 / fConst0)));
		fConst306 = (fConst302 * cos((53714.467625638812 / fConst0)));
		fConst307 = (fConst302 * cos((53784.272002016776 / fConst0)));
		fConst308 = pow(0.001, (1.0 / (0.235040347058 * fConst0)));
		fConst309 = (cos((53958.782942930266 / fConst0)) * (0.0 - (2.0 * fConst308)));
		fConst310 = mydsp_faustpower2_f(fConst308);
		fConst311 = pow(0.001, (1.0 / (0.305528943153 * fConst0)));
		fConst312 = (cos((54936.044212284585 / fConst0)) * (0.0 - (2.0 * fConst311)));
		fConst313 = mydsp_faustpower2_f(fConst311);
		fConst314 = pow(0.001, (1.0 / (0.28421843725099999 * fConst0)));
		fConst315 = (cos((55145.457341418478 / fConst0)) * (0.0 - (2.0 * fConst314)));
		fConst316 = mydsp_faustpower2_f(fConst314);
		fConst317 = (cos((55215.261717796442 / fConst0)) * fConst48);
		fConst318 = (cos((55668.990164284616 / fConst0)) * fConst57);
		fConst319 = pow(0.001, (1.0 / (0.067210373342000002 * fConst0)));
		fConst320 = (0.0 - (2.0 * fConst319));
		fConst321 = (cos((56681.153621859332 / fConst0)) * fConst320);
		fConst322 = mydsp_faustpower2_f(fConst319);
		fConst323 = (fConst320 * cos((56750.957998237303 / fConst0)));
		fConst324 = pow(0.001, (1.0 / (0.117559358926 * fConst0)));
		fConst325 = (cos((57553.708326615299 / fConst0)) * (0.0 - (2.0 * fConst324)));
		fConst326 = mydsp_faustpower2_f(fConst324);
		fConst327 = pow(0.001, (1.0 / (0.118699950961 * fConst0)));
		fConst328 = (cos((57658.414891150824 / fConst0)) * (0.0 - (2.0 * fConst327)));
		fConst329 = mydsp_faustpower2_f(fConst327);
		fConst330 = pow(0.001, (1.0 / (0.26568756261999998 * fConst0)));
		fConst331 = (0.0 - (2.0 * fConst330));
		fConst332 = (cos((58530.969595969618 / fConst0)) * fConst331);
		fConst333 = mydsp_faustpower2_f(fConst330);
		fConst334 = (fConst331 * cos((59473.328677103535 / fConst0)));
		fConst335 = (fConst331 * cos((60101.568064505205 / fConst0)));
		fConst336 = (cos((60380.78557007989 / fConst0)) * fConst87);
		fConst337 = pow(0.001, (1.0 / (0.93992632156599998 * fConst0)));
		fConst338 = (cos((61358.046839371375 / fConst0)) * (0.0 - (2.0 * fConst337)));
		fConst339 = mydsp_faustpower2_f(fConst337);
		fConst340 = pow(0.001, (1.0 / (0.030854289415899998 * fConst0)));
		fConst341 = (0.0 - (2.0 * fConst340));
		fConst342 = (cos((62335.308108725694 / fConst0)) * fConst341);
		fConst343 = mydsp_faustpower2_f(fConst340);
		fConst344 = pow(0.001, (1.0 / (0.030623470831300001 * fConst0)));
		fConst345 = (cos((62440.014673324047 / fConst0)) * (0.0 - (2.0 * fConst344)));
		fConst346 = mydsp_faustpower2_f(fConst344);
		fConst347 = pow(0.001, (1.0 / (0.086120788670400003 * fConst0)));
		fConst348 = (cos((62823.938743434272 / fConst0)) * (0.0 - (2.0 * fConst347)));
		fConst349 = mydsp_faustpower2_f(fConst347);
		fConst350 = pow(0.001, (1.0 / (0.10022610011200001 * fConst0)));
		fConst351 = (cos((63487.080318742184 / fConst0)) * (0.0 - (2.0 * fConst350)));
		fConst352 = mydsp_faustpower2_f(fConst350);
		fConst353 = pow(0.001, (1.0 / (0.101895228693 * fConst0)));
		fConst354 = (cos((63661.591259844157 / fConst0)) * (0.0 - (2.0 * fConst353)));
		fConst355 = mydsp_faustpower2_f(fConst353);
		fConst356 = pow(0.001, (1.0 / (0.210733934924 * fConst0)));
		fConst357 = (0.0 - (2.0 * fConst356));
		fConst358 = (cos((64848.265658583703 / fConst0)) * fConst357);
		fConst359 = mydsp_faustpower2_f(fConst356);
		fConst360 = pow(0.001, (1.0 / (0.203712082574 * fConst0)));
		fConst361 = (0.0 - (2.0 * fConst360));
		fConst362 = (cos((65057.678787403434 / fConst0)) * fConst361);
		fConst363 = mydsp_faustpower2_f(fConst360);
		fConst364 = pow(0.001, (1.0 / (0.19098497525300001 * fConst0)));
		fConst365 = (cos((65336.896292915284 / fConst0)) * (0.0 - (2.0 * fConst364)));
		fConst366 = mydsp_faustpower2_f(fConst364);
		fConst367 = (fConst173 * cos((65581.21161070939 / fConst0)));
		fConst368 = pow(0.001, (1.0 / (0.0300245494419 * fConst0)));
		fConst369 = (cos((67256.516643780516 / fConst0)) * (0.0 - (2.0 * fConst368)));
		fConst370 = mydsp_faustpower2_f(fConst368);
		fConst371 = pow(0.001, (1.0 / (0.029168947552800001 * fConst0)));
		fConst372 = (cos((67465.929772600255 / fConst0)) * (0.0 - (2.0 * fConst371)));
		fConst373 = mydsp_faustpower2_f(fConst371);
		fConst374 = pow(0.001, (1.0 / (0.029308136368899999 * fConst0)));
		fConst375 = (0.0 - (2.0 * fConst374));
		fConst376 = (cos((67535.734149292373 / fConst0)) * fConst375);
		fConst377 = mydsp_faustpower2_f(fConst374);
		fConst378 = (fConst375 * cos((67640.440713702235 / fConst0)));
		fConst379 = (fConst375 * cos((67745.147278112097 / fConst0)));
		fConst380 = pow(0.001, (1.0 / (0.030321045172600002 * fConst0)));
		fConst381 = (0.0 - (2.0 * fConst380));
		fConst382 = (cos((68094.169160316073 / fConst0)) * fConst381);
		fConst383 = mydsp_faustpower2_f(fConst380);
		fConst384 = (fConst381 * cos((68163.973536379883 / fConst0)));
		fConst385 = pow(0.001, (1.0 / (0.060265687390200003 * fConst0)));
		fConst386 = (cos((68966.72386519771 / fConst0)) * (0.0 - (2.0 * fConst385)));
		fConst387 = mydsp_faustpower2_f(fConst385);
		fConst388 = pow(0.001, (1.0 / (0.059102648277900002 * fConst0)));
		fConst389 = (cos((69141.234805671367 / fConst0)) * (0.0 - (2.0 * fConst388)));
		fConst390 = mydsp_faustpower2_f(fConst388);
		fConst391 = pow(0.001, (1.0 / (0.10275083242499999 * fConst0)));
		fConst392 = (cos((69804.376381733251 / fConst0)) * (0.0 - (2.0 * fConst391)));
		fConst393 = mydsp_faustpower2_f(fConst391);
		fConst394 = pow(0.001, (1.0 / (0.103620937917 * fConst0)));
		fConst395 = (0.0 - (2.0 * fConst394));
		fConst396 = (cos((70013.78951055299 / fConst0)) * fConst395);
		fConst397 = mydsp_faustpower2_f(fConst394);
		fConst398 = (fConst395 * cos((70083.593887245108 / fConst0)));
		fConst399 = pow(0.001, (1.0 / (0.128689136067 * fConst0)));
		fConst400 = (cos((70572.224521576703 / fConst0)) * (0.0 - (2.0 * fConst399)));
		fConst401 = mydsp_faustpower2_f(fConst399);
		fConst402 = (fConst289 * cos((70746.735462678684 / fConst0)));
		fConst403 = (fConst284 * cos((70991.050779844474 / fConst0)));
		fConst404 = (cos((71235.366097638587 / fConst0)) * fConst87);
		fConst405 = pow(0.001, (1.0 / (0.123492741768 * fConst0)));
		fConst406 = (0.0 - (2.0 * fConst405));
		fConst407 = (cos((71305.170473702397 / fConst0)) * fConst406);
		fConst408 = mydsp_faustpower2_f(fConst405);
		fConst409 = (fConst406 * cos((71374.974850394516 / fConst0)));
		fConst410 = pow(0.001, (1.0 / (0.12225859813000001 * fConst0)));
		fConst411 = (cos((71444.779226458311 / fConst0)) * (0.0 - (2.0 * fConst410)));
		fConst412 = mydsp_faustpower2_f(fConst410);
		fConst413 = pow(0.001, (1.0 / (0.094791728066100006 * fConst0)));
		fConst414 = (cos((72247.529554647816 / fConst0)) * (0.0 - (2.0 * fConst413)));
		fConst415 = mydsp_faustpower2_f(fConst413);
		fConst416 = (fConst140 * cos((72456.942684095862 / fConst0)));
		fConst417 = (fConst140 * cos((72526.747060159672 / fConst0)));
		fConst418 = (fConst341 * cos((73224.790824567623 / fConst0)));
		fConst419 = pow(0.001, (1.0 / (0.0309320061128 * fConst0)));
		fConst420 = (cos((73294.595200631433 / fConst0)) * (0.0 - (2.0 * fConst419)));
		fConst421 = mydsp_faustpower2_f(fConst419);
		fConst422 = pow(0.001, (1.0 / (0.031246838046300001 * fConst0)));
		fConst423 = (cos((73504.008330079479 / fConst0)) * (0.0 - (2.0 * fConst422)));
		fConst424 = mydsp_faustpower2_f(fConst422);
		fConst425 = pow(0.001, (1.0 / (0.054140434158899998 * fConst0)));
		fConst426 = (0.0 - (2.0 * fConst425));
		fConst427 = (cos((73818.12802330908 / fConst0)) * fConst426);
		fConst428 = mydsp_faustpower2_f(fConst425);
		fConst429 = (fConst426 * cos((73887.932400001184 / fConst0)));
		fConst430 = pow(0.001, (1.0 / (0.053902275508600002 * fConst0)));
		fConst431 = (0.0 - (2.0 * fConst430));
		fConst432 = (cos((73957.736776064994 / fConst0)) * fConst431);
		fConst433 = mydsp_faustpower2_f(fConst430);
		fConst434 = (fConst431 * cos((74027.541152757127 / fConst0)));
		fConst435 = (fConst426 * cos((74097.345528820922 / fConst0)));
		fConst436 = (fConst426 * cos((74167.149905513041 / fConst0)));
		fConst437 = (fConst426 * cos((74271.856469922917 / fConst0)));
		fConst438 = (fConst426 * cos((74341.660846615036 / fConst0)));
		fConst439 = pow(0.001, (1.0 / (0.054380709776599999 * fConst0)));
		fConst440 = (cos((74446.367411024898 / fConst0)) * (0.0 - (2.0 * fConst439)));
		fConst441 = mydsp_faustpower2_f(fConst439);
		fConst442 = (fConst426 * cos((74551.073975434774 / fConst0)));
		fConst443 = pow(0.001, (1.0 / (0.058259444938199997 * fConst0)));
		fConst444 = (cos((74830.291480946617 / fConst0)) * (0.0 - (2.0 * fConst443)));
		fConst445 = mydsp_faustpower2_f(fConst443);
		fConst446 = (fConst426 * cos((75284.019927560468 / fConst0)));
		fConst447 = pow(0.001, (1.0 / (0.028625200620499999 * fConst0)));
		fConst448 = (cos((76331.085573544071 / fConst0)) * (0.0 - (2.0 * fConst447)));
		fConst449 = mydsp_faustpower2_f(fConst447);
		fConst450 = pow(0.001, (1.0 / (0.17715116305600001 * fConst0)));
		fConst451 = (cos((80030.717521261962 / fConst0)) * (0.0 - (2.0 * fConst450)));
		fConst452 = mydsp_faustpower2_f(fConst450);
		fConst453 = pow(0.001, (1.0 / (0.16977312994099999 * fConst0)));
		fConst454 = (cos((80240.130650710009 / fConst0)) * (0.0 - (2.0 * fConst453)));
		fConst455 = mydsp_faustpower2_f(fConst453);
		fConst456 = pow(0.001, (1.0 / (0.165186785054 * fConst0)));
		fConst457 = (0.0 - (2.0 * fConst456));
		fConst458 = (cos((80414.641591812004 / fConst0)) * fConst457);
		fConst459 = mydsp_faustpower2_f(fConst456);
		fConst460 = pow(0.001, (1.0 / (0.19401523889300001 * fConst0)));
		fConst461 = (0.0 - (2.0 * fConst460));
		fConst462 = (cos((80728.761285041604 / fConst0)) * fConst461);
		fConst463 = mydsp_faustpower2_f(fConst460);
		fConst464 = pow(0.001, (1.0 / (0.13891953748999999 * fConst0)));
		fConst465 = (cos((81182.489731655442 / fConst0)) * (0.0 - (2.0 * fConst464)));
		fConst466 = mydsp_faustpower2_f(fConst464);
		fConst467 = (fConst144 * cos((81391.902861103488 / fConst0)));
		fConst468 = pow(0.001, (1.0 / (0.106322048027 * fConst0)));
		fConst469 = (cos((82124.848812600874 / fConst0)) * (0.0 - (2.0 * fConst468)));
		fConst470 = mydsp_faustpower2_f(fConst468);
		fConst471 = pow(0.001, (1.0 / (0.149078647077 * fConst0)));
		fConst472 = (0.0 - (2.0 * fConst471));
		fConst473 = (cos((84882.12168000167 / fConst0)) * fConst472);
		fConst474 = mydsp_faustpower2_f(fConst471);
		fConst475 = (fConst461 * cos((85021.730432757584 / fConst0)));
		fConst476 = pow(0.001, (1.0 / (0.22633805133099999 * fConst0)));
		fConst477 = (cos((85475.458879371421 / fConst0)) * (0.0 - (2.0 * fConst476)));
		fConst478 = mydsp_faustpower2_f(fConst476);
		fConst479 = (fConst461 * cos((85824.480760947088 / fConst0)));
		fConst480 = (fConst461 * cos((85929.187325985273 / fConst0)));
		fConst481 = (fConst461 * cos((85998.991702049068 / fConst0)));
		fConst482 = pow(0.001, (1.0 / (0.152803653959 * fConst0)));
		fConst483 = (cos((86173.502643151063 / fConst0)) * (0.0 - (2.0 * fConst482)));
		fConst484 = mydsp_faustpower2_f(fConst482);
		fConst485 = (fConst472 * cos((86278.209207560925 / fConst0)));
		fConst486 = (fConst472 * cos((86348.013584253058 / fConst0)));
		fConst487 = (fConst472 * cos((86417.817960316854 / fConst0)));
		fConst488 = pow(0.001, (1.0 / (0.025479721830699999 * fConst0)));
		fConst489 = (0.0 - (2.0 * fConst488));
		fConst490 = (cos((86766.839842520829 / fConst0)) * fConst489);
		fConst491 = mydsp_faustpower2_f(fConst488);
		fConst492 = pow(0.001, (1.0 / (0.025532641031199999 * fConst0)));
		fConst493 = (0.0 - (2.0 * fConst492));
		fConst494 = (cos((86836.644218584639 / fConst0)) * fConst493);
		fConst495 = mydsp_faustpower2_f(fConst492);
		fConst496 = pow(0.001, (1.0 / (0.025585781189400001 * fConst0)));
		fConst497 = (0.0 - (2.0 * fConst496));
		fConst498 = (cos((86976.252971340553 / fConst0)) * fConst497);
		fConst499 = mydsp_faustpower2_f(fConst496);
		fConst500 = (fConst493 * cos((87080.959535750429 / fConst0)));
		fConst501 = (fConst489 * cos((87185.666100788614 / fConst0)));
		fConst502 = (fConst489 * cos((87255.47047685241 / fConst0)));
		fConst503 = (fConst489 * cos((87360.177041262286 / fConst0)));
		fConst504 = (fConst497 * cos((87534.687982364267 / fConst0)));
		fConst505 = pow(0.001, (1.0 / (0.025639143692099998 * fConst0)));
		fConst506 = (0.0 - (2.0 * fConst505));
		fConst507 = (cos((87604.492359056399 / fConst0)) * fConst506);
		fConst508 = mydsp_faustpower2_f(fConst505);
		fConst509 = pow(0.001, (1.0 / (0.074578516471100004 * fConst0)));
		fConst510 = (0.0 - (2.0 * fConst509));
		fConst511 = (cos((87674.296735120195 / fConst0)) * fConst510);
		fConst512 = mydsp_faustpower2_f(fConst509);
		fConst513 = (fConst510 * cos((87744.101111812313 / fConst0)));
		fConst514 = pow(0.001, (1.0 / (0.026297357621900001 * fConst0)));
		fConst515 = (cos((87813.905487876109 / fConst0)) * (0.0 - (2.0 * fConst514)));
		fConst516 = mydsp_faustpower2_f(fConst514);
		fConst517 = pow(0.001, (1.0 / (0.079934734156600004 * fConst0)));
		fConst518 = (cos((88058.220805041914 / fConst0)) * (0.0 - (2.0 * fConst517)));
		fConst519 = mydsp_faustpower2_f(fConst517);
		fConst520 = pow(0.001, (1.0 / (0.079416186506800004 * fConst0)));
		fConst521 = (cos((88162.927370080099 / fConst0)) * (0.0 - (2.0 * fConst520)));
		fConst522 = mydsp_faustpower2_f(fConst520);
		fConst523 = pow(0.001, (1.0 / (0.077900177785300007 * fConst0)));
		fConst524 = (cos((88267.633934489961 / fConst0)) * (0.0 - (2.0 * fConst523)));
		fConst525 = mydsp_faustpower2_f(fConst523);
		fConst526 = pow(0.001, (1.0 / (0.076441019409699995 * fConst0)));
		fConst527 = (cos((88442.144875591955 / fConst0)) * (0.0 - (2.0 * fConst526)));
		fConst528 = mydsp_faustpower2_f(fConst526);
		fConst529 = (fConst510 * cos((88581.753628347869 / fConst0)));
		fConst530 = (fConst506 * cos((88651.55800441168 / fConst0)));
		fConst531 = (fConst489 * cos((88826.06894551366 / fConst0)));
		fConst532 = (fConst489 * cos((88895.873322205793 / fConst0)));
		fConst533 = (fConst493 * cos((88965.677698269588 / fConst0)));
		fConst534 = (fConst489 * cos((89035.482074961707 / fConst0)));
		fConst535 = (fConst489 * cos((89314.699580473563 / fConst0)));
		fConst536 = (fConst489 * cos((89384.503956537374 / fConst0)));
		fConst537 = (fConst489 * cos((89489.210520947236 / fConst0)));
		fConst538 = pow(0.001, (1.0 / (0.0194107664379 * fConst0)));
		fConst539 = (0.0 - (2.0 * fConst538));
		fConst540 = (cos((89593.91708598542 / fConst0)) * fConst539);
		fConst541 = mydsp_faustpower2_f(fConst538);
		fConst542 = pow(0.001, (1.0 / (0.0253222762797 * fConst0)));
		fConst543 = (cos((89908.036779215021 / fConst0)) * (0.0 - (2.0 * fConst542)));
		fConst544 = mydsp_faustpower2_f(fConst542);
		fConst545 = pow(0.001, (1.0 / (0.0254270222127 * fConst0)));
		fConst546 = (0.0 - (2.0 * fConst545));
		fConst547 = (cos((90047.645531970949 / fConst0)) * fConst546);
		fConst548 = mydsp_faustpower2_f(fConst545);
		fConst549 = (fConst546 * cos((90117.449908663068 / fConst0)));
		fConst550 = (fConst489 * cos((90222.15647307293 / fConst0)));
		fConst551 = (fConst493 * cos((90291.960849765048 / fConst0)));
		fConst552 = (fConst493 * cos((90361.765225828858 / fConst0)));
		fConst553 = (fConst493 * cos((90431.569602520991 / fConst0)));
		fConst554 = (fConst493 * cos((90501.373978584787 / fConst0)));
		fConst555 = (fConst489 * cos((90606.080542994649 / fConst0)));
		fConst556 = pow(0.001, (1.0 / (0.047992205691000003 * fConst0)));
		fConst557 = (0.0 - (2.0 * fConst556));
		fConst558 = (cos((91199.417742364429 / fConst0)) * fConst557);
		fConst559 = mydsp_faustpower2_f(fConst556);
		fConst560 = pow(0.001, (1.0 / (0.053200225235000002 * fConst0)));
		fConst561 = (0.0 - (2.0 * fConst560));
		fConst562 = (cos((91304.124306774291 / fConst0)) * fConst561);
		fConst563 = mydsp_faustpower2_f(fConst560);
		fConst564 = (fConst561 * cos((91373.928683466409 / fConst0)));
		fConst565 = (fConst561 * cos((91443.733060158527 / fConst0)));
		fConst566 = pow(0.001, (1.0 / (0.16744854417400001 * fConst0)));
		fConst567 = (0.0 - (2.0 * fConst566));
		fConst568 = (cos((92037.070258899985 / fConst0)) * fConst567);
		fConst569 = mydsp_faustpower2_f(fConst566);
		fConst570 = (fConst567 * cos((92106.874635592103 / fConst0)));
		fConst571 = (cos((92386.09214110396 / fConst0)) * fConst8);
		fConst572 = (fConst361 * cos((92665.309646615817 / fConst0)));
		fConst573 = (fConst361 * cos((92770.016211025679 / fConst0)));
		fConst574 = (fConst361 * cos((92874.722775435541 / fConst0)));
		fConst575 = pow(0.001, (1.0 / (0.18243691814900001 * fConst0)));
		fConst576 = (cos((93153.940280947398 / fConst0)) * (0.0 - (2.0 * fConst575)));
		fConst577 = mydsp_faustpower2_f(fConst575);
		fConst578 = (cos((93363.353410395444 / fConst0)) * fConst8);
		fConst579 = (cos((93433.157786459255 / fConst0)) * fConst8);
		fConst580 = (fConst457 * cos((93572.766539215168 / fConst0)));
		fConst581 = pow(0.001, (1.0 / (0.053666205970700001 * fConst0)));
		fConst582 = (0.0 - (2.0 * fConst581));
		fConst583 = (cos((94375.516868032995 / fConst0)) * fConst582);
		fConst584 = mydsp_faustpower2_f(fConst581);
		fConst585 = (fConst561 * cos((94515.125620788924 / fConst0)));
		fConst586 = (fConst561 * cos((94584.929996852719 / fConst0)));
		fConst587 = (fConst561 * cos((94689.636561890919 / fConst0)));
		fConst588 = pow(0.001, (1.0 / (0.052970260718199998 * fConst0)));
		fConst589 = (0.0 - (2.0 * fConst588));
		fConst590 = (cos((94759.440937954714 / fConst0)) * fConst589);
		fConst591 = mydsp_faustpower2_f(fConst588);
		fConst592 = (fConst589 * cos((94829.245314646832 / fConst0)));
		fConst593 = (fConst589 * cos((94899.049690710643 / fConst0)));
		fConst594 = pow(0.001, (1.0 / (0.051849670933399997 * fConst0)));
		fConst595 = (cos((94968.854067402761 / fConst0)) * (0.0 - (2.0 * fConst594)));
		fConst596 = mydsp_faustpower2_f(fConst594);
		fConst597 = pow(0.001, (1.0 / (0.046712066679100002 * fConst0)));
		fConst598 = (cos((95178.267196222499 / fConst0)) * (0.0 - (2.0 * fConst597)));
		fConst599 = mydsp_faustpower2_f(fConst597);
		fConst600 = (fConst557 * cos((95248.071572914618 / fConst0)));
		fConst601 = (fConst561 * cos((95387.680325670546 / fConst0)));
		fConst602 = (fConst582 * cos((95492.386890080408 / fConst0)));
		fConst603 = pow(0.001, (1.0 / (0.053432198176900002 * fConst0)));
		fConst604 = (0.0 - (2.0 * fConst603));
		fConst605 = (cos((95597.09345449027 / fConst0)) * fConst604);
		fConst606 = mydsp_faustpower2_f(fConst603);
		fConst607 = (fConst561 * cos((95771.604395592265 / fConst0)));
		fConst608 = (fConst561 * cos((95841.408771656061 / fConst0)));
		fConst609 = (fConst426 * cos((95946.115336694245 / fConst0)));
		fConst610 = (fConst561 * cos((96190.43065386005 / fConst0)));
		fConst611 = pow(0.001, (1.0 / (0.119862907549 * fConst0)));
		fConst612 = (0.0 - (2.0 * fConst611));
		fConst613 = (cos((96399.843782679774 / fConst0)) * fConst612);
		fConst614 = mydsp_faustpower2_f(fConst611);
		fConst615 = (fConst612 * cos((96469.648159371893 / fConst0)));
		fConst616 = (fConst153 * cos((96679.061288191631 / fConst0)));
		fConst617 = (fConst153 * cos((96783.767853229801 / fConst0)));
		fConst618 = (fConst153 * cos((96888.474417639663 / fConst0)));
		fConst619 = (cos((96993.18098204954 / fConst0)) * fConst24);
		fConst620 = (cos((97062.985358741658 / fConst0)) * fConst24);
		fConst621 = pow(0.001, (1.0 / (0.142148401762 * fConst0)));
		fConst622 = (cos((97272.398487561397 / fConst0)) * (0.0 - (2.0 * fConst621)));
		fConst623 = mydsp_faustpower2_f(fConst621);
		fConst624 = pow(0.001, (1.0 / (0.20037382490799999 * fConst0)));
		fConst625 = (cos((97342.202864253515 / fConst0)) * (0.0 - (2.0 * fConst624)));
		fConst626 = mydsp_faustpower2_f(fConst624);
		fConst627 = (fConst357 * cos((97446.909428663392 / fConst0)));
		fConst628 = (fConst357 * cos((97551.615993073239 / fConst0)));
		fConst629 = (cos((97726.126934175234 / fConst0)) * fConst24);
		fConst630 = (fConst604 * cos((98144.953192443005 / fConst0)));
		fConst631 = (fConst561 * cos((98214.757569135138 / fConst0)));
		fConst632 = (fConst589 * cos((98319.464133545 / fConst0)));
		fConst633 = (fConst557 * cos((98459.072886300928 / fConst0)));
		fConst634 = pow(0.001, (1.0 / (0.046890739607900002 * fConst0)));
		fConst635 = (cos((98563.77945071079 / fConst0)) * (0.0 - (2.0 * fConst634)));
		fConst636 = mydsp_faustpower2_f(fConst634);
		fConst637 = pow(0.001, (1.0 / (0.041355501235400001 * fConst0)));
		fConst638 = (cos((98703.388203466733 / fConst0)) * (0.0 - (2.0 * fConst637)));
		fConst639 = mydsp_faustpower2_f(fConst637);
		fConst640 = pow(0.001, (1.0 / (0.040941350162599997 * fConst0)));
		fConst641 = (0.0 - (2.0 * fConst640));
		fConst642 = (cos((98877.899144568699 / fConst0)) * fConst641);
		fConst643 = mydsp_faustpower2_f(fConst640);
		fConst644 = (fConst497 * cos((99017.507897324642 / fConst0)));
		fConst645 = (fConst497 * cos((99087.312273388437 / fConst0)));
		fConst646 = (fConst641 * cos((99157.116650080556 / fConst0)));
		fConst647 = pow(0.001, (1.0 / (0.026410369937500001 * fConst0)));
		fConst648 = (cos((99226.921026144366 / fConst0)) * (0.0 - (2.0 * fConst647)));
		fConst649 = mydsp_faustpower2_f(fConst647);
		fConst650 = pow(0.001, (1.0 / (0.041216521244700002 * fConst0)));
		fConst651 = (cos((99296.725402836484 / fConst0)) * (0.0 - (2.0 * fConst650)));
		fConst652 = mydsp_faustpower2_f(fConst650);
		fConst653 = (fConst641 * cos((99366.529778900294 / fConst0)));
		fConst654 = (fConst641 * cos((99471.236343938479 / fConst0)));
		fConst655 = (fConst506 * cos((99575.942908348341 / fConst0)));
		fConst656 = (fConst489 * cos((99645.747284412137 / fConst0)));
		fConst657 = (fConst489 * cos((99750.453849450336 / fConst0)));
		fConst658 = (fConst546 * cos((99890.06260220625 / fConst0)));
		fConst659 = (fConst539 * cos((99994.769166616126 / fConst0)));
		fConst660 = (fConst539 * cos((100064.57354267992 / fConst0)));
		fConst661 = pow(0.001, (1.0 / (0.40734580540600002 * fConst0)));
		fConst662 = (0.0 - (2.0 * fConst661));
		fConst663 = (cos((102647.33546897872 / fConst0)) * fConst662);
		fConst664 = mydsp_faustpower2_f(fConst661);
		fConst665 = pow(0.001, (1.0 / (0.29098367721200002 * fConst0)));
		fConst666 = (cos((102752.0420333886 / fConst0)) * (0.0 - (2.0 * fConst665)));
		fConst667 = mydsp_faustpower2_f(fConst665);
		fConst668 = (fConst662 * cos((102856.74859842678 / fConst0)));
		
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
		for (int l230 = 0; (l230 < 3); l230 = (l230 + 1)) {
			fRec230[l230] = 0.0;
			
		}
		for (int l231 = 0; (l231 < 3); l231 = (l231 + 1)) {
			fRec231[l231] = 0.0;
			
		}
		for (int l232 = 0; (l232 < 3); l232 = (l232 + 1)) {
			fRec232[l232] = 0.0;
			
		}
		for (int l233 = 0; (l233 < 3); l233 = (l233 + 1)) {
			fRec233[l233] = 0.0;
			
		}
		for (int l234 = 0; (l234 < 3); l234 = (l234 + 1)) {
			fRec234[l234] = 0.0;
			
		}
		for (int l235 = 0; (l235 < 3); l235 = (l235 + 1)) {
			fRec235[l235] = 0.0;
			
		}
		for (int l236 = 0; (l236 < 3); l236 = (l236 + 1)) {
			fRec236[l236] = 0.0;
			
		}
		for (int l237 = 0; (l237 < 3); l237 = (l237 + 1)) {
			fRec237[l237] = 0.0;
			
		}
		for (int l238 = 0; (l238 < 3); l238 = (l238 + 1)) {
			fRec238[l238] = 0.0;
			
		}
		for (int l239 = 0; (l239 < 3); l239 = (l239 + 1)) {
			fRec239[l239] = 0.0;
			
		}
		for (int l240 = 0; (l240 < 3); l240 = (l240 + 1)) {
			fRec240[l240] = 0.0;
			
		}
		for (int l241 = 0; (l241 < 3); l241 = (l241 + 1)) {
			fRec241[l241] = 0.0;
			
		}
		for (int l242 = 0; (l242 < 3); l242 = (l242 + 1)) {
			fRec242[l242] = 0.0;
			
		}
		for (int l243 = 0; (l243 < 3); l243 = (l243 + 1)) {
			fRec243[l243] = 0.0;
			
		}
		for (int l244 = 0; (l244 < 3); l244 = (l244 + 1)) {
			fRec244[l244] = 0.0;
			
		}
		for (int l245 = 0; (l245 < 3); l245 = (l245 + 1)) {
			fRec245[l245] = 0.0;
			
		}
		for (int l246 = 0; (l246 < 3); l246 = (l246 + 1)) {
			fRec246[l246] = 0.0;
			
		}
		for (int l247 = 0; (l247 < 3); l247 = (l247 + 1)) {
			fRec247[l247] = 0.0;
			
		}
		for (int l248 = 0; (l248 < 3); l248 = (l248 + 1)) {
			fRec248[l248] = 0.0;
			
		}
		for (int l249 = 0; (l249 < 3); l249 = (l249 + 1)) {
			fRec249[l249] = 0.0;
			
		}
		for (int l250 = 0; (l250 < 3); l250 = (l250 + 1)) {
			fRec250[l250] = 0.0;
			
		}
		for (int l251 = 0; (l251 < 3); l251 = (l251 + 1)) {
			fRec251[l251] = 0.0;
			
		}
		for (int l252 = 0; (l252 < 3); l252 = (l252 + 1)) {
			fRec252[l252] = 0.0;
			
		}
		for (int l253 = 0; (l253 < 3); l253 = (l253 + 1)) {
			fRec253[l253] = 0.0;
			
		}
		for (int l254 = 0; (l254 < 3); l254 = (l254 + 1)) {
			fRec254[l254] = 0.0;
			
		}
		for (int l255 = 0; (l255 < 3); l255 = (l255 + 1)) {
			fRec255[l255] = 0.0;
			
		}
		for (int l256 = 0; (l256 < 3); l256 = (l256 + 1)) {
			fRec256[l256] = 0.0;
			
		}
		for (int l257 = 0; (l257 < 3); l257 = (l257 + 1)) {
			fRec257[l257] = 0.0;
			
		}
		for (int l258 = 0; (l258 < 3); l258 = (l258 + 1)) {
			fRec258[l258] = 0.0;
			
		}
		for (int l259 = 0; (l259 < 3); l259 = (l259 + 1)) {
			fRec259[l259] = 0.0;
			
		}
		for (int l260 = 0; (l260 < 3); l260 = (l260 + 1)) {
			fRec260[l260] = 0.0;
			
		}
		for (int l261 = 0; (l261 < 3); l261 = (l261 + 1)) {
			fRec261[l261] = 0.0;
			
		}
		for (int l262 = 0; (l262 < 3); l262 = (l262 + 1)) {
			fRec262[l262] = 0.0;
			
		}
		for (int l263 = 0; (l263 < 3); l263 = (l263 + 1)) {
			fRec263[l263] = 0.0;
			
		}
		for (int l264 = 0; (l264 < 3); l264 = (l264 + 1)) {
			fRec264[l264] = 0.0;
			
		}
		for (int l265 = 0; (l265 < 3); l265 = (l265 + 1)) {
			fRec265[l265] = 0.0;
			
		}
		for (int l266 = 0; (l266 < 3); l266 = (l266 + 1)) {
			fRec266[l266] = 0.0;
			
		}
		for (int l267 = 0; (l267 < 3); l267 = (l267 + 1)) {
			fRec267[l267] = 0.0;
			
		}
		for (int l268 = 0; (l268 < 3); l268 = (l268 + 1)) {
			fRec268[l268] = 0.0;
			
		}
		for (int l269 = 0; (l269 < 3); l269 = (l269 + 1)) {
			fRec269[l269] = 0.0;
			
		}
		for (int l270 = 0; (l270 < 3); l270 = (l270 + 1)) {
			fRec270[l270] = 0.0;
			
		}
		for (int l271 = 0; (l271 < 3); l271 = (l271 + 1)) {
			fRec271[l271] = 0.0;
			
		}
		for (int l272 = 0; (l272 < 3); l272 = (l272 + 1)) {
			fRec272[l272] = 0.0;
			
		}
		for (int l273 = 0; (l273 < 3); l273 = (l273 + 1)) {
			fRec273[l273] = 0.0;
			
		}
		for (int l274 = 0; (l274 < 3); l274 = (l274 + 1)) {
			fRec274[l274] = 0.0;
			
		}
		for (int l275 = 0; (l275 < 3); l275 = (l275 + 1)) {
			fRec275[l275] = 0.0;
			
		}
		for (int l276 = 0; (l276 < 3); l276 = (l276 + 1)) {
			fRec276[l276] = 0.0;
			
		}
		for (int l277 = 0; (l277 < 3); l277 = (l277 + 1)) {
			fRec277[l277] = 0.0;
			
		}
		for (int l278 = 0; (l278 < 3); l278 = (l278 + 1)) {
			fRec278[l278] = 0.0;
			
		}
		for (int l279 = 0; (l279 < 3); l279 = (l279 + 1)) {
			fRec279[l279] = 0.0;
			
		}
		for (int l280 = 0; (l280 < 3); l280 = (l280 + 1)) {
			fRec280[l280] = 0.0;
			
		}
		for (int l281 = 0; (l281 < 3); l281 = (l281 + 1)) {
			fRec281[l281] = 0.0;
			
		}
		for (int l282 = 0; (l282 < 3); l282 = (l282 + 1)) {
			fRec282[l282] = 0.0;
			
		}
		for (int l283 = 0; (l283 < 3); l283 = (l283 + 1)) {
			fRec283[l283] = 0.0;
			
		}
		for (int l284 = 0; (l284 < 3); l284 = (l284 + 1)) {
			fRec284[l284] = 0.0;
			
		}
		for (int l285 = 0; (l285 < 3); l285 = (l285 + 1)) {
			fRec285[l285] = 0.0;
			
		}
		for (int l286 = 0; (l286 < 3); l286 = (l286 + 1)) {
			fRec286[l286] = 0.0;
			
		}
		for (int l287 = 0; (l287 < 3); l287 = (l287 + 1)) {
			fRec287[l287] = 0.0;
			
		}
		for (int l288 = 0; (l288 < 3); l288 = (l288 + 1)) {
			fRec288[l288] = 0.0;
			
		}
		for (int l289 = 0; (l289 < 3); l289 = (l289 + 1)) {
			fRec289[l289] = 0.0;
			
		}
		for (int l290 = 0; (l290 < 3); l290 = (l290 + 1)) {
			fRec290[l290] = 0.0;
			
		}
		for (int l291 = 0; (l291 < 3); l291 = (l291 + 1)) {
			fRec291[l291] = 0.0;
			
		}
		for (int l292 = 0; (l292 < 3); l292 = (l292 + 1)) {
			fRec292[l292] = 0.0;
			
		}
		for (int l293 = 0; (l293 < 3); l293 = (l293 + 1)) {
			fRec293[l293] = 0.0;
			
		}
		for (int l294 = 0; (l294 < 3); l294 = (l294 + 1)) {
			fRec294[l294] = 0.0;
			
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
		ui_interface->openVerticalBox("cabinetRandallExcelTreble");
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
			fRec0[0] = (fTemp1 - ((fConst2 * fRec0[1]) + (fConst3 * fRec0[2])));
			fRec1[0] = (fTemp1 - ((fConst5 * fRec1[1]) + (fConst6 * fRec1[2])));
			fRec2[0] = (fTemp1 - ((fConst9 * fRec2[1]) + (fConst10 * fRec2[2])));
			fRec3[0] = (fTemp1 - ((fConst13 * fRec3[1]) + (fConst14 * fRec3[2])));
			fRec4[0] = (fTemp1 - ((fConst15 * fRec4[1]) + (fConst14 * fRec4[2])));
			fRec5[0] = (fTemp1 - ((fConst18 * fRec5[1]) + (fConst19 * fRec5[2])));
			fRec6[0] = (fTemp1 - ((fConst21 * fRec6[1]) + (fConst22 * fRec6[2])));
			fRec7[0] = (fTemp1 - ((fConst25 * fRec7[1]) + (fConst26 * fRec7[2])));
			fRec8[0] = (fTemp1 - ((fConst28 * fRec8[1]) + (fConst29 * fRec8[2])));
			fRec9[0] = (fTemp1 - ((fConst32 * fRec9[1]) + (fConst33 * fRec9[2])));
			fRec10[0] = (fTemp1 - ((fConst34 * fRec10[1]) + (fConst33 * fRec10[2])));
			fRec11[0] = (fTemp1 - ((fConst36 * fRec11[1]) + (fConst37 * fRec11[2])));
			fRec12[0] = (fTemp1 - ((fConst40 * fRec12[1]) + (fConst41 * fRec12[2])));
			fRec13[0] = (fTemp1 - ((fConst42 * fRec13[1]) + (fConst41 * fRec13[2])));
			fRec14[0] = (fTemp1 - ((fConst43 * fRec14[1]) + (fConst41 * fRec14[2])));
			fRec15[0] = (fTemp1 - ((fConst45 * fRec15[1]) + (fConst46 * fRec15[2])));
			fRec16[0] = (fTemp1 - ((fConst49 * fRec16[1]) + (fConst50 * fRec16[2])));
			fRec17[0] = (fTemp1 - ((fConst53 * fRec17[1]) + (fConst54 * fRec17[2])));
			fRec18[0] = (fTemp1 - ((fConst55 * fRec18[1]) + (fConst54 * fRec18[2])));
			fRec19[0] = (fTemp1 - ((fConst58 * fRec19[1]) + (fConst59 * fRec19[2])));
			fRec20[0] = (fTemp1 - ((fConst62 * fRec20[1]) + (fConst63 * fRec20[2])));
			fRec21[0] = (fTemp1 - ((fConst64 * fRec21[1]) + (fConst63 * fRec21[2])));
			fRec22[0] = (fTemp1 - ((fConst66 * fRec22[1]) + (fConst67 * fRec22[2])));
			fRec23[0] = (fTemp1 - ((fConst70 * fRec23[1]) + (fConst71 * fRec23[2])));
			fRec24[0] = (fTemp1 - ((fConst74 * fRec24[1]) + (fConst75 * fRec24[2])));
			fRec25[0] = (fTemp1 - ((fConst77 * fRec25[1]) + (fConst78 * fRec25[2])));
			fRec26[0] = (fTemp1 - ((fConst79 * fRec26[1]) + (fConst19 * fRec26[2])));
			fRec27[0] = (fTemp1 - ((fConst81 * fRec27[1]) + (fConst82 * fRec27[2])));
			fRec28[0] = (fTemp1 - ((fConst84 * fRec28[1]) + (fConst85 * fRec28[2])));
			fRec29[0] = (fTemp1 - ((fConst88 * fRec29[1]) + (fConst89 * fRec29[2])));
			fRec30[0] = (fTemp1 - ((fConst91 * fRec30[1]) + (fConst92 * fRec30[2])));
			fRec31[0] = (fTemp1 - ((fConst94 * fRec31[1]) + (fConst95 * fRec31[2])));
			fRec32[0] = (fTemp1 - ((fConst98 * fRec32[1]) + (fConst99 * fRec32[2])));
			fRec33[0] = (fTemp1 - ((fConst102 * fRec33[1]) + (fConst103 * fRec33[2])));
			fRec34[0] = (fTemp1 - ((fConst105 * fRec34[1]) + (fConst106 * fRec34[2])));
			fRec35[0] = (fTemp1 - ((fConst108 * fRec35[1]) + (fConst109 * fRec35[2])));
			fRec36[0] = (fTemp1 - ((fConst112 * fRec36[1]) + (fConst113 * fRec36[2])));
			fRec37[0] = (fTemp1 - ((fConst114 * fRec37[1]) + (fConst113 * fRec37[2])));
			fRec38[0] = (fTemp1 - ((fConst116 * fRec38[1]) + (fConst117 * fRec38[2])));
			fRec39[0] = (fTemp1 - ((fConst119 * fRec39[1]) + (fConst120 * fRec39[2])));
			fRec40[0] = (fTemp1 - ((fConst123 * fRec40[1]) + (fConst124 * fRec40[2])));
			fRec41[0] = (fTemp1 - ((fConst126 * fRec41[1]) + (fConst127 * fRec41[2])));
			fRec42[0] = (fTemp1 - ((fConst129 * fRec42[1]) + (fConst130 * fRec42[2])));
			fRec43[0] = (fTemp1 - ((fConst131 * fRec43[1]) + (fConst124 * fRec43[2])));
			fRec44[0] = (fTemp1 - ((fConst132 * fRec44[1]) + (fConst71 * fRec44[2])));
			fRec45[0] = (fTemp1 - ((fConst134 * fRec45[1]) + (fConst135 * fRec45[2])));
			fRec46[0] = (fTemp1 - ((fConst136 * fRec46[1]) + (fConst71 * fRec46[2])));
			fRec47[0] = (fTemp1 - ((fConst137 * fRec47[1]) + (fConst103 * fRec47[2])));
			fRec48[0] = (fTemp1 - ((fConst138 * fRec48[1]) + (fConst103 * fRec48[2])));
			fRec49[0] = (fTemp1 - ((fConst141 * fRec49[1]) + (fConst142 * fRec49[2])));
			fRec50[0] = (fTemp1 - ((fConst145 * fRec50[1]) + (fConst146 * fRec50[2])));
			fRec51[0] = (fTemp1 - ((fConst149 * fRec51[1]) + (fConst150 * fRec51[2])));
			fRec52[0] = (fTemp1 - ((fConst151 * fRec52[1]) + (fConst89 * fRec52[2])));
			fRec53[0] = (fTemp1 - ((fConst154 * fRec53[1]) + (fConst155 * fRec53[2])));
			fRec54[0] = (fTemp1 - ((fConst156 * fRec54[1]) + (fConst89 * fRec54[2])));
			fRec55[0] = (fTemp1 - ((fConst157 * fRec55[1]) + (fConst75 * fRec55[2])));
			fRec56[0] = (fTemp1 - ((fConst158 * fRec56[1]) + (fConst99 * fRec56[2])));
			fRec57[0] = (fTemp1 - ((fConst159 * fRec57[1]) + (fConst75 * fRec57[2])));
			fRec58[0] = (fTemp1 - ((fConst161 * fRec58[1]) + (fConst162 * fRec58[2])));
			fRec59[0] = (fTemp1 - ((fConst163 * fRec59[1]) + (fConst71 * fRec59[2])));
			fRec60[0] = (fTemp1 - ((fConst165 * fRec60[1]) + (fConst166 * fRec60[2])));
			fRec61[0] = (fTemp1 - ((fConst168 * fRec61[1]) + (fConst169 * fRec61[2])));
			fRec62[0] = (fTemp1 - ((fConst170 * fRec62[1]) + (fConst99 * fRec62[2])));
			fRec63[0] = (fTemp1 - ((fConst171 * fRec63[1]) + (fConst99 * fRec63[2])));
			fRec64[0] = (fTemp1 - ((fConst174 * fRec64[1]) + (fConst175 * fRec64[2])));
			fRec65[0] = (fTemp1 - ((fConst176 * fRec65[1]) + (fConst175 * fRec65[2])));
			fRec66[0] = (fTemp1 - ((fConst178 * fRec66[1]) + (fConst179 * fRec66[2])));
			fRec67[0] = (fTemp1 - ((fConst181 * fRec67[1]) + (fConst182 * fRec67[2])));
			fRec68[0] = (fTemp1 - ((fConst184 * fRec68[1]) + (fConst185 * fRec68[2])));
			fRec69[0] = (fTemp1 - ((fConst187 * fRec69[1]) + (fConst188 * fRec69[2])));
			fRec70[0] = (fTemp1 - ((fConst190 * fRec70[1]) + (fConst191 * fRec70[2])));
			fRec71[0] = (fTemp1 - ((fConst194 * fRec71[1]) + (fConst195 * fRec71[2])));
			fRec72[0] = (fTemp1 - ((fConst196 * fRec72[1]) + (fConst195 * fRec72[2])));
			fRec73[0] = (fTemp1 - ((fConst199 * fRec73[1]) + (fConst200 * fRec73[2])));
			fRec74[0] = (fTemp1 - ((fConst202 * fRec74[1]) + (fConst203 * fRec74[2])));
			fRec75[0] = (fTemp1 - ((fConst205 * fRec75[1]) + (fConst206 * fRec75[2])));
			fRec76[0] = (fTemp1 - ((fConst208 * fRec76[1]) + (fConst209 * fRec76[2])));
			fRec77[0] = (fTemp1 - ((fConst210 * fRec77[1]) + (fConst195 * fRec77[2])));
			fRec78[0] = (fTemp1 - ((fConst211 * fRec78[1]) + (fConst200 * fRec78[2])));
			fRec79[0] = (fTemp1 - ((fConst214 * fRec79[1]) + (fConst215 * fRec79[2])));
			fRec80[0] = (fTemp1 - ((fConst216 * fRec80[1]) + (fConst215 * fRec80[2])));
			fRec81[0] = (fTemp1 - ((fConst218 * fRec81[1]) + (fConst219 * fRec81[2])));
			fRec82[0] = (fTemp1 - ((fConst221 * fRec82[1]) + (fConst222 * fRec82[2])));
			fRec83[0] = (fTemp1 - ((fConst224 * fRec83[1]) + (fConst225 * fRec83[2])));
			fRec84[0] = (fTemp1 - ((fConst227 * fRec84[1]) + (fConst228 * fRec84[2])));
			fRec85[0] = (fTemp1 - ((fConst230 * fRec85[1]) + (fConst231 * fRec85[2])));
			fRec86[0] = (fTemp1 - ((fConst233 * fRec86[1]) + (fConst234 * fRec86[2])));
			fRec87[0] = (fTemp1 - ((fConst236 * fRec87[1]) + (fConst237 * fRec87[2])));
			fRec88[0] = (fTemp1 - ((fConst239 * fRec88[1]) + (fConst240 * fRec88[2])));
			fRec89[0] = (fTemp1 - ((fConst242 * fRec89[1]) + (fConst243 * fRec89[2])));
			fRec90[0] = (fTemp1 - ((fConst245 * fRec90[1]) + (fConst246 * fRec90[2])));
			fRec91[0] = (fTemp1 - ((fConst249 * fRec91[1]) + (fConst250 * fRec91[2])));
			fRec92[0] = (fTemp1 - ((fConst251 * fRec92[1]) + (fConst250 * fRec92[2])));
			fRec93[0] = (fTemp1 - ((fConst253 * fRec93[1]) + (fConst254 * fRec93[2])));
			fRec94[0] = (fTemp1 - ((fConst257 * fRec94[1]) + (fConst258 * fRec94[2])));
			fRec95[0] = (fTemp1 - ((fConst259 * fRec95[1]) + (fConst258 * fRec95[2])));
			fRec96[0] = (fTemp1 - ((fConst261 * fRec96[1]) + (fConst262 * fRec96[2])));
			fRec97[0] = (fTemp1 - ((fConst264 * fRec97[1]) + (fConst265 * fRec97[2])));
			fRec98[0] = (fTemp1 - ((fConst267 * fRec98[1]) + (fConst268 * fRec98[2])));
			fRec99[0] = (fTemp1 - ((fConst270 * fRec99[1]) + (fConst271 * fRec99[2])));
			fRec100[0] = (fTemp1 - ((fConst274 * fRec100[1]) + (fConst275 * fRec100[2])));
			fRec101[0] = (fTemp1 - ((fConst276 * fRec101[1]) + (fConst275 * fRec101[2])));
			fRec102[0] = (fTemp1 - ((fConst278 * fRec102[1]) + (fConst279 * fRec102[2])));
			fRec103[0] = (fTemp1 - ((fConst281 * fRec103[1]) + (fConst282 * fRec103[2])));
			fRec104[0] = (fTemp1 - ((fConst285 * fRec104[1]) + (fConst286 * fRec104[2])));
			fRec105[0] = (fTemp1 - ((fConst287 * fRec105[1]) + (fConst150 * fRec105[2])));
			fRec106[0] = (fTemp1 - ((fConst290 * fRec106[1]) + (fConst291 * fRec106[2])));
			fRec107[0] = (fTemp1 - ((fConst292 * fRec107[1]) + (fConst291 * fRec107[2])));
			fRec108[0] = (fTemp1 - ((fConst293 * fRec108[1]) + (fConst146 * fRec108[2])));
			fRec109[0] = (fTemp1 - ((fConst294 * fRec109[1]) + (fConst146 * fRec109[2])));
			fRec110[0] = (fTemp1 - ((fConst296 * fRec110[1]) + (fConst297 * fRec110[2])));
			fRec111[0] = (fTemp1 - ((fConst299 * fRec111[1]) + (fConst300 * fRec111[2])));
			fRec112[0] = (fTemp1 - ((fConst303 * fRec112[1]) + (fConst304 * fRec112[2])));
			fRec113[0] = (fTemp1 - ((fConst305 * fRec113[1]) + (fConst304 * fRec113[2])));
			fRec114[0] = (fTemp1 - ((fConst306 * fRec114[1]) + (fConst304 * fRec114[2])));
			fRec115[0] = (fTemp1 - ((fConst307 * fRec115[1]) + (fConst304 * fRec115[2])));
			fRec116[0] = (fTemp1 - ((fConst309 * fRec116[1]) + (fConst310 * fRec116[2])));
			fRec117[0] = (fTemp1 - ((fConst312 * fRec117[1]) + (fConst313 * fRec117[2])));
			fRec118[0] = (fTemp1 - ((fConst315 * fRec118[1]) + (fConst316 * fRec118[2])));
			fRec119[0] = (fTemp1 - ((fConst317 * fRec119[1]) + (fConst50 * fRec119[2])));
			fRec120[0] = (fTemp1 - ((fConst318 * fRec120[1]) + (fConst59 * fRec120[2])));
			fRec121[0] = (fTemp1 - ((fConst321 * fRec121[1]) + (fConst322 * fRec121[2])));
			fRec122[0] = (fTemp1 - ((fConst323 * fRec122[1]) + (fConst322 * fRec122[2])));
			fRec123[0] = (fTemp1 - ((fConst325 * fRec123[1]) + (fConst326 * fRec123[2])));
			fRec124[0] = (fTemp1 - ((fConst328 * fRec124[1]) + (fConst329 * fRec124[2])));
			fRec125[0] = (fTemp1 - ((fConst332 * fRec125[1]) + (fConst333 * fRec125[2])));
			fRec126[0] = (fTemp1 - ((fConst334 * fRec126[1]) + (fConst333 * fRec126[2])));
			fRec127[0] = (fTemp1 - ((fConst335 * fRec127[1]) + (fConst333 * fRec127[2])));
			fRec128[0] = (fTemp1 - ((fConst336 * fRec128[1]) + (fConst89 * fRec128[2])));
			fRec129[0] = (fTemp1 - ((fConst338 * fRec129[1]) + (fConst339 * fRec129[2])));
			fRec130[0] = (fTemp1 - ((fConst342 * fRec130[1]) + (fConst343 * fRec130[2])));
			fRec131[0] = (fTemp1 - ((fConst345 * fRec131[1]) + (fConst346 * fRec131[2])));
			fRec132[0] = (fTemp1 - ((fConst348 * fRec132[1]) + (fConst349 * fRec132[2])));
			fRec133[0] = (fTemp1 - ((fConst351 * fRec133[1]) + (fConst352 * fRec133[2])));
			fRec134[0] = (fTemp1 - ((fConst354 * fRec134[1]) + (fConst355 * fRec134[2])));
			fRec135[0] = (fTemp1 - ((fConst358 * fRec135[1]) + (fConst359 * fRec135[2])));
			fRec136[0] = (fTemp1 - ((fConst362 * fRec136[1]) + (fConst363 * fRec136[2])));
			fRec137[0] = (fTemp1 - ((fConst365 * fRec137[1]) + (fConst366 * fRec137[2])));
			fRec138[0] = (fTemp1 - ((fConst367 * fRec138[1]) + (fConst175 * fRec138[2])));
			fRec139[0] = (fTemp1 - ((fConst369 * fRec139[1]) + (fConst370 * fRec139[2])));
			fRec140[0] = (fTemp1 - ((fConst372 * fRec140[1]) + (fConst373 * fRec140[2])));
			fRec141[0] = (fTemp1 - ((fConst376 * fRec141[1]) + (fConst377 * fRec141[2])));
			fRec142[0] = (fTemp1 - ((fConst378 * fRec142[1]) + (fConst377 * fRec142[2])));
			fRec143[0] = (fTemp1 - ((fConst379 * fRec143[1]) + (fConst377 * fRec143[2])));
			fRec144[0] = (fTemp1 - ((fConst382 * fRec144[1]) + (fConst383 * fRec144[2])));
			fRec145[0] = (fTemp1 - ((fConst384 * fRec145[1]) + (fConst383 * fRec145[2])));
			fRec146[0] = (fTemp1 - ((fConst386 * fRec146[1]) + (fConst387 * fRec146[2])));
			fRec147[0] = (fTemp1 - ((fConst389 * fRec147[1]) + (fConst390 * fRec147[2])));
			fRec148[0] = (fTemp1 - ((fConst392 * fRec148[1]) + (fConst393 * fRec148[2])));
			fRec149[0] = (fTemp1 - ((fConst396 * fRec149[1]) + (fConst397 * fRec149[2])));
			fRec150[0] = (fTemp1 - ((fConst398 * fRec150[1]) + (fConst397 * fRec150[2])));
			fRec151[0] = (fTemp1 - ((fConst400 * fRec151[1]) + (fConst401 * fRec151[2])));
			fRec152[0] = (fTemp1 - ((fConst402 * fRec152[1]) + (fConst291 * fRec152[2])));
			fRec153[0] = (fTemp1 - ((fConst403 * fRec153[1]) + (fConst286 * fRec153[2])));
			fRec154[0] = (fTemp1 - ((fConst404 * fRec154[1]) + (fConst89 * fRec154[2])));
			fRec155[0] = (fTemp1 - ((fConst407 * fRec155[1]) + (fConst408 * fRec155[2])));
			fRec156[0] = (fTemp1 - ((fConst409 * fRec156[1]) + (fConst408 * fRec156[2])));
			fRec157[0] = (fTemp1 - ((fConst411 * fRec157[1]) + (fConst412 * fRec157[2])));
			fRec158[0] = (fTemp1 - ((fConst414 * fRec158[1]) + (fConst415 * fRec158[2])));
			fRec159[0] = (fTemp1 - ((fConst416 * fRec159[1]) + (fConst142 * fRec159[2])));
			fRec160[0] = (fTemp1 - ((fConst417 * fRec160[1]) + (fConst142 * fRec160[2])));
			fRec161[0] = (fTemp1 - ((fConst418 * fRec161[1]) + (fConst343 * fRec161[2])));
			fRec162[0] = (fTemp1 - ((fConst420 * fRec162[1]) + (fConst421 * fRec162[2])));
			fRec163[0] = (fTemp1 - ((fConst423 * fRec163[1]) + (fConst424 * fRec163[2])));
			fRec164[0] = (fTemp1 - ((fConst427 * fRec164[1]) + (fConst428 * fRec164[2])));
			fRec165[0] = (fTemp1 - ((fConst429 * fRec165[1]) + (fConst428 * fRec165[2])));
			fRec166[0] = (fTemp1 - ((fConst432 * fRec166[1]) + (fConst433 * fRec166[2])));
			fRec167[0] = (fTemp1 - ((fConst434 * fRec167[1]) + (fConst433 * fRec167[2])));
			fRec168[0] = (fTemp1 - ((fConst435 * fRec168[1]) + (fConst428 * fRec168[2])));
			fRec169[0] = (fTemp1 - ((fConst436 * fRec169[1]) + (fConst428 * fRec169[2])));
			fRec170[0] = (fTemp1 - ((fConst437 * fRec170[1]) + (fConst428 * fRec170[2])));
			fRec171[0] = (fTemp1 - ((fConst438 * fRec171[1]) + (fConst428 * fRec171[2])));
			fRec172[0] = (fTemp1 - ((fConst440 * fRec172[1]) + (fConst441 * fRec172[2])));
			fRec173[0] = (fTemp1 - ((fConst442 * fRec173[1]) + (fConst428 * fRec173[2])));
			fRec174[0] = (fTemp1 - ((fConst444 * fRec174[1]) + (fConst445 * fRec174[2])));
			fRec175[0] = (fTemp1 - ((fConst446 * fRec175[1]) + (fConst428 * fRec175[2])));
			fRec176[0] = (fTemp1 - ((fConst448 * fRec176[1]) + (fConst449 * fRec176[2])));
			fRec177[0] = (fTemp1 - ((fConst451 * fRec177[1]) + (fConst452 * fRec177[2])));
			fRec178[0] = (fTemp1 - ((fConst454 * fRec178[1]) + (fConst455 * fRec178[2])));
			fRec179[0] = (fTemp1 - ((fConst458 * fRec179[1]) + (fConst459 * fRec179[2])));
			fRec180[0] = (fTemp1 - ((fConst462 * fRec180[1]) + (fConst463 * fRec180[2])));
			fRec181[0] = (fTemp1 - ((fConst465 * fRec181[1]) + (fConst466 * fRec181[2])));
			fRec182[0] = (fTemp1 - ((fConst467 * fRec182[1]) + (fConst146 * fRec182[2])));
			fRec183[0] = (fTemp1 - ((fConst469 * fRec183[1]) + (fConst470 * fRec183[2])));
			fRec184[0] = (fTemp1 - ((fConst473 * fRec184[1]) + (fConst474 * fRec184[2])));
			fRec185[0] = (fTemp1 - ((fConst475 * fRec185[1]) + (fConst463 * fRec185[2])));
			fRec186[0] = (fTemp1 - ((fConst477 * fRec186[1]) + (fConst478 * fRec186[2])));
			fRec187[0] = (fTemp1 - ((fConst479 * fRec187[1]) + (fConst463 * fRec187[2])));
			fRec188[0] = (fTemp1 - ((fConst480 * fRec188[1]) + (fConst463 * fRec188[2])));
			fRec189[0] = (fTemp1 - ((fConst481 * fRec189[1]) + (fConst463 * fRec189[2])));
			fRec190[0] = (fTemp1 - ((fConst483 * fRec190[1]) + (fConst484 * fRec190[2])));
			fRec191[0] = (fTemp1 - ((fConst485 * fRec191[1]) + (fConst474 * fRec191[2])));
			fRec192[0] = (fTemp1 - ((fConst486 * fRec192[1]) + (fConst474 * fRec192[2])));
			fRec193[0] = (fTemp1 - ((fConst487 * fRec193[1]) + (fConst474 * fRec193[2])));
			fRec194[0] = (fTemp1 - ((fConst490 * fRec194[1]) + (fConst491 * fRec194[2])));
			fRec195[0] = (fTemp1 - ((fConst494 * fRec195[1]) + (fConst495 * fRec195[2])));
			fRec196[0] = (fTemp1 - ((fConst498 * fRec196[1]) + (fConst499 * fRec196[2])));
			fRec197[0] = (fTemp1 - ((fConst500 * fRec197[1]) + (fConst495 * fRec197[2])));
			fRec198[0] = (fTemp1 - ((fConst501 * fRec198[1]) + (fConst491 * fRec198[2])));
			fRec199[0] = (fTemp1 - ((fConst502 * fRec199[1]) + (fConst491 * fRec199[2])));
			fRec200[0] = (fTemp1 - ((fConst503 * fRec200[1]) + (fConst491 * fRec200[2])));
			fRec201[0] = (fTemp1 - ((fConst504 * fRec201[1]) + (fConst499 * fRec201[2])));
			fRec202[0] = (fTemp1 - ((fConst507 * fRec202[1]) + (fConst508 * fRec202[2])));
			fRec203[0] = (fTemp1 - ((fConst511 * fRec203[1]) + (fConst512 * fRec203[2])));
			fRec204[0] = (fTemp1 - ((fConst513 * fRec204[1]) + (fConst512 * fRec204[2])));
			fRec205[0] = (fTemp1 - ((fConst515 * fRec205[1]) + (fConst516 * fRec205[2])));
			fRec206[0] = (fTemp1 - ((fConst518 * fRec206[1]) + (fConst519 * fRec206[2])));
			fRec207[0] = (fTemp1 - ((fConst521 * fRec207[1]) + (fConst522 * fRec207[2])));
			fRec208[0] = (fTemp1 - ((fConst524 * fRec208[1]) + (fConst525 * fRec208[2])));
			fRec209[0] = (fTemp1 - ((fConst527 * fRec209[1]) + (fConst528 * fRec209[2])));
			fRec210[0] = (fTemp1 - ((fConst529 * fRec210[1]) + (fConst512 * fRec210[2])));
			fRec211[0] = (fTemp1 - ((fConst530 * fRec211[1]) + (fConst508 * fRec211[2])));
			fRec212[0] = (fTemp1 - ((fConst531 * fRec212[1]) + (fConst491 * fRec212[2])));
			fRec213[0] = (fTemp1 - ((fConst532 * fRec213[1]) + (fConst491 * fRec213[2])));
			fRec214[0] = (fTemp1 - ((fConst533 * fRec214[1]) + (fConst495 * fRec214[2])));
			fRec215[0] = (fTemp1 - ((fConst534 * fRec215[1]) + (fConst491 * fRec215[2])));
			fRec216[0] = (fTemp1 - ((fConst535 * fRec216[1]) + (fConst491 * fRec216[2])));
			fRec217[0] = (fTemp1 - ((fConst536 * fRec217[1]) + (fConst491 * fRec217[2])));
			fRec218[0] = (fTemp1 - ((fConst537 * fRec218[1]) + (fConst491 * fRec218[2])));
			fRec219[0] = (fTemp1 - ((fConst540 * fRec219[1]) + (fConst541 * fRec219[2])));
			fRec220[0] = (fTemp1 - ((fConst543 * fRec220[1]) + (fConst544 * fRec220[2])));
			fRec221[0] = (fTemp1 - ((fConst547 * fRec221[1]) + (fConst548 * fRec221[2])));
			fRec222[0] = (fTemp1 - ((fConst549 * fRec222[1]) + (fConst548 * fRec222[2])));
			fRec223[0] = (fTemp1 - ((fConst550 * fRec223[1]) + (fConst491 * fRec223[2])));
			fRec224[0] = (fTemp1 - ((fConst551 * fRec224[1]) + (fConst495 * fRec224[2])));
			fRec225[0] = (fTemp1 - ((fConst552 * fRec225[1]) + (fConst495 * fRec225[2])));
			fRec226[0] = (fTemp1 - ((fConst553 * fRec226[1]) + (fConst495 * fRec226[2])));
			fRec227[0] = (fTemp1 - ((fConst554 * fRec227[1]) + (fConst495 * fRec227[2])));
			fRec228[0] = (fTemp1 - ((fConst555 * fRec228[1]) + (fConst491 * fRec228[2])));
			fRec229[0] = (fTemp1 - ((fConst558 * fRec229[1]) + (fConst559 * fRec229[2])));
			fRec230[0] = (fTemp1 - ((fConst562 * fRec230[1]) + (fConst563 * fRec230[2])));
			fRec231[0] = (fTemp1 - ((fConst564 * fRec231[1]) + (fConst563 * fRec231[2])));
			fRec232[0] = (fTemp1 - ((fConst565 * fRec232[1]) + (fConst563 * fRec232[2])));
			fRec233[0] = (fTemp1 - ((fConst568 * fRec233[1]) + (fConst569 * fRec233[2])));
			fRec234[0] = (fTemp1 - ((fConst570 * fRec234[1]) + (fConst569 * fRec234[2])));
			fRec235[0] = (fTemp1 - ((fConst571 * fRec235[1]) + (fConst10 * fRec235[2])));
			fRec236[0] = (fTemp1 - ((fConst572 * fRec236[1]) + (fConst363 * fRec236[2])));
			fRec237[0] = (fTemp1 - ((fConst573 * fRec237[1]) + (fConst363 * fRec237[2])));
			fRec238[0] = (fTemp1 - ((fConst574 * fRec238[1]) + (fConst363 * fRec238[2])));
			fRec239[0] = (fTemp1 - ((fConst576 * fRec239[1]) + (fConst577 * fRec239[2])));
			fRec240[0] = (fTemp1 - ((fConst578 * fRec240[1]) + (fConst10 * fRec240[2])));
			fRec241[0] = (fTemp1 - ((fConst579 * fRec241[1]) + (fConst10 * fRec241[2])));
			fRec242[0] = (fTemp1 - ((fConst580 * fRec242[1]) + (fConst459 * fRec242[2])));
			fRec243[0] = (fTemp1 - ((fConst583 * fRec243[1]) + (fConst584 * fRec243[2])));
			fRec244[0] = (fTemp1 - ((fConst585 * fRec244[1]) + (fConst563 * fRec244[2])));
			fRec245[0] = (fTemp1 - ((fConst586 * fRec245[1]) + (fConst563 * fRec245[2])));
			fRec246[0] = (fTemp1 - ((fConst587 * fRec246[1]) + (fConst563 * fRec246[2])));
			fRec247[0] = (fTemp1 - ((fConst590 * fRec247[1]) + (fConst591 * fRec247[2])));
			fRec248[0] = (fTemp1 - ((fConst592 * fRec248[1]) + (fConst591 * fRec248[2])));
			fRec249[0] = (fTemp1 - ((fConst593 * fRec249[1]) + (fConst591 * fRec249[2])));
			fRec250[0] = (fTemp1 - ((fConst595 * fRec250[1]) + (fConst596 * fRec250[2])));
			fRec251[0] = (fTemp1 - ((fConst598 * fRec251[1]) + (fConst599 * fRec251[2])));
			fRec252[0] = (fTemp1 - ((fConst600 * fRec252[1]) + (fConst559 * fRec252[2])));
			fRec253[0] = (fTemp1 - ((fConst601 * fRec253[1]) + (fConst563 * fRec253[2])));
			fRec254[0] = (fTemp1 - ((fConst602 * fRec254[1]) + (fConst584 * fRec254[2])));
			fRec255[0] = (fTemp1 - ((fConst605 * fRec255[1]) + (fConst606 * fRec255[2])));
			fRec256[0] = (fTemp1 - ((fConst607 * fRec256[1]) + (fConst563 * fRec256[2])));
			fRec257[0] = (fTemp1 - ((fConst608 * fRec257[1]) + (fConst563 * fRec257[2])));
			fRec258[0] = (fTemp1 - ((fConst609 * fRec258[1]) + (fConst428 * fRec258[2])));
			fRec259[0] = (fTemp1 - ((fConst610 * fRec259[1]) + (fConst563 * fRec259[2])));
			fRec260[0] = (fTemp1 - ((fConst613 * fRec260[1]) + (fConst614 * fRec260[2])));
			fRec261[0] = (fTemp1 - ((fConst615 * fRec261[1]) + (fConst614 * fRec261[2])));
			fRec262[0] = (fTemp1 - ((fConst616 * fRec262[1]) + (fConst155 * fRec262[2])));
			fRec263[0] = (fTemp1 - ((fConst617 * fRec263[1]) + (fConst155 * fRec263[2])));
			fRec264[0] = (fTemp1 - ((fConst618 * fRec264[1]) + (fConst155 * fRec264[2])));
			fRec265[0] = (fTemp1 - ((fConst619 * fRec265[1]) + (fConst26 * fRec265[2])));
			fRec266[0] = (fTemp1 - ((fConst620 * fRec266[1]) + (fConst26 * fRec266[2])));
			fRec267[0] = (fTemp1 - ((fConst622 * fRec267[1]) + (fConst623 * fRec267[2])));
			fRec268[0] = (fTemp1 - ((fConst625 * fRec268[1]) + (fConst626 * fRec268[2])));
			fRec269[0] = (fTemp1 - ((fConst627 * fRec269[1]) + (fConst359 * fRec269[2])));
			fRec270[0] = (fTemp1 - ((fConst628 * fRec270[1]) + (fConst359 * fRec270[2])));
			fRec271[0] = (fTemp1 - ((fConst629 * fRec271[1]) + (fConst26 * fRec271[2])));
			fRec272[0] = (fTemp1 - ((fConst630 * fRec272[1]) + (fConst606 * fRec272[2])));
			fRec273[0] = (fTemp1 - ((fConst631 * fRec273[1]) + (fConst563 * fRec273[2])));
			fRec274[0] = (fTemp1 - ((fConst632 * fRec274[1]) + (fConst591 * fRec274[2])));
			fRec275[0] = (fTemp1 - ((fConst633 * fRec275[1]) + (fConst559 * fRec275[2])));
			fRec276[0] = (fTemp1 - ((fConst635 * fRec276[1]) + (fConst636 * fRec276[2])));
			fRec277[0] = (fTemp1 - ((fConst638 * fRec277[1]) + (fConst639 * fRec277[2])));
			fRec278[0] = (fTemp1 - ((fConst642 * fRec278[1]) + (fConst643 * fRec278[2])));
			fRec279[0] = (fTemp1 - ((fConst644 * fRec279[1]) + (fConst499 * fRec279[2])));
			fRec280[0] = (fTemp1 - ((fConst645 * fRec280[1]) + (fConst499 * fRec280[2])));
			fRec281[0] = (fTemp1 - ((fConst646 * fRec281[1]) + (fConst643 * fRec281[2])));
			fRec282[0] = (fTemp1 - ((fConst648 * fRec282[1]) + (fConst649 * fRec282[2])));
			fRec283[0] = (fTemp1 - ((fConst651 * fRec283[1]) + (fConst652 * fRec283[2])));
			fRec284[0] = (fTemp1 - ((fConst653 * fRec284[1]) + (fConst643 * fRec284[2])));
			fRec285[0] = (fTemp1 - ((fConst654 * fRec285[1]) + (fConst643 * fRec285[2])));
			fRec286[0] = (fTemp1 - ((fConst655 * fRec286[1]) + (fConst508 * fRec286[2])));
			fRec287[0] = (fTemp1 - ((fConst656 * fRec287[1]) + (fConst491 * fRec287[2])));
			fRec288[0] = (fTemp1 - ((fConst657 * fRec288[1]) + (fConst491 * fRec288[2])));
			fRec289[0] = (fTemp1 - ((fConst658 * fRec289[1]) + (fConst548 * fRec289[2])));
			fRec290[0] = (fTemp1 - ((fConst659 * fRec290[1]) + (fConst541 * fRec290[2])));
			fRec291[0] = (fTemp1 - ((fConst660 * fRec291[1]) + (fConst541 * fRec291[2])));
			fRec292[0] = (fTemp1 - ((fConst663 * fRec292[1]) + (fConst664 * fRec292[2])));
			fRec293[0] = (fTemp1 - ((fConst666 * fRec293[1]) + (fConst667 * fRec293[2])));
			fRec294[0] = (fTemp1 - ((fConst668 * fRec294[1]) + (fConst664 * fRec294[2])));
			output0[i] = FAUSTFLOAT(((fSlow1 + (fSlow0 * (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((0.123136253493 * (fRec0[0] - fRec0[2])) + (0.36445160102399998 * (fRec1[0] - fRec1[2]))) + (0.54927336160100004 * (fRec2[0] - fRec2[2]))) + (0.56845770331099998 * (fRec3[0] - fRec3[2]))) + (0.57838873573000005 * (fRec4[0] - fRec4[2]))) + (0.86744617741300001 * (fRec5[0] - fRec5[2]))) + (0.84752795982499995 * (fRec6[0] - fRec6[2]))) + (0.309278063873 * (fRec7[0] - fRec7[2]))) + (0.94690672772499995 * (fRec8[0] - fRec8[2]))) + (0.65721022755900005 * (fRec9[0] - fRec9[2]))) + (0.64646181883999998 * (fRec10[0] - fRec10[2]))) + (0.47823136406200001 * (fRec11[0] - fRec11[2]))) + (0.566489977358 * (fRec12[0] - fRec12[2]))) + (0.67054911136899997 * (fRec13[0] - fRec13[2]))) + (0.86741541986100001 * (fRec14[0] - fRec14[2]))) + (0.56695918744899998 * (fRec15[0] - fRec15[2]))) + (0.453483585164 * (fRec16[0] - fRec16[2]))) + (0.39276374519099999 * (fRec17[0] - fRec17[2]))) + (0.43766185817600001 * (fRec18[0] - fRec18[2]))) + (0.48858148565300002 * (fRec19[0] - fRec19[2]))) + (0.51322248912400004 * (fRec20[0] - fRec20[2]))) + (0.56516970276199996 * (fRec21[0] - fRec21[2]))) + (0.659480989415 * (fRec22[0] - fRec22[2]))) + (0.501711358818 * (fRec23[0] - fRec23[2]))) + (0.495218583652 * (fRec24[0] - fRec24[2]))) + (0.45345048823400003 * (fRec25[0] - fRec25[2]))) + (0.79538220318300001 * (fRec26[0] - fRec26[2]))) + (0.95952759837500001 * (fRec27[0] - fRec27[2]))) + (fRec28[0] - fRec28[2])) + (0.65930177063399997 * (fRec29[0] - fRec29[2]))) + (0.68578507727100002 * (fRec30[0] - fRec30[2]))) + (0.75682561373099999 * (fRec31[0] - fRec31[2]))) + (0.48462187670500001 * (fRec32[0] - fRec32[2]))) + (0.46670013209 * (fRec33[0] - fRec33[2]))) + (0.62782708861500003 * (fRec34[0] - fRec34[2]))) + (0.71990443633300005 * (fRec35[0] - fRec35[2]))) + (0.70380310749499997 * (fRec36[0] - fRec36[2]))) + (0.71396242244100006 * (fRec37[0] - fRec37[2]))) + (0.69088677982400004 * (fRec38[0] - fRec38[2]))) + (0.64531635086000005 * (fRec39[0] - fRec39[2]))) + (0.58515594153899997 * (fRec40[0] - fRec40[2]))) + (0.655216054554 * (fRec41[0] - fRec41[2]))) + (0.61452413873 * (fRec42[0] - fRec42[2]))) + (0.57747367860099996 * (fRec43[0] - fRec43[2]))) + (0.50022280355899995 * (fRec44[0] - fRec44[2]))) + (0.57678701350399997 * (fRec45[0] - fRec45[2]))) + (0.50273065551700002 * (fRec46[0] - fRec46[2]))) + (0.463705235695 * (fRec47[0] - fRec47[2]))) + (0.45892316689899998 * (fRec48[0] - fRec48[2]))) + (0.59653348486400004 * (fRec49[0] - fRec49[2]))) + (0.69773228799099996 * (fRec50[0] - fRec50[2]))) + (0.66508078817000005 * (fRec51[0] - fRec51[2]))) + (0.63325115877399996 * (fRec52[0] - fRec52[2]))) + (0.69171547580500004 * (fRec53[0] - fRec53[2]))) + (0.62799752433099998 * (fRec54[0] - fRec54[2]))) + (0.49047680358599999 * (fRec55[0] - fRec55[2]))) + (0.48875124588300001 * (fRec56[0] - fRec56[2]))) + (0.49665803185599999 * (fRec57[0] - fRec57[2]))) + (0.50679940626700004 * (fRec58[0] - fRec58[2]))) + (0.50472192206800004 * (fRec59[0] - fRec59[2]))) + (0.53243173150000001 * (fRec60[0] - fRec60[2]))) + (0.55781472122099995 * (fRec61[0] - fRec61[2]))) + (0.482876869032 * (fRec62[0] - fRec62[2]))) + (0.48426162393400002 * (fRec63[0] - fRec63[2]))) + (0.65285178736600002 * (fRec64[0] - fRec64[2]))) + (0.65525273072400003 * (fRec65[0] - fRec65[2]))) + (0.57761894032299999 * (fRec66[0] - fRec66[2]))) + (0.59761862776100005 * (fRec67[0] - fRec67[2]))) + (0.41627933895300001 * (fRec68[0] - fRec68[2]))) + (0.40644864252599999 * (fRec69[0] - fRec69[2]))) + (0.3702988505 * (fRec70[0] - fRec70[2]))) + (0.34349910744899997 * (fRec71[0] - fRec71[2]))) + (0.34448122782000001 * (fRec72[0] - fRec72[2]))) + (0.32464323550899998 * (fRec73[0] - fRec73[2]))) + (0.31561856074700001 * (fRec74[0] - fRec74[2]))) + (0.33737853602000001 * (fRec75[0] - fRec75[2]))) + (0.35208225221099998 * (fRec76[0] - fRec76[2]))) + (0.34609872308700002 * (fRec77[0] - fRec77[2]))) + (0.32189135168299998 * (fRec78[0] - fRec78[2]))) + (0.29903894014100002 * (fRec79[0] - fRec79[2]))) + (0.30011123544399998 * (fRec80[0] - fRec80[2]))) + (0.22857716033200001 * (fRec81[0] - fRec81[2]))) + (0.15969113156199999 * (fRec82[0] - fRec82[2]))) + (0.114601911515 * (fRec83[0] - fRec83[2]))) + (0.121682503604 * (fRec84[0] - fRec84[2]))) + (0.108729897844 * (fRec85[0] - fRec85[2]))) + (0.107563811742 * (fRec86[0] - fRec86[2]))) + (0.083876225976599994 * (fRec87[0] - fRec87[2]))) + (0.081565013394599997 * (fRec88[0] - fRec88[2]))) + (0.065520614383100001 * (fRec89[0] - fRec89[2]))) + (0.044575569343399998 * (fRec90[0] - fRec90[2]))) + (0.046235897700799999 * (fRec91[0] - fRec91[2]))) + (0.045947797158900003 * (fRec92[0] - fRec92[2]))) + (0.045568096452699998 * (fRec93[0] - fRec93[2]))) + (0.0470873345305 * (fRec94[0] - fRec94[2]))) + (0.047027515769099998 * (fRec95[0] - fRec95[2]))) + (0.0488443491535 * (fRec96[0] - fRec96[2]))) + (0.026514564428000001 * (fRec97[0] - fRec97[2]))) + (0.0191958661589 * (fRec98[0] - fRec98[2]))) + (0.016617847586799999 * (fRec99[0] - fRec99[2]))) + (0.018014568256000001 * (fRec100[0] - fRec100[2]))) + (0.018137854571299999 * (fRec101[0] - fRec101[2]))) + (0.0124833985073 * (fRec102[0] - fRec102[2]))) + (0.0101652059265 * (fRec103[0] - fRec103[2]))) + (0.0115604348742 * (fRec104[0] - fRec104[2]))) + (0.010833769214599999 * (fRec105[0] - fRec105[2]))) + (0.014677113056599999 * (fRec106[0] - fRec106[2]))) + (0.0147356628908 * (fRec107[0] - fRec107[2]))) + (0.0139511069911 * (fRec108[0] - fRec108[2]))) + (0.0137698729645 * (fRec109[0] - fRec109[2]))) + (0.019899089493799999 * (fRec110[0] - fRec110[2]))) + (0.0188483489921 * (fRec111[0] - fRec111[2]))) + (0.022291918247000001 * (fRec112[0] - fRec112[2]))) + (0.022182138606100001 * (fRec113[0] - fRec113[2]))) + (0.022609060005999999 * (fRec114[0] - fRec114[2]))) + (0.022647764942399999 * (fRec115[0] - fRec115[2]))) + (0.021107376104 * (fRec116[0] - fRec116[2]))) + (0.017441941147600001 * (fRec117[0] - fRec117[2]))) + (0.016382623374799999 * (fRec118[0] - fRec118[2]))) + (0.016877812015899999 * (fRec119[0] - fRec119[2]))) + (0.019332931034200002 * (fRec120[0] - fRec120[2]))) + (0.0132802248259 * (fRec121[0] - fRec121[2]))) + (0.0134469759863 * (fRec122[0] - fRec122[2]))) + (0.021571758530900001 * (fRec123[0] - fRec123[2]))) + (0.022300044259899999 * (fRec124[0] - fRec124[2]))) + (0.027664167818300001 * (fRec125[0] - fRec125[2]))) + (0.028399926395899999 * (fRec126[0] - fRec126[2]))) + (0.028466619313899998 * (fRec127[0] - fRec127[2]))) + (0.026313690277999999 * (fRec128[0] - fRec128[2]))) + (0.0115152595225 * (fRec129[0] - fRec129[2]))) + (0.017099761017599999 * (fRec130[0] - fRec130[2]))) + (0.016545502222700001 * (fRec131[0] - fRec131[2]))) + (0.0200491942066 * (fRec132[0] - fRec132[2]))) + (0.025256745802300001 * (fRec133[0] - fRec133[2]))) + (0.0263994959721 * (fRec134[0] - fRec134[2]))) + (0.044291577359400001 * (fRec135[0] - fRec135[2]))) + (0.043284741214399999 * (fRec136[0] - fRec136[2]))) + (0.041805147603100001 * (fRec137[0] - fRec137[2]))) + (0.039556601846600002 * (fRec138[0] - fRec138[2]))) + (0.015055749435500001 * (fRec139[0] - fRec139[2]))) + (0.0134611882263 * (fRec140[0] - fRec140[2]))) + (0.0138179035592 * (fRec141[0] - fRec141[2]))) + (0.013850891214899999 * (fRec142[0] - fRec142[2]))) + (0.0138311053226 * (fRec143[0] - fRec143[2]))) + (0.015764044533299999 * (fRec144[0] - fRec144[2]))) + (0.0156562364125 * (fRec145[0] - fRec145[2]))) + (0.022311978580700002 * (fRec146[0] - fRec146[2]))) + (0.021052944241600001 * (fRec147[0] - fRec147[2]))) + (0.027303618833999999 * (fRec148[0] - fRec148[2]))) + (0.027466824665999999 * (fRec149[0] - fRec149[2]))) + (0.0274583550507 * (fRec150[0] - fRec150[2]))) + (0.031730033577499997 * (fRec151[0] - fRec151[2]))) + (0.032855669215299997 * (fRec152[0] - fRec152[2]))) + (0.032283481841800001 * (fRec153[0] - fRec153[2]))) + (0.030605807139100001 * (fRec154[0] - fRec154[2]))) + (0.030555247724799998 * (fRec155[0] - fRec155[2]))) + (0.030497867744800001 * (fRec156[0] - fRec156[2]))) + (0.030302685427899999 * (fRec157[0] - fRec157[2]))) + (0.024800031621200001 * (fRec158[0] - fRec158[2]))) + (0.023531840669199999 * (fRec159[0] - fRec159[2]))) + (0.023228771000900001 * (fRec160[0] - fRec160[2]))) + (0.017387091522800002 * (fRec161[0] - fRec161[2]))) + (0.017560933645600001 * (fRec162[0] - fRec162[2]))) + (0.018408061884100001 * (fRec163[0] - fRec163[2]))) + (0.018740240922800001 * (fRec164[0] - fRec164[2]))) + (0.018732583762900001 * (fRec165[0] - fRec165[2]))) + (0.0186421091146 * (fRec166[0] - fRec166[2]))) + (0.018657851386600002 * (fRec167[0] - fRec167[2]))) + (0.018913955086500001 * (fRec168[0] - fRec168[2]))) + (0.018917757721799999 * (fRec169[0] - fRec169[2]))) + (0.018697573976300001 * (fRec170[0] - fRec170[2]))) + (0.0187697418026 * (fRec171[0] - fRec171[2]))) + (0.019117005631300001 * (fRec172[0] - fRec172[2]))) + (0.018913763071400001 * (fRec173[0] - fRec173[2]))) + (0.0202567112126 * (fRec174[0] - fRec174[2]))) + (0.018758203322100001 * (fRec175[0] - fRec175[2]))) + (0.0103790868767 * (fRec176[0] - fRec176[2]))) + (0.025288030787299999 * (fRec177[0] - fRec177[2]))) + (0.024902789236800001 * (fRec178[0] - fRec178[2]))) + (0.024715163074700001 * (fRec179[0] - fRec179[2]))) + (0.026887465480100001 * (fRec180[0] - fRec180[2]))) + (0.021260619387299999 * (fRec181[0] - fRec181[2]))) + (0.020583100656200001 * (fRec182[0] - fRec182[2]))) + (0.0144870567405 * (fRec183[0] - fRec183[2]))) + (0.015679520853699998 * (fRec184[0] - fRec184[2]))) + (0.016668663490399999 * (fRec185[0] - fRec185[2]))) + (0.0194556405686 * (fRec186[0] - fRec186[2]))) + (0.016569043795400001 * (fRec187[0] - fRec187[2]))) + (0.016659069853499998 * (fRec188[0] - fRec188[2]))) + (0.016567913545899999 * (fRec189[0] - fRec189[2]))) + (0.015881158444599999 * (fRec190[0] - fRec190[2]))) + (0.0155464686505 * (fRec191[0] - fRec191[2]))) + (0.015323718730199999 * (fRec192[0] - fRec192[2]))) + (0.0153187007108 * (fRec193[0] - fRec193[2]))) + (0.0115020685547 * (fRec194[0] - fRec194[2]))) + (0.0116041737544 * (fRec195[0] - fRec195[2]))) + (0.012008996612900001 * (fRec196[0] - fRec196[2]))) + (0.011793122628000001 * (fRec197[0] - fRec197[2]))) + (0.011486109676699999 * (fRec198[0] - fRec198[2]))) + (0.011498397712300001 * (fRec199[0] - fRec199[2]))) + (0.0112690312214 * (fRec200[0] - fRec200[2]))) + (0.012063734320800001 * (fRec201[0] - fRec201[2]))) + (0.012241989433 * (fRec202[0] - fRec202[2]))) + (0.012717424613500001 * (fRec203[0] - fRec203[2]))) + (0.0127321161327 * (fRec204[0] - fRec204[2]))) + (0.0124225532444 * (fRec205[0] - fRec205[2]))) + (0.013972531509700001 * (fRec206[0] - fRec206[2]))) + (0.0139292102716 * (fRec207[0] - fRec207[2]))) + (0.013490714393700001 * (fRec208[0] - fRec208[2]))) + (0.0129381361826 * (fRec209[0] - fRec209[2]))) + (0.012791288071999999 * (fRec210[0] - fRec210[2]))) + (0.012208306188600001 * (fRec211[0] - fRec211[2]))) + (0.0113643199311 * (fRec212[0] - fRec212[2]))) + (0.0114047513667 * (fRec213[0] - fRec213[2]))) + (0.011556890194799999 * (fRec214[0] - fRec214[2]))) + (0.011396397194100001 * (fRec215[0] - fRec215[2]))) + (0.011050096439800001 * (fRec216[0] - fRec216[2]))) + (0.010905715163799999 * (fRec217[0] - fRec217[2]))) + (0.0109021451742 * (fRec218[0] - fRec218[2]))) + (0.0102359858863 * (fRec219[0] - fRec219[2]))) + (0.010384655776 * (fRec220[0] - fRec220[2]))) + (0.0107265747518 * (fRec221[0] - fRec221[2]))) + (0.010766530367199999 * (fRec222[0] - fRec222[2]))) + (0.0114784295224 * (fRec223[0] - fRec223[2]))) + (0.0118302688653 * (fRec224[0] - fRec224[2]))) + (0.011699295726499999 * (fRec225[0] - fRec225[2]))) + (0.011864054523499999 * (fRec226[0] - fRec226[2]))) + (0.011885545470299999 * (fRec227[0] - fRec227[2]))) + (0.0111066671045 * (fRec228[0] - fRec228[2]))) + (0.016029714864799999 * (fRec229[0] - fRec229[2]))) + (0.017456430391400001 * (fRec230[0] - fRec230[2]))) + (0.017524908974300001 * (fRec231[0] - fRec231[2]))) + (0.017952429208500001 * (fRec232[0] - fRec232[2]))) + (0.029347480718200002 * (fRec233[0] - fRec233[2]))) + (0.0299429986449 * (fRec234[0] - fRec234[2]))) + (0.030792335148300001 * (fRec235[0] - fRec235[2]))) + (0.035471209176299999 * (fRec236[0] - fRec236[2]))) + (0.035620380770000001 * (fRec237[0] - fRec237[2]))) + (0.035534723490099999 * (fRec238[0] - fRec238[2]))) + (0.0335353893926 * (fRec239[0] - fRec239[2]))) + (0.0306499378606 * (fRec240[0] - fRec240[2]))) + (0.030642345507800001 * (fRec241[0] - fRec241[2]))) + (0.029149284968999999 * (fRec242[0] - fRec242[2]))) + (0.018416762561499999 * (fRec243[0] - fRec243[2]))) + (0.017520286093399999 * (fRec244[0] - fRec244[2]))) + (0.017662727750199999 * (fRec245[0] - fRec245[2]))) + (0.017422726699799999 * (fRec246[0] - fRec246[2]))) + (0.017319385166400001 * (fRec247[0] - fRec247[2]))) + (0.0169856097724 * (fRec248[0] - fRec248[2]))) + (0.016981090648100002 * (fRec249[0] - fRec249[2]))) + (0.016330167295299999 * (fRec250[0] - fRec250[2]))) + (0.0153010139748 * (fRec251[0] - fRec251[2]))) + (0.0159994483612 * (fRec252[0] - fRec252[2]))) + (0.017506346980699999 * (fRec253[0] - fRec253[2]))) + (0.018292763479599999 * (fRec254[0] - fRec254[2]))) + (0.018150931455000002 * (fRec255[0] - fRec255[2]))) + (0.017992078411799999 * (fRec256[0] - fRec256[2]))) + (0.0179215014752 * (fRec257[0] - fRec257[2]))) + (0.0186560543815 * (fRec258[0] - fRec258[2]))) + (0.017777966601399998 * (fRec259[0] - fRec259[2]))) + (0.0203259238024 * (fRec260[0] - fRec260[2]))) + (0.020403844746299998 * (fRec261[0] - fRec261[2]))) + (0.021728315647 * (fRec262[0] - fRec262[2]))) + (0.021715666627500001 * (fRec263[0] - fRec263[2]))) + (0.0222719502167 * (fRec264[0] - fRec264[2]))) + (0.022548027584399999 * (fRec265[0] - fRec265[2]))) + (0.0224343229544 * (fRec266[0] - fRec266[2]))) + (0.0235085424153 * (fRec267[0] - fRec267[2]))) + (0.023975298518899998 * (fRec268[0] - fRec268[2]))) + (0.024659087676199998 * (fRec269[0] - fRec269[2]))) + (0.024264152350700001 * (fRec270[0] - fRec270[2]))) + (0.022576971334399999 * (fRec271[0] - fRec271[2]))) + (0.018201116868500001 * (fRec272[0] - fRec272[2]))) + (0.017643824133600002 * (fRec273[0] - fRec273[2]))) + (0.017305033054599999 * (fRec274[0] - fRec274[2]))) + (0.015916100279399999 * (fRec275[0] - fRec275[2]))) + (0.0153099605246 * (fRec276[0] - fRec276[2]))) + (0.013509042303999999 * (fRec277[0] - fRec277[2]))) + (0.012932316788500001 * (fRec278[0] - fRec278[2]))) + (0.0120073685524 * (fRec279[0] - fRec279[2]))) + (0.0119729429972 * (fRec280[0] - fRec280[2]))) + (0.0129385735022 * (fRec281[0] - fRec281[2]))) + (0.0124829310258 * (fRec282[0] - fRec282[2]))) + (0.0133495154313 * (fRec283[0] - fRec283[2]))) + (0.0129476348875 * (fRec284[0] - fRec284[2]))) + (0.0131666518225 * (fRec285[0] - fRec285[2]))) + (0.012162420159200001 * (fRec286[0] - fRec286[2]))) + (0.011154399908 * (fRec287[0] - fRec287[2]))) + (0.010968546753 * (fRec288[0] - fRec288[2]))) + (0.010679062124200001 * (fRec289[0] - fRec289[2]))) + (0.0102650561369 * (fRec290[0] - fRec290[2]))) + (0.010304210493400001 * (fRec291[0] - fRec291[2]))) + (0.010288010956 * (fRec292[0] - fRec292[2]))) + (0.0101748463532 * (fRec293[0] - fRec293[2]))) + (0.010284097683200001 * (fRec294[0] - fRec294[2]))))) * fTemp0));
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
			fRec230[2] = fRec230[1];
			fRec230[1] = fRec230[0];
			fRec231[2] = fRec231[1];
			fRec231[1] = fRec231[0];
			fRec232[2] = fRec232[1];
			fRec232[1] = fRec232[0];
			fRec233[2] = fRec233[1];
			fRec233[1] = fRec233[0];
			fRec234[2] = fRec234[1];
			fRec234[1] = fRec234[0];
			fRec235[2] = fRec235[1];
			fRec235[1] = fRec235[0];
			fRec236[2] = fRec236[1];
			fRec236[1] = fRec236[0];
			fRec237[2] = fRec237[1];
			fRec237[1] = fRec237[0];
			fRec238[2] = fRec238[1];
			fRec238[1] = fRec238[0];
			fRec239[2] = fRec239[1];
			fRec239[1] = fRec239[0];
			fRec240[2] = fRec240[1];
			fRec240[1] = fRec240[0];
			fRec241[2] = fRec241[1];
			fRec241[1] = fRec241[0];
			fRec242[2] = fRec242[1];
			fRec242[1] = fRec242[0];
			fRec243[2] = fRec243[1];
			fRec243[1] = fRec243[0];
			fRec244[2] = fRec244[1];
			fRec244[1] = fRec244[0];
			fRec245[2] = fRec245[1];
			fRec245[1] = fRec245[0];
			fRec246[2] = fRec246[1];
			fRec246[1] = fRec246[0];
			fRec247[2] = fRec247[1];
			fRec247[1] = fRec247[0];
			fRec248[2] = fRec248[1];
			fRec248[1] = fRec248[0];
			fRec249[2] = fRec249[1];
			fRec249[1] = fRec249[0];
			fRec250[2] = fRec250[1];
			fRec250[1] = fRec250[0];
			fRec251[2] = fRec251[1];
			fRec251[1] = fRec251[0];
			fRec252[2] = fRec252[1];
			fRec252[1] = fRec252[0];
			fRec253[2] = fRec253[1];
			fRec253[1] = fRec253[0];
			fRec254[2] = fRec254[1];
			fRec254[1] = fRec254[0];
			fRec255[2] = fRec255[1];
			fRec255[1] = fRec255[0];
			fRec256[2] = fRec256[1];
			fRec256[1] = fRec256[0];
			fRec257[2] = fRec257[1];
			fRec257[1] = fRec257[0];
			fRec258[2] = fRec258[1];
			fRec258[1] = fRec258[0];
			fRec259[2] = fRec259[1];
			fRec259[1] = fRec259[0];
			fRec260[2] = fRec260[1];
			fRec260[1] = fRec260[0];
			fRec261[2] = fRec261[1];
			fRec261[1] = fRec261[0];
			fRec262[2] = fRec262[1];
			fRec262[1] = fRec262[0];
			fRec263[2] = fRec263[1];
			fRec263[1] = fRec263[0];
			fRec264[2] = fRec264[1];
			fRec264[1] = fRec264[0];
			fRec265[2] = fRec265[1];
			fRec265[1] = fRec265[0];
			fRec266[2] = fRec266[1];
			fRec266[1] = fRec266[0];
			fRec267[2] = fRec267[1];
			fRec267[1] = fRec267[0];
			fRec268[2] = fRec268[1];
			fRec268[1] = fRec268[0];
			fRec269[2] = fRec269[1];
			fRec269[1] = fRec269[0];
			fRec270[2] = fRec270[1];
			fRec270[1] = fRec270[0];
			fRec271[2] = fRec271[1];
			fRec271[1] = fRec271[0];
			fRec272[2] = fRec272[1];
			fRec272[1] = fRec272[0];
			fRec273[2] = fRec273[1];
			fRec273[1] = fRec273[0];
			fRec274[2] = fRec274[1];
			fRec274[1] = fRec274[0];
			fRec275[2] = fRec275[1];
			fRec275[1] = fRec275[0];
			fRec276[2] = fRec276[1];
			fRec276[1] = fRec276[0];
			fRec277[2] = fRec277[1];
			fRec277[1] = fRec277[0];
			fRec278[2] = fRec278[1];
			fRec278[1] = fRec278[0];
			fRec279[2] = fRec279[1];
			fRec279[1] = fRec279[0];
			fRec280[2] = fRec280[1];
			fRec280[1] = fRec280[0];
			fRec281[2] = fRec281[1];
			fRec281[1] = fRec281[0];
			fRec282[2] = fRec282[1];
			fRec282[1] = fRec282[0];
			fRec283[2] = fRec283[1];
			fRec283[1] = fRec283[0];
			fRec284[2] = fRec284[1];
			fRec284[1] = fRec284[0];
			fRec285[2] = fRec285[1];
			fRec285[1] = fRec285[0];
			fRec286[2] = fRec286[1];
			fRec286[1] = fRec286[0];
			fRec287[2] = fRec287[1];
			fRec287[1] = fRec287[0];
			fRec288[2] = fRec288[1];
			fRec288[1] = fRec288[0];
			fRec289[2] = fRec289[1];
			fRec289[1] = fRec289[0];
			fRec290[2] = fRec290[1];
			fRec290[1] = fRec290[0];
			fRec291[2] = fRec291[1];
			fRec291[1] = fRec291[0];
			fRec292[2] = fRec292[1];
			fRec292[1] = fRec292[0];
			fRec293[2] = fRec293[1];
			fRec293[1] = fRec293[0];
			fRec294[2] = fRec294[1];
			fRec294[1] = fRec294[0];
			
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
