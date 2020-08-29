/* ------------------------------------------------------------
name: "simpleVocoder"
Code generated with Faust 2.8.3 (https://faust.grame.fr)
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
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\",";
                tab(fTab + 1, fUI); fUI << "\"index\": \"" << getAddressIndex(path) << "\"" << ((fMetaAux.size() > 0) ? "," : "");
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
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab + 1, fUI); fUI << "\"index\": \"" << getAddressIndex(path) << "\",";
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
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab + 1, fUI); fUI << "\"index\": \"" << getAddressIndex(path) << "\",";
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
            std::string path = buildPath(label);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << "soundfile" << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\"" << ",";
            tab(fTab + 1, fUI); fUI << "\"url\": \"" << url << "\"" << ",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\"" << ((fPathTable.size() > 0) ? "," : "");
            if (fPathTable.size() > 0) {
                tab(fTab + 1, fUI); fUI << "\"index\": \"" << getAddressIndex(path) << "\"";
            }
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
#include "effect.cpp"
#endif

#if SOUNDFILE
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2018 GRAME, Centre National de Creation Musicale
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

#ifdef __APPLE__
#include <CoreFoundation/CFBundle.h>
#endif

// Always included otherwise -i mode later on will not always include it (with the conditional includes)
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

#ifndef __Soundfile__
#define __Soundfile__

#include <iostream>

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#define BUFFER_SIZE 1024
#define SAMPLE_RATE 44100
#define MAX_CHAN    64

#ifdef _MSC_VER
#define PRE_PACKED_STRUCTURE  __pragma(pack(push,1))
#define POST_PACKED_STRUCTURE ;__pragma(pack(pop))
#else
#define PRE_PACKED_STRUCTURE
#define POST_PACKED_STRUCTURE __attribute__((__packed__))
#endif

/*
 The soundfile structure to be used by the DSP code.
 It has to be 'packed' to that the LLVM backend can correctly access it.
*/

PRE_PACKED_STRUCTURE
struct Soundfile {
    
    FAUSTFLOAT** fBuffers;
    int fLength;
    int fSampleRate;
    int fChannels;
    
    Soundfile()
    {
        fBuffers = NULL;
        fLength = -1;
        fSampleRate = -1;
        fChannels = -1;
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

/*
 The generic soundfile reader.
 */

class SoundfileReader {
    
    protected:
    
        void FillDefault(Soundfile* soundfile, const std::string& path_name_str, int max_chan)
        {
            if (path_name_str != "") {
                std::cerr << "Error opening the file : " << path_name_str << std::endl;
            }
            
            soundfile->fChannels = 1;
            soundfile->fLength = BUFFER_SIZE;
            soundfile->fSampleRate = SAMPLE_RATE;
            
            // Allocate 1 channel
            soundfile->fBuffers[0] = new FAUSTFLOAT[BUFFER_SIZE];
            if (!soundfile->fBuffers[0]) {
                throw std::bad_alloc();
            }
            memset(soundfile->fBuffers[0], 0, BUFFER_SIZE * sizeof(FAUSTFLOAT));
            
            // Share the same buffer for all other channels so that we have max_chan channels available
            for (int chan = soundfile->fChannels; chan < max_chan; chan++) {
                soundfile->fBuffers[chan] = soundfile->fBuffers[0];
            }
        }
    
        Soundfile* Create(int max_chan)
        {
            Soundfile* soundfile = new Soundfile();
            if (!soundfile) {
                throw std::bad_alloc();
            }
            soundfile->fBuffers = new FAUSTFLOAT*[max_chan];
            if (!soundfile->fBuffers) {
                throw std::bad_alloc();
            }
            return soundfile;
        }
    
    public:
    
        virtual ~SoundfileReader() {}
    
        virtual Soundfile* Read(const std::string& path_name_str, int max_chan) = 0;
    
        virtual std::string CheckAux(const std::string& path_name_str) = 0;
        
        // Check if soundfile exists and return the real path_name
        static std::string Check(const std::vector<std::string>& sound_directories, const std::string& file_name_str);
    
};

#endif

#if defined(JUCE_32BIT) || defined(JUCE_64BIT)
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2018 GRAME, Centre National de Creation Musicale
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

#ifndef __JuceReader__
#define __JuceReader__


struct JuceReader : public SoundfileReader {
    
    std::string CheckAux(const std::string& path_name_str)
    {
        File file(path_name_str);
        if (file.existsAsFile()) {
            return path_name_str;
        } else {
            std::cerr << "ERROR : cannot open '" << path_name_str << std::endl;
            return "";
        }
    }
    
    JuceReader() {}
    
    Soundfile* Read(const std::string& path_name_str, int max_chan)
    {
        Soundfile* soundfile = Create(max_chan);
        
        AudioFormatManager formatManager;
        formatManager.registerBasicFormats();
        
        ScopedPointer<AudioFormatReader> formatReader = formatManager.createReaderFor(File(path_name_str));
        if (formatReader) {
            
            soundfile->fChannels = int(formatReader->numChannels);
            soundfile->fSampleRate = int(formatReader->sampleRate);
            soundfile->fLength = int(formatReader->lengthInSamples);
            
            for (int chan = 0; chan < soundfile->fChannels; chan++) {
                soundfile->fBuffers[chan] = new FAUSTFLOAT[soundfile->fLength];
                if (!soundfile->fBuffers[chan]) {
                    throw std::bad_alloc();
                }
            }
            
            if (formatReader->read(reinterpret_cast<int *const *>(soundfile->fBuffers), soundfile->fChannels, 0, soundfile->fLength, false)) {
                // Possibly concert samples
                if (!formatReader->usesFloatingPointData) {
                    for (int chan = 0; chan < soundfile->fChannels; ++chan) {
                        FAUSTFLOAT* buffer = soundfile->fBuffers[chan];
                        FloatVectorOperations::convertFixedToFloat(buffer, reinterpret_cast<const int*>(buffer), 1.0f/0x7fffffff, soundfile->fLength);
                    }
                }
                // Share the same buffers for all other channels so that we have max_chan channels available
                for (int chan = soundfile->fChannels; chan < max_chan; chan++) {
                    soundfile->fBuffers[chan] = soundfile->fBuffers[chan % soundfile->fChannels];
                }
            } else {
                std::cerr << "Error opening the file : " << path_name_str << std::endl;
            }
            
        } else {
            FillDefault(soundfile, path_name_str, max_chan);
        }
        
        return soundfile;
    }
    
    static Soundfile* createSoundfile(const std::string& path_name_str, int max_chan)
    {
        JuceReader reader;
        return reader.Read(path_name_str, max_chan);
    }
    
};

#endif
Soundfile* createSoundfile(const std::string& path_name_str, int max_chan)
{
    return JuceReader::createSoundfile(path_name_str, max_chan);
}
#else
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2018 GRAME, Centre National de Creation Musicale
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

#ifndef __LibsndfileReader__
#define __LibsndfileReader__

#include <sndfile.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <fstream>


struct LibsndfileReader : public SoundfileReader {
    
    typedef sf_count_t (* sample_read)(SNDFILE* sndfile, FAUSTFLOAT* ptr, sf_count_t frames);
    
    std::string CheckAux(const std::string& path_name_str)
    {
        SF_INFO snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name_str.c_str(), SFM_READ, &snd_info);
        if (snd_file) {
            sf_close(snd_file);
            return path_name_str;
        } else {
            std::cerr << "ERROR : cannot open '" << path_name_str << "' (" << sf_strerror(NULL) << ")" << std::endl;
            return "";
        }
    }
    
    LibsndfileReader() {}
    
    Soundfile* Read(const std::string& path_name_str, int max_chan)
    {
        Soundfile* soundfile = Create(max_chan);
        
        // Open sndfile
        SF_INFO	snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name_str.c_str(), SFM_READ, &snd_info);
        
        if (snd_file) {
            
            soundfile->fChannels = std::min(max_chan, snd_info.channels);
            soundfile->fLength = int(snd_info.frames);
            soundfile->fSampleRate = snd_info.samplerate;
            
            for (int chan = 0; chan < soundfile->fChannels; chan++) {
                soundfile->fBuffers[chan] = new FAUSTFLOAT[snd_info.frames];
                if (!soundfile->fBuffers[chan]) {
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
                    for (int chan = 0; chan < soundfile->fChannels; chan++) {
                        soundfile->fBuffers[chan][index + sample] = buffer[sample * snd_info.channels + chan];
                    }
                }
                index += nbf;
            } while (nbf == BUFFER_SIZE);
            
            // Share the same buffers for all other channels so that we have max_chan channels available
            for (int chan = soundfile->fChannels; chan < max_chan; chan++) {
                soundfile->fBuffers[chan] = soundfile->fBuffers[chan % snd_info.channels];
            }
       
            sf_close(snd_file);
            
        } else {
            FillDefault(soundfile, path_name_str, max_chan);
        }
        
        return soundfile;
    }
    
    static Soundfile* createSoundfile(const std::string& path_name_str, int max_chan)
    {
        LibsndfileReader reader;
        return reader.Read(path_name_str, max_chan);
    }
};

#endif
Soundfile* createSoundfile(const std::string& path_name_str, int max_chan)
{
    return LibsndfileReader::createSoundfile(path_name_str, max_chan);
}
#endif

// To be used by dsp code if no SoundUI is used or when soundfile is not found
extern "C" Soundfile* defaultsound = createSoundfile("", MAX_CHAN);

class SoundUI : public GenericUI
{
		
    private:
    
        std::vector<std::string> fSoundfileDir;             // The soundfile directories
        std::map<std::string, Soundfile*> fSoundfileMap;    // Map to share loaded soundfiles
    
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
            for (it = fSoundfileMap.begin(); it != fSoundfileMap.end(); it++) {
                delete (*it).second;
            }
        }

        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* url, Soundfile** sf_zone)
        {
            std::string path_name_str = SoundfileReader::Check(fSoundfileDir, url);
            if (path_name_str != "") {
                // Check if 'path_name_str' is already loaded
                if (fSoundfileMap.find(path_name_str) == fSoundfileMap.end()) {
                    fSoundfileMap[path_name_str] = createSoundfile(path_name_str, MAX_CHAN);
                }
                // Get the soundfile
                *sf_zone = fSoundfileMap[path_name_str];
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
        #ifdef ANDROID_DRIVER
            bundle_path_str = "/data/data/__CURRENT_ANDROID_PACKAGE__/files";
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
        #ifdef ANDROID_DRIVER
            bundle_path_str = "/data/data/__CURRENT_ANDROID_PACKAGE__/files";
        #endif
            return bundle_path_str;
        }
};

// Check if soundfile exists and return the real path_name
std::string SoundfileReader::Check(const std::vector<std::string>& sound_directories, const std::string& file_name_str)
{
#if defined(JUCE_32BIT) || defined(JUCE_64BIT)
    JuceReader reader;
#else
    LibsndfileReader reader;
#endif
    std::string path_name_str = reader.CheckAux(file_name_str);
    if (path_name_str != "") {
        return path_name_str;
    } else {
        for (int i = 0; i < sound_directories.size(); i++) {
            std::string res = reader.CheckAux(sound_directories[i] + "/" + file_name_str);
            if (res != "") { return res; }
        }
        return "";
    }
}

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

