/******************************************************************************
* Position Class
*
* Written by Kyler Mellor
*
* The purpose of the Position class is to provide an easy way to change the 
* position of the object. The client can get, set, and add to a position.
******************************************************************************/
#pragma once

#ifndef POSITION_H
#define POSITION_H

class Velocity;
class Acceleration;
class TestPosition;

/************************************************
* POSITION CLASS
* The purpose of the Position class is to provide
* an easy way to change the position of the
* object. The client can get, set, and add to a
* position.
************************************************/
class Position
{
private:
   long double x;
   long double y;
public:
   friend TestPosition;

   Position() : x(0.0), y(0.0) { }
   Position(const double& x, const double& y) : x(x), y(y) { }

   long double getXPixels() const { return x; }
   long double getYPixels() const { return y; }

   void setXPixels(const long double& x) { this->x = x; }
   void setYPixels(const long double& y) { this->y = y; }
   void add(const long double& x, const long double& y);
   void add(Position& pos);

   void computeNewPosition(const Acceleration& accel, const Velocity& vel, const double& time);

   Position operator+ (const Position& rhs);
   bool operator== (const Position& rhs);
   bool operator!= (const Position& rhs);
};

#endif // POSITION_H