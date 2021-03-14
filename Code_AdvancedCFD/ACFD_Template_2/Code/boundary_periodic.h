//
//  boundary_periodic.h
//  AdvancedCFD
//
//  Created by Patrick Jenny on 05/01/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#ifndef AdvancedCFD_boundary_periodic_h
#define AdvancedCFD_boundary_periodic_h

#include "boundary.h"
#include "grid.h"

/**
 * \brief Class for the computation of boundary fluxes for a periodic
 *        boundary condition.
 */
class Boundary_Periodic : public Boundary {
  void operator () (Grid* g) const {
    for (int j=0; j < g->n(1); j++) {
      for (int k=0; k < g->n(2); k++) {
        for (int iv=0; iv < g->nv(); iv++) {
          g->f(0, g->n(0), j, k)[iv] = g->f(0, 0, j, k)[iv];
        }
      }
    }
    for (int i=0; i < g->n(0); i++) {
      for (int k=0; k < g->n(2); k++) {
        for (int iv=0; iv < g->nv(); iv++) {
          g->f(1, i, g->n(1), k)[iv] = g->f(1, i, 0, k)[iv];
        }
      }
    }
    for (int i=0; i < g->n(0); i++) {
      for (int j=0; j < g->n(1); j++) {
        for (int iv=0; iv < g->nv(); iv++) {
          g->f(2, i, j, g->n(2))[iv] = g->f(2, i, j, 0)[iv];
        }
      }
    }
  }
};

#endif
