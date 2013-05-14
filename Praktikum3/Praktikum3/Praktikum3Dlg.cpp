
// Praktikum3Dlg.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "Praktikum3.h"
#include "Praktikum3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg-Dialogfeld für Anwendungsbefehl "Info"

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialogfelddaten
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

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
	, m_fMinX(0)
	, m_fMaxX(0)
	, m_fMinY(0)
	, m_fMaxY(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPraktikum3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EMINX, m_fMinX);
	DDX_Text(pDX, IDC_EMAXX, m_fMaxX);
	DDX_Text(pDX, IDC_EMINY, m_fMinY);
	DDX_Text(pDX, IDC_EMAXY, m_fMaxY);
}

BEGIN_MESSAGE_MAP(CPraktikum3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BZOOMALLES, &CPraktikum3Dlg::OnBnClickedBzoomalles)
	ON_BN_CLICKED(IDC_BACTION, &CPraktikum3Dlg::OnBnClickedBaction)
END_MESSAGE_MAP()


// CPraktikum3Dlg-Meldungshandler

BOOL CPraktikum3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Hinzufügen des Menübefehls "Info..." zum Systemmenü.

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

	// Symbol für dieses Dialogfeld festlegen. Wird automatisch erledigt
	//  wenn das Hauptfenster der Anwendung kein Dialogfeld ist
	SetIcon(m_hIcon, TRUE);			// Großes Symbol verwenden
	SetIcon(m_hIcon, FALSE);		// Kleines Symbol verwenden

	// TODO: Hier zusätzliche Initialisierung einfügen

	// OGL-Fenster konfigurieren
	float xmin, xmax, ymin, ymax;
	m_cGrafik.GetModellRaum(xmin, xmax, ymin, ymax);
	float width = xmax - xmin, height = ymax - ymin;

	m_wOpenGL.InitOpenGL("Übersichtsfenster", 0.f, width, 0.f, height);
	m_wOpenGL2.InitOpenGL("Zoomfenster", width, 1.5f * width, 0.f, height);

	// Grafik dem OpenGL-Fenster zuordnen
	m_wOpenGL.setGrafik(&m_cGrafik);
	m_wOpenGL2.setGrafik(&m_cGrafik);
	m_wOpenGL.shareContext(m_wOpenGL2);

	// Grafik initialisieren (wenn notwendig)
	m_cGrafik.Init();

	// WC-Window setzen
	m_wOpenGL.setWindow(xmin - 0.1*width, xmax + 0.1*width, ymin - 0.1*height, ymax + 0.1*height);
	m_wOpenGL2.setWindow(xmin, xmax, ymin, ymax);

	OnBnClickedBzoomalles();

	return TRUE;  // TRUE zurückgeben, wenn der Fokus nicht auf ein Steuerelement gesetzt wird
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

// Wenn Sie dem Dialogfeld eine Schaltfläche "Minimieren" hinzufügen, benötigen Sie
//  den nachstehenden Code, um das Symbol zu zeichnen. Für MFC-Anwendungen, die das 
//  Dokument/Ansicht-Modell verwenden, wird dies automatisch ausgeführt.

void CPraktikum3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Gerätekontext zum Zeichnen

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

// Die System ruft diese Funktion auf, um den Cursor abzufragen, der angezeigt wird, während der Benutzer
//  das minimierte Fenster mit der Maus zieht.
HCURSOR CPraktikum3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPraktikum3Dlg::OnBnClickedBzoomalles()
{
	float minx, maxx, miny, maxy;
	m_cGrafik.GetModellRaum(minx, maxx, miny, maxy);
	m_wOpenGL2.setWindow(minx, maxx, miny, maxy);
	m_wOpenGL2.Invalidate();

	m_fMinX = minx;
	m_fMaxX = maxx;
	m_fMinY = miny;
	m_fMaxY = maxy;
	UpdateData(false);
}


void CPraktikum3Dlg::OnBnClickedBaction()
{
	UpdateData(true);

	float minx = m_fMinX, maxx = m_fMaxX, miny = m_fMinY, maxy = m_fMaxY;
	m_wOpenGL2.setWindow(minx, maxx, miny, maxy);
	m_wOpenGL2.Invalidate();
}
