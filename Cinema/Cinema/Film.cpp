#include "Film.h"
#include <string.h>
#include <iostream>
using namespace std;

Film::Film()
{
	strcpy_s(name, "empty");
	strcpy_s(year, "empty");
	strcpy_s(genre, "empty");
	price = 0;
}

Film::Film(const char* _name, const char* _year, const char* _genre, double _price)
{
	strcpy_s(name, _name);
	strcpy_s(year, _year);
	strcpy_s(genre, _genre);
	price = _price;
}

void Film::Print()
{
	cout << "Name: " << name << endl;
	cout << "Year: " << year << endl;
	cout << "Genre: " << genre << endl;
	cout << "Price: " << price << endl;
}

void Film::operator=(Film& newMovie)
{
	strcpy_s(name, newMovie.name);
	strcpy_s(year, newMovie.year);
	strcpy_s(genre, newMovie.genre);
	price = newMovie.price;
}
