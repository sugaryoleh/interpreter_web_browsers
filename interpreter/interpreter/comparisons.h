#pragma once
#include "node.h"
#include "lib.h"

namespace performers {
	namespace binop {
		namespace comparisons {

			void comparison(Node*);

			void _less(Node*);
			void _greater(Node*);
			void equal(Node*);
			void lessOrEqual(Node*);
			void greaterOrEqual(Node*);
		}
	}
}