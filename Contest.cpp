//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define DEBUG

class Book
{
public:
	string bookname;
	ll price, number;
	Book() :price(), number() {}
	ll display()
	{
		return price * number;
	}
	ll borrow()
	{
		return --number;
	}
	ll restore()
	{
		return ++number;
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
	Book aBook;
	char op;
	while (cin >> aBook.bookname >> aBook.price >> aBook.number)
	{
		cout << aBook.bookname << ' ' << aBook.price << ' ' << aBook.number << endl;
		for (int i = 0; i < 5; ++i)
		{
			cin >> op;
			switch (op)
			{
			case 'B':
				cout << aBook.borrow() << endl; break;
			case 'R':
				cout << aBook.restore() << endl; break;
			case 'C':
				cout << aBook.display() << endl; break;
			default:
				break;
			}
		}
	}
}