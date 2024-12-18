//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> X(n + 1), Y(m + 1);
    unordered_map<int, int> cx, cy;
    vector<array<int, 3>> px, py;
    rep(i ,1, n) cin >> X[i], cx[X[i]] = 1;
    rep(i, 1, m) cin >> Y[i], cy[Y[i]] = 1;
    sort(X.begin(), X.end()); sort(Y.begin(), Y.end());
    for(int i = 1, x, y; i <= k; i++) {
        cin >> x >> y;
        if(cx[x] && cy[y]) continue;
        (cx[x] ? px : py).push_back({x, y, 0});
    }
    for(auto &x : px) 
        x[2] = lower_bound(Y.begin() + 1, Y.end(), x[1]) - Y.begin();
    for(auto &y : py) y[2] = lower_bound(X.begin() + 1, X.end(), y[0]) - X.begin();
    sort(px.begin(), px.end(), [](const array<int, 3> &x, const array<int, 3> &y) {
        return(x[2] == y[2] ? x[0] < y[0] : x[2] < y[2]); 
    });
    sort(py.begin(), py.end(), [](const array<int, 3> &x, const array<int, 3> &y) {
        return(x[2] == y[2] ? x[1] < y[1] : x[2] < y[2]);
    });
    int it = 0;
    ll ans = 0;
    rep(i, 2, m) {
        int s = Y[i - 1], e = Y[i];
		int last = it;
		while (it < px.size() && px[it][1] < e) ++it;
		int p = last;
		int sum = 0;
		for (int j = last + 1; j < it; j++) {
			if (px[j][0] != px[j - 1][0]) sum += (j - p) * (j - p), p = j;
		}
		sum += (it - p) * (it - p);
		ans += ((last - it) * (last - it) - sum) / 2;
    } 
    it = 0;
    rep(i, 2, n) {
        int s = X[i - 1], e = X[i];
		int last = it;
		while (it < py.size() && py[it][0] < e) ++it;
		int p = last;
		int sum = 0;
		for (int j = last + 1; j < it; j++) {
			if (py[j][1] != py[j - 1][1]) sum += (j - p) * (j - p), p = j;
		}
		sum += (it - p) * (it - p);
		ans += ((last - it) * (last - it) - sum) / 2;
    } 
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;cin >> T;
    while(T--) solve() ;
    return 0;
}