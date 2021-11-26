#include "XorChipher.h"
#include "ECBStrategy.h"
#include "CBCStrategy.h"
#include "CFBStrategy.h"
#include "Context.h"
#include <iostream>

std::vector<char> codeAndPrint(std::vector<char>& data, Client& cl)
{
	std::pair<std::vector<char>, size_t> codedDataAndZerosNum = cl.codeData(data);
	for (auto i : codedDataAndZerosNum.first)
	{
		std::cout << i << " ";
	}

	std::cout << std::endl;
	return codedDataAndZerosNum.first;
}

std::vector<char> encodeAndPrint(std::vector<char>& codedData, Client& cl)
{
	std::vector<char> encodedData = cl.encodeData(codedData);;
	for (auto i : encodedData)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	return encodedData;
}

void codePrintEncodePrint(std::vector<char>& data, Client& cl)
{
	std::vector<char> codedData = codeAndPrint(data, cl);
	encodeAndPrint(codedData, cl);
}


int main()
{
	std::vector<char> data = { '1', '2', '3', '4', '5', '6' };
	std::vector<char> passwd = { 'k', 'e', 'y' };
	XorChipher xorcode(passwd);
	CFBStrategy CFBcoding(xorcode, 2);
	ECBStrategy ECBcoding(xorcode, 2);
	CBCStrategy CBCcoding(xorcode, 2);

	Client CFBcl(CFBcoding);
	Client ECBcl(ECBcoding);
	Client CBCcl(CBCcoding);
	
	std::vector<Client*> clients = { &CFBcl, &ECBcl, &CBCcl };
	for (auto& cl : clients)
	{
		codePrintEncodePrint(data, *cl);
	}

}