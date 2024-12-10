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

  //Grab MOGO
  chassis.drive_distance(-35);
  chassis.drive_distance(-4);
  Hook.set(true);


  //Score ring
  chassis.turn_to_angle(-90);
  Conveyor.spin(reverse, 100, percent);
  Intake.spin(reverse, 100, percent);
  chassis.drive_distance(16);

  //Drop MOGO
  chassis.turn_to_angle(180);
  chassis.drive_distance(-18);
  chassis.turn_to_angle(162);
  RA.spinToPosition(230, degrees, false);
  LA.spinToPosition(230, degrees, false);
  Hook.set(false);
  Intake.stop();
  Conveyor.stop();

  //Touch climb
  chassis.drive_distance(29);
  chassis.turn_to_angle(84);
  chassis.drive_distance(6);
  
}

void BLUEP(){

  //Calibrate
  RA.setPosition(0, degrees);
  LA.setPosition(0, degrees);
  Claw.setPosition(0, degrees);

  //Grab MOGO
  chassis.drive_distance(-29);
  chassis.drive_distance(-7);
  Hook.set(true);

  //Score ring
  chassis.turn_to_angle(90);
  Conveyor.spin(reverse, 100, percent);
  Intake.spin(reverse, 100, percent);
  chassis.drive_distance(16);

  //Drop MOGO
  chassis.turn_to_angle(-180);
  chassis.drive_distance(-18);
  chassis.turn_to_angle(-162);
  RA.spinToPosition(230, degrees, false);
  LA.spinToPosition(230, degrees, false);
  Hook.set(false);
  Intake.stop();
  Conveyor.stop();

  //Touch climb
  chassis.drive_distance(32);
  chassis.turn_to_angle(-84);
  chassis.drive_distance(6);
  
}
