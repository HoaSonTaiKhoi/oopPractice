#include<windows.h>
int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdShow,
	int nCmdShow)
{
	MessageBox(
		NULL,
		"Welcome!",
		"Come to my first app",
		MB_OK | MB_ICONEXCLAMATION
	);
	return 0;
}