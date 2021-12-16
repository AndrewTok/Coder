#include "ECBStrategy.h"

std::vector<char> ECBStrategy::encode(const std::vector<char>& data) const
{
	if (data.size() == 0)
	{
		return std::vector<char>();
	}
	std::vector<char> codedData(sizeof(size_t), 0);
	size_t blocksCount = getBlocksCountInData(data);
	size_t numberOfAddedZeros = 0;
	for (size_t currBlockNum = 0; currBlockNum < blocksCount; ++currBlockNum)
	{
		std::vector<char> currBlock = getBlockFromData(data, currBlockNum);
		if (currBlock.size() < blockSize)
		{
			numberOfAddedZeros = fillLastBlockWithZero(currBlock);
		}
		std::vector<char> codedBlock = encodeBlock(currBlock);
		codedData.insert(codedData.end(), codedBlock.begin(), codedBlock.end());
	}
	storeNumberOfAddedBytes(codedData, numberOfAddedZeros);
	return codedData;
}

std::vector<char> ECBStrategy::decode(const std::vector<char>& codedData) const
{
	if (!checkCorrectnessCodedData(codedData))
	{
		return std::vector<char>{};
	}
	std::vector<char> decodedData;
	size_t numberOfAddedZeros = loadNumberOfAddedBytes(codedData);
	size_t blocksCount = getBlocksCountInCodedData(codedData);
	for (size_t currBlockNum = 0; currBlockNum < blocksCount; ++currBlockNum)
	{
		std::vector<char> currBlock = getBlockFromCodedData(codedData, currBlockNum);
		std::vector<char> decodedBlock = decodeBlock(currBlock);
		decodedData.insert(decodedData.end(), decodedBlock.begin(), decodedBlock.end());
	}
	decodedData.erase(decodedData.end() - numberOfAddedZeros, decodedData.end());
	return decodedData;
}
