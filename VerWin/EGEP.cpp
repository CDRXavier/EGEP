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
L
*/


#ifndef UNICODE
#define UNICODE
#endif


#include <windows.h>
#include <wingdi.h>
//for the project to work
#include "stdafx.h"

//#define IDC_MYICON                      2
//#define IDD_EGEP_DIALOG                 102
#define IDS_APP_TITLE                   103
//#define IDM_ABOUT                       104
#define IDI_EGEP                        107
#define IDI_SMALL                       108
#define IDC_EGEP                        109
//#define IDR_MAINFRAME                   128
//#define IDC_STATIC                     -1

constexpr int winHeight = 250;
constexpr int winWidth = 200;
//int positionX, positionY;
//int currentX, currentY;
//int previousX, previousY;

constexpr int sqrSize = 20;
constexpr int maxStringLength = 100;
WCHAR titleString[maxStringLength];
WCHAR windowClassName[maxStringLength];

//global variables
//int color = 6;
int mouseX, mouseY;
RECT button;
int coord[2];
int oldCoord[2];
//bool keyState[8];
int food[2];
RECT roundDot;
bool running;
HBRUSH brush;

//RECT xCoord;
//RECT yCoord;


//function identifier
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow);
constexpr bool isKeyDown(SHORT keyState);
int rangedRand(int min, int max);
int main(HWND hwnd);
int setup(HWND hwnd);
//void IntToString(sf::String & rStr, int val);
bool nextFrame(unsigned int rate);




//entry point function
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
	LoadStringW(hInstance, IDS_APP_TITLE, titleString, maxStringLength);
	LoadStringW(hInstance, IDC_EGEP, windowClassName, maxStringLength);

	//Register the window class name. (any value?)
	const wchar_t CLASS_NAME[] = { 'n','o','n','s','e','n','c','e' };
	WNDCLASS wc = {};
	wc.lpszMenuName = MAKEINTRESOURCEW(IDC_EGEP);

	//pointer to application-definded function called the window procedure.
	wc.lpfnWndProc = WindowProc;
	//handle to the application instance.
	wc.hInstance = hInstance;
	//identifies the window class.
	wc.lpszClassName = CLASS_NAME;

	//registers the windows class.
	RegisterClass(&wc);

	//initialize global string (why?)
	//LoadStringW(instanceHandle, IDS_APP_TITLE, titleString, maxStringLength);
	//LoadStringW(instanceHandle, IDC_EGEP, windowClassName, maxStringLength);
	//RegisterWindowClass(instanceHandle);

	// Create the window.
	HWND hwnd = CreateWindowEx(
		0,                              // Optional window styles.
		CLASS_NAME,                     // Window class
		L"Windows Project",
		//L"WindowsProject",              // Window title
		(WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX),// Window style
		// Size and position
		CW_USEDEFAULT, CW_USEDEFAULT, winWidth, winHeight,
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

	// Run the message loop.
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




bool framePassed = false;
unsigned int thisFrameStart;
unsigned int nextFrameStart;

/*
void timeToString(float timeVal)
{
	static char chTime[12] = "00:00:00.00";
//	int bigSecs = static_cast<int>( 100.0f*ElapsedTime );
	int bigSecs = static_cast<int>( 100.0f*timeVal );// bigSecs = 100 * actual seconds


	// hours
	bigSecs %= 8640000;// 24 hours
	chTime[0] = '0' + bigSecs/3600000;// tens of hours
	bigSecs %= 3600000;
	chTime[1] = '0' + bigSecs/360000;// one hour
	chTime[2] = ':';

	// minutes
	bigSecs %= 360000;// 60 minute
	chTime[3] = '0' + bigSecs/60000;// tens of minutes
	bigSecs %= 60000;
	chTime[4] = '0' + bigSecs/6000;// minutes
	chTime[5] = ':';

	// whole seconds
	bigSecs %= 6000;// 60 seconds
	chTime[6] = '0' + bigSecs/1000;// tens of seconds
	bigSecs %= 1000;
	chTime[7] = '0' + bigSecs/100;// seconds
	chTime[8] = '.';

	// hundredths of seconds
	bigSecs %= 100;
	chTime[9] = '0' + bigSecs/10;
	bigSecs %= 10;
	chTime[10] = '0' + bigSecs;
	chTime[11] = '\0';

	// assign to text
	//timeText.SetText( chTime );

	return;
}// end of timeToString()
void boolhiss(int val, char target[])//intToString(int val)[8]
{
	char chInt[20] = "01";
	char chIntRev[20] = "aaaaaaaaaaaaaaaaaaa";

	int Dcount = 0;
	do
	{
		chIntRev[Dcount] = val%10 + '0';
		Dcount++;
		val /= 10;
	}while(val && Dcount<20);

	for(int i=0; i<Dcount; i++)
		chInt[i] = chIntRev[Dcount-1-i];
	chInt[Dcount] = '\0';

	// assign to text

	target = chInt;
}// end of IntToString()
*/






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
		if (remaining > 3)
			Sleep(3);
		return false;
	}
	//if none of them
	nextFrameStart = currentTick + rate;
	//lastFrameStart = currentTick;
		framePassed = true;
		return framePassed;
}



