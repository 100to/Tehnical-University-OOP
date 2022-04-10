#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "descriptor.h"
#include "lexicalUnit.h"
#include "DihotTable.h"
#include "HashTable.h"
#include "BinTree.h"
using namespace std;
int lexicalUnit::newAddress = 0;     
int lexicalUnit::newDescriptor = 1;


int _tmain(int argc, _TCHAR* argv[])
{
	fstream input;
	char temp1[100], temp2[100];
	lexicalUnit neshto;
	BinTree b = *new BinTree();
	input.open("input.txt", ios::in);
	while (input >> temp1 >> temp2)
	{
		neshto = *new lexicalUnit(temp2, temp1);
		b.insert(neshto);
	}
	b.print();
	return 0;
}

