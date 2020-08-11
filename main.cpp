//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#define clearA(a) memset((a),0,sizeof(a))

int main()
{
	int m = 0, n = 0;
	bool pic[10000];

	int tempN = 0;
	while (cin >> m >> n)
	{
		clearA(pic);
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> tempN;
				pic[i * n + j] = bool(tempN);
			}
		}
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> tempN;
				pic[i * n + j] ^= !(bool(tempN));
			}
		}
		int countN = 0;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				countN += pic[i * n + j];
			}
		}
		cout << fixed << setprecision(2) << countN * 100 / double(m * n) << endl;
	}
}
