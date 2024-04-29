#include "stdafx.h"
#include"LYQROB.h"
#include "GREET.h"
#include "SPREADHANDS.h"
#include"MARCHONTHESPOT.h"
#include "HORSERIDINGSTANCE.h"

int LYQ::flag = 0;

void drawhat(float radius, float height, int segments) {
	// 绘制侧面
	glColor3f(0.7, 0.1, 0.7);
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < segments; ++i) {
		float angle1 = 2.0f * pi * (float)i / (float)segments;
		float angle2 = 2.0f * pi * (float)(i + 1) / (float)segments;
		float x1 = radius * cos(angle1);
		float z1 = radius * sin(angle1);
		float x2 = radius * cos(angle2);
		float z2 = radius * sin(angle2);

		// 侧面三角形
		glVertex3f(x1, 0, z1);     // 底面三角形顶点1
		glVertex3f(x2, 0, z2);     // 底面三角形顶点2
		glVertex3f(0, height, 0); // 顶部顶点
	}
	glEnd();

	// 绘制底面
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0, 0, 0); // 圆锥底部中心
	for (int i = 0; i <= segments; ++i) {
		float angle = 2.0f * pi * (float)i / (float)segments;
		float x = radius * cos(angle);
		float z = radius * sin(angle);
		glVertex3f(x, 0, z); // 底面顶点
	}
	glEnd();

}
void bowtie() {
	glRotatef(90.0, 0.0, 0.0, 1.0); // 绕着 z 轴旋转 90 度
	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 1.0);  
	glVertex2f(-0.25, 0.25);    // 左上角顶点
	glVertex2f(0.25, 0.25);     // 右上角顶点
	glVertex2f(0.0, 0.0);     // 中心顶点
	glEnd();
	glBegin(GL_TRIANGLES);  
	glVertex2f(-0.25, -0.25);    // 左下角顶点
	glVertex2f(0.25, -0.25);     // 右下角顶点
	glVertex2f(0.0, 0.0);      // 中心顶点
	glEnd();
}
void mouse(){
	glRotatef(90.0, 0.0, 1.0, 0.0); 

	glBegin(GL_TRIANGLES);
	glVertex3f(0.0, 0.0, -0.25);
	glVertex3f(-0.01, -0.05, 0.0);
	glVertex3f(0.0, 0.0, 0.25);
	glEnd();
}
void LYQ::init() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1.0, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void color_skin()
{
	float red = 1.0;
	float green = 1.0;
	float blue = 0.9;
	glColor3f(red, green, blue);
}
void color_joint()
{
	float red = 1.0;
	float green = 1.0;
	float blue = 0.0;
	glColor3f(red, green, blue);
}
void LYQ::drawRobot() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (flag == 5){//自旋操作
		body_center_x = 0;
		body_center_y = 0;
		body_center_z = 0;
		glRotatef(sp, 0, 1, 0);
	}
	
	
	// 画头部
	glPushMatrix();
	color_skin();  // 设置头部颜色
	glTranslatef(body_center_x, body_center_y, body_center_z);
	glTranslatef(0.0, 1.55, 0.0);
	glutSolidSphere(0.55, 30, 30);
	//画耳朵
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.7);
	glRotatef(90.0, 1.0, 0.0, 0.0); // 将圆柱体旋转使其垂直于xy平面
	glTranslatef(0.5, 0.0, -0.05);
	GLUquadricObj *leftear = gluNewQuadric(); // 创建圆柱体对象
	gluCylinder(leftear, 0.1, 0.1, 0.3, 20, 20); // 绘制圆柱体
	glPopMatrix();
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.7);
	glRotatef(90.0, 1.0, 0.0, 0.0); // 将圆柱体旋转使其垂直于xy平面
	glTranslatef(-0.5, 0.0, -0.05);
	GLUquadricObj *rightear = gluNewQuadric(); // 创建圆柱体对象
	gluCylinder(rightear, 0.1, 0.1, 0.3, 20, 20); // 绘制圆柱体
	glPopMatrix();
	//画眼睛
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);  // 设置眼睛颜色
	glTranslatef(0.22, 0.0, 0.5);
	glutSolidSphere(0.075, 30, 30);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);  
	glTranslatef(-0.22, 0.0, 0.5);
	glutSolidSphere(0.075, 30, 30);
	glPopMatrix();
	//画嘴巴
	glPushMatrix();
	glTranslatef(0.0, -0.3, 0.46);
	mouse();
	glPopMatrix();
	//画帽子
	glPushMatrix();
	glTranslatef(0.0, 0.25, 0.0);
	drawhat(0.8, 1.3, 50);
	glPopMatrix();
	// 画身体
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);  // 设置身体颜色
	glTranslatef(0.0, -1.55, 0.0);
	glScalef(1.1, 2.0, 0.5);
	glutSolidCube(1.0);
	
	glScalef(1 / 1.1, 1 / 2.0, 1 / 0.5);
	
	//画领结
	glPushMatrix();
	glTranslatef(0.0, 0.8, 0.252);
	bowtie();
	glPopMatrix();

	// 左肩关节
	glPushMatrix();
	color_joint();
	glTranslatef(-0.7, 0.85, 0.0);
	glutWireSphere(0.2, 20, 20);
	// 左上臂
	glPushMatrix();
	color_skin();
	// 应用摆动角度
	switch (flag)
	{
	case 0:
		//静止
		break;
	case 1:
		//打招呼
		glRotatef(2 * left_upper_arm_swing_angle, 0.0, 0.0, 1.0);
		break;
	case 2:
		//摊手
		glRotatef(left_upper_arm_swing_angle, 0.0, 0.0, 1.0);
		break;
	case 3:
		//原地踏步
		glRotatef(2 * left_upper_arm_swing_angle, 1.0, 0.0, 0.15);
		break;
	case 4:
		//马步下蹲
		glRotatef(0.7* left_upper_arm_swing_angle, 1.0, -1.0, 0.0);
		break;
	default:
		break;
	}
	glRotatef(90.0, 1.0, 0.0, 0.0); // 将圆柱体旋转使其垂直于xy平面
	GLUquadricObj *leftUpperArmCylinder = gluNewQuadric(); // 创建圆柱体对象
	gluCylinder(leftUpperArmCylinder, 0.2, 0.15, 1.0, 20, 20); // 绘制圆柱体
	// 左肘关节
	glPushMatrix();
	color_joint();
	glTranslatef(0.0, 0.0, 1.0);
	glutWireSphere(0.15, 20, 20);
	// 左下臂
	glPushMatrix();
	color_skin();
	// 应用摆动角度
	switch (flag)
	{
	case 0:
		//静止
		break;
	case 1:
		//打招呼
		glRotatef(3 * left_lower_arm_swing_angle, 0.0, 1.0, 0.0);
		break;
	case 2:
		//摊手
		glRotatef(3 * left_lower_arm_swing_angle, 0.0, 1.0, 0.0);
		break;
	case 3:
		//原地踏步
		glRotatef(3 * left_lower_arm_swing_angle, 0.0, -1.0, 0.0); 
		break;
	case 4:
		//马步下蹲
		glRotatef(3.7 * left_lower_arm_swing_angle, -1.0, 0.18, 0.0);
		break;
	default:
		break;
	}
	GLUquadricObj *leftLowerArmCylinder = gluNewQuadric();
	gluCylinder(leftLowerArmCylinder, 0.15, 0.12, 0.8, 20, 20);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();



	// 右肩关节
	glPushMatrix();
	color_joint();
	glTranslatef(0.7, 0.85, 0.0);
	glutWireSphere(0.2, 20, 20);
	// 右上臂
	glPushMatrix();
	color_skin();
	// 应用摆动角度
	switch (flag)
	{
	case 0:
		//静止
		break;
	case 1:
		//打招呼
		break;
	case 2:
		//摊手
		glRotatef(right_upper_arm_swing_angle, 0.0, 0.0, -1.0);
		break;
	case 3:
		//原地踏步
		glRotatef(2 * right_upper_arm_swing_angle, -1.0, 0.0, 0.15);
		break;
	case 4:
		//马步下蹲
		glRotatef(0.7 * right_upper_arm_swing_angle, 1.0, -1.0, 0.0);
		break;
	default:
		break;
	}
	glRotatef(90.0, 1.0, 0.0, 0.0);
	GLUquadricObj *rightUpperArmCylinder = gluNewQuadric();
	gluCylinder(rightUpperArmCylinder, 0.2, 0.15, 1.0, 20, 20);
	// 右肘关节
	glPushMatrix();
	color_joint();
	glTranslatef(0.0, 0.0, 1.0);
	glutWireSphere(0.15, 20, 20);
	// 右下臂
	glPushMatrix();
	color_skin();
	// 应用摆动角度
	switch (flag)
	{
	case 0:
		//静止
		break;
	case 1:
		//打招呼
		break;
	case 2:
		//摊手
		glRotatef(2 * right_lower_arm_swing_angle, 0.0, -1.0, 0.0);
		break;
	case 3:
		//原地踏步
		glRotatef(3 * right_lower_arm_swing_angle, 0.0, -1.0, 0.0);
		break;
	case 4:
		//马步下蹲
		glRotatef(3.7 * right_lower_arm_swing_angle, 1.0, -0.18, 0.0);
		break;
	default:
		break;
	}
	GLUquadricObj *rightLowerArmCylinder = gluNewQuadric();
	gluCylinder(rightLowerArmCylinder, 0.15, 0.12, 0.9, 20, 20);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	// 左髋关节
	glPushMatrix();
	color_joint();
	glTranslatef(-0.35, -1.1, 0.0);
	glutWireSphere(0.23, 20, 20);
	// 左大腿
	glPushMatrix();
	color_skin();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	// 应用摆动角度
	switch (flag)
	{
	case 0:
		//静止
		break;
	case 1:
		//打招呼
		break;
	case 2:
		//摊手
		break;
	case 3:
		//原地踏步
		glRotatef(2 * left_upper_leg_swing_angle, -1.0, 0.0, 0.0);
		break;
	case 4:
		//马步下蹲
		glRotatef(2 * left_upper_leg_swing_angle, -1.0, -0.4, 0.0);
		break;
	default:
		break;
	}
	GLUquadricObj *leftUpperLegCylinder = gluNewQuadric();
	gluCylinder(leftUpperLegCylinder, 0.23, 0.2, 1.2, 20, 20);
	// 左膝关节
	glPushMatrix();
	color_joint();
	glTranslatef(0.0, 0.0, 1.2);
	glutWireSphere(0.2, 20, 20);
	// 左小腿
	glPushMatrix();
	color_skin();
	// 应用摆动角度
	switch (flag)
	{
	case 0:
		//静止
		break;
	case 1:
		//打招呼
		break;
	case 2:
		//摊手
		break;
	case 3:
		//原地踏步
		glRotatef(2 * left_lower_leg_swing_angle, 1.0, 0.0, 0.0);
		break;
	case 4:
		//马步下蹲
		glRotatef(2 * left_lower_leg_swing_angle, 1.0, 0.4, 0.0);
		break;
	default:
		break;
	}
	GLUquadricObj *leftLowerLegCylinder = gluNewQuadric();
	gluCylinder(leftLowerLegCylinder, 0.2, 0.15, 1.1, 20, 20);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	// 右髋关节
	glPushMatrix();
	color_joint();
	glTranslatef(0.35, -1.1, 0.0);
	glutWireSphere(0.23, 20, 20);
	// 右大腿
	glPushMatrix();
	color_skin();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	// 应用摆动角度
	switch (flag)
	{
	case 0:
		//静止
		break;
	case 1:
		//打招呼
		break;
	case 2:
		//摊手
		break;
	case 3:
		//原地踏步
		glRotatef(2 * right_upper_leg_swing_angle, 1.0, 0.0, 0.0);
		break;
	case 4:
		//马步下蹲
		glRotatef(2 * right_upper_leg_swing_angle, -1.0, 0.4, 0.0);
		break;
	default:
		break;
	}
	GLUquadricObj *rightUpperLegCylinder = gluNewQuadric();
	gluCylinder(rightUpperLegCylinder, 0.23, 0.2, 1.2, 20, 20);
	// 右膝关节
	glPushMatrix();
	color_joint();
	glTranslatef(0.0, 0.0, 1.2);
	glutWireSphere(0.2, 20, 20);
	// 右小腿
	glPushMatrix();
	color_skin();
	// 应用摆动角度
	switch (flag)
	{
	case 0:
		//静止
		break;
	case 1:
		//打招呼
		break;
	case 2:
		//摊手
		break;
	case 3:
		//原地踏步
		glRotatef(2 * right_lower_leg_swing_angle, -1.0, 0.0, 0.0);
		break;
	case 4:
		//马步下蹲
		glRotatef(2 * right_lower_leg_swing_angle, 1.0, -0.4, 0.0);
		break;
	default:
		break;
	}
	GLUquadricObj *rightLowerLegCylinder = gluNewQuadric();
	gluCylinder(rightLowerLegCylinder, 0.2, 0.15, 1.1, 20, 20);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	
	glPopMatrix();
	glPopMatrix();

	glFlush();
}

