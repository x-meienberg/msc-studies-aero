//
//  plot_advection.cpp
//  AdvancedCFD
//
//  Created by Patrick Jenny on 06/01/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#include "plot_advection.h"
#include "grid.h"

void Plot_Advection::plot_1d (bool init, Grid* g) {
  if (init) {
    _gp = new Gnuplot("Advection 1D");
    _gp->cmd("set xrange[ 0: 1]");
    _gp->cmd("set yrange[-1: 2]");
    return;
  }
  FILE* file = fopen ("advect1d.out","w");
  for (int i=0; i < g->n(0); i++) {
    fprintf(file,"%le %le \n",g->x(0,i,0,0),g->u(i,0,0)[0]);
  }
  fprintf(file,"\n");
  fclose (file);
  _gp->cmd("p'advect1d.out'u 1:2 w l lt -1");
}

void Plot_Advection::plot_2d (bool init, Grid* g) {
  if (init) {
    _gp = new Gnuplot("Advection 2D");
    _gp->cmd("set xrange[ 0: 1]");
    _gp->cmd("set yrange[ 0: 1]");
    _gp->cmd("set zrange[-2: 2]");
    return;
  }
  FILE* file = fopen ("advect2d.out","w");
  for (int i=0; i < g->n(0); i++) {
    for (int j=0; j < g->n(1); j++) {
      fprintf(file,"%le %le %le\n",g->x(0,i,j,0),g->x(1,i,j,0),g->u(i,j,0)[0]);
    }
    fprintf(file,"\n");
  }
  fprintf(file,"\n");
  fclose (file);
  _gp->cmd("sp'advect2d.out'u 1:2:3 w l lt -1");
}
