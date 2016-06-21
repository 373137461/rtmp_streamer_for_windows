
/**
* \file OwnerDrawButton.h
*
* \brief �Ի水ť��ʵ����
*
* \author
*/

#pragma once
#include <Windows.h>
enum STATE
{
	STATE_UP,
	STATE_DOWN,
	STATE_FOCUS,
	STATE_DISABLE
};
class COBSButton
{
public:
	COBSButton(void);
	~COBSButton(void);
private:
	COBSButton(const COBSButton &OtherOwnerDrawButton);
	COBSButton &operator=(const COBSButton &OtherOwnerDrawButton);
public:
	/**
	* \brief ˢ�¿ؼ�
	*/
	bool InvalidataCtrl();
public:
	/**
	* \brief ������ť
	* \param lpszCaption ������Ϊ��ť����ʾ�ı�
	* \param lpszImage ������Ϊ��ť��λͼ·��
	* \param rect ������Ϊ��ť������
	* \param hParentWnd ������Ϊ��ť�ĸ����ھ��
	* \param nID ������Ϊ��ť�Ŀؼ�ID
	* \param lpszImage ������Ϊ��ť�ؼ�һ��״̬λͼ·��
	*/
	BOOL Create(LPCTSTR lpszCaption, const RECT& rect, HWND hParentWnd, \
		UINT nID, LPCTSTR lpszImage,int nSubPic=4);
	/**
	* \brief �ı�ָ������������
	*/
	BOOL ChangeSubPic(STATE index, LPCTSTR lpszImage);
	/**
	* \brief ���ư�ť
	* \param hDC ������Ϊ��ť�Ļ�����DC���
	*/
	void Draw(HDC hDC);
	void DrawFocusRect(HDC hDC, RECT &rcWnd);
	/**
	* \brief ���ð�ť
	* \param fEnable ������Ϊ���ð�ť�Ƿ����
	*/
	void EnableButton(bool fEnable);

	void OnLbuttonDown(WPARAM wParam, LPARAM lParam);
	void OnLbuttonUp(WPARAM wParam, LPARAM lParam);
	void OnLbuttonDBClick(WPARAM wParam, LPARAM lParam);
	void OnMouseMove(WPARAM wParam, LPARAM lParam);
	void OnMouseLeave(WPARAM wParam, LPARAM lParam);
	
private:
	/**
	* \brief ��ť��Ϣ�ص�����
	*/
	static LRESULT CALLBACK ButtonProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
public:

	WNDPROC     m_OldProc;//!��ť��Ĭ����Ϣ�ص�����
	HWND        m_hWnd;      //!�˰�ť�ľ��
private:
	HDC         m_hdcMemory;         //�ڴ�dc
	HBITMAP     m_hOldBmp;
	HBITMAP     m_hFourStateBitmap; //!��ť����ͨ��״̬λͼ
	BOOL        m_fRoundButton;  //!��ǰ�ؼ����ͣ�TRUEΪ��ť���ͣ�FALSEΪһ�����ʾλͼ�ؼ�
	BOOL        m_fTrackMouse;
	int         m_nButtonState;//!��ť�ĵ�ǰ״̬
	HFONT       m_hFont;//!�ؼ�����
	int         m_nSubPic;
};
