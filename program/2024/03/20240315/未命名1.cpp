#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
vector<VI> G; 
vector<int> a{0};
vector<array<int, 2>> F; //ºÚÉ«°×É« 
int n;
//void dfs(int x, int fa = 0) {
//	f[x] = fa;
//	for(auto to : G[x]) if(to != fa) 
//		dfs(to, x);
//}
void dfs2(int x, int fa) {
	auto &f = F[x];
	f[1] = f[0] = 1;
	for(auto to : G[x]) if(to != fa) {
		dfs2(to, x);
		(f[1] *= (F[to][0] + F[to][1]) % mod) %= mod;
		(f[0] *= F[to][1]) %= mod;
	}
//	f[1] = max(f[1], 1ll); f[0] = max(f[0], 1ll);
} 

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> n; G.resize(n + 1);	F.resize(n + 1);
	for(int i = 2, a , b; i <= n; i++) {
		cin >> a >> b;
		G[a].push_back(b), G[b].push_back(a);
	} 
	dfs2(1, 0);
	cout << (F[1][1] + F[1][0]) % mod<< '\n';
    return 0;
}

