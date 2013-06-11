
// Prak3_A0Dlg.h: Headerdatei
//

#pragma once
#include "myOpenglMaus.h"





// CPrak3_A0Dlg-Dialogfeld
class CPrak3_A0Dlg : public CDialog
{
// Konstruktion
public:
	CPrak3_A0Dlg(CWnd* pParent = NULL);	// Standardkonstruktor

// Dialogfelddaten
	enum { IDD = IDD_PRAK3_A0_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung


// Implementierung
protected:
	HICON m_hIcon;

	// Generierte Funktionen für die Meldungstabellen
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	myOpenGL m_wOpenGL; // OpenGL-Fenster
	CGrafik m_cGrafik;  // Darzustellende Grafik
public:
	int m_iLoeschen;
	afx_msg void OnBnClickedBloeschen();
};
