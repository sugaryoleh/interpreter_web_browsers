#include "assign.h"

namespace performers {
	namespace binop {

		void assign(Node* node)
		{
			if (node->leftChild->token.type == Lib::TYPES::ID)
			{
				VarDictionary* vd = VarDictionary::getVarDict();
				string type = node->rightChild->token.type;
				if (type == Lib::TYPES::ID)
				{
					varConverter(node->rightChild);
					type = node->rightChild->token.type;
				}
				if (type == Lib::TYPES::INT || type == Lib::TYPES::STR || type == Lib::TYPES::BOOL)
				{
					vd->push(node->leftChild->token.value, node->rightChild->token);
					node->token = node->rightChild->token;
					node->eraseChildren();

				}
				else if (type == Lib::TYPES::BROWSER)
				{
					cout << "browser" << endl;
					vd->push(node->leftChild->token.value, node->rightChild->token);
				}
				else
				{
					throw Exception("cannot assign right value with type " + node->rightChild->token.type);
				}
			}
			else
			{
				throw Exception("cannot assign to left value with type " + node->leftChild->token.type);
			}
		}
	}
}