#pragma once
#include <list>
#include <string>
#include "lexer.h"
#include "ast.h"
#include "performer.h"
#include "code.h"
#include "misk.h"
#include "node.h"
#include "treeoptimizer.h"
#include "windows.h"

using namespace std;

class Interpreter
{
private:
	VarDictionary* vd;
	ProcessDictionary* pd;
	list<string> trees;
	list<string> optTrees;
	Lexer* lexer = new Lexer();
	static Interpreter* i;
	bool optMode = false;
public:
		Interpreter( Lexer*);
		Interpreter();
		void interpret(const int&);
		static Interpreter* getInterpreter();
		void runInteractive();
		void runUsual(const string&);
		string reprTrees();
};
