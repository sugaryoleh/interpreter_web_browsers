#include "exception.h"

Exception::Exception()
{
	this->text = "unhandled interpreter exception in line " + to_string(Code::pos) + "\n";
}

Exception::Exception(const string& text)
{
	this->text = text + "in line " + to_string(Code::pos) + "\n";
}

const string& Exception::_what() const
{
	return this->text;
}
