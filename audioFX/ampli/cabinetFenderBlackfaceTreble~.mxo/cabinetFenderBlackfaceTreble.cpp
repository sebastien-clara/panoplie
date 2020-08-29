/* ------------------------------------------------------------
name: "cabinetFenderBlackfaceTreble"
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
	double fConst6;
	double fConst7;
	double fConst8;
	double fRec1[3];
	double fConst9;
	double fConst10;
	double fConst11;
	double fConst12;
	double fRec2[3];
	double fConst13;
	double fRec3[3];
	double fConst14;
	double fConst15;
	double fConst16;
	double fRec4[3];
	double fConst17;
	double fConst18;
	double fConst19;
	double fConst20;
	double fRec5[3];
	double fConst21;
	double fRec6[3];
	double fConst22;
	double fConst23;
	double fConst24;
	double fConst25;
	double fRec7[3];
	double fConst26;
	double fRec8[3];
	double fConst27;
	double fConst28;
	double fConst29;
	double fRec9[3];
	double fConst30;
	double fRec10[3];
	double fConst31;
	double fConst32;
	double fConst33;
	double fConst34;
	double fRec11[3];
	double fConst35;
	double fRec12[3];
	double fConst36;
	double fConst37;
	double fConst38;
	double fConst39;
	double fRec13[3];
	double fConst40;
	double fConst41;
	double fConst42;
	double fRec14[3];
	double fConst43;
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
	double fRec17[3];
	double fConst52;
	double fRec18[3];
	double fConst53;
	double fRec19[3];
	double fConst54;
	double fConst55;
	double fConst56;
	double fRec20[3];
	double fConst57;
	double fRec21[3];
	double fConst58;
	double fConst59;
	double fConst60;
	double fRec22[3];
	double fConst61;
	double fConst62;
	double fConst63;
	double fConst64;
	double fRec23[3];
	double fConst65;
	double fConst66;
	double fConst67;
	double fRec24[3];
	double fConst68;
	double fRec25[3];
	double fConst69;
	double fRec26[3];
	double fConst70;
	double fConst71;
	double fConst72;
	double fRec27[3];
	double fConst73;
	double fConst74;
	double fConst75;
	double fConst76;
	double fRec28[3];
	double fConst77;
	double fRec29[3];
	double fConst78;
	double fConst79;
	double fConst80;
	double fConst81;
	double fRec30[3];
	double fConst82;
	double fConst83;
	double fConst84;
	double fRec31[3];
	double fConst85;
	double fRec32[3];
	double fConst86;
	double fRec33[3];
	double fConst87;
	double fConst88;
	double fConst89;
	double fRec34[3];
	double fConst90;
	double fConst91;
	double fConst92;
	double fConst93;
	double fRec35[3];
	double fConst94;
	double fConst95;
	double fConst96;
	double fRec36[3];
	double fConst97;
	double fConst98;
	double fConst99;
	double fRec37[3];
	double fConst100;
	double fRec38[3];
	double fConst101;
	double fRec39[3];
	double fConst102;
	double fConst103;
	double fConst104;
	double fConst105;
	double fRec40[3];
	double fConst106;
	double fConst107;
	double fConst108;
	double fConst109;
	double fRec41[3];
	double fConst110;
	double fRec42[3];
	double fConst111;
	double fRec43[3];
	double fConst112;
	double fRec44[3];
	double fConst113;
	double fRec45[3];
	double fConst114;
	double fConst115;
	double fConst116;
	double fRec46[3];
	double fConst117;
	double fConst118;
	double fConst119;
	double fConst120;
	double fRec47[3];
	double fConst121;
	double fRec48[3];
	double fConst122;
	double fConst123;
	double fConst124;
	double fRec49[3];
	double fConst125;
	double fConst126;
	double fConst127;
	double fRec50[3];
	double fConst128;
	double fConst129;
	double fConst130;
	double fRec51[3];
	double fConst131;
	double fRec52[3];
	double fConst132;
	double fRec53[3];
	double fConst133;
	double fConst134;
	double fConst135;
	double fRec54[3];
	double fConst136;
	double fConst137;
	double fConst138;
	double fRec55[3];
	double fConst139;
	double fConst140;
	double fConst141;
	double fRec56[3];
	double fConst142;
	double fConst143;
	double fConst144;
	double fConst145;
	double fRec57[3];
	double fConst146;
	double fRec58[3];
	double fConst147;
	double fRec59[3];
	double fConst148;
	double fConst149;
	double fConst150;
	double fRec60[3];
	double fConst151;
	double fRec61[3];
	double fConst152;
	double fConst153;
	double fConst154;
	double fConst155;
	double fRec62[3];
	double fConst156;
	double fRec63[3];
	double fConst157;
	double fRec64[3];
	double fConst158;
	double fRec65[3];
	double fConst159;
	double fRec66[3];
	double fConst160;
	double fConst161;
	double fConst162;
	double fRec67[3];
	double fConst163;
	double fRec68[3];
	double fConst164;
	double fRec69[3];
	double fConst165;
	double fRec70[3];
	double fConst166;
	double fRec71[3];
	double fConst167;
	double fRec72[3];
	double fConst168;
	double fRec73[3];
	double fConst169;
	double fRec74[3];
	double fConst170;
	double fRec75[3];
	double fConst171;
	double fRec76[3];
	double fConst172;
	double fRec77[3];
	double fConst173;
	double fConst174;
	double fConst175;
	double fConst176;
	double fRec78[3];
	double fConst177;
	double fRec79[3];
	double fConst178;
	double fConst179;
	double fConst180;
	double fConst181;
	double fRec80[3];
	double fConst182;
	double fRec81[3];
	double fConst183;
	double fConst184;
	double fConst185;
	double fRec82[3];
	double fConst186;
	double fConst187;
	double fConst188;
	double fConst189;
	double fRec83[3];
	double fConst190;
	double fConst191;
	double fConst192;
	double fRec84[3];
	double fConst193;
	double fConst194;
	double fConst195;
	double fRec85[3];
	double fConst196;
	double fConst197;
	double fConst198;
	double fRec86[3];
	double fConst199;
	double fConst200;
	double fConst201;
	double fConst202;
	double fRec87[3];
	double fConst203;
	double fConst204;
	double fConst205;
	double fConst206;
	double fRec88[3];
	double fConst207;
	double fRec89[3];
	double fConst208;
	double fConst209;
	double fConst210;
	double fRec90[3];
	double fConst211;
	double fConst212;
	double fConst213;
	double fRec91[3];
	double fConst214;
	double fConst215;
	double fConst216;
	double fConst217;
	double fRec92[3];
	double fConst218;
	double fConst219;
	double fConst220;
	double fConst221;
	double fRec93[3];
	double fConst222;
	double fConst223;
	double fConst224;
	double fConst225;
	double fRec94[3];
	double fConst226;
	double fConst227;
	double fConst228;
	double fRec95[3];
	double fConst229;
	double fRec96[3];
	double fConst230;
	double fRec97[3];
	double fConst231;
	double fRec98[3];
	double fConst232;
	double fConst233;
	double fConst234;
	double fConst235;
	double fRec99[3];
	double fConst236;
	double fRec100[3];
	double fConst237;
	double fRec101[3];
	double fConst238;
	double fRec102[3];
	double fConst239;
	double fConst240;
	double fConst241;
	double fRec103[3];
	double fConst242;
	double fRec104[3];
	double fConst243;
	double fConst244;
	double fConst245;
	double fConst246;
	double fRec105[3];
	double fConst247;
	double fConst248;
	double fConst249;
	double fRec106[3];
	double fConst250;
	double fRec107[3];
	double fConst251;
	double fConst252;
	double fConst253;
	double fRec108[3];
	double fConst254;
	double fRec109[3];
	double fConst255;
	double fRec110[3];
	double fConst256;
	double fRec111[3];
	double fConst257;
	double fRec112[3];
	double fConst258;
	double fRec113[3];
	double fConst259;
	double fRec114[3];
	double fConst260;
	double fRec115[3];
	double fConst261;
	double fConst262;
	double fConst263;
	double fConst264;
	double fRec116[3];
	double fConst265;
	double fRec117[3];
	double fConst266;
	double fRec118[3];
	double fConst267;
	double fRec119[3];
	double fConst268;
	double fConst269;
	double fConst270;
	double fConst271;
	double fRec120[3];
	double fConst272;
	double fRec121[3];
	double fConst273;
	double fConst274;
	double fConst275;
	double fConst276;
	double fRec122[3];
	double fConst277;
	double fRec123[3];
	double fConst278;
	double fConst279;
	double fConst280;
	double fRec124[3];
	double fConst281;
	double fConst282;
	double fConst283;
	double fConst284;
	double fRec125[3];
	double fConst285;
	double fRec126[3];
	double fConst286;
	double fConst287;
	double fConst288;
	double fRec127[3];
	double fConst289;
	double fConst290;
	double fConst291;
	double fRec128[3];
	double fConst292;
	double fConst293;
	double fConst294;
	double fRec129[3];
	double fConst295;
	double fRec130[3];
	double fConst296;
	double fConst297;
	double fConst298;
	double fRec131[3];
	double fConst299;
	double fRec132[3];
	double fConst300;
	double fConst301;
	double fConst302;
	double fRec133[3];
	double fConst303;
	double fConst304;
	double fConst305;
	double fRec134[3];
	double fConst306;
	double fConst307;
	double fConst308;
	double fRec135[3];
	double fConst309;
	double fConst310;
	double fConst311;
	double fRec136[3];
	double fConst312;
	double fConst313;
	double fConst314;
	double fConst315;
	double fRec137[3];
	double fConst316;
	double fConst317;
	double fConst318;
	double fConst319;
	double fRec138[3];
	double fConst320;
	double fConst321;
	double fConst322;
	double fRec139[3];
	double fConst323;
	double fConst324;
	double fConst325;
	double fRec140[3];
	double fConst326;
	double fRec141[3];
	double fConst327;
	double fConst328;
	double fConst329;
	double fRec142[3];
	double fConst330;
	double fRec143[3];
	double fConst331;
	double fConst332;
	double fConst333;
	double fRec144[3];
	double fConst334;
	double fConst335;
	double fConst336;
	double fConst337;
	double fRec145[3];
	double fConst338;
	double fRec146[3];
	double fConst339;
	double fRec147[3];
	double fConst340;
	double fConst341;
	double fConst342;
	double fRec148[3];
	double fConst343;
	double fConst344;
	double fConst345;
	double fRec149[3];
	double fConst346;
	double fConst347;
	double fConst348;
	double fRec150[3];
	double fConst349;
	double fConst350;
	double fConst351;
	double fConst352;
	double fRec151[3];
	double fConst353;
	double fConst354;
	double fConst355;
	double fConst356;
	double fRec152[3];
	double fConst357;
	double fConst358;
	double fConst359;
	double fRec153[3];
	double fConst360;
	double fConst361;
	double fConst362;
	double fRec154[3];
	double fConst363;
	double fRec155[3];
	double fConst364;
	double fRec156[3];
	double fConst365;
	double fRec157[3];
	double fConst366;
	double fConst367;
	double fConst368;
	double fRec158[3];
	double fConst369;
	double fConst370;
	double fConst371;
	double fRec159[3];
	double fConst372;
	double fConst373;
	double fConst374;
	double fConst375;
	double fRec160[3];
	double fConst376;
	double fConst377;
	double fConst378;
	double fRec161[3];
	double fConst379;
	double fRec162[3];
	double fConst380;
	double fConst381;
	double fConst382;
	double fRec163[3];
	double fConst383;
	double fConst384;
	double fConst385;
	double fRec164[3];
	double fConst386;
	double fConst387;
	double fConst388;
	double fRec165[3];
	double fConst389;
	double fConst390;
	double fConst391;
	double fConst392;
	double fRec166[3];
	double fConst393;
	double fRec167[3];
	double fConst394;
	double fConst395;
	double fConst396;
	double fRec168[3];
	double fConst397;
	double fRec169[3];
	double fConst398;
	double fRec170[3];
	double fConst399;
	double fConst400;
	double fConst401;
	double fConst402;
	double fRec171[3];
	double fConst403;
	double fConst404;
	double fConst405;
	double fConst406;
	double fRec172[3];
	double fConst407;
	double fConst408;
	double fConst409;
	double fConst410;
	double fRec173[3];
	double fConst411;
	double fConst412;
	double fConst413;
	double fConst414;
	double fRec174[3];
	double fConst415;
	double fRec175[3];
	double fConst416;
	double fConst417;
	double fConst418;
	double fConst419;
	double fRec176[3];
	double fConst420;
	double fConst421;
	double fConst422;
	double fConst423;
	double fRec177[3];
	double fConst424;
	double fConst425;
	double fConst426;
	double fConst427;
	double fRec178[3];
	double fConst428;
	double fRec179[3];
	double fConst429;
	double fRec180[3];
	double fConst430;
	double fRec181[3];
	double fConst431;
	double fConst432;
	double fConst433;
	double fConst434;
	double fRec182[3];
	double fConst435;
	double fRec183[3];
	double fConst436;
	double fConst437;
	double fConst438;
	double fConst439;
	double fRec184[3];
	double fConst440;
	double fRec185[3];
	double fConst441;
	double fConst442;
	double fConst443;
	double fConst444;
	double fRec186[3];
	double fConst445;
	double fRec187[3];
	double fConst446;
	double fConst447;
	double fConst448;
	double fConst449;
	double fRec188[3];
	double fConst450;
	double fConst451;
	double fConst452;
	double fConst453;
	double fRec189[3];
	double fConst454;
	double fRec190[3];
	double fConst455;
	double fRec191[3];
	double fConst456;
	double fConst457;
	double fConst458;
	double fRec192[3];
	double fConst459;
	double fRec193[3];
	double fConst460;
	double fRec194[3];
	double fConst461;
	double fRec195[3];
	double fConst462;
	double fRec196[3];
	double fConst463;
	double fRec197[3];
	double fConst464;
	double fRec198[3];
	double fConst465;
	double fRec199[3];
	double fConst466;
	double fRec200[3];
	double fConst467;
	double fRec201[3];
	double fConst468;
	double fConst469;
	double fConst470;
	double fRec202[3];
	double fConst471;
	double fRec203[3];
	double fConst472;
	double fRec204[3];
	double fConst473;
	double fRec205[3];
	double fConst474;
	double fRec206[3];
	double fConst475;
	double fRec207[3];
	double fConst476;
	double fRec208[3];
	double fConst477;
	double fConst478;
	double fConst479;
	double fConst480;
	double fRec209[3];
	double fConst481;
	double fRec210[3];
	double fConst482;
	double fRec211[3];
	double fConst483;
	double fRec212[3];
	double fConst484;
	double fRec213[3];
	double fConst485;
	double fRec214[3];
	double fConst486;
	double fRec215[3];
	double fConst487;
	double fRec216[3];
	double fConst488;
	double fRec217[3];
	double fConst489;
	double fRec218[3];
	double fConst490;
	double fRec219[3];
	double fConst491;
	double fRec220[3];
	double fConst492;
	double fRec221[3];
	double fConst493;
	double fConst494;
	double fConst495;
	double fRec222[3];
	double fConst496;
	double fConst497;
	double fConst498;
	double fRec223[3];
	double fConst499;
	double fConst500;
	double fConst501;
	double fRec224[3];
	double fConst502;
	double fConst503;
	double fConst504;
	double fConst505;
	double fRec225[3];
	double fConst506;
	double fRec226[3];
	double fConst507;
	double fConst508;
	double fConst509;
	double fConst510;
	double fRec227[3];
	double fConst511;
	double fRec228[3];
	double fConst512;
	double fRec229[3];
	double fConst513;
	double fConst514;
	double fConst515;
	double fConst516;
	double fRec230[3];
	double fConst517;
	double fConst518;
	double fConst519;
	double fConst520;
	double fRec231[3];
	double fConst521;
	double fRec232[3];
	double fConst522;
	double fConst523;
	double fConst524;
	double fConst525;
	double fRec233[3];
	double fConst526;
	double fConst527;
	double fConst528;
	double fConst529;
	double fRec234[3];
	double fConst530;
	double fRec235[3];
	double fConst531;
	double fRec236[3];
	double fConst532;
	double fConst533;
	double fConst534;
	double fConst535;
	double fRec237[3];
	double fConst536;
	double fRec238[3];
	double fConst537;
	double fRec239[3];
	double fConst538;
	double fRec240[3];
	double fConst539;
	double fRec241[3];
	double fConst540;
	double fRec242[3];
	double fConst541;
	double fRec243[3];
	double fConst542;
	double fRec244[3];
	double fConst543;
	double fRec245[3];
	double fConst544;
	double fRec246[3];
	double fConst545;
	double fConst546;
	double fConst547;
	double fConst548;
	double fRec247[3];
	double fConst549;
	double fRec248[3];
	double fConst550;
	double fRec249[3];
	double fConst551;
	double fRec250[3];
	double fConst552;
	double fRec251[3];
	double fConst553;
	double fRec252[3];
	double fConst554;
	double fRec253[3];
	double fConst555;
	double fRec254[3];
	double fConst556;
	double fRec255[3];
	double fConst557;
	double fRec256[3];
	double fConst558;
	double fRec257[3];
	double fConst559;
	double fRec258[3];
	double fConst560;
	double fRec259[3];
	double fConst561;
	double fRec260[3];
	double fConst562;
	double fRec261[3];
	double fConst563;
	double fRec262[3];
	double fConst564;
	double fRec263[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.0");
		m->declare("description", "Generated by tools/physicalModeling/ir2dsp.py");
		m->declare("filename", "cabinetFenderBlackfaceTreble");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "0.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.1");
		m->declare("name", "cabinetFenderBlackfaceTreble");
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
		fConst1 = pow(0.001, (1.0 / (0.098610814397899996 * fConst0)));
		fConst2 = (0.0 - (2.0 * fConst1));
		fConst3 = (cos((663.14157562206776 / fConst0)) * fConst2);
		fConst4 = mydsp_faustpower2_f(fConst1);
		fConst5 = pow(0.001, (1.0 / (0.099411891051299994 * fConst0)));
		fConst6 = (0.0 - (2.0 * fConst5));
		fConst7 = (cos((837.65251657954252 / fConst0)) * fConst6);
		fConst8 = mydsp_faustpower2_f(fConst5);
		fConst9 = pow(0.001, (1.0 / (0.61097953158700002 * fConst0)));
		fConst10 = (0.0 - (2.0 * fConst9));
		fConst11 = (cos((1116.8700221039621 / fConst0)) * fConst10);
		fConst12 = mydsp_faustpower2_f(fConst9);
		fConst13 = (fConst6 * cos((1500.7940922016101 / fConst0)));
		fConst14 = pow(0.001, (1.0 / (0.28421843725099999 * fConst0)));
		fConst15 = (cos((1710.2072213480665 / fConst0)) * (0.0 - (2.0 * fConst14)));
		fConst16 = mydsp_faustpower2_f(fConst14);
		fConst17 = pow(0.001, (1.0 / (0.29807892888600002 * fConst0)));
		fConst18 = (0.0 - (2.0 * fConst17));
		fConst19 = (cos((1919.6203504945229 / fConst0)) * fConst18);
		fConst20 = mydsp_faustpower2_f(fConst17);
		fConst21 = (fConst18 * cos((2094.1312914457149 / fConst0)));
		fConst22 = pow(0.001, (1.0 / (0.29098367721200002 * fConst0)));
		fConst23 = (0.0 - (2.0 * fConst22));
		fConst24 = (cos((2722.3706788788008 / fConst0)) * fConst23);
		fConst25 = mydsp_faustpower2_f(fConst22);
		fConst26 = (fConst18 * cos((3804.3385127937813 / fConst0)));
		fConst27 = pow(0.001, (1.0 / (0.643132225291 * fConst0)));
		fConst28 = (cos((4502.3822766111143 / fConst0)) * (0.0 - (2.0 * fConst27)));
		fConst29 = mydsp_faustpower2_f(fConst27);
		fConst30 = (fConst10 * cos((4746.6975939465519 / fConst0)));
		fConst31 = pow(0.001, (1.0 / (0.19714325297800001 * fConst0)));
		fConst32 = (0.0 - (2.0 * fConst31));
		fConst33 = (cos((5340.0347931906563 / fConst0)) * fConst32);
		fConst34 = mydsp_faustpower2_f(fConst31);
		fConst35 = (fConst32 * cos((5514.5457341418478 / fConst0)));
		fConst36 = pow(0.001, (1.0 / (0.19098497525300001 * fConst0)));
		fConst37 = (0.0 - (2.0 * fConst36));
		fConst38 = (cos((5723.9588632883042 / fConst0)) * fConst37);
		fConst39 = mydsp_faustpower2_f(fConst36);
		fConst40 = pow(0.001, (1.0 / (0.305528943153 * fConst0)));
		fConst41 = (cos((6212.5894979591803 / fConst0)) * (0.0 - (2.0 * fConst40)));
		fConst42 = mydsp_faustpower2_f(fConst40);
		fConst43 = pow(0.001, (1.0 / (0.207163501523 * fConst0)));
		fConst44 = (0.0 - (2.0 * fConst43));
		fConst45 = (cos((6282.3938743434264 / fConst0)) * fConst44);
		fConst46 = mydsp_faustpower2_f(fConst43);
		fConst47 = pow(0.001, (1.0 / (0.55544306068799998 * fConst0)));
		fConst48 = (0.0 - (2.0 * fConst47));
		fConst49 = (cos((6422.0026270867875 / fConst0)) * fConst48);
		fConst50 = mydsp_faustpower2_f(fConst47);
		fConst51 = (fConst32 * cos((6945.5354499529285 / fConst0)));
		fConst52 = (fConst37 * cos((7120.046390929253 / fConst0)));
		fConst53 = (fConst37 * cos((7189.8507673072163 / fConst0)));
		fConst54 = pow(0.001, (1.0 / (0.203712082574 * fConst0)));
		fConst55 = (cos((7887.8945310868494 / fConst0)) * (0.0 - (2.0 * fConst54)));
		fConst56 = mydsp_faustpower2_f(fConst54);
		fConst57 = (fConst44 * cos((7992.6010956852097 / fConst0)));
		fConst58 = pow(0.001, (1.0 / (0.210733934924 * fConst0)));
		fConst59 = (cos((8062.4054720631739 / fConst0)) * (0.0 - (2.0 * fConst58)));
		fConst60 = mydsp_faustpower2_f(fConst58);
		fConst61 = pow(0.001, (1.0 / (0.039876518787599999 * fConst0)));
		fConst62 = (0.0 - (2.0 * fConst61));
		fConst63 = (cos((8446.3295421733874 / fConst0)) * fConst62);
		fConst64 = mydsp_faustpower2_f(fConst61);
		fConst65 = pow(0.001, (1.0 / (0.040006577844699999 * fConst0)));
		fConst66 = (cos((8655.7426713072782 / fConst0)) * (0.0 - (2.0 * fConst65)));
		fConst67 = mydsp_faustpower2_f(fConst65);
		fConst68 = (fConst62 * cos((8725.5470476852406 / fConst0)));
		fConst69 = (fConst62 * cos((8830.2536122836009 / fConst0)));
		fConst70 = pow(0.001, (1.0 / (0.20037382490799999 * fConst0)));
		fConst71 = (cos((9249.0798705513826 / fConst0)) * (0.0 - (2.0 * fConst70)));
		fConst72 = mydsp_faustpower2_f(fConst70);
		fConst73 = pow(0.001, (1.0 / (0.039618926095300003 * fConst0)));
		fConst74 = (0.0 - (2.0 * fConst73));
		fConst75 = (cos((10016.928010771811 / fConst0)) * fConst74);
		fConst76 = mydsp_faustpower2_f(fConst73);
		fConst77 = (fConst74 * cos((10156.536763527738 / fConst0)));
		fConst78 = pow(0.001, (1.0 / (0.71878562230200005 * fConst0)));
		fConst79 = (0.0 - (2.0 * fConst78));
		fConst80 = (cos((10749.873962771842 / fConst0)) * fConst79);
		fConst81 = mydsp_faustpower2_f(fConst78);
		fConst82 = pow(0.001, (1.0 / (0.097046807606399998 * fConst0)));
		fConst83 = (cos((11517.72210292944 / fConst0)) * (0.0 - (2.0 * fConst82)));
		fConst84 = mydsp_faustpower2_f(fConst82);
		fConst85 = (fConst2 * cos((11762.037420283727 / fConst0)));
		fConst86 = (fConst2 * cos((11936.548361260051 / fConst0)));
		fConst87 = pow(0.001, (1.0 / (0.076921287468300001 * fConst0)));
		fConst88 = (cos((12145.961490393942 / fConst0)) * (0.0 - (2.0 * fConst87)));
		fConst89 = mydsp_faustpower2_f(fConst87);
		fConst90 = pow(0.001, (1.0 / (0.76370482680899998 * fConst0)));
		fConst91 = (0.0 - (2.0 * fConst90));
		fConst92 = (cos((12809.103066016009 / fConst0)) * fConst91);
		fConst93 = mydsp_faustpower2_f(fConst90);
		fConst94 = pow(0.001, (1.0 / (0.58188899920299997 * fConst0)));
		fConst95 = (cos((13611.853394394002 / fConst0)) * (0.0 - (2.0 * fConst94)));
		fConst96 = mydsp_faustpower2_f(fConst94);
		fConst97 = pow(0.001, (1.0 / (0.174621551698 * fConst0)));
		fConst98 = (cos((14344.799346394033 / fConst0)) * (0.0 - (2.0 * fConst97)));
		fConst99 = mydsp_faustpower2_f(fConst97);
		fConst100 = (fConst2 * cos((14554.212475527924 / fConst0)));
		fConst101 = (fConst74 * cos((14868.332169260177 / fConst0)));
		fConst102 = pow(0.001, (1.0 / (0.93992632156599998 * fConst0)));
		fConst103 = (0.0 - (2.0 * fConst102));
		fConst104 = (cos((15391.864992126317 / fConst0)) * fConst103);
		fConst105 = mydsp_faustpower2_f(fConst102);
		fConst106 = pow(0.001, (1.0 / (0.87279432353899999 * fConst0)));
		fConst107 = (0.0 - (2.0 * fConst106));
		fConst108 = (cos((16404.028449638201 / fConst0)) * fConst107);
		fConst109 = mydsp_faustpower2_f(fConst106);
		fConst110 = (fConst103 * cos((17136.974401701063 / fConst0)));
		fConst111 = (fConst91 * cos((17939.724730079059 / fConst0)));
		fConst112 = (fConst79 * cos((18114.235670992552 / fConst0)));
		fConst113 = (fConst91 * cos((18847.181622992583 / fConst0)));
		fConst114 = pow(0.001, (1.0 / (0.239647444806 * fConst0)));
		fConst115 = (cos((19649.931951433409 / fConst0)) * (0.0 - (2.0 * fConst114)));
		fConst116 = mydsp_faustpower2_f(fConst114);
		fConst117 = pow(0.001, (1.0 / (0.254620512528 * fConst0)));
		fConst118 = (0.0 - (2.0 * fConst117));
		fConst119 = (cos((19859.345080567295 / fConst0)) * fConst118);
		fConst120 = mydsp_faustpower2_f(fConst117);
		fConst121 = (fConst118 * cos((20278.171338835076 / fConst0)));
		fConst122 = pow(0.001, (1.0 / (0.24443882647000001 * fConst0)));
		fConst123 = (cos((20696.997597102858 / fConst0)) * (0.0 - (2.0 * fConst122)));
		fConst124 = mydsp_faustpower2_f(fConst122);
		fConst125 = pow(0.001, (1.0 / (0.123492741768 * fConst0)));
		fConst126 = (cos((21395.041360945324 / fConst0)) * (0.0 - (2.0 * fConst125)));
		fConst127 = mydsp_faustpower2_f(fConst125);
		fConst128 = pow(0.001, (1.0 / (0.12225859813000001 * fConst0)));
		fConst129 = (cos((21674.258866457178 / fConst0)) * (0.0 - (2.0 * fConst128)));
		fConst130 = mydsp_faustpower2_f(fConst128);
		fConst131 = (fConst48 * cos((22337.400442079244 / fConst0)));
		fConst132 = (fConst48 * cos((22477.009194835169 / fConst0)));
		fConst133 = pow(0.001, (1.0 / (0.0417781332279 * fConst0)));
		fConst134 = (cos((23419.368276031924 / fConst0)) * (0.0 - (2.0 * fConst133)));
		fConst135 = mydsp_faustpower2_f(fConst133);
		fConst136 = pow(0.001, (1.0 / (0.041495423464600001 * fConst0)));
		fConst137 = (cos((23558.977028787849 / fConst0)) * (0.0 - (2.0 * fConst136)));
		fConst138 = mydsp_faustpower2_f(fConst136);
		fConst139 = pow(0.001, (1.0 / (0.0624152329582 * fConst0)));
		fConst140 = (cos((24082.509851653991 / fConst0)) * (0.0 - (2.0 * fConst139)));
		fConst141 = mydsp_faustpower2_f(fConst139);
		fConst142 = pow(0.001, (1.0 / (0.128689136067 * fConst0)));
		fConst143 = (0.0 - (2.0 * fConst142));
		fConst144 = (cos((24431.531733543809 / fConst0)) * fConst143);
		fConst145 = mydsp_faustpower2_f(fConst142);
		fConst146 = (fConst18 * cos((24850.357991811587 / fConst0)));
		fConst147 = (fConst23 * cos((25129.575497386275 / fConst0)));
		fConst148 = pow(0.001, (1.0 / (0.45259774442700001 * fConst0)));
		fConst149 = (cos((25967.228013921831 / fConst0)) * (0.0 - (2.0 * fConst148)));
		fConst150 = mydsp_faustpower2_f(fConst148);
		fConst151 = (fConst143 * cos((26735.076154142262 / fConst0)));
		fConst152 = pow(0.001, (1.0 / (0.67885744053700003 * fConst0)));
		fConst153 = (0.0 - (2.0 * fConst152));
		fConst154 = (cos((27712.337423496581 / fConst0)) * fConst153);
		fConst155 = mydsp_faustpower2_f(fConst152);
		fConst156 = (fConst153 * cos((27921.75055263047 / fConst0)));
		fConst157 = (fConst153 * cos((28619.794316410105 / fConst0)));
		fConst158 = (fConst103 * cos((29457.446833008496 / fConst0)));
		fConst159 = (fConst103 * cos((30295.099349606888 / fConst0)));
		fConst160 = pow(0.001, (1.0 / (0.814613258605 * fConst0)));
		fConst161 = (cos((31167.654054362847 / fConst0)) * (0.0 - (2.0 * fConst160)));
		fConst162 = mydsp_faustpower2_f(fConst160);
		fConst163 = (fConst10 * cos((32110.013135496767 / fConst0)));
		fConst164 = (fConst103 * cos((32982.567840315562 / fConst0)));
		fConst165 = (fConst103 * cos((33820.220356851118 / fConst0)));
		fConst166 = (fConst103 * cos((34622.970685229113 / fConst0)));
		fConst167 = (fConst103 * cos((35495.5253900479 / fConst0)));
		fConst168 = (fConst107 * cos((36333.177906583463 / fConst0)));
		fConst169 = (fConst107 * cos((37170.830423181855 / fConst0)));
		fConst170 = (fConst107 * cos((38078.28731615821 / fConst0)));
		fConst171 = (fConst91 * cos((38846.135456315809 / fConst0)));
		fConst172 = (fConst79 * cos((39683.787972914201 / fConst0)));
		fConst173 = pow(0.001, (1.0 / (0.172163197002 * fConst0)));
		fConst174 = (0.0 - (2.0 * fConst173));
		fConst175 = (cos((40242.222984000735 / fConst0)) * fConst174);
		fConst176 = mydsp_faustpower2_f(fConst173);
		fConst177 = (fConst174 * cos((40661.049242268513 / fConst0)));
		fConst178 = pow(0.001, (1.0 / (0.0227463823712 * fConst0)));
		fConst179 = (0.0 - (2.0 * fConst178));
		fConst180 = (cos((41638.310511622833 / fConst0)) * fConst179);
		fConst181 = mydsp_faustpower2_f(fConst178);
		fConst182 = (fConst179 * cos((41812.821452536322 / fConst0)));
		fConst183 = pow(0.001, (1.0 / (0.019816774127199999 * fConst0)));
		fConst184 = (cos((42161.843334488978 / fConst0)) * (0.0 - (2.0 * fConst183)));
		fConst185 = mydsp_faustpower2_f(fConst183);
		fConst186 = pow(0.001, (1.0 / (0.024612612142400001 * fConst0)));
		fConst187 = (0.0 - (2.0 * fConst186));
		fConst188 = (cos((42720.278345512685 / fConst0)) * fConst187);
		fConst189 = mydsp_faustpower2_f(fConst186);
		fConst190 = pow(0.001, (1.0 / (0.086731018433500007 * fConst0)));
		fConst191 = (cos((43453.224297512716 / fConst0)) * (0.0 - (2.0 * fConst190)));
		fConst192 = mydsp_faustpower2_f(fConst190);
		fConst193 = pow(0.001, (1.0 / (0.069498963184800006 * fConst0)));
		fConst194 = (cos((43976.757120378854 / fConst0)) * (0.0 - (2.0 * fConst193)));
		fConst195 = mydsp_faustpower2_f(fConst193);
		fConst196 = pow(0.001, (1.0 / (0.070296900654999994 * fConst0)));
		fConst197 = (cos((44186.170249512747 / fConst0)) * (0.0 - (2.0 * fConst196)));
		fConst198 = mydsp_faustpower2_f(fConst196);
		fConst199 = pow(0.001, (1.0 / (0.025692729937599999 * fConst0)));
		fConst200 = (0.0 - (2.0 * fConst199));
		fConst201 = (cos((44709.703072378885 / fConst0)) * fConst200);
		fConst202 = mydsp_faustpower2_f(fConst199);
		fConst203 = pow(0.001, (1.0 / (0.025964067081099999 * fConst0)));
		fConst204 = (0.0 - (2.0 * fConst203));
		fConst205 = (cos((44919.116201512777 / fConst0)) * fConst204);
		fConst206 = mydsp_faustpower2_f(fConst203);
		fConst207 = (fConst187 * cos((45163.431518867066 / fConst0)));
		fConst208 = pow(0.001, (1.0 / (0.0605636441966 * fConst0)));
		fConst209 = (cos((45617.15996535524 / fConst0)) * (0.0 - (2.0 * fConst208)));
		fConst210 = mydsp_faustpower2_f(fConst208);
		fConst211 = pow(0.001, (1.0 / (0.026129646387100001 * fConst0)));
		fConst212 = (cos((46070.888411843422 / fConst0)) * (0.0 - (2.0 * fConst211)));
		fConst213 = mydsp_faustpower2_f(fConst211);
		fConst214 = pow(0.001, (1.0 / (0.025746541336 * fConst0)));
		fConst215 = (0.0 - (2.0 * fConst214));
		fConst216 = (cos((46454.812481953632 / fConst0)) * fConst215);
		fConst217 = mydsp_faustpower2_f(fConst214);
		fConst218 = pow(0.001, (1.0 / (0.024514475740999998 * fConst0)));
		fConst219 = (0.0 - (2.0 * fConst218));
		fConst220 = (cos((46803.834363843453 / fConst0)) * fConst219);
		fConst221 = mydsp_faustpower2_f(fConst218);
		fConst222 = pow(0.001, (1.0 / (0.0260742184201 * fConst0)));
		fConst223 = (0.0 - (2.0 * fConst222));
		fConst224 = (cos((47222.660622111231 / fConst0)) * fConst223);
		fConst225 = mydsp_faustpower2_f(fConst222);
		fConst226 = pow(0.001, (1.0 / (0.023988456994400002 * fConst0)));
		fConst227 = (cos((47571.68250406388 / fConst0)) * (0.0 - (2.0 * fConst226)));
		fConst228 = mydsp_faustpower2_f(fConst226);
		fConst229 = (fConst215 * cos((48060.313138709622 / fConst0)));
		fConst230 = (fConst187 * cos((48863.063467087617 / fConst0)));
		fConst231 = (fConst200 * cos((49002.672219843545 / fConst0)));
		fConst232 = pow(0.001, (1.0 / (0.022662582530800002 * fConst0)));
		fConst233 = (0.0 - (2.0 * fConst232));
		fConst234 = (cos((49596.009419087648 / fConst0)) * fConst233);
		fConst235 = mydsp_faustpower2_f(fConst232);
		fConst236 = (fConst233 * cos((49665.813795465612 / fConst0)));
		fConst237 = (fConst179 * cos((49945.031301040297 / fConst0)));
		fConst238 = (fConst179 * cos((50084.640053796225 / fConst0)));
		fConst239 = pow(0.001, (1.0 / (0.022704404858300001 * fConst0)));
		fConst240 = (cos((50294.053182930118 / fConst0)) * (0.0 - (2.0 * fConst239)));
		fConst241 = mydsp_faustpower2_f(fConst239);
		fConst242 = (fConst219 * cos((50747.781629418292 / fConst0)));
		fConst243 = pow(0.001, (1.0 / (0.023710972195399999 * fConst0)));
		fConst244 = (0.0 - (2.0 * fConst243));
		fConst245 = (cos((51166.60788768607 / fConst0)) * fConst244);
		fConst246 = mydsp_faustpower2_f(fConst243);
		fConst247 = pow(0.001, (1.0 / (0.0238489048115 * fConst0)));
		fConst248 = (cos((51341.118828662395 / fConst0)) * (0.0 - (2.0 * fConst247)));
		fConst249 = mydsp_faustpower2_f(fConst247);
		fConst250 = (fConst219 * cos((51725.042898709777 / fConst0)));
		fConst251 = pow(0.001, (1.0 / (0.0245634456083 * fConst0)));
		fConst252 = (cos((52597.597603528571 / fConst0)) * (0.0 - (2.0 * fConst251)));
		fConst253 = mydsp_faustpower2_f(fConst251);
		fConst254 = (fConst223 * cos((53086.228238174313 / fConst0)));
		fConst255 = (fConst204 * cos((53644.663249260848 / fConst0)));
		fConst256 = (fConst219 * cos((53923.880754772712 / fConst0)));
		fConst257 = (fConst223 * cos((54517.217954016807 / fConst0)));
		fConst258 = (fConst223 * cos((55005.848588662549 / fConst0)));
		fConst259 = (fConst219 * cos((55354.870470552363 / fConst0)));
		fConst260 = (fConst219 * cos((55599.185787906652 / fConst0)));
		fConst261 = pow(0.001, (1.0 / (0.0240824056841 * fConst0)));
		fConst262 = (0.0 - (2.0 * fConst261));
		fConst263 = (cos((56471.740492662611 / fConst0)) * fConst262);
		fConst264 = mydsp_faustpower2_f(fConst261);
		fConst265 = (fConst244 * cos((56855.664562772836 / fConst0)));
		fConst266 = (fConst262 * cos((57274.490821103442 / fConst0)));
		fConst267 = (fConst219 * cos((57798.023643906745 / fConst0)));
		fConst268 = pow(0.001, (1.0 / (0.023619903008400001 * fConst0)));
		fConst269 = (0.0 - (2.0 * fConst268));
		fConst270 = (cos((58147.045525859394 / fConst0)) * fConst269);
		fConst271 = mydsp_faustpower2_f(fConst268);
		fConst272 = (fConst269 * cos((58496.067407749208 / fConst0)));
		fConst273 = pow(0.001, (1.0 / (0.019259022252200001 * fConst0)));
		fConst274 = (0.0 - (2.0 * fConst273));
		fConst275 = (cos((58914.893666016993 / fConst0)) * fConst274);
		fConst276 = mydsp_faustpower2_f(fConst273);
		fConst277 = (fConst274 * cos((59612.937429859456 / fConst0)));
		fConst278 = pow(0.001, (1.0 / (0.0191393313718 * fConst0)));
		fConst279 = (cos((60380.78557007989 / fConst0)) * (0.0 - (2.0 * fConst278)));
		fConst280 = mydsp_faustpower2_f(fConst278);
		fConst281 = pow(0.001, (1.0 / (0.015331941562699999 * fConst0)));
		fConst282 = (0.0 - (2.0 * fConst281));
		fConst283 = (cos((61183.535898457885 / fConst0)) * fConst282);
		fConst284 = mydsp_faustpower2_f(fConst281);
		fConst285 = (fConst282 * cos((61288.24246299341 / fConst0)));
		fConst286 = pow(0.001, (1.0 / (0.0153701226114 * fConst0)));
		fConst287 = (cos((61602.362156725663 / fConst0)) * (0.0 - (2.0 * fConst286)));
		fConst288 = mydsp_faustpower2_f(fConst286);
		fConst289 = pow(0.001, (1.0 / (0.0169775302929 * fConst0)));
		fConst290 = (cos((62300.405920568126 / fConst0)) * (0.0 - (2.0 * fConst289)));
		fConst291 = mydsp_faustpower2_f(fConst289);
		fConst292 = pow(0.001, (1.0 / (0.0154084952857 * fConst0)));
		fConst293 = (cos((63207.86281323032 / fConst0)) * (0.0 - (2.0 * fConst292)));
		fConst294 = mydsp_faustpower2_f(fConst292);
		fConst295 = (fConst282 * cos((63521.982507088236 / fConst0)));
		fConst296 = pow(0.001, (1.0 / (0.015389284905299999 * fConst0)));
		fConst297 = (cos((64150.221894804061 / fConst0)) * (0.0 - (2.0 * fConst296)));
		fConst298 = mydsp_faustpower2_f(fConst296);
		fConst299 = (fConst282 * cos((64394.537211969866 / fConst0)));
		fConst300 = pow(0.001, (1.0 / (0.015312922449900001 * fConst0)));
		fConst301 = (cos((64952.972222993565 / fConst0)) * (0.0 - (2.0 * fConst300)));
		fConst302 = mydsp_faustpower2_f(fConst300);
		fConst303 = pow(0.001, (1.0 / (0.0151438610824 * fConst0)));
		fConst304 = (cos((65267.091916851481 / fConst0)) * (0.0 - (2.0 * fConst303)));
		fConst305 = mydsp_faustpower2_f(fConst303);
		fConst306 = pow(0.001, (1.0 / (0.015125307825399999 * fConst0)));
		fConst307 = (cos((65406.700669607402 / fConst0)) * (0.0 - (2.0 * fConst306)));
		fConst308 = mydsp_faustpower2_f(fConst306);
		fConst309 = pow(0.001, (1.0 / (0.014888208483099999 * fConst0)));
		fConst310 = (cos((65755.722551183062 / fConst0)) * (0.0 - (2.0 * fConst309)));
		fConst311 = mydsp_faustpower2_f(fConst309);
		fConst312 = pow(0.001, (1.0 / (0.0132303018198 * fConst0)));
		fConst313 = (0.0 - (2.0 * fConst312));
		fConst314 = (cos((66244.353186142966 / fConst0)) * fConst313);
		fConst315 = mydsp_faustpower2_f(fConst312);
		fConst316 = pow(0.001, (1.0 / (0.0132161602651 * fConst0)));
		fConst317 = (0.0 - (2.0 * fConst316));
		fConst318 = (cos((66767.886008820613 / fConst0)) * fConst317);
		fConst319 = mydsp_faustpower2_f(fConst316);
		fConst320 = pow(0.001, (1.0 / (0.22633805133099999 * fConst0)));
		fConst321 = (cos((67151.810079370654 / fConst0)) * (0.0 - (2.0 * fConst320)));
		fConst322 = mydsp_faustpower2_f(fConst320);
		fConst323 = pow(0.001, (1.0 / (0.0136239765034 * fConst0)));
		fConst324 = (cos((67326.321019844312 / fConst0)) * (0.0 - (2.0 * fConst323)));
		fConst325 = mydsp_faustpower2_f(fConst323);
		fConst326 = (fConst313 * cos((67710.245090394368 / fConst0)));
		fConst327 = pow(0.001, (1.0 / (0.235040347058 * fConst0)));
		fConst328 = (cos((67989.46259590621 / fConst0)) * (0.0 - (2.0 * fConst327)));
		fConst329 = mydsp_faustpower2_f(fConst327);
		fConst330 = (fConst317 * cos((68687.506359685853 / fConst0)));
		fConst331 = pow(0.001, (1.0 / (0.0129667140414 * fConst0)));
		fConst332 = (cos((69629.865440631271 / fConst0)) * (0.0 - (2.0 * fConst331)));
		fConst333 = mydsp_faustpower2_f(fConst331);
		fConst334 = pow(0.001, (1.0 / (0.0126874064918 * fConst0)));
		fConst335 = (0.0 - (2.0 * fConst334));
		fConst336 = (cos((69943.985134489194 / fConst0)) * fConst335);
		fConst337 = mydsp_faustpower2_f(fConst334);
		fConst338 = (fConst335 * cos((70013.78951055299 / fConst0)));
		fConst339 = (fConst335 * cos((70537.32233385896 / fConst0)));
		fConst340 = pow(0.001, (1.0 / (0.00571953085919 * fConst0)));
		fConst341 = (cos((70956.148592126745 / fConst0)) * (0.0 - (2.0 * fConst340)));
		fConst342 = mydsp_faustpower2_f(fConst340);
		fConst343 = pow(0.001, (1.0 / (0.0112365405185 * fConst0)));
		fConst344 = (cos((71165.561720946454 / fConst0)) * (0.0 - (2.0 * fConst343)));
		fConst345 = mydsp_faustpower2_f(fConst343);
		fConst346 = pow(0.001, (1.0 / (0.011206054647899999 * fConst0)));
		fConst347 = (cos((71933.409861418215 / fConst0)) * (0.0 - (2.0 * fConst346)));
		fConst348 = mydsp_faustpower2_f(fConst346);
		fConst349 = pow(0.001, (1.0 / (0.0057169279701100003 * fConst0)));
		fConst350 = (0.0 - (2.0 * fConst349));
		fConst351 = (cos((72282.431742993882 / fConst0)) * fConst350);
		fConst352 = mydsp_faustpower2_f(fConst349);
		fConst353 = pow(0.001, (1.0 / (0.011216198077599999 * fConst0)));
		fConst354 = (0.0 - (2.0 * fConst353));
		fConst355 = (cos((72666.355812915586 / fConst0)) * fConst354);
		fConst356 = mydsp_faustpower2_f(fConst353);
		fConst357 = pow(0.001, (1.0 / (0.011226360017600001 * fConst0)));
		fConst358 = (cos((73015.377695119576 / fConst0)) * (0.0 - (2.0 * fConst357)));
		fConst359 = mydsp_faustpower2_f(fConst357);
		fConst360 = pow(0.001, (1.0 / (0.0112569574068 * fConst0)));
		fConst361 = (cos((73713.421458899204 / fConst0)) * (0.0 - (2.0 * fConst360)));
		fConst362 = mydsp_faustpower2_f(fConst360);
		fConst363 = (fConst354 * cos((73992.63896441106 / fConst0)));
		fConst364 = (fConst354 * cos((74481.269599370964 / fConst0)));
		fConst365 = (fConst350 * cos((74865.193669292683 / fConst0)));
		fConst366 = pow(0.001, (1.0 / (0.0057091336976699998 * fConst0)));
		fConst367 = (cos((75004.802422048611 / fConst0)) * (0.0 - (2.0 * fConst366)));
		fConst368 = mydsp_faustpower2_f(fConst366);
		fConst369 = pow(0.001, (1.0 / (0.0056247978495899999 * fConst0)));
		fConst370 = (cos((75528.335244726259 / fConst0)) * (0.0 - (2.0 * fConst369)));
		fConst371 = mydsp_faustpower2_f(fConst369);
		fConst372 = pow(0.001, (1.0 / (0.0055773772681199998 * fConst0)));
		fConst373 = (0.0 - (2.0 * fConst372));
		fConst374 = (cos((76296.183385198019 / fConst0)) * fConst373);
		fConst375 = mydsp_faustpower2_f(fConst372);
		fConst376 = pow(0.001, (1.0 / (0.0055724327644199999 * fConst0)));
		fConst377 = (cos((76645.205266773672 / fConst0)) * (0.0 - (2.0 * fConst376)));
		fConst378 = mydsp_faustpower2_f(fConst376);
		fConst379 = (fConst373 * cos((76924.422772285514 / fConst0)));
		fConst380 = pow(0.001, (1.0 / (0.0055551968187699998 * fConst0)));
		fConst381 = (cos((77378.151218899366 / fConst0)) * (0.0 - (2.0 * fConst380)));
		fConst382 = mydsp_faustpower2_f(fConst380);
		fConst383 = pow(0.001, (1.0 / (0.0055625703898999996 * fConst0)));
		fConst384 = (cos((77692.270912757274 / fConst0)) * (0.0 - (2.0 * fConst383)));
		fConst385 = mydsp_faustpower2_f(fConst383);
		fConst386 = pow(0.001, (1.0 / (0.0054634860441200002 * fConst0)));
		fConst387 = (cos((78495.021240946764 / fConst0)) * (0.0 - (2.0 * fConst386)));
		fConst388 = mydsp_faustpower2_f(fConst386);
		fConst389 = pow(0.001, (1.0 / (0.0054024865646199998 * fConst0)));
		fConst390 = (0.0 - (2.0 * fConst389));
		fConst391 = (cos((78844.043123150754 / fConst0)) * fConst390);
		fConst392 = mydsp_faustpower2_f(fConst389);
		fConst393 = (fConst390 * cos((78948.749687560616 / fConst0)));
		fConst394 = pow(0.001, (1.0 / (0.0054563763861300001 * fConst0)));
		fConst395 = (cos((79193.065004726406 / fConst0)) * (0.0 - (2.0 * fConst394)));
		fConst396 = mydsp_faustpower2_f(fConst394);
		fConst397 = (fConst153 * cos((82753.088200316692 / fConst0)));
		fConst398 = (fConst153 * cos((83625.642905198329 / fConst0)));
		fConst399 = pow(0.001, (1.0 / (0.043099602338600003 * fConst0)));
		fConst400 = (0.0 - (2.0 * fConst399));
		fConst401 = (cos((84498.197610079937 / fConst0)) * fConst400);
		fConst402 = mydsp_faustpower2_f(fConst399);
		fConst403 = pow(0.001, (1.0 / (0.050986816824100001 * fConst0)));
		fConst404 = (0.0 - (2.0 * fConst403));
		fConst405 = (cos((85300.947938269441 / fConst0)) * fConst404);
		fConst406 = mydsp_faustpower2_f(fConst403);
		fConst407 = pow(0.001, (1.0 / (0.0507755786847 * fConst0)));
		fConst408 = (0.0 - (2.0 * fConst407));
		fConst409 = (cos((85370.752314961559 / fConst0)) * fConst408);
		fConst410 = mydsp_faustpower2_f(fConst407);
		fConst411 = pow(0.001, (1.0 / (0.0499478700703 * fConst0)));
		fConst412 = (0.0 - (2.0 * fConst411));
		fConst413 = (cos((85510.361067717487 / fConst0)) * fConst412);
		fConst414 = mydsp_faustpower2_f(fConst411);
		fConst415 = (fConst400 * cos((85649.969820473416 / fConst0)));
		fConst416 = pow(0.001, (1.0 / (0.044833055848999999 * fConst0)));
		fConst417 = (0.0 - (2.0 * fConst416));
		fConst418 = (cos((85789.578573229344 / fConst0)) * fConst417);
		fConst419 = mydsp_faustpower2_f(fConst416);
		fConst420 = pow(0.001, (1.0 / (0.067210373342000002 * fConst0)));
		fConst421 = (0.0 - (2.0 * fConst420));
		fConst422 = (cos((86313.111395906992 / fConst0)) * fConst421);
		fConst423 = mydsp_faustpower2_f(fConst420);
		fConst424 = pow(0.001, (1.0 / (0.051414618438500002 * fConst0)));
		fConst425 = (0.0 - (2.0 * fConst424));
		fConst426 = (cos((86557.426713072782 / fConst0)) * fConst425);
		fConst427 = mydsp_faustpower2_f(fConst424);
		fConst428 = (fConst421 * cos((86941.350782994501 / fConst0)));
		fConst429 = (fConst421 * cos((87046.057348032686 / fConst0)));
		fConst430 = (fConst421 * cos((87150.763912442548 / fConst0)));
		fConst431 = pow(0.001, (1.0 / (0.063713916777299998 * fConst0)));
		fConst432 = (0.0 - (2.0 * fConst431));
		fConst433 = (cos((87325.274853544543 / fConst0)) * fConst432);
		fConst434 = mydsp_faustpower2_f(fConst431);
		fConst435 = (fConst421 * cos((87429.981417954405 / fConst0)));
		fConst436 = pow(0.001, (1.0 / (0.066843531989300001 * fConst0)));
		fConst437 = (0.0 - (2.0 * fConst436));
		fConst438 = (cos((87499.7857940182 / fConst0)) * fConst437);
		fConst439 = mydsp_faustpower2_f(fConst436);
		fConst440 = (fConst432 * cos((87569.590170710333 / fConst0)));
		fConst441 = pow(0.001, (1.0 / (0.052292160228700001 * fConst0)));
		fConst442 = (0.0 - (2.0 * fConst441));
		fConst443 = (cos((87674.296735120195 / fConst0)) * fConst442);
		fConst444 = mydsp_faustpower2_f(fConst441);
		fConst445 = (fConst421 * cos((87918.612052285986 / fConst0)));
		fConst446 = pow(0.001, (1.0 / (0.075035572403900005 * fConst0)));
		fConst447 = (0.0 - (2.0 * fConst446));
		fConst448 = (cos((88023.31861732417 / fConst0)) * fConst447);
		fConst449 = mydsp_faustpower2_f(fConst446);
		fConst450 = pow(0.001, (1.0 / (0.076441019409699995 * fConst0)));
		fConst451 = (0.0 - (2.0 * fConst450));
		fConst452 = (cos((88093.12299338798 / fConst0)) * fConst451);
		fConst453 = mydsp_faustpower2_f(fConst450);
		fConst454 = (fConst451 * cos((88162.927370080099 / fConst0)));
		fConst455 = (fConst451 * cos((88232.731746143894 / fConst0)));
		fConst456 = pow(0.001, (1.0 / (0.107254010001 * fConst0)));
		fConst457 = (cos((88860.971133859741 / fConst0)) * (0.0 - (2.0 * fConst456)));
		fConst458 = mydsp_faustpower2_f(fConst456);
		fConst459 = (fConst447 * cos((89070.38426267945 / fConst0)));
		fConst460 = (fConst437 * cos((89244.895203781445 / fConst0)));
		fConst461 = (fConst437 * cos((89349.601768191307 / fConst0)));
		fConst462 = (fConst451 * cos((89593.91708598542 / fConst0)));
		fConst463 = (fConst432 * cos((89768.428026459093 / fConst0)));
		fConst464 = (fConst425 * cos((90117.449908663068 / fConst0)));
		fConst465 = (fConst442 * cos((90291.960849765048 / fConst0)));
		fConst466 = (fConst425 * cos((90361.765225828858 / fConst0)));
		fConst467 = (fConst408 * cos((90571.178355276905 / fConst0)));
		fConst468 = pow(0.001, (1.0 / (0.0505660863164 * fConst0)));
		fConst469 = (cos((90640.982731340715 / fConst0)) * (0.0 - (2.0 * fConst468)));
		fConst470 = mydsp_faustpower2_f(fConst468);
		fConst471 = (fConst412 * cos((90780.591484096643 / fConst0)));
		fConst472 = (fConst412 * cos((91059.808989608486 / fConst0)));
		fConst473 = (fConst404 * cos((91129.613366300619 / fConst0)));
		fConst474 = (fConst417 * cos((91339.026495120343 / fConst0)));
		fConst475 = (fConst400 * cos((91408.830871812475 / fConst0)));
		fConst476 = (fConst400 * cos((91548.439624568389 / fConst0)));
		fConst477 = pow(0.001, (1.0 / (0.0429486508916 * fConst0)));
		fConst478 = (0.0 - (2.0 * fConst477));
		fConst479 = (cos((91653.146188978266 / fConst0)) * fConst478);
		fConst480 = mydsp_faustpower2_f(fConst477);
		fConst481 = (fConst478 * cos((91862.559318426313 / fConst0)));
		fConst482 = (fConst400 * cos((91932.363694490123 / fConst0)));
		fConst483 = (fConst478 * cos((92037.070258899985 / fConst0)));
		fConst484 = (fConst478 * cos((92141.776823938169 / fConst0)));
		fConst485 = (fConst400 * cos((92211.58120000198 / fConst0)));
		fConst486 = (fConst478 * cos((92386.09214110396 / fConst0)));
		fConst487 = (fConst400 * cos((92525.700893859888 / fConst0)));
		fConst488 = (fConst400 * cos((92665.309646615817 / fConst0)));
		fConst489 = (fConst400 * cos((92770.016211025679 / fConst0)));
		fConst490 = (fConst400 * cos((92909.624963781607 / fConst0)));
		fConst491 = (fConst400 * cos((93014.331528191469 / fConst0)));
		fConst492 = (fConst400 * cos((93084.135904883588 / fConst0)));
		fConst493 = pow(0.001, (1.0 / (0.042798755050300001 * fConst0)));
		fConst494 = (cos((93188.842469293464 / fConst0)) * (0.0 - (2.0 * fConst493)));
		fConst495 = mydsp_faustpower2_f(fConst493);
		fConst496 = pow(0.001, (1.0 / (0.042649903780500001 * fConst0)));
		fConst497 = (cos((93258.646845985582 / fConst0)) * (0.0 - (2.0 * fConst496)));
		fConst498 = mydsp_faustpower2_f(fConst496);
		fConst499 = pow(0.001, (1.0 / (0.042502086201299999 * fConst0)));
		fConst500 = (cos((93363.353410395444 / fConst0)) * (0.0 - (2.0 * fConst499)));
		fConst501 = mydsp_faustpower2_f(fConst499);
		fConst502 = pow(0.001, (1.0 / (0.0391136164816 * fConst0)));
		fConst503 = (0.0 - (2.0 * fConst502));
		fConst504 = (cos((93468.059974805306 / fConst0)) * fConst503);
		fConst505 = mydsp_faustpower2_f(fConst502);
		fConst506 = (fConst503 * cos((93572.766539215168 / fConst0)));
		fConst507 = pow(0.001, (1.0 / (0.034111896907999997 * fConst0)));
		fConst508 = (0.0 - (2.0 * fConst507));
		fConst509 = (cos((93677.473104253368 / fConst0)) * fConst508);
		fConst510 = mydsp_faustpower2_f(fConst507);
		fConst511 = (fConst503 * cos((93782.17966866323 / fConst0)));
		fConst512 = (fConst508 * cos((93886.886233073092 / fConst0)));
		fConst513 = pow(0.001, (1.0 / (0.073680924705600004 * fConst0)));
		fConst514 = (0.0 - (2.0 * fConst513));
		fConst515 = (cos((96748.86566488375 / fConst0)) * fConst514);
		fConst516 = mydsp_faustpower2_f(fConst513);
		fConst517 = pow(0.001, (1.0 / (0.083763462758800006 * fConst0)));
		fConst518 = (0.0 - (2.0 * fConst517));
		fConst519 = (cos((96818.670040947545 / fConst0)) * fConst518);
		fConst520 = mydsp_faustpower2_f(fConst517);
		fConst521 = (fConst518 * cos((96958.278793703488 / fConst0)));
		fConst522 = pow(0.001, (1.0 / (0.072374371026199993 * fConst0)));
		fConst523 = (0.0 - (2.0 * fConst522));
		fConst524 = (cos((97097.887546459402 / fConst0)) * fConst523);
		fConst525 = mydsp_faustpower2_f(fConst522);
		fConst526 = pow(0.001, (1.0 / (0.071949100616900005 * fConst0)));
		fConst527 = (0.0 - (2.0 * fConst526));
		fConst528 = (cos((97167.691923151535 / fConst0)) * fConst527);
		fConst529 = mydsp_faustpower2_f(fConst526);
		fConst530 = (fConst523 * cos((97551.615993073239 / fConst0)));
		fConst531 = (fConst523 * cos((97621.420369765357 / fConst0)));
		fConst532 = pow(0.001, (1.0 / (0.071113394818299994 * fConst0)));
		fConst533 = (0.0 - (2.0 * fConst532));
		fConst534 = (cos((97795.931310867352 / fConst0)) * fConst533);
		fConst535 = mydsp_faustpower2_f(fConst532);
		fConst536 = (fConst533 * cos((98144.953192443005 / fConst0)));
		fConst537 = (fConst523 * cos((98214.757569135138 / fConst0)));
		fConst538 = (fConst523 * cos((98354.366321891066 / fConst0)));
		fConst539 = (fConst523 * cos((98493.975074646994 / fConst0)));
		fConst540 = (fConst523 * cos((98563.77945071079 / fConst0)));
		fConst541 = (fConst514 * cos((98703.388203466733 / fConst0)));
		fConst542 = (fConst523 * cos((98808.094767876581 / fConst0)));
		fConst543 = (fConst523 * cos((98912.801332914765 / fConst0)));
		fConst544 = (fConst523 * cos((99017.507897324642 / fConst0)));
		fConst545 = pow(0.001, (1.0 / (0.084925755391100005 * fConst0)));
		fConst546 = (0.0 - (2.0 * fConst545));
		fConst547 = (cos((99087.312273388437 / fConst0)) * fConst546);
		fConst548 = mydsp_faustpower2_f(fConst545);
		fConst549 = (fConst546 * cos((99226.921026144366 / fConst0)));
		fConst550 = (fConst546 * cos((99366.529778900294 / fConst0)));
		fConst551 = (fConst514 * cos((99436.334155592413 / fConst0)));
		fConst552 = (fConst523 * cos((99541.040720002289 / fConst0)));
		fConst553 = (fConst518 * cos((99610.845096694393 / fConst0)));
		fConst554 = (fConst523 * cos((99680.649472758203 / fConst0)));
		fConst555 = (fConst514 * cos((99855.160413860198 / fConst0)));
		fConst556 = (fConst523 * cos((99924.964789923994 / fConst0)));
		fConst557 = (fConst523 * cos((99994.769166616126 / fConst0)));
		fConst558 = (fConst546 * cos((100169.28010771811 / fConst0)));
		fConst559 = (fConst518 * cos((100239.08448378192 / fConst0)));
		fConst560 = (fConst523 * cos((100308.88886047404 / fConst0)));
		fConst561 = (fConst514 * cos((100413.5954248839 / fConst0)));
		fConst562 = (fConst527 * cos((100623.00855433194 / fConst0)));
		fConst563 = (fConst527 * cos((100762.61730708789 / fConst0)));
		fConst564 = (fConst514 * cos((100832.42168315168 / fConst0)));
		
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
		ui_interface->openVerticalBox("cabinetFenderBlackfaceTreble");
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
			fRec1[0] = (fTemp1 - ((fConst7 * fRec1[1]) + (fConst8 * fRec1[2])));
			fRec2[0] = (fTemp1 - ((fConst11 * fRec2[1]) + (fConst12 * fRec2[2])));
			fRec3[0] = (fTemp1 - ((fConst13 * fRec3[1]) + (fConst8 * fRec3[2])));
			fRec4[0] = (fTemp1 - ((fConst15 * fRec4[1]) + (fConst16 * fRec4[2])));
			fRec5[0] = (fTemp1 - ((fConst19 * fRec5[1]) + (fConst20 * fRec5[2])));
			fRec6[0] = (fTemp1 - ((fConst21 * fRec6[1]) + (fConst20 * fRec6[2])));
			fRec7[0] = (fTemp1 - ((fConst24 * fRec7[1]) + (fConst25 * fRec7[2])));
			fRec8[0] = (fTemp1 - ((fConst26 * fRec8[1]) + (fConst20 * fRec8[2])));
			fRec9[0] = (fTemp1 - ((fConst28 * fRec9[1]) + (fConst29 * fRec9[2])));
			fRec10[0] = (fTemp1 - ((fConst30 * fRec10[1]) + (fConst12 * fRec10[2])));
			fRec11[0] = (fTemp1 - ((fConst33 * fRec11[1]) + (fConst34 * fRec11[2])));
			fRec12[0] = (fTemp1 - ((fConst35 * fRec12[1]) + (fConst34 * fRec12[2])));
			fRec13[0] = (fTemp1 - ((fConst38 * fRec13[1]) + (fConst39 * fRec13[2])));
			fRec14[0] = (fTemp1 - ((fConst41 * fRec14[1]) + (fConst42 * fRec14[2])));
			fRec15[0] = (fTemp1 - ((fConst45 * fRec15[1]) + (fConst46 * fRec15[2])));
			fRec16[0] = (fTemp1 - ((fConst49 * fRec16[1]) + (fConst50 * fRec16[2])));
			fRec17[0] = (fTemp1 - ((fConst51 * fRec17[1]) + (fConst34 * fRec17[2])));
			fRec18[0] = (fTemp1 - ((fConst52 * fRec18[1]) + (fConst39 * fRec18[2])));
			fRec19[0] = (fTemp1 - ((fConst53 * fRec19[1]) + (fConst39 * fRec19[2])));
			fRec20[0] = (fTemp1 - ((fConst55 * fRec20[1]) + (fConst56 * fRec20[2])));
			fRec21[0] = (fTemp1 - ((fConst57 * fRec21[1]) + (fConst46 * fRec21[2])));
			fRec22[0] = (fTemp1 - ((fConst59 * fRec22[1]) + (fConst60 * fRec22[2])));
			fRec23[0] = (fTemp1 - ((fConst63 * fRec23[1]) + (fConst64 * fRec23[2])));
			fRec24[0] = (fTemp1 - ((fConst66 * fRec24[1]) + (fConst67 * fRec24[2])));
			fRec25[0] = (fTemp1 - ((fConst68 * fRec25[1]) + (fConst64 * fRec25[2])));
			fRec26[0] = (fTemp1 - ((fConst69 * fRec26[1]) + (fConst64 * fRec26[2])));
			fRec27[0] = (fTemp1 - ((fConst71 * fRec27[1]) + (fConst72 * fRec27[2])));
			fRec28[0] = (fTemp1 - ((fConst75 * fRec28[1]) + (fConst76 * fRec28[2])));
			fRec29[0] = (fTemp1 - ((fConst77 * fRec29[1]) + (fConst76 * fRec29[2])));
			fRec30[0] = (fTemp1 - ((fConst80 * fRec30[1]) + (fConst81 * fRec30[2])));
			fRec31[0] = (fTemp1 - ((fConst83 * fRec31[1]) + (fConst84 * fRec31[2])));
			fRec32[0] = (fTemp1 - ((fConst85 * fRec32[1]) + (fConst4 * fRec32[2])));
			fRec33[0] = (fTemp1 - ((fConst86 * fRec33[1]) + (fConst4 * fRec33[2])));
			fRec34[0] = (fTemp1 - ((fConst88 * fRec34[1]) + (fConst89 * fRec34[2])));
			fRec35[0] = (fTemp1 - ((fConst92 * fRec35[1]) + (fConst93 * fRec35[2])));
			fRec36[0] = (fTemp1 - ((fConst95 * fRec36[1]) + (fConst96 * fRec36[2])));
			fRec37[0] = (fTemp1 - ((fConst98 * fRec37[1]) + (fConst99 * fRec37[2])));
			fRec38[0] = (fTemp1 - ((fConst100 * fRec38[1]) + (fConst4 * fRec38[2])));
			fRec39[0] = (fTemp1 - ((fConst101 * fRec39[1]) + (fConst76 * fRec39[2])));
			fRec40[0] = (fTemp1 - ((fConst104 * fRec40[1]) + (fConst105 * fRec40[2])));
			fRec41[0] = (fTemp1 - ((fConst108 * fRec41[1]) + (fConst109 * fRec41[2])));
			fRec42[0] = (fTemp1 - ((fConst110 * fRec42[1]) + (fConst105 * fRec42[2])));
			fRec43[0] = (fTemp1 - ((fConst111 * fRec43[1]) + (fConst93 * fRec43[2])));
			fRec44[0] = (fTemp1 - ((fConst112 * fRec44[1]) + (fConst81 * fRec44[2])));
			fRec45[0] = (fTemp1 - ((fConst113 * fRec45[1]) + (fConst93 * fRec45[2])));
			fRec46[0] = (fTemp1 - ((fConst115 * fRec46[1]) + (fConst116 * fRec46[2])));
			fRec47[0] = (fTemp1 - ((fConst119 * fRec47[1]) + (fConst120 * fRec47[2])));
			fRec48[0] = (fTemp1 - ((fConst121 * fRec48[1]) + (fConst120 * fRec48[2])));
			fRec49[0] = (fTemp1 - ((fConst123 * fRec49[1]) + (fConst124 * fRec49[2])));
			fRec50[0] = (fTemp1 - ((fConst126 * fRec50[1]) + (fConst127 * fRec50[2])));
			fRec51[0] = (fTemp1 - ((fConst129 * fRec51[1]) + (fConst130 * fRec51[2])));
			fRec52[0] = (fTemp1 - ((fConst131 * fRec52[1]) + (fConst50 * fRec52[2])));
			fRec53[0] = (fTemp1 - ((fConst132 * fRec53[1]) + (fConst50 * fRec53[2])));
			fRec54[0] = (fTemp1 - ((fConst134 * fRec54[1]) + (fConst135 * fRec54[2])));
			fRec55[0] = (fTemp1 - ((fConst137 * fRec55[1]) + (fConst138 * fRec55[2])));
			fRec56[0] = (fTemp1 - ((fConst140 * fRec56[1]) + (fConst141 * fRec56[2])));
			fRec57[0] = (fTemp1 - ((fConst144 * fRec57[1]) + (fConst145 * fRec57[2])));
			fRec58[0] = (fTemp1 - ((fConst146 * fRec58[1]) + (fConst20 * fRec58[2])));
			fRec59[0] = (fTemp1 - ((fConst147 * fRec59[1]) + (fConst25 * fRec59[2])));
			fRec60[0] = (fTemp1 - ((fConst149 * fRec60[1]) + (fConst150 * fRec60[2])));
			fRec61[0] = (fTemp1 - ((fConst151 * fRec61[1]) + (fConst145 * fRec61[2])));
			fRec62[0] = (fTemp1 - ((fConst154 * fRec62[1]) + (fConst155 * fRec62[2])));
			fRec63[0] = (fTemp1 - ((fConst156 * fRec63[1]) + (fConst155 * fRec63[2])));
			fRec64[0] = (fTemp1 - ((fConst157 * fRec64[1]) + (fConst155 * fRec64[2])));
			fRec65[0] = (fTemp1 - ((fConst158 * fRec65[1]) + (fConst105 * fRec65[2])));
			fRec66[0] = (fTemp1 - ((fConst159 * fRec66[1]) + (fConst105 * fRec66[2])));
			fRec67[0] = (fTemp1 - ((fConst161 * fRec67[1]) + (fConst162 * fRec67[2])));
			fRec68[0] = (fTemp1 - ((fConst163 * fRec68[1]) + (fConst12 * fRec68[2])));
			fRec69[0] = (fTemp1 - ((fConst164 * fRec69[1]) + (fConst105 * fRec69[2])));
			fRec70[0] = (fTemp1 - ((fConst165 * fRec70[1]) + (fConst105 * fRec70[2])));
			fRec71[0] = (fTemp1 - ((fConst166 * fRec71[1]) + (fConst105 * fRec71[2])));
			fRec72[0] = (fTemp1 - ((fConst167 * fRec72[1]) + (fConst105 * fRec72[2])));
			fRec73[0] = (fTemp1 - ((fConst168 * fRec73[1]) + (fConst109 * fRec73[2])));
			fRec74[0] = (fTemp1 - ((fConst169 * fRec74[1]) + (fConst109 * fRec74[2])));
			fRec75[0] = (fTemp1 - ((fConst170 * fRec75[1]) + (fConst109 * fRec75[2])));
			fRec76[0] = (fTemp1 - ((fConst171 * fRec76[1]) + (fConst93 * fRec76[2])));
			fRec77[0] = (fTemp1 - ((fConst172 * fRec77[1]) + (fConst81 * fRec77[2])));
			fRec78[0] = (fTemp1 - ((fConst175 * fRec78[1]) + (fConst176 * fRec78[2])));
			fRec79[0] = (fTemp1 - ((fConst177 * fRec79[1]) + (fConst176 * fRec79[2])));
			fRec80[0] = (fTemp1 - ((fConst180 * fRec80[1]) + (fConst181 * fRec80[2])));
			fRec81[0] = (fTemp1 - ((fConst182 * fRec81[1]) + (fConst181 * fRec81[2])));
			fRec82[0] = (fTemp1 - ((fConst184 * fRec82[1]) + (fConst185 * fRec82[2])));
			fRec83[0] = (fTemp1 - ((fConst188 * fRec83[1]) + (fConst189 * fRec83[2])));
			fRec84[0] = (fTemp1 - ((fConst191 * fRec84[1]) + (fConst192 * fRec84[2])));
			fRec85[0] = (fTemp1 - ((fConst194 * fRec85[1]) + (fConst195 * fRec85[2])));
			fRec86[0] = (fTemp1 - ((fConst197 * fRec86[1]) + (fConst198 * fRec86[2])));
			fRec87[0] = (fTemp1 - ((fConst201 * fRec87[1]) + (fConst202 * fRec87[2])));
			fRec88[0] = (fTemp1 - ((fConst205 * fRec88[1]) + (fConst206 * fRec88[2])));
			fRec89[0] = (fTemp1 - ((fConst207 * fRec89[1]) + (fConst189 * fRec89[2])));
			fRec90[0] = (fTemp1 - ((fConst209 * fRec90[1]) + (fConst210 * fRec90[2])));
			fRec91[0] = (fTemp1 - ((fConst212 * fRec91[1]) + (fConst213 * fRec91[2])));
			fRec92[0] = (fTemp1 - ((fConst216 * fRec92[1]) + (fConst217 * fRec92[2])));
			fRec93[0] = (fTemp1 - ((fConst220 * fRec93[1]) + (fConst221 * fRec93[2])));
			fRec94[0] = (fTemp1 - ((fConst224 * fRec94[1]) + (fConst225 * fRec94[2])));
			fRec95[0] = (fTemp1 - ((fConst227 * fRec95[1]) + (fConst228 * fRec95[2])));
			fRec96[0] = (fTemp1 - ((fConst229 * fRec96[1]) + (fConst217 * fRec96[2])));
			fRec97[0] = (fTemp1 - ((fConst230 * fRec97[1]) + (fConst189 * fRec97[2])));
			fRec98[0] = (fTemp1 - ((fConst231 * fRec98[1]) + (fConst202 * fRec98[2])));
			fRec99[0] = (fTemp1 - ((fConst234 * fRec99[1]) + (fConst235 * fRec99[2])));
			fRec100[0] = (fTemp1 - ((fConst236 * fRec100[1]) + (fConst235 * fRec100[2])));
			fRec101[0] = (fTemp1 - ((fConst237 * fRec101[1]) + (fConst181 * fRec101[2])));
			fRec102[0] = (fTemp1 - ((fConst238 * fRec102[1]) + (fConst181 * fRec102[2])));
			fRec103[0] = (fTemp1 - ((fConst240 * fRec103[1]) + (fConst241 * fRec103[2])));
			fRec104[0] = (fTemp1 - ((fConst242 * fRec104[1]) + (fConst221 * fRec104[2])));
			fRec105[0] = (fTemp1 - ((fConst245 * fRec105[1]) + (fConst246 * fRec105[2])));
			fRec106[0] = (fTemp1 - ((fConst248 * fRec106[1]) + (fConst249 * fRec106[2])));
			fRec107[0] = (fTemp1 - ((fConst250 * fRec107[1]) + (fConst221 * fRec107[2])));
			fRec108[0] = (fTemp1 - ((fConst252 * fRec108[1]) + (fConst253 * fRec108[2])));
			fRec109[0] = (fTemp1 - ((fConst254 * fRec109[1]) + (fConst225 * fRec109[2])));
			fRec110[0] = (fTemp1 - ((fConst255 * fRec110[1]) + (fConst206 * fRec110[2])));
			fRec111[0] = (fTemp1 - ((fConst256 * fRec111[1]) + (fConst221 * fRec111[2])));
			fRec112[0] = (fTemp1 - ((fConst257 * fRec112[1]) + (fConst225 * fRec112[2])));
			fRec113[0] = (fTemp1 - ((fConst258 * fRec113[1]) + (fConst225 * fRec113[2])));
			fRec114[0] = (fTemp1 - ((fConst259 * fRec114[1]) + (fConst221 * fRec114[2])));
			fRec115[0] = (fTemp1 - ((fConst260 * fRec115[1]) + (fConst221 * fRec115[2])));
			fRec116[0] = (fTemp1 - ((fConst263 * fRec116[1]) + (fConst264 * fRec116[2])));
			fRec117[0] = (fTemp1 - ((fConst265 * fRec117[1]) + (fConst246 * fRec117[2])));
			fRec118[0] = (fTemp1 - ((fConst266 * fRec118[1]) + (fConst264 * fRec118[2])));
			fRec119[0] = (fTemp1 - ((fConst267 * fRec119[1]) + (fConst221 * fRec119[2])));
			fRec120[0] = (fTemp1 - ((fConst270 * fRec120[1]) + (fConst271 * fRec120[2])));
			fRec121[0] = (fTemp1 - ((fConst272 * fRec121[1]) + (fConst271 * fRec121[2])));
			fRec122[0] = (fTemp1 - ((fConst275 * fRec122[1]) + (fConst276 * fRec122[2])));
			fRec123[0] = (fTemp1 - ((fConst277 * fRec123[1]) + (fConst276 * fRec123[2])));
			fRec124[0] = (fTemp1 - ((fConst279 * fRec124[1]) + (fConst280 * fRec124[2])));
			fRec125[0] = (fTemp1 - ((fConst283 * fRec125[1]) + (fConst284 * fRec125[2])));
			fRec126[0] = (fTemp1 - ((fConst285 * fRec126[1]) + (fConst284 * fRec126[2])));
			fRec127[0] = (fTemp1 - ((fConst287 * fRec127[1]) + (fConst288 * fRec127[2])));
			fRec128[0] = (fTemp1 - ((fConst290 * fRec128[1]) + (fConst291 * fRec128[2])));
			fRec129[0] = (fTemp1 - ((fConst293 * fRec129[1]) + (fConst294 * fRec129[2])));
			fRec130[0] = (fTemp1 - ((fConst295 * fRec130[1]) + (fConst284 * fRec130[2])));
			fRec131[0] = (fTemp1 - ((fConst297 * fRec131[1]) + (fConst298 * fRec131[2])));
			fRec132[0] = (fTemp1 - ((fConst299 * fRec132[1]) + (fConst284 * fRec132[2])));
			fRec133[0] = (fTemp1 - ((fConst301 * fRec133[1]) + (fConst302 * fRec133[2])));
			fRec134[0] = (fTemp1 - ((fConst304 * fRec134[1]) + (fConst305 * fRec134[2])));
			fRec135[0] = (fTemp1 - ((fConst307 * fRec135[1]) + (fConst308 * fRec135[2])));
			fRec136[0] = (fTemp1 - ((fConst310 * fRec136[1]) + (fConst311 * fRec136[2])));
			fRec137[0] = (fTemp1 - ((fConst314 * fRec137[1]) + (fConst315 * fRec137[2])));
			fRec138[0] = (fTemp1 - ((fConst318 * fRec138[1]) + (fConst319 * fRec138[2])));
			fRec139[0] = (fTemp1 - ((fConst321 * fRec139[1]) + (fConst322 * fRec139[2])));
			fRec140[0] = (fTemp1 - ((fConst324 * fRec140[1]) + (fConst325 * fRec140[2])));
			fRec141[0] = (fTemp1 - ((fConst326 * fRec141[1]) + (fConst315 * fRec141[2])));
			fRec142[0] = (fTemp1 - ((fConst328 * fRec142[1]) + (fConst329 * fRec142[2])));
			fRec143[0] = (fTemp1 - ((fConst330 * fRec143[1]) + (fConst319 * fRec143[2])));
			fRec144[0] = (fTemp1 - ((fConst332 * fRec144[1]) + (fConst333 * fRec144[2])));
			fRec145[0] = (fTemp1 - ((fConst336 * fRec145[1]) + (fConst337 * fRec145[2])));
			fRec146[0] = (fTemp1 - ((fConst338 * fRec146[1]) + (fConst337 * fRec146[2])));
			fRec147[0] = (fTemp1 - ((fConst339 * fRec147[1]) + (fConst337 * fRec147[2])));
			fRec148[0] = (fTemp1 - ((fConst341 * fRec148[1]) + (fConst342 * fRec148[2])));
			fRec149[0] = (fTemp1 - ((fConst344 * fRec149[1]) + (fConst345 * fRec149[2])));
			fRec150[0] = (fTemp1 - ((fConst347 * fRec150[1]) + (fConst348 * fRec150[2])));
			fRec151[0] = (fTemp1 - ((fConst351 * fRec151[1]) + (fConst352 * fRec151[2])));
			fRec152[0] = (fTemp1 - ((fConst355 * fRec152[1]) + (fConst356 * fRec152[2])));
			fRec153[0] = (fTemp1 - ((fConst358 * fRec153[1]) + (fConst359 * fRec153[2])));
			fRec154[0] = (fTemp1 - ((fConst361 * fRec154[1]) + (fConst362 * fRec154[2])));
			fRec155[0] = (fTemp1 - ((fConst363 * fRec155[1]) + (fConst356 * fRec155[2])));
			fRec156[0] = (fTemp1 - ((fConst364 * fRec156[1]) + (fConst356 * fRec156[2])));
			fRec157[0] = (fTemp1 - ((fConst365 * fRec157[1]) + (fConst352 * fRec157[2])));
			fRec158[0] = (fTemp1 - ((fConst367 * fRec158[1]) + (fConst368 * fRec158[2])));
			fRec159[0] = (fTemp1 - ((fConst370 * fRec159[1]) + (fConst371 * fRec159[2])));
			fRec160[0] = (fTemp1 - ((fConst374 * fRec160[1]) + (fConst375 * fRec160[2])));
			fRec161[0] = (fTemp1 - ((fConst377 * fRec161[1]) + (fConst378 * fRec161[2])));
			fRec162[0] = (fTemp1 - ((fConst379 * fRec162[1]) + (fConst375 * fRec162[2])));
			fRec163[0] = (fTemp1 - ((fConst381 * fRec163[1]) + (fConst382 * fRec163[2])));
			fRec164[0] = (fTemp1 - ((fConst384 * fRec164[1]) + (fConst385 * fRec164[2])));
			fRec165[0] = (fTemp1 - ((fConst387 * fRec165[1]) + (fConst388 * fRec165[2])));
			fRec166[0] = (fTemp1 - ((fConst391 * fRec166[1]) + (fConst392 * fRec166[2])));
			fRec167[0] = (fTemp1 - ((fConst393 * fRec167[1]) + (fConst392 * fRec167[2])));
			fRec168[0] = (fTemp1 - ((fConst395 * fRec168[1]) + (fConst396 * fRec168[2])));
			fRec169[0] = (fTemp1 - ((fConst397 * fRec169[1]) + (fConst155 * fRec169[2])));
			fRec170[0] = (fTemp1 - ((fConst398 * fRec170[1]) + (fConst155 * fRec170[2])));
			fRec171[0] = (fTemp1 - ((fConst401 * fRec171[1]) + (fConst402 * fRec171[2])));
			fRec172[0] = (fTemp1 - ((fConst405 * fRec172[1]) + (fConst406 * fRec172[2])));
			fRec173[0] = (fTemp1 - ((fConst409 * fRec173[1]) + (fConst410 * fRec173[2])));
			fRec174[0] = (fTemp1 - ((fConst413 * fRec174[1]) + (fConst414 * fRec174[2])));
			fRec175[0] = (fTemp1 - ((fConst415 * fRec175[1]) + (fConst402 * fRec175[2])));
			fRec176[0] = (fTemp1 - ((fConst418 * fRec176[1]) + (fConst419 * fRec176[2])));
			fRec177[0] = (fTemp1 - ((fConst422 * fRec177[1]) + (fConst423 * fRec177[2])));
			fRec178[0] = (fTemp1 - ((fConst426 * fRec178[1]) + (fConst427 * fRec178[2])));
			fRec179[0] = (fTemp1 - ((fConst428 * fRec179[1]) + (fConst423 * fRec179[2])));
			fRec180[0] = (fTemp1 - ((fConst429 * fRec180[1]) + (fConst423 * fRec180[2])));
			fRec181[0] = (fTemp1 - ((fConst430 * fRec181[1]) + (fConst423 * fRec181[2])));
			fRec182[0] = (fTemp1 - ((fConst433 * fRec182[1]) + (fConst434 * fRec182[2])));
			fRec183[0] = (fTemp1 - ((fConst435 * fRec183[1]) + (fConst423 * fRec183[2])));
			fRec184[0] = (fTemp1 - ((fConst438 * fRec184[1]) + (fConst439 * fRec184[2])));
			fRec185[0] = (fTemp1 - ((fConst440 * fRec185[1]) + (fConst434 * fRec185[2])));
			fRec186[0] = (fTemp1 - ((fConst443 * fRec186[1]) + (fConst444 * fRec186[2])));
			fRec187[0] = (fTemp1 - ((fConst445 * fRec187[1]) + (fConst423 * fRec187[2])));
			fRec188[0] = (fTemp1 - ((fConst448 * fRec188[1]) + (fConst449 * fRec188[2])));
			fRec189[0] = (fTemp1 - ((fConst452 * fRec189[1]) + (fConst453 * fRec189[2])));
			fRec190[0] = (fTemp1 - ((fConst454 * fRec190[1]) + (fConst453 * fRec190[2])));
			fRec191[0] = (fTemp1 - ((fConst455 * fRec191[1]) + (fConst453 * fRec191[2])));
			fRec192[0] = (fTemp1 - ((fConst457 * fRec192[1]) + (fConst458 * fRec192[2])));
			fRec193[0] = (fTemp1 - ((fConst459 * fRec193[1]) + (fConst449 * fRec193[2])));
			fRec194[0] = (fTemp1 - ((fConst460 * fRec194[1]) + (fConst439 * fRec194[2])));
			fRec195[0] = (fTemp1 - ((fConst461 * fRec195[1]) + (fConst439 * fRec195[2])));
			fRec196[0] = (fTemp1 - ((fConst462 * fRec196[1]) + (fConst453 * fRec196[2])));
			fRec197[0] = (fTemp1 - ((fConst463 * fRec197[1]) + (fConst434 * fRec197[2])));
			fRec198[0] = (fTemp1 - ((fConst464 * fRec198[1]) + (fConst427 * fRec198[2])));
			fRec199[0] = (fTemp1 - ((fConst465 * fRec199[1]) + (fConst444 * fRec199[2])));
			fRec200[0] = (fTemp1 - ((fConst466 * fRec200[1]) + (fConst427 * fRec200[2])));
			fRec201[0] = (fTemp1 - ((fConst467 * fRec201[1]) + (fConst410 * fRec201[2])));
			fRec202[0] = (fTemp1 - ((fConst469 * fRec202[1]) + (fConst470 * fRec202[2])));
			fRec203[0] = (fTemp1 - ((fConst471 * fRec203[1]) + (fConst414 * fRec203[2])));
			fRec204[0] = (fTemp1 - ((fConst472 * fRec204[1]) + (fConst414 * fRec204[2])));
			fRec205[0] = (fTemp1 - ((fConst473 * fRec205[1]) + (fConst406 * fRec205[2])));
			fRec206[0] = (fTemp1 - ((fConst474 * fRec206[1]) + (fConst419 * fRec206[2])));
			fRec207[0] = (fTemp1 - ((fConst475 * fRec207[1]) + (fConst402 * fRec207[2])));
			fRec208[0] = (fTemp1 - ((fConst476 * fRec208[1]) + (fConst402 * fRec208[2])));
			fRec209[0] = (fTemp1 - ((fConst479 * fRec209[1]) + (fConst480 * fRec209[2])));
			fRec210[0] = (fTemp1 - ((fConst481 * fRec210[1]) + (fConst480 * fRec210[2])));
			fRec211[0] = (fTemp1 - ((fConst482 * fRec211[1]) + (fConst402 * fRec211[2])));
			fRec212[0] = (fTemp1 - ((fConst483 * fRec212[1]) + (fConst480 * fRec212[2])));
			fRec213[0] = (fTemp1 - ((fConst484 * fRec213[1]) + (fConst480 * fRec213[2])));
			fRec214[0] = (fTemp1 - ((fConst485 * fRec214[1]) + (fConst402 * fRec214[2])));
			fRec215[0] = (fTemp1 - ((fConst486 * fRec215[1]) + (fConst480 * fRec215[2])));
			fRec216[0] = (fTemp1 - ((fConst487 * fRec216[1]) + (fConst402 * fRec216[2])));
			fRec217[0] = (fTemp1 - ((fConst488 * fRec217[1]) + (fConst402 * fRec217[2])));
			fRec218[0] = (fTemp1 - ((fConst489 * fRec218[1]) + (fConst402 * fRec218[2])));
			fRec219[0] = (fTemp1 - ((fConst490 * fRec219[1]) + (fConst402 * fRec219[2])));
			fRec220[0] = (fTemp1 - ((fConst491 * fRec220[1]) + (fConst402 * fRec220[2])));
			fRec221[0] = (fTemp1 - ((fConst492 * fRec221[1]) + (fConst402 * fRec221[2])));
			fRec222[0] = (fTemp1 - ((fConst494 * fRec222[1]) + (fConst495 * fRec222[2])));
			fRec223[0] = (fTemp1 - ((fConst497 * fRec223[1]) + (fConst498 * fRec223[2])));
			fRec224[0] = (fTemp1 - ((fConst500 * fRec224[1]) + (fConst501 * fRec224[2])));
			fRec225[0] = (fTemp1 - ((fConst504 * fRec225[1]) + (fConst505 * fRec225[2])));
			fRec226[0] = (fTemp1 - ((fConst506 * fRec226[1]) + (fConst505 * fRec226[2])));
			fRec227[0] = (fTemp1 - ((fConst509 * fRec227[1]) + (fConst510 * fRec227[2])));
			fRec228[0] = (fTemp1 - ((fConst511 * fRec228[1]) + (fConst505 * fRec228[2])));
			fRec229[0] = (fTemp1 - ((fConst512 * fRec229[1]) + (fConst510 * fRec229[2])));
			fRec230[0] = (fTemp1 - ((fConst515 * fRec230[1]) + (fConst516 * fRec230[2])));
			fRec231[0] = (fTemp1 - ((fConst519 * fRec231[1]) + (fConst520 * fRec231[2])));
			fRec232[0] = (fTemp1 - ((fConst521 * fRec232[1]) + (fConst520 * fRec232[2])));
			fRec233[0] = (fTemp1 - ((fConst524 * fRec233[1]) + (fConst525 * fRec233[2])));
			fRec234[0] = (fTemp1 - ((fConst528 * fRec234[1]) + (fConst529 * fRec234[2])));
			fRec235[0] = (fTemp1 - ((fConst530 * fRec235[1]) + (fConst525 * fRec235[2])));
			fRec236[0] = (fTemp1 - ((fConst531 * fRec236[1]) + (fConst525 * fRec236[2])));
			fRec237[0] = (fTemp1 - ((fConst534 * fRec237[1]) + (fConst535 * fRec237[2])));
			fRec238[0] = (fTemp1 - ((fConst536 * fRec238[1]) + (fConst535 * fRec238[2])));
			fRec239[0] = (fTemp1 - ((fConst537 * fRec239[1]) + (fConst525 * fRec239[2])));
			fRec240[0] = (fTemp1 - ((fConst538 * fRec240[1]) + (fConst525 * fRec240[2])));
			fRec241[0] = (fTemp1 - ((fConst539 * fRec241[1]) + (fConst525 * fRec241[2])));
			fRec242[0] = (fTemp1 - ((fConst540 * fRec242[1]) + (fConst525 * fRec242[2])));
			fRec243[0] = (fTemp1 - ((fConst541 * fRec243[1]) + (fConst516 * fRec243[2])));
			fRec244[0] = (fTemp1 - ((fConst542 * fRec244[1]) + (fConst525 * fRec244[2])));
			fRec245[0] = (fTemp1 - ((fConst543 * fRec245[1]) + (fConst525 * fRec245[2])));
			fRec246[0] = (fTemp1 - ((fConst544 * fRec246[1]) + (fConst525 * fRec246[2])));
			fRec247[0] = (fTemp1 - ((fConst547 * fRec247[1]) + (fConst548 * fRec247[2])));
			fRec248[0] = (fTemp1 - ((fConst549 * fRec248[1]) + (fConst548 * fRec248[2])));
			fRec249[0] = (fTemp1 - ((fConst550 * fRec249[1]) + (fConst548 * fRec249[2])));
			fRec250[0] = (fTemp1 - ((fConst551 * fRec250[1]) + (fConst516 * fRec250[2])));
			fRec251[0] = (fTemp1 - ((fConst552 * fRec251[1]) + (fConst525 * fRec251[2])));
			fRec252[0] = (fTemp1 - ((fConst553 * fRec252[1]) + (fConst520 * fRec252[2])));
			fRec253[0] = (fTemp1 - ((fConst554 * fRec253[1]) + (fConst525 * fRec253[2])));
			fRec254[0] = (fTemp1 - ((fConst555 * fRec254[1]) + (fConst516 * fRec254[2])));
			fRec255[0] = (fTemp1 - ((fConst556 * fRec255[1]) + (fConst525 * fRec255[2])));
			fRec256[0] = (fTemp1 - ((fConst557 * fRec256[1]) + (fConst525 * fRec256[2])));
			fRec257[0] = (fTemp1 - ((fConst558 * fRec257[1]) + (fConst548 * fRec257[2])));
			fRec258[0] = (fTemp1 - ((fConst559 * fRec258[1]) + (fConst520 * fRec258[2])));
			fRec259[0] = (fTemp1 - ((fConst560 * fRec259[1]) + (fConst525 * fRec259[2])));
			fRec260[0] = (fTemp1 - ((fConst561 * fRec260[1]) + (fConst516 * fRec260[2])));
			fRec261[0] = (fTemp1 - ((fConst562 * fRec261[1]) + (fConst529 * fRec261[2])));
			fRec262[0] = (fTemp1 - ((fConst563 * fRec262[1]) + (fConst529 * fRec262[2])));
			fRec263[0] = (fTemp1 - ((fConst564 * fRec263[1]) + (fConst516 * fRec263[2])));
			output0[i] = FAUSTFLOAT(((fSlow1 + (fSlow0 * ((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((0.30709716092200001 * (fRec0[0] - fRec0[2])) + (0.35395211346200001 * (fRec1[0] - fRec1[2]))) + (0.40899455212899999 * (fRec2[0] - fRec2[2]))) + (0.37298286228200001 * (fRec3[0] - fRec3[2]))) + (0.64723755464699995 * (fRec4[0] - fRec4[2]))) + (0.75831734996800004 * (fRec5[0] - fRec5[2]))) + (0.758203169801 * (fRec6[0] - fRec6[2]))) + (0.68980235143199997 * (fRec7[0] - fRec7[2]))) + (0.52851380984600005 * (fRec8[0] - fRec8[2]))) + (0.70040813984399997 * (fRec9[0] - fRec9[2]))) + (0.68222528583499997 * (fRec10[0] - fRec10[2]))) + (0.54462493103499998 * (fRec11[0] - fRec11[2]))) + (0.54105663829999995 * (fRec12[0] - fRec12[2]))) + (0.49991648167500002 * (fRec13[0] - fRec13[2]))) + (0.67663914197300001 * (fRec14[0] - fRec14[2]))) + (0.66335578608599999 * (fRec15[0] - fRec15[2]))) + (0.69777717224900004 * (fRec16[0] - fRec16[2]))) + (0.54059551786600002 * (fRec17[0] - fRec17[2]))) + (0.51754695941600004 * (fRec18[0] - fRec18[2]))) + (0.51964051718199999 * (fRec19[0] - fRec19[2]))) + (0.52082316352199998 * (fRec20[0] - fRec20[2]))) + (0.52780988323599998 * (fRec21[0] - fRec21[2]))) + (0.53150071723799996 * (fRec22[0] - fRec22[2]))) + (0.39607179278299998 * (fRec23[0] - fRec23[2]))) + (0.410248639819 * (fRec24[0] - fRec24[2]))) + (0.404123521486 * (fRec25[0] - fRec25[2]))) + (0.39486159529699999 * (fRec26[0] - fRec26[2]))) + (0.49381091160099999 * (fRec27[0] - fRec27[2]))) + (0.316497816057 * (fRec28[0] - fRec28[2]))) + (0.32264601437500001 * (fRec29[0] - fRec29[2]))) + (0.70189633372399995 * (fRec30[0] - fRec30[2]))) + (0.51785690473299995 * (fRec31[0] - fRec31[2]))) + (0.54542242008099995 * (fRec32[0] - fRec32[2]))) + (0.54451604269700005 * (fRec33[0] - fRec33[2]))) + (0.454519689422 * (fRec34[0] - fRec34[2]))) + (0.96994724871799998 * (fRec35[0] - fRec35[2]))) + (0.92040568095499997 * (fRec36[0] - fRec36[2]))) + (0.58314663890700003 * (fRec37[0] - fRec37[2]))) + (0.54143218010799998 * (fRec38[0] - fRec38[2]))) + (0.354703882079 * (fRec39[0] - fRec39[2]))) + (0.63857784016800001 * (fRec40[0] - fRec40[2]))) + (0.60525764826299999 * (fRec41[0] - fRec41[2]))) + (0.70541357482800005 * (fRec42[0] - fRec42[2]))) + (0.72170257638500002 * (fRec43[0] - fRec43[2]))) + (0.71183825079899998 * (fRec44[0] - fRec44[2]))) + (0.69111142155899996 * (fRec45[0] - fRec45[2]))) + (0.73513969754399999 * (fRec46[0] - fRec46[2]))) + (0.87585524690600003 * (fRec47[0] - fRec47[2]))) + (0.85500828654799998 * (fRec48[0] - fRec48[2]))) + (0.81183814888600003 * (fRec49[0] - fRec49[2]))) + (0.53061436187400002 * (fRec50[0] - fRec50[2]))) + (0.484216442739 * (fRec51[0] - fRec51[2]))) + (0.33915735854599999 * (fRec52[0] - fRec52[2]))) + (0.335687461972 * (fRec53[0] - fRec53[2]))) + (0.41016313292000001 * (fRec54[0] - fRec54[2]))) + (0.38733142860000003 * (fRec55[0] - fRec55[2]))) + (0.56691416595400002 * (fRec56[0] - fRec56[2]))) + (0.66538721684199997 * (fRec57[0] - fRec57[2]))) + (0.77255187644400003 * (fRec58[0] - fRec58[2]))) + (0.747000916781 * (fRec59[0] - fRec59[2]))) + (0.730876043822 * (fRec60[0] - fRec60[2]))) + (0.68225712555399998 * (fRec61[0] - fRec61[2]))) + (0.76728824553200003 * (fRec62[0] - fRec62[2]))) + (0.78528400371700002 * (fRec63[0] - fRec63[2]))) + (fRec64[0] - fRec64[2])) + (0.93554686280199995 * (fRec65[0] - fRec65[2]))) + (0.923865100657 * (fRec66[0] - fRec66[2]))) + (0.90367894149500005 * (fRec67[0] - fRec67[2]))) + (0.94546182304799997 * (fRec68[0] - fRec68[2]))) + (0.772640376643 * (fRec69[0] - fRec69[2]))) + (0.64320964644400003 * (fRec70[0] - fRec70[2]))) + (0.50407545092200001 * (fRec71[0] - fRec71[2]))) + (0.53022638703900005 * (fRec72[0] - fRec72[2]))) + (0.51044643433699999 * (fRec73[0] - fRec73[2]))) + (0.31494268882499998 * (fRec74[0] - fRec74[2]))) + (0.27484499236999999 * (fRec75[0] - fRec75[2]))) + (0.26760180337900003 * (fRec76[0] - fRec76[2]))) + (0.26470787937700002 * (fRec77[0] - fRec77[2]))) + (0.217342448444 * (fRec78[0] - fRec78[2]))) + (0.218455265742 * (fRec79[0] - fRec79[2]))) + (0.19818225091300001 * (fRec80[0] - fRec80[2]))) + (0.19699798196900001 * (fRec81[0] - fRec81[2]))) + (0.174074017567 * (fRec82[0] - fRec82[2]))) + (0.231377743877 * (fRec83[0] - fRec83[2]))) + (0.309026542731 * (fRec84[0] - fRec84[2]))) + (0.28308105833300001 * (fRec85[0] - fRec85[2]))) + (0.29457079769200001 * (fRec86[0] - fRec86[2]))) + (0.239728034723 * (fRec87[0] - fRec87[2]))) + (0.244186813556 * (fRec88[0] - fRec88[2]))) + (0.23066034375300001 * (fRec89[0] - fRec89[2]))) + (0.26607718866800001 * (fRec90[0] - fRec90[2]))) + (0.25268024948000001 * (fRec91[0] - fRec91[2]))) + (0.243692234087 * (fRec92[0] - fRec92[2]))) + (0.22742174795699999 * (fRec93[0] - fRec93[2]))) + (0.249302949243 * (fRec94[0] - fRec94[2]))) + (0.21927280048100001 * (fRec95[0] - fRec95[2]))) + (0.24308054842499999 * (fRec96[0] - fRec96[2]))) + (0.236955542987 * (fRec97[0] - fRec97[2]))) + (0.24203929803099999 * (fRec98[0] - fRec98[2]))) + (0.18778130338099999 * (fRec99[0] - fRec99[2]))) + (0.187547935528 * (fRec100[0] - fRec100[2]))) + (0.19867021812300001 * (fRec101[0] - fRec101[2]))) + (0.198399992444 * (fRec102[0] - fRec102[2]))) + (0.19192250371200001 * (fRec103[0] - fRec103[2]))) + (0.22582855101099999 * (fRec104[0] - fRec104[2]))) + (0.20692120585099999 * (fRec105[0] - fRec105[2]))) + (0.213022615468 * (fRec106[0] - fRec106[2]))) + (0.22584826550000001 * (fRec107[0] - fRec107[2]))) + (0.22937051603899999 * (fRec108[0] - fRec108[2]))) + (0.247965027393 * (fRec109[0] - fRec109[2]))) + (0.244559095423 * (fRec110[0] - fRec110[2]))) + (0.228020783073 * (fRec111[0] - fRec111[2]))) + (0.25062131160099999 * (fRec112[0] - fRec112[2]))) + (0.25103794219800002 * (fRec113[0] - fRec113[2]))) + (0.22664952582799999 * (fRec114[0] - fRec114[2]))) + (0.226875418903 * (fRec115[0] - fRec115[2]))) + (0.22091976767300001 * (fRec116[0] - fRec116[2]))) + (0.202873125894 * (fRec117[0] - fRec117[2]))) + (0.22236349320099999 * (fRec118[0] - fRec118[2]))) + (0.22683589949499999 * (fRec119[0] - fRec119[2]))) + (0.200686533064 * (fRec120[0] - fRec120[2]))) + (0.20022683433999999 * (fRec121[0] - fRec121[2]))) + (0.16558811844900001 * (fRec122[0] - fRec122[2]))) + (0.16434726007299999 * (fRec123[0] - fRec123[2]))) + (0.142980453403 * (fRec124[0] - fRec124[2]))) + (0.10326189197000001 * (fRec125[0] - fRec125[2]))) + (0.10281043857699999 * (fRec126[0] - fRec126[2]))) + (0.107585837288 * (fRec127[0] - fRec127[2]))) + (0.12562772553000001 * (fRec128[0] - fRec128[2]))) + (0.11381033369 * (fRec129[0] - fRec129[2]))) + (0.103455544523 * (fRec130[0] - fRec130[2]))) + (0.110185835407 * (fRec131[0] - fRec131[2]))) + (0.102494444596 * (fRec132[0] - fRec132[2]))) + (0.096457339867999994 * (fRec133[0] - fRec133[2]))) + (0.083625136152299995 * (fRec134[0] - fRec134[2]))) + (0.082372154612399995 * (fRec135[0] - fRec135[2]))) + (0.066334775838299997 * (fRec136[0] - fRec136[2]))) + (0.054967111323999999 * (fRec137[0] - fRec137[2]))) + (0.052819617437700001 * (fRec138[0] - fRec138[2]))) + (0.0607484825609 * (fRec139[0] - fRec139[2]))) + (0.0577382804808 * (fRec140[0] - fRec140[2]))) + (0.055122805311799999 * (fRec141[0] - fRec141[2]))) + (0.061975380094700001 * (fRec142[0] - fRec142[2]))) + (0.052631948795299997 * (fRec143[0] - fRec143[2]))) + (0.046076833207199998 * (fRec144[0] - fRec144[2]))) + (0.039786125811499998 * (fRec145[0] - fRec145[2]))) + (0.039982532122600001 * (fRec146[0] - fRec146[2]))) + (0.039483263290200001 * (fRec147[0] - fRec147[2]))) + (0.032353444154800001 * (fRec148[0] - fRec148[2]))) + (0.034815490227599999 * (fRec149[0] - fRec149[2]))) + (0.032926786022999997 * (fRec150[0] - fRec150[2]))) + (0.031860872697300001 * (fRec151[0] - fRec151[2]))) + (0.033529195212500001 * (fRec152[0] - fRec152[2]))) + (0.034482900561 * (fRec153[0] - fRec153[2]))) + (0.035774270310000002 * (fRec154[0] - fRec154[2]))) + (0.033187080383000001 * (fRec155[0] - fRec155[2]))) + (0.0334818333904 * (fRec156[0] - fRec156[2]))) + (0.031530540833700001 * (fRec157[0] - fRec157[2]))) + (0.0310516617902 * (fRec158[0] - fRec158[2]))) + (0.028121563038100001 * (fRec159[0] - fRec159[2]))) + (0.023704128764999999 * (fRec160[0] - fRec160[2]))) + (0.021631040416399998 * (fRec161[0] - fRec161[2]))) + (0.023998359495699999 * (fRec162[0] - fRec162[2]))) + (0.017796006342000001 * (fRec163[0] - fRec163[2]))) + (0.019710638390999999 * (fRec164[0] - fRec164[2]))) + (0.014962052149600001 * (fRec165[0] - fRec165[2]))) + (0.011202901338100001 * (fRec166[0] - fRec166[2]))) + (0.011013427587399999 * (fRec167[0] - fRec167[2]))) + (0.012171082203 * (fRec168[0] - fRec168[2]))) + (0.012091853550900001 * (fRec169[0] - fRec169[2]))) + (0.0134204812534 * (fRec170[0] - fRec170[2]))) + (0.013879963528900001 * (fRec171[0] - fRec171[2]))) + (0.0164342652073 * (fRec172[0] - fRec172[2]))) + (0.016167460191700001 * (fRec173[0] - fRec173[2]))) + (0.0150626556124 * (fRec174[0] - fRec174[2]))) + (0.0140527744632 * (fRec175[0] - fRec175[2]))) + (0.0147230198283 * (fRec176[0] - fRec176[2]))) + (0.018963959307999999 * (fRec177[0] - fRec177[2]))) + (0.0165469090363 * (fRec178[0] - fRec178[2]))) + (0.018212947504800001 * (fRec179[0] - fRec179[2]))) + (0.019081718452200001 * (fRec180[0] - fRec180[2]))) + (0.018994433335500001 * (fRec181[0] - fRec181[2]))) + (0.0178124360217 * (fRec182[0] - fRec182[2]))) + (0.018220546065099999 * (fRec183[0] - fRec183[2]))) + (0.0181175826461 * (fRec184[0] - fRec184[2]))) + (0.017749773195800001 * (fRec185[0] - fRec185[2]))) + (0.017208767719000002 * (fRec186[0] - fRec186[2]))) + (0.0190165583742 * (fRec187[0] - fRec187[2]))) + (0.019472194516000001 * (fRec188[0] - fRec188[2]))) + (0.019746473061999999 * (fRec189[0] - fRec189[2]))) + (0.0198134381774 * (fRec190[0] - fRec190[2]))) + (0.019724343592599999 * (fRec191[0] - fRec191[2]))) + (0.0222130643917 * (fRec192[0] - fRec192[2]))) + (0.019502299845500001 * (fRec193[0] - fRec193[2]))) + (0.018138461632299999 * (fRec194[0] - fRec194[2]))) + (0.018100540352699999 * (fRec195[0] - fRec195[2]))) + (0.0197337814589 * (fRec196[0] - fRec196[2]))) + (0.018051579859100001 * (fRec197[0] - fRec197[2]))) + (0.0165460648104 * (fRec198[0] - fRec198[2]))) + (0.017324362952199999 * (fRec199[0] - fRec199[2]))) + (0.016818647304100001 * (fRec200[0] - fRec200[2]))) + (0.016073054410199999 * (fRec201[0] - fRec201[2]))) + (0.0158388434822 * (fRec202[0] - fRec202[2]))) + (0.0156542814568 * (fRec203[0] - fRec203[2]))) + (0.0151799700193 * (fRec204[0] - fRec204[2]))) + (0.016252393735600001 * (fRec205[0] - fRec205[2]))) + (0.014564802311900001 * (fRec206[0] - fRec206[2]))) + (0.0139623141329 * (fRec207[0] - fRec207[2]))) + (0.014079209487700001 * (fRec208[0] - fRec208[2]))) + (0.013259870529900001 * (fRec209[0] - fRec209[2]))) + (0.0132660074465 * (fRec210[0] - fRec210[2]))) + (0.013548015577 * (fRec211[0] - fRec211[2]))) + (0.013284172048800001 * (fRec212[0] - fRec212[2]))) + (0.013258980337100001 * (fRec213[0] - fRec213[2]))) + (0.013467848114 * (fRec214[0] - fRec214[2]))) + (0.0134039692302 * (fRec215[0] - fRec215[2]))) + (0.013879035768900001 * (fRec216[0] - fRec216[2]))) + (0.0137984179574 * (fRec217[0] - fRec217[2]))) + (0.013730027104599999 * (fRec218[0] - fRec218[2]))) + (0.013710441014200001 * (fRec219[0] - fRec219[2]))) + (0.0142355976982 * (fRec220[0] - fRec220[2]))) + (0.0139812932556 * (fRec221[0] - fRec221[2]))) + (0.012911600480799999 * (fRec222[0] - fRec222[2]))) + (0.012738783403299999 * (fRec223[0] - fRec223[2]))) + (0.011856117704700001 * (fRec224[0] - fRec224[2]))) + (0.0114161396557 * (fRec225[0] - fRec225[2]))) + (0.011404852566 * (fRec226[0] - fRec226[2]))) + (0.011063911293900001 * (fRec227[0] - fRec227[2]))) + (0.011342026767499999 * (fRec228[0] - fRec228[2]))) + (0.0108538408815 * (fRec229[0] - fRec229[2]))) + (0.0108812587085 * (fRec230[0] - fRec230[2]))) + (0.011069874211100001 * (fRec231[0] - fRec231[2]))) + (0.011181454347899999 * (fRec232[0] - fRec232[2]))) + (0.0103204239947 * (fRec233[0] - fRec233[2]))) + (0.0101956655646 * (fRec234[0] - fRec234[2]))) + (0.010456120685 * (fRec235[0] - fRec235[2]))) + (0.010549803605299999 * (fRec236[0] - fRec236[2]))) + (0.010056738809600001 * (fRec237[0] - fRec237[2]))) + (0.010045483670000001 * (fRec238[0] - fRec238[2]))) + (0.0105163535312 * (fRec239[0] - fRec239[2]))) + (0.0105794326455 * (fRec240[0] - fRec240[2]))) + (0.0104707050025 * (fRec241[0] - fRec241[2]))) + (0.0106648501728 * (fRec242[0] - fRec242[2]))) + (0.0109278172549 * (fRec243[0] - fRec243[2]))) + (0.0104205154346 * (fRec244[0] - fRec244[2]))) + (0.010542961850100001 * (fRec245[0] - fRec245[2]))) + (0.0106429661227 * (fRec246[0] - fRec246[2]))) + (0.011391621943 * (fRec247[0] - fRec247[2]))) + (0.011495946750199999 * (fRec248[0] - fRec248[2]))) + (0.011339260897999999 * (fRec249[0] - fRec249[2]))) + (0.0107438303743 * (fRec250[0] - fRec250[2]))) + (0.010519345438699999 * (fRec251[0] - fRec251[2]))) + (0.011070409158 * (fRec252[0] - fRec252[2]))) + (0.0106615897247 * (fRec253[0] - fRec253[2]))) + (0.010880844243100001 * (fRec254[0] - fRec254[2]))) + (0.0105143605788 * (fRec255[0] - fRec255[2]))) + (0.010581153952100001 * (fRec256[0] - fRec256[2]))) + (0.0116227007119 * (fRec257[0] - fRec257[2]))) + (0.0110320614019 * (fRec258[0] - fRec258[2]))) + (0.0102875354698 * (fRec259[0] - fRec259[2]))) + (0.010772568800900001 * (fRec260[0] - fRec260[2]))) + (0.010186605900400001 * (fRec261[0] - fRec261[2]))) + (0.0100817801797 * (fRec262[0] - fRec262[2]))) + (0.010872899328000001 * (fRec263[0] - fRec263[2]))))) * fTemp0));
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
