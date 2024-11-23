#include "vex.h"

/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs.
 */

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */

/*task RejectRed(){
  while (--){
    Intake.spin(forward, 100, percent);
    Intake.spin(reverse, 100, percent);
  }
}*/
void REDP(){

//score on alliance stake
RA.setPosition(0, degrees);
LA.setPosition(0, degrees);
Claw.setPosition(0, degrees);
chassis.turn_to_angle(32);
RA.spinToPosition(220,degrees,false);
LA.spinToPosition(220,degrees,false);
chassis.drive_distance(7);
Claw.spinToPosition(-400,degrees, true);
chassis.drive_distance(-8);

//pick up MOGO
chassis.turn_to_angle(60);
chassis.drive_distance(-18);
chassis.turn_to_angle(23);
chassis.drive_distance(-42);
Hook.set(true);
wait(0.01, seconds);

//Pick up and score ring
Intake.spin(reverse, 100, percent);
Conveyor.spin(reverse, 100, percent);
chassis.turn_to_angle(-20);
chassis.drive_distance(19);

//touch climb
//chassis.turn_to_angle(75);
//Claw.spinToPosition(-180,degrees,false); 
//chassis.drive_distance(34);
Claw.spinToPosition(-180,degrees,false); 
//chassis.turn_to_angle(180);
chassis.turn_to_angle(120);
//chassis.drive_distance(10);
chassis.drive_distance(20);



}
void BLUEN(){
//startTask(RejectRed);
RA.setPosition(0,degrees);
LA.setPosition(0,degrees);
Claw.setPosition(0,degrees);
  //Turn to goal
  //wait(7, seconds);//temp
  chassis.turn_to_angle(38);
  RA.spinToPosition(220,degrees,false);
  LA.spinToPosition(220,degrees,false);
  chassis.drive_distance(11);
  Claw.spinToPosition(-400,degrees, true);
  chassis.drive_distance(-8);
  //chassis.turn_to_angle(0);//temp
  //RA.spinToPosition(300,degrees,false);//temp
  //LA.spinToPosition(300,degrees,false);//temp
  //chassis.drive_distance(-65);//temp
  chassis.turn_to_angle(22);
  chassis.drive_distance(-31);
  Hook.set(true); //grab goal
  chassis.turn_to_angle(268);
  Intake.spin(reverse, 100, percent);
  Conveyor.spin(reverse, 100, percent);
  chassis.drive_distance(40);//grab 1st ring
  chassis.turn_to_angle(170);
  chassis.drive_distance(10);//grab second ring
  chassis.turn_to_angle(132);
  chassis.drive_distance(8);//grab 3rd ring
  chassis.turn_to_angle(95);
  FR.spin(forward,100,percent);
  BR.spin(forward,100,percent);
  FL.spin(forward,100,percent);
  BL.spin(forward,100,percent);
  Claw.spinToPosition(-180,degrees,false); 

}
 void REDN(){
RA.setPosition(0,degrees);
LA.setPosition(0,degrees);
Claw.setPosition(0,degrees);
  //Turn to goal
  chassis.turn_to_angle(318);
  RA.spinToPosition(230,degrees,false);
  LA.spinToPosition(230,degrees,false);
  chassis.drive_distance(10);
  Claw.spinToPosition(-400,degrees, true);
  chassis.drive_distance(-8);
  chassis.turn_to_angle(338);
  chassis.drive_distance(-31);
  Hook.set(true); //grab goal
  chassis.turn_to_angle(92);
  Intake.spin(reverse, 100, percent);
  Conveyor.spin(reverse, 100, percent);
  chassis.drive_distance(40);//grab 1st ring
  chassis.turn_to_angle(190);
  chassis.drive_distance(16);//grab second ring
  chassis.turn_to_angle(210);
  chassis.drive_distance(7);//grab 3rd ring
  chassis.turn_to_angle(260);
  Claw.spinToPosition(-190,degrees,false);
  chassis.drive_distance(35);

 }


void BLUEP(){

//score on alliance stake
RA.setPosition(0, degrees);
LA.setPosition(0, degrees);
Claw.setPosition(0, degrees);
chassis.turn_to_angle(-30);
RA.spinToPosition(220,degrees,false);
LA.spinToPosition(220,degrees,false);
chassis.drive_distance(7);
Claw.spinToPosition(-400,degrees, true);
chassis.drive_distance(-8);

//pick up MOGO
chassis.turn_to_angle(-60);
chassis.drive_distance(-18);
chassis.turn_to_angle(-32);
chassis.drive_distance(-43);
Hook.set(true);
wait(0.01, seconds);

//Pick up and score ring
Intake.spin(reverse, 100, percent);
Conveyor.spin(reverse, 100, percent);
chassis.turn_to_angle(20);
chassis.drive_distance(19);

//touch climb
//chassis.turn_to_angle(75);
//Claw.spinToPosition(-180,degrees,false); 
//chassis.drive_distance(34);
Claw.spinToPosition(-180,degrees,false); 
//chassis.turn_to_angle(180);
chassis.turn_to_angle(-120);
//chassis.drive_distance(10);
chassis.drive_distance(20);
 }
 /*
  chassis.drive_distance(-36);
  Hook.set(true);
  chassis.turn_to_angle(90);
  Intake.spin(reverse, 100, percent);
  Conveyor.spin(reverse, 100, percent);
  chassis.drive_distance(27);
  wait(.5, seconds);
  chassis.drive_distance(-22);
  chassis.turn_to_angle(135);
  chassis.drive_distance(28.5);
  wait(.5, seconds);
  chassis.drive_distance(-20);
  chassis.turn_to_angle(90);
  chassis.drive_distance(25);
  chassis.turn_to_angle(180);
  chassis.drive_distance(17);
*/

  /*
  working 15 second
  chassis.turn_to_angle(341);
  chassis.drive_distance(-40);
  Hook.set(true);
  chassis.turn_to_angle(127);
  Intake.spin(reverse, 100, percent);
  Conveyor.spin(reverse, 100, percent);
  chassis.drive_distance(22);
  chassis.drive_distance(-4);
  chassis.turn_to_angle(40);
  chassis.drive_distance(18);
  chassis.turn_to_angle(155);
  chassis.drive_distance(17);
  */
  /*
  //More Garbage - Artemus
  RA.spinToPosition(150, degrees,false);
  LA.spinToPosition(150, degrees, false);
  Claw.spinToPosition(150, degrees true);
  */


  //Garbage lines (AN)
  /*
  wait(.5, seconds);
  chassis.turn_to_angle(-90);
  chassis.drive_distance(18);
  wait(.5, seconds);
  RA.spinToPosition(150, degrees, false);
  LA.spinToPosition(150, degrees, false);
  */
