#include "toboolconverter.h"

namespace performers
{
	void toBoolConverter(Node* node)
	{
		if (node->token.type == "INT")
		{
			if (node->token.value == "0")
				node->token.value = "False";
			else
				node->token.value = "True";
			node->token.type == Lib::TYPES::BOOL;
			node->token.priority = Lib::VAR_prt;
		}
		else if (node->token.type == "STR")
		{
			if (node->token.value == "")
				node->token.value = "False";
			else
				node->token.value = "True";
			node->token.type == Lib::TYPES::BOOL;
			node->token.priority = Lib::VAR_prt;
		}
		else
		{
			cout << "Cannot convert type " << node->token.type << node->token.value << " to " << Lib::TYPES::BOOL << endl;
			exit(1);
		}
	}
}