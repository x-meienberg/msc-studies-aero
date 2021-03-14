//
//  system_nsincompressible.h
//  AdvancedCFD
//
//  Created by Patrick Jenny on 06/01/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#ifndef AdvancedCFD_system_nsincompressible_h
#define AdvancedCFD_system_nsincompressible_h

#include "system.h"
#include <Eigen/Eigen>
#include <Eigen/Sparse>

using namespace Eigen;

class Grid;

/**
 * \brief Class for the solution of the Poisson equation that arises from
 *        the incompressible Navier-Stokes equations
 */
class System_NSIncompressible : public System {
public:
  System_NSIncompressible     (Grid* g);
  /**
   * Solves the Poisson equation
   * @param dt Time step
   */
  void operator            () (double dt);
protected:
  VectorXd                         _p, _b;
  SparseMatrix<double>             _A;
  Grid*                            _g;
  BiCGSTAB< SparseMatrix<double> > _solver;
};

#endif
