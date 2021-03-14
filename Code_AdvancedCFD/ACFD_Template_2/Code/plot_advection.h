//
//  plot_advection.h
//  AdvancedCFD
//
//  Created by Patrick Jenny on 06/01/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#ifndef AdvancedCFD_plot_advection_h
#define AdvancedCFD_plot_advection_h

#include "plot.h"
#include "control.h"
#include "gnuplot_i.h"
#include <stdio.h>

/**
 * \brief Plotting class for the linear advection-diffusion equation
 */
class Plot_Advection : public Plot {
public:
	/**
	 * Constructor that initializes the Gnuplot object used for the plots.
	 * Uses the key "Case_Plot" in the control file.
	 * - 1: 1D plot
	 * - 2: 2D plot
	 */
  Plot_Advection   (Control* c)
	: Plot(c) {
    switch (_c->getInt("Case_Plot")) {
      case 1:  plot_1d (true);                                break;
      case 2:  plot_2d (true);                                break;
      default: printf("\nPlot initialization not defined\n"); break;
    }
  }
  ~Plot_Advection  () {delete _gp;}
  /**
   * Plot the field defined on the grid. Uses the key "Case_Plot" as in the constructor.
   */
  void operator () (Grid* g) {
    switch (_c->getInt("Case_Plot")) {
      case 1:  plot_1d (false, g);             break;
      case 2:  plot_2d (false, g);             break;
      default: printf("\nPlot not defined\n"); break;
    }
  }
private:
  void plot_1d (bool init, Grid* g = 0);
  void plot_2d (bool init, Grid* g = 0);
  Gnuplot* _gp;
};

#endif
