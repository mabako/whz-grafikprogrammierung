
// Praktikum3.h: Hauptheaderdatei für die PROJECT_NAME-Anwendung
//

#pragma once

#ifndef __AFXWIN_H__
	#error "'stdafx.h' vor dieser Datei für PCH einschließen"
#endif

#include "resource.h"		// Hauptsymbole


// CPraktikum3App:
// Siehe Praktikum3.cpp für die Implementierung dieser Klasse
//

class CPraktikum3App : public CWinApp
{
public:
	CPraktikum3App();

// Überschreibungen
public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};

extern CPraktikum3App theApp;