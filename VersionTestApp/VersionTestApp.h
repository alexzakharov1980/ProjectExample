
// VersionTestApp.h : main header file for the VersionTestApp application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CVersionTestAppApp:
// See VersionTestApp.cpp for the implementation of this class
//

class CVersionTestAppApp : public CWinApp
{
public:
	CVersionTestAppApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
protected:
	HMENU  m_hMDIMenu;
	HACCEL m_hMDIAccel;

public:
	afx_msg void OnAppAbout();
	afx_msg void OnFileNew();
	DECLARE_MESSAGE_MAP()
};

extern CVersionTestAppApp theApp;
