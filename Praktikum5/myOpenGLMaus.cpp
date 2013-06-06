#include "StdAfx.h"
#include "myopenglMaus.h"

myOpenGL::myOpenGL(void)
{
	
}

myOpenGL::~myOpenGL(void)
{	
}

void myOpenGL::OnSizeGL(int cx, int cy)
{
	// TODO: Fügen Sie hier Ihren Meldungsbehandlungscode ein.
	glViewport(0,0,cx,cy);	
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
	m_pGrafik->Draw();
}
