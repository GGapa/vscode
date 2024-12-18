#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
const int N = 800 + 5;
const int mod = 1e9 + 7;

int n[3], tot[3];
vector<int> G[3][N];
int si[3][N], cha[3][N];
set<int> s;
ll ans = 0;

int dfs1(int x, int id) {
	if(si[id][x]) return si[id][x];
	si[id][x] = cha[id][x];
	for(auto to : G[id][x]) 
		si[id][x] += dfs1(to, id);
	return si[id][x];
}

void gsi(int id) { 
	rep(i, 1, n[id]) if(!si[id][i]) dfs1(i, id);
} 

void read(int id) {
	rep(i, 2, n[id]) {
		int fa;
		cin >> fa;
		G[id][i].push_back(fa);
	}
}

void init() {
	rep(i, 1, N) cha[1][i] = cha[2][i] = 1;
}

int check() {
	gsi(0);
	tot[1] = 0;
	rep(i, 1, n[1]) {
		tot[1] += si[1][i];
		if(G[1][i].size() == 0 && si[1][i] != si[2][si[0][i] - si[1][i]]) return 0;
	}
//	if(tot[1] != tot[2]) return 0;
	return 1;
} 

void dfs(int x) {
//	cout << x << endl;
	if(x > n[1]) {
		memset(si[0], 0, sizeof(si[0]));
		ans += check();
		return ;
	}
	for(auto i : s){
//		cout << i << endl;
		cha[0][x] = i;
		dfs(x);
		cha[0][x] = 1;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("b.in", "r", stdin);
//	freopen("b.out", "w", stdout);
	cin >> n[1] >> n[2]; 
	n[0] = n[1];
	init();
	read(1); read(2);
	memcpy(G[0], G[1], sizeof(G[0]));
	gsi(1); gsi(2);
	rep(i, 1, n[2]) cout << si[2][i] << " \n"[i == n[2]];
	cout << endl;
	int q;
	cin >> q;
	rep(i, 1, n[2]) tot[2] += si[2][i];
	while(q--) {
		int op, x;
		ans = 0;
		cin >> op >> x;
		if(op == 1) s.insert(x);
		if(op == 2) s.erase(x);	 
		dfs(1);
		cout << ans << '\n';
	}
	cout << endl;
	return 0; 
}
