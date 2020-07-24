#include "if.h"

namespace performers
{
	namespace operators
	{

		int _if(Node* node)
		{
			if (node->rightChild != nullptr)
			{
				performers::performTree(node->rightChild);
				if (node->rightChild->token.type != Lib::TYPES::BOOL)
				{
					toBoolConverter(node->rightChild);
				}
				int endPos = getPosOfEnd(Code::code, Code::pos);
				int elsePos = getPosOfElse(Code::code, Code::pos);
				Interpreter* i = Interpreter::getInterpreter();

				if (node->rightChild->token.value == "False")
				{
					if (elsePos != -1)
					{
						Code::pos = elsePos + 1;
						i->interpret(endPos);
					}
					return endPos;
				}
				else if (node->rightChild->token.value == "True")
				{
					if (elsePos != -1)
					{
						Code::pos += 1;
						i->interpret(elsePos);
					}
					else
					{
						Code::pos += 1;
						i->interpret(endPos);
					}
					return endPos;
				}
			}
			else
			{
				throw Exception("If condition must be '" + Lib::TYPES::BOOL + "' type\n");				
			}
			return 0;
		}
	}
}

