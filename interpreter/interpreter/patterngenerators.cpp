#include "patterngenerators.h"

const AST& int_int_pattern()
{
	Node* head = new Node(Token("", Lib::TYPES::RESERVED, Lib::MUL_DIV_prt));
	head->leftChild = new Node(Token("", Lib::TYPES::INT, Lib::VAR_prt));
	head->rightChild = new Node(Token("", Lib::TYPES::INT, Lib::VAR_prt));
	AST* tree = new AST(head);
	return *tree;
}

const AST& out_of_breaks_pattern()
{
	Node *head = new Node(Token("", Lib::TYPES::RESERVED, Lib::PLUS_MINUS_prt));
	head->leftChild = new Node(Token("", Lib::TYPES::RESERVED, Lib::MUL_DIV_prt));
	head->rightChild = new Node(Token("", Lib::TYPES::RESERVED, Lib::MUL_DIV_prt));
	head->rightChild->rightChild = new Node(Token("", Lib::TYPES::INT, Lib::VAR_prt));
	head->rightChild->leftChild = new Node(Token("", Lib::TYPES::INT, Lib::VAR_prt));
	head->leftChild->rightChild = new Node(Token("", Lib::TYPES::INT, Lib::VAR_prt));
	head->leftChild->leftChild = new Node(Token("", Lib::TYPES::INT, Lib::VAR_prt));
	AST* tree = new AST(head);
	return *tree;
}

const AST& empty_string_pattern()
{
	Node* head = new Node(Token("", Lib::TYPES::RESERVED, Lib::PLUS_MINUS_prt));
	head->leftChild = new Node(Token("", Lib::TYPES::STR, Lib::VAR_prt));
	head->rightChild = new Node(Token("", Lib::TYPES::STR, Lib::VAR_prt));
	AST* tree = new AST(head);
	return *tree;
}

const AST& empty_string_pattern_i()
{
	Node* head = new Node(Token("", Lib::TYPES::RESERVED, Lib::PLUS_MINUS_prt));
	head->leftChild = new Node(Token("", Lib::TYPES::STR, Lib::VAR_prt));
	head->rightChild = new Node(Token("", Lib::TYPES::INT, Lib::VAR_prt));
	AST* tree = new AST(head);
	return *tree;
}

const AST& condition_pattern()
{
	Node* head = new Node(Token("", Lib::TYPES::RESERVED, 0));
	head->leftChild = new Node(Token("", Lib::TYPES::RESERVED, 0));
	head->rightChild = new Node(Token("", Lib::TYPES::RESERVED, 0));
	head->rightChild->rightChild = new Node(Token("", Lib::TYPES::INT, Lib::VAR_prt));
	head->rightChild->leftChild = new Node(Token("", Lib::TYPES::INT, Lib::VAR_prt));
	head->leftChild->rightChild = new Node(Token("", Lib::TYPES::INT, Lib::VAR_prt));
	head->leftChild->leftChild = new Node(Token("", Lib::TYPES::INT, Lib::VAR_prt));
	AST* tree = new AST(head);
	return *tree;
}