#include "XorChipher.h"
#include "ECBStrategy.h"
#include "CBCStrategy.h"
#include <iostream>
int main()
{
	std::vector<char> data = { '1', '2', '3', '4', '5', '6' };
	std::vector<char> passwd = { 'k', 'e', 'y' };
	XorChipher xorcode(passwd);
	CBCStrategy ECBcoding(xorcode, 2);
	
	std::pair<std::vector<char>, size_t> codedDataAndZerosNum = ECBcoding.code(data);
	for (auto i : codedDataAndZerosNum.first)
	{
		std::cout << i << " ";
	}

	std::cout << std::endl;

	std::vector<char>  encodedData = ECBcoding.encode(codedDataAndZerosNum.first);
	for (auto i : encodedData)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;


}