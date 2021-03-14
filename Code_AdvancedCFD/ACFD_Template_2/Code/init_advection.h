//
//  init_advection.h
//  AdvancedCFD
//
//  Created by Patrick Jenny on 05/01/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#ifndef AdvancedCFD_init_advection_h
#define AdvancedCFD_init_advection_h

#include "init.h"
#include <stdio.h>

/**
 * \brief Initial condition for the linear advection-diffusion equation
 */
class Init_Advection : public Init {
public:
  Init_Advection   (Control* c)
	: Init(c) {}
  ~Init_Advection  ()           {}
  /**
   * Defines the initial condition given an entry in the control file.
   * - 1: 1D top hat
   * - 2: 1D sine wave
   * - 3: 2D top hat
   * - 4: 2D sine wave
   */
  void operator () (Grid* g) const {
    switch (_c->getInt("Case_Init")) {
      case 1:  init_1d_tophat (g);                          break;
      case 2:  init_1d_sin    (g);                          break;
      case 3:  init_2d_tophat (g);                          break;
      case 4:  init_2d_sin    (g);                          break;
      default: printf("\nInitial condition not defined\n"); break;
    }
  }
private:
  void init_1d_tophat (Grid* g) const;
  void init_1d_sin    (Grid* g) const;
  void init_2d_tophat (Grid* g) const;
  void init_2d_sin    (Grid* g) const;
};

#endif
