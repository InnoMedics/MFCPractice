﻿#pragma once
#include "afxdialogex.h"


// IDC_BUTTON_ANALYZE 대화 상자

class IDC_BUTTON_ANALYZE : public CDialogEx
{
	DECLARE_DYNAMIC(IDC_BUTTON_ANALYZE)

public:
	IDC_BUTTON_ANALYZE(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~IDC_BUTTON_ANALYZE();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
