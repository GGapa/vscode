#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int n;

void solve() {
    cin >> n;
    string s; 
    cin >> s;
    int st, e; st = e = 0;
    rep(i, 0, n - 1) {
        if(!st && s[i] == 'B') st = i + 1;
        if(s[i] == 'B' && st) e = i + 1;
    }
    cout << e - st + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}