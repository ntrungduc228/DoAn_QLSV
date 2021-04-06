#pragma once
#include"myLib.h"
#include"functions.h"

void xuLyNhapDiem(string& so, int x, int& y);
void xuLyNhapChuoi(string& str, int maxLengStr, int x, int& y);
void xuLyNhapSo(int& so, int maxLeng, int x, int& y);
void xuLyNhapHo(string& TEN, int maxLengName, int x, int& y);
void xuLyNhapTen(string& TEN, int maxLengName, int x, int& y);
void xuLyNhapMa(string& MA, int maxLeng, int x, int& y);
void xuLyNhapMaLop(string& MA, int maxLeng, int x, int& y);



/*
		======================== DINH NGHIA HAM ==================================
*/

void xuLyNhapDiem(string &so,int x, int& y)
{
	int maxLeng = 3;
	string str = so;
	
	char c; int xTemp=x;
	
	while (true)
	{
		c = _getch();
		if (((c >= 48 && c <= 57) || c == '.') && str.length() < maxLeng)
		{

			if (str.length() > 1)
			{
				if (str[str.length() - 1] != '.')
				{
					continue;
				}
			}
			else if (str.length() > 0)
			{
				if ((str[str.length() - 1] == '1' && c != '0' && c != '.') || (str[str.length() - 1] != '1' && c != '.'))
				{
					continue;
				}
			}

			gotoxy(++xTemp, y);
			cout << c;
			str.insert(str.end(), c);
		}
		else if (c == ENTER && str.length() > 0 && str[0]!=NULL)
		{
			y= whereY() + 3;
			so = str;
			break;
		}
		else if (c == ESC)
		{
			y = 0;
			break;
		}
		else if (c == BACKSPACE && str.length() > 0)
		{
			str.erase(str.length() - 1, 1);
			gotoxy(xTemp, whereY());
			cout << " ";
			if(xTemp - 1 >=x-1 )
			gotoxy(xTemp--, whereY());

		}
		else if (c == F4)
		{
			so = str;
			y = 4;
			break;
		}
		else if (c == -32)
		{
			c = _getch();
			if (c == DOWN && str[0] != NULL)
			{
				y=whereY() + 3;
				break;
			}
			else if (c == UP && str[0] != NULL)
			{
				y = whereY() - 3;
				break;
			}
			else if (c == LEFT && str[0] != NULL)
			{
				y = 1;
				break;
			}
			else if (c == RIGHT && str[0] != NULL)
			{
				y = 2;
				break;
			}
			
		}

	}

	so = str;
	/*if (!str.empty())
		so = stoi(str.c_str());*/
}

void xuLyNhapChuoi(string& str, int maxLengStr, int x, int& y)
{
	//string str=""; 
	char c;
	int xTemp = x-1;
	
	

	while (true)
	{
		c = _getch();
		if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57) || c == SPACE) && str.length() < maxLengStr)
		{
			if (str.length() == 0)
			{
				c = toupper(c);
			}
			else if (c == SPACE)
			{
				if (str[str.length() - 1] == SPACE)
					continue;
			}
			else {
				c = tolower(c);
			}

			gotoxy(++xTemp, y);
			cout << c;
			str.insert(str.end(), c);
		}
		else if (c == ENTER && str.length() > 0)
		{
			y = whereY() + 3;
			break;
		}
		else if (c == BACKSPACE && str.length() > 0)
		{
			str.erase(str.length() - 1, 1);
			gotoxy(xTemp, whereY());
			cout << " ";
			gotoxy(xTemp--, whereY());

		}
		else if (c == ESC)
		{
			y = 0;
			break;
		}
		else if (c == -32)
		{
			c = _getch();
			if (c == DOWN && whereY() + 3)
			{
				y = whereY() + 3;
				break;
			}
			else if (c == UP)
			{

				y = whereY() - 3;
				break;
			}
			
		}

	}
	///return str;
}


void xuLyNhapSo(int &so,int maxLeng, int x, int& y)
{
	string str; 
		str = to_string(so);
	char c;
	int xTemp = x ;
	while (true)
	{
		c = _getch();
		if ((c >= 48 && c <= 57) && str.length() < maxLeng)
		{

			gotoxy(++xTemp, y);
			cout << c;
			str.insert(str.end(), c);
		}
		else if (c == ENTER && str.length() > 0)
		{
			y= whereY() +3;
			break;
		}
		else if (c == BACKSPACE && str.length()>0)
		{
			str.erase(str.length() - 1, 1);
			gotoxy(xTemp, whereY());
			cout << " ";
			gotoxy(xTemp--, whereY());

		}
		else if (c == ESC)
		{
			y = 0;
			break;
		}
		else if (c == -32)
		{
			c = _getch();
			if (c == DOWN && str.length() > 0)
			{
				y=whereY()+3;
				break;
			}
			else if (c == UP)
			{
				y = whereY() - 3;
				break;
			}
			

		}

	}

	
	if (!str.empty())
		so = stoi(str.c_str());
}


