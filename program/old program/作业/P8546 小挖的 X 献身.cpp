/*
#include <iostream>
#include <limits.h>
using namespace std;
#define re xx = x; yy = y
int map[101][101], n;
long long ans=0;
bool cheak(int x, int y)
{
	return x > 0 && y > 0 && x <= n && y <= n && map[x][y] == 1;
}
void dfs1(int x, int y)
{
	int sum1, sum2, sum3, sum4, finallysum = INT_MIN;
	sum1 = sum2 = sum3 = sum4 = 0;
	int xx, yy;
	re;
	while (cheak(xx, yy))xx--, yy--, sum1++;
	re;
	while (cheak(xx, yy))xx--, yy++, sum2++;
	re;
	while (cheak(xx, yy))xx++, yy--, sum3++;
	re;
	while (cheak(xx, yy))xx++, yy++, sum4++;
	finallysum = min(min(min(sum1, sum2), sum3), sum4);
	ans += finallysum - 1;
}
void dfs2(int x, int y)
{
	int sum1, sum2, sum3, sum4, finallysum = INT_MIN;
	sum1 = sum2 = sum3 = sum4 = 0;
	int xx, yy;
	re;
	while (cheak(xx, yy))xx--, yy--, sum1++;
	y++; re;
	while (cheak(xx, yy))xx--, yy++, sum2++;
	y--; x++; re;
	while (cheak(xx, yy))xx++, yy--, sum3++;
	y++; re;
	while (cheak(xx, yy))xx++, yy++, sum4++;
	finallysum = min(min(min(sum1, sum2), sum3), sum4);
	ans += finallysum;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 1; j <= temp.length(); j++)
			map[i][j] = temp[j-1] - '0';
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == 1)
			{
				dfs1(i, j);
			}
			if (map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1)
			{
				dfs2(i, j);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
*/