#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  HTMotor)
#pragma config(Motor,  mtr_S1_C1_1,     backLeft,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     backRight,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     frontLeft,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     frontRight,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     donutLift,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     LEDs,  tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"
void initializeRobot() {

}

task main{
  initializeRobot();
  waitForStart();

  int whichController = 0;
  int ledsOn = -1;
  while (true)
  {
    getJoystickSettings(joystick);


//controller switching to scoring
    if (joy1Btn(3) == 1)
      {
      	whichController = 0;
      }
//controller switching to aquiring
    if (joy2Btn(3) == 1)
      {
      	whichController = 1;
      }

//////////////////////////////////////////////////////////
//scoring code
//////////////////////////////////////////////////////////
    if (whichController == 0)
    {
//motors
     if (abs(joystick.joy1_y1) > 10) {
       motor[frontLeft]= -joystick.joy1_y1;
       motor[backLeft] = -joystick.joy1_y1;
       }else {
       motor[frontLeft]= 0;
       motor[backLeft] = 0;
     }
     if (abs(joystick.joy1_y2) > 10) {
       motor[backRight] = joystick.joy1_y2;
       motor[frontRight] = joystick.joy1_y2;
       } else {
       motor[backRight] = 0;
       motor[frontRight] = 0;
     }

//LEDs
   if (ledsOn == 1) {
     motor[LEDs] = 25;
   } else {
       motor[LEDs] = 0;
     }

     if (joy1Btn(1) == 1) {
       ledsOn = 1;
     }
     if (joy1Btn(2) == 1){
       ledsOn = -1;
       }


//donutlift up
     if (joy1Btn(8) == 1)
     {
       motor[donutLift] = 50;
     }
//donutlift down
     if (joy1Btn(6) == 1)
     {
       //motor[donutLift] = -100;
     }
//donutlift stationary
     if ((joy1Btn(6) == 0) && (joy1Btn(8) == 0))
     {
       motor[donutLift] = 0;
     }

    }
/////////////////////////////////////////////////////////
//aquire code
/////////////////////////////////////////////////////////
    if (whichController == 1)
    {
//motors
     if (abs(joystick.joy2_y2) > 10) {
       motor[frontLeft]= joystick.joy2_y2;
       motor[backLeft] = joystick.joy2_y2;
       }else {
       motor[frontLeft]= 0;
       motor[backLeft] = 0;
     }
     if (abs(joystick.joy2_y1) > 10) {
       motor[backRight] = -joystick.joy2_y1;
       motor[frontRight] = -joystick.joy2_y1;
       } else {
       motor[backRight] = 0;
       motor[frontRight] = 0;
     }

//donutlift up and stationary
       if (joy2Btn(8) == 1)
     {motor[donutLift] = 100;
       }
//donutlift down
     if (joy2Btn(6) == 1)
     {
       motor[donutLift] = -100;
     }
//donutlift stationary
     if ((joy2Btn(6) == 0) && (joy2Btn(8) == 0) && (whichController == 1))
     {
       motor[donutLift] = 0;
     }

    }

  }

}