#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

int ask(string s) {
    cout << "? " << s << endl;
    int ret; cin >> ret;
    return ret;
}

void out(string s) {
    cout << "! " << s << endl;
}

void solve() {
    int n; cin >> n;
    if(n == 1) {
        if(ask("1")) out("1");
        else out("0");
        return ;
    }

    string s = "0";
    for(int tag = 1; tag && s.size() < n; ) {
        tag = 0;
        if(ask(s + "0")) {
            tag = 1; s = s + "0";
        }
        else if(ask(s + "1")) {
            tag = 1; s = s + "1";
        }
    }
    for(int tag = 1; tag && s.size() < n; ) {
        tag = 0;
        if(ask("0" + s)) {
            tag = 1; s = "0" + s;
        }
        else if(ask("1" + s)) {
            tag = 1; s = "1" + s;
        }
    }
    if(s.size() != n) {
        cout << "! ";
        rep(i, 1, n) cout << 1;
        cout << endl;
        return ;
    }
    out(s);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}