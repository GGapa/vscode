/*
#include <iostream>
using namespace std;

int main()
{
	int a[1000], n, i, ls;
	double all=0.0, ans;
	bool bj = true;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	while (bj)
	{
		bj = false;
		for (i = 0; i < n-1; i++)
		{
			if (a[i] > a[i + 1])
			{
				ls = a[i + 1];
				a[i + 1] = a[i];
				a[i] = ls;
				bj = true;
			}
		}
	}
	a[0] = 0;
	a[n - 1] = 0;
	for (i = 0; i < n; i++)
	{
		all += a[i];
	}
	ans = all / double(n-2);
	printf("%.2f", ans);
	return 0;
}
*/