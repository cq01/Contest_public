//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int tableSize = 25;
const int primeTable[tableSize] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };
bool isPrime(int x)
{
	for (int i = 0; i < tableSize; ++i)
	{
		if (x == primeTable[i])
		{
			return true;
		}
	}
	return false;
}
int main()
{
	char str[128];
	while (cin >> str)
	{
		int num = strlen(str);
		int times[26] = { 0,0,0,0,0,0 };
		memset(times, 0, sizeof(times));
		for (int i = 0; i < num; ++i)
		{
			++times[str[i] - 'a'];
		}
		int minN = 200, maxN = 0;
		for (int i = 0; i < 26; ++i)
		{
			if (times[i])
			{
				minN = min(minN, times[i]);
				maxN = max(maxN, times[i]);
			}

		}
		int LW = maxN - minN;
		if (isPrime(LW))
		{
			cout << "Lucky Word\n" << LW << endl;
		}
		else {
			cout << "No Answer\n0" << endl;
		}
	}
}

