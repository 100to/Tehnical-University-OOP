#pragma once
#include "AccountInfoH.h"
#define SIZE 10

class BankClient
{
private:
	char firstName[20];
	char lastName[20];
	int clientNumber;
	int currentNumberOfBankAccounts;
	AccountInfo accountInfo[SIZE];
	int CheckForAcc(AccountInfo& accToRemove);
public:
	BankClient();
	int GetClientNumber();
	BankClient(const char* firstName, const char* lastName,int clNumber);
	bool AddAccount(AccountInfo accInfo);
	bool RemoveAccount(AccountInfo& accToRemove);
	int CheckWithIBAN(const char* searchIBAN);
	void AddAmount(const char* IbanForAddAmount, double addAmount);
	double SumOfAmount();
	void PrintClient();
	void operator=(BankClient& newClient);
};

