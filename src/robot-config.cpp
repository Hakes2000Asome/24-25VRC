#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;

//The motor constructor takes motors as (port, ratio, reversed), so for example
//motor LeftFront = motor(PORT1, ratio6_1, false);
motor FL = motor(PORT1, ratio6_1, true);
motor FR = motor(PORT2, ratio6_1, false);
motor BL = motor(PORT3, ratio6_1, true);
motor BR = motor(PORT4, ratio6_1, false);
motor RA = motor(PORT17, ratio18_1, true);
motor LA = motor(PORT14, ratio18_1, false);
motor Claw = motor(PORT11, ratio18_1, true);
motor Intake = motor(PORT15, ratio18_1, false);
motor Conveyor = motor(PORT8, ratio18_1, false);
inertial Inertial5 = inertial(PORT6);
digital_out Hook = digital_out(Brain.ThreeWirePort.A);
controller Controller1 = controller(primary);




//Add your devices below, and don't forget to do the same in robot-config.h:


void vexcodeInit( void ) {
  // nothing to initialize
}