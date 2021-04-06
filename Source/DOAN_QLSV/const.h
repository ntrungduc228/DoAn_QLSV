#pragma once
#include<iostream>
#include<string>
using namespace std;
const int ConsoleWidth = 1368; // chieu ngang man hinh
const int ConsoleHeight = 745; // chieu doc man hinh

const int LeftSideBar = 34;

const int LengButton = LeftSideBar - 6;

const int yTitleContent = 2;
const int WallWidth = 163;
const int WallHeight = 42;
const int midSideBar = WallHeight / 2;

const int xTable = LeftSideBar + 3;
const int yTable = 5;

/* DEFINE KEY */

#define F1 59
#define F2 60
#define F3 61
#define F4 62
#define F5 63
#define ESC 27
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define PAGEUP 73
#define PAGEDOWN 81
#define HOME 71
#define ENTER 13
#define SPACE 32
#define BACKSPACE 8

string MENU[5] = { " LOP TIN CHI ", " SINH VIEN ", " MON HOC ", " DIEM " ,"THOAT"};

string MENU_LopTC[5] = {	" Them lop tin chi",
							" Xoa lop tin chi",
							" Sua lop tin chi",
							"In DS 1 lop tin chi",
							"In DS lop tin chi" };

string MENU_Sinhvien[5] = { " Them lop hoc",
							" Nhap DS sinh vien",
							" Xoa sinh vien",
							" Sua sinh vien",
							" In DS sinh vien 1 lop " };

string MENU_Monhoc[5] = {	" Them mon hoc ",
							" Xoa mon hoc",
							" Sua mon hoc",
							" Dang ky mon hoc  ",
							"  In DS mon hoc   " };

string MENU_Diem[4] = {		" Nhap diem lop tin chi ",
							"   Bang diem mon hoc  ",
							" Bang diem trung binh  ",
							"   Bang diem tong ket  " };

const int xMENU = LeftSideBar / 2 - LengButton / 2;  // x=3;
const int yMENU = 3 + yTitleContent;
const int disMEMU = 3; // khoang cach giua 2 button menu