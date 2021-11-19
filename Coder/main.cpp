#include "XorChipher.h"
#include "ECBStrategy.h"
#include <iostream>
int main()
{
	XorChipher xorcode("key");
	ECBStrategy ECBcoding(xorcode, 2);
	
	std::string codedStr = ECBcoding.code("123456");
	std::cout << codedStr << std::endl;

	std::string encodedStr = ECBcoding.encode(codedStr);
	std::cout << encodedStr << std::endl;


}