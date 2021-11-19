#pragma once
#include "CodeStrategy.h"



class ECBStrategy final : public CodeStrategy
{
	size_t getBlocksCountInData(const std::string& data) const;
	void fillLastBlockWithZero(std::string& lastBlock) const;
	virtual std::string codeBlock(const std::string& dataBlock) const override;
	virtual std::string encodeBlock(const std::string& codedDataBlock) const override;

public:

	ECBStrategy(BlockChipher& _chipher, size_t _blockSize) : CodeStrategy(_chipher, _blockSize) {}

	virtual std::string code(const std::string& data) const override;
	virtual std::string encode(const std::string& codedData) const override;
};
