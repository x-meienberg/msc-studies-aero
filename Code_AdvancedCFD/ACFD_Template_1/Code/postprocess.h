//
//  postprocess.h
//  AdvancedCFD
//
//  Created by Adrien Lücker on 09/02/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#ifndef AdvancedCFD_postprocess_h
#define AdvancedCFD_postprocess_h

class Control;
class Grid;

/**
 * \brief Abstract class for postprocessing simulation results
 */
class Postprocess {
public:
  Postprocess           (Control* c)
  : _c(c) {}
  virtual ~Postprocess  () {}
  /**
   * Postprocess results
   */
  virtual void operator () (Grid* g, const double t) const = 0;
protected:
  Control* _c;
};

#endif
