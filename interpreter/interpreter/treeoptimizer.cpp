#include "TreeOptimizer.h"

	TreeOptimizer* TreeOptimizer::treeOpt = nullptr;

	TreeOptimizer::TreeOptimizer()
	{
		this->optPatterns.push_back({ int_int_pattern(), int_int_optimizer});
		this->optPatterns.push_back({ out_of_breaks_pattern(), out_of_breaks_optimizer });
		this->optPatterns.push_back({ empty_string_pattern(), empty_string_optimizer });
		this->optPatterns.push_back({ empty_string_pattern_i(), empty_string_optimizer });
		this->optPatterns.push_back({ condition_pattern(), condition_optimizer });
	}

	TreeOptimizer* TreeOptimizer::getOptimizer()
	{
		if (TreeOptimizer::treeOpt == nullptr)
			TreeOptimizer::treeOpt = new TreeOptimizer;
		return TreeOptimizer::treeOpt;
	}

	void TreeOptimizer::optimize(Node* tree)
	{	
		if (tree->leftChild != nullptr) TreeOptimizer::optimize(tree->leftChild);
		if (tree->rightChild != nullptr) TreeOptimizer::optimize(tree->rightChild);
		if (tree->rightChild != nullptr &&tree->rightChild->token.type == Lib::TYPES::ID) performers::varConverter(tree->rightChild);
		if (tree->leftChild != nullptr && tree->leftChild->token.type == Lib::TYPES::ID &&tree->token.value != ":=") performers::varConverter(tree->leftChild);
		for (auto it = this->optPatterns.begin(); it != this->optPatterns.end(); it++)
		{
			if (nodeTypeEquality(tree, it->first))
			{
				it->second(tree);
			}
		}
	}

