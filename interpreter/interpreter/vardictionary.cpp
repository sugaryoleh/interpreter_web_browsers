#include "vardictionary.h"

VarDictionary* VarDictionary::vd = nullptr;

VarDictionary* VarDictionary::getVarDict()
{
	if (VarDictionary::vd == nullptr)
		VarDictionary::vd = new VarDictionary();
	return VarDictionary::vd;
}

void VarDictionary::push(const string& key, const Token& val)
{
	vars[key] = val;
}

Token& VarDictionary::get(const string& key)
{
	auto it = vars.find(key);
	if (it != vars.end())
	{
		return it->second;
	}
	throw Exception("no var with id " + key);
}

const map<string, Token>& VarDictionary::getVars() 
{
	return this->vars;
}

string VarDictionary::repr()
{
	string buf;
	buf += "DICT.\nstart\n";
	for (auto it = this->vars.begin(); it != this->vars.end(); it++)
	{
		buf += "{ " + it->first + " : " + Token::repr(it->second) + " }\n";
	}
	buf += "end\n";
	return buf;
}

Token VarDictionary::operator[](const string& key) const
{
	auto it = vars.find(key);
	if (it != vars.end())
	{
		return it->second;
	}
	throw Exception("no var with id " + key);
}

void VarDictionary::_delete(const string& key)
{
	if (this->vars.find(key) != this->vars.end())
	{
		this->vars.erase(key);
	}
	else throw Exception("no var with id " + key);

}
