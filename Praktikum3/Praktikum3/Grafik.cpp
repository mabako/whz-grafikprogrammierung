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
	// Rotes Rechteck [-200,200] x [0,300] mit Breitenfaktor 4.
	glLineWidth(4);
	glColor3f(1, 0, 0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(-200, 0);
		glVertex2f(200, 0);
		glVertex2f(200, 300);
		glVertex2f(-200, 300);
	glEnd();

	glFlush();
}