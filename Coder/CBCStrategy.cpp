#include "CBCStrategy.h"
#include <iostream>

void CBCStrategy::codeCurrBlockWithPrevious(std::vector<char>& currBlock, const std::vector<char>& previousBlock) const
{
	size_t currIdx = 0;
	for (auto& c : currBlock)
	{
		c ^= previousBlock.at(currIdx);
		++currIdx;
	}
}

std::vector<char> CBCStrategy::encode(const std::vector<char>& data) const
{
	if (data.size() == 0)
	{
		return std::vector<char>();
	}
	std::vector<char> codedData(sizeof(size_t), 0);
	std::vector<char> previousBlock{ initVector };
	size_t blocksCount = getBlocksCountInData(data);
	size_t numberOfAddedZeros = 0;
	for (size_t currBlockNum = 0; currBlockNum < blocksCount; ++currBlockNum)
	{
		std::vector<char> currBlock = getBlockFromData(data, currBlockNum);
		if (currBlock.size() < blockSize)
		{
			numberOfAddedZeros = fillLastBlockWithZero(currBlock);
		}
		codeCurrBlockWithPrevious(currBlock, previousBlock);
		std::vector<char> codedBlock = encodeBlock(currBlock);
		previousBlock = codedBlock;
		codedData.insert(codedData.end(), codedBlock.begin(), codedBlock.end());
	}
	storeNumberOfAddedBytes(codedData, numberOfAddedZeros);
	return codedData;
}

std::vector<char> CBCStrategy::decode(const std::vector<char>& codedData) const
{
	if (!checkCorrectnessCodedData(codedData))
	{
		return std::vector<char>{};
	}
	size_t numberOfAddedZeros = loadNumberOfAddedBytes(codedData);
	if (numberOfAddedZeros == size_t(~0))
	{
		return std::vector<char>{};
	}
	std::vector<char> previousBlock;
	size_t blocksCount = getBlocksCountInCodedData(codedData);
	std::vector<char> decodedData;
	for (size_t currBlockNum = blocksCount - 1; currBlockNum != ~size_t(0); --currBlockNum)
	{
		if (currBlockNum == 0)
		{
			previousBlock = initVector;
		}
		else
		{
			previousBlock = getBlockFromCodedData(codedData, currBlockNum - 1);
		}
		std::vector<char> currBlock = getBlockFromCodedData(codedData, currBlockNum);
		std::vector<char> encodedBlock = decodeBlock(currBlock);
		codeCurrBlockWithPrevious(encodedBlock, previousBlock);
		decodedData.insert(decodedData.begin(), encodedBlock.begin(), encodedBlock.end());
	}
	decodedData.erase(decodedData.end() - numberOfAddedZeros, decodedData.end());
	return decodedData;
}
