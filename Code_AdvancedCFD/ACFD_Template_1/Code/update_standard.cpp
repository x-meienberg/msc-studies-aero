//
//  update_standard.cpp
//  AdvancedCFD
//
//  Created by Patrick Jenny on 06/01/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#include "update_standard.h"
#include "grid.h"
#include <stdio.h>

void Update_Standard::operator () (Grid* g, double dt, double weight) const {
  for (int i=0; i < g->n(0); i++) {
    for (int j=0; j < g->n(1); j++) {
      for (int k=0; k < g->n(2); k++) {
        for (int ind=0; ind < g->nv(); ind++) {
          g->rhs(i,j,k)[ind] *= weight;
          g->rhs(i,j,k)[ind] -= ((g->f(0,i+1,j  ,k  )[ind] - g->f(0,i,j,k)[ind])/g->dx(0)
                               + (g->f(1,i  ,j+1,k  )[ind] - g->f(1,i,j,k)[ind])/g->dx(1)
                               + (g->f(2,i  ,j  ,k+1)[ind] - g->f(2,i,j,k)[ind])/g->dx(2));
          g->rhs(i,j,k)[ind] += g->q(i,j,k)[ind];
          g->u  (i,j,k)[ind] += dt*g->rhs(i,j,k)[ind];
          g->u  (i,j,k)[ind]  = g->u(i,j,k)[ind]/ g->diag(i,j,k)[ind];
          g->rhs(i,j,k)[ind] -= g->u(i,j,k)[ind]*(g->diag(i,j,k)[ind]-1.0);
        }
      }
    }
  }
}
