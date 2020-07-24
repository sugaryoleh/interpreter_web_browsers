#pragma once
#include "node.h"
#include "lib.h"
#include "toboolconverter.h"


namespace performers {
	namespace binop {
		namespace combinations {
			void combination(Node*);

			void _and(Node*);
			void _or(Node*);
		}
	}
}