
// MFCStudyView.h : CMFCStudyView Ŭ������ �������̽�
//

#pragma once
#include "atltypes.h"


class CMFCStudyView : public CView
{
protected: // serialization������ ��������ϴ�.
	CMFCStudyView();
	DECLARE_DYNCREATE(CMFCStudyView)

// Ư���Դϴ�.
public:
	CMFCStudyDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CMFCStudyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	bool m_bTimerRun;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CString m_strTimer;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
	CString m_strOutText;
	CPoint m_ptNow;
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	CPoint m_ptClientSize;
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // MFCStudyView.cpp�� ����� ����
inline CMFCStudyDoc* CMFCStudyView::GetDocument() const
   { return reinterpret_cast<CMFCStudyDoc*>(m_pDocument); }
#endif

