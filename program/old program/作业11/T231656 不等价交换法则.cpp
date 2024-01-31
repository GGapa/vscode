/*
#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
#define maxn 1000000
long long a[maxn] = { 0 };

int main()
{
	long long n, w, ans = 0, num = -1;
	cin >> n;
	for (long long i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	cin >> w;
	sort(a + 1, a + n + 1);
	w = min(w, a[n]);
	for (int i = 1; i <= n - 1; i++)
		if (ans <= w)
			ans += a[i];
		else
		{
			cout << i - 2 << endl;
			return 0;
		}
	if (ans <= w)
		cout << n - 1 << endl;
	else
		cout << n - 2 << endl;
	return 0;
}
*/