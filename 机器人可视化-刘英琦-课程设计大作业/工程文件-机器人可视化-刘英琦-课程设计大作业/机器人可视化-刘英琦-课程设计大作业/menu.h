#ifndef MENU_
#define MENU_

#include "stdafx.h"
#include <glut.h>
#define ROBSTATIC 1
#define MOVE 2

GLint nSelected = ROBSTATIC;

void makeMenu()
{
	glutAddMenuEntry("1 ��ֹ", ROBSTATIC);
	glutAddMenuEntry("2 �˶�", MOVE);
	glutAttachMenu(GLUT_RIGHT_BUTTON);  //ָ���˵��¼�������Ҽ���������
}

void OnMenu(int value)
{

	switch (value)
	{
	case ROBSTATIC:
		nSelected = ROBSTATIC;
		break;
	case MOVE:
		nSelected = MOVE;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


#endif