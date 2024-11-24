/*
#include <iostream>
#include <limits.h>
using namespace std;
#define maxn 21
int n, cnt, a[maxn], temp[maxn], rela[maxn][maxn], an[maxn], mans = INT_MIN, num = 0, man[maxn] = { 0 }, ans;
void dfs(int x)
{
	bool re = true;
	for (int i = 1; i <= n; i++)
	{
		if (rela[x][i] == 1)
		{
			re = false;
		}
	}
	if (re)
	{
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (x == i)continue;
		if (rela[x][i] == 1)
		{

			an[num++] = i;
			ans += a[i];
			dfs(i);

			if (ans > mans)
			{
				mans = ans;
				cnt = num;
				for (int j = 0; j < num; j++)
					man[j] = an[j];
			}

			num--;
			ans -= a[i];

		}
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			cin >> temp[j];
			rela[i][j] = temp[j];
			//rela[j][i] = temp[j];
		}
	}
	mans = 0;
	for (int i = 1; i <= n; i++)
	{
		num = 1;
		ans = a[i];

		//cnt = 1;
		for (int j = 0; j < maxn; j++)
			an[j] = 0;
		an[0] = i;
		dfs(i);
		if (a[i] > mans)
		{
			mans = a[i];
			cnt = 1;
			man[0] = i;
		}
	}
	for (int i = 0; i < cnt; i++)
		cout << man[i] << " ";
	cout << endl;
	cout << mans << endl;
	return 0;
}
*/