#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <vector>
#include <string.h>
#include <fstream>
#include "Console.h"
#include "Screen0.h"     
#include "Screen1.h" 
#include "Screen2.h"
using namespace std;
 
void Char_color(){
	for(int i=0; i<300; i++){
		TextColor(i);
		cout << i<<" "<<(char)i<<endl;
	}
}

void CAPNHATDANHSACH(){
	int x = 45, y = 3;
	TextColor(13);
	gotoXY(x,y); 	cout<<",---.                   |         |            |          |                       |    ";
	gotoXY(x,y+1); 	cout<<"|    ,---.,---.    ,---.|---.,---.|---     ,---|,---.,---.|---.    ,---.,---.,---.|---.";
	gotoXY(x,y+2); 	cout<<"|    ,---||   |    |   ||   |,---||        |   |,---||   ||   |    `---.,---||    |   |";
	gotoXY(x,y+3); 	cout<<"`---'`---^|---'    `   '`   '`---^`---'    `---'`---^`   '`   '    `---'`---^`---'`   '";
	
	Button(1,1,"     BACK", false);
	Button(x ,y+30,"      ADD", false); 
	Button(x+35, y+30,"     EDIT", false);
	Button(x+70, y+30,"    DELETE", false);
	Button(x+110,y+15,"     Next >>", false);
	Button(x-40,y+15," << Previous", false);	
}

THIETBI ReadInfo(ifstream &filein){
	THIETBI ttb;
	string temp;
	getline(filein, temp, '*');
	getline(filein, temp, '*');
	strcpy(ttb.maTTB,temp.c_str());
	getline(filein, temp, '*');
	strcpy(ttb.tenTTB,temp.c_str());
	getline(filein, temp, '*');
	strcpy(ttb.nsx,temp.c_str());
	getline(filein, temp, '*');
	strcpy(ttb.nsd,temp.c_str());
	getline(filein, temp, '*');
	strcpy(ttb.chung_loai,temp.c_str());
	filein >> ttb.cap;
	
	return ttb;
}

void OutFile(char *Filename, LIST_THIET_BI* list){
	ifstream filein;
	filein.open(Filename, ios_base::in);
	while(!filein.eof()){
		THIETBI ttb = ReadInfo(filein);
		list->push_back(ttb);
		gotoXY(10,0);
	}
	filein.close();
}
 
void PrintScreen(LIST_THIET_BI* list, int &page){
	An_tro_chuot();
	TextColor(11);
	if(page <= 1) page = 1;
		for(int i = 0; i < 10; i++) { 
		int k = 10*(page-1)+i;
		if(k == (list->size())){
			page--;
			break;
		}
		gotoXY(26,12+i*2); printf("%3d",(k+1));
		gotoXY(40,12+i*2); cout << list->at(k).maTTB<<"   ";
		gotoXY(65,12+i*2); cout << list->at(k).tenTTB<<"    ";
		gotoXY(90,12+i*2); cout << list->at(k).nsx;
		gotoXY(110,12+i*2);cout << list->at(k).nsd;
		gotoXY(127,12+i*2);cout << list->at(k).chung_loai<<"   ";
		gotoXY(145,12+i*2);cout << list->at(k).cap;
	}
}

void XuLyHieuUng(MOUSE_EVENT_RECORD mer, LIST_THIET_BI* list, int page){
	PrintScreen(list, page);
	for(int i = 0; i<10; i++){
		TextColor(14);
			if(mer.dwMousePosition.X >=24 && mer.dwMousePosition.X <= 150 && mer.dwMousePosition.Y >=(11+2*i) && mer.dwMousePosition.Y <= (12+2*i)){
				TextColor(4);
				int k = 10*(page-1)+i;
				gotoXY(26,12+i*2); printf("%3d",(k+1));
				gotoXY(40,12+i*2); cout << list->at(k).maTTB<<"   ";
				gotoXY(65,12+i*2); cout << list->at(k).tenTTB<<"    ";
				gotoXY(90,12+i*2); cout << list->at(k).nsx;
				gotoXY(110,12+i*2);cout << list->at(k).nsd;
				gotoXY(127,12+i*2);cout << list->at(k).chung_loai<<"   ";
				gotoXY(145,12+i*2);cout << list->at(k).cap;
				
			}
			
	}
}

