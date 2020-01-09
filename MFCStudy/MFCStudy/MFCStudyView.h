
// MFCStudyView.h : CMFCStudyView 클래스의 인터페이스
//

#pragma once
#include "atltypes.h"


class CMFCStudyView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMFCStudyView();
	DECLARE_DYNCREATE(CMFCStudyView)

// 특성입니다.
public:
	CMFCStudyDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMFCStudyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
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

#ifndef _DEBUG  // MFCStudyView.cpp의 디버그 버전
inline CMFCStudyDoc* CMFCStudyView::GetDocument() const
   { return reinterpret_cast<CMFCStudyDoc*>(m_pDocument); }
#endif

