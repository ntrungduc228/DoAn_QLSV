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
#include<iomanip>
#include"view.h"
using namespace std;


const int MAXLOPTC = 1000;
const int MAXLOPSV = 200;
const int maxDong1Trang = 15;
const int maxCotMH1Trang = 6;
int soLuong_MH = 0;

/*
=========================================================================
===================== Cau truc Danh sach sinh vien ======================
=========================================================================
*/


struct sinhvien
{
	string MASV;
	string HO;
	string TEN;
	string PHAI;
	string SDT;
	string MALOP;
};
typedef struct sinhvien SINHVIEN;

struct NodeSV
{
	SINHVIEN data;
	struct NodeSV* pNext;
};
typedef struct NodeSV NODESV;


struct listSV
{
	NODESV* pHead;
	NODESV* pTail;
		
};
typedef struct listSV LISTSV; /* cau truc dung de quan li danh sach sinh vien */
/*
=========================================================================
===================== Ket thuc danh sach sinh vien ======================
=========================================================================
*/


/*
=========================================================================
====================== Cau truc Danh sach Lop hoc =======================
=========================================================================
*/

struct LopSV
{
	int soLuongSV;
	string MALOP;
		
	LISTSV DSSV;
};
typedef struct LopSV LOPSV;

struct listLop
{
	int n = 0;
	LOPSV Lop[MAXLOPSV];
};
typedef struct listLop LISTLOP;

/*
=========================================================================
====================== Ket thuc danh sach Lop hoc =======================
=========================================================================
*/





/*
=========================================================================
====================== Cau truc Danh sach mon hoc =======================
=========================================================================
*/

struct monhoc
{
	string MAMH;
	string TENMH;
	int STCLT;
	int STCTH;
};
typedef struct monhoc MONHOC;

struct NodeMH
{
	MONHOC data;
	struct NodeMH* pLeft;
	struct NodeMH* pRight;
};
typedef struct NodeMH NODEMH;
typedef struct NodeMH* TREE; /* cau truc dung de quan li danh sach mon hoc */

/*
=========================================================================
====================== Ket thuc Danh sach mon hoc =======================
=========================================================================
*/





/*
=========================================================================
====================== Cau truc Danh sach dang ky =======================
=========================================================================
*/

struct dangky
{
	string MASV;
	float DIEM=0;
};
typedef struct dangky DANGKY;

struct NodeDK
{
	DANGKY data;
	struct NodeDK* pNext;
};
typedef struct NodeDK NODEDK;

struct ListDK
{
	NODEDK* pHead;
	NODEDK* pTail;
};
typedef struct ListDK LISTDK;





/*
=========================================================================
====================== Ket thuc Danh sach dang ky =======================
=========================================================================
*/


/*
=========================================================================
========================= Cau truc lop tin chi ==========================
=========================================================================
*/

struct lopTC
{
	int MALOPTC;
	string MAMH;
	int KHOA;
	int HOCKY;
	int NHOM;
	int SVMAX;

		
	LISTDK DSDK;
};
typedef struct lopTC LOPTC;

struct ListLopTC
{
	int n = 0;
	LOPTC* LopTC[MAXLOPTC];
};
typedef struct ListLopTC LISTLOPTC;

/*
=========================================================================
==================== Ket thuc cau truc lop tin chi ======================
=========================================================================
*/





/*====================== KHAI BAO NGUYEN MAU HAM ========================*/

/*
=========================================================================
========================= Phan xu ly Sinh vien ==========================
=========================================================================
*/


NODESV* taoNode_SV();
int timviTri_SV(LISTSV DSSV, NODESV* SV);
int tim_SV(LISTSV DSSV, string MASV);
NODESV* layInfo_SV(LISTSV DSSV, int viTriLay);
void themVaoDau_SV(LISTSV& DSSV, NODESV* SV);
void themVaoCuoi_SV(LISTSV& DSSV, NODESV* SV);
void them_SV(LISTSV& DSSV, NODESV* SV, int viTriThem);
void xoaDau_SV(LISTSV& DSSV);
void xoaCuoi_SV(LISTSV& DSSV);
void xoa_SV(LISTSV& DSSV, string MASV);
void free_SV(LISTSV& DSSV);
void chinhSua_SV(LISTSV& DSSV, NODESV* SV);
void nhap_SV(LOPSV& LSV, LISTSV& DSSV, SINHVIEN& SV, int luaChon);
void xuatDS1Trang_SV(LISTSV DSSV, LOPSV LSV, int batDau, int ketThuc, LISTCOL newListCol, int luaChon, int& viTriChon);
void xuatDSTheoTrang_SV(LISTSV DSSV, LOPSV LSV, int luaChon, int& viTriChon);
void chon_SV(LISTSV& DSSV, LOPSV LSV, int luaChon);


/*
=========================================================================
======================= Ket thuc xu ly Sinh vien ========================
=========================================================================
*/



/*
=========================================================================
========================== Phan xu ly Mon hoc ===========================
=========================================================================
*/

bool isEmptyTree_MH(TREE DSMH);
void tim_MH(TREE DSMH, string MAMH, string& TENMH);
void them_MH(TREE& DSMH, MONHOC MH);
void chinhSua_MH(TREE& DSMH, MONHOC MH);
void nhap_MH(TREE& DSMH, MONHOC& MH, int luaChon);
void timNodeTheMang_MH(TREE& temp, TREE& DSMH);
void xoa_MH(TREE& DSMH, string MAMH);
void free_MH(TREE& DSMH);
void chuyenCaythanhMang_MH(TREE DSMH, MONHOC* ArrMH, int& n);
void sapXepTen_MH(MONHOC* ArrMH, int& n); // Selection Sort
void xuatDS1Trang_MH(MONHOC* ArrMH, int batDau, int ketThuc, LISTCOL newListCol, int luaChon, int& viTriChon);
void xuatDSTheoTrang_MH(MONHOC* ArrMH, int tongSoDong, int luaChon, int& viTriChon);
void chon_MH(TREE& DSMH, int luaChon);


/*
=========================================================================
======================== Ket thuc xu ly mon hoc =========================
=========================================================================
*/



/*
=========================================================================
========================== Phan xu ly Dang ky ===========================
=========================================================================
*/


NODEDK* taoNode_DK();
int timViTri_DK(LISTDK DSDK, NODEDK* DK);
int timSV_DK(LISTDK DSDK, string MASV);
void themVaoDau_DK(LISTDK& DSDK, NODEDK* DK);
void themVaoCuoi_DK(LISTDK& DSDK, NODEDK* DK);
void them_DK(LISTDK& DSDK, NODEDK* DK, int viTriThem);
void luuDiemDS_DK(LISTDK& DSDK, LISTDK& DSDIEM);
void free_DK(LISTDK& DSDK);
bool checkDK_LTC(LISTLOPTC DSLTC, string MAMH, string MASV);
NODESV* layInfoSV_LSV(LISTLOP DSLSV, string MASV);
void xuatDSLTC1Trang_DK(LISTLOPTC DSLTC, TREE DSMH, int batDau, int ketThuc, LISTCOL newListCol, string MASV, int& viTriChon);
void xuatDSLTCTheoTrang_DK(LISTLOPTC DSLTC, TREE DSMH, string MASV, int& viTriChon);
void dangKyLTC_SV(LISTLOPTC& DSLTC, TREE DSMH, LISTLOP DSLSV);
void thongKeDS_DK(LISTDK DSDK, LISTLOP DSLSV, LISTSV& DSSVDK, int& soLuong);
void thongKeDiemDS_DK(LISTDK DSDK, LISTLOP DSLSV, LISTSV& DSSVDK, LISTDK& DSDIEM, int& soLuong);
void thongKeDSDiemTB_SV(LISTSV DSSV, LISTLOPTC DSLTC, LISTDK& DSDIEM, int& soLuong);
void thongKeDSDiemTK_SV(LISTSV DSSV, LISTLOPTC DSLTC, LISTDK& DSDIEM, string MAMH, int& soLuong);
void xuatDS_DK(LISTDK DSDK, LISTLOP DSLSV);
void xuatDS1Trang_DK(LISTSV DSSV, int batDau, int ketThuc, LISTCOL newListCol);
void xuatDSTheoTrang_DK(LISTDK DSDK, LISTLOP DSLSV);
void nhapDS1Trang_Diem(LISTSV DSSV, LISTDK& DSDK, int batDau, int ketThuc, LISTCOL newListCol, char& key);
void nhapDSTheoTrang_Diem(LISTDK& DSDK, LISTLOP DSLSV);
void xuatDS1Trang_Diem(LISTSV DSSV, LISTDK DSDK, int batDau, int ketThuc, LISTCOL newListCol);
void xuatDSTheoTrang_Diem(LISTDK DSDK, LISTLOP DSLSV);
void xuatDSTheoTrang_DiemTB(LISTSV DSSV, LISTLOPTC DSLTC);
void xuatDS1Trang_DiemTK(LISTSV DSSV, LISTLOPTC DSLTC, LOPSV LSV, int batDau, int ketThuc, MONHOC* ArrMH, int batDauMH, int ketThucMH, LISTCOL newListCol);



/*
=========================================================================
======================== Ket thuc xu ly dang ky =========================
=========================================================================
*/






/*
=========================================================================
======================== Phan xu ly DS 1 Lop SV =========================
=========================================================================
*/

bool isFull_LSV(LISTLOP DSLSV);
bool them_LSV(LISTLOP& DSLSV, LOPSV Lop);
int timMaLop_LSV(LISTLOP& DSLSV, string MALOP);
void nhap_LSV(LISTLOP& DSLSV);
void xuatDS1Trang_LSV(LISTLOP DSLSV, int batDau, int ketThuc, LISTCOL newListCol, int luaChon, int& viTriChon);
void xuatDSTheoTrang_LSV(LISTLOP DSLSV, int luaChon, int& viTriChon);
void chon_LSV(LISTLOP& DSLSV, LISTLOPTC DSLTC, TREE DSMH, int luaChon);


/*
=========================================================================
===================== Ket thuc xu ly DS 1 Lop SV ========================
=========================================================================
*/




/*
=========================================================================
========================== Phan xu ly Lop TC ============================
=========================================================================
*/

bool isNull_LTC(LISTLOPTC DSLTC);
bool isNull_LTC(LISTLOPTC DSLTC);
LOPTC* tao_LTC();
int them_LTC(LISTLOPTC& DSLTC, LOPTC* LTC);
void hoanVi_LTC(LOPTC* a, LOPTC* b);
void sapXep_LTC(LISTLOPTC& DSLTC, TREE DSMH); // Selection Sort;
int timMaLop_LTC(LISTLOPTC DSLTC, int maLopTC);
void freeDS_LTC(LISTLOPTC& DSLTC);
int checkMaLop_LTC(LISTLOPTC& DSLTC, int maLop);
void chinhSua_LTC(LISTLOPTC& DSLTC, LOPTC* LTC);
void xoa_LTC(LISTLOPTC& DSLTC, int maLop);
bool checkTrungMaLop_LTC(LISTLOPTC DSLTC, int maLop);
int taoMaLop_LTC();
MONHOC chonMH_LTC(TREE& DSMH);
void nhap_LTC(LISTLOPTC& DSLTC, TREE DSMH, LOPTC* LTC, int luaChon);
void xuatDS1Trang_LTC(LISTLOPTC DSLTC, TREE DSMH, int batDau, int ketThuc, LISTCOL newListCol, int luaChon, int& viTriChon);
void xuatDSTheoTrang_LTC(LISTLOPTC DSLTC, TREE DSMH, int luaChon, int& viTriChon);
void chon_LTC(LISTLOPTC& DSLTC, TREE DSMH, LISTLOP DSLSV, int luaChon);

/*
=========================================================================
======================== Ket thuc xu ly lop TC ==========================
=========================================================================
*/







/*=========================== DINH NGHIA HAM ============================*/



/*
=========================================================================
========================= Phan xu ly Sinh vien ==========================
=========================================================================
*/

NODESV* taoNode_SV()
{
	NODESV* SV = new NODESV;
	SV->pNext = NULL;
	return SV;
}

int timviTri_SV(LISTSV DSSV, NODESV *SV )
{
	int viTri = 1;

		NODESV* k = DSSV.pHead;
		while (k!=NULL&&k->data.TEN<=SV->data.TEN)
		{
			if (k->data.TEN == SV->data.TEN)
			{
				while (k != NULL && k->data.HO < SV->data.HO)
				{

					viTri++;
					k = k->pNext;
				}
				return viTri;

			}
			viTri++;
			k = k->pNext;
		}
	return viTri;
}

int tim_SV(LISTSV DSSV, string MASV)
{
	int viTri = 1;
	if (DSSV.pHead != NULL);
	for (NODESV* k = DSSV.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.MASV == MASV) return viTri;
		else viTri++;
	}
		return -1;
}

NODESV* layInfo_SV(LISTSV DSSV, int viTriLay)
{
	if (DSSV.pHead != NULL)
	{
		NODESV* SV = new NODESV;

		int viTri = 1;

		for (NODESV* k = DSSV.pHead; k != NULL; k = k->pNext)
		{
			if (viTri == viTriLay)
			{
				SV->data.MASV = k->data.MASV;
				SV->data.MALOP = k->data.MALOP;
				SV->data.HO = k->data.HO;
				SV->data.TEN = k->data.TEN;
				SV->data.PHAI = k->data.PHAI;
				SV->data.SDT = k->data.SDT;
				SV->pNext = k->pNext;

				return SV;
			}
			viTri++;
		}
	}
	return NULL;
}

void themVaoDau_SV(LISTSV& DSSV, NODESV* SV)
{	
	if (DSSV.pHead == NULL)
	{
		DSSV.pHead = DSSV.pTail = SV;
	}
	else
	{
		SV->pNext = DSSV.pHead; 
		DSSV.pHead = SV; 
	}
		
}

void themVaoCuoi_SV(LISTSV& DSSV, NODESV* SV)
{
	if (DSSV.pHead == NULL)
	{
		DSSV.pHead = DSSV.pTail = SV;
	}
	else
	{
		DSSV.pTail->pNext = SV;
		DSSV.pTail = SV; 
	}
	
}

void them_SV(LISTSV& DSSV,NODESV* SV, int viTriThem)
{
	int n = 0;
	for (NODESV* k = DSSV.pHead; k != NULL; k = k->pNext) n++;

	if (DSSV.pHead == NULL || viTriThem == 1)
	{
		themVaoDau_SV(DSSV, SV);
		return;
	}
	else if (viTriThem == n + 1)
	{
		themVaoCuoi_SV(DSSV, SV);
		return;
	}
	else
	{
		int viTri=0;
		NODESV* pTrc= taoNode_SV();
		for (NODESV* k = DSSV.pHead; k != NULL; k = k->pNext)
		{
			viTri++;
			if (viTri == viTriThem)
			{
				
				SV->pNext = k;
				pTrc->pNext = SV;
				break;
			}

			pTrc = k;
		}
		return;
	}
}

void xoaDau_SV(LISTSV& DSSV)
{
	if (DSSV.pHead == NULL)
	{
		return;
	}
	NODESV*p = DSSV.pHead; 
	DSSV.pHead = DSSV.pHead->pNext;
	delete p;
}

void xoaCuoi_SV(LISTSV &DSSV)
{

	
	if (DSSV.pHead == NULL)
	{
		return;
	}
	
	if (DSSV.pHead->pNext == NULL)
	{
		xoaDau_SV(DSSV);
		return;
	}
	
	for (NODESV* k = DSSV.pHead; k != NULL; k = k->pNext)
	{
		
		if (k->pNext == DSSV.pTail)
		{
			delete DSSV.pTail; 
			k->pNext = NULL; 
			DSSV.pTail = k; 
			return;
		}
	}
}

void xoa_SV(LISTSV& DSSV, string MASV)
{
	if (DSSV.pHead == NULL)
	{
		return;
	}
	
	if (DSSV.pHead->data.MASV == MASV)
	{
		xoaDau_SV(DSSV);
		return;
	}
	
	if (DSSV.pHead->data.MASV == MASV)
	{
		xoaCuoi_SV(DSSV);
		return;
	}

	NODESV* pTrc = new NODESV; 
	
	for (NODESV* k = DSSV.pHead; k != NULL; k = k->pNext)
	{
		
		if (k->data.MASV == MASV)
		{
			pTrc->pNext = k->pNext; 
			delete k; 
			return;
		}
		pTrc = k; 
	}
}


