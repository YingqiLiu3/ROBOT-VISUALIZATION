// �����˿��ӻ�-��Ӣ��-�γ���ƴ���ҵ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <glut.h>
#include "LYQROB.h"
#define ROBSTATIC 1 //��̬
#define GRT 2 //���к�
#define SH 3 //̯��
#define MOTS 4 //ԭ��̤��
#define HRS 5 //���¶�
#define SPIN 6 //����
GLint nSelected = ROBSTATIC;
void makeMenu()
{
	glutAddMenuEntry("1 ��ֹ", ROBSTATIC);
	glutAddMenuEntry("2 ���к�", GRT);
	glutAddMenuEntry("3 ̯��", SH);
	glutAddMenuEntry("4 ԭ��̤��", MOTS);
	glutAddMenuEntry("5 ���¶�", HRS);
	glutAddMenuEntry("6 ����", SPIN);
	glutAttachMenu(GLUT_RIGHT_BUTTON);  //ָ���˵��¼�������Ҽ���������
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
	glutCreateWindow("��Ӣ���γ���ƴ���ҵ");
	glutCreateMenu(OnMenu);
	glutDisplayFunc(onDisplay);
	glutTimerFunc(0, LYQ::update, 0); // ��ʼ���¶���
	makeMenu();
	glEnable(GL_DEPTH_TEST);
	
	glutMainLoop();
	return 0;
}

