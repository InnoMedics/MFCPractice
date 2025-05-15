// OnBnClickedButtonSelect.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication2.h"
#include "afxdialogex.h"
#include "OnBnClickedButtonSelect.h"


// OnBnClickedButtonSelect 대화 상자

IMPLEMENT_DYNAMIC(OnBnClickedButtonSelect, CDialogEx)

OnBnClickedButtonSelect::OnBnClickedButtonSelect(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
{

}

OnBnClickedButtonSelect::~OnBnClickedButtonSelect()
{
}

void OnBnClickedButtonSelect::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(OnBnClickedButtonSelect, CDialogEx)
END_MESSAGE_MAP()


// OnBnClickedButtonSelect 메시지 처리기
