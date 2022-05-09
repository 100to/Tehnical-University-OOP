#pragma once
class Film
{
	char name[30];
	char year[30];
	char genre[30];
	double price;
public:
	Film();
	Film(const char* _name, const char* _year,const char* _genre, double _price);
	void Print();
	void operator=(Film& newMovie);
};