int setup(HWND hwnd) {
	//set the dimension of the button
	coord[0] = 20;
	coord[1] = 20;
	SetRect(&button, coord[0], coord[1], sqrSize + coord[0], sqrSize + coord[1]);
	food[0] = /*rangedRand(0,winWidth)*/50;
	food[1] = /*rangedRand(0,winHeight)*/50;
	//SetRect(&xCoord, 0, 100, 20, 120);
	//SetRect(&yCoord, 0, 120, 20, 140);
	//rand();
	//give the button a initial brush
	brush = CreateSolidBrush(RGB(75, 75, 75));

	running = true;
	//previousTicks = GetTickCount();
	//return to signal completion
	return 0;
}
int main(HWND hwnd)
{
	if (nextFrame(20)) {
		// Calculate delta time 
		//DWORD currentTicks = GetTickCount();
		//DWORD deltaTicks = (currentTicks - previousTicks);
		//float deltaTime = (static_cast<float>(deltaTicks) / 1000.0f);
		//previousTicks = currentTicks;

		oldCoord[0] = coord[0];
		oldCoord[1] = coord[1];

		//time = GetTickCount();
			//the highest bit tells if the key is pressed
			//the lowest tell if the key is toggled
		if (isKeyDown(GetAsyncKeyState(0x57)) /*&& (coord[1] >= 0)*/)
			coord[1] = coord[1] - 3;//A
		if (isKeyDown(GetAsyncKeyState(0x41)) /*&& (coord[0] >= 0)*/)
			coord[0] = coord[0] - 3;
		if (isKeyDown(GetAsyncKeyState(0x53)) /*&& (coord[1] <= (winHeight - sqrSize))*/)
			//button.top = button.top + 3;
			coord[1] = coord[1] + 3;
		if (isKeyDown(GetAsyncKeyState(0x44)) /*&& (coord[0] <= (winWidth - sqrSize))*/)
			coord[0] = coord[0] + 3;
		//limiter does not work. why?

		//SetRect(&button, coord[0], coord[1], coord[0] + sqrSize, coord[1] + sqrSize);
		
		if ((oldCoord[0] != coord[0]) || (oldCoord[1] != coord[1]))
		{
			HWND hwnd = GetActiveWindow();

			RECT oldButtonBounds{ oldCoord[0], oldCoord[1], oldCoord[0] + sqrSize, oldCoord[1] + sqrSize };
			InvalidateRect(hwnd, &oldButtonBounds, TRUE);

			SetRect(&button, coord[0], coord[1], coord[0] + sqrSize, coord[1] + sqrSize);
			//InvalidateRect(hwnd, &button, TRUE);
			//InvalidateRect(hwnd, &xCoord, TRUE);
			//InvalidateRect(hwnd, &yCoord, TRUE);

			/*
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hwnd, &ps);
			//create a "brush" to paint stuff
			//the background
			FillRect(hdc, &ps.rcPaint, (HBRUSH)6);
			Ellipse(hdc,food[0],food[1],food[0] + sqrSize, food[1] + sqrSize);
			*/
			SetRect(&roundDot, food[0], food[1], food[0] + sqrSize, food[1] + sqrSize);
			//the button
			//FillRect(hdc, &button, brush);
			//EndPaint(hwnd, &ps);
			//square (x and y) bonding box
			if ((abs(coord[0] - food[0]) < 20) && (abs(coord[1] - food[1]) < sqrSize) &&
				//taxicab bonding box
				(abs(coord[0] - food[0]) + abs(coord[1] - food[1]) < 1.25 * sqrSize)) {
				if (food[0] < 60)
					food[0] = 100;
				else
					food[0] = 50;
				if (food[1] < 60)
					food[1] = 100;
				else
					food[1] = 50;
				//food[1] = food[1] + 20;
				//food[0] = rangedRand(0, 100);
				//food[1] = rangedRand(0, 100);
				InvalidateRect(hwnd, &roundDot, TRUE);
			}
		}
		
		/*
		if (GetAsyncKeyState(0x57) & 0x8000)
			keyState[0] = true; //key "W"
		else
			keyState[0] = false;
		if (GetAsyncKeyState(0x41) & 0x8000)
			keyState[1] = true; //key "A"
		else
			keyState[1] = false;
		if (GetAsyncKeyState(0x53) & 0x8000)
			keyState[2] = true; //key "S"
		else
			keyState[2] = false;
		if (GetAsyncKeyState(0x44) & 0x8000)
			keyState[3] = true; //key "D"
		else
			keyState[3] = false;
		//every 0.1 seconds
		if (keyState[0] && coord[1] > 0) {
			coord[1] = coord[1] - 3;
			//UpdateWindow(hwnd);
			//InvalidateRect(hwnd, &button, true);
		}
		if (keyState[2] && (coord[1] < (winWidth - 20))) {
			coord[1] = coord[1] + 3;
			//UpdateWindow(hwnd);
			//InvalidateRect(hwnd, &button, true);
		}
		if (keyState[1] && (coord[0] > 0)) {
			coord[0] = coord[0] - 3;
			//UpdateWindow(hwnd);
			//InvalidateRect(hwnd, &button, true);
		}
		if (keyState[3] && (coord[0] < (winHeight - 20))) {
			coord[0] = coord[0] + 3;
			//UpdateWindow(hwnd);
			//InvalidateRect(hwnd, &button, true);
		}
		*/
		/*
		if (keyState[0] || keyState[1] || keyState[2] || keyState[3]) {
			HWND windowHandle = GetActiveWindow();
			RECT oldButtonBounds{ previousX, previousY, positionX + 100, positionY + 80 };
			InvalidateRect(windowHandle, &oldButtonBounds, FALSE);
			RECT newButtonBounds{ positionX, positionY, positionX + 100, positionY + 80 };
			InvalidateRect(windowHandle, &newButtonBounds, FALSE);
		}
		*/
		return 0;
	}
}



