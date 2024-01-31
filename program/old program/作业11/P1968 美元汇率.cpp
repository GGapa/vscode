/*
#include <iostream>
#include <cstdio>
#define maxn 1000000
using namespace std;
int a[maxn];
double dp[maxn][2];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	dp[1][0] = 100;
	dp[1][1] = a[1];
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = max(dp[i - 1][0], (dp[i - 1][1] / a[i]) * 100);
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] * a[i] / 100);
	}
	printf("%.2f\n", max(dp[n][0], (dp[n][1] / a[n]) * 100));
	return 0;
}
*/