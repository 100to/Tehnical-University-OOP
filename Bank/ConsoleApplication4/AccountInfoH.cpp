#include "stdafx.h"
#include "AccountInfoH.h"
#include <string.h>
using namespace std;

char* AccountInfo::getIBAN()
{
	return this->IBAN;
}

double AccountInfo::getAmount()
{
	return this->amountOfAccount;
}

char* AccountInfo::getType()
{
	return this->typeOfBankAccount;
}

void AccountInfo::AddAmount(double add)
{
	this->amountOfAccount += add;
}

AccountInfo::AccountInfo()
{
	strcpy_s(this->typeOfBankAccount, 20, "empty");
	strcpy_s(this->IBAN, 23, "empty");
	this->amountOfAccount = 0;
}

AccountInfo::AccountInfo(const char* typeOfBankAccount, const char* Iban, double amount)
{
	strcpy_s(this->typeOfBankAccount, 20, typeOfBankAccount);
	strcpy_s(this->IBAN, 23, Iban);
	this->amountOfAccount = amount;
}
void AccountInfo::operator=(AccountInfo& otherAcc)
{
	strcpy_s(this->typeOfBankAccount, 20, otherAcc.typeOfBankAccount);
	strcpy_s(this->IBAN, 23, otherAcc.IBAN);
	this->amountOfAccount = otherAcc.amountOfAccount;
};

bool AccountInfo::operator==(AccountInfo& otherAcc)
{
	if (strcmp(this->typeOfBankAccount, otherAcc.typeOfBankAccount) == 0)
	{
		if (strcmp(this->IBAN, otherAcc.IBAN) == 0)
		{
			return this->amountOfAccount == otherAcc.amountOfAccount;
		}
	}
	return false;
};