void free_SV(LISTSV& DSSV)
{
	NODESV* SV = NULL;
	while (DSSV.pHead != NULL)
	{
		SV = DSSV.pHead;
		DSSV.pHead = DSSV.pHead->pNext;
		delete SV;
	}
}

void chinhSua_SV(LISTSV& DSSV, NODESV* SV)
{
	if (DSSV.pHead != NULL)
	{
		for (NODESV* k = DSSV.pHead; k != NULL; k = k->pNext)
		{
			if (k->data.MASV == SV->data.MASV)
			{
				k->data.MASV = SV->data.MASV;
				k->data.HO = SV->data.HO;
				k->data.TEN = SV->data.TEN;
				k->data.PHAI = SV->data.PHAI;
				k->data.SDT = SV->data.SDT;
				k->data.MALOP = SV->data.MALOP;
				
				return;
			}
		}
	}
	else {
		return;
	}
}


void nhap_SV(LOPSV& LSV,LISTSV &DSSV,SINHVIEN &SV, int luaChon)
{
	/*
	luaChon == 1 -> them sinh vien moi
	luaChon == 2 -> sua sinh vien cu
	*/
	int num = 1;
	if (luaChon == 1)
	{
		formThem_SV("Them sinh vien moi");
	}
	else if (luaChon == 2)
		formThem_SV("Sua sinh vien");

	int x = 48, y = 8;
	gotoxy(x, y);
	int xConTro ;
	if (luaChon == 1)
		xConTro = x;
	else if (luaChon == 2)
		xConTro = x + 17;
	int yConTro = y;

NHAP_SV:
	gotoxy(39, yConTro);
	cout << num;
	showCursortype();
	

	gotoxy(x, yConTro);
	cout << SV.MASV;
	gotoxy(x + 17, yConTro);
	cout << SV.HO;
	gotoxy(x + 58, yConTro);
	cout << SV.TEN;
	gotoxy(x + 82, yConTro);
	cout << SV.PHAI;
	gotoxy(x + 97, yConTro);
	if (SV.SDT != "-1")
		cout << SV.SDT;
	else cout << "0";

	
	while (true)
	{
		yConTro = y;
		showCursortype();
		if (xConTro == x && luaChon==1)
		{
			gotoxy(x + SV.MASV.length(), yConTro);
			xuLyNhapMa(SV.MASV, 10, x + SV.MASV.length(), yConTro);
			if (yConTro == y + 3)
			{
				yConTro = y;
				xConTro = x + 17;
				gotoxy(x + SV.HO.length() + 17, yConTro);
			}
			else if (yConTro == y - 3)
			{
				yConTro = y;

			}
			else if (yConTro == 0) return;
		}
			if (xConTro == x + 17)
		{
			gotoxy(x + 17 + SV.HO.length(), yConTro);
			xuLyNhapHo(SV.HO, 21, x +SV.HO.length()+17, yConTro);

			if (yConTro == y + 3)
			{
				yConTro = y;
				xConTro = x + 58;
				gotoxy(x + SV.TEN.length() + 58, yConTro);
			}
			else if (yConTro == y - 3)
			{
				yConTro = y;
				xConTro = x;
			}
			else if (yConTro == 0) return;
		}
			if (xConTro == x + 58)
		{
			
			xuLyNhapTen(SV.TEN, 8, x + SV.TEN.length()+58, yConTro);


			if (yConTro == y + 3)
			{
				yConTro = y;
				xConTro = x + 82;
				gotoxy(x + SV.PHAI.length() + 82, yConTro);
			}
			else if (yConTro == y - 3)
			{
				yConTro = y;
				xConTro = x+17;
			}
			else if (yConTro == 0) return;

		}
			if (xConTro == x + 82)
		{
			
			xuLyNhapTen(SV.PHAI, 3, x + SV.PHAI.length() + 82, yConTro);
			if (yConTro == y + 3)
			{
				yConTro = y;
				xConTro = x + 97;
				gotoxy(x + SV.SDT.length() + 97, yConTro);
			}
			else if (yConTro == y - 3)
			{
				yConTro = y;
				xConTro = x+58;
			}
			else if (yConTro == 0) return;
		}
			if (xConTro == x + 97)
		{
			int so=0;
		
			xuLyNhapSo(so, 11, x + 97, yConTro);
			SV.SDT = to_string(so);

			if (yConTro == y + 3)
			{
				yConTro = y;
				xConTro = x+100;
			}
			else if (yConTro == y - 3)
			{
				yConTro = y;
				xConTro = x+82;
			}
			else if (yConTro == 0) return;
		}
		else if (xConTro == x + 100)
		{
			if (luaChon == 1) // them
			{
				int checkTrung = tim_SV(DSSV, SV.MASV);
				if (checkTrung >0)
				{
					printNotifi(90, 32, "Ma sinh vien bi trung");
						
					nhap_SV(LSV, DSSV, SV, luaChon);
					
				}
				else
				{
					NODESV* NSV = taoNode_SV();
					NSV->data = SV;
					int viTriThem = timviTri_SV(DSSV, NSV);
					them_SV(DSSV, NSV, viTriThem);
					LSV.soLuongSV++;

					LISTCOL newListCol = ListColSV();
					++num;
					formNhap_SV(1, newListCol, num);
					deleteListCol(newListCol);
					xConTro = x;
					
					y = y + 2;
					yConTro = y;
					

					SV.MASV = "";
					SV.HO = "";
					SV.TEN = "";
					SV.PHAI = "";
					SV.SDT = "";
					
					
					goto NHAP_SV;
				}
				
			}
			else if (luaChon == 2) // sua
			{
				NODESV* NSV = taoNode_SV();
				NSV->data = SV;
				chinhSua_SV(DSSV, NSV);

				return;
			}
		}


	}

}


void xuatDS1Trang_SV(LISTSV DSSV, LOPSV LSV, int batDau, int ketThuc, LISTCOL newListCol, int luaChon, int& viTriChon)
{
	int soDong = ketThuc % maxDong1Trang;
	if (soDong == 0) soDong = maxDong1Trang;
	draw_Table(soDong, newListCol);

	int STT = batDau - 1;
	int x = xTable, y = yTable + 3;
	int yConTro = y;
	int i = 0;
	
	NODESV* First = DSSV.pHead;
	for (int j = 0; j < STT+1; j++) First = First->pNext; // chay den STT can xuat

	for (NODESV *k=First ; (k!=NULL) ; k=k->pNext,i++)
	{
		++STT;
		gotoxy(x + round(newListCol.infoCol[0]->widthCol / 2.0), y + i * 2);
		if (luaChon == 1) // xuat STT
			cout << STT + 1;
		else if (luaChon == 2 || luaChon == 3) // xuat mui ten
		{
			if (i == 0)
			{
				cout << "->";
			}
		}


		gotoxy(x + round(newListCol.infoCol[1]->widthCol / 2.0) +1, y + i * 2);
		cout << k->data.MASV;
		gotoxy(x + round(newListCol.infoCol[2]->widthCol / 2.0) + 8, y + i * 2);
		cout << k->data.HO;
		gotoxy(x + 69, y + i * 2);
		cout << k->data.TEN;
		gotoxy(x + 93, y + i * 2);
		cout << k->data.PHAI;
		gotoxy(x + 108, y + i * 2);
		if (k->data.SDT == "-1")cout << "0"; else cout << k->data.SDT;

		if (i == soDong-1) break;
	}
}

void xuatDSTheoTrang_SV(LISTSV DSSV,LOPSV LSV,int luaChon, int& viTriChon)
{
	int tongSoDong = LSV.soLuongSV;
	int soDu = tongSoDong % maxDong1Trang;
	if (soDu > 0) soDu = 1;
	else soDu == 0;

	int soTrang = tongSoDong / maxDong1Trang + soDu;
	int trangHienTai = 1;

	int batDau = 0;
	int ketThuc;
	if (tongSoDong > maxDong1Trang) ketThuc = maxDong1Trang; else ketThuc = tongSoDong;
	LISTCOL newListCol = ListColSV();
	
	xuatDS1Trang_SV(DSSV, LSV, batDau, ketThuc,newListCol ,luaChon, viTriChon);
	xuatTrang(trangHienTai, soTrang);


	int x = xTable, y = yTable + 3;
	int yConTro = y;

	char key;
	while (true)
	{
		key = GetKey();

		if (key == RIGHT)
		{
			if (trangHienTai < soTrang)
			{
				
					delete_Table(maxDong1Trang, newListCol);
				

				trangHienTai++;
				if (trangHienTai > soTrang) trangHienTai = soTrang;

				batDau = (trangHienTai - 1) * maxDong1Trang;
				if (tongSoDong > maxDong1Trang)
					ketThuc = batDau + maxDong1Trang;
				else ketThuc = tongSoDong;

				if (ketThuc > tongSoDong) ketThuc = batDau + tongSoDong % batDau;


				xuatDS1Trang_SV(DSSV, LSV, batDau, ketThuc, newListCol, luaChon, viTriChon);
				xuatTrang(trangHienTai, soTrang);
				yConTro = y;
				viTriChon = batDau + 1;
			}
		

		}
		else if (key == LEFT)
		{
			if (trangHienTai > 1)
			{
				
				trangHienTai--;
				if (trangHienTai == 0) trangHienTai = 1;

				batDau = (trangHienTai - 1) * maxDong1Trang;
				if (tongSoDong > maxDong1Trang)
					ketThuc = batDau + maxDong1Trang;
				else ketThuc = tongSoDong;

				if (ketThuc > tongSoDong) ketThuc = batDau + tongSoDong % batDau;

			
				xuatDS1Trang_SV(DSSV, LSV, batDau, ketThuc, newListCol, luaChon, viTriChon);
				xuatTrang(trangHienTai, soTrang);
				yConTro = y;
				viTriChon = batDau + 1;
				
			}
		}
		else if (key == ESC)
		{
			viTriChon = -1;
			deleteListCol(newListCol);
			return;
		}

		if (luaChon == 2 || luaChon == 3)
		{
			int soDong = ketThuc % maxDong1Trang;
			if (soDong == 0) soDong = maxDong1Trang;
			

			if (key == UP)
			{
				gotoxy(x + round(newListCol.infoCol[0]->widthCol / 2.0), yConTro);
				cout << "  ";

				yConTro = whereY() - 2;

				if (yConTro < y) yConTro = y;

				gotoxy(x + round(newListCol.infoCol[0]->widthCol / 2.0), yConTro);
				cout << "->";


				viTriChon--;
				if (viTriChon < 1) viTriChon = 1;
			}
			else if (key == DOWN)
			{
				gotoxy(x + round(newListCol.infoCol[0]->widthCol / 2.0), yConTro);
				cout << "  ";
				yConTro = whereY() + 2;

				if (yConTro == y + soDong * 2) yConTro = y + (soDong - 1) * 2;

				gotoxy(x + round(newListCol.infoCol[0]->widthCol / 2.0), yConTro);
				cout << "->";

				viTriChon++;
				if (viTriChon == soDong) viTriChon = soDong;

			}
			else if (key == ESC)
			{

				return;
			}
			else if (key == ENTER)
			{
				delete_Table(ketThuc, newListCol);
				return;
			}
			else if (key == LEFT || key == RIGHT)
			{
				
			}

			
		}


	}
}

void chon_SV(LISTSV& DSSV,LOPSV LSV, int luaChon)
{
	if (DSSV.pHead != NULL)
	{
		int viTriChon = 1;
		if (luaChon == 1) // xuat
		{
				xuatDSTheoTrang_SV(DSSV, LSV, luaChon, viTriChon);
		}
		else if (luaChon == 2) // xoa
		{
			xuatDSTheoTrang_SV(DSSV, LSV, luaChon, viTriChon);
			if (viTriChon != -1)
			{
				NODESV* SV = layInfo_SV(DSSV, viTriChon);
				if (SV != NULL)
					xoa_SV(DSSV, SV->data.MASV);
			}
		}
		else if (luaChon == 3) // sua
		{
			xuatDSTheoTrang_SV(DSSV, LSV, luaChon, viTriChon);
			if (viTriChon != -1)
			{
				NODESV* SV = layInfo_SV(DSSV, viTriChon);
				if(SV!=NULL)
					nhap_SV(LSV, DSSV, SV->data, 2);
			}
		}
	}
	else {
		return;
	}
}

/*
=========================================================================
======================= Ket thuc xu ly Sinh vien ========================
=========================================================================
*/








/*
=========================================================================
========================== Phan xu ly Mon hoc ===========================
=========================================================================
*/

bool isEmptyTree_MH(TREE DSMH)
{
	return (DSMH == NULL ? true : false);
}

void tim_MH(TREE DSMH, string MAMH, string& TENMH)
{
	if (isEmptyTree_MH(DSMH))
	{
		return;
	}else if (MAMH < DSMH->data.MAMH)
		{
			tim_MH(DSMH->pLeft, MAMH, TENMH);
		}
		else if (MAMH > DSMH->data.MAMH)
		{
			tim_MH(DSMH->pRight, MAMH, TENMH);
		}
		else if (MAMH == DSMH->data.MAMH)
		{
			TENMH = DSMH->data.TENMH;
		}

	
}

void them_MH(TREE& DSMH, MONHOC MH)
{
	if (isEmptyTree_MH(DSMH))
	{
		NODEMH* p = new NODEMH;
		p->data = MH;
		p->pLeft = NULL;
		p->pRight = NULL;
		DSMH = p;
		soLuong_MH++;
	}
	else
	{
		if (MH.MAMH < DSMH->data.MAMH)
		{
			them_MH(DSMH->pLeft, MH);
		}
		else if (MH.MAMH > DSMH->data.MAMH)
		{
			them_MH(DSMH->pRight, MH);
		}
	}
}




void chinhSua_MH(TREE& DSMH, MONHOC MH)
{
	if (isEmptyTree_MH(DSMH))
	{
		return;
	}
	else
	{
		if (MH.MAMH < DSMH->data.MAMH)
		{
			chinhSua_MH(DSMH->pLeft, MH);
		}
		else if (MH.MAMH > DSMH->data.MAMH)
		{
			chinhSua_MH(DSMH->pRight, MH);
		}
		else
		{
			DSMH->data.MAMH = MH.MAMH;
			DSMH->data.TENMH = MH.TENMH;
			DSMH->data.STCLT = MH.STCLT;
			DSMH->data.STCTH = MH.STCTH;
		}
	}
}


