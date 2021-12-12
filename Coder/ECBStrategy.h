#pragma once
#include "CodeStrategy.h"



class ECBStrategy final : public CodeStrategy
{
	//size_t getBlocksCountInData(const std::vector<char>& data) const;
	//std::vector<char> getBlockFromData(const std::vector<char>& data, size_t blockNum) const;
	//size_t fillLastBlockWithZero(std::vector<char>& lastBlock) const;
	//virtual std::vector<char> codeBlock(const std::vector<char>& dataBlock) const override;
	//virtual std::vector<char> encodeBlock(const std::vector<char>& codedDataBlock) const override;

public:

	ECBStrategy(const std::vector<char>& passwd, size_t _blockSize) : CodeStrategy(passwd, _blockSize) {}

	virtual std::vector<char> encode(const std::vector<char>& data) const override;
	virtual std::vector<char> decode(const std::vector<char>& codedData) const override;
};
