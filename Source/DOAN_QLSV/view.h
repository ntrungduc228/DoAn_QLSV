#pragma once
#include"const.h"
#include"myLib.h"
#include"validate.h"
#include <fcntl.h>
#include <io.h>
#include<fstream>

struct column
{
	int widthCol;
	string nameCol;
};
typedef struct column COL;

struct listColumn
{
	int numOfCol = 0;
	COL* infoCol[10];  // 10 con tro kieu COL
};
typedef struct listColumn LISTCOL;


LISTCOL ListColDiemTK();
LISTCOL ListColDiem(int type);
LISTCOL ListColDK();
LISTCOL ListColSV();
LISTCOL ListColLopSV();
LISTCOL ListColMonHoc();
LISTCOL ListColLopTC();

void deleteListCol(LISTCOL newListCol);
void xoaTrang();
void xuatTrang(int trangHienTai, int soTrang);
void drawFormInput(int xForm, int yForm, int formHeight, int formWidth, string titleForm);
void drawButton(int x, int y, int lengButton);
void drawEffectButton(int x, int y, int LengButton);
void deleteFormInput(int xForm, int yForm, int formHeight, int formWidth);
void formConfirm(string content, bool & isConfirm);
void deleteFormNotifi(string content);
void formNotifi(string content);
void deleteNotifi(int x, int y, string content);
void printNotifi(int x, int y, string content);
void formThem_LSV(string title);
void formNhapMa_SV();
void formThem_MH(string title);
void formThem_LTC(string title);
void draw_Table(int numOfRow, LISTCOL newListCol);
void delete_Table(int numOfRow, LISTCOL newListCol);
void formNhap_SV(int numOfRow, LISTCOL newListCol, int num);
void formThem_SV(string title);
void veKhungChinh();
void printInfo();
void loadLogo();

void reset_View();
void init_View();
void printTitle(int x, int y, string title);
void menuTitle(string menuTitle[], int pos, int numMENU);
int chonMenu(int numMENU, int pos, string title[]);
void clearMenuTitle(int numMENU);
void xoaHuongDan();
void xuatHD(const wchar_t* str);
void huongDanMenuChinh();
void huongDanMenuCon();
void huongDanChon();







LISTCOL ListColDiemTK()
{
	LISTCOL newListCol;
	newListCol.numOfCol = 9;

	for (int i = 0; i < newListCol.numOfCol; i++)
	{
		newListCol.infoCol[i] = new COL;
	}

	newListCol.infoCol[0]->widthCol = 5;
	newListCol.infoCol[0]->nameCol = "STT";

	newListCol.infoCol[1]->widthCol = 15;
	newListCol.infoCol[1]->nameCol = "Ma sinh vien";

	newListCol.infoCol[2]->widthCol = 40;
	newListCol.infoCol[2]->nameCol = "Ho Ten";

	for (int i = 3; i <= 8; i++)
	{
		newListCol.infoCol[i]->widthCol = 9;
		newListCol.infoCol[i]->nameCol = "";
	}

	return newListCol;
}

LISTCOL ListColDiem(int type)
{
	LISTCOL newListCol;
	newListCol.numOfCol = 5;

	for (int i = 0; i < newListCol.numOfCol; i++)
	{
		newListCol.infoCol[i] = new COL;
	}

	newListCol.infoCol[0]->widthCol = 7;
	newListCol.infoCol[0]->nameCol = "STT";

	newListCol.infoCol[1]->widthCol = 20;
	newListCol.infoCol[1]->nameCol = "Ma sinh vien";

	newListCol.infoCol[2]->widthCol = 45;
	newListCol.infoCol[2]->nameCol = "Ho";

	newListCol.infoCol[3]->widthCol = 30;
	newListCol.infoCol[3]->nameCol = "Ten";
	
	if (type == 1) // diem mon hoc
	{
		newListCol.infoCol[4]->widthCol = 17;
		newListCol.infoCol[4]->nameCol = "Diem";
	}
	else if (type == 2) // diem TB
	{
		newListCol.infoCol[4]->widthCol = 17;
		newListCol.infoCol[4]->nameCol = "Diem TB";
	}

	return newListCol;
}

