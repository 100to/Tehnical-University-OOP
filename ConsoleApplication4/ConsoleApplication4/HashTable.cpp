#include "stdafx.h"
#include "HashTable.h"
#include <iostream>
using namespace std;



HashTable::HashTable()
{
	for (int i = 0; i < 127; i++)
	{
		table[i] = *new lexicalUnit("empty", "empty");
	}
}

int HashTable::HeshFunction(const char* pIdentificator)
{
	int sum = 0;
	for (int i = 0; pIdentificator[i] != '\0'; i++)
	{
		sum += pIdentificator[i];
	}
	return sum & 123;
}

int HashTable::search(const char* pIdentificator)
{
	int i = HeshFunction(pIdentificator) + 1;
	while (i != HeshFunction(pIdentificator))
	{
		if (strcmp(pIdentificator, table[i].getIdetificator())==0)
		{
			return -i;
		}
		else if (i == 127)
		{
			i = 0;
		}
		else if (strcmp(table[i].getIdetificator(), "empty") == 0)
		{
			return i;
		}
		i++;
	}
	return i;
}

int HashTable::add(lexicalUnit& luAdd)
{
	int i = search(luAdd.getIdetificator());
	int j=0;
	if (i < 0)
	{
		while (j != i)
		{
			j = i + 1;
			if (j == 127)
			{
				j = 0;
			}
			else if (strcmp(table[j].getIdetificator(), "empty") == 0)
			{
				table[j] = luAdd;
			}
		}
	}
	else
	{
		table[i] = luAdd;
	}
	return 0;
}

int HashTable::del(const char* pIdentificator)
{
	int i = search(pIdentificator);
	if (i < 0)
	{
		i *= -1;
		table[i] = *new lexicalUnit("empty", "empty");;
	}
	return 0;
}

void HashTable::printAll()
{
	for (int i = 0; i < 127; i++)
	{
		if (strcmp(table[i].getIdetificator(), "empty") != 0)
		{
			table[i].print();
		}
	}
}
