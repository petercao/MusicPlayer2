#pragma once

// CTagEditDlg 对话框

class CTagEditDlg : public CDialog
{
	DECLARE_DYNAMIC(CTagEditDlg)

public:
	struct ItemInfo
	{
		wstring file_path;
		SongInfo song_info;
		bool operator==(const ItemInfo& a) const
		{
			return file_path == a.file_path;
		}
	};


	CTagEditDlg(vector<ItemInfo>& file_list, int index, CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTagEditDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAG_EDIT_DIALOG };
#endif

protected:
	vector<ItemInfo>& m_file_list;
	int m_index;

	CComboBox m_genre_combo;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	void ShowInfo();

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedPreviousButton();
	afx_msg void OnBnClickedNextButton();
	afx_msg void OnBnClickedSaveButton();
};
