#include "optimizergenerators.h"

void int_int_optimizer(Node* head)
{
 	if (head->token.value == "*" || head->token.value == "/") {
		//minus [/][*] minus
		if (head->leftChild->token.value[0] == '-' && head->rightChild->token.value[0] == '-')
		{
			head->leftChild->token.value = head->leftChild->token.value.substr(1, head->leftChild->token.value.length());
			head->rightChild->token.value = head->rightChild->token.value.substr(1, head->rightChild->token.value.length());
		}
		//val [*][/] 1 or 1 [*] val
		if (head->leftChild->token.value == "1")
		{
			delete head->leftChild;
			head->leftChild = nullptr;
			head->token = head->rightChild->token;
			delete head->rightChild;
			head->rightChild = nullptr;
		}
		else if (head->rightChild->token.value == "1")
		{
			delete head->rightChild;
			head->rightChild = nullptr;
			head->token = head->leftChild->token;
			delete head->leftChild;
			head->leftChild = nullptr;
		}
	}
}

void out_of_breaks_optimizer(Node* head)
{
	if (head->token.value == "+" || head->token.value == "-")
	{
		cout << "here" << endl;
		auto left1 = head->leftChild;
		auto right1 = head->rightChild;
		if ((left1->token.value == "*" && right1->token.value == "*") ||
			(left1->token.value == "/" && right1->token.value == "/"))
		{
			Token token;
			bool f = 0;
			if (left1->leftChild->token == right1->leftChild->token)
			{
				f = 1;
				token = head->leftChild->leftChild->token;
				head->rightChild->leftChild->token = left1->rightChild->token;
				head->rightChild->rightChild->token = right1->rightChild->token;
			}
			else if (left1->leftChild->token == right1->rightChild->token)
			{
				f = 1;
				token = head->leftChild->leftChild->token;
				head->rightChild->leftChild->token = left1->rightChild->token;
				head->rightChild->rightChild->token = right1->leftChild->token;
			}
			else if (left1->rightChild->token == right1->leftChild->token)
			{
				f = 1;
				token = head->leftChild->rightChild->token;
				head->rightChild->leftChild->token = left1->leftChild->token;
				head->rightChild->rightChild->token = right1->rightChild->token;
			}
			else if (left1->rightChild->token == right1->rightChild->token)
			{
				f = 1;
				token = head->leftChild->rightChild->token;
				head->rightChild->leftChild->token = left1->leftChild->token;
				head->rightChild->rightChild->token = right1->leftChild->token;
			}
			if (f)
			{
				delete head->leftChild->leftChild;
				head->leftChild->leftChild = nullptr;
				delete head->leftChild->rightChild;
				head->leftChild->rightChild = nullptr;
				head->leftChild->token = token;
				token = head->token;
				head->token = head->rightChild->token;
				head->rightChild->token = token;
			}
		}
	}
}

void empty_string_optimizer(Node* head)
{
	if (head->token.value == "+")
	{
		if (head->leftChild->token.value == "")
		{
			delete head->leftChild;
			head->leftChild = nullptr;
			head->token = head->rightChild->token;
			delete head->rightChild;
			head->rightChild = nullptr;
		}
		else if (head->rightChild->token.value == "")
		{
			delete head->rightChild;
			head->rightChild = nullptr;
			head->token = head->leftChild->token;
			delete head->leftChild;
			head->leftChild = nullptr;
		}
	}
}

void condition_optimizer(Node *head)
{
	if (head->token.value == ">" || head->token.value == "<" ||
		head->token.value == ">=" || head->token.value == ">=" || head->token.value == "=")
	{
		if (head->leftChild->token == head->rightChild->token)
		{
			auto left1 = head->leftChild;
			auto right1 = head->rightChild;
			if (head->leftChild->leftChild->token == head->rightChild->leftChild->token)
			{
				head->leftChild->token = head->leftChild->rightChild->token;
				delete head->leftChild->leftChild;
				head->leftChild->leftChild = nullptr;
				delete head->leftChild->rightChild;
				head->leftChild->rightChild = nullptr;

				head->rightChild->token = head->rightChild->rightChild->token;
				delete head->rightChild->leftChild;
				head->rightChild->leftChild = nullptr;
				delete head->rightChild->rightChild;
				head->rightChild->rightChild = nullptr;
			}
			else if (head->leftChild->leftChild->token == head->rightChild->rightChild->token)
			{
				head->leftChild->token = head->leftChild->rightChild->token;
				delete head->leftChild->leftChild;
				head->leftChild->leftChild = nullptr;
				delete head->leftChild->rightChild;
				head->leftChild->rightChild = nullptr;

				head->rightChild->token = head->rightChild->leftChild->token;
				delete head->rightChild->rightChild;
				head->rightChild->rightChild = nullptr;
				delete head->rightChild->leftChild;
				head->rightChild->leftChild = nullptr;
			}
			else if (head->leftChild->rightChild->token == head->rightChild->leftChild->token)
			{
				head->leftChild->token = head->leftChild->leftChild->token;
				delete head->leftChild->rightChild;
				head->leftChild->rightChild = nullptr;
				delete head->leftChild->leftChild;
				head->leftChild->leftChild = nullptr;

				head->rightChild->token = head->rightChild->rightChild->token;
				delete head->rightChild->rightChild;
				head->rightChild->rightChild = nullptr;
				delete head->rightChild->leftChild;
				head->rightChild->leftChild = nullptr;
			}
			else if (head->leftChild->rightChild->token == head->rightChild->rightChild->token)
			{
				head->leftChild->token = head->leftChild->leftChild->token;
				delete head->leftChild->rightChild;
				head->leftChild->rightChild = nullptr;
				delete head->leftChild->leftChild;
				head->leftChild->leftChild = nullptr;

				head->rightChild->token = head->rightChild->leftChild->token;
				delete head->rightChild->rightChild;
				head->rightChild->rightChild = nullptr;
				delete head->rightChild->leftChild;
				head->rightChild->leftChild = nullptr;
			}
		}
	}
}