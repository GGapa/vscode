/*
#include <iostream>
#include <queue>
using namespace std;
#define maxn 205
int x[maxn];
bool bj[maxn] = { true };
struct an_
{
	int step, num;
};
queue<an_>y;
int main()
{
	for (int i = 0; i < maxn; i++)
		bj[i] = true;
	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	an_ ls;
	ls.num = a;
	ls.step = 0;
	y.push(ls);
	while (!y.empty())
	{
		if (y.front().num + x[y.front().num] <= n && bj[y.front().num + x[y.front().num]])
		{
			ls.num = y.front().num + x[y.front().num];
			ls.step = y.front().step + 1;
			bj[y.front().num + x[y.front().num]] = false;
			y.push(ls);
		}
		if (y.front().num - x[y.front().num] >= 1 && bj[y.front().num - x[y.front().num]])
		{
			ls.num = y.front().num - x[y.front().num];
			ls.step = y.front().step + 1;
			bj[y.front().num - x[y.front().num]] = false;
			y.push(ls);
		}
		if (y.front().num == b)
		{
			cout << y.front().step << endl;
			return 0;
		}
		y.pop();
	}
	cout << -1 << endl;
	return 0;
}

*/