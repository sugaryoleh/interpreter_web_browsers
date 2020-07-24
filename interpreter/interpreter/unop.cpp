#include "unop.h"

namespace performers
{
	namespace unop
	{
		void unOp(Node* node)
		{
			if (node->token.value == "-")
			{
				performers::unop::unaryMinus(node);
			}
			else if (node->token.value == "!")
			{
				performers::unop::_not(node);
			}
			else if (node->token.value == "delete")
			{
				performers::unop::_delete(node);
			}
			else if (node->token.value == "run")
			{
				performers::unop::run(node);
			}
			else if (node->token.value == "quit")
			{
				performers::unop::qiut(node);
			}
			//else throw Exception("undefined unary operation '" + node->token.value + "'");
		}

		void unaryMinus(Node* node)
		{
			if (node->rightChild != nullptr)
			{
				if (node->rightChild->token.type == Lib::TYPES::INT)
				{
					node->token = Token("-" + node->rightChild->token.value, Lib::TYPES::INT, Lib::VAR_prt);
					node->eraseChildren();
				}
				else
				{
					throw Exception("Unary '-' cannot be used to type '" + node->rightChild->token.type + "'");
				}
			}
		}

		void _not(Node* node)
		{
			if (node->rightChild != nullptr)
			{
				if (node->rightChild->token.type == Lib::TYPES::INT || node->rightChild->token.type == Lib::TYPES::STR)
				{
					toBoolConverter(node->rightChild);
				}
				if (node->rightChild->token.type == Lib::TYPES::BOOL) {
					if (node->rightChild->token.value == "False")
					{
						node->token = Token("True", Lib::TYPES::BOOL, Lib::VAR_prt);
					}
					else if (node->rightChild->token.value == "True")
					{
						node->token = Token("False", Lib::TYPES::BOOL, Lib::VAR_prt);
					}
					node->eraseChildren();

				}
				else
				{
					throw Exception("Unary '!' cannot be used to type '" + node->rightChild->token.type + "'");
				}

			}
		}

		void _delete(Node* node)
		{
			if (node->rightChild != nullptr)
			{
				if (node->rightChild->token.type == Lib::TYPES::BROWSER)
				{
					ProcessDictionary::getProcessDict()->_delete(node->rightChild->token.value);
				}
				VarDictionary::getVarDict()->_delete(node->rightChild->token.value);
				
			}
			else
			{
				throw Exception("'delete' cannot be used to type '" + node->rightChild->token.type + "'");

			}
		}
	}
}