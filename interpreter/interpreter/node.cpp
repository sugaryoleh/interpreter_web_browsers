#include "node.h"

Node::Node(const Token & tok)
{
	this->token = tok;
	this->leftChild = nullptr;
	this->rightChild = nullptr;
}

Node::Node(const Node& node)
{
	this->token = node.token;
	if (node.rightChild != nullptr)
		this->rightChild = new Node(*node.rightChild);
	if (node.leftChild != nullptr)
	this->leftChild = new Node(*node.leftChild);
}

void Node::addLeftChild(Node*l)
{
	this->leftChild = l;
}

void Node::addRightChild(Node* r)
{
	this->rightChild = r;
}

void Node::addChildren(Node* l , Node*r)
{
	this->leftChild = l;
	this->rightChild = r;
}

string Node::repr(const Node& node)
{
	return Token::repr(node.token);
}

Node& Node::operator=(const Node* node)
{
	this->token = node->token;
	this->leftChild = new Node(*node->leftChild);
	this->rightChild = new Node(*node->rightChild);
	return *this;
}

void Node::erase()
{
	if (this->leftChild != nullptr) this->leftChild->erase();
	if (this->rightChild != nullptr) this->rightChild->erase();
	delete this;
}

void Node::eraseChildren()
{
	if (this->leftChild != nullptr) this->leftChild->erase();
	if (this->rightChild != nullptr) this->rightChild->erase();
	this->leftChild = nullptr;
	this->rightChild = nullptr;
}

ostream& operator<<(ostream& out, const Node&node)
{
	out <<  node.token;
	return out;
}

bool operator==(const Node& l, const Node& r)
{
	if (&l != &r && &l != nullptr && &r!= nullptr) {
		if (l.token == r.token) return true;
			//&&l.leftChild->token == r.leftChild->token &&
			//l.rightChild->token == r.rightChild->token) return true;
		return false;
	}
	else return true;
}

bool operator!=(const Node& l, const Node& r)
{
	if (l.token == r.token ||
		l.leftChild->token == r.leftChild->token ||
		l.rightChild->token == r.rightChild->token) return true;
	else return false;
}


