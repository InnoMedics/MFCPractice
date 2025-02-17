// IDC_BUTTON_SELECT_IMAGES.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "IDC_BUTTON_SELECT_IMAGES.h"


// IDC_BUTTON_SELECT_IMAGES 대화 상자

IMPLEMENT_DYNAMIC(IDC_BUTTON_SELECT_IMAGES, CDialogEx)

IDC_BUTTON_SELECT_IMAGES::IDC_BUTTON_SELECT_IMAGES(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{

}

IDC_BUTTON_SELECT_IMAGES::~IDC_BUTTON_SELECT_IMAGES()
{
}

void IDC_BUTTON_SELECT_IMAGES::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(IDC_BUTTON_SELECT_IMAGES, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &IDC_BUTTON_SELECT_IMAGES::OnBnClickedButton2)
END_MESSAGE_MAP()


// IDC_BUTTON_SELECT_IMAGES 메시지 처리기

void IDC_BUTTON_SELECT_IMAGES::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
