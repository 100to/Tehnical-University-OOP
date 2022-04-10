#pragma once
class AccountInfo {
	char typeOfBankAccount[20];
	double amountOfAccount;
	char IBAN[23];
public:
	char* getIBAN();
	double getAmount();
	char* getType();
	void AddAmount(double add);
	AccountInfo();
	AccountInfo(const char* typeOfBankAccount, const char* Iban, double ammount);
	void operator = (AccountInfo& otherAcc);
	bool operator == (AccountInfo& otherAcc);
};

