#include "StdAfx.h"
#include "GKS_Programm.h"

extern CServer gs;

//#define A2

CGKS_Programm::CGKS_Programm(void)
{
}

CGKS_Programm::~CGKS_Programm(void)
{
}

void CGKS_Programm::execute()
{
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

	AfxMessageBox("Grafik gezeichnet");

#ifdef A2
	// Figur 1 löschen
	loeschen(101);
	loeschen(102);
	loeschen(103);
	AfxMessageBox("Figur 1 gelöscht");

	// Mittlere Linien von Fgigur 3 löschen
	loeschen(302);
	loeschen(303);
	AfxMessageBox("Linien in Figur 3 gelöscht");

	// Bildschirm löschen
	clearScreen();
	AfxMessageBox("BS gelöscht");
	m_DatenBasis.redraw();
#else
	// Verschieben von Figur 1 um 200, 130
	CVektor v;
	v.set(200, 130);
	schieben(101, v);
	schieben(102, v);
	schieben(103, v);
	AfxMessageBox("Figur 1 verschoben");

	// Figur 3 um -45° bezüglich des Punktes 150, 200 drehen
	CPunkt bas;
	bas.set(150, 200);
	for(int i = 301; i <= 304; ++ i)
	{
		drehen(i, bas, -45);
	}

	// Figur 1 um 45° bezüglich des aktuellen Mittelpunkts (300, 230) drehen
	bas.set(300, 230);
	drehen(101, bas, 45);
	drehen(102, bas, 45);
	drehen(103, bas, 45);

	// Figur 2 um (-150, 100) verschieben
	v.set(-150, 100);
	schieben(201, v);
	schieben(202, v);
	AfxMessageBox("Figur 2 verschoben");

	// Figur 3 löschen
	for(int i = 301; i <= 304; ++ i)
	{
		loeschen(i);
	}
	AfxMessageBox("Figur 3 gelöscht");
#endif

	// Haltepunkt
	AfxMessageBox("Programmende");
}

void CGKS_Programm::loeschen(int objNr)
{
	CGeoObject* pObject = m_DatenBasis.searchObject(objNr);
	m_DatenBasis.deleteObject(pObject);
}

void CGKS_Programm::schieben(int objNr, CVektor v) {
	// Objekt in der Datenbasis suchen.
	CGeoObject* pObject = m_DatenBasis.searchObject(objNr);

	// Gefundenes Objekt verschieben
	pObject->Schieben(v);

	// Alte Grafik löschen
	pObject->LoescheGrafik();

	// Neu zeichnen
	pObject->Zeichnen();
}

void CGKS_Programm::drehen(int objNr, CPunkt basisPunkt, float winkel)
{
	// Objekt in der Datenbasis suchen.
	CGeoObject* pObject = m_DatenBasis.searchObject(objNr);

	// Gefundenes Objekt drehen
	pObject->Drehen(basisPunkt, winkel);

	// Alte Grafik löschen
	pObject->LoescheGrafik();

	// Neu zeichnen
	pObject->Zeichnen();
}

void CGKS_Programm::clearScreen()
{
	gs.gx_clear_ws(1);
}

void CGKS_Programm::startGKS(void)
{
	// Server starten	
	gs.gopen_gks("con");
	gs.gopen_ws(1,NULL,GKS_SUBWINDOW);
	gs.gactivate_ws(1);
	gs.gx_set_win(1,0,420,0,300);
	gs.gx_set_vp(1,0,1,0.1,0.85);
}

void CGKS_Programm::stopGKS(void)
{
	gs.gdeactivate_ws(1);
	gs.gclose_ws(1);
	// Server beenden
	gs.gclose_gks();
}
