// OnBnClickedButtonReset.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication2.h"
#include "afxdialogex.h"
#include "OnBnClickedButtonReset.h"


// OnBnClickedButtonReset 대화 상자

IMPLEMENT_DYNAMIC(OnBnClickedButtonReset, CDialogEx)

OnBnClickedButtonReset::OnBnClickedButtonReset(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
{

}

OnBnClickedButtonReset::~OnBnClickedButtonReset()
{
}

void OnBnClickedButtonReset::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(OnBnClickedButtonReset, CDialogEx)
END_MESSAGE_MAP()


// OnBnClickedButtonReset 메시지 처리기
