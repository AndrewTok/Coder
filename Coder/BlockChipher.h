#pragma once
#include <string>

class BlockChipher
{
protected:

	std::string passwd;


public:
	virtual ~BlockChipher() = default;
	BlockChipher(std::string _passwd) : passwd(std::move(_passwd)) {}
	void setPasswd(std::string _passwd) { passwd = std::move(_passwd); }
	virtual std::string code(const std::string& data) const = 0;
	virtual std::string encode(const std::string& codedData) const = 0;
 
};
