/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define maxn 55
int n, a[maxn][maxn], ans[maxn], bj[maxn];
void dfs(int x, int y)
{
	if (x == 1 && y >= 1 + n)
	{
		for (int i = 1; i < y; i++)cout << ans[i] << " ";
		exit(0);
	}
	for (int i = 1; i <= n; i++)
	{
		if (i!=x&&a[x][i] != 0 && (bj[i] == 0 || (i == 1 && y == n)))
		{
			ans[y+1] = i;
			bj[i] = 1;
			dfs(i, y + 1);
			bj[i] = 0;
		}
	}
}
int main()
{
	cin >> n;
	int in1, in2;
	while (scanf_s("%d%d", &in1, &in2) == 2)
	{
		a[in1][in2] = a[in2][in1] = 1;
	}
	ans[1] = bj[1] = 1;
	dfs(1, 1);
	return 0;
}
*/