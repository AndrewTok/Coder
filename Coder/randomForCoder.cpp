#include "randomForCoder.h"

std::vector<char> genRandomVector(size_t size)
{
	if (size == 0)
	{
		return std::vector<char>();
	}
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(0, 256);
	std::vector<char> data;
	for (size_t i = size; i != 0; --i)
	{
		data.push_back(char(distrib(gen)));
	}
	return data;
}
