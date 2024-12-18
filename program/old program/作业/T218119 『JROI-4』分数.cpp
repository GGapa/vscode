/*
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int gys(int x, int y)
{
	if (x % y == 0)
	{
		return y;
	}
	else
	{
		gys(y, x % y);
	}
}

int main()
{
	int t, n,n_;
	int ls = 2;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		int z=1,ans=0;
		int m=0;
		bool bj = true;
		for (int j = n; j >= 0; j--)
		{
			bj = true;
			for (int q = sqrt(j); q >= 2; q--)
			{
				if (j % q == 0)
				{
					bj = false;
					break;
				}
			}
			if (bj) {
				m = j;
				break;
			}
		}
		if (bj)
		{
			cout << m << endl;
		}
	}
	return 0;
}
*/