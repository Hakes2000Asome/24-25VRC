using namespace vex;

extern brain Brain;

//To set up a motor called LeftFront here, you'd use
//extern motor LeftFront;

//Add your devices below, and don't forget to do the same in robot-config.cpp:
extern motor FL;
extern motor FR;
extern motor ML;
extern motor MR;
extern motor BL;
extern motor BR;
extern motor Conveyor;
extern inertial Inertial5;
extern digital_out Hook;
extern controller Controller1;
extern digital_out Doinker;
extern motor A1;
extern motor A2;
extern digital_in AL;

void  vexcodeInit( void );