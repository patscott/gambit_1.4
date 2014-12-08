//   GAMBIT: Global and Modular BSM Inference Tool
//   *********************************************
///  \file
///
///  Types used internally, returned and/or read
///  in by more than one backend, model or module.
///
///  *********************************************
///
///  Authors (add name and date if you modify):
///   
///  \author Pat Scott  
///          (patscott@physics.mcgill.ca)
///  \date 2013 Apr, Oct
///  \date 2014 Mar, Sep, Nov
///
///  \author Abram Krislock
///          (abram.krislock@fysik.su.se)
///  \date 2013 Dec
//
///  \author Christoph Weniger
///          (c.weniger@uva.nl)
///  \date 2014 Mar
///
///  \author Anders Kvellestad
///          (anderkve@fys.uio.no)
///  \date 2014 Oct
///
///  *********************************************

#ifndef __shared_types_hpp__
#define __shared_types_hpp__

#include "model_parameters.hpp"        // Definitions required to understand model parameter objects
#include "base_functions.hpp"          // GAMBIT BaseFunction Objects
#include "funktions.hpp"               // GAMBIT Funktions (replaces BaseFunctions)
#include "SLHA_readers.hpp"            // SLHA readers from contributed packages

// Other types that don't belong in any of the existing includes.  As the number of such types grows, they
// should be progressively organised into new headers, and those headers included from here.
namespace Gambit
{ 
  // Pointer to a function that takes an integer by reference and returns a double.
  // Just used for example purposes in ExampleBit_A and ExampleBit_B.
  typedef double(*fptr)(int&); 
}

#include "default_bossed_versions.hpp" // Default versions of backends to use when employing BOSSed types
#include "backend_types_rollcall.hpp"  // All backend types (header is auto-generated by backend harvester).

#endif //__shared_types_hpp__


