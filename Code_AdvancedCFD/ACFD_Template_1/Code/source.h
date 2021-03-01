//
//  source.h
//  AdvancedCFD
//
//  Created by Patrick Jenny on 12/11/14.
//  Copyright (c) 2014 Patrick Jenny. All rights reserved.
//

#ifndef AdvancedCFD_source_h
#define AdvancedCFD_source_h

#include "grid.h"

/**
 * \brief Abstract class for a source term that is applied to a Grid object.
 */
class Source {
public:
/**
 * Constructor that sets the source term to zero
 */
	Source (Grid* g) {
	  for (int i=0; i < g->n(0); i++) {
	    for (int j=0; j < g->n(1); j++) {
	      for (int k=0; k < g->n(2); k++) {
	        for (int iv=0; iv < g->nv(); iv++) {
	          g->q   (i,j,k)[iv] = 0.0;
	          g->diag(i,j,k)[iv] = 1.0;
	        }
	      }
	    }
	  }
	}
  virtual ~Source       () {}
  /**
   * Set the source term value in the Grid object
   */
  virtual void operator () (Grid* g) const = 0;
};

#endif
