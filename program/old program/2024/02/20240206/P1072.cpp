#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

void solve() {
    int a0, a1, b0, b1;
    cin >> a0 >> a1 >> b0 >> b1;
    int a = a0 / a1, b = b1 / b0, c = 0;
    for (int x = 1; x * x <= b1; x++) {
       if (b1 % x) continue;
        int y = b1 / x;
        c += x % a1 == 0 && __gcd(x / a1, a) == 1 && __gcd(b, y) == 1;
        c += x != y && y % a1 == 0 && __gcd(y / a1, a) == 1 && __gcd(b, x) == 1;
    }
    cout << c << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}