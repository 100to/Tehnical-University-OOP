#include "Property.h"
#include <string.h>
#include <iostream>
using namespace std;

House::House(int num, int _floors, double area, const char* _adress, const char* _owner, double _price, double _area)
	: Property(_adress, _owner, _price, _area)
{
	numberOfRooms = num;
	floors = _floors;
	yardArea = area;
}

void House::Print()
{
	cout << "Number of rooms: " << numberOfRooms << endl;
	cout << "Floors: " << floors << endl;
	cout << "Yard Area: " << yardArea << endl;

}

House::House()
{
	numberOfRooms = 0;
	floors = 0;
	yardArea = 0;
}


Apartament::Apartament(int num, int _floor, const char* _adress, const char* _owner, double _price, double _area)
	: Property(_adress, _owner, _price, _area)
{
	numberOfRooms = num;
	floor = _floor;
}

void Apartament::Print()
{
	cout << "Number of rooms: " << numberOfRooms << endl;
	cout << "Floors: " << floor << endl;
}


Apartament::Apartament()
{
	numberOfRooms = 0;
	floor = 0;
}

Plot::Plot()
{
	water = false;
	electricity = false;
	pathToRoad = false;
}

Plot::Plot(bool _water, bool _electricity, bool _path, const char* _adress, const char* _owner, double _price, double _area)
	: Property(_adress, _owner, _price, _area)
{
	water = _water;
	electricity = _electricity;
	pathToRoad = _path;
}

void Plot::Print()
{
	cout << "Water: " << water << endl;
	cout << "Electricity: " << electricity << endl;
	cout << "Path to road: " << pathToRoad << endl;
}

Property::Property()
{
	strcpy_s(address, "emtpy");
	strcpy_s(owner, "emtpy");
	price = 0;
	area = 0;
}

Property::Property(const char* _adress, const char* _owner, double _price, double _area)
{
	strcpy_s(address, _adress);
	strcpy_s(owner, _owner);
	price = _price;
	area = _area;
}

void Property::Print()
{
	cout << "Adress: " << address << endl;
	cout << "Owner: " << owner << endl;
	cout << "Price: " << price << endl;
	cout << "Area: " << area << endl;
}

void Property::operator=(Property& newProperty)
{
	strcpy_s(address, newProperty.address);
	strcpy_s(owner, newProperty.owner);
	price = newProperty.price;
	area = newProperty.area;
}

double Property::GetPrice()
{
	return price;
}

char* Property::GetAddress()
{
	return address;
}


