#include "ECBStrategy.h"

//size_t ECBStrategy::getBlocksCountInData(const std::vector<char>& data) const
//{
//	size_t blocksCount = data.size() / blockSize;
//	if (data.size() % blockSize != 0)
//	{
//		++blocksCount;
//	}
//	return blocksCount;
//
//}
//
//std::vector<char> ECBStrategy::getBlockFromData(const std::vector<char>& data, size_t blockNum) const
//{
//	if (blockNum > getBlocksCountInData(data))
//	{
//		return std::vector<char>{};
//	}
//	size_t startBlockShift = blockNum*blockSize;
//	if (startBlockShift + blockSize < data.size())
//	{
//		size_t endBlockShift = startBlockShift + blockSize;
//		return std::vector<char>(data.begin() + startBlockShift, data.begin() + endBlockShift);
//	}
//	return std::vector<char>(data.begin() + startBlockShift, data.end());
//}
//
//size_t ECBStrategy::fillLastBlockWithZero(std::vector<char>& lastBlock) const
//{
//	size_t additionalZerosNum = blockSize - lastBlock.size();
//	for (size_t i = 0; i < additionalZerosNum; ++i)
//	{
//		lastBlock.push_back('0');
//	}
//	return additionalZerosNum;
//}
//
//std::vector<char> ECBStrategy::codeBlock(const std::vector<char>& dataBlock) const
//{
//	return chipher.code(dataBlock);
//}
//
//std::vector<char> ECBStrategy::encodeBlock(const std::vector<char>& codedDataBlock) const
//{
//	return chipher.encode(codedDataBlock);
//}

std::pair<std::vector<char>, size_t> ECBStrategy::code(const std::vector<char>& data) const
{
	std::vector<char> codedData;
	
	size_t blocksCount = getBlocksCountInData(data);
	size_t numberOfAddedZeros = 0;
	for (size_t currBlockNum = 0; currBlockNum < blocksCount; ++currBlockNum)
	{
		std::vector<char> currBlock = getBlockFromData(data, currBlockNum);
		if (currBlock.size() < blockSize)
		{
			numberOfAddedZeros = fillLastBlockWithZero(currBlock);
		}
		std::vector<char> codedBlock = codeBlock(currBlock);
		codedData.insert(codedData.end(), codedBlock.begin(), codedBlock.end());
	}
	return std::pair<std::vector<char>, size_t>{codedData, numberOfAddedZeros};
}

std::vector<char> ECBStrategy::encode(const std::vector<char>& codedData) const
{
	//std::string encodedData;

	//size_t blocksCount = codedData.size() / blockSize;
	//for (size_t currBlockNum = 0; currBlockNum < blocksCount; ++currBlockNum)
	//{
	//	std::string currBlock = codedData.substr(currBlockNum * blockSize, blockSize);
	//	encodedData.append(encodeBlock(currBlock));
	//}
	//return encodedData;
	if (codedData.size() % blockSize != 0)
	{
		return std::vector<char>{};
	}
	std::vector<char> encodedData;

	size_t blocksCount = codedData.size() / blockSize;
	for (size_t currBlockNum = 0; currBlockNum < blocksCount; ++currBlockNum)
	{
		std::vector<char> currBlock = getBlockFromData(codedData, currBlockNum);
		std::vector<char> encodedBlock = encodeBlock(currBlock);
		encodedData.insert(encodedData.end(), encodedBlock.begin(), encodedBlock.end());
	}
	return encodedData;
}
