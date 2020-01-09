
// MFC_CalculatorDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "MFC_Calculator.h"
#include "MFC_CalculatorDlg.h"
#include "afxdialogex.h"
#include <stack>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC_CalculatorDlg 대화 상자



CMFC_CalculatorDlg::CMFC_CalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC_CALCULATOR_DIALOG, pParent)
	, m_inputstream(_T(""))
	, m_findindex(0)
	, m_streamlength(0)
	, m_priority(0)
	, m_search_N(0)
	, m_search_S(0)
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_CalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_button1);
	DDX_Control(pDX, IDC_BUTTON2, m_button2);
	DDX_Control(pDX, IDC_BUTTON3, m_button3);
	DDX_Control(pDX, IDC_BUTTON4, m_button4);
	DDX_Control(pDX, IDC_BUTTON5, m_button5);
	DDX_Control(pDX, IDC_BUTTON6, m_button6);
	DDX_Control(pDX, IDC_BUTTON7, m_button7);
	DDX_Control(pDX, IDC_BUTTON8, m_button8);
	DDX_Control(pDX, IDC_BUTTON9, m_button9);
	DDX_Control(pDX, IDC_BUTTON10, m_button0);
	DDX_Control(pDX, IDC_BUTTON11, m_button_dot);
	DDX_Control(pDX, IDC_BUTTON12, m_button_enter);
	DDX_Control(pDX, IDC_BUTTON16, m_button_plus);
	DDX_Control(pDX, IDC_BUTTON13, m_button_div);
	DDX_Control(pDX, IDC_BUTTON14, m_button_mul);
	DDX_Control(pDX, IDC_BUTTON15, m_button_sub);
	DDX_Control(pDX, IDC_BUTTON17, m_button_delete);
	DDX_Control(pDX, IDC_BUTTON18, m_button_clear);
	DDX_Control(pDX, IDC_EDIT1, m_edit_input);
	DDX_Control(pDX, IDC_EDIT2, m_edit_output);
}

BEGIN_MESSAGE_MAP(CMFC_CalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC_CalculatorDlg::OnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON18, &CMFC_CalculatorDlg::OnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_CalculatorDlg::OnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFC_CalculatorDlg::OnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFC_CalculatorDlg::OnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFC_CalculatorDlg::OnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CMFC_CalculatorDlg::OnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CMFC_CalculatorDlg::OnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CMFC_CalculatorDlg::OnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CMFC_CalculatorDlg::OnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CMFC_CalculatorDlg::OnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC_CalculatorDlg::OnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFC_CalculatorDlg::OnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFC_CalculatorDlg::OnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFC_CalculatorDlg::OnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFC_CalculatorDlg::OnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFC_CalculatorDlg::OnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFC_CalculatorDlg::OnClickedButton9)
	ON_EN_CHANGE(IDC_EDIT1, &CMFC_CalculatorDlg::OnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CMFC_CalculatorDlg::OnChangeEdit2)
END_MESSAGE_MAP()


// CMFC_CalculatorDlg 메시지 처리기

BOOL CMFC_CalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFC_CalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFC_CalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFC_CalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFC_CalculatorDlg::OnClickedButton18()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CMFC_CalculatorDlg::OnClickedButton11()						// .
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 두 번째 .은 두번 눌러야 나옴  <-  수정 필요 20.01.09
	char tchar;
	int tint;
	tint = m_inputstream.GetLength() - 1;
	tchar = m_inputstream.GetAt(tint);

	int finddot = m_inputstream.Find('.',m_findindex);

	if (tchar == '.') {
		return;
	}

	if (finddot == -1) {
		UpdateInputEdit('.');
		return;
	}
}


void CMFC_CalculatorDlg::OnClickedButton12()						// Enter
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//int StackSize = GetStackSize();
	//int oldpr = 4;
	//int pr;
	//int pop1;
	//int pop2;
	//bool calcFlag = false;
	//bool shiftFlag = false;
	//int rst = 0;
	//char opr;

	char* st = LPSTR(LPCTSTR(m_inputstream));						// CString inputstream 을 Char형으로 Type Casting.
	for (int i = 0; i < 30; i++) {
		if (st[i] == '+' || st[i] == '-' || st[i] == '*' || st[i] == '/') {
			if (CheckFormula(i))
				return;

			pr = MakePriority(st[i]);
			m_search_S = i;
			for (int tp = 0; m_search_N < m_search_S; tp++,m_search_N++) {
				TempArray[tp] = m_inputstream[m_search_N];
			}
			m_search_N = m_search_S + 1;
			
				
		}
	}
}


