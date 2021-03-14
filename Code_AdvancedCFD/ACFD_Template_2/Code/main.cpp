//
//  main.cpp
//  AdvancedCFD
//
//  Created by Patrick Jenny on 30/10/14.
//  Copyright (c) 2014 Patrick Jenny. All rights reserved.
//

#include "driver_standard.h"

int main (int argc, char * const argv[]) {
  Driver* d = new Driver_Standard;
  (*d)();
  delete d;
  return 0;
}

