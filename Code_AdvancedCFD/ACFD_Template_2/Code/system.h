//
//  system.h
//  AdvancedCFD
//
//  Created by Patrick Jenny on 09/12/14.
//  Copyright (c) 2014 Patrick Jenny. All rights reserved.
//

#ifndef AdvancedCFD_system_h
#define AdvancedCFD_system_h

/**
 * \brief Abstract class for the solution of linear systems
 */
class System {
public:
  virtual ~System          () {};
  virtual void operator () (double dt) = 0;
};

#endif
