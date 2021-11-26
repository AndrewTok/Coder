#include "Client.h"

std::pair<std::vector<char>, size_t> Client::codeData(const std::vector<char>& data) const
{
	return strategy.code(data);
}

std::vector<char> Client::encodeData(const std::vector<char>& codedData) const
{
	return strategy.encode(codedData);
}
