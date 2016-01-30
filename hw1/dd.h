//
//  dd.h
//  hw1
//
//  Created by Ulan Korabay on 1/29/16.
//  Copyright (c) 2016 Ulan Korabay. All rights reserved.
//

#ifndef __hw1__dd__
#define __hw1__dd__

#include <stdio.h>
#include <iostream>
#include "dd.h"
#include <fstream>
#include <string>
#include <cstdio>
#include <sstream>
#include <bitset>
typedef unsigned char BYTE;

extern void Processhexdump(std::istream& in);
extern void Processencbase64(std::istream& in);
extern void Processdecbase64(std::istream& in);

#endif /* defined(__hw1__dd__) */

