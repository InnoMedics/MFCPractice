
// MFCApplication2Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"
#include "ImageDialog.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

// Python 실행 함수
std::string runPythonScript(const std::vector<std::string>& imagePaths) {
    std::string command = "python E:\\VSCode\\MFCApplication2\\analyze.py";

    for (const auto& path : imagePaths) {
        command += " \"" + path + "\"";
    }

    FILE* pipe = _popen(command.c_str(), "r");
    if (!pipe) return "Error";

    char buffer[128];
    std::string result;
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
    }
    _pclose(pipe);

    return result;
}

// 파일 경로 저장 변수
CString selectedFilePath;

// 파일 선택 버튼
void CMFCApplication2Dlg::OnBnClickedButtonSelect()
{
    CFileDialog dlg(TRUE, _T("jpg"), NULL,
        OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_ALLOWMULTISELECT,
        _T("Image Files (*.jpg;*.png;*.bmp;*.jpeg)|*.jpg;*.png;*.bmp;*.jpeg|All Files (*.*)|*.*||"));

    dlg.m_ofn.nMaxFile = 1024; // 다중 선택을 위한 버퍼 크기 증가
    TCHAR szFile[1024] = { 0 };
    dlg.m_ofn.lpstrFile = szFile;

    if (dlg.DoModal() == IDOK) {
        selectedFilePaths.RemoveAll(); // 기존 경로 초기화

        POSITION pos = dlg.GetStartPosition();


        while (pos) {
            CString filePath = dlg.GetNextPathName(pos);
            selectedFilePaths.Add(filePath);
        }

        // 선택한 파일 경로를 UI에 표시 (한 줄씩)
        CString paths;
        for (int i = 0; i < selectedFilePaths.GetSize(); i++) {
            paths += selectedFilePaths[i] + _T("\r\n");
        }

        SetDlgItemText(IDC_STATIC_PATH, paths);
    }
}

// 분석 버튼
void CMFCApplication2Dlg::OnBnClickedButtonAnalyze()
{
    if (selectedFilePaths.GetSize() == 0) {
        MessageBox(_T("먼저 이미지를 선택하세요."), _T("오류"), MB_OK | MB_ICONERROR);
        return;
    }

    std::vector<std::string> imagePaths;
    for (int i = 0; i < selectedFilePaths.GetSize(); i++) {
        imagePaths.emplace_back(CT2A(selectedFilePaths[i])); // CString → std::string 변환
    }

    std::string result = runPythonScript(imagePaths);

    // 분석 결과 출력 (객체 개수)
    CString resultText;
    resultText.Format(_T("객체 개수: %s"), CString(result.c_str()));
    SetDlgItemText(IDC_STATIC_RESULT, resultText);

    // 분석 결과 출력 (이미지)
    ImageDialog imagedlg;
    imagedlg.DoModal();
}

// 초기화 버튼
void CMFCApplication2Dlg::OnBnClickedButtonReset()
{
    selectedFilePath = _T("");
    SetDlgItemText(IDC_STATIC_PATH, _T("파일을 선택하세요."));
    SetDlgItemText(IDC_STATIC_RESULT, _T("분석 결과 대기 중..."));
}

CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

BOOL CMFCApplication2Dlg::OnInitDialog()
{
    CDialogEx::OnInitDialog(); // 부모 클래스의 OnInitDialog 호출

    // 다이얼로그 초기화 작업 (예: 아이콘 설정)
    SetIcon(m_hIcon, TRUE);  // 큰 아이콘
    SetIcon(m_hIcon, FALSE); // 작은 아이콘

    // 여기서 초기화 작업 추가

    return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE, 설정하면 FALSE
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON_SELECT, &CMFCApplication2Dlg::OnBnClickedButtonSelect)
    ON_BN_CLICKED(IDC_BUTTON_ANALYZE, &CMFCApplication2Dlg::OnBnClickedButtonAnalyze)
    ON_BN_CLICKED(IDC_BUTTON_RESET, &CMFCApplication2Dlg::OnBnClickedButtonReset)
END_MESSAGE_MAP()