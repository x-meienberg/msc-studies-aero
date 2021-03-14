//
//  driver_standard.cpp
//  AdvancedCFD
//
//  Created by Patrick Jenny on 06/01/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#include "driver_standard.h"
#include "control.h"
#include "time.h"
#include "init.h"
#include "boundary.h"
#include "fluxes.h"
#include "source.h"
#include "update.h"
#include "plot.h"
#include "setup_advection.h"
#include "setup_nsincompressible.h"
#include <stdio.h>

class Grid;

void Driver_Standard::operator () () {
  Control      run("case.ctr");
  run.read();
  Grid*        grid;
  Init*        init;
  Boundary*    boundary;
  Fluxes*      fluxes;
  Source*      source;
  Update*      update;
  Plot*        plot;
  Postprocess* postprocess;
  Time*        time;
  Control*     control;
  Setup*       setup;
  switch (run.getInt("case")) {
    case 1:  {setup = new Setup_Advection        (&control,&time,&grid,&init,&boundary,&fluxes,&source,&update,&plot,&postprocess); break;}
    case 3:  {setup = new Setup_NSIncompressible (&control,&time,&grid,&init,&boundary,&fluxes,&source,&update,&plot,&postprocess); break;}
    default: {printf("\nno case defined!\n"); return; break;}
  }
  (*init) (grid);
  //
  // Choose between 3rd-order Runge-Kutta and Euler explicit
  //
  int    nrk      = 3;
  double alpha[3] = {1.0/3.0,15.0/16.0,   8.0/ 15.0};
  double beta [3] = {0.0    ,-5.0/ 9.0,-153.0/128.0};
  if (!run.getBool("rk")) {alpha[0] = 1.0, nrk = 1;}
  //
  // Time loop
  //
  for (time->begin(); !time->end(); time->inc()) {
    for (int rk=0; rk < nrk; rk++) {
      (*fluxes)     (grid);
      (*boundary)   (grid);
     (*source)     (grid);
      (*update)     (grid,time->dt()*alpha[rk],beta[rk]);
    }
    if (time->output() || !grid->checkNan()) {
      printf("time step %d,\t time = %lf\n", time->it(), time->t());
      (*plot)       (grid);
      (*postprocess)(grid, time->t() + time->dt());
      (*setup).refresh();
      if (!grid->checkNan()) {
        delete setup;
        return;
      }
    }
  }
  printf("simulation ended!\n");
  delete setup;
  return;
}
