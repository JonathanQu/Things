#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motor1,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motor2,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motor3,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motor4,        tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


task main()
{
motor[motor1] = 100;
motor[motor2] = 100;
motor[motor3] = 100;
motor[motor4] = 100;
wait1Msec(2000);
motor[motor1] = 100;
motor[motor2] = 0;
wait1Msec(2000);

}
