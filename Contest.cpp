//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define DEBUG

class Student
{
	ll score;
	static ll total, count;
public:
	void scoretotalcount(int s)
	{
		total += score = s;
		++count;
	}
	static ll sum()
	{
		return total;
	}
	static ll average()
	{
		return total / count;
	}
};

ll Student::count = 0;
ll Student::total = 0;
int main()
{
#ifdef DEBUG
	fstream in, out;
	in.open("C:\\Users\\qi010\\Desktop\\cin.txt", ios::in);
	out.open("C:\\Users\\qi010\\Desktop\\cout.txt", ios::app);
	streambuf* stream_buffer_cout = cout.rdbuf();
	streambuf* stream_buffer_cin = cin.rdbuf();
	streambuf* stream_buffer_in = in.rdbuf();
	streambuf* stream_buffer_out = out.rdbuf();
	cin.rdbuf(stream_buffer_in);
	cout.rdbuf(stream_buffer_out);
#endif // DEBUG

	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	Student stu[5];
	ll input;
	for (int i = 0; i < 5; ++i)
	{
		cin >> input;
		stu[i].scoretotalcount(input);
	}
	cout << Student::sum() << ' ' << Student::average() << endl;
}