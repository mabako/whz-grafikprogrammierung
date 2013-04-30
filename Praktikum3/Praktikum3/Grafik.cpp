#include "StdAfx.h"
#include "Grafik.h"

CGrafik::CGrafik(void)
{
}

CGrafik::~CGrafik(void)
{
}

void CGrafik::Init()
{
}

void CGrafik::Draw()
{
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
		glVertex2f(0, 0);
		glVertex2f(90,10);
		glVertex2f(50,80);                
	glEnd();
	glFlush();        
}