/*
#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
using namespace std;

int ans[20][8];

int main()
{
	int a[8] = { 1 };
	int n;
	cin >> n;
	int ls = 0, num = 0;
	for (int i = 0; i < n * 2; i++)
	{
		while (a[n - 1] != 0)
		{
			a[ls]++;
			for (int j = 0; j < n; j++)
			{
				if (accumulate(a,a+n,0) >= n)
				{
					a[j] = 0;
					a[j + 1]++;
					ls++;
					break;
				}
			}
			for (int j = 0; j < n; j++)
			{
				int l = 0;
				if (a[j] != 0)ans[num][l] = a[j];
				{
					l++;
				}
			}
			num++;
		}
	}
	return 0;
}
*/