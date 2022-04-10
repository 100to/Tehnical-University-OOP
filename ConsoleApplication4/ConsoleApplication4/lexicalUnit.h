#pragma once
class lexicalUnit
{
	char identificator[20];
	char type[20];
	char descriptor[5];
	int address;
	void setAddress(char *type);
	void setDescriptor();
public:
	static int newAddress;
	static int newDescriptor;
	lexicalUnit();
	lexicalUnit(const char* _identificator, const char* _type);
	lexicalUnit& operator=(lexicalUnit& lu);
	~lexicalUnit();
	char* getIdetificator();
	void print();
};

