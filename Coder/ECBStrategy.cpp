#include "ECBStrategy.h"

size_t ECBStrategy::getBlocksCountInData(const std::string& data) const
{
	size_t blocksCount = data.size() / blockSize;
	if (data.size() % blockSize != 0)
	{
		++blocksCount;
	}
	return blocksCount;

}

void ECBStrategy::fillLastBlockWithZero(std::string& lastBlock) const
{
	size_t additionalZerosNum = blockSize - lastBlock.size();
	lastBlock.append(additionalZerosNum, '0');
}

std::string ECBStrategy::codeBlock(const std::string& dataBlock) const
{
	return chipher.code(dataBlock);
}

std::string ECBStrategy::encodeBlock(const std::string& codedDataBlock) const
{
	return chipher.encode(codedDataBlock);
}

std::string ECBStrategy::code(const std::string& data) const
{
	std::string codedData;
	
	size_t blocksCount = getBlocksCountInData(data);
	for (size_t currBlockNum = 0; currBlockNum < blocksCount; ++currBlockNum)
	{
		std::string currBlock = data.substr(currBlockNum * blockSize, blockSize);
		if (currBlock.size() < blockSize)
		{
			fillLastBlockWithZero(currBlock);
		}
		codedData.append(codeBlock(currBlock));
	}
	return codedData;
}

std::string ECBStrategy::encode(const std::string& codedData) const
{
	std::string encodedData;

	size_t blocksCount = codedData.size() / blockSize;
	for (size_t currBlockNum = 0; currBlockNum < blocksCount; ++currBlockNum)
	{
		std::string currBlock = codedData.substr(currBlockNum * blockSize, blockSize);
		encodedData.append(encodeBlock(currBlock));
	}
	return encodedData;
}
