#pragma once
class MovieTheater
{
protected:
	int seats[10][16];
	int boughtTickets;
public:
	MovieTheater();
	void AddNewPeople(int seatNum,int rowNum, int numOfPeople);
	void PrintAllSeats();
};

