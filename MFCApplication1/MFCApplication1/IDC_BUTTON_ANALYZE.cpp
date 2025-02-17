// IDC_BUTTON_ANALYZE.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "IDC_BUTTON_ANALYZE.h"


// IDC_BUTTON_ANALYZE 대화 상자

IMPLEMENT_DYNAMIC(IDC_BUTTON_ANALYZE, CDialogEx)

IDC_BUTTON_ANALYZE::IDC_BUTTON_ANALYZE(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{

}

IDC_BUTTON_ANALYZE::~IDC_BUTTON_ANALYZE()
{
}

void IDC_BUTTON_ANALYZE::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(IDC_BUTTON_ANALYZE, CDialogEx)
END_MESSAGE_MAP()


// IDC_BUTTON_ANALYZE 메시지 처리기
