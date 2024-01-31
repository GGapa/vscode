/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int a[25], n, m;
	double ans = 0,num=0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		num = 0;
		for (int j = 0; j < m; j++)
		{
			cin >> a[j];
			num += a[j];
		}
		sort(a, a + m);
		num -= a[0];
		num -= a[m - 1];
		ans = max(ans, num / (m-2));
	}
	printf("%.2f\n", ans);
	return 0;
}
*/