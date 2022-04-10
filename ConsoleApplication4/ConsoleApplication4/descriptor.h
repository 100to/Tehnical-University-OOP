#pragma once
#include "lexicalUnit.h"

class descriptor
{
	lexicalUnit table[100];
	int number;
public:
	descriptor();
	~descriptor();
	int add(lexicalUnit &lu);
	int del(char* pIdentificator);
	int search(char *pIdentificator);
	void printAll();
};

