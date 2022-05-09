#include "Ticket.h"
#include <string.h>
#include <iostream>
using namespace std;

Ticket::Ticket(int _seatNum, int _rowNum, const char* _date, double _price, Film _movie)
{
	seatNum = _seatNum;
	rowNum = _rowNum;
	strcpy_s(date, _date);
	price = _price;
	movie = _movie;
}

double Ticket::BuyTicket(int _seatNum, int _rowNum)
{
	seatNum = _seatNum;
	rowNum = _rowNum;
	return price;
}

void Ticket::Print()
{
	cout << "Seat num: " << seatNum << " Row num: " << rowNum<<endl;
	movie.Print();
}

int Ticket::GetSeatNum()
{
	return seatNum;
}

int Ticket::GetRowNum()
{
	return rowNum;
}
