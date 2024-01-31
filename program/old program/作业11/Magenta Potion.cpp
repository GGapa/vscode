/*
#include <iostream>
#include <limits.h>
using namespace std;
long long a[200005];
long long ma = 1 << 30;
int main()
{
	long long n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++)cin >> a[i];
	while (q--)
	{
		long long input, x, y;
		cin >> input >> x >> y;
		x--, y--;
		if (input == 1)
		{
			a[x] = y;
		}
		long long m = 1, f = 1, out = INT_MIN;
		if (input == 2)
		{
			m = 1; f = 1; out = INT_MIN;
			bool bj = true;
			for (int i = x; i <= y; i++)
			{
				if (a[i] < 0)
				{
					for (int j = i + 1; j <= y; j++)
					{
						if (a[j] < 0)f++;
						if (a[i] == 0)
						{
							m = 1;
							break;
						}
					}
					if (f % 2 == 0)m *= a[i];
					else
					{
						m = 1;
						continue;
					}
				}
				if (a[i] == 0)
				{
					m = 1;
					continue;
				}
				m *= a[i];
				out = max(out, m);
				if (out >= ma)
				{
					cout << "Too large" << endl;
					bj = false;
					break;
				}
			}
			if (bj)cout << m << endl;
		}
	}
	return 0;
}
*/