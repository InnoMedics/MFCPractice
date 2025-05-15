// ImageDialog.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication2.h"
#include "afxdialogex.h"
#include "ImageDialog.h"
#include "MFCApplication2Dlg.h"

IMPLEMENT_DYNAMIC(ImageDialog, CDialogEx)

ImageDialog::ImageDialog(CString imagePath, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_IMAGE_DIALOG, pParent), m_imagePath(imagePath)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

ImageDialog::~ImageDialog()
{
	if (m_image)
		m_image.Destroy();
}

void ImageDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_IMAGE, m_picture_control);  // Picture Control 연결
}

BEGIN_MESSAGE_MAP(ImageDialog, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()

BOOL ImageDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	SetDlgItemText(IDC_STATIC_PATH, m_imagePath);  // 이미지 경로 표시

	// 이미지 로드
	if (m_image)
		m_image.Destroy();

	HRESULT hr = m_image.Load(m_imagePath);
	if (FAILED(hr)) {
		AfxMessageBox(_T("이미지 로드 실패"));
		return TRUE;
	}

	// OnPaint 호출 강제
	Invalidate();

	return TRUE;
}

void ImageDialog::OnPaint()
{
	CPaintDC dc(this);

	if (IsIconic())
	{
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else if (m_image)
	{
		// Picture Control DC 얻기
		CDC* pDC = m_picture_control.GetDC();
		if (pDC)
		{
			CRect rect;
			m_picture_control.GetClientRect(&rect);

			// 원본 이미지 크기
			int imgWidth = m_image.GetWidth();
			int imgHeight = m_image.GetHeight();

			// 컨트롤 크기
			int ctrlWidth = rect.Width();
			int ctrlHeight = rect.Height();

			// 비율 계산
			double imgAspect = (double)imgWidth / imgHeight;
			double ctrlAspect = (double)ctrlWidth / ctrlHeight;

			int drawWidth, drawHeight;

			if (imgAspect > ctrlAspect)
			{
				// 가로 기준 맞춤
				drawWidth = ctrlWidth;
				drawHeight = static_cast<int>(ctrlWidth / imgAspect);
			}
			else
			{
				// 세로 기준 맞춤
				drawHeight = ctrlHeight;
				drawWidth = static_cast<int>(ctrlHeight * imgAspect);
			}

			// 중앙 정렬 좌표
			int x = (ctrlWidth - drawWidth) / 2;
			int y = (ctrlHeight - drawHeight) / 2;

			// 출력
			m_image.StretchBlt(pDC->GetSafeHdc(), x, y, drawWidth, drawHeight, SRCCOPY);

			ReleaseDC(pDC);
		}
	}
}
