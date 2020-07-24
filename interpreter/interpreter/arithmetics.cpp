#include "arithmetics.h"

namespace performers {
	namespace binop {

		namespace arithmetics
		{

			void arithmetic(Node* node)
			{
				string val = node->token.value;
				if (val == "+")
				{
					_plus(node);
				}
				else if (val == "-")
				{
					_minus(node);
				}
				else if (val == "*")
				{
					multiply(node);
				}
				else if (val == "/")
				{
					cout << "/" << endl;
					divide(node);
				}
				else throw Exception("no operation '" + val + "' ");
			}

			void _plus(Node* node)
			{
				if (node->leftChild->token.type == Lib::TYPES::INT && node->rightChild->token.type == Lib::TYPES::INT)
				{
					add(node);
				}
				else if (node->leftChild->token.type == Lib::TYPES::STR && node->rightChild->token.type == Lib::TYPES::STR)
				{
					concat(node);
				}
				else if (node->leftChild->token.type == Lib::TYPES::STR && node->rightChild->token.type == Lib::TYPES::INT)
				{
					node->rightChild->token.type = Lib::TYPES::STR;
					concat(node);
				}
				else
				{
					throw Exception("cannot use '+' for '" + node->leftChild->token.type + "' and " + node->rightChild->token.type + "'");
				}
			}

			void add(Node* node)
			{
				node->token = Token(to_string(stoi(node->leftChild->token.value) + stoi(node->rightChild->token.value)), node->leftChild->token.type, node->leftChild->token.priority);
				node->eraseChildren();
			}

			void concat(Node* node)
			{
				node->token.value = node->leftChild->token.value + node->rightChild->token.value;
				node->token.type = Lib::TYPES::STR;
				node->token.priority = Lib::VAR_prt;
				node->eraseChildren();
			}

			void _minus(Node* node)
			{
				node->token = Token(to_string(stoi(node->leftChild->token.value) - stoi(node->rightChild->token.value)), node->leftChild->token.type, node->leftChild->token.priority);
				cout << node->token.value << endl;
				node->eraseChildren();
			}

			void multiply(Node* node)
			{
				node->token = Token(to_string(stoi(node->leftChild->token.value) * stoi(node->rightChild->token.value)), node->leftChild->token.type, node->leftChild->token.priority);
				node->eraseChildren();
			}

			void divide(Node* node)
			{
				node->token = Token(to_string(stoi(node->leftChild->token.value) / stoi(node->rightChild->token.value)), node->leftChild->token.type, node->leftChild->token.priority);
				node->eraseChildren();
			}
		}
	}
}