#pragma once
#include "Property.h"

class AgencyClass
{
	char name[30];
	Property* properties;
	int propertiesCount;
	int count;
public:
	AgencyClass();
	AgencyClass(const char* inputName, int inputPropertyCount);
	void AddProperty(Property newProperty);
	void DeleteProperty(const char* searchingAddress);
	Property* FindPropertyInPriceRange(double lowerPrice, double higherPrice);
	void PrintAll();
};

