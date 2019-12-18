//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <bits/stdc++.h>
using namespace std;

#define clear_array(x) memset((x),0,sizeof(x))
bool Test();
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int T;
	while (cin >> T)
	{
		for (int t = 0; t < T; ++t)
		{
			if (Test())
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
		}
	}
}

bool Test()
{
	char numstr[21] = { 0 };
	uint8_t numarray[20] = { 0 };
	clear_array(numstr);
	clear_array(numarray);
	cin >> numstr;
	uint8_t num1count[10] = { 0 }, num2count[10] = { 0 };
	clear_array(num1count);
	clear_array(num2count);

	for (int i = strlen(numstr) - 1, j = 0; i >= 0; --i)
	{
		numarray[j++] = uint8_t(numstr[i] - '0');
	}
	for (uint8_t& x : numarray)
	{
		++num1count[x];
	}
	uint8_t jin = 0;
	for (uint8_t& x : numarray)
	{
		x = x * 2 + jin;
		jin = x / 10;
		x %= 10;
	}
	for (uint8_t& x : numarray)
	{
		++num2count[x];
	}
	bool isConsist = true;
	for (int i = 0; i < 10; ++i)
	{
		isConsist = isConsist && (num1count[i] == num2count[i]);
	}
	return isConsist;
}