//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		if (fabs(a) <= 2 && fabs(b) <= 2)
		{
			cout << "true" << endl;
		}
		else
		{
			cout << "false" << endl;
		}
	}
}

