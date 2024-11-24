/*
#include <iostream>
#include <queue>
using namespace std;
#define maxn 40
int a[maxn][maxn], k, n,map[maxn][maxn];
int main()
{
	cin >> k;
	n = 1 << k;
	for (int i = 1; i <= n; i++)
	{
		int num = i + 1;
		a[i][1] = i;
		for (int j = 2; j <= n; j++)
		{
			bool bj = true;
			for (int q = i-1; q >= 0; q--)
			{
				if (num == a[q][j]||a[i][j]!=0)
				{
					bj = false;
					break;
				}
			}
			if (bj)
			{
				a[i][j] = num;
				a[num][j] = i;
				num++;
				j = 2;
			}
		}
	}
	for (int i = 1; i <= n; i++)
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