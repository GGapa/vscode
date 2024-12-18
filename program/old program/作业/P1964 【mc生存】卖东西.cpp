/*
#include <map>
#include <iostream>
#include <string>
#include <limits.h>
using namespace std;
#define maxn 1005
int m, n;
int w[1500005], dp[maxn], ma = 0;
map<string, int>a, b, c;
map<string, bool>bj;
string name[maxn];
int main()
{
	cin >> m >> n;
	m = 21 - m;
	int in1, in2, in3;
	for (int i = 1; i <= n; i++)
	{
		cin >> in1 >> in2 >> in3;
		cin >> name[i];
		a[name[i]] += in1;
		b[name[i]] = in2;
		c[name[i]] = in3;
	}
	int f = 0;
	for (int i = 1; i <= n; i++)
	{
		if (bj[name[i]] == false)
		{
			bj[name[i]] = true;
			while (a[name[i]] >= c[name[i]])
			{
				w[++f] = b[name[i]] * c[name[i]];
				a[name[i]] -= c[name[i]];
			}
			if (a[name[i]])
				w[++f] = b[name[i]] * a[name[i]];
		}
	}
	for (int i = 1; i <= f; i++)
	{
		for (int j = m; j >= 1; j--)
		{
			dp[j] = max(dp[j], dp[j - 1] + w[i]);
			ma = max(ma, dp[j]);
		}
	}
	cout << ma << endl;
	return 0;
}
*/