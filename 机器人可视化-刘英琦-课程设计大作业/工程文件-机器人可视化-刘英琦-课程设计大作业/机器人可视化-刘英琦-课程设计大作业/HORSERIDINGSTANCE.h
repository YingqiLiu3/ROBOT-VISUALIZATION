#ifndef HORSERIDINGSTANCE
#define HORSERIDINGSTANCE

#include "global_variables.h"

void HorseRidingStance(float currentTime, float& body_center_x, float& body_center_y, float& body_center_z,
	float& left_upper_arm_swing_angle, float& right_upper_arm_swing_angle,
	float& left_lower_arm_swing_angle, float& right_lower_arm_swing_angle,
	float& left_upper_leg_swing_angle, float& right_upper_leg_swing_angle,
	float& left_lower_leg_swing_angle, float& right_lower_leg_swing_angle){
	float speed = 1;
	LeftUpperLegSpeed = RightUpperLegSpeed = LeftLowerLegSpeed = RightLowerLegSpeed = speed / 2 ;
	LeftUpperArmSpeed = RightUpperArmSpeed = LeftLowerArmSpeed = RightLowerArmSpeed = speed / 2;
	LeftUpperLegRange = 45;
	RightUpperLegRange = 45;
	LeftLowerLegRange = 45;
	RightLowerLegRange = 45;
	body_center_y = (cos(currentTime*speed) - 1)* 0.5;
	body_center_z = -fabs( 0.99 * sin(currentTime*speed / 2));
	//printf("%f\n",body_center_z);
	left_upper_leg_swing_angle = fabs(sin(currentTime * LeftUpperLegSpeed) * LeftUpperLegRange);
	right_upper_leg_swing_angle = fabs(sin(currentTime * RightUpperLegSpeed) * RightUpperLegRange);
	left_lower_leg_swing_angle = fabs(sin(currentTime * LeftLowerLegSpeed) * LeftLowerLegRange);
	right_lower_leg_swing_angle = fabs(sin(currentTime * RightLowerLegSpeed) * RightLowerLegRange);

	left_upper_arm_swing_angle = fabs(sin(currentTime * LeftUpperArmSpeed)* LeftUpperArmRange);
	right_upper_arm_swing_angle = fabs(sin(currentTime * RightUpperArmSpeed)* RightUpperArmRange);

	left_lower_arm_swing_angle = fabs(sin(currentTime * LeftLowerArmSpeed) * LeftLowerArmRange);

	right_lower_arm_swing_angle = -fabs(sin(currentTime * RightLowerArmSpeed) * RightLowerArmRange);
}
#endif // !HORSERIDINGSTANCE
