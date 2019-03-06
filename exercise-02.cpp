/*
* Author 	: Jonathan Rafma Nanda Siregar
* NPM 		: 140810180056
* Deskripsi : Pemesanan Tiket CinemaXXX1
* Tahun 	: 2019
*/
#include <iostream>
#include <string.h>
using namespace std;
struct Theater{
	int room;
	char seat[3];
	//string MovieTItle;
	char MovieTitle[30];
};
int main(){
	Theater theater;
//	cout << "Movie Title : "; getline(cin, theater.MovieTItle);
	cout << "Movie Title : "; cin.getline(theater.MovieTitle, 29);
	cout << "Movie seat  : "; cin >> theater.seat;
	cout << "Movie room  : "; cin >> theater.room;
	
	cout << endl << "Option of Movie Title : " << theater.MovieTitle;
	cout << endl << "Option of Movie seat  : " << theater.seat;
	cout << endl << "Option of Movie room  : " << theater.room;
}
