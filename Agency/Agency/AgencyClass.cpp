#include "AgencyClass.h"
#include <string.h>

AgencyClass::AgencyClass()
{
	strcpy_s(name, "empty");
	count = 1;
	propertiesCount = 0;
	properties = new Property[count];
}

AgencyClass::AgencyClass(const char* inputName, int inputPropertyCount)
{
	strcpy_s(name, inputName);
	count = inputPropertyCount;
	properties = new Property[count];
}

void AgencyClass::AddProperty(Property newProperty)
{
	if (propertiesCount == count)
	{
		count *= 2;
		Property* temp = new Property[count];
		for (int i = 0; i < propertiesCount; i++)
		{
			temp[i] = properties[i];
		}
		delete[] properties;
		properties = temp;
	}
	properties[propertiesCount] = newProperty;
	propertiesCount++;
}

void AgencyClass::DeleteProperty(const char* searchingAddress)
{
	for (int i = 0; i < propertiesCount; i++)
	{
		if (strcmp(properties[i].GetAddress(), searchingAddress)==0)
		{
			for (int j = i; j < propertiesCount-1; j++)
			{
				properties[j] = properties[j + 1];
			}
			propertiesCount--;
			break;
		}
	}
}

Property* AgencyClass::FindPropertyInPriceRange(double lowerPrice, double higherPrice)
{
	for (int i = 0; i < propertiesCount; i++)
	{
		if (properties[i].GetPrice() >= lowerPrice && properties[i].GetPrice() <= higherPrice)
		{
			return &properties[i];
		}
	}
	return NULL;
}

void AgencyClass::PrintAll()
{
	for (int i = 0; i < propertiesCount; i++)
	{
		properties[i].Print();
	}
}
