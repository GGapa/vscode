/*
#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;
#define maxn 10005
int a[maxn], hi[maxn], ans = 1, num = 0;
int dp[10005] = { 0 };
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int ml=0,len=1;
	dp[1] = a[1];
	for (int i = 2; i <= n; i++)
	{
		if (dp[len] < a[i])
		{
			dp[++len] = a[i];
		}
		else
		{
			for (int j = 1;; j++)
			{
				if (dp[j] >= a[i]) 
				{
					dp[j] = a[i];
					break;
				}
			}
		}
	}
	cout << len << endl;
	return 0;
}
*/