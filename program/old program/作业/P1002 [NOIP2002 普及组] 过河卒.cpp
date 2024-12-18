/*
#include <iostream>
using namespace std;
long long a[24][24] = { 0 };
const int fx[] = { 0, -2, -1, 1, 2, 2, 1, -1, -2 };
const int fy[] = { 0, 1, 2, 2, 1, -1, -2, -2, -1 };


int main()
{
	int n, m, hn, hm, c[24][24] = { 0 };
	
	cin >> n >> m >> hn >> hm;
	n += 2; m += 2; hm += 2; hn += 2;
	for (int i = 0; i <= 8; i++) c[hn + fx[i]][hm + fy[i]] = 1;
	a[2][2] = 1 - c[2][2];
	for (int i = 2; i <= n+1; i++)
	{
		for (int j = 2; j <= m+1; j++)
		{
			if (c[i][j])continue;
			if (j - 1 >= 0)
			{
				a[i][j] += a[i][j - 1];
			}
			if (i - 1 >= 0)
			{
				a[i][j] += a[i - 1][j];
			}
		}
	}
	cout << a[n][m] << endl;
	return 0;
}
*/