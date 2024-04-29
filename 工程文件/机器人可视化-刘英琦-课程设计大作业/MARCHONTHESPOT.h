#ifndef MARCHONTHESPOT
#define MARCHONTHESPOT

#include "global_variables.h"

void MarchOnTheSpot(float currentTime, float& body_center_x, float& body_center_y, float& body_center_z,
	float& left_upper_arm_swing_angle, float& right_upper_arm_swing_angle,
	float& left_lower_arm_swing_angle, float& right_lower_arm_swing_angle,
	float& left_upper_leg_swing_angle, float& right_upper_leg_swing_angle,
	float& left_lower_leg_swing_angle, float& right_lower_leg_swing_angle) {
	LeftUpperLegRange = RightUpperLegRange = LeftLowerLegRange = RightLowerLegRange = 60;
	LeftLowerArmRange = RightLowerArmRange = 45;
	// 计算左右臂摆动角度
	left_upper_arm_swing_angle = (sin(currentTime * LeftUpperArmSpeed) + cos(currentTime * LeftUpperArmSpeed)) / 2 * LeftUpperArmRange;
	right_upper_arm_swing_angle = (sin(currentTime * RightUpperArmSpeed) + cos(currentTime * RightUpperArmSpeed)) / 2 * RightUpperArmRange;

	// 计算左右前臂摆动角度
	left_lower_arm_swing_angle = (sin(currentTime * LeftLowerArmSpeed) + cos(currentTime * LeftLowerArmSpeed)) / 2 * LeftLowerArmRange;
	if (left_lower_arm_swing_angle > -3)
	{
		left_lower_arm_swing_angle = 0;
	}
	right_lower_arm_swing_angle = (sin(currentTime * RightLowerArmSpeed) + cos(currentTime * RightLowerArmSpeed)) / 2 * RightLowerArmRange;
	if (right_lower_arm_swing_angle < 3)
	{
		right_lower_arm_swing_angle = 0;
	}
	// 计算左右大腿摆动角度
	left_upper_leg_swing_angle = (sin(currentTime * LeftUpperLegSpeed) + cos(currentTime * LeftUpperLegSpeed)) / 2 * LeftUpperLegRange;
	if (left_upper_leg_swing_angle < 0)
	{
		left_upper_leg_swing_angle = 0;
	}
	right_upper_leg_swing_angle = (sin(currentTime * RightUpperLegSpeed) + cos(currentTime * RightUpperLegSpeed)) / 2 * RightUpperLegRange;
	if (right_upper_leg_swing_angle > 0)
	{
		right_upper_leg_swing_angle = 0;
	}
	// 计算左右小腿摆动角度
	left_lower_leg_swing_angle = (sin(currentTime * LeftLowerLegSpeed) + cos(currentTime * LeftLowerLegSpeed)) / 2 * LeftLowerLegRange;
	if (left_lower_leg_swing_angle < 0)
	{
		left_lower_leg_swing_angle = 0;
	}
	right_lower_leg_swing_angle = (sin(currentTime * RightLowerLegSpeed) + cos(currentTime * RightLowerLegSpeed)) / 2 * RightLowerLegRange;
	if (right_lower_leg_swing_angle > 0)
	{
		right_lower_leg_swing_angle = 0;
	}
}

#endif // !MARCHONTHESPOT
