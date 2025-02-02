#include "vex.h"

using namespace vex;
competition Competition;

/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors. In VEXcode Pro V5, you can do this using the graphical          */
/*  configurer port icon at the top right. In the VSCode extension, you'll   */
/*  need to go to robot-config.cpp and robot-config.h and create the         */
/*  motors yourself by following the style shown. All motors must be         */
/*  properly reversed, meaning the drive should drive forward when all       */
/*  motors spin forward.                                                     */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your motors.                                     */
/*---------------------------------------------------------------------------*/

Drive chassis(

//Pick your drive setup from the list below:
//ZERO_TRACKER_NO_ODOM
//ZERO_TRACKER_ODOM
//TANK_ONE_FORWARD_ENCODER
//TANK_ONE_FORWARD_ROTATION
//TANK_ONE_SIDEWAYS_ENCODER
//TANK_ONE_SIDEWAYS_ROTATION
//TANK_TWO_ENCODER
//TANK_TWO_ROTATION
//HOLONOMIC_TWO_ENCODER
//HOLONOMIC_TWO_ROTATION
//
//Write it here:
TANK_ONE_FORWARD_ROTATION,

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
motor_group(FL, BL, ML),

//Right Motors:
motor_group(FR, BR, MR),

//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT21,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
3.125,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
0.77,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
365,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
PORT1,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
PORT20,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
4.125,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
6.375,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
PORT19,

//Sideways tracker diameter (reverse to make the direction switch):
2.75,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
-1.75 

);

int current_auton_selection = 0;
bool auto_started = false;

/**
 * Function before autonomous. It prints the current auton number on the screen
 * and tapping the screen cycles the selected auton by 1. Add anything else you
 * may need, like resetting pneumatic components. You can rename these autons to
 * be more descriptive, if you like.
 */

void pre_auton() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();
  Inertial5.calibrate();
  task::sleep(20);



  // Drive train brake status (for derek)
  FL.setBrake(brake);
  FR.setBrake(brake);
  BL.setBrake(brake);
  BR.setBrake(brake);
  A1.setBrake(brake);
  A2.setBrake(brake);


  }


/**
 * Auton function, which runs the selected auton. Case 0 is the default,
 * and will run in the brain screen goes untouched during preauton. Replace
 * drive_test(), for example, with your own auton function you created in
 * autons.cpp and declared in autons.h.
 */

void autonomous(void) {
  auto_started = true;
  //REDP - slot 1
  //BLUEP - slot 2
  REDP();
  
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

void usercontrol(void) {
  // User control code here, inside the loop
bool toggleDoinker = 0;
bool toggleMOGO = 0;
bool toggleArm = 0;
  while (true) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................
   
   /*
   used buttons:
   y = MOGO grab
   b = MOGO release
   Right = Claw forward
   Down = Claw reverse
   L1 = arm up
   L2 = arm down
   R1 = conveyor up
   R2 = conveyer down
   */

    //MOGO 
    //Grab
    if(Controller1.ButtonB.pressing()){
      toggleMOGO = !toggleMOGO;
       while(Controller1.ButtonB.pressing()){
        task::sleep(10);
       }
    }
    if(toggleMOGO){
      Hook.set(true);
    }
    if(!toggleMOGO){
      Hook.set(false);
    }

    //Conveyor
    //Down
    if(Controller1.ButtonR2.pressing()){
      Conveyor.spin(forward, 100, percent);
    }
    //Up
    if(Controller1.ButtonR1.pressing()){
      Conveyor.spin(reverse, 100, percent);
    }
    //Stop
    if(!(Controller1.ButtonR1.pressing()||Controller1.ButtonR2.pressing()))  {
      Conveyor.stop();
    }

    //Doinker
    if(Controller1.ButtonA.pressing()){
      toggleDoinker = !toggleDoinker;
       while(Controller1.ButtonA.pressing()){
        task::sleep(10);
       }
    }
    if(toggleDoinker){
      Doinker.set(true);
    }
    if(!toggleDoinker){
      Doinker.set(false);
    }

    //Arm 
    //Down
    if(Controller1.ButtonL2.pressing()){
      A1.spin(forward, 100, percent);
      A2.spin(forward, 100, percent);
    }

    //Up
    if(Controller1.ButtonL1.pressing()){
      A1.spin(reverse, 100, percent);
      A2.spin(reverse, 100, percent);
    }

    //location
    if(Controller1.ButtonLeft.pressing()){
      toggleArm = 1;
    }
    if(!AL.value()){
      toggleArm = 0;
    }
    if(Controller1.ButtonRight.pressing()){
      toggleArm = 0;
    }
    if(toggleArm){
      A1.spin(forward, 30, percent);
      A2.spin(forward, 30 ,percent);
    }

    //Stop
    if(!(Controller1.ButtonL1.pressing()||Controller1.ButtonL2.pressing()||toggleArm))  {
      A1.stop();
      A2.stop();
    }



    //Replace this line with chassis.control_tank(); for tank drive 
    //or chassis.control_holonomic(); for holo drive.
    chassis.control_tank();

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
