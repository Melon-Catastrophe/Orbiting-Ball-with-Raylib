/******************************************************************************
* Object Class
*
* Written by Kyler Mellor
*
* This file contains the object class. An Object has a Position and a Velocity.
* An object is designed to be able to be inherited from to add additional 
* features. Future objects might also have a Direction.
******************************************************************************/
#pragma once

#include "position.h"
#include "velocity.h"

class Object
{
private:
   Position pos;
   Velocity vel;
   double gravityAccel;

protected:
   void setX(const double& x) { pos.setXPixels(x); }
   void setY(const double& y) { pos.setYPixels(y); }

public:
   Object();

   void update(const double& time);
   
   double getDX() const { return vel.getDX(); }
   double getDY() const { return vel.getDY(); }
   double getX() const { return pos.getXPixels(); }
   double getY() const { return pos.getYPixels(); }
   Position getPosition() const { return pos; }

   void setSpeed(const double& dx, const double& dy) { vel = Velocity(dx, dy); }

   double resetVelocity() { vel.reset(); }

   bool hasGravity();
   double getGravityAcceleration() { return gravityAccel; }

   virtual void draw() { }
};