void spin()
{
	sp += 0.1;
	glutPostRedisplay();
}
void LYQ::onDisplay()
{	
	// 设置窗口背景颜色
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	init();
	gluLookAt(-1.5, 0, 5.8, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	drawRobot();

	if (flag == 5){
		glutIdleFunc(spin);
	}
}


void LYQ::update(int value)
{
	float currentTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0; // 获取自程序运行开始以来经过的时间（秒）
	switch (flag)
	{
	case 0:
		//静止状态
		initGlobalVariables();
		break;
	case 1://打招呼
		initGlobalVariables();
		Greet(currentTime, body_center_x, body_center_y, body_center_z,
			left_upper_arm_swing_angle, right_upper_arm_swing_angle,
			left_lower_arm_swing_angle, right_lower_arm_swing_angle,
			left_upper_leg_swing_angle, right_upper_leg_swing_angle,
			left_lower_leg_swing_angle, right_lower_leg_swing_angle);
		break;
	case 2://摊手
		initGlobalVariables();
		SpreadHands(currentTime, body_center_x, body_center_y, body_center_z,
			left_upper_arm_swing_angle, right_upper_arm_swing_angle,
			left_lower_arm_swing_angle, right_lower_arm_swing_angle,
			left_upper_leg_swing_angle, right_upper_leg_swing_angle,
			left_lower_leg_swing_angle, right_lower_leg_swing_angle);

		break;
	case 3://原地踏步
		initGlobalVariables();
		MarchOnTheSpot(currentTime, body_center_x, body_center_y, body_center_z,
		left_upper_arm_swing_angle, right_upper_arm_swing_angle,
		left_lower_arm_swing_angle, right_lower_arm_swing_angle,
		left_upper_leg_swing_angle, right_upper_leg_swing_angle,
		left_lower_leg_swing_angle, right_lower_leg_swing_angle);
		break;
	case 4://扎马步
		initGlobalVariables();
		HorseRidingStance(currentTime, body_center_x, body_center_y, body_center_z,
			left_upper_arm_swing_angle, right_upper_arm_swing_angle,
			left_lower_arm_swing_angle, right_lower_arm_swing_angle,
			left_upper_leg_swing_angle, right_upper_leg_swing_angle,
			left_lower_leg_swing_angle, right_lower_leg_swing_angle);
		break;
	case 5://自旋
		//initGlobalVariables();
		break;
	default:
		break;
	}
	glutPostRedisplay(); // 重新绘制场景
	glutTimerFunc(1000 / 60, update, value + 1); // 设置下一帧更新时间
}
