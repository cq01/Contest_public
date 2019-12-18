//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <iostream>
#include <cstring>
#include <algorithm>
#define clearA(a) memset((a),0,sizeof(a))
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		short Tlist[20000];
		bool inL[5000];
		clearA(inL);
		clearA(Tlist);
		int in;
		int m = 0;
		for (int i = 0; i < n; ++i)
		{

			cin >> in;
			if (!(inL[in]))
			{
				inL[in] = true;
				Tlist[m++] = in;
			}
		}

		for (int i = 0; i < m; ++i)
		{
			cout << Tlist[i] << ' ';
		}
		cout << endl;
	}
}