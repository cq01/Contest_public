//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define clr_0(A) memset((A),0,sizeof(A))
//#define DEBUG
class Employee
{
public:
	char name[256];
	Employee* next;
	Employee() :name(), next() {}
	virtual int pay() = 0;

protected:
	static int basic;
};
int Employee::basic = 2000;
class Teacher :public Employee
{
	static int levelpay[3];
public:
	int level;
	int classtime;
	Teacher() :level(), classtime() {}
	int pay()
	{
		return basic + classtime * levelpay[level - 1];
	}
};
int Teacher::levelpay[3] = { 50,30,20 };
class Admin :public Employee
{
public:
	int work;
	Admin() :work() {}
	int pay()
	{
		return basic + work;
	}
};
class Worker :public Employee
{
	static int payperday;
public:
	int day;
	Worker() :day() {}
	int pay()
	{
		return basic + payperday * day;
	}
};
int Worker::payperday = 20;
Employee* read()
{
	Employee* head = new Teacher;
	Teacher* p = static_cast<Teacher*>(head);
	Teacher* q = p;
	while (cin >> p->name >> p->level >> p->classtime)
	{
		q = p;
		p = static_cast<Teacher*>(p->next = new Teacher());
	}
	delete static_cast<Teacher*>(p);
	q->next = nullptr;
	return head;
}
void print(Employee* head)
{
	int sum = 0, cnt = 0, low = INT_MAX, high = INT_MIN;
	for (auto p = head; p; p = p->next)
	{
		const int& ppay = p->pay();
		sum += ppay;
		++cnt;
		low = min(low, ppay);
		high = max(high, ppay);
	}
	cout << sum << endl << sum / cnt << endl << high << endl << low << endl;
}
void del(Employee* head)
{
	for (auto p = head; p; )
	{
		auto temp = p;
		p = p->next;
		delete temp;
	}
}
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
	Employee* head = read();
	print(head);
	del(head);
}
