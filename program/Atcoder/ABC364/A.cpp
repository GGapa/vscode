#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int cnt = 0;
    rep(i, 1, n) {
        string s; cin >> s;
        if(s == "sweet") cnt++;
        else cnt = 0;
        if(cnt >= 2 &&i != n) return cout << "No\n", 0;
    }
    cout << "Yes\n";
    return 0;
}