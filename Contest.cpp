//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{

	char s[128];
	char op[4];
	int x, n;
	cin >> s;
	string str(s);
	while (cin >> op)
	{
		if (!strcmp(op, "ADD"))
		{
			cin >> s >> x;
			str.insert(++x, s);
			cout << str << endl;
		}
		else if (!strcmp(op, "DEL"))
		{
			cin >> x >> n;
			str.erase(x, n);
			cout << str << endl;
		}
		else if (!strcmp(op, "SER"))
		{
			cin >> s;
			cout << str.find(s) << endl;
		}
		else
		{
			cin >> s >> x;
			str.replace(x, strlen(s), s);
			cout << str << endl;
		}
	}
}
