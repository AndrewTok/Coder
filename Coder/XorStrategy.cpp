#include "XorStrategy.h"
#include <algorithm>
char XorStrategy::currUsingPasswdSymbol(size_t indexInData) const
{
	return passwd[indexInData % passwd.size()];
}

std::string XorStrategy::code(const std::string& data) const
{
	size_t currIndex = 0;
	std::string output;
	for (auto& currByte : data)
	{
		char codedByte = currByte ^ currUsingPasswdSymbol(currIndex);
		output.push_back(codedByte);
		// emplace back
		++currIndex;
	}
	//std::for_each(data.begin(), data.end(),
	//	[&currIndex, &output, this](const char& currByte) {
	//		char codedByte = currByte ^ currUsingPasswdSymbol(currIndex);
	//		output.push_back(codedByte);
	//		currIndex++;
	//	});
	return output;
}

std::string XorStrategy::encode(const std::string& codedData) const 
{
	return code(codedData);
}
