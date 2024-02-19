#include "Autons.h"
#include "Functions.h"
#include "DriveFunctionsConfig.h"
#include "vex.h"

//add function prototypes for auton routines here
void noAuton();
void Auton1();
void Auton2();
void Auton3();

//add function names and function pointers here
//follow the existing sytax, replacing the string
//with function name to show on the controller screen
autonsTuple autons[] = {{"NONE",    &noAuton},
                        {"AUTON_1", &Auton1},
                        {"AUTON_2", &Auton2},
                        {"Auton3", &Auton3}};

const uint8_t numAutons = sizeof(autons)/sizeof(autonsTuple);


//Put your auton routines in here
void Auton1()
{
 setRotGains(0.017, 0.00, 0.00, 20, 10); //update PID gains to tune robot
  setLinGains(100, 0.00, 0.00, 20, 10);
  moveLinear(32, 75, 3000);
  moveLinear(-10, 75, 3000);
  moveLinear(12, 75, 3000);
  moveLinear(-20, 75, 3000);
  moveStop(brake);
  /*moveRotate(180, 50, 5000);
  moveLinear(12, 75, 5000);*/
}

void noAuton()
{
 
}

void Auton2()
{
  Brain.Screen.setCursor(10,1);
  Brain.Screen.print("Programming Skills");

  //Launch from start position
  ArmLift.setStopping(hold);
  ArmLift.setVelocity(100, percent);
  ArmLift.spinTo(-135, rotationUnits::deg);
  puncher.setVelocity(99, rpm);
  puncher.spin(directionType::rev);
  /*wait(3, sec);
  puncher.stop();

  //move forward to clear bar
  moveLinear(6, 25, 1000);
  moveStop(brake);
  //move to drive under bar
  moveRotate(45, 50, 1000);
  moveLinear(12, 50, 1000);
  moveRotate(-30, 50, 1000);
  moveLinear(67, 100, 1000);*/
/*
  //rotate to face goal
  moveRotate(-45, 50, 1000);
  //approach goal
  moveLinear(23, 100, 1000);
  moveLinear(-12, 100, 1000);

  //rotate to drive to other side of goal
  moveRotate(-35, 50, 1000);
  moveLinear(24, 100, 1000);

  //face goal and score
  moveRotate(90, 50, 1000);
  moveLinear(12, 100, 1000);
  moveLinear(-12, 100, 1000);*/

  //moveRotate(45, 50, 10000);
   // Brain.Screen.setCurso`r(11,1);
  //Brain.Screen.print("Rotation Complete!!");
  //moveLinear(80, 100, 10000);
  //moveRotate(-45, 50, 10000);
}

void Auton3 ()
{
  setRotGains(0.017, 0.00, 0.00, 20, 10); //update PID gains to tune robot
  setLinGains(100, 0.00, 0.00, 20, 10);
  ArmLift.setStopping(hold);
  ArmLift.setVelocity(100, percent);
  ArmLift.spinTo(-135, rotationUnits::deg);
  puncher.setVelocity(100, rpm);
  puncher.spin(directionType::rev);
  wait(30,sec);
  puncher.stop();
  moveLinear(2, 75, 3000);
  moveRotate(-90, 75, 3000);
  moveLinear(32, 100, 3000);
  moveLinear(-10, 100, 3000);
  moveRotate(90,75,3000);
  moveLinear(40, 100, 3000);
  moveRotate(-220, 75, 3000);
  moveLinear(75, 100, 3000);
}