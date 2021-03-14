//
//  postprocess_advection.cpp
//  AdvancedCFD
//
//  Created by Adrien Lücker on 09/02/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#include "postprocess_advection.h"
#include "grid.h"
#include <cmath>
#include <stdio.h>

void Postprocess_Advection::L2_error_1d_tophat (Grid* g, const double t) const {
  double rms_error = 0.0;
  double a[3] = {_c->getDouble("a",1),_c->getDouble("a",2),_c->getDouble("a",3)};
  for (int i=0; i < g->n(0); i++) {
    for (int j=0; j < g->n(1); j++) {
      for (int k=0; k < g->n(2); k++) {
        //
        // Compute the position at t=0 that corresponds to the current position,
        // by account on the domain periodicity.
        //
        double x_adv = wrap_to_interval(g->x(0, i, j, k) - a[0]*t, g->length(0));
        double u_ex  = 0.0;
        if (x_adv >= g->length(0)/4. && x_adv <= g->length(0)*3./4.) {
          u_ex = 1.0;
        }
        rms_error += std::pow(u_ex - g->u(i,j,k)[0], 2.0);
      }
    }
  }
  rms_error = std::sqrt(rms_error*g->dx(0));
  printf("time %lf,\t error = %le\n", t, rms_error);
  //
  // Write error to file
  //
  FILE* file = fopen ("advect1d_error.out","a");
  fprintf(file,"%le %le\n", t, rms_error);
  fclose (file);
}

void Postprocess_Advection::L2_error_1d_sin (Grid* g, const double t) const {
  double rms_error = 0.0;
  double a[3] = {_c->getDouble("a",1),_c->getDouble("a",2),_c->getDouble("a",3)};
  for (int i=0; i < g->n(0); i++) {
    for (int j=0; j < g->n(1); j++) {
      for (int k=0; k < g->n(2); k++) {
        double x_adv = g->x(0, i, j, k) - a[0]*t;
        rms_error += std::pow(sin(x_adv*2.0*M_PI) - g->u(i,j,k)[0], 2.0);
      }
    }
  }
  rms_error = std::sqrt(rms_error*g->dx(0)*g->dx(1));
  printf("time %lf,\t error = %le\n", t, rms_error);
  //
  // Write error to file
  //
  FILE* file = fopen ("advect1d_error.out","a");
  fprintf(file,"%le %le\n", t, rms_error);
  fclose (file);
}

void Postprocess_Advection::L2_error_2d_tophat (Grid* g, const double t) const {
  double rms_error = 0.0;
  double a[3] = {_c->getDouble("a",1),_c->getDouble("a",2),_c->getDouble("a",3)};
  for (int i=0; i < g->n(0); i++) {
    for (int j=0; j < g->n(1); j++) {
      for (int k=0; k < g->n(2); k++) {
        //
        // Compute the position at t=0 that corresponds to the current position,
        // by account on the domain periodicity.
        //
        double x_adv = wrap_to_interval(g->x(0, i, j, k) - a[0]*t, g->length(0));
        double y_adv = wrap_to_interval(g->x(1, i, j, k) - a[1]*t, g->length(1));
        double u_ex  = 0.0;
        if (x_adv >= g->length(0)/4. && x_adv <= g->length(0)*3./4. &&
            y_adv >= g->length(1)/4. && y_adv <= g->length(1)*3./4.) {
          u_ex = 1.0;
        }
        rms_error += std::pow(u_ex - g->u(i,j,k)[0], 2.0);
      }
    }
  }
  rms_error = std::sqrt(rms_error*g->dx(0)*g->dx(1));
  printf("time %lf,\t error = %le\n", t, rms_error);
  //
  // Write error to file
  //
  FILE* file = fopen ("advect2d_error.out","a");
  fprintf(file,"%le %le\n", t, rms_error);
  fclose (file);
}

void Postprocess_Advection::L2_error_2d_sin (Grid* g, const double t) const {
  double rms_error = 0.0;
  double a[3] = {_c->getDouble("a",1),_c->getDouble("a",2),_c->getDouble("a",3)};
  for (int i=0; i < g->n(0); i++) {
    for (int j=0; j < g->n(1); j++) {
      for (int k=0; k < g->n(2); k++) {
        double x_adv = g->x(0, i, j, k) - a[0]*t;
        double y_adv = g->x(1, i, j, k) - a[1]*t;
        rms_error += std::pow(sin(x_adv*2.0*M_PI)*sin(y_adv*2.0*M_PI) - g->u(i,j,k)[0], 2.0);
      }
    }
  }
  rms_error = std::sqrt(rms_error*g->dx(0)*g->dx(1));
  printf("time %lf,\t error = %le\n", t, rms_error);
  //
  // Write error to file
  //
  FILE* file = fopen ("advect2d_error.out","a");
  fprintf(file,"%le %le\n", t, rms_error);
  fclose (file);
}
