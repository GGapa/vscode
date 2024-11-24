#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    string s; cin >> s; s = " " + s;
    vector<int> F(n + 1);
    s[1] = '(';
    rep(i, 1, n)  {
        F[i] = F[i - 1] +(s[i] == '(') - (s[i] == ')');
        if(s[i] == '_') {
            if(F[i] > 0) s[i] = ')', F[i]--;
            else s[i] = '(', F[i]++;
        }
    }
    vector<int> st;
    int ans = 0;
    rep(i ,1, n) {
        if(s[i] == ')') ans += i - st.back(), st.pop_back();
        else st.push_back(i);
    }
    // cout << s << '\n';
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
0 1 1 0 0 1 1 0
*/