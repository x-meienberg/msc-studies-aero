//
//  postprocess_advection.h
//  AdvancedCFD
//
//  Created by Adrien Lücker on 09/02/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#ifndef AdvancedCFD_postprocess_advection_h
#define AdvancedCFD_postprocess_advection_h

#include "control.h"
#include "postprocess.h"
#include <stdio.h>
#include <cmath>

/**
 * \brief Postprocessing class for the linear advection-diffusion equation
 */
class Postprocess_Advection : public Postprocess {
public:
	/**
	 * Constructor.
	 * Uses the key "Case_Postprocess" in the control file.
	 * - 1: 1D postprocess
	 * - 2: 2D postprocess
	 */
  Postprocess_Advection   (Control* c)
	: Postprocess(c) {
    //
    // Open and close the output file to erase its contents.
    //
    FILE* file;
    switch (_c->getInt("Case_Init")) {
      case 1: file = fopen ("advect1d_error.out","w"); fclose(file); break;
      case 2: file = fopen ("advect1d_error.out","w"); fclose(file); break;
      case 3: file = fopen ("advect2d_error.out","w"); fclose(file); break;
      case 4: file = fopen ("advect2d_error.out","w"); fclose(file); break;
      default: printf("\nCase_Init not defined\n");                  break;
    }
  }
  ~Postprocess_Advection  () {}
  /**
   * Compute the L2 error of the numerical solution.
   * Currently, this only works without diffusion (mu = 0).
   * Uses the key "Case_Init" to choose the analytical solution to compare against.
   */
  void operator () (Grid* g, const double t) const {
    switch (_c->getInt("Case_Init")) {
      case 1:  L2_error_1d_tophat (g, t);           break;
      case 2:  L2_error_1d_sin    (g, t);           break;
      case 3:  L2_error_2d_tophat (g, t);           break;
      case 4:  L2_error_2d_sin    (g, t);           break;
      default: printf("\nCase_Init not defined\n"); break;
    }
  }
private:
  /**
   * Wrap a given value to the interval [0, upper_bound).
   */
  double wrap_to_interval (double value, double upper_bound) const {
    double wrapped_value = std::fmod(value, upper_bound);
    if (wrapped_value < 0) {
      wrapped_value += upper_bound;
    }
    return wrapped_value;
  }
  void L2_error_1d_tophat (Grid* g, const double t) const;
  void L2_error_1d_sin    (Grid* g, const double t) const;
  void L2_error_2d_tophat (Grid* g, const double t) const;
  void L2_error_2d_sin    (Grid* g, const double t) const;
};

#endif
