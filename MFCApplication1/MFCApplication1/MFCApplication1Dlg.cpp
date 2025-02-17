
// MFCApplication1Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CMFCDialogAppDlg::CMFCDialogAppDlg(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCDialogAppDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCDialogAppDlg, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON_SELECT_IMAGES, &CMFCDialogAppDlg::OnBnClickedButtonSelectImages)
    ON_BN_CLICKED(IDC_BUTTON_ANALYZE, &CMFCDialogAppDlg::OnBnClickedButtonAnalyze)
END_MESSAGE_MAP()

BOOL CMFCDialogAppDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();
    SetIcon(m_hIcon, TRUE);
    SetIcon(m_hIcon, FALSE);
    return TRUE;
}

// 이미지 선택 버튼 클릭 시
void CMFCDialogAppDlg::OnBnClickedButtonSelectImages()
{
    CFileDialog dlg(TRUE, nullptr, nullptr, OFN_ALLOWMULTISELECT | OFN_FILEMUSTEXIST, _T("Image Files|*.jpg;*.png;*.bmp;*.tif|All Files|*.*||"), this);

    if (dlg.DoModal() == IDOK)
    {
        POSITION pos = dlg.GetStartPosition();
        m_selectedFiles.clear();
        while (pos)
        {
            m_selectedFiles.push_back(dlg.GetNextPathName(pos));
        }
    }
}

// 분석 버튼 클릭 시
void CMFCDialogAppDlg::OnBnClickedButtonAnalyze()
{
    if (m_selectedFiles.empty())
    {
        AfxMessageBox(_T("이미지를 선택하세요."));
        return;
    }

    CString result = RunPythonScript(m_selectedFiles);
    AfxMessageBox(result);
}

// 파이썬 실행 함수
CString CMFCDialogAppDlg::RunPythonScript(const std::vector<CString>& filePaths)
{
    CString command = _T("python analysis.py");
    for (const auto& path : filePaths)
    {
        command += _T(" \"") + path + _T("\"");
    }

    FILE* pipe = _tpopen(command, _T("r"));
    if (!pipe) return _T("파이썬 실행 실패");

    TCHAR buffer[128];
    CString result;
    while (_fgetts(buffer, 128, pipe))  // 파이썬 출력 읽기
    {
        result += buffer;
    }

    _pclose(pipe);
    result.Trim();

    // 디버깅용 로그 출력
    if (result.IsEmpty())
    {
        AfxMessageBox(_T("파이썬에서 응답이 없습니다!"));
    }

    return result;
}


