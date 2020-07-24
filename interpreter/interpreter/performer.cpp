#include "performer.h"

namespace performers
{

	int perform(Node* node)
	{
		if (node->token.value == "if")
		{
			return performers::operators::_if(node);
		}
		else if (node->token.value == "while")
		{
			return performers::operators::_while(node);
		}
		else if (node->token.value == "help" && node->rightChild == nullptr && node->leftChild == nullptr)
		{
			ifstream fin("manual.txt");
			string line;
			while (!fin.eof())
			{
				getline(fin, line);
				cout << line << endl;
			}
			fin.close();
		}
		else
		{
			performers::performTree(node);
			return Code::pos + 1;
		}

	}

	void performTree(Node* node)
	{
		bool rflag = 0, lflag = 0;
		if (node->leftChild != nullptr)
		{
			performTree(node->leftChild);
			lflag = 1;
		}
		if (node->rightChild != nullptr)
		{
			performTree(node->rightChild);
			rflag = 1;
		}
		if (lflag && rflag)
		{
			binop::binOp(node);
		}
		else if (lflag || rflag)
		{
			unop::unOp(node);
		}
	
	}
}