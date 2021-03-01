//
//  postprocess_empty.h
//  AdvancedCFD
//
//  Created by Adrien Lücker on 09/02/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#ifndef AdvancedCFD_postprocess_empty_h
#define AdvancedCFD_postprocess_empty_h

#include "postprocess.h"

class Control;
class Grid;

/**
 * \brief Empty postprocessing class (does nothing)
 */
class Postprocess_Empty : public Postprocess {
public:
  Postprocess_Empty          (Control* c)
  : Postprocess(c) {}
  virtual ~Postprocess_Empty () {}
  /**
   * Empty postprocess (do nothing)
   */
  virtual void operator () (Grid* g, const double t) const {}
};

#endif
