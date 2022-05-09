#pragma once
class Property
{
private:
	char address[50];
	char owner[50];
	double price;
	double area;
public:
	Property();
	Property(const char* _adress, const char* _owner, double _price, double _area);
	virtual void Print();
	void operator=(Property& newProperty);
	double GetPrice();
	char* GetAddress();
};
class House : public Property
{
	int numberOfRooms;
	int floors;
	double yardArea;
public:
	House();
	House(int num, int _floors, double area, const char* _adress, const char* _owner, double _price, double _area);
	void Print();
};

class Apartament : public Property
{
	int numberOfRooms;
	int floor;
public:
	Apartament();
	Apartament(int num, int _floor, const char* _adress, const char* _owner, double _price, double _area);
	void Print();
};

class Plot : public Property
{
	bool water;
	bool electricity;
	bool pathToRoad;
public:
	Plot();
	Plot(bool _water, bool _electricity, bool _path, const char* _adress, const char* _owner, double _price, double _area);
	void Print();
};


