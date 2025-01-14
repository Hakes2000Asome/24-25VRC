#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;

//The motor constructor takes motors as (port, ratio, reversed), so for example
//motor LeftFront = motor(PORT1, ratio6_1, false);
motor ML = motor(PORT1, ratio6_1, true);
motor MR = motor(PORT9, ratio6_1, false);
motor FL = motor(PORT2, ratio6_1, true);
motor FR = motor(PORT10, ratio6_1, false);
motor BL = motor(PORT3, ratio6_1, true);
motor BR = motor(PORT8, ratio6_1, false);
motor Conveyor = motor(PORT7, ratio6_1, false);
inertial Inertial5 = inertial(PORT21);
digital_out Hook = digital_out(Brain.ThreeWirePort.A);
digital_out Doinker = digital_out(Brain.ThreeWirePort.B);
controller Controller1 = controller(primary);




//Add your devices below, and don't forget to do the same in robot-config.h:


void vexcodeInit( void ) {
  // nothing to initialize
}