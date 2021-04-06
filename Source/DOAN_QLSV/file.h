#pragma once
#include"functions.h"

/*
	============================ LOAD DATA ==============================
*/

void loadData_MH(TREE& DSMH);
void loadData_LTC(LISTLOPTC& DSLTC);
void loadData_SV(LISTLOP& DSLSV);
void loadData_DK(LISTLOPTC& DSLTC);
void loadData_LSV(LISTLOP& DSLSV);


/*
	============================ SAVE DATA ==============================
*/

void ghiFile_MH(TREE DSMH, ofstream& fileOut);
void ghiFile_LTC(LOPTC* LTC, ofstream& fileOut);
void ghiFile_LSV(LOPSV LSV, ofstream& fileOut);
void ghiFile_SV(SINHVIEN SV, ofstream& fileOut);
void ghiFileDS_SV(LISTSV DSSV, ofstream& fileOut);
void ghiFile_DK(DANGKY DK, ofstream& fileOut);
void ghiFileDS_DK(LISTDK DSDK, int maLop, ofstream& fileOut);

void saveFile_DK(LISTLOPTC DSLTC);
void saveFile_LTC(LISTLOPTC DSLTC);
void saveFile_LSV(LISTLOP DSLSV);
void saveFile_SV(LISTLOP DSLSV);



/*
	=========================== DINH NGHIA HAM ==========================
	============================ LOAD DATA ==============================
*/

void loadData_MH(TREE& DSMH)
{
	ifstream fileIn; char temp;
	fileIn.open("data\\DSMH.txt", ios::in);
	if (fileIn.is_open())
	{
		//if(DSMH==NULL)
		while (!fileIn.eof())
		{
			MONHOC MH;
			//fileIn.ignore();
			if(DSMH!=NULL)
			fileIn.ignore();
			getline(fileIn, MH.MAMH, ',');
			getline(fileIn, MH.TENMH, ',');
			fileIn >> MH.STCLT;
			fileIn >> temp; //  doc dau , giua 2 so nguyen -> tuong tu cho cac ham load data khac
			fileIn >> MH.STCTH;
	
			them_MH(DSMH, MH);
			if (fileIn.eof()) break;
		}
		
	}
	else
	{
		cout << "\nKhong mo file DSMH duoc\n";
	}
	fileIn.close();
}


void loadData_LTC(LISTLOPTC& DSLTC)
{
	ifstream fileIn; char temp;
	fileIn.open("data\\DSLTC.txt", ios::in);
	//if (DSLTC.n == 0)
	while (!fileIn.eof())
	{
		
		DSLTC.LopTC[DSLTC.n] = new LOPTC;
		fileIn >> DSLTC.LopTC[DSLTC.n]->MALOPTC;
		fileIn >> temp;
		getline(fileIn, DSLTC.LopTC[DSLTC.n]->MAMH, ',');
		fileIn >> DSLTC.LopTC[DSLTC.n]->KHOA;
		fileIn >> temp;
		fileIn >> DSLTC.LopTC[DSLTC.n]->HOCKY;
		fileIn >> temp;
		fileIn >> DSLTC.LopTC[DSLTC.n]->NHOM;
		fileIn >> temp;
		fileIn >> DSLTC.LopTC[DSLTC.n]->SVMAX;

		DSLTC.LopTC[DSLTC.n]->DSDK.pHead = NULL;
		DSLTC.LopTC[DSLTC.n]->DSDK.pTail = NULL;

		DSLTC.n++;

		if (fileIn.eof()) break;
	}
	fileIn.close();
}


