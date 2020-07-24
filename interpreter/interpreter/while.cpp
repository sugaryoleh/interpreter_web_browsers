#include "while.h"

namespace performers
{
	namespace operators
	{

		int _while(Node* node)
		{

			if (node->rightChild != nullptr)
			{
				Node copy = Node(*node);
				performTree(copy.rightChild);
				if (copy.rightChild->token.type != Lib::TYPES::BOOL)
				{
					toBoolConverter(copy.rightChild);
				}
				int endPos = getPosOfEnd(Code::code, Code::pos);
				int position = Code::pos;
				VarDictionary* vd = VarDictionary::getVarDict();
				Interpreter* i = Interpreter::getInterpreter();

				while (true)
				{
					Code::pos = position + 1;
					i->interpret(endPos);
					Node copy(*node);
					performTree(copy.rightChild);
					if (copy.rightChild->token.type != Lib::TYPES::BOOL)
					{
						toBoolConverter(copy.rightChild);
					}
					if (copy.rightChild->token.value == "False") break;
				}
				return endPos;
			};
		}
	}
}