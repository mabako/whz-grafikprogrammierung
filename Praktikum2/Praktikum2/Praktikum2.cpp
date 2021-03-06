// Praktikum1.cpp : Definiert den Einsprungpunkt f�r die Konsolenanwendung.
//
#include "stdafx.h"
#include "Praktikum2.h"
#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Das einzige Anwendungsobjekt
CWinApp theApp;

#include "GKS_Programm.h"
CServer gs;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// MFC initialisieren. Bei Fehlschlag Fehlermeldung ausgeben.
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: Passen Sie den Fehlercode an Ihre Anforderungen an
		cerr << _T("Schwerwiegender Fehler: MFC-Initialisierung fehlgeschlagen") << endl;
		nRetCode = 1;
	}
	else
	{
		CGKS_Programm* gks_prog = new CGKS_Programm();
		gks_prog->startGKS();
		gks_prog->execute();
		gks_prog->stopGKS();
		delete gks_prog;
	}

	return nRetCode;
}
