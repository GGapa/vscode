/*
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int n, l, r, a[51], ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> l >> r;
	int x = 0, y = 0;
	int sum;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	if (sum > n * r || sum < n * l)
	{
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] > r)
		{
			x += a[i] - r;
		}
		if (a[i] < l)
		{
			y += l - a[i];
		}
	}
	cout << max(y,x) << endl;
	return 0;
}
*/