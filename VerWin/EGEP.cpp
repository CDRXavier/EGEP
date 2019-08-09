#include <windows.h>
#include <wingdi.h>
//for the project to work
#include "stdafx.h"

//{{NO_DEPENDENCIES}}
// Microsoft Visual C++ generated include file.
// Used by WindowsProject2.rc

#define IDS_APP_TITLE			103

#define IDR_MAINFRAME			128
#define IDD_EGEP_DIALOG	102
#define IDD_ABOUTBOX			103
#define IDM_ABOUT				104
#define IDM_EXIT				105
#define IDI_EGEP				107
#define IDI_SMALL				108
#define IDC_EGEP			109
#define IDC_MYICON				2
#ifndef IDC_STATIC
#define IDC_STATIC				-1
#endif
// Next default values for new objects
//
#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS

#define _APS_NO_MFC					130
#define _APS_NEXT_RESOURCE_VALUE	129
#define _APS_NEXT_COMMAND_VALUE		32771
#define _APS_NEXT_CONTROL_VALUE		1000
#define _APS_NEXT_SYMED_VALUE		110
#endif
#endif


constexpr int winHeight = 200;
constexpr int winWidth = 200;

constexpr int sqrSize = 20;
constexpr int maxStringLength = 100;
WCHAR titleString[maxStringLength];
WCHAR windowClassName[maxStringLength];

//global variables
int mouseX, mouseY;
RECT button;
int coord[2];
//bool keyState[8];
int food[2];
RECT roundDot;
bool running;
HBRUSH brush;
HINSTANCE hInst;
bool framePassed = false;
unsigned int nextFrameStart;

//function identifier
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow);
constexpr bool isKeyDown(SHORT keyState);
int rangedRand(int min, int max);
int main(HWND hwnd);
int setup(HWND hwnd);
bool nextFrame(unsigned int rate);


//entry point function
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
	//initialize global strings.
	LoadStringW(hInstance, IDS_APP_TITLE, titleString, maxStringLength);
	LoadStringW(hInstance, IDC_EGEP, windowClassName, maxStringLength);

	//Register the window class name. (any value)
	const wchar_t CLASS_NAME[] = {'e','x','p','e','r','i','m','e','n','t'};
	WNDCLASS wc = {};
	wc.lpszMenuName = MAKEINTRESOURCEW(IDC_EGEP);
	hInst = hInstance;
	//pointer to application-definded function called the window procedure.
	wc.lpfnWndProc = WindowProc;
	//handle to the application instance.
	wc.hInstance = hInstance;
	//identifies the window class.
	wc.lpszClassName = CLASS_NAME;

	//registers the windows class.
	RegisterClass(&wc);

	// Create the window.
	HWND hwnd = CreateWindowEx(
		0,															// Optional window styles.
		CLASS_NAME,													// Window class
		L"EGEP",													// Window title
		(WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX),	// Window style
		CW_USEDEFAULT, CW_USEDEFAULT, winWidth + 16, winHeight + 59,
		//CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		//starting x, starting y, width, height 

		NULL,       // Parent window  
		NULL,       // Menu
		hInstance,  // Instance handle
		NULL        // Additional application data
	);

	if (hwnd == NULL)
		return 0;
	//draw the window.
	ShowWindow(hwnd, nCmdShow);

	//load accelerator table
	HACCEL acceleratorTableHandle = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EGEP));

	//setting variables
	setup(hwnd);

	//The message loop.
	MSG msg/* = {}*/;
	while (running) {
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE) != 0) {
			if (!TranslateAccelerator(msg.hwnd, acceleratorTableHandle, &msg)) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
				if (msg.message == WM_QUIT)
					running = false;
			}
		}
		main(hwnd);
	}
	return 0;
}

bool nextFrame(unsigned int rate) {
	unsigned int currentTick = static_cast<unsigned int>(GetTickCount());
	unsigned int remaining;
	rate = 1000 / rate;

	if (framePassed) {
		framePassed = false;
		return false;
	}
	if (currentTick < nextFrameStart) {
		remaining = nextFrameStart - currentTick;
		if (remaining > 1)
			Sleep(remaining - 1);
		return false;
	}
	//if none of them
	nextFrameStart = currentTick + rate;
	//lastFrameStart = currentTick;
	framePassed = true;
	return framePassed;
}



int setup(HWND hwnd) {
	//set the location of the button
	coord[0] = 20;
	coord[1] = 20;
	SetRect(&button, coord[0], coord[1], sqrSize + coord[0], sqrSize + coord[1]);
	food[0] = 50;
	food[1] = 50;
	//give the button a initial brush
	brush = CreateSolidBrush(RGB(75, 75, 75));
	running = true;
	//return to signal completion
	return 0;
}
int main(HWND hwnd)
{
	if (nextFrame(30)) {
		//the nextFrame workes well (in eliminating unnecessary CPU usage) up until 50 fps
		//if pumping 60 fps, it will use about 10% of the CPU
		int oldCoord[2];
		oldCoord[0] = coord[0];
		oldCoord[1] = coord[1];

		if (isKeyDown(GetAsyncKeyState(0x57)) && (coord[1] > 0))
			coord[1] = coord[1] - 4;//A
		if (isKeyDown(GetAsyncKeyState(0x41)) && (coord[0] > 0))
			coord[0] = coord[0] - 4;//S
		if (isKeyDown(GetAsyncKeyState(0x53)) && (coord[1] < (winHeight - sqrSize)))
			coord[1] = coord[1] + 4;//D
		if (isKeyDown(GetAsyncKeyState(0x44)) && (coord[0] < (winWidth - sqrSize)))
			coord[0] = coord[0] + 4;//F

		if ((oldCoord[0] != coord[0]) || (oldCoord[1] != coord[1]))
		{
			HWND hwnd = GetActiveWindow();
			InvalidateRect(hwnd, &button, TRUE);
			SetRect(&button, coord[0], coord[1], coord[0] + sqrSize, coord[1] + sqrSize);
			InvalidateRect(hwnd, &button, TRUE);
			if ((abs(coord[0] - food[0]) < 20) && (abs(coord[1] - food[1]) < sqrSize) &&
				(abs(coord[0] - food[0]) + abs(coord[1] - food[1]) < 1.3 * sqrSize)) {
				//food[1] = food[1] + 20;
				food[0] = 4 * rangedRand(0, (winWidth - sqrSize) / 4);
				food[1] = 4 * rangedRand(0, (winHeight -sqrSize) / 4);
				InvalidateRect(hwnd, &roundDot, TRUE);
			}
			SetRect(&roundDot, food[0], food[1], food[0] + sqrSize, food[1] + sqrSize);
			InvalidateRect(hwnd, &roundDot, TRUE);
		}
		return 0;
	}
}

constexpr bool isKeyDown(SHORT keyState) {
	return ((keyState & 0x8000) != 0);
}

int rangedRand(int min, int max)
{
	int u = (int)((double)rand() / (RAND_MAX + 1) * (max - min)) + min;
	return u;
}



//the DispatchMessage function will call this function
//the window procedure of the window that is the target of the message.
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
//HWND is the handle
//uMsg is the message code
//WPARAM and LPARAM are additional data to the message
//LRESULT is a int value that's a "response" to the message
{
	switch (uMsg) {
	//from the menu selections, the WM_COMMAND is sent
	case WM_COMMAND:{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId) {
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hwnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hwnd);
			break;
		default:
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
		}
	}
	break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		running = false;
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_PAINT: {
		//painting procedures
		//initialize PAINTSTRUCT here
		PAINTSTRUCT ps;
		//Handle Device Context
		HDC hdc = BeginPaint(hwnd, &ps);
		//create a "brush" to paint stuff
		//the background
		FillRect(hdc, &ps.rcPaint, (HBRUSH)6);
		//the button
		FillRect(hdc, &button, brush);
		//the food
		Ellipse(hdc, food[0], food[1], food[0] + sqrSize, food[1] + sqrSize);
		EndPaint(hwnd, &ps);
	}
	return 0;
	case WM_LBUTTONUP:
		//case WM_MOUSEACTIVATE:
	case WM_MOUSEMOVE:
		mouseX = ((int)(short)LOWORD(lParam));
		mouseY = ((int)(short)HIWORD(lParam));
		//tell the system that the rectangle here need to be redrawn

		//compare mouse coordinate with the boarder of the button
		if (mouseX > coord[0] && mouseX < (sqrSize + coord[0]) && mouseY > coord[1] && mouseY < (sqrSize + coord[1])) {
			brush = CreateSolidBrush(RGB(75, 75, 75));
			InvalidateRect(hwnd, &button, TRUE);
		}
		else
			brush = CreateSolidBrush(RGB(100, 100, 100));
		return 0;

	case WM_LBUTTONDOWN:
		mouseX = ((int)(short)LOWORD(lParam));
		mouseY = ((int)(short)HIWORD(lParam));
		
		if (mouseX > coord[0] && mouseX < (sqrSize + coord[0]) && mouseY > coord[1] && mouseY < (sqrSize + coord[1])) {
			food[0] = 4 * rangedRand(0, (winWidth - sqrSize)/ 4);
			food[1] = 4 * rangedRand(0, (winHeight - sqrSize) / 4);
			InvalidateRect(hwnd, &roundDot, TRUE);
			SetRect(&roundDot, food[0], food[1], food[0] + sqrSize, food[1] + sqrSize);
			InvalidateRect(hwnd, &button, TRUE);
			brush = CreateSolidBrush(RGB(0, 0, 0));
		}
		return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message) {
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}