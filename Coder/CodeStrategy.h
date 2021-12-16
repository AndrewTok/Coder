#pragma once
#include "XorChipher.h"


class CodeStrategy
{

protected:
	XorChipher chipher;
	size_t blockSize;
	virtual std::vector<char> encodeBlock(const std::vector<char>& dataBlock) const;
	virtual std::vector<char> decodeBlock(const std::vector<char>& codedDataBlock) const;

	virtual size_t getBlocksCountInData(const std::vector<char>& data) const;
	virtual size_t getBlocksCountInCodedData(const std::vector<char>& codedData) const;
	virtual bool checkCorrectnessCodedData(const std::vector<char>& codedData) const;
	virtual std::vector<char> getBlockFromData(const std::vector<char>& data, size_t blockNum) const;
	virtual std::vector<char> getBlockFromCodedData(const std::vector<char>& data, size_t blockNum) const;
	virtual size_t fillLastBlockWithZero(std::vector<char>& lastBlock) const;

	void storeNumberOfAddedBytes(std::vector<char>& codedData, size_t numberOfAddedZeros) const;
	size_t loadNumberOfAddedBytes(const std::vector<char>& codedData) const;


public:

	virtual ~CodeStrategy() = default;
	CodeStrategy(const std::vector<char>& passwd, size_t _blockSize) : chipher(passwd), blockSize(_blockSize) {}
	virtual std::vector<char> encode(const std::vector<char>& data) const = 0; 
	virtual std::vector<char> decode(const std::vector<char>& codedData) const = 0;

};
