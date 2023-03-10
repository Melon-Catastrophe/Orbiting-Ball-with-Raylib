# Ball Orbit

I created this program for two reasons: to learn how to use Raylib and to practice my C++ skills. I had already written most of the code for the physics, so it was relatively easy to convert to using Raylib.

### Ball's Motion

![Ball's First Orbit](Images\Ball First Orbit.gif)

As you can see in the gif above, I have a black circle orbiting the center red circle.

The orbiting mechanics uses real physics equations to calculate the next step of the ball that is orbiting. Since I am using algebraic physics equations instead of calculus-based formulas, the ball slowly moves inward towards the center. This could also be caused by not having the starting velocity of the orbiting ball set correctly. 

To track this slow inwards movement, I created a couple functions to draw a crosshair each time the outer ball crosses the X or Y axis. This shows how the ball slowly moves inward with time. Eventually, the ball coincides with the inner circle and stops moving.

![Crosshair Movement](Images\Ball Crosshair.gif)

### Conclusion

To further improve the simulation, I would like to calculate what the starting velocity should be for a perfect orbit and see if my physics will be able to keep the ball in a stationary orbit. This will tell me if it is necessary to use calculus or not to calculate the physics.