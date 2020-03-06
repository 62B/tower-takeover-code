//CONFIG CODE
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>
 
 #include "v5.h"
 #include "v5_vcs.h"
 
 vex::brain Brain;
 vex::motor LeftMotor = vex::motor(vex::PORT6);
 vex::motor LeftMotor2 = vex::motor(vex::PORT5);
 vex::motor RightMotor = vex::motor(vex::PORT18, true);
 vex::motor RightMotor2 = vex::motor(vex::PORT15, true);
 vex::motor Flipper1 = vex::motor(vex::PORT8);
 vex::motor Flipper2 = vex::motor(vex::PORT20, true);
 vex::motor Arm = vex::motor(vex::PORT7, true);
 vex::motor Tray = vex::motor(vex::PORT19, true);
//vex::limit ALimit = vex::limit(Brain.ThreeWirePort.B);
 vex::limit ArmLimit = vex::limit(Brain.ThreeWirePort.G);
 vex::limit TrayLimit = vex::limit(Brain.ThreeWirePort.H);
 vex::controller Controller1 = vex::controller();
 vex::competition Competition = vex::competition();
 

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)

