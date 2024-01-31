/*
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int w, n, a[300000];
	cin >> w >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	long long l=0, r=n-1, ans = 0;
	while (l <= r)
	{
		if (a[l] + a[r] <= w)
		{
			l++; r--; ans++;
		}
		else
		{
			r--; ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
*/