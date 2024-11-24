/*
#include <iostream>
#include <algorithm>
using namespace std;
int a[10000010];
int b[10000010];
int main()
{
	int i, j, n, m;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[n - i + 1] = a[i];
	}
	int mina = 1000000007, minb = 1000000007, maxx = 0;
	for (i = 1; i <= n; i++)
	{
		a[i] -= i;
		b[i] -= i;
		maxx = max(maxx, a[i] - mina);
		maxx = max(maxx, b[i] - minb);
		mina = min(mina, a[i]);
		minb = min(minb, b[i]);
	}
	printf("%d", maxx - 1);
	return 0;
}
*/