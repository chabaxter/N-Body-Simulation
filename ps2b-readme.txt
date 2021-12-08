/**********************************************************************
 *  N-Body Simulation ps2b-readme.txt template
 **********************************************************************/

Name: Charles Baxter

Hours to complete assignment: 1
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
	The physics simulation for the universe class is implemented. Each
CelestialBody object now moves in the universe over time using actual physics
calculations. The acceleration of each CelestialBody in the x and y direction
is calculated by using each body's position and mass. The acceleration at any
given time can then be used to change the velocity of each CelestialObject,
but it must be defined for a certain time period. The lower the time period,
the more accurate the simulation. The new velocities of each CelestialBody can
then be used to calculate the new positions of each CelestialBody over the
same time interval. The program also impliments a simple counter to display
how much time has elapsed, as well as play a sound file as long as the program
is running.

/**********************************************************************
 *  If you created your own universe for extra credit, describe it
 *  here and why it is interesting.
 **********************************************************************/
	The created universe, test.txt, simply has a sun and two mars. The
second mars is flipped about the y-axis, with the velocity still being the
same. This is done so each mars objects come extremely close together multiple
times around their orbits. The innacuracy of the caluclations due to the time
interval is much more noticable, as each begins to lose their original orbits
quite rapidly, and each loses their orbits in different ways. This also shows
that each object in the Universe is being calculated against each other object,
not just with the sun.

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/