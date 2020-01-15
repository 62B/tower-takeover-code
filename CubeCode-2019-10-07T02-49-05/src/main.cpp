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
 vex::motor RightMotor = vex::motor(vex::PORT19, true);
 vex::motor RightMotor2 = vex::motor(vex::PORT15, true);
 vex::motor Flipper1 = vex::motor(vex::PORT10);
 vex::motor Flipper2 = vex::motor(vex::PORT21, true);
 vex::motor Arm = vex::motor(vex::PORT7, true);
 vex::motor Tray = vex::motor(vex::PORT20, true);
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


//MAIN CODE
 #include "vex.h"
 
 using namespace vex;


//Robot (all motors) stops for 100 milliseconds.
void shortBrake()
{
    LeftMotor.stop(vex::brakeType::brake);
    LeftMotor2.stop(vex::brakeType::brake);
    RightMotor.stop(vex::brakeType::brake);
    RightMotor2.stop(vex::brakeType::brake);
    Flipper1.stop(vex::brakeType::brake);
    Flipper2.stop(vex::brakeType::brake);
    Arm.stop(vex::brakeType::brake);
    Tray.stop(vex::brakeType::brake);
    vex::task::sleep(50);
}

//Moves tray forward for num milliseconds.
void trayForward(int num){
  Tray.spin(vex::directionType::fwd, 120, vex::velocityUnits::pct);
  vex::task::sleep(num);
}

//Moves tray backwards for num milliseconds.
void trayBackward(int num){
  Tray.spin(vex::directionType::rev, 120, vex::velocityUnits::pct);
  vex::task::sleep(num);
}

//Moves tray backwards fast for num milliseconds.
void trayBackwardFast(int num){
  Tray.spin(vex::directionType::rev, 180, vex::velocityUnits::pct);
  vex::task::sleep(num);
}

//Moves arms up for num milliseconds.
void armsUp(int num){
  Arm.spin(vex::directionType::fwd, 120, vex::velocityUnits::pct);
  vex::task::sleep(num);
}

//Moves arms us fast for num milliseconds.
void armsUpFast(int num){
  Arm.spin(vex::directionType::fwd, 240, vex::velocityUnits::pct);
  vex::task::sleep(num);
}

//Moves arms down for num milliseconds.
void armsDown(int num){
  Arm.spin(vex::directionType::rev, 120, vex::velocityUnits::pct);
  vex::task::sleep(num);
}

//Robot drives forward for num milliseconds.
void fdrive (int num)
{
    LeftMotor.resetRotation();
    LeftMotor2.resetRotation();
    RightMotor.resetRotation();
    RightMotor2.resetRotation();
    RightMotor.startRotateTo(num,vex::rotationUnits::deg,240,vex::velocityUnits::rpm);
    LeftMotor.startRotateTo(num,vex::rotationUnits::deg,240,vex::velocityUnits::rpm);
    RightMotor2.startRotateTo(num,vex::rotationUnits::deg,240,vex::velocityUnits::rpm);
    LeftMotor2.rotateTo(num,vex::rotationUnits::deg,240,vex::velocityUnits::rpm);
}

//Robot drives forward slowly for num milliseconds.
void fdriveslow (int num)
{
    LeftMotor.resetRotation();
    LeftMotor2.resetRotation();
    RightMotor.resetRotation();
    RightMotor2.resetRotation();
    RightMotor.startRotateTo(num,vex::rotationUnits::deg,30,vex::velocityUnits::rpm);
    LeftMotor.startRotateTo(num,vex::rotationUnits::deg,30,vex::velocityUnits::rpm);
    RightMotor2.startRotateTo(num,vex::rotationUnits::deg,30,vex::velocityUnits::rpm);
    LeftMotor2.rotateTo(num,vex::rotationUnits::deg,30,vex::velocityUnits::rpm);
}

