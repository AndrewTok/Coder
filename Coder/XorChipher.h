#pragma once
#include <string>
#include <vector>

class XorChipher final
{
	
	
	
	
public:

	XorChipher(std::vector<char> _passwd) : passwd(std::move(_passwd)) {}
	std::vector<char> code(const std::vector<char>& data) const;
	std::vector<char> encode(const std::vector<char>& codedData) const;
	void setPasswd(std::vector<char> _passwd) { passwd = std::move(_passwd); }

private:
	std::vector<char> passwd;
	char currUsingPasswdSymbol(size_t indexInData) const;

};