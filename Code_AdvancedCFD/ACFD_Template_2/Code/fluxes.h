//
//  fluxes.h
//  AdvancedCFD
//
//  Created by Patrick Jenny on 10/11/14.
//  Copyright (c) 2014 Patrick Jenny. All rights reserved.
//

#ifndef AdvancedCFD_flux_h
#define AdvancedCFD_flux_h

#include <math.h>

class Control;
class Grid;

/**
 * \brief Class for the computation of numerical fluxes over cell
 *        interfaces for a given conservation law
 */
class Fluxes {
public:
  /**
   * Construct from Control and Grid objects
   */
  Fluxes                (Control* c, Grid* g);
  virtual ~Fluxes       () {}
  /**
   * Compute fluxes based on a scheme given in the control file
   */
  virtual void operator () (Grid* g) const = 0;
protected:
  /**
   * Set all fluxes to zero
   */
  void reinitialize_fluxes(Grid* g) const;
  /**
   * Minmod of two numbers
   */
  double minmod (double a, double b) const {
      if (a*b    <0.0    ) return 0.0;
      if (fabs(a)>fabs(b)) return b;
      return a;
    }
  Control* _c;
};

#endif
