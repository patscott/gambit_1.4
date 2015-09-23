//   GAMBIT: Global and Modular BSM Inference Tool
//   *********************************************
///  \file
///
///  Basic set of known mathematical and physical
///  constants for GAMBIT.
///
///  *********************************************
///
///  Authors (add name and date if you modify):
///   
///  \author Pat Scott 
///          (p.scott@imperial.ac.uk)
///  \date   2015 Mar
///
///  \author Christoph Weniger
///          (c.weniger@uva.nl)
///  \date   2015 Apr
//
///  *********************************************

#ifndef __numerical_constants_hpp__
#define __numerical_constants_hpp__

#include <cmath>

namespace Gambit
{

  const double pi = 3.141592653589793238462643383279502884197;
  const double root2 = sqrt(2.0);
  const double gev2cm2 = pow(197.327053e-16, 2.0);              // cm^2 per GeV^-2
  const double gev2pb = gev2cm2*1e36;                           // pb per GeV^-2
  const double s2cm = 2.99792458e10;                            // cm per s
  const double atomic_mass_unit=0.931494028;                    // atomic mass unit (GeV/c^2)
  const double m_proton_amu = 1.00727646688;                    // proton mass (amu)
  const double m_neutron_amu = 1.0086649156;                    // neutron mass (amu)
  const double m_proton = m_proton_amu * atomic_mass_unit;      // proton mass (GeV/c^2)
  const double m_neutron = m_neutron_amu * atomic_mass_unit;    // neutron mass (GeV/c^2)    

}

#endif //#defined __numerical_constants_hpp__
