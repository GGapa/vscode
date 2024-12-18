/*
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int n, a[10][2], b[10] = { 0 }, s = 1, k = 0, ls = 1,ans=99999999;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i][0] >> a[i][1];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			b[j] = 1;
		}
		for (int j = 0; j < ls; j++)
		{
			b[j] = 2;
		}
//.		b[3] = 2;
		while (next_permutation(b, b + n));
		{
			for (int q = 0; q < n; q++)
			{
				if (b[q] == 2)
				{
					s *= a[q][0]; k += a[q][1];
				}
			}
		}
		int ls1 = fabs(s - k);
		ans = min(ls1, ans);
		s = 1; k = 0;
		ls++;
	}
	if (n == 1)
	{
		cout << fabs(a[0][0] - a[0][1]) << endl;
		return 0;
	}
	cout << ans << endl;
	return 0;
}
*/