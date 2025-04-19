/**
 * @file HSLAPixel.cpp
 * Implementation of the HSLAPixel class for use in with the PNG library.
 *
 * @author University of Illinois CS 225 Course Staff
 * @version 2018r1-lab1 - Updated for CS 400
 */

#include <cmath>
#include <iostream>
#include "HSLAPixel.h"
using namespace std;

namespace uiuc {
    HSLAPixel::HSLAPixel() {
        this->h = 0;
        this->s = 0;
        this->l = 1;
        this->a = 1;
    }
    
    HSLAPixel::HSLAPixel(double h, double s, double l, double a) {
        this->h = h;
        this->s = s;
        this->l = l;
        this->a = a;
    }
    
    // HSLAPixel::~HSLAPixel() { }
}
