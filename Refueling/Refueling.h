#pragma once
#include "Header.h"

class Refueling
{
public:
	Refueling(void);
	Refueling(LPCTSTR lpStr);
public:
	static BOOL CALLBACK DlgProc(HWND hWnd, UINT mes, WPARAM wp, LPARAM lp);
	static Refueling* ptr;
	BOOL Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
	void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
	void Cls_OnClose(HWND hwnd);
	void Choice_of_fuel(float);
	TCHAR text[200];
	TCHAR str[100];
	HWND hCombo, hEditPrice, hRadioButCount, hRadioButSum, hEditCount, hEditSum, hEditRefPay;
};