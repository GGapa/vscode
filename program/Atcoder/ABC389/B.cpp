#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    LL x; cin >> x;
    LL sum = 1;
    rep(i, 1, 10000000) {
        sum *= i;
        if(sum == x) return cout << i << '\n', 0;
    }
    return 0;
}