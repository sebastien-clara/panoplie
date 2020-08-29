/* ------------------------------------------------------------
name: "cabinetFenderBlackfaceBass"
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
	double fConst9;
	double fRec2[3];
	double fConst10;
	double fRec3[3];
	double fConst11;
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
	double fRec6[3];
	double fConst20;
	double fConst21;
	double fConst22;
	double fConst23;
	double fRec7[3];
	double fConst24;
	double fConst25;
	double fConst26;
	double fRec8[3];
	double fConst27;
	double fConst28;
	double fConst29;
	double fRec9[3];
	double fConst30;
	double fConst31;
	double fConst32;
	double fConst33;
	double fRec10[3];
	double fConst34;
	double fRec11[3];
	double fConst35;
	double fConst36;
	double fConst37;
	double fConst38;
	double fRec12[3];
	double fConst39;
	double fConst40;
	double fConst41;
	double fConst42;
	double fRec13[3];
	double fConst43;
	double fRec14[3];
	double fConst44;
	double fConst45;
	double fConst46;
	double fConst47;
	double fRec15[3];
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
	double fConst65;
	double fConst66;
	double fRec21[3];
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
	double fConst79;
	double fRec25[3];
	double fConst80;
	double fConst81;
	double fConst82;
	double fConst83;
	double fRec26[3];
	double fConst84;
	double fConst85;
	double fConst86;
	double fConst87;
	double fRec27[3];
	double fConst88;
	double fRec28[3];
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
	double fRec31[3];
	double fConst98;
	double fConst99;
	double fConst100;
	double fConst101;
	double fRec32[3];
	double fConst102;
	double fConst103;
	double fConst104;
	double fConst105;
	double fRec33[3];
	double fConst106;
	double fConst107;
	double fConst108;
	double fRec34[3];
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
	double fRec38[3];
	double fConst116;
	double fConst117;
	double fConst118;
	double fRec39[3];
	double fConst119;
	double fConst120;
	double fConst121;
	double fRec40[3];
	double fConst122;
	double fConst123;
	double fConst124;
	double fConst125;
	double fRec41[3];
	double fConst126;
	double fConst127;
	double fConst128;
	double fRec42[3];
	double fConst129;
	double fRec43[3];
	double fConst130;
	double fConst131;
	double fConst132;
	double fRec44[3];
	double fConst133;
	double fConst134;
	double fConst135;
	double fRec45[3];
	double fConst136;
	double fRec46[3];
	double fConst137;
	double fConst138;
	double fConst139;
	double fRec47[3];
	double fConst140;
	double fRec48[3];
	double fConst141;
	double fConst142;
	double fConst143;
	double fRec49[3];
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
	double fConst152;
	double fConst153;
	double fRec52[3];
	double fConst154;
	double fRec53[3];
	double fConst155;
	double fRec54[3];
	double fConst156;
	double fConst157;
	double fConst158;
	double fRec55[3];
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
	double fRec60[3];
	double fConst167;
	double fRec61[3];
	double fConst168;
	double fRec62[3];
	double fConst169;
	double fRec63[3];
	double fConst170;
	double fRec64[3];
	double fConst171;
	double fConst172;
	double fConst173;
	double fRec65[3];
	double fConst174;
	double fRec66[3];
	double fConst175;
	double fRec67[3];
	double fConst176;
	double fRec68[3];
	double fConst177;
	double fConst178;
	double fConst179;
	double fRec69[3];
	double fConst180;
	double fConst181;
	double fConst182;
	double fConst183;
	double fRec70[3];
	double fConst184;
	double fConst185;
	double fConst186;
	double fConst187;
	double fRec71[3];
	double fConst188;
	double fRec72[3];
	double fConst189;
	double fConst190;
	double fConst191;
	double fConst192;
	double fRec73[3];
	double fConst193;
	double fConst194;
	double fConst195;
	double fRec74[3];
	double fConst196;
	double fConst197;
	double fConst198;
	double fRec75[3];
	double fConst199;
	double fConst200;
	double fConst201;
	double fRec76[3];
	double fConst202;
	double fRec77[3];
	double fConst203;
	double fConst204;
	double fConst205;
	double fConst206;
	double fRec78[3];
	double fConst207;
	double fConst208;
	double fConst209;
	double fRec79[3];
	double fConst210;
	double fConst211;
	double fConst212;
	double fRec80[3];
	double fConst213;
	double fConst214;
	double fConst215;
	double fRec81[3];
	double fConst216;
	double fConst217;
	double fConst218;
	double fConst219;
	double fRec82[3];
	double fConst220;
	double fRec83[3];
	double fConst221;
	double fRec84[3];
	double fConst222;
	double fRec85[3];
	double fConst223;
	double fConst224;
	double fConst225;
	double fRec86[3];
	double fConst226;
	double fRec87[3];
	double fConst227;
	double fConst228;
	double fConst229;
	double fRec88[3];
	double fConst230;
	double fConst231;
	double fConst232;
	double fRec89[3];
	double fConst233;
	double fConst234;
	double fConst235;
	double fRec90[3];
	double fConst236;
	double fRec91[3];
	double fConst237;
	double fRec92[3];
	double fConst238;
	double fRec93[3];
	double fConst239;
	double fConst240;
	double fConst241;
	double fConst242;
	double fRec94[3];
	double fConst243;
	double fConst244;
	double fConst245;
	double fRec95[3];
	double fConst246;
	double fConst247;
	double fConst248;
	double fRec96[3];
	double fConst249;
	double fConst250;
	double fConst251;
	double fRec97[3];
	double fConst252;
	double fConst253;
	double fConst254;
	double fConst255;
	double fRec98[3];
	double fConst256;
	double fRec99[3];
	double fConst257;
	double fRec100[3];
	double fConst258;
	double fRec101[3];
	double fConst259;
	double fConst260;
	double fConst261;
	double fRec102[3];
	double fConst262;
	double fConst263;
	double fConst264;
	double fConst265;
	double fRec103[3];
	double fConst266;
	double fConst267;
	double fConst268;
	double fRec104[3];
	double fConst269;
	double fConst270;
	double fConst271;
	double fRec105[3];
	double fConst272;
	double fRec106[3];
	double fConst273;
	double fConst274;
	double fConst275;
	double fConst276;
	double fRec107[3];
	double fConst277;
	double fRec108[3];
	double fConst278;
	double fConst279;
	double fConst280;
	double fRec109[3];
	double fConst281;
	double fRec110[3];
	double fConst282;
	double fConst283;
	double fConst284;
	double fConst285;
	double fRec111[3];
	double fConst286;
	double fConst287;
	double fConst288;
	double fRec112[3];
	double fConst289;
	double fConst290;
	double fConst291;
	double fRec113[3];
	double fConst292;
	double fConst293;
	double fConst294;
	double fRec114[3];
	double fConst295;
	double fRec115[3];
	double fConst296;
	double fConst297;
	double fConst298;
	double fRec116[3];
	double fConst299;
	double fRec117[3];
	double fConst300;
	double fConst301;
	double fConst302;
	double fRec118[3];
	double fConst303;
	double fConst304;
	double fConst305;
	double fRec119[3];
	double fConst306;
	double fConst307;
	double fConst308;
	double fRec120[3];
	double fConst309;
	double fConst310;
	double fConst311;
	double fRec121[3];
	double fConst312;
	double fConst313;
	double fConst314;
	double fConst315;
	double fRec122[3];
	double fConst316;
	double fRec123[3];
	double fConst317;
	double fConst318;
	double fConst319;
	double fRec124[3];
	double fConst320;
	double fRec125[3];
	double fConst321;
	double fConst322;
	double fConst323;
	double fRec126[3];
	double fConst324;
	double fConst325;
	double fConst326;
	double fConst327;
	double fRec127[3];
	double fConst328;
	double fRec128[3];
	double fConst329;
	double fConst330;
	double fConst331;
	double fRec129[3];
	double fConst332;
	double fConst333;
	double fConst334;
	double fRec130[3];
	double fConst335;
	double fConst336;
	double fConst337;
	double fRec131[3];
	double fConst338;
	double fConst339;
	double fConst340;
	double fRec132[3];
	double fConst341;
	double fConst342;
	double fConst343;
	double fRec133[3];
	double fConst344;
	double fConst345;
	double fConst346;
	double fRec134[3];
	double fConst347;
	double fConst348;
	double fConst349;
	double fRec135[3];
	double fConst350;
	double fConst351;
	double fConst352;
	double fConst353;
	double fRec136[3];
	double fConst354;
	double fRec137[3];
	double fConst355;
	double fRec138[3];
	double fConst356;
	double fConst357;
	double fConst358;
	double fRec139[3];
	double fConst359;
	double fConst360;
	double fConst361;
	double fConst362;
	double fRec140[3];
	double fConst363;
	double fRec141[3];
	double fConst364;
	double fConst365;
	double fConst366;
	double fRec142[3];
	double fConst367;
	double fConst368;
	double fConst369;
	double fRec143[3];
	double fConst370;
	double fConst371;
	double fConst372;
	double fRec144[3];
	double fConst373;
	double fConst374;
	double fConst375;
	double fRec145[3];
	double fConst376;
	double fConst377;
	double fConst378;
	double fConst379;
	double fRec146[3];
	double fConst380;
	double fRec147[3];
	double fConst381;
	double fConst382;
	double fConst383;
	double fConst384;
	double fRec148[3];
	double fConst385;
	double fRec149[3];
	double fConst386;
	double fConst387;
	double fConst388;
	double fRec150[3];
	double fConst389;
	double fConst390;
	double fConst391;
	double fRec151[3];
	double fConst392;
	double fConst393;
	double fConst394;
	double fRec152[3];
	double fConst395;
	double fConst396;
	double fConst397;
	double fRec153[3];
	double fConst398;
	double fConst399;
	double fConst400;
	double fRec154[3];
	double fConst401;
	double fRec155[3];
	double fConst402;
	double fConst403;
	double fConst404;
	double fConst405;
	double fRec156[3];
	double fConst406;
	double fRec157[3];
	double fConst407;
	double fRec158[3];
	double fConst408;
	double fConst409;
	double fConst410;
	double fRec159[3];
	double fConst411;
	double fConst412;
	double fConst413;
	double fConst414;
	double fRec160[3];
	double fConst415;
	double fRec161[3];
	double fConst416;
	double fRec162[3];
	double fConst417;
	double fRec163[3];
	double fConst418;
	double fConst419;
	double fConst420;
	double fRec164[3];
	double fConst421;
	double fRec165[3];
	double fConst422;
	double fRec166[3];
	double fConst423;
	double fRec167[3];
	double fConst424;
	double fRec168[3];
	double fConst425;
	double fConst426;
	double fConst427;
	double fConst428;
	double fRec169[3];
	double fConst429;
	double fConst430;
	double fConst431;
	double fRec170[3];
	double fConst432;
	double fConst433;
	double fConst434;
	double fConst435;
	double fRec171[3];
	double fConst436;
	double fRec172[3];
	double fConst437;
	double fConst438;
	double fConst439;
	double fRec173[3];
	double fConst440;
	double fRec174[3];
	double fConst441;
	double fConst442;
	double fConst443;
	double fRec175[3];
	double fConst444;
	double fRec176[3];
	double fConst445;
	double fConst446;
	double fConst447;
	double fConst448;
	double fRec177[3];
	double fConst449;
	double fConst450;
	double fConst451;
	double fConst452;
	double fRec178[3];
	double fConst453;
	double fRec179[3];
	double fConst454;
	double fRec180[3];
	double fConst455;
	double fRec181[3];
	double fConst456;
	double fRec182[3];
	double fConst457;
	double fRec183[3];
	double fConst458;
	double fConst459;
	double fConst460;
	double fRec184[3];
	double fConst461;
	double fConst462;
	double fConst463;
	double fConst464;
	double fRec185[3];
	double fConst465;
	double fConst466;
	double fConst467;
	double fConst468;
	double fRec186[3];
	double fConst469;
	double fRec187[3];
	double fConst470;
	double fRec188[3];
	double fConst471;
	double fConst472;
	double fConst473;
	double fConst474;
	double fRec189[3];
	double fConst475;
	double fRec190[3];
	double fConst476;
	double fRec191[3];
	double fConst477;
	double fRec192[3];
	double fConst478;
	double fRec193[3];
	double fConst479;
	double fRec194[3];
	double fConst480;
	double fConst481;
	double fConst482;
	double fConst483;
	double fRec195[3];
	double fConst484;
	double fRec196[3];
	double fConst485;
	double fConst486;
	double fConst487;
	double fConst488;
	double fRec197[3];
	double fConst489;
	double fRec198[3];
	double fConst490;
	double fConst491;
	double fConst492;
	double fConst493;
	double fRec199[3];
	double fConst494;
	double fConst495;
	double fConst496;
	double fConst497;
	double fRec200[3];
	double fConst498;
	double fRec201[3];
	double fConst499;
	double fRec202[3];
	double fConst500;
	double fRec203[3];
	double fConst501;
	double fRec204[3];
	double fConst502;
	double fRec205[3];
	double fConst503;
	double fConst504;
	double fConst505;
	double fConst506;
	double fRec206[3];
	double fConst507;
	double fRec207[3];
	double fConst508;
	double fRec208[3];
	double fConst509;
	double fConst510;
	double fConst511;
	double fRec209[3];
	double fConst512;
	double fRec210[3];
	double fConst513;
	double fRec211[3];
	double fConst514;
	double fRec212[3];
	double fConst515;
	double fRec213[3];
	double fConst516;
	double fConst517;
	double fConst518;
	double fRec214[3];
	double fConst519;
	double fConst520;
	double fConst521;
	double fConst522;
	double fRec215[3];
	double fConst523;
	double fRec216[3];
	double fConst524;
	double fRec217[3];
	double fConst525;
	double fRec218[3];
	double fConst526;
	double fRec219[3];
	double fConst527;
	double fRec220[3];
	double fConst528;
	double fRec221[3];
	double fConst529;
	double fConst530;
	double fConst531;
	double fRec222[3];
	double fConst532;
	double fConst533;
	double fConst534;
	double fRec223[3];
	double fConst535;
	double fRec224[3];
	double fConst536;
	double fConst537;
	double fConst538;
	double fRec225[3];
	double fConst539;
	double fRec226[3];
	double fConst540;
	double fConst541;
	double fConst542;
	double fConst543;
	double fRec227[3];
	double fConst544;
	double fConst545;
	double fConst546;
	double fRec228[3];
	double fConst547;
	double fConst548;
	double fConst549;
	double fConst550;
	double fRec229[3];
	double fConst551;
	double fRec230[3];
	double fConst552;
	double fConst553;
	double fConst554;
	double fConst555;
	double fRec231[3];
	double fConst556;
	double fConst557;
	double fConst558;
	double fConst559;
	double fRec232[3];
	double fConst560;
	double fRec233[3];
	double fConst561;
	double fRec234[3];
	double fConst562;
	double fRec235[3];
	double fConst563;
	double fRec236[3];
	double fConst564;
	double fConst565;
	double fConst566;
	double fConst567;
	double fRec237[3];
	double fConst568;
	double fConst569;
	double fConst570;
	double fConst571;
	double fRec238[3];
	double fConst572;
	double fConst573;
	double fConst574;
	double fRec239[3];
	double fConst575;
	double fConst576;
	double fConst577;
	double fRec240[3];
	double fConst578;
	double fRec241[3];
	double fConst579;
	double fRec242[3];
	double fConst580;
	double fConst581;
	double fConst582;
	double fConst583;
	double fRec243[3];
	double fConst584;
	double fRec244[3];
	double fConst585;
	double fRec245[3];
	double fConst586;
	double fRec246[3];
	double fConst587;
	double fConst588;
	double fConst589;
	double fConst590;
	double fRec247[3];
	double fConst591;
	double fRec248[3];
	double fConst592;
	double fRec249[3];
	double fConst593;
	double fRec250[3];
	double fConst594;
	double fRec251[3];
	double fConst595;
	double fRec252[3];
	double fConst596;
	double fRec253[3];
	double fConst597;
	double fRec254[3];
	double fConst598;
	double fRec255[3];
	double fConst599;
	double fRec256[3];
	double fConst600;
	double fRec257[3];
	double fConst601;
	double fConst602;
	double fConst603;
	double fRec258[3];
	double fConst604;
	double fConst605;
	double fConst606;
	double fConst607;
	double fRec259[3];
	double fConst608;
	double fConst609;
	double fConst610;
	double fRec260[3];
	double fConst611;
	double fRec261[3];
	double fConst612;
	double fRec262[3];
	double fConst613;
	double fRec263[3];
	double fConst614;
	double fRec264[3];
	double fConst615;
	double fRec265[3];
	double fConst616;
	double fRec266[3];
	double fConst617;
	double fRec267[3];
	double fConst618;
	double fRec268[3];
	double fConst619;
	double fRec269[3];
	double fConst620;
	double fRec270[3];
	double fConst621;
	double fRec271[3];
	double fConst622;
	double fRec272[3];
	double fConst623;
	double fRec273[3];
	double fConst624;
	double fRec274[3];
	double fConst625;
	double fConst626;
	double fConst627;
	double fConst628;
	double fRec275[3];
	double fConst629;
	double fRec276[3];
	double fConst630;
	double fRec277[3];
	double fConst631;
	double fRec278[3];
	double fConst632;
	double fRec279[3];
	double fConst633;
	double fRec280[3];
	double fConst634;
	double fRec281[3];
	double fConst635;
	double fRec282[3];
	double fConst636;
	double fRec283[3];
	double fConst637;
	double fRec284[3];
	double fConst638;
	double fRec285[3];
	double fConst639;
	double fRec286[3];
	double fConst640;
	double fRec287[3];
	double fConst641;
	double fRec288[3];
	double fConst642;
	double fRec289[3];
	double fConst643;
	double fConst644;
	double fConst645;
	double fConst646;
	double fRec290[3];
	double fConst647;
	double fRec291[3];
	double fConst648;
	double fRec292[3];
	double fConst649;
	double fRec293[3];
	double fConst650;
	double fRec294[3];
	double fConst651;
	double fRec295[3];
	double fConst652;
	double fRec296[3];
	double fConst653;
	double fRec297[3];
	double fConst654;
	double fRec298[3];
	double fConst655;
	double fRec299[3];
	double fConst656;
	double fRec300[3];
	double fConst657;
	double fRec301[3];
	double fConst658;
	double fRec302[3];
	double fConst659;
	double fRec303[3];
	double fConst660;
	double fConst661;
	double fConst662;
	double fRec304[3];
	double fConst663;
	double fRec305[3];
	double fConst664;
	double fRec306[3];
	double fConst665;
	double fRec307[3];
	double fConst666;
	double fRec308[3];
	double fConst667;
	double fConst668;
	double fConst669;
	double fConst670;
	double fRec309[3];
	double fConst671;
	double fRec310[3];
	double fConst672;
	double fRec311[3];
	double fConst673;
	double fRec312[3];
	double fConst674;
	double fRec313[3];
	double fConst675;
	double fRec314[3];
	double fConst676;
	double fRec315[3];
	double fConst677;
	double fRec316[3];
	double fConst678;
	double fRec317[3];
	double fConst679;
	double fRec318[3];
	double fConst680;
	double fRec319[3];
	double fConst681;
	double fRec320[3];
	double fConst682;
	double fRec321[3];
	double fConst683;
	double fRec322[3];
	double fConst684;
	double fRec323[3];
	double fConst685;
	double fRec324[3];
	double fConst686;
	double fRec325[3];
	double fConst687;
	double fRec326[3];
	double fConst688;
	double fRec327[3];
	double fConst689;
	double fRec328[3];
	double fConst690;
	double fRec329[3];
	double fConst691;
	double fConst692;
	double fConst693;
	double fRec330[3];
	double fConst694;
	double fRec331[3];
	double fConst695;
	double fRec332[3];
	double fConst696;
	double fRec333[3];
	double fConst697;
	double fRec334[3];
	double fConst698;
	double fRec335[3];
	double fConst699;
	double fConst700;
	double fConst701;
	double fConst702;
	double fRec336[3];
	double fConst703;
	double fRec337[3];
	double fConst704;
	double fRec338[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.0");
		m->declare("description", "Generated by tools/physicalModeling/ir2dsp.py");
		m->declare("filename", "cabinetFenderBlackfaceBass");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "0.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.1");
		m->declare("name", "cabinetFenderBlackfaceBass");
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
		fConst1 = pow(0.001, (1.0 / (0.099411891051299994 * fConst0)));
		fConst2 = (0.0 - (2.0 * fConst1));
		fConst3 = (cos((663.14157562206776 / fConst0)) * fConst2);
		fConst4 = mydsp_faustpower2_f(fConst1);
		fConst5 = (fConst2 * cos((837.65251657954252 / fConst0)));
		fConst6 = pow(0.001, (1.0 / (0.61097953158700002 * fConst0)));
		fConst7 = (0.0 - (2.0 * fConst6));
		fConst8 = (cos((1116.8700221039621 / fConst0)) * fConst7);
		fConst9 = mydsp_faustpower2_f(fConst6);
		fConst10 = (cos((1500.7940922016101 / fConst0)) * fConst2);
		fConst11 = pow(0.001, (1.0 / (0.27776070820600002 * fConst0)));
		fConst12 = (0.0 - (2.0 * fConst11));
		fConst13 = (cos((1710.2072213480665 / fConst0)) * fConst12);
		fConst14 = mydsp_faustpower2_f(fConst11);
		fConst15 = pow(0.001, (1.0 / (0.29807892888600002 * fConst0)));
		fConst16 = (0.0 - (2.0 * fConst15));
		fConst17 = (cos((1919.6203504945229 / fConst0)) * fConst16);
		fConst18 = mydsp_faustpower2_f(fConst15);
		fConst19 = (fConst16 * cos((2094.1312914457149 / fConst0)));
		fConst20 = pow(0.001, (1.0 / (0.29098367721200002 * fConst0)));
		fConst21 = (0.0 - (2.0 * fConst20));
		fConst22 = (cos((2792.1750552630469 / fConst0)) * fConst21);
		fConst23 = mydsp_faustpower2_f(fConst20);
		fConst24 = pow(0.001, (1.0 / (0.31336100944099998 * fConst0)));
		fConst25 = (cos((3804.3385127937813 / fConst0)) * (0.0 - (2.0 * fConst24)));
		fConst26 = mydsp_faustpower2_f(fConst24);
		fConst27 = pow(0.001, (1.0 / (0.12225859813000001 * fConst0)));
		fConst28 = (cos((4083.5560183244843 / fConst0)) * (0.0 - (2.0 * fConst27)));
		fConst29 = mydsp_faustpower2_f(fConst27);
		fConst30 = pow(0.001, (1.0 / (0.67885744053700003 * fConst0)));
		fConst31 = (0.0 - (2.0 * fConst30));
		fConst32 = (cos((4502.3822766111143 / fConst0)) * fConst31);
		fConst33 = mydsp_faustpower2_f(fConst30);
		fConst34 = (fConst31 * cos((4711.7954057575707 / fConst0)));
		fConst35 = pow(0.001, (1.0 / (0.10275083242499999 * fConst0)));
		fConst36 = (0.0 - (2.0 * fConst35));
		fConst37 = (cos((5340.0347931906563 / fConst0)) * fConst36);
		fConst38 = mydsp_faustpower2_f(fConst35);
		fConst39 = pow(0.001, (1.0 / (0.101895228693 * fConst0)));
		fConst40 = (0.0 - (2.0 * fConst39));
		fConst41 = (cos((5479.6435459528657 / fConst0)) * fConst40);
		fConst42 = mydsp_faustpower2_f(fConst39);
		fConst43 = (fConst40 * cos((5549.4479223371127 / fConst0)));
		fConst44 = pow(0.001, (1.0 / (0.101053767176 * fConst0)));
		fConst45 = (0.0 - (2.0 * fConst44));
		fConst46 = (cos((5758.8610514772863 / fConst0)) * fConst45);
		fConst47 = mydsp_faustpower2_f(fConst44);
		fConst48 = pow(0.001, (1.0 / (0.305528943153 * fConst0)));
		fConst49 = (cos((6247.4916861481624 / fConst0)) * (0.0 - (2.0 * fConst48)));
		fConst50 = mydsp_faustpower2_f(fConst48);
		fConst51 = pow(0.001, (1.0 / (0.33029520684899999 * fConst0)));
		fConst52 = (0.0 - (2.0 * fConst51));
		fConst53 = (cos((6387.1004389292211 / fConst0)) * fConst52);
		fConst54 = mydsp_faustpower2_f(fConst51);
		fConst55 = (fConst52 * cos((6456.9048153071853 / fConst0)));
		fConst56 = pow(0.001, (1.0 / (0.16084182675700001 * fConst0)));
		fConst57 = (0.0 - (2.0 * fConst56));
		fConst58 = (cos((6771.0245090394355 / fConst0)) * fConst57);
		fConst59 = mydsp_faustpower2_f(fConst56);
		fConst60 = pow(0.001, (1.0 / (0.19401523889300001 * fConst0)));
		fConst61 = (0.0 - (2.0 * fConst60));
		fConst62 = (cos((6910.6332617953631 / fConst0)) * fConst61);
		fConst63 = mydsp_faustpower2_f(fConst60);
		fConst64 = pow(0.001, (1.0 / (0.19098497525300001 * fConst0)));
		fConst65 = (cos((7154.9485790868184 / fConst0)) * (0.0 - (2.0 * fConst64)));
		fConst66 = mydsp_faustpower2_f(fConst64);
		fConst67 = (fConst57 * cos((7224.7529554647808 / fConst0)));
		fConst68 = pow(0.001, (1.0 / (0.13288296520000001 * fConst0)));
		fConst69 = (0.0 - (2.0 * fConst68));
		fConst70 = (cos((7573.7748374174298 / fConst0)) * fConst69);
		fConst71 = mydsp_faustpower2_f(fConst68);
		fConst72 = pow(0.001, (1.0 / (0.103620937917 * fConst0)));
		fConst73 = (0.0 - (2.0 * fConst72));
		fConst74 = (cos((8132.2098484411372 / fConst0)) * fConst73);
		fConst75 = mydsp_faustpower2_f(fConst72);
		fConst76 = pow(0.001, (1.0 / (0.10450591701 * fConst0)));
		fConst77 = (0.0 - (2.0 * fConst76));
		fConst78 = (cos((8202.0142248191005 / fConst0)) * fConst77);
		fConst79 = mydsp_faustpower2_f(fConst76);
		fConst80 = pow(0.001, (1.0 / (0.097046807606399998 * fConst0)));
		fConst81 = (0.0 - (2.0 * fConst80));
		fConst82 = (cos((8795.3514240632048 / fConst0)) * fConst81);
		fConst83 = mydsp_faustpower2_f(fConst80);
		fConst84 = pow(0.001, (1.0 / (0.098610814397899996 * fConst0)));
		fConst85 = (0.0 - (2.0 * fConst84));
		fConst86 = (cos((9004.7645531970957 / fConst0)) * fConst85);
		fConst87 = mydsp_faustpower2_f(fConst84);
		fConst88 = (fConst85 * cos((9074.5689295750581 / fConst0)));
		fConst89 = pow(0.001, (1.0 / (0.086731018433500007 * fConst0)));
		fConst90 = (cos((9737.7105051971266 / fConst0)) * (0.0 - (2.0 * fConst89)));
		fConst91 = mydsp_faustpower2_f(fConst89);
		fConst92 = pow(0.001, (1.0 / (0.015033222817 * fConst0)));
		fConst93 = (cos((10191.438951685303 / fConst0)) * (0.0 - (2.0 * fConst92)));
		fConst94 = mydsp_faustpower2_f(fConst92);
		fConst95 = pow(0.001, (1.0 / (0.015088338069 * fConst0)));
		fConst96 = (cos((10400.852080882027 / fConst0)) * (0.0 - (2.0 * fConst95)));
		fConst97 = mydsp_faustpower2_f(fConst95);
		fConst98 = pow(0.001, (1.0 / (0.0329225566183 * fConst0)));
		fConst99 = (0.0 - (2.0 * fConst98));
		fConst100 = (cos((10924.384903685333 / fConst0)) * fConst99);
		fConst101 = mydsp_faustpower2_f(fConst98);
		fConst102 = pow(0.001, (1.0 / (0.030547298781300001 * fConst0)));
		fConst103 = (0.0 - (2.0 * fConst102));
		fConst104 = (cos((11273.406785637982 / fConst0)) * fConst103);
		fConst105 = mydsp_faustpower2_f(fConst102);
		fConst106 = pow(0.001, (1.0 / (0.015642837487499998 * fConst0)));
		fConst107 = (cos((11517.72210292944 / fConst0)) * (0.0 - (2.0 * fConst106)));
		fConst108 = mydsp_faustpower2_f(fConst106);
		fConst109 = (fConst103 * cos((11762.037420283727 / fConst0)));
		fConst110 = pow(0.001, (1.0 / (0.0307769632561 * fConst0)));
		fConst111 = (0.0 - (2.0 * fConst110));
		fConst112 = (cos((12145.961490393942 / fConst0)) * fConst111);
		fConst113 = mydsp_faustpower2_f(fConst110);
		fConst114 = (fConst52 * cos((12704.396501417647 / fConst0)));
		fConst115 = (fConst52 * cos((13227.92932428379 / fConst0)));
		fConst116 = pow(0.001, (1.0 / (0.34916474114099999 * fConst0)));
		fConst117 = (cos((13472.244641638075 / fConst0)) * (0.0 - (2.0 * fConst116)));
		fConst118 = mydsp_faustpower2_f(fConst116);
		fConst119 = pow(0.001, (1.0 / (0.030172067020600001 * fConst0)));
		fConst120 = (cos((13925.973088126255 / fConst0)) * (0.0 - (2.0 * fConst119)));
		fConst121 = mydsp_faustpower2_f(fConst119);
		fConst122 = pow(0.001, (1.0 / (0.030623470831300001 * fConst0)));
		fConst123 = (0.0 - (2.0 * fConst122));
		fConst124 = (cos((14135.386217260146 / fConst0)) * fConst123);
		fConst125 = mydsp_faustpower2_f(fConst122);
		fConst126 = pow(0.001, (1.0 / (0.0596784944693 * fConst0)));
		fConst127 = (cos((14519.310287370357 / fConst0)) * (0.0 - (2.0 * fConst126)));
		fConst128 = mydsp_faustpower2_f(fConst126);
		fConst129 = (fConst7 * cos((15391.864992126317 / fConst0)));
		fConst130 = pow(0.001, (1.0 / (0.066843531989300001 * fConst0)));
		fConst131 = (cos((15950.300003212855 / fConst0)) * (0.0 - (2.0 * fConst130)));
		fConst132 = mydsp_faustpower2_f(fConst130);
		fConst133 = pow(0.001, (1.0 / (0.643132225291 * fConst0)));
		fConst134 = (cos((16299.32188510267 / fConst0)) * (0.0 - (2.0 * fConst133)));
		fConst135 = mydsp_faustpower2_f(fConst133);
		fConst136 = (fConst2 * cos((17032.267837102703 / fConst0)));
		fConst137 = pow(0.001, (1.0 / (0.10022610011200001 * fConst0)));
		fConst138 = (cos((17206.778778079028 / fConst0)) * (0.0 - (2.0 * fConst137)));
		fConst139 = mydsp_faustpower2_f(fConst137);
		fConst140 = (fConst45 * cos((17416.191907212917 / fConst0)));
		fConst141 = pow(0.001, (1.0 / (0.39420814571200002 * fConst0)));
		fConst142 = (cos((17625.605036346806 / fConst0)) * (0.0 - (2.0 * fConst141)));
		fConst143 = mydsp_faustpower2_f(fConst141);
		fConst144 = pow(0.001, (1.0 / (0.150918156646 * fConst0)));
		fConst145 = (cos((18428.355364724801 / fConst0)) * (0.0 - (2.0 * fConst144)));
		fConst146 = mydsp_faustpower2_f(fConst144);
		fConst147 = pow(0.001, (1.0 / (0.165186785054 * fConst0)));
		fConst148 = (0.0 - (2.0 * fConst147));
		fConst149 = (cos((18812.279434835014 / fConst0)) * fConst148);
		fConst150 = mydsp_faustpower2_f(fConst147);
		fConst151 = pow(0.001, (1.0 / (0.19714325297800001 * fConst0)));
		fConst152 = (cos((19231.105693102796 / fConst0)) * (0.0 - (2.0 * fConst151)));
		fConst153 = mydsp_faustpower2_f(fConst151);
		fConst154 = (fConst61 * cos((19405.616634079121 / fConst0)));
		fConst155 = (fConst61 * cos((19545.225386835045 / fConst0)));
		fConst156 = pow(0.001, (1.0 / (0.147283463044 * fConst0)));
		fConst157 = (cos((20138.562586079152 / fConst0)) * (0.0 - (2.0 * fConst156)));
		fConst158 = mydsp_faustpower2_f(fConst156);
		fConst159 = (fConst85 * cos((20592.291032567329 / fConst0)));
		fConst160 = (fConst2 * cos((20871.508538079182 / fConst0)));
		fConst161 = (fConst111 * cos((21325.23698456736 / fConst0)));
		fConst162 = pow(0.001, (1.0 / (0.55544306068799998 * fConst0)));
		fConst163 = (0.0 - (2.0 * fConst162));
		fConst164 = (cos((21534.650113701249 / fConst0)) * fConst163);
		fConst165 = mydsp_faustpower2_f(fConst162);
		fConst166 = (fConst111 * cos((21848.769807433502 / fConst0)));
		fConst167 = (fConst103 * cos((22162.889501165751 / fConst0)));
		fConst168 = (fConst123 * cos((22791.128888567422 / fConst0)));
		fConst169 = (fConst111 * cos((23000.542017701311 / fConst0)));
		fConst170 = (fConst103 * cos((23419.368276031924 / fConst0)));
		fConst171 = pow(0.001, (1.0 / (0.015544329708500001 * fConst0)));
		fConst172 = (cos((23803.292346142138 / fConst0)) * (0.0 - (2.0 * fConst171)));
		fConst173 = mydsp_faustpower2_f(fConst171);
		fConst174 = (fConst163 * cos((24257.020792567484 / fConst0)));
		fConst175 = (fConst21 * cos((24815.455803654022 / fConst0)));
		fConst176 = (fConst12 * cos((25164.477685543839 / fConst0)));
		fConst177 = pow(0.001, (1.0 / (0.93992632156599998 * fConst0)));
		fConst178 = (cos((25653.108320252413 / fConst0)) * (0.0 - (2.0 * fConst177)));
		fConst179 = mydsp_faustpower2_f(fConst177);
		fConst180 = pow(0.001, (1.0 / (0.71878562230200005 * fConst0)));
		fConst181 = (0.0 - (2.0 * fConst180));
		fConst182 = (cos((26560.565213165941 / fConst0)) * fConst181);
		fConst183 = mydsp_faustpower2_f(fConst180);
		fConst184 = pow(0.001, (1.0 / (0.76370482680899998 * fConst0)));
		fConst185 = (0.0 - (2.0 * fConst184));
		fConst186 = (cos((27468.022106142293 / fConst0)) * fConst185);
		fConst187 = mydsp_faustpower2_f(fConst184);
		fConst188 = (fConst31 * cos((28375.478999118652 / fConst0)));
		fConst189 = pow(0.001, (1.0 / (0.106322048027 * fConst0)));
		fConst190 = (0.0 - (2.0 * fConst189));
		fConst191 = (cos((29352.740268472968 / fConst0)) * fConst190);
		fConst192 = mydsp_faustpower2_f(fConst189);
		fConst193 = pow(0.001, (1.0 / (0.16744854417400001 * fConst0)));
		fConst194 = (cos((30225.294973228927 / fConst0)) * (0.0 - (2.0 * fConst193)));
		fConst195 = mydsp_faustpower2_f(fConst193);
		fConst196 = pow(0.001, (1.0 / (0.174621551698 * fConst0)));
		fConst197 = (cos((31062.947489827318 / fConst0)) * (0.0 - (2.0 * fConst196)));
		fConst198 = mydsp_faustpower2_f(fConst196);
		fConst199 = pow(0.001, (1.0 / (0.15875398966000001 * fConst0)));
		fConst200 = (cos((31726.089065449389 / fConst0)) * (0.0 - (2.0 * fConst199)));
		fConst201 = mydsp_faustpower2_f(fConst199);
		fConst202 = (fConst148 * cos((32005.306570961238 / fConst0)));
		fConst203 = pow(0.001, (1.0 / (0.038140777462499997 * fConst0)));
		fConst204 = (0.0 - (2.0 * fConst203));
		fConst205 = (cos((33401.39409858334 / fConst0)) * fConst204);
		fConst206 = mydsp_faustpower2_f(fConst203);
		fConst207 = pow(0.001, (1.0 / (0.055614852744500003 * fConst0)));
		fConst208 = (cos((33820.220356851118 / fConst0)) * (0.0 - (2.0 * fConst207)));
		fConst209 = mydsp_faustpower2_f(fConst207);
		fConst210 = pow(0.001, (1.0 / (0.124752072014 * fConst0)));
		fConst211 = (cos((34553.166308851149 / fConst0)) * (0.0 - (2.0 * fConst210)));
		fConst212 = mydsp_faustpower2_f(fConst210);
		fConst213 = pow(0.001, (1.0 / (0.126037367835 * fConst0)));
		fConst214 = (cos((34797.481626205437 / fConst0)) * (0.0 - (2.0 * fConst213)));
		fConst215 = mydsp_faustpower2_f(fConst213);
		fConst216 = pow(0.001, (1.0 / (0.16977312994099999 * fConst0)));
		fConst217 = (0.0 - (2.0 * fConst216));
		fConst218 = (cos((35635.134142803829 / fConst0)) * fConst217);
		fConst219 = mydsp_faustpower2_f(fConst216);
		fConst220 = (fConst217 * cos((36333.177906583463 / fConst0)));
		fConst221 = (fConst217 * cos((36472.786659339385 / fConst0)));
		fConst222 = (fConst69 * cos((37031.221670425926 / fConst0)));
		fConst223 = pow(0.001, (1.0 / (0.015125307825399999 * fConst0)));
		fConst224 = (cos((38008.482939780246 / fConst0)) * (0.0 - (2.0 * fConst223)));
		fConst225 = mydsp_faustpower2_f(fConst223);
		fConst226 = (fConst185 * cos((38915.939832693766 / fConst0)));
		fConst227 = pow(0.001, (1.0 / (0.58188899920299997 * fConst0)));
		fConst228 = (cos((39823.396725670122 / fConst0)) * (0.0 - (2.0 * fConst227)));
		fConst229 = mydsp_faustpower2_f(fConst227);
		fConst230 = pow(0.001, (1.0 / (0.0119062269167 * fConst0)));
		fConst231 = (cos((40451.636113134628 / fConst0)) * (0.0 - (2.0 * fConst230)));
		fConst232 = mydsp_faustpower2_f(fConst230);
		fConst233 = pow(0.001, (1.0 / (0.0119176877079 * fConst0)));
		fConst234 = (cos((40730.853618646484 / fConst0)) * (0.0 - (2.0 * fConst233)));
		fConst235 = mydsp_faustpower2_f(fConst233);
		fConst236 = (fConst181 * cos((41603.408323402437 / fConst0)));
		fConst237 = (fConst185 * cos((42475.963028158396 / fConst0)));
		fConst238 = (fConst7 * cos((43418.322109355147 / fConst0)));
		fConst239 = pow(0.001, (1.0 / (0.28421843725099999 * fConst0)));
		fConst240 = (0.0 - (2.0 * fConst239));
		fConst241 = (cos((44046.561496756818 / fConst0)) * fConst240);
		fConst242 = mydsp_faustpower2_f(fConst239);
		fConst243 = pow(0.001, (1.0 / (0.13583417831200001 * fConst0)));
		fConst244 = (cos((44709.703072378885 / fConst0)) * (0.0 - (2.0 * fConst243)));
		fConst245 = mydsp_faustpower2_f(fConst243);
		fConst246 = pow(0.001, (1.0 / (0.13891953748999999 * fConst0)));
		fConst247 = (cos((44988.920577890742 / fConst0)) * (0.0 - (2.0 * fConst246)));
		fConst248 = mydsp_faustpower2_f(fConst246);
		fConst249 = pow(0.001, (1.0 / (0.14381981386199999 * fConst0)));
		fConst250 = (cos((45582.257777134844 / fConst0)) * (0.0 - (2.0 * fConst249)));
		fConst251 = mydsp_faustpower2_f(fConst249);
		fConst252 = pow(0.001, (1.0 / (0.145531021491 * fConst0)));
		fConst253 = (0.0 - (2.0 * fConst252));
		fConst254 = (cos((45791.670906331572 / fConst0)) * fConst253);
		fConst255 = mydsp_faustpower2_f(fConst252);
		fConst256 = (fConst21 * cos((46454.812481953632 / fConst0)));
		fConst257 = (fConst240 * cos((47222.660622111231 / fConst0)));
		fConst258 = (fConst253 * cos((48025.410950489226 / fConst0)));
		fConst259 = pow(0.001, (1.0 / (0.038621059178000003 * fConst0)));
		fConst260 = (cos((49037.574408063942 / fConst0)) * (0.0 - (2.0 * fConst259)));
		fConst261 = mydsp_faustpower2_f(fConst259);
		fConst262 = pow(0.001, (1.0 / (0.045330329407300002 * fConst0)));
		fConst263 = (0.0 - (2.0 * fConst262));
		fConst264 = (cos((49770.520360063972 / fConst0)) * fConst263);
		fConst265 = mydsp_faustpower2_f(fConst262);
		fConst266 = pow(0.001, (1.0 / (0.053666205970700001 * fConst0)));
		fConst267 = (cos((50643.075064819932 / fConst0)) * (0.0 - (2.0 * fConst266)));
		fConst268 = mydsp_faustpower2_f(fConst266);
		fConst269 = pow(0.001, (1.0 / (0.049745148756600001 * fConst0)));
		fConst270 = (cos((51445.825393197927 / fConst0)) * (0.0 - (2.0 * fConst269)));
		fConst271 = mydsp_faustpower2_f(fConst269);
		fConst272 = (fConst263 * cos((52388.184474394671 / fConst0)));
		fConst273 = pow(0.001, (1.0 / (0.045668030113600003 * fConst0)));
		fConst274 = (0.0 - (2.0 * fConst273));
		fConst275 = (cos((52597.597603528571 / fConst0)) * fConst274);
		fConst276 = mydsp_faustpower2_f(fConst273);
		fConst277 = (fConst274 * cos((53156.03261455227 / fConst0)));
		fConst278 = pow(0.001, (1.0 / (0.044833055848999999 * fConst0)));
		fConst279 = (cos((53574.858872820056 / fConst0)) * (0.0 - (2.0 * fConst278)));
		fConst280 = mydsp_faustpower2_f(fConst278);
		fConst281 = (fConst263 * cos((54063.489507528633 / fConst0)));
		fConst282 = pow(0.001, (1.0 / (0.047992205691000003 * fConst0)));
		fConst283 = (0.0 - (2.0 * fConst282));
		fConst284 = (cos((54517.217954016807 / fConst0)) * fConst283);
		fConst285 = mydsp_faustpower2_f(fConst282);
		fConst286 = pow(0.001, (1.0 / (0.053200225235000002 * fConst0)));
		fConst287 = (cos((55005.848588662549 / fConst0)) * (0.0 - (2.0 * fConst286)));
		fConst288 = mydsp_faustpower2_f(fConst286);
		fConst289 = pow(0.001, (1.0 / (0.049146754525299999 * fConst0)));
		fConst290 = (cos((55703.89235250502 / fConst0)) * (0.0 - (2.0 * fConst289)));
		fConst291 = mydsp_faustpower2_f(fConst289);
		fConst292 = pow(0.001, (1.0 / (0.048950481220099998 * fConst0)));
		fConst293 = (cos((55913.305481638905 / fConst0)) * (0.0 - (2.0 * fConst292)));
		fConst294 = mydsp_faustpower2_f(fConst292);
		fConst295 = (fConst274 * cos((56436.83830450505 / fConst0)));
		fConst296 = pow(0.001, (1.0 / (0.045838777663700002 * fConst0)));
		fConst297 = (cos((56716.0558100169 / fConst0)) * (0.0 - (2.0 * fConst296)));
		fConst298 = mydsp_faustpower2_f(fConst296);
		fConst299 = (fConst283 * cos((56960.371127371189 / fConst0)));
		fConst300 = pow(0.001, (1.0 / (0.045163348248099998 * fConst0)));
		fConst301 = (cos((57832.925832127141 / fConst0)) * (0.0 - (2.0 * fConst300)));
		fConst302 = mydsp_faustpower2_f(fConst300);
		fConst303 = pow(0.001, (1.0 / (0.043558903011800001 * fConst0)));
		fConst304 = (cos((58600.773972347575 / fConst0)) * (0.0 - (2.0 * fConst303)));
		fConst305 = mydsp_faustpower2_f(fConst303);
		fConst306 = pow(0.001, (1.0 / (0.038022571483799998 * fConst0)));
		fConst307 = (cos((59543.133053481492 / fConst0)) * (0.0 - (2.0 * fConst306)));
		fConst308 = mydsp_faustpower2_f(fConst306);
		fConst309 = pow(0.001, (1.0 / (0.0228308064216 * fConst0)));
		fConst310 = (cos((60171.372440883169 / fConst0)) * (0.0 - (2.0 * fConst309)));
		fConst311 = mydsp_faustpower2_f(fConst309);
		fConst312 = pow(0.001, (1.0 / (0.022704404858300001 * fConst0)));
		fConst313 = (0.0 - (2.0 * fConst312));
		fConst314 = (cos((61148.633710237489 / fConst0)) * fConst313);
		fConst315 = mydsp_faustpower2_f(fConst312);
		fConst316 = (fConst313 * cos((61323.144651213806 / fConst0)));
		fConst317 = pow(0.001, (1.0 / (0.0227885159351 * fConst0)));
		fConst318 = (cos((61951.384038615484 / fConst0)) * (0.0 - (2.0 * fConst317)));
		fConst319 = mydsp_faustpower2_f(fConst317);
		fConst320 = (fConst313 * cos((62160.797167812205 / fConst0)));
		fConst321 = pow(0.001, (1.0 / (0.0227463823712 * fConst0)));
		fConst322 = (cos((62789.036555213868 / fConst0)) * (0.0 - (2.0 * fConst321)));
		fConst323 = mydsp_faustpower2_f(fConst321);
		fConst324 = pow(0.001, (1.0 / (0.0066794237628100004 * fConst0)));
		fConst325 = (0.0 - (2.0 * fConst324));
		fConst326 = (cos((63696.493448190224 / fConst0)) * fConst325);
		fConst327 = mydsp_faustpower2_f(fConst324);
		fConst328 = (fConst325 * cos((63871.004389292219 / fConst0)));
		fConst329 = pow(0.001, (1.0 / (0.0065984149726699996 * fConst0)));
		fConst330 = (cos((64324.732835906056 / fConst0)) * (0.0 - (2.0 * fConst329)));
		fConst331 = mydsp_faustpower2_f(fConst329);
		fConst332 = pow(0.001, (1.0 / (0.0066053801895800002 * fConst0)));
		fConst333 = (cos((64534.145964725787 / fConst0)) * (0.0 - (2.0 * fConst332)));
		fConst334 = mydsp_faustpower2_f(fConst332);
		fConst335 = pow(0.001, (1.0 / (0.0065227674736 * fConst0)));
		fConst336 = (cos((65267.091916851481 / fConst0)) * (0.0 - (2.0 * fConst335)));
		fConst337 = mydsp_faustpower2_f(fConst335);
		fConst338 = pow(0.001, (1.0 / (0.0065879949798200001 * fConst0)));
		fConst339 = (cos((65546.309422363338 / fConst0)) * (0.0 - (2.0 * fConst338)));
		fConst340 = mydsp_faustpower2_f(fConst338);
		fConst341 = pow(0.001, (1.0 / (0.0060620478587199997 * fConst0)));
		fConst342 = (cos((66000.037868977175 / fConst0)) * (0.0 - (2.0 * fConst341)));
		fConst343 = mydsp_faustpower2_f(fConst341);
		fConst344 = pow(0.001, (1.0 / (0.0065024400703800004 * fConst0)));
		fConst345 = (cos((66349.059750552828 / fConst0)) * (0.0 - (2.0 * fConst344)));
		fConst346 = mydsp_faustpower2_f(fConst344);
		fConst347 = pow(0.001, (1.0 / (0.0060679135642600001 * fConst0)));
		fConst348 = (cos((67047.10351433247 / fConst0)) * (0.0 - (2.0 * fConst347)));
		fConst349 = mydsp_faustpower2_f(fConst347);
		fConst350 = pow(0.001, (1.0 / (0.0060649792744400001 * fConst0)));
		fConst351 = (0.0 - (2.0 * fConst350));
		fConst352 = (cos((67116.907891024588 / fConst0)) * fConst351);
		fConst353 = mydsp_faustpower2_f(fConst350);
		fConst354 = (fConst351 * cos((67256.516643780516 / fConst0)));
		fConst355 = (fConst351 * cos((67710.245090394368 / fConst0)));
		fConst356 = pow(0.001, (1.0 / (0.0060040166659900002 * fConst0)));
		fConst357 = (cos((68268.680101418067 / fConst0)) * (0.0 - (2.0 * fConst356)));
		fConst358 = mydsp_faustpower2_f(fConst356);
		fConst359 = pow(0.001, (1.0 / (0.0060097690754699999 * fConst0)));
		fConst360 = (0.0 - (2.0 * fConst359));
		fConst361 = (cos((68512.995418583858 / fConst0)) * fConst360);
		fConst362 = mydsp_faustpower2_f(fConst359);
		fConst363 = (fConst360 * cos((68582.799794647653 / fConst0)));
		fConst364 = pow(0.001, (1.0 / (0.0060386994958700002 * fConst0)));
		fConst365 = (cos((68687.506359685853 / fConst0)) * (0.0 - (2.0 * fConst364)));
		fConst366 = mydsp_faustpower2_f(fConst364);
		fConst367 = pow(0.001, (1.0 / (0.00607379078313 * fConst0)));
		fConst368 = (cos((69211.0391823635 / fConst0)) * (0.0 - (2.0 * fConst367)));
		fConst369 = mydsp_faustpower2_f(fConst367);
		fConst370 = pow(0.001, (1.0 / (0.0060591193128799996 * fConst0)));
		fConst371 = (cos((69804.376381733251 / fConst0)) * (0.0 - (2.0 * fConst370)));
		fConst372 = mydsp_faustpower2_f(fConst370);
		fConst373 = pow(0.001, (1.0 / (0.0060708507324099999 * fConst0)));
		fConst374 = (cos((70153.398263308918 / fConst0)) * (0.0 - (2.0 * fConst373)));
		fConst375 = mydsp_faustpower2_f(fConst373);
		fConst376 = pow(0.001, (1.0 / (0.0060445194847499996 * fConst0)));
		fConst377 = (0.0 - (2.0 * fConst376));
		fConst378 = (cos((70397.713581103017 / fConst0)) * fConst377);
		fConst379 = mydsp_faustpower2_f(fConst376);
		fConst380 = (fConst377 * cos((70502.420145512893 / fConst0)));
		fConst381 = pow(0.001, (1.0 / (0.0060068914751100003 * fConst0)));
		fConst382 = (0.0 - (2.0 * fConst381));
		fConst383 = (cos((70851.442027088546 / fConst0)) * fConst382);
		fConst384 = mydsp_faustpower2_f(fConst381);
		fConst385 = (fConst382 * cos((70991.050779844474 / fConst0)));
		fConst386 = pow(0.001, (1.0 / (0.0059925452608399999 * fConst0)));
		fConst387 = (cos((71374.974850394516 / fConst0)) * (0.0 - (2.0 * fConst386)));
		fConst388 = mydsp_faustpower2_f(fConst386);
		fConst389 = pow(0.001, (1.0 / (0.00598397081689 * fConst0)));
		fConst390 = (cos((72073.018614174143 / fConst0)) * (0.0 - (2.0 * fConst389)));
		fConst391 = mydsp_faustpower2_f(fConst389);
		fConst392 = pow(0.001, (1.0 / (0.0059274372612499997 * fConst0)));
		fConst393 = (cos((72666.355812915586 / fConst0)) * (0.0 - (2.0 * fConst392)));
		fConst394 = mydsp_faustpower2_f(fConst392);
		fConst395 = pow(0.001, (1.0 / (0.0059302382158199999 * fConst0)));
		fConst396 = (cos((72910.671130709699 / fConst0)) * (0.0 - (2.0 * fConst395)));
		fConst397 = mydsp_faustpower2_f(fConst395);
		fConst398 = pow(0.001, (1.0 / (0.0058968028314600003 * fConst0)));
		fConst399 = (cos((73329.497388977485 / fConst0)) * (0.0 - (2.0 * fConst398)));
		fConst400 = mydsp_faustpower2_f(fConst398);
		fConst401 = (fConst81 * cos((75528.335244726259 / fConst0)));
		fConst402 = pow(0.001, (1.0 / (0.095531676037600002 * fConst0)));
		fConst403 = (0.0 - (2.0 * fConst402));
		fConst404 = (cos((75807.552750238116 / fConst0)) * fConst403);
		fConst405 = mydsp_faustpower2_f(fConst402);
		fConst406 = (fConst190 * cos((76226.379008505886 / fConst0)));
		fConst407 = (fConst2 * cos((76645.205266773672 / fConst0)));
		fConst408 = pow(0.001, (1.0 / (0.18519992650100001 * fConst0)));
		fConst409 = (cos((76994.227148977647 / fConst0)) * (0.0 - (2.0 * fConst408)));
		fConst410 = mydsp_faustpower2_f(fConst408);
		fConst411 = pow(0.001, (1.0 / (0.097822554973599998 * fConst0)));
		fConst412 = (0.0 - (2.0 * fConst411));
		fConst413 = (cos((77447.955595591484 / fConst0)) * fConst412);
		fConst414 = mydsp_faustpower2_f(fConst411);
		fConst415 = (fConst85 * cos((77517.759971655294 / fConst0)));
		fConst416 = (fConst36 * cos((77692.270912757274 / fConst0)));
		fConst417 = (fConst81 * cos((78076.194982678993 / fConst0)));
		fConst418 = pow(0.001, (1.0 / (0.096283276735800005 * fConst0)));
		fConst419 = (cos((78355.41248819085 / fConst0)) * (0.0 - (2.0 * fConst418)));
		fConst420 = mydsp_faustpower2_f(fConst418);
		fConst421 = (fConst412 * cos((78564.825617638897 / fConst0)));
		fConst422 = (fConst81 * cos((78704.434370394825 / fConst0)));
		fConst423 = (fConst403 * cos((78878.945310868497 / fConst0)));
		fConst424 = (fConst403 * cos((78948.749687560616 / fConst0)));
		fConst425 = pow(0.001, (1.0 / (0.036226400298399998 * fConst0)));
		fConst426 = (0.0 - (2.0 * fConst425));
		fConst427 = (cos((81217.391920001493 / fConst0)) * fConst426);
		fConst428 = mydsp_faustpower2_f(fConst425);
		fConst429 = pow(0.001, (1.0 / (0.035803617353799999 * fConst0)));
		fConst430 = (cos((81461.707237167298 / fConst0)) * (0.0 - (2.0 * fConst429)));
		fConst431 = mydsp_faustpower2_f(fConst429);
		fConst432 = pow(0.001, (1.0 / (0.0404019058763 * fConst0)));
		fConst433 = (0.0 - (2.0 * fConst432));
		fConst434 = (cos((82299.359753702855 / fConst0)) * fConst433);
		fConst435 = mydsp_faustpower2_f(fConst432);
		fConst436 = (fConst433 * cos((82369.164130394987 / fConst0)));
		fConst437 = pow(0.001, (1.0 / (0.040269262917199997 * fConst0)));
		fConst438 = (cos((82438.968506458783 / fConst0)) * (0.0 - (2.0 * fConst437)));
		fConst439 = mydsp_faustpower2_f(fConst437);
		fConst440 = (fConst77 * cos((83137.012270238425 / fConst0)));
		fConst441 = pow(0.001, (1.0 / (0.12734944065600001 * fConst0)));
		fConst442 = (cos((83869.958222364119 / fConst0)) * (0.0 - (2.0 * fConst441)));
		fConst443 = mydsp_faustpower2_f(fConst441);
		fConst444 = (fConst73 * cos((84218.98010456808 / fConst0)));
		fConst445 = pow(0.001, (1.0 / (0.042798755050300001 * fConst0)));
		fConst446 = (0.0 - (2.0 * fConst445));
		fConst447 = (cos((84428.393233387818 / fConst0)) * fConst446);
		fConst448 = mydsp_faustpower2_f(fConst445);
		fConst449 = pow(0.001, (1.0 / (0.042649903780500001 * fConst0)));
		fConst450 = (0.0 - (2.0 * fConst449));
		fConst451 = (cos((84498.197610079937 / fConst0)) * fConst450);
		fConst452 = mydsp_faustpower2_f(fConst449);
		fConst453 = (fConst450 * cos((84568.001986143747 / fConst0)));
		fConst454 = (fConst450 * cos((84707.610738899675 / fConst0)));
		fConst455 = (fConst446 * cos((84951.926056065466 / fConst0)));
		fConst456 = (fConst433 * cos((85615.067632127364 / fConst0)));
		fConst457 = (fConst433 * cos((85684.87200819116 / fConst0)));
		fConst458 = pow(0.001, (1.0 / (0.040137489749199999 * fConst0)));
		fConst459 = (cos((85789.578573229344 / fConst0)) * (0.0 - (2.0 * fConst458)));
		fConst460 = mydsp_faustpower2_f(fConst458);
		fConst461 = pow(0.001, (1.0 / (0.038379412732800003 * fConst0)));
		fConst462 = (0.0 - (2.0 * fConst461));
		fConst463 = (cos((85964.089513703017 / fConst0)) * fConst462);
		fConst464 = mydsp_faustpower2_f(fConst461);
		fConst465 = pow(0.001, (1.0 / (0.037905097431799997 * fConst0)));
		fConst466 = (0.0 - (2.0 * fConst465));
		fConst467 = (cos((86313.111395906992 / fConst0)) * fConst466);
		fConst468 = mydsp_faustpower2_f(fConst465);
		fConst469 = (fConst466 * cos((86452.72014866292 / fConst0)));
		fConst470 = (fConst204 * cos((86627.2310897649 / fConst0)));
		fConst471 = pow(0.001, (1.0 / (0.038259722229499998 * fConst0)));
		fConst472 = (0.0 - (2.0 * fConst471));
		fConst473 = (cos((86731.937654174762 / fConst0)) * fConst472);
		fConst474 = mydsp_faustpower2_f(fConst471);
		fConst475 = (fConst472 * cos((86836.644218584639 / fConst0)));
		fConst476 = (fConst472 * cos((86906.448595276757 / fConst0)));
		fConst477 = (fConst462 * cos((87011.155159686619 / fConst0)));
		fConst478 = (fConst472 * cos((87185.666100788614 / fConst0)));
		fConst479 = (fConst462 * cos((87325.274853544543 / fConst0)));
		fConst480 = pow(0.001, (1.0 / (0.038499856007600003 * fConst0)));
		fConst481 = (0.0 - (2.0 * fConst480));
		fConst482 = (cos((87395.079229608338 / fConst0)) * fConst481);
		fConst483 = mydsp_faustpower2_f(fConst480);
		fConst484 = (fConst481 * cos((87499.7857940182 / fConst0)));
		fConst485 = pow(0.001, (1.0 / (0.041355501235400001 * fConst0)));
		fConst486 = (0.0 - (2.0 * fConst485));
		fConst487 = (cos((87779.003299530057 / fConst0)) * fConst486);
		fConst488 = mydsp_faustpower2_f(fConst485);
		fConst489 = (fConst486 * cos((87848.80767622219 / fConst0)));
		fConst490 = pow(0.001, (1.0 / (0.041216521244700002 * fConst0)));
		fConst491 = (0.0 - (2.0 * fConst490));
		fConst492 = (cos((87988.416428978104 / fConst0)) * fConst491);
		fConst493 = mydsp_faustpower2_f(fConst490);
		fConst494 = pow(0.001, (1.0 / (0.042209509340999998 * fConst0)));
		fConst495 = (0.0 - (2.0 * fConst494));
		fConst496 = (cos((88232.731746143894 / fConst0)) * fConst495);
		fConst497 = mydsp_faustpower2_f(fConst494);
		fConst498 = (fConst450 * cos((88337.438311182093 / fConst0)));
		fConst499 = (fConst450 * cos((88407.242687245889 / fConst0)));
		fConst500 = (fConst450 * cos((88511.949251655751 / fConst0)));
		fConst501 = (fConst450 * cos((88616.655816693936 / fConst0)));
		fConst502 = (fConst450 * cos((88686.460192757746 / fConst0)));
		fConst503 = pow(0.001, (1.0 / (0.080992434005400002 * fConst0)));
		fConst504 = (0.0 - (2.0 * fConst503));
		fConst505 = (cos((89070.38426267945 / fConst0)) * fConst504);
		fConst506 = mydsp_faustpower2_f(fConst503);
		fConst507 = (fConst504 * cos((89244.895203781445 / fConst0)));
		fConst508 = (fConst504 * cos((89559.014897639354 / fConst0)));
		fConst509 = pow(0.001, (1.0 / (0.094791728066100006 * fConst0)));
		fConst510 = (cos((89698.623650395297 / fConst0)) * (0.0 - (2.0 * fConst509)));
		fConst511 = mydsp_faustpower2_f(fConst509);
		fConst512 = (fConst403 * cos((89803.330214805144 / fConst0)));
		fConst513 = (fConst403 * cos((89873.134591497277 / fConst0)));
		fConst514 = (fConst403 * cos((89977.841155907139 / fConst0)));
		fConst515 = (fConst504 * cos((90082.547720317001 / fConst0)));
		fConst516 = pow(0.001, (1.0 / (0.081531860931600003 * fConst0)));
		fConst517 = (cos((90187.254284726878 / fConst0)) * (0.0 - (2.0 * fConst516)));
		fConst518 = mydsp_faustpower2_f(fConst516);
		fConst519 = pow(0.001, (1.0 / (0.0789043297965 * fConst0)));
		fConst520 = (0.0 - (2.0 * fConst519));
		fConst521 = (cos((90326.863037482792 / fConst0)) * fConst520);
		fConst522 = mydsp_faustpower2_f(fConst519);
		fConst523 = (fConst446 * cos((90431.569602520991 / fConst0)));
		fConst524 = (fConst450 * cos((90536.276166930853 / fConst0)));
		fConst525 = (fConst495 * cos((90606.080542994649 / fConst0)));
		fConst526 = (fConst450 * cos((90675.884919686781 / fConst0)));
		fConst527 = (fConst450 * cos((90780.591484096643 / fConst0)));
		fConst528 = (fConst495 * cos((90920.200236852572 / fConst0)));
		fConst529 = pow(0.001, (1.0 / (0.042064729040700001 * fConst0)));
		fConst530 = (cos((91024.906801262434 / fConst0)) * (0.0 - (2.0 * fConst529)));
		fConst531 = mydsp_faustpower2_f(fConst529);
		fConst532 = pow(0.001, (1.0 / (0.041495423464600001 * fConst0)));
		fConst533 = (cos((91269.222119056547 / fConst0)) * (0.0 - (2.0 * fConst532)));
		fConst534 = mydsp_faustpower2_f(fConst532);
		fConst535 = (fConst491 * cos((91373.928683466409 / fConst0)));
		fConst536 = pow(0.001, (1.0 / (0.040941350162599997 * fConst0)));
		fConst537 = (cos((91443.733060158527 / fConst0)) * (0.0 - (2.0 * fConst536)));
		fConst538 = mydsp_faustpower2_f(fConst536);
		fConst539 = (fConst466 * cos((91827.657130080246 / fConst0)));
		fConst540 = pow(0.001, (1.0 / (0.0376723180826 * fConst0)));
		fConst541 = (0.0 - (2.0 * fConst540));
		fConst542 = (cos((91932.363694490123 / fConst0)) * fConst541);
		fConst543 = mydsp_faustpower2_f(fConst540);
		fConst544 = pow(0.001, (1.0 / (0.037328471764899999 * fConst0)));
		fConst545 = (cos((92002.168071182241 / fConst0)) * (0.0 - (2.0 * fConst544)));
		fConst546 = mydsp_faustpower2_f(fConst544);
		fConst547 = pow(0.001, (1.0 / (0.033829851895599998 * fConst0)));
		fConst548 = (0.0 - (2.0 * fConst547));
		fConst549 = (cos((92351.189952757893 / fConst0)) * fConst548);
		fConst550 = mydsp_faustpower2_f(fConst547);
		fConst551 = (fConst548 * cos((95003.756255120505 / fConst0)));
		fConst552 = pow(0.001, (1.0 / (0.034398695496599997 * fConst0)));
		fConst553 = (0.0 - (2.0 * fConst552));
		fConst554 = (cos((95073.560631812623 / fConst0)) * fConst553);
		fConst555 = mydsp_faustpower2_f(fConst552);
		fConst556 = pow(0.001, (1.0 / (0.036013765344900001 * fConst0)));
		fConst557 = (0.0 - (2.0 * fConst556));
		fConst558 = (cos((95143.365007876433 / fConst0)) * fConst557);
		fConst559 = mydsp_faustpower2_f(fConst556);
		fConst560 = (fConst557 * cos((95248.071572914618 / fConst0)));
		fConst561 = (fConst204 * cos((95317.875948978413 / fConst0)));
		fConst562 = (fConst541 * cos((95387.680325670546 / fConst0)));
		fConst563 = (fConst204 * cos((95492.386890080408 / fConst0)));
		fConst564 = pow(0.001, (1.0 / (0.063713916777299998 * fConst0)));
		fConst565 = (0.0 - (2.0 * fConst564));
		fConst566 = (cos((95666.897831182403 / fConst0)) * fConst565);
		fConst567 = mydsp_faustpower2_f(fConst564);
		fConst568 = pow(0.001, (1.0 / (0.069498963184800006 * fConst0)));
		fConst569 = (0.0 - (2.0 * fConst568));
		fConst570 = (cos((95771.604395592265 / fConst0)) * fConst569);
		fConst571 = mydsp_faustpower2_f(fConst568);
		fConst572 = pow(0.001, (1.0 / (0.077900177785300007 * fConst0)));
		fConst573 = (cos((95841.408771656061 / fConst0)) * (0.0 - (2.0 * fConst572)));
		fConst574 = mydsp_faustpower2_f(fConst572);
		fConst575 = pow(0.001, (1.0 / (0.086120788670400003 * fConst0)));
		fConst576 = (cos((95981.017524411989 / fConst0)) * (0.0 - (2.0 * fConst575)));
		fConst577 = mydsp_faustpower2_f(fConst575);
		fConst578 = (cos((96050.821901104107 / fConst0)) * fConst520);
		fConst579 = (cos((96120.626277167918 / fConst0)) * fConst520);
		fConst580 = pow(0.001, (1.0 / (0.072374371026199993 * fConst0)));
		fConst581 = (0.0 - (2.0 * fConst580));
		fConst582 = (cos((96190.43065386005 / fConst0)) * fConst581);
		fConst583 = mydsp_faustpower2_f(fConst580);
		fConst584 = (fConst581 * cos((96330.039406615964 / fConst0)));
		fConst585 = (fConst581 * cos((96434.745971025841 / fConst0)));
		fConst586 = (fConst581 * cos((96574.354723781755 / fConst0)));
		fConst587 = pow(0.001, (1.0 / (0.075498271004600007 * fConst0)));
		fConst588 = (0.0 - (2.0 * fConst587));
		fConst589 = (cos((96713.963476537683 / fConst0)) * fConst588);
		fConst590 = mydsp_faustpower2_f(fConst587);
		fConst591 = (fConst581 * cos((96783.767853229801 / fConst0)));
		fConst592 = (fConst588 * cos((96958.278793703488 / fConst0)));
		fConst593 = (fConst581 * cos((97028.083170395606 / fConst0)));
		fConst594 = (fConst569 * cos((97097.887546459402 / fConst0)));
		fConst595 = (fConst581 * cos((97202.594111497587 / fConst0)));
		fConst596 = (fConst581 * cos((97272.398487561397 / fConst0)));
		fConst597 = (fConst581 * cos((97377.105051971259 / fConst0)));
		fConst598 = (fConst581 * cos((97516.71380535551 / fConst0)));
		fConst599 = (fConst565 * cos((97656.322558111438 / fConst0)));
		fConst600 = (fConst565 * cos((97726.126934175234 / fConst0)));
		fConst601 = pow(0.001, (1.0 / (0.064383764231400006 * fConst0)));
		fConst602 = (cos((97830.833498585096 / fConst0)) * (0.0 - (2.0 * fConst601)));
		fConst603 = mydsp_faustpower2_f(fConst601);
		fConst604 = pow(0.001, (1.0 / (0.058259444938199997 * fConst0)));
		fConst605 = (0.0 - (2.0 * fConst604));
		fConst606 = (cos((97970.442251341025 / fConst0)) * fConst605);
		fConst607 = mydsp_faustpower2_f(fConst604);
		fConst608 = pow(0.001, (1.0 / (0.064047086976099996 * fConst0)));
		fConst609 = (cos((98075.148816379209 / fConst0)) * (0.0 - (2.0 * fConst608)));
		fConst610 = mydsp_faustpower2_f(fConst608);
		fConst611 = (fConst605 * cos((98144.953192443005 / fConst0)));
		fConst612 = (fConst541 * cos((98284.561945198948 / fConst0)));
		fConst613 = (fConst541 * cos((98389.268509608795 / fConst0)));
		fConst614 = (fConst541 * cos((98459.072886300928 / fConst0)));
		fConst615 = (fConst541 * cos((98563.77945071079 / fConst0)));
		fConst616 = (fConst541 * cos((98633.583827402908 / fConst0)));
		fConst617 = (fConst204 * cos((98738.290391812785 / fConst0)));
		fConst618 = (fConst204 * cos((98842.996956222647 / fConst0)));
		fConst619 = (fConst204 * cos((98912.801332914765 / fConst0)));
		fConst620 = (fConst204 * cos((98982.605708978575 / fConst0)));
		fConst621 = (fConst541 * cos((99087.312273388437 / fConst0)));
		fConst622 = (fConst204 * cos((99226.921026144366 / fConst0)));
		fConst623 = (fConst541 * cos((99296.725402836484 / fConst0)));
		fConst624 = (fConst541 * cos((99436.334155592413 / fConst0)));
		fConst625 = pow(0.001, (1.0 / (0.036659309796600002 * fConst0)));
		fConst626 = (0.0 - (2.0 * fConst625));
		fConst627 = (cos((99610.845096694393 / fConst0)) * fConst626);
		fConst628 = mydsp_faustpower2_f(fConst625);
		fConst629 = (fConst204 * cos((99855.160413860198 / fConst0)));
		fConst630 = (fConst541 * cos((99924.964789923994 / fConst0)));
		fConst631 = (fConst553 * cos((100029.67135496218 / fConst0)));
		fConst632 = (fConst626 * cos((100169.28010771811 / fConst0)));
		fConst633 = (fConst426 * cos((100308.88886047404 / fConst0)));
		fConst634 = (fConst557 * cos((100413.5954248839 / fConst0)));
		fConst635 = (fConst553 * cos((100483.39980157603 / fConst0)));
		fConst636 = (fConst548 * cos((100588.10636598589 / fConst0)));
		fConst637 = (fConst548 * cos((100727.71511874182 / fConst0)));
		fConst638 = (fConst548 * cos((100902.2260598438 / fConst0)));
		fConst639 = (fConst557 * cos((101006.93262425368 / fConst0)));
		fConst640 = (fConst548 * cos((101146.54137700959 / fConst0)));
		fConst641 = (fConst553 * cos((101251.24794141947 / fConst0)));
		fConst642 = (fConst548 * cos((101321.05231811159 / fConst0)));
		fConst643 = pow(0.001, (1.0 / (0.033370023759999999 * fConst0)));
		fConst644 = (0.0 - (2.0 * fConst643));
		fConst645 = (cos((101390.85669417538 / fConst0)) * fConst644);
		fConst646 = mydsp_faustpower2_f(fConst643);
		fConst647 = (fConst548 * cos((101530.46544693132 / fConst0)));
		fConst648 = (fConst548 * cos((101635.17201134117 / fConst0)));
		fConst649 = (fConst548 * cos((101774.78076409712 / fConst0)));
		fConst650 = (fConst548 * cos((101879.48732913529 / fConst0)));
		fConst651 = (fConst548 * cos((101984.19389354516 / fConst0)));
		fConst652 = (fConst99 * cos((102053.99826960896 / fConst0)));
		fConst653 = (fConst99 * cos((102158.70483464714 / fConst0)));
		fConst654 = (fConst548 * cos((102403.02015181293 / fConst0)));
		fConst655 = (fConst548 * cos((102507.72671622281 / fConst0)));
		fConst656 = (fConst548 * cos((102577.53109291493 / fConst0)));
		fConst657 = (fConst644 * cos((102786.94422173467 / fConst0)));
		fConst658 = (fConst548 * cos((102856.74859842678 / fConst0)));
		fConst659 = (fConst548 * cos((102961.45516283665 / fConst0)));
		fConst660 = pow(0.001, (1.0 / (0.033736872871299999 * fConst0)));
		fConst661 = (cos((103066.16172724651 / fConst0)) * (0.0 - (2.0 * fConst660)));
		fConst662 = mydsp_faustpower2_f(fConst660);
		fConst663 = (fConst644 * cos((103170.86829165638 / fConst0)));
		fConst664 = (fConst548 * cos((103275.57485669457 / fConst0)));
		fConst665 = (fConst553 * cos((103415.18360945048 / fConst0)));
		fConst666 = (fConst548 * cos((103554.79236220641 / fConst0)));
		fConst667 = pow(0.001, (1.0 / (0.034987042341200002 * fConst0)));
		fConst668 = (0.0 - (2.0 * fConst667));
		fConst669 = (cos((103659.49892661627 / fConst0)) * fConst668);
		fConst670 = mydsp_faustpower2_f(fConst667);
		fConst671 = (fConst626 * cos((103764.20549102615 / fConst0)));
		fConst672 = (fConst668 * cos((103868.91205606432 / fConst0)));
		fConst673 = (fConst626 * cos((103938.71643212813 / fConst0)));
		fConst674 = (fConst541 * cos((104008.52080882025 / fConst0)));
		fConst675 = (fConst557 * cos((104078.32518488406 / fConst0)));
		fConst676 = (fConst626 * cos((104183.03174929392 / fConst0)));
		fConst677 = (fConst626 * cos((104287.73831433212 / fConst0)));
		fConst678 = (fConst668 * cos((104357.5426903959 / fConst0)));
		fConst679 = (fConst541 * cos((104532.0536314979 / fConst0)));
		fConst680 = (fConst557 * cos((104636.76019590777 / fConst0)));
		fConst681 = (fConst472 * cos((104706.56457259989 / fConst0)));
		fConst682 = (fConst541 * cos((104846.1733253558 / fConst0)));
		fConst683 = (fConst426 * cos((104915.97770141962 / fConst0)));
		fConst684 = (fConst426 * cos((105055.58645417554 / fConst0)));
		fConst685 = (fConst426 * cos((105125.39083086768 / fConst0)));
		fConst686 = (fConst626 * cos((105264.9995836236 / fConst0)));
		fConst687 = (fConst553 * cos((105334.80395968739 / fConst0)));
		fConst688 = (fConst553 * cos((105404.60833637952 / fConst0)));
		fConst689 = (fConst553 * cos((105474.41271244333 / fConst0)));
		fConst690 = (fConst548 * cos((105544.21708913545 / fConst0)));
		fConst691 = pow(0.001, (1.0 / (0.035595912947999998 * fConst0)));
		fConst692 = (cos((105614.02146519926 / fConst0)) * (0.0 - (2.0 * fConst691)));
		fConst693 = mydsp_faustpower2_f(fConst691);
		fConst694 = (fConst548 * cos((105718.7280296091 / fConst0)));
		fConst695 = (fConst548 * cos((105858.33678236503 / fConst0)));
		fConst696 = (fConst553 * cos((105928.14115905717 / fConst0)));
		fConst697 = (fConst99 * cos((105997.94553512098 / fConst0)));
		fConst698 = (fConst548 * cos((106102.65210015916 / fConst0)));
		fConst699 = pow(0.001, (1.0 / (0.032573151440800002 * fConst0)));
		fConst700 = (0.0 - (2.0 * fConst699));
		fConst701 = (cos((106172.45647622294 / fConst0)) * fConst700);
		fConst702 = mydsp_faustpower2_f(fConst699);
		fConst703 = (fConst700 * cos((106242.26085291509 / fConst0)));
		fConst704 = (fConst700 * cos((106695.98929952891 / fConst0)));
		
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
		for (int l295 = 0; (l295 < 3); l295 = (l295 + 1)) {
			fRec295[l295] = 0.0;
			
		}
		for (int l296 = 0; (l296 < 3); l296 = (l296 + 1)) {
			fRec296[l296] = 0.0;
			
		}
		for (int l297 = 0; (l297 < 3); l297 = (l297 + 1)) {
			fRec297[l297] = 0.0;
			
		}
		for (int l298 = 0; (l298 < 3); l298 = (l298 + 1)) {
			fRec298[l298] = 0.0;
			
		}
		for (int l299 = 0; (l299 < 3); l299 = (l299 + 1)) {
			fRec299[l299] = 0.0;
			
		}
		for (int l300 = 0; (l300 < 3); l300 = (l300 + 1)) {
			fRec300[l300] = 0.0;
			
		}
		for (int l301 = 0; (l301 < 3); l301 = (l301 + 1)) {
			fRec301[l301] = 0.0;
			
		}
		for (int l302 = 0; (l302 < 3); l302 = (l302 + 1)) {
			fRec302[l302] = 0.0;
			
		}
		for (int l303 = 0; (l303 < 3); l303 = (l303 + 1)) {
			fRec303[l303] = 0.0;
			
		}
		for (int l304 = 0; (l304 < 3); l304 = (l304 + 1)) {
			fRec304[l304] = 0.0;
			
		}
		for (int l305 = 0; (l305 < 3); l305 = (l305 + 1)) {
			fRec305[l305] = 0.0;
			
		}
		for (int l306 = 0; (l306 < 3); l306 = (l306 + 1)) {
			fRec306[l306] = 0.0;
			
		}
		for (int l307 = 0; (l307 < 3); l307 = (l307 + 1)) {
			fRec307[l307] = 0.0;
			
		}
		for (int l308 = 0; (l308 < 3); l308 = (l308 + 1)) {
			fRec308[l308] = 0.0;
			
		}
		for (int l309 = 0; (l309 < 3); l309 = (l309 + 1)) {
			fRec309[l309] = 0.0;
			
		}
		for (int l310 = 0; (l310 < 3); l310 = (l310 + 1)) {
			fRec310[l310] = 0.0;
			
		}
		for (int l311 = 0; (l311 < 3); l311 = (l311 + 1)) {
			fRec311[l311] = 0.0;
			
		}
		for (int l312 = 0; (l312 < 3); l312 = (l312 + 1)) {
			fRec312[l312] = 0.0;
			
		}
		for (int l313 = 0; (l313 < 3); l313 = (l313 + 1)) {
			fRec313[l313] = 0.0;
			
		}
		for (int l314 = 0; (l314 < 3); l314 = (l314 + 1)) {
			fRec314[l314] = 0.0;
			
		}
		for (int l315 = 0; (l315 < 3); l315 = (l315 + 1)) {
			fRec315[l315] = 0.0;
			
		}
		for (int l316 = 0; (l316 < 3); l316 = (l316 + 1)) {
			fRec316[l316] = 0.0;
			
		}
		for (int l317 = 0; (l317 < 3); l317 = (l317 + 1)) {
			fRec317[l317] = 0.0;
			
		}
		for (int l318 = 0; (l318 < 3); l318 = (l318 + 1)) {
			fRec318[l318] = 0.0;
			
		}
		for (int l319 = 0; (l319 < 3); l319 = (l319 + 1)) {
			fRec319[l319] = 0.0;
			
		}
		for (int l320 = 0; (l320 < 3); l320 = (l320 + 1)) {
			fRec320[l320] = 0.0;
			
		}
		for (int l321 = 0; (l321 < 3); l321 = (l321 + 1)) {
			fRec321[l321] = 0.0;
			
		}
		for (int l322 = 0; (l322 < 3); l322 = (l322 + 1)) {
			fRec322[l322] = 0.0;
			
		}
		for (int l323 = 0; (l323 < 3); l323 = (l323 + 1)) {
			fRec323[l323] = 0.0;
			
		}
		for (int l324 = 0; (l324 < 3); l324 = (l324 + 1)) {
			fRec324[l324] = 0.0;
			
		}
		for (int l325 = 0; (l325 < 3); l325 = (l325 + 1)) {
			fRec325[l325] = 0.0;
			
		}
		for (int l326 = 0; (l326 < 3); l326 = (l326 + 1)) {
			fRec326[l326] = 0.0;
			
		}
		for (int l327 = 0; (l327 < 3); l327 = (l327 + 1)) {
			fRec327[l327] = 0.0;
			
		}
		for (int l328 = 0; (l328 < 3); l328 = (l328 + 1)) {
			fRec328[l328] = 0.0;
			
		}
		for (int l329 = 0; (l329 < 3); l329 = (l329 + 1)) {
			fRec329[l329] = 0.0;
			
		}
		for (int l330 = 0; (l330 < 3); l330 = (l330 + 1)) {
			fRec330[l330] = 0.0;
			
		}
		for (int l331 = 0; (l331 < 3); l331 = (l331 + 1)) {
			fRec331[l331] = 0.0;
			
		}
		for (int l332 = 0; (l332 < 3); l332 = (l332 + 1)) {
			fRec332[l332] = 0.0;
			
		}
		for (int l333 = 0; (l333 < 3); l333 = (l333 + 1)) {
			fRec333[l333] = 0.0;
			
		}
		for (int l334 = 0; (l334 < 3); l334 = (l334 + 1)) {
			fRec334[l334] = 0.0;
			
		}
		for (int l335 = 0; (l335 < 3); l335 = (l335 + 1)) {
			fRec335[l335] = 0.0;
			
		}
		for (int l336 = 0; (l336 < 3); l336 = (l336 + 1)) {
			fRec336[l336] = 0.0;
			
		}
		for (int l337 = 0; (l337 < 3); l337 = (l337 + 1)) {
			fRec337[l337] = 0.0;
			
		}
		for (int l338 = 0; (l338 < 3); l338 = (l338 + 1)) {
			fRec338[l338] = 0.0;
			
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
		ui_interface->openVerticalBox("cabinetFenderBlackfaceBass");
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
			fRec2[0] = (fTemp1 - ((fConst8 * fRec2[1]) + (fConst9 * fRec2[2])));
			fRec3[0] = (fTemp1 - ((fConst10 * fRec3[1]) + (fConst4 * fRec3[2])));
			fRec4[0] = (fTemp1 - ((fConst13 * fRec4[1]) + (fConst14 * fRec4[2])));
			fRec5[0] = (fTemp1 - ((fConst17 * fRec5[1]) + (fConst18 * fRec5[2])));
			fRec6[0] = (fTemp1 - ((fConst19 * fRec6[1]) + (fConst18 * fRec6[2])));
			fRec7[0] = (fTemp1 - ((fConst22 * fRec7[1]) + (fConst23 * fRec7[2])));
			fRec8[0] = (fTemp1 - ((fConst25 * fRec8[1]) + (fConst26 * fRec8[2])));
			fRec9[0] = (fTemp1 - ((fConst28 * fRec9[1]) + (fConst29 * fRec9[2])));
			fRec10[0] = (fTemp1 - ((fConst32 * fRec10[1]) + (fConst33 * fRec10[2])));
			fRec11[0] = (fTemp1 - ((fConst34 * fRec11[1]) + (fConst33 * fRec11[2])));
			fRec12[0] = (fTemp1 - ((fConst37 * fRec12[1]) + (fConst38 * fRec12[2])));
			fRec13[0] = (fTemp1 - ((fConst41 * fRec13[1]) + (fConst42 * fRec13[2])));
			fRec14[0] = (fTemp1 - ((fConst43 * fRec14[1]) + (fConst42 * fRec14[2])));
			fRec15[0] = (fTemp1 - ((fConst46 * fRec15[1]) + (fConst47 * fRec15[2])));
			fRec16[0] = (fTemp1 - ((fConst49 * fRec16[1]) + (fConst50 * fRec16[2])));
			fRec17[0] = (fTemp1 - ((fConst53 * fRec17[1]) + (fConst54 * fRec17[2])));
			fRec18[0] = (fTemp1 - ((fConst55 * fRec18[1]) + (fConst54 * fRec18[2])));
			fRec19[0] = (fTemp1 - ((fConst58 * fRec19[1]) + (fConst59 * fRec19[2])));
			fRec20[0] = (fTemp1 - ((fConst62 * fRec20[1]) + (fConst63 * fRec20[2])));
			fRec21[0] = (fTemp1 - ((fConst65 * fRec21[1]) + (fConst66 * fRec21[2])));
			fRec22[0] = (fTemp1 - ((fConst67 * fRec22[1]) + (fConst59 * fRec22[2])));
			fRec23[0] = (fTemp1 - ((fConst70 * fRec23[1]) + (fConst71 * fRec23[2])));
			fRec24[0] = (fTemp1 - ((fConst74 * fRec24[1]) + (fConst75 * fRec24[2])));
			fRec25[0] = (fTemp1 - ((fConst78 * fRec25[1]) + (fConst79 * fRec25[2])));
			fRec26[0] = (fTemp1 - ((fConst82 * fRec26[1]) + (fConst83 * fRec26[2])));
			fRec27[0] = (fTemp1 - ((fConst86 * fRec27[1]) + (fConst87 * fRec27[2])));
			fRec28[0] = (fTemp1 - ((fConst88 * fRec28[1]) + (fConst87 * fRec28[2])));
			fRec29[0] = (fTemp1 - ((fConst90 * fRec29[1]) + (fConst91 * fRec29[2])));
			fRec30[0] = (fTemp1 - ((fConst93 * fRec30[1]) + (fConst94 * fRec30[2])));
			fRec31[0] = (fTemp1 - ((fConst96 * fRec31[1]) + (fConst97 * fRec31[2])));
			fRec32[0] = (fTemp1 - ((fConst100 * fRec32[1]) + (fConst101 * fRec32[2])));
			fRec33[0] = (fTemp1 - ((fConst104 * fRec33[1]) + (fConst105 * fRec33[2])));
			fRec34[0] = (fTemp1 - ((fConst107 * fRec34[1]) + (fConst108 * fRec34[2])));
			fRec35[0] = (fTemp1 - ((fConst109 * fRec35[1]) + (fConst105 * fRec35[2])));
			fRec36[0] = (fTemp1 - ((fConst112 * fRec36[1]) + (fConst113 * fRec36[2])));
			fRec37[0] = (fTemp1 - ((fConst114 * fRec37[1]) + (fConst54 * fRec37[2])));
			fRec38[0] = (fTemp1 - ((fConst115 * fRec38[1]) + (fConst54 * fRec38[2])));
			fRec39[0] = (fTemp1 - ((fConst117 * fRec39[1]) + (fConst118 * fRec39[2])));
			fRec40[0] = (fTemp1 - ((fConst120 * fRec40[1]) + (fConst121 * fRec40[2])));
			fRec41[0] = (fTemp1 - ((fConst124 * fRec41[1]) + (fConst125 * fRec41[2])));
			fRec42[0] = (fTemp1 - ((fConst127 * fRec42[1]) + (fConst128 * fRec42[2])));
			fRec43[0] = (fTemp1 - ((fConst129 * fRec43[1]) + (fConst9 * fRec43[2])));
			fRec44[0] = (fTemp1 - ((fConst131 * fRec44[1]) + (fConst132 * fRec44[2])));
			fRec45[0] = (fTemp1 - ((fConst134 * fRec45[1]) + (fConst135 * fRec45[2])));
			fRec46[0] = (fTemp1 - ((fConst136 * fRec46[1]) + (fConst4 * fRec46[2])));
			fRec47[0] = (fTemp1 - ((fConst138 * fRec47[1]) + (fConst139 * fRec47[2])));
			fRec48[0] = (fTemp1 - ((fConst140 * fRec48[1]) + (fConst47 * fRec48[2])));
			fRec49[0] = (fTemp1 - ((fConst142 * fRec49[1]) + (fConst143 * fRec49[2])));
			fRec50[0] = (fTemp1 - ((fConst145 * fRec50[1]) + (fConst146 * fRec50[2])));
			fRec51[0] = (fTemp1 - ((fConst149 * fRec51[1]) + (fConst150 * fRec51[2])));
			fRec52[0] = (fTemp1 - ((fConst152 * fRec52[1]) + (fConst153 * fRec52[2])));
			fRec53[0] = (fTemp1 - ((fConst154 * fRec53[1]) + (fConst63 * fRec53[2])));
			fRec54[0] = (fTemp1 - ((fConst155 * fRec54[1]) + (fConst63 * fRec54[2])));
			fRec55[0] = (fTemp1 - ((fConst157 * fRec55[1]) + (fConst158 * fRec55[2])));
			fRec56[0] = (fTemp1 - ((fConst159 * fRec56[1]) + (fConst87 * fRec56[2])));
			fRec57[0] = (fTemp1 - ((fConst160 * fRec57[1]) + (fConst4 * fRec57[2])));
			fRec58[0] = (fTemp1 - ((fConst161 * fRec58[1]) + (fConst113 * fRec58[2])));
			fRec59[0] = (fTemp1 - ((fConst164 * fRec59[1]) + (fConst165 * fRec59[2])));
			fRec60[0] = (fTemp1 - ((fConst166 * fRec60[1]) + (fConst113 * fRec60[2])));
			fRec61[0] = (fTemp1 - ((fConst167 * fRec61[1]) + (fConst105 * fRec61[2])));
			fRec62[0] = (fTemp1 - ((fConst168 * fRec62[1]) + (fConst125 * fRec62[2])));
			fRec63[0] = (fTemp1 - ((fConst169 * fRec63[1]) + (fConst113 * fRec63[2])));
			fRec64[0] = (fTemp1 - ((fConst170 * fRec64[1]) + (fConst105 * fRec64[2])));
			fRec65[0] = (fTemp1 - ((fConst172 * fRec65[1]) + (fConst173 * fRec65[2])));
			fRec66[0] = (fTemp1 - ((fConst174 * fRec66[1]) + (fConst165 * fRec66[2])));
			fRec67[0] = (fTemp1 - ((fConst175 * fRec67[1]) + (fConst23 * fRec67[2])));
			fRec68[0] = (fTemp1 - ((fConst176 * fRec68[1]) + (fConst14 * fRec68[2])));
			fRec69[0] = (fTemp1 - ((fConst178 * fRec69[1]) + (fConst179 * fRec69[2])));
			fRec70[0] = (fTemp1 - ((fConst182 * fRec70[1]) + (fConst183 * fRec70[2])));
			fRec71[0] = (fTemp1 - ((fConst186 * fRec71[1]) + (fConst187 * fRec71[2])));
			fRec72[0] = (fTemp1 - ((fConst188 * fRec72[1]) + (fConst33 * fRec72[2])));
			fRec73[0] = (fTemp1 - ((fConst191 * fRec73[1]) + (fConst192 * fRec73[2])));
			fRec74[0] = (fTemp1 - ((fConst194 * fRec74[1]) + (fConst195 * fRec74[2])));
			fRec75[0] = (fTemp1 - ((fConst197 * fRec75[1]) + (fConst198 * fRec75[2])));
			fRec76[0] = (fTemp1 - ((fConst200 * fRec76[1]) + (fConst201 * fRec76[2])));
			fRec77[0] = (fTemp1 - ((fConst202 * fRec77[1]) + (fConst150 * fRec77[2])));
			fRec78[0] = (fTemp1 - ((fConst205 * fRec78[1]) + (fConst206 * fRec78[2])));
			fRec79[0] = (fTemp1 - ((fConst208 * fRec79[1]) + (fConst209 * fRec79[2])));
			fRec80[0] = (fTemp1 - ((fConst211 * fRec80[1]) + (fConst212 * fRec80[2])));
			fRec81[0] = (fTemp1 - ((fConst214 * fRec81[1]) + (fConst215 * fRec81[2])));
			fRec82[0] = (fTemp1 - ((fConst218 * fRec82[1]) + (fConst219 * fRec82[2])));
			fRec83[0] = (fTemp1 - ((fConst220 * fRec83[1]) + (fConst219 * fRec83[2])));
			fRec84[0] = (fTemp1 - ((fConst221 * fRec84[1]) + (fConst219 * fRec84[2])));
			fRec85[0] = (fTemp1 - ((fConst222 * fRec85[1]) + (fConst71 * fRec85[2])));
			fRec86[0] = (fTemp1 - ((fConst224 * fRec86[1]) + (fConst225 * fRec86[2])));
			fRec87[0] = (fTemp1 - ((fConst226 * fRec87[1]) + (fConst187 * fRec87[2])));
			fRec88[0] = (fTemp1 - ((fConst228 * fRec88[1]) + (fConst229 * fRec88[2])));
			fRec89[0] = (fTemp1 - ((fConst231 * fRec89[1]) + (fConst232 * fRec89[2])));
			fRec90[0] = (fTemp1 - ((fConst234 * fRec90[1]) + (fConst235 * fRec90[2])));
			fRec91[0] = (fTemp1 - ((fConst236 * fRec91[1]) + (fConst183 * fRec91[2])));
			fRec92[0] = (fTemp1 - ((fConst237 * fRec92[1]) + (fConst187 * fRec92[2])));
			fRec93[0] = (fTemp1 - ((fConst238 * fRec93[1]) + (fConst9 * fRec93[2])));
			fRec94[0] = (fTemp1 - ((fConst241 * fRec94[1]) + (fConst242 * fRec94[2])));
			fRec95[0] = (fTemp1 - ((fConst244 * fRec95[1]) + (fConst245 * fRec95[2])));
			fRec96[0] = (fTemp1 - ((fConst247 * fRec96[1]) + (fConst248 * fRec96[2])));
			fRec97[0] = (fTemp1 - ((fConst250 * fRec97[1]) + (fConst251 * fRec97[2])));
			fRec98[0] = (fTemp1 - ((fConst254 * fRec98[1]) + (fConst255 * fRec98[2])));
			fRec99[0] = (fTemp1 - ((fConst256 * fRec99[1]) + (fConst23 * fRec99[2])));
			fRec100[0] = (fTemp1 - ((fConst257 * fRec100[1]) + (fConst242 * fRec100[2])));
			fRec101[0] = (fTemp1 - ((fConst258 * fRec101[1]) + (fConst255 * fRec101[2])));
			fRec102[0] = (fTemp1 - ((fConst260 * fRec102[1]) + (fConst261 * fRec102[2])));
			fRec103[0] = (fTemp1 - ((fConst264 * fRec103[1]) + (fConst265 * fRec103[2])));
			fRec104[0] = (fTemp1 - ((fConst267 * fRec104[1]) + (fConst268 * fRec104[2])));
			fRec105[0] = (fTemp1 - ((fConst270 * fRec105[1]) + (fConst271 * fRec105[2])));
			fRec106[0] = (fTemp1 - ((fConst272 * fRec106[1]) + (fConst265 * fRec106[2])));
			fRec107[0] = (fTemp1 - ((fConst275 * fRec107[1]) + (fConst276 * fRec107[2])));
			fRec108[0] = (fTemp1 - ((fConst277 * fRec108[1]) + (fConst276 * fRec108[2])));
			fRec109[0] = (fTemp1 - ((fConst279 * fRec109[1]) + (fConst280 * fRec109[2])));
			fRec110[0] = (fTemp1 - ((fConst281 * fRec110[1]) + (fConst265 * fRec110[2])));
			fRec111[0] = (fTemp1 - ((fConst284 * fRec111[1]) + (fConst285 * fRec111[2])));
			fRec112[0] = (fTemp1 - ((fConst287 * fRec112[1]) + (fConst288 * fRec112[2])));
			fRec113[0] = (fTemp1 - ((fConst290 * fRec113[1]) + (fConst291 * fRec113[2])));
			fRec114[0] = (fTemp1 - ((fConst293 * fRec114[1]) + (fConst294 * fRec114[2])));
			fRec115[0] = (fTemp1 - ((fConst295 * fRec115[1]) + (fConst276 * fRec115[2])));
			fRec116[0] = (fTemp1 - ((fConst297 * fRec116[1]) + (fConst298 * fRec116[2])));
			fRec117[0] = (fTemp1 - ((fConst299 * fRec117[1]) + (fConst285 * fRec117[2])));
			fRec118[0] = (fTemp1 - ((fConst301 * fRec118[1]) + (fConst302 * fRec118[2])));
			fRec119[0] = (fTemp1 - ((fConst304 * fRec119[1]) + (fConst305 * fRec119[2])));
			fRec120[0] = (fTemp1 - ((fConst307 * fRec120[1]) + (fConst308 * fRec120[2])));
			fRec121[0] = (fTemp1 - ((fConst310 * fRec121[1]) + (fConst311 * fRec121[2])));
			fRec122[0] = (fTemp1 - ((fConst314 * fRec122[1]) + (fConst315 * fRec122[2])));
			fRec123[0] = (fTemp1 - ((fConst316 * fRec123[1]) + (fConst315 * fRec123[2])));
			fRec124[0] = (fTemp1 - ((fConst318 * fRec124[1]) + (fConst319 * fRec124[2])));
			fRec125[0] = (fTemp1 - ((fConst320 * fRec125[1]) + (fConst315 * fRec125[2])));
			fRec126[0] = (fTemp1 - ((fConst322 * fRec126[1]) + (fConst323 * fRec126[2])));
			fRec127[0] = (fTemp1 - ((fConst326 * fRec127[1]) + (fConst327 * fRec127[2])));
			fRec128[0] = (fTemp1 - ((fConst328 * fRec128[1]) + (fConst327 * fRec128[2])));
			fRec129[0] = (fTemp1 - ((fConst330 * fRec129[1]) + (fConst331 * fRec129[2])));
			fRec130[0] = (fTemp1 - ((fConst333 * fRec130[1]) + (fConst334 * fRec130[2])));
			fRec131[0] = (fTemp1 - ((fConst336 * fRec131[1]) + (fConst337 * fRec131[2])));
			fRec132[0] = (fTemp1 - ((fConst339 * fRec132[1]) + (fConst340 * fRec132[2])));
			fRec133[0] = (fTemp1 - ((fConst342 * fRec133[1]) + (fConst343 * fRec133[2])));
			fRec134[0] = (fTemp1 - ((fConst345 * fRec134[1]) + (fConst346 * fRec134[2])));
			fRec135[0] = (fTemp1 - ((fConst348 * fRec135[1]) + (fConst349 * fRec135[2])));
			fRec136[0] = (fTemp1 - ((fConst352 * fRec136[1]) + (fConst353 * fRec136[2])));
			fRec137[0] = (fTemp1 - ((fConst354 * fRec137[1]) + (fConst353 * fRec137[2])));
			fRec138[0] = (fTemp1 - ((fConst355 * fRec138[1]) + (fConst353 * fRec138[2])));
			fRec139[0] = (fTemp1 - ((fConst357 * fRec139[1]) + (fConst358 * fRec139[2])));
			fRec140[0] = (fTemp1 - ((fConst361 * fRec140[1]) + (fConst362 * fRec140[2])));
			fRec141[0] = (fTemp1 - ((fConst363 * fRec141[1]) + (fConst362 * fRec141[2])));
			fRec142[0] = (fTemp1 - ((fConst365 * fRec142[1]) + (fConst366 * fRec142[2])));
			fRec143[0] = (fTemp1 - ((fConst368 * fRec143[1]) + (fConst369 * fRec143[2])));
			fRec144[0] = (fTemp1 - ((fConst371 * fRec144[1]) + (fConst372 * fRec144[2])));
			fRec145[0] = (fTemp1 - ((fConst374 * fRec145[1]) + (fConst375 * fRec145[2])));
			fRec146[0] = (fTemp1 - ((fConst378 * fRec146[1]) + (fConst379 * fRec146[2])));
			fRec147[0] = (fTemp1 - ((fConst380 * fRec147[1]) + (fConst379 * fRec147[2])));
			fRec148[0] = (fTemp1 - ((fConst383 * fRec148[1]) + (fConst384 * fRec148[2])));
			fRec149[0] = (fTemp1 - ((fConst385 * fRec149[1]) + (fConst384 * fRec149[2])));
			fRec150[0] = (fTemp1 - ((fConst387 * fRec150[1]) + (fConst388 * fRec150[2])));
			fRec151[0] = (fTemp1 - ((fConst390 * fRec151[1]) + (fConst391 * fRec151[2])));
			fRec152[0] = (fTemp1 - ((fConst393 * fRec152[1]) + (fConst394 * fRec152[2])));
			fRec153[0] = (fTemp1 - ((fConst396 * fRec153[1]) + (fConst397 * fRec153[2])));
			fRec154[0] = (fTemp1 - ((fConst399 * fRec154[1]) + (fConst400 * fRec154[2])));
			fRec155[0] = (fTemp1 - ((fConst401 * fRec155[1]) + (fConst83 * fRec155[2])));
			fRec156[0] = (fTemp1 - ((fConst404 * fRec156[1]) + (fConst405 * fRec156[2])));
			fRec157[0] = (fTemp1 - ((fConst406 * fRec157[1]) + (fConst192 * fRec157[2])));
			fRec158[0] = (fTemp1 - ((fConst407 * fRec158[1]) + (fConst4 * fRec158[2])));
			fRec159[0] = (fTemp1 - ((fConst409 * fRec159[1]) + (fConst410 * fRec159[2])));
			fRec160[0] = (fTemp1 - ((fConst413 * fRec160[1]) + (fConst414 * fRec160[2])));
			fRec161[0] = (fTemp1 - ((fConst415 * fRec161[1]) + (fConst87 * fRec161[2])));
			fRec162[0] = (fTemp1 - ((fConst416 * fRec162[1]) + (fConst38 * fRec162[2])));
			fRec163[0] = (fTemp1 - ((fConst417 * fRec163[1]) + (fConst83 * fRec163[2])));
			fRec164[0] = (fTemp1 - ((fConst419 * fRec164[1]) + (fConst420 * fRec164[2])));
			fRec165[0] = (fTemp1 - ((fConst421 * fRec165[1]) + (fConst414 * fRec165[2])));
			fRec166[0] = (fTemp1 - ((fConst422 * fRec166[1]) + (fConst83 * fRec166[2])));
			fRec167[0] = (fTemp1 - ((fConst423 * fRec167[1]) + (fConst405 * fRec167[2])));
			fRec168[0] = (fTemp1 - ((fConst424 * fRec168[1]) + (fConst405 * fRec168[2])));
			fRec169[0] = (fTemp1 - ((fConst427 * fRec169[1]) + (fConst428 * fRec169[2])));
			fRec170[0] = (fTemp1 - ((fConst430 * fRec170[1]) + (fConst431 * fRec170[2])));
			fRec171[0] = (fTemp1 - ((fConst434 * fRec171[1]) + (fConst435 * fRec171[2])));
			fRec172[0] = (fTemp1 - ((fConst436 * fRec172[1]) + (fConst435 * fRec172[2])));
			fRec173[0] = (fTemp1 - ((fConst438 * fRec173[1]) + (fConst439 * fRec173[2])));
			fRec174[0] = (fTemp1 - ((fConst440 * fRec174[1]) + (fConst79 * fRec174[2])));
			fRec175[0] = (fTemp1 - ((fConst442 * fRec175[1]) + (fConst443 * fRec175[2])));
			fRec176[0] = (fTemp1 - ((fConst444 * fRec176[1]) + (fConst75 * fRec176[2])));
			fRec177[0] = (fTemp1 - ((fConst447 * fRec177[1]) + (fConst448 * fRec177[2])));
			fRec178[0] = (fTemp1 - ((fConst451 * fRec178[1]) + (fConst452 * fRec178[2])));
			fRec179[0] = (fTemp1 - ((fConst453 * fRec179[1]) + (fConst452 * fRec179[2])));
			fRec180[0] = (fTemp1 - ((fConst454 * fRec180[1]) + (fConst452 * fRec180[2])));
			fRec181[0] = (fTemp1 - ((fConst455 * fRec181[1]) + (fConst448 * fRec181[2])));
			fRec182[0] = (fTemp1 - ((fConst456 * fRec182[1]) + (fConst435 * fRec182[2])));
			fRec183[0] = (fTemp1 - ((fConst457 * fRec183[1]) + (fConst435 * fRec183[2])));
			fRec184[0] = (fTemp1 - ((fConst459 * fRec184[1]) + (fConst460 * fRec184[2])));
			fRec185[0] = (fTemp1 - ((fConst463 * fRec185[1]) + (fConst464 * fRec185[2])));
			fRec186[0] = (fTemp1 - ((fConst467 * fRec186[1]) + (fConst468 * fRec186[2])));
			fRec187[0] = (fTemp1 - ((fConst469 * fRec187[1]) + (fConst468 * fRec187[2])));
			fRec188[0] = (fTemp1 - ((fConst470 * fRec188[1]) + (fConst206 * fRec188[2])));
			fRec189[0] = (fTemp1 - ((fConst473 * fRec189[1]) + (fConst474 * fRec189[2])));
			fRec190[0] = (fTemp1 - ((fConst475 * fRec190[1]) + (fConst474 * fRec190[2])));
			fRec191[0] = (fTemp1 - ((fConst476 * fRec191[1]) + (fConst474 * fRec191[2])));
			fRec192[0] = (fTemp1 - ((fConst477 * fRec192[1]) + (fConst464 * fRec192[2])));
			fRec193[0] = (fTemp1 - ((fConst478 * fRec193[1]) + (fConst474 * fRec193[2])));
			fRec194[0] = (fTemp1 - ((fConst479 * fRec194[1]) + (fConst464 * fRec194[2])));
			fRec195[0] = (fTemp1 - ((fConst482 * fRec195[1]) + (fConst483 * fRec195[2])));
			fRec196[0] = (fTemp1 - ((fConst484 * fRec196[1]) + (fConst483 * fRec196[2])));
			fRec197[0] = (fTemp1 - ((fConst487 * fRec197[1]) + (fConst488 * fRec197[2])));
			fRec198[0] = (fTemp1 - ((fConst489 * fRec198[1]) + (fConst488 * fRec198[2])));
			fRec199[0] = (fTemp1 - ((fConst492 * fRec199[1]) + (fConst493 * fRec199[2])));
			fRec200[0] = (fTemp1 - ((fConst496 * fRec200[1]) + (fConst497 * fRec200[2])));
			fRec201[0] = (fTemp1 - ((fConst498 * fRec201[1]) + (fConst452 * fRec201[2])));
			fRec202[0] = (fTemp1 - ((fConst499 * fRec202[1]) + (fConst452 * fRec202[2])));
			fRec203[0] = (fTemp1 - ((fConst500 * fRec203[1]) + (fConst452 * fRec203[2])));
			fRec204[0] = (fTemp1 - ((fConst501 * fRec204[1]) + (fConst452 * fRec204[2])));
			fRec205[0] = (fTemp1 - ((fConst502 * fRec205[1]) + (fConst452 * fRec205[2])));
			fRec206[0] = (fTemp1 - ((fConst505 * fRec206[1]) + (fConst506 * fRec206[2])));
			fRec207[0] = (fTemp1 - ((fConst507 * fRec207[1]) + (fConst506 * fRec207[2])));
			fRec208[0] = (fTemp1 - ((fConst508 * fRec208[1]) + (fConst506 * fRec208[2])));
			fRec209[0] = (fTemp1 - ((fConst510 * fRec209[1]) + (fConst511 * fRec209[2])));
			fRec210[0] = (fTemp1 - ((fConst512 * fRec210[1]) + (fConst405 * fRec210[2])));
			fRec211[0] = (fTemp1 - ((fConst513 * fRec211[1]) + (fConst405 * fRec211[2])));
			fRec212[0] = (fTemp1 - ((fConst514 * fRec212[1]) + (fConst405 * fRec212[2])));
			fRec213[0] = (fTemp1 - ((fConst515 * fRec213[1]) + (fConst506 * fRec213[2])));
			fRec214[0] = (fTemp1 - ((fConst517 * fRec214[1]) + (fConst518 * fRec214[2])));
			fRec215[0] = (fTemp1 - ((fConst521 * fRec215[1]) + (fConst522 * fRec215[2])));
			fRec216[0] = (fTemp1 - ((fConst523 * fRec216[1]) + (fConst448 * fRec216[2])));
			fRec217[0] = (fTemp1 - ((fConst524 * fRec217[1]) + (fConst452 * fRec217[2])));
			fRec218[0] = (fTemp1 - ((fConst525 * fRec218[1]) + (fConst497 * fRec218[2])));
			fRec219[0] = (fTemp1 - ((fConst526 * fRec219[1]) + (fConst452 * fRec219[2])));
			fRec220[0] = (fTemp1 - ((fConst527 * fRec220[1]) + (fConst452 * fRec220[2])));
			fRec221[0] = (fTemp1 - ((fConst528 * fRec221[1]) + (fConst497 * fRec221[2])));
			fRec222[0] = (fTemp1 - ((fConst530 * fRec222[1]) + (fConst531 * fRec222[2])));
			fRec223[0] = (fTemp1 - ((fConst533 * fRec223[1]) + (fConst534 * fRec223[2])));
			fRec224[0] = (fTemp1 - ((fConst535 * fRec224[1]) + (fConst493 * fRec224[2])));
			fRec225[0] = (fTemp1 - ((fConst537 * fRec225[1]) + (fConst538 * fRec225[2])));
			fRec226[0] = (fTemp1 - ((fConst539 * fRec226[1]) + (fConst468 * fRec226[2])));
			fRec227[0] = (fTemp1 - ((fConst542 * fRec227[1]) + (fConst543 * fRec227[2])));
			fRec228[0] = (fTemp1 - ((fConst545 * fRec228[1]) + (fConst546 * fRec228[2])));
			fRec229[0] = (fTemp1 - ((fConst549 * fRec229[1]) + (fConst550 * fRec229[2])));
			fRec230[0] = (fTemp1 - ((fConst551 * fRec230[1]) + (fConst550 * fRec230[2])));
			fRec231[0] = (fTemp1 - ((fConst554 * fRec231[1]) + (fConst555 * fRec231[2])));
			fRec232[0] = (fTemp1 - ((fConst558 * fRec232[1]) + (fConst559 * fRec232[2])));
			fRec233[0] = (fTemp1 - ((fConst560 * fRec233[1]) + (fConst559 * fRec233[2])));
			fRec234[0] = (fTemp1 - ((fConst561 * fRec234[1]) + (fConst206 * fRec234[2])));
			fRec235[0] = (fTemp1 - ((fConst562 * fRec235[1]) + (fConst543 * fRec235[2])));
			fRec236[0] = (fTemp1 - ((fConst563 * fRec236[1]) + (fConst206 * fRec236[2])));
			fRec237[0] = (fTemp1 - ((fConst566 * fRec237[1]) + (fConst567 * fRec237[2])));
			fRec238[0] = (fTemp1 - ((fConst570 * fRec238[1]) + (fConst571 * fRec238[2])));
			fRec239[0] = (fTemp1 - ((fConst573 * fRec239[1]) + (fConst574 * fRec239[2])));
			fRec240[0] = (fTemp1 - ((fConst576 * fRec240[1]) + (fConst577 * fRec240[2])));
			fRec241[0] = (fTemp1 - ((fConst578 * fRec241[1]) + (fConst522 * fRec241[2])));
			fRec242[0] = (fTemp1 - ((fConst579 * fRec242[1]) + (fConst522 * fRec242[2])));
			fRec243[0] = (fTemp1 - ((fConst582 * fRec243[1]) + (fConst583 * fRec243[2])));
			fRec244[0] = (fTemp1 - ((fConst584 * fRec244[1]) + (fConst583 * fRec244[2])));
			fRec245[0] = (fTemp1 - ((fConst585 * fRec245[1]) + (fConst583 * fRec245[2])));
			fRec246[0] = (fTemp1 - ((fConst586 * fRec246[1]) + (fConst583 * fRec246[2])));
			fRec247[0] = (fTemp1 - ((fConst589 * fRec247[1]) + (fConst590 * fRec247[2])));
			fRec248[0] = (fTemp1 - ((fConst591 * fRec248[1]) + (fConst583 * fRec248[2])));
			fRec249[0] = (fTemp1 - ((fConst592 * fRec249[1]) + (fConst590 * fRec249[2])));
			fRec250[0] = (fTemp1 - ((fConst593 * fRec250[1]) + (fConst583 * fRec250[2])));
			fRec251[0] = (fTemp1 - ((fConst594 * fRec251[1]) + (fConst571 * fRec251[2])));
			fRec252[0] = (fTemp1 - ((fConst595 * fRec252[1]) + (fConst583 * fRec252[2])));
			fRec253[0] = (fTemp1 - ((fConst596 * fRec253[1]) + (fConst583 * fRec253[2])));
			fRec254[0] = (fTemp1 - ((fConst597 * fRec254[1]) + (fConst583 * fRec254[2])));
			fRec255[0] = (fTemp1 - ((fConst598 * fRec255[1]) + (fConst583 * fRec255[2])));
			fRec256[0] = (fTemp1 - ((fConst599 * fRec256[1]) + (fConst567 * fRec256[2])));
			fRec257[0] = (fTemp1 - ((fConst600 * fRec257[1]) + (fConst567 * fRec257[2])));
			fRec258[0] = (fTemp1 - ((fConst602 * fRec258[1]) + (fConst603 * fRec258[2])));
			fRec259[0] = (fTemp1 - ((fConst606 * fRec259[1]) + (fConst607 * fRec259[2])));
			fRec260[0] = (fTemp1 - ((fConst609 * fRec260[1]) + (fConst610 * fRec260[2])));
			fRec261[0] = (fTemp1 - ((fConst611 * fRec261[1]) + (fConst607 * fRec261[2])));
			fRec262[0] = (fTemp1 - ((fConst612 * fRec262[1]) + (fConst543 * fRec262[2])));
			fRec263[0] = (fTemp1 - ((fConst613 * fRec263[1]) + (fConst543 * fRec263[2])));
			fRec264[0] = (fTemp1 - ((fConst614 * fRec264[1]) + (fConst543 * fRec264[2])));
			fRec265[0] = (fTemp1 - ((fConst615 * fRec265[1]) + (fConst543 * fRec265[2])));
			fRec266[0] = (fTemp1 - ((fConst616 * fRec266[1]) + (fConst543 * fRec266[2])));
			fRec267[0] = (fTemp1 - ((fConst617 * fRec267[1]) + (fConst206 * fRec267[2])));
			fRec268[0] = (fTemp1 - ((fConst618 * fRec268[1]) + (fConst206 * fRec268[2])));
			fRec269[0] = (fTemp1 - ((fConst619 * fRec269[1]) + (fConst206 * fRec269[2])));
			fRec270[0] = (fTemp1 - ((fConst620 * fRec270[1]) + (fConst206 * fRec270[2])));
			fRec271[0] = (fTemp1 - ((fConst621 * fRec271[1]) + (fConst543 * fRec271[2])));
			fRec272[0] = (fTemp1 - ((fConst622 * fRec272[1]) + (fConst206 * fRec272[2])));
			fRec273[0] = (fTemp1 - ((fConst623 * fRec273[1]) + (fConst543 * fRec273[2])));
			fRec274[0] = (fTemp1 - ((fConst624 * fRec274[1]) + (fConst543 * fRec274[2])));
			fRec275[0] = (fTemp1 - ((fConst627 * fRec275[1]) + (fConst628 * fRec275[2])));
			fRec276[0] = (fTemp1 - ((fConst629 * fRec276[1]) + (fConst206 * fRec276[2])));
			fRec277[0] = (fTemp1 - ((fConst630 * fRec277[1]) + (fConst543 * fRec277[2])));
			fRec278[0] = (fTemp1 - ((fConst631 * fRec278[1]) + (fConst555 * fRec278[2])));
			fRec279[0] = (fTemp1 - ((fConst632 * fRec279[1]) + (fConst628 * fRec279[2])));
			fRec280[0] = (fTemp1 - ((fConst633 * fRec280[1]) + (fConst428 * fRec280[2])));
			fRec281[0] = (fTemp1 - ((fConst634 * fRec281[1]) + (fConst559 * fRec281[2])));
			fRec282[0] = (fTemp1 - ((fConst635 * fRec282[1]) + (fConst555 * fRec282[2])));
			fRec283[0] = (fTemp1 - ((fConst636 * fRec283[1]) + (fConst550 * fRec283[2])));
			fRec284[0] = (fTemp1 - ((fConst637 * fRec284[1]) + (fConst550 * fRec284[2])));
			fRec285[0] = (fTemp1 - ((fConst638 * fRec285[1]) + (fConst550 * fRec285[2])));
			fRec286[0] = (fTemp1 - ((fConst639 * fRec286[1]) + (fConst559 * fRec286[2])));
			fRec287[0] = (fTemp1 - ((fConst640 * fRec287[1]) + (fConst550 * fRec287[2])));
			fRec288[0] = (fTemp1 - ((fConst641 * fRec288[1]) + (fConst555 * fRec288[2])));
			fRec289[0] = (fTemp1 - ((fConst642 * fRec289[1]) + (fConst550 * fRec289[2])));
			fRec290[0] = (fTemp1 - ((fConst645 * fRec290[1]) + (fConst646 * fRec290[2])));
			fRec291[0] = (fTemp1 - ((fConst647 * fRec291[1]) + (fConst550 * fRec291[2])));
			fRec292[0] = (fTemp1 - ((fConst648 * fRec292[1]) + (fConst550 * fRec292[2])));
			fRec293[0] = (fTemp1 - ((fConst649 * fRec293[1]) + (fConst550 * fRec293[2])));
			fRec294[0] = (fTemp1 - ((fConst650 * fRec294[1]) + (fConst550 * fRec294[2])));
			fRec295[0] = (fTemp1 - ((fConst651 * fRec295[1]) + (fConst550 * fRec295[2])));
			fRec296[0] = (fTemp1 - ((fConst652 * fRec296[1]) + (fConst101 * fRec296[2])));
			fRec297[0] = (fTemp1 - ((fConst653 * fRec297[1]) + (fConst101 * fRec297[2])));
			fRec298[0] = (fTemp1 - ((fConst654 * fRec298[1]) + (fConst550 * fRec298[2])));
			fRec299[0] = (fTemp1 - ((fConst655 * fRec299[1]) + (fConst550 * fRec299[2])));
			fRec300[0] = (fTemp1 - ((fConst656 * fRec300[1]) + (fConst550 * fRec300[2])));
			fRec301[0] = (fTemp1 - ((fConst657 * fRec301[1]) + (fConst646 * fRec301[2])));
			fRec302[0] = (fTemp1 - ((fConst658 * fRec302[1]) + (fConst550 * fRec302[2])));
			fRec303[0] = (fTemp1 - ((fConst659 * fRec303[1]) + (fConst550 * fRec303[2])));
			fRec304[0] = (fTemp1 - ((fConst661 * fRec304[1]) + (fConst662 * fRec304[2])));
			fRec305[0] = (fTemp1 - ((fConst663 * fRec305[1]) + (fConst646 * fRec305[2])));
			fRec306[0] = (fTemp1 - ((fConst664 * fRec306[1]) + (fConst550 * fRec306[2])));
			fRec307[0] = (fTemp1 - ((fConst665 * fRec307[1]) + (fConst555 * fRec307[2])));
			fRec308[0] = (fTemp1 - ((fConst666 * fRec308[1]) + (fConst550 * fRec308[2])));
			fRec309[0] = (fTemp1 - ((fConst669 * fRec309[1]) + (fConst670 * fRec309[2])));
			fRec310[0] = (fTemp1 - ((fConst671 * fRec310[1]) + (fConst628 * fRec310[2])));
			fRec311[0] = (fTemp1 - ((fConst672 * fRec311[1]) + (fConst670 * fRec311[2])));
			fRec312[0] = (fTemp1 - ((fConst673 * fRec312[1]) + (fConst628 * fRec312[2])));
			fRec313[0] = (fTemp1 - ((fConst674 * fRec313[1]) + (fConst543 * fRec313[2])));
			fRec314[0] = (fTemp1 - ((fConst675 * fRec314[1]) + (fConst559 * fRec314[2])));
			fRec315[0] = (fTemp1 - ((fConst676 * fRec315[1]) + (fConst628 * fRec315[2])));
			fRec316[0] = (fTemp1 - ((fConst677 * fRec316[1]) + (fConst628 * fRec316[2])));
			fRec317[0] = (fTemp1 - ((fConst678 * fRec317[1]) + (fConst670 * fRec317[2])));
			fRec318[0] = (fTemp1 - ((fConst679 * fRec318[1]) + (fConst543 * fRec318[2])));
			fRec319[0] = (fTemp1 - ((fConst680 * fRec319[1]) + (fConst559 * fRec319[2])));
			fRec320[0] = (fTemp1 - ((fConst681 * fRec320[1]) + (fConst474 * fRec320[2])));
			fRec321[0] = (fTemp1 - ((fConst682 * fRec321[1]) + (fConst543 * fRec321[2])));
			fRec322[0] = (fTemp1 - ((fConst683 * fRec322[1]) + (fConst428 * fRec322[2])));
			fRec323[0] = (fTemp1 - ((fConst684 * fRec323[1]) + (fConst428 * fRec323[2])));
			fRec324[0] = (fTemp1 - ((fConst685 * fRec324[1]) + (fConst428 * fRec324[2])));
			fRec325[0] = (fTemp1 - ((fConst686 * fRec325[1]) + (fConst628 * fRec325[2])));
			fRec326[0] = (fTemp1 - ((fConst687 * fRec326[1]) + (fConst555 * fRec326[2])));
			fRec327[0] = (fTemp1 - ((fConst688 * fRec327[1]) + (fConst555 * fRec327[2])));
			fRec328[0] = (fTemp1 - ((fConst689 * fRec328[1]) + (fConst555 * fRec328[2])));
			fRec329[0] = (fTemp1 - ((fConst690 * fRec329[1]) + (fConst550 * fRec329[2])));
			fRec330[0] = (fTemp1 - ((fConst692 * fRec330[1]) + (fConst693 * fRec330[2])));
			fRec331[0] = (fTemp1 - ((fConst694 * fRec331[1]) + (fConst550 * fRec331[2])));
			fRec332[0] = (fTemp1 - ((fConst695 * fRec332[1]) + (fConst550 * fRec332[2])));
			fRec333[0] = (fTemp1 - ((fConst696 * fRec333[1]) + (fConst555 * fRec333[2])));
			fRec334[0] = (fTemp1 - ((fConst697 * fRec334[1]) + (fConst101 * fRec334[2])));
			fRec335[0] = (fTemp1 - ((fConst698 * fRec335[1]) + (fConst550 * fRec335[2])));
			fRec336[0] = (fTemp1 - ((fConst701 * fRec336[1]) + (fConst702 * fRec336[2])));
			fRec337[0] = (fTemp1 - ((fConst703 * fRec337[1]) + (fConst702 * fRec337[2])));
			fRec338[0] = (fTemp1 - ((fConst704 * fRec338[1]) + (fConst702 * fRec338[2])));
			output0[i] = FAUSTFLOAT((fTemp0 * (fSlow1 + (fSlow0 * (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((0.25188438345399999 * (fRec0[0] - fRec0[2])) + (0.29456778870200001 * (fRec1[0] - fRec1[2]))) + (0.32890223918799999 * (fRec2[0] - fRec2[2]))) + (0.27760024212899997 * (fRec3[0] - fRec3[2]))) + (0.49516406994399997 * (fRec4[0] - fRec4[2]))) + (0.58343740167199998 * (fRec5[0] - fRec5[2]))) + (0.59626964227000001 * (fRec6[0] - fRec6[2]))) + (0.57056714984400003 * (fRec7[0] - fRec7[2]))) + (0.402229847493 * (fRec8[0] - fRec8[2]))) + (0.32090387680799998 * (fRec9[0] - fRec9[2]))) + (0.48275862312700002 * (fRec10[0] - fRec10[2]))) + (0.47425524047099998 * (fRec11[0] - fRec11[2]))) + (0.32174364006599998 * (fRec12[0] - fRec12[2]))) + (0.31120584268700002 * (fRec13[0] - fRec13[2]))) + (0.31123108322800003 * (fRec14[0] - fRec14[2]))) + (0.30541419696099997 * (fRec15[0] - fRec15[2]))) + (0.479935452885 * (fRec16[0] - fRec16[2]))) + (0.50853314328699994 * (fRec17[0] - fRec17[2]))) + (0.50894687375199998 * (fRec18[0] - fRec18[2]))) + (0.39003675719199998 * (fRec19[0] - fRec19[2]))) + (0.40848290829299999 * (fRec20[0] - fRec20[2]))) + (0.39375103251100002 * (fRec21[0] - fRec21[2]))) + (0.39041867525599999 * (fRec22[0] - fRec22[2]))) + (0.38288401201200001 * (fRec23[0] - fRec23[2]))) + (0.33847543380599998 * (fRec24[0] - fRec24[2]))) + (0.34569364806000002 * (fRec25[0] - fRec25[2]))) + (0.272337609584 * (fRec26[0] - fRec26[2]))) + (0.27988527395399998 * (fRec27[0] - fRec27[2]))) + (0.28054263144300001 * (fRec28[0] - fRec28[2]))) + (0.192409798331 * (fRec29[0] - fRec29[2]))) + (0.21109247495399999 * (fRec30[0] - fRec30[2]))) + (0.23843090668399999 * (fRec31[0] - fRec31[2]))) + (0.37159896748999999 * (fRec32[0] - fRec32[2]))) + (0.32691448410500001 * (fRec33[0] - fRec33[2]))) + (0.30257050614999997 * (fRec34[0] - fRec34[2]))) + (0.32598127092000001 * (fRec35[0] - fRec35[2]))) + (0.35284019056100002 * (fRec36[0] - fRec36[2]))) + (0.50579302615400001 * (fRec37[0] - fRec37[2]))) + (0.51740128048300005 * (fRec38[0] - fRec38[2]))) + (0.55735674991899997 * (fRec39[0] - fRec39[2]))) + (0.31855318823200002 * (fRec40[0] - fRec40[2]))) + (0.334196155602 * (fRec41[0] - fRec41[2]))) + (0.40290576278000001 * (fRec42[0] - fRec42[2]))) + (0.69453996340199997 * (fRec43[0] - fRec43[2]))) + (0.44560484425500002 * (fRec44[0] - fRec44[2]))) + (0.61118851175199995 * (fRec45[0] - fRec45[2]))) + (0.52032305477399998 * (fRec46[0] - fRec46[2]))) + (0.53745159079899996 * (fRec47[0] - fRec47[2]))) + (0.57150063938100004 * (fRec48[0] - fRec48[2]))) + (0.60916084590200004 * (fRec49[0] - fRec49[2]))) + (0.66628865440200002 * (fRec50[0] - fRec50[2]))) + (0.68996400041899997 * (fRec51[0] - fRec51[2]))) + (0.80024048285500005 * (fRec52[0] - fRec52[2]))) + (0.78633961135099995 * (fRec53[0] - fRec53[2]))) + (0.78353646920700004 * (fRec54[0] - fRec54[2]))) + (0.64209693016299996 * (fRec55[0] - fRec55[2]))) + (0.501913641277 * (fRec56[0] - fRec56[2]))) + (0.51505425949700001 * (fRec57[0] - fRec57[2]))) + (0.35634149052699998 * (fRec58[0] - fRec58[2]))) + (0.42910907328499998 * (fRec59[0] - fRec59[2]))) + (0.353789762053 * (fRec60[0] - fRec60[2]))) + (0.32286054151600002 * (fRec61[0] - fRec61[2]))) + (0.34426951615899998 * (fRec62[0] - fRec62[2]))) + (0.355801900655 * (fRec63[0] - fRec63[2]))) + (0.32185768509099999 * (fRec64[0] - fRec64[2]))) + (0.29107391629700002 * (fRec65[0] - fRec65[2]))) + (0.37501978660399998 * (fRec66[0] - fRec66[2]))) + (0.403438929843 * (fRec67[0] - fRec67[2]))) + (0.37257047811299998 * (fRec68[0] - fRec68[2]))) + (0.53565627925199999 * (fRec69[0] - fRec69[2]))) + (0.46639665184700002 * (fRec70[0] - fRec70[2]))) + (0.60467399663700006 * (fRec71[0] - fRec71[2]))) + (0.66499786135500005 * (fRec72[0] - fRec72[2]))) + (0.63230548360100003 * (fRec73[0] - fRec73[2]))) + (0.93980514531399995 * (fRec74[0] - fRec74[2]))) + (fRec75[0] - fRec75[2])) + (0.86861546193600003 * (fRec76[0] - fRec76[2]))) + (0.91370181174200005 * (fRec77[0] - fRec77[2]))) + (0.36529585428299999 * (fRec78[0] - fRec78[2]))) + (0.39460371617700002 * (fRec79[0] - fRec79[2]))) + (0.38756305562499999 * (fRec80[0] - fRec80[2]))) + (0.40488445162699999 * (fRec81[0] - fRec81[2]))) + (0.48633454893099998 * (fRec82[0] - fRec82[2]))) + (0.48518507209900003 * (fRec83[0] - fRec83[2]))) + (0.48532366912699998 * (fRec84[0] - fRec84[2]))) + (0.46226551429500001 * (fRec85[0] - fRec85[2]))) + (0.26074587604900001 * (fRec86[0] - fRec86[2]))) + (0.223428959895 * (fRec87[0] - fRec87[2]))) + (0.185381184974 * (fRec88[0] - fRec88[2]))) + (0.13017334441299999 * (fRec89[0] - fRec89[2]))) + (0.138031724927 * (fRec90[0] - fRec90[2]))) + (0.123137331499 * (fRec91[0] - fRec91[2]))) + (0.16523436521500001 * (fRec92[0] - fRec92[2]))) + (0.19798110832800001 * (fRec93[0] - fRec93[2]))) + (0.18040273232099999 * (fRec94[0] - fRec94[2]))) + (0.121604778297 * (fRec95[0] - fRec95[2]))) + (0.13062524890999999 * (fRec96[0] - fRec96[2]))) + (0.125266540585 * (fRec97[0] - fRec97[2]))) + (0.137101909661 * (fRec98[0] - fRec98[2]))) + (0.18483349310399999 * (fRec99[0] - fRec99[2]))) + (0.17780759364400001 * (fRec100[0] - fRec100[2]))) + (0.13375898226300001 * (fRec101[0] - fRec101[2]))) + (0.123192755738 * (fRec102[0] - fRec102[2]))) + (0.177447625212 * (fRec103[0] - fRec103[2]))) + (0.21632421971400001 * (fRec104[0] - fRec104[2]))) + (0.20851606102100001 * (fRec105[0] - fRec105[2]))) + (0.178241844954 * (fRec106[0] - fRec106[2]))) + (0.182989057712 * (fRec107[0] - fRec107[2]))) + (0.18212228977299999 * (fRec108[0] - fRec108[2]))) + (0.164855112389 * (fRec109[0] - fRec109[2]))) + (0.17797990346199999 * (fRec110[0] - fRec110[2]))) + (0.189797081555 * (fRec111[0] - fRec111[2]))) + (0.21203703200499999 * (fRec112[0] - fRec112[2]))) + (0.199658504417 * (fRec113[0] - fRec113[2]))) + (0.196307237154 * (fRec114[0] - fRec114[2]))) + (0.184730360835 * (fRec115[0] - fRec115[2]))) + (0.18777186680399999 * (fRec116[0] - fRec116[2]))) + (0.19011907561999999 * (fRec117[0] - fRec117[2]))) + (0.171781053277 * (fRec118[0] - fRec118[2]))) + (0.14070391233000001 * (fRec119[0] - fRec119[2]))) + (0.111393669352 * (fRec120[0] - fRec120[2]))) + (0.0957438805606 * (fRec121[0] - fRec121[2]))) + (0.0890744024419 * (fRec122[0] - fRec122[2]))) + (0.088431392903000006 * (fRec123[0] - fRec123[2]))) + (0.094351146138799996 * (fRec124[0] - fRec124[2]))) + (0.089072672529100005 * (fRec125[0] - fRec125[2]))) + (0.090640562690300006 * (fRec126[0] - fRec126[2]))) + (0.075510009810000001 * (fRec127[0] - fRec127[2]))) + (0.076371910897599996 * (fRec128[0] - fRec128[2]))) + (0.057437599582400002 * (fRec129[0] - fRec129[2]))) + (0.062416028714699999 * (fRec130[0] - fRec130[2]))) + (0.045583078064100002 * (fRec131[0] - fRec131[2]))) + (0.0481960684534 * (fRec132[0] - fRec132[2]))) + (0.032679847071699998 * (fRec133[0] - fRec133[2]))) + (0.035522457578099999 * (fRec134[0] - fRec134[2]))) + (0.033527779319099997 * (fRec135[0] - fRec135[2]))) + (0.033249705331699998 * (fRec136[0] - fRec136[2]))) + (0.0328796679898 * (fRec137[0] - fRec137[2]))) + (0.033345475623700001 * (fRec138[0] - fRec138[2]))) + (0.0273648722434 * (fRec139[0] - fRec139[2]))) + (0.029010770233899998 * (fRec140[0] - fRec140[2]))) + (0.029174141421799998 * (fRec141[0] - fRec141[2]))) + (0.029697551433899998 * (fRec142[0] - fRec142[2]))) + (0.035090276592000001 * (fRec143[0] - fRec143[2]))) + (0.032025351554900001 * (fRec144[0] - fRec144[2]))) + (0.0345915994975 * (fRec145[0] - fRec145[2]))) + (0.030877973889100001 * (fRec146[0] - fRec146[2]))) + (0.030916441114699999 * (fRec147[0] - fRec147[2]))) + (0.0278897571447 * (fRec148[0] - fRec148[2]))) + (0.028643149633199999 * (fRec149[0] - fRec149[2]))) + (0.0256569927043 * (fRec150[0] - fRec150[2]))) + (0.021689937925 * (fRec151[0] - fRec151[2]))) + (0.014298601628900001 * (fRec152[0] - fRec152[2]))) + (0.015101850754299999 * (fRec153[0] - fRec153[2]))) + (0.0101502606496 * (fRec154[0] - fRec154[2]))) + (0.0121241606261 * (fRec155[0] - fRec155[2]))) + (0.0111874821307 * (fRec156[0] - fRec156[2]))) + (0.0137725337551 * (fRec157[0] - fRec157[2]))) + (0.0130914794142 * (fRec158[0] - fRec158[2]))) + (0.0161429524991 * (fRec159[0] - fRec159[2]))) + (0.0125876114868 * (fRec160[0] - fRec160[2]))) + (0.012748190284900001 * (fRec161[0] - fRec161[2]))) + (0.0131979581826 * (fRec162[0] - fRec162[2]))) + (0.0116890588587 * (fRec163[0] - fRec163[2]))) + (0.011323441128199999 * (fRec164[0] - fRec164[2]))) + (0.0123474668689 * (fRec165[0] - fRec165[2]))) + (0.012032020002700001 * (fRec166[0] - fRec166[2]))) + (0.011270981202199999 * (fRec167[0] - fRec167[2]))) + (0.0111068783251 * (fRec168[0] - fRec168[2]))) + (0.013235790264500001 * (fRec169[0] - fRec169[2]))) + (0.012659252348299999 * (fRec170[0] - fRec170[2]))) + (0.018023532766400001 * (fRec171[0] - fRec171[2]))) + (0.017897904188999999 * (fRec172[0] - fRec172[2]))) + (0.017796488029399999 * (fRec173[0] - fRec173[2]))) + (0.0228914031149 * (fRec174[0] - fRec174[2]))) + (0.023949852717800001 * (fRec175[0] - fRec175[2]))) + (0.022649698584799999 * (fRec176[0] - fRec176[2]))) + (0.021575182032500001 * (fRec177[0] - fRec177[2]))) + (0.021121126959200001 * (fRec178[0] - fRec178[2]))) + (0.0210482932229 * (fRec179[0] - fRec179[2]))) + (0.021142094093599999 * (fRec180[0] - fRec180[2]))) + (0.021684459218699999 * (fRec181[0] - fRec181[2]))) + (0.017920238400699999 * (fRec182[0] - fRec182[2]))) + (0.017924826518700001 * (fRec183[0] - fRec183[2]))) + (0.017762148774700001 * (fRec184[0] - fRec184[2]))) + (0.017002051574200001 * (fRec185[0] - fRec185[2]))) + (0.0155858300598 * (fRec186[0] - fRec186[2]))) + (0.016030187749500002 * (fRec187[0] - fRec187[2]))) + (0.016478770375699999 * (fRec188[0] - fRec188[2]))) + (0.016757750563700002 * (fRec189[0] - fRec189[2]))) + (0.016824176915900001 * (fRec190[0] - fRec190[2]))) + (0.016912208121899999 * (fRec191[0] - fRec191[2]))) + (0.017037451387999999 * (fRec192[0] - fRec192[2]))) + (0.016739291503800002 * (fRec193[0] - fRec193[2]))) + (0.016919242442699999 * (fRec194[0] - fRec194[2]))) + (0.017250586978500002 * (fRec195[0] - fRec195[2]))) + (0.017253688019800002 * (fRec196[0] - fRec196[2]))) + (0.01891240391 * (fRec197[0] - fRec197[2]))) + (0.018938743764199999 * (fRec198[0] - fRec198[2]))) + (0.018662670473199999 * (fRec199[0] - fRec199[2]))) + (0.020444723138600001 * (fRec200[0] - fRec200[2]))) + (0.020864961754800002 * (fRec201[0] - fRec201[2]))) + (0.0211277211662 * (fRec202[0] - fRec202[2]))) + (0.021206565060600001 * (fRec203[0] - fRec203[2]))) + (0.020878888619099999 * (fRec204[0] - fRec204[2]))) + (0.020785374551100001 * (fRec205[0] - fRec205[2]))) + (0.0224288172927 * (fRec206[0] - fRec206[2]))) + (0.022580248730300002 * (fRec207[0] - fRec207[2]))) + (0.022734404072399999 * (fRec208[0] - fRec208[2]))) + (0.023272934158000001 * (fRec209[0] - fRec209[2]))) + (0.023435174357900001 * (fRec210[0] - fRec210[2]))) + (0.023466297535799999 * (fRec211[0] - fRec211[2]))) + (0.0233736826728 * (fRec212[0] - fRec212[2]))) + (0.0226100100317 * (fRec213[0] - fRec213[2]))) + (0.022850187032200001 * (fRec214[0] - fRec214[2]))) + (0.022184542431300001 * (fRec215[0] - fRec215[2]))) + (0.0215450023251 * (fRec216[0] - fRec216[2]))) + (0.020927230085600001 * (fRec217[0] - fRec217[2]))) + (0.0206269383624 * (fRec218[0] - fRec218[2]))) + (0.0209234868044 * (fRec219[0] - fRec219[2]))) + (0.020808061482000002 * (fRec220[0] - fRec220[2]))) + (0.020253895031500001 * (fRec221[0] - fRec221[2]))) + (0.020184360171999999 * (fRec222[0] - fRec222[2]))) + (0.019061190256300001 * (fRec223[0] - fRec223[2]))) + (0.018733974190700001 * (fRec224[0] - fRec224[2]))) + (0.018541640223099998 * (fRec225[0] - fRec225[2]))) + (0.015850689839900001 * (fRec226[0] - fRec226[2]))) + (0.0153645858652 * (fRec227[0] - fRec227[2]))) + (0.01465136563 * (fRec228[0] - fRec228[2]))) + (0.0105800462305 * (fRec229[0] - fRec229[2]))) + (0.011747521165499999 * (fRec230[0] - fRec230[2]))) + (0.0119236208741 * (fRec231[0] - fRec231[2]))) + (0.0125216842409 * (fRec232[0] - fRec232[2]))) + (0.012582451993299999 * (fRec233[0] - fRec233[2]))) + (0.0135344750087 * (fRec234[0] - fRec234[2]))) + (0.013256871282199999 * (fRec235[0] - fRec235[2]))) + (0.0135541135392 * (fRec236[0] - fRec236[2]))) + (0.0144643230657 * (fRec237[0] - fRec237[2]))) + (0.0150947590249 * (fRec238[0] - fRec238[2]))) + (0.0161992758634 * (fRec239[0] - fRec239[2]))) + (0.016686687601300002 * (fRec240[0] - fRec240[2]))) + (0.0165291188525 * (fRec241[0] - fRec241[2]))) + (0.016444118844800001 * (fRec242[0] - fRec242[2]))) + (0.0157456035506 * (fRec243[0] - fRec243[2]))) + (0.015497351000500001 * (fRec244[0] - fRec244[2]))) + (0.015443278609200001 * (fRec245[0] - fRec245[2]))) + (0.015759627398199999 * (fRec246[0] - fRec246[2]))) + (0.015905422413500001 * (fRec247[0] - fRec247[2]))) + (0.01572143707 * (fRec248[0] - fRec248[2]))) + (0.015834858387900001 * (fRec249[0] - fRec249[2]))) + (0.0151884466934 * (fRec250[0] - fRec250[2]))) + (0.0149829303458 * (fRec251[0] - fRec251[2]))) + (0.0153246129541 * (fRec252[0] - fRec252[2]))) + (0.0152159562681 * (fRec253[0] - fRec253[2]))) + (0.0153535548837 * (fRec254[0] - fRec254[2]))) + (0.0152104156713 * (fRec255[0] - fRec255[2]))) + (0.0144848023149 * (fRec256[0] - fRec256[2]))) + (0.014469633922199999 * (fRec257[0] - fRec257[2]))) + (0.014759862125599999 * (fRec258[0] - fRec258[2]))) + (0.014224289445700001 * (fRec259[0] - fRec259[2]))) + (0.0146558101822 * (fRec260[0] - fRec260[2]))) + (0.014039100556 * (fRec261[0] - fRec261[2]))) + (0.0134102334966 * (fRec262[0] - fRec262[2]))) + (0.013108888616900001 * (fRec263[0] - fRec263[2]))) + (0.0134126608149 * (fRec264[0] - fRec264[2]))) + (0.0132655208793 * (fRec265[0] - fRec265[2]))) + (0.013001120305100001 * (fRec266[0] - fRec266[2]))) + (0.0136077481738 * (fRec267[0] - fRec267[2]))) + (0.013623359932099999 * (fRec268[0] - fRec268[2]))) + (0.0134878283736 * (fRec269[0] - fRec269[2]))) + (0.0135235347974 * (fRec270[0] - fRec270[2]))) + (0.013005163099099999 * (fRec271[0] - fRec271[2]))) + (0.0134427722488 * (fRec272[0] - fRec272[2]))) + (0.0130874312888 * (fRec273[0] - fRec273[2]))) + (0.0133885467452 * (fRec274[0] - fRec274[2]))) + (0.012903353587 * (fRec275[0] - fRec275[2]))) + (0.013457359205 * (fRec276[0] - fRec276[2]))) + (0.013072166852500001 * (fRec277[0] - fRec277[2]))) + (0.012161754095500001 * (fRec278[0] - fRec278[2]))) + (0.0128669266092 * (fRec279[0] - fRec279[2]))) + (0.012734810014700001 * (fRec280[0] - fRec280[2]))) + (0.012575867375100001 * (fRec281[0] - fRec281[2]))) + (0.012028766637300001 * (fRec282[0] - fRec282[2]))) + (0.0115798595577 * (fRec283[0] - fRec283[2]))) + (0.011857779211200001 * (fRec284[0] - fRec284[2]))) + (0.0112681762453 * (fRec285[0] - fRec285[2]))) + (0.012541962411399999 * (fRec286[0] - fRec286[2]))) + (0.0118251893348 * (fRec287[0] - fRec287[2]))) + (0.011944904227500001 * (fRec288[0] - fRec288[2]))) + (0.011557513175000001 * (fRec289[0] - fRec289[2]))) + (0.010860442457 * (fRec290[0] - fRec290[2]))) + (0.0113832849399 * (fRec291[0] - fRec291[2]))) + (0.0112927149497 * (fRec292[0] - fRec292[2]))) + (0.0114252876879 * (fRec293[0] - fRec293[2]))) + (0.0116810602221 * (fRec294[0] - fRec294[2]))) + (0.011235842151 * (fRec295[0] - fRec295[2]))) + (0.0107353941681 * (fRec296[0] - fRec296[2]))) + (0.010712202512699999 * (fRec297[0] - fRec297[2]))) + (0.0117499828155 * (fRec298[0] - fRec298[2]))) + (0.0116225541834 * (fRec299[0] - fRec299[2]))) + (0.01168821123 * (fRec300[0] - fRec300[2]))) + (0.0108307813129 * (fRec301[0] - fRec301[2]))) + (0.011131642282 * (fRec302[0] - fRec302[2]))) + (0.0113311867587 * (fRec303[0] - fRec303[2]))) + (0.011001100630600001 * (fRec304[0] - fRec304[2]))) + (0.0109434823074 * (fRec305[0] - fRec305[2]))) + (0.011842635583199999 * (fRec306[0] - fRec306[2]))) + (0.011947654399800001 * (fRec307[0] - fRec307[2]))) + (0.011703519403799999 * (fRec308[0] - fRec308[2]))) + (0.0122546794833 * (fRec309[0] - fRec309[2]))) + (0.01278888324 * (fRec310[0] - fRec310[2]))) + (0.0124176731145 * (fRec311[0] - fRec311[2]))) + (0.0128854766489 * (fRec312[0] - fRec312[2]))) + (0.013114151134099999 * (fRec313[0] - fRec313[2]))) + (0.0125130715718 * (fRec314[0] - fRec314[2]))) + (0.0127470458895 * (fRec315[0] - fRec315[2]))) + (0.012851554165100001 * (fRec316[0] - fRec316[2]))) + (0.012406651234200001 * (fRec317[0] - fRec317[2]))) + (0.013275811331900001 * (fRec318[0] - fRec318[2]))) + (0.0124865562256 * (fRec319[0] - fRec319[2]))) + (0.0137948430007 * (fRec320[0] - fRec320[2]))) + (0.0130875925269 * (fRec321[0] - fRec321[2]))) + (0.012710525322 * (fRec322[0] - fRec322[2]))) + (0.012721584607700001 * (fRec323[0] - fRec323[2]))) + (0.012740460727999999 * (fRec324[0] - fRec324[2]))) + (0.0128817867037 * (fRec325[0] - fRec325[2]))) + (0.0121653961346 * (fRec326[0] - fRec326[2]))) + (0.011913796418 * (fRec327[0] - fRec327[2]))) + (0.0120453475754 * (fRec328[0] - fRec328[2]))) + (0.011765511095900001 * (fRec329[0] - fRec329[2]))) + (0.0124500276586 * (fRec330[0] - fRec330[2]))) + (0.0113977364963 * (fRec331[0] - fRec331[2]))) + (0.0116210008226 * (fRec332[0] - fRec332[2]))) + (0.0120623190717 * (fRec333[0] - fRec333[2]))) + (0.010616200583900001 * (fRec334[0] - fRec334[2]))) + (0.0111794127801 * (fRec335[0] - fRec335[2]))) + (0.010045602955700001 * (fRec336[0] - fRec336[2]))) + (0.0103952717017 * (fRec337[0] - fRec337[2]))) + (0.0102168121494 * (fRec338[0] - fRec338[2])))))));
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
			fRec295[2] = fRec295[1];
			fRec295[1] = fRec295[0];
			fRec296[2] = fRec296[1];
			fRec296[1] = fRec296[0];
			fRec297[2] = fRec297[1];
			fRec297[1] = fRec297[0];
			fRec298[2] = fRec298[1];
			fRec298[1] = fRec298[0];
			fRec299[2] = fRec299[1];
			fRec299[1] = fRec299[0];
			fRec300[2] = fRec300[1];
			fRec300[1] = fRec300[0];
			fRec301[2] = fRec301[1];
			fRec301[1] = fRec301[0];
			fRec302[2] = fRec302[1];
			fRec302[1] = fRec302[0];
			fRec303[2] = fRec303[1];
			fRec303[1] = fRec303[0];
			fRec304[2] = fRec304[1];
			fRec304[1] = fRec304[0];
			fRec305[2] = fRec305[1];
			fRec305[1] = fRec305[0];
			fRec306[2] = fRec306[1];
			fRec306[1] = fRec306[0];
			fRec307[2] = fRec307[1];
			fRec307[1] = fRec307[0];
			fRec308[2] = fRec308[1];
			fRec308[1] = fRec308[0];
			fRec309[2] = fRec309[1];
			fRec309[1] = fRec309[0];
			fRec310[2] = fRec310[1];
			fRec310[1] = fRec310[0];
			fRec311[2] = fRec311[1];
			fRec311[1] = fRec311[0];
			fRec312[2] = fRec312[1];
			fRec312[1] = fRec312[0];
			fRec313[2] = fRec313[1];
			fRec313[1] = fRec313[0];
			fRec314[2] = fRec314[1];
			fRec314[1] = fRec314[0];
			fRec315[2] = fRec315[1];
			fRec315[1] = fRec315[0];
			fRec316[2] = fRec316[1];
			fRec316[1] = fRec316[0];
			fRec317[2] = fRec317[1];
			fRec317[1] = fRec317[0];
			fRec318[2] = fRec318[1];
			fRec318[1] = fRec318[0];
			fRec319[2] = fRec319[1];
			fRec319[1] = fRec319[0];
			fRec320[2] = fRec320[1];
			fRec320[1] = fRec320[0];
			fRec321[2] = fRec321[1];
			fRec321[1] = fRec321[0];
			fRec322[2] = fRec322[1];
			fRec322[1] = fRec322[0];
			fRec323[2] = fRec323[1];
			fRec323[1] = fRec323[0];
			fRec324[2] = fRec324[1];
			fRec324[1] = fRec324[0];
			fRec325[2] = fRec325[1];
			fRec325[1] = fRec325[0];
			fRec326[2] = fRec326[1];
			fRec326[1] = fRec326[0];
			fRec327[2] = fRec327[1];
			fRec327[1] = fRec327[0];
			fRec328[2] = fRec328[1];
			fRec328[1] = fRec328[0];
			fRec329[2] = fRec329[1];
			fRec329[1] = fRec329[0];
			fRec330[2] = fRec330[1];
			fRec330[1] = fRec330[0];
			fRec331[2] = fRec331[1];
			fRec331[1] = fRec331[0];
			fRec332[2] = fRec332[1];
			fRec332[1] = fRec332[0];
			fRec333[2] = fRec333[1];
			fRec333[1] = fRec333[0];
			fRec334[2] = fRec334[1];
			fRec334[1] = fRec334[0];
			fRec335[2] = fRec335[1];
			fRec335[1] = fRec335[0];
			fRec336[2] = fRec336[1];
			fRec336[1] = fRec336[0];
			fRec337[2] = fRec337[1];
			fRec337[1] = fRec337[0];
			fRec338[2] = fRec338[1];
			fRec338[1] = fRec338[0];
			
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
