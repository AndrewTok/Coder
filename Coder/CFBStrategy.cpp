#include "CFBStrategy.h"

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

std::pair<std::vector<char>, size_t> CFBStrategy::code(const std::vector<char>& data) const
{
	std::vector<char> codedData;
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
		std::vector<char> codedBlock = codeBlock(previousBlock);
		codedBlock = xorBlocks(codedBlock, currBlock);
		previousBlock = codedBlock;
		codedData.insert(codedData.end(), codedBlock.begin(), codedBlock.end());
	}
	return std::pair<std::vector<char>, size_t>{codedData, numberOfAddedZeros};
}

std::vector<char> CFBStrategy::encode(const std::vector<char>& codedData) const
{
	if (codedData.size() % blockSize != 0)
	{
		return std::vector<char>{};
	}
	std::vector<char> encodedData;
	std::vector<char> previousBlock;
	size_t blocksCount = codedData.size() / blockSize;
	for (size_t currBlockNum = blocksCount - 1; currBlockNum != ~size_t(0); --currBlockNum)
	{
		if (currBlockNum == 0)
		{
			previousBlock = initVector;
		}
		else
		{
			previousBlock = getBlockFromData(codedData, currBlockNum - 1);
		}
		std::vector<char> currBlock = getBlockFromData(codedData, currBlockNum);
		std::vector<char> encodedBlock = xorBlocks(currBlock, codeBlock(previousBlock));
		encodedData.insert(encodedData.begin(), encodedBlock.begin(), encodedBlock.end());
	}
	return encodedData;
}