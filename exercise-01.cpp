/*
* Author 	: Jonathan Rafma Nanda Siregar
* NPM 		: 140810180056
* Deskripsi : Input self profile
* Tahun 	: 2019
*/
#include <iostream>
#include <string.h> 
using namespace std;

struct Orang{ //declaration of typedata of "People"
	int umur; //sub-typedata of "age"
	char nama[30]; //sub-typedata of "name" with 30 lengths
	char jk; //sub-typedata of "gender"
	char goldar; //sub-typedata of "blood-classification
};
int main(){
	Orang orang; //using struct People by name "people"
	cout << "nama  : "; cin >> orang.nama; // input People.name
	cout << "umur  : "; cin >> orang.umur; // input People.age
	cout << "jk    : "; cin >> orang.jk; // input People.gender
	cout << "goldar: "; cin >> orang.goldar; // input People.blood
	// ------ show all the input of struct "People" ------ //
	cout << endl << orang.nama << endl; 
	cout << orang.umur << endl;
	cout << orang.jk << endl;
	cout << orang.goldar << endl;
}
