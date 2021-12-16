#include "CFBStrategy.h"
#include <iostream>

std::vector<char> CFBStrategy::xorBlocks(const std::vector<char>& currBlock, const std::vector<char>& previousBlock) const
{
	if (currBlock.size() != previousBlock.size())
	{
		return std::vector<char>{};
	}
	std::vector<char> output(currBlock.size());
	size_t idx = 0;
	for (auto& c : output)
	{
		c = currBlock[idx] ^ previousBlock[idx];
		++idx;
	}
	return output;
}

std::vector<char> CFBStrategy::encode(const std::vector<char>& data) const
{
	if (data.size() == 0)
	{
		return std::vector<char>();
	}
	std::vector<char> codedData( sizeof(size_t), 0 );
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
		std::vector<char> codedBlock = xorBlocks(encodeBlock(previousBlock), currBlock);
		previousBlock = codedBlock;
		codedData.insert(codedData.end(), codedBlock.begin(), codedBlock.end());
	}
	storeNumberOfAddedBytes(codedData, numberOfAddedZeros);
	return codedData;
}

std::vector<char> CFBStrategy::decode(const std::vector<char>& codedData) const
{
	if (!checkCorrectnessCodedData(codedData))
	{
		return std::vector<char>{};
	}
	std::vector<char> decodedData;
	std::vector<char> previousBlock;
	size_t blocksCount = getBlocksCountInCodedData(codedData);
	size_t numberOfAddedZeros = loadNumberOfAddedBytes(codedData);
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
		std::vector<char> decodedBlock = xorBlocks(currBlock, decodeBlock(previousBlock));
		decodedData.insert(decodedData.begin(), decodedBlock.begin(), decodedBlock.end());
	}
	decodedData.erase(decodedData.end() - numberOfAddedZeros, decodedData.end());
	return decodedData;
}
