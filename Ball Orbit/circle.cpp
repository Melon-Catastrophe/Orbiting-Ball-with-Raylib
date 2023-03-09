/******************************************************************************
* Circle Class
*
* Written by Kyler Mellor
*
* The Circle class is inherited from the Object class and contains the same
* methods and attributes as Object. In addition, we have a way to set the
* position of the Circle, draw the Circle, and various non-default
* constructors that are beneficial for Circle to have.
******************************************************************************/
#pragma once

#include "circle.h"

/************************************************
* NON-DEFAULT CONSTRUCTORS
************************************************/
Circle::Circle(const double& x, const double& y) : Object()
{
   setX(x);
   setY(y);
   radius = 10.0;
}

Circle::Circle(const double& x, const double& y, const int& radius) : Object()
{
   setX(x);
   setY(y);
   this->radius = radius;
}

/************************************************
* SET POSITION
* Sets the position of the Circle, given an x 
* and y coordinate.
************************************************/
void Circle::setPosition(const double& x, const double& y)
{
   setX(x);
   setY(y);
}