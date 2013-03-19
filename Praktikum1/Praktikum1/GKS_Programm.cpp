#include "StdAfx.h"
#include "GKS_Programm.h"

extern CServer gs;

CGKS_Programm::CGKS_Programm(void)
{
}

CGKS_Programm::~CGKS_Programm(void)
{
}

void CGKS_Programm::execute()
{
	AfxMessageBox("Programmende");
}

void CGKS_Programm::startGKS(void)
{
	// Server starten	
	gs.gopen_gks("con");
	gs.gopen_ws(1,NULL,GKS_SUBWINDOW);
	gs.gactivate_ws(1);
	gs.gx_set_win(1,0,400,0,300);
	gs.gx_set_vp(1,0,1,0.1,0.85);
}

void CGKS_Programm::stopGKS(void)
{
	gs.gdeactivate_ws(1);
	gs.gclose_ws(1);
	// Server beenden
	gs.gclose_gks();
}
