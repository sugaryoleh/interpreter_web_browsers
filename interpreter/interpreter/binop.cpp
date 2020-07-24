#include "binop.h"

namespace performers
{
	namespace binop
	{
		void binOp(Node* node)
		{
			string val = node->token.value;
			if (val == ":=")
			{
				assign(node);
			}
			else if (val == "open")
			{
				performers::binop::open(node);
			}
			else if (val == "click")
			{
				performers::binop::click(node);
			}
			else if (val == "clear")
			{
				performers::binop::clear(node);
			}
			else if (val == "input")
			{
				performers::binop::input(node);
			}
			else {
				if (node->leftChild->token.type == Lib::TYPES::ID)
				{
					performers::varConverter(node->leftChild);
				}
				if (node->rightChild->token.type == Lib::TYPES::ID)
				{
					performers::varConverter(node->rightChild);
				}
				if (ifIn(Lib::Operations::arithmetics + 1, *(val.c_str()), atoi(Lib::Operations::arithmetics)))
				{
					performers::binop::arithmetics::arithmetic(node);
				}
				else if (ifIn(Lib::Operations::comparisons + 1, *(val.c_str()), atoi(Lib::Operations::comparisons)))
				{
					performers::binop::comparisons::comparison(node);
				}
				else if (ifIn(Lib::Operations::combinations + 1, *(val.c_str()), atoi(Lib::Operations::combinations)))
				{
					performers::binop::combinations::combination(node);
				}
				else
				{
					throw Exception("cannot perform operation '" + val + "'");
				}
			}
		}
	}
}