//
//  plot_nsincompressible.h
//  AdvancedCFD
//
//  Created by Patrick Jenny on 06/01/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#ifndef AdvancedCFD_plot_nsincompressible_h
#define AdvancedCFD_plot_nsincompressible_h

#include "plot.h"
#include "control.h"
#include "gnuplot_i.h"
#include <stdio.h>

/**
 * \brief Plotting class for the incompressible Navier-Stokes equations
 */
class Plot_NSIncompressible : public Plot {
public:
	/**
	 * Constructor that initializes the Gnuplot objects used for the plots.
	 * Uses the key "Case_Plot" in the control file.
	 * - 1: Riemann problem
	 * - 2: pump simulation
	 */
  Plot_NSIncompressible     (Control* c)
	: Plot(c) {
    switch (_c->getInt("Case_Plot")) {
      case 1:  plot_Riemann (true);                           break;
      case 2:  plot_pump    (true);                           break;
      default: printf("\nPlot initialization not defined\n"); break;
    }
  }
  ~Plot_NSIncompressible    () {delete _gp; delete _gv;}
  /**
   * Plot the fields defined on the grid. Uses the key "Case_Plot" as in the constructor.
   */
  void operator () (Grid* g) {
    switch (_c->getInt("Case_Plot")) {
      case 1:  plot_Riemann (false, g);        break;
      case 2:  plot_pump    (false, g);        break;
      default: printf("\nPlot not defined\n"); break;
    }
  }
private:
  void plot_pump    (bool init, Grid* g = 0);
  void plot_Riemann (bool init, Grid* g = 0);
  Gnuplot* _gv;
  Gnuplot* _gp;
};

#endif
