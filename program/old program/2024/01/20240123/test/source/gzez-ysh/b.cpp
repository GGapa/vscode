#include <bits/stdc++.h>
using namespace std;
const int N = 8e2;
typedef long long ll;
const int inf = 1e9;
const ll INF = 1e18;
inline int read() {
	int s = 0,f = 1;char ch = getchar();
	while (!isdigit(ch)) f = ch == '-' ? -1 : 1, ch = getchar();
	while (isdigit(ch)) s = s * 10 + ch - '0', ch = getchar();
	return s * f;
}
int n1,n2,head[N + 10],head2[N + 10],cnt2,cnt;
struct edge {
	int v,nxt;
}ed[N * 2 + 10],ed2[N * 2 + 10];
void add(int u,int v) {
	ed[++cnt] = {v,head[u]};
	head[u] = cnt;
}
void add2(int u,int v) {
	ed2[++cnt2] = {v,head2[u]};
	head2[u] = cnt2;
}
int du[N + 10],to[N + 10],sz[N + 10],to2[N + 10];
const int mod = 1e9 + 7;
vector<int> vc[N + 10];
int FL,mx = 0;
void dfs(int x,int y) {
	int ct = 1,ct2 = 1;
	while (du[y] == 1) y = to[y], ct2 ++;
	while (sz[x] == 1) x = to2[x], ct ++;
	vc[ct].push_back(ct2);
	if (ct > ct2) {
		FL = 1;
		return;
	}
	mx = max(mx,ct2);
	if (sz[x] != du[y]) {
		FL = 1;
		return;
	}
	for (int i = head[x],j = head2[y];j;j = ed2[j].nxt, i = ed[i].nxt) {
		dfs(ed[i].v,ed2[j].v);
	}
}
int tmp[N + 10],tt;
struct poly {
	int a[N + 10];
	poly() {
		memset(a,0,sizeof a);
	}
	inline int& operator[] (const int &x) {
		return a[x];
	}
	inline friend poly operator * (poly x,poly y) {
		poly z;
		for (int i = 0;i <= mx;i ++ )
			for (int j = 0;j <= mx - i;j ++ )
				z[i + j] = (z[i + j] + 1ll * x[i] * y[j]) % mod;
		return z;
	}
}dp,a;
poly qpow(poly a,int b) {
	poly res;
	res[0] = 1;
	while (b) {
		if (b & 1) res = res * a;
		b >>= 1, a = a * a;
	}
	return res;
}
//void times(int *f,int *g,int n,int m) {
//	for (int i = 0;i < n;i ++ ) F[i] = f[i], f[i] = 0;
//}
/*
c[i] = a[k]*dp[i-k]
*/
int main() {
//	srand(time(0));
//	system("fc b.out ex_b3.ans");
//	freopen("ex_b3.in","r",stdin);
//	freopen("b.out","w",stdout);
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
//	mx = sqrt(800);
//	for (int i = 1;i <= sqrt(800);i ++ )
//		for (int j = 1;j <= 100;j ++ )
//			qpow(a,1);
//	return 0;
	n1 = read(), n2 = read();
//	n1 = 800, n2 = 800;
	for (int i = 2;i <= n1;i ++ ) {
		int u = read();
//		int u = i - 1;
		add(u,i),sz[u] ++,to2[u] = i;
	}
	for (int i = 2;i <= n2;i ++ ) {
//		int u = i - 1;
		int u = read();
		add2(u,i);du[u] ++, to[u] = i;
	}
	dfs(1,1);
	for (int i = 1;i <= n1;i ++ ) if (vc[i].size() > 0) tmp[++tt] = i;
	int q = read();
//	int q = 100,u = 0;
	if (FL) {
		while (q -- ) puts("0");
		return 0;
	}
//	for (int i = 1;i <= tot;i ++ ) cout << tt[i].first << ' ' << tt[i].second << endl;
	while (q -- ) {
//		cerr << q << endl;
		int op = read(),u = read();
//		int op = 0;u ++;
		a.a[u] ^= 1;
//		if (len.find(u) == len.end()) len.insert(u);
//		else len.erase(u);
		memset(dp.a,0,sizeof dp.a);
		dp[0] = 1;
		int res = 1;
		for (int i = 1;i <= tt;i ++ ) {
			dp = dp * qpow(a,tmp[i] - tmp[i - 1]);
			for (int j : vc[tmp[i]]) res = 1ll * res * dp[j] % mod;
		}
		printf("%d\n",res);
	}
	return 0;
}
/*
5 8
1 1 3 3
1 1 2 3 3 5 6
3
1 1
1 2
1 3
*/
