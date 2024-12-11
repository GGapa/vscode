// Poker  abc193_d
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int k; cin >> k;
    string S, T; cin >> S >> T;
    vector<int> cnt(10, k);
    for(auto i : S + T) if(i != '#') cnt[i - '0']--;
    auto sum = [&](string s) {
        vector<ll> F(10);
        iota(F.begin(), F.end(), 0);
        for(auto i : s) F[i - '0'] *= 10;
        return accumulate(F.begin(), F.end(), 0);
    };
    int res, ans; res = ans = 0;
    rep(i, 1, 9) rep(j, 1, 9) {
        S[4] = '0' + i, T[4] = '0' + j;
        if(sum(S) > sum(T)) 
            ans += cnt[i] * (cnt[j] - (i == j));
    }
    res = accumulate(cnt.begin(), cnt.end(), -k);
    printf("%.10f\n", 1.0 * ans / (1.0 * res * (res - 1)));
    return 0;
}