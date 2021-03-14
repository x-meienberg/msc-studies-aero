//
//  init_nsincompressible.cpp
//  AdvancedCFD
//
//  Created by Patrick Jenny on 05/01/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#include "init_nsincompressible.h"

void Init_NSIncompressible::init_2d_uniform (Grid* g) const {
  for (int i=0; i < g->n(0); i++) {
    for (int j=0; j < g->n(1); j++) {
      for (int k=0; k < g->n(2); k++) {
        g->u(i,j,k)[0] =      0.0;
        g->u(i,j,k)[1] =      0.0;
        g->u(i,j,k)[2] =      0.0;
      }
    }
  }
}