LISTCOL ListColDK()
{
	LISTCOL newListCol;
	newListCol.numOfCol = 5;

	for (int i = 0; i < newListCol.numOfCol; i++)
	{
		newListCol.infoCol[i] = new COL;
	}

	newListCol.infoCol[0]->widthCol = 7;
	newListCol.infoCol[0]->nameCol = "STT";

	newListCol.infoCol[1]->widthCol = 20;
	newListCol.infoCol[1]->nameCol = "Ma sinh vien";

	newListCol.infoCol[2]->widthCol = 45;
	newListCol.infoCol[2]->nameCol = "Ho";

	newListCol.infoCol[3]->widthCol = 30;
	newListCol.infoCol[3]->nameCol = "Ten";

	newListCol.infoCol[4]->widthCol = 17;
	newListCol.infoCol[4]->nameCol = "Lop";

	return newListCol;
}

LISTCOL ListColSV()
{
	LISTCOL newListCol;
	newListCol.numOfCol = 6;

	for (int i = 0; i < newListCol.numOfCol; i++)
	{
		newListCol.infoCol[i] = new COL;
	}

	newListCol.infoCol[0]->widthCol = 5;
	newListCol.infoCol[0]->nameCol = "STT";

	newListCol.infoCol[1]->widthCol = 20;
	newListCol.infoCol[1]->nameCol = "Ma sinh vien";

	newListCol.infoCol[2]->widthCol = 40;
	newListCol.infoCol[2]->nameCol = "Ho";

	newListCol.infoCol[3]->widthCol = 23;
	newListCol.infoCol[3]->nameCol = "Ten";

	newListCol.infoCol[4]->widthCol = 14;
	newListCol.infoCol[4]->nameCol = "Phai";

	newListCol.infoCol[5]->widthCol = 15;
	newListCol.infoCol[5]->nameCol = "SDT";


	return newListCol;
}

LISTCOL ListColLopSV()
{
	LISTCOL newListCol;
	newListCol.numOfCol = 3;

	for (int i = 0; i < newListCol.numOfCol; i++)
	{
		newListCol.infoCol[i] = new COL;
	}

	newListCol.infoCol[0]->widthCol = 5;
	newListCol.infoCol[0]->nameCol = "STT";

	newListCol.infoCol[1]->widthCol = 60;
	newListCol.infoCol[1]->nameCol = "Ten lop hoc";

	newListCol.infoCol[2]->widthCol = 55;
	newListCol.infoCol[2]->nameCol = "So sinh vien hien tai cua lop";

	return newListCol;
}

LISTCOL ListColMonHoc()
{
	LISTCOL newListCol;
	newListCol.numOfCol = 5;

	for (int i = 0; i < newListCol.numOfCol; i++)
	{
		newListCol.infoCol[i] = new COL;
	}

	newListCol.infoCol[0]->widthCol = 5;
	newListCol.infoCol[0]->nameCol = "STT";

	newListCol.infoCol[1]->widthCol = 14;
	newListCol.infoCol[1]->nameCol = "Ma mon hoc";

	newListCol.infoCol[2]->widthCol = 55;
	newListCol.infoCol[2]->nameCol = "Ten mon hoc";

	newListCol.infoCol[3]->widthCol = 22;
	newListCol.infoCol[3]->nameCol = "So TC ly thuyet";

	newListCol.infoCol[4]->widthCol = 22;
	newListCol.infoCol[4]->nameCol = "So TC thuc hanh";

	return newListCol;
}


