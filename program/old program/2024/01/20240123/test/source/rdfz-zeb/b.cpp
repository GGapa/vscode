//#pragma GCC optimize(3)
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
const ll MOD = 1e9 + 7;
const int N = 810;

vector <int> G1[N], G2[N];
ll f[N][N];
int n1, g[N][N], n2, m, son2[N][N], sz1[N], sz2[N], s[N], cnt;

void dfs1(int x)
{
	sz1[x] = 1;
	for(auto& y : G1[x]) dfs1(y), sz1[x] += sz1[y];
	for(int y = 1; y <= n2; y++)
	{
		if(sz1[x] > sz2[y]) continue;
		for(int i = 1; i <= cnt; i++)
		{
			int len = s[i] - 1;
			if(son2[y][len] != -1)
			{
				int ny = son2[y][len];
				if(G1[x].size() == G2[ny].size())
				{
					ll v;
					if(g[x][ny] != -1)
					{
						v = g[x][ny];
					}
					else
					{
						v = 1;
						for(int j = 0; j < G1[x].size(); j++)
						{
							v = v * f[G1[x][j]][G2[ny][j]] % MOD;
						}
						g[x][ny] = v;
					}
					f[x][y] += v;
					if(f[x][y] >= MOD) f[x][y] -= MOD;
				}
			}
			else break;
		}
	}
}

void dfs2(int x)
{
	sz2[x] = 1;
	for(auto& y : G2[x])
	{
		dfs2(y);
		sz2[x] += sz2[y];
	}
	son2[x][0] = x;
	if(G2[x].size() > 1)
	{
		for(int j = 1; j <= n2; j++) son2[x][j] = -1;
	}
	else if(G2[x].size() == 1)
	{
		for(int j = 1; j <= n2; j++)
		{
			son2[x][j] = son2[G2[x][0]][j - 1];
		}
	}
	else
	{
		for(int j = 1; j <= n2; j++)
		{
			son2[x][j] = -1;
		}
	}
}

int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	scanf("%d%d", &n1, &n2);
	for(int i = 2; i <= n1; i++)
	{
		int fa;
		scanf("%d", &fa);
		G1[fa].push_back(i);
	}
	for(int i = 2; i <= n2; i++)
	{
		int fa;
		scanf("%d", &fa);
		G2[fa].push_back(i);
	}
	dfs2(1);
	scanf("%d", &m);
	while(m--)
	{
		int op, x;
		scanf("%d%d", &op, &x);
		if(op == 1)
		{
			s[++cnt] = x;
		}
		else
		{
			for(int i = 1; i <= cnt; i++)
			{
				if(s[i] == x)
				{
					swap(s[i], s[cnt]);
					cnt--;
					break;
				}
			}
		}
		sort(s + 1, s + cnt + 1);
		for(int x = 1; x <= n1; x++)
		{
		    memset(f[x], 0, sizeof(f[x]));
		    memset(g[x], -1, sizeof(g[x]));
		}
		dfs1(1);
		printf("%lld\n", f[1][1]);
	}
	
	return 0;
}
