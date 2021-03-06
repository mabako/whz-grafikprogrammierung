
// Praktikum3Dlg.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "Praktikum3.h"
#include "Praktikum3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg-Dialogfeld f�r Anwendungsbefehl "Info"

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialogfelddaten
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterst�tzung

// Implementierung
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPraktikum3Dlg-Dialogfeld




CPraktikum3Dlg::CPraktikum3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPraktikum3Dlg::IDD, pParent)
	, m_fDxDlg(0)
	, m_fDyDlg(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPraktikum3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDX, m_fDxDlg);
	DDX_Text(pDX, IDC_EDY, m_fDyDlg);
}

BEGIN_MESSAGE_MAP(CPraktikum3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BAKTION, &CPraktikum3Dlg::OnBnClickedBaktion)
END_MESSAGE_MAP()


// CPraktikum3Dlg-Meldungshandler

BOOL CPraktikum3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Hinzuf�gen des Men�befehls "Info..." zum Systemmen�.

	// IDM_ABOUTBOX muss sich im Bereich der Systembefehle befinden.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Symbol f�r dieses Dialogfeld festlegen. Wird automatisch erledigt
	//  wenn das Hauptfenster der Anwendung kein Dialogfeld ist
	SetIcon(m_hIcon, TRUE);			// Gro�es Symbol verwenden
	SetIcon(m_hIcon, FALSE);		// Kleines Symbol verwenden

	// TODO: Hier zus�tzliche Initialisierung einf�gen

	float xmin = -250;
	float xmax = 250;
	float ymin = -50;
	float ymax = 350;

	// OGL-Fenster konfigurieren
	m_wOpenGL.InitOpenGL("Praktikum3", 0, xmax - xmin, 0, ymax - ymin);
	// Grafik dem OpenGL-Fenster zuordnen
	m_wOpenGL.setGrafik(&m_cGrafik);
	// Grafik initialisieren (wenn notwendig)
	m_cGrafik.Init();
	// WC-Window setzen
	m_wOpenGL.setWindow(xmin, xmax + 200, ymin, ymax);


	// Initialisierung der Schaltfl�chen
	m_fDxDlg = m_cGrafik.m_fDx;
	m_fDyDlg = m_cGrafik.m_fDy;
	UpdateData(false);


	return TRUE;  // TRUE zur�ckgeben, wenn der Fokus nicht auf ein Steuerelement gesetzt wird
}

void CPraktikum3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Wenn Sie dem Dialogfeld eine Schaltfl�che "Minimieren" hinzuf�gen, ben�tigen Sie
//  den nachstehenden Code, um das Symbol zu zeichnen. F�r MFC-Anwendungen, die das 
//  Dokument/Ansicht-Modell verwenden, wird dies automatisch ausgef�hrt.

void CPraktikum3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Ger�tekontext zum Zeichnen

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Symbol in Clientrechteck zentrieren
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Symbol zeichnen
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Die System ruft diese Funktion auf, um den Cursor abzufragen, der angezeigt wird, w�hrend der Benutzer
//  das minimierte Fenster mit der Maus zieht.
HCURSOR CPraktikum3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPraktikum3Dlg::OnBnClickedBaktion()
{
	UpdateData(true);
	m_cGrafik.m_fDx = m_fDxDlg;
	m_cGrafik.m_fDy = m_fDyDlg;
	m_wOpenGL.Invalidate();
}