static double mydsp_faustpower2_f(double value) {
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
	
	int fSamplingFreq;
	double fConst0;
	double fConst1;
	double fConst2;
	FAUSTFLOAT fHslider0;
	double fConst3;
	FAUSTFLOAT fHslider1;
	double fVec0[2];
	double fRec1[2];
	FAUSTFLOAT fVslider0;
	double fRec2[2];
	double fConst4;
	double fRec0[3];
	double fRec5[3];
	double fConst5;
	double fConst6;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	double fRec4[2];
	double fRec3[2];
	double fConst7;
	double fConst8;
	double fConst9;
	double fRec6[3];
	double fRec9[3];
	double fConst10;
	double fRec8[2];
	double fRec7[2];
	double fConst11;
	double fConst12;
	double fConst13;
	double fRec10[3];
	double fRec13[3];
	double fConst14;
	double fRec12[2];
	double fRec11[2];
	double fConst15;
	double fConst16;
	double fConst17;
	double fRec14[3];
	double fRec17[3];
	double fConst18;
	double fRec16[2];
	double fRec15[2];
	double fConst19;
	double fConst20;
	double fConst21;
	double fRec18[3];
	double fRec21[3];
	double fConst22;
	double fRec20[2];
	double fRec19[2];
	double fConst23;
	double fConst24;
	double fConst25;
	double fRec22[3];
	double fRec25[3];
	double fConst26;
	double fRec24[2];
	double fRec23[2];
	double fConst27;
	double fConst28;
	double fConst29;
	double fRec26[3];
	double fRec29[3];
	double fConst30;
	double fRec28[2];
	double fRec27[2];
	double fConst31;
	double fConst32;
	double fConst33;
	double fRec30[3];
	double fRec33[3];
	double fConst34;
	double fRec32[2];
	double fRec31[2];
	double fConst35;
	double fConst36;
	double fConst37;
	double fRec34[3];
	double fRec37[3];
	double fConst38;
	double fRec36[2];
	double fRec35[2];
	double fConst39;
	double fConst40;
	double fConst41;
	double fRec38[3];
	double fRec41[3];
	double fConst42;
	double fRec40[2];
	double fRec39[2];
	double fConst43;
	double fConst44;
	double fConst45;
	double fRec42[3];
	double fRec45[3];
	double fConst46;
	double fRec44[2];
	double fRec43[2];
	double fConst47;
	double fConst48;
	double fConst49;
	double fRec46[3];
	double fRec49[3];
	double fConst50;
	double fRec48[2];
	double fRec47[2];
	double fConst51;
	double fConst52;
	double fConst53;
	double fRec50[3];
	double fRec53[3];
	double fConst54;
	double fRec52[2];
	double fRec51[2];
	double fConst55;
	double fConst56;
	double fConst57;
	double fRec54[3];
	double fRec57[3];
	double fConst58;
	double fRec56[2];
	double fRec55[2];
	double fConst59;
	double fConst60;
	double fConst61;
	double fRec58[3];
	double fRec61[3];
	double fConst62;
	double fRec60[2];
	double fRec59[2];
	double fConst63;
	double fConst64;
	double fConst65;
	double fRec62[3];
	double fRec65[3];
	double fConst66;
	double fRec64[2];
	double fRec63[2];
	double fConst67;
	double fConst68;
	double fConst69;
	double fRec66[3];
	double fRec69[3];
	double fConst70;
	double fRec68[2];
	double fRec67[2];
	double fConst71;
	double fConst72;
	double fConst73;
	double fRec70[3];
	double fRec73[3];
	double fConst74;
	double fRec72[2];
	double fRec71[2];
	double fConst75;
	double fConst76;
	double fConst77;
	double fRec74[3];
	double fRec77[3];
	double fConst78;
	double fRec76[2];
	double fRec75[2];
	double fConst79;
	double fConst80;
	double fConst81;
	double fRec78[3];
	double fRec81[3];
	double fConst82;
	double fRec80[2];
	double fRec79[2];
	double fConst83;
	double fConst84;
	double fConst85;
	double fRec82[3];
	double fRec85[3];
	double fConst86;
	double fRec84[2];
	double fRec83[2];
	double fConst87;
	double fConst88;
	double fConst89;
	double fRec86[3];
	double fRec89[3];
	double fConst90;
	double fRec88[2];
	double fRec87[2];
	double fConst91;
	double fConst92;
	double fConst93;
	double fRec90[3];
	double fRec93[3];
	double fConst94;
	double fRec92[2];
	double fRec91[2];
	double fConst95;
	double fConst96;
	double fConst97;
	double fRec94[3];
	double fRec97[3];
	double fConst98;
	double fRec96[2];
	double fRec95[2];
	double fConst99;
	double fConst100;
	double fConst101;
	double fRec98[3];
	double fRec101[3];
	double fConst102;
	double fRec100[2];
	double fRec99[2];
	double fConst103;
	double fConst104;
	double fConst105;
	double fRec102[3];
	double fRec105[3];
	double fConst106;
	double fRec104[2];
	double fRec103[2];
	double fConst107;
	double fConst108;
	double fConst109;
	double fRec106[3];
	double fRec109[3];
	double fConst110;
	double fRec108[2];
	double fRec107[2];
	double fConst111;
	double fConst112;
	double fConst113;
	double fRec110[3];
	double fRec113[3];
	double fConst114;
	double fRec112[2];
	double fRec111[2];
	double fConst115;
	double fConst116;
	double fConst117;
	double fRec114[3];
	double fRec117[3];
	double fConst118;
	double fRec116[2];
	double fRec115[2];
	double fConst119;
	double fConst120;
	double fConst121;
	double fRec118[3];
	double fRec121[3];
	double fConst122;
	double fRec120[2];
	double fRec119[2];
	double fConst123;
	double fConst124;
	double fConst125;
	double fRec122[3];
	double fRec125[3];
	double fConst126;
	double fRec124[2];
	double fRec123[2];
	double fConst127;
	double fConst128;
	double fConst129;
	double fRec126[3];
	double fRec129[3];
	double fConst130;
	double fRec128[2];
	double fRec127[2];
	double fConst131;
	double fConst132;
	double fConst133;
	double fRec130[3];
	double fRec133[3];
	double fConst134;
	double fRec132[2];
	double fRec131[2];
	double fConst135;
	double fConst136;
	double fConst137;
	double fRec134[3];
	double fRec137[3];
	double fConst138;
	double fRec136[2];
	double fRec135[2];
	double fConst139;
	double fConst140;
	double fConst141;
	double fRec138[3];
	double fRec141[3];
	double fConst142;
	double fRec140[2];
	double fRec139[2];
	double fConst143;
	double fConst144;
	double fConst145;
	double fRec142[3];
	double fRec145[3];
	double fConst146;
	double fRec144[2];
	double fRec143[2];
	double fConst147;
	double fConst148;
	double fConst149;
	double fRec146[3];
	double fRec149[3];
	double fConst150;
	double fRec148[2];
	double fRec147[2];
	double fConst151;
	double fConst152;
	double fConst153;
	double fRec150[3];
	double fRec153[3];
	double fConst154;
	double fRec152[2];
	double fRec151[2];
	double fConst155;
	double fConst156;
	double fConst157;
	double fRec154[3];
	double fRec157[3];
	double fConst158;
	double fRec156[2];
	double fRec155[2];
	double fConst159;
	double fConst160;
	double fConst161;
	double fRec158[3];
	double fRec161[3];
	double fConst162;
	double fRec160[2];
	double fRec159[2];
	double fConst163;
	double fConst164;
	double fConst165;
	double fRec162[3];
	double fRec165[3];
	double fConst166;
	double fRec164[2];
	double fRec163[2];
	double fConst167;
	double fConst168;
	double fConst169;
	double fRec168[3];
	double fConst170;
	double fRec167[2];
	double fRec166[2];
	double fRec169[3];
	double fConst171;
	double fConst172;
	double fConst173;
	double fRec172[3];
	double fConst174;
	double fRec171[2];
	double fRec170[2];
	double fRec173[3];
	double fConst175;
	double fConst176;
	double fConst177;
	double fRec176[3];
	double fConst178;
	double fRec175[2];
	double fRec174[2];
	double fRec177[3];
	double fConst179;
	double fConst180;
	double fConst181;
	double fRec180[3];
	double fConst182;
	double fRec179[2];
	double fRec178[2];
	double fRec181[3];
	double fConst183;
	double fConst184;
	double fConst185;
	double fRec184[3];
	double fConst186;
	double fRec183[2];
	double fRec182[2];
	double fRec185[3];
	double fConst187;
	double fConst188;
	double fConst189;
	double fRec188[3];
	double fConst190;
	double fRec187[2];
	double fRec186[2];
	double fRec189[3];
	double fConst191;
	double fConst192;
	double fConst193;
	double fRec192[3];
	double fConst194;
	double fRec191[2];
	double fRec190[2];
	double fRec193[3];
	double fConst195;
	double fConst196;
	double fConst197;
	double fRec196[3];
	double fConst198;
	double fRec195[2];
	double fRec194[2];
	double fRec197[3];
	double fConst199;
	double fConst200;
	double fConst201;
	double fRec200[3];
	double fConst202;
	double fRec199[2];
	double fRec198[2];
	double fRec201[3];
	double fConst203;
	double fConst204;
	double fConst205;
	double fRec204[3];
	double fConst206;
	double fRec203[2];
	double fRec202[2];
	double fRec205[3];
	double fConst207;
	double fConst208;
	double fConst209;
	double fRec208[3];
	double fConst210;
	double fRec207[2];
	double fRec206[2];
	double fRec209[3];
	double fConst211;
	double fConst212;
	double fConst213;
	double fRec212[3];
	double fConst214;
	double fRec211[2];
	double fRec210[2];
	double fRec213[3];
	double fConst215;
	double fConst216;
	double fConst217;
	double fRec216[3];
	double fConst218;
	double fRec215[2];
	double fRec214[2];
	double fRec217[3];
	double fConst219;
	double fConst220;
	double fConst221;
	double fRec220[3];
	double fConst222;
	double fRec219[2];
	double fRec218[2];
	double fRec221[3];
	double fConst223;
	double fConst224;
	double fConst225;
	double fRec222[3];
	double fRec225[3];
	double fConst226;
	double fRec224[2];
	double fRec223[2];
	double fConst227;
	double fConst228;
	double fConst229;
	double fRec226[3];
	double fRec229[3];
	double fConst230;
	double fRec228[2];
	double fRec227[2];
	double fConst231;
	double fConst232;
	double fConst233;
	double fRec230[3];
	double fRec233[3];
	double fConst234;
	double fRec232[2];
	double fRec231[2];
	double fConst235;
	double fConst236;
	double fConst237;
	double fRec234[3];
	double fRec237[3];
	double fConst238;
	double fRec236[2];
	double fRec235[2];
	double fConst239;
	double fConst240;
	double fConst241;
	double fRec238[3];
	double fRec241[3];
	double fConst242;
	double fRec240[2];
	double fRec239[2];
	double fConst243;
	double fConst244;
	double fConst245;
	double fRec242[3];
	double fRec245[3];
	double fConst246;
	double fRec244[2];
	double fRec243[2];
	double fConst247;
	double fConst248;
	double fConst249;
	double fRec246[3];
	double fRec249[3];
	double fConst250;
	double fRec248[2];
	double fRec247[2];
	double fConst251;
	double fConst252;
	double fConst253;
	double fRec250[3];
	double fRec253[3];
	double fConst254;
	double fRec252[2];
	double fRec251[2];
	double fConst255;
	double fConst256;
	double fConst257;
	double fRec254[3];
	double fRec257[3];
	double fConst258;
	double fRec256[2];
	double fRec255[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "0.0");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.0");
		m->declare("filename", "simpleVocoder");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "0.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.1");
		m->declare("name", "simpleVocoder");
		m->declare("oscillators.lib/lf_imptrain:copyright", "Julius O. Smith");
		m->declare("oscillators.lib/lf_imptrain:license", "STK-4.3.0 (see licenses/stk-4.3.0.md)");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.0");
		m->declare("vaeffects.lib/name", "Faust Virtual Analog Filter Effect Library");
		m->declare("vaeffects.lib/version", "0.0");
	}

	virtual int getNumInputs() {
		return 1;
		
	}
	virtual int getNumOutputs() {
		return 2;
		
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
		
	}
	
	virtual void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = std::min(192000.0, std::max(1.0, double(fSamplingFreq)));
		fConst1 = std::tan((86.580925629131272 / fConst0));
		fConst2 = (1.0 / fConst1);
		fConst3 = (1.0 / fConst0);
		fConst4 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst1))));
		fConst5 = (0.0 - fConst2);
		fConst6 = (1000.0 / fConst0);
		fConst7 = std::tan((95.445304460225799 / fConst0));
		fConst8 = (1.0 / fConst7);
		fConst9 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst7))));
		fConst10 = (0.0 - fConst8);
		fConst11 = std::tan((105.21724129546709 / fConst0));
		fConst12 = (1.0 / fConst11);
		fConst13 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst11))));
		fConst14 = (0.0 - fConst12);
		fConst15 = std::tan((115.98965426782146 / fConst0));
		fConst16 = (1.0 / fConst15);
		fConst17 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst15))));
		fConst18 = (0.0 - fConst16);
		fConst19 = std::tan((127.86497470874437 / fConst0));
		fConst20 = (1.0 / fConst19);
		fConst21 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst19))));
		fConst22 = (0.0 - fConst20);
		fConst23 = std::tan((140.95612113401737 / fConst0));
		fConst24 = (1.0 / fConst23);
		fConst25 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst23))));
		fConst26 = (0.0 - fConst24);
		fConst27 = std::tan((155.38757294877101 / fConst0));
		fConst28 = (1.0 / fConst27);
		fConst29 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst27))));
		fConst30 = (0.0 - fConst28);
		fConst31 = std::tan((171.29655408120178 / fConst0));
		fConst32 = (1.0 / fConst31);
		fConst33 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst31))));
		fConst34 = (0.0 - fConst32);
		fConst35 = std::tan((188.83433779976647 / fConst0));
		fConst36 = (1.0 / fConst35);
		fConst37 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst35))));
		fConst38 = (0.0 - fConst36);
		fConst39 = std::tan((208.16768512093211 / fConst0));
		fConst40 = (1.0 / fConst39);
		fConst41 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst39))));
		fConst42 = (0.0 - fConst40);
		fConst43 = std::tan((229.48043048482631 / fConst0));
		fConst44 = (1.0 / fConst43);
		fConst45 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst43))));
		fConst46 = (0.0 - fConst44);
		fConst47 = std::tan((252.97522977645821 / fConst0));
		fConst48 = (1.0 / fConst47);
		fConst49 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst47))));
		fConst50 = (0.0 - fConst48);
		fConst51 = std::tan((278.8754873138667 / fConst0));
		fConst52 = (1.0 / fConst51);
		fConst53 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst51))));
		fConst54 = (0.0 - fConst52);
		fConst55 = std::tan((307.42748012629335 / fConst0));
		fConst56 = (1.0 / fConst55);
		fConst57 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst55))));
		fConst58 = (0.0 - fConst56);
		fConst59 = std::tan((338.90269972144324 / fConst0));
		fConst60 = (1.0 / fConst59);
		fConst61 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst59))));
		fConst62 = (0.0 - fConst60);
		fConst63 = std::tan((373.6004336089261 / fConst0));
		fConst64 = (1.0 / fConst63);
		fConst65 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst63))));
		fConst66 = (0.0 - fConst64);
		fConst67 = std::tan((411.85061112673742 / fConst0));
		fConst68 = (1.0 / fConst67);
		fConst69 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst67))));
		fConst70 = (0.0 - fConst68);
		fConst71 = std::tan((454.01694063080589 / fConst0));
		fConst72 = (1.0 / fConst71);
		fConst73 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst71))));
		fConst74 = (0.0 - fConst72);
		fConst75 = std::tan((500.50036787811041 / fConst0));
		fConst76 = (1.0 / fConst75);
		fConst77 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst75))));
		fConst78 = (0.0 - fConst76);
		fConst79 = std::tan((551.74288848799608 / fConst0));
		fConst80 = (1.0 / fConst79);
		fConst81 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst79))));
		fConst82 = (0.0 - fConst80);
		fConst83 = std::tan((608.23175073312711 / fConst0));
		fConst84 = (1.0 / fConst83);
		fConst85 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst83))));
		fConst86 = (0.0 - fConst84);
		fConst87 = std::tan((670.50408862303561 / fConst0));
		fConst88 = (1.0 / fConst87);
		fConst89 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst87))));
		fConst90 = (0.0 - fConst88);
		fConst91 = std::tan((739.15202933473131 / fConst0));
		fConst92 = (1.0 / fConst91);
		fConst93 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst91))));
		fConst94 = (0.0 - fConst92);
		fConst95 = std::tan((814.82832355525409 / fConst0));
		fConst96 = (1.0 / fConst95);
		fConst97 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst95))));
		fConst98 = (0.0 - fConst96);
		fConst99 = std::tan((898.25255227323839 / fConst0));
		fConst100 = (1.0 / fConst99);
		fConst101 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst99))));
		fConst102 = (0.0 - fConst100);
		fConst103 = std::tan((990.217969037834 / fConst0));
		fConst104 = (1.0 / fConst103);
		fConst105 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst103))));
		fConst106 = (0.0 - fConst104);
		fConst107 = std::tan((1091.5990427457709 / fConst0));
		fConst108 = (1.0 / fConst107);
		fConst109 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst107))));
		fConst110 = (0.0 - fConst108);
		fConst111 = std::tan((1203.3597726784494 / fConst0));
		fConst112 = (1.0 / fConst111);
		fConst113 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst111))));
		fConst114 = (0.0 - fConst112);
		fConst115 = std::tan((1326.5628548540053 / fConst0));
		fConst116 = (1.0 / fConst115);
		fConst117 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst115))));
		fConst118 = (0.0 - fConst116);
		fConst119 = std::tan((1462.3797868541828 / fConst0));
		fConst120 = (1.0 / fConst119);
		fConst121 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst119))));
		fConst122 = (0.0 - fConst120);
		fConst123 = std::tan((1612.1020072094836 / fConst0));
		fConst124 = (1.0 / fConst123);
		fConst125 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst123))));
		fConst126 = (0.0 - fConst124);
		fConst127 = std::tan((1777.1531752633464 / fConst0));
		fConst128 = (1.0 / fConst127);
		fConst129 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst127))));
		fConst130 = (0.0 - fConst128);
		fConst131 = std::tan((1959.1027082805399 / fConst0));
		fConst132 = (1.0 / fConst131);
		fConst133 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst131))));
		fConst134 = (0.0 - fConst132);
		fConst135 = std::tan((2159.6807045196892 / fConst0));
		fConst136 = (1.0 / fConst135);
		fConst137 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst135))));
		fConst138 = (0.0 - fConst136);
		fConst139 = std::tan((2380.794394168513 / fConst0));
		fConst140 = (1.0 / fConst139);
		fConst141 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst139))));
		fConst142 = (0.0 - fConst140);
		fConst143 = std::tan((2624.5462745683112 / fConst0));
		fConst144 = (1.0 / fConst143);
		fConst145 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst143))));
		fConst146 = (0.0 - fConst144);
		fConst147 = std::tan((2893.2541021695852 / fConst0));
		fConst148 = (1.0 / fConst147);
		fConst149 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst147))));
		fConst150 = (0.0 - fConst148);
		fConst151 = std::tan((3189.472931315715 / fConst0));
		fConst152 = (1.0 / fConst151);
		fConst153 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst151))));
		fConst154 = (0.0 - fConst152);
		fConst155 = std::tan((3516.0194094142503 / fConst0));
		fConst156 = (1.0 / fConst155);
		fConst157 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst155))));
		fConst158 = (0.0 - fConst156);
		fConst159 = std::tan((3875.99855951059 / fConst0));
		fConst160 = (1.0 / fConst159);
		fConst161 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst159))));
		fConst162 = (0.0 - fConst160);
		fConst163 = std::tan((4272.8333049307548 / fConst0));
		fConst164 = (1.0 / fConst163);
		fConst165 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst163))));
		fConst166 = (0.0 - fConst164);
		fConst167 = std::tan((4710.2970167333451 / fConst0));
		fConst168 = (1.0 / fConst167);
		fConst169 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst167))));
		fConst170 = (0.0 - fConst168);
		fConst171 = std::tan((5192.5493934537208 / fConst0));
		fConst172 = (1.0 / fConst171);
		fConst173 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst171))));
		fConst174 = (0.0 - fConst172);
		fConst175 = std::tan((5724.176014309076 / fConst0));
		fConst176 = (1.0 / fConst175);
		fConst177 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst175))));
		fConst178 = (0.0 - fConst176);
		fConst179 = std::tan((6310.2319419628202 / fConst0));
		fConst180 = (1.0 / fConst179);
		fConst181 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst179))));
		fConst182 = (0.0 - fConst180);
		fConst183 = std::tan((6956.2897894526277 / fConst0));
		fConst184 = (1.0 / fConst183);
		fConst185 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst183))));
		fConst186 = (0.0 - fConst184);
		fConst187 = std::tan((7668.4927083347447 / fConst0));
		fConst188 = (1.0 / fConst187);
		fConst189 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst187))));
		fConst190 = (0.0 - fConst188);
		fConst191 = std::tan((8453.6128018913969 / fConst0));
		fConst192 = (1.0 / fConst191);
		fConst193 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst191))));
		fConst194 = (0.0 - fConst192);
		fConst195 = std::tan((9319.1155188332741 / fConst0));
		fConst196 = (1.0 / fConst195);
		fConst197 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst195))));
		fConst198 = (0.0 - fConst196);
		fConst199 = std::tan((10273.230639795614 / fConst0));
		fConst200 = (1.0 / fConst199);
		fConst201 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst199))));
		fConst202 = (0.0 - fConst200);
		fConst203 = std::tan((11325.030531615153 / fConst0));
		fConst204 = (1.0 / fConst203);
		fConst205 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst203))));
		fConst206 = (0.0 - fConst204);
		fConst207 = std::tan((12484.516413482084 / fConst0));
		fConst208 = (1.0 / fConst207);
		fConst209 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst207))));
		fConst210 = (0.0 - fConst208);
		fConst211 = std::tan((13762.71345524352 / fConst0));
		fConst212 = (1.0 / fConst211);
		fConst213 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst211))));
		fConst214 = (0.0 - fConst212);
		fConst215 = std::tan((15171.775612116937 / fConst0));
		fConst216 = (1.0 / fConst215);
		fConst217 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst215))));
		fConst218 = (0.0 - fConst216);
		fConst219 = std::tan((16725.101192652364 / fConst0));
		fConst220 = (1.0 / fConst219);
		fConst221 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst219))));
		fConst222 = (0.0 - fConst220);
		fConst223 = std::tan((18437.460258841165 / fConst0));
		fConst224 = (1.0 / fConst223);
		fConst225 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst223))));
		fConst226 = (0.0 - fConst224);
		fConst227 = std::tan((20325.135069776981 / fConst0));
		fConst228 = (1.0 / fConst227);
		fConst229 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst227))));
		fConst230 = (0.0 - fConst228);
		fConst231 = std::tan((22406.074904301538 / fConst0));
		fConst232 = (1.0 / fConst231);
		fConst233 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst231))));
		fConst234 = (0.0 - fConst232);
		fConst235 = std::tan((24700.066734792919 / fConst0));
		fConst236 = (1.0 / fConst235);
		fConst237 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst235))));
		fConst238 = (0.0 - fConst236);
		fConst239 = std::tan((27228.923374977083 / fConst0));
		fConst240 = (1.0 / fConst239);
		fConst241 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst239))));
		fConst242 = (0.0 - fConst240);
		fConst243 = std::tan((30016.690890798494 / fConst0));
		fConst244 = (1.0 / fConst243);
		fConst245 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst243))));
		fConst246 = (0.0 - fConst244);
		fConst247 = std::tan((33089.877246551383 / fConst0));
		fConst248 = (1.0 / fConst247);
		fConst249 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst247))));
		fConst250 = (0.0 - fConst248);
		fConst251 = std::tan((36477.704360392658 / fConst0));
		fConst252 = (1.0 / fConst251);
		fConst253 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst251))));
		fConst254 = (0.0 - fConst252);
		fConst255 = std::tan((40212.385965949354 / fConst0));
		fConst256 = (1.0 / fConst255);
		fConst257 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst255))));
		fConst258 = (0.0 - fConst256);
		
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.5);
		fHslider1 = FAUSTFLOAT(330.0);
		fVslider0 = FAUSTFLOAT(0.5);
		fHslider2 = FAUSTFLOAT(5.0);
		fHslider3 = FAUSTFLOAT(5.0);
		
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0;
			
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec1[l1] = 0.0;
			
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec2[l2] = 0.0;
			
		}
		for (int l3 = 0; (l3 < 3); l3 = (l3 + 1)) {
			fRec0[l3] = 0.0;
			
		}
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec5[l4] = 0.0;
			
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec4[l5] = 0.0;
			
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec3[l6] = 0.0;
			
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec6[l7] = 0.0;
			
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec9[l8] = 0.0;
			
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec8[l9] = 0.0;
			
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec7[l10] = 0.0;
			
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec10[l11] = 0.0;
			
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec13[l12] = 0.0;
			
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec12[l13] = 0.0;
			
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec11[l14] = 0.0;
			
		}
		for (int l15 = 0; (l15 < 3); l15 = (l15 + 1)) {
			fRec14[l15] = 0.0;
			
		}
		for (int l16 = 0; (l16 < 3); l16 = (l16 + 1)) {
			fRec17[l16] = 0.0;
			
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec16[l17] = 0.0;
			
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec15[l18] = 0.0;
			
		}
		for (int l19 = 0; (l19 < 3); l19 = (l19 + 1)) {
			fRec18[l19] = 0.0;
			
		}
		for (int l20 = 0; (l20 < 3); l20 = (l20 + 1)) {
			fRec21[l20] = 0.0;
			
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec20[l21] = 0.0;
			
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec19[l22] = 0.0;
			
		}
		for (int l23 = 0; (l23 < 3); l23 = (l23 + 1)) {
			fRec22[l23] = 0.0;
			
		}
		for (int l24 = 0; (l24 < 3); l24 = (l24 + 1)) {
			fRec25[l24] = 0.0;
			
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec24[l25] = 0.0;
			
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec23[l26] = 0.0;
			
		}
		for (int l27 = 0; (l27 < 3); l27 = (l27 + 1)) {
			fRec26[l27] = 0.0;
			
		}
		for (int l28 = 0; (l28 < 3); l28 = (l28 + 1)) {
			fRec29[l28] = 0.0;
			
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec28[l29] = 0.0;
			
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec27[l30] = 0.0;
			
		}
		for (int l31 = 0; (l31 < 3); l31 = (l31 + 1)) {
			fRec30[l31] = 0.0;
			
		}
		for (int l32 = 0; (l32 < 3); l32 = (l32 + 1)) {
			fRec33[l32] = 0.0;
			
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec32[l33] = 0.0;
			
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec31[l34] = 0.0;
			
		}
		for (int l35 = 0; (l35 < 3); l35 = (l35 + 1)) {
			fRec34[l35] = 0.0;
			
		}
		for (int l36 = 0; (l36 < 3); l36 = (l36 + 1)) {
			fRec37[l36] = 0.0;
			
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec36[l37] = 0.0;
			
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec35[l38] = 0.0;
			
		}
		for (int l39 = 0; (l39 < 3); l39 = (l39 + 1)) {
			fRec38[l39] = 0.0;
			
		}
		for (int l40 = 0; (l40 < 3); l40 = (l40 + 1)) {
			fRec41[l40] = 0.0;
			
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec40[l41] = 0.0;
			
		}
		for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
			fRec39[l42] = 0.0;
			
		}
		for (int l43 = 0; (l43 < 3); l43 = (l43 + 1)) {
			fRec42[l43] = 0.0;
			
		}
		for (int l44 = 0; (l44 < 3); l44 = (l44 + 1)) {
			fRec45[l44] = 0.0;
			
		}
		for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) {
			fRec44[l45] = 0.0;
			
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fRec43[l46] = 0.0;
			
		}
		for (int l47 = 0; (l47 < 3); l47 = (l47 + 1)) {
			fRec46[l47] = 0.0;
			
		}
		for (int l48 = 0; (l48 < 3); l48 = (l48 + 1)) {
			fRec49[l48] = 0.0;
			
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fRec48[l49] = 0.0;
			
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fRec47[l50] = 0.0;
			
		}
		for (int l51 = 0; (l51 < 3); l51 = (l51 + 1)) {
			fRec50[l51] = 0.0;
			
		}
		for (int l52 = 0; (l52 < 3); l52 = (l52 + 1)) {
			fRec53[l52] = 0.0;
			
		}
		for (int l53 = 0; (l53 < 2); l53 = (l53 + 1)) {
			fRec52[l53] = 0.0;
			
		}
		for (int l54 = 0; (l54 < 2); l54 = (l54 + 1)) {
			fRec51[l54] = 0.0;
			
		}
		for (int l55 = 0; (l55 < 3); l55 = (l55 + 1)) {
			fRec54[l55] = 0.0;
			
		}
		for (int l56 = 0; (l56 < 3); l56 = (l56 + 1)) {
			fRec57[l56] = 0.0;
			
		}
		for (int l57 = 0; (l57 < 2); l57 = (l57 + 1)) {
			fRec56[l57] = 0.0;
			
		}
		for (int l58 = 0; (l58 < 2); l58 = (l58 + 1)) {
			fRec55[l58] = 0.0;
			
		}
		for (int l59 = 0; (l59 < 3); l59 = (l59 + 1)) {
			fRec58[l59] = 0.0;
			
		}
		for (int l60 = 0; (l60 < 3); l60 = (l60 + 1)) {
			fRec61[l60] = 0.0;
			
		}
		for (int l61 = 0; (l61 < 2); l61 = (l61 + 1)) {
			fRec60[l61] = 0.0;
			
		}
		for (int l62 = 0; (l62 < 2); l62 = (l62 + 1)) {
			fRec59[l62] = 0.0;
			
		}
		for (int l63 = 0; (l63 < 3); l63 = (l63 + 1)) {
			fRec62[l63] = 0.0;
			
		}
		for (int l64 = 0; (l64 < 3); l64 = (l64 + 1)) {
			fRec65[l64] = 0.0;
			
		}
		for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) {
			fRec64[l65] = 0.0;
			
		}
		for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) {
			fRec63[l66] = 0.0;
			
		}
		for (int l67 = 0; (l67 < 3); l67 = (l67 + 1)) {
			fRec66[l67] = 0.0;
			
		}
		for (int l68 = 0; (l68 < 3); l68 = (l68 + 1)) {
			fRec69[l68] = 0.0;
			
		}
		for (int l69 = 0; (l69 < 2); l69 = (l69 + 1)) {
			fRec68[l69] = 0.0;
			
		}
		for (int l70 = 0; (l70 < 2); l70 = (l70 + 1)) {
			fRec67[l70] = 0.0;
			
		}
		for (int l71 = 0; (l71 < 3); l71 = (l71 + 1)) {
			fRec70[l71] = 0.0;
			
		}
		for (int l72 = 0; (l72 < 3); l72 = (l72 + 1)) {
			fRec73[l72] = 0.0;
			
		}
		for (int l73 = 0; (l73 < 2); l73 = (l73 + 1)) {
			fRec72[l73] = 0.0;
			
		}
		for (int l74 = 0; (l74 < 2); l74 = (l74 + 1)) {
			fRec71[l74] = 0.0;
			
		}
		for (int l75 = 0; (l75 < 3); l75 = (l75 + 1)) {
			fRec74[l75] = 0.0;
			
		}
		for (int l76 = 0; (l76 < 3); l76 = (l76 + 1)) {
			fRec77[l76] = 0.0;
			
		}
		for (int l77 = 0; (l77 < 2); l77 = (l77 + 1)) {
			fRec76[l77] = 0.0;
			
		}
		for (int l78 = 0; (l78 < 2); l78 = (l78 + 1)) {
			fRec75[l78] = 0.0;
			
		}
		for (int l79 = 0; (l79 < 3); l79 = (l79 + 1)) {
			fRec78[l79] = 0.0;
			
		}
		for (int l80 = 0; (l80 < 3); l80 = (l80 + 1)) {
			fRec81[l80] = 0.0;
			
		}
		for (int l81 = 0; (l81 < 2); l81 = (l81 + 1)) {
			fRec80[l81] = 0.0;
			
		}
		for (int l82 = 0; (l82 < 2); l82 = (l82 + 1)) {
			fRec79[l82] = 0.0;
			
		}
		for (int l83 = 0; (l83 < 3); l83 = (l83 + 1)) {
			fRec82[l83] = 0.0;
			
		}
		for (int l84 = 0; (l84 < 3); l84 = (l84 + 1)) {
			fRec85[l84] = 0.0;
			
		}
		for (int l85 = 0; (l85 < 2); l85 = (l85 + 1)) {
			fRec84[l85] = 0.0;
			
		}
		for (int l86 = 0; (l86 < 2); l86 = (l86 + 1)) {
			fRec83[l86] = 0.0;
			
		}
		for (int l87 = 0; (l87 < 3); l87 = (l87 + 1)) {
			fRec86[l87] = 0.0;
			
		}
		for (int l88 = 0; (l88 < 3); l88 = (l88 + 1)) {
			fRec89[l88] = 0.0;
			
		}
		for (int l89 = 0; (l89 < 2); l89 = (l89 + 1)) {
			fRec88[l89] = 0.0;
			
		}
		for (int l90 = 0; (l90 < 2); l90 = (l90 + 1)) {
			fRec87[l90] = 0.0;
			
		}
		for (int l91 = 0; (l91 < 3); l91 = (l91 + 1)) {
			fRec90[l91] = 0.0;
			
		}
		for (int l92 = 0; (l92 < 3); l92 = (l92 + 1)) {
			fRec93[l92] = 0.0;
			
		}
		for (int l93 = 0; (l93 < 2); l93 = (l93 + 1)) {
			fRec92[l93] = 0.0;
			
		}
		for (int l94 = 0; (l94 < 2); l94 = (l94 + 1)) {
			fRec91[l94] = 0.0;
			
		}
		for (int l95 = 0; (l95 < 3); l95 = (l95 + 1)) {
			fRec94[l95] = 0.0;
			
		}
		for (int l96 = 0; (l96 < 3); l96 = (l96 + 1)) {
			fRec97[l96] = 0.0;
			
		}
		for (int l97 = 0; (l97 < 2); l97 = (l97 + 1)) {
			fRec96[l97] = 0.0;
			
		}
		for (int l98 = 0; (l98 < 2); l98 = (l98 + 1)) {
			fRec95[l98] = 0.0;
			
		}
		for (int l99 = 0; (l99 < 3); l99 = (l99 + 1)) {
			fRec98[l99] = 0.0;
			
		}
		for (int l100 = 0; (l100 < 3); l100 = (l100 + 1)) {
			fRec101[l100] = 0.0;
			
		}
		for (int l101 = 0; (l101 < 2); l101 = (l101 + 1)) {
			fRec100[l101] = 0.0;
			
		}
		for (int l102 = 0; (l102 < 2); l102 = (l102 + 1)) {
			fRec99[l102] = 0.0;
			
		}
		for (int l103 = 0; (l103 < 3); l103 = (l103 + 1)) {
			fRec102[l103] = 0.0;
			
		}
		for (int l104 = 0; (l104 < 3); l104 = (l104 + 1)) {
			fRec105[l104] = 0.0;
			
		}
		for (int l105 = 0; (l105 < 2); l105 = (l105 + 1)) {
			fRec104[l105] = 0.0;
			
		}
		for (int l106 = 0; (l106 < 2); l106 = (l106 + 1)) {
			fRec103[l106] = 0.0;
			
		}
		for (int l107 = 0; (l107 < 3); l107 = (l107 + 1)) {
			fRec106[l107] = 0.0;
			
		}
		for (int l108 = 0; (l108 < 3); l108 = (l108 + 1)) {
			fRec109[l108] = 0.0;
			
		}
		for (int l109 = 0; (l109 < 2); l109 = (l109 + 1)) {
			fRec108[l109] = 0.0;
			
		}
		for (int l110 = 0; (l110 < 2); l110 = (l110 + 1)) {
			fRec107[l110] = 0.0;
			
		}
		for (int l111 = 0; (l111 < 3); l111 = (l111 + 1)) {
			fRec110[l111] = 0.0;
			
		}
		for (int l112 = 0; (l112 < 3); l112 = (l112 + 1)) {
			fRec113[l112] = 0.0;
			
		}
		for (int l113 = 0; (l113 < 2); l113 = (l113 + 1)) {
			fRec112[l113] = 0.0;
			
		}
		for (int l114 = 0; (l114 < 2); l114 = (l114 + 1)) {
			fRec111[l114] = 0.0;
			
		}
		for (int l115 = 0; (l115 < 3); l115 = (l115 + 1)) {
			fRec114[l115] = 0.0;
			
		}
		for (int l116 = 0; (l116 < 3); l116 = (l116 + 1)) {
			fRec117[l116] = 0.0;
			
		}
		for (int l117 = 0; (l117 < 2); l117 = (l117 + 1)) {
			fRec116[l117] = 0.0;
			
		}
		for (int l118 = 0; (l118 < 2); l118 = (l118 + 1)) {
			fRec115[l118] = 0.0;
			
		}
		for (int l119 = 0; (l119 < 3); l119 = (l119 + 1)) {
			fRec118[l119] = 0.0;
			
		}
		for (int l120 = 0; (l120 < 3); l120 = (l120 + 1)) {
			fRec121[l120] = 0.0;
			
		}
		for (int l121 = 0; (l121 < 2); l121 = (l121 + 1)) {
			fRec120[l121] = 0.0;
			
		}
		for (int l122 = 0; (l122 < 2); l122 = (l122 + 1)) {
			fRec119[l122] = 0.0;
			
		}
		for (int l123 = 0; (l123 < 3); l123 = (l123 + 1)) {
			fRec122[l123] = 0.0;
			
		}
		for (int l124 = 0; (l124 < 3); l124 = (l124 + 1)) {
			fRec125[l124] = 0.0;
			
		}
		for (int l125 = 0; (l125 < 2); l125 = (l125 + 1)) {
			fRec124[l125] = 0.0;
			
		}
		for (int l126 = 0; (l126 < 2); l126 = (l126 + 1)) {
			fRec123[l126] = 0.0;
			
		}
		for (int l127 = 0; (l127 < 3); l127 = (l127 + 1)) {
			fRec126[l127] = 0.0;
			
		}
		for (int l128 = 0; (l128 < 3); l128 = (l128 + 1)) {
			fRec129[l128] = 0.0;
			
		}
		for (int l129 = 0; (l129 < 2); l129 = (l129 + 1)) {
			fRec128[l129] = 0.0;
			
		}
		for (int l130 = 0; (l130 < 2); l130 = (l130 + 1)) {
			fRec127[l130] = 0.0;
			
		}
		for (int l131 = 0; (l131 < 3); l131 = (l131 + 1)) {
			fRec130[l131] = 0.0;
			
		}
		for (int l132 = 0; (l132 < 3); l132 = (l132 + 1)) {
			fRec133[l132] = 0.0;
			
		}
		for (int l133 = 0; (l133 < 2); l133 = (l133 + 1)) {
			fRec132[l133] = 0.0;
			
		}
		for (int l134 = 0; (l134 < 2); l134 = (l134 + 1)) {
			fRec131[l134] = 0.0;
			
		}
		for (int l135 = 0; (l135 < 3); l135 = (l135 + 1)) {
			fRec134[l135] = 0.0;
			
		}
		for (int l136 = 0; (l136 < 3); l136 = (l136 + 1)) {
			fRec137[l136] = 0.0;
			
		}
		for (int l137 = 0; (l137 < 2); l137 = (l137 + 1)) {
			fRec136[l137] = 0.0;
			
		}
		for (int l138 = 0; (l138 < 2); l138 = (l138 + 1)) {
			fRec135[l138] = 0.0;
			
		}
		for (int l139 = 0; (l139 < 3); l139 = (l139 + 1)) {
			fRec138[l139] = 0.0;
			
		}
		for (int l140 = 0; (l140 < 3); l140 = (l140 + 1)) {
			fRec141[l140] = 0.0;
			
		}
		for (int l141 = 0; (l141 < 2); l141 = (l141 + 1)) {
			fRec140[l141] = 0.0;
			
		}
		for (int l142 = 0; (l142 < 2); l142 = (l142 + 1)) {
			fRec139[l142] = 0.0;
			
		}
		for (int l143 = 0; (l143 < 3); l143 = (l143 + 1)) {
			fRec142[l143] = 0.0;
			
		}
		for (int l144 = 0; (l144 < 3); l144 = (l144 + 1)) {
			fRec145[l144] = 0.0;
			
		}
		for (int l145 = 0; (l145 < 2); l145 = (l145 + 1)) {
			fRec144[l145] = 0.0;
			
		}
		for (int l146 = 0; (l146 < 2); l146 = (l146 + 1)) {
			fRec143[l146] = 0.0;
			
		}
		for (int l147 = 0; (l147 < 3); l147 = (l147 + 1)) {
			fRec146[l147] = 0.0;
			
		}
		for (int l148 = 0; (l148 < 3); l148 = (l148 + 1)) {
			fRec149[l148] = 0.0;
			
		}
		for (int l149 = 0; (l149 < 2); l149 = (l149 + 1)) {
			fRec148[l149] = 0.0;
			
		}
		for (int l150 = 0; (l150 < 2); l150 = (l150 + 1)) {
			fRec147[l150] = 0.0;
			
		}
		for (int l151 = 0; (l151 < 3); l151 = (l151 + 1)) {
			fRec150[l151] = 0.0;
			
		}
		for (int l152 = 0; (l152 < 3); l152 = (l152 + 1)) {
			fRec153[l152] = 0.0;
			
		}
		for (int l153 = 0; (l153 < 2); l153 = (l153 + 1)) {
			fRec152[l153] = 0.0;
			
		}
		for (int l154 = 0; (l154 < 2); l154 = (l154 + 1)) {
			fRec151[l154] = 0.0;
			
		}
		for (int l155 = 0; (l155 < 3); l155 = (l155 + 1)) {
			fRec154[l155] = 0.0;
			
		}
		for (int l156 = 0; (l156 < 3); l156 = (l156 + 1)) {
			fRec157[l156] = 0.0;
			
		}
		for (int l157 = 0; (l157 < 2); l157 = (l157 + 1)) {
			fRec156[l157] = 0.0;
			
		}
		for (int l158 = 0; (l158 < 2); l158 = (l158 + 1)) {
			fRec155[l158] = 0.0;
			
		}
		for (int l159 = 0; (l159 < 3); l159 = (l159 + 1)) {
			fRec158[l159] = 0.0;
			
		}
		for (int l160 = 0; (l160 < 3); l160 = (l160 + 1)) {
			fRec161[l160] = 0.0;
			
		}
		for (int l161 = 0; (l161 < 2); l161 = (l161 + 1)) {
			fRec160[l161] = 0.0;
			
		}
		for (int l162 = 0; (l162 < 2); l162 = (l162 + 1)) {
			fRec159[l162] = 0.0;
			
		}
		for (int l163 = 0; (l163 < 3); l163 = (l163 + 1)) {
			fRec162[l163] = 0.0;
			
		}
		for (int l164 = 0; (l164 < 3); l164 = (l164 + 1)) {
			fRec165[l164] = 0.0;
			
		}
		for (int l165 = 0; (l165 < 2); l165 = (l165 + 1)) {
			fRec164[l165] = 0.0;
			
		}
		for (int l166 = 0; (l166 < 2); l166 = (l166 + 1)) {
			fRec163[l166] = 0.0;
			
		}
		for (int l167 = 0; (l167 < 3); l167 = (l167 + 1)) {
			fRec168[l167] = 0.0;
			
		}
		for (int l168 = 0; (l168 < 2); l168 = (l168 + 1)) {
			fRec167[l168] = 0.0;
			
		}
		for (int l169 = 0; (l169 < 2); l169 = (l169 + 1)) {
			fRec166[l169] = 0.0;
			
		}
		for (int l170 = 0; (l170 < 3); l170 = (l170 + 1)) {
			fRec169[l170] = 0.0;
			
		}
		for (int l171 = 0; (l171 < 3); l171 = (l171 + 1)) {
			fRec172[l171] = 0.0;
			
		}
		for (int l172 = 0; (l172 < 2); l172 = (l172 + 1)) {
			fRec171[l172] = 0.0;
			
		}
		for (int l173 = 0; (l173 < 2); l173 = (l173 + 1)) {
			fRec170[l173] = 0.0;
			
		}
		for (int l174 = 0; (l174 < 3); l174 = (l174 + 1)) {
			fRec173[l174] = 0.0;
			
		}
		for (int l175 = 0; (l175 < 3); l175 = (l175 + 1)) {
			fRec176[l175] = 0.0;
			
		}
		for (int l176 = 0; (l176 < 2); l176 = (l176 + 1)) {
			fRec175[l176] = 0.0;
			
		}
		for (int l177 = 0; (l177 < 2); l177 = (l177 + 1)) {
			fRec174[l177] = 0.0;
			
		}
		for (int l178 = 0; (l178 < 3); l178 = (l178 + 1)) {
			fRec177[l178] = 0.0;
			
		}
		for (int l179 = 0; (l179 < 3); l179 = (l179 + 1)) {
			fRec180[l179] = 0.0;
			
		}
		for (int l180 = 0; (l180 < 2); l180 = (l180 + 1)) {
			fRec179[l180] = 0.0;
			
		}
		for (int l181 = 0; (l181 < 2); l181 = (l181 + 1)) {
			fRec178[l181] = 0.0;
			
		}
		for (int l182 = 0; (l182 < 3); l182 = (l182 + 1)) {
			fRec181[l182] = 0.0;
			
		}
		for (int l183 = 0; (l183 < 3); l183 = (l183 + 1)) {
			fRec184[l183] = 0.0;
			
		}
		for (int l184 = 0; (l184 < 2); l184 = (l184 + 1)) {
			fRec183[l184] = 0.0;
			
		}
		for (int l185 = 0; (l185 < 2); l185 = (l185 + 1)) {
			fRec182[l185] = 0.0;
			
		}
		for (int l186 = 0; (l186 < 3); l186 = (l186 + 1)) {
			fRec185[l186] = 0.0;
			
		}
		for (int l187 = 0; (l187 < 3); l187 = (l187 + 1)) {
			fRec188[l187] = 0.0;
			
		}
		for (int l188 = 0; (l188 < 2); l188 = (l188 + 1)) {
			fRec187[l188] = 0.0;
			
		}
		for (int l189 = 0; (l189 < 2); l189 = (l189 + 1)) {
			fRec186[l189] = 0.0;
			
		}
		for (int l190 = 0; (l190 < 3); l190 = (l190 + 1)) {
			fRec189[l190] = 0.0;
			
		}
		for (int l191 = 0; (l191 < 3); l191 = (l191 + 1)) {
			fRec192[l191] = 0.0;
			
		}
		for (int l192 = 0; (l192 < 2); l192 = (l192 + 1)) {
			fRec191[l192] = 0.0;
			
		}
		for (int l193 = 0; (l193 < 2); l193 = (l193 + 1)) {
			fRec190[l193] = 0.0;
			
		}
		for (int l194 = 0; (l194 < 3); l194 = (l194 + 1)) {
			fRec193[l194] = 0.0;
			
		}
		for (int l195 = 0; (l195 < 3); l195 = (l195 + 1)) {
			fRec196[l195] = 0.0;
			
		}
		for (int l196 = 0; (l196 < 2); l196 = (l196 + 1)) {
			fRec195[l196] = 0.0;
			
		}
		for (int l197 = 0; (l197 < 2); l197 = (l197 + 1)) {
			fRec194[l197] = 0.0;
			
		}
		for (int l198 = 0; (l198 < 3); l198 = (l198 + 1)) {
			fRec197[l198] = 0.0;
			
		}
		for (int l199 = 0; (l199 < 3); l199 = (l199 + 1)) {
			fRec200[l199] = 0.0;
			
		}
		for (int l200 = 0; (l200 < 2); l200 = (l200 + 1)) {
			fRec199[l200] = 0.0;
			
		}
		for (int l201 = 0; (l201 < 2); l201 = (l201 + 1)) {
			fRec198[l201] = 0.0;
			
		}
		for (int l202 = 0; (l202 < 3); l202 = (l202 + 1)) {
			fRec201[l202] = 0.0;
			
		}
		for (int l203 = 0; (l203 < 3); l203 = (l203 + 1)) {
			fRec204[l203] = 0.0;
			
		}
		for (int l204 = 0; (l204 < 2); l204 = (l204 + 1)) {
			fRec203[l204] = 0.0;
			
		}
		for (int l205 = 0; (l205 < 2); l205 = (l205 + 1)) {
			fRec202[l205] = 0.0;
			
		}
		for (int l206 = 0; (l206 < 3); l206 = (l206 + 1)) {
			fRec205[l206] = 0.0;
			
		}
		for (int l207 = 0; (l207 < 3); l207 = (l207 + 1)) {
			fRec208[l207] = 0.0;
			
		}
		for (int l208 = 0; (l208 < 2); l208 = (l208 + 1)) {
			fRec207[l208] = 0.0;
			
		}
		for (int l209 = 0; (l209 < 2); l209 = (l209 + 1)) {
			fRec206[l209] = 0.0;
			
		}
		for (int l210 = 0; (l210 < 3); l210 = (l210 + 1)) {
			fRec209[l210] = 0.0;
			
		}
		for (int l211 = 0; (l211 < 3); l211 = (l211 + 1)) {
			fRec212[l211] = 0.0;
			
		}
		for (int l212 = 0; (l212 < 2); l212 = (l212 + 1)) {
			fRec211[l212] = 0.0;
			
		}
		for (int l213 = 0; (l213 < 2); l213 = (l213 + 1)) {
			fRec210[l213] = 0.0;
			
		}
		for (int l214 = 0; (l214 < 3); l214 = (l214 + 1)) {
			fRec213[l214] = 0.0;
			
		}
		for (int l215 = 0; (l215 < 3); l215 = (l215 + 1)) {
			fRec216[l215] = 0.0;
			
		}
		for (int l216 = 0; (l216 < 2); l216 = (l216 + 1)) {
			fRec215[l216] = 0.0;
			
		}
		for (int l217 = 0; (l217 < 2); l217 = (l217 + 1)) {
			fRec214[l217] = 0.0;
			
		}
		for (int l218 = 0; (l218 < 3); l218 = (l218 + 1)) {
			fRec217[l218] = 0.0;
			
		}
		for (int l219 = 0; (l219 < 3); l219 = (l219 + 1)) {
			fRec220[l219] = 0.0;
			
		}
		for (int l220 = 0; (l220 < 2); l220 = (l220 + 1)) {
			fRec219[l220] = 0.0;
			
		}
		for (int l221 = 0; (l221 < 2); l221 = (l221 + 1)) {
			fRec218[l221] = 0.0;
			
		}
		for (int l222 = 0; (l222 < 3); l222 = (l222 + 1)) {
			fRec221[l222] = 0.0;
			
		}
		for (int l223 = 0; (l223 < 3); l223 = (l223 + 1)) {
			fRec222[l223] = 0.0;
			
		}
		for (int l224 = 0; (l224 < 3); l224 = (l224 + 1)) {
			fRec225[l224] = 0.0;
			
		}
		for (int l225 = 0; (l225 < 2); l225 = (l225 + 1)) {
			fRec224[l225] = 0.0;
			
		}
		for (int l226 = 0; (l226 < 2); l226 = (l226 + 1)) {
			fRec223[l226] = 0.0;
			
		}
		for (int l227 = 0; (l227 < 3); l227 = (l227 + 1)) {
			fRec226[l227] = 0.0;
			
		}
		for (int l228 = 0; (l228 < 3); l228 = (l228 + 1)) {
			fRec229[l228] = 0.0;
			
		}
		for (int l229 = 0; (l229 < 2); l229 = (l229 + 1)) {
			fRec228[l229] = 0.0;
			
		}
		for (int l230 = 0; (l230 < 2); l230 = (l230 + 1)) {
			fRec227[l230] = 0.0;
			
		}
		for (int l231 = 0; (l231 < 3); l231 = (l231 + 1)) {
			fRec230[l231] = 0.0;
			
		}
		for (int l232 = 0; (l232 < 3); l232 = (l232 + 1)) {
			fRec233[l232] = 0.0;
			
		}
		for (int l233 = 0; (l233 < 2); l233 = (l233 + 1)) {
			fRec232[l233] = 0.0;
			
		}
		for (int l234 = 0; (l234 < 2); l234 = (l234 + 1)) {
			fRec231[l234] = 0.0;
			
		}
		for (int l235 = 0; (l235 < 3); l235 = (l235 + 1)) {
			fRec234[l235] = 0.0;
			
		}
		for (int l236 = 0; (l236 < 3); l236 = (l236 + 1)) {
			fRec237[l236] = 0.0;
			
		}
		for (int l237 = 0; (l237 < 2); l237 = (l237 + 1)) {
			fRec236[l237] = 0.0;
			
		}
		for (int l238 = 0; (l238 < 2); l238 = (l238 + 1)) {
			fRec235[l238] = 0.0;
			
		}
		for (int l239 = 0; (l239 < 3); l239 = (l239 + 1)) {
			fRec238[l239] = 0.0;
			
		}
		for (int l240 = 0; (l240 < 3); l240 = (l240 + 1)) {
			fRec241[l240] = 0.0;
			
		}
		for (int l241 = 0; (l241 < 2); l241 = (l241 + 1)) {
			fRec240[l241] = 0.0;
			
		}
		for (int l242 = 0; (l242 < 2); l242 = (l242 + 1)) {
			fRec239[l242] = 0.0;
			
		}
		for (int l243 = 0; (l243 < 3); l243 = (l243 + 1)) {
			fRec242[l243] = 0.0;
			
		}
		for (int l244 = 0; (l244 < 3); l244 = (l244 + 1)) {
			fRec245[l244] = 0.0;
			
		}
		for (int l245 = 0; (l245 < 2); l245 = (l245 + 1)) {
			fRec244[l245] = 0.0;
			
		}
		for (int l246 = 0; (l246 < 2); l246 = (l246 + 1)) {
			fRec243[l246] = 0.0;
			
		}
		for (int l247 = 0; (l247 < 3); l247 = (l247 + 1)) {
			fRec246[l247] = 0.0;
			
		}
		for (int l248 = 0; (l248 < 3); l248 = (l248 + 1)) {
			fRec249[l248] = 0.0;
			
		}
		for (int l249 = 0; (l249 < 2); l249 = (l249 + 1)) {
			fRec248[l249] = 0.0;
			
		}
		for (int l250 = 0; (l250 < 2); l250 = (l250 + 1)) {
			fRec247[l250] = 0.0;
			
		}
		for (int l251 = 0; (l251 < 3); l251 = (l251 + 1)) {
			fRec250[l251] = 0.0;
			
		}
		for (int l252 = 0; (l252 < 3); l252 = (l252 + 1)) {
			fRec253[l252] = 0.0;
			
		}
		for (int l253 = 0; (l253 < 2); l253 = (l253 + 1)) {
			fRec252[l253] = 0.0;
			
		}
		for (int l254 = 0; (l254 < 2); l254 = (l254 + 1)) {
			fRec251[l254] = 0.0;
			
		}
		for (int l255 = 0; (l255 < 3); l255 = (l255 + 1)) {
			fRec254[l255] = 0.0;
			
		}
		for (int l256 = 0; (l256 < 3); l256 = (l256 + 1)) {
			fRec257[l256] = 0.0;
			
		}
		for (int l257 = 0; (l257 < 2); l257 = (l257 + 1)) {
			fRec256[l257] = 0.0;
			
		}
		for (int l258 = 0; (l258 < 2); l258 = (l258 + 1)) {
			fRec255[l258] = 0.0;
			
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
		ui_interface->openHorizontalBox("faustVocoder");
		ui_interface->openVerticalBox("Excitation");
		ui_interface->declare(&fHslider1, "0", "");
		ui_interface->declare(&fHslider1, "style", "knob");
		ui_interface->addHorizontalSlider("Freq", &fHslider1, 330.0, 50.0, 2000.0, 0.10000000000000001);
		ui_interface->declare(&fVslider0, "1", "");
		ui_interface->addVerticalSlider("Gain", &fVslider0, 0.5, 0.0, 1.0, 0.01);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Vocoder");
		ui_interface->declare(&fHslider2, "0", "");
		ui_interface->declare(&fHslider2, "style", "knob");
		ui_interface->declare(&fHslider2, "tooltip", "Attack time in seconds");
		ui_interface->addHorizontalSlider("Attack", &fHslider2, 5.0, 0.10000000000000001, 100.0, 0.10000000000000001);
		ui_interface->declare(&fHslider3, "1", "");
		ui_interface->declare(&fHslider3, "style", "knob");
		ui_interface->declare(&fHslider3, "tooltip", "Release time in seconds");
		ui_interface->addHorizontalSlider("Release", &fHslider3, 5.0, 0.10000000000000001, 100.0, 0.10000000000000001);
		ui_interface->declare(&fHslider0, "2", "");
		ui_interface->declare(&fHslider0, "style", "knob");
		ui_interface->declare(&fHslider0, "tooltip", "Coefficient to adjust the   bandwidth of each band");
		ui_interface->addHorizontalSlider("BW", &fHslider0, 0.5, 0.10000000000000001, 2.0, 0.001);
		ui_interface->closeBox();
		ui_interface->closeBox();
		
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		double fSlow0 = double(fHslider0);
		double fSlow1 = (0.0928739122498006 * fSlow0);
		double fSlow2 = (1.0 / ((fConst2 * (fConst2 + fSlow1)) + 1.0));
		double fSlow3 = double(fHslider1);
		double fSlow4 = (0.0010000000000000009 * double(fVslider0));
		double fSlow5 = ((fConst2 * (fConst2 - fSlow1)) + 1.0);
		double fSlow6 = std::exp((0.0 - (fConst6 / double(fHslider2))));
		double fSlow7 = std::exp((0.0 - (fConst6 / double(fHslider3))));
		double fSlow8 = (0.092873912249800683 * fSlow0);
		double fSlow9 = (1.0 / ((fConst8 * (fConst8 + fSlow8)) + 1.0));
		double fSlow10 = ((fConst8 * (fConst8 - fSlow8)) + 1.0);
		double fSlow11 = (0.092873912249800461 * fSlow0);
		double fSlow12 = (1.0 / ((fConst12 * (fConst12 + fSlow11)) + 1.0));
		double fSlow13 = ((fConst12 * (fConst12 - fSlow11)) + 1.0);
		double fSlow14 = (1.0 / ((fConst16 * (fConst16 + fSlow8)) + 1.0));
		double fSlow15 = ((fConst16 * (fConst16 - fSlow8)) + 1.0);
		double fSlow16 = (0.092873912249800739 * fSlow0);
		double fSlow17 = (1.0 / ((fConst20 * (fConst20 + fSlow16)) + 1.0));
		double fSlow18 = ((fConst20 * (fConst20 - fSlow16)) + 1.0);
		double fSlow19 = (0.092873912249800544 * fSlow0);
		double fSlow20 = (1.0 / ((fConst24 * (fConst24 + fSlow19)) + 1.0));
		double fSlow21 = ((fConst24 * (fConst24 - fSlow19)) + 1.0);
		double fSlow22 = (0.092873912249800655 * fSlow0);
		double fSlow23 = (1.0 / ((fConst28 * (fConst28 + fSlow22)) + 1.0));
		double fSlow24 = ((fConst28 * (fConst28 - fSlow22)) + 1.0);
		double fSlow25 = (0.092873912249800614 * fSlow0);
		double fSlow26 = (1.0 / ((fConst32 * (fConst32 + fSlow25)) + 1.0));
		double fSlow27 = ((fConst32 * (fConst32 - fSlow25)) + 1.0);
		double fSlow28 = (0.092873912249800517 * fSlow0);
		double fSlow29 = (1.0 / ((fConst36 * (fConst36 + fSlow28)) + 1.0));
		double fSlow30 = ((fConst36 * (fConst36 - fSlow28)) + 1.0);
		double fSlow31 = (0.092873912249800822 * fSlow0);
		double fSlow32 = (1.0 / ((fConst40 * (fConst40 + fSlow31)) + 1.0));
		double fSlow33 = ((fConst40 * (fConst40 - fSlow31)) + 1.0);
		double fSlow34 = (1.0 / ((fConst44 * (fConst44 + fSlow19)) + 1.0));
		double fSlow35 = ((fConst44 * (fConst44 - fSlow19)) + 1.0);
		double fSlow36 = (0.092873912249800503 * fSlow0);
		double fSlow37 = (1.0 / ((fConst48 * (fConst48 + fSlow36)) + 1.0));
		double fSlow38 = ((fConst48 * (fConst48 - fSlow36)) + 1.0);
		double fSlow39 = (0.092873912249800752 * fSlow0);
		double fSlow40 = (1.0 / ((fConst52 * (fConst52 + fSlow39)) + 1.0));
		double fSlow41 = ((fConst52 * (fConst52 - fSlow39)) + 1.0);
		double fSlow42 = (1.0 / ((fConst56 * (fConst56 + fSlow19)) + 1.0));
		double fSlow43 = ((fConst56 * (fConst56 - fSlow19)) + 1.0);
		double fSlow44 = (0.092873912249800725 * fSlow0);
		double fSlow45 = (1.0 / ((fConst60 * (fConst60 + fSlow44)) + 1.0));
		double fSlow46 = ((fConst60 * (fConst60 - fSlow44)) + 1.0);
		double fSlow47 = (1.0 / ((fConst64 * (fConst64 + fSlow19)) + 1.0));
		double fSlow48 = ((fConst64 * (fConst64 - fSlow19)) + 1.0);
		double fSlow49 = (1.0 / ((fConst68 * (fConst68 + fSlow1)) + 1.0));
		double fSlow50 = ((fConst68 * (fConst68 - fSlow1)) + 1.0);
		double fSlow51 = (1.0 / ((fConst72 * (fConst72 + fSlow39)) + 1.0));
		double fSlow52 = ((fConst72 * (fConst72 - fSlow39)) + 1.0);
		double fSlow53 = (1.0 / ((fConst76 * (fConst76 + fSlow28)) + 1.0));
		double fSlow54 = ((fConst76 * (fConst76 - fSlow28)) + 1.0);
		double fSlow55 = (0.092873912249800641 * fSlow0);
		double fSlow56 = (1.0 / ((fConst80 * (fConst80 + fSlow55)) + 1.0));
		double fSlow57 = ((fConst80 * (fConst80 - fSlow55)) + 1.0);
		double fSlow58 = (1.0 / ((fConst84 * (fConst84 + fSlow36)) + 1.0));
		double fSlow59 = ((fConst84 * (fConst84 - fSlow36)) + 1.0);
		double fSlow60 = (0.09287391224980085 * fSlow0);
		double fSlow61 = (1.0 / ((fConst88 * (fConst88 + fSlow60)) + 1.0));
		double fSlow62 = ((fConst88 * (fConst88 - fSlow60)) + 1.0);
		double fSlow63 = (0.092873912249800447 * fSlow0);
		double fSlow64 = (1.0 / ((fConst92 * (fConst92 + fSlow63)) + 1.0));
		double fSlow65 = ((fConst92 * (fConst92 - fSlow63)) + 1.0);
		double fSlow66 = (0.092873912249800586 * fSlow0);
		double fSlow67 = (1.0 / ((fConst96 * (fConst96 + fSlow66)) + 1.0));
		double fSlow68 = ((fConst96 * (fConst96 - fSlow66)) + 1.0);
		double fSlow69 = (0.092873912249800794 * fSlow0);
		double fSlow70 = (1.0 / ((fConst100 * (fConst100 + fSlow69)) + 1.0));
		double fSlow71 = ((fConst100 * (fConst100 - fSlow69)) + 1.0);
		double fSlow72 = (1.0 / ((fConst104 * (fConst104 + fSlow66)) + 1.0));
		double fSlow73 = ((fConst104 * (fConst104 - fSlow66)) + 1.0);
		double fSlow74 = (1.0 / ((fConst108 * (fConst108 + fSlow66)) + 1.0));
		double fSlow75 = ((fConst108 * (fConst108 - fSlow66)) + 1.0);
		double fSlow76 = (1.0 / ((fConst112 * (fConst112 + fSlow22)) + 1.0));
		double fSlow77 = ((fConst112 * (fConst112 - fSlow22)) + 1.0);
		double fSlow78 = (1.0 / ((fConst116 * (fConst116 + fSlow1)) + 1.0));
		double fSlow79 = ((fConst116 * (fConst116 - fSlow1)) + 1.0);
		double fSlow80 = (1.0 / ((fConst120 * (fConst120 + fSlow22)) + 1.0));
		double fSlow81 = ((fConst120 * (fConst120 - fSlow22)) + 1.0);
		double fSlow82 = (0.092873912249800489 * fSlow0);
		double fSlow83 = (1.0 / ((fConst124 * (fConst124 + fSlow82)) + 1.0));
		double fSlow84 = ((fConst124 * (fConst124 - fSlow82)) + 1.0);
		double fSlow85 = (0.092873912249800766 * fSlow0);
		double fSlow86 = (1.0 / ((fConst128 * (fConst128 + fSlow85)) + 1.0));
		double fSlow87 = ((fConst128 * (fConst128 - fSlow85)) + 1.0);
		double fSlow88 = (0.09287391224980053 * fSlow0);
		double fSlow89 = (1.0 / ((fConst132 * (fConst132 + fSlow88)) + 1.0));
		double fSlow90 = ((fConst132 * (fConst132 - fSlow88)) + 1.0);
		double fSlow91 = (1.0 / ((fConst136 * (fConst136 + fSlow25)) + 1.0));
		double fSlow92 = ((fConst136 * (fConst136 - fSlow25)) + 1.0);
		double fSlow93 = (1.0 / ((fConst140 * (fConst140 + fSlow55)) + 1.0));
		double fSlow94 = ((fConst140 * (fConst140 - fSlow55)) + 1.0);
		double fSlow95 = (1.0 / ((fConst144 * (fConst144 + fSlow88)) + 1.0));
		double fSlow96 = ((fConst144 * (fConst144 - fSlow88)) + 1.0);
		double fSlow97 = (1.0 / ((fConst148 * (fConst148 + fSlow8)) + 1.0));
		double fSlow98 = ((fConst148 * (fConst148 - fSlow8)) + 1.0);
		double fSlow99 = (1.0 / ((fConst152 * (fConst152 + fSlow55)) + 1.0));
		double fSlow100 = ((fConst152 * (fConst152 - fSlow55)) + 1.0);
		double fSlow101 = (1.0 / ((fConst156 * (fConst156 + fSlow16)) + 1.0));
		double fSlow102 = ((fConst156 * (fConst156 - fSlow16)) + 1.0);
		double fSlow103 = (0.092873912249800475 * fSlow0);
		double fSlow104 = (1.0 / ((fConst160 * (fConst160 + fSlow103)) + 1.0));
		double fSlow105 = ((fConst160 * (fConst160 - fSlow103)) + 1.0);
		double fSlow106 = (0.092873912249800669 * fSlow0);
		double fSlow107 = (1.0 / ((fConst164 * (fConst164 + fSlow106)) + 1.0));
		double fSlow108 = ((fConst164 * (fConst164 - fSlow106)) + 1.0);
		double fSlow109 = (0.092873912249800628 * fSlow0);
		double fSlow110 = (1.0 / ((fConst168 * (fConst168 + fSlow109)) + 1.0));
		double fSlow111 = ((fConst168 * (fConst168 - fSlow109)) + 1.0);
		double fSlow112 = (1.0 / ((fConst172 * (fConst172 + fSlow19)) + 1.0));
		double fSlow113 = ((fConst172 * (fConst172 - fSlow19)) + 1.0);
		double fSlow114 = (1.0 / ((fConst176 * (fConst176 + fSlow106)) + 1.0));
		double fSlow115 = ((fConst176 * (fConst176 - fSlow106)) + 1.0);
		double fSlow116 = (1.0 / ((fConst180 * (fConst180 + fSlow106)) + 1.0));
		double fSlow117 = ((fConst180 * (fConst180 - fSlow106)) + 1.0);
		double fSlow118 = (1.0 / ((fConst184 * (fConst184 + fSlow55)) + 1.0));
		double fSlow119 = ((fConst184 * (fConst184 - fSlow55)) + 1.0);
		double fSlow120 = (1.0 / ((fConst188 * (fConst188 + fSlow1)) + 1.0));
		double fSlow121 = ((fConst188 * (fConst188 - fSlow1)) + 1.0);
		double fSlow122 = (1.0 / ((fConst192 * (fConst192 + fSlow28)) + 1.0));
		double fSlow123 = ((fConst192 * (fConst192 - fSlow28)) + 1.0);
		double fSlow124 = (1.0 / ((fConst196 * (fConst196 + fSlow22)) + 1.0));
		double fSlow125 = ((fConst196 * (fConst196 - fSlow22)) + 1.0);
		double fSlow126 = (1.0 / ((fConst200 * (fConst200 + fSlow66)) + 1.0));
		double fSlow127 = ((fConst200 * (fConst200 - fSlow66)) + 1.0);
		double fSlow128 = (1.0 / ((fConst204 * (fConst204 + fSlow25)) + 1.0));
		double fSlow129 = ((fConst204 * (fConst204 - fSlow25)) + 1.0);
		double fSlow130 = (1.0 / ((fConst208 * (fConst208 + fSlow22)) + 1.0));
		double fSlow131 = ((fConst208 * (fConst208 - fSlow22)) + 1.0);
		double fSlow132 = (0.092873912249800558 * fSlow0);
		double fSlow133 = (1.0 / ((fConst212 * (fConst212 + fSlow132)) + 1.0));
		double fSlow134 = ((fConst212 * (fConst212 - fSlow132)) + 1.0);
		double fSlow135 = (1.0 / ((fConst216 * (fConst216 + fSlow31)) + 1.0));
		double fSlow136 = ((fConst216 * (fConst216 - fSlow31)) + 1.0);
		double fSlow137 = (1.0 / ((fConst220 * (fConst220 + fSlow103)) + 1.0));
		double fSlow138 = ((fConst220 * (fConst220 - fSlow103)) + 1.0);
		double fSlow139 = (1.0 / ((fConst224 * (fConst224 + fSlow25)) + 1.0));
		double fSlow140 = ((fConst224 * (fConst224 - fSlow25)) + 1.0);
		double fSlow141 = (0.09287391224980078 * fSlow0);
		double fSlow142 = (1.0 / ((fConst228 * (fConst228 + fSlow141)) + 1.0));
		double fSlow143 = ((fConst228 * (fConst228 - fSlow141)) + 1.0);
		double fSlow144 = (1.0 / ((fConst232 * (fConst232 + fSlow36)) + 1.0));
		double fSlow145 = ((fConst232 * (fConst232 - fSlow36)) + 1.0);
		double fSlow146 = (1.0 / ((fConst236 * (fConst236 + fSlow8)) + 1.0));
		double fSlow147 = ((fConst236 * (fConst236 - fSlow8)) + 1.0);
		double fSlow148 = (1.0 / ((fConst240 * (fConst240 + fSlow19)) + 1.0));
		double fSlow149 = ((fConst240 * (fConst240 - fSlow19)) + 1.0);
		double fSlow150 = (1.0 / ((fConst244 * (fConst244 + fSlow39)) + 1.0));
		double fSlow151 = ((fConst244 * (fConst244 - fSlow39)) + 1.0);
		double fSlow152 = (1.0 / ((fConst248 * (fConst248 + fSlow106)) + 1.0));
		double fSlow153 = ((fConst248 * (fConst248 - fSlow106)) + 1.0);
		double fSlow154 = (1.0 / ((fConst252 * (fConst252 + fSlow66)) + 1.0));
		double fSlow155 = ((fConst252 * (fConst252 - fSlow66)) + 1.0);
		double fSlow156 = (1.0 / ((fConst256 * (fConst256 + fSlow19)) + 1.0));
		double fSlow157 = ((fConst256 * (fConst256 - fSlow19)) + 1.0);
		for (int i = 0; (i < count); i = (i + 1)) {
			fVec0[0] = fSlow3;
			double fTemp0 = (fRec1[1] + (fConst3 * fVec0[1]));
			fRec1[0] = (fTemp0 - std::floor(fTemp0));
			fRec2[0] = (fSlow4 + (0.999 * fRec2[1]));
			double fTemp1 = (double(((fRec1[0] - fRec1[1]) < 0.0)) * fRec2[0]);
			fRec0[0] = (fTemp1 - (fSlow2 * ((fSlow5 * fRec0[2]) + (fConst4 * fRec0[1]))));
			double fTemp2 = double(input0[i]);
			fRec5[0] = (fTemp2 - (fSlow2 * ((fSlow5 * fRec5[2]) + (fConst4 * fRec5[1]))));
			double fTemp3 = std::fabs((fSlow2 * ((fConst2 * fRec5[0]) + (fConst5 * fRec5[2]))));
			double fTemp4 = ((fRec3[1] > fTemp3)?fSlow7:fSlow6);
			fRec4[0] = ((fRec4[1] * fTemp4) + (fTemp3 * (1.0 - fTemp4)));
			fRec3[0] = fRec4[0];
			fRec6[0] = (fTemp1 - (fSlow9 * ((fSlow10 * fRec6[2]) + (fConst9 * fRec6[1]))));
			fRec9[0] = (fTemp2 - (fSlow9 * ((fSlow10 * fRec9[2]) + (fConst9 * fRec9[1]))));
			double fTemp5 = std::fabs((fSlow9 * ((fConst8 * fRec9[0]) + (fConst10 * fRec9[2]))));
			double fTemp6 = ((fRec7[1] > fTemp5)?fSlow7:fSlow6);
			fRec8[0] = ((fRec8[1] * fTemp6) + (fTemp5 * (1.0 - fTemp6)));
			fRec7[0] = fRec8[0];
			fRec10[0] = (fTemp1 - (fSlow12 * ((fSlow13 * fRec10[2]) + (fConst13 * fRec10[1]))));
			fRec13[0] = (fTemp2 - (fSlow12 * ((fSlow13 * fRec13[2]) + (fConst13 * fRec13[1]))));
			double fTemp7 = std::fabs((fSlow12 * ((fConst12 * fRec13[0]) + (fConst14 * fRec13[2]))));
			double fTemp8 = ((fRec11[1] > fTemp7)?fSlow7:fSlow6);
			fRec12[0] = ((fRec12[1] * fTemp8) + (fTemp7 * (1.0 - fTemp8)));
			fRec11[0] = fRec12[0];
			fRec14[0] = (fTemp1 - (fSlow14 * ((fSlow15 * fRec14[2]) + (fConst17 * fRec14[1]))));
			fRec17[0] = (fTemp2 - (fSlow14 * ((fSlow15 * fRec17[2]) + (fConst17 * fRec17[1]))));
			double fTemp9 = std::fabs((fSlow14 * ((fConst16 * fRec17[0]) + (fConst18 * fRec17[2]))));
			double fTemp10 = ((fRec15[1] > fTemp9)?fSlow7:fSlow6);
			fRec16[0] = ((fRec16[1] * fTemp10) + (fTemp9 * (1.0 - fTemp10)));
			fRec15[0] = fRec16[0];
			fRec18[0] = (fTemp1 - (fSlow17 * ((fSlow18 * fRec18[2]) + (fConst21 * fRec18[1]))));
			fRec21[0] = (fTemp2 - (fSlow17 * ((fSlow18 * fRec21[2]) + (fConst21 * fRec21[1]))));
			double fTemp11 = std::fabs((fSlow17 * ((fConst20 * fRec21[0]) + (fConst22 * fRec21[2]))));
			double fTemp12 = ((fRec19[1] > fTemp11)?fSlow7:fSlow6);
			fRec20[0] = ((fRec20[1] * fTemp12) + (fTemp11 * (1.0 - fTemp12)));
			fRec19[0] = fRec20[0];
			fRec22[0] = (fTemp1 - (fSlow20 * ((fSlow21 * fRec22[2]) + (fConst25 * fRec22[1]))));
			fRec25[0] = (fTemp2 - (fSlow20 * ((fSlow21 * fRec25[2]) + (fConst25 * fRec25[1]))));
			double fTemp13 = std::fabs((fSlow20 * ((fConst24 * fRec25[0]) + (fConst26 * fRec25[2]))));
			double fTemp14 = ((fRec23[1] > fTemp13)?fSlow7:fSlow6);
			fRec24[0] = ((fRec24[1] * fTemp14) + (fTemp13 * (1.0 - fTemp14)));
			fRec23[0] = fRec24[0];
			fRec26[0] = (fTemp1 - (fSlow23 * ((fSlow24 * fRec26[2]) + (fConst29 * fRec26[1]))));
			fRec29[0] = (fTemp2 - (fSlow23 * ((fSlow24 * fRec29[2]) + (fConst29 * fRec29[1]))));
			double fTemp15 = std::fabs((fSlow23 * ((fConst28 * fRec29[0]) + (fConst30 * fRec29[2]))));
			double fTemp16 = ((fRec27[1] > fTemp15)?fSlow7:fSlow6);
			fRec28[0] = ((fRec28[1] * fTemp16) + (fTemp15 * (1.0 - fTemp16)));
			fRec27[0] = fRec28[0];
			fRec30[0] = (fTemp1 - (fSlow26 * ((fSlow27 * fRec30[2]) + (fConst33 * fRec30[1]))));
			fRec33[0] = (fTemp2 - (fSlow26 * ((fSlow27 * fRec33[2]) + (fConst33 * fRec33[1]))));
			double fTemp17 = std::fabs((fSlow26 * ((fConst32 * fRec33[0]) + (fConst34 * fRec33[2]))));
			double fTemp18 = ((fRec31[1] > fTemp17)?fSlow7:fSlow6);
			fRec32[0] = ((fRec32[1] * fTemp18) + (fTemp17 * (1.0 - fTemp18)));
			fRec31[0] = fRec32[0];
			fRec34[0] = (fTemp1 - (fSlow29 * ((fSlow30 * fRec34[2]) + (fConst37 * fRec34[1]))));
			fRec37[0] = (fTemp2 - (fSlow29 * ((fSlow30 * fRec37[2]) + (fConst37 * fRec37[1]))));
			double fTemp19 = std::fabs((fSlow29 * ((fConst36 * fRec37[0]) + (fConst38 * fRec37[2]))));
			double fTemp20 = ((fRec35[1] > fTemp19)?fSlow7:fSlow6);
			fRec36[0] = ((fRec36[1] * fTemp20) + (fTemp19 * (1.0 - fTemp20)));
			fRec35[0] = fRec36[0];
			fRec38[0] = (fTemp1 - (fSlow32 * ((fSlow33 * fRec38[2]) + (fConst41 * fRec38[1]))));
			fRec41[0] = (fTemp2 - (fSlow32 * ((fSlow33 * fRec41[2]) + (fConst41 * fRec41[1]))));
			double fTemp21 = std::fabs((fSlow32 * ((fConst40 * fRec41[0]) + (fConst42 * fRec41[2]))));
			double fTemp22 = ((fRec39[1] > fTemp21)?fSlow7:fSlow6);
			fRec40[0] = ((fRec40[1] * fTemp22) + (fTemp21 * (1.0 - fTemp22)));
			fRec39[0] = fRec40[0];
			fRec42[0] = (fTemp1 - (fSlow34 * ((fSlow35 * fRec42[2]) + (fConst45 * fRec42[1]))));
			fRec45[0] = (fTemp2 - (fSlow34 * ((fSlow35 * fRec45[2]) + (fConst45 * fRec45[1]))));
			double fTemp23 = std::fabs((fSlow34 * ((fConst44 * fRec45[0]) + (fConst46 * fRec45[2]))));
			double fTemp24 = ((fRec43[1] > fTemp23)?fSlow7:fSlow6);
			fRec44[0] = ((fRec44[1] * fTemp24) + (fTemp23 * (1.0 - fTemp24)));
			fRec43[0] = fRec44[0];
			fRec46[0] = (fTemp1 - (fSlow37 * ((fSlow38 * fRec46[2]) + (fConst49 * fRec46[1]))));
			fRec49[0] = (fTemp2 - (fSlow37 * ((fSlow38 * fRec49[2]) + (fConst49 * fRec49[1]))));
			double fTemp25 = std::fabs((fSlow37 * ((fConst48 * fRec49[0]) + (fConst50 * fRec49[2]))));
			double fTemp26 = ((fRec47[1] > fTemp25)?fSlow7:fSlow6);
			fRec48[0] = ((fRec48[1] * fTemp26) + (fTemp25 * (1.0 - fTemp26)));
			fRec47[0] = fRec48[0];
			fRec50[0] = (fTemp1 - (fSlow40 * ((fSlow41 * fRec50[2]) + (fConst53 * fRec50[1]))));
			fRec53[0] = (fTemp2 - (fSlow40 * ((fSlow41 * fRec53[2]) + (fConst53 * fRec53[1]))));
			double fTemp27 = std::fabs((fSlow40 * ((fConst52 * fRec53[0]) + (fConst54 * fRec53[2]))));
			double fTemp28 = ((fRec51[1] > fTemp27)?fSlow7:fSlow6);
			fRec52[0] = ((fRec52[1] * fTemp28) + (fTemp27 * (1.0 - fTemp28)));
			fRec51[0] = fRec52[0];
			fRec54[0] = (fTemp1 - (fSlow42 * ((fSlow43 * fRec54[2]) + (fConst57 * fRec54[1]))));
			fRec57[0] = (fTemp2 - (fSlow42 * ((fSlow43 * fRec57[2]) + (fConst57 * fRec57[1]))));
			double fTemp29 = std::fabs((fSlow42 * ((fConst56 * fRec57[0]) + (fConst58 * fRec57[2]))));
			double fTemp30 = ((fRec55[1] > fTemp29)?fSlow7:fSlow6);
			fRec56[0] = ((fRec56[1] * fTemp30) + (fTemp29 * (1.0 - fTemp30)));
			fRec55[0] = fRec56[0];
			fRec58[0] = (fTemp1 - (fSlow45 * ((fSlow46 * fRec58[2]) + (fConst61 * fRec58[1]))));
			fRec61[0] = (fTemp2 - (fSlow45 * ((fSlow46 * fRec61[2]) + (fConst61 * fRec61[1]))));
			double fTemp31 = std::fabs((fSlow45 * ((fConst60 * fRec61[0]) + (fConst62 * fRec61[2]))));
			double fTemp32 = ((fRec59[1] > fTemp31)?fSlow7:fSlow6);
			fRec60[0] = ((fRec60[1] * fTemp32) + (fTemp31 * (1.0 - fTemp32)));
			fRec59[0] = fRec60[0];
			fRec62[0] = (fTemp1 - (fSlow47 * ((fSlow48 * fRec62[2]) + (fConst65 * fRec62[1]))));
			fRec65[0] = (fTemp2 - (fSlow47 * ((fSlow48 * fRec65[2]) + (fConst65 * fRec65[1]))));
			double fTemp33 = std::fabs((fSlow47 * ((fConst64 * fRec65[0]) + (fConst66 * fRec65[2]))));
			double fTemp34 = ((fRec63[1] > fTemp33)?fSlow7:fSlow6);
			fRec64[0] = ((fRec64[1] * fTemp34) + (fTemp33 * (1.0 - fTemp34)));
			fRec63[0] = fRec64[0];
			fRec66[0] = (fTemp1 - (fSlow49 * ((fSlow50 * fRec66[2]) + (fConst69 * fRec66[1]))));
			fRec69[0] = (fTemp2 - (fSlow49 * ((fSlow50 * fRec69[2]) + (fConst69 * fRec69[1]))));
			double fTemp35 = std::fabs((fSlow49 * ((fConst68 * fRec69[0]) + (fConst70 * fRec69[2]))));
			double fTemp36 = ((fRec67[1] > fTemp35)?fSlow7:fSlow6);
			fRec68[0] = ((fRec68[1] * fTemp36) + (fTemp35 * (1.0 - fTemp36)));
			fRec67[0] = fRec68[0];
			fRec70[0] = (fTemp1 - (fSlow51 * ((fSlow52 * fRec70[2]) + (fConst73 * fRec70[1]))));
			fRec73[0] = (fTemp2 - (fSlow51 * ((fSlow52 * fRec73[2]) + (fConst73 * fRec73[1]))));
			double fTemp37 = std::fabs((fSlow51 * ((fConst72 * fRec73[0]) + (fConst74 * fRec73[2]))));
			double fTemp38 = ((fRec71[1] > fTemp37)?fSlow7:fSlow6);
			fRec72[0] = ((fRec72[1] * fTemp38) + (fTemp37 * (1.0 - fTemp38)));
			fRec71[0] = fRec72[0];
			fRec74[0] = (fTemp1 - (fSlow53 * ((fSlow54 * fRec74[2]) + (fConst77 * fRec74[1]))));
			fRec77[0] = (fTemp2 - (fSlow53 * ((fSlow54 * fRec77[2]) + (fConst77 * fRec77[1]))));
			double fTemp39 = std::fabs((fSlow53 * ((fConst76 * fRec77[0]) + (fConst78 * fRec77[2]))));
			double fTemp40 = ((fRec75[1] > fTemp39)?fSlow7:fSlow6);
			fRec76[0] = ((fRec76[1] * fTemp40) + (fTemp39 * (1.0 - fTemp40)));
			fRec75[0] = fRec76[0];
			fRec78[0] = (fTemp1 - (fSlow56 * ((fSlow57 * fRec78[2]) + (fConst81 * fRec78[1]))));
			fRec81[0] = (fTemp2 - (fSlow56 * ((fSlow57 * fRec81[2]) + (fConst81 * fRec81[1]))));
			double fTemp41 = std::fabs((fSlow56 * ((fConst80 * fRec81[0]) + (fConst82 * fRec81[2]))));
			double fTemp42 = ((fRec79[1] > fTemp41)?fSlow7:fSlow6);
			fRec80[0] = ((fRec80[1] * fTemp42) + (fTemp41 * (1.0 - fTemp42)));
			fRec79[0] = fRec80[0];
			fRec82[0] = (fTemp1 - (fSlow58 * ((fSlow59 * fRec82[2]) + (fConst85 * fRec82[1]))));
			fRec85[0] = (fTemp2 - (fSlow58 * ((fSlow59 * fRec85[2]) + (fConst85 * fRec85[1]))));
			double fTemp43 = std::fabs((fSlow58 * ((fConst84 * fRec85[0]) + (fConst86 * fRec85[2]))));
			double fTemp44 = ((fRec83[1] > fTemp43)?fSlow7:fSlow6);
			fRec84[0] = ((fRec84[1] * fTemp44) + (fTemp43 * (1.0 - fTemp44)));
			fRec83[0] = fRec84[0];
			fRec86[0] = (fTemp1 - (fSlow61 * ((fSlow62 * fRec86[2]) + (fConst89 * fRec86[1]))));
			fRec89[0] = (fTemp2 - (fSlow61 * ((fSlow62 * fRec89[2]) + (fConst89 * fRec89[1]))));
			double fTemp45 = std::fabs((fSlow61 * ((fConst88 * fRec89[0]) + (fConst90 * fRec89[2]))));
			double fTemp46 = ((fRec87[1] > fTemp45)?fSlow7:fSlow6);
			fRec88[0] = ((fRec88[1] * fTemp46) + (fTemp45 * (1.0 - fTemp46)));
			fRec87[0] = fRec88[0];
			fRec90[0] = (fTemp1 - (fSlow64 * ((fSlow65 * fRec90[2]) + (fConst93 * fRec90[1]))));
			fRec93[0] = (fTemp2 - (fSlow64 * ((fSlow65 * fRec93[2]) + (fConst93 * fRec93[1]))));
			double fTemp47 = std::fabs((fSlow64 * ((fConst92 * fRec93[0]) + (fConst94 * fRec93[2]))));
			double fTemp48 = ((fRec91[1] > fTemp47)?fSlow7:fSlow6);
			fRec92[0] = ((fRec92[1] * fTemp48) + (fTemp47 * (1.0 - fTemp48)));
			fRec91[0] = fRec92[0];
			fRec94[0] = (fTemp1 - (fSlow67 * ((fSlow68 * fRec94[2]) + (fConst97 * fRec94[1]))));
			fRec97[0] = (fTemp2 - (fSlow67 * ((fSlow68 * fRec97[2]) + (fConst97 * fRec97[1]))));
			double fTemp49 = std::fabs((fSlow67 * ((fConst96 * fRec97[0]) + (fConst98 * fRec97[2]))));
			double fTemp50 = ((fRec95[1] > fTemp49)?fSlow7:fSlow6);
			fRec96[0] = ((fRec96[1] * fTemp50) + (fTemp49 * (1.0 - fTemp50)));
			fRec95[0] = fRec96[0];
			fRec98[0] = (fTemp1 - (fSlow70 * ((fSlow71 * fRec98[2]) + (fConst101 * fRec98[1]))));
			fRec101[0] = (fTemp2 - (fSlow70 * ((fSlow71 * fRec101[2]) + (fConst101 * fRec101[1]))));
			double fTemp51 = std::fabs((fSlow70 * ((fConst100 * fRec101[0]) + (fConst102 * fRec101[2]))));
			double fTemp52 = ((fRec99[1] > fTemp51)?fSlow7:fSlow6);
			fRec100[0] = ((fRec100[1] * fTemp52) + (fTemp51 * (1.0 - fTemp52)));
			fRec99[0] = fRec100[0];
			fRec102[0] = (fTemp1 - (fSlow72 * ((fSlow73 * fRec102[2]) + (fConst105 * fRec102[1]))));
			fRec105[0] = (fTemp2 - (fSlow72 * ((fSlow73 * fRec105[2]) + (fConst105 * fRec105[1]))));
			double fTemp53 = std::fabs((fSlow72 * ((fConst104 * fRec105[0]) + (fConst106 * fRec105[2]))));
			double fTemp54 = ((fRec103[1] > fTemp53)?fSlow7:fSlow6);
			fRec104[0] = ((fRec104[1] * fTemp54) + (fTemp53 * (1.0 - fTemp54)));
			fRec103[0] = fRec104[0];
			fRec106[0] = (fTemp1 - (fSlow74 * ((fSlow75 * fRec106[2]) + (fConst109 * fRec106[1]))));
			fRec109[0] = (fTemp2 - (fSlow74 * ((fSlow75 * fRec109[2]) + (fConst109 * fRec109[1]))));
			double fTemp55 = std::fabs((fSlow74 * ((fConst108 * fRec109[0]) + (fConst110 * fRec109[2]))));
			double fTemp56 = ((fRec107[1] > fTemp55)?fSlow7:fSlow6);
			fRec108[0] = ((fRec108[1] * fTemp56) + (fTemp55 * (1.0 - fTemp56)));
			fRec107[0] = fRec108[0];
			fRec110[0] = (fTemp1 - (fSlow76 * ((fSlow77 * fRec110[2]) + (fConst113 * fRec110[1]))));
			fRec113[0] = (fTemp2 - (fSlow76 * ((fSlow77 * fRec113[2]) + (fConst113 * fRec113[1]))));
			double fTemp57 = std::fabs((fSlow76 * ((fConst112 * fRec113[0]) + (fConst114 * fRec113[2]))));
			double fTemp58 = ((fRec111[1] > fTemp57)?fSlow7:fSlow6);
			fRec112[0] = ((fRec112[1] * fTemp58) + (fTemp57 * (1.0 - fTemp58)));
			fRec111[0] = fRec112[0];
			fRec114[0] = (fTemp1 - (fSlow78 * ((fSlow79 * fRec114[2]) + (fConst117 * fRec114[1]))));
			fRec117[0] = (fTemp2 - (fSlow78 * ((fSlow79 * fRec117[2]) + (fConst117 * fRec117[1]))));
			double fTemp59 = std::fabs((fSlow78 * ((fConst116 * fRec117[0]) + (fConst118 * fRec117[2]))));
			double fTemp60 = ((fRec115[1] > fTemp59)?fSlow7:fSlow6);
			fRec116[0] = ((fRec116[1] * fTemp60) + (fTemp59 * (1.0 - fTemp60)));
			fRec115[0] = fRec116[0];
			fRec118[0] = (fTemp1 - (fSlow80 * ((fSlow81 * fRec118[2]) + (fConst121 * fRec118[1]))));
			fRec121[0] = (fTemp2 - (fSlow80 * ((fSlow81 * fRec121[2]) + (fConst121 * fRec121[1]))));
			double fTemp61 = std::fabs((fSlow80 * ((fConst120 * fRec121[0]) + (fConst122 * fRec121[2]))));
			double fTemp62 = ((fRec119[1] > fTemp61)?fSlow7:fSlow6);
			fRec120[0] = ((fRec120[1] * fTemp62) + (fTemp61 * (1.0 - fTemp62)));
			fRec119[0] = fRec120[0];
			fRec122[0] = (fTemp1 - (fSlow83 * ((fSlow84 * fRec122[2]) + (fConst125 * fRec122[1]))));
			fRec125[0] = (fTemp2 - (fSlow83 * ((fSlow84 * fRec125[2]) + (fConst125 * fRec125[1]))));
			double fTemp63 = std::fabs((fSlow83 * ((fConst124 * fRec125[0]) + (fConst126 * fRec125[2]))));
			double fTemp64 = ((fRec123[1] > fTemp63)?fSlow7:fSlow6);
			fRec124[0] = ((fRec124[1] * fTemp64) + (fTemp63 * (1.0 - fTemp64)));
			fRec123[0] = fRec124[0];
			fRec126[0] = (fTemp1 - (fSlow86 * ((fSlow87 * fRec126[2]) + (fConst129 * fRec126[1]))));
			fRec129[0] = (fTemp2 - (fSlow86 * ((fSlow87 * fRec129[2]) + (fConst129 * fRec129[1]))));
			double fTemp65 = std::fabs((fSlow86 * ((fConst128 * fRec129[0]) + (fConst130 * fRec129[2]))));
			double fTemp66 = ((fRec127[1] > fTemp65)?fSlow7:fSlow6);
			fRec128[0] = ((fRec128[1] * fTemp66) + (fTemp65 * (1.0 - fTemp66)));
			fRec127[0] = fRec128[0];
			fRec130[0] = (fTemp1 - (fSlow89 * ((fSlow90 * fRec130[2]) + (fConst133 * fRec130[1]))));
			fRec133[0] = (fTemp2 - (fSlow89 * ((fSlow90 * fRec133[2]) + (fConst133 * fRec133[1]))));
			double fTemp67 = std::fabs((fSlow89 * ((fConst132 * fRec133[0]) + (fConst134 * fRec133[2]))));
			double fTemp68 = ((fRec131[1] > fTemp67)?fSlow7:fSlow6);
			fRec132[0] = ((fRec132[1] * fTemp68) + (fTemp67 * (1.0 - fTemp68)));
			fRec131[0] = fRec132[0];
			fRec134[0] = (fTemp1 - (fSlow91 * ((fSlow92 * fRec134[2]) + (fConst137 * fRec134[1]))));
			fRec137[0] = (fTemp2 - (fSlow91 * ((fSlow92 * fRec137[2]) + (fConst137 * fRec137[1]))));
			double fTemp69 = std::fabs((fSlow91 * ((fConst136 * fRec137[0]) + (fConst138 * fRec137[2]))));
			double fTemp70 = ((fRec135[1] > fTemp69)?fSlow7:fSlow6);
			fRec136[0] = ((fRec136[1] * fTemp70) + (fTemp69 * (1.0 - fTemp70)));
			fRec135[0] = fRec136[0];
			fRec138[0] = (fTemp1 - (fSlow93 * ((fSlow94 * fRec138[2]) + (fConst141 * fRec138[1]))));
			fRec141[0] = (fTemp2 - (fSlow93 * ((fSlow94 * fRec141[2]) + (fConst141 * fRec141[1]))));
			double fTemp71 = std::fabs((fSlow93 * ((fConst140 * fRec141[0]) + (fConst142 * fRec141[2]))));
			double fTemp72 = ((fRec139[1] > fTemp71)?fSlow7:fSlow6);
			fRec140[0] = ((fRec140[1] * fTemp72) + (fTemp71 * (1.0 - fTemp72)));
			fRec139[0] = fRec140[0];
			fRec142[0] = (fTemp1 - (fSlow95 * ((fSlow96 * fRec142[2]) + (fConst145 * fRec142[1]))));
			fRec145[0] = (fTemp2 - (fSlow95 * ((fSlow96 * fRec145[2]) + (fConst145 * fRec145[1]))));
			double fTemp73 = std::fabs((fSlow95 * ((fConst144 * fRec145[0]) + (fConst146 * fRec145[2]))));
			double fTemp74 = ((fRec143[1] > fTemp73)?fSlow7:fSlow6);
			fRec144[0] = ((fRec144[1] * fTemp74) + (fTemp73 * (1.0 - fTemp74)));
			fRec143[0] = fRec144[0];
			fRec146[0] = (fTemp1 - (fSlow97 * ((fSlow98 * fRec146[2]) + (fConst149 * fRec146[1]))));
			fRec149[0] = (fTemp2 - (fSlow97 * ((fSlow98 * fRec149[2]) + (fConst149 * fRec149[1]))));
			double fTemp75 = std::fabs((fSlow97 * ((fConst148 * fRec149[0]) + (fConst150 * fRec149[2]))));
			double fTemp76 = ((fRec147[1] > fTemp75)?fSlow7:fSlow6);
			fRec148[0] = ((fRec148[1] * fTemp76) + (fTemp75 * (1.0 - fTemp76)));
			fRec147[0] = fRec148[0];
			fRec150[0] = (fTemp1 - (fSlow99 * ((fSlow100 * fRec150[2]) + (fConst153 * fRec150[1]))));
			fRec153[0] = (fTemp2 - (fSlow99 * ((fSlow100 * fRec153[2]) + (fConst153 * fRec153[1]))));
			double fTemp77 = std::fabs((fSlow99 * ((fConst152 * fRec153[0]) + (fConst154 * fRec153[2]))));
			double fTemp78 = ((fRec151[1] > fTemp77)?fSlow7:fSlow6);
			fRec152[0] = ((fRec152[1] * fTemp78) + (fTemp77 * (1.0 - fTemp78)));
			fRec151[0] = fRec152[0];
			fRec154[0] = (fTemp1 - (fSlow101 * ((fSlow102 * fRec154[2]) + (fConst157 * fRec154[1]))));
			fRec157[0] = (fTemp2 - (fSlow101 * ((fSlow102 * fRec157[2]) + (fConst157 * fRec157[1]))));
			double fTemp79 = std::fabs((fSlow101 * ((fConst156 * fRec157[0]) + (fConst158 * fRec157[2]))));
			double fTemp80 = ((fRec155[1] > fTemp79)?fSlow7:fSlow6);
			fRec156[0] = ((fRec156[1] * fTemp80) + (fTemp79 * (1.0 - fTemp80)));
			fRec155[0] = fRec156[0];
			fRec158[0] = (fTemp1 - (fSlow104 * ((fSlow105 * fRec158[2]) + (fConst161 * fRec158[1]))));
			fRec161[0] = (fTemp2 - (fSlow104 * ((fSlow105 * fRec161[2]) + (fConst161 * fRec161[1]))));
			double fTemp81 = std::fabs((fSlow104 * ((fConst160 * fRec161[0]) + (fConst162 * fRec161[2]))));
			double fTemp82 = ((fRec159[1] > fTemp81)?fSlow7:fSlow6);
			fRec160[0] = ((fRec160[1] * fTemp82) + (fTemp81 * (1.0 - fTemp82)));
			fRec159[0] = fRec160[0];
			fRec162[0] = (fTemp1 - (fSlow107 * ((fSlow108 * fRec162[2]) + (fConst165 * fRec162[1]))));
			fRec165[0] = (fTemp2 - (fSlow107 * ((fSlow108 * fRec165[2]) + (fConst165 * fRec165[1]))));
			double fTemp83 = std::fabs((fSlow107 * ((fConst164 * fRec165[0]) + (fConst166 * fRec165[2]))));
			double fTemp84 = ((fRec163[1] > fTemp83)?fSlow7:fSlow6);
			fRec164[0] = ((fRec164[1] * fTemp84) + (fTemp83 * (1.0 - fTemp84)));
			fRec163[0] = fRec164[0];
			fRec168[0] = (fTemp2 - (fSlow110 * ((fSlow111 * fRec168[2]) + (fConst169 * fRec168[1]))));
			double fTemp85 = std::fabs((fSlow110 * ((fConst168 * fRec168[0]) + (fConst170 * fRec168[2]))));
			double fTemp86 = ((fRec166[1] > fTemp85)?fSlow7:fSlow6);
			fRec167[0] = ((fRec167[1] * fTemp86) + (fTemp85 * (1.0 - fTemp86)));
			fRec166[0] = fRec167[0];
			fRec169[0] = (fTemp1 - (fSlow110 * ((fSlow111 * fRec169[2]) + (fConst169 * fRec169[1]))));
			fRec172[0] = (fTemp2 - (fSlow112 * ((fSlow113 * fRec172[2]) + (fConst173 * fRec172[1]))));
			double fTemp87 = std::fabs((fSlow112 * ((fConst172 * fRec172[0]) + (fConst174 * fRec172[2]))));
			double fTemp88 = ((fRec170[1] > fTemp87)?fSlow7:fSlow6);
			fRec171[0] = ((fRec171[1] * fTemp88) + (fTemp87 * (1.0 - fTemp88)));
			fRec170[0] = fRec171[0];
			fRec173[0] = (fTemp1 - (fSlow112 * ((fSlow113 * fRec173[2]) + (fConst173 * fRec173[1]))));
			fRec176[0] = (fTemp2 - (fSlow114 * ((fSlow115 * fRec176[2]) + (fConst177 * fRec176[1]))));
			double fTemp89 = std::fabs((fSlow114 * ((fConst176 * fRec176[0]) + (fConst178 * fRec176[2]))));
			double fTemp90 = ((fRec174[1] > fTemp89)?fSlow7:fSlow6);
			fRec175[0] = ((fRec175[1] * fTemp90) + (fTemp89 * (1.0 - fTemp90)));
			fRec174[0] = fRec175[0];
			fRec177[0] = (fTemp1 - (fSlow114 * ((fSlow115 * fRec177[2]) + (fConst177 * fRec177[1]))));
			fRec180[0] = (fTemp2 - (fSlow116 * ((fSlow117 * fRec180[2]) + (fConst181 * fRec180[1]))));
			double fTemp91 = std::fabs((fSlow116 * ((fConst180 * fRec180[0]) + (fConst182 * fRec180[2]))));
			double fTemp92 = ((fRec178[1] > fTemp91)?fSlow7:fSlow6);
			fRec179[0] = ((fRec179[1] * fTemp92) + (fTemp91 * (1.0 - fTemp92)));
			fRec178[0] = fRec179[0];
			fRec181[0] = (fTemp1 - (fSlow116 * ((fSlow117 * fRec181[2]) + (fConst181 * fRec181[1]))));
			fRec184[0] = (fTemp2 - (fSlow118 * ((fSlow119 * fRec184[2]) + (fConst185 * fRec184[1]))));
			double fTemp93 = std::fabs((fSlow118 * ((fConst184 * fRec184[0]) + (fConst186 * fRec184[2]))));
			double fTemp94 = ((fRec182[1] > fTemp93)?fSlow7:fSlow6);
			fRec183[0] = ((fRec183[1] * fTemp94) + (fTemp93 * (1.0 - fTemp94)));
			fRec182[0] = fRec183[0];
			fRec185[0] = (fTemp1 - (fSlow118 * ((fSlow119 * fRec185[2]) + (fConst185 * fRec185[1]))));
			fRec188[0] = (fTemp2 - (fSlow120 * ((fSlow121 * fRec188[2]) + (fConst189 * fRec188[1]))));
			double fTemp95 = std::fabs((fSlow120 * ((fConst188 * fRec188[0]) + (fConst190 * fRec188[2]))));
			double fTemp96 = ((fRec186[1] > fTemp95)?fSlow7:fSlow6);
			fRec187[0] = ((fRec187[1] * fTemp96) + (fTemp95 * (1.0 - fTemp96)));
			fRec186[0] = fRec187[0];
			fRec189[0] = (fTemp1 - (fSlow120 * ((fSlow121 * fRec189[2]) + (fConst189 * fRec189[1]))));
			fRec192[0] = (fTemp2 - (fSlow122 * ((fSlow123 * fRec192[2]) + (fConst193 * fRec192[1]))));
			double fTemp97 = std::fabs((fSlow122 * ((fConst192 * fRec192[0]) + (fConst194 * fRec192[2]))));
			double fTemp98 = ((fRec190[1] > fTemp97)?fSlow7:fSlow6);
			fRec191[0] = ((fRec191[1] * fTemp98) + (fTemp97 * (1.0 - fTemp98)));
			fRec190[0] = fRec191[0];
			fRec193[0] = (fTemp1 - (fSlow122 * ((fSlow123 * fRec193[2]) + (fConst193 * fRec193[1]))));
			fRec196[0] = (fTemp2 - (fSlow124 * ((fSlow125 * fRec196[2]) + (fConst197 * fRec196[1]))));
			double fTemp99 = std::fabs((fSlow124 * ((fConst196 * fRec196[0]) + (fConst198 * fRec196[2]))));
			double fTemp100 = ((fRec194[1] > fTemp99)?fSlow7:fSlow6);
			fRec195[0] = ((fRec195[1] * fTemp100) + (fTemp99 * (1.0 - fTemp100)));
			fRec194[0] = fRec195[0];
			fRec197[0] = (fTemp1 - (fSlow124 * ((fSlow125 * fRec197[2]) + (fConst197 * fRec197[1]))));
			fRec200[0] = (fTemp2 - (fSlow126 * ((fSlow127 * fRec200[2]) + (fConst201 * fRec200[1]))));
			double fTemp101 = std::fabs((fSlow126 * ((fConst200 * fRec200[0]) + (fConst202 * fRec200[2]))));
			double fTemp102 = ((fRec198[1] > fTemp101)?fSlow7:fSlow6);
			fRec199[0] = ((fRec199[1] * fTemp102) + (fTemp101 * (1.0 - fTemp102)));
			fRec198[0] = fRec199[0];
			fRec201[0] = (fTemp1 - (fSlow126 * ((fSlow127 * fRec201[2]) + (fConst201 * fRec201[1]))));
			fRec204[0] = (fTemp2 - (fSlow128 * ((fSlow129 * fRec204[2]) + (fConst205 * fRec204[1]))));
			double fTemp103 = std::fabs((fSlow128 * ((fConst204 * fRec204[0]) + (fConst206 * fRec204[2]))));
			double fTemp104 = ((fRec202[1] > fTemp103)?fSlow7:fSlow6);
			fRec203[0] = ((fRec203[1] * fTemp104) + (fTemp103 * (1.0 - fTemp104)));
			fRec202[0] = fRec203[0];
			fRec205[0] = (fTemp1 - (fSlow128 * ((fSlow129 * fRec205[2]) + (fConst205 * fRec205[1]))));
			fRec208[0] = (fTemp2 - (fSlow130 * ((fSlow131 * fRec208[2]) + (fConst209 * fRec208[1]))));
			double fTemp105 = std::fabs((fSlow130 * ((fConst208 * fRec208[0]) + (fConst210 * fRec208[2]))));
			double fTemp106 = ((fRec206[1] > fTemp105)?fSlow7:fSlow6);
			fRec207[0] = ((fRec207[1] * fTemp106) + (fTemp105 * (1.0 - fTemp106)));
			fRec206[0] = fRec207[0];
			fRec209[0] = (fTemp1 - (fSlow130 * ((fSlow131 * fRec209[2]) + (fConst209 * fRec209[1]))));
			fRec212[0] = (fTemp2 - (fSlow133 * ((fSlow134 * fRec212[2]) + (fConst213 * fRec212[1]))));
			double fTemp107 = std::fabs((fSlow133 * ((fConst212 * fRec212[0]) + (fConst214 * fRec212[2]))));
			double fTemp108 = ((fRec210[1] > fTemp107)?fSlow7:fSlow6);
			fRec211[0] = ((fRec211[1] * fTemp108) + (fTemp107 * (1.0 - fTemp108)));
			fRec210[0] = fRec211[0];
			fRec213[0] = (fTemp1 - (fSlow133 * ((fSlow134 * fRec213[2]) + (fConst213 * fRec213[1]))));
			fRec216[0] = (fTemp2 - (fSlow135 * ((fSlow136 * fRec216[2]) + (fConst217 * fRec216[1]))));
			double fTemp109 = std::fabs((fSlow135 * ((fConst216 * fRec216[0]) + (fConst218 * fRec216[2]))));
			double fTemp110 = ((fRec214[1] > fTemp109)?fSlow7:fSlow6);
			fRec215[0] = ((fRec215[1] * fTemp110) + (fTemp109 * (1.0 - fTemp110)));
			fRec214[0] = fRec215[0];
			fRec217[0] = (fTemp1 - (fSlow135 * ((fSlow136 * fRec217[2]) + (fConst217 * fRec217[1]))));
			fRec220[0] = (fTemp2 - (fSlow137 * ((fSlow138 * fRec220[2]) + (fConst221 * fRec220[1]))));
			double fTemp111 = std::fabs((fSlow137 * ((fConst220 * fRec220[0]) + (fConst222 * fRec220[2]))));
			double fTemp112 = ((fRec218[1] > fTemp111)?fSlow7:fSlow6);
			fRec219[0] = ((fRec219[1] * fTemp112) + (fTemp111 * (1.0 - fTemp112)));
			fRec218[0] = fRec219[0];
			fRec221[0] = (fTemp1 - (fSlow137 * ((fSlow138 * fRec221[2]) + (fConst221 * fRec221[1]))));
			fRec222[0] = (fTemp1 - (fSlow139 * ((fSlow140 * fRec222[2]) + (fConst225 * fRec222[1]))));
			fRec225[0] = (fTemp2 - (fSlow139 * ((fSlow140 * fRec225[2]) + (fConst225 * fRec225[1]))));
			double fTemp113 = std::fabs((fSlow139 * ((fConst224 * fRec225[0]) + (fConst226 * fRec225[2]))));
			double fTemp114 = ((fRec223[1] > fTemp113)?fSlow7:fSlow6);
			fRec224[0] = ((fRec224[1] * fTemp114) + (fTemp113 * (1.0 - fTemp114)));
			fRec223[0] = fRec224[0];
			fRec226[0] = (fTemp1 - (fSlow142 * ((fSlow143 * fRec226[2]) + (fConst229 * fRec226[1]))));
			fRec229[0] = (fTemp2 - (fSlow142 * ((fSlow143 * fRec229[2]) + (fConst229 * fRec229[1]))));
			double fTemp115 = std::fabs((fSlow142 * ((fConst228 * fRec229[0]) + (fConst230 * fRec229[2]))));
			double fTemp116 = ((fRec227[1] > fTemp115)?fSlow7:fSlow6);
			fRec228[0] = ((fRec228[1] * fTemp116) + (fTemp115 * (1.0 - fTemp116)));
			fRec227[0] = fRec228[0];
			fRec230[0] = (fTemp1 - (fSlow144 * ((fSlow145 * fRec230[2]) + (fConst233 * fRec230[1]))));
			fRec233[0] = (fTemp2 - (fSlow144 * ((fSlow145 * fRec233[2]) + (fConst233 * fRec233[1]))));
			double fTemp117 = std::fabs((fSlow144 * ((fConst232 * fRec233[0]) + (fConst234 * fRec233[2]))));
			double fTemp118 = ((fRec231[1] > fTemp117)?fSlow7:fSlow6);
			fRec232[0] = ((fRec232[1] * fTemp118) + (fTemp117 * (1.0 - fTemp118)));
			fRec231[0] = fRec232[0];
			fRec234[0] = (fTemp1 - (fSlow146 * ((fSlow147 * fRec234[2]) + (fConst237 * fRec234[1]))));
			fRec237[0] = (fTemp2 - (fSlow146 * ((fSlow147 * fRec237[2]) + (fConst237 * fRec237[1]))));
			double fTemp119 = std::fabs((fSlow146 * ((fConst236 * fRec237[0]) + (fConst238 * fRec237[2]))));
			double fTemp120 = ((fRec235[1] > fTemp119)?fSlow7:fSlow6);
			fRec236[0] = ((fRec236[1] * fTemp120) + (fTemp119 * (1.0 - fTemp120)));
			fRec235[0] = fRec236[0];
			fRec238[0] = (fTemp1 - (fSlow148 * ((fSlow149 * fRec238[2]) + (fConst241 * fRec238[1]))));
			fRec241[0] = (fTemp2 - (fSlow148 * ((fSlow149 * fRec241[2]) + (fConst241 * fRec241[1]))));
			double fTemp121 = std::fabs((fSlow148 * ((fConst240 * fRec241[0]) + (fConst242 * fRec241[2]))));
			double fTemp122 = ((fRec239[1] > fTemp121)?fSlow7:fSlow6);
			fRec240[0] = ((fRec240[1] * fTemp122) + (fTemp121 * (1.0 - fTemp122)));
			fRec239[0] = fRec240[0];
			fRec242[0] = (fTemp1 - (fSlow150 * ((fSlow151 * fRec242[2]) + (fConst245 * fRec242[1]))));
			fRec245[0] = (fTemp2 - (fSlow150 * ((fSlow151 * fRec245[2]) + (fConst245 * fRec245[1]))));
			double fTemp123 = std::fabs((fSlow150 * ((fConst244 * fRec245[0]) + (fConst246 * fRec245[2]))));
			double fTemp124 = ((fRec243[1] > fTemp123)?fSlow7:fSlow6);
			fRec244[0] = ((fRec244[1] * fTemp124) + (fTemp123 * (1.0 - fTemp124)));
			fRec243[0] = fRec244[0];
			fRec246[0] = (fTemp1 - (fSlow152 * ((fSlow153 * fRec246[2]) + (fConst249 * fRec246[1]))));
			fRec249[0] = (fTemp2 - (fSlow152 * ((fSlow153 * fRec249[2]) + (fConst249 * fRec249[1]))));
			double fTemp125 = std::fabs((fSlow152 * ((fConst248 * fRec249[0]) + (fConst250 * fRec249[2]))));
			double fTemp126 = ((fRec247[1] > fTemp125)?fSlow7:fSlow6);
			fRec248[0] = ((fRec248[1] * fTemp126) + (fTemp125 * (1.0 - fTemp126)));
			fRec247[0] = fRec248[0];
			fRec250[0] = (fTemp1 - (fSlow154 * ((fSlow155 * fRec250[2]) + (fConst253 * fRec250[1]))));
			fRec253[0] = (fTemp2 - (fSlow154 * ((fSlow155 * fRec253[2]) + (fConst253 * fRec253[1]))));
			double fTemp127 = std::fabs((fSlow154 * ((fConst252 * fRec253[0]) + (fConst254 * fRec253[2]))));
			double fTemp128 = ((fRec251[1] > fTemp127)?fSlow7:fSlow6);
			fRec252[0] = ((fRec252[1] * fTemp128) + (fTemp127 * (1.0 - fTemp128)));
			fRec251[0] = fRec252[0];
			fRec254[0] = (fTemp1 - (fSlow156 * ((fSlow157 * fRec254[2]) + (fConst257 * fRec254[1]))));
			fRec257[0] = (fTemp2 - (fSlow156 * ((fSlow157 * fRec257[2]) + (fConst257 * fRec257[1]))));
			double fTemp129 = std::fabs((fSlow156 * ((fConst256 * fRec257[0]) + (fConst258 * fRec257[2]))));
			double fTemp130 = ((fRec255[1] > fTemp129)?fSlow7:fSlow6);
			fRec256[0] = ((fRec256[1] * fTemp130) + (fTemp129 * (1.0 - fTemp130)));
			fRec255[0] = fRec256[0];
			double fTemp131 = ((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((fSlow2 * ((fRec0[2] * (0.0 - (fConst2 * fRec3[0]))) + (fConst2 * (fRec3[0] * fRec0[0])))) + (fSlow9 * ((fRec6[2] * (0.0 - (fConst8 * fRec7[0]))) + (fConst8 * (fRec7[0] * fRec6[0]))))) + (fSlow12 * ((fRec10[2] * (0.0 - (fConst12 * fRec11[0]))) + (fConst12 * (fRec11[0] * fRec10[0]))))) + (fSlow14 * ((fRec14[2] * (0.0 - (fConst16 * fRec15[0]))) + (fConst16 * (fRec15[0] * fRec14[0]))))) + (fSlow17 * ((fRec18[2] * (0.0 - (fConst20 * fRec19[0]))) + (fConst20 * (fRec19[0] * fRec18[0]))))) + (fSlow20 * ((fRec22[2] * (0.0 - (fConst24 * fRec23[0]))) + (fConst24 * (fRec23[0] * fRec22[0]))))) + (fSlow23 * ((fRec26[2] * (0.0 - (fConst28 * fRec27[0]))) + (fConst28 * (fRec27[0] * fRec26[0]))))) + (fSlow26 * ((fRec30[2] * (0.0 - (fConst32 * fRec31[0]))) + (fConst32 * (fRec31[0] * fRec30[0]))))) + (fSlow29 * ((fRec34[2] * (0.0 - (fConst36 * fRec35[0]))) + (fConst36 * (fRec35[0] * fRec34[0]))))) + (fSlow32 * ((fRec38[2] * (0.0 - (fConst40 * fRec39[0]))) + (fConst40 * (fRec39[0] * fRec38[0]))))) + (fSlow34 * ((fRec42[2] * (0.0 - (fConst44 * fRec43[0]))) + (fConst44 * (fRec43[0] * fRec42[0]))))) + (fSlow37 * ((fRec46[2] * (0.0 - (fConst48 * fRec47[0]))) + (fConst48 * (fRec47[0] * fRec46[0]))))) + (fSlow40 * ((fRec50[2] * (0.0 - (fConst52 * fRec51[0]))) + (fConst52 * (fRec51[0] * fRec50[0]))))) + (fSlow42 * ((fRec54[2] * (0.0 - (fConst56 * fRec55[0]))) + (fConst56 * (fRec55[0] * fRec54[0]))))) + (fSlow45 * ((fRec58[2] * (0.0 - (fConst60 * fRec59[0]))) + (fConst60 * (fRec59[0] * fRec58[0]))))) + (fSlow47 * ((fRec62[2] * (0.0 - (fConst64 * fRec63[0]))) + (fConst64 * (fRec63[0] * fRec62[0]))))) + (fSlow49 * ((fRec66[2] * (0.0 - (fConst68 * fRec67[0]))) + (fConst68 * (fRec67[0] * fRec66[0]))))) + (fSlow51 * ((fRec70[2] * (0.0 - (fConst72 * fRec71[0]))) + (fConst72 * (fRec71[0] * fRec70[0]))))) + (fSlow53 * ((fRec74[2] * (0.0 - (fConst76 * fRec75[0]))) + (fConst76 * (fRec75[0] * fRec74[0]))))) + (fSlow56 * ((fRec78[2] * (0.0 - (fConst80 * fRec79[0]))) + (fConst80 * (fRec79[0] * fRec78[0]))))) + (fSlow58 * ((fRec82[2] * (0.0 - (fConst84 * fRec83[0]))) + (fConst84 * (fRec83[0] * fRec82[0]))))) + (fSlow61 * ((fRec86[2] * (0.0 - (fConst88 * fRec87[0]))) + (fConst88 * (fRec87[0] * fRec86[0]))))) + (fSlow64 * ((fRec90[2] * (0.0 - (fConst92 * fRec91[0]))) + (fConst92 * (fRec91[0] * fRec90[0]))))) + (fSlow67 * ((fRec94[2] * (0.0 - (fConst96 * fRec95[0]))) + (fConst96 * (fRec95[0] * fRec94[0]))))) + (fSlow70 * ((fRec98[2] * (0.0 - (fConst100 * fRec99[0]))) + (fConst100 * (fRec99[0] * fRec98[0]))))) + (fSlow72 * ((fRec102[2] * (0.0 - (fConst104 * fRec103[0]))) + (fConst104 * (fRec103[0] * fRec102[0]))))) + (fSlow74 * ((fRec106[2] * (0.0 - (fConst108 * fRec107[0]))) + (fConst108 * (fRec107[0] * fRec106[0]))))) + (fSlow76 * ((fRec110[2] * (0.0 - (fConst112 * fRec111[0]))) + (fConst112 * (fRec111[0] * fRec110[0]))))) + (fSlow78 * ((fRec114[2] * (0.0 - (fConst116 * fRec115[0]))) + (fConst116 * (fRec115[0] * fRec114[0]))))) + (fSlow80 * ((fRec118[2] * (0.0 - (fConst120 * fRec119[0]))) + (fConst120 * (fRec119[0] * fRec118[0]))))) + (fSlow83 * ((fRec122[2] * (0.0 - (fConst124 * fRec123[0]))) + (fConst124 * (fRec123[0] * fRec122[0]))))) + (fSlow86 * ((fRec126[2] * (0.0 - (fConst128 * fRec127[0]))) + (fConst128 * (fRec127[0] * fRec126[0]))))) + (fSlow89 * ((fRec130[2] * (0.0 - (fConst132 * fRec131[0]))) + (fConst132 * (fRec131[0] * fRec130[0]))))) + (fSlow91 * ((fRec134[2] * (0.0 - (fConst136 * fRec135[0]))) + (fConst136 * (fRec135[0] * fRec134[0]))))) + (fSlow93 * ((fRec138[2] * (0.0 - (fConst140 * fRec139[0]))) + (fConst140 * (fRec139[0] * fRec138[0]))))) + (fSlow95 * ((fRec142[2] * (0.0 - (fConst144 * fRec143[0]))) + (fConst144 * (fRec143[0] * fRec142[0]))))) + (fSlow97 * ((fRec146[2] * (0.0 - (fConst148 * fRec147[0]))) + (fConst148 * (fRec147[0] * fRec146[0]))))) + (fSlow99 * ((fRec150[2] * (0.0 - (fConst152 * fRec151[0]))) + (fConst152 * (fRec151[0] * fRec150[0]))))) + (fSlow101 * ((fRec154[2] * (0.0 - (fConst156 * fRec155[0]))) + (fConst156 * (fRec155[0] * fRec154[0]))))) + (fSlow104 * ((fRec158[2] * (0.0 - (fConst160 * fRec159[0]))) + (fConst160 * (fRec159[0] * fRec158[0]))))) + (fSlow107 * ((fRec162[2] * (0.0 - (fConst164 * fRec163[0]))) + (fConst164 * (fRec163[0] * fRec162[0]))))) + (fSlow110 * ((fConst168 * (fRec166[0] * fRec169[0])) + (fRec169[2] * (0.0 - (fConst168 * fRec166[0])))))) + (fSlow112 * ((fConst172 * (fRec170[0] * fRec173[0])) + (fRec173[2] * (0.0 - (fConst172 * fRec170[0])))))) + (fSlow114 * ((fConst176 * (fRec174[0] * fRec177[0])) + (fRec177[2] * (0.0 - (fConst176 * fRec174[0])))))) + (fSlow116 * ((fConst180 * (fRec178[0] * fRec181[0])) + (fRec181[2] * (0.0 - (fConst180 * fRec178[0])))))) + (fSlow118 * ((fConst184 * (fRec182[0] * fRec185[0])) + (fRec185[2] * (0.0 - (fConst184 * fRec182[0])))))) + (fSlow120 * ((fConst188 * (fRec186[0] * fRec189[0])) + (fRec189[2] * (0.0 - (fConst188 * fRec186[0])))))) + (fSlow122 * ((fConst192 * (fRec190[0] * fRec193[0])) + (fRec193[2] * (0.0 - (fConst192 * fRec190[0])))))) + (fSlow124 * ((fConst196 * (fRec194[0] * fRec197[0])) + (fRec197[2] * (0.0 - (fConst196 * fRec194[0])))))) + (fSlow126 * ((fConst200 * (fRec198[0] * fRec201[0])) + (fRec201[2] * (0.0 - (fConst200 * fRec198[0])))))) + (fSlow128 * ((fConst204 * (fRec202[0] * fRec205[0])) + (fRec205[2] * (0.0 - (fConst204 * fRec202[0])))))) + (fSlow130 * ((fConst208 * (fRec206[0] * fRec209[0])) + (fRec209[2] * (0.0 - (fConst208 * fRec206[0])))))) + (fSlow133 * ((fConst212 * (fRec210[0] * fRec213[0])) + (fRec213[2] * (0.0 - (fConst212 * fRec210[0])))))) + (fSlow135 * ((fConst216 * (fRec214[0] * fRec217[0])) + (fRec217[2] * (0.0 - (fConst216 * fRec214[0])))))) + (fSlow137 * ((fConst220 * (fRec218[0] * fRec221[0])) + (fRec221[2] * (0.0 - (fConst220 * fRec218[0])))))) + (fSlow139 * ((fRec222[2] * (0.0 - (fConst224 * fRec223[0]))) + (fConst224 * (fRec223[0] * fRec222[0]))))) + (fSlow142 * ((fRec226[2] * (0.0 - (fConst228 * fRec227[0]))) + (fConst228 * (fRec227[0] * fRec226[0]))))) + (fSlow144 * ((fRec230[2] * (0.0 - (fConst232 * fRec231[0]))) + (fConst232 * (fRec231[0] * fRec230[0]))))) + (fSlow146 * ((fRec234[2] * (0.0 - (fConst236 * fRec235[0]))) + (fConst236 * (fRec235[0] * fRec234[0]))))) + (fSlow148 * ((fRec238[2] * (0.0 - (fConst240 * fRec239[0]))) + (fConst240 * (fRec239[0] * fRec238[0]))))) + (fSlow150 * ((fRec242[2] * (0.0 - (fConst244 * fRec243[0]))) + (fConst244 * (fRec243[0] * fRec242[0]))))) + (fSlow152 * ((fRec246[2] * (0.0 - (fConst248 * fRec247[0]))) + (fConst248 * (fRec247[0] * fRec246[0]))))) + (fSlow154 * ((fRec250[2] * (0.0 - (fConst252 * fRec251[0]))) + (fConst252 * (fRec251[0] * fRec250[0]))))) + (fSlow156 * ((fRec254[2] * (0.0 - (fConst256 * fRec255[0]))) + (fConst256 * (fRec255[0] * fRec254[0])))));
			output0[i] = FAUSTFLOAT(fTemp131);
			output1[i] = FAUSTFLOAT(fTemp131);
			fVec0[1] = fVec0[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec4[1] = fRec4[0];
			fRec3[1] = fRec3[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec8[1] = fRec8[0];
			fRec7[1] = fRec7[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec11[1] = fRec11[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
			fRec16[1] = fRec16[0];
			fRec15[1] = fRec15[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			fRec21[2] = fRec21[1];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			fRec19[1] = fRec19[0];
			fRec22[2] = fRec22[1];
			fRec22[1] = fRec22[0];
			fRec25[2] = fRec25[1];
			fRec25[1] = fRec25[0];
			fRec24[1] = fRec24[0];
			fRec23[1] = fRec23[0];
			fRec26[2] = fRec26[1];
			fRec26[1] = fRec26[0];
			fRec29[2] = fRec29[1];
			fRec29[1] = fRec29[0];
			fRec28[1] = fRec28[0];
			fRec27[1] = fRec27[0];
			fRec30[2] = fRec30[1];
			fRec30[1] = fRec30[0];
			fRec33[2] = fRec33[1];
			fRec33[1] = fRec33[0];
			fRec32[1] = fRec32[0];
			fRec31[1] = fRec31[0];
			fRec34[2] = fRec34[1];
			fRec34[1] = fRec34[0];
			fRec37[2] = fRec37[1];
			fRec37[1] = fRec37[0];
			fRec36[1] = fRec36[0];
			fRec35[1] = fRec35[0];
			fRec38[2] = fRec38[1];
			fRec38[1] = fRec38[0];
			fRec41[2] = fRec41[1];
			fRec41[1] = fRec41[0];
			fRec40[1] = fRec40[0];
			fRec39[1] = fRec39[0];
			fRec42[2] = fRec42[1];
			fRec42[1] = fRec42[0];
			fRec45[2] = fRec45[1];
			fRec45[1] = fRec45[0];
			fRec44[1] = fRec44[0];
			fRec43[1] = fRec43[0];
			fRec46[2] = fRec46[1];
			fRec46[1] = fRec46[0];
			fRec49[2] = fRec49[1];
			fRec49[1] = fRec49[0];
			fRec48[1] = fRec48[0];
			fRec47[1] = fRec47[0];
			fRec50[2] = fRec50[1];
			fRec50[1] = fRec50[0];
			fRec53[2] = fRec53[1];
			fRec53[1] = fRec53[0];
			fRec52[1] = fRec52[0];
			fRec51[1] = fRec51[0];
			fRec54[2] = fRec54[1];
			fRec54[1] = fRec54[0];
			fRec57[2] = fRec57[1];
			fRec57[1] = fRec57[0];
			fRec56[1] = fRec56[0];
			fRec55[1] = fRec55[0];
			fRec58[2] = fRec58[1];
			fRec58[1] = fRec58[0];
			fRec61[2] = fRec61[1];
			fRec61[1] = fRec61[0];
			fRec60[1] = fRec60[0];
			fRec59[1] = fRec59[0];
			fRec62[2] = fRec62[1];
			fRec62[1] = fRec62[0];
			fRec65[2] = fRec65[1];
			fRec65[1] = fRec65[0];
			fRec64[1] = fRec64[0];
			fRec63[1] = fRec63[0];
			fRec66[2] = fRec66[1];
			fRec66[1] = fRec66[0];
			fRec69[2] = fRec69[1];
			fRec69[1] = fRec69[0];
			fRec68[1] = fRec68[0];
			fRec67[1] = fRec67[0];
			fRec70[2] = fRec70[1];
			fRec70[1] = fRec70[0];
			fRec73[2] = fRec73[1];
			fRec73[1] = fRec73[0];
			fRec72[1] = fRec72[0];
			fRec71[1] = fRec71[0];
			fRec74[2] = fRec74[1];
			fRec74[1] = fRec74[0];
			fRec77[2] = fRec77[1];
			fRec77[1] = fRec77[0];
			fRec76[1] = fRec76[0];
			fRec75[1] = fRec75[0];
			fRec78[2] = fRec78[1];
			fRec78[1] = fRec78[0];
			fRec81[2] = fRec81[1];
			fRec81[1] = fRec81[0];
			fRec80[1] = fRec80[0];
			fRec79[1] = fRec79[0];
			fRec82[2] = fRec82[1];
			fRec82[1] = fRec82[0];
			fRec85[2] = fRec85[1];
			fRec85[1] = fRec85[0];
			fRec84[1] = fRec84[0];
			fRec83[1] = fRec83[0];
			fRec86[2] = fRec86[1];
			fRec86[1] = fRec86[0];
			fRec89[2] = fRec89[1];
			fRec89[1] = fRec89[0];
			fRec88[1] = fRec88[0];
			fRec87[1] = fRec87[0];
			fRec90[2] = fRec90[1];
			fRec90[1] = fRec90[0];
			fRec93[2] = fRec93[1];
			fRec93[1] = fRec93[0];
			fRec92[1] = fRec92[0];
			fRec91[1] = fRec91[0];
			fRec94[2] = fRec94[1];
			fRec94[1] = fRec94[0];
			fRec97[2] = fRec97[1];
			fRec97[1] = fRec97[0];
			fRec96[1] = fRec96[0];
			fRec95[1] = fRec95[0];
			fRec98[2] = fRec98[1];
			fRec98[1] = fRec98[0];
			fRec101[2] = fRec101[1];
			fRec101[1] = fRec101[0];
			fRec100[1] = fRec100[0];
			fRec99[1] = fRec99[0];
			fRec102[2] = fRec102[1];
			fRec102[1] = fRec102[0];
			fRec105[2] = fRec105[1];
			fRec105[1] = fRec105[0];
			fRec104[1] = fRec104[0];
			fRec103[1] = fRec103[0];
			fRec106[2] = fRec106[1];
			fRec106[1] = fRec106[0];
			fRec109[2] = fRec109[1];
			fRec109[1] = fRec109[0];
			fRec108[1] = fRec108[0];
			fRec107[1] = fRec107[0];
			fRec110[2] = fRec110[1];
			fRec110[1] = fRec110[0];
			fRec113[2] = fRec113[1];
			fRec113[1] = fRec113[0];
			fRec112[1] = fRec112[0];
			fRec111[1] = fRec111[0];
			fRec114[2] = fRec114[1];
			fRec114[1] = fRec114[0];
			fRec117[2] = fRec117[1];
			fRec117[1] = fRec117[0];
			fRec116[1] = fRec116[0];
			fRec115[1] = fRec115[0];
			fRec118[2] = fRec118[1];
			fRec118[1] = fRec118[0];
			fRec121[2] = fRec121[1];
			fRec121[1] = fRec121[0];
			fRec120[1] = fRec120[0];
			fRec119[1] = fRec119[0];
			fRec122[2] = fRec122[1];
			fRec122[1] = fRec122[0];
			fRec125[2] = fRec125[1];
			fRec125[1] = fRec125[0];
			fRec124[1] = fRec124[0];
			fRec123[1] = fRec123[0];
			fRec126[2] = fRec126[1];
			fRec126[1] = fRec126[0];
			fRec129[2] = fRec129[1];
			fRec129[1] = fRec129[0];
			fRec128[1] = fRec128[0];
			fRec127[1] = fRec127[0];
			fRec130[2] = fRec130[1];
			fRec130[1] = fRec130[0];
			fRec133[2] = fRec133[1];
			fRec133[1] = fRec133[0];
			fRec132[1] = fRec132[0];
			fRec131[1] = fRec131[0];
			fRec134[2] = fRec134[1];
			fRec134[1] = fRec134[0];
			fRec137[2] = fRec137[1];
			fRec137[1] = fRec137[0];
			fRec136[1] = fRec136[0];
			fRec135[1] = fRec135[0];
			fRec138[2] = fRec138[1];
			fRec138[1] = fRec138[0];
			fRec141[2] = fRec141[1];
			fRec141[1] = fRec141[0];
			fRec140[1] = fRec140[0];
			fRec139[1] = fRec139[0];
			fRec142[2] = fRec142[1];
			fRec142[1] = fRec142[0];
			fRec145[2] = fRec145[1];
			fRec145[1] = fRec145[0];
			fRec144[1] = fRec144[0];
			fRec143[1] = fRec143[0];
			fRec146[2] = fRec146[1];
			fRec146[1] = fRec146[0];
			fRec149[2] = fRec149[1];
			fRec149[1] = fRec149[0];
			fRec148[1] = fRec148[0];
			fRec147[1] = fRec147[0];
			fRec150[2] = fRec150[1];
			fRec150[1] = fRec150[0];
			fRec153[2] = fRec153[1];
			fRec153[1] = fRec153[0];
			fRec152[1] = fRec152[0];
			fRec151[1] = fRec151[0];
			fRec154[2] = fRec154[1];
			fRec154[1] = fRec154[0];
			fRec157[2] = fRec157[1];
			fRec157[1] = fRec157[0];
			fRec156[1] = fRec156[0];
			fRec155[1] = fRec155[0];
			fRec158[2] = fRec158[1];
			fRec158[1] = fRec158[0];
			fRec161[2] = fRec161[1];
			fRec161[1] = fRec161[0];
			fRec160[1] = fRec160[0];
			fRec159[1] = fRec159[0];
			fRec162[2] = fRec162[1];
			fRec162[1] = fRec162[0];
			fRec165[2] = fRec165[1];
			fRec165[1] = fRec165[0];
			fRec164[1] = fRec164[0];
			fRec163[1] = fRec163[0];
			fRec168[2] = fRec168[1];
			fRec168[1] = fRec168[0];
			fRec167[1] = fRec167[0];
			fRec166[1] = fRec166[0];
			fRec169[2] = fRec169[1];
			fRec169[1] = fRec169[0];
			fRec172[2] = fRec172[1];
			fRec172[1] = fRec172[0];
			fRec171[1] = fRec171[0];
			fRec170[1] = fRec170[0];
			fRec173[2] = fRec173[1];
			fRec173[1] = fRec173[0];
			fRec176[2] = fRec176[1];
			fRec176[1] = fRec176[0];
			fRec175[1] = fRec175[0];
			fRec174[1] = fRec174[0];
			fRec177[2] = fRec177[1];
			fRec177[1] = fRec177[0];
			fRec180[2] = fRec180[1];
			fRec180[1] = fRec180[0];
			fRec179[1] = fRec179[0];
			fRec178[1] = fRec178[0];
			fRec181[2] = fRec181[1];
			fRec181[1] = fRec181[0];
			fRec184[2] = fRec184[1];
			fRec184[1] = fRec184[0];
			fRec183[1] = fRec183[0];
			fRec182[1] = fRec182[0];
			fRec185[2] = fRec185[1];
			fRec185[1] = fRec185[0];
			fRec188[2] = fRec188[1];
			fRec188[1] = fRec188[0];
			fRec187[1] = fRec187[0];
			fRec186[1] = fRec186[0];
			fRec189[2] = fRec189[1];
			fRec189[1] = fRec189[0];
			fRec192[2] = fRec192[1];
			fRec192[1] = fRec192[0];
			fRec191[1] = fRec191[0];
			fRec190[1] = fRec190[0];
			fRec193[2] = fRec193[1];
			fRec193[1] = fRec193[0];
			fRec196[2] = fRec196[1];
			fRec196[1] = fRec196[0];
			fRec195[1] = fRec195[0];
			fRec194[1] = fRec194[0];
			fRec197[2] = fRec197[1];
			fRec197[1] = fRec197[0];
			fRec200[2] = fRec200[1];
			fRec200[1] = fRec200[0];
			fRec199[1] = fRec199[0];
			fRec198[1] = fRec198[0];
			fRec201[2] = fRec201[1];
			fRec201[1] = fRec201[0];
			fRec204[2] = fRec204[1];
			fRec204[1] = fRec204[0];
			fRec203[1] = fRec203[0];
			fRec202[1] = fRec202[0];
			fRec205[2] = fRec205[1];
			fRec205[1] = fRec205[0];
			fRec208[2] = fRec208[1];
			fRec208[1] = fRec208[0];
			fRec207[1] = fRec207[0];
			fRec206[1] = fRec206[0];
			fRec209[2] = fRec209[1];
			fRec209[1] = fRec209[0];
			fRec212[2] = fRec212[1];
			fRec212[1] = fRec212[0];
			fRec211[1] = fRec211[0];
			fRec210[1] = fRec210[0];
			fRec213[2] = fRec213[1];
			fRec213[1] = fRec213[0];
			fRec216[2] = fRec216[1];
			fRec216[1] = fRec216[0];
			fRec215[1] = fRec215[0];
			fRec214[1] = fRec214[0];
			fRec217[2] = fRec217[1];
			fRec217[1] = fRec217[0];
			fRec220[2] = fRec220[1];
			fRec220[1] = fRec220[0];
			fRec219[1] = fRec219[0];
			fRec218[1] = fRec218[0];
			fRec221[2] = fRec221[1];
			fRec221[1] = fRec221[0];
			fRec222[2] = fRec222[1];
			fRec222[1] = fRec222[0];
			fRec225[2] = fRec225[1];
			fRec225[1] = fRec225[0];
			fRec224[1] = fRec224[0];
			fRec223[1] = fRec223[0];
			fRec226[2] = fRec226[1];
			fRec226[1] = fRec226[0];
			fRec229[2] = fRec229[1];
			fRec229[1] = fRec229[0];
			fRec228[1] = fRec228[0];
			fRec227[1] = fRec227[0];
			fRec230[2] = fRec230[1];
			fRec230[1] = fRec230[0];
			fRec233[2] = fRec233[1];
			fRec233[1] = fRec233[0];
			fRec232[1] = fRec232[0];
			fRec231[1] = fRec231[0];
			fRec234[2] = fRec234[1];
			fRec234[1] = fRec234[0];
			fRec237[2] = fRec237[1];
			fRec237[1] = fRec237[0];
			fRec236[1] = fRec236[0];
			fRec235[1] = fRec235[0];
			fRec238[2] = fRec238[1];
			fRec238[1] = fRec238[0];
			fRec241[2] = fRec241[1];
			fRec241[1] = fRec241[0];
			fRec240[1] = fRec240[0];
			fRec239[1] = fRec239[0];
			fRec242[2] = fRec242[1];
			fRec242[1] = fRec242[0];
			fRec245[2] = fRec245[1];
			fRec245[1] = fRec245[0];
			fRec244[1] = fRec244[0];
			fRec243[1] = fRec243[0];
			fRec246[2] = fRec246[1];
			fRec246[1] = fRec246[0];
			fRec249[2] = fRec249[1];
			fRec249[1] = fRec249[0];
			fRec248[1] = fRec248[0];
			fRec247[1] = fRec247[0];
			fRec250[2] = fRec250[1];
			fRec250[1] = fRec250[0];
			fRec253[2] = fRec253[1];
			fRec253[1] = fRec253[0];
			fRec252[1] = fRec252[0];
			fRec251[1] = fRec251[0];
			fRec254[2] = fRec254[1];
			fRec254[1] = fRec254[0];
			fRec257[2] = fRec257[1];
			fRec257[1] = fRec257[0];
			fRec256[1] = fRec256[0];
			fRec255[1] = fRec255[0];
			
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

        static void runAllGuis() {
            std::list<GUI*>::iterator g;
            for (g = fGuiList.begin(); g != fGuiList.end(); g++) {
                (*g)->run();
            }
        }
    
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

//-------------------------
// For timestamped control
//-------------------------

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
#include <assert.h>

class MapUI;

/*******************************************************************************
 * MIDI processor definition.
 *
 * MIDI input or output handling classes will implement this interface,
 * so the same method names (keyOn, ctrlChange...) will be used either
 * when decoding MIDI input or encoding MIDI output events.
 *******************************************************************************/

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

/****************************************************
 * Base class for MIDI input handling.
 *
 * Shared common code used for input handling:
 * - decoding Real-Time messages: handleSync
 * - decoding one data byte messages: handleData1
 * - decoding two data byte messages: handleData2
 ****************************************************/

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

//-------------------------------
// For timestamped MIDI messages
//-------------------------------

struct DatedMessage {
    
    double fDate;
    unsigned char fBuffer[3];
    size_t fSize;
    
    DatedMessage(double date, unsigned char* buffer, size_t size)
    :fDate(date), fSize(size)
    {
        assert(size <= 3);
        memcpy(fBuffer, buffer, size);
    }
    
    DatedMessage():fDate(0.0), fSize(0)
    {}
    
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

/*****************************************************************************
 * Base class for MIDI aware UI items
 ******************************************************************************/

class uiMidiItem : public uiMidi, public uiItem {
    
    public:
        
        uiMidiItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidi(midi_out, input), uiItem(ui, zone)
        {}
        virtual ~uiMidiItem()
        {}
    
        virtual void reflectZone() {}
    
};

/*****************************************************************************
 * Base class for MIDI aware UI items with timestamp support
 ******************************************************************************/

class uiMidiTimedItem : public uiMidi, public uiTimedItem {
    
    public:
        
        uiMidiTimedItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidi(midi_out, input), uiTimedItem(ui, zone)
        {}
        virtual ~uiMidiTimedItem()
        {}
    
        virtual void reflectZone() {}
    
};

//-------------
// MIDI sync
//-------------

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
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(v));
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
    void modifyZone(double date, FAUSTFLOAT v)
    {
        if (fInputCtrl) {
            uiItem::modifyZone(FAUSTFLOAT(v));
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
                //uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fState));
                uiItem::modifyZone(FAUSTFLOAT(fState));//uiMidiTimedItem
            }
        }

};

//----------------------
// Standard MIDI events
//----------------------

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

/******************************************************************************************
 * MidiUI : Faust User Interface
 * This class decodes MIDI metadata and maps incoming MIDI messages to them.
 * Currently ctrl, keyon/keyoff, keypress, pgm, chanpress, pitchwheel/pitchbend
 * start/stop/clock meta data are handled.
 *
 * Maps associating MIDI event ID (like each ctrl number) with all MIDI aware UI items
 * are defined and progressively filled when decoding MIDI related metadata.
 * MIDI aware UI items are used in both directions:
 *  - modifying their internal state when receving MIDI input events
 *  - sending their internal state as MIDI output events
 *******************************************************************************************/

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
    std::string url;
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
                
                else if (label == "url") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->url = value;
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

struct Soundfile;

typedef std::map<std::string, pair <int, FAUSTFLOAT*> > controlMap;

struct JSONUIDecoder {

    std::string fName;
    std::string fFileName;
    
    std::map<std::string, std::string> fMetadatas; 
    std::vector<itemInfo*> fUiItems;     
    
    FAUSTFLOAT* fInControl;
    FAUSTFLOAT* fOutControl;
    Soundfile** fSoundfiles;
    
    std::string fJSON;
    
    int fNumInputs, fNumOutputs; 
    int fInputItems, fOutputItems, fSoundfileItems;
    
    std::string fVersion;
    std::string fOptions;
    
    int fDSPSize;
    
    controlMap fPathInputTable;     // [path, <index, zone>]
    controlMap fPathOutputTable;    // [path, <index, zone>]
    
    bool isInput(const string& type) { return (type == "vslider" || type == "hslider" || type == "nentry" || type == "button" || type == "checkbox"); }
    bool isOutput(const string& type) { return (type == "hbargraph" || type == "vbargraph"); }
    bool isSoundfile(const string& type) { return (type == "soundfile"); }

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
        fSoundfileItems = 0;
        
        vector<itemInfo*>::iterator it;
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            string type = (*it)->type;
            if (isInput(type)) {
                fInputItems++;
            } else if (isOutput(type)) {
                fOutputItems++;          
            } else if (isSoundfile(type)) {
                fSoundfileItems++;
            }
        }
        
        fInControl = new FAUSTFLOAT[fInputItems];
        fOutControl = new FAUSTFLOAT[fOutputItems];
        fSoundfiles = new Soundfile*[fSoundfileItems];
        
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
        int counterSound = 0;
        vector<itemInfo*>::iterator it;
        
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            
            string type = (*it)->type;
            
            FAUSTFLOAT init = STR2REAL((*it)->init);
            FAUSTFLOAT min = STR2REAL((*it)->min);
            FAUSTFLOAT max = STR2REAL((*it)->max);
            FAUSTFLOAT step = STR2REAL((*it)->step);
            
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
            } else if (type == "soundfile") {
                ui->addSoundfile((*it)->label.c_str(), (*it)->url.c_str(), &fSoundfiles[counterSound]);
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
            
            if (isInput(type)) {
                counterIn++;
            } else if (isOutput(type)) {
                counterOut++;
            } else if (isSoundfile(type)) {
                counterSound++;
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
    void keyOn(int pitch, int velocity, bool trigger)
    {
        setParamValue(fFreqPath, midiToFreq(pitch));
        setParamValue(fGainPath, float(velocity)/127.f);
        fNote = pitch;
        fTrigger = trigger;
    }

    // Normalized MIDI velocity [0..1]
    void keyOn(int pitch, float velocity, bool trigger)
    {
        setParamValue(fFreqPath, midiToFreq(pitch));
        setParamValue(fGainPath, velocity);
        fNote = pitch;
        fTrigger = trigger;
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
                    snprintf(buffer, 32, ((fVoiceTable.size() < 8) ? "Voice%ld" : "V%ld"), long(i+1));
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
 * Base class for MIDI controllable DSP.
 */

class dsp_poly : public decorator_dsp, public midi {

    public:
    
        dsp_poly(dsp* dsp):decorator_dsp(dsp)
        {}
    
        virtual ~dsp_poly() {}
    
        // Group API
        virtual void setGroup(bool group) = 0;
        virtual bool getGroup() = 0;

};

/**
 * Polyphonic DSP: groups a set of DSP to be played together or triggered by MIDI.
 *
 * All voices are preallocated by cloning the single DSP voice given at creation time.
 * Dynamic voice allocation is done in 'getFreeVoice'
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
         *                setGroup/getGroup methods can be used to set/get the group state.
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
    
        // Terminate all active voices, gently or immediately (depending of 'hard' value)
        void allNotesOff(bool hard = false)
        {
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->keyOff(hard);
            }
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
    
        void setGroup(bool group) { fGroupControl = group; }
        bool getGroup() { return fGroupControl; }

        // MIDI API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            if (checkPolyphony()) {
                int voice = getFreeVoice();
                fVoiceTable[voice]->keyOn(pitch, velocity, true);
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

};

inline std::string pathToContent(const std::string& path)
{
    std::ifstream file(path.c_str(), std::ifstream::binary);
    
    file.seekg(0, file.end);
    int size = int(file.tellg());
    file.seekg(0, file.beg);
    
    // And allocate buffer to that a single line can be read...
    char* buffer = new char[size + 1];
    file.read(buffer, size);
    
    // Terminate the string
    buffer[size] = 0;
    string result = buffer;
    file.close();
    delete [] buffer;
    return result;
}

/**
 * Polyphonic DSP with an integrated effect. fPolyDSP will respond to MIDI messages.
 */
class dsp_poly_effect : public dsp_poly {
    
    private:
        
        dsp_poly* fPolyDSP;
        
    public:
        
        dsp_poly_effect(dsp_poly* dsp1, dsp* dsp2)
        :dsp_poly(dsp2), fPolyDSP(dsp1)
        {}
        
        virtual ~dsp_poly_effect()
        {
            // dsp_poly_effect is also a decorator_dsp, which will free fPolyDSP
        }
        
        // MIDI API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            return fPolyDSP->keyOn(channel, pitch, velocity);
        }
        void keyOff(int channel, int pitch, int velocity)
        {
            fPolyDSP->keyOff(channel, pitch, velocity);
        }
        void keyPress(int channel, int pitch, int press)
        {
            fPolyDSP->keyPress(channel, pitch, press);
        }
        void chanPress(int channel, int press)
        {
            fPolyDSP->chanPress(channel, press);
        }
        void ctrlChange(int channel, int ctrl, int value)
        {
            fPolyDSP->ctrlChange(channel, ctrl, value);
        }
        void ctrlChange14bits(int channel, int ctrl, int value)
        {
            fPolyDSP->ctrlChange14bits(channel, ctrl, value);
        }
        void pitchWheel(int channel, int wheel)
        {
            fPolyDSP->pitchWheel(channel, wheel);
        }
        void progChange(int channel, int pgm)
        {
            fPolyDSP->progChange(channel, pgm);
        }
        
        // Group API
        void setGroup(bool group)
        {
            fPolyDSP->setGroup(group);
        }
        bool getGroup()
        {
            return fPolyDSP->getGroup();
        }
};

/**
 * Polyphonic DSP factory class. Helper code to support polyphonic DSP source with an integrated effect.
 */

struct dsp_poly_factory : public dsp_factory {
    
    dsp_factory* fProcessFactory;
    dsp_factory* fEffectFactory;
    
    std::string getEffectCode(const std::string& dsp_content)
    {
        std::stringstream effect_code;
        effect_code << "adapt(1,1) = _; adapt(2,2) = _,_; adapt(1,2) = _ <: _,_; adapt(2,1) = _,_ :> _;";
        effect_code << "adaptor(F,G) = adapt(outputs(F),inputs(G)); dsp_code = environment{ " << dsp_content << " };";
        effect_code << "process = adaptor(dsp_code.process, dsp_code.effect) : dsp_code.effect;";
        return effect_code.str();
    }

    dsp_poly_factory(dsp_factory* process_factory = NULL,
                     dsp_factory* effect_factory = NULL):
    fProcessFactory(process_factory)
    ,fEffectFactory(effect_factory)
    {}
    
    virtual ~dsp_poly_factory()
    {}
    
    virtual std::string getName() { return fProcessFactory->getName(); }
    virtual std::string getSHAKey() { return fProcessFactory->getSHAKey(); }
    virtual std::string getDSPCode() { return fProcessFactory->getDSPCode(); }
    
    virtual std::vector<std::string> getDSPFactoryLibraryList() { return fProcessFactory->getDSPFactoryLibraryList(); }
    virtual std::vector<std::string> getDSPFactoryIncludePathnames() { return fProcessFactory->getDSPFactoryIncludePathnames(); }
    
    virtual void setMemoryManager(dsp_memory_manager* manager)
    {
        fProcessFactory->setMemoryManager(manager);
        if (fEffectFactory) {
            fEffectFactory->setMemoryManager(manager);
        }
    }
    virtual dsp_memory_manager* getMemoryManager() { return fProcessFactory->getMemoryManager(); }
    
    /* Create a new polyphonic DSP instance with global effect, to be deleted with C++ 'delete'
     *
     * @param nvoices - number of polyphony voices
     * @param control - whether voices will be dynamically allocated and controlled (typically by a MIDI controler).
     *                If false all voices are always running.
     * @param group - if true, voices are not individually accessible, a global "Voices" tab will automatically dispatch
     *                a given control on all voices, assuming GUI::updateAllGuis() is called.
     *                If false, all voices can be individually controlled.
     */
    dsp_poly* createPolyDSPInstance(int nvoices, bool control, bool group)
    {
        dsp_poly* dsp_poly = new mydsp_poly(fProcessFactory->createDSPInstance(), nvoices, control, group);
        if (fEffectFactory) {
            // the 'dsp_poly' object has to be controlled with MIDI, so kept separated from new dsp_sequencer(...) object
            return new dsp_poly_effect(dsp_poly, new dsp_sequencer(dsp_poly, fEffectFactory->createDSPInstance()));
        } else {
            return new dsp_poly_effect(dsp_poly, dsp_poly);
        }
    }
    
    /* Create a new DSP instance, to be deleted with C++ 'delete' */
    dsp* createDSPInstance()
    {
        return fProcessFactory->createDSPInstance();
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
    // SoundUI has to be dispatched on all internal voices
    if (dsp_poly) dsp_poly->setGroup(false);
    x->m_dsp->buildUserInterface(x->m_soundInterface);
    if (dsp_poly) dsp_poly->setGroup(true);
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
