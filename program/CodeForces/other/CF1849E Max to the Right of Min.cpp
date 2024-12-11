#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 1e6 + 5, INF = 1e9;

int n;

int A[N], pos[N];
int mn[__lg(N) + 1][N];

void init() { 
    rep(i, 0, __lg(N)) rep(j, 0, N - 1) mn[i][j] = INF;
    rep(i ,1, n) mn[0][i] = A[i];
    rep(i, 1, __lg(n)) for(int j = 1; j + (1 << i) - 1 <= n; j++)
        mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << i - 1)]);
}

int query(int l, int r) {
    if(l > r) return -INF;
    int d = __lg(r - l + 1);
    return min(mn[d][l], mn[d][r - (1 << d) + 1]);
}

signed main() {
	// freopen("data.in", "r", stdin);
	// freopen("user.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> A[i], pos[A[i]] = i;
    init();

    LL ans = 0;
    set<int> s;
    per(i, n, 1) {
        auto it = s.lower_bound(pos[i]);
        int l = -1, r = -1;
        l = (it == s.begin() ? 1 : *prev(it) + 1);
        r = (it == s.end() ? n : *it - 1);

        if(pos[i] - l <= r - pos[i]) {
            rep(ll, l, pos[i]) {
                int nl = ll;
                int m1 = query(ll, pos[i]), ol = nl;
				// if(m1 > query(pos[i], r)) continue;
                nl = pos[i];
                int res = pos[i];
                
                int nr = r;
                while(nl <= nr) {
                    int mid = nl + nr >> 1;
                    if(query(pos[i], mid) > m1) nl = mid + 1, res = mid;
                    else nr = mid - 1;
                }

                if(ll != res) {
					ans += (res - pos[i] + (ll != pos[i]));
					// cerr << ll << " " << pos[i] << " " << res << '\n';
				}
            }
        }
        else {
            rep(rr, pos[i], r) {
                int nr = rr;
                int m1 = query(pos[i], rr), oor = nr;
				if(query(l, pos[i]) > m1) continue;
                nr = pos[i];
                int res = pos[i];
                
                int nl = l;
                while(nl <= nr) {
                    int mid = nl + nr >> 1;
                    if(query(mid, pos[i]) < m1) nl = mid + 1, res = mid;
                    else nr = mid - 1;
                }

                if(rr != res) {
					ans += (res - l + (rr != pos[i] || res != pos[i]));
					// cerr << res << " " << pos[i] << " " << rr << '\n';
				}
            }
        }
        s.insert({pos[i]});
    }

    cout << ans << '\n';
    return 0; 
} 