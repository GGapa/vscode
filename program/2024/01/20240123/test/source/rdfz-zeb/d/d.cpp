#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int N = 910, M = 35;
typedef long long ll;
const ll MOD = 998244353;

int n, m, k, p, t, head[N], ver[2 * N], Next[2 * N], edge[2 * N], tot = 1, a[N];
ll jc[2 * N], jc_inv[2 * N];

ll power(ll a, ll b)
{
	ll c = 1;
	while(b)
	{
		if(b & 1) c = c * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return c;
}

struct node{
	ll a[M];
	
	void _init()
	{
		memset(a, 0, sizeof(a));
	}
}f[N][M][2], f2[M][2];

ll C(ll n, ll m)
{
	if(n < 0 || m < 0 || n < m) return 0;
	return jc[n] * jc_inv[n - m] % MOD * jc_inv[m] % MOD;
}

void add(int x, int y, int z)
{
	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}

node calc(ll z)
{
	z %= MOD;
	node a;
	a.a[0] = 1;
	for(int i = 1; i <= k; i++) a.a[i] = a.a[i - 1] * z % MOD;
	return a;
}

node operator *(const node a, const node b)
{
	node c;
	c._init();
	for(int i1 = 0; i1 <= k; i1++)
	{
		for(int i2 = 0; i1 + i2 <= k; i2++)
		{
			c.a[i1 + i2] += C(i1 + i2, i1) * a.a[i1] % MOD * b.a[i2] % MOD;
			if(c.a[i1 + i2] >= MOD) c.a[i1 + i2] -= MOD;
		}
	}
	return c;
}

node operator +(const node a, const node b)
{
	node c;
	for(int i = 0; i <= k; i++) c.a[i] = (a.a[i] + b.a[i]) % MOD;
	return c;
}


void dfs1(int x, int fa)
{
	f[x][0][0].a[0] = f[x][0][1].a[0] = f[x][1][0].a[0] = f[x][1][1].a[0] = 1;
	for(int i = 1; i <= k; i++)
	{
		f[x][0][0].a[i] = f[x][1][0].a[i] = 0;
		f[x][0][1].a[i] = f[x][0][1].a[i - 1] * a[x] % MOD;
		f[x][1][1].a[i] = f[x][1][1].a[i - 1] * (a[x] + t) % MOD;
	}
	
	for(int i = head[x]; i; i = Next[i])
	{
		int y = ver[i], z = edge[i];
		if(y != fa)
		{
			dfs1(y, x);
			for(int p0 = 0; p0 <= p; p0++) f2[p0][0]._init(), f2[p0][1]._init();
			for(int p1 = 0; p1 <= p; p1++)
			{
				for(int p2 = 0; p1 + p2 <= p; p2++)
				{
					f2[p1 + p2][0] = f2[p1 + p2][0] + (f[x][p1][0] * calc(z) * f[y][p2][0]);
					if(p1 + p2 < p) f2[p1 + p2 + 1][0] = f2[p1 + p2 + 1][0] + (f[x][p1][0] * calc(z + t) * f[y][p2][0]);
					f2[p1 + p2][0] = f2[p1 + p2][0] + (f[x][p1][0] * f[y][p2][1]);
					if(p1 + p2 < p) f2[p1 + p2 + 1][0] = f2[p1 + p2 + 1][0] + (f[x][p1][0] * f[y][p2][1]);
					f2[p1 + p2][1] = f2[p1 + p2][1] + (f[x][p1][1] * f[y][p2][0]);
					if(p1 + p2 < p) f2[p1 + p2 + 1][1] = f2[p1 + p2 + 1][1] + (f[x][p1][1] * f[y][p2][0]);
				}
			}
			for(int p0 = 0; p0 <= p; p0++) f[x][p0][0] = f2[p0][0], f[x][p0][1] = f2[p0][1];
		}
	}
}

void init()
{
	int lim = max(2 * n - 1, k);
	jc[0] = 1;
	for(int i = 1; i <= lim; i++) jc[i] = jc[i - 1] * i % MOD;
	jc_inv[lim] = power(jc[lim], MOD - 2);
	for(int i = lim - 1; i >= 0; i--) jc_inv[i] = jc_inv[i + 1] * (i + 1) % MOD;
}

int main()
{
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	scanf("%d%d%d%d%d", &n, &m, &k, &p, &t);
	init();
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z), add(y, x, z);
	}
	dfs1(1, 0);
	printf("%lld\n", (f[1][p][0].a[k] + f[1][p][1].a[k]) % MOD * power(C(2 * n - 1, p), MOD - 2) % MOD);
	return 0;
}
