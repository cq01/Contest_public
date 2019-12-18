//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <bits/stdc++.h>
using namespace std;

#define clear_array(x) memset((x),0,sizeof(x))

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int T;
	while (cin >> T)
	{
		for (int i = 0; i < T; ++i)
		{
			stack<string> str_stack;
			string str;
			char c;
			do
			{
				cin >> str;
				str_stack.push(str);
				c = cin.get();
			} while (c != '\n');
			do
			{
				cout << str_stack.top();
				str_stack.pop();
				if (!(str_stack.empty()))
				{
					cout << ' ';
				}
			} while (!(str_stack.empty()));
			cout << endl;
		}
	}
}