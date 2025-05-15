// OnBnClickedButtonAnalyze.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication2.h"
#include "afxdialogex.h"
#include "OnBnClickedButtonAnalyze.h"


// OnBnClickedButtonAnalyze 대화 상자

IMPLEMENT_DYNAMIC(OnBnClickedButtonAnalyze, CDialogEx)

OnBnClickedButtonAnalyze::OnBnClickedButtonAnalyze(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
{

}

OnBnClickedButtonAnalyze::~OnBnClickedButtonAnalyze()
{
}

void OnBnClickedButtonAnalyze::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(OnBnClickedButtonAnalyze, CDialogEx)
END_MESSAGE_MAP()


// OnBnClickedButtonAnalyze 메시지 처리기
