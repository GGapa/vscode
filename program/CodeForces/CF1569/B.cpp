//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    string s ;cin >> s; s =  " " + s;
    int c2, c1; c2 = c1 =0 ;
    vector<VI> ans(n + 1, VI(n + 1));
    vector  <int> wt;
    rep(i ,1, n) {
        if(s[i] == '1') {
            c1++;
        }
        else {
            c2++;
            wt.push_back(i);
        }
    }
    if(c2 <= 2 && c2 > 0) return cout << "NO\n", void ();
    rep(i, 0, (int) wt.size() - 2) ans[wt[i]][wt[i + 1]] = 1, ans[wt[i + 1]][wt[i]] = -1;
    if(c2) ans[wt.back()][wt[0]] = 1, ans[wt[0]][wt.back()] = -1;
    cout << "YES\n";
    rep(i, 1, n) {
        rep(j, 1, n) {
            if(i == j) {
                cout << "X";
                continue;
            }
            if(ans[i][j] == 1) cout << '+';
            else if(ans[i][j] == -1) cout << '-';
            else cout << "=";
        }
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;cin >> T;
    while(T--) solve() ;
    return 0;
}