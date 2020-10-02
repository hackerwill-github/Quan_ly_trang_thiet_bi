#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <vector>
#include <string.h>
#include "Console.h"
using namespace std;


void FormatDate(char *a, int vitri, COORD toado){
	if(a[0]>='1' && a[0]<='9'){
		a[1] = a[0];	a[0] = '0';
		gotoXY(toado.X, toado.Y);
		cout << a[0]<<a[1];
		vitri = 2;
	}
	if(a[3]>='1' && a[3]<='9'){
		a[4] = a[3];	a[3] = '0';
		gotoXY(toado.X+3, toado.Y);
		cout << a[3]<<a[4] ;
		vitri = 5;
	}
	if(vitri == 2 || vitri == 5){
		a[vitri] = '/';
		cout<<a[vitri]; 
	}
}

int Screen2_key_event(KEY_EVENT_RECORD ker, COORD toado, char *a, int size){
	int vitri = strlen(a);	
	gotoXY(toado.X + vitri, toado.Y);
	char key = ker.uChar.AsciiChar;
	TextColor(11);
	if(ker.bKeyDown ){
		if(vitri < size-1){
			if(( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' ) || (key == SPACE) || (key == '-')){
				cout <<key;
				a[vitri] = key;
			}
		}
		if(key == BACKSPACE && vitri > 0)
		{	vitri--;
			a[vitri] = '\0';
			gotoXY(toado.X+vitri, toado.Y);
			cout<<" ";
			gotoXY(toado.X+vitri, toado.Y);
		}  
	}
	return 1;
}   

int Screen2_key_alphabet(KEY_EVENT_RECORD ker, COORD toado, char *a,  int size){
	int vitri = strlen(a);	
	gotoXY(toado.X + vitri, toado.Y);
	char key = ker.uChar.AsciiChar;
	TextColor(11);
	if(ker.bKeyDown ){
		if(vitri < size-1){
			if(( key >= 'A' && key <= 'Z') || ( key >='a' && key <= 'z' ) || (key == SPACE)){
				cout <<key;
				a[vitri] = key;
			}
		}
		if(key == BACKSPACE && vitri > 0)
		{	vitri--;
			a[vitri] = '\0';
			gotoXY(toado.X+vitri, toado.Y);
			cout<<" ";
			gotoXY(toado.X+vitri, toado.Y);
		}
	}
	return 1;
}  

int Screen2_key_number(KEY_EVENT_RECORD ker, COORD toado, char *a, int size){
	int vitri = strlen(a);	
	gotoXY(toado.X + vitri, toado.Y);
	char key = ker.uChar.AsciiChar;
	TextColor(11);
	if(ker.bKeyDown ){
		if(vitri < size-1){
			if(( key <= '9' && key >= '0')){
				cout <<key;
				a[vitri++] = key;
				if(toado.X == 3 || toado.X == 4){
					FormatDate(a,vitri,toado); 
				}
			}
		}
		if(key == BACKSPACE && vitri > 0)
		{	vitri--;
			a[vitri] = '\0';
			gotoXY(toado.X+vitri, toado.Y);
			cout<<" ";
			gotoXY(toado.X+vitri, toado.Y);
		}
	}
	return 1;
} 

bool Check_Full(LIST_THIET_BI* list ,THIETBI &ttb, COORD &toado){
	THIETBI temp;
	if(strlen(ttb.maTTB) == 0){
		Note_Frame("                Ma Trang Thiet Bi IS EMPTY!!!"); return false;
	}else if(strlen(ttb.tenTTB) == 0){
		Note_Frame("               Ten Trang Thiet Bi IS EMPTY!!!"); return false;
	}else if(strlen(ttb.nsx) == 0){
		Note_Frame("                Ngay San Xuat IS EMPTY!!!"); return false;
	}else if(strlen(ttb.nsd) == 0){
		Note_Frame("               Ngay Su Dung IS EMPTY!!!"); return false;
	}else if(strlen(ttb.chung_loai) == 0){
		Note_Frame("                 Chung loai IS EMPTY!!!"); return false;
	}else if(atoi(ttb.cap) <1|| atoi(ttb.cap) >5){ 
		Note_Frame("                       Cap IS EMPTY !!!"); return false;
	}else{
		if(toado.Y <=9){
			list->push_back(ttb);
			ttb	= temp;	
			toado.X = 0;	toado.Y++;
		}else Note_Frame("              TABLE IS FULL! PLEASE SAVE OLD DATA!   ");
	}
	return true;
}

int CountLine(char *Filename){
	FILE *f1;
	int count = 0;
	char c;
	f1 = fopen(Filename,"a+");
	rewind(f1);
	do{
		c = fgetc(f1);
		if(c == '\n'){
			count++;
		}
	}while(c!=EOF);
	fclose(f1);
	return count;
}

void InFile(char *Filename,LIST_THIET_BI* list)
{
	LIST_THIET_BI temp;
	FILE *f1;
	gotoXY(10,0);
	cout <<"1";
	int count = CountLine(Filename);
	gotoXY(20,0);
	cout << count;
	f1 = fopen(Filename, "a+b");
	for (unsigned i = 0; i < list->size(); i++)
	{
		fprintf(f1, "%-.03d*%s*%s*%s*%s*%s*%s*\n", (count+ i + 1), list->at(i).maTTB, list->at(i).tenTTB,list->at(i).nsx, list->at(i).nsd,list->at(i).chung_loai,list->at(i).cap);
	}
	fclose(f1);
	Note_Frame("                     DATA HAS BEEN SAVED !!!!   ");
}

int Screen2_Mouse_event(MOUSE_EVENT_RECORD mer,LIST_THIET_BI list, COORD &toado){
	if(mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED){
		if(mer.dwMousePosition.X >=1 && mer.dwMousePosition.X <= 25 && mer.dwMousePosition.Y >=1 && mer.dwMousePosition.Y <= 3){
			return -1;
		}
		if(mer.dwMousePosition.X >=75 && mer.dwMousePosition.X <= 95 && mer.dwMousePosition.Y >=33 && mer.dwMousePosition.Y <= 36){
			Button(80, 33, "     SAVE", true);
			InFile("Output.txt",&list);
			Button(80, 33, "     SAVE", false);
			
		}	
		for(int i=0; i<10; i++){ 
			if(mer.dwMousePosition.Y >= (11+i*2) && mer.dwMousePosition.Y <= (13+i*2)){
				toado.Y = (i+1);
				if(mer.dwMousePosition.X >= 24 && mer.dwMousePosition.X <=31 )toado.X = 0;
				if(mer.dwMousePosition.X >= 32 && mer.dwMousePosition.X <= 57) toado.X = 1;
				if(mer.dwMousePosition.X >= 58 && mer.dwMousePosition.X <= 86) toado.X = 2;
				if(mer.dwMousePosition.X >= 87 && mer.dwMousePosition.X <= 105) toado.X = 3;
				if(mer.dwMousePosition.X >= 106 && mer.dwMousePosition.X <= 123) toado.X = 4;
				if(mer.dwMousePosition.X >= 124 && mer.dwMousePosition.X <= 141) toado.X = 5;
				if(mer.dwMousePosition.X >= 142 && mer.dwMousePosition.X <= 152) toado.X = 6;
			}
		}
	}else if(mer.dwEventFlags == MOUSE_MOVED){
		if(mer.dwMousePosition.X >=70 && mer.dwMousePosition.X <= 105 && mer.dwMousePosition.Y >=30 && mer.dwMousePosition.Y <= 40){
			An_tro_chuot();
			if(mer.dwMousePosition.X >=75 && mer.dwMousePosition.X <= 95 && mer.dwMousePosition.Y >=33 && mer.dwMousePosition.Y <= 35){
				Button(80, 33, "     SAVE",true);
			}else Button(80, 33, "     SAVE",false);
			Hien_tro_chuot();
		}
		if(mer.dwMousePosition.X >=0 && mer.dwMousePosition.X <= 30 && mer.dwMousePosition.Y >=0 && mer.dwMousePosition.Y <= 9){
			An_tro_chuot();
			if(mer.dwMousePosition.X >=1 && mer.dwMousePosition.X <= 25 && mer.dwMousePosition.Y >=1 && mer.dwMousePosition.Y <= 3){
				Button(1,1,"     BACK", true);
			}else Button(1,1,"     BACK", false);
			Hien_tro_chuot();
		}
	} return 0;
} 

   

