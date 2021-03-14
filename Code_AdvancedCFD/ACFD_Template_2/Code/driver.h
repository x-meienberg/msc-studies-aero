//
//  driver.h
//  AdvancedCFD
//
//  Created by Patrick Jenny on 02/12/14.
//  Copyright (c) 2014 Patrick Jenny. All rights reserved.
//

#ifndef AdvancedCFD_driver_h
#define AdvancedCFD_driver_h

/**
 * \brief Abstract class for a simulation code driver
 */
class Driver {
public:
  virtual ~Driver() {}
  /**
   * Run the simulation
   */
  virtual void operator () () = 0;
};

#endif
