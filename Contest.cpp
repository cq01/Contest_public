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
	bool flag1 = false;//
	bool flag2 = false;/**/
	bool flag2_2 = false;
	bool flag3 = false;// '
	bool flag4 = false;//"
	char ch;
	while (EOF != (ch = getchar()))
	{
		if (flag2_2)
		{
			flag2_2 = false;
			if (ch == '\n')
				continue;
		}
		if (flag3 || flag4)
		{
			putchar(ch);
			if (ch == '\'')flag3 = false;
			if (ch == '\"')flag4 = false;
			continue;
		}
		if (flag1)
		{
			if (ch == '\n')
			{
				flag1 = false;
				putchar('\n');
			}
			continue;
		}
		if (flag2)
		{
			if (ch == '*' && '/' == (ch = getchar()))
			{
				flag2 = false;
				flag2_2 = true;
			}
			continue;
		}
		if (ch == '/')
		{
			ch = getchar();
			switch (ch)
			{
			case '/':flag1 = true; break;
			case '*':flag2 = true; break;
			default:putchar('/'); putchar(ch); break;
			}
			continue;
		}
		switch (ch)
		{
		case '\'':flag3 = true; break;
		case '\"':flag4 = true; break;
		case '\\':putchar('\\'); ch = getchar(); break;
		default:
			break;
		}
		putchar(ch);
	}
}
