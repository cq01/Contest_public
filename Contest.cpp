//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define clr_0(A) memset((A),0,sizeof(A))
//#define DEBUG
constexpr int maxn = int(1e6);

class Good
{
public:
	static int cnt;
	static double discount, sum;
	Good(int num, double price)
	{
		cnt += num;
		sum += price * discount * num * (num >= 10 ? 0.98 : 1);
	}
};
int Good::cnt = 0;
double Good::discount = 1, Good::sum = 0;
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
	int n, m, num;
	double p, d;
	while (cin >> n)
	{
		while (n--)
		{
			Good::sum = 0;
			Good::cnt = 0;
			cin >> d >> m;
			Good::discount = 1 - d;
			while (m--)
			{
				cin >> num >> p;
				Good(num, p);
			}
			cout << Good::sum << ' ' << Good::sum / Good::cnt << endl;
		}
	}

}
