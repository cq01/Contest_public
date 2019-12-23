//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <bits/stdc++.h>
using namespace std;

#define clr(A) memset((A),0,sizeof(A))
int search(int k);
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int k;
	while (cin >> k)
	{
		cin.get();
		cout << search(k) << endl;
	}
}

int search(int k)
{
	char str[257] = {};
	int alph[26] = {};
	clr(str);
	clr(alph);
	cin.getline(str, sizeof str);
	int len = strlen(str);
	for (char& c : str)
	{
		if (c)
		{
			++alph[c - 'a'];
		}
		else
		{
			break;
		}
	}
	for (char& c : str)
	{
		if (c)
		{
			if (alph[c - 'a'] < k)
			{
				c = ' ';

			}
		}
		else
		{
			break;
		}
	}
	clr(alph);
	int maxnum = 0;
	int i = 0;
	int n = 0;
	stringstream ss(str);
	string s;
	while (ss >> s)
	{
		maxnum = max(maxnum, int(s.length()));
	}
	return 	maxnum;
}
