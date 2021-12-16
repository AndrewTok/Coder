#pragma once
#include "CodeStrategy.h"



class ECBStrategy final : public CodeStrategy
{

public:

	ECBStrategy(const std::vector<char>& passwd, size_t _blockSize) : CodeStrategy(passwd, _blockSize) {}

	virtual std::vector<char> encode(const std::vector<char>& data) const override;
	virtual std::vector<char> decode(const std::vector<char>& codedData) const override;
};
