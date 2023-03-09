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

#include "raylib.h"
#include "object.h"

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : public Object
{
private:
   int radius;
public:
   Circle() : Object() { radius = 10; }
   Circle(const int& radius) : Object() { this->radius = radius; }
   Circle(const double& x, const double& y);
   Circle(const double& x, const double& y, const int& radius);

   void setPosition(const double& x, const double& y);

   void draw() { DrawCircle(getX(), getY(), radius, BLACK); }
};

#endif // CIRCLE_H