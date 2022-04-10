#include "stdafx.h"
#include <iostream>
#include <string.h>
#include "BankClientH.h"
#include "AccountInfoH.h"
#include "BankH.h"
#include "Fibonacci.h"
#define SIZE 10
using namespace std;

int main()
{
	BankClient BankClient1 = *new BankClient("Ivan", "ASD",11);
	BankClient BankClient2 = *new BankClient("asd", "ASD", 22);
	BankClient BankClient3 = *new BankClient("dsa", "ASD", 33);
	AccountInfo accountInfo1 = *new AccountInfo("asd", "123123", 10);
	AccountInfo accountInfo2 = *new AccountInfo("dsa", "111", 19);
	AccountInfo accountInfo3 = *new AccountInfo("qwe", "1343", 18);
	BankH bank1 = *new BankH(1);
	BankClient1.AddAccount(accountInfo1);
	BankClient1.AddAccount(accountInfo2);
	BankClient1.AddAccount(accountInfo3);
	BankClient1.AddAmount("123123", 5);
	BankClient1.RemoveAccount(accountInfo1);
	BankClient1.PrintClient();
	bank1.AddClient(BankClient1);
	bank1.AddClient(BankClient2);
	bank1.AddClient(BankClient3);
	bank1.DeleteClient(11);
	return 0;
}