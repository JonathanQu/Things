#pragma config(Motor,  motorA,          motor1,        tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          motor2,        tmotorNXT, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
motor[motorA] = 100;
motor[motorB] = 100;
wait1Msec(2000);
motor[motorA] = 100;
motor[motorB] = 0;
wait1Msec{2000);

}
