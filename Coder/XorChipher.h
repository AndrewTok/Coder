#pragma once
#include "BlockChipher.h"

class XorChipher final : public BlockChipher
{

	char currUsingPasswdSymbol(size_t indexInData) const;
	
public:
	XorChipher(std::string _passwd) : BlockChipher(std::move(_passwd)) {}
	virtual std::string code(const std::string& data) const override;
	virtual std::string encode(const std::string& codedData) const  override;
	//virtual ~XorStrategy() = default;
};