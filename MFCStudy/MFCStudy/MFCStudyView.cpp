
// MFCStudyView.cpp : CMFCStudyView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFCStudy.h"
#endif

#include "MFCStudyDoc.h"
#include "MFCStudyView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCStudyView

IMPLEMENT_DYNCREATE(CMFCStudyView, CView)

BEGIN_MESSAGE_MAP(CMFCStudyView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_DESTROY()
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CMFCStudyView 생성/소멸

CMFCStudyView::CMFCStudyView()
	: m_bTimerRun(false)
	, m_strTimer(_T(""))
	, m_strOutText(_T(""))
	, m_ptNow(0)
	, m_ptClientSize(0)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFCStudyView::~CMFCStudyView()
{
}

BOOL CMFCStudyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFCStudyView 그리기

void CMFCStudyView::OnDraw(CDC* pDC)
{
	CMFCStudyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	pDC->TextOut(m_ptNow.x, m_ptNow.y, m_strOutText);
	/* Timer */
	//CRect rect;
	//GetClientRect(&rect);
	//pDC->DrawText(m_strTimer, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}


// CMFCStudyView 인쇄

BOOL CMFCStudyView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFCStudyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFCStudyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMFCStudyView 진단

#ifdef _DEBUG
void CMFCStudyView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCStudyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCStudyDoc* CMFCStudyView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCStudyDoc)));
	return (CMFCStudyDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCStudyView 메시지 처리기


int CMFCStudyView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	/* Timer */
	//SetTimer(0, 1000, NULL);
	//m_bTimerRun = TRUE;
	return 0;
}


void CMFCStudyView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CTime timer;
	timer = CTime::GetCurrentTime();
	
	m_strTimer.Format("현재는 %d년 %d월 %d일 %d시 %d분 %d초 ",
		timer.GetYear(), timer.GetMonth(), timer.GetDay(),
		timer.GetHour(), timer.GetMinute(), timer.GetSecond());
	Invalidate();

	CView::OnTimer(nIDEvent);
}


void CMFCStudyView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_ptNow.x = point.x;
	m_ptNow.y = point.y;
	Invalidate();
	/* Timer */
	//if (!m_bTimerRun) {
	//	if (AfxMessageBox("디지털 시계 동작?", MB_YESNO | MB_ICONQUESTION) == IDYES) {
	//		SetTimer(0, 1000, NULL);
	//		m_bTimerRun = TRUE;
	//	}
	//}
	//else {
	//	AfxMessageBox("디지털 시계 이미 동작 중");
	//}
	CView::OnLButtonDown(nFlags, point);
}


void CMFCStudyView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (!m_strOutText.IsEmpty()) {
		if (AfxMessageBox("문자를 모두 지움?", MB_YESNO | MB_ICONQUESTION) == IDYES) {
			m_strOutText.Empty();
		}
	}
	else {
		AfxMessageBox("문자열 입력");
	}
	Invalidate();
	/* Timer */
	//if (!m_bTimerRun) {
	//	AfxMessageBox("디지털 시계 이미 동작 멈춤");
	//}
	//else {
	//	if (AfxMessageBox("정말로 멈춤?", MB_YESNO | MB_ICONQUESTION) == IDYES) {
	//		KillTimer(0);
	//		m_bTimerRun = FALSE;
	//	}
	//}
	CView::OnRButtonDown(nFlags, point);
}


void CMFCStudyView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	/* Timer */
	//if (m_bTimerRun) {
	//	KillTimer(0);
	//}
}


void CMFCStudyView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int nCharIndex;
	nCharIndex = m_strOutText.GetLength();

	if (nChar == VK_BACK) {
		m_strOutText.Delete(nCharIndex - 1, 1);
	}
	else {
		m_strOutText += (WCHAR)nChar;
	}
	Invalidate();
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMFCStudyView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (nChar) {
	case VK_LEFT:
		m_ptNow.x--;
		break;
	case VK_RIGHT:
		m_ptNow.x++;
		break;
	case VK_UP:
		m_ptNow.y++;
		break;
	case VK_DOWN:
		m_ptNow.y--;
		break;
	case VK_PRIOR:
		m_ptNow.y += 50;
		break;
	case VK_NEXT:
		m_ptNow.y += 50;
		break;
	case VK_HOME:
		m_ptNow = CPoint(0, 0);
		break;
	}
	if (m_ptNow.x < 0)
	{
		m_ptNow.x = 0;
	}
	if (m_ptNow.y < 0)
	{
		m_ptNow.x = 0;
	}
	if (m_ptNow.x < m_ptClientSize.x)
	{
		m_ptNow.x = m_ptClientSize.x;
	}
	if (m_ptNow.x < m_ptClientSize.y)
	{
		m_ptNow.x = m_ptClientSize.y;
	}
	Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMFCStudyView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	m_ptClientSize.x = cx;
	m_ptClientSize.y = cy;

	Invalidate();
}
