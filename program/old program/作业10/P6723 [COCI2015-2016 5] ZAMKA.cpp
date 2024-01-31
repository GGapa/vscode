/*
#include <iostream>
using namespace std;

int main()
{
	int l, d, x, n, m;
	cin >> l >> d >> x;
	for (int i = l; i <= d; i++)
	{
		int num = i, all = 0,ls=0;
		while (num > 0)
		{
			ls =+ num % 10;
			num /= 10;
			all += ls;
		}
		if (all == x)
		{
			n = i;
		}
	}
	for (int i = d; i >= l; i--)
	{
		int num = i, all = 0,ls=0;
		while (num > 0)
		{
			ls = num % 10;
			num /= 10;
			all += ls;
		}
		if (all == x)
		{
			m = i;
		}
	}
	cout << m << endl << n << endl;
	return 0;
}
*/