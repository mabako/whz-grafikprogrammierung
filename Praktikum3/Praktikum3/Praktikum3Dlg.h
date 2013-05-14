
// Praktikum3Dlg.h: Headerdatei
//

#pragma once


// CPraktikum3Dlg-Dialogfeld
class CPraktikum3Dlg : public CDialogEx
{
private:
	myOpenGL m_wOpenGL; // OpenGL-Fenster
	CGrafik m_cGrafik; // Darzustellende Grafik

// Konstruktion
public:
	CPraktikum3Dlg(CWnd* pParent = NULL);	// Standardkonstruktor

// Dialogfelddaten
	enum { IDD = IDD_PRAKTIKUM3_DIALOG };

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
	float m_fDxDlg;
	float m_fDyDlg;
public:
	afx_msg void OnBnClickedBaktion();
};
