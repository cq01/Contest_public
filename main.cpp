//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define clr_0(A) memset((A),0,sizeof(A))
//#define DEBUG
constexpr int maxn = int(1e5);

template<typename T>
class Mat
{
public:
	vector<vector<T> > matrix;
	void read(int n)
	{
		matrix.resize(n);
		for (auto& l : matrix)
		{
			l.resize(n);
			for (auto& v : l)cin >> v;
		}
	}
	void print_max()
	{
		int n = matrix.size();
		for (int i = 0; i < n; ++i)
		{
			if (i)cout << ' ';
			auto maxnum = matrix[0][i];
			for (int j = 0; j < n; ++j)
			{
				maxnum = max(maxnum, matrix[j][i]);
			}
			cout << maxnum;
		}
		cout << endl;
	}
	void print_90()
	{
		int n = matrix.size();
		for (int i = 0; i < n; ++i)
		{

			for (int j = n - 1; j >= 0; --j)
			{
				if (j != n - 1)cout << ' ';
				cout << matrix[j][i];
			}
			cout << endl;
		}
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
	int n;
	Mat<int> Mi;
	Mat<char> Mc;
	while (cin >> n)
	{
		Mi.read(n);
		Mc.read(n);
		Mi.print_max();
		Mi.print_90();
		Mc.print_max();
		Mc.print_90();
	}
		}
