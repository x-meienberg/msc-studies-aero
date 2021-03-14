//
//  update_nsincompressible.h
//  AdvancedCFD
//
//  Created by Patrick Jenny on 06/01/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#ifndef AdvancedCFD_update_nsincompressible_h
#define AdvancedCFD_update_nsincompressible_h

#include "update.h"

class Grid;
class System;

/**
 * \brief Class for the update of a grid object during a time loop, for the incompressible
 * Navier-Stokes equations.
 */
class Update_NSIncompressible : public Update {
public:
  Update_NSIncompressible  (System* sy) {_sy = sy;}
  void operator ()         (Grid* g, double dt, double weight = 0) const;
private:
  System* _sy;
};

#endif
