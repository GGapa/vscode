#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A;

    for(int i = 1, x; i <= n; i++) {
        cin >> x;
        if(x != 0 || i == 1)  A.emplace_back(x);
    }

    LL sum = 0, cnt = 0;
    for(auto a : A) {
        sum += a;
        if(sum == 0) cnt++;
        if(sum < 0) return cout << "No\n", void();  
    }
    if(cnt != 1 || sum != 0) return cout << "No\n", void();
        // debug 这里细节写挂了，没有判 sum != 0
    cout << "Yes\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}