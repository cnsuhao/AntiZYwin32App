
// MFCApplication1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "QDeal.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	// ʵ��
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


// CMFCApplication1Dlg �Ի���



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


// CMFCApplication1Dlg ��Ϣ�������

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	ShowWindow(SW_MINIMIZE);

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnEnChangeEdit4()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	/*
	1 ��ȡ��������
	2 ���ݺϷ����ж�
	3 ������ѡ������ò�ѯģ��
	4 ��ѯģ�鷵������
	5 չʾģ�鷵������
	*/

	//char cQName[2048];
	char cNames[2048];
	char cComponents[2048];
	char cToxicology[2048];
	int nReturn = 0;


	UpdateData(true);


	CString QueryText = m_QName;
	
	//����
	QueryText.Trim();


	if (QueryText == L"")
	{
		::MessageBox(NULL,L"���������ѯ��ҩ������",L"�������п�ѧ������ʲô?",MB_OK);
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

	


	//��ѯ�������ݼ���ʾ
	switch (nReturn)
	{
		//δ�ҵ�
	case 0:
	{
		CString csStr = L"���ݿ���û���ҵ��óɷֵ���Ϣ.";//���ýӿ�

		int  nLength = m_Names.SendMessage(WM_GETTEXTLENGTH);
		m_Names.SetSel(nLength, nLength);
		m_Names.ReplaceSel(csStr);


		break;
	}
	//�ҵ���
	case 1:
	{
		{
			//��ʾ����ѯ��ҩ��
			{
				m_lable_of_name = QueryText;

				UpdateData(false);
			}

			//�漰�г�ҩ����
			{
				CString csStr(cNames);
				int  nLength = m_Names.SendMessage(WM_GETTEXTLENGTH);
				m_Names.SetSel(nLength, nLength);
				m_Names.ReplaceSel(csStr);
			}
			//ҩ��ɷ�
			{
				CString csStr(cComponents);
				int  nLength = m_Components.SendMessage(WM_GETTEXTLENGTH);
				m_Components.SetSel(nLength, nLength);
				m_Components.ReplaceSel(csStr);

			}
			//������Ϣ
			{
				CString csStr(cToxicology);
				int  nLength = m_Toxicology.SendMessage(WM_GETTEXTLENGTH);
				m_Toxicology.SetSel(nLength, nLength);
				m_Toxicology.ReplaceSel(csStr);

			}
		}



		break;
	}
	//���ݿ��޷���
	case 2:
	{
		CString csStr = L"���ݿ��޷���,һ������Ϊ���ݿ����ֱ��ı�����ļ�����ʧ,�������ݿ��ļ���������@���п�ѧ�� ��ȡ�汾.";

		int  nLength = m_Names.SendMessage(WM_GETTEXTLENGTH);
		m_Names.SetSel(nLength, nLength);
		m_Names.ReplaceSel(csStr);

		break;
	}

	default:
	{
		CString csStr = L"һ����ֵĴ���,�����򱻴۸�.�����ر������ԭ�汾.@���п�ѧ�� ��ȡ�汾.";

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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	::MessageBox(NULL,L"    �������˵�@���п�ѧ��  ,Ӧ�������������������ª��С����,�������ڰ�����ʱ���ض���Լ��˵��˺�.\r\n\r\n     �ҽ� www.meoncn.cn/Item/3595.aspx   �е�����ת��Ϊһ���Զ�������ݿ�(��ʽ�ڴ����и���),��Ϊ��������������˷���.\r\n\r\n    ��ҽ�Թ��˲����������ϵ��Ⱥ�,Ҳ�������쾫���ϵĶ���.\r\n\r\n    Ϊ�˷������������,�ܽ���ת��Ϊ�ֻ�APP,������������ǿ���Դ���(�ҵĴ��벢������,���Ǻ�����),�й���:http://code.taobao.org/svn/AntiZYwin32App/ 2015��10��16�� 15:34:25",L"����",MB_OK);
}
