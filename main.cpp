//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <bits/stdc++.h>
using namespace std;

#define clr(A) memset((A),0,sizeof(A))
int search(int a, int b);
int total(int n)
{
	if (!n)
	{
		return 0;
	}
	int sum = 0;
	int maxShu = n / 2;
	for (int i = 0; i <= maxShu; i++)
	{
		sum += search(n - 2 * i, i);
	}
	return sum;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n;
	/*for (int i = 1; i < 100; i++)
	{
		cout << i <<' '<< log(total(i))/i << endl;
	}*/
	while (cin >> n)
	{
		
		cout << total(n) << endl;
	}
}
int place(int a, int b);
int search(int a, int b)//a<=b
{
	if (a > b)
	{
		swap(a, b);
	}//a<=b
	return place(a, b + 1);
}
int place(int a, int b)
{
	if (a == 1)
	{
		return b;
	}
	if (!b)
	{
		return 0;
	}
	if (!a)
	{
		return 1;
	}
	return place(a - 1, b) + place(a, b - 1);
}