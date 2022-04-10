#include "stdafx.h"
#include "DihotTable.h"

DihotTable::DihotTable()
{
	lexNumber = 0;
}

int DihotTable::BinarySearch(const char* pIdentificator, int l, int r)
{
	if (l==r)
	{
		return -r;
	}
	int m = (l + r) / 2;
	if (strcmp(table[m].getIdetificator(), pIdentificator)==0)
	{
		return m;
	}
	if (strcmp(table[m].getIdetificator(), pIdentificator) > 0)
	{
		if (r==-1)
		{
			return m;
		}
		return BinarySearch(pIdentificator, l, m-1);
	}
	else if (strcmp(table[m].getIdetificator(), pIdentificator) < 0)
	{
		return BinarySearch(pIdentificator, m+1, r);
	}
	return 101;
}

int DihotTable::add(lexicalUnit& luAdd)
{
	if (lexNumber==100)
	{
		return 0;
	}
	int i = BinarySearch(luAdd.getIdetificator(), 0, lexNumber);
	if (i==101)
	{
		return 0;
	}
	else if (i<0 && i*-1==lexNumber)
	{
		table[lexNumber] = luAdd;
	}
	else
	{
		if (i<0)
		{
			i *= -1;
		}
		for (int j = lexNumber-1; j >= i; j--)
		{
			table[j+1] = table[j];
		}
		table[i] = luAdd;
	}
	lexNumber++;
	return 1;
}

int DihotTable::del(const char* pIdentificator)
{
	for (int i = 0; i < lexNumber; i++)
	{
		if (strcmp(table[i].getIdetificator(),pIdentificator)==0)
		{
			for (int j = i; j < lexNumber; j++)
			{
				table[j] = table[j + 1];
			}
			lexNumber--;
			return 1;
		}
	}
	return 0;
}

void DihotTable::printAll()
{
	for (int i = 0; i < lexNumber; i++)
	{
		table[i].print();
	}
}
