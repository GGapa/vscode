/*
#include <iostream>
#include <limits.h>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define maxn 20
double x[maxn], y[maxn], ti = 0;
double ans = INT_MAX, len[maxn][maxn], f[maxn][34000];
int n;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			len[i][j] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
		}
	}
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < 34000; j++)
			f[i][j] = INT_MAX;
	for (int i = 1; i <= n; i++)
		f[i][(1 << i - 1)] = len[0][i];
	for (int q = 1; q < (1 << n); q++)
	{
		for (int i = 1; i <= n; i++)
		{
			if ((q & (1 << i - 1)) == 0)continue;
			for (int j = 1; j <= n; j++)
			{
				if ((q & (1 << j - 1)) == 0 || i == j)continue;
				f[i][q] = min(f[i][q], f[j][q - (1 << (i - 1))] + len[i][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		ans = min(ans, f[i][(1 << n) - 1]);
	}
	printf("%.2f", ans);
	return 0;
}
*/