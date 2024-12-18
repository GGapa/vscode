/*
#include <iostream>
#include <algorithm>
using namespace std;
int a[1000000];
int main()
{
	int n, m;
	long long mi, ma;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	mi = a[0];
	ma = a[n - 1];
	long long temp1 = -1, temp2 = -1, temp3, temp4;
	temp1 = mi;
	for (int i = 0; i < m; i++)
	{
		if (temp1 <= 2)
		{
			temp1 -= 2;
		}
		else
		{
			temp1 /= 2;
		}
	}
	if (ma <= 1)
	{
		temp2 = ma + 2;
		for (int i = 0; i < m - 1; i++)
			temp2 *= 2;
	}
	else
	{
		temp2 = ma;
		for (int i = 0; i < m; i++)
			temp2 *= 2;
	}
	cout << max(a[n - 1] - temp1, temp2 - a[0]) << endl;
	return 0;
}
*/