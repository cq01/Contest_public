//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define clr_0(A) memset((A),0,sizeof(A))
//#define DEBUG

class Integer
{
protected:
	int n;
};
class Vector :public Integer
{
protected:
	int* v;
	//vector<int> v;
public:
	void set(int _n)
	{
		n = _n;
		v = new int[n]();
		//v.clear();
		//v.resize(n);
		for (int i = 0; i < n; ++i)cin >> v[i];
	}
	const Vector& print()const
	{
		for (int i = 0; i < n; ++i)
		{
			if (i)cout << ' ';
			cout << v[i];
		}
		cout << endl;
		return *this;
	}
	Vector operator+(const Vector& ano)const
	{
		Vector ret;
		ret.n = n;
		ret.v = new int[n]();
		//ret.v.resize(n);
		for (int i = 0; i < n; ++i)ret.v[i] = v[i] + ano.v[i];
		return ret;
	}

	Vector operator-(const Vector& ano)const
	{
		Vector ret;
		ret.n = n;
		ret.v = new int[n]();
		//ret.v.resize(n);
		for (int i = 0; i < n; ++i)ret.v[i] = v[i] - ano.v[i];
		return ret;
	}
	int operator*(const Vector& ano)const
	{
		int ret = 0;
		for (int i = 0; i < n; ++i)ret += v[i] * ano.v[i];
		return ret;
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
	int num;
	Vector v1, v2;
	while (cin >> num)
	{
		v1.set(num);
		v2.set(num);
		(v1 + v2).print();
		(v1 - v2).print();
		cout << v1 * v2 << endl;
	}
}