//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include<iostream>
using namespace std;

struct student
{
	int record;
	char name[128];
};
int main()
{
	student stu[10];
	for (int i = 0; i < 10; ++i)
	{
		cin >> stu[i].name >> stu[i].record;
	}
	int a = 0, max = 0;
	for (int j = 0; j < 10; ++j)
	{
		if (stu[j].record > max)
		{
			max = stu[j].record;
			a = j;
		}
	}
	cout << stu[a].name << endl;
}
