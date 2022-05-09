#include "StudentTicket.h"
#include <iostream>
using namespace std;

StudentTicket::StudentTicket(int _seatRow, int _rowNum, const char* _date, double _price, Film _movie)
    :Ticket(_seatRow,_rowNum,_date,_price,_movie)
{
}

double StudentTicket::BuyTicket(int _seatNum, int _rowNum)
{
    seatNum = _seatNum;
    rowNum = _rowNum;
    return price*0.80;
}

void StudentTicket::Print()
{
    cout << "Seat num: " << seatNum << " Row num: " << rowNum<<endl;
    movie.Print();
}
