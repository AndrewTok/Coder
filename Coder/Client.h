#pragma once
#include "CodeStrategy.h"


class Client final
{
	CodeStrategy& strategy;

public:
	Client(CodeStrategy& _chipher) : strategy(_chipher){}
	std::pair<std::vector<char>, size_t> codeData(const std::vector<char>& data) const;
	std::vector<char> encodeData(const std::vector<char>& codedData) const;

};