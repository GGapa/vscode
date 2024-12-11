 #include <bits/stdc++.h>
 #define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
 #define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
 using namespace std;
 using LL = long long;
 using VI = vector<int>;
 
unordered_map<int, int> mp;

 signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<string> A(n + 1);
    vector<VI> cnt(n + 1, VI(27));
    vector<int> F(n + 1);
    int tp = (1 << 26) - 1;
    rep(i, 1, n) {
        cin >> A[i];
        for(auto c : A[i]) cnt[i][c - 'a']++;
        int t = 0;
        rep(j, 0, 25) t |= ((cnt[i][j] & 1) << j);
        F[i] = t;
    }
    LL ans = 0;
    rep(del, 0, 25) {
        mp.clear();
        rep(i, 1, n) if(!cnt[i][del]) {
            ans += mp[F[i] | (1 << del)];
            mp[(F[i] ^ tp) | (1 << del)] += 1;
        }
    }
    cout << ans << '\n';
    return 0;
}