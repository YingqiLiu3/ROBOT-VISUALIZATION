// 机器人可视化-刘英琦-课程设计大作业.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <glut.h>
#include "LYQROB.h"
#define ROBSTATIC 1 //静态
#define GRT 2 //打招呼
#define SH 3 //摊手
#define MOTS 4 //原地踏步
#define HRS 5 //马步下蹲
#define SPIN 6 //自旋
GLint nSelected = ROBSTATIC;
void makeMenu()
{
	glutAddMenuEntry("1 静止", ROBSTATIC);
	glutAddMenuEntry("2 打招呼", GRT);
	glutAddMenuEntry("3 摊手", SH);
	glutAddMenuEntry("4 原地踏步", MOTS);
	glutAddMenuEntry("5 马步下蹲", HRS);
	glutAddMenuEntry("6 自旋", SPIN);
	glutAttachMenu(GLUT_RIGHT_BUTTON);  //指定菜单事件由鼠标右键单击产生
}

void OnMenu(int value)
{

	switch (value)
	{
	case ROBSTATIC:
		nSelected = ROBSTATIC;
		break;
	case GRT:
		nSelected = GRT;
		break;
	case SH:
		nSelected = SH;
		break;
	case MOTS:
		nSelected = MOTS;
		break;
	case HRS:
		nSelected = HRS;
		break;
	case SPIN:
		nSelected = SPIN;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}
void onDisplay(){
	LYQ::onDisplay();
	switch (nSelected)
	{
	case ROBSTATIC:
		LYQ::flag = 0;
		break;
	case GRT:
		LYQ::flag = 1;
		break;
	case SH:
		LYQ::flag = 2;
		break;
	case MOTS:
		LYQ::flag = 3;
		break;
	case HRS:
		LYQ::flag = 4;
		break;
	case SPIN:
		LYQ::flag = 5;
		break;
	default:
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("刘英琦课程设计大作业");
	glutCreateMenu(OnMenu);
	glutDisplayFunc(onDisplay);
	glutTimerFunc(0, LYQ::update, 0); // 开始更新动画
	makeMenu();
	glEnable(GL_DEPTH_TEST);
	
	glutMainLoop();
	return 0;
}

