#pragma once
#include "node.h"
#include  "misk.h"
#include "varconverter.h"
using namespace std;

class AST
{
private:
	Node* buildTree(const list<Token>&);
	static string _repr(Node*, int);
	static void countDetour(const Node&, int&);
	static Node* copyDetour(const Node*);
	static void deepEqDetour(const Node*, const Node*, bool&);
	static void nodeEqDetour(const Node&, const Node&, bool&);
	static void nodeTypeEqDetour(const Node&, const Node&, bool&);
public:
	string repr();
	AST(const list<Token>&);
	AST(const AST&);
	AST(const Node*);
	Node* mainNode;
	AST& operator = (const AST&);
	friend ostream& operator << (ostream&, const AST&);
	friend bool operator == (const AST&, const AST&);
	friend int size(const AST&);
	friend bool deepEquality(const AST&, const AST&);
	friend bool nodeEquality(const AST&, const AST&);
	friend bool nodeTypeEquality(const AST&, const AST&);
	friend bool operator == (const AST&, const AST&);
	friend bool operator < (const AST&, const AST&);
	~AST();
};

