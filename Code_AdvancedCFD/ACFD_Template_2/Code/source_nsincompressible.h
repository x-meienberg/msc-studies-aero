//
//  source_nsincompressible.h
//  AdvancedCFD
//
//  Created by Patrick Jenny on 05/01/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#ifndef AdvancedCFD_source_nsincompressible_h
#define AdvancedCFD_source_nsincompressible_h

#include "source.h"
#include "control.h"

class Grid;
class Time;

/**
 * \brief Source terms for the compressible Navier-Stokes equations.
 *
 * Two source terms are available: an oscillating cylinder and a pump.
 */
class Source_NSIncompressible : public Source {
public:
  Source_NSIncompressible (Control* c, Grid* g, Time* t);
  /**
   * Set the source term value in the Grid object.
   * The source term is chosen according to the entry "Case_Source" in the control file.
   * - 1: oscillating cylinder
   * - 2: pump (contracting cylinder with a slit)
   */
  void operator ()      (Grid* g) const {
    switch (_c->getInt("Case_Source")) {
      case 1:  source_oscillating_cylinder (g);  break;
      case 2:  source_pump                 (g);  break;
      default:                                   break;
    }
  }
private:
  void source_oscillating_cylinder (Grid* g) const;
  void source_pump                 (Grid* g) const;
  Time*    _t;
  Control* _c;
};

#endif
