#include "ast.h"


Node* AST::buildTree(const list<Token>& tokens)
{
	int size = tokens.size();
	int* priorities = getPriorities(tokens);
	int pos = getNext(priorities, size);
	auto it = tokens.begin();
	advance(it, pos);
	Node* currentNode = new Node(*it);
	if (getSlice(tokens, 0, pos).size() != 0)
	{
		currentNode->addLeftChild(this->buildTree(getSlice(tokens, 0, pos)));
	}
	if (getSlice(tokens, pos + 1, size).size() != 0)
	{
		currentNode->addRightChild(this->buildTree(getSlice(tokens, pos + 1, size)));
	}
	return currentNode;
}

string AST::_repr(Node* node, int deepness) 
{
	if (node != nullptr) {
		string space;
		for (int i = 0; i < deepness; i++) space += "-";
		string currentLevel = space + Node::repr(*node) + "\n";
		deepness += 3;
		string children = "";
		if (node->leftChild != nullptr)
			children += AST::_repr(node->leftChild, deepness);
		if (node->rightChild != nullptr)
			children += AST::_repr(node->rightChild, deepness);
		return currentLevel + children;
	}
	else return "";
}

void AST::countDetour(const Node& node, int& c)
{
	c++;
	if (node.leftChild != nullptr) AST::countDetour(*node.leftChild, c);
	if (node.rightChild != nullptr) AST::countDetour(*node.rightChild, c);
}

string AST::repr()
{
	return AST::_repr(this->mainNode, 0);
}

AST::AST(const list<Token>& tokens)
{
	this->mainNode = this->buildTree(tokens);
}

AST::AST(const AST& ast)
{
	this->mainNode = copyDetour(ast.mainNode);
}

AST::AST(const Node* node)
{
	this->mainNode = this->copyDetour(node);
}

Node* AST::copyDetour(const Node* node)
{
	Node* newNode = nullptr;
	if (node != nullptr)
	{
		newNode = new Node(*node);
		newNode->leftChild = copyDetour(node->leftChild);
		newNode->rightChild = copyDetour(node->rightChild);
	}
	return newNode;
}

AST& AST::operator=(const AST& ast)
{
	this->mainNode = copyDetour(ast.mainNode);
	return *this;
}

AST::~AST()
{
	this->mainNode->erase();
}

ostream& operator<<(ostream& out, const AST& tree)
{
	out << AST::_repr(tree.mainNode, 3);
	return out;
}

void AST::deepEqDetour(const Node* l, const Node* r, bool& f)
{
		if (l == r)
		{
			AST::deepEqDetour(l->leftChild, r->leftChild, f);
			AST::deepEqDetour(l->rightChild, r->rightChild, f);
		}
		else f = false;
}

void AST::nodeEqDetour(const Node& l, const Node& r, bool &f)
{
	if (&l != &r) {
		if (l==r && &l != nullptr && &r != nullptr)
		{
			AST::nodeEqDetour(*l.leftChild, *r.leftChild, f);
			AST::nodeEqDetour(*l.rightChild, *r.rightChild, f);
		}
		else f = false;
	}
}



void AST::nodeTypeEqDetour(const Node& l, const Node& r, bool& f)
{
	if (&l != &r) {
		if (&l != nullptr && &r != nullptr && l.token.type == r.token.type)
		{
			nodeTypeEqDetour(*l.leftChild, *r.leftChild, f);
			nodeTypeEqDetour(*l.rightChild, *r.rightChild, f);
		}
		else f = false;
	}
}

bool operator==(const AST& l, const AST& r)
{
	bool f = true;
	AST::nodeEqDetour(*l.mainNode, *r.mainNode, f);
	return f;
}

int size(const AST& tree)
{
	int s = 0;
	AST::countDetour(*tree.mainNode, s);
	return s;
}

bool operator<(const AST& l, const AST& r)
{
	if (size(l) < size(r)) return true;
	else return false;
}

bool deepEquality(const AST& l, const AST& r)
{
	bool f = 1;
	AST::deepEqDetour(l.mainNode, r.mainNode, f);
	return f;
}

bool nodeEquality(const AST& l, const AST& r)
{
	bool f = 1;
	AST::nodeEqDetour(*l.mainNode, *r.mainNode, f);
	return f;
}



bool nodeTypeEquality(const AST& l, const AST& r)
{
	bool f = 1;
	AST::nodeTypeEqDetour(*l.mainNode, *r.mainNode, f);
	return f;
}