int Screen3_Mouse_event(MOUSE_EVENT_RECORD mer,LIST_THIET_BI* list, COORD &toado, int &page ){
	if(mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED){
		XuLyHieuUng(mer, list, page);
		if(mer.dwMousePosition.X >=155 && mer.dwMousePosition.X <= 170 && mer.dwMousePosition.Y >=18 && mer.dwMousePosition.Y <= 20) {
			XoaDulieu(); 
			return 2;
		}
		if(mer.dwMousePosition.X >=5 && mer.dwMousePosition.X <= 20 && mer.dwMousePosition.Y >=18 && mer.dwMousePosition.Y <= 20) return 1;
		if(mer.dwMousePosition.X >=1 && mer.dwMousePosition.X <= 25 && mer.dwMousePosition.Y >=1 && mer.dwMousePosition.Y <= 3){
			return -1;
		}
		if(mer.dwMousePosition.X >=75 && mer.dwMousePosition.X <= 95 && mer.dwMousePosition.Y >=33 && mer.dwMousePosition.Y <= 36){
			Button(80, 33, "     SAVE", true);
			InFile("Output.txt",list);
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
//		XuLyHieuUng(mer, list, page);
		if(mer.dwMousePosition.X >=0 && mer.dwMousePosition.X <= 200 && mer.dwMousePosition.Y >=0 && mer.dwMousePosition.Y <= 50){
			
			
			if(mer.dwMousePosition.X >=1 && mer.dwMousePosition.X <= 20 && mer.dwMousePosition.Y >=1 && mer.dwMousePosition.Y <= 3){
				Button(1,1,"     BACK", true);
			}else Button(1,1,"     BACK", false);
			
			if(mer.dwMousePosition.X >=115 && mer.dwMousePosition.X <= 130 && mer.dwMousePosition.Y >=33 && mer.dwMousePosition.Y <= 35){
				Button(115, 33, "    DELETE",true);
			}else Button(115, 33,"    DELETE",false);
			
			if(mer.dwMousePosition.X >=45 && mer.dwMousePosition.X <= 60 && mer.dwMousePosition.Y >=33 && mer.dwMousePosition.Y <= 35){
				Button(45, 33,"      ADD",true);
			}else Button(45, 33,"      ADD",false);
			
			if(mer.dwMousePosition.X >=80 && mer.dwMousePosition.X <= 95 && mer.dwMousePosition.Y >=33 && mer.dwMousePosition.Y <= 35){
				Button(80, 33, "     EDIT",true);
			}else Button(80, 33, "     EDIT",false);
			
			if(mer.dwMousePosition.X >=155 && mer.dwMousePosition.X <= 170 && mer.dwMousePosition.Y >=18 && mer.dwMousePosition.Y <= 20){
				Button(155, 18,"     Next >>",true);
			}else Button(155, 18,"     Next >>",false);
			
			if(mer.dwMousePosition.X >=5 && mer.dwMousePosition.X <= 20 && mer.dwMousePosition.Y >=18 && mer.dwMousePosition.Y <= 20){
				Button(5, 18," << Previous",true);
			}else Button(5, 18," << Previous",false);
		}
	} return 0;
} 



int Screen3(HANDLE &hStdin, INPUT_RECORD &irInBuf){
	LIST_THIET_BI list;
	DWORD cNumRead, i; 
	COORD toado; toado.X=0; toado.Y =1;
	Xoa_Full_Man_hinh();  
	CAPNHATDANHSACH(); 
	Table();
	THIETBI ttb;
	int page = 1;
	OutFile("Input.txt", &list);
	PrintScreen(&list, page);
    while(true){  
    	
    	ReadConsoleInput( hStdin, &irInBuf, 1, &cNumRead); 
			if(irInBuf.EventType == MOUSE_EVENT){
				switch(Screen3_Mouse_event(irInBuf.Event.MouseEvent,&list, toado, page)){
					case -1:	return -1;
					case  2:{
						page++;
						PrintScreen(&list, page);
						break;
					}
					case  1:{
						page--;
						PrintScreen(&list, page);
						break;
					}
				}
			}
			
	}
}  
 
int Run(){                                        
	HANDLE hStdin;
	DWORD fdwMode, mode;                      
	INPUT_RECORD irInBuf ;
	hStdin = GetStdHandle(STD_INPUT_HANDLE);  
    fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
//    Screen0(hStdin, irInBuf); 
	while(true){
		switch(index1){
			case -1: {
				index1 = Screen1(hStdin, irInBuf);
				break;
			}
			case 0:{
				index1 = Screen2(hStdin, irInBuf);
				break;
			}
			case 1:{
				index1 = Screen3(hStdin, irInBuf);
				break;
			}
		}
	}
}

int main(){             
	resizeConsole(1300,800);
	Run();     
//	Char_color();
	
	
	return 0;
}

