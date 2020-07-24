#pragma once
#include "node.h"
#include "lib.h"
#include "interprocesscommunicator.h"
#include "processdictionary.h"
#include "varconverter.h"
#include "ast.h"
using namespace std;
#include <iostream>

namespace performers
{
	namespace binop
	{
		void open(Node*);
		void click(Node*);
		void input(Node*);
		void clear(Node*);
	}
	namespace unop
	{
		void run(Node*);
		void qiut(Node*);

	}
}