LISTCOL ListColLopTC()
{
	LISTCOL newListCol;
	newListCol.numOfCol = 8;
	for (int i = 0; i < newListCol.numOfCol; i++)
	{
		newListCol.infoCol[i] = new COL;
	}

	newListCol.infoCol[0]->widthCol = 5;
	newListCol.infoCol[0]->nameCol = "STT";

	newListCol.infoCol[1]->widthCol = 8;
	newListCol.infoCol[1]->nameCol = "Ma lop";

	newListCol.infoCol[2]->widthCol = 13;
	newListCol.infoCol[2]->nameCol = "Ma mon hoc";

	newListCol.infoCol[3]->widthCol = 42;
	newListCol.infoCol[3]->nameCol = "Ten mon hoc";

	newListCol.infoCol[4]->widthCol = 8;
	newListCol.infoCol[4]->nameCol = "Khoa";

	newListCol.infoCol[5]->widthCol = 8;
	newListCol.infoCol[5]->nameCol = "Hoc ky";

	newListCol.infoCol[6]->widthCol = 8;
	newListCol.infoCol[6]->nameCol = "Nhom";

	newListCol.infoCol[7]->widthCol = 14;
	newListCol.infoCol[7]->nameCol = "SV toi da";

	/*newListCol.infoCol[8]->widthCol = 9;
	newListCol.infoCol[8]->nameCol = "Con lai";*/

	return newListCol;
}

void deleteListCol(LISTCOL newListCol)
{
	for (int i = 0; i < newListCol.numOfCol; i++)
		delete newListCol.infoCol[i];
}

void xoaTrang()
{
	SetColor(cllightwhite, cllightwhite);
	gotoxy(LeftSideBar + 4, WallHeight - 2);
	cout << "          ";
	SetColor(clblack, cllightwhite);
}

void xuatTrang(int trangHienTai, int soTrang)
{
	SetColor(clblack, cllightwhite);
	gotoxy(LeftSideBar + 4, WallHeight - 2);
	cout << "Trang " << trangHienTai << "/" << soTrang;
}

void drawFormInput(int xForm, int yForm, int formHeight, int formWidth, string titleForm)
{
	int x = xForm; int y = yForm;

	for (int i = 0; i <= formHeight; i++)
	{
		for (int j = 0; j <= formWidth; j++)
		{
			if (j == 0 || j == formWidth || i == 0 || i == formHeight)
			{
				SetColor(cllightblue, cllightwhite);
			}
			else
			{
				SetColor(cllightwhite, cllightwhite);
			}
			gotoxy(x + j, y);
			if (i == 0)
			{
				cout << char(220);
			}
			else if (i == formHeight)
			{
				cout << char(223);
			}
			else
				cout << char(219);
		}
		y++;
	}
	SetColor(clblack, cllightwhite);
	gotoxy(xForm + formWidth / 2 - titleForm.length() / 2, yForm + 2);
	cout << titleForm;


}

void drawButton(int x, int y, int lengButton)
{
	SetColor(clblack, cllightwhite);
	gotoxy(x, y);
	cout << char(218);
	for (int i = 0; i < lengButton; i++) cout << char(196);
	cout << char(191);

	gotoxy(x, y + 1);
	cout << char(179);

	SetColor(cllightwhite, cllightwhite);
	for (int i = 1; i <= lengButton; i++)
	{
		gotoxy(x + i, y + 1);
		cout << char(219);
	}
	SetColor(clblack, cllightwhite);

	gotoxy(lengButton + 1 + x, y + 1);
	cout << char(179);

	gotoxy(x, y + 2);
	cout << char(192);
	for (int i = 0; i < lengButton; i++) cout << char(196);
	cout << char(217);
}

void drawEffectButton(int x, int y, int LengButton)
{
	SetColor(clgreen, cllightwhite);
	gotoxy(x, y);
	cout << char(220);
	for (int i = 0; i < LengButton; i++) cout << char(220);
	cout << char(220);

	gotoxy(x, y + 1);
	cout << char(219);

	SetColor(clgreen, clgreen);
	for (int i = 1; i <= LengButton; i++)
	{
		gotoxy(x + i, y + 1);
		cout << char(219);
	}
	SetColor(clgreen, cllightwhite);

	gotoxy(LengButton + 1 + x, y + 1);
	cout << char(219);

	gotoxy(x, y + 2);
	cout << char(223);
	for (int i = 0; i < LengButton; i++) cout << char(223);
	cout << char(223);

	SetColor(cllightwhite, clgreen);
}

