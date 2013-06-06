
// Prak3_A0.cpp: Definiert das Klassenverhalten für die Anwendung.
//

#include "stdafx.h"
#include "Prak3_A0.h"
#include "Prak3_A0Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPrak3_A0App

BEGIN_MESSAGE_MAP(CPrak3_A0App, CWinAppEx)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CPrak3_A0App-Erstellung

CPrak3_A0App::CPrak3_A0App()
{
	// TODO: Hier Code zur Konstruktion einfügen
	// Alle wichtigen Initialisierungen in InitInstance positionieren
}


// Das einzige CPrak3_A0App-Objekt

CPrak3_A0App theApp;


// CPrak3_A0App-Initialisierung

BOOL CPrak3_A0App::InitInstance()
{
	// InitCommonControlsEx() ist für Windows XP erforderlich, wenn ein Anwendungsmanifest
	// die Verwendung von ComCtl32.dll Version 6 oder höher zum Aktivieren
	// von visuellen Stilen angibt. Ansonsten treten beim Erstellen von Fenstern Fehler auf.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Legen Sie dies fest, um alle allgemeinen Steuerelementklassen einzubeziehen,
	// die Sie in Ihrer Anwendung verwenden möchten.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	AfxEnableControlContainer();

	// Standardinitialisierung
	// Wenn Sie diese Features nicht verwenden und die Größe
	// der ausführbaren Datei verringern möchten, entfernen Sie
	// die nicht erforderlichen Initialisierungsroutinen.
	// Ändern Sie den Registrierungsschlüssel, unter dem Ihre Einstellungen gespeichert sind.
	// TODO: Ändern Sie diese Zeichenfolge entsprechend,
	// z.B. zum Namen Ihrer Firma oder Organisation.
	SetRegistryKey(_T("Vom lokalen Anwendungs-Assistenten generierte Anwendungen"));

	CPrak3_A0Dlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Fügen Sie hier Code ein, um das Schließen des
		//  Dialogfelds über "OK" zu steuern
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Fügen Sie hier Code ein, um das Schließen des
		//  Dialogfelds über "Abbrechen" zu steuern
	}

	// Da das Dialogfeld geschlossen wurde, FALSE zurückliefern, sodass wir die
	//  Anwendung verlassen, anstatt das Nachrichtensystem der Anwendung zu starten.
	return FALSE;
}
