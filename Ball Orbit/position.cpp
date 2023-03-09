#include "position.h"
#include "velocity.h"
#include "acceleration.h"

/************************************************
* ADD
* Adds the X and Y parameters to the position.
************************************************/
void Position::add(const long double& x, const long double& y)
{
   this->x += x;
   this->y += y;
}

/************************************************
* ADD
* Adds two positions together.
************************************************/
void Position::add(Position& pos)
{
   this->x += pos.x;
   this->y += pos.y;
}

/*******************************************
* COMPUTE NEW POSITION
* Calculates the new position based on the
* acceleration and velocity.
******************************************/
void Position::computeNewPosition(const Acceleration& accel, const Velocity& vel, const double& time)
{
   setXPixels(x + (vel.getDX() * time) + (0.5 * accel.getDDX() * (time * time)));
   setYPixels(y + (vel.getDY() * time) + (0.5 * accel.getDDY() * (time * time)));
}

/************************************************
* ADDITION OPERATOR
* Returns the addition of two Positions.
* Example: if "pos1 + pos2", this will return
* a new "pos3" that adds the x and y components
* of Position 1 and Position 2.
************************************************/
Position Position::operator+ (const Position& rhs)
{
   Position newPos;
   newPos.x = this->x + rhs.x;
   newPos.y = this->y + rhs.y;
   return newPos;
}

/************************************************
* EQUALITY OPERATOR
* Returns true if the two positions are equal,
* false if they are not equal.
************************************************/
bool Position::operator== (const Position& rhs)
{
   if (this->x == rhs.x && this->y == rhs.y)
      return true;
   else
      return false;
}

/************************************************
* INEQUALITY OPERATOR
* Returns false if the two positions are equal,
* true if they are not equal.
************************************************/
bool Position::operator!= (const Position& rhs)
{
   if (this->x == rhs.x || this->y == rhs.y)
      return false;
   else
      return true;
}