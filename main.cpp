//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <bits/stdc++.h>
using namespace std;


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n, m;
	while (cin >> n >> m)
	{
		priority_queue<int, vector<int>, greater<int> > N, M;
		int x;
		//in
		while (n--)
		{
			cin >> x;
			N.push(x);
		}
		while (m--)
		{
			cin >> x;
			M.push(x);
		}
		//out
		bool notfirst = false;
		while (!(N.empty()||M.empty()))
		{
			if (N.top()==M.top())
			{
				if (notfirst)
				{
					cout << ' ';
				}
				notfirst = true;
				cout << N.top();
				N.pop();
				M.pop();
			}
			else if (N.top()<M.top())
			{
				N.pop();
			}
			else if (N.top()>M.top())
			{
				M.pop();
			}
		}
		cout << endl;
	}
}