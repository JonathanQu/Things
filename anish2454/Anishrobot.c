#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     Q1,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     Q2,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     Q3,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     Q4,            tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

task main() {
	while(true){
		getJoystickSettings(joystick);
	 	int x1 = joystick.joy1_x1;
		int y1 = joystick.joy1_y1;
		int x2 = joystick.joy1_x2;
	 	int y2 = joystick.joy1_y2;

if (y1 > 50 || y1 < -50 && x1 < 10 && x1 > -10){
	motor[Q1] = y1;
	motor[Q2] = y1 * -1;
	motor[Q3] = y1 * -1;
	motor[Q4] = y1;
}
else if (x1 > 50 || x1 < -50 && y1 < 5 && y1 > -5) {
	motor[Q1] = y1;
	motor[Q4] = -y1;
	motor[Q2] = y1;
	motor[Q3] = -y1;
}
else if(y1 > 25 && x1 > 25) {
	motor[Q1] = 100;
	motor[Q3] = -100;
}
else if(y1 < -25 && x1 > 25) {
	motor[Q2] = 100;
	motor[Q4] = -100;
}
else if(y1 < -25 && x1 < -25) {
	motor[Q1] = -100;
	motor[Q3] = 100;
}
else if(y1 > 25 && x1 < -25) {
	motor[Q2] = -100;
	motor[Q4] = 100;
}
else if(x2 > 25 || x2 < -25) {
	motor[Q1] = x2;
	motor[Q3] = x2;
	motor[Q4] = x2;
	motor[Q2] = x2;
}
else{
	 		motor[Q1] = 0;
	 		motor[Q2] = 0;
	 		motor[Q3] = 0;
	 		motor[Q4] = 0;
	 	}
	}
}
