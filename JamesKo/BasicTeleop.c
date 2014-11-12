#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     Q1,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     Q2,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     Q3,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     Q4,            tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

task main() {
	while (true) {
		getJoystickSettings(joystick);
		int y1 = joystick.joy1_y1;
		int x1 = joystick.joy1_x1;

		if ((x1 < 25 && x1 > -25) &&
			(y1 < 25 && y1 > -25)) {}

		else if (y1 < 25 && y1 > -25) {
			if (x1 >= 25) {
				motor[Q2] = ((4 * x1) /3) - (100 / 3);
				motor[Q4] = ((4 * x1) /3) - (100 / 3);
			}
			if (x1 <= -25) {
				motor[Q1] = ((4 * x1) /3) - (100 / 3);
				motor[Q3] = ((4 * x1) /3) - (100 / 3);
			}
		}
		else if (x1 < 25 && x1 > -25) {
			if (y1 >= 25) {
				motor[Q1] = ((4 * y1) /3) - (100 / 3);
				motor[Q2] = ((4 * y1) /3) - (100 / 3);
			}
			if (y1 <= -25) {
				motor[Q3] = ((4 * y1) /3) - (100 / 3);
				motor[Q4] = ((4 * y1) /3) - (100 / 3);
			}
		}
		else if ((x1 >= 25 || x1 =< -25) &&
			(y1 >= 25 || y1 <= -25)) {
			if (x1 >= 25) {
				if (y1 >= 25) {
					// move NE
					motor[Q1] = ((4 * y1) /3) - (100 / 3);
					motor[Q2] = ((4 * ((x1 + y1) / 2)) /3) - (100 / 3); //
					motor[Q4] = ((4 * x1) /3) - (100 / 3);
				}
				if (y1 <= -25) {
					// mv SE
					motor[Q2] = ((4 * x1) /3) - (100 / 3);
					motor[Q3] = ((4 * y1) /3) - (100 / 3);
					motor[Q4] = ((4 * ((x1 + y1) / 2)) /3) - (100 / 3); //
				}
			}
			if (x1 <= -25) {
				if (y1 >= 25) {
					// mv NW
					motor[Q1] = ((4 * ((x1 + y1) / 2)) /3) - (100 / 3); //
					motor[Q2] = ((4 * x1) /3) - (100 / 3);
					motor[Q3] = ((4 * y1) /3) - (100 / 3);
				}
				if (y1 <= -25) {
					// mv SW
					motor[Q1] = ((4 * x1) /3) - (100 / 3);
					motor[Q3] = ((4 * ((x1 + y1) / 2)) /3) - (100 / 3); //
					motor[Q4] = ((4 * y1) /3) - (100 / 3);
				}
			}
		}
	}
}