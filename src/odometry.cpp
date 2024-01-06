#include "vex.h"
#include "odometry.h"

//when the wheel turns 360 degrees, how many inches does it move?
double PI = 3.14159265;
double degreesToInches = 2.75*PI/360;
int odoLoop = 0;

//x&y heading for where robot is on the field
double static xInitial = 0;
double static yInitial = 0;
double static thetaInitial = 0;

//sets initial values for last loop for calculating absolute coordinates
double xLastLoop = xInitial;
double yLastLoop = yInitial;
double thetaLastLoop = thetaInitial;

//absolute coordinates
double xAbsolute = xInitial;
double yAbsolute = yInitial;
double thetaAbsolute = thetaInitial;

//prints useful stuff to screen
void printSensors(){
    Brain.Screen.setCursor(5, 1);
    Brain.Screen.print("Inertial Sensor's current heading (deg): ");
    Brain.Screen.print(InertialSensor.heading());
    Brain.Screen.newLine();
    Brain.Screen.print("encoder degrees = ");
    Brain.Screen.print(Tracker.position(degrees));
    Brain.Screen.newLine();
    Brain.Screen.print("encoder to inches = ");
    Brain.Screen.print(degreesToInches * (Tracker.position(degrees)));
    Brain.Screen.setCursor(2, 1);

    Brain.Screen.print("xAbsolute = ");
    Brain.Screen.print(xAbsolute);
    Brain.Screen.newLine();
    Brain.Screen.print("yAbsolute = ");
    Brain.Screen.print(yAbsolute);
    Brain.Screen.newLine();
    Brain.Screen.print("thetaAbsolute = ");
    Brain.Screen.print(thetaAbsolute);
}

int odo(){
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("Odometry Initiated");
    while(true){
        double inchesMoved = degreesToInches*(Tracker.position(degrees));
        double deltaX = cos(thetaAbsolute*(PI/180)) * inchesMoved;
        double deltaY = sin(thetaAbsolute*(PI/180)) * inchesMoved;

        xAbsolute = xLastLoop + deltaX;
        yAbsolute = yLastLoop + deltaY;
        thetaAbsolute = InertialSensor.heading();
        xLastLoop = xAbsolute;
        yLastLoop = yAbsolute;

        printSensors();
    

        odoLoop ++;
        Brain.Screen.setCursor(1, 1);
        Brain.Screen.print("Odometry running %d", odoLoop);

        Tracker.resetRotation();
        vex::task::sleep(100);
    }
    return 0;
}