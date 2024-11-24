/*
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, a[1000];
	bool bj = true;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		int ls = fabs(a[i] - a[i + 1]);
		bj = false;
		for (int j = 1; j <= n-1; j++)
		{
			if (ls == j)
			{
				bj = true;
				break;
			}
		}
		if (!bj)
		{
			cout << "Not jolly" << endl;
			return 0;
		}
	}
	cout << "Jolly" << endl;
	return 0;
}
*/