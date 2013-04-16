#include "stdafx.h"

extern CServer gs;

CKreis::CKreis(void) {

}

CKreis::CKreis(int objektnummer, CPunkt mittelpunkt, float radius) {
	Set(objektnummer, mittelpunkt, radius);
}

CKreis::~CKreis() {
}

void CKreis::Zeichnen() {
	gs.gcreate_seg(m_iObjNr);

	Gpoint_list kreis;
	// Mittelpunkt, Peripheriepunkt
	Gpoint punkte[2] = {{m_MP.get_x(), m_MP.get_y()}, {m_MP.get_x() + m_fRadius, m_MP.get_y()}};
	kreis.num_points = 2;
	kreis.points = punkte;
	gs.gx_circle(&kreis);

	gs.gclose_seg();
}

void CKreis::Set(int objektnummer, CPunkt mittelpunkt, float radius) {
	m_iObjNr = objektnummer;
	m_MP = mittelpunkt;
	m_fRadius = radius;
}

void CKreis::Schieben(CVektor v) {
	m_MP.schieben(v);
}

void CKreis::Drehen(CPunkt basisPunkt, float winkel)
{
	m_MP.drehen(basisPunkt, winkel);
}

