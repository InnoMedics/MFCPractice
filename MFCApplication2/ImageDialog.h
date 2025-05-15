#pragma once
#include "afxdialogex.h"
#include <atlimage.h>

class ImageDialog : public CDialogEx
{
	DECLARE_DYNAMIC(ImageDialog)

public:
	ImageDialog(CString imagePath, CWnd* pParent = nullptr);
	virtual ~ImageDialog();

	enum { IDD = IDD_IMAGE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()

private:
	CString m_imagePath;
	CImage m_image;
	CStatic m_picture_control;
	HICON m_hIcon;
};
