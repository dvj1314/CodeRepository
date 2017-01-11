// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// (��Fluent UI��)����ʾ�������ο���
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���  
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�  
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ������� 
// http://go.microsoft.com/fwlink/?LinkId=238214��
//
// ��Ȩ����(C) Microsoft Corporation
// ��������Ȩ����

// TestGitPrjView.h : CTestGitPrjView ��Ľӿ�
//

#pragma once


class CTestGitPrjView : public CFormView
{
protected: // �������л�����
	CTestGitPrjView();
	DECLARE_DYNCREATE(CTestGitPrjView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_TESTGITPRJ_FORM };
#endif

// ����
public:
	CTestGitPrjDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CTestGitPrjView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // TestGitPrjView.cpp �еĵ��԰汾
inline CTestGitPrjDoc* CTestGitPrjView::GetDocument() const
   { return reinterpret_cast<CTestGitPrjDoc*>(m_pDocument); }
#endif

