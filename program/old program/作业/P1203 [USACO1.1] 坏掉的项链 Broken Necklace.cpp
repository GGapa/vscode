/*
#include <iostream>
#include <limits.h>
#define maxn 355*3
using namespace std;
int n, b[maxn], ans = 1, sum = 0;
char a[maxn];
int cheak(int x)
{
	if (x < 0)
		return n - 1;
	if (x >= n)
		return 0;
	else
		return x;
}
int main()
{
	cin >> n >> a;
	for (int i = 0; i < n; i++)
	{
		int it1 = i;
		char v = a[it1];
		sum = 0;
		it1 = cheak(it1);
		while (a[it1] == v || a[it1] == 'w' || v == 'w')
		{
			if (sum > n)
			{
				sum--;
				break;
			}
			if (v == 'w' && a[it1] != 'w')
				v = a[it1];
			sum++;
			it1++;
			it1 = cheak(it1);
		}
		it1 = i - 1;
		it1 = cheak(it1);
		v = a[it1];
		while (a[it1] == v || a[it1] == 'w' || v == 'w')
		{
			if (sum > n)
			{
				sum--;
				break;
			}
			if (v == 'w' && a[it1] != 'w')
				v = a[it1];
			sum++;
			it1--;
			it1 = cheak(it1);
		}
		ans = max(ans, sum);
	}
	cout << min(ans, n) << endl;
	return 0;
}
*/