//
//  setup.h
//  AdvancedCFD
//
//  Created by Patrick Jenny on 11/11/14.
//  Copyright (c) 2014 Patrick Jenny. All rights reserved.
//

#ifndef AdvancedCFD_setup_h
#define AdvancedCFD_setup_h

#include "control.h"
#include "grid.h"
#include "time.h"
#include "postprocess.h"

class Init;
class Fluxes;
class Source;
class Update;
class Plot;

#include <stdio.h>

/**
 * \brief Class for the simulation setup.
 *
 * This class allocates and deletes all required pointers.
 * Classes derived from Setup need to allocate objects of type Control,
 * Grid, Time, Init, Boundary, Fluxes, Source, Update and Plot.
 *
 * This class is not abstract but no object should be instantiated since
 * there is only a default constructor that does nothing.
 */
class Setup {
public:
	/**
	 * Destructor that deletes all pointers
	 */
  virtual ~Setup () {
    delete _c;
    delete _g;
    delete _t;
    delete _i;
    delete _b;
    delete _f;
    delete _q;
    delete _u;
    delete _p;
    delete _pp;
    printf("Setup destroyed!\n\n");
  }
  /**
   * Reread the entries "dt", "nout" and "nt" from the control file
   */
  virtual void refresh () {
    _c ->read();
    _t->dt  () = _c->getDouble("dt");
    _t->nout() = _c->getInt   ("nout");
    _t->nt  () = _c->getInt   ("nt");
  }
protected:
  Control*     _c;
  Grid*        _g;
  Time*        _t;
  Init*        _i;
  Boundary*    _b;
  Fluxes*      _f;
  Source*      _q;
  Update*      _u;
  Plot*        _p;
  Postprocess* _pp;
};

#endif
