//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <iostream>
#include <cstring>
using namespace std;
struct number
{
	number* next;
	char data;
};
void creat(number*& head, char* s);
void readDelete(number* &head);
int main()
{
	number* head = nullptr;
	char s[256] = { 0 };
	while (cin >> s)
	{
		creat(head, s);
		readDelete(head);
	}

}

void creat(number*& head, char* s)
{
	number* p = nullptr, * last = nullptr;
	int n = (int)strlen(s);
	for (int i = n - 1; i >= 0; --i)
	{
		p = last;
		last = new number;
		last->data = *(s + i);
		if (head == nullptr)
		{
			head = last;
			p = head;
		}
		else
		{
			if (p != nullptr)
			{
				p->next = last;
			}
		}
	}
	if (last != nullptr)
	{
		last->next = nullptr;
	}
	p = nullptr;
	last = nullptr;
}
void readDelete(number* &head)
{
	number* pt = nullptr;
	while (head != nullptr)
	{
		cout << head->data;
		pt = head;
		head = pt->next;
		delete pt;
	}
	pt = nullptr;
	head = nullptr;// head 不为nullptr 下次调用会有异常
	cout << endl;
}