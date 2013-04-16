#include "stdafx.h"

extern CServer gs;

CLinie::CLinie() {
}

CLinie::CLinie(int objektnummer, CPunkt anfang, CPunkt ende) {
	Set(objektnummer, anfang, ende);
}

CLinie::~CLinie() {
}

void CLinie::Zeichnen() {
	gs.gcreate_seg(m_iObjNr);

	Gpoint_list linie;
	Gpoint punkte[2] = {{m_AP.get_x(), m_AP.get_y()}, {m_EP.get_x(), m_EP.get_y()}};
	linie.num_points = 2;
	linie.points = punkte;
	gs.gpolyline(&linie);

	gs.gclose_seg();
}

void CLinie::Set(int objektnummer, CPunkt anfang, CPunkt ende) {
	m_iObjNr = objektnummer;
	m_AP = anfang;
	m_EP = ende;
}

void CLinie::Schieben(CVektor v) {
	m_AP.schieben(v);
	m_EP.schieben(v);
}

void CLinie::Drehen(CPunkt basisPunkt, float winkel)
{
	m_AP.drehen(basisPunkt, winkel);
	m_EP.drehen(basisPunkt, winkel);
}
