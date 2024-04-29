#ifndef SPREADHANDS
#define SPREADHANDS

#include "global_variables.h"


void SpreadHands(float currentTime, float& body_center_x, float& body_center_y, float& body_center_z,
	float& left_upper_arm_swing_angle, float& right_upper_arm_swing_angle,
	float& left_lower_arm_swing_angle, float& right_lower_arm_swing_angle,
	float& left_upper_leg_swing_angle, float& right_upper_leg_swing_angle,
	float& left_lower_leg_swing_angle, float& right_lower_leg_swing_angle){
	

	left_upper_arm_swing_angle = sin(currentTime * LeftUpperArmSpeed)*LeftUpperArmRange;
	if (left_upper_arm_swing_angle > 0){
		left_upper_arm_swing_angle = 0;
	}
	left_lower_arm_swing_angle = sin(currentTime * LeftLowerArmSpeed)*LeftLowerArmRange;
	if (left_lower_arm_swing_angle > 0){
		left_lower_arm_swing_angle = 0;
	}
	right_upper_arm_swing_angle = sin(currentTime * RightUpperArmSpeed)*RightUpperArmRange;
	if (right_upper_arm_swing_angle > 0){
		right_upper_arm_swing_angle = 0;
	}
	right_lower_arm_swing_angle = sin(currentTime * RightLowerArmSpeed)*RightLowerArmRange;
	if (right_lower_arm_swing_angle > 0){
		right_lower_arm_swing_angle = 0;
	}

}


#endif // !SPREADHANDS
