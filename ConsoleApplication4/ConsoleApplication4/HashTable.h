#pragma once
#include "lexicalUnit.h"
class HashTable
{
	lexicalUnit table[127];
public:
	HashTable();
	int HeshFunction(const char* pIdentificator);
	int search(const char* pIdentificator);
	int add(lexicalUnit& luAdd);
	int del(const char* pIdentificator);
	void printAll();
};

