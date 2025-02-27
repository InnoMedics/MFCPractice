// ImageDialog.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication2.h"
#include "afxdialogex.h"
#include "ImageDialog.h"


// ImageDialog 대화 상자

IMPLEMENT_DYNAMIC(ImageDialog, CDialogEx)

ImageDialog::ImageDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_IMAGE_DIALOG, pParent)
{

}

ImageDialog::~ImageDialog()
{
}

void ImageDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ImageDialog, CDialogEx)
	ON_STN_CLICKED(IDC_PIC, &ImageDialog::OnStnClickedPic)
END_MESSAGE_MAP()


// ImageDialog 메시지 처리기

BOOL ImageDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// BMP 리소스 로드
	HBITMAP hBitmap = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_PUPPY));
	if (hBitmap)
	{
		CStatic* pImageControl = (CStatic*)GetDlgItem(IDC_PIC);
		if (pImageControl)
		{
			pImageControl->SetBitmap(hBitmap);
		}
	}

	return TRUE;
}
void ImageDialog::OnStnClickedPic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
