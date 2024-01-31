/*
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int n,a[10001]={0};
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int l;
		cin >> l >> a[i];
	}
	sort(a+1, a + n+1);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (n % 2 == 0)
		{
			ans += abs((a[n / 2] + a[n / 2 + 1]) / 2 - a[i]);
		}
		else
		{
			ans += abs(a[n / 2 + 1] - a[i]);
		}
	}
	cout << ans << endl;
	return 0;
}
*/