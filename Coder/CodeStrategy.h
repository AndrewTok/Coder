#pragma once
#include <string>
#include "BlockChipher.h"


class CodeStrategy
{

protected:
	BlockChipher& chipher;
	size_t blockSize;
	virtual std::string codeBlock(const std::string& dataBlock) const = 0;
	virtual std::string encodeBlock(const std::string& codedDataBlock) const = 0;

public:
	virtual ~CodeStrategy() = default;
	CodeStrategy(BlockChipher& _chipher, size_t _blockSize) : chipher(_chipher), blockSize(_blockSize) {}
	virtual std::string code(const std::string & data) const = 0;
	virtual std::string encode(const std::string & codedData) const = 0;
};
