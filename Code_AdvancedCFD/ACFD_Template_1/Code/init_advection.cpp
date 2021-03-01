//
//  init_advection.cpp
//  AdvancedCFD
//
//  Created by Patrick Jenny on 05/01/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#include "init_advection.h"
#include "grid.h"
#include <math.h>

//
// 1d tophat
//
void Init_Advection::init_1d_tophat (Grid* g) const {
  //
  // EDIT
  //
}

//
// 1d sin
//
void Init_Advection::init_1d_sin (Grid* g) const {
  for (int i=0; i < g->n(0); i++) {
    for (int j=0; j < g->n(1); j++) {
      for (int k=0; k < g->n(2); k++) {
        for (int iv=0; iv < g->nv(); iv++) {
          g->u(i,j,k)[0] = sin(g->x(0,i,j,k)*2.*M_PI);
        }
      }
    }
  }
}

//
// 2d tophat
//
void Init_Advection::init_2d_tophat (Grid* g) const {
  //
  // EDIT
  //
}

//
// 2d sin
//
void Init_Advection::init_2d_sin (Grid* g) const {
  for (int i=0; i < g->n(0); i++) {
    for (int j=0; j < g->n(1); j++) {
      for (int k=0; k < g->n(2); k++) {
        for (int iv=0; iv < g->nv(); iv++) {
          g->u(i,j,k)[0] = sin(g->x(0,i,j,k)*2.*M_PI)*sin(g->x(1,i,j,k)*2.*M_PI);
        }
      }
    }
  }
}
