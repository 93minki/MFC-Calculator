
// MFC_CalculatorDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"


// CMFC_CalculatorDlg 대화 상자
class CMFC_CalculatorDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFC_CalculatorDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton m_button1;
	afx_msg void OnClickedButton2();
	CButton m_button2;
	CButton m_button3;
	CButton m_button4;
	CButton m_button5;
	CButton m_button6;
	CButton m_button7;
	CButton m_button8;
	CButton m_button9;
	CButton m_button0;
	CButton m_button_dot;
	CButton m_button_enter;
	CButton m_button_plus;
	CButton m_button_div;
	CButton m_button_mul;
	CButton m_button_sub;
	CButton m_button_delete;
	afx_msg void OnClickedButton18();
	CButton m_button_clear;
	CEdit m_edit_input;
	CEdit m_edit_output;
	afx_msg void OnClickedButton1();
	afx_msg void OnClickedButton10();
	afx_msg void OnClickedButton11();
	afx_msg void OnClickedButton12();
	afx_msg void OnClickedButton13();
	afx_msg void OnClickedButton14();
	afx_msg void OnClickedButton15();
	afx_msg void OnClickedButton16();
	afx_msg void OnClickedButton17();
	afx_msg void OnClickedButton3();
	afx_msg void OnClickedButton4();
	afx_msg void OnClickedButton5();
	afx_msg void OnClickedButton6();
	afx_msg void OnClickedButton7();
	afx_msg void OnClickedButton8();
	afx_msg void OnClickedButton9();
	afx_msg void OnChangeEdit1();
	afx_msg void OnChangeEdit2();
	void UpdateInputEdit(char input);
	CString m_inputstream;
	int m_findindex;
	int m_streamlength;
	int MakePriority(char symbol);
	int m_priority;
	bool CheckFormula(int num);
	int GetStackSize();
	int m_search_N;
	int m_search_S;
//	char TempArray[30];
};
