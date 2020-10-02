
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "Console.h"
using namespace std;

int index1 = -1;
int index2 = -1;
int index3 = -1;

string Menu[6]={" Cap Nhat Danh Sach","    In Danh Sach","      Sap xep","      Tim kiem","      Thong Ke" ,"       Thoat"};
string Sap_xep[2] = {"    Thuat Toan", "      Tu Khoa"};
string Sx_Thuat_toan[4]={"   Selection Sort", "   Insertion Sort", "    Bubble Sort", "    Quick Sort"};
string Sx_Tu_khoa[3] = { "   Ngay San Xuat","    Ngay Su Dung","         Cap"};
string Tim_kiem[2] = { "      Tu Khoa","    Thuat Toan"};
string Tk_Thuat_Toan[2] = {"      Tuan Tu", "       Nhi Phan"};
string Tk_Tu_khoa[6] = {"       Ma TTB"," Ten Trang Thiet Bi", "   Ngay San Xuat","    Ngay Su Dung","     Chung Loai","         Cap"};
string Thong_ke[2] = {"     Chung Loai","    Cap"};

/*----------------------------------------------------------------------------------------------------------------------------------------------*/


void Khung_menu(int x, int y, string a[], int n){
	gotoXY(x,y);
	for(int i=0; i<n; i++){
		Khung_don(x,y + i*3,a[i]);
	}
	Khung_don(2,35,"     REFRRESH   ");
	TextColor(14);
	gotoXY(25, 36); cout <<"<-- Click here to reset menu";
	gotoXY(80, 36); cout <<"!!!  Click to choose anything you want !!!";
}

void Eraser(int x, int y){
	for(int i=0; i<28; i++){
		gotoXY(x,y+i); cout <<"                                                                                        ";
	}
}

void Reset(){
		index1 = -1;
		index2 = -1;
		index3 = -1;
		Eraser(25,8);
		Eraser(50,8);
		Khung_hieu_ung(2,35);
}

void Exit_Frame(){
	int x = 55; int y = 15;
	TextColor(12);
	gotoXY(x,y);	cout << GOC1;
	for(int i=1; i<61; i++){
		gotoXY(x+1*i,y);	cout << NGANG;
	}
	gotoXY(x+60,y); cout <<GOC2;
	TextColor(11); 
	gotoXY(x,y+1); cout<<"                    Do You Want To Exit ???                ";
	gotoXY(x,y+2); cout<<"                                                           ";
	TextColor(14); 
	gotoXY(x,y+3); cout<<"               YES                           NO            "; 
	TextColor(12);
	gotoXY(x,y+4); cout<<"                                                           ";
	gotoXY(x,y+5); cout<<"                                                           ";
	gotoXY(x,y+4); cout<<GOC4;
	for(int i=1; i<61; i++){
		gotoXY(x+1*i,y+4);cout << NGANG;
	}
	gotoXY(x+60,y+4); cout <<GOC3;
}

