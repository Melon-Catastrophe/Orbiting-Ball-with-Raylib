/******************************************************************************
* Acceleration Class
*
* Written by Kyler Mellor
*
* This file contains the Acceleration class. The purpose of this class is to
* provide an easy way to add accelerations together and store acceleration 
* information.
******************************************************************************/
#pragma once

#include <cmath>

class Acceleration
{
private:
   long double ddx;
   long double ddy;

   void setDDX(const long double& ddx) { this->ddx = ddx; }
   void setDDY(const long double& ddy) { this->ddy = ddy; }
public:
   Acceleration() : ddx(0.0), ddy(0.0) { }

   long double getDDX() const { return ddx; }
   long double getDDY() const { return ddy; }

   void set(const long double& acceleration, const long double& angle);
   void add(const long double& acceleration, const long double& angle);
};