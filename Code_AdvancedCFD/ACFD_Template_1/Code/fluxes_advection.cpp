//
//  fluxes_advection.cpp
//  AdvancedCFD
//
//  Created by Patrick Jenny on 06/01/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#include "fluxes_advection.h"
#include "grid.h"

Fluxes_Advection::Fluxes_Advection (Control* c, Grid* g)
: Fluxes(c, g)
{}

void Fluxes_Advection::fluxes_conv_central (Grid* g) const {
  double a[3] = {_c->getDouble("a",1),_c->getDouble("a",2),_c->getDouble("a",3)};
  for (int i=0; i < g->n(0); i++) {
    int im = g->periodic_index(i, -1, 0);
    for (int j=0; j < g->n(1); j++) {
      int jm = g->periodic_index(j, -1, 1);
      for (int k=0; k < g->n(2); k++) {
        int km = g->periodic_index(k, -1, 2);
        for (int ind=0; ind < g->nv(); ind++) {
          g->f(0,i,j,k)[ind] = a[0]*0.5*(g->u(i,j,k)[ind] + g->u(im,j ,k )[ind]);
          g->f(1,i,j,k)[ind] = a[1]*0.5*(g->u(i,j,k)[ind] + g->u(i ,jm,k )[ind]);
          g->f(2,i,j,k)[ind] = a[2]*0.5*(g->u(i,j,k)[ind] + g->u(i ,j ,km)[ind]);
        }
      }
    }
  }
}

void Fluxes_Advection::fluxes_conv_upwind (Grid* g) const {
  double a[3] = {_c->getDouble("a",1),_c->getDouble("a",2),_c->getDouble("a",3)};
  //
  // EDIT
  //
}
