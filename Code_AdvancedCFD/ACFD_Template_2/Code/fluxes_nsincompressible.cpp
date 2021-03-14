//
//  fluxes_nsincompressible.cpp
//  AdvancedCFD
//
//  Created by Patrick Jenny on 06/01/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#include "fluxes_nsincompressible.h"

Fluxes_NSIncompressible::Fluxes_NSIncompressible (Control* c, Grid* g)
: Fluxes(c, g)
{}

void Fluxes_NSIncompressible::operator () (Grid* g) const {
  double muscl = _c->getDouble("muscl");
  for (int i=0; i < g->n(0); i++) {
    int ip  = g->periodic_index(i, +1, 0);
    int im  = g->periodic_index(i, -1, 0);
    int imm = g->periodic_index(i, -2, 0);
    for (int j=0; j < g->n(1); j++) {
      int jp  = g->periodic_index(j, +1, 1);
      int jm  = g->periodic_index(j, -1, 1);
      int jmm = g->periodic_index(j, -2, 1);
      double a0 = (g->u(i,j,0)[1] + g->u(im,j,0)[1])/2.0;
      double a1 = (g->u(i,j,0)[2] + g->u(i,jm,0)[2])/2.0;
      double u0, u1;
      if (a0>0.0) {
        u0 = g->u(im,j,0)[1] + muscl*0.5*minmod(g->u(im,j,0)[1]-g->u(imm,j,0)[1],g->u(i,j,0)[1]-g->u(im,j,0)[1]);
        u1 = g->u(im,j,0)[2] + muscl*0.5*minmod(g->u(im,j,0)[2]-g->u(imm,j,0)[2],g->u(i,j,0)[2]-g->u(im,j,0)[2]);
      }
      else {
        u0 = g->u(i ,j,0)[1] - muscl*0.5*minmod(g->u(ip,j,0)[1]-g->u(i,j,0)[1],g->u(i,j,0)[1]-g->u(im,j,0)[1]);
        u1 = g->u(i ,j,0)[2] - muscl*0.5*minmod(g->u(ip,j,0)[2]-g->u(i,j,0)[2],g->u(i,j,0)[2]-g->u(im,j,0)[2]);
      }
      g->f(0,i,j,0)[1] = u0*u0;
      g->f(0,i,j,0)[2] = u0*u1;
      if (a1>0.0) {
        u0 = g->u(i,jm,0)[1] + muscl*0.5*minmod(g->u(i,jm,0)[1]-g->u(i,jmm,0)[1],g->u(i,j,0)[1]-g->u(i,jm,0)[1]);
        u1 = g->u(i,jm,0)[2] + muscl*0.5*minmod(g->u(i,jm,0)[2]-g->u(i,jmm,0)[2],g->u(i,j,0)[2]-g->u(i,jm,0)[2]);
      }
      else {
        u0 = g->u(i,j ,0)[1] - muscl*0.5*minmod(g->u(i,jp,0)[1]-g->u(i,j,0)[1],g->u(i,j,0)[1]-g->u(i,jm,0)[1]);
        u1 = g->u(i,j ,0)[2] - muscl*0.5*minmod(g->u(i,jp,0)[2]-g->u(i,j,0)[2],g->u(i,j,0)[2]-g->u(i,jm,0)[2]);
      }
      g->f(1,i,j,0)[1] = u1*u0;
      g->f(1,i,j,0)[2] = u1*u1;
    }
  }
}