int Exit_function(MOUSE_EVENT_RECORD mouse){
	Exit_Frame();
	if(mouse.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED){
		if(mouse.dwMousePosition.X >=65 && mouse.dwMousePosition.X <= 80 && mouse.dwMousePosition.Y == 18){
		TextColor(4); gotoXY(70,13); cout<<"YES "; 
		TextColor(14); gotoXY(100,13); cout<<" NO ";
		Sleep(50); 
		return -2;
	}
	if(mouse.dwMousePosition.X >=95 && mouse.dwMousePosition.X <= 110 && mouse.dwMousePosition.Y == 18){
		TextColor(14); gotoXY(70,13); cout<<"YES "; 
		TextColor(4); gotoXY(100,13); cout<<" NO ";
		Sleep(50); 
		Reset();
	}
	}
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------*/
void End(){
	int x = 45;
	int y = 5;
	Xoa_Full_Man_hinh();
	while(true){
	TextColor(rand() % (13-2+1)+2);
	gotoXY(x,y+5); cout <<"                           .-.      .-.                       .-.  .-.  .-.";
	gotoXY(x,y+6); cout <<"                           : :      : :                       : :  : :  : :";
	gotoXY(x,y+7); cout <<"                           : :      : :                       : :  : :  : :";
	gotoXY(x,y+8); cout <<" .--.    .--.    .--.    .-' :      : `-.   .-..-.   .--.     : :  : :  : :";
	gotoXY(x,y+9); cout <<"' .; :  ' .; :  ' .; :  ' .; :      ' .; :  : :; :  ' '_.'    :_;  :_;  :_;";
	gotoXY(x,y+10);cout <<"`._. ;  `.__.'  `.__.'  `.__.'      `.__.'  `._. ;  `.__.'    :_;  :_;  :_;";
	gotoXY(x,y+11);cout <<" .-. :                                       .-. : "; 
	gotoXY(x,y+12);cout <<" `._.'                                       `._.'  ";
	Sleep(80);
	}
}

void MTA(){
	int x = 130, y= 5 ;
	srand(time(NULL));
	int color = rand() % (13-2+1)+2;
	TextColor(color);     
	gotoXY(x,y  ); cout<<"  ***                       ***  ";    
	gotoXY(x,y+1); cout<<"  *****                   *****  ";       
	gotoXY(x,y+2); cout<<"  *** ***               *** ***   ";       
	gotoXY(x,y+3); cout<<"  ***   ***           ***   ***   ";       
	gotoXY(x,y+4); cout<<"  ***     ***       ***     ***   ";       
	gotoXY(x,y+5); cout<<"  ***       ***   ***       ***   ";       
	gotoXY(x,y+6); cout<<"  ***         *****         ***   ";       
	gotoXY(x,y+7); cout<<"  ***                       ***   ";       
	gotoXY(x,y+8); cout<<"  ***                       ***   ";   
	int color1 = rand() % (13-2+1)+2;
	TextColor(color1);    
	gotoXY(x,y+9); cout<<"                                  ";       
	gotoXY(x,y+10); cout<<"      **********************     ";       
	gotoXY(x,y+11); cout<<"      **********************     ";       
	gotoXY(x,y+12); cout<<"               ***                ";       
	gotoXY(x,y+13); cout<<"               ***                ";       
	gotoXY(x,y+14); cout<<"               ***                ";       
	gotoXY(x,y+15); cout<<"               ***                ";       
	gotoXY(x,y+16); cout<<"               ***                ";       
	gotoXY(x,y+17); cout<<"               ***                ";       
	gotoXY(x,y+18); cout<<"               ***                ";       
	gotoXY(x,y+19); cout<<"               ***                ";
	int color2 = rand() % (13-2+1)+2;    
	TextColor(color2);   
	gotoXY(x,y+20); cout<<"                                  ";       
	gotoXY(x,y+21); cout<<"               ***                ";       
	gotoXY(x,y+22); cout<<"             *** ***              ";       
	gotoXY(x,y+23); cout<<"            ***   ***             ";       
	gotoXY(x,y+24); cout<<"           ***     ***            ";       
	gotoXY(x,y+25); cout<<"          ***       ***           ";       
	gotoXY(x,y+26); cout<<"         ***         ***          ";       
	gotoXY(x,y+27); cout<<"        *****************         ";       
	gotoXY(x,y+28); cout<<"       *******************        ";       
	gotoXY(x,y+29); cout<<"      ***               ***       ";       
	gotoXY(x,y+30); cout<<"     ***                 ***      ";    
		TextColor(color+1);    
}

void Welcome(){
	int x = 55; 
	int y = 2;
	int color =rand() % (6-1+1)+1;
	TextColor(270);	gotoXY(x+13,y-1); printf("  Nguyen Le Minh - Lop: ANHTTT k54  ");
	TextColor(color);
	gotoXY(x,y);	cout << GOC1;
	for(int i=1; i<61; i++){
		gotoXY(x+1*i,y);	cout << NGANG;
	}
	gotoXY(x+60,y); cout <<GOC2;
	gotoXY(x,y+1); cout<<"                                                           ";
	TextColor(color+1);
	gotoXY(x,y+2); cout<<"          CHUONG TRINH QUAN LY TRANG THIET BI HVKTQS         ";
	TextColor(color);
	gotoXY(x,y+3); cout<<"                                                           ";
	gotoXY(x,y+4); cout<<GOC4;
	for(int i=1; i<61; i++){
		gotoXY(x+1*i,y+4);cout << NGANG;
	}
	gotoXY(x+60,y+4); cout <<GOC3;
	MTA();
}

void Khung_menu_hieu_ung(int x, int y, string a[], int n, int k){
	gotoXY(x,y);
	for(int i=0; i<n; i++){
		if(i==k) Khung_hieu_ung(x,y+k*3);
		else Khung_don(x,y + i*3,a[i]);
	}
}

int Screen1_Mouse_event(MOUSE_EVENT_RECORD mer, int x, int y,string a[6],int n){
	if(mer.dwEventFlags == MOUSE_MOVED){
		for(int i=0; i<n; i++){
			if(mer.dwMousePosition.X >= x && mer.dwMousePosition.X <(x+20) && mer.dwMousePosition.Y > (y+i*3-1) && mer.dwMousePosition.Y <((y+i*3)+3)){
				Khung_menu_hieu_ung(x,y,a,n,i);
			}
		}
		if(mer.dwMousePosition.X <= x || mer.dwMousePosition.X >(x+20) || mer.dwMousePosition.Y <(y-1) || mer.dwMousePosition.Y >(y+n*3)){
			Khung_menu(x,y,a,n);
			if(mer.dwMousePosition.X >= 2 && mer.dwMousePosition.X <(2+20) && mer.dwMousePosition.Y > 35 && mer.dwMousePosition.Y <40) Khung_hieu_ung(2,35);
		}
	}
	if(mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED){
		for(int i=0; i<n; i++){
			if(mer.dwMousePosition.X >= x && mer.dwMousePosition.X <(x+20) && mer.dwMousePosition.Y > (y+i*3-1) && mer.dwMousePosition.Y <((y+i*3)+3)){
				Khung_hieu_ung(x,y+i*3);
				return i;
			}
		}
			if(mer.dwMousePosition.X >= 2 && mer.dwMousePosition.X <(2+20) && mer.dwMousePosition.Y > 35 && mer.dwMousePosition.Y <40) Reset();
	}
	return -1;
}

int Screen1(HANDLE &hStdin, INPUT_RECORD &irInBuf ) {
	Xoa_Full_Man_hinh();
 	DWORD  cNumRead,i; 
	Khung_menu(2,8,Menu,6);
	An_tro_chuot();
    while(true){  
    		ReadConsoleInput( hStdin, &irInBuf, 1, &cNumRead); 
	 		Welcome(); 
            if(irInBuf.EventType == MOUSE_EVENT){
                    switch(index1){
                    	case -1:{
                    		index1 = Screen1_Mouse_event(irInBuf.Event.MouseEvent, 2,8,Menu,6);break;
						}
                    	case 0: {
							index1 = -1;
							return 0;
						}
						case 1: {
							index1 = -1;
							return 1;
						}
						case 2:{
							switch(index2){
								case -1:{
									index2 = Screen1_Mouse_event(irInBuf.Event.MouseEvent, 25,14,Sap_xep,2); break;
								}
								case 0:{
									index3 = Screen1_Mouse_event(irInBuf.Event.MouseEvent, 50,14,Sx_Thuat_toan,4); break;
								}
								case 1:{
									index3 = Screen1_Mouse_event(irInBuf.Event.MouseEvent, 50,17,Sx_Tu_khoa,3); break;
								}
							}break;
						}
						case 3:{
							switch(index2){
								case -1:{
									index2 = Screen1_Mouse_event(irInBuf.Event.MouseEvent, 25,17,Tim_kiem,2);break;
								}
								case 0:{
									index3 = Screen1_Mouse_event(irInBuf.Event.MouseEvent, 50,17,Tk_Tu_khoa,6);break;
								}
								case 1:{
									index3 = Screen1_Mouse_event(irInBuf.Event.MouseEvent, 50,20,Tk_Thuat_Toan,2);break;
								}
							}break;
						}
						case 4:{
							switch(index2){
								case -1:{
									index3 = Screen1_Mouse_event(irInBuf.Event.MouseEvent, 25,20,Thong_ke,2);break;
								}
							}break;
						}
						case 5:{
							index3 = Exit_function(irInBuf.Event.MouseEvent);
							if(index3 == -2){
								End();
							}
							break;
						}
					}
            } 
	}
}

