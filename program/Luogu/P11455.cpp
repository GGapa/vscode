#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 100005;

int n, a[N], mg, ty, pro;
vector<int>son[N], nd[N];
int lov[N], anp[N];
inline void get(int x, int a) {
	int ans = 0, np = 0;
	lov[x] = 1e9 + 7; pro -= anp[x];
	while (np < (int)son[x].size()) {
		int cp = upper_bound(son[x].begin(), son[x].end(), son[x][np] + a) - son[x].begin();
		if (cp != (int)son[x].size()) lov[x] = min(lov[x], son[x][cp] - son[x][np]);
		ans++; np = cp;
	}
	if (ans != 1) nd[lov[x]].emplace_back(x);
	anp[x] = ans; pro += ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
	rep(i, 1, n)
		cin >> a[i], son[a[i]].emplace_back(i);
	rep(i, 1, n)
		if (!son[i].size()) continue;
		else if (son[i].size() == 1) pro++;
		else nd[1].emplace_back(i);
	rep(i, 1, n) {
		for (int sp : nd[i]) get(sp, i);
		cout << pro << '\n';
	}
    return 0; 
}
