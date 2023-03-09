/******************************************************************************
* Acceleration Class
*
* Written by Kyler Mellor
*
* This file contains the Acceleration class. The purpose of this class is to
* provide an easy way to add accelerations together and store acceleration
* information.
******************************************************************************/

#include "acceleration.h"

/*************************************************************************
* SET
* Sets ddx and ddy according to the total acceleration and the angle of
* acceleration.
*************************************************************************/
void Acceleration::set(const long double& acceleration, const long double& angle)
{
   setDDX(acceleration * sin(angle));
   setDDY(acceleration * cos(angle));
}

/*************************************************************************
* ADD
* Adds the acceleration to the current acceleration given the total
* acceleration to be added and the angle of acceleration.
*************************************************************************/
void Acceleration::add(const long double& acceleration, const long double& angle)
{
   setDDX(ddx + (acceleration * sin(angle)));
   setDDY(ddy + (acceleration * cos(angle)));
}