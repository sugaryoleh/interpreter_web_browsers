#include "comparisons.h"

namespace performers {
	namespace binop {
		namespace comparisons {

			void comparison(Node* node)
			{
				if ((node->leftChild->token.type == node->rightChild->token.type) && (node->leftChild->token.type == Lib::TYPES::INT || node->leftChild->token.type == Lib::TYPES::STR || (node->leftChild->token.type == Lib::TYPES::BOOL)))
				{
					string value = node->token.value;
					if (value == "<")
					{
						_less(node);
					}
					else if (value == ">")
					{
						_greater(node);
					}
					else if (value == "=")
					{
						equal(node);
					}
					else if (value == "<=")
					{
						lessOrEqual(node);
					}
					else if (value == ">=")
					{
						greaterOrEqual(node);
					}
				}
			}

			void _less(Node* node)
			{
				if (node->leftChild->token.type == Lib::TYPES::STR)
				{
					if (node->leftChild->token.value < node->rightChild->token.value)
					{
						node->token = Token("True", Lib::TYPES::BOOL, Lib::VAR_prt);
					}
					else
					{
						node->token = Token("False", Lib::TYPES::BOOL, Lib::VAR_prt);
					}
				}
				else
				{
					if (stoi(node->leftChild->token.value) < stoi(node->rightChild->token.value))
					{
						node->token = Token("True", Lib::TYPES::BOOL, Lib::VAR_prt);
					}
					else
					{
						node->token = Token("False", Lib::TYPES::BOOL, Lib::VAR_prt);
					}
				}
				delete node->leftChild;
				node->leftChild = nullptr;
				delete node->rightChild;
				node->rightChild = nullptr;
			}

			void _greater(Node* node)
			{
				if (node->leftChild->token.type == Lib::TYPES::STR)
				{
					if (node->leftChild->token.value > node->rightChild->token.value)
					{
						node->token = Token("True", Lib::TYPES::BOOL, Lib::VAR_prt);
					}
					else
					{
						node->token = Token("False", Lib::TYPES::BOOL, Lib::VAR_prt);
					}
				}
				else
				{
					if (stoi(node->leftChild->token.value) > stoi(node->rightChild->token.value))
					{
						node->token = Token("True", Lib::TYPES::BOOL, Lib::VAR_prt);
					}
					else
					{
						node->token = Token("False", Lib::TYPES::BOOL, Lib::VAR_prt);
					}
				}
				delete node->leftChild;
				node->leftChild = nullptr;
				delete node->rightChild;
				node->rightChild = nullptr;
			}

			void equal(Node* node)
			{
				if (node->leftChild->token.value == node->rightChild->token.value)
				{
					node->token = Token("True", Lib::TYPES::BOOL, Lib::VAR_prt);
				}
				else
				{
					node->token = Token("False", Lib::TYPES::BOOL, Lib::VAR_prt);
				}
				delete node->leftChild;
				node->leftChild = nullptr;
				delete node->rightChild;
				node->rightChild = nullptr;
			}

			void lessOrEqual(Node* node)
			{
				if (node->leftChild->token.type == Lib::TYPES::STR)
				{
					if (node->leftChild->token.value < node->rightChild->token.value || node->leftChild->token.value == node->rightChild->token.value)
					{
						node->token = Token("True", Lib::TYPES::BOOL, Lib::VAR_prt);
					}
					else
					{
						node->token = Token("False", Lib::TYPES::BOOL, Lib::VAR_prt);
					}
				}
				else
				{
					if (stoi(node->leftChild->token.value) < stoi(node->rightChild->token.value)|| stoi(node->leftChild->token.value) == stoi(node->rightChild->token.value))
					{
						node->token = Token("True", Lib::TYPES::BOOL, Lib::VAR_prt);
					}
					else
					{
						node->token = Token("False", Lib::TYPES::BOOL, Lib::VAR_prt);
					}
				}
				delete node->leftChild;
				node->leftChild = nullptr;
				delete node->rightChild;
				node->rightChild = nullptr;
			}

			void greaterOrEqual(Node* node)
			{
				if (node->leftChild->token.type == Lib::TYPES::STR)
				{
					if (node->leftChild->token.value > node->rightChild->token.value || node->leftChild->token.value == node->rightChild->token.value)
					{
						node->token = Token("True", Lib::TYPES::BOOL, Lib::VAR_prt);
					}
					else
					{
						node->token = Token("False", Lib::TYPES::BOOL, Lib::VAR_prt);
					}
				}
				else
				{
					if (stoi(node->leftChild->token.value) > stoi(node->rightChild->token.value) || stoi(node->leftChild->token.value) == stoi(node->rightChild->token.value))
					{
						node->token = Token("True", Lib::TYPES::BOOL, Lib::VAR_prt);
					}
					else
					{
						node->token = Token("False", Lib::TYPES::BOOL, Lib::VAR_prt);
					}
				}
				delete node->leftChild;
				node->leftChild = nullptr;
				delete node->rightChild;
				node->rightChild = nullptr;
			}
		}
	}
}