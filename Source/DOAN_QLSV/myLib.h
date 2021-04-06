/*============================= MYLIB.H =============================*/
#pragma once
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <dos.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include<ctime>
#include"const.h"
using namespace std;

const int clblack = 0;
const int clblue = 1;
const int clgreen = 2;
const int claqua = 3;
const int clred = 4;
const int clpurple = 5;
const int clyellow = 6;
const int clwhite = 7;
const int clgray = 8;
const int cllightblue = 9;
const int cllightgreen = 10;
const int cllightaqua = 11;
const int cllightred = 12;
const int cllightpurple = 13;
const int cllightyellow = 14;
const int cllightwhite = 15;


/*=================== KHAI BAO NGUYEN MAU HAM ====================*/

void resizeConsole(int width, int height);
void removeScrollbar();
void gotoxy(int x, int y);
void hideCursortype();  // an con tro man hinh
void showCursortype(); // show ra con tro man hinh
void SetColor(WORD color);  // version 1
void SetColor(int textcolor, int backgroundcolor); // version 2
void SetBGColor(WORD color);
int whereX(void);
int whereY(void);
int GetKey();

/*=================== DINH NGHIA NGUYEN MAU HAM ====================*/

void resizeConsole(int width, int height)
{
	// CODE 1

	/*HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);*/

	// CODE 2

	HWND c = GetConsoleWindow();
	DWORD style = GetWindowLong(c, GWL_STYLE);
	RECT r;
	COORD s = { width,height };
	GetWindowRect(c, &r);
	MoveWindow(c, 1, 1, width, height, TRUE);
	style &= ~WS_MAXIMIZEBOX;
	SetWindowLong(c, GWL_STYLE, style);
	SetWindowPos(c, NULL, 1, 1, width, height, SWP_NOSIZE | SWP_NOMOVE | SWP_FRAMECHANGED);
}


void removeScrollbar()
{

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);
	//system("color F0");
	/*string title = ("    ");                                                                                                                                                                 QUAN LY SINH VIEN - SV:TRAN OANH TOAI - N17DCCN155");
	SetConsoleTitle(title.c_str());*/
}

void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}


void hideCursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void showCursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE; Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}



void SetColor(WORD color)
{
	/*HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);*/


	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleOutput, color);

}
void SetColor(int textcolor, int backgroundcolor)
{
	int color;

	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	color = backgroundcolor * 16 + textcolor;
	SetConsoleTextAttribute(hConsoleOutput, color);

}

void SetBGColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
	//system("cls");

}

int whereX(void)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.X;
}

int whereY(void)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.Y;
}

int GetKey()
{
	char key;
		key = _getch();
		if (key == -32 || key == 0)
		{
			key = _getch();
			return key;
		}
		else return key;
	
}


