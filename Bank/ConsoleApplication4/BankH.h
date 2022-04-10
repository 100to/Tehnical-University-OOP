#pragma once
#include "BankClientH.h"
#include"Fibonacci.h"
class BankH
{
private:
	int Current;
	int MaxNumberOfClients;
	BankClient* allClients;
	Fibonacci FNumber;
public:
	BankH(int _MaxNumberOfClients);
	bool AddClient(BankClient& newClient);
	void DeleteClient(int searchNumber);
	~BankH();
};

