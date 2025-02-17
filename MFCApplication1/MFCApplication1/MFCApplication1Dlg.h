
#pragma once
#include <vector>
#include <string>

class CMFCDialogAppDlg : public CDialogEx
{
public:
    CMFCDialogAppDlg(CWnd* pParent = nullptr);

#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_MFCDIALOGAPP_DIALOG };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);

protected:
    HICON m_hIcon;

    virtual BOOL OnInitDialog();
    afx_msg void OnBnClickedButtonSelectImages();
    afx_msg void OnBnClickedButtonAnalyze();
    DECLARE_MESSAGE_MAP()

private:
    std::vector<CString> m_selectedFiles;
    CString RunPythonScript(const std::vector<CString>& filePaths);
};
