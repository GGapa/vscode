
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    rep(i, 0, n - 1) if(i % 2 == 1) s[i] ^= '1' ^ '0';
    vector<int> A(n + 1), S(n + 1), P(n + 1);
    rep(i, 1, n) cin >> A[i];
    rep(i, 1, n ) {
        S[i] = S[i - 1]; P[i] = P[i - 1];
        (s[i - 1] == '0' ? P[i] : S[i]) += A[i];
    }
    int ans = 1e18;
    rep(i, 1, n) {
        ans = min(S[i] + P[n] - P[i], ans);
        ans = min(P[i] + S[n] - S[i], ans);
    }
    cout << ans << '\n';
    return 0;
}

/*
01001

*/