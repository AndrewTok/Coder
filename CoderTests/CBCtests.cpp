#include "pch.h"
#include "CBCStrategy.h"



TEST(CBCcoder, testCodeEmptyPasswd) 
{
	std::vector<char> data = { '1', '2', '3', '4', '5', '6' };
	std::vector<char> passwd = {};
	XorChipher xorcode(passwd);
	CBCStrategy CBCcoding(xorcode, 2);
	std::pair<std::vector<char>, size_t> codedData = CBCcoding.code(data);
	ASSERT_EQ(codedData.second, 0);
	ASSERT_EQ(codedData.first, data);
}

TEST(CBCcoder, testCorrectCode)
{
	std::vector<char> data = { '1', '2', '3', '4', '5', '6' };
	std::vector<char> passwd = { 'k', 'e', 'y' };
	XorChipher xorcode(passwd);
	CBCStrategy CBCcoding(xorcode, 2);
	std::pair<std::vector<char>, size_t> codedData = CBCcoding.code(data);
	ASSERT_EQ(codedData.second, 0);
	ASSERT_EQ(codedData.first, data);
}

TEST(CBCcoder, testEmptyData)
{
	std::vector<char> data = {};
	std::vector<char> passwd = { 'k', 'e', 'y' };
	XorChipher xorcode(passwd);
	CBCStrategy CBCcoding(xorcode, 2);
	std::pair<std::vector<char>, size_t> codedData = CBCcoding.code(data);
	ASSERT_EQ(codedData.second, 0);
	ASSERT_EQ(codedData.first, data);
}