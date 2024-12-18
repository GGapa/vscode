/*
#include <iostream>
using namespace std;
int a[26][3], bag[26][30001] = { 0 }, he = 0;
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		for (int j = 0; j < 2; j++)
			cin >> a[i][j];
	for (int i = 1; i <= m; i++)
	{
		a[i][2] = a[i][0] * a[i][1];
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[i][0] > j)
			{
				bag[i][j] = bag[i - 1][j];
			}
			else
			{
				bag[i][j] = max(bag[i - 1][j], a[i][2]+ bag[i - 1][j - a[i][0]]);
			}
		}
	}
	cout << bag[m][n] << endl;
	return 0;
}
*/