#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 805;
const ll mod = 1e9 + 7;
const ll inf = 5e16;

ll dp[maxn][maxn];
int fa1[maxn], fa2[maxn], deg1[maxn], deg2[maxn], l1, l2, l3, st[105], top;
vector<int> g1[maxn], g2[maxn];
vector<pii> que;
bool Fl, s[maxn];

void dfs(int u1, int u2)
{
	int cnt1 = 1, cnt2 = 1;
	while (deg1[u1] == 1) u1 = g1[u1][0], cnt1++;
	while (deg2[u2] == 1) u2 = g2[u2][0], cnt2++;
	que.emplace_back(make_pair(cnt1, cnt2));
	l1 = max(l1, cnt1), l2 = max(l2, cnt2), l3 = max(l3, cnt2 - cnt1 + 1);
	if (g1[u1].size() != g2[u2].size())
	{
		Fl = true;
		return;
	}
	for (int i = 0; i < g1[u1].size(); i++) dfs(g1[u1][i], g2[u2][i]);
}

int main()
{
//	int start = clock();
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n1, n2;
	cin >> n1 >> n2;
	for (int i = 2; i <= n1; i++)
	{
		cin >> fa1[i]; deg1[fa1[i]]++;
		g1[fa1[i]].emplace_back(i);
	}
	for (int i = 2; i <= n2; i++)
	{
		cin >> fa2[i]; deg2[fa2[i]]++;
		g2[fa2[i]].emplace_back(i);
	}
	Fl = false, dfs(1, 1);
	
	int q;
	cin >> q;
	while (q--)
	{
		int op, x;
		cin >> op >> x;
		if (Fl)
		{
			cout << "0\n";
			continue;
		}
		
		s[x] ^= 1;
		dp[0][0] = 1;
		int mx = 0; top = 0;
		for (int i = 1; i <= l2; i++)
			if (s[i]) mx = i, st[++top] = i;
		for (int i = 1; i <= l1; i++)
		{
			int len = min(l2, min(i * mx, l3 + i));
			for (int k = i; k <= len; k++) dp[i][k] = 0;
			for (int j = 1; j <= top; j++)
			{
				if (st[j] > len) break;
				for (int k = len; k >= i && k >= st[j]; k--) dp[i][k] += dp[i - 1][k - st[j]];
			}
			for (int k = i; k <= len; k++)
				if (dp[i][k] >= inf) dp[i][k] %= mod;
		}
		
		ll ans = 1;
		for (pii tmp : que) (ans *= dp[tmp.first][tmp.second] % mod) %= mod;
		cout << ans << "\n";
	}
//	cerr << 1.0 * (clock() - start) / CLOCKS_PER_SEC;
	return 0;
}
