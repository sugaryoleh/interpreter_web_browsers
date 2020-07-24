#pragma once
#include <list>
#include <map>
#include "token.h"
#include "lexer.h"
// AST
int getNext(const int*, const int&);
int* getPriorities(const list<Token>&);
list<string> getSlice(list<string>, const int&, const int&);
list<Token> getSlice(list<Token>, const int&, const int&);
ostream& operator << (ostream&, const list<Token>&);
//parsers

bool ifIn(const char*, const char&, const int&);

//if and while

int getPosOfEnd(const list<string>&, const int&);
int getPosOfElse(const list<string>&, const int&);

