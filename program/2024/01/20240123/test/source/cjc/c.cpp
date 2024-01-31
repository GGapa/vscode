#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 10, mod = 998244353;
int n, m, t, a[N];

mt19937 rd(time(0));

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &t);
	while(t --)
	{
		for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		printf("%d\n", rd() % mod);
	}
	return 0;
}
