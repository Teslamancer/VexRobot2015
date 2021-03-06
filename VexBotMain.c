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
bool toggler;
void pre_auton()
{
	toggler = false;
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
		driveMec(rampITUP(getAxisValue()));
		shootEMUP(shooterToggle());
		elevate(shooterToggle());
	  // This is the main execution loop for the user control program. Each time through the loop
	  // your program should update motor + servo values based on feedback from the joysticks.

	  // .....................................................................................
	  // Insert user code here. This is where you use the joystick values to update your motors, etc.
	  // .....................................................................................

	  UserControlCodePlaceholderForTesting(); // Remove this function call once you have "real" code.
	}
}


float rampITUP(short x[2]){
	float Y[3]={0,0,0,0};
	for(int i=0;i<4;i++){
	Y[i]=((x[i]^3)/16129)*((x[i])/abs(x[i]));
}
	return Y;
}

////////////////////////////////////////////////////////////////////////////////
//
//                              Motor Control
//
////////////////////////////////////////////////////////////////////////////////

//assumes motor ports
short[] finaldrv(short driv[]){
	short drv[3];
@@ -128,3 +106,56 @@ short[] finaldrv(short driv[]){

	return drv;
}

void driveMec(float driv[3]){
	finaldrv(driv);

	motor[port1]=(driv[0]);
	motor[port2]=(driv[1]);
	motor[port3]=(driv[2]);
	motor[port4]=(driv[3]);
}

void shootEMUP(bool check){

	if (check){
		motor[/*shooter motor*/] = //127 || -127
		motor[/*shooter motor*/] = //127 || -127
	}
}

void elevate(bool check){
	if (check){
		motor[/*elevator motor*/] = //127 || -127
	}
}
////////////////////////////////////////////////////////////////////////////////
//
//                              Input Manager
//
////////////////////////////////////////////////////////////////////////////////

bool shooterToggle(){
	bool button = getButton(/*trigger*/);
	if (button && toggler = false){
		toggler=true;
	}else if (button && toggler = true) {
		toggler = false;
	}
	return toggler
}

static float getAxisValue(){
	static float axis[2];

	axis[0] = getJoystickValue(joystick);
	axis[1] = getJoystickValue(joystick);
	axis[2] = getJoystickValue(joystick);
	return axis;
}

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
