/*
* Author 	: Jonathan Rafma Nanda Siregar
* NPM 		: 140810180056
* Deskripsi : Input, Cetak, Gaji, Rata-rata, Tertinggi, Terendah Pegawai
* Tahun 	: 2019
*/
#include <iostream>
#include <string.h>
#include <conio.h>
#include <sstream>
using namespace std;
struct Pegawai{
	char nip[15];
	char nama[50];
	int gol;
};
typedef Pegawai LarikPgw[100];
void BanyakData(int& n);
void CariGaji(LarikPgw Pgw, int n);
void CetakDaftar(LarikPgw Pgw, int n);
void RataGaji(LarikPgw Pgw, int n);
void GajiTerendah(LarikPgw Pgw, int n);
void GajiTertinggi(LarikPgw Pgw, int n);
void InputPegawai(LarikPgw& Pgw, int n);
void Menu(int n);
int main(){
	LarikPgw Pgw;
	int n;
	BanyakData(n);
	InputPegawai(Pgw, n);
	Menu:
	int choice = 0;
	system("cls");
	cout << "[1] Cetak Daftar Pegawai\n[2] Cari Gaji\n[3] Rata Gaji\n[4] Gaji Terendah\n[5] Gaji Tertinggi\n\n  -> Jumlah Pegawai yang telah diinput ada " << n;
	cout << endl << "Pilihan    : "; cin >> choice;
	if (choice == 1){
		CetakDaftar(Pgw, n);
		cout << "\n\nKlik apa saja untuk melanjutkan...";
		getch();
		goto Menu;
	}
	else if (choice == 2){
		CariGaji(Pgw, n);
		cout << "\n\nKlik apa saja untuk melanjutkan...";
		getch();
		goto Menu;
	}
	else if (choice == 3){
		RataGaji(Pgw, n);
		cout << "\n\nKlik apa saja untuk melanjutkan...";
		getch();
		goto Menu;
	}
	else if (choice == 4){
		GajiTerendah(Pgw, n);
		cout << "\n\nKlik apa saja untuk melanjutkan...";
		getch();
		goto Menu;
	}
	else if (choice == 5){
		GajiTertinggi(Pgw, n);
		cout << "\n\nKlik apa saja untuk melanjutkan...";
		getch();
		goto Menu;
	}
	else if (choice <= 0 || choice > 5)
	{
		cout << "Pilihan tidak valid!"; getch();
		goto Menu;
	}

}
void BanyakData(int& n){
	while (n == 0 || n > 100)
	{
		system("cls");
		cout << "Masukkan banyaknya data : "; cin >> n;
	}
	if (n == 0 || n > 100){
	cout << "Jumlah data tidak valid! (valid, n > 0 dan n < 100)";
	getch();
	}
}
void InputPegawai(LarikPgw& Pgw, int n){
	for (int i = 0; i < n; i++){
		system("cls");
		cout << "-------------------------------------------------------------------" << endl;
		cout << "Input data ke-" << i+1 << endl;
		cout << "Nama (maks. 50 karakter)    : "; cin.ignore(); cin.getline(Pgw[i].nama, 49);
		cout << "NIP (maks. 15 karakter)     : "; cin.ignore(); cin.getline(Pgw[i].nip, 14);
		cout << "Golongan (1 karakter)       : "; cin>> Pgw[i].gol;
		//cout << "Golongan (only 1 characters) : "; cin.ignore(); cin >> Pgw[i].gol;
	}
	cout << "Proses penginputan data selesai! Klik apa saja untuk melanjutkan..."; getch();
}
void CetakDaftar(LarikPgw Pgw, int n){
	system("cls");
	printf("\n DAFTAR PARA PEGAWAI");
	printf("\n +----------------------------------------------------+-----------------+-----------+");
	printf("\n | NAMA                                               | NIP             | GOLONGAN  |");
	printf("\n +----------------------------------------------------+-----------------+-----------+");
	for (int h = 0; h < n; h++){
		string namaPgw = Pgw[h].nama;
		int NumOfCharOfNama = namaPgw.length();
		int LessNumOfNama = 50-NumOfCharOfNama;
		string NIPPgw = Pgw[h].nip;
		int NumOfCharOfNIP = NIPPgw.length();
		int LessNumOfNIP = 15-NumOfCharOfNIP;
		cout << "\n | " << Pgw[h].nama;
		for (int j = 0; j <= LessNumOfNama; j++){
			cout << " ";
		}
		cout << "| " << Pgw[h].nip;
		for (int k = 0; k <= LessNumOfNIP; k++){
			cout << " ";
		}
		cout << "| " << Pgw[h].gol;
		for (int m = 0; m <= 8; m++){
			cout << " ";
		}
		cout << "|";
	}
	printf("\n +----------------------------------------------------+-----------------+-----------+");
}
void CariGaji(LarikPgw Pgw, int n){
	system("cls");
	printf("\n DAFTAR GAJI PARA PEGAWAI");
	printf("\n +----------------------------------------------------+-----------------+");
	printf("\n | NAMA                                               | GAJI            |");
	printf("\n +----------------------------------------------------+-----------------+");
	for (int i = 0; i < n; i++)
	{
		string namaPgw = Pgw[i].nama;
		int NumOfCharOfNama = namaPgw.length();
		int LessNumOfNama = 50-NumOfCharOfNama;
		cout << "\n | " << Pgw[i].nama;
		for (int j = 0; j <= LessNumOfNama; j++){
			cout << " ";
		}
		cout << "| ";
		if (Pgw[i].gol == 1){
			cout << "IDR 2000000     |";
		}
		else if (Pgw[i].gol == 2){
			cout << "IDR 3000000     |";
		}
		else if (Pgw[i].gol == 3){
			cout << "IDR 5000000     |";
		}
		else if (Pgw[i].gol == 4){
			cout << "IDR 8000000     |";
		}
		else if (Pgw[i].gol < 1 || Pgw[i].gol > 4){
			cout << "IDR 0           |";
		}
	}
	printf("\n +----------------------------------------------------+-----------------+");
}
void RataGaji(LarikPgw Pgw, int n){
	system("cls");
	printf("\n DAFTAR RATA-RATA GAJI PEGAWAI");
	printf("\n +----------------------------------------------------+-----------------+");
	printf("\n | NAMA                                               | GAJI            |");
	printf("\n +----------------------------------------------------+-----------------+");
	int total = 0;
	int gaji = 0;
	for (int i = 0; i < n; i++){
		string namaPgw = Pgw[i].nama;
		int NumOfCharOfNama = namaPgw.length();
		int LessNumOfNama = 50-NumOfCharOfNama;
		cout << "\n | " << Pgw[i].nama;
		for (int j = 0; j <= LessNumOfNama; j++){
			cout << " ";
		}
		cout << "| ";
		if (Pgw[i].gol == 1){
			gaji = 2000;
			cout << "IDR 2000000     |";
		}
		else if (Pgw[i].gol == 2){
			gaji = 3000;
			cout << "IDR 3000000     |";
		}
		else if (Pgw[i].gol == 3){
			gaji = 5000;
			cout << "IDR 5000000     |";
		}
		else if (Pgw[i].gol == 4){
			gaji = 8000;
			cout << "IDR 8000000     |";
		}
		else if (Pgw[i].gol < 1 || Pgw[i].gol > 4){
			gaji = 0;
			cout << "IDR 0           |";
		}
		total = total+gaji;
	}
	printf("\n +----------------------------------------------------+-----------------+");
	cout <<"\n | JUMLAH TOTAL                                       | IDR ";
	stringstream ss;
	ss << total;
	string jumlah = ss.str();
	char NumOfCharOfJumlah = jumlah.length();
	int LessOfCharOfJumlah = 11-NumOfCharOfJumlah;
	cout << total << "000";
	for (int k = 0; k <= LessOfCharOfJumlah-3; k++){
		cout << " ";
	}
	cout << "|";
	printf("\n +----------------------------------------------------+-----------------+");
	printf("\n | RATA-RATA                                          | IDR ");
	int rata_rata = total/n;
	stringstream ss2;
	ss2 << rata_rata;
	string rata = ss2.str();
	char NumOfCharOfRata = rata.length();
	int LessOfCharOfRata = 11-NumOfCharOfRata;
	cout << rata_rata << "000";
	for (int a = 0; a <= LessOfCharOfRata-3; a++){
		cout << " ";
	}
	cout << "|";
	printf("\n +----------------------------------------------------+-----------------+");
}
void GajiTerendah(LarikPgw Pgw, int n){
	system("cls");
	printf("\n DAFTAR GAJI TERENDAH");
	printf("\n +----------------------------------------------------+-----------------+");
	printf("\n | NAMA                                               | GAJI            |");
	printf("\n +----------------------------------------------------+-----------------+");
	int prob = 0;
	int prob2 = 0;
	int prob3 = 0;
	int prob4 = 0;
	for (int i = 0; i < n; i++){
		if (Pgw[i].gol == 1){
			prob = 1;
			string namaPgw = Pgw[i].nama;
			int NumOfCharOfNama = namaPgw.length();
			int LessNumOfNama = 50-NumOfCharOfNama;
			cout << "\n | " << Pgw[i].nama;
			for (int j = 0; j <= LessNumOfNama; j++){
				cout << " ";
			}
			cout << "| IDR 2000000     |";
			printf("\n +----------------------------------------------------+-----------------+");
		}
	}
	if (prob == 0){
		for (int k = 0; k < n; k++){
			if (Pgw[k].gol == 2){
				prob2 = 1;
				string namaPgw = Pgw[k].nama;
				int NumOfCharOfNama = namaPgw.length();
				int LessNumOfNama = 50-NumOfCharOfNama;
				cout << "\n | " << Pgw[k].nama;
				for (int l = 0; l <= LessNumOfNama; l++){
					cout << " ";
				}
				cout << "| IDR 3000000     |";
				printf("\n +----------------------------------------------------+-----------------+");
			}
		}
		if (prob2 == 0){
			for (int m = 0; m < n; m++){
				if (Pgw[m].gol == 3){
					prob3 = 1;
					string namaPgw = Pgw[m].nama;
					int NumOfCharOfNama = namaPgw.length();
					int LessNumOfNama = 50-NumOfCharOfNama;
					cout << "\n | " << Pgw[m].nama;
					for (int p = 0; p <= LessNumOfNama; p++){
						cout << " ";
					}
					cout << "| IDR 5000000     |";
					printf("\n +----------------------------------------------------+-----------------+");
				}
			}
			if (prob3 == 0){
				for (int q = 0; q < n; q++){
					if (Pgw[q].gol == 4){
						prob4 = 1;
						string namaPgw = Pgw[q].nama;
						int NumOfCharOfNama = namaPgw.length();
						int LessNumOfNama = 50-NumOfCharOfNama;
						cout << "\n | " << Pgw[q].nama;
						for (int r = 0; r <= LessNumOfNama; r++){
							cout << " ";
						}
						cout << "| IDR 8000000     |";
						printf("\n +----------------------------------------------------+-----------------+");
					}
				}
				if (prob4 == 0){
					for (int s = 0; s < n; s++){
						if (Pgw[s].gol < 1 || Pgw[s].gol > 4){
							string namaPgw = Pgw[s].nama;
							int NumOfCharOfNama = namaPgw.length();
							int LessNumOfNama = 50-NumOfCharOfNama;
							cout << "\n | " << Pgw[s].nama;
							for (int t = 0; t <= LessNumOfNama; t++){
								cout << " ";
							}
							cout << "| IDR 0           |";
							printf("\n +----------------------------------------------------+-----------------+");
						}
					}
				}
			}
		}
	}
}
void GajiTertinggi(LarikPgw Pgw, int n){
	system("cls");
	printf("\n DAFTAR GAJI TERTINGGI");
	printf("\n +----------------------------------------------------+-----------------+");
	printf("\n | NAMA                                               | GAJI            |");
	printf("\n +----------------------------------------------------+-----------------+");
	int prob = 0;
	int prob2 = 0;
	int prob3 = 0;
	int prob4 = 0;
	for (int i = 0; i < n; i++){
		if (Pgw[i].gol == 4){
			prob = 1;
			string namaPgw = Pgw[i].nama;
			int NumOfCharOfNama = namaPgw.length();
			int LessNumOfNama = 50-NumOfCharOfNama;
			cout << "\n | " << Pgw[i].nama;
			for (int j = 0; j <= LessNumOfNama; j++){
				cout << " ";
			}
			cout << "| IDR 8000000     |";
			printf("\n +----------------------------------------------------+-----------------+");
		}
	}
	if (prob == 0){
		for (int k = 0; k < n; k++){
			if (Pgw[k].gol == 3){
				prob2 = 1;
				string namaPgw = Pgw[k].nama;
				int NumOfCharOfNama = namaPgw.length();
				int LessNumOfNama = 50-NumOfCharOfNama;
				cout << "\n | " << Pgw[k].nama;
				for (int l = 0; l <= LessNumOfNama; l++){
					cout << " ";
				}
				cout << "| IDR 5000000     |";
				printf("\n +----------------------------------------------------+-----------------+");
			}
		}
		if (prob2 == 0){
			for (int m = 0; m < n; m++){
				if (Pgw[m].gol == 2){
					prob3 = 1;
					string namaPgw = Pgw[m].nama;
					int NumOfCharOfNama = namaPgw.length();
					int LessNumOfNama = 50-NumOfCharOfNama;
					cout << "\n | " << Pgw[m].nama;
					for (int p = 0; p <= LessNumOfNama; p++){
						cout << " ";
					}
					cout << "| IDR 3000000     |";
					printf("\n +----------------------------------------------------+-----------------+");
				}
			}
			if (prob3 == 0){
				for (int q = 0; q < n; q++){
					if (Pgw[q].gol == 1){
						prob4 = 1;
						string namaPgw = Pgw[q].nama;
						int NumOfCharOfNama = namaPgw.length();
						int LessNumOfNama = 50-NumOfCharOfNama;
						cout << "\n | " << Pgw[q].nama;
						for (int r = 0; r <= LessNumOfNama; r++){
							cout << " ";
						}
						cout << "| IDR 2000000     |";
						printf("\n +----------------------------------------------------+-----------------+");
					}
				}
				if (prob4 == 0){
					for (int s = 0; s < n; s++){
						if (Pgw[s].gol < 1 || Pgw[s].gol > 4){
							string namaPgw = Pgw[s].nama;
							int NumOfCharOfNama = namaPgw.length();
							int LessNumOfNama = 50-NumOfCharOfNama;
							cout << "\n | " << Pgw[s].nama;
							for (int t = 0; t <= LessNumOfNama; t++){
								cout << " ";
							}
							cout << "| IDR 0           |";
							printf("\n +----------------------------------------------------+-----------------+");
						}
					}
				}
			}
		}
	}
}
