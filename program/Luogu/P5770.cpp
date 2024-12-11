#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using VI = vector<int>;

constexpr int N = 70;

LL F[N];
ULL mul[N];

void solve() {
    int n; LL k; cin >> n >> k;
    vector<char> ans(n + 1);
    auto work = [&](int x) {
        vector<ULL> G(n + 1);
        for (int i = 1; i <= n; i++) {
            if (i <= x) {
                G[i] = 1;
                for (int j = 1; j < i; j++) {
                    bool tag = 1;
                    for (int z = 1; z <= j; z++) tag &= (ans[z] == ans[i - j + z]);
                    if (tag)G[i] = 0;
                }
                continue;
            }
            G[i] = mul[i - x];
            for (int j = 1; j <= i / 2; j++)
                if (G[j]) {
                    if (x <= i - j) {
                        G[i] -= G[j] * mul[i - j - max(x, j)];
                        continue;
                    }
                    bool tag = 1;
                    for (int z = 1; z <= j && z + i - j <= x; z++) tag &= (ans[z] == ans[i - j + z]);
                    if (tag) G[i]--;
                }
        }

        return G[n];
    };

    // cout << F[n] << '\n';
    cout << work(0) << '\n';
    ULL sum = 0;
    rep(i, 1, n) {
        ans[i] = 'a';
        auto t = work(i);
        if(k > t) k -= t, ans[i] = 'b';
        cout << ans[i];
    }
    cout << '\n';
}

void init() {
    F[1] = F[2] = 2;
    rep(i, 3, 64) F[i] = F[i - 1] * 2 - ((i & 1) == 0) * F[i / 2];
    mul[0] = 1;
    rep(i, 1, 64) mul[i] = mul[i - 1] * 2;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}