#pragma once
#include "afxdialogex.h"


// ImageDialog 대화 상자

class ImageDialog : public CDialogEx
{
	DECLARE_DYNAMIC(ImageDialog)

public:
	ImageDialog(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~ImageDialog();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IMAGE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual BOOL OnInitDialog();
	
	CStatic m_imageControl; // Image Control 변수
	void LoadImageFromFile(CString imagePath); // 추가

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedPic();
};
