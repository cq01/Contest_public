//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define clr_0(A) memset((A),0,sizeof(A))
//#define DEBUG
constexpr int maxn = 1e6;
int nxt[maxn];
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
	int n, m;
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; ++i)
		{
			nxt[i] = i + 1;
		}
		nxt[n - 1LL] = 0;
		int cnt = n;
		int cur = 0;
		int call = 0;
		while (cur != nxt[cur])
		{
			++call;
			if (call >= m - 1)
			{
				call = 0;
				nxt[cur] = nxt[nxt[cur]];
			}
			cur = nxt[cur];
		}
		cout << cur << endl;
	}
}
