//
//  plot_nsincompressible.cpp
//  AdvancedCFD
//
//  Created by Patrick Jenny on 06/01/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#include "plot_nsincompressible.h"
#include "grid.h"

void Plot_NSIncompressible::plot_pump (bool init, Grid* g) {
  if (init) {
    _gp = new Gnuplot("NS Pressure");
    _gp->cmd("set xrange[0:6.283]");
    _gp->cmd("set yrange[0:6.283]");
    _gp->cmd("set zrange[-50000:50000]");
    _gp->cmd("unset key");
    _gv = new Gnuplot("NS Velo");
    _gv->cmd("set xrange[0:6.283]");
    _gv->cmd("set yrange[0:6.283]");
    _gv->cmd("set zrange[-90:90]");
    _gv->cmd("unset key");
    return;
  }
  FILE * file = fopen ("nsIncompressible2d.out","w");
  for (int i=0; i < g->n(0); i++) {
    for (int j=0; j < g->n(1); j++) {
      fprintf(file,"%le %le %le %le %le\n",g->x(0,i,j,0),g->x(1,i,j,0),g->u(i,j,0)[0],g->u(i,j,0)[1],g->u(i,j,0)[2]);
    }
    fprintf(file,"\n");
  }
  fprintf(file,"\n");
  fclose (file);
  _gv->cmd("p 'nsIncompressible2d.out'u 1:2:(0.004*$4):(0.004*$5) w vec lt -1");
  _gp->cmd("sp'nsIncompressible2d.out'u 1:2:3 w l lt -1");
}

void Plot_NSIncompressible::plot_Riemann (bool init, Grid* g) {
  if (init) {
    _gp = new Gnuplot("NS 1D");
    _gp->cmd("set xrange[0:7]");
    _gp->cmd("set yrange[-90:90]");
    return;
  }
  FILE * file = fopen ("nsIncompressible1d.out","w");
  for (int i=0; i < g->n(0); i++) {
    fprintf(file,"%le %le %le %le\n",g->x(0,i,0,0),g->u(i,0,0)[0],g->u(i,0,0)[0],g->u(i,0,0)[1]);
  }
  fprintf(file,"\n");
  fclose (file);
  _gp->cmd("p'nsIncompressible1d.out'u 1:($3/$2) w l");
}
