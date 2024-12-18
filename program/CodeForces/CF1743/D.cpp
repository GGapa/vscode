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
    string s; cin >> s; s = " " + s;
    int it = 0, st = 0;
    queue<int> pos;
    for(int i = 1, tag = 0; i <= n; i++) {
        if(s[i] == '1') {
            if(!tag) st = i;
             tag = 1, pos.push(i);
        }
        if(tag && s[i] == '0') {
            it = i;
            break;
        }
    }
    if(!st) return cout << 0 << '\n' ,0;
    if(!it) {
        bool tag = 0;
        rep(i, 1, n) {
            tag |= (s[i] != '0');
            if(tag) cout << s[i];
        }
        if(!tag) cout << 0 << '\n';
        return 0;
    }
    vector<int> ans(n + 1);
    auto check = [&](int st) {
        for(int i = it, j = st, tag = 1; i <= n; i++, j++) {
            if(ans[i] > ((s[i] - '0') | (s[j] - '0'))) {if(tag) return ;}
            else if(ans[i] != ((s[i] - '0') | (s[j] - '0')))tag = 0;
        }
        for(int i = it, j = st, tag = 1; i <= n; i++, j++) ans[i] = ((s[i] - '0') | (s[j] - '0'));
    };
    while(!pos.empty()) {
        check(pos.front()); pos.pop();
    }
    rep(i, st, n) {
        if(i < it) cout << 1;
        else cout << ans[i];
    }
    cout << '\n';
    return 0;
}
/*
5
10110
*/