void CMFC_CalculatorDlg::OnClickedButton13()						// /
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	char tchar;
	m_streamlength = m_inputstream.GetLength() - 1;					// 1 개 함수로 가능?
	m_findindex = m_streamlength;
	tchar = m_inputstream.GetAt(m_streamlength);
	if (tchar == '+' || tchar == '-' || tchar == '*' || tchar == '/') {
		m_inputstream.SetAt(m_streamlength, '/');
		SetDlgItemText(IDC_EDIT1, m_inputstream);
	}
	else {
		UpdateInputEdit('/');
	}
}


void CMFC_CalculatorDlg::OnClickedButton14()						// *
{
	char tchar;
	m_streamlength = m_inputstream.GetLength() - 1;
	m_findindex = m_streamlength;
	tchar = m_inputstream.GetAt(m_streamlength);
	if (tchar == '+' || tchar == '-' || tchar == '*' || tchar == '/') {
		m_inputstream.SetAt(m_streamlength, '*');
		SetDlgItemText(IDC_EDIT1, m_inputstream);
	}
	else {
		UpdateInputEdit('*');
	}
}


void CMFC_CalculatorDlg::OnClickedButton15()						// -
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	char tchar;
	m_streamlength = m_inputstream.GetLength() - 1;
	m_findindex = m_streamlength;
	tchar = m_inputstream.GetAt(m_streamlength);
	if (tchar == '+' || tchar == '-' || tchar == '*' || tchar == '/') {
		m_inputstream.SetAt(m_streamlength, '-');
		SetDlgItemText(IDC_EDIT1, m_inputstream);
	}
	else {
		UpdateInputEdit('-');
	}
}


void CMFC_CalculatorDlg::OnClickedButton16()						// +
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	char tchar;
	m_streamlength = m_inputstream.GetLength() - 1;
	m_findindex = m_streamlength;
	tchar = m_inputstream.GetAt(m_streamlength);
	if (tchar == '+' || tchar == '-' || tchar == '*' || tchar == '/') {
		m_inputstream.SetAt(m_streamlength, '+');
		SetDlgItemText(IDC_EDIT1, m_inputstream);
	}
	else {
		UpdateInputEdit('+');
	}
}


void CMFC_CalculatorDlg::OnClickedButton17()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CMFC_CalculatorDlg::OnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateInputEdit('1');
}

void CMFC_CalculatorDlg::OnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateInputEdit('2');
}

void CMFC_CalculatorDlg::OnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateInputEdit('3');
}

void CMFC_CalculatorDlg::OnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateInputEdit('4');
}

void CMFC_CalculatorDlg::OnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateInputEdit('5');
}

void CMFC_CalculatorDlg::OnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateInputEdit('6');
}

void CMFC_CalculatorDlg::OnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateInputEdit('7');
}

void CMFC_CalculatorDlg::OnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateInputEdit('8');
}

void CMFC_CalculatorDlg::OnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateInputEdit('9');
}

void CMFC_CalculatorDlg::OnClickedButton10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateInputEdit('0');
}

void CMFC_CalculatorDlg::OnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFC_CalculatorDlg::OnChangeEdit2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFC_CalculatorDlg::UpdateInputEdit(char input)
{
	m_inputstream += input;
	SetDlgItemText(IDC_EDIT1, m_inputstream);
}


int CMFC_CalculatorDlg::MakePriority(char symbol)
{
	switch (symbol) {
	case '+':
		m_priority = 2;
		break;
	case '-':
		m_priority = 2;
		break;
	case '*':
		m_priority = 1;
		break;
	case '/':
		m_priority = 1;
		break;
	case '(':
		m_priority = 0;
		break;
	case ')':
		m_priority = 0;
		break;
	}
	return m_priority;
}


bool CMFC_CalculatorDlg::CheckFormula(int num)
{
	if (m_inputstream[num + 1] == '\0') {
		MessageBox(_T("Wrong"), _T("Wrong Formula"), MB_ICONWARNING);
		return true;
	}
	return false;
}


int CMFC_CalculatorDlg::GetStackSize()
{
	int StackSize;
	for (int a = 0; a < 30; a++) {
		if (m_inputstream[a] == '\0') {
			StackSize = a;
			return a;
		}
	}
}
