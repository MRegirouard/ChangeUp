using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern motor FrontLeft;
extern motor FrontRight;
extern motor BackLeft;
extern motor BackRight;
extern motor LeftIntake;
extern motor RightIntake;
extern motor LeftLift;
extern motor RightLift;
extern controller Controller1;
extern controller Controller2;
extern signature Vision__SIG_1;
extern signature Vision__SIG_2;
extern signature Vision__SIG_3;
extern signature Vision__SIG_4;
extern signature Vision__SIG_5;
extern signature Vision__SIG_6;
extern signature Vision__SIG_7;
extern vision Vision;
extern limit BallSwitch;
extern limit ArmDownSwitch;
extern limit ArmUpSwitch;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );