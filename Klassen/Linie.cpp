#include "stdafx.h"

CLinie::CLinie() {
}

CLinie::CLinie(int objektnummer, CPunkt anfang, CPunkt ende) {
	Set(objektnummer, anfang, ende);
}

CLinie::~CLinie() {
}

void CLinie::Zeichnen() {
}

void CLinie::Set(int objektnummer, CPunkt anfang, CPunkt ende) {
	m_iObjNr = objektnummer;
	m_AP = anfang;
	m_EP = ende;
}
