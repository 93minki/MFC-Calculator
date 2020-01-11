
// MFC_CalculatorDlg.cpp : ���� ����
// 5�� ���� 20.01.11 
// �����ȣ ǥ�� �Լ�ȭ
// ���� ó���� �����ȣ ��� ����
// �Ҽ��� ǥ��� �ٷ� �� ���ڰ� �����ȣ�� ��� 0�� �Բ� . ����

#include "stdafx.h"
#include "MFC_Calculator.h"
#include "MFC_CalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CMFC_CalculatorDlg ��ȭ ����



CMFC_CalculatorDlg::CMFC_CalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC_CALCULATOR_DIALOG, pParent)
	, m_inputstream(_T(""))
	, m_findindex(0)
	, m_streamlength(0)
	, m_priority(0)
	, m_search_N(0)
	, m_search_S(0)
	
	, m_nsp(0)
	, m_ssp(0)
	, m_cleanflag(false)
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
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CMFC_CalculatorDlg �޽��� ó����

BOOL CMFC_CalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	AllocConsole();
	freopen("CONOUT$", "wt", stdout);
	m_nsp = -1;
	m_ssp = -1;
	/*StackNum[MAX_SIZE] = { '\0', };
	StackSymbol[MAX_SIZE] = { '\0', };
	TempArray[MAX_SIZE] = { '\0', };*/
	for (int i = 0; i < MAX_SIZE; i++) {
		StackNum[i] = '\0';
		StackSymbol[i] = '\0';
		TempArray[i] = '\0';
	}
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMFC_CalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CMFC_CalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFC_CalculatorDlg::OnClickedButton18()						// Clear
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ClearEdit();
}

void CMFC_CalculatorDlg::OnClickedButton11()						// .
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// �� ��° .�� �ι� ������ ����  <-  ���� �ʿ� 20.01.09
	char tchar;
	int tint;
	tint = m_inputstream.GetLength() - 1;
	tchar = m_inputstream.GetAt(tint);

	int finddot = m_inputstream.Find('.',m_findindex);

	if (tchar == '.') {
		return;
	}

	if (finddot == -1) {
		if (tchar == '+' || tchar == '-' || tchar == '*' || tchar == ' /') {
			UpdateInputEdit('0');
		}
		UpdateInputEdit('.');
		return;
	}
}


void CMFC_CalculatorDlg::OnClickedButton12()						// Enter
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	//********************************* CString -> Character Type Array **********************************//
	char inputstream[MAX_SIZE];
	size_t CharactersConverted = 0;
	wcstombs_s(&CharactersConverted, inputstream, m_inputstream.GetLength() + 1, m_inputstream, _TRUNCATE);
	printf("Input Stream : %s\n", inputstream);
	//****************************************************************************************************//

	/* ���� ���� */
	int oldpri = 4;
	int pri;

	bool calcFlag = false;
	bool shiftFlag = false;



	for (int i = 0; i < m_inputstream.GetLength(); i++) {
		if (inputstream[i] == '+' || inputstream[i] == '-' || inputstream[i] == '*' || inputstream[i] == '/') {
			if (CheckFormula(i)) {
				return;
			}
			pri = MakePriority(inputstream[i]);
			m_search_S = i;
			for (int tp = 0; m_search_N < m_search_S; m_search_N++, tp++) {
				TempArray[tp] = inputstream[m_search_N];
			}
			m_search_N = m_search_S + 1;
			if (shiftFlag) {
				NumStackPush(atof(TempArray)*-1);
				shiftFlag = false;
			}
			else {
				NumStackPush(atof(TempArray));
			}
			InitTempArray();
			if (calcFlag) {
				Calculation();
				SymStackPush(inputstream[i]);
				calcFlag = false;
			}
			else if (oldpri == 4) {
				SymStackPush(inputstream[i]);
				oldpri = pri;
			}
			else if (oldpri < pri) {
				Calculation();
				SymStackPush(inputstream[i]);
				oldpri = pri;
			}
			else if (oldpri == pri) {
				Calculation();
				SymStackPush(inputstream[i]);
				oldpri = pri;
			}
			else if (oldpri > pri) {
				SymStackPush(inputstream[i]);
				calcFlag = true;
			}

			if (inputstream[i] == '-') {
				StackSymbol[m_ssp] = '+';
				shiftFlag = true;
			}
		}

		if (inputstream[i + 1] == '\0') {
			m_search_S = i + 1;
			for (int tp = 0; m_search_N < m_search_S; m_search_N++, tp++) {
				TempArray[tp] = inputstream[m_search_N];
			}
			if (shiftFlag) {
				NumStackPush(atof(TempArray)*-1);
			}
			else {
				NumStackPush(atof(TempArray));
			}

			for (int x = 0; !IsSymStackEmpty(); x++) {
				Calculation();
			}
			InitTempArray();
			//**************** float --> CString *****************//
			showFloat.Format(_T("%0.2f"), StackNum[0]);
			m_cleanflag = true;
			SetDlgItemText(IDC_EDIT2, showFloat);
			return;
		}
		
	}

}


void CMFC_CalculatorDlg::OnClickedButton13()						// /
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ShowSymbol('/');
}


void CMFC_CalculatorDlg::OnClickedButton14()						// *
{
	ShowSymbol('*');
}


void CMFC_CalculatorDlg::OnClickedButton15()						// -
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ShowSymbol('-');
}


void CMFC_CalculatorDlg::OnClickedButton16()						// +
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ShowSymbol('+');
}


