/*
#include <iostream>
using namespace std;

int bag[40][30000];

int main()
{
	int a[40], v, n;
	cin >> v >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < 30000; i++)
		bag[0][i] = 0;
	for (int i = 0; i < 40; i++)
		bag[i][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			if (a[i - 1] > j)
			{
				bag[i][j] = bag[i - 1][j];
			}
			else
			{
				bag[i][j] = max(bag[i - 1][j], a[i - 1] + bag[i - 1][j-a[i-1]]);
			}
		}
	}
	cout << v - bag[n][v] << endl;
}
*/