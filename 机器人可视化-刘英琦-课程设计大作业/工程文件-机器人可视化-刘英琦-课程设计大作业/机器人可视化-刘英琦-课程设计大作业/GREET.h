#ifndef GREET
#define GREET

#include "global_variables.h"
void Greet(float currentTime, float& body_center_x, float& body_center_y, float& body_center_z,
	float& left_upper_arm_swing_angle, float& right_upper_arm_swing_angle,
	float& left_lower_arm_swing_angle, float& right_lower_arm_swing_angle,
	float& left_upper_leg_swing_angle, float& right_upper_leg_swing_angle,
	float& left_lower_leg_swing_angle, float& right_lower_leg_swing_angle){
	LeftUpperArmSpeed = 0.7;
	LeftUpperArmRange = 72;
	LeftLowerArmSpeed = 4.2;
	LeftLowerArmRange = 28;
	left_upper_arm_swing_angle = sin(currentTime * LeftUpperArmSpeed)  * LeftUpperArmRange;
	if (left_upper_arm_swing_angle > 0)
	{	
		left_upper_arm_swing_angle = -left_upper_arm_swing_angle;
		
	}
	
	if (left_upper_arm_swing_angle < -36)
	{
		left_lower_arm_swing_angle = sin(currentTime * LeftLowerArmSpeed)  * LeftLowerArmRange;
		if (left_lower_arm_swing_angle > 0)
		{
			left_lower_arm_swing_angle = -left_lower_arm_swing_angle;
		}
	}
	
}

#endif // !GREET
