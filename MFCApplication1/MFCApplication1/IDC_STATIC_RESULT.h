#pragma once
#include "afxdialogex.h"


// IDC_STATIC_RESULT 대화 상자

class IDC_STATIC_RESULT : public CDialogEx
{
	DECLARE_DYNAMIC(IDC_STATIC_RESULT)

public:
	IDC_STATIC_RESULT(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~IDC_STATIC_RESULT();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
