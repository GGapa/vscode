// P9188 

#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = s.size(); s = " " + s;
    vector<ll> F(n + 1), lt(7);    
    rep(i, 1, n) {
        if(s[i] == 'b') lt[1] = i;
        if(s[i] == 'e') lt[2] = lt[1], lt[6] = lt[5];
        if(s[i] == 's') lt[4] = lt[3], lt[3] = lt[2];
        if(s[i] == 'i') lt[5] = lt[4];
        if(lt[6] > 0)F[i] = F[lt[6] - 1] + lt[6];
    }
    cout << accumulate(F.begin() + 1, F.end(), 0ll) << '\n';
    return 0;
}