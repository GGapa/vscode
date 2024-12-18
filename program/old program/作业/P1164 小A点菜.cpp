/*
#include <iostream>
using namespace std;

int bag[110][10010] = { 0 };

int main()
{
	int n, m, a[110] = { 0 };
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++)//当前选择几份菜
	{
		for (int j = 1; j <= m; j++)
		{
			if (j == a[i])
			{
				bag[i][j] = bag[i - 1][j] + 1;
			}
			if (j > a[i])
			{
				bag[i][j] = bag[i - 1][j] + bag[i - 1][j - a[i]];
			}
			if (j < a[i])
			{
				bag[i][j] = bag[i - 1][j];
			}
		}
	}
	cout << bag[n][m] << endl;
	return 0;
}
*/