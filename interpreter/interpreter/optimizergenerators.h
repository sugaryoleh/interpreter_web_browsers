#pragma once
#include "ast.h"
#include "node.h"

void int_int_optimizer(Node*);
void out_of_breaks_optimizer(Node*);
void empty_string_optimizer(Node*);
void condition_optimizer(Node*);