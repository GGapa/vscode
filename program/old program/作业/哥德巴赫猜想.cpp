/*
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	int i, j, q, n, a[10000] = {0}, b = 1;
	bool bj;
	cin >> n;
	a[0] = 2;
	for (i = 3; i < n; i+=2)
	{
		bj = true;
		for (j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				bj = false;
				break;
			}
		}
		if (bj)
		{
			a[b] = i;
			b++;
		}
	}
	for (i = 4; i <= n; i += 2)
	{
		bj = false;
		for (j = 0; j < 10000; j++)
		{
			for (q = 0; q < 10000; q++)
			{
				if (a[j] + a[q] == i)
				{
					printf("%d=%d+%d\r\n", i, a[j], a[q]);
					bj = true;
					break;
				}
			}
			if (bj)break;
		}
	}
	return 0;
}
*/