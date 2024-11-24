#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;


void solve() {
	int n; cin >> n;
	vector<pair<int, char>> A(n + 1);
	rep(i ,1, n) cin >> A[i].first;
	string s; cin >> s;
	rep(i, 1, n) A[i].second = s[i - 1];
	int dn = count(s.begin(), s.end(), '0'), up = n - dn;
	int x = 1, y = dn + 1;
	vector<int> id(n + 1);
	iota(id.begin(), id.end(), 0);
	sort(id.begin() + 1, id.end(), [&](const int &x, const int &y){
		return A[x].first < A[y].first;
	});
	vector<int> ans(n +1);
	rep(t, 1, n) {
		int i = id[t];
		if(A[i].second == '0') ans[i] = x++;
		else ans[i] = y++;
	}
	rep(i ,1, n) cout <<ans[i] << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int T; cin >> T; 
	while(T--) solve();
    return 0;
}
