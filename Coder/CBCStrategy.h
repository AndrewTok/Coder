#pragma once
#include <random>
#include <algorithm>
#include "CodeStrategy.h"
#include "randomForCoder.h"

class CBCStrategy final : public CodeStrategy
{

	std::vector<char> initVector;

	void codeCurrBlockWithPrevious(std::vector<char>& currBlock, const std::vector<char>& previousBlock) const;

public:

	CBCStrategy(const std::vector<char>& passwd, size_t _blockSize) : CodeStrategy(passwd, _blockSize), initVector(genRandomVector(_blockSize)) {}


	virtual std::vector<char> encode(const std::vector<char>& data) const override;
	virtual std::vector<char> decode(const std::vector<char>& codedData) const override;
};

