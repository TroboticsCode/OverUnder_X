#ifndef ROBOT_CONFIG_H
#define ROBOT_CONFIG_H

using namespace vex;

extern brain Brain;

// VEXcode devices - declare new devices here, set them up
// in robot-config.cpp
extern controller Controller1;
extern motor tester;
extern motor ArmLift;
extern motor intake;
extern motor puncher;

extern encoder Tracker;
extern inertial InertialSensor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );

#endif