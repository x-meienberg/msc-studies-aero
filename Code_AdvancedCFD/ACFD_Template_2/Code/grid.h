//
//  grid.h
//  AdvancedCFD
//
//  Created by Patrick Jenny on 10/11/14.
//  Copyright (c) 2014 Patrick Jenny. All rights reserved.
//

#ifndef AdvancedCFD_grid_h
#define AdvancedCFD_grid_h

/**
 * \brief Class for a 3D Cartesian grid with associated fields and coefficients
 *
 * - dimensions nx x ny x nz
 * - nv dependent variables
 * - nc coefficients
 * - domain size of lx x ly x lz
 */
class Grid {
public:
  /**
   * Grid constructor
   * @param nv Number of dependent variables
   * @param nc Number of coefficients
   * @param nx, ny, nz Dimensions: nx x ny x nz
   * @param lx, ly, lz Domain size: lx x ly x lz
   */
  Grid (int nv, int nc, int nx, int ny, int nz, double lx, double ly, double lz);
  /**
   * Grid destructor
   */
  ~Grid();
  /**
   * Dimensions: n(0) x n(1) x n(2)
   */
  int       n  (int ind) const                {return _n  [ind];}
  /**
   * Number of dependent variable
   */
  int       nv () const                       {return _nv;}
  /**
   * Number of coefficients
   */
  int       nc () const                       {return _nc;}
  /**
   * Read/write access to fields using index triplets
   */
  double*&  c   (         int i, int j, int k) {return _c   [ (i*_n[1]+j)*_n[2]+k];}
  double*&  q   (         int i, int j, int k) {return _q   [ (i*_n[1]+j)*_n[2]+k];}
  double*&  rhs (         int i, int j, int k) {return _rhs [ (i*_n[1]+j)*_n[2]+k];}
  double*&  diag(         int i, int j, int k) {return _diag[ (i*_n[1]+j)*_n[2]+k];}
  double*&  u   (         int i, int j, int k) {return _u   [ (i*_n[1]+j)*_n[2]+k];}
  double*&  f   (int dir, int i, int j, int k) {return _f   [((i*(_n[1]+1)+j)*(_n[2]+1)+k)*3+dir];}
  /**
   * Coordinates (x,y,z) = (x(0,i,j,k),x(1,i,j,k),x(2,i,j,k) for each grid node (i,j,k)
   */
  double&   x  (int dir, int i, int j, int k) {return _x  [((i*_n[1]+j)*_n[2]+k)*3+dir];}
  /**
   * Uniform grid spacings dx(0), dx(1) and dx(2) in x-, y- and z-directions, respectively
   */
  double    dx (int dir) const                {return _dx [dir];}
  /**
   * Domain length in x-, y- and z-directions, respectively
   */
  double    length (int dir) const            {return dx(dir)*n(dir);}
  /**
   * Computation of index with an offset, using domain periodicity if (i + offset) is smaller
   * than 0 or great than n(dir)-1.
   * @param i Index
   * @param offset Offset with respect to i
   * @param dir Coordinate axis
   */
  int       periodic_index(int i, int offset, int dir) const {return (i + offset + n(dir)) % n(dir);}
  bool checkNan();
private:
  int      _n[3];
  int      _nv;
  int      _nc;
  double*  _x;
  double** _u;
  double** _c;
  double** _f;
  double** _q;
  double** _rhs;
  double** _diag;
  double   _dx[3];
};

#endif
