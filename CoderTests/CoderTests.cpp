#include "pch.h"
#include "CBCStrategy.h"
#include "ECBStrategy.h"
#include "CFBStrategy.h"
#include "Client.h"
#include <random>
#include <iostream>
#include "randomForCoder.h"


void checkEncodeDecodeEachCLient(const std::vector<Client*>& clients, const std::vector<char>& data)
{
	ASSERT_EQ(clients.size(), 3);
	for (auto& cl : clients)
	{
		ASSERT_NE(cl, nullptr);
		std::vector<char> codedData = cl->encodeData(data);
		codedData = cl->decodeData(codedData);
		ASSERT_EQ(codedData, data);
	}
}

void makeAndCheckEachClient(size_t dataSize, size_t passwdSize, size_t blockSize)
{
	std::vector<char> data = genRandomVector(dataSize);
	std::vector<char> passwd = genRandomVector(passwdSize);

	CBCStrategy CBCcoding(passwd, blockSize);
	CFBStrategy CFBcoding(passwd, blockSize);
	ECBStrategy ECBcoding(passwd, blockSize);

	Client CBCclient(CBCcoding);
	Client CFBclient(CFBcoding);
	Client ECBclient(ECBcoding);

	std::vector<Client*> clients = { &CBCclient, &CFBclient, &ECBclient };
	checkEncodeDecodeEachCLient(clients, data);
}


TEST(Coder, testCorrectCode)
{
	size_t maxSize = 32;
	for (size_t i = 1; i < maxSize; ++i)
	{
		std::cout << double(i) / double(maxSize) * 100 << "%" << std::endl;
		for (size_t j = 1; j < maxSize; ++j)
		{
			for (size_t k = 1; k < maxSize; ++k)
			{
				makeAndCheckEachClient(i, j, k);
			}
		}
	}
}

TEST(Coder, testEmptyData)
{
	size_t maxSize = 128;
	for (size_t i = 1; i < maxSize; ++i)
	{
		for (size_t j = 1; j < maxSize; ++j)
		{
			makeAndCheckEachClient(0, i, j);

		}
	}
}


TEST(Coder, testSmallDataBigBlockSize)
{
	size_t passwSize = 3;
	size_t dataSize = 7;
	size_t maxBlockSize = 1048676;
	for (size_t blockSize = maxBlockSize - 3; blockSize < maxBlockSize; ++blockSize)
	{
		std::cout << double(blockSize) / double(maxBlockSize) * 100 << "%" << std::endl;
		makeAndCheckEachClient(dataSize, passwSize, blockSize);
	}
}

TEST(Coder, testBigDataBigBlockSize)
{
	size_t passwSize = 3;
	size_t dataSize = 1048676;
	size_t maxBlockSize = 1048676;
	for (size_t blockSize = maxBlockSize - 3; blockSize < maxBlockSize; ++blockSize)
	{
		std::cout << double(blockSize) / double(maxBlockSize) * 100 << "%" << std::endl;
		makeAndCheckEachClient(dataSize, passwSize, blockSize);
	}
}

TEST(Coder, testBigDataSmallBlockSize)
{
	size_t passwSize = 3;
	size_t dataSize = 1048676;
	size_t maxBlockSize = 13;
	for (size_t blockSize = maxBlockSize - 3; blockSize < maxBlockSize; ++blockSize)
	{
		std::cout << double(blockSize) / double(maxBlockSize) * 100 << "%" << std::endl;
		makeAndCheckEachClient(dataSize, passwSize, blockSize);
	}
}

TEST(Coder, testSmallDataSmallBlockSize)
{
	size_t passwSize = 2;
	size_t dataSize = 11;
	size_t maxBlockSize = 13;
	for (size_t blockSize = maxBlockSize - 8; blockSize < maxBlockSize; ++blockSize)
	{
		std::cout << double(blockSize) / double(maxBlockSize) * 100 << "%" << std::endl;
		makeAndCheckEachClient(dataSize, passwSize, blockSize);
	}
}