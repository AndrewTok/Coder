#pragma once
#include <random>
#include <time.h>
#include <algorithm>
#include "CodeStrategy.h"
class CBCStrategy final : public CodeStrategy
{

	std::vector<char> initVector;

	void codeCurrBlockWithPrevious(std::vector<char>& currBlock, const std::vector<char>& previousBlock) const;

public:

	CBCStrategy(XorChipher& _chipher, size_t _blockSize) : CodeStrategy(_chipher, _blockSize), initVector(_blockSize)
	{
		std::srand(time(0));
		std::transform(initVector.begin(), initVector.end(), initVector.begin(),
			[](char c) -> char {return char(std::rand() % 256); });
		//for (auto& i : initVector)
		//{
		//	char currSym = char(std::rand() % 256);
		//	i = currSym;
		//}
	}


	virtual std::pair<std::vector<char>, size_t> code(const std::vector<char>& data) const override;
	virtual std::vector<char> encode(const std::vector<char>& codedData) const override;
};

