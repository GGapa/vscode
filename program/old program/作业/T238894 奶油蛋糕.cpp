/*
#include <iostream>
#include <string>
using namespace std;
#define maxn 55
int main()
{
	long long n, m, x, y, a[maxn][maxn] = { 1 }, kx, ky, add[maxn][maxn];
	string move;
	cin >> n >> m >> x >> y >> move;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			add[i][j] = 1;
		}
	}
	for (int i =0; i < m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int q = 1; q <= n; q++)
			{
				if (j != y || x != q)
				{
					a[j][q] += add[j][q];
					add[j][q]++;
				}
			}
		}
		add[y][x] = 1;
		if (move[i] == 'N')
			y++;
		if (move[i] == 'S')
			y--;
		if (move[i] == 'W')
			x--;
		if (move[i] == 'E')
			x++;
	}
	for (int i = n; i > 0; i--)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
*/