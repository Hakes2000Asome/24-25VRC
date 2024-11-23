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

void REDP(){

  //Calibrate
  RA.setPosition(0, degrees);
  LA.setPosition(0, degrees);
  Claw.setPosition(0, degrees);

  //score on alliance stake
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

  //Touch climb
  Claw.spinToPosition(-180,degrees,false); 
  chassis.turn_to_angle(120);
  chassis.drive_distance(20);
}

void BLUEN(){
  
  //Calibrate
  RA.setPosition(0,degrees);
  LA.setPosition(0,degrees);
  Claw.setPosition(0,degrees);

  //Score on alliance steak
  chassis.turn_to_angle(38);
  RA.spinToPosition(220,degrees,false);
  LA.spinToPosition(220,degrees,false);
  chassis.drive_distance(9);
  Claw.spinToPosition(-400,degrees, true);
  chassis.drive_distance(-8);
  
  //Grab MOGO
  chassis.turn_to_angle(22);
  chassis.drive_distance(-31);
  Hook.set(true); 

  //Grab first ring
  chassis.turn_to_angle(268);
  Intake.spin(reverse, 100, percent);
  Conveyor.spin(reverse, 100, percent);
  chassis.drive_distance(40);
  
  //Grab second ring
  chassis.turn_to_angle(170);
  chassis.drive_distance(10);
  
  //Grab third ring
  chassis.turn_to_angle(132);
  chassis.drive_distance(8);
  
  //Touch climb
  chassis.turn_to_angle(95);
  FR.spin(forward,100,percent);
  BR.spin(forward,100,percent);
  FL.spin(forward,100,percent);
  BL.spin(forward,100,percent);
  Claw.spinToPosition(-180,degrees,false); 
}

 void REDN(){

  //Calibrate
  RA.setPosition(0,degrees);
  LA.setPosition(0,degrees);
  Claw.setPosition(0,degrees)
  ;
  //Score on alliance steak
  chassis.turn_to_angle(318);
  RA.spinToPosition(230,degrees,false);
  LA.spinToPosition(230,degrees,false);
  chassis.drive_distance(10);
  Claw.spinToPosition(-400,degrees, true);
  chassis.drive_distance(-8);
  
  //Grab MOGO
  chassis.turn_to_angle(338);
  chassis.drive_distance(-31);
  Hook.set(true);

  //Grab first ring
  chassis.turn_to_angle(92);
  Intake.spin(reverse, 100, percent);
  Conveyor.spin(reverse, 100, percent);
  chassis.drive_distance(40);

  //Grab second ring
  chassis.turn_to_angle(190);
  chassis.drive_distance(16);
  
  //Grab third ring
  chassis.turn_to_angle(210);
  chassis.drive_distance(7);

  //Touch climb
  chassis.turn_to_angle(260);
  Claw.spinToPosition(-190,degrees,false);
  chassis.drive_distance(35);
 }

void BLUEP(){

  //Calibrate
  RA.setPosition(0, degrees);
  LA.setPosition(0, degrees);
  Claw.setPosition(0, degrees);

  // Score on alliance stake
  chassis.turn_to_angle(-28);
  RA.spinToPosition(220,degrees,false);
  LA.spinToPosition(220,degrees,false);
  chassis.drive_distance(7);
  Claw.spinToPosition(-400,degrees, true);
  chassis.drive_distance(-8);

  //Pick up MOGO
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

  //Touch climb
  Claw.spinToPosition(-180,degrees,false); 
  chassis.turn_to_angle(-120);
  chassis.drive_distance(20);
}
