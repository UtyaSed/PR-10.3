// PR_10_3.cpp
// Обухов Віктор
// Лабораторна робота № 10.3
// Опрацювання текстового файлу
// Варіант 7


#include <iostream>
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

struct Tovar
{
	string name;
	string market;
	int price;
	int kilk;
	string mass;

};

void enter_save(char* fname);
void load_print(char* fname);
void market_find(char* fname, char* market);

int main()
{
	char fname[61];
	char market[151];
	char ch;
	do
	{
		cout << "--------------------------------\n";
		cout << "Main Menu\n";
		cout << "Please make your selection\n" << endl;
		cout << "[1] - Enter & Save Data\n" << endl;
		cout << "[2] - Load & Print Data\n" << endl;
		cout << "[3] - Find market\n" << endl;
		cout << "[0] - Exit\n";
		cout << "--------------------------------\n";
		cout << "Your Choise: "; cin >> ch;
		switch (ch)
		{
		case '0':
			cout << "Goodbye! See Ya Later, Aligator!!!";
			break;
		case '1':
			cout << "You Chosen [1] - Enter & Save Data:\n";
			cin.get();
			cin.sync();
			cout << "Enter file name: "; cin.getline(fname, sizeof(fname));
			enter_save(fname);
			break;
		case '2':
			cout << "You Chosen [2] - Load & Print Data:\n";
			cin.get();
			cin.sync();
			cout << "Enter file name: "; cin.getline(fname, sizeof(fname));
			load_print(fname);
			break;
		case '3':
			cout << "You Chosen [3] - Find market:\n";
			cin.get();
			cin.sync();
			cout << "Enter File Name: "; cin.getline(fname, sizeof(fname));
			cout << "Enter name market: "; cin.getline(market, sizeof(market));
			market_find(fname, market);
			break;
		default:
			cout << endl;
			cout << "--------------------------------\n";
			cout << "Main Menu\n";
			cout << "Please make your selection\n";
			cout << "[1] - Enter & Save Data\n" << endl;
			cout << "[2] - Load & Print Data\n" << endl;
			cout << "[3] - Find Friend By Telephone\n" << endl;
			cout << "[0] - Exit\n";
			cout << "--------------------------------\n";
			cout << "Your Choise: "; cin >> ch;
		}
	} while (ch != '0');
	return 0;
}
void enter_save(char* fname)
{
	ofstream f(fname, ios::binary);
	if (!f)
	{
		cerr << "Error opening file '" << fname << "'" << endl;
		return;
	}
	Tovar tovar;
	char ch;
	do
	{
		cout << endl;
		cout << "Product name: "; cin.sync();
		cin >> tovar.name;
		cout << "Store name: "; cin.sync();
		cin >> tovar.market;
		cout << "Price: ";
		cin >> tovar.price;
		cout << "Number: ";
		cin >> tovar.kilk;
		cout << "Mass: ";
		cin >> tovar.mass;
		

		if (!f.write((char*)&tovar, sizeof(Tovar)))
		{
			cerr << "Error writing file." << endl;
		}
		cout << "Continue? (Y/N) "; cin >> ch;
	} while (ch == 'Y' || ch == 'y');
}
void load_print(char* fname)
{
	ifstream f(fname, ios::binary);
	if (!f)
	{
		cerr << "Error opening file '" << fname << "'" << endl;
		return;
	}

	Tovar tovar;
	while (f.read((char*)&tovar, sizeof(Tovar)))
	{
		cout << endl;
		cout <<  "Product name: " << tovar.name << endl;
		cout << "Store name: " << tovar.market << endl;
		cout << "Price: " << tovar.price << endl;
		cout << "Number: " << tovar.kilk << endl;
		cout << "Mass: " << tovar.mass << endl;

	}
}
void market_find(char* fname, char* market)
{
	ifstream f(fname, ios::binary);
	if (!f)
	{
		cerr << "Error opening file '" << fname << "'" << endl;
		return;
	}

	Tovar tovar;
	while (f.read((char*)&tovar, sizeof(Tovar)))
	{
		if (tovar.market == market) {
			cout << endl;
			cout << "Found market (" << market << ") :" << endl;
			cout << endl;
			cout << "Product name: " << tovar.name << endl;
			cout << "Store name: " << tovar.market << endl;
			cout << "Price: " << tovar.price << endl;
			cout << "Number: " << tovar.kilk << endl;
			cout << "Mass: " << tovar.mass << endl;
		}
		else
		{
			cout << "...";
			cout << endl;
		}
	}
	return;
}