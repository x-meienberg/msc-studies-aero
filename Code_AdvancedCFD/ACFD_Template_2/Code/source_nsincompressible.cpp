//
//  source_nsincompressible.cpp
//  AdvancedCFD
//
//  Created by Patrick Jenny on 05/01/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#include "source_nsincompressible.h"

#include "grid.h"
#include "time.h"
#include <math.h>

Source_NSIncompressible::Source_NSIncompressible (Control* c, Grid* g, Time* t)
: Source(g),
  _t(t),
  _c(c)
{}

void Source_NSIncompressible::source_oscillating_cylinder (Grid* g) const {
  double h     = double(g->n(1))*g->dx(1);
  double r     = 0.125*h;
  double xo[2] = {0.5*h,(0.5 + 0.25*sin(_t->t()*300.0))*h};
  double vo[2] = {0.0  ,(300.0*0.25*cos(_t->t()*300.0))*h};
  for (int i=0; i < g->n(0); i++) {
    for (int j=0; j < g->n(1); j++) {
      for (int k=0; k < g->n(2); k++) {
        for (int iv=0; iv < g->nv(); iv++) {
          g->q(i,j,k)[iv] = 0.0;
        }
        double d[2] = {g->x(0,i,j,k)-xo[0],g->x(1,i,j,k)-xo[1]};
        if (pow(d[0],2)+pow(d[1],2)<pow(r,2)) {
          g->q(i,j,k)[1] = -1000.0*(g->u(i,j,k)[1]-vo[0]);
          g->q(i,j,k)[2] = -1000.0*(g->u(i,j,k)[2]-vo[1]);
        }
      }
    }
  }
}

void Source_NSIncompressible::source_pump (Grid* g) const {
  double omega = 0.5/_t->dt();
  double h     = double(g->n(1))*g->dx(1);
  double r     = 0.3*h*( 1.0 + 0.5*sin(_t->t()*50.0));
  double v     = 0.3*h*(50.0 * 0.5*cos(_t->t()*50.0));
  double xo[2] = {0.5*h,0.5*h};
  for (int i=0; i < g->n(0); i++) {
    for (int j=0; j < g->n(1); j++) {
      for (int k=0; k < g->n(2); k++) {
        for (int iv=0; iv < g->nv(); iv++) {
          g->q   (i,j,k)[iv] = 0.0;
        }
        double d[2] = {g->x(0,i,j,k)-xo[0],g->x(1,i,j,k)-xo[1]};
        double dist = sqrt(pow(d[0],2)+pow(d[1],2));
        if (dist<r && dist>r-0.04*h && (d[0]*d[0]>(0.051*h)*(0.051*h) || d[1]<0.0)) {
          double velo  = v*dist/r;
          double vo[2] = {velo*d[0]/dist,velo*d[1]/dist};
          g->q(i,j,k)[1] = -omega*(g->u(i,j,k)[1] - vo[0]);
          g->q(i,j,k)[2] = -omega*(g->u(i,j,k)[2] - vo[1]);
        }
      }
    }
  }
}