constexpr bool isKeyDown(SHORT keyState) {
	return ((keyState & 0x8000) != 0);
}


int rangedRand(int min, int max)
{
	int u = (double)rand() / (RAND_MAX + 1) * (max - min) + min;
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
	case WM_CLOSE:
		//if (MessageBox(hwnd, L"Really quit?", L"My application", MB_OKCANCEL) == IDOK)
		DestroyWindow(hwnd);
		running = false;
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

		//case WM_SIZE:
			/*{
				int width = LOWORD(lParam);  // Macro to get the low-order word.
				int height = HIWORD(lParam); // Macro to get the high-order word.

				// Respond to the message:
				OnSize(hwnd, (UINT)wParam, width, height);

			  }*/
			  //intentional fallthrough

	case WM_PAINT:
		//SetRect(&button, coord[0], coord[1], 20 + coord[0], 20 + coord[1]);
		{
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
			//Ellipse(hdc, 10, 10, 20, 20);
			// draw text
			/*A handle to the device context.
	lpchText
	A pointer to the string that specifies the text to be drawn. If the nCount parameter is -1, the string must be null-terminated.
	If uFormat includes DT_MODIFYSTRING, the function could add up to four additional characters to this string. The buffer containing the string should be large enough to accommodate these extra characters.
	cchText
	The length, in characters, of the string. If nCount is -1, then the lpchText parameter is assumed to be a pointer to a null-terminated string and DrawText computes the character count automatically.
	lprc LPRect structure that contains the rectangle (in logical coordinates) in which the text is to be formatted.
	format changes the method of formatting the text.*/

	//TextOut(hdc, 0,0,L"", 15);
			/*
			if (food[0] < 20)
				DrawTextA(hdc, "0", 1, &xCoord, DT_CALCRECT);
			else if (food[0] < 40)
				DrawTextA(hdc, "20", 2, &xCoord, DT_CALCRECT);
			else if (food[0] < 60)
				DrawTextA(hdc, "40", 2, &xCoord, DT_CALCRECT);
			else if (food[0] < 80)
				DrawTextA(hdc, "60", 2, &xCoord, DT_CALCRECT);
			else if (food[0] < 100)
				DrawTextA(hdc, "80", 2, &xCoord, DT_CALCRECT);
			else if (food[0] < 120)
				DrawTextA(hdc, "100", 3, &xCoord, DT_CALCRECT);
			else if (food[0] < 140)
				DrawTextA(hdc, "120", 3, &xCoord, DT_CALCRECT);
			else if (food[0] < 160)
				DrawTextA(hdc, "140", 3, &xCoord, DT_CALCRECT);
			else if (food[0] < 180)
				DrawTextA(hdc, "160", 3, &xCoord, DT_CALCRECT);
			else if (food[0] < 200)
				DrawTextA(hdc, "180", 3, &xCoord, DT_CALCRECT);
			else
				DrawTextA(hdc, "OUT!", 4, &xCoord, DT_CALCRECT);

			if (food[1] < 20)
				DrawTextA(hdc, "0", 1, &yCoord, DT_CALCRECT);
			else if (food[1] < 40)
				DrawTextA(hdc, "20", 2, &yCoord, DT_CALCRECT);
			else if (food[1] < 60)
				DrawTextA(hdc, "40", 2, &yCoord, DT_CALCRECT);
			else if (food[1] < 80)
				DrawTextA(hdc, "60", 2, &yCoord, DT_CALCRECT);
			else if (food[1] < 100)
				DrawTextA(hdc, "80", 2, &yCoord, DT_CALCRECT);
			else if (food[1] < 120)
				DrawTextA(hdc, "100", 3, &yCoord, DT_CALCRECT);
			else if (food[1] < 140)
				DrawTextA(hdc, "120", 3, &yCoord, DT_CALCRECT);
			else if (food[1] < 160)
				DrawTextA(hdc, "140", 3, &yCoord, DT_CALCRECT);
			else if (food[1] < 180)
				DrawTextA(hdc, "160", 3, &yCoord, DT_CALCRECT);
			else if (food[1] < 200)
				DrawTextA(hdc, "180", 3, &yCoord, DT_CALCRECT);
			else
				DrawTextA(hdc, "OUT!", 4, &yCoord, DT_CALCRECT);
				*/
			//TextOut(hdc, 0, 0, L"Hello, Windows!", 15);
			//TextOut(hdc, 20, 60, L"Click me! :)", 15);
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
		if (mouseX > coord[0] && mouseX < (20 + coord[0]) && mouseY > coord[1] && mouseY < (20 + coord[1])) {
			brush = CreateSolidBrush(RGB(75, 75, 75));
			InvalidateRect(hwnd, &button, TRUE);
		}
		else
			brush = CreateSolidBrush(RGB(100, 100, 100));
		return 0;

	case WM_LBUTTONDOWN:
		//mouseX = LOWORD(lParam);
		//GET_X_PARAM == ((int)(short)LOWORD(lParam));
		//GET_Y_PARAM == ((int)(short)HIWORD(lParam));
		mouseX = ((int)(short)LOWORD(lParam));
		mouseY = ((int)(short)HIWORD(lParam));
		if (mouseX > coord[0] && mouseX < (20 + coord[0]) && mouseY > coord[1] && mouseY < (20 + coord[1])) {
			food[0] = rangedRand(0, winWidth);
			food[1] = rangedRand(0, winHeight);
			InvalidateRect(hwnd, &roundDot, TRUE);
			InvalidateRect(hwnd, &button, TRUE);
			brush = CreateSolidBrush(RGB(0, 0, 0));
		}
		//to tell the system that a redraw is required
		//UpdateWindow(hwnd);
		return 0;
		/*
	case WM_KEYDOWN:
		//key = ((int)(short)LOWORD(lParam));
		switch (wParam) {
		case 0x57: keyState[0] = true; break;
		case 0x41: keyState[1] = true; break;
		case 0x53: keyState[2] = true; break;
		case 0x44: keyState[3] = true; break;
		}
		return 0;
	case WM_KEYUP:
		switch (wParam) {
		case 0x57: keyState[0] = false; break;
		case 0x41: keyState[1] = false; break;
		case 0x53: keyState[2] = false; break;
		case 0x44: keyState[3] = false; break;
		}
		return 0;*/
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

// Message handler for about box.
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


/*
int frameStart = 0;
int lasttick;
bool nextFrame(int rate) {
	int duration = 1000 / rate;
	int currentTick = GetTickCount();
	int dektaTicks = currentTick - frameStart;

	int lastFrameDurationMS = duration;
	bool justRendered = true;
	//if rendered, and timer didn't expire yet
	if (justRendered) {
		lastFrameDurationMS = dektaTicks;
		justRendered = false;
		return false;
	}
	else {
		//if it didn't render but it is time to render
		if (dektaTicks > duration) {
			justRendered = true;
			frameStart = currentTick;
			return true;
		}
		if (dektaTicks < duration) {
			//sleep?
			//if ((dektaTicks - 10) < duration)
			//	WaitMessage();
			return false;
		}
	}
}*/