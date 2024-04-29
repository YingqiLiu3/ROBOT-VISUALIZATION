#ifndef LYQROB
#define LYQROB

#include "stdafx.h"
#include <glut.h>
#include "global_variables.h"
#include "init_gv.h"
#include <Windows.h>
#include <math.h>

class LYQ
{
public:
	LYQ();
	~LYQ();
	static int flag;
	static void init();
	static void drawRobot();
	static void onDisplay();
	static void update(int value);
};


#endif