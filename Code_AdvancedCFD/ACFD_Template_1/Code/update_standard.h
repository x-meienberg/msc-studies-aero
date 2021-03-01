//
//  update_standard.h
//  AdvancedCFD
//
//  Created by Patrick Jenny on 06/01/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#ifndef AdvancedCFD_update_standard_h
#define AdvancedCFD_update_standard_h

#include "update.h"

/**
 * \brief Class for the update of a grid object during a time loop, using
 * standard flux differencing.
 */
class Update_Standard : public Update {
public:
  void operator () (Grid* g, double dt, double weight = 0) const;
};

#endif
