/******************************************************************************
* Velocity Class
*
* Written by Kyler Mellor
*
* The purpose of the position class is to provide an easy way to change the
* velocity of the object. The client can get, set, and add to a velocity.
******************************************************************************/
#pragma once

#ifndef VELOCITY_H
#define VELOCITY_H

// Forward declaring dependency.
class Acceleration;

class Velocity
{
private:
   long double dx;
   long double dy;
public:
   Velocity() : dx(0.0), dy(0.0) { }
   Velocity(const long double& dx, const long double& dy) : dx(dx), dy(dy) { }

   long double getDX() const { return dx; }
   long double getDY() const { return dy; }

   void setDX(const long double& dx) { this->dx = dx; }
   void setDY(const long double& dy) { this->dy = dy; }

   void reverse();
   void reverseDX() { dx *= -1; }
   void reverseDY() { dy *= -1; }

   void add(const long double& dx, const long double& dy);
   void add(Velocity& vel);

   void update(const Acceleration& accel, const double& time);

   void reset();
};

#endif // VELOCITY_H