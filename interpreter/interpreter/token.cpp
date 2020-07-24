#include "token.h"

Token::Token(const string& val, const string& type, const int& pr)
{
	this->value = val;
	this->type = type;
	this->priority = pr;
}

string Token::repr(const Token& tok)
{
	return "{ VALUE:\t" + tok.value + "\t|\tTYPE:\t" + tok.type + "\t|\tPRIORITY:\t" + to_string(tok.priority) + "}\n";
}

Token Token::operator=(const Token& r)
{
	if (&r != this)
	{
		this->value = r.value;
		this->type = r.type;
		this->priority = r.priority;
	}
	return *this;
}

ostream& operator<<(ostream& out, const Token& tok)
{
	out << "{ VALUE:\t" + tok.value + "\t|\tTYPE:\t" + tok.type + "\t|\tPRIORITY:\t" + to_string(tok.priority) + "}\n";
	return out;
}

bool operator==(const Token& l, const Token& r)
{
	if (l.priority == r.priority && l.type == r.type && l.value == r.value) return true;
	else return false;
}

bool operator!=(const Token& l, const Token& r)
{
	if (l.priority == r.priority || l.type == r.type|| l.value == r.value) return true;
	else return false;
}

bool notStrongEqulaity(const Token& l, const Token& r)
{
	if (l.priority == r.priority && l.type == r.type)
		if (l.value == r.value || l.value =="" || r.value =="") return true;
	else return false;
}
