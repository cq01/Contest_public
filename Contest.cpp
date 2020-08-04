//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define clr_0(A) memset((A),0,sizeof(A))
//#define DEBUG
constexpr int maxn = int(1e6);

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
	string s;
	while (cin >> s)
	{
		for (auto& v : s)if (v == '5')v = ' ';
		stringstream ss(s);
		vector<ll> num;
		ll x;
		while (ss >> x)
		{
			num.push_back(x);
		}
		sort(num.begin(), num.end());
		auto it = num.begin();
		cout << *it;
		++it;
		while (it != num.end())
		{
			cout << ' ' << *it;
			++it;
		}
		cout << endl;
	}
}
