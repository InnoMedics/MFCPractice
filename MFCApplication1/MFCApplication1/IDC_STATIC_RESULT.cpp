// IDC_STATIC_RESULT.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "IDC_STATIC_RESULT.h"


// IDC_STATIC_RESULT 대화 상자

IMPLEMENT_DYNAMIC(IDC_STATIC_RESULT, CDialogEx)

IDC_STATIC_RESULT::IDC_STATIC_RESULT(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{

}

IDC_STATIC_RESULT::~IDC_STATIC_RESULT()
{
}

void IDC_STATIC_RESULT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(IDC_STATIC_RESULT, CDialogEx)
END_MESSAGE_MAP()


// IDC_STATIC_RESULT 메시지 처리기
