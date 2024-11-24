#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define CSP2024 GG BUT I WILL WIN NOIP2024
using namespace std;
using LL = long long;
using VI = vector<int>;
constexpr int N = 1e6  +5;

bitset<N> vis;
vector<int> p;
int mn[N];
 
void init() {
    p.push_back(-1);
    for (int i = 2; i < N; i++) {
        if (!vis[i]) p.push_back(i), mn[i] = i;
        for (int j = 1; j <= p.size() && i * p[j] < N; j++) {
            vis[i * p[j]] = 1;
            mn[i * p[j]] = p[j];
            if (i % p[j] == 0) break;
        }
    }
}

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1);
    int cnt = 0, it = -1;
    sort(A.begin(), A.end());
    rep(i, 1, n) {
         cin >> A[i];
         if(vis[A[i]] == 0) cnt++, it = A[i];
    }
    if(cnt > 1) return cout << -1 << '\n', void();
    if(cnt == 1) {
        bool tag = 1;
        rep(i, 1, n) if(A[i] != it && A[i] < 2 * it) tag = false;
        rep(i, 1, n) if(A[i] != it && A[i] % it != 0 && A[i] % 2 != 0 && A[i] - mn[A[i]] < 2 * it)  tag = false;
        if(tag) return cout << it << '\n', void();
        else return cout << -1 << '\n', void();
    }
    cout << 2 << '\n', void();
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
/*
2 配上 3 能构成任何数
*/