void deleteFormInput(int xForm, int yForm, int formHeight, int formWidth)
{
	int x = xForm; int y = yForm;

	SetColor(cllightwhite, cllightwhite);
	for (int i = 0; i <= formHeight; i++)
	{
		for (int j = 0; j <= formWidth; j++)
		{
			gotoxy(x + j, y);
			cout << char(219);
		}
		y++;
	}

}

void formConfirm(string content, bool& isConfirm)
{
	int formWidth = 40;
	int formHeight = 9;
	int xForm = 82;
	int yForm = 12;
	drawFormInput(xForm + 3, yForm + 1, formHeight, formWidth, "");

	SetColor(cllightwhite, cllightred);
	gotoxy(96, 15);
	cout << content;
	SetColor(clblack, cllightwhite);

	int chon = 1;
	while (chon)
	{
		hideCursortype();
		char key;

		if (chon == 1)
		{
			drawEffectButton(89, 17, 10);
			gotoxy(91, 18);
			cout << "Xac nhan";

			drawButton(109, 17, 10);
			gotoxy(113, 18);
			cout << "Huy";
		}
		else if (chon == 2)
		{
			drawButton(89, 17, 10);
			gotoxy(91, 18);
			cout << "Xac nhan";

			drawEffectButton(109, 17, 10);
			gotoxy(113, 18);
			cout << "Huy";
		}

		key = GetKey();
		if (key == LEFT)
		{
			if (chon == 2) chon--;

		}
		else if (key == RIGHT)
		{
			if (chon == 1) chon++;
		}

		else if (key == ENTER)
		{
			deleteFormInput(xForm + 3, yForm + 1, formHeight, formWidth);
			if (chon == 1) isConfirm = true;
			else if (chon == 2) isConfirm = false;
			chon = 0;
		}

	}
	SetColor(clblack, cllightwhite);
}

void deleteFormNotifi(string content)
{
	int formWidth = content.length() + 10;
	int formHeight = 9;
	int xForm = 85;
	int yForm = 13;

	SetColor(cllightwhite, cllightwhite);
	int x = xForm; int y = yForm;

	for (int i = 0; i <= formHeight; i++)
	{
		for (int j = 0; j <= formWidth; j++)
		{
			gotoxy(x++, y);
			cout << char(219);
		}
		y++;
		x = xForm;
	}
	SetColor(clblack, cllightwhite);
}



void formNotifi(string content)
{
	
	int formWidth = 34;
	int formHeight = 9;
	int xForm =82;
	int yForm =12;
	drawFormInput(xForm + 3, yForm + 1, formHeight, formWidth, "");

	gotoxy(98, 15);
	SetColor(cllightwhite, cllightred);
	cout << "THONG BAO";

	gotoxy(103 - content.length() / 2, 17);
	cout << content;
	

	drawEffectButton(98, 19, 7);
	gotoxy(101, 20);
	SetColor(cllightwhite, clgreen);
	cout << "OK";

	SetColor(clblack, cllightwhite);
	
	_getch();
	
	hideCursortype();
	/*
	bool ok = true;
	while (ok)
	{
		char key = GetKey();
		if (key == ENTER)
		{
			deleteFormNotifi(content);
			ok = false;
		}
	}*/
	
}

void deleteNotifi(int x, int y,string content)
{
	SetColor(cllightwhite, cllightwhite);
	for (int i = 0; i < content.length(); i++)
	{
		gotoxy(x++, y);
		cout << char(219);
	}
}

void printNotifi(int x, int y,string content)
{
	gotoxy(x, y);
	SetColor(cllightwhite, cllightred);
	cout << content;
	SetColor(clblack, cllightwhite);

	bool ok = true;
	while (ok)
	{
		int key = GetKey();
		if (key == ENTER || key == UP || key == DOWN || key == ESC || key == LEFT || key == RIGHT)
		{
			deleteNotifi(x, y, content);
			ok = false;
		}
	}
}



