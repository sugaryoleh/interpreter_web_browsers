#include "combinations.h"

namespace performers {
	namespace binop {
		namespace combinations {

			void combination(Node* node)
			{
				if (node->leftChild->token.type != Lib::TYPES::BOOL)
				{
					toBoolConverter(node->leftChild);
				}
				if (node->rightChild->token.type != Lib::TYPES::BOOL)
				{
					toBoolConverter(node->rightChild);
				}
				if (node->token.value == "|")
				{
					_or(node);
				}
				else if (node->token.value == "&")
				{
					_and(node);
				}
			}

			void _and(Node* node)
			{
				string val;
				if (node->rightChild->token.value == "True" && node->leftChild->token.value == "True")
				{
					val = "True";
				}
				else
				{
					val = "False";
				}
				node->token = Token(val, Lib::TYPES::BOOL, Lib::VAR_prt);
				node->eraseChildren();
			}

			void _or(Node* node)
			{
				string val;
				if (node->rightChild->token.value == "True" || node->leftChild->token.value == "True")
				{
					val = "True";
				}
				else
				{
					val = "False";
				}
				node->token = Token(val, Lib::TYPES::BOOL, Lib::VAR_prt);
				node->eraseChildren();
			}
		}
	}
}