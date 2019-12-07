 #include "vex.h"
 
 using namespace vex;

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
    vex::task::sleep(200);
}

void trayForward(int num){
  Tray.spin(vex::directionType::fwd, 120, vex::velocityUnits::pct);
  vex::task::sleep(num);
}

void trayBackward(int num){
  Tray.spin(vex::directionType::rev, 120, vex::velocityUnits::pct);
  vex::task::sleep(num);
}

void armsUp(int num){
  Arm.spin(vex::directionType::fwd, 120, vex::velocityUnits::pct);
  vex::task::sleep(num);
}

void armsDown(int num){
  Arm.spin(vex::directionType::rev, 120, vex::velocityUnits::pct);
  vex::task::sleep(num);
}

void fdrive (int num)
{
    LeftMotor.resetRotation();
    LeftMotor2.resetRotation();
    RightMotor.resetRotation();
    RightMotor2.resetRotation();
    RightMotor.startRotateTo(num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    LeftMotor.startRotateTo(num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    RightMotor2.startRotateTo(num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    LeftMotor2.rotateTo(num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
}

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

void fdriveintake (int num)
{
    LeftMotor.resetRotation();
    LeftMotor2.resetRotation();
    RightMotor.resetRotation();
    RightMotor2.resetRotation();
    Flipper1.resetRotation();
    Flipper2.resetRotation();
    RightMotor.startRotateTo(num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    LeftMotor.startRotateTo(num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    RightMotor2.startRotateTo(num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    LeftMotor2.startRotateTo(num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    Flipper1.startRotateTo(num*-2,vex::rotationUnits::deg,240,vex::velocityUnits::rpm);
    Flipper2.rotateTo(num*-2,vex::rotationUnits::deg,240,vex::velocityUnits::rpm);
}


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

void rturn ()
{
    LeftMotor.resetRotation();
    LeftMotor2.resetRotation();
    RightMotor.resetRotation();
    RightMotor2.resetRotation();
    LeftMotor.startRotateTo(295,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    LeftMotor2.rotateTo(295,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    RightMotor.startRotateTo(-295,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    RightMotor2.startRotateTo(-295,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
}

void lturn ()
{
    LeftMotor.resetRotation();
    LeftMotor2.resetRotation();
    RightMotor.resetRotation();
    RightMotor2.resetRotation();
    LeftMotor.startRotateTo(-295,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    LeftMotor2.rotateTo(-295,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    RightMotor.startRotateTo(295,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    RightMotor2.startRotateTo(295,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
}

void rturnNum (int num)
{
    LeftMotor.resetRotation();
    LeftMotor2.resetRotation();
    RightMotor.resetRotation();
    RightMotor2.resetRotation();
    LeftMotor.startRotateTo(num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    LeftMotor2.rotateTo(num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    RightMotor.startRotateTo(-num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    RightMotor2.startRotateTo(-num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
}

void lturnNum (int num)
{
    LeftMotor.resetRotation();
    LeftMotor2.resetRotation();
    RightMotor.resetRotation();
    RightMotor2.resetRotation();
    LeftMotor.startRotateTo(-num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    LeftMotor2.rotateTo(-num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    RightMotor.startRotateTo(num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
    RightMotor2.startRotateTo(num,vex::rotationUnits::deg,120,vex::velocityUnits::rpm);
}

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


trayForward(1000);
shortBrake();
armsUp(1500);
shortBrake();
armsDown(750);
shortBrake();
trayBackward(1000);
shortBrake();
armsDown(200);
shortBrake();
bdrive(550);
brakeIt();
fdriveslow(550);
brakeIt();

/*
fdriveintake(1000);
brakeIt();
rturnNum(450);
brakeIt();
fdrive(750);
brakeIt();

*/
//deload function


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
 
