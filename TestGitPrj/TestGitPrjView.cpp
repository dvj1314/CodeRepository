// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面 
// (“Fluent UI”)。该示例仅供参考，
// 用以补充《Microsoft 基础类参考》和 
// MFC C++ 库软件随附的相关电子文档。  
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。  
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问 
// http://go.microsoft.com/fwlink/?LinkId=238214。
//
// 版权所有(C) Microsoft Corporation
// 保留所有权利。

// TestGitPrjView.cpp : CTestGitPrjView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CTestGitPrjView 构造/析构

CTestGitPrjView::CTestGitPrjView()
	: CFormView(IDD_TESTGITPRJ_FORM)
{
	// TODO: 在此处添加构造代码

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
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

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


// CTestGitPrjView 诊断

#ifdef _DEBUG
void CTestGitPrjView::AssertValid() const
{
	CFormView::AssertValid();
}

void CTestGitPrjView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CTestGitPrjDoc* CTestGitPrjView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestGitPrjDoc)));
	return (CTestGitPrjDoc*)m_pDocument;
}
#endif //_DEBUG


// CTestGitPrjView 消息处理程序
