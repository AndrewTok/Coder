#include "XorChipher.h"
#include <iostream>
int main()
{
	BlockChipher* xorcode = new XorChipher("key");

	std::string codedStr = xorcode->code("12345");
	std::cout << codedStr << std::endl;
	std::string encodedStr = xorcode->encode(codedStr);
	std::cout << encodedStr << std::endl;
	delete(xorcode);
}