void formThem_LSV(string title)
{
	int x = 2, y = 20;
	int formWidth = 60;
	int formHeight = 15;
	int xForm = WallWidth / 2 - formWidth / 4;
	int yForm = WallHeight / 2 - formHeight / 2;
	drawFormInput(xForm + 3, yForm + 1, formHeight, formWidth, title);

	SetColor(clblack, cllightwhite);
	LISTCOL newListCol = ListColLopSV();
	
		gotoxy(xForm + 6, y);
		cout << newListCol.infoCol[1]->nameCol;
		drawButton(xForm + formWidth / 2 - 10, y - 1, 40);


	deleteListCol(newListCol);
}

void formNhapMa_SV()
{
	int x = 2, y = 20;
	int formWidth = 40;
	int formHeight = 8;
	int xForm = WallWidth / 2 - formWidth / 4;
	int yForm = WallHeight / 2 - formHeight / 2;
	drawFormInput(xForm + 3, yForm + 1, formHeight, formWidth,"");
	gotoxy(xForm+14, y );
	cout << "Nhap ma sinh vien";

	drawButton(xForm + formWidth / 2 - 10, y + 2, 25);
}

void formThem_MH(string title)
{
	int x = 2, y = 16;
	int formWidth = 70;
	int formHeight = 25;
	int xForm = WallWidth / 2 - formWidth / 4;
	int yForm = WallHeight / 2 - formHeight / 2 ;
	drawFormInput(xForm+3, yForm+1, formHeight, formWidth, title);
	
	//cout << xForm << " " << yForm;

	SetColor(clblack, cllightwhite);
	LISTCOL newListCol = ListColMonHoc();
	for (int i = 1; i < newListCol.numOfCol; i++)
	{
		gotoxy(xForm + 10, y);
		cout << newListCol.infoCol[i]->nameCol;
		drawButton(xForm + formWidth / 2 - 7, y -1, 40);

		y += 3;
	}

	
	deleteListCol(newListCol);
}


void formThem_LTC(string title)
{
	int x = 2, y = 10;
	int formWidth = 66;
	int formHeight = 36;
	int xForm = WallWidth / 2 - formWidth / 4;
	int yForm = WallHeight / 2 - formHeight / 2;
	drawFormInput(xForm + 3, yForm +1, formHeight, formWidth, title);

	//cout << xForm << " " << yForm;

	SetColor(clblack, cllightwhite);
	LISTCOL newListCol = ListColLopTC();
	for (int i = 1; i < newListCol.numOfCol; i++)
	{
		gotoxy(xForm + 10, y);
		cout << newListCol.infoCol[i]->nameCol;
		drawButton(xForm + formWidth / 2 - 10, y - 1, 40);

		y += 3;
	}


	deleteListCol(newListCol);
}

void draw_Table(int numOfRow, LISTCOL newListCol)
{
	int x = xTable, y = yTable;
	
	// hang so 0 la hang tieu de, du lieu bat dau tu hang 1 -> numOfRow
	for (int jRow = 0; jRow <= numOfRow; jRow++)
	{
		for (int iCol = 0; iCol < newListCol.numOfCol; iCol++)
		{
			int iWidthCol = newListCol.infoCol[iCol]->widthCol;
			SetColor(clblack, cllightwhite);

			if (iCol == 0 && jRow == 0)
			{
				gotoxy(x, y);
				cout << char(218);
			}

			gotoxy(x + 1, y);
			for (int i = 0; i < iWidthCol; i++) cout << char(196);


			if (iCol + 1 == newListCol.numOfCol && jRow == 0)
			{
				cout << char(191);
			}
			else if (jRow == 0)
			{
				cout << char(194);
			}

			gotoxy(x, y + 1);
			cout << char(179);

			SetColor(cllightwhite, cllightwhite);
			for (int i = 1; i <= iWidthCol; i++)
			{
				gotoxy(x + i, y + 1);
				cout << char(219);
			}
			SetColor(clblack, cllightwhite);

			if (jRow == 0)
			{
				gotoxy(x + iWidthCol / 2 - newListCol.infoCol[iCol]->nameCol.length() / 2 + 1, y + 1);
				cout << newListCol.infoCol[iCol]->nameCol;
			}

			gotoxy(iWidthCol + x + 1, y + 1);
			cout << char(179);

			gotoxy(x, y + 2);
			if (iCol == 0 && jRow == numOfRow)
			{
				cout << char(192);
			}
			else if (iCol == 0)
			{
				cout << char(195);
			}

			gotoxy(x + 1, y + 2);
			for (int i = 0; i < iWidthCol; i++) cout << char(196);

			if (iCol + 1 == newListCol.numOfCol && jRow == numOfRow)
			{
				cout << char(217);
			}
			else if (jRow == numOfRow)
			{
				cout << char(193);
			}
			else if (iCol + 1 == newListCol.numOfCol)
			{
				cout << char(180);
			}
			else
			{
				cout << char(197);
			}

			x += iWidthCol + 1;
		}

		x = xTable, y += 2;
	}
}

