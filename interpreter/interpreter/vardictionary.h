#pragma once
#include <map>
#include <string>
#include <iostream>
#include "token.h"
#include "exception.h"
using namespace std;
class VarDictionary
{
private:
	map<string, Token> vars;
	static VarDictionary* vd;
public:
	static VarDictionary* getVarDict();
	void push(const string &, const Token&);
	Token& get(const string&);
	const map<string, Token>& getVars();
	string repr();
	Token operator[](const string&) const;
	void _delete(const string&);
};

