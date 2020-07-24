#include "code.h"

int Code::pos = 0;
list<string> Code::code;

void Code::readCode(const string& name)
{
	ifstream file;
	file.open(name);
	if (!file.is_open())
		throw Exception("Cannot read source code file '" + name + "'");
	string str;
	Code::pos = 0;
	while (getline(file, str))
	{
		Code::code.push_back(str);
	}
}
