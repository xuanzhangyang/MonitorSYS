
// MonitorSYS.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMonitorSYSApp: 
// �йش����ʵ�֣������ MonitorSYS.cpp
//

class CMonitorSYSApp : public CWinApp
{
public:
	CMonitorSYSApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMonitorSYSApp theApp;