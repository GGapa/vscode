/*
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int num=2, i, n, q,ge=1;
	bool bj = true;
	cin >> n;
	if (n < 2)
	{
		cout << 0 << endl;
		return 0;
	}
	cout << 2 << endl;
	for (i = 2; i <= n; i++)
	{
		bj = true;
		for (q = 2; q <= (sqrt(i) + 1); q++)
		{
			if (i % q == 0)
			{
				bj = false;
			}
		}
		if (bj)
		{
			if ((num += i) > n) break;
			ge++;
			cout << i << endl;
		}
	}
	cout << ge << endl;
	return 0;
}
*/