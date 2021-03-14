//
//  init_nsincompressible.h
//  AdvancedCFD
//
//  Created by Patrick Jenny on 05/01/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#ifndef AdvancedCFD_init_nsincompressible_h
#define AdvancedCFD_init_nsincompressible_h

#include "init.h"
#include "grid.h"
#include <stdio.h>

/**
 * \brief Initial condition for the compressible Navier-Stokes equations
 */
class Init_NSIncompressible : public Init {
public:
  Init_NSIncompressible    (Control* c)
  : Init(c) {}
  ~Init_NSIncompressible   ()           {}
  /**
   * Defines the initial condition given an entry in the control file.
   * - 2: uniform field
   */
  void operator () (Grid* g) const {
    switch (_c->getInt("Case_Init")) {
      case 2:  init_2d_uniform       (g);    break;
      default: printf("\nInitial condition not defined\n"); break;
    }
  }
private:
  void init_2d_uniform(Grid* g) const;
};

#endif
