#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

int ask(const string s) {
    cout << s << endl;
    int ret; cin >> ret;
    return ret;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n = ask("a");
    if(n == 0) return 0;
    if(n == 300) return cout << string(n, 'b') << endl, 0;
    string s; 
    int m = ask((s = string(n + 1, 'a')));
    if(m == 0) return 0;
    if(m > n) return cout << string(n, 'b') << endl, 0;
    rep(i, 0, n) {
        s[i] = 'b';
        int t = ask(s);
        if(t == 0) return 0;
        if(t < m) m = t; 
        else s[i] = 'a';
    }
    cout << s << endl;
    return 0;
}