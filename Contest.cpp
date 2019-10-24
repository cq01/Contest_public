//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <iostream>
#include<iomanip>
#include <bitset>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		cout <<' '<< bitset<8>(n) << ' ' << hex << setw(2) << setfill('0') << n <<endl;
	}
}