#include "Autons.h"
#include "Functions.h"
#include "DriveFunctionsConfig.h"
#include "vex.h"

//add function prototypes for auton routines here
void noAuton();
void Auton1();
void Auton2();

//add function names and function pointers here
//follow the existing sytax, replacing the string
//with function name to show on the controller screen
autonsTuple autons[] = {{"NONE",    &noAuton},
                        {"AUTON_1", &Auton1},
                        {"AUTON_2", &Auton2}};

const uint8_t numAutons = sizeof(autons)/sizeof(autonsTuple);


//Put your auton routines in here
void noAuton()
{
  //dummy function for running no auton
  //LEAVE IN PLACE!
}

void Auton1()
{
  //setRotGains(0.001, 0.001, 0.001, 20, 10); //update PID gains to tune robot
  //setLinGains(0.001, 0.001, 0.001, 20, 10);

  Brain.Screen.print("Match");
  Brain.Screen.newLine();

  moveLinear(32, 75, 10000);
  wait(1, sec);
  moveLinear(-10 ,50, 10000);
  
  //moveLinear(-48, 100, 100000);

//  moveRotate(720, 100, 100000);
//  moveRotate(-720, 100, 100000);
}

void Auton2()
{
  Brain.Screen.setCursor(10,1);
  Brain.Screen.print("Programming Skills");

  //Launch from start position
  puncher.setVelocity(88, rpm);
  puncher.spin(directionType::rev);
  wait(3, sec);
  puncher.stop();

  //move forward to clear bar
  moveLinear(6, 25, 1000);
  moveStop(brake);
  //move to drive under bar
  moveRotate(45, 50, 1000);
  moveLinear(12, 50, 1000);
  moveRotate(-30, 50, 1000);
  moveLinear(67, 100, 1000);
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