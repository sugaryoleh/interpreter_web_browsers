#include "lexer.h"


Lexer::Lexer(list<Token> token_exprs) {
	this->exprs = token_exprs;
}

Lexer::Lexer()
{
	this->exprs = Lib::token_expressions;
}

list<Token> Lexer::lex(const string& line)
{
	string line_copy = line;
	list<Token> tokens;
	while (line_copy != "")
	{
		bool match = 0;
		for (auto expr : this->exprs)
		{
			smatch matches;
			regex pat(expr.value);
			regex_search(line_copy, matches, pat);
			if (!matches.empty())
			{
				if (matches.prefix() == "")
				{
					match = 1;
					if (expr.type != Lib::TYPES::NONE)
						tokens.push_back(Token(matches[0], expr.type, expr.priority));
					line_copy = matches.suffix();
				}
			}
		}
		if (match == 0)
		{
			 throw Exception("Error. Wrong symb in sequence '" + line_copy + "'");
		}
	}
	for (auto& tok : tokens)
	{
		if (tok.type == Lib::TYPES::STR)
		{
			tok.value = tok.value.substr(1, tok.value.length() - 2);
		}
	}
	return tokens;
}

