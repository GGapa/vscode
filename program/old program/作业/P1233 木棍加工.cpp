/*
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 5001
struct st
{
	int l, w;
}a[maxn];
bool cmp(st x, st y)
{
	return x.l != y.l ? (x.l < y.l) : (x.w < y.w);
}
int n, ans = 0, dp[12000];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i].l >> a[i].w;
	sort(a, a + n, cmp);
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j].w > a[i].w)
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans + 1 << endl;
	return 0;
}
*/