#pragma once
#include "token.h"
#include <iostream>
class Node
{
public:
	Token token;
	Node *leftChild;
	Node *rightChild;
	Node(const Token&);
	Node(const Node&);
	void addLeftChild(Node *);
	void addRightChild(Node*);
	void addChildren(Node*, Node*);
	static string repr(const Node&);
	friend ostream& operator << (ostream& out, const Node &);
	Node& operator = (const Node*);
	friend bool operator == (const Node&, const Node&);
	friend bool operator != (const Node&, const Node&);
	void erase();
	void eraseChildren();
};

