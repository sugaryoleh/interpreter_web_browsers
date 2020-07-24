#pragma once
#include "node.h"
#include "lib.h"
#include "toboolconverter.h"
#include "browseroperations.h"


namespace performers
{
	namespace unop
	{
		void unOp(Node*);

		void unaryMinus(Node*);
		void _not(Node*);
		void _delete(Node*);
	}
}