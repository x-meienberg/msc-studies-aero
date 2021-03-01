//
//  grid.cpp
//  AdvancedCFD
//
//  Created by Patrick Jenny on 06/01/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#include "grid.h"

Grid::Grid (int nv, int nc, int nx, int ny, int nz, double lx, double ly, double lz) {
  _n [0] = nx;
  _n [1] = ny;
  _n [2] = nz;
  _nv    = nv;
  _nc    = nc;
  _dx[0] = lx/double(nx);
  _dx[1] = ly/double(ny);
  _dx[2] = lz/double(nz);
  _x     = new double [_n[0]*_n[1]*_n[2]*3];
  _u     = new double*[_n[0]*_n[1]*_n[2]];
  _c     = new double*[_n[0]*_n[1]*_n[2]];
  _q     = new double*[_n[0]*_n[1]*_n[2]];
  _rhs   = new double*[_n[0]*_n[1]*_n[2]];
  _diag  = new double*[_n[0]*_n[1]*_n[2]];
  _f     = new double*[(_n[0]+1)*(_n[1]+1)*(_n[2]+1)*3];
  for (int i=0; i < _n[0]; i++) {
    for (int j=0; j < _n[1]; j++) {
      for (int k=0; k < _n[2]; k++) {
        x   (0,i,j,k) = (0.5+double(i))*_dx[0];
        x   (1,i,j,k) = (0.5+double(j))*_dx[1];
        x   (2,i,j,k) = (0.5+double(k))*_dx[2];
        u   (  i,j,k) = new double[_nv];
        q   (  i,j,k) = new double[_nv];
        rhs (  i,j,k) = new double[_nv];
        diag(  i,j,k) = new double[_nv];
        c   (  i,j,k) = new double[_nc];
      }
    }
  }
  for (int i=0; i < _n[0]+1; i++) {
    for (int j=0; j < _n[1]+1; j++) {
      for (int k=0; k < _n[2]+1; k++) {
        f(0,i,j,k) = new double[_nv];
        f(1,i,j,k) = new double[_nv];
        f(2,i,j,k) = new double[_nv];
      }
    }
  }
};
/**
 * Grid destructor
 */
Grid::~Grid() {
  for (int i=0; i < _n[0]; i++) {
    for (int j=0; j < _n[1]; j++) {
      for (int k=0; k < _n[2]; k++) {
        delete[] u   (  i,j,k);
        delete[] q   (  i,j,k);
        delete[] rhs (  i,j,k);
        delete[] diag(  i,j,k);
        delete[] c   (  i,j,k);
      }
    }
  }
  for (int i=0; i < _n[0]+1; i++) {
    for (int j=0; j < _n[1]+1; j++) {
      for (int k=0; k < _n[2]+1; k++) {
        delete[] f(0,i,j,k);
        delete[] f(1,i,j,k);
        delete[] f(2,i,j,k);
      }
    }
  }
  delete[] _x;
  delete[] _u;
  delete[] _q;
  delete[] _c;
  delete[] _f;
  delete[] _rhs;
  delete[] _diag;
};
