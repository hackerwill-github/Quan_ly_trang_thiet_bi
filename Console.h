#pragma once

/*----------library Default---------------*/
#include <iostream>
#include <windows.h>
#include<string.h>
#include<ctype.h>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <vector>
using namespace std;

#define	MAX			30
#define GOC1 		(char)201
#define GOC2 		(char)187
#define GOC3		(char)188
#define GOC4		(char)200
#define DOC			(char)186
#define NGANG 		(char)205
#define GOC1 		(char)201
#define GOC2 		(char)187
#define GOC3		(char)188
#define GOC4		(char)200 
#define DOC			(char)186
#define NGANG 		(char)205     
#define ENTER 		13
#define	BACKSPACE	8
#define SPACE 		32
#define MAX_ACCOUNT 10
#define LOADING		(char)433   
#define	TABLE_NGANG	char(196)
#define TABLE_DOC	char(179)
#define TABLE_GOC1	char(218)
#define TABLE_GOC2	char(191)
#define TABLE_GOC3	char(217)
#define TABLE_GOC4	char(192)   

	
/*------------------------------General Function-----------------------------------------------------------------------------------------*/
void gotoXY (int column, int line){	
	COORD coord; 	
	coord.X = column;  	
	coord.Y = line; 	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void TextColor (int color){	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
	}

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
} 

int GetKey(){	
	char key;key = getch();
	if(key==-32 || key==0)
	return -getch();
	else return key;
}

void An_tro_chuot()
{
	CONSOLE_CURSOR_INFO Info;  
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void Hien_tro_chuot(){
	CONSOLE_CURSOR_INFO Info;  
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

/*-------------------------------------------------Graphics Function---------------------------------------------------------------------------------*/

void Khung_don(int x, int y, string a){
	TextColor(10);
	gotoXY(x,y);
	cout <<GOC1 <<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<GOC2;
	gotoXY(x,y+1);
	TextColor(14);
	cout << a;
	TextColor(10);
	gotoXY(x,y+2);
	cout <<GOC4 <<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<GOC3;
}

void Khung_hieu_ung(int x, int y){
	TextColor(4);
	gotoXY(x,y);
	cout <<GOC1 <<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<GOC2;
	gotoXY(x,y+1);
	TextColor(4);
	gotoXY(x,y+2);
	cout <<GOC4 <<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<GOC3;
}

void Button(int x, int y, string a, bool turn){
	if(turn == false){
		
		TextColor(10);
		gotoXY(x,y);
		cout <<GOC1 <<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<GOC2;
		gotoXY(x,y+1);
		TextColor(14);
		cout << a;
		TextColor(10);
		gotoXY(x,y+2);
		cout <<GOC4 <<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<GOC3;
	}else{
		TextColor(4);
		gotoXY(x,y);
		cout <<GOC1 <<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<GOC2;
		gotoXY(x,y+1);
		TextColor(3);
		cout << a;
		TextColor(4);
		gotoXY(x,y+2);
		cout <<GOC4 <<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<NGANG<<GOC3;
	}
}

void Note_Frame(string s){
	int x = 60; int y = 37;
	TextColor(14);
	gotoXY(x,y);	cout << GOC1;
	for(int i=1; i<61; i++){
		gotoXY(x+1*i,y);	cout << NGANG;
	}
	gotoXY(x+60,y); cout <<GOC2;
	TextColor(4); 
	gotoXY(x,y+1); cout<< s;
	gotoXY(x,y+2); cout<<"                                                           ";
	TextColor(14); 
	gotoXY(x,y+2); cout<<GOC4;
	for(int i=1; i<61; i++){
		gotoXY(x+1*i,y+2);cout << NGANG;
	}
	gotoXY(x+60,y+2); cout <<GOC3;
	Sleep(2000); 
	gotoXY(x,y);
	cout <<"                                                                                                                                        ";
	cout <<"                                                                                                                                        ";
	cout <<"                                                                                                                                        ";
	cout <<"                                                                                                                                        ";
}

void Xoa_Full_Man_hinh(){
	gotoXY(0,0);
	TextColor(0);
	for(int i=0;i<45; i++){
		cout <<"                                                                                                                                                            ";
	}
}

void KhungDoiTuong(int y, bool turn){
	int x = 25;
	if(turn == true) TextColor(4);
	if(turn == false) TextColor(14);
	int length = 0;
	string Table_keyword[7] = {"  STT  ","    Ma Trang Thiet Bi    ","      Ten Trang Thiet Bi      ", "   Ngay san xuat   ", "   Ngay Su Dung   ", "    Chung Loai    ", "   Cap   "};
	for(int i=0; i<7; i++){ 
		gotoXY(x- 1,y+1); 
		cout << TABLE_DOC;
		length += Table_keyword[i].length();
		gotoXY(x+ length- 1,y+1); 
		cout << TABLE_DOC;
	}
	for(int j = 0; j<(length); j++){
		gotoXY(x+j, y);
		cout << TABLE_NGANG;
		gotoXY(x+j, y+2);
		cout << TABLE_NGANG;
	}
	for(int j =0; j<=7; j++){
		gotoXY(x-1,y); cout << TABLE_GOC1;
		gotoXY(x+length-1,y); cout << TABLE_GOC2;
		gotoXY(x+length-1,y+2); cout << TABLE_GOC3;
		gotoXY(x-1,y+2); cout << TABLE_GOC4;
	}
}

void XoaDulieu(){
	TextColor(0);
	for(int i=0; i<10;i++){
		gotoXY(26,12+i*2); cout <<"   ";
		gotoXY(40,12+i*2); cout <<"            ";
		gotoXY(65,12+i*2); cout <<"                    ";
		gotoXY(90,12+i*2); cout <<"            ";
		gotoXY(110,12+i*2);cout <<"            ";
		gotoXY(127,12+i*2);cout <<"            ";
		gotoXY(145,12+i*2);cout <<" ";
	}
}

/*---------------------------------------------------Structure data---------------------------------------------------------------*/
struct THIETBI{
	char maTTB[20]="";
	char tenTTB[25]="";   
	char nsx[11]="";       
	char nsd[11]="";
	char chung_loai[15]="";
	char cap[2]="";
};

typedef vector<THIETBI> LIST_THIET_BI;

struct Date{
	char ngay[2];
	char thang[2];
	char nam[4];
};








