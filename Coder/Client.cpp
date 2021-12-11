#include "Client.h"

std::vector<char> Client::encodeData(const std::vector<char>& data) const
{
	return strategy.encode(data);
}

std::vector<char> Client::decodeData(const std::vector<char>& codedData) const
{
	return strategy.decode(codedData);
}
