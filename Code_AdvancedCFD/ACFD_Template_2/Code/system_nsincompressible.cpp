//
//  system_nsincompressible.cpp
//  AdvancedCFD
//
//  Created by Patrick Jenny on 06/01/15.
//  Copyright (c) 2015 Patrick Jenny. All rights reserved.
//

#include "system_nsincompressible.h"

#include "grid.h"

System_NSIncompressible::System_NSIncompressible     (Grid* g) {
  _g = g;
  int n = _g->n(0)*_g->n(1)*_g->n(2);

  int kSize = 2; //TODO Change the stencil width
  double dkSize2 = (double)(kSize*kSize);

  _A.resize(n,n);
  _b.resize(n);
  for (int i=0; i<_g->n(0); i++) {
    int ip  = _g->periodic_index(i,kSize,0);
    int im  = _g->periodic_index(i,-kSize,0);
    for (int j=0; j<_g->n(1); j++) {
      int jp  = _g->periodic_index(j, kSize,1);
      int jm  = _g->periodic_index(j,-kSize,1);
      for (int k=0; k<_g->n(2); k++) {
        int l  = (i *_g->n(1)+j )*_g->n(2)+k;
        int le = (ip*_g->n(1)+j )*_g->n(2)+k;
        int lw = (im*_g->n(1)+j )*_g->n(2)+k;
        int ln = (i *_g->n(1)+jp)*_g->n(2)+k;
        int ls = (i *_g->n(1)+jm)*_g->n(2)+k;
        _A.insert(l,l ) = -(2.0 /(dkSize2*_g->dx(0)*_g->dx(0)) + 2.0/(dkSize2*_g->dx(1)*_g->dx(1)));
        _A.insert(l,le) =   1.0 /(dkSize2*_g->dx(0)*_g->dx(0));
        _A.insert(l,lw) =   1.0 /(dkSize2*_g->dx(0)*_g->dx(0));
        _A.insert(l,ls) =   1.0 /(dkSize2*_g->dx(1)*_g->dx(1));
        _A.insert(l,ln) =   1.0 /(dkSize2*_g->dx(1)*_g->dx(1));
        if (l==0) {
          _A.coeffRef(l,le) =   0.0;
          _A.coeffRef(l,lw) =   0.0;
          _A.coeffRef(l,ln) =   0.0;
          _A.coeffRef(l,ls) =   0.0;
          _A.coeffRef(l,l ) =   1.0;
        }
      }
    }
  }
  _solver.compute(_A);
}

void System_NSIncompressible::operator () (double dt) {
  for (int i=0; i<_g->n(0); i++) {
    int ip  = _g->periodic_index(i, 1,0);
    int im  = _g->periodic_index(i, -1,0);
    for (int j=0; j<_g->n(1); j++) {
      int jp  = _g->periodic_index(j, 1,1);
      int jm  = _g->periodic_index(j,-1,1);
      int l  = i *_g->n(1)+j;
      //TODO Compute the right hand side of the linear system
      //TODO Include or not the divergence term
    }
  }
  _b(0) =   0.0;
  _p    = _solver.solve(_b);
  for (int i=0; i<_g->n(0); i++) {
    for (int j=0; j<_g->n(1); j++) {
      int l  = i *_g->n(1)+j;
      _g->u(i,j,0)[0] = _p(l);
    }
  }
}
