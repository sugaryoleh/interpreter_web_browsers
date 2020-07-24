#pragma once
#include "node.h"
#include "lib.h"
#include "varconverter.h"

namespace performers {
	namespace binop {
		namespace arithmetics {
			void arithmetic(Node*);
			void _plus(Node*);
			void _minus(Node*);
			void multiply(Node*);
			void divide(Node*);

			void add(Node*);
			void concat(Node*);
		}
	}
}