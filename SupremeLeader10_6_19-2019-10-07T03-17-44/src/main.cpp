#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "v5.h"
#include "v5_vcs.h"

vex::brain Brain;
vex::motor LeftMotor = vex::motor(vex::PORT2);
vex::motor LeftMotor2 = vex::motor(vex::PORT11);
vex::motor RightMotor = vex::motor(vex::PORT10, true);
vex::motor RightMotor2 = vex::motor(vex::PORT20, true);
vex::motor Intake1 = vex::motor(vex::PORT16);
vex::motor Intake2 = vex::motor(vex::PORT18, true);
vex::motor Arm = vex::motor(vex::PORT1, true);
vex::motor Tray = vex::motor(vex::PORT14, true);
vex::limit ALimit = vex::limit(Brain.ThreeWirePort.B);
vex::limit FTrayLimit = vex::limit(Brain.ThreeWirePort.G);
vex::limit BTrayLimit = vex::limit(Brain.ThreeWirePort.H);
vex::controller Controller1 = vex::controller();
vex::competition Competition = vex::competition();



#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen

// A global instance of vex::competition


// define your global instances of motors and other devices here


/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */ 
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton( void ) {
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous( void ) {
  // Ok So we need to do a lot, but the general design of the robot will stay the same. So for now I think it would be a good idea to just plan out autons.
  // I was thinking one where we just intake the four cubes on the floor and stack them in a zone, and maybe placing one in a bucket, just an idea.
  // Current auton drives backwards to place cube in goal, then forward, then deploy mechnism and stop.
RightMotor.spin(vex::directionType::fwd, -100, vex::velocityUnits::pct);
RightMotor2.spin(vex::directionType::fwd, -100, vex::velocityUnits::pct);     
LeftMotor.spin(vex::directionType::fwd, -100, vex::velocityUnits::pct);
LeftMotor2.spin(vex::directionType::fwd, -100, vex::velocityUnits::pct);
vex::task::sleep(1000);
RightMotor.stop(vex::brake);
RightMotor2.stop(vex::brake);
LeftMotor.stop(vex::brake);
LeftMotor2.stop(vex::brake);
vex::task::sleep(100);
RightMotor.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
RightMotor2.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);     
LeftMotor.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
LeftMotor2.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
vex::task::sleep(100);
Arm.spin(vex::directionType::fwd, 240, vex::velocityUnits::pct);
Intake1.spin(vex::directionType::fwd, -240, vex::velocityUnits::pct);
Intake2.spin(vex::directionType::fwd, -240, vex::velocityUnits::pct);
vex::task::sleep(500);
Arm.stop(vex::brake);
Intake1.stop(vex::brake);
Intake2.stop(vex::brake);
RightMotor.stop(vex::brake);
RightMotor2.stop(vex::brake);
LeftMotor.stop(vex::brake);
LeftMotor2.stop(vex::brake);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol( void ) {
  // User control code here, inside the loop
  while (1) {
    
        // For drive I was thinking of maybe a toggle button that lowers drive speed to help w/ stacking cubes
        RightMotor.spin(vex::directionType::fwd, (Controller1.Axis2.value())*0.75, vex::velocityUnits::pct);
        RightMotor2.spin(vex::directionType::fwd, (Controller1.Axis2.value())*0.75, vex::velocityUnits::pct);
       
        LeftMotor.spin(vex::directionType::fwd, (Controller1.Axis3.value())*0.75, vex::velocityUnits::pct);
        LeftMotor2.spin(vex::directionType::fwd, (Controller1.Axis3.value())*0.75, vex::velocityUnits::pct);
        
        //Intakes
        if (Controller1.ButtonR2.pressing()){
            Intake1.spin(vex::directionType::fwd, -240, vex::velocityUnits::pct);
            Intake2.spin(vex::directionType::fwd, -240, vex::velocityUnits::pct);
        }
        else if (Controller1.ButtonR1.pressing()){
            Intake1.spin(vex::directionType::fwd, 240, vex::velocityUnits::pct);
            Intake2.spin(vex::directionType::fwd, 240, vex::velocityUnits::pct);
        }
        else{
            Intake1.stop(vex::brakeType::brake);
            Intake2.stop(vex::brakeType::brake);
        }

        //Arm
        //Lifts arm to place cube on bucket, tray may need to move, tba
        if (Controller1.ButtonL1.pressing()){
            Arm.spin(vex::directionType::fwd, 240, vex::velocityUnits::pct);
            //Tray.spin(vex::directionType::fwd, -80, vex::velocityUnits::pct);
        }
        else if (Controller1.ButtonL2.pressing()){
            Arm.spin(vex::directionType::rev, 240, vex::velocityUnits::pct);
           // Tray.spin(vex::directionType::rev, -80, vex::velocityUnits::pct);
        }
        else{
            Arm.stop(vex::brakeType::hold);
        }
        if (ALimit.pressing()){
          //Tray.stop(vex::brakeType::hold);
        }

        
        //Tray
        //Moves the tray from start to stacking position, these are good but could we add a toggle that makes it go all the way up&down until it hits the limit switch
        if (Controller1.ButtonA.pressing()&&!(BTrayLimit.pressing()))
        {
          Tray.spin(vex::directionType::fwd, -120, vex::velocityUnits::pct);
        }
        else if (Controller1.ButtonB.pressing()&&!(FTrayLimit.pressing()))
        {
          Tray.spin(vex::directionType::rev, -120, vex::velocityUnits::pct);
        }
        else
        { 
          Tray.stop(vex::brakeType::brake);
        }
        
        
    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    
    //Run the pre-autonomous function. 
    pre_auton();
       
    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }    
       
}