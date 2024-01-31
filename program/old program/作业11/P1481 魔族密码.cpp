/*
#include <iostream>
#include <string>
using namespace std;
#define maxn 2005
string a[maxn];
int dp[maxn],n,ans=0;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		dp[i] = 1;
		for (int j = i - 1; j >= 1; j--)
		{
			if (a[i].find(a[j]) == 0)
			{
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}
*/