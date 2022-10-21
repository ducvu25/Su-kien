#include <iostream>
#include <vector>
#include <windows.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;
int x = 40;
int y = 60;
void TextColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void gotoXY(int x, int y) { // x la ngang, y la doc
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
vector <string> input(char *s){
	ifstream cin(s);
	vector <string> kq;
	string x;
	while(1){
		if(!getline(cin, x))
			return kq;
		kq.push_back(x);
	} 
}

void Sao(int n, int *xi, int *yi, int d){
	for(int i=0; i<n; i++){
		int mau = rand() %14 + 1;
		TextColor(mau);
		gotoXY(xi[i], yi[i]);
		cout << "*";
	}
	if(d == 0)
		for(int i=0; i<n; i++){
			gotoXY(xi[i], yi[i]);
			cout << " ";
		}
}
void VePhao(int xi, int yi, vector<string> phao){
	for(int i=0; i<phao.size(); i++){
		gotoXY(x + xi, y - yi + i);
		cout << phao[i];
	}
}
char** Mang(){
	vector <string> no = input("./no.txt");
	char** kq = new char*[no.size()];
	for(int i=0; i<no.size(); i++)
		kq[i] = new char[80];
	for(int i=0; i<no.size(); i++)
		for(int j=0; j<80; j++){
			if(j > no[i].size() - 1)
				kq[i][j] = 32;
			else
				kq[i][j] = no[i][j];
		}
	return kq;
}
void No(int nx, int ny, int n){
	int d = 0;
	char** s = Mang();
	for(int i=0; i<30/n; i++){
		switch(i % 3){
			case 0:{
				for(int jj=13; jj<21; jj++)
					for(int j=20; j<53; j++){
						int mau = rand() %14 + 1;
						TextColor(mau);
						gotoXY(x + j - nx, jj + ny);
						cout << s[jj][j];
					}
				break;
			}
			case 1:{
				for(int jj=5; jj<25; jj++)
					for(int j=10; j<73; j++){
						int mau = rand() %14 + 1;
						TextColor(mau);
						gotoXY(x + j - nx, jj + ny);
						cout << s[jj][j];
//						Sleep(10);
					}
				break;
			}
			case 2:{
				for(int jj=5; jj<27; jj++)
					for(int j=0; j<80; j++){
						int mau = rand() %14 + 1;
						TextColor(mau);
						gotoXY(x + j - nx, jj + ny);
						cout << s[jj][j];
//						Sleep(10);
					}
				break;
			}
		}
		Sleep(100);
	}
}
void Phao(vector<string> phao){
	vector <string> phao2 = input("./Be phong.txt");
	for(int ii=0; ii<phao2.size(); ii++){
			gotoXY(x - 22, y + ii);
			cout << phao2[ii];
		}
	Sleep(200);
	int n = 200;
	int xi[n], yi[n];
	for(int i=0; i<50; i++){
		if(i % 24 == 1){
			for(int j=0; j<n; j++){
				xi[j] = (rand() %20+ 2)*10;
				yi[j] = y - i - (rand() %13)*2 + 10;
			}
			Sao(n, xi, yi, 1);
		}
		if(i % 24 == 0)
			Sao(n, xi, yi, 0);
		TextColor(11);
		VePhao(0, i, phao);
		gotoXY(15, y - i - phao.size() - 5);
		Sleep(200);
	}
	No(18,7, 1);
}

void Chim(int nx, int ny){
	vector<string> c1 = input("./Chim1.0.txt");
	vector<string> c2 = input("./Chim2.0.txt");
	vector<string> c3 = input("./Chim3.0.txt");
	vector<string> c4 = input("./Chim4.0.txt");
	for(int j=20; j<=130; j++){
		if(j % 4 == 0){
			for(int i=0; i<c4.size(); i++){
				int start = 130 - j;
				if(start < 0)
					start = 0;
				for(int t = start; t < c4[i].size(); t++){
					gotoXY(x + j + t + nx, y+i + ny);
					cout << c4[i][t];
				}
			}
		}else if(j % 3 == 0){
			for(int i=0; i<c3.size(); i++){
				int start = 130 - j;
				if(start < 0)
					start = 0;
				for(int t = start; t < c4[i].size(); t++){
					gotoXY(x + j + t + nx, y+i + ny);
					cout << c3[i][t];
				}
			}
		}else if(j % 2 == 0){
			for(int i=0; i<c2.size(); i++){
				int start = 130 - j;
				if(start < 0)
					start = 0;
				for(int t = start; t < c4[i].size(); t++){
					gotoXY(x + j + t + nx, y+i + ny);
					cout << c2[i][t];
				}
			}
		}else{
			for(int i=0; i<c1.size(); i++){
				int start = 130 - j;
				if(start < 0)
					start = 0;
				for(int t = start; t < c4[i].size(); t++){
					gotoXY(x + j + t + nx, y+i + ny);
					cout << c1[i][t];
				}
			}
		}
		//Sleep(50);
	}
}

void Banh(vector<string> banh){
	vector<string> c1 = input("./Chim1.0.txt");
	vector<string> c2 = input("./Chim2.0.txt");
	vector<string> c3 = input("./Chim3.0.txt");
	vector<string> c4 = input("./Chim4.0.txt");
	int n = 5;
	TextColor(8);
	for(int i=banh.size() - 1; i>=0; i--){
		gotoXY(x, y + i - n);
		cout << banh[i] << endl;
		Sleep(100);
	}
	TextColor(7);
	for(int i=banh.size() - 1; i>=0; i--){
		gotoXY(x, y + i- n);
		cout << banh[i] << endl;
	}
	int nx = 170, ny = -20;
	Chim(40, -20);
	int xi[30], yi[30];
	for(int i=0; i<5; i++){
		TextColor(11);
		gotoXY(x + 18, y + 4- n); cout << ')';
		gotoXY(x + 26, y + 3- n); cout << '(';
		gotoXY(x + 40, y + 3- n); cout << ')';
		gotoXY(x + 48, y + 4- n); cout << '(';
		Sleep(200);
		TextColor(12);
		gotoXY(x + 18, y + 4- n); cout << " ";
		gotoXY(x + 26, y + 3- n); cout << " ";
		gotoXY(x + 40, y + 3- n); cout << " ";
		gotoXY(x + 48, y + 4- n); cout << " ";
		gotoXY(x + 18, y + 3- n); cout << char(3);
		gotoXY(x + 26, y + 2- n); cout << char(3);
		gotoXY(x + 40, y + 2- n); cout << char(3);
		gotoXY(x + 48, y + 3- n); cout << char(3);
		for(int j=0; j<30; j++){
			xi[j] = (rand() %12 + 1)*6;
			yi[j] = (rand() %4 + 5)*4;
			int mau = rand() %14 + 1;
			TextColor(mau);
			gotoXY(x + xi[j], yi[j]);
			cout << "*";
			Sleep(25);
		}
		for(int j=0; j<30; j++){
			gotoXY(x + xi[j], yi[j]);
			cout << " ";
		}
		gotoXY(x + 18, y + 3- n); cout << " ";
		gotoXY(x + 26, y + 2- n); cout << " ";
		gotoXY(x + 40, y + 2- n); cout << " ";
		gotoXY(x + 48, y + 3- n); cout << " ";
		Sleep(200);
		gotoXY(x + 18, y + 2- n); cout << char(3);
		gotoXY(x + 26, y + 1- n); cout << char(3);
		gotoXY(x + 40, y + 1- n); cout << char(3);
		gotoXY(x + 48, y + 2- n); cout << char(3);
		for(int j=0; j<30; j++){
			xi[j] = (rand() %12 + 1)*6;
			yi[j] = (rand() %4 + 5)*4;
			int mau = rand() %14 + 1;
			TextColor(mau);
			gotoXY(x + xi[j], yi[j]);
			cout << "*";
			Sleep(25);
		}
		for(int j=0; j<30; j++){
			gotoXY(x + xi[j], yi[j]);
			cout << " ";
		}
		gotoXY(x + 18, y + 2- n); cout << " ";
		gotoXY(x + 26, y + 1- n); cout << " ";
		gotoXY(x + 40, y + 1- n); cout << " ";
		gotoXY(x + 48, y + 2- n); cout << " ";
		Sleep(200);
		TextColor(14);
		gotoXY(x + 18, y + 4- n); cout << '(';
		gotoXY(x + 26, y + 3- n); cout << ')';
		gotoXY(x + 40, y + 3- n); cout << '(';
		gotoXY(x + 48, y + 4- n); cout << ')';
		TextColor(14);
		for(int t=0; t<10; t++){
			for(int ix=0; ix<c4.size(); ix++){
				gotoXY(x  + nx, y+ix + ny);
				cout<<c4[ix];
			}
			Sleep(200);
			for(int ix=0; ix<c3.size(); ix++){
				gotoXY(x + nx, y+ix + ny);
				cout<<c3[ix];
			}
			Sleep(200);
			for(int ix=0; ix<c2.size(); ix++){
				gotoXY(x + nx, y+ix + ny);
				cout<<c2[ix];
			}
			Sleep(200);
			for(int ix=0; ix<c1.size(); ix++){
				gotoXY(x + nx, y+ix + ny);
				cout<<c1[ix];
			}
			Sleep(200);
		}
		Sleep(200);
		No(-65, 15, 4);
		No(40, 15, 4);
	}
}
void End(int nx, int ny){
	vector <string> hoa = input("./Hoa.txt");
	for(int i=0; i<hoa.size(); i++){
		for(int j=0; j<hoa[i].size(); j++){
			gotoXY(x +j +nx, y + i + ny);
			if(hoa[i][j] == ':' || hoa[i][j] == '\'')
				TextColor(15);
			else
				TextColor(12);
			cout << hoa[i][j];
		}
		Sleep(100);
	}
}
int main(){
	getch();
	vector <string> banh = input("./banh.txt");
	vector <string> phao = input("./phao.txt");
	Phao(phao);
	system("cls");
	Banh(banh);
	End(0, 1);
	return 0;
}
