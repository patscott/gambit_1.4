// ====================================================================
// This file is part of FlexibleSUSY.
//
// FlexibleSUSY is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published
// by the Free Software Foundation, either version 3 of the License,
// or (at your option) any later version.
//
// FlexibleSUSY is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with FlexibleSUSY.  If not, see
// <http://www.gnu.org/licenses/>.
// ====================================================================

// File generated at Mon 1 Jun 2015 13:14:17

/**
 * @file NUHMSSM_two_scale_model.cpp
 * @brief implementation of the NUHMSSM model class
 *
 * Contains the definition of the NUHMSSM model class methods
 * which solve EWSB and calculate pole masses and mixings from DRbar
 * parameters.
 *
 * This file was generated at Mon 1 Jun 2015 13:14:17 with FlexibleSUSY
 * 1.1.0 (git commit: v1.1.0) and SARAH 4.5.6 .
 */

#include "NUHMSSM_two_scale_model.hpp"

namespace flexiblesusy {

using namespace NUHMSSM_info;

#define CLASSNAME NUHMSSM<Two_scale>

CLASSNAME::NUHMSSM(const NUHMSSM_input_parameters& input_)
   : Two_scale_model()
   , NUHMSSM_mass_eigenstates(input_)
{
}

CLASSNAME::~NUHMSSM()
{
}

void CLASSNAME::calculate_spectrum()
{
   NUHMSSM_mass_eigenstates::calculate_spectrum();
}

void CLASSNAME::clear_problems()
{
   NUHMSSM_mass_eigenstates::clear_problems();
}

std::string CLASSNAME::name() const
{
   return NUHMSSM_mass_eigenstates::name();
}

void CLASSNAME::run_to(double scale, double eps)
{
   NUHMSSM_mass_eigenstates::run_to(scale, eps);
}

void CLASSNAME::print(std::ostream& out) const
{
   NUHMSSM_mass_eigenstates::print(out);
}

void CLASSNAME::set_precision(double p)
{
   NUHMSSM_mass_eigenstates::set_precision(p);
}

} // namespace flexiblesusy