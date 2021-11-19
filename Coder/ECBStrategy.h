#pragma once
#include "CodeStrategy.h"



class ECBStrategy final : public CodeStrategy
{
	virtual std::string codeBlock(const std::string& dataBlock) const = 0;
	virtual std::string encodeBlock(const std::string& codedDataBlock) const = 0;

public:

	ECBStrategy(BlockChipher& _chipher, size_t _blockSize) : CodeStrategy(_chipher, _blockSize) {}

	virtual std::string code(const std::string& data) const = 0;
	virtual std::string encode(const std::string& codedData) const = 0;
};
