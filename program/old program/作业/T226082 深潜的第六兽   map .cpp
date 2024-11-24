/*
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
using namespace std;
long long ans = 0;
#define maxn 500005
struct island_
{
	long long l, r, h;
};
map<long long, island_>island;
long long  n, m, x , mh;
int paixu(island_ temp1, island_ temp2)
{
	return temp1.h > temp2.h;
}

void dfs(long long a, long long h)
{
	bool bj = true;
	if (h <= 0)
	{
		ans++;
		ans %= 998244353;
		return;
	}
	for (int i = mh; i >= 0; i--)
	{
		if (island[i].l <= a && island[i].r >= a && island[i].h <= h)
		{
			bj = false;
			dfs(island[i].l, island[i].h - 1);
			dfs(island[i].r, island[i].h - 1);
			return;
		}
	}
	if (bj)
	{
		ans++;
		ans %= 998244353;
		return;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		island_ temp;
		cin >> temp.l >> temp.r >> temp.h;
		mh = max(temp.h, mh);
		island.insert({ temp.h, temp });
	}
	//sort(island.begin(), island.end(), paixu);
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		dfs(x, 1000000000);
	}
	cout << ans << endl;
	return 0;
}

*/