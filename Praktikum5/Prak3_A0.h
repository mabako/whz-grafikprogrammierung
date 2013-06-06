
// Prak3_A0.h: Hauptheaderdatei für die PROJECT_NAME-Anwendung
//

#pragma once

#ifndef __AFXWIN_H__
	#error "'stdafx.h' vor dieser Datei für PCH einschließen"
#endif

#include "resource.h"		// Hauptsymbole


// CPrak3_A0App:
// Siehe Prak3_A0.cpp für die Implementierung dieser Klasse
//

class CPrak3_A0App : public CWinAppEx
{
public:
	CPrak3_A0App();

// Überschreibungen
	public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};

extern CPrak3_A0App theApp;