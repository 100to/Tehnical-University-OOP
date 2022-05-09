#include <iostream>
#include "AgencyClass.h"
#include "Property.h"
using namespace std;

int main()
{
    AgencyClass* arrayOfProperties = new AgencyClass("imot",3);
    arrayOfProperties->AddProperty(*new House(2, 1, 10, "Botev", "Ivan", 100, 11));
    arrayOfProperties->AddProperty(*new Apartament(3, 2, "Vazov", "Georgi", 200, 20));
    arrayOfProperties->AddProperty(*new Apartament(1, 1, "Georgiev", "Mitko", 50, 22));
    arrayOfProperties->AddProperty(*new Plot(true,false,true,"Smirnenski","Dimitar",220,50));
    arrayOfProperties->DeleteProperty("Botev");
    arrayOfProperties->PrintAll();
}
