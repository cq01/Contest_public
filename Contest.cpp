//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <iostream>
using namespace std;
int main()
{
	int a;
	while (cin >> a)
	{
		for (int i = 0; i < 5; ++i)
		{
			cout << "  " << a % 10;
			a /= 10;
		}
		cout << endl;
	}

}

