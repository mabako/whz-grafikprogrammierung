
// Praktikum3.h: Hauptheaderdatei f�r die PROJECT_NAME-Anwendung
//

#pragma once

#ifndef __AFXWIN_H__
	#error "'stdafx.h' vor dieser Datei f�r PCH einschlie�en"
#endif

#include "resource.h"		// Hauptsymbole


// CPraktikum3App:
// Siehe Praktikum3.cpp f�r die Implementierung dieser Klasse
//

class CPraktikum3App : public CWinApp
{
public:
	CPraktikum3App();

// �berschreibungen
public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};

extern CPraktikum3App theApp;