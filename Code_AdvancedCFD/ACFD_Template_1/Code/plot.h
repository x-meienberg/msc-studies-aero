//
//  plot.h
//  AdvancedCFD
//
//  Created by Patrick Jenny on 10/11/14.
//  Copyright (c) 2014 Patrick Jenny. All rights reserved.
//

#ifndef AdvancedCFD_plot_h
#define AdvancedCFD_plot_h

class Control;
class Grid;

/**
 * \brief Abstract class for plotting simulation results
 */
class Plot {
public:
	Plot                  (Control* c)
  : _c(c) {}
  virtual ~Plot         () {}
  /**
   * Plot simulation results given an entry in the control file.
   */
  virtual void operator () (Grid* g) = 0;
protected:
  Control* _c;
};

#endif
