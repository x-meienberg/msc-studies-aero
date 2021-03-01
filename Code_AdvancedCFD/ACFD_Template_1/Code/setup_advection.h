//
//  setup_advection.h
//  AdvancedCFD
//
//  Created by Patrick Jenny on 05/01/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#ifndef AdvancedCFD_setup_advection_h
#define AdvancedCFD_setup_advection_h

#include "setup.h"
#include "init_advection.h"
#include "boundary_periodic.h"
#include "fluxes_advection.h"
#include "source_empty.h"
#include "update_standard.h"
#include "plot_advection.h"
#include "postprocess_advection.h"

/**
 * \brief Simulation setup for the linear advection-diffusion equation
 */
class Setup_Advection : public Setup {
public:
	/**
	 * Constructor that allocates all member pointers
	 *
	 * The control file "advect.ctr" is used for the setup.
	 *
	 * The arguments are passed as double pointers (of type Class**)
	 * and the corresponding pointers (of type Class*) are allocated in this constructor.
	 * Therefore, the caller has access to all created objects.
	 */
  Setup_Advection (Control** c, Time** t, Grid** g, Init** i, Boundary** b,
                   Fluxes** f, Source** q, Update** u, Plot** p, Postprocess** pp) {
    _c  = (*c) = new Control("advect.ctr");
    _c->read();
    _g  = (*g) = new Grid(1, 0, _c->getInt("n",1), _c->getInt("n",2), _c->getInt("n",3),
    		                  _c->getDouble("lx",1), _c->getDouble("lx",2), _c->getDouble("lx",3));
    _t  = (*t) = new Time(_c->getInt("nt"), _c->getInt("nout"), _c->getDouble("dt"));
    _i  = (*i) = new Init_Advection       (_c);
    _b  = (*b) = new Boundary_Periodic;
    _f  = (*f) = new Fluxes_Advection     (_c, _g);
    _q  = (*q) = new Source_Empty         (_g);
    _u  = (*u) = new Update_Standard;
    _p  = (*p) = new Plot_Advection       (_c);
    _pp = (*pp)= new Postprocess_Advection(_c);
  }
};

#endif
