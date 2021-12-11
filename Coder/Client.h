#pragma once
#include "CodeStrategy.h"


class Client final
{
	CodeStrategy& strategy;

public:
	Client(CodeStrategy& _chipher) : strategy(_chipher){}
	std::vector<char> encodeData(const std::vector<char>& data) const;
	std::vector<char> decodeData(const std::vector<char>& codedData) const;

};