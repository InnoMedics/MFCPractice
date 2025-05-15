#pragma once
#include "afxdialogex.h"


// OnBnClickedButtonAnalyze 대화 상자

class OnBnClickedButtonAnalyze : public CDialogEx
{
	DECLARE_DYNAMIC(OnBnClickedButtonAnalyze)

public:
	OnBnClickedButtonAnalyze(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~OnBnClickedButtonAnalyze();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION2_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
