//
//  setup_nsincompressible.h
//  AdvancedCFD
//
//  Created by Patrick Jenny on 05/01/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#ifndef AdvancedCFD_setup_nsincompressible_h
#define AdvancedCFD_setup_nsincompressible_h

#include "setup.h"
#include "init_nsincompressible.h"
#include "plot_nsincompressible.h"
#include "fluxes_nsincompressible.h"
#include "update_nsincompressible.h"
#include "boundary_periodic.h"
#include "source_nsincompressible.h"
#include "system_nsincompressible.h"
#include "postprocess_empty.h"

/**
 * \brief Simulation setup for the incompressible Navier-Stokes equations
 */
class Setup_NSIncompressible : public Setup {
public:
	/**
	 * Constructor that allocates all member pointers
	 *
	 * The control file "nsIncompressible.ctr" is used for the setup.
	 *
	 * The arguments are passed as double pointers (of type Class**)
	 * and the corresponding pointers (of type Class*) are allocated in this constructor.
	 * Therefore, the caller has access to all created objects.
	 */
  Setup_NSIncompressible (Control** c, Time** t, Grid** g, Init** i, Boundary** b,
                   Fluxes** f, Source** q, Update** u, Plot** p, Postprocess** pp) {
    _c  = (*c) = new Control("nsIncompressible.ctr");
    _c->read();
    _g  = (*g) = new Grid(3, 0, _c->getInt("n",1), _c->getInt("n",2), _c->getInt("n",3),
                          _c->getDouble("lx",1), _c->getDouble("lx",2), _c->getDouble("lx",3));
    _sy        = new System_NSIncompressible (_g);
    _t  = (*t) = new Time(_c->getInt("nt"), _c->getInt("nout"), _c->getDouble("dt"));
    _i  = (*i) = new Init_NSIncompressible   (_c);
    _b  = (*b) = new Boundary_Periodic;
    _f  = (*f) = new Fluxes_NSIncompressible (_c, _g);
    _q  = (*q) = new Source_NSIncompressible (_c, _g, _t);
    _u  = (*u) = new Update_NSIncompressible (_sy);
    _p  = (*p) = new Plot_NSIncompressible   (_c);
    _pp = (*pp)= new Postprocess_Empty       (_c);
  }
  ~Setup_NSIncompressible () {delete _sy;}
private:
  System*  _sy;
};

#endif
