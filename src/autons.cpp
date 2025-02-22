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
  chassis.set_drive_exit_conditions(1.5, 100, 3000);
  chassis.set_turn_exit_conditions(1, 200, 1000);
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
  chassis.drive_distance(-23);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-12);
  Hook.set(true);


  //Score ring
  Conveyor.spin(reverse, 100, percent);
  chassis.turn_to_angle(-90);
  wait(0.5, seconds); //wait function to prevent curving maybe?????
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
  chassis.drive_distance(-23);
  chassis.turn_to_angle(45);
  chassis.drive_distance(-12);
  Hook.set(true);

  //Score ring
  Conveyor.spin(reverse, 100, percent);
  chassis.turn_to_angle(90);
  wait(0.5, seconds); //wait to fix curving issue??? maybe...
  chassis.drive_distance(16);

  //Drop MOGO
  chassis.turn_to_angle(-180);
  chassis.drive_distance(-18);
  wait(1, seconds); //derek conveyor timing request (the sequel)
  chassis.turn_to_angle(-162);
  Hook.set(false);
  Conveyor.stop();

  //Raise Arm
  A1.spin(reverse, 100, percent);
  A2.spin(reverse, 100 ,percent);

  //Touch climb
  chassis.drive_distance(32);
  chassis.turn_to_angle(-84);
  chassis.drive_distance(6);
  
}

void SKILLS(){

  //grab MOGO
  chassis.turn_to_angle(-40);
  chassis.drive_distance(-15);
  Hook.set(true);

  //grab 1st ring
  Conveyor.spin(reverse, 100, percent);
  chassis.turn_to_angle(180);
  wait(0.1, seconds);
  chassis.drive_distance(24);

  //grab second ring
  chassis.turn_to_angle(95);
  chassis.drive_distance(24.5, 95, 6, 8);

  //grab 3rd & 4th ring
  chassis.turn_to_angle(11);
  chassis.drive_distance(32, 11, 3, 8); // 36 -> 34

  //grab 5th ring
  chassis.drive_distance(-15);
  chassis.turn_to_angle(95);
  chassis.drive_distance(12);

  //drop of goal
  chassis.turn_to_angle(-160);
  chassis.drive_distance(-12, -160, 4, 6);
  wait(0.1, seconds);
  Conveyor.spin(forward, 100, percent);
  wait(0.3, seconds);
  Conveyor.spin(reverse, 100, percent);
  Hook.set(false);


//STAGE
//TWO

  //pick up 2nd goal
  chassis.drive_distance(6);
  chassis.turn_to_angle(93); // successful until here
  chassis.drive_distance(-74,93.5);
  Hook.set(true);
  chassis.drive_distance(-8);

  //pick up 1st ring
  chassis.turn_to_angle(190);
  chassis.drive_distance(24);

  //pick up 2nd ring
  chassis.turn_to_angle(-86);
  chassis.drive_distance(22);

  //pick up 3rd ring
  chassis.turn_to_angle(-155);
  chassis.drive_distance(20);

  //pick up 4th ring
  chassis.turn_to_angle(0);
  chassis.drive_distance(36);
  
  //pick up 5th ring
  chassis.turn_to_angle(-270);
  chassis.drive_distance(10);

  //pick up 6th ring
  chassis.turn_to_angle(0);
  chassis.drive_distance(12,0,5,8);

  //drop goal
  chassis.turn_to_angle(120);
  chassis.drive_distance(-13,110,5,8); // -12
  wait(0.1, seconds);
  Conveyor.spin(forward, 100, percent);
  wait(0.3, seconds);
  Conveyor.spin(reverse, 100, percent);
  Hook.set(false);

//STAGE
//THREE

 //pick up third stake
  wait(0.2, seconds);
  chassis.drive_distance(25);
  chassis.turn_to_angle(0);
  chassis.drive_distance(-97,0);
  chassis.turn_to_angle(-93);
  chassis.drive_distance(-32);
  Hook.set(true);

  //grab first ring
  Conveyor.spin(reverse, 100, percent);
  chassis.turn_to_angle(-27.5);
  chassis.drive_distance(26);

  //grab second ring
  chassis.turn_to_angle(-95);
  chassis.drive_distance(28.5);

  //grab third & fourth ring
  chassis.turn_to_angle(-180);
  chassis.drive_distance(26, -180, 3, 8);

  //grab 5th ring
  chassis.drive_distance(-25);
  chassis.turn_to_angle(-135);
  chassis.drive_distance(12);

  //clear corner
  Doinker.set(true);
  wait(0.3, seconds);
  chassis.turn_to_angle(-250);
  chassis.turn_to_angle(-330);

  //push mogo
  Hook.set(false);
  chassis.drive_distance(-20);

}
