/*
#include <iostream>
#include <algorithm>
#include <limits.h>
#define maxn 300005
using namespace std;
long long a[maxn], b[maxn], n, m = INT_MIN, ans = 0;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		b[i] = a[i] + n - i + 1;
	}
	for (int i = 1; i <= n; i++)
		m = max(m, b[i]);
	for (int i = n; i >= 1; i--)
		if (a[i] + n >= m)
			ans++;
	cout << ans << endl;
	return 0;
}
*/