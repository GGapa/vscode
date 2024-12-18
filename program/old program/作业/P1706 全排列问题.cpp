/*
#include <iostream>
#include <cstdio>
using namespace std;
int n, a[10], ans[10];
void dfs(int x)
{
	if (x > n || x < 1)
	{
		for (int i = 1; i <= n; i++)
			printf("%5d", ans[i]);
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 0)
		{
			ans[x] = i;
			a[i] = 1;
			dfs(x + 1);
			a[i] = 0;
			ans[x] = 0;
		}
	}
}

int main()
{
	cin >> n;
	dfs(1);
	return 0;
}
*/