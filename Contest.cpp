//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <iostream>
using namespace std;
int main()
{
	int a, b, c, s;
	while (cin>>a>>b>>c)
	{
		s = a > b ? (b > c ? c : b) : (a > c ? c : a);
		cout << s << endl;
	}
}

