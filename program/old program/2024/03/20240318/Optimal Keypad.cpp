// Optimal Keypad
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const string SIG = " abcdefghijklmnopqrstuvwxyz+*/?";

int F[300], D[40][40], pre[40][40];

int dp ( int i, int g){
        int &d = D[i][g], k;
        if(d != -1) return d;
        if(g == 1) {
            for(d = 0, k = 1; k <= i; k++) d += F[(int)SIG[k]] * k;
            return d;
        }
        for(d = 1e9, k = g - 1; k < i; k++) {
            int nd = dp(k, g - 1);
            for(int j = k + 1; j <= i; j++) nd += F[(int)SIG[j]] * (j - k);
            if(nd < d) pre[i][g] = k, d = nd;
        }
        return d;
    };

void solve() {
    int n; cin >> n;
    memset(F, 0, sizeof(F)); memset(D, -1, sizeof(D)), memset(pre, 0, sizeof(pre));
    string s;
    rep(i, 1, n) {
        cin >> s;
        for(auto c : s) F[(int)c]++;
    } 
    // using VI = vector<int>;
    // vector<VI> D(30 + 1, VI(30 + 1, -1)), pre (30 + 1, VI(30 + 1)); 
    
    dp(30, 12);
    s.resize(11);
    for(int i = 30, g = 12; g > 1; i = pre[i][g--]) 
        s[g - 2] = SIG[pre[i][g] + 1];
    cout << s << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();

    return 0;
}