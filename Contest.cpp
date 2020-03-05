//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define clr_0(A) memset((A),0,sizeof(A))
//#define DEBUG

class Employee
{
protected:
	string name, number;
	double basicSalary;
public:
	Employee() :basicSalary(2000) {}
	void input()
	{
		cin >> number >> name;
	}
	double pay()
	{
		return basicSalary;
	}
	void print()
	{
		cout << name << ' ' << number << ' ' << pay() << endl;
	}
};
class Salesman :protected Employee
{
protected:
	double sales;
	static double commrate;
public:
	Salesman() :sales() {}
	void input()
	{
		Employee::input();
		cin >> sales;
	}
	double pay()
	{
		return Employee::pay() + sales * commrate;
	}
	void print()
	{
		cout << name << ' ' << number << ' ' << pay() << endl;
	}
};
double Salesman::commrate = 5e-3;
class Salesmanager :protected Salesman
{
protected:
	double jobSalary;
public:
	Salesmanager() :jobSalary(3000) {}
	void input()
	{
		Salesman::input();
	}
	double pay()
	{
		return Salesman::pay() + jobSalary;
	}
	void print()
	{
		cout << name << ' ' << number << ' ' << pay() << endl;
	}
};
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
	Employee a;
	Salesman b;
	Salesmanager c;
	a.input();
	b.input();
	c.input();
	a.print();
	b.print();
	c.print();
}