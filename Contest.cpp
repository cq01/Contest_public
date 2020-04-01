//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define clr_0(A) memset((A),0,sizeof(A))
//#define DEBUG
constexpr int maxn = 1e6;
template<typename T>
class Average
{
	T sum;
	int n;
public:
	Average() :sum(), n() {}
	void add(T x)
	{
		sum += x;
		++n;
	}
	T cal() { return sum / n; }
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
	Average<int> A;
	Average<double> B;
	int x;
	double y;
	for (int i = 0; i < 3; ++i)
	{
		cin >> x, A.add(x);
	}
	for (int i = 0; i < 3; ++i)
	{
		cin >> y, B.add(y);
	}
	cout << A.cal() << endl << setprecision(3) << fixed << B.cal() << endl;
}
