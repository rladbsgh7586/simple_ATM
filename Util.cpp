#include "Util.h"

bool isNumber(const string& str)
{
	for (char const& c : str)
		if (isdigit(c) == 0) return false;
	return true;
}

int stringToInt(string val)
{
	int i = 0;
	stringstream ssInt(val);
	ssInt >> i;
	return i;
}