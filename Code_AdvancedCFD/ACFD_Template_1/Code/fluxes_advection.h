//
//  fluxes_advection.h
//  AdvancedCFD
//
//  Created by Patrick Jenny on 06/01/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#ifndef AdvancedCFD_fluxes_advection_h
#define AdvancedCFD_fluxes_advection_h

#include "fluxes.h"
#include "control.h"
#include <stdio.h>

/**
 * \brief Computation of fluxes for the linear advection-diffusion equation
 */
class Fluxes_Advection : public Fluxes {
public:
  Fluxes_Advection  (Control* c, Grid* g);
  ~Fluxes_Advection () {}
  /**
   * Compute fluxes using a MUSCL or central scheme for the advection term.
   * The central scheme is used for the diffusion term.
   *
   * The value of the key "Case_Fluxes" is read from the control file and used
   * for the discretization of the advection term.
   * - 1: MUSCL scheme
   * - 2: central scheme
   *
   * The upwind scheme can be used by selecting the MUSCL scheme and setting
   * key "muscl" to 0 in the control file.
   *
   * The advection velocity is read from the key "a".
   *
   * The diffusion coefficient corresponds to the key "mu".
   */
  void operator () (Grid* g) const {
    switch (_c->getInt("Case_Fluxes")) {
      case 1:  fluxes_conv_upwind (g);           break;
      case 2:  fluxes_conv_central(g);           break;
      default: printf("\nFluxes not defined\n"); break;
    }
  }
private:
  /**
   * Central scheme for the advection term
   */
  void fluxes_conv_central (Grid* g) const;
  /**
   * Upwind scheme for the advection term
   */
  void fluxes_conv_upwind  (Grid* g) const;
};

#endif
