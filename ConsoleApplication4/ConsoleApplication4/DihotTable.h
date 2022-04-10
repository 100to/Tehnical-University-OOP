#pragma once
#include "descriptor.h"
#include "lexicalUnit.h"
class DihotTable
{
	lexicalUnit table[100];
	int lexNumber;
public:
	DihotTable();
	int BinarySearch(const char* pIdentificator, int l, int r);
	int add(lexicalUnit& luAdd);
	int del(const char* pIdentificator);
	void printAll();
};

