#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 2e5 + 5;
int del[N];

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1), cnt(n + 1), S(n + 2);
    rep(i ,1, n) cin >> A[i], cnt[A[i]]++;
    sort(A.begin() + 1, A.end());
    A.erase(unique(A.begin() + 1, A.end()), A.end());
    int m = n;
    n = A.size() - 1; 
    rep(i, 1, n) S[i] = S[i - 1] + cnt[A[i]];
    S[n + 1] = S[n];

    vector<int> F(50), G(50);
    for(int i = 0, j = 0; (1 << i) <= m; i++) {
        while(j < n && S[j + 1] <= (1 << i)) j++;
        F[i] = j;
    }
    for(int i = 0, j = n + 1; (1 << i) <= m; i++) {
        while(j > 1 && S[n] - S[j - 2] <= (1 << i)) j--;
        G[i] = j;
    }

    int ans = 2e9;
    for(int i = 0; (1 << i) <= m; i++) for(int j = 0; (1 << j) <= m; j++) 
        {
            int x = F[i], y = G[j]; y = max(y, x + 1);
            ans = min(ans, (1 << i) + (1 << j) - S[x] - (S[n] - S[y - 1]) + del[S[y - 1] - S[x]]);
        }
    cout << ans << '\n';
}

void init() {
    del[0] = 1;
    for(int i = 1, up = 1; i < N; i++) {
        del[i] = up - i;
        if(i == up) up *= 2;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    int T; cin >> T;
    while(T--) solve();
    return 0;
}