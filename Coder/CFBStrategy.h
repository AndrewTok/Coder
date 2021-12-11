#pragma once
#include <random>
#include <time.h>
#include <algorithm>
#include "CodeStrategy.h"

class CFBStrategy final : public CodeStrategy
{
	std::vector<char> initVector;

	std::vector<char> xorBlocks(const std::vector<char>& currBlock, const std::vector<char>& previousBlock) const;

public:
	//убрать из парам xor chipher создавать как member  передавать passwd
	CFBStrategy(XorChipher& _chipher, size_t _blockSize) : CodeStrategy(_chipher, _blockSize), initVector(_blockSize)
	{
		std::srand(time(0));
		std::transform(initVector.begin(), initVector.end(), initVector.begin(),
			[](char c) -> char {return char(std::rand() % 256); });
	}


	virtual std::vector<char> encode(const std::vector<char>& data) const override;
	virtual std::vector<char> decode(const std::vector<char>& codedData) const override;
};

