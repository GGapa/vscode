#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

const int N = 2e5 + 5;

vector<int> G[N];
int n;

namespace sub3 {
	void main() {
		if(n % 2 == 0) return cout << "-1\n", void();
		cout << 2 + n / 2 << '\n';
	}
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
	int n; cin >> n;
	bool x1 = true;
	for(int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		if(u != 1) x1 = false;
		u--, v--;
		G[u].push_back(v), G[v].push_back(u);
	}
	if(x1) return sub3::main(), 0;
	return 0; 
} 
