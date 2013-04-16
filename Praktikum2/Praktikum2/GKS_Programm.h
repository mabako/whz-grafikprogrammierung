#pragma once

#include "DatenBasis.h"

class CGKS_Programm
{
private:
	CDatenBasis m_DatenBasis;
public:
	CGKS_Programm(void);
	~CGKS_Programm(void);
	void execute();
	void startGKS();
	void stopGKS();
	void loeschen(int objNr);
	void schieben(int objNr, CVektor v);
	void drehen(int objNr, CPunkt basisPunkt, float winkel);
	void clearScreen();
};
