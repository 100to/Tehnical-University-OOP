#include "stdafx.h"
#include "Fibonacci.h"

Fibonacci::Fibonacci()
{
	f1 = 1;
	f2 = 1;
}

int Fibonacci::Get()
{
	int temp = f1;
	f1 = f2;
	f2 = temp + f1;
	return f2;
}

int Fibonacci::Set(int number)
{
	while (number>=f1)
	{
		Get();
	}
	return f2;
}
