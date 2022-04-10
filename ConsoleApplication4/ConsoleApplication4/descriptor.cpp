#include "stdafx.h"
#include "descriptor.h"


descriptor::descriptor()
{
	number = 0;
}

int descriptor::add(lexicalUnit& lu)
{
	table[number] = lu;
	number++;
	return 1;
}

int descriptor::del(char* pIdentificator)
{
	int i = search(pIdentificator);
	if (i != -1)
	{
		for (int j = i; j < number - 1; j++)
		{
			table[j] = table[j + 1];
		}
		number--;
		return 1;
	}
	return 0;
}

int descriptor::search(char* pIdentificator)
{
	for (int i = 0; i < number; i++)
	{
		if (strcmp(table[i].getIdetificator(), pIdentificator)==0)
		{
			return i;
		}
	}
	return -1;
}

void descriptor::printAll()
{
	for (int i = 0; i < number; i++)
	{
		table[i].print();
	}
}

descriptor::~descriptor()
{
}
