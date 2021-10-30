#pragma once
#include <string>

class CodeStrategy
{
protected:

	std::string passwd;


public:
	virtual ~CodeStrategy() = default;
	CodeStrategy(std::string _passwd) : passwd(std::move(_passwd)) {}
	void setPasswd(std::string _passwd) { passwd = std::move(_passwd); }
	virtual std::string code(const std::string& data) const = 0;
	virtual std::string encode(const std::string& codedData) const = 0;
 
};
