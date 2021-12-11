#include "XorChipher.h"
#include "ECBStrategy.h"
#include "CBCStrategy.h"
#include "CFBStrategy.h"
#include "Client.h"
#include <iostream>

std::vector<char> encodeAndPrint(const std::vector<char>& data, Client& cl)
{
	std::vector<char> encodedData = cl.encodeData(data);
	for (auto i : encodedData)
	{
		std::cout << i << " ";
	}

	std::cout << std::endl;
	return encodedData;
}

std::vector<char> decodeAndPrint(std::vector<char>& encodedData, Client& cl)
{
	std::vector<char> decodedData = cl.decodeData(encodedData);;
	for (auto i : decodedData)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	return decodedData;
}

void encodePrintDecodePrint(std::vector<char>& data, Client& cl)
{
	std::vector<char> codedData = encodeAndPrint(data, cl);
	decodeAndPrint(codedData, cl);
}


int main()
{
	std::vector<char> data = {'1', '2', '3', '4', '5', '6' };
	std::vector<char> passwd = { 'k', 'e', 'y' };
	XorChipher xorcode(passwd);
	CFBStrategy CFBcoding(xorcode, 2);
	ECBStrategy ECBcoding(xorcode, 2);
	CBCStrategy CBCcoding(xorcode, 2);

	Client CFBcl(CFBcoding);
	Client ECBcl(ECBcoding);
	Client CBCcl(CBCcoding);
	std::cout << "Im in main\n";
	
	//encodePrintDecodePrint(data, CBCcl);
	

	std::vector<Client*> clients = { &CFBcl, &ECBcl, &CBCcl };
	for (auto& cl : clients)
	{
		encodePrintDecodePrint(data, *cl);
	}

}