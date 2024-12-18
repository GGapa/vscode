/*
#include <iostream>
#include <cmath>
using namespace std;
long long a[100000000], num = 1;
int main()
{
	long long t, n;
	cin >> t;
	a[0] = 2;
	for (int i = 3; i < 100; i++)
	{
		bool bj = true;
		for (int j = 2; j < sqrt(i) + 1; j++)
		{
			if (i % j == 0)
			{
				bj = false;
				break;
			}
		}
		if (bj)
			a[num++] = i;
	}
	while (t--)
	{
		long long ans = 0;
		bool bj = true, br = false;
		cin >> n;
		while (bj)
		{
			bj = false;
			for (long long y = 0; y < a[n]; y++)
			{
				for (long long z = 1; z < a[n]; z++)
				{
					long long x = pow(a[y], a[z]);
					if (x > n)
					{
						br = true;
						break;
					}
					if (n % x== 0)
					{
						ans++;
						bj = true;
						n /= x;
						break;
					}
				}
				if (br)
				{
					br = false;
					continue;
				}
			}
		}
		cout << (ans) << endl;
	}
	return 0;
}
*/