//Robot drives forward while intaking for num milliseconds.
void fdriveintake (int num)
{
    LeftMotor.resetRotation();
    LeftMotor2.resetRotation();
    RightMotor.resetRotation();
    RightMotor2.resetRotation();
    Flipper1.resetRotation();
    Flipper2.resetRotation();
    RightMotor.startRotateTo(num,vex::rotationUnits::deg,80,vex::velocityUnits::rpm);
    LeftMotor.startRotateTo(num,vex::rotationUnits::deg,80,vex::velocityUnits::rpm);
    RightMotor2.startRotateTo(num,vex::rotationUnits::deg,80,vex::velocityUnits::rpm);
    LeftMotor2.startRotateTo(num,vex::rotationUnits::deg,80,vex::velocityUnits::rpm);
    Flipper1.startRotateTo(num*-2,vex::rotationUnits::deg,240,vex::velocityUnits::rpm);
    Flipper2.rotateTo(num*-2,vex::rotationUnits::deg,240,vex::velocityUnits::rpm);
}

//Robot drives backwards while intaking for num milliseconds.
void bdriveintake (int num)
{
    LeftMotor.resetRotation();
    LeftMotor2.resetRotation();
    RightMotor.resetRotation();
    RightMotor2.resetRotation();
    Flipper1.resetRotation();
    Flipper2.resetRotation();
    RightMotor.startRotateTo(-num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    LeftMotor.startRotateTo(-num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    RightMotor2.startRotateTo(-num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    LeftMotor2.startRotateTo(-num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    Flipper1.startRotateTo(num*-2,vex::rotationUnits::deg,240,vex::velocityUnits::rpm);
    Flipper2.rotateTo(num*-2,vex::rotationUnits::deg,240,vex::velocityUnits::rpm);
}

//Robot drives backwards while intaking for num milliseconds.
void bdriveouttake (int num)
{
    LeftMotor.resetRotation();
    LeftMotor2.resetRotation();
    RightMotor.resetRotation();
    RightMotor2.resetRotation();
    Flipper1.resetRotation();
    Flipper2.resetRotation();
    RightMotor.startRotateTo(-num,vex::rotationUnits::deg,40,vex::velocityUnits::rpm);
    LeftMotor.startRotateTo(-num,vex::rotationUnits::deg,40,vex::velocityUnits::rpm);
    RightMotor2.startRotateTo(-num,vex::rotationUnits::deg,40,vex::velocityUnits::rpm);
    LeftMotor2.startRotateTo(-num,vex::rotationUnits::deg,40,vex::velocityUnits::rpm);
    Flipper1.startRotateTo(num*2,vex::rotationUnits::deg,240,vex::velocityUnits::rpm);
    Flipper2.rotateTo(num*2,vex::rotationUnits::deg,240,vex::velocityUnits::rpm);
}

void bdriveoutt (int num)
{
    RightMotor.spin(vex::directionType::rev, 360, vex::velocityUnits::pct);
    LeftMotor.spin(vex::directionType::rev, 360, vex::velocityUnits::pct);
    RightMotor2.spin(vex::directionType::rev, 360, vex::velocityUnits::pct);
    LeftMotor2.spin(vex::directionType::rev, 360, vex::velocityUnits::pct);
    Flipper1.spin(vex::directionType::fwd, 120, vex::velocityUnits::pct);
    Flipper2.spin(vex::directionType::fwd, 120, vex::velocityUnits::pct);
    Tray.spin(vex::directionType::rev, 120, vex::velocityUnits::pct);
    vex::task::sleep(num);
}

//Robot brakes and intakes for num milliseconds.
void brakeintake (int num)
{
    LeftMotor.stop(vex::brakeType::brake);
    LeftMotor2.stop(vex::brakeType::brake);
    RightMotor.stop(vex::brakeType::brake);
    RightMotor2.stop(vex::brakeType::brake);
    Flipper1.spin(vex::directionType::rev, 240, vex::velocityUnits::pct);
    Flipper2.spin(vex::directionType::rev, 240, vex::velocityUnits::pct);
    vex::task::sleep(num);
}

//Robot brakes and outtakes for num milliseconds.
void brakeouttake (int num)
{
    LeftMotor.stop(vex::brakeType::brake);
    LeftMotor2.stop(vex::brakeType::brake);
    RightMotor.stop(vex::brakeType::brake);
    RightMotor2.stop(vex::brakeType::brake);
    Flipper1.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    Flipper2.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    vex::task::sleep(num);
}

//Robot drives backwards for num milliseconds.
void bdrive (int num)
{
    LeftMotor.resetRotation();
    LeftMotor2.resetRotation();
    RightMotor.resetRotation();
    RightMotor2.resetRotation();
    RightMotor.startRotateTo(-num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    LeftMotor.startRotateTo(-num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    RightMotor2.startRotateTo(-num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    LeftMotor2.rotateTo(-num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
}

//Robot turns right. If it turns too much or too little, change the 295 accordingly.
void rturn ()
{
    LeftMotor.resetRotation();
    LeftMotor2.resetRotation();
    RightMotor.resetRotation();
    RightMotor2.resetRotation();
    LeftMotor.startRotateTo(295,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    LeftMotor2.startRotateTo(295,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    RightMotor.startRotateTo(-295,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    RightMotor2.rotateTo(-295,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
}

//Robot turns left. If it turns too much or too little, change the 295 accordingly.
void lturn ()
{
    LeftMotor.resetRotation();
    LeftMotor2.resetRotation();
    RightMotor.resetRotation();
    RightMotor2.resetRotation();
    LeftMotor.startRotateTo(-295,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    LeftMotor2.startRotateTo(-295,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    RightMotor.startRotateTo(295,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    RightMotor2.rotateTo(295,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
}

//Robot turns right for num degrees.
void rturnNum (int num)
{
    LeftMotor.resetRotation();
    LeftMotor2.resetRotation();
    RightMotor.resetRotation();
    RightMotor2.resetRotation();
    LeftMotor.startRotateTo(num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    LeftMotor2.startRotateTo(num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    RightMotor.startRotateTo(-num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    RightMotor2.rotateTo(-num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
}

//Robot turns left for num milliseconds.
void lturnNum (int num)
{
    LeftMotor.resetRotation();
    LeftMotor2.resetRotation();
    RightMotor.resetRotation();
    RightMotor2.resetRotation();
    LeftMotor.startRotateTo(-num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    LeftMotor2.startRotateTo(-num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    RightMotor.startRotateTo(num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    RightMotor2.rotateTo(num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
}

//Robot brakes (all motors stop) for 550 milliseconds.
void brakeIt()
{
    LeftMotor.stop(vex::brakeType::brake);
    LeftMotor2.stop(vex::brakeType::brake);
    RightMotor.stop(vex::brakeType::brake);
    RightMotor2.stop(vex::brakeType::brake);
    Flipper1.stop(vex::brakeType::brake);
    Flipper2.stop(vex::brakeType::brake);
    Arm.stop(vex::brakeType::brake);
    Tray.stop(vex::brakeType::brake);
    vex::task::sleep(550);
}

 void pre_auton( void ) {
   // All activities that occur before the competition starts
   // Example: clearing encoders, setting servo positions, ...
   
 }

 void autonomous( void ) {

//Deploy
trayForward(1000);
shortBrake();
armsUpFast(950);
shortBrake();
armsDown(800);
shortBrake();
trayBackward(1000);
shortBrake();
armsDown(200);
shortBrake();
//Robot drives forward and intakes cubes
fdriveintake(1500);
shortBrake();
brakeintake(700);
shortBrake();
//Robot drives back to the stacking zone
bdriveintake(900);
shortBrake();
//Robot turns towards stacking zone
rturnNum(320);
shortBrake();
//Robot moves toward stacking zone
fdrive(320);
shortBrake();
//deload function
trayForward(2000);
shortBrake();
brakeouttake(750);
shortBrake();
bdriveoutt(1000);
shortBrake();

}
 

 
 void usercontrol( void ) {
   // User control code here, inside the loop
   while (1) {
     
         // For drive I was thinking of maybe a toggle button that lowers drive speed to help w/ stacking cubes
         /*if (Controller1.Axis3.value()>-2 && Controller1.Axis3.value()<2 && Controller1.Axis1.value()>-2 && Controller1.Axis1.value()<2)
         {
            LeftMotor.stop(vex::brakeType::brake);
            LeftMotor2.stop(vex::brakeType::brake);
            RightMotor.stop(vex::brakeType::brake);
            RightMotor2.stop(vex::brakeType::brake);
         }
         
         if (Controller1.Axis3.value()<-2 || Controller1.Axis3.value()>2){
            LeftMotor.spin(vex::directionType::fwd, (Controller1.Axis3.value())*0.6, vex::velocityUnits::pct);
            LeftMotor2.spin(vex::directionType::fwd, (Controller1.Axis3.value())*0.6, vex::velocityUnits::pct);
            RightMotor.spin(vex::directionType::fwd, (Controller1.Axis3.value())*0.6, vex::velocityUnits::pct);
            RightMotor2.spin(vex::directionType::fwd, (Controller1.Axis3.value())*0.6, vex::velocityUnits::pct);
         }
         if(Controller1.Axis2.value()>-2 && Controller1.Axis2.value()<2)
         {
             RightMotor.stop (vex::brakeType::brake);
             RightMotor2.stop (vex::brakeType::brake);
         }
         
         if (Controller1.Axis1.value()<-2 || Controller1.Axis1.value()>2){
            LeftMotor.spin(vex::directionType::fwd, (Controller1.Axis1.value())*0.3, vex::velocityUnits::pct);
            LeftMotor2.spin(vex::directionType::fwd, (Controller1.Axis1.value())*0.3, vex::velocityUnits::pct);
            RightMotor.spin(vex::directionType::rev, (Controller1.Axis1.value())*0.3, vex::velocityUnits::pct);
            RightMotor2.spin(vex::directionType::rev, (Controller1.Axis1.value())*0.3, vex::velocityUnits::pct);
         }*/

         RightMotor.spin(vex::directionType::fwd, (Controller1.Axis2.value())*0.75, vex::velocityUnits::pct);
         RightMotor2.spin(vex::directionType::fwd, (Controller1.Axis2.value())*0.75, vex::velocityUnits::pct);
       
         LeftMotor.spin(vex::directionType::fwd, (Controller1.Axis3.value())*0.75, vex::velocityUnits::pct);
         LeftMotor2.spin(vex::directionType::fwd, (Controller1.Axis3.value())*0.75, vex::velocityUnits::pct);

         //Intakes
         if (Controller1.ButtonR2.pressing()){
             Flipper1.spin(vex::directionType::rev, 120, vex::velocityUnits::pct);
             Flipper2.spin(vex::directionType::rev, 120, vex::velocityUnits::pct);
         }
         else if (Controller1.ButtonR1.pressing()){
             Flipper1.spin(vex::directionType::fwd, 240, vex::velocityUnits::pct);
             Flipper2.spin(vex::directionType::fwd, 240, vex::velocityUnits::pct);
         }
         else{
             Flipper1.stop(vex::brakeType::brake);
             Flipper2.stop(vex::brakeType::brake);
         }
 
         //Arm
         //Lifts arm to place cube on bucket, tray may need to move, tba
         if (Controller1.ButtonL1.pressing()){
             Arm.spin(vex::directionType::fwd, 120, vex::velocityUnits::pct);
             //Tray.spin(vex::directionType::fwd, -80, vex::velocityUnits::pct);
         }
         else if (Controller1.ButtonL2.pressing()){
             Arm.spin(vex::directionType::rev, 120, vex::velocityUnits::pct);
            // Tray.spin(vex::directionType::rev, -80, vex::velocityUnits::pct);
         }
         else{
             Arm.stop(vex::brakeType::hold);
         }
        //if (ALimit.pressing()){
           //Tray.stop(vex::brakeType::hold);
        //}
         //Tray
         //Moves the tray from start to stacking position, these are good but could we add a toggle that makes it go all the way up&down until it hits the limit switch
         if (Controller1.ButtonB.pressing() && !TrayLimit.pressing()){
           Tray.spin(vex::directionType::rev, 120, vex::velocityUnits::pct);
         }
         else if (Controller1.ButtonA.pressing()) {
           Tray.spin(vex::directionType::fwd, 120, vex::velocityUnits::pct);
         }
         else { 
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
 
