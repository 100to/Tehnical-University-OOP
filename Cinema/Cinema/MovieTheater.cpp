#include "MovieTheater.h"
#include <iostream>
using namespace std;

MovieTheater::MovieTheater()
{
	boughtTickets = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			seats[i][j] = 0;
		}
	}
}

void MovieTheater::AddNewPeople(int seatNum, int rowNum, int numOfPeople)
{
	if (seats[rowNum][seatNum] == 0 && numOfPeople == 1)
	{
		seats[rowNum][seatNum] = 1;
		boughtTickets++;
	}
	else if (numOfPeople > 1)
	{
		bool freeSeats = false;
		int countOfFreeSeats = 0;
		int lastRowNum = 0;
		int lastSeatNum = 0;
		for (int i = rowNum; i < 10; i++)
		{
			for (int j = seatNum; j < 16; j++)
			{
				if (seats[i][j] == 0)
				{
					countOfFreeSeats++;
				}
				else
				{
					countOfFreeSeats = 0;
				}
				if (countOfFreeSeats == numOfPeople)
				{
					freeSeats = true;
					lastRowNum = i;
					lastSeatNum = j;
					break;
				}
			}
			if (freeSeats == true)
			{
				break;
			}
		}
		if (freeSeats == true)
		{
			bool newRow = false;
			for (int i = 0; i < numOfPeople; i++)
			{
				if (lastSeatNum - i >= 0 && newRow == false)
				{
					seats[lastRowNum][lastSeatNum - i] = 1;
				}
				else if (lastSeatNum - i < 0 && newRow == false)
				{
					newRow = true;
					lastRowNum--;
					lastSeatNum = 15;
					seats[lastRowNum][lastSeatNum] = 1;
				}
				else
				{
					if (lastSeatNum > 0)
					{
						lastSeatNum--;
						seats[lastRowNum][lastSeatNum] = 1;
					}
					else
					{
						lastRowNum--;
						lastSeatNum = 15;
						seats[lastRowNum][lastSeatNum] = 1;
					}
				}
			}
			boughtTickets += numOfPeople;
		}
	}
}

void MovieTheater::PrintAllSeats()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			cout << seats[i][j] << " ";
		}
		cout << endl;
	}
}
