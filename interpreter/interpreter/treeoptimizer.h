#pragma once
#pragma once
#include <list>
#include "patterngenerators.h"
#include "optimizergenerators.h"
#include "varconverter.h"

using namespace std;

typedef void(*optimizer)(Node*);

class TreeOptimizer
{
private:
	static TreeOptimizer* treeOpt;
	list<pair<AST, optimizer>> optPatterns;
	TreeOptimizer();
public:
	static TreeOptimizer* getOptimizer();
	void optimize(Node*);
};


