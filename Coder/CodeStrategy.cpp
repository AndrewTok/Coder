#include "CodeStrategy.h"

size_t CodeStrategy::getBlocksCountInData(const std::vector<char>& data) const
{
	size_t blocksCount = data.size() / blockSize;
	if (data.size() % blockSize != 0)
	{
		++blocksCount;
	}
	return blocksCount;

}

size_t CodeStrategy::getBlocksCountInCodedData(const std::vector<char>& codedData) const
{
	if (codedData.size() < sizeof(size_t))
	{
		return 0;
	}
	return (codedData.size() - sizeof(size_t))/blockSize;
}

bool CodeStrategy::checkCorrectnessCodedData(const std::vector<char>& codedData) const
{

	return (codedData.size() >= sizeof(size_t)) && (codedData.size() - sizeof(size_t)) % blockSize == 0;
}

std::vector<char> CodeStrategy::getBlockFromData(const std::vector<char>& data, size_t blockNum) const
{
	if (blockNum > getBlocksCountInData(data))
	{
		return std::vector<char>{};
	}
	size_t startBlockShift = blockNum * blockSize;
	if (startBlockShift + blockSize < data.size())
	{
		size_t endBlockShift = startBlockShift + blockSize;
		return std::vector<char>(data.begin() + startBlockShift, data.begin() + endBlockShift);
	}
	return std::vector<char>(data.begin() + startBlockShift, data.end());
}

std::vector<char> CodeStrategy::getBlockFromCodedData(const std::vector<char>& data, size_t blockNum) const
{
	if (blockNum > getBlocksCountInCodedData(data))
	{
		return std::vector<char>{};
	}
	size_t startBlockShift = blockNum * blockSize + sizeof(size_t);
	size_t endBlockShift = startBlockShift + blockSize;
	if (endBlockShift < data.size())
	{
		return std::vector<char>(data.begin() + startBlockShift, data.begin() + endBlockShift);
	}
	return std::vector<char>(data.begin() + startBlockShift, data.end());
}

size_t CodeStrategy::fillLastBlockWithZero(std::vector<char>& lastBlock) const
{
	size_t additionalZerosNum = blockSize - lastBlock.size();
	for (size_t i = 0; i < additionalZerosNum; ++i)
	{
		lastBlock.push_back('\0');
	}
	return additionalZerosNum;
}

size_t CodeStrategy::loadNumberOfAddedBytes(const std::vector<char>& codedData) const
{
	if (codedData.size() < sizeof(size_t))
	{
		return -1;
	}
	size_t numberOfAddedZeros = 0;
	char* numPtr = (char*)(&numberOfAddedZeros);
	for (size_t i = (sizeof(size_t) - 1); i != ~0; --i)
	{
		*(numPtr + i)  = codedData[i];
	}
	return numberOfAddedZeros;
}

void CodeStrategy::storeNumberOfAddedBytes(std::vector<char>& codedData, size_t numberOfAddedZeros) const
{
	if (codedData.size() < sizeof(size_t))
	{
		return;
	}
	char* numPtr = (char*)&numberOfAddedZeros;
	for (size_t i = 0; i < sizeof(size_t); ++i)
	{
		codedData[i] = *(numPtr + i);
	}

}

std::vector<char> CodeStrategy::encodeBlock(const std::vector<char>& dataBlock) const
{
	return chipher.encode(dataBlock);
}

std::vector<char> CodeStrategy::decodeBlock(const std::vector<char>& codedDataBlock) const
{
	return chipher.decode(codedDataBlock);
}
