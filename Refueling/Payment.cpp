#include "Payment.h"
#include "Cafe.h"
#include "Refueling.h"


Payment* Payment::ptr = NULL;

double Payment::AllSum = 0;

Payment::Payment(void)
{
	ptr = this;
}

void Payment::Cls_OnClose(HWND hwnd)
{
	EndDialog(hwnd, IDCANCEL);
}

BOOL Payment::Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
	hEditAllPay = GetDlgItem(hwnd, IDC_EDITALLPAY);
	return TRUE;
}


void Payment::Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	TCHAR buffer[200];
	double payFuel = 0, payCafe = 0;
	//double AllSum = 0;
	if (id == IDC_BUTTONFUEL)
	{
		Refueling dlg;
		INT_PTR result = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG2), hwnd, Refueling::DlgProc);
		if (result == IDC_BUTTON2)
		{
			// Переданные от дополнительного диалога данные отображаются на статике
			payFuel = _wtoi(dlg.str);
			AllSum += payFuel + payCafe;
			_stprintf_s(buffer, TEXT(" %.2f"), AllSum);
			SetWindowText(hEditAllPay, buffer);
		}
	}
	else if (id == IDC_BUTTONCAFE)
	{
		Cafe dlg1;
		INT_PTR result1 = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG3), hwnd, Cafe::DlgProc);
		if (result1 == IDC_BUTTONQ2)
		{
            payCafe = _wtoi(dlg1.str) + payFuel;
			AllSum += payFuel + payCafe;
			_stprintf_s(buffer, TEXT(" %.2f"), AllSum);
			SetWindowText(hEditAllPay, buffer);
		}
	}
	if (id == IDC_BUTTON3)
	{
		EndDialog(hwnd, IDC_BUTTON3);
	}

}

BOOL CALLBACK Payment::DlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		HANDLE_MSG(hwnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hwnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hwnd, WM_COMMAND, ptr->Cls_OnCommand);
	}
	return FALSE;
}
