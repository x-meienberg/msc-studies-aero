//
//  fluxes.cpp
//  AdvancedCFD
//
//  Created by Adrien Lücker on 11/01/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#include "fluxes.h"
#include "control.h"
#include "grid.h"

Fluxes::Fluxes (Control* c, Grid* g)
: _c(c)
{
  reinitialize_fluxes(g);
}

void Fluxes::reinitialize_fluxes(Grid* g) const
{
  for (int i=0; i < g->n(0)+1; i++) {
    for (int j=0; j < g->n(1)+1; j++) {
      for (int k=0; k < g->n(2)+1; k++) {
        for (int ind=0; ind < g->nv(); ind++) {
          g->f(0,i,j,k)[ind] = 0.0;
          g->f(1,i,j,k)[ind] = 0.0;
          g->f(2,i,j,k)[ind] = 0.0;
        }
      }
    }
  }
}




