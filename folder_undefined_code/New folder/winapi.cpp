#include <windows.h>
const char * ClassName="HoangDodpetrai";
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
   WNDCLASSEX wc; 

wc.cbSize	= sizeof(WNDCLASSEX);
wc.style	= 0;
wc.lpfnWndProc	= WndProc;
wc.cbClsExtra	= 0;
wc.cbWndExtra	= 0;
wc.hInstance	= hInstance;
//wc.hIcon	= LoadIcon(NULL, IDI_APPLICATION);
wc.hCursor	= LoadCursor(NULL, IDC_ARROW);
wc.hbrBackground	= (HBRUSH)(COLOR_WINDOW + 1);
wc.lpszMenuName	= NULL;
wc.lpszClassName	= ClassName;
//wc.hIconSm	= LoadIcon(NULL, IDI_APPLICATION);

if (!RegisterClassEx(&wc))
{
	MessageBox(NULL, "Cannot Register window", "Error",  MB_OK|MB_ICONEXCLAMATION);
	return 0;
}
  HWND hwnd;
hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		ClassName,
		"The title of stdio.vn",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT, 
		240,
		120,
		NULL,
		NULL,
		hInstance,
		NULL
		);
if (hwnd == NULL)
{
	MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
	return 0;
}

ShowWindow(hwnd, nCmdShow);
UpdateWindow(hwnd);



MSG Msg;

while (GetMessage(&Msg, NULL, 0, 0) > 0)
{
	TranslateMessage(&Msg);
	DispatchMessage(&Msg);
}
return Msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		case WM_CLOSE:
			DestroyWindow(hwnd);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}