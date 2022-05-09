#pragma once
#include "Ticket.h"
class GroupTicket : public Ticket
{
	int numOfPeople;
public:
	GroupTicket(int num, int _numInRow, int _rowNum, const char* _date, double _price, Film _movie);
	double BuyTicket(int _numInRow, int _rowNum) override;
	void Print() override;
};

