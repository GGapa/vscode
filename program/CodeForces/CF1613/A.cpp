#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    double x1, x2;
    int p1, p2;
    cin >> x1 >> p1 >> x2 >> p2;
    while(x1 >= 10) x1 /= 10, p1++;
    while(x2 >= 10) x2 /= 10, p2++;
    if(p1 > p2) return cout << ">\n", void();
    else if(p1 < p2) return cout << "<\n", void();
    else {
        if(x1 == x2) return cout << "=\n", void();
        else if(x1 > x2) return cout << ">\n", void();
        else if(x1 < x2) return cout << "<\n", void();
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}