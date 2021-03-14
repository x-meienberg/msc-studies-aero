//
//  source_empty.h
//  AdvancedCFD
//
//  Created by Patrick Jenny on 05/01/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#ifndef AdvancedCFD_source_empty_h
#define AdvancedCFD_source_empty_h

#include "source.h"

/**
 * \brief Empty source, i.e., the source term equals zero
 */
class Source_Empty : public Source {
public:
  Source_Empty  (Grid* g)
	: Source(g)
	{}
  /**
   * Set the source term value in the Grid object.
   * Does nothing since the source term was set to zero in the constructor.
   */
  void operator () (Grid* g) const {}
};

#endif
