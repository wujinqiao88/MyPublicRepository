#include<windows.h>
#include<stdio.h>

LRESULT CALLBACK WindowProc(
  HWND hwnd,      // handle to window
  UINT uMsg,      // message identifier
  WPARAM wParam,  // first message parameter
  LPARAM lParam   // second message parameter
);
int WINAPI WinMain(
  HINSTANCE hInstance,      // handle to current instance
  HINSTANCE hPrevInstance,  // handle to previous instance
  LPSTR lpCmdLine,          // command line
  int nCmdShow              // show state
)
{
	HMENU hMenu = CreateMenu();
	HMENU hSubMenu = CreateMenu();
	AppendMenu(hSubMenu,MF_BYPOSITION | MF_STRING,101,"打开(&O)");
	AppendMenu(hSubMenu,MF_BYPOSITION | MF_STRING,102,"保存(&S)");
	AppendMenu(hSubMenu,MF_BYPOSITION | MF_STRING,103,"关闭(&C)");
	AppendMenu(hSubMenu,MF_BYPOSITION | MF_STRING,104,"退出(&Q)");

	AppendMenu(hMenu,MF_BYPOSITION |MF_POPUP|MF_STRING,(UINT)hSubMenu,"文件(&F)");
	

	WNDCLASS wndcls;
	wndcls.cbClsExtra = 0;
	wndcls.cbWndExtra = 0;
	wndcls.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndcls.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndcls.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndcls.hInstance = hInstance;
	wndcls.lpfnWndProc = WindowProc;
	wndcls.lpszClassName = "WJQ";
	wndcls.lpszMenuName = NULL;
	wndcls.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndcls);

	HWND hwnd;
	hwnd = CreateWindow("WJQ","西安敦瑞测量技术有限公司",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,0,CW_USEDEFAULT,600,NULL,hMenu,hInstance,NULL);

	ShowWindow(hwnd,nCmdShow);

	UpdateWindow(hwnd);

	MSG msg;
	while(GetMessage(&msg,NULL,NULL,NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
} 

LRESULT CALLBACK WindowProc(
  HWND hwnd,      // handle to window
  UINT uMsg,      // message identifier
  WPARAM wParam,  // first message parameter
  LPARAM lParam   // second message parameter
)
{
	switch(uMsg)
	{
	case WM_COMMAND:
		if ((UINT)wParam == 101)
		{
			MessageBox(hwnd,"dgajagd","hello",MB_OK);
		}
	case WM_PAINT:
		HDC dc;
		PAINTSTRUCT ps;
		dc = BeginPaint(hwnd,&ps);
		TextOut(dc,0,0,"Paint message received !",strlen("Paint message received !"));
		EndPaint(hwnd,&ps);
		break;
	case WM_CHAR:
		char str[50];
		sprintf(str,"WM_CHAR message received ! Char is %c ",wParam);
		MessageBox(hwnd,str,"WM_CHAR",MB_OK);
		break;
	case WM_LBUTTONDOWN:
		MessageBox(hwnd,"LBUTTONDOWN message received !","WM_LBUTTONDOWN",MB_OK);
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default: 
		return DefWindowProc(hwnd,uMsg,wParam,lParam);
	}

	return 0;
}
