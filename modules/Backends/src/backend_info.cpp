//   GAMBIT: Global and Modular BSM Inference Tool
//   *********************************************
///  \file
///
///  Simple container used for storing info about
///  backends during initialisation time.
///
///  *********************************************
///
///  Authors (add name and date if you modify):
///   
///  \author Pat Scott  
///          (patscott@physics.mcgill.ca)
///  \date 2014 Dec
///
///  *********************************************

#include "gambit/Backends/backend_info.hpp"
#include "gambit/cmake/cmake_variables.hpp"

namespace Gambit
{

  // Public method definitions for backend_info class 

  /// Constructor
  Backends::backend_info::backend_info() : 
   filename(GAMBIT_DIR "/config/backend_locations.yaml")
  {
    // Read yaml configuration file
    try
    { 
      bepathfile = YAML::LoadFile(filename);
    } 
    catch (YAML::Exception &e)
    {
      std::ostringstream msg;
      msg << "Could not read backend locations file \""<<filename<<"\"!" << endl;
      msg << "Please check that file exists and contains valid YAML." << endl;
      msg << "("<<e.what()<<")";
      utils_error().raise(LOCAL_INFO,msg.str());
    }
  }

  /// Return the path to a backend library, given a backend name and version.
  str Backends::backend_info::path(str be, str ver) const
  {
    const str default_path("no path in config/backend_locations.yaml"); 
    str p;
    auto be_it = bepathoverrides.find(be);
    bool override_present = (be_it != bepathoverrides.end()); 
    if (override_present)
    {
      auto ver_it = be_it->second.find(ver);
      if (ver_it != be_it->second.end())
      {
        p = ver_it->second;
        if (p.substr(0,2) == "./") p = p.substr(2,p.npos);
      }
      else 
      {
        override_present = false;
      }
    }  
    if (not override_present)
    {
      if (bepathfile[be][ver])
      {
        p = bepathfile[be][ver].as<str>();
        if (p.substr(0,2) == "./") p = p.substr(2,p.npos);
      }
      else
      {      
        p = default_path;
        std::ostringstream msg;
        msg << "Could not find path for backend "<< be <<" v" << ver << endl;
        msg << "in " << filename << "." << endl;
        msg << "Setting path to \"" << default_path << "\".";
        utils_warning().raise(LOCAL_INFO,msg.str());
      }
    }
    return p;
  }

  /// Return the complete path to a backend library, given a backend name and version.
  str Backends::backend_info::corrected_path(str be, str ver) const
  {
    str p = path(be,ver);
    if (p.substr(0,1) != "/")
    {
      p = GAMBIT_DIR "/"+p;
    }
    return p;
  }

  /// Return the path to the folder in which a backend library resides
  str Backends::backend_info::path_dir(str be, str ver) const
  {
    str p = corrected_path(be,ver);
    for (int i = p.length()-1; i >= 0; --i)
    {
      if (p[i] == '/') return p.substr(0,i); 
    }  
    return p;
  }

  /// Given a backend and a safe version (with no periods), return the true version
  str Backends::backend_info::version_from_safe_version (str be, str sv) const 
  { 
    return safe_version_map.at(be).first.at(sv);
  } 
 
  /// Given a backend and a true version (with periods), return the safe version
  str Backends::backend_info::safe_version_from_version (str be, str v) const 
  { 
    return safe_version_map.at(be).second.at(v);
  } 

  /// Link a backend's version and safe version
  void Backends::backend_info::link_versions(str be, str v, str sv)
  {
    safe_version_map[be].first[sv] = v;
    safe_version_map[be].second[v] = sv;
  }

  /// Override a backend's config file location
  void Backends::backend_info::override_path(str& be, str& ver, str path)
  {
    int l = str(GAMBIT_DIR).length();
    if (path.substr(0,l) == GAMBIT_DIR) path.replace(0, l, ".");
    bepathoverrides[be][ver] = path;
  }

}



