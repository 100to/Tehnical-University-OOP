#pragma once
#include"Film.h"
class Ticket
{
protected:
	int seatNum;
	int rowNum;
	char date[30];
	Film movie;
	double price;
public:
	Ticket(int _seatRow, int _rowNum, const char* _date, double _price, Film _movie);
	virtual double BuyTicket(int _numInRow, int _rowNum);
	virtual void Print();
	int GetSeatNum();
	int GetRowNum();
};

