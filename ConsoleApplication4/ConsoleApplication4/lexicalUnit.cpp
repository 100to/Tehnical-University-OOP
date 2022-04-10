#include "stdafx.h"
#include "lexicalUnit.h"
#include <iostream>
using namespace std;

lexicalUnit::lexicalUnit()
{
	strcpy_s(identificator, 20, "empty");
	strcpy_s(type, 20, "empty");
	strcpy_s(descriptor, 5, "null");
	address = 0;
}

lexicalUnit::lexicalUnit(const char* _identificator, const char* _type)
{
	strcpy_s(identificator, 20, _identificator);
	strcpy_s(type, 20, _type);
	setAddress(type);
	setDescriptor();
}

void lexicalUnit::setAddress(char *type)
{
	address = newAddress;
	int size = 0;
	if (strcmp(type, "int")==0)
	{
		size = 2;
	}
	else if (strcmp(type, "char") == 0)
	{
		size = 1;
	}
	else if (strcmp(type, "float") == 0)
	{
		size = 4;
	}
	else if (strcmp(type, "double") == 0)
	{
		size = 8;
	}
	newAddress += size;
}

void lexicalUnit::setDescriptor()
{
	sprintf_s(descriptor, "V%d", newDescriptor);
	newDescriptor++;
}

lexicalUnit& lexicalUnit::operator=(lexicalUnit& lu)
{
	strcpy_s(identificator, 20, lu.identificator);
	strcpy_s(type, 20, lu.type);
	strcpy_s(descriptor, 5, lu.descriptor);
	address = lu.address;
	return lu;
}

char* lexicalUnit::getIdetificator()
{
	return identificator;
}

void lexicalUnit::print()
{
	cout << identificator << " " << type << " " << descriptor << " " << address << endl;
}

lexicalUnit::~lexicalUnit()
{

}
