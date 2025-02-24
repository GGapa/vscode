#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
// using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

constexpr int mod = 1e9 + 3, B = 233;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int k, n; cin >> k >> n;
    vector<string> A(k);
    for(auto &s : A) cin >> s;
    vector<LL> pw(n + 1); pw[0] = 1;
    rep(i, 1, n) pw[i] = pw[i - 1] * B % mod;
    string s; cin >> s; s = " " + s;

    vector<int> stk, F(n + 1), q;
    vector<VI> hs(n + 1, VI(__lg(n) + 1)), nt = hs;
    auto cmp = [&](int x, int y) {
        per(i, __lg(n), 0) if(hs[x][i] == hs[y][i]) x = nt[x][i], y = nt[y][i];
        return s[x] >= s[y];
    };
    per(i, n, 1) {
        while(!stk.empty() && A[s[i] - 'a'][s[stk.back()] - 'a'] == '1')  stk.pop_back();
        if(stk.empty()) F[i] = 0;
        else {
            auto it = lower_bound(q.begin(), q.end(), stk.back(), greater<int>());
            F[i] = *it;
        }
        nt[i][0] = F[i]; hs[i][0] = s[i] - 'a';
        rep(j, 1, __lg(n)) nt[i][j] = nt[nt[i][j - 1]][j - 1], hs[i][j] = (hs[i][j - 1] + hs[nt[i][j - 1]][j - 1] * pw[1 << j - 1]) % mod;
        while(!q.empty() && cmp(q.back(), i)) q.pop_back();
        q.push_back(i), stk.push_back(i);
    }
    for(int i = 1; i; i = F[i]) cout << s[i];
    return 0;
}