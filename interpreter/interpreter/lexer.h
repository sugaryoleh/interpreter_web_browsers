#pragma once
#include <string>
#include <list>
#include <regex>
#include "lib.h"
#include "token.h"
#include "exception.h"
using namespace std;

class Lexer
{
	list<Token> exprs;
public:
	Lexer(list<Token>);
	Lexer();
	list<Token> lex(const string &);
};

