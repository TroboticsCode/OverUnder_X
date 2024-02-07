// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Inertial12           inertial      12
// ---- END VEXCODE CONFIGURED DEVICES ----
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       JBormann                                                  */
/*    Created:      Nov. 2019                                                 */
/*    Description:  Trobotics Template File                                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "Autons.h"
#include "Functions.h"
#include "DriveFunctionsConfig.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void)
{
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  initDriveMotors();

  Controller1.ButtonX.pressed(cycle_autons);
  Brain.Screen.pressed(cycle_autons);
  return;
}

void autonomous(void)
{
  auton_runner();
}
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void)
{
  // initialize odo things
  InertialSensor.calibrate();
  while (InertialSensor.isCalibrating())
  {
    wait(100, msec);
  }
  Brain.Screen.printAt(10, 50, "Hello V5");
  Tracker.resetRotation();

  // add local user control variables here:

  // User control code here, inside the loop:
  // remove existing demo code and replace with you own! Then remove this comment
  while (1)
  {
    // leave the drive code here, it should work if you set up
    //  DriveFunctionsConfig.h properly
    userDrive();
    if (Controller1.ButtonY.pressing())
    {
      puncher.setVelocity(88, rpm);
      puncher.spin(directionType::rev);
    }

    if (Controller1.ButtonB.pressing())
    {
      puncher.setVelocity(44, rpm);
      puncher.spin(directionType::rev);
    }
    if (Controller1.ButtonA.pressing())
    {
      puncher.stop();
    }

    if (Controller1.ButtonR1.pressing())
    {
      ArmLift.spin(directionType::fwd, 100, velocityUnits::pct);
    }
    else if (Controller1.ButtonR2.pressing())
    {
      ArmLift.spin(directionType::rev, 100, velocityUnits::pct);
    }
    else
    {
      ArmLift.stop(brakeType::hold);
    }

    if (Controller1.ButtonL1.pressing())
    {
      ArmLift.setStopping(hold);
    }
    else
    {
      ArmLift.setStopping(coast);
    }
    /*if (Controller1.ButtonUp.pressing);
    {
      /* code */
  }

  // if(ArmLift.position(degrees)<50){
  // ArmLift.setStopping(coast);
  //}
  // if(ArmLift.position(degrees)>50){
  // ArmLift.setStopping(hold);
  // }

  wait(20, msec); // Sleep the task for a short amount of time to
}

// Main will set up the competition functions and callbacks.

int main()
{
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true)
  {
    wait(100, msec);
  }
}