void loadData_SV(LISTLOP &DSLSV)
{
	ifstream fileIn; char temp;
	fileIn.open("data\\DSSV.txt",ios::in);
	if (fileIn.is_open())
	{
		//if(DSSV.pHead==NULL)
		while (!fileIn.eof())
		{
			
			NODESV* SV = taoNode_SV();
			getline(fileIn, SV->data.MASV, ',');
			getline(fileIn, SV->data.HO, ',');
			getline(fileIn, SV->data.TEN, ',');
			getline(fileIn, SV->data.PHAI, ',');
			getline(fileIn, SV->data.SDT, ',');
			getline(fileIn, SV->data.MALOP,'\n');


			/*int viTriThem = timviTri_SV(DSSV, SV);
			them_SV(DSSV,SV, viTriThem);*/
	
			int viTriLop = timMaLop_LSV(DSLSV, SV->data.MALOP);
			if (viTriLop != -1)
			{
				int viTriThem = timviTri_SV(DSLSV.Lop[viTriLop].DSSV, SV);
				/*cout << viTriThem;
				system("pause");*/
				them_SV(DSLSV.Lop[viTriLop].DSSV, SV, viTriThem);
				DSLSV.Lop[viTriLop].soLuongSV++;
			}
			if (fileIn.eof()) break;
			
		}
	}
	else {
		cout << "\nKhong mo file duoc";
		system("pause");
	}
	fileIn.close();
}

void loadData_DK(LISTLOPTC& DSLTC)
{
	ifstream fileIn; char temp; int maLop; int viTriLop=0, viTriThem=0;
	fileIn.open("data\\DSDK.txt", ios::in);
	if (fileIn.is_open())
	{
		
			while (!fileIn.eof())
			{
				
				fileIn >> maLop;
				viTriLop = timMaLop_LTC(DSLTC, maLop);
				if (viTriLop != -1)
				{
					fileIn >> temp;
					NODEDK* DK = taoNode_DK();
					getline(fileIn, DK->data.MASV, ',');
					fileIn >> DK->data.DIEM;

					//cout <<maLop<<" "<<viTriLop<<" " <<DK->data.MASV << " " << DK->data.DIEM<<endl;
					
					viTriThem = timViTri_DK(DSLTC.LopTC[viTriLop]->DSDK, DK);
					if(viTriThem!=-1) // viTriThem == -1 -> da co maSV nay 
					them_DK(DSLTC.LopTC[viTriLop]->DSDK, DK, viTriThem);
					
				}


				if (fileIn.eof()) break;

			}
	}
	else {
		cout << "\nKhong mo file duoc";
		system("pause");
	}
	fileIn.close();
}

void loadData_LSV(LISTLOP& DSLSV)
{
	ifstream fileIn; char temp;
	fileIn.open("data\\DSLSV.txt", ios::in);
	//if (DSLSV.n == 0) 
	while (!fileIn.eof())
	{
		
		getline(fileIn, DSLSV.Lop[DSLSV.n].MALOP, ',');
		fileIn >> DSLSV.Lop[DSLSV.n].soLuongSV;
		fileIn.ignore();

		DSLSV.Lop[DSLSV.n].DSSV.pHead = NULL;
		DSLSV.Lop[DSLSV.n].DSSV.pTail = NULL;

		DSLSV.n++;
		if (fileIn.eof()) break;
	}
	fileIn.close();
}

/*
	============================ SAVE DATA ==============================
*/

void ghiFile_MH(TREE DSMH, ofstream& fileOut)
{
	char temp = ',';
	if (DSMH != NULL)
	{
		ghiFile_MH(DSMH->pLeft, fileOut);
		fileOut << DSMH->data.MAMH;
		fileOut << temp;
		fileOut << DSMH->data.TENMH;
		fileOut << temp;
		fileOut << DSMH->data.STCLT;
		fileOut << temp;
		fileOut << DSMH->data.STCTH;
		fileOut << '\n';
		ghiFile_MH(DSMH->pRight, fileOut);
	}
}

void saveFile_MH(TREE DSMH)
{
	ofstream fileOut;
	fileOut.open("dataTemp\\DSMH.txt", ios::out);
	if (fileOut.is_open())
	{
		if(DSMH!=NULL)
		ghiFile_MH(DSMH, fileOut);
	}
	fileOut.close();
}

