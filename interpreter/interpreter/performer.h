#pragma once
#include "token.h"
#include "lexer.h"
#include "lib.h"
#include "node.h"
#include "binop.h"
#include "unop.h"
#include "code.h"
#include "if.h"
#include "while.h"
#include "browseroperations.h"

namespace performers
{

		int perform(Node*);
		void performTree(Node*);

}

