#include "XorChipher.h"
#include <algorithm>
char XorChipher::currUsingPasswdSymbol(size_t indexInData) const
{
	if (passwd.size() == 0)
	{
		return '\0';
	}
	return passwd[indexInData % passwd.size()];
}

std::vector<char> XorChipher::encode(const std::vector<char>& data) const
{
	size_t currIndex = 0;
	std::vector<char> output;
	for (auto& currByte : data)
	{
		char codedByte = currByte ^ currUsingPasswdSymbol(currIndex);
		output.push_back(codedByte);
		// emplace back
		++currIndex;
	}
	return output;
}

std::vector<char> XorChipher::decode(const std::vector<char>& codedData) const
{
	return encode(codedData);
}
