#include "Refueling.h"
#include <stdlib.h>
#include <string>

Refueling* Refueling::ptr = NULL;

Refueling::Refueling(void)
{
	ptr = this;
}

Refueling::Refueling(LPCTSTR lpStr)
{
	ptr = this;
}

void Refueling::Cls_OnClose(HWND hwnd)
{
	EndDialog(hwnd, IDC_BUTTON2);
}

BOOL Refueling::Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
	hCombo = GetDlgItem(hwnd, IDC_COMBO2);
	SendMessage(hCombo, CB_ADDSTRING, 0, LPARAM(TEXT("A-76")));
	SendMessage(hCombo, CB_ADDSTRING, 0, LPARAM(TEXT("A-95")));
	SendMessage(hCombo, CB_ADDSTRING, 0, LPARAM(TEXT("A-92")));
	hEditPrice = GetDlgItem(hwnd, IDC_EDITPRICE);

	hRadioButCount = GetDlgItem(hwnd, IDC_RADIO1);
	hRadioButSum = GetDlgItem(hwnd, IDC_RADIO2);

	hEditCount = GetDlgItem(hwnd, IDC_EDIT2);
	hEditSum = GetDlgItem(hwnd, IDC_EDIT3);

	hEditRefPay = GetDlgItem(hwnd, IDC_EDIT4);

	EnableWindow(hEditCount, FALSE);
	EnableWindow(hEditSum, FALSE);
	return TRUE;
}

void Refueling::Choice_of_fuel(float price)
{
	_stprintf_s(text, TEXT(" %.2f"), price);
	/*std::wstring str = std::to_wstring(price);//   std::to_wstring(price).c_str()*/
	int PriceFuel = SetWindowText(hEditPrice, text);
}

void Refueling::Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	float price;
	LRESULT res;
	HWND hParent = GetParent(GetDlgItem(hwnd, IDC_EDITALLPAY));
	if (id == IDC_BUTTON1)
	{
		int indexCombo = SendMessage(hCombo, CB_GETCURSEL, 0, 0);
		if (indexCombo == 0)
		{
			price = 51.59;
			Choice_of_fuel(price);
		}
		if (indexCombo == 1)
		{
			price = 48.90;
			Choice_of_fuel(price);
		}
		if (indexCombo == 2)
		{
			price = 44.90;
			Choice_of_fuel(price);
		}

		res = SendDlgItemMessage(hwnd, IDC_RADIO1, BM_GETCHECK, 0, 0);
		if (res == BST_CHECKED)
		{
			GetWindowText(hEditCount, str, 20);

			double num = _wtof(str) * price;

			_stprintf_s(str, TEXT("%.2f"), num);
			SendMessage(hEditRefPay, WM_SETTEXT, 0, LPARAM(str));

			SetWindowText(hParent, str);
		}
		res = SendDlgItemMessage(hwnd, IDC_RADIO2, BM_GETCHECK, 0, 0);
		if (res == BST_CHECKED)
		{
			GetWindowText(hEditSum, str, 20);
			double num = _wtoi(str);

			GetWindowText(hEditPrice, text, 20);
			double pice = _wtoi(text);
		
			double result = num / price;
			_stprintf_s(str, TEXT("%.3f"), result);
			SendMessage(hEditCount, WM_SETTEXT, 0, LPARAM(str));

			_stprintf_s(str, TEXT("%.2f"), num);
			SendMessage(hEditRefPay, WM_SETTEXT, 0, LPARAM(str));

			SetWindowText(hParent, str);
		}
	}

	res = SendDlgItemMessage(hwnd, IDC_RADIO1, BM_GETCHECK, 0, 0);
	if (res == BST_CHECKED)
	{
		EnableWindow(hEditSum, FALSE);
		EnableWindow(hEditCount, TRUE);
	}
	res = SendDlgItemMessage(hwnd, IDC_RADIO2, BM_GETCHECK, 0, 0);
	if (res == BST_CHECKED)
	{
		EnableWindow(hEditCount, FALSE);
		EnableWindow(hEditSum, TRUE);
	}
	if (id == IDC_BUTTON2)
	{
		EndDialog(hwnd, IDC_BUTTON2);
	}
}

BOOL CALLBACK Refueling::DlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		HANDLE_MSG(hwnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hwnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hwnd, WM_COMMAND, ptr->Cls_OnCommand);
	}
	return FALSE;
}
