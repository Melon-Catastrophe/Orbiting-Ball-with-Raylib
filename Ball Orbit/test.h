/******************************************************************************
* Tests
*
* Written by Kyler Mellor
*
* This file contains unit tests for various classes. Each class has its own
* Test class. For example, Position has a TestPosition class. 
* 
* The testRunner() function calls of the the tests in all of the test classes
* to help automate testing.
******************************************************************************/
#pragma once

#include "position.h"
#include "velocity.h"
#include <assert.h>           // For verifying unit tests.

/************************************************
* CLOSE ENOUGH
* Returns if the test value is close enough to 
* the actual value.
*************************************************/
bool closeEnough(double value, double test, double tolerence)
{
   double difference = value - test;
   return (difference >= -tolerence) && (difference <= tolerence);
}

class TestPosition
{
public:
   void run()
   {
      getXPixels_simple();
      getYPixels_simple();
      getXPixels_large();
      getYPixels_large();

      add_doubleTypical();
      add_positionTypical();

      opPlus_same();
      opPlus_typical();
      opEqualTo_true();
      opEqualTo_false();

      position_default();
      position_nondefault();
   }

private:
   void getXPixels_simple()
   {
      // Setup
      Position pos;
      pos.x = 12.0;
      pos.y = 1.0;
      double x_pos = 0.0;

      // Exercise
      x_pos = pos.getXPixels();

      // Verify
      assert(x_pos == 12.0);
      assert(pos.x == 12.0);
      assert(pos.y ==  1.0);
   }  // Teardown

   void getYPixels_simple()
   {
      // Setup
      Position pos;
      pos.x = 1.0;
      pos.y = 12.0;
      double y_pos = 0.0;

      // Exercise
      y_pos = pos.getYPixels();

      // Verify
      assert(y_pos == 12.0);
      assert(pos.y == 12.0);
      assert(pos.x == 1.0);
   }  // Teardown

   void getXPixels_large()
   {
      // Setup
      Position pos;
      pos.x = 12000.0;
      pos.y = 1.0;
      double x_pos = 0.0;

      // Exercise
      x_pos = pos.getXPixels();

      // Verify
      assert(x_pos == 12000.0);
      assert(pos.x == 12000.0);
      assert(pos.y == 1.0);
   }  // Teardown

   void getYPixels_large()
   {
      // Setup
      Position pos;
      pos.y = 12000.0;
      pos.x = 1.0;
      double y_pos = 0.0;

      // Exercise
      y_pos = pos.getYPixels();

      // Verify
      assert(y_pos == 12000.0);
      assert(pos.y == 12000.0);
      assert(pos.x == 1.0);
   }  // Teardown

   void add_doubleTypical()
   {
      // Setup
      Position pos;
      pos.x = 5.0;
      pos.y = 5.0;

      // Exercise
      pos.add(5.0, 5.0);

      // Verify
      assert(pos.x == 10.0);
      assert(pos.y == 10.0);
   }  // Teardown

   void add_positionTypical()
   {
      // Setup
      Position pos1;
      Position pos2;
      pos1.x = 5.0;
      pos1.y = 5.0;
      pos2.x = 5.0;
      pos2.y = 5.0;

      // Exercise
      pos1.add(pos2);

      // Verify
      assert(pos1.x == 10.0);
      assert(pos1.y == 10.0);
      assert(pos2.x == 5.0);
      assert(pos2.y == 5.0);
   }  // Teardown

   void opPlus_same()
   {
      // Setup
      Position pos1;
      Position pos2;
      pos1.x = 5.0;
      pos1.y = 5.0;
      pos2.x = 5.0;
      pos2.y = 5.0;

      Position verify_pos;
      verify_pos.x = 0.0;
      verify_pos.y = 0.0;

      // Exercise
      verify_pos = pos1 + pos2;

      // Verify
      assert(verify_pos.x == 10.0);
      assert(verify_pos.y == 10.0);
      assert(pos1.x == 5.0);
      assert(pos1.y == 5.0);
      assert(pos2.x == 5.0);
      assert(pos2.y == 5.0);
   }  // Teardown

   void opPlus_typical()
   {
      // Setup
      Position pos1;
      Position pos2;
      pos1.x = 5.0;
      pos1.y = 5.0;
      pos2.x = 3.0;
      pos2.y = 3.0;

      Position verify_pos;
      verify_pos.x = 0.0;
      verify_pos.y = 0.0;

      // Exercise
      verify_pos = pos1 + pos2;

      // Verify
      assert(verify_pos.x == 8.0);
      assert(verify_pos.y == 8.0);
      assert(pos1.x == 5.0);
      assert(pos1.y == 5.0);
      assert(pos2.x == 3.0);
      assert(pos2.y == 3.0);
   }  // Teardown

   void opEqualTo_true()
   {
      // Setup
      Position pos1;
      Position pos2;
      pos1.x = 5.0;
      pos1.y = 5.0;
      pos2.x = 5.0;
      pos2.y = 5.0;

      bool verify = false;

      // Exercise
      verify = (pos1 == pos2);

      // Verify
      assert(verify == true);
      assert(pos1.x == 5.0);
      assert(pos1.y == 5.0);
      assert(pos2.x == 5.0);
      assert(pos2.y == 5.0);
   }  // Teardown

   void opEqualTo_false()
   {
      // Setup
      Position pos1;
      Position pos2;
      pos1.x = 5.0;
      pos1.y = 5.0;
      pos2.x = 3.0;
      pos2.y = 3.0;

      bool verify = true;

      // Exercise
      verify = (pos1 == pos2);

      // Verify
      assert(verify == false);
      assert(pos1.x == 5.0);
      assert(pos1.y == 5.0);
      assert(pos2.x == 3.0);
      assert(pos2.y == 3.0);
   }  // Teardown

   void position_default()
   {
      // Setup
      Position pos;

      // Exercise
      pos = Position();

      // Verify
      assert(pos.x == 0.0);
      assert(pos.y == 0.0);
   }  // Teardown

   void position_nondefault()
   {
      // Setup
      Position pos;

      // Exercise
      pos = Position(3.0, 5.0);

      // Verify
      assert(pos.x == 3.0);
      assert(pos.y == 5.0);
   }  // Teardown
};

/************************************************
* TEST RUNNER
* Runs all the unit tests.
************************************************/
void testRunner()
{
   TestPosition().run();
}