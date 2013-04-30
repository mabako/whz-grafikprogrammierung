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

	// Senkrechte Mittellinie des Rechtecks, Breitenfaktor 0.8, rot, Strichlinie
	glEnable(GL_LINE_STIPPLE);
	glLineWidth(0.8f);
	glLineStipple(1, 0xFF);
	glBegin(GL_LINES);
		glVertex2f(0, 0);
		glVertex2f(0, 300);
	glEnd();
	glDisable(GL_LINE_STIPPLE);

	// Dreieck (20, 20), (140, 20), (140, 260) mit einer Seitenhalbierenden.
	glLineWidth(2);
	glColor3f(0, 0, 1);
	glBegin(GL_LINE_STRIP);
		glVertex2f(20, 20);
		glVertex2f(140, 20);
		glVertex2f(140, 260);
		glVertex2f(20, 20);

		// Fortsetzung zur Seitenhalbierenden
		glVertex2f(140, 140);
	glEnd();

	// Eckpunkte des Dreiecks
	glPointSize(5);
	glColor3f(1, 1, 0);
	glBegin(GL_POINTS);
		glVertex2f(20, 20);
		glVertex2f(140, 20);
		glVertex2f(140, 260);
	glEnd();

	// Punkt-Raster im Abstand 20 für x >= 0

	// Quadrat (-100, 0) (-20, 80) (-100, 160) (-180, 80); Rot gefüllt mit gelbem Rand mit Breitenfaktor 2
	glColor3f(1, 0, 0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
		glVertex2f(-100, 0);
		glVertex2f(-20, 80);
		glVertex2f(-100, 160);
		glVertex2f(-180, 80);
	glEnd();

	glLineWidth(2);
	glColor3f(1, 1, 0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
		glVertex2f(-100, 0);
		glVertex2f(-20, 80);
		glVertex2f(-100, 160);
		glVertex2f(-180, 80);
	glEnd();

	glFlush();
}