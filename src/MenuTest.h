
// MenuTest.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMenuTestApp:
// See MenuTest.cpp for the implementation of this class
//

class CMenuTestApp : public CWinApp
{
public:
	CMenuTestApp();

public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CMenuTestApp theApp;