#include "StdAfx.h"

CGrafik::CGrafik(void)
{ }

CGrafik::~CGrafik(void)
{ }

void CGrafik::Init()
{
	// Aktuelle größte Objektnummer
	m_imaxNr = 100;  // Neue Objekte bekommen Nummern ab 101
	
	// OGL-Befehle
	glEnable(GL_COLOR_LOGIC_OP);

	// Ein Test-Objekt
	CLinie* p_linie;
	CKreis* p_kreis;
	float s45=0.5*sqrt(2.0f);
	// Figur 1
	CPunkt mp, p1, p2;
	mp.set(100,100);
	p1.set(100+50*s45,100+50*s45);
	p2.set(100-50*s45,100-50*s45);
	p_linie = new CLinie(101,p1, p2);
	m_DatenBasis.addObject(p_linie);
	p_linie->Zeichnen();

	p1.set(100+50*s45,100-50*s45);
	p2.set(100-50*s45,100+50*s45);
	p_linie = new CLinie(102,p1, p2);
	m_DatenBasis.addObject(p_linie);
	p_linie->Zeichnen();

	p_kreis = new CKreis(103,mp,50);
	m_DatenBasis.addObject(p_kreis);
	p_kreis->Zeichnen();

	// Figur 2
	mp.set(300,100);
	p_kreis = new CKreis(201,mp,25);
	m_DatenBasis.addObject(p_kreis);
	p_kreis->Zeichnen();
	p_kreis = new CKreis(202,mp,50);
	m_DatenBasis.addObject(p_kreis);
	p_kreis->Zeichnen();

	// Figur 3 (von unten nach oben)
	float x1=150, x2=250, y=200;
	for (int i=301; i<=304; i++)
	{
		p1.set(x1,y); p2.set(x2,y);
		p_linie = new CLinie(i,p1,p2);
		m_DatenBasis.addObject(p_linie);
		p_linie->Zeichnen();
		y = y + 25;
	}
}

void CGrafik::Draw()
{	
	drawObjects(GL_RENDER);  // Zeichnen aller Displaylisten
}

void CGrafik::drawObjects(GLenum mode)
{		
	glColor3f(1,0,0);

	int objekte[] = {101, 102, 103, 201, 202, 301, 302, 303, 304};
	for(GLuint i = 0; i < sizeof(objekte) / sizeof(objekte[0]); ++ i)
	{
		if (mode == GL_SELECT) glLoadName(objekte[i]);
		glCallList(objekte[i]);
	}
	glFlush();
}

// Implementierung der aufgabenspezifischen Methoden


