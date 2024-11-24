/*
#include <iostream>
#include <cmath>
using namespace std;
#define maxn 1064
int a[maxn][maxn];
int main()
{
	int s, t, n, m;
	cin >> s >> t;
	while (t--)
	{
		int ans = 0;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				a[i][j] = 1;
			}
		}
		cout << (n / 2) * m + (m / 2) * n - (m / 2)*(n/2) << " " << 1 << endl;
	}
}
*/