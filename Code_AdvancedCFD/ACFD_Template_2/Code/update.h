//
//  update.h
//  AdvancedCFD
//
//  Created by Patrick Jenny on 10/11/14.
//  Copyright (c) 2014 Patrick Jenny. All rights reserved.
//

#ifndef AdvancedCFD_update_h
#define AdvancedCFD_update_h

class Grid;

/**
 * \brief Abstract class for the update of a grid object during a time loop
 */
class Update {
public:
  virtual ~Update          () {}
  /**
   * Update operator.
   * @param g grid
   * @param dt time step
   * @param weight weighting factor for the equation right-hand side (e.g. used in Runge-Kutta schemes)
   */
  virtual void operator () (Grid* g, double dt, double weight = 0) const = 0;
};

#endif
