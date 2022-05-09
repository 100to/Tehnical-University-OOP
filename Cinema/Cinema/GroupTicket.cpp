#include "GroupTicket.h"
#include <iostream>
using namespace std;

GroupTicket::GroupTicket(int num, int _numInRow, int _rowNum, const char* _date, double _price, Film _movie)
	: Ticket(_numInRow, _rowNum, _date, _price, _movie)
{
	numOfPeople = num;
}

double GroupTicket::BuyTicket(int _numInRow, int _rowNum)
{
	if (numOfPeople > 20)
	{
		return (price * 0.8) * numOfPeople;
	}
	else if (numOfPeople > 10)
	{
		return (price * 0.9) * numOfPeople;
	}
	else
	{
		return price * numOfPeople;
	}
}

void GroupTicket::Print()
{
	cout << "Seat num: " << seatNum << " Row num: " << rowNum << endl;
	cout << "Number of people: " << numOfPeople << endl;
	movie.Print();
}
