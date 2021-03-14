//
//  fluxes_nsincompressible.h
//  AdvancedCFD
//
//  Created by Patrick Jenny on 06/01/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#ifndef AdvancedCFD_fluxes_nsincompressible_h
#define AdvancedCFD_fluxes_nsincompressible_h

#include "fluxes.h"
#include "grid.h"
#include "control.h"
#include <stdio.h>

/**
 * \brief Computation of fluxes for the incompressible Navier-Stokes equations
 */
class Fluxes_NSIncompressible : public Fluxes {
public:
  Fluxes_NSIncompressible (Control* c, Grid* g);
  ~Fluxes_NSIncompressible()           {}
  /**
   * Compute fluxes.
   */
  void operator ()        (Grid* g) const;
private:
};

#endif
