
// MFCApplication1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "QDeal.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication1Dlg::IDD, pParent)
	, m_QName(_T(""))
	, m_lable_of_name(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, m_Names);
	DDX_Control(pDX, IDC_EDIT4, m_Components);
	DDX_Control(pDX, IDC_EDIT3, m_Toxicology);
	DDX_Text(pDX, IDC_EDIT1, m_QName);
	DDX_Text(pDX, IDC_STATIC4, m_lable_of_name);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT4, &CMFCApplication1Dlg::OnEnChangeEdit4)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_MINIMIZE);

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码

	/*
	1 获取输入内容
	2 内容合法性判断
	3 按照所选规则调用查询模块
	4 查询模块返回内容
	5 展示模块返回内容
	*/

	//char cQName[2048];
	char cNames[2048];
	char cComponents[2048];
	char cToxicology[2048];
	int nReturn = 0;


	UpdateData(true);


	CString QueryText = m_QName;
	
	//过滤
	QueryText.Trim();


	if (QueryText == L"")
	{
		::MessageBox(NULL,L"请输入待查询的药物名称",L"在你心中科学道义是什么?",MB_OK);
		return;
	}
	//CString to char*
	{
		int iLen = WideCharToMultiByte(CP_ACP, 0, QueryText, -1, NULL, 0, NULL, NULL);
		char *ptxtTemp = new char[iLen + 1];
		WideCharToMultiByte(CP_ACP, 0, QueryText, -1, ptxtTemp, iLen, NULL, NULL);


		nReturn = QueryInfromation(ptxtTemp, cNames, cComponents, cToxicology);



		delete[] ptxtTemp;

	}
	m_QName="";
	m_lable_of_name = "";

	UpdateData(false);

	m_Names.SetSel(0, -1);
	m_Names.Clear();

	m_Components.SetSel(0, -1);
	m_Components.Clear();

	m_Toxicology.SetSel(0, -1);
	m_Toxicology.Clear();

	


	//查询返回内容及显示
	switch (nReturn)
	{
		//未找到
	case 0:
	{
		CString csStr = L"数据库中没有找到该成分的信息.";//调用接口

		int  nLength = m_Names.SendMessage(WM_GETTEXTLENGTH);
		m_Names.SetSel(nLength, nLength);
		m_Names.ReplaceSel(csStr);


		break;
	}
	//找到了
	case 1:
	{
		{
			//显示被查询的药物
			{
				m_lable_of_name = QueryText;

				UpdateData(false);
			}

			//涉及中成药名称
			{
				CString csStr(cNames);
				int  nLength = m_Names.SendMessage(WM_GETTEXTLENGTH);
				m_Names.SetSel(nLength, nLength);
				m_Names.ReplaceSel(csStr);
			}
			//药物成分
			{
				CString csStr(cComponents);
				int  nLength = m_Components.SendMessage(WM_GETTEXTLENGTH);
				m_Components.SetSel(nLength, nLength);
				m_Components.ReplaceSel(csStr);

			}
			//毒理信息
			{
				CString csStr(cToxicology);
				int  nLength = m_Toxicology.SendMessage(WM_GETTEXTLENGTH);
				m_Toxicology.SetSel(nLength, nLength);
				m_Toxicology.ReplaceSel(csStr);

			}
		}



		break;
	}
	//数据库无法打开
	case 2:
	{
		CString csStr = L"数据库无法打开,一般是因为数据库名字被改变或者文件本身丢失,或者数据库文件被锁定等@冰刃科学家 获取版本.";

		int  nLength = m_Names.SendMessage(WM_GETTEXTLENGTH);
		m_Names.SetSel(nLength, nLength);
		m_Names.ReplaceSel(csStr);

		break;
	}

	default:
	{
		CString csStr = L"一个奇怪的错误,本程序被篡改.请下载本程序的原版本.@冰刃科学家 获取版本.";

		int  nLength = m_Names.SendMessage(WM_GETTEXTLENGTH);
		m_Names.SetSel(nLength, nLength);
		m_Names.ReplaceSel(csStr);

		break;
	}
	break;
	}

	return;
	//4

	//5





}







void CMFCApplication1Dlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	::MessageBox(NULL,L"    我是渣浪的@冰刃科学家  ,应友人需求制作了这个简陋的小程序,方便大家在案边随时拦截毒物对家人的伤害.\r\n\r\n     我将 www.meoncn.cn/Item/3595.aspx   中的内容转换为一个自定义的数据库(格式在代码中给出),这为程序的升级埋下了伏笔.\r\n\r\n    旧医对国人不仅是肉体上的迫害,也是在制造精神上的毒瘤.\r\n\r\n    为了方便有意的友人,能将其转换为手机APP,所以这个程序是开放源码的(我的代码并不优美,但是很清晰),托管在:http://code.taobao.org/svn/AntiZYwin32App/ 2015年10月16日 15:34:25",L"关于",MB_OK);
}
