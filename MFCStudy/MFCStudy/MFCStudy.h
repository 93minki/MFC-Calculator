
// MFCStudy.h : MFCStudy ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMFCStudyApp:
// �� Ŭ������ ������ ���ؼ��� MFCStudy.cpp�� �����Ͻʽÿ�.
//

class CMFCStudyApp : public CWinApp
{
public:
	CMFCStudyApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCStudyApp theApp;
