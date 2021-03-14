//
//  boundary.h
//  AdvancedCFD
//
//  Created by Patrick Jenny on 10/11/14.
//  Copyright (c) 2014 Patrick Jenny. All rights reserved.
//

#ifndef AdvancedCFD_boundary_h
#define AdvancedCFD_boundary_h

class Grid;

/**
 * \brief Abstract class for the computation of boundary fluxes
 */
class Boundary {
public:
  virtual ~Boundary        () {}
  /**
   * Operator that computes the boundary fluxes
   * @param g Pointer to grid object
   */
  virtual void operator () (Grid* g) const = 0;
};

#endif
