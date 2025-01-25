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
  chassis.set_drive_constants(10, 0.7, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0.01, 1, 0);
  chassis.set_turn_constants(12, 0.32, 0.1, 4.9, 0);
  chassis.set_swing_constants(12, .3, .001, 2, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 100, 1000);
  chassis.set_turn_exit_conditions(1, 100, 500);
  chassis.set_swing_exit_conditions(1, 100, 500);
}

/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */

void REDP(){

  //Calibrate


  //Grab MOGO
  chassis.drive_distance(-35);
  chassis.drive_distance(-4);
  Hook.set(true);


  //Score ring
  chassis.turn_to_angle(-90);
  wait(0.5, seconds); //wait function to prevent curving maybe?????
  Conveyor.spin(reverse, 100, percent);
  chassis.drive_distance(16);

  //Drop MOGO
  chassis.turn_to_angle(180);
  chassis.drive_distance(-18);
  wait(0.5, seconds); //derek conveyor timing request
  chassis.turn_to_angle(162);
  Hook.set(false);
  Conveyor.stop();
  
  //Raise Arm
  A1.spin(reverse, 100, percent);
  A2.spin(reverse, 100 ,percent);

  //Touch climb
  chassis.drive_distance(29);
  chassis.turn_to_angle(84);
  chassis.drive_distance(6);
  
}

void BLUEP(){

  //Calibrate

  //Grab MOGO
  chassis.drive_distance(-29);
  chassis.drive_distance(-7);
  Hook.set(true);

  //Score ring
  chassis.turn_to_angle(90);
  Conveyor.spin(reverse, 100, percent);
  chassis.drive_distance(16);

  //Drop MOGO
  chassis.turn_to_angle(-180);
  chassis.drive_distance(-18);
  chassis.turn_to_angle(-162);
  Hook.set(false);
  Conveyor.stop();

  //Touch climb
  chassis.drive_distance(32);
  chassis.turn_to_angle(-84);
  chassis.drive_distance(6);
  
}

void SKILLS(){
  chassis.drive_distance(-15);
  Hook.set(true);
  chassis.turn_to_angle(180);
  Conveyor.spin(reverse, 100, percent);
  chassis.drive_distance(24);
  chassis.turn_to_angle(90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(150);
  chassis.drive_distance(21);
  chassis.turn_to_angle(0);
  chassis.drive_distance(48);
  chassis.turn_to_angle(270);
  chassis.drive_distance(12);
  chassis.turn_to_angle(0);
  chassis.drive_distance(12);
  chassis.turn_to_angle(-120);
  chassis.drive_distance(-5);
  Hook.set(false);
  chassis.drive_distance(26);
  chassis.turn_to_angle(90);

  chassis.drive_distance(-48);
  Hook.set(true);

  chassis.turn_to_angle(180);
  Conveyor.spin(reverse, 100, percent);
  chassis.drive_distance(24);
  chassis.turn_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(-150);
  chassis.drive_distance(21);
  chassis.turn_to_angle(0);
  chassis.drive_distance(48);
  chassis.turn_to_angle(-270);
  chassis.drive_distance(12);
  chassis.turn_to_angle(0);
  chassis.drive_distance(12);
  chassis.turn_to_angle(120);
  chassis.drive_distance(-5);
  Hook.set(false);
  chassis.drive_distance(26);
  chassis.turn_to_angle(-90);
  chassis.drive_distance(-48);

  
}