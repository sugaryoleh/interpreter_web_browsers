#include "misk.h"

//AST

int getNext(const int* prts, const int& len)
{
	int max = *prts;
	int maxPos = 0;
	for (int i = 1; i < len; i++)
	{
		if (prts[i] > max) //|| prts[i] == max)
		{
			max = prts[i];
			maxPos = i;
		}
	}
	return maxPos;
}

int* getPriorities(const list<Token>& tokens)
{
	int* ptr = new int[tokens.size()];
	int counter = 0;
	for (auto it = tokens.begin(); it != tokens.end(); it++)
	{
		ptr[counter] = (*it).priority;
		counter++;
	}
	return ptr;
}

list<string> getSlice(list<string> orig, const int& l, const int& r)
{
	list<string> slice;
	int size = orig.size();
	if (l >= 0 && l <= r && r <= size)
	{
		list<string>::iterator it_l = orig.begin();
		list<string>::iterator it_r = orig.begin();
		advance(it_l, l);
		advance(it_r, r);
		for (it_l; it_l != it_r; it_l++)
			slice.push_back(*it_l);
		return slice;
	}
	else {
		/*EXCEPT*/
		throw Exception("Index out of range");
	}
}

list<Token> getSlice(list<Token> orig, const int& l, const int& r)
{
	list<Token> slice;
	int size = orig.size();
	if (l >= 0 && l <= r && r <= size)
	{
		list<Token>::iterator it_l = orig.begin();
		list<Token>::iterator it_r = orig.begin();
		advance(it_l, l);
		advance(it_r, r);
		for (it_l; it_l != it_r; it_l++)
			slice.push_back(*it_l);
		return slice;
	}
	else {
		/*EXCEPT*/
		throw Exception("Index out of range");
	}
}

ostream& operator<<(ostream& out, const list<Token>& tokens)
{
	for (auto it = tokens.begin(); it != tokens.end(); it++)
		out << *it;
	return out;
}

bool ifIn(const char* chars, const char& symb, const int& size)
{
	for (int i = 0; i < size; i++)
		if (chars[i] == symb)
		{
			return 1;
		}
	return 0;
}



//parsers

//if and while

int getPosOfEnd(const list<string>& lines, const int& pos)
{
	int count = 1;
	Lexer tokenizer = Lexer();
	auto it = lines.begin();
	advance(it, pos + 1);
	for (int i = pos + 1; i < lines.size(); i++)
	{
		list<Token> toks = tokenizer.lex(*it);
		for (auto it_ = toks.begin(); it_ != toks.end(); it_++)
		{
			if (it_->value == "if" || it_->value == "while")
			{
				count += 1;
			}
			else if (it_->value == "end")
			{
				count -= 1;
			}
		}
		if (count == 0)
			return i;
		it++;
	}
	throw Exception("'if' nas not closing tag 'end'");
}

int getPosOfElse(const list<string>& lines, const int& pos)
{
	int count = 0;
	Lexer tokenizer = Lexer();
	auto it = lines.begin();
	advance(it, pos + 1);
	for (int i = pos + 1; i < lines.size(); i++)
	{
		list<Token> toks = tokenizer.lex(*it);
		for (auto it_ = toks.begin(); it_ != toks.end(); it_++)
		{
			if (it_->value == "if")
			{
				count += 1;
			}
			else if (it_->value == "end")
			{
				count -= 1;
			}
			if (it_->value == "else" && count == 0)
			{
				return i;
			}
		}
		it++;
	}
	return -1;
}
