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

size_t CodeStrategy::fillLastBlockWithZero(std::vector<char>& lastBlock) const
{
	size_t additionalZerosNum = blockSize - lastBlock.size();
	for (size_t i = 0; i < additionalZerosNum; ++i)
	{
		lastBlock.push_back('0');
	}
	return additionalZerosNum;
}

std::vector<char> CodeStrategy::codeBlock(const std::vector<char>& dataBlock) const
{
	return chipher.code(dataBlock);
}

std::vector<char> CodeStrategy::encodeBlock(const std::vector<char>& codedDataBlock) const
{
	return chipher.encode(codedDataBlock);
}
