#include<iostream>
#include"Console.h"
#include"Input.h"
using namespace std;

#define	TABLE_NGANG	char(196)
#define TABLE_DOC	char(179)
#define TABLE_GOC1	char(218)
#define TABLE_GOC2	char(191)
#define TABLE_GOC3	char(217)
#define TABLE_GOC4	char(192) 
/*----------------------------------------------------------------Appearance-------------------------------------------------------------------------*/

void THEMMOIDANHSACH(){
	int x = 45;
	int y = 3;
	TextColor(13);
	gotoXY(x,y);   cout <<"--.--|                            o        |          |                     |";    
 	gotoXY(x,y+1); cout <<"  |  |---.,---.,-.-.    ,-.-.,---..    ,---|,---.,---.|---.  ,---.,---.,---.|---.";
  	gotoXY(x,y+2); cout <<"  |  |   ||---'| | |    | | ||   ||    |   |,---||   ||   |  `---.,---||    |   |";
  	gotoXY(x,y+3); cout <<"  `  `   '`---'` ' '    ` ' '`---'`    `---'`---^`   '`   '  `---'`---^`---'`   '";

	Sleep(80);
	Button(x+35, y+30, "     SAVE", false);
	Button(1,1,"     BACK", false);
}


void Table(){
	int length;
	int x = 25, y = 8, z = 24;
	gotoXY(x,y);
	string Table_keyword[7] = {"  STT  ","    Ma Trang Thiet Bi    ","      Ten Trang Thiet Bi      ", "   Ngay san xuat   ", "   Ngay Su Dung   ", "    Chung Loai    ", "   Cap   "};
	for(int i=0; i<7; i++){ 
		length += Table_keyword[i].length();
	}
	TextColor(14);
	An_tro_chuot();
	for(int j = 0; j<(length); j++){
		gotoXY(x+j, y);
		cout << TABLE_NGANG;
		gotoXY(x+j, y+3);
		cout << TABLE_NGANG;
		for(int k =0; k<22; k+= 2){
			gotoXY(x+j, y+3+k);
			cout << TABLE_NGANG;
		}
//		Sleep(10);
	}
	for(int j =0; j<=7; j++){
		gotoXY(x-1,y); cout << TABLE_GOC1;
		gotoXY(x+length-1,y); cout << TABLE_GOC2;
		gotoXY(x+length-1,y+23); cout << TABLE_GOC3;
		gotoXY(x-1,y+23); cout << TABLE_GOC4;
		for(int i = 1; i<23; i++){
			if(i==2 && j<7){
				TextColor(10);
				cout <<Table_keyword[j];
			}gotoXY(z,y+i);
		TextColor(14);
		cout << TABLE_DOC;
//			 Sleep(10); 
		}
		if(j<7) z +=Table_keyword[j].length();
		 gotoXY(z, y); cout << TABLE_GOC2;
		 gotoXY(z,y+23); cout << TABLE_GOC3;
	} Hien_tro_chuot();
}



/*---------------------------------------------------- Feature--------------------------------------------------------------------------------*/


void XuLyEnter(KEY_EVENT_RECORD ker,LIST_THIET_BI* list,THIETBI &ttb, COORD &toado){
	char key = ker.uChar.AsciiChar;
	if(ker.bKeyDown){
		if(key == ENTER){
			if(toado.X == 7){
				Check_Full(list,ttb, toado);
			}else {
				toado.X++;	
			}
		}
	}
}

void XuLyToaDo(KEY_EVENT_RECORD ker, COORD &toado, THIETBI &ttb){
	COORD local_coord;
	char key = ker.uChar.AsciiChar;
	for(int i = 1; i<=10;i++){
		TextColor(11);
		if(toado.Y == i) local_coord.Y = 10+i*2;
	}if(toado.X == 0){
		gotoXY(27,local_coord.Y);
		cout << toado.Y;
		gotoXY(35,local_coord.Y);
		toado.X = 1;
	}else if(toado.X == 1){
		local_coord.X = 40 ;
		Screen2_key_event(ker, local_coord, ttb.maTTB,10);
	}else if(toado.X == 2){
		local_coord.X = 65;
		Screen2_key_event(ker, local_coord, ttb.tenTTB,20);
	}else if(toado.X == 3){
		local_coord.X = 90;
		Screen2_key_number(ker,local_coord, ttb.nsx,11);
	}else if(toado.X == 4){
		local_coord.X = 110;
		Screen2_key_number(ker,local_coord, ttb.nsd, 11);
	}else if(toado.X == 5){
		local_coord.X = 128;
		Screen2_key_alphabet(ker,local_coord, ttb.chung_loai,10);
	}else if(toado.X == 6){
		local_coord.X = 145;
		Screen2_key_number(ker,local_coord, ttb.cap,2);
	}
}

int Screen2(HANDLE &hStdin, INPUT_RECORD &irInBuf){
	LIST_THIET_BI list;
	DWORD cNumRead, i; 
	COORD toado; toado.X=0; toado.Y =1;
	Xoa_Full_Man_hinh();
	THEMMOIDANHSACH();
	Table();
	Hien_tro_chuot();
	THIETBI ttb;
	char a[20];
    while(true){  
    		ReadConsoleInput( hStdin, &irInBuf, 1, &cNumRead); 
	 		
			if(irInBuf.EventType == MOUSE_EVENT){
				if(Screen2_Mouse_event(irInBuf.Event.MouseEvent,list, toado) == -1)
					return -1;
			}
			XuLyToaDo(irInBuf.Event.KeyEvent,toado,ttb);
			XuLyEnter(irInBuf.Event.KeyEvent,&list,ttb, toado);
			
	}
}  
