
/*

	Nguyen Trung Duc  -  N19DCCN040 - D19CQCN03-N
	De Tai: Quan ly sinh vien
	Lan cuoi update: 21/06/2020

*/
#include"menu.h"


void init_Data(TREE& DSMH, LISTLOPTC& DSLTC, LISTLOP& DSLSV)
{
	loadData_LSV(DSLSV);
	loadData_LTC(DSLTC);
	loadData_SV(DSLSV);
	loadData_MH(DSMH);
	loadData_DK(DSLTC);
	
}


int main()
{
	TREE DSMH = NULL;
	LISTLOPTC DSLTC;

	LISTLOP DSLSV;
	DSLSV.n = 0;
	init_View();
	init_Data(DSMH, DSLTC, DSLSV);
	
	menuChinh(DSMH,DSLTC,DSLSV);
	
	_getch();
	return 0;

}