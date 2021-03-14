//
//  init.h
//  AdvancedCFD
//
//  Created by Patrick Jenny on 10/11/14.
//  Copyright (c) 2014 Patrick Jenny. All rights reserved.
//

#ifndef AdvancedCFD_init_h
#define AdvancedCFD_init_h

#include "control.h"

class Grid;

/**
 * \brief Abstract class for the definition of initial conditions for fields
 * defined on a Grid object.
 */
class Init {
public:
	Init          (Control* c)
	: _c(c) {}
  virtual ~Init () {}
  /**
   * Defines the initial condition given an entry in the control file
   */
  virtual void operator () (Grid* g) const = 0;
protected:
  Control* _c;
};

#endif
