/*
#include <iostream>
using namespace std;
int a[105], b[105] = { 0 }, c[105] = { 0 }, n, bi = 0, ci = 0, ans = 0, num;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = c[i] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j] && b[i] <= b[j] + 1)
				b[i] = b[j] + 1;
		}
	}
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = n - 1; j >= i; j--)
		{
			if (a[i] > a[j] && c[i] <= c[j] + 1)
				c[i] = c[j] + 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		num = c[i] + b[i] - 1;
		ans = max(num, ans);
	}
	cout << n - ans << endl;
}

*/