#include "stdafx.h"
#include "BankH.h"
#include "BankClientH.h"
#include "Fibonacci.h"
#include <iostream>


BankH::BankH(int _maxNumberOfClients)
{
	FNumber = *new Fibonacci();
	Current = 0;
	MaxNumberOfClients = FNumber.Set(_maxNumberOfClients);
	allClients = new BankClient[MaxNumberOfClients];
}

bool BankH::AddClient(BankClient& newClient)
{
	if (Current < MaxNumberOfClients)
	{
		allClients[Current] = newClient;
	}
	else
	{
		BankClient* temp = new BankClient[MaxNumberOfClients];
		temp = allClients;
		MaxNumberOfClients = FNumber.Set(MaxNumberOfClients);
		allClients = new BankClient[MaxNumberOfClients];
		for (int i = 0; i < Current; i++)
		{
			allClients[i] = temp[i];
		}
		allClients[Current] = newClient;
	}
	Current++;
	return true;
}

void BankH::DeleteClient(int searchNumber)
{
	for (int i = 0; i < Current; i++)
	{
		if (allClients[i].GetClientNumber() == searchNumber)
		{
			if (Current == 1)
			{
				allClients[0] = *new BankClient("empty", "empty", 0);
			}
			else if (Current == MaxNumberOfClients-1)
			{
				allClients[Current] = *new BankClient("empty", "empty", 0);
			}
			else
			{
				for (int j = i; j < Current - 1; j++)
				{
					allClients[j] = allClients[j + 1];
				}
			}
			Current--;
			break;
		}
	}
}

BankH::~BankH()
{
	delete[]this->allClients;
}

