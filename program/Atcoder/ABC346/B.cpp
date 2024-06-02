// 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    string t1 = "wbwbwwbwbwbw", s;
    for(; s.size() <= (n + m) * 3; ) s += t1;
    rep(i, 0, s.size() - 1) {
        int t1, t2; t1 = t2 = 0;
        for(int j = 0; i + j < (n + m) * 3 && j < n + m; j++) {
            if(s[i + j] == 'w') t1++;
            else t2++;
        }
        if(t1 == n && t2 == m) {
            cout << "Yes\n";
            exit(0);
        }
    }
    cout << "No\n";
    return 0;
}