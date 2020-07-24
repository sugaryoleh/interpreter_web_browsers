#include "varconverter.h"

namespace performers
{
	void varConverter(Node* node)
	{
		*node = VarDictionary::getVarDict()->get(node->token.value);
	}
}