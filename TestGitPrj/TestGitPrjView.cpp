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

// TestGitPrjView.cpp : CTestGitPrjView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "TestGitPrj.h"
#endif

#include "TestGitPrjDoc.h"
#include "TestGitPrjView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestGitPrjView

IMPLEMENT_DYNCREATE(CTestGitPrjView, CFormView)

BEGIN_MESSAGE_MAP(CTestGitPrjView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTestGitPrjView ����/����

CTestGitPrjView::CTestGitPrjView()
	: CFormView(IDD_TESTGITPRJ_FORM)
{
	// TODO: �ڴ˴���ӹ������

}

CTestGitPrjView::~CTestGitPrjView()
{
}

void CTestGitPrjView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CTestGitPrjView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

void CTestGitPrjView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void CTestGitPrjView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTestGitPrjView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTestGitPrjView ���

#ifdef _DEBUG
void CTestGitPrjView::AssertValid() const
{
	CFormView::AssertValid();
}

void CTestGitPrjView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CTestGitPrjDoc* CTestGitPrjView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestGitPrjDoc)));
	return (CTestGitPrjDoc*)m_pDocument;
}
#endif //_DEBUG


// CTestGitPrjView ��Ϣ�������
