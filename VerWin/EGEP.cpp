// WindowsDesktopProgram1.cpp : Defines the entry point for the application.
//
/*
#include "stdafx.h"
#include "WindowsDesktopProgram1.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSDESKTOPPROGRAM1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSDESKTOPPROGRAM1));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSDESKTOPPROGRAM1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSDESKTOPPROGRAM1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
*/
#ifndef UNICODE
#define UNICODE
#endif
//include windows controls
//#include <Windowsx.h>
//the windows shell
#include <windows.h>
//for the project to work
#include "stdafx.h"
//function identifier
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int main(HWND hwnd);
void setup();
//global variables
int color = 6;
int mouseX;
int mouseY;
RECT button;
int coord[2];
int key;
bool keystate[8];
HBRUSH brush;

int time;
//entry point function
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
	//Register the window class name. (any value?)
	const wchar_t CLASS_NAME[] = L"nosnense";
	WNDCLASS wc = {};

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
		0,                              // Optional window styles.
		CLASS_NAME,                     // Window class
		L"WindowsProject",              // Window title
		WS_OVERLAPPEDWINDOW,            // Window style

		// Size and position
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
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

	setup();
	// Run the message loop.
	MSG msg = {};
	while (GetMessage(&msg, NULL, 0, 0)) {
		main(hwnd);
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		}
	return 0;
}
void setup() {
	//set the dimension of the button
	coord[0] = 20;
	coord[1] = 20;
	SetRect(&button, coord[0], coord[1], 100 + coord[0], 80 + coord[1]);

	//give the button a initial brush
	brush = CreateSolidBrush(RGB(75, 75, 75));

	//set the textbox
	//SetRect(textbox, 1,1,1,1);
}
int main(HWND hwnd)
{
	//if (GetKeyState(0x57)) keystate[0] = true; //key "W"
	//else keystate[0] = false;
	//if (GetKeyState(0x41)) keystate[1] = true; //key "A"
	//else keystate[1] = false;
	//if (GetKeyState(0x53)) keystate[2] = true; //key "S"
	//else keystate[2] = false;
	//if (GetKeyState(0x44)) keystate[3] = true; //key "D"
	//else keystate[3] = false;
	
	time = (int)GetTickCount();
	if ((time % 1) == 0) {
		//every 0.1 seconds
		if (keystate[0] && coord[1] > 0) {
			coord[1] = coord[1] - 1;
			InvalidateRect(hwnd, &button, true);
		}
		if (keystate[2]) {
			coord[1] = coord[1] + 1;
			InvalidateRect(hwnd, &button, true);
		}
		if (keystate[1] && (coord[0] > 0)) {
			coord[0] = coord[0] - 1;
			InvalidateRect(hwnd, &button, true);
		}
		if (keystate[3]) {

			coord[0] = coord[0] + 1;
			InvalidateRect(hwnd, &button, true);
		}
	}
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
	case WM_CLOSE:
		if (MessageBox(hwnd, L"Really quit?", L"My application", MB_OKCANCEL) == IDOK)
			DestroyWindow(hwnd);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_SIZE:
		/*{
			  int width = LOWORD(lParam);  // Macro to get the low-order word.
			  int height = HIWORD(lParam); // Macro to get the high-order word.

			  // Respond to the message:
			  OnSize(hwnd, (UINT)wParam, width, height);

		  }*/
		//intentional fallthrough
	case WM_PAINT:
		SetRect(&button, coord[0], coord[1], 100 + coord[0], 80 + coord[1]);
		{
		//painting procedures
		//initialize PAINTSTRUCT here	
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		//create a "brush" to paint stuff
		//the background
		FillRect(hdc, &ps.rcPaint, (HBRUSH)6);
		//the button
		FillRect(hdc, &button, brush);
		// draw text
		/*A handle to the device context.

lpchText
A pointer to the string that specifies the text to be drawn. If the nCount parameter is -1, the string must be null-terminated.
If uFormat includes DT_MODIFYSTRING, the function could add up to four additional characters to this string. The buffer containing the string should be large enough to accommodate these extra characters.
cchText
The length, in characters, of the string. If nCount is -1, then the lpchText parameter is assumed to be a pointer to a null-terminated string and DrawText computes the character count automatically.
lprc LPRect structure that contains the rectangle (in logical coordinates) in which the text is to be formatted.
format changes the method of formatting the text.
*/
//TextOut(hdc, 0,0,L"", 15);
		if ((time % 10) == 0)
			DrawTextA(hdc, "MOVE!!!", 6, &button, DT_CALCRECT);
//TextOut(hdc, 0, 0, L"Hello, Windows!", 15);
//TextOut(hdc, 20, 60, L"Click me! :)", 15);
		EndPaint(hwnd, &ps);
	}
	return 0;
	case WM_LBUTTONUP:
	case WM_MOUSEACTIVATE:
	case WM_MOUSEMOVE:
		mouseX = ((int)(short)LOWORD(lParam));
		mouseY = ((int)(short)HIWORD(lParam));
		//tell the system that the rectangle here need to be redrawn
		InvalidateRect(hwnd, &button, TRUE);
		//compare mouse coordinate with the boarder of the button
		if (mouseX > coord[0] && mouseX < (100 + coord[0]) && mouseY > coord[1] && mouseY < (80 + coord[1]))
			brush = CreateSolidBrush(RGB(75, 75, 75));
		else
			brush = CreateSolidBrush(RGB(100, 100, 100));
		return 0;

	case WM_LBUTTONDOWN:
		//mouseX = LOWORD(lParam);
		//GET_X_PARAM == ((int)(short)LOWORD(lParam));
		//GET_Y_PARAM == ((int)(short)HIWORD(lParam));
		mouseX = ((int)(short)LOWORD(lParam));
		mouseY = ((int)(short)HIWORD(lParam));
		if (mouseX > coord[0] && mouseX < (100 + coord[0]) && mouseY > coord[1] && mouseY < (80 + coord[1])) {
			InvalidateRect(hwnd, &button, TRUE);
			brush = CreateSolidBrush(RGB(0, 0, 0));
		}
		//to tell the system that a redraw is required
		//UpdateWindow(hwnd);
		return 0;
	case WM_KEYDOWN:
		//key = ((int)(short)LOWORD(lParam));
		switch (wParam) {
		case 0x57: keystate[0] = true; break;
		case 0x41: keystate[1] = true; break;
		case 0x53: keystate[2] = true; break;
		case 0x44: keystate[3] = true; break;
		}
		//GetKeyState('W');
		//if (key & 0x57 == 0x57) keystate[0] = true; //key "W"
		//if (key & 0x41 == 0x41) keystate[1] = true; //key "A"
		//if (key & 0x53 == 0x53) keystate[2] = true; //key "S"
		//if (key & 0x44 == 0x44) keystate[3] = true; //key "D"
		return 0;
	case WM_KEYUP:
		switch (wParam) {
		case 0x57: keystate[0] = false; break;
		case 0x41: keystate[1] = false; break;
		case 0x53: keystate[2] = false; break;
		case 0x44: keystate[3] = false; break;
		}
		//key = ((int)(short)LOWORD(lParam));
		//if (key & 0x57 == 0x57) keystate[0] = false; //key "W"
		//if (key & 0x41 == 0x41) keystate[1] = false; //key "A"
		//if (key & 0x53 == 0x53) keystate[2] = false; //key "S"
		//if (key & 0x44 == 0x44) keystate[3] = false; //key "D"
		return 0;
	}


	//default action toward messages
	return DefWindowProc(hwnd, uMsg, wParam, lParam);


}
/*
void OnSize(HWND hwnd, UINT flag, int width, int height)
{
	//do resizing stuff
}
*/