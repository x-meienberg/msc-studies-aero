//
//  driver_standard.h
//  AdvancedCFD
//
//  Created by Patrick Jenny on 05/01/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#ifndef AdvancedCFD_driver_standard_h
#define AdvancedCFD_driver_standard_h

#include "driver.h"

/**
 * \brief Driver for numerical simulation of conservation laws.
 */
class Driver_Standard : public Driver {
public:
  void operator () ();
};

#endif
