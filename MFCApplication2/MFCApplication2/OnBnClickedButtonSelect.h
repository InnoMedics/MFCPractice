#pragma once
#include "afxdialogex.h"


// OnBnClickedButtonSelect 대화 상자

class OnBnClickedButtonSelect : public CDialogEx
{
	DECLARE_DYNAMIC(OnBnClickedButtonSelect)

public:
	OnBnClickedButtonSelect(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~OnBnClickedButtonSelect();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION2_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
