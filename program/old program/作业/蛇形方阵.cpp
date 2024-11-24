/*
#include <iostream>
using namespace std;

int main()
{
	int i=1, n, j, num = 1, a[10][10] = { 0 }, x=0, y=0, bj = 1;
	cin >> n;
	bj = n;
	for (; i <= n * n;)
	{
		while (y++ < n && a[x][y] == 0)
			a[x][y] = i++;
		y--;
		while (x++ < n-1 && a[x][y] == 0)
			a[x][y] = i++;
		x --;
		while (y-- >1 && a[x][y] == 0)
			a[x][y] = i++;
		y++;
		while (x-- >1 && a[x][y] == 0)
			a[x][y] = i++;
		x++;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 1; j < n+1; j++)
			printf("%3d", a[i][j]);
		cout << endl;
	}
	return 0;
}
*/