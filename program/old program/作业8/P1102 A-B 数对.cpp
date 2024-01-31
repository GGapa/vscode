/*
#include <iostream>
#include <algorithm>
using namespace std;
long long a[200000], n, s, ans = 0;

int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int r1 = 0, r2 = 0;
	for (int i = 0; i <n; i++)
	{
		while (r1 < n && a[r1] - a[i] <= s)r1++;
		while (r2 < n && a[r2] - a[i] < s)r2++;
		if(r1-r2>0)ans += r1 - r2;
	}
	cout << ans << endl;
	return 0;
}
*/