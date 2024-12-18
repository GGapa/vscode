#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;


void solve() {
    int n; cin >> n;
    string s; cin >> s;
    rep(st, 1, 1e4) {
        string t = "";
        if(st % 3 == 0 && st % 5 == 0) {
            t = "FB";
            for(int i = st + 1; t.size() < n; i++) {
                if(i % 3 == 0 && t.size() < n) t += 'F';
                if(i % 5 == 0 && t.size() < n) t += 'B';
            }
            if(t == s) return cout << "YES\n", void();
            t = "B";
            for(int i = st + 1; t.size() < n; i++) {
                if(i % 3 == 0 && t.size() < n) t += 'F';
                if(i % 5 == 0 && t.size() < n) t += 'B';
            }
            if(t == s) return cout << "YES\n", void();
        }
        else {
            for(int i = st; t.size() < n; i++) {
                if(i % 3 == 0 && t.size() < n) t += 'F';
                if(i % 5 == 0 && t.size() < n) t += 'B';
            }
            if(t == s) return cout << "YES\n", void();
        }
    }
    cout << "NO\n"; 
}

void init() {
    string s;
    rep(i, 1, 100) {
        if(i % 3 == 0) s += 'F';
        if(i % 5 == 0) s += 'B';
    }
    cerr << s << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // init();
    int T; cin >> T;
    while(T--) solve();
    return 0;
}