void ghiFile_LTC(LOPTC *LTC, ofstream &fileOut)
{
	char temp = ',';
	fileOut << LTC->MALOPTC;
	fileOut << temp;
	fileOut << LTC->MAMH;
	fileOut << temp;
	fileOut << LTC->KHOA;
	fileOut << temp;
	fileOut << LTC->HOCKY;
	fileOut << temp;
	fileOut << LTC->NHOM;
	fileOut << temp;
	fileOut << LTC->SVMAX;
	
}

void saveFile_LTC(LISTLOPTC DSLTC)
{
	ofstream fileOut;
	fileOut.open("dataTemp\\DSLTC.txt", ios::out);
	if (fileOut.is_open())
	{
		if (DSLTC.n > 0)
		{
			for (int i = 0; i < DSLTC.n; i++)
			{
				ghiFile_LTC(DSLTC.LopTC[i], fileOut);
				fileOut << '\n';
			}
		}
	}
	fileOut.close();
}

void ghiFile_LSV(LOPSV LSV,ofstream &fileOut)
{
	char temp = ',';
	fileOut << LSV.MALOP;
	fileOut << temp;
	fileOut << 0;
}

void saveFile_LSV(LISTLOP DSLSV)
{
	ofstream fileOut;
	fileOut.open("dataTemp\\DSLSV.txt", ios::out);
	if (fileOut.is_open())
	{
		if (DSLSV.n > 0)
		{
			for (int i = 0; i < DSLSV.n; i++)
			{
				ghiFile_LSV(DSLSV.Lop[i], fileOut);
				fileOut << '\n';
			}
		}
	}
	fileOut.close();
}

void ghiFile_SV(SINHVIEN SV, ofstream& fileOut)
{
	char temp = ',';
	fileOut << SV.MASV;
	fileOut << temp;
	fileOut << SV.HO;
	fileOut << temp;
	fileOut << SV.TEN;
	fileOut << temp;
	fileOut << SV.PHAI;
	fileOut << temp;
	fileOut << SV.SDT;
	fileOut << temp;
	fileOut << SV.MALOP;

}

void ghiFileDS_SV(LISTSV DSSV, ofstream &fileOut)
{
	if (DSSV.pHead != NULL)
	{
		for (NODESV* k = DSSV.pHead; k != NULL; k = k->pNext)
		{
			ghiFile_SV(k->data, fileOut);
			fileOut << '\n';
		}
	}
}

void saveFile_SV(LISTLOP DSLSV)
{
	ofstream fileOut;
	fileOut.open("dataTemp\\DSSV.txt", ios::out);
	if (fileOut.is_open())
	{
		if (DSLSV.n > 0)
		{
			for (int i = 0; i < DSLSV.n; i++)
			{
				ghiFileDS_SV(DSLSV.Lop[i].DSSV, fileOut);
				
			}
		}
	}
	fileOut.close();
}

void ghiFile_DK(DANGKY DK, ofstream& fileOut)
{
	char temp = ',';
	fileOut << temp;
	fileOut << DK.MASV;
	fileOut << temp;
	fileOut << DK.DIEM;
}

void ghiFileDS_DK(LISTDK DSDK, int maLop,ofstream& fileOut)
{
	if (DSDK.pHead != NULL)
	{
		for (NODEDK* k = DSDK.pHead; k != NULL; k = k->pNext)
		{
			fileOut << maLop;
			ghiFile_DK(k->data, fileOut);
			fileOut << '\n';
		}
	}
}

void saveFile_DK(LISTLOPTC DSLTC)
{
	ofstream fileOut;
	fileOut.open("dataTemp\\DSDK.txt", ios::out);
	if (fileOut.is_open())
	{
		if (DSLTC.n > 0)
		{
			for (int i = 0; i < DSLTC.n; i++)
			{
				ghiFileDS_DK(DSLTC.LopTC[i]->DSDK, DSLTC.LopTC[i]->MALOPTC, fileOut);
			}
		}
	}
	fileOut.close();
}



