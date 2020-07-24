#pragma once
#include <string>
#include <iostream>
using namespace std;


class Token
{
public:
	string value;
	string type;
	int priority;
	Token() {};
	Token(const string&, const string&, const int&);
	static string repr(const Token&);
	friend ostream & operator << (ostream& out, const Token& tok);
	Token operator = (const Token&);
	friend bool operator == (const Token& l, const Token& r);
	friend bool operator != (const Token& l, const Token& r);
	friend bool notStrongEqulaity(const Token& l, const Token& r);
};