void delete_Table(int numOfRow, LISTCOL newListCol)
{
	int x = xTable, y = yTable;
	SetColor(cllightwhite, cllightwhite);
	// hang so 0 la hang tieu de, du lieu bat dau tu hang 1 -> numOfRow
	for (int jRow = 0; jRow <= numOfRow; jRow++)
	{
		for (int iCol = 0; iCol < newListCol.numOfCol; iCol++)
		{
			int iWidthCol = newListCol.infoCol[iCol]->widthCol;
			

			if (iCol == 0 && jRow == 0)
			{
				gotoxy(x, y);
				cout << char(218);
			}

			gotoxy(x + 1, y);
			for (int i = 0; i < iWidthCol; i++) cout << char(219);


			if (iCol + 1 == newListCol.numOfCol && jRow == 0)
			{
				cout << char(191);
			}
			else if (jRow == 0)
			{
				cout << char(194);
			}

			gotoxy(x, y + 1);
			cout << char(219);

			
			for (int i = 1; i <= iWidthCol; i++)
			{
				gotoxy(x + i, y + 1);
				cout << char(219);
			}
			

			/*if (jRow == 0)
			{
				gotoxy(x + iWidthCol / 2 - newListCol.infoCol[iCol]->nameCol.length() / 2 + 1, y + 1);
				cout << newListCol.infoCol[iCol]->nameCol;
			}*/

			gotoxy(iWidthCol + x + 1, y + 1);
			cout << char(219);

			gotoxy(x, y + 2);
			if (iCol == 0 && jRow == numOfRow)
			{
				cout << char(219);
			}
			else if (iCol == 0)
			{
				cout << char(219);
			}

			gotoxy(x + 1, y + 2);
			for (int i = 0; i < iWidthCol; i++) cout << char(219);

			if (iCol + 1 == newListCol.numOfCol && jRow == numOfRow)
			{
				cout << char(219);
			}
			else if (jRow == numOfRow)
			{
				cout << char(219);
			}
			else if (iCol + 1 == newListCol.numOfCol)
			{
				cout << char(219);
			}
			else
			{
				cout << char(219);
			}

			x += iWidthCol + 1;
		}

		x = xTable, y += 2;
	}

	
}

