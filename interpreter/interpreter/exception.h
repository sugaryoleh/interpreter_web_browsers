#pragma once
#include <string>
#include "code.h"
using namespace std;

class Exception : protected exception
{
private:
	string text = "";
public:
	Exception();
	Exception(const string&);
	virtual const string& _what() const;
};

