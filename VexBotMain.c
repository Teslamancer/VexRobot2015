#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!
#include Math;
/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
  // .....................................................................................
  // Insert user code here.
  // .....................................................................................

	AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{
		driveMec(getAxisValue());
	  // This is the main execution loop for the user control program. Each time through the loop
	  // your program should update motor + servo values based on feedback from the joysticks.

	  // .....................................................................................
	  // Insert user code here. This is where you use the joystick values to update your motors, etc.
	  // .....................................................................................

	  UserControlCodePlaceholderForTesting(); // Remove this function call once you have "real" code.
	}
}

//Input Manager
bool getButton(TVexJoysticks button){
	bool isPressed;
	if(vexRT[button]==1){
		isPressed=true;
}else{
		isPressed=false;
}
	return isPressed;
}

short getJoystickValue(TVexJoysticks joystick){
	if(-127<=vexRT[joystick]<=127){//will check for joystick values to be legit, otherwise don't run
	return vexRT[joystick];
}
}
static double[] getAxisValue(){
	static double[] axis= new double [3];

	axis[0] = getJoystickValue(joystick);
	axis[1] = getJoystickValue(joystick);
	axis[2] = getJoystickValue(joystick);
	return axis;
}
//yolo hope this works
/*
int rampITUP(short x){
	short Y=0;
	Y=((x^3)/16129)*((x)/(short)abs(x));
	return Y;
}
*/

int driv[3];

void driveMec(double[] driv){
	finaldrv(driv);

	motor[port1]=(driv[0]);
	motor[port2]=(driv[1]);
	motor[port3]=(driv[2]);
	motor[port4]=(driv[3]);
}


//assumes motor ports
short[] finaldrv(short driv[]){
	short drv[3];
	drv[0] = (driv[0] *.75) - (driv[1]*.75) + (driv[2]);
	drv[1] = ((driv[0] *.75) + driv[1]*.75 + (driv[2]));
	drv[2] = -(driv[0] *.75) + (driv[1]*.75) + (driv[2]);
	drv[3] = (-(driv[0] *.75) - (driv[1]*.75) + (driv[2]));

	return drv;
}