void formNhap_SV(int numOfRow, LISTCOL newListCol, int num)
{
	int x = xTable, y = yTable+2*num;

	
	for (int jRow = 0; jRow < numOfRow; jRow++)
	{
		for (int iCol = 0; iCol < newListCol.numOfCol; iCol++)
		{
			int iWidthCol = newListCol.infoCol[iCol]->widthCol;
			SetColor(clblack, cllightwhite);

			if (iCol == 0)
			{
				gotoxy(x, y);
				cout<<char(195);
			}

			gotoxy(x + 1, y);
			for (int i = 0; i < iWidthCol; i++) cout << char(196);

			if (iCol + 1 == newListCol.numOfCol && jRow == 0)
			{
				cout << char(180);
			}
			else if (jRow == 0)
			{
				cout << char(197);
			}
			
			gotoxy(x, y + 1);
			cout << char(179);
			
			SetColor(cllightwhite, cllightwhite);
			for (int i = 1; i <= iWidthCol; i++)
			{
				gotoxy(x + i, y + 1);
				cout << char(219);
			}
			SetColor(clblack, cllightwhite);
			

			gotoxy(iWidthCol + x + 1, y + 1);
			cout << char(179);
			
			gotoxy(x, y + 2);
			if (iCol == 0 && jRow == numOfRow-1)
			{
				cout << char(192);
			}
			else if (iCol == 0)
			{
				cout << char(195);
			}

			gotoxy(x + 1, y + 2);
			for (int i = 0; i < iWidthCol; i++) cout << char(196);

			if (iCol + 1 == newListCol.numOfCol && jRow == numOfRow-1)
			{
				cout << char(217);
			}
			else if (jRow == numOfRow-1)
			{
				cout << char(193);
			}
			else if (iCol + 1 == newListCol.numOfCol)
			{
				cout << char(180);
			}
			else
			{
				cout << char(197);
			}

			x += iWidthCol + 1;
		}

		x = xTable, y += 2;
	}
}

void formThem_SV(string title)
{
	LISTCOL newListCol = ListColSV();
	draw_Table(0, newListCol);
	formNhap_SV(1, newListCol,1);

	deleteListCol(newListCol);
}



void veKhungChinh()
{
	SetColor(cllightblue, cllightwhite);

	// ve tuong doc
	int x = 1; int y = 0;
	while (y <= WallHeight)
	{
		gotoxy(x, y);
		cout << char(219);
		gotoxy(WallWidth, y);
		cout << char(219);

		// chia khung 2 thanh 2 phan
		gotoxy(LeftSideBar, y);
		cout << char(219);

		y++;
	}

	// ve tuong ngang
	x = 1, y = 0;
	while (x <= WallWidth)
	{
		gotoxy(x, y);
		cout << char(220);
		gotoxy(x, WallHeight);
		cout << char(223);

		x++;
	}

	x = 2;
	y = WallHeight / 2;
	while (x < LeftSideBar)
	{
		gotoxy(x, y);
		cout << char(205);
		x++;
	}

	SetColor(cllightwhite, clyellow);

	string titleContent;

	titleContent = "  CHUC NANG  ";
	gotoxy(LeftSideBar / 2 - titleContent.length() / 2, yTitleContent);
	cout << titleContent;
	titleContent = "  HUONG DAN  ";
	gotoxy(LeftSideBar / 2 - titleContent.length() / 2, WallHeight / 2 + yTitleContent);
	cout << titleContent;

	SetBGColor(cllightwhite);
}

void printInfo()
{
	gotoxy(80, 35);
	SetColor(cllightwhite, cllightred);
	cout << " NGUYEN TRUNG DUC - N19DCCN040 - D19CQCN03-N ";
	SetColor(cllightwhite, cllightwhite);
}

void loadLogo()
{
	string duLieuMotHang;
	ifstream fileIn;
	fileIn.open("data\\logo1.txt", ios_base::in);
	if (fileIn.is_open())
	{
		int dong = 10;
		SetColor(cllightblue, cllightwhite);
		while (!fileIn.eof())
		{
			getline(fileIn, duLieuMotHang);
			gotoxy(43, dong);
			char kiTu;
			for (int i = 0; i < duLieuMotHang.length(); i++)
			{
				if (duLieuMotHang[i] == '#')
				{
					duLieuMotHang[i] = 219;
				}
			}
			cout << duLieuMotHang;
			if (fileIn.eof())
			{
				break;
			}
			dong++;
		}
		printInfo();
	}
	else return;
	fileIn.close();
}

void reset_View()
{
	int x = LeftSideBar + 1, y = 1;

	SetColor(cllightwhite, cllightwhite);
	for (int i = 0; i < WallHeight-1; i++)
	{
		for (int j = 0; j < WallWidth - x; j++)
		{
			gotoxy(x + j, y + i);
			cout << char(219);
		}
	}
	

}



