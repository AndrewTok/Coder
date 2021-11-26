#pragma once
#include "XorChipher.h"


class CodeStrategy
{

protected:
	XorChipher& chipher;
	size_t blockSize;
	virtual std::vector<char> codeBlock(const std::vector<char>& dataBlock) const;
	virtual std::vector<char> encodeBlock(const std::vector<char>& codedDataBlock) const;

	virtual size_t getBlocksCountInData(const std::vector<char>& data) const;
	virtual std::vector<char> getBlockFromData(const std::vector<char>& data, size_t blockNum) const;
	virtual size_t fillLastBlockWithZero(std::vector<char>& lastBlock) const;

public:
	virtual ~CodeStrategy() = default;
	CodeStrategy(XorChipher& _chipher, size_t _blockSize) : chipher(_chipher), blockSize(_blockSize) {}
	virtual std::pair<std::vector<char>, size_t> code(const std::vector<char>& data) const = 0; // return coded data and number of added zero to the end
	virtual std::vector<char> encode(const std::vector<char>& codedData) const = 0;
};
