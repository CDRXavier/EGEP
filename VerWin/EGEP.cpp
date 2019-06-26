{\rtf1\ansi\ansicpg1252\deff0\nouicompat\deflang1033{\fonttbl{\f0\fnil\fcharset0 ??;}{\f1\fnil\fcharset0 Calibri;}}
{\*\generator Riched20 10.0.18362}\viewkind4\uc1 
\pard\f0\fs22 /*\par
#include "stdafx.h"\par
#include "WindowsDesktopProgram1.h"\par
\par
#define MAX_LOADSTRING 100\par
\par
// Global Variables:\par
HINSTANCE hInst;                                // current instance\par
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text\par
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name\par
\par
// Forward declarations of functions included in this code module:\par
ATOM                MyRegisterClass(HINSTANCE hInstance);\par
BOOL                InitInstance(HINSTANCE, int);\par
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);\par
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);\par
\par
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,\par
\tab\tab\tab\tab\tab  _In_opt_ HINSTANCE hPrevInstance,\par
\tab\tab\tab\tab\tab  _In_ LPWSTR    lpCmdLine,\par
\tab\tab\tab\tab\tab  _In_ int       nCmdShow)\par
\{\par
\tab UNREFERENCED_PARAMETER(hPrevInstance);\par
\tab UNREFERENCED_PARAMETER(lpCmdLine);\par
\par
\tab // TODO: Place code here.\par
\par
\tab // Initialize global strings\par
\tab LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);\par
\tab LoadStringW(hInstance, IDC_WINDOWSDESKTOPPROGRAM1, szWindowClass, MAX_LOADSTRING);\par
\tab MyRegisterClass(hInstance);\par
\par
\tab // Perform application initialization:\par
\tab if (!InitInstance (hInstance, nCmdShow))\par
\tab\{\par
\tab\tab return FALSE;\par
\tab\}\par
\par
\tab HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSDESKTOPPROGRAM1));\par
\par
\tab MSG msg;\par
\par
\tab // Main message loop:\par
\tab while (GetMessage(&msg, nullptr, 0, 0))\par
\tab\{\par
\tab\tab if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))\par
\tab\tab\{\par
\tab\tab\tab TranslateMessage(&msg);\par
\tab\tab\tab DispatchMessage(&msg);\par
\tab\tab\}\par
\tab\}\par
\par
\tab return (int) msg.wParam;\par
\}\par
\par
\par
\par
//\par
//  FUNCTION: MyRegisterClass()\par
//\par
//  PURPOSE: Registers the window class.\par
//\par
ATOM MyRegisterClass(HINSTANCE hInstance)\par
\{\par
\tab WNDCLASSEXW wcex;\par
\par
\tab wcex.cbSize = sizeof(WNDCLASSEX);\par
\par
\tab wcex.style          = CS_HREDRAW | CS_VREDRAW;\par
\tab wcex.lpfnWndProc    = WndProc;\par
\tab wcex.cbClsExtra     = 0;\par
\tab wcex.cbWndExtra     = 0;\par
\tab wcex.hInstance      = hInstance;\par
\tab wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSDESKTOPPROGRAM1));\par
\tab wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);\par
\tab wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);\par
\tab wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSDESKTOPPROGRAM1);\par
\tab wcex.lpszClassName  = szWindowClass;\par
\tab wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));\par
\par
\tab return RegisterClassExW(&wcex);\par
\}\par
\par
//\par
//   FUNCTION: InitInstance(HINSTANCE, int)\par
//\par
//   PURPOSE: Saves instance handle and creates main window\par
//\par
//   COMMENTS:\par
//\par
//        In this function, we save the instance handle in a global variable and\par
//        create and display the main program window.\par
//\par
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)\par
\{\par
   hInst = hInstance; // Store instance handle in our global variable\par
\par
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,\par
\tab   CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);\par
\par
   if (!hWnd)\par
   \{\par
\tab   return FALSE;\par
   \}\par
\par
   ShowWindow(hWnd, nCmdShow);\par
   UpdateWindow(hWnd);\par
\par
   return TRUE;\par
\}\par
\par
//\par
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)\par
//\par
//  PURPOSE: Processes messages for the main window.\par
//\par
//  WM_COMMAND  - process the application menu\par
//  WM_PAINT    - Paint the main window\par
//  WM_DESTROY  - post a quit message and return\par
//\par
//\par
L\par
*/\par
\par
\par
#ifndef UNICODE\par
#define UNICODE\par
#endif\par
\par
#include <windows.h>\par
#include <wingdi.h>\par
//for the project to work\par
#include "stdafx.h"\par
\par
//#define IDC_MYICON                      2\par
//#define IDD_EGEP_DIALOG                 102\par
#define IDS_APP_TITLE                   103\par
//#define IDM_ABOUT                       104\par
#define IDI_EGEP                        107\par
#define IDI_SMALL                       108\par
#define IDC_EGEP                        109\par
//#define IDR_MAINFRAME                   128\par
//#define IDC_STATIC                     -1\par
\par
constexpr int winHeight = 250;\par
constexpr int winWidth = 200;\par
//int positionX, positionY;\par
//int currentX, currentY;\par
//int previousX, previousY;\par
\par
constexpr int sqrSize = 20;\par
constexpr int maxStringLength = 100;\par
WCHAR titleString[maxStringLength];\par
WCHAR windowClassName[maxStringLength];\par
\par
//global variables\par
//int color = 6;\par
int mouseX, mouseY;\par
RECT button;\par
int coord[2];\par
int oldCoord[2];\par
//bool keyState[8];\par
int food[2];\par
RECT roundDot;\par
bool running;\par
HBRUSH brush;\par
RECT xCoord;\par
RECT yCoord;\par
//the clock variables\par
//float ElapsedTime = 0.0f;\par
//float prevtime = 0.0f;\par
//DWORD previousTicks;\par
\par
//function identifier\par
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);\par
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);\par
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow);\par
constexpr bool isKeyDown(SHORT keyState);\par
int rangedRand(int min, int max);\par
int main(HWND hwnd);\par
int setup(HWND hwnd);\par
//void IntToString(sf::String & rStr, int val);\par
bool nextFrame(unsigned int rate);\par
\par
\par
\par
\par
//entry point function\par
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)\par
\{\par
\tab LoadStringW(hInstance, IDS_APP_TITLE, titleString, maxStringLength);\par
\tab LoadStringW(hInstance, IDC_EGEP, windowClassName, maxStringLength);\par
\par
\tab //Register the window class name. (any value?)\par
\tab const wchar_t CLASS_NAME[] = \{ 'n','o','n','s','e','n','c','e' \};\par
\tab WNDCLASS wc = \{\};\par
\tab wc.lpszMenuName = MAKEINTRESOURCEW(IDC_EGEP);\par
\par
\tab //pointer to application-definded function called the window procedure.\par
\tab wc.lpfnWndProc = WindowProc;\par
\tab //handle to the application instance.\par
\tab wc.hInstance = hInstance;\par
\tab //identifies the window class.\par
\tab wc.lpszClassName = CLASS_NAME;\par
\par
\tab //registers the windows class.\par
\tab RegisterClass(&wc);\par
\par
\tab //initialize global string (why?)\par
\tab //LoadStringW(instanceHandle, IDS_APP_TITLE, titleString, maxStringLength);\par
\tab //LoadStringW(instanceHandle, IDC_EGEP, windowClassName, maxStringLength);\par
\tab //RegisterWindowClass(instanceHandle);\par
\par
\tab // Create the window.\par
\tab HWND hwnd = CreateWindowEx(\par
\tab\tab 0,                              // Optional window styles.\par
\tab\tab CLASS_NAME,                     // Window class\par
\tab\tab L"Windows Project",\par
\tab\tab //L"WindowsProject",              // Window title\par
\tab\tab (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX),// Window style\par
\tab\tab // Size and position\par
\tab\tab CW_USEDEFAULT, CW_USEDEFAULT, winWidth, winHeight,\par
\tab\tab //CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,\par
\tab\tab //starting x, starting y, width, height \par
\par
\tab\tab NULL,       // Parent window  \par
\tab\tab NULL,       // Menu\par
\tab\tab hInstance,  // Instance handle\par
\tab\tab NULL        // Additional application data\par
\tab );\par
\par
\tab if (hwnd == NULL)\par
\tab\tab return 0;\par
\tab //draw the window.\par
\tab ShowWindow(hwnd, nCmdShow);\par
\par
\tab //load accelerator table\par
\tab HACCEL acceleratorTableHandle = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EGEP));\par
\par
\par
\tab //setting variables\par
\tab setup(hwnd);\par
\par
\tab // Run the message loop.\par
\tab MSG msg/* = \{\}*/;\par
\tab while (running) \{\par
\tab\tab while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE) != 0) \{\par
\tab\tab\tab if (!TranslateAccelerator(msg.hwnd, acceleratorTableHandle, &msg)) \{\par
\tab\tab\tab\tab TranslateMessage(&msg);\par
\tab\tab\tab\tab DispatchMessage(&msg);\par
\tab\tab\tab\tab if (msg.message == WM_QUIT)\par
\tab\tab\tab\tab\tab running = false;\par
\tab\tab\tab\}\par
\tab\tab\}\par
\tab\tab main(hwnd);\par
\tab\}\par
\tab return 0;\par
\}\par
\par
\par
\par
\par
bool framePassed = false;\par
unsigned int lastFrameDurationMs = 0;\par
unsigned int frameDuration;\par
unsigned int thisFrameStart;\par
unsigned int frameCount;\par
\par
\par
\par
\par
/*\par
void timeToString(float timeVal)\par
\{\par
\tab static char chTime[12] = "00:00:00.00";\par
//\tab int bigSecs = static_cast<int>( 100.0f*ElapsedTime );\par
\tab int bigSecs = static_cast<int>( 100.0f*timeVal );// bigSecs = 100 * actual seconds\par
\par
\par
\tab // hours\par
\tab bigSecs %= 8640000;// 24 hours\par
\tab chTime[0] = '0' + bigSecs/3600000;// tens of hours\par
\tab bigSecs %= 3600000;\par
\tab chTime[1] = '0' + bigSecs/360000;// one hour\par
\tab chTime[2] = ':';\par
\par
\tab // minutes\par
\tab bigSecs %= 360000;// 60 minute\par
\tab chTime[3] = '0' + bigSecs/60000;// tens of minutes\par
\tab bigSecs %= 60000;\par
\tab chTime[4] = '0' + bigSecs/6000;// minutes\par
\tab chTime[5] = ':';\par
\par
\tab // whole seconds\par
\tab bigSecs %= 6000;// 60 seconds\par
\tab chTime[6] = '0' + bigSecs/1000;// tens of seconds\par
\tab bigSecs %= 1000;\par
\tab chTime[7] = '0' + bigSecs/100;// seconds\par
\tab chTime[8] = '.';\par
\par
\tab // hundredths of seconds\par
\tab bigSecs %= 100;\par
\tab chTime[9] = '0' + bigSecs/10;\par
\tab bigSecs %= 10;\par
\tab chTime[10] = '0' + bigSecs;\par
\tab chTime[11] = '\\0';\par
\par
\tab // assign to text\par
\tab //timeText.SetText( chTime );\par
\par
\tab return;\par
\}// end of timeToString()\par
void boolhiss(int val, char target[])//intToString(int val)[8]\par
\{\par
\tab char chInt[20] = "01";\par
\tab char chIntRev[20] = "aaaaaaaaaaaaaaaaaaa";\par
\par
\tab int Dcount = 0;\par
\tab do\par
\tab\{\par
\tab\tab chIntRev[Dcount] = val%10 + '0';\par
\tab\tab Dcount++;\par
\tab\tab val /= 10;\par
\tab\}while(val && Dcount<20);\par
\par
\tab for(int i=0; i<Dcount; i++)\par
\tab\tab chInt[i] = chIntRev[Dcount-1-i];\par
\tab chInt[Dcount] = '\\0';\par
\par
\tab // assign to text\par
\par
\tab target = chInt;\par
\}// end of IntToString()\par
*/\par
\par
\par
bool nextFrame(unsigned int rate) \{\par
\tab rate = 1000 / rate;\par
\tab unsigned int currentTick = static_cast<unsigned int>(GetTickCount());\par
\tab unsigned int frameDurationMs = currentTick - thisFrameStart;\par
\tab if (framePassed) \{\par
\tab\tab lastFrameDurationMs = frameDurationMs;\par
\tab\tab framePassed = false;\par
\tab\tab return false;\par
\tab\}\par
\tab else if (frameDurationMs < rate) \{\par
\tab\tab //if ((frameDurationMs + 10) < eachFrameMillis)\par
\tab\tab //\tab WaitMessage();\par
\tab\tab return false;\par
\tab\}\par
\tab else \{\par
\tab\tab framePassed = true;\par
\tab\tab thisFrameStart = currentTick;\par
\tab\tab //frameCount++;\par
\tab\tab return true;\par
\tab\}\par
\}\par
\par
\par
\par
int setup(HWND hwnd) \{\par
\tab //set the dimension of the button\par
\tab coord[0] = 20;\par
\tab coord[1] = 20;\par
\tab SetRect(&button, coord[0], coord[1], sqrSize + coord[0], sqrSize + coord[1]);\par
\tab food[0] = rangedRand(0,winWidth);\par
\tab food[1] = rangedRand(0,winHeight);\par
\tab SetRect(&xCoord, 0, 100, 20, 120);\par
\tab SetRect(&yCoord, 0, 120, 20, 140);\par
\tab //rand();\par
\tab //give the button a initial brush\par
\tab brush = CreateSolidBrush(RGB(75, 75, 75));\par
\par
\tab running = true;\par
\tab //previousTicks = GetTickCount();\par
\tab //return to signal completion\par
\tab return 0;\par
\}\par
int main(HWND hwnd)\par
\{\par
\tab if (nextFrame(20)) \{\par
\tab\tab // Calculate delta time \par
\tab\tab //DWORD currentTicks = GetTickCount();\par
\tab\tab //DWORD deltaTicks = (currentTicks - previousTicks);\par
\tab\tab //float deltaTime = (static_cast<float>(deltaTicks) / 1000.0f);\par
\tab\tab //previousTicks = currentTicks;\par
\par
\tab\tab oldCoord[0] = coord[0];\par
\tab\tab oldCoord[1] = coord[1];\par
\par
\tab\tab //time = GetTickCount();\par
\tab\tab\tab //the highest bit tells if the key is pressed\par
\tab\tab\tab //the lowest tell if the key is toggled\par
\tab\tab if (isKeyDown(GetAsyncKeyState(0x57)) /*&& (coord[1] >= 0)*/)\par
\tab\tab\tab coord[1] = coord[1] - 3;//A\par
\tab\tab if (isKeyDown(GetAsyncKeyState(0x41)) /*&& (coord[0] >= 0)*/)\par
\tab\tab\tab coord[0] = coord[0] - 3;\par
\tab\tab if (isKeyDown(GetAsyncKeyState(0x53)) /*&& (coord[1] <= (winHeight - sqrSize))*/)\par
\tab\tab\tab //button.top = button.top + 3;\par
\tab\tab\tab coord[1] = coord[1] + 3;\par
\tab\tab if (isKeyDown(GetAsyncKeyState(0x44)) /*&& (coord[0] <= (winWidth - sqrSize))*/)\par
\tab\tab\tab coord[0] = coord[0] + 3;\par
\tab\tab //limiter does not work. why?\par
\par
\tab\tab //SetRect(&button, coord[0], coord[1], coord[0] + sqrSize, coord[1] + sqrSize);\par
\tab\tab /*\par
\tab\tab if ((oldCoord[0] != coord[0]) || (oldCoord[1] != coord[1]))\par
\tab\tab\{\par
\tab\tab\tab HWND hwnd = GetActiveWindow();\par
\par
\tab\tab\tab RECT oldButtonBounds\{ oldCoord[0], oldCoord[1], oldCoord[0] + sqrSize, oldCoord[1] + sqrSize \};\par
\tab\tab\tab InvalidateRect(hwnd, &oldButtonBounds, TRUE);\par
\par
\tab\tab\tab SetRect(&button, coord[0], coord[1], coord[0] + sqrSize, coord[1] + sqrSize);\par
\tab\tab\tab InvalidateRect(hwnd, &button, TRUE);\par
\tab\tab\tab InvalidateRect(hwnd, &xCoord, TRUE);\par
\tab\tab\tab InvalidateRect(hwnd, &yCoord, TRUE);\par
\par
\tab\tab\tab\par
\tab\tab\tab PAINTSTRUCT ps;\par
\tab\tab\tab HDC hdc = BeginPaint(hwnd, &ps);\par
\tab\tab\tab //create a "brush" to paint stuff\par
\tab\tab\tab //the background\par
\tab\tab\tab FillRect(hdc, &ps.rcPaint, (HBRUSH)6);\par
\tab\tab\tab Ellipse(hdc,food[0],food[1],food[0] + sqrSize, food[1] + sqrSize);\par
\tab\tab\tab SetRect(&roundDot, food[0], food[1], food[0] + sqrSize, food[1] + sqrSize);\par
\tab\tab\tab //the button\par
\tab\tab\tab FillRect(hdc, &button, brush);\par
\tab\tab\tab EndPaint(hwnd, &ps);\par
\tab\tab\tab //square (x and y) bonding box\par
\tab\tab\tab if ((abs(coord[0] - food[0]) < 20) && (abs(coord[1] - food[1]) < sqrSize) &&\par
\tab\tab\tab\tab //taxicab bonding box\par
\tab\tab\tab\tab (abs(coord[0] - food[0]) + abs(coord[1] - food[1]) < 1.25 * sqrSize)) \{\par
\tab\tab\tab\tab food[0] = rangedRand(0, winWidth - 20);\par
\tab\tab\tab\tab food[1] = rangedRand(0, winHeight - 20);\par
\tab\tab\tab\tab InvalidateRect(hwnd, &roundDot, TRUE);\par
\tab\tab\tab\}\par
\tab\tab\}\par
\tab\tab */\par
\tab\tab /*\par
\tab\tab if (GetAsyncKeyState(0x57) & 0x8000)\par
\tab\tab\tab keyState[0] = true; //key "W"\par
\tab\tab else\par
\tab\tab\tab keyState[0] = false;\par
\tab\tab if (GetAsyncKeyState(0x41) & 0x8000)\par
\tab\tab\tab keyState[1] = true; //key "A"\par
\tab\tab else\par
\tab\tab\tab keyState[1] = false;\par
\tab\tab if (GetAsyncKeyState(0x53) & 0x8000)\par
\tab\tab\tab keyState[2] = true; //key "S"\par
\tab\tab else\par
\tab\tab\tab keyState[2] = false;\par
\tab\tab if (GetAsyncKeyState(0x44) & 0x8000)\par
\tab\tab\tab keyState[3] = true; //key "D"\par
\tab\tab else\par
\tab\tab\tab keyState[3] = false;\par
\tab\tab //every 0.1 seconds\par
\tab\tab if (keyState[0] && coord[1] > 0) \{\par
\tab\tab\tab coord[1] = coord[1] - 3;\par
\tab\tab\tab //UpdateWindow(hwnd);\par
\tab\tab\tab //InvalidateRect(hwnd, &button, true);\par
\tab\tab\}\par
\tab\tab if (keyState[2] && (coord[1] < (winWidth - 20))) \{\par
\tab\tab\tab coord[1] = coord[1] + 3;\par
\tab\tab\tab //UpdateWindow(hwnd);\par
\tab\tab\tab //InvalidateRect(hwnd, &button, true);\par
\tab\tab\}\par
\tab\tab if (keyState[1] && (coord[0] > 0)) \{\par
\tab\tab\tab coord[0] = coord[0] - 3;\par
\tab\tab\tab //UpdateWindow(hwnd);\par
\tab\tab\tab //InvalidateRect(hwnd, &button, true);\par
\tab\tab\}\par
\tab\tab if (keyState[3] && (coord[0] < (winHeight - 20))) \{\par
\tab\tab\tab coord[0] = coord[0] + 3;\par
\tab\tab\tab //UpdateWindow(hwnd);\par
\tab\tab\tab //InvalidateRect(hwnd, &button, true);\par
\tab\tab\}\par
\tab\tab */\par
\tab\tab /*\par
\tab\tab if (keyState[0] || keyState[1] || keyState[2] || keyState[3]) \{\par
\tab\tab\tab HWND windowHandle = GetActiveWindow();\par
\tab\tab\tab RECT oldButtonBounds\{ previousX, previousY, positionX + 100, positionY + 80 \};\par
\tab\tab\tab InvalidateRect(windowHandle, &oldButtonBounds, FALSE);\par
\tab\tab\tab RECT newButtonBounds\{ positionX, positionY, positionX + 100, positionY + 80 \};\par
\tab\tab\tab InvalidateRect(windowHandle, &newButtonBounds, FALSE);\par
\tab\tab\}\par
\tab\tab */\par
\tab\tab return 0;\par
\tab\}\par
\}\par
\par
\par
\par
constexpr bool isKeyDown(SHORT keyState) \{\par
\tab return ((keyState & 0x8000) != 0);\par
\}\par
\par
\par
int rangedRand(int min, int max)\par
\{\par
\tab\tab int u = (double)rand() / (RAND_MAX + 1) * (max - min) + min;\par
\tab\tab return u;\par
\}\par
\par
\par
\par
//the DispatchMessage function will call this function\par
//the window procedure of the window that is the target of the message.\par
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)\par
//HWND is the handle\par
//uMsg is the message code\par
//WPARAM and LPARAM are additional data to the message\par
//LRESULT is a int value that's a "response" to the message\par
\{\par
\tab switch (uMsg) \{\par
\tab case WM_CLOSE:\par
\tab\tab //if (MessageBox(hwnd, L"Really quit?", L"My application", MB_OKCANCEL) == IDOK)\par
\tab\tab DestroyWindow(hwnd);\par
\tab\tab running = false;\par
\tab\tab return 0;\par
\tab case WM_DESTROY:\par
\tab\tab PostQuitMessage(0);\par
\tab\tab return 0;\par
\par
\tab\tab //case WM_SIZE:\par
\tab\tab\tab /*\{\par
\tab\tab\tab\tab int width = LOWORD(lParam);  // Macro to get the low-order word.\par
\tab\tab\tab\tab int height = HIWORD(lParam); // Macro to get the high-order word.\par
\par
\tab\tab\tab\tab // Respond to the message:\par
\tab\tab\tab\tab OnSize(hwnd, (UINT)wParam, width, height);\par
\par
\tab\tab\tab   \}*/\par
\tab\tab\tab   //intentional fallthrough\par
\par
\tab case WM_PAINT:\par
\tab\tab //SetRect(&button, coord[0], coord[1], 20 + coord[0], 20 + coord[1]);\par
\tab\tab\{\par
\tab\tab\tab //painting procedures\par
\tab\tab\tab //initialize PAINTSTRUCT here\tab\par
\tab\tab\tab PAINTSTRUCT ps;\par
\tab\tab\tab //Handle Device Context\par
\tab\tab\tab HDC hdc = BeginPaint(hwnd, &ps);\par
\tab\tab\tab //create a "brush" to paint stuff\par
\tab\tab\tab\par
\tab\tab\tab //the background\par
\tab\tab\tab FillRect(hdc, &ps.rcPaint, (HBRUSH)6);\par
\tab\tab\tab\par
\tab\tab\tab //the button\par
\tab\tab\tab FillRect(hdc, &button, brush);\par
\tab\tab\tab //the food\par
\tab\tab\tab Ellipse(hdc, food[0], food[1], food[0] + sqrSize, food[1] + sqrSize);\par
\tab\tab\tab //Ellipse(hdc, 10, 10, 20, 20);\par
\tab\tab\tab // draw text\par
\tab\tab\tab /*A handle to the device context.\par
\tab lpchText\par
\tab A pointer to the string that specifies the text to be drawn. If the nCount parameter is -1, the string must be null-terminated.\par
\tab If uFormat includes DT_MODIFYSTRING, the function could add up to four additional characters to this string. The buffer containing the string should be large enough to accommodate these extra characters.\par
\tab cchText\par
\tab The length, in characters, of the string. If nCount is -1, then the lpchText parameter is assumed to be a pointer to a null-terminated string and DrawText computes the character count automatically.\par
\tab lprc LPRect structure that contains the rectangle (in logical coordinates) in which the text is to be formatted.\par
\tab format changes the method of formatting the text.*/\par
\par
\tab //TextOut(hdc, 0,0,L"", 15);\par
\tab\tab\tab\par
\tab\tab\tab if (food[0] < 20)\par
\tab\tab\tab\tab DrawTextA(hdc, "0", 1, &xCoord, DT_CALCRECT);\par
\tab\tab\tab else if (food[0] < 40)\par
\tab\tab\tab\tab DrawTextA(hdc, "20", 2, &xCoord, DT_CALCRECT);\par
\tab\tab\tab else if (food[0] < 60)\par
\tab\tab\tab\tab DrawTextA(hdc, "40", 2, &xCoord, DT_CALCRECT);\par
\tab\tab\tab else if (food[0] < 80)\par
\tab\tab\tab\tab DrawTextA(hdc, "60", 2, &xCoord, DT_CALCRECT);\par
\tab\tab\tab else if (food[0] < 100)\par
\tab\tab\tab\tab DrawTextA(hdc, "80", 2, &xCoord, DT_CALCRECT);\par
\tab\tab\tab else if (food[0] < 120)\par
\tab\tab\tab\tab DrawTextA(hdc, "100", 3, &xCoord, DT_CALCRECT);\par
\tab\tab\tab else if (food[0] < 140)\par
\tab\tab\tab\tab DrawTextA(hdc, "120", 3, &xCoord, DT_CALCRECT);\par
\tab\tab\tab else if (food[0] < 160)\par
\tab\tab\tab\tab DrawTextA(hdc, "140", 3, &xCoord, DT_CALCRECT);\par
\tab\tab\tab else if (food[0] < 180)\par
\tab\tab\tab\tab DrawTextA(hdc, "160", 3, &xCoord, DT_CALCRECT);\par
\tab\tab\tab else if (food[0] < 200)\par
\tab\tab\tab\tab DrawTextA(hdc, "180", 3, &xCoord, DT_CALCRECT);\par
\tab\tab\tab else\par
\tab\tab\tab\tab DrawTextA(hdc, "OUT!", 4, &xCoord, DT_CALCRECT);\par
\par
\tab\tab\tab if (food[1] < 20)\par
\tab\tab\tab\tab DrawTextA(hdc, "0", 1, &yCoord, DT_CALCRECT);\par
\tab\tab\tab else if (food[1] < 40)\par
\tab\tab\tab\tab DrawTextA(hdc, "20", 2, &yCoord, DT_CALCRECT);\par
\tab\tab\tab else if (food[1] < 60)\par
\tab\tab\tab\tab DrawTextA(hdc, "40", 2, &yCoord, DT_CALCRECT);\par
\tab\tab\tab else if (food[1] < 80)\par
\tab\tab\tab\tab DrawTextA(hdc, "60", 2, &yCoord, DT_CALCRECT);\par
\tab\tab\tab else if (food[1] < 100)\par
\tab\tab\tab\tab DrawTextA(hdc, "80", 2, &yCoord, DT_CALCRECT);\par
\tab\tab\tab else if (food[1] < 120)\par
\tab\tab\tab\tab DrawTextA(hdc, "100", 3, &yCoord, DT_CALCRECT);\par
\tab\tab\tab else if (food[1] < 140)\par
\tab\tab\tab\tab DrawTextA(hdc, "120", 3, &yCoord, DT_CALCRECT);\par
\tab\tab\tab else if (food[1] < 160)\par
\tab\tab\tab\tab DrawTextA(hdc, "140", 3, &yCoord, DT_CALCRECT);\par
\tab\tab\tab else if (food[1] < 180)\par
\tab\tab\tab\tab DrawTextA(hdc, "160", 3, &yCoord, DT_CALCRECT);\par
\tab\tab\tab else if (food[1] < 200)\par
\tab\tab\tab\tab DrawTextA(hdc, "180", 3, &yCoord, DT_CALCRECT);\par
\tab\tab\tab else\par
\tab\tab\tab\tab DrawTextA(hdc, "OUT!", 4, &yCoord, DT_CALCRECT);\par
\tab\tab\tab //TextOut(hdc, 0, 0, L"Hello, Windows!", 15);\par
\tab\tab\tab //TextOut(hdc, 20, 60, L"Click me! :)", 15);\par
\tab\tab\tab EndPaint(hwnd, &ps);\par
\tab\tab\}\par
\tab\tab return 0;\par
\tab case WM_LBUTTONUP:\par
\tab\tab //case WM_MOUSEACTIVATE:\par
\tab case WM_MOUSEMOVE:\par
\tab\tab mouseX = ((int)(short)LOWORD(lParam));\par
\tab\tab mouseY = ((int)(short)HIWORD(lParam));\par
\tab\tab //tell the system that the rectangle here need to be redrawn\par
\tab\tab\par
\tab\tab //compare mouse coordinate with the boarder of the button\par
\tab\tab if (mouseX > coord[0] && mouseX < (20 + coord[0]) && mouseY > coord[1] && mouseY < (20 + coord[1])) \{\par
\tab\tab\tab brush = CreateSolidBrush(RGB(75, 75, 75));\par
\tab\tab\tab InvalidateRect(hwnd, &button, TRUE);\par
\tab\tab\}\par
\tab\tab else\par
\tab\tab\tab brush = CreateSolidBrush(RGB(100, 100, 100));\par
\tab\tab return 0;\par
\par
\tab case WM_LBUTTONDOWN:\par
\tab\tab //mouseX = LOWORD(lParam);\par
\tab\tab //GET_X_PARAM == ((int)(short)LOWORD(lParam));\par
\tab\tab //GET_Y_PARAM == ((int)(short)HIWORD(lParam));\par
\tab\tab mouseX = ((int)(short)LOWORD(lParam));\par
\tab\tab mouseY = ((int)(short)HIWORD(lParam));\par
\tab\tab if (mouseX > coord[0] && mouseX < (20 + coord[0]) && mouseY > coord[1] && mouseY < (20 + coord[1])) \{\par
\tab\tab\tab food[0] = rangedRand(0, winWidth);\par
\tab\tab\tab food[1] = rangedRand(0, winHeight);\par
\tab\tab\tab InvalidateRect(hwnd, &roundDot, TRUE);\par
\tab\tab\tab InvalidateRect(hwnd, &button, TRUE);\par
\tab\tab\tab brush = CreateSolidBrush(RGB(0, 0, 0));\par
\tab\tab\}\par
\tab\tab //to tell the system that a redraw is required\par
\tab\tab //UpdateWindow(hwnd);\par
\tab\tab return 0;\par
\tab\tab /*\par
\tab case WM_KEYDOWN:\par
\tab\tab //key = ((int)(short)LOWORD(lParam));\par
\tab\tab switch (wParam) \{\par
\tab\tab case 0x57: keyState[0] = true; break;\par
\tab\tab case 0x41: keyState[1] = true; break;\par
\tab\tab case 0x53: keyState[2] = true; break;\par
\tab\tab case 0x44: keyState[3] = true; break;\par
\tab\tab\}\par
\tab\tab return 0;\par
\tab case WM_KEYUP:\par
\tab\tab switch (wParam) \{\par
\tab\tab case 0x57: keyState[0] = false; break;\par
\tab\tab case 0x41: keyState[1] = false; break;\par
\tab\tab case 0x53: keyState[2] = false; break;\par
\tab\tab case 0x44: keyState[3] = false; break;\par
\tab\tab\}\par
\tab\tab return 0;*/\par
\tab\}\par
\tab //default action toward messages\par
\tab return DefWindowProc(hwnd, uMsg, wParam, lParam);\par
\}\par
\par
\par
/*\par
void OnSize(HWND hwnd, UINT flag, int width, int height)\par
\{\par
\tab //do resizing stuff\par
\}\par
*/\par
\par
// Message handler for about box.\par
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)\par
\{\par
\tab UNREFERENCED_PARAMETER(lParam);\par
\tab switch (message) \{\par
\tab case WM_INITDIALOG:\par
\tab\tab return (INT_PTR)TRUE;\par
\par
\tab case WM_COMMAND:\par
\tab\tab if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) \{\par
\tab\tab\tab EndDialog(hDlg, LOWORD(wParam));\par
\tab\tab\tab return (INT_PTR)TRUE;\par
\tab\tab\}\par
\tab\tab break;\par
\tab\}\par
\tab return (INT_PTR)FALSE;\par
\}\par
\par
\par
/*\par
int frameStart = 0;\par
int lasttick;\par
bool nextFrame(int rate) \{\par
\tab int duration = 1000 / rate;\par
\tab int currentTick = GetTickCount();\par
\tab int dektaTicks = currentTick - frameStart;\par
\par
\tab int lastFrameDurationMS = duration;\par
\tab bool justRendered = true;\par
\tab //if rendered, and timer didn't expire yet\par
\tab if (justRendered) \{\par
\tab\tab lastFrameDurationMS = dektaTicks;\par
\tab\tab justRendered = false;\par
\tab\tab return false;\par
\tab\}\par
\tab else \{\par
\tab\tab //if it didn't render but it is time to render\par
\tab\tab if (dektaTicks > duration) \{\par
\tab\tab\tab justRendered = true;\par
\tab\tab\tab frameStart = currentTick;\par
\tab\tab\tab return true;\par
\tab\tab\}\par
\tab\tab if (dektaTicks < duration) \{\par
\tab\tab\tab //sleep?\par
\tab\tab\tab //if ((dektaTicks - 10) < duration)\par
\tab\tab\tab //\tab WaitMessage();\par
\tab\tab\tab return false;\par
\tab\tab\}\par
\tab\}\par
\}*/\par

\pard\sa200\sl276\slmult1\f1\lang9\par
}
 