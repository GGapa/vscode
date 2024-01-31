/*
#include <iostream>
using namespace std;
#define maxn 50
int n, a[maxn][maxn]={0}, num = 0, ans = 0, bj[maxn][maxn], b[maxn], bx[maxn], by[maxn], bd1[maxn], bd2[maxn], conum = 0;
void dfs1(int x)
{
	if (x >= n)
	{
		if (ans < 3)
		{
			for (int i = 0; i < n; i++ )
			{
				cout << b[i]+1 << " ";
			}
			cout << endl;
		}
		ans++;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if ( by[i] == 0 && bd1[i + x] == 0 && bd2[i - x + n] == 0)
		{//就表示这个点能取
			b[x] = i;
			//bx[x] = 1;
			by[i] = 1;
			bd1[i + x] = 1;
			bd2[i - x + n] = 1;
			//cout << x << endl;
			dfs1(x + 1);
			b[x] = by[i] = bd1[i + x] = bd2[i - x + n] = 0;
		}
	}
}

int main()
{
	cin >> n;
	dfs1(0);
	cout << ans << endl;
	return 0;
}

*/