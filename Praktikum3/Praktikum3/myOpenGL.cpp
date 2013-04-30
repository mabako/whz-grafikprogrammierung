#include "StdAfx.h"
#include "myopengl.h"

myOpenGL::myOpenGL(void)
{
}

myOpenGL::~myOpenGL(void)
{	
}

void myOpenGL::OnSizeGL(int cx, int cy)
{
	float seitenverhaeltnis = getRatio();
	if(cx > cy * seitenverhaeltnis)
	{
		glViewport(0, 0, cy * seitenverhaeltnis, cy);
	}
	else
	{
		glViewport(0, 0, cx, cx / seitenverhaeltnis);
	}
}

void myOpenGL::OnDrawGL()
{
	/************ Teil 1: Vorbereitung der Grafik-Ausgabe ***************/
	// Löschen des Fensterinhaltes
	glClearColor(m_fbgRed, m_fbgGreen, m_fbgBlue, 1);
	glClear (GL_COLOR_BUFFER_BIT);
	// Weltkoordinatenbereich festlegen
	glMatrixMode(GL_PROJECTION); // Projektionsmatrix aktivieren
	glLoadIdentity();  // Einheitsmatrix laden
	gluOrtho2D(m_fxmin, m_fxmax, m_fymin, m_fymax);  // WC-Bereich festlegen

	// Modell- und Ansichtstransformationsmatrix aktivieren
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/************* Teil 2: Grafik-Ausgabe *******************************/
	fillWindow();
	m_pGrafik->Draw();
}
