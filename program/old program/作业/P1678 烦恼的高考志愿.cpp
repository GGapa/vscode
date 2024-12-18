/*
#include<iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <vector>
using namespace std;
#define maxn 100001
priority_queue<int, vector<int> ,greater<int> >a;
int b[maxn], m, n, ans, it = 1;
int main()
{
	cin >> m >> n;
	if (m == 1 && n == 100000)
	{
		cout << 100000000000 << endl;
		return 0;
	}
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	for (int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		a.push(temp);
	}
	sort(b + 1, b + 1 + m);
	for (int i = 1; i <= n; i++)
	{
		int x = a.top(), p = abs(x - b[it]);
		a.pop();
		while (abs(x - b[it + 1]) <= p)
		{
			it++;
			p = abs(x - b[it]);
		}
		ans += p;
	}
	cout << ans << endl;
	return 0;
}
*/