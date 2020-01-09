
// MFCStudyView.cpp : CMFCStudyView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	// ǥ�� �μ� ����Դϴ�.
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

// CMFCStudyView ����/�Ҹ�

CMFCStudyView::CMFCStudyView()
	: m_bTimerRun(false)
	, m_strTimer(_T(""))
	, m_strOutText(_T(""))
	, m_ptNow(0)
	, m_ptClientSize(0)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMFCStudyView::~CMFCStudyView()
{
}

BOOL CMFCStudyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMFCStudyView �׸���

void CMFCStudyView::OnDraw(CDC* pDC)
{
	CMFCStudyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	pDC->TextOut(m_ptNow.x, m_ptNow.y, m_strOutText);
	/* Timer */
	//CRect rect;
	//GetClientRect(&rect);
	//pDC->DrawText(m_strTimer, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}


// CMFCStudyView �μ�

BOOL CMFCStudyView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMFCStudyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMFCStudyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMFCStudyView ����

#ifdef _DEBUG
void CMFCStudyView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCStudyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCStudyDoc* CMFCStudyView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCStudyDoc)));
	return (CMFCStudyDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCStudyView �޽��� ó����


int CMFCStudyView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	/* Timer */
	//SetTimer(0, 1000, NULL);
	//m_bTimerRun = TRUE;
	return 0;
}


void CMFCStudyView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CTime timer;
	timer = CTime::GetCurrentTime();
	
	m_strTimer.Format("����� %d�� %d�� %d�� %d�� %d�� %d�� ",
		timer.GetYear(), timer.GetMonth(), timer.GetDay(),
		timer.GetHour(), timer.GetMinute(), timer.GetSecond());
	Invalidate();

	CView::OnTimer(nIDEvent);
}


void CMFCStudyView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_ptNow.x = point.x;
	m_ptNow.y = point.y;
	Invalidate();
	/* Timer */
	//if (!m_bTimerRun) {
	//	if (AfxMessageBox("������ �ð� ����?", MB_YESNO | MB_ICONQUESTION) == IDYES) {
	//		SetTimer(0, 1000, NULL);
	//		m_bTimerRun = TRUE;
	//	}
	//}
	//else {
	//	AfxMessageBox("������ �ð� �̹� ���� ��");
	//}
	CView::OnLButtonDown(nFlags, point);
}


void CMFCStudyView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (!m_strOutText.IsEmpty()) {
		if (AfxMessageBox("���ڸ� ��� ����?", MB_YESNO | MB_ICONQUESTION) == IDYES) {
			m_strOutText.Empty();
		}
	}
	else {
		AfxMessageBox("���ڿ� �Է�");
	}
	Invalidate();
	/* Timer */
	//if (!m_bTimerRun) {
	//	AfxMessageBox("������ �ð� �̹� ���� ����");
	//}
	//else {
	//	if (AfxMessageBox("������ ����?", MB_YESNO | MB_ICONQUESTION) == IDYES) {
	//		KillTimer(0);
	//		m_bTimerRun = FALSE;
	//	}
	//}
	CView::OnRButtonDown(nFlags, point);
}


void CMFCStudyView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	/* Timer */
	//if (m_bTimerRun) {
	//	KillTimer(0);
	//}
}


void CMFCStudyView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	m_ptClientSize.x = cx;
	m_ptClientSize.y = cy;

	Invalidate();
}
