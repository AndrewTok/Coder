#pragma once
#include <string>
#include <vector>

class XorChipher final
{
	
	
	
	
public:

	XorChipher(std::vector<char> _passwd) : passwd(std::move(_passwd)) 
	{ 
		if (passwd.size() == 0)
		{
			passwd = { '\0' };
		}
	}
	std::vector<char> encode(const std::vector<char>& data) const;
	std::vector<char> decode(const std::vector<char>& codedData) const;
	void setPasswd(std::vector<char> _passwd) { passwd = std::move(_passwd); }

private:
	std::vector<char> passwd;
	char currUsingPasswdSymbol(size_t indexInData) const;

};