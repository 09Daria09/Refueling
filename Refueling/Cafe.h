#pragma once
#include "Header.h"

class Cafe
{
public:
	Cafe(void);
	Cafe(LPCTSTR lpStr);
public:
	static BOOL CALLBACK DlgProc(HWND hWnd, UINT mes, WPARAM wp, LPARAM lp);
	static Cafe* ptr;
	BOOL Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
	void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
	void Cls_OnClose(HWND hwnd);
	TCHAR text[200];
	TCHAR text1[200];
	static double sum;
	TCHAR str[100];
	HWND hCheckHotDog, hCheckHamburger, hCheckPotatoFri, hCheckCocaCola,
		hEditPriceHotDog, hEditPriceHamburger, hEditPricePotatoFri, hEditPriceCocaCola,
		hEditCountHotDog, hEditCountHamburger, hEditCountPotatoFri, hEditCountCocaCola, hEditCafePay;
};