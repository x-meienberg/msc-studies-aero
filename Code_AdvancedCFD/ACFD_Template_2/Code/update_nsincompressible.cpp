//
//  update_nscompressible.cpp
//  AdvancedCFD
//
//  Created by Patrick Jenny on 06/01/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#include "update_nsincompressible.h"
#include "grid.h"
#include "system.h"

void Update_NSIncompressible::operator () (Grid* g, double dt, double weight) const {
  for (int i=0; i < g->n(0); i++) {
    for (int j=0; j < g->n(1); j++) {
      for (int k=0; k < g->n(2); k++) {
        for (int ind=1; ind<3; ind++) {
          g->rhs(i,j,k)[ind] *= weight;
          g->rhs(i,j,k)[ind] -= (((g->f(0,i+1,j,k)[ind] - g->f(0,i,j,k)[ind])/g->dx(0) + (g->f(1,i,j+1,k)[ind] - g->f(1,i,j,k)[ind])/g->dx(1)));
          g->rhs(i,j,k)[ind] += g->q(i,j,k)[ind];
        }
      }
    }
  }
  (*_sy)(dt);
  for (int i=0; i < g->n(0); i++) {
    int im = g->periodic_index(i,-1,0);
    int ip = g->periodic_index(i, 1,0);
    for (int j=0; j < g->n(1); j++) {
      int jm = g->periodic_index(j,-1,1);
      int jp = g->periodic_index(j, 1,1);
      for (int k=0; k < g->n(2); k++) {
    	//TODO Implement the contribution of the pressure gradient



        g->u(i,j,k)[1] += dt*g->rhs(i,j,k)[1];
        g->u(i,j,k)[2] += dt*g->rhs(i,j,k)[2];
      }
    }
  }
}
