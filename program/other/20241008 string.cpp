#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	vector<int> cnt(26);
	for(auto c : s) cnt[c - 'a'] ++;
	LL ans = 1ll * (n) *  (n + 1) / 2;
	rep(i, 0, 25) ans -= 1ll * (cnt[i]) * (cnt[i] - 1) / 2;
	cout << ans << '\n';
	return 0; 
}