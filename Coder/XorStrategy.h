#pragma once
#include "CodeStrategy.h"

class XorStrategy final : public CodeStrategy
{

	char currUsingPasswdSymbol(size_t indexInData) const;
	
public:
	XorStrategy(std::string _passwd) : CodeStrategy(std::move(_passwd)) {}
	virtual std::string code(const std::string& data) const override;
	virtual std::string encode(const std::string& codedData) const  override;
	//virtual ~XorStrategy() = default;
};