void xuLyNhapHo(string &TEN,int maxLengName, int x, int& y)
{
	 char c;
	int xTemp = x - 1;
	while (true)
	{
		c = _getch();
		if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == SPACE) && TEN.length() < maxLengName)
		{
			if (TEN.length() == 0|| TEN[TEN.length() - 1] == SPACE)
			{
				c = toupper(c);
			}
			else if (c == SPACE)
			{
				if (TEN[TEN.length() - 1] == SPACE)
					continue;
			}
			else {
				c = tolower(c);
			}

			gotoxy(++xTemp, y);
			cout << c;
			TEN.insert(TEN.end(), c);
		}
		else if (c == ENTER && TEN.length() > 0)
		{
			y =whereY() + 3;
			break;
		}
		else if (c == BACKSPACE && TEN.length()>0)
		{
			TEN.erase(TEN.length() - 1, 1);
			gotoxy(xTemp, whereY());
			cout << " ";
			gotoxy(xTemp--, whereY());

		}
		else if (c == ESC)
		{
			y = 0;
			break;
		}
		else if (c == -32)
		{
			c = _getch();
			if (c == DOWN && TEN.length()>0 )
			{
				y = whereY() + 3;
				break;
			}
			else if (c == UP)
			{
				y = whereY() - 3;
				break;
			}
			
		}

	}
	
}

void xuLyNhapTen(string& TEN, int maxLengName, int x, int& y)
{
	char c;
	int xTemp = x - 1;
	while (true)
	{
		c = _getch();
		if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122) ) && TEN.length() < maxLengName)
		{
			if (TEN.length() == 0)
			{
				c = toupper(c);
			}
			else {
				c = tolower(c);
			}

			gotoxy(++xTemp, y);
			cout << c;
			TEN.insert(TEN.end(), c);
		}
		else if (c == ENTER && TEN.length() > 0)
		{
			y = whereY() + 3;
			break;
		}
		else if (c == BACKSPACE && TEN.length() > 0)
		{
			TEN.erase(TEN.length() - 1, 1);
			gotoxy(xTemp, whereY());
			cout << " ";
			gotoxy(xTemp--, whereY());

		}
		else if (c == ESC)
		{
			y = 0;
			break;
		}
		else if (c == -32)
		{
			c = _getch();
			if (c == DOWN && TEN.length() > 0)
			{
				y = whereY() + 3;
				break;
			}
			else if (c == UP)
			{
				y = whereY() - 3;
				break;
			}

		}

	}

}

void xuLyNhapMa(string &MA,int maxLeng, int x, int& y)
{
	 char c;
	int xTemp = x - 1;
	while (true)
	{

		c = _getch();
		if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57)) && MA.length() < maxLeng)
		{
			c = toupper(c);

			gotoxy(++xTemp, y);
			cout << c;
			MA.insert(MA.end(), c);
		}
		else if (c == ENTER && MA.length() > 0)
		{
			y = whereY() + 3;
			break;
		}
		else if (c == BACKSPACE && MA.length()>0)
		{
			MA.erase(MA.length() - 1, 1);
			gotoxy(xTemp, whereY());
			cout << " ";
			gotoxy(xTemp--, whereY());

		}
		else if (c == ESC)
		{
			y = 0;
			break;
		}
		else if (c == -32)
		{
			c = _getch();
			if (c == DOWN && MA.length() > 0)
			{
				y = whereY() + 3;
				break;
			}
			else if (c == UP)
			{
				y = whereY() - 3;
				break;
			}
			
			
		}

	}
	x = xTemp;
	
	
}


void xuLyNhapMaLop(string& MA, int maxLeng, int x, int& y)
{
	char c;
	int xTemp = x - 1;
	while (true)
	{

		c = _getch();
		if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57) || c=='-') && MA.length() < maxLeng)
		{
			c = toupper(c);

			gotoxy(++xTemp, y);
			cout << c;
			MA.insert(MA.end(), c);
		}
		else if (c == ENTER && MA.length() > 0)
		{
			y = whereY() + 3;
			break;
		}
		else if (c == BACKSPACE && MA.length() > 0)
		{
			MA.erase(MA.length() - 1, 1);
			gotoxy(xTemp, whereY());
			cout << " ";
			gotoxy(xTemp--, whereY());

		}
		else if (c == ESC)
		{
			y = 0;
			break;
		}
		else if (c == -32)
		{
			c = _getch();
			if (c == DOWN && MA.length() > 0)
			{
				y = whereY() + 3;
				break;
			}
			else if (c == UP)
			{
				y = whereY() - 3;
				break;
			}


		}

	}
	x = xTemp;


}