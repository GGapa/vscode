#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<ll>;

int n, m, q;

struct Que {
    int x, y, id, ty;
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("matrix.in", "r", stdin);
    // freopen("matrix.out", "w", stdout);
    cin >> n >> m ;
    vector<string> S(n + 1); 
    vector<int> len(n + 1);
    vector<Que> Q;
    rep(i, 1, n) cin >> S[i], len[i] = S[i].size(), S[i] = " " + S[i];
    cin >> q;
    vector<ll> ans(q + 1);
    for(int x1, x2, y1, y2, i = 1; i <= q; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        Q.push_back((Que){x2, y2, i, 1});
        Q.push_back((Que){x1 - 1, y2, i, -1});
        Q.push_back((Que){x2, y1 - 1, i, -1});
        Q.push_back((Que){x1 - 1, y1 - 1, i, 1});
    }
    sort(Q.begin(), Q.end(), [](const Que &x, const Que &y) {
        return x.x < y.x;
    });
    int mx = 100;
    vector<VI> A(mx + 1, VI(mx + 1)), F = A;
	auto gans = [&](const int j) {
        if(j == 0) return 0ll;
		ll ans = 0; 
		rep(i, 1, mx) ans += F[i][i] * (j / i) + F[i][j % i];
        // cout << j << " " << ans << '\n';
		return ans;
	};
    for(int i = 1, j = 0; i <= n; i++) {
        int t = len[i]; auto &a = A[t], &f = F[t];
        rep(j, 1, t) a[j] += (S[i][j] - '0'), f[j] = f[j - 1] + a[j];
		for(; j < Q.size() && Q[j].x <= i; j++) {
            if(Q[j].x == 0) continue;
            ans[Q[j].id] += Q[j].ty * gans(Q[j].y);
        }
    }
	rep(i ,1, q) cout << ans[i] << '\n'; 
    return 0;
}