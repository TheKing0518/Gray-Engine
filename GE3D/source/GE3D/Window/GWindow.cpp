#include <GE3D/Window/GWindow.h>
#include <Windows.h>
#include <assert.h>

GWindow::GWindow()
{
	WNDCLASSEX wc = {};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpszClassName = L"GE3DWindow";
	wc.lpfnWndProc = DefWindowProc;

	assert(RegisterClassEx(&wc));

	RECT rc = { 0, 0, 1024, 768 };
	AdjustWindowRect(&rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, false);

	m_handle = CreateWindowEx(NULL, L"GE3DWindow", L"Gray Engine Application", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
		CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, NULL, NULL);

	assert(m_handle);

	ShowWindow((HWND)m_handle, SW_SHOW);
	UpdateWindow((HWND)m_handle);

}

GWindow::~GWindow()
{
	DestroyWindow((HWND)m_handle);
}
