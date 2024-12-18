/*
#include <iostream>
using namespace std;
#define MAXN 1005
int a[MAXN],b[MAXN]={0};
int find(int x)
{
	if (x == a[x])return x;
	return a[x] = find(a[x]);
}
void join(int x,int y)
{
	int ls1 = find(x), ls2 = find(y);
	if (ls1 != ls2)
		a[ls1] = ls2;
}
int main()
{
	int n, m;
	while (cin >> n)
	{
		int ans = 0;
		if (n == 0)
			return 0;
		for (int i = 0; i < MAXN; i++)
		{
			a[i] = i;
			b[i] = 0;
		}
		cin >> m;
		if (m == 0)
		{
			cout << n - 1 << endl;
			break;
		}
		for (int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			join(x, y);
		}
		for (int i = 1; i <= n; i++)
		{
			b[find(i)]++;
		}
		for (int i = 1; i <= n; i++ )
		{
			if (b[i] != 0)
				ans++;
		}
		cout << ans-1 << endl;
	}
	return 0;
}
*/