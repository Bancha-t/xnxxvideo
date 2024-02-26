#include <windows.h>
#include <stdio.h>

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    static HWND textfield, textbox1, textbox2;
    static HWND add, sub, mul, div;
    char outMessage[100];
    char num1[256], num2[256];
    double val1, val2, result;

    switch (message) {
        case WM_CREATE:
            textfield = CreateWindow("STATIC", "Please input two numbers", WS_VISIBLE | WS_CHILD | WS_BORDER, 20, 20, 200, 20, hwnd, NULL, NULL, NULL);
            textbox1 = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 62.5, 60, 120, 20, hwnd, NULL, NULL, NULL);
            textbox2 = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 62.5, 90, 120, 20, hwnd, NULL, NULL, NULL);
            add = CreateWindow("BUTTON", "+", WS_VISIBLE | WS_CHILD | WS_BORDER, 65, 130, 20, 20, hwnd, (HMENU)1, NULL, NULL);
            sub = CreateWindow("BUTTON", "-", WS_VISIBLE | WS_CHILD | WS_BORDER, 95, 130, 20, 20, hwnd, (HMENU)2, NULL, NULL);
            mul = CreateWindow("BUTTON", "*", WS_VISIBLE | WS_CHILD | WS_BORDER, 125, 130, 20, 20, hwnd, (HMENU)3, NULL, NULL);
            div = CreateWindow("BUTTON", "/", WS_VISIBLE | WS_CHILD | WS_BORDER, 155, 130, 20, 20, hwnd, (HMENU)4, NULL, NULL);
            break;
        case WM_COMMAND:
            GetWindowText(textbox1, num1, 256);
            GetWindowText(textbox2, num2, 256);
            val1 = atof(num1);
            val2 = atof(num2);
            switch (LOWORD(wParam)) {
                case 1:
    				result = val1 + val2;
   				break;
				case 2:
    				result = val1 - val2;
    			break;
				case 3:
    				result = val1 * val2;
    			break;
				case 4:
    			result = val1 / val2;
   				 break;
			}
			sprintf(outMessage, "Hello");
			MessageBox(hwnd, outMessage, "Result", MB_OK);

            }
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow) {
    WNDCLASSEX wincl = {};
    HWND hwnd;
    MSG messages;

    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = "Test";
    wincl.lpfnWndProc = WindowProcedure;
    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof(WNDCLASSEX);
    wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(255, 0, 0));

    if (!RegisterClassEx(&wincl))
        return 0;

    hwnd = CreateWindowEx(
        0,
        "Test",
        "MyCalculator",
        WS_SYSMENU,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        250,
        200,
        HWND_DESKTOP,
        NULL,
        hThisInstance,
        NULL);

    ShowWindow(hwnd, nCmdShow);

    while (GetMessage(&messages, NULL, 0, 0)) {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }

    return messages.wParam;
}
