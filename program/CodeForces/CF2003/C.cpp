#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> cnt(27) ;
    for(auto c : s) cnt[c - 'a']++;
    string ans = "";
    vector<int> id(27) ;
    iota(id.begin(), id.end(), 0) ;
    sort(id.begin(), id.end(), [&](const int &x, const int  &y) {
        return cnt[x] > cnt[y];
    });
    for(int tag = 1; tag; ) {
        tag = 0;
        rep(c, 0, 26) {
            int i = id[c] ;
            if(cnt[i]) 
                ans += (char)(i + 'a'), tag = 1, cnt[i]--;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
bzyxwvutsrqponmlkjihgfedca
*/