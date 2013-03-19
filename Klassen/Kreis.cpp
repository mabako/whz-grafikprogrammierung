#include "stdafx.h"

CKreis::CKreis(void) {

}

CKreis::CKreis(int objektnummer, CPunkt mittelpunkt, float radius) {
	Set(objektnummer, mittelpunkt, radius);
}

CKreis::~CKreis() {
}

void CKreis::Zeichnen() {
}

void CKreis::Set(int objektnummer, CPunkt mittelpunkt, float radius) {
	m_iObjNr = objektnummer;
	m_MP = mittelpunkt;
	m_fRadius = radius;
}