/*
#include <iostream>
#include <stack>
using namespace std;
#define maxn 5012
int n, k, xq, yq;
int map[maxn][maxn], fx[4] = { -1,-1,1,1 }, fy[4] = { -1,1,-1,1 },
bj[maxn][maxn];
void digui(int x, int y)
{
	int num = 0;
	if (x > n || y > n || x < 1 || y < 1)
		return;
	for (int i = x; i <= x + 1; i++)
	{
		for (int j = y; j <= y + 1; j++)
		{
			if (map[i][j] == 1)
			{
				num++;
			}
		}
	}
	if (num == 1)
	{
		bool br = false;
		for (int i = x; i <= x + 1; i++)
		{
			for (int j = y; j <= y + 1; j++)
			{
				for (int q = 0; q < 4; q++)
				{
					if (i + fx[q] >= x && i + fx[q] <= x + 1 && j + fy[q] >= y && j + fy[q] <= y + 1 &&
						map[i][j] == 0 && map[i + fx[q]][j] == 0 && map[i][j + fy[q]] == 0 &&
						i + fx[q] <= n && j + fy[q] <= n && i <= n && j <= n)
					{
						map[i + fx[q]][j] = map[i][j + fy[q]] = map[i][j] = 1;
						bj[i][j] = q + 1;
						br = true;
						break;
					}
				}
				if (br)
					break;
			}
			if (br)
				break;
		}
		digui(x + 1, y + 1);
		digui(x - 1, y - 1);
		digui(x - 1, y + 1);//?
		digui(x + 1, y - 1);//?
	}
	else
		return;
}
int main()
{
	cin >> k;
	n = 1 << k;
	cin >> xq >> yq;
	map[xq][yq] = 1;
	if (xq % 2 == 0 && yq % 2 != 0)
		digui(xq - 1, yq);
	else if (xq % 2 == 0 && yq % 2 == 0)
		digui(xq - 1, yq - 1);
	else if (xq % 2 != 0 && yq % 2 == 0)
		digui(xq, yq - 1);
	else
		digui(xq, yq);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (bj[i][j] != 0)
			{
				cout << i << " " << j << " " << bj[i][j] << endl;
			}
		}
	}
	return 0;
}
*/