void CMFC_CalculatorDlg::OnClickedButton17()							//C
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_cleanflag) {
		ClearEdit();
		return;
	}
	m_findindex = m_inputstream.GetLength() - 1;
	
	m_inputstream.Delete(m_findindex, 1);

	SetDlgItemText(IDC_EDIT1, m_inputstream);
}

void CMFC_CalculatorDlg::OnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateInputEdit('1');
}

void CMFC_CalculatorDlg::OnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateInputEdit('2');
}

void CMFC_CalculatorDlg::OnClickedButton3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateInputEdit('3');
}

void CMFC_CalculatorDlg::OnClickedButton4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateInputEdit('4');
}

void CMFC_CalculatorDlg::OnClickedButton5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateInputEdit('5');
}

void CMFC_CalculatorDlg::OnClickedButton6()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateInputEdit('6');
}

void CMFC_CalculatorDlg::OnClickedButton7()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateInputEdit('7');
}

void CMFC_CalculatorDlg::OnClickedButton8()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateInputEdit('8');
}

void CMFC_CalculatorDlg::OnClickedButton9()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateInputEdit('9');
}

void CMFC_CalculatorDlg::OnClickedButton10()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateInputEdit('0');
}

void CMFC_CalculatorDlg::OnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMFC_CalculatorDlg::OnChangeEdit2()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
		MessageBox(_T("Wrong Formula"), _T("Check Formula"), MB_ICONWARNING);
		return true;
	}
	return false;
}


int CMFC_CalculatorDlg::GetStackSize()
{
	int StackSize;
	for (int a = 0; a < MAX_SIZE; a++) {
		if (m_inputstream[a] == '\0') {
			StackSize = a;
			return a;
		}
	}
}


void CMFC_CalculatorDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	FreeConsole();
}


bool CMFC_CalculatorDlg::IsNumStackEmpty()
{
	if (m_nsp < 0) {
		return true;
	}
	else {
		return false;
	}
}

bool CMFC_CalculatorDlg::IsSymStackEmpty() {
	if (m_ssp < 0) {
		return true;
	}
	else {
		return false;
	}
}

bool CMFC_CalculatorDlg::IsNumStackFull() {
	if (m_nsp > MAX_SIZE) {
		return true;
	}
	else {
		return false;
	}
}

bool CMFC_CalculatorDlg::IsSymStackFull() {
	if (m_ssp > MAX_SIZE) {
		return true;
	}
	else {
		return false;
	}
}

void CMFC_CalculatorDlg::NumStackPush(float value) {
	if (IsNumStackFull() == true) {
		printf("Num Stack is Full!!!\n");
	}
	else {
		StackNum[++m_nsp] = value;
	}

}

void CMFC_CalculatorDlg::SymStackPush(char value) {
	if (IsSymStackFull() == true) {
		printf("Sym Stack is Full!!!\n");
	}
	else {
		StackSymbol[++m_ssp] = value;
	}
}

float CMFC_CalculatorDlg::NumStackPop() {
	float rtnum;
	if (IsNumStackEmpty() == true) {
		printf("Num Stack is Empty!!!\n");
		return 0;
	}
	else {
		rtnum = StackNum[m_nsp];
		StackNum[m_nsp] = '\0';
		m_nsp--;
		return rtnum;
	}
	
}

char CMFC_CalculatorDlg::SymStackPop() {
	char rtchar;
	if (IsSymStackEmpty() == true) {
		printf("Sym Stack is Empty!!!\n");
		return 0;
	}
	else {
		rtchar = StackSymbol[m_ssp];
		StackSymbol[m_ssp] = '\0';
		m_ssp--;
		return rtchar;
	}

}

void CMFC_CalculatorDlg::InitTempArray()
{
	for (int i = 0; i < sizeof(TempArray); i++) {
		TempArray[i] = '\0';
		if (TempArray[i + 1] == '\0') {
			return;
		}
	}
}


void CMFC_CalculatorDlg::Calculation()
{
	float pop1;
	float pop2;
	char opr;
	float rst;

	pop1 = NumStackPop();
	pop2 = NumStackPop();
	opr = SymStackPop();

	switch (opr) {
	case '+':
		rst = pop2 + pop1;
		NumStackPush(rst);
		break;
	case '-':
		rst = pop2 - pop1;
		NumStackPush(rst);
		break;
	case'*':
		rst = pop2 * pop1;
		NumStackPush(rst);
		break;
	case '/':
		rst = pop2 / pop1;
		NumStackPush(rst);
		break;
	}
}


void CMFC_CalculatorDlg::ClearEdit()
{
	NumStackPop();
	m_inputstream.Empty();
	showFloat.Empty();
	m_search_N = 0;
	m_search_S = 0;
	SetDlgItemText(IDC_EDIT1, _T("0"));
	SetDlgItemText(IDC_EDIT2, _T("0"));
}


void CMFC_CalculatorDlg::ShowSymbol(char symbol)
{
	char tchar;
	if (m_inputstream == "\0") {
		MessageBox(_T("Wrong Formula"), _T("Check Formula"), MB_ICONWARNING);
		return;
	}
	m_streamlength = m_inputstream.GetLength() - 1;
	m_findindex = m_streamlength;
	tchar = m_inputstream.GetAt(m_streamlength);
	if (tchar == '+' || tchar == '-' || tchar == '*' || tchar == '/') {
		m_inputstream.SetAt(m_streamlength, symbol);
		SetDlgItemText(IDC_EDIT1, m_inputstream);
	}
	else {
		UpdateInputEdit(symbol);
	}
}
