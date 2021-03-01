//
//  time.h
//  AdvancedCFD
//
//  Created by Patrick Jenny on 12/11/14.
//  Copyright (c) 2014 Patrick Jenny. All rights reserved.
//

#ifndef AdvancedCFD_time_h
#define AdvancedCFD_time_h

/**
 * \brief Class for running time loops.
 */
class Time {
public:
	/**
	 * Construct from components
	 * @param nt Number of time steps
	 * @param nout Number of time steps between result outputs
	 * @param dt Time step size
	 */
  Time (int nt, int nout, double dt)
	: _it  (0),
    _nt  (nt),
    _nout(nout),
    _dt  (dt),
    _t   (0.0)
  {}
  /**
   * Set the time to zero.
   */
  void    begin () {_it = 0; _t = 0.0;}
  /**
   * Return whether the time loop is ended.
   */
  bool    end   () const {return _it >= _nt;}
  /**
   * Increment by one time step.
   */
  void    inc   () {_it++; _t += _dt;}
  /**
   * Return whether the current time step is an output time step
   */
  bool    output() {return (it() % nout() == 0) || (it() == nt() - 1);}
  /**
   * Read/write access to the number of time steps
   */
  int&    nt    () {return _nt;}
  /**
   * Read/write access to the iteration number
   */
  int&    it    () {return _it;}
  /**
   * Read/write access to the number of time steps between result outputs
   */
  int&    nout  () {return _nout;}
  /**
   * Read/write access to the time step size
   */
  double& dt    () {return _dt;}
  /**
   * Read/write access to the current time
   */
  double& t     () {return _t;}
protected:
  int    _it;
  int    _nt;
  int    _nout;
  double _dt;
  double _t;
};

#endif
