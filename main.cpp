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
	int n;
	while (cin >> n)
	{
		vector<int> T(n);
		for (int i = 0; i < n; i++)
		{
			cin >> T[i];
		}
		int t;
		cin >> t;
		int sum = T[n - 1] + t;
		bool* yun = new bool[sum + 1];
		memset(yun, 0, (sum + 1) * sizeof(bool));
		for (int& t0 : T)
		{
			for (int i = t0; i < t0 + t; i++)
			{
				yun[i] = true;
			}
		}
		int Tsum = 0;
		for (int i = 0; i < sum + 1; i++)
		{
			Tsum += yun[i];
		}
		cout << Tsum << endl;
		delete[] yun;
	}
}

