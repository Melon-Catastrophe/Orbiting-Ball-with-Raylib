/******************************************************************************
* Object Class
*
* Written by Kyler Mellor
*
* This file contains additional methods for the object class. An Object has a 
* Position and a Velocity. An object is designed to be able to be inherited 
* from to add additional features. Future objects might also have a Direction.
******************************************************************************/

#include "acceleration.h"
#include "object.h"
#include <cmath>

/************************************************
* DEFAULT CONSTRUCTOR
************************************************/
Object::Object()
{
   pos = Position();
   vel = Velocity();
   gravityAccel = 50.0;
}

/************************************************
* UPDATE
* Updates the object. Handles updating the
* velocity and position due to gravity and
* collisions.
************************************************/
void Object::update(const double& time)
{
   Acceleration accel;
   accel.set(gravityAccel, atan2(0.0 - pos.getXPixels(), 0.0 - pos.getYPixels())); // TODO: Create getDirectionOfCenter function in Position.

   // v1 = v0 + at
   vel.update(accel, time);

   // x1 = x0 + vt + (1/2) * at^2
   pos.computeNewPosition(accel, vel, time);
}

/************************************************
* HAS GRAVITY
* Returns true if the object is affected by
* gravity; otherwise, returns false.
************************************************/
bool Object::hasGravity()
{
   if (gravityAccel != 0.0)
      return true;
   else
      return false;
}