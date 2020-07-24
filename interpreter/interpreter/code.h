#pragma once
#include <list>
#include <string>
#include <fstream>
#include <iostream>
#include "exception.h"
using namespace std;

class Code
{
public:
	static list<string> code;
	static int pos;
	static void readCode(const string&);
};

