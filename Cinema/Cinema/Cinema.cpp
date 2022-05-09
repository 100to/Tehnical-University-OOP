#include <iostream>
#include "Film.h"
#include "GroupTicket.h"
#include "MovieTheater.h"
#include "StudentTicket.h"
#include "Ticket.h"

int main()
{
	MovieTheater cinema;
	Ticket* array[5];
	Film film("John Wick 3", "15/03/2019", "Action", 20);
	Ticket ticket(0, 3,"15/03/2019", 20, film);
	cinema.AddNewPeople(ticket.GetSeatNum(), ticket.GetRowNum(), 1);
	StudentTicket studentTicket(2, 3, "15/03/2019", 20, film);
	cinema.AddNewPeople(studentTicket.GetSeatNum(), studentTicket.GetRowNum(), 1);
	GroupTicket groupTicket(22, 2, 8, "15/03/2019", 20, film);

	array[0] = &ticket;
	array[1] = &studentTicket;
	array[2] = &groupTicket;

	for (int i = 0; i < 3; i++)
	{
		array[i]->BuyTicket(i, 1);
	}

	cinema.AddNewPeople(groupTicket.GetSeatNum(), groupTicket.GetRowNum(),22);
	ticket.Print();
	studentTicket.Print();
	groupTicket.Print();
	cinema.PrintAllSeats();
}

