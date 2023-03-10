#include <raylib.h>
#include "test.h"   // For testing classes
#include "circle.h" // For Circles
#include <cstdlib>
#include <vector>

//----------------------------------------------------------------------------------
// Local Variables Definition
//----------------------------------------------------------------------------------
static const int screenWidth = 800;
static const int screenHeight = 450;

/****************************
* DRAW CROSSHAIR
****************************/
void drawCrosshair(const Position& pos)
{
   DrawRectangle(pos.getXPixels(), pos.getYPixels(), 5, 2, RED);
   DrawRectangle(pos.getXPixels(), pos.getYPixels(), 2, 5, RED);
   DrawRectangle(pos.getXPixels() - 5, pos.getYPixels(), 5, 2, RED);
   DrawRectangle(pos.getXPixels(), pos.getYPixels() - 5, 2, 5, RED);
}

/****************************
* GET CROSSHAIR POSITION
* Returns the position of 
* the crosshair, or (0, 0).
****************************/
Position getCrosshairPos(const Position& lastPosition, const Position& currentPosition)
{
   bool shouldDrawCrosshair = false;
   Position crosshairPos = Position();
   
   if (abs(lastPosition.getXPixels() - currentPosition.getXPixels()) < 0.01)
      shouldDrawCrosshair = true;
   else if (abs(lastPosition.getYPixels() - currentPosition.getYPixels()) < 0.01)
      shouldDrawCrosshair = true;

   if (shouldDrawCrosshair)
      crosshairPos = currentPosition;
   
   return crosshairPos;
}

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
   testRunner();

   // Initialization
   //--------------------------------------------------------------------------------------
   const int screenWidth = 800;
   const int screenHeight = 450;

   InitWindow(screenWidth, screenHeight, "Orbit Simulation");

   Camera2D camera = Camera2D();
   camera.offset = Vector2 { screenWidth / 2, screenHeight / 2 };
   camera.zoom = 1.0f;

   Vector2 ballPosition = { (float) screenWidth / 2, (float) screenHeight / 2 };

   SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
   Circle circle;
   circle.setPosition(200.0, 0.0);
   circle.setSpeed(0.0, -100.0);
   
   static Position lastPosition = Position();
   static Position currentPosition = Position();
   std::vector<Position> crosshairPositions = { };

   //--------------------------------------------------------------------------------------

   // Main game loop
   while (!WindowShouldClose())    // Detect window close button or ESC key
   {
      // Update
      //----------------------------------------------------------------------------------
      circle.update(GetFrameTime());

      // Update current position for comparison.
      currentPosition = circle.getPosition();
      Position crosshairPosition = getCrosshairPos(lastPosition, currentPosition);
      if (crosshairPosition != Position())
         crosshairPositions.push_back(crosshairPosition);      

      //----------------------------------------------------------------------------------

      // Draw
      //----------------------------------------------------------------------------------
      BeginDrawing();
      BeginMode2D(camera);

      ClearBackground(RAYWHITE);

      DrawCircleV(Vector2{ 0 }, 10.0, MAROON);  // Origin
      circle.draw();

      for (auto it : crosshairPositions)
      {
         drawCrosshair(it);
      }

      // Get previous position of circle for next round.
      lastPosition = circle.getPosition();

      EndMode2D();
      EndDrawing();
      //----------------------------------------------------------------------------------
   }

   // De-Initialization
   //--------------------------------------------------------------------------------------
   CloseWindow();        // Close window and OpenGL context
   //--------------------------------------------------------------------------------------

   return 0;
}