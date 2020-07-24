#include "interpreter.h"

Interpreter* Interpreter::i = nullptr;

Interpreter::Interpreter(Lexer*lex)
{
	this->lexer = lex;
}

Interpreter::Interpreter()
{
	vd = VarDictionary::getVarDict();
	pd = ProcessDictionary::getProcessDict();

}

void Interpreter::interpret(const int& e)
{
	auto it = Code::code.begin();
	if (this->optMode) {
		TreeOptimizer* tp = TreeOptimizer::getOptimizer();
		while (Code::pos < e)
		{
			auto tokens = this->lexer->lex(*(next(it, Code::pos)));
			AST tree(tokens);
			this->trees.push_back("ast\n" + tree.repr());
			tp->optimize(tree.mainNode);
			this->optTrees.push_back("optimized ast\n" + tree.repr());
			Code::pos = performers::perform(tree.mainNode);
		}
	}
	else
	{
		while (Code::pos < e)
		{
			Lexer lex;
			auto tokens = lex.lex(*(next(it, Code::pos)));
			AST tree(tokens);
			this->trees.push_back("ast\n" + tree.repr());
			//Code::pos += 1;
			Code::pos = performers::perform(tree.mainNode);
		}
	}
	cout << this->reprTrees();
	auto var = this->pd->getProcesses();
	//var.begin()->second->pipc->run(var.begin()->second->buf);
	for (auto it = var.begin(); it != var.end();  it++)
	{
		it->second->pipc->run(it->second->buf);
	}
}

Interpreter* Interpreter::getInterpreter()
{
	if (Interpreter::i == nullptr)
		Interpreter::i = new Interpreter();
	return Interpreter::i;
}

void Interpreter::runInteractive()
{
	InterProcessCommunicator ipc;
	ipc.init("Globalfmo");
	ipc.run(cin);
}

void Interpreter::runUsual(const string& path)
{
	Code::readCode(path);
	if (*Code::code.begin() == "#optimize")
	{
		cout << "optimized mode " << endl;
		this->optMode = true;
		Code::pos += 1;
	}
	this->interpret(Code::code.size());	
	
	
}

string Interpreter::reprTrees()
{
	string repr;
	auto it = this->trees.begin();
	auto oit = this->optTrees.begin();
	while (it != this->trees.end() && oit != this->optTrees.end())
	{
		repr += *it;
		repr += *oit;
		it++;
		if (oit != this->optTrees.end())  oit++;
	}
	return repr;
}