void init_View()
{
	resizeConsole(ConsoleWidth, ConsoleHeight);
	removeScrollbar();
	system("color F0"); // backgroundConsole = lightwhite(F) , colorConsole = black(0)
	veKhungChinh();
	loadLogo();
	printInfo();
	hideCursortype();
}

void printTitle(int x, int y, string title)
{
	gotoxy(x, y);
	cout << title;
}

void menuTitle(string menuTitle[], int pos, int numMENU)
{
	int x = xMENU, y = yMENU;

	for (int i = 0; i < numMENU; i++)
	{

		if (pos == i)
		{

			drawEffectButton(x, y,28);
			SetColor(cllightwhite, clgreen);
			printTitle(LeftSideBar / 2 - menuTitle[i].length() / 2, y + 1, menuTitle[i]);
			SetColor(clblack, cllightwhite);
		}
		else
		{
			drawButton(x, y,28);
			printTitle(LeftSideBar / 2 - menuTitle[i].length() / 2, y + 1, menuTitle[i]);
		}

		y += disMEMU;
	}
}



int chonMenu(int numMENU, int pos, string title[])
{
	int key;
	while (true)
	{
		menuTitle(title, pos, numMENU);
		key = GetKey();

		if (key == UP)
		{
			--pos;
			if (pos < 0)
			{
				pos = numMENU - 1;
			}
			//return pos;
		}
		else if (key == DOWN)
		{
			++pos;
			if (pos == numMENU)
			{
				pos = 0;
			}
			//return pos;
		}
		else if (key == ESC)
		{
			return -1;
		}
		else if (key == ENTER)
		{
			return pos;
		}


	}
}


void clearMenuTitle(int numMENU)
{

	int x = xMENU, y = yMENU;
	for (int i = 1; i < LeftSideBar - 2; i++)
	{

		for (int j = 0; j < numMENU * disMEMU; j++)
		{
			gotoxy(x, y + j);
			cout << " ";
		}
		x++;
	}
}


/* =================== HUONG DAN =======================*/

void xoaHuongDan()
{
	SetColor(cllightwhite, cllightwhite);
	
	for (int i = 25; i < 40; i++)
	{
		for (int j = 4; j < 34; j++)
		{
			gotoxy( j, i);
			cout << char(219);
		}
	}
}

void xuatHD(const wchar_t* str)
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	wcout << str;
	_setmode(_fileno(stdout), _O_TEXT);
}

void huongDanMenuChinh()
{
	SetColor(clblack, cllightwhite);
	gotoxy(4, 25);
	cout << "Di chuyen bang mui ten";
	gotoxy(4, 26);
	xuatHD(L"\u2191 : Len");
	gotoxy(4, 27);
	xuatHD(L"\u2193 : Xuong");
	gotoxy(4, 28);
	cout << "Nhan Enter de chon";
	gotoxy(4, 29);
	cout << "Nhan Esc de thoat";

}


void huongDanMenuCon()
{
	SetColor(clblack, cllightwhite);
	gotoxy(4, 25);
	cout << "Di chuyen bang mui ten";
	gotoxy(4, 26);
	xuatHD(L"\u2191 : Len");
	gotoxy(4, 27);
	xuatHD(L"\u2193 : Xuong");
	gotoxy(4, 28);
	cout << "Nhan Enter de chon";
	gotoxy(4, 29);
	cout << "Nhan Esc de ve menu chinh";
}


void huongDanChon()
{
	SetColor(clblack, cllightwhite);
	gotoxy(4, 25);
	cout << "Di chuyen bang mui ten";
	gotoxy(4, 26);
	xuatHD(L"\u2191 : Len");
	gotoxy(4, 27);
	xuatHD(L"\u2193 : Xuong");
	gotoxy(4, 28);
	xuatHD(L"\u2190 \u2192 : xem trang khac");
	gotoxy(4, 29);
	cout << "Nhan Enter de chon";
	gotoxy(4, 30);
	cout << "Nhan Esc de quay lai";
}

