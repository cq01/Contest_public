//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define DEBUG

class Box
{
	ll length, width, height;
public:
	Box() = default;
	Box(ll l, ll w, ll h) :length(l), width(w), height(h) {}
	void setBox(ll l, ll w, ll h)
	{
		length = l;
		width = w;
		height = h;
	}
	ll volume()
	{
		return length * width * height;
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
	ll l, w, h;
	Box a;
	while (cin >> l >> w >> h)
	{
		a.setBox(l, w, h);
		cout << a.volume() << endl;
	}
}