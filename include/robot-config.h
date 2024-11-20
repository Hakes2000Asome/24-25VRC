using namespace vex;

extern brain Brain;

//To set up a motor called LeftFront here, you'd use
//extern motor LeftFront;

//Add your devices below, and don't forget to do the same in robot-config.cpp:
extern motor FL;
extern motor FR;
extern motor BL;
extern motor BR;
extern motor RA;
extern motor LA;
extern motor Claw;
extern motor Intake;
extern motor Conveyor;
extern inertial Inertial5;
extern digital_out Hook;
extern controller Controller1;
extern rotation front;
extern rotation sideways;
extern distance top;
extern limit bucketreturn;
extern limit bucketforward;
extern motor artemis;

void  vexcodeInit( void );