//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <bits/stdc++.h>
using namespace std;

#define clr(A) memset((A),0,sizeof(A))
struct Reduce
{
	int sum;
	int r;
};
bool operator<(const Reduce& x, const Reduce& y)
{
	return x.r > y.r;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n;
	while (cin >> n)
	{
		int goodPrice;
		bool is8;
		double sum1 = 0;
		double sum2 = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> goodPrice;
			cin >> is8;
			sum1 += (is8 ? (goodPrice * 0.8) : goodPrice);
			sum2 += goodPrice;
		}
		int m;
		cin >> m;
		//priority_queue<Reduce,queue<Reduce>,less<Reduce>> plan;
		vector<Reduce> plan(m);
		for (int i = 0; i < m; ++i)
		{
			Reduce x;
			cin >> x.sum >> x.r;
			plan.push_back(x);
		}
		sort(plan.begin(), plan.end());
		//while (!(plan.empty()))
		for (int i = 0; i < m; i++)
		{
			const Reduce& x = plan[i];
			if (sum2 >= x.sum)
			{
				sum2 -= x.r;
				break;
			}
		}
		cout << fixed << setprecision(2) << min(sum1, sum2) << endl;
	}
}

