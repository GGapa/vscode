/*
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define maxn 10001
int x[maxn], y[maxn], n;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];
	sort(x + 1, x + n + 1); sort(y + 1, y + n + 1);
	int X, Y;
	for (int i = 1; i <= n; i++)x[i] -= i; sort(x + 1, x + n + 1);
	n % 2 == 0 ? (X = (x[n / 2] + x[n / 2 + 1]) / 2) : (X = x[n / 2 + 1]);
	n % 2 == 0 ? (Y = (y[n / 2] + y[n / 2 + 1]) / 2) : (Y = y[n / 2 + 1]);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += abs(x[i] - X)+abs(y[i]-Y);
	}
	cout << ans << endl;
	return 0;
}
*/