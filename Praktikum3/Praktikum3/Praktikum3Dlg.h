
// Praktikum3Dlg.h: Headerdatei
//

#pragma once


// CPraktikum3Dlg-Dialogfeld
class CPraktikum3Dlg : public CDialogEx
{
private:
	myOpenGL m_wOpenGL;
	myOpenGL m_wOpenGL2; // OpenGL-Fenster
	CGrafik m_cGrafik; // Darzustellende Grafik

// Konstruktion
public:
	CPraktikum3Dlg(CWnd* pParent = NULL);	// Standardkonstruktor

// Dialogfelddaten
	enum { IDD = IDD_PRAKTIKUM3_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterst�tzung


// Implementierung
protected:
	HICON m_hIcon;

	// Generierte Funktionen f�r die Meldungstabellen
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBzoomalles();
	afx_msg void OnBnClickedBaction();
private:
	float m_fMinX;
	float m_fMaxX;
	float m_fMinY;
	float m_fMaxY;
};
