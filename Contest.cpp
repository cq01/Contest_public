//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define clr_0(A) memset((A),0,sizeof(A))
//#define DEBUG

class Vector
{
private:
	vector<ll> val;
public:
	void read(size_t num)
	{
		val.clear();
		val.resize(num);
		for (auto& v : val) cin >> v;
	}
	void print()
	{
		for (int i = 0; i < val.size(); ++i)
		{
			if (i)cout << ' ';
			cout << val[i];
		}
		cout << endl;
	}
	friend Vector operator+(const Vector& a, const Vector& b);
	friend Vector operator-(const Vector& a, const Vector& b);
	friend ll operator*(const Vector& a, const Vector& b);
};
Vector operator+(const Vector& a, const Vector& b)
{
	Vector ret;
	ret.val.clear();
	ret.val.resize(a.val.size());
	for (int i = 0; i < ret.val.size(); ++i)
	{
		ret.val[i] = a.val[i] + b.val[i];
	}
	return ret;
}
Vector operator-(const Vector& a, const Vector& b)
{
	Vector ret;
	ret.val.clear();
	ret.val.resize(a.val.size());
	for (int i = 0; i < ret.val.size(); ++i)
	{
		ret.val[i] = a.val[i] - b.val[i];
	}
	return ret;
}
ll operator*(const Vector& a, const Vector& b)
{
	ll ret = 0;
	for (int i = 0; i < a.val.size(); ++i)
	{
		ret += a.val[i] * b.val[i];
	}
	return ret;
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
	char op;
	size_t num;
	Vector a, b;
	while (cin >> op >> num)
	{
		a.read(num);
		b.read(num);
		switch (op)
		{
		case '+':(a + b).print(); break;
		case '-':(a - b).print(); break;
		case '*':cout << a * b << endl; break;
		default:
			break;
		}
	}
}