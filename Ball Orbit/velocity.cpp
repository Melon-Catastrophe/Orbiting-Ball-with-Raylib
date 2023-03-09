/******************************************************************************
* Velocity Class
*
* Written by Kyler Mellor
*
* The purpose of the position class is to provide an easy way to change the
* velocity of the object. The client can get, set, and add to a velocity.
******************************************************************************/
#include "velocity.h"
#include "acceleration.h"

/************************************************
* REVERSE
* Reverses both the x and y component of the
* velocity. This will cause the object to
* suddenly reverse direction.
************************************************/
void Velocity::reverse()
{
   this->dx *= -1;
   this->dy *= -1;
}

/************************************************
* ADD
* Adds the X and Y parameters to the velocity.
************************************************/
void Velocity::add(const long double& dx, const long double& dy)
{
   this->dx += dx;
   this->dy += dy;
}

/************************************************
* ADD
* Adds two Velocities together.
************************************************/
void Velocity::add(Velocity& vel)
{
   this->dx += vel.dx;
   this->dy += vel.dy;
}

/************************************************
* UPDATE
* Updates the velocity given an acceleration and
* an amount of time to update to.
************************************************/
void Velocity::update(const Acceleration& accel, const double& time)
{
   this->dx = this->dx + (accel.getDDX() * time);
   this->dy = this->dy + (accel.getDDY() * time);
}

/************************************************
* RESET
* Resets the velocity to suddenly stop the
* object.
************************************************/
void Velocity::reset()
{
   this->dx += 0.0;
   this->dy += 0.0;
}