void nhap_MH(TREE &DSMH, MONHOC &MH,int luaChon)
{
	/*
		luaChon == 1 -> them mon hoc
		luaChon == 2 -> sua mon hoc cu
	*/
	if (luaChon == 1)
		formThem_MH("Them mon hoc");
	else if (luaChon == 2)
		formThem_MH("Sua mon hoc");

	
	int x = 93, y = 16;
	//gotoxy(x, y);

	int yConTro = y;
	SetColor(clblack, cllightwhite);

	if (!MH.MAMH.empty()) {
		gotoxy(x, yConTro);
		cout << MH.MAMH;
		gotoxy(x, yConTro + 3);
		cout << MH.TENMH;
		
	}
	gotoxy(x, yConTro + 6);
	cout << MH.STCLT;
	gotoxy(x, yConTro + 9);
	cout << MH.STCTH;

	while (true)
	{
		showCursortype();
		if (yConTro < y + 12)
		{
			drawButton(87, 28, 10);
			gotoxy(90, 29);
			cout << "Luu";

			drawButton(109, 28, 10);
			gotoxy(113, 29);
			cout << "Huy";
		}

		if (yConTro == y)
		{
			
			gotoxy(x + MH.MAMH.length(), yConTro);
			xuLyNhapMa(MH.MAMH, 7, x + MH.MAMH.length(), yConTro);

			if (yConTro < y) yConTro = y;
		}
		else if (yConTro == y + 3)
		{
			gotoxy(x + MH.TENMH.length(), yConTro);
			xuLyNhapChuoi(MH.TENMH, 30, x + MH.TENMH.length(), yConTro);
			
		}
		else if (yConTro == y + 6)
		{
				gotoxy(x, yConTro);
			xuLyNhapSo(MH.STCLT, 2, x, yConTro);
		}
		else if (yConTro == y + 9)
		{
				gotoxy(x, yConTro);
			xuLyNhapSo(MH.STCTH, 2, x, yConTro);

		}
		else if (yConTro == y + 12)
		{
			hideCursortype();
			int chon = 1;
			while (chon)
			{
				char key; 

				if (chon == 1)
				{
					drawEffectButton(87, 28, 10);
					gotoxy(90, 29);
					cout << "Luu";

					drawButton(109, 28, 10);
					gotoxy(113, 29);
					cout << "Huy";
				}
				else if (chon == 2)
				{
					drawButton(87, 28, 10);
					gotoxy(90, 29);
					cout << "Luu";

					drawEffectButton(109, 28, 10);
					gotoxy(113, 29);
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
				else if (key == UP)
				{
					yConTro = y + 9;
					chon = 0;
				}
				else if (key == ENTER)
				{
					
						if (chon == 1)
						{
							if (luaChon == 1)
							{
									string checkTrungMa="";
								tim_MH(DSMH, MH.MAMH, checkTrungMa);
								if (checkTrungMa != "")
								{
										
									printNotifi(90, 32, "Ma mon hoc bi trung");
									
										
								}
								else if (!MH.MAMH.empty() && !MH.TENMH.empty() && (MH.STCLT > 0 || MH.STCTH > 0) )
								{
									them_MH(DSMH, MH);
									yConTro = 0;
									chon = 0;
								}
								else
								{
									printNotifi(90, 32, "Vui long nhap day du thong tin");
								}
									
							}
							else if (luaChon == 2)
							{
								if (!MH.MAMH.empty() && !MH.TENMH.empty())
								{
									chinhSua_MH(DSMH, MH);
									yConTro = 0;
									chon = 0;
								}
							}
							
						}
						else if (chon == 2)
						{
							luaChon = 0;
							yConTro = 0;
							chon = 0;
							//return;
						}
					
					
				}
			
				

			}
			
		}
		else if (yConTro == 0)
		{
			hideCursortype();
				if (luaChon == 1)
				{
					formNotifi("Them mon hoc thanh cong");
				}
				else if (luaChon == 2)
				{
					formNotifi("Sua mon hoc thanh cong");
			
				}
			return;
		}

		
	}
	
	
}



void timNodeTheMang_MH(TREE& temp, TREE& DSMH)
{
	if (DSMH->pLeft != NULL)
	{
		timNodeTheMang_MH(temp, DSMH->pLeft);
	}
	else 
	{
		temp->data = DSMH->data; 
		temp = DSMH; 
		DSMH = DSMH->pRight; 	
	}

}

void xoa_MH(TREE& DSMH, string MAMH)
{

	if (DSMH == NULL)
	{
		return; 
	}
	else
	{

		if (MAMH < DSMH->data.MAMH)
		{
			xoa_MH(DSMH->pLeft, MAMH);
		}
		else if (MAMH > DSMH->data.MAMH)
		{
			xoa_MH(DSMH->pRight, MAMH);
		}
		else
		{
			NODEMH* temp = DSMH;
			if (DSMH->pLeft == NULL && DSMH->pRight == NULL)
			{
				delete DSMH; DSMH = NULL; return;
			}
			if (DSMH->pLeft == NULL)
			{

				DSMH = DSMH->pRight;
			}
			else if (DSMH->pRight == NULL)
			{

				DSMH = DSMH->pLeft;
			}
			else
			{
				timNodeTheMang_MH(temp, DSMH->pRight);
			}
			delete temp;
		}
	}
}

void free_MH(TREE& DSMH)
{
	if (DSMH != NULL)
	{
		free_MH(DSMH->pLeft);
		free_MH(DSMH->pRight);
		delete DSMH;
	}
}

void chuyenCaythanhMang_MH(TREE DSMH, MONHOC* ArrMH, int& n)
{
	if (DSMH != NULL)
	{
		chuyenCaythanhMang_MH(DSMH->pLeft, ArrMH, n);
		ArrMH[n++] = DSMH->data;
		chuyenCaythanhMang_MH(DSMH->pRight, ArrMH, n);
	}
	else return;
}

void sapXepTen_MH(MONHOC* ArrMH, int& n) // Selection Sort
{
	MONHOC  temp;
	for (int i = 0; i < n - 1; i++)
	{
		int iMin = i;
		for (int j = i + 1; j < n; j++)
		{
			if (ArrMH[iMin].TENMH > ArrMH[j].TENMH)
			{
				iMin = j;

			}
		}

		temp = ArrMH[i];
		ArrMH[i] = ArrMH[iMin];
		ArrMH[iMin] = temp;

	}

}





void xuatDS1Trang_MH(MONHOC* ArrMH, int batDau, int ketThuc, LISTCOL newListCol,int luaChon, int &viTriChon)
{
	int soDong = ketThuc % maxDong1Trang;
	if (soDong == 0) soDong = maxDong1Trang;
	draw_Table(soDong, newListCol);

	int STT = batDau - 1;
	int x = xTable, y = yTable + 3;
	int yConTro = y;

	for (int i = 0; i < soDong; i++)
	{
		++STT;
		gotoxy(x + round(newListCol.infoCol[0]->widthCol / 2.0), y + i * 2);
		if (luaChon == 1) // xuat STT
			cout << STT + 1;
		else if (luaChon == 2 || luaChon ==3 ) // xuat mui ten
		{
			if (i == 0)
			{
				cout << "->";
			}
		}

		gotoxy(x + round(newListCol.infoCol[1]->widthCol / 2.0) + 3, y + i * 2); 
		cout << ArrMH[STT].MAMH;
		gotoxy(x + round(newListCol.infoCol[2]->widthCol / 2.0), y + i * 2);
		cout << ArrMH[STT].TENMH;
		gotoxy(x + newListCol.infoCol[2]->widthCol + round(newListCol.infoCol[3]->widthCol * 1.5), y + i * 2);
		cout << ArrMH[STT].STCLT;
		gotoxy(x + newListCol.infoCol[2]->widthCol + round(newListCol.infoCol[4]->widthCol * 2.5) + 1, y + i * 2);
		cout << ArrMH[STT].STCTH;
	}


}

void xuatDSTheoTrang_MH(MONHOC* ArrMH, int tongSoDong,int luaChon, int &viTriChon)
{
		int soDu = tongSoDong % maxDong1Trang;
		if (soDu > 0) soDu = 1;
		else soDu == 0;

		int soTrang = tongSoDong / maxDong1Trang + soDu;
	int trangHienTai = 1;

	int batDau = 0;
	int ketThuc;
	if (tongSoDong > maxDong1Trang) ketThuc = maxDong1Trang; else ketThuc = tongSoDong;
	LISTCOL newListCol = ListColMonHoc();
	xuatDS1Trang_MH(ArrMH, batDau, ketThuc, newListCol,luaChon,viTriChon);
	xuatTrang(trangHienTai, soTrang);

	int x = xTable, y = yTable + 3;
	int yConTro = y;

	char key;
	while (true)
	{
		key = GetKey();

		if (key == RIGHT)
		{
			if (trangHienTai < soTrang)
			{
				
				delete_Table(maxDong1Trang, newListCol);

				trangHienTai++;
				if (trangHienTai > soTrang) trangHienTai = soTrang;

				batDau = (trangHienTai - 1) * maxDong1Trang;
				if (tongSoDong > maxDong1Trang)
					ketThuc = batDau + maxDong1Trang;
				else ketThuc = tongSoDong;

				if (ketThuc > tongSoDong) ketThuc = batDau + tongSoDong % batDau;

				
				xuatDS1Trang_MH(ArrMH, batDau, ketThuc, newListCol,luaChon,viTriChon);
				xuatTrang(trangHienTai, soTrang);
				yConTro = y;
				viTriChon = batDau + 1;
			}
			//cout <<"\n"<< batDau << " " << ketThuc<<endl;

		}
		else if (key == LEFT)
		{
			if (trangHienTai > 1)
			{
				
				//delete_Table(ketThuc, newListCol);
				trangHienTai--;
				if (trangHienTai == 0) trangHienTai = 1;

				batDau = (trangHienTai - 1) * maxDong1Trang;
				if (tongSoDong > maxDong1Trang)
					ketThuc = batDau + maxDong1Trang;
				else ketThuc = tongSoDong;

				if (ketThuc > tongSoDong) ketThuc = batDau + tongSoDong % batDau;

				
				xuatDS1Trang_MH(ArrMH, batDau, ketThuc, newListCol,luaChon,viTriChon);
				xuatTrang(trangHienTai, soTrang);
				yConTro = y;
				viTriChon = batDau+1;
				
			}
		}
		
		else if (key == ESC)
		{
			viTriChon = -1;
			deleteListCol(newListCol);
			return;
		}
		
		

		if (luaChon == 2 || luaChon ==3 )
		{
			int soDong = ketThuc % maxDong1Trang;
			if (soDong == 0) soDong = maxDong1Trang;

				if (key == UP)
				{
					gotoxy(x + round(newListCol.infoCol[0]->widthCol / 2.0), yConTro);
					cout << "  ";

					yConTro = whereY() - 2;

					if (yConTro < y) yConTro = y;

					gotoxy(x + round(newListCol.infoCol[0]->widthCol / 2.0), yConTro);
					cout << "->";


					viTriChon--;
					if (viTriChon < 1) viTriChon = 1;
				}
				else if (key == DOWN)
				{
					gotoxy(x + round(newListCol.infoCol[0]->widthCol / 2.0), yConTro);
					cout << "  ";
					yConTro = whereY() + 2;

					if (yConTro == y + soDong * 2) yConTro = y + (soDong - 1) * 2;

					gotoxy(x + round(newListCol.infoCol[0]->widthCol / 2.0), yConTro);
					cout << "->";

					viTriChon++;
					if (viTriChon == soDong) viTriChon = soDong;

				}
				else if (key == ESC )
				{
					viTriChon = -1;
					return;
				}
				else if (key == ENTER)
				{
					return;
				}
				else if (key == LEFT || key == RIGHT)
				{
					//run = false;
				}

			//}
		}

	}

}
void chon_MH(TREE& DSMH, int luaChon)
{
	if (DSMH != NULL)
	{
		MONHOC* ArrMH = new MONHOC[soLuong_MH];
		int n = 0;
		chuyenCaythanhMang_MH(DSMH, ArrMH, n);
		sapXepTen_MH(ArrMH, n);

		int viTriChon = 1;
		
		if(luaChon == 1) // xuat
		{
			xuatDSTheoTrang_MH(ArrMH, n, 1, viTriChon);
		}
		else if (luaChon == 2) // xoa
		{
			xuatDSTheoTrang_MH(ArrMH, n, 2, viTriChon);
			//cout << viTriChon;
			if (viTriChon != -1)
			{
				bool xacNhan = true;
				formConfirm("Ban co chac chan xoa", xacNhan);
				if (xacNhan)
				{
					xoa_MH(DSMH, ArrMH[viTriChon - 1].MAMH);
					formNotifi("Xoa mon hoc thanh cong");
				}
				else return;
			}
			
		}
		else if (luaChon == 3) // sua
		{
			xuatDSTheoTrang_MH(ArrMH, n, 3, viTriChon);
			cout << viTriChon;
			if (viTriChon != -1)
			nhap_MH(DSMH, ArrMH[viTriChon-1],2);
		}
		
		_getch();

		
		delete[] ArrMH;
	}
	else {
		formNotifi("Khong co mon hoc ");
		_getch();
		return;
	}
}






/*void xuatDS1Trang_MH(MONHOC *ArrMH,int batDau, int ketThuc, LISTCOL newListCol)
{
	int soDong = ketThuc % maxDong1Trang;
	if (soDong == 0) soDong = maxDong1Trang;
	draw_Table(soDong, newListCol);

	int STT = batDau-1;
	int x = xTable, y = yTable+3;
	for (int i = 0; i < soDong; i++)
	{
		gotoxy(x + round(newListCol.infoCol[0]->widthCol/2.0), y + i * 2);
		cout << ++STT + 1;
		gotoxy(x + round(newListCol.infoCol[1]->widthCol / 2.0)+ArrMH[i].MAMH.length()/2, y + i * 2);
		cout << ArrMH[STT].MAMH;
		gotoxy(x + round(newListCol.infoCol[2]->widthCol / 2.0), y + i * 2);
		cout << ArrMH[STT].TENMH;
		gotoxy(x +newListCol.infoCol[2]->widthCol  + round(newListCol.infoCol[3]->widthCol*1.5), y + i * 2);
		cout << ArrMH[STT].STCLT;
		gotoxy(x + newListCol.infoCol[2]->widthCol + round(newListCol.infoCol[4]->widthCol*2.5)+1, y + i * 2);
		cout << ArrMH[STT].STCTH;
	}
	
}

void xuatDSTheoTrang_MH(MONHOC *ArrMH,int tongSoDong)
{
	
	int soTrang = tongSoDong / maxDong1Trang + 1;
	int trangHienTai = 1;
	
	int batDau = 0;
	int ketThuc; 
	if (tongSoDong > maxDong1Trang) ketThuc = maxDong1Trang; else ketThuc = tongSoDong;
	LISTCOL newListCol = ListColMonHoc();
	xuatDS1Trang_MH(ArrMH, batDau, ketThuc,newListCol);
	xuatTrang(trangHienTai, soTrang);

	char key;
	while (true)
	{
		key = GetKey();

		if (key == RIGHT)
		{
			if (trangHienTai < soTrang)
			{
				delete_Table(ketThuc, newListCol);

				trangHienTai++;
				if (trangHienTai > soTrang) trangHienTai = soTrang;

				batDau = (trangHienTai - 1) * maxDong1Trang;
				if (tongSoDong > maxDong1Trang)
					ketThuc = batDau + maxDong1Trang;
				else ketThuc = tongSoDong;

				if (ketThuc > tongSoDong) ketThuc = batDau + tongSoDong % batDau;

				
				xuatDS1Trang_MH(ArrMH, batDau, ketThuc, newListCol);
				xuatTrang(trangHienTai, soTrang);
			}
			//cout <<"\n"<< batDau << " " << ketThuc<<endl;

		}
		else if (key == LEFT)
		{
			if (trangHienTai > 1)
			{
				//delete_Table(ketThuc, newListCol);
				trangHienTai--;
				if (trangHienTai == 0) trangHienTai = 1;

				batDau = (trangHienTai - 1) * maxDong1Trang;
				if (tongSoDong > maxDong1Trang)
					ketThuc = batDau + maxDong1Trang;
				else ketThuc = tongSoDong;

				if (ketThuc > tongSoDong) ketThuc = batDau + tongSoDong % batDau;

				//delete_Table(ketThuc, newListCol);
				xuatDS1Trang_MH(ArrMH, batDau, ketThuc, newListCol);
				xuatTrang(trangHienTai, soTrang);
				//cout << "\n" << batDau << " " << ketThuc << endl;
			}
		}
		else if (key == ESC)
		{
			deleteListCol(newListCol);
			return;
		}
		
	}

}



void xuatDS_MH(TREE DSMH)
{
	

	if (DSMH != NULL)
	{
		MONHOC* ArrMH = new MONHOC[soLuong_MH];
		int n = 0;
		chuyenCaythanhMang_MH(DSMH, ArrMH, n);
		sapXepTen_MH(ArrMH, n);
		xuatDSTheoTrang_MH(ArrMH, n);
		delete[] ArrMH;
	}
	else {
		return;
	}
}*/


/*
=========================================================================
======================== Ket thuc xu ly mon hoc =========================
=========================================================================
*/







/*
=========================================================================
========================== Phan xu ly Dang ky ===========================
=========================================================================
*/
NODEDK* taoNode_DK()
{
	NODEDK* DK = new NODEDK;
	DK->pNext = NULL;
	return DK;
}

int timViTri_DK(LISTDK DSDK, NODEDK* DK)
{
	int viTri = 1;

	NODEDK* k = DSDK.pHead;
	while (k != NULL && k->data.MASV <= DK->data.MASV)
	{
		if (k->data.MASV == DK->data.MASV) return -1;
		viTri++;
		k = k->pNext;
	}
	return viTri;
}

int timSV_DK(LISTDK DSDK, string MASV)
{
	int viTri = 1;
	if (DSDK.pHead != NULL)
		for (NODEDK* k = DSDK.pHead; k != NULL; k = k->pNext)
		{
			if (k->data.MASV == MASV) return viTri;
			else viTri++;
		}
	return -1;
}

void themVaoDau_DK(LISTDK& DSDK, NODEDK* DK)
{
	if (DSDK.pHead == NULL)
	{
		DSDK.pHead = DSDK.pTail = DK;
	}
	else
	{
		DK->pNext = DSDK.pHead;
		DSDK.pHead = DK; 
	}
	
}

void themVaoCuoi_DK(LISTDK& DSDK, NODEDK* DK)
{
	if (DSDK.pHead == NULL)
	{
		DSDK.pHead = DSDK.pTail = DK;
	}
	else
	{
		DSDK.pTail->pNext = DK;
		DSDK.pTail = DK;
	}
	
}

void them_DK(LISTDK& DSDK, NODEDK* DK, int viTriThem)
{
	int n = 0;
	for (NODEDK* k = DSDK.pHead; k != NULL; k = k->pNext) n++;

	if (DSDK.pHead == NULL || viTriThem == 1)
	{
		themVaoDau_DK(DSDK, DK);
	}
	else if (viTriThem == n + 1)
	{
		
		themVaoCuoi_DK(DSDK, DK);
	}
	else
	{
		int viTri = 0;
		NODEDK* pTrc = taoNode_DK();
		for (NODEDK* k = DSDK.pHead; k != NULL; k = k->pNext)
		{
			viTri++;
			if (viTri == viTriThem)
			{
				DK->pNext = k;
				pTrc->pNext = DK;
				break;
			}

			pTrc = k;
		}
	}
}

void luuDiemDS_DK(LISTDK& DSDK, LISTDK &DSDIEM)
{
	if (DSDK.pHead != NULL && DSDIEM.pHead != NULL)
	{
		NODEDK* tempDK = DSDK.pHead;
		
		for (; tempDK != NULL; tempDK = tempDK->pNext)
		{
			for (NODEDK* tempDiem = DSDIEM.pHead; tempDiem != NULL; tempDiem = tempDiem->pNext)
			{
				if (tempDK->data.MASV == tempDiem->data.MASV && float(tempDK->data.DIEM) < float(tempDiem->data.DIEM))
				{
					tempDK->data.DIEM = tempDiem->data.DIEM;
					break;
				}
			}
		}
	}
	else {
		return;
	}
	
	/*system("cls");
	SetColor(clblack, cllightwhite);
	for (NODEDK* k = DSDIEM.pHead; k != NULL; k = k->pNext)
	{
		cout << endl << k->data.MASV << "\t" << k->data.DIEM;
	}
	cout << endl;
	for (NODEDK* temp = DSDK.pHead; temp != NULL; temp = temp->pNext)
	{
		cout << endl << temp->data.MASV << "\t" << temp->data.DIEM;
	}*/
}


void free_DK(LISTDK& DSDK)
{
	NODEDK* DK = NULL;
	while (DSDK.pHead != NULL)
	{
		DK = DSDK.pHead;
		DSDK.pHead = DSDK.pHead->pNext;
		delete DK;
	}
}

bool checkDK_LTC(LISTLOPTC DSLTC, string MAMH, string MASV)
{

	for (int i = 0; i < DSLTC.n; i++)
	{
		if (DSLTC.LopTC[i]->MAMH == MAMH)
		{
			if (DSLTC.LopTC[i]->DSDK.pHead != NULL)

				for (NODEDK* k = DSLTC.LopTC[i]->DSDK.pHead; k != NULL; k = k->pNext)
				{
					if (k->data.MASV == MASV) return true;

				}
		}
	}

	return false;
}

NODESV* layInfoSV_LSV(LISTLOP DSLSV, string MASV)
{
	for (int i = 0; i < DSLSV.n; i++)
	{
		if(DSLSV.Lop[i].DSSV.pHead!=NULL)
		for (NODESV* SV = DSLSV.Lop[i].DSSV.pHead; SV != NULL; SV = SV->pNext)
		{
			if (SV->data.MASV == MASV)
			{
				return SV;
			}
		}
	}
	return NULL;
}

void xuatDSLTC1Trang_DK(LISTLOPTC DSLTC, TREE DSMH, int batDau, int ketThuc, LISTCOL newListCol,string MASV, int& viTriChon)
{
	int soDong = ketThuc % maxDong1Trang;
	if (soDong == 0) soDong = maxDong1Trang;
	draw_Table(soDong, newListCol);

	int STT = batDau - 1;
	int x = xTable, y = yTable + 3;
	int yConTro = y;


	string TENMH;
	bool daDangKy = checkDK_LTC(DSLTC, DSLTC.LopTC[STT+1]->MAMH, MASV);
	for (int i = 0; i < soDong; i++)
	{
		++STT;
		gotoxy(x + round(newListCol.infoCol[0]->widthCol / 2.0), y + i * 2);
			if (i == 0 && daDangKy==false )
			{
				cout << "->";
			}
			else if(i==0 && daDangKy==true)
			{
				SetColor(cllightred, cllightwhite);
				cout << "X";
				SetColor(clblack, cllightwhite);
			}

		tim_MH(DSMH, DSLTC.LopTC[STT]->MAMH, TENMH);

		gotoxy(x + round(newListCol.infoCol[1]->widthCol / 2.0) + 5, y + i * 2);
		cout << DSLTC.LopTC[STT]->MALOPTC;
		gotoxy(x + round(newListCol.infoCol[2]->widthCol / 2.0) + 12, y + i * 2);
		cout << DSLTC.LopTC[STT]->MAMH;
		gotoxy(x + newListCol.infoCol[3]->widthCol - 6, y + i * 2);
		cout << TENMH;
		gotoxy(x + 75, y + i * 2);
		cout << DSLTC.LopTC[STT]->KHOA;
		gotoxy(x + 85, y + i * 2);
		cout << DSLTC.LopTC[STT]->HOCKY;
		gotoxy(x + 94, y + i * 2);
		cout << DSLTC.LopTC[STT]->NHOM;
		gotoxy(x + 106, y + i * 2);
		cout << DSLTC.LopTC[STT]->SVMAX;
	}
}

void xuatDSLTCTheoTrang_DK(LISTLOPTC DSLTC, TREE DSMH, string MASV,int& viTriChon)
{
	//bool check[MAXLOPTC] = { false };
	int tongSoDong = DSLTC.n;
	int soDu = tongSoDong % maxDong1Trang;
	if (soDu > 0) soDu = 1;
	else soDu == 0;

	int soTrang = tongSoDong / maxDong1Trang + soDu;
	int trangHienTai = 1;

	int batDau = 0;
	int ketThuc;
	if (tongSoDong > maxDong1Trang) ketThuc = maxDong1Trang; else ketThuc = tongSoDong;
	LISTCOL newListCol = ListColLopTC();
	xuatDSLTC1Trang_DK(DSLTC, DSMH, batDau, ketThuc, newListCol, MASV, viTriChon);
	xuatTrang(trangHienTai, soTrang);

	int x = xTable, y = yTable + 3;
	int yConTro = y;

	char key;
	while (true)
	{
		key = GetKey();

		if (key == RIGHT)
		{
			if (trangHienTai < soTrang)
			{
				delete_Table(ketThuc, newListCol);

				trangHienTai++;
				if (trangHienTai > soTrang) trangHienTai = soTrang;

				batDau = (trangHienTai - 1) * maxDong1Trang;
				if (tongSoDong > maxDong1Trang)
					ketThuc = batDau + maxDong1Trang;
				else ketThuc = tongSoDong;

				if (ketThuc > tongSoDong) ketThuc = batDau + tongSoDong % batDau;


				xuatDSLTC1Trang_DK(DSLTC, DSMH, batDau, ketThuc, newListCol, MASV, viTriChon);
				xuatTrang(trangHienTai, soTrang);
				yConTro = y;
				viTriChon = batDau + 1;
			}
			//cout <<"\n"<< batDau << " " << ketThuc<<endl;

		}
		else if (key == LEFT)
		{
			if (trangHienTai > 1)
			{
				//delete_Table(ketThuc, newListCol);
				trangHienTai--;
				if (trangHienTai == 0) trangHienTai = 1;

				batDau = (trangHienTai - 1) * maxDong1Trang;
				if (tongSoDong > maxDong1Trang)
					ketThuc = batDau + maxDong1Trang;
				else ketThuc = tongSoDong;

				if (ketThuc > tongSoDong) ketThuc = batDau + tongSoDong % batDau;

				//delete_Table(ketThuc, newListCol);
				xuatDSLTC1Trang_DK(DSLTC, DSMH, batDau, ketThuc, newListCol, MASV, viTriChon);
				xuatTrang(trangHienTai, soTrang);
				yConTro = y;
				viTriChon = batDau + 1;
				//cout << "\n" << batDau << " " << ketThuc << endl;
			}
		}
		else if (key == ESC)
		{
			viTriChon = -1;
			deleteListCol(newListCol);
			return;
		}


		int soDong = ketThuc % maxDong1Trang;
		if (soDong == 0) soDong = maxDong1Trang;
		bool daDangKy = false;
		/*	daDangKy = checkDK_LTC(DSLTC, DSLTC.LopTC[STT]->MAMH, MASV);
			if (daDangKy)
			{
				SetColor(cllightred, cllightwhite);
				cout << "X";
				SetColor(cllightwhite, cllightwhite);
			}*/

		if (key == UP)
		{
			gotoxy(x + round(newListCol.infoCol[0]->widthCol / 2.0), yConTro);
			cout << "  ";

			yConTro = whereY() - 2;

			if (yConTro < y) yConTro = y;

			gotoxy(x + round(newListCol.infoCol[0]->widthCol / 2.0), yConTro);

			daDangKy = checkDK_LTC(DSLTC, DSLTC.LopTC[viTriChon-2]->MAMH, MASV);
			if(daDangKy){
				SetColor(cllightred, cllightwhite);
				cout << "X";
				SetColor(clblack, cllightwhite);
				daDangKy = false;
			}else
			cout << "->";


			viTriChon--;
			if (viTriChon < 1) viTriChon = 1;
		}
		else if (key == DOWN)
		{
			gotoxy(x + round(newListCol.infoCol[0]->widthCol / 2.0), yConTro);
			cout << "  ";
			yConTro = whereY() + 2;

			if (yConTro == y + soDong * 2) yConTro = y + (soDong - 1) * 2;

			gotoxy(x + round(newListCol.infoCol[0]->widthCol / 2.0), yConTro);

			daDangKy = checkDK_LTC(DSLTC, DSLTC.LopTC[viTriChon]->MAMH, MASV);
			if (daDangKy) {
				SetColor(cllightred, cllightwhite);
				cout << "X";
				SetColor(clblack, cllightwhite);
				daDangKy = false;
			}
			else
				cout << "->";

			viTriChon++;
			if (viTriChon == soDong) viTriChon = soDong;

		}
		else if (key == ESC)
		{
			viTriChon = -1;
			return;
		}
		else if (key == ENTER)
		{
			delete_Table(soDong, newListCol);
			return;
		}
		else if (key == LEFT || key == RIGHT)
		{
			//run = false;
		}

		//}
	
	}
}

void dangKyLTC_SV(LISTLOPTC &DSLTC, TREE DSMH,LISTLOP DSLSV)
{
	formNhapMa_SV();
	showCursortype();
	gotoxy(82, 23);

	int yConTro = 23;
	string MASV;
	int timSV=-1;
	xuLyNhapMa(MASV, 10, 82, yConTro);
	if (yConTro == 26)
	{
		hideCursortype();
		for (int i = 0; i < DSLSV.n; i++)
		{
				timSV = tim_SV(DSLSV.Lop[i].DSSV, MASV);
				if (timSV != -1)
				{
					break;
			}
		}

		if (timSV != -1)
		{

			DANGKY:
				int viTriChon = 1;
				xuatDSLTCTheoTrang_DK(DSLTC, DSMH, MASV, viTriChon);
				if (viTriChon == -1)
				{
					return;
				}
				else
				{
					bool daDangKy = checkDK_LTC(DSLTC, DSLTC.LopTC[viTriChon-1]->MAMH, MASV);
					if (daDangKy == FALSE)
					{

						NODEDK* DK = taoNode_DK();
						DK->data.MASV = MASV;
						DK->data.DIEM = 0;
						int viTriThem = timViTri_DK(DSLTC.LopTC[viTriChon - 1]->DSDK, DK);
						them_DK(DSLTC.LopTC[viTriChon - 1]->DSDK, DK, viTriThem);

						formNotifi("Dang ky mon hoc thanh cong");
						return;
					}
					else {
						formNotifi("Ban da dang ky mon nay roi");
						goto DANGKY;

					}
				}
		}
		else if (timSV == -1)
		{
			formNotifi("Khong tim thay sinh vien");
		}

		
	}
		
}


void thongKeDS_DK(LISTDK DSDK, LISTLOP DSLSV,LISTSV &DSSVDK, int &soLuong)
{
	if (DSDK.pHead != NULL)
	{
		for (NODEDK* DK = DSDK.pHead; DK != NULL; DK = DK->pNext)
		{
			
			NODESV* NSV = layInfoSV_LSV(DSLSV, DK->data.MASV);
			
			if (NSV != NULL)
			{
				NODESV* SV = taoNode_SV();
				/*SV->data.MALOP = NSV->data.MALOP;
				SV->data.MASV = NSV->data.MASV;
				SV->data.HO = NSV->data.HO;
				SV->data.TEN = NSV->data.TEN;
				SV->data.PHAI = NSV->data.PHAI;
				SV->data.SDT = NSV->data.SDT;
				SV->data.MALOP = NSV->data.MALOP;*/
				SV->data = NSV->data;
				int viTriThem = timviTri_SV(DSSVDK, NSV);
				them_SV(DSSVDK, SV, viTriThem);
				soLuong++;
			}
		}

	}
	else {
		return;
	}
}

void thongKeDiemDS_DK(LISTDK DSDK, LISTLOP DSLSV, LISTSV& DSSVDK,LISTDK &DSDIEM, int& soLuong)
{
	if (DSDK.pHead != NULL)
	{
		int i = -1; bool check = true;
		for (NODEDK* DK = DSDK.pHead; DK != NULL; DK = DK->pNext)
		{

			NODESV* NSV = layInfoSV_LSV(DSLSV, DK->data.MASV);
			if (NSV != NULL)
			{
				NODESV* SV = taoNode_SV();
				SV->data = NSV->data;
				int viTriThem = timviTri_SV(DSSVDK, NSV);
				them_SV(DSSVDK, SV, viTriThem);

				NODEDK* NDK = taoNode_DK();
				NDK->data = DK->data;
				them_DK(DSDIEM, NDK, viTriThem);
				soLuong++;
			}
		}

	}
	else {
		return;
	}
}

void thongKeDSDiemTB_SV(LISTSV DSSV, LISTLOPTC DSLTC, LISTDK& DSDIEM, int &soLuong)
{
	string MAMH = "";  float diemTB = 0, tongDiem = 0; int soMonHoc = 0;
	int i = 0;
	for (NODESV* SV = DSSV.pHead; SV != NULL; SV = SV->pNext)
	{
		
			for (int i = 0; i < DSLTC.n; i++)
			{
				if (MAMH != DSLTC.LopTC[i]->MAMH)
					for (NODEDK* DK = DSLTC.LopTC[i]->DSDK.pHead; DK != NULL; DK = DK->pNext)
					{
						if (DK->data.MASV == SV->data.MASV)
						{
							MAMH = DSLTC.LopTC[i]->MAMH;

							tongDiem += DK->data.DIEM;
							soMonHoc++;

							break;
						}
					}
			}
			if (soMonHoc > 0) { 
				diemTB = tongDiem / (soMonHoc * 1.0); 

				diemTB = round(diemTB * 10) / 10;     //  lam tron diem, lay 1 chu so sau day phay
			}

				NODEDK* NDK = taoNode_DK();
				NDK->data.MASV = SV->data.MASV;
				NDK->data.DIEM = diemTB;
				them_DK(DSDIEM, NDK, i+1);
				i++;
			
			/*cout << "\nDiem tb: " << diemTB;
			cout << "\n======================================";*/
			diemTB = 0; tongDiem = 0; soMonHoc = 0;
			MAMH = "";
		
	}
	soLuong = i;
}


void thongKeDSDiemTK_SV(LISTSV DSSV, LISTLOPTC DSLTC,LISTDK &DSDIEM,string MAMH,int &soLuong)
{
	string temp = "";
	int stt = 0;
	bool daDangKy = false;
	for (NODESV* SV = DSSV.pHead; SV != NULL; SV = SV->pNext)
	{
		for (int i = 0; i < DSLTC.n; i++)
		{
			if(DSLTC.LopTC[i]->MAMH==MAMH)
			for (NODEDK* DK = DSLTC.LopTC[i]->DSDK.pHead; DK != NULL; DK = DK->pNext)
			{
				if (DK->data.MASV == SV->data.MASV)
				{
					temp = DSLTC.LopTC[i]->MAMH;

					NODEDK* NDK = taoNode_DK();
					NDK->data.MASV = SV->data.MASV;
					NDK->data.DIEM = DK->data.DIEM;
					them_DK(DSDIEM, NDK, stt + 1);
					stt++;
					soLuong++;
					i = DSLTC.n + 1;
					daDangKy = true;
					break;
				}
			}

			
			
		}


	}
	
}


void xuatDS_DK(LISTDK DSDK, LISTLOP DSLSV)
{
	LISTSV DSSVDK;
	DSSVDK.pHead = NULL;
	DSSVDK.pTail = NULL;
	int soLuong = 0;

	thongKeDS_DK(DSDK, DSLSV, DSSVDK, soLuong);
	cout << soLuong;
	if (DSSVDK.pHead != NULL) 
		for (NODESV* SV = DSSVDK.pHead; SV != NULL; SV = SV->pNext)
		{
			cout << "\nMa sv: " << SV->data.MASV;
			cout << "\nHo ten: " << SV->data.HO << " " << SV->data.TEN;
			cout << "\nPhai: " << SV->data.PHAI;
			cout << "\nSDT: " << SV->data.SDT;
			cout << "\nMa lop: " << SV->data.MALOP;
			cout << "\n======================================";
		}
	
}

void xuatDS1Trang_DK(LISTSV DSSV, int batDau, int ketThuc, LISTCOL newListCol)
{
	int soDong = ketThuc % maxDong1Trang;
	if (soDong == 0) soDong = maxDong1Trang;
	draw_Table(soDong, newListCol);

	int STT = batDau - 1;
	int x = xTable, y = yTable + 3;
	int yConTro = y;
	int i = 0;

	NODESV* First = DSSV.pHead;
	for (int j = 0; j < STT + 1; j++) First = First->pNext; // chay den STT can xuat

	for (NODESV* k = First; (k != NULL); k = k->pNext, i++)
	{
		++STT;
		gotoxy(x + round(newListCol.infoCol[0]->widthCol / 2.0), y + i * 2);
		cout << STT + 1;

		gotoxy(x + round(newListCol.infoCol[1]->widthCol / 2.0) + 3, y + i * 2);
		cout << k->data.MASV;

		gotoxy(x + round(newListCol.infoCol[2]->widthCol / 2.0) + 7, y + i * 2);
		cout << k->data.HO;

		gotoxy(x + 76, y + i * 2);
		cout << k->data.TEN;

		gotoxy(x + 109, y + i * 2);
		cout << k->data.MALOP;

		if (i == soDong - 1) break;
	}
}

void xuatDSTheoTrang_DK(LISTDK DSDK,LISTLOP DSLSV)
{
	LISTSV DSSVDK;
	DSSVDK.pHead = NULL;
	DSSVDK.pTail = NULL;
	int soLuong = 0;

	thongKeDS_DK(DSDK, DSLSV, DSSVDK,soLuong);
	
	if (DSSVDK.pHead != NULL)
	{
		int tongSoDong = soLuong;
		int soDu = tongSoDong % maxDong1Trang;
		if (soDu > 0) soDu = 1;
		else soDu == 0;

		int soTrang = tongSoDong / maxDong1Trang + soDu;
		int trangHienTai = 1;

		int batDau = 0;
		int ketThuc;
		if (tongSoDong > maxDong1Trang) ketThuc = maxDong1Trang; else ketThuc = tongSoDong;
		LISTCOL newListCol = ListColDK();

		xuatDS1Trang_DK(DSSVDK, batDau, ketThuc, newListCol);
		xuatTrang(trangHienTai, soTrang);

		int x = xTable, y = yTable + 3;
		int yConTro = y;

		char key;
		while (true)
		{
			key = GetKey();

			if (key == RIGHT)
			{
				if (trangHienTai < soTrang)
				{
				
					delete_Table(maxDong1Trang, newListCol);

					trangHienTai++;
					if (trangHienTai > soTrang) trangHienTai = soTrang;

					batDau = (trangHienTai - 1) * maxDong1Trang;
					if (tongSoDong > maxDong1Trang)
						ketThuc = batDau + maxDong1Trang;
					else ketThuc = tongSoDong;

					if (ketThuc > tongSoDong) ketThuc = batDau + tongSoDong % batDau;


					xuatDS1Trang_DK(DSSVDK, batDau, ketThuc, newListCol);
					xuatTrang(trangHienTai, soTrang);
					yConTro = y;
					//viTriChon = batDau + 1;
				}
				//cout <<"\n"<< batDau << " " << ketThuc<<endl;

			}
			else if (key == LEFT)
			{
				if (trangHienTai > 1)
				{
					//delete_Table(ketThuc, newListCol);
					trangHienTai--;
					if (trangHienTai == 0) trangHienTai = 1;

					batDau = (trangHienTai - 1) * maxDong1Trang;
					if (tongSoDong > maxDong1Trang)
						ketThuc = batDau + maxDong1Trang;
					else ketThuc = tongSoDong;

					if (ketThuc > tongSoDong) ketThuc = batDau + tongSoDong % batDau;

					//delete_Table(ketThuc, newListCol);
					xuatDS1Trang_DK(DSSVDK, batDau, ketThuc, newListCol);
					xuatTrang(trangHienTai, soTrang);
					yConTro = y;
					//viTriChon = batDau + 1;
					//cout << "\n" << batDau << " " << ketThuc << endl;
				}
			}
			else if (key == ESC)
			{
				//viTriChon = -1;
				deleteListCol(newListCol);
				free_SV(DSSVDK);
				return;
			}
		}
	}
	else
	{
		formNotifi("Lop khong co sinh vien");
		return;
	}
}




void nhapDS1Trang_Diem(LISTSV DSSV, LISTDK& DSDK, int batDau, int ketThuc, LISTCOL newListCol, char &key)
{
	int soDong = ketThuc % maxDong1Trang;
	if (soDong == 0) soDong = maxDong1Trang;
	draw_Table(soDong, newListCol);

	int STT = batDau - 1;
	int x = xTable, y = yTable + 3;
	int yConTro = y;
	int i = 0;

	NODESV* First = DSSV.pHead;
	for (int j = 0; j < STT + 1; j++) First = First->pNext; // chay den STT can xuat

	NODEDK* FirstDiem = DSDK.pHead;
	for (int j = 0; j < STT + 1; j++)FirstDiem = FirstDiem->pNext; // chay den STT diem can xuat

	NODEDK* kDiem = FirstDiem;

	for (NODESV* k = First; (k != NULL || kDiem != NULL); k = k->pNext, kDiem = kDiem->pNext, i++)
	{
		++STT;
		gotoxy(x + round(newListCol.infoCol[0]->widthCol / 2.0), y + i * 2);
		cout << STT + 1;

		gotoxy(x + round(newListCol.infoCol[1]->widthCol / 2.0) + 3, y + i * 2);
		cout << k->data.MASV;

		gotoxy(x + round(newListCol.infoCol[2]->widthCol / 2.0) + 7, y + i * 2);
		cout << k->data.HO;

		gotoxy(x + 76, y + i * 2);
		cout << k->data.TEN;

		gotoxy(x + 114, y + i * 2);
		cout <<setprecision(2) << kDiem->data.DIEM;

		
				if (i == soDong-1) break;
	}

	int xConTro = x+114;
	i = batDau;

	DANGKY SVDK;
	SVDK.DIEM = 0;
	//float Diem=0;
	int j = batDau;
	NODEDK* k = DSDK.pHead;;
	for (int temp = 0; temp < j; temp++) k = k->pNext;
	int temp=y;
	/*showCursortype();
	gotoxy(xConTro, yConTro+2);
	xuLyNhapDiem(Diem, xConTro, yConTro);*/
	showCursortype();
	bool nhapDiem = true;
//NHAP_DIEM:
	while (nhapDiem)
	{
		
		temp = yConTro;
		for (NODEDK*tempDK =k;tempDK!=NULL || j==soDong-1; tempDK = tempDK->pNext,j++)
		{
			if (j == i)
			{
				//cout <<endl<< j << " " << i;

				SVDK.MASV = tempDK->data.MASV;
				SVDK.DIEM= tempDK->data.DIEM;
				j = batDau;
				break;
				
			}
		}
		
		//gotoxy(1, 5);
		//cout << "SVDK trc khi sua" << SVDK.DIEM;

		gotoxy(xConTro, yConTro);
		string str = to_string(SVDK.DIEM);
		str.erase(3, 8);
		if (str[str.length() - 1] == '0')
		{
			str.erase(1, 2);
		}

		xuLyNhapDiem(str, xConTro , yConTro);

		if (!str.empty())
			SVDK.DIEM = stof(str.c_str());

		
		//gotoxy(1, 2);
		//cout <<"sau khi sua" <<str;
		//cout <<"sau khi sua" <<SVDK.DIEM;

		if (yConTro == temp+3)
		{
			//gotoxy(1, 3);
			i++;
			if (i > STT+1) i = STT+1;
			//cout << i;
			yConTro = temp + 2;

			if (yConTro > y + (soDong-1) *2) yConTro = y + (soDong-1) *2;

			for (k = DSDK.pHead; k != NULL; k = k->pNext)
			{
				if (k->data.MASV == SVDK.MASV)
				{
					k->data.DIEM = SVDK.DIEM;
					break;
				}
			}
			
		}

		if (yConTro == temp - 3)
		{
			//gotoxy(1, 3);
			
			i--;
			if (i == 0) i = 1;
			
			//cout << i;
			yConTro = temp - 2;
			
			if (yConTro < y) yConTro = y;

			for (k = DSDK.pHead; k != NULL; k = k->pNext)
			{
				if (k->data.MASV == SVDK.MASV)
				{
					k->data.DIEM = SVDK.DIEM;
					break;
				}
			}
			
		}

		if (yConTro == 1)
		{
			key = 1;
			nhapDiem = false;
		}

		if (yConTro == 2)
		{
			key = 2;
			nhapDiem = false;
		}
		
		if (yConTro == 4)
		{
			for (k = DSDK.pHead; k != NULL; k = k->pNext)
			{
				if (k->data.MASV == SVDK.MASV)
				{
					k->data.DIEM = SVDK.DIEM;
					break;
				}
			}
			key = 4;
			nhapDiem = false;
		}

		if (yConTro == 0 )
		{
			key = 0;
			nhapDiem = false;
		}
	}
}

void nhapDSTheoTrang_Diem(LISTDK &DSDK, LISTLOP DSLSV)
{
	LISTSV DSSVDK;
	DSSVDK.pHead = NULL;
	DSSVDK.pTail = NULL;
	LISTDK DSDIEM;
	DSDIEM.pHead = NULL;
	DSDIEM.pTail = NULL;
	int soLuong = 0;


	thongKeDiemDS_DK(DSDK, DSLSV, DSSVDK, DSDIEM, soLuong);


	if (DSSVDK.pHead != NULL)
	{
		int tongSoDong = soLuong;
		int soDu = tongSoDong % maxDong1Trang;
		if (soDu > 0) soDu = 1;
		else soDu == 0;

		int soTrang = tongSoDong / maxDong1Trang + soDu;
		int trangHienTai = 1;
		
		int batDau = 0;
		int ketThuc;
		if (tongSoDong > maxDong1Trang) ketThuc = maxDong1Trang; else ketThuc = tongSoDong;

		LISTCOL newListCol = ListColDiem(1);
		char key=0;
		
		xuatTrang(trangHienTai, soTrang);

		nhapDS1Trang_Diem(DSSVDK, DSDIEM, batDau, ketThuc, newListCol,key);
		

		int x = xTable, y = yTable + 3;
		int yConTro = y;

		
		
		while (true)
		{
			//key = GetKey();
			
			if (key == 1)
			{
				key = LEFT;
			}
			else if (key == 2)
			{
				key = RIGHT;
			}
			else if (key == 4)
			{
				key = F4;
			}
			else if (key == 0)
			{
				key = ESC;
			}

			if (key == RIGHT)
			{
				if (trangHienTai <= soTrang)
				{
					hideCursortype();
					delete_Table(maxDong1Trang, newListCol);

					trangHienTai++;
					if (trangHienTai > soTrang) trangHienTai = soTrang;

					batDau = (trangHienTai - 1) * maxDong1Trang;
					if (tongSoDong > maxDong1Trang)
						ketThuc = batDau + maxDong1Trang;
					else ketThuc = tongSoDong;

					if (ketThuc > tongSoDong) ketThuc = batDau + tongSoDong % batDau;

					key = 0; 
					xuatTrang(trangHienTai, soTrang);
					nhapDS1Trang_Diem(DSSVDK, DSDIEM, batDau, ketThuc, newListCol,key);
					
					yConTro = y;
					//viTriChon = batDau + 1;
				}
				//cout <<"\n"<< batDau << " " << ketThuc<<endl;

			}
			else if (key == LEFT)
			{
				if (trangHienTai >= 1)
				{
					hideCursortype();
					//delete_Table(ketThuc, newListCol);
					trangHienTai--;
					if (trangHienTai == 0) trangHienTai = 1;

					batDau = (trangHienTai - 1) * maxDong1Trang;
					if (tongSoDong > maxDong1Trang)
						ketThuc = batDau + maxDong1Trang;
					else ketThuc = tongSoDong;

					if (ketThuc > tongSoDong) ketThuc = batDau + tongSoDong % batDau;

					//delete_Table(ketThuc, newListCol);
					key = 0;
					xuatTrang(trangHienTai, soTrang);
					nhapDS1Trang_Diem(DSSVDK, DSDIEM, batDau, ketThuc, newListCol,key);
					
					yConTro = y;
					//viTriChon = batDau + 1;
					//cout << "\n" << batDau << " " << ketThuc << endl;
				}
			}
			else if (key == F4)
			{
				luuDiemDS_DK(DSDK, DSDIEM);
				deleteListCol(newListCol);
				free_DK(DSDIEM);
				free_SV(DSSVDK);
				return;
				formNotifi("Luu diem thanh cong");
			}
			else if (key == ESC)
			{
				//viTriChon = -1;
				deleteListCol(newListCol);
				free_DK(DSDIEM);
				free_SV(DSSVDK);
				return;
			}
		}


	}
	else
	{
		formNotifi("Lop khong co sinh vien");
		return;
	}
}


void xuatDS1Trang_Diem(LISTSV DSSV, LISTDK DSDK,int batDau, int ketThuc, LISTCOL newListCol)
{
	int soDong = ketThuc % maxDong1Trang;
	if (soDong == 0) soDong = maxDong1Trang;
	draw_Table(soDong, newListCol);

	int STT = batDau - 1;
	int x = xTable, y = yTable + 3;
	int yConTro = y;
	int i = 0;

	NODESV* First = DSSV.pHead;
	for (int j = 0; j < STT + 1; j++) First = First->pNext; // chay den STT SV can xuat

	NODEDK* FirstDiem = DSDK.pHead;
	for (int j = 0; j < STT + 1; j++)FirstDiem = FirstDiem->pNext; // chay den STT diem can xuat

	NODEDK* kDiem = FirstDiem;

	for (NODESV* k = First; (k != NULL || kDiem!= NULL); k = k->pNext, kDiem = kDiem->pNext, i++)
	{
		++STT;
		gotoxy(x + round(newListCol.infoCol[0]->widthCol / 2.0), y + i * 2);
		cout << STT + 1;

		gotoxy(x + round(newListCol.infoCol[1]->widthCol / 2.0) + 3, y + i * 2);
		cout << k->data.MASV;

		gotoxy(x + round(newListCol.infoCol[2]->widthCol / 2.0) + 7, y + i * 2);
		cout << k->data.HO;

		gotoxy(x + 76, y + i * 2);
		cout << k->data.TEN;

		gotoxy(x + 114, y + i * 2);
		cout << kDiem->data.DIEM;


		if (i == soDong - 1) break;
	}

}


void xuatDSTheoTrang_Diem(LISTDK DSDK, LISTLOP DSLSV)
{

	LISTSV DSSVDK;
	DSSVDK.pHead = NULL;
	DSSVDK.pTail = NULL;
	LISTDK DSDIEM;
	DSDIEM.pHead = NULL;
	DSDIEM.pTail = NULL;
	int soLuong = 0;

	
		thongKeDiemDS_DK(DSDK, DSLSV, DSSVDK, DSDIEM, soLuong);
	

	if (DSSVDK.pHead != NULL)
	{
		int tongSoDong = soLuong;
		int soDu = tongSoDong % maxDong1Trang;
		if (soDu > 0) soDu = 1;
		else soDu == 0;

		int soTrang = tongSoDong / maxDong1Trang + soDu;
		int trangHienTai = 1;

		int batDau = 0;
		int ketThuc;
		if (tongSoDong > maxDong1Trang) ketThuc = maxDong1Trang; else ketThuc = tongSoDong;
	
		LISTCOL newListCol= ListColDiem(1);
		

		xuatDS1Trang_Diem(DSSVDK, DSDIEM, batDau, ketThuc, newListCol);
		xuatTrang(trangHienTai, soTrang);


		int x = xTable, y = yTable + 3;
		int yConTro = y;

		char key;
		while (true)
		{
			key = GetKey();

			if (key == RIGHT)
			{
				if (trangHienTai < soTrang)
				{
					
					delete_Table(maxDong1Trang, newListCol);

					trangHienTai++;
					if (trangHienTai > soTrang) trangHienTai = soTrang;

					batDau = (trangHienTai - 1) * maxDong1Trang;
					if (tongSoDong > maxDong1Trang)
						ketThuc = batDau + maxDong1Trang;
					else ketThuc = tongSoDong;

					if (ketThuc > tongSoDong) ketThuc = batDau + tongSoDong % batDau;


					xuatDS1Trang_Diem(DSSVDK, DSDIEM, batDau, ketThuc, newListCol);
					xuatTrang(trangHienTai, soTrang);
					yConTro = y;
					//viTriChon = batDau + 1;
				}
				//cout <<"\n"<< batDau << " " << ketThuc<<endl;

			}
			else if (key == LEFT)
			{
				if (trangHienTai > 1)
				{
					//delete_Table(ketThuc, newListCol);
					trangHienTai--;
					if (trangHienTai == 0) trangHienTai = 1;

					batDau = (trangHienTai - 1) * maxDong1Trang;
					if (tongSoDong > maxDong1Trang)
						ketThuc = batDau + maxDong1Trang;
					else ketThuc = tongSoDong;

					if (ketThuc > tongSoDong) ketThuc = batDau + tongSoDong % batDau;

					//delete_Table(ketThuc, newListCol);
					xuatDS1Trang_Diem(DSSVDK, DSDIEM, batDau, ketThuc, newListCol);
					xuatTrang(trangHienTai, soTrang);
					yConTro = y;
					//viTriChon = batDau + 1;
					//cout << "\n" << batDau << " " << ketThuc << endl;
				}
			}
			else if (key == ESC)
			{
				//viTriChon = -1;
				deleteListCol(newListCol);
				free_DK(DSDIEM);
				free_SV(DSSVDK);
				return;
			}
		}


	}
	else
	{
		formNotifi("Lop khong co sinh vien");
		return;
	}
}



void xuatDSTheoTrang_DiemTB(LISTSV DSSV,LISTLOPTC DSLTC)
{
	LISTDK DSDIEM;
	DSDIEM.pHead = NULL;
	DSDIEM.pTail = NULL;
	int soLuong = 0;

	thongKeDSDiemTB_SV(DSSV, DSLTC, DSDIEM, soLuong);

	int tongSoDong = soLuong;
	int soDu = tongSoDong % maxDong1Trang;
	if (soDu > 0) soDu = 1;
	else soDu == 0;

	int soTrang = tongSoDong / maxDong1Trang + soDu;
	int trangHienTai = 1;

	int batDau = 0;
	int ketThuc;
	if (tongSoDong > maxDong1Trang) ketThuc = maxDong1Trang; else ketThuc = tongSoDong;

	LISTCOL newListCol = ListColDiem(1);


	xuatDS1Trang_Diem(DSSV, DSDIEM, batDau, ketThuc, newListCol);
	xuatTrang(trangHienTai, soTrang);


	int x = xTable, y = yTable + 3;
	int yConTro = y;

	char key;
	while (true)
	{
		key = GetKey();

		if (key == RIGHT)
		{
			if (trangHienTai < soTrang)
			{
				delete_Table(maxDong1Trang, newListCol);

				trangHienTai++;
				if (trangHienTai > soTrang) trangHienTai = soTrang;

				batDau = (trangHienTai - 1) * maxDong1Trang;
				if (tongSoDong > maxDong1Trang)
					ketThuc = batDau + maxDong1Trang;
				else ketThuc = tongSoDong;

				if (ketThuc > tongSoDong) ketThuc = batDau + tongSoDong % batDau;


				xuatDS1Trang_Diem(DSSV, DSDIEM, batDau, ketThuc, newListCol);
				xuatTrang(trangHienTai, soTrang);
				yConTro = y;
				//viTriChon = batDau + 1;
			}
			//cout <<"\n"<< batDau << " " << ketThuc<<endl;

		}
		else if (key == LEFT)
		{
			if (trangHienTai > 1)
			{
				//delete_Table(ketThuc, newListCol);
				trangHienTai--;
				if (trangHienTai == 0) trangHienTai = 1;

				batDau = (trangHienTai - 1) * maxDong1Trang;
				if (tongSoDong > maxDong1Trang)
					ketThuc = batDau + maxDong1Trang;
				else ketThuc = tongSoDong;

				if (ketThuc > tongSoDong) ketThuc = batDau + tongSoDong % batDau;

				//delete_Table(ketThuc, newListCol);
				xuatDS1Trang_Diem(DSSV, DSDIEM, batDau, ketThuc, newListCol);
				xuatTrang(trangHienTai, soTrang);
				yConTro = y;
				//viTriChon = batDau + 1;
				//cout << "\n" << batDau << " " << ketThuc << endl;
			}
		}
		else if (key == ESC)
		{
			//viTriChon = -1;
			deleteListCol(newListCol);
			free_DK(DSDIEM);
			return;
		}
	}

}



void xuatDS1Trang_DiemTK(LISTSV DSSV,LISTLOPTC DSLTC, LOPSV LSV, int batDau, int ketThuc,MONHOC *ArrMH,int batDauMH, int ketThucMH,LISTCOL newListCol)
{

	/*================= THONG TIN SINH VEIN =======================*/
	int soDong = ketThuc % maxDong1Trang;
	if (soDong == 0) soDong = maxDong1Trang;
	draw_Table(soDong, newListCol);

	int STT = batDau - 1;
	int x = xTable, y = yTable + 3;
	int yConTro = y;
	int i = 0;

	NODESV* First = DSSV.pHead;
	for (int j = 0; j < STT + 1; j++) First = First->pNext; // chay den STT can xuat

	for (NODESV* k = First; (k != NULL); k = k->pNext, i++)
	{
		++STT;
		gotoxy(x + round(newListCol.infoCol[0]->widthCol / 2.0), y + i * 2);
		
			cout << STT + 1;

		gotoxy(x + round(newListCol.infoCol[1]->widthCol / 2.0) + 1, y + i * 2);
		cout << k->data.MASV;
		gotoxy(x + round(newListCol.infoCol[2]->widthCol / 2.0) + 3, y + i * 2);
		cout << k->data.HO;
		gotoxy(x + round(newListCol.infoCol[2]->widthCol / 2.0) + 4 + k->data.HO.length(), y + i * 2);
		cout << k->data.TEN;
		

		if (i == soDong - 1) break;
	}

	/*======================== MA MON HOC ================================*/
	int soDongMH = ketThucMH % maxCotMH1Trang;
	if (soDongMH == 0) soDongMH =maxCotMH1Trang;
	int STTMH = batDauMH - 1;


	for (int i = 0; i < soDongMH; i++)
	{
		++STTMH;
		gotoxy(x + 75 + (i-1)*10 , y-2);
		cout << ArrMH[STTMH].MAMH;
	}


	/*========================== DIEM ============================*/
	
	STTMH = batDauMH - 1;
	STT = batDau - 1;

	LISTDK DSDIEM;
	DSDIEM.pHead = NULL;
	DSDIEM.pTail = NULL;
	int soLuong = 0;
	for (int i = 0; i < soDongMH; i++)
	{
		DSDIEM.pHead = NULL;
		DSDIEM.pTail = NULL;
		++STTMH;
		thongKeDSDiemTK_SV(DSSV, DSLTC, DSDIEM, ArrMH[STTMH].MAMH,soLuong);
		
			First = DSSV.pHead;
		for (int j = 0; j <= STT; j++) First = First->pNext;
		

		if (DSDIEM.pHead != NULL) {
			

			/*for (; FirstDiem != NULL; FirstDiem = FirstDiem->pNext)
				cout << "\n" << FirstDiem->data.MASV << " " << FirstDiem->data.DIEM << ArrMH[STTMH].MAMH << " ";*/
			/*while (FirstDiem->data.MASV != First->data.MASV)
			{
				First = First->pNext;
				if (First->data.MASV == First->data.MASV) break;
			}*/
			int j = 0;
			for (NODESV* k = First; ((k != NULL)); k = k->pNext,j++)
			{
				gotoxy(x + 78 + (i - 1) * 10, y + j * 2);
				for (NODEDK* FirstDiem = DSDIEM.pHead; FirstDiem != NULL; FirstDiem = FirstDiem->pNext)
				{
					//cout << First->data.MASV << " -  " << FirstDiem->data.MASV;
					if (k->data.MASV == FirstDiem->data.MASV)
					{
						cout << FirstDiem->data.DIEM;
						break;
						//FirstDiem = FirstDiem->pNext;
					}
				}
				if (j == soDong - 1) break;
			}

			free_DK(DSDIEM);
			soLuong = 0;
		}
	}

	

}

void xuatDSTheoTrang_DiemTK(LISTLOPTC DSLTC,LISTSV DSSV,LOPSV LSV,TREE DSMH)
{
	int tongSoDong = LSV.soLuongSV;
	int soDu = tongSoDong % maxDong1Trang;
	if (soDu > 0) soDu = 1;
	else soDu == 0;

	int soTrang = tongSoDong / maxDong1Trang + soDu;
	int trangHienTai = 1;

	int batDau = 0;
	int ketThuc;
	if (tongSoDong > maxDong1Trang) ketThuc = maxDong1Trang; else ketThuc = tongSoDong;
	LISTCOL newListCol = ListColDiemTK();


		MONHOC* ArrMH = new MONHOC[soLuong_MH];
		int n = 0;
		chuyenCaythanhMang_MH(DSMH, ArrMH, n);
		sapXepTen_MH(ArrMH, n);
	

		int soDuMH = n % 6;
		if (soDuMH > 0) soDuMH = 1;
		else soDuMH == 0;

		int soTrangMH = n / 6 + soDuMH;
		int trangHienTaiMH = 1;

		int batDauMH = 0;
		int ketThucMH;
		if (n > 6) ketThucMH = 6; else ketThucMH = n;

		

	xuatDS1Trang_DiemTK(DSSV, DSLTC,LSV, batDau, ketThuc,ArrMH,batDauMH,ketThucMH, newListCol);
	xuatTrang(trangHienTai, soTrang);


	int x = xTable, y = yTable + 3;
	int yConTro = y;

	char key;
	while (true)
	{
		key = GetKey();

		if (key == RIGHT)
		{
			if (trangHienTai < soTrang)
			{
				
				delete_Table(maxDong1Trang, newListCol);

				trangHienTai++;
				if (trangHienTai > soTrang) trangHienTai = soTrang;

				batDau = (trangHienTai - 1) * maxDong1Trang;
				if (tongSoDong > maxDong1Trang)
					ketThuc = batDau + maxDong1Trang;
				else ketThuc = tongSoDong;

				if (ketThuc > tongSoDong) ketThuc = batDau + tongSoDong % batDau;


				xuatDS1Trang_DiemTK(DSSV, DSLTC,LSV, batDau, ketThuc, ArrMH, batDauMH, ketThucMH, newListCol);
				xuatTrang(trangHienTai, soTrang);
				yConTro = y;
				//viTriChon = batDau + 1;
			}
			//cout <<"\n"<< batDau << " " << ketThuc<<endl;

		}
		else if (key == LEFT)
		{
			if (trangHienTai > 1)
			{
				//delete_Table(ketThuc, newListCol);
				trangHienTai--;
				if (trangHienTai == 0) trangHienTai = 1;

				batDau = (trangHienTai - 1) * maxDong1Trang;
				if (tongSoDong > maxDong1Trang)
					ketThuc = batDau + maxDong1Trang;
				else ketThuc = tongSoDong;

				if (ketThuc > tongSoDong) ketThuc = batDau + tongSoDong % batDau;

				//delete_Table(ketThuc, newListCol);
				xuatDS1Trang_DiemTK(DSSV,DSLTC, LSV, batDau, ketThuc, ArrMH, batDauMH, ketThucMH, newListCol);
				xuatTrang(trangHienTai, soTrang);
				yConTro = y;
				//viTriChon = batDau + 1;
				//cout << "\n" << batDau << " " << ketThuc << endl;
			}
		}
		else if (key == UP)
		{
			if (trangHienTaiMH > 1)
			{
				//delete_Table(ketThuc, newListCol);
				trangHienTaiMH--;
				if (trangHienTaiMH == 0) trangHienTaiMH = 1;

				batDauMH = (trangHienTaiMH - 1) * maxCotMH1Trang;
				if (n > maxCotMH1Trang)
					ketThucMH = batDauMH + maxCotMH1Trang;
				else ketThucMH = n;

				if (ketThucMH > n) ketThucMH = batDauMH + n % batDauMH;

				//delete_Table(ketThuc, newListCol);
				xuatDS1Trang_DiemTK(DSSV,DSLTC, LSV, batDau, ketThuc, ArrMH, batDauMH, ketThucMH, newListCol);
				xuatTrang(trangHienTai, soTrang);
				yConTro = y;
				//viTriChon = batDau + 1;
				//cout << "\n" << batDau << " " << ketThuc << endl;
			}
		}
		else if (key == DOWN)
		{
			if (trangHienTaiMH < soTrangMH)
			{
				//delete_Table(ketThuc, newListCol);

				trangHienTaiMH++;
				if (trangHienTaiMH > soTrangMH) trangHienTaiMH = soTrangMH;

				batDauMH = (trangHienTaiMH - 1) * maxCotMH1Trang;
				if (n > maxCotMH1Trang)
					ketThucMH = batDauMH + maxCotMH1Trang;
				else ketThucMH = n;

				if (ketThucMH > n) ketThucMH = batDauMH + n % batDauMH;


				xuatDS1Trang_DiemTK(DSSV,DSLTC, LSV, batDau, ketThuc, ArrMH, batDauMH, ketThucMH, newListCol);
				xuatTrang(trangHienTai, soTrang);
				yConTro = y;
				//viTriChon = batDau + 1;
			}
			//cout <<"\n"<< batDau << " " << ketThuc<<endl;
		}


		else if (key == ESC)
		{
			delete[] ArrMH;
			deleteListCol(newListCol);
			return;
		}

		


	}

}

/*
=========================================================================
======================== Ket thuc xu ly dang ky =========================
=========================================================================
*/







/*
=========================================================================
========================= Phan xu ly DS Lop SV ==========================
=========================================================================
*/





bool isFull_LSV(LISTLOP DSLSV)
{
	return (DSLSV.n == MAXLOPSV ? true : false);
}

bool them_LSV(LISTLOP& DSLSV, LOPSV Lop)
{
	if (isFull_LSV(DSLSV))
	{
		return 0;
	}
	else
	{
		DSLSV.Lop[DSLSV.n++] = Lop;
		return 1;
	}
}

int timMaLop_LSV(LISTLOP& DSLSV, string MALOP)
{
	for (int i = 0; i < DSLSV.n; i++)
	{
		if (DSLSV.Lop[i].MALOP == MALOP) return i;

	}
	return -1;
}

void nhap_LSV(LISTLOP& DSLSV)
{
	formThem_LSV("Them lop");

	LOPSV LSV;
	LSV.soLuongSV = 0;
	LSV.DSSV.pHead = NULL;
	LSV.DSSV.pTail = NULL;

	int x = 87, y = 20;
	gotoxy(x, y);

	int yConTro = y;
	SetColor(clblack, cllightwhite);

	while (true)
	{
		showCursortype();
		if (yConTro < y + 3)
		{
			drawButton(86, 24, 10);
			gotoxy(89, 25);
			cout << "Luu";

			drawButton(108, 24, 10);
			gotoxy(112, 25);
			cout << "Huy";
		}

		if (yConTro == y)
		{
			gotoxy(x + LSV.MALOP.length(), yConTro);
			xuLyNhapMaLop(LSV.MALOP, 11, x + LSV.MALOP.length(), yConTro);

			if (yConTro < y) yConTro = y;
		}

		if (yConTro == y + 3)
		{
			hideCursortype();
			int chon = 1;
			while (chon)
			{
				
				char key;

				if (chon == 1)
				{
					drawEffectButton(86, 24, 10);
					gotoxy(89, 25);
					cout << "Luu";

					drawButton(108, 24, 10);
					gotoxy(112, 25);
					cout << "Huy";
				}
				else if (chon == 2)
				{
					drawButton(86, 24, 10);
					gotoxy(89, 25);
					cout << "Luu";

					drawEffectButton(108, 24, 10);
					gotoxy(112, 25);
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
				else if (key == UP)
				{
					yConTro = y;
					chon = 0;
				}
				else if (key == ENTER)
				{
					if (chon == 1)
					{
						int viTri = timMaLop_LSV(DSLSV, LSV.MALOP);
						if (viTri > 0)
						{
							printNotifi(95, 28, "Ma lop bi trung");
						}
						else if (!LSV.MALOP.empty())
						{
							them_LSV(DSLSV, LSV);
							yConTro = 0;
							chon = 0;

							hideCursortype();

							formNotifi("Them lop thanh cong");
							return;
						}
						else {
							formNotifi("Vui long nhap day du thong tin");
						}
					}
					else if (chon == 2)
					{
						yConTro = 0;
						chon = 0;
					}
				}

			}
		}
		else if (yConTro == 0)
		{
			//hideCursortype();

			//formNotifi("Them lop thanh cong");

			return;
		}
	}

}

void xuatDS1Trang_LSV(LISTLOP DSLSV, int batDau, int ketThuc, LISTCOL newListCol, int luaChon, int& viTriChon)
{
	int soDong = ketThuc % maxDong1Trang;
	if (soDong == 0) soDong = maxDong1Trang;
	draw_Table(soDong, newListCol);

	int STT = batDau - 1;
	int x = xTable, y = yTable + 3;
	int yConTro = y;

	for (int i = 0; i < soDong; i++)
	{
		++STT;
		gotoxy(x + round(newListCol.infoCol[0]->widthCol / 2.0), y + i * 2);
		if (luaChon == 1) // xuat STT
			cout << STT + 1;
		else if (luaChon == 2) // xuat mui ten
		{
			if (i == 0)
			{
				cout << "->";
			}
		}

		gotoxy(x + round(newListCol.infoCol[0]->widthCol) + 2, y + i * 2);
		cout << DSLSV.Lop[STT].MALOP;
		gotoxy(x + newListCol.infoCol[1]->widthCol + 8, y + i * 2);
		cout << DSLSV.Lop[STT].soLuongSV;
	}
}

void xuatDSTheoTrang_LSV(LISTLOP DSLSV, int luaChon, int& viTriChon)
{
	int tongSoDong = DSLSV.n;
	int soDu = tongSoDong % maxDong1Trang;
	if (soDu > 0) soDu = 1;
	else soDu == 0;

	int soTrang = tongSoDong / maxDong1Trang + soDu;
	int trangHienTai = 1;

	int batDau = 0;
	int ketThuc;
	if (tongSoDong > maxDong1Trang) ketThuc = maxDong1Trang; else ketThuc = tongSoDong;
	LISTCOL newListCol = ListColLopSV();

	xuatDS1Trang_LSV(DSLSV, batDau, ketThuc, newListCol, luaChon, viTriChon);
	xuatTrang(trangHienTai, soTrang);


	int x = xTable, y = yTable + 3;
	int yConTro = y;

	char key;
	while (true)
	{
		key = GetKey();

		if (key == RIGHT)
		{
			if (trangHienTai < soTrang)
			{
				
				delete_Table(maxDong1Trang, newListCol);

				trangHienTai++;
				if (trangHienTai > soTrang) trangHienTai = soTrang;

				batDau = (trangHienTai - 1) * maxDong1Trang;
				if (tongSoDong > maxDong1Trang)
					ketThuc = batDau + maxDong1Trang;
				else ketThuc = tongSoDong;

				if (ketThuc > tongSoDong) ketThuc = batDau + tongSoDong % batDau;


				xuatDS1Trang_LSV(DSLSV, batDau, ketThuc, newListCol, luaChon, viTriChon);
				xuatTrang(trangHienTai, soTrang);
				yConTro = y;
				viTriChon = batDau + 1;
			}
			//cout <<"\n"<< batDau << " " << ketThuc<<endl;

		}
		else if (key == LEFT)
		{
			if (trangHienTai > 1)
			{
				//delete_Table(ketThuc, newListCol);
				trangHienTai--;
				if (trangHienTai == 0) trangHienTai = 1;

				batDau = (trangHienTai - 1) * maxDong1Trang;
				if (tongSoDong > maxDong1Trang)
					ketThuc = batDau + maxDong1Trang;
				else ketThuc = tongSoDong;

				if (ketThuc > tongSoDong) ketThuc = batDau + tongSoDong % batDau;

				//delete_Table(ketThuc, newListCol);
				xuatDS1Trang_LSV(DSLSV, batDau, ketThuc, newListCol, luaChon, viTriChon);
				xuatTrang(trangHienTai, soTrang);
				yConTro = y;
				viTriChon = batDau + 1;
				//cout << "\n" << batDau << " " << ketThuc << endl;
			}
		}
		else if (key == ESC)
		{
			viTriChon = -1;
			deleteListCol(newListCol);
			return;
		}

		if (luaChon == 2 || luaChon == 3)
		{
			int soDong = ketThuc % maxDong1Trang;
			if (soDong == 0) soDong = maxDong1Trang;
			//int key;
			/*bool run = true;
			while (run)
			{*/

			//key = GetKey();

			if (key == UP)
			{
				gotoxy(x + round(newListCol.infoCol[0]->widthCol / 2.0), yConTro);
				cout << "  ";

				yConTro = whereY() - 2;

				if (yConTro < y) yConTro = y;

				gotoxy(x + round(newListCol.infoCol[0]->widthCol / 2.0), yConTro);
				cout << "->";


				viTriChon--;
				if (viTriChon < 1) viTriChon = 1;
			}
			else if (key == DOWN)
			{
				gotoxy(x + round(newListCol.infoCol[0]->widthCol / 2.0), yConTro);
				cout << "  ";
				yConTro = whereY() + 2;

				if (yConTro == y + soDong * 2) yConTro = y + (soDong - 1) * 2;

				gotoxy(x + round(newListCol.infoCol[0]->widthCol / 2.0), yConTro);
				cout << "->";

				viTriChon++;
				if (viTriChon == soDong) viTriChon = soDong;

			}
			else if (key == ESC)
			{

				return;
			}
			else if (key == ENTER)
			{
				delete_Table(ketThuc, newListCol);
				return;
			}
			else if (key == LEFT || key == RIGHT)
			{
				//run = false;
			}

			//}
		}


	}
}

void chon_LSV(LISTLOP& DSLSV, LISTLOPTC DSLTC,TREE DSMH, int luaChon)
{
	if (DSLSV.n > 0)
	{
		int viTriChon = 1;
		if (luaChon == 1)
		{

			xuatDSTheoTrang_LSV(DSLSV, 2, viTriChon);
			if (viTriChon > 0)
			{
				SINHVIEN SV;

				SV.MALOP = "";
				SV.HO = "";
				SV.TEN = "";

				nhap_SV(DSLSV.Lop[viTriChon - 1], DSLSV.Lop[viTriChon - 1].DSSV, SV, luaChon);
			}

		}
		else if (luaChon == 2) // xuat ds 1 lop 
		{
			do {
				viTriChon = 1;
				xuatDSTheoTrang_LSV(DSLSV, 2, viTriChon);
				if (viTriChon > 0 && DSLSV.Lop[viTriChon - 1].soLuongSV > 0)
					chon_SV(DSLSV.Lop[viTriChon - 1].DSSV, DSLSV.Lop[viTriChon - 1], 1);
				else if (viTriChon != -1) formNotifi("Lop khong co sinh vien nao");
			} while (DSLSV.Lop[viTriChon - 1].soLuongSV == 0 && viTriChon != -1);
		}
		else if (luaChon == 3) // sua
		{
			do {
				viTriChon = 1;
				xuatDSTheoTrang_LSV(DSLSV, 2, viTriChon);
				if (viTriChon > 0 && DSLSV.Lop[viTriChon - 1].soLuongSV > 0) {
					chon_SV(DSLSV.Lop[viTriChon - 1].DSSV, DSLSV.Lop[viTriChon - 1], 3);
					formNotifi("Sua thanh cong");
				}
				else if (viTriChon != -1) formNotifi("Lop khong co sinh vien nao");
			} while (DSLSV.Lop[viTriChon - 1].soLuongSV == 0 && viTriChon != -1);
		}
		else if (luaChon == 4) // xoa
		{
			do {
				viTriChon = 1;
				xuatDSTheoTrang_LSV(DSLSV, 2, viTriChon);
				if (viTriChon > 0 && DSLSV.Lop[viTriChon - 1].soLuongSV > 0)
				{
					chon_SV(DSLSV.Lop[viTriChon - 1].DSSV, DSLSV.Lop[viTriChon - 1], 2);
					DSLSV.Lop[viTriChon - 1].soLuongSV--;
					formNotifi("Xoa thanh cong");
				}
				else if (viTriChon != -1) formNotifi("Lop khong co sinh vien nao");
			} while (DSLSV.Lop[viTriChon - 1].soLuongSV == 0 && viTriChon != -1);
		}
		else if (luaChon == 5)
		{

			do {
				viTriChon = 1;
				xuatDSTheoTrang_LSV(DSLSV, 2, viTriChon);
				if (viTriChon > 0 && DSLSV.Lop[viTriChon - 1].soLuongSV > 0)
				{
					xuatDSTheoTrang_DiemTB(DSLSV.Lop[viTriChon - 1].DSSV, DSLTC);
				}
				else if (viTriChon != -1) formNotifi("Lop khong co sinh vien nao");
			} while (DSLSV.Lop[viTriChon - 1].soLuongSV == 0 && viTriChon != -1);

		}
		else if (luaChon == 6) // xuat diem TK
		{
			do {
				viTriChon = 1;
				xuatDSTheoTrang_LSV(DSLSV, 2, viTriChon);
				if (viTriChon > 0 && DSLSV.Lop[viTriChon - 1].soLuongSV > 0)
				{
					xuatDSTheoTrang_DiemTK(DSLTC,DSLSV.Lop[viTriChon - 1].DSSV, DSLSV.Lop[viTriChon-1],DSMH);
				}
				else if (viTriChon != -1) formNotifi("Lop khong co sinh vien nao");
			} while (DSLSV.Lop[viTriChon - 1].soLuongSV == 0 && viTriChon != -1);
		}
	}
	else
	{
		return;
	}
}


/*
=========================================================================
====================== Ket thuc xu ly DS Lop SV =========================
=========================================================================
*/










/*
=========================================================================
========================== Phan xu ly Lop TC ============================
=========================================================================
*/

bool isNull_LTC(LISTLOPTC DSLTC)
{
	return (DSLTC.n==0 ? true : false);
}

bool isFull_LTC(LISTLOPTC DSLTC)
{
	return (DSLTC.n == MAXLOPTC ? true : false);
}

LOPTC* tao_LTC()
{
	LOPTC *LTC = new LOPTC;
	LTC->KHOA = 2019;
	LTC->HOCKY = 0;
	LTC->NHOM = 0;
	LTC->SVMAX = 0;
	LTC->DSDK.pHead = NULL;
	LTC->DSDK.pTail = NULL;

	return LTC;
}

int them_LTC(LISTLOPTC& DSLTC,LOPTC* LTC)
{
	if (isFull_LTC(DSLTC))
	{
		return 0;
	}
	else
	{
		//DSLTC.LopTC[DSLTC.n] = new LOPTC;
		DSLTC.LopTC[DSLTC.n++] = LTC;
	}
	return 1;
}

void hoanVi_LTC(LOPTC* a, LOPTC* b)
{
	LOPTC* temp= new LOPTC;

	temp->MALOPTC = a->MALOPTC;
	temp->MAMH = a->MAMH;
	temp->KHOA = a->KHOA;
	temp->HOCKY = a->HOCKY;
	temp->NHOM = a->NHOM;
	temp->SVMAX = a->SVMAX;
	temp->DSDK = a->DSDK;

	a->MALOPTC = b->MALOPTC;
	a->MAMH = b->MAMH;
	a->KHOA = b->KHOA;
	a->HOCKY = b->HOCKY;
	a->NHOM = b->NHOM;
	a->SVMAX = b->SVMAX;
	a->DSDK = b->DSDK;


	b->MALOPTC = temp->MALOPTC;
	b->MAMH = temp->MAMH;
	b->KHOA = temp->KHOA;
	b->HOCKY = temp->HOCKY;
	b->NHOM = temp->NHOM;
	b->SVMAX = temp->SVMAX;
	b->DSDK = temp->DSDK;

	delete temp;
}


/*void sapXep_LTC(LISTLOPTC& DSLTC,TREE DSMH)
{
	if (DSLTC.n > 1)
	{
		string iStr, jStr;
		for (int i = 0; i < DSLTC.n - 1; i++)
		{
			tim_MH(DSMH, DSLTC.LopTC[i]->MAMH, iStr);
			for (int j = i+1; j < DSLTC.n; j++)
			{
				tim_MH(DSMH, DSLTC.LopTC[j]->MAMH, jStr);
				if (jStr.compare(iStr) < 0)  // jStr < iStr
				{
					hoanVi_LTC(DSLTC.LopTC[i], DSLTC.LopTC[j]);
					iStr = jStr;
					//tim_MH(DSMH, DSLTC.LopTC[i]->MAMH, iStr);
				}
			}
			
		}
	}
}*/

void sapXep_LTC(LISTLOPTC& DSLTC, TREE DSMH) // Selection Sort
{
	if (DSLTC.n > 1)
	{
		int i, j, min_idx;
		string iStr, jStr;
		
		for (i = 0; i < DSLTC.n - 1; i++)
		{
			min_idx = i;
			tim_MH(DSMH, DSLTC.LopTC[min_idx]->MAMH, iStr);
			
			for (j = i + 1; j < DSLTC.n; j++)
			{
				tim_MH(DSMH, DSLTC.LopTC[j]->MAMH, jStr);
				if (jStr < iStr)
				{
					min_idx = j;
					iStr = jStr;
					//tim_MH(DSMH, DSLTC.LopTC[min_idx]->MAMH, iStr);
				}
				
			}
			
			hoanVi_LTC(DSLTC.LopTC[min_idx], DSLTC.LopTC[i]);
		}
	}
	
}

int timMaLop_LTC(LISTLOPTC DSLTC, int maLopTC)
{
	for (int i = 0; i < DSLTC.n; i++)
	{
		if (DSLTC.LopTC[i]->MALOPTC == maLopTC) return i;
	}
	return -1;
}

void freeDS_LTC(LISTLOPTC& DSLTC)
{
	if (DSLTC.n < 0)
	{
		return;
	}
	else
	{
		for (int i = 0; i < DSLTC.n; i++)
		{
			delete DSLTC.LopTC[i];
		}
	}
}

int checkMaLop_LTC(LISTLOPTC& DSLTC, int maLop)
{
	for (int i = 0; i < DSLTC.n; i++)
	{
		if (DSLTC.LopTC[i]->MALOPTC == maLop)
			return i;
	}
	return -1;
}

void chinhSua_LTC(LISTLOPTC& DSLTC, LOPTC *LTC)
{
	int viTriSua = checkMaLop_LTC(DSLTC, LTC->MALOPTC);
	if (viTriSua >= 0)
	{
		DSLTC.LopTC[viTriSua]->KHOA = LTC->KHOA;
		DSLTC.LopTC[viTriSua]->HOCKY = LTC->HOCKY;
		DSLTC.LopTC[viTriSua]->NHOM = LTC->NHOM;
		DSLTC.LopTC[viTriSua]->SVMAX = LTC->SVMAX;

	}
	else cout << "\nKhong tim thay ma lop tc";
}

void xoa_LTC(LISTLOPTC& DSLTC, int maLop)
{
	int viTriXoa = checkMaLop_LTC(DSLTC, maLop);
	if (viTriXoa >= 0)
	{
		for (int i = viTriXoa; i < DSLTC.n - 1; i++)
		{
			DSLTC.LopTC[i] = DSLTC.LopTC[i + 1];
		}

		LOPTC* temp = DSLTC.LopTC[DSLTC.n];
		
		DSLTC.n--;
	}
	else cout << "\nKhong tim thay ma lop tc";
}

bool checkTrungMaLop_LTC(LISTLOPTC DSLTC, int maLop)
{
	if (!isNull_LTC(DSLTC))
	{
		for (int i = 0; i < DSLTC.n; i++)
		{
			if (DSLTC.LopTC[i]->MALOPTC == maLop)
				return true;
		}
	}
	return false;
}

int taoMaLop_LTC()
{
	// ramdom trong khoang [a;b] -> int rand = rand() % (b-a+1) +a;
	srand(time(NULL));
	int maLop = 0;
	while (true)
	{
		int iMa = rand() % (9 - 0 + 1) + 0;
		maLop = maLop * 10 + iMa;
		if (maLop > 100) break;
	}
	return maLop;
}

MONHOC chonMH_LTC(TREE& DSMH)
{
	MONHOC MH;
	if (DSMH != NULL)
	{
		MONHOC* ArrMH = new MONHOC[soLuong_MH];
		int n = 0;
		chuyenCaythanhMang_MH(DSMH, ArrMH, n);
		sapXepTen_MH(ArrMH, n);

		int viTriChon = 1;
		
		
			xuatDSTheoTrang_MH(ArrMH, n, 2, viTriChon);
			if (viTriChon != -1)
			{
				MH.MAMH = ArrMH[viTriChon - 1].MAMH;
				MH.TENMH = ArrMH[viTriChon - 1].TENMH;
			}
			else {
				MH.MAMH ="-1";
			}

		delete[] ArrMH;
	}
	
	return MH;
}

void nhap_LTC(LISTLOPTC& DSLTC,TREE DSMH,LOPTC *LTC, int luaChon)
{
	/*
		luaChon == 1 -> them LTC
		luaChon == 2 -> sua LTC 
	*/
	

	
	MONHOC MH;

	

	if (luaChon == 1)
	{
		MH = chonMH_LTC(DSMH);

		if (MH.MAMH == "-1") return;

		do
		{
			LTC->MALOPTC = taoMaLop_LTC();
		} while (checkTrungMaLop_LTC(DSLTC, LTC->MALOPTC)==true);


		LTC->MAMH = MH.MAMH;

		formThem_LTC("Them Lop TC");
		
	}
		
	else if (luaChon == 2)
	{
		//NODEMH* pMH = search_MH(DSMH, MH.MAMH);
		tim_MH(DSMH, LTC->MAMH, MH.TENMH);
		//MH.TENMH = pMH->data.TENMH;
		formThem_LTC("Sua Lop TC");
		
	}

	
	int x = 89, y = 10;
	//gotoxy(x, y);

	int yConTro = y;
	SetColor(clblack, cllightwhite);

	

	gotoxy(x, y);
	cout << LTC->MALOPTC;
	gotoxy(x, y + 3);
	cout << LTC->MAMH;
	gotoxy(x, y + 6);
	cout << MH.TENMH;
	gotoxy(x, y + 9);
	cout << LTC->KHOA;
	gotoxy(x, y + 12);
	cout << LTC->HOCKY;
	gotoxy(x, y + 15);
	cout << LTC->NHOM;
	gotoxy(x, y + 18);
	cout << LTC->SVMAX;


	yConTro = y + 9;
	while (true)
	{
		showCursortype();
		if (yConTro < y + 21)
		{
			drawButton(87, 31, 10);
			gotoxy(90, 32);
			cout << "Luu";

			drawButton(109, 31, 10);
			gotoxy(113, 32);
			cout << "Huy";
		}

		if (yConTro == y + 9)
		{
			gotoxy(x+4, yConTro);
			xuLyNhapSo(LTC->KHOA, 4, x+3, yConTro);

			if (yConTro == 0) return;
			if (yConTro < y+9) yConTro = y+9;
			
		}
		else if(yConTro == y + 12)
		{
			
			gotoxy(x+1, yConTro);
			xuLyNhapSo(LTC->HOCKY, 2, x, yConTro);

				if (yConTro == 0) return;
		}
		else if (yConTro == y + 15)
		{
			gotoxy(x + 1, yConTro);
			xuLyNhapSo(LTC->NHOM, 2, x, yConTro);
			if (yConTro == 0) return;
		}
		else if (yConTro == y + 18)
		{
			if (LTC->SVMAX >= 100)
			{
				gotoxy(x + 3, yConTro);
				xuLyNhapSo(LTC->SVMAX, 3, x+2, yConTro);
			}
			else if (LTC->SVMAX >= 10)
			{
				gotoxy(x + 2, yConTro);
				xuLyNhapSo(LTC->SVMAX, 3, x + 1, yConTro);
			}
			else
			{
				gotoxy(x + 1, yConTro);
				xuLyNhapSo(LTC->SVMAX, 3, x, yConTro);
			}
			if (yConTro == 0) return;
			 
		}
		else if (yConTro == y + 21)
		{
			int chon = 1;
			while (chon)
			{
				hideCursortype();
				char key;

				if (chon == 1)
				{
					drawEffectButton(87, 31, 10);
					gotoxy(90, 32);
					cout << "Luu";

					drawButton(109, 31, 10);
					gotoxy(113, 32);
					cout << "Huy";
				}
				else if (chon == 2)
				{
					drawButton(87, 31, 10);
					gotoxy(90, 32);
					cout << "Luu";

					drawEffectButton(109, 31, 10);
					gotoxy(113, 32);
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
				else if (key == UP)
				{
					yConTro = y + 9;
					chon = 0;
				}
				else if (key == ESC)
				{
					yConTro = 0;
					luaChon = 0;
					chon = 0;
				}
				else if (key == ENTER)
				{
					if (chon == 1)
					{
						if (luaChon == 1) // them
						{
							if (LTC->HOCKY == 0)
							{
								printNotifi(110, 33, "Du lieu khong hop le");
							}
							else
							{
								them_LTC(DSLTC, LTC);
								yConTro = 0;
								chon = 0;
							}
						}
						else if (luaChon == 2) // sua
						{
							
							chinhSua_LTC(DSLTC, LTC);
							yConTro = 0;
							chon = 0;
						}
					}
					else if (chon == 2)
					{
						luaChon = 0;
						yConTro = 0;
						chon = 0;
						
					}
				}
			}
		}
		else if (yConTro == 0)
		{
			hideCursortype();
			if (luaChon == 1)
			{
				formNotifi("Them Lop TC thanh cong");
			}
			else if (luaChon == 2)
			{
				formNotifi("Sua Lop TC thanh cong");

			}
			return;
		}

	}
}

void xuatDS1Trang_LTC(LISTLOPTC DSLTC,TREE DSMH, int batDau, int ketThuc, LISTCOL newListCol, int luaChon, int& viTriChon)
{
	int soDong = ketThuc % maxDong1Trang;
	if (soDong == 0) soDong = maxDong1Trang;
	draw_Table(soDong, newListCol);

	int STT = batDau - 1;
	int x = xTable, y = yTable + 3;
	int yConTro = y;

	string TENMH;
	for (int i = 0; i < soDong; i++)
	{
		++STT;
		gotoxy(x + round(newListCol.infoCol[0]->widthCol / 2.0), y + i * 2);
		if (luaChon == 1) // xuat STT
			cout << STT + 1;
		else if (luaChon == 2 || luaChon == 3 || luaChon == 4 || luaChon == 5 ) // xuat mui ten
		{
			if (i == 0)
			{
				cout << "->";
			}
		}
		
		tim_MH(DSMH, DSLTC.LopTC[STT]->MAMH, TENMH);
		
		gotoxy(x + round(newListCol.infoCol[1]->widthCol / 2.0)+5, y + i * 2);
		cout << DSLTC.LopTC[STT]->MALOPTC;
		gotoxy(x + round(newListCol.infoCol[2]->widthCol / 2.0)+12, y + i * 2);
		cout << DSLTC.LopTC[STT]->MAMH;
		gotoxy(x + newListCol.infoCol[3]->widthCol -6 , y + i * 2);
		cout << TENMH;
		gotoxy(x + 75, y + i * 2);
		cout << DSLTC.LopTC[STT]->KHOA;
		gotoxy(x + 85, y + i * 2);
		cout << DSLTC.LopTC[STT]->HOCKY;
		gotoxy(x + 94, y + i * 2);
		cout << DSLTC.LopTC[STT]->NHOM;
		gotoxy(x + 106, y + i * 2);
		cout << DSLTC.LopTC[STT]->SVMAX;
	}
}

void xuatDSTheoTrang_LTC(LISTLOPTC DSLTC,TREE DSMH, int luaChon, int& viTriChon)
{
	int tongSoDong = DSLTC.n;
	int soDu = tongSoDong % maxDong1Trang;
	if (soDu > 0) soDu = 1;
	else soDu == 0;

	int soTrang = tongSoDong / maxDong1Trang + soDu;
	int trangHienTai = 1;

	int batDau = 0;
	int ketThuc;
	if (tongSoDong > maxDong1Trang) ketThuc = maxDong1Trang; else ketThuc = tongSoDong;
	LISTCOL newListCol = ListColLopTC();
	xuatDS1Trang_LTC(DSLTC,DSMH, batDau, ketThuc, newListCol, luaChon, viTriChon);
	xuatTrang(trangHienTai, soTrang);
	
	int x = xTable, y = yTable + 3;
	int yConTro = y;

	char key;
	while (true)
	{
		key = GetKey();

		if (key == RIGHT)
		{
			if (trangHienTai < soTrang)
			{
				delete_Table(maxDong1Trang, newListCol);

				trangHienTai++;
				if (trangHienTai > soTrang) trangHienTai = soTrang;

				batDau = (trangHienTai - 1) * maxDong1Trang;
				if (tongSoDong > maxDong1Trang)
					ketThuc = batDau + maxDong1Trang;
				else ketThuc = tongSoDong;

				if (ketThuc > tongSoDong) ketThuc = batDau + tongSoDong % batDau;

				
				xuatDS1Trang_LTC(DSLTC, DSMH, batDau, ketThuc, newListCol, luaChon, viTriChon);
				xuatTrang(trangHienTai, soTrang);
				yConTro = y;
				viTriChon = batDau + 1;
			}
			//cout <<"\n"<< batDau << " " << ketThuc<<endl;

		}
		else if (key == LEFT)
		{
			if (trangHienTai > 1)
			{
				//delete_Table(ketThuc, newListCol);
				trangHienTai--;
				if (trangHienTai == 0) trangHienTai = 1;

				batDau = (trangHienTai - 1) * maxDong1Trang;
				if (tongSoDong > maxDong1Trang)
					ketThuc = batDau + maxDong1Trang;
				else ketThuc = tongSoDong;

				if (ketThuc > tongSoDong) ketThuc = batDau + tongSoDong % batDau;

				//delete_Table(ketThuc, newListCol);
				xuatDS1Trang_LTC(DSLTC, DSMH, batDau, ketThuc, newListCol, luaChon, viTriChon);
				xuatTrang(trangHienTai, soTrang);
				yConTro = y;
				viTriChon = batDau + 1;
				//cout << "\n" << batDau << " " << ketThuc << endl;
			}
		}
		else if (key == ESC)
		{
			viTriChon = -1;
			xoaTrang();
			delete_Table(maxDong1Trang, newListCol);
			deleteListCol(newListCol);
			return;
		}

		if (luaChon == 2 || luaChon == 3 || luaChon==4 || luaChon ==5)
		{
			int soDong = ketThuc % maxDong1Trang;
			if (soDong == 0) soDong = maxDong1Trang;
			
			if (key == UP)
			{
				gotoxy(x + round(newListCol.infoCol[0]->widthCol / 2.0), yConTro);
				cout << "  ";

				yConTro = whereY() - 2;

				if (yConTro < y) yConTro = y;

				gotoxy(x + round(newListCol.infoCol[0]->widthCol / 2.0), yConTro);
				cout << "->";


				viTriChon--;
				if (viTriChon < 1) viTriChon = 1;
			}
			else if (key == DOWN)
			{
				gotoxy(x + round(newListCol.infoCol[0]->widthCol / 2.0), yConTro);
				cout << "  ";
				yConTro = whereY() + 2;

				if (yConTro == y + soDong * 2) yConTro = y + (soDong - 1) * 2;

				gotoxy(x + round(newListCol.infoCol[0]->widthCol / 2.0), yConTro);
				cout << "->";

				viTriChon++;
				if (viTriChon == soDong) viTriChon = soDong;

			}
			else if (key == ESC)
			{

				return;
			}
			else if (key == ENTER)
			{
				xoaTrang();
				delete_Table(maxDong1Trang, newListCol);
				return;
			}
			else if (key == LEFT || key == RIGHT)
			{
					
			}

				
		}


	}
}

void chon_LTC(LISTLOPTC &DSLTC,TREE DSMH,LISTLOP DSLSV,int luaChon)
{
	if (DSLTC.n > 0)
	{
		int viTriChon = 1;
		if (luaChon == 1) // xuat
		{
			xuatDSTheoTrang_LTC(DSLTC,DSMH, 1, viTriChon);
		}
		else if (luaChon == 2) // xoa
		{
			xuatDSTheoTrang_LTC(DSLTC, DSMH, 2, viTriChon);
			
			if (viTriChon != -1)
			{
				bool xacNhan = true;
				formConfirm("Ban co chac chan xoa", xacNhan);
				if (xacNhan)
				{
					xoa_LTC(DSLTC, DSLTC.LopTC[viTriChon - 1]->MALOPTC);
					formNotifi("Xoa Lop TC thanh cong");
				}
				else return;
			}
				
		}
		else if (luaChon == 3) // sua
		{
			xuatDSTheoTrang_LTC(DSLTC, DSMH, 3, viTriChon);
			cout << viTriChon;
			if (viTriChon != -1)
			{
				if (DSLTC.LopTC[viTriChon - 1]->DSDK.pHead==NULL) {
					nhap_LTC(DSLTC, DSMH, DSLTC.LopTC[viTriChon - 1], 2);
				}
				else
				{
					formNotifi("Da co sinh vien, khong the sua");
				}
			}
		}
		else if (luaChon == 4) // xuat DS dang ki LTC
		{
			xuatDSTheoTrang_LTC(DSLTC, DSMH, 3, viTriChon);
			cout << viTriChon;
			if (viTriChon != -1)
			{
				xuatDSTheoTrang_DK(DSLTC.LopTC[viTriChon - 1]->DSDK, DSLSV);
			}
		}
		else if (luaChon == 5) // chon LTC de xuat diem 
		{
			xuatDSTheoTrang_LTC(DSLTC, DSMH, 3, viTriChon);
			if (viTriChon != -1)
			{
				xuatDSTheoTrang_Diem(DSLTC.LopTC[viTriChon - 1]->DSDK, DSLSV);
			}
		}
		else if (luaChon == 6) // chon LTC de nhap diem
		{
			xuatDSTheoTrang_LTC(DSLTC, DSMH, 3, viTriChon);
			if (viTriChon != -1)
			{
				nhapDSTheoTrang_Diem(DSLTC.LopTC[viTriChon - 1]->DSDK, DSLSV);
			}
		}
		
	}
	else {
		formNotifi("Khong co lop TC nao");
		return;
	}
}

/*
=========================================================================
======================== Ket thuc xu ly lop TC ==========================
=========================================================================
*/



