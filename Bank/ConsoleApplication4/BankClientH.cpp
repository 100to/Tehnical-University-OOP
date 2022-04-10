#include "stdafx.h"
#include <iostream>
#include "BankClientH.h"
#include <string.h>
#define SIZE 10
using namespace std;


BankClient::BankClient()
{
	strcpy_s(firstName, 20, "empty");
	strcpy_s(lastName, 20, "empty");
	clientNumber = 0;
	currentNumberOfBankAccounts = 0;
}

int BankClient::GetClientNumber()
{
	return clientNumber;
}

BankClient::BankClient(const char* firstName, const char* lastName, int clNumber)
{
	strcpy_s(this->firstName, 20, firstName);
	strcpy_s(this->lastName, 20, lastName);
	clientNumber = clNumber;
	this->currentNumberOfBankAccounts = 0;
}

bool BankClient::AddAccount(AccountInfo accInfo)
{
	if (currentNumberOfBankAccounts < SIZE)
	{
		this->accountInfo[this->currentNumberOfBankAccounts] = accInfo;
		this->currentNumberOfBankAccounts++;
		return true;
	}
	return false;
}

int BankClient::CheckForAcc(AccountInfo& accToRemove)
{
	for (int i = 0; i < currentNumberOfBankAccounts; i++)
	{
		if (this->accountInfo[i] == accToRemove)
		{
			return i;
		}
	}
	return -1;
}

bool BankClient::RemoveAccount(AccountInfo& accToRemove)
{
	int check = CheckForAcc(accToRemove);
	if (check != -1)
	{
		for (int i = check; i < this->currentNumberOfBankAccounts - 1; i++)
		{
			this->accountInfo[i] = this->accountInfo[i + 1];
		}
		currentNumberOfBankAccounts--;
		return true;
	}
	return false;
}

int BankClient::CheckWithIBAN(const char* searchIBAN)
{
	for (int i = 0; i < currentNumberOfBankAccounts; i++)
	{
		if (strcmp(this->accountInfo[i].getIBAN(), searchIBAN) == 0)
		{
			return i;
		}
	}
	return -1;
}

void BankClient::AddAmount(const char* IbanForAddAmount, double addAmount)
{
	int index = CheckWithIBAN(IbanForAddAmount);
	if (index != -1)
	{
		this->accountInfo[index].AddAmount(addAmount);
	}
}

double BankClient::SumOfAmount()
{
	double sum = 0;
	for (int i = 0; i < currentNumberOfBankAccounts; i++)
	{
		sum += this->accountInfo[i].getAmount();
	}
	return sum;
}

void BankClient::PrintClient()
{
	cout << this->firstName << endl;
	cout << this->lastName << endl;
	for (int i = 0; i < currentNumberOfBankAccounts; i++)
	{
		cout << this->accountInfo[i].getType() << endl;
		cout << this->accountInfo[i].getIBAN() << endl;
		cout << this->accountInfo[i].getAmount() << endl;
	}
}

void BankClient::operator=(BankClient& newClient)
{
	strcpy_s(firstName, 20, newClient.firstName);
	strcpy_s(lastName, 20, newClient.lastName);
	this->clientNumber = newClient.clientNumber;
};