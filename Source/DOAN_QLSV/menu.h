#pragma once
#include"functions.h"
#include"const.h"
#include"view.h"
#include"file.h"



void menuChinh(TREE& DSMH,LISTLOPTC& DSLTC, LISTLOP& DSLSV)
{
	int choose = 0;
	bool backMenu = true;
	while (backMenu)
	{
		hideCursortype();
		xoaHuongDan();
		huongDanMenuChinh();
		loadLogo();
		choose = chonMenu(5, choose, MENU);
		

		if (choose == 0)  /*============ LOP TIN CHI ============*/
		{
			backMenu = false;
			clearMenuTitle(5);
			xoaHuongDan();
			huongDanMenuCon();
			int chooseSub = 0;
			LOPTC:
			hideCursortype();
				chooseSub = chonMenu(5, chooseSub, MENU_LopTC);
				reset_View();
				xoaHuongDan();
				huongDanChon();
			switch (chooseSub)
			{
			case 0: // them Lop TC
			{
				
				LOPTC* LTC;
				LTC = tao_LTC();
				nhap_LTC(DSLTC, DSMH, LTC, 1);
				reset_View();
				loadLogo();
				goto LOPTC;
				
				break;
			}
			case 1: // xoa Lop TC
			{
				sapXep_LTC(DSLTC, DSMH);
				chon_LTC(DSLTC, DSMH, DSLSV, 2);
				reset_View();
				goto LOPTC;
				break;
			}
			case 2: // sua Lop TC
			{
				sapXep_LTC(DSLTC, DSMH);
				chon_LTC(DSLTC, DSMH, DSLSV, 3);
				reset_View();
				goto LOPTC;
				break;
			}
			case 3: // in ds 1 lop TC
			{
				sapXep_LTC(DSLTC, DSMH);
				chon_LTC(DSLTC, DSMH, DSLSV, 4);
				reset_View();
				goto LOPTC;
				break;
			}
			case 4: // in ds Lop TC
			{
				sapXep_LTC(DSLTC, DSMH);
				chon_LTC(DSLTC, DSMH, DSLSV, 1);
				reset_View();
				goto LOPTC;
				break;
			}
			case-1:  // quay lai MENU chinh
			{
				clearMenuTitle(4);
				backMenu = true;
			}
			default:
				break;
			}
		}
		else if (choose == 1) /*============ SINH VIEN ============*/
		{

			backMenu = false;
			clearMenuTitle(5);
			xoaHuongDan();
			huongDanMenuCon();
			int chooseSub = 0;
		SV:
			hideCursortype();
			chooseSub = chonMenu(5, chooseSub, MENU_Sinhvien);
			reset_View();
			xoaHuongDan();
			huongDanChon();
			switch (chooseSub)
			{
			case 0: // them Lop hoc
			{
				nhap_LSV(DSLSV);
				reset_View();
				goto SV;
				break;
			}
			case 1: // nhap DS sinh vien
			{
				chon_LSV(DSLSV, DSLTC, DSMH, 1);
				reset_View();
				goto SV;
				break;
			}
			case 2: // xoa sinh vien
			{
				chon_LSV(DSLSV, DSLTC, DSMH, 4);
				reset_View();
				goto SV;
				break;
			}
			case 3: // sua sinh vien
			{
				chon_LSV(DSLSV, DSLTC, DSMH, 3);
				reset_View();
				goto SV;
				break;
			}
			case 4: // in DS sinh vien 1 lop
			{
				chon_LSV(DSLSV, DSLTC, DSMH, 2);
				reset_View();
				goto SV;
				break;
			}
			case-1:  // quay lai MENU chinh
			{
				clearMenuTitle(4);
				backMenu = true;
			}
			default:
				break;
			}

		}
		else if (choose == 2) /*============ MON HOC ============*/
		{
		backMenu = false;
		clearMenuTitle(5);
		xoaHuongDan();
		huongDanMenuCon();
		int chooseSub = 0;
		MH:
		hideCursortype();
		chooseSub = chonMenu(5, chooseSub, MENU_Monhoc);
		reset_View();
		xoaHuongDan();
		huongDanChon();
		switch (chooseSub)
		{
		case 0: // them mon hoc
		{
			MONHOC MH;
			MH.STCLT = 0;
			MH.STCTH = 0;
			nhap_MH(DSMH, MH, 1);
			reset_View();
			goto MH;
			break;
		}
		case 1: // xoa mon hoc
		{
			chon_MH(DSMH, 2);
			reset_View();
			goto MH;
			break;
		}
		case 2: // sua mon hoc
		{
			chon_MH(DSMH, 3);
			reset_View();
			goto MH;
			break;
		}
		case 3: // dang ky mon hoc
		{
			sapXep_LTC(DSLTC, DSMH);
			dangKyLTC_SV(DSLTC, DSMH, DSLSV);
			reset_View();
			goto MH;
			break;
		}
		case 4: // in DS mon hoc
		{
			chon_MH(DSMH, 1);
			reset_View();
			goto MH;
			break;
		}
		case-1:  // quay lai MENU chinh
		{
			clearMenuTitle(4);
			backMenu = true;
		}
		default:
			break;
		}

		}
		else if (choose == 3) /*============ DIEM ============*/
		{
		backMenu = false;
		clearMenuTitle(5);
		xoaHuongDan();
		huongDanMenuCon();
		int chooseSub = 0;
	DIEM:
		hideCursortype();
		chooseSub = chonMenu(4, chooseSub, MENU_Diem);
		reset_View();
		xoaHuongDan();
		huongDanChon();
		switch (chooseSub)
		{
		case 0: // nhap diem Lop TC
		{
			sapXep_LTC(DSLTC, DSMH);
			chon_LTC(DSLTC, DSMH, DSLSV, 6);
			reset_View();
			goto DIEM;
			break;
		}
		case 1: // bang diem mon hoc
		{
			sapXep_LTC(DSLTC, DSMH);
			chon_LTC(DSLTC, DSMH, DSLSV, 5);
			reset_View();
			goto DIEM;
			break;
		}
		case 2: // bang diem trung binh
		{
			chon_LSV(DSLSV, DSLTC, DSMH, 5);
			reset_View();
			goto DIEM;
			break;
		}
		case 3: // bang diem tong ket
		{
			chon_LSV(DSLSV, DSLTC, DSMH, 6);
			reset_View();
			goto DIEM;
			break;
		}
		case-1:  // quay lai MENU chinh
		{
			clearMenuTitle(4);
			backMenu = true;
		}
		default:
			break;
		}

		}
		else if (choose == -1 || choose == 4)
		{
			saveFile_MH(DSMH);
			saveFile_LTC(DSLTC);
			saveFile_LSV(DSLSV);
			saveFile_SV(DSLSV);
			saveFile_DK(DSLTC);

			free_MH(DSMH);
			for (int i = 0; i < DSLSV.n; i++)
			{
				free_SV(DSLSV.Lop[i].DSSV);
			}
			
			for (int i = 0; i < DSLTC.n; i++)
			{
				free_DK(DSLTC.LopTC[i]->DSDK);
			}

			freeDS_LTC(DSLTC);
			exit(0);
		}
	}
}