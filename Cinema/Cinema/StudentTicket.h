#pragma once
#include "Ticket.h"
class StudentTicket : public Ticket 
{
public:
	StudentTicket(int _seatRow, int _rowNum, const char* _date, double _price, Film _movie);
	double BuyTicket(int _seatNum, int _rowNum) override;
	void Print() override;
};

