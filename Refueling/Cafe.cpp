#include "Cafe.h"

Cafe* Cafe::ptr = NULL;
//double Cafe::sum = 0;
Cafe::Cafe(void)
{
	ptr = this;
}

Cafe::Cafe(LPCTSTR lpStr)
{
	ptr = this;
	//_tcscpy(text, lpStr);
}

void Cafe::Cls_OnClose(HWND hwnd)
{
	EndDialog(hwnd, IDC_BUTTONQ2);
}

BOOL Cafe::Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
	hCheckHotDog = GetDlgItem(hwnd, IDC_CHECK1);
	hCheckHamburger = GetDlgItem(hwnd, IDC_CHECK2);
	hCheckPotatoFri = GetDlgItem(hwnd, IDC_CHECK4);
	hCheckCocaCola = GetDlgItem(hwnd, IDC_CHECK3);

	hEditPriceHotDog = GetDlgItem(hwnd, IDC_EDIT);
	hEditPriceHamburger = GetDlgItem(hwnd, IDC_EDIT6);
	hEditPricePotatoFri = GetDlgItem(hwnd, IDC_EDIT5);
	hEditPriceCocaCola = GetDlgItem(hwnd, IDC_EDIT7);
	SetWindowText(hEditPriceHotDog, TEXT("55"));
	SetWindowText(hEditPriceHamburger, TEXT("68"));
	SetWindowText(hEditPricePotatoFri, TEXT("40"));
	SetWindowText(hEditPriceCocaCola, TEXT("35"));

	hEditCountHotDog = GetDlgItem(hwnd, IDC_EDIT11);
	hEditCountHamburger = GetDlgItem(hwnd, IDC_EDIT8);
	hEditCountPotatoFri = GetDlgItem(hwnd, IDC_EDIT10);
	hEditCountCocaCola = GetDlgItem(hwnd, IDC_EDIT9);

	EnableWindow(hEditCountCocaCola, FALSE);
	EnableWindow(hEditCountPotatoFri, FALSE);
	EnableWindow(hEditCountHamburger, FALSE);
	EnableWindow(hEditCountHotDog, FALSE);

	hEditCafePay = GetDlgItem(hwnd, IDC_EDIT12);

	return TRUE;
}


void Cafe::Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	BOOL Cola{}, HotDog{}, Hamburger{}, Potato{};
	LRESULT res;
	double sum = 0;
	HWND hParent = GetParent(GetDlgItem(hwnd, IDC_EDITALLPAY));
	res = SendDlgItemMessage(hwnd, IDC_CHECK1, BM_GETCHECK, 0, 0);
	if (res == BST_CHECKED)
	{
		HotDog = EnableWindow(hEditCountHotDog, TRUE);
	}
	else
	{
		EnableWindow(hEditCountHotDog, FALSE);
	}
	res = SendDlgItemMessage(hwnd, IDC_CHECK2, BM_GETCHECK, 0, 0);
	if (res == BST_CHECKED)
	{
		Hamburger = EnableWindow(hEditCountHamburger, TRUE);
	}
	else
	{
		EnableWindow(hEditCountHamburger, FALSE);
	}
	res = SendDlgItemMessage(hwnd, IDC_CHECK4, BM_GETCHECK, 0, 0);
	if (res == BST_CHECKED)
	{
		Potato = EnableWindow(hEditCountPotatoFri, TRUE);
	}
	else
	{
		EnableWindow(hEditCountPotatoFri, FALSE);
	}
	res = SendDlgItemMessage(hwnd, IDC_CHECK3, BM_GETCHECK, 0, 0);
	if (res == BST_CHECKED)
	{
		
		Cola = EnableWindow(hEditCountCocaCola, TRUE);
	}
	else
	{
		EnableWindow(hEditCountCocaCola, FALSE);
	}

	if (id == IDC_BUTTONQ)
	{
		if (HotDog == 0)
		{
			GetWindowText(hEditCountHotDog, text1, 20);
			GetWindowText(hEditPriceHotDog, text, 20);
			sum += _wtoi(text1)*_wtoi(text);
		}
		if (Hamburger == 0)
		{
			GetWindowText(hEditCountHamburger, text1, 20);
			GetWindowText(hEditPriceHamburger, text, 20);
			sum += _wtoi(text1) * _wtoi(text);
		}
		if (Potato == 0)
		{
			GetWindowText(hEditCountPotatoFri, text1, 20);
			GetWindowText(hEditPricePotatoFri, text, 20);
			sum += _wtoi(text1) * _wtoi(text);
		}
		if (Cola == 0)
		{
			GetWindowText(hEditCountCocaCola, text1, 20);
			GetWindowText(hEditPriceCocaCola, text, 20);
			sum += _wtoi(text1) * _wtoi(text);
		}
		_stprintf_s(str, TEXT("%.2f"), sum);
		SendMessage(hEditCafePay, WM_SETTEXT, 0, LPARAM(str));

		SetWindowText(hParent, str);
    }
	if (id == IDC_BUTTONQ2)
	{
		EndDialog(hwnd, IDC_BUTTONQ2);
	}
}

BOOL CALLBACK Cafe::DlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		HANDLE_MSG(hwnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hwnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hwnd, WM_COMMAND, ptr->Cls_OnCommand);
	}